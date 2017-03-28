/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr_phy_reset.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
/// @file p9c_mss_ddr_phy_reset.C
/// @brief HWP to set up ddr phy
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
////

#include <fapi2.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <p9c_mss_ddr_phy_reset.H>
#include <p9c_mss_unmask_errors.H>
#include <p9c_mss_termination_control.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>

enum phy
{
    POWERDOWN_1_P0_MASTER_PD_CNTL = CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0_MASTER_PD_CNTL,
    POWERDOWN_1_P0_WR_FIFO_STAB = CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0_WR_FIFO_STAB,

    FORCE_MCLK_LOW_N = CEN_MBA_CCS_MODEQ_FORCE_MCLK_LOW_N,
    DDR_DFI_RESET_RECOVER = CEN_MBA_CCS_MODEQ_MCBIST_DDR_DFI_RESET_RECOVER,

    DP18_PLL_LOCK_STATUS = CEN_MBA_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_LOCK,
    DP18_PLL_LOCK_STATUS_LEN = CEN_MBA_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_LOCK_LEN,

    AD32S_PLL_LOCK_STATUS = CEN_MBA_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_LOCK,
    AD32S_PLL_LOCK_STATUS_LEN = CEN_MBA_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_LOCK_LEN,

};

extern "C"
{
    // TODO RTC:168629 Segregate API from p9c_ddr_phy_reset.C into a PHY dir
    // prototypes of functions called in phy reset
    fapi2::ReturnCode deassert_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);
    fapi2::ReturnCode ddr_phy_reset_cloned(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);
    fapi2::ReturnCode ddr_phy_flush(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Does a soft reset of the DDR PHY logic and lock the DDR PLLs
    /// @param[in]  i_target the MBA target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode p9c_mss_ddr_phy_reset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        FAPI_TRY(ddr_phy_reset_cloned(i_target), "ddr_phy_reset_cloned failed!");
        FAPI_TRY(mss_slew_cal(i_target), "mss_slew_cal failed!");
        FAPI_TRY(ddr_phy_flush(i_target), "ddr_phy_flush failed!");

        // If mss_unmask_ddrphy_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_ddrphy_errors runs clean,
        // it will just return the passed in rc.
        FAPI_TRY(mss_unmask_ddrphy_errors(i_target));

    fapi_try_exit:
        FAPI_DBG("end");
        return fapi2::current_err;
    }

    ///
    /// @brief PHY reset cloned
    /// @param[in] i_target the MBA target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode ddr_phy_reset_cloned(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        // Loop 10 times during PLL lock polling
        constexpr uint64_t MAX_POLL_LOOPS = 10;
        constexpr uint64_t DP18_PLL_EXP_LOCK_STATUS = 0xF800;  // DP18 PLL lock status
        constexpr uint64_t AD32S_PLL_EXP_LOCK_STATUS = 0xC000; // AD32S PLL lock status

        uint32_t l_poll_count = 0;
        uint32_t l_done_polling = 0;
        uint8_t l_is_simulation = 0;
        fapi2::buffer<uint64_t> l_data;
        fapi2::buffer<uint64_t> l_dp_p0_lock_data;
        fapi2::buffer<uint64_t> l_dp_p1_lock_data;
        fapi2::buffer<uint64_t> l_ad_p0_lock_data;
        fapi2::buffer<uint64_t> l_ad_p1_lock_data;
        uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {}; // 10 byte array of bad bits
        uint8_t l_valid_dimms = 0;
        uint8_t l_valid_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
        uint8_t l_num_mranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {};
        uint8_t l_port = 0;
        uint16_t l_actual = 0;
        uint16_t l_poll = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        bool l_new_error = false;
        uint8_t l_continue_on_dp18_pll_lock_failure = 0;

        FAPI_INF("********* mss_ddr_phy_reset start *********");

        //
        // Here are the specific instructions from section 14.7.3 of the Centaur Chip Specification:
        //
        // Run cen_ddr_phy_reset.C prepares the DDR PLLs. These PLLs were previously configured via scan init, but have
        // been held in reset. At this point the PLL GP bit is deasserted to take the PLLs out of reset.
        //
        // The cen_ddr_phy_reset.C now resets the DDR PHY logic. This process will NOT destroy any configuration values
        // previously loaded via the init file. The intent is for the initialized phase rotator configuration to remain valid after the
        // soft reset completes. If this assumption fails to hold true, it will require replacing this step with a PHY hard reset,
        // and then using inband configuration writes to restore all the DDR Configuration Registers.
        //
        // The following steps must be performed as part of the PHY reset procedure.

        // PLL Lock cannot happen if mclk low is asserted
        // this procedure was moved from draminit to:
        // Deassert Force_mclk_low signal
        // see CQ 216395 (HW217109)
        FAPI_TRY(deassert_force_mclk_low(i_target), " deassert_force_mclk_low Failed");

        //
        // 1. Drive all control signals to the PHY to their inactive state, idle state, or inactive value.
        //    (Note: The chip should already be in this state.)
        FAPI_DBG("Step 1: All control signals to the PHYs should already be set to their inactive state, idle state, or inactive values.\n");

        //
        // 2. For DD0: Assert dfi_reset_all (GP4 bit 5 = "1") for at least 32 memory clock cycles. This signal DOES
        //    erradicate all DDR configuration register initialization, thereby requiring the DDR registers to be reprogrammed
        //    via SCOM after the PHY reset sequence completes.
        //    For DD1: Set mcbist_ddr_dfi_reset_recover ="1" (CCS_MODEQ(25) SCOM Addr: 0x030106A7 & 0x03010EA7)
        //    for at least 32 memory clock cycles. This signal does NOT reset the configuration registers
        //    within the PHY.
        FAPI_DBG("Step 2: MBA CCS_MODEQ(25), Setting mcbist_ddr_dfi_reset_recover = 1 for DDR PHY soft reset.\n");
        FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_CCS_MODEQ, l_data), "Error reading CCS_MODEQ register.");
        l_data.setBit<DDR_DFI_RESET_RECOVER>();
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_CCS_MODEQ, l_data));
        FAPI_TRY(fapi2::delay(DELAY_100NS, DELAY_2000SIMCYCLES)); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)

        //
        // 3. For DD0: Deassert dfi_reset_all (GP4 bit 5 = "0")
        //    For DD1: Deassert mcbist_ddr_dfi_reset_recover = "0" (CCS_MODEQ(25) SCOM Addr: 0x030106A7 0x03010EA7)
        FAPI_DBG("Step 3: MBA CCS_MODEQ(25), Setting mcbist_ddr_dfi_reset_recover = 0 to release soft reset.\n");
        FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_CCS_MODEQ, l_data), "Error reading CCS_MODEQ register.");
        l_data.clearBit<DDR_DFI_RESET_RECOVER>();
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_CCS_MODEQ, l_data), "Error writing CCS_MODEQ register.");

        //
        // 4. Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset and enable the internal impedance controller.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 4: Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset.\n");
        l_data = 0x0000000000000010ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P1, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");

        //
        // 5. Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset while impedance controller is still enabled.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 5: Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset.\n");
        l_data = 0x0000000000000018ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P1, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");

        //
        // 6. Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller.
        //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 6: Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller.\n");
        l_data = 0x0000000000000008ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P0 register.");
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P1, l_data),
                 "Error writing DPHY01_DDRPHY_PC_IO_PVT_FET_CONTROL_P1 register.");

        //
        // 7. Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 7: Write 0x4000 into the PC Resets Regs. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active.\n");
        l_data = 0x0000000000004000ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_RESETS_P0, l_data),
                 "Error writing DPHY01_DDRPHY_PC_RESETS_P0 register.");
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_RESETS_P1, l_data),
                 "Error writing DPHY01_DDRPHY_PC_RESETS_P1 register.");

        //
        // 8. Wait at least 1 millisecond to allow the PLLs to lock. Otherwise, poll the PC DP18 PLL Lock Status
        //    and the PC AD32S PLL Lock Status to determine if all PLLs have locked.
        //    PC DP18 PLL Lock Status should be 0xF800:  (SCOM Addr: 0x8000C0000301143F, 0x8001C0000301143F, 0x8000C0000301183F, 0x8001C0000301183F)
        //    PC AD32S PLL Lock Status should be 0xC000: (SCOM Addr: 0x8000C0010301143F, 0x8001C0010301143F, 0x8000C0010301183F, 0x8001C0010301183F)
        //------------------------
        // 8a - Poll for lock bits
        FAPI_DBG("Step 8: Poll until DP18 and AD32S PLLs have locked....\n");

        do
        {
            FAPI_TRY(fapi2::delay(DELAY_1US, DELAY_20000SIMCYCLES)); // wait 20000 simcycles (in sim mode) OR 1 usec (in hw mode)
            l_done_polling = 1;
            FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_ROX, l_dp_p0_lock_data));
            l_dp_p0_lock_data.extract<DP18_PLL_LOCK_STATUS, DP18_PLL_LOCK_STATUS_LEN>(l_poll);

            if ( l_poll != DP18_PLL_EXP_LOCK_STATUS )
            {
                l_done_polling = 0;
            }

            FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_ROX, l_dp_p1_lock_data));
            l_dp_p1_lock_data.extract<DP18_PLL_LOCK_STATUS, DP18_PLL_LOCK_STATUS_LEN>(l_poll);

            if ( l_poll != DP18_PLL_EXP_LOCK_STATUS )
            {
                l_done_polling = 0;
            }

            FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_ROX, l_ad_p0_lock_data));
            l_ad_p0_lock_data.extract<48, 16>(l_poll);

            if ( l_poll != AD32S_PLL_EXP_LOCK_STATUS )
            {
                l_done_polling = 0;
            }

            FAPI_TRY(fapi2::getScom( i_target, CEN_MBA_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_ROX, l_ad_p1_lock_data));
            l_ad_p1_lock_data.extract<48, 16>(l_poll);

            if ( l_poll != AD32S_PLL_EXP_LOCK_STATUS )
            {
                l_done_polling = 0;
            }

            l_poll_count++;
        }
        while ((l_done_polling == 0) && (l_poll_count < MAX_POLL_LOOPS));   // Poll until PLLs are locked.


        if (l_poll_count == MAX_POLL_LOOPS)
        {

            //-------------------------------
            // Check to see if we should continue even if the DP18 PLL lock fails
            const auto l_centaurTarget = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL,
                                   l_centaurTarget,
                                   l_continue_on_dp18_pll_lock_failure));

            FAPI_DBG("Got attribute ATTR_CENTAUR_EC_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL:  value=%X.\n",
                     l_continue_on_dp18_pll_lock_failure);

            //-------------------------------
            // 8b - Check Port 0 DP lock bits

            // TODO RTC:168628 Log FFDC in p9c_ddr_phy_reset instead of only printing traces?
            l_dp_p0_lock_data.extract<48, 16>(l_poll);

            if ( l_poll != DP18_PLL_EXP_LOCK_STATUS )
            {
                if ( !l_dp_p0_lock_data.getBit<48>() )
                {
                    FAPI_INF("Port 0 DP 0 PLL failed to lock!");
                }

                if ( !l_dp_p0_lock_data.getBit<49>() )
                {
                    FAPI_INF("Port 0 DP 1 PLL failed to lock!");
                }

                if ( !l_dp_p0_lock_data.getBit<50>() )
                {
                    FAPI_INF("Port 0 DP 2 PLL failed to lock!");
                }

                if ( !l_dp_p0_lock_data.getBit<51>() )
                {
                    FAPI_INF("Port 0 DP 3 PLL failed to lock!");
                }

                if ( !l_dp_p0_lock_data.getBit<52>() )
                {
                    FAPI_INF("Port 0 DP 4 PLL failed to lock!");
                }

                if (!l_continue_on_dp18_pll_lock_failure)
                {
                    l_dp_p0_lock_data.extract<48, 16>(l_actual);

                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_DP18_0_PLL_FAILED_TO_LOCK().
                                set_EXPECTED_STATUS(DP18_PLL_EXP_LOCK_STATUS).
                                set_ACTUAL_STATUS(l_actual).
                                set_MBA_IN_ERROR(i_target).
                                set_MEMBUF_CHIP_IN_ERROR(l_centaurTarget),
                                "One or more DP18 port 0 (0x0C000) PLL failed to lock!,DP18 PLL lock failed and this chip does not have the known DP18 lock bug.");
                }

                // for DD1 parts that have the DP18 lock bug - keep going to initialize any other channels that might be good.
                FAPI_INF("Continuing anyway to initialize any other channels that might be good...");
            }

            //-------------------------------
            // 8c - Check Port 1 DP lock bits
            l_dp_p1_lock_data.extract< 48, 16>(l_poll);

            if ( l_poll != DP18_PLL_EXP_LOCK_STATUS )
            {
                if ( !l_dp_p1_lock_data.getBit<48>() )
                {
                    FAPI_INF("Port 1 DP 0 PLL failed to lock!");
                }

                if ( !l_dp_p1_lock_data.getBit<49>() )
                {
                    FAPI_INF("Port 1 DP 1 PLL failed to lock!");
                }

                if ( !l_dp_p1_lock_data.getBit<50>() )
                {
                    FAPI_INF("Port 1 DP 2 PLL failed to lock!");
                }

                if ( !l_dp_p1_lock_data.getBit<51>() )
                {
                    FAPI_INF("Port 1 DP 3 PLL failed to lock!");
                }

                if ( !l_dp_p1_lock_data.getBit<52>() )
                {
                    FAPI_INF("Port 1 DP 4 PLL failed to lock!");
                }

                if (!l_continue_on_dp18_pll_lock_failure)
                {
                    l_dp_p1_lock_data.extract<48, 16>(l_actual);

                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_DP18_1_PLL_FAILED_TO_LOCK().
                                set_EXPECTED_STATUS(DP18_PLL_EXP_LOCK_STATUS).
                                set_ACTUAL_STATUS(l_actual).
                                set_MBA_IN_ERROR(i_target).
                                set_MEMBUF_CHIP_IN_ERROR(l_centaurTarget),
                                "One or more DP18 port 1 (0x0C000) PLL failed to lock!,DP18 PLL lock failed and this chip does not have the known DP18 lock bug.");
                }

                // for DD1 parts that have the DP18 lock bug - keep going to initialize any other channels that might be good.
                // FAPI_INF("One or more DP18 port 1 (0x1C000) PLL failed to lock!   Lock Status = %04X",l_dp_p1_lock_data.getHalfWord(3));
                FAPI_INF("Continuing anyway to initialize any other channels that might be good...");
            }

            //-------------------------------
            // 8d - Check Port 0 AD lock bits
            l_ad_p0_lock_data.extract<48, 16>(l_poll);
            l_ad_p0_lock_data.extract<48, 16>(l_actual);

            FAPI_ASSERT(l_poll == AD32S_PLL_EXP_LOCK_STATUS,
                        fapi2::CEN_MSS_AD32S_0_PLL_FAILED_TO_LOCK().
                        set_EXPECTED_STATUS(AD32S_PLL_EXP_LOCK_STATUS).
                        set_ACTUAL_STATUS(l_actual).
                        set_MBA_IN_ERROR(i_target).
                        set_MEMBUF_CHIP_IN_ERROR(l_centaurTarget),
                        "One or more AD32S port 0 (0x0C001) PLL failed to lock!");

            //-------------------------------
            // 8e - Check Port 1 AD lock bits
            l_ad_p1_lock_data.extract<48, 16>(l_poll);
            l_ad_p1_lock_data.extract<48, 16>(l_actual);

            FAPI_ASSERT( l_poll == AD32S_PLL_EXP_LOCK_STATUS,
                         fapi2::CEN_MSS_AD32S_1_PLL_FAILED_TO_LOCK().
                         set_EXPECTED_STATUS(AD32S_PLL_EXP_LOCK_STATUS).
                         set_ACTUAL_STATUS(l_actual).
                         set_MBA_IN_ERROR(i_target).
                         set_MEMBUF_CHIP_IN_ERROR(l_centaurTarget),
                         "One or more AD32S port 1 (0x0C001) PLL failed to lock!");
        }
        else
        {
            FAPI_INF("AD32S PLLs are now locked.  DP18 PLLs should also be locked.");
        }

        //
        // 9.Write '8024'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //   This takes the dphy_nclk/SysClk alignment circuit out of reset and puts the dphy_nclk/SysClk alignment circuit into the Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 9: Write '8024'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
        l_data = 0x0000000000008024ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1, l_data));

        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_2, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_2, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_3, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_3, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_4, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_4, l_data));

        //
        // 10.Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.
        FAPI_DBG("Step 10: Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.\n");

        // wait 2000000 simcycles (in sim mode) OR 100 usec (in hw mode)
        FAPI_TRY(fapi2::delay(DELAY_100US, DELAY_2000000SIMCYCLES));

        //
        // 11.Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset
        //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
        FAPI_DBG("Step 11: Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset.\n");
        l_data = 0x0000000000000000ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_RESETS_P0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_RESETS_P1, l_data));

        //
        // 12.Write '8020'x into the ADR SysClk Phase Rotator Control Registers and into the DP18 SysClk Phase Rotator Control Registers.
        //    This takes the dphy_nclk/SysClk alignment circuit out of Continuous Update Mode.
        //           ADR SysClk PR Control Registers  :  (SCOM Addr: 0x800080320301143F, 0x800084320301143F, 0x800180320301143F, 0x800184320301143F,
        //                                                           0x800080320301183F, 0x800084320301183F, 0x800180320301183F, 0x800184320301183F)
        //          DP18 SysClk PR Control Registers  :  (SCOM Addr: 0x800000070301143F, 0x800004070301143F, 0x800008070301143F, 0x80000C070301143F, 0x800010070301143F,
        //                                                           0x800000070301183F, 0x800004070301183F, 0x800008070301183F, 0x80000C070301183F, 0x800010070301183F,
        //                                                           0x800100070301143F, 0x800104070301143F, 0x800108070301143F, 0x80010C070301143F, 0x800110070301143F,
        //                                                           0x800100070301183F, 0x800104070301183F, 0x800108070301183F, 0x80010C070301183F, 0x800110070301183F)
        FAPI_DBG("Step 12: Write '8020'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
        l_data = 0x0000000000008020ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1, l_data));

        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_1, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_2, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_2, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_3, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_3, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_4, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_4, l_data));

        // Work-around required to get alignment in simulation
        // Read the ATTR_IS_SIMULATION attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_simulation));

        if (l_is_simulation)
        {
            FAPI_DBG("Step 12.1 (SIM ONLY): Write '8000'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
            l_data = 0x0000000000008000ull;
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1, l_data));

            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_2, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_2, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_3, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_3, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_4, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_4, l_data));

            FAPI_DBG("Step 12.2 (SIM ONLY): Write '8080'x into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs.\n");
            l_data = 0x0000000000008080ull;
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S1, l_data));

            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_0, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_1, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_2, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_2, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_3, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_3, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P0_4, l_data));
            FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_DP18_SYSCLK_PR_P1_4, l_data));
        }

        //
        // 13.Wait at least 32 memory clock cycles.
        FAPI_DBG("Step 13: Wait at least 32 memory clock cycles.\n");
        FAPI_TRY(fapi2::delay(DELAY_100NS, DELAY_2000SIMCYCLES)); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)

        //
        // 14.Write 0x0018 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.
        //    This step takes approximately 2112 (64 * 33) memory clock cycles.
        //                                                (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
        FAPI_DBG("Step 14: Write 0x0018 to PC IO PVT N/P FET driver control register to enable internal ZQ calibration.\n");
        l_data = 0x0000000000000018ull;
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data));
        FAPI_TRY(fapi2::putScom( i_target, CEN_MBA_DDRPHY_PC_IO_PVT_FET_CONTROL_P1, l_data));

        //
        // Now do some error checking and mark bad channels
        // Check to see if there were any register access problems on DP registers, or corresponding PLLs that did not lock.
        // If so, mark the DP pairs as bad.

        // Loop through only valid (functional) dimms.
        // For each valid dimm, loop through all the ranks belonging to that dimm.
        // If there was either a register access error, or if the PLL did not lock, then mark the DP pair as bad.
        // Do this by setting the dqBitmap attribute for all dimms and ranks associated with that PLL or register.
        // Read the dqBitmap first, so that you do not clear values that may already be set.
        // (Some DP channels may already be marked as bad.)

        // TODO RTC:168627 Find out if we can avoid ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR
        // Find out which dimms are functional
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target,  l_valid_dimms));
        l_valid_dimm[0][0] = (l_valid_dimms & 0x80);
        l_valid_dimm[0][1] = (l_valid_dimms & 0x40);
        l_valid_dimm[1][0] = (l_valid_dimms & 0x08);
        l_valid_dimm[1][1] = (l_valid_dimms & 0x04);

        // Find out how many ranks are on each dimm
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target,  l_num_mranks_per_dimm));

        // Loop through each PORT (0,1)
        for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++ )
        {
            // Loop through each DIMM:(0,1)
            for(l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++ )
            {
                if (l_valid_dimm[l_port][l_dimm])
                {
                    // Ok, this DIMM is functional. So loop through the RANKs of this dimm.
                    for(l_rank = 0; l_rank < l_num_mranks_per_dimm[l_port][l_dimm]; ++l_rank )
                    {
                        // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                        FAPI_TRY(dimmGetBadDqBitmap(i_target, l_port, l_dimm, l_rank, l_dqBitmap));

                        // Mark the bad bits for each register that had problems or PLL that did not lock
                        l_new_error = false;

                        if ( l_port == 0 )
                        {
                            if ( !l_dp_p0_lock_data.getBit<48>() )
                            {
                                l_dqBitmap[0] = 0xff;
                                l_dqBitmap[1] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p0_lock_data.getBit<49>() )
                            {
                                l_dqBitmap[2] = 0xff;
                                l_dqBitmap[3] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p0_lock_data.getBit<50>() )
                            {
                                l_dqBitmap[4] = 0xff;
                                l_dqBitmap[5] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p0_lock_data.getBit<51>() )
                            {
                                l_dqBitmap[6] = 0xff;
                                l_dqBitmap[7] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p0_lock_data.getBit<52>() )
                            {
                                l_dqBitmap[8] = 0xff;
                                l_dqBitmap[9] = 0xff;
                                l_new_error = true;
                            }
                        }
                        else
                        {
                            if ( !l_dp_p1_lock_data.getBit<48>() )
                            {
                                l_dqBitmap[0] = 0xff;
                                l_dqBitmap[1] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p1_lock_data.getBit<49>() )
                            {
                                l_dqBitmap[2] = 0xff;
                                l_dqBitmap[3] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p1_lock_data.getBit<50>() )
                            {
                                l_dqBitmap[4] = 0xff;
                                l_dqBitmap[5] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p1_lock_data.getBit<51>() )
                            {
                                l_dqBitmap[6] = 0xff;
                                l_dqBitmap[7] = 0xff;
                                l_new_error = true;
                            }

                            if ( !l_dp_p1_lock_data.getBit<52>() )
                            {
                                l_dqBitmap[8] = 0xff;
                                l_dqBitmap[9] = 0xff;
                                l_new_error = true;
                            }
                        }

                        // If there are new errors, write back the bad DQ Bitmap for l_port, l_dimm, l_rank
                        if ( l_new_error )
                        {
                            FAPI_TRY(dimmSetBadDqBitmap(i_target, l_port, l_dimm, l_rank, l_dqBitmap));
                        }
                    }  // End of loop over RANKs
                }
            }  // End of loop over DIMMs
        }  // End of loop over PORTs

    fapi_try_exit:
        FAPI_INF("********* mss_ddr_phy_reset complete *********");
        return fapi2::current_err;
    }

    ///
    /// @brief deassert MCLK
    /// @param[in] i_target the MBA target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode deassert_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data_buffer;

        FAPI_INF( "+++++++++++++++++++++ DEASSERTING FORCE MCLK LOW +++++++++++++++++++++");

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));
        l_data_buffer.setBit<63>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Flush DDR PHY
    /// @param[in] i_target the MBA target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode ddr_phy_flush(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data;
        fapi2::buffer<uint64_t> l_mask;

        FAPI_INF(" Performing ddr_phy_flush routine");

        FAPI_INF("ADR/DP18 FLUSH: 1) set PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");
        l_data.setBit<48>(); // set MASTER_PD_CNTL bit
        l_data.setBit<58>(); // set WR_FIFO_STAB bit

        l_mask.setBit<48>(); // set MASTER_PD_CNTL bit
        l_mask.setBit<58>(); // set WR_FIFO_STAB mask bit

        FAPI_TRY(fapi2::putScomUnderMask(i_target, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0, l_data, l_mask));
        FAPI_TRY(fapi2::putScomUnderMask(i_target, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1, l_data, l_mask));
        FAPI_TRY(fapi2::delay(DELAY_100NS, DELAY_2000SIMCYCLES)); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)

        FAPI_INF("ADR/DP18 FLUSH: 2) clear PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");
        l_data.flush<0>(); // clear data buffer
        l_mask.flush<0>(); // clear mask buffer
        l_mask.setBit<48>(); // set MASTER_PD_CNTL bit
        l_mask.setBit<58>(); // set WR_FIFO_STAB mask bit

        FAPI_TRY(fapi2::putScomUnderMask(i_target, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0, l_data, l_mask));
        FAPI_TRY(fapi2::putScomUnderMask(i_target, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1, l_data, l_mask));

    fapi_try_exit:
        return fapi2::current_err;
    }

}//end extern C
