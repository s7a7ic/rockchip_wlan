// SPDX-License-Identifier: GPL-2.0
/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PHYDM_PHYSTATUS_H__
#define __PHYDM_PHYSTATUS_H__

/*--------------------------Define -------------------------------------------*/
#define	CCK_RSSI_INIT_COUNT 5

#define	RA_RSSI_STATE_INIT	0
#define	RA_RSSI_STATE_SEND	1
#define	RA_RSSI_STATE_HOLD	2

#define	CFO_HW_RPT_2_MHZ(val) ((val<<1) + (val>>1))
/* ((X* 3125)  / 10)>>7 = (X*10)>>2 = X*2.5 = X<<1 + X>>1  */

/* ************************************************************
 * structure and define
 * ************************************************************ */

__PACK struct _phy_rx_agc_info {
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8	gain: 7, trsw: 1;
#else
	u8	trsw: 1, gain: 7;
#endif
};

__PACK struct _phy_status_rpt_8192cd {
	struct _phy_rx_agc_info path_agc[2];
	u8	ch_corr[2];
	u8	cck_sig_qual_ofdm_pwdb_all;
	u8	cck_agc_rpt_ofdm_cfosho_a;
	u8	cck_rpt_b_ofdm_cfosho_b;
	u8	rsvd_1;/*ch_corr_msb;*/
	u8	noise_power_db_msb;
	s8	path_cfotail[2];
	u8	pcts_mask[2];
	s8	stream_rxevm[2];
	u8	path_rxsnr[2];
	u8	noise_power_db_lsb;
	u8	rsvd_2[3];
	u8	stream_csi[2];
	u8	stream_target_csi[2];
	s8	sig_evm;
	u8	rsvd_3;

#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8	antsel_rx_keep_2: 1;	/*ex_intf_flg:1;*/
	u8	sgi_en: 1;
	u8	rxsc: 2;
	u8	idle_long: 1;
	u8	r_ant_train_en: 1;
	u8	ant_sel_b: 1;
	u8	ant_sel: 1;
#else	/*_BIG_ENDIAN_	*/
	u8	ant_sel: 1;
	u8	ant_sel_b: 1;
	u8	r_ant_train_en: 1;
	u8	idle_long: 1;
	u8	rxsc: 2;
	u8	sgi_en: 1;
	u8	antsel_rx_keep_2: 1;/*ex_intf_flg:1;*/
#endif
};

struct _phy_status_rpt_8812 {
	/*	DWORD 0*/
	u8			gain_trsw[2];							/*path-A and path-B {TRSW, gain[6:0] }*/
	u8			chl_num_LSB;							/*channel number[7:0]*/
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8			chl_num_MSB: 2;							/*channel number[9:8]*/
	u8			sub_chnl: 4;								/*sub-channel location[3:0]*/
	u8			r_RFMOD: 2;								/*RF mode[1:0]*/
#else	/*_BIG_ENDIAN_	*/
	u8			r_RFMOD: 2;
	u8			sub_chnl: 4;
	u8			chl_num_MSB: 2;
#endif

	/*	DWORD 1*/
	u8			pwdb_all;								/*CCK signal quality / OFDM pwdb all*/
	s8			cfosho[2];		/*DW1 byte 1 DW1 byte2	CCK AGC report and CCK_BB_Power / OFDM path-A and path-B short CFO*/
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	/*this should be checked again because the definition of 8812 and 8814 is different*/
	/*	u8			r_cck_rx_enable_pathc:2;					cck rx enable pathc[1:0]*/
	/*	u8			cck_rx_path:4;							cck rx path[3:0]*/
	u8			resvd_0: 6;
	u8			bt_RF_ch_MSB: 2;						/*8812A:2'b0			8814A: bt rf channel keep[7:6]*/
#else	/*_BIG_ENDIAN_*/
	u8			bt_RF_ch_MSB: 2;
	u8			resvd_0: 6;
#endif

	/*	DWORD 2*/
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8			ant_div_sw_a: 1;							/*8812A: ant_div_sw_a    8814A: 1'b0*/
	u8			ant_div_sw_b: 1;							/*8812A: ant_div_sw_b    8814A: 1'b0*/
	u8			bt_RF_ch_LSB: 6;						/*8812A: 6'b0                   8814A: bt rf channel keep[5:0]*/
#else	/*_BIG_ENDIAN_	*/
	u8			bt_RF_ch_LSB: 6;
	u8			ant_div_sw_b: 1;
	u8			ant_div_sw_a: 1;
#endif
	s8			cfotail[2];		   /*DW2 byte 1 DW2 byte 2	path-A and path-B CFO tail*/
	u8			PCTS_MSK_RPT_0;						/*PCTS mask report[7:0]*/
	u8			PCTS_MSK_RPT_1;						/*PCTS mask report[15:8]*/

	/*	DWORD 3*/
	s8			rxevm[2];	         /*DW3 byte 1 DW3 byte 2	stream 1 and stream 2 RX EVM*/
	s8			rxsnr[2];	         /*DW3 byte 3 DW4 byte 0	path-A and path-B RX SNR*/

	/*	DWORD 4*/
	u8			PCTS_MSK_RPT_2;						/*PCTS mask report[23:16]*/
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8			PCTS_MSK_RPT_3: 6;						/*PCTS mask report[29:24]*/
	u8			pcts_rpt_valid: 1;							/*pcts_rpt_valid*/
	u8			resvd_1: 1;								/*1'b0*/
#else	/*_BIG_ENDIAN_*/
	u8			resvd_1: 1;
	u8			pcts_rpt_valid: 1;
	u8			PCTS_MSK_RPT_3: 6;
#endif
	s8			rxevm_cd[2];	   /*DW 4 byte 3 DW5 byte 0  8812A: 16'b0	8814A: stream 3 and stream 4 RX EVM*/

	/*	DWORD 5*/
	u8			csi_current[2];	   /*DW5 byte 1 DW5 byte 2	8812A: stream 1 and 2 CSI	8814A:  path-C and path-D RX SNR*/
	u8			gain_trsw_cd[2];	   /*DW5 byte 3 DW6 byte 0	path-C and path-D {TRSW, gain[6:0] }*/

	/*	DWORD 6*/
	s8			sigevm;									/*signal field EVM*/
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8			antidx_antc: 3;							/*8812A: 3'b0		8814A: antidx_antc[2:0]*/
	u8			antidx_antd: 3;							/*8812A: 3'b0		8814A: antidx_antd[2:0]*/
	u8			dpdt_ctrl_keep: 1;						/*8812A: 1'b0		8814A: dpdt_ctrl_keep*/
	u8			GNT_BT_keep: 1;							/*8812A: 1'b0		8814A: GNT_BT_keep*/
#else	/*_BIG_ENDIAN_*/
	u8			GNT_BT_keep: 1;
	u8			dpdt_ctrl_keep: 1;
	u8			antidx_antd: 3;
	u8			antidx_antc: 3;
#endif
#if (ODM_ENDIAN_TYPE == ODM_ENDIAN_LITTLE)
	u8			antidx_anta: 3;							/*antidx_anta[2:0]*/
	u8			antidx_antb: 3;							/*antidx_antb[2:0]*/
	u8			hw_antsw_occur: 2;								/*1'b0*/
#else	/*_BIG_ENDIAN_*/
	u8			hw_antsw_occur: 2;
	u8			antidx_antb: 3;
	u8			antidx_anta: 3;
#endif
};

void phydm_reset_phystatus_avg(struct PHY_DM_STRUCT *p_dm);

void phydm_reset_phystatus_statistic(struct PHY_DM_STRUCT *p_dm);

void phydm_reset_rssi_for_dm(struct PHY_DM_STRUCT *p_dm, u8 station_id);

void phydm_get_cck_rssi_table_from_reg(struct PHY_DM_STRUCT *p_dm);

u8 phydm_rate_to_num_ss(struct PHY_DM_STRUCT *p_dm, u8 data_rate);

s32 phydm_signal_scale_mapping(struct PHY_DM_STRUCT *p_dm, s32 curr_sig);

void odm_phy_status_query(
	struct PHY_DM_STRUCT					*p_dm,
	struct phydm_phyinfo_struct			*p_phy_info,
	u8						*p_phy_status,
	struct phydm_perpkt_info_struct			*p_pktinfo
);

void phydm_rx_phy_status_init(void *p_dm_void);

#endif /* __HALHWOUTSRC_H__ */
