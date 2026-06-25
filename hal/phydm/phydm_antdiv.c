// SPDX-License-Identifier: GPL-2.0
/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 ******************************************************************************/
#include "phydm_precomp.h"

/* ******************************************************
 * when antenna test utility is on or some testing need to disable antenna diversity
 * call this function to disable all ODM related mechanisms which will switch antenna.
 * ****************************************************** */

void odm_ant_div_reset(void *p_dm_void)
{
	struct PHY_DM_STRUCT		*p_dm = (struct PHY_DM_STRUCT *)p_dm_void;
}
