/*
 * Copyright (C) 2012-2016 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale i.MX6Q SabreSD board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX6QSABRESD_CONFIG_H
#define __MX6QSABRESD_CONFIG_H

#define CONFIG_MACH_TYPE	3980
#define CONFIG_MXC_UART_BASE	UART5_BASE
#define CONFIG_CONSOLE_DEV	"ttymxc4"
#define CONFIG_MMCROOT		"/dev/mmcblk2p2"  /* SDHC3 */

#define PHYS_SDRAM_SIZE		(128u * 1024 * 1024)

#include "mx6sabre_common.h"

#define CONFIG_SYS_FSL_USDHC_NUM	3
#define CONFIG_SYS_MMC_ENV_DEV		1	/* SDHC3 */
#define CONFIG_SYS_MMC_ENV_PART		0       /* user partition */

/*
 * imx6 q/dl/solo pcie would be failed to work properly in kernel, if
 * the pcie module is iniialized/enumerated both in uboot and linux
 * kernel.
 * rootcause:imx6 q/dl/solo pcie don't have the reset mechanism.
 * it is only be RESET by the POR. So, the pcie module only be
 * initialized/enumerated once in one POR.
 * Set to use pcie in kernel defaultly, mask the pcie config here.
 * Remove the mask freely, if the uboot pcie functions, rather than
 * the kernel's, are required.
 */
/* #define CONFIG_CMD_PCI */
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW
#define CONFIG_PCIE_IMX
#define CONFIG_PCIE_IMX_PERST_GPIO	IMX_GPIO_NR(7, 12)
#define CONFIG_PCIE_IMX_POWER_GPIO	IMX_GPIO_NR(3, 19)
#endif

#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS \
	"fdt_addr=0x18000000\0" \
	"bootargs=console=" CONFIG_CONSOLE_DEV ",115200\0"\
	"bootcmd=cp.b 0x08100000 0x12000000 0x018C0000;"\
		"cp.b 0x080E0000 0x18000000 0x00020000;"\
		"bootz ${loadaddr} - ${fdt_addr}\0"

#undef CONFIG_CI_UDC
#undef CONFIG_USBD_HS
#undef CONFIG_USB_GADGET_DUALSPEED

#undef CONFIG_USB_GADGET
#undef CONFIG_CMD_USB_MASS_STORAGE
#undef CONFIG_USB_FUNCTION_MASS_STORAGE

#undef CONFIG_CMD_DFU
#undef CONFIG_USB_FUNCTION_DFU

#undef CONFIG_CMD_NET

#undef CONFIG_VIDEO
#undef CONFIG_VIDEO_IPUV3
#undef CONFIG_CFB_CONSOLE
#undef CONFIG_IMX_HDMI
#undef CONFIG_IMX_VIDEO_SKIP

#undef CONFIG_MMC
#undef CONFIG_CMD_MMC
#undef CONFIG_GENERIC_MMC
#undef CONFIG_FSL_ESDHC
#undef CONFIG_FSL_USDHC

#endif                         /* __MX6QSABRESD_CONFIG_H */
