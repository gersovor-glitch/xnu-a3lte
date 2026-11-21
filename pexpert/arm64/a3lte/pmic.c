/*
 * a3lte (SM-A300F) PMIC driver
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void pmic_init(void) {
    a3lte_pmic_init();
}

int pmic_read(uint8_t reg) {
    /* Read PMIC register via SPMI */
    return 0;
}

int pmic_write(uint8_t reg, uint8_t val) {
    /* Write PMIC register via SPMI */
    return 0;
}
