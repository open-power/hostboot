/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_power_cleanup.C $ */
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
///
/// @file p9c_mss_power_cleanup.C
/// @brief Procedure to deconfig centaurs and mbas
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------
#include <p9c_cen_stopclocks.H>
#include <p9c_mss_power_cleanup.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_eff_config.H>
#include <generic/memory/lib/utils/c_str.H>

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

constexpr uint64_t PERV_CLOCKS_ON = 0x000007FFFFFFFFFF;
constexpr uint64_t MEM_CLOCKS_ON  = 0x0000001FFFFFFFFF;

//------------------------------------------------------------------------------
// extern encapsulation
//------------------------------------------------------------------------------
extern "C"
{

    ///
    /// @brief mss_power_cleanup(): Clean up a centaur and also MBAs, also calls the mba cleanup under the covers
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba0: the mba0
    /// @param[in] i_target_mba1: the mba1
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_power_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
                                            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba0,
                                            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba1)
    {
        fapi2::ReturnCode rc, rc0, rc1, rcf, rcc;
        uint8_t centaur_functional = 1, mba0_functional = 1, mba1_functional = 1;
        uint8_t cen_init_state = 0;

        FAPI_INF("Running p9c_mss_power_cleanupon %s\n", mss::c_str(i_target_centaur));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_centaur,  centaur_functional),
                 "ERROR: Cannot get ATTR_FUNCTIONAL");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_mba0,  mba0_functional), "ERROR: Cannot get ATTR_FUNCTIONAL");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_mba1,  mba1_functional), "ERROR: Cannot get ATTR_FUNCTIONAL");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_INIT_STATE, i_target_centaur,  cen_init_state),
                 "ERROR: Cannot get ATTR_FUNCTIONAL");

        if (cen_init_state == fapi2::ENUM_ATTR_CEN_MSS_INIT_STATE_COLD)
        {
            FAPI_ERR("Centaur clocks not on.  Cannot execute p9c_mss_power_cleanup on this target: %s",
                     mss::c_str(i_target_centaur));
        }

        rc0 = mss_power_cleanup_mba_part1(i_target_centaur, i_target_mba0);
        rc1 = mss_power_cleanup_mba_part1(i_target_centaur, i_target_mba1);
        rcf = mss_power_cleanup_mba_fence(i_target_centaur, i_target_mba0, i_target_mba1);
        rcc = mss_power_cleanup_centaur(i_target_centaur);

        if(rc0)
        {
            FAPI_ASSERT(!mba0_functional,
                        fapi2::CEN_MSS_POWER_CLEANUP_MBA0_UNEXPECTED_BAD_RC().
                        set_MBA_CHIPLET(i_target_mba0),
                        "mba0 was functional yet it got a bad return code");
            FAPI_INF("mba0 was not functional and it got a bad return code");
        }

        if(rc1)
        {
            FAPI_ASSERT(!mba1_functional,
                        fapi2::CEN_MSS_POWER_CLEANUP_MBA1_UNEXPECTED_BAD_RC().
                        set_MBA_CHIPLET(i_target_mba1),
                        "mba1 was functional yet it got a bad return code");
            FAPI_INF("mba1 was not functional and it got a bad return code");
        }

        if(rcf)
        {
            FAPI_ASSERT(!centaur_functional,
                        fapi2::CEN_MSS_POWER_CLEANUP_FENCING_UNEXPECTED_BAD_RC().
                        set_CENTAUR(i_target_centaur),
                        "centaur was functional yet it got a bad return code");
            FAPI_INF("centaur was not functional and it got a bad return code");
        }

        if(rcc)
        {
            FAPI_ASSERT(!centaur_functional,
                        fapi2::CEN_MSS_POWER_CLEANUP_CENTAUR_UNEXPECTED_BAD_RC().
                        set_CENTAUR(i_target_centaur),
                        "centaur was functional yet it got a bad return code");
            FAPI_INF("centaur was not functional and it got a bad return code");
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end p9c_mss_power_cleanup()

    ///
    /// @brief setup bits for the CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0 register
    /// @param[in] i_mba_functional  1 for functional
    /// @param[in/out] io_data_buffer_64 buffer for bits
    /// @return fapi2::ReturnCode
    ///
    static fapi2::ReturnCode set_powerdown_bits(const uint8_t i_mba_functional,  fapi2::buffer<uint64_t>& io_data_buffer_64)
    {
        if(i_mba_functional == 0)
        {
            FAPI_INF("set_powerdown_bits MBA not Functional");
            io_data_buffer_64.setBit < 0  + 48 > (); // MASTER_PD_CNTL (48)
            io_data_buffer_64.setBit < 1  + 48 > (); // ANALOG_INPUT_STAB2 (49)
            io_data_buffer_64.setBit < 7  + 48 > (); // ANALOG_INPUT_STAB1 (55)
            io_data_buffer_64.setBit < 8  + 48, 2 > (); // SYSCLK_CLK_GATE (56:57)
            io_data_buffer_64.setBit < 10 + 48 > (); // DP18_RX_PD(0) (58)
            io_data_buffer_64.setBit < 11 + 48 > (); // DP18_RX_PD(1) (59)
            io_data_buffer_64.setBit < 14 + 48 > (); // TX_TRISTATE_CNTL (62)
            io_data_buffer_64.setBit < 15 + 48 > (); // VCC_REG_PD (63)
        }
        else
        {
            io_data_buffer_64.clearBit < 0  + 48 > (); // MASTER_PD_CNTL (48)
            io_data_buffer_64.clearBit < 1  + 48 > (); // ANALOG_INPUT_STAB2 (49)
            io_data_buffer_64.clearBit < 7  + 48 > (); // ANALOG_INPUT_STAB1 (55)
            io_data_buffer_64.clearBit < 8  + 48, 2 > (); // SYSCLK_CLK_GATE (56:57)
            io_data_buffer_64.clearBit < 10 + 48 > (); // DP18_RX_PD(0) (58)
            io_data_buffer_64.clearBit < 11 + 48 > (); // DP18_RX_PD(1) (59)
            io_data_buffer_64.clearBit < 14 + 48 > (); // TX_TRISTATE_CNTL (62)
            io_data_buffer_64.clearBit < 15 + 48 > (); // VCC_REG_PD (63)
        }

        return fapi2::current_err;
    }

    ///
    /// @brief mss_power_cleanup_part1(): Clean up an MBA
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba: the mba
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_mba_part1(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        // turn off functional vector

        uint8_t centaur_functional = 0;
        uint8_t mba_functional = 0;
        uint8_t unit_pos = 0;
        uint8_t memon = 0;
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint32_t> cfam_data;

        FAPI_INF("Starting mss_power_cleanup_mba_part1");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_centaur,  centaur_functional),
                 "ERROR: Cannot get ATTR_FUNCTIONAL");
        FAPI_INF("working on a centaur whose functional is %d", centaur_functional);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_mba,  mba_functional), "ERROR: Cannot get ATTR_FUNCTIONAL");
        FAPI_INF("working on an mba whose functional is %d", mba_functional);

        // But to clarify so there's no misconception, you can only turn off the clocks to the MEMS grid (Ports 2/3).
        // If you want to deconfigure Ports 0/1, there is no way to turn those clocks off.
        // The best you can do there is shut down the PHY inside DDR
        // (I think they have an ultra low power mode where you can turn off virtually everything including their PLLs, phase rotators, analogs , FIFOs, etc)
        // plus of course you can disable their I/O. I think those steps should be done no matter which port you're deconfiguring,
        // but in terms of the chip clock grid, you only get that additional power savings in the bad Port 2/3 case.
        if(centaur_functional == 1 && mba_functional == 0)
        {
            FAPI_INF("cleanup_part1 MBA not functional");
            // check that clocks are up to the DDR partition before turning it off
            // this case will only happen if we get memory up and later come back and want to
            // deconfigure it.  The first time, it may not even be up yet.
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_CLOCK_STAT_PCB, data_buffer_64), "ERROR: Cannot getScom 0x1030008");

            if(static_cast<uint64_t>(data_buffer_64) == PERV_CLOCKS_ON)
            {
                // pervasive clocks are on
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_TCM_CLOCK_STAT_PCB, data_buffer_64), "ERROR: Cannot getScom 0x3030008");

                if(static_cast<uint64_t>(data_buffer_64) == MEM_CLOCKS_ON)
                {
                    memon = 1;
                }
            }

            if(memon)
            {
                FAPI_INF("Mem Clocks On");

                if(mba_functional == 0)
                {
                    FAPI_INF("This mba is not functional, doing more transactions");

                    // Do Port 0
                    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0, data_buffer_64),
                             "ERROR: Cannot getScom CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0");
                    FAPI_TRY(set_powerdown_bits(mba_functional, data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0, data_buffer_64),
                             "ERROR: Cannot putScom CEN_MBA_DDRPHY_PC_POWERDOWN_1_P0");
                    // Do Port 1
                    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1, data_buffer_64),
                             "ERROR: Cannot getScom CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1");
                    FAPI_TRY(set_powerdown_bits(mba_functional, data_buffer_64));

                    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1, data_buffer_64),
                             "ERROR: Cannot putScom CEN_MBA_DDRPHY_PC_POWERDOWN_1_P1");
                    // From Section 10.4
                } // mba functional
            }

            //12. Grid Clock off , South Port Pair. This is done by asserting the GP bit controlling
            //TP_CHIP_DPHY23_GRID_DISABLE (Table 57 ). This must be decided during CFAMINIT . it may not be
            //dynamically updated
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  unit_pos),
                     "ERROR: Cannot get ATTR_CHIP_UNIT_POS"); // 0 = MBA01 and 1 = MBA23

            if(unit_pos == 1)
            {
                FAPI_TRY(fapi2::getCfamRegister( i_target_centaur, CEN_FSIGP4, cfam_data), "ERROR: Cannot getCfamRegister CEN_FSIGP4");

                if(mba_functional == 0)
                {
                    cfam_data.setBit<1>();
                }
                else
                {
                    cfam_data.clearBit<1>();
                }

                FAPI_TRY(fapi2::putCfamRegister( i_target_centaur, CEN_FSIGP4, cfam_data), "ERROR: Cannot putCfamRegister CEN_FSIGP4");
            } // mba 1 only code

        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_power_cleanup_mba_part1

    ///
    /// @brief mss_power_cleanup_mba_fence(): enable_partial_good_dc memn_fence_dc mems_fence_dc
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba0: the mba0
    /// @param[in] i_target_mba1: the mba1
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_mba_fence(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba0,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba1)
    {
        // turn off functional vector
        uint8_t mba_functional0, mba_functional1 = 0;
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint32_t> cfam_data;
        uint8_t memon = 0;

        FAPI_INF("Starting mss_power_cleanup_mba_fence");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_mba0,  mba_functional0));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_mba1,  mba_functional1));
        FAPI_INF("mba0 functional is %d", mba_functional0);
        FAPI_INF("mba1 functional is %d", mba_functional1);


        //enable_partial_good_dc memn_fence_dc mems_fence_dc Fencing Behavior
        //0 0 0 Normal operation, no fencing enabled
        //0 1 1 Chiplet boundary (inter chiplet nets) fencing enabled. Both
        //      bits set for full fencing. Both MBAs fenced from MBS but
        //      not from each other
        //0 0 1 Not a valid setting. Fencing enabled for MEMS chiplet boundary only.
        //0 1 0 Not a valid setting. Fencing enabled for MEMS chiplet boundary only.
        //1 0 0 No Fencing enabled .
        //1 0 1 MEMS (Ports 2/3) bad, fencing enabled to MEMN and at chiplet boundary of MEMS
        //1 1 0 MEMN (Ports 0/1) bad, fencing enabled to MEMS and at chiplet boundary of MEMN
        //1 1 1 Fencing enabled between MEMN and MEMS and at chiplet boundary.
        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_CLOCK_STAT_PCB, data_buffer_64));

        if(static_cast<uint64_t>(data_buffer_64) == PERV_CLOCKS_ON)
        {
            // pervasive clocks are on
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_TCM_CLOCK_STAT_PCB, data_buffer_64));

            if(static_cast<uint64_t>(data_buffer_64) == MEM_CLOCKS_ON)
            {
                memon = 1;
            }
        }

        if(memon)
        {
            FAPI_INF("Mem Clocks On");
            FAPI_TRY(fapi2::getScom( i_target_centaur, CEN_PCBSLMEM_GP3_REG_PCB, data_buffer_64));

            if(mba_functional0 == 0 || mba_functional1 == 0)
            {
                // one of the two are non-functional
                data_buffer_64.setBit<31>(); // enable_partial_good_dc
            }
            else
            {
                data_buffer_64.clearBit<31>();
            }

            if(mba_functional0 == 0)
            {
                data_buffer_64.setBit<18>(); // memn_fence_dc
            }
            else
            {
                data_buffer_64.clearBit<18>(); // memn_fence_dc
            }

            if(mba_functional1 == 0)
            {
                data_buffer_64.setBit<17>(); // mems_fence_dc
            }
            else
            {
                data_buffer_64.clearBit<17>(); // mems_fence_dc
            }

            FAPI_TRY(fapi2::putScom( i_target_centaur, CEN_PCBSLMEM_GP3_REG_PCB, data_buffer_64));
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_power_cleanup_mba_fence

    ///
    /// @brief mss_power_cleanup_centaur(): Clean up a centaur
    /// @param[in] i_target_centaur: the centaur
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_centaur(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur)
    {
        // turn off functional vector
        uint8_t centaur_functional = 0;
        uint8_t memon = 0;
        uint8_t pervon = 0;
        fapi2::buffer<uint64_t> data_buffer_64;

        FAPI_INF("Starting mss_power_cleanup_centaur");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, i_target_centaur,  centaur_functional),
                 "ERROR: Cannot get ATTR_FUNCTIONAL");

        if(centaur_functional == 0)
        {
            // check that clocks are up to the DDR partition before turning it off
            // this case will only happen if we get memory up and later come back and want to
            // deconfigure it.  The first time, it may not even be up yet.
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_CLOCK_STAT_PCB, data_buffer_64), "ERROR: Cannot getScom 0x1030008");

            if(static_cast<uint64_t>(data_buffer_64) == PERV_CLOCKS_ON)
            {
                // pervasive clocks are on
                pervon = 1;
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_TCM_CLOCK_STAT_PCB, data_buffer_64), "ERROR: Cannot getScom 0x3030008");

                if(static_cast<uint64_t>(data_buffer_64) == MEM_CLOCKS_ON)
                {
                    memon = 1;
                }
            }

            if(pervon || memon)
            {
                bool l_stop_mem_clks = true;
                bool l_stop_nest_clks = true;
                bool l_stop_dram_rfrsh_clks = true;
                bool l_stop_tp_clks = false;
                bool l_stop_vitl_clks = false;
                FAPI_INF("Calling p9c_cen_stopclocks");
                FAPI_TRY(p9c_cen_stopclocks(i_target_centaur, l_stop_mem_clks, l_stop_nest_clks, l_stop_dram_rfrsh_clks, l_stop_tp_clks,
                                            l_stop_vitl_clks ));

            }// clocks are on, so kill them
        } // non functional centaurs

        FAPI_INF("Ending mss_power_cleanup_centaur");

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_power_cleanup_centaur
} // extern "C"
