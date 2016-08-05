/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/sbe/p9_get_sbe_msg_register.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_get_sbe_msg_register.C
///
/// @brief Returns the SBE message register
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Puranik <santosh.puranik@in.ibm.com>
// *HWP FW Owner        : Dhruvaraj Subhash Chandran <dhruvaraj@in.ibm.com>
// *HWP Team            : SBE
// *HWP Level           : 2
// *HWP Consumed by     : SE, Hostboot, Cronus
//------------------------------------------------------------------------------


#include "p9_get_sbe_msg_register.H"
#include "p9_perv_scom_addresses.H"

fapi2::ReturnCode p9_get_sbe_msg_register(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip,
        sbeMsgReg_t& o_sbeReg)
{
    fapi2::buffer<uint32_t> l_reg;

    FAPI_DBG("Entering ...");

    FAPI_TRY(fapi2::getCfamRegister(i_chip, PERV_SB_MSG_FSI, l_reg));

    o_sbeReg.reg = l_reg;

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
