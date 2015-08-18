/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_quad_scom_addresses_fld.H $        */
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
/// @file p9_quad_scom_addresses_fld.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE
#ifndef __P9_QUAD_SCOM_ADDRESSES_FLD_H
#define __P9_QUAD_SCOM_ADDRESSES_FLD_H


#include <p9_scom_template_consts.H>
#include <p9_quad_scom_addresses_fld_fixes.H>

REG64_FLD( CAPP_APCFG_APCCTL_PHB_SEL                               , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_PHB_SEL );
REG64_FLD( CAPP_APCFG_APCCTL_PHB_SEL_LEN                           , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_PHB_SEL_LEN );
REG64_FLD( CAPP_APCFG_HANG_POLL_SCALE                              , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_SCALE );
REG64_FLD( CAPP_APCFG_HANG_POLL_SCALE_LEN                          , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_SCALE_LEN );
REG64_FLD( CAPP_APCFG_SPEC_HPC_DIR_STATE                           , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SPEC_HPC_DIR_STATE );
REG64_FLD( CAPP_APCFG_SPEC_HPC_DIR_STATE_LEN                       , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SPEC_HPC_DIR_STATE_LEN );
REG64_FLD( CAPP_APCFG_APCCTL_P9_MODE                               , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_P9_MODE );
REG64_FLD( CAPP_APCFG_APCCTL_SYSADDR                               , 15  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_SYSADDR );
REG64_FLD( CAPP_APCFG_APCCTL_SYSADDR_LEN                           , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_SYSADDR_LEN );
REG64_FLD( CAPP_APCFG_APCCTL_MEM_SEL_MODE                          , 21  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_MEM_SEL_MODE );
REG64_FLD( CAPP_APCFG_APCCTL_ENB_FRC_ADDR13                        , 22  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_ENB_FRC_ADDR13 );

REG64_FLD( CAPP_APCLCO_TARGET_VALID                                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TARGET_VALID );
REG64_FLD( CAPP_APCLCO_TARGET_VALID_LEN                            , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TARGET_VALID_LEN );
REG64_FLD( CAPP_APCLCO_TARGET_ID0                                  , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TARGET_ID0 );
REG64_FLD( CAPP_APCLCO_TARGET_MIN                                  , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TARGET_MIN );
REG64_FLD( CAPP_APCLCO_TARGET_MIN_LEN                              , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TARGET_MIN_LEN );

REG64_FLD( CAPP_APCTL_APCCTL_ENB_CRESP_EXAM                        , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_ENB_CRESP_EXAM );
REG64_FLD( CAPP_APCTL_APCCTL_ADR_BAR_MODE                          , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_ADR_BAR_MODE );
REG64_FLD( CAPP_APCTL_APCCTL_DISABLE_NN_RN                         , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_DISABLE_NN_RN );
REG64_FLD( CAPP_APCTL_APCCTL_DISABLE_VG_NOT_SYS                    , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_DISABLE_VG_NOT_SYS );
REG64_FLD( CAPP_APCTL_APCCTL_DISABLE_G                             , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_DISABLE_G );
REG64_FLD( CAPP_APCTL_APCCTL_DISABLE_LN                            , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_DISABLE_LN );
REG64_FLD( CAPP_APCTL_APCCTL_SKIP_G                                , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_SKIP_G );
REG64_FLD( CAPP_APCTL_APCCTL_HANG_ARE                              , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_HANG_ARE );
REG64_FLD( CAPP_APCTL_APCCTL_HANG_DEAD                             , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_HANG_DEAD );
REG64_FLD( CAPP_APCTL_APCCTL_CFG_BKILL_INC                         , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_CFG_BKILL_INC );
REG64_FLD( CAPP_APCTL_RDBUFF_ALLOC                                 , 10  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RDBUFF_ALLOC );
REG64_FLD( CAPP_APCTL_RDBUFF_ALLOC_LEN                             , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RDBUFF_ALLOC_LEN );
REG64_FLD( CAPP_APCTL_APCCTL_DISABLE_PSL_CMDQUEUE                  , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_DISABLE_PSL_CMDQUEUE );
REG64_FLD( CAPP_APCTL_APCCTL_ENABLE_MASTER_RETRY_BACKOFF           , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_ENABLE_MASTER_RETRY_BACKOFF );
REG64_FLD( CAPP_APCTL_SCPTGT_LFSR_MODE                             , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SCPTGT_LFSR_MODE );
REG64_FLD( CAPP_APCTL_SCPTGT_LFSR_MODE_LEN                         , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SCPTGT_LFSR_MODE_LEN );
REG64_FLD( CAPP_APCTL_APCCTL_ENABLE_RD_VG_SCOPE_PREDICT            , 17  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_ENABLE_RD_VG_SCOPE_PREDICT );
REG64_FLD( CAPP_APCTL_WR_EPSILON_VALUE                             , 39  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_WR_EPSILON_VALUE );
REG64_FLD( CAPP_APCTL_WR_EPSILON_VALUE_LEN                         , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_WR_EPSILON_VALUE_LEN );
REG64_FLD( CAPP_APCTL_APCCTL_MAX_RETRY                             , 56  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_MAX_RETRY );
REG64_FLD( CAPP_APCTL_APCCTL_MAX_RETRY_LEN                         , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCCTL_MAX_RETRY_LEN );

REG64_FLD( CAPP_APC_ARRY_ADDR_APCARY_ADDRESS                       , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY_ADDRESS );
REG64_FLD( CAPP_APC_ARRY_ADDR_APCARY_ADDRESS_LEN                   , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY_ADDRESS_LEN );

REG64_FLD( CAPP_APC_ARRY_RDDATA_APCARY                             , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY     );
REG64_FLD( CAPP_APC_ARRY_RDDATA_APCARY_LEN                         , 64  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY_LEN );

REG64_FLD( CAPP_APC_ARRY_WRDATA_APCARY                             , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY     );
REG64_FLD( CAPP_APC_ARRY_WRDATA_APCARY_LEN                         , 64  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_APCARY_LEN );

REG64_FLD( CAPP_APC_PMUSEL_GRPSEL                                  , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_GRPSEL     );
REG64_FLD( CAPP_APC_PMUSEL_GRPSEL_LEN                              , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_GRPSEL_LEN );
REG64_FLD( CAPP_APC_PMUSEL_FSMJ_EVENT_SEL                          , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_EVENT_SEL );
REG64_FLD( CAPP_APC_PMUSEL_FSMJ_EVENT_SEL_LEN                      , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_EVENT_SEL_LEN );
REG64_FLD( CAPP_APC_PMUSEL_FSMJ_FSM_SEL                            , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_FSM_SEL );
REG64_FLD( CAPP_APC_PMUSEL_FSMJ_FSM_SEL_LEN                        , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_FSM_SEL_LEN );

REG64_FLD( CAPP_ASE_TUPLE0_LPID                                    , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID       );
REG64_FLD( CAPP_ASE_TUPLE0_LPID_LEN                                , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID_LEN   );
REG64_FLD( CAPP_ASE_TUPLE0_PID                                     , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID        );
REG64_FLD( CAPP_ASE_TUPLE0_PID_LEN                                 , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE0_TID                                     , 44  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID        );
REG64_FLD( CAPP_ASE_TUPLE0_TID_LEN                                 , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE0_VALID                                   , 63  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );

REG64_FLD( CAPP_ASE_TUPLE1_LPID                                    , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID       );
REG64_FLD( CAPP_ASE_TUPLE1_LPID_LEN                                , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID_LEN   );
REG64_FLD( CAPP_ASE_TUPLE1_PID                                     , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID        );
REG64_FLD( CAPP_ASE_TUPLE1_PID_LEN                                 , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE1_TID                                     , 44  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID        );
REG64_FLD( CAPP_ASE_TUPLE1_TID_LEN                                 , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE1_VALID                                   , 63  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );

REG64_FLD( CAPP_ASE_TUPLE2_LPID                                    , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID       );
REG64_FLD( CAPP_ASE_TUPLE2_LPID_LEN                                , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID_LEN   );
REG64_FLD( CAPP_ASE_TUPLE2_PID                                     , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID        );
REG64_FLD( CAPP_ASE_TUPLE2_PID_LEN                                 , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE2_TID                                     , 44  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID        );
REG64_FLD( CAPP_ASE_TUPLE2_TID_LEN                                 , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE2_VALID                                   , 63  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );

REG64_FLD( CAPP_ASE_TUPLE3_LPID                                    , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID       );
REG64_FLD( CAPP_ASE_TUPLE3_LPID_LEN                                , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPID_LEN   );
REG64_FLD( CAPP_ASE_TUPLE3_PID                                     , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID        );
REG64_FLD( CAPP_ASE_TUPLE3_PID_LEN                                 , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE3_TID                                     , 44  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID        );
REG64_FLD( CAPP_ASE_TUPLE3_TID_LEN                                 , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TID_LEN    );
REG64_FLD( CAPP_ASE_TUPLE3_VALID                                   , 63  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );

REG64_FLD( EQ_ATOMIC_LOCK_REG_ENABLE                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EQ_ATOMIC_LOCK_REG_ID                                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EQ_ATOMIC_LOCK_REG_ID_LEN                               , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EQ_ATOMIC_LOCK_REG_ACTIVITY                             , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EQ_ATOMIC_LOCK_REG_ACTIVITY_LEN                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EX_ATOMIC_LOCK_REG_ENABLE                               , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EX_ATOMIC_LOCK_REG_ID                                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EX_ATOMIC_LOCK_REG_ID_LEN                               , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EX_ATOMIC_LOCK_REG_ACTIVITY                             , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EX_ATOMIC_LOCK_REG_ACTIVITY_LEN                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( C_ATOMIC_LOCK_REG_ENABLE                                , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( C_ATOMIC_LOCK_REG_ID                                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( C_ATOMIC_LOCK_REG_ID_LEN                                , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( C_ATOMIC_LOCK_REG_ACTIVITY                              , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( C_ATOMIC_LOCK_REG_ACTIVITY_LEN                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EQ_BIST_TC_START_TEST_DC                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_START_TEST_DC );
REG64_FLD( EQ_BIST_TC_SRAM_ABIST_MODE_DC                           , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_SRAM_ABIST_MODE_DC );
REG64_FLD( EQ_BIST_TC_EDRAM_ABIST_MODE_DC                          , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_EDRAM_ABIST_MODE_DC );
REG64_FLD( EQ_BIST_TC_IOBIST_MODE_DC                               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_IOBIST_MODE_DC );
REG64_FLD( EQ_BIST_PERV                                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EQ_BIST_UNIT1                                           , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EQ_BIST_UNIT2                                           , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EQ_BIST_UNIT3                                           , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EQ_BIST_UNIT4                                           , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EQ_BIST_UNIT5                                           , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EQ_BIST_UNIT6                                           , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EQ_BIST_UNIT7                                           , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EQ_BIST_UNIT8                                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EQ_BIST_UNIT9                                           , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EQ_BIST_UNIT10                                          , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );

REG64_FLD( EX_BIST_TC_START_TEST_DC                                , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_START_TEST_DC );
REG64_FLD( EX_BIST_TC_SRAM_ABIST_MODE_DC                           , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_SRAM_ABIST_MODE_DC );
REG64_FLD( EX_BIST_TC_EDRAM_ABIST_MODE_DC                          , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_EDRAM_ABIST_MODE_DC );
REG64_FLD( EX_BIST_TC_IOBIST_MODE_DC                               , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_IOBIST_MODE_DC );
REG64_FLD( EX_BIST_PERV                                            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EX_BIST_UNIT1                                           , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EX_BIST_UNIT2                                           , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EX_BIST_UNIT3                                           , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EX_BIST_UNIT4                                           , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EX_BIST_UNIT5                                           , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EX_BIST_UNIT6                                           , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EX_BIST_UNIT7                                           , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EX_BIST_UNIT8                                           , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EX_BIST_UNIT9                                           , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EX_BIST_UNIT10                                          , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );

REG64_FLD( C_BIST_TC_START_TEST_DC                                 , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_START_TEST_DC );
REG64_FLD( C_BIST_TC_SRAM_ABIST_MODE_DC                            , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_SRAM_ABIST_MODE_DC );
REG64_FLD( C_BIST_TC_EDRAM_ABIST_MODE_DC                           , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_EDRAM_ABIST_MODE_DC );
REG64_FLD( C_BIST_TC_IOBIST_MODE_DC                                , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_IOBIST_MODE_DC );
REG64_FLD( C_BIST_PERV                                             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( C_BIST_UNIT1                                            , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( C_BIST_UNIT2                                            , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( C_BIST_UNIT3                                            , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( C_BIST_UNIT4                                            , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( C_BIST_UNIT5                                            , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( C_BIST_UNIT6                                            , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( C_BIST_UNIT7                                            , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( C_BIST_UNIT8                                            , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( C_BIST_UNIT9                                            , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( C_BIST_UNIT10                                           , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );

REG64_FLD( CAPP_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL_TIMER_ENABLE   , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TIMER_ENABLE );
REG64_FLD( CAPP_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL_TIMER_PERIOD_MASK , 48  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TIMER_PERIOD_MASK );
REG64_FLD( CAPP_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL_TIMER_PERIOD_MASK_LEN , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TIMER_PERIOD_MASK_LEN );

REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_ERROR_RECOVERY_INITIATED   , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_RECOVERY_INITIATED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_ERROR_RECOVERY_COMPLETE    , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ERROR_RECOVERY_COMPLETE );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_TLBI_PSL_DEAD              , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBI_PSL_DEAD );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_TLBI_FENCE                 , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBI_FENCE );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_RECOVERY_FAILED            , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RECOVERY_FAILED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_RTAGFLUSH_FAILED           , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RTAGFLUSH_FAILED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_PRECISE_DIR_FLUSH_FAILED   , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PRECISE_DIR_FLUSH_FAILED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_COURSE_DIR_FLUSH_FAILED    , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COURSE_DIR_FLUSH_FAILED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_RECOVERY_HANG_DETECTED     , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RECOVERY_HANG_DETECTED );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_EPOCH_VALUE                , 10  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EPOCH_VALUE );
REG64_FLD( CAPP_CAPP_ERR_STATUS_CONTROL_EPOCH_VALUE_LEN            , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EPOCH_VALUE_LEN );

REG64_FLD( EQ_CC_ATOMIC_LOCK_REG_ENABLE                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EQ_CC_ATOMIC_LOCK_REG_ID                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EQ_CC_ATOMIC_LOCK_REG_ID_LEN                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EQ_CC_ATOMIC_LOCK_REG_ACTIVITY                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EQ_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EX_CC_ATOMIC_LOCK_REG_ENABLE                            , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EX_CC_ATOMIC_LOCK_REG_ID                                , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EX_CC_ATOMIC_LOCK_REG_ID_LEN                            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EX_CC_ATOMIC_LOCK_REG_ACTIVITY                          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EX_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( C_CC_ATOMIC_LOCK_REG_ENABLE                             , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( C_CC_ATOMIC_LOCK_REG_ID                                 , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( C_CC_ATOMIC_LOCK_REG_ID_LEN                             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( C_CC_ATOMIC_LOCK_REG_ACTIVITY                           , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( C_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN                       , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EQ_CC_PROTECT_MODE_REG_READ_ENABLE                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EQ_CC_PROTECT_MODE_REG_WRITE_ENABLE                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( EX_CC_PROTECT_MODE_REG_READ_ENABLE                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EX_CC_PROTECT_MODE_REG_WRITE_ENABLE                     , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( C_CC_PROTECT_MODE_REG_READ_ENABLE                       , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( C_CC_PROTECT_MODE_REG_WRITE_ENABLE                      , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( EQ_CLK_REGION_CLOCK_CMD                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD  );
REG64_FLD( EQ_CLK_REGION_CLOCK_CMD_LEN                             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD_LEN );
REG64_FLD( EQ_CLK_REGION_SLAVE_MODE                                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SLAVE_MODE );
REG64_FLD( EQ_CLK_REGION_MASTER_MODE                               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_MODE );
REG64_FLD( EQ_CLK_REGION_CLOCK_PERV                                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PERV );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT1                               , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT1 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT2                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT2 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT3                               , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT3 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT4                               , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT4 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT5                               , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT5 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT6                               , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT6 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT7                               , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT7 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT8                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT8 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT9                               , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT9 );
REG64_FLD( EQ_CLK_REGION_CLOCK_UNIT10                              , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT10 );
REG64_FLD( EQ_CLK_REGION_SEL_THOLD_SL                              , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_SL );
REG64_FLD( EQ_CLK_REGION_SEL_THOLD_NSL                             , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_NSL );
REG64_FLD( EQ_CLK_REGION_SEL_THOLD_ARY                             , 50  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ARY );
REG64_FLD( EQ_CLK_REGION_CLOCK_PULSE_USE_EVEN                      , 52  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PULSE_USE_EVEN );

REG64_FLD( EX_CLK_REGION_CLOCK_CMD                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD  );
REG64_FLD( EX_CLK_REGION_CLOCK_CMD_LEN                             , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD_LEN );
REG64_FLD( EX_CLK_REGION_SLAVE_MODE                                , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SLAVE_MODE );
REG64_FLD( EX_CLK_REGION_MASTER_MODE                               , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_MODE );
REG64_FLD( EX_CLK_REGION_CLOCK_PERV                                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PERV );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT1                               , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT1 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT2                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT2 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT3                               , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT3 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT4                               , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT4 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT5                               , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT5 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT6                               , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT6 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT7                               , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT7 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT8                               , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT8 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT9                               , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT9 );
REG64_FLD( EX_CLK_REGION_CLOCK_UNIT10                              , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT10 );
REG64_FLD( EX_CLK_REGION_SEL_THOLD_SL                              , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_SL );
REG64_FLD( EX_CLK_REGION_SEL_THOLD_NSL                             , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_NSL );
REG64_FLD( EX_CLK_REGION_SEL_THOLD_ARY                             , 50  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ARY );
REG64_FLD( EX_CLK_REGION_CLOCK_PULSE_USE_EVEN                      , 52  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PULSE_USE_EVEN );

REG64_FLD( C_CLK_REGION_CLOCK_CMD                                  , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD  );
REG64_FLD( C_CLK_REGION_CLOCK_CMD_LEN                              , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_CMD_LEN );
REG64_FLD( C_CLK_REGION_SLAVE_MODE                                 , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SLAVE_MODE );
REG64_FLD( C_CLK_REGION_MASTER_MODE                                , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MASTER_MODE );
REG64_FLD( C_CLK_REGION_CLOCK_PERV                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PERV );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT1                                , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT1 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT2                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT2 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT3                                , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT3 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT4                                , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT4 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT5                                , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT5 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT6                                , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT6 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT7                                , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT7 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT8                                , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT8 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT9                                , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT9 );
REG64_FLD( C_CLK_REGION_CLOCK_UNIT10                               , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_UNIT10 );
REG64_FLD( C_CLK_REGION_SEL_THOLD_SL                               , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_SL );
REG64_FLD( C_CLK_REGION_SEL_THOLD_NSL                              , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_NSL );
REG64_FLD( C_CLK_REGION_SEL_THOLD_ARY                              , 50  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEL_THOLD_ARY );
REG64_FLD( C_CLK_REGION_CLOCK_PULSE_USE_EVEN                       , 52  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLOCK_PULSE_USE_EVEN );

REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_PERV                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT1                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT2                          , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT3                          , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT4                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT5                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT6                          , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT7                          , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT8                          , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT9                          , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EQ_CLOCK_STAT_ARY_STATUS_UNIT10                         , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_PERV                           , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT1                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT2                          , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT3                          , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT4                          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT5                          , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT6                          , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT7                          , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT8                          , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT9                          , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EX_CLOCK_STAT_ARY_STATUS_UNIT10                         , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( C_CLOCK_STAT_ARY_STATUS_PERV                            , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT1                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT2                           , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT3                           , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT4                           , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT5                           , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT6                           , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT7                           , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT8                           , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT9                           , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( C_CLOCK_STAT_ARY_STATUS_UNIT10                          , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_PERV                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT1                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT2                          , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT3                          , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT4                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT5                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT6                          , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT7                          , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT8                          , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT9                          , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EQ_CLOCK_STAT_NSL_STATUS_UNIT10                         , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_PERV                           , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT1                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT2                          , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT3                          , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT4                          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT5                          , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT6                          , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT7                          , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT8                          , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT9                          , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EX_CLOCK_STAT_NSL_STATUS_UNIT10                         , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( C_CLOCK_STAT_NSL_STATUS_PERV                            , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT1                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT2                           , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT3                           , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT4                           , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT5                           , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT6                           , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT7                           , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT8                           , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT9                           , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( C_CLOCK_STAT_NSL_STATUS_UNIT10                          , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_PERV                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT1                           , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT2                           , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT3                           , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT4                           , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT5                           , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT6                           , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT7                           , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT8                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT9                           , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EQ_CLOCK_STAT_SL_STATUS_UNIT10                          , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EX_CLOCK_STAT_SL_STATUS_PERV                            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT1                           , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT2                           , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT3                           , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT4                           , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT5                           , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT6                           , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT7                           , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT8                           , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT9                           , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( EX_CLOCK_STAT_SL_STATUS_UNIT10                          , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( C_CLOCK_STAT_SL_STATUS_PERV                             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_PERV );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT1                            , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT1 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT2                            , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT2 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT3                            , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT3 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT4                            , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT4 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT5                            , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT5 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT6                            , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT6 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT7                            , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT7 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT8                            , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT8 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT9                            , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT9 );
REG64_FLD( C_CLOCK_STAT_SL_STATUS_UNIT10                           , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATUS_UNIT10 );

REG64_FLD( EQ_CME_LCL_EIMR_INTERRUPT_MASK                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_MASK );
REG64_FLD( EQ_CME_LCL_EIMR_INTERRUPT_MASK_LEN                      , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_MASK_LEN );

REG64_FLD( EX_CME_LCL_EIMR_INTERRUPT_MASK                          , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_MASK );
REG64_FLD( EX_CME_LCL_EIMR_INTERRUPT_MASK_LEN                      , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_MASK_LEN );

REG64_FLD( EQ_CME_LCL_EINR_INTERRUPT_INPUT                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_INPUT );
REG64_FLD( EQ_CME_LCL_EINR_INTERRUPT_INPUT_LEN                     , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_INPUT_LEN );

REG64_FLD( EX_CME_LCL_EINR_INTERRUPT_INPUT                         , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_INPUT );
REG64_FLD( EX_CME_LCL_EINR_INTERRUPT_INPUT_LEN                     , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_INPUT_LEN );

REG64_FLD( EQ_CME_LCL_EIPR_INTERRUPT_POLARITY                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_POLARITY );
REG64_FLD( EQ_CME_LCL_EIPR_INTERRUPT_POLARITY_LEN                  , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_POLARITY_LEN );

REG64_FLD( EX_CME_LCL_EIPR_INTERRUPT_POLARITY                      , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_POLARITY );
REG64_FLD( EX_CME_LCL_EIPR_INTERRUPT_POLARITY_LEN                  , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_POLARITY_LEN );

REG64_FLD( EQ_CME_LCL_EITR_INTERRUPT_TYPE                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_TYPE );
REG64_FLD( EQ_CME_LCL_EITR_INTERRUPT_TYPE_LEN                      , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_TYPE_LEN );

REG64_FLD( EX_CME_LCL_EITR_INTERRUPT_TYPE                          , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_TYPE );
REG64_FLD( EX_CME_LCL_EITR_INTERRUPT_TYPE_LEN                      , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INTERRUPT_TYPE_LEN );

REG64_FLD( EQ_CME_LCL_ICRR_COMM_RECV                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_COMM_RECV  );
REG64_FLD( EQ_CME_LCL_ICRR_COMM_RECV_LEN                           , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_COMM_RECV_LEN );

REG64_FLD( EX_CME_LCL_ICRR_COMM_RECV                               , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_COMM_RECV  );
REG64_FLD( EX_CME_LCL_ICRR_COMM_RECV_LEN                           , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_COMM_RECV_LEN );

REG64_FLD( EQ_CME_LCL_SISR_PC_UNMASKED_ATTN_C0                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_UNMASKED_ATTN_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PC_INSTR_RUNNING_C0                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_INSTR_RUNNING_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_ALL_HV_C0                      , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ALL_HV_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_ACTIVE_C0                      , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ACTIVE_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_C0                             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_C0_LEN                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C0_LEN );
REG64_FLD( EQ_CME_LCL_SISR_ALLOW_REG_WAKEUP_C0                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ALLOW_REG_WAKEUP_C0 );
REG64_FLD( EQ_CME_LCL_SISR_SPARE_9                                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_9    );
REG64_FLD( EQ_CME_LCL_SISR_PCBMUX_GRANT_C0                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBMUX_GRANT_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PCBMUX_GRANT_C1                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBMUX_GRANT_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PC_NON_HV_RUNNING_C0                    , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C0 );
REG64_FLD( EQ_CME_LCL_SISR_PC_NON_HV_RUNNING_C0_LEN                , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C0_LEN );
REG64_FLD( EQ_CME_LCL_SISR_PC_UNMASKED_ATTN_C1                     , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_UNMASKED_ATTN_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PC_INSTR_RUNNING_C1                     , 17  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_INSTR_RUNNING_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_ALL_HV_C1                      , 18  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ALL_HV_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_ACTIVE_C1                      , 19  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ACTIVE_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_C1                             , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PM_STATE_C1_LEN                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C1_LEN );
REG64_FLD( EQ_CME_LCL_SISR_ALLOW_REG_WAKEUP_C1                     , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ALLOW_REG_WAKEUP_C1 );
REG64_FLD( EQ_CME_LCL_SISR_SPARE_25_27                             , 25  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_25_27 );
REG64_FLD( EQ_CME_LCL_SISR_SPARE_25_27_LEN                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_25_27_LEN );
REG64_FLD( EQ_CME_LCL_SISR_PC_NON_HV_RUNNING_C1                    , 28  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C1 );
REG64_FLD( EQ_CME_LCL_SISR_PC_NON_HV_RUNNING_C1_LEN                , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C1_LEN );

REG64_FLD( EX_CME_LCL_SISR_PC_UNMASKED_ATTN_C0                     , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_UNMASKED_ATTN_C0 );
REG64_FLD( EX_CME_LCL_SISR_PC_INSTR_RUNNING_C0                     , 1   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_INSTR_RUNNING_C0 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_ALL_HV_C0                      , 2   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ALL_HV_C0 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_ACTIVE_C0                      , 3   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ACTIVE_C0 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_C0                             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C0 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_C0_LEN                         , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C0_LEN );
REG64_FLD( EX_CME_LCL_SISR_ALLOW_REG_WAKEUP_C0                     , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ALLOW_REG_WAKEUP_C0 );
REG64_FLD( EX_CME_LCL_SISR_SPARE_9                                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_9    );
REG64_FLD( EX_CME_LCL_SISR_PCBMUX_GRANT_C0                         , 10  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBMUX_GRANT_C0 );
REG64_FLD( EX_CME_LCL_SISR_PCBMUX_GRANT_C1                         , 11  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBMUX_GRANT_C1 );
REG64_FLD( EX_CME_LCL_SISR_PC_NON_HV_RUNNING_C0                    , 12  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C0 );
REG64_FLD( EX_CME_LCL_SISR_PC_NON_HV_RUNNING_C0_LEN                , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C0_LEN );
REG64_FLD( EX_CME_LCL_SISR_PC_UNMASKED_ATTN_C1                     , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_UNMASKED_ATTN_C1 );
REG64_FLD( EX_CME_LCL_SISR_PC_INSTR_RUNNING_C1                     , 17  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_INSTR_RUNNING_C1 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_ALL_HV_C1                      , 18  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ALL_HV_C1 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_ACTIVE_C1                      , 19  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_ACTIVE_C1 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_C1                             , 20  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C1 );
REG64_FLD( EX_CME_LCL_SISR_PM_STATE_C1_LEN                         , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PM_STATE_C1_LEN );
REG64_FLD( EX_CME_LCL_SISR_ALLOW_REG_WAKEUP_C1                     , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ALLOW_REG_WAKEUP_C1 );
REG64_FLD( EX_CME_LCL_SISR_SPARE_25_27                             , 25  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_25_27 );
REG64_FLD( EX_CME_LCL_SISR_SPARE_25_27_LEN                         , 3   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SPARE_25_27_LEN );
REG64_FLD( EX_CME_LCL_SISR_PC_NON_HV_RUNNING_C1                    , 28  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C1 );
REG64_FLD( EX_CME_LCL_SISR_PC_NON_HV_RUNNING_C1_LEN                , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PC_NON_HV_RUNNING_C1_LEN );

REG64_FLD( EQ_CME_SCOM_AFSR_INST_CYCLE_SAMPLE                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INST_CYCLE_SAMPLE );
REG64_FLD( EQ_CME_SCOM_AFSR_INST_CYCLE_SAMPLE_LEN                  , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INST_CYCLE_SAMPLE_LEN );
REG64_FLD( EQ_CME_SCOM_AFSR_AVG_CYCLE_SAMPLE                       , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_AVG_CYCLE_SAMPLE );
REG64_FLD( EQ_CME_SCOM_AFSR_AVG_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_AVG_CYCLE_SAMPLE_LEN );
REG64_FLD( EQ_CME_SCOM_AFSR_SAMPLE_VALID                           , 63  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_VALID );

REG64_FLD( EX_CME_SCOM_AFSR_INST_CYCLE_SAMPLE                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INST_CYCLE_SAMPLE );
REG64_FLD( EX_CME_SCOM_AFSR_INST_CYCLE_SAMPLE_LEN                  , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INST_CYCLE_SAMPLE_LEN );
REG64_FLD( EX_CME_SCOM_AFSR_AVG_CYCLE_SAMPLE                       , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_AVG_CYCLE_SAMPLE );
REG64_FLD( EX_CME_SCOM_AFSR_AVG_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_AVG_CYCLE_SAMPLE_LEN );
REG64_FLD( EX_CME_SCOM_AFSR_SAMPLE_VALID                           , 63  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_VALID );

REG64_FLD( EQ_CME_SCOM_AFTR_MAX_CYCLE_SAMPLE                       , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MAX_CYCLE_SAMPLE );
REG64_FLD( EQ_CME_SCOM_AFTR_MAX_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MAX_CYCLE_SAMPLE_LEN );
REG64_FLD( EQ_CME_SCOM_AFTR_MIN_CYCLE_SAMPLE                       , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MIN_CYCLE_SAMPLE );
REG64_FLD( EQ_CME_SCOM_AFTR_MIN_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MIN_CYCLE_SAMPLE_LEN );

REG64_FLD( EX_CME_SCOM_AFTR_MAX_CYCLE_SAMPLE                       , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MAX_CYCLE_SAMPLE );
REG64_FLD( EX_CME_SCOM_AFTR_MAX_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MAX_CYCLE_SAMPLE_LEN );
REG64_FLD( EX_CME_SCOM_AFTR_MIN_CYCLE_SAMPLE                       , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MIN_CYCLE_SAMPLE );
REG64_FLD( EX_CME_SCOM_AFTR_MIN_CYCLE_SAMPLE_LEN                   , 20  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MIN_CYCLE_SAMPLE_LEN );

REG64_FLD( EQ_CME_SCOM_BCEBAR0_BASE                                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE       );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_BASE_LEN                            , 36  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE_LEN   );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_RD_SCOPE                            , 57  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE   );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_RD_SCOPE_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE_LEN );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_WR_SCOPE                            , 59  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_WR_SCOPE   );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_VG_TARGET_SEL                       , 60  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VG_TARGET_SEL );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_SIZE                                , 61  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE       );
REG64_FLD( EQ_CME_SCOM_BCEBAR0_SIZE_LEN                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE_LEN   );

REG64_FLD( EX_CME_SCOM_BCEBAR0_BASE                                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE       );
REG64_FLD( EX_CME_SCOM_BCEBAR0_BASE_LEN                            , 36  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE_LEN   );
REG64_FLD( EX_CME_SCOM_BCEBAR0_RD_SCOPE                            , 57  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE   );
REG64_FLD( EX_CME_SCOM_BCEBAR0_RD_SCOPE_LEN                        , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE_LEN );
REG64_FLD( EX_CME_SCOM_BCEBAR0_WR_SCOPE                            , 59  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_WR_SCOPE   );
REG64_FLD( EX_CME_SCOM_BCEBAR0_VG_TARGET_SEL                       , 60  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VG_TARGET_SEL );
REG64_FLD( EX_CME_SCOM_BCEBAR0_SIZE                                , 61  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE       );
REG64_FLD( EX_CME_SCOM_BCEBAR0_SIZE_LEN                            , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE_LEN   );

REG64_FLD( EQ_CME_SCOM_BCEBAR1_BASE                                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE       );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_BASE_LEN                            , 36  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE_LEN   );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_RD_SCOPE                            , 57  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE   );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_RD_SCOPE_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE_LEN );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_WR_SCOPE                            , 59  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_WR_SCOPE   );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_VG_TARGET_SEL                       , 60  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VG_TARGET_SEL );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_SIZE                                , 61  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE       );
REG64_FLD( EQ_CME_SCOM_BCEBAR1_SIZE_LEN                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE_LEN   );

REG64_FLD( EX_CME_SCOM_BCEBAR1_BASE                                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE       );
REG64_FLD( EX_CME_SCOM_BCEBAR1_BASE_LEN                            , 36  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_BASE_LEN   );
REG64_FLD( EX_CME_SCOM_BCEBAR1_RD_SCOPE                            , 57  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE   );
REG64_FLD( EX_CME_SCOM_BCEBAR1_RD_SCOPE_LEN                        , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RD_SCOPE_LEN );
REG64_FLD( EX_CME_SCOM_BCEBAR1_WR_SCOPE                            , 59  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_WR_SCOPE   );
REG64_FLD( EX_CME_SCOM_BCEBAR1_VG_TARGET_SEL                       , 60  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VG_TARGET_SEL );
REG64_FLD( EX_CME_SCOM_BCEBAR1_SIZE                                , 61  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE       );
REG64_FLD( EX_CME_SCOM_BCEBAR1_SIZE_LEN                            , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SIZE_LEN   );

REG64_FLD( EQ_CME_SCOM_BCECSR_BUSY                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EQ_CME_SCOM_BCECSR_ERROR                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( EQ_CME_SCOM_BCECSR_RNW                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RNW        );
REG64_FLD( EQ_CME_SCOM_BCECSR_BARSEL                               , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BARSEL     );
REG64_FLD( EQ_CME_SCOM_BCECSR_PRIORITY                             , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRIORITY   );
REG64_FLD( EQ_CME_SCOM_BCECSR_INJECT_ERR                           , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INJECT_ERR );
REG64_FLD( EQ_CME_SCOM_BCECSR_TYPE                                 , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EQ_CME_SCOM_BCECSR_TYPE_LEN                             , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EQ_CME_SCOM_BCECSR_NUM_BLOCKS                           , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NUM_BLOCKS );
REG64_FLD( EQ_CME_SCOM_BCECSR_NUM_BLOCKS_LEN                       , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NUM_BLOCKS_LEN );
REG64_FLD( EQ_CME_SCOM_BCECSR_SBASE                                , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SBASE      );
REG64_FLD( EQ_CME_SCOM_BCECSR_SBASE_LEN                            , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SBASE_LEN  );
REG64_FLD( EQ_CME_SCOM_BCECSR_MBASE                                , 42  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MBASE      );
REG64_FLD( EQ_CME_SCOM_BCECSR_MBASE_LEN                            , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MBASE_LEN  );

REG64_FLD( EX_CME_SCOM_BCECSR_BUSY                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EX_CME_SCOM_BCECSR_ERROR                                , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( EX_CME_SCOM_BCECSR_RNW                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RNW        );
REG64_FLD( EX_CME_SCOM_BCECSR_BARSEL                               , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BARSEL     );
REG64_FLD( EX_CME_SCOM_BCECSR_PRIORITY                             , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRIORITY   );
REG64_FLD( EX_CME_SCOM_BCECSR_INJECT_ERR                           , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INJECT_ERR );
REG64_FLD( EX_CME_SCOM_BCECSR_TYPE                                 , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EX_CME_SCOM_BCECSR_TYPE_LEN                             , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EX_CME_SCOM_BCECSR_NUM_BLOCKS                           , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NUM_BLOCKS );
REG64_FLD( EX_CME_SCOM_BCECSR_NUM_BLOCKS_LEN                       , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NUM_BLOCKS_LEN );
REG64_FLD( EX_CME_SCOM_BCECSR_SBASE                                , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SBASE      );
REG64_FLD( EX_CME_SCOM_BCECSR_SBASE_LEN                            , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SBASE_LEN  );
REG64_FLD( EX_CME_SCOM_BCECSR_MBASE                                , 42  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MBASE      );
REG64_FLD( EX_CME_SCOM_BCECSR_MBASE_LEN                            , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MBASE_LEN  );

REG64_FLD( EQ_CME_SCOM_EIIR_DEBUGGER                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEBUGGER   );
REG64_FLD( EQ_CME_SCOM_EIIR_DEBUG_TRIGGER                          , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEBUG_TRIGGER );
REG64_FLD( EQ_CME_SCOM_EIIR_BCE_TIMEOUT                            , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BCE_TIMEOUT );
REG64_FLD( EQ_CME_SCOM_EIIR_PC_INTR_PENDING_C0                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PC_INTR_PENDING_C0 );
REG64_FLD( EQ_CME_SCOM_EIIR_PC_INTR_PENDING_C1                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PC_INTR_PENDING_C1 );
REG64_FLD( EQ_CME_SCOM_EIIR_SPECIAL_WAKEUP_C0                      , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WAKEUP_C0 );
REG64_FLD( EQ_CME_SCOM_EIIR_SPECIAL_WAKEUP_C1                      , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WAKEUP_C1 );
REG64_FLD( EQ_CME_SCOM_EIIR_REG_WAKEUP_C0                          , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REG_WAKEUP_C0 );
REG64_FLD( EQ_CME_SCOM_EIIR_REG_WAKEUP_C1                          , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REG_WAKEUP_C1 );
REG64_FLD( EQ_CME_SCOM_EIIR_PC_PM_STATE_ACTIVE_C0                  , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PC_PM_STATE_ACTIVE_C0 );
REG64_FLD( EQ_CME_SCOM_EIIR_PC_PM_STATE_ACTIVE_C1                  , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PC_PM_STATE_ACTIVE_C1 );
REG64_FLD( EQ_CME_SCOM_EIIR_L2_PURGE_DONE                          , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L2_PURGE_DONE );
REG64_FLD( EQ_CME_SCOM_EIIR_NCU_PURGE_DONE                         , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NCU_PURGE_DONE );
REG64_FLD( EQ_CME_SCOM_EIIR_CHTM_PURGE_DONE_C0                     , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHTM_PURGE_DONE_C0 );
REG64_FLD( EQ_CME_SCOM_EIIR_CHTM_PURGE_DONE_C1                     , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHTM_PURGE_DONE_C1 );

REG64_FLD( EX_CME_SCOM_EIIR_DEBUGGER                               , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEBUGGER   );
REG64_FLD( EX_CME_SCOM_EIIR_DEBUG_TRIGGER                          , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEBUG_TRIGGER );
REG64_FLD( EX_CME_SCOM_EIIR_BCE_TIMEOUT                            , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BCE_TIMEOUT );
REG64_FLD( EX_CME_SCOM_EIIR_PC_INTR_PENDING_C0                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_INTR_PENDING_C0 );
REG64_FLD( EX_CME_SCOM_EIIR_PC_INTR_PENDING_C1                     , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_INTR_PENDING_C1 );
REG64_FLD( EX_CME_SCOM_EIIR_SPECIAL_WAKEUP_C0                      , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WAKEUP_C0 );
REG64_FLD( EX_CME_SCOM_EIIR_SPECIAL_WAKEUP_C1                      , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WAKEUP_C1 );
REG64_FLD( EX_CME_SCOM_EIIR_REG_WAKEUP_C0                          , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REG_WAKEUP_C0 );
REG64_FLD( EX_CME_SCOM_EIIR_REG_WAKEUP_C1                          , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REG_WAKEUP_C1 );
REG64_FLD( EX_CME_SCOM_EIIR_PC_PM_STATE_ACTIVE_C0                  , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_PM_STATE_ACTIVE_C0 );
REG64_FLD( EX_CME_SCOM_EIIR_PC_PM_STATE_ACTIVE_C1                  , 21  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_PM_STATE_ACTIVE_C1 );
REG64_FLD( EX_CME_SCOM_EIIR_L2_PURGE_DONE                          , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L2_PURGE_DONE );
REG64_FLD( EX_CME_SCOM_EIIR_NCU_PURGE_DONE                         , 23  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NCU_PURGE_DONE );
REG64_FLD( EX_CME_SCOM_EIIR_CHTM_PURGE_DONE_C0                     , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHTM_PURGE_DONE_C0 );
REG64_FLD( EX_CME_SCOM_EIIR_CHTM_PURGE_DONE_C1                     , 25  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHTM_PURGE_DONE_C1 );

REG64_FLD( EQ_CME_SCOM_FLAGS_DATA                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_FLAGS_DATA_LEN                              , 32  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_FLAGS_DATA                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_FLAGS_DATA_LEN                              , 32  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_FWMR_PMCR_OVERRIDE_EN                       , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMCR_OVERRIDE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_PSCR_OVERRIDE_EN                       , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PSCR_OVERRIDE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_PMSR_OVERRIDE_EN                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMSR_OVERRIDE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_BCESCR_OVERRIDE_EN                     , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_BCESCR_OVERRIDE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_ACCR_OVERRIDE_EN                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ACCR_OVERRIDE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_VDM_LCL_SAMPLE_EN                      , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_LCL_SAMPLE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_FREQ_LCL_SAMPLE_EN                     , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FREQ_LCL_SAMPLE_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_LOCK_PCB_ON_ERR                        , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LOCK_PCB_ON_ERR );
REG64_FLD( EQ_CME_SCOM_FWMR_QUEUED_WR_EN                           , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUEUED_WR_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_QUEUED_RD_EN                           , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUEUED_RD_EN );
REG64_FLD( EQ_CME_SCOM_FWMR_MASK_PURGE_INTERFACE                   , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_MASK_PURGE_INTERFACE );
REG64_FLD( EQ_CME_SCOM_FWMR_IGNORE_PECE                            , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IGNORE_PECE );
REG64_FLD( EQ_CME_SCOM_FWMR_STOP_OVERRIDE_MODE                     , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP_OVERRIDE_MODE );
REG64_FLD( EQ_CME_SCOM_FWMR_STOP_ACTIVE_MASK                       , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP_ACTIVE_MASK );
REG64_FLD( EQ_CME_SCOM_FWMR_AUTO_STOP1_DISABLE                     , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_AUTO_STOP1_DISABLE );
REG64_FLD( EQ_CME_SCOM_FWMR_STOP1_ACTIVE_ENABLE                    , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP1_ACTIVE_ENABLE );
REG64_FLD( EQ_CME_SCOM_FWMR_FENCE_EISR                             , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FENCE_EISR );
REG64_FLD( EQ_CME_SCOM_FWMR_SPARE_21_23                            , 21  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_21_23 );
REG64_FLD( EQ_CME_SCOM_FWMR_SPARE_21_23_LEN                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_21_23_LEN );
REG64_FLD( EQ_CME_SCOM_FWMR_AVG_FREQ_TSEL                          , 24  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_AVG_FREQ_TSEL );
REG64_FLD( EQ_CME_SCOM_FWMR_AVG_FREQ_TSEL_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_AVG_FREQ_TSEL_LEN );

REG64_FLD( EX_CME_SCOM_FWMR_PMCR_OVERRIDE_EN                       , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMCR_OVERRIDE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_PSCR_OVERRIDE_EN                       , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PSCR_OVERRIDE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_PMSR_OVERRIDE_EN                       , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMSR_OVERRIDE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_BCESCR_OVERRIDE_EN                     , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_BCESCR_OVERRIDE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_ACCR_OVERRIDE_EN                       , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ACCR_OVERRIDE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_VDM_LCL_SAMPLE_EN                      , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_LCL_SAMPLE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_FREQ_LCL_SAMPLE_EN                     , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FREQ_LCL_SAMPLE_EN );
REG64_FLD( EX_CME_SCOM_FWMR_LOCK_PCB_ON_ERR                        , 7   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LOCK_PCB_ON_ERR );
REG64_FLD( EX_CME_SCOM_FWMR_QUEUED_WR_EN                           , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUEUED_WR_EN );
REG64_FLD( EX_CME_SCOM_FWMR_QUEUED_RD_EN                           , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUEUED_RD_EN );
REG64_FLD( EX_CME_SCOM_FWMR_MASK_PURGE_INTERFACE                   , 10  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_MASK_PURGE_INTERFACE );
REG64_FLD( EX_CME_SCOM_FWMR_IGNORE_PECE                            , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IGNORE_PECE );
REG64_FLD( EX_CME_SCOM_FWMR_STOP_OVERRIDE_MODE                     , 16  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP_OVERRIDE_MODE );
REG64_FLD( EX_CME_SCOM_FWMR_STOP_ACTIVE_MASK                       , 17  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP_ACTIVE_MASK );
REG64_FLD( EX_CME_SCOM_FWMR_AUTO_STOP1_DISABLE                     , 18  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_AUTO_STOP1_DISABLE );
REG64_FLD( EX_CME_SCOM_FWMR_STOP1_ACTIVE_ENABLE                    , 19  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STOP1_ACTIVE_ENABLE );
REG64_FLD( EX_CME_SCOM_FWMR_FENCE_EISR                             , 20  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FENCE_EISR );
REG64_FLD( EX_CME_SCOM_FWMR_SPARE_21_23                            , 21  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_21_23 );
REG64_FLD( EX_CME_SCOM_FWMR_SPARE_21_23_LEN                        , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_21_23_LEN );
REG64_FLD( EX_CME_SCOM_FWMR_AVG_FREQ_TSEL                          , 24  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_AVG_FREQ_TSEL );
REG64_FLD( EX_CME_SCOM_FWMR_AVG_FREQ_TSEL_LEN                      , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_AVG_FREQ_TSEL_LEN );

REG64_FLD( EQ_CME_SCOM_LFIR_PPE_INTERNAL_ERROR                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_INTERNAL_ERROR );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_EXTERNAL_ERROR                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_EXTERNAL_ERROR );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_PROGRESS_ERROR                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_PROGRESS_ERROR );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_BREAKPOINT_ERROR                   , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_BREAKPOINT_ERROR );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_WATCHDOG                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WATCHDOG );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_HALTED                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_HALTED );
REG64_FLD( EQ_CME_SCOM_LFIR_PPE_DEBUG_TRIGGER                      , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_DEBUG_TRIGGER );
REG64_FLD( EQ_CME_SCOM_LFIR_SRAM_UE                                , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_UE    );
REG64_FLD( EQ_CME_SCOM_LFIR_SRAM_CE                                , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_CE    );
REG64_FLD( EQ_CME_SCOM_LFIR_SRAM_SCRUB_ERR                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_ERR );
REG64_FLD( EQ_CME_SCOM_LFIR_BCE_ERROR                              , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_BCE_ERROR  );
REG64_FLD( EQ_CME_SCOM_LFIR_SPARE11                                , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE11    );
REG64_FLD( EQ_CME_SCOM_LFIR_FIR_PARITY_ERR_DUP                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_PARITY_ERR_DUP );
REG64_FLD( EQ_CME_SCOM_LFIR_FIR_PARITY_ERR                         , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_PARITY_ERR );

REG64_FLD( EX_CME_SCOM_LFIR_PPE_INTERNAL_ERROR                     , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_INTERNAL_ERROR );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_EXTERNAL_ERROR                     , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_EXTERNAL_ERROR );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_PROGRESS_ERROR                     , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_PROGRESS_ERROR );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_BREAKPOINT_ERROR                   , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_BREAKPOINT_ERROR );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_WATCHDOG                           , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WATCHDOG );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_HALTED                             , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_HALTED );
REG64_FLD( EX_CME_SCOM_LFIR_PPE_DEBUG_TRIGGER                      , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_DEBUG_TRIGGER );
REG64_FLD( EX_CME_SCOM_LFIR_SRAM_UE                                , 7   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_UE    );
REG64_FLD( EX_CME_SCOM_LFIR_SRAM_CE                                , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_CE    );
REG64_FLD( EX_CME_SCOM_LFIR_SRAM_SCRUB_ERR                         , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_ERR );
REG64_FLD( EX_CME_SCOM_LFIR_BCE_ERROR                              , 10  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_BCE_ERROR  );
REG64_FLD( EX_CME_SCOM_LFIR_SPARE11                                , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE11    );
REG64_FLD( EX_CME_SCOM_LFIR_FIR_PARITY_ERR_DUP                     , 12  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_PARITY_ERR_DUP );
REG64_FLD( EX_CME_SCOM_LFIR_FIR_PARITY_ERR                         , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_PARITY_ERR );

REG64_FLD( EQ_CME_SCOM_LFIRACT0_FIR_ACTION0                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION0 );
REG64_FLD( EQ_CME_SCOM_LFIRACT0_FIR_ACTION0_LEN                    , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION0_LEN );

REG64_FLD( EX_CME_SCOM_LFIRACT0_FIR_ACTION0                        , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION0 );
REG64_FLD( EX_CME_SCOM_LFIRACT0_FIR_ACTION0_LEN                    , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION0_LEN );

REG64_FLD( EQ_CME_SCOM_LFIRACT1_FIR_ACTION1                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION1 );
REG64_FLD( EQ_CME_SCOM_LFIRACT1_FIR_ACTION1_LEN                    , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION1_LEN );

REG64_FLD( EX_CME_SCOM_LFIRACT1_FIR_ACTION1                        , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION1 );
REG64_FLD( EX_CME_SCOM_LFIRACT1_FIR_ACTION1_LEN                    , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_FIR_ACTION1_LEN );

REG64_FLD( EQ_CME_SCOM_LFIRMASK_FIR_MASK                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_MASK   );
REG64_FLD( EQ_CME_SCOM_LFIRMASK_FIR_MASK_LEN                       , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_MASK_LEN );

REG64_FLD( EX_CME_SCOM_LFIRMASK_FIR_MASK                           , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_MASK   );
REG64_FLD( EX_CME_SCOM_LFIRMASK_FIR_MASK_LEN                       , 14  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_FIR_MASK_LEN );

REG64_FLD( EQ_CME_SCOM_PMCRS0_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_PMCRS0_DATA_LEN                             , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_PMCRS0_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_PMCRS0_DATA_LEN                             , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_PMCRS1_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_PMCRS1_DATA_LEN                             , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_PMCRS1_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_PMCRS1_DATA_LEN                             , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_PMSRS0_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_PMSRS0_DATA_LEN                             , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_PMSRS0_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_PMSRS0_DATA_LEN                             , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_PMSRS1_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_PMSRS1_DATA_LEN                             , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_PMSRS1_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_PMSRS1_DATA_LEN                             , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_PSCRS00_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS00_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS00_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS00_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS00_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS00_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS00_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS00_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS00_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS00_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS00_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS00_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS00_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS00_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS01_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS01_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS01_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS01_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS01_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS01_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS01_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS01_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS01_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS01_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS01_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS01_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS01_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS01_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS02_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS02_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS02_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS02_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS02_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS02_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS02_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS02_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS02_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS02_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS02_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS02_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS02_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS02_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS03_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS03_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS03_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS03_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS03_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS03_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS03_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS03_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS03_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS03_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS03_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS03_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS03_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS03_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS10_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS10_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS10_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS10_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS10_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS10_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS10_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS10_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS10_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS10_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS10_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS10_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS10_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS10_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS11_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS11_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS11_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS11_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS11_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS11_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS11_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS11_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS11_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS11_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS11_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS11_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS11_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS11_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS12_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS12_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS12_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS12_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS12_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS12_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS12_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS12_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS12_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS12_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS12_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS12_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS12_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS12_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_PSCRS13_SPARE0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EQ_CME_SCOM_PSCRS13_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS13_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EQ_CME_SCOM_PSCRS13_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS13_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EQ_CME_SCOM_PSCRS13_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EQ_CME_SCOM_PSCRS13_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EX_CME_SCOM_PSCRS13_SPARE0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SPARE0     );
REG64_FLD( EX_CME_SCOM_PSCRS13_OS_STATUS_DISABLE_A_N               , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OS_STATUS_DISABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_STATE_LOSS_ENABLE_A_N               , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STATE_LOSS_ENABLE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_EXIT_CRITERION_A_N                  , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXIT_CRITERION_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_POWER_SAVING_LIMIT_A_N              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_POWER_SAVING_LIMIT_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWER_SAVING_LIMIT_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS13_HYP_VIRT_EXIT_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_VIRT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_EXT_EBB_EXIT_ENABLE                 , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EBB_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_EXT_RESUME_EXIT_ENABLE              , 10  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_RESUME_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_EXT_EXIT_ENABLE                     , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_EXT_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_DEC_EXIT_ENABLE                     , 12  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DEC_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_HMI_EXIT_ENABLE                     , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HMI_EXIT_ENABLE );
REG64_FLD( EX_CME_SCOM_PSCRS13_LEVEL_TRANSITION_RATE_A_N           , 14  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_LEVEL_TRANSITION_RATE_A_N_LEN       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_LEVEL_TRANSITION_RATE_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS13_MAX_PROMOTE_LEVEL_A_N               , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_MAX_PROMOTE_LEVEL_A_N_LEN           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_MAX_PROMOTE_LEVEL_A_N_LEN );
REG64_FLD( EX_CME_SCOM_PSCRS13_STOP_REQUEST_LEVEL_A_N              , 20  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N );
REG64_FLD( EX_CME_SCOM_PSCRS13_STOP_REQUEST_LEVEL_A_N_LEN          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_STOP_REQUEST_LEVEL_A_N_LEN );

REG64_FLD( EQ_CME_SCOM_QFMR_TIMEBASE                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EQ_CME_SCOM_QFMR_TIMEBASE_LEN                           , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EQ_CME_SCOM_QFMR_CYCLES                                 , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLES     );
REG64_FLD( EQ_CME_SCOM_QFMR_CYCLES_LEN                             , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLES_LEN );

REG64_FLD( EX_CME_SCOM_QFMR_TIMEBASE                               , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_CME_SCOM_QFMR_TIMEBASE_LEN                           , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_CME_SCOM_QFMR_CYCLES                                 , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLES     );
REG64_FLD( EX_CME_SCOM_QFMR_CYCLES_LEN                             , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLES_LEN );

REG64_FLD( EQ_CME_SCOM_SICR_PC_ENTRY_ACK_C0                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_ENTRY_ACK_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_PC_BLOCK_INTERRUPTS_C0                 , 1   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_BLOCK_INTERRUPTS_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_PC_WAKEUP_C0                           , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_WAKEUP_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_PCBMUX_REQ_C0                          , 3   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PCBMUX_REQ_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_4_5                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_4_5 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_4_5_LEN                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_4_5_LEN );
REG64_FLD( EQ_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C0               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PCC_CORE_INTF_QUIESCE_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C0                , 7   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_CORE_INTF_QUIESCE_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_8_11                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_8_11 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_8_11_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_8_11_LEN );
REG64_FLD( EQ_CME_SCOM_SICR_PC_ENTRY_ACK_C1                        , 12  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_ENTRY_ACK_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_PC_BLOCK_INTERRUPTS_C1                 , 13  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_BLOCK_INTERRUPTS_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_PC_WAKEUP_C1                           , 14  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PC_WAKEUP_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_PCBMUX_REQ_C1                          , 15  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PCBMUX_REQ_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_16_17                         , 16  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_16_17 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_16_17_LEN                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_16_17_LEN );
REG64_FLD( EQ_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C1               , 18  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PCC_CORE_INTF_QUIESCE_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C1                , 19  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_CORE_INTF_QUIESCE_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_20_23                         , 20  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_20_23 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_20_23_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_20_23_LEN );
REG64_FLD( EQ_CME_SCOM_SICR_L2_PURGE                               , 24  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_PURGE   );
REG64_FLD( EQ_CME_SCOM_SICR_L2_PURGE_ABORT                         , 25  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_PURGE_ABORT );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED26                             , 26  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED26 );
REG64_FLD( EQ_CME_SCOM_SICR_NCU_TLBIE_QUIESCE                      , 27  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_TLBIE_QUIESCE );
REG64_FLD( EQ_CME_SCOM_SICR_NCU_PURGE                              , 28  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_PURGE  );
REG64_FLD( EQ_CME_SCOM_SICR_NCU_PURGE_ABORT                        , 29  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_PURGE_ABORT );
REG64_FLD( EQ_CME_SCOM_SICR_CHTM_PURGE_C0                          , 30  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CHTM_PURGE_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_CHTM_PURGE_C1                          , 31  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CHTM_PURGE_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_HMI_REQUEST_C0                         , 32  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_HMI_REQUEST_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_HMI_REQUEST_C1                         , 33  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_HMI_REQUEST_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_PPM_SPARE_OUT_C0                       , 34  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PPM_SPARE_OUT_C0 );
REG64_FLD( EQ_CME_SCOM_SICR_PPM_SPARE_OUT_C1                       , 35  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PPM_SPARE_OUT_C1 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_36_39                         , 36  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_36_39 );
REG64_FLD( EQ_CME_SCOM_SICR_RESERVED_36_39_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_36_39_LEN );

REG64_FLD( EX_CME_SCOM_SICR_PC_ENTRY_ACK_C0                        , 0   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_ENTRY_ACK_C0 );
REG64_FLD( EX_CME_SCOM_SICR_PC_BLOCK_INTERRUPTS_C0                 , 1   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_BLOCK_INTERRUPTS_C0 );
REG64_FLD( EX_CME_SCOM_SICR_PC_WAKEUP_C0                           , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_WAKEUP_C0 );
REG64_FLD( EX_CME_SCOM_SICR_PCBMUX_REQ_C0                          , 3   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PCBMUX_REQ_C0 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_4_5                           , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_4_5 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_4_5_LEN                       , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_4_5_LEN );
REG64_FLD( EX_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C0               , 6   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PCC_CORE_INTF_QUIESCE_C0 );
REG64_FLD( EX_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C0                , 7   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_L2_CORE_INTF_QUIESCE_C0 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_8_11                          , 8   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_8_11 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_8_11_LEN                      , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_8_11_LEN );
REG64_FLD( EX_CME_SCOM_SICR_PC_ENTRY_ACK_C1                        , 12  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_ENTRY_ACK_C1 );
REG64_FLD( EX_CME_SCOM_SICR_PC_BLOCK_INTERRUPTS_C1                 , 13  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_BLOCK_INTERRUPTS_C1 );
REG64_FLD( EX_CME_SCOM_SICR_PC_WAKEUP_C1                           , 14  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PC_WAKEUP_C1 );
REG64_FLD( EX_CME_SCOM_SICR_PCBMUX_REQ_C1                          , 15  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PCBMUX_REQ_C1 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_16_17                         , 16  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_16_17 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_16_17_LEN                     , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_16_17_LEN );
REG64_FLD( EX_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C1               , 18  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PCC_CORE_INTF_QUIESCE_C1 );
REG64_FLD( EX_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C1                , 19  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_L2_CORE_INTF_QUIESCE_C1 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_20_23                         , 20  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_20_23 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_20_23_LEN                     , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_20_23_LEN );
REG64_FLD( EX_CME_SCOM_SICR_L2_PURGE                               , 24  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_L2_PURGE   );
REG64_FLD( EX_CME_SCOM_SICR_L2_PURGE_ABORT                         , 25  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_L2_PURGE_ABORT );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED26                             , 26  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED26 );
REG64_FLD( EX_CME_SCOM_SICR_NCU_TLBIE_QUIESCE                      , 27  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_TLBIE_QUIESCE );
REG64_FLD( EX_CME_SCOM_SICR_NCU_PURGE                              , 28  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_PURGE  );
REG64_FLD( EX_CME_SCOM_SICR_NCU_PURGE_ABORT                        , 29  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_NCU_PURGE_ABORT );
REG64_FLD( EX_CME_SCOM_SICR_CHTM_PURGE_C0                          , 30  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_CHTM_PURGE_C0 );
REG64_FLD( EX_CME_SCOM_SICR_CHTM_PURGE_C1                          , 31  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_CHTM_PURGE_C1 );
REG64_FLD( EX_CME_SCOM_SICR_HMI_REQUEST_C0                         , 32  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_HMI_REQUEST_C0 );
REG64_FLD( EX_CME_SCOM_SICR_HMI_REQUEST_C1                         , 33  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_HMI_REQUEST_C1 );
REG64_FLD( EX_CME_SCOM_SICR_PPM_SPARE_OUT_C0                       , 34  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PPM_SPARE_OUT_C0 );
REG64_FLD( EX_CME_SCOM_SICR_PPM_SPARE_OUT_C1                       , 35  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_PPM_SPARE_OUT_C1 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_36_39                         , 36  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_36_39 );
REG64_FLD( EX_CME_SCOM_SICR_RESERVED_36_39_LEN                     , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_36_39_LEN );

REG64_FLD( EQ_CME_SCOM_SRTCH0_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_SRTCH0_DATA_LEN                             , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_SRTCH0_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_SRTCH0_DATA_LEN                             , 32  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_SRTCH1_DATA                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_CME_SCOM_SRTCH1_DATA_LEN                             , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CME_SCOM_SRTCH1_DATA                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_CME_SCOM_SRTCH1_DATA_LEN                             , 32  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_VDM_CONTROL_SUMMARY            , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_VDM_CONTROL_SUMMARY );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_VDM_CONTROL_SUMMARY_LEN        , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_VDM_CONTROL_SUMMARY_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CACHE_VDM_DATA                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CACHE_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CACHE_VDM_DATA_LEN             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CACHE_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE0_VDM_DATA                 , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE0_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE0_VDM_DATA_LEN             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE0_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE1_VDM_DATA                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE1_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE1_VDM_DATA_LEN             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE1_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE2_VDM_DATA                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE2_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE2_VDM_DATA_LEN             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE2_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE3_VDM_DATA                 , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE3_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_INSTANT_CORE3_VDM_DATA_LEN             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE3_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_VDM_CONTROL_SUMMARY             , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_VDM_CONTROL_SUMMARY );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_VDM_CONTROL_SUMMARY_LEN         , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_VDM_CONTROL_SUMMARY_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CACHE_VDM_DATA                  , 36  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CACHE_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CACHE_VDM_DATA_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CACHE_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE0_VDM_DATA                  , 40  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE0_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE0_VDM_DATA_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE0_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE1_VDM_DATA                  , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE1_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE1_VDM_DATA_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE1_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE2_VDM_DATA                  , 48  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE2_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE2_VDM_DATA_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE2_VDM_DATA_LEN );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE3_VDM_DATA                  , 52  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE3_VDM_DATA );
REG64_FLD( EQ_CME_SCOM_VDSR_STICKY_CORE3_VDM_DATA_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE3_VDM_DATA_LEN );

REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_VDM_CONTROL_SUMMARY            , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_VDM_CONTROL_SUMMARY );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_VDM_CONTROL_SUMMARY_LEN        , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_VDM_CONTROL_SUMMARY_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CACHE_VDM_DATA                 , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CACHE_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CACHE_VDM_DATA_LEN             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CACHE_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE0_VDM_DATA                 , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE0_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE0_VDM_DATA_LEN             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE0_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE1_VDM_DATA                 , 12  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE1_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE1_VDM_DATA_LEN             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE1_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE2_VDM_DATA                 , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE2_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE2_VDM_DATA_LEN             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE2_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE3_VDM_DATA                 , 20  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE3_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_INSTANT_CORE3_VDM_DATA_LEN             , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_INSTANT_CORE3_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_VDM_CONTROL_SUMMARY             , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_VDM_CONTROL_SUMMARY );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_VDM_CONTROL_SUMMARY_LEN         , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_VDM_CONTROL_SUMMARY_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CACHE_VDM_DATA                  , 36  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CACHE_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CACHE_VDM_DATA_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CACHE_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE0_VDM_DATA                  , 40  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE0_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE0_VDM_DATA_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE0_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE1_VDM_DATA                  , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE1_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE1_VDM_DATA_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE1_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE2_VDM_DATA                  , 48  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE2_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE2_VDM_DATA_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE2_VDM_DATA_LEN );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE3_VDM_DATA                  , 52  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE3_VDM_DATA );
REG64_FLD( EX_CME_SCOM_VDSR_STICKY_CORE3_VDM_DATA_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STICKY_CORE3_VDM_DATA_LEN );

REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_EXTREME_DROOP_CTR                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_EXTREME_DROOP_CTR );
REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_EXTREME_DROOP_CTR_LEN             , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_EXTREME_DROOP_CTR_LEN );
REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_LARGE_DROOP_CTR                   , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_LARGE_DROOP_CTR );
REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_LARGE_DROOP_CTR_LEN               , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_LARGE_DROOP_CTR_LEN );
REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_SMALL_DROOP_CTR                   , 40  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_SMALL_DROOP_CTR );
REG64_FLD( EQ_CME_SCOM_VTSR0_VDM_SMALL_DROOP_CTR_LEN               , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_SMALL_DROOP_CTR_LEN );

REG64_FLD( EX_CME_SCOM_VTSR0_VDM_EXTREME_DROOP_CTR                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_EXTREME_DROOP_CTR );
REG64_FLD( EX_CME_SCOM_VTSR0_VDM_EXTREME_DROOP_CTR_LEN             , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_EXTREME_DROOP_CTR_LEN );
REG64_FLD( EX_CME_SCOM_VTSR0_VDM_LARGE_DROOP_CTR                   , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_LARGE_DROOP_CTR );
REG64_FLD( EX_CME_SCOM_VTSR0_VDM_LARGE_DROOP_CTR_LEN               , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_LARGE_DROOP_CTR_LEN );
REG64_FLD( EX_CME_SCOM_VTSR0_VDM_SMALL_DROOP_CTR                   , 40  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_SMALL_DROOP_CTR );
REG64_FLD( EX_CME_SCOM_VTSR0_VDM_SMALL_DROOP_CTR_LEN               , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_SMALL_DROOP_CTR_LEN );

REG64_FLD( EQ_CME_SCOM_VTSR1_VDM_NO_DROOP_CTR                      , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_NO_DROOP_CTR );
REG64_FLD( EQ_CME_SCOM_VTSR1_VDM_NO_DROOP_CTR_LEN                  , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_NO_DROOP_CTR_LEN );
REG64_FLD( EQ_CME_SCOM_VTSR1_VDM_OVERVOLT_CTR                      , 40  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_OVERVOLT_CTR );
REG64_FLD( EQ_CME_SCOM_VTSR1_VDM_OVERVOLT_CTR_LEN                  , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_OVERVOLT_CTR_LEN );

REG64_FLD( EX_CME_SCOM_VTSR1_VDM_NO_DROOP_CTR                      , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_NO_DROOP_CTR );
REG64_FLD( EX_CME_SCOM_VTSR1_VDM_NO_DROOP_CTR_LEN                  , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_NO_DROOP_CTR_LEN );
REG64_FLD( EX_CME_SCOM_VTSR1_VDM_OVERVOLT_CTR                      , 40  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_OVERVOLT_CTR );
REG64_FLD( EX_CME_SCOM_VTSR1_VDM_OVERVOLT_CTR_LEN                  , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDM_OVERVOLT_CTR_LEN );

REG64_FLD( EQ_CME_SCOM_XIPCBQ0_PCBQ_N_INFO                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO );
REG64_FLD( EQ_CME_SCOM_XIPCBQ0_PCBQ_N_INFO_LEN                     , 26  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO_LEN );

REG64_FLD( EX_CME_SCOM_XIPCBQ0_PCBQ_N_INFO                         , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO );
REG64_FLD( EX_CME_SCOM_XIPCBQ0_PCBQ_N_INFO_LEN                     , 26  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO_LEN );

REG64_FLD( EQ_CME_SCOM_XIPCBQ1_PCBQ_N_INFO                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO );
REG64_FLD( EQ_CME_SCOM_XIPCBQ1_PCBQ_N_INFO_LEN                     , 26  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO_LEN );

REG64_FLD( EX_CME_SCOM_XIPCBQ1_PCBQ_N_INFO                         , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO );
REG64_FLD( EX_CME_SCOM_XIPCBQ1_PCBQ_N_INFO_LEN                     , 26  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCBQ_N_INFO_LEN );

REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_6C                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_6C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_7C                               , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_7C );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_14C                              , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_14C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_15C                              , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_15C );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC                   , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_22C                              , 22  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_22C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_23C                              , 23  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_23C );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC                   , 24  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN               , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_30C                              , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_30C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_31C                              , 31  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_31C );
REG64_FLD( EQ_CPLT_CONF0_CTRL_CC_OFLOW_FEH_SEL_DC                  , 32  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OFLOW_FEH_SEL_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC                   , 33  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SCAN_PROTECT_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_CC_SDIS_DC_N                         , 34  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SDIS_DC_N );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_TEST_CONTROL_35C                 , 35  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_35C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_TEST_CONTROL_36C                 , 36  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_36C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_TEST_CONTROL_37C                 , 37  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_37C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_TEST_CONTROL_38C                 , 38  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_38C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_TEST_CONTROL_39C                 , 39  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_39C );
REG64_FLD( EQ_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC             , 40  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_EPS_MASK_VITL_PCB_ERR_DC );
REG64_FLD( EQ_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC        , 41  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC );
REG64_FLD( EQ_CPLT_CONF0_ERR501                                    , 42  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_ERR501     );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_43C                              , 43  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43C );
REG64_FLD( EQ_CPLT_CONF0_FREE_USAGE_44C                            , 44  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_44C );
REG64_FLD( EQ_CPLT_CONF0_FREE_USAGE_45C                            , 45  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_45C );
REG64_FLD( EQ_CPLT_CONF0_FREE_USAGE_46C                            , 46  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_46C );
REG64_FLD( EQ_CPLT_CONF0_FREE_USAGE_47C                            , 47  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_47C );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_GROUP_ID_DC                       , 48  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_GROUP_ID_DC_LEN                   , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_CHIP_ID_DC                        , 52  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_ID_55C                           , 55  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_55C );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_SYS_ID_DC                         , 56  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC );
REG64_FLD( EQ_CPLT_CONF0_TC_UNIT_SYS_ID_DC_LEN                     , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC_LEN );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_ID_61C                           , 61  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_61C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_ID_62C                           , 62  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_62C );
REG64_FLD( EQ_CPLT_CONF0_RESERVED_ID_63C                           , 63  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_63C );

REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC                   , 0   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN               , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_6C                               , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_6C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_7C                               , 7   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_7C );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC                   , 8   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN               , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_14C                              , 14  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_14C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_15C                              , 15  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_15C );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC                   , 16  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN               , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_22C                              , 22  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_22C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_23C                              , 23  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_23C );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC                   , 24  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN               , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_30C                              , 30  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_30C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_31C                              , 31  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_31C );
REG64_FLD( EX_CPLT_CONF0_CTRL_CC_OFLOW_FEH_SEL_DC                  , 32  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OFLOW_FEH_SEL_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC                   , 33  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SCAN_PROTECT_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_CC_SDIS_DC_N                         , 34  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SDIS_DC_N );
REG64_FLD( EX_CPLT_CONF0_RESERVED_TEST_CONTROL_35C                 , 35  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_35C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_TEST_CONTROL_36C                 , 36  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_36C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_TEST_CONTROL_37C                 , 37  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_37C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_TEST_CONTROL_38C                 , 38  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_38C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_TEST_CONTROL_39C                 , 39  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_39C );
REG64_FLD( EX_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC             , 40  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_EPS_MASK_VITL_PCB_ERR_DC );
REG64_FLD( EX_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC        , 41  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC );
REG64_FLD( EX_CPLT_CONF0_ERR501                                    , 42  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_ERR501     );
REG64_FLD( EX_CPLT_CONF0_RESERVED_43C                              , 43  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43C );
REG64_FLD( EX_CPLT_CONF0_FREE_USAGE_44C                            , 44  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_44C );
REG64_FLD( EX_CPLT_CONF0_FREE_USAGE_45C                            , 45  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_45C );
REG64_FLD( EX_CPLT_CONF0_FREE_USAGE_46C                            , 46  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_46C );
REG64_FLD( EX_CPLT_CONF0_FREE_USAGE_47C                            , 47  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_47C );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_GROUP_ID_DC                       , 48  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_GROUP_ID_DC_LEN                   , 4   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_CHIP_ID_DC                        , 52  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN                    , 3   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_ID_55C                           , 55  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_55C );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_SYS_ID_DC                         , 56  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC );
REG64_FLD( EX_CPLT_CONF0_TC_UNIT_SYS_ID_DC_LEN                     , 5   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC_LEN );
REG64_FLD( EX_CPLT_CONF0_RESERVED_ID_61C                           , 61  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_61C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_ID_62C                           , 62  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_62C );
REG64_FLD( EX_CPLT_CONF0_RESERVED_ID_63C                           , 63  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_63C );

REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC                    , 0   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN                , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE0_SEL_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_6C                                , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_6C );
REG64_FLD( C_CPLT_CONF0_RESERVED_7C                                , 7   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_7C );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC                    , 8   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN                , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE1_SEL_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_14C                               , 14  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_14C );
REG64_FLD( C_CPLT_CONF0_RESERVED_15C                               , 15  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_15C );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC                    , 16  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN                , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE2_SEL_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_22C                               , 22  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_22C );
REG64_FLD( C_CPLT_CONF0_RESERVED_23C                               , 23  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_23C );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC                    , 24  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN                , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_PROBE3_SEL_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_30C                               , 30  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_30C );
REG64_FLD( C_CPLT_CONF0_RESERVED_31C                               , 31  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_31C );
REG64_FLD( C_CPLT_CONF0_CTRL_CC_OFLOW_FEH_SEL_DC                   , 32  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OFLOW_FEH_SEL_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC                    , 33  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SCAN_PROTECT_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_CC_SDIS_DC_N                          , 34  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SDIS_DC_N );
REG64_FLD( C_CPLT_CONF0_RESERVED_TEST_CONTROL_35C                  , 35  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_35C );
REG64_FLD( C_CPLT_CONF0_RESERVED_TEST_CONTROL_36C                  , 36  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_36C );
REG64_FLD( C_CPLT_CONF0_RESERVED_TEST_CONTROL_37C                  , 37  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_37C );
REG64_FLD( C_CPLT_CONF0_RESERVED_TEST_CONTROL_38C                  , 38  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_38C );
REG64_FLD( C_CPLT_CONF0_RESERVED_TEST_CONTROL_39C                  , 39  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_TEST_CONTROL_39C );
REG64_FLD( C_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC              , 40  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_EPS_MASK_VITL_PCB_ERR_DC );
REG64_FLD( C_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC         , 41  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC );
REG64_FLD( C_CPLT_CONF0_ERR501                                     , 42  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_ERR501     );
REG64_FLD( C_CPLT_CONF0_RESERVED_43C                               , 43  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43C );
REG64_FLD( C_CPLT_CONF0_FREE_USAGE_44C                             , 44  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_44C );
REG64_FLD( C_CPLT_CONF0_FREE_USAGE_45C                             , 45  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_45C );
REG64_FLD( C_CPLT_CONF0_FREE_USAGE_46C                             , 46  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_46C );
REG64_FLD( C_CPLT_CONF0_FREE_USAGE_47C                             , 47  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_47C );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_GROUP_ID_DC                        , 48  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_GROUP_ID_DC_LEN                    , 4   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_GROUP_ID_DC_LEN );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_CHIP_ID_DC                         , 52  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN                     , 3   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CHIP_ID_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_ID_55C                            , 55  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_55C );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_SYS_ID_DC                          , 56  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC );
REG64_FLD( C_CPLT_CONF0_TC_UNIT_SYS_ID_DC_LEN                      , 5   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYS_ID_DC_LEN );
REG64_FLD( C_CPLT_CONF0_RESERVED_ID_61C                            , 61  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_61C );
REG64_FLD( C_CPLT_CONF0_RESERVED_ID_62C                            , 62  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_62C );
REG64_FLD( C_CPLT_CONF0_RESERVED_ID_63C                            , 63  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_ID_63C );

REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_EQ                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_EQ );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_EQ_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_EQ_LEN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_PWR_UP                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_PWR_UP );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_PWR_UP_LEN              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_PWR_UP_LEN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_PWR_DN                  , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_PWR_DN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_PWR_DN_LEN              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_PWR_DN_LEN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_L3_UP                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_L3_UP );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_L3_UP_LEN               , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_L3_UP_LEN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_L3_DN                   , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_L3_DN );
REG64_FLD( EQ_CPLT_CONF1_TCEP_AMUX_VSELECT_L3_DN_LEN               , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TCEP_AMUX_VSELECT_L3_DN_LEN );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_16D                            , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_16D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_17D                            , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_17D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_18D                            , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_18D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_19D                            , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_19D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_20D                            , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_20D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_21D                            , 21  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_21D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_22D                            , 22  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_22D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_23D                            , 23  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_23D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_24D                            , 24  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_24D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_25D                            , 25  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_25D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_26D                            , 26  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_26D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_27D                            , 27  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_27D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_28D                            , 28  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_28D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_29D                            , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_29D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_30D                            , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_30D );
REG64_FLD( EQ_CPLT_CONF1_FREE_USAGE_31D                            , 31  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_31D );

REG64_FLD( EX_CPLT_CONF1_UNUSED_0D                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0D  );
REG64_FLD( EX_CPLT_CONF1_UNUSED_1D                                 , 1   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1D  );
REG64_FLD( EX_CPLT_CONF1_UNUSED_2D                                 , 2   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2D  );
REG64_FLD( EX_CPLT_CONF1_UNUSED_3D                                 , 3   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_3D  );
REG64_FLD( EX_CPLT_CONF1_IOVALID_4D                                , 4   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_4D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_5D                                , 5   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_5D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_6D                                , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_6D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_7D                                , 7   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_7D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_8D                                , 8   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_8D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_9D                                , 9   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_9D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_10D                               , 10  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_10D );
REG64_FLD( EX_CPLT_CONF1_IOVALID_11D                               , 11  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_11D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_12D                            , 12  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_12D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_13D                            , 13  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_13D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_14D                            , 14  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_14D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_15D                            , 15  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_15D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_16D                            , 16  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_16D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_17D                            , 17  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_17D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_18D                            , 18  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_18D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_19D                            , 19  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_19D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_20D                            , 20  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_20D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_21D                            , 21  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_21D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_22D                            , 22  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_22D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_23D                            , 23  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_23D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_24D                            , 24  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_24D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_25D                            , 25  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_25D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_26D                            , 26  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_26D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_27D                            , 27  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_27D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_28D                            , 28  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_28D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_29D                            , 29  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_29D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_30D                            , 30  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_30D );
REG64_FLD( EX_CPLT_CONF1_FREE_USAGE_31D                            , 31  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_31D );

REG64_FLD( C_CPLT_CONF1_UNUSED_0D                                  , 0   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0D  );
REG64_FLD( C_CPLT_CONF1_UNUSED_1D                                  , 1   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1D  );
REG64_FLD( C_CPLT_CONF1_UNUSED_2D                                  , 2   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2D  );
REG64_FLD( C_CPLT_CONF1_UNUSED_3D                                  , 3   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_3D  );
REG64_FLD( C_CPLT_CONF1_IOVALID_4D                                 , 4   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_4D );
REG64_FLD( C_CPLT_CONF1_IOVALID_5D                                 , 5   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_5D );
REG64_FLD( C_CPLT_CONF1_IOVALID_6D                                 , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_6D );
REG64_FLD( C_CPLT_CONF1_IOVALID_7D                                 , 7   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_7D );
REG64_FLD( C_CPLT_CONF1_IOVALID_8D                                 , 8   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_8D );
REG64_FLD( C_CPLT_CONF1_IOVALID_9D                                 , 9   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_9D );
REG64_FLD( C_CPLT_CONF1_IOVALID_10D                                , 10  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_10D );
REG64_FLD( C_CPLT_CONF1_IOVALID_11D                                , 11  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_IOVALID_11D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_12D                             , 12  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_12D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_13D                             , 13  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_13D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_14D                             , 14  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_14D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_15D                             , 15  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_15D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_16D                             , 16  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_16D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_17D                             , 17  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_17D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_18D                             , 18  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_18D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_19D                             , 19  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_19D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_20D                             , 20  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_20D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_21D                             , 21  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_21D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_22D                             , 22  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_22D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_23D                             , 23  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_23D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_24D                             , 24  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_24D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_25D                             , 25  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_25D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_26D                             , 26  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_26D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_27D                             , 27  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_27D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_28D                             , 28  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_28D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_29D                             , 29  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_29D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_30D                             , 30  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_30D );
REG64_FLD( C_CPLT_CONF1_FREE_USAGE_31D                             , 31  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_31D );

REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABSTCLK_MUXSEL_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC                 , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYNCCLK_MUXSEL_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FLUSHMODE_INH_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FORCE_ALIGN_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC                   , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_ARY_WRT_THRU_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_AVP_MODE                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_AVP_MODE );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_6A                             , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_6A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_7A                             , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_7A );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC            , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABIST_RECOV_DISABLE_DC );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_9A                             , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_9A );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC          , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_11A                              , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_11A );
REG64_FLD( EQ_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC                      , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_SKIT_MODE_BIST_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC      , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC             , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CONSTRAIN_SAFESCAN_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC               , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_RRFA_TEST_ENABLE_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_NBTI_HDR_ENABLE_OVR_DC                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_HDR_ENABLE_OVR_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_NBTI_PROBE_GATE_DC                     , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_PROBE_GATE_DC );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_18A                              , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_18A );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_19A                              , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_19A );
REG64_FLD( EQ_CPLT_CTRL0_TC_PSRO_SEL_DC                            , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CTRL0_TC_BSC_WRAPSEL_DC                         , 28  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_WRAPSEL_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_BSC_INTMODE_DC                         , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INTMODE_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_BSC_INV_DC                             , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INV_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_BSC_EXTMODE_DC                         , 31  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_EXTMODE_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_REFCLK_DRVR_EN_DC                      , 32  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REFCLK_DRVR_EN_DC );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_33A                              , 33  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_33A );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_34A                              , 34  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_34A );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_35A                              , 35  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_35A );
REG64_FLD( EQ_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC                  , 36  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_EDGE_DELAYED_DC );
REG64_FLD( EQ_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC                   , 37  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_ALIGN_FLUSH_DC );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_38A                              , 38  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_38A );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_39A                              , 39  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_39A );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC                   , 40  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN               , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC_LEN );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_42A                              , 42  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_42A );
REG64_FLD( EQ_CPLT_CTRL0_RESERVED_43A                              , 43  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43A );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_DCTEST_DC                         , 44  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_DCTEST_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC                    , 45  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OTP_PRGMODE_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC                  , 46  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SSS_CALIBRATE_DC );
REG64_FLD( EQ_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC                      , 47  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_PIN_LBIST_DC );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_48A                            , 48  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_48A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_49A                            , 49  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_49A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_50A                            , 50  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_50A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_51A                            , 51  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_51A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_52A                            , 52  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_52A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_53A                            , 53  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_53A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_54A                            , 54  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_54A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_55A                            , 55  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_55A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_56A                            , 56  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_56A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_57A                            , 57  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_57A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_58A                            , 58  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_58A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_59A                            , 59  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_59A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_60A                            , 60  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_60A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_61A                            , 61  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_61A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_62A                            , 62  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_62A );
REG64_FLD( EQ_CPLT_CTRL0_FREE_USAGE_63A                            , 63  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_63A );

REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC                 , 0   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABSTCLK_MUXSEL_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC                 , 1   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYNCCLK_MUXSEL_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC                  , 2   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FLUSHMODE_INH_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC                    , 3   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FORCE_ALIGN_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC                   , 4   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_ARY_WRT_THRU_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_AVP_MODE                          , 5   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_AVP_MODE );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_6A                             , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_6A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_7A                             , 7   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_7A );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC            , 8   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABIST_RECOV_DISABLE_DC );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_9A                             , 9   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_9A );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC          , 10  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_11A                              , 11  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_11A );
REG64_FLD( EX_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC                      , 12  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_SKIT_MODE_BIST_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC      , 13  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC             , 14  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CONSTRAIN_SAFESCAN_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC               , 15  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_RRFA_TEST_ENABLE_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_NBTI_HDR_ENABLE_OVR_DC                 , 16  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_HDR_ENABLE_OVR_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_NBTI_PROBE_GATE_DC                     , 17  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_PROBE_GATE_DC );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_18A                              , 18  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_18A );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_19A                              , 19  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_19A );
REG64_FLD( EX_CPLT_CTRL0_TC_PSRO_SEL_DC                            , 20  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN                        , 8   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CTRL0_TC_BSC_WRAPSEL_DC                         , 28  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_WRAPSEL_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_BSC_INTMODE_DC                         , 29  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INTMODE_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_BSC_INV_DC                             , 30  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INV_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_BSC_EXTMODE_DC                         , 31  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_EXTMODE_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_REFCLK_DRVR_EN_DC                      , 32  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REFCLK_DRVR_EN_DC );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_33A                              , 33  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_33A );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_34A                              , 34  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_34A );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_35A                              , 35  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_35A );
REG64_FLD( EX_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC                  , 36  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_EDGE_DELAYED_DC );
REG64_FLD( EX_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC                   , 37  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_ALIGN_FLUSH_DC );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_38A                              , 38  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_38A );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_39A                              , 39  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_39A );
REG64_FLD( EX_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC                   , 40  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN               , 2   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC_LEN );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_42A                              , 42  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_42A );
REG64_FLD( EX_CPLT_CTRL0_RESERVED_43A                              , 43  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43A );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_DCTEST_DC                         , 44  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_DCTEST_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC                    , 45  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OTP_PRGMODE_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC                  , 46  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SSS_CALIBRATE_DC );
REG64_FLD( EX_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC                      , 47  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_PIN_LBIST_DC );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_48A                            , 48  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_48A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_49A                            , 49  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_49A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_50A                            , 50  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_50A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_51A                            , 51  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_51A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_52A                            , 52  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_52A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_53A                            , 53  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_53A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_54A                            , 54  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_54A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_55A                            , 55  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_55A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_56A                            , 56  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_56A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_57A                            , 57  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_57A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_58A                            , 58  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_58A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_59A                            , 59  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_59A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_60A                            , 60  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_60A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_61A                            , 61  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_61A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_62A                            , 62  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_62A );
REG64_FLD( EX_CPLT_CTRL0_FREE_USAGE_63A                            , 63  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_63A );

REG64_FLD( C_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC                  , 0   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABSTCLK_MUXSEL_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC                  , 1   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_SYNCCLK_MUXSEL_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC                   , 2   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FLUSHMODE_INH_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC                     , 3   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_FORCE_ALIGN_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC                    , 4   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_ARY_WRT_THRU_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_AVP_MODE                           , 5   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_AVP_MODE );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_6A                              , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_6A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_7A                              , 7   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_7A );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC             , 8   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_ABIST_RECOV_DISABLE_DC );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_9A                              , 9   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_9A );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC           , 10  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_IOBIST_TX_WRAP_ENABLE_DC );
REG64_FLD( C_CPLT_CTRL0_RESERVED_11A                               , 11  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_11A );
REG64_FLD( C_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC                       , 12  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_SKIT_MODE_BIST_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC       , 13  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_DETERMINISTIC_TEST_ENABLE_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC              , 14  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_CONSTRAIN_SAFESCAN_DC );
REG64_FLD( C_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENABLE_DC                , 15  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_RRFA_TEST_ENABLE_DC );
REG64_FLD( C_CPLT_CTRL0_TC_NBTI_HDR_ENABLE_OVR_DC                  , 16  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_HDR_ENABLE_OVR_DC );
REG64_FLD( C_CPLT_CTRL0_TC_NBTI_PROBE_GATE_DC                      , 17  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_NBTI_PROBE_GATE_DC );
REG64_FLD( C_CPLT_CTRL0_RESERVED_18A                               , 18  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_18A );
REG64_FLD( C_CPLT_CTRL0_RESERVED_19A                               , 19  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_19A );
REG64_FLD( C_CPLT_CTRL0_TC_PSRO_SEL_DC                             , 20  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC );
REG64_FLD( C_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN                         , 8   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PSRO_SEL_DC_LEN );
REG64_FLD( C_CPLT_CTRL0_TC_BSC_WRAPSEL_DC                          , 28  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_WRAPSEL_DC );
REG64_FLD( C_CPLT_CTRL0_TC_BSC_INTMODE_DC                          , 29  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INTMODE_DC );
REG64_FLD( C_CPLT_CTRL0_TC_BSC_INV_DC                              , 30  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_INV_DC );
REG64_FLD( C_CPLT_CTRL0_TC_BSC_EXTMODE_DC                          , 31  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_BSC_EXTMODE_DC );
REG64_FLD( C_CPLT_CTRL0_TC_REFCLK_DRVR_EN_DC                       , 32  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REFCLK_DRVR_EN_DC );
REG64_FLD( C_CPLT_CTRL0_RESERVED_33A                               , 33  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_33A );
REG64_FLD( C_CPLT_CTRL0_RESERVED_34A                               , 34  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_34A );
REG64_FLD( C_CPLT_CTRL0_RESERVED_35A                               , 35  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_35A );
REG64_FLD( C_CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC                   , 36  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_EDGE_DELAYED_DC );
REG64_FLD( C_CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC                    , 37  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_OELCC_ALIGN_FLUSH_DC );
REG64_FLD( C_CPLT_CTRL0_RESERVED_38A                               , 38  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_38A );
REG64_FLD( C_CPLT_CTRL0_RESERVED_39A                               , 39  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_39A );
REG64_FLD( C_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC                    , 40  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN                , 2   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_MISC_CLKDIV_SEL_DC_LEN );
REG64_FLD( C_CPLT_CTRL0_RESERVED_42A                               , 42  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_42A );
REG64_FLD( C_CPLT_CTRL0_RESERVED_43A                               , 43  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED_43A );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_DCTEST_DC                          , 44  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_DCTEST_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_OTP_PRGMODE_DC                     , 45  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_OTP_PRGMODE_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC                   , 46  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_SSS_CALIBRATE_DC );
REG64_FLD( C_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC                       , 47  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_CTRL_CC_PIN_LBIST_DC );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_48A                             , 48  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_48A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_49A                             , 49  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_49A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_50A                             , 50  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_50A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_51A                             , 51  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_51A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_52A                             , 52  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_52A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_53A                             , 53  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_53A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_54A                             , 54  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_54A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_55A                             , 55  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_55A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_56A                             , 56  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_56A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_57A                             , 57  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_57A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_58A                             , 58  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_58A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_59A                             , 59  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_59A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_60A                             , 60  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_60A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_61A                             , 61  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_61A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_62A                             , 62  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_62A );
REG64_FLD( C_CPLT_CTRL0_FREE_USAGE_63A                             , 63  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_FREE_USAGE_63A );

REG64_FLD( EQ_CPLT_CTRL1_UNUSED_0B                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0B  );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_1B                                 , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1B  );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_2B                                 , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2B  );
REG64_FLD( EQ_CPLT_CTRL1_TC_VITL_REGION_FENCE                      , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_VITL_REGION_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_PERV_REGION_FENCE                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PERV_REGION_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION1_FENCE                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION1_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION2_FENCE                          , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION2_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION3_FENCE                          , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION3_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION4_FENCE                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION4_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION5_FENCE                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION5_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION6_FENCE                          , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION6_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION7_FENCE                          , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION7_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION8_FENCE                          , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION8_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_TC_REGION9_FENCE                          , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION9_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_14B                                , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_14B );
REG64_FLD( EQ_CPLT_CTRL1_RESERVED                                  , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED   );
REG64_FLD( EQ_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE             , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_MULTICYCLE_TEST_FENCE );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_17B                                , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_17B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_18B                                , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_18B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_19B                                , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_19B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_20B                                , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_20B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_21B                                , 21  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_21B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_22B                                , 22  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_22B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_23B                                , 23  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_23B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_24B                                , 24  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_24B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_25B                                , 25  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_25B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_26B                                , 26  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_26B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_27B                                , 27  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_27B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_28B                                , 28  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_28B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_29B                                , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_29B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_30B                                , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_30B );
REG64_FLD( EQ_CPLT_CTRL1_UNUSED_31B                                , 31  , SH_UNT_EQ       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_31B );

REG64_FLD( EX_CPLT_CTRL1_UNUSED_0B                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0B  );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_1B                                 , 1   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1B  );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_2B                                 , 2   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2B  );
REG64_FLD( EX_CPLT_CTRL1_TC_VITL_REGION_FENCE                      , 3   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_VITL_REGION_FENCE );
REG64_FLD( EX_CPLT_CTRL1_TC_PERV_REGION_FENCE                      , 4   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PERV_REGION_FENCE );
REG64_FLD( EX_CPLT_CTRL1_TC_REGION1_FENCE                          , 5   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION1_FENCE );
REG64_FLD( EX_CPLT_CTRL1_TC_REGION2_FENCE                          , 6   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION2_FENCE );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_7B                                 , 7   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_7B  );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_8B                                 , 8   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_8B  );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_9B                                 , 9   , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_9B  );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_10B                                , 10  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_10B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_11B                                , 11  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_11B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_12B                                , 12  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_12B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_13B                                , 13  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_13B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_14B                                , 14  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_14B );
REG64_FLD( EX_CPLT_CTRL1_RESERVED                                  , 15  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED   );
REG64_FLD( EX_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE             , 16  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_MULTICYCLE_TEST_FENCE );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_17B                                , 17  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_17B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_18B                                , 18  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_18B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_19B                                , 19  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_19B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_20B                                , 20  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_20B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_21B                                , 21  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_21B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_22B                                , 22  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_22B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_23B                                , 23  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_23B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_24B                                , 24  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_24B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_25B                                , 25  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_25B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_26B                                , 26  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_26B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_27B                                , 27  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_27B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_28B                                , 28  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_28B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_29B                                , 29  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_29B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_30B                                , 30  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_30B );
REG64_FLD( EX_CPLT_CTRL1_UNUSED_31B                                , 31  , SH_UNT_EX       , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_31B );

REG64_FLD( C_CPLT_CTRL1_UNUSED_0B                                  , 0   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_0B  );
REG64_FLD( C_CPLT_CTRL1_UNUSED_1B                                  , 1   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_1B  );
REG64_FLD( C_CPLT_CTRL1_UNUSED_2B                                  , 2   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_2B  );
REG64_FLD( C_CPLT_CTRL1_TC_VITL_REGION_FENCE                       , 3   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_VITL_REGION_FENCE );
REG64_FLD( C_CPLT_CTRL1_TC_PERV_REGION_FENCE                       , 4   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_PERV_REGION_FENCE );
REG64_FLD( C_CPLT_CTRL1_TC_REGION1_FENCE                           , 5   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION1_FENCE );
REG64_FLD( C_CPLT_CTRL1_TC_REGION2_FENCE                           , 6   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_REGION2_FENCE );
REG64_FLD( C_CPLT_CTRL1_UNUSED_7B                                  , 7   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_7B  );
REG64_FLD( C_CPLT_CTRL1_UNUSED_8B                                  , 8   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_8B  );
REG64_FLD( C_CPLT_CTRL1_UNUSED_9B                                  , 9   , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_9B  );
REG64_FLD( C_CPLT_CTRL1_UNUSED_10B                                 , 10  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_10B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_11B                                 , 11  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_11B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_12B                                 , 12  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_12B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_13B                                 , 13  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_13B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_14B                                 , 14  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_14B );
REG64_FLD( C_CPLT_CTRL1_RESERVED                                   , 15  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_RESERVED   );
REG64_FLD( C_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE              , 16  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_TC_UNIT_MULTICYCLE_TEST_FENCE );
REG64_FLD( C_CPLT_CTRL1_UNUSED_17B                                 , 17  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_17B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_18B                                 , 18  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_18B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_19B                                 , 19  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_19B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_20B                                 , 20  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_20B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_21B                                 , 21  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_21B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_22B                                 , 22  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_22B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_23B                                 , 23  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_23B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_24B                                 , 24  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_24B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_25B                                 , 25  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_25B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_26B                                 , 26  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_26B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_27B                                 , 27  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_27B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_28B                                 , 28  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_28B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_29B                                 , 29  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_29B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_30B                                 , 30  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_30B );
REG64_FLD( C_CPLT_CTRL1_UNUSED_31B                                 , 31  , SH_UNT_C        , SH_ACS_SCOM2_CLEAR,
           SH_FLD_UNUSED_31B );

REG64_FLD( EQ_CPLT_MASK0_CPLTMASK0                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0  );
REG64_FLD( EQ_CPLT_MASK0_CPLTMASK0_LEN                             , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0_LEN );

REG64_FLD( EX_CPLT_MASK0_CPLTMASK0                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0  );
REG64_FLD( EX_CPLT_MASK0_CPLTMASK0_LEN                             , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0_LEN );

REG64_FLD( C_CPLT_MASK0_CPLTMASK0                                  , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0  );
REG64_FLD( C_CPLT_MASK0_CPLTMASK0_LEN                              , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CPLTMASK0_LEN );

REG64_FLD( EQ_CPLT_STAT0_SRAM_ABIST_DONE_DC                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SRAM_ABIST_DONE_DC );
REG64_FLD( EQ_CPLT_STAT0_DRAM_ABIST_DONE_DC                        , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DRAM_ABIST_DONE_DC );
REG64_FLD( EQ_CPLT_STAT0_RESERVED_2E                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_2E );
REG64_FLD( EQ_CPLT_STAT0_RESERVED_3E                               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_3E );
REG64_FLD( EQ_CPLT_STAT0_TC_DIAG_PORT0_OUT                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT0_OUT );
REG64_FLD( EQ_CPLT_STAT0_TC_DIAG_PORT1_OUT                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT1_OUT );
REG64_FLD( EQ_CPLT_STAT0_RESERVED_6E                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6E );
REG64_FLD( EQ_CPLT_STAT0_PLL_DESTOUT                               , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PLL_DESTOUT );
REG64_FLD( EQ_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_OPCG_DONE_DC );
REG64_FLD( EQ_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC             , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_CHIPLET_IS_ALIGNED_DC );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_10E                            , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_10E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_11E                            , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_11E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_12E                            , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_12E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_13E                            , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_13E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_14E                            , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_14E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_15E                            , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_15E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_16E                            , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_16E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_17E                            , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_17E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_18E                            , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_18E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_19E                            , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_19E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_20E                            , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_20E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_21E                            , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_21E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_22E                            , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_22E );
REG64_FLD( EQ_CPLT_STAT0_FREE_USAGE_23E                            , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_23E );

REG64_FLD( EX_CPLT_STAT0_SRAM_ABIST_DONE_DC                        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SRAM_ABIST_DONE_DC );
REG64_FLD( EX_CPLT_STAT0_DRAM_ABIST_DONE_DC                        , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DRAM_ABIST_DONE_DC );
REG64_FLD( EX_CPLT_STAT0_RESERVED_2E                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_2E );
REG64_FLD( EX_CPLT_STAT0_RESERVED_3E                               , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_3E );
REG64_FLD( EX_CPLT_STAT0_TC_DIAG_PORT0_OUT                         , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT0_OUT );
REG64_FLD( EX_CPLT_STAT0_TC_DIAG_PORT1_OUT                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT1_OUT );
REG64_FLD( EX_CPLT_STAT0_RESERVED_6E                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6E );
REG64_FLD( EX_CPLT_STAT0_PLL_DESTOUT                               , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PLL_DESTOUT );
REG64_FLD( EX_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_OPCG_DONE_DC );
REG64_FLD( EX_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC             , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_CHIPLET_IS_ALIGNED_DC );
REG64_FLD( EX_CPLT_STAT0_PC_TC_VALID_NOT_HV_MODE                   , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_TC_VALID_NOT_HV_MODE );
REG64_FLD( EX_CPLT_STAT0_PC_TC_AVP_OUT                             , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PC_TC_AVP_OUT );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_12E                            , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_12E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_13E                            , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_13E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_14E                            , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_14E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_15E                            , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_15E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_16E                            , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_16E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_17E                            , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_17E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_18E                            , 18  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_18E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_19E                            , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_19E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_20E                            , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_20E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_21E                            , 21  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_21E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_22E                            , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_22E );
REG64_FLD( EX_CPLT_STAT0_FREE_USAGE_23E                            , 23  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_23E );

REG64_FLD( C_CPLT_STAT0_SRAM_ABIST_DONE_DC                         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SRAM_ABIST_DONE_DC );
REG64_FLD( C_CPLT_STAT0_DRAM_ABIST_DONE_DC                         , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DRAM_ABIST_DONE_DC );
REG64_FLD( C_CPLT_STAT0_RESERVED_2E                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_2E );
REG64_FLD( C_CPLT_STAT0_RESERVED_3E                                , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_3E );
REG64_FLD( C_CPLT_STAT0_TC_DIAG_PORT0_OUT                          , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT0_OUT );
REG64_FLD( C_CPLT_STAT0_TC_DIAG_PORT1_OUT                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TC_DIAG_PORT1_OUT );
REG64_FLD( C_CPLT_STAT0_RESERVED_6E                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6E );
REG64_FLD( C_CPLT_STAT0_PLL_DESTOUT                                , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PLL_DESTOUT );
REG64_FLD( C_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC                       , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_OPCG_DONE_DC );
REG64_FLD( C_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC              , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CC_CTRL_CHIPLET_IS_ALIGNED_DC );
REG64_FLD( C_CPLT_STAT0_PC_TC_VALID_NOT_HV_MODE                    , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PC_TC_VALID_NOT_HV_MODE );
REG64_FLD( C_CPLT_STAT0_PC_TC_AVP_OUT                              , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PC_TC_AVP_OUT );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_12E                             , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_12E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_13E                             , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_13E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_14E                             , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_14E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_15E                             , 15  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_15E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_16E                             , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_16E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_17E                             , 17  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_17E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_18E                             , 18  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_18E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_19E                             , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_19E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_20E                             , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_20E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_21E                             , 21  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_21E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_22E                             , 22  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_22E );
REG64_FLD( C_CPLT_STAT0_FREE_USAGE_23E                             , 23  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FREE_USAGE_23E );

REG64_FLD( EX_CPPM_CACCR_CLK_SB_STRENGTH                           , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_STRENGTH );
REG64_FLD( EX_CPPM_CACCR_CLK_SB_STRENGTH_LEN                       , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_STRENGTH_LEN );
REG64_FLD( EX_CPPM_CACCR_CLK_SB_SPARE                              , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_SPARE );
REG64_FLD( EX_CPPM_CACCR_CLK_SB_PULSE_MODE_EN                      , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EX_CPPM_CACCR_CLK_SB_PULSE_MODE                         , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE );
REG64_FLD( EX_CPPM_CACCR_CLK_SB_PULSE_MODE_LEN                     , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( EX_CPPM_CACCR_CLK_SW_RESCLK                             , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_RESCLK );
REG64_FLD( EX_CPPM_CACCR_CLK_SW_RESCLK_LEN                         , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_RESCLK_LEN );
REG64_FLD( EX_CPPM_CACCR_CLK_SW_SPARE                              , 12  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_SPARE );
REG64_FLD( EX_CPPM_CACCR_QUAD_CLK_SB_OVERRIDE                      , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUAD_CLK_SB_OVERRIDE );
REG64_FLD( EX_CPPM_CACCR_QUAD_CLK_SW_OVERRIDE                      , 14  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_QUAD_CLK_SW_OVERRIDE );
REG64_FLD( EX_CPPM_CACCR_CLK_SYNC_ENABLE                           , 15  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SYNC_ENABLE );

REG64_FLD( C_CPPM_CACCR_CLK_SB_STRENGTH                            , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_STRENGTH );
REG64_FLD( C_CPPM_CACCR_CLK_SB_STRENGTH_LEN                        , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_STRENGTH_LEN );
REG64_FLD( C_CPPM_CACCR_CLK_SB_SPARE                               , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_SPARE );
REG64_FLD( C_CPPM_CACCR_CLK_SB_PULSE_MODE_EN                       , 5   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE_EN );
REG64_FLD( C_CPPM_CACCR_CLK_SB_PULSE_MODE                          , 6   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE );
REG64_FLD( C_CPPM_CACCR_CLK_SB_PULSE_MODE_LEN                      , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( C_CPPM_CACCR_CLK_SW_RESCLK                              , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_RESCLK );
REG64_FLD( C_CPPM_CACCR_CLK_SW_RESCLK_LEN                          , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_RESCLK_LEN );
REG64_FLD( C_CPPM_CACCR_CLK_SW_SPARE                               , 12  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SW_SPARE );
REG64_FLD( C_CPPM_CACCR_QUAD_CLK_SB_OVERRIDE                       , 13  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_QUAD_CLK_SB_OVERRIDE );
REG64_FLD( C_CPPM_CACCR_QUAD_CLK_SW_OVERRIDE                       , 14  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_QUAD_CLK_SW_OVERRIDE );
REG64_FLD( C_CPPM_CACCR_CLK_SYNC_ENABLE                            , 15  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLK_SYNC_ENABLE );

REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_STRENGTH                    , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_STRENGTH );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_STRENGTH_LEN                , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_STRENGTH_LEN );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_SPARE                       , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_SPARE );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE_EN               , 5   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE                  , 6   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE_LEN              , 2   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SW_RESCLK                      , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_RESCLK );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SW_RESCLK_LEN                  , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_RESCLK_LEN );
REG64_FLD( EX_CPPM_CACSR_ACTUAL_CLK_SW_SPARE                       , 12  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_SPARE );
REG64_FLD( EX_CPPM_CACSR_CLK_SYNC_DONE                             , 13  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_CLK_SYNC_DONE );

REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_STRENGTH                     , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_STRENGTH );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_STRENGTH_LEN                 , 4   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_STRENGTH_LEN );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_SPARE                        , 4   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_SPARE );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE_EN                , 5   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE_EN );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE                   , 6   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SB_PULSE_MODE_LEN               , 2   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SW_RESCLK                       , 8   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_RESCLK );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SW_RESCLK_LEN                   , 4   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_RESCLK_LEN );
REG64_FLD( C_CPPM_CACSR_ACTUAL_CLK_SW_SPARE                        , 12  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTUAL_CLK_SW_SPARE );
REG64_FLD( C_CPPM_CACSR_CLK_SYNC_DONE                              , 13  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_CLK_SYNC_DONE );

REG64_FLD( EX_CPPM_CIVRMLCR_IVRM_LOCAL_CONTROL                     , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_LOCAL_CONTROL );
REG64_FLD( EX_CPPM_CIVRMLCR_RESERVED_1_2                           , 1   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_1_2 );
REG64_FLD( EX_CPPM_CIVRMLCR_RESERVED_1_2_LEN                       , 2   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_1_2_LEN );
REG64_FLD( EX_CPPM_CIVRMLCR_IVRM_UREG_TEST_EN                      , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_EN );
REG64_FLD( EX_CPPM_CIVRMLCR_IVRM_UREG_TEST_ID                      , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_ID );
REG64_FLD( EX_CPPM_CIVRMLCR_IVRM_UREG_TEST_ID_LEN                  , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_ID_LEN );

REG64_FLD( C_CPPM_CIVRMLCR_IVRM_LOCAL_CONTROL                      , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_LOCAL_CONTROL );
REG64_FLD( C_CPPM_CIVRMLCR_RESERVED_1_2                            , 1   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_1_2 );
REG64_FLD( C_CPPM_CIVRMLCR_RESERVED_1_2_LEN                        , 2   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_1_2_LEN );
REG64_FLD( C_CPPM_CIVRMLCR_IVRM_UREG_TEST_EN                       , 3   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_EN );
REG64_FLD( C_CPPM_CIVRMLCR_IVRM_UREG_TEST_ID                       , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_ID );
REG64_FLD( C_CPPM_CIVRMLCR_IVRM_UREG_TEST_ID_LEN                   , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_UREG_TEST_ID_LEN );

REG64_FLD( EX_CPPM_CMEDATA_DATA                                    , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA       );
REG64_FLD( EX_CPPM_CMEDATA_DATA_LEN                                , 32  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA_LEN   );

REG64_FLD( C_CPPM_CMEDATA_DATA                                     , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA       );
REG64_FLD( C_CPPM_CMEDATA_DATA_LEN                                 , 32  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_CPPM_CMEDB0_CME_MESSAGE_NUMBER0                      , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER0 );
REG64_FLD( EX_CPPM_CMEDB0_CME_MESSAGE_NUMBER0_LEN                  , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER0_LEN );
REG64_FLD( EX_CPPM_CMEDB0_CME_MESSAGE_HI                           , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_HI );
REG64_FLD( EX_CPPM_CMEDB0_CME_MESSAGE_HI_LEN                       , 56  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_HI_LEN );

REG64_FLD( C_CPPM_CMEDB0_CME_MESSAGE_NUMBER0                       , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER0 );
REG64_FLD( C_CPPM_CMEDB0_CME_MESSAGE_NUMBER0_LEN                   , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER0_LEN );
REG64_FLD( C_CPPM_CMEDB0_CME_MESSAGE_HI                            , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_HI );
REG64_FLD( C_CPPM_CMEDB0_CME_MESSAGE_HI_LEN                        , 56  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_HI_LEN );

REG64_FLD( EX_CPPM_CMEDB1_CME_MESSAGE_NUMBER_N                     , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( EX_CPPM_CMEDB1_CME_MESSAGE_NUMBER_N_LEN                 , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( C_CPPM_CMEDB1_CME_MESSAGE_NUMBER_N                      , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( C_CPPM_CMEDB1_CME_MESSAGE_NUMBER_N_LEN                  , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( EX_CPPM_CMEDB2_CME_MESSAGE_NUMBER_N                     , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( EX_CPPM_CMEDB2_CME_MESSAGE_NUMBER_N_LEN                 , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( C_CPPM_CMEDB2_CME_MESSAGE_NUMBER_N                      , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( C_CPPM_CMEDB2_CME_MESSAGE_NUMBER_N_LEN                  , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( EX_CPPM_CMEDB3_CME_MESSAGE_NUMBER_N                     , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( EX_CPPM_CMEDB3_CME_MESSAGE_NUMBER_N_LEN                 , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( C_CPPM_CMEDB3_CME_MESSAGE_NUMBER_N                      , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N );
REG64_FLD( C_CPPM_CMEDB3_CME_MESSAGE_NUMBER_N_LEN                  , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_MESSAGE_NUMBER_N_LEN );

REG64_FLD( EX_CPPM_CMEMSG_CME_MESSAGE                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_CME_MESSAGE );
REG64_FLD( EX_CPPM_CMEMSG_CME_MESSAGE_LEN                          , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_CME_MESSAGE_LEN );

REG64_FLD( C_CPPM_CMEMSG_CME_MESSAGE                               , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_CME_MESSAGE );
REG64_FLD( C_CPPM_CMEMSG_CME_MESSAGE_LEN                           , 64  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_CME_MESSAGE_LEN );

REG64_FLD( EX_CPPM_CPMMR_PPM_WRITE_DISABLE                         , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPM_WRITE_DISABLE );
REG64_FLD( EX_CPPM_CPMMR_PPM_WRITE_OVERRIDE                        , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPM_WRITE_OVERRIDE );
REG64_FLD( EX_CPPM_CPMMR_RESERVED_2_11                             , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_2_11 );
REG64_FLD( EX_CPPM_CPMMR_RESERVED_2_11_LEN                         , 10  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_2_11_LEN );
REG64_FLD( EX_CPPM_CPMMR_CME_ERR_NOTIFY_DIS                        , 12  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_ERR_NOTIFY_DIS );
REG64_FLD( EX_CPPM_CPMMR_WKUP_NOTIFY_SELECT                        , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_WKUP_NOTIFY_SELECT );
REG64_FLD( EX_CPPM_CPMMR_ENABLE_PECE                               , 14  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ENABLE_PECE );
REG64_FLD( EX_CPPM_CPMMR_CME_SPECIAL_WKUP_DONE_DIS                 , 15  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_SPECIAL_WKUP_DONE_DIS );

REG64_FLD( C_CPPM_CPMMR_PPM_WRITE_DISABLE                          , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PPM_WRITE_DISABLE );
REG64_FLD( C_CPPM_CPMMR_PPM_WRITE_OVERRIDE                         , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PPM_WRITE_OVERRIDE );
REG64_FLD( C_CPPM_CPMMR_RESERVED_2_11                              , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_2_11 );
REG64_FLD( C_CPPM_CPMMR_RESERVED_2_11_LEN                          , 10  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_2_11_LEN );
REG64_FLD( C_CPPM_CPMMR_CME_ERR_NOTIFY_DIS                         , 12  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_ERR_NOTIFY_DIS );
REG64_FLD( C_CPPM_CPMMR_WKUP_NOTIFY_SELECT                         , 13  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_WKUP_NOTIFY_SELECT );
REG64_FLD( C_CPPM_CPMMR_ENABLE_PECE                                , 14  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_ENABLE_PECE );
REG64_FLD( C_CPPM_CPMMR_CME_SPECIAL_WKUP_DONE_DIS                  , 15  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_SPECIAL_WKUP_DONE_DIS );

REG64_FLD( EX_CPPM_CSAR_SCRATCH_ATOMIC_DATA                        , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCRATCH_ATOMIC_DATA );
REG64_FLD( EX_CPPM_CSAR_SCRATCH_ATOMIC_DATA_LEN                    , 32  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCRATCH_ATOMIC_DATA_LEN );

REG64_FLD( C_CPPM_CSAR_SCRATCH_ATOMIC_DATA                         , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCRATCH_ATOMIC_DATA );
REG64_FLD( C_CPPM_CSAR_SCRATCH_ATOMIC_DATA_LEN                     , 32  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCRATCH_ATOMIC_DATA_LEN );

REG64_FLD( EX_CPPM_ERR_PCB_INTERRUPT_PROTOCOL                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_INTERRUPT_PROTOCOL );
REG64_FLD( EX_CPPM_ERR_SPECIAL_WKUP_PROTOCOL                       , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_PROTOCOL );
REG64_FLD( EX_CPPM_ERR_PFET_SEQ_PROGRAM                            , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PFET_SEQ_PROGRAM );
REG64_FLD( EX_CPPM_ERR_CLK_SYNC                                    , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLK_SYNC   );
REG64_FLD( EX_CPPM_ERR_PECE_INTR_DISABLED                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PECE_INTR_DISABLED );
REG64_FLD( EX_CPPM_ERR_DECONFIGURED_INTR                           , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DECONFIGURED_INTR );
REG64_FLD( EX_CPPM_ERR_RESERVED_6_7                                , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6_7 );
REG64_FLD( EX_CPPM_ERR_RESERVED_6_7_LEN                            , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6_7_LEN );

REG64_FLD( C_CPPM_ERR_PCB_INTERRUPT_PROTOCOL                       , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_INTERRUPT_PROTOCOL );
REG64_FLD( C_CPPM_ERR_SPECIAL_WKUP_PROTOCOL                        , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_PROTOCOL );
REG64_FLD( C_CPPM_ERR_PFET_SEQ_PROGRAM                             , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PFET_SEQ_PROGRAM );
REG64_FLD( C_CPPM_ERR_CLK_SYNC                                     , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLK_SYNC   );
REG64_FLD( C_CPPM_ERR_PECE_INTR_DISABLED                           , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PECE_INTR_DISABLED );
REG64_FLD( C_CPPM_ERR_DECONFIGURED_INTR                            , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DECONFIGURED_INTR );
REG64_FLD( C_CPPM_ERR_RESERVED_6_7                                 , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6_7 );
REG64_FLD( C_CPPM_ERR_RESERVED_6_7_LEN                             , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_6_7_LEN );

REG64_FLD( EX_CPPM_ERRMSK_RESERVED_0_7                             , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_7 );
REG64_FLD( EX_CPPM_ERRMSK_RESERVED_0_7_LEN                         , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_7_LEN );

REG64_FLD( C_CPPM_ERRMSK_RESERVED_0_7                              , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_7 );
REG64_FLD( C_CPPM_ERRMSK_RESERVED_0_7_LEN                          , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_7_LEN );

REG64_FLD( EX_CPPM_IPPMCMD_QPPM_REG                                , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_REG   );
REG64_FLD( EX_CPPM_IPPMCMD_QPPM_REG_LEN                            , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_REG_LEN );
REG64_FLD( EX_CPPM_IPPMCMD_QPPM_RNW                                , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RNW   );
REG64_FLD( EX_CPPM_IPPMCMD_RESERVED_9                              , 9   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_9 );

REG64_FLD( C_CPPM_IPPMCMD_QPPM_REG                                 , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_REG   );
REG64_FLD( C_CPPM_IPPMCMD_QPPM_REG_LEN                             , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_REG_LEN );
REG64_FLD( C_CPPM_IPPMCMD_QPPM_RNW                                 , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RNW   );
REG64_FLD( C_CPPM_IPPMCMD_RESERVED_9                               , 9   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_9 );

REG64_FLD( EX_CPPM_IPPMRDATA_QPPM_RDATA                            , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RDATA );
REG64_FLD( EX_CPPM_IPPMRDATA_QPPM_RDATA_LEN                        , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RDATA_LEN );

REG64_FLD( C_CPPM_IPPMRDATA_QPPM_RDATA                             , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RDATA );
REG64_FLD( C_CPPM_IPPMRDATA_QPPM_RDATA_LEN                         , 64  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_RDATA_LEN );

REG64_FLD( EX_CPPM_IPPMSTAT_QPPM_ONGOING                           , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_ONGOING );
REG64_FLD( EX_CPPM_IPPMSTAT_QPPM_STATUS                            , 1   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_STATUS );
REG64_FLD( EX_CPPM_IPPMSTAT_QPPM_STATUS_LEN                        , 2   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_STATUS_LEN );

REG64_FLD( C_CPPM_IPPMSTAT_QPPM_ONGOING                            , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_ONGOING );
REG64_FLD( C_CPPM_IPPMSTAT_QPPM_STATUS                             , 1   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_STATUS );
REG64_FLD( C_CPPM_IPPMSTAT_QPPM_STATUS_LEN                         , 2   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_QPPM_STATUS_LEN );

REG64_FLD( EX_CPPM_IPPMWDATA_QPPM_WDATA                            , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_WDATA );
REG64_FLD( EX_CPPM_IPPMWDATA_QPPM_WDATA_LEN                        , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_WDATA_LEN );

REG64_FLD( C_CPPM_IPPMWDATA_QPPM_WDATA                             , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_WDATA );
REG64_FLD( C_CPPM_IPPMWDATA_QPPM_WDATA_LEN                         , 64  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_QPPM_WDATA_LEN );

REG64_FLD( EX_CPPM_PERRSUM_ERROR                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_ERROR      );

REG64_FLD( C_CPPM_PERRSUM_ERROR                                    , 0   , SH_UNT_C        , SH_ACS_SCOM_WCLRPART,
           SH_FLD_ERROR      );

REG64_FLD( EQ_CSAR_SRAM_ADDRESS                                    , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_ADDRESS );
REG64_FLD( EQ_CSAR_SRAM_ADDRESS_LEN                                , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_ADDRESS_LEN );

REG64_FLD( EX_CSAR_SRAM_ADDRESS                                    , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_ADDRESS );
REG64_FLD( EX_CSAR_SRAM_ADDRESS_LEN                                , 13  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_ADDRESS_LEN );

REG64_FLD( EQ_CSCR_SRAM_ACCESS_MODE                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_ACCESS_MODE );
REG64_FLD( EQ_CSCR_SRAM_SCRUB_ENABLE                               , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_ENABLE );
REG64_FLD( EQ_CSCR_ECC_CORRECT_DIS                                 , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_CORRECT_DIS );
REG64_FLD( EQ_CSCR_ECC_DETECT_DIS                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_DETECT_DIS );
REG64_FLD( EQ_CSCR_ECC_INJECT_TYPE                                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_INJECT_TYPE );
REG64_FLD( EQ_CSCR_ECC_INJECT_ERR                                  , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_INJECT_ERR );
REG64_FLD( EQ_CSCR_SPARE_6_7                                       , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_6_7  );
REG64_FLD( EQ_CSCR_SPARE_6_7_LEN                                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_6_7_LEN );
REG64_FLD( EQ_CSCR_SRAM_SCRUB_INDEX                                , 47  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_INDEX );
REG64_FLD( EQ_CSCR_SRAM_SCRUB_INDEX_LEN                            , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_INDEX_LEN );

REG64_FLD( EX_CSCR_SRAM_ACCESS_MODE                                , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_ACCESS_MODE );
REG64_FLD( EX_CSCR_SRAM_SCRUB_ENABLE                               , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_ENABLE );
REG64_FLD( EX_CSCR_ECC_CORRECT_DIS                                 , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_CORRECT_DIS );
REG64_FLD( EX_CSCR_ECC_DETECT_DIS                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_DETECT_DIS );
REG64_FLD( EX_CSCR_ECC_INJECT_TYPE                                 , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_INJECT_TYPE );
REG64_FLD( EX_CSCR_ECC_INJECT_ERR                                  , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ECC_INJECT_ERR );
REG64_FLD( EX_CSCR_SPARE_6_7                                       , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_6_7  );
REG64_FLD( EX_CSCR_SPARE_6_7_LEN                                   , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_6_7_LEN );
REG64_FLD( EX_CSCR_SRAM_SCRUB_INDEX                                , 47  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_INDEX );
REG64_FLD( EX_CSCR_SRAM_SCRUB_INDEX_LEN                            , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SRAM_SCRUB_INDEX_LEN );

REG64_FLD( EQ_CSDR_SRAM_DATA                                       , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_DATA  );
REG64_FLD( EQ_CSDR_SRAM_DATA_LEN                                   , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_DATA_LEN );

REG64_FLD( EX_CSDR_SRAM_DATA                                       , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_DATA  );
REG64_FLD( EX_CSDR_SRAM_DATA_LEN                                   , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_SRAM_DATA_LEN );

REG64_FLD( EX_L2_CTRL_T0_RUN_Q                                     , 48  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T0_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T1_RUN_Q                                     , 49  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T1_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T2_RUN_Q                                     , 50  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T2_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T3_RUN_Q                                     , 51  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T3_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T4_RUN_Q                                     , 52  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T4_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T5_RUN_Q                                     , 53  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T5_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T6_RUN_Q                                     , 54  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T6_RUN_Q   );
REG64_FLD( EX_L2_CTRL_T7_RUN_Q                                     , 55  , SH_UNT_EX_L2    , SH_ACS_SCOM_NC  ,
           SH_FLD_T7_RUN_Q   );

REG64_FLD( C_CTRL_T0_RUN_Q                                         , 48  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T0_RUN_Q   );
REG64_FLD( C_CTRL_T1_RUN_Q                                         , 49  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T1_RUN_Q   );
REG64_FLD( C_CTRL_T2_RUN_Q                                         , 50  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T2_RUN_Q   );
REG64_FLD( C_CTRL_T3_RUN_Q                                         , 51  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T3_RUN_Q   );
REG64_FLD( C_CTRL_T4_RUN_Q                                         , 52  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T4_RUN_Q   );
REG64_FLD( C_CTRL_T5_RUN_Q                                         , 53  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T5_RUN_Q   );
REG64_FLD( C_CTRL_T6_RUN_Q                                         , 54  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T6_RUN_Q   );
REG64_FLD( C_CTRL_T7_RUN_Q                                         , 55  , SH_UNT_C        , SH_ACS_SCOM_NC  ,
           SH_FLD_T7_RUN_Q   );

REG64_FLD( EQ_CTRL_ATOMIC_LOCK_REG_ENABLE                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EQ_CTRL_ATOMIC_LOCK_REG_ID                              , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EQ_CTRL_ATOMIC_LOCK_REG_ID_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EQ_CTRL_ATOMIC_LOCK_REG_ACTIVITY                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EQ_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN                    , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EX_CTRL_ATOMIC_LOCK_REG_ENABLE                          , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( EX_CTRL_ATOMIC_LOCK_REG_ID                              , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( EX_CTRL_ATOMIC_LOCK_REG_ID_LEN                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( EX_CTRL_ATOMIC_LOCK_REG_ACTIVITY                        , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( EX_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN                    , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( C_CTRL_ATOMIC_LOCK_REG_ENABLE                           , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENABLE     );
REG64_FLD( C_CTRL_ATOMIC_LOCK_REG_ID                               , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID         );
REG64_FLD( C_CTRL_ATOMIC_LOCK_REG_ID_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ID_LEN     );
REG64_FLD( C_CTRL_ATOMIC_LOCK_REG_ACTIVITY                         , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY   );
REG64_FLD( C_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN                     , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACTIVITY_LEN );

REG64_FLD( EQ_CTRL_PROTECT_MODE_REG_READ_ENABLE                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EQ_CTRL_PROTECT_MODE_REG_WRITE_ENABLE                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( EX_CTRL_PROTECT_MODE_REG_READ_ENABLE                    , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EX_CTRL_PROTECT_MODE_REG_WRITE_ENABLE                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( C_CTRL_PROTECT_MODE_REG_READ_ENABLE                     , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( C_CTRL_PROTECT_MODE_REG_WRITE_ENABLE                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( CAPP_CXA_SNP_ARRAY_ADDR_REG_ADDRESS                     , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS    );
REG64_FLD( CAPP_CXA_SNP_ARRAY_ADDR_REG_ADDRESS_LEN                 , 15  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_LEN );

REG64_FLD( CAPP_CXA_SNP_ARRAY_READ_REG_DATA                        , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA       );
REG64_FLD( CAPP_CXA_SNP_ARRAY_READ_REG_DATA_LEN                    , 64  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA_LEN   );

REG64_FLD( CAPP_CXA_SNP_ARRAY_WRITE_REG_DATA                       , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA       );
REG64_FLD( CAPP_CXA_SNP_ARRAY_WRITE_REG_DATA_LEN                   , 64  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA_LEN   );

REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG0_0_CANNED_0                  , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_0_CANNED_0 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG0_0_CANNED_0_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_0_CANNED_0_LEN );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG0_0_CANNED_1                  , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_0_CANNED_1 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG0_0_CANNED_1_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_0_CANNED_1_LEN );

REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG1_1_CANNED_0                  , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_1_CANNED_0 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG1_1_CANNED_0_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_1_CANNED_0_LEN );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG1_1_CANNED_1                  , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_1_CANNED_1 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG1_1_CANNED_1_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_1_CANNED_1_LEN );

REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG2_2_CANNED_0                  , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_2_CANNED_0 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG2_2_CANNED_0_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_2_CANNED_0_LEN );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG2_2_CANNED_1                  , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_2_CANNED_1 );
REG64_FLD( CAPP_CXA_SNP_CAN_PRESP_REG2_2_CANNED_1_LEN              , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_2_CANNED_1_LEN );

REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_ENABLE_TTYPE_DECODE           , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ENABLE_TTYPE_DECODE );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_PRECISE_DIR_SIZE              , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PRECISE_DIR_SIZE );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_PRECISE_DIR_SIZE_LEN          , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PRECISE_DIR_SIZE_LEN );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_COARSE_DIR_ENABLE             , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COARSE_DIR_ENABLE );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_COARSE_DIR_SECTORS            , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COARSE_DIR_SECTORS );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_MCD_CHICKEN_SWITCH            , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_MCD_CHICKEN_SWITCH );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_BHR_DIR_STATE                 , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BHR_DIR_STATE );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_BHR_DIR_STATE_LEN             , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BHR_DIR_STATE_LEN );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_LPC_MODE                      , 12  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPC_MODE   );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_LPC_MODE_LEN                  , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_LPC_MODE_LEN );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_CT_COMPARE_VECTOR             , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CT_COMPARE_VECTOR );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_CT_COMPARE_VECTOR_LEN         , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CT_COMPARE_VECTOR_LEN );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_PHB_FILTER_CNTL               , 38  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PHB_FILTER_CNTL );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_PHB_FILTER_CNTL_LEN           , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PHB_FILTER_CNTL_LEN );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_EPOCH_TEST_VECTOR             , 40  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EPOCH_TEST_VECTOR );
REG64_FLD( CAPP_CXA_SNP_CAPI_CFG_REG_EPOCH_TEST_VECTOR_LEN         , 24  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EPOCH_TEST_VECTOR_LEN );

REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_MODE                 , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_MODE );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER0                , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER0 );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER0_LEN            , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER0_LEN );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER1                , 15  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER1 );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER1_LEN            , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER1_LEN );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER2                , 25  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER2 );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_READ_EPSILON_TIER2_LEN            , 11  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_READ_EPSILON_TIER2_LEN );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_ADDRESS_PIPELINE_MASTERWAIT_COUNT , 45  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_PIPELINE_MASTERWAIT_COUNT );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_ADDRESS_PIPELINE_MASTERWAIT_COUNT_LEN , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_PIPELINE_MASTERWAIT_COUNT_LEN );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_DATA_HANG_POLL_SCALE              , 48  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA_HANG_POLL_SCALE );
REG64_FLD( CAPP_CXA_SNP_CNTL_REG_DATA_HANG_POLL_SCALE_LEN          , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_DATA_HANG_POLL_SCALE_LEN );

REG64_FLD( CAPP_CXA_SNP_ERROR_REPORT_REG_C_ERR_RPT_HOLD_DATA       , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_C_ERR_RPT_HOLD_DATA );
REG64_FLD( CAPP_CXA_SNP_ERROR_REPORT_REG_C_ERR_RPT_HOLD_DATA_LEN   , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_C_ERR_RPT_HOLD_DATA_LEN );

REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_GROUP                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_GROUP      );
REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_GROUP_LEN            , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_GROUP_LEN  );
REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_FSMJ_EVENT           , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_EVENT );
REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_FSMJ_EVENT_LEN       , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_EVENT_LEN );
REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_FSMJ_FSM             , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_FSM   );
REG64_FLD( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG_FSMJ_FSM_LEN         , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FSMJ_FSM_LEN );

REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_EN                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EN         );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_SIZE              , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SIZE       );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_SIZE_LEN          , 18  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SIZE_LEN   );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_STARTING_ADDRESS  , 19  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_STARTING_ADDRESS );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_STARTING_ADDRESS_LEN , 27  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_STARTING_ADDRESS_LEN );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_SYSTEM            , 50  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM     );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG_SYSTEM_LEN        , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM_LEN );

REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_EN          , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_EN    );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_SIZE        , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_SIZE  );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_SIZE_LEN    , 18  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_SIZE_LEN );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_STARTING_ADDRESS , 19  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_STARTING_ADDRESS );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_STARTING_ADDRESS_LEN , 27  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_STARTING_ADDRESS_LEN );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_SYSTEM      , 50  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_SYSTEM );
REG64_FLD( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1_BAR1_SYSTEM_LEN  , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_SYSTEM_LEN );

REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG_EN                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_EN         );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG_MS_GROUP_CHIP     , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_MS_GROUP_CHIP );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG_MS_GROUP_CHIP_LEN , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_MS_GROUP_CHIP_LEN );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG_STARTING_ADDRESS  , 22  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_STARTING_ADDRESS );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG_STARTING_ADDRESS_LEN , 31  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_STARTING_ADDRESS_LEN );

REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1_BAR1_EN          , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_EN    );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1_BAR1_MS_GROUP_CHIP , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_MS_GROUP_CHIP );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1_BAR1_MS_GROUP_CHIP_LEN , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_MS_GROUP_CHIP_LEN );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1_BAR1_STARTING_ADDRESS , 22  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_STARTING_ADDRESS );
REG64_FLD( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1_BAR1_STARTING_ADDRESS_LEN , 31  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BAR1_STARTING_ADDRESS_LEN );

REG64_FLD( EQ_DBG_CBS_CC_RESET_EP                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESET_EP   );
REG64_FLD( EQ_DBG_CBS_CC_OPCG_IP                                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_OPCG_IP    );
REG64_FLD( EQ_DBG_CBS_CC_VITL_CLKOFF                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VITL_CLKOFF );
REG64_FLD( EQ_DBG_CBS_CC_TEST_ENABLE                               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TEST_ENABLE );
REG64_FLD( EQ_DBG_CBS_CC_REQ                                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ        );
REG64_FLD( EQ_DBG_CBS_CC_CMD                                       , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CMD        );
REG64_FLD( EQ_DBG_CBS_CC_CMD_LEN                                   , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CMD_LEN    );
REG64_FLD( EQ_DBG_CBS_CC_STATE                                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATE      );
REG64_FLD( EQ_DBG_CBS_CC_STATE_LEN                                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STATE_LEN  );
REG64_FLD( EQ_DBG_CBS_CC_SECURITY_DEBUG_MODE                       , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SECURITY_DEBUG_MODE );
REG64_FLD( EQ_DBG_CBS_CC_PROTOCOL_ERROR                            , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PROTOCOL_ERROR );
REG64_FLD( EQ_DBG_CBS_CC_PCB_IDLE                                  , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PCB_IDLE   );
REG64_FLD( EQ_DBG_CBS_CC_CURRENT_OPCG_MODE                         , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE );
REG64_FLD( EQ_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE_LEN );
REG64_FLD( EQ_DBG_CBS_CC_LAST_OPCG_MODE                            , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE );
REG64_FLD( EQ_DBG_CBS_CC_LAST_OPCG_MODE_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE_LEN );
REG64_FLD( EQ_DBG_CBS_CC_PCB_ERROR                                 , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PCB_ERROR  );
REG64_FLD( EQ_DBG_CBS_CC_PARITY_ERROR                              , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PARITY_ERROR );
REG64_FLD( EQ_DBG_CBS_CC_ERROR                                     , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( EQ_DBG_CBS_CC_CHIPLET_IS_ALIGNED                        , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_IS_ALIGNED );
REG64_FLD( EQ_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET                   , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PCB_REQUEST_SINCE_RESET );
REG64_FLD( EQ_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE               , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_TEST_ENABLE_CHANGE );
REG64_FLD( EQ_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE               , 30  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_VITL_CLKOFF_CHANGE );
REG64_FLD( EQ_DBG_CBS_CC_TP_TPFSI_ACK                              , 31  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TP_TPFSI_ACK );

REG64_FLD( EX_DBG_CBS_CC_RESET_EP                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESET_EP   );
REG64_FLD( EX_DBG_CBS_CC_OPCG_IP                                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_OPCG_IP    );
REG64_FLD( EX_DBG_CBS_CC_VITL_CLKOFF                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_VITL_CLKOFF );
REG64_FLD( EX_DBG_CBS_CC_TEST_ENABLE                               , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TEST_ENABLE );
REG64_FLD( EX_DBG_CBS_CC_REQ                                       , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ        );
REG64_FLD( EX_DBG_CBS_CC_CMD                                       , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CMD        );
REG64_FLD( EX_DBG_CBS_CC_CMD_LEN                                   , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CMD_LEN    );
REG64_FLD( EX_DBG_CBS_CC_STATE                                     , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATE      );
REG64_FLD( EX_DBG_CBS_CC_STATE_LEN                                 , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STATE_LEN  );
REG64_FLD( EX_DBG_CBS_CC_SECURITY_DEBUG_MODE                       , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SECURITY_DEBUG_MODE );
REG64_FLD( EX_DBG_CBS_CC_PROTOCOL_ERROR                            , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PROTOCOL_ERROR );
REG64_FLD( EX_DBG_CBS_CC_PCB_IDLE                                  , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_IDLE   );
REG64_FLD( EX_DBG_CBS_CC_CURRENT_OPCG_MODE                         , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE );
REG64_FLD( EX_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN                     , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE_LEN );
REG64_FLD( EX_DBG_CBS_CC_LAST_OPCG_MODE                            , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE );
REG64_FLD( EX_DBG_CBS_CC_LAST_OPCG_MODE_LEN                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE_LEN );
REG64_FLD( EX_DBG_CBS_CC_PCB_ERROR                                 , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_ERROR  );
REG64_FLD( EX_DBG_CBS_CC_PARITY_ERROR                              , 25  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PARITY_ERROR );
REG64_FLD( EX_DBG_CBS_CC_ERROR                                     , 26  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( EX_DBG_CBS_CC_CHIPLET_IS_ALIGNED                        , 27  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_IS_ALIGNED );
REG64_FLD( EX_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET                   , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_REQUEST_SINCE_RESET );
REG64_FLD( EX_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE               , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_TEST_ENABLE_CHANGE );
REG64_FLD( EX_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE               , 30  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_VITL_CLKOFF_CHANGE );
REG64_FLD( EX_DBG_CBS_CC_TP_TPFSI_ACK                              , 31  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TP_TPFSI_ACK );

REG64_FLD( C_DBG_CBS_CC_RESET_EP                                   , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESET_EP   );
REG64_FLD( C_DBG_CBS_CC_OPCG_IP                                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_OPCG_IP    );
REG64_FLD( C_DBG_CBS_CC_VITL_CLKOFF                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_VITL_CLKOFF );
REG64_FLD( C_DBG_CBS_CC_TEST_ENABLE                                , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TEST_ENABLE );
REG64_FLD( C_DBG_CBS_CC_REQ                                        , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ        );
REG64_FLD( C_DBG_CBS_CC_CMD                                        , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CMD        );
REG64_FLD( C_DBG_CBS_CC_CMD_LEN                                    , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CMD_LEN    );
REG64_FLD( C_DBG_CBS_CC_STATE                                      , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATE      );
REG64_FLD( C_DBG_CBS_CC_STATE_LEN                                  , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STATE_LEN  );
REG64_FLD( C_DBG_CBS_CC_SECURITY_DEBUG_MODE                        , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SECURITY_DEBUG_MODE );
REG64_FLD( C_DBG_CBS_CC_PROTOCOL_ERROR                             , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PROTOCOL_ERROR );
REG64_FLD( C_DBG_CBS_CC_PCB_IDLE                                   , 15  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_IDLE   );
REG64_FLD( C_DBG_CBS_CC_CURRENT_OPCG_MODE                          , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE );
REG64_FLD( C_DBG_CBS_CC_CURRENT_OPCG_MODE_LEN                      , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CURRENT_OPCG_MODE_LEN );
REG64_FLD( C_DBG_CBS_CC_LAST_OPCG_MODE                             , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE );
REG64_FLD( C_DBG_CBS_CC_LAST_OPCG_MODE_LEN                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LAST_OPCG_MODE_LEN );
REG64_FLD( C_DBG_CBS_CC_PCB_ERROR                                  , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_ERROR  );
REG64_FLD( C_DBG_CBS_CC_PARITY_ERROR                               , 25  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PARITY_ERROR );
REG64_FLD( C_DBG_CBS_CC_ERROR                                      , 26  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ERROR      );
REG64_FLD( C_DBG_CBS_CC_CHIPLET_IS_ALIGNED                         , 27  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_IS_ALIGNED );
REG64_FLD( C_DBG_CBS_CC_PCB_REQUEST_SINCE_RESET                    , 28  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_REQUEST_SINCE_RESET );
REG64_FLD( C_DBG_CBS_CC_PARANOIA_TEST_ENABLE_CHANGE                , 29  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_TEST_ENABLE_CHANGE );
REG64_FLD( C_DBG_CBS_CC_PARANOIA_VITL_CLKOFF_CHANGE                , 30  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PARANOIA_VITL_CLKOFF_CHANGE );
REG64_FLD( C_DBG_CBS_CC_TP_TPFSI_ACK                               , 31  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TP_TPFSI_ACK );

REG64_FLD( CAPP_DEBUG_CONTROL_BLOCK_MUX_PORT_SEL                   , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_MUX_PORT_SEL );
REG64_FLD( CAPP_DEBUG_CONTROL_BLOCK_MUX_PORT_SEL_LEN               , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_MUX_PORT_SEL_LEN );
REG64_FLD( CAPP_DEBUG_CONTROL_BLOCK_SEL                            , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_SEL  );
REG64_FLD( CAPP_DEBUG_CONTROL_BLOCK_SEL_LEN                        , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_SEL_LEN );

REG64_FLD( EQ_DEBUG_MUX_SEL_REG_L3                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EQ_DEBUG_MUX_SEL_REG_L3_LEN                             , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( EX_DEBUG_MUX_SEL_REG_L3                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EX_DEBUG_MUX_SEL_REG_L3_LEN                             , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( CAPP_DFSUOP1_WORD                                       , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_WORD       );
REG64_FLD( CAPP_DFSUOP1_WORD_LEN                                   , 56  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_WORD_LEN   );

REG64_FLD( EQ_DRAM_REF_REG_L3_TIMER_DIVIDE_MAJOR                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MAJOR );
REG64_FLD( EQ_DRAM_REF_REG_L3_TIMER_DIVIDE_MAJOR_LEN               , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MAJOR_LEN );
REG64_FLD( EQ_DRAM_REF_REG_L3_SCOM_INIT                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_INIT );
REG64_FLD( EQ_DRAM_REF_REG_L3_SCOM_QUIESCE_CACHE                   , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_CACHE );
REG64_FLD( EQ_DRAM_REF_REG_L3_SCOM_QUIESCE_CACHE_LFSR              , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_CACHE_LFSR );
REG64_FLD( EQ_DRAM_REF_REG_L3_SCOM_QUIESCE_REFRESH                 , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_REFRESH );
REG64_FLD( EQ_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MINOR );
REG64_FLD( EQ_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR_LEN               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MINOR_LEN );

REG64_FLD( EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MAJOR                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MAJOR );
REG64_FLD( EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MAJOR_LEN               , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MAJOR_LEN );
REG64_FLD( EX_DRAM_REF_REG_L3_SCOM_INIT                            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_INIT );
REG64_FLD( EX_DRAM_REF_REG_L3_SCOM_QUIESCE_CACHE                   , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_CACHE );
REG64_FLD( EX_DRAM_REF_REG_L3_SCOM_QUIESCE_CACHE_LFSR              , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_CACHE_LFSR );
REG64_FLD( EX_DRAM_REF_REG_L3_SCOM_QUIESCE_REFRESH                 , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_QUIESCE_REFRESH );
REG64_FLD( EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR                   , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MINOR );
REG64_FLD( EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR_LEN               , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TIMER_DIVIDE_MINOR_LEN );

REG64_FLD( EQ_DTS_RESULT0_0_RESULT                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT   );
REG64_FLD( EQ_DTS_RESULT0_0_RESULT_LEN                             , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT_LEN );
REG64_FLD( EQ_DTS_RESULT0_1_RESULT                                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT   );
REG64_FLD( EQ_DTS_RESULT0_1_RESULT_LEN                             , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT_LEN );

REG64_FLD( EX_DTS_RESULT0_0_RESULT                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT   );
REG64_FLD( EX_DTS_RESULT0_0_RESULT_LEN                             , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT_LEN );
REG64_FLD( EX_DTS_RESULT0_1_RESULT                                 , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT   );
REG64_FLD( EX_DTS_RESULT0_1_RESULT_LEN                             , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT_LEN );

REG64_FLD( C_DTS_RESULT0_0_RESULT                                  , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT   );
REG64_FLD( C_DTS_RESULT0_0_RESULT_LEN                              , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_0_RESULT_LEN );
REG64_FLD( C_DTS_RESULT0_1_RESULT                                  , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT   );
REG64_FLD( C_DTS_RESULT0_1_RESULT_LEN                              , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_1_RESULT_LEN );

REG64_FLD( EQ_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE               , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE );
REG64_FLD( EQ_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN           , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE_LEN );
REG64_FLD( EQ_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR        , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_OVERFLOW_ERR );
REG64_FLD( EQ_DTS_TRC_RESULT_1                                     , 48  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_1          );
REG64_FLD( EQ_DTS_TRC_RESULT_1_LEN                                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_LEN      );

REG64_FLD( EX_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE               , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE );
REG64_FLD( EX_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN           , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE_LEN );
REG64_FLD( EX_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR        , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_OVERFLOW_ERR );
REG64_FLD( EX_DTS_TRC_RESULT_1                                     , 48  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_1          );
REG64_FLD( EX_DTS_TRC_RESULT_1_LEN                                 , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_1_LEN      );

REG64_FLD( C_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE                , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE );
REG64_FLD( C_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN            , 44  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_VALUE_LEN );
REG64_FLD( C_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR         , 44  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMESTAMP_COUNTER_OVERFLOW_ERR );
REG64_FLD( C_DTS_TRC_RESULT_1                                      , 48  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_1          );
REG64_FLD( C_DTS_TRC_RESULT_1_LEN                                  , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_1_LEN      );

REG64_FLD( EQ_EDRAM_BANK_FAIL_L3                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EQ_EDRAM_BANK_FAIL_L3_LEN                               , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( EX_L3_EDRAM_BANK_FAIL_L3                                , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EX_L3_EDRAM_BANK_FAIL_L3_LEN                            , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( EQ_EDRAM_BANK_SOFT_DIS_L3_CFG                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG     );
REG64_FLD( EQ_EDRAM_BANK_SOFT_DIS_L3_CFG_LEN                       , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG_LEN );

REG64_FLD( EX_L3_EDRAM_BANK_SOFT_DIS_L3_CFG                        , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG     );
REG64_FLD( EX_L3_EDRAM_BANK_SOFT_DIS_L3_CFG_LEN                    , 10  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG_LEN );

REG64_FLD( EQ_EDRAM_REG_L3_CP_UTIL_EN_DC                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EN_DC );
REG64_FLD( EQ_EDRAM_REG_L3_CP_UTIL_SEL_DC                          , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_SEL_DC );
REG64_FLD( EQ_EDRAM_REG_L3_CP_UTIL_SEL_DC_LEN                      , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_SEL_DC_LEN );
REG64_FLD( EQ_EDRAM_REG_L3_CP_UTIL_EXT_SEL                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EXT_SEL );
REG64_FLD( EQ_EDRAM_REG_L3_CP_UTIL_EXT_SEL_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EXT_SEL_LEN );
REG64_FLD( EQ_EDRAM_REG_L3_UTIL_MON_BITS                           , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_UTIL_MON_BITS );
REG64_FLD( EQ_EDRAM_REG_L3_UTIL_MON_BITS_LEN                       , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_UTIL_MON_BITS_LEN );

REG64_FLD( EX_L3_EDRAM_REG_L3_CP_UTIL_EN_DC                        , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EN_DC );
REG64_FLD( EX_L3_EDRAM_REG_L3_CP_UTIL_SEL_DC                       , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_SEL_DC );
REG64_FLD( EX_L3_EDRAM_REG_L3_CP_UTIL_SEL_DC_LEN                   , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_SEL_DC_LEN );
REG64_FLD( EX_L3_EDRAM_REG_L3_CP_UTIL_EXT_SEL                      , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EXT_SEL );
REG64_FLD( EX_L3_EDRAM_REG_L3_CP_UTIL_EXT_SEL_LEN                  , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CP_UTIL_EXT_SEL_LEN );
REG64_FLD( EX_L3_EDRAM_REG_L3_UTIL_MON_BITS                        , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_UTIL_MON_BITS );
REG64_FLD( EX_L3_EDRAM_REG_L3_UTIL_MON_BITS_LEN                    , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_UTIL_MON_BITS_LEN );

REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_VAL                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_VAL     );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_UE                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_UE );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_UE                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_UE );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_SPARE3                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE3  );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_SYNDROME             , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_SYNDROME );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_SYNDROME_LEN         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_SYNDROME_LEN );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_SYNDROME             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_SYNDROME );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_SYNDROME_LEN         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_SYNDROME_LEN );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_DW                            , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DW      );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG0_L3_DW_LEN                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DW_LEN  );

REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_VAL                           , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_VAL     );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_UE                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_UE );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_UE                   , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_UE );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_SPARE3                        , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE3  );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_SYNDROME             , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_SYNDROME );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_1ST_BEAT_SYNDROME_LEN         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_1ST_BEAT_SYNDROME_LEN );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_SYNDROME             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_SYNDROME );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_2ND_BEAT_SYNDROME_LEN         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_2ND_BEAT_SYNDROME_LEN );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_DW                            , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_DW      );
REG64_FLD( EX_ED_RD_ERR_STAT_REG0_L3_DW_LEN                        , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_DW_LEN  );

REG64_FLD( EQ_ED_RD_ERR_STAT_REG1_L3_RA                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_RA      );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG1_L3_RA_LEN                        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_RA_LEN  );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG1_L3_BANK                          , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_BANK    );
REG64_FLD( EQ_ED_RD_ERR_STAT_REG1_L3_BANK_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_BANK_LEN );

REG64_FLD( EX_L3_ED_RD_ERR_STAT_REG1_L3_RA                         , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_RA      );
REG64_FLD( EX_L3_ED_RD_ERR_STAT_REG1_L3_RA_LEN                     , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_RA_LEN  );
REG64_FLD( EX_L3_ED_RD_ERR_STAT_REG1_L3_BANK                       , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_BANK    );
REG64_FLD( EX_L3_ED_RD_ERR_STAT_REG1_L3_BANK_LEN                   , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_BANK_LEN );

REG64_FLD( EQ_ERROR_REG_CE                                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CE         );
REG64_FLD( EQ_ERROR_REG_CHIPLET_ERRORS                             , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS );
REG64_FLD( EQ_ERROR_REG_CHIPLET_ERRORS_LEN                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS_LEN );
REG64_FLD( EQ_ERROR_REG_PARITY                                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PARITY     );
REG64_FLD( EQ_ERROR_REG_DATA_BUFFER                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DATA_BUFFER );
REG64_FLD( EQ_ERROR_REG_ADDR_BUFFER                                , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_BUFFER );
REG64_FLD( EQ_ERROR_REG_PCB_FSM                                    , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PCB_FSM    );
REG64_FLD( EQ_ERROR_REG_CL_FSM                                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CL_FSM     );
REG64_FLD( EQ_ERROR_REG_INT_RX_FSM                                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INT_RX_FSM );
REG64_FLD( EQ_ERROR_REG_INT_TX_FSM                                 , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INT_TX_FSM );
REG64_FLD( EQ_ERROR_REG_INT_TYPE                                   , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INT_TYPE   );
REG64_FLD( EQ_ERROR_REG_CL_DATA                                    , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CL_DATA    );
REG64_FLD( EQ_ERROR_REG_INFO                                       , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INFO       );
REG64_FLD( EQ_ERROR_REG_UNUSED_0                                   , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_0   );
REG64_FLD( EQ_ERROR_REG_CHIPLET_ATOMIC_LOCK                        , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ATOMIC_LOCK );
REG64_FLD( EQ_ERROR_REG_PCB_INTERFACE                              , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PCB_INTERFACE );
REG64_FLD( EQ_ERROR_REG_CHIPLET_OFFLINE                            , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_OFFLINE );
REG64_FLD( EQ_ERROR_REG_CHIPLET_GRID_SKITTER                       , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_GRID_SKITTER );
REG64_FLD( EQ_ERROR_REG_CTRL_PARITY                                , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CTRL_PARITY );
REG64_FLD( EQ_ERROR_REG_ADDRESS_PARITY                             , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_PARITY );
REG64_FLD( EQ_ERROR_REG_TIMEOUT_PARITY                             , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_PARITY );
REG64_FLD( EQ_ERROR_REG_CONFIG_PARITY                              , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CONFIG_PARITY );
REG64_FLD( EQ_ERROR_REG_UNUSED_1                                   , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_1   );
REG64_FLD( EQ_ERROR_REG_DIV_PARITY                                 , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DIV_PARITY );
REG64_FLD( EQ_ERROR_REG_PLL_UNLOCK                                 , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK );
REG64_FLD( EQ_ERROR_REG_PLL_UNLOCK_LEN                             , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK_LEN );

REG64_FLD( EX_ERROR_REG_CE                                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CE         );
REG64_FLD( EX_ERROR_REG_CHIPLET_ERRORS                             , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS );
REG64_FLD( EX_ERROR_REG_CHIPLET_ERRORS_LEN                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS_LEN );
REG64_FLD( EX_ERROR_REG_PARITY                                     , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PARITY     );
REG64_FLD( EX_ERROR_REG_DATA_BUFFER                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DATA_BUFFER );
REG64_FLD( EX_ERROR_REG_ADDR_BUFFER                                , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_BUFFER );
REG64_FLD( EX_ERROR_REG_PCB_FSM                                    , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_FSM    );
REG64_FLD( EX_ERROR_REG_CL_FSM                                     , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CL_FSM     );
REG64_FLD( EX_ERROR_REG_INT_RX_FSM                                 , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INT_RX_FSM );
REG64_FLD( EX_ERROR_REG_INT_TX_FSM                                 , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INT_TX_FSM );
REG64_FLD( EX_ERROR_REG_INT_TYPE                                   , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INT_TYPE   );
REG64_FLD( EX_ERROR_REG_CL_DATA                                    , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CL_DATA    );
REG64_FLD( EX_ERROR_REG_INFO                                       , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INFO       );
REG64_FLD( EX_ERROR_REG_UNUSED_0                                   , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_0   );
REG64_FLD( EX_ERROR_REG_CHIPLET_ATOMIC_LOCK                        , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ATOMIC_LOCK );
REG64_FLD( EX_ERROR_REG_PCB_INTERFACE                              , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PCB_INTERFACE );
REG64_FLD( EX_ERROR_REG_CHIPLET_OFFLINE                            , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_OFFLINE );
REG64_FLD( EX_ERROR_REG_CHIPLET_GRID_SKITTER                       , 18  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_GRID_SKITTER );
REG64_FLD( EX_ERROR_REG_CTRL_PARITY                                , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CTRL_PARITY );
REG64_FLD( EX_ERROR_REG_ADDRESS_PARITY                             , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_PARITY );
REG64_FLD( EX_ERROR_REG_TIMEOUT_PARITY                             , 21  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_PARITY );
REG64_FLD( EX_ERROR_REG_CONFIG_PARITY                              , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CONFIG_PARITY );
REG64_FLD( EX_ERROR_REG_UNUSED_1                                   , 23  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_1   );
REG64_FLD( EX_ERROR_REG_DIV_PARITY                                 , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DIV_PARITY );
REG64_FLD( EX_ERROR_REG_PLL_UNLOCK                                 , 25  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK );
REG64_FLD( EX_ERROR_REG_PLL_UNLOCK_LEN                             , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK_LEN );

REG64_FLD( C_ERROR_REG_CE                                          , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CE         );
REG64_FLD( C_ERROR_REG_CHIPLET_ERRORS                              , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS );
REG64_FLD( C_ERROR_REG_CHIPLET_ERRORS_LEN                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ERRORS_LEN );
REG64_FLD( C_ERROR_REG_PARITY                                      , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PARITY     );
REG64_FLD( C_ERROR_REG_DATA_BUFFER                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DATA_BUFFER );
REG64_FLD( C_ERROR_REG_ADDR_BUFFER                                 , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ADDR_BUFFER );
REG64_FLD( C_ERROR_REG_PCB_FSM                                     , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_FSM    );
REG64_FLD( C_ERROR_REG_CL_FSM                                      , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CL_FSM     );
REG64_FLD( C_ERROR_REG_INT_RX_FSM                                  , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INT_RX_FSM );
REG64_FLD( C_ERROR_REG_INT_TX_FSM                                  , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INT_TX_FSM );
REG64_FLD( C_ERROR_REG_INT_TYPE                                    , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INT_TYPE   );
REG64_FLD( C_ERROR_REG_CL_DATA                                     , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CL_DATA    );
REG64_FLD( C_ERROR_REG_INFO                                        , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INFO       );
REG64_FLD( C_ERROR_REG_UNUSED_0                                    , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_0   );
REG64_FLD( C_ERROR_REG_CHIPLET_ATOMIC_LOCK                         , 15  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_ATOMIC_LOCK );
REG64_FLD( C_ERROR_REG_PCB_INTERFACE                               , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PCB_INTERFACE );
REG64_FLD( C_ERROR_REG_CHIPLET_OFFLINE                             , 17  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_OFFLINE );
REG64_FLD( C_ERROR_REG_CHIPLET_GRID_SKITTER                        , 18  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CHIPLET_GRID_SKITTER );
REG64_FLD( C_ERROR_REG_CTRL_PARITY                                 , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CTRL_PARITY );
REG64_FLD( C_ERROR_REG_ADDRESS_PARITY                              , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ADDRESS_PARITY );
REG64_FLD( C_ERROR_REG_TIMEOUT_PARITY                              , 21  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TIMEOUT_PARITY );
REG64_FLD( C_ERROR_REG_CONFIG_PARITY                               , 22  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CONFIG_PARITY );
REG64_FLD( C_ERROR_REG_UNUSED_1                                    , 23  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_1   );
REG64_FLD( C_ERROR_REG_DIV_PARITY                                  , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DIV_PARITY );
REG64_FLD( C_ERROR_REG_PLL_UNLOCK                                  , 25  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK );
REG64_FLD( C_ERROR_REG_PLL_UNLOCK_LEN                              , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PLL_UNLOCK_LEN );

REG64_FLD( EQ_ERROR_STATUS_ERRORS                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERRORS     );
REG64_FLD( EQ_ERROR_STATUS_ERRORS_LEN                              , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERRORS_LEN );

REG64_FLD( EX_ERROR_STATUS_ERRORS                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERRORS     );
REG64_FLD( EX_ERROR_STATUS_ERRORS_LEN                              , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERRORS_LEN );

REG64_FLD( C_ERROR_STATUS_ERRORS                                   , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ERRORS     );
REG64_FLD( C_ERROR_STATUS_ERRORS_LEN                               , 32  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ERRORS_LEN );

REG64_FLD( EQ_ERR_INJ_REG_L3_SINGLE_CAC                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_CAC );
REG64_FLD( EQ_ERR_INJ_REG_L3_SOLID_CAC                             , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_CAC );
REG64_FLD( EQ_ERR_INJ_REG_L3_CAC_TYPE                              , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CAC_TYPE );
REG64_FLD( EQ_ERR_INJ_REG_L3_CAC_TYPE_LEN                          , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CAC_TYPE_LEN );
REG64_FLD( EQ_ERR_INJ_REG_L3_SINGLE_DIR                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_DIR );
REG64_FLD( EQ_ERR_INJ_REG_L3_SOLID_DIR                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_DIR );
REG64_FLD( EQ_ERR_INJ_REG_L3_DIR_TYPE                              , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_TYPE );
REG64_FLD( EQ_ERR_INJ_REG_L3_SINGLE_LRU                            , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_LRU );
REG64_FLD( EQ_ERR_INJ_REG_L3_SOLID_LRU                             , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_LRU );

REG64_FLD( EX_L2_ERR_INJ_REG_DW_TYPE                               , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DW_TYPE    );
REG64_FLD( EX_L2_ERR_INJ_REG_DW_TYPE_LEN                           , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DW_TYPE_LEN );
REG64_FLD( EX_L2_ERR_INJ_REG_CW_TYPE                               , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CW_TYPE    );
REG64_FLD( EX_L2_ERR_INJ_REG_CW_TYPE_LEN                           , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CW_TYPE_LEN );
REG64_FLD( EX_L2_ERR_INJ_REG_STQ_TYPE                              , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_STQ_TYPE   );
REG64_FLD( EX_L2_ERR_INJ_REG_STQ_TYPE_LEN                          , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_STQ_TYPE_LEN );
REG64_FLD( EX_L2_ERR_INJ_REG_CPI_TYPE                              , 10  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CPI_TYPE   );
REG64_FLD( EX_L2_ERR_INJ_REG_CPI_TYPE_LEN                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CPI_TYPE_LEN );
REG64_FLD( EX_L2_ERR_INJ_REG_LVDIR_EN                              , 13  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_LVDIR_EN   );

REG64_FLD( EX_L3_ERR_INJ_REG_L3_SINGLE_CAC                         , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_CAC );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_SOLID_CAC                          , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_CAC );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_CAC_TYPE                           , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CAC_TYPE );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_CAC_TYPE_LEN                       , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CAC_TYPE_LEN );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_SINGLE_DIR                         , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_DIR );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_SOLID_DIR                          , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_DIR );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_DIR_TYPE                           , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_TYPE );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_SINGLE_LRU                         , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SINGLE_LRU );
REG64_FLD( EX_L3_ERR_INJ_REG_L3_SOLID_LRU                          , 8   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SOLID_LRU );

REG64_FLD( EQ_ERR_RPT0_FIR14_NCCTL_RLD_BARRIER                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_RLD_BARRIER );
REG64_FLD( EQ_ERR_RPT0_FIR14_NCCTL_SNP                             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_SNP );
REG64_FLD( EQ_ERR_RPT0_FIR14_NCCTL_TLBIE_ACK                       , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_TLBIE_ACK );
REG64_FLD( EQ_ERR_RPT0_FIR14_NCCTL_SYNC                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_SYNC );
REG64_FLD( EQ_ERR_RPT0_FIR14_NCCTL_VSYNC                           , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_VSYNC );
REG64_FLD( EQ_ERR_RPT0_FIR14_TMCTL_TIDX_TEND_LDST_SEQ              , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_TMCTL_TIDX_TEND_LDST_SEQ );
REG64_FLD( EQ_ERR_RPT0_FIR14_RVCTL                                 , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RVCTL );
REG64_FLD( EQ_ERR_RPT0_FIR14_SRCTL0_BAD_HPC                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL0_BAD_HPC );
REG64_FLD( EQ_ERR_RPT0_FIR14_SRCTL1_BAD_HPC                        , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL1_BAD_HPC );
REG64_FLD( EQ_ERR_RPT0_FIR14_SRCTL2_BAD_HPC                        , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL2_BAD_HPC );
REG64_FLD( EQ_ERR_RPT0_FIR14_SRCTL3_BAD_HPC                        , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL3_BAD_HPC );
REG64_FLD( EQ_ERR_RPT0_FIR14_PBARB_FSM_REQ_OVERFLOW                , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PBARB_FSM_REQ_OVERFLOW );
REG64_FLD( EQ_ERR_RPT0_FIR14_PBARB_TRASHMODE_PB_REQ                , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PBARB_TRASHMODE_PB_REQ );
REG64_FLD( EQ_ERR_RPT0_FIR14_L3PF_MACH_DONE                        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_L3PF_MACH_DONE );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD0_TTAG_PERR                       , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD0_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD1_TTAG_PERR                       , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD1_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD2_TTAG_PERR                       , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD2_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD3_TTAG_PERR                       , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD3_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR0_TTAG_PERR                         , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR0_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR0_ATAG_PERR                         , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR0_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR1_TTAG_PERR                         , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR1_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR1_ATAG_PERR                         , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR1_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR2_TTAG_PERR                         , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR2_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR2_ATAG_PERR                         , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR2_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR3_TTAG_PERR                         , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR3_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_CR3_ATAG_PERR                         , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR3_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD0_ADDR_PERR                       , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD0_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD1_ADDR_PERR                       , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD1_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD2_ADDR_PERR                       , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD2_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCMD3_ADDR_PERR                       , 30  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD3_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT0_FIR9_PEC_PHASE3_TIMEOUT                     , 31  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE3_TIMEOUT );
REG64_FLD( EQ_ERR_RPT0_FIR9_PEC_PHASE4_SAME                        , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE4_SAME );
REG64_FLD( EQ_ERR_RPT0_FIR9_PEC_PHASE4_RCCO_DISP_FAIL              , 33  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE4_RCCO_DISP_FAIL );
REG64_FLD( EQ_ERR_RPT0_FIR9_PEC_PHASE5_TIMEOUT                     , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE5_TIMEOUT );
REG64_FLD( EQ_ERR_RPT0_FIR14_B01_BOTH_ACTIVE                       , 35  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B01_BOTH_ACTIVE );
REG64_FLD( EQ_ERR_RPT0_FIR14_PHANTOM_B01_REQ                       , 36  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PHANTOM_B01_REQ );
REG64_FLD( EQ_ERR_RPT0_FIR14_RC_UNEXP_F2_DATA                      , 37  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_F2_DATA );
REG64_FLD( EQ_ERR_RPT0_FIR14_RC_UNEXP_PURG_HIT                     , 38  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_PURG_HIT );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCX_UNEXP_IDLE_PBL3_DATA              , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_PBL3_DATA );
REG64_FLD( EQ_ERR_RPT0_FIR14_RCX_UNEXP_IDLE_PB_CRESP               , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_PB_CRESP );
REG64_FLD( EQ_ERR_RPT0_FIR14_COX_UNEXP_IDLE_PB_CRESP               , 41  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_COX_UNEXP_IDLE_PB_CRESP );

REG64_FLD( EX_L2_ERR_RPT0_FIR14_NCCTL_RLD_BARRIER                  , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_RLD_BARRIER );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_NCCTL_SNP                          , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_SNP );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_NCCTL_TLBIE_ACK                    , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_TLBIE_ACK );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_NCCTL_SYNC                         , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_SYNC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_NCCTL_VSYNC                        , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCCTL_VSYNC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_TMCTL_TIDX_TEND_LDST_SEQ           , 6   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_TMCTL_TIDX_TEND_LDST_SEQ );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RVCTL                              , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RVCTL );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_SRCTL0_BAD_HPC                     , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL0_BAD_HPC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_SRCTL1_BAD_HPC                     , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL1_BAD_HPC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_SRCTL2_BAD_HPC                     , 10  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL2_BAD_HPC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_SRCTL3_BAD_HPC                     , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_SRCTL3_BAD_HPC );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_PBARB_FSM_REQ_OVERFLOW             , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PBARB_FSM_REQ_OVERFLOW );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_PBARB_TRASHMODE_PB_REQ             , 13  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PBARB_TRASHMODE_PB_REQ );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_L3PF_MACH_DONE                     , 14  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_L3PF_MACH_DONE );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD0_TTAG_PERR                    , 15  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD0_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD1_TTAG_PERR                    , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD1_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD2_TTAG_PERR                    , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD2_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD3_TTAG_PERR                    , 18  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD3_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR0_TTAG_PERR                      , 19  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR0_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR0_ATAG_PERR                      , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR0_ATAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR1_TTAG_PERR                      , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR1_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR1_ATAG_PERR                      , 22  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR1_ATAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR2_TTAG_PERR                      , 23  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR2_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR2_ATAG_PERR                      , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR2_ATAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR3_TTAG_PERR                      , 25  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR3_TTAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_CR3_ATAG_PERR                      , 26  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_CR3_ATAG_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD0_ADDR_PERR                    , 27  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD0_ADDR_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD1_ADDR_PERR                    , 28  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD1_ADDR_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD2_ADDR_PERR                    , 29  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD2_ADDR_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCMD3_ADDR_PERR                    , 30  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCMD3_ADDR_PERR );
REG64_FLD( EX_L2_ERR_RPT0_FIR9_PEC_PHASE3_TIMEOUT                  , 31  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE3_TIMEOUT );
REG64_FLD( EX_L2_ERR_RPT0_FIR9_PEC_PHASE4_SAME                     , 32  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE4_SAME );
REG64_FLD( EX_L2_ERR_RPT0_FIR9_PEC_PHASE4_RCCO_DISP_FAIL           , 33  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE4_RCCO_DISP_FAIL );
REG64_FLD( EX_L2_ERR_RPT0_FIR9_PEC_PHASE5_TIMEOUT                  , 34  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR9_PEC_PHASE5_TIMEOUT );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_B01_BOTH_ACTIVE                    , 35  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B01_BOTH_ACTIVE );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_PHANTOM_B01_REQ                    , 36  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PHANTOM_B01_REQ );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RC_UNEXP_F2_DATA                   , 37  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_F2_DATA );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RC_UNEXP_PURG_HIT                  , 38  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_PURG_HIT );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCX_UNEXP_IDLE_PBL3_DATA           , 39  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_PBL3_DATA );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_RCX_UNEXP_IDLE_PB_CRESP            , 40  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_PB_CRESP );
REG64_FLD( EX_L2_ERR_RPT0_FIR14_COX_UNEXP_IDLE_PB_CRESP            , 41  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_COX_UNEXP_IDLE_PB_CRESP );

REG64_FLD( EQ_ERR_RPT1_FIR14_RCX_UNEXP_IDLE_L3_CRESP               , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_L3_CRESP );
REG64_FLD( EQ_ERR_RPT1_FIR14_RCX_UNEXP_IDLE_L3_DWDONE              , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_L3_DWDONE );
REG64_FLD( EQ_ERR_RPT1_FIR14_RCX_UNEXP_PB_RC_DTAG_PCHK             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_PB_RC_DTAG_PCHK );
REG64_FLD( EQ_ERR_RPT1_FIR14_DW_SET_REF_WITH_FLAG_IDLE             , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_DW_SET_REF_WITH_FLAG_IDLE );
REG64_FLD( EQ_ERR_RPT1_FIR14_KILL_REF_WITH_FLAG_IDLE               , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_KILL_REF_WITH_FLAG_IDLE );
REG64_FLD( EQ_ERR_RPT1_FIR14_DW_SET_SI_BY_MACH                     , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_DW_SET_SI_BY_MACH );
REG64_FLD( EQ_ERR_RPT1_FIR14_PD_DIR_MULT_HIT                       , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PD_DIR_MULT_HIT );
REG64_FLD( EQ_ERR_RPT1_FIR14_B0_SD_DIR_MULT_HIT                    , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B0_SD_DIR_MULT_HIT );
REG64_FLD( EQ_ERR_RPT1_FIR14_B1_SD_DIR_MULT_HIT                    , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B1_SD_DIR_MULT_HIT );
REG64_FLD( EQ_ERR_RPT1_FIR14_B2_SD_DIR_MULT_HIT                    , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B2_SD_DIR_MULT_HIT );
REG64_FLD( EQ_ERR_RPT1_FIR14_B3_SD_DIR_MULT_HIT                    , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B3_SD_DIR_MULT_HIT );
REG64_FLD( EQ_ERR_RPT1_FIR14_INVALID_SNP_CPS_STATU_RTN             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_INVALID_SNP_CPS_STATU_RTN );
REG64_FLD( EQ_ERR_RPT1_FIR14_HANG_WAITING_FOR_FP_MATE              , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_HANG_WAITING_FOR_FP_MATE );
REG64_FLD( EQ_ERR_RPT1_FIR14_BAD_FP_MATE                           , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_BAD_FP_MATE );
REG64_FLD( EQ_ERR_RPT1_FIR14_LSU_TAG_REUSE                         , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_LSU_TAG_REUSE );
REG64_FLD( EQ_ERR_RPT1_FIR14_IFU_MULT_REQ                          , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_IFU_MULT_REQ );
REG64_FLD( EQ_ERR_RPT1_FIR14_XPF_MULT_REQ                          , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_XPF_MULT_REQ );
REG64_FLD( EQ_ERR_RPT1_FIR14_XLT_QUEUE_OVRFLW                      , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_XLT_QUEUE_OVRFLW );
REG64_FLD( EQ_ERR_RPT1_FIR14_L3PF_REQ                              , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_L3PF_REQ );
REG64_FLD( EQ_ERR_RPT1_FIR14_NCU_TID_DONE                          , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCU_TID_DONE );
REG64_FLD( EQ_ERR_RPT1_FIR11_LRU_MEM_INVALID_ABCD                  , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR11_LRU_MEM_INVALID_ABCD );
REG64_FLD( EQ_ERR_RPT1_FIR11_LRU_MEM_INVALID_EFGH                  , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR11_LRU_MEM_INVALID_EFGH );
REG64_FLD( EQ_ERR_RPT1_FIR14_STQ_COMING                            , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_STQ_COMING );
REG64_FLD( EQ_ERR_RPT1_FIR14_STQ_OVERFLOW                          , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_STQ_OVERFLOW );
REG64_FLD( EQ_ERR_RPT1_FIR14_RC_PBBUS_SFSTAT                       , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_PBBUS_SFSTAT );
REG64_FLD( EQ_ERR_RPT1_FIR14_TMA_LARXA_VS_FRCMISS_SV               , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_TMA_LARXA_VS_FRCMISS_SV );
REG64_FLD( EQ_ERR_RPT1_FIR37_RC_TGT_NODAL_REQ_CRESP_DINC           , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR37_RC_TGT_NODAL_REQ_CRESP_DINC );
REG64_FLD( EQ_ERR_RPT1_FIR37_SN_TGT_NODAL_REQ_CRESP_DINC           , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR37_SN_TGT_NODAL_REQ_CRESP_DINC );
REG64_FLD( EQ_ERR_RPT1_FIR14_RC_UNEXP_DIRSTAT_VS_DSECT_CHK         , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_DIRSTAT_VS_DSECT_CHK );

REG64_FLD( EX_L2_ERR_RPT1_FIR14_RCX_UNEXP_IDLE_L3_CRESP            , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_L3_CRESP );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_RCX_UNEXP_IDLE_L3_DWDONE           , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_IDLE_L3_DWDONE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_RCX_UNEXP_PB_RC_DTAG_PCHK          , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RCX_UNEXP_PB_RC_DTAG_PCHK );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_DW_SET_REF_WITH_FLAG_IDLE          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_DW_SET_REF_WITH_FLAG_IDLE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_KILL_REF_WITH_FLAG_IDLE            , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_KILL_REF_WITH_FLAG_IDLE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_DW_SET_SI_BY_MACH                  , 6   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_DW_SET_SI_BY_MACH );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_PD_DIR_MULT_HIT                    , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_PD_DIR_MULT_HIT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_B0_SD_DIR_MULT_HIT                 , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B0_SD_DIR_MULT_HIT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_B1_SD_DIR_MULT_HIT                 , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B1_SD_DIR_MULT_HIT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_B2_SD_DIR_MULT_HIT                 , 10  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B2_SD_DIR_MULT_HIT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_B3_SD_DIR_MULT_HIT                 , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_B3_SD_DIR_MULT_HIT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_INVALID_SNP_CPS_STATU_RTN          , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_INVALID_SNP_CPS_STATU_RTN );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_HANG_WAITING_FOR_FP_MATE           , 13  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_HANG_WAITING_FOR_FP_MATE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_BAD_FP_MATE                        , 14  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_BAD_FP_MATE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_LSU_TAG_REUSE                      , 15  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_LSU_TAG_REUSE );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_IFU_MULT_REQ                       , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_IFU_MULT_REQ );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_XPF_MULT_REQ                       , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_XPF_MULT_REQ );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_XLT_QUEUE_OVRFLW                   , 18  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_XLT_QUEUE_OVRFLW );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_L3PF_REQ                           , 19  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_L3PF_REQ );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_NCU_TID_DONE                       , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_NCU_TID_DONE );
REG64_FLD( EX_L2_ERR_RPT1_FIR11_LRU_MEM_INVALID_ABCD               , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR11_LRU_MEM_INVALID_ABCD );
REG64_FLD( EX_L2_ERR_RPT1_FIR11_LRU_MEM_INVALID_EFGH               , 22  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR11_LRU_MEM_INVALID_EFGH );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_STQ_COMING                         , 23  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_STQ_COMING );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_STQ_OVERFLOW                       , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_STQ_OVERFLOW );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_RC_PBBUS_SFSTAT                    , 25  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_PBBUS_SFSTAT );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_TMA_LARXA_VS_FRCMISS_SV            , 26  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_TMA_LARXA_VS_FRCMISS_SV );
REG64_FLD( EX_L2_ERR_RPT1_FIR37_RC_TGT_NODAL_REQ_CRESP_DINC        , 27  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR37_RC_TGT_NODAL_REQ_CRESP_DINC );
REG64_FLD( EX_L2_ERR_RPT1_FIR37_SN_TGT_NODAL_REQ_CRESP_DINC        , 28  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR37_SN_TGT_NODAL_REQ_CRESP_DINC );
REG64_FLD( EX_L2_ERR_RPT1_FIR14_RC_UNEXP_DIRSTAT_VS_DSECT_CHK      , 29  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FIR14_RC_UNEXP_DIRSTAT_VS_DSECT_CHK );

REG64_FLD( EQ_ERR_RPT_REG_FIR0_OVERFLOW                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_OVERFLOW );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_ILLEGAL_STORE_SIZE                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_ILLEGAL_STORE_SIZE );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_LD_AMO_SEQ                          , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_LD_AMO_SEQ );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR0_TTAG_PERR                       , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR0_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR0_ATAG_PERR                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR0_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR1_TTAG_PERR                       , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR1_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR1_ATAG_PERR                       , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR1_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR2_TTAG_PERR                       , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR2_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR2_ATAG_PERR                       , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR2_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR3_TTAG_PERR                       , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR3_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_CR3_ATAG_PERR                       , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR3_ATAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_SNP0_ADDR_PERR                      , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP0_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_SNP0_TTAG_PERR                      , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP0_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_SNP1_ADDR_PERR                      , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP1_ADDR_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_SNP1_TTAG_PERR                      , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP1_TTAG_PERR );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PBARB_TRASHMODE                     , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PBARB_TRASHMODE );
REG64_FLD( EQ_ERR_RPT_REG_FIR1_TLBIE_BAD_OP                        , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_TLBIE_BAD_OP );
REG64_FLD( EQ_ERR_RPT_REG_FIR1_MASTER_SEQ_ID_PAR                   , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_MASTER_SEQ_ID_PAR );
REG64_FLD( EQ_ERR_RPT_REG_FIR1_SNOOP_TLBIE_SEQ_PARITY              , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_SNOOP_TLBIE_SEQ_PARITY );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PURGE_LVL_ERR1                      , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_LVL_ERR1 );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PURGE_LVL_ERR2                      , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_LVL_ERR2 );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PURGE_ABORT_LVL_ERR1                , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_ABORT_LVL_ERR1 );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PURGE_ABORT_LVL_ERR2                , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_ABORT_LVL_ERR2 );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PURGE_DONE_LVL_ERR1                 , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_DONE_LVL_ERR1 );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_IMA_FSM_TIMEOUT                     , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_IMA_FSM_TIMEOUT );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PPE_WR_FSM_TIMEOUT                  , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PPE_WR_FSM_TIMEOUT );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_PPE_RD_FSM_TIMEOUT                  , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PPE_RD_FSM_TIMEOUT );
REG64_FLD( EQ_ERR_RPT_REG_FIR0_TLB_DATA_PAR                        , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_TLB_DATA_PAR );
REG64_FLD( EQ_ERR_RPT_REG_FIR19_LD_TGT_NODAL_DINC                  , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR19_LD_TGT_NODAL_DINC );
REG64_FLD( EQ_ERR_RPT_REG_FIR19_ST_TGT_NODAL_DINC                  , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FIR19_ST_TGT_NODAL_DINC );

REG64_FLD( EX_ERR_RPT_REG_FIR0_OVERFLOW                            , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_OVERFLOW );
REG64_FLD( EX_ERR_RPT_REG_FIR0_ILLEGAL_STORE_SIZE                  , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_ILLEGAL_STORE_SIZE );
REG64_FLD( EX_ERR_RPT_REG_FIR0_LD_AMO_SEQ                          , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_LD_AMO_SEQ );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR0_TTAG_PERR                       , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR0_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR0_ATAG_PERR                       , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR0_ATAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR1_TTAG_PERR                       , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR1_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR1_ATAG_PERR                       , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR1_ATAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR2_TTAG_PERR                       , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR2_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR2_ATAG_PERR                       , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR2_ATAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR3_TTAG_PERR                       , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR3_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_CR3_ATAG_PERR                       , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_CR3_ATAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_SNP0_ADDR_PERR                      , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP0_ADDR_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_SNP0_TTAG_PERR                      , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP0_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_SNP1_ADDR_PERR                      , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP1_ADDR_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_SNP1_TTAG_PERR                      , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_SNP1_TTAG_PERR );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PBARB_TRASHMODE                     , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PBARB_TRASHMODE );
REG64_FLD( EX_ERR_RPT_REG_FIR1_TLBIE_BAD_OP                        , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_TLBIE_BAD_OP );
REG64_FLD( EX_ERR_RPT_REG_FIR1_MASTER_SEQ_ID_PAR                   , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_MASTER_SEQ_ID_PAR );
REG64_FLD( EX_ERR_RPT_REG_FIR1_SNOOP_TLBIE_SEQ_PARITY              , 18  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR1_SNOOP_TLBIE_SEQ_PARITY );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PURGE_LVL_ERR1                      , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_LVL_ERR1 );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PURGE_LVL_ERR2                      , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_LVL_ERR2 );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PURGE_ABORT_LVL_ERR1                , 21  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_ABORT_LVL_ERR1 );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PURGE_ABORT_LVL_ERR2                , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_ABORT_LVL_ERR2 );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PURGE_DONE_LVL_ERR1                 , 23  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PURGE_DONE_LVL_ERR1 );
REG64_FLD( EX_ERR_RPT_REG_FIR0_IMA_FSM_TIMEOUT                     , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_IMA_FSM_TIMEOUT );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PPE_WR_FSM_TIMEOUT                  , 25  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PPE_WR_FSM_TIMEOUT );
REG64_FLD( EX_ERR_RPT_REG_FIR0_PPE_RD_FSM_TIMEOUT                  , 26  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_PPE_RD_FSM_TIMEOUT );
REG64_FLD( EX_ERR_RPT_REG_FIR0_TLB_DATA_PAR                        , 27  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR0_TLB_DATA_PAR );
REG64_FLD( EX_ERR_RPT_REG_FIR19_LD_TGT_NODAL_DINC                  , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR19_LD_TGT_NODAL_DINC );
REG64_FLD( EX_ERR_RPT_REG_FIR19_ST_TGT_NODAL_DINC                  , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FIR19_ST_TGT_NODAL_DINC );

REG64_FLD( EQ_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK   , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK             , 17  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_THERM_MODEREG_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK           , 18  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_MODEREG_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK          , 19  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_FORCEREG_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK         , 20  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SCAN_INIT_VERSION_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK              , 21  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VOLT_MODEREG_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_COUNT_STATE_MASK                      , 23  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_COUNT_STATE_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_RUN_STATE_MASK                        , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_RUN_STATE_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_THRES_STATE_MASK                      , 25  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_THRES_STATE_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_OVERFLOW_MASK                         , 26  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_SHIFTER_PARITY_MASK                   , 27  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_PARITY_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_SHIFTER_VALID_MASK                    , 28  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_VALID_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_TIMEOUT_MASK                          , 29  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEOUT_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_F_SKITTER_READ_MASK                   , 30  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_F_SKITTER_READ_MASK );
REG64_FLD( EQ_ERR_STATUS_REG_PCB_MASK                              , 31  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCB_MASK   );

REG64_FLD( EX_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK   , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK             , 17  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_THERM_MODEREG_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK           , 18  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_MODEREG_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK          , 19  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_FORCEREG_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK         , 20  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SCAN_INIT_VERSION_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK              , 21  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VOLT_MODEREG_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_COUNT_STATE_MASK                      , 23  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_COUNT_STATE_MASK );
REG64_FLD( EX_ERR_STATUS_REG_RUN_STATE_MASK                        , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_RUN_STATE_MASK );
REG64_FLD( EX_ERR_STATUS_REG_THRES_STATE_MASK                      , 25  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_THRES_STATE_MASK );
REG64_FLD( EX_ERR_STATUS_REG_OVERFLOW_MASK                         , 26  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_MASK );
REG64_FLD( EX_ERR_STATUS_REG_SHIFTER_PARITY_MASK                   , 27  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_PARITY_MASK );
REG64_FLD( EX_ERR_STATUS_REG_SHIFTER_VALID_MASK                    , 28  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_VALID_MASK );
REG64_FLD( EX_ERR_STATUS_REG_TIMEOUT_MASK                          , 29  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEOUT_MASK );
REG64_FLD( EX_ERR_STATUS_REG_F_SKITTER_READ_MASK                   , 30  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_F_SKITTER_READ_MASK );
REG64_FLD( EX_ERR_STATUS_REG_PCB_MASK                              , 31  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PCB_MASK   );

REG64_FLD( C_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK    , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SERIAL_SHIFTCNT_MODEREG_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_THERM_MODEREG_PARITY_MASK              , 17  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_THERM_MODEREG_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_MASK            , 18  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_MODEREG_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_MASK           , 19  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SKITTER_FORCEREG_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_SCAN_INIT_VERSION_PARITY_MASK          , 20  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SCAN_INIT_VERSION_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_VOLT_MODEREG_PARITY_MASK               , 21  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VOLT_MODEREG_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_COUNT_STATE_MASK                       , 23  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_COUNT_STATE_MASK );
REG64_FLD( C_ERR_STATUS_REG_RUN_STATE_MASK                         , 24  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_RUN_STATE_MASK );
REG64_FLD( C_ERR_STATUS_REG_THRES_STATE_MASK                       , 25  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_THRES_STATE_MASK );
REG64_FLD( C_ERR_STATUS_REG_OVERFLOW_MASK                          , 26  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_MASK );
REG64_FLD( C_ERR_STATUS_REG_SHIFTER_PARITY_MASK                    , 27  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_PARITY_MASK );
REG64_FLD( C_ERR_STATUS_REG_SHIFTER_VALID_MASK                     , 28  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_SHIFTER_VALID_MASK );
REG64_FLD( C_ERR_STATUS_REG_TIMEOUT_MASK                           , 29  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEOUT_MASK );
REG64_FLD( C_ERR_STATUS_REG_F_SKITTER_READ_MASK                    , 30  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_F_SKITTER_READ_MASK );
REG64_FLD( C_ERR_STATUS_REG_PCB_MASK                               , 31  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_PCB_MASK   );

REG64_FLD( EQ_FIR_ACTION0_REG_ACTION0                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0    );
REG64_FLD( EQ_FIR_ACTION0_REG_ACTION0_LEN                          , 31  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0_LEN );

REG64_FLD( CAPP_FIR_ACTION0_REG_ACTION0                            , 0   , SH_UNT_CAPP     , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTION0    );
REG64_FLD( CAPP_FIR_ACTION0_REG_ACTION0_LEN                        , 51  , SH_UNT_CAPP     , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTION0_LEN );

REG64_FLD( EX_FIR_ACTION0_REG_ACTION0                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0    );
REG64_FLD( EX_FIR_ACTION0_REG_ACTION0_LEN                          , 31  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0_LEN );

REG64_FLD( EX_L2_FIR_ACTION0_REG_ACTION0                           , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0    );
REG64_FLD( EX_L2_FIR_ACTION0_REG_ACTION0_LEN                       , 42  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0_LEN );

REG64_FLD( EX_L3_FIR_ACTION0_REG_ACTION0                           , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0    );
REG64_FLD( EX_L3_FIR_ACTION0_REG_ACTION0_LEN                       , 31  , SH_UNT_EX_L3    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION0_LEN );

REG64_FLD( EQ_FIR_ACTION1_REG_ACTION1                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1    );
REG64_FLD( EQ_FIR_ACTION1_REG_ACTION1_LEN                          , 31  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1_LEN );

REG64_FLD( CAPP_FIR_ACTION1_REG_ACTION1                            , 0   , SH_UNT_CAPP     , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTION1    );
REG64_FLD( CAPP_FIR_ACTION1_REG_ACTION1_LEN                        , 51  , SH_UNT_CAPP     , SH_ACS_SCOM_RO  ,
           SH_FLD_ACTION1_LEN );

REG64_FLD( EX_FIR_ACTION1_REG_ACTION1                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1    );
REG64_FLD( EX_FIR_ACTION1_REG_ACTION1_LEN                          , 31  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1_LEN );

REG64_FLD( EX_L2_FIR_ACTION1_REG_ACTION1                           , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1    );
REG64_FLD( EX_L2_FIR_ACTION1_REG_ACTION1_LEN                       , 42  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1_LEN );

REG64_FLD( EX_L3_FIR_ACTION1_REG_ACTION1                           , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1    );
REG64_FLD( EX_L3_FIR_ACTION1_REG_ACTION1_LEN                       , 31  , SH_UNT_EX_L3    , SH_ACS_SCOM_RW  ,
           SH_FLD_ACTION1_LEN );

REG64_FLD( EQ_FIR_MASK_REG_CONTROL_ERR                             , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_CONTROL_ERR );
REG64_FLD( EQ_FIR_MASK_REG_TLBIE_SW_ERR                            , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SW_ERR );
REG64_FLD( EQ_FIR_MASK_REG_ST_ADDR_ERR                             , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_LD_ADDR_ERR                             , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_ST_FOREIGN0_ACK_DEAD                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_FOREIGN0_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_ST_FOREIGN1_ACK_DEAD                    , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_FOREIGN1_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_LD_FOREIGN0_ACK_DEAD                    , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_FOREIGN0_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_LD_FOREIGN1_ACK_DEAD                    , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_FOREIGN1_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_STQ_DATA_PARITY_ERR                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STQ_DATA_PARITY_ERR );
REG64_FLD( EQ_FIR_MASK_REG_STORE_TIMEOUT                           , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STORE_TIMEOUT );
REG64_FLD( EQ_FIR_MASK_REG_TLBIE_MASTER_TIMEOUT                    , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_MASTER_TIMEOUT );
REG64_FLD( EQ_FIR_MASK_REG_TLBIE_SNOOP_TIMEOUT                     , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SNOOP_TIMEOUT );
REG64_FLD( EQ_FIR_MASK_REG_HTM_IMA_TIMEOUT                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_HTM_IMA_TIMEOUT );
REG64_FLD( EQ_FIR_MASK_REG_IMA_CRESP_ADDR_ERR                      , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_IMA_FOREIGN0_ACK_DEAD                   , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_FOREIGN0_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_IMA_FOREIGN1_ACK_DEAD                   , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_FOREIGN1_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_PMISC_CRESP_ADDR_ERR                    , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMISC_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_TLBIE_CONTROL_ERR                       , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_CONTROL_ERR );
REG64_FLD( EQ_FIR_MASK_REG_PPE_RD_CRESP_ADDR_ERR                   , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_PPE_WR_CRESP_ADDR_ERR                   , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_MASK_REG_PPE_RD_FOREIGN0_ACK_DEAD                , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_FOREIGN0_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_PPE_RD_FOREIGN1_ACK_DEAD                , 21  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_FOREIGN1_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_PPE_WR_FOREIGN0_ACK_DEAD                , 22  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_FOREIGN0_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_PPE_WR_FOREIGN1_ACK_DEAD                , 23  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_FOREIGN1_ACK_DEAD );
REG64_FLD( EQ_FIR_MASK_REG_SPARE                                   , 24  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE      );
REG64_FLD( EQ_FIR_MASK_REG_SPARE_LEN                               , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_LEN  );
REG64_FLD( EQ_FIR_MASK_REG_SCOM_ERR1                               , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EQ_FIR_MASK_REG_SCOM_ERR2                               , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( CAPP_FIR_MASK_REG_BAR_PE                                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_BAR_PE     );
REG64_FLD( CAPP_FIR_MASK_REG_REGISTER_PE                           , 1   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_REGISTER_PE );
REG64_FLD( CAPP_FIR_MASK_REG_MASTER_ARRAY_CE                       , 2   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_ARRAY_CE );
REG64_FLD( CAPP_FIR_MASK_REG_MASTER_ARRAY_UE                       , 3   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_ARRAY_UE );
REG64_FLD( CAPP_FIR_MASK_REG_TIMER_EXPIRED_RECOV_ERROR             , 4   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIMER_EXPIRED_RECOV_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_TIMER_EXPIRED_XSTOP_ERROR             , 5   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIMER_EXPIRED_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_PSL_CMD_UE                            , 6   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PSL_CMD_UE );
REG64_FLD( CAPP_FIR_MASK_REG_PSL_CMD_SUE                           , 7   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PSL_CMD_SUE );
REG64_FLD( CAPP_FIR_MASK_REG_SNOOP_ARRAY_CE                        , 8   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOP_ARRAY_CE );
REG64_FLD( CAPP_FIR_MASK_REG_SNOOP_ARRAY_UE                        , 9   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOP_ARRAY_UE );
REG64_FLD( CAPP_FIR_MASK_REG_RECOVERY_FAILED                       , 10  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_RECOVERY_FAILED );
REG64_FLD( CAPP_FIR_MASK_REG_ILLEGAL_LPC_BAR_ACCESS                , 11  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ILLEGAL_LPC_BAR_ACCESS );
REG64_FLD( CAPP_FIR_MASK_REG_XPT_RECOVERABLE_ERROR                 , 12  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_MASTER_RECOVERABLE_ERROR              , 13  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_SNOOPER_RECOVERABLE_ERROR             , 14  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOPER_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_SECURE_SCOM_ERROR                     , 15  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SECURE_SCOM_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_MASTER_SYS_XSTOP_ERROR                , 16  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_SNOOPER_SYS_XSTOP_ERROR               , 17  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOPER_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_XPT_SYS_XSTOP_ERROR                   , 18  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_MUOP_ERROR_1                          , 19  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_1 );
REG64_FLD( CAPP_FIR_MASK_REG_MUOP_ERROR_2                          , 20  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_2 );
REG64_FLD( CAPP_FIR_MASK_REG_MUOP_ERROR_3                          , 21  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_3 );
REG64_FLD( CAPP_FIR_MASK_REG_SUOP_ERROR_1                          , 22  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_1 );
REG64_FLD( CAPP_FIR_MASK_REG_SUOP_ERROR_2                          , 23  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_2 );
REG64_FLD( CAPP_FIR_MASK_REG_SUOP_ERROR_3                          , 24  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_3 );
REG64_FLD( CAPP_FIR_MASK_REG_POWERBUS_MISC_ERROR                   , 25  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_MISC_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_POWERBUS_INTERFACE_PE                 , 26  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_INTERFACE_PE );
REG64_FLD( CAPP_FIR_MASK_REG_POWERBUS_DATA_HANG_ERROR              , 27  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_DATA_HANG_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_POWERBUS_HANG_ERROR                   , 28  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_HANG_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_LD_CLASS_CMD_ADDR_ERR                 , 29  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_CLASS_CMD_ADDR_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_ST_CLASS_CMD_ADDR_ERR                 , 30  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_CLASS_CMD_ADDR_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_PHB_LINK_DOWN                         , 31  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PHB_LINK_DOWN );
REG64_FLD( CAPP_FIR_MASK_REG_LD_CLASS_CMD_FOREIGN_LINK_FAIL        , 32  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_CLASS_CMD_FOREIGN_LINK_FAIL );
REG64_FLD( CAPP_FIR_MASK_REG_FOREIGN_LINK_HANG_ERROR               , 33  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_FOREIGN_LINK_HANG_ERROR );
REG64_FLD( CAPP_FIR_MASK_REG_XPT_POWERBUS_CE                       , 34  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_CE );
REG64_FLD( CAPP_FIR_MASK_REG_XPT_POWERBUS_UE                       , 35  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_UE );
REG64_FLD( CAPP_FIR_MASK_REG_XPT_POWERBUS_SUE                      , 36  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_SUE );
REG64_FLD( CAPP_FIR_MASK_REG_TLBI_TIMEOUT                          , 37  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_TIMEOUT );
REG64_FLD( CAPP_FIR_MASK_REG_TLBI_SEQ_ERR                          , 38  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_SEQ_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_TLBI_BAD_OP_ERR                       , 39  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_BAD_OP_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_TLBI_SEQ_NUM_PARITY_ERR               , 40  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_SEQ_NUM_PARITY_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_ST_CLASS_CMD_FOREIGN_LINK_FAIL        , 41  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_CLASS_CMD_FOREIGN_LINK_FAIL );
REG64_FLD( CAPP_FIR_MASK_REG_TIME_BASE_ERR                         , 42  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIME_BASE_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_TRANSPORT_INFORMATIONAL_ERR           , 43  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TRANSPORT_INFORMATIONAL_ERR );
REG64_FLD( CAPP_FIR_MASK_REG_SPARE_2                               , 44  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_2    );
REG64_FLD( CAPP_FIR_MASK_REG_SPARE_3                               , 45  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_3    );
REG64_FLD( CAPP_FIR_MASK_REG_SPARE_4                               , 46  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_4    );
REG64_FLD( CAPP_FIR_MASK_REG_APC_ARRAY_CMD_CE_ERPT                 , 47  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_APC_ARRAY_CMD_CE_ERPT );
REG64_FLD( CAPP_FIR_MASK_REG_APC_ARRAY_CMD_UE_ERPT                 , 48  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_APC_ARRAY_CMD_UE_ERPT );
REG64_FLD( CAPP_FIR_MASK_REG_SCOM_ERR2                             , 49  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );
REG64_FLD( CAPP_FIR_MASK_REG_SCOM_ERR                              , 50  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR   );

REG64_FLD( EX_FIR_MASK_REG_CONTROL_ERR                             , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CONTROL_ERR );
REG64_FLD( EX_FIR_MASK_REG_TLBIE_SW_ERR                            , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SW_ERR );
REG64_FLD( EX_FIR_MASK_REG_ST_ADDR_ERR                             , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_LD_ADDR_ERR                             , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_ST_FOREIGN0_ACK_DEAD                    , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_FOREIGN0_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_ST_FOREIGN1_ACK_DEAD                    , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_FOREIGN1_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_LD_FOREIGN0_ACK_DEAD                    , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_FOREIGN0_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_LD_FOREIGN1_ACK_DEAD                    , 7   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_FOREIGN1_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_STQ_DATA_PARITY_ERR                     , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STQ_DATA_PARITY_ERR );
REG64_FLD( EX_FIR_MASK_REG_STORE_TIMEOUT                           , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STORE_TIMEOUT );
REG64_FLD( EX_FIR_MASK_REG_TLBIE_MASTER_TIMEOUT                    , 10  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_MASTER_TIMEOUT );
REG64_FLD( EX_FIR_MASK_REG_TLBIE_SNOOP_TIMEOUT                     , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SNOOP_TIMEOUT );
REG64_FLD( EX_FIR_MASK_REG_HTM_IMA_TIMEOUT                         , 12  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_HTM_IMA_TIMEOUT );
REG64_FLD( EX_FIR_MASK_REG_IMA_CRESP_ADDR_ERR                      , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_IMA_FOREIGN0_ACK_DEAD                   , 14  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_FOREIGN0_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_IMA_FOREIGN1_ACK_DEAD                   , 15  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_FOREIGN1_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_PMISC_CRESP_ADDR_ERR                    , 16  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMISC_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_TLBIE_CONTROL_ERR                       , 17  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_CONTROL_ERR );
REG64_FLD( EX_FIR_MASK_REG_PPE_RD_CRESP_ADDR_ERR                   , 18  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_PPE_WR_CRESP_ADDR_ERR                   , 19  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_MASK_REG_PPE_RD_FOREIGN0_ACK_DEAD                , 20  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_FOREIGN0_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_PPE_RD_FOREIGN1_ACK_DEAD                , 21  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_FOREIGN1_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_PPE_WR_FOREIGN0_ACK_DEAD                , 22  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_FOREIGN0_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_PPE_WR_FOREIGN1_ACK_DEAD                , 23  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_FOREIGN1_ACK_DEAD );
REG64_FLD( EX_FIR_MASK_REG_SPARE                                   , 24  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE      );
REG64_FLD( EX_FIR_MASK_REG_SPARE_LEN                               , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_LEN  );
REG64_FLD( EX_FIR_MASK_REG_SCOM_ERR1                               , 29  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EX_FIR_MASK_REG_SCOM_ERR2                               , 30  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( EX_L2_FIR_MASK_REG_L2                                   , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_L2         );
REG64_FLD( EX_L2_FIR_MASK_REG_L2_LEN                               , 42  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_L2_LEN     );

REG64_FLD( EQ_FIR_REG_CONTROL_ERR                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_CONTROL_ERR );
REG64_FLD( EQ_FIR_REG_TLBIE_CONTROL_ERR                            , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_CONTROL_ERR );
REG64_FLD( EQ_FIR_REG_TLBIE_SLBIEG_SW_ERR                          , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SLBIEG_SW_ERR );
REG64_FLD( EQ_FIR_REG_ST_ADDR_ERR                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_LD_ADDR_ERR                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_ST_ACK_DEAD                                  , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ACK_DEAD );
REG64_FLD( EQ_FIR_REG_LD_ACK_DEAD                                  , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ACK_DEAD );
REG64_FLD( EQ_FIR_REG_MSG_ADDR_ERR                                 , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_MSG_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_STQ_DATA_PARITY_ERR                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STQ_DATA_PARITY_ERR );
REG64_FLD( EQ_FIR_REG_STORE_TIMEOUT                                , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_STORE_TIMEOUT );
REG64_FLD( EQ_FIR_REG_TLBIE_MASTER_TIMEOUT                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_MASTER_TIMEOUT );
REG64_FLD( EQ_FIR_REG_TLBIE_SNOOP_TIMEOUT                          , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SNOOP_TIMEOUT );
REG64_FLD( EQ_FIR_REG_IMA_CRESP_ADDR_ERR                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_IMA_ACK_DEAD                                 , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_ACK_DEAD );
REG64_FLD( EQ_FIR_REG_PMISC_CRESP_ADDR_ERR                         , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMISC_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_PPE_RD_CRESP_ADDR_ERR                        , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_PPE_WR_CRESP_ADDR_ERR                        , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_CRESP_ADDR_ERR );
REG64_FLD( EQ_FIR_REG_PPE_RD_ACK_DEAD                              , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_ACK_DEAD );
REG64_FLD( EQ_FIR_REG_PPE_WR_ACK_DEAD                              , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_ACK_DEAD );
REG64_FLD( EQ_FIR_REG_TGT_NODAL_DINC_ERR                           , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_TGT_NODAL_DINC_ERR );
REG64_FLD( EQ_FIR_REG_SPARE                                        , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE      );
REG64_FLD( EQ_FIR_REG_SPARE_LEN                                    , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_LEN  );
REG64_FLD( EQ_FIR_REG_SCOM_ERR1                                    , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EQ_FIR_REG_SCOM_ERR2                                    , 30  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( CAPP_FIR_REG_BAR_PE                                     , 0   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_BAR_PE     );
REG64_FLD( CAPP_FIR_REG_REGISTER_PE                                , 1   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_REGISTER_PE );
REG64_FLD( CAPP_FIR_REG_MASTER_ARRAY_CE                            , 2   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_ARRAY_CE );
REG64_FLD( CAPP_FIR_REG_MASTER_ARRAY_UE                            , 3   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_ARRAY_UE );
REG64_FLD( CAPP_FIR_REG_TIMER_EXPIRED_RECOV_ERROR                  , 4   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIMER_EXPIRED_RECOV_ERROR );
REG64_FLD( CAPP_FIR_REG_TIMER_EXPIRED_XSTOP_ERROR                  , 5   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIMER_EXPIRED_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_REG_PSL_CMD_UE                                 , 6   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PSL_CMD_UE );
REG64_FLD( CAPP_FIR_REG_PSL_CMD_SUE                                , 7   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PSL_CMD_SUE );
REG64_FLD( CAPP_FIR_REG_SNOOP_ARRAY_CE                             , 8   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOP_ARRAY_CE );
REG64_FLD( CAPP_FIR_REG_SNOOP_ARRAY_UE                             , 9   , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOP_ARRAY_UE );
REG64_FLD( CAPP_FIR_REG_RECOVERY_FAILED                            , 10  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_RECOVERY_FAILED );
REG64_FLD( CAPP_FIR_REG_ILLEGAL_LPC_BAR_ACCESS                     , 11  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ILLEGAL_LPC_BAR_ACCESS );
REG64_FLD( CAPP_FIR_REG_XPT_RECOVERABLE_ERROR                      , 12  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_REG_MASTER_RECOVERABLE_ERROR                   , 13  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_REG_SNOOPER_RECOVERABLE_ERROR                  , 14  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOPER_RECOVERABLE_ERROR );
REG64_FLD( CAPP_FIR_REG_SECURE_SCOM_ERROR                          , 15  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SECURE_SCOM_ERROR );
REG64_FLD( CAPP_FIR_REG_MASTER_SYS_XSTOP_ERROR                     , 16  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MASTER_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_REG_SNOOPER_SYS_XSTOP_ERROR                    , 17  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SNOOPER_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_REG_XPT_SYS_XSTOP_ERROR                        , 18  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_SYS_XSTOP_ERROR );
REG64_FLD( CAPP_FIR_REG_MUOP_ERROR_1                               , 19  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_1 );
REG64_FLD( CAPP_FIR_REG_MUOP_ERROR_2                               , 20  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_2 );
REG64_FLD( CAPP_FIR_REG_MUOP_ERROR_3                               , 21  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_MUOP_ERROR_3 );
REG64_FLD( CAPP_FIR_REG_SUOP_ERROR_1                               , 22  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_1 );
REG64_FLD( CAPP_FIR_REG_SUOP_ERROR_2                               , 23  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_2 );
REG64_FLD( CAPP_FIR_REG_SUOP_ERROR_3                               , 24  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SUOP_ERROR_3 );
REG64_FLD( CAPP_FIR_REG_POWERBUS_MISC_ERROR                        , 25  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_MISC_ERROR );
REG64_FLD( CAPP_FIR_REG_POWERBUS_INTERFACE_PE                      , 26  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_INTERFACE_PE );
REG64_FLD( CAPP_FIR_REG_POWERBUS_DATA_HANG_ERROR                   , 27  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_DATA_HANG_ERROR );
REG64_FLD( CAPP_FIR_REG_POWERBUS_HANG_ERROR                        , 28  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_POWERBUS_HANG_ERROR );
REG64_FLD( CAPP_FIR_REG_LD_CLASS_CMD_ADDR_ERR                      , 29  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_CLASS_CMD_ADDR_ERR );
REG64_FLD( CAPP_FIR_REG_ST_CLASS_CMD_ADDR_ERR                      , 30  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_CLASS_CMD_ADDR_ERR );
REG64_FLD( CAPP_FIR_REG_PHB_LINK_DOWN                              , 31  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PHB_LINK_DOWN );
REG64_FLD( CAPP_FIR_REG_LD_CLASS_CMD_FOREIGN_LINK_FAIL             , 32  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_CLASS_CMD_FOREIGN_LINK_FAIL );
REG64_FLD( CAPP_FIR_REG_FOREIGN_LINK_HANG_ERROR                    , 33  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_FOREIGN_LINK_HANG_ERROR );
REG64_FLD( CAPP_FIR_REG_XPT_POWERBUS_CE                            , 34  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_CE );
REG64_FLD( CAPP_FIR_REG_XPT_POWERBUS_UE                            , 35  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_UE );
REG64_FLD( CAPP_FIR_REG_XPT_POWERBUS_SUE                           , 36  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_XPT_POWERBUS_SUE );
REG64_FLD( CAPP_FIR_REG_TLBI_TIMEOUT                               , 37  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_TIMEOUT );
REG64_FLD( CAPP_FIR_REG_TLBI_SEQ_ERR                               , 38  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_SEQ_ERR );
REG64_FLD( CAPP_FIR_REG_TLBI_BAD_OP_ERR                            , 39  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_BAD_OP_ERR );
REG64_FLD( CAPP_FIR_REG_TLBI_SEQ_NUM_PARITY_ERR                    , 40  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBI_SEQ_NUM_PARITY_ERR );
REG64_FLD( CAPP_FIR_REG_ST_CLASS_CMD_FOREIGN_LINK_FAIL             , 41  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_CLASS_CMD_FOREIGN_LINK_FAIL );
REG64_FLD( CAPP_FIR_REG_TIME_BASE_ERR                              , 42  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TIME_BASE_ERR );
REG64_FLD( CAPP_FIR_REG_TRANSPORT_INFORMATIONAL_ERR                , 43  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_TRANSPORT_INFORMATIONAL_ERR );
REG64_FLD( CAPP_FIR_REG_APC_ARRAY_CMD_CE_ERPT                      , 44  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_APC_ARRAY_CMD_CE_ERPT );
REG64_FLD( CAPP_FIR_REG_APC_ARRAY_CMD_UE_ERPT                      , 45  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_APC_ARRAY_CMD_UE_ERPT );
REG64_FLD( CAPP_FIR_REG_PSL_CREDIT_TIMEOUT_ERR                     , 46  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_PSL_CREDIT_TIMEOUT_ERR );
REG64_FLD( CAPP_FIR_REG_SPARE_2                                    , 47  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_2    );
REG64_FLD( CAPP_FIR_REG_HYPERVISOR                                 , 48  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_HYPERVISOR );
REG64_FLD( CAPP_FIR_REG_SPARE_3                                    , 49  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_3    );
REG64_FLD( CAPP_FIR_REG_SCOM_ERR2                                  , 50  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );
REG64_FLD( CAPP_FIR_REG_SCOM_ERR                                   , 51  , SH_UNT_CAPP     , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR   );

REG64_FLD( EX_FIR_REG_CONTROL_ERR                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CONTROL_ERR );
REG64_FLD( EX_FIR_REG_TLBIE_CONTROL_ERR                            , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_CONTROL_ERR );
REG64_FLD( EX_FIR_REG_TLBIE_SLBIEG_SW_ERR                          , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SLBIEG_SW_ERR );
REG64_FLD( EX_FIR_REG_ST_ADDR_ERR                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ADDR_ERR );
REG64_FLD( EX_FIR_REG_LD_ADDR_ERR                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ADDR_ERR );
REG64_FLD( EX_FIR_REG_ST_ACK_DEAD                                  , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_ST_ACK_DEAD );
REG64_FLD( EX_FIR_REG_LD_ACK_DEAD                                  , 6   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LD_ACK_DEAD );
REG64_FLD( EX_FIR_REG_MSG_ADDR_ERR                                 , 7   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_MSG_ADDR_ERR );
REG64_FLD( EX_FIR_REG_STQ_DATA_PARITY_ERR                          , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STQ_DATA_PARITY_ERR );
REG64_FLD( EX_FIR_REG_STORE_TIMEOUT                                , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_STORE_TIMEOUT );
REG64_FLD( EX_FIR_REG_TLBIE_MASTER_TIMEOUT                         , 10  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_MASTER_TIMEOUT );
REG64_FLD( EX_FIR_REG_TLBIE_SNOOP_TIMEOUT                          , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TLBIE_SNOOP_TIMEOUT );
REG64_FLD( EX_FIR_REG_IMA_CRESP_ADDR_ERR                           , 12  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_REG_IMA_ACK_DEAD                                 , 13  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IMA_ACK_DEAD );
REG64_FLD( EX_FIR_REG_PMISC_CRESP_ADDR_ERR                         , 14  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PMISC_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_REG_PPE_RD_CRESP_ADDR_ERR                        , 15  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_REG_PPE_WR_CRESP_ADDR_ERR                        , 16  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_CRESP_ADDR_ERR );
REG64_FLD( EX_FIR_REG_PPE_RD_ACK_DEAD                              , 17  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_RD_ACK_DEAD );
REG64_FLD( EX_FIR_REG_PPE_WR_ACK_DEAD                              , 18  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PPE_WR_ACK_DEAD );
REG64_FLD( EX_FIR_REG_TGT_NODAL_DINC_ERR                           , 19  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TGT_NODAL_DINC_ERR );
REG64_FLD( EX_FIR_REG_SPARE                                        , 20  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE      );
REG64_FLD( EX_FIR_REG_SPARE_LEN                                    , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SPARE_LEN  );
REG64_FLD( EX_FIR_REG_SCOM_ERR1                                    , 29  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EX_FIR_REG_SCOM_ERR2                                    , 30  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( EX_L2_FIR_REG_CACHE_RD_CE                               , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_RD_CE );
REG64_FLD( EX_L2_FIR_REG_CACHE_RD_UE                               , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_RD_UE );
REG64_FLD( EX_L2_FIR_REG_CACHE_RD_SUE                              , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_RD_SUE );
REG64_FLD( EX_L2_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED      , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_HW_DIR_INTIATED_LINE_DELETE_OCCURRED );
REG64_FLD( EX_L2_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO );
REG64_FLD( EX_L2_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO );
REG64_FLD( EX_L2_FIR_REG_DIR_CE_DETECTED                           , 6   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_DIR_CE_DETECTED );
REG64_FLD( EX_L2_FIR_REG_DIR_UE_DETECTED                           , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_DIR_UE_DETECTED );
REG64_FLD( EX_L2_FIR_REG_DIR_STUCK_BIT_CE                          , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_DIR_STUCK_BIT_CE );
REG64_FLD( EX_L2_FIR_REG_DIR_SBCE_REPAIR_FAILED                    , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_DIR_SBCE_REPAIR_FAILED );
REG64_FLD( EX_L2_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED              , 10  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_MULTIPLE_DIR_ERRORS_DETECTED );
REG64_FLD( EX_L2_FIR_REG_LRU_READ_ERROR_DETECTED                   , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_LRU_READ_ERROR_DETECTED );
REG64_FLD( EX_L2_FIR_REG_RC_POWERBUS_DATA_TIMEOUT                  , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_POWERBUS_DATA_TIMEOUT );
REG64_FLD( EX_L2_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT                 , 13  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_NCU_POWERBUS_DATA_TIMEOUT );
REG64_FLD( EX_L2_FIR_REG_HW_CONTROL_ERROR                          , 14  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_HW_CONTROL_ERROR );
REG64_FLD( EX_L2_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED   , 15  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED );
REG64_FLD( EX_L2_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR       , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_INHIBITED_HIT_CACHEABLE_ERROR );
REG64_FLD( EX_L2_FIR_REG_RC_LOAD_RECIVED_PB_CRESP_ADR_ERR          , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_LOAD_RECIVED_PB_CRESP_ADR_ERR );
REG64_FLD( EX_L2_FIR_REG_RC_STORE_RECIVED_PB_CRESP_ADR_ERR         , 18  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_STORE_RECIVED_PB_CRESP_ADR_ERR );
REG64_FLD( EX_L2_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK          , 19  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK );
REG64_FLD( EX_L2_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK          , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK );
REG64_FLD( EX_L2_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK         , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK );
REG64_FLD( EX_L2_FIR_REG_TGT_NODAL_REQ_DINC_ERR                    , 22  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TGT_NODAL_REQ_DINC_ERR );
REG64_FLD( EX_L2_FIR_REG_RC_LOAD_RECIVED_PB_CRESP_ADR_ERR_FOR_HYP  , 23  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_LOAD_RECIVED_PB_CRESP_ADR_ERR_FOR_HYP );
REG64_FLD( EX_L2_FIR_REG_RCDAT_RD_PARITY_ERR                       , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RCDAT_RD_PARITY_ERR );
REG64_FLD( EX_L2_FIR_REG_LVDIR_PERR                                , 26  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_LVDIR_PERR );
REG64_FLD( EX_L2_FIR_REG_RC_LOAD_RECEIVED_PB_ACK_DEAD_FROM_ALINKRECOV , 27  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_LOAD_RECEIVED_PB_ACK_DEAD_FROM_ALINKRECOV );
REG64_FLD( EX_L2_FIR_REG_RC_STORE_RECEIVED_PB_ACK_DEAD_FROM_ALINKRECOV , 29  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_RC_STORE_RECEIVED_PB_ACK_DEAD_FROM_ALINKRECOV );
REG64_FLD( EX_L2_FIR_REG_CACHE_RD_CE_AND_UE                        , 36  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CACHE_RD_CE_AND_UE );
REG64_FLD( EX_L2_FIR_REG_SCOM_ERR1                                 , 40  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EX_L2_FIR_REG_SCOM_ERR2                                 , 41  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( EX_L3_FIR_REG_PB_CMD_ERR                                , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_PB_CMD_ERR );
REG64_FLD( EX_L3_FIR_REG_PB_DATA_ERR                               , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_PB_DATA_ERR );
REG64_FLD( EX_L3_FIR_REG_L3_DRAM_POS_WORDLINE_FAIL                 , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_DRAM_POS_WORDLINE_FAIL );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_RD_CE_DET_NOT_LINDEL_REQ           , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_RD_CE_DET_NOT_LINDEL_REQ );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_RD_UE_DET                          , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_RD_UE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_RD_SUE_DET                         , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_RD_SUE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_CE_FROM_PB                 , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_CE_FROM_PB );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_UE_FROM_PB                 , 8   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_UE_FROM_PB );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_SUE_FROM_PB                , 9   , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_SUE_FROM_PB );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_CE_FROM_L2                 , 10  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_CE_FROM_L2 );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_UE_FROM_L2                 , 11  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_UE_FROM_L2 );
REG64_FLD( EX_L3_FIR_REG_L3_CAC_WR_DATA_SUE_FROM_L2_OR_WIHPC       , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CAC_WR_DATA_SUE_FROM_L2_OR_WIHPC );
REG64_FLD( EX_L3_FIR_REG_L3_DIR_RD_CE_DET                          , 13  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_DIR_RD_CE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_DIR_RD_UE_DET                          , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_DIR_RD_UE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_DIR_RD_PHANTOM_ERROR                   , 15  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_DIR_RD_PHANTOM_ERROR );
REG64_FLD( EX_L3_FIR_REG_L3_CO_SN_CRESP_ADDR_ERR                   , 16  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CO_SN_CRESP_ADDR_ERR );
REG64_FLD( EX_L3_FIR_REG_L3_PF_CRESP_ADDR_ERR                      , 17  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_PF_CRESP_ADDR_ERR );
REG64_FLD( EX_L3_FIR_REG_L3_ADDR_HANG_DETECTED                     , 18  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_ADDR_HANG_DETECTED );
REG64_FLD( EX_L3_FIR_REG_L3_LRU_INVAL_CNT                          , 19  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_LRU_INVAL_CNT );
REG64_FLD( EX_L3_FIR_REG_L3_PPE_RD_CE_DET                          , 20  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_PPE_RD_CE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_PPE_RD_UE_DET                          , 21  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_PPE_RD_UE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_PPE_RD_SUE_DET                         , 22  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_PPE_RD_SUE_DET );
REG64_FLD( EX_L3_FIR_REG_L3_MACH_HANG_DETECTED                     , 23  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_MACH_HANG_DETECTED );
REG64_FLD( EX_L3_FIR_REG_L3_HW_CONTROL_ERR                         , 24  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_HW_CONTROL_ERR );
REG64_FLD( EX_L3_FIR_REG_L3_SNOOP_SW_ERR_DETECTED                  , 25  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_SNOOP_SW_ERR_DETECTED );
REG64_FLD( EX_L3_FIR_REG_L3_LINE_DEL_CE_DONE                       , 26  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_LINE_DEL_CE_DONE );
REG64_FLD( EX_L3_FIR_REG_L3_DRAM_ERROR                             , 27  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_DRAM_ERROR );
REG64_FLD( EX_L3_FIR_REG_L3_LRU_ERROR                              , 28  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_LRU_ERROR );
REG64_FLD( EX_L3_FIR_REG_L3_ALL_MEMBERS_DELETED_ERROR              , 29  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_ALL_MEMBERS_DELETED_ERROR );
REG64_FLD( EX_L3_FIR_REG_L3_REFRESH_TIMER_ERROR                    , 30  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_REFRESH_TIMER_ERROR );
REG64_FLD( EX_L3_FIR_REG_L3_CO_SN_CRESP_ACK_DEAD_CACR4             , 31  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_CO_SN_CRESP_ACK_DEAD_CACR4 );
REG64_FLD( EX_L3_FIR_REG_L3_PF_CRESP_ACK_DEAD_CACR4                , 32  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_PF_CRESP_ACK_DEAD_CACR4 );
REG64_FLD( EX_L3_FIR_REG_SCOM_ERR1                                 , 33  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR1  );
REG64_FLD( EX_L3_FIR_REG_SCOM_ERR2                                 , 34  , SH_UNT_EX_L3    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_ERR2  );

REG64_FLD( CAPP_FLUSHCPIG_FLUSH_CP_IG_STATE_MAP                    , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_CP_IG_STATE_MAP );
REG64_FLD( CAPP_FLUSHCPIG_FLUSH_CP_IG_STATE_MAP_LEN                , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_CP_IG_STATE_MAP_LEN );

REG64_FLD( CAPP_FLUSHSHUE_FLUSH_SUE_STATE_MAP                      , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_SUE_STATE_MAP );
REG64_FLD( CAPP_FLUSHSHUE_FLUSH_SUE_STATE_MAP_LEN                  , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_SUE_STATE_MAP_LEN );

REG64_FLD( EQ_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN );
REG64_FLD( EQ_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN_LEN                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN_LEN );

REG64_FLD( EX_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN                     , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN );
REG64_FLD( EX_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN_LEN                 , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN_LEN );

REG64_FLD( C_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN                      , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN );
REG64_FLD( C_GXSTOP0_MASK_REG_GXSTP0_XSTOP_IN_LEN                  , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP0_XSTOP_IN_LEN );

REG64_FLD( EQ_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN );
REG64_FLD( EQ_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN_LEN                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN_LEN );

REG64_FLD( EX_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN                     , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN );
REG64_FLD( EX_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN_LEN                 , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN_LEN );

REG64_FLD( C_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN                      , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN );
REG64_FLD( C_GXSTOP1_MASK_REG_GXSTP1_XSTOP_IN_LEN                  , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP1_XSTOP_IN_LEN );

REG64_FLD( EQ_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN );
REG64_FLD( EQ_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN_LEN                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN_LEN );

REG64_FLD( EX_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN                     , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN );
REG64_FLD( EX_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN_LEN                 , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN_LEN );

REG64_FLD( C_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN                      , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN );
REG64_FLD( C_GXSTOP2_MASK_REG_GXSTP2_XSTOP_IN_LEN                  , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP2_XSTOP_IN_LEN );

REG64_FLD( EQ_GXSTOP_TRIG_REG_GXSTP_IN                             , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN   );
REG64_FLD( EQ_GXSTOP_TRIG_REG_GXSTP_IN_LEN                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN_LEN );

REG64_FLD( EX_GXSTOP_TRIG_REG_GXSTP_IN                             , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN   );
REG64_FLD( EX_GXSTOP_TRIG_REG_GXSTP_IN_LEN                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN_LEN );

REG64_FLD( C_GXSTOP_TRIG_REG_GXSTP_IN                              , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN   );
REG64_FLD( C_GXSTOP_TRIG_REG_GXSTP_IN_LEN                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GXSTP_IN_LEN );

REG64_FLD( EQ_HANG_PULSE_0_REG_0                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_0          );
REG64_FLD( EQ_HANG_PULSE_0_REG_0_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_0_LEN      );
REG64_FLD( EQ_HANG_PULSE_0_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_0_REG_0                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_0          );
REG64_FLD( EX_HANG_PULSE_0_REG_0_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_0_LEN      );
REG64_FLD( EX_HANG_PULSE_0_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_0_REG_0                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_0          );
REG64_FLD( C_HANG_PULSE_0_REG_0_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_0_LEN      );
REG64_FLD( C_HANG_PULSE_0_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_1_REG_1                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_1          );
REG64_FLD( EQ_HANG_PULSE_1_REG_1_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_1_LEN      );
REG64_FLD( EQ_HANG_PULSE_1_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_1_REG_1                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_1          );
REG64_FLD( EX_HANG_PULSE_1_REG_1_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_1_LEN      );
REG64_FLD( EX_HANG_PULSE_1_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_1_REG_1                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_1          );
REG64_FLD( C_HANG_PULSE_1_REG_1_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_1_LEN      );
REG64_FLD( C_HANG_PULSE_1_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_2_REG_2                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_2          );
REG64_FLD( EQ_HANG_PULSE_2_REG_2_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_2_LEN      );
REG64_FLD( EQ_HANG_PULSE_2_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_2_REG_2                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_2          );
REG64_FLD( EX_HANG_PULSE_2_REG_2_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_2_LEN      );
REG64_FLD( EX_HANG_PULSE_2_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_2_REG_2                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_2          );
REG64_FLD( C_HANG_PULSE_2_REG_2_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_2_LEN      );
REG64_FLD( C_HANG_PULSE_2_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_3_REG_3                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_3          );
REG64_FLD( EQ_HANG_PULSE_3_REG_3_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_3_LEN      );
REG64_FLD( EQ_HANG_PULSE_3_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_3_REG_3                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_3          );
REG64_FLD( EX_HANG_PULSE_3_REG_3_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_3_LEN      );
REG64_FLD( EX_HANG_PULSE_3_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_3_REG_3                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_3          );
REG64_FLD( C_HANG_PULSE_3_REG_3_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_3_LEN      );
REG64_FLD( C_HANG_PULSE_3_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_4_REG_4                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_4          );
REG64_FLD( EQ_HANG_PULSE_4_REG_4_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_4_LEN      );
REG64_FLD( EQ_HANG_PULSE_4_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_4_REG_4                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_4          );
REG64_FLD( EX_HANG_PULSE_4_REG_4_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_4_LEN      );
REG64_FLD( EX_HANG_PULSE_4_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_4_REG_4                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_4          );
REG64_FLD( C_HANG_PULSE_4_REG_4_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_4_LEN      );
REG64_FLD( C_HANG_PULSE_4_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_5_REG_5                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_5          );
REG64_FLD( EQ_HANG_PULSE_5_REG_5_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_5_LEN      );
REG64_FLD( EQ_HANG_PULSE_5_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_5_REG_5                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_5          );
REG64_FLD( EX_HANG_PULSE_5_REG_5_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_5_LEN      );
REG64_FLD( EX_HANG_PULSE_5_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_5_REG_5                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_5          );
REG64_FLD( C_HANG_PULSE_5_REG_5_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_5_LEN      );
REG64_FLD( C_HANG_PULSE_5_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HANG_PULSE_6_REG_6                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_6          );
REG64_FLD( EQ_HANG_PULSE_6_REG_6_LEN                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_6_LEN      );
REG64_FLD( EQ_HANG_PULSE_6_REG_SUPPRESS                            , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EX_HANG_PULSE_6_REG_6                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_6          );
REG64_FLD( EX_HANG_PULSE_6_REG_6_LEN                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_6_LEN      );
REG64_FLD( EX_HANG_PULSE_6_REG_SUPPRESS                            , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( C_HANG_PULSE_6_REG_6                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_6          );
REG64_FLD( C_HANG_PULSE_6_REG_6_LEN                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_6_LEN      );
REG64_FLD( C_HANG_PULSE_6_REG_SUPPRESS                             , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS   );

REG64_FLD( EQ_HEARTBEAT_REG_DEAD                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEAD       );

REG64_FLD( EX_HEARTBEAT_REG_DEAD                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEAD       );

REG64_FLD( C_HEARTBEAT_REG_DEAD                                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEAD       );

REG64_FLD( EX_L2_HID_ONE_PPC                                       , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_ONE_PPC    );
REG64_FLD( EX_L2_HID_EN_INSTRUC_TRACE                              , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_EN_INSTRUC_TRACE );
REG64_FLD( EX_L2_HID_FLUSH_IC                                      , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_IC   );
REG64_FLD( EX_L2_HID_EN_ATTN                                       , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_EN_ATTN    );
REG64_FLD( EX_L2_HID_HILE                                          , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_HILE       );
REG64_FLD( EX_L2_HID_DIS_RECOVERY                                  , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DIS_RECOVERY );

REG64_FLD( C_HID_ONE_PPC                                           , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ONE_PPC    );
REG64_FLD( C_HID_EN_INSTRUC_TRACE                                  , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_EN_INSTRUC_TRACE );
REG64_FLD( C_HID_FLUSH_IC                                          , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FLUSH_IC   );
REG64_FLD( C_HID_EN_ATTN                                           , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_EN_ATTN    );
REG64_FLD( C_HID_HILE                                              , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_HILE       );
REG64_FLD( C_HID_DIS_RECOVERY                                      , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DIS_RECOVERY );

REG64_FLD( EQ_HTM_CTRL_HTMSC_TRIG                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG );
REG64_FLD( EQ_HTM_CTRL_HTMSC_TRIG_LEN                              , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG_LEN );
REG64_FLD( EQ_HTM_CTRL_HTMSC_MTSPR_TRIG                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_TRIG );
REG64_FLD( EQ_HTM_CTRL_HTMSC_MTSPR_MARK                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_MARK );
REG64_FLD( EQ_HTM_CTRL_HTMSC_MARK                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK );
REG64_FLD( EQ_HTM_CTRL_HTMSC_MARK_LEN                              , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_LEN );
REG64_FLD( EQ_HTM_CTRL_HTMSC_DBG0_STOP                             , 6   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG0_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_DBG1_STOP                             , 7   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG1_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_RUN_STOP                              , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RUN_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_CHIP0_STOP                            , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP0_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_CHIP1_STOP                            , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP1_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_SPARE1112                             , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112 );
REG64_FLD( EQ_HTM_CTRL_HTMSC_SPARE1112_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112_LEN );
REG64_FLD( EQ_HTM_CTRL_HTMSC_XSTOP_STOP                            , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_XSTOP_STOP );
REG64_FLD( EQ_HTM_CTRL_HTMSC_SPARE1415                             , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415 );
REG64_FLD( EQ_HTM_CTRL_HTMSC_SPARE1415_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_TRIG                         , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_TRIG_LEN                     , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_MTSPR_TRIG                   , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_TRIG );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_MTSPR_MARK                   , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_MARK );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_MARK                         , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_MARK_LEN                     , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_DBG0_STOP                    , 6   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG0_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_DBG1_STOP                    , 7   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG1_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_RUN_STOP                     , 8   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RUN_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_CHIP0_STOP                   , 9   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP0_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_CHIP1_STOP                   , 10  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP1_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_SPARE1112                    , 11  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112 );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_SPARE1112_LEN                , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_XSTOP_STOP                   , 13  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_XSTOP_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_SPARE1415                    , 14  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415 );
REG64_FLD( EX_CHTMLBS0_HTM_CTRL_HTMSC_SPARE1415_LEN                , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_TRIG                         , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_TRIG_LEN                     , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_TRIG_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_MTSPR_TRIG                   , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_TRIG );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_MTSPR_MARK                   , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MTSPR_MARK );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_MARK                         , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_MARK_LEN                     , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_DBG0_STOP                    , 6   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG0_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_DBG1_STOP                    , 7   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DBG1_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_RUN_STOP                     , 8   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RUN_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_CHIP0_STOP                   , 9   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP0_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_CHIP1_STOP                   , 10  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CHIP1_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_SPARE1112                    , 11  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112 );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_SPARE1112_LEN                , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1112_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_XSTOP_STOP                   , 13  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_XSTOP_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_SPARE1415                    , 14  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415 );
REG64_FLD( EX_CHTMLBS1_HTM_CTRL_HTMSC_SPARE1415_LEN                , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE1415_LEN );

REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_ENABLE_SPLIT_CORE                , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE_SPLIT_CORE );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_SPARE2TO4                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4 );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_SPARE2TO4_LEN                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4_LEN );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_SCOPE                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_SCOPE_LEN                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC                                  , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC      );
REG64_FLD( EQ_HTM_IMA_PDBAR_HTMSC_LEN                              , 43  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_LEN  );

REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_ENABLE_SPLIT_CORE       , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE_SPLIT_CORE );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_SPARE2TO4               , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4 );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_SPARE2TO4_LEN           , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_SCOPE                   , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_SCOPE_LEN               , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC                         , 8   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC      );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_PDBAR_HTMSC_LEN                     , 43  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_LEN  );

REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_ENABLE_SPLIT_CORE       , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE_SPLIT_CORE );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_SPARE2TO4               , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4 );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_SPARE2TO4_LEN           , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE2TO4_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_SCOPE                   , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_SCOPE_LEN               , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC                         , 8   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC      );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_PDBAR_HTMSC_LEN                     , 43  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_LEN  );

REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_ERROR                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_ERROR );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_TRACE_ACTIVE                    , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_TRACE_ACTIVE );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_PDBAR_ERROR                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_PDBAR_ERROR );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_RESERVED                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_RESERVED_LEN                    , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED_LEN );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_FSM                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM  );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_FSM_LEN                         , 7   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM_LEN );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_COUNT                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT );
REG64_FLD( EQ_HTM_IMA_STATUS_HTMSC_COUNT_LEN                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_ERROR                  , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_ERROR );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_TRACE_ACTIVE           , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_TRACE_ACTIVE );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_PDBAR_ERROR            , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_PDBAR_ERROR );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_RESERVED               , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_RESERVED_LEN           , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_FSM                    , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM  );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_FSM_LEN                , 7   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_COUNT                  , 12  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT );
REG64_FLD( EX_CHTMLBS0_HTM_IMA_STATUS_HTMSC_COUNT_LEN              , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_ERROR                  , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_ERROR );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_TRACE_ACTIVE           , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_TRACE_ACTIVE );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_PDBAR_ERROR            , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_PDBAR_ERROR );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_RESERVED               , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_RESERVED_LEN           , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_RESERVED_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_FSM                    , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM  );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_FSM_LEN                , 7   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_FSM_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_COUNT                  , 12  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT );
REG64_FLD( EX_CHTMLBS1_HTM_IMA_STATUS_HTMSC_COUNT_LEN              , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMSC_COUNT_LEN );

REG64_FLD( EQ_HTM_LAST_ADDRESS                                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS    );
REG64_FLD( EQ_HTM_LAST_ADDRESS_LEN                                 , 49  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_LAST_ADDRESS                            , 8   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS    );
REG64_FLD( EX_CHTMLBS0_HTM_LAST_ADDRESS_LEN                        , 49  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_LAST_ADDRESS                            , 8   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS    );
REG64_FLD( EX_CHTMLBS1_HTM_LAST_ADDRESS_LEN                        , 49  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_ADDRESS_LEN );

REG64_FLD( EQ_HTM_MEM_HTMSC_ALLOC                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ALLOC );
REG64_FLD( EQ_HTM_MEM_HTMSC_SCOPE                                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EQ_HTM_MEM_HTMSC_SCOPE_LEN                              , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EQ_HTM_MEM_HTMSC_PRIORITY                               , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PRIORITY );
REG64_FLD( EQ_HTM_MEM_HTMSC_SIZE_SMALL                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_SMALL );
REG64_FLD( EQ_HTM_MEM_HTMSC_SPARE                                  , 6   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE );
REG64_FLD( EQ_HTM_MEM_HTMSC_SPARE_LEN                              , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_LEN );
REG64_FLD( EQ_HTM_MEM_HTMSC_BASE                                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE );
REG64_FLD( EQ_HTM_MEM_HTMSC_BASE_LEN                               , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE_LEN );
REG64_FLD( EQ_HTM_MEM_HTMSC_SIZE                                   , 40  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE );
REG64_FLD( EQ_HTM_MEM_HTMSC_SIZE_LEN                               , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_ALLOC                         , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ALLOC );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SCOPE                         , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SCOPE_LEN                     , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_PRIORITY                      , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PRIORITY );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SIZE_SMALL                    , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_SMALL );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SPARE                         , 6   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SPARE_LEN                     , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_BASE                          , 8   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_BASE_LEN                      , 32  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SIZE                          , 40  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE );
REG64_FLD( EX_CHTMLBS0_HTM_MEM_HTMSC_SIZE_LEN                      , 9   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_ALLOC                         , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ALLOC );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SCOPE                         , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SCOPE_LEN                     , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SCOPE_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_PRIORITY                      , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PRIORITY );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SIZE_SMALL                    , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_SMALL );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SPARE                         , 6   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SPARE_LEN                     , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_BASE                          , 8   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_BASE_LEN                      , 32  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_BASE_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SIZE                          , 40  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE );
REG64_FLD( EX_CHTMLBS1_HTM_MEM_HTMSC_SIZE_LEN                      , 9   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SIZE_LEN );

REG64_FLD( EQ_HTM_MODE_HTMSC_ENABLE                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE );
REG64_FLD( EQ_HTM_MODE_HTMSC_CONTENT_SEL                           , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL );
REG64_FLD( EQ_HTM_MODE_HTMSC_CONTENT_SEL_LEN                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL_LEN );
REG64_FLD( EQ_HTM_MODE_HTMSC_SPARE0                                , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE0 );
REG64_FLD( EQ_HTM_MODE_HTMSC_CAPTURE                               , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE );
REG64_FLD( EQ_HTM_MODE_HTMSC_CAPTURE_LEN                           , 6   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE_LEN );
REG64_FLD( EQ_HTM_MODE_HTMSC_DD1EQUIV                              , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DD1EQUIV );
REG64_FLD( EQ_HTM_MODE_HTMSC_SPARE_1TO2                            , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2 );
REG64_FLD( EQ_HTM_MODE_HTMSC_SPARE_1TO2_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2_LEN );
REG64_FLD( EQ_HTM_MODE_HTMSC_WRAP                                  , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_WRAP );
REG64_FLD( EQ_HTM_MODE_HTMSC_DIS_TSTAMP                            , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_TSTAMP );
REG64_FLD( EQ_HTM_MODE_HTMSC_SINGLE_TSTAMP                         , 15  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SINGLE_TSTAMP );
REG64_FLD( EQ_HTM_MODE_HTMSC_DIS_STALL                             , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_STALL );
REG64_FLD( EQ_HTM_MODE_HTMSC_MARKERS_ONLY                          , 17  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARKERS_ONLY );
REG64_FLD( EQ_HTM_MODE_HTMSC_DIS_GROUP                             , 18  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_GROUP );
REG64_FLD( EQ_HTM_MODE_HTMSC_SPARES                                , 19  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES );
REG64_FLD( EQ_HTM_MODE_HTMSC_SPARES_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES_LEN );
REG64_FLD( EQ_HTM_MODE_HTMSC_VGTARGET                              , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET );
REG64_FLD( EQ_HTM_MODE_HTMSC_VGTARGET_LEN                          , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_ENABLE                       , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_CONTENT_SEL                  , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_CONTENT_SEL_LEN              , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SPARE0                       , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE0 );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_CAPTURE                      , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_CAPTURE_LEN                  , 6   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_DD1EQUIV                     , 10  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DD1EQUIV );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SPARE_1TO2                   , 11  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2 );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SPARE_1TO2_LEN               , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_WRAP                         , 13  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_WRAP );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_DIS_TSTAMP                   , 14  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_TSTAMP );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SINGLE_TSTAMP                , 15  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SINGLE_TSTAMP );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_DIS_STALL                    , 16  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_STALL );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_MARKERS_ONLY                 , 17  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARKERS_ONLY );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_DIS_GROUP                    , 18  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_GROUP );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SPARES                       , 19  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_SPARES_LEN                   , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES_LEN );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_VGTARGET                     , 24  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET );
REG64_FLD( EX_CHTMLBS0_HTM_MODE_HTMSC_VGTARGET_LEN                 , 16  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_ENABLE                       , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_ENABLE );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_CONTENT_SEL                  , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_CONTENT_SEL_LEN              , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CONTENT_SEL_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SPARE0                       , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE0 );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_CAPTURE                      , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_CAPTURE_LEN                  , 6   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_CAPTURE_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_DD1EQUIV                     , 10  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DD1EQUIV );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SPARE_1TO2                   , 11  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2 );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SPARE_1TO2_LEN               , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARE_1TO2_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_WRAP                         , 13  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_WRAP );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_DIS_TSTAMP                   , 14  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_TSTAMP );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SINGLE_TSTAMP                , 15  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SINGLE_TSTAMP );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_DIS_STALL                    , 16  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_STALL );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_MARKERS_ONLY                 , 17  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARKERS_ONLY );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_DIS_GROUP                    , 18  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_DIS_GROUP );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SPARES                       , 19  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_SPARES_LEN                   , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_SPARES_LEN );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_VGTARGET                     , 24  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET );
REG64_FLD( EX_CHTMLBS1_HTM_MODE_HTMSC_VGTARGET_LEN                 , 16  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_VGTARGET_LEN );

REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_IN_PROG );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_PURGE_DONE                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_DONE );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_CRESP_OV                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_CRESP_OV );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_REPAIR                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_REPAIR );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_BUF_WAIT                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_BUF_WAIT );
REG64_FLD( EQ_HTM_STAT_STATUS_TRIG_DROPPED_Q                       , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_TRIG_DROPPED_Q );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_ADDR_ERROR                     , 6   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ADDR_ERROR );
REG64_FLD( EQ_HTM_STAT_STATUS_REC_DROPPED_Q                        , 7   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_REC_DROPPED_Q );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_INIT                           , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_INIT );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_PREREQ                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PREREQ );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_READY                          , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_READY );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_TRACING                        , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_TRACING );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_PAUSED                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PAUSED );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_FLUSH                          , 13  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_FLUSH );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_COMPLETE                       , 14  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_COMPLETE );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_ENABLE                         , 15  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ENABLE );
REG64_FLD( EQ_HTM_STAT_HTMCO_STATUS_STAMP                          , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_STAMP );
REG64_FLD( EQ_HTM_STAT_STATUS_SCOM_ERROR                           , 17  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_SCOM_ERROR );
REG64_FLD( EQ_HTM_STAT_STATUS_UNUSED                               , 18  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED );
REG64_FLD( EQ_HTM_STAT_STATUS_UNUSED_LEN                           , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG         , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_IN_PROG );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_PURGE_DONE            , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_DONE );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_CRESP_OV              , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_CRESP_OV );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_REPAIR                , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_REPAIR );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_BUF_WAIT              , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_BUF_WAIT );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_STATUS_TRIG_DROPPED_Q              , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_TRIG_DROPPED_Q );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_ADDR_ERROR            , 6   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ADDR_ERROR );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_STATUS_REC_DROPPED_Q               , 7   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_REC_DROPPED_Q );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_INIT                  , 8   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_INIT );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_PREREQ                , 9   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PREREQ );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_READY                 , 10  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_READY );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_TRACING               , 11  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_TRACING );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_PAUSED                , 12  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PAUSED );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_FLUSH                 , 13  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_FLUSH );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_COMPLETE              , 14  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_COMPLETE );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_ENABLE                , 15  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ENABLE );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_HTMCO_STATUS_STAMP                 , 16  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_STAMP );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_STATUS_SCOM_ERROR                  , 17  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_SCOM_ERROR );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_STATUS_UNUSED                      , 18  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED );
REG64_FLD( EX_CHTMLBS0_HTM_STAT_STATUS_UNUSED_LEN                  , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG         , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_IN_PROG );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_PURGE_DONE            , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PURGE_DONE );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_CRESP_OV              , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_CRESP_OV );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_REPAIR                , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_REPAIR );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_BUF_WAIT              , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_BUF_WAIT );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_STATUS_TRIG_DROPPED_Q              , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_TRIG_DROPPED_Q );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_ADDR_ERROR            , 6   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ADDR_ERROR );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_STATUS_REC_DROPPED_Q               , 7   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_REC_DROPPED_Q );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_INIT                  , 8   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_INIT );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_PREREQ                , 9   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PREREQ );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_READY                 , 10  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_READY );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_TRACING               , 11  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_TRACING );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_PAUSED                , 12  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_PAUSED );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_FLUSH                 , 13  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_FLUSH );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_COMPLETE              , 14  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_COMPLETE );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_ENABLE                , 15  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_ENABLE );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_HTMCO_STATUS_STAMP                 , 16  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_HTMCO_STATUS_STAMP );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_STATUS_SCOM_ERROR                  , 17  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_SCOM_ERROR );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_STATUS_UNUSED                      , 18  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED );
REG64_FLD( EX_CHTMLBS1_HTM_STAT_STATUS_UNUSED_LEN                  , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RO  ,
           SH_FLD_STATUS_UNUSED_LEN );

REG64_FLD( EQ_HTM_TRIG_HTMSC_START                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_START );
REG64_FLD( EQ_HTM_TRIG_HTMSC_STOP                                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP );
REG64_FLD( EQ_HTM_TRIG_HTMSC_PAUSE                                 , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PAUSE );
REG64_FLD( EQ_HTM_TRIG_HTMSC_STOP_ALT                              , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP_ALT );
REG64_FLD( EQ_HTM_TRIG_HTMSC_RESET                                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RESET );
REG64_FLD( EQ_HTM_TRIG_HTMSC_MARK_VALID                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_VALID );
REG64_FLD( EQ_HTM_TRIG_HTMSC_MARK_TYPE                             , 6   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE );
REG64_FLD( EQ_HTM_TRIG_HTMSC_MARK_TYPE_LEN                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE_LEN );

REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_START                        , 0   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_START );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_STOP                         , 1   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_PAUSE                        , 2   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PAUSE );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_STOP_ALT                     , 3   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP_ALT );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_RESET                        , 4   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RESET );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_MARK_VALID                   , 5   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_VALID );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_MARK_TYPE                    , 6   , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE );
REG64_FLD( EX_CHTMLBS0_HTM_TRIG_HTMSC_MARK_TYPE_LEN                , 10  , SH_UNT_EX_CHTMLBS0, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE_LEN );

REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_START                        , 0   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_START );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_STOP                         , 1   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_PAUSE                        , 2   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_PAUSE );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_STOP_ALT                     , 3   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_STOP_ALT );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_RESET                        , 4   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_RESET );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_MARK_VALID                   , 5   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_VALID );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_MARK_TYPE                    , 6   , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE );
REG64_FLD( EX_CHTMLBS1_HTM_TRIG_HTMSC_MARK_TYPE_LEN                , 10  , SH_UNT_EX_CHTMLBS1, SH_ACS_SCOM_RW  ,
           SH_FLD_HTMSC_MARK_TYPE_LEN );

REG64_FLD( EQ_INJECT_REG_THERM_TRIP                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP );
REG64_FLD( EQ_INJECT_REG_THERM_TRIP_LEN                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP_LEN );
REG64_FLD( EQ_INJECT_REG_THERM_MODE                                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE );
REG64_FLD( EQ_INJECT_REG_THERM_MODE_LEN                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE_LEN );

REG64_FLD( EX_INJECT_REG_THERM_TRIP                                , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP );
REG64_FLD( EX_INJECT_REG_THERM_TRIP_LEN                            , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP_LEN );
REG64_FLD( EX_INJECT_REG_THERM_MODE                                , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE );
REG64_FLD( EX_INJECT_REG_THERM_MODE_LEN                            , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE_LEN );

REG64_FLD( C_INJECT_REG_THERM_TRIP                                 , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP );
REG64_FLD( C_INJECT_REG_THERM_TRIP_LEN                             , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THERM_TRIP_LEN );
REG64_FLD( C_INJECT_REG_THERM_MODE                                 , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE );
REG64_FLD( C_INJECT_REG_THERM_MODE_LEN                             , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THERM_MODE_LEN );

REG64_FLD( EQ_INJ_REG_STQ_ERR                                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STQ_ERR    );
REG64_FLD( EQ_INJ_REG_STQ_ERR_LEN                                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STQ_ERR_LEN );

REG64_FLD( EX_INJ_REG_STQ_ERR                                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STQ_ERR    );
REG64_FLD( EX_INJ_REG_STQ_ERR_LEN                                  , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STQ_ERR_LEN );

REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_L3SDRTL0_CHECKSTOP_ERR          , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL0_CHECKSTOP_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_L3SDRTL1_CHECKSTOP_ERR          , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL1_CHECKSTOP_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_L3CORTR_NO_LCO_TGTS_ERR         , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3CORTR_NO_LCO_TGTS_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_RCMD_TTAG_P_ERR                 , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RCMD_TTAG_P_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_RCMD_TTAG_P_ERR_LEN             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RCMD_TTAG_P_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_RCMD_ADDR_P_ERR                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RCMD_ADDR_P_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_RCMD_ADDR_P_ERR_LEN             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RCMD_ADDR_P_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CRESP_TTAG_P_ERR                , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CRESP_TTAG_P_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CRESP_TTAG_P_ERR_LEN            , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CRESP_TTAG_P_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CRESP_ATAG_P_ERR                , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CRESP_ATAG_P_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CRESP_ATAG_P_ERR_LEN            , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CRESP_ATAG_P_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_DATA_RTAG_P_ERR                 , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DATA_RTAG_P_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_CRESP_ERR        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_CRESP_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_CRESP_ERR_LEN    , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SN_UNSOLICITED_CRESP_ERR        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SN_UNSOLICITED_CRESP_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SN_UNSOLICITED_CRESP_ERR_LEN    , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SN_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CO_UNSOLICITED_CRESP_ERR        , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CO_UNSOLICITED_CRESP_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CO_UNSOLICITED_CRESP_ERR_LEN    , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CO_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_WI_UNSOLICITED_DATA_ERR         , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WI_UNSOLICITED_DATA_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_DATA_ERR         , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_DATA_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_TM_CAM_ERR                      , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TM_CAM_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_TM_CAM_ERR_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TM_CAM_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_COFSM_ADDR_ERR                  , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_COFSM_ADDR_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SNFSM_ADDR_ERR                  , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNFSM_ADDR_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_L3SDRTL0_CACHE_INHIBIT_ERR      , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL0_CACHE_INHIBIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_L3SDRTL1_CACHE_INHIBIT_ERR      , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL1_CACHE_INHIBIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SPARE1_ERR                      , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE1_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SPARE1_ERR_LEN                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE1_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SPARE2_ERR                      , 30  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE2_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SPARE2_ERR_LEN                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE2_ERR_LEN );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_SN_MACHINE_HANG_ERR             , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SN_MACHINE_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_RD_MACHINE_HANG_ERR             , 33  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RD_MACHINE_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CI_MACHINE_HANG_ERR             , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CI_MACHINE_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD0_REG_CO_MACHINE_HANG_ERR             , 35  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CO_MACHINE_HANG_ERR );

REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_L3SDRTL0_CHECKSTOP_ERR       , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL0_CHECKSTOP_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_L3SDRTL1_CHECKSTOP_ERR       , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL1_CHECKSTOP_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_L3CORTR_NO_LCO_TGTS_ERR      , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3CORTR_NO_LCO_TGTS_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_RCMD_TTAG_P_ERR              , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_RCMD_TTAG_P_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_RCMD_TTAG_P_ERR_LEN          , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_RCMD_TTAG_P_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_RCMD_ADDR_P_ERR              , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_RCMD_ADDR_P_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_RCMD_ADDR_P_ERR_LEN          , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_RCMD_ADDR_P_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CRESP_TTAG_P_ERR             , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CRESP_TTAG_P_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CRESP_TTAG_P_ERR_LEN         , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CRESP_TTAG_P_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CRESP_ATAG_P_ERR             , 9   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CRESP_ATAG_P_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CRESP_ATAG_P_ERR_LEN         , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CRESP_ATAG_P_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_DATA_RTAG_P_ERR              , 11  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_DATA_RTAG_P_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_CRESP_ERR     , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_CRESP_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_CRESP_ERR_LEN , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SN_UNSOLICITED_CRESP_ERR     , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SN_UNSOLICITED_CRESP_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SN_UNSOLICITED_CRESP_ERR_LEN , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SN_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CO_UNSOLICITED_CRESP_ERR     , 16  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CO_UNSOLICITED_CRESP_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CO_UNSOLICITED_CRESP_ERR_LEN , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CO_UNSOLICITED_CRESP_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_WI_UNSOLICITED_DATA_ERR      , 18  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WI_UNSOLICITED_DATA_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_PF_UNSOLICITED_DATA_ERR      , 19  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PF_UNSOLICITED_DATA_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_TM_CAM_ERR                   , 20  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_TM_CAM_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_TM_CAM_ERR_LEN               , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_TM_CAM_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_COFSM_ADDR_ERR               , 24  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_COFSM_ADDR_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SNFSM_ADDR_ERR               , 25  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SNFSM_ADDR_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_L3SDRTL0_CACHE_INHIBIT_ERR   , 26  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL0_CACHE_INHIBIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_L3SDRTL1_CACHE_INHIBIT_ERR   , 27  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3SDRTL1_CACHE_INHIBIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SPARE1_ERR                   , 28  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SPARE1_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SPARE1_ERR_LEN               , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SPARE1_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SPARE2_ERR                   , 30  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SPARE2_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SPARE2_ERR_LEN               , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SPARE2_ERR_LEN );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_SN_MACHINE_HANG_ERR          , 32  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_SN_MACHINE_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_RD_MACHINE_HANG_ERR          , 33  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_RD_MACHINE_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CI_MACHINE_HANG_ERR          , 34  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CI_MACHINE_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD0_REG_CO_MACHINE_HANG_ERR          , 35  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_CO_MACHINE_HANG_ERR );

REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PF_MACHINE_HANG_ERR             , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PF_MACHINE_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_WI_MACHINE_HANG_ERR             , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WI_MACHINE_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3L2CTL_RD_OVERRUN_CK_ERR       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3L2CTL_RD_OVERRUN_CK_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3L2CTL_PF_OVERRUN_CK_ERR       , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3L2CTL_PF_OVERRUN_CK_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3CICTL_CI_OVERRUN_CK_ERR       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3CICTL_CI_OVERRUN_CK_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3XMEMA0_DW_DIR_HIT_ERR         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA0_DW_DIR_HIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3XMEMA1_DW_DIR_HIT_ERR         , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA1_DW_DIR_HIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3XMEMA0_CRW_DIR_HIT_ERR        , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA0_CRW_DIR_HIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3XMEMA1_CRW_DIR_HIT_ERR        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA1_CRW_DIR_HIT_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR0            , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR0 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR1            , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR1 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR2            , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR2 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR0            , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR0 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR1            , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR1 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR2            , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR2 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_MC_FP_MATE_CMD_ERR0             , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MC_FP_MATE_CMD_ERR0 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_MC_FP_MATE_CMD_ERR1             , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MC_FP_MATE_CMD_ERR1 );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3PBEXCA0_OVERFLOW_ERR          , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA0_OVERFLOW_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3PBEXCA1_OVERFLOW_ERR          , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA1_OVERFLOW_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3PBEXCA0_UNDERFLOW_ERR         , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA0_UNDERFLOW_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_L3PBEXCA1_UNDERFLOW_ERR         , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA1_UNDERFLOW_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_PF_MACHINE_W4DT_HANG_ERR        , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PF_MACHINE_W4DT_HANG_ERR );
REG64_FLD( EQ_L3_CTL_CHECK_RD1_REG_WI_MACHINE_W4DT_HANG_ERR        , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WI_MACHINE_W4DT_HANG_ERR );

REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PF_MACHINE_HANG_ERR          , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PF_MACHINE_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_WI_MACHINE_HANG_ERR          , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WI_MACHINE_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3L2CTL_RD_OVERRUN_CK_ERR    , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3L2CTL_RD_OVERRUN_CK_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3L2CTL_PF_OVERRUN_CK_ERR    , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3L2CTL_PF_OVERRUN_CK_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3CICTL_CI_OVERRUN_CK_ERR    , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3CICTL_CI_OVERRUN_CK_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3XMEMA0_DW_DIR_HIT_ERR      , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA0_DW_DIR_HIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3XMEMA1_DW_DIR_HIT_ERR      , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA1_DW_DIR_HIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3XMEMA0_CRW_DIR_HIT_ERR     , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA0_CRW_DIR_HIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3XMEMA1_CRW_DIR_HIT_ERR     , 8   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3XMEMA1_CRW_DIR_HIT_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR0         , 9   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR0 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR1         , 10  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR1 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA0_CMD_REQ_ERR2         , 11  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA0_CMD_REQ_ERR2 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR0         , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR0 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR1         , 13  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR1 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PBEXCA1_CMD_REQ_ERR2         , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PBEXCA1_CMD_REQ_ERR2 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_MC_FP_MATE_CMD_ERR0          , 15  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_MC_FP_MATE_CMD_ERR0 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_MC_FP_MATE_CMD_ERR1          , 16  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_MC_FP_MATE_CMD_ERR1 );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3PBEXCA0_OVERFLOW_ERR       , 17  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA0_OVERFLOW_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3PBEXCA1_OVERFLOW_ERR       , 18  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA1_OVERFLOW_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3PBEXCA0_UNDERFLOW_ERR      , 19  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA0_UNDERFLOW_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_L3PBEXCA1_UNDERFLOW_ERR      , 20  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3PBEXCA1_UNDERFLOW_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_PF_MACHINE_W4DT_HANG_ERR     , 21  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_PF_MACHINE_W4DT_HANG_ERR );
REG64_FLD( EX_L3_L3_CTL_CHECK_RD1_REG_WI_MACHINE_W4DT_HANG_ERR     , 22  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WI_MACHINE_W4DT_HANG_ERR );

REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER0_EPS_VAL            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER0_EPS_VAL );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER0_EPS_VAL_LEN        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER0_EPS_VAL_LEN );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL            , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL_LEN        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL_LEN );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL            , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL_LEN        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL_LEN );
REG64_FLD( EQ_L3_RD_EPSILON_CFG_REG_EPS_MODE_SEL                   , 36  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_MODE_SEL );

REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER0_EPS_VAL            , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER0_EPS_VAL );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER0_EPS_VAL_LEN        , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER0_EPS_VAL_LEN );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL            , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL_LEN        , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL_LEN );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL            , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL_LEN        , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL_LEN );
REG64_FLD( EX_L3_RD_EPSILON_CFG_REG_EPS_MODE_SEL                   , 36  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_EPS_MODE_SEL );

REG64_FLD( EQ_L3_RTIM_PERIOD_MONITOR_MON                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MON        );
REG64_FLD( EQ_L3_RTIM_PERIOD_MONITOR_MON_LEN                       , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MON_LEN    );

REG64_FLD( EX_L3_L3_RTIM_PERIOD_MONITOR_MON                        , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_MON        );
REG64_FLD( EX_L3_L3_RTIM_PERIOD_MONITOR_MON_LEN                    , 8   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_MON_LEN    );

REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL_LEN        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL_LEN );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL            , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL_LEN        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL_LEN );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EN_WT4CR_EPS_ON_LCO            , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EN_WT4CR_EPS_ON_LCO );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EN_WT4CR_EXTENDED_MODE         , 25  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EN_WT4CR_EXTENDED_MODE );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EPS_STEP_MODE                  , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_STEP_MODE );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EPS_STEP_MODE_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_STEP_MODE_LEN );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EPS_DIVIDER_MODE               , 30  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_DIVIDER_MODE );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EPS_DIVIDER_MODE_LEN           , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_DIVIDER_MODE_LEN );
REG64_FLD( EQ_L3_WR_EPSILON_CFG_REG_EPS_CNT_USE_DIVIDER_EN         , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EPS_CNT_USE_DIVIDER_EN );

REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL         , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_WT4CR_TIER1_EPS_VAL_LEN     , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER1_EPS_VAL_LEN );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL         , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_WT4CR_TIER2_EPS_VAL_LEN     , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_WT4CR_TIER2_EPS_VAL_LEN );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EN_WT4CR_EPS_ON_LCO         , 24  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EN_WT4CR_EPS_ON_LCO );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EN_WT4CR_EXTENDED_MODE      , 25  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EN_WT4CR_EXTENDED_MODE );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EPS_STEP_MODE               , 26  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EPS_STEP_MODE );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EPS_STEP_MODE_LEN           , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EPS_STEP_MODE_LEN );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EPS_DIVIDER_MODE            , 30  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EPS_DIVIDER_MODE );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EPS_DIVIDER_MODE_LEN        , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EPS_DIVIDER_MODE_LEN );
REG64_FLD( EX_L3_L3_WR_EPSILON_CFG_REG_EPS_CNT_USE_DIVIDER_EN      , 34  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_EPS_CNT_USE_DIVIDER_EN );

REG64_FLD( EQ_LINEDEL_TRIG_REG_TRIG                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIG       );
REG64_FLD( EQ_LINEDEL_TRIG_REG_DONE                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DONE       );
REG64_FLD( EQ_LINEDEL_TRIG_REG_SPARE                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE      );
REG64_FLD( EQ_LINEDEL_TRIG_REG_SPARE_LEN                           , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPARE_LEN  );

REG64_FLD( EX_L2_LINEDEL_TRIG_REG_TRIG                             , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TRIG       );
REG64_FLD( EX_L2_LINEDEL_TRIG_REG_DONE                             , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DONE       );
REG64_FLD( EX_L2_LINEDEL_TRIG_REG_SPARE                            , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPARE      );
REG64_FLD( EX_L2_LINEDEL_TRIG_REG_SPARE_LEN                        , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPARE_LEN  );

REG64_FLD( EQ_LINE_DELETED_MEMBERS_REG_L3                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EQ_LINE_DELETED_MEMBERS_REG_L3_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( EX_L3_LINE_DELETED_MEMBERS_REG_L3                       , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3         );
REG64_FLD( EX_L3_LINE_DELETED_MEMBERS_REG_L3_LEN                   , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LEN     );

REG64_FLD( CAPP_LINK_DELAY_TIMER_VALUE                             , 27  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALUE      );
REG64_FLD( CAPP_LINK_DELAY_TIMER_VALUE_LEN                         , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( CAPP_LINK_DELAY_TIMER_VALID                             , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );
REG64_FLD( CAPP_LINK_DELAY_TIMER_RESP_PKT_RCV                      , 33  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RESP_PKT_RCV );
REG64_FLD( CAPP_LINK_DELAY_TIMER_SECURE_ERR                        , 34  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SECURE_ERR );

REG64_FLD( EQ_LOCAL_FIR_ACTION0_IN                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EQ_LOCAL_FIR_ACTION0_IN_LEN                             , 41  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EX_LOCAL_FIR_ACTION0_IN                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EX_LOCAL_FIR_ACTION0_IN_LEN                             , 41  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( C_LOCAL_FIR_ACTION0_IN                                  , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( C_LOCAL_FIR_ACTION0_IN_LEN                              , 41  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EQ_LOCAL_FIR_ACTION1_IN                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EQ_LOCAL_FIR_ACTION1_IN_LEN                             , 41  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EX_LOCAL_FIR_ACTION1_IN                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EX_LOCAL_FIR_ACTION1_IN_LEN                             , 41  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( C_LOCAL_FIR_ACTION1_IN                                  , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( C_LOCAL_FIR_ACTION1_IN_LEN                              , 41  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EQ_LOCAL_FIR_MASK_LFIR_IN                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN    );
REG64_FLD( EQ_LOCAL_FIR_MASK_LFIR_IN_LEN                           , 41  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN_LEN );

REG64_FLD( EX_LOCAL_FIR_MASK_LFIR_IN                               , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN    );
REG64_FLD( EX_LOCAL_FIR_MASK_LFIR_IN_LEN                           , 41  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN_LEN );

REG64_FLD( C_LOCAL_FIR_MASK_LFIR_IN                                , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN    );
REG64_FLD( C_LOCAL_FIR_MASK_LFIR_IN_LEN                            , 41  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_LFIR_IN_LEN );

REG64_FLD( EQ_LRU_VIC_ALLOC_REG_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG );
REG64_FLD( EQ_LRU_VIC_ALLOC_REG_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG_LEN , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG_LEN );
REG64_FLD( EQ_LRU_VIC_ALLOC_REG_L3_COLUMN_MD_CFG                   , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_MD_CFG );
REG64_FLD( EQ_LRU_VIC_ALLOC_REG_L3_COLUMN_MD_CFG_LEN               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_MD_CFG_LEN );

REG64_FLD( EX_L3_LRU_VIC_ALLOC_REG_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG );
REG64_FLD( EX_L3_LRU_VIC_ALLOC_REG_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG_LEN , 20  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_SEGR_LCO_COLUMN_L2_CFG_LEN );
REG64_FLD( EX_L3_LRU_VIC_ALLOC_REG_L3_COLUMN_MD_CFG                , 20  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_MD_CFG );
REG64_FLD( EX_L3_LRU_VIC_ALLOC_REG_L3_COLUMN_MD_CFG_LEN            , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_COLUMN_MD_CFG_LEN );

REG64_FLD( EQ_MIB_XIICAC_ICACHE_TAG_ADDR                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR );
REG64_FLD( EQ_MIB_XIICAC_ICACHE_TAG_ADDR_LEN                       , 27  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR_LEN );
REG64_FLD( EQ_MIB_XIICAC_ICACHE_ERR                                , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_ERR );
REG64_FLD( EQ_MIB_XIICAC_XISIB_PIB_IFETCH_PENDING                  , 34  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_XISIB_PIB_IFETCH_PENDING );
REG64_FLD( EQ_MIB_XIICAC_XIMEM_MEM_IFETCH_PENDING                  , 35  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IFETCH_PENDING );
REG64_FLD( EQ_MIB_XIICAC_ICACHE_VALID                              , 36  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID );
REG64_FLD( EQ_MIB_XIICAC_ICACHE_VALID_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID_LEN );

REG64_FLD( EX_MIB_XIICAC_ICACHE_TAG_ADDR                           , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR );
REG64_FLD( EX_MIB_XIICAC_ICACHE_TAG_ADDR_LEN                       , 27  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_TAG_ADDR_LEN );
REG64_FLD( EX_MIB_XIICAC_ICACHE_ERR                                , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_ERR );
REG64_FLD( EX_MIB_XIICAC_XISIB_PIB_IFETCH_PENDING                  , 34  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_XISIB_PIB_IFETCH_PENDING );
REG64_FLD( EX_MIB_XIICAC_XIMEM_MEM_IFETCH_PENDING                  , 35  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IFETCH_PENDING );
REG64_FLD( EX_MIB_XIICAC_ICACHE_VALID                              , 36  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID );
REG64_FLD( EX_MIB_XIICAC_ICACHE_VALID_LEN                          , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_ICACHE_VALID_LEN );

REG64_FLD( EQ_MIB_XIMEM_MEM_ADDR                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR   );
REG64_FLD( EQ_MIB_XIMEM_MEM_ADDR_LEN                               , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR_LEN );
REG64_FLD( EQ_MIB_XIMEM_MEM_R_NW                                   , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_R_NW   );
REG64_FLD( EQ_MIB_XIMEM_MEM_BUSY                                   , 33  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BUSY   );
REG64_FLD( EQ_MIB_XIMEM_MEM_IMPRECISE_ERROR_PENDING                , 34  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( EQ_MIB_XIMEM_MEM_BYTE_ENABLE                            , 35  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE );
REG64_FLD( EQ_MIB_XIMEM_MEM_BYTE_ENABLE_LEN                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE_LEN );
REG64_FLD( EQ_MIB_XIMEM_MEM_LINE_MODE                              , 43  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_LINE_MODE );
REG64_FLD( EQ_MIB_XIMEM_MEM_ERROR                                  , 49  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR  );
REG64_FLD( EQ_MIB_XIMEM_MEM_ERROR_LEN                              , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR_LEN );
REG64_FLD( EQ_MIB_XIMEM_MEM_IFETCH_PENDING                         , 62  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IFETCH_PENDING );
REG64_FLD( EQ_MIB_XIMEM_MEM_DATAOP_PENDING                         , 63  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_DATAOP_PENDING );

REG64_FLD( EX_MIB_XIMEM_MEM_ADDR                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR   );
REG64_FLD( EX_MIB_XIMEM_MEM_ADDR_LEN                               , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ADDR_LEN );
REG64_FLD( EX_MIB_XIMEM_MEM_R_NW                                   , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_R_NW   );
REG64_FLD( EX_MIB_XIMEM_MEM_BUSY                                   , 33  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BUSY   );
REG64_FLD( EX_MIB_XIMEM_MEM_IMPRECISE_ERROR_PENDING                , 34  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( EX_MIB_XIMEM_MEM_BYTE_ENABLE                            , 35  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE );
REG64_FLD( EX_MIB_XIMEM_MEM_BYTE_ENABLE_LEN                        , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_BYTE_ENABLE_LEN );
REG64_FLD( EX_MIB_XIMEM_MEM_LINE_MODE                              , 43  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_LINE_MODE );
REG64_FLD( EX_MIB_XIMEM_MEM_ERROR                                  , 49  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR  );
REG64_FLD( EX_MIB_XIMEM_MEM_ERROR_LEN                              , 3   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_ERROR_LEN );
REG64_FLD( EX_MIB_XIMEM_MEM_IFETCH_PENDING                         , 62  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_IFETCH_PENDING );
REG64_FLD( EX_MIB_XIMEM_MEM_DATAOP_PENDING                         , 63  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_MEM_DATAOP_PENDING );

REG64_FLD( EQ_MIB_XISGB_STORE_ADDRESS                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS );
REG64_FLD( EQ_MIB_XISGB_STORE_ADDRESS_LEN                          , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS_LEN );
REG64_FLD( EQ_MIB_XISGB_XIMEM_MEM_IMPRECISE_ERROR_PENDING          , 35  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( EQ_MIB_XISGB_SGB_BYTE_VALID                             , 36  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID );
REG64_FLD( EQ_MIB_XISGB_SGB_BYTE_VALID_LEN                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID_LEN );
REG64_FLD( EQ_MIB_XISGB_SGB_FLUSH_PENDING                          , 63  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_FLUSH_PENDING );

REG64_FLD( EX_MIB_XISGB_STORE_ADDRESS                              , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS );
REG64_FLD( EX_MIB_XISGB_STORE_ADDRESS_LEN                          , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_STORE_ADDRESS_LEN );
REG64_FLD( EX_MIB_XISGB_XIMEM_MEM_IMPRECISE_ERROR_PENDING          , 35  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_XIMEM_MEM_IMPRECISE_ERROR_PENDING );
REG64_FLD( EX_MIB_XISGB_SGB_BYTE_VALID                             , 36  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID );
REG64_FLD( EX_MIB_XISGB_SGB_BYTE_VALID_LEN                         , 4   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_BYTE_VALID_LEN );
REG64_FLD( EX_MIB_XISGB_SGB_FLUSH_PENDING                          , 63  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_SGB_FLUSH_PENDING );

REG64_FLD( EQ_MIB_XISIB_PIB_ADDR                                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR   );
REG64_FLD( EQ_MIB_XISIB_PIB_ADDR_LEN                               , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR_LEN );
REG64_FLD( EQ_MIB_XISIB_PIB_R_NW                                   , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_R_NW   );
REG64_FLD( EQ_MIB_XISIB_PIB_BUSY                                   , 33  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_BUSY   );
REG64_FLD( EQ_MIB_XISIB_PIB_IMPRECISE_ERROR_PENDING                , 34  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IMPRECISE_ERROR_PENDING );
REG64_FLD( EQ_MIB_XISIB_PIB_RSP_INFO                               , 49  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO );
REG64_FLD( EQ_MIB_XISIB_PIB_RSP_INFO_LEN                           , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO_LEN );
REG64_FLD( EQ_MIB_XISIB_PIB_IFETCH_PENDING                         , 62  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IFETCH_PENDING );
REG64_FLD( EQ_MIB_XISIB_PIB_DATAOP_PENDING                         , 63  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_DATAOP_PENDING );

REG64_FLD( EX_MIB_XISIB_PIB_ADDR                                   , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR   );
REG64_FLD( EX_MIB_XISIB_PIB_ADDR_LEN                               , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_ADDR_LEN );
REG64_FLD( EX_MIB_XISIB_PIB_R_NW                                   , 32  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_R_NW   );
REG64_FLD( EX_MIB_XISIB_PIB_BUSY                                   , 33  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_BUSY   );
REG64_FLD( EX_MIB_XISIB_PIB_IMPRECISE_ERROR_PENDING                , 34  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IMPRECISE_ERROR_PENDING );
REG64_FLD( EX_MIB_XISIB_PIB_RSP_INFO                               , 49  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO );
REG64_FLD( EX_MIB_XISIB_PIB_RSP_INFO_LEN                           , 3   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_RSP_INFO_LEN );
REG64_FLD( EX_MIB_XISIB_PIB_IFETCH_PENDING                         , 62  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_IFETCH_PENDING );
REG64_FLD( EX_MIB_XISIB_PIB_DATAOP_PENDING                         , 63  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_PIB_DATAOP_PENDING );

REG64_FLD( EQ_MODE_REG_IN0                                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( EQ_MODE_REG_IN1                                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( EQ_MODE_REG_IN2                                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( EQ_MODE_REG_IN3                                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( EQ_MODE_REG_IN4                                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( EQ_MODE_REG_IN5                                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( EQ_MODE_REG_IN6                                         , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( EQ_MODE_REG_IN7                                         , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( EQ_MODE_REG_IN8                                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( EQ_MODE_REG_IN9                                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( EQ_MODE_REG_IN10                                        , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( EQ_MODE_REG_IN11                                        , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( EQ_MODE_REG_IN                                          , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EQ_MODE_REG_IN_LEN                                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EX_MODE_REG_IN0                                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( EX_MODE_REG_IN1                                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( EX_MODE_REG_IN2                                         , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( EX_MODE_REG_IN3                                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( EX_MODE_REG_IN4                                         , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( EX_MODE_REG_IN5                                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( EX_MODE_REG_IN6                                         , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( EX_MODE_REG_IN7                                         , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( EX_MODE_REG_IN8                                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( EX_MODE_REG_IN9                                         , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( EX_MODE_REG_IN10                                        , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( EX_MODE_REG_IN11                                        , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( EX_MODE_REG_IN                                          , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( EX_MODE_REG_IN_LEN                                      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( C_MODE_REG_IN0                                          , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN0        );
REG64_FLD( C_MODE_REG_IN1                                          , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN1        );
REG64_FLD( C_MODE_REG_IN2                                          , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN2        );
REG64_FLD( C_MODE_REG_IN3                                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN3        );
REG64_FLD( C_MODE_REG_IN4                                          , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN4        );
REG64_FLD( C_MODE_REG_IN5                                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN5        );
REG64_FLD( C_MODE_REG_IN6                                          , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN6        );
REG64_FLD( C_MODE_REG_IN7                                          , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN7        );
REG64_FLD( C_MODE_REG_IN8                                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN8        );
REG64_FLD( C_MODE_REG_IN9                                          , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN9        );
REG64_FLD( C_MODE_REG_IN10                                         , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN10       );
REG64_FLD( C_MODE_REG_IN11                                         , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN11       );
REG64_FLD( C_MODE_REG_IN                                           , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN         );
REG64_FLD( C_MODE_REG_IN_LEN                                       , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN_LEN     );

REG64_FLD( EQ_MODE_REG0_L3_DISABLED_CFG                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DISABLED_CFG );
REG64_FLD( EQ_MODE_REG0_L3_DMAP_CI_EN_CFG                          , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DMAP_CI_EN_CFG );
REG64_FLD( EQ_MODE_REG0_L3_RDSN_LINEDEL_UE_EN                      , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_RDSN_LINEDEL_UE_EN );
REG64_FLD( EQ_MODE_REG0_L3_NO_ALLOCATE_EN                          , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_NO_ALLOCATE_EN );
REG64_FLD( EQ_MODE_REG0_L3_NO_ALLOCATE_ACTIVE                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_NO_ALLOCATE_ACTIVE );
REG64_FLD( EQ_MODE_REG0_L3_SPARE5                                  , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE5  );
REG64_FLD( EQ_MODE_REG0_L3_IS_ECO_CFG                              , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_IS_ECO_CFG );
REG64_FLD( EQ_MODE_REG0_L3_SPARE7                                  , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE7  );
REG64_FLD( EQ_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_RTY_LIMIT_DISABLE );
REG64_FLD( EQ_MODE_REG0_L3_DYN_LCO_BLK_DIS_CFG                     , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DYN_LCO_BLK_DIS_CFG );
REG64_FLD( EQ_MODE_REG0_L3_LCO_ADDR_TGT_ENABLE                     , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_ADDR_TGT_ENABLE );
REG64_FLD( EQ_MODE_REG0_L3_ADDR_HASH_EN_CFG                        , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_ADDR_HASH_EN_CFG );
REG64_FLD( EQ_MODE_REG0_L3CERRS_CFG_DCACHE_CAPP                    , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3CERRS_CFG_DCACHE_CAPP );
REG64_FLD( EQ_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS               , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3CERRS_LCO_RETRY_THROTL_DIS );
REG64_FLD( EQ_MODE_REG0_L3_HANG_POLL_PULSE_DIV                     , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_HANG_POLL_PULSE_DIV );
REG64_FLD( EQ_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_MODE_REG0_L3_DATA_POLL_PULSE_DIV                     , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DATA_POLL_PULSE_DIV );
REG64_FLD( EQ_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_MODE_REG0_L3_SYSMAP_SM_NOT_LG_SEL                    , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SYSMAP_SM_NOT_LG_SEL );

REG64_FLD( EX_L2_MODE_REG0_CFG_LRU_DIRECT_MAP                      , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_LRU_DIRECT_MAP );
REG64_FLD( EX_L2_MODE_REG0_CFG_RANDOM_EN                           , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_RANDOM_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_SINGLE_MEM_EN                       , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_SINGLE_MEM_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_SINGLE_MEM                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_SINGLE_MEM );
REG64_FLD( EX_L2_MODE_REG0_CFG_SINGLE_MEM_LEN                      , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_SINGLE_MEM_LEN );
REG64_FLD( EX_L2_MODE_REG0_CFG_L3_DIS                              , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_L3_DIS );
REG64_FLD( EX_L2_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN              , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_CO_SOFT_PURGE_ME_SX_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN          , 13  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_CO_SOFT_PURGE_ALL_LINES_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_DCBZ_TRASHMODE_EN                   , 14  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_DCBZ_TRASHMODE_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_CAC_ERR_REPAIR_EN                   , 15  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_CAC_ERR_REPAIR_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN                , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_LINEDEL_ON_CAC_UE_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN        , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_C0_L2_PB_ARB_RATE_SEL               , 18  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_C0_L2_PB_ARB_RATE_SEL );
REG64_FLD( EX_L2_MODE_REG0_CFG_C0_L2_PB_ARB_RATE_SEL_LEN           , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_C0_L2_PB_ARB_RATE_SEL_LEN );
REG64_FLD( EX_L2_MODE_REG0_CFG_HASH_L3_ADDR_EN                     , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_HASH_L3_ADDR_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN , 22  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_SYSMAP_SM_NOT_LG_SEL                , 23  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_SYSMAP_SM_NOT_LG_SEL );
REG64_FLD( EX_L2_MODE_REG0_CFG_Q_BIT_TID_MASK                      , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_Q_BIT_TID_MASK );
REG64_FLD( EX_L2_MODE_REG0_CFG_Q_BIT_TID_MASK_LEN                  , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_Q_BIT_TID_MASK_LEN );
REG64_FLD( EX_L2_MODE_REG0_CFG_STQ_PF_EN                           , 32  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_STQ_PF_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_DCACHE_CAPP_LPC_EN                  , 33  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_DCACHE_CAPP_LPC_EN );
REG64_FLD( EX_L2_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL             , 34  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_PERFMON_INFO_SRC_ED_SEL );
REG64_FLD( EX_L2_MODE_REG0_CFG_C1_L2_PB_ARB_RATE_SEL               , 35  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_C1_L2_PB_ARB_RATE_SEL );
REG64_FLD( EX_L2_MODE_REG0_CFG_C1_L2_PB_ARB_RATE_SEL_LEN           , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_C1_L2_PB_ARB_RATE_SEL_LEN );

REG64_FLD( EX_L3_MODE_REG0_L3_DISABLED_CFG                         , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DISABLED_CFG );
REG64_FLD( EX_L3_MODE_REG0_L3_DMAP_CI_EN_CFG                       , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DMAP_CI_EN_CFG );
REG64_FLD( EX_L3_MODE_REG0_L3_RDSN_LINEDEL_UE_EN                   , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_RDSN_LINEDEL_UE_EN );
REG64_FLD( EX_L3_MODE_REG0_L3_NO_ALLOCATE_EN                       , 3   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_NO_ALLOCATE_EN );
REG64_FLD( EX_L3_MODE_REG0_L3_NO_ALLOCATE_ACTIVE                   , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_NO_ALLOCATE_ACTIVE );
REG64_FLD( EX_L3_MODE_REG0_L3_SPARE5                               , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE5  );
REG64_FLD( EX_L3_MODE_REG0_L3_IS_ECO_CFG                           , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_IS_ECO_CFG );
REG64_FLD( EX_L3_MODE_REG0_L3_SPARE7                               , 7   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SPARE7  );
REG64_FLD( EX_L3_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE                , 8   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_RTY_LIMIT_DISABLE );
REG64_FLD( EX_L3_MODE_REG0_L3_DYN_LCO_BLK_DIS_CFG                  , 9   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DYN_LCO_BLK_DIS_CFG );
REG64_FLD( EX_L3_MODE_REG0_L3_LCO_ADDR_TGT_ENABLE                  , 10  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_ADDR_TGT_ENABLE );
REG64_FLD( EX_L3_MODE_REG0_L3_ADDR_HASH_EN_CFG                     , 11  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_ADDR_HASH_EN_CFG );
REG64_FLD( EX_L3_MODE_REG0_L3CERRS_CFG_DCACHE_CAPP                 , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3CERRS_CFG_DCACHE_CAPP );
REG64_FLD( EX_L3_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS            , 13  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3CERRS_LCO_RETRY_THROTL_DIS );
REG64_FLD( EX_L3_MODE_REG0_L3_HANG_POLL_PULSE_DIV                  , 14  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_HANG_POLL_PULSE_DIV );
REG64_FLD( EX_L3_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN              , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_L3_MODE_REG0_L3_DATA_POLL_PULSE_DIV                  , 18  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DATA_POLL_PULSE_DIV );
REG64_FLD( EX_L3_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN              , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_L3_MODE_REG0_L3_SYSMAP_SM_NOT_LG_SEL                 , 22  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SYSMAP_SM_NOT_LG_SEL );

REG64_FLD( EQ_MODE_REG1_L3_LCO_ENABLE_CFG                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_ENABLE_CFG );
REG64_FLD( EQ_MODE_REG1_L3_LCO_TARGET_GROUP                        , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_GROUP );
REG64_FLD( EQ_MODE_REG1_L3_LCO_TARGET_ID                           , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_ID );
REG64_FLD( EQ_MODE_REG1_L3_LCO_TARGET_ID_LEN                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_ID_LEN );
REG64_FLD( EQ_MODE_REG1_L3_LCO_TARGET_VICTIMS                      , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_VICTIMS );
REG64_FLD( EQ_MODE_REG1_L3_LCO_TARGET_VICTIMS_LEN                  , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_VICTIMS_LEN );
REG64_FLD( EQ_MODE_REG1_L3_SCOM_FENCE_LVL                          , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_FENCE_LVL );

REG64_FLD( EX_L2_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS         , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS );
REG64_FLD( EX_L2_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS                , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CFG_ECCCK_UE_SUE_DET_DIS );
REG64_FLD( EX_L2_MODE_REG1_HANG_POLL_PULSE_DIV                     , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV );
REG64_FLD( EX_L2_MODE_REG1_HANG_POLL_PULSE_DIV_LEN                 , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_L2_MODE_REG1_DATA_POLL_PULSE_DIV                     , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DATA_POLL_PULSE_DIV );
REG64_FLD( EX_L2_MODE_REG1_DATA_POLL_PULSE_DIV_LEN                 , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_L2_MODE_REG1_PM03_SMT_ROTATION_DIS                   , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM03_SMT_ROTATION_DIS );
REG64_FLD( EX_L2_MODE_REG1_PM47_SMT_ROTATION_DIS                   , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM47_SMT_ROTATION_DIS );
REG64_FLD( EX_L2_MODE_REG1_PM07_TID_ROTATE_PLSS_RATE               , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM07_TID_ROTATE_PLSS_RATE );
REG64_FLD( EX_L2_MODE_REG1_PM07_TID_ROTATE_PLSS_RATE_LEN           , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM07_TID_ROTATE_PLSS_RATE_LEN );
REG64_FLD( EX_L2_MODE_REG1_PM03_L23_EVENT_TID_SEL_EN               , 25  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM03_L23_EVENT_TID_SEL_EN );
REG64_FLD( EX_L2_MODE_REG1_PM03_L23_EVENT_TID_SEL_NUM              , 26  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM03_L23_EVENT_TID_SEL_NUM );
REG64_FLD( EX_L2_MODE_REG1_PM03_L23_EVENT_TID_SEL_NUM_LEN          , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM03_L23_EVENT_TID_SEL_NUM_LEN );
REG64_FLD( EX_L2_MODE_REG1_PM47_L23_EVENT_TID_SEL_EN               , 29  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM47_L23_EVENT_TID_SEL_EN );
REG64_FLD( EX_L2_MODE_REG1_PM47_L23_EVENT_TID_SEL_NUM              , 30  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM47_L23_EVENT_TID_SEL_NUM );
REG64_FLD( EX_L2_MODE_REG1_PM47_L23_EVENT_TID_SEL_NUM_LEN          , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_PM47_L23_EVENT_TID_SEL_NUM_LEN );

REG64_FLD( EX_L3_MODE_REG1_L3_LCO_ENABLE_CFG                       , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_ENABLE_CFG );
REG64_FLD( EX_L3_MODE_REG1_L3_LCO_TARGET_GROUP                     , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_GROUP );
REG64_FLD( EX_L3_MODE_REG1_L3_LCO_TARGET_ID                        , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_ID );
REG64_FLD( EX_L3_MODE_REG1_L3_LCO_TARGET_ID_LEN                    , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_ID_LEN );
REG64_FLD( EX_L3_MODE_REG1_L3_LCO_TARGET_VICTIMS                   , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_VICTIMS );
REG64_FLD( EX_L3_MODE_REG1_L3_LCO_TARGET_VICTIMS_LEN               , 16  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LCO_TARGET_VICTIMS_LEN );
REG64_FLD( EX_L3_MODE_REG1_L3_SCOM_FENCE_LVL                       , 22  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_SCOM_FENCE_LVL );

REG64_FLD( EQ_MULTICAST_GROUP_1_MULTICAST1                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1 );
REG64_FLD( EQ_MULTICAST_GROUP_1_MULTICAST1_LEN                     , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1_LEN );

REG64_FLD( EX_MULTICAST_GROUP_1_MULTICAST1                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1 );
REG64_FLD( EX_MULTICAST_GROUP_1_MULTICAST1_LEN                     , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1_LEN );

REG64_FLD( C_MULTICAST_GROUP_1_MULTICAST1                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1 );
REG64_FLD( C_MULTICAST_GROUP_1_MULTICAST1_LEN                      , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST1_LEN );

REG64_FLD( EQ_MULTICAST_GROUP_2_MULTICAST2                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2 );
REG64_FLD( EQ_MULTICAST_GROUP_2_MULTICAST2_LEN                     , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2_LEN );

REG64_FLD( EX_MULTICAST_GROUP_2_MULTICAST2                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2 );
REG64_FLD( EX_MULTICAST_GROUP_2_MULTICAST2_LEN                     , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2_LEN );

REG64_FLD( C_MULTICAST_GROUP_2_MULTICAST2                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2 );
REG64_FLD( C_MULTICAST_GROUP_2_MULTICAST2_LEN                      , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST2_LEN );

REG64_FLD( EQ_MULTICAST_GROUP_3_MULTICAST3                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3 );
REG64_FLD( EQ_MULTICAST_GROUP_3_MULTICAST3_LEN                     , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3_LEN );

REG64_FLD( EX_MULTICAST_GROUP_3_MULTICAST3                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3 );
REG64_FLD( EX_MULTICAST_GROUP_3_MULTICAST3_LEN                     , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3_LEN );

REG64_FLD( C_MULTICAST_GROUP_3_MULTICAST3                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3 );
REG64_FLD( C_MULTICAST_GROUP_3_MULTICAST3_LEN                      , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST3_LEN );

REG64_FLD( EQ_MULTICAST_GROUP_4_MULTICAST4                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4 );
REG64_FLD( EQ_MULTICAST_GROUP_4_MULTICAST4_LEN                     , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4_LEN );

REG64_FLD( EX_MULTICAST_GROUP_4_MULTICAST4                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4 );
REG64_FLD( EX_MULTICAST_GROUP_4_MULTICAST4_LEN                     , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4_LEN );

REG64_FLD( C_MULTICAST_GROUP_4_MULTICAST4                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4 );
REG64_FLD( C_MULTICAST_GROUP_4_MULTICAST4_LEN                      , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MULTICAST4_LEN );

REG64_FLD( EQ_NCU_DARN_BAR_REG_ADDR                                , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDR       );
REG64_FLD( EQ_NCU_DARN_BAR_REG_ADDR_LEN                            , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_LEN   );

REG64_FLD( EX_NCU_DARN_BAR_REG_ADDR                                , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDR       );
REG64_FLD( EX_NCU_DARN_BAR_REG_ADDR_LEN                            , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_LEN   );

REG64_FLD( EQ_NCU_MODE_REG_HTM_QUEUE_LIMIT                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HTM_QUEUE_LIMIT );
REG64_FLD( EQ_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HTM_QUEUE_LIMIT_LEN );
REG64_FLD( EQ_NCU_MODE_REG_TRASH_EN                                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRASH_EN   );
REG64_FLD( EQ_NCU_MODE_REG_FENCE_TLBIE                             , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FENCE_TLBIE );
REG64_FLD( EQ_NCU_MODE_REG_DROP_PRIORITY_MASK                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DROP_PRIORITY_MASK );
REG64_FLD( EQ_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DROP_PRIORITY_MASK_LEN );
REG64_FLD( EQ_NCU_MODE_REG_TLBI_GROUP_PUMP_EN                      , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBI_GROUP_PUMP_EN );
REG64_FLD( EQ_NCU_MODE_REG_SLBI_GROUP_PUMP_EN                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SLBI_GROUP_PUMP_EN );
REG64_FLD( EQ_NCU_MODE_REG_SYSMAP_SM_NOT_LG_SEL                    , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SYSMAP_SM_NOT_LG_SEL );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_PACING_CNT_EN                     , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_PACING_CNT_EN );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_DEC_RATE                          , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_DEC_RATE );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_DEC_RATE_LEN                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_DEC_RATE_LEN );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_INC_RATE                          , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_INC_RATE );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_INC_RATE_LEN                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_INC_RATE_LEN );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_CNT_THRESH                        , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_THRESH );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN                    , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_THRESH_LEN );
REG64_FLD( EQ_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN                 , 35  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_WT4TX_CORE_EN );
REG64_FLD( EQ_NCU_MODE_REG_TLB_CHK_WAIT_DEC                        , 36  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_CHK_WAIT_DEC );
REG64_FLD( EQ_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN                    , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_CHK_WAIT_DEC_LEN );

REG64_FLD( EX_NCU_MODE_REG_HTM_QUEUE_LIMIT                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HTM_QUEUE_LIMIT );
REG64_FLD( EX_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN                     , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HTM_QUEUE_LIMIT_LEN );
REG64_FLD( EX_NCU_MODE_REG_TRASH_EN                                , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRASH_EN   );
REG64_FLD( EX_NCU_MODE_REG_FENCE_TLBIE                             , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FENCE_TLBIE );
REG64_FLD( EX_NCU_MODE_REG_DROP_PRIORITY_MASK                      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DROP_PRIORITY_MASK );
REG64_FLD( EX_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN                  , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DROP_PRIORITY_MASK_LEN );
REG64_FLD( EX_NCU_MODE_REG_TLBI_GROUP_PUMP_EN                      , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBI_GROUP_PUMP_EN );
REG64_FLD( EX_NCU_MODE_REG_SLBI_GROUP_PUMP_EN                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SLBI_GROUP_PUMP_EN );
REG64_FLD( EX_NCU_MODE_REG_SYSMAP_SM_NOT_LG_SEL                    , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SYSMAP_SM_NOT_LG_SEL );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_PACING_CNT_EN                     , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_PACING_CNT_EN );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_DEC_RATE                          , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_DEC_RATE );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_DEC_RATE_LEN                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_DEC_RATE_LEN );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_INC_RATE                          , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_INC_RATE );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_INC_RATE_LEN                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_INC_RATE_LEN );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_CNT_THRESH                        , 27  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_THRESH );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN                    , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_THRESH_LEN );
REG64_FLD( EX_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN                 , 35  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_CNT_WT4TX_CORE_EN );
REG64_FLD( EX_NCU_MODE_REG_TLB_CHK_WAIT_DEC                        , 36  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_CHK_WAIT_DEC );
REG64_FLD( EX_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN                    , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_CHK_WAIT_DEC_LEN );

REG64_FLD( EQ_NCU_MODE_REG2_HANG_POLL_PULSE_DIV                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_CP_DATA_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_CP_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_SNOOP_DATA_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN      , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV           , 18  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG1_HANG_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG1_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV           , 22  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG2_HANG_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN       , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG2_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EQ_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV         , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_TLB_DATA_POLL_PULSE_DIV );
REG64_FLD( EQ_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN     , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN );

REG64_FLD( EX_NCU_MODE_REG2_HANG_POLL_PULSE_DIV                    , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_CP_DATA_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_CP_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_SNOOP_DATA_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN      , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV           , 18  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG1_HANG_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN       , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG1_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV           , 22  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG2_HANG_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN       , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLB_STG2_HANG_POLL_PULSE_DIV_LEN );
REG64_FLD( EX_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV         , 26  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_TLB_DATA_POLL_PULSE_DIV );
REG64_FLD( EX_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN     , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN );

REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_EN                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_EN );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD_LEN              , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD_LEN );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT_LEN              , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT_LEN );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT                  , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT );
REG64_FLD( EQ_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT_LEN              , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT_LEN );

REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_EN                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_EN );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD                  , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD_LEN              , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD_LEN );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT_LEN              , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT_LEN );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT                  , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT );
REG64_FLD( EX_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT_LEN              , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT_LEN );

REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY8_VALID                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY8_ID                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY8_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY7_VALID                      , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY7_ID                         , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY7_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY6_VALID                      , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY6_ID                         , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY6_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY5_VALID                      , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY5_ID                         , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG0_DELAY5_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_ID_LEN );

REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY8_VALID                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY8_ID                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY8_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY8_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY7_VALID                      , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY7_ID                         , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY7_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY7_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY6_VALID                      , 26  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY6_ID                         , 27  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY6_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY6_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY5_VALID                      , 39  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY5_ID                         , 40  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG0_DELAY5_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY5_ID_LEN );

REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY4_VALID                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY4_ID                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY4_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY3_VALID                      , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY3_ID                         , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY3_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY2_VALID                      , 26  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY2_ID                         , 27  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY2_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_ID_LEN );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY1_VALID                      , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_VALID );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY1_ID                         , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_ID  );
REG64_FLD( EQ_NCU_SLOW_LPAR_REG1_DELAY1_ID_LEN                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_ID_LEN );

REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY4_VALID                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY4_ID                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY4_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY4_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY3_VALID                      , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY3_ID                         , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY3_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY3_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY2_VALID                      , 26  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY2_ID                         , 27  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY2_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY2_ID_LEN );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY1_VALID                      , 39  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_VALID );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY1_ID                         , 40  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_ID  );
REG64_FLD( EX_NCU_SLOW_LPAR_REG1_DELAY1_ID_LEN                     , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DELAY1_ID_LEN );

REG64_FLD( EQ_NCU_SPEC_BAR_REG_EN                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EN         );
REG64_FLD( EQ_NCU_SPEC_BAR_REG_ADDR                                , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDR       );
REG64_FLD( EQ_NCU_SPEC_BAR_REG_ADDR_LEN                            , 42  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_LEN   );

REG64_FLD( EX_NCU_SPEC_BAR_REG_EN                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_EN         );
REG64_FLD( EX_NCU_SPEC_BAR_REG_ADDR                                , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDR       );
REG64_FLD( EX_NCU_SPEC_BAR_REG_ADDR_LEN                            , 42  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ADDR_LEN   );

REG64_FLD( EQ_NCU_STATUS_REG_CORE0_REQ_ACTIVE                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CORE0_REQ_ACTIVE );
REG64_FLD( EQ_NCU_STATUS_REG_CORE1_REQ_ACTIVE                      , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CORE1_REQ_ACTIVE );
REG64_FLD( EQ_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CORE_OR_SNP_REQ_ACTIVE );
REG64_FLD( EQ_NCU_STATUS_REG_ANY_REQ_ACTIVE                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ANY_REQ_ACTIVE );

REG64_FLD( EX_NCU_STATUS_REG_CORE0_REQ_ACTIVE                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CORE0_REQ_ACTIVE );
REG64_FLD( EX_NCU_STATUS_REG_CORE1_REQ_ACTIVE                      , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CORE1_REQ_ACTIVE );
REG64_FLD( EX_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE                , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CORE_OR_SNP_REQ_ACTIVE );
REG64_FLD( EX_NCU_STATUS_REG_ANY_REQ_ACTIVE                        , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ANY_REQ_ACTIVE );

REG64_FLD( EQ_NET_CTRL0_CHIPLET_ENABLE                             , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CHIPLET_ENABLE );
REG64_FLD( EQ_NET_CTRL0_PCB_EP_RESET                               , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_PCB_EP_RESET );
REG64_FLD( EQ_NET_CTRL0_CLK_ASYNC_RESET                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_ASYNC_RESET );
REG64_FLD( EQ_NET_CTRL0_PLL_TEST_EN                                , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_TEST_EN );
REG64_FLD( EQ_NET_CTRL0_PLL_RESET                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_RESET  );
REG64_FLD( EQ_NET_CTRL0_PLL_BYPASS                                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_BYPASS );
REG64_FLD( EQ_NET_CTRL0_VITAL_SCAN                                 , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN );
REG64_FLD( EQ_NET_CTRL0_VITAL_SCAN_IN                              , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN_IN );
REG64_FLD( EQ_NET_CTRL0_FLUSH_ALIGN_OVR                            , 9   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_ALIGN_OVR );
REG64_FLD( EQ_NET_CTRL0_ARRAY_WRITE_ASSIST_EN                      , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_ARRAY_WRITE_ASSIST_EN );
REG64_FLD( EQ_NET_CTRL0_ACT_DIS                                    , 11  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_ACT_DIS    );
REG64_FLD( EQ_NET_CTRL0_MPW1                                       , 12  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW1       );
REG64_FLD( EQ_NET_CTRL0_MPW2                                       , 13  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW2       );
REG64_FLD( EQ_NET_CTRL0_MPW3                                       , 14  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW3       );
REG64_FLD( EQ_NET_CTRL0_DELAY_LCLKR                                , 15  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_DELAY_LCLKR );
REG64_FLD( EQ_NET_CTRL0_VITAL_THOLD                                , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_THOLD );
REG64_FLD( EQ_NET_CTRL0_FLUSH_SCAN_N                               , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_SCAN_N );
REG64_FLD( EQ_NET_CTRL0_FENCE_EN                                   , 18  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_FENCE_EN   );
REG64_FLD( EQ_NET_CTRL0_RI_N                                       , 19  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_RI_N       );
REG64_FLD( EQ_NET_CTRL0_DI1_N                                      , 20  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_DI1_N      );
REG64_FLD( EQ_NET_CTRL0_DI2_N                                      , 21  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_DI2_N      );
REG64_FLD( EQ_NET_CTRL0_TP_FENCE_PCB                               , 25  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_TP_FENCE_PCB );
REG64_FLD( EQ_NET_CTRL0_LVLTRANS_FENCE                             , 26  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_LVLTRANS_FENCE );
REG64_FLD( EQ_NET_CTRL0_L3_EDRAM_ENABLE                            , 27  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_L3_EDRAM_ENABLE );
REG64_FLD( EQ_NET_CTRL0_HTB_INTEST                                 , 28  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_INTEST );
REG64_FLD( EQ_NET_CTRL0_HTB_EXTEST                                 , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_EXTEST );

REG64_FLD( EX_NET_CTRL0_CHIPLET_ENABLE                             , 0   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CHIPLET_ENABLE );
REG64_FLD( EX_NET_CTRL0_PCB_EP_RESET                               , 1   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_PCB_EP_RESET );
REG64_FLD( EX_NET_CTRL0_CLK_ASYNC_RESET                            , 2   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_ASYNC_RESET );
REG64_FLD( EX_NET_CTRL0_PLL_TEST_EN                                , 3   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_TEST_EN );
REG64_FLD( EX_NET_CTRL0_PLL_RESET                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_RESET  );
REG64_FLD( EX_NET_CTRL0_PLL_BYPASS                                 , 5   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_BYPASS );
REG64_FLD( EX_NET_CTRL0_VITAL_SCAN                                 , 6   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN );
REG64_FLD( EX_NET_CTRL0_VITAL_SCAN_IN                              , 7   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN_IN );
REG64_FLD( EX_NET_CTRL0_FLUSH_ALIGN_OVR                            , 9   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_ALIGN_OVR );
REG64_FLD( EX_NET_CTRL0_ARRAY_WRITE_ASSIST_EN                      , 10  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_ARRAY_WRITE_ASSIST_EN );
REG64_FLD( EX_NET_CTRL0_ACT_DIS                                    , 11  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_ACT_DIS    );
REG64_FLD( EX_NET_CTRL0_MPW1                                       , 12  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW1       );
REG64_FLD( EX_NET_CTRL0_MPW2                                       , 13  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW2       );
REG64_FLD( EX_NET_CTRL0_MPW3                                       , 14  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW3       );
REG64_FLD( EX_NET_CTRL0_DELAY_LCLKR                                , 15  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_DELAY_LCLKR );
REG64_FLD( EX_NET_CTRL0_VITAL_THOLD                                , 16  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_THOLD );
REG64_FLD( EX_NET_CTRL0_FLUSH_SCAN_N                               , 17  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_SCAN_N );
REG64_FLD( EX_NET_CTRL0_FENCE_EN                                   , 18  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_FENCE_EN   );
REG64_FLD( EX_NET_CTRL0_RI_N                                       , 19  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_RI_N       );
REG64_FLD( EX_NET_CTRL0_DI1_N                                      , 20  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_DI1_N      );
REG64_FLD( EX_NET_CTRL0_DI2_N                                      , 21  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_DI2_N      );
REG64_FLD( EX_NET_CTRL0_TP_FENCE_PCB                               , 25  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_TP_FENCE_PCB );
REG64_FLD( EX_NET_CTRL0_LVLTRANS_FENCE                             , 26  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_LVLTRANS_FENCE );
REG64_FLD( EX_NET_CTRL0_L3_EDRAM_ENABLE                            , 27  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_L3_EDRAM_ENABLE );
REG64_FLD( EX_NET_CTRL0_HTB_INTEST                                 , 28  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_INTEST );
REG64_FLD( EX_NET_CTRL0_HTB_EXTEST                                 , 29  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_EXTEST );

REG64_FLD( C_NET_CTRL0_CHIPLET_ENABLE                              , 0   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CHIPLET_ENABLE );
REG64_FLD( C_NET_CTRL0_PCB_EP_RESET                                , 1   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_PCB_EP_RESET );
REG64_FLD( C_NET_CTRL0_CLK_ASYNC_RESET                             , 2   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_ASYNC_RESET );
REG64_FLD( C_NET_CTRL0_PLL_TEST_EN                                 , 3   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_TEST_EN );
REG64_FLD( C_NET_CTRL0_PLL_RESET                                   , 4   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_RESET  );
REG64_FLD( C_NET_CTRL0_PLL_BYPASS                                  , 5   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_BYPASS );
REG64_FLD( C_NET_CTRL0_VITAL_SCAN                                  , 6   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN );
REG64_FLD( C_NET_CTRL0_VITAL_SCAN_IN                               , 7   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_SCAN_IN );
REG64_FLD( C_NET_CTRL0_FLUSH_ALIGN_OVR                             , 9   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_ALIGN_OVR );
REG64_FLD( C_NET_CTRL0_ARRAY_WRITE_ASSIST_EN                       , 10  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_ARRAY_WRITE_ASSIST_EN );
REG64_FLD( C_NET_CTRL0_ACT_DIS                                     , 11  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_ACT_DIS    );
REG64_FLD( C_NET_CTRL0_MPW1                                        , 12  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW1       );
REG64_FLD( C_NET_CTRL0_MPW2                                        , 13  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW2       );
REG64_FLD( C_NET_CTRL0_MPW3                                        , 14  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_MPW3       );
REG64_FLD( C_NET_CTRL0_DELAY_LCLKR                                 , 15  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_DELAY_LCLKR );
REG64_FLD( C_NET_CTRL0_VITAL_THOLD                                 , 16  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_VITAL_THOLD );
REG64_FLD( C_NET_CTRL0_FLUSH_SCAN_N                                , 17  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_FLUSH_SCAN_N );
REG64_FLD( C_NET_CTRL0_FENCE_EN                                    , 18  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_FENCE_EN   );
REG64_FLD( C_NET_CTRL0_RI_N                                        , 19  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_RI_N       );
REG64_FLD( C_NET_CTRL0_DI1_N                                       , 20  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_DI1_N      );
REG64_FLD( C_NET_CTRL0_DI2_N                                       , 21  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_DI2_N      );
REG64_FLD( C_NET_CTRL0_TP_FENCE_PCB                                , 25  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_TP_FENCE_PCB );
REG64_FLD( C_NET_CTRL0_LVLTRANS_FENCE                              , 26  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_LVLTRANS_FENCE );
REG64_FLD( C_NET_CTRL0_L3_EDRAM_ENABLE                             , 27  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_L3_EDRAM_ENABLE );
REG64_FLD( C_NET_CTRL0_HTB_INTEST                                  , 28  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_INTEST );
REG64_FLD( C_NET_CTRL0_HTB_EXTEST                                  , 29  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_HTB_EXTEST );

REG64_FLD( EQ_NET_CTRL1_PLL_CLKIN_SEL                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_CLKIN_SEL );
REG64_FLD( EQ_NET_CTRL1_CLK_DIV_BYPASS_EN                          , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_DIV_BYPASS_EN );
REG64_FLD( EQ_NET_CTRL1_CLK_PDLY_BYPASS_EN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PDLY_BYPASS_EN );
REG64_FLD( EQ_NET_CTRL1_SB_STRENGTH                                , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH );
REG64_FLD( EQ_NET_CTRL1_SB_STRENGTH_LEN                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH_LEN );
REG64_FLD( EQ_NET_CTRL1_CLK_PULSE_EN                               , 25  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_EN );
REG64_FLD( EQ_NET_CTRL1_CLK_PULSE_MODE                             , 26  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE );
REG64_FLD( EQ_NET_CTRL1_CLK_PULSE_MODE_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE_LEN );
REG64_FLD( EQ_NET_CTRL1_RESCLK_DIS                                 , 28  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_RESCLK_DIS );
REG64_FLD( EQ_NET_CTRL1_CPM_CAL_SET                                , 29  , SH_UNT_EQ       , SH_ACS_SCOM2_WOR,
           SH_FLD_CPM_CAL_SET );

REG64_FLD( EX_NET_CTRL1_PLL_CLKIN_SEL                              , 0   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_CLKIN_SEL );
REG64_FLD( EX_NET_CTRL1_CLK_DIV_BYPASS_EN                          , 1   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_DIV_BYPASS_EN );
REG64_FLD( EX_NET_CTRL1_CLK_PDLY_BYPASS_EN                         , 2   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PDLY_BYPASS_EN );
REG64_FLD( EX_NET_CTRL1_SB_STRENGTH                                , 16  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH );
REG64_FLD( EX_NET_CTRL1_SB_STRENGTH_LEN                            , 4   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH_LEN );
REG64_FLD( EX_NET_CTRL1_CLK_PULSE_EN                               , 25  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_EN );
REG64_FLD( EX_NET_CTRL1_CLK_PULSE_MODE                             , 26  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE );
REG64_FLD( EX_NET_CTRL1_CLK_PULSE_MODE_LEN                         , 2   , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE_LEN );
REG64_FLD( EX_NET_CTRL1_RESCLK_DIS                                 , 28  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_RESCLK_DIS );
REG64_FLD( EX_NET_CTRL1_CPM_CAL_SET                                , 29  , SH_UNT_EX       , SH_ACS_SCOM2_WOR,
           SH_FLD_CPM_CAL_SET );

REG64_FLD( C_NET_CTRL1_PLL_CLKIN_SEL                               , 0   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_PLL_CLKIN_SEL );
REG64_FLD( C_NET_CTRL1_CLK_DIV_BYPASS_EN                           , 1   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_DIV_BYPASS_EN );
REG64_FLD( C_NET_CTRL1_CLK_PDLY_BYPASS_EN                          , 2   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PDLY_BYPASS_EN );
REG64_FLD( C_NET_CTRL1_SB_STRENGTH                                 , 16  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH );
REG64_FLD( C_NET_CTRL1_SB_STRENGTH_LEN                             , 4   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_SB_STRENGTH_LEN );
REG64_FLD( C_NET_CTRL1_CLK_PULSE_EN                                , 25  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_EN );
REG64_FLD( C_NET_CTRL1_CLK_PULSE_MODE                              , 26  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE );
REG64_FLD( C_NET_CTRL1_CLK_PULSE_MODE_LEN                          , 2   , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CLK_PULSE_MODE_LEN );
REG64_FLD( C_NET_CTRL1_RESCLK_DIS                                  , 28  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_RESCLK_DIS );
REG64_FLD( C_NET_CTRL1_CPM_CAL_SET                                 , 29  , SH_UNT_C        , SH_ACS_SCOM2_WOR,
           SH_FLD_CPM_CAL_SET );

REG64_FLD( EX_L2_OCC_SCOMC_MODE                                    , 54  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( EX_L2_OCC_SCOMC_MODE_LEN                                , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE_LEN   );

REG64_FLD( C_OCC_SCOMC_MODE                                        , 54  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( C_OCC_SCOMC_MODE_LEN                                    , 7   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE_LEN   );

REG64_FLD( EQ_OPCG_ALIGN_INOP                                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INOP       );
REG64_FLD( EQ_OPCG_ALIGN_INOP_LEN                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INOP_LEN   );
REG64_FLD( EQ_OPCG_ALIGN_SNOP                                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNOP       );
REG64_FLD( EQ_OPCG_ALIGN_SNOP_LEN                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_LEN   );
REG64_FLD( EQ_OPCG_ALIGN_ENOP                                      , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENOP       );
REG64_FLD( EQ_OPCG_ALIGN_ENOP_LEN                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_LEN   );
REG64_FLD( EQ_OPCG_ALIGN_INOP_WAIT                                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT  );
REG64_FLD( EQ_OPCG_ALIGN_INOP_WAIT_LEN                             , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT_LEN );
REG64_FLD( EQ_OPCG_ALIGN_SNOP_WAIT                                 , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT  );
REG64_FLD( EQ_OPCG_ALIGN_SNOP_WAIT_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT_LEN );
REG64_FLD( EQ_OPCG_ALIGN_ENOP_WAIT                                 , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT  );
REG64_FLD( EQ_OPCG_ALIGN_ENOP_WAIT_LEN                             , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT_LEN );
REG64_FLD( EQ_OPCG_ALIGN_INOP_FORCE_SG                             , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INOP_FORCE_SG );
REG64_FLD( EQ_OPCG_ALIGN_SNOP_FORCE_SG                             , 41  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_FORCE_SG );
REG64_FLD( EQ_OPCG_ALIGN_ENOP_FORCE_SG                             , 42  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_FORCE_SG );
REG64_FLD( EQ_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD                        , 43  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NO_WAIT_ON_CLK_CMD );
REG64_FLD( EQ_OPCG_ALIGN_SOURCE_SELECT                             , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT );
REG64_FLD( EQ_OPCG_ALIGN_SOURCE_SELECT_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT_LEN );
REG64_FLD( EQ_OPCG_ALIGN_UNUSED46                                  , 46  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED46   );
REG64_FLD( EQ_OPCG_ALIGN_SCAN_RATIO                                , 47  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO );
REG64_FLD( EQ_OPCG_ALIGN_SCAN_RATIO_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO_LEN );
REG64_FLD( EQ_OPCG_ALIGN_WAIT_CYCLES                               , 52  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EQ_OPCG_ALIGN_WAIT_CYCLES_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EX_OPCG_ALIGN_INOP                                      , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INOP       );
REG64_FLD( EX_OPCG_ALIGN_INOP_LEN                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INOP_LEN   );
REG64_FLD( EX_OPCG_ALIGN_SNOP                                      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SNOP       );
REG64_FLD( EX_OPCG_ALIGN_SNOP_LEN                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_LEN   );
REG64_FLD( EX_OPCG_ALIGN_ENOP                                      , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENOP       );
REG64_FLD( EX_OPCG_ALIGN_ENOP_LEN                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_LEN   );
REG64_FLD( EX_OPCG_ALIGN_INOP_WAIT                                 , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT  );
REG64_FLD( EX_OPCG_ALIGN_INOP_WAIT_LEN                             , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT_LEN );
REG64_FLD( EX_OPCG_ALIGN_SNOP_WAIT                                 , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT  );
REG64_FLD( EX_OPCG_ALIGN_SNOP_WAIT_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT_LEN );
REG64_FLD( EX_OPCG_ALIGN_ENOP_WAIT                                 , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT  );
REG64_FLD( EX_OPCG_ALIGN_ENOP_WAIT_LEN                             , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT_LEN );
REG64_FLD( EX_OPCG_ALIGN_INOP_FORCE_SG                             , 40  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INOP_FORCE_SG );
REG64_FLD( EX_OPCG_ALIGN_SNOP_FORCE_SG                             , 41  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SNOP_FORCE_SG );
REG64_FLD( EX_OPCG_ALIGN_ENOP_FORCE_SG                             , 42  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ENOP_FORCE_SG );
REG64_FLD( EX_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD                        , 43  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NO_WAIT_ON_CLK_CMD );
REG64_FLD( EX_OPCG_ALIGN_SOURCE_SELECT                             , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT );
REG64_FLD( EX_OPCG_ALIGN_SOURCE_SELECT_LEN                         , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT_LEN );
REG64_FLD( EX_OPCG_ALIGN_UNUSED46                                  , 46  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED46   );
REG64_FLD( EX_OPCG_ALIGN_SCAN_RATIO                                , 47  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO );
REG64_FLD( EX_OPCG_ALIGN_SCAN_RATIO_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO_LEN );
REG64_FLD( EX_OPCG_ALIGN_WAIT_CYCLES                               , 52  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EX_OPCG_ALIGN_WAIT_CYCLES_LEN                           , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( C_OPCG_ALIGN_INOP                                       , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INOP       );
REG64_FLD( C_OPCG_ALIGN_INOP_LEN                                   , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INOP_LEN   );
REG64_FLD( C_OPCG_ALIGN_SNOP                                       , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SNOP       );
REG64_FLD( C_OPCG_ALIGN_SNOP_LEN                                   , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SNOP_LEN   );
REG64_FLD( C_OPCG_ALIGN_ENOP                                       , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENOP       );
REG64_FLD( C_OPCG_ALIGN_ENOP_LEN                                   , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENOP_LEN   );
REG64_FLD( C_OPCG_ALIGN_INOP_WAIT                                  , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT  );
REG64_FLD( C_OPCG_ALIGN_INOP_WAIT_LEN                              , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INOP_WAIT_LEN );
REG64_FLD( C_OPCG_ALIGN_SNOP_WAIT                                  , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT  );
REG64_FLD( C_OPCG_ALIGN_SNOP_WAIT_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SNOP_WAIT_LEN );
REG64_FLD( C_OPCG_ALIGN_ENOP_WAIT                                  , 32  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT  );
REG64_FLD( C_OPCG_ALIGN_ENOP_WAIT_LEN                              , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENOP_WAIT_LEN );
REG64_FLD( C_OPCG_ALIGN_INOP_FORCE_SG                              , 40  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INOP_FORCE_SG );
REG64_FLD( C_OPCG_ALIGN_SNOP_FORCE_SG                              , 41  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SNOP_FORCE_SG );
REG64_FLD( C_OPCG_ALIGN_ENOP_FORCE_SG                              , 42  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ENOP_FORCE_SG );
REG64_FLD( C_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD                         , 43  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_NO_WAIT_ON_CLK_CMD );
REG64_FLD( C_OPCG_ALIGN_SOURCE_SELECT                              , 44  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT );
REG64_FLD( C_OPCG_ALIGN_SOURCE_SELECT_LEN                          , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SOURCE_SELECT_LEN );
REG64_FLD( C_OPCG_ALIGN_UNUSED46                                   , 46  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED46   );
REG64_FLD( C_OPCG_ALIGN_SCAN_RATIO                                 , 47  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO );
REG64_FLD( C_OPCG_ALIGN_SCAN_RATIO_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN_RATIO_LEN );
REG64_FLD( C_OPCG_ALIGN_WAIT_CYCLES                                , 52  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( C_OPCG_ALIGN_WAIT_CYCLES_LEN                            , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EQ_OPCG_CAPT1_COUNT                                     , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_COUNT      );
REG64_FLD( EQ_OPCG_CAPT1_COUNT_LEN                                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_COUNT_LEN  );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_01                                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_01_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_02                                    , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_02_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_03                                    , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_03_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_04                                    , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_04_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_05                                    , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_05_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_06                                    , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_06_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_07                                    , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_07_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_08                                    , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_08_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_09                                    , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_09_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_10                                    , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_10_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_11                                    , 54  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_11_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11_LEN );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_12                                    , 59  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12     );
REG64_FLD( EQ_OPCG_CAPT1_SEQ_12_LEN                                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12_LEN );

REG64_FLD( EX_OPCG_CAPT1_COUNT                                     , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_COUNT      );
REG64_FLD( EX_OPCG_CAPT1_COUNT_LEN                                 , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_COUNT_LEN  );
REG64_FLD( EX_OPCG_CAPT1_SEQ_01                                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_01_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_02                                    , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_02_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_03                                    , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_03_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_04                                    , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_04_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_05                                    , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_05_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_06                                    , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_06_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_07                                    , 34  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_07_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_08                                    , 39  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_08_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_09                                    , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_09_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_10                                    , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_10_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_11                                    , 54  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_11_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11_LEN );
REG64_FLD( EX_OPCG_CAPT1_SEQ_12                                    , 59  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12     );
REG64_FLD( EX_OPCG_CAPT1_SEQ_12_LEN                                , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12_LEN );

REG64_FLD( C_OPCG_CAPT1_COUNT                                      , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_COUNT      );
REG64_FLD( C_OPCG_CAPT1_COUNT_LEN                                  , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_COUNT_LEN  );
REG64_FLD( C_OPCG_CAPT1_SEQ_01                                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01     );
REG64_FLD( C_OPCG_CAPT1_SEQ_01_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_01_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_02                                     , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02     );
REG64_FLD( C_OPCG_CAPT1_SEQ_02_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_02_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_03                                     , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03     );
REG64_FLD( C_OPCG_CAPT1_SEQ_03_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_03_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_04                                     , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04     );
REG64_FLD( C_OPCG_CAPT1_SEQ_04_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_04_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_05                                     , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05     );
REG64_FLD( C_OPCG_CAPT1_SEQ_05_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_05_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_06                                     , 29  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06     );
REG64_FLD( C_OPCG_CAPT1_SEQ_06_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_06_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_07                                     , 34  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07     );
REG64_FLD( C_OPCG_CAPT1_SEQ_07_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_08                                     , 39  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08     );
REG64_FLD( C_OPCG_CAPT1_SEQ_08_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_09                                     , 44  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09     );
REG64_FLD( C_OPCG_CAPT1_SEQ_09_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_10                                     , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10     );
REG64_FLD( C_OPCG_CAPT1_SEQ_10_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_11                                     , 54  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11     );
REG64_FLD( C_OPCG_CAPT1_SEQ_11_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11_LEN );
REG64_FLD( C_OPCG_CAPT1_SEQ_12                                     , 59  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12     );
REG64_FLD( C_OPCG_CAPT1_SEQ_12_LEN                                 , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12_LEN );

REG64_FLD( EQ_OPCG_CAPT2_UNUSED                                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EQ_OPCG_CAPT2_UNUSED_LEN                                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_13_01EVEN                             , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_13_01EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_14_01ODD                              , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_14_01ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_15_02EVEN                             , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_15_02EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_16_02ODD                              , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_16_02ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_17_03EVEN                             , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_17_03EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_18_03ODD                              , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_18_03ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_19_04EVEN                             , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_19_04EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_20_04ODD                              , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_20_04ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_21_05EVEN                             , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_21_05EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_22_05ODD                              , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_22_05ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_23_06EVEN                             , 54  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_23_06EVEN_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_24_06ODD                              , 59  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD );
REG64_FLD( EQ_OPCG_CAPT2_SEQ_24_06ODD_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD_LEN );

REG64_FLD( EX_OPCG_CAPT2_UNUSED                                    , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EX_OPCG_CAPT2_UNUSED_LEN                                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_13_01EVEN                             , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_13_01EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_14_01ODD                              , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_14_01ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_15_02EVEN                             , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_15_02EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_16_02ODD                              , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_16_02ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_17_03EVEN                             , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_17_03EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_18_03ODD                              , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_18_03ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_19_04EVEN                             , 34  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_19_04EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_20_04ODD                              , 39  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_20_04ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_21_05EVEN                             , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_21_05EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_22_05ODD                              , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_22_05ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_23_06EVEN                             , 54  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_23_06EVEN_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT2_SEQ_24_06ODD                              , 59  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD );
REG64_FLD( EX_OPCG_CAPT2_SEQ_24_06ODD_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD_LEN );

REG64_FLD( C_OPCG_CAPT2_UNUSED                                     , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( C_OPCG_CAPT2_UNUSED_LEN                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_13_01EVEN                              , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_13_01EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_13_01EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_14_01ODD                               , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_14_01ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_14_01ODD_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_15_02EVEN                              , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_15_02EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_15_02EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_16_02ODD                               , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_16_02ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_16_02ODD_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_17_03EVEN                              , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_17_03EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_17_03EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_18_03ODD                               , 29  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_18_03ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_18_03ODD_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_19_04EVEN                              , 34  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_19_04EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_19_04EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_20_04ODD                               , 39  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_20_04ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_20_04ODD_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_21_05EVEN                              , 44  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_21_05EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_21_05EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_22_05ODD                               , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_22_05ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_22_05ODD_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_23_06EVEN                              , 54  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_23_06EVEN_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_23_06EVEN_LEN );
REG64_FLD( C_OPCG_CAPT2_SEQ_24_06ODD                               , 59  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD );
REG64_FLD( C_OPCG_CAPT2_SEQ_24_06ODD_LEN                           , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_24_06ODD_LEN );

REG64_FLD( EQ_OPCG_CAPT3_UNUSED                                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EQ_OPCG_CAPT3_UNUSED_LEN                                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_07EVEN                                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_07EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_07ODD                                 , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_07ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_08EVEN                                , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_08EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_08ODD                                 , 19  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_08ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_09EVEN                                , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_09EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_09ODD                                 , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_09ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_10EVEN                                , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_10EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_10ODD                                 , 39  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_10ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_11EVEN                                , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_11EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_11ODD                                 , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_11ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_12EVEN                                , 54  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_12EVEN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN_LEN );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_12ODD                                 , 59  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD  );
REG64_FLD( EQ_OPCG_CAPT3_SEQ_12ODD_LEN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD_LEN );

REG64_FLD( EX_OPCG_CAPT3_UNUSED                                    , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EX_OPCG_CAPT3_UNUSED_LEN                                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_07EVEN                                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_07EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_07ODD                                 , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_07ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_08EVEN                                , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_08EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_08ODD                                 , 19  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_08ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_09EVEN                                , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_09EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_09ODD                                 , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_09ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_10EVEN                                , 34  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_10EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_10ODD                                 , 39  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_10ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_11EVEN                                , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_11EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_11ODD                                 , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_11ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_12EVEN                                , 54  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_12EVEN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN_LEN );
REG64_FLD( EX_OPCG_CAPT3_SEQ_12ODD                                 , 59  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD  );
REG64_FLD( EX_OPCG_CAPT3_SEQ_12ODD_LEN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD_LEN );

REG64_FLD( C_OPCG_CAPT3_UNUSED                                     , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( C_OPCG_CAPT3_UNUSED_LEN                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_07EVEN                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_07EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_07ODD                                  , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_07ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_07ODD_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_08EVEN                                 , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_08EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_08ODD                                  , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_08ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_08ODD_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_09EVEN                                 , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_09EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_09ODD                                  , 29  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_09ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_09ODD_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_10EVEN                                 , 34  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_10EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_10ODD                                  , 39  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_10ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_10ODD_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_11EVEN                                 , 44  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_11EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_11ODD                                  , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_11ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_11ODD_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_12EVEN                                 , 54  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_12EVEN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12EVEN_LEN );
REG64_FLD( C_OPCG_CAPT3_SEQ_12ODD                                  , 59  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD  );
REG64_FLD( C_OPCG_CAPT3_SEQ_12ODD_LEN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SEQ_12ODD_LEN );

REG64_FLD( EQ_OPCG_REG0_RUNN_MODE                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUNN_MODE  );
REG64_FLD( EQ_OPCG_REG0_GO                                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GO         );
REG64_FLD( EQ_OPCG_REG0_RUN_SCAN0                                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_SCAN0  );
REG64_FLD( EQ_OPCG_REG0_SCAN0_MODE                                 , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN0_MODE );
REG64_FLD( EQ_OPCG_REG0_IN_SLAVE_MODE                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN_SLAVE_MODE );
REG64_FLD( EQ_OPCG_REG0_IN_MASTER_MODE                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_IN_MASTER_MODE );
REG64_FLD( EQ_OPCG_REG0_KEEP_MS_MODE                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_MS_MODE );
REG64_FLD( EQ_OPCG_REG0_UNUSED78                                   , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78   );
REG64_FLD( EQ_OPCG_REG0_UNUSED78_LEN                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78_LEN );
REG64_FLD( EQ_OPCG_REG0_RUN_CHIPLET_SCAN0                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0 );
REG64_FLD( EQ_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL                   , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0_NO_PLL );
REG64_FLD( EQ_OPCG_REG0_RUN_ON_UPDATE_DR                           , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_UPDATE_DR );
REG64_FLD( EQ_OPCG_REG0_RUN_ON_CAPTURE_DR                          , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_CAPTURE_DR );
REG64_FLD( EQ_OPCG_REG0_STOP_RUNN_ON_XSTOP                         , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_RUNN_ON_XSTOP );
REG64_FLD( EQ_OPCG_REG0_STARTS_BIST                                , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );
REG64_FLD( EQ_OPCG_REG0_UNUSED1520                                 , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520 );
REG64_FLD( EQ_OPCG_REG0_UNUSED1520_LEN                             , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520_LEN );
REG64_FLD( EQ_OPCG_REG0_LOOP_COUNT                                 , 21  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT );
REG64_FLD( EQ_OPCG_REG0_LOOP_COUNT_LEN                             , 43  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT_LEN );

REG64_FLD( EX_OPCG_REG0_RUNN_MODE                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUNN_MODE  );
REG64_FLD( EX_OPCG_REG0_GO                                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GO         );
REG64_FLD( EX_OPCG_REG0_RUN_SCAN0                                  , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_SCAN0  );
REG64_FLD( EX_OPCG_REG0_SCAN0_MODE                                 , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN0_MODE );
REG64_FLD( EX_OPCG_REG0_IN_SLAVE_MODE                              , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN_SLAVE_MODE );
REG64_FLD( EX_OPCG_REG0_IN_MASTER_MODE                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_IN_MASTER_MODE );
REG64_FLD( EX_OPCG_REG0_KEEP_MS_MODE                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_MS_MODE );
REG64_FLD( EX_OPCG_REG0_UNUSED78                                   , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78   );
REG64_FLD( EX_OPCG_REG0_UNUSED78_LEN                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78_LEN );
REG64_FLD( EX_OPCG_REG0_RUN_CHIPLET_SCAN0                          , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0 );
REG64_FLD( EX_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL                   , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0_NO_PLL );
REG64_FLD( EX_OPCG_REG0_RUN_ON_UPDATE_DR                           , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_UPDATE_DR );
REG64_FLD( EX_OPCG_REG0_RUN_ON_CAPTURE_DR                          , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_CAPTURE_DR );
REG64_FLD( EX_OPCG_REG0_STOP_RUNN_ON_XSTOP                         , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_RUNN_ON_XSTOP );
REG64_FLD( EX_OPCG_REG0_STARTS_BIST                                , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );
REG64_FLD( EX_OPCG_REG0_UNUSED1520                                 , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520 );
REG64_FLD( EX_OPCG_REG0_UNUSED1520_LEN                             , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520_LEN );
REG64_FLD( EX_OPCG_REG0_LOOP_COUNT                                 , 21  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT );
REG64_FLD( EX_OPCG_REG0_LOOP_COUNT_LEN                             , 43  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT_LEN );

REG64_FLD( C_OPCG_REG0_RUNN_MODE                                   , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUNN_MODE  );
REG64_FLD( C_OPCG_REG0_GO                                          , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GO         );
REG64_FLD( C_OPCG_REG0_RUN_SCAN0                                   , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_SCAN0  );
REG64_FLD( C_OPCG_REG0_SCAN0_MODE                                  , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN0_MODE );
REG64_FLD( C_OPCG_REG0_IN_SLAVE_MODE                               , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN_SLAVE_MODE );
REG64_FLD( C_OPCG_REG0_IN_MASTER_MODE                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_IN_MASTER_MODE );
REG64_FLD( C_OPCG_REG0_KEEP_MS_MODE                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_KEEP_MS_MODE );
REG64_FLD( C_OPCG_REG0_UNUSED78                                    , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78   );
REG64_FLD( C_OPCG_REG0_UNUSED78_LEN                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED78_LEN );
REG64_FLD( C_OPCG_REG0_RUN_CHIPLET_SCAN0                           , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0 );
REG64_FLD( C_OPCG_REG0_RUN_CHIPLET_SCAN0_NO_PLL                    , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_CHIPLET_SCAN0_NO_PLL );
REG64_FLD( C_OPCG_REG0_RUN_ON_UPDATE_DR                            , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_UPDATE_DR );
REG64_FLD( C_OPCG_REG0_RUN_ON_CAPTURE_DR                           , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_ON_CAPTURE_DR );
REG64_FLD( C_OPCG_REG0_STOP_RUNN_ON_XSTOP                          , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_RUNN_ON_XSTOP );
REG64_FLD( C_OPCG_REG0_STARTS_BIST                                 , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STARTS_BIST );
REG64_FLD( C_OPCG_REG0_UNUSED1520                                  , 15  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520 );
REG64_FLD( C_OPCG_REG0_UNUSED1520_LEN                              , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1520_LEN );
REG64_FLD( C_OPCG_REG0_LOOP_COUNT                                  , 21  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT );
REG64_FLD( C_OPCG_REG0_LOOP_COUNT_LEN                              , 43  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LOOP_COUNT_LEN );

REG64_FLD( EQ_OPCG_REG1_SCAN_COUNT                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT );
REG64_FLD( EQ_OPCG_REG1_SCAN_COUNT_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT_LEN );
REG64_FLD( EQ_OPCG_REG1_MISR_A_VAL                                 , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL );
REG64_FLD( EQ_OPCG_REG1_MISR_A_VAL_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL_LEN );
REG64_FLD( EQ_OPCG_REG1_MISR_B_VAL                                 , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL );
REG64_FLD( EQ_OPCG_REG1_MISR_B_VAL_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL_LEN );
REG64_FLD( EQ_OPCG_REG1_MISR_INIT_WAIT                             , 36  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT );
REG64_FLD( EQ_OPCG_REG1_MISR_INIT_WAIT_LEN                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT_LEN );
REG64_FLD( EQ_OPCG_REG1_SUPPRESS_EVEN_CLK                          , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS_EVEN_CLK );
REG64_FLD( EQ_OPCG_REG1_SCAN_CLK_USE_EVEN                          , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_CLK_USE_EVEN );
REG64_FLD( EQ_OPCG_REG1_UNUSED2                                    , 50  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2    );
REG64_FLD( EQ_OPCG_REG1_UNUSED2_LEN                                , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2_LEN );
REG64_FLD( EQ_OPCG_REG1_USE_ARY_CLK_DURING_FILL                    , 53  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_USE_ARY_CLK_DURING_FILL );
REG64_FLD( EQ_OPCG_REG1_SG_HIGH_DURING_FILL                        , 54  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SG_HIGH_DURING_FILL );
REG64_FLD( EQ_OPCG_REG1_RTIM_THOLD_FORCE                           , 55  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RTIM_THOLD_FORCE );
REG64_FLD( EQ_OPCG_REG1_LBIST_SKITTER_CTL                          , 56  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LBIST_SKITTER_CTL );
REG64_FLD( EQ_OPCG_REG1_MISR_MODE                                  , 57  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MISR_MODE  );
REG64_FLD( EQ_OPCG_REG1_INFINITE_MODE                              , 58  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INFINITE_MODE );
REG64_FLD( EQ_OPCG_REG1_NSL_FILL_COUNT                             , 59  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT );
REG64_FLD( EQ_OPCG_REG1_NSL_FILL_COUNT_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT_LEN );

REG64_FLD( EX_OPCG_REG1_SCAN_COUNT                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT );
REG64_FLD( EX_OPCG_REG1_SCAN_COUNT_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT_LEN );
REG64_FLD( EX_OPCG_REG1_MISR_A_VAL                                 , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL );
REG64_FLD( EX_OPCG_REG1_MISR_A_VAL_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL_LEN );
REG64_FLD( EX_OPCG_REG1_MISR_B_VAL                                 , 24  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL );
REG64_FLD( EX_OPCG_REG1_MISR_B_VAL_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL_LEN );
REG64_FLD( EX_OPCG_REG1_MISR_INIT_WAIT                             , 36  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT );
REG64_FLD( EX_OPCG_REG1_MISR_INIT_WAIT_LEN                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT_LEN );
REG64_FLD( EX_OPCG_REG1_SUPPRESS_EVEN_CLK                          , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS_EVEN_CLK );
REG64_FLD( EX_OPCG_REG1_SCAN_CLK_USE_EVEN                          , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SCAN_CLK_USE_EVEN );
REG64_FLD( EX_OPCG_REG1_UNUSED2                                    , 50  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2    );
REG64_FLD( EX_OPCG_REG1_UNUSED2_LEN                                , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2_LEN );
REG64_FLD( EX_OPCG_REG1_USE_ARY_CLK_DURING_FILL                    , 53  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_USE_ARY_CLK_DURING_FILL );
REG64_FLD( EX_OPCG_REG1_SG_HIGH_DURING_FILL                        , 54  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SG_HIGH_DURING_FILL );
REG64_FLD( EX_OPCG_REG1_RTIM_THOLD_FORCE                           , 55  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RTIM_THOLD_FORCE );
REG64_FLD( EX_OPCG_REG1_LBIST_SKITTER_CTL                          , 56  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LBIST_SKITTER_CTL );
REG64_FLD( EX_OPCG_REG1_MISR_MODE                                  , 57  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MISR_MODE  );
REG64_FLD( EX_OPCG_REG1_INFINITE_MODE                              , 58  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INFINITE_MODE );
REG64_FLD( EX_OPCG_REG1_NSL_FILL_COUNT                             , 59  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT );
REG64_FLD( EX_OPCG_REG1_NSL_FILL_COUNT_LEN                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT_LEN );

REG64_FLD( C_OPCG_REG1_SCAN_COUNT                                  , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT );
REG64_FLD( C_OPCG_REG1_SCAN_COUNT_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN_COUNT_LEN );
REG64_FLD( C_OPCG_REG1_MISR_A_VAL                                  , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL );
REG64_FLD( C_OPCG_REG1_MISR_A_VAL_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_A_VAL_LEN );
REG64_FLD( C_OPCG_REG1_MISR_B_VAL                                  , 24  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL );
REG64_FLD( C_OPCG_REG1_MISR_B_VAL_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_B_VAL_LEN );
REG64_FLD( C_OPCG_REG1_MISR_INIT_WAIT                              , 36  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT );
REG64_FLD( C_OPCG_REG1_MISR_INIT_WAIT_LEN                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_INIT_WAIT_LEN );
REG64_FLD( C_OPCG_REG1_SUPPRESS_EVEN_CLK                           , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SUPPRESS_EVEN_CLK );
REG64_FLD( C_OPCG_REG1_SCAN_CLK_USE_EVEN                           , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SCAN_CLK_USE_EVEN );
REG64_FLD( C_OPCG_REG1_UNUSED2                                     , 50  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2    );
REG64_FLD( C_OPCG_REG1_UNUSED2_LEN                                 , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED2_LEN );
REG64_FLD( C_OPCG_REG1_USE_ARY_CLK_DURING_FILL                     , 53  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_USE_ARY_CLK_DURING_FILL );
REG64_FLD( C_OPCG_REG1_SG_HIGH_DURING_FILL                         , 54  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SG_HIGH_DURING_FILL );
REG64_FLD( C_OPCG_REG1_RTIM_THOLD_FORCE                            , 55  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RTIM_THOLD_FORCE );
REG64_FLD( C_OPCG_REG1_LBIST_SKITTER_CTL                           , 56  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LBIST_SKITTER_CTL );
REG64_FLD( C_OPCG_REG1_MISR_MODE                                   , 57  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MISR_MODE  );
REG64_FLD( C_OPCG_REG1_INFINITE_MODE                               , 58  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INFINITE_MODE );
REG64_FLD( C_OPCG_REG1_NSL_FILL_COUNT                              , 59  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT );
REG64_FLD( C_OPCG_REG1_NSL_FILL_COUNT_LEN                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_NSL_FILL_COUNT_LEN );

REG64_FLD( EQ_OPCG_REG2_GO2                                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GO2        );
REG64_FLD( EQ_OPCG_REG2_PRPG_WEIGHTING                             , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING );
REG64_FLD( EQ_OPCG_REG2_PRPG_WEIGHTING_LEN                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING_LEN );
REG64_FLD( EQ_OPCG_REG2_PRPG_VALUE                                 , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE );
REG64_FLD( EQ_OPCG_REG2_PRPG_VALUE_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE_LEN );
REG64_FLD( EQ_OPCG_REG2_PRPG_A_VAL                                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL );
REG64_FLD( EQ_OPCG_REG2_PRPG_A_VAL_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL_LEN );
REG64_FLD( EQ_OPCG_REG2_PRPG_B_VAL                                 , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL );
REG64_FLD( EQ_OPCG_REG2_PRPG_B_VAL_LEN                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL_LEN );
REG64_FLD( EQ_OPCG_REG2_PRPG_MODE                                  , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_MODE  );
REG64_FLD( EQ_OPCG_REG2_UNUSED41_63                                , 41  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63 );
REG64_FLD( EQ_OPCG_REG2_UNUSED41_63_LEN                            , 23  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63_LEN );

REG64_FLD( EX_OPCG_REG2_GO2                                        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GO2        );
REG64_FLD( EX_OPCG_REG2_PRPG_WEIGHTING                             , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING );
REG64_FLD( EX_OPCG_REG2_PRPG_WEIGHTING_LEN                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING_LEN );
REG64_FLD( EX_OPCG_REG2_PRPG_VALUE                                 , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE );
REG64_FLD( EX_OPCG_REG2_PRPG_VALUE_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE_LEN );
REG64_FLD( EX_OPCG_REG2_PRPG_A_VAL                                 , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL );
REG64_FLD( EX_OPCG_REG2_PRPG_A_VAL_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL_LEN );
REG64_FLD( EX_OPCG_REG2_PRPG_B_VAL                                 , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL );
REG64_FLD( EX_OPCG_REG2_PRPG_B_VAL_LEN                             , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL_LEN );
REG64_FLD( EX_OPCG_REG2_PRPG_MODE                                  , 40  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRPG_MODE  );
REG64_FLD( EX_OPCG_REG2_UNUSED41_63                                , 41  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63 );
REG64_FLD( EX_OPCG_REG2_UNUSED41_63_LEN                            , 23  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63_LEN );

REG64_FLD( C_OPCG_REG2_GO2                                         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GO2        );
REG64_FLD( C_OPCG_REG2_PRPG_WEIGHTING                              , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING );
REG64_FLD( C_OPCG_REG2_PRPG_WEIGHTING_LEN                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_WEIGHTING_LEN );
REG64_FLD( C_OPCG_REG2_PRPG_VALUE                                  , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE );
REG64_FLD( C_OPCG_REG2_PRPG_VALUE_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_VALUE_LEN );
REG64_FLD( C_OPCG_REG2_PRPG_A_VAL                                  , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL );
REG64_FLD( C_OPCG_REG2_PRPG_A_VAL_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_A_VAL_LEN );
REG64_FLD( C_OPCG_REG2_PRPG_B_VAL                                  , 28  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL );
REG64_FLD( C_OPCG_REG2_PRPG_B_VAL_LEN                              , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_B_VAL_LEN );
REG64_FLD( C_OPCG_REG2_PRPG_MODE                                   , 40  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PRPG_MODE  );
REG64_FLD( C_OPCG_REG2_UNUSED41_63                                 , 41  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63 );
REG64_FLD( C_OPCG_REG2_UNUSED41_63_LEN                             , 23  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED41_63_LEN );

REG64_FLD( EQ_PHYP_PURGE_CMD_REG_TRIGGER                           , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER    );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_TYPE                              , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_TYPE_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_BUSY                              , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS                , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY_ON_THIS );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_PRGSM_BUSY                        , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_MEM                               , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_MEM_LEN                           , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_CGC                               , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CGC        );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_CGC_LEN                           , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CGC_LEN    );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_BANK                              , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BANK       );
REG64_FLD( EQ_PHYP_PURGE_CMD_REG_ERR                               , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERR        );

REG64_FLD( EX_PHYP_PURGE_CMD_REG_TRIGGER                           , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER    );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_TYPE                              , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_TYPE_LEN                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_BUSY                              , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS                , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY_ON_THIS );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_PRGSM_BUSY                        , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_MEM                               , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_MEM_LEN                           , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_CGC                               , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CGC        );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_CGC_LEN                           , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CGC_LEN    );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_BANK                              , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BANK       );
REG64_FLD( EX_PHYP_PURGE_CMD_REG_ERR                               , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERR        );

REG64_FLD( EQ_PHYP_PURGE_REG_L3_REQ                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_TTYPE                              , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE   );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_TTYPE_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE_LEN );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_LINE_DEL_ON_NEXT_CE                , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_NEXT_CE );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_LINE_DEL_ON_ALL_CE                 , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_ALL_CE );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_BUSY_ERR                           , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_MEMBER                             , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER  );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_MEMBER_LEN                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER_LEN );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_DIR_ADDR                           , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR );
REG64_FLD( EQ_PHYP_PURGE_REG_L3_DIR_ADDR_LEN                       , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR_LEN );

REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_REQ                             , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_TTYPE                           , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE   );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_TTYPE_LEN                       , 4   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE_LEN );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_LINE_DEL_ON_NEXT_CE             , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_NEXT_CE );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_LINE_DEL_ON_ALL_CE              , 6   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_ALL_CE );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_BUSY_ERR                        , 9   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_MEMBER                          , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER  );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_MEMBER_LEN                      , 5   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER_LEN );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_DIR_ADDR                        , 17  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR );
REG64_FLD( EX_L3_PHYP_PURGE_REG_L3_DIR_ADDR_LEN                    , 12  , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR_LEN );

REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_ENABLE                 , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_ENABLE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_ENABLE                 , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_ENABLE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_ENABLE                 , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_ENABLE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_ENABLE                 , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_ENABLE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_PRESCALER_SELECT                , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_PRESCALER_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_PRESCALER_SELECT_LEN            , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_PRESCALER_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER_FREEZE_MODE             , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER_FREEZE_MODE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER_RESET_MODE              , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER_RESET_MODE );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_EVENT_SELECT           , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_POSEDGE_SELECT         , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_BIT_PAIR_SELECT        , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER0_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER0_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_EVENT_SELECT           , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_POSEDGE_SELECT         , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_BIT_PAIR_SELECT        , 21  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER1_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER1_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_EVENT_SELECT           , 23  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_POSEDGE_SELECT         , 27  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_BIT_PAIR_SELECT        , 28  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER2_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER2_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_EVENT_SELECT           , 30  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_POSEDGE_SELECT         , 34  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_BIT_PAIR_SELECT        , 35  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_COUNTER3_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_COUNTER3_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_PORT_SELECT                     , 37  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_PORT_SELECT );
REG64_FLD( CAPP_PMU_CNTRA_CFG_PMUA_PORT_SELECT_LEN                 , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUA_PORT_SELECT_LEN );

REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_0                           , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_0 );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_0_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_0_LEN );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_1                           , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_1 );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_1_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_1_LEN );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_2                           , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_2 );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_2_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_2_LEN );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_3                           , 48  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_3 );
REG64_FLD( CAPP_PMU_CNTRA_REG_COUNTERA_3_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERA_3_LEN );

REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_ENABLE                 , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_ENABLE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_ENABLE                 , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_ENABLE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_ENABLE                 , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_ENABLE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_ENABLE                 , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_ENABLE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_PRESCALER_SELECT                , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_PRESCALER_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_PRESCALER_SELECT_LEN            , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_PRESCALER_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER_FREEZE_MODE             , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER_FREEZE_MODE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER_RESET_MODE              , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER_RESET_MODE );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_EVENT_SELECT           , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_POSEDGE_SELECT         , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_BIT_PAIR_SELECT        , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER0_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER0_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_EVENT_SELECT           , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_POSEDGE_SELECT         , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_BIT_PAIR_SELECT        , 21  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER1_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER1_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_EVENT_SELECT           , 23  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_POSEDGE_SELECT         , 27  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_BIT_PAIR_SELECT        , 28  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER2_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER2_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_EVENT_SELECT           , 30  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_EVENT_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_EVENT_SELECT_LEN       , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_EVENT_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_POSEDGE_SELECT         , 34  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_POSEDGE_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_BIT_PAIR_SELECT        , 35  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_BIT_PAIR_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_COUNTER3_BIT_PAIR_SELECT_LEN    , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_COUNTER3_BIT_PAIR_SELECT_LEN );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_PORT_SELECT                     , 37  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_PORT_SELECT );
REG64_FLD( CAPP_PMU_CNTRB_CFG_PMUB_PORT_SELECT_LEN                 , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMUB_PORT_SELECT_LEN );

REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_0                           , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_0 );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_0_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_0_LEN );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_1                           , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_1 );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_1_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_1_LEN );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_2                           , 32  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_2 );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_2_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_2_LEN );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_3                           , 48  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_3 );
REG64_FLD( CAPP_PMU_CNTRB_REG_COUNTERB_3_LEN                       , 16  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_COUNTERB_3_LEN );

REG64_FLD( EQ_PM_FENCE_LCO_REG_L3_CFG                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG     );

REG64_FLD( EX_L3_PM_FENCE_LCO_REG_L3_CFG                           , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_CFG     );

REG64_FLD( EQ_PM_PURGE_REG_L3_REQ                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EQ_PM_PURGE_REG_L3_BUSY_ERR                             , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EQ_PM_PURGE_REG_L3_ABORT                                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_ABORT   );

REG64_FLD( EX_L3_PM_PURGE_REG_L3_REQ                               , 0   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EX_L3_PM_PURGE_REG_L3_BUSY_ERR                          , 1   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EX_L3_PM_PURGE_REG_L3_ABORT                             , 2   , SH_UNT_EX_L3    , SH_ACS_SCOM     ,
           SH_FLD_L3_ABORT   );

REG64_FLD( EQ_PPE_XIDBGPRO_NULL_MSR_SIBRC                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( EQ_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN                      , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( EQ_PPE_XIDBGPRO_NULL_MSR_WE                             , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( EQ_PPE_XIDBGPRO_NULL_MSR_LP                             , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );

REG64_FLD( EX_PPE_XIDBGPRO_NULL_MSR_SIBRC                          , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( EX_PPE_XIDBGPRO_NULL_MSR_SIBRC_LEN                      , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( EX_PPE_XIDBGPRO_NULL_MSR_WE                             , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( EX_PPE_XIDBGPRO_NULL_MSR_LP                             , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );

REG64_FLD( EQ_PPE_XIRAMDBG_NULL_MSR_SIBRC                          , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( EQ_PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN                      , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( EQ_PPE_XIRAMDBG_NULL_MSR_WE                             , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( EQ_PPE_XIRAMDBG_NULL_MSR_LP                             , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );
REG64_FLD( EQ_PPE_XIRAMDBG_XIRAMRA_SPRG0                           , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( EQ_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN                       , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( EX_PPE_XIRAMDBG_NULL_MSR_SIBRC                          , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC );
REG64_FLD( EX_PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN                      , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_SIBRC_LEN );
REG64_FLD( EX_PPE_XIRAMDBG_NULL_MSR_WE                             , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_WE );
REG64_FLD( EX_PPE_XIRAMDBG_NULL_MSR_LP                             , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_NULL_MSR_LP );
REG64_FLD( EX_PPE_XIRAMDBG_XIRAMRA_SPRG0                           , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( EX_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN                       , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( EQ_PPE_XIRAMEDR_XIRAMGA_IR                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR );
REG64_FLD( EQ_PPE_XIRAMEDR_XIRAMGA_IR_LEN                          , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR_LEN );
REG64_FLD( EQ_PPE_XIRAMEDR_EDR                                     , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EDR        );
REG64_FLD( EQ_PPE_XIRAMEDR_EDR_LEN                                 , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_EDR_LEN    );

REG64_FLD( EX_PPE_XIRAMEDR_XIRAMGA_IR                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR );
REG64_FLD( EX_PPE_XIRAMEDR_XIRAMGA_IR_LEN                          , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_XIRAMGA_IR_LEN );
REG64_FLD( EX_PPE_XIRAMEDR_EDR                                     , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_EDR        );
REG64_FLD( EX_PPE_XIRAMEDR_EDR_LEN                                 , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_EDR_LEN    );

REG64_FLD( EQ_PPE_XIRAMGA_IR                                       , 0   , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_IR         );
REG64_FLD( EQ_PPE_XIRAMGA_IR_LEN                                   , 32  , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_IR_LEN     );
REG64_FLD( EQ_PPE_XIRAMGA_XIRAMRA_SPRG0                            , 32  , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( EQ_PPE_XIRAMGA_XIRAMRA_SPRG0_LEN                        , 32  , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( EX_PPE_XIRAMGA_IR                                       , 0   , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_IR         );
REG64_FLD( EX_PPE_XIRAMGA_IR_LEN                                   , 32  , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_IR_LEN     );
REG64_FLD( EX_PPE_XIRAMGA_XIRAMRA_SPRG0                            , 32  , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0 );
REG64_FLD( EX_PPE_XIRAMGA_XIRAMRA_SPRG0_LEN                        , 32  , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIRAMRA_SPRG0_LEN );

REG64_FLD( EQ_PPE_XIRAMRA_XIXCR_XCR                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR  );
REG64_FLD( EQ_PPE_XIRAMRA_XIXCR_XCR_LEN                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR_LEN );
REG64_FLD( EQ_PPE_XIRAMRA_SPRG0                                    , 32  , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0      );
REG64_FLD( EQ_PPE_XIRAMRA_SPRG0_LEN                                , 32  , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0_LEN  );

REG64_FLD( EX_PPE_XIRAMRA_XIXCR_XCR                                , 1   , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR  );
REG64_FLD( EX_PPE_XIRAMRA_XIXCR_XCR_LEN                            , 3   , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XIXCR_XCR_LEN );
REG64_FLD( EX_PPE_XIRAMRA_SPRG0                                    , 32  , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0      );
REG64_FLD( EX_PPE_XIRAMRA_SPRG0_LEN                                , 32  , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_SPRG0_LEN  );

REG64_FLD( EQ_PPE_XIXCR_XCR                                        , 1   , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR        );
REG64_FLD( EQ_PPE_XIXCR_XCR_LEN                                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR_LEN    );

REG64_FLD( EX_PPE_XIXCR_XCR                                        , 1   , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR        );
REG64_FLD( EX_PPE_XIXCR_XCR_LEN                                    , 3   , SH_UNT_EX       , SH_ACS_SCOM_WO  ,
           SH_FLD_XCR_LEN    );

REG64_FLD( EQ_PPM_CGCR_CLKGLM_ASYNC_RESET                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_ASYNC_RESET );
REG64_FLD( EQ_PPM_CGCR_RESERVED_1_2                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2 );
REG64_FLD( EQ_PPM_CGCR_RESERVED_1_2_LEN                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2_LEN );
REG64_FLD( EQ_PPM_CGCR_CLKGLM_SEL                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_SEL );

REG64_FLD( EX_PPM_CGCR_CLKGLM_ASYNC_RESET                          , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_ASYNC_RESET );
REG64_FLD( EX_PPM_CGCR_RESERVED_1_2                                , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2 );
REG64_FLD( EX_PPM_CGCR_RESERVED_1_2_LEN                            , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2_LEN );
REG64_FLD( EX_PPM_CGCR_CLKGLM_SEL                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_SEL );

REG64_FLD( C_PPM_CGCR_CLKGLM_ASYNC_RESET                           , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_ASYNC_RESET );
REG64_FLD( C_PPM_CGCR_RESERVED_1_2                                 , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2 );
REG64_FLD( C_PPM_CGCR_RESERVED_1_2_LEN                             , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_1_2_LEN );
REG64_FLD( C_PPM_CGCR_CLKGLM_SEL                                   , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CLKGLM_SEL );

REG64_FLD( EQ_PPM_IVRMCR_IVRM_VID_VALID                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VID_VALID );
REG64_FLD( EQ_PPM_IVRMCR_IVRM_BYPASS_B                             , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_BYPASS_B );
REG64_FLD( EQ_PPM_IVRMCR_IVRM_POWERON                              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_POWERON );
REG64_FLD( EQ_PPM_IVRMCR_IVRM_VREG_SLOW_DC                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VREG_SLOW_DC );
REG64_FLD( EQ_PPM_IVRMCR_RESERVED_4_7                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7 );
REG64_FLD( EQ_PPM_IVRMCR_RESERVED_4_7_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7_LEN );

REG64_FLD( EX_PPM_IVRMCR_IVRM_VID_VALID                            , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VID_VALID );
REG64_FLD( EX_PPM_IVRMCR_IVRM_BYPASS_B                             , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_BYPASS_B );
REG64_FLD( EX_PPM_IVRMCR_IVRM_POWERON                              , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_POWERON );
REG64_FLD( EX_PPM_IVRMCR_IVRM_VREG_SLOW_DC                         , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VREG_SLOW_DC );
REG64_FLD( EX_PPM_IVRMCR_RESERVED_4_7                              , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7 );
REG64_FLD( EX_PPM_IVRMCR_RESERVED_4_7_LEN                          , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7_LEN );

REG64_FLD( C_PPM_IVRMCR_IVRM_VID_VALID                             , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VID_VALID );
REG64_FLD( C_PPM_IVRMCR_IVRM_BYPASS_B                              , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_BYPASS_B );
REG64_FLD( C_PPM_IVRMCR_IVRM_POWERON                               , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_POWERON );
REG64_FLD( C_PPM_IVRMCR_IVRM_VREG_SLOW_DC                          , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_IVRM_VREG_SLOW_DC );
REG64_FLD( C_PPM_IVRMCR_RESERVED_4_7                               , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7 );
REG64_FLD( C_PPM_IVRMCR_RESERVED_4_7_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_4_7_LEN );

REG64_FLD( EQ_PPM_IVRMDVR_IVRM_IVID                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID  );
REG64_FLD( EQ_PPM_IVRMDVR_IVRM_IVID_LEN                            , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID_LEN );
REG64_FLD( EQ_PPM_IVRMDVR_RESERVED_8_10                            , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10 );
REG64_FLD( EQ_PPM_IVRMDVR_RESERVED_8_10_LEN                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10_LEN );
REG64_FLD( EQ_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE                  , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE );
REG64_FLD( EQ_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE_LEN              , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE_LEN );
REG64_FLD( EQ_PPM_IVRMDVR_RESERVED_16_18                           , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18 );
REG64_FLD( EQ_PPM_IVRMDVR_RESERVED_16_18_LEN                       , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18_LEN );
REG64_FLD( EQ_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE                 , 19  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE );
REG64_FLD( EQ_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE_LEN             , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE_LEN );

REG64_FLD( EX_PPM_IVRMDVR_IVRM_IVID                                , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID  );
REG64_FLD( EX_PPM_IVRMDVR_IVRM_IVID_LEN                            , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID_LEN );
REG64_FLD( EX_PPM_IVRMDVR_RESERVED_8_10                            , 8   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10 );
REG64_FLD( EX_PPM_IVRMDVR_RESERVED_8_10_LEN                        , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10_LEN );
REG64_FLD( EX_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE                  , 11  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE );
REG64_FLD( EX_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE_LEN              , 5   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE_LEN );
REG64_FLD( EX_PPM_IVRMDVR_RESERVED_16_18                           , 16  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18 );
REG64_FLD( EX_PPM_IVRMDVR_RESERVED_16_18_LEN                       , 3   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18_LEN );
REG64_FLD( EX_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE                 , 19  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE );
REG64_FLD( EX_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE_LEN             , 5   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE_LEN );

REG64_FLD( C_PPM_IVRMDVR_IVRM_IVID                                 , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID  );
REG64_FLD( C_PPM_IVRMDVR_IVRM_IVID_LEN                             , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_IVID_LEN );
REG64_FLD( C_PPM_IVRMDVR_RESERVED_8_10                             , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10 );
REG64_FLD( C_PPM_IVRMDVR_RESERVED_8_10_LEN                         , 3   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_8_10_LEN );
REG64_FLD( C_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE                   , 11  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE );
REG64_FLD( C_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CORE_LEN               , 5   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CORE_LEN );
REG64_FLD( C_PPM_IVRMDVR_RESERVED_16_18                            , 16  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18 );
REG64_FLD( C_PPM_IVRMDVR_RESERVED_16_18_LEN                        , 3   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_16_18_LEN );
REG64_FLD( C_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE                  , 19  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE );
REG64_FLD( C_PPM_IVRMDVR_IVRM_PFET_STRENGTH_CACHE_LEN              , 5   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_IVRM_PFET_STRENGTH_CACHE_LEN );

REG64_FLD( EQ_PPM_IVRMST_IVRM_VID_DONE                             , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_IVRM_VID_DONE );

REG64_FLD( EX_PPM_IVRMST_IVRM_VID_DONE                             , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_IVRM_VID_DONE );

REG64_FLD( C_PPM_IVRMST_IVRM_VID_DONE                              , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_IVRM_VID_DONE );

REG64_FLD( EQ_PPM_PFCS_VDD_PFET_FORCE_STATE                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_FORCE_STATE_LEN                    , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE_LEN );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_FORCE_STATE                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_FORCE_STATE_LEN                    , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE_LEN );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_VAL_OVERRIDE                       , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_VAL_OVERRIDE );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_SEL_OVERRIDE                       , 5   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_OVERRIDE );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_VAL_OVERRIDE                       , 6   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_VAL_OVERRIDE );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_SEL_OVERRIDE                       , 7   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_OVERRIDE );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_REGULATION_FINGER_EN               , 8   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_EN );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_REGULATION_FINGER_VALUE            , 9   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_VALUE );
REG64_FLD( EQ_PPM_PFCS_RESERVED_10_11                              , 10  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11 );
REG64_FLD( EQ_PPM_PFCS_RESERVED_10_11_LEN                          , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11_LEN );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_ENABLE_VALUE                       , 12  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_ENABLE_VALUE_LEN                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE_LEN );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_SEL_VALUE                          , 20  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE );
REG64_FLD( EQ_PPM_PFCS_VDD_PFET_SEL_VALUE_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE_LEN );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_ENABLE_VALUE                       , 24  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_ENABLE_VALUE_LEN                   , 8   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE_LEN );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_SEL_VALUE                          , 32  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE );
REG64_FLD( EQ_PPM_PFCS_VCS_PFET_SEL_VALUE_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE_LEN );
REG64_FLD( EQ_PPM_PFCS_VDD_PG_STATE                                , 42  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE );
REG64_FLD( EQ_PPM_PFCS_VDD_PG_STATE_LEN                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE_LEN );
REG64_FLD( EQ_PPM_PFCS_VDD_PG_SEL                                  , 46  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL );
REG64_FLD( EQ_PPM_PFCS_VDD_PG_SEL_LEN                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL_LEN );
REG64_FLD( EQ_PPM_PFCS_VCS_PG_STATE                                , 50  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE );
REG64_FLD( EQ_PPM_PFCS_VCS_PG_STATE_LEN                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE_LEN );
REG64_FLD( EQ_PPM_PFCS_VCS_PG_SEL                                  , 54  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL );
REG64_FLD( EQ_PPM_PFCS_VCS_PG_SEL_LEN                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL_LEN );

REG64_FLD( EX_PPM_PFCS_VDD_PFET_FORCE_STATE                        , 0   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_FORCE_STATE_LEN                    , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE_LEN );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_FORCE_STATE                        , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_FORCE_STATE_LEN                    , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE_LEN );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_VAL_OVERRIDE                       , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_VAL_OVERRIDE );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_SEL_OVERRIDE                       , 5   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_OVERRIDE );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_VAL_OVERRIDE                       , 6   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_VAL_OVERRIDE );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_SEL_OVERRIDE                       , 7   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_OVERRIDE );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_REGULATION_FINGER_EN               , 8   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_EN );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_REGULATION_FINGER_VALUE            , 9   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_VALUE );
REG64_FLD( EX_PPM_PFCS_RESERVED_10_11                              , 10  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11 );
REG64_FLD( EX_PPM_PFCS_RESERVED_10_11_LEN                          , 2   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11_LEN );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_ENABLE_VALUE                       , 12  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_ENABLE_VALUE_LEN                   , 8   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE_LEN );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_SEL_VALUE                          , 20  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE );
REG64_FLD( EX_PPM_PFCS_VDD_PFET_SEL_VALUE_LEN                      , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE_LEN );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_ENABLE_VALUE                       , 24  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_ENABLE_VALUE_LEN                   , 8   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE_LEN );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_SEL_VALUE                          , 32  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE );
REG64_FLD( EX_PPM_PFCS_VCS_PFET_SEL_VALUE_LEN                      , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE_LEN );
REG64_FLD( EX_PPM_PFCS_VDD_PG_STATE                                , 42  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE );
REG64_FLD( EX_PPM_PFCS_VDD_PG_STATE_LEN                            , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE_LEN );
REG64_FLD( EX_PPM_PFCS_VDD_PG_SEL                                  , 46  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL );
REG64_FLD( EX_PPM_PFCS_VDD_PG_SEL_LEN                              , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL_LEN );
REG64_FLD( EX_PPM_PFCS_VCS_PG_STATE                                , 50  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE );
REG64_FLD( EX_PPM_PFCS_VCS_PG_STATE_LEN                            , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE_LEN );
REG64_FLD( EX_PPM_PFCS_VCS_PG_SEL                                  , 54  , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL );
REG64_FLD( EX_PPM_PFCS_VCS_PG_SEL_LEN                              , 4   , SH_UNT_EX       , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL_LEN );

REG64_FLD( C_PPM_PFCS_VDD_PFET_FORCE_STATE                         , 0   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE );
REG64_FLD( C_PPM_PFCS_VDD_PFET_FORCE_STATE_LEN                     , 2   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_FORCE_STATE_LEN );
REG64_FLD( C_PPM_PFCS_VCS_PFET_FORCE_STATE                         , 2   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE );
REG64_FLD( C_PPM_PFCS_VCS_PFET_FORCE_STATE_LEN                     , 2   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_FORCE_STATE_LEN );
REG64_FLD( C_PPM_PFCS_VDD_PFET_VAL_OVERRIDE                        , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_VAL_OVERRIDE );
REG64_FLD( C_PPM_PFCS_VDD_PFET_SEL_OVERRIDE                        , 5   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_OVERRIDE );
REG64_FLD( C_PPM_PFCS_VCS_PFET_VAL_OVERRIDE                        , 6   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_VAL_OVERRIDE );
REG64_FLD( C_PPM_PFCS_VCS_PFET_SEL_OVERRIDE                        , 7   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_OVERRIDE );
REG64_FLD( C_PPM_PFCS_VDD_PFET_REGULATION_FINGER_EN                , 8   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_EN );
REG64_FLD( C_PPM_PFCS_VDD_PFET_REGULATION_FINGER_VALUE             , 9   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_REGULATION_FINGER_VALUE );
REG64_FLD( C_PPM_PFCS_RESERVED_10_11                               , 10  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11 );
REG64_FLD( C_PPM_PFCS_RESERVED_10_11_LEN                           , 2   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_10_11_LEN );
REG64_FLD( C_PPM_PFCS_VDD_PFET_ENABLE_VALUE                        , 12  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE );
REG64_FLD( C_PPM_PFCS_VDD_PFET_ENABLE_VALUE_LEN                    , 8   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_ENABLE_VALUE_LEN );
REG64_FLD( C_PPM_PFCS_VDD_PFET_SEL_VALUE                           , 20  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE );
REG64_FLD( C_PPM_PFCS_VDD_PFET_SEL_VALUE_LEN                       , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PFET_SEL_VALUE_LEN );
REG64_FLD( C_PPM_PFCS_VCS_PFET_ENABLE_VALUE                        , 24  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE );
REG64_FLD( C_PPM_PFCS_VCS_PFET_ENABLE_VALUE_LEN                    , 8   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_ENABLE_VALUE_LEN );
REG64_FLD( C_PPM_PFCS_VCS_PFET_SEL_VALUE                           , 32  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE );
REG64_FLD( C_PPM_PFCS_VCS_PFET_SEL_VALUE_LEN                       , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PFET_SEL_VALUE_LEN );
REG64_FLD( C_PPM_PFCS_VDD_PG_STATE                                 , 42  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE );
REG64_FLD( C_PPM_PFCS_VDD_PG_STATE_LEN                             , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_STATE_LEN );
REG64_FLD( C_PPM_PFCS_VDD_PG_SEL                                   , 46  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL );
REG64_FLD( C_PPM_PFCS_VDD_PG_SEL_LEN                               , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VDD_PG_SEL_LEN );
REG64_FLD( C_PPM_PFCS_VCS_PG_STATE                                 , 50  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE );
REG64_FLD( C_PPM_PFCS_VCS_PG_STATE_LEN                             , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_STATE_LEN );
REG64_FLD( C_PPM_PFCS_VCS_PG_SEL                                   , 54  , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL );
REG64_FLD( C_PPM_PFCS_VCS_PG_SEL_LEN                               , 4   , SH_UNT_C        , SH_ACS_SCOM2    ,
           SH_FLD_VCS_PG_SEL_LEN );

REG64_FLD( EQ_PPM_PFDLY_POWDN_DLY                                  , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY  );
REG64_FLD( EQ_PPM_PFDLY_POWDN_DLY_LEN                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY_LEN );
REG64_FLD( EQ_PPM_PFDLY_POWUP_DLY                                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY  );
REG64_FLD( EQ_PPM_PFDLY_POWUP_DLY_LEN                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY_LEN );

REG64_FLD( EX_PPM_PFDLY_POWDN_DLY                                  , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY  );
REG64_FLD( EX_PPM_PFDLY_POWDN_DLY_LEN                              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY_LEN );
REG64_FLD( EX_PPM_PFDLY_POWUP_DLY                                  , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY  );
REG64_FLD( EX_PPM_PFDLY_POWUP_DLY_LEN                              , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY_LEN );

REG64_FLD( C_PPM_PFDLY_POWDN_DLY                                   , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY  );
REG64_FLD( C_PPM_PFDLY_POWDN_DLY_LEN                               , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_POWDN_DLY_LEN );
REG64_FLD( C_PPM_PFDLY_POWUP_DLY                                   , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY  );
REG64_FLD( C_PPM_PFDLY_POWUP_DLY_LEN                               , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_POWUP_DLY_LEN );

REG64_FLD( EQ_PPM_PFOFF_VDD_VOFF_SEL                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL );
REG64_FLD( EQ_PPM_PFOFF_VDD_VOFF_SEL_LEN                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL_LEN );
REG64_FLD( EQ_PPM_PFOFF_VCS_VOFF_SEL                               , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL );
REG64_FLD( EQ_PPM_PFOFF_VCS_VOFF_SEL_LEN                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL_LEN );

REG64_FLD( EX_PPM_PFOFF_VDD_VOFF_SEL                               , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL );
REG64_FLD( EX_PPM_PFOFF_VDD_VOFF_SEL_LEN                           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL_LEN );
REG64_FLD( EX_PPM_PFOFF_VCS_VOFF_SEL                               , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL );
REG64_FLD( EX_PPM_PFOFF_VCS_VOFF_SEL_LEN                           , 4   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL_LEN );

REG64_FLD( C_PPM_PFOFF_VDD_VOFF_SEL                                , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL );
REG64_FLD( C_PPM_PFOFF_VDD_VOFF_SEL_LEN                            , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_VDD_VOFF_SEL_LEN );
REG64_FLD( C_PPM_PFOFF_VCS_VOFF_SEL                                , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL );
REG64_FLD( C_PPM_PFOFF_VCS_VOFF_SEL_LEN                            , 4   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_VCS_VOFF_SEL_LEN );

REG64_FLD( EQ_PPM_PFSNS_VDD_PFETS_ENABLED_SENSE                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_ENABLED_SENSE );
REG64_FLD( EQ_PPM_PFSNS_VDD_PFETS_DISABLED_SENSE                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_DISABLED_SENSE );
REG64_FLD( EQ_PPM_PFSNS_VCS_PFETS_ENABLED_SENSE                    , 2   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_ENABLED_SENSE );
REG64_FLD( EQ_PPM_PFSNS_VCS_PFETS_DISABLED_SENSE                   , 3   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_DISABLED_SENSE );
REG64_FLD( EQ_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL                  , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL );
REG64_FLD( EQ_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL_LEN              , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL_LEN );
REG64_FLD( EQ_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL                  , 24  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL );
REG64_FLD( EQ_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL_LEN              , 8   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL_LEN );

REG64_FLD( EX_PPM_PFSNS_VDD_PFETS_ENABLED_SENSE                    , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_ENABLED_SENSE );
REG64_FLD( EX_PPM_PFSNS_VDD_PFETS_DISABLED_SENSE                   , 1   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_DISABLED_SENSE );
REG64_FLD( EX_PPM_PFSNS_VCS_PFETS_ENABLED_SENSE                    , 2   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_ENABLED_SENSE );
REG64_FLD( EX_PPM_PFSNS_VCS_PFETS_DISABLED_SENSE                   , 3   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_DISABLED_SENSE );
REG64_FLD( EX_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL                  , 16  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL );
REG64_FLD( EX_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL_LEN              , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL_LEN );
REG64_FLD( EX_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL                  , 24  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL );
REG64_FLD( EX_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL_LEN              , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL_LEN );

REG64_FLD( C_PPM_PFSNS_VDD_PFETS_ENABLED_SENSE                     , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_ENABLED_SENSE );
REG64_FLD( C_PPM_PFSNS_VDD_PFETS_DISABLED_SENSE                    , 1   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VDD_PFETS_DISABLED_SENSE );
REG64_FLD( C_PPM_PFSNS_VCS_PFETS_ENABLED_SENSE                     , 2   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_ENABLED_SENSE );
REG64_FLD( C_PPM_PFSNS_VCS_PFETS_DISABLED_SENSE                    , 3   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VCS_PFETS_DISABLED_SENSE );
REG64_FLD( C_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL                   , 16  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL );
REG64_FLD( C_PPM_PFSNS_TP_VDD_PFET_ENABLE_ACTUAL_LEN               , 8   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VDD_PFET_ENABLE_ACTUAL_LEN );
REG64_FLD( C_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL                   , 24  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL );
REG64_FLD( C_PPM_PFSNS_TP_VCS_PFET_ENABLE_ACTUAL_LEN               , 8   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TP_VCS_PFET_ENABLE_ACTUAL_LEN );

REG64_FLD( EQ_PPM_PIG_REQ_INTR_TYPE                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE );
REG64_FLD( EQ_PPM_PIG_REQ_INTR_TYPE_LEN                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE_LEN );
REG64_FLD( EQ_PPM_PIG_REQ_INTR_PAYLOAD                             , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD );
REG64_FLD( EQ_PPM_PIG_REQ_INTR_PAYLOAD_LEN                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD_LEN );
REG64_FLD( EQ_PPM_PIG_GRANTED_PACKET                               , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET );
REG64_FLD( EQ_PPM_PIG_GRANTED_PACKET_LEN                           , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET_LEN );
REG64_FLD( EQ_PPM_PIG_INTR_GRANTED                                 , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INTR_GRANTED );
REG64_FLD( EQ_PPM_PIG_GRANTED_SOURCE                               , 34  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE );
REG64_FLD( EQ_PPM_PIG_GRANTED_SOURCE_LEN                           , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE_LEN );
REG64_FLD( EQ_PPM_PIG_PENDING_SOURCE                               , 37  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE );
REG64_FLD( EQ_PPM_PIG_PENDING_SOURCE_LEN                           , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE_LEN );

REG64_FLD( EX_PPM_PIG_REQ_INTR_TYPE                                , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE );
REG64_FLD( EX_PPM_PIG_REQ_INTR_TYPE_LEN                            , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE_LEN );
REG64_FLD( EX_PPM_PIG_REQ_INTR_PAYLOAD                             , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD );
REG64_FLD( EX_PPM_PIG_REQ_INTR_PAYLOAD_LEN                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD_LEN );
REG64_FLD( EX_PPM_PIG_GRANTED_PACKET                               , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET );
REG64_FLD( EX_PPM_PIG_GRANTED_PACKET_LEN                           , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET_LEN );
REG64_FLD( EX_PPM_PIG_INTR_GRANTED                                 , 32  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INTR_GRANTED );
REG64_FLD( EX_PPM_PIG_GRANTED_SOURCE                               , 34  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE );
REG64_FLD( EX_PPM_PIG_GRANTED_SOURCE_LEN                           , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE_LEN );
REG64_FLD( EX_PPM_PIG_PENDING_SOURCE                               , 37  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE );
REG64_FLD( EX_PPM_PIG_PENDING_SOURCE_LEN                           , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE_LEN );

REG64_FLD( C_PPM_PIG_REQ_INTR_TYPE                                 , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE );
REG64_FLD( C_PPM_PIG_REQ_INTR_TYPE_LEN                             , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_TYPE_LEN );
REG64_FLD( C_PPM_PIG_REQ_INTR_PAYLOAD                              , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD );
REG64_FLD( C_PPM_PIG_REQ_INTR_PAYLOAD_LEN                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_INTR_PAYLOAD_LEN );
REG64_FLD( C_PPM_PIG_GRANTED_PACKET                                , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET );
REG64_FLD( C_PPM_PIG_GRANTED_PACKET_LEN                            , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_PACKET_LEN );
REG64_FLD( C_PPM_PIG_INTR_GRANTED                                  , 32  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INTR_GRANTED );
REG64_FLD( C_PPM_PIG_GRANTED_SOURCE                                , 34  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE );
REG64_FLD( C_PPM_PIG_GRANTED_SOURCE_LEN                            , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_GRANTED_SOURCE_LEN );
REG64_FLD( C_PPM_PIG_PENDING_SOURCE                                , 37  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE );
REG64_FLD( C_PPM_PIG_PENDING_SOURCE_LEN                            , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PENDING_SOURCE_LEN );

REG64_FLD( EQ_PPM_SCRATCH0_DATA                                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_PPM_SCRATCH0_DATA_LEN                                , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_PPM_SCRATCH0_DATA                                    , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_PPM_SCRATCH0_DATA_LEN                                , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( C_PPM_SCRATCH0_DATA                                     , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( C_PPM_SCRATCH0_DATA_LEN                                 , 64  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_PPM_SCRATCH1_DATA                                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EQ_PPM_SCRATCH1_DATA_LEN                                , 64  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EX_PPM_SCRATCH1_DATA                                    , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( EX_PPM_SCRATCH1_DATA_LEN                                , 64  , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( C_PPM_SCRATCH1_DATA                                     , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA       );
REG64_FLD( C_PPM_SCRATCH1_DATA_LEN                                 , 64  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_DATA_LEN   );

REG64_FLD( EQ_PPM_SPWKUP_FSP_FSP_SPECIAL_WKUP                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FSP_SPECIAL_WKUP );

REG64_FLD( EX_PPM_SPWKUP_FSP_FSP_SPECIAL_WKUP                      , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_FSP_SPECIAL_WKUP );

REG64_FLD( C_PPM_SPWKUP_FSP_FSP_SPECIAL_WKUP                       , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FSP_SPECIAL_WKUP );

REG64_FLD( EQ_PPM_SPWKUP_HYP_HYP_SPECIAL_WKUP                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_SPECIAL_WKUP );

REG64_FLD( EX_PPM_SPWKUP_HYP_HYP_SPECIAL_WKUP                      , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_SPECIAL_WKUP );

REG64_FLD( C_PPM_SPWKUP_HYP_HYP_SPECIAL_WKUP                       , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_HYP_SPECIAL_WKUP );

REG64_FLD( EQ_PPM_SPWKUP_OCC_OCC_SPECIAL_WKUP                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_SPECIAL_WKUP );

REG64_FLD( EX_PPM_SPWKUP_OCC_OCC_SPECIAL_WKUP                      , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_SPECIAL_WKUP );

REG64_FLD( C_PPM_SPWKUP_OCC_OCC_SPECIAL_WKUP                       , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_SPECIAL_WKUP );

REG64_FLD( EQ_PPM_SPWKUP_OTR_OTR_SPECIAL_WKUP                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OTR_SPECIAL_WKUP );

REG64_FLD( EX_PPM_SPWKUP_OTR_OTR_SPECIAL_WKUP                      , 0   , SH_UNT_EX       , SH_ACS_SCOM_RW  ,
           SH_FLD_OTR_SPECIAL_WKUP );

REG64_FLD( C_PPM_SPWKUP_OTR_OTR_SPECIAL_WKUP                       , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_OTR_SPECIAL_WKUP );

REG64_FLD( EQ_PPM_SSHFSP_STOP_GATED_FSP                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED_FSP );
REG64_FLD( EQ_PPM_SSHFSP_SPECIAL_WKUP_ACTIVE_FSP                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_FSP );
REG64_FLD( EQ_PPM_SSHFSP_STOP_TRANSITION_FSP                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP );
REG64_FLD( EQ_PPM_SSHFSP_STOP_TRANSITION_FSP_LEN                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP_LEN );
REG64_FLD( EQ_PPM_SSHFSP_REQ_STOP_LEVEL_FSP                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP );
REG64_FLD( EQ_PPM_SSHFSP_REQ_STOP_LEVEL_FSP_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( EQ_PPM_SSHFSP_ACT_STOP_LEVEL_FSP                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP );
REG64_FLD( EQ_PPM_SSHFSP_ACT_STOP_LEVEL_FSP_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP_LEN );
REG64_FLD( EQ_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP                , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP );
REG64_FLD( EQ_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( EQ_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP                , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP );
REG64_FLD( EQ_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP_LEN );

REG64_FLD( EX_PPM_SSHFSP_STOP_GATED_FSP                            , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED_FSP );
REG64_FLD( EX_PPM_SSHFSP_SPECIAL_WKUP_ACTIVE_FSP                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_FSP );
REG64_FLD( EX_PPM_SSHFSP_STOP_TRANSITION_FSP                       , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP );
REG64_FLD( EX_PPM_SSHFSP_STOP_TRANSITION_FSP_LEN                   , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP_LEN );
REG64_FLD( EX_PPM_SSHFSP_REQ_STOP_LEVEL_FSP                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP );
REG64_FLD( EX_PPM_SSHFSP_REQ_STOP_LEVEL_FSP_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( EX_PPM_SSHFSP_ACT_STOP_LEVEL_FSP                        , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP );
REG64_FLD( EX_PPM_SSHFSP_ACT_STOP_LEVEL_FSP_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP_LEN );
REG64_FLD( EX_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP                , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP );
REG64_FLD( EX_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( EX_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP                , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP );
REG64_FLD( EX_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP_LEN );

REG64_FLD( C_PPM_SSHFSP_STOP_GATED_FSP                             , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED_FSP );
REG64_FLD( C_PPM_SSHFSP_SPECIAL_WKUP_ACTIVE_FSP                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_FSP );
REG64_FLD( C_PPM_SSHFSP_STOP_TRANSITION_FSP                        , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP );
REG64_FLD( C_PPM_SSHFSP_STOP_TRANSITION_FSP_LEN                    , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_FSP_LEN );
REG64_FLD( C_PPM_SSHFSP_REQ_STOP_LEVEL_FSP                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP );
REG64_FLD( C_PPM_SSHFSP_REQ_STOP_LEVEL_FSP_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( C_PPM_SSHFSP_ACT_STOP_LEVEL_FSP                         , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP );
REG64_FLD( C_PPM_SSHFSP_ACT_STOP_LEVEL_FSP_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_FSP_LEN );
REG64_FLD( C_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP                 , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP );
REG64_FLD( C_PPM_SSHFSP_DEEPEST_REQ_STOP_LEVEL_FSP_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_FSP_LEN );
REG64_FLD( C_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP                 , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP );
REG64_FLD( C_PPM_SSHFSP_DEEPEST_ACT_STOP_LEVEL_FSP_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_FSP_LEN );

REG64_FLD( EQ_PPM_SSHHYP_RUN_STOP_HYP                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_HYP );
REG64_FLD( EQ_PPM_SSHHYP_SPECIAL_WKUP_ACTIVE_HYP                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_HYP );
REG64_FLD( EQ_PPM_SSHHYP_STOP_TRANSITION_HYP                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP );
REG64_FLD( EQ_PPM_SSHHYP_STOP_TRANSITION_HYP_LEN                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP_LEN );
REG64_FLD( EQ_PPM_SSHHYP_REQ_STOP_LEVEL_HYP                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP );
REG64_FLD( EQ_PPM_SSHHYP_REQ_STOP_LEVEL_HYP_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( EQ_PPM_SSHHYP_ACT_STOP_LEVEL_HYP                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP );
REG64_FLD( EQ_PPM_SSHHYP_ACT_STOP_LEVEL_HYP_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP_LEN );
REG64_FLD( EQ_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP                , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP );
REG64_FLD( EQ_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( EQ_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP                , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP );
REG64_FLD( EQ_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP_LEN );

REG64_FLD( EX_PPM_SSHHYP_RUN_STOP_HYP                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_HYP );
REG64_FLD( EX_PPM_SSHHYP_SPECIAL_WKUP_ACTIVE_HYP                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_HYP );
REG64_FLD( EX_PPM_SSHHYP_STOP_TRANSITION_HYP                       , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP );
REG64_FLD( EX_PPM_SSHHYP_STOP_TRANSITION_HYP_LEN                   , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP_LEN );
REG64_FLD( EX_PPM_SSHHYP_REQ_STOP_LEVEL_HYP                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP );
REG64_FLD( EX_PPM_SSHHYP_REQ_STOP_LEVEL_HYP_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( EX_PPM_SSHHYP_ACT_STOP_LEVEL_HYP                        , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP );
REG64_FLD( EX_PPM_SSHHYP_ACT_STOP_LEVEL_HYP_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP_LEN );
REG64_FLD( EX_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP                , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP );
REG64_FLD( EX_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( EX_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP                , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP );
REG64_FLD( EX_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP_LEN );

REG64_FLD( C_PPM_SSHHYP_RUN_STOP_HYP                               , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_HYP );
REG64_FLD( C_PPM_SSHHYP_SPECIAL_WKUP_ACTIVE_HYP                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_HYP );
REG64_FLD( C_PPM_SSHHYP_STOP_TRANSITION_HYP                        , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP );
REG64_FLD( C_PPM_SSHHYP_STOP_TRANSITION_HYP_LEN                    , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_HYP_LEN );
REG64_FLD( C_PPM_SSHHYP_REQ_STOP_LEVEL_HYP                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP );
REG64_FLD( C_PPM_SSHHYP_REQ_STOP_LEVEL_HYP_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( C_PPM_SSHHYP_ACT_STOP_LEVEL_HYP                         , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP );
REG64_FLD( C_PPM_SSHHYP_ACT_STOP_LEVEL_HYP_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_HYP_LEN );
REG64_FLD( C_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP                 , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP );
REG64_FLD( C_PPM_SSHHYP_DEEPEST_REQ_STOP_LEVEL_HYP_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_HYP_LEN );
REG64_FLD( C_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP                 , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP );
REG64_FLD( C_PPM_SSHHYP_DEEPEST_ACT_STOP_LEVEL_HYP_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_HYP_LEN );

REG64_FLD( EQ_PPM_SSHOCC_RUN_STOP_OCC                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OCC );
REG64_FLD( EQ_PPM_SSHOCC_SPECIAL_WKUP_ACTIVE_OCC                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OCC );
REG64_FLD( EQ_PPM_SSHOCC_STOP_TRANSITION_OCC                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC );
REG64_FLD( EQ_PPM_SSHOCC_STOP_TRANSITION_OCC_LEN                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC_LEN );
REG64_FLD( EQ_PPM_SSHOCC_REQ_STOP_LEVEL_OCC                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC );
REG64_FLD( EQ_PPM_SSHOCC_REQ_STOP_LEVEL_OCC_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( EQ_PPM_SSHOCC_ACT_STOP_LEVEL_OCC                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC );
REG64_FLD( EQ_PPM_SSHOCC_ACT_STOP_LEVEL_OCC_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC_LEN );
REG64_FLD( EQ_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC                , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC );
REG64_FLD( EQ_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( EQ_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC                , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC );
REG64_FLD( EQ_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC_LEN );

REG64_FLD( EX_PPM_SSHOCC_RUN_STOP_OCC                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OCC );
REG64_FLD( EX_PPM_SSHOCC_SPECIAL_WKUP_ACTIVE_OCC                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OCC );
REG64_FLD( EX_PPM_SSHOCC_STOP_TRANSITION_OCC                       , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC );
REG64_FLD( EX_PPM_SSHOCC_STOP_TRANSITION_OCC_LEN                   , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC_LEN );
REG64_FLD( EX_PPM_SSHOCC_REQ_STOP_LEVEL_OCC                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC );
REG64_FLD( EX_PPM_SSHOCC_REQ_STOP_LEVEL_OCC_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( EX_PPM_SSHOCC_ACT_STOP_LEVEL_OCC                        , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC );
REG64_FLD( EX_PPM_SSHOCC_ACT_STOP_LEVEL_OCC_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC_LEN );
REG64_FLD( EX_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC                , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC );
REG64_FLD( EX_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( EX_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC                , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC );
REG64_FLD( EX_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC_LEN );

REG64_FLD( C_PPM_SSHOCC_RUN_STOP_OCC                               , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OCC );
REG64_FLD( C_PPM_SSHOCC_SPECIAL_WKUP_ACTIVE_OCC                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OCC );
REG64_FLD( C_PPM_SSHOCC_STOP_TRANSITION_OCC                        , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC );
REG64_FLD( C_PPM_SSHOCC_STOP_TRANSITION_OCC_LEN                    , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OCC_LEN );
REG64_FLD( C_PPM_SSHOCC_REQ_STOP_LEVEL_OCC                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC );
REG64_FLD( C_PPM_SSHOCC_REQ_STOP_LEVEL_OCC_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( C_PPM_SSHOCC_ACT_STOP_LEVEL_OCC                         , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC );
REG64_FLD( C_PPM_SSHOCC_ACT_STOP_LEVEL_OCC_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OCC_LEN );
REG64_FLD( C_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC                 , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC );
REG64_FLD( C_PPM_SSHOCC_DEEPEST_REQ_STOP_LEVEL_OCC_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OCC_LEN );
REG64_FLD( C_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC                 , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC );
REG64_FLD( C_PPM_SSHOCC_DEEPEST_ACT_STOP_LEVEL_OCC_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OCC_LEN );

REG64_FLD( EQ_PPM_SSHOTR_RUN_STOP_OTR                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OTR );
REG64_FLD( EQ_PPM_SSHOTR_SPECIAL_WKUP_ACTIVE_OTR                   , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OTR );
REG64_FLD( EQ_PPM_SSHOTR_STOP_TRANSITION_OTR                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR );
REG64_FLD( EQ_PPM_SSHOTR_STOP_TRANSITION_OTR_LEN                   , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR_LEN );
REG64_FLD( EQ_PPM_SSHOTR_REQ_STOP_LEVEL_OTR                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR );
REG64_FLD( EQ_PPM_SSHOTR_REQ_STOP_LEVEL_OTR_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( EQ_PPM_SSHOTR_ACT_STOP_LEVEL_OTR                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR );
REG64_FLD( EQ_PPM_SSHOTR_ACT_STOP_LEVEL_OTR_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR_LEN );
REG64_FLD( EQ_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR                , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR );
REG64_FLD( EQ_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( EQ_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR                , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR );
REG64_FLD( EQ_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR_LEN            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR_LEN );

REG64_FLD( EX_PPM_SSHOTR_RUN_STOP_OTR                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OTR );
REG64_FLD( EX_PPM_SSHOTR_SPECIAL_WKUP_ACTIVE_OTR                   , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OTR );
REG64_FLD( EX_PPM_SSHOTR_STOP_TRANSITION_OTR                       , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR );
REG64_FLD( EX_PPM_SSHOTR_STOP_TRANSITION_OTR_LEN                   , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR_LEN );
REG64_FLD( EX_PPM_SSHOTR_REQ_STOP_LEVEL_OTR                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR );
REG64_FLD( EX_PPM_SSHOTR_REQ_STOP_LEVEL_OTR_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( EX_PPM_SSHOTR_ACT_STOP_LEVEL_OTR                        , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR );
REG64_FLD( EX_PPM_SSHOTR_ACT_STOP_LEVEL_OTR_LEN                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR_LEN );
REG64_FLD( EX_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR                , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR );
REG64_FLD( EX_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( EX_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR                , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR );
REG64_FLD( EX_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR_LEN            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR_LEN );

REG64_FLD( C_PPM_SSHOTR_RUN_STOP_OTR                               , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RUN_STOP_OTR );
REG64_FLD( C_PPM_SSHOTR_SPECIAL_WKUP_ACTIVE_OTR                    , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_ACTIVE_OTR );
REG64_FLD( C_PPM_SSHOTR_STOP_TRANSITION_OTR                        , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR );
REG64_FLD( C_PPM_SSHOTR_STOP_TRANSITION_OTR_LEN                    , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_OTR_LEN );
REG64_FLD( C_PPM_SSHOTR_REQ_STOP_LEVEL_OTR                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR );
REG64_FLD( C_PPM_SSHOTR_REQ_STOP_LEVEL_OTR_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( C_PPM_SSHOTR_ACT_STOP_LEVEL_OTR                         , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR );
REG64_FLD( C_PPM_SSHOTR_ACT_STOP_LEVEL_OTR_LEN                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_OTR_LEN );
REG64_FLD( C_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR                 , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR );
REG64_FLD( C_PPM_SSHOTR_DEEPEST_REQ_STOP_LEVEL_OTR_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_REQ_STOP_LEVEL_OTR_LEN );
REG64_FLD( C_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR                 , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR );
REG64_FLD( C_PPM_SSHOTR_DEEPEST_ACT_STOP_LEVEL_OTR_LEN             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DEEPEST_ACT_STOP_LEVEL_OTR_LEN );

REG64_FLD( EQ_PPM_SSHSRC_STOP_GATED                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED );
REG64_FLD( EQ_PPM_SSHSRC_STOP_TRANSITION                           , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION );
REG64_FLD( EQ_PPM_SSHSRC_STOP_TRANSITION_LEN                       , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_LEN );
REG64_FLD( EQ_PPM_SSHSRC_SPECIAL_WKUP_DONE                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_DONE );
REG64_FLD( EQ_PPM_SSHSRC_REQ_STOP_LEVEL                            , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL );
REG64_FLD( EQ_PPM_SSHSRC_REQ_STOP_LEVEL_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_LEN );
REG64_FLD( EQ_PPM_SSHSRC_ACT_STOP_LEVEL                            , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL );
REG64_FLD( EQ_PPM_SSHSRC_ACT_STOP_LEVEL_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_LEN );

REG64_FLD( EX_PPM_SSHSRC_STOP_GATED                                , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED );
REG64_FLD( EX_PPM_SSHSRC_STOP_TRANSITION                           , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION );
REG64_FLD( EX_PPM_SSHSRC_STOP_TRANSITION_LEN                       , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_LEN );
REG64_FLD( EX_PPM_SSHSRC_SPECIAL_WKUP_DONE                         , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_DONE );
REG64_FLD( EX_PPM_SSHSRC_REQ_STOP_LEVEL                            , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL );
REG64_FLD( EX_PPM_SSHSRC_REQ_STOP_LEVEL_LEN                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_LEN );
REG64_FLD( EX_PPM_SSHSRC_ACT_STOP_LEVEL                            , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL );
REG64_FLD( EX_PPM_SSHSRC_ACT_STOP_LEVEL_LEN                        , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_LEN );

REG64_FLD( C_PPM_SSHSRC_STOP_GATED                                 , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_GATED );
REG64_FLD( C_PPM_SSHSRC_STOP_TRANSITION                            , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION );
REG64_FLD( C_PPM_SSHSRC_STOP_TRANSITION_LEN                        , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_STOP_TRANSITION_LEN );
REG64_FLD( C_PPM_SSHSRC_SPECIAL_WKUP_DONE                          , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPECIAL_WKUP_DONE );
REG64_FLD( C_PPM_SSHSRC_REQ_STOP_LEVEL                             , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL );
REG64_FLD( C_PPM_SSHSRC_REQ_STOP_LEVEL_LEN                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REQ_STOP_LEVEL_LEN );
REG64_FLD( C_PPM_SSHSRC_ACT_STOP_LEVEL                             , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL );
REG64_FLD( C_PPM_SSHSRC_ACT_STOP_LEVEL_LEN                         , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ACT_STOP_LEVEL_LEN );

REG64_FLD( EQ_PPM_VDMCR_VDM_POWERON                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_POWERON );
REG64_FLD( EQ_PPM_VDMCR_VDM_DISABLE                                , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_DISABLE );

REG64_FLD( EX_PPM_VDMCR_VDM_POWERON                                , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_POWERON );
REG64_FLD( EX_PPM_VDMCR_VDM_DISABLE                                , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_DISABLE );

REG64_FLD( C_PPM_VDMCR_VDM_POWERON                                 , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_POWERON );
REG64_FLD( C_PPM_VDMCR_VDM_DISABLE                                 , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_VDM_DISABLE );

REG64_FLD( EQ_PRD_PURGE_CMD_REG_TRIGGER                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER    );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_TYPE                               , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_TYPE_LEN                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_BUSY                               , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS                 , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY_ON_THIS );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_PRGSM_BUSY                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_MEM                                , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_MEM_LEN                            , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_CGC                                , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CGC        );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_CGC_LEN                            , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CGC_LEN    );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_BANK                               , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BANK       );
REG64_FLD( EQ_PRD_PURGE_CMD_REG_ERR                                , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERR        );

REG64_FLD( EX_PRD_PURGE_CMD_REG_TRIGGER                            , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER    );
REG64_FLD( EX_PRD_PURGE_CMD_REG_TYPE                               , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE       );
REG64_FLD( EX_PRD_PURGE_CMD_REG_TYPE_LEN                           , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TYPE_LEN   );
REG64_FLD( EX_PRD_PURGE_CMD_REG_BUSY                               , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BUSY       );
REG64_FLD( EX_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS                 , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY_ON_THIS );
REG64_FLD( EX_PRD_PURGE_CMD_REG_PRGSM_BUSY                         , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PRGSM_BUSY );
REG64_FLD( EX_PRD_PURGE_CMD_REG_MEM                                , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MEM        );
REG64_FLD( EX_PRD_PURGE_CMD_REG_MEM_LEN                            , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MEM_LEN    );
REG64_FLD( EX_PRD_PURGE_CMD_REG_CGC                                , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CGC        );
REG64_FLD( EX_PRD_PURGE_CMD_REG_CGC_LEN                            , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CGC_LEN    );
REG64_FLD( EX_PRD_PURGE_CMD_REG_BANK                               , 28  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BANK       );
REG64_FLD( EX_PRD_PURGE_CMD_REG_ERR                                , 29  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERR        );

REG64_FLD( EQ_PRD_PURGE_REG_L3_REQ                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EQ_PRD_PURGE_REG_L3_TTYPE                               , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE   );
REG64_FLD( EQ_PRD_PURGE_REG_L3_TTYPE_LEN                           , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE_LEN );
REG64_FLD( EQ_PRD_PURGE_REG_L3_LINE_DEL_ON_NEXT_CE                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_NEXT_CE );
REG64_FLD( EQ_PRD_PURGE_REG_L3_LINE_DEL_ON_ALL_CE                  , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_ALL_CE );
REG64_FLD( EQ_PRD_PURGE_REG_L3_BUSY_ERR                            , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EQ_PRD_PURGE_REG_L3_MEMBER                              , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER  );
REG64_FLD( EQ_PRD_PURGE_REG_L3_MEMBER_LEN                          , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER_LEN );
REG64_FLD( EQ_PRD_PURGE_REG_L3_DIR_ADDR                            , 17  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR );
REG64_FLD( EQ_PRD_PURGE_REG_L3_DIR_ADDR_LEN                        , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR_LEN );

REG64_FLD( EX_PRD_PURGE_REG_L3_REQ                                 , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_REQ     );
REG64_FLD( EX_PRD_PURGE_REG_L3_TTYPE                               , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE   );
REG64_FLD( EX_PRD_PURGE_REG_L3_TTYPE_LEN                           , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_TTYPE_LEN );
REG64_FLD( EX_PRD_PURGE_REG_L3_LINE_DEL_ON_NEXT_CE                 , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_NEXT_CE );
REG64_FLD( EX_PRD_PURGE_REG_L3_LINE_DEL_ON_ALL_CE                  , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_LINE_DEL_ON_ALL_CE );
REG64_FLD( EX_PRD_PURGE_REG_L3_BUSY_ERR                            , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_BUSY_ERR );
REG64_FLD( EX_PRD_PURGE_REG_L3_MEMBER                              , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER  );
REG64_FLD( EX_PRD_PURGE_REG_L3_MEMBER_LEN                          , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_MEMBER_LEN );
REG64_FLD( EX_PRD_PURGE_REG_L3_DIR_ADDR                            , 17  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR );
REG64_FLD( EX_PRD_PURGE_REG_L3_DIR_ADDR_LEN                        , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_L3_DIR_ADDR_LEN );

REG64_FLD( EQ_PRE_COUNTER_REG_COUNTER                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_COUNTER    );
REG64_FLD( EQ_PRE_COUNTER_REG_COUNTER_LEN                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_COUNTER_LEN );

REG64_FLD( EX_PRE_COUNTER_REG_COUNTER                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_COUNTER    );
REG64_FLD( EX_PRE_COUNTER_REG_COUNTER_LEN                          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_COUNTER_LEN );

REG64_FLD( C_PRE_COUNTER_REG_COUNTER                               , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_COUNTER    );
REG64_FLD( C_PRE_COUNTER_REG_COUNTER_LEN                           , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_COUNTER_LEN );

REG64_FLD( EQ_PROTECT_MODE_REG_READ_ENABLE                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EQ_PROTECT_MODE_REG_WRITE_ENABLE                        , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( EX_PROTECT_MODE_REG_READ_ENABLE                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( EX_PROTECT_MODE_REG_WRITE_ENABLE                        , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( C_PROTECT_MODE_REG_READ_ENABLE                          , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_READ_ENABLE );
REG64_FLD( C_PROTECT_MODE_REG_WRITE_ENABLE                         , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WRITE_ENABLE );

REG64_FLD( CAPP_PSLTTMAP0_VALID                                    , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );
REG64_FLD( CAPP_PSLTTMAP0_TTYPE_MATCH                              , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH );
REG64_FLD( CAPP_PSLTTMAP0_TTYPE_MATCH_LEN                          , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP0_TSIZE_MATCH                              , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH );
REG64_FLD( CAPP_PSLTTMAP0_TSIZE_MATCH_LEN                          , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP0_TSIZE_MASK                               , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK );
REG64_FLD( CAPP_PSLTTMAP0_TSIZE_MASK_LEN                           , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK_LEN );
REG64_FLD( CAPP_PSLTTMAP0_TTYPE_REPLACE                            , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE );
REG64_FLD( CAPP_PSLTTMAP0_TTYPE_REPLACE_LEN                        , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE_LEN );

REG64_FLD( CAPP_PSLTTMAP1_VALID                                    , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );
REG64_FLD( CAPP_PSLTTMAP1_TTYPE_MATCH                              , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH );
REG64_FLD( CAPP_PSLTTMAP1_TTYPE_MATCH_LEN                          , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP1_TSIZE_MATCH                              , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH );
REG64_FLD( CAPP_PSLTTMAP1_TSIZE_MATCH_LEN                          , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP1_TSIZE_MASK                               , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK );
REG64_FLD( CAPP_PSLTTMAP1_TSIZE_MASK_LEN                           , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK_LEN );
REG64_FLD( CAPP_PSLTTMAP1_TTYPE_REPLACE                            , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE );
REG64_FLD( CAPP_PSLTTMAP1_TTYPE_REPLACE_LEN                        , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE_LEN );

REG64_FLD( CAPP_PSLTTMAP2_VALID                                    , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );
REG64_FLD( CAPP_PSLTTMAP2_TTYPE_MATCH                              , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH );
REG64_FLD( CAPP_PSLTTMAP2_TTYPE_MATCH_LEN                          , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP2_TSIZE_MATCH                              , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH );
REG64_FLD( CAPP_PSLTTMAP2_TSIZE_MATCH_LEN                          , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP2_TSIZE_MASK                               , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK );
REG64_FLD( CAPP_PSLTTMAP2_TSIZE_MASK_LEN                           , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK_LEN );
REG64_FLD( CAPP_PSLTTMAP2_TTYPE_REPLACE                            , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE );
REG64_FLD( CAPP_PSLTTMAP2_TTYPE_REPLACE_LEN                        , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE_LEN );

REG64_FLD( CAPP_PSLTTMAP3_VALID                                    , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_VALID      );
REG64_FLD( CAPP_PSLTTMAP3_TTYPE_MATCH                              , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH );
REG64_FLD( CAPP_PSLTTMAP3_TTYPE_MATCH_LEN                          , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP3_TSIZE_MATCH                              , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH );
REG64_FLD( CAPP_PSLTTMAP3_TSIZE_MATCH_LEN                          , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MATCH_LEN );
REG64_FLD( CAPP_PSLTTMAP3_TSIZE_MASK                               , 13  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK );
REG64_FLD( CAPP_PSLTTMAP3_TSIZE_MASK_LEN                           , 7   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TSIZE_MASK_LEN );
REG64_FLD( CAPP_PSLTTMAP3_TTYPE_REPLACE                            , 20  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE );
REG64_FLD( CAPP_PSLTTMAP3_TTYPE_REPLACE_LEN                        , 6   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TTYPE_REPLACE_LEN );

REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_32                            , 32  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_32 );
REG64_FLD( EX_L2_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD                 , 33  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_A_THRESHOLD );
REG64_FLD( EX_L2_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN             , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_A_THRESHOLD_LEN );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_40                            , 40  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_40 );
REG64_FLD( EX_L2_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD                 , 41  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_B_THRESHOLD );
REG64_FLD( EX_L2_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN             , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_B_THRESHOLD_LEN );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_48                            , 48  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_48 );
REG64_FLD( EX_L2_PWM_EVENTS_PSTATE_A_THRESHOLD                     , 49  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_A_THRESHOLD );
REG64_FLD( EX_L2_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN                 , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_A_THRESHOLD_LEN );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_52                            , 52  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_52 );
REG64_FLD( EX_L2_PWM_EVENTS_PSTATE_B_THRESHOLD                     , 53  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_B_THRESHOLD );
REG64_FLD( EX_L2_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN                 , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_B_THRESHOLD_LEN );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_56                            , 56  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_56 );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_57                            , 57  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_57 );
REG64_FLD( EX_L2_PWM_EVENTS_EVENT_MUX_SELECTS                      , 58  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_EVENT_MUX_SELECTS );
REG64_FLD( EX_L2_PWM_EVENTS_EVENT_MUX_SELECTS_LEN                  , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_EVENT_MUX_SELECTS_LEN );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_60                            , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_60 );
REG64_FLD( EX_L2_PWM_EVENTS_RESERVED_61                            , 61  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_61 );
REG64_FLD( EX_L2_PWM_EVENTS_PMCM_THRESHOLD                         , 62  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PMCM_THRESHOLD );
REG64_FLD( EX_L2_PWM_EVENTS_PMCM_THRESHOLD_LEN                     , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_PMCM_THRESHOLD_LEN );

REG64_FLD( C_PWM_EVENTS_RESERVED_32                                , 32  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_32 );
REG64_FLD( C_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD                     , 33  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_A_THRESHOLD );
REG64_FLD( C_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN                 , 7   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_A_THRESHOLD_LEN );
REG64_FLD( C_PWM_EVENTS_RESERVED_40                                , 40  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_40 );
REG64_FLD( C_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD                     , 41  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_B_THRESHOLD );
REG64_FLD( C_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN                 , 7   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_SCALE_B_THRESHOLD_LEN );
REG64_FLD( C_PWM_EVENTS_RESERVED_48                                , 48  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_48 );
REG64_FLD( C_PWM_EVENTS_PSTATE_A_THRESHOLD                         , 49  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_A_THRESHOLD );
REG64_FLD( C_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN                     , 3   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_A_THRESHOLD_LEN );
REG64_FLD( C_PWM_EVENTS_RESERVED_52                                , 52  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_52 );
REG64_FLD( C_PWM_EVENTS_PSTATE_B_THRESHOLD                         , 53  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_B_THRESHOLD );
REG64_FLD( C_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN                     , 3   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PSTATE_B_THRESHOLD_LEN );
REG64_FLD( C_PWM_EVENTS_RESERVED_56                                , 56  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_56 );
REG64_FLD( C_PWM_EVENTS_RESERVED_57                                , 57  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_57 );
REG64_FLD( C_PWM_EVENTS_EVENT_MUX_SELECTS                          , 58  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_EVENT_MUX_SELECTS );
REG64_FLD( C_PWM_EVENTS_EVENT_MUX_SELECTS_LEN                      , 2   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_EVENT_MUX_SELECTS_LEN );
REG64_FLD( C_PWM_EVENTS_RESERVED_60                                , 60  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_60 );
REG64_FLD( C_PWM_EVENTS_RESERVED_61                                , 61  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_61 );
REG64_FLD( C_PWM_EVENTS_PMCM_THRESHOLD                             , 62  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PMCM_THRESHOLD );
REG64_FLD( C_PWM_EVENTS_PMCM_THRESHOLD_LEN                         , 2   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_PMCM_THRESHOLD_LEN );

REG64_FLD( EQ_QPPM_DPLL_CTRL_LOCK_SEL                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_LOCK_SEL   );
REG64_FLD( EQ_QPPM_DPLL_CTRL_DYNAMIC_FILTER_ENABLE                 , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DYNAMIC_FILTER_ENABLE );
REG64_FLD( EQ_QPPM_DPLL_CTRL_FF_BYPASS                             , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FF_BYPASS  );
REG64_FLD( EQ_QPPM_DPLL_CTRL_DCO_OVERRIDE                          , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DCO_OVERRIDE );
REG64_FLD( EQ_QPPM_DPLL_CTRL_DCO_INCR                              , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DCO_INCR   );
REG64_FLD( EQ_QPPM_DPLL_CTRL_DCO_DECR                              , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_DCO_DECR   );
REG64_FLD( EQ_QPPM_DPLL_CTRL_FF_SLEWRATE                           , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FF_SLEWRATE );
REG64_FLD( EQ_QPPM_DPLL_CTRL_FF_SLEWRATE_LEN                       , 10  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_FF_SLEWRATE_LEN );
REG64_FLD( EQ_QPPM_DPLL_CTRL_SS_ENABLE                             , 16  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_SS_ENABLE  );
REG64_FLD( EQ_QPPM_DPLL_CTRL_RESERVED_17_19                        , 17  , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_17_19 );
REG64_FLD( EQ_QPPM_DPLL_CTRL_RESERVED_17_19_LEN                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_RESERVED_17_19_LEN );

REG64_FLD( EQ_QPPM_DPLL_FREQ_FMAX                                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FMAX       );
REG64_FLD( EQ_QPPM_DPLL_FREQ_FMAX_LEN                              , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FMAX_LEN   );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_FMAX                            , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_FMAX );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_FMAX_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_FMAX_LEN );
REG64_FLD( EQ_QPPM_DPLL_FREQ_FREQ_MULT                             , 17  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_MULT  );
REG64_FLD( EQ_QPPM_DPLL_FREQ_FREQ_MULT_LEN                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQ_MULT_LEN );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_MULT                            , 28  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_MULT );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_MULT_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_MULT_LEN );
REG64_FLD( EQ_QPPM_DPLL_FREQ_FMIN                                  , 33  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FMIN       );
REG64_FLD( EQ_QPPM_DPLL_FREQ_FMIN_LEN                              , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_FMIN_LEN   );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_FMIN                            , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_FMIN );
REG64_FLD( EQ_QPPM_DPLL_FREQ_HIRES_FMIN_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_HIRES_FMIN_LEN );

REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_AVG                           , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_AVG );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_AVG_LEN                       , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_AVG_LEN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_AVG                     , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_AVG );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_AVG_LEN                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_AVG_LEN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_MAX                           , 21  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_MAX );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_MAX_LEN                       , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_MAX_LEN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_MAX                     , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_MAX );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_MAX_LEN                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_MAX_LEN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_MIN                           , 41  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_MIN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_FREQIN_MIN_LEN                       , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQIN_MIN_LEN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_MIN                     , 52  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_MIN );
REG64_FLD( EQ_QPPM_DPLL_ICHAR_HIRES_FREQIN_MIN_LEN                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQIN_MIN_LEN );

REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_MAX                          , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_MAX );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_MAX_LEN                      , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_MAX_LEN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_MAX                    , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_MAX );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_MAX_LEN                , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_MAX_LEN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_AVG                          , 21  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_AVG );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_AVG_LEN                      , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_AVG_LEN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_AVG                    , 32  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_AVG );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_AVG_LEN                , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_AVG_LEN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_MIN                          , 41  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_MIN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_FREQOUT_MIN_LEN                      , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_MIN_LEN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_MIN                    , 52  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_MIN );
REG64_FLD( EQ_QPPM_DPLL_OCHAR_HIRES_FREQOUT_MIN_LEN                , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_MIN_LEN );

REG64_FLD( EQ_QPPM_DPLL_STAT_FREQOUT                               , 1   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT    );
REG64_FLD( EQ_QPPM_DPLL_STAT_FREQOUT_LEN                           , 11  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQOUT_LEN );
REG64_FLD( EQ_QPPM_DPLL_STAT_HIRES_FREQOUT                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT );
REG64_FLD( EQ_QPPM_DPLL_STAT_HIRES_FREQOUT_LEN                     , 5   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_HIRES_FREQOUT_LEN );
REG64_FLD( EQ_QPPM_DPLL_STAT_RESERVED_57_60                        , 57  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_RESERVED_57_60 );
REG64_FLD( EQ_QPPM_DPLL_STAT_RESERVED_57_60_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_RESERVED_57_60_LEN );
REG64_FLD( EQ_QPPM_DPLL_STAT_FSAFE_ACTIVE                          , 61  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FSAFE_ACTIVE );
REG64_FLD( EQ_QPPM_DPLL_STAT_FREQ_CHANGE                           , 62  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_FREQ_CHANGE );
REG64_FLD( EQ_QPPM_DPLL_STAT_LOCK                                  , 63  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_LOCK       );

REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX0_ENABLE                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX0_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX0_VWL_ENABLE                    , 1   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX0_VWL_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX0_VROW_VBLH_ENABLE              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX0_VROW_VBLH_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX0_VPP_ENABLE                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX0_VPP_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX1_ENABLE                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX1_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX1_VWL_ENABLE                    , 5   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX1_VWL_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX1_VROW_VBLH_ENABLE              , 6   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX1_VROW_VBLH_ENABLE );
REG64_FLD( EQ_QPPM_EDRAM_CTRL_L3_EX1_VPP_ENABLE                    , 7   , SH_UNT_EQ       , SH_ACS_SCOM2_OR ,
           SH_FLD_L3_EX1_VPP_ENABLE );

REG64_FLD( EQ_QPPM_ERR_PCB_INTERRUPT_PROTOCOL                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_PCB_INTERRUPT_PROTOCOL );
REG64_FLD( EQ_QPPM_ERR_SPECIAL_WKUP_PROTOCOL                       , 1   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_SPECIAL_WKUP_PROTOCOL );
REG64_FLD( EQ_QPPM_ERR_PFET_SEQ_PROGRAM                            , 2   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_PFET_SEQ_PROGRAM );
REG64_FLD( EQ_QPPM_ERR_OCC_HEARTBEAT_LOSS                          , 3   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_OCC_HEARTBEAT_LOSS );
REG64_FLD( EQ_QPPM_ERR_L2_EX0_CLK_SYNC                             , 4   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_L2_EX0_CLK_SYNC );
REG64_FLD( EQ_QPPM_ERR_L2_EX1_CLK_SYNC                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_L2_EX1_CLK_SYNC );
REG64_FLD( EQ_QPPM_ERR_SPARE_6_7                                   , 6   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_SPARE_6_7  );
REG64_FLD( EQ_QPPM_ERR_SPARE_6_7_LEN                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_SPARE_6_7_LEN );
REG64_FLD( EQ_QPPM_ERR_DPLL_INT                                    , 8   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_DPLL_INT   );
REG64_FLD( EQ_QPPM_ERR_DPLL_DYN_FMIN                               , 9   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_DPLL_DYN_FMIN );
REG64_FLD( EQ_QPPM_ERR_DPLL_DCO_FULL                               , 10  , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_DPLL_DCO_FULL );
REG64_FLD( EQ_QPPM_ERR_DPLL_DCO_EMPTY                              , 11  , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_DPLL_DCO_EMPTY );

REG64_FLD( EQ_QPPM_ERRMSK_RESERVED_0_11                            , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_11 );
REG64_FLD( EQ_QPPM_ERRMSK_RESERVED_0_11_LEN                        , 12  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_RESERVED_0_11_LEN );

REG64_FLD( EQ_QPPM_ERRSUM_PM_ERROR                                 , 0   , SH_UNT_EQ       , SH_ACS_SCOM_WCLRPART,
           SH_FLD_PM_ERROR   );

REG64_FLD( EQ_QPPM_OCCHB_OCC_HEARTBEAT_COUNT                       , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_HEARTBEAT_COUNT );
REG64_FLD( EQ_QPPM_OCCHB_OCC_HEARTBEAT_COUNT_LEN                   , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_HEARTBEAT_COUNT_LEN );
REG64_FLD( EQ_QPPM_OCCHB_OCC_HEARTBEAT_ENABLE                      , 16  , SH_UNT_EQ       , SH_ACS_SCOM_RW  ,
           SH_FLD_OCC_HEARTBEAT_ENABLE );

REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_STRENGTH                      , 0   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_STRENGTH );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_STRENGTH_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_STRENGTH_LEN );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_SPARE                         , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_SPARE );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_PULSE_MODE_EN                 , 5   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_PULSE_MODE                    , 6   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_PULSE_MODE );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SB_PULSE_MODE_LEN                , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SW_RESCLK                        , 8   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SW_RESCLK );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SW_RESCLK_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SW_RESCLK_LEN );
REG64_FLD( EQ_QPPM_QACCR_CORE_CLK_SW_SPARE                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CORE_CLK_SW_SPARE );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SYNC_ENABLE                    , 13  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SYNC_ENABLE );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_14_15                            , 14  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_14_15 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_14_15_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_14_15_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLKGLM_ASYNC_RESET                 , 16  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLKGLM_ASYNC_RESET );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_17_18                            , 17  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_17_18 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_17_18_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_17_18_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLKGLM_SEL                         , 19  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLKGLM_SEL );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_STRENGTH                    , 20  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_STRENGTH );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_STRENGTH_LEN                , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_STRENGTH_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_SPARE0                      , 24  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_SPARE0 );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_PULSE_MODE_EN               , 25  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_PULSE_MODE                  , 26  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_PULSE_MODE );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SB_PULSE_MODE_LEN              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SW_RESCLK                      , 28  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SW_RESCLK );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SW_RESCLK_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SW_RESCLK_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX0_CLK_SW_SPARE1                      , 32  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX0_CLK_SW_SPARE1 );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SYNC_ENABLE                    , 33  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SYNC_ENABLE );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_34_35                            , 34  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_34_35 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_34_35_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_34_35_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLKGLM_ASYNC_RESET                 , 36  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLKGLM_ASYNC_RESET );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_37_38                            , 37  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_37_38 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_37_38_LEN                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_37_38_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLKGLM_SEL                         , 39  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLKGLM_SEL );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_STRENGTH                    , 40  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_STRENGTH );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_STRENGTH_LEN                , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_STRENGTH_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_SPARE0                      , 44  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_SPARE0 );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_PULSE_MODE_EN               , 45  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_PULSE_MODE                  , 46  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_PULSE_MODE );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SB_PULSE_MODE_LEN              , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SB_PULSE_MODE_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SW_RESCLK                      , 48  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SW_RESCLK );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SW_RESCLK_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SW_RESCLK_LEN );
REG64_FLD( EQ_QPPM_QACCR_L2_EX1_CLK_SW_SPARE1                      , 52  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L2_EX1_CLK_SW_SPARE1 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_53_55                            , 53  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_53_55 );
REG64_FLD( EQ_QPPM_QACCR_RESERVED_53_55_LEN                        , 3   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED_53_55_LEN );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_STRENGTH                        , 56  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_STRENGTH );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_STRENGTH_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_STRENGTH_LEN );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_SPARE0                          , 60  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_SPARE0 );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_PULSE_MODE_EN                   , 61  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_PULSE_MODE_EN );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_PULSE_MODE                      , 62  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_PULSE_MODE );
REG64_FLD( EQ_QPPM_QACCR_L3_CLK_SB_PULSE_MODE_LEN                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_L3_CLK_SB_PULSE_MODE_LEN );

REG64_FLD( EQ_QPPM_QACSR_L2_EX0_CLK_SYNC_DONE                      , 62  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_L2_EX0_CLK_SYNC_DONE );
REG64_FLD( EQ_QPPM_QACSR_L2_EX1_CLK_SYNC_DONE                      , 63  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_L2_EX1_CLK_SYNC_DONE );

REG64_FLD( EQ_QPPM_QPMMR_FSAFE                                     , 1   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_FSAFE      );
REG64_FLD( EQ_QPPM_QPMMR_FSAFE_LEN                                 , 11  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_FSAFE_LEN  );
REG64_FLD( EQ_QPPM_QPMMR_ENABLE_FSAFE_UPON_HEARTBEAT_LOSS          , 12  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_ENABLE_FSAFE_UPON_HEARTBEAT_LOSS );
REG64_FLD( EQ_QPPM_QPMMR_RESERVED13_15                             , 13  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED13_15 );
REG64_FLD( EQ_QPPM_QPMMR_RESERVED13_15_LEN                         , 3   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED13_15_LEN );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_IVRM_ENABLE                  , 20  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_IVRM_ENABLE );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_IVRM_SEL                     , 21  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_IVRM_SEL );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_ACLK_ENABLE                  , 22  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_ACLK_ENABLE );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_ACLK_SEL                     , 23  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_ACLK_SEL );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_VDM_ENABLE                   , 24  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_VDM_ENABLE );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_VDM_SEL                      , 25  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_VDM_SEL );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_DPLL_ENABLE                  , 26  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_DPLL_ENABLE );
REG64_FLD( EQ_QPPM_QPMMR_CME_INTERPPM_DPLL_SEL                     , 27  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_CME_INTERPPM_DPLL_SEL );
REG64_FLD( EQ_QPPM_QPMMR_RESERVED28_29                             , 28  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED28_29 );
REG64_FLD( EQ_QPPM_QPMMR_RESERVED28_29_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_RESERVED28_29_LEN );
REG64_FLD( EQ_QPPM_QPMMR_PB_PURGE_PLS                              , 30  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PB_PURGE_PLS );
REG64_FLD( EQ_QPPM_QPMMR_PB_PURGE_DONE_LVL                         , 31  , SH_UNT_EQ       , SH_ACS_SCOM2    ,
           SH_FLD_PB_PURGE_DONE_LVL );

REG64_FLD( EQ_QPPM_VDMCFGR_VDM_VID_COMPARE                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_VID_COMPARE );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_VID_COMPARE_LEN                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_VID_COMPARE_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_OVERVOLT                            , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_OVERVOLT );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_OVERVOLT_LEN                        , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_OVERVOLT_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_SMALL                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_SMALL );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_SMALL_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_SMALL_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_LARGE                         , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_LARGE );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_LARGE_LEN                     , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_LARGE_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_XTREME                        , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_XTREME );
REG64_FLD( EQ_QPPM_VDMCFGR_VDM_DROOP_XTREME_LEN                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VDM_DROOP_XTREME_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VID_COMPARE_MAX                         , 32  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VID_COMPARE_MAX );
REG64_FLD( EQ_QPPM_VDMCFGR_VID_COMPARE_MAX_LEN                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VID_COMPARE_MAX_LEN );
REG64_FLD( EQ_QPPM_VDMCFGR_VID_COMPARE_MIN                         , 40  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VID_COMPARE_MIN );
REG64_FLD( EQ_QPPM_VDMCFGR_VID_COMPARE_MIN_LEN                     , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VID_COMPARE_MIN_LEN );

REG64_FLD( EQ_RD_EPS_REG_TIER0_VALUE                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER0_VALUE );
REG64_FLD( EQ_RD_EPS_REG_TIER0_VALUE_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER0_VALUE_LEN );
REG64_FLD( EQ_RD_EPS_REG_TIER1_VALUE                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE );
REG64_FLD( EQ_RD_EPS_REG_TIER1_VALUE_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE_LEN );
REG64_FLD( EQ_RD_EPS_REG_TIER2_VALUE                               , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE );
REG64_FLD( EQ_RD_EPS_REG_TIER2_VALUE_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE_LEN );

REG64_FLD( EX_L2_RD_EPS_REG_TIER0_VALUE                            , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER0_VALUE );
REG64_FLD( EX_L2_RD_EPS_REG_TIER0_VALUE_LEN                        , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER0_VALUE_LEN );
REG64_FLD( EX_L2_RD_EPS_REG_TIER1_VALUE                            , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE );
REG64_FLD( EX_L2_RD_EPS_REG_TIER1_VALUE_LEN                        , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE_LEN );
REG64_FLD( EX_L2_RD_EPS_REG_TIER2_VALUE                            , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE );
REG64_FLD( EX_L2_RD_EPS_REG_TIER2_VALUE_LEN                        , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE_LEN );

REG64_FLD( EQ_SCAN_REGION_TYPE_SYSTEM_FAST_INIT                    , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM_FAST_INIT );
REG64_FLD( EQ_SCAN_REGION_TYPE_VITL                                , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_VITL       );
REG64_FLD( EQ_SCAN_REGION_TYPE_PERV                                , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT1                               , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT2                               , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT3                               , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT4                               , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT5                               , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT6                               , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT7                               , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT8                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT9                               , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EQ_SCAN_REGION_TYPE_UNIT10                              , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EQ_SCAN_REGION_TYPE_FUNC                                , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FUNC       );
REG64_FLD( EQ_SCAN_REGION_TYPE_CFG                                 , 49  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG        );
REG64_FLD( EQ_SCAN_REGION_TYPE_CCFG_GPTR                           , 50  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CCFG_GPTR  );
REG64_FLD( EQ_SCAN_REGION_TYPE_REGF                                , 51  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REGF       );
REG64_FLD( EQ_SCAN_REGION_TYPE_LBIST                               , 52  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LBIST      );
REG64_FLD( EQ_SCAN_REGION_TYPE_ABIST                               , 53  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ABIST      );
REG64_FLD( EQ_SCAN_REGION_TYPE_REPR                                , 54  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_REPR       );
REG64_FLD( EQ_SCAN_REGION_TYPE_TIME                                , 55  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIME       );
REG64_FLD( EQ_SCAN_REGION_TYPE_BNDY                                , 56  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_BNDY       );
REG64_FLD( EQ_SCAN_REGION_TYPE_FARR                                , 57  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FARR       );
REG64_FLD( EQ_SCAN_REGION_TYPE_CMSK                                , 58  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CMSK       );
REG64_FLD( EQ_SCAN_REGION_TYPE_INEX                                , 59  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_INEX       );

REG64_FLD( EX_SCAN_REGION_TYPE_SYSTEM_FAST_INIT                    , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM_FAST_INIT );
REG64_FLD( EX_SCAN_REGION_TYPE_VITL                                , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_VITL       );
REG64_FLD( EX_SCAN_REGION_TYPE_PERV                                , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT1                               , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT2                               , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT3                               , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT4                               , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT5                               , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT6                               , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT7                               , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT8                               , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT9                               , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EX_SCAN_REGION_TYPE_UNIT10                              , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EX_SCAN_REGION_TYPE_FUNC                                , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FUNC       );
REG64_FLD( EX_SCAN_REGION_TYPE_CFG                                 , 49  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG        );
REG64_FLD( EX_SCAN_REGION_TYPE_CCFG_GPTR                           , 50  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CCFG_GPTR  );
REG64_FLD( EX_SCAN_REGION_TYPE_REGF                                , 51  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REGF       );
REG64_FLD( EX_SCAN_REGION_TYPE_LBIST                               , 52  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LBIST      );
REG64_FLD( EX_SCAN_REGION_TYPE_ABIST                               , 53  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ABIST      );
REG64_FLD( EX_SCAN_REGION_TYPE_REPR                                , 54  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_REPR       );
REG64_FLD( EX_SCAN_REGION_TYPE_TIME                                , 55  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TIME       );
REG64_FLD( EX_SCAN_REGION_TYPE_BNDY                                , 56  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_BNDY       );
REG64_FLD( EX_SCAN_REGION_TYPE_FARR                                , 57  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FARR       );
REG64_FLD( EX_SCAN_REGION_TYPE_CMSK                                , 58  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CMSK       );
REG64_FLD( EX_SCAN_REGION_TYPE_INEX                                , 59  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_INEX       );

REG64_FLD( C_SCAN_REGION_TYPE_SYSTEM_FAST_INIT                     , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SYSTEM_FAST_INIT );
REG64_FLD( C_SCAN_REGION_TYPE_VITL                                 , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_VITL       );
REG64_FLD( C_SCAN_REGION_TYPE_PERV                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT1                                , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT2                                , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT3                                , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT4                                , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT5                                , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT6                                , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT7                                , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT8                                , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT9                                , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( C_SCAN_REGION_TYPE_UNIT10                               , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( C_SCAN_REGION_TYPE_FUNC                                 , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FUNC       );
REG64_FLD( C_SCAN_REGION_TYPE_CFG                                  , 49  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG        );
REG64_FLD( C_SCAN_REGION_TYPE_CCFG_GPTR                            , 50  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CCFG_GPTR  );
REG64_FLD( C_SCAN_REGION_TYPE_REGF                                 , 51  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REGF       );
REG64_FLD( C_SCAN_REGION_TYPE_LBIST                                , 52  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LBIST      );
REG64_FLD( C_SCAN_REGION_TYPE_ABIST                                , 53  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ABIST      );
REG64_FLD( C_SCAN_REGION_TYPE_REPR                                 , 54  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_REPR       );
REG64_FLD( C_SCAN_REGION_TYPE_TIME                                 , 55  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TIME       );
REG64_FLD( C_SCAN_REGION_TYPE_BNDY                                 , 56  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_BNDY       );
REG64_FLD( C_SCAN_REGION_TYPE_FARR                                 , 57  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FARR       );
REG64_FLD( C_SCAN_REGION_TYPE_CMSK                                 , 58  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CMSK       );
REG64_FLD( C_SCAN_REGION_TYPE_INEX                                 , 59  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_INEX       );

REG64_FLD( EX_L2_SCOMC_MODE                                        , 54  , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( EX_L2_SCOMC_MODE_LEN                                    , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE_LEN   );

REG64_FLD( C_SCOMC_MODE                                            , 54  , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE       );
REG64_FLD( C_SCOMC_MODE_LEN                                        , 7   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_MODE_LEN   );

REG64_FLD( EQ_SKITTER_CLKSRC_REG_SKITTER0                          , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0   );
REG64_FLD( EQ_SKITTER_CLKSRC_REG_SKITTER0_LEN                      , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0_LEN );

REG64_FLD( EX_SKITTER_CLKSRC_REG_SKITTER0                          , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0   );
REG64_FLD( EX_SKITTER_CLKSRC_REG_SKITTER0_LEN                      , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0_LEN );

REG64_FLD( C_SKITTER_CLKSRC_REG_SKITTER0                           , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0   );
REG64_FLD( C_SKITTER_CLKSRC_REG_SKITTER0_LEN                       , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SKITTER0_LEN );

REG64_FLD( EQ_SKITTER_FORCE_REG_F_READ                             , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_F_READ     );

REG64_FLD( EX_SKITTER_FORCE_REG_F_READ                             , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_F_READ     );

REG64_FLD( C_SKITTER_FORCE_REG_F_READ                              , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_F_READ     );

REG64_FLD( EQ_SKITTER_MODE_REG_HOLD_SAMPLE                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE );
REG64_FLD( EQ_SKITTER_MODE_REG_DISABLE_STICKINESS                  , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_STICKINESS );
REG64_FLD( EQ_SKITTER_MODE_REG_UNUSED1                             , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1    );
REG64_FLD( EQ_SKITTER_MODE_REG_UNUSED1_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1_LEN );
REG64_FLD( EQ_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL                    , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL );
REG64_FLD( EQ_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN                , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL_LEN );
REG64_FLD( EQ_SKITTER_MODE_REG_RESET_TRIG_SEL                      , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL );
REG64_FLD( EQ_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN                  , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL_LEN );
REG64_FLD( EQ_SKITTER_MODE_REG_SAMPLE_GUTS                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS );
REG64_FLD( EQ_SKITTER_MODE_REG_SAMPLE_GUTS_LEN                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS_LEN );
REG64_FLD( EQ_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER            , 44  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE_WITH_TRIGGER );
REG64_FLD( EQ_SKITTER_MODE_REG_DATA_V_LT                           , 45  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DATA_V_LT  );

REG64_FLD( EX_SKITTER_MODE_REG_HOLD_SAMPLE                         , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE );
REG64_FLD( EX_SKITTER_MODE_REG_DISABLE_STICKINESS                  , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_STICKINESS );
REG64_FLD( EX_SKITTER_MODE_REG_UNUSED1                             , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1    );
REG64_FLD( EX_SKITTER_MODE_REG_UNUSED1_LEN                         , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1_LEN );
REG64_FLD( EX_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL                    , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL );
REG64_FLD( EX_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN                , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL_LEN );
REG64_FLD( EX_SKITTER_MODE_REG_RESET_TRIG_SEL                      , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL );
REG64_FLD( EX_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN                  , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL_LEN );
REG64_FLD( EX_SKITTER_MODE_REG_SAMPLE_GUTS                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS );
REG64_FLD( EX_SKITTER_MODE_REG_SAMPLE_GUTS_LEN                     , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS_LEN );
REG64_FLD( EX_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER            , 44  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE_WITH_TRIGGER );
REG64_FLD( EX_SKITTER_MODE_REG_DATA_V_LT                           , 45  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DATA_V_LT  );

REG64_FLD( C_SKITTER_MODE_REG_HOLD_SAMPLE                          , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE );
REG64_FLD( C_SKITTER_MODE_REG_DISABLE_STICKINESS                   , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_STICKINESS );
REG64_FLD( C_SKITTER_MODE_REG_UNUSED1                              , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1    );
REG64_FLD( C_SKITTER_MODE_REG_UNUSED1_LEN                          , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED1_LEN );
REG64_FLD( C_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL                     , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL );
REG64_FLD( C_SKITTER_MODE_REG_HOLD_DBGTRIG_SEL_LEN                 , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_HOLD_DBGTRIG_SEL_LEN );
REG64_FLD( C_SKITTER_MODE_REG_RESET_TRIG_SEL                       , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL );
REG64_FLD( C_SKITTER_MODE_REG_RESET_TRIG_SEL_LEN                   , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RESET_TRIG_SEL_LEN );
REG64_FLD( C_SKITTER_MODE_REG_SAMPLE_GUTS                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS );
REG64_FLD( C_SKITTER_MODE_REG_SAMPLE_GUTS_LEN                      , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_GUTS_LEN );
REG64_FLD( C_SKITTER_MODE_REG_HOLD_SAMPLE_WITH_TRIGGER             , 44  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_HOLD_SAMPLE_WITH_TRIGGER );
REG64_FLD( C_SKITTER_MODE_REG_DATA_V_LT                            , 45  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DATA_V_LT  );

REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_PERV_THOLD_CHECK );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN          , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_MALF_PULSE_GEN );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP          , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_STOP_HANG_CNT_SYS_XSTP );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK          , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_CL_ATOMIC_LOCK );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT               , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_HEARTBEAT );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO           , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_FORCE_TO_ZERO );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_PM_DISABLE                      , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_DISABLE );
REG64_FLD( EQ_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE                  , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_MUX_DISABLE );
REG64_FLD( EQ_SLAVE_CONFIG_REG_ERROR_MASK                          , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK );
REG64_FLD( EQ_SLAVE_CONFIG_REG_ERROR_MASK_LEN                      , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK_LEN );

REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_PERV_THOLD_CHECK );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN          , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_MALF_PULSE_GEN );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP          , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_STOP_HANG_CNT_SYS_XSTP );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK          , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_CL_ATOMIC_LOCK );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT               , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_HEARTBEAT );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO           , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_FORCE_TO_ZERO );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_PM_DISABLE                      , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_DISABLE );
REG64_FLD( EX_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE                  , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_MUX_DISABLE );
REG64_FLD( EX_SLAVE_CONFIG_REG_ERROR_MASK                          , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK );
REG64_FLD( EX_SLAVE_CONFIG_REG_ERROR_MASK_LEN                      , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK_LEN );

REG64_FLD( C_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_PERV_THOLD_CHECK );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN           , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_MALF_PULSE_GEN );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP           , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_STOP_HANG_CNT_SYS_XSTP );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK           , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_CL_ATOMIC_LOCK );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT                , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_HEARTBEAT );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO            , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_DISABLE_FORCE_TO_ZERO );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_PM_DISABLE                       , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_DISABLE );
REG64_FLD( C_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE                   , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CFG_PM_MUX_DISABLE );
REG64_FLD( C_SLAVE_CONFIG_REG_ERROR_MASK                           , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK );
REG64_FLD( C_SLAVE_CONFIG_REG_ERROR_MASK_LEN                       , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_ERROR_MASK_LEN );

REG64_FLD( EX_L2_SPR_MODE_RAM_OVERRIDE                             , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_RAM_OVERRIDE );
REG64_FLD( EX_L2_SPR_MODE_CIABR_EN                                 , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CIABR_EN   );
REG64_FLD( EX_L2_SPR_MODE_SPRC_WR_EN                               , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC_WR_EN );
REG64_FLD( EX_L2_SPR_MODE_TRIG_OVERIDE                             , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TRIG_OVERIDE );
REG64_FLD( EX_L2_SPR_MODE_DIS_TRACE                                , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DIS_TRACE  );
REG64_FLD( EX_L2_SPR_MODE_BLOCK_FIR_ERR_INJ                        , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_FIR_ERR_INJ );
REG64_FLD( EX_L2_SPR_MODE_TIMEFAC_ERROR_INJ                        , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIMEFAC_ERROR_INJ );
REG64_FLD( EX_L2_SPR_MODE_TIMEFAC_ERROR_INJ_LEN                    , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIMEFAC_ERROR_INJ_LEN );
REG64_FLD( EX_L2_SPR_MODE_SPRC0_SEL                                , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC0_SEL  );
REG64_FLD( EX_L2_SPR_MODE_SPRC1_SEL                                , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC1_SEL  );
REG64_FLD( EX_L2_SPR_MODE_SPRC2_SEL                                , 18  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC2_SEL  );
REG64_FLD( EX_L2_SPR_MODE_SPRC3_SEL                                , 19  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC3_SEL  );
REG64_FLD( EX_L2_SPR_MODE_SPRC_T0_SEL                              , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T0_SEL );
REG64_FLD( EX_L2_SPR_MODE_SPRC_T1_SEL                              , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T1_SEL );
REG64_FLD( EX_L2_SPR_MODE_SPRC_T2_SEL                              , 22  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T2_SEL );
REG64_FLD( EX_L2_SPR_MODE_SPRC_T3_SEL                              , 23  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T3_SEL );

REG64_FLD( C_SPR_MODE_RAM_OVERRIDE                                 , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_RAM_OVERRIDE );
REG64_FLD( C_SPR_MODE_CIABR_EN                                     , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CIABR_EN   );
REG64_FLD( C_SPR_MODE_SPRC_WR_EN                                   , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC_WR_EN );
REG64_FLD( C_SPR_MODE_TRIG_OVERIDE                                 , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TRIG_OVERIDE );
REG64_FLD( C_SPR_MODE_DIS_TRACE                                    , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DIS_TRACE  );
REG64_FLD( C_SPR_MODE_BLOCK_FIR_ERR_INJ                            , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_BLOCK_FIR_ERR_INJ );
REG64_FLD( C_SPR_MODE_TIMEFAC_ERROR_INJ                            , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TIMEFAC_ERROR_INJ );
REG64_FLD( C_SPR_MODE_TIMEFAC_ERROR_INJ_LEN                        , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TIMEFAC_ERROR_INJ_LEN );
REG64_FLD( C_SPR_MODE_SPRC0_SEL                                    , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC0_SEL  );
REG64_FLD( C_SPR_MODE_SPRC1_SEL                                    , 17  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC1_SEL  );
REG64_FLD( C_SPR_MODE_SPRC2_SEL                                    , 18  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC2_SEL  );
REG64_FLD( C_SPR_MODE_SPRC3_SEL                                    , 19  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC3_SEL  );
REG64_FLD( C_SPR_MODE_SPRC_T0_SEL                                  , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T0_SEL );
REG64_FLD( C_SPR_MODE_SPRC_T1_SEL                                  , 21  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T1_SEL );
REG64_FLD( C_SPR_MODE_SPRC_T2_SEL                                  , 22  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T2_SEL );
REG64_FLD( C_SPR_MODE_SPRC_T3_SEL                                  , 23  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SPRC_T3_SEL );

REG64_FLD( EX_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT                , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLE_COUNT );
REG64_FLD( EX_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN            , 8   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLE_COUNT_LEN );

REG64_FLD( C_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT                 , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLE_COUNT );
REG64_FLD( C_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN             , 8   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_CYCLE_COUNT_LEN );

REG64_FLD( EX_L2_SPURR_FREQ_REF_FREQUENCY_REFERENCE                , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQUENCY_REFERENCE );
REG64_FLD( EX_L2_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN            , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQUENCY_REFERENCE_LEN );

REG64_FLD( C_SPURR_FREQ_REF_FREQUENCY_REFERENCE                    , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQUENCY_REFERENCE );
REG64_FLD( C_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN                , 8   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FREQUENCY_REFERENCE_LEN );

REG64_FLD( EX_L2_SPURR_FREQ_SCALE_OVERRIDE_EN                      , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_OVERRIDE_EN );
REG64_FLD( EX_L2_SPURR_FREQ_SCALE_FACTOR                           , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FACTOR     );
REG64_FLD( EX_L2_SPURR_FREQ_SCALE_FACTOR_LEN                       , 7   , SH_UNT_EX_L2    , SH_ACS_SCOM_RW  ,
           SH_FLD_FACTOR_LEN );

REG64_FLD( C_SPURR_FREQ_SCALE_OVERRIDE_EN                          , 0   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_OVERRIDE_EN );
REG64_FLD( C_SPURR_FREQ_SCALE_FACTOR                               , 1   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FACTOR     );
REG64_FLD( C_SPURR_FREQ_SCALE_FACTOR_LEN                           , 7   , SH_UNT_C        , SH_ACS_SCOM_RW  ,
           SH_FLD_FACTOR_LEN );

REG64_FLD( EQ_SUM_MASK_REG_SMASK_IN                                , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN   );
REG64_FLD( EQ_SUM_MASK_REG_SMASK_IN_LEN                            , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN_LEN );

REG64_FLD( EX_SUM_MASK_REG_SMASK_IN                                , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN   );
REG64_FLD( EX_SUM_MASK_REG_SMASK_IN_LEN                            , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN_LEN );

REG64_FLD( C_SUM_MASK_REG_SMASK_IN                                 , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN   );
REG64_FLD( C_SUM_MASK_REG_SMASK_IN_LEN                             , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SMASK_IN_LEN );

REG64_FLD( EQ_SYNC_CONFIG_PULSE_DELAY                              , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY );
REG64_FLD( EQ_SYNC_CONFIG_PULSE_DELAY_LEN                          , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY_LEN );
REG64_FLD( EQ_SYNC_CONFIG_UNUSED3                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED3    );
REG64_FLD( EQ_SYNC_CONFIG_LISTEN_TO_PULSE_DIS                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_LISTEN_TO_PULSE_DIS );
REG64_FLD( EQ_SYNC_CONFIG_USE_FOR_SCAN                             , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_USE_FOR_SCAN );
REG64_FLD( EQ_SYNC_CONFIG_DISABLE_PCB_ITR                          , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_PCB_ITR );
REG64_FLD( EQ_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED                 , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CLEAR_CHIPLET_IS_ALIGNED );
REG64_FLD( EQ_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE                , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT_REGION_CLKCMD_ENABLE );
REG64_FLD( EQ_SYNC_CONFIG_UNUSED919                                , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919  );
REG64_FLD( EQ_SYNC_CONFIG_UNUSED919_LEN                            , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919_LEN );

REG64_FLD( EX_SYNC_CONFIG_PULSE_DELAY                              , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY );
REG64_FLD( EX_SYNC_CONFIG_PULSE_DELAY_LEN                          , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY_LEN );
REG64_FLD( EX_SYNC_CONFIG_UNUSED3                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED3    );
REG64_FLD( EX_SYNC_CONFIG_LISTEN_TO_PULSE_DIS                      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_LISTEN_TO_PULSE_DIS );
REG64_FLD( EX_SYNC_CONFIG_USE_FOR_SCAN                             , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_USE_FOR_SCAN );
REG64_FLD( EX_SYNC_CONFIG_DISABLE_PCB_ITR                          , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_PCB_ITR );
REG64_FLD( EX_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED                 , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_CLEAR_CHIPLET_IS_ALIGNED );
REG64_FLD( EX_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE                , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT_REGION_CLKCMD_ENABLE );
REG64_FLD( EX_SYNC_CONFIG_UNUSED919                                , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919  );
REG64_FLD( EX_SYNC_CONFIG_UNUSED919_LEN                            , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919_LEN );

REG64_FLD( C_SYNC_CONFIG_PULSE_DELAY                               , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY );
REG64_FLD( C_SYNC_CONFIG_PULSE_DELAY_LEN                           , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PULSE_DELAY_LEN );
REG64_FLD( C_SYNC_CONFIG_UNUSED3                                   , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED3    );
REG64_FLD( C_SYNC_CONFIG_LISTEN_TO_PULSE_DIS                       , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_LISTEN_TO_PULSE_DIS );
REG64_FLD( C_SYNC_CONFIG_USE_FOR_SCAN                              , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_USE_FOR_SCAN );
REG64_FLD( C_SYNC_CONFIG_DISABLE_PCB_ITR                           , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DISABLE_PCB_ITR );
REG64_FLD( C_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED                  , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_CLEAR_CHIPLET_IS_ALIGNED );
REG64_FLD( C_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE                 , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT_REGION_CLKCMD_ENABLE );
REG64_FLD( C_SYNC_CONFIG_UNUSED919                                 , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919  );
REG64_FLD( C_SYNC_CONFIG_UNUSED919_LEN                             , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED919_LEN );

REG64_FLD( CAPP_TFMR_CHIP_TOD_STATUS                               , 47  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CHIP_TOD_STATUS );
REG64_FLD( CAPP_TFMR_CHIP_TOD_STATUS_LEN                           , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CHIP_TOD_STATUS_LEN );

REG64_FLD( EQ_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR                   , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DIS_CPM_BUBBLE_CORR );
REG64_FLD( EQ_THERM_MODE_REG_FORCE_THRES_ACT                       , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_FORCE_THRES_ACT );
REG64_FLD( EQ_THERM_MODE_REG_THRES_TRIP_ENA                        , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA );
REG64_FLD( EQ_THERM_MODE_REG_THRES_TRIP_ENA_LEN                    , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA_LEN );
REG64_FLD( EQ_THERM_MODE_REG_DTS_SAMPLE_ENA                        , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_SAMPLE_ENA );
REG64_FLD( EQ_THERM_MODE_REG_SAMPLE_PULSE_CNT                      , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT );
REG64_FLD( EQ_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN                  , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT_LEN );
REG64_FLD( EQ_THERM_MODE_REG_THRES_ENA                             , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA  );
REG64_FLD( EQ_THERM_MODE_REG_THRES_ENA_LEN                         , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA_LEN );
REG64_FLD( EQ_THERM_MODE_REG_DTS_TRIGGER                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER );
REG64_FLD( EQ_THERM_MODE_REG_DTS_TRIGGER_SEL                       , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER_SEL );
REG64_FLD( EQ_THERM_MODE_REG_THRES_OVERFLOW_MASK                   , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_THRES_OVERFLOW_MASK );
REG64_FLD( EQ_THERM_MODE_REG_UNUSED                                , 15  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EQ_THERM_MODE_REG_DTS_READ_SEL                          , 16  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL );
REG64_FLD( EQ_THERM_MODE_REG_DTS_READ_SEL_LEN                      , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL_LEN );
REG64_FLD( EQ_THERM_MODE_REG_DTS_ENABLE_L1                         , 20  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1 );
REG64_FLD( EQ_THERM_MODE_REG_DTS_ENABLE_L1_LEN                     , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1_LEN );

REG64_FLD( EX_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR                   , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DIS_CPM_BUBBLE_CORR );
REG64_FLD( EX_THERM_MODE_REG_FORCE_THRES_ACT                       , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_FORCE_THRES_ACT );
REG64_FLD( EX_THERM_MODE_REG_THRES_TRIP_ENA                        , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA );
REG64_FLD( EX_THERM_MODE_REG_THRES_TRIP_ENA_LEN                    , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA_LEN );
REG64_FLD( EX_THERM_MODE_REG_DTS_SAMPLE_ENA                        , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_SAMPLE_ENA );
REG64_FLD( EX_THERM_MODE_REG_SAMPLE_PULSE_CNT                      , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT );
REG64_FLD( EX_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN                  , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT_LEN );
REG64_FLD( EX_THERM_MODE_REG_THRES_ENA                             , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA  );
REG64_FLD( EX_THERM_MODE_REG_THRES_ENA_LEN                         , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA_LEN );
REG64_FLD( EX_THERM_MODE_REG_DTS_TRIGGER                           , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER );
REG64_FLD( EX_THERM_MODE_REG_DTS_TRIGGER_SEL                       , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER_SEL );
REG64_FLD( EX_THERM_MODE_REG_THRES_OVERFLOW_MASK                   , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_THRES_OVERFLOW_MASK );
REG64_FLD( EX_THERM_MODE_REG_UNUSED                                , 15  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( EX_THERM_MODE_REG_DTS_READ_SEL                          , 16  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL );
REG64_FLD( EX_THERM_MODE_REG_DTS_READ_SEL_LEN                      , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL_LEN );
REG64_FLD( EX_THERM_MODE_REG_DTS_ENABLE_L1                         , 20  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1 );
REG64_FLD( EX_THERM_MODE_REG_DTS_ENABLE_L1_LEN                     , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1_LEN );

REG64_FLD( C_THERM_MODE_REG_DIS_CPM_BUBBLE_CORR                    , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DIS_CPM_BUBBLE_CORR );
REG64_FLD( C_THERM_MODE_REG_FORCE_THRES_ACT                        , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_FORCE_THRES_ACT );
REG64_FLD( C_THERM_MODE_REG_THRES_TRIP_ENA                         , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA );
REG64_FLD( C_THERM_MODE_REG_THRES_TRIP_ENA_LEN                     , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THRES_TRIP_ENA_LEN );
REG64_FLD( C_THERM_MODE_REG_DTS_SAMPLE_ENA                         , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_SAMPLE_ENA );
REG64_FLD( C_THERM_MODE_REG_SAMPLE_PULSE_CNT                       , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT );
REG64_FLD( C_THERM_MODE_REG_SAMPLE_PULSE_CNT_LEN                   , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_SAMPLE_PULSE_CNT_LEN );
REG64_FLD( C_THERM_MODE_REG_THRES_ENA                              , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA  );
REG64_FLD( C_THERM_MODE_REG_THRES_ENA_LEN                          , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THRES_ENA_LEN );
REG64_FLD( C_THERM_MODE_REG_DTS_TRIGGER                            , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER );
REG64_FLD( C_THERM_MODE_REG_DTS_TRIGGER_SEL                        , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_TRIGGER_SEL );
REG64_FLD( C_THERM_MODE_REG_THRES_OVERFLOW_MASK                    , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_THRES_OVERFLOW_MASK );
REG64_FLD( C_THERM_MODE_REG_UNUSED                                 , 15  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNUSED     );
REG64_FLD( C_THERM_MODE_REG_DTS_READ_SEL                           , 16  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL );
REG64_FLD( C_THERM_MODE_REG_DTS_READ_SEL_LEN                       , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_READ_SEL_LEN );
REG64_FLD( C_THERM_MODE_REG_DTS_ENABLE_L1                          , 20  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1 );
REG64_FLD( C_THERM_MODE_REG_DTS_ENABLE_L1_LEN                      , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_DTS_ENABLE_L1_LEN );

REG64_FLD( EQ_TIMESTAMP_COUNTER_READ_VALUE                         , 0   , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE      );
REG64_FLD( EQ_TIMESTAMP_COUNTER_READ_VALUE_LEN                     , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( EQ_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR                  , 44  , SH_UNT_EQ       , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_ERR );

REG64_FLD( EX_TIMESTAMP_COUNTER_READ_VALUE                         , 0   , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE      );
REG64_FLD( EX_TIMESTAMP_COUNTER_READ_VALUE_LEN                     , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( EX_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR                  , 44  , SH_UNT_EX       , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_ERR );

REG64_FLD( C_TIMESTAMP_COUNTER_READ_VALUE                          , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE      );
REG64_FLD( C_TIMESTAMP_COUNTER_READ_VALUE_LEN                      , 44  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_VALUE_LEN  );
REG64_FLD( C_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR                   , 44  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_OVERFLOW_ERR );

REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_TIMEOUT                       , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_TIMEOUT );
REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_SEQ_ERR                       , 1   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_SEQ_ERR );
REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_SEQ_PERR                      , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_SEQ_PERR );
REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_BAD_OP_ERR                    , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_BAD_OP_ERR );
REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_SNP_ADDR_PERR                 , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_SNP_ADDR_PERR );
REG64_FLD( CAPP_TLBI_ERROR_REPORT_IN_SNP_TTAG_PERR                 , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_IN_SNP_TTAG_PERR );

REG64_FLD( EX_L2_TOD_READ_TIMEBASE                                 , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_READ_TIMEBASE_LEN                             , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE_LEN );

REG64_FLD( C_TOD_READ_TIMEBASE                                     , 0   , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_READ_TIMEBASE_LEN                                 , 60  , SH_UNT_C        , SH_ACS_SCOM_RO  ,
           SH_FLD_TIMEBASE_LEN );

REG64_FLD( CAPP_TOD_SYNC000_TIMEBASE                               , 55  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TIMEBASE   );
REG64_FLD( CAPP_TOD_SYNC000_TIMEBASE_LEN                           , 5   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( CAPP_TOD_SYNC000_CHIP_STATUS                            , 60  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( CAPP_TOD_SYNC000_CHIP_STATUS_LEN                        , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC000_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC000_TIMEBASE_LEN                          , 55  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC000_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC000_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC000_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC000_TIMEBASE_LEN                              , 55  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC000_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC000_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC001_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC001_TIMEBASE_LEN                          , 54  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC001_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC001_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC001_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC001_TIMEBASE_LEN                              , 54  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC001_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC001_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC010_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC010_TIMEBASE_LEN                          , 53  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC010_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC010_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC010_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC010_TIMEBASE_LEN                              , 53  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC010_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC010_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC011_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC011_TIMEBASE_LEN                          , 52  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC011_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC011_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC011_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC011_TIMEBASE_LEN                              , 52  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC011_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC011_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC100_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC100_TIMEBASE_LEN                          , 51  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC100_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC100_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC100_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC100_TIMEBASE_LEN                              , 51  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC100_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC100_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC101_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC101_TIMEBASE_LEN                          , 50  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC101_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC101_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC101_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC101_TIMEBASE_LEN                              , 50  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC101_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC101_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC110_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC110_TIMEBASE_LEN                          , 49  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC110_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC110_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC110_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC110_TIMEBASE_LEN                              , 49  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC110_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC110_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_L2_TOD_SYNC111_TIMEBASE                              , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( EX_L2_TOD_SYNC111_TIMEBASE_LEN                          , 48  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( EX_L2_TOD_SYNC111_CHIP_STATUS                           , 60  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( EX_L2_TOD_SYNC111_CHIP_STATUS_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( C_TOD_SYNC111_TIMEBASE                                  , 0   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE   );
REG64_FLD( C_TOD_SYNC111_TIMEBASE_LEN                              , 48  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_TIMEBASE_LEN );
REG64_FLD( C_TOD_SYNC111_CHIP_STATUS                               , 60  , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS );
REG64_FLD( C_TOD_SYNC111_CHIP_STATUS_LEN                           , 4   , SH_UNT_C        , SH_ACS_SCOM1_WO ,
           SH_FLD_CHIP_STATUS_LEN );

REG64_FLD( EX_V0_HMER_MALFUNCTION_ALERT                            , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_V0_HMER_CME_REQUEST                                  , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_V0_HMER_PROC_RCVY_DONE                               , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_V0_HMER_TFAC_ERR                                     , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_V0_HMER_TFMR_PARITY_ERR                              , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_V0_HMER_XSCOM_FAIL                                   , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_V0_HMER_XSCOM_DONE                                   , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_V0_HMER_PROC_RCVY_AGAIN                              , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_V0_HMER_SCOM_FIR_HMI                                 , 16  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_V0_HMER_TRIG_FIR_HMI                                 , 17  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_V0_HMER_HYP_RECOURCE_ERR                             , 20  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_V0_HMER_XSCOM_STATUS                                 , 21  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_V0_HMER_XSCOM_STATUS_LEN                             , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EX_L2_V0_HMER_MALFUNCTION_ALERT                         , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_L2_V0_HMER_CME_REQUEST                               , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_L2_V0_HMER_PROC_RCVY_DONE                            , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_L2_V0_HMER_TFAC_ERR                                  , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_L2_V0_HMER_TFMR_PARITY_ERR                           , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_L2_V0_HMER_XSCOM_FAIL                                , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_L2_V0_HMER_XSCOM_DONE                                , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_L2_V0_HMER_PROC_RCVY_AGAIN                           , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_L2_V0_HMER_SCOM_FIR_HMI                              , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_L2_V0_HMER_TRIG_FIR_HMI                              , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_L2_V0_HMER_HYP_RECOURCE_ERR                          , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_L2_V0_HMER_XSCOM_STATUS                              , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_L2_V0_HMER_XSCOM_STATUS_LEN                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( C_V0_HMER_MALFUNCTION_ALERT                             , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( C_V0_HMER_CME_REQUEST                                   , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( C_V0_HMER_PROC_RCVY_DONE                                , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( C_V0_HMER_TFAC_ERR                                      , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( C_V0_HMER_TFMR_PARITY_ERR                               , 5   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( C_V0_HMER_XSCOM_FAIL                                    , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( C_V0_HMER_XSCOM_DONE                                    , 9   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( C_V0_HMER_PROC_RCVY_AGAIN                               , 11  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( C_V0_HMER_SCOM_FIR_HMI                                  , 16  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( C_V0_HMER_TRIG_FIR_HMI                                  , 17  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( C_V0_HMER_HYP_RECOURCE_ERR                              , 20  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( C_V0_HMER_XSCOM_STATUS                                  , 21  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( C_V0_HMER_XSCOM_STATUS_LEN                              , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EX_V1_HMER_MALFUNCTION_ALERT                            , 0   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_V1_HMER_CME_REQUEST                                  , 1   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_V1_HMER_PROC_RCVY_DONE                               , 2   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_V1_HMER_TFAC_ERR                                     , 4   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_V1_HMER_TFMR_PARITY_ERR                              , 5   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_V1_HMER_XSCOM_FAIL                                   , 8   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_V1_HMER_XSCOM_DONE                                   , 9   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_V1_HMER_PROC_RCVY_AGAIN                              , 11  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_V1_HMER_SCOM_FIR_HMI                                 , 16  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_V1_HMER_TRIG_FIR_HMI                                 , 17  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_V1_HMER_HYP_RECOURCE_ERR                             , 20  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_V1_HMER_XSCOM_STATUS                                 , 21  , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_V1_HMER_XSCOM_STATUS_LEN                             , 3   , SH_UNT_EX       , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EX_L2_V1_HMER_MALFUNCTION_ALERT                         , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_L2_V1_HMER_CME_REQUEST                               , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_L2_V1_HMER_PROC_RCVY_DONE                            , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_L2_V1_HMER_TFAC_ERR                                  , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_L2_V1_HMER_TFMR_PARITY_ERR                           , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_L2_V1_HMER_XSCOM_FAIL                                , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_L2_V1_HMER_XSCOM_DONE                                , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_L2_V1_HMER_PROC_RCVY_AGAIN                           , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_L2_V1_HMER_SCOM_FIR_HMI                              , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_L2_V1_HMER_TRIG_FIR_HMI                              , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_L2_V1_HMER_HYP_RECOURCE_ERR                          , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_L2_V1_HMER_XSCOM_STATUS                              , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_L2_V1_HMER_XSCOM_STATUS_LEN                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM1_WAND,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( C_V1_HMER_MALFUNCTION_ALERT                             , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( C_V1_HMER_CME_REQUEST                                   , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( C_V1_HMER_PROC_RCVY_DONE                                , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( C_V1_HMER_TFAC_ERR                                      , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( C_V1_HMER_TFMR_PARITY_ERR                               , 5   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( C_V1_HMER_XSCOM_FAIL                                    , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( C_V1_HMER_XSCOM_DONE                                    , 9   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( C_V1_HMER_PROC_RCVY_AGAIN                               , 11  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( C_V1_HMER_SCOM_FIR_HMI                                  , 16  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( C_V1_HMER_TRIG_FIR_HMI                                  , 17  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( C_V1_HMER_HYP_RECOURCE_ERR                              , 20  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( C_V1_HMER_XSCOM_STATUS                                  , 21  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( C_V1_HMER_XSCOM_STATUS_LEN                              , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EX_L2_V2_HMER_MALFUNCTION_ALERT                         , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_L2_V2_HMER_CME_REQUEST                               , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_L2_V2_HMER_PROC_RCVY_DONE                            , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_L2_V2_HMER_TFAC_ERR                                  , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_L2_V2_HMER_TFMR_PARITY_ERR                           , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_L2_V2_HMER_XSCOM_FAIL                                , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_L2_V2_HMER_XSCOM_DONE                                , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_L2_V2_HMER_PROC_RCVY_AGAIN                           , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_L2_V2_HMER_SCOM_FIR_HMI                              , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_L2_V2_HMER_TRIG_FIR_HMI                              , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_L2_V2_HMER_HYP_RECOURCE_ERR                          , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_L2_V2_HMER_XSCOM_STATUS                              , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_L2_V2_HMER_XSCOM_STATUS_LEN                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( C_V2_HMER_MALFUNCTION_ALERT                             , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( C_V2_HMER_CME_REQUEST                                   , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( C_V2_HMER_PROC_RCVY_DONE                                , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( C_V2_HMER_TFAC_ERR                                      , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( C_V2_HMER_TFMR_PARITY_ERR                               , 5   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( C_V2_HMER_XSCOM_FAIL                                    , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( C_V2_HMER_XSCOM_DONE                                    , 9   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( C_V2_HMER_PROC_RCVY_AGAIN                               , 11  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( C_V2_HMER_SCOM_FIR_HMI                                  , 16  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( C_V2_HMER_TRIG_FIR_HMI                                  , 17  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( C_V2_HMER_HYP_RECOURCE_ERR                              , 20  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( C_V2_HMER_XSCOM_STATUS                                  , 21  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( C_V2_HMER_XSCOM_STATUS_LEN                              , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EX_L2_V3_HMER_MALFUNCTION_ALERT                         , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( EX_L2_V3_HMER_CME_REQUEST                               , 1   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( EX_L2_V3_HMER_PROC_RCVY_DONE                            , 2   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( EX_L2_V3_HMER_TFAC_ERR                                  , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( EX_L2_V3_HMER_TFMR_PARITY_ERR                           , 5   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( EX_L2_V3_HMER_XSCOM_FAIL                                , 8   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( EX_L2_V3_HMER_XSCOM_DONE                                , 9   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( EX_L2_V3_HMER_PROC_RCVY_AGAIN                           , 11  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( EX_L2_V3_HMER_SCOM_FIR_HMI                              , 16  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( EX_L2_V3_HMER_TRIG_FIR_HMI                              , 17  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( EX_L2_V3_HMER_HYP_RECOURCE_ERR                          , 20  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( EX_L2_V3_HMER_XSCOM_STATUS                              , 21  , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( EX_L2_V3_HMER_XSCOM_STATUS_LEN                          , 3   , SH_UNT_EX_L2    , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( C_V3_HMER_MALFUNCTION_ALERT                             , 0   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_MALFUNCTION_ALERT );
REG64_FLD( C_V3_HMER_CME_REQUEST                                   , 1   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_CME_REQUEST );
REG64_FLD( C_V3_HMER_PROC_RCVY_DONE                                , 2   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_DONE );
REG64_FLD( C_V3_HMER_TFAC_ERR                                      , 4   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFAC_ERR   );
REG64_FLD( C_V3_HMER_TFMR_PARITY_ERR                               , 5   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TFMR_PARITY_ERR );
REG64_FLD( C_V3_HMER_XSCOM_FAIL                                    , 8   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_FAIL );
REG64_FLD( C_V3_HMER_XSCOM_DONE                                    , 9   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_DONE );
REG64_FLD( C_V3_HMER_PROC_RCVY_AGAIN                               , 11  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_PROC_RCVY_AGAIN );
REG64_FLD( C_V3_HMER_SCOM_FIR_HMI                                  , 16  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_SCOM_FIR_HMI );
REG64_FLD( C_V3_HMER_TRIG_FIR_HMI                                  , 17  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_TRIG_FIR_HMI );
REG64_FLD( C_V3_HMER_HYP_RECOURCE_ERR                              , 20  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_HYP_RECOURCE_ERR );
REG64_FLD( C_V3_HMER_XSCOM_STATUS                                  , 21  , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS );
REG64_FLD( C_V3_HMER_XSCOM_STATUS_LEN                              , 3   , SH_UNT_C        , SH_ACS_SCOM2_OR ,
           SH_FLD_XSCOM_STATUS_LEN );

REG64_FLD( EQ_WR_EPS_REG_TIER1_VALUE                               , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE );
REG64_FLD( EQ_WR_EPS_REG_TIER1_VALUE_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE_LEN );
REG64_FLD( EQ_WR_EPS_REG_TIER2_VALUE                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE );
REG64_FLD( EQ_WR_EPS_REG_TIER2_VALUE_LEN                           , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE_LEN );
REG64_FLD( EQ_WR_EPS_REG_DIVIDER_MODE                              , 24  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DIVIDER_MODE );
REG64_FLD( EQ_WR_EPS_REG_DIVIDER_MODE_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_DIVIDER_MODE_LEN );
REG64_FLD( EQ_WR_EPS_REG_MODE_SEL                                  , 28  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MODE_SEL   );
REG64_FLD( EQ_WR_EPS_REG_CNT_USE_L2_DIVIDER_EN                     , 29  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_CNT_USE_L2_DIVIDER_EN );
REG64_FLD( EQ_WR_EPS_REG_L2_STEP_MODE                              , 30  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L2_STEP_MODE );
REG64_FLD( EQ_WR_EPS_REG_L2_STEP_MODE_LEN                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_L2_STEP_MODE_LEN );

REG64_FLD( EX_L2_WR_EPS_REG_TIER1_VALUE                            , 0   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE );
REG64_FLD( EX_L2_WR_EPS_REG_TIER1_VALUE_LEN                        , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER1_VALUE_LEN );
REG64_FLD( EX_L2_WR_EPS_REG_TIER2_VALUE                            , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE );
REG64_FLD( EX_L2_WR_EPS_REG_TIER2_VALUE_LEN                        , 12  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_TIER2_VALUE_LEN );
REG64_FLD( EX_L2_WR_EPS_REG_DIVIDER_MODE                           , 24  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DIVIDER_MODE );
REG64_FLD( EX_L2_WR_EPS_REG_DIVIDER_MODE_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_DIVIDER_MODE_LEN );
REG64_FLD( EX_L2_WR_EPS_REG_MODE_SEL                               , 28  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_MODE_SEL   );
REG64_FLD( EX_L2_WR_EPS_REG_CNT_USE_L2_DIVIDER_EN                  , 29  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_CNT_USE_L2_DIVIDER_EN );
REG64_FLD( EX_L2_WR_EPS_REG_L2_STEP_MODE                           , 30  , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_L2_STEP_MODE );
REG64_FLD( EX_L2_WR_EPS_REG_L2_STEP_MODE_LEN                       , 4   , SH_UNT_EX_L2    , SH_ACS_SCOM     ,
           SH_FLD_L2_STEP_MODE_LEN );

REG64_FLD( CAPP_XPT_CONTROL_SEND_PACKET_TIMER_VALUE                , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SEND_PACKET_TIMER_VALUE );
REG64_FLD( CAPP_XPT_CONTROL_SEND_PACKET_TIMER_VALUE_LEN            , 10  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SEND_PACKET_TIMER_VALUE_LEN );
REG64_FLD( CAPP_XPT_CONTROL_CI_STORE_BUFFER_THRESHOLD              , 10  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CI_STORE_BUFFER_THRESHOLD );
REG64_FLD( CAPP_XPT_CONTROL_CI_STORE_BUFFER_THRESHOLD_LEN          , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CI_STORE_BUFFER_THRESHOLD_LEN );
REG64_FLD( CAPP_XPT_CONTROL_MAX_LPC_DATA_PBH0_CI_STORE_BUFFERS     , 14  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_MAX_LPC_DATA_PBH0_CI_STORE_BUFFERS );
REG64_FLD( CAPP_XPT_CONTROL_MAX_LPC_DATA_PBH0_CI_STORE_BUFFERS_LEN , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_MAX_LPC_DATA_PBH0_CI_STORE_BUFFERS_LEN );
REG64_FLD( CAPP_XPT_CONTROL_TLBI_DATA_POLL_PULSE_DIV               , 18  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBI_DATA_POLL_PULSE_DIV );
REG64_FLD( CAPP_XPT_CONTROL_TLBI_DATA_POLL_PULSE_DIV_LEN           , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBI_DATA_POLL_PULSE_DIV_LEN );
REG64_FLD( CAPP_XPT_CONTROL_SN_WRT_DBUF_MAX_CREDIT                 , 22  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SN_WRT_DBUF_MAX_CREDIT );
REG64_FLD( CAPP_XPT_CONTROL_SN_WRT_DBUF_MAX_CREDIT_LEN             , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SN_WRT_DBUF_MAX_CREDIT_LEN );
REG64_FLD( CAPP_XPT_CONTROL_RESERVED                               , 26  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RESERVED   );
REG64_FLD( CAPP_XPT_CONTROL_RESERVED_LEN                           , 2   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_RESERVED_LEN );
REG64_FLD( CAPP_XPT_CONTROL_SN_MSG_MAX_CREDIT                      , 28  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SN_MSG_MAX_CREDIT );
REG64_FLD( CAPP_XPT_CONTROL_SN_MSG_MAX_CREDIT_LEN                  , 9   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_SN_MSG_MAX_CREDIT_LEN );
REG64_FLD( CAPP_XPT_CONTROL_BENIGN_PTR_DATA                        , 37  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_BENIGN_PTR_DATA );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_EN                         , 38  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_EN );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_THRESHOLD                  , 39  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_THRESHOLD_LEN              , 3   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_THRESHOLD_LEN );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_CMPLT_CNT                  , 42  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_CMPLT_CNT_LEN              , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_CMPLT_CNT_LEN );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_DELAY_CNT                  , 46  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT );
REG64_FLD( CAPP_XPT_CONTROL_TLBIE_STALL_DELAY_CNT_LEN              , 8   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_TLBIE_STALL_DELAY_CNT_LEN );
REG64_FLD( CAPP_XPT_CONTROL_CI_BUFF_AVAIL                          , 62  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_CI_BUFF_AVAIL );
REG64_FLD( CAPP_XPT_CONTROL_ALINK_NOTPHB_MODE                      , 63  , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_ALINK_NOTPHB_MODE );

REG64_FLD( CAPP_XPT_PMU_EVENTS_SEL_PMON_GROUP_SELECT               , 0   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMON_GROUP_SELECT );
REG64_FLD( CAPP_XPT_PMU_EVENTS_SEL_PMON_GROUP_SELECT_LEN           , 4   , SH_UNT_CAPP     , SH_ACS_SCOM     ,
           SH_FLD_PMON_GROUP_SELECT_LEN );

REG64_FLD( EQ_XSTOP1_MASK_B                                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EQ_XSTOP1_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EQ_XSTOP1_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EQ_XSTOP1_WAIT_ALLWAYS                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EQ_XSTOP1_PERV                                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EQ_XSTOP1_UNIT1                                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EQ_XSTOP1_UNIT2                                         , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EQ_XSTOP1_UNIT3                                         , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EQ_XSTOP1_UNIT4                                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EQ_XSTOP1_UNIT5                                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EQ_XSTOP1_UNIT6                                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EQ_XSTOP1_UNIT7                                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EQ_XSTOP1_UNIT8                                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EQ_XSTOP1_UNIT9                                         , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EQ_XSTOP1_UNIT10                                        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EQ_XSTOP1_WAIT_CYCLES                                   , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EQ_XSTOP1_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EX_XSTOP1_MASK_B                                        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EX_XSTOP1_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EX_XSTOP1_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EX_XSTOP1_WAIT_ALLWAYS                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EX_XSTOP1_PERV                                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EX_XSTOP1_UNIT1                                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EX_XSTOP1_UNIT2                                         , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EX_XSTOP1_UNIT3                                         , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EX_XSTOP1_UNIT4                                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EX_XSTOP1_UNIT5                                         , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EX_XSTOP1_UNIT6                                         , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EX_XSTOP1_UNIT7                                         , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EX_XSTOP1_UNIT8                                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EX_XSTOP1_UNIT9                                         , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EX_XSTOP1_UNIT10                                        , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EX_XSTOP1_WAIT_CYCLES                                   , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EX_XSTOP1_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( C_XSTOP1_MASK_B                                         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( C_XSTOP1_KEEP_EDRAM_ENABLED_ON                          , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( C_XSTOP1_TRIGGER_OPCG_ON                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( C_XSTOP1_WAIT_ALLWAYS                                   , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( C_XSTOP1_PERV                                           , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( C_XSTOP1_UNIT1                                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( C_XSTOP1_UNIT2                                          , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( C_XSTOP1_UNIT3                                          , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( C_XSTOP1_UNIT4                                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( C_XSTOP1_UNIT5                                          , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( C_XSTOP1_UNIT6                                          , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( C_XSTOP1_UNIT7                                          , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( C_XSTOP1_UNIT8                                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( C_XSTOP1_UNIT9                                          , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( C_XSTOP1_UNIT10                                         , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( C_XSTOP1_WAIT_CYCLES                                    , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( C_XSTOP1_WAIT_CYCLES_LEN                                , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EQ_XSTOP2_MASK_B                                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EQ_XSTOP2_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EQ_XSTOP2_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EQ_XSTOP2_WAIT_ALLWAYS                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EQ_XSTOP2_PERV                                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EQ_XSTOP2_UNIT1                                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EQ_XSTOP2_UNIT2                                         , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EQ_XSTOP2_UNIT3                                         , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EQ_XSTOP2_UNIT4                                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EQ_XSTOP2_UNIT5                                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EQ_XSTOP2_UNIT6                                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EQ_XSTOP2_UNIT7                                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EQ_XSTOP2_UNIT8                                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EQ_XSTOP2_UNIT9                                         , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EQ_XSTOP2_UNIT10                                        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EQ_XSTOP2_WAIT_CYCLES                                   , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EQ_XSTOP2_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EX_XSTOP2_MASK_B                                        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EX_XSTOP2_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EX_XSTOP2_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EX_XSTOP2_WAIT_ALLWAYS                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EX_XSTOP2_PERV                                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EX_XSTOP2_UNIT1                                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EX_XSTOP2_UNIT2                                         , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EX_XSTOP2_UNIT3                                         , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EX_XSTOP2_UNIT4                                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EX_XSTOP2_UNIT5                                         , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EX_XSTOP2_UNIT6                                         , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EX_XSTOP2_UNIT7                                         , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EX_XSTOP2_UNIT8                                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EX_XSTOP2_UNIT9                                         , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EX_XSTOP2_UNIT10                                        , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EX_XSTOP2_WAIT_CYCLES                                   , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EX_XSTOP2_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( C_XSTOP2_MASK_B                                         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( C_XSTOP2_KEEP_EDRAM_ENABLED_ON                          , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( C_XSTOP2_TRIGGER_OPCG_ON                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( C_XSTOP2_WAIT_ALLWAYS                                   , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( C_XSTOP2_PERV                                           , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( C_XSTOP2_UNIT1                                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( C_XSTOP2_UNIT2                                          , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( C_XSTOP2_UNIT3                                          , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( C_XSTOP2_UNIT4                                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( C_XSTOP2_UNIT5                                          , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( C_XSTOP2_UNIT6                                          , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( C_XSTOP2_UNIT7                                          , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( C_XSTOP2_UNIT8                                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( C_XSTOP2_UNIT9                                          , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( C_XSTOP2_UNIT10                                         , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( C_XSTOP2_WAIT_CYCLES                                    , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( C_XSTOP2_WAIT_CYCLES_LEN                                , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EQ_XSTOP3_MASK_B                                        , 0   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EQ_XSTOP3_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EQ_XSTOP3_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EQ_XSTOP3_WAIT_ALLWAYS                                  , 3   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EQ_XSTOP3_PERV                                          , 4   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EQ_XSTOP3_UNIT1                                         , 5   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EQ_XSTOP3_UNIT2                                         , 6   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EQ_XSTOP3_UNIT3                                         , 7   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EQ_XSTOP3_UNIT4                                         , 8   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EQ_XSTOP3_UNIT5                                         , 9   , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EQ_XSTOP3_UNIT6                                         , 10  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EQ_XSTOP3_UNIT7                                         , 11  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EQ_XSTOP3_UNIT8                                         , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EQ_XSTOP3_UNIT9                                         , 13  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EQ_XSTOP3_UNIT10                                        , 14  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EQ_XSTOP3_WAIT_CYCLES                                   , 48  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EQ_XSTOP3_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EQ       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( EX_XSTOP3_MASK_B                                        , 0   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( EX_XSTOP3_KEEP_EDRAM_ENABLED_ON                         , 1   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( EX_XSTOP3_TRIGGER_OPCG_ON                               , 2   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( EX_XSTOP3_WAIT_ALLWAYS                                  , 3   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( EX_XSTOP3_PERV                                          , 4   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( EX_XSTOP3_UNIT1                                         , 5   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( EX_XSTOP3_UNIT2                                         , 6   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( EX_XSTOP3_UNIT3                                         , 7   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( EX_XSTOP3_UNIT4                                         , 8   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( EX_XSTOP3_UNIT5                                         , 9   , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( EX_XSTOP3_UNIT6                                         , 10  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( EX_XSTOP3_UNIT7                                         , 11  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( EX_XSTOP3_UNIT8                                         , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( EX_XSTOP3_UNIT9                                         , 13  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( EX_XSTOP3_UNIT10                                        , 14  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( EX_XSTOP3_WAIT_CYCLES                                   , 48  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( EX_XSTOP3_WAIT_CYCLES_LEN                               , 12  , SH_UNT_EX       , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

REG64_FLD( C_XSTOP3_MASK_B                                         , 0   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_MASK_B     );
REG64_FLD( C_XSTOP3_KEEP_EDRAM_ENABLED_ON                          , 1   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_KEEP_EDRAM_ENABLED_ON );
REG64_FLD( C_XSTOP3_TRIGGER_OPCG_ON                                , 2   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_TRIGGER_OPCG_ON );
REG64_FLD( C_XSTOP3_WAIT_ALLWAYS                                   , 3   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_ALLWAYS );
REG64_FLD( C_XSTOP3_PERV                                           , 4   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_PERV       );
REG64_FLD( C_XSTOP3_UNIT1                                          , 5   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT1      );
REG64_FLD( C_XSTOP3_UNIT2                                          , 6   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT2      );
REG64_FLD( C_XSTOP3_UNIT3                                          , 7   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT3      );
REG64_FLD( C_XSTOP3_UNIT4                                          , 8   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT4      );
REG64_FLD( C_XSTOP3_UNIT5                                          , 9   , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT5      );
REG64_FLD( C_XSTOP3_UNIT6                                          , 10  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT6      );
REG64_FLD( C_XSTOP3_UNIT7                                          , 11  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT7      );
REG64_FLD( C_XSTOP3_UNIT8                                          , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT8      );
REG64_FLD( C_XSTOP3_UNIT9                                          , 13  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT9      );
REG64_FLD( C_XSTOP3_UNIT10                                         , 14  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_UNIT10     );
REG64_FLD( C_XSTOP3_WAIT_CYCLES                                    , 48  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES );
REG64_FLD( C_XSTOP3_WAIT_CYCLES_LEN                                , 12  , SH_UNT_C        , SH_ACS_SCOM     ,
           SH_FLD_WAIT_CYCLES_LEN );

#endif

