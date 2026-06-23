// SPDX-License-Identifier: GPL-2.0
/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 ******************************************************************************/
#ifndef __HAL_IC_CFG_H__
#define __HAL_IC_CFG_H__

#define RTL8723B_SUPPORT				0

#ifdef CONFIG_RTL8723B
	#undef RTL8723B_SUPPORT
	#define RTL8723B_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
#endif

#endif /*__HAL_IC_CFG_H__*/
