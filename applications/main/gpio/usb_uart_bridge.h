#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct UsbUartBridge UsbUartBridge;

typedef struct {
    uint8_t vcp_ch;
    uint8_t uart_ch;
    uint8_t flow_pins;
    uint8_t baudrate_mode;
    uint32_t baudrate;
    uint8_t software_de_re;
    uint8_t databits;
    uint8_t parity;
    uint8_t stopbits;
} UsbUartConfig;

typedef struct {
    uint32_t rx_cnt;
    uint32_t tx_cnt;
    uint32_t baudrate_cur;
    uint8_t databits_cur;
    char parity_cur;
    float stopbits_cur;
} UsbUartState;

UsbUartBridge* usb_uart_enable(UsbUartConfig* cfg);

void usb_uart_disable(UsbUartBridge* usb_uart);

void usb_uart_set_config(UsbUartBridge* usb_uart, UsbUartConfig* cfg);

void usb_uart_get_config(UsbUartBridge* usb_uart, UsbUartConfig* cfg);

void usb_uart_get_state(UsbUartBridge* usb_uart, UsbUartState* st);
