/*
 * a3lte (SM-A300F) SDHCI driver
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void sdhci_init(void) {
    a3lte_sdhci_init();
}

int sdhci_read_block(uint32_t base, uint32_t block, void *buf) {
    /* Read block from eMMC/SD */
    return 0;
}

int sdhci_write_block(uint32_t base, uint32_t block, const void *buf) {
    /* Write block to eMMC/SD */
    return 0;
}
