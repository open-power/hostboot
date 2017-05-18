/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_pre_trainadv.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_io_obus_pre_trainadv.H
/// @brief Pre-Training PHY Status Function.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
///   Pre-Training PHY Status Function.
///
/// Procedure Prereq:
///   - System clocks are running.
///   - Scominit Procedure is completed.
///   - IO DCCAL Procedure is completed.
/// @endverbatim
///----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_obus_pre_trainadv.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------

/**
 * @brief A simple HWP that runs prior to io_run_trainig.
 *  This function is called on every Abus(Obus PHY).
 * @param[in] i_tgt   Fapi2 Target
 * @param[in] i_ctgt  Fapi2 Connected Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_obus_pre_trainadv(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt,
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_ctgt)
{
    FAPI_IMP("Entering...");
    uint8_t l_status = 0x0;

    char tgt_string[fapi2::MAX_ECMD_STRING_LEN];
    char ctgt_string[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt, tgt_string, fapi2::MAX_ECMD_STRING_LEN);
    fapi2::toString(i_ctgt, ctgt_string, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("Checking %s - %s Debug Status.", tgt_string, ctgt_string);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_O_DEBUG, i_tgt, l_status));

    if(l_status == fapi2::ENUM_ATTR_IO_O_DEBUG_TRUE)
    {
        FAPI_INF("Debug True.");
    }
    else
    {
        FAPI_INF("Debug False.");
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}
