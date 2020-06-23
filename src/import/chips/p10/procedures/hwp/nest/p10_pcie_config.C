/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_config.C $  */
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
/// @file p10_pcie_config.C
/// @brief Perform SCOM initialization required for PEC operation.
///
/// *HWP HW Maintainer : Ricardo Mata Jr. (ricmata@us.ibm.com)
/// *HWP FW Maintainer : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by   : HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pcie_config.H>
#include <p10_fbc_utils.H>

#include <p10_scom_pec.H>
#include <p10_scom_phb.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint8_t NUM_STACK_CONFIG = 3;

// PCI MMIO BAR Register contstants
const uint8_t P10_PCIE_CONFIG_BAR_SHIFT = 8;

// Nest FIR Register constants
const uint64_t NFIR_ACTION0_REG = 0x5B0F81E000000000ULL;
const uint64_t NFIR_ACTION1_REG = 0x7F0F81E000000000ULL;
const uint64_t NFIR_MASK_REG    = 0x0030001C00000000ULL;

// PCI PBCQ Hardware Configuration Register field definitions
const uint8_t PBCQ_HWCFG_HANG_POLL_SCALE = 0x0;
const uint8_t PBCQ_HWCFG_DATA_POLL_SCALE = 0x2;
const uint8_t PBCQ_HWCFG_HANG_PE_SCALE = 0x1;
const uint8_t PBCQ_HWCFG_CACHE_INJ_MODE = 0x3;
const uint8_t PBCQ_HWCFG_CACHE_INJ_RATE = 0x3;

// PCI Nest Trace Control Register field definitions
const uint8_t PBCQ_NESTTRC_SEL_A = 0x9;

// PCI FIR Register constants
const uint64_t PFIR_ACTION0_REG = 0xB000000000000000ULL;
const uint64_t PFIR_ACTION1_REG = 0xB000000000000000ULL;
const uint64_t PFIR_MASK_REG    = 0x0E00000000000000ULL;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Configures fabric mode registers
/// @param[in] i_target       Reference to pec chip target
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_pcie_config(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    using namespace scomt;
    using namespace scomt::pec;
    using namespace scomt::phb;

    FAPI_DBG("Entering ...");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_PCIE_MMIO_BAR0_BASE_ADDR_OFFSET_Type l_mmio_bar0_offsets;
    fapi2::ATTR_PROC_PCIE_MMIO_BAR1_BASE_ADDR_OFFSET_Type l_mmio_bar1_offsets;
    fapi2::ATTR_PROC_PCIE_PHB_REGISTER_BASE_ADDR_OFFSET_Type l_phb_register_bar_offsets;
    fapi2::ATTR_PROC_PCIE_BAR_SIZE_Type l_bar_sizes;

    fapi2::buffer<uint64_t> l_scom_data;
    fapi2::buffer<uint64_t> l_data_zeroes;
    fapi2::buffer<uint64_t> l_data_ones;
    std::vector<uint64_t> l_topo_table_scom_values;
    l_data_zeroes.flush<0>();
    l_data_ones.flush<1>();
    uint64_t l_base_addr_nm0;
    uint64_t l_base_addr_nm1;
    uint64_t l_base_addr_m;
    uint64_t l_base_addr_mmio;
    uint8_t  l_attr_proc_pcie_phb_active[NUM_STACK_CONFIG] = {0};
    uint8_t  l_pec_id = 0;

    auto l_pec_chiplets_vec = i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL);
    auto l_phb_chiplets_vec = i_target.getChildren<fapi2::TARGET_TYPE_PHB>(fapi2::TARGET_STATE_FUNCTIONAL);
    FAPI_DBG("PEC target vector size: %#x\n", l_pec_chiplets_vec.size());
    FAPI_DBG("PHB target vector size: %#x\n", l_phb_chiplets_vec.size());

    // read system level BAR MMIO offset/size attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_MMIO_BAR0_BASE_ADDR_OFFSET, FAPI_SYSTEM, l_mmio_bar0_offsets),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_MMIO_BAR0_BASE_ADDR_OFFSET)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_MMIO_BAR1_BASE_ADDR_OFFSET, FAPI_SYSTEM, l_mmio_bar1_offsets),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_MMIO_BAR1_BASE_ADDR_OFFSET)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PHB_REGISTER_BASE_ADDR_OFFSET, FAPI_SYSTEM, l_phb_register_bar_offsets),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_PHB_REGISTER_BASE_ADDR_OFFSET)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_BAR_SIZE, FAPI_SYSTEM, l_bar_sizes),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_BAR_SIZE)");

    // determine base address of chip nm/m/mmio regions in real address space
    FAPI_TRY(p10_fbc_utils_get_chip_base_address(
                 i_target,
                 EFF_TOPOLOGY_ID,
                 l_base_addr_nm0,
                 l_base_addr_nm1,
                 l_base_addr_m,
                 l_base_addr_mmio),
             "Error from p10_fbc_utils_get_chip_base_address");


    // PHASE2.1: PBCQ INITIALIZATION SEQUENCE
    // initialize functional PEC chiplets
    for (auto l_pec_chiplet : l_pec_chiplets_vec)
    {
        // Get the PEC unit id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pec_chiplet, l_pec_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        // Grab the IOVALID attribute to determine if PEC is bifurcated or not.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PHB_ACTIVE, l_pec_chiplet, l_attr_proc_pcie_phb_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_PHB_ACTIVE");
        FAPI_DBG("l_attr_proc_pcie_phb_active 0x%.0x", l_attr_proc_pcie_phb_active);


        // Phase2 init step 1
        // NestBase+0x00
        // Set bits 00:03 = 0b0001 Set hang poll scale
        // Set bits 04:07 = 0b0001 Set data scale
        // Set bits 08:11 = 0b0001 Set hang pe scale
        // Set bit 22 = 0b1 Disable out­of­order store behavior
        // Set bit 33 = 0b1 Enable Channel Tag streaming behavior
        // Set bits 34:35 = 0b11 Set P9 Style cache-inject behavior
        // Set bit 60 = 0b1 only if PEC is bifurcated or trifurcated.
        l_scom_data = 0;
        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(l_pec_chiplet),
                 "Error from PREP_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG");

        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(PBCQ_HWCFG_HANG_POLL_SCALE, l_scom_data);
        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(PBCQ_HWCFG_DATA_POLL_SCALE, l_scom_data);
        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(PBCQ_HWCFG_HANG_PE_SCALE, l_scom_data);
        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(l_scom_data);
        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(l_scom_data);
        SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(PBCQ_HWCFG_CACHE_INJ_MODE, l_scom_data);

        if ((l_attr_proc_pcie_phb_active[1] == fapi2::ENUM_ATTR_PROC_PCIE_PHB_ACTIVE_ENABLE)
            || (l_attr_proc_pcie_phb_active[2] == fapi2::ENUM_ATTR_PROC_PCIE_PHB_ACTIVE_ENABLE))
        {
            SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(l_scom_data);
        }

        FAPI_DBG("PEC%i: %#lx - %#lx", l_pec_id, PB_PBCQ_PEPBREGS_PBCQHWCFG_REG, l_scom_data());
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(l_pec_chiplet, l_scom_data),
                 "Error from PUT_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG");

        // Phase2 init step 2
        // NestBase+0x01
        // N/A Modify Drop Priority Control Register (DrPriCtl)

        // Phase2 init step 3
        // NestBase+0x03
        // Set bits 00:03 = 0b1001 Enable trace, and select
        // Inbound operations with addr information
        l_scom_data = 0;
        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_NESTTRC_REG(l_pec_chiplet),
                 "Error from PREP_PB_PBCQ_PEPBREGS_NESTTRC_REG");
        SET_PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A(PBCQ_NESTTRC_SEL_A, l_scom_data);
        FAPI_DBG("PEC%i: %#lx - %#lx", l_pec_id, PB_PBCQ_PEPBREGS_NESTTRC_REG, l_scom_data());
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_NESTTRC_REG(l_pec_chiplet, l_scom_data),
                 "Error from PUT_PB_PBCQ_PEPBREGS_NESTTRC_REG");

        // Phase2 init step 4
        // NestBase+0x05
        // N/A For use of atomics/asb_notify

        // Phase2 init step 5
        // NestBase+0x06
        // N/A To override scope prediction

        // Phase2 init step 6
        // PCIBase +0x00
        // Set bits 30 = 0b1 Enable Trace
        l_scom_data = 0;
        FAPI_TRY(PREP_PB_PBAIB_REGS_PBAIBHWCFG_REG(l_pec_chiplet), "Error from PREP_PB_PBAIB_REGS_PBAIBHWCFG_REG");
        SET_PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_PCIE_CLK_TRACE_EN(l_scom_data);
        FAPI_DBG("PEC%i: %#lx - %#lx", l_pec_id, PB_PBAIB_REGS_PBAIBHWCFG_REG, l_scom_data());
        FAPI_TRY(PUT_PB_PBAIB_REGS_PBAIBHWCFG_REG(l_pec_chiplet, l_scom_data),
                 "Error from PUT_PB_PBAIB_REGS_PBAIBHWCFG_REG");

        //Set topology id table
        FAPI_TRY(topo::get_topology_table_scoms(i_target, l_topo_table_scom_values),
                 "Error forming topology ID table scom data");

        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0(l_pec_chiplet));
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0(l_pec_chiplet, l_topo_table_scom_values[0]));

        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG1(l_pec_chiplet));
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG1(l_pec_chiplet, l_topo_table_scom_values[1]));

        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(l_pec_chiplet));
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(l_pec_chiplet, l_topo_table_scom_values[2]));

        FAPI_TRY(PREP_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3(l_pec_chiplet));
        FAPI_TRY(PUT_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3(l_pec_chiplet, l_topo_table_scom_values[3]));

    }

    // initialize functional PHB chiplets
    for (auto l_phb_chiplet : l_phb_chiplets_vec)
    {
        fapi2::ATTR_PROC_PCIE_BAR_ENABLE_Type l_bar_enables;
        fapi2::buffer<uint64_t> l_mmio0_bar = l_base_addr_mmio;
        fapi2::buffer<uint64_t> l_mmio1_bar = l_base_addr_mmio;
        fapi2::buffer<uint64_t> l_phb_register_bar = l_base_addr_mmio;
        uint8_t l_phb_id = 0;

        // Get the PHB id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_phb_chiplet, l_phb_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        // Phase2 init step 7_a
        // NestBase+StackBase+0xA
        // 0xFFFFFFFF_FFFFFFFF
        // Clear any spurious cerr_rpt0 bits (cerr_rpt0)
        FAPI_TRY(PREP_REGS_CERR_RPT0_REG(l_phb_chiplet),
                 "Error from PREP_REGS_CERR_RPT0_REG");
        FAPI_TRY(PUT_REGS_CERR_RPT0_REG(l_phb_chiplet, l_data_ones),
                 "Error from PUT_REGS_CERR_RPT0_REG");

        // Phase2 init step 7_b
        // NestBase+StackBase+0xB
        // 0xFFFFFFFF_FFFFFFFF
        // Clear any spurious cerr_rpt1 bits (cerr_rpt1)
        FAPI_TRY(PREP_REGS_CERR_RPT1_REG(l_phb_chiplet),
                 "Error from PREP_REGS_CERR_RPT1_REG");
        FAPI_TRY(PUT_REGS_CERR_RPT1_REG(l_phb_chiplet, l_data_ones),
                 "Error from PUT_REGS_CERR_RPT1_REG");

        // Phase2 init step 7_c
        // NestBase+StackBase+0x0
        // 0x00000000_00000000
        // Clear any spurious FIR
        // bits (NFIR)NFIR
        FAPI_TRY(PREP_REGS_NFIR_REG_RW(l_phb_chiplet),
                 "Error from PREP_REGS_NFIR_REG_RW");
        FAPI_TRY(PUT_REGS_NFIR_REG_RW(l_phb_chiplet, l_data_zeroes),
                 "Error from PUT_REGS_NFIR_REG_RW");

        // Phase2 init step 8
        // NestBase+StackBase+0x8
        // 0x00000000_00000000
        // Clear any spurious WOF
        // bits (NFIRWOF)
        FAPI_TRY(PREP_REGS_NFIRWOF_REG(l_phb_chiplet),
                 "Error from PREP_REGS_NFIRWOF_REG");
        FAPI_TRY(PUT_REGS_NFIRWOF_REG(l_phb_chiplet, l_data_zeroes),
                 "Error from PUT_REGS_NFIRWOF_REG");

        // Phase2 init step 9
        // NestBase+StackBase+0x6
        // Set the per FIR Bit Action 0 register
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_NFIRACTION0_REG(l_phb_chiplet),
                 "Error from PREP_REGS_NFIRACTION0_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_NFIRACTION0_REG, NFIR_ACTION0_REG);
        FAPI_TRY(PUT_REGS_NFIRACTION0_REG(l_phb_chiplet, NFIR_ACTION0_REG),
                 "Error from PUT_REGS_NFIRACTION0_REG");

        // Phase2 init step 10
        // NestBase+StackBase+0x7
        // Set the per FIR Bit Action 1 register
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_NFIRACTION1_REG(l_phb_chiplet),
                 "Error from PREP_REGS_NFIRACTION1_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_NFIRACTION1_REG, NFIR_ACTION1_REG);
        FAPI_TRY(PUT_REGS_NFIRACTION1_REG(l_phb_chiplet, NFIR_ACTION1_REG),
                 "Error from PUT_REGS_NFIRACTION1_REG");

        // Phase2 init step 11
        // NestBase+StackBase+0x3
        // Set FIR Mask Bits to allow errors (NFIRMask)
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_NFIRMASK_REG_RW(l_phb_chiplet),
                 "Error from REGS_NFIRMASK_REG_RW");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_NFIRMASK_REG_RW, NFIR_MASK_REG);
        FAPI_TRY(PUT_REGS_NFIRMASK_REG_RW(l_phb_chiplet, NFIR_MASK_REG),
                 "Error from PUT_REGS_NFIRMASK_REG_RW");

        // Phase2 init step 12a
        // NestBase+StackBase+0x15
        // 0x00000000_00000000
        // Set Data Freeze Type Register for SUE handling (DFREEZE)
        FAPI_TRY(PREP_REGS_PE_DFREEZE_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PE_DFREEZE_REG");
        FAPI_TRY(PUT_REGS_PE_DFREEZE_REG(l_phb_chiplet, l_data_zeroes),
                 "Error from PUT_REGS_PE_DFREEZE_REG");

        // Phase2 init step 12_b
        // NestBase+StackBase+0x17
        // Set Enable cache inject for partial writes.
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PE_CACHE_INJECT_CNTL_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PE_CACHE_INJECT_CNTL_REG");
        SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(l_scom_data);
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_PE_CACHE_INJECT_CNTL_REG, l_scom_data());
        FAPI_TRY(PUT_REGS_PE_CACHE_INJECT_CNTL_REG(l_phb_chiplet, l_scom_data),
                 "Error from PUT_REGS_PE_CACHE_INJECT_CNTL_REG");

        //Phase2 init step 13_a
        //PCIBase+StackBase+0xB
        // 0x00000000_00000000
        // Clear any spurious pbaib_cerr_rpt_bits
        FAPI_TRY(PREP_REGS_PBAIB_CERR_RPT_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PBAIB_CERR_RPT_REG");
        FAPI_TRY(PUT_REGS_PBAIB_CERR_RPT_REG(l_phb_chiplet, l_data_zeroes),
                 "Error from PUT_REGS_PBAIB_CERR_RPT_REG");

        // Phase2 init step 14
        // PCIBase+StackBase+0x8
        // 0x00000000_00000000
        // Clear any spurious WOF
        // bits (PFIRWOF)
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PFIRWOF_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PFIRWOF_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_PFIRWOF_REG, l_scom_data());
        FAPI_TRY(PUT_REGS_PFIRWOF_REG(l_phb_chiplet, l_data_zeroes),
                 "Error from PUT_REGS_PFIRWOF_REG");

        // Phase2 init step 15
        // PCIBase+StackBase+0x6
        // Set the per FIR Bit Action 0 register
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PFIRACTION0_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PFIRACTION0_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_PFIRACTION0_REG, PFIR_ACTION0_REG);
        FAPI_TRY(PUT_REGS_PFIRACTION0_REG(l_phb_chiplet, PFIR_ACTION0_REG),
                 "Error from PUT_REGS_PFIRACTION0_REG");

        // Phase2 init step 16
        // PCIBase+StackBase+0x7
        // Set the per FIR Bit Action 1 register
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PFIRACTION1_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PFIRACTION1_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_PFIRACTION1_REG, PFIR_ACTION1_REG);
        FAPI_TRY(PUT_REGS_PFIRACTION1_REG(l_phb_chiplet, PFIR_ACTION1_REG),
                 "Error from PUT_REGS_PFIRACTION1_REG");

        // Phase2 init step 17
        // PCIBase+StackBase+0x3
        // Set FIR Mask Bits to allow errors (PFIRMask)
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PFIRMASK_REG_RW(l_phb_chiplet),
                 "Error from PREP_REGS_PFIRMASK_REG_RW");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_PFIRMASK_REG_RW, PFIR_MASK_REG);
        FAPI_TRY(PUT_REGS_PFIRMASK_REG_RW(l_phb_chiplet, PFIR_MASK_REG),
                 "Error from PUT_REGS_PFIRMASK_REG_RW");

        // PHASE2.2: PBCQ INITIALIZATION SEQUENCE
        // Get the BAR enable attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_BAR_ENABLE, l_phb_chiplet, l_bar_enables),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_BAR_ENABLE)");

        // step 18: NestBase+StackBase+0xE>Set MMIO Base
        // Address Register 0 (MMIOBAR0)
        l_mmio0_bar += l_mmio_bar0_offsets[l_phb_id];
        FAPI_DBG("PHB%i bar0 addr: %#lx", l_phb_id, l_mmio0_bar());
        l_mmio0_bar = l_mmio0_bar << P10_PCIE_CONFIG_BAR_SHIFT;
        FAPI_TRY(PREP_REGS_MMIOBAR0_REG(l_phb_chiplet),
                 "Error from PREP_REGS_MMIOBAR0_REG");
        FAPI_TRY(PUT_REGS_MMIOBAR0_REG(l_phb_chiplet, l_mmio0_bar),
                 "Error from PUT_REGS_MMIOBAR0_REG");

        // step 19: NestBase+StackBase+0xF Set MMIO BASE
        // Address Register Mask 0 (MMIOBAR0_MASK)
        FAPI_DBG("PHB%i bar0 size: %#lx", l_phb_id, l_bar_sizes[0]);
        FAPI_TRY(PREP_REGS_MMIOBAR0_MASK_REG(l_phb_chiplet),
                 "Error from PREP_REGS_MMIOBAR0_MASK_REG");
        FAPI_TRY(PUT_REGS_MMIOBAR0_MASK_REG(l_phb_chiplet, l_bar_sizes[0]),
                 "Error from PUT_REGS_MMIOBAR0_MASK_REG");

        // step 20: NestBase+StackBase+0x10 Set MMIO Base
        // Address Register 1 (MMIOBAR1)
        l_mmio1_bar += l_mmio_bar1_offsets[l_phb_id];
        FAPI_DBG("PHB%i bar1 addr: %#lx", l_phb_id, l_mmio1_bar());
        l_mmio1_bar = l_mmio1_bar << P10_PCIE_CONFIG_BAR_SHIFT;
        FAPI_TRY(PREP_REGS_MMIOBAR1_REG(l_phb_chiplet),
                 "Error from PREP_REGS_MMIOBAR1_REG");
        FAPI_TRY(PUT_REGS_MMIOBAR1_REG(l_phb_chiplet, l_mmio1_bar),
                 "Error from PUT_REGS_MMIOBAR1_REG");

        // step 21: NestBase+StackBase+0x11 Set MMIO Base
        // Address Register Mask 1 (MMIOBAR1_MASK)
        FAPI_DBG("PHB%i bar1 size: %#lx", l_phb_id, l_bar_sizes[1]);
        FAPI_TRY(PREP_REGS_MMIOBAR1_MASK_REG(l_phb_chiplet),
                 "Error from PREP_REGS_MMIOBAR1_MASK_REG");
        FAPI_TRY(PUT_REGS_MMIOBAR1_MASK_REG(l_phb_chiplet, l_bar_sizes[1]),
                 "Error from PUT_REGS_MMIOBAR1_MASK_REG");

        // step 22: NestBase+StackBase+0x12 Set PHB
        // Regsiter Base address Register (PHBBAR)
        l_phb_register_bar += l_phb_register_bar_offsets[l_phb_id];
        FAPI_DBG("PHB%i bar1 addr: %#lx", l_phb_id, l_phb_register_bar());
        l_phb_register_bar = l_phb_register_bar << P10_PCIE_CONFIG_BAR_SHIFT;
        FAPI_TRY(PREP_REGS_PHBBAR_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PHBBAR_REG");
        FAPI_TRY(PUT_REGS_PHBBAR_REG(l_phb_chiplet, l_phb_register_bar),
                 "Error from PUT_REGS_PHBBAR_REG");

        // step 23: NestBase+StackBase+0x14 Set Base
        // address Enable Register (BARE)
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_BARE_REG(l_phb_chiplet),
                 "Error from PREP_REGS_BARE_REG");

        if (l_bar_enables[0])
        {
            SET_REGS_BARE_REG_MMIO_BAR0_EN(l_scom_data); // bit 0 for BAR0
        }

        if (l_bar_enables[1])
        {
            SET_REGS_BARE_REG_MMIO_BAR1_EN(l_scom_data); // bit 1 for BAR1
        }

        if (l_bar_enables[2])
        {
            SET_REGS_BARE_REG_PHB_BAR_EN(l_scom_data); // bit 2 for PHB
        }

        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, REGS_BARE_REG, l_scom_data());
        FAPI_TRY(PUT_REGS_BARE_REG(l_phb_chiplet, l_scom_data),
                 "Error from PUT_REGS_BARE_REG");

        // Phase2 init step 24
        // PCIBase+StackBase +0x0A
        // 0x00000000_00000000
        // Remove ETU/AIB bus from reset (PHBReset)
        l_scom_data = 0;
        FAPI_TRY(PREP_REGS_PHBRESET_REG(l_phb_chiplet),
                 "Error from PREP_REGS_PHBRESET_REG");
        CLEAR_REGS_PHBRESET_REG_PE_ETU_RESET(l_scom_data);
        FAPI_TRY(PUT_REGS_PHBRESET_REG(l_phb_chiplet, l_scom_data),
                 "Error from PUT_REGS_PHBRESET_REG");

        // Configure ETU FIR (all masked)
        l_scom_data = 0;
        FAPI_TRY(PREP_RSB_REGS_ACT0_REG(l_phb_chiplet),
                 "Error from PREP_RSB_REGS_ACT0_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, RSB_REGS_ACT0_REG, l_scom_data());
        FAPI_TRY(PUT_RSB_REGS_ACT0_REG(l_phb_chiplet, l_scom_data),
                 "Error from PUT_RSB_REGS_ACT0_REG");

        l_scom_data = 0;
        FAPI_TRY(PREP_RSB_REGS_ACTION1_REG(l_phb_chiplet),
                 "Error from PREP_RSB_REGS_ACTION1_REG");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, RSB_REGS_ACTION1_REG, l_scom_data());
        FAPI_TRY(PUT_RSB_REGS_ACTION1_REG(l_phb_chiplet, l_scom_data),
                 "Error from PUT_RSB_REGS_ACTION1_REG");

        l_scom_data = 0;
        FAPI_TRY(PREP_RSB_REGS_MASK_REG_RW(l_phb_chiplet),
                 "Error from PREP_RSB_REGS_MASK_REG_RW");
        FAPI_DBG("PHB%i: %#lx - %#lx", l_phb_id, RSB_REGS_MASK_REG_RW, l_scom_data());
        FAPI_TRY(PUT_RSB_REGS_MASK_REG_RW(l_phb_chiplet, l_data_ones),
                 "Error from PUT_RSB_REGS_MASK_REG_RW");
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;

}
