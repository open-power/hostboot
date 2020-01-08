/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getputsram_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_getputsram_utils.C
///
/// @brief Common code to support get/putsram HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_getputsram_utils.H>

ocb::PM_OCB_CHAN_NUM getOcbChanNum(const uint8_t i_mode)
{
    FAPI_DBG("Entering getOcbChanNum: i_mode 0x%.2X", i_mode);
    ocb::PM_OCB_CHAN_NUM l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN3;
    uint8_t l_inputChannel = (i_mode >> MODE_OCB_CHAN_BIT_SHIFT) & 0x7;

    switch (l_inputChannel)
    {
        case 0b001:
            l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN0;
            break;

        case 0b010:
            l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN1;
            break;

        case 0b011:
            l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN2;
            break;

        case 0b100:
            l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN3;
            break;

        default:
            l_ocbChan = ocb::PM_OCB_CHAN_NUM::OCB_CHAN3;
            break;
    }

    FAPI_DBG("Exiting getOcbChanNum: OCB channel %d", l_ocbChan);
    return l_ocbChan;
}
