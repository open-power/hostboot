/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_hreset.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file  p9_sbe_hreset.C
///
/// @brief Restart SBE Runtime
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Thi Tran <thi@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------
#include "p9_sbe_hreset.H"
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_frequency_buckets.H>

// ----------------
// Constants
// ----------------

// Bit definitions for MBOX SCRATCH 3 reg (CFAM 283A, SCOM 0x5003A)
#define SCRATCH_3_REG_IPL_MODE_BIT       0
#define SCRATCH_3_REG_RUNTIME_MODE_BIT   1


fapi2::ReturnCode p9_sbe_i2c_bit_rate_divisor_setting(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    bool i_masterProc)
{
    uint8_t l_attr_nest_pll_bucket = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::buffer<uint16_t> l_mb_bit_rate_divisor;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;

    FAPI_INF("Entering p9_sbe_i2c_bit_rate_divisor_setting...");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NEST_PLL_BUCKET, FAPI_SYSTEM,
                           l_attr_nest_pll_bucket));
    FAPI_INF("ATTR_NEST_PLL_BUCKET value: %d", l_attr_nest_pll_bucket);
    l_mb_bit_rate_divisor = NEST_PLL_FREQ_I2CDIV_LIST[l_attr_nest_pll_bucket - 1];
    FAPI_INF("Bit_rate_divisor value: %d", l_mb_bit_rate_divisor);

    FAPI_DBG("Adjust I2C bit rate divisor setting in I2CM B Mode Reg");
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_MODE_REGISTER_B, l_data64));
    l_data64.insertFromRight< 0, 16 >(l_mb_bit_rate_divisor);
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_MODE_REGISTER_B, l_data64));

    FAPI_INF("Writing I2C bit rate divisor into mailbox_reg_2");

    if (i_masterProc)
    {
        FAPI_TRY(fapi2::getScom(i_target_chip, PERV_SCRATCH_REGISTER_2_SCOM, l_data64));
        l_data64.insertFromRight< 0, 16 >(l_mb_bit_rate_divisor);
        FAPI_INF("p9_sbe_i2c_bit_rate_divisor_setting - Master proc Scratch2 0x%.16llX", l_data64);
        FAPI_TRY(fapi2::putScom(i_target_chip, PERV_SCRATCH_REGISTER_2_SCOM, l_data64));
    }
    else
    {
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI, l_data32));
        l_data32.insertFromRight< 0, 16 >(l_mb_bit_rate_divisor);
        FAPI_INF("p9_sbe_i2c_bit_rate_divisor_setting - Slave proc Scratch2 0x%.8X", l_data32);
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_SCRATCH_REGISTER_2_FSI, l_data32));
    }

fapi_try_exit:
    FAPI_INF("Exiting p9_sbe_i2c_bit_rate_divisor_setting...");
    return fapi2::current_err;
}

// See doxygen in header file
fapi2::ReturnCode p9_sbe_hreset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_restart_ipl)
{
    FAPI_DBG("p9_sbe_hreset: Entering...");
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint64_t> l_data64;
    uint8_t l_scratch3_bitToClear = 0;
    uint8_t l_scratch3_bitToSet = 0;
    uint8_t l_startVectorBit = 0;
    uint8_t l_masterProc = 0;

    FAPI_INF("SBE HRESET to %s", i_restart_ipl ? "IPL" : "RUNTIME");

    // Determine if target is a master
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target,
                           l_masterProc),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");

    // Set I2C bit rate in scratch2 register
    FAPI_TRY(p9_sbe_i2c_bit_rate_divisor_setting(i_target, l_masterProc),
             "Error from p9_sbe_i2c_bit_rate_divisor_setting()");

    // Setup correct bit positions depending on SBE restart mode
    if (i_restart_ipl == true)
    {
        // SBE restart IPL code execution
        l_startVectorBit = PERV_SB_CS_START_RESTART_VECTOR0;
        l_scratch3_bitToClear = SCRATCH_3_REG_RUNTIME_MODE_BIT;
        l_scratch3_bitToSet   = SCRATCH_3_REG_IPL_MODE_BIT;
    }
    else
    {
        // SBE restart RUNTIME code execution
        l_startVectorBit = PERV_SB_CS_START_RESTART_VECTOR1;
        l_scratch3_bitToClear = SCRATCH_3_REG_IPL_MODE_BIT;
        l_scratch3_bitToSet   = SCRATCH_3_REG_RUNTIME_MODE_BIT;
    }

    // Must do SCOM access for master; CFAM access for slaves
    if (l_masterProc)
    {
        // Clear Self Boot message reg
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, PERV_SB_MSG_SCOM, l_data64),
                 "Error from putScom to PERV_SB_MSG_SCOM");

        // Set MBOX scratch_3 register to indicate IPL/Runtime
        FAPI_TRY(fapi2::getScom(i_target, PERV_SCRATCH_REGISTER_3_SCOM, l_data64),
                 "Error from getScom to PERV_SCRATCH_REGISTER_3_SCOM");
        FAPI_TRY(l_data64.clearBit(l_scratch3_bitToClear));
        FAPI_TRY(l_data64.setBit(l_scratch3_bitToSet));
        FAPI_TRY(fapi2::putScom(i_target, PERV_SCRATCH_REGISTER_3_SCOM, l_data64),
                 "Error from putScom to PERV_SCRATCH_REGISTER_3_SCOM");

        // HRESET
        FAPI_TRY(fapi2::getScom(i_target, PERV_SB_CS_SCOM, l_data64),
                 "Error from getScom to PERV_SB_CS_SCOM");

        FAPI_TRY(l_data64.clearBit(l_startVectorBit));
        FAPI_TRY(fapi2::putScom(i_target, PERV_SB_CS_SCOM, l_data64),
                 "Error from putScom to PERV_SB_CS_SCOM (1)");

        FAPI_TRY(l_data64.setBit(l_startVectorBit));
        FAPI_TRY(fapi2::putScom(i_target, PERV_SB_CS_SCOM, l_data64),
                 "Error from putScom to PERV_SB_CS_SCOM (2)");

        FAPI_TRY(l_data64.clearBit(l_startVectorBit));
        FAPI_TRY(fapi2::putScom(i_target, PERV_SB_CS_SCOM, l_data64),
                 "Error from putScom to PERV_SB_CS_SCOM (3)");
    }
    else
    {
        // Clear Self Boot message reg
        l_data32.flush<0>();
        FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_SB_MSG_FSI, l_data32));

        // Set MBOX scratch_3 register to indicate IPL/Runtime
        FAPI_TRY(fapi2::getCfamRegister(i_target, PERV_SCRATCH_REGISTER_3_FSI,
                                        l_data32));
        FAPI_TRY(l_data32.clearBit(l_scratch3_bitToClear));
        FAPI_TRY(l_data32.setBit(l_scratch3_bitToSet));
        FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_SCRATCH_REGISTER_3_FSI,
                                        l_data32));

        // HRESET
        FAPI_TRY(fapi2::getCfamRegister(i_target, PERV_SB_CS_FSI, l_data32),
                 "Error from getCfamRegister to PERV_SB_CS_FSI");
        FAPI_TRY(l_data32.clearBit(l_startVectorBit));
        FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_SB_CS_FSI, l_data32),
                 "Error from putCfamRegister to PERV_SB_CS_FSI (1)");

        FAPI_TRY(l_data32.setBit(l_startVectorBit));
        FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_SB_CS_FSI, l_data32),
                 "Error from putCfamRegister to PERV_SB_CS_FSI (2)");

        FAPI_TRY(l_data32.clearBit(l_startVectorBit));
        FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_SB_CS_FSI, l_data32),
                 "Error from putCfamRegister to PERV_SB_CS_FSI (3)");
    }

fapi_try_exit:
    FAPI_INF("p9_sbe_hreset: Exiting ...");
    return fapi2::current_err;
}
