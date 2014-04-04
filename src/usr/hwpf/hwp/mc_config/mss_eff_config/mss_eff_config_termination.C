/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_termination.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_eff_config_termination.C,v 1.46 2014/03/14 17:08:42 kcook Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_termination.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_termination
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Dave Cadigan      Email: dcadiga@us.ibm.com
// *! BACKUP NAME : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This procedure is a place holder for attributes set by the machine parsable workbook.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.46  | kcook    |14-MAR-14| Fixed create_db_ddr4 stub function definition
//   1.45  | kcook    |14-MAR-14| Added DDR4 support
//   1.44  | mjjones  |07-MAR-14| Only compile if FAPI_MSSLABONLY defined
//   1.43  | dcadiga  |04-MAR-14| Added in ISDimm support for KG 
//   1.42  | asaetow  |22-JAN-14| Fixed target "const fapi::Target" to "const fapi::Target&" for mss_eff_config.C v1.38 and mss_eff_config_termination.H v1.2
//   1.41  | dcadiga  |13-JAN-14| Removed checking of dimm type attribute for CDIMM, replaced with custom dimm type attribute
//   1.40  | bellows  |02-JAN-14| VPD attribute removal
//   1.39  | bellows  |25-NOV-13| removed dimm spare temp, added using namespace fapi
//   1.38  | dcadiga  |22-NOV-13| DDR4 ATTR_VREF_DQ_TRAIN_VALUE change for Menlo (0 to 16)
//   1.37  | dcadiga  |22-NOV-13| New Settings for RC/A and RC/C from Nov5/2013 Spreadsheet, DDR4 Enum Update
//   1.36  | bellows  |19-SEP-13| Patched the AM keyword workaround.for >1 ranks
//   1.35  | bellows  |16-SEP-13| Hostboot compile update.
//   1.34  | kcook    |13-SEP-13| Updated define FAPI_LRDIMM token.
//   1.33  | bellows  |12-SEP-13| set_vpd_dimm_spare function added before AM keyword shows up
//   1.32  | kcook    |27-AUG-13| Removed LRDIMM support to mss_lrdimm_funcs.C.       
//   1.31  | kcook    |16-AUG-13| Added LRDIMM support.       
//   1.30  | dcadiga  |07-AUG-13| Fixed hostboot compile issue
//   1.29  | dcadiga  |05-AUG-13| KG3 allowed, ifdef removed for lab card uint declaration, added 4R support to 1600, changed 4Rx4 / 4Rx8 RCD Drive Settings
//   1.28  | asaetow  |05-AUG-13| Added temp workaround for incorrect byte33 SPD data in early lab OLD 16G/32G CDIMMs.
//         |          |         | NOTE: Do NOT pickup without mss_eff_config.C v1.27 or newer, contains EFF_STACK_TYPE_DDP_QDP support.
//   1.27  | bellows  |24-JUL-13| KG3 support #def for cronus only compiles
//   1.26  | dcadiga  |28-JUN-13| Fixed checking of lab_only_rc
//   1.25  | dcadiga  |26-JUN-13| B4 Change to run regardless of ranks configured, Set code to point back to B4 settings instead of B settings (was test mode)
//   1.24  | dcadiga  |25-JUN-13| KG3 Settings, RLO Settings,WLO,GPO Settings. KG3 DISABLED FOR NOW.  Also added lab_rc check and set
//   1.23  | dcadiga  |03-JUN-13| Updated B4 settings and 2 Socket ISDIMM Configs
//   1.22  | asaetow  |17-MAY-13| Added DDR4 attr and ATTR_EFF_DRAM_ADDRESS_MIRRORING attr.
//   1.21  | dcadiga  |07-MAY-13| Fixed RC/A Clk Drive and Impedance Settings, Added RC B4 and some patches to make it work, Added in fix for AL in 2N mode
//   1.20  | dcadiga  |30-APR-13| Fixed Hostboot Compile Error LN 972
//   1.19  | dcadiga  |19-APR-13| Added Cdimm RCB/RCC, changed RDIMM settings for MBA0 so that a 1R card will work and a 4R card will work
//   1.18  | dcadiga  |10-APR-13| Added UDIMM for ICICLE DDR4, fixed DD0 Clk shift
//   1.17  | asaetow  |26-MAR-13| Removed width check for RDIMM MBA0 4Rank 1333. 
//   1.16  | dcadiga  |25-MAR-13| Added in 2N Addressing Mode.
//   1.15  | dcadiga  |14-MAR-13| Fixed simulation issue.
//   1.14  | dcadiga  |12-MAR-13| Code re-write for new dimms.  Confirmed working on all systems
//   1.13  | asaetow  |19-FEB-12| Changed default SI value for CDIMM, turned of Rtt_NOM and disabled Rtt_WR for DIMM1.
//   1.12  | asaetow  |07-FEB-12| Added check for Centaur EC10 ADR Centerlane NWELL workaround.
//   1.11  | asaetow  |22-DEC-12| Added CDIMM workaround for EC10 ADR Centerlane race condition, subtract 32ticks.
//         |          |         | NOTE: Need EC check for Centaur EC10 ADR Centerlane NWELL workaround.
//   1.10  | asaetow  |22-DEC-12| Added Centaur EC10 ADR Centerlane PR=0x7F workaround for NWELL LVS issue.
//         |          |         | NOTE: Need EC check for Centaur EC10 ADR Centerlane NWELL workaround.
//         |          |         | Fixed (l_attr_is_simulation || 1) to (l_attr_is_simulation != 0) from v1.8 and v1.9.
//   1.9   | bellows  |12-DEC-12| Changed phase rotators for sim to 0x40 for clocks
//   1.8   | bellows  |06-DEC-12| Added sim leg for rotator values
//   1.7   | asaetow  |18-NOV-12| Changed ATTR_MSS_CAL_STEP_ENABLE from 0x7F back to 0xFF. 
//   1.6   | asaetow  |17-NOV-12| Fixed uint8_t attr_eff_odt_wr for 4R RDIMMs.
//   1.5   | asaetow  |17-NOV-12| Added PR settings.
//         |          |         | Fixed RCD settings for RDIMM.
//   1.4   | asaetow  |17-NOV-12| Changed ATTR_MSS_CAL_STEP_ENABLE from 0xFF to 0x7F. 
//   1.3   | asaetow  |05-NOV-12| Added Paul's SI value for pre-machine parsable workbook.
//         |          |         | NOTE: DO NOT pick-up without memory_attributes.xml v1.45 or newer.
//   1.2   | asaetow  |05-SEP-12| Added ATTR_MSS_CAL_STEP_ENABLE.
//   1.1   | asaetow  |30-APR-12| First Draft.

#ifdef FAPI_MSSLABONLY

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

#include <mss_lrdimm_funcs.H>
#include <mss_ddr4_funcs.H>
#include <mss_lrdimm_ddr4_funcs.H>

using namespace fapi;



#ifndef FAPI_LRDIMM
using namespace fapi;
fapi::ReturnCode mss_lrdimm_rewrite_odt( const Target& i_target_mba,
                                  uint32_t *p_b_var_array,
                                  uint32_t *var_array_p_array[5])
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of LRDIMM function on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
ReturnCode mss_lrdimm_term_atts(const Target& i_target_mba) 
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of LRDIMM function on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
#endif

#ifndef FAPI_DDR4
fapi::ReturnCode mss_create_rcd_ddr4(const Target& i_target_mba)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mss_create_rcd_ddr4 on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
fapi::ReturnCode mss_create_db_ddr4(const Target& i_target_mba)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mss_create_db_ddr4 on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
fapi::ReturnCode mss_lrdimm_ddr4_term_atts(const Target& i_target_mba)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of mss_lrdimm_ddr4_term_atts on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
   return rc;

}
#endif

//----------------------------------------------------------------------
// ENUMs and CONSTs
//----------------------------------------------------------------------

// Define attribute array size
const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;
const uint8_t RANK_SIZE = 4;

// Define the size of the array that holds the values to set - Now done when we determine if isdimm
const uint8_t STORE_ARRAY_SIZE = 10;

//Declare all Static Arrays

uint32_t attr_eff_dimm_rcd_ibt[PORT_SIZE][DIMM_SIZE];
uint8_t attr_eff_dimm_rcd_mirror_mode[PORT_SIZE][DIMM_SIZE];
uint32_t attr_eff_cen_rd_vref[PORT_SIZE];
uint32_t attr_eff_dram_wr_vref[PORT_SIZE];
uint8_t attr_eff_dram_wrddr4_vref[PORT_SIZE];
uint8_t attr_eff_cen_rcv_imp_dq_dqs[PORT_SIZE];
uint8_t attr_eff_cen_drv_imp_dq_dqs[PORT_SIZE];
uint8_t attr_eff_cen_slew_rate_dq_dqs[PORT_SIZE];
uint8_t l_attr_vpd_2n_mode_enabled;
uint8_t attr_eff_dram_al;
uint8_t attr_eff_rlo[PORT_SIZE];
uint8_t attr_eff_wlo[PORT_SIZE];
uint8_t attr_eff_gpo[PORT_SIZE];
uint8_t attr_eff_dram_2n_mode_enabled[PORT_SIZE];




//Declare all Static Arrays

uint8_t attr_vpd_dram_ron[PORT_SIZE][DIMM_SIZE];
uint8_t attr_vpd_dram_rtt_nom[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
uint8_t attr_vpd_dram_rtt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
uint8_t attr_vpd_odt_rd[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
uint8_t attr_vpd_odt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
uint8_t attr_vpd_cen_drv_imp_cntl[PORT_SIZE];
uint8_t attr_vpd_cen_drv_imp_addr[PORT_SIZE];
uint8_t attr_vpd_cen_drv_imp_clk[PORT_SIZE];
uint8_t attr_vpd_cen_drv_imp_spcke[PORT_SIZE];
uint8_t attr_vpd_cen_slew_rate_cntl[PORT_SIZE];
uint8_t attr_vpd_cen_slew_rate_addr[PORT_SIZE];
uint8_t attr_vpd_cen_slew_rate_clk[PORT_SIZE];
uint8_t attr_vpd_cen_slew_rate_spcke[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_clk_p0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_clk_p1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_clk_p0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_clk_p1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a3[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a4[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a5[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a6[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a7[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a8[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a9[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a10[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a11[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a12[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a13[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a14[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_a15[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_bA0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_bA1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_bA2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_casn[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_rasn[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_cmd_wen[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_par[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m_actn[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_cke0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_cke1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_cke2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_cke3[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_csn0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_csn1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_csn2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_csn3[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_odt0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m0_cntl_odt1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_cke0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_cke1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_cke2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_cke3[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_csn0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_csn1[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_csn2[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_csn3[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_odt0[PORT_SIZE];
uint8_t attr_vpd_cen_phase_rot_m1_cntl_odt1[PORT_SIZE];


//Declare the different dimms here:
//Cdimm rc_A
uint32_t cdimm_default[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};

uint32_t cdimm_rca_1r_1333_mba1[STORE_ARRAY_SIZE] =
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};

uint32_t cdimm_rca_1r_1600_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};

//Cdimm rc_A DD1.0

//RCB

//RCB4

uint32_t cdimm_rcb4_2r_1600_mba0[210] =
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD68625,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD68625,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,93,91,90,92,4,5,5,4,0,0,4,2,5,4,10,3,6,3,5,10,9,8,11,12,11,11,11,12,10,0,27,0,2,0,0,0,6,0,10,0,29,0,16,0,0,0,8,0,91,98,93,98,11,8,12,4,1,0,3,0,10,4,12,5,10,8,6,10,7,6,11,13,16,13,7,5,10,0,30,0,8,0,0,0,7,0,12,0,31,0,10,0,0,0,4,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t cdimm_rcb4_2r_1600_mba1[210] =
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD68625,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD68625,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM20,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,108,117,108,117,18,18,17,22,21,22,24,24,28,17,15,18,17,20,18,15,19,21,14,14,18,14,15,14,10,0,55,0,15,0,0,0,0,0,13,0,56,0,0,0,0,0,13,0,117,114,117,113,21,22,26,22,23,24,25,24,25,27,18,26,20,24,26,20,21,22,19,20,17,18,24,29,0,0,53,0,1,0,0,0,0,0,0,0,52,0,11,0,0,0,1,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

//RCC

/*

//RDIMM A/B Ports MBA0 Glacier
uint32_t rdimm_glacier_1600_r10_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r20e_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r20e_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r20b_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r20b_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r40_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};


//RDIMM C/D Ports MBA1 Glacier

uint32_t rdimm_glacier_1333_r10_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r10_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r20e_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r20e_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r20b_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r20b_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1066_r40_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r11_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r11_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r22e_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r22e_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1333_r22b_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1600_r22b_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_glacier_1066_r44_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};

//UDIMM TEMP FOR JAKE ICICLE
uint32_t udimm_glacier_1600_r10_mba0[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};

uint32_t udimm_glacier_1600_r10_mba1[STORE_ARRAY_SIZE] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF
};


//KG3 

uint32_t rdimm_kg3_1333_r1_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r1_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r1_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r1_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r2b_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r2b_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r2b_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};


uint32_t rdimm_kg3_1600_r2b_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};


uint32_t rdimm_kg3_1333_r2e_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r2e_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r2e_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r2e_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r4_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1333_r4_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r4_mba0[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};

uint32_t rdimm_kg3_1600_r4_mba1[STORE_ARRAY_SIZE] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON
};
*/


//RDIMM A/B Ports MBA0 Glacier
uint32_t rdimm_glacier_1600_r10_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,63,0,0,0,2,3,2,5,0,1,4,3,6,2,8,3,4,3,3,8,8,8,8,9,8,9,8,0,3,12,0,0,0,12,2,12,3,11,0,0,0,0,0,0,0,0,0,0,70,0,0,0,8,6,9,4,2,0,3,2,10,1,9,3,7,6,3,6,6,5,7,9,11,10,4,0,3,5,0,0,4,10,3,12,3,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r20e_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,67,0,0,0,1,2,2,4,0,1,3,2,5,2,6,3,3,3,2,7,7,7,6,8,6,7,7,0,2,10,0,0,0,10,2,10,2,9,0,0,0,0,0,0,0,0,0,0,71,0,0,0,7,5,7,3,2,0,2,1,8,1,8,2,6,5,3,5,5,4,6,7,9,9,3,0,1,3,0,0,3,7,2,9,1,10,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r20e_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,66,0,0,0,2,3,2,5,0,1,4,3,6,2,8,3,4,3,3,8,8,8,8,9,8,9,8,0,3,12,0,0,0,12,2,12,3,11,0,0,0,0,0,0,0,0,0,0,75,0,0,0,8,6,9,4,2,0,3,2,10,1,9,3,7,6,3,6,6,5,8,9,11,11,4,0,3,5,0,0,4,10,3,12,3,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r20b_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,63,0,0,0,2,2,2,4,0,1,3,2,5,2,6,3,3,3,2,6,7,7,6,8,6,7,7,0,2,10,0,0,0,10,2,10,2,9,0,0,0,0,0,0,0,0,0,0,68,0,0,0,7,5,7,3,2,0,2,1,8,1,8,2,6,5,3,5,5,4,6,7,9,9,3,0,2,4,0,0,4,8,3,10,2,10,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r20b_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,63,0,0,0,2,3,2,5,0,1,4,3,6,2,8,3,4,3,3,8,8,8,8,9,8,9,8,0,3,12,0,0,0,12,2,12,3,11,0,0,0,0,0,0,0,0,0,0,70,0,0,0,8,6,9,4,2,0,3,2,10,1,9,3,7,6,3,6,6,5,8,9,11,11,4,0,3,5,0,0,5,10,3,12,3,13,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r40_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0xC0,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,0xC0,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,63,0,0,0,2,3,2,4,1,1,4,3,5,2,7,3,4,3,3,7,7,7,7,8,7,8,7,0,3,11,0,0,1,11,3,11,3,10,0,0,0,0,0,0,0,0,0,0,71,0,0,0,7,5,7,3,2,0,2,1,8,1,8,2,6,5,3,5,5,4,6,7,9,9,3,0,2,4,0,0,4,8,3,10,3,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

//RDIMM C/D Ports MBA1 Glacier

uint32_t rdimm_glacier_1333_r10_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,69,0,0,0,12,11,12,11,8,12,13,13,16,12,9,12,11,14,12,7,9,10,7,8,11,6,9,0,8,1,0,0,10,1,10,4,3,1,0,0,0,0,0,0,0,0,0,0,69,0,0,0,10,10,13,10,11,13,13,12,13,13,9,13,10,12,13,10,10,10,9,10,8,8,12,0,4,11,0,0,4,12,4,11,3,9,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r10_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,15,13,15,14,10,15,16,17,21,15,11,15,13,18,15,9,11,13,8,10,14,7,11,0,10,2,0,0,13,2,12,5,4,2,0,0,0,0,0,0,0,0,0,0,71,0,0,0,12,13,16,13,13,16,16,15,16,17,11,16,12,15,17,12,12,13,11,12,9,10,15,0,4,14,0,0,4,15,4,13,4,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r20e_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,73,0,0,0,12,11,12,11,8,12,13,13,16,12,9,12,11,14,12,7,9,10,7,8,11,6,9,0,8,1,0,0,10,1,10,4,3,1,0,0,0,0,0,0,0,0,0,0,73,0,0,0,10,10,13,11,11,13,13,12,13,13,9,13,10,12,13,10,10,10,9,10,8,8,12,0,4,11,0,0,4,12,4,11,3,9,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r20e_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,77,0,0,0,15,13,15,14,10,15,16,17,21,15,11,15,13,18,15,9,11,13,8,10,14,7,11,0,9,1,0,0,13,2,12,5,4,1,0,0,0,0,0,0,0,0,0,0,77,0,0,0,12,13,16,13,13,16,16,15,16,17,11,16,13,15,17,12,12,13,11,12,9,10,15,0,4,14,0,0,4,15,4,13,3,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r20b_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,69,0,0,0,12,10,12,11,8,11,13,13,16,12,9,12,10,14,12,7,9,10,7,8,11,6,9,0,8,1,0,0,10,1,10,4,3,1,0,0,0,0,0,0,0,0,0,0,69,0,0,0,10,10,13,10,10,13,13,12,13,13,8,13,10,12,13,10,9,10,9,10,8,8,12,0,4,11,0,0,4,12,4,11,3,9,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r20b_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,14,13,15,14,10,14,16,17,21,15,11,15,13,17,15,9,11,13,8,10,14,7,11,0,10,1,0,0,13,2,12,5,4,1,0,0,0,0,0,0,0,0,0,0,71,0,0,0,12,13,16,13,13,16,16,15,16,16,10,16,12,15,17,12,12,12,11,12,9,9,15,0,4,14,0,0,4,15,4,13,4,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1066_r40_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0xC0,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,0xC0,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,69,0,0,0,10,9,10,9,7,10,11,11,14,10,7,10,9,12,10,6,7,8,5,7,9,5,7,0,7,1,0,0,9,1,8,3,3,1,0,0,0,0,0,0,0,0,0,0,69,0,0,0,8,8,11,8,9,10,11,10,11,11,7,11,8,10,11,8,8,8,7,8,6,6,10,0,3,10,0,0,3,10,3,9,2,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r11_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,73,0,69,0,18,17,18,17,14,18,19,19,22,18,15,18,17,20,18,13,15,16,13,14,17,12,15,0,11,5,0,0,14,5,13,7,7,5,11,2,0,0,3,3,5,3,8,2,73,0,69,0,16,16,19,16,17,19,19,18,19,19,15,19,16,18,19,16,16,16,15,16,14,14,18,0,7,15,0,0,7,15,7,14,6,13,4,12,0,0,9,14,9,11,4,11,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r11_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,0xA0,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,76,0,71,0,21,20,22,20,17,21,23,23,27,22,18,22,20,24,21,15,18,20,15,17,20,14,18,0,14,6,0,0,17,6,17,10,9,6,13,2,0,0,4,3,5,3,10,3,76,0,71,0,19,20,23,20,20,23,23,22,23,23,17,23,19,22,23,19,19,19,18,19,16,16,22,0,9,19,0,0,9,20,9,18,8,16,4,15,0,0,11,17,10,13,5,13,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r22e_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,77,0,72,0,17,16,18,17,14,17,18,19,22,18,15,18,16,19,17,13,14,16,12,14,17,11,14,0,12,5,0,0,14,5,14,8,7,5,11,2,0,0,3,3,5,3,8,2,77,0,72,0,16,16,19,16,16,18,19,18,19,19,14,18,16,18,19,16,15,16,15,16,13,13,18,0,8,15,0,0,8,16,8,15,7,13,4,12,0,0,9,14,9,11,4,11,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r22e_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,81,0,77,0,21,19,21,20,16,21,22,23,27,22,17,21,19,23,21,15,17,19,14,16,20,13,17,0,13,5,0,0,16,5,15,8,7,5,13,2,0,0,4,3,5,3,10,2,81,0,77,0,19,19,23,19,19,22,23,21,23,23,17,22,19,21,23,19,18,19,18,19,16,16,22,0,7,17,0,0,8,18,8,16,7,15,4,15,0,0,11,17,10,13,5,13,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1333_r22b_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,73,0,69,0,16,14,16,15,12,16,17,17,21,16,12,16,14,18,16,10,12,14,10,12,15,9,12,0,12,6,0,0,15,6,14,8,8,6,11,2,0,0,3,3,5,3,8,2,73,0,69,0,14,14,17,14,14,17,17,16,17,17,12,17,14,16,17,13,13,14,13,14,11,11,16,0,8,16,0,0,8,17,8,15,7,14,4,12,0,0,9,14,9,11,4,10,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1600_r22b_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0x20,0x10,0x00,0x00,0x80,0x40,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,0xA0,0x50,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,78,0,71,0,20,18,20,19,15,20,21,22,26,21,16,21,18,23,20,14,16,18,13,15,19,12,16,0,16,8,0,0,20,8,19,12,11,8,14,2,0,0,4,3,6,3,10,3,78,0,71,0,17,18,22,18,18,21,22,20,22,22,15,21,17,20,22,17,17,17,16,17,14,14,21,0,11,21,0,0,11,22,11,20,10,18,4,15,0,0,11,17,11,13,5,13,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_glacier_1066_r44_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM20,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,0x20,0x20,0x20,0x20,0x80,0x80,0x80,0x80,0x20,0x20,0x20,0x20,0x80,0x80,0x80,0x80,0xA0,0x20,0x60,0x20,0xA0,0x80,0x90,0x80,0xA0,0x20,0x60,0x20,0xA0,0x80,0x90,0x80,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,74,0,68,0,15,14,15,14,12,15,16,16,19,15,12,15,14,17,15,11,12,14,10,12,14,9,12,0,12,7,0,0,15,7,14,9,9,7,9,1,0,0,3,2,4,3,7,2,74,0,68,0,13,14,16,14,14,16,16,15,16,16,12,16,13,15,16,13,13,13,12,13,11,11,15,0,9,15,0,0,9,16,9,15,8,14,3,10,0,0,8,12,7,9,3,9,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

//UDIMM TEMP FOR JAKE ICICLE
uint32_t udimm_glacier_1600_r10_mba0[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,63,0,0,0,2,3,2,5,0,1,4,3,6,2,8,3,4,3,3,8,8,8,8,9,8,9,8,0,3,12,0,0,0,12,2,12,3,11,0,0,0,0,0,0,0,0,0,0,70,0,0,0,8,6,9,4,2,0,3,2,10,1,9,3,7,6,3,6,6,5,7,9,11,10,4,0,3,5,0,0,4,10,3,12,3,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t udimm_glacier_1600_r10_mba1[210] = 
{fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,15,13,15,14,10,15,16,17,21,15,11,15,13,18,15,9,11,13,8,10,14,7,11,0,10,2,0,0,13,2,12,5,4,2,0,0,0,0,0,0,0,0,0,0,71,0,0,0,12,13,16,13,13,16,16,15,16,17,11,16,12,15,17,12,12,13,11,12,9,10,15,0,4,14,0,0,4,15,4,13,4,12,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};


//KG3 

uint32_t rdimm_kg3_1333_r1_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r1_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r1_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r1_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r2b_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r2b_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r2b_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};


uint32_t rdimm_kg3_1600_r2b_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};


uint32_t rdimm_kg3_1333_r2e_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r2e_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r2e_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r2e_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r4_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1333_r4_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r4_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg3_1600_r4_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM30,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

//KG4

uint32_t rdimm_kg4_1600_r1_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r1_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r2b_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r2b_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r2e_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r2e_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM40,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r4_mba0[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,70,0,0,0,2,2,2,3,1,1,4,2,4,2,7,3,3,3,2,7,7,7,7,8,7,8,0,0,2,11,0,0,0,11,2,12,2,10,0,0,0,0,0,0,0,0,0,0,66,0,0,0,6,4,7,3,0,0,2,0,8,0,7,1,6,4,2,6,5,5,7,8,11,9,0,0,1,4,0,0,2,10,1,11,1,11,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

uint32_t rdimm_kg4_1600_r4_mba1[210] = {fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100,fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF,fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RON_OHM34,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_OHM60,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_NOM_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_OHM120,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,fapi::ENUM_ATTR_VPD_DRAM_RTT_WR_DISABLE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_CEN_RD_VREF_VDD50000,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,fapi::ENUM_ATTR_VPD_DRAM_WR_VREF_VDD500,24,24,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_RCV_IMP_DQ_DQS_OHM60,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CNTL_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_ADDR_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_CLK_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_DRV_IMP_SPCKE_OHM40,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CNTL_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_ADDR_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_CLK_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,fapi::ENUM_ATTR_VPD_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS,71,0,0,0,8,8,8,8,7,8,10,9,12,8,6,9,7,11,9,5,5,7,4,4,8,4,0,0,10,2,0,0,12,1,11,2,3,0,0,0,0,0,0,0,0,0,0,0,68,0,0,0,2,3,5,2,3,4,5,4,5,5,1,5,2,4,5,2,2,2,1,2,0,1,0,0,1,10,0,0,1,11,1,9,1,8,0,0,0,0,0,0,0,0,0,0,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE,fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE
};

//Base Array Which Is Used For Looper To Setup Data
uint32_t base_var_array[210];


extern "C" {


//******************************************************************************
//* name=mss_eff_config_termination, param=i_target_mba, return=ReturnCode
//******************************************************************************
  fapi::ReturnCode mss_eff_config_termination(const fapi::Target& i_target_mba) {
    fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
    const char * const PROCEDURE_NAME = "mss_eff_config_termination";
    FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());
   // Fetch dependent attributes
    uint8_t l_target_mba_pos = 0;
    uint32_t l_mss_freq = 0;
    uint32_t l_mss_volt = 0;
    uint8_t l_nwell_misplacement = 0;
    uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][DIMM_SIZE];
    uint8_t l_stack_type_u8array[PORT_SIZE][DIMM_SIZE];
    uint8_t l_dimm_size_u8array[PORT_SIZE][DIMM_SIZE];
   // ATTR_EFF_DRAM_GEN: EMPTY = 0, DDR3 = 1, DDR4 = 2, 
    uint8_t l_dram_gen_u8;
   // ATTR_EFF_DIMM_TYPE: CDIMM = 0, RDIMM = 1, UDIMM = 2, LRDIMM = 3,
    uint8_t l_dimm_type_u8;
    uint8_t l_dimm_custom_u8;
    uint8_t l_num_drops_per_port;
    uint8_t l_dram_width_u8;

// this statement makes only lab version of this code have a raw card attribute
#ifdef FAPIECMD
    uint8_t l_lab_raw_card_u8 = 0;
#endif
    uint8_t l_bluewaterfall_broken = 0;
    uint8_t l_dimm_rc_u8 = 0; //THIS VAR MATCHES LAB_RAW_CARD for enum position / card type (ie 5 is kg3, 0 is RC/A etc
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_target_mba_pos);
    fapi::Target l_target_centaur;
    rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_mss_volt); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_NWELL_MISPLACEMENT, &l_target_centaur, l_nwell_misplacement); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_BLUEWATERFALL_BROKEN, &l_target_centaur, l_bluewaterfall_broken); if(rc) return rc;
// Look up a lab only attribute in non-host boot environments
#ifdef FAPIECMD
    rc = FAPI_ATTR_GET(ATTR_LAB_ONLY_RAW_CARD, NULL, l_lab_raw_card_u8); if(rc) return rc;
    //l_lab_raw_card_u8 = fapi::ENUM_ATTR_LAB_ONLY_RAW_CARD_KG3;
#endif



    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, attr_eff_cen_slew_rate_dq_dqs); if(rc) return rc;




    if (l_mss_freq <= 0) {
      FAPI_ERR("Invalid ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc,RC_MSS_PLACE_HOLDER_ERROR); return rc;
    }
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_AL, &i_target_mba, attr_eff_dram_al); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target_mba, l_stack_type_u8array); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_gen_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimm_type_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_dimm_custom_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, l_dram_width_u8); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &i_target_mba, l_dimm_size_u8array); if(rc) return rc;

   // Temp workaround for incorrect byte33 SPD data "ATTR_EFF_STACK_TYPE" in early lab CDIMMs.
    uint8_t l_stack_type_modified = 0;
    for (uint8_t cur_port = 0; cur_port < PORT_SIZE; cur_port += 1) {
      for (uint8_t cur_dimm = 0; cur_dimm < DIMM_SIZE; cur_dimm += 1) {
        if ((l_dimm_custom_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) && (l_stack_type_u8array[cur_port][cur_dimm] == fapi::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP) && (l_dram_width_u8 == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8) && (l_dimm_size_u8array[cur_port][cur_dimm] == 4)) {
          FAPI_INF("WARNING: Wrong Byte33 SPD detected for OLD 16G/32G CDIMM on %s PORT%d DIMM%d!", i_target_mba.toEcmdString(), cur_port, cur_dimm);
          FAPI_INF("WARNING: Implimenting workaround on %s PORT%d DIMM%d!", i_target_mba.toEcmdString(), cur_port, cur_dimm);
          l_stack_type_modified = 1; 
          l_stack_type_u8array[cur_port][cur_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
        }
      }
    }
    if (l_stack_type_modified == 1) {
      FAPI_INF("WARNING: ATTR_EFF_STACK_TYPE is being set to ENUM_ATTR_EFF_STACK_TYPE_NONE. Check Byte33 of your SPD on %s!", i_target_mba.toEcmdString());
      rc = FAPI_ATTR_SET(ATTR_EFF_STACK_TYPE, &i_target_mba, l_stack_type_u8array); if(rc) return rc;
    }


   // Fetch impacted attributes
    uint64_t l_attr_eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];
    rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;

   // find out if we are in simulation mode
    uint8_t l_attr_is_simulation;
    rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, l_attr_is_simulation); if(rc) return rc;


   // Define local attribute variables
    uint8_t l_attr_mss_cal_step_enable = 0xFF;
   //DEBUG MESSAGE!
    FAPI_INF("DRAM GEN %d WIDTH %d 00R %d 10R %d 01R %d 11R %d DPP %d stack %d type %d custom %d\n",l_dram_gen_u8,l_dram_width_u8,l_num_ranks_per_dimm_u8array[0][0],l_num_ranks_per_dimm_u8array[1][0],l_num_ranks_per_dimm_u8array[0][1],l_num_ranks_per_dimm_u8array[1][1],l_num_drops_per_port,l_stack_type_u8array[0][0],l_dimm_type_u8,l_dimm_custom_u8);


   //Now, Determine The Type Of Dimm We Are Using
   //l_target_mba_pos == 0,1 - MBA POS
   //l_num_drops_per_port == drops / port
   //if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM )
    if(l_attr_is_simulation != 0) {
      FAPI_INF("In Sim Detected %s on %s value is %d", PROCEDURE_NAME, i_target_mba.toEcmdString(), l_attr_is_simulation);
      if((l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM) ||  (l_dimm_custom_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) ){
        memcpy(base_var_array,cdimm_default,STORE_ARRAY_SIZE*sizeof(uint32_t));

      }
      else if(l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM){
        memcpy(base_var_array,rdimm_glacier_1600_r22e_mba1,STORE_ARRAY_SIZE*sizeof(uint32_t));  

      }
      else{
        FAPI_ERR("Invalid Dimm SIM This Should Never Happen!\n");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;

      }


    }
// lab only settings
#ifdef FAPIECMD
    else if(l_lab_raw_card_u8 == fapi::ENUM_ATTR_LAB_ONLY_RAW_CARD_KG3){
      //KG3
      //FAPI_ERR("RUNNING AS KG3 LAB CARD TYPE, KG3 IS DISABLED UNTIL THE INITIAL SETTINGS ARE VERIFIED\n");
      //FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      if( l_target_mba_pos == 0){
        if ( l_mss_freq <= 1466 ) { // 1333Mbps
          if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {     
               //Removed Width Check, use settings for either x8 or x4, use 1600 settings for 1333!
            memcpy(base_var_array,rdimm_kg3_1333_r1_mba0,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - KG3 RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){
            memcpy(base_var_array,rdimm_kg3_1333_r2e_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r2e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4, use 1600 settings for 1333!
            memcpy(base_var_array,rdimm_kg3_1333_r1_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r1 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_kg3_1333_r2b_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r2b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
            memcpy(base_var_array,rdimm_kg3_1333_r4_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r4 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type KG3 FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }


        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
          if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {     
               //Removed Width Check, use settings for either x8 or x4
            memcpy(base_var_array,rdimm_kg3_1600_r1_mba0,210*sizeof(uint32_t)); 
            FAPI_INF("LRDIMM: Base - KG3 LRDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4
            memcpy(base_var_array,rdimm_kg3_1600_r1_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){

            memcpy(base_var_array,rdimm_kg3_1600_r2e_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_kg3_1600_r2b_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
            memcpy(base_var_array,rdimm_kg3_1600_r4_mba0,210*sizeof(uint32_t));
            FAPI_INF("KG3 r40 %d MBA%s Using 1333 Settings\n",l_mss_freq,i_target_mba.toEcmdString());
          }

          else{
            FAPI_ERR("Invalid Dimm Type KG3 FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }//1600      
      }//MBA0
      else{
        if ( l_mss_freq <= 1466 ) { // 1333Mbps
          if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {     
               //Removed Width Check, use settings for either x8 or x4,
            memcpy(base_var_array,rdimm_kg3_1333_r1_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - KG3 RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          } 
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){
            memcpy(base_var_array,rdimm_kg3_1333_r2e_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r2e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4, use 1600 settings for 1333!
            memcpy(base_var_array,rdimm_kg3_1333_r1_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r1 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_kg3_1333_r2b_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r2b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
            memcpy(base_var_array,rdimm_kg3_1333_r4_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r4 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type KG3 FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }


        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
          if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {     
               //Removed Width Check, use settings for either x8 or x4
            memcpy(base_var_array,rdimm_kg3_1600_r1_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - KG3 RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4
            memcpy(base_var_array,rdimm_kg3_1600_r1_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){

            memcpy(base_var_array,rdimm_kg3_1600_r2e_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_kg3_1600_r2b_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
            memcpy(base_var_array,rdimm_kg3_1600_r4_mba1,210*sizeof(uint32_t));
            FAPI_INF("KG3 r40 %d MBA%s Using 1333 Settings\n",l_mss_freq,i_target_mba.toEcmdString());
          }

          else{
            FAPI_ERR("Invalid Dimm Type KG3 FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }//1600      
      }//MBA1
    }
#endif

   else if ( (l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) && ( (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) ) {
      //KG4
      if( l_target_mba_pos == 0){
         if ( l_mss_freq <= 1733 ) { // 1600Mbps
            if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {
               //Removed Width Check, use settings for either x8 or x4
               memcpy(base_var_array,rdimm_kg4_1600_r1_mba0,210*sizeof(uint32_t));
               FAPI_INF("LRDIMM: Base - KG4 RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4
               memcpy(base_var_array,rdimm_kg4_1600_r1_mba0,210*sizeof(uint32_t));
               FAPI_INF("KG4 r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){

               memcpy(base_var_array,rdimm_kg4_1600_r2e_mba0,210*sizeof(uint32_t));
               FAPI_INF("KG4 r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
               memcpy(base_var_array,rdimm_kg4_1600_r2b_mba0,210*sizeof(uint32_t));
               FAPI_INF("KG4 r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               memcpy(base_var_array,rdimm_kg4_1600_r4_mba0,210*sizeof(uint32_t));
               FAPI_INF("KG4 r40 %d MBA%s Using 1333 Settings\n",l_mss_freq,i_target_mba.toEcmdString());
            }

            else{
               FAPI_ERR("Invalid Dimm Type KG4 FREQ %d MBA0\n",l_mss_freq);
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
              //    memcpy(base_var_array,cdimm_rcb4_2r_1600_mba0,210*sizeof(uint32_t));
              //    FAPI_INF("CDIMM rcb4_2r_1600 MBA0 \n");
         }//1600
      }//MBA0
      else{
         if ( l_mss_freq <= 1733 ) { // 1600Mbps
            if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {
               //Removed Width Check, use settings for either x8 or x4
               memcpy(base_var_array,rdimm_kg4_1600_r1_mba1,210*sizeof(uint32_t));
               FAPI_INF("LRDIMM: Base - KG4 RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4
               memcpy(base_var_array,rdimm_kg4_1600_r1_mba1,210*sizeof(uint32_t));
               FAPI_INF("KG4 r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){

               memcpy(base_var_array,rdimm_kg4_1600_r2e_mba1,210*sizeof(uint32_t));
               FAPI_INF("KG4 r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
               memcpy(base_var_array,rdimm_kg4_1600_r2b_mba1,210*sizeof(uint32_t));
               FAPI_INF("KG4 r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               memcpy(base_var_array,rdimm_kg4_1600_r4_mba1,210*sizeof(uint32_t));
               FAPI_INF("KG4 r40 %d MBA%s Using 1333 Settings\n",l_mss_freq,i_target_mba.toEcmdString());
            }

            else{
               FAPI_ERR("Invalid Dimm Type KG4 FREQ %d MBA0\n",l_mss_freq);
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         }//1600
      }//MBA1
   }


    else if((l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM) || (l_dimm_custom_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)){ 
      if(l_dimm_custom_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) {

         //This is a CDIMM!
         if(l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) {
           //2R Cdimm RCB4
            l_dimm_rc_u8 = 2;
            if ( l_mss_freq <= 1733 ) { // 1600Mbps
               if(l_target_mba_pos == 0){
                  memcpy(base_var_array,cdimm_rcb4_2r_1600_mba0,210*sizeof(uint32_t));
                  FAPI_INF("CDIMM rcb4_2r_1600 MBA0 \n");
                  //memcpy(base_var_array,cdimm_rcb_2r_1600_mba0,210*sizeof(uint32_t));
                  //FAPI_INF("CDIMM rcb4 Running with RCB DDR3 Settings MBA0\n");

               }
               else if(l_target_mba_pos == 1){
                  memcpy(base_var_array,cdimm_rcb4_2r_1600_mba1,210*sizeof(uint32_t));
                  FAPI_INF("CDIMM rcb4_2r_1600 MBA1 \n");
                  //memcpy(base_var_array,cdimm_rcb_2r_1600_mba1,210*sizeof(uint32_t));
                  //FAPI_INF("CDIMM rcb4 Running with RCB DDR3 Settings MBA1\n");


               }
              else{
                 FAPI_ERR("Invalid Dimm Type CDIMM RCB4 FREQ %d\n",l_mss_freq);
                 FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
              }
            }
         }//CDIMM RCB4
         else {
           memcpy(base_var_array,cdimm_default,210*sizeof(uint32_t));
         }
      }//End CDIMM
      else{
         //This is a UDIMM!
        l_dimm_rc_u8 = 7;
        if( l_target_mba_pos == 0 ){
          if ( l_mss_freq <= 1733 ) { // 1600Mbps
            if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
              memcpy(base_var_array,udimm_glacier_1600_r10_mba0,210*sizeof(uint32_t));
              FAPI_INF("UDIMM ICICLE r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else{
              FAPI_ERR("Invalid Dimm Type UDIMM FREQ %d MBA0\n",l_mss_freq);
              FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;

            }
          }
          else{
            FAPI_ERR("Invalid Dimm Type UDIMM FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }
        else{
          if ( l_mss_freq <= 1733 ) { // 1600Mbps
            if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
              memcpy(base_var_array,udimm_glacier_1600_r10_mba1,210*sizeof(uint32_t));
              FAPI_INF("UDIMM ICICLE r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
            }
            else{
              FAPI_ERR("Invalid Dimm Type UDIMM FREQ %d MBA0\n",l_mss_freq);
              FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;

            }
          }
          else{
            FAPI_ERR("Invalid Dimm Type UDIMM FREQ %d MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }




      }//End UDIMM
    }
    else if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ){
      l_dimm_rc_u8 = 7;
      if( l_target_mba_pos == 0){
        if ( l_mss_freq <= 1466 ) { // 1333Mbps

          if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){
            memcpy(base_var_array,rdimm_glacier_1333_r20e_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4, use 1600 settings for 1333!
            memcpy(base_var_array,rdimm_glacier_1600_r10_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_glacier_1333_r20b_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
            memcpy(base_var_array,rdimm_glacier_1333_r40_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r40 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type RDIMM FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }

        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
          if((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //Removed Width Check, use settings for either x8 or x4
            memcpy(base_var_array,rdimm_glacier_1600_r10_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 4)){

            memcpy(base_var_array,rdimm_glacier_1600_r20e_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)  && (l_dram_width_u8 == 8)){
            memcpy(base_var_array,rdimm_glacier_1600_r20b_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)){
               //USE 1333 settings at 1600
            memcpy(base_var_array,rdimm_glacier_1333_r40_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r40 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }

          else{
            FAPI_ERR("Invalid Dimm Type RDIMM FREQ %d MBA0\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }//1600      
      }//MBA0
      else{
        if ( l_mss_freq <= 1200 ) { // 1066Mbps
          if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 4)) || ((l_num_ranks_per_dimm_u8array[1][0] == 4) && (l_num_ranks_per_dimm_u8array[1][1] == 4)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)){  
            memcpy(base_var_array,rdimm_glacier_1066_r44_mba1,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r44 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());  
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 4) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){  
            memcpy(base_var_array,rdimm_glacier_1066_r40_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r44 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else{
            FAPI_ERR("Invalid Dimm Type RDIMM FREQ %d MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }

        } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
          if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 1) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){  
            memcpy(base_var_array,rdimm_glacier_1333_r10_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 1)) || ((l_num_ranks_per_dimm_u8array[1][0] == 1) && (l_num_ranks_per_dimm_u8array[1][1] == 1)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)){  
            memcpy(base_var_array,rdimm_glacier_1333_r11_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r11 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE) && (l_dram_width_u8 == 4)){  
            memcpy(base_var_array,rdimm_glacier_1333_r20e_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE) && (l_dram_width_u8 == 8)){  
            memcpy(base_var_array,rdimm_glacier_1333_r20b_mba1,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());  
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 2)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 2)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && (l_dram_width_u8 == 4)){  
            memcpy(base_var_array,rdimm_glacier_1333_r22e_mba1,210*sizeof(uint32_t)); 
            FAPI_INF("RDIMM r22e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString()); 
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 2)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 2)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && (l_dram_width_u8 == 8)){  
            memcpy(base_var_array,rdimm_glacier_1333_r22b_mba1,210*sizeof(uint32_t)); 
            FAPI_INF("RDIMM r22b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString()); 
          }        
          else if((((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 4) && (l_num_ranks_per_dimm_u8array[1][1] == 0))) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){
               //Use 4R MBA0 settings for CD only!
            memcpy(base_var_array,rdimm_glacier_1333_r40_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r40 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }


          else{
            FAPI_ERR("Invalid Dimm Type RDIMM FREQ %d HERE MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps

          if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 1) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){  
            memcpy(base_var_array,rdimm_glacier_1600_r10_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 1) && (l_num_ranks_per_dimm_u8array[0][1] == 1)) || ((l_num_ranks_per_dimm_u8array[1][0] == 1) && (l_num_ranks_per_dimm_u8array[1][1] == 1)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)){  
            memcpy(base_var_array,rdimm_glacier_1600_r11_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r11 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE) && (l_dram_width_u8 == 4)){  
            memcpy(base_var_array,rdimm_glacier_1600_r20e_mba1,210*sizeof(uint32_t)); 
            FAPI_INF("RDIMM r20e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 0)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE) && (l_dram_width_u8 == 8)){  
            memcpy(base_var_array,rdimm_glacier_1600_r20b_mba1,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r20b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());  
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 2)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 2)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && (l_dram_width_u8 == 4)){  
            memcpy(base_var_array,rdimm_glacier_1600_r22e_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r22e %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }        
          else if( ( ((l_num_ranks_per_dimm_u8array[0][0] == 2) && (l_num_ranks_per_dimm_u8array[0][1] == 2)) || ((l_num_ranks_per_dimm_u8array[1][0] == 2) && (l_num_ranks_per_dimm_u8array[1][1] == 2)) ) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && (l_dram_width_u8 == 8)){  
            memcpy(base_var_array,rdimm_glacier_1600_r22b_mba1,210*sizeof(uint32_t));  
            FAPI_INF("RDIMM r22b %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          } 
          else if((((l_num_ranks_per_dimm_u8array[0][0] == 4) && (l_num_ranks_per_dimm_u8array[0][1] == 0)) || ((l_num_ranks_per_dimm_u8array[1][0] == 4) && (l_num_ranks_per_dimm_u8array[1][1] == 0))) && (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){
               //Use 4R MBA0 1333 settings for CD only!
            memcpy(base_var_array,rdimm_glacier_1333_r40_mba0,210*sizeof(uint32_t));
            FAPI_INF("RDIMM r40 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type RDIMM FREQ %d MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }//1600
      }//MBA1
    }//End RDIMM
    else if( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ){
      l_dimm_rc_u8 = 7;
      // Set LRDIMM base var array as 1Rank RDIMM
      if( l_target_mba_pos == 0){
        if ( l_mss_freq <= 1466 ) { // 1333Mbps
            //Removed Width Check, use settings for either x8 or x4, use 1600 settings for 1333!
          memcpy(base_var_array,rdimm_glacier_1600_r10_mba0,210*sizeof(uint32_t));
          FAPI_INF("LRDIMM: Base - RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());

        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
            //Removed Width Check, use settings for either x8 or x4
          memcpy(base_var_array,rdimm_glacier_1600_r10_mba0,210*sizeof(uint32_t));
          FAPI_INF("LRDIMM: Base - LRDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
        }
      }//MBA0
      else{
        if ( l_mss_freq <= 1466 ) { // 1333Mbps
          if( (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){
            memcpy(base_var_array,rdimm_glacier_1333_r10_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if( (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)){
            memcpy(base_var_array,rdimm_glacier_1333_r11_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - RDIMM r11 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type LRDIMM FREQ %d HERE MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        } else if ( l_mss_freq <= 1733 ) { // 1600Mbps

          if( (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE)){
            memcpy(base_var_array,rdimm_glacier_1600_r10_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - RDIMM r10 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else if( (l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)){
            memcpy(base_var_array,rdimm_glacier_1600_r11_mba1,210*sizeof(uint32_t));
            FAPI_INF("LRDIMM: Base - RDIMM r11 %d MBA%s\n",l_mss_freq,i_target_mba.toEcmdString());
          }
          else{
            FAPI_ERR("Invalid Dimm Type LRDIMM FREQ %d MBA1\n",l_mss_freq);
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
        }
      }//MBA1

//----------------------------------------------------------------------------------------------------------------

      // For dual drop, Set ODT_RD as 2rank (8R LRDIMM) or 4rank (4R LRDIMM)
      if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) {
        uint32_t *p_1066_mba1_array = &rdimm_glacier_1066_r44_mba1[0];
        uint32_t *p_1333_x4_mba1_array = &rdimm_glacier_1333_r22e_mba1[0];
        uint32_t *p_1333_x8_mba1_array = &rdimm_glacier_1333_r22b_mba1[0];
        uint32_t *p_1600_x4_mba1_array = &rdimm_glacier_1600_r22e_mba1[0];
        uint32_t *p_1600_x8_mba1_array = &rdimm_glacier_1600_r22b_mba1[0];

        uint32_t *p_b_var_array = &base_var_array[0];

        uint32_t *var_array_p_array[] = {p_1066_mba1_array, p_1333_x4_mba1_array, p_1333_x8_mba1_array, 
        p_1600_x4_mba1_array, p_1600_x8_mba1_array};

        rc = mss_lrdimm_rewrite_odt(i_target_mba, p_b_var_array, var_array_p_array);

        if(rc)
        {
          FAPI_ERR("FAILED LRDIMM rewrite ODT_RD");
          FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
        }
      }
    } // LRDIMM
    else{
      FAPI_ERR("Invalid Dimm Type of %d", l_dimm_type_u8);
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
    }

   // Now Set All The Attributes
    uint8_t i = 0;
    attr_eff_dimm_rcd_ibt[0][0] = base_var_array[i++];             // keep 0
    attr_eff_dimm_rcd_ibt[0][1] = base_var_array[i++];             // keep 1
    attr_eff_dimm_rcd_ibt[1][0] = base_var_array[i++];             // keep 2
    attr_eff_dimm_rcd_ibt[1][1] = base_var_array[i++];             // keep 3 
    attr_eff_dimm_rcd_mirror_mode[0][0] = base_var_array[i++];     // keep 4
    attr_eff_dimm_rcd_mirror_mode[0][1] = base_var_array[i++];     // keep 5
    attr_eff_dimm_rcd_mirror_mode[1][0] = base_var_array[i++];     // keep 6
    attr_eff_dimm_rcd_mirror_mode[1][1] = base_var_array[i++];     // keep 7


   //Fix for VPD Mode for lab rdimm 
    if(((l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) || ( l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) ) && (l_lab_raw_card_u8 != fapi::ENUM_ATTR_LAB_ONLY_RAW_CARD_KG3)){
      FAPI_INF("RON i %d SHOULD NOT BE HERE\n",i);
      attr_vpd_dram_ron[0][0] = base_var_array[i++];
      attr_vpd_dram_ron[0][1] = base_var_array[i++];
      attr_vpd_dram_ron[1][0] = base_var_array[i++];
      attr_vpd_dram_ron[1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][3] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][0] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][1] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][2] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][3] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][0] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][1] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][2] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][3] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][0] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][1] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][2] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][3] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][0] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][1] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][2] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][3] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][0] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][1] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][2] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][3] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][0] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][1] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][2] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][3] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][0] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][1] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][2] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][3] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][0] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][1] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][2] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][3] = base_var_array[i++];
      attr_eff_cen_rd_vref[0] = base_var_array[i++];
      attr_eff_cen_rd_vref[1] = base_var_array[i++];
      if(l_dram_gen_u8 == 1){
        attr_eff_dram_wr_vref[0] = base_var_array[i++];
        attr_eff_dram_wr_vref[1] = base_var_array[i++];
      }
      else if(l_dram_gen_u8 == 2){
        attr_eff_dram_wrddr4_vref[0] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[1] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[0] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[1] = base_var_array[i++];
      }
      attr_eff_cen_rcv_imp_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_rcv_imp_dq_dqs[1] = base_var_array[i++];
      attr_eff_cen_drv_imp_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_drv_imp_dq_dqs[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_cntl[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_cntl[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_addr[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_addr[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_clk[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_clk[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_spcke[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_spcke[1] = base_var_array[i++];
      attr_eff_cen_slew_rate_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_slew_rate_dq_dqs[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_cntl[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_cntl[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_addr[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_addr[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_clk[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_clk[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_spcke[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_spcke[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a4[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a5[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a6[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a7[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a8[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a9[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a10[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a11[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a12[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a13[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a14[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a15[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_casn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_rasn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_wen[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_par[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_actn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a4[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a5[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a6[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a7[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a8[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a9[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a10[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a11[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a12[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a13[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a14[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a15[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_casn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_rasn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_wen[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_par[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_actn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt1[1] = base_var_array[i++];

    }

#ifdef FAPIECMD
    if(l_lab_raw_card_u8 == fapi::ENUM_ATTR_LAB_ONLY_RAW_CARD_KG3 ){
      FAPI_INF("In KG3 Incrementing I for ron i is %d\n",i);
      attr_vpd_dram_ron[0][0] = base_var_array[i++];
      attr_vpd_dram_ron[0][1] = base_var_array[i++];
      attr_vpd_dram_ron[1][0] = base_var_array[i++];
      attr_vpd_dram_ron[1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[0][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_nom[1][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[0][1][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][0][3] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][0] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][1] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][2] = base_var_array[i++];
      attr_vpd_dram_rtt_wr[1][1][3] = base_var_array[i++];
      FAPI_INF("In KG3 Incrementing I for odt_rd i is %d\n",i);

      attr_vpd_odt_rd[0][0][0] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][1] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][2] = base_var_array[i++];
      attr_vpd_odt_rd[0][0][3] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][0] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][1] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][2] = base_var_array[i++];
      attr_vpd_odt_rd[0][1][3] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][0] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][1] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][2] = base_var_array[i++];
      attr_vpd_odt_rd[1][0][3] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][0] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][1] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][2] = base_var_array[i++];
      attr_vpd_odt_rd[1][1][3] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][0] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][1] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][2] = base_var_array[i++];
      attr_vpd_odt_wr[0][0][3] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][0] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][1] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][2] = base_var_array[i++];
      attr_vpd_odt_wr[0][1][3] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][0] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][1] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][2] = base_var_array[i++];
      attr_vpd_odt_wr[1][0][3] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][0] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][1] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][2] = base_var_array[i++];
      attr_vpd_odt_wr[1][1][3] = base_var_array[i++];
      attr_eff_cen_rd_vref[0] = base_var_array[i++];
      attr_eff_cen_rd_vref[1] = base_var_array[i++];
      if(l_dram_gen_u8 == 1){
        attr_eff_dram_wr_vref[0] = base_var_array[i++];
        attr_eff_dram_wr_vref[1] = base_var_array[i++];
      }
      else if(l_dram_gen_u8 == 2){
        attr_eff_dram_wrddr4_vref[0] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[1] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[0] = base_var_array[i++];
        attr_eff_dram_wrddr4_vref[1] = base_var_array[i++];
      }
      attr_eff_cen_rcv_imp_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_rcv_imp_dq_dqs[1] = base_var_array[i++];
      attr_eff_cen_drv_imp_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_drv_imp_dq_dqs[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_cntl[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_cntl[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_addr[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_addr[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_clk[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_clk[1] = base_var_array[i++];
      attr_vpd_cen_drv_imp_spcke[0] = base_var_array[i++];
      attr_vpd_cen_drv_imp_spcke[1] = base_var_array[i++];
      attr_eff_cen_slew_rate_dq_dqs[0] = base_var_array[i++];
      attr_eff_cen_slew_rate_dq_dqs[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_cntl[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_cntl[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_addr[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_addr[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_clk[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_clk[1] = base_var_array[i++];
      attr_vpd_cen_slew_rate_spcke[0] = base_var_array[i++];
      attr_vpd_cen_slew_rate_spcke[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a4[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a5[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a6[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a7[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a8[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a9[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a10[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a11[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a12[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a13[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a14[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a15[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_casn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_rasn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_wen[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_par[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_actn[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn2[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn3[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt0[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt1[0] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_clk_p1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_clk_p1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a4[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a5[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a6[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a7[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a8[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a9[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a10[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a11[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a12[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a13[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a14[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_a15[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_bA2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_casn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_rasn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_cmd_wen[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_par[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m_actn[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_cke3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_csn3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m0_cntl_odt1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_cke3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn1[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn2[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_csn3[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt0[1] = base_var_array[i++];
      attr_vpd_cen_phase_rot_m1_cntl_odt1[1] = base_var_array[i++];

    }
#endif










   // set these attributes from the VPD but allow the code to override later
    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_RD_VREF, &i_target_mba, attr_eff_cen_rd_vref); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_WR_VREF, &i_target_mba, attr_eff_dram_wr_vref); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_WRDDR4_VREF, &i_target_mba, attr_eff_dram_wrddr4_vref); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_RCV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, attr_eff_cen_slew_rate_dq_dqs); if(rc) return rc;

  //Now Setup the RCD - Done Here to Steal Code From Anuwats Version Of Eff Config Termination

    if ( l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4 && 
         ( (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || 
           (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ) ) {

      rc = mss_create_rcd_ddr4(i_target_mba);

      if (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) {
         rc = mss_create_db_ddr4(i_target_mba);
      }

      if (rc)
      {
        FAPI_ERR("Setting DDR4 RCD words failed \n");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }

    }
    else if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) {
      for( int l_port = 0; l_port < PORT_SIZE; l_port += 1 ) {
        for( int l_dimm = 0; l_dimm < DIMM_SIZE; l_dimm += 1 ) {
          uint64_t l_mss_freq_mask        = 0xFFFFFFFFFFCFFFFFLL;
          uint64_t l_mss_volt_mask        = 0xFFFFFFFFFFFEFFFFLL;
          uint64_t l_rcd_ibt_mask         = 0xFFBFFFFF8FFFFFFFLL;
          uint64_t l_rcd_mirror_mode_mask = 0xFFFFFFFF7FFFFFFFLL;
          if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) {
            if(l_dram_width_u8 == 4){
              l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0005050080210000LL;
            }
            else {						       
              l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0005550080210000LL;

            }
          } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 2 ) {
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0005550000210000LL;
          } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 1 ) {
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0C00000001210000LL;
          } else {
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0000000000000000LL;
          }
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_mss_freq_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_mss_volt_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_rcd_ibt_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_rcd_mirror_mode_mask; 
          if ( l_mss_freq <= 933 ) {         // 800Mbps
            l_mss_freq_mask = 0x0000000000000000LL;
          } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
            l_mss_freq_mask = 0x0000000000100000LL;
          } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
            l_mss_freq_mask = 0x0000000000200000LL;
          } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
            l_mss_freq_mask = 0x0000000000300000LL;
          } else {                           // 1866Mbps
            FAPI_ERR("Invalid RDIMM ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
          if ( l_mss_volt >= 1420 ) {        // 1.5V
            l_mss_volt_mask = 0x0000000000000000LL;
          } else if ( l_mss_volt >= 1270 ) { // 1.35V
            l_mss_volt_mask = 0x0000000000010000LL;
          } else {                           // 1.2V 
            FAPI_ERR("Invalid RDIMM ATTR_MSS_VOLT = %d on %s!", l_mss_volt, i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          } 
          if ( attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF ) {
            l_rcd_ibt_mask = 0x0000000070000000LL;
          } else if ( attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100 ) {
            l_rcd_ibt_mask = 0x0000000000000000LL;
          } else if ( attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_150 ) {
            l_rcd_ibt_mask = 0x0040000000000000LL;
          } else if ( attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200 ) {
            l_rcd_ibt_mask = 0x0000000020000000LL;
          } else if ( attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_300 ) {
            l_rcd_ibt_mask = 0x0000000040000000LL;
          } else {
            FAPI_ERR("Invalid DIMM_RCD_IBT on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
          if ( attr_eff_dimm_rcd_mirror_mode[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF ) {
            l_rcd_mirror_mode_mask = 0x0000000000000000LL;
          } else if ( attr_eff_dimm_rcd_mirror_mode[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON ) {
            l_rcd_mirror_mode_mask = 0x0000000080000000LL;
          } else {
            FAPI_ERR("Invalid DIMM_RCD_MIRROR_MODE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
          }
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_mss_freq_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_mss_volt_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_rcd_ibt_mask; 
          l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_rcd_mirror_mode_mask; 
        }
      }
    }


   // For DDR4
    uint8_t l_attr_eff_dram_lpasr = ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_NORMAL;	// 0
    uint8_t l_attr_eff_write_crc = ENUM_ATTR_EFF_WRITE_CRC_DISABLE;			// 0; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_mpr_page = 0;									// 0; maybe add ENUMS: PG0=0, PG1=1, PG2=2, PG3=3	for more readability?
    uint8_t l_attr_eff_geardown_mode = ENUM_ATTR_EFF_GEARDOWN_MODE_HALF;		// 0
    uint8_t l_attr_eff_per_dram_access = ENUM_ATTR_EFF_PER_DRAM_ACCESS_DISABLE;	// 1; change ENUMS: DISABLE=0; ENABLE=1
    uint8_t l_attr_eff_temp_readout = ENUM_ATTR_EFF_TEMP_READOUT_DISABLE;		// 1; change ENUMS: DISABLE=0; ENABLE=1
    uint8_t l_attr_eff_fine_refresh_mode = ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL;	// 4; maybe change ENUMS: NORMAL=0; FIXED_2X=1, FIXED_4X=2, FLY_2X=5, FLY_4X=6   to align with spec better
    uint8_t l_attr_eff_crc_wr_latency = ENUM_ATTR_EFF_CRC_WR_LATENCY_4NCK;		// 0; change ENUMS:  4NCK=4, 5NCK=5, 6NCK=6		following convention
    uint8_t l_attr_eff_mpr_rd_format = ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL;		// 0
    uint8_t l_attr_eff_max_powerdown_mode = ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE;	// 1; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_temp_ref_range = ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL;	// 0
    uint8_t l_attr_eff_temp_ref_mode = ENUM_ATTR_EFF_TEMP_REF_MODE_ENABLE;		// 0; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_int_vref_mon = ENUM_ATTR_EFF_INT_VREF_MON_DISABLE;		// change to disable; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_cs_cmd_latency = 0;								// 0; maybe add ENUMS: DISABLE=0, 3CYC=3, 4CYC=4, 5CYC=5, 6CYC=6, 8CYC=8   for better readability
    uint8_t l_attr_eff_self_ref_abort = ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE;		// 1; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_rd_preamble_train = ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE;	// 1; change ENUMS: DISABLE=0, ENABLE=1
    uint8_t l_attr_eff_rd_preamble = ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK;			// 0; change ENUMS:  1NCK=1, 2NCK=2		following convention
    uint8_t l_attr_eff_wr_preamble = ENUM_ATTR_EFF_WR_PREAMBLE_1NCLK;			// 0; change ENUMS:  1NCK=1, 2NCK=2		following convention
    uint8_t l_attr_eff_ca_parity_latency = ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE;	// 0; add ENUMS: PL4=4, PL5=5, PL6=6, PL8=8,    for better readability
    uint8_t l_attr_eff_crc_error_clear = ENUM_ATTR_EFF_CRC_ERROR_CLEAR_ERROR;		// 0; change ENUMS: CLEAR=0, ERROR=1 	to match spec.
    uint8_t l_attr_eff_ca_parity_error_status = ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_ERROR;	// 0; change ENUMS: CLEAR=0, ERROR=1	to match spec
    uint8_t l_attr_eff_odt_input_buff = ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED;	// 0; change ENUMS: DEACTIVATED=0, ACTIVATED=1
    uint8_t l_attr_eff_ca_parity = ENUM_ATTR_EFF_CA_PARITY_DISABLE;			// change to disable;  change ENUMS: DISABLE=0, ENABLE=1	to match spec
    uint8_t l_attr_eff_data_mask = ENUM_ATTR_EFF_DATA_MASK_DISABLE;			// 0
    uint8_t l_attr_eff_write_dbi = ENUM_ATTR_EFF_WRITE_DBI_DISABLE;			// 0
    uint8_t l_attr_eff_read_dbi = ENUM_ATTR_EFF_READ_DBI_DISABLE;				// 0
//   uint8_t l_attr_tccd_l = ENUM_ATTR_TCCD_L_5NCK;						// 5; maybe add ENUMS: 4NCK=4, 5NCK=5, 6NCK=6; 7NCK=7, 8NCK=8 for better readability
   // uint8_t l_attr_tccd_l = 5;                                             // 5; maybe add ENUMS: 4NCK=4, 5NCK=5, 6NCK=6; 7NCK=7, 8NCK=8 for better readability

/*
 * Remove Before COMMIT
   uint8_t l_attr_eff_dram_lpasr = 0;
   uint8_t l_attr_eff_write_crc = 0;
   uint8_t l_attr_eff_mpr_page = 0;
   uint8_t l_attr_eff_geardown_mode = 0;
   uint8_t l_attr_eff_per_dram_access = 1;
   uint8_t l_attr_eff_temp_readout = 1;
   uint8_t l_attr_eff_fine_refresh_mode = 4;
   uint8_t l_attr_eff_crc_wr_latency = 0;
   uint8_t l_attr_eff_mpr_rd_format = 0;
   uint8_t l_attr_eff_max_powerdown_mode = 1;
   uint8_t l_attr_eff_temp_ref_range = 0;
   uint8_t l_attr_eff_temp_ref_mode = 0;
   uint8_t l_attr_eff_int_vref_mon = 0;
   uint8_t l_attr_eff_cs_cmd_latency = 0;
   uint8_t l_attr_eff_self_ref_abort = 1;
   uint8_t l_attr_eff_rd_preamble_train = 1;
   uint8_t l_attr_eff_rd_preamble = 0;
   uint8_t l_attr_eff_wr_preamble = 0;
   uint8_t l_attr_eff_ca_parity_latency = 0;
   uint8_t l_attr_eff_crc_error_clear = 0;
   uint8_t l_attr_eff_ca_parity_error_status = 0;
   uint8_t l_attr_eff_odt_input_buff = 0;
   uint8_t l_attr_eff_ca_parity = 0;
   uint8_t l_attr_eff_data_mask = 0;
   uint8_t l_attr_eff_write_dbi = 0;
   uint8_t l_attr_eff_read_dbi = 0;
   uint8_t l_attr_tccd_l = 5;
*/
    uint8_t l_attr_eff_rtt_park[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
    uint8_t l_attr_vref_dq_train_value[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
    uint8_t l_attr_vref_dq_train_range[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
    uint8_t l_attr_vref_dq_train_enable[PORT_SIZE][DIMM_SIZE][RANK_SIZE];

    for( int l_port = 0; l_port < PORT_SIZE; l_port += 1 ) {
      for( int l_dimm = 0; l_dimm < DIMM_SIZE; l_dimm += 1 ) {
        for( int l_rank = 0; l_rank < RANK_SIZE; l_rank += 1 ) {
          l_attr_eff_rtt_park[l_port][l_dimm][l_rank] = 0;
          l_attr_vref_dq_train_value[l_port][l_dimm][l_rank] = 16;
          l_attr_vref_dq_train_range[l_port][l_dimm][l_rank] = 0;
          l_attr_vref_dq_train_enable[l_port][l_dimm][l_rank] = ENUM_ATTR_VREF_DQ_TRAIN_ENABLE_DISABLE;
        }
      }
    }


   //RLO Settings
    FAPI_INF("Card Type is %d BW %d NW %d POS %d\n",l_dimm_rc_u8,l_bluewaterfall_broken,l_nwell_misplacement,l_target_mba_pos);
    if(l_dimm_custom_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES){
      //if((l_lab_raw_card_u8 == 0) || (l_lab_raw_card_u8 == 1) || (l_lab_raw_card_u8 == 2) || (l_lab_raw_card_u8 == 3)){
         //These are cdimms, RLO on all ports is 1!
         //WLO,RLO,GPO all come from VPD NOW
/*
         if((l_bluewaterfall_broken == 1) && (l_nwell_misplacement == 0) && (l_dimm_rc_u8 == 3) && (l_target_mba_pos == 0)){
            FAPI_INF("DD1.01 RC/C, Applying Port A Workaround For RLO!\n");
            attr_eff_rlo[0] = (uint8_t)2;
            attr_eff_rlo[1] = (uint8_t)1;
          }
         else if((l_bluewaterfall_broken == 1) && (l_nwell_misplacement == 0) && (l_dimm_rc_u8 == 3) && (l_target_mba_pos == 1)){
            FAPI_INF("DD1.01 RC/C, Applying Port BC Workaround For RLO!\n");
            attr_eff_rlo[0] = (uint8_t)1;
            attr_eff_rlo[1] = (uint8_t)1;
          }
          else if((l_bluewaterfall_broken == 0) && (l_nwell_misplacement == 0) && (l_dimm_rc_u8 == 3)){
             attr_eff_rlo[0] = (uint8_t)1;
             attr_eff_rlo[1] = (uint8_t)1;

          }
          else{
             attr_eff_rlo[0] = (uint8_t)0;
             attr_eff_rlo[1] = (uint8_t)0;
          }

          //Set WLO and GPO
          attr_eff_wlo[0] = (uint8_t)0;
          attr_eff_wlo[1] = (uint8_t)0;
          attr_eff_gpo[0] = (uint8_t)5;
          attr_eff_gpo[1] = (uint8_t)5;
*/     
      if ( l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4 ) {
      // Set for CDIMM B4
          attr_eff_rlo[0] = (uint8_t)0;
          attr_eff_rlo[1] = (uint8_t)0;
          attr_eff_wlo[0] = (uint8_t)0;
          attr_eff_wlo[1] = (uint8_t)0;
          attr_eff_gpo[0] = (uint8_t)5;
          attr_eff_gpo[1] = (uint8_t)5;
      }

    }
    else if(l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM){
  //else if((l_lab_raw_card_u8 == 5) || (l_lab_raw_card_u8 == 6) || (l_lab_raw_card_u8 == 7)){
       //RDIMM
      attr_eff_rlo[0] = (uint8_t)2;
      attr_eff_rlo[1] = (uint8_t)2;
       //Set WLO and GPO
      attr_eff_wlo[0] = (uint8_t)1;
      attr_eff_wlo[1] = (uint8_t)1;
      attr_eff_gpo[0] = (uint8_t)5;
      attr_eff_gpo[1] = (uint8_t)5;

    }
    else if(l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM){
       //LRDIMM
       if ( l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4 ) {
         attr_eff_rlo[0] = (uint8_t)5;
         attr_eff_rlo[1] = (uint8_t)5;
         attr_eff_wlo[0] = (uint8_t)1;
         attr_eff_wlo[1] = (uint8_t)1; 
       } 
       else {
         attr_eff_rlo[0] = (uint8_t)6;
         attr_eff_rlo[1] = (uint8_t)6;
         attr_eff_wlo[0] = (uint8_t)255; // WLO = -1, 2's complement
         attr_eff_wlo[1] = (uint8_t)255; 
      }
      attr_eff_gpo[0] = (uint8_t)7;
      attr_eff_gpo[1] = (uint8_t)7;

    }
    else{
      FAPI_ERR("Invalid Card Type RLO Settings \n");
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;

    } 



    FAPI_INF("About To Set Attributes\n");


    rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_LPASR, &i_target_mba, l_attr_eff_dram_lpasr); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_WRITE_CRC, &i_target_mba, l_attr_eff_write_crc); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_MPR_PAGE, &i_target_mba, l_attr_eff_mpr_page); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_GEARDOWN_MODE, &i_target_mba, l_attr_eff_geardown_mode); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_PER_DRAM_ACCESS, &i_target_mba, l_attr_eff_per_dram_access); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_TEMP_READOUT, &i_target_mba, l_attr_eff_temp_readout); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_FINE_REFRESH_MODE, &i_target_mba, l_attr_eff_fine_refresh_mode); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CRC_WR_LATENCY, &i_target_mba, l_attr_eff_crc_wr_latency); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_MPR_RD_FORMAT, &i_target_mba, l_attr_eff_mpr_rd_format); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_MAX_POWERDOWN_MODE, &i_target_mba, l_attr_eff_max_powerdown_mode); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_TEMP_REF_RANGE, &i_target_mba, l_attr_eff_temp_ref_range); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_TEMP_REF_MODE, &i_target_mba, l_attr_eff_temp_ref_mode); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_INT_VREF_MON, &i_target_mba, l_attr_eff_int_vref_mon); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CS_CMD_LATENCY, &i_target_mba, l_attr_eff_cs_cmd_latency); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_SELF_REF_ABORT, &i_target_mba, l_attr_eff_self_ref_abort); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_RD_PREAMBLE_TRAIN, &i_target_mba, l_attr_eff_rd_preamble_train); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_RD_PREAMBLE, &i_target_mba, l_attr_eff_rd_preamble); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_WR_PREAMBLE, &i_target_mba, l_attr_eff_wr_preamble); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CA_PARITY_LATENCY, &i_target_mba, l_attr_eff_ca_parity_latency); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CRC_ERROR_CLEAR, &i_target_mba, l_attr_eff_crc_error_clear); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CA_PARITY_ERROR_STATUS, &i_target_mba, l_attr_eff_ca_parity_error_status); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_ODT_INPUT_BUFF, &i_target_mba, l_attr_eff_odt_input_buff); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_RTT_PARK, &i_target_mba, l_attr_eff_rtt_park); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CA_PARITY, &i_target_mba, l_attr_eff_ca_parity); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_DATA_MASK, &i_target_mba, l_attr_eff_data_mask); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_WRITE_DBI, &i_target_mba, l_attr_eff_write_dbi); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_READ_DBI, &i_target_mba, l_attr_eff_read_dbi); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_VREF_DQ_TRAIN_VALUE, &i_target_mba, l_attr_vref_dq_train_value); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_VREF_DQ_TRAIN_RANGE, &i_target_mba, l_attr_vref_dq_train_range); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_VREF_DQ_TRAIN_ENABLE, &i_target_mba, l_attr_vref_dq_train_enable); if(rc) return rc;
   // rc = FAPI_ATTR_SET(ATTR_TCCD_L, &i_target_mba, l_attr_tccd_l); if(rc) return rc;
    FAPI_INF("Set some attributes, setting more\n");

   // Set attributes
    rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba, l_attr_mss_cal_step_enable); if(rc) return rc;
    if(l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) { // do not override DDR4 RCD 
       rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
    } 
    rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_IBT, &i_target_mba, attr_eff_dimm_rcd_ibt); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_MIRROR_MODE, &i_target_mba, attr_eff_dimm_rcd_mirror_mode); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, attr_eff_cen_rd_vref); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, attr_eff_dram_wr_vref); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
    rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, attr_eff_cen_slew_rate_dq_dqs); if(rc) return rc;

   //Set AL to be 1 less IF 2N Mode Is Enabled
    rc = FAPI_ATTR_GET(ATTR_VPD_DRAM_2N_MODE_ENABLED, &i_target_mba, l_attr_vpd_2n_mode_enabled); if(rc) return rc;
    FAPI_INF("Still alive here\n");
    if(l_attr_vpd_2n_mode_enabled == fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_TRUE ) {
      FAPI_INF("Changing Additive Latency For 2N Mode\nCurrent AL IS %d\n",attr_eff_dram_al);
      if(attr_eff_dram_al == 1){
        attr_eff_dram_al = 2;
      }
      rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_AL, &i_target_mba, attr_eff_dram_al); if(rc) return rc;

    }
    FAPI_INF("AFTER AL SW\n");

    uint8_t l_attr_vpd_dimm_spare[2][2][4];

    if(l_dimm_custom_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) {
      memset(l_attr_vpd_dimm_spare,ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE,2*2*4);
      rc = FAPI_ATTR_SET(ATTR_VPD_DIMM_SPARE, &i_target_mba, l_attr_vpd_dimm_spare); if(rc) return rc;
    }


    FAPI_INF("Setting more VPD ATTRS\n");

   //Fix for VPD Mode for lab rdimm and CDIMM B4
    if((l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) || (l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
       || (l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4) ){
      FAPI_INF("IN RDIMM ATTR SETTING\n");
      rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba, l_attr_mss_cal_step_enable); if(rc) return rc;
      if(l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) { // do not override DDR4 RCD 
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
      }
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_IBT, &i_target_mba, attr_eff_dimm_rcd_ibt); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_MIRROR_MODE, &i_target_mba, attr_eff_dimm_rcd_mirror_mode); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, attr_eff_cen_rd_vref); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, attr_eff_dram_wr_vref); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CNTL, &i_target_mba, attr_vpd_cen_drv_imp_cntl); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_ADDR, &i_target_mba, attr_vpd_cen_drv_imp_addr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CLK, &i_target_mba, attr_vpd_cen_drv_imp_clk); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_SPCKE, &i_target_mba, attr_vpd_cen_drv_imp_spcke); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CNTL, &i_target_mba, attr_vpd_cen_slew_rate_cntl); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_ADDR, &i_target_mba, attr_vpd_cen_slew_rate_addr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CLK, &i_target_mba, attr_vpd_cen_slew_rate_clk); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_SPCKE, &i_target_mba, attr_vpd_cen_slew_rate_spcke); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RON, &i_target_mba, attr_vpd_dram_ron); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_NOM, &i_target_mba, attr_vpd_dram_rtt_nom); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_WR, &i_target_mba, attr_vpd_dram_rtt_wr); if(rc) return rc;
      if(l_dram_gen_u8 == 2){
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_WRDDR4_VREF, &i_target_mba, attr_eff_dram_wrddr4_vref); if(rc) return rc;
      }
      rc = FAPI_ATTR_SET(ATTR_VPD_ODT_RD, &i_target_mba, attr_vpd_odt_rd); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_ODT_WR, &i_target_mba, attr_vpd_odt_wr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0, &i_target_mba, attr_vpd_cen_phase_rot_m0_clk_p0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1, &i_target_mba, attr_vpd_cen_phase_rot_m0_clk_p1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0, &i_target_mba, attr_vpd_cen_phase_rot_m1_clk_p0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1, &i_target_mba, attr_vpd_cen_phase_rot_m1_clk_p1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a4); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a5); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a6); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a7); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a8); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a9); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a10); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a11); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a12); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a13); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a14); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a15); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_casn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_rasn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_wen); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_PAR, &i_target_mba, attr_vpd_cen_phase_rot_m_par); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_ACTN, &i_target_mba, attr_vpd_cen_phase_rot_m_actn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_odt0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_odt1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_odt0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_odt1); if(rc) return rc;
//   rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_2N_MODE_ENABLED, &i_target_mba, attr_eff_dram_2n_mode_enabled); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_RLO, &i_target_mba, attr_eff_rlo); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_WLO, &i_target_mba, attr_eff_wlo); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_GPO, &i_target_mba, attr_eff_gpo); if(rc) return rc;

    }
#ifdef FAPIECMD
    if(l_lab_raw_card_u8 == fapi::ENUM_ATTR_LAB_ONLY_RAW_CARD_KG3){
      FAPI_INF("IN KGC ATTR SET\n");
      rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba, l_attr_mss_cal_step_enable); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_IBT, &i_target_mba, attr_eff_dimm_rcd_ibt); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_MIRROR_MODE, &i_target_mba, attr_eff_dimm_rcd_mirror_mode); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_RD_VREF, &i_target_mba, attr_eff_cen_rd_vref); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_WR_VREF, &i_target_mba, attr_eff_dram_wr_vref); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_RCV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_DQ_DQS, &i_target_mba, attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CNTL, &i_target_mba, attr_vpd_cen_drv_imp_cntl); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_ADDR, &i_target_mba, attr_vpd_cen_drv_imp_addr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CLK, &i_target_mba, attr_vpd_cen_drv_imp_clk); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_SPCKE, &i_target_mba, attr_vpd_cen_drv_imp_spcke); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CNTL, &i_target_mba, attr_vpd_cen_slew_rate_cntl); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_ADDR, &i_target_mba, attr_vpd_cen_slew_rate_addr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CLK, &i_target_mba, attr_vpd_cen_slew_rate_clk); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_SPCKE, &i_target_mba, attr_vpd_cen_slew_rate_spcke); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RON, &i_target_mba, attr_vpd_dram_ron); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_NOM, &i_target_mba, attr_vpd_dram_rtt_nom); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_RTT_WR, &i_target_mba, attr_vpd_dram_rtt_wr); if(rc) return rc;
      if(l_dram_gen_u8 == 2){
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_WRDDR4_VREF, &i_target_mba, attr_eff_dram_wrddr4_vref); if(rc) return rc;
      }
      rc = FAPI_ATTR_SET(ATTR_VPD_ODT_RD, &i_target_mba, attr_vpd_odt_rd); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_ODT_WR, &i_target_mba, attr_vpd_odt_wr); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0, &i_target_mba, attr_vpd_cen_phase_rot_m0_clk_p0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1, &i_target_mba, attr_vpd_cen_phase_rot_m0_clk_p1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0, &i_target_mba, attr_vpd_cen_phase_rot_m1_clk_p0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1, &i_target_mba, attr_vpd_cen_phase_rot_m1_clk_p1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a4); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a5); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a6); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a7); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a8); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a9); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a10); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a11); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a12); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a13); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a14); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_a15); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_bA2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_casn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_rasn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN, &i_target_mba, attr_vpd_cen_phase_rot_m_cmd_wen); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_PAR, &i_target_mba, attr_vpd_cen_phase_rot_m_par); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M_ACTN, &i_target_mba, attr_vpd_cen_phase_rot_m_actn); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_cke3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_csn3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_odt0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1, &i_target_mba, attr_vpd_cen_phase_rot_m0_cntl_odt1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_cke3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn1); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn2); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_csn3); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_odt0); if(rc) return rc;
      rc = FAPI_ATTR_SET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1, &i_target_mba, attr_vpd_cen_phase_rot_m1_cntl_odt1); if(rc) return rc;

    }
#endif


    if(l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
    {  
       if(l_dram_gen_u8 == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3)
       { 
          rc = mss_lrdimm_term_atts(i_target_mba);
       }
       else 
       {
          rc = mss_lrdimm_ddr4_term_atts(i_target_mba);
       }

      if (rc)
      {
        FAPI_ERR("Setting LR term atts failed \n");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
    }








    FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
    return rc;

  }

 ////////////////////////////////////////////////////////////////////////////////////////////
  fapi::ReturnCode mss_eff_config_termination_vpd(const fapi::Target& i_target_mba) {
    fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
    const char * const PROCEDURE_NAME = "mss_eff_config_termination_vpd";
    FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());

    do {
      std::vector<fapi::Target> l_target_dimm_array;
      uint8_t spd_custom;
      uint8_t spd_device_type;

      rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array);
      if(rc)
      {
        FAPI_ERR("Error retrieving assodiated dimms");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR);
        break;
      }
//------------------------------------------------------------------------------
      for (uint8_t l_dimm_index = 0; l_dimm_index <
        l_target_dimm_array.size(); l_dimm_index += 1)
      {
        rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &l_target_dimm_array[l_dimm_index],
                           spd_custom);
        if(rc) break;

        rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_target_dimm_array[l_dimm_index],
                           spd_device_type);
        if(rc) break;
      }
      if(rc) break;

      if ((spd_custom == fapi::ENUM_ATTR_SPD_CUSTOM_NO) || spd_device_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4) {

 // update soem constants for ISDIMMs

           // Get a vector of DIMM targets
        rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array, fapi::TARGET_STATE_PRESENT);
        if (rc) return rc;
        for (uint32_t k=0; k < l_target_dimm_array.size(); k++)
        {
          uint32_t version0 = 0x00;
          rc = FAPI_ATTR_SET(ATTR_VPD_VERSION, &l_target_dimm_array[k], version0); // early VPD versions use fixed TSYS,
          if (rc) return rc;
        }

        uint32_t attr_vpd_cke_pri_map[2] = { 0x00008484, 0x00002121 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CKE_PRI_MAP, &i_target_mba, attr_vpd_cke_pri_map);
        if (rc) return rc;

        uint64_t attr_vpd_cke_pwr_map = 0xde007b00de007b00ull;
        rc = FAPI_ATTR_SET(ATTR_VPD_CKE_PWR_MAP,  &i_target_mba,  attr_vpd_cke_pwr_map);
        if (rc) return rc;

        uint8_t attr_vpd_dram_2n_mode_enabled = 0x00;
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_2N_MODE_ENABLED,  &i_target_mba,  attr_vpd_dram_2n_mode_enabled);
        if (rc) return rc;

        uint8_t l_attr_vpd_dimm_spare[2][2][4] = {{{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0}}};
        rc = FAPI_ATTR_SET(ATTR_VPD_DIMM_SPARE, &i_target_mba, l_attr_vpd_dimm_spare); if(rc) return rc;
        if(rc) return rc;

        uint32_t attr_vpd_cen_rd_vref[2] = { 0x0000c350, 0x0000c350 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_RD_VREF,  &i_target_mba, attr_vpd_cen_rd_vref);
        if (rc) return rc;

        uint32_t attr_vpd_dram_wr_vref[2] = { 0x000001f4, 0x000001f4 };
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_WR_VREF,  &i_target_mba, attr_vpd_dram_wr_vref);
        if (rc) return rc;

        uint8_t attr_vpd_dram_wrddr4_vref[2] = { 0x18, 0x18};
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_WRDDR4_VREF,  &i_target_mba, attr_vpd_dram_wrddr4_vref);
        if(rc) return rc;

        uint8_t attr_vpd_cen_rcv_imp_dq_dqs[2] = {  0x3c, 0x3c };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_RCV_IMP_DQ_DQS,  &i_target_mba, attr_vpd_cen_rcv_imp_dq_dqs);
        if(rc) return rc;

        uint8_t attr_vpd_cen_drv_imp_dq_dqs[2] = {  0x07, 0x07 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_DQ_DQS,  &i_target_mba, attr_vpd_cen_drv_imp_dq_dqs);
        if(rc) return rc;

        uint8_t attr_vpd_cen_drv_imp_cntl[2] = {  0x28, 0x28 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CNTL,  &i_target_mba, attr_vpd_cen_drv_imp_cntl);
        if(rc) return rc;

        uint8_t attr_vpd_cen_drv_imp_addr[2] = {  0x28, 0x28 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_ADDR,  &i_target_mba, attr_vpd_cen_drv_imp_addr);
        if(rc) return rc;

        uint8_t attr_vpd_cen_drv_imp_clk[2] = {  0x28, 0x28 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_CLK,  &i_target_mba, attr_vpd_cen_drv_imp_clk);
        if(rc) return rc;

        uint8_t attr_vpd_cen_drv_imp_spcke[2] = {  0x28, 0x28 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_DRV_IMP_SPCKE,  &i_target_mba, attr_vpd_cen_drv_imp_spcke);
        if(rc) return rc;

        uint8_t attr_vpd_cen_slew_rate_dq_dqs[2] = {  0x04, 0x04 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_DQ_DQS,  &i_target_mba, attr_vpd_cen_slew_rate_dq_dqs);
        if(rc) return rc;

        uint8_t attr_vpd_cen_slew_rate_cntl[2] = {  0x03, 0x03 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CNTL,  &i_target_mba, attr_vpd_cen_slew_rate_cntl);
        if(rc) return rc;

        uint8_t attr_vpd_cen_slew_rate_addr[2] = {  0x03, 0x03 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_ADDR,  &i_target_mba, attr_vpd_cen_slew_rate_addr);
        if(rc) return rc;

        uint8_t attr_vpd_cen_slew_rate_clk[2] = {  0x03, 0x03 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_CLK,  &i_target_mba, attr_vpd_cen_slew_rate_clk);
        if(rc) return rc;

        uint8_t attr_vpd_cen_slew_rate_spcke[2] = {  0x03, 0x03 };
        rc = FAPI_ATTR_SET(ATTR_VPD_CEN_SLEW_RATE_SPCKE,  &i_target_mba, attr_vpd_cen_slew_rate_spcke);
        if(rc) return rc;

        uint8_t attr_vpd_dram_address_mirroring[2][2] = {{  0x00, 0x00 },{0x00, 0x00}};
        rc = FAPI_ATTR_SET(ATTR_VPD_DRAM_ADDRESS_MIRRORING,  &i_target_mba, attr_vpd_dram_address_mirroring);
        if(rc) return rc;

 ////////////////////////////////////////////////////////////////////////////////////////////

        fapi::Target target_chip;
        rc = fapiGetParentChip(i_target_mba, target_chip);
        if (rc) {
          FAPI_ERR("Error calling fapiGetParentChip");
          return rc;
        }

        uint32_t slope = 0x0000c1be;
        uint32_t intercept = 0x0000c06a;
        rc = FAPI_ATTR_SET(ATTR_CDIMM_VPD_MASTER_POWER_SLOPE, &target_chip, slope);
        if (rc) return rc;

        rc = FAPI_ATTR_SET(ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT, &target_chip, intercept);
        if (rc) return rc;

        rc = FAPI_ATTR_SET(ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE, &target_chip, slope);
        if (rc) return rc;

        rc = FAPI_ATTR_SET(ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT, &target_chip, intercept);
        if (rc) return rc;
      }
      if(rc) break;
 ////////////////////////////////////////////////////////////////////////////////////////////


    } while (0);

    FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
    return rc;

  }
 ////////////////////////////////////////////////////////////////////////////////////////////


} // extern "C"

#endif
