/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mcbist_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file mss_mcbist_common.C
/// @brief mcbist procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#include <fapi2.H>
#include <p9c_mss_mcbist.H>
#include <p9c_mss_mcbist_address.H>
#include <p9c_mss_access_delay_reg.H>
#include <fapiTestHwpDq.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{
    constexpr uint8_t MCB_TEST_NUM = 16;
    constexpr uint64_t MCB_MAX_TIMEOUT = 0000000600000000ull;

    ///
    /// @brief Will setup the required MCBIST configuration register
    /// @param[in]  i_target_mba        Centaur input mba
    /// @param[in]  i_mcbbytemask       It is used to mask bad bits read from SPD
    /// @param[in]  i_mcbrotate         Provides the number of bit to shift per burst
    /// @param[in]  i_mcbrotdata        Provides the rotate data to shift per burst
    /// @param[in]  i_sub_info
    /// @param[in]  i_str_cust_addr
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode setup_mcbist(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const mcbist_byte_mask i_mcbbytemask,
                                   const uint8_t i_mcbrotate,
                                   const uint64_t i_mcbrotdata,
                                   struct subtest_info i_sub_info[30],
                                   const char* i_str_cust_addr)
    {
        FAPI_DBG("%s:Function Setup_MCBIST", mss::c_str(i_target_mba));
        FAPI_DBG("Custom Addr Mode %s", i_str_cust_addr);
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::buffer<uint64_t> l_data_buffer_mask1a_64;
        fapi2::buffer<uint64_t> l_data_buffer_mask1b_64;
        fapi2::buffer<uint64_t> l_data_buffer_mask0_64;
        uint8_t l_bit32 = 0;
        uint8_t l_new_addr = 1;
        uint32_t i_mcbpatt = 0;
        uint32_t i_mcbtest = 0;
        uint8_t l_mba_position = 0;
        mcbist_test_mem i_mcbtest1;
        mcbist_data_gen i_mcbpatt1;
        i_mcbtest1 = CENSHMOO;
        i_mcbpatt1 = ABLE_FIVE;
        uint8_t l_index = 0;
        uint8_t l_flag = 0;
        constexpr uint64_t scom_array[8] =
        {
            CEN_MBA_MBABS0, CEN_MBA_MBABS1,
            CEN_MBA_MBABS2, CEN_MBA_MBABS3,
            CEN_MBA_MBABS4, CEN_MBA_MBABS5,
            CEN_MBA_MBABS6, CEN_MBA_MBABS7
        };

        constexpr uint64_t l_scom_array_MBS[16] =
        {
            CEN_ECC01_MBSBS2, CEN_ECC01_MBSBS3,
            CEN_ECC01_MBSBS4, CEN_ECC01_MBSBS5,
            CEN_ECC01_MBSBS6, CEN_ECC01_MBSBS7,
            CEN_ECC23_MBSBS0, CEN_ECC23_MBSBS1,
            CEN_ECC23_MBSBS2, CEN_ECC23_MBSBS3,
            CEN_ECC23_MBSBS4, CEN_ECC23_MBSBS5,
            CEN_ECC23_MBSBS6, CEN_ECC23_MBSBS7,
            CEN_ECC01_MBSBS0, CEN_ECC01_MBSBS1
        };

        const auto l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_PATTERN, i_target_mba,  i_mcbpatt));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba,  i_mcbtest));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mba_position));

        mss_conversion_testtype(i_target_mba, i_mcbtest, i_mcbtest1);
        mss_conversion_data(i_target_mba, i_mcbpatt, i_mcbpatt1);

        FAPI_TRY(mcb_reset_trap(i_target_mba));

        //should set attr for this 1st 8 or last 8
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ERROR_CAPTURE, i_target_mba,  l_bit32));

        if (l_bit32 == 1)
        {
            FAPI_DBG("%s: error capture set to last 8 Bits", mss::c_str(i_target_mba));
            FAPI_TRY(fapi2::getScom(l_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer_64));
            l_data_buffer_64.setBit<32>();
            FAPI_TRY(fapi2::putScom(l_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer_64));

            FAPI_TRY(fapi2::getScom(l_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer_64));
            l_data_buffer_64.setBit<32>();
            FAPI_TRY(fapi2::putScom(l_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer_64));

        }

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBA_WRQ0Q, l_data_buffer_64));
        l_data_buffer_64.clearBit<5>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBA_WRQ0Q, l_data_buffer_64));

        //#RRQ FIFO Mode OFF
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBA_RRQ0Q, l_data_buffer_64));
        l_data_buffer_64.setBit<6>();
        l_data_buffer_64.setBit<7>();
        l_data_buffer_64.setBit<8>();
        l_data_buffer_64.setBit<9>();
        l_data_buffer_64.setBit<10>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBA_RRQ0Q, l_data_buffer_64));

        //power bus ECC setting for random data
        //# MBA01_MBA_WRD_MODE - disbale powerbus ECC checking and correction
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBA_WRD_MODE, l_data_buffer_64));
        l_data_buffer_64.setBit<0>();
        l_data_buffer_64.setBit<1>();
        l_data_buffer_64.setBit<5>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBA_WRD_MODE, l_data_buffer_64));

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_data_buffer_64));
        l_data_buffer_64.clearBit<29>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_data_buffer_64));


        for (l_index = 0; l_index < 8; l_index++)
        {
            FAPI_TRY(fapi2::getScom(i_target_mba, scom_array[l_index], l_data_buffer_64));

            l_flag = (uint64_t(l_data_buffer_64)) ? 1 : 0;

            if (l_flag == 1)
            {
                break;
            }
        }

        for (l_index = 0; l_index < 16; l_index++)
        {
            FAPI_TRY(fapi2::getScom(l_target_centaur, l_scom_array_MBS[l_index], l_data_buffer_64));

            l_flag = (uint64_t(l_data_buffer_64)) ? 1 : 0;

            if (l_flag == 1)
            {
                break;
            }
        }

        if (l_flag == 1)
        {
            FAPI_DBG("%s:WARNING: Bit Steering  is enabled !!!", mss::c_str(i_target_mba));
        }
        else
        {
            FAPI_DBG("%s:steer mode is not enabled", mss::c_str(i_target_mba));
        }

        FAPI_TRY(cfg_mcb_test_mem(i_target_mba, i_mcbtest1, i_sub_info));

        FAPI_TRY(cfg_mcb_dgen(i_target_mba, i_mcbpatt1, i_mcbrotate, i_mcbrotdata));


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ADDR_MODES, i_target_mba,  l_new_addr));

        if (l_new_addr != 0)
        {
            FAPI_TRY(address_generation(i_target_mba, i_str_cust_addr));
        }

        FAPI_INF( "+++ Enabling Refresh +++");

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

        //Bit 0 is enable
        l_data_buffer_64.setBit<0>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));


        if (i_mcbbytemask != NONE)
        {
            FAPI_TRY(cfg_byte_mask(i_target_mba));

        }

    fapi_try_exit:
        return fapi2::current_err;

    }

    ///
    /// @brief Clears all the trap registers in MCBIST engine
    /// @param[in] i_target_mba Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_reset_trap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_mba_position = 0;
        const auto i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mba_position));

        FAPI_DBG("%s:Function - mcb_reset_trap", mss::c_str(i_target_mba));
        //Reset the MCBIST runtime counter
        FAPI_DBG("%s:Clearing the MCBIST Runtime Counter ", mss::c_str(i_target_mba));
        l_data_buffer_64.flush<0>();

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_RUNTIMECTRQ, l_data_buffer_64));
        l_data_buffer_64.clearBit<0, 37>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_RUNTIMECTRQ, l_data_buffer_64));

        l_data_buffer_64.flush<0>();

        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer_64));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Checks for dimms drop in the particular port & starts MCBIST
    /// @param[in] i_target_mna Centaur.mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode start_mcb(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint64_t l_time = 0;
        FAPI_DBG("%s:Function - start_mcb", mss::c_str(i_target_mba));

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAGRAQ, l_data_buffer_64));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba,  l_num_ranks_per_dimm));

        // Enables the address engines.  Only one LFSR is required to hit both dimms, 0b11 shown to cause fails (second lfsr is not configured)
        if (l_num_ranks_per_dimm[0][0] > 0)
        {
            FAPI_DBG("%s: Socket 0 Configured", mss::c_str(i_target_mba));
            l_data_buffer_64.setBit<24>();
            l_data_buffer_64.clearBit<25>();
        }
        else if (l_num_ranks_per_dimm[0][1] > 0)
        {
            FAPI_DBG("%s: Socket 1 Configured", mss::c_str(i_target_mba));
            l_data_buffer_64.clearBit<24>();
            l_data_buffer_64.setBit<25>();
        }
        else
        {
            FAPI_DBG("%s:No Socket found", mss::c_str(i_target_mba));
        }

        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAGRAQ, l_data_buffer_64));

        FAPI_DBG("%s:STARTING MCBIST for Centaur Target", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCB_CNTLSTATQ, l_data_buffer_64));

        if (l_data_buffer_64.getBit<0>())
        {
            FAPI_DBG("%s:MCBIST already in progess, wait till MCBIST completes",
                     mss::c_str(i_target_mba));
            return fapi2::current_err;
        }

        l_data_buffer_64.flush<0>();
        l_data_buffer_64.setBit<0>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_MAX_TIMEOUT, i_target_mba,  l_time));

        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCB_CNTLQ, l_data_buffer_64));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief check the MCBIST Configuration Register for mcb fail, in progress, done
    /// @param[in] i_target_mba Centaur.mba
    /// @param[out] o_mcb_status MCB status
    /// @param[in] i_sub_info  MCB subtest information array
    /// @param[in] i_flag  verbose flag
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode poll_mcb(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                               uint8_t* o_mcb_status,
                               struct subtest_info i_sub_info[30],
                               const uint8_t i_flag)
    {
        // return value after each SCOM access/buffer modification
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::buffer<uint64_t> l_data_buffer_trap_64;
        fapi2::buffer<uint64_t> l_stop_on_fail_buffer_64;
        //Current status of the MCB (done, fail, in progress)
        uint8_t l_mcb_done = 0;
        uint8_t l_mcb_fail = 0;
        uint8_t l_mcb_ip = 0;
        //Time out variables
        uint64_t l_mcb_timeout = 0;
        uint32_t l_count = 0;
        uint64_t l_time = 0;
        uint32_t l_time_count = 0;
        uint8_t l_index = 0;
        uint8_t l_Subtest_no = 0;
        uint64_t l_counter = 0x0ll;
        uint32_t i_mcbtest = 0;
        uint32_t l_st_ln = 0;
        uint32_t l_len = 0;
        uint32_t l_dts_0 = 0;
        uint32_t l_dts_1 = 0;
        uint8_t l_mcb_stop_on_fail = 0;
        mcbist_test_mem i_mcbtest1;
        const auto i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //Should get the attributes l_time
        uint8_t test_array_count[44] = { 0, 2, 2, 1, 1, 1, 6, 6, 30, 30,
                                         2, 7, 4, 2, 1, 5, 4, 2, 1, 1,
                                         3, 1, 1, 4, 2, 1, 1, 1, 1, 10,
                                         0, 5, 3, 3, 3, 3, 9, 4, 30, 1,
                                         2, 2, 3, 3
                                       };

        FAPI_DBG("%s:Function Poll_MCBIST", mss::c_str(i_target_mba));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_MAX_TIMEOUT, i_target_mba,  l_time));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_STOP_ON_ERROR, i_target_mba,  l_mcb_stop_on_fail));

        if (l_time == 0x0000000000000000)
        {
            l_time = MCB_MAX_TIMEOUT;
        }

        FAPI_DBG("%s:Value  of max time %016llX", mss::c_str(i_target_mba), l_time);

        while ((l_mcb_done == 0) && (l_mcb_timeout <= l_time))
        {

            FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCB_CNTLSTATQ, l_data_buffer_64));

            if (l_data_buffer_64.getBit<0>())
            {
                l_time_count++;

                if (l_time_count == 500)
                {
                    l_time_count = 0;
                    FAPI_DBG("%s:POLLING STATUS:POLLING IN PROGRESS...........",
                             mss::c_str(i_target_mba));
                    FAPI_TRY(fapi2::getScom(i_target_centaur, 0x02050000, l_data_buffer_64));
                    FAPI_TRY(l_data_buffer_64.extractToRight(l_dts_0, 0, 12));
                    FAPI_TRY(l_data_buffer_64.extractToRight(l_dts_1, 16, 12));

                    FAPI_DBG("%s:DTS Thermal Sensor 0 Results %d", mss::c_str(i_target_centaur), l_dts_0);
                    FAPI_DBG("%s:DTS Thermal Sensor 1 Results %d", mss::c_str(i_target_centaur), l_dts_1);

                    if (i_flag == 0)
                    {
                        // Read Counter Reg
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_RUNTIMECTRQ, l_data_buffer_64));
                        FAPI_TRY(l_data_buffer_64.extract(l_counter, 0, 64));
                        FAPI_DBG("%s:MCBCounter  %016llX  ", mss::c_str(i_target_mba), l_counter);

                        //Read Sub-Test number
                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBSTATAQ_ROX, l_data_buffer_64));
                        l_st_ln = 3;
                        l_len = 5;

                        FAPI_TRY(l_data_buffer_64.extract(l_Subtest_no, l_st_ln, l_len));
                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba,  i_mcbtest));
                        mss_conversion_testtype(i_target_mba, i_mcbtest, i_mcbtest1);

                        l_index = test_array_count[i_mcbtest] = {0};

                        if (l_Subtest_no < l_index)
                        {
                            switch (i_sub_info[l_Subtest_no].l_operation_type)
                            {
                                case 0:
                                    FAPI_DBG("%s:SUBTEST        :WRITE", mss::c_str(i_target_mba));
                                    break;

                                case 1:
                                    FAPI_DBG("%s:SUBTEST        :READ", mss::c_str(i_target_mba));
                                    break;

                                case 2:
                                    FAPI_DBG("%s:SUBTEST        :READ - WRITE", mss::c_str(i_target_mba));
                                    break;

                                case 3:
                                    FAPI_DBG("%s:SUBTEST        :WRITE - READ", mss::c_str(i_target_mba));
                                    break;

                                case 4:
                                    FAPI_DBG("%s:SUBTEST        :READ - WRITE - READ", mss::c_str(i_target_mba));
                                    break;

                                case 5:
                                    FAPI_DBG("%s:SUBTEST        :READ - WRITE - WRITE", mss::c_str(i_target_mba));
                                    break;

                                case 6:
                                    FAPI_DBG("%s:SUBTEST        :RANDOM COMMAND SEQUENCE", mss::c_str(i_target_mba));
                                    break;

                                case 7:
                                    FAPI_DBG("%s:SUBTEST        :GOTO SUBTEST N OR REFRESH ONLY", mss::c_str(i_target_mba));
                                    break;

                                default:
                                    FAPI_DBG("%s:Wrong Operation selected for Subtest", mss::c_str(i_target_mba));
                            }

                            switch (i_sub_info[l_Subtest_no].l_data_mode)
                            {
                                case 0:
                                    FAPI_DBG("%s:DATA MODE      :FIXED DATA", mss::c_str(i_target_mba));
                                    break;

                                case 1:
                                    FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_FORWARD", mss::c_str(i_target_mba));
                                    break;

                                case 2:
                                    FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_REVERSE", mss::c_str(i_target_mba));
                                    break;

                                case 3:
                                    FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC FORWARD", mss::c_str(i_target_mba));
                                    break;

                                case 4:
                                    FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC REVERSE", mss::c_str(i_target_mba));
                                    break;

                                case 5:
                                    FAPI_DBG("%s:DATA MODE      :DATA EQUAL ADDRESS", mss::c_str(i_target_mba));
                                    break;

                                case 6:
                                    FAPI_DBG("%s:DATA MODE      :DATA ROTATE LEFT", mss::c_str(i_target_mba));
                                    break;

                                case 7:
                                    FAPI_DBG("%s:DATA MODE      :DATA ROTATE RIGHT", mss::c_str(i_target_mba));
                                    break;

                                default:
                                    FAPI_DBG("%s:Wrong Data Mode selected for Subtest", mss::c_str(i_target_mba));
                            }

                            switch (i_sub_info[l_Subtest_no].l_addr_mode)
                            {
                                case 0:
                                    FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL FORWARD", mss::c_str(i_target_mba));
                                    break;

                                case 1:
                                    FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL REVERSE", mss::c_str(i_target_mba));
                                    break;

                                case 2:
                                    FAPI_DBG("%s:ADDRESS MODE   :RANDOM FORWARD", mss::c_str(i_target_mba));
                                    break;

                                case 3:
                                    FAPI_DBG("%s:ADDRESS MODE   :RANDOM REVERSE", mss::c_str(i_target_mba));
                                    break;

                                default:
                                    FAPI_DBG("%s:Wrong Address Mode selected for Subtest", mss::c_str(i_target_mba));
                            }
                        } // if subtest no  < index
                    } // if i_flag == 0
                } // if time count == 500

                l_mcb_ip = 1;
            }  // if getBit<0>

            if (l_data_buffer_64.getBit<1>())
            {
                FAPI_DBG("%s:POLLING STATUS:MCBIST POLLING DONE",
                         mss::c_str(i_target_mba));
                FAPI_DBG("%s:MCBIST is done", mss::c_str(i_target_mba));
                l_mcb_ip = 0;
                l_mcb_done = 1;

                FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBCFGQ, l_data_buffer_trap_64));
                l_data_buffer_64.clearBit<60>();
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBCFGQ, l_data_buffer_trap_64));
            }

            if (l_data_buffer_64.getBit<2>())
            {
                l_mcb_fail = 1;
                FAPI_DBG("%s:POLLING STATUS:MCBIST FAILED", mss::c_str(i_target_mba));

                if (l_mcb_stop_on_fail == 1) //if stop on error is 1, break after the current subtest completes
                {
                    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBCFGQ, l_stop_on_fail_buffer_64));
                    l_stop_on_fail_buffer_64.setBit<62>();
                    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBCFGQ, l_stop_on_fail_buffer_64));

                    FAPI_DBG("%s:MCBIST will break after Current Subtest",
                             mss::c_str(i_target_mba));

                    while (l_mcb_done == 0) // Poll till MCBIST is done
                    {
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCB_CNTLSTATQ, l_data_buffer_64));

                        if (l_data_buffer_64.getBit<1>())
                        {
                            l_mcb_ip = 0;
                            l_mcb_done = 1;

                            FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBCFGQ, l_data_buffer_trap_64));
                            l_data_buffer_64.clearBit<60>();
                            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBCFGQ, l_data_buffer_trap_64));

                            FAPI_DBG("%s:MCBIST Done", mss::c_str(i_target_mba));
                            l_stop_on_fail_buffer_64.clearBit<62>();
                            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBCFGQ, l_stop_on_fail_buffer_64));

                        }
                    }
                }
            }

            l_mcb_timeout++;

            FAPI_ASSERT(l_mcb_timeout < l_time,
                        fapi2::CEN_MSS_MCBIST_TIMEOUT_ERROR().
                        set_MBA_TARGET(i_target_mba),
                        "poll_mcb:Maximum time out");

            l_count++;
        }

        FAPI_DBG("%s:*************************************************", mss::c_str(i_target_mba));
        FAPI_DBG("%s:MCB done bit : %d", mss::c_str(i_target_mba), l_mcb_done);
        FAPI_DBG("%s:MCB fail bit : %d", mss::c_str(i_target_mba), l_mcb_fail);
        FAPI_DBG("%s:MCB IP   bit : %d", mss::c_str(i_target_mba), l_mcb_ip);
        FAPI_DBG("%s:*************************************************", mss::c_str(i_target_mba));

        if ((l_mcb_done == 1) && (l_mcb_fail == 1) && (l_mcb_stop_on_fail == true))
        {
            *o_mcb_status = 1; /// MCB fail
        }
        else if ((l_mcb_done == 1) && (l_mcb_fail == 0))
        {
            *o_mcb_status = 0;//pass;
        }
        else if ((l_mcb_done == 0) && (l_mcb_ip == 1) && (l_mcb_timeout == l_time))
        {
            *o_mcb_status = 1;//fail;
        }

        if (*o_mcb_status == 1)
        {
            FAPI_DBG("poll_mcb: MCBIST failed");
            return fapi2::FAPI2_RC_FALSE;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief print the mcbist cdimm error map
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] i_mcb_fail_160
    /// @param[in] i_port Centaur input port
    /// @param[in] i_array  error array
    /// @param[in] i_number  Highest index in array w error
    /// @param[in] i_data_buf_port MCB data mask
    /// @param[in] i_data_buf_spare MCB data mask
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_error_map_print(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                          const fapi2::variable_buffer& i_mcb_fail_160,
                                          const uint8_t i_port,
                                          const uint8_t i_array[DIMM_DQ_SPD_DATA_SIZE],
                                          const uint8_t i_number,
                                          const fapi2::buffer<uint64_t> i_data_buf_port,
                                          const fapi2::buffer<uint64_t> i_data_buf_spare)
    {
        uint8_t l_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_PORTS_PER_MBA] = {0};
        uint8_t l_rankpair_table[MAX_RANKS_PER_PORT] = {0};
        uint8_t l_cur_rank = 0;
        uint16_t l_index0, l_index1, l_byte, l_nibble = 0;
        uint8_t l_max_rank = 0;
        uint8_t l_rank_pair = 0;
        char l_str1[200] = "";
        uint8_t l_rank = 0;
        uint8_t l_mba_position = 0;
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint64_t l_generic_buffer = 0;
        uint32_t l_sbit, l_len;
        uint16_t l_output = 0;
        uint8_t l_index, l_value, l_value1;
        uint8_t l_marray0[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_num, io_num, l_inter, l_num2, l_index2;
        fapi2::variable_buffer l_data_buffer1_64(64), l_data_buffer3_64(64);
        FAPI_INF("Function MCB_ERROR_MAP_PRINT");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mba_position));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  dram_stack));

        if (dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm));
        }
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm));
        }

        l_max_rank = l_num_ranks_per_dimm[i_port][0] + l_num_ranks_per_dimm[i_port][1];

        FAPI_TRY(mss_getrankpair(i_target_mba, i_port, 0, &l_rank_pair, l_rankpair_table));

        FAPI_ASSERT(l_max_rank != 0,
                    fapi2::CEN_MSS_PLACE_HOLDER_ERROR(),
                    "%s: NO RANK FOUND ON PORT %d ", mss::c_str(i_target_mba), i_port);

        if (i_port == 0)
        {
            l_sbit = 0;
            l_len = 16;
            FAPI_TRY(i_data_buf_port.extract(l_generic_buffer, 0, 64));
            FAPI_TRY(i_data_buf_spare.extractToRight(l_output, l_sbit, l_len));

            if (l_mba_position == 0)
            {
                FAPI_DBG("%s:################# MBA01 ###########################\n", mss::c_str(i_target_mba));
                FAPI_DBG("%s:################# PORT0  ERROR MAP #################\n", mss::c_str(i_target_mba));
            }
            else
            {
                FAPI_DBG("%s:################# MBA23 ###########################\n", mss::c_str(i_target_mba));
                FAPI_DBG("%s:################# PORT0 ERROR MAP #################\n", mss::c_str(i_target_mba));
            }

            FAPI_DBG("%s:Byte      00112233445566778899", mss::c_str(i_target_mba));
            FAPI_DBG("%s:Nibble    01010101010101010101", mss::c_str(i_target_mba));
            FAPI_DBG("%s:MASK      %016llX%04X\n", mss::c_str(i_target_mba), l_generic_buffer, l_output);
        }
        else
        {
            l_sbit = 16;
            l_len = 16;
            FAPI_TRY(i_data_buf_port.extract(l_generic_buffer, 0, 64));
            FAPI_TRY(i_data_buf_spare.extractToRight(l_output, l_sbit, l_len));

            if (l_mba_position == 0)
            {
                FAPI_DBG("%s:################# MBA01 ###########################\n", mss::c_str(i_target_mba));
                FAPI_DBG("%s:################# PORT1 ERROR MAP #################\n", mss::c_str(i_target_mba));
            }
            else
            {
                FAPI_DBG("%s:################# MBA23 ###########################\n", mss::c_str(i_target_mba));
                FAPI_DBG("%s:################# PORT1 ERROR MAP #################\n", mss::c_str(i_target_mba));
            }

            FAPI_DBG("%s:Byte      00112233445566778899", mss::c_str(i_target_mba));
            FAPI_DBG("%s:Nibble    01010101010101010101", mss::c_str(i_target_mba));
            FAPI_DBG("%s:MASK      %016llX%04X\n", mss::c_str(i_target_mba), l_generic_buffer, l_output);
        }

        l_data_buffer1_64.flush<0>();

        l_num = 0;

        for (l_index = 0; l_index < i_number; l_index++)
        {
            l_value = i_array[l_index];
            l_inter = (l_value / 4);
            l_num2 = l_num - 1;

            if (l_inter == l_marray0[l_num2] && (l_num != 0))
            {
                continue;
            }

            l_value1 = l_inter;
            l_marray0[l_num] = l_value1;
            l_num++;
        }

        io_num = l_num;

        l_cur_rank = 0;
        l_rank = 0;
        l_num = 0;
        l_value = 0;

        FAPI_TRY(mss_getrankpair(i_target_mba, i_port, 0, &l_rank_pair, l_rankpair_table));

        for (l_cur_rank = 0; l_cur_rank < l_max_rank; l_cur_rank++)
        {
            l_index2 = 0;
            l_num = 0;
            l_rank = l_rankpair_table[l_cur_rank];
            sprintf(l_str1, "%s:%-4s%d%5s", mss::c_str(i_target_mba), "RANK", l_rank, "");

            for (l_byte = 0; l_byte < MAX_BYTES_PER_RANK; l_byte++)
            {
                for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble++)
                {
                    l_value = l_marray0[l_num];
                    l_index0 = (l_rank * 20) + (l_byte * 2) + l_nibble;
                    l_index2 = (l_byte * 2) + l_nibble;
                    l_index1 = l_index0;
                    //FAPI_DBG("l_rank %x  l_index0 %x  l_index2 %x", l_rank, l_index0, l_index2);

                    if ((l_value == l_index2) && (l_num < io_num))
                    {
                        strcat(l_str1, "M");
                        l_num++;
                    }
                    else
                    {
                        if (i_mcb_fail_160.isBitSet(l_index1))
                        {
                            strcat(l_str1, "X");
                        }
                        else
                        {
                            strcat(l_str1, ".");
                        }
                    }
                }
            }

            FAPI_DBG("%s", l_str1);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Reads the nibblewise Error map registers into o_error_map
    /// @param[in] i_target_mba Centaur input mba
    /// @param[out] o_error_map[][8][10][2]   Contains the error map
    /// @param[in] i_CDarray0[80]
    /// @param[in] i_CDarray1[80]
    /// @param[in] count_bad_dq[2]
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_error_map(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                    uint8_t o_error_map[MAX_PORTS_PER_MBA][MAX_RANKS_PER_PORT][MAX_BYTES_PER_RANK][MAX_NIBBLES_PER_BYTE],
                                    uint8_t i_CDarray0[DIMM_DQ_SPD_DATA_SIZE],
                                    uint8_t i_CDarray1[DIMM_DQ_SPD_DATA_SIZE],
                                    uint8_t count_bad_dq[2])
    {
        fapi2::buffer<uint64_t> l_mcbem1ab;
        fapi2::buffer<uint64_t> l_mcbem2ab;
        fapi2::buffer<uint64_t> l_mcbem3ab;
        fapi2::variable_buffer l_mcb_fail_160(160);
        fapi2::variable_buffer l_mcb_fail1_160(160);
        fapi2::variable_buffer l_ISDIMM_BUF1(64), l_ISDIMM_BUF0(64);
        fapi2::variable_buffer l_ISDIMM_spare1(8), l_ISDIMM_spare0(8);
        uint8_t l_max_rank0, l_max_rank1;
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> i_target_centaur;
        uint16_t l_index0 = 0;
        uint32_t l_index1 = 0;
        uint8_t l_port = 0;
        uint8_t l_rank = 0;
        uint8_t l_byte = 0;
        uint8_t l_nibble = 0;
        uint8_t l_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_PORTS_PER_MBA] = {0};
        uint8_t l_mba_position = 0;
        uint8_t rank_pair = 0;
        uint8_t i_byte = 0;
        uint8_t i_nibble = 0;
        uint8_t i_input_index_u8 = 0;
        uint8_t o_val = 0;
        uint8_t i_byte1 = 0;
        uint8_t i_nibble1 = 0;
        uint8_t l_zmode_port = 0;
        uint8_t l_zmode = 0;
        uint8_t l_index = 0;
        uint8_t l_i = 0;
        uint8_t l_number = 0;
        uint8_t l_value = 0;
        uint8_t l_value1 = 0;
        uint8_t l_number1 = 0;//l_cur_rank,
        uint8_t l_array[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_marray11[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_array0[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_marray0[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_array1[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_marray1[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_marray[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t cdimm_dq0[ISDIMM_MAX_DQ_72] = { 0 };
        uint8_t cdimm_dq1[ISDIMM_MAX_DQ_72] = { 0 };
        uint8_t cdimm_dq[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_isarray1[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_isarray0[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_isarray[DIMM_DQ_SPD_DATA_SIZE] = { 0 };
        uint8_t l_rankpair_table[MAX_RANKS_PER_PORT] = {0};
        fapi2::buffer<uint64_t> l_data_buffer1_64, l_data_buffer3_64,
              l_data_buf_port0, l_data_buf_port1, l_data_buf_spare;
        uint64_t l_generic_buffer0 = 0;
        uint64_t l_generic_buffer1 = 0;
        uint64_t l_generic_buffer = 0;
        uint32_t l_sbit = 0;
        uint32_t l_len = 0;
        uint8_t l_output0 = 0;
        uint8_t l_output1 = 0;
        uint8_t l_output = 0;
        uint8_t l_j = 0;
        input_type l_input_type_e = ISDIMM_DQ;
        uint8_t valid_rank[MAX_RANKS_PER_PORT] = {0};
        char l_str[200] = "";
        uint8_t l_max_bytes = 9;
        uint8_t l_max_rank = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_port_index = 0;
        FAPI_DBG("%s:Function MCB_ERROR_MAP", mss::c_str(i_target_mba));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mba_position));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  dram_stack));

        if (dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm));
        }
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm));
        }

        l_max_rank0 = l_num_ranks_per_dimm[0][0] + l_num_ranks_per_dimm[0][1];
        l_max_rank1 = l_num_ranks_per_dimm[1][0] + l_num_ranks_per_dimm[1][1];
        i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        if (l_mba_position == 0)
        {
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMA1Q, l_mcbem1ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem1ab), 0, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMA2Q, l_mcbem2ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem2ab), 60, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMA3Q, l_mcbem3ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem3ab), 120, 40, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMB1Q, l_mcbem1ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem1ab), 0, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMB2Q, l_mcbem2ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem2ab), 60, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBEMB3Q, l_mcbem3ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem3ab), 120, 40, 0));
        }
        else if (l_mba_position == 1)
        {
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMA1Q, l_mcbem1ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem1ab), 0, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMA2Q, l_mcbem2ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem2ab), 60, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMA3Q, l_mcbem3ab));

            FAPI_TRY(l_mcb_fail_160.insert(uint64_t(l_mcbem3ab), 120, 40, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMB1Q, l_mcbem1ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem1ab), 0, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMB2Q, l_mcbem2ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem2ab), 60, 60, 0));
            FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBEMB3Q, l_mcbem3ab));

            FAPI_TRY(l_mcb_fail1_160.insert(uint64_t(l_mcbem3ab), 120, 40, 0));
        }

        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            FAPI_TRY(mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank));

            if (l_port == 0)
            {
                l_max_rank = l_max_rank0;
            }
            else
            {
                l_max_rank = l_max_rank1;
            }

            for (uint8_t l_rank_index = 0; l_rank_index < l_max_rank; l_rank_index++)
            {
                l_rank = valid_rank[l_rank_index];

                for (l_byte = 0; l_byte < MAX_BYTES_PER_RANK; l_byte++)
                {
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble++)
                    {
                        if (l_port == 0 && l_zmode == 1 && l_zmode_port == 1)
                        {
                            continue;
                        }
                        else if (l_port == 1 && l_zmode == 1 && l_zmode_port == 0)
                        {
                            continue;
                        }
                        else if (l_port == 0)
                        {
                            l_index0 = (l_rank * 20) + (l_byte * 2) + l_nibble;
                            l_index1 = l_index0;

                            if ((l_mcb_fail_160.isBitSet(l_index1)))
                            {
                                o_error_map[l_port][l_rank][l_byte][l_nibble] = 1;
                            }
                            else
                            {
                                o_error_map[l_port][l_rank][l_byte][l_nibble] = 0;
                            }
                        }
                        else if (l_port == 1)
                        {
                            l_index0 = (l_rank * 20) + (l_byte * 2) + l_nibble;
                            l_index1 = l_index0;

                            if ((l_mcb_fail1_160.isBitSet(l_index1)))
                            {
                                o_error_map[l_port][l_rank][l_byte][l_nibble] = 1;
                            }
                            else
                            {
                                o_error_map[l_port][l_rank][l_byte][l_nibble] = 0;
                            }
                        }
                    }
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_attr_eff_dimm_type_u8));

        l_i = 0;
        l_data_buffer1_64.flush<0>();
        l_port_index = 0;

        while (l_port_index < MAX_PORTS_PER_MBA)
        {
            l_data_buffer1_64.flush<0>();
            l_data_buffer3_64.flush<0>();

            if (l_mba_position == 0)
            {
                if (l_port_index == 0)
                {
                    l_i = 0;
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buf_port0));
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buf_spare));

                    for (l_index = 0; l_index < 64; l_index++)
                    {
                        if (l_data_buf_port0.getBit(l_index))
                        {
                            l_array0[l_i] = l_index;
                            l_i++;
                        }
                    }

                    for (l_index = 0; l_index < 16; l_index++)
                    {
                        if (l_data_buf_spare.getBit(l_index))
                        {
                            l_array0[l_i] = l_index + 64;
                            l_i++;
                        }
                    }

                    l_number1 = l_i;
                }

                else
                {
                    l_i = 0;
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buf_port1));
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buf_spare));

                    for (l_index = 0; l_index < 64; l_index++)
                    {
                        if (l_data_buf_port1.getBit(l_index))
                        {
                            l_array1[l_i] = l_index;
                            l_i++;
                        }
                    }

                    for (l_index = 16; l_index < 32; l_index++)
                    {
                        if (l_data_buf_spare.getBit(l_index))
                        {
                            l_array1[l_i] = l_index + 64 - 16;
                            l_i++;
                        }
                    }

                    l_number = l_i;
                }
            }
            else
            {
                if (l_port_index == 0)
                {
                    l_i = 0;
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buf_spare));

                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buf_port0));

                    for (l_index = 0; l_index < 64; l_index++)
                    {
                        if (l_data_buf_port0.getBit(l_index))
                        {
                            l_array0[l_i] = l_index;
                            l_i++;
                        }
                    }

                    for (l_index = 0; l_index < 16; l_index++)
                    {
                        if (l_data_buf_spare.getBit(l_index))
                        {
                            l_array0[l_i] = l_index + 64;
                            l_i++;
                        }
                    }

                    l_number1 = l_i;
                }
                else
                {
                    l_i = 0;
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buf_spare));
                    FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q, l_data_buf_port1));

                    for (l_index = 0; l_index < 64; l_index++)
                    {
                        if (l_data_buf_port1.getBit(l_index))
                        {
                            l_array1[l_i] = l_index;
                            l_i++;
                        }
                    }

                    for (l_index = 16; l_index < 32; l_index++)
                    {
                        if (l_data_buf_spare.getBit(l_index))
                        {
                            l_array1[l_i] = l_index + 64 - 16;
                            l_i++;
                        }
                    }

                    l_number = l_i;
                }
            }

            ++l_port_index;
        }

        //Conversion from CDIMM larray to ISDIMM larray
        //port 0
        for (l_i = 0; l_i < ISDIMM_MAX_DQ_72; l_i++)
        {
            FAPI_TRY(rosetta_map(i_target_mba, 0, l_input_type_e, l_i, 0, o_val));
            cdimm_dq0[o_val] = l_i;
        }

        //port 1
        for (l_i = 0; l_i < ISDIMM_MAX_DQ_72; l_i++)
        {
            FAPI_TRY(rosetta_map(i_target_mba, 1, l_input_type_e, l_i, 0, o_val));
            cdimm_dq1[o_val] = l_i;
        }

        uint8_t l_num, io_num, io_num0, io_num1, l_inter, l_flag, l_n;
        l_n = 0;
        io_num0 = 0;
        io_num1 = 0;
        l_port = 0;

        while (l_port < MAX_PORTS_PER_MBA)
        {
            l_num = 0;

            if (l_port == 0)
            {
                for (l_index = 0; l_index < l_number1; l_index++)
                {
                    l_array[l_index] = l_array0[l_index];
                }

                l_n = l_number1;
                FAPI_TRY(mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, l_rankpair_table));

                for (l_i = 0; l_i < ISDIMM_MAX_DQ_72; l_i++)
                {
                    cdimm_dq[l_i] = cdimm_dq0[l_i];
                }
            }
            else
            {
                for (l_index = 0; l_index < l_number; l_index++)
                {
                    l_array[l_index] = l_array1[l_index];
                    l_n = l_number;
                }

                FAPI_TRY(mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, l_rankpair_table));

                for (l_i = 0; l_i < ISDIMM_MAX_DQ_72; l_i++)
                {
                    cdimm_dq[l_i] = cdimm_dq1[l_i];
                }
            }

            //Getting array for converting CDIMM values as index and ISDIMM values as value of array for that index
            for (l_index = 0; l_index < l_n; l_index++)
            {
                l_value = l_array[l_index];
                l_value1 = cdimm_dq[l_value];

                if (l_value >= 72)
                {
                    l_value1 = 255;
                }

                l_isarray[l_index] = l_value1;
            }

            if (l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            {
                //For ISDIMM marray
                for (l_index = 0; l_index < l_n; l_index++)
                {
                    l_value = l_isarray[l_index];
                    l_inter = (l_value / 4);
                    l_value1 = l_num - 1;
                    l_marray[l_num] = l_inter * 4;
                    l_num++;
                }
            }
            else
            {
                //For CDIMM marray
                for (l_index = 0; l_index < l_n; l_index++)
                {
                    l_value = l_array[l_index];
                    l_inter = (l_value / 4);
                    l_value1 = l_num - 1;
                    l_marray[l_num] = l_inter * 4;
                    l_num++;
                }
            }

            //Loop to sort Masked ISDIMM array
            for (l_i = 0; l_i < l_num - 1; l_i++)
            {
                for (l_j = l_i + 1; l_j < l_num; l_j++)
                {
                    if (l_marray[l_i] > l_marray[l_j])
                    {
                        l_value = l_marray[l_j];
                        l_marray[l_j] = l_marray[l_i];
                        l_marray[l_i] = l_value;
                    }
                }
            }

            //loop to remove repetition elements
            l_j = 0;

            for (l_i = 0; l_i < l_num; l_i++)
            {
                l_flag = 0;

                if ((l_marray[l_i] == l_marray[l_i + 1]) && (l_num != 0))
                {
                    l_flag = 1;
                }

                if (l_flag == 0)
                {
                    l_marray11[l_j] = l_marray[l_i];
                    l_j++;
                }
            }

            l_num = l_j;

            if (l_port == 0)
            {
                io_num0 = l_num;

                if (io_num0 >= 21)
                {
                    io_num0 = 21;
                }

                for (l_index = 0; l_index < io_num0; l_index++)
                {
                    l_marray0[l_index] = l_marray11[l_index];
                }

                for (l_index = 0; l_index < l_number1; l_index++)
                {

                    l_isarray0[l_index] = l_isarray[l_index];
                }
            }
            else
            {
                io_num1 = l_num;

                if (io_num1 >= 21)
                {
                    io_num1 = 21;
                }

                for (l_index = 0; l_index < io_num1; l_index++)
                {
                    l_marray1[l_index] = l_marray11[l_index];
                }

                for (l_index = 0; l_index < l_number; l_index++)
                {

                    l_isarray1[l_index] = l_isarray[l_index];
                }
            }

            l_port++;
        }

        count_bad_dq[0] = l_number1;
        count_bad_dq[1] = l_number;

        for (l_i = 0; l_i < l_number1; l_i++)
        {
            i_CDarray0[l_i] = l_array0[l_i];
        }

        for (l_i = 0; l_i < l_number; l_i++)
        {
            i_CDarray1[l_i] = l_array1[l_i];
        }

        if(l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)  //Calling ISDIMM error mAP and LRDIMM
        {
            FAPI_DBG("%s:#################  Error MAP for ISDIMM #################",
                     mss::c_str(i_target_mba));

            for (l_port = 0; l_port < 2; l_port++)
            {
                if (l_port == 0)
                {
                    l_max_rank = l_max_rank0;

                    io_num = io_num0;

                    for (l_index = 0; l_index < io_num; l_index++)
                    {
                        l_marray[l_index] = l_marray0[l_index];
                    }
                }
                else
                {
                    l_max_rank = l_max_rank1;

                    io_num = io_num1;

                    for (l_index = 0; l_index < io_num; l_index++)
                    {
                        l_marray[l_index] = l_marray1[l_index];
                    }
                }

                if (l_max_rank == 0)
                {
                    FAPI_DBG("%s: NO RANKS FOUND ON  PORT  %d", mss::c_str(i_target_mba), l_port);
                }
                else
                {
                    //To set the mask print in error map
                    l_value = 0;

                    if (l_port == 0)
                    {
                        //For Port 0
                        for (l_index = 0; l_index < l_number1; l_index++)
                        {
                            l_flag = 0;
                            l_value = l_isarray0[l_index];

                            if (l_value >= 72)
                            {
                                l_flag = 1;
                            }

                            if ((l_value >= 64) && (l_value < 72))
                            {
                                l_value1 = l_value - 64;
                                l_flag = 2;
                                FAPI_TRY(l_ISDIMM_spare0.setBit(l_value1));
                            }

                            if (l_flag == 0)
                            {
                                FAPI_TRY(l_ISDIMM_BUF0.setBit(l_value));
                            }
                        }

                        l_generic_buffer0 = 0;
                        l_output0 = 0;
                        FAPI_TRY(l_ISDIMM_BUF0.extract(l_generic_buffer0, 0, 64));
                        l_sbit = 0;
                        l_len = 8;
                        FAPI_TRY(l_ISDIMM_spare0.extractToRight(l_output0, l_sbit, l_len));
                        l_generic_buffer = l_generic_buffer0;
                        l_output = l_output0;
                    }
                    else
                    {
                        for (l_index = 0; l_index < l_number; l_index++)
                        {
                            l_flag = 0;
                            l_value = l_isarray1[l_index];

                            if (l_value >= 72)
                            {
                                l_flag = 1;
                            }

                            if ((l_value >= 64) && (l_value < 72))
                            {
                                l_value1 = l_value - 64;
                                l_flag = 2;
                                FAPI_TRY(l_ISDIMM_spare1.setBit(l_value1));
                            }

                            if (l_flag == 0)
                            {
                                FAPI_TRY(l_ISDIMM_BUF1.setBit(l_value));
                            }
                        }

                        l_generic_buffer1 = 0;
                        l_output1 = 0;
                        FAPI_TRY(l_ISDIMM_BUF1.extract(l_generic_buffer1, 0, 64));
                        l_sbit = 0;
                        l_len = 8;
                        FAPI_TRY(l_ISDIMM_spare1.extractToRight(l_output1, l_sbit, l_len));
                        l_generic_buffer = l_generic_buffer1;
                        l_output = l_output1;
                    }

                    //Mask calculation Ends
                    if (l_mba_position == 0)
                    {
                        //FAPI_DBG("%s:MASK      %016llX%02X\n",mss::c_str(i_target_mba),l_generic_buffer0,l_output0);
                        FAPI_DBG("%s:################# MBA01 ###########################\n", mss::c_str(i_target_mba));
                        FAPI_DBG("%s:################# PORT%d ERROR MAP #################\n", mss::c_str(i_target_mba), l_port);
                        FAPI_DBG("%s:Byte      001122334455667788", mss::c_str(i_target_mba));
                        FAPI_DBG("%s:Nibble    010101010101010101", mss::c_str(i_target_mba));
                        FAPI_DBG("%s:MASK      %016llX%02X\n", mss::c_str(i_target_mba), l_generic_buffer, l_output);
                    }
                    else
                    {
                        FAPI_DBG("%s:################# MBA23 ###########################\n", mss::c_str(i_target_mba));
                        FAPI_DBG(
                            "%s:################# PORT%d ERROR MAP #################\n", mss::c_str(i_target_mba), l_port);
                        FAPI_DBG("%s:Byte      001122334455667788", mss::c_str(i_target_mba));
                        FAPI_DBG("%s:Nibble    010101010101010101", mss::c_str(i_target_mba));
                        FAPI_DBG("%s:MASK      %016llX%02X\n", mss::c_str(i_target_mba), l_generic_buffer, l_output);
                    }

                    for (uint8_t i = 0; i < l_max_rank; i++)
                    {
                        l_num = 0;
                        FAPI_TRY(mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank));

                        l_rank = valid_rank[i];
                        sprintf(l_str, "%s:%-4s%d%5s", mss::c_str(i_target_mba), "RANK", l_rank, "");
                        l_flag = 0;

                        for (i_byte = 0; i_byte < l_max_bytes; i_byte++)
                        {
                            for (i_nibble = 0; i_nibble < MAX_NIBBLES_PER_BYTE; i_nibble++)
                            {
                                l_flag = 0;
                                l_inter = l_marray[l_num];

                                i_input_index_u8 = (BITS_PER_BYTE * i_byte) + (BITS_PER_NIBBLE * i_nibble);

                                if ((l_inter == i_input_index_u8) && (l_num < io_num))
                                {
                                    l_num++;
                                    l_flag = 1;
                                }

                                FAPI_TRY(rosetta_map(i_target_mba, l_port,
                                                     l_input_type_e, i_input_index_u8,
                                                     0, o_val));

                                i_byte1 = o_val / BITS_PER_BYTE;
                                i_nibble1 = o_val % BITS_PER_BYTE;

                                if (i_nibble1 > 3)
                                {
                                    i_nibble1 = 1;
                                }
                                else
                                {
                                    i_nibble1 = 0;
                                }

                                if (l_flag == 1)
                                {
                                    strcat(l_str, "M");
                                }
                                else
                                {
                                    if (o_error_map[l_port][l_rank][i_byte1][i_nibble1] == 1)
                                    {
                                        strcat(l_str, "X");
                                    }
                                    else
                                    {
                                        strcat(l_str, ".");
                                    }
                                }
                            } // for nibble
                        } // for byte
                    } // for rank
                } // ranks found
            } // for each port
        } //custom dimm yes

        else //Calling CDIMM error Map print
        {
            FAPI_DBG("%s:################# CDIMM ERROR MAP ###########################\n", mss::c_str(i_target_mba));
            l_port = 0;
            mcb_error_map_print(i_target_mba, l_mcb_fail_160, l_port, l_array0,
                                l_number1, l_data_buf_port0, l_data_buf_spare);

            l_port = 1;
            mcb_error_map_print(i_target_mba, l_mcb_fail1_160, l_port, l_array1,
                                l_number, l_data_buf_port1, l_data_buf_spare);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Based on parameters passed we write data into Register being passed
    /// @param[in]   i_target_mba               Centaur input mba
    /// @param[in]   i_reg_addr                 Register address
    /// @param[in]   i_operation_type           Operation Type
    /// @param[in]   i_cfg_test_123_cmd         Integer value
    /// @param[in]   i_addr_mode                Sequential or Random address modes
    /// @param[in]   i_data_mode                Data Mode
    /// @param[in]   i_done                     Done Bit
    /// @param[in]   i_data_select_mode         Different BURST modes or DEFAULT
    /// @param[in]   i_addr_select_mode         Address Select mode
    /// @param[in]   i_testnumber               Subtest number
    /// @param[in]   i_testnumber1              Subtest number
    /// @param[in]   i_total_subtest_no
    /// @param[in]   i_sub_info                 Subtest info array
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_write_test_mem(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint64_t i_reg_addr,
                                         const mcbist_oper_type i_operation_type,
                                         const uint8_t i_cfg_test_123_cmd,
                                         const mcbist_addr_mode i_addr_mode,
                                         const mcbist_data_mode i_data_mode,
                                         const uint8_t i_done,
                                         const mcbist_data_select_mode i_data_select_mode,
                                         const mcbist_add_select_mode i_addr_select_mode,
                                         const uint8_t i_testnumber,
                                         const uint8_t i_testnumber1,
                                         const uint8_t i_total_subtest_no,
                                         struct subtest_info i_sub_info[30])
    {
        uint8_t l_index = 0;
        uint8_t l_operation_type = i_operation_type;
        uint8_t l_cfg_test_123_cmd = i_cfg_test_123_cmd;
        uint8_t l_addr_mode = i_addr_mode;
        uint8_t l_data_mode = i_data_mode;
        uint8_t l_data_select_mode = i_data_select_mode;
        uint8_t l_addr_select_mode = i_addr_select_mode;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_done_bit = 0;

        FAPI_DBG("%s:Function mcb_write_test_mem", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, i_reg_addr, l_data_buffer_64));

        l_index = i_testnumber * (MCB_TEST_NUM);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));

        if (l_done_bit == 1)
        {
            return fapi2::FAPI2_RC_FALSE;
        }

        i_sub_info[i_testnumber1].l_operation_type = l_operation_type;
        i_sub_info[i_testnumber1].l_data_mode = l_data_mode;
        i_sub_info[i_testnumber1].l_addr_mode = l_addr_mode;

        // Operation type
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_operation_type, l_index, 3));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_cfg_test_123_cmd, l_index + 3, 3));
        // ADDR MODE
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_addr_mode, l_index + 6, 2));
        // DATA MODE
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_data_mode, l_index + 8, 3));
        // Done bit
        FAPI_TRY(l_data_buffer_64.insertFromRight(i_done, l_index + 11, 1));
        // Data Select Mode
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_data_select_mode, l_index + 12, 2));

        // Address Select mode
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_addr_select_mode, l_index + 14, 2));

        FAPI_TRY(fapi2::putScom(i_target_mba, i_reg_addr, l_data_buffer_64));
        FAPI_TRY(fapi2::getScom(i_target_mba, i_reg_addr, l_data_buffer_64));

        FAPI_DBG("%s:SUBTEST %d of %d in Progress.................... ",
                 mss::c_str(i_target_mba), i_testnumber1, i_total_subtest_no);
        FAPI_DBG("%s:SUBTEST DETAILS", mss::c_str(i_target_mba));

        switch (l_operation_type)
        {
            case 0:
                FAPI_DBG("%s:SUBTEST        :WRITE", mss::c_str(i_target_mba));
                break;

            case 1:
                FAPI_DBG("%s:SUBTEST        :READ", mss::c_str(i_target_mba));
                break;

            case 2:
                FAPI_DBG("%s:SUBTEST        :READ - WRITE", mss::c_str(i_target_mba));
                break;

            case 3:
                FAPI_DBG("%s:SUBTEST        :WRITE - READ", mss::c_str(i_target_mba));
                break;

            case 4:
                FAPI_DBG("%s:SUBTEST        :READ - WRITE - READ", mss::c_str(i_target_mba));
                break;

            case 5:
                FAPI_DBG("%s:SUBTEST        :READ - WRITE - WRITE", mss::c_str(i_target_mba));
                break;

            case 6:
                FAPI_DBG("%s:SUBTEST        :RANDOM COMMAND SEQUENCE", mss::c_str(i_target_mba));
                break;

            case 7:
                FAPI_DBG("%s:SUBTEST        :GOTO SUBTEST N OR REFRESH ONLY", mss::c_str(i_target_mba));
                break;

            default:
                FAPI_DBG("%s:Wrong Operation selected for Subtest", mss::c_str(i_target_mba));
        }

        switch (l_data_mode)
        {
            case 0:
                FAPI_DBG("%s:DATA MODE      :FIXED DATA", mss::c_str(i_target_mba));
                break;

            case 1:
                FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_FORWARD", mss::c_str(i_target_mba));
                break;

            case 2:
                FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_REVERSE", mss::c_str(i_target_mba));
                break;

            case 3:
                FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC FORWARD", mss::c_str(i_target_mba));
                break;

            case 4:
                FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC REVERSE", mss::c_str(i_target_mba));
                break;

            case 5:
                FAPI_DBG("%s:DATA MODE      :DATA EQUAL ADDRESS", mss::c_str(i_target_mba));
                break;

            case 6:
                FAPI_DBG("%s:DATA MODE      :DATA ROTATE LEFT", mss::c_str(i_target_mba));
                break;

            case 7:
                FAPI_DBG("%s:DATA MODE      :DATA ROTATE RIGHT", mss::c_str(i_target_mba));
                break;

            default:
                FAPI_DBG("%s:Wrong Data Mode selected for Subtest", mss::c_str(i_target_mba));
        }

        switch (l_addr_mode)
        {
            case 0:
                FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL FORWARD", mss::c_str(i_target_mba));
                break;

            case 1:
                FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL REVERSE", mss::c_str(i_target_mba));
                break;

            case 2:
                FAPI_DBG("%s:ADDRESS MODE   :RANDOM FORWARD", mss::c_str(i_target_mba));
                break;

            case 3:
                FAPI_DBG("%s:ADDRESS MODE   :RANDOM REVERSE", mss::c_str(i_target_mba));
                break;

            default:
                FAPI_DBG("%s:Wrong Address Mode selected for Subtest", mss::c_str(i_target_mba));
        }

        FAPI_DBG("%s:SUBTEST %d of %d done ", mss::c_str(i_target_mba),
                 i_testnumber1, i_total_subtest_no);

        if (i_done == 1)
        {
            FAPI_DBG("%s:DONE BIT IS SET FOR CURRENT SUBTEST %d",
                     mss::c_str(i_target_mba), i_testnumber1);
        }

        if ((l_data_mode == 0) || (l_data_mode == 6) || (l_data_mode == 7) || (l_data_mode == 5))
        {
            i_sub_info[i_testnumber1].l_fixed_data_enable = 1;
        }
        else if ((l_data_mode == 1) || (l_data_mode == 2) || (l_data_mode == 3) || (l_data_mode == 4))
        {
            i_sub_info[i_testnumber1].l_random_data_enable = 1;
        }

        if ((l_addr_mode == 0) || (l_addr_mode == 1))
        {
            i_sub_info[i_testnumber1].l_fixed_addr_enable = 1;
        }
        else if ((l_addr_mode == 2) || (l_addr_mode == 3))
        {
            i_sub_info[i_testnumber1].l_random_addr_enable = 1;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief It is used to mask bad bits read from SPD
    /// @param[in]  i_target_mba Centaur.mba
    /// @return FAPI2_RC_SUCCESS  iff successful
    ///
    fapi2::ReturnCode cfg_byte_mask(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint8_t l_max_0 = 0;
        uint8_t l_max_1 = 0;
        uint8_t l_num_ranks = 0;
        uint8_t l_rnk = 0;
        uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t rank_pair = 0;
        uint64_t l_var = 0xFFFFFFFFFFFFFFFFull;
        uint16_t l_spare = 0xFFFF;
        fapi2::buffer<uint64_t> l_data_buffer1_64;
        fapi2::buffer<uint64_t> l_data_buffer2_64;
        fapi2::buffer<uint64_t> l_data_buffer3_64;
        fapi2::buffer<uint64_t> l_data_buffer4_64;
        fapi2::buffer<uint64_t> l_data_buffer5_64;
        const auto i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        uint8_t l_mba_position = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {0};
        uint8_t l_dq[DATA_BYTES_PER_PORT] = { 0 };
        uint8_t l_sp[SP_BYTES_PER_PORT] = { 0 };
        uint16_t l_index0 = 0;
        uint8_t l_index_sp = 0;
        uint16_t l_sp_isdimm = 0xff;
        uint8_t valid_rank[MAX_RANKS_PER_PORT] = {0};

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba,  num_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mba_position));

        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            l_num_ranks = num_ranks_per_dimm[l_port][0] + num_ranks_per_dimm[l_port][1];
            FAPI_TRY(mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank));

            for (l_rank = 0; l_rank < l_num_ranks; l_rank++)
            {
                l_rnk = valid_rank[l_rank];

                if (l_rnk == 255)
                {
                    continue;
                }

                l_max_0 = num_ranks_per_dimm[0][0] + num_ranks_per_dimm[0][1];
                l_max_1 = num_ranks_per_dimm[1][0] + num_ranks_per_dimm[1][1];

                l_data_buffer3_64.flush<0>();

                FAPI_DBG("%s:Function cfg_byte_mask", mss::c_str(i_target_mba));

                if (l_rnk > 3)
                {
                    l_dimm = 1;
                    l_rnk = l_rnk - 4;
                }
                else
                {
                    l_dimm = 0;
                }

                FAPI_TRY(dimmGetBadDqBitmap(i_target_mba, l_port, l_dimm, l_rnk, l_dqBitmap));

                for (l_index0 = 0; l_index0 < DIMM_DQ_RANK_BITMAP_SIZE; l_index0++)
                {
                    if (l_index0 < DATA_BYTES_PER_PORT)
                    {
                        l_dq[l_index0] = l_dqBitmap[l_index0];

                        if (l_dqBitmap[l_index0])
                        {
                            FAPI_DBG("%s:\n the port=%d  bad dq=%x on dq=%d",
                                     mss::c_str(i_target_mba), l_port,
                                     l_dqBitmap[l_index0], l_index0);
                        }
                    }
                    else
                    {
                        if (l_dqBitmap[l_index0])
                        {
                            FAPI_DBG("%s:\n the port=%d  bad dq=%x on dq=%d",
                                     mss::c_str(i_target_mba), l_port,
                                     l_dqBitmap[l_index0], l_index0);
                        }

                        l_sp[l_index_sp] = l_dqBitmap[l_index0];
                        l_index_sp++;
                    }
                }

                for(l_index0 = 0; l_index0 < DATA_BYTES_PER_PORT; l_index0++)
                {
                    FAPI_TRY(l_data_buffer1_64.insertFromRight(l_dq[l_index0], l_index0 * BITS_PER_BYTE, BITS_PER_BYTE));
                }

                if (l_mba_position == 0)
                {
                    if (l_port == 0)
                    {
                        if(l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp_isdimm, 8, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 0, 8));
                        }
                        else
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 0, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[1], 8, 8));
                        }

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buffer4_64));

                        l_data_buffer1_64 |= l_data_buffer4_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buffer1_64));

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer5_64));

                        l_data_buffer2_64 |= l_data_buffer5_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer2_64));

                    }
                    else
                    {
                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer2_64));

                        if(l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp_isdimm, 24, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 16, 8));
                        }
                        else
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 16, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[1], 24, 8));
                        }

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buffer4_64));

                        l_data_buffer1_64 |= l_data_buffer4_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buffer1_64));

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer5_64));

                        l_data_buffer2_64 |= l_data_buffer5_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer2_64));

                    }
                }
                else
                {
                    if (l_port == 0)
                    {
                        if(l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp_isdimm, 8, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 0, 8));
                        }
                        else
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 0, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[1], 8, 8));
                        }

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buffer4_64));

                        l_data_buffer1_64 |= l_data_buffer4_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buffer1_64));

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer5_64));

                        l_data_buffer2_64 |= l_data_buffer5_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer2_64));

                    }
                    else
                    {
                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer2_64));

                        if(l_attr_eff_dimm_type_u8 != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp_isdimm, 24, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 16, 8));
                        }
                        else
                        {
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[0], 16, 8));
                            FAPI_TRY(l_data_buffer2_64.insertFromRight(l_sp[1], 24, 8));
                        }

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q, l_data_buffer4_64));

                        l_data_buffer1_64 |= l_data_buffer4_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q,
                                                l_data_buffer1_64));

                        FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer5_64));

                        l_data_buffer2_64 |= l_data_buffer5_64;
                        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer2_64));

                    }
                }
            }
        }

        if (l_max_0 == 0)
        {
            if (l_mba_position == 0)
            {
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buffer1_64));

                l_data_buffer1_64.insert<0, 64>(l_var);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMA1Q, l_data_buffer1_64));

                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer1_64));

                l_data_buffer1_64.insertFromRight<0, 16>(l_spare);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer1_64));

            }
            else
            {
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buffer1_64));

                l_data_buffer1_64.insert<0, 64>(l_var);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMA1Q, l_data_buffer1_64));

                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer1_64));

                l_data_buffer1_64.insertFromRight<0, 16>(l_spare);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer1_64));

            }
        }

        if (l_max_1 == 0)
        {
            if (l_mba_position == 0)
            {
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buffer1_64));
                l_data_buffer1_64.insert<0, 64>(l_var);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMB1Q, l_data_buffer1_64));

                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer1_64));
                l_data_buffer1_64.insertFromRight<16, 16>(l_spare);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBCMABQ, l_data_buffer1_64));

            }
            else
            {
                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q, l_data_buffer1_64));
                l_data_buffer1_64.insert<0, 64>(l_var);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMB1Q, l_data_buffer1_64));

                FAPI_TRY(fapi2::getScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer1_64));
                l_data_buffer1_64.insertFromRight<16, 16>(l_spare);
                FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MCBCMABQ, l_data_buffer1_64));

            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Convert Testype num to mcbist_test_mem type
    /// @param[in] i_target_mba  Centaur input mba
    /// @param[in] i_pattern     MCBIST testtype
    /// @param[out] o_mcbtest     MCBIST testtype
    ///
    void mss_conversion_testtype(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const uint8_t i_pattern,
                                 mcbist_test_mem& o_mcbtest)
    {

        FAPI_INF("%s:value of testtype is %d", mss::c_str(i_target_mba), i_pattern);

        switch (i_pattern)
        {
            case 0:
                o_mcbtest = USER_MODE;
                FAPI_INF("%s:TESTTYPE :USER_MODE", mss::c_str(i_target_mba));
                break;

            case 1:
                o_mcbtest = CENSHMOO;
                FAPI_INF("%s:TESTTYPE :CENSHMOO", mss::c_str(i_target_mba));
                break;

            case 2:
                o_mcbtest = SUREFAIL;
                FAPI_INF("%s:TESTTYPE :SUREFAIL", mss::c_str(i_target_mba));
                break;

            case 3:
                o_mcbtest = MEMWRITE;
                FAPI_INF("%s:TESTTYPE :MEMWRITE", mss::c_str(i_target_mba));
                break;

            case 4:
                o_mcbtest = MEMREAD;
                FAPI_INF("%s:TESTTYPE :MEMREAD", mss::c_str(i_target_mba));
                break;

            case 5:
                o_mcbtest = CBR_REFRESH;
                FAPI_INF("%s:TESTTYPE :CBR_REFRESH", mss::c_str(i_target_mba));
                break;

            case 6:
                o_mcbtest = MCBIST_SHORT;
                FAPI_INF("%s:TESTTYPE :MCBIST_SHORT", mss::c_str(i_target_mba));
                break;

            case 7:
                o_mcbtest = SHORT_SEQ;
                FAPI_INF("%s:TESTTYPE :SHORT_SEQ", mss::c_str(i_target_mba));
                break;

            case 8:
                o_mcbtest = DELTA_I;
                FAPI_INF("%s:TESTTYPE :DELTA_I", mss::c_str(i_target_mba));
                break;

            case 9:
                o_mcbtest = DELTA_I_LOOP;
                FAPI_INF("%s:TESTTYPE :DELTA_I_LOOP", mss::c_str(i_target_mba));
                break;

            case 10:
                o_mcbtest = SHORT_RAND;
                FAPI_INF("%s:TESTTYPE :SHORT_RAND", mss::c_str(i_target_mba));
                break;

            case 11:
                o_mcbtest = LONG1;
                FAPI_INF("%s:TESTTYPE :LONG1", mss::c_str(i_target_mba));
                break;

            case 12:
                o_mcbtest = BUS_TAT;
                FAPI_INF("%s:TESTTYPE :BUS_TAT", mss::c_str(i_target_mba));
                break;

            case 13:
                o_mcbtest = SIMPLE_FIX;
                FAPI_INF("%s:TESTTYPE :SIMPLE_FIX", mss::c_str(i_target_mba));
                break;

            case 14:
                o_mcbtest = SIMPLE_RAND;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RAND", mss::c_str(i_target_mba));
                break;

            case 15:
                o_mcbtest = SIMPLE_RAND_2W;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_2W", mss::c_str(i_target_mba));
                break;

            case 16:
                o_mcbtest = SIMPLE_RAND_FIXD;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_FIXD", mss::c_str(i_target_mba));
                break;

            case 17:
                o_mcbtest = SIMPLE_RA_RD_WR;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RA_RD_WR", mss::c_str(i_target_mba));
                break;

            case 18:
                o_mcbtest = SIMPLE_RA_RD_R;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RA_RD_R", mss::c_str(i_target_mba));
                break;

            case 19:
                o_mcbtest = SIMPLE_RA_FD_R;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_R", mss::c_str(i_target_mba));
                break;

            case 20:
                o_mcbtest = SIMPLE_RA_FD_R_INF;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_R_INF", mss::c_str(i_target_mba));
                break;

            case 21:
                o_mcbtest = SIMPLE_SA_FD_R;
                FAPI_INF("%s:TESTTYPE :SIMPLE_SA_FD_R", mss::c_str(i_target_mba));
                break;

            case 22:
                o_mcbtest = SIMPLE_RA_FD_W;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_W", mss::c_str(i_target_mba));
                break;

            case 23:
                o_mcbtest = INFINITE;
                FAPI_INF("%s:TESTTYPE :INFINITE", mss::c_str(i_target_mba));
                break;

            case 24:
                o_mcbtest = WR_ONLY;
                FAPI_INF("%s:TESTTYPE :WR_ONLY", mss::c_str(i_target_mba));
                break;

            case 25:
                o_mcbtest = W_ONLY;
                FAPI_INF("%s:TESTTYPE :W_ONLY", mss::c_str(i_target_mba));
                break;

            case 26:
                o_mcbtest = R_ONLY;
                FAPI_INF("%s:TESTTYPE :R_ONLY", mss::c_str(i_target_mba));
                break;

            case 27:
                o_mcbtest = W_ONLY_RAND;
                FAPI_INF("%s:TESTTYPE :W_ONLY_RAND", mss::c_str(i_target_mba));
                break;

            case 28:
                o_mcbtest = R_ONLY_RAND;
                FAPI_INF("%s:TESTTYPE :R_ONLY_RAND", mss::c_str(i_target_mba));
                break;

            case 29:
                o_mcbtest = R_ONLY_MULTI;
                FAPI_INF("%s:TESTTYPE :R_ONLY_MULTI", mss::c_str(i_target_mba));
                break;

            case 30:
                o_mcbtest = SHORT;
                FAPI_INF("%s:TESTTYPE :SHORT", mss::c_str(i_target_mba));
                break;

            case 31:
                o_mcbtest = SIMPLE_RAND_BARI;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_BARI", mss::c_str(i_target_mba));
                break;

            case 32:
                o_mcbtest = W_R_INFINITE;
                FAPI_INF("%s:TESTTYPE :W_R_INFINITE", mss::c_str(i_target_mba));
                break;

            case 33:
                o_mcbtest = W_R_RAND_INFINITE;
                FAPI_INF("%s:TESTTYPE :W_R_RAND_INFINITE", mss::c_str(i_target_mba));
                break;

            case 34:
                o_mcbtest = R_INFINITE1;
                FAPI_INF("%s:TESTTYPE :R_INFINITE1", mss::c_str(i_target_mba));
                break;

            case 35:
                o_mcbtest = R_INFINITE_RF;
                FAPI_INF("%s:TESTTYPE :R_INFINITE_RF", mss::c_str(i_target_mba));
                break;

            case 36:
                o_mcbtest = MARCH;
                FAPI_INF("%s:TESTTYPE :MARCH", mss::c_str(i_target_mba));
                break;

            case 37:
                o_mcbtest = SIMPLE_FIX_RF;
                FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RF", mss::c_str(i_target_mba));
                break;

            case 38:
                o_mcbtest = SHMOO_STRESS;
                FAPI_INF("%s:TESTTYPE :SHMOO_STRESS", mss::c_str(i_target_mba));
                break;

            case 39:
                o_mcbtest = SIMPLE_RAND_RA;
                FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_RA", mss::c_str(i_target_mba));
                break;

            case 40:
                o_mcbtest = SIMPLE_FIX_RA;
                FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RA", mss::c_str(i_target_mba));
                break;

            case 41:
                o_mcbtest = SIMPLE_FIX_RF_RA;
                FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RF_RA", mss::c_str(i_target_mba));
                break;

            case 42:
                o_mcbtest = TEST_RR;
                FAPI_INF("%s:TESTTYPE :TEST_RR", mss::c_str(i_target_mba));
                break;

            case 43:
                o_mcbtest = TEST_RF;
                FAPI_INF("%s:TESTTYPE :TEST_RF", mss::c_str(i_target_mba));
                break;

            case 44:
                o_mcbtest = W_ONLY_INFINITE_RAND;
                FAPI_INF("%s:TESTTYPE :W_ONLY_INFINITE_RAND", mss::c_str(i_target_mba));
                break;

            case 45:
                o_mcbtest = MCB_2D_CUP_SEQ;
                FAPI_INF("%s:TESTTYPE :MCB_2D_CUP_SEQ", mss::c_str(i_target_mba));
                break;

            case 46:
                o_mcbtest = MCB_2D_CUP_RAND;
                FAPI_INF("%s:TESTTYPE :MCB_2D_CUP_RAND", mss::c_str(i_target_mba));
                break;

            case 47:
                o_mcbtest = SHMOO_STRESS_INFINITE;
                FAPI_INF("%s:TESTTYPE :SHMOO_STRESS_INFINITE", mss::c_str(i_target_mba));
                break;

            case 48:
                o_mcbtest = HYNIX_1_COL;
                FAPI_INF("%s:TESTTYPE :HYNIX_1_COL", mss::c_str(i_target_mba));
                break;

            case 49:
                o_mcbtest = RMWFIX;
                FAPI_INF("%s:TESTTYPE :RMWFIX", mss::c_str(i_target_mba));
                break;

            case 50:
                o_mcbtest = RMWFIX_I;
                FAPI_INF("%s:TESTTYPE :RMWFIX_I", mss::c_str(i_target_mba));
                break;

            case 51:
                o_mcbtest = W_INFINITE;
                FAPI_INF("%s:TESTTYPE :W_INFINITE", mss::c_str(i_target_mba));
                break;

            case 52:
                o_mcbtest = R_INFINITE;
                FAPI_INF("%s:TESTTYPE :R_INFINITE", mss::c_str(i_target_mba));
                break;


            default:
                FAPI_INF("%s:Wrong Test_type,so using default test_type",
                         mss::c_str(i_target_mba));
        }

    }

    ///
    /// @brief convert number pattern to mcbist_data_gen type
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_pattern    input pattern
    /// @param[out] o_mcbpatt   mcbist_data_gen type pattern
    ///
    void mss_conversion_data(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                             const uint8_t i_pattern,
                             mcbist_data_gen& o_mcbpatt)
    {
        FAPI_INF("%s:value of pattern is %d", mss::c_str(i_target_mba), i_pattern);

        switch (i_pattern)
        {
            case 0:
                o_mcbpatt = ABLE_FIVE;
                FAPI_INF("%s:PATTERN :ABLE_FIVE", mss::c_str(i_target_mba));
                break;

            case 1:
                o_mcbpatt = USR_MODE;
                FAPI_INF("%s:PATTERN :USER_MODE", mss::c_str(i_target_mba));
                break;

            case 2:
                o_mcbpatt = ONEHOT;
                FAPI_INF("%s:PATTERN :ONEHOT", mss::c_str(i_target_mba));
                break;

            case 3:
                o_mcbpatt = DQ0_00011111_RESTALLONE;
                FAPI_INF("%s:PATTERN :DQ0_00011111_RESTALLONE", mss::c_str(i_target_mba));
                break;

            case 4:
                o_mcbpatt = DQ0_11100000_RESTALLZERO;
                FAPI_INF("%s:PATTERN :DQ0_11100000_RESTALLZERO", mss::c_str(i_target_mba));
                break;

            case 5:
                o_mcbpatt = ALLZERO;
                FAPI_INF("%s:PATTERN :ALLZERO", mss::c_str(i_target_mba));
                break;

            case 6:
                o_mcbpatt = ALLONE;
                FAPI_INF("%s:PATTERN :ALLONE", mss::c_str(i_target_mba));
                break;

            case 7:
                o_mcbpatt = BYTE_BURST_SIGNATURE;
                FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE", mss::c_str(i_target_mba));
                break;

            case 8:
                o_mcbpatt = BYTE_BURST_SIGNATURE_V1;
                FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V1", mss::c_str(i_target_mba));
                break;

            case 9:
                o_mcbpatt = BYTE_BURST_SIGNATURE_V2;
                FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V2", mss::c_str(i_target_mba));
                break;

            case 10:
                o_mcbpatt = BYTE_BURST_SIGNATURE_V3;
                FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V3", mss::c_str(i_target_mba));
                break;

            case 11:
                o_mcbpatt = DATA_GEN_DELTA_I;
                FAPI_INF("%s:PATTERN :DATA_GEN_DELTA_I", mss::c_str(i_target_mba));
                break;

            case 12:
                o_mcbpatt = MCBIST_2D_CUP_PAT0;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT0", mss::c_str(i_target_mba));
                break;

            case 13:
                o_mcbpatt = MPR;
                FAPI_INF("%s:PATTERN :MPR", mss::c_str(i_target_mba));
                break;

            case 14:
                o_mcbpatt = MPR03;
                FAPI_INF("%s:PATTERN :MPR03", mss::c_str(i_target_mba));
                break;

            case 15:
                o_mcbpatt = MPR25;
                FAPI_INF("%s:PATTERN :MPR25", mss::c_str(i_target_mba));
                break;

            case 16:
                o_mcbpatt = MPR47;
                FAPI_INF("%s:PATTERN :MPR47", mss::c_str(i_target_mba));
                break;

            case 17:
                o_mcbpatt = DELTA_I1;
                FAPI_INF("%s:PATTERN :DELTA_I1", mss::c_str(i_target_mba));
                break;

            case 18:
                o_mcbpatt = MCBIST_2D_CUP_PAT1;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT1", mss::c_str(i_target_mba));
                break;

            case 19:
                o_mcbpatt = MHC_55;
                FAPI_INF("%s:PATTERN :MHC_55", mss::c_str(i_target_mba));
                break;

            case 20:
                o_mcbpatt = MHC_DQ_SIM;
                FAPI_INF("%s:PATTERN :MHC_DQ_SIM", mss::c_str(i_target_mba));
                break;

            case 21:
                o_mcbpatt = MCBIST_2D_CUP_PAT2;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT2", mss::c_str(i_target_mba));
                break;

            case 22:
                o_mcbpatt = MCBIST_2D_CUP_PAT3;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT3", mss::c_str(i_target_mba));
                break;

            case 23:
                o_mcbpatt = MCBIST_2D_CUP_PAT4;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT4", mss::c_str(i_target_mba));
                break;

            case 24:
                o_mcbpatt = MCBIST_2D_CUP_PAT5;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT5", mss::c_str(i_target_mba));
                break;

            case 25:
                o_mcbpatt = MCBIST_2D_CUP_PAT6;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT6", mss::c_str(i_target_mba));
                break;

            case 26:
                o_mcbpatt = MCBIST_2D_CUP_PAT7;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT7", mss::c_str(i_target_mba));
                break;

            case 27:
                o_mcbpatt = MCBIST_2D_CUP_PAT8;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT8", mss::c_str(i_target_mba));
                break;

            case 28:
                o_mcbpatt = MCBIST_2D_CUP_PAT9;
                FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT9", mss::c_str(i_target_mba));
                break;

            case 29:
                o_mcbpatt = CWLPATTERN;
                FAPI_INF("%s:PATTERN :CWLPATTERN", mss::c_str(i_target_mba));
                break;

            case 30:
                o_mcbpatt = GREY1;
                FAPI_INF("%s:PATTERN :GREY1", mss::c_str(i_target_mba));
                break;

            case 31:
                o_mcbpatt = DC_ONECHANGE;
                FAPI_INF("%s:PATTERN :DC_ONECHANGE", mss::c_str(i_target_mba));
                break;

            case 32:
                o_mcbpatt = DC_ONECHANGEDIAG;
                FAPI_INF("%s:PATTERN :DC_ONECHANGEDIAG", mss::c_str(i_target_mba));
                break;

            case 33:
                o_mcbpatt = GREY2;
                FAPI_INF("%s:PATTERN :GREY2", mss::c_str(i_target_mba));
                break;

            case 34:
                o_mcbpatt = FIRST_XFER;
                FAPI_INF("%s:PATTERN :FIRST_XFER", mss::c_str(i_target_mba));
                break;

            case 35:
                o_mcbpatt = MCBIST_222_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_222_XFER", mss::c_str(i_target_mba));
                break;

            case 36:
                o_mcbpatt = MCBIST_333_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_333_XFER", mss::c_str(i_target_mba));
                break;

            case 37:
                o_mcbpatt = MCBIST_444_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_444_XFER", mss::c_str(i_target_mba));
                break;

            case 38:
                o_mcbpatt = MCBIST_555_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_555_XFER", mss::c_str(i_target_mba));
                break;

            case 39:
                o_mcbpatt = MCBIST_666_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_666_XFER", mss::c_str(i_target_mba));
                break;

            case 40:
                o_mcbpatt = MCBIST_777_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_777_XFER", mss::c_str(i_target_mba));
                break;

            case 41:
                o_mcbpatt = MCBIST_888_XFER;
                FAPI_INF("%s:PATTERN :MCBIST_888_XFER", mss::c_str(i_target_mba));
                break;

            case 42:
                o_mcbpatt = FIRST_XFER_X4MODE;
                FAPI_INF("%s:PATTERN :FIRST_XFER_X4MODE", mss::c_str(i_target_mba));
                break;

            case 43:
                o_mcbpatt = MCBIST_LONG;
                FAPI_INF("%s:PATTERN :MCBIST_LONG", mss::c_str(i_target_mba));
                break;

            case 44:
                o_mcbpatt = PSEUDORANDOM;
                FAPI_INF("%s:PATTERN :PSEUDORANDOM", mss::c_str(i_target_mba));
                break;

            case 45:
                o_mcbpatt = CASTLE;
                FAPI_INF("%s:PATTERN :CASTLE", mss::c_str(i_target_mba));
                break;

            default:
                FAPI_INF("%s:Wrong Data Pattern,so using default pattern",
                         mss::c_str(i_target_mba));
        }
    }
}

