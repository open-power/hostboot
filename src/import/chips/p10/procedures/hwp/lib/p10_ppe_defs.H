/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_ppe_defs.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
///
/// @file  p10_ppe_defs.H
/// @brief PPE commonly used definitions
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 1
/// *HWP Consumed by     : FSP, HB, SBE
#ifndef __P10_PPE_DEFS_H__
#define __P10_PPE_DEFS_H__

#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
#include <p10_scom_pauc.H>

/// @brief Base SCOM addresses for PPE State Collection
//const uint64_t SBE_BASE_ADDRESS   = Unknown;
const uint64_t GPE0_BASE_ADDRESS  = scomt::proc::TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXCR;
const uint64_t GPE1_BASE_ADDRESS  = scomt::proc::TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR;
const uint64_t PGPE_BASE_ADDRESS  = scomt::proc::TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR;
const uint64_t XGPE_BASE_ADDRESS  = scomt::proc::TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR;
const uint64_t QME_BASE_ADDRESS   = scomt::eq::QME_SCOM_XIXCR;
const uint64_t PHY_BASE_ADDRESS   = scomt::pauc::PHY_PPE_WRAP_XIXCR;
const uint64_t DL_BASE_ADDRESS    = scomt::pauc::PHY_PPE_WRAP_XIXCR;

#endif  // __P10_PPE_DEFS_H__
