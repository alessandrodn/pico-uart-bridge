Raspberry Pi Pico USB-UART Bridge
=================================

This program bridges the Raspberry Pi Pico HW UARTs to two independent USB CDC serial devices in order to behave like any other USB-to-UART Bridge controllers.

Disclaimer
----------

This software is provided without warranty, according to the MIT License, and should therefore not be used where it may endanger life, financial stakes, or cause discomfort and inconvenience to others.

Waveshare RP2040-Zero
---------------------
This branch contains some adaptation to work on the [Waveshare RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero) board.

| Waveshare RP2040-Zero GPIO | Function |
|:--------------------------:|:--------:|
| GPIO0 (Pin 0)              | UART0 TX |
| GPIO1 (Pin 1)              | UART0 RX |
| GPIO4 (Pin 4)              | UART1 TX |
| GPIO5 (Pin 5)              | UART1 RX |

To drive the onboard LED (WS2812), I integrated the [RGB led WS2812 library for RP2040 using PIO](https://github.com/dgatf/pio-ws2812-rp2040).
