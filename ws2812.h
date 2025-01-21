#ifndef WS2812_H
#define WS2812_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware/pio.h"

void ws2812_init(PIO pio, uint pin, float freq);
void pixel_rgb_put(uint32_t rgb0);

#ifdef __cplusplus
}
#endif

#endif
