/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/common/include/cen_gen_scom_addresses_fixes.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

//Example: To fix an existing definiton
//CEN_FIXREG32 (CEN_MBA_1_CCS_INST_ARR0_10, RULL(0x01234567));
#include <p9_const_common.H>
#include <p9_scom_template_consts.H>
#ifndef CEN_GEN_SCOM_ADDRESSES_FIXES_H
#define CEN_GEN_SCOM_ADDRESSES_FIXES_H

REG64( CEN_WRITE_ALL_FUNC_GP3                           , RULL(0x6B0F0012), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_WRITE_ALL_FUNC_GP3_AND                       , RULL(0x6B0F0013), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_WRITE_ALL_FUNC_GP3_OR                        , RULL(0x6B0F0014), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_WRITE_ALL_PCB_SLAVE_ERRREG                   , RULL(0x6B0F001F), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_PERV_LOCAL_FIR                               , RULL(0x0004000A), SH_UNT_PERV     , SH_ACS_SCOM_RW   );
REG64( CEN_PERV_TP_LOCAL_FIR                            , RULL(0x0104000A), SH_UNT_PERV_1   , SH_ACS_SCOM_RW   );
REG64( CEN_PERV_LOCAL_FIR_AND                           , RULL(0x0004000B), SH_UNT_PERV     , SH_ACS_SCOM1_AND );
REG64( CEN_PERV_TP_LOCAL_FIR_AND                        , RULL(0x0104000B), SH_UNT_PERV_1   , SH_ACS_SCOM1_AND );
REG64( CEN_PERV_LOCAL_FIR_OR                            , RULL(0x0004000C), SH_UNT_PERV     , SH_ACS_SCOM2_OR  );
REG64( CEN_PERV_TP_LOCAL_FIR_OR                         , RULL(0x0104000C), SH_UNT_PERV_1   , SH_ACS_SCOM2_OR  );
REG64( CEN_PERV_LOCAL_FIR_MASK                          , RULL(0x0004000D), SH_UNT_PERV     , SH_ACS_SCOM_RW   );
REG64( CEN_PERV_TP_LOCAL_FIR_MASK                       , RULL(0x0104000D), SH_UNT_PERV_1   , SH_ACS_SCOM_RW   );
REG64( CEN_PERV_LOCAL_FIR_MASK_AND                      , RULL(0x0004000E), SH_UNT_PERV     , SH_ACS_SCOM1_AND );
REG64( CEN_PERV_TP_LOCAL_FIR_MASK_AND                   , RULL(0x0104000E), SH_UNT_PERV_1   , SH_ACS_SCOM1_AND );
REG64( CEN_PERV_LOCAL_FIR_MASK_OR                       , RULL(0x0004000F), SH_UNT_PERV     , SH_ACS_SCOM2_OR  );
REG64( CEN_PERV_TP_LOCAL_FIR_MASK_OR                    , RULL(0x0104000F), SH_UNT_PERV_1   , SH_ACS_SCOM2_OR  );
REG64( CEN_GENERIC_GP1                                  , RULL(0x00000001), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_GP0_AND                              , RULL(0x00000004), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_GP0_OR                               , RULL(0x00000005), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_GP3_AND                              , RULL(0x000F0013), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_GP3_OR                               , RULL(0x000F0014), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_OPCG_CNTL0                           , RULL(0x00030002), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_OPCG_CNTL2                           , RULL(0x00030004), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_CLK_REGION                           , RULL(0x00030006), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_CLK_SCANSEL                          , RULL(0x00030007), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_CLK_STATUS                           , RULL(0x00030008), SH_UNT_PERV,       SH_ACS_FSI       );
REG64( CEN_GENERIC_CLK_SCANDATA0                        , RULL(0x00038000), SH_UNT_PERV,       SH_ACS_FSI       );

#endif
