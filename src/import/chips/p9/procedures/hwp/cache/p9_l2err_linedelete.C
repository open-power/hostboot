/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l2err_linedelete.C $ */
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

///----------------------------------------------------------------------------
///
/// @file p9_l2err_linedelete.C
///
/// @brief Delete the L2 error cache line according to the error extraction
///        information.
///        See more detailed description in header file.
///
/// *HWP HWP Owner   : Chen Qian <qianqc@cn.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : PRDF
/// *HWP Level       : 3
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l2err_linedelete.H>
#include <p9_l2_flush.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
// See doxygen in header file
fapi2::ReturnCode p9_l2err_linedelete(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const p9_l2err_extract_err_data& i_err_data,
    const uint64_t i_busyCount)
{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_cmdReg;
    p9core::purgeData_t l_purgeData;

    // mark function entry
    FAPI_DBG("Entering p9_l2err_linedelete. BusyCount %d", i_busyCount);

    //   +---------------------------+
    //   |    L2 Line Delete Scom    |
    //   +---------------------------+
    //   |Bit(s)|  Data              |
    //   +------+--------------------+
    //   |    0 | Trigger            |
    //   +------+--------------------+
    //   |  1:4 | Purge type (LD=0x2)|
    //   +------+--------------------+
    //   | 5:16 | Don't care         |
    //   +------+--------------------+
    //   |17:19 | Member             |
    //   +------+--------------------+
    //   |20:27 | CGC  addr 48:55    |
    //   +------+--------------------+
    //   |   28 | Bank               |
    //   +------+--------------------+
    //   |29:30 | Don't care         |
    //   +------+--------------------+

    // Write member, address and bank into PRD Purge Engine Command Register
    // SCOM Addr: 0x000000001001080E
    // bit 0 is the trigger, the act of writing this bit to 1 sets off the line delete
    // bits 1:4 is ttype 0b0010 = line delete
    // bits 17:19 is the member
    // bits 20:27 is the cgc address
    // bit 28 is the bank

    // Ensure that purge engine is idle before starting line delete
    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount, l_cmdReg),
             "Error returned from purgeCompleteCheck call");

    // Set PRD Purge Engine Command register values for line delete
    l_purgeData.iv_cmdType = 0b0010; // L2 Dir Line_Delete
    l_purgeData.iv_cmdMem = i_err_data.member;
    l_purgeData.iv_cmdBank = i_err_data.bank;
    l_purgeData.iv_cmdCGC = i_err_data.address;

    FAPI_TRY(setupAndTriggerPrdPurge(i_target, l_purgeData, l_cmdReg),
             "Error returned from setupAndTriggerPrdPurge");

    // Verify purge/line delete complete
    FAPI_TRY(purgeCompleteCheck(i_target, i_busyCount, l_cmdReg),
             "Error returned from purgeCompleteCheck call");

fapi_try_exit:
    FAPI_INF("Exiting p9_l2err_linedelete...");
    return fapi2::current_err;
} // p9_l2err_extract
