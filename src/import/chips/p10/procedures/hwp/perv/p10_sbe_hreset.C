/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_hreset.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
//------------------------------------------------------------------------------
/// @file  p10_sbe_hreset.C
///
/// @brief Restart SBE Runtime
//------------------------------------------------------------------------------
// *HWP HW Owner        : Manish Chowdhary <manichow@in.ibm.com>
// *HWP HW Backup Owner : Rajees Rahman  <rajerpp1@in.ibm.com>
// *HWP FW Owner        : Manish Chowdhary <manichow@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------
#include "p10_sbe_hreset.H"
#include <p10_scom_proc_1.H>
#include <p10_scom_perv_a.H>
#include <p10_scom_perv_1.H>
//#include <reg00002.H>

// ----------------
// Constants
// ----------------

// Bit definitions for MBOX SCRATCH 3 reg (CFAM 283A, SCOM 0x5003A)
#define SCRATCH_3_REG_IPL_MODE_BIT       0
#define SCRATCH_3_REG_RUNTIME_MODE_BIT   1

// See doxygen in header file
fapi2::ReturnCode p10_sbe_hreset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;
    using namespace scomt::perv;

    FAPI_DBG("p10_sbe_hreset: Entering...");
    fapi2::buffer<uint32_t> l_data32(0);
    fapi2::buffer<uint64_t> l_data64(0);
    uint8_t l_masterProc = 0;

    // Determine if target is a master
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target,
                           l_masterProc),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");

#ifndef __HOSTBOOT_RUNTIME

    // Must do SCOM access for master; CFAM access for slaves
    if (l_masterProc)
#endif
    {
        // Clear Self Boot message reg
        FAPI_TRY(PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG(i_target));
        l_data64.flush<0>();
        FAPI_TRY(PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG(i_target, l_data64));

        // Set MBOX scratch_3 register to indicate IPL/Runtime
        FAPI_TRY(PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(i_target));
        FAPI_TRY(GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(i_target, l_data64));
        FAPI_TRY(l_data64.clearBit(SCRATCH_3_REG_IPL_MODE_BIT));
        FAPI_TRY(l_data64.setBit(SCRATCH_3_REG_RUNTIME_MODE_BIT));
        FAPI_TRY(PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW(i_target, l_data64));

        // HRESET
        FAPI_TRY(PREP_FSXCOMP_FSXLOG_SB_CS(i_target));
        FAPI_TRY(GET_FSXCOMP_FSXLOG_SB_CS(i_target, l_data64));
        CLEAR_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(l_data64);
        CLEAR_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(l_data64);
        FAPI_TRY(PUT_FSXCOMP_FSXLOG_SB_CS(i_target, l_data64));

        SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(l_data64);
        FAPI_TRY(PUT_FSXCOMP_FSXLOG_SB_CS(i_target, l_data64));
    }

#ifndef __HOSTBOOT_RUNTIME
    else
    {
        // Clear Self Boot message reg
        l_data32.flush<0>();
        FAPI_TRY(fapi2::putCfamRegister(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_FSI, l_data32));

        // Set MBOX scratch_3 register to indicate IPL/Runtime
        FAPI_TRY(fapi2::getCfamRegister(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI,
                                        l_data32));
        FAPI_TRY(l_data32.clearBit(SCRATCH_3_REG_IPL_MODE_BIT));
        FAPI_TRY(l_data32.setBit(SCRATCH_3_REG_RUNTIME_MODE_BIT));
        FAPI_TRY(fapi2::putCfamRegister(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI,
                                        l_data32));

        // HRESET
        FAPI_TRY(fapi2::getCfamRegister(i_target, FSXCOMP_FSXLOG_SB_CS_FSI, l_data32),
                 "Error from getCfamRegister to FSXCOMP_FSXLOG_SB_CS_FSI");
        FAPI_TRY(l_data32.clearBit(FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0));
        FAPI_TRY(l_data32.clearBit(FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1));
        FAPI_TRY(fapi2::putCfamRegister(i_target, FSXCOMP_FSXLOG_SB_CS_FSI, l_data32),
                 "Error from putCfamRegister to FSXCOMP_FSXLOG_SB_CS_FSI");

        FAPI_TRY(l_data32.setBit(FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1));
        FAPI_TRY(fapi2::putCfamRegister(i_target, FSXCOMP_FSXLOG_SB_CS_FSI, l_data32),
                 "Error from putCfamRegister to FSXCOMP_FSXLOG_SB_CS_FSI");
    }

#endif

fapi_try_exit:
    FAPI_INF("p10_sbe_hreset: Exiting ...");
    return fapi2::current_err;
}
