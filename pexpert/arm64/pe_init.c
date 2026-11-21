/*
 * Platform initialization for a3lte (SM-A300F)
 * Based on Apple's platform initialization code
 */

#include <pexpert/pexpert.h>
#include <arm64/board_config.h>
#include <pexpert/arm64/a3lte/a3lte.h>

/*
 * Platform initialization function
 * Called after platform identification
 */
void PE_init_platform(void)
{
    /* Initialize a3lte-specific platform */
    if (strcmp(PE_get_platform_name(), "a3lte") == 0) {
        /* Initialize UART */
        a3lte_uart_init();
        
        /* Initialize CPU */
        a3lte_cpu_init();
        
        /* Initialize PMIC */
        a3lte_pmic_init();
        
        /* Initialize SDHCI */
        a3lte_sdhci_init();
        
        /* Initialize display */
        a3lte_display_init();
        
        /* Initialize touch */
        a3lte_touch_init();
        
        /* Set up memory map */
        a3lte_setup_memory_map();
        
        /* Set up interrupt controller */
        a3lte_gic_init();
        
        /* Set up timer */
        a3lte_timer_init();
        
        /* Set up spin table for secondary CPUs */
        a3lte_spin_table_init();
    }
}

/*
 * Platform-specific memory map setup
 */
void a3lte_setup_memory_map(void)
{
    /* Physical memory: 1GB at 0x80000000 */
    PE_add_memory_region(0x80000000, 0x40000000, kPEMemoryTypeMain);
    
    /* Reserved regions */
    PE_add_memory_region(0x86500000, 0x180000, kPEMemoryTypeReserved);  /* TrustZone */
    PE_add_memory_region(0x86400000, 0x100000, kPEMemoryTypeReserved);  /* Hypervisor */
    PE_add_memory_region(0x86300000, 0x100000, kPEMemoryTypeReserved);  /* SMEM */
    PE_add_memory_region(0x86700000, 0xE0000, kPEMemoryTypeReserved);   /* RPM */
    PE_add_memory_region(0x86800000, 0x600000, kPEMemoryTypeReserved);  /* WCNSS */
    PE_add_memory_region(0x86E00000, 0x5400000, kPEMemoryTypeReserved); /* MPSS */
    
    /* Framebuffer: MDSS at 0x1A00000 */
    PE_add_memory_region(0x1A00000, 0x300000, kPEMemoryTypeFramebuffer);
}
