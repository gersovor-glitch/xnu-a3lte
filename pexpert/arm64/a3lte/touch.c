/*
 * a3lte (SM-A300F) Touch driver
 */

#include <pexpert/arm64/a3lte/a3lte.h>

void touch_init(void) {
    a3lte_touch_init();
}

int touch_read(int *x, int *y) {
    /* Read touch coordinates */
    return 0;
}
