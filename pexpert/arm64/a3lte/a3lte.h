/*
 * a3lte (SM-A300F) platform header
 * Defines hardware registers and constants for Samsung Galaxy A3 (MSM8916)
 */

#ifndef _PEXPERT_ARM64_A3LTE_A3LTE_H_
#define _PEXPERT_ARM64_A3LTE_A3LTE_H_

#include <stdint.h>

/* Base addresses */
#define A3LTE_UART_BASE        0x078B0000
#define A3LTE_GIC_DIST_BASE    0x0B000000
#define A3LTE_GIC_REDIST_BASE  0x0B002000
#define A3LTE_GIC_CPU_BASE     0x0B001000
#define A3LTE_TIMER_BASE       0x0B020000
#define A3LTE_SPMI_BASE        0x0200F000
#define A3LTE_SDHCI_EMMC_BASE  0x07824900
#define A3LTE_SDHCI_SD_BASE    0x07864900
#define A3LTE_USB_BASE         0x078D9000
#define A3LTE_MDSS_BASE        0x01A00000
#define A3LTE_SPIN_TABLE_ADDR  0x86700088
#define A3LTE_RPM_MSG_RAM      0x00060000

/* Memory regions */
#define A3LTE_PHYS_MEMORY_BASE 0x80000000
#define A3LTE_PHYS_MEMORY_SIZE 0x40000000  /* 1GB */

/* Reserved memory regions */
#define A3LTE_TZ_BASE      0x86500000
#define A3LTE_TZ_SIZE      0x180000
#define A3LTE_HYP_BASE     0x86400000
#define A3LTE_HYP_SIZE     0x100000
#define A3LTE_SMEM_BASE    0x86300000
#define A3LTE_SMEM_SIZE    0x100000
#define A3LTE_RPM_BASE     0x86700000
#define A3LTE_RPM_SIZE     0xE0000
#define A3LTE_WCNSS_BASE   0x86800000
#define A3LTE_WCNSS_SIZE   0x600000
#define A3LTE_MPSS_BASE    0x86E00000
#define A3LTE_MPSS_SIZE    0x5400000

/* Framebuffer */
#define A3LTE_FB_BASE      0x1A00000
#define A3LTE_FB_WIDTH     540
#define A3LTE_FB_HEIGHT    960
#define A3LTE_FB_STRIDE    2160
#define A3LTE_FB_DEPTH     32
#define A3LTE_FB_SIZE      (A3LTE_FB_STRIDE * A3LTE_FB_HEIGHT)

/* UART registers (PL011 compatible) */
#define UART_DR            0x00
#define UART_RSR_ECR       0x04
#define UART_FR            0x18
#define UART_ILPR          0x20
#define UART_IBRD          0x24
#define UART_FBRD          0x28
#define UART_LCR_H         0x2C
#define UART_CR            0x30
#define UART_IFLS          0x34
#define UART_IMSC          0x38
#define UART_RIS           0x3C
#define UART_MIS           0x40
#define UART_ICR           0x44
#define UART_DMACR         0x48

/* UART flags */
#define UART_FR_TXFF       (1 << 5)
#define UART_FR_RXFE       (1 << 4)
#define UART_FR_BUSY       (1 << 3)

/* GICv2 registers */
#define GIC_DIST_CTRL      0x0000
#define GIC_DIST_TYPER     0x0004
#define GIC_DIST_IIDR      0x0008
#define GIC_DIST_IGROUP    0x0080
#define GIC_DIST_ISENABLE  0x0100
#define GIC_DIST_ICENABLE  0x0180
#define GIC_DIST_ISPEND    0x0200
#define GIC_DIST_ICPEND    0x0280
#define GIC_DIST_ISACTIVE  0x0300
#define GIC_DIST_ICACTIVE  0x0380
#define GIC_DIST_IPRI      0x0400
#define GIC_DIST_ITARGETS  0x0800
#define GIC_DIST_ICFGR     0x0C00

#define GIC_CPU_CTRL       0x0000
#define GIC_CPU_PRIMASK    0x0004
#define GIC_CPU_BINPOINT   0x0008
#define GIC_CPU_IAR        0x000C
#define GIC_CPU_EOI        0x0010
#define GIC_CPU_RPR        0x0014
#define GIC_CPU_HPI        0x0018
#define GIC_CPU_ABPR       0x001C

/* Timer registers (Generic Timer) */
#define CNTCTL_BASE        0x0000
#define CNTCTL_CNTCR       0x0000
#define CNTCTL_CNTSR       0x0004
#define CNTCTL_CNTCV       0x0008
#define CNTCTL_CNTVOFF     0x0010

/* Timer frequency */
#define A3LTE_TIMER_FREQ   19200000

/* CPU count */
#define A3LTE_CPU_COUNT    4

/* Function prototypes */
void a3lte_uart_init(void);
void a3lte_uart_putc(char c);
void a3lte_cpu_init(void);
void a3lte_pmic_init(void);
void a3lte_sdhci_init(void);
void a3lte_display_init(void);
void a3lte_touch_init(void);
void a3lte_gic_init(void);
void a3lte_timer_init(void);
void a3lte_spin_table_init(void);

#endif /* _PEXPERT_ARM64_A3LTE_A3LTE_H_ */
