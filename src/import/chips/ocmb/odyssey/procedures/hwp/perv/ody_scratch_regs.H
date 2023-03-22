/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_scratch_regs.H $ */
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
//------------------------------------------------------------------------------
/// @file  ody_scratch_regs.H
/// @brief Definition of scratch register fields shared between
///        ody_sppe_config_update and ody_sppe_attr_setup
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <ody_scom_perv_cfam.H>

enum ody_scratch_regs
{
    // Scratch_reg_1 (RESERVED)
    SCRATCH1_REG_VALID_BIT                          = 0,

    // Scratch_reg_2 (RESERVED)
    SCRATCH2_REG_VALID_BIT                          = 1,

    // Scratch_reg_3 (RESERVED)
    SCRATCH3_REG_VALID_BIT                          = 2,

    // Scratch_reg_4 (RESERVED)
    SCRATCH4_REG_VALID_BIT                          = 3,

    // Scratch_reg_5 (SPI bus clock divider)
    SCRATCH5_REG_VALID_BIT                          = 4,
    ATTR_SPI_BUS_DIV_REF_STARTBIT                   = 0,
    ATTR_SPI_BUS_DIV_REF_LENGTH                     = 16,
    MEMPORT_FUNCTIONAL_STATE_STARTBIT               = 16,
    MEMPORT_FUNCTIONAL_STATE_LENGTH                 = 2,

    // Scratch_reg_6 (PLL bucket/frequency configuration)
    SCRATCH6_REG_VALID_BIT                          = 5,
    ATTR_OCMB_PLL_BUCKET_STARTBIT                   = 0,
    ATTR_OCMB_PLL_BUCKET_LENGTH                     = 4,
    ATTR_OCMB_PLL_FREQ_STARTBIT                     = 16,
    ATTR_OCMB_PLL_FREQ_LENGTH                       = 16,

    // Scratch_reg_7 (clockstop-on-checkstop setup)
    SCRATCH7_REG_VALID_BIT                          = 6,
    ATTR_CLOCKSTOP_ON_XSTOP_STARTBIT                = 10,
    ATTR_CLOCKSTOP_ON_XSTOP_LENGTH                  = 2,
    ATTR_CLOCKSTOP_ON_XSTOP_DISABLED                = 0x0,
    ATTR_CLOCKSTOP_ON_XSTOP_XSTOP                   = 0x1,
    ATTR_CLOCKSTOP_ON_XSTOP_XSTOP_SPATTN            = 0x2,
    ATTR_CLOCKSTOP_ON_XSTOP_STAGED_XSTOP            = 0x3,

    // Scratch_reg_8 (PLL bypass, relative position)
    SCRATCH8_REG_VALID_BIT                          = 7,
    ATTR_IO_TANK_PLL_BYPASS_BIT                     = 0,
    ATTR_BUS_POS_STARTBIT                           = 16,
    ATTR_BUS_POS_LENGTH                             = 8,

    // Scratch_reg_9
    SCRATCH9_REG_VALID_BIT                          = 8,

    // Scratch_reg_10 (RESERVED)
    SCRATCH10_REG_VALID_BIT                         = 9,

    // Scratch_reg_11 (FW Mode flags)
    SCRATCH11_REG_VALID_BIT                         = 10,
    ATTR_OCMB_BOOT_FLAGS_STARTBIT                   = 0,
    ATTR_OCMB_BOOT_FLAGS_LENGTH                     = 32,

    ATTR_IS_SIMULATION_STARTBIT                     = 3,
    ATTR_IS_SIMULATION_LENGTH                       = 1,

    // Scratch_reg_12 (RESERVED)
    SCRATCH12_REG_VALID_BIT                         = 11,

    // Scratch_reg_13 (RESERVED)
    SCRATCH13_REG_VALID_BIT                         = 12,

    // Scratch_reg_14 (RESERVED)
    SCRATCH14_REG_VALID_BIT                         = 13,

    // Scratch_reg_15 (RESERVED)
    SCRATCH15_REG_VALID_BIT                         = 14,
};

struct ody_scratch_reg_id_t
{
    const uint8_t num;
    const uint64_t scom_addr;
    const uint32_t cfam_addr;
};

static const ody_scratch_reg_id_t SCRATCH_REGISTER1  = {  1,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW, 0x2838 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER2  = {  2,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW, 0x2839 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER3  = {  3,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW, 0x283A };
static const ody_scratch_reg_id_t SCRATCH_REGISTER4  = {  4,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW, 0x283B };
static const ody_scratch_reg_id_t SCRATCH_REGISTER5  = {  5,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW, 0x283C };
static const ody_scratch_reg_id_t SCRATCH_REGISTER6  = {  6,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_RW, 0x283D };
static const ody_scratch_reg_id_t SCRATCH_REGISTER7  = {  7,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW, 0x283E };
static const ody_scratch_reg_id_t SCRATCH_REGISTER8  = {  8,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW, 0x283F };
static const ody_scratch_reg_id_t SCRATCH_REGISTER9  = {  9,  scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_RW, 0x2980 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER10 = { 10, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW, 0x2981 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER11 = { 11, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_RW, 0x2982 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER12 = { 12, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_RW, 0x2983 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER13 = { 13, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_13_RW, 0x2984 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER14 = { 14, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_14_RW, 0x2985 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER15 = { 15, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_15_RW, 0x2986 };
static const ody_scratch_reg_id_t SCRATCH_REGISTER16 = { 16, scomt::perv::CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_16_RW, 0x2987 };

///
/// @brief Initialize SPPE scratch registers based on platform attributes/
/// targeting model
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_OCMB_CHIP
/// @param[in]   i_update_all              True=Force all scratch registers to be updated
///                                        (Hostboot/ody_sppe_setup_config usage)
///                                        False=Update only if corresponding scratch valid
///                                        is not asserted (SPPE/ody_sppe_attr_setup usage)
/// @param[in]   i_use_scom                True=perform all MBOX accesses via SCOM
///                                        False=use CFAM
///
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode ody_scratch_regs_update(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_update_all,
    const bool i_use_scom);
