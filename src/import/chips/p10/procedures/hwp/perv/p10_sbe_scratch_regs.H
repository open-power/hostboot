/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_scratch_regs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_sbe_scratch_regs.H
///
/// @brief Definition of scratch register fields shared between
///        p10_setup_sbe_config and p10_sbe_attr_setup
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#ifndef _P10_SBE_SCRATCH_REGS_H_
#define _P10_SBE_SCRATCH_REGS_H_

#include <p10_scom_perv.H>

enum p10_sbe_scratch_regs
{
    // Scratch_reg_1
    SCRATCH1_REG_VALID_BIT                          = 0,

    CORE_GARD_STARTBIT                              = 0,
    CORE_GARD_LENGTH                                = 32,
    GARD_VECTOR_STARTBIT                            = 0,

    CORE_GARD_EQ_MASK                               = 0xF,
    EQ_PG_MMA_SHIFT                                 = 5,
    EQ_PG_L3_SHIFT                                  = 11,
    EQ_PG_ECL2_SHIFT                                = 15,

    // Scratch_reg_2
    SCRATCH2_REG_VALID_BIT                          = 1,

    PCI_GARD_STARTBIT                               = 0,
    PCI_GARD_LENGTH                                 = 2,
    MC_GARD_STARTBIT                                = 4,
    MC_GARD_LENGTH                                  = 4,
    PAUC_GARD_STARTBIT                              = 8,
    PAUC_GARD_LENGTH                                = 4,
    PAU_GARD_STARTBIT                               = 12,
    PAU_GARD_LENGTH                                 = 8,
    IOHS_GARD_STARTBIT                              = 20,
    IOHS_GARD_LENGTH                                = 8,

    N1_PG_NMMU1_SHIFT                               = 14,
    PAU_GARD_PAUC_MASK                              = 0x3,
    PAUC_PG_PAU_SHIFT                               = 17,

    // Scratch_reg_3
    SCRATCH3_REG_VALID_BIT                          = 2,

    ATTR_BOOT_FLAGS_STARTBIT                        = 0,
    ATTR_BOOT_FLAGS_LENGTH                          = 32,

    // Scratch_reg_4
    SCRATCH4_REG_VALID_BIT                          = 3,

    ATTR_SPI_BUS_DIV_REF_STARTBIT                   = 0,
    ATTR_SPI_BUS_DIV_REF_LENGTH                     = 16,
    ATTR_FREQ_CORE_BOOT_MHZ_STARTBIT                = 16,
    ATTR_FREQ_CORE_BOOT_MHZ_LENGTH                  = 16,

    // Scratch_reg_5
    SCRATCH5_REG_VALID_BIT                          = 4,

    IPL_TYPE_STARTBIT                               = 0,
    IPL_TYPE_LENGTH                                 = 2,
    IPL_TYPE_HOSTBOOT                               = 0x0,
    IPL_TYPE_CACHE_CONTAINED                        = 0x1,
    IPL_TYPE_CHIP_CONTAINED                         = 0x2,

    ATTR_RUNN_MODE_BIT                              = 2,

    ATTR_DISABLE_HBBL_VECTORS_BIT                   = 3,

    ATTR_SBE_SELECT_EX_POLICY_STARTBIT              = 4,
    ATTR_SBE_SELECT_EX_POLICY_LENGTH                = 3,

    ATTR_CONTAINED_LOAD_PATH_BIT                    = 7,

    ATTR_CLOCKSTOP_ON_XSTOP_STARTBIT                = 10,
    ATTR_CLOCKSTOP_ON_XSTOP_LENGTH                  = 2,
    ATTR_CLOCKSTOP_ON_XSTOP_DISABLED                = 0x0,
    ATTR_CLOCKSTOP_ON_XSTOP_XSTOP                   = 0x1,
    ATTR_CLOCKSTOP_ON_XSTOP_XSTOP_SPATTN            = 0x2,
    ATTR_CLOCKSTOP_ON_XSTOP_STAGED_XSTOP            = 0x3,

    ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_STARTBIT        = 12,
    ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_LENGTH          = 2,

    ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_STARTBIT         = 28,
    ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_LENGTH           = 2,

    // Scratch_reg_6
    SCRATCH6_REG_VALID_BIT                          = 5,

    ATTR_FILTER_PLL_BUCKET_STARTBIT                 = 0,
    ATTR_FILTER_PLL_BUCKET_LENGTH                   = 2,
    ATTR_PCI_PLL_BUCKET_STARTBIT                    = 2,
    ATTR_PCI_PLL_BUCKET_LENGTH                      = 2,
    ATTR_SKEWADJ_BYPASS_BIT                         = 6,
    ATTR_DCADJ_BYPASS_BIT                           = 7,
    ATTR_CP_PLLTODFLT_BYPASS_BIT                    = 8,
    ATTR_CP_PLLNESTFLT_BYPASS_BIT                   = 9,
    ATTR_CP_PLLIOFLT_BYPASS_BIT                     = 10,
    ATTR_CP_PLLIOSSFLT_BYPASS_BIT                   = 11,
    ATTR_NEST_DPLL_BYPASS_BIT                       = 12,
    ATTR_PAU_DPLL_BYPASS_BIT                        = 13,
    ATTR_IO_TANK_PLL_BYPASS_BIT                     = 14,
    ATTR_BOOT_PAU_DPLL_BYPASS_BIT                   = 15,

    ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_STARTBIT       = 16,
    ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_LENGTH         = 4,
    ATTR_PROC_FABRIC_TOPOLOGY_MODE_BIT              = 20,
    ATTR_PROC_FABRIC_BROADCAST_MODE_STARTBIT        = 22,
    ATTR_PROC_FABRIC_BROADCAST_MODE_LENGTH          = 2,
    ATTR_PROC_SBE_MASTER_CHIP_BIT                   = 24,
    ATTR_CP_REFCLOCK_SELECT_STARTBIT                = 25,
    ATTR_CP_REFCLOCK_SELECT_LENGTH                  = 3,
    ATTR_PROC_FABRIC_TOPOLOGY_ID_STARTBIT           = 28,
    ATTR_PROC_FABRIC_TOPOLOGY_ID_LENGTH             = 4,

    // Scratch_reg_7
    SCRATCH7_REG_VALID_BIT                          = 6,

    ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC_STARTBIT   = 0,
    ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC_LENGTH     = 32,

    // Scratch_reg_9
    SCRATCH9_REG_VALID_BIT                          = 8,

    ATTR_FREQ_PAU_MHZ_STARTBIT                      = 0,
    ATTR_FREQ_PAU_MHZ_LENGTH                        = 16,
    ATTR_MC_PLL_BUCKET_STARTBIT                     = 16,
    ATTR_MC_PLL_BUCKET_LENGTH                       = 3,

    // Scratch_reg_10
    SCRATCH10_REG_VALID_BIT                         = 9,

    ATTR_IOHS_PLL_BUCKET_STARTBIT                   = 0,
    ATTR_IOHS_PLL_BUCKET_LENGTH                     = 4,

    ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC_STARTBIT = 0,
    ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC_LENGTH   = 32,

    // Scratch_reg_13
    SCRATCH13_REG_VALID_BIT                         = 12,

    ATTR_TPM_SPI_BUS_DIV_STARTBIT                   = 0,
    ATTR_TPM_SPI_BUS_DIV_LENGTH                     = 16,
};

struct p10_sbe_scratch_reg_id_t
{
    const uint8_t num;
    const uint64_t scom_addr;
    const uint32_t cfam_addr;
};

static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER1  = {  1, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER2  = {  2, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER3  = {  3, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER4  = {  4, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER5  = {  5, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER6  = {  6, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER7  = {  7, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER8  = {  8, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER9  = {  9, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_RW,  scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_FSI  };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER10 = { 10, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI };
static const p10_sbe_scratch_reg_id_t SCRATCH_REGISTER13 = { 13, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_13_RW, scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_13_FSI };


///
/// @brief Initialize SBE scratch registers based on platform attribute/
/// targeting model
///
/// @param[in] i_target       Reference to processor chip target
/// @param[in] i_update_all   True=Force all scratch registers to be updated
///                           (service processor/p10_setup_sbe_config usage)
///                           False=Update only if corresponding scratch valid
///                           is not asserted (SBE/p10_sbe_attr_setup usage)
/// @param[in] i_use_scom     True=perform all MBOX accesses via SCOM
///                           False=use CFAM
///
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_sbe_scratch_regs_update(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const bool i_update_all,
    const bool i_use_scom);


///
/// @brief Calculate functional unit target number from pervasive target type
///
/// @param[in]    i_target_perv  Pervasive target instance
/// @param[in]    i_type         Functional target type
///
/// @return uint8_t
///
uint8_t
p10_sbe_scratch_regs_get_unit_num(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_perv,
    const fapi2::TargetType i_type);


///
/// @brief Set all PLL BUCKET attributes
///
/// @param[in] i_target_chip          Processor chip target
///
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode
p10_sbe_scratch_regs_set_pll_buckets(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);

#endif // _P10_SBE_SCRATCH_REGS_H_
