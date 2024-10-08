/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_pie.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_load_pie.H
/// @brief Loads the binaries for the PHY Initialization Engine (PIE) to initialize the PHY to mainline mode
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_LOAD_PIE_H_
#define _ODY_LOAD_PIE_H_

#include <fapi2.H>
#include <hwp_data_stream.H>

typedef fapi2::ReturnCode (*ody_load_pie_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::hwp_data_istream&,
        fapi2::hwp_data_istream&,
        fapi2::hwp_data_istream&,
        fapi2::hwp_data_istream&);

extern "C"
{

///
/// @brief Load the PHY Initialization Engine (PIE) to initialize the PHY to mainline mode
/// @param[in] i_target, the MC of the ports
/// @param[in] i_code_data0 - hwp_data_istream for the PIE image data for port0
/// @param[in] i_code_data1 - hwp_data_istream for the PIE image data for port1
/// @param[in] i_code_sections0 - hwp_data_istream for the PIE code sections for port0
/// @param[in] i_code_sections1 - hwp_data_istream for the PIE code sections for port1
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_pie( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    fapi2::hwp_data_istream& i_code_data0,
                                    fapi2::hwp_data_istream& i_code_data1,
                                    fapi2::hwp_data_istream& i_code_sections0,
                                    fapi2::hwp_data_istream& i_code_sections1 );

}

#endif
