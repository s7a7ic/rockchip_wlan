// SPDX-License-Identifier: GPL-2.0
/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PHYDM_PRIMARYCCA_H__
#define __PHYDM_PRIMARYCCA_H__

#define PRIMARYCCA_VERSION	"1.0"  /*2017.03.23, Dino*/

#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
#define	SECOND_CH_AT_LSB	2	/*primary CH @ MSB,  SD4: HAL_PRIME_CHNL_OFFSET_UPPER*/
#define	SECOND_CH_AT_USB	1	/*primary CH @ LSB,   SD4: HAL_PRIME_CHNL_OFFSET_LOWER*/
#endif

#define	OFDMCCA_TH	500
#define	bw_ind_bias		500
#define	PRI_CCA_MONITOR_TIME	30

#endif /* __PHYDM_PRIMARYCCA_H__ */
