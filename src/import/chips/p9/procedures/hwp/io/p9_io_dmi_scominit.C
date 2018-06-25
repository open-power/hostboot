/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_dmi_scominit.C $  */
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
/// @file p9_io_dmi_scominit.C
/// @brief Invoke DMI processor side initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
//   Invoke DMI scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_regs.H>
#include <p9_io_scom.H>
#include <p9_io_dmi_scominit.H>
#include <p9c_dmi_io_scom.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t DMI_FIR_ACTION0_REG = 0x07011006;
const uint64_t DMI_FIR_ACTION1_REG = 0x07011007;
const uint64_t DMI_FIR_MASK_REG    = 0x07011003;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/**
 * @brief Gets the value of the ATTR_CHIP_UNIT_NUM and passes back by reference
 * @param[in]  i_tgt         Fapi2 Target
 * @param[out] o_chipunitnum Chip Unit Number
 * @return FAPI2_RC_SUCCESS on success, otherwise error
 */
fapi2::ReturnCode p9_dmi_get_chipunit_num(const DMI_TGT& i_tgt, uint8_t& o_chipunitnum)
{
    FAPI_IMP("I/O DMI Scominit: Get Chipunit Number Start.");

    // Retrieve chipunitnum attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_tgt, o_chipunitnum ),
             "Error getting ATTR_CHIP_UNIT_POS, rc = 0x%.8X",
             (uint64_t)fapi2::current_err );

fapi_try_exit:
    FAPI_IMP("I/O DMI Scominit: Get Chipunit Number Exit.");
    return fapi2::current_err;
}


/**
 * @brief HWP that calls the DMI SCOM initfiles
 * Should be called for all valid/connected DMI endpoints
 *
 * @param[in] i_tgt  Reference to DMI chiplet target
 *
 * @return FAPI2_RC_SUCCESS on success, error otherwise
 */
fapi2::ReturnCode p9_io_dmi_scominit(const DMI_TGT& i_tgt)
{
    // mark HWP entry
    FAPI_INF("p9_io_dmi_scominit: Entering ...");
    const uint8_t GRP_03  = 3;
    const uint8_t LANE_00 = 0;
    fapi2::ReturnCode rc  = fapi2::FAPI2_RC_SUCCESS;

    // Get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> sys_tgt;

    // assert IO reset to power-up bus endpoint logic
    // read-modify-write, set single reset bit (HW auto-clears)
    // on writeback
    FAPI_TRY(io::rmw(EDIP_RX_IORESET, i_tgt, GRP_03, LANE_00, 1));

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY(fapi2::delay(50000, 1000000));

    FAPI_TRY(io::rmw(EDIP_TX_IORESET, i_tgt, GRP_03, LANE_00, 1));

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY(fapi2::delay(50000, 1000000));

    FAPI_INF("Invoke FAPI2 p9c_dmi_scom Procedure");
    FAPI_EXEC_HWP(rc, p9c_dmi_io_scom, i_tgt, sys_tgt);

    if(rc)
    {
        FAPI_ERR("P9 I/O DMI Scominit Failed");
        fapi2::current_err = rc;
    }

    // configure FIR
    {
        fapi2::Target<fapi2::TARGET_TYPE_MC> l_mc_tgt =
            i_tgt.getParent<fapi2::TARGET_TYPE_MC>();

        // mask(1) action0(X) action1(X) : Masked
        // mask(0) action0(0) action1(0) : System Checkstop
        // mask(0) action0(0) action1(1) : Recoverable
        // mask(0) action0(1) action1(0) : Host Attention
        // mask(0) action0(1) action1(1) : Unit Checkstop
        fapi2::buffer<uint64_t> l_fir_mask;
        fapi2::buffer<uint64_t> l_fir_action0;
        fapi2::buffer<uint64_t> l_fir_action1;
        l_fir_mask.flush<1>();
        l_fir_action0.flush<0>();
        l_fir_action1.flush<0>();

        // 0    Rx Invalid State or Parity Error         recoverable
        l_fir_mask.clearBit<0>();
        l_fir_action1.setBit<0>();
        // 1    Tx Invalid State or Parity Error         recoverable
        l_fir_mask.clearBit<1>();
        l_fir_action1.setBit<1>();
        // 2    GCR Hange Error                          recoverable
        l_fir_mask.clearBit<2>();
        l_fir_action1.setBit<2>();
        // 3:7  Reserved                                 mask
        // 8    Rx Bus 0 Training Error                  mask
        // 9    Rx Bus 0 Spare Lane Deployed             recoverable
        l_fir_mask.clearBit<9>();
        l_fir_action1.setBit<9>();
        // 10   Rx Bus 0 Max Spares Exceeded             recoverable
        l_fir_mask.clearBit<10>();
        l_fir_action1.setBit<10>();
        // 11   Rx Bus 0 Recal or Dynamic Repair Error   recoverable
        l_fir_mask.clearBit<11>();
        l_fir_action1.setBit<11>();
        // 12   Rx Bus 0 Too Many Bus Errors             unit_cs
        l_fir_mask.clearBit<12>();
        l_fir_action0.setBit<12>();
        l_fir_action1.setBit<12>();
        // 13:15 Reserved                                mask
        // 16   Rx Bus 1 Training Error                  mask
        // 17   Rx Bus 1 Spare Lane Deployed             recoverable
        l_fir_mask.clearBit<17>();
        l_fir_action1.setBit<17>();
        // 18   Rx Bus 1 Max Spares Exceeded             recoverable
        l_fir_mask.clearBit<18>();
        l_fir_action1.setBit<18>();
        // 19   Rx Bus 1 Recal or Dynamic Repair Error   recoverable
        l_fir_mask.clearBit<19>();
        l_fir_action1.setBit<19>();
        // 20   Rx Bus 1 Too Many Bus Errors             unit_cs
        l_fir_mask.clearBit<20>();
        l_fir_action0.setBit<20>();
        l_fir_action1.setBit<20>();
        // 21:23 Reserved                                mask
        // 24   Rx Bus 2 Training Error                  mask
        // 25   Rx Bus 2 Spare Lane Deployed             recoverable
        l_fir_mask.clearBit<25>();
        l_fir_action1.setBit<25>();
        // 26   Rx Bus 2 Max Spares Exceeded             recoverable
        l_fir_mask.clearBit<26>();
        l_fir_action1.setBit<26>();
        // 27   Rx Bus 2 Recal or Dynamic Repair Error   recoverable
        l_fir_mask.clearBit<27>();
        l_fir_action1.setBit<27>();
        // 28   Rx Bus 2 Too Many Bus Errors             unit_cs
        l_fir_mask.clearBit<28>();
        l_fir_action0.setBit<28>();
        l_fir_action1.setBit<28>();
        // 29:31 Reserved                                mask
        // 32   Rx Bus 3 Training Error                  mask
        // 33   Rx Bus 3 Spare Lane Deployed             recoverable
        l_fir_mask.clearBit<33>();
        l_fir_action1.setBit<33>();
        // 34   Rx Bus 3 Max Spares Exceeded             recoverable
        l_fir_mask.clearBit<34>();
        l_fir_action1.setBit<34>();
        // 35   Rx Bus 3 Recal or Dynamic Repair Error   recoverable
        l_fir_mask.clearBit<35>();
        l_fir_action1.setBit<35>();
        // 36   Rx Bus 3 Too Many Bus Errors             unit_cs
        l_fir_mask.clearBit<36>();
        l_fir_action0.setBit<36>();
        l_fir_action1.setBit<36>();
        // 37:39 Reserved                                mask
        // 40:47 Bus 4 - Unused                          mask
        // 48    Scom Error                              mask
        // 49    Scom Error                              mask
        // 50:63 Unused                                  mask


        FAPI_TRY(fapi2::putScom(l_mc_tgt, DMI_FIR_ACTION0_REG, l_fir_action0));
        FAPI_TRY(fapi2::putScom(l_mc_tgt, DMI_FIR_ACTION1_REG, l_fir_action1));
        FAPI_TRY(fapi2::putScom(l_mc_tgt, DMI_FIR_MASK_REG, l_fir_mask));
    }

    // mark HWP exit
    FAPI_INF("p9_io_dmi_scominit: ... Exiting");

fapi_try_exit:
    return fapi2::current_err;
}
