/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_pcie_scominit.C $             */
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
/// @file p9_pcie_scominit.C
/// @brief Perform PCIE Phase1 init sequence (FAPI2)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_pcie_scominit.H>

#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fixes.H>
#include <p9_misc_scom_addresses_fld.H>

/// @brief This function configures a buffer with respect to different pec id
///
/// @param[in]         in_target The target
/// @param[in/out]     io_buf  The buffer
/// @param[in]         in_pec_id The PEC id
/// @param[in]         in_attr The attribute value to be set
/// @param[in]         in_pec_id The PEC id
/// @param[in]         in_pec[0-2]_s The start bit for pec[0-2]
/// @param[in]         in_pec[0-2]_c The bit count for pec[0-2]
//
/// @return  FAPI2_RC_SUCCESS if success, else error code.

fapi2::ReturnCode set_buf(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& in_target,
                          fapi2::buffer<uint64_t>& io_buf,
                          const int in_pec_id, const uint8_t in_attr,
                          const uint32_t in_pec0_s, const uint32_t in_pec0_c,
                          const uint32_t in_pec1_s, const uint32_t in_pec1_c,
                          const uint32_t in_pec2_s, const uint32_t in_pec2_c)
{
    switch(in_pec_id)
    {
        case 0:
            FAPI_TRY(io_buf.insertFromRight(in_attr, in_pec0_s, in_pec0_c));
            break;

        case 1:
            FAPI_TRY(io_buf.insertFromRight(in_attr, in_pec1_s, in_pec1_c));
            break;

        case 2:
            FAPI_TRY(io_buf.insertFromRight(in_attr, in_pec2_s, in_pec2_c));
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P9_PCIE_SCOMINIT_PECID_ERROR().set_TARGET(in_target),
                        "Unknown PEC ID: %i!", in_pec_id);
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_pcie_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    uint8_t l_attr_proc_pcie_iop_config = 0;
    uint8_t l_attr_proc_pcie_iop_swap = 0;
    uint8_t l_attr_proc_pcie_iovalid_enable = 0;
    fapi2::buffer<uint64_t> l_buf = 0;
    unsigned char l_pec_id = 0;
    auto l_pec_chiplets_vec = i_target.getChildren<fapi2::TARGET_TYPE_PEC>();
    uint32_t l_pcs_config_mode[NUM_PCS_CONFIG] = {PCS_CONFIG_MODE0, PCS_CONFIG_MODE1, PCS_CONFIG_MODE2, PCS_CONFIG_MODE3};
    uint8_t l_pcs_cdr_gain[NUM_PCS_CONFIG] = {0};
    uint16_t l_pcs_loff_control[NUM_PCS_CONFIG] = {0};
    uint16_t l_pcs_vga_control_register3[NUM_PCS_CONFIG] = {0};
    uint16_t l_pcs_m_cntl[NUM_M_CONFIG] = {0};
    uint8_t l_pcs_rot_cntl_cdr_lookahead = 0;
    uint8_t l_pcs_rot_cntl_cdr_ssc = 0;
    uint8_t l_attr_8 = 0;
    uint16_t l_attr_16 = 0;

    FAPI_DBG("target vec size: %#x", l_pec_chiplets_vec.size());
    FAPI_DBG("l_buf: %#x", l_buf());

    for (auto l_pec_chiplets : l_pec_chiplets_vec)
    {
        // Get the pec id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pec_chiplets,
                               l_pec_id));

        // Phase1 init step 1 (get VPD, no operation here)

        // Phase1 init step 2a
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_IOP_CONFIG, l_pec_chiplets,
                               l_attr_proc_pcie_iop_config));
        FAPI_DBG("attr_proc_pcie_iop_config: %#x", l_attr_proc_pcie_iop_config);
        l_buf = 0;
        FAPI_TRY(set_buf(i_target, l_buf, l_pec_id, l_attr_proc_pcie_iop_config,
                         PEC0_IOP_CONFIG_START_BIT, PEC0_IOP_BIT_COUNT * 2,
                         PEC1_IOP_CONFIG_START_BIT, PEC1_IOP_BIT_COUNT * 2,
                         PEC2_IOP_CONFIG_START_BIT, PEC2_IOP_BIT_COUNT * 2));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CONF1_OR, l_buf));

        // Phase1 init step 2b
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_IOP_SWAP, l_pec_chiplets,
                               l_attr_proc_pcie_iop_swap));
        FAPI_DBG("attr_proc_pcie_iop_swap: %#x", l_attr_proc_pcie_iop_swap);
        l_buf = 0;
        FAPI_TRY(set_buf(i_target, l_buf, l_pec_id, l_attr_proc_pcie_iop_swap,
                         PEC0_IOP_SWAP_START_BIT, PEC0_IOP_BIT_COUNT,
                         PEC1_IOP_SWAP_START_BIT, PEC1_IOP_BIT_COUNT,
                         PEC2_IOP_SWAP_START_BIT, PEC2_IOP_BIT_COUNT));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CONF1_OR, l_buf));

        // Phase1 init step 3a
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_IOVALID_ENABLE, l_pec_chiplets,
                               l_attr_proc_pcie_iovalid_enable));
        FAPI_DBG("l_attr_proc_pcie_iovalid_enable: %#x", l_attr_proc_pcie_iovalid_enable);
        l_buf = 0;
        FAPI_TRY(set_buf(i_target, l_buf, l_pec_id, l_attr_proc_pcie_iovalid_enable,
                         PEC0_IOP_IOVALID_ENABLE_START_BIT, PEC0_IOP_BIT_COUNT,
                         PEC1_IOP_IOVALID_ENABLE_START_BIT, PEC1_IOP_BIT_COUNT,
                         PEC2_IOP_IOVALID_ENABLE_START_BIT, PEC2_IOP_BIT_COUNT));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CONF1_OR, l_buf));

        // Phase1 init step 3b (enable clock)
        l_buf = 0;
        FAPI_TRY(l_buf.insertFromRight(1, PEC_CPLT_CTRL0_TC_REFCLK_DRVR_EN_DC, 1));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CTRL0_OR, l_buf));

        // Phase1 init step 4 (PMA reset)
        l_buf = 0;
        FAPI_TRY(l_buf.insertFromRight(1, PEC_IOP_PMA_RESET_START_BIT, 1));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CONF1_CLEAR, l_buf));

        // Phase1 init step 5 (Set FIR action0)
        l_buf = 0;
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_FIR_ACTION0_REG, l_buf));

        // Phase1 init step 6 (Set FIR action1)
        l_buf = 0xFFFFFFFFF8000000;
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_FIR_ACTION1_REG, l_buf));

        // Phase1 init step 7 (Set FIR mask)
        l_buf = 0xFFFFFFFFF8000000;
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_FIR_MASK_REG, l_buf));

        // Phase1 init step 8-11 (Config 0 - 3)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_RX_CDR_GAIN, l_pec_chiplets,
                               l_pcs_cdr_gain));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_RX_LOFF_CONTROL, l_pec_chiplets,
                               l_pcs_loff_control));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_RX_VGA_CONTRL_REGISTER3, l_pec_chiplets,
                               l_pcs_vga_control_register3));

        for (int i = 0; i < NUM_PCS_CONFIG; i++)
        {
            // RX Config Mode
            l_buf = 0;
            FAPI_TRY(l_buf.insertFromRight(l_pcs_config_mode[i], 48, 16));
            FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
            FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_CONFIG_MODE_REG, l_buf));

            // RX CDR GAIN
            FAPI_TRY(fapi2::getScom(l_pec_chiplets, PEC_PCS_RX_CDR_GAIN_REG, l_buf));
            FAPI_TRY(l_buf.insertFromRight(l_pcs_cdr_gain[i], 56, 8));
            FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
            FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_CDR_GAIN_REG, l_buf));

            // RX LOFF CONTROL
            l_buf = 0;
            FAPI_TRY(l_buf.insertFromRight(l_pcs_loff_control[i], 48, 16));
            FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
            FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_LOFF_CONTROL_REG, l_buf));

            // RX VGA CONTROL REGISTER3
            l_buf = 0;
            FAPI_TRY(l_buf.insertFromRight(l_pcs_vga_control_register3[i], 48, 16));
            FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
            FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_VGA_CONTROL3_REG, l_buf));
        }

        // Phase1 init step 12 (RX Rot Cntl CDR Lookahead Disabled,SSC Disabled)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_RX_ROT_CDR_LOOKAHEAD, l_pec_chiplets,
                               l_pcs_rot_cntl_cdr_lookahead));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_RX_ROT_CDR_SSC, l_pec_chiplets,
                               l_pcs_rot_cntl_cdr_ssc));
        FAPI_TRY(fapi2::getScom(l_pec_chiplets, PEC_PCS_RX_ROT_CNTL_REG, l_buf));
        FAPI_TRY(l_buf.insertFromRight(l_pcs_rot_cntl_cdr_lookahead, 55, 1));
        FAPI_TRY(l_buf.insertFromRight(l_pcs_rot_cntl_cdr_ssc, 63, 1));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_ROT_CNTL_REG, l_buf));

        // Phase1 init step 13 (RX Config Mode Enable External Config Control)
        l_buf = 0;
        FAPI_TRY(l_buf.insertFromRight(0x8600, 48, 16));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_PCS_RX_CONFIG_MODE_REG, l_buf));

        // Phase1 init step 14 (PCLCK Control Register - PLLA)
        SET_REG_RMW_WITH_SINGLE_ATTR_8(fapi2::ATTR_PROC_PCIE_PCS_PCLCK_CNTL_PLLA,
                                       PEC_PCS_PCLCK_CNTL_PLLA_REG,
                                       56, 8);

        // Phase1 init step 15 (PCLCK Control Register - PLLB)
        SET_REG_RMW_WITH_SINGLE_ATTR_8(fapi2::ATTR_PROC_PCIE_PCS_PCLCK_CNTL_PLLB,
                                       PEC_PCS_PCLCK_CNTL_PLLB_REG,
                                       56, 8);

        // Phase1 init step 16 (TX DCLCK Rotator Override)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_TX_DCLCK_ROT,
                                       PEC_PCS_TX_DCLCK_ROTATOR_REG,
                                       48, 16);

        // Phase1 init step 17 (TX FIFO Config Offset)
        SET_REG_RMW_WITH_SINGLE_ATTR_8(fapi2::ATTR_PROC_PCIE_PCS_TX_FIFO_CONFIG_OFFSET,
                                       PEC_PCS_TX_FIFO_CONFIG_OFFSET_REG,
                                       59, 5);

        // Phase1 init step 18 (TX PCIe Receiver Detect Control Register 1)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_TX_PCIE_RECV_DETECT_CNTL_REG1,
                                       PEC_PCS_TX_PCIE_REC_DETECT_CNTL1_REG,
                                       48, 16);

        // Phase1 init step 19 (TX PCIe Receiver Detect Control Register 2)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_TX_PCIE_RECV_DETECT_CNTL_REG2,
                                       PEC_PCS_TX_PCIE_REC_DETECT_CNTL2_REG,
                                       48, 16);

        // Phase1 init step 20 (TX Power Sequence Enable)
        SET_REG_RMW_WITH_SINGLE_ATTR_8(fapi2::ATTR_PROC_PCIE_PCS_TX_POWER_SEQ_ENABLE,
                                       PEC_PCS_TX_POWER_SEQ_ENABLE_REG,
                                       56, 7);

        // Phase1 init step 21 (RX Phase Rotator Control)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_RX_PHASE_ROTATOR_CNTL,
                                       PEC_PCS_RX_ROT_CNTL_REG,
                                       48, 16);

        // Phase1 init step 22 (RX VGA Control Register 1)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_RX_VGA_CNTL_REG1,
                                       PEC_PCS_RX_VGA_CONTROL1_REG,
                                       48, 16);

        // Phase1 init step 23 (RX VGA Control Register 2)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_RX_VGA_CNTL_REG2,
                                       PEC_PCS_RX_VGA_CONTROL2_REG,
                                       48, 16);

        // Phase1 init step 24 (RX SIGDET Control)
        SET_REG_WR_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_RX_SIGDET_CNTL,
                                       PEC_PCS_RX_SIGDET_CONTROL_REG,
                                       48, 16);
        // Phase1 init step 25
        l_buf = 0;
        FAPI_TRY(l_buf.insertFromRight(1, PEC_IOP_PIPE_RESET_START_BIT, 1));
        FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf());
        FAPI_TRY(fapi2::putScom(l_pec_chiplets, PEC_CPLT_CONF1_CLEAR, l_buf));

        // Phase1 init step 26 (PCS System Control)
        SET_REG_RMW_WITH_SINGLE_ATTR_16(fapi2::ATTR_PROC_PCIE_PCS_SYSTEM_CNTL,
                                        PEC_PCS_SYS_CONTROL_REG,
                                        55, 9);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PCS_M_CNTL, l_pec_chiplets,
                               l_pcs_m_cntl));

        // Phase1 init step 27 (PCS M1 Control)
        SET_REG_RMW(l_pcs_m_cntl[0],
                    PEC_PCS_M1_CONTROL_REG,
                    55, 9);

        // Phase1 init step 28 (PCS M2 Control)
        SET_REG_RMW(l_pcs_m_cntl[1],
                    PEC_PCS_M1_CONTROL_REG,
                    55, 9);

        // Phase1 init step 29 (PCS M3 Control)
        SET_REG_RMW(l_pcs_m_cntl[2],
                    PEC_PCS_M1_CONTROL_REG,
                    55, 9);

        // Phase1 init step 30 (PCS M4 Control)
        SET_REG_RMW(l_pcs_m_cntl[3],
                    PEC_PCS_M1_CONTROL_REG,
                    55, 9);
    }

    FAPI_INF("End");

fapi_try_exit:
    return fapi2::current_err;
}
