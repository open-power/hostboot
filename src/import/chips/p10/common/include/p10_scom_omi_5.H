/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_5.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_omi_5_H_
#define __p10_scom_omi_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [RXCTL_DATASM_4_PLREGS_RX_MODE1_PL]
static const uint64_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL = 0x8003d04410012c3full;

static const uint32_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
//<< [RXCTL_DATASM_4_PLREGS_RX_MODE1_PL]
// omi/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00010.H"
#include "omi/reg00011.H"
#endif
#endif
