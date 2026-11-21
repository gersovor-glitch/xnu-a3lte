/*
 * a3lte (SM-A300F) Display driver (MDSS)
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void display_init(void) {
    a3lte_display_init();
}

void display_set_framebuffer(void *fb) {
    /* Set framebuffer base address */
}
