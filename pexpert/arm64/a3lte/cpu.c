/*
 * a3lte (SM-A300F) CPU driver
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void cpu_init(void) {
    a3lte_cpu_init();
}

void cpu_start_secondary(int cpu) {
    /* Start secondary CPU via spin table */
    volatile uint64_t *spin_table = (volatile uint64_t *)A3LTE_SPIN_TABLE_ADDR;
    spin_table[cpu] = 0x80000000;  /* Kernel entry point */
    
    /* Send SEV to wake up CPU */
    asm volatile("sev" ::: "memory");
}

int cpu_is_online(int cpu) {
    /* Check if CPU is online */
    return 1;  /* Simplified */
}
