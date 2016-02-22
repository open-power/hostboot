/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_pcie_config.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//-----------------------------------------------------------------------------------
///
/// @file p9_pcie_config.C
/// @brief Perform PCIE Phase2 init sequence (FAPI2)
///

// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_pcie_config.H>

#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_pcie_config(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    // Four BARs
    const uint8_t NUM_BAR = 4;

    uint64_t l_bar_address[NUM_BAR] = {0};
    uint64_t l_bar_mask[NUM_BAR] = {0};
    uint8_t l_bar_enable[NUM_BAR] = {0};

    fapi2::buffer<uint64_t> l_buf = 0;
    auto l_pec_chiplets_vec = i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL);
    auto l_phb_chiplets_vec = i_target.getChildren<fapi2::TARGET_TYPE_PHB>(fapi2::TARGET_STATE_FUNCTIONAL);
    FAPI_DBG("pec target vec size: %#x\n", l_pec_chiplets_vec.size());
    FAPI_DBG("phb target vec size: %#x\n", l_phb_chiplets_vec.size());
    unsigned char l_pec_id = 0;
    unsigned char l_phb_id = 0;

    for (auto l_pec_chiplets : l_pec_chiplets_vec)
    {
        // Get the pec id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pec_chiplets,
                               l_pec_id));

        // Phase2 init step 1
        // NestBase+0x00
        // Set bits 00:03 = 0b0001Set hang poll scale
        // Set bits             04:07 = 0b0010 Set data scale
        // Set bits 08:11 = 0b0001 Set hang pe scale
        // Set bit 22 = 0b1 Disable out-of-order store behavior
        FAPI_TRY(fapi2::getScom(l_pec_chiplets, PEC_PBCQHWCFG_REG, l_buf));
        l_buf.insertFromRight<PEC_PBCQHWCFG_REG_HANG_POLL_SCALE, PEC_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(0x1);
        l_buf.insertFromRight<PEC_PBCQHWCFG_REG_HANG_DATA_SCALE, PEC_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(0x2);
        l_buf.insertFromRight<PEC_PBCQHWCFG_REG_HANG_PE_SCALE, PEC_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(0x1);
        l_buf.insertFromRight<PEC_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE, 1>(0x1);
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PBCQHWCFG_REG, l_buf));

        // Phase2 init step 2
        // NestBase+0x01
        // N/A Modify Drop Priority Control Register (DrPriCtl)

        // Phase2 init step 3
        // NestBase+0x03
        // Set bits 00:03 = 0b1001 Enable trace, and select
        // Inbound operations with addr information
        FAPI_TRY(fapi2::getScom(l_pec_chiplets, PEC_NESTTRC_REG, l_buf));
        // TODO: no register bit field defined.
        l_buf.insertFromRight<0, 4>(0x9);
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_NESTTRC_REG, l_buf));

        // Phase2 init step 4
        // NestBase+0x05
        // N/A For use of atomics/asb_notify

        // Phase2 init step 5
        // NestBase+0x06
        // N/A To override scope prediction

        // Phase2 init step 6
        // PCIBase +0x00
        // Set bits 30 = 0b1 Enable Trace
        l_buf = 0;
        l_buf.setBit<PEC_PBAIBHWCFG_REG_PE_PCIE_CLK_TRACE_EN>();
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PBAIBHWCFG_REG, l_buf));
    }

    for (auto l_phb_chiplets : l_phb_chiplets_vec)
    {
        // Get the pec id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_phb_chiplets,
                               l_phb_id));
        // Phase2 init step 7_a
        // NestBase+StackBase+0xA
        // 0x00000000_00000000
        // Clear any spurious cerr_rpt0 bits (cerr_rpt0)
        // TODO: HW363246 this step appears in the v1.0 doc but failed PCB address
        // error in model e9034
        //l_buf = (uint64_t)0x0;
        //FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        //FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_CERR_RPT0_REG, l_buf));

        // Phase2 init step 7_b
        // NestBase+StackBase+0xB
        // 0x00000000_00000000
        // Clear any spurious cerr_rpt1 bits (cerr_rpt1)
        // TODO: HW363246 this step appears in the v1.0 doc but failed PCB address
        // error in model e9034
        //l_buf = (uint64_t)0x0;
        //FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        //FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_CERR_RPT1_REG, l_buf));

        // Phase2 init step 7_c
        // NestBase+StackBase+0x0
        // 0x00000000_00000000
        // Clear any spurious FIR
        // bits (NFIR)NFIR
        l_buf = (uint64_t)0x0;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_NFIR_REG, l_buf));

        // Phase2 init step 8
        // NestBase+StackBase+0x8
        // 0x00000000_00000000
        // Clear any spurious WOF
        // bits (NFIRWOF)
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_NFIRWOF_REG, l_buf));

        // Phase2 init step 9
        // NestBase+StackBase+0x6
        // 0x5B0F8190_00000000
        // Set the per FIR Bit Action 0 register
        l_buf = 0x5B0F819000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_NFIRACTION0_REG, l_buf));

        // Phase2 init step 10
        // NestBase+StackBase+0x7
        // 0x7F0F8190_00000000
        // Set the per FIR Bit Action 1 register
        l_buf = 0x7F0F819000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_NFIRACTION1_REG, l_buf));

        // Phase2 init step 11
        // NestBase+StackBase+0x3
        // 0x00000000_00000000
        // Set FIR Mask Bits to allow errors (NFIRMask)
        l_buf = 0x0000000000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_NFIRMASK_REG, l_buf));

        // Phase2 init step 12
        // NestBase+StackBase+0x15
        // 0x00000000_00000000
        // Set Data Freeze Type Register for SUE handling (DFREEZE)
        l_buf = 0x0000000000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PE_DFREEZE_REG, l_buf));

        // Phase2 init step 13_a
        // PCIBase+StackBase+0xB
        // 0x00000000_00000000
        // Clear any spurious pbaib_cerr_rpt bits
        l_buf = (uint64_t)0x0;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PFIR_REG, l_buf));

        // Phase2 init step 13_b
        // PCIBase+StackBase+0x0
        // 0x00000000_00000000
        // Clear any spurious FIR
        // bits (PFIR)PFIR
        l_buf = (uint64_t)0x0;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PBAIB_CERR_RPT_REG, l_buf));

        // Phase2 init step 14
        // PCIBase+StackBase+0x8
        // 0x00000000_00000000
        // Clear any spurious WOF
        // bits (PFIRWOF)
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PFIRWOF_REG, l_buf));

        // Phase2 init step 15
        // PCIBase+StackBase+0x6
        // 0x5B0F8190_00000000
        // Set the per FIR Bit Action 0 register
        l_buf = 0x5B0F819000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PFIRACTION0_REG, l_buf));

        // Phase2 init step 16
        // PCIBase+StackBase+0x7
        // 0x7F0F8190_00000000
        // Set the per FIR Bit Action 1 register
        l_buf = 0x7F0F819000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PFIRACTION1_REG, l_buf));

        // Phase2 init step 17
        // PCIBase+StackBase+0x3
        // 0x00000000_00000000
        // Set FIR Mask Bits to allow errors (PFIRMask)
        l_buf = 0x0000000000000000;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PFIRMASK_REG, l_buf));

        // Get the attribute for BAR address and size.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_BAR_BASE_ADDR, l_phb_chiplets,
                               l_bar_address));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_BAR_SIZE, l_phb_chiplets,
                               l_bar_mask));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_BAR_ENABLE, l_phb_chiplets,
                               l_bar_enable));

        // step 18: NestBase+StackBase+0xE<software programmed>Set MMIO Base
        // Address Register 0 (MMIOBAR0)
        FAPI_DBG("phb%i bar0 addr: %#lx", l_phb_id, l_bar_address[0]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_MMIOBAR0_REG, l_bar_address[0]));

        // step 19: NestBase+StackBase+0xF<software programmed>Set MMIO BASE
        // Address Register Mask 0 (MMIOBAR0_MASK)
        FAPI_DBG("phb%i bar0 mask: %#lx", l_phb_id, l_bar_mask[0]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_MMIOBAR0_MASK_REG, l_bar_mask[0]));

        // step 20: NestBase+StackBase+0x10<software programmed>Set MMIO Base
        // Address Register 1 (MMIOBAR1)
        FAPI_DBG("phb%i bar1 addr: %#lx", l_phb_id, l_bar_address[1]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_MMIOBAR1_REG, l_bar_address[1]));

        // step 21: NestBase+StackBase+0x11<software programmed>Set MMIO Base
        // Address Register Mask 1 (MMIOBAR1_MASK)
        FAPI_DBG("phb%i bar1 mask: %#lx", l_phb_id, l_bar_mask[1]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_MMIOBAR1_MASK_REG, l_bar_mask[1]));

        // step 22: NestBase+StackBase+0x12<software programmed>Set PHB
        // Regsiter Base address Register (PHBBAR)
        FAPI_DBG("phb%i phb addr: %#lx", l_phb_id, l_bar_address[2]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PHBBAR_REG, l_bar_address[2]));

        // step 23: NestBase+StackBase+0x13<software programmed>Set Interrupt
        // BASEase Address Register (INTBAR)
        FAPI_DBG("phb%i int addr: %#lx", l_phb_id, l_bar_address[3]);
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_INTBAR_REG, l_bar_address[3]));

        // step 24: NestBase+StackBase+0x14<software programmed>Set Base
        // addressress Enable Register (BARE)
        l_buf = (uint64_t)0x0;
        l_buf.insertFromRight<PHB_BARE_REG_PE_MMIO_BAR0_EN, 1>(l_bar_enable[0]); // bit 0 for BAR0
        l_buf.insertFromRight<PHB_BARE_REG_PE_MMIO_BAR1_EN, 1>(l_bar_enable[1]); // bit 1 for BAR1
        l_buf.insertFromRight<PHB_BARE_REG_PE_PHB_BAR_EN, 1>(l_bar_enable[2]); // bit 2 for PHB
        l_buf.insertFromRight<PHB_BARE_REG_PE_INT_BAR_EN, 1>(l_bar_enable[3]); // bit 3 for INT
        FAPI_DBG("phb%i bar enable: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_BARE_REG, l_buf));

        // Phase2 init step 25
        // PCIBase+StackBase +0x0A
        // 0x00000000_00000000
        // Remove ETU/AIB bus from reset (PHBReset)
        l_buf = (uint64_t)0x0;
        FAPI_DBG("phb%i: %#lx", l_phb_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_phb_chiplets, PHB_PHBRESET_REG, l_buf));
    }

    FAPI_INF("End");

fapi_try_exit:
    return fapi2::current_err;
}
