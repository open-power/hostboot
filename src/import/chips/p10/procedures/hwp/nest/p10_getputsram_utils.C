/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getputsram_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <p10_scom_proc.H>
#include <p10_getputsram_utils.H>

using namespace scomt::proc;

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

bool is_OCB_PBA_InterleavedMode (const uint8_t i_mode)
{
    bool l_isInterleaved = false;
    uint8_t l_occMode = (i_mode >> MODE_OCC_ACCESS_MODE_BIT_SHIFT) & 0x3;

    // Only one specific use-case in P10 is SBE MPIPL Dump which
    // uses OCB channel 3 for both SRAM read and memory write
    // in an interleaved manner in normal/linear mode
    if ((l_occMode != OCB_MODE_CIRCULAR) &&
        (ocb::PM_OCB_CHAN_NUM::OCB_CHAN3 == getOcbChanNum(i_mode)) &&
        ((i_mode >> MODE_OCB_PBA_INTERLEAVED_SHIFT) & 0x01))
    {
        l_isInterleaved = true;
    }

    return l_isInterleaved;
}


fapi2::ReturnCode p10_ocb_handlePbaContext (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint8_t i_mode,
        const bool    i_save )
{
    FAPI_DBG(">> p10_ocb_handlePbaContext: %s", (i_save) ? "save" : "restore");
    static fapi2::buffer<uint64_t> l_ocbar3;

    if (is_OCB_PBA_InterleavedMode (i_mode))
    {
        if (i_save)
        {
            FAPI_TRY (fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3, l_ocbar3));
        }
        else
        {
            FAPI_TRY (fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3, l_ocbar3));
            l_ocbar3.flush<0>();
        }
    }

fapi_try_exit:
    FAPI_DBG("<< p10_ocb_handlePbaContext");
    return fapi2::current_err;
}
