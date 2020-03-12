/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/sbe/p10_get_sbe_msg_register.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_get_sbe_msg_register.C
///
/// @brief Returns the SBE message register
//------------------------------------------------------------------------------
// *HWP HW Owner        : RAJA DAS <rajadas2@in.ibm.com>
// *HWP FW Owner        : RAJA DAS <rajadas2@in.ibm.com>
// *HWP Team            : SBE
// *HWP Level           : 3
// *HWP Consumed by     : SE, Hostboot, Cronus
//------------------------------------------------------------------------------


#include "p10_get_sbe_msg_register.H"
#include "p10_scom_perv_d.H"

using namespace scomt::perv;

fapi2::ReturnCode p10_get_sbe_msg_register(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip,
    sbeMsgReg_t& o_sbeReg)
{
    FAPI_DBG("Entering ...");

    fapi2::buffer<uint32_t> l_cfamReg;
#ifdef __HOSTBOOT_MODULE
    fapi2::buffer<uint64_t> l_scomReg;
#ifndef __HOSTBOOT_RUNTIME
    uint8_t l_is_master_chip = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_chip, l_is_master_chip));

    if(l_is_master_chip)
#else
    if(true)
#endif
    {
        FAPI_TRY(fapi2::getScom(i_chip, FSXCOMP_FSXLOG_SB_MSG, l_scomReg));
        l_scomReg.extract<0, 32>(o_sbeReg.reg);
    }
    else
#endif
    {
        FAPI_TRY(fapi2::getCfamRegister(i_chip, FSXCOMP_FSXLOG_SB_MSG_FSI, l_cfamReg));
        o_sbeReg.reg = l_cfamReg;
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
