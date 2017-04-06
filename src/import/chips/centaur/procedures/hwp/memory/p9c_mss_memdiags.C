/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_memdiags.C $ */
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
/// @file p9c_mss_memdiags.C
/// @brief  Uses maint cmds to write patterns to memory and read back.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9c_mss_memdiags.H>
#include <p9c_mss_maint_cmds.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{

    //------------------------------------------------------------------------------
    // Constants and enums
    //------------------------------------------------------------------------------
    static constexpr uint32_t l_mbeccfir_addr[MAX_MBA_PER_CEN] =
    {
        // port0/1                     port2/3
        CEN_ECC01_MBECCFIR,  CEN_ECC23_MBECCFIR
    };
    constexpr uint8_t NUM_PATTERNS = 9;

    ///
    /// @brief Uses maint cmds to write patterns to memory and read back.
    /// @param[in]  i_target  Reference to target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode p9c_mss_memdiags(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        bool l_poll = true;
        mss_MaintCmd::PatternIndex l_initPattern;
        uint32_t l_stopCondition = 0;
        fapi2::buffer<uint64_t> l_startAddr;
        fapi2::buffer<uint64_t> l_endAddr;
        fapi2::buffer<uint64_t> l_mbspaq;

        uint8_t l_dimm_ranks_configed_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint8_t l_master_rank = MSS_ALL_RANKS;

        // Index to keep track of which pattern in the sequence
        // of patterns we are on.
        uint8_t l_pattern_index = 0;

        // Variable to store last pattern index we ran, which should be 0's pattern
        uint8_t l_last_pattern_index = 0;
        // maint error summary per rank, per pattern
        uint8_t l_error_summary[MAX_RANKS_PER_PORT][NUM_PATTERNS] =
        {
            // l_pattern index
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank0
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank1
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank2
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank3
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank4
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank5
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // rank6
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}// rank7
        };

        bool l_ecc_error_found = false;
        bool l_UE_found = false;
        uint64_t l_mnfg_flags = 0;
        uint8_t l_symbol_mark = MSS_INVALID_SYMBOL;
        uint8_t l_chip_mark = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
        uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {0}; // 10 byte array of bad bits
        fapi2::buffer<uint64_t> l_data;
        uint8_t l_port = 0;
        uint8_t l_byte = 0;
        uint8_t l_valid_dimms  = 0;
        uint8_t l_valid_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};

        //------------------------------------------------------
        // Restore DRAM repairs
        //------------------------------------------------------
        uint8_t o_repairs_applied = 0;
        uint8_t o_repairs_exceeded = 0;
        FAPI_TRY(mss_restore_DRAM_repairs(i_target, o_repairs_applied, o_repairs_exceeded));

        FAPI_ASSERT(!o_repairs_exceeded,
                    fapi2::CEN_MSS_MEMDIAGS_RESTORE_REPAIRS_EXCEEDED().
                    set_MBA(i_target),
                    "FATAL: Memdiags exiting with error before running patterns, due to DRAM repairs exceeded on %s.",
                    mss::c_str(i_target));

        //------------------------------------------------------
        // Get configured master ranks, so we can do init/read on each one
        //------------------------------------------------------
        // NOTE: This attribute is for master ranks only
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, i_target,  l_dimm_ranks_configed_array));

        FAPI_INF("master ranks on dimm0 = %02x", l_dimm_ranks_configed_array[0][0]);
        FAPI_INF("master ranks on dimm1 = %02x", l_dimm_ranks_configed_array[0][1]);

        //------------------------------------------------------
        // Get mnfg flags
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mnfg_flags));

        //------------------------------------------------------
        // MNFG_ENABLE_STANDARD_PATTERN_TEST
        //------------------------------------------------------
        // Loop through each rank and do random sf init, followed by sf read
        // Loop through each rank and do sf init to F's, followed by sf read
        // Loop through each rank and do sf init to 0's, followed by sf read
        if (l_mnfg_flags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_ENABLE_STANDARD_PATTERN_TEST)
        {
            //------------------------------------------------------
            // Rank-by-rank: super fast random init followed super fast read
            //------------------------------------------------------
            l_initPattern = mss_MaintCmd::PATTERN_RANDOM;

            for( l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; ++l_dimm)
            {
                for( l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
                {
                    if (l_dimm_ranks_configed_array[0][l_dimm] & (0x80 >> l_rank))
                    {
                        l_master_rank = l_rank + l_dimm * 4;
                        FAPI_INF("Working on master rank %d", l_master_rank);

                        //------------------------------------------------------
                        // Get address range to run maint cmds on
                        //------------------------------------------------------

                        FAPI_TRY(mss_get_address_range( i_target,
                                                        l_master_rank,
                                                        l_startAddr,
                                                        l_endAddr ));


                        //------------------------------------------------------
                        // Do a super random fast init of all of memory
                        //------------------------------------------------------

                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

                        mss_SuperFastRandomInit* sfrinit = new mss_SuperFastRandomInit( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_initPattern,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfrinit->setupAndExecuteCmd());
                        FAPI_TRY(sfrinit->cleanupCmd());
                        delete sfrinit;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));


                        //------------------------------------------------------
                        // Do a super fast read of all of memory
                        //------------------------------------------------------


                        // NOTE: Ideally, I would be running through all the ranks
                        // at once, instead of rank-by-rank. In that case I'd want
                        // to set it up this way:
                        //          //mss_MaintCmd::STOP_IMMEDIATE|
                        //          mss_MaintCmd::STOP_END_OF_RANK|
                        //          //mss_MaintCmd::STOP_ON_HARD_NCE_ETE|
                        //          //mss_MaintCmd::STOP_ON_INT_NCE_ETE|
                        //          //mss_MaintCmd::STOP_ON_SOFT_NCE_ETE|
                        //          //mss_MaintCmd::STOP_ON_SCE|
                        //          //mss_MaintCmd::STOP_ON_MCE|
                        //          //mss_MaintCmd::STOP_ON_RETRY_CE_ETE|
                        //          mss_MaintCmd::STOP_ON_MPE|
                        //          mss_MaintCmd::STOP_ON_UE|
                        //          //mss_MaintCmd::STOP_ON_SUE|
                        //          mss_MaintCmd::STOP_ON_END_ADDRESS|
                        //          mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION
                        //
                        // But, since this has to work in VBU, where it takes too long to do
                        // all addresses, I can only do a small address range on one rank at
                        // a time. So I am setting this up to run to end address and give me a
                        // cmd complete attention. After cmd is done, I'll be
                        // checking which errors came on.

                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

                        mss_SuperFastRead* sfread = new mss_SuperFastRead( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfread->setupAndExecuteCmd());
                        FAPI_TRY(sfread->cleanupCmd());
                        delete sfread;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));

                        // Check for ECC errors once cmd has stopped
                        FAPI_TRY(mss_check_for_ECC_errors(i_target, l_error_summary, l_pattern_index));

                    } // End if valid master rank
                } // End for l_rank 0-3
            } // End for l_dimm 0-1

            //------------------------------------------------------
            // Rank-by-rank: super fast init to F's followed super fast read
            //------------------------------------------------------
            l_initPattern = mss_MaintCmd::PATTERN_1;
            l_pattern_index ++;

            for( l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; ++l_dimm)
            {
                for( l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
                {
                    if (l_dimm_ranks_configed_array[0][l_dimm] & (0x80 >> l_rank))
                    {
                        l_master_rank = l_rank + l_dimm * 4;
                        FAPI_INF("Working on master rank %d", l_master_rank);

                        //------------------------------------------------------
                        // Get address range to run maint cmds on
                        //------------------------------------------------------

                        FAPI_TRY(mss_get_address_range( i_target,
                                                        l_master_rank,
                                                        l_startAddr,
                                                        l_endAddr ));

                        //------------------------------------------------------
                        // Do a super fast init of all of memory
                        //------------------------------------------------------

                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;


                        mss_SuperFastInit* sfinit = new mss_SuperFastInit( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_initPattern,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfinit->setupAndExecuteCmd());

                        delete sfinit;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));

                        //------------------------------------------------------
                        // Do a super fast read of all of memory
                        //------------------------------------------------------
                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

                        mss_SuperFastRead* sfread = new mss_SuperFastRead( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfread->setupAndExecuteCmd());
                        FAPI_TRY(sfread->cleanupCmd());
                        delete sfread;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));
                        // Check for ECC errors once cmd has stopped
                        FAPI_TRY(mss_check_for_ECC_errors(i_target, l_error_summary, l_pattern_index));
                    } // End if valid master rank
                } // End for l_rank 0-3
            } // End for l_dimm 0-1


            //------------------------------------------------------
            // Rank-by-rank: super fast init to 0's followed super fast read
            //------------------------------------------------------
            l_initPattern = mss_MaintCmd::PATTERN_0;
            l_pattern_index ++;

            for( l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; ++l_dimm)
            {
                for( l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
                {
                    if (l_dimm_ranks_configed_array[0][l_dimm] & (0x80 >> l_rank))
                    {
                        l_master_rank = l_rank + l_dimm * 4;
                        FAPI_INF("Working on master rank %d", l_master_rank);

                        //------------------------------------------------------
                        // Get address range to run maint cmds on
                        //------------------------------------------------------

                        FAPI_TRY(mss_get_address_range( i_target,
                                                        l_master_rank,
                                                        l_startAddr,
                                                        l_endAddr ));

                        //------------------------------------------------------
                        // Do a super fast init of all of memory
                        //------------------------------------------------------

                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

                        mss_SuperFastInit* sfinit = new mss_SuperFastInit( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_initPattern,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfinit->setupAndExecuteCmd());
                        delete sfinit;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));

                        //------------------------------------------------------
                        // Do a super fast read of all of memory
                        //------------------------------------------------------
                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

                        mss_SuperFastRead* sfread = new mss_SuperFastRead( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfread->setupAndExecuteCmd());
                        FAPI_TRY(sfread->cleanupCmd());
                        delete sfread;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));
                        // Check for ECC errors once cmd has stopped
                        FAPI_TRY(mss_check_for_ECC_errors(i_target, l_error_summary, l_pattern_index));
                    } // End if valid master rank
                } // End for l_rank 0-3
            } // End for l_dimm 0-1

            // Get last pattern index. Need this so I can error out if last pattern,
            // has any SUEs.
            l_last_pattern_index = l_pattern_index;

            // Show final value of markstore
            FAPI_INF("Markstore");

            for(l_master_rank = 0; l_master_rank < MAX_RANKS_PER_PORT; ++l_master_rank )
            {
                FAPI_TRY(mss_get_mark_store(i_target, l_master_rank, l_symbol_mark, l_chip_mark ));
            }

            // Show final value of steer muxes
            FAPI_INF("Steer MUXES");

            for(l_master_rank = 0; l_master_rank < MAX_RANKS_PER_PORT; ++l_master_rank )
            {
                FAPI_TRY(mss_check_steering(i_target,
                                            l_master_rank,
                                            l_dramSparePort0Symbol,
                                            l_dramSparePort1Symbol,
                                            l_eccSpareSymbol));


            }



            // Find out which dimms are functional
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target,  l_valid_dimms));

            l_valid_dimm[0][0] = (l_valid_dimms & 0x80); // port0, dimm0
            l_valid_dimm[0][1] = (l_valid_dimms & 0x40); // port0, dimm1
            l_valid_dimm[1][0] = (l_valid_dimms & 0x08); // port1, dimm0
            l_valid_dimm[1][1] = (l_valid_dimms & 0x04); // port1, dimm1


            // Show final state of bad bits
            // For each port in the given MBA:0,1
            for(l_port = 0; l_port < MAX_PORTS_PER_MBA; ++l_port )
            {
                // For each DIMM select on the given port:0,1
                for(l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; ++l_dimm )
                {
                    if (l_valid_dimm[l_port][l_dimm])
                    {
                        // For each rank select on the given DIMM select:0,1,2,3
                        for(l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank )
                        {


                            // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                            FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                                        l_port,
                                                        l_dimm,
                                                        l_rank,
                                                        l_dqBitmap));

                            // For each byte
                            for(l_byte = 0; l_byte < DIMM_DQ_RANK_BITMAP_SIZE; ++l_byte )
                            {
                                if(l_dqBitmap[l_byte])
                                {
                                    FAPI_INF("port%d, dimm%d, rank%d, l_dqBitmap[%d] = %02x",
                                             l_port, l_dimm, l_rank, l_byte, l_dqBitmap[l_byte]);
                                }
                            } // End for loop on bytes
                        }// End for loop on ranks
                    } // End if valid dimm
                }// End for loop on dimms
            } // End for loop on ports


            //------------------------------------------------------
            // Check if any ECC errors found
            //------------------------------------------------------
            for(l_master_rank = 0; l_master_rank < MAX_RANKS_PER_PORT; ++l_master_rank )
            {
                for(l_pattern_index = 0; l_pattern_index < 9; ++l_pattern_index )
                {
                    // Check for valid rank and valid pattern, with an ecc error
                    if ((l_error_summary[l_master_rank][l_pattern_index] & 0x80) &&
                        (l_error_summary[l_master_rank][l_pattern_index] & 0x7F))
                    {
                        l_ecc_error_found = true;
                    }
                }
            }

            //------------------------------------------------------
            // Print traces to show summary of what memdiags found,
            // if we found any ecc error during the test
            //------------------------------------------------------
            if (l_ecc_error_found)
            {
                FAPI_ERR(" WARNING: ECC error found during memdiags on %s.", mss::c_str(i_target));
                FAPI_ERR(" NOTE: UE or SUE(in last pattern) will required exit with error.");
                FAPI_ERR(" NOTE: If only MPE, NCE, SCE, MCE, RCE, or SUE(not in last pattern), it is safe to continue.");
                FAPI_ERR(" **********************************************");
                FAPI_ERR(" Maint ECC error summary, per rank, per pattern on %s.", mss::c_str(i_target));

                for(l_master_rank = 0; l_master_rank < MAX_RANKS_PER_PORT; ++l_master_rank )
                {
                    for(l_pattern_index = 0; l_pattern_index < 9; ++l_pattern_index )
                    {
                        // Check if valid
                        if (l_error_summary[l_master_rank][l_pattern_index] & 0x80)
                        {
                            FAPI_ERR("master rank %d, pattern index %d on %s", l_master_rank, l_pattern_index, mss::c_str(i_target));

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x40)
                            {
                                FAPI_ERR("WARNING:     Maint MPE: mark placed error");
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x20)
                            {
                                FAPI_ERR("WARNING:     Maint NCE: new CE");
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x10)
                            {
                                FAPI_ERR("WARNING:     Maint SCE: symbol corrected error");
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x08)
                            {
                                FAPI_ERR("WARNING:     Maint MCE: mark corrected error");
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x04)
                            {
                                FAPI_ERR("WARNING:     Maint RCE: retry CE");
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x02)
                            {
                                if (l_pattern_index == l_last_pattern_index)
                                {
                                    FAPI_ERR("FATAL:       Maint SUE in last pattern");
                                    l_UE_found = true;
                                }
                                else
                                {
                                    FAPI_ERR("WARNING:     Maint SUE: special UE");
                                }
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] & 0x01)
                            {
                                FAPI_ERR("FATAL:       Maint UE");
                                l_UE_found = true;
                            }

                            if (l_error_summary[l_master_rank][l_pattern_index] == 0x80)
                            {
                                FAPI_ERR("             Clean");
                            }
                        }
                    }
                }

                FAPI_ERR(" **********************************************");
            }

            FAPI_ASSERT(!l_UE_found,
                        fapi2::CEN_MSS_MEMDIAGS_UE_OR_SUE_IN_LAST_PATTERN().
                        set_MBA(i_target),
                        "FATAL: Memdiags exiting with error due to UE, or SUE(in last pattern) on %s.", mss::c_str(i_target));

        } // End MNFG_ENABLE_STANDARD_PATTERN_TEST


        //------------------------------------------------------
        // DEFAULT: SF INIT to 0's
        //------------------------------------------------------
        else
        {
            l_initPattern = mss_MaintCmd::PATTERN_0;

            for( l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; ++l_dimm)
            {
                for( l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
                {
                    if (l_dimm_ranks_configed_array[0][l_dimm] & (0x80 >> l_rank))
                    {
                        l_master_rank = l_rank + l_dimm * 4;
                        FAPI_INF("Working on master rank %d", l_master_rank);

                        //------------------------------------------------------
                        // Get address range to run maint cmds on
                        //------------------------------------------------------

                        FAPI_TRY(mss_get_address_range( i_target,
                                                        l_master_rank,
                                                        l_startAddr,
                                                        l_endAddr ));


                        //------------------------------------------------------
                        // Do a super fast init of all of memory
                        //------------------------------------------------------

                        l_stopCondition =
                            mss_MaintCmd::STOP_ON_END_ADDRESS |
                            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;


                        mss_SuperFastInit* sfinit = new mss_SuperFastInit( i_target,
                                l_startAddr,
                                l_endAddr,
                                l_initPattern,
                                l_stopCondition,
                                l_poll);

                        FAPI_TRY(sfinit->setupAndExecuteCmd());

                        delete sfinit;

                        // Clear special attention reg, MBSPAQ, between commands
                        l_mbspaq.flush<0>();
                        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ, l_mbspaq));

                    } // End if valid master rank
                } // End for l_rank 0-3
            } // End for l_dimm 0-1
        } // End DEFAULT: SF INIT to 0's

        FAPI_DBG("End p9c_mss_memdiags.");

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Check for ECC errors after sf read
    /// @param[in]      i_target  Reference to target
    /// @param[out]     o_error_summary   Maint error summary per rank, per pattern
    /// @param[in]      i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_check_for_ECC_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t (&o_error_summary)[MAX_RANKS_PER_PORT][NUM_PATTERNS],
            const uint8_t i_pattern_index)
    {

        fapi2::buffer<uint64_t> l_mbmaca;
        fapi2::buffer<uint64_t> l_mbeccfir;
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
        uint8_t l_mbaPosition = 0;
        uint8_t l_rank = 0;
        bool l_mark_verified = false;
        uint8_t l_bad_bits[MAX_PORTS_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE] =
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        };

        FAPI_INF("ENTER mss_check_for_ECC_errors()");
        // Assumption is we've stopped at the end of a rank, so find out
        // which rank.
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));

        // Get l_rank
        FAPI_TRY(l_mbmaca.extract(l_rank, 0, 4, 8 - 4));

        // Get Centaur target for the given MBA
        l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        // Get MBA position: 0 = mba01, 1 = mba23
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

        // Read MBECCFIR
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));

        // Update error summary per rank, per pattern
        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);

        //------------------------------------------------------
        // If MBECCFIR[41]: UE set, do UE isolation
        //------------------------------------------------------
        if (l_mbeccfir.getBit<41>())
        {
            // UE isolation
            FAPI_TRY(mss_IPL_UE_isolation(i_target, l_rank, l_bad_bits));
        }

        //------------------------------------------------------
        // Else if MPE, MBECCFIR[20-27], verify chip mark
        // and steer if spare available
        //------------------------------------------------------
        else if (l_mbeccfir.getBit(20 + l_rank))
        {
            FAPI_TRY(mss_ipl_verify_chip_mark(i_target, l_rank, i_pattern_index, o_error_summary, l_mark_verified));

            // If chip mark verified, meaning MCE found on second pass of VCM,
            // and no UEs or RCEs hit during VCM, attempt DRAM steering
            if (l_mark_verified)
            {
                FAPI_TRY(mss_ipl_steer(i_target, l_rank, i_pattern_index, o_error_summary));
            }
        }

        //------------------------------------------------------
        // Cleanup error status
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, l_rank));



        FAPI_INF("EXIT mss_check_for_ECC_errors()");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Update error summary per rank, per pattern
    /// @param[in]      i_rank            Rank being analyzed
    /// @param[in]      i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @param[in]      i_mbeccfir        MBECCFIR
    /// @param[out]     o_error_summary   Maint error summary per rank, per pattern
    /// @return none
    ///
    void mss_update_error_summary(const uint8_t i_rank,
                                  const uint8_t i_pattern_index,
                                  const fapi2::buffer<uint64_t> i_mbeccfir,
                                  uint8_t (&o_error_summary)[MAX_RANKS_PER_PORT][NUM_PATTERNS])

    {
        FAPI_INF("ENTER mss_update_error_summary");
        // Valid bit stored in o_error_summary bit 0
        o_error_summary[i_rank][i_pattern_index] |= 0x80;

        // Capture error summary
        if (i_mbeccfir.getBit(20 + i_rank))
        {
            FAPI_DBG("%d:Maint MPE, rank%d", 20 + i_rank, i_rank );

            // Maint MPE stored in o_error_summary bit 1
            o_error_summary[i_rank][i_pattern_index] |= 0x40;
        }

        if (i_mbeccfir.getBit<36>())
        {
            FAPI_DBG("36: Maint NCE");

            // Maint NCE stored in o_error_summary bit 2
            o_error_summary[i_rank][i_pattern_index] |= 0x20;
        }

        if (i_mbeccfir.getBit<37>())
        {
            FAPI_DBG("37: Maint SCE");

            // Maint SCE stored in o_error_summary bit 3
            o_error_summary[i_rank][i_pattern_index] |= 0x10;
        }

        if (i_mbeccfir.getBit<38>())
        {
            FAPI_DBG("38: Maint MCE");

            // Maint MCE stored in o_error_summary bit 4
            o_error_summary[i_rank][i_pattern_index] |= 0x08;
        }

        if (i_mbeccfir.getBit<39>())
        {
            FAPI_DBG("39: Maint RCE");

            // Maint RCE stored in o_error_summary bit 5
            o_error_summary[i_rank][i_pattern_index] |= 0x04;
        }

        if (i_mbeccfir.getBit<40>())
        {
            FAPI_DBG("40: Maint SUE");

            // Maint SUE stored in o_error_summary bit 6
            o_error_summary[i_rank][i_pattern_index] |= 0x02;
        }

        if (i_mbeccfir.getBit<41>())
        {
            FAPI_DBG("41: Maint UE");

            // Maint UE stored in o_error_summary bit 7
            o_error_summary[i_rank][i_pattern_index] |= 0x01;
        }

        FAPI_INF("EXIT mss_update_error_summary()");

        return;
    }

    ///
    /// @brief Runs IPL verify chip mark procedure on a given rank
    /// @param[in]  i_target          Reference to target
    /// @param[in]  i_rank            Rank to run on
    /// @param[in]  i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @param[out] o_error_summary   Maint error summary per rank, per pattern
    /// @param[out] o_mark verified   True if chip mark verified, and no UEs or RCEs hit.
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ipl_verify_chip_mark(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_rank,
            const uint8_t i_pattern_index,
            uint8_t (&o_error_summary)[MAX_RANKS_PER_PORT][NUM_PATTERNS],
            bool& o_mark_verified)
    {

        fapi2::buffer<uint64_t> l_startAddr;
        fapi2::buffer<uint64_t> l_endAddr;
        bool l_poll = true;
        uint32_t l_stopCondition;
        mss_MaintCmd::TimeBaseSpeed l_speed;
        fapi2::buffer<uint64_t> l_mbeccfir;
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
        uint8_t l_mbaPosition = 0;
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint8_t l_centaurDQ = 0;
        uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {0}; // 10 byte array of bad bits
        uint8_t l_symbol_mark = MSS_INVALID_SYMBOL;
        uint8_t l_chip_mark = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
        uint8_t l_bad_bits[2][10] =
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        };
        uint8_t l_dramWidth = 0;
        // NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
        uint8_t l_spare_dram[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; // Array defining if spare dram exit
        mss_TimeBaseSteerCleanup* tbsteer;
        mss_SuperFastRead* sfread;
        FAPI_INF("ENTER mss_ipl_verify_chip_mark()");

        o_mark_verified = false;

        //------------------------------------------------------
        // Get l_dramWidth
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

        //------------------------------------------------------
        // Get array attribute that defines if spare dram exits
        //------------------------------------------------------
        //     l_spare_dram[port][dimm][rank]
        //     NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
        //     NOTE: Typically will same value for whole Centaur.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_target,  l_spare_dram));

        //------------------------------------------------------
        // Read mark store to find new chip mark (don't care about symbol mark)
        //------------------------------------------------------
        FAPI_TRY(mss_get_mark_store(i_target, i_rank, l_symbol_mark, l_chip_mark ));

        FAPI_ASSERT(l_chip_mark != MSS_INVALID_SYMBOL,
                    fapi2::CEN_MSS_PLACE_HOLDER_ERROR(),
                    "Can't find rank%d chip mark to verify %s", i_rank, mss::c_str(i_target));

        // Find l_dimm, 0 or 1
        l_dimm = i_rank / 4;

        // Find l_rank, 0,1,2,3
        l_rank = i_rank % 4;

        if (l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
        {
            // Find which port the chip mark is on, 0 or 1
            l_port = mss_x8_chip_mark_to_centaurDQ[l_chip_mark / 4][1];

            // Find first Centaur DQ for the chip mark
            l_centaurDQ = mss_x8_chip_mark_to_centaurDQ[l_chip_mark / 4][0];

            FAPI_ERR("WARNING: Attempting to verify x8 chip mark on port%d, dimm%d, rank%d, dq%d-%d on %s",
                     l_port, l_dimm, l_rank, l_centaurDQ , l_centaurDQ + 7, mss::c_str(i_target));
        }
        else if (l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
        {
            // Find which port the chip mark is on, 0 or 1
            l_port = mss_x4_chip_mark_to_centaurDQ[l_chip_mark / 2][1];

            // Find first Centaur DQ for the chip mark
            l_centaurDQ = mss_x4_chip_mark_to_centaurDQ[l_chip_mark / 2][0];

            FAPI_ERR("WARNING: Attempting to verify x4 chip mark on port%d, dimm%d, rank%d, dq%d-%d on %s",
                     l_port, l_dimm, l_rank, l_centaurDQ , l_centaurDQ + 3, mss::c_str(i_target));
        }

        //------------------------------------------------------
        // Get Centaur target for the given MBA
        //------------------------------------------------------
        l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //------------------------------------------------------
        // Get MBA position: 0 = mba01, 1 = mba23
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

        //------------------------------------------------------
        // Get address range to run maint cmds on
        //------------------------------------------------------
        FAPI_TRY(mss_get_address_range( i_target,
                                        i_rank,
                                        l_startAddr,
                                        l_endAddr ));

        //------------------------------------------------------
        // Cleanup before starting 1st pass
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, i_rank));

        //------------------------------------------------------
        // 1st pass: super fast read, to end of rank
        //------------------------------------------------------

        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

        sfread = new mss_SuperFastRead( i_target,
                                        l_startAddr,
                                        l_endAddr,
                                        l_stopCondition,
                                        l_poll);

        FAPI_TRY(sfread->setupAndExecuteCmd());
        FAPI_TRY(sfread->cleanupCmd());
        delete sfread;

        //------------------------------------------------------
        // Read MBECCFIR
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));

        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);

        // If MBECCFIR[38]: MAINT MCE
        if (l_mbeccfir.getBit<38>())
        {
            FAPI_ERR("WARNING: Re-Read of rank following MPE found a MCE, meaning it could be a hard error or intermittent write error on %s.",
                     mss::c_str(i_target));
        }
        else
        {
            FAPI_ERR("WARNING: Re-Read of rank following MPE found a no MCE, meaning it must have been an intermittent read error on %s.",
                     mss::c_str(i_target));
        }


        //------------------------------------------------------
        // Cleanup before starting 2nd pass
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, i_rank));

        l_speed = mss_MaintCmd::FAST_MAX_BW_IMPACT;

        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

        tbsteer = new mss_TimeBaseSteerCleanup( i_target,
                                                l_startAddr,
                                                l_endAddr,
                                                l_speed,
                                                l_stopCondition,
                                                l_poll);

        FAPI_TRY(tbsteer->setupAndExecuteCmd());
        delete tbsteer;

        //------------------------------------------------------
        // Read MBECCFIR
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));

        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);

        // If MBECCFIR[41]:UE, or MBECCFIR[39]:RCE
        if (l_mbeccfir.getBit<41>() || l_mbeccfir.getBit<39>())
        {
            FAPI_ERR("FATAL: Found MBECCFIR[41]:UE or MBECCFIR[39]:RCE during 1st phase of VCM so more bad then chip mark can fix on %s."
                     , mss::c_str(i_target));

            // NOTE: We will leave chip mark in markstore but not bother to update
            // bad bit attribute. Primary purpose of bad bit attribute is to
            // allow us to restore repairs on subsequent IPLs, and since we
            // have UEs we know we are going to callout the hw anyway.

            // UE isolation
            // NOTE: UE isolation is based on comparing trapped actual data to a
            // known pattern. Since Centaur doesn't trap UE data on timebased
            // steer cleanup, UE isolation function will just say both DIMMs
            // in the logical DIMM pair are bad. A future enhancement to
            // the UE isolation function may allow us to isolate.
            FAPI_TRY(mss_IPL_UE_isolation(i_target, l_rank, l_bad_bits));




            // NOTE: We will not update bad bit attribute with bad bits found
            // in UE isolation, since we're calling out the hw anyway. Also,
            // we'll most likely have too many bad bits to repair. Also, want
            // to avoid storing bad bits from a UE in case UE was just due to
            // some sort of setup problem, as opposed to real bad hw.

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MEMDIAGS_UE_DURING_VCM().
                        set_MBA(i_target),
                        "FATAL: Found MBECCFIR[41]:UE or MBECCFIR[39]:RCE during 1st phase of VCM so more bad then chip mark can fix on %s.",
                        mss::c_str(i_target));
        }

        //------------------------------------------------------
        // Cleanup before starting 3rd pass
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, i_rank));
        //------------------------------------------------------
        // 3rd pass: super fast read, to end of rank
        //------------------------------------------------------

        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

        sfread = new mss_SuperFastRead( i_target,
                                        l_startAddr,
                                        l_endAddr,
                                        l_stopCondition,
                                        l_poll);

        FAPI_TRY(sfread->setupAndExecuteCmd());
        FAPI_TRY(sfread->cleanupCmd());
        delete sfread;

        //------------------------------------------------------
        // Read MBECCFIR
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));
        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);


        // If MBECCFIR[41]: UE
        if (l_mbeccfir.getBit<41>())
        {
            FAPI_ERR("FATAL: Found MBECCFIR[41]: UE during 3rd phase of VCM so more bad then chip mark can fix on %s.",
                     mss::c_str(i_target));

            // NOTE: We will leave chip mark in markstore but not bother to update
            // bad bit attribute. Primary purpose of bad bit attribute is to
            // allow us to restore repairs on subsequent IPLs, and since we
            // have UEs we know are going to callout the hw anyway.

            // UE isolation
            // NOTE: UE isolation is based on comparing trapped actual data to a
            // known pattern.
            FAPI_TRY(mss_IPL_UE_isolation(i_target, l_rank, l_bad_bits));

            // NOTE: We will not update bad bit attribute with bad bits found
            // in UE isolation, since we're calling out the hw anyway. Also,
            // we'll most likely have too many bad bits to repair. Also, want
            // to avoid storing bad bits from a UE in case UE was just due to
            // some sort of setup problem, as opposed to real bad hw.

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MEMDIAGS_UE_DURING_VCM().
                        set_MBA(i_target),
                        "FATAL: Found MBECCFIR[41]: UE during 3rd phase of VCM so more bad then chip mark can fix on %s.",
                        mss::c_str(i_target));
        }

        // Else If MBECCFIR[38]: MCE
        else if (l_mbeccfir.getBit<38>())
        {
            FAPI_ERR("WARNING: Found MBECCFIR[38]: MCE during 3rd phase of VCM so chip mark verified on %s.",
                     mss::c_str(i_target));

            o_mark_verified = true;


            // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
            FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                        l_port,
                                        l_dimm,
                                        l_rank,
                                        l_dqBitmap));

            // Check what is being steered
            FAPI_TRY(mss_check_steering(i_target,
                                        i_rank,
                                        l_dramSparePort0Symbol,
                                        l_dramSparePort1Symbol,
                                        l_eccSpareSymbol));

            // x8 mode:
            if(l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
            {
                // If chip mark happened to come from a byte position that is being
                // steered, it means we actually have to mark the spare bad instead.
                if(((0 == l_port) && ( l_dramSparePort0Symbol == l_chip_mark)) ||
                   ((1 == l_port) && ( l_dramSparePort1Symbol == l_chip_mark)))

                {
                    // Mark the 8 Centaur DQs associated with the spare as bad
                    l_dqBitmap[9] = 0xff;
                    FAPI_ERR("WARNING: x8 chip mark came from chip possition being steered, meaning x8 SPARE is bad");
                    FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[9] on %s", l_port, l_dimm, l_rank,
                             mss::c_str(i_target));
                }
                else
                {
                    // Mark the 8 Centaur DQs associated with the chip mark as bad
                    l_dqBitmap[l_centaurDQ / 8] = 0xff;
                    FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[%d] on %s", l_port, l_dimm, l_rank,
                             l_centaurDQ / 8, mss::c_str(i_target));
                }
            }

            // x4 mode:
            else if(l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
            {
                // NOTE: DRAM spare and ECC spare should never be fixing the same symbols
                // since DRAM spare can't be used to fix ECC spare and vice versa.

                // If chip mark happened to come from a chip position that is being
                // steered to a DRAM spare, it means we actually have to mark the spare bad instead.
                if(((0 == l_port) && ( l_dramSparePort0Symbol == l_chip_mark)) ||
                   ((1 == l_port) && ( l_dramSparePort1Symbol == l_chip_mark)))
                {
                    // Mark the 4 Centaur DQs associated with the DRAM spare as bad
                    if (l_spare_dram[l_port][l_dimm][l_rank] == 1)
                    {
                        l_dqBitmap[9] = 0xf0;    // LOW_NIBBLE = 1
                    }
                    else if (l_spare_dram[l_port][l_dimm][l_rank] == 2)
                    {
                        l_dqBitmap[9] = 0x0f;    // HIGH_NIBBLE = 2
                    }

                    FAPI_ERR("WARNING: x4 chip mark came from chip possition being steered, meaning x4 DRAM SPARE is bad");
                    FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[9] = %02x on %s",
                             l_port, l_dimm, l_rank, l_dqBitmap[9], mss::c_str(i_target));
                }
                // Else if chip mark happened to come from a chip position that is being
                // steered to the ECC spare, it means we actually have to mark the ECC spare bad instead.
                else if (l_eccSpareSymbol == l_chip_mark)
                {
                    // Mark the 4 Centaur DQs associated with the ECC spare as bad: port 1, dq 68-71
                    l_port = 1;
                    l_dqBitmap[8] = 0x0f;
                    FAPI_ERR("WARNING: x4 chip mark came from chip possition being steered, meaning x4 ECC SPARE is bad");
                    FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[8] = %02x on %s",
                             l_port, l_dimm, l_rank, l_dqBitmap[8], mss::c_str(i_target));
                }

                else
                {
                    // Mark the 4 Centaur DQs associated with the chip mark as bad
                    if (l_centaurDQ % 8)
                    {
                        l_dqBitmap[l_centaurDQ / 8] = l_dqBitmap[l_centaurDQ / 8] | 0x0f;
                    }
                    else
                    {
                        l_dqBitmap[l_centaurDQ / 8] = l_dqBitmap[l_centaurDQ / 8] | 0xf0;
                    }

                    FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[%d] = %02x on %s",
                             l_port, l_dimm, l_rank, l_centaurDQ / 8, l_dqBitmap[l_centaurDQ / 8], mss::c_str(i_target));
                }
            }

            // Update the bad DQ Bitmap for l_port, l_dimm, l_rank
            FAPI_TRY(dimmSetBadDqBitmap(i_target,
                                        l_port,
                                        l_dimm,
                                        l_rank,
                                        l_dqBitmap));
        }

        // Else no evidence chip is bad so remove chip mark
        else
        {
            FAPI_ERR("WARNING: Couldn't verify chip was bad so removing chip mark on %s.", mss::c_str(i_target));
            FAPI_TRY(mss_put_mark_store(i_target, i_rank, l_symbol_mark, MSS_INVALID_SYMBOL ));
        }

        FAPI_INF("EXIT mss_ipl_verify_chip_mark()");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Runs IPL steer procedure on a given rank
    /// @param[in]  i_target          Reference to target
    /// @param[in]  i_rank            Rank to run on
    /// @param[in]  i_pattern_index   Index to keep track of which pattern in
    /// @param[out] o_error_summary   Maint error summary per rank, per pattern
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ipl_steer(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                    const uint8_t i_rank,
                                    const uint8_t i_pattern_index,
                                    uint8_t (&o_error_summary)[8][9])
    {
        fapi2::buffer<uint64_t> l_startAddr;
        fapi2::buffer<uint64_t> l_endAddr;
        bool l_poll = true;
        uint32_t l_stopCondition = 0;
        mss_MaintCmd::TimeBaseSpeed l_speed;
        fapi2::buffer<uint64_t> l_mbeccfir;
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
        uint8_t l_mbaPosition = 0;
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint8_t l_centaurDQ = 0;
        uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {0}; // 10 byte array of bad bits
        uint8_t l_symbol_mark = MSS_INVALID_SYMBOL;
        uint8_t l_chip_mark = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
        uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
        uint8_t l_bad_bits[MAX_PORTS_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE] =
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        };
        // NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
        uint8_t l_spare_dram[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; // Array defining if spare dram exit
        uint8_t l_dramWidth = 0;

        bool l_x8_dram_spare_exists = false;
        bool l_x8_dram_spare_available = false;
        bool l_do_x8_dram_steer = false;

        bool l_x4_dram_spare_exists = false;
        bool l_x4_dram_spare_available = false;
        bool l_do_x4_dram_steer = false;

        bool l_x4_ecc_spare_exists = false;
        bool l_x4_ecc_spare_available = false;
        bool l_do_x4_ecc_steer = false;
        mss_SuperFastRead* sfread;
        mss_TimeBaseSteerCleanup* tbsteer;
        FAPI_INF("ENTER mss_ipl_steer()");

        //------------------------------------------------------
        // NOTE: This function will only do one of the 3 possible steer types,
        // depending on what spares exist and what spares are available:
        //
        //     1. x8 dram steer
        //     2. x4 dram steer
        //     3. x4 ecc steer
        //     4. (or no steer if spares not available)
        //------------------------------------------------------


        //------------------------------------------------------
        // Get l_dramWidth
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

        //------------------------------------------------------
        // Get array attribute that defines if spare dram exits
        //------------------------------------------------------
        //     l_spare_dram[port][dimm][rank]
        //     NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
        //     NOTE: Typically will same value for whole Centaur.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_target,  l_spare_dram));

        //------------------------------------------------------
        // Read mark store to find chip mark (don't care about symbol mark)
        //------------------------------------------------------
        FAPI_TRY(mss_get_mark_store(i_target, i_rank, l_symbol_mark, l_chip_mark ));

        if (MSS_INVALID_SYMBOL == l_chip_mark)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MEMDIAGS_CANT_STEER().
                        set_MBA(i_target),
                        "Can't steer without rank%d chip mark %s", i_rank, mss::c_str(i_target));
        }

        //------------------------------------------------------
        // x8 mode:
        //------------------------------------------------------

        //------------------------------------------------------
        // Determine if x8 dram spare exits and is available
        //------------------------------------------------------
        if (l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
        {
            // Find which port the chip mark is on, 0 or 1
            l_port = mss_x8_chip_mark_to_centaurDQ[l_chip_mark / 4][1];

            // Find l_dimm, 0 or 1
            l_dimm = i_rank / 4;

            // Find l_rank, 0,1,2,3

            l_rank = i_rank % 4;

            // Determine if spare x8 DRAM exists
            l_x8_dram_spare_exists = l_spare_dram[l_port][l_dimm][l_rank] == 3; // FULL_BYTE

            // Determine if spare x8 DRAM is available
            FAPI_TRY(mss_check_steering(i_target,
                                        i_rank,
                                        l_dramSparePort0Symbol,
                                        l_dramSparePort1Symbol,
                                        l_eccSpareSymbol));

            l_x8_dram_spare_available = ((0 == l_port) && ( l_dramSparePort0Symbol == MSS_INVALID_SYMBOL)) ||
                                        ((1 == l_port) && ( l_dramSparePort1Symbol == MSS_INVALID_SYMBOL));

            l_do_x8_dram_steer = l_x8_dram_spare_exists && l_x8_dram_spare_available;
        }


        //------------------------------------------------------
        // x4 mode:
        //------------------------------------------------------

        else if (l_dramWidth == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
        {
            // Find which port the chip mark is on, 0 or 1
            l_port = mss_x4_chip_mark_to_centaurDQ[l_chip_mark / 2][1];

            // Find l_dimm, 0 or 1
            l_dimm = i_rank / 4;

            // Find l_rank, 0,1,2,3
            l_rank = i_rank % 4;

            // Determine if spare x4 DRAM exists
            l_x4_dram_spare_exists = (l_spare_dram[l_port][l_dimm][l_rank] == 1) || // LOW_NIBBLE = 1
                                     (l_spare_dram[l_port][l_dimm][l_rank] == 2);   // HIGH_NIBBLE = 2

            // Determine if spare x4 DRAM is available
            FAPI_TRY(mss_check_steering(i_target,
                                        i_rank,
                                        l_dramSparePort0Symbol,
                                        l_dramSparePort1Symbol,
                                        l_eccSpareSymbol));

            l_x4_dram_spare_available = ((0 == l_port) && ( l_dramSparePort0Symbol == MSS_INVALID_SYMBOL)) ||
                                        ((1 == l_port) && ( l_dramSparePort1Symbol == MSS_INVALID_SYMBOL));

            // Do x4 dram steer if x4 DRAM spare exists and is available on this port,
            // as long as chip mark not actually fixing ecc spare, since can't use dram
            // spare to fix ecc spare.
            if ((l_x4_dram_spare_exists && l_x4_dram_spare_available) && !(l_eccSpareSymbol == l_chip_mark))
            {
                l_do_x4_dram_steer = true;
            }

            // Only try x4 ecc steer if can't do x4 dram steer
            if (!l_do_x4_dram_steer)
            {
                // Always true in x4 mode
                l_x4_ecc_spare_exists = true;

                // Determine if x4 ecc spare is available
                l_x4_ecc_spare_available = l_eccSpareSymbol == MSS_INVALID_SYMBOL;

                // Do x4 ecc steer if x4 ecc spare exists and is available,
                // as long as chip mark not actually fixing dram spare, since can't use ecc
                // spare to fix dram spare.
                if ((l_x4_ecc_spare_exists && l_x4_ecc_spare_available) && !((l_dramSparePort0Symbol == l_chip_mark)
                        || (l_dramSparePort1Symbol == l_chip_mark)))
                {
                    l_do_x4_ecc_steer = true;
                }
            }
        }

        //------------------------------------------------------
        // Exit if no spares available
        //------------------------------------------------------
        if (!l_do_x8_dram_steer && !l_do_x4_dram_steer && !l_do_x4_ecc_steer)
        {
            FAPI_ERR("WARNING: No spares available, so EXIT mss_ipl_steer() on %s.", mss::c_str(i_target));
            return fapi2::FAPI2_RC_FALSE;
        }

        if (l_do_x8_dram_steer)
        {
            FAPI_ERR("WARNING: Attempting x8 dram steer on %s.", mss::c_str(i_target));
        }

        if (l_do_x4_dram_steer)
        {
            FAPI_ERR("WARNING: Attempting x4 dram steer on %s.", mss::c_str(i_target));
        }

        if (l_do_x4_ecc_steer)
        {
            FAPI_ERR("WARNING: Attempting x4 ecc steer on %s.", mss::c_str(i_target));
        }

        //------------------------------------------------------
        // Set write mux, wait for periodic cal, set read mux, for the given rank
        //------------------------------------------------------
        FAPI_TRY(mss_do_steering(i_target,           // MBA
                                 i_rank,             // Master rank: 0-7
                                 l_chip_mark,        // First symbol index of byte to steer
                                 l_do_x4_ecc_steer)); // True if can't do x4 dram steer and x4 ecc steer spare available

        //------------------------------------------------------
        // Cleanup before starting 1st pass
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, i_rank));

        //------------------------------------------------------
        // Get address range to run maint cmds on
        //------------------------------------------------------
        FAPI_TRY(mss_get_address_range( i_target,
                                        i_rank,
                                        l_startAddr,
                                        l_endAddr ));

        //------------------------------------------------------
        // 1st pass: timebase steer cleanup, to end of rank
        //------------------------------------------------------
        l_speed = mss_MaintCmd::FAST_MAX_BW_IMPACT;

        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

        tbsteer = new mss_TimeBaseSteerCleanup( i_target,
                                                l_startAddr,
                                                l_endAddr,
                                                l_speed,
                                                l_stopCondition,
                                                l_poll);

        FAPI_TRY(tbsteer->setupAndExecuteCmd());
        delete tbsteer;

        //------------------------------------------------------
        // Get Centaur target for the given MBA
        //------------------------------------------------------
        l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //------------------------------------------------------
        // Get MBA position: 0 = mba01, 1 = mba23
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

        //------------------------------------------------------
        // Read MBECCFIR
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));

        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);


        // If MBECCFIR[41]:UE, or MBECCFIR[39]:RCE
        if (l_mbeccfir.getBit<41>() || l_mbeccfir.getBit<39>())
        {

            FAPI_ERR("FATAL: Found MBECCFIR[41]:UE or MBECCFIR[39]:RCE during 1st phase of steer, so more bad then chip mark can fix on %s."
                     , mss::c_str(i_target));

            // NOTE: We will leave chip mark in markstore and leave muxes set,
            // but not bother to update bad bit attribute.
            // Primary purpose of bad bit attribute is to
            // allow us to restore repairs on subsequent IPLs, and since we
            // have UEs we know are going to callout the hw anyway.

            // UE isolation
            // NOTE: UE isolation is based on comparing trapped actual data to a
            // known pattern. Since Centaur doesn't trap UE data on timebased
            // steer cleanup, UE isolation function will just say both DIMMs
            // in the logical DIMM pair are bad. A future enhancement to
            // the UE isolation function may allow us to isolate.
            FAPI_TRY(mss_IPL_UE_isolation(i_target, l_rank, l_bad_bits));




            // NOTE: We will not update bad bit attribute with bad bits found
            // in UE isolation, since we're calling out the hw anyway. Also,
            // we'll most likely have too many bad bits to repair. Also, want
            // to avoid storing bad bits from a UE in case UE was just due to
            // some sort of setup problem, as opposed to real bad hw.

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MEMDIAGS_UE_OR_RCE_DURING_IPL_STEER().
                        set_MBA(i_target),
                        "FATAL: Found MBECCFIR[41]:UE or MBECCFIR[39]:RCE during 1st phase of steer, so more bad then chip mark can fix on %s.",
                        mss::c_str(i_target));
        }

        //------------------------------------------------------
        // Cleanup before starting 2nd pass
        //------------------------------------------------------
        FAPI_TRY(mss_error_status_cleanup(i_target, i_rank));

        //------------------------------------------------------
        // 2nd pass: super fast read, to end of rank
        //------------------------------------------------------

        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

        sfread = new mss_SuperFastRead( i_target,
                                        l_startAddr,
                                        l_endAddr,
                                        l_stopCondition,
                                        l_poll);

        FAPI_TRY(sfread->setupAndExecuteCmd());
        FAPI_TRY(sfread->cleanupCmd());
        delete sfread;

        //------------------------------------------------------
        // Read MBECCFIR
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_addr[l_mbaPosition], l_mbeccfir));

        mss_update_error_summary(l_rank,
                                 i_pattern_index,
                                 l_mbeccfir,
                                 o_error_summary);

        // If MBECCFIR[41]: UE
        if (l_mbeccfir.getBit<41>())
        {

            FAPI_ERR("FATAL: Found MBECCFIR[41]: UE during 2nd phase of steer, so more bad then chip mark can fix on %s.",
                     mss::c_str(i_target));

            // NOTE: We will leave chip mark in markstore and leave muxes set,
            // but not bother to update bad bit attribute.
            // Primary purpose of bad bit attribute is to
            // allow us to restore repairs on subsequent IPLs, and since we
            // have UEs we know are going to callout the hw anyway.

            // UE isolation
            // NOTE: UE isolation is based on comparing trapped actual data to a
            // known pattern.
            FAPI_TRY(mss_IPL_UE_isolation(i_target, l_rank, l_bad_bits));




            // NOTE: We will not update bad bit attribute with bad bits found
            // in UE isolation, since we're calling out the hw anyway. Also,
            // we'll most likely have too many bad bits to repair. Also, want
            // to avoid storing bad bits from a UE in case UE was just due to
            // some sort of setup problem, as opposed to real bad hw.

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MEMDIAGS_UE_OR_RCE_DURING_IPL_STEER().
                        set_MBA(i_target),
                        "FATAL: Found MBECCFIR[41]: UE during 2nd phase of steer, so more bad then chip mark can fix on %s.",
                        mss::c_str(i_target));
        }

        // Else If MBECCFIR[38]: MCE
        else if (l_mbeccfir.getBit<38>())
        {

            if (l_do_x8_dram_steer)
            {
                FAPI_ERR("WARNING: Found MBECCFIR[38]: MCE, during 2nd phase of steer, which means x8 dram spare is bad on %s.",
                         mss::c_str(i_target));

                // Leave chip mark in place and muxes set, and record bad bits in
                // VPD (both the byte we tried to steer around and the spare).

                // Find first Centaur DQ for the chip mark
                l_centaurDQ = mss_x8_chip_mark_to_centaurDQ[l_chip_mark / 4][0];

                // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));

                // Mark the 8 Centaur DQs associated with the x8 dram spare as bad
                l_dqBitmap[9] = 0xff;
                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[9] = %02x on %s",
                         l_port, l_dimm, l_rank, l_dqBitmap[9], mss::c_str(i_target));

                // Mark the 8 Centaur DQs associated with the chip mark as bad
                l_dqBitmap[l_centaurDQ / 8] = 0xff;
                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[%d] = %02x on %s",
                         l_port, l_dimm, l_rank, l_centaurDQ / 8, l_dqBitmap[l_centaurDQ / 8], mss::c_str(i_target));


                // Update the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmSetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));
            }

            else if (l_do_x4_dram_steer)
            {
                FAPI_ERR("WARNING: Found MBECCFIR[38]: MCE, during 2nd phase of steer, which means x4 dram spare is bad on %s.",
                         mss::c_str(i_target));

                // Leave chip mark in place and muxes set, and record bad bits in
                // VPD (both the byte we tried to steer around and the spare).

                // Find first Centaur DQ for the chip mark
                l_centaurDQ = mss_x4_chip_mark_to_centaurDQ[l_chip_mark / 2][0];

                // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));

                // Mark the 4 Centaur DQs associated with the x4 dram spare as bad
                if (l_spare_dram[l_port][l_dimm][l_rank] == 1)
                {
                    l_dqBitmap[9] = 0xf0;    // LOW_NIBBLE = 1
                }
                else if (l_spare_dram[l_port][l_dimm][l_rank] == 2)
                {
                    l_dqBitmap[9] = 0x0f;    // HIGH_NIBBLE = 2
                }

                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[9] = %02x on %s",
                         l_port, l_dimm, l_rank, l_dqBitmap[9], mss::c_str(i_target));

                // Mark the 4 Centaur DQs associated with the chip mark as bad
                if (l_centaurDQ % 8)
                {
                    l_dqBitmap[l_centaurDQ / 8] = 0x0f;
                }
                else
                {
                    l_dqBitmap[l_centaurDQ / 8] = 0xf0;
                }

                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[%d] = %02x on %s",
                         l_port, l_dimm, l_rank, l_centaurDQ / 8, l_dqBitmap[l_centaurDQ / 8], mss::c_str(i_target));

                // Update the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmSetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));
            }
            else if (l_do_x4_ecc_steer)
            {
                FAPI_ERR("WARNING: Found MBECCFIR[38]: MCE, during 2nd phase of steer, which means x4 ecc spare is bad on %s.",
                         mss::c_str(i_target));

                // Leave chip mark in place and muxes set, and record bad bits in
                // VPD (both the byte we tried to steer around and the spare).

                // Find first Centaur DQ for the chip mark
                l_centaurDQ = mss_x4_chip_mark_to_centaurDQ[l_chip_mark / 2][0];

                // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));

                // Mark the 4 Centaur DQs associated with the ECC spare as bad: port 1, dq 68-71
                l_port = 1;
                l_dqBitmap[8] = 0x0f;
                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[8] = %02x on %s",
                         l_port, l_dimm, l_rank, l_dqBitmap[8], mss::c_str(i_target));

                // Mark the 4 Centaur DQs associated with the chip mark as bad
                if (l_centaurDQ % 8)
                {
                    l_dqBitmap[l_centaurDQ / 8] = 0x0f;
                }
                else
                {
                    l_dqBitmap[l_centaurDQ / 8] = 0xf0;
                }

                FAPI_ERR("WARNING: Updating attribute for port%d, dimm%d, rank%d, l_dqBitmap[%d] = %02x on %s",
                         l_port, l_dimm, l_rank, l_centaurDQ / 8, l_dqBitmap[l_centaurDQ / 8], mss::c_str(i_target));

                // Update the bad DQ Bitmap for l_port, l_dimm, l_rank
                FAPI_TRY(dimmSetBadDqBitmap(i_target,
                                            l_port,
                                            l_dimm,
                                            l_rank,
                                            l_dqBitmap));
            }

            FAPI_ASSERT_NOEXIT(false,
                               fapi2::CEN_MSS_MEMDIAGS_ECC_SPARE_BAD().
                               set_MBA(i_target));
        }
        // Else spare is good and steer was successful,
        // so remove chip mark from mark store.
        else
        {
            FAPI_ERR("WARNING: Steer successful, removing chip mark on %s.", mss::c_str(i_target));
            FAPI_TRY(mss_put_mark_store(i_target, i_rank, l_symbol_mark, MSS_INVALID_SYMBOL ));
        }

        FAPI_INF("EXIT mss_ipl_steer()");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Clears ECC error status
    /// @param[in]  i_target    Reference to target
    /// @param[in]  i_rank      Rank to run on
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_error_status_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_rank)
    {
        fapi2::buffer<uint64_t> l_mbeccfir_and;
        fapi2::buffer<uint64_t> l_mbspa_and;
        fapi2::buffer<uint64_t> l_mbstr;
        fapi2::buffer<uint64_t> l_mbmaca;
        uint8_t l_mbaPosition = 0;

        static const uint32_t l_mbeccfir_and_addr[MAX_MBA_PER_CEN] =
        {
            // port0/1                         port2/3
            CEN_ECC01_MBECCFIR_WOX_AND,  CEN_ECC23_MBECCFIR_WOX_AND
        };

        static const uint32_t l_mbstr_addr[MAX_MBA_PER_CEN] =
        {
            // port0/1                port2/3
            CEN_MCBISTS01_MBSTRQ,  CEN_MCBISTS23_MBSTRQ
        };

        FAPI_INF("ENTER mss_error_status_cleanup()");

        //------------------------------------------------------
        // Get Centaur target for the given MBA
        //------------------------------------------------------
        const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //------------------------------------------------------
        // Get MBA position: 0 = mba01, 1 = mba23
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));
        //------------------------------------------------------
        // Read MBMACA
        //------------------------------------------------------
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));
        //------------------------------------------------------
        // Clear all scrub error counters
        //------------------------------------------------------
        // Read MBSTR
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbstr_addr[l_mbaPosition], l_mbstr));
        // Setting this bit clears all scrub error counters.
        // HW clears the bit again once counters are cleared.
        // NOTE: DD1 bug: also clears fetch CE/UE addresses, so careful using
        // at runtime.
        l_mbstr.setBit<53>();
        //------------------------------------------------------
        // Clear error status bits 40-46 in MCMACA
        //------------------------------------------------------
        l_mbmaca.clearBit<40, 7>();

        //------------------------------------------------------
        // Setup MBECCFIR AND mask
        //------------------------------------------------------

        // Start with all 1's in AND mask
        l_mbeccfir_and.flush<1>();

        // 20-27:Maint MPE
        FAPI_TRY(l_mbeccfir_and.clearBit(20 + i_rank));

        // 36: Maint NCE
        // 37: Maint SCE
        // 38: Maint MCE
        // 39: Maint RCE
        // 40: Maint SUE
        // 41: Maint UE
        l_mbeccfir_and.clearBit<36, 6>();

        //------------------------------------------------------
        // Setup MBSPA AND mask
        //------------------------------------------------------

        // Start with all 0's in AND mask, because we want to clear everything
        l_mbspa_and.flush<0>();

        //------------------------------------------------------
        // Write MBSTR
        //------------------------------------------------------
        FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbstr_addr[l_mbaPosition], l_mbstr));

        //------------------------------------------------------
        // Write to MBECCFIR AND mask
        //------------------------------------------------------
        FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbeccfir_and_addr[l_mbaPosition], l_mbeccfir_and));

        //------------------------------------------------------
        // Write to MBSPA AND mask
        //------------------------------------------------------
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBSPAQ_WOX_AND, l_mbspa_and));

        //------------------------------------------------------
        // Write MCMACA
        //------------------------------------------------------
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));
        FAPI_INF("EXIT mss_error_status_cleanup()");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Does a targeted fast scrub of either single address or whole rank
    /// @param[in]  i_target          Reference to target (MBA)
    /// @param[in]  i_address         Address to scrub
    /// @param[in]  i_address_range   SINGLE_ADDRESS, or WHOLE_RANK
    /// @param[in]  i_ce_type         SOFT or INTERMITTENT or HARD or any combo
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_targeted_fast_scrub(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const fapi2::buffer<uint64_t> i_address,
            const AddressRange i_address_range,
            uint8_t i_ce_type)
    {
        fapi2::buffer<uint64_t> l_mbstr;
        fapi2::buffer<uint64_t> l_mbmccq;
        fapi2::buffer<uint64_t> l_startAddr;
        fapi2::buffer<uint64_t> l_endAddr;
        uint8_t l_mbaPosition = 0;
        bool l_poll = true;
        uint32_t l_stopCondition = 0;
        mss_MaintCmd::TimeBaseSpeed l_speed;
        uint8_t l_rank = 0;
        mss_TimeBaseScrub* tbscrub;

        static const uint32_t l_mbstr_addr[MAX_MBA_PER_CEN] =
        {
            // port0/1                port2/3
            CEN_MCBISTS01_MBSTRQ,  CEN_MCBISTS23_MBSTRQ
        };

        //------------------------------------------------------
        // Get Centaur target for the given MBA
        //------------------------------------------------------
        const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //------------------------------------------------------
        // Stop any running maint cmd
        //------------------------------------------------------

        // Read MBMCCQ
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCCQ, l_mbmccq));
        // Set bit 1 to force the cmd to stop
        l_mbmccq.setBit<1>();

        // Write MBMCCQ
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCCQ, l_mbmccq));

        // Clear bit 1 again, just in case cmd was already stopped
        // in which case, bit 1 doesn't self-clear after we set it.
        l_mbmccq.clearBit<1>();

        // Write MBMCCQ
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCCQ, l_mbmccq));

        //------------------------------------------------------
        // Set CE types to count and clear all scrub error counters
        //------------------------------------------------------

        // Read MBSTR
        FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbstr_addr[l_mbaPosition], l_mbstr));
        // Start by clearing all bits 55,56,57
        l_mbstr.clearBit<55, 3>();

        // Enable SOFT CE counting
        if ( 0 != (i_ce_type & SOFT) )
        {
            l_mbstr.setBit<55>();
        }

        // Enable INTERMITTENT CE counting
        if ( 0 != (i_ce_type & INTERMITTENT) )
        {
            l_mbstr.setBit<56>();
        }

        // Enable HARD CE counting
        if ( 0 != (i_ce_type & HARD) )
        {
            l_mbstr.setBit<57>();
        }


        // Setting this bit clears all scrub error counters.
        // HW clears the bit again once counters are cleared.
        // NOTE: DD1 bug: also clears fetch CE/UE addresses, so careful using
        // at runtime.
        l_mbstr.setBit<53>();

        // Write MBSTR
        FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbstr_addr[l_mbaPosition], l_mbstr));

        //------------------------------------------------------
        // Get address range to run maint cmds on
        //------------------------------------------------------

        // SINGLE_ADDRESS
        if (i_address_range == SINGLE_ADDRESS)
        {
            l_startAddr = i_address;
            l_endAddr = i_address;
        }

        // WHOLE_RANK
        else
        {
            // Get l_rank
            FAPI_TRY(i_address.extract(l_rank, 1, 3, 8 - 3));    // (1:3)
            FAPI_TRY(mss_get_address_range( i_target,
                                            l_rank,
                                            l_startAddr,
                                            l_endAddr ));
        }

        //------------------------------------------------------
        // Set timebase as possible
        //------------------------------------------------------
        l_speed = mss_MaintCmd::FAST_MAX_BW_IMPACT;

        //------------------------------------------------------
        // Don't stop on errors
        // Stop on end address
        //------------------------------------------------------
        l_stopCondition =
            mss_MaintCmd::STOP_ON_END_ADDRESS;

        //------------------------------------------------------
        // Create tbscrub object and execute cmd
        //------------------------------------------------------
        tbscrub = new mss_TimeBaseScrub( i_target,
                                         l_startAddr,
                                         l_endAddr,
                                         l_speed,
                                         l_stopCondition,
                                         l_poll);

        FAPI_TRY(tbscrub->setupAndExecuteCmd());
        delete tbscrub;
        FAPI_INF("EXIT mss_targeted_fast_scrub()");
    fapi_try_exit:
        return fapi2::current_err;
    }
} // extern "C"
