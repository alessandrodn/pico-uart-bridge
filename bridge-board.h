// SPDX-License-Identifier: MIT

#ifndef BRIDGE_BOARD_H
#define BRIDGE_BOARD_H

/* Preserve the original bridge wiring unless the board needs other pins. */
#ifndef BRIDGE_UART0_TX_PIN
#if defined(WAVESHARE_RP2040_ZERO) || defined(WAVESHARE_RP2040_ONE) || defined(WAVESHARE_RP2350_ZERO)
#define BRIDGE_UART0_TX_PIN PICO_DEFAULT_UART_TX_PIN
#else
#define BRIDGE_UART0_TX_PIN 16
#endif
#endif

#ifndef BRIDGE_UART0_RX_PIN
#if defined(WAVESHARE_RP2040_ZERO) || defined(WAVESHARE_RP2040_ONE) || defined(WAVESHARE_RP2350_ZERO)
#define BRIDGE_UART0_RX_PIN PICO_DEFAULT_UART_RX_PIN
#else
#define BRIDGE_UART0_RX_PIN 17
#endif
#endif

#ifndef BRIDGE_UART1_TX_PIN
#define BRIDGE_UART1_TX_PIN 4
#endif
#ifndef BRIDGE_UART1_RX_PIN
#define BRIDGE_UART1_RX_PIN 5
#endif

#endif
