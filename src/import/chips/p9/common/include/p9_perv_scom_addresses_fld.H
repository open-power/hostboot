/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_perv_scom_addresses_fld.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_perv_scom_addresses_fld.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE
#ifndef __P9_PERV_SCOM_ADDRESSES_FLD_H
#define __P9_PERV_SCOM_ADDRESSES_FLD_H


#include <p9_scom_template_consts.H>
#include <p9_perv_scom_addresses_fld_fixes.H>

REG64_FLD( PERV_1_ATOMIC_LOCK_REG_ENABLE                           , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( PERV_1_ATOMIC_LOCK_REG_ID                               , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( PERV_1_ATOMIC_LOCK_REG_ID_LEN                           , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( PERV_1_ATOMIC_LOCK_REG_ACTIVITY                         , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( PERV_1_ATOMIC_LOCK_REG_ACTIVITY_LEN                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( PERV_1_BIST_TC_START_TEST_DC                            , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_START_TEST_DC );
REG64_FLD( PERV_1_BIST_TC_SRAM_ABIST_MODE_DC                       , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_SRAM_ABIST_MODE_DC );
REG64_FLD( PERV_1_BIST_TC_EDRAM_ABIST_MODE_DC                      , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_EDRAM_ABIST_MODE_DC );
REG64_FLD( PERV_1_BIST_TC_IOBIST_MODE_DC                           , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_IOBIST_MODE_DC );
REG64_FLD( PERV_1_BIST_PERV                                        , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( PERV_1_BIST_UNIT1                                       , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( PERV_1_BIST_UNIT2                                       , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( PERV_1_BIST_UNIT3                                       , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( PERV_1_BIST_UNIT4                                       , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( PERV_1_BIST_UNIT5                                       , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( PERV_1_BIST_UNIT6                                       , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( PERV_1_BIST_UNIT7                                       , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( PERV_1_BIST_UNIT8                                       , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( PERV_1_BIST_UNIT9                                       , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( PERV_1_BIST_UNIT10                                      , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );

REG64_FLD( PERV_BIT_SEL_REG_2_SELECT_REGISTER_FSP2PIB              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SELECT_REGISTER_FSP2PIB );
REG64_FLD( PERV_BIT_SEL_REG_2_SELECT_REGISTER_FSP2PIB_LEN          , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SELECT_REGISTER_FSP2PIB_LEN );

REG64_FLD( PERV_CBS_CS_START_BOOT_SEQUENCER                        , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_START_BOOT_SEQUENCER );
REG64_FLD( PERV_CBS_CS_OPTION_PIB_RESET                            , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OPTION_PIB_RESET );
REG64_FLD( PERV_CBS_CS_PREVENT_SBE_START                           , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PREVENT_SBE_START );
REG64_FLD( PERV_CBS_CS_SECURE_ACCESS_BIT                           , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SECURE_ACCESS_BIT );
REG64_FLD( PERV_CBS_CS_SAMPLED_SMD_PIN                             , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SAMPLED_SMD_PIN );
REG64_FLD( PERV_CBS_CS_STATE_MACHINE_TRANSITION_DELAY              , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STATE_MACHINE_TRANSITION_DELAY );
REG64_FLD( PERV_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN          , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STATE_MACHINE_TRANSITION_DELAY_LEN );
REG64_FLD( PERV_CBS_CS_INTERNAL_STATE_VECTOR                       , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_INTERNAL_STATE_VECTOR );
REG64_FLD( PERV_CBS_CS_INTERNAL_STATE_VECTOR_LEN                   , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_INTERNAL_STATE_VECTOR_LEN );

REG64_FLD( PERV_CBS_STAT_DBG_RESET_EP                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_RESET_EP );
REG64_FLD( PERV_CBS_STAT_DBG_OPCG_IP                               , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_OPCG_IP );
REG64_FLD( PERV_CBS_STAT_DBG_VITL_CLKOFF                           , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_VITL_CLKOFF );
REG64_FLD( PERV_CBS_STAT_DBG_TEST_ENABLE                           , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_TEST_ENABLE );
REG64_FLD( PERV_CBS_STAT_DBG_REQ                                   , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_REQ    );
REG64_FLD( PERV_CBS_STAT_DBG_CMD                                   , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CMD    );
REG64_FLD( PERV_CBS_STAT_DBG_CMD_LEN                               , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CMD_LEN );
REG64_FLD( PERV_CBS_STAT_DBG_STATE                                 , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_STATE  );
REG64_FLD( PERV_CBS_STAT_DBG_STATE_LEN                             , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_STATE_LEN );
REG64_FLD( PERV_CBS_STAT_DBG_SECURITY_DEBUG_MODE                   , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_SECURITY_DEBUG_MODE );
REG64_FLD( PERV_CBS_STAT_DBG_PROTOCOL_ERROR                        , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PROTOCOL_ERROR );
REG64_FLD( PERV_CBS_STAT_DBG_PCB_IDLE                              , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PCB_IDLE );
REG64_FLD( PERV_CBS_STAT_DBG_CURRENT_OPCG_MODE                     , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CURRENT_OPCG_MODE );
REG64_FLD( PERV_CBS_STAT_DBG_CURRENT_OPCG_MODE_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CURRENT_OPCG_MODE_LEN );
REG64_FLD( PERV_CBS_STAT_DBG_LAST_OPCG_MODE                        , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_LAST_OPCG_MODE );
REG64_FLD( PERV_CBS_STAT_DBG_LAST_OPCG_MODE_LEN                    , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_LAST_OPCG_MODE_LEN );
REG64_FLD( PERV_CBS_STAT_DBG_PCB_ERROR                             , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PCB_ERROR );
REG64_FLD( PERV_CBS_STAT_DBG_PARITY_ERROR                          , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PARITY_ERROR );
REG64_FLD( PERV_CBS_STAT_DBG_CC_ERROR                              , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CC_ERROR );
REG64_FLD( PERV_CBS_STAT_DBG_CHIPLET_IS_ALIGNED                    , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_CHIPLET_IS_ALIGNED );
REG64_FLD( PERV_CBS_STAT_DBG_PCB_REQUEST_SINCE_RESET               , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PCB_REQUEST_SINCE_RESET );
REG64_FLD( PERV_CBS_STAT_DBG_PARANOIA_TEST_ENABLE_CHANGE           , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PARANOIA_TEST_ENABLE_CHANGE );
REG64_FLD( PERV_CBS_STAT_DBG_PARANOIA_VITL_CLKOFF_CHANGE           , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_PARANOIA_VITL_CLKOFF_CHANGE );
REG64_FLD( PERV_CBS_STAT_DBG_TP_TPFSI_ACK                          , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DBG_TP_TPFSI_ACK );

REG64_FLD( PERV_CBS_TR_SIGNATURE                                   , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SIGNATURE  );
REG64_FLD( PERV_CBS_TR_SIGNATURE_LEN                               , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SIGNATURE_LEN );
REG64_FLD( PERV_CBS_TR_UNUSED                                      , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( PERV_CBS_TR_UNUSED_LEN                                  , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( PERV_CBS_TR_TRANS_DELAY                                 , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TRANS_DELAY );
REG64_FLD( PERV_CBS_TR_TRANS_DELAY_LEN                             , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TRANS_DELAY_LEN );

REG64_FLD( PERV_1_CC_ATOMIC_LOCK_REG_ENABLE                        , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( PERV_1_CC_ATOMIC_LOCK_REG_ID                            , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( PERV_1_CC_ATOMIC_LOCK_REG_ID_LEN                        , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( PERV_1_CC_ATOMIC_LOCK_REG_ACTIVITY                      , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( PERV_1_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN                  , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( PERV_1_CC_PROTECT_MODE_REG_READ_ENABLE                  , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( PERV_1_CC_PROTECT_MODE_REG_WRITE_ENABLE                 , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( PERV_1_CLK_REGION_CLOCK_CMD                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD  );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_CMD_LEN                         , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD_LEN );
REG64_FLD( PERV_1_CLK_REGION_SLAVE_MODE                            , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SLAVE_MODE );
REG64_FLD( PERV_1_CLK_REGION_MASTER_MODE                           , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MASTER_MODE );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_PERV                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PERV );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT1                           , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT1 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT2                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT2 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT3                           , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT3 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT4                           , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT4 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT5                           , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT5 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT6                           , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT6 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT7                           , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT7 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT8                           , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT8 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT9                           , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT9 );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_UNIT10                          , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT10 );
REG64_FLD( PERV_1_CLK_REGION_SEL_THOLD_SL                          , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_SL );
REG64_FLD( PERV_1_CLK_REGION_SEL_THOLD_NSL                         , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_NSL );
REG64_FLD( PERV_1_CLK_REGION_SEL_THOLD_ARY                         , 50  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ARY );
REG64_FLD( PERV_1_CLK_REGION_CLOCK_PULSE_USE_EVEN                  , 52  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PULSE_USE_EVEN );

REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_PERV                       , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT1                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT2                      , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT3                      , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT4                      , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT5                      , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT6                      , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT7                      , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT8                      , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT9                      , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( PERV_1_CLOCK_STAT_ARY_STATUS_UNIT10                     , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_PERV                       , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT1                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT2                      , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT3                      , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT4                      , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT5                      , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT6                      , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT7                      , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT8                      , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT9                      , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( PERV_1_CLOCK_STAT_NSL_STATUS_UNIT10                     , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_PERV                        , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT1                       , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT2                       , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT3                       , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT4                       , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT5                       , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT6                       , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT7                       , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT8                       , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT9                       , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( PERV_1_CLOCK_STAT_SL_STATUS_UNIT10                      , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( PERV_PIB2OPB1_CMD_WRDAT_WRITE_NOT_READ                  , 0   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM     ,
           SH_FLD_WRITE_NOT_READ );

REG64_FLD( PERV_CMD_WRDAT_WRITE_NOT_READ                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_WRITE_NOT_READ );

REG64_FLD( PERV_PIB2OPB0_CMD_WRDAT_WRITE_NOT_READ                  , 0   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM     ,
           SH_FLD_WRITE_NOT_READ );

REG32_FLD( PERV_FSII2C_COMMAND_REGISTER_CMD_REG                    , 0   , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_CMD_REG    );
REG32_FLD( PERV_FSII2C_COMMAND_REGISTER_CMD_REG_LEN                , 32  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_CMD_REG_LEN );

REG32_FLD( PERV_FSI2PIB_COMMAND_REGISTER_CMD_REG                   , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_CMD_REG    );
REG32_FLD( PERV_FSI2PIB_COMMAND_REGISTER_CMD_REG_LEN               , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_CMD_REG_LEN );

REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_WRITE_FLAG        , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_WRITE_FLAG );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_BROADCAST_FLAG    , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_BROADCAST_FLAG );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_ADDRESS      , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_ADDRESS );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_ADDRESS_LEN  , 14  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_ADDRESS_LEN );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_REGION       , 16  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_REGION );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_REGION_LEN   , 12  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_REGION_LEN );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_TYPE         , 28  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_TYPE );
REG32_FLD( PERV_FSISHIFT_COMMAND_REGISTER_CMDREG_SCAN_TYPE_LEN     , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_CMDREG_SCAN_TYPE_LEN );

REG32_FLD( PERV_FSI2PIB_COMPLEMENT_MASK_REG                        , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSI2PIB_COMPLEMENT_MASK_REG_LEN                    , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSISHIFT_COMPLEMENT_MASK_REG                       , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_COMPLEMENT_MASK_REG_LEN                   , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_6C                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_6C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_7C                           , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_7C );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC               , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_14C                          , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_14C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_15C                          , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_15C );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC               , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_22C                          , 22  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_22C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_23C                          , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_23C );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC               , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_30C                          , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_30C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_31C                          , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_31C );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_CC_OFLOW_FEH_SEL_DC              , 32  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OFLOW_FEH_SEL_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC               , 33  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SCAN_PROTECT_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_CC_SDIS_DC_N                     , 34  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SDIS_DC_N );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_35C             , 35  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_35C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_36C             , 36  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_36C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_37C             , 37  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_37C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_38C             , 38  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_38C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_TEST_CONTROL_39C             , 39  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_39C );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC         , 40  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_EPS_MASK_VITL_PCB_ERR_DC );
REG64_FLD( PERV_1_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC    , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC );
REG64_FLD( PERV_1_CPLT_CONF0_ERR501                                , 42  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_ERR501     );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_43C                          , 43  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43C );
REG64_FLD( PERV_1_CPLT_CONF0_FREE_USAGE_44C                        , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_44C );
REG64_FLD( PERV_1_CPLT_CONF0_FREE_USAGE_45C                        , 45  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_45C );
REG64_FLD( PERV_1_CPLT_CONF0_FREE_USAGE_46C                        , 46  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_46C );
REG64_FLD( PERV_1_CPLT_CONF0_FREE_USAGE_47C                        , 47  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_47C );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_GROUP_ID_DC                   , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_GROUP_ID_DC_LEN               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC                    , 52  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN                , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_ID_55C                       , 55  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_55C );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_SYS_ID_DC                     , 56  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC );
REG64_FLD( PERV_1_CPLT_CONF0_TC_UNIT_SYS_ID_DC_LEN                 , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC_LEN );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_ID_61C                       , 61  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_61C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_ID_62C                       , 62  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_62C );
REG64_FLD( PERV_1_CPLT_CONF0_RESERVED_ID_63C                       , 63  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_63C );

REG64_FLD( PERV_1_CPLT_CONF1_TCPERV_AMUX_VSELECT_CHIP              , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCPERV_AMUX_VSELECT_CHIP );
REG64_FLD( PERV_1_CPLT_CONF1_TCPERV_AMUX_VSELECT_CHIP_LEN          , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCPERV_AMUX_VSELECT_CHIP_LEN );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_4D                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_4D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_5D                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_5D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_6D                            , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_6D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_7D                            , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_7D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_8D                            , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_8D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_9D                            , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_9D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_10D                           , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_10D );
REG64_FLD( PERV_1_CPLT_CONF1_IOVALID_11D                           , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_11D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_12D                        , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_12D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_13D                        , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_13D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_14D                        , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_14D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_15D                        , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_15D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_16D                        , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_16D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_17D                        , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_17D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_18D                        , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_18D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_19D                        , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_19D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_20D                        , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_20D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_21D                        , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_21D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_22D                        , 22  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_22D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_23D                        , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_23D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_24D                        , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_24D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_25D                        , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_25D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_26D                        , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_26D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_27D                        , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_27D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_28D                        , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_28D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_29D                        , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_29D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_30D                        , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_30D );
REG64_FLD( PERV_1_CPLT_CONF1_FREE_USAGE_31D                        , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_31D );

REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABSTCLK_MUXSEL_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC             , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYNCCLK_MUXSEL_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC              , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FLUSHMODE_INH_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC                , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FORCE_ALIGN_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_ARY_WRT_THRU_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_AVP_MODE                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_AVP_MODE );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_6A                         , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_6A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_7A                         , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_7A );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC        , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABIST_RECOV_DISABLE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_9A                         , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_9A );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC      , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_11A                          , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_11A );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC                  , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_SKIT_MODE_BIST_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC  , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC         , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CONSTRAIN_SAFESCAN_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC           , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_RRFA_TEST_ENABLE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_NBTI_HDR_ENABLE_OVR_DC             , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_HDR_ENABLE_OVR_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_NBTI_PROBE_GATE_DC                 , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_PROBE_GATE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_18A                          , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_18A );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_19A                          , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_19A );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_PSRO_SEL_DC                        , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN                    , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_BSC_WRAPSEL_DC                     , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_WRAPSEL_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_BSC_INTMODE_DC                     , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INTMODE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_BSC_INV_DC                         , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INV_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_BSC_EXTMODE_DC                     , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_EXTMODE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_REFCLK_DRVR_EN_DC                  , 32  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REFCLK_DRVR_EN_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_33A                          , 33  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_33A );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_34A                          , 34  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_34A );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_35A                          , 35  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_35A );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC              , 36  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_EDGE_DELAYED_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC               , 37  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_ALIGN_FLUSH_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_38A                          , 38  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_38A );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_39A                          , 39  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_39A );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC               , 40  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC_LEN );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_42A                          , 42  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_42A );
REG64_FLD( PERV_1_CPLT_CTRL0_RESERVED_43A                          , 43  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43A );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_DCTEST_DC                     , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_DCTEST_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC                , 45  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OTP_PRGMODE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC              , 46  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SSS_CALIBRATE_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC                  , 47  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_PIN_LBIST_DC );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_48A                        , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_48A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_49A                        , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_49A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_50A                        , 50  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_50A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_51A                        , 51  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_51A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_52A                        , 52  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_52A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_53A                        , 53  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_53A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_54A                        , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_54A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_55A                        , 55  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_55A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_56A                        , 56  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_56A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_57A                        , 57  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_57A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_58A                        , 58  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_58A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_59A                        , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_59A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_60A                        , 60  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_60A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_61A                        , 61  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_61A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_62A                        , 62  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_62A );
REG64_FLD( PERV_1_CPLT_CTRL0_FREE_USAGE_63A                        , 63  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_63A );

REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_0B                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0B  );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_1B                             , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1B  );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_2B                             , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2B  );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_VITL_REGION_FENCE                  , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_VITL_REGION_FENCE );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_PERV_REGION_FENCE                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PERV_REGION_FENCE );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_5B                             , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_5B  );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_6B                             , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_6B  );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_REGION3_FENCE                      , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION3_FENCE );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_8B                             , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_8B  );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_9B                             , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_9B  );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_10B                            , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_10B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_11B                            , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_11B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_12B                            , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_12B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_13B                            , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_13B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_14B                            , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_14B );
REG64_FLD( PERV_1_CPLT_CTRL1_RESERVED                              , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED   );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE         , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_MULTICYCLE_TEST_FENCE );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_17B                            , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_17B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_18B                            , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_18B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_19B                            , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_19B );
REG64_FLD( PERV_1_CPLT_CTRL1_TC_PERV_EXPORT_FREEZE                 , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PERV_EXPORT_FREEZE );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_21B                            , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_21B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_22B                            , 22  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_22B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_23B                            , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_23B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_24B                            , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_24B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_25B                            , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_25B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_26B                            , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_26B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_27B                            , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_27B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_28B                            , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_28B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_29B                            , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_29B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_30B                            , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_30B );
REG64_FLD( PERV_1_CPLT_CTRL1_UNUSED_31B                            , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_31B );

REG64_FLD( PERV_1_CPLT_MASK0_CPLTMASK0                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0  );
REG64_FLD( PERV_1_CPLT_MASK0_CPLTMASK0_LEN                         , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0_LEN );

REG64_FLD( PERV_1_CPLT_STAT0_SRAM_ABIST_DONE_DC                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SRAM_ABIST_DONE_DC );
REG64_FLD( PERV_1_CPLT_STAT0_DRAM_ABIST_DONE_DC                    , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DRAM_ABIST_DONE_DC );
REG64_FLD( PERV_1_CPLT_STAT0_RESERVED_2E                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_2E );
REG64_FLD( PERV_1_CPLT_STAT0_RESERVED_3E                           , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_3E );
REG64_FLD( PERV_1_CPLT_STAT0_TC_DIAG_PORT0_OUT                     , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT0_OUT );
REG64_FLD( PERV_1_CPLT_STAT0_TC_DIAG_PORT1_OUT                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT1_OUT );
REG64_FLD( PERV_1_CPLT_STAT0_RESERVED_6E                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6E );
REG64_FLD( PERV_1_CPLT_STAT0_PLL_DESTOUT                           , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PLL_DESTOUT );
REG64_FLD( PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC                  , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_OPCG_DONE_DC );
REG64_FLD( PERV_1_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC         , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_CHIPLET_IS_ALIGNED_DC );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_10E                        , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_10E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_11E                        , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_11E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_12E                        , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_12E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_13E                        , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_13E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_14E                        , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_14E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_15E                        , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_15E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_16E                        , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_16E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_17E                        , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_17E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_18E                        , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_18E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_19E                        , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_19E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_20E                        , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_20E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_21E                        , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_21E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_22E                        , 22  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_22E );
REG64_FLD( PERV_1_CPLT_STAT0_FREE_USAGE_23E                        , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_23E );

REG64_FLD( PERV_1_CTRL_ATOMIC_LOCK_REG_ENABLE                      , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( PERV_1_CTRL_ATOMIC_LOCK_REG_ID                          , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( PERV_1_CTRL_ATOMIC_LOCK_REG_ID_LEN                      , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( PERV_1_CTRL_ATOMIC_LOCK_REG_ACTIVITY                    , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( PERV_1_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN                , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( PERV_1_CTRL_PROTECT_MODE_REG_READ_ENABLE                , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( PERV_1_CTRL_PROTECT_MODE_REG_WRITE_ENABLE               , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG32_FLD( PERV_FSI2PIB_DATA_REGISTER_0_REG                        , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI      ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSI2PIB_DATA_REGISTER_0_REG_LEN                    , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI      ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSI2PIB_DATA_REGISTER_1_REG                        , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSI2PIB_DATA_REGISTER_1_REG_LEN                    , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG64_FLD( PERV_1_DBG_CBS_CC_RESET_EP                              , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESET_EP   );
REG64_FLD( PERV_1_DBG_CBS_CC_OPCG_IP                               , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_OPCG_IP    );
REG64_FLD( PERV_1_DBG_CBS_CC_VITL_CLKOFF                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_VITL_CLKOFF );
REG64_FLD( PERV_1_DBG_CBS_CC_TEST_ENABLE                           , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TEST_ENABLE );
REG64_FLD( PERV_1_DBG_CBS_CC_REQ                                   , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_REQ        );
REG64_FLD( PERV_1_DBG_CBS_CC_CMD                                   , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CMD        );
REG64_FLD( PERV_1_DBG_CBS_CC_CMD_LEN                               , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CMD_LEN    );
REG64_FLD( PERV_1_DBG_CBS_CC_STATE                                 , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATE      );
REG64_FLD( PERV_1_DBG_CBS_CC_STATE_LEN                             , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STATE_LEN  );
REG64_FLD( PERV_1_DBG_CBS_CC_SECURITY_DEBUG_MODE                   , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SECURITY_DEBUG_MODE );
REG64_FLD( PERV_1_DBG_CBS_CC_PROTOCOL_ERROR                        , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PROTOCOL_ERROR );
REG64_FLD( PERV_1_DBG_CBS_CC_PCB_IDLE                              , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PCB_IDLE   );
REG64_FLD( PERV_1_DBG_CBS_CC_CURRENT_OPCG_MODE                     , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE );
REG64_FLD( PERV_1_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN                 , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE_LEN );
REG64_FLD( PERV_1_DBG_CBS_CC_LAST_OPCG_MODE                        , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE );
REG64_FLD( PERV_1_DBG_CBS_CC_LAST_OPCG_MODE_LEN                    , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE_LEN );
REG64_FLD( PERV_1_DBG_CBS_CC_PCB_ERROR                             , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PCB_ERROR  );
REG64_FLD( PERV_1_DBG_CBS_CC_PARITY_ERROR                          , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PARITY_ERROR );
REG64_FLD( PERV_1_DBG_CBS_CC_ERROR                                 , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( PERV_1_DBG_CBS_CC_CHIPLET_IS_ALIGNED                    , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_IS_ALIGNED );
REG64_FLD( PERV_1_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET               , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PCB_REQUEST_SINCE_RESET );
REG64_FLD( PERV_1_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE           , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_TEST_ENABLE_CHANGE );
REG64_FLD( PERV_1_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE           , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_VITL_CLKOFF_CHANGE );
REG64_FLD( PERV_1_DBG_CBS_CC_TP_TPFSI_ACK                          , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TP_TPFSI_ACK );

REG32_FLD( PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_REG                , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_REG_LEN            , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSISHIFT_DMA_MODE_REGISTER_REG_ENABLE              , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_ENABLE );
REG32_FLD( PERV_FSISHIFT_DMA_MODE_REGISTER_REG_FIFO_SIZE_EQ_1      , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_FIFO_SIZE_EQ_1 );
REG32_FLD( PERV_FSISHIFT_DMA_MODE_REGISTER_REG_UNUSED              , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_UNUSED );
REG32_FLD( PERV_FSISHIFT_DMA_MODE_REGISTER_REG_UNUSED_LEN          , 30  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_UNUSED_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_OPCODE          , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_OPCODE     );
REG32_FLD( PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_OPCODE_LEN      , 8   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_OPCODE_LEN );
REG32_FLD( PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_SIZE            , 8   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_SIZE       );
REG32_FLD( PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_SIZE_LEN        , 24  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_SIZE_LEN   );

REG32_FLD( PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_BUF0_REG_DATA0 , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF0_REG_DATA0 );
REG32_FLD( PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_BUF0_REG_DATA0_LEN , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF0_REG_DATA0_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_BUF1_REG_DATA1 , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF1_REG_DATA1 );
REG32_FLD( PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_BUF1_REG_DATA1_LEN , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF1_REG_DATA1_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_BUF0_REG_DATA0 , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF0_REG_DATA0 );
REG32_FLD( PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_BUF0_REG_DATA0_LEN , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF0_REG_DATA0_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_BUF1_REG_DATA0 , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF1_REG_DATA0 );
REG32_FLD( PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_BUF1_REG_DATA0_LEN , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_BUF1_REG_DATA0_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_REMAINING_WORDS     , 8   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REMAINING_WORDS );
REG32_FLD( PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_REMAINING_WORDS_LEN , 24  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REMAINING_WORDS_LEN );

REG32_FLD( PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_REG                 , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_REG_LEN             , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_REG           , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_REG_LEN       , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_PERMISSION_TO_SEND_1 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_PERMISSION_TO_SEND_1 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_ABORT_1            , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_ABORT_1 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_LBUS_SLAVE_1B_PENDING , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_LBUS_SLAVE_1B_PENDING );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_PIB_SLAVE_PENDING  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_PIB_SLAVE_PENDING );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_UNUSED_27          , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_UNUSED_27 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_XDN_1              , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_XDN_1 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_XUP_1              , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_XUP_1 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_UNUSED_24          , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_UNUSED_24 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT       , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_HEADER_COUNT );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_LEN   , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_HEADER_COUNT_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT         , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_DATA_COUNT );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_LEN     , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_DATA_COUNT_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_1B    , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_HEADER_COUNT_1B );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_HEADER_COUNT_1B_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_HEADER_COUNT_1B_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_1B      , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_DATA_COUNT_1B );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_1A_DSC1_DATA_COUNT_1B_LEN  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC1_DATA_COUNT_1B_LEN );

REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_PERMISSION_TO_SEND_2 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_PERMISSION_TO_SEND_2 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_ABORT_2            , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_ABORT_2 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_LBUS_SLAVE_2B_PENDING , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_LBUS_SLAVE_2B_PENDING );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_PIB_SLAVE_PENDING  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_PIB_SLAVE_PENDING );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_UNUSED_27          , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_UNUSED_27 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_XDN_2              , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_XDN_2 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_XUP_2              , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_XUP_2 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_UNUSED_24          , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_UNUSED_24 );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT       , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_HEADER_COUNT );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_LEN   , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_HEADER_COUNT_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT         , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_DATA_COUNT );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_LEN     , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_DATA_COUNT_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_2B    , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_HEADER_COUNT_2B );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_HEADER_COUNT_2B_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_HEADER_COUNT_2B_LEN );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_2B      , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_DATA_COUNT_2B );
REG64_FLD( PERV_DOORBELL_STATUS_CONTROL_2A_DSC2_DATA_COUNT_2B_LEN  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DSC2_DATA_COUNT_2B_LEN );

REG64_FLD( PERV_1_DTS_RESULT0_0_RESULT                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT   );
REG64_FLD( PERV_1_DTS_RESULT0_0_RESULT_LEN                         , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT_LEN );
REG64_FLD( PERV_1_DTS_RESULT0_1_RESULT                             , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT   );
REG64_FLD( PERV_1_DTS_RESULT0_1_RESULT_LEN                         , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT_LEN );

REG64_FLD( PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE           , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE );
REG64_FLD( PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN       , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE_LEN );
REG64_FLD( PERV_1_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR    , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_OVERFLOW_ERR );
REG64_FLD( PERV_1_DTS_TRC_RESULT_1                                 , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_1          );
REG64_FLD( PERV_1_DTS_TRC_RESULT_1_LEN                             , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_1_LEN      );

REG64_FLD( PERV_ERROR_REG_TIMEOUT_ACTIVE                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_ACTIVE );
REG64_FLD( PERV_ERROR_REG_PARITY_ERR                               , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PARITY_ERR );
REG64_FLD( PERV_ERROR_REG_BEAT_NUM_ERR                             , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_BEAT_NUM_ERR );
REG64_FLD( PERV_ERROR_REG_BEAT_REC_ERR                             , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_BEAT_REC_ERR );
REG64_FLD( PERV_ERROR_REG_RECEIVED                                 , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RECEIVED   );
REG64_FLD( PERV_ERROR_REG_RX_PCB_DATA_P_ERR                        , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RX_PCB_DATA_P_ERR );
REG64_FLD( PERV_ERROR_REG_PIB_ADDR_P_ERR                           , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_ADDR_P_ERR );
REG64_FLD( PERV_ERROR_REG_PIB_DATA_P_ERR                           , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_DATA_P_ERR );

REG64_FLD( PERV_1_ERROR_STATUS_ERRORS                              , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ERRORS     );
REG64_FLD( PERV_1_ERROR_STATUS_ERRORS_LEN                          , 32  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ERRORS_LEN );

REG64_FLD( PERV_1_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK         , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_THERM_MODEREG_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK       , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_MODEREG_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK      , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_FORCEREG_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK     , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SCAN_INIT_VERSION_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK          , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_VOLT_MODEREG_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_COUNT_STATE_MASK                  , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_COUNT_STATE_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_RUN_STATE_MASK                    , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_RUN_STATE_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_THRES_STATE_MASK                  , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_THRES_STATE_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_OVERFLOW_MASK                     , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_SHIFTER_PARITY_MASK               , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_PARITY_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_SHIFTER_VALID_MASK                , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_VALID_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_TIMEOUT_MASK                      , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEOUT_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_F_SKITTER_READ_MASK               , 30  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_F_SKITTER_READ_MASK );
REG64_FLD( PERV_1_ERR_STATUS_REG_PCB_MASK                          , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_PCB_MASK   );

REG64_FLD( PERV_FI2C_CFG_PIBI2CM_PIB_SLAVE_ID                      , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_PIBI2CM_PIB_SLAVE_ID );
REG64_FLD( PERV_FI2C_CFG_PIBI2CM_PIB_SLAVE_ID_LEN                  , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_PIBI2CM_PIB_SLAVE_ID_LEN );
REG64_FLD( PERV_FI2C_CFG_ECC_ENABLE                                , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_ECC_ENABLE );
REG64_FLD( PERV_FI2C_CFG_DISABLE_ECC_CHK                           , 17  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DISABLE_ECC_CHK );
REG64_FLD( PERV_FI2C_CFG_I2C_SPEED_MUX                             , 18  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_I2C_SPEED_MUX );
REG64_FLD( PERV_FI2C_CFG_I2C_SPEED_MUX_LEN                         , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_I2C_SPEED_MUX_LEN );
REG64_FLD( PERV_FI2C_CFG_BIT_RATE_DIVISOR_VALUE                    , 20  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_BIT_RATE_DIVISOR_VALUE );
REG64_FLD( PERV_FI2C_CFG_BIT_RATE_DIVISOR_VALUE_LEN                , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_BIT_RATE_DIVISOR_VALUE_LEN );
REG64_FLD( PERV_FI2C_CFG_I2C_BUS_HELD_MODE_ENABLE                  , 36  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_I2C_BUS_HELD_MODE_ENABLE );
REG64_FLD( PERV_FI2C_CFG_PIPELINE_ENABLE                           , 37  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_PIPELINE_ENABLE );
REG64_FLD( PERV_FI2C_CFG_BACKUP_SEEPROM_SELECT                     , 38  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_BACKUP_SEEPROM_SELECT );
REG64_FLD( PERV_FI2C_CFG_FORCE_RESET                               , 39  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_FORCE_RESET );
REG64_FLD( PERV_FI2C_CFG_RESET_PIB                                 , 40  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESET_PIB  );
REG64_FLD( PERV_FI2C_CFG_RESERVED_FOR_CONFIGS                      , 41  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_FOR_CONFIGS );
REG64_FLD( PERV_FI2C_CFG_RESERVED_FOR_CONFIGS_LEN                  , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_FOR_CONFIGS_LEN );
REG64_FLD( PERV_FI2C_CFG_I2C_TIMEOUT                               , 44  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_I2C_TIMEOUT );
REG64_FLD( PERV_FI2C_CFG_I2C_TIMEOUT_LEN                           , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_I2C_TIMEOUT_LEN );

REG64_FLD( PERV_FI2C_SCFG0_REGISTER_VALID                          , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_REGISTER_VALID );
REG64_FLD( PERV_FI2C_SCFG0_RESERVED_3                              , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_3 );
REG64_FLD( PERV_FI2C_SCFG0_RESERVED_4                              , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_4 );
REG64_FLD( PERV_FI2C_SCFG0_RESERVED_4_LEN                          , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_4_LEN );
REG64_FLD( PERV_FI2C_SCFG0_RESERVED_5                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_5 );
REG64_FLD( PERV_FI2C_SCFG0_RESERVED_5_LEN                          , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_5_LEN );
REG64_FLD( PERV_FI2C_SCFG0_DEVICE_ID                               , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID  );
REG64_FLD( PERV_FI2C_SCFG0_DEVICE_ID_LEN                           , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID_LEN );
REG64_FLD( PERV_FI2C_SCFG0_ECC_ENABLE                              , 15  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_ECC_ENABLE );
REG64_FLD( PERV_FI2C_SCFG0_MEMORY_SIZE_IN_PPE_ADDR_MAP             , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP );
REG64_FLD( PERV_FI2C_SCFG0_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN         , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN );
REG64_FLD( PERV_FI2C_SCFG0_START_SEEPROM_ADDRESS                   , 32  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS );
REG64_FLD( PERV_FI2C_SCFG0_START_SEEPROM_ADDRESS_LEN               , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS_LEN );
REG64_FLD( PERV_FI2C_SCFG0_START_PPE_ADDR                          , 48  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR );
REG64_FLD( PERV_FI2C_SCFG0_START_PPE_ADDR_LEN                      , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR_LEN );

REG64_FLD( PERV_FI2C_SCFG1_REGISTER_VALID                          , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_REGISTER_VALID );
REG64_FLD( PERV_FI2C_SCFG1_RESERVED_6                              , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_6 );
REG64_FLD( PERV_FI2C_SCFG1_RESERVED_7                              , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_7 );
REG64_FLD( PERV_FI2C_SCFG1_RESERVED_7_LEN                          , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_7_LEN );
REG64_FLD( PERV_FI2C_SCFG1_RESERVED_8                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_8 );
REG64_FLD( PERV_FI2C_SCFG1_RESERVED_8_LEN                          , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_8_LEN );
REG64_FLD( PERV_FI2C_SCFG1_DEVICE_ID                               , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID  );
REG64_FLD( PERV_FI2C_SCFG1_DEVICE_ID_LEN                           , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID_LEN );
REG64_FLD( PERV_FI2C_SCFG1_ECC_ENABLE                              , 15  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_ECC_ENABLE );
REG64_FLD( PERV_FI2C_SCFG1_MEMORY_SIZE_IN_PPE_ADDR_MAP             , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP );
REG64_FLD( PERV_FI2C_SCFG1_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN         , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN );
REG64_FLD( PERV_FI2C_SCFG1_START_SEEPROM_ADDRESS                   , 32  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS );
REG64_FLD( PERV_FI2C_SCFG1_START_SEEPROM_ADDRESS_LEN               , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS_LEN );
REG64_FLD( PERV_FI2C_SCFG1_START_PPE_ADDR                          , 48  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR );
REG64_FLD( PERV_FI2C_SCFG1_START_PPE_ADDR_LEN                      , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR_LEN );

REG64_FLD( PERV_FI2C_SCFG2_REGISTER_VALID                          , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_REGISTER_VALID );
REG64_FLD( PERV_FI2C_SCFG2_RESERVED_9                              , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_9 );
REG64_FLD( PERV_FI2C_SCFG2_RESERVED_10                             , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_10 );
REG64_FLD( PERV_FI2C_SCFG2_RESERVED_10_LEN                         , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_10_LEN );
REG64_FLD( PERV_FI2C_SCFG2_RESERVED_11                             , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_11 );
REG64_FLD( PERV_FI2C_SCFG2_RESERVED_11_LEN                         , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_11_LEN );
REG64_FLD( PERV_FI2C_SCFG2_DEVICE_ID                               , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID  );
REG64_FLD( PERV_FI2C_SCFG2_DEVICE_ID_LEN                           , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID_LEN );
REG64_FLD( PERV_FI2C_SCFG2_ECC_ENABLE                              , 15  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_ECC_ENABLE );
REG64_FLD( PERV_FI2C_SCFG2_MEMORY_SIZE_IN_PPE_ADDR_MAP             , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP );
REG64_FLD( PERV_FI2C_SCFG2_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN         , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN );
REG64_FLD( PERV_FI2C_SCFG2_START_SEEPROM_ADDRESS                   , 32  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS );
REG64_FLD( PERV_FI2C_SCFG2_START_SEEPROM_ADDRESS_LEN               , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS_LEN );
REG64_FLD( PERV_FI2C_SCFG2_START_PPE_ADDR                          , 48  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR );
REG64_FLD( PERV_FI2C_SCFG2_START_PPE_ADDR_LEN                      , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR_LEN );

REG64_FLD( PERV_FI2C_SCFG3_REGISTER_VALID                          , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_REGISTER_VALID );
REG64_FLD( PERV_FI2C_SCFG3_RESERVED_12                             , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_12 );
REG64_FLD( PERV_FI2C_SCFG3_RESERVED_13                             , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_13 );
REG64_FLD( PERV_FI2C_SCFG3_RESERVED_13_LEN                         , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_13_LEN );
REG64_FLD( PERV_FI2C_SCFG3_RESERVED_14                             , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_14 );
REG64_FLD( PERV_FI2C_SCFG3_RESERVED_14_LEN                         , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_14_LEN );
REG64_FLD( PERV_FI2C_SCFG3_DEVICE_ID                               , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID  );
REG64_FLD( PERV_FI2C_SCFG3_DEVICE_ID_LEN                           , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DEVICE_ID_LEN );
REG64_FLD( PERV_FI2C_SCFG3_ECC_ENABLE                              , 15  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_ECC_ENABLE );
REG64_FLD( PERV_FI2C_SCFG3_MEMORY_SIZE_IN_PPE_ADDR_MAP             , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP );
REG64_FLD( PERV_FI2C_SCFG3_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN         , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_MEMORY_SIZE_IN_PPE_ADDR_MAP_LEN );
REG64_FLD( PERV_FI2C_SCFG3_START_SEEPROM_ADDRESS                   , 32  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS );
REG64_FLD( PERV_FI2C_SCFG3_START_SEEPROM_ADDRESS_LEN               , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_SEEPROM_ADDRESS_LEN );
REG64_FLD( PERV_FI2C_SCFG3_START_PPE_ADDR                          , 48  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR );
REG64_FLD( PERV_FI2C_SCFG3_START_PPE_ADDR_LEN                      , 16  , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START_PPE_ADDR_LEN );

REG64_FLD( PERV_FI2C_STAT_PIB_RESPONSE_INFO                        , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_PIB_RESPONSE_INFO );
REG64_FLD( PERV_FI2C_STAT_PIB_RESPONSE_INFO_LEN                    , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_PIB_RESPONSE_INFO_LEN );
REG64_FLD( PERV_FI2C_STAT_I2CM_PIB_ERRORS                          , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_PIB_ERRORS );
REG64_FLD( PERV_FI2C_STAT_I2CM_PIB_ERRORS_LEN                      , 6   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_PIB_ERRORS_LEN );
REG64_FLD( PERV_FI2C_STAT_I2CM_ECC_ERRORS                          , 9   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_ECC_ERRORS );
REG64_FLD( PERV_FI2C_STAT_I2CM_ECC_ERRORS_LEN                      , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_ECC_ERRORS_LEN );
REG64_FLD( PERV_FI2C_STAT_I2CM_I2C_ERRORS                          , 12  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_I2C_ERRORS );
REG64_FLD( PERV_FI2C_STAT_I2CM_I2C_ERRORS_LEN                      , 7   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_I2CM_I2C_ERRORS_LEN );
REG64_FLD( PERV_FI2C_STAT_ERR_ADDR_BEYOND_RANGE                    , 19  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_ERR_ADDR_BEYOND_RANGE );
REG64_FLD( PERV_FI2C_STAT_ERR_ADDR_OVERLAP                         , 20  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_ERR_ADDR_OVERLAP );
REG64_FLD( PERV_FI2C_STAT_PIB_ABORT                                , 21  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_PIB_ABORT  );
REG64_FLD( PERV_FI2C_STAT_RESERVED_FOR_ERRS                        , 22  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_RESERVED_FOR_ERRS );
REG64_FLD( PERV_FI2C_STAT_RESERVED_FOR_ERRS_LEN                    , 10  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_RESERVED_FOR_ERRS_LEN );
REG64_FLD( PERV_FI2C_STAT_LOCKED_PIBM_ADDR                         , 32  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_PIBM_ADDR );
REG64_FLD( PERV_FI2C_STAT_LOCKED_PIBM_ADDR_LEN                     , 8   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_PIBM_ADDR_LEN );
REG64_FLD( PERV_FI2C_STAT_RESERVED_FOR_ADDRESS                     , 40  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_RESERVED_FOR_ADDRESS );
REG64_FLD( PERV_FI2C_STAT_RESERVED_FOR_ADDRESS_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_RESERVED_FOR_ADDRESS_LEN );
REG64_FLD( PERV_FI2C_STAT_LOCKED_FSM_STATE                         , 43  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_FSM_STATE );
REG64_FLD( PERV_FI2C_STAT_LOCKED_FSM_STATE_LEN                     , 5   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_FSM_STATE_LEN );
REG64_FLD( PERV_FI2C_STAT_LOCKED_SEEPROM_ADDRESS                   , 48  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_SEEPROM_ADDRESS );
REG64_FLD( PERV_FI2C_STAT_LOCKED_SEEPROM_ADDRESS_LEN               , 16  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_LOCKED_SEEPROM_ADDRESS_LEN );

REG64_FLD( PERV_FIRST_ERR_REG_TIMEOUT_ACTIVE                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_ACTIVE );
REG64_FLD( PERV_FIRST_ERR_REG_PARITY                               , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PARITY     );
REG64_FLD( PERV_FIRST_ERR_REG_BEAT_NUM                             , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_BEAT_NUM   );
REG64_FLD( PERV_FIRST_ERR_REG_BEAT_REC                             , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_BEAT_REC   );
REG64_FLD( PERV_FIRST_ERR_REG_RECEIVED_ERROR                       , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RECEIVED_ERROR );
REG64_FLD( PERV_FIRST_ERR_REG_RX_PCB_DATA_P                        , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RX_PCB_DATA_P );
REG64_FLD( PERV_FIRST_ERR_REG_PIB_ADDR_P                           , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_ADDR_P );
REG64_FLD( PERV_FIRST_ERR_REG_PIB_DATA_P                           , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_DATA_P );

REG64_FLD( PERV_FIRST_REPLY_REG_REGISTER                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REGISTER   );
REG64_FLD( PERV_FIRST_REPLY_REG_REGISTER_LEN                       , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REGISTER_LEN );

REG64_FLD( PERV_1_FIR_MASK_IN0                                     , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_FIR_MASK_IN1                                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( PERV_1_FIR_MASK_IN2                                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( PERV_1_FIR_MASK_IN3                                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( PERV_1_FIR_MASK_IN4                                     , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_FIR_MASK_IN5                                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_FIR_MASK_IN6                                     , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_FIR_MASK_IN7                                     , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_FIR_MASK_IN8                                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_FIR_MASK_IN9                                     , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( PERV_1_FIR_MASK_IN10                                    , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( PERV_1_FIR_MASK_IN11                                    , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( PERV_1_FIR_MASK_IN12                                    , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN12       );
REG64_FLD( PERV_1_FIR_MASK_IN13                                    , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN13       );
REG64_FLD( PERV_1_FIR_MASK_IN14                                    , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN14       );
REG64_FLD( PERV_1_FIR_MASK_IN15                                    , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN15       );
REG64_FLD( PERV_1_FIR_MASK_IN16                                    , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN16       );
REG64_FLD( PERV_1_FIR_MASK_IN17                                    , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN17       );
REG64_FLD( PERV_1_FIR_MASK_IN18                                    , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN18       );
REG64_FLD( PERV_1_FIR_MASK_IN19                                    , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN19       );
REG64_FLD( PERV_1_FIR_MASK_IN20                                    , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN20       );
REG64_FLD( PERV_1_FIR_MASK_IN21                                    , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21       );
REG64_FLD( PERV_1_FIR_MASK_IN21_LEN                                , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21_LEN   );
REG64_FLD( PERV_1_FIR_MASK_IN26                                    , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN26       );

REG64_FLD( PERV_1_FMU_MODE_REG_TOD_CNTR_REF                        , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TOD_CNTR_REF );
REG64_FLD( PERV_1_FMU_MODE_REG_TOD_CNTR_REF_LEN                    , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TOD_CNTR_REF_LEN );
REG64_FLD( PERV_1_FMU_MODE_REG_POWER_UP_CNTR_REF                   , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_POWER_UP_CNTR_REF );
REG64_FLD( PERV_1_FMU_MODE_REG_POWER_UP_CNTR_REF_LEN               , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_POWER_UP_CNTR_REF_LEN );

REG64_FLD( PERV_1_FMU_OSC_CNTR1_REG_RESULT_AVAILABLE               , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESULT_AVAILABLE );
REG64_FLD( PERV_1_FMU_OSC_CNTR1_REG_PULSE1_CNTR                    , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE1_CNTR );
REG64_FLD( PERV_1_FMU_OSC_CNTR1_REG_PULSE1_CNTR_LEN                , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE1_CNTR_LEN );

REG64_FLD( PERV_1_FMU_OSC_CNTR2_REG_RESULT_AVAILABLE               , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESULT_AVAILABLE );
REG64_FLD( PERV_1_FMU_OSC_CNTR2_REG_PULSE2_CNTR                    , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE2_CNTR );
REG64_FLD( PERV_1_FMU_OSC_CNTR2_REG_PULSE2_CNTR_LEN                , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE2_CNTR_LEN );

REG64_FLD( PERV_1_FMU_PULSE_GEN_REG_INT_ENA                        , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INT_ENA    );
REG64_FLD( PERV_1_FMU_PULSE_GEN_REG_INT_CNTR_REF                   , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INT_CNTR_REF );
REG64_FLD( PERV_1_FMU_PULSE_GEN_REG_INT_CNTR_REF_LEN               , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INT_CNTR_REF_LEN );

REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_REQ_RESET_FR_SBE    , 6   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_REQ_RESET_FR_SBE );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_REQ_RESET_FR_SP     , 7   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_REQ_RESET_FR_SP );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_DEQUEUED_EOT_FLAG   , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_DEQUEUED_EOT_FLAG );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_FULL           , 10  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_FULL );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EMPTY          , 11  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_EMPTY );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_ENTRY_COUNT    , 12  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_ENTRY_COUNT );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_ENTRY_COUNT_LEN , 4   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_ENTRY_COUNT_LEN );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_VALID_FLAGS    , 16  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_VALID_FLAGS );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_VALID_FLAGS_LEN , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_VALID_FLAGS_LEN );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EOT_FLAGS      , 24  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_EOT_FLAGS );
REG64_FLD( PERV_FSB_FSB_DOWNFIFO_STATUS_DNFIFO_FIFO_EOT_FLAGS_LEN  , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DNFIFO_FIFO_EOT_FLAGS_LEN );

REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_REQ_RESET_FR_SP              , 6   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_REQ_RESET_FR_SP );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_REQ_RESET_FR_SBE             , 7   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_REQ_RESET_FR_SBE );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_DEQUEUED_EOT_FLAG            , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_DEQUEUED_EOT_FLAG );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_FULL                    , 10  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_FULL  );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EMPTY                   , 11  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_EMPTY );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT             , 12  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_ENTRY_COUNT );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN         , 4   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_ENTRY_COUNT_LEN );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS             , 16  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_VALID_FLAGS );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_VALID_FLAGS_LEN         , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_VALID_FLAGS_LEN );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS               , 24  , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_EOT_FLAGS );
REG64_FLD( PERV_FSB_FSB_UPFIFO_STATUS_FIFO_EOT_FLAGS_LEN           , 8   , SH_UNT_PERV_FSB , SH_ACS_FSI_BYTE ,
           SH_FLD_FIFO_EOT_FLAGS_LEN );

REG32_FLD( PERV_FSISCRPD1_FSI_SCRATCH_PAD1                         , 0   , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD1 );
REG32_FLD( PERV_FSISCRPD1_FSI_SCRATCH_PAD1_LEN                     , 32  , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD1_LEN );

REG32_FLD( PERV_FSISCRPD2_FSI_SCRATCH_PAD2                         , 0   , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD2 );
REG32_FLD( PERV_FSISCRPD2_FSI_SCRATCH_PAD2_LEN                     , 32  , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD2_LEN );

REG32_FLD( PERV_FSISCRPD3_FSI_SCRATCH_PAD3                         , 0   , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD3 );
REG32_FLD( PERV_FSISCRPD3_FSI_SCRATCH_PAD3_LEN                     , 32  , SH_UNT_PERV     , SH_ACS_FSI_BYTE ,
           SH_FLD_FSI_SCRATCH_PAD3_LEN );

REG32_FLD( PERV_FSI_A_LLMOD_ASYNC_MODE                             , 31  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ASYNC_MODE );

REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_ENABLE                      , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_1_ENABLE                    , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_1_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_2_ENABLE                    , 2   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_2_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_3_ENABLE                    , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_3_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_4_ENABLE                    , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_4_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_5_ENABLE                    , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_5_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_6_ENABLE                    , 6   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_6_ENABLE );
REG32_FLD( PERV_FSI_A_MST_0_MENP0_PORT_7_ENABLE                    , 7   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_7_ENABLE );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_ENABLE             , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_1_ENABLE           , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_1_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_2_ENABLE           , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_2_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_3_ENABLE           , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_3_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_4_ENABLE           , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_4_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_5_ENABLE           , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_5_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_6_ENABLE           , 6   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_6_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MENP0_PORT_7_ENABLE           , 7   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_7_ENABLE );

REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FIRST_ERROR                     , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FIRST_ERROR );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FIRST_ERROR_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FIRST_ERROR_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST         , 17  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FAILING_OPB_MASTER_FRST );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN     , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FAILING_OPB_MASTER_FRST_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_ACTUAL_ERROR                    , 20  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ACTUAL_ERROR );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_ACTUAL_ERROR_LEN                , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT          , 29  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FAILING_OPB_MASTER_ACT );
REG32_FLD( PERV_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN      , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_FAILING_OPB_MASTER_ACT_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FIRST_ERROR            , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FIRST_ERROR );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FIRST_ERROR_LEN        , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FIRST_ERROR_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST , 17  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_FRST );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_FRST_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_ACTUAL_ERROR           , 20  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ACTUAL_ERROR );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_ACTUAL_ERROR_LEN       , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT , 29  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_ACT );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_ACT_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA             , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_IPOLL_AND_DMA );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY         , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS     , 2   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_RELATIVE_ADDRESS_CMDS );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_ENABLE_PARITY_CHECK              , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_PARITY_CHECK );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION             , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_CLOCK_RATE_SELECTION );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN         , 10  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_CLOCK_RATE_SELECTION_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1           , 14  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_CLOCK_RATE_SELECTION_1 );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN       , 10  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_CLOCK_RATE_SELECTION_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_CLOCK_DIV_4                      , 25  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_CLOCK_DIV_4 );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_TIMEOUT_SEL                      , 26  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_TIMEOUT_SEL );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_TIMEOUT_SEL_LEN                  , 2   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_TIMEOUT_SEL_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_RECEIVER_MODE                    , 29  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_RECEIVER_MODE );
REG32_FLD( PERV_FSI_A_MST_0_MMODE_RECEIVER_MODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_RECEIVER_MODE_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA    , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_IPOLL_AND_DMA );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_RELATIVE_ADDRESS_CMDS );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_ENABLE_PARITY_CHECK     , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_PARITY_CHECK );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION    , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN , 10  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1  , 14  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN , 10  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_CLOCK_DIV_4             , 25  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_DIV_4 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_TIMEOUT_SEL             , 26  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_TIMEOUT_SEL );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_TIMEOUT_SEL_LEN         , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_TIMEOUT_SEL_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_RECEIVER_MODE           , 29  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_RECEIVER_MODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MMODE_RECEIVER_MODE_LEN       , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_RECEIVER_MODE_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MRESP1_PORT_GENERAL_RESET_1            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_1 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP1_PORT_ERROR_RESET_1              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_1 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP1_PORT_GENERAL_RESET_1   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP1_PORT_ERROR_RESET_1     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_1 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP2_PORT_GENERAL_RESET_2            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_2 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP2_PORT_ERROR_RESET_2              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_2 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP2_PORT_GENERAL_RESET_2   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP2_PORT_ERROR_RESET_2     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_2 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP3_PORT_GENERAL_RESET_3            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_3 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP3_PORT_ERROR_RESET_3              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_3 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP3_PORT_GENERAL_RESET_3   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_3 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP3_PORT_ERROR_RESET_3     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_3 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP4_PORT_GENERAL_RESET_4            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_4 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP4_PORT_ERROR_RESET_4              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_4 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP4_PORT_GENERAL_RESET_4   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_4 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP4_PORT_ERROR_RESET_4     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_4 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP5_PORT_GENERAL_RESET_5            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_5 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP5_PORT_ERROR_RESET_5              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_5 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP5_PORT_GENERAL_RESET_5   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_5 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP5_PORT_ERROR_RESET_5     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_5 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP6_PORT_GENERAL_RESET_6            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_6 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP6_PORT_ERROR_RESET_6              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_6 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP6_PORT_GENERAL_RESET_6   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_6 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP6_PORT_ERROR_RESET_6     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_6 );

REG32_FLD( PERV_FSI_A_MST_0_MRESP7_PORT_GENERAL_RESET_7            , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_GENERAL_RESET_7 );
REG32_FLD( PERV_FSI_A_MST_0_MRESP7_PORT_ERROR_RESET_7              , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT_ERROR_RESET_7 );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP7_PORT_GENERAL_RESET_7   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_7 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MRESP7_PORT_ERROR_RESET_7     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_7 );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT0_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT1_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT2_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT3_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT4_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT5_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT6_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_PORT7_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_A_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_0_ENABLE                    , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_0_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_ENABLE                      , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_2_ENABLE                    , 2   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_2_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_3_ENABLE                    , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_3_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_4_ENABLE                    , 4   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_4_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_5_ENABLE                    , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_5_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_6_ENABLE                    , 6   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_6_ENABLE );
REG32_FLD( PERV_FSI_A_MST_1_MENP0_PORT_7_ENABLE                    , 7   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_7_ENABLE );

REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FIRST_ERROR                     , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FIRST_ERROR );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FIRST_ERROR_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FIRST_ERROR_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST         , 17  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_FRST );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_FRST_LEN     , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_FRST_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_ACTUAL_ERROR                    , 20  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ACTUAL_ERROR );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_ACTUAL_ERROR_LEN                , 4   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT          , 29  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_ACT );
REG32_FLD( PERV_FSI_A_MST_1_MESRB0_FAILING_OPB_MASTER_ACT_LEN      , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_FAILING_OPB_MASTER_ACT_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA             , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_IPOLL_AND_DMA );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY         , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS     , 2   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_RELATIVE_ADDRESS_CMDS );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_ENABLE_PARITY_CHECK              , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_ENABLE_PARITY_CHECK );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0           , 4   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_0 );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN       , 10  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION             , 14  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_CLOCK_RATE_SELECTION_LEN         , 10  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_RATE_SELECTION_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_CLOCK_DIV_4                      , 25  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_CLOCK_DIV_4 );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_TIMEOUT_SEL                      , 26  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_TIMEOUT_SEL );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_TIMEOUT_SEL_LEN                  , 2   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_TIMEOUT_SEL_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_RECEIVER_MODE                    , 29  , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_RECEIVER_MODE );
REG32_FLD( PERV_FSI_A_MST_1_MMODE_RECEIVER_MODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_RECEIVER_MODE_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MRESP1_PORT_GENERAL_RESET              , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET );
REG32_FLD( PERV_FSI_A_MST_1_MRESP1_PORT_ERROR_RESET                , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET );

REG32_FLD( PERV_FSI_A_MST_1_MRESP2_PORT_GENERAL_RESET_2            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_2 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP2_PORT_ERROR_RESET_2              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_2 );

REG32_FLD( PERV_FSI_A_MST_1_MRESP3_PORT_GENERAL_RESET_3            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_3 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP3_PORT_ERROR_RESET_3              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_3 );

REG32_FLD( PERV_FSI_A_MST_1_MRESP4_PORT_GENERAL_RESET_4            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_4 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP4_PORT_ERROR_RESET_4              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_4 );

REG32_FLD( PERV_FSI_A_MST_1_MRESP5_PORT_GENERAL_RESET_5            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_5 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP5_PORT_ERROR_RESET_5              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_5 );

REG32_FLD( PERV_FSI_A_MST_1_MRESP6_PORT_GENERAL_RESET_6            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_6 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP6_PORT_ERROR_RESET_6              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_6 );

REG32_FLD( PERV_FSI_A_MST_1_MRESP7_PORT_GENERAL_RESET_7            , 0   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_GENERAL_RESET_7 );
REG32_FLD( PERV_FSI_A_MST_1_MRESP7_PORT_ERROR_RESET_7              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT_ERROR_RESET_7 );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP0_PORT0_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT0_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP1_PORT1_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT1_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP2_PORT2_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT2_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP3_PORT3_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT3_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP4_PORT4_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT4_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP5_PORT5_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT5_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP6_PORT6_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT6_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_0              , 1   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_0 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_0_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_0_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE                , 5   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_A_MST_1_MSTAP7_PORT7_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOMFSI0 ,
           SH_FLD_PORT7_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_A_SMODE_WARM_START_COMPLETED                   , 0   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_WARM_START_COMPLETED );
REG32_FLD( PERV_FSI_A_SMODE_ENABLE_AUX_PORT_UNUSED                 , 1   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_AUX_PORT_UNUSED );
REG32_FLD( PERV_FSI_A_SMODE_ENABLE_HW_ERROR_RECOVERY               , 2   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSI_A_SMODE_OWN_ID_THIS_SLAVE                      , 6   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_OWN_ID_THIS_SLAVE );
REG32_FLD( PERV_FSI_A_SMODE_OWN_ID_THIS_SLAVE_LEN                  , 2   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_OWN_ID_THIS_SLAVE_LEN );
REG32_FLD( PERV_FSI_A_SMODE_ECHO_DELAY_CYCLES                      , 8   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ECHO_DELAY_CYCLES );
REG32_FLD( PERV_FSI_A_SMODE_ECHO_DELAY_CYCLES_LEN                  , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_ECHO_DELAY_CYCLES_LEN );
REG32_FLD( PERV_FSI_A_SMODE_SEND_DELAY_CYCLES                      , 12  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_SEND_DELAY_CYCLES );
REG32_FLD( PERV_FSI_A_SMODE_SEND_DELAY_CYCLES_LEN                  , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_SEND_DELAY_CYCLES_LEN );
REG32_FLD( PERV_FSI_A_SMODE_LBUS_CLOCK_DIVIDER                     , 20  , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_LBUS_CLOCK_DIVIDER );
REG32_FLD( PERV_FSI_A_SMODE_LBUS_CLOCK_DIVIDER_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_FSI0     ,
           SH_FLD_LBUS_CLOCK_DIVIDER_LEN );

REG32_FLD( PERV_FSI_B_LLMOD_ASYNC_MODE                             , 31  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ASYNC_MODE );

REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_ENABLE                      , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_1_ENABLE                    , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_1_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_2_ENABLE                    , 2   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_2_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_3_ENABLE                    , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_3_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_4_ENABLE                    , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_4_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_5_ENABLE                    , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_5_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_6_ENABLE                    , 6   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_6_ENABLE );
REG32_FLD( PERV_FSI_B_MST_0_MENP0_PORT_7_ENABLE                    , 7   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_7_ENABLE );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_ENABLE             , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_1_ENABLE           , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_1_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_2_ENABLE           , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_2_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_3_ENABLE           , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_3_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_4_ENABLE           , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_4_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_5_ENABLE           , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_5_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_6_ENABLE           , 6   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_6_ENABLE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MENP0_PORT_7_ENABLE           , 7   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_7_ENABLE );

REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FIRST_ERROR                     , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FIRST_ERROR );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FIRST_ERROR_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FIRST_ERROR_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST         , 17  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FAILING_OPB_MASTER_FRST );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN     , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FAILING_OPB_MASTER_FRST_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_ACTUAL_ERROR                    , 20  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ACTUAL_ERROR );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_ACTUAL_ERROR_LEN                , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT          , 29  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FAILING_OPB_MASTER_ACT );
REG32_FLD( PERV_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN      , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_FAILING_OPB_MASTER_ACT_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FIRST_ERROR            , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FIRST_ERROR );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FIRST_ERROR_LEN        , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FIRST_ERROR_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST , 17  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FAILING_OPB_MASTER_FRST );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FAILING_OPB_MASTER_FRST_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_ACTUAL_ERROR           , 20  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ACTUAL_ERROR );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_ACTUAL_ERROR_LEN       , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT , 29  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FAILING_OPB_MASTER_ACT );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_FAILING_OPB_MASTER_ACT_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MMODE_ENABLE_IPOLL_AND_DMA             , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_IPOLL_AND_DMA );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY         , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS     , 2   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_RELATIVE_ADDRESS_CMDS );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_ENABLE_PARITY_CHECK              , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_PARITY_CHECK );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION             , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_CLOCK_RATE_SELECTION );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN         , 10  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_CLOCK_RATE_SELECTION_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1           , 14  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_CLOCK_RATE_SELECTION_1 );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN       , 10  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_CLOCK_RATE_SELECTION_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_CLOCK_DIV_4                      , 25  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_CLOCK_DIV_4 );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_TIMEOUT_SEL                      , 26  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_TIMEOUT_SEL );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_TIMEOUT_SEL_LEN                  , 2   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_TIMEOUT_SEL_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_RECEIVER_MODE                    , 29  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_RECEIVER_MODE );
REG32_FLD( PERV_FSI_B_MST_0_MMODE_RECEIVER_MODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_RECEIVER_MODE_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_IPOLL_AND_DMA    , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ENABLE_IPOLL_AND_DMA );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ENABLE_RELATIVE_ADDRESS_CMDS );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_ENABLE_PARITY_CHECK     , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_ENABLE_PARITY_CHECK );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION    , 4   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_CLOCK_RATE_SELECTION );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_LEN , 10  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_CLOCK_RATE_SELECTION_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1  , 14  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_CLOCK_RATE_SELECTION_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN , 10  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_CLOCK_RATE_SELECTION_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_CLOCK_DIV_4             , 25  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_CLOCK_DIV_4 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_TIMEOUT_SEL             , 26  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_TIMEOUT_SEL );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_TIMEOUT_SEL_LEN         , 2   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_TIMEOUT_SEL_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_RECEIVER_MODE           , 29  , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_RECEIVER_MODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MMODE_RECEIVER_MODE_LEN       , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_RECEIVER_MODE_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MRESP1_PORT_GENERAL_RESET_1            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_1 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP1_PORT_ERROR_RESET_1              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_1 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP1_PORT_GENERAL_RESET_1   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP1_PORT_ERROR_RESET_1     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_1 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP2_PORT_GENERAL_RESET_2            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_2 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP2_PORT_ERROR_RESET_2              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_2 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP2_PORT_GENERAL_RESET_2   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP2_PORT_ERROR_RESET_2     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_2 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP3_PORT_GENERAL_RESET_3            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_3 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP3_PORT_ERROR_RESET_3              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_3 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP3_PORT_GENERAL_RESET_3   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_3 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP3_PORT_ERROR_RESET_3     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_3 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP4_PORT_GENERAL_RESET_4            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_4 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP4_PORT_ERROR_RESET_4              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_4 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP4_PORT_GENERAL_RESET_4   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_4 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP4_PORT_ERROR_RESET_4     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_4 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP5_PORT_GENERAL_RESET_5            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_5 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP5_PORT_ERROR_RESET_5              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_5 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP5_PORT_GENERAL_RESET_5   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_5 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP5_PORT_ERROR_RESET_5     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_5 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP6_PORT_GENERAL_RESET_6            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_6 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP6_PORT_ERROR_RESET_6              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_6 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP6_PORT_GENERAL_RESET_6   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_6 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP6_PORT_ERROR_RESET_6     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_6 );

REG32_FLD( PERV_FSI_B_MST_0_MRESP7_PORT_GENERAL_RESET_7            , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_GENERAL_RESET_7 );
REG32_FLD( PERV_FSI_B_MST_0_MRESP7_PORT_ERROR_RESET_7              , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT_ERROR_RESET_7 );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP7_PORT_GENERAL_RESET_7   , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_GENERAL_RESET_7 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MRESP7_PORT_ERROR_RESET_7     , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT_ERROR_RESET_7 );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT0_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP0_PORT0_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT0_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT1_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP1_PORT1_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT1_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT2_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP2_PORT2_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT2_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT3_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP3_PORT3_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT3_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT4_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP4_PORT4_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT4_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT5_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP5_PORT5_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT5_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT6_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP6_PORT6_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT6_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE                , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1              , 5   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE_1 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2              , 9   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE_2 );
REG32_FLD( PERV_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN          , 3   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_PORT7_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE       , 1   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_LEN   , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1     , 5   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE_1 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_1_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE_1_LEN );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2     , 9   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE_2 );
REG32_FLD( PERV_FSISHIFT_FSI_B_MST_0_MSTAP7_PORT7_ERROR_CODE_2_LEN , 3   , SH_UNT_PERV_FSISHIFT, SH_ACS_SCOMFSI1 ,
           SH_FLD_PORT7_ERROR_CODE_2_LEN );

REG32_FLD( PERV_FSI_B_SMODE_WARM_START_COMPLETED                   , 0   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_WARM_START_COMPLETED );
REG32_FLD( PERV_FSI_B_SMODE_ENABLE_AUX_PORT_UNUSED                 , 1   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_AUX_PORT_UNUSED );
REG32_FLD( PERV_FSI_B_SMODE_ENABLE_HW_ERROR_RECOVERY               , 2   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ENABLE_HW_ERROR_RECOVERY );
REG32_FLD( PERV_FSI_B_SMODE_OWN_ID_THIS_SLAVE                      , 6   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_OWN_ID_THIS_SLAVE );
REG32_FLD( PERV_FSI_B_SMODE_OWN_ID_THIS_SLAVE_LEN                  , 2   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_OWN_ID_THIS_SLAVE_LEN );
REG32_FLD( PERV_FSI_B_SMODE_ECHO_DELAY_CYCLES                      , 8   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ECHO_DELAY_CYCLES );
REG32_FLD( PERV_FSI_B_SMODE_ECHO_DELAY_CYCLES_LEN                  , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_ECHO_DELAY_CYCLES_LEN );
REG32_FLD( PERV_FSI_B_SMODE_SEND_DELAY_CYCLES                      , 12  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_SEND_DELAY_CYCLES );
REG32_FLD( PERV_FSI_B_SMODE_SEND_DELAY_CYCLES_LEN                  , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_SEND_DELAY_CYCLES_LEN );
REG32_FLD( PERV_FSI_B_SMODE_LBUS_CLOCK_DIVIDER                     , 20  , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_LBUS_CLOCK_DIVIDER );
REG32_FLD( PERV_FSI_B_SMODE_LBUS_CLOCK_DIVIDER_LEN                 , 4   , SH_UNT_PERV     , SH_ACS_FSI1     ,
           SH_FLD_LBUS_CLOCK_DIVIDER_LEN );

REG64_FLD( PERV_GPWRP_MAGIC_COOKIE                                 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MAGIC_COOKIE );
REG64_FLD( PERV_GPWRP_MAGIC_COOKIE_LEN                             , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MAGIC_COOKIE_LEN );
REG64_FLD( PERV_GPWRP_EN_OR_DIS_WRITE_PROTECTION                   , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_EN_OR_DIS_WRITE_PROTECTION );
REG64_FLD( PERV_GPWRP_EN_OR_DIS_WRITE_PROTECTION_LEN               , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_EN_OR_DIS_WRITE_PROTECTION_LEN );

REG64_FLD( PERV_1_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN                 , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN );
REG64_FLD( PERV_1_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN_LEN             , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN_LEN );

REG64_FLD( PERV_1_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN                 , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN );
REG64_FLD( PERV_1_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN_LEN             , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN_LEN );

REG64_FLD( PERV_1_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN                 , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN );
REG64_FLD( PERV_1_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN_LEN             , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN_LEN );

REG64_FLD( PERV_1_GXSTOP_TRIG_REG_GXSTP_IN                         , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN   );
REG64_FLD( PERV_1_GXSTOP_TRIG_REG_GXSTP_IN_LEN                     , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN_LEN );

REG64_FLD( PERV_1_HANG_PULSE_0_REG_0                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_0          );
REG64_FLD( PERV_1_HANG_PULSE_0_REG_0_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_0_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_0_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_1_REG_1                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_1          );
REG64_FLD( PERV_1_HANG_PULSE_1_REG_1_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_1_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_1_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_2_REG_2                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_2          );
REG64_FLD( PERV_1_HANG_PULSE_2_REG_2_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_2_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_2_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_3_REG_3                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_3          );
REG64_FLD( PERV_1_HANG_PULSE_3_REG_3_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_3_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_3_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_4_REG_4                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_4          );
REG64_FLD( PERV_1_HANG_PULSE_4_REG_4_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_4_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_4_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_5_REG_5                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_5          );
REG64_FLD( PERV_1_HANG_PULSE_5_REG_5_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_5_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_5_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HANG_PULSE_6_REG_6                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_6          );
REG64_FLD( PERV_1_HANG_PULSE_6_REG_6_LEN                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_6_LEN      );
REG64_FLD( PERV_1_HANG_PULSE_6_REG_SUPPRESS                        , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( PERV_1_HEARTBEAT_REG_DEAD                               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DEAD       );

REG64_FLD( PERV_HOST_MASK_REG_IPOLL_0                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_0    );
REG64_FLD( PERV_HOST_MASK_REG_IPOLL_1                              , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_1    );
REG64_FLD( PERV_HOST_MASK_REG_IPOLL_2                              , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_2    );
REG64_FLD( PERV_HOST_MASK_REG_IPOLL_3                              , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_3    );
REG64_FLD( PERV_HOST_MASK_REG_IPOLL_4                              , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_4    );
REG64_FLD( PERV_HOST_MASK_REG_IPOLL_5                              , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IPOLL_5    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_0                              , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_0    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_1                              , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_1    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_2                              , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_2    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_3                              , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_3    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_4                              , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_4    );
REG64_FLD( PERV_HOST_MASK_REG_ERROR_5                              , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_5    );

REG64_FLD( PERV_IGNORE_PAR_REG_PARITY                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PARITY     );
REG64_FLD( PERV_IGNORE_PAR_REG_DISABLE_ECC_CORRECTION              , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_ECC_CORRECTION );
REG64_FLD( PERV_IGNORE_PAR_REG_ECC_S_BIT_ERROR                     , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ECC_S_BIT_ERROR );

REG64_FLD( PERV_1_INJECT_REG_THERM_TRIP                            , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP );
REG64_FLD( PERV_1_INJECT_REG_THERM_TRIP_LEN                        , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP_LEN );
REG64_FLD( PERV_1_INJECT_REG_THERM_MODE                            , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE );
REG64_FLD( PERV_1_INJECT_REG_THERM_MODE_LEN                        , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE_LEN );

REG32_FLD( PERV_FSI2PIB_INTERRUPT_STATUS_REG                       , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_STATUS_REG );
REG32_FLD( PERV_FSI2PIB_INTERRUPT_STATUS_REG_LEN                   , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_STATUS_REG_LEN );

REG64_FLD( PERV_INTERRUPT1_REG_INTERRUPT1                          , 0   , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT1 );
REG64_FLD( PERV_INTERRUPT1_REG_INTERRUPT1_LEN                      , 56  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT1_LEN );

REG64_FLD( PERV_INTERRUPT2_REG_INTERRUPT2                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT2 );
REG64_FLD( PERV_INTERRUPT2_REG_INTERRUPT2_LEN                      , 22  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT2_LEN );

REG64_FLD( PERV_INTERRUPT3_REG_INTERRUPT3                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT3 );
REG64_FLD( PERV_INTERRUPT3_REG_INTERRUPT3_LEN                      , 23  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT3_LEN );

REG64_FLD( PERV_INTERRUPT4_REG_INTERRUPT4                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT4 );
REG64_FLD( PERV_INTERRUPT4_REG_INTERRUPT4_LEN                      , 23  , SH_UNT_PERV     , SH_ACS_SCOM2_AND,
           SH_FLD_INTERRUPT4_LEN );

REG64_FLD( PERV_INTERRUPT_CONF_REG_UNUSED0                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED0    );
REG64_FLD( PERV_INTERRUPT_CONF_REG_SEL0                            , 1   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_SEL0       );
REG64_FLD( PERV_INTERRUPT_CONF_REG_SEL0_LEN                        , 3   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_SEL0_LEN   );
REG64_FLD( PERV_INTERRUPT_CONF_REG_UNUSED4                         , 4   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED4    );
REG64_FLD( PERV_INTERRUPT_CONF_REG_SEL1                            , 5   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_SEL1       );
REG64_FLD( PERV_INTERRUPT_CONF_REG_SEL1_LEN                        , 3   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_SEL1_LEN   );
REG64_FLD( PERV_INTERRUPT_CONF_REG_GP                              , 8   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_GP         );
REG64_FLD( PERV_INTERRUPT_CONF_REG_CC                              , 9   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_CC         );
REG64_FLD( PERV_INTERRUPT_CONF_REG_UNUSED2                         , 10  , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED2    );
REG64_FLD( PERV_INTERRUPT_CONF_REG_UNUSED3                         , 11  , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED3    );

REG64_FLD( PERV_INTERRUPT_HOLD_REG_HOLD                            , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HOLD       );
REG64_FLD( PERV_INTERRUPT_HOLD_REG_HOLD_LEN                        , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HOLD_LEN   );

REG32_FLD( PERV_FSII2C_INTERRUPT_MASK_REGISTER_INT                 , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM2_AND,
           SH_FLD_INT        );
REG32_FLD( PERV_FSII2C_INTERRUPT_MASK_REGISTER_INT_LEN             , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM2_AND,
           SH_FLD_INT_LEN    );

REG64_FLD( PERV_INTERRUPT_TYPE_MASK_REG_GP                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_GP         );
REG64_FLD( PERV_INTERRUPT_TYPE_MASK_REG_CC                         , 1   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_CC         );
REG64_FLD( PERV_INTERRUPT_TYPE_MASK_REG_UNUSED2                    , 2   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED2    );
REG64_FLD( PERV_INTERRUPT_TYPE_MASK_REG_UNUSED3                    , 3   , SH_UNT_PERV     , SH_ACS_SCOM2_WAND,
           SH_FLD_UNUSED3    );

REG64_FLD( PERV_INTERRUPT_TYPE_REG_ATTENTION                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ATTENTION  );
REG64_FLD( PERV_INTERRUPT_TYPE_REG_RECOVERABLE_ERROR               , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RECOVERABLE_ERROR );
REG64_FLD( PERV_INTERRUPT_TYPE_REG_CHECKSTOP                       , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_CHECKSTOP  );

REG64_FLD( PERV_IODA_TCD_IDIAL_VLD                                 , 0   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_VLD  );
REG64_FLD( PERV_IODA_TCD_IDIAL_RSVD0                               , 1   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0 );
REG64_FLD( PERV_IODA_TCD_IDIAL_RSVD0_LEN                           , 5   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0_LEN );
REG64_FLD( PERV_IODA_TCD_IDIAL_PC                                  , 6   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PC   );
REG64_FLD( PERV_IODA_TCD_IDIAL_PC_LEN                              , 2   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PC_LEN );
REG64_FLD( PERV_IODA_TCD_IDIAL_PE                                  , 8   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PE   );
REG64_FLD( PERV_IODA_TCD_IDIAL_PE_LEN                              , 4   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PE_LEN );
REG64_FLD( PERV_IODA_TCD_IDIAL_EA                                  , 12  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_EA   );
REG64_FLD( PERV_IODA_TCD_IDIAL_EA_LEN                              , 37  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_EA_LEN );
REG64_FLD( PERV_IODA_TCD_IDIAL_RSVD1                               , 49  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD1 );
REG64_FLD( PERV_IODA_TCD_IDIAL_RSVD1_LEN                           , 15  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD1_LEN );

REG64_FLD( PERV_IODA_TDR_IDIAL_RA                                  , 0   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RA   );
REG64_FLD( PERV_IODA_TDR_IDIAL_RA_LEN                              , 39  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RA_LEN );
REG64_FLD( PERV_IODA_TDR_IDIAL_RSVD0                               , 39  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0 );
REG64_FLD( PERV_IODA_TDR_IDIAL_RSVD0_LEN                           , 2   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0_LEN );
REG64_FLD( PERV_IODA_TDR_IDIAL_PAR                                 , 41  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PAR  );
REG64_FLD( PERV_IODA_TDR_IDIAL_PAR_LEN                             , 5   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PAR_LEN );

REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RSVD0                           , 0   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0 );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RSVD0_LEN                       , 13  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0_LEN );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RA                              , 13  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RA   );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RA_LEN                          , 39  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RA_LEN );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RSVD1                           , 52  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD1 );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_RSVD1_LEN                       , 10  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD1_LEN );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_PC                              , 62  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PC   );
REG64_FLD( PERV_IODA_TDR_MEM_IDIAL_PC_LEN                          , 2   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PC_LEN );

REG64_FLD( PERV_FSB_IODA_TVT_TVT0_XLAT_ADDR                        , 0   , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_XLAT_ADDR );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_XLAT_ADDR_LEN                    , 48  , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_XLAT_ADDR_LEN );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_TABLE_LEVEL                      , 48  , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_TABLE_LEVEL );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_TABLE_LEVEL_LEN                  , 3   , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_TABLE_LEVEL_LEN );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_TABLE_SIZE                       , 51  , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_TABLE_SIZE );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_TABLE_SIZE_LEN                   , 5   , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_TABLE_SIZE_LEN );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_SPARE                            , 56  , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_SPARE );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_SPARE_LEN                        , 3   , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_SPARE_LEN );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_PAGE_SIZE                        , 59  , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_PAGE_SIZE );
REG64_FLD( PERV_FSB_IODA_TVT_TVT0_PAGE_SIZE_LEN                    , 5   , SH_UNT_PERV_FSB , SH_ACS_IODA     ,
           SH_FLD_TVT0_PAGE_SIZE_LEN );

REG64_FLD( PERV_IODA_XLT_EA_IDIAL_EA                               , 0   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_EA   );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_EA_LEN                           , 37  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_EA_LEN );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_PE                               , 37  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PE   );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_PE_LEN                           , 4   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_PE_LEN );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_RNW                              , 41  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RNW  );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_TAG                              , 42  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_TAG  );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_TAG_LEN                          , 8   , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_TAG_LEN );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_RSVD0                            , 50  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0 );
REG64_FLD( PERV_IODA_XLT_EA_IDIAL_RSVD0_LEN                        , 14  , SH_UNT_PERV     , SH_ACS_IODA     ,
           SH_FLD_IDIAL_RSVD0_LEN );

REG64_FLD( PERV_1_LOCAL_FIR_IN0                                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_LOCAL_FIR_IN1                                    , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN1        );
REG64_FLD( PERV_1_LOCAL_FIR_IN2                                    , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN2        );
REG64_FLD( PERV_1_LOCAL_FIR_IN3                                    , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN3        );
REG64_FLD( PERV_1_LOCAL_FIR_IN4                                    , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_LOCAL_FIR_IN5                                    , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_LOCAL_FIR_IN6                                    , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_LOCAL_FIR_IN7                                    , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_LOCAL_FIR_IN8                                    , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_LOCAL_FIR_IN9                                    , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN9        );
REG64_FLD( PERV_1_LOCAL_FIR_IN10                                   , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN10       );
REG64_FLD( PERV_1_LOCAL_FIR_IN11                                   , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN11       );
REG64_FLD( PERV_1_LOCAL_FIR_IN12                                   , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN12       );
REG64_FLD( PERV_1_LOCAL_FIR_IN12_LEN                               , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN12_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN14                                   , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN14       );
REG64_FLD( PERV_1_LOCAL_FIR_IN15                                   , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN15       );
REG64_FLD( PERV_1_LOCAL_FIR_IN16                                   , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN16       );
REG64_FLD( PERV_1_LOCAL_FIR_IN16_LEN                               , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN16_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN19                                   , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN19       );
REG64_FLD( PERV_1_LOCAL_FIR_IN20                                   , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN20       );
REG64_FLD( PERV_1_LOCAL_FIR_IN21                                   , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN21       );
REG64_FLD( PERV_1_LOCAL_FIR_IN22                                   , 22  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN22       );
REG64_FLD( PERV_1_LOCAL_FIR_IN22_LEN                               , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN22_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN24                                   , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN24       );
REG64_FLD( PERV_1_LOCAL_FIR_IN25                                   , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN25       );
REG64_FLD( PERV_1_LOCAL_FIR_IN26                                   , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN26       );
REG64_FLD( PERV_1_LOCAL_FIR_IN27                                   , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN27       );
REG64_FLD( PERV_1_LOCAL_FIR_IN28                                   , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN28       );
REG64_FLD( PERV_1_LOCAL_FIR_IN29                                   , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN29       );
REG64_FLD( PERV_1_LOCAL_FIR_IN29_LEN                               , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN29_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN31                                   , 31  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN31       );
REG64_FLD( PERV_1_LOCAL_FIR_IN31_LEN                               , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN31_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN33                                   , 33  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN33       );
REG64_FLD( PERV_1_LOCAL_FIR_IN33_LEN                               , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN33_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN35                                   , 35  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN35       );
REG64_FLD( PERV_1_LOCAL_FIR_IN36                                   , 36  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN36       );
REG64_FLD( PERV_1_LOCAL_FIR_IN36_LEN                               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN36_LEN   );
REG64_FLD( PERV_1_LOCAL_FIR_IN40                                   , 40  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_IN40       );

REG64_FLD( PERV_1_LOCAL_FIR_ACTION0_IN                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( PERV_1_LOCAL_FIR_ACTION0_IN_LEN                         , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( PERV_1_LOCAL_FIR_ACTION1_IN                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( PERV_1_LOCAL_FIR_ACTION1_IN_LEN                         , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( PERV_1_LOCAL_FIR_MASK_LFIR_IN                           , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN    );
REG64_FLD( PERV_1_LOCAL_FIR_MASK_LFIR_IN_LEN                       , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC0A     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC0A_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC0B     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC0B_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_1_A_M1HC1A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC1A     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_1_A_M1HC1A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC1A_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_1_B_M1HC1B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC1B     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_1_B_M1HC1B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC1B_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_2_A_M1HC2A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC2A     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_2_A_M1HC2A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M1HC2A_LEN );

REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_2_B_M1HC2B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC2B     );
REG64_FLD( PERV_MAILBOX_1_HEADER_COMMAND_2_B_M1HC2B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M1HC2B_LEN );

REG64_FLD( PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_PIB_PENDING , 29  , SH_UNT_PERV     ,
           SH_ACS_SCOM1_CLEAR, SH_FLD_M1SASIM1_ENABLE_PIB_PENDING );
REG64_FLD( PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_XUP , 30  , SH_UNT_PERV     ,
           SH_ACS_SCOM1_CLEAR, SH_FLD_M1SASIM1_ENABLE_XUP );
REG64_FLD( PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_M1SASIM1_ENABLE_PIB_ERROR , 31  , SH_UNT_PERV     ,
           SH_ACS_SCOM1_CLEAR, SH_FLD_M1SASIM1_ENABLE_PIB_ERROR );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC0A     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC0A_LEN );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC0B     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC0B_LEN );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC1A     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC1A_LEN );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC1B     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC1B_LEN );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_2_A_M2HC2A                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC2A     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_2_A_M2HC2A_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M2HC2A_LEN );

REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_2_B_M2HC2B                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC2B     );
REG64_FLD( PERV_MAILBOX_2_HEADER_COMMAND_2_B_M2HC2B_LEN            , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_M2HC2B_LEN );

REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_31_28 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADES_UNUSED_31_28 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_31_28_LEN , 4   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_UNUSED_31_28_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ILLEGAL_OPERATION_ATTEMPTED_1 , 4   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ILLEGAL_OPERATION_ATTEMPTED_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_WRITE_FULL_PIB_1 , 5   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_WRITE_FULL_PIB_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_READ_EMPTY_PIB_1 , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_READ_EMPTY_PIB_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_LBUS_B_RAM_PARITY_DETECTED_1 , 7   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_LBUS_B_RAM_PARITY_DETECTED_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_1 , 8   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ADDRESS_OF_LBUS_PARITY_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_1_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ADDRESS_OF_LBUS_PARITY_1_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_15_12 , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADES_UNUSED_15_12 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_UNUSED_15_12_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_UNUSED_15_12_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ILLEGAL_OPERATION_ATTEMPTED_2 , 20  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ILLEGAL_OPERATION_ATTEMPTED_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_WRITE_FULL_PIB_2 , 21  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_WRITE_FULL_PIB_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_READ_EMPTY_PIB_2 , 22  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_READ_EMPTY_PIB_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_LBUS_B_RAM_PARITY_DETECTED_2 , 23  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_LBUS_B_RAM_PARITY_DETECTED_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_2 , 24  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ADDRESS_OF_LBUS_PARITY_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSADES_ADDRESS_OF_LBUS_PARITY_2_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSADES_ADDRESS_OF_LBUS_PARITY_2_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_1_0 , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_1_0 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_1_0_LEN , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_1_0_LEN );

REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_31_11 , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_UNUSED_31_11 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_31_11_LEN , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_UNUSED_31_11_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_ERROR_2 , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_PIB_ERROR_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_XUP_2     , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_XUP_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_PENDING_2 , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_PIB_PENDING_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_7_3 , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_UNUSED_7_3 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_UNUSED_7_3_LEN , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_UNUSED_7_3_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_ERROR_1 , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_PIB_ERROR_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_XUP_1     , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_XUP_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_MSADI_PIB_PENDING_1 , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSADI_PIB_PENDING_1 );

REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_31_28 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_31_28 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_31_28_LEN , 4   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_UNUSED_31_28_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_1 , 4   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_WRITE_FULL_PIB_A_1 , 5   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_WRITE_FULL_PIB_A_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_READ_EMPTY_PIB_A_1 , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_READ_EMPTY_PIB_A_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_PIB_A_RAM_PARITY_DETECTED_1 , 7   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_PIB_A_RAM_PARITY_DETECTED_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_1 , 8   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ADDRESS_OF_PIB_PARITY_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_1_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ADDRESS_OF_PIB_PARITY_1_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_17_12 , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_17_12 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_17_12_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_UNUSED_17_12_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_2 , 20  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ILLEGAL_OPERATION_ATTEMPTED_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_WRITE_FULL_PIB_A_2 , 21  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_WRITE_FULL_PIB_A_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_READ_EMPTY_PIB_A_2 , 22  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_READ_EMPTY_PIB_A_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_PIB_A_RAM_PARITY_DETECTED_2 , 23  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_PIB_A_RAM_PARITY_DETECTED_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_2 , 24  , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ADDRESS_OF_PIB_PARITY_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_ADDRESS_OF_PIB_PARITY_2_LEN , 6   , SH_UNT_PERV     ,
           SH_ACS_SCOM     , SH_FLD_MSBDES_ADDRESS_OF_PIB_PARITY_2_LEN );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_1_0 , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_1_0 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_MSBDES_UNUSED_1_0_LEN , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDES_UNUSED_1_0_LEN );

REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_PENDING_1 , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_LBUS_PENDING_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_PENDING_2 , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_LBUS_PENDING_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_XDN_1     , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_XDN_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_XDN_2     , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_XDN_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_ERROR_1 , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_LBUS_ERROR_1 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MSBDI_LBUS_ERROR_2 , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MSBDI_LBUS_ERROR_2 );

REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_PENDING , 24  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_LBUS_PENDING );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_PENDING_2 , 25  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_LBUS_PENDING_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_XDN , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MSBDIM1_ENABLE_XDN );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_XDN_2 , 27  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_XDN_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_ERROR , 28  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_LBUS_ERROR );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_LBUS_ERROR_2 , 29  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_LBUS_ERROR_2 );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_ABORT , 30  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_ABORT );
REG64_FLD( PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_MSBDIM1_ENABLE_ABORT_2 , 31  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RO  , SH_FLD_MSBDIM1_ENABLE_ABORT_2 );

REG64_FLD( PERV_MCAST_COMP_MASK_REG_MULTICAST_COMPARE_REGISTER     , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_REGISTER );
REG64_FLD( PERV_MCAST_COMP_MASK_REG_MULTICAST_COMPARE_REGISTER_LEN , 64  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_REGISTER_LEN );

REG64_FLD( PERV_MCAST_COMP_REG_MULTICAST_COMPARE_REGISTER          , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_REGISTER );
REG64_FLD( PERV_MCAST_COMP_REG_MULTICAST_COMPARE_REGISTER_LEN      , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_REGISTER_LEN );

REG64_FLD( PERV_MCAST_COMP_VAL_REG_MULTICAST_COMPARE_VALUE_REGISTER , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_VALUE_REGISTER );
REG64_FLD( PERV_MCAST_COMP_VAL_REG_MULTICAST_COMPARE_VALUE_REGISTER_LEN , 64  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST_COMPARE_VALUE_REGISTER_LEN );

REG64_FLD( PERV_MCAST_GRP_0_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_0_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_1_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_1_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_2_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_2_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_3_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_3_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_4_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_4_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_5_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_5_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MCAST_GRP_6_SLAVES_REG_GROUP                       , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( PERV_MCAST_GRP_6_SLAVES_REG_GROUP_LEN                   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );

REG64_FLD( PERV_MIB_XIICAC_ICACHE_TAG_ADDR                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR );
REG64_FLD( PERV_MIB_XIICAC_ICACHE_TAG_ADDR_LEN                     , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR_LEN );
REG64_FLD( PERV_MIB_XIICAC_ICACHE_ERR                              , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_ERR );
REG64_FLD( PERV_MIB_XIICAC_XISIB_PIB_IFETCH_PENDING                , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_XISIB_PIB_IFETCH_PENDING );
REG64_FLD( PERV_MIB_XIICAC_XIMEM_MEM_IFETCH_PENDING                , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IFETCH_PENDING );
REG64_FLD( PERV_MIB_XIICAC_ICACHE_VALID                            , 36  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID );
REG64_FLD( PERV_MIB_XIICAC_ICACHE_VALID_LEN                        , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID_LEN );

REG64_FLD( PERV_MIB_XIMEM_MEM_ADDR                                 , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR   );
REG64_FLD( PERV_MIB_XIMEM_MEM_ADDR_LEN                             , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR_LEN );
REG64_FLD( PERV_MIB_XIMEM_MEM_R_NW                                 , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_R_NW   );
REG64_FLD( PERV_MIB_XIMEM_MEM_BUSY                                 , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BUSY   );
REG64_FLD( PERV_MIB_XIMEM_MEM_IMPRECISE_ERROR_PENDING              , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( PERV_MIB_XIMEM_MEM_BYTE_ENABLE                          , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE );
REG64_FLD( PERV_MIB_XIMEM_MEM_BYTE_ENABLE_LEN                      , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE_LEN );
REG64_FLD( PERV_MIB_XIMEM_MEM_LINE_MODE                            , 43  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_LINE_MODE );
REG64_FLD( PERV_MIB_XIMEM_MEM_ERROR                                , 49  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR  );
REG64_FLD( PERV_MIB_XIMEM_MEM_ERROR_LEN                            , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR_LEN );
REG64_FLD( PERV_MIB_XIMEM_MEM_IFETCH_PENDING                       , 62  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IFETCH_PENDING );
REG64_FLD( PERV_MIB_XIMEM_MEM_DATAOP_PENDING                       , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_DATAOP_PENDING );

REG64_FLD( PERV_MIB_XISGB_STORE_ADDRESS                            , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS );
REG64_FLD( PERV_MIB_XISGB_STORE_ADDRESS_LEN                        , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS_LEN );
REG64_FLD( PERV_MIB_XISGB_XIMEM_MEM_IMPRECISE_ERROR_PENDING        , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( PERV_MIB_XISGB_SGB_BYTE_VALID                           , 36  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID );
REG64_FLD( PERV_MIB_XISGB_SGB_BYTE_VALID_LEN                       , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID_LEN );
REG64_FLD( PERV_MIB_XISGB_SGB_FLUSH_PENDING                        , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_FLUSH_PENDING );

REG64_FLD( PERV_MIB_XISIB_PIB_ADDR                                 , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR   );
REG64_FLD( PERV_MIB_XISIB_PIB_ADDR_LEN                             , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR_LEN );
REG64_FLD( PERV_MIB_XISIB_PIB_R_NW                                 , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_R_NW   );
REG64_FLD( PERV_MIB_XISIB_PIB_BUSY                                 , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_BUSY   );
REG64_FLD( PERV_MIB_XISIB_PIB_IMPRECISE_ERROR_PENDING              , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IMPRECISE_ERROR_PENDING );
REG64_FLD( PERV_MIB_XISIB_PIB_RSP_INFO                             , 49  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO );
REG64_FLD( PERV_MIB_XISIB_PIB_RSP_INFO_LEN                         , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO_LEN );
REG64_FLD( PERV_MIB_XISIB_PIB_IFETCH_PENDING                       , 62  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IFETCH_PENDING );
REG64_FLD( PERV_MIB_XISIB_PIB_DATAOP_PENDING                       , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_DATAOP_PENDING );

REG64_FLD( PERV_1_MODE_REG_IN0                                     , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_MODE_REG_IN1                                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( PERV_1_MODE_REG_IN2                                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( PERV_1_MODE_REG_IN3                                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( PERV_1_MODE_REG_IN4                                     , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_MODE_REG_IN5                                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_MODE_REG_IN6                                     , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_MODE_REG_IN7                                     , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_MODE_REG_IN8                                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_MODE_REG_IN9                                     , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( PERV_1_MODE_REG_IN10                                    , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( PERV_1_MODE_REG_IN11                                    , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( PERV_1_MODE_REG_IN                                      , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( PERV_1_MODE_REG_IN_LEN                                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG32_FLD( PERV_FSII2C_MODE_REGISTER_BIT_RATE_DIVISOR              , 0   , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_BIT_RATE_DIVISOR );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_BIT_RATE_DIVISOR_LEN          , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_BIT_RATE_DIVISOR_LEN );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_PORT_NUMBER                   , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_PORT_NUMBER );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_PORT_NUMBER_LEN               , 6   , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_PORT_NUMBER_LEN );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_CHKSW_I2C_BUSY                , 27  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_CHKSW_I2C_BUSY );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_FGAT                          , 28  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_FGAT       );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_DIAG                          , 29  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_DIAG       );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_PACING_ALLOW                  , 30  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_PACING_ALLOW );
REG32_FLD( PERV_FSII2C_MODE_REGISTER_WRAP                          , 31  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_WRAP       );

REG64_FLD( PERV_1_MULTICAST_GROUP_1_MULTICAST1                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1 );
REG64_FLD( PERV_1_MULTICAST_GROUP_1_MULTICAST1_LEN                 , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1_LEN );

REG64_FLD( PERV_1_MULTICAST_GROUP_2_MULTICAST2                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2 );
REG64_FLD( PERV_1_MULTICAST_GROUP_2_MULTICAST2_LEN                 , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2_LEN );

REG64_FLD( PERV_1_MULTICAST_GROUP_3_MULTICAST3                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3 );
REG64_FLD( PERV_1_MULTICAST_GROUP_3_MULTICAST3_LEN                 , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3_LEN );

REG64_FLD( PERV_1_MULTICAST_GROUP_4_MULTICAST4                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4 );
REG64_FLD( PERV_1_MULTICAST_GROUP_4_MULTICAST4_LEN                 , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4_LEN );

REG64_FLD( PERV_1_NET_CTRL0_CHIPLET_ENABLE                         , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CHIPLET_ENABLE );
REG64_FLD( PERV_1_NET_CTRL0_PCB_EP_RESET                           , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_PCB_EP_RESET );
REG64_FLD( PERV_1_NET_CTRL0_CLK_ASYNC_RESET                        , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_ASYNC_RESET );
REG64_FLD( PERV_1_NET_CTRL0_PLL_TEST_EN                            , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_TEST_EN );
REG64_FLD( PERV_1_NET_CTRL0_PLL_RESET                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_RESET  );
REG64_FLD( PERV_1_NET_CTRL0_PLL_BYPASS                             , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_BYPASS );
REG64_FLD( PERV_1_NET_CTRL0_VITAL_SCAN                             , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN );
REG64_FLD( PERV_1_NET_CTRL0_VITAL_SCAN_IN                          , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN_IN );
REG64_FLD( PERV_1_NET_CTRL0_FLUSH_ALIGN_OVR                        , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_ALIGN_OVR );
REG64_FLD( PERV_1_NET_CTRL0_ARRAY_WRITE_ASSIST_EN                  , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_ARRAY_WRITE_ASSIST_EN );
REG64_FLD( PERV_1_NET_CTRL0_ACT_DIS                                , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_ACT_DIS    );
REG64_FLD( PERV_1_NET_CTRL0_MPW1                                   , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW1       );
REG64_FLD( PERV_1_NET_CTRL0_MPW2                                   , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW2       );
REG64_FLD( PERV_1_NET_CTRL0_MPW3                                   , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW3       );
REG64_FLD( PERV_1_NET_CTRL0_DELAY_LCLKR                            , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_DELAY_LCLKR );
REG64_FLD( PERV_1_NET_CTRL0_VITAL_THOLD                            , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_THOLD );
REG64_FLD( PERV_1_NET_CTRL0_FLUSH_SCAN_N                           , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_SCAN_N );
REG64_FLD( PERV_1_NET_CTRL0_FENCE_EN                               , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_FENCE_EN   );
REG64_FLD( PERV_1_NET_CTRL0_RI_N                                   , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_RI_N       );
REG64_FLD( PERV_1_NET_CTRL0_DI1_N                                  , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_DI1_N      );
REG64_FLD( PERV_1_NET_CTRL0_DI2_N                                  , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_DI2_N      );
REG64_FLD( PERV_1_NET_CTRL0_TP_FENCE_PCB                           , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_TP_FENCE_PCB );
REG64_FLD( PERV_1_NET_CTRL0_LVLTRANS_FENCE                         , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_LVLTRANS_FENCE );
REG64_FLD( PERV_1_NET_CTRL0_L3_EDRAM_ENABLE                        , 27  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_L3_EDRAM_ENABLE );
REG64_FLD( PERV_1_NET_CTRL0_HTB_INTEST                             , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_INTEST );
REG64_FLD( PERV_1_NET_CTRL0_HTB_EXTEST                             , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_EXTEST );

REG64_FLD( PERV_1_NET_CTRL1_PLL_CLKIN_SEL                          , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_CLKIN_SEL );
REG64_FLD( PERV_1_NET_CTRL1_CLK_DIV_BYPASS_EN                      , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_DIV_BYPASS_EN );
REG64_FLD( PERV_1_NET_CTRL1_CLK_PDLY_BYPASS_EN                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PDLY_BYPASS_EN );
REG64_FLD( PERV_1_NET_CTRL1_SB_STRENGTH                            , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH );
REG64_FLD( PERV_1_NET_CTRL1_SB_STRENGTH_LEN                        , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH_LEN );
REG64_FLD( PERV_1_NET_CTRL1_CLK_PULSE_EN                           , 25  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_EN );
REG64_FLD( PERV_1_NET_CTRL1_CLK_PULSE_MODE                         , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE );
REG64_FLD( PERV_1_NET_CTRL1_CLK_PULSE_MODE_LEN                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE_LEN );
REG64_FLD( PERV_1_NET_CTRL1_RESCLK_DIS                             , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_RESCLK_DIS );
REG64_FLD( PERV_1_NET_CTRL1_CPM_CAL_SET                            , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM2_WOR,
           SH_FLD_CPM_CAL_SET );

REG64_FLD( PERV_1_OPCG_ALIGN_INOP                                  , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INOP       );
REG64_FLD( PERV_1_OPCG_ALIGN_INOP_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INOP_LEN   );
REG64_FLD( PERV_1_OPCG_ALIGN_SNOP                                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SNOP       );
REG64_FLD( PERV_1_OPCG_ALIGN_SNOP_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SNOP_LEN   );
REG64_FLD( PERV_1_OPCG_ALIGN_ENOP                                  , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENOP       );
REG64_FLD( PERV_1_OPCG_ALIGN_ENOP_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENOP_LEN   );
REG64_FLD( PERV_1_OPCG_ALIGN_INOP_WAIT                             , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT  );
REG64_FLD( PERV_1_OPCG_ALIGN_INOP_WAIT_LEN                         , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT_LEN );
REG64_FLD( PERV_1_OPCG_ALIGN_SNOP_WAIT                             , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT  );
REG64_FLD( PERV_1_OPCG_ALIGN_SNOP_WAIT_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT_LEN );
REG64_FLD( PERV_1_OPCG_ALIGN_ENOP_WAIT                             , 32  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT  );
REG64_FLD( PERV_1_OPCG_ALIGN_ENOP_WAIT_LEN                         , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT_LEN );
REG64_FLD( PERV_1_OPCG_ALIGN_INOP_FORCE_SG                         , 40  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INOP_FORCE_SG );
REG64_FLD( PERV_1_OPCG_ALIGN_SNOP_FORCE_SG                         , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SNOP_FORCE_SG );
REG64_FLD( PERV_1_OPCG_ALIGN_ENOP_FORCE_SG                         , 42  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ENOP_FORCE_SG );
REG64_FLD( PERV_1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD                    , 43  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_NO_WAIT_ON_CLK_CMD );
REG64_FLD( PERV_1_OPCG_ALIGN_SOURCE_SELECT                         , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT );
REG64_FLD( PERV_1_OPCG_ALIGN_SOURCE_SELECT_LEN                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT_LEN );
REG64_FLD( PERV_1_OPCG_ALIGN_UNUSED46                              , 46  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED46   );
REG64_FLD( PERV_1_OPCG_ALIGN_SCAN_RATIO                            , 47  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO );
REG64_FLD( PERV_1_OPCG_ALIGN_SCAN_RATIO_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO_LEN );
REG64_FLD( PERV_1_OPCG_ALIGN_WAIT_CYCLES                           , 52  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( PERV_1_OPCG_ALIGN_WAIT_CYCLES_LEN                       , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( PERV_1_OPCG_CAPT1_COUNT                                 , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_COUNT      );
REG64_FLD( PERV_1_OPCG_CAPT1_COUNT_LEN                             , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_COUNT_LEN  );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_01                                , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_01_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_02                                , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_02_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_03                                , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_03_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_04                                , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_04_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_05                                , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_05_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_06                                , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_06_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_07                                , 34  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_07_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_08                                , 39  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_08_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_09                                , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_09_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_10                                , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_10_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_11                                , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_11_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11_LEN );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_12                                , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12     );
REG64_FLD( PERV_1_OPCG_CAPT1_SEQ_12_LEN                            , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12_LEN );

REG64_FLD( PERV_1_OPCG_CAPT2_UNUSED                                , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( PERV_1_OPCG_CAPT2_UNUSED_LEN                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_13_01EVEN                         , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_13_01EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_14_01ODD                          , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_14_01ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_15_02EVEN                         , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_15_02EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_16_02ODD                          , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_16_02ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_17_03EVEN                         , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_17_03EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_18_03ODD                          , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_18_03ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_19_04EVEN                         , 34  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_19_04EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_20_04ODD                          , 39  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_20_04ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_21_05EVEN                         , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_21_05EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_22_05ODD                          , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_22_05ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_23_06EVEN                         , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_23_06EVEN_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_24_06ODD                          , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD );
REG64_FLD( PERV_1_OPCG_CAPT2_SEQ_24_06ODD_LEN                      , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD_LEN );

REG64_FLD( PERV_1_OPCG_CAPT3_UNUSED                                , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( PERV_1_OPCG_CAPT3_UNUSED_LEN                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_07EVEN                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_07EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_07ODD                             , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_07ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_08EVEN                            , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_08EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_08ODD                             , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_08ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_09EVEN                            , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_09EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_09ODD                             , 29  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_09ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_10EVEN                            , 34  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_10EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_10ODD                             , 39  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_10ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_11EVEN                            , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_11EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_11ODD                             , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_11ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_12EVEN                            , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_12EVEN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN_LEN );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_12ODD                             , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD  );
REG64_FLD( PERV_1_OPCG_CAPT3_SEQ_12ODD_LEN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD_LEN );

REG64_FLD( PERV_1_OPCG_REG0_RUNN_MODE                              , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUNN_MODE  );
REG64_FLD( PERV_1_OPCG_REG0_GO                                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GO         );
REG64_FLD( PERV_1_OPCG_REG0_RUN_SCAN0                              , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUN_SCAN0  );
REG64_FLD( PERV_1_OPCG_REG0_SCAN0_MODE                             , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN0_MODE );
REG64_FLD( PERV_1_OPCG_REG0_IN_SLAVE_MODE                          , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_SLAVE_MODE );
REG64_FLD( PERV_1_OPCG_REG0_IN_MASTER_MODE                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_MASTER_MODE );
REG64_FLD( PERV_1_OPCG_REG0_KEEP_MS_MODE                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_KEEP_MS_MODE );
REG64_FLD( PERV_1_OPCG_REG0_UNUSED78                               , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78   );
REG64_FLD( PERV_1_OPCG_REG0_UNUSED78_LEN                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78_LEN );
REG64_FLD( PERV_1_OPCG_REG0_RUN_CHIPLET_SCAN0                      , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0 );
REG64_FLD( PERV_1_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL               , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0_NO_PLL );
REG64_FLD( PERV_1_OPCG_REG0_RUN_ON_UPDATE_DR                       , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_UPDATE_DR );
REG64_FLD( PERV_1_OPCG_REG0_RUN_ON_CAPTURE_DR                      , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_CAPTURE_DR );
REG64_FLD( PERV_1_OPCG_REG0_STOP_RUNN_ON_XSTOP                     , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STOP_RUNN_ON_XSTOP );
REG64_FLD( PERV_1_OPCG_REG0_STARTS_BIST                            , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );
REG64_FLD( PERV_1_OPCG_REG0_UNUSED1520                             , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520 );
REG64_FLD( PERV_1_OPCG_REG0_UNUSED1520_LEN                         , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520_LEN );
REG64_FLD( PERV_1_OPCG_REG0_LOOP_COUNT                             , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT );
REG64_FLD( PERV_1_OPCG_REG0_LOOP_COUNT_LEN                         , 43  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT_LEN );

REG64_FLD( PERV_1_OPCG_REG1_SCAN_COUNT                             , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT );
REG64_FLD( PERV_1_OPCG_REG1_SCAN_COUNT_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT_LEN );
REG64_FLD( PERV_1_OPCG_REG1_MISR_A_VAL                             , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL );
REG64_FLD( PERV_1_OPCG_REG1_MISR_A_VAL_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL_LEN );
REG64_FLD( PERV_1_OPCG_REG1_MISR_B_VAL                             , 24  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL );
REG64_FLD( PERV_1_OPCG_REG1_MISR_B_VAL_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL_LEN );
REG64_FLD( PERV_1_OPCG_REG1_MISR_INIT_WAIT                         , 36  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT );
REG64_FLD( PERV_1_OPCG_REG1_MISR_INIT_WAIT_LEN                     , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT_LEN );
REG64_FLD( PERV_1_OPCG_REG1_SUPPRESS_EVEN_CLK                      , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS_EVEN_CLK );
REG64_FLD( PERV_1_OPCG_REG1_SCAN_CLK_USE_EVEN                      , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SCAN_CLK_USE_EVEN );
REG64_FLD( PERV_1_OPCG_REG1_UNUSED2                                , 50  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2    );
REG64_FLD( PERV_1_OPCG_REG1_UNUSED2_LEN                            , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2_LEN );
REG64_FLD( PERV_1_OPCG_REG1_USE_ARY_CLK_DURING_FILL                , 53  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_USE_ARY_CLK_DURING_FILL );
REG64_FLD( PERV_1_OPCG_REG1_SG_HIGH_DURING_FILL                    , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SG_HIGH_DURING_FILL );
REG64_FLD( PERV_1_OPCG_REG1_RTIM_THOLD_FORCE                       , 55  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RTIM_THOLD_FORCE );
REG64_FLD( PERV_1_OPCG_REG1_LBIST_SKITTER_CTL                      , 56  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LBIST_SKITTER_CTL );
REG64_FLD( PERV_1_OPCG_REG1_MISR_MODE                              , 57  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MISR_MODE  );
REG64_FLD( PERV_1_OPCG_REG1_INFINITE_MODE                          , 58  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INFINITE_MODE );
REG64_FLD( PERV_1_OPCG_REG1_NSL_FILL_COUNT                         , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT );
REG64_FLD( PERV_1_OPCG_REG1_NSL_FILL_COUNT_LEN                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT_LEN );

REG64_FLD( PERV_1_OPCG_REG2_GO2                                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GO2        );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_WEIGHTING                         , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_WEIGHTING_LEN                     , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING_LEN );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_VALUE                             , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_VALUE_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE_LEN );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_A_VAL                             , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_A_VAL_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL_LEN );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_B_VAL                             , 28  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_B_VAL_LEN                         , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL_LEN );
REG64_FLD( PERV_1_OPCG_REG2_PRPG_MODE                              , 40  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PRPG_MODE  );
REG64_FLD( PERV_1_OPCG_REG2_UNUSED41_63                            , 41  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63 );
REG64_FLD( PERV_1_OPCG_REG2_UNUSED41_63_LEN                        , 23  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63_LEN );

REG64_FLD( PERV_1_OSCERR_HOLD_CP                                   , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CP         );
REG64_FLD( PERV_1_OSCERR_HOLD_CP_LEN                               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CP_LEN     );
REG64_FLD( PERV_1_OSCERR_HOLD_MEM                                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( PERV_1_OSCERR_HOLD_MEM_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( PERV_1_OSCERR_HOLD_GX                                   , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GX         );
REG64_FLD( PERV_1_OSCERR_HOLD_GX_LEN                               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GX_LEN     );
REG64_FLD( PERV_1_OSCERR_HOLD_CPLITE                               , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLITE     );
REG64_FLD( PERV_1_OSCERR_HOLD_CPLITE_LEN                           , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLITE_LEN );

REG64_FLD( PERV_1_OSCERR_MASK_CP                                   , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CP         );
REG64_FLD( PERV_1_OSCERR_MASK_CP_LEN                               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CP_LEN     );
REG64_FLD( PERV_1_OSCERR_MASK_MEM                                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( PERV_1_OSCERR_MASK_MEM_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( PERV_1_OSCERR_MASK_GX                                   , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GX         );
REG64_FLD( PERV_1_OSCERR_MASK_GX_LEN                               , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_GX_LEN     );
REG64_FLD( PERV_1_OSCERR_MASK_CPLITE                               , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLITE     );
REG64_FLD( PERV_1_OSCERR_MASK_CPLITE_LEN                           , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CPLITE_LEN );

REG64_FLD( PERV_1_OSCERR_MCODE_IN                                  , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( PERV_1_OSCERR_MCODE_IN_LEN                              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( PERV_PB_PSAVE_CFG_ENABLE                                , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( PERV_PB_PSAVE_CFG_X0_ACT                                , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_X0_ACT     );
REG64_FLD( PERV_PB_PSAVE_CFG_X1_ACT                                , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_X1_ACT     );
REG64_FLD( PERV_PB_PSAVE_CFG_X2_ACT                                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_X2_ACT     );
REG64_FLD( PERV_PB_PSAVE_CFG_PS_SPARE1                             , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PS_SPARE1  );
REG64_FLD( PERV_PB_PSAVE_CFG_WSIZE                                 , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_WSIZE      );
REG64_FLD( PERV_PB_PSAVE_CFG_WSIZE_LEN                             , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_WSIZE_LEN  );
REG64_FLD( PERV_PB_PSAVE_CFG_LUC                                   , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LUC        );
REG64_FLD( PERV_PB_PSAVE_CFG_LUC_LEN                               , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LUC_LEN    );
REG64_FLD( PERV_PB_PSAVE_CFG_HUC                                   , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HUC        );
REG64_FLD( PERV_PB_PSAVE_CFG_HUC_LEN                               , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HUC_LEN    );
REG64_FLD( PERV_PB_PSAVE_CFG_LUT                                   , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LUT        );
REG64_FLD( PERV_PB_PSAVE_CFG_LUT_LEN                               , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LUT_LEN    );
REG64_FLD( PERV_PB_PSAVE_CFG_HUT                                   , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HUT        );
REG64_FLD( PERV_PB_PSAVE_CFG_HUT_LEN                               , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_HUT_LEN    );

REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_ACTUAL_ERROR                   , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_ACTUAL_ERROR );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_ACTUAL_ERROR_LEN               , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_0_ENABLE                  , 8   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_0_ENABLE );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_1_ENABLE                  , 12  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_1_ENABLE );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_2_ENABLE                  , 16  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_2_ENABLE );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_3_ENABLE                  , 20  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_3_ENABLE );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_4_ENABLE                  , 24  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_4_ENABLE );
REG32_FLD( PERV_PEEK4A0_FSI_A_MST_0_PORT_5_ENABLE                  , 28  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_5_ENABLE );

REG32_FLD( PERV_PEEK4A4_FSI_A_MST_0_PORT_6_ENABLE                  , 0   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_6_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_0_PORT_7_ENABLE                  , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_0_PORT_7_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_ACTUAL_ERROR                   , 8   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_ACTUAL_ERROR );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_ACTUAL_ERROR_LEN               , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_PORT_0_ENABLE                  , 12  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_PORT_0_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_PORT_1_ENABLE                  , 16  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_PORT_1_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_PORT_2_ENABLE                  , 20  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_PORT_2_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_PORT_3_ENABLE                  , 24  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_PORT_3_ENABLE );
REG32_FLD( PERV_PEEK4A4_FSI_A_MST_1_PORT_4_ENABLE                  , 28  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_A_MST_1_PORT_4_ENABLE );

REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_ACTUAL_ERROR                   , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_ACTUAL_ERROR );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_ACTUAL_ERROR_LEN               , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_ACTUAL_ERROR_LEN );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_0_ENABLE                  , 8   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_0_ENABLE );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_1_ENABLE                  , 12  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_1_ENABLE );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_2_ENABLE                  , 16  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_2_ENABLE );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_3_ENABLE                  , 20  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_3_ENABLE );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_4_ENABLE                  , 24  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_4_ENABLE );
REG32_FLD( PERV_PEEK4A8_FSI_B_MST_0_PORT_5_ENABLE                  , 28  , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_5_ENABLE );

REG32_FLD( PERV_PEEK4AC_FSI_B_MST_0_PORT_6_ENABLE                  , 0   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_6_ENABLE );
REG32_FLD( PERV_PEEK4AC_FSI_B_MST_0_PORT_7_ENABLE                  , 4   , SH_UNT_PERV     , SH_ACS_FSI      ,
           SH_FLD_FSI_B_MST_0_PORT_7_ENABLE );

REG64_FLD( PERV_PERV_CTRL0_TP_CHIPLET_EN_DC                        , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CHIPLET_EN_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_PCB_EP_RESET_DC                      , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PCB_EP_RESET_DC );
REG64_FLD( PERV_PERV_CTRL0_2_RESERVED                              , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_2_RESERVED );
REG64_FLD( PERV_PERV_CTRL0_TP_PLL_TEST_EN_DC                       , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_TEST_EN_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_PLLRST_DC                            , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLLRST_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_PLLBYP_DC                            , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLLBYP_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_SCAN_CLK_DC                     , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_SCAN_CLK_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_SCIN_DC                         , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_SCIN_DC );
REG64_FLD( PERV_PERV_CTRL0_8_RESERVED                              , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_8_RESERVED );
REG64_FLD( PERV_PERV_CTRL0_TP_FLUSH_ALIGN_OVERWRITE                , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FLUSH_ALIGN_OVERWRITE );
REG64_FLD( PERV_PERV_CTRL0_TP_ARRAY_WRITE_ASSIST_EN_DC             , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_ARRAY_WRITE_ASSIST_EN_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_ACT_DIS_DC                      , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_ACT_DIS_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_MPW1_DC_N                       , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_MPW1_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_MPW2_DC_N                       , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_MPW2_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_MPW3_DC_N                       , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_MPW3_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_DELAY_LCLKR_DC                  , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_DELAY_LCLKR_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_VITL_CLKOFF_DC                       , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_VITL_CLKOFF_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_FLUSH_SCAN_DC_N                      , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FLUSH_SCAN_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_FENCE_EN_DC                          , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FENCE_EN_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_RI_DC_N                              , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_RI_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_DI1_DC_N                             , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_DI1_DC_N );
REG64_FLD( PERV_PERV_CTRL0_TP_DI2_DC_N                             , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_DI2_DC_N );
REG64_FLD( PERV_PERV_CTRL0_22_RESERVED                             , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_RESERVED );
REG64_FLD( PERV_PERV_CTRL0_23_RESERVED                             , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_RESERVED );
REG64_FLD( PERV_PERV_CTRL0_24_RESERVED                             , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_RESERVED );
REG64_FLD( PERV_PERV_CTRL0_TP_FENCE_PCB_DC                         , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FENCE_PCB_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_LVLTRANS_FENCE_DC                    , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_LVLTRANS_FENCE_DC );
REG64_FLD( PERV_PERV_CTRL0_TP_EDRAM_ENABLE_DC                      , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_EDRAM_ENABLE_DC );
REG64_FLD( PERV_PERV_CTRL0_28_RESERVED_FOR_HTB                     , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_RESERVED_FOR_HTB );
REG64_FLD( PERV_PERV_CTRL0_29_RESERVED_FOR_HTB                     , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_RESERVED_FOR_HTB );
REG64_FLD( PERV_PERV_CTRL0_30_RESERVED_FOR_HTB                     , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_RESERVED_FOR_HTB );
REG64_FLD( PERV_PERV_CTRL0_31_RESERVED_FOR_HTB                     , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_RESERVED_FOR_HTB );

REG64_FLD( PERV_PERV_CTRL1_UNUSED1                                 , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1    );
REG64_FLD( PERV_PERV_CTRL1_UNUSED2                                 , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2    );
REG64_FLD( PERV_PERV_CTRL1_UNUSED3                                 , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_UNUSED3    );
REG64_FLD( PERV_PERV_CTRL1_3_RESERVED                              , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_3_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_4_RESERVED                              , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_4_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_5_RESERVED                              , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_5_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_6_RESERVED                              , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_6_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_7_RESERVED                              , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_7_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_8_RESERVED                              , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_8_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_9_RESERVED                              , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_9_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_10_RESERVED                             , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_10_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_11_RESERVED                             , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_11_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_12_RESERVED                             , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_12_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_13_RESERVED                             , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_13_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_14_RESERVED                             , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_14_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_15_RESERVED                             , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC              , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_SEC_BUF_DRV_STRENGTH_DC );
REG64_FLD( PERV_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN          , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_SEC_BUF_DRV_STRENGTH_DC_LEN );
REG64_FLD( PERV_PERV_CTRL1_20_RESERVED                             , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_20_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_21_RESERVED                             , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_21_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_22_RESERVED                             , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_23_RESERVED                             , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_24_RESERVED                             , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_TP_CLK_PULSE_ENABLE_DC                  , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_PULSE_ENABLE_DC );
REG64_FLD( PERV_PERV_CTRL1_TP_CLK_PULSE_MODE_DC                    , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_PULSE_MODE_DC );
REG64_FLD( PERV_PERV_CTRL1_TP_CLK_PULSE_MODE_DC_LEN                , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_PULSE_MODE_DC_LEN );
REG64_FLD( PERV_PERV_CTRL1_TP_RESCLK_DIS_DC                        , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_RESCLK_DIS_DC );
REG64_FLD( PERV_PERV_CTRL1_TP_CPM_CAL_SET                          , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CPM_CAL_SET );
REG64_FLD( PERV_PERV_CTRL1_30_RESERVED                             , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_RESERVED );
REG64_FLD( PERV_PERV_CTRL1_TP_PCB_PM_MUX_SEL_DC                    , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PCB_PM_MUX_SEL_DC );

REG64_FLD( PERV_PPE_XIDBGPRO_NULL_MSR_SIBRC                        , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( PERV_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN                    , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( PERV_PPE_XIDBGPRO_NULL_MSR_WE                           , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( PERV_PPE_XIDBGPRO_NULL_MSR_LP                           , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );

REG64_FLD( PERV_PPE_XIRAMDBG_NULL_MSR_SIBRC                        , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( PERV_PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN                    , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( PERV_PPE_XIRAMDBG_NULL_MSR_WE                           , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( PERV_PPE_XIRAMDBG_NULL_MSR_LP                           , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );
REG64_FLD( PERV_PPE_XIRAMDBG_XIRAMRA_SPRG0                         , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( PERV_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN                     , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( PERV_PPE_XIRAMEDR_XIRAMGA_IR                            , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR );
REG64_FLD( PERV_PPE_XIRAMEDR_XIRAMGA_IR_LEN                        , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR_LEN );
REG64_FLD( PERV_PPE_XIRAMEDR_EDR                                   , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_EDR        );
REG64_FLD( PERV_PPE_XIRAMEDR_EDR_LEN                               , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_EDR_LEN    );

REG64_FLD( PERV_PPE_XIRAMGA_IR                                     , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_IR         );
REG64_FLD( PERV_PPE_XIRAMGA_IR_LEN                                 , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_IR_LEN     );
REG64_FLD( PERV_PPE_XIRAMGA_XIRAMRA_SPRG0                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( PERV_PPE_XIRAMGA_XIRAMRA_SPRG0_LEN                      , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( PERV_PPE_XIRAMRA_XIXCR_XCR                              , 1   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR  );
REG64_FLD( PERV_PPE_XIRAMRA_XIXCR_XCR_LEN                          , 3   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR_LEN );
REG64_FLD( PERV_PPE_XIRAMRA_SPRG0                                  , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0      );
REG64_FLD( PERV_PPE_XIRAMRA_SPRG0_LEN                              , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0_LEN  );

REG64_FLD( PERV_PPE_XIXCR_XCR                                      , 1   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR        );
REG64_FLD( PERV_PPE_XIXCR_XCR_LEN                                  , 3   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR_LEN    );

REG64_FLD( PERV_1_PRE_COUNTER_REG_COUNTER                          , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_COUNTER    );
REG64_FLD( PERV_1_PRE_COUNTER_REG_COUNTER_LEN                      , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_COUNTER_LEN );

REG64_FLD( PERV_1_PROTECT_MODE_REG_READ_ENABLE                     , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( PERV_1_PROTECT_MODE_REG_WRITE_ENABLE                    , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( PERV_PRV_DBG_PIB_RESET                                  , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_PIB_RESET  );
REG64_FLD( PERV_PRV_DBG_RESERVED_15                                , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_15 );
REG64_FLD( PERV_PRV_DBG_RESERVED_16                                , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_16 );
REG64_FLD( PERV_PRV_DBG_RESERVED_16_LEN                            , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_16_LEN );
REG64_FLD( PERV_PRV_DBG_RESERVED_17                                , 6   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_17 );
REG64_FLD( PERV_PRV_DBG_RESERVED_17_LEN                            , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_RESERVED_17_LEN );

REG32_FLD( PERV_FSISHIFT_READ_BUFFER_REG                           , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_READ_BUFFER_REG_LEN                       , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG64_FLD( PERV_REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RECEIVE_ACKNOWLEDGE_REGISTER );
REG64_FLD( PERV_REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER_LEN       , 64  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RECEIVE_ACKNOWLEDGE_REGISTER_LEN );

REG64_FLD( PERV_REC_ERR_REG0_MASTER_RESPONSE_BIT                   , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MASTER_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_MASTER_ERROR_CODE                     , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MASTER_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_MASTER_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MASTER_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE1_RESPONSE_BIT                   , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE1_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE1_ERROR_CODE                     , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE1_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE1_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE2_RESPONSE_BIT                   , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE2_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE2_ERROR_CODE                     , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE2_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE2_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE3_RESPONSE_BIT                   , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE3_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE3_ERROR_CODE                     , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE3_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE3_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE4_RESPONSE_BIT                   , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE4_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE4_ERROR_CODE                     , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE4_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE4_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE5_RESPONSE_BIT                   , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE5_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE5_ERROR_CODE                     , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE5_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE5_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE6_RESPONSE_BIT                   , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE6_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE6_ERROR_CODE                     , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE6_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE6_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE7_RESPONSE_BIT                   , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE7_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE7_ERROR_CODE                     , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE7_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE7_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE8_RESPONSE_BIT                   , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE8_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE8_ERROR_CODE                     , 33  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE8_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE8_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE9_RESPONSE_BIT                   , 36  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE9_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE9_ERROR_CODE                     , 37  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE9_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE9_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE10_RESPONSE_BIT                  , 40  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE10_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE10_ERROR_CODE                    , 41  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE10_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE10_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE11_RESPONSE_BIT                  , 44  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE11_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE11_ERROR_CODE                    , 45  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE11_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE11_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE12_RESPONSE_BIT                  , 48  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE12_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE12_ERROR_CODE                    , 49  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE12_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE12_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE13_RESPONSE_BIT                  , 52  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE13_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE13_ERROR_CODE                    , 53  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE13_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE13_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE14_RESPONSE_BIT                  , 56  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE14_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE14_ERROR_CODE                    , 57  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE14_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE14_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE15_RESPONSE_BIT                  , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE15_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE15_ERROR_CODE                    , 61  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE15_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE15_ERROR_CODE_LEN );

REG64_FLD( PERV_REC_ERR_REG1_SLAVE16_RESPONSE_BIT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE16_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE16_ERROR_CODE                    , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE16_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE16_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE16_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE17_RESPONSE_BIT                  , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE17_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE17_ERROR_CODE                    , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE17_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE17_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE17_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE18_RESPONSE_BIT                  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE18_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE18_ERROR_CODE                    , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE18_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE18_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE18_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE19_RESPONSE_BIT                  , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE19_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE19_ERROR_CODE                    , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE19_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE19_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE19_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE20_RESPONSE_BIT                  , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE20_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE20_ERROR_CODE                    , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE20_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE20_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE20_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE21_RESPONSE_BIT                  , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE21_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE21_ERROR_CODE                    , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE21_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE21_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE21_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE22_RESPONSE_BIT                  , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE22_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE22_ERROR_CODE                    , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE22_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE22_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE22_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE23_RESPONSE_BIT                  , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE23_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE23_ERROR_CODE                    , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE23_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE23_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE23_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE24_RESPONSE_BIT                  , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE24_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE24_ERROR_CODE                    , 33  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE24_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE24_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE24_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE25_RESPONSE_BIT                  , 36  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE25_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE25_ERROR_CODE                    , 37  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE25_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE25_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE25_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE26_RESPONSE_BIT                  , 40  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE26_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE26_ERROR_CODE                    , 41  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE26_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE26_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE26_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE27_RESPONSE_BIT                  , 44  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE27_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE27_ERROR_CODE                    , 45  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE27_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE27_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE27_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE28_RESPONSE_BIT                  , 48  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE28_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE28_ERROR_CODE                    , 49  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE28_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE28_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE28_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE29_RESPONSE_BIT                  , 52  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE29_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE29_ERROR_CODE                    , 53  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE29_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE29_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE29_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE30_RESPONSE_BIT                  , 56  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE30_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE30_ERROR_CODE                    , 57  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE30_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE30_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE30_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE31_RESPONSE_BIT                  , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE31_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE31_ERROR_CODE                    , 61  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE31_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG1_SLAVE31_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE31_ERROR_CODE_LEN );

REG64_FLD( PERV_REC_ERR_REG2_SLAVE32_RESPONSE_BIT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE32_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE32_ERROR_CODE                    , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE32_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE32_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE32_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE33_RESPONSE_BIT                  , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE33_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE33_ERROR_CODE                    , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE33_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE33_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE33_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE34_RESPONSE_BIT                  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE34_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE34_ERROR_CODE                    , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE34_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE34_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE34_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE35_RESPONSE_BIT                  , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE35_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE35_ERROR_CODE                    , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE35_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE35_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE35_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE36_RESPONSE_BIT                  , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE36_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE36_ERROR_CODE                    , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE36_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE36_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE36_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE37_RESPONSE_BIT                  , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE37_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE37_ERROR_CODE                    , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE37_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE37_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE37_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE38_RESPONSE_BIT                  , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE38_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE38_ERROR_CODE                    , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE38_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE38_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE38_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE39_RESPONSE_BIT                  , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE39_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE39_ERROR_CODE                    , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE39_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE39_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE39_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE40_RESPONSE_BIT                  , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE40_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE40_ERROR_CODE                    , 33  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE40_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE40_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE40_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE41_RESPONSE_BIT                  , 36  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE41_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE41_ERROR_CODE                    , 37  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE41_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE41_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE41_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE42_RESPONSE_BIT                  , 40  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE42_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE42_ERROR_CODE                    , 41  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE42_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE42_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE42_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE43_RESPONSE_BIT                  , 44  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE43_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE43_ERROR_CODE                    , 45  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE43_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE43_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE43_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE44_RESPONSE_BIT                  , 48  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE44_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE44_ERROR_CODE                    , 49  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE44_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE44_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE44_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE45_RESPONSE_BIT                  , 52  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE45_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE45_ERROR_CODE                    , 53  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE45_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE45_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE45_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE46_RESPONSE_BIT                  , 56  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE46_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE46_ERROR_CODE                    , 57  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE46_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE46_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE46_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE47_RESPONSE_BIT                  , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE47_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE47_ERROR_CODE                    , 61  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE47_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG2_SLAVE47_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE47_ERROR_CODE_LEN );

REG64_FLD( PERV_REC_ERR_REG3_SLAVE48_RESPONSE_BIT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE48_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE48_ERROR_CODE                    , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE48_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE48_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE48_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE49_RESPONSE_BIT                  , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE49_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE49_ERROR_CODE                    , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE49_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE49_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE49_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE50_RESPONSE_BIT                  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE50_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE50_ERROR_CODE                    , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE50_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE50_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE50_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE51_RESPONSE_BIT                  , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE51_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE51_ERROR_CODE                    , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE51_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE51_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE51_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE52_RESPONSE_BIT                  , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE52_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE52_ERROR_CODE                    , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE52_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE52_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE52_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE53_RESPONSE_BIT                  , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE53_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE53_ERROR_CODE                    , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE53_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE53_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE53_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE54_RESPONSE_BIT                  , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE54_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE54_ERROR_CODE                    , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE54_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE54_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE54_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE55_RESPONSE_BIT                  , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE55_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE55_ERROR_CODE                    , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE55_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE55_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE55_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE56_RESPONSE_BIT                  , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE56_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE56_ERROR_CODE                    , 33  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE56_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE56_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE56_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE57_RESPONSE_BIT                  , 36  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE57_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE57_ERROR_CODE                    , 37  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE57_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE57_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE57_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE58_RESPONSE_BIT                  , 40  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE58_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE58_ERROR_CODE                    , 41  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE58_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE58_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE58_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE59_RESPONSE_BIT                  , 44  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE59_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE59_ERROR_CODE                    , 45  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE59_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE59_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE59_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE60_RESPONSE_BIT                  , 48  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE60_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE60_ERROR_CODE                    , 49  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE60_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE60_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE60_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE61_RESPONSE_BIT                  , 52  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE61_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE61_ERROR_CODE                    , 53  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE61_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE61_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE61_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE62_RESPONSE_BIT                  , 56  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE62_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE62_ERROR_CODE                    , 57  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE62_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE62_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE62_ERROR_CODE_LEN );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE63_RESPONSE_BIT                  , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE63_RESPONSE_BIT );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE63_ERROR_CODE                    , 61  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE63_ERROR_CODE );
REG64_FLD( PERV_REC_ERR_REG3_SLAVE63_ERROR_CODE_LEN                , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SLAVE63_ERROR_CODE_LEN );

REG64_FLD( PERV_RESET_REG_PCB                                      , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PCB        );
REG64_FLD( PERV_RESET_REG_ENDPOINTS                                , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_ENDPOINTS  );
REG64_FLD( PERV_RESET_REG_TIMEOUT_EN                               , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_EN );

REG64_FLD( PERV_1_RFIR_IN0                                         , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_RFIR_LFIR_RECOV_ERR                              , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LFIR_RECOV_ERR );
REG64_FLD( PERV_1_RFIR_IN4                                         , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_RFIR_IN5                                         , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_RFIR_IN6                                         , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_RFIR_IN7                                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_RFIR_IN8                                         , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_RFIR_IN9                                         , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( PERV_1_RFIR_IN10                                        , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( PERV_1_RFIR_IN11                                        , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( PERV_1_RFIR_IN12                                        , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN12       );
REG64_FLD( PERV_1_RFIR_IN13                                        , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN13       );
REG64_FLD( PERV_1_RFIR_IN14                                        , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN14       );
REG64_FLD( PERV_1_RFIR_IN15                                        , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN15       );
REG64_FLD( PERV_1_RFIR_IN16                                        , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN16       );
REG64_FLD( PERV_1_RFIR_IN17                                        , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN17       );
REG64_FLD( PERV_1_RFIR_IN18                                        , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN18       );
REG64_FLD( PERV_1_RFIR_IN19                                        , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN19       );
REG64_FLD( PERV_1_RFIR_IN20                                        , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN20       );
REG64_FLD( PERV_1_RFIR_IN21                                        , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21       );
REG64_FLD( PERV_1_RFIR_IN21_LEN                                    , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21_LEN   );

REG64_FLD( PERV_ROOT_CTRL0_TPFSI_SBE_FENCE_VTLIO_DC                , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_SBE_FENCE_VTLIO_DC );
REG64_FLD( PERV_ROOT_CTRL0_TPFSI_TP_FENCE_VTLIO_DC                 , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_FENCE_VTLIO_DC );
REG64_FLD( PERV_ROOT_CTRL0_TPFSI_TPI2C_BUS_FENCE_DC                , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TPI2C_BUS_FENCE_DC );
REG64_FLD( PERV_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPCFSI_OPB_SW0_FENCE_DC );
REG64_FLD( PERV_ROOT_CTRL0_TPCFSI_OPB_SW0_FENCE_DC_LEN             , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPCFSI_OPB_SW0_FENCE_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC                 , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPCFSI_OPB_SW1_FENCE_DC );
REG64_FLD( PERV_ROOT_CTRL0_TPCFSI_OPB_SW1_FENCE_DC_LEN             , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPCFSI_OPB_SW1_FENCE_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL0_FENCE1_DC                               , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE1_DC  );
REG64_FLD( PERV_ROOT_CTRL0_FENCE2_DC                               , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE2_DC  );
REG64_FLD( PERV_ROOT_CTRL0_FENCE3_DC                               , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE3_DC  );
REG64_FLD( PERV_ROOT_CTRL0_FENCE4_DC                               , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE4_DC  );
REG64_FLD( PERV_ROOT_CTRL0_FENCE5_DC                               , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE5_DC  );
REG64_FLD( PERV_ROOT_CTRL0_FENCE6_DC                               , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FENCE6_DC  );
REG64_FLD( PERV_ROOT_CTRL0_SPARE_FENCE_CONTROL                     , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SPARE_FENCE_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_VDD2VIO_LVL_FENCE_DC                    , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_VDD2VIO_LVL_FENCE_DC );
REG64_FLD( PERV_ROOT_CTRL0_PIB2PCB_DC                              , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB2PCB_DC );
REG64_FLD( PERV_ROOT_CTRL0_OOB_MUX                                 , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OOB_MUX    );
REG64_FLD( PERV_ROOT_CTRL0_18_SPARE_MUX_CONTROL                    , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_18_SPARE_MUX_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_19_SPARE_MUX_CONTROL                    , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_19_SPARE_MUX_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_REQ                      , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FSI_CC_VSB_CBS_REQ );
REG64_FLD( PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD                      , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FSI_CC_VSB_CBS_CMD );
REG64_FLD( PERV_ROOT_CTRL0_FSI_CC_VSB_CBS_CMD_LEN                  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FSI_CC_VSB_CBS_CMD_LEN );
REG64_FLD( PERV_ROOT_CTRL0_24_SPARE_CBS_CONTROL                    , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_SPARE_CBS_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_25_SPARE_CBS_CONTROL                    , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_SPARE_CBS_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_26_SPARE_CBS_CONTROL                    , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_SPARE_CBS_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_27_SPARE_CBS_CONTROL                    , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_27_SPARE_CBS_CONTROL );
REG64_FLD( PERV_ROOT_CTRL0_28_SPARE_RESET                          , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_SPARE_RESET );
REG64_FLD( PERV_ROOT_CTRL0_29_SPARE_RESET                          , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_SPARE_RESET );
REG64_FLD( PERV_ROOT_CTRL0_PCB_RESET_DC                            , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PCB_RESET_DC );
REG64_FLD( PERV_ROOT_CTRL0_GLOBAL_EP_RESET_DC                      , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GLOBAL_EP_RESET_DC );

REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE0_SEL_DC                        , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE0_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN                    , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE0_SEL_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE1_SEL_DC                        , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE1_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN                    , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE1_SEL_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE_MESH_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE_DRV_EN_DC                      , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE_DRV_EN_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_PROBE_HIGHDRIVE_DC                   , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PROBE_HIGHDRIVE_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC                     , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FSI_PROBE_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN                 , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FSI_PROBE_SEL_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL1_13_SPARE_PROBE                          , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_13_SPARE_PROBE );
REG64_FLD( PERV_ROOT_CTRL1_14_SPARE_PROBE                          , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_14_SPARE_PROBE );
REG64_FLD( PERV_ROOT_CTRL1_15_SPARE_PROBE                          , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_SPARE_PROBE );
REG64_FLD( PERV_ROOT_CTRL1_TP_IDDQ_DC                              , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_IDDQ_DC );
REG64_FLD( PERV_ROOT_CTRL1_SPARE_RI_CONTROL                        , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SPARE_RI_CONTROL );
REG64_FLD( PERV_ROOT_CTRL1_SPARE_DI_CONTROL                        , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SPARE_DI_CONTROL );
REG64_FLD( PERV_ROOT_CTRL1_TP_RI_DC_B                              , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_RI_DC_B );
REG64_FLD( PERV_ROOT_CTRL1_TP_DI1_DC_B                             , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_DI1_DC_B );
REG64_FLD( PERV_ROOT_CTRL1_TP_DI2_DC_B                             , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_DI2_DC_B );
REG64_FLD( PERV_ROOT_CTRL1_22_SPARE_TEST                           , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_SPARE_TEST );
REG64_FLD( PERV_ROOT_CTRL1_23_SPARE_TEST                           , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_SPARE_TEST );
REG64_FLD( PERV_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC                  , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_TEST_BURNIN_MODE_DC );
REG64_FLD( PERV_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC           , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_ARRAY_SET_VBL_TO_VDD_DC );
REG64_FLD( PERV_ROOT_CTRL1_TPFSI_TP_LOWFREQTEST_REFCLK_DC          , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_LOWFREQTEST_REFCLK_DC );
REG64_FLD( PERV_ROOT_CTRL1_TP_GLBCK_MEM_TESTCLK_SEL_DC             , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_MEM_TESTCLK_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL1_28_SPARE_TEST_CONTROL                   , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_SPARE_TEST_CONTROL );
REG64_FLD( PERV_ROOT_CTRL1_29_SPARE_TEST_CONTROL                   , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_SPARE_TEST_CONTROL );
REG64_FLD( PERV_ROOT_CTRL1_30_SPARE_TEST_CONTROL                   , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_SPARE_TEST_CONTROL );
REG64_FLD( PERV_ROOT_CTRL1_31_SPARE_TEST_CONTROL                   , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_SPARE_TEST_CONTROL );

REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_ASYNC_EN_DC        , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_VSB_DBG_PCB_ASYNC_EN_DC );
REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_DATA_PAR_DIS_DC    , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_VSB_DBG_PCB_DATA_PAR_DIS_DC );
REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_VSB_DBG_PCB_TYPE_PAR_DIS_DC    , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_VSB_DBG_PCB_TYPE_PAR_DIS_DC );
REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_VSB_PCB_GSD_LATCHED_MODE_DC    , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_VSB_PCB_GSD_LATCHED_MODE_DC );
REG64_FLD( PERV_ROOT_CTRL2_TP_PIB_VSB_DISABLE_PARITY_DC            , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PIB_VSB_DISABLE_PARITY_DC );
REG64_FLD( PERV_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC               , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PIB_TRACE_MODE_DATA_DC );
REG64_FLD( PERV_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE               , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PIB_VSB_SBE_TRACE_MODE );
REG64_FLD( PERV_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP               , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_TPCPERV_VSB_TRACE_STOP );
REG64_FLD( PERV_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT                     , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GPIO_PIB_TIMEOUT );
REG64_FLD( PERV_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GPIO_PIB_TIMEOUT_LEN );
REG64_FLD( PERV_ROOT_CTRL2_SPARE_PIB_CONTROL                       , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SPARE_PIB_CONTROL );
REG64_FLD( PERV_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC                  , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPCFSI_OPB_SW_RESET_DC );
REG64_FLD( PERV_ROOT_CTRL2_13_SPARE_OPB_CONTROL                    , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_13_SPARE_OPB_CONTROL );
REG64_FLD( PERV_ROOT_CTRL2_14_SPARE_OPB_CONTROL                    , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_14_SPARE_OPB_CONTROL );
REG64_FLD( PERV_ROOT_CTRL2_15_SPARE_OPB_CONTROL                    , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_SPARE_OPB_CONTROL );
REG64_FLD( PERV_ROOT_CTRL2_16_FREE_USAGE                           , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_16_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_TP_GLBCK_VSB_NEST_VREGDLY_SHUTOFF_DC    , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_VSB_NEST_VREGDLY_SHUTOFF_DC );
REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_PFET_FORCE_OFF_DC              , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_PFET_FORCE_OFF_DC );
REG64_FLD( PERV_ROOT_CTRL2_TPFSI_TP_PFET_OVERRIDE_ON_DC_N          , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_TP_PFET_OVERRIDE_ON_DC_N );
REG64_FLD( PERV_ROOT_CTRL2_20_FREE_USAGE                           , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_20_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_21_FREE_USAGE                           , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_21_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_22_FREE_USAGE                           , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_23_FREE_USAGE                           , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_24_FREE_USAGE                           , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_25_FREE_USAGE                           , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_26_FREE_USAGE                           , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_27_FREE_USAGE                           , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_27_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_28_FREE_USAGE                           , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_29_FREE_USAGE                           , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_30_FREE_USAGE                           , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_FREE_USAGE );
REG64_FLD( PERV_ROOT_CTRL2_31_FREE_USAGE                           , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_FREE_USAGE );

REG64_FLD( PERV_ROOT_CTRL3_OSCSWITCH_CNTL0_DC                      , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OSCSWITCH_CNTL0_DC );
REG64_FLD( PERV_ROOT_CTRL3_OSCSWITCH_CNTL0_DC_LEN                  , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OSCSWITCH_CNTL0_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_USEOSC_DC           , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_VSB_PCIESW_USEOSC_DC );
REG64_FLD( PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_USEOSC_DC_LEN       , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_VSB_PCIESW_USEOSC_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_TWEAK_DC            , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_VSB_PCIESW_TWEAK_DC );
REG64_FLD( PERV_ROOT_CTRL3_TP_GLBCK_VSB_PCIESW_TWEAK_DC_LEN        , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_GLBCK_VSB_PCIESW_TWEAK_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL3_OSCSWITCH_CNTL1_DC                      , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OSCSWITCH_CNTL1_DC );
REG64_FLD( PERV_ROOT_CTRL3_OSCSWITCH_CNTL1_DC_LEN                  , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_OSCSWITCH_CNTL1_DC_LEN );

REG64_FLD( PERV_ROOT_CTRL4_TP_OSCSWITCH_VSB                        , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_OSCSWITCH_VSB );
REG64_FLD( PERV_ROOT_CTRL4_TP_OSCSWITCH_VSB_LEN                    , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_OSCSWITCH_VSB_LEN );

REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ0_DC                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_ERRINJ0_DC );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ0_DC_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_ERRINJ0_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ1_DC                  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_ERRINJ1_DC );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_ERRINJ1_DC_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_ERRINJ1_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_TWEAK_DC                    , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_TWEAK_DC );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_TWEAK_DC_LEN                , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_TWEAK_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_SKEW_ADJUST_DC              , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_SKEW_ADJUST_DC );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_SKEW_ADJUST_DC_LEN          , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_SKEW_ADJUST_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_SNS_CONTENT_SEL_DC          , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_SNS_CONTENT_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL5_TPFSI_OSCSW_SNS_CONTENT_SEL_DC_LEN      , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW_SNS_CONTENT_SEL_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL5_15_SPARE_OSC                            , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_16_SPARE_OSC                            , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_16_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_17_SPARE_OSC                            , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_17_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_18_SPARE_OSC                            , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_18_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_19_SPARE_OSC                            , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_19_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_20_SPARE_OSC                            , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_20_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_21_SPARE_OSC                            , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_21_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_22_SPARE_OSC                            , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_23_SPARE_OSC                            , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_24_SPARE_OSC                            , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_25_SPARE_OSC                            , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_26_SPARE_OSC                            , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_27_SPARE_OSC                            , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_27_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_28_SPARE_OSC                            , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_29_SPARE_OSC                            , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_30_SPARE_OSC                            , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_SPARE_OSC );
REG64_FLD( PERV_ROOT_CTRL5_31_SPARE_OSC                            , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_SPARE_OSC );

REG64_FLD( PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC               , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLLREFCLK_RCVR_TERM_DC );
REG64_FLD( PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLLREFCLK_RCVR_TERM_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC               , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PCIREFCLK_RCVR_TERM_DC );
REG64_FLD( PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PCIREFCLK_RCVR_TERM_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL6_REFCLK_0_TERM_DIS_DC                    , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REFCLK_0_TERM_DIS_DC );
REG64_FLD( PERV_ROOT_CTRL6_REFCLK_1_TERM_DIS_DC                    , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REFCLK_1_TERM_DIS_DC );
REG64_FLD( PERV_ROOT_CTRL6_6_SPARE_TERM_DIS                        , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_6_SPARE_TERM_DIS );
REG64_FLD( PERV_ROOT_CTRL6_7_SPARE_TERM_DIS                        , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_7_SPARE_TERM_DIS );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_OSCSW0_PGOOD_N                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW0_PGOOD_N );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_OSCSW1_PGOOD                      , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OSCSW1_PGOOD );
REG64_FLD( PERV_ROOT_CTRL6_10_SPARE_REFCLOCK                       , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_10_SPARE_REFCLOCK );
REG64_FLD( PERV_ROOT_CTRL6_11_SPARE_REFCLOCK                       , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_11_SPARE_REFCLOCK );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC              , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OFFCHIP_REFCLK_EN_DC );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN          , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN );
REG64_FLD( PERV_ROOT_CTRL6_GP_TP_GLBCK_VSB_NEST_MESH_SEL_DC        , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_GP_TP_GLBCK_VSB_NEST_MESH_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL6_25_SPARE_REFCLOCK_CONTROL               , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_SPARE_REFCLOCK_CONTROL );
REG64_FLD( PERV_ROOT_CTRL6_26_SPARE_REFCLOCK_CONTROL               , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_SPARE_REFCLOCK_CONTROL );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_ALTREFCLK_SEL                     , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_ALTREFCLK_SEL );
REG64_FLD( PERV_ROOT_CTRL6_TPFSI_ALTREFCLK_SE1                     , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TPFSI_ALTREFCLK_SE1 );
REG64_FLD( PERV_ROOT_CTRL6_29_SPARE_REFCLOCK_CONTROL               , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_SPARE_REFCLOCK_CONTROL );
REG64_FLD( PERV_ROOT_CTRL6_30_SPARE_REFCLOCK_CONTROL               , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_SPARE_REFCLOCK_CONTROL );
REG64_FLD( PERV_ROOT_CTRL6_31_SPARE_REFCLOCK_CONTROL               , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_SPARE_REFCLOCK_CONTROL );

REG64_FLD( PERV_ROOT_CTRL7_0_SPARE_SECTOR_BUFFER_CONTROL           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_1_SPARE_SECTOR_BUFFER_CONTROL           , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_1_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_2_SPARE_SECTOR_BUFFER_CONTROL           , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_2_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_3_SPARE_SECTOR_BUFFER_CONTROL           , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_3_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_4_SPARE_SECTOR_BUFFER_CONTROL           , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_4_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_5_SPARE_SECTOR_BUFFER_CONTROL           , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_5_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_6_SPARE_SECTOR_BUFFER_CONTROL           , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_6_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_7_SPARE_SECTOR_BUFFER_CONTROL           , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_7_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_8_SPARE_SECTOR_BUFFER_CONTROL           , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_8_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_9_SPARE_SECTOR_BUFFER_CONTROL           , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_9_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_10_SPARE_SECTOR_BUFFER_CONTROL          , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_10_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_11_SPARE_SECTOR_BUFFER_CONTROL          , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_11_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_12_SPARE_SECTOR_BUFFER_CONTROL          , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_12_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_13_SPARE_SECTOR_BUFFER_CONTROL          , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_13_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_14_SPARE_SECTOR_BUFFER_CONTROL          , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_14_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_15_SPARE_SECTOR_BUFFER_CONTROL          , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_SPARE_SECTOR_BUFFER_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_16_SPARE_RESONANT_CLOCKING_CONTROL      , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_16_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_17_SPARE_RESONANT_CLOCKING_CONTROL      , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_17_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_18_SPARE_RESONANT_CLOCKING_CONTROL      , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_18_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_19_SPARE_RESONANT_CLOCKING_CONTROL      , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_19_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_20_SPARE_RESONANT_CLOCKING_CONTROL      , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_20_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_21_SPARE_RESONANT_CLOCKING_CONTROL      , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_21_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_22_SPARE_RESONANT_CLOCKING_CONTROL      , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_23_SPARE_RESONANT_CLOCKING_CONTROL      , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL      , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_24_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL      , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL      , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL      , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_27_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL      , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_28_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL      , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_29_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL      , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_30_SPARE_RESONANT_CLOCKING_CONTROL );
REG64_FLD( PERV_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL      , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_31_SPARE_RESONANT_CLOCKING_CONTROL );

REG64_FLD( PERV_ROOT_CTRL8_TP_SSPLL_PLL_RESET0_DC                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_SSPLL_PLL_RESET0_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_SSPLL_PLL_BYPASS0_DC                 , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_SSPLL_PLL_BYPASS0_DC );
REG64_FLD( PERV_ROOT_CTRL8_2_SPARE_SS_PLL_CONTROL                  , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_2_SPARE_SS_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_3_SPARE_SS_PLL_CONTROL                  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_3_SPARE_SS_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_TP_FILTPLL_PLL_RESET1_DC                , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FILTPLL_PLL_RESET1_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_FILTPLL_PLL_BYPASS1_DC               , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FILTPLL_PLL_BYPASS1_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_FILTPLL_CP_ALT_BYPASS_DC             , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FILTPLL_CP_ALT_BYPASS_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_FILTPLL_IO_ALT_BYPASS_DC             , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FILTPLL_IO_ALT_BYPASS_DC );
REG64_FLD( PERV_ROOT_CTRL8_8_SPARE_FILTER_PLL_CONTROL              , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_8_SPARE_FILTER_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_9_SPARE_FILTER_PLL_CONTROL              , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_9_SPARE_FILTER_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_TP_TANKPLL_TEST_PLL_BYPASS2_DC          , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_TANKPLL_TEST_PLL_BYPASS2_DC );
REG64_FLD( PERV_ROOT_CTRL8_SPARE_TANK_PLL_CONTROL                  , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SPARE_TANK_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_TEST_ENABLE_DC                   , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_TEST_ENABLE_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_FORCE_OUT_EN_DC                  , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_FORCE_OUT_EN_DC );
REG64_FLD( PERV_ROOT_CTRL8_14_SPARE_PLL                            , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_14_SPARE_PLL );
REG64_FLD( PERV_ROOT_CTRL8_15_SPARE_PLL                            , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_15_SPARE_PLL );
REG64_FLD( PERV_ROOT_CTRL8_TP_CLK_ASYNC_RESET_DC                   , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_ASYNC_RESET_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_CLK_DIV_BYPASS_EN_DC                 , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_DIV_BYPASS_EN_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_CLK_PDLY_BYPASS1_EN_DC               , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_PDLY_BYPASS1_EN_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_CLK_PDLY_BYPASS2_EN_DC               , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_CLK_PDLY_BYPASS2_EN_DC );
REG64_FLD( PERV_ROOT_CTRL8_20_SPARE_PLL_CONTROL                    , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_20_SPARE_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_21_SPARE_PLL_CONTROL                    , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_21_SPARE_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_22_SPARE_PLL_CONTROL                    , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_22_SPARE_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_23_SPARE_PLL_CONTROL                    , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_23_SPARE_PLL_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_TP_FSI_CLKIN_SEL_DC                     , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_FSI_CLKIN_SEL_DC );
REG64_FLD( PERV_ROOT_CTRL8_25_SPARE_CLKIN_CONTROL                  , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_25_SPARE_CLKIN_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_26_SPARE_CLKIN_CONTROL                  , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_26_SPARE_CLKIN_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_27_SPARE_CLKIN_CONTROL                  , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_27_SPARE_CLKIN_CONTROL );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL1_DC                    , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_CLKIN_SEL1_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL2_DC                    , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_CLKIN_SEL2_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL3_DC                    , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_CLKIN_SEL3_DC );
REG64_FLD( PERV_ROOT_CTRL8_TP_PLL_CLKIN_SEL4_DC                    , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TP_PLL_CLKIN_SEL4_DC );

REG64_FLD( PERV_SBE_LCL_DBG_EN                                     , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_EN         );
REG64_FLD( PERV_SBE_LCL_DBG_HALT_ON_XSTOP                          , 1   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_HALT_ON_XSTOP );
REG64_FLD( PERV_SBE_LCL_DBG_HALT_ON_TRIG                           , 2   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_HALT_ON_TRIG );
REG64_FLD( PERV_SBE_LCL_DBG_EN_RISCTRACE                           , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_EN_RISCTRACE );
REG64_FLD( PERV_SBE_LCL_DBG_EN_TRACE_FULL_IVA                      , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_EN_TRACE_FULL_IVA );
REG64_FLD( PERV_SBE_LCL_DBG_DIS_TRACE_EXTRA                        , 5   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_DIS_TRACE_EXTRA );
REG64_FLD( PERV_SBE_LCL_DBG_DIS_TRACE_STALL                        , 6   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_DIS_TRACE_STALL );
REG64_FLD( PERV_SBE_LCL_DBG_HTM_TRACE_MODE                         , 7   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_HTM_TRACE_MODE );
REG64_FLD( PERV_SBE_LCL_DBG_SYNC_TIMER_SEL                         , 8   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_SYNC_TIMER_SEL );
REG64_FLD( PERV_SBE_LCL_DBG_SYNC_TIMER_SEL_LEN                     , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_SYNC_TIMER_SEL_LEN );
REG64_FLD( PERV_SBE_LCL_DBG_FIR_TRIGGER                            , 12  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_FIR_TRIGGER );
REG64_FLD( PERV_SBE_LCL_DBG_MIB_GPIO                               , 13  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_MIB_GPIO   );
REG64_FLD( PERV_SBE_LCL_DBG_MIB_GPIO_LEN                           , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_MIB_GPIO_LEN );
REG64_FLD( PERV_SBE_LCL_DBG_HALT_INPUT                             , 16  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_HALT_INPUT );

REG64_FLD( PERV_SBE_LCL_EIMR_START0                                , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START0     );
REG64_FLD( PERV_SBE_LCL_EIMR_START1                                , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START1     );
REG64_FLD( PERV_SBE_LCL_EIMR_INTR0                                 , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR0      );
REG64_FLD( PERV_SBE_LCL_EIMR_INTR1                                 , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR1      );
REG64_FLD( PERV_SBE_LCL_EIMR_DRTM_REQ                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DRTM_REQ   );
REG64_FLD( PERV_SBE_LCL_EIMR_SBEFIFO_RESET                         , 5   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_RESET );
REG64_FLD( PERV_SBE_LCL_EIMR_SBEFIFO_DATA                          , 6   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_DATA );
REG64_FLD( PERV_SBE_LCL_EIMR_SPARE                                 , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SPARE      );
REG64_FLD( PERV_SBE_LCL_EIMR_TRIG                                  , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_TRIG       );
REG64_FLD( PERV_SBE_LCL_EIMR_XSTOP                                 , 9   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_XSTOP      );

REG64_FLD( PERV_SBE_LCL_EINR_START0                                , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_START0     );
REG64_FLD( PERV_SBE_LCL_EINR_START1                                , 1   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_START1     );
REG64_FLD( PERV_SBE_LCL_EINR_INTR0                                 , 2   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_INTR0      );
REG64_FLD( PERV_SBE_LCL_EINR_INTR1                                 , 3   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_INTR1      );
REG64_FLD( PERV_SBE_LCL_EINR_DRTM_REQ                              , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_DRTM_REQ   );
REG64_FLD( PERV_SBE_LCL_EINR_SBEFIFO_RESET                         , 5   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_SBEFIFO_RESET );
REG64_FLD( PERV_SBE_LCL_EINR_SBEFIFO_DATA                          , 6   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_SBEFIFO_DATA );
REG64_FLD( PERV_SBE_LCL_EINR_SPARE                                 , 7   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_SPARE      );
REG64_FLD( PERV_SBE_LCL_EINR_TRIG                                  , 8   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_TRIG       );
REG64_FLD( PERV_SBE_LCL_EINR_XSTOP                                 , 9   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_XSTOP      );

REG64_FLD( PERV_SBE_LCL_EIPR_START0                                , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START0     );
REG64_FLD( PERV_SBE_LCL_EIPR_START1                                , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START1     );
REG64_FLD( PERV_SBE_LCL_EIPR_INTR0                                 , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR0      );
REG64_FLD( PERV_SBE_LCL_EIPR_INTR1                                 , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR1      );
REG64_FLD( PERV_SBE_LCL_EIPR_DRTM_REQ                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DRTM_REQ   );
REG64_FLD( PERV_SBE_LCL_EIPR_SBEFIFO_RESET                         , 5   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_RESET );
REG64_FLD( PERV_SBE_LCL_EIPR_SBEFIFO_DATA                          , 6   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_DATA );
REG64_FLD( PERV_SBE_LCL_EIPR_SPARE                                 , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SPARE      );
REG64_FLD( PERV_SBE_LCL_EIPR_TRIG                                  , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_TRIG       );
REG64_FLD( PERV_SBE_LCL_EIPR_XSTOP                                 , 9   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_XSTOP      );

REG64_FLD( PERV_SBE_LCL_EISR_START0                                , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START0     );
REG64_FLD( PERV_SBE_LCL_EISR_START1                                , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START1     );
REG64_FLD( PERV_SBE_LCL_EISR_INTR0                                 , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR0      );
REG64_FLD( PERV_SBE_LCL_EISR_INTR1                                 , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR1      );
REG64_FLD( PERV_SBE_LCL_EISR_DRTM_REQ                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DRTM_REQ   );
REG64_FLD( PERV_SBE_LCL_EISR_SBEFIFO_RESET                         , 5   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_RESET );
REG64_FLD( PERV_SBE_LCL_EISR_SBEFIFO_DATA                          , 6   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_DATA );
REG64_FLD( PERV_SBE_LCL_EISR_SPARE                                 , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SPARE      );
REG64_FLD( PERV_SBE_LCL_EISR_TRIG                                  , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_TRIG       );
REG64_FLD( PERV_SBE_LCL_EISR_XSTOP                                 , 9   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_XSTOP      );

REG64_FLD( PERV_SBE_LCL_EITR_START0                                , 0   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START0     );
REG64_FLD( PERV_SBE_LCL_EITR_START1                                , 1   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_START1     );
REG64_FLD( PERV_SBE_LCL_EITR_INTR0                                 , 2   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR0      );
REG64_FLD( PERV_SBE_LCL_EITR_INTR1                                 , 3   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_INTR1      );
REG64_FLD( PERV_SBE_LCL_EITR_DRTM_REQ                              , 4   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_DRTM_REQ   );
REG64_FLD( PERV_SBE_LCL_EITR_SBEFIFO_RESET                         , 5   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_RESET );
REG64_FLD( PERV_SBE_LCL_EITR_SBEFIFO_DATA                          , 6   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SBEFIFO_DATA );
REG64_FLD( PERV_SBE_LCL_EITR_SPARE                                 , 7   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_SPARE      );
REG64_FLD( PERV_SBE_LCL_EITR_TRIG                                  , 8   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_TRIG       );
REG64_FLD( PERV_SBE_LCL_EITR_XSTOP                                 , 9   , SH_UNT_PERV     , SH_ACS_PPE2     ,
           SH_FLD_XSTOP      );

REG64_FLD( PERV_SBE_LCL_IVPR_IVPR                                  , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_IVPR       );
REG64_FLD( PERV_SBE_LCL_IVPR_IVPR_LEN                              , 23  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_IVPR_LEN   );

REG64_FLD( PERV_SBE_LCL_TBR_TIMEBASE                               , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_TIMEBASE   );
REG64_FLD( PERV_SBE_LCL_TBR_TIMEBASE_LEN                           , 32  , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_TIMEBASE_LEN );

REG64_FLD( PERV_SBE_LCL_TSEL_FIT_SEL                               , 0   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_FIT_SEL    );
REG64_FLD( PERV_SBE_LCL_TSEL_FIT_SEL_LEN                           , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_FIT_SEL_LEN );
REG64_FLD( PERV_SBE_LCL_TSEL_WATCHDOG_SEL                          , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_WATCHDOG_SEL );
REG64_FLD( PERV_SBE_LCL_TSEL_WATCHDOG_SEL_LEN                      , 4   , SH_UNT_PERV     , SH_ACS_PPE      ,
           SH_FLD_WATCHDOG_SEL_LEN );

REG64_FLD( PERV_SB_CS_SECURE_DEBUG_MODE                            , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SECURE_DEBUG_MODE );
REG64_FLD( PERV_SB_CS_START_RESTART_VECTOR0                        , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_START_RESTART_VECTOR0 );
REG64_FLD( PERV_SB_CS_START_RESTART_VECTOR1                        , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_START_RESTART_VECTOR1 );
REG64_FLD( PERV_SB_CS_INTERRUPT_S0                                 , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_INTERRUPT_S0 );
REG64_FLD( PERV_SB_CS_INTERRUPT_S1                                 , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_INTERRUPT_S1 );
REG64_FLD( PERV_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS                   , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DEBUG_BOLT_ON_CONTROL_BITS );
REG64_FLD( PERV_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN               , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DEBUG_BOLT_ON_CONTROL_BITS_LEN );

REG64_FLD( PERV_1_SCAN_REGION_TYPE_SYSTEM_FAST_INIT                , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM_FAST_INIT );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_VITL                            , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_VITL       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_PERV                            , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT1                           , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT2                           , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT3                           , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT4                           , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT5                           , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT6                           , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT7                           , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT8                           , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT9                           , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_UNIT10                          , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_FUNC                            , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FUNC       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_CFG                             , 49  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG        );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_CCFG_GPTR                       , 50  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CCFG_GPTR  );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_REGF                            , 51  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_REGF       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_LBIST                           , 52  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LBIST      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_ABIST                           , 53  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ABIST      );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_REPR                            , 54  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_REPR       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_TIME                            , 55  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TIME       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_BNDY                            , 56  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_BNDY       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_FARR                            , 57  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FARR       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_CMSK                            , 58  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CMSK       );
REG64_FLD( PERV_1_SCAN_REGION_TYPE_INEX                            , 59  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_INEX       );

REG64_FLD( PERV_FSI2PIB_SCRATCH0_SCRATCH_N                         , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N  );
REG64_FLD( PERV_FSI2PIB_SCRATCH0_SCRATCH_N_LEN                     , 64  , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N_LEN );

REG64_FLD( PERV_FSI2PIB_SCRATCH1_SCRATCH_N                         , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N  );
REG64_FLD( PERV_FSI2PIB_SCRATCH1_SCRATCH_N_LEN                     , 64  , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N_LEN );

REG64_FLD( PERV_FSI2PIB_SCRATCH2_SCRATCH_N                         , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N  );
REG64_FLD( PERV_FSI2PIB_SCRATCH2_SCRATCH_N_LEN                     , 64  , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N_LEN );

REG64_FLD( PERV_FSI2PIB_SCRATCH3_SCRATCH_N                         , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N  );
REG64_FLD( PERV_FSI2PIB_SCRATCH3_SCRATCH_N_LEN                     , 64  , SH_UNT_PERV_FSI2PIB, SH_ACS_PPE2     ,
           SH_FLD_SCRATCH_N_LEN );

REG64_FLD( PERV_SCRATCH_REGISTER_1_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_1_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_2_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_2_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_3_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_3_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_4_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_4_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_5_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_5_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_6_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_6_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_7_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_7_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG64_FLD( PERV_SCRATCH_REGISTER_8_SR                              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR         );
REG64_FLD( PERV_SCRATCH_REGISTER_8_SR_LEN                          , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SR_LEN     );

REG32_FLD( PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_REGISTER         , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REGISTER   );
REG32_FLD( PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_REGISTER_LEN     , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REGISTER_LEN );

REG64_FLD( PERV_1_SKITTER_CLKSRC_REG_SKITTER0                      , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0   );
REG64_FLD( PERV_1_SKITTER_CLKSRC_REG_SKITTER0_LEN                  , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0_LEN );

REG64_FLD( PERV_1_SKITTER_FORCE_REG_F_READ                         , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_F_READ     );

REG64_FLD( PERV_1_SKITTER_MODE_REG_HOLD_SAMPLE                     , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE );
REG64_FLD( PERV_1_SKITTER_MODE_REG_DISABLE_STICKINESS              , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_STICKINESS );
REG64_FLD( PERV_1_SKITTER_MODE_REG_UNUSED1                         , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1    );
REG64_FLD( PERV_1_SKITTER_MODE_REG_UNUSED1_LEN                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1_LEN );
REG64_FLD( PERV_1_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL                , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL );
REG64_FLD( PERV_1_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN            , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL_LEN );
REG64_FLD( PERV_1_SKITTER_MODE_REG_RESET_TRIG_SEL                  , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL );
REG64_FLD( PERV_1_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN              , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL_LEN );
REG64_FLD( PERV_1_SKITTER_MODE_REG_SAMPLE_GUTS                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS );
REG64_FLD( PERV_1_SKITTER_MODE_REG_SAMPLE_GUTS_LEN                 , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS_LEN );
REG64_FLD( PERV_1_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER        , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE_WITH_TRIGGER );
REG64_FLD( PERV_1_SKITTER_MODE_REG_DATA_V_LT                       , 45  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DATA_V_LT  );

REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_PERV_THOLD_CHECK );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN      , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_MALF_PULSE_GEN );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP      , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_STOP_HANG_CNT_SYS_XSTP );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK      , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_CL_ATOMIC_LOCK );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT           , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_HEARTBEAT );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO       , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_FORCE_TO_ZERO );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_PM_DISABLE                  , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_DISABLE );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE              , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_MUX_DISABLE );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_ERROR_MASK                      , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK );
REG64_FLD( PERV_1_SLAVE_CONFIG_REG_ERROR_MASK_LEN                  , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK_LEN );

REG64_FLD( PERV_SNS1LTH_SNS1_UNUSED_0_31                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SNS1_UNUSED_0_31 );
REG64_FLD( PERV_SNS1LTH_SNS1_UNUSED_0_31_LEN                       , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SNS1_UNUSED_0_31_LEN );

REG64_FLD( PERV_SNS2LTH_SNS2_UNUSED_0_31                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SNS2_UNUSED_0_31 );
REG64_FLD( PERV_SNS2LTH_SNS2_UNUSED_0_31_LEN                       , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SNS2_UNUSED_0_31_LEN );

REG64_FLD( PERV_1_SPATTN_IN0                                       , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_SPATTN_IN1                                       , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN1        );
REG64_FLD( PERV_1_SPATTN_IN2                                       , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN2        );
REG64_FLD( PERV_1_SPATTN_IN3                                       , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN3        );
REG64_FLD( PERV_1_SPATTN_IN4                                       , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_SPATTN_IN5                                       , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_SPATTN_IN6                                       , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_SPATTN_IN7                                       , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_SPATTN_IN8                                       , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_SPATTN_IN9                                       , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM2_NC ,
           SH_FLD_IN9        );

REG64_FLD( PERV_1_SPA_MASK_IN                                      , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( PERV_1_SPA_MASK_IN_LEN                                  , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG32_FLD( PERV_FSI2PIB_STATUS_ANY_ERROR                           , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_ANY_ERROR  );
REG32_FLD( PERV_FSI2PIB_STATUS_SYSTEM_CHECKSTOP                    , 1   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_SYSTEM_CHECKSTOP );
REG32_FLD( PERV_FSI2PIB_STATUS_SPECIAL_ATTENTION                   , 2   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_SPECIAL_ATTENTION );
REG32_FLD( PERV_FSI2PIB_STATUS_RECOVERABLE_ERROR                   , 3   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_RECOVERABLE_ERROR );
REG32_FLD( PERV_FSI2PIB_STATUS_CHIPLET_INTERRUPT_FROM_HOST         , 4   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_CHIPLET_INTERRUPT_FROM_HOST );
REG32_FLD( PERV_FSI2PIB_STATUS_PARITY_CHECK                        , 5   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PARITY_CHECK );
REG32_FLD( PERV_FSI2PIB_STATUS_POWER_MANAGEMENT_INTERRUPT          , 6   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_POWER_MANAGEMENT_INTERRUPT );
REG32_FLD( PERV_FSI2PIB_STATUS_PROTECTION_CHECK                    , 7   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PROTECTION_CHECK );
REG32_FLD( PERV_FSI2PIB_STATUS_SELFBOOT_DONE                       , 8   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_SELFBOOT_DONE );
REG32_FLD( PERV_FSI2PIB_STATUS_RESERVED_9                          , 9   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_RESERVED_9 );
REG32_FLD( PERV_FSI2PIB_STATUS_RESERVED_10                         , 10  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_RESERVED_10 );
REG32_FLD( PERV_FSI2PIB_STATUS_PIB_ABORT                           , 11  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PIB_ABORT  );
REG32_FLD( PERV_FSI2PIB_STATUS_USE_OSC_OBSERVATION                 , 12  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_USE_OSC_OBSERVATION );
REG32_FLD( PERV_FSI2PIB_STATUS_USE_OSC_OBSERVATION_LEN             , 4   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_USE_OSC_OBSERVATION_LEN );
REG32_FLD( PERV_FSI2PIB_STATUS_VDD_NEST_OBSERVE                    , 16  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_VDD_NEST_OBSERVE );
REG32_FLD( PERV_FSI2PIB_STATUS_PIB_ERROR_CODE                      , 17  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PIB_ERROR_CODE );
REG32_FLD( PERV_FSI2PIB_STATUS_PIB_ERROR_CODE_LEN                  , 3   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PIB_ERROR_CODE_LEN );
REG32_FLD( PERV_FSI2PIB_STATUS_OSCILLATOR                          , 20  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_OSCILLATOR );
REG32_FLD( PERV_FSI2PIB_STATUS_OSCILLATOR_LEN                      , 4   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_OSCILLATOR_LEN );
REG32_FLD( PERV_FSI2PIB_STATUS_PLLLOCK_0_FILTER_PLL_NEST           , 24  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PLLLOCK_0_FILTER_PLL_NEST );
REG32_FLD( PERV_FSI2PIB_STATUS_PLLLOCK_1_FILTER_PLL_MC             , 25  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PLLLOCK_1_FILTER_PLL_MC );
REG32_FLD( PERV_FSI2PIB_STATUS_PLLLOCK_2_XBUS                      , 26  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PLLLOCK_2_XBUS );
REG32_FLD( PERV_FSI2PIB_STATUS_PLLLOCK_3_NEST                      , 27  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_PLLLOCK_3_NEST );
REG32_FLD( PERV_FSI2PIB_STATUS_INTERRUPT_CONDITION_PENDING         , 28  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_INTERRUPT_CONDITION_PENDING );
REG32_FLD( PERV_FSI2PIB_STATUS_INTERRUPT_ENABLED                   , 29  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_INTERRUPT_ENABLED );
REG32_FLD( PERV_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION           , 30  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_SELFBOOT_ENGINE_ATTENTION );
REG32_FLD( PERV_FSI2PIB_STATUS_RESERVED_31                         , 31  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_RESERVED_31 );

REG32_FLD( PERV_FSISHIFT_STATUS_4                                  , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_4          );
REG32_FLD( PERV_FSISHIFT_STATUS_4_LEN                              , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_4_LEN      );

REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_CMD_PARITY_ERROR         , 1   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_CMD_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR     , 2   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_WR_DATA_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR     , 3   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_RD_DATA_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR  , 4   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_LCK_STATUS_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_FSM_PARITY_ERROR         , 5   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_FSM_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB1_STAT_RDDAT_ERRES_OPB_PARITY_ERROR         , 8   , SH_UNT_PERV_PIB2OPB1, SH_ACS_SCOM_RO  ,
           SH_FLD_OPB_PARITY_ERROR );

REG64_FLD( PERV_STAT_RDDAT_ERRES_CMD_PARITY_ERROR                  , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_CMD_PARITY_ERROR );
REG64_FLD( PERV_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR              , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_WR_DATA_PARITY_ERROR );
REG64_FLD( PERV_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_RD_DATA_PARITY_ERROR );
REG64_FLD( PERV_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR           , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_LCK_STATUS_PARITY_ERROR );
REG64_FLD( PERV_STAT_RDDAT_ERRES_FSM_PARITY_ERROR                  , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_FSM_PARITY_ERROR );
REG64_FLD( PERV_STAT_RDDAT_ERRES_OPB_PARITY_ERROR                  , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RO  ,
           SH_FLD_OPB_PARITY_ERROR );

REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_CMD_PARITY_ERROR         , 1   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_CMD_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR     , 2   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_WR_DATA_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR     , 3   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_RD_DATA_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR  , 4   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_LCK_STATUS_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_FSM_PARITY_ERROR         , 5   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_FSM_PARITY_ERROR );
REG64_FLD( PERV_PIB2OPB0_STAT_RDDAT_ERRES_OPB_PARITY_ERROR         , 8   , SH_UNT_PERV_PIB2OPB0, SH_ACS_SCOM_RO  ,
           SH_FLD_OPB_PARITY_ERROR );

REG64_FLD( PERV_1_SUM_MASK_REG_SMASK_IN                            , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN   );
REG64_FLD( PERV_1_SUM_MASK_REG_SMASK_IN_LEN                        , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN_LEN );

REG64_FLD( PERV_1_SYNC_CONFIG_PULSE_DELAY                          , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY );
REG64_FLD( PERV_1_SYNC_CONFIG_PULSE_DELAY_LEN                      , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY_LEN );
REG64_FLD( PERV_1_SYNC_CONFIG_UNUSED3                              , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED3    );
REG64_FLD( PERV_1_SYNC_CONFIG_LISTEN_TO_PULSE_DIS                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_LISTEN_TO_PULSE_DIS );
REG64_FLD( PERV_1_SYNC_CONFIG_USE_FOR_SCAN                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_USE_FOR_SCAN );
REG64_FLD( PERV_1_SYNC_CONFIG_DISABLE_PCB_ITR                      , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_PCB_ITR );
REG64_FLD( PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED             , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_CLEAR_CHIPLET_IS_ALIGNED );
REG64_FLD( PERV_1_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE            , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT_REGION_CLKCMD_ENABLE );
REG64_FLD( PERV_1_SYNC_CONFIG_UNUSED919                            , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919  );
REG64_FLD( PERV_1_SYNC_CONFIG_UNUSED919_LEN                        , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919_LEN );

REG64_FLD( PERV_1_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR               , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DIS_CPM_BUBBLE_CORR );
REG64_FLD( PERV_1_THERM_MODE_REG_FORCE_THRES_ACT                   , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_FORCE_THRES_ACT );
REG64_FLD( PERV_1_THERM_MODE_REG_THRES_TRIP_ENA                    , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA );
REG64_FLD( PERV_1_THERM_MODE_REG_THRES_TRIP_ENA_LEN                , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA_LEN );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_SAMPLE_ENA                    , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_SAMPLE_ENA );
REG64_FLD( PERV_1_THERM_MODE_REG_SAMPLE_PULSE_CNT                  , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT );
REG64_FLD( PERV_1_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN              , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT_LEN );
REG64_FLD( PERV_1_THERM_MODE_REG_THRES_ENA                         , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA  );
REG64_FLD( PERV_1_THERM_MODE_REG_THRES_ENA_LEN                     , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA_LEN );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_TRIGGER                       , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_TRIGGER_SEL                   , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER_SEL );
REG64_FLD( PERV_1_THERM_MODE_REG_THRES_OVERFLOW_MASK               , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_THRES_OVERFLOW_MASK );
REG64_FLD( PERV_1_THERM_MODE_REG_UNUSED                            , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_READ_SEL                      , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_READ_SEL_LEN                  , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL_LEN );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_ENABLE_L1                     , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1 );
REG64_FLD( PERV_1_THERM_MODE_REG_DTS_ENABLE_L1_LEN                 , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1_LEN );

REG64_FLD( PERV_TIMEOUT_REG_REGISTER                               , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REGISTER   );
REG64_FLD( PERV_TIMEOUT_REG_REGISTER_LEN                           , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_REGISTER_LEN );

REG64_FLD( PERV_1_TIMESTAMP_COUNTER_READ_VALUE                     , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE      );
REG64_FLD( PERV_1_TIMESTAMP_COUNTER_READ_VALUE_LEN                 , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( PERV_1_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR              , 44  , SH_UNT_PERV_1   , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_ERR );

REG64_FLD( PERV_TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TIMEBASE_ENABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT   , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_CORE_SYNC_PERIOD_SELECT );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE        , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_SYNC_CHECK_DISABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE        , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_RX_TTYPE_1_ON_STEP_ENABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_MOVE_TO_TB_ON_2X_SYNC_ENABLE     , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_ON_2X_SYNC_ENABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM            , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_USE_TB_SYNC_MECHANISM );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC                 , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_USE_TB_STEP_SYNC );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE             , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LOW_ORDER_STEP_VALUE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN         , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_LOW_ORDER_STEP_VALUE_LEN );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DISTRIBUTION_BROADCAST_MODE_ENABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_17_18                 , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_17_18 );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_17_18_LEN             , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_17_18_LEN );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_19_23                 , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_19_23 );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_19_23_LEN             , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_19_23_LEN );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_24_25                 , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_24_25 );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_24_25_LEN             , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_24_25_LEN );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET        , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_TX_TTYPE_PIB_MST_IF_RESET );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_27                    , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_27 );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE          , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_CLOCK_OFF_ENABLE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_0X10_SPARE_29                    , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X10_SPARE_29 );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_XSTOP_GATE                       , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_XSTOP_GATE );
REG64_FLD( PERV_TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE       , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STICKY_ERROR_INJECT_ENABLE );

REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X00_DATA_PARITY              , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X00_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY               , 1   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_M_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY               , 2   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_M_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X01_DATA_PARITY              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X01_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X02_DATA_PARITY              , 4   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X02_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X03_DATA_PARITY              , 5   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X03_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X04_DATA_PARITY              , 6   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X04_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X05_DATA_PARITY              , 7   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X05_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X06_DATA_PARITY              , 8   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X06_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X07_DATA_PARITY              , 9   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X07_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY               , 10  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_S_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X08_DATA_PARITY              , 11  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X08_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X09_DATA_PARITY              , 12  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X09_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X0A_DATA_PARITY              , 13  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X0A_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK           , 14  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_M_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK           , 15  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_M_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK           , 16  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_S_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK             , 17  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PSS_HAM                       , 18  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PSS_HAM    );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X0B_DATA_PARITY              , 19  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X0B_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY               , 20  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_S_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK           , 21  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_S_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY , 22  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_DELAY_STEP_CHECK_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X0C_DATA_PARITY              , 23  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X0C_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY , 24  , SH_UNT_PERV     ,
           SH_ACS_SCOM_WO  , SH_FLD_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X17_0X18_0X21_0X22_DATA_PARITY , 25  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X17_0X18_0X21_0X22_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X1D_0X1E_0X1F_DATA_PARITY    , 26  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X1D_0X1E_0X1F_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X20_DATA_PARITY              , 27  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X20_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X23_DATA_PARITY              , 28  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X23_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X24_DATA_PARITY              , 29  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X24_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X29_DATA_PARITY              , 30  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X29_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X30_0X31_0X32_0X33_DATA_PARITY , 31  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X30_0X31_0X32_0X33_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X10_DATA_PARITY              , 32  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X10_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK             , 33  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_SYNC_CHECK );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY       , 34  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_FSM_STATE_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_TIME_PARITY            , 35  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_TIME_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_I_PATH_TIME_OVERFLOW          , 36  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_I_PATH_TIME_OVERFLOW );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY , 37  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_WOF_LOW_ORDER_STEP_COUNTER_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_0                    , 38  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_0 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_1                    , 39  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_1 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_2                    , 40  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_2 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_3                    , 41  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_3 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_4                    , 42  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_4 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_5                    , 43  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_5 );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID        , 44  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_SLAVE_ADDR_INVALID );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID       , 45  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_SLAVE_WRITE_INVALID );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID        , 46  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_SLAVE_READ_INVALID );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY         , 47  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_SLAVE_ADDR_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY         , 48  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_SLAVE_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_0X27_DATA_PARITY              , 49  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_0X27_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO           , 50  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_MASTER_RSP_INFO );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_LEN       , 3   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_MASTER_RSP_INFO_LEN );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID              , 53  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_INVALID );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY        , 54  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_RX_TTYPE_4_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST            , 55  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_MASTER_REQUEST );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_PIB_ACCESS   , 56  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_PIB_RESET_DURING_PIB_ACCESS );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP                , 57  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_EXTERNAL_XSTOP );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_SPARE_58                      , 58  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPARE_58   );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_SPARE_59                      , 59  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPARE_59   );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_SPARE_60                      , 60  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPARE_60   );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_SPARE_61                      , 61  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_SPARE_61   );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT           , 62  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_OSCSWITCH_INTERRUPT );
REG64_FLD( PERV_TOD_ERROR_INJECT_REG_CORE_STEP                     , 63  , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_CORE_STEP  );

REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X00_DATA_PARITY                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X00_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_M_PATH_0_PARITY                 , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_M_PATH_1_PARITY                 , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X01_DATA_PARITY                , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X02_DATA_PARITY                , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X03_DATA_PARITY                , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X04_DATA_PARITY                , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X05_DATA_PARITY                , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X05_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X06_DATA_PARITY                , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X06_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X07_DATA_PARITY                , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_S_PATH_0_PARITY                 , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X08_DATA_PARITY                , 11  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X08_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X09_DATA_PARITY                , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X09_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X0A_DATA_PARITY                , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0A_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK             , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK             , 15  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK             , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK               , 17  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PSS_HAM                         , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PSS_HAM    );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X0B_DATA_PARITY                , 19  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_S_PATH_1_PARITY                 , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK             , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY  , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_STEP_CHECK_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X0C_DATA_PARITY                , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0C_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X17_0X18_0X21_0X22_DATA_PARITY , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X17_0X18_0X21_0X22_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X1D_0X1E_0X1F_DATA_PARITY      , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X1D_0X1E_0X1F_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X20_DATA_PARITY                , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X20_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X23_DATA_PARITY                , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X23_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X24_DATA_PARITY                , 29  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X24_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X29_DATA_PARITY                , 30  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X29_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X30_0X31_0X32_0X33_DATA_PARITY , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X30_0X31_0X32_0X33_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X10_DATA_PARITY                , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X10_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK               , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_SYNC_CHECK );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY         , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_FSM_STATE_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_TIME_PARITY              , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_I_PATH_TIME_OVERFLOW            , 36  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_OVERFLOW );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY , 37  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_WOF_LOW_ORDER_STEP_COUNTER_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_0                      , 38  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_0 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_1                      , 39  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_1 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_2                      , 40  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_2 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_3                      , 41  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_3 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_4                      , 42  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_5                      , 43  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_5 );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID          , 44  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_INVALID );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID         , 45  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_WRITE_INVALID );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID          , 46  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_READ_INVALID );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY           , 47  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY           , 48  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_0X27_DATA_PARITY                , 49  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X27_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO             , 50  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_LEN         , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO_LEN );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_INVALID                , 53  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_INVALID );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY          , 54  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST              , 55  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_REQUEST );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_PIB_RESET_DURING_PIB_ACCESS     , 56  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_RESET_DURING_PIB_ACCESS );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_EXTERNAL_XSTOP                  , 57  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_EXTERNAL_XSTOP );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_SPARE_58                        , 58  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_58   );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_SPARE_59                        , 59  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_59   );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_SPARE_60                        , 60  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_60   );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_SPARE_61                        , 61  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_61   );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT             , 62  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_OSCSWITCH_INTERRUPT );
REG64_FLD( PERV_TOD_ERROR_MASK_REG_SPARE_63                        , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_63   );

REG64_FLD( PERV_TOD_ERROR_REG_0X00_DATA_PARITY                     , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X00_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_M_PATH_0_PARITY                      , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_M_PATH_1_PARITY                      , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X01_DATA_PARITY                     , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X02_DATA_PARITY                     , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X03_DATA_PARITY                     , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X04_DATA_PARITY                     , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X05_DATA_PARITY                     , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X05_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X06_DATA_PARITY                     , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X06_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X07_DATA_PARITY                     , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_S_PATH_0_PARITY                      , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X08_DATA_PARITY                     , 11  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X08_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X09_DATA_PARITY                     , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X09_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X0A_DATA_PARITY                     , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0A_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_M_PATH_0_STEP_CHECK                  , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_M_PATH_1_STEP_CHECK                  , 15  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_S_PATH_0_STEP_CHECK                  , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_STEP_CHECK                    , 17  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_PSS_HAM                              , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PSS_HAM    );
REG64_FLD( PERV_TOD_ERROR_REG_0X0B_DATA_PARITY                     , 19  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_S_PATH_1_PARITY                      , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_S_PATH_1_STEP_CHECK                  , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY       , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_STEP_CHECK_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X0C_DATA_PARITY                     , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0C_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X17_0X18_0X21_0X22_DATA_PARITY      , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X17_0X18_0X21_0X22_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X1D_0X1E_0X1F_DATA_PARITY           , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X1D_0X1E_0X1F_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X20_DATA_PARITY                     , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X20_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X23_DATA_PARITY                     , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X23_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X24_DATA_PARITY                     , 29  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X24_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X29_DATA_PARITY                     , 30  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X29_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X30_0X31_0X32_0X33_DATA_PARITY      , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X30_0X31_0X32_0X33_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X10_DATA_PARITY                     , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X10_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_SYNC_CHECK                    , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_SYNC_CHECK );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY              , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_FSM_STATE_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_TIME_PARITY                   , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_I_PATH_TIME_OVERFLOW                 , 36  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_OVERFLOW );
REG64_FLD( PERV_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY    , 37  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_WOF_LOW_ORDER_STEP_COUNTER_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_0                           , 38  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_0 );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_1                           , 39  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_1 );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_2                           , 40  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_2 );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_3                           , 41  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_3 );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_4                           , 42  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4 );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_5                           , 43  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_5 );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID               , 44  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_INVALID );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID              , 45  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_WRITE_INVALID );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID               , 46  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_READ_INVALID );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY                , 47  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY                , 48  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_0X27_DATA_PARITY                     , 49  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X27_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_MASTER_RSP_INFO                  , 50  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_MASTER_RSP_INFO_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO_LEN );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_INVALID                     , 53  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_INVALID );
REG64_FLD( PERV_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY               , 54  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_MASTER_REQUEST                   , 55  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_REQUEST );
REG64_FLD( PERV_TOD_ERROR_REG_PIB_RESET_DURING_PIB_ACCESS          , 56  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_RESET_DURING_PIB_ACCESS );
REG64_FLD( PERV_TOD_ERROR_REG_EXTERNAL_XSTOP                       , 57  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_EXTERNAL_XSTOP );
REG64_FLD( PERV_TOD_ERROR_REG_SPARE_58                             , 58  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_58   );
REG64_FLD( PERV_TOD_ERROR_REG_SPARE_59                             , 59  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_59   );
REG64_FLD( PERV_TOD_ERROR_REG_SPARE_60                             , 60  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_60   );
REG64_FLD( PERV_TOD_ERROR_REG_SPARE_61                             , 61  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_61   );
REG64_FLD( PERV_TOD_ERROR_REG_OSCSWITCH_INTERRUPT                  , 62  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_OSCSWITCH_INTERRUPT );
REG64_FLD( PERV_TOD_ERROR_REG_SPARE_63                             , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_63   );

REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X00_DATA_PARITY             , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X00_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY              , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY              , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X01_DATA_PARITY             , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X02_DATA_PARITY             , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X03_DATA_PARITY             , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X04_DATA_PARITY             , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X05_DATA_PARITY             , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X05_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X06_DATA_PARITY             , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X06_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X07_DATA_PARITY             , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY              , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X08_DATA_PARITY             , 11  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X08_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X09_DATA_PARITY             , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X09_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X0A_DATA_PARITY             , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0A_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK          , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK          , 15  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK          , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_0_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK            , 17  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK  , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PSS_HAM_CORE_INTERRUPT_MASK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X0B_DATA_PARITY             , 19  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY              , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK          , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_S_PATH_1_STEP_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_STEP_CHECK_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X0C_DATA_PARITY             , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0C_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY , 24  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RW  , SH_FLD_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X17_0X18_0X21_0X22_DATA_PARITY , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X17_0X18_0X21_0X22_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X1D_0X1E_0X1F_DATA_PARITY   , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X1D_0X1E_0X1F_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X20_DATA_PARITY             , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X20_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X23_DATA_PARITY             , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X23_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X24_DATA_PARITY             , 29  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X24_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X29_DATA_PARITY             , 30  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X29_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X30_0X31_0X32_0X33_DATA_PARITY , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X30_0X31_0X32_0X33_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X10_DATA_PARITY             , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X10_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK            , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_SYNC_CHECK );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY      , 34  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_FSM_STATE_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_TIME_PARITY           , 35  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_I_PATH_TIME_OVERFLOW_CORE_INTERRUPT , 36  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_TIME_OVERFLOW_CORE_INTERRUPT );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY , 37  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_WOF_LOW_ORDER_STEP_COUNTER_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_0                   , 38  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_0 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_1                   , 39  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_1 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_2                   , 40  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_2 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_3                   , 41  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_3 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_4                   , 42  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_5                   , 43  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_5 );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID       , 44  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_INVALID );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID      , 45  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_WRITE_INVALID );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID       , 46  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_READ_INVALID );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY        , 47  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_ADDR_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY        , 48  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_SLAVE_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_0X27_DATA_PARITY             , 49  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X27_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO          , 50  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_LEN      , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_RSP_INFO_LEN );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID             , 53  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_INVALID );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY       , 54  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_TTYPE_4_DATA_PARITY );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST           , 55  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_MASTER_REQUEST );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_PIB_ACCESS  , 56  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PIB_RESET_DURING_PIB_ACCESS );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP               , 57  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_EXTERNAL_XSTOP );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_SPARE_58                     , 58  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_58   );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_SPARE_59                     , 59  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_59   );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_SPARE_60                     , 60  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_60   );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_SPARE_61                     , 61  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_61   );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT          , 62  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_OSCSWITCH_INTERRUPT );
REG64_FLD( PERV_TOD_ERROR_ROUTING_REG_SPARE_63                     , 63  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE_63   );

REG64_FLD( PERV_TOD_FSM_REG_I_PATH_STATE                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_STATE );
REG64_FLD( PERV_TOD_FSM_REG_I_PATH_STATE_LEN                       , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_STATE_LEN );
REG64_FLD( PERV_TOD_FSM_REG_IS_RUNNING                             , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_RUNNING );
REG64_FLD( PERV_TOD_FSM_REG_0X24_SPARE_05_07                       , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X24_SPARE_05_07 );
REG64_FLD( PERV_TOD_FSM_REG_0X24_SPARE_05_07_LEN                   , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X24_SPARE_05_07_LEN );

REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_DELAY_DISABLE                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DELAY_DISABLE );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_DISABLE           , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DELAY_ADJUST_DISABLE );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_02_04               , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X06_SPARE_02_04 );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_02_04_LEN           , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X06_SPARE_02_04_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_STEP_SELECT         , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_STEP_SELECT );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION       , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_LEN   , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_CONSTANT_CPS_ENABLE , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_CONSTANT_CPS_ENABLE );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT      , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_VALIDITY_COUNT );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_STEP_CHECK_VALIDITY_COUNT_LEN  , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STEP_CHECK_VALIDITY_COUNT_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_16_21               , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X06_SPARE_16_21 );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_0X06_SPARE_16_21_LEN           , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X06_SPARE_16_21_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_VALUE             , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DELAY_ADJUST_VALUE );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_DELAY_ADJUST_VALUE_LEN         , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_DELAY_ADJUST_VALUE_LEN );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_CPS                            , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_CPS        );
REG64_FLD( PERV_TOD_I_PATH_CTRL_REG_CPS_LEN                        , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_CPS_LEN    );

REG64_FLD( PERV_TOD_LOAD_TOD_MOD_REG_FSM_TRIGGER                   , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_FSM_TRIGGER );
REG64_FLD( PERV_TOD_LOAD_TOD_MOD_REG_FSM_SYNC_ENABLE               , 1   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_FSM_SYNC_ENABLE );

REG64_FLD( PERV_TOD_LOAD_TOD_REG_VALUE                             , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_VALUE      );
REG64_FLD( PERV_TOD_LOAD_TOD_REG_VALUE_LEN                         , 60  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( PERV_TOD_LOAD_TOD_REG_WOF                               , 60  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_WOF        );
REG64_FLD( PERV_TOD_LOAD_TOD_REG_WOF_LEN                           , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_WOF_LEN    );

REG64_FLD( PERV_TOD_LOW_ORDER_STEP_REG_COUNTER_VALUE               , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_VALUE );
REG64_FLD( PERV_TOD_LOW_ORDER_STEP_REG_COUNTER_VALUE_LEN           , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_VALUE_LEN );
REG64_FLD( PERV_TOD_LOW_ORDER_STEP_REG_0X23_SPARE_06_07            , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X23_SPARE_06_07 );
REG64_FLD( PERV_TOD_LOW_ORDER_STEP_REG_0X23_SPARE_06_07_LEN        , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X23_SPARE_06_07_LEN );

REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_ENABLE , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_STEP_CREATE_THRESHOLD_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_ENABLE , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_STEP_ALIGN_THRESHOLD_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_ENABLE , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_STEP_CREATE_THRESHOLD_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_ENABLE , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_STEP_ALIGN_THRESHOLD_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_0X0B_SPARE_04_05                , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_SPARE_04_05 );
REG64_FLD( PERV_TOD_MISC_RESET_REG_0X0B_SPARE_04_05_LEN            , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_SPARE_04_05_LEN );
REG64_FLD( PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_SYNC_DISABLE , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_DISTR_STEP_SYNC_TX_SYNC_DISABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_SYNC_DISABLE  , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_CORE_STEP_SYNC_TX_SYNC_DISABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE           , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PROBE_0_TOGGLE_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE           , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PROBE_1_TOGGLE_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE           , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PROBE_2_TOGGLE_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE           , 11  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PROBE_3_TOGGLE_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_DISABLE      , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_DISTR_STEP_SYNC_TX_DISABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_TRIGGER      , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_DISTR_STEP_SYNC_TX_TRIGGER );
REG64_FLD( PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_ENABLE        , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_CORE_STEP_SYNC_TX_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_TRIGGER       , 15  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_CORE_STEP_SYNC_TX_TRIGGER );
REG64_FLD( PERV_TOD_MISC_RESET_REG_TRACE_ENABLE                    , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_TRACE_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_0X0B_SPARE_17                   , 17  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_SPARE_17 );
REG64_FLD( PERV_TOD_MISC_RESET_REG_TRACE_DATA_SELECT               , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_TRACE_DATA_SELECT );
REG64_FLD( PERV_TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_TRACE_DATA_SELECT_LEN );
REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_ENABLE , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_0_SYNC_CREATE_COUNTER_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_ENABLE , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_PATH_1_SYNC_CREATE_COUNTER_ENABLE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD    , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_TWOS_COMPL_LOAD );
REG64_FLD( PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST             , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_ADJUST );
REG64_FLD( PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE );
REG64_FLD( PERV_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN );
REG64_FLD( PERV_TOD_MISC_RESET_REG_0X0B_SPARE_33_39                , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_SPARE_33_39 );
REG64_FLD( PERV_TOD_MISC_RESET_REG_0X0B_SPARE_33_39_LEN            , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0B_SPARE_33_39_LEN );

REG64_FLD( PERV_TOD_MOVE_TOD_TO_TB_REG_TRIGGER                     , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_MODE                   , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_RATE                   , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RATE       );
REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN               , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RATE_LEN   );
REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG      , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_FLAG );
REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE     , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_VALUE );
REG64_FLD( PERV_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_VALUE_LEN );

REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_MODE                   , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_RATE                   , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RATE       );
REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN               , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RATE_LEN   );
REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG      , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_FLAG );
REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE     , 33  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_VALUE );
REG64_FLD( PERV_TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN , 31  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_COUNTER_LOAD_VALUE_LEN );

REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID                , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_OSC_NOT_VALID );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID                , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_OSC_NOT_VALID );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_ALIGN_DISABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE           , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_ALIGN_DISABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE  , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CREATE_DUAL_EDGE_DISABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT         , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SYNC_CREATE_SPS_SELECT );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN     , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SYNC_CREATE_SPS_SELECT_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION     , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CONSTANT_CPS_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT    , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_VALIDITY_COUNT );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_VALIDITY_COUNT_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION     , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CONSTANT_CPS_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT    , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_VALIDITY_COUNT );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_VALIDITY_COUNT_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE       , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_LOCAL_STEP_MODE_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE       , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_LOCAL_STEP_MODE_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE            , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_STEER_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE            , 29  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_STEER_ENABLE );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0X00_SPARE_30_31               , 30  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X00_SPARE_30_31 );
REG64_FLD( PERV_TOD_M_PATH_CTRL_REG_0X00_SPARE_30_31_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X00_SPARE_30_31_LEN );

REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD       , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_ALIGN_THRESHOLD );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN   , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_ALIGN_THRESHOLD_LEN );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_0_CPS                        , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_CPS      );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_0_CPS_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_CPS_LEN  );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD       , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_ALIGN_THRESHOLD );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN   , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_ALIGN_THRESHOLD_LEN );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_1_CPS                        , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_CPS      );
REG64_FLD( PERV_TOD_M_PATH_STATUS_REG_1_CPS_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_CPS_LEN  );

REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT  );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_RX_SELECT_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_03              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_SPARE_03 );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_SELECT               , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_SELECT               , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_SELECT               , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_SELECT               , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_SELECT               , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_SELECT               , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_SELECT               , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_SELECT               , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X0_TX_ENABLE               , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X1_TX_ENABLE               , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X2_TX_ENABLE               , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X3_TX_ENABLE               , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X4_TX_ENABLE               , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X5_TX_ENABLE               , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X6_TX_ENABLE               , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_X7_TX_ENABLE               , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_28_31           , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_SPARE_28_31 );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_0X01_SPARE_28_31_LEN       , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X01_SPARE_28_31_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE         , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_VALUE );
REG64_FLD( PERV_TOD_PRI_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE_LEN     , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_VALUE_LEN );

REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_RX_SELECT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT  );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_RX_SELECT_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_03              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_SPARE_03 );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_SELECT               , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_SELECT               , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_SELECT               , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_SELECT               , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_SELECT               , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_SELECT               , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_SELECT               , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_SELECT               , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X0_TX_ENABLE               , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X1_TX_ENABLE               , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X2_TX_ENABLE               , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X3_TX_ENABLE               , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X4_TX_ENABLE               , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X5_TX_ENABLE               , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X6_TX_ENABLE               , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_X7_TX_ENABLE               , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_ENABLE );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_28_31           , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_SPARE_28_31 );
REG64_FLD( PERV_TOD_PRI_PORT_1_CTRL_REG_0X02_SPARE_28_31_LEN       , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X02_SPARE_28_31_LEN );

REG64_FLD( PERV_TOD_PROBE_SELECT_REG_0_DATA                        , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_DATA     );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_0_DATA_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_DATA_LEN );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_1_DATA                        , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_DATA     );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_1_DATA_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_DATA_LEN );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_2_DATA                        , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_2_DATA     );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_2_DATA_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_2_DATA_LEN );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_3_DATA                        , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_3_DATA     );
REG64_FLD( PERV_TOD_PROBE_SELECT_REG_3_DATA_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_3_DATA_LEN );

REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT             , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_M_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_SELECT                , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_M_S_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT         , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_M_S_DRAWER_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_S_PATH_1_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_M_PATH_0_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_M_PATH_1_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_S_PATH_0_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE  , 7   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_I_PATH_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT             , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_M_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_SELECT                , 9   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_M_S_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT         , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_M_S_DRAWER_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE , 11  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_S_PATH_1_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_M_PATH_0_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_M_PATH_1_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_S_PATH_0_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE  , 15  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_I_PATH_STEP_CHECK_ENABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_SWITCH_SYNC_ERROR_DISABLE     , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SWITCH_SYNC_ERROR_DISABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE , 17  , SH_UNT_PERV     ,
           SH_ACS_SCOM_RW  , SH_FLD_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CHECK_ENABLE_CHICKEN_SWITCH );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_19                 , 19  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_SPARE_19 );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_20                 , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_SPARE_20 );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM          , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_MISC_RESYNC_OSC_FROM );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_22_31              , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_SPARE_22_31 );
REG64_FLD( PERV_TOD_PSS_MSS_CTRL_REG_0X07_SPARE_22_31_LEN          , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X07_SPARE_22_31_LEN );

REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT              , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_SEC_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN          , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_SEC_SELECT_LEN );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_0X08_SPARE_03               , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X08_SPARE_03 );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID      , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_0_OSC_NOT_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID      , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_1_OSC_NOT_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID   , 6   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_0_STEP_CHECK_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID   , 7   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_1_STEP_CHECK_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID   , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_S_PATH_0_STEP_CHECK_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID     , 9   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_I_PATH_STEP_CHECK_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID   , 10  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_S_PATH_1_STEP_CHECK_VALID );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL                  , 11  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_SPECIAL );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT           , 12  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_M_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_S_SELECT              , 13  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_M_S_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT       , 14  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_M_S_DRAWER_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT           , 15  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PRI_S_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT           , 16  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SEC_M_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_S_SELECT              , 17  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SEC_M_S_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT       , 18  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SEC_M_S_DRAWER_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT           , 19  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_SEC_S_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_RUNNING                  , 20  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_RUNNING );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY                  , 21  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_PRIMARY );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY                , 22  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_SECONDARY );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER            , 23  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_ACTIVE_MASTER );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER            , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_BACKUP_MASTER );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_IS_SLAVE                    , 25  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_IS_SLAVE   );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT               , 26  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT               , 27  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_S_PATH_SELECT );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH , 28  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_0_STEP_ALIGN_VALID_SWITCH );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH , 29  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_1_STEP_ALIGN_VALID_SWITCH );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_0X08_SPARE_30               , 30  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X08_SPARE_30 );
REG64_FLD( PERV_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER       , 31  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_M_PATH_SWITCH_TRIGGER );

REG64_FLD( PERV_TOD_RX_TTYPE_CTRL_REG_DATA                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( PERV_TOD_RX_TTYPE_CTRL_REG_DATA_LEN                     , 64  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_RX_SELECT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT  );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_RX_SELECT_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_03              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_SPARE_03 );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_SELECT               , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_SELECT               , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_SELECT               , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_SELECT               , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_SELECT               , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_SELECT               , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_SELECT               , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_SELECT               , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X0_TX_ENABLE               , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X1_TX_ENABLE               , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X2_TX_ENABLE               , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X3_TX_ENABLE               , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X4_TX_ENABLE               , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X5_TX_ENABLE               , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X6_TX_ENABLE               , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_X7_TX_ENABLE               , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_28_31           , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_SPARE_28_31 );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_0X03_SPARE_28_31_LEN       , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X03_SPARE_28_31_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE         , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_VALUE );
REG64_FLD( PERV_TOD_SEC_PORT_0_CTRL_REG_I_PATH_DELAY_VALUE_LEN     , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_PATH_DELAY_VALUE_LEN );

REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_RX_SELECT                  , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT  );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_RX_SELECT_LEN              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_RX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_03              , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_SPARE_03 );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_SELECT               , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_SELECT               , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_SELECT               , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_SELECT               , 10  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_SELECT               , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_SELECT               , 14  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_SELECT               , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_SELECT               , 18  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_SELECT_LEN           , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_SELECT_LEN );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X0_TX_ENABLE               , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X0_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X1_TX_ENABLE               , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X1_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X2_TX_ENABLE               , 22  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X2_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X3_TX_ENABLE               , 23  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X3_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X4_TX_ENABLE               , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X4_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X5_TX_ENABLE               , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X5_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X6_TX_ENABLE               , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X6_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_X7_TX_ENABLE               , 27  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_X7_TX_ENABLE );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_28_31           , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_SPARE_28_31 );
REG64_FLD( PERV_TOD_SEC_PORT_1_CTRL_REG_0X04_SPARE_28_31_LEN       , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X04_SPARE_28_31_LEN );

REG64_FLD( PERV_TOD_START_TOD_REG_FSM_TRIGGER                      , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FSM_TRIGGER );
REG64_FLD( PERV_TOD_START_TOD_REG_0X22_SPARE_01                    , 1   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X22_SPARE_01 );
REG64_FLD( PERV_TOD_START_TOD_REG_FSM_DATA02                       , 2   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_FSM_DATA02 );
REG64_FLD( PERV_TOD_START_TOD_REG_0X22_SPARE_03_07                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X22_SPARE_03_07 );
REG64_FLD( PERV_TOD_START_TOD_REG_0X22_SPARE_03_07_LEN             , 5   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X22_SPARE_03_07_LEN );

REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_PRI_SELECT                     , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_PRI_SELECT );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0X05_SPARE_01                  , 1   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X05_SPARE_01 );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_M_CPS_ENABLE                   , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_CPS_ENABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_DISABLE            , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_DISABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_SEC_SELECT                     , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SEC_SELECT );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0X05_SPARE_05                  , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X05_SPARE_05 );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR , 6   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN , 2   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION     , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE , 12  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_CONSTANT_CPS_ENABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT    , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_VALIDITY_COUNT );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_STEP_CHECK_VALIDITY_COUNT_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION     , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE , 20  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_CONSTANT_CPS_ENABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT    , 21  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_VALIDITY_COUNT );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_STEP_CHECK_VALIDITY_COUNT_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_ERROR_DISABLE      , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_ERROR_DISABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_M_CPS_DISABLE , 25  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_CHECK_M_CPS_DISABLE );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR , 26  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN , 2   , SH_UNT_PERV     ,
           SH_ACS_SCOM_RW  , SH_FLD_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION , 28  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_CHECK_CPS_DEVIATION );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX     , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_MISS_COUNT_MAX );
REG64_FLD( PERV_TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_MAX_LEN , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_REMOTE_SYNC_MISS_COUNT_MAX_LEN );

REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_M_0_STEP_ALIGN_FSM_STATE     , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_0_STEP_ALIGN_FSM_STATE );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_M_0_STEP_ALIGN_FSM_STATE_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_0_STEP_ALIGN_FSM_STATE_LEN );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_M_1_STEP_ALIGN_FSM_STATE     , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_1_STEP_ALIGN_FSM_STATE );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_M_1_STEP_ALIGN_FSM_STATE_LEN , 4   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_M_1_STEP_ALIGN_FSM_STATE_LEN );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_I_DELAY_ADJUST_RATIO         , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_DELAY_ADJUST_RATIO );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_I_DELAY_ADJUST_RATIO_LEN     , 5   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_I_DELAY_ADJUST_RATIO_LEN );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0X0A_SPARE_13_15             , 13  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0A_SPARE_13_15 );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0X0A_SPARE_13_15_LEN         , 3   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0X0A_SPARE_13_15_LEN );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0_CPS                        , 16  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_CPS      );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0_CPS_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_CPS_LEN  );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_1_CPS                        , 24  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_CPS      );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_1_CPS_LEN                    , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_CPS_LEN  );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0_REMOTE_SYNC_LATE_SYNC_COUNT , 32  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_REMOTE_SYNC_LATE_SYNC_COUNT );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_0_REMOTE_SYNC_LATE_SYNC_COUNT_LEN , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_0_REMOTE_SYNC_LATE_SYNC_COUNT_LEN );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_1_REMOTE_SYNC_LATE_SYNC_COUNT , 40  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_REMOTE_SYNC_LATE_SYNC_COUNT );
REG64_FLD( PERV_TOD_S_PATH_STATUS_REG_1_REMOTE_SYNC_LATE_SYNC_COUNT_LEN , 8   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_1_REMOTE_SYNC_LATE_SYNC_COUNT_LEN );

REG64_FLD( PERV_TOD_TIMER_REG_VALUE                                , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_VALUE      );
REG64_FLD( PERV_TOD_TIMER_REG_VALUE_LEN                            , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( PERV_TOD_TIMER_REG_0X0D_SPARE_60_62                     , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X0D_SPARE_60_62 );
REG64_FLD( PERV_TOD_TIMER_REG_0X0D_SPARE_60_62_LEN                 , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X0D_SPARE_60_62_LEN );
REG64_FLD( PERV_TOD_TIMER_REG_STATUS                               , 63  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_STATUS     );

REG64_FLD( PERV_TOD_TRACE_DATA_1_REG_SET                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET        );
REG64_FLD( PERV_TOD_TRACE_DATA_1_REG_SET_LEN                       , 64  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET_LEN    );

REG64_FLD( PERV_TOD_TRACE_DATA_2_REG_SET                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET        );
REG64_FLD( PERV_TOD_TRACE_DATA_2_REG_SET_LEN                       , 64  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET_LEN    );

REG64_FLD( PERV_TOD_TRACE_DATA_3_REG_SET                           , 0   , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET        );
REG64_FLD( PERV_TOD_TRACE_DATA_3_REG_SET_LEN                       , 64  , SH_UNT_PERV     , SH_ACS_SCOM_RW  ,
           SH_FLD_SET_LEN    );

REG64_FLD( PERV_TOD_TX_TTYPE_0_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_1_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_2_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_3_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_4_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_5_REG_TRIGGER                         , 0   , SH_UNT_PERV     , SH_ACS_SCOM_WO  ,
           SH_FLD_TRIGGER    );

REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS      , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_CORE_ADDRESS );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS_LEN  , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_CORE_ADDRESS_LEN );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ID           , 24  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_CORE_ID );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ID_LEN       , 8   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_CORE_ID_LEN );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_4_SEND_MODE                  , 32  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_4_SEND_MODE );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_4_SEND_ENABLE                , 33  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_4_SEND_ENABLE );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_0X27_SPARE_34                , 34  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X27_SPARE_34 );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_MOVE_TO_TB_CORE_ADDRESS_ENABLE , 35  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_MOVE_TO_TB_CORE_ADDRESS_ENABLE );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_0X27_SPARE_36                , 36  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_0X27_SPARE_36 );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_PIB_FSM_STATE                , 37  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_FSM_STATE );
REG64_FLD( PERV_TOD_TX_TTYPE_CTRL_REG_PIB_FSM_STATE_LEN            , 3   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_PIB_FSM_STATE_LEN );

REG64_FLD( PERV_TOD_VALUE_REG_VALUE                                , 0   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_VALUE      );
REG64_FLD( PERV_TOD_VALUE_REG_VALUE_LEN                            , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( PERV_TOD_VALUE_REG_WOF_COUNTER                          , 60  , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_WOF_COUNTER );
REG64_FLD( PERV_TOD_VALUE_REG_WOF_COUNTER_LEN                      , 4   , SH_UNT_PERV     , SH_ACS_SCOM     ,
           SH_FLD_WOF_COUNTER_LEN );

REG32_FLD( PERV_FSI2PIB_TRUE_MASK_REG                              , 0   , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSI2PIB_TRUE_MASK_REG_LEN                          , 32  , SH_UNT_PERV_FSI2PIB, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSISHIFT_TRUE_MASK_REG                             , 0   , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG        );
REG32_FLD( PERV_FSISHIFT_TRUE_MASK_REG_LEN                         , 32  , SH_UNT_PERV_FSISHIFT, SH_ACS_FSI_BYTE ,
           SH_FLD_REG_LEN    );

REG32_FLD( PERV_FSII2C_WATER_MARK_REGISTER_WATERMARK_REG           , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_WATERMARK_REG );
REG32_FLD( PERV_FSII2C_WATER_MARK_REGISTER_WATERMARK_REG_LEN       , 16  , SH_UNT_PERV_FSII2C, SH_ACS_SCOM     ,
           SH_FLD_WATERMARK_REG_LEN );

REG64_FLD( PERV_1_XFIR_IN0                                         , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( PERV_1_XFIR_IN1                                         , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( PERV_1_XFIR_IN2                                         , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( PERV_1_XFIR_IN3                                         , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( PERV_1_XFIR_IN4                                         , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( PERV_1_XFIR_IN5                                         , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( PERV_1_XFIR_IN6                                         , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( PERV_1_XFIR_IN7                                         , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( PERV_1_XFIR_IN8                                         , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( PERV_1_XFIR_IN9                                         , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( PERV_1_XFIR_IN10                                        , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( PERV_1_XFIR_IN11                                        , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( PERV_1_XFIR_IN12                                        , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN12       );
REG64_FLD( PERV_1_XFIR_IN13                                        , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN13       );
REG64_FLD( PERV_1_XFIR_IN14                                        , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN14       );
REG64_FLD( PERV_1_XFIR_IN15                                        , 15  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN15       );
REG64_FLD( PERV_1_XFIR_IN16                                        , 16  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN16       );
REG64_FLD( PERV_1_XFIR_IN17                                        , 17  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN17       );
REG64_FLD( PERV_1_XFIR_IN18                                        , 18  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN18       );
REG64_FLD( PERV_1_XFIR_IN19                                        , 19  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN19       );
REG64_FLD( PERV_1_XFIR_IN20                                        , 20  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN20       );
REG64_FLD( PERV_1_XFIR_IN21                                        , 21  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21       );
REG64_FLD( PERV_1_XFIR_IN21_LEN                                    , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN21_LEN   );
REG64_FLD( PERV_1_XFIR_IN26                                        , 26  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_IN26       );

REG64_FLD( PERV_1_XSTOP1_MASK_B                                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( PERV_1_XSTOP1_KEEP_EDRAM_ENABLED_ON                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( PERV_1_XSTOP1_TRIGGER_OPCG_ON                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( PERV_1_XSTOP1_WAIT_ALLWAYS                              , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( PERV_1_XSTOP1_PERV                                      , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( PERV_1_XSTOP1_UNIT1                                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( PERV_1_XSTOP1_UNIT2                                     , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( PERV_1_XSTOP1_UNIT3                                     , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( PERV_1_XSTOP1_UNIT4                                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( PERV_1_XSTOP1_UNIT5                                     , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( PERV_1_XSTOP1_UNIT6                                     , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( PERV_1_XSTOP1_UNIT7                                     , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( PERV_1_XSTOP1_UNIT8                                     , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( PERV_1_XSTOP1_UNIT9                                     , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( PERV_1_XSTOP1_UNIT10                                    , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( PERV_1_XSTOP1_WAIT_CYCLES                               , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( PERV_1_XSTOP1_WAIT_CYCLES_LEN                           , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( PERV_1_XSTOP2_MASK_B                                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( PERV_1_XSTOP2_KEEP_EDRAM_ENABLED_ON                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( PERV_1_XSTOP2_TRIGGER_OPCG_ON                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( PERV_1_XSTOP2_WAIT_ALLWAYS                              , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( PERV_1_XSTOP2_PERV                                      , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( PERV_1_XSTOP2_UNIT1                                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( PERV_1_XSTOP2_UNIT2                                     , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( PERV_1_XSTOP2_UNIT3                                     , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( PERV_1_XSTOP2_UNIT4                                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( PERV_1_XSTOP2_UNIT5                                     , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( PERV_1_XSTOP2_UNIT6                                     , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( PERV_1_XSTOP2_UNIT7                                     , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( PERV_1_XSTOP2_UNIT8                                     , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( PERV_1_XSTOP2_UNIT9                                     , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( PERV_1_XSTOP2_UNIT10                                    , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( PERV_1_XSTOP2_WAIT_CYCLES                               , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( PERV_1_XSTOP2_WAIT_CYCLES_LEN                           , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( PERV_1_XSTOP3_MASK_B                                    , 0   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( PERV_1_XSTOP3_KEEP_EDRAM_ENABLED_ON                     , 1   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( PERV_1_XSTOP3_TRIGGER_OPCG_ON                           , 2   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( PERV_1_XSTOP3_WAIT_ALLWAYS                              , 3   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( PERV_1_XSTOP3_PERV                                      , 4   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( PERV_1_XSTOP3_UNIT1                                     , 5   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( PERV_1_XSTOP3_UNIT2                                     , 6   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( PERV_1_XSTOP3_UNIT3                                     , 7   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( PERV_1_XSTOP3_UNIT4                                     , 8   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( PERV_1_XSTOP3_UNIT5                                     , 9   , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( PERV_1_XSTOP3_UNIT6                                     , 10  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( PERV_1_XSTOP3_UNIT7                                     , 11  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( PERV_1_XSTOP3_UNIT8                                     , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( PERV_1_XSTOP3_UNIT9                                     , 13  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( PERV_1_XSTOP3_UNIT10                                    , 14  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( PERV_1_XSTOP3_WAIT_CYCLES                               , 48  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( PERV_1_XSTOP3_WAIT_CYCLES_LEN                           , 12  , SH_UNT_PERV_1   , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

#endif

