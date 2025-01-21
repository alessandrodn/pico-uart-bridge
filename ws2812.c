#include "ws2812.h"

#include "hardware/clocks.h"
#include "ws2812.pio.h"

static PIO _pio;
static uint _sm;

void ws2812_init(PIO pio, uint pin, float freq) {
    _pio = pio;
    _sm = pio_claim_unused_sm(pio, true);

    uint offset = pio_add_program(pio, &ws2812_program);

    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, _sm, pin, 1, true);
    pio_sm_config c = ws2812_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, pin);
    sm_config_set_out_shift(&c, false, true, 24);
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);

    int cycles_per_bit = ws2812_T1 + ws2812_T2 + ws2812_T3;
    float div = clock_get_hz(clk_sys) / (freq * cycles_per_bit);
    sm_config_set_clkdiv(&c, div);

    pio_sm_init(pio, _sm, offset, &c);
    pio_sm_set_enabled(pio, _sm, true);
}

void pixel_rgb_put(uint32_t rgb) { pio_sm_put_blocking(_pio, _sm, rgb); }
