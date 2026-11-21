/*
 * a3lte (SM-A300F) UART driver
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void uart_putc(char c) {
    a3lte_uart_putc(c);
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

void uart_puthex(uint64_t val) {
    char buf[18];
    buf[0] = '0'; buf[1] = 'x';
    for (int i = 15; i >= 0; i--) {
        int nib = (val >> (i * 4)) & 0xF;
        buf[17 - i] = (nib < 10) ? '0' + nib : 'a' + (nib - 10);
    }
    buf[18] = '\0';
    uart_puts(buf);
}
