/*
 * a3lte (SM-A300F) platform implementation
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void a3lte_uart_init(void) {
    /* Initialize UART at 115200 baud */
    volatile uint32_t *uart = (volatile uint32_t *)A3LTE_UART_BASE;
    uart[UART_CR/4] = 0;  /* Disable UART */
    uart[UART_IBRD/4] = 104;  /* Integer baud rate divisor for 115200 @ 19.2MHz */
    uart[UART_FBRD/4] = 11;   /* Fractional baud rate divisor */
    uart[UART_LCR_H/4] = 0x70;  /* 8 bits, no parity, 1 stop bit, FIFOs enabled */
    uart[UART_CR/4] = 0x301;  /* Enable UART, TX, RX */
}

void a3lte_uart_putc(char c) {
    volatile uint32_t *uart = (volatile uint32_t *)A3LTE_UART_BASE;
    while (uart[UART_FR/4] & UART_FR_TXFF) {}
    uart[UART_DR/4] = c;
}

void a3lte_cpu_init(void) {
    /* CPU initialization - Cortex-A53 specific */
    /* Enable L2 cache if present */
}

void a3lte_pmic_init(void) {
    /* PMIC initialization - PM8916 / RT5033 */
}

void a3lte_sdhci_init(void) {
    /* SDHCI initialization for eMMC and SD */
}

void a3lte_display_init(void) {
    /* Display initialization - MDSS 540x960 */
}

void a3lte_touch_init(void) {
    /* Touch controller initialization */
}

void a3lte_gic_init(void) {
    /* GICv2 initialization */
    volatile uint32_t *gic_dist = (volatile uint32_t *)A3LTE_GIC_DIST_BASE;
    volatile uint32_t *gic_cpu = (volatile uint32_t *)A3LTE_GIC_CPU_BASE;
    
    /* Disable distributor */
    gic_dist[GIC_DIST_CTRL/4] = 0;
    
    /* Set all interrupts to group 1 (non-secure) */
    for (int i = 0; i < 32; i++) {
        gic_dist[(GIC_DIST_IGROUP + i*4)/4] = 0xFFFFFFFF;
    }
    
    /* Enable distributor */
    gic_dist[GIC_DIST_CTRL/4] = 1;
    
    /* Enable CPU interface */
    gic_cpu[GIC_CPU_CTRL/4] = 1;
    gic_cpu[GIC_CPU_PRIMASK/4] = 0xFF;
}

void a3lte_timer_init(void) {
    /* Generic timer initialization */
    /* Timer frequency is 19.2 MHz */
}

void a3lte_spin_table_init(void) {
    /* Initialize spin table for secondary CPU bring-up */
    volatile uint64_t *spin_table = (volatile uint64_t *)A3LTE_SPIN_TABLE_ADDR;
    for (int i = 0; i < A3LTE_CPU_COUNT; i++) {
        spin_table[i] = 0;
    }
}
