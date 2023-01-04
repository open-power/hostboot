/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_scom_lib.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file io_scom_lib.C
///
/// @brief SCOM function lib for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#include <fapi2.H>
#include <io_scom_lib.H>

fapi2::ReturnCode rmwIoHardwareReg(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI >
                                   &i_target,
                                   const uint64_t& i_addr,
                                   const uint32_t& i_data,
                                   const uint32_t& i_dataBit,
                                   const uint32_t& i_dataLen)
{
    FAPI_DBG("Start - RMW register at 0x%08X, bit %d, for %d bits", i_addr, i_dataBit, i_dataLen);

    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY(getScom(i_target, i_addr, l_buffer),
             "Error getscom to address 0x%08X.", i_addr);
    l_buffer.insertFromRight(i_data, i_dataBit, i_dataLen);
    FAPI_TRY(putScom(i_target, i_addr, l_buffer),
             "Error putscom to address 0x%08X.", i_addr);

fapi_try_exit:
    FAPI_DBG("End - RMW");
    return fapi2::current_err;
}

fapi2::ReturnCode readIoHardwareReg(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI >
                                    &i_target,
                                    const uint64_t& i_addr,
                                    const uint32_t& i_dataBit,
                                    const uint32_t& i_dataLen,
                                    uint32_t& o_data)
{
    FAPI_DBG("Start - Reading register at 0x%08X, bit %d, for %d bits", i_addr, i_dataBit, i_dataLen);

    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY(getScom(i_target, i_addr, l_buffer),
             "Error getscom to address 0x%08X.", i_addr);
    FAPI_TRY(l_buffer.extractToRight(o_data, i_dataBit, i_dataLen));

fapi_try_exit:
    FAPI_DBG("End - Read");
    return fapi2::current_err;
}
