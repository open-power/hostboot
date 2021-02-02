/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l3err_extract.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
///----------------------------------------------------------------------------
///
/// @file p10_l3err_extract.C
///
/// @brief Parse and extract error information from L3 trace array (FAPI)
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_l3err_extract.H>
#include <p10_proc_gettracearray.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t P10_L3ERR_EXTRACT_ECC_PAT[73] =
{
    0xc4, 0x8c, 0x94, 0xd0, 0xf4, 0xb0, 0xa8, 0xe0, //0
    0x62, 0x46, 0x4a, 0x68, 0x7a, 0x58, 0x54, 0x70, //8
    0x31, 0x23, 0x25, 0x34, 0x3d, 0x2c, 0x2a, 0x38, //16
    0x98, 0x91, 0x92, 0x1a, 0x9e, 0x16, 0x15, 0x1c, //24
    0x4c, 0xc8, 0x49, 0x0d, 0x4f, 0x0b, 0x8a, 0x0e, //32
    0x26, 0x64, 0xa4, 0x86, 0xa7, 0x85, 0x45, 0x07, //40
    0x13, 0x32, 0x52, 0x43, 0xd3, 0xc2, 0xa2, 0x83, //48
    0x89, 0x19, 0x29, 0xa1, 0xe9, 0x61, 0x51, 0xc1, //56
    0xc7, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 //64
};

const uint8_t L3ERR_MAX_CYCLES_BACK = 9;
const uint8_t L3ERR_NUM_DWS = 8;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point
fapi2::ReturnCode p10_l3err_extract(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const fapi2::variable_buffer& i_ta_data,
    p10_l3err_extract_err_type i_err_type,
    p10_l3err_extract_err_data& o_err_data,
    bool& o_error_found)
{
    bool                    l_err_found = false;
    bool                    l_err_is_ce = true; //ce or ue flag
    int32_t                 l_trace_index = 0;
    uint32_t                l_indexes[L3ERR_MAX_CYCLES_BACK];
    fapi2::variable_buffer  l_trace_array[P10_TRACEARRAY_NUM_ROWS];
    uint8_t                 l_syndrome = 0;
    uint8_t                 l_dw = 0;
    uint32_t                l_ta_length = i_ta_data.getBitLength();
    uint32_t                l_exp_ta_length = P10_TRACEARRAY_NUM_ROWS *
            P10_TRACEARRAY_BITS_PER_ROW;
    uint32_t                l_syndrome_col = 0;
    uint32_t                l_addr46_57 = 0;
    uint32_t                l_rd_cmd = 0;
    uint32_t                l_ce_dw = 0;
    uint32_t                l_ue_dw = 0;
    uint8_t                 l_member = 0;
    int32_t                 l_ce_trace_index = 0;
    uint32_t                l_indexes_index = 0;
    uint32_t                l_cycles = 0;
    uint32_t                l_rd_cmd_cycle = 0;


    // mark function entry
    FAPI_DBG("Entering p10_l3err_extract...");

    // check if the supplied data is the correct size, used mostly for
    // manual tool input
    FAPI_ASSERT(l_ta_length == l_exp_ta_length,
                fapi2::P10_L3ERR_EXTRACT_TA_WRONG_SIZE_ERR()
                .set_TARGET(i_target)
                .set_TA_DATA_SIZE(l_ta_length)
                .set_EXP_TA_DATA_SIZE(l_exp_ta_length),
                "Specified trace array length (%u) does not match expected length (%u)",
                l_ta_length, l_exp_ta_length);

    // build the indexable array and print out contents at the same time for debug
    for(uint8_t i = 0; i < P10_TRACEARRAY_NUM_ROWS; i++)
    {
        l_trace_array[i].resize(P10_TRACEARRAY_BITS_PER_ROW);
        FAPI_TRY(i_ta_data.extract(l_trace_array[i],
                                   P10_TRACEARRAY_BITS_PER_ROW * i,
                                   P10_TRACEARRAY_BITS_PER_ROW),
                 "buffer extract() call returns an error.");
        FAPI_DBG("%2X: 0x%016llX%016llX",
                 i, l_trace_array[i].get<uint64_t>( 0 ),
                 l_trace_array[i].get<uint64_t>( 1 ));
    }

    //********************************************************************//
    // L3 Trace                                                           //
    //********************************************************************//
    // The array has 2 parts. Both halves matter for this code.           //
    // This code will handle both parts as a whole for simplicity.        //
    //                                                                    //
    // Three entry formats exist for bits 0:94:                           //
    //    ============================================                    //
    //    | 0:87 | 88:94 | Format Type               |                    //
    //    |------+-------+---------------------------|                    //
    //    |  =0  |  =0   | Compression start stamp   |                    //
    //    | !=0  |  =0   | Compression stamp         |                    //
    //    | any  | !=0   | Trace data (see below)    |                    //
    //    ============================================                    //
    //                                                                    //
    // Notes about compression:                                           //
    //  - The compression start stamp is set when compression is turned   //
    //     on, so it will probably never be in the trace. It represents   //
    //     no clock cycles so it can be ignored.                          //
    //  - The compression stamp indicates a repeat count that should be   //
    //     added to the repeat count of the previous data entry.          //
    //                                                                    //
    // L3_1 trace array                                                   //
    //                                                                    //
    //  0:  11       l3caadd_b0_cac_addr_ccar1(46 to 57)                  //
    //                    due to serialization of the read data bus,      //
    //                    only one bank can be read at a time             //
    //                    (all reads are two nclks)                       //
    //  12: 23       l3caadd_b1_cac_addr_ccar1(46 to 57)                  //
    //  24: 35       l3caadd_b2_cac_addr_ccar1(46 to 57)                  //
    //  36: 47       l3caadd_b3_cac_addr_ccar1(46 to 57)                  //
    //  48: 51       l3cactl_rd_mem_ccar1(0 to 3)                         //
    //  52: 55       l3cactl_bx_rd_cmd_ccar1(0 to 3)                      //
    //                    so all error (ce, ue, sue) that occur on the    //
    //                    same pair of clks are associated with the bank  //
    //                    indicated by this signal                        //
    //  56: 63       l3cacerr_rd_df_ce_ccar7_8(0 to 7)                    //
    //                    bit 0 is for DW0, bit 1 for DW1 etc             //
    //  64: 71       l3cacerr_rd_df_ue_ccar7_8(0 to 7)                    //
    //  72: 79       l3cacerr_rd_df_sue_ccar7_8(0 to 7)                   //
    //  80: 87       l3cacerr_rd_df_syn_ccar7_8(0 to 7)                   //
    //                    multiple error bits may assert on the same clk  //
    //                    if there are multiple errors on the same clk,   //
    //                    this signal provides the syndrome for one of    //
    //                    the error based on the following priority:      //
    //                    highest priority: UE,  DW0, DW1... DW7          //
    //                    middle priority:  SUE, DW0, DW1... DW7          //
    //                    lowest priority:  CE,  DW0, DW1... DW7          //
    //                                                                    //
    //********************************************************************//

    ////////////////////////////////////////////////////////////////////////
    // Look for CE/UE
    ////////////////////////////////////////////////////////////////////////
    l_err_found = false;
    l_trace_index = P10_TRACEARRAY_NUM_ROWS; // the last entry in the array is the newest
    FAPI_DBG("l_trace_index = %X", l_trace_index);

    while( !l_err_found && (l_trace_index > 0) )
    {
        l_trace_index--;

        if (p10_tracearray_is_trace_start_marker(l_trace_array[l_trace_index]) ==
            fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_DBG("Head found at trace index %i", l_trace_index);
            FAPI_DBG("%2X: 0x%016llX%016llX",
                     l_trace_index,
                     l_trace_array[l_trace_index].get<uint64_t>( 0 ),
                     l_trace_array[l_trace_index].get<uint64_t>( 1 ));
            l_err_found = false;
            l_err_is_ce = true;
            break;
        }

        // Only look at data entries (ie ignore compression entries for now)
        l_trace_array[l_trace_index].extract(l_ce_dw, 56, 8);
        l_trace_array[l_trace_index].extract(l_ue_dw, 64, 8);

        if( !l_trace_array[l_trace_index].isBitClear( 88, 7 ) )
        {
            // Check for CE first if we are not explicitly looking for a UE
            if ( l_ce_dw && !(i_err_type == L3ERR_UE) )
            {
                FAPI_DBG("Found CE at trace index %i", l_trace_index);
                FAPI_DBG("%2X: 0x%016llX%016llX",
                         l_trace_index,
                         l_trace_array[l_trace_index].get<uint64_t>( 0 ),
                         l_trace_array[l_trace_index].get<uint64_t>( 1 ));
                l_err_found = true;
                l_err_is_ce = true;
                l_dw = l_ce_dw;
                break;
            }

            // Check for UE second if we are not explicitly looking for a CE
            if ( l_ue_dw && !(i_err_type == L3ERR_CE) )
            {
                FAPI_DBG("Found UE at trace index %i", l_trace_index);
                l_err_found = true;
                l_err_is_ce = false;
                l_dw = l_ue_dw;
                break;
            }
        }

    } //end loop looking for CE/UE

    for (uint8_t i = 0; i < 8; i++)
    {
        l_dw = l_dw << 1;

        if (l_dw == 0)
        {
            l_dw = i;
            break;
        }
    }

    FAPI_DBG("Found UE or CE: l_err_found = %i l_dw = %u", l_err_found, l_dw);
    o_error_found = l_err_found;

    // Return if error not found.
    if (!l_err_found)
    {
        FAPI_DBG("No error is found!");
        return fapi2::current_err;
    }

    // Generate compression l_indexes, we will use these to look back for data
    l_ce_trace_index = l_trace_index;

    while( (l_indexes_index < L3ERR_MAX_CYCLES_BACK) &&
           (l_ce_trace_index > 0) )
    {
        FAPI_TRY(l_trace_array[l_ce_trace_index].extractToRight( l_cycles, 88, 7 ),
                 "buffer extractToRight() call returns an error.");

        if( l_cycles != 0 )
        {
            //This is a data entry with LFSR data
            //convert LFSR to cycle count
            // lfsr polynomial f(x) = 1 + x + x^7
            //7f,3f,5f,2f,57,2b,55,2a,15
            switch( l_cycles )
            {
                case 0x7F:
                    l_cycles = 1;
                    break;

                case 0x3F:
                    l_cycles = 2;
                    break;

                case 0x5F:
                    l_cycles = 3;
                    break;

                case 0x2F:
                    l_cycles = 4;
                    break;

                case 0x57:
                    l_cycles = 5;
                    break;

                case 0x2b:
                    l_cycles = 6;
                    break;

                case 0x55:
                    l_cycles = 7;
                    break;

                case 0x2a:
                    l_cycles = 8;
                    break;

                // Should not need more than 8
                default:
                    l_cycles = 8;
                    break;
            }

            FAPI_DBG("cycles = %x", l_cycles);

            // Put "l_trace_index" into "l_indexes" up to "cycles" number of times
            for( ; (l_cycles > 0) && (l_indexes_index < L3ERR_MAX_CYCLES_BACK);
                 l_cycles-- )
            {
                l_indexes[l_indexes_index] = l_ce_trace_index;
                l_indexes_index++;
            }
        }
        else
        {
            //This is a compression stamp
            FAPI_DBG( "Skipping compression stamp\n" );
        }

        //Go look at the previous entry
        l_ce_trace_index--;

    } // while


    for ( int8_t i = L3ERR_MAX_CYCLES_BACK - 1; i >= 0; i--)
    {
        FAPI_DBG("uncomp %i cycles back: 0x%016llX%016llX",
                 i, l_trace_array[l_indexes[i]].get<uint64_t>( 0 ),
                 l_trace_array[l_indexes[i]].get<uint64_t>( 1 ));

    }

    FAPI_TRY(l_trace_array[l_indexes[6]].extractToRight( l_rd_cmd, 52, 4 ),
             "extractToRight() - rd_cmd returns an error.");

    if (l_rd_cmd != 0)
    {
        l_rd_cmd_cycle = l_indexes[6];
        FAPI_DBG("Read command 6 cycles back\n");
    }
    else
    {
        FAPI_TRY(l_trace_array[l_indexes[7]].extractToRight( l_rd_cmd, 52, 4 ),
                 "extractToRight() - rd_cmd returns an error.");

        if (l_rd_cmd != 0)
        {
            l_rd_cmd_cycle = l_indexes[7];
            FAPI_DBG("Read command 7 cycles back\n");
        }
    }

    FAPI_ASSERT(l_rd_cmd != 0,
                fapi2::P10_L3ERR_RD_CMD_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_6_0(l_trace_array[ 6 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_6_1(l_trace_array[ 6 ].get<uint64_t>( 1 ))
                .set_TRACE_ARRAY_7_0(l_trace_array[ 7 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_7_1(l_trace_array[ 7 ].get<uint64_t>( 1 )),
                "Error: could not find rd_cmd: 0x%016llX%016llX, 0x%016llX%016llX; ",
                l_trace_array[ 6 ].get<uint64_t>( 0 ),
                l_trace_array[ 6 ].get<uint64_t>( 1 ),
                l_trace_array[ 7 ].get<uint64_t>( 0 ),
                l_trace_array[ 7 ].get<uint64_t>( 1 ));

    ////////////////////////////////////////////////////////////////////////
    // Determine syndrome/column
    ////////////////////////////////////////////////////////////////////////
    FAPI_TRY(l_trace_array[ l_trace_index ].extractToRight( l_syndrome,  80,  8 ),
             "extractToRight() Syndrome data call returns an error.");


    FAPI_ASSERT(!(l_err_is_ce && (l_syndrome == 0)),
                fapi2::P10_L3ERR_EXTRACT_SYNDROME_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_1(l_trace_array[ l_trace_index ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_2(l_trace_array[ l_trace_index ].get<uint64_t>( 1 )),
                "Error: could not find syndrome: 0x%016llX%016llX; ",
                l_trace_array[ l_trace_index ].get<uint64_t>( 0 ),
                l_trace_array[ l_trace_index ].get<uint64_t>( 1 ));

    FAPI_DBG("Found syndrome: 0x%2X", l_syndrome);

    // Look up column from syndrome
    if ( l_err_is_ce )
    {
        // Decodes the specified syndrome into a column offset
        bool found = false;

        // Use the ECC lookup to find what column the error occured
        for( uint8_t i = 0;
             i < (uint8_t)(sizeof(P10_L3ERR_EXTRACT_ECC_PAT) / sizeof(uint8_t));
             i++)
        {
            if( l_syndrome == P10_L3ERR_EXTRACT_ECC_PAT[i] )
            {
                l_syndrome_col = i;
                found = true;
                break;
            }
        }

        FAPI_ASSERT(found,
                    fapi2::P10_L3ERR_EXTRACT_UNKNOWN_SYNDROME_ECC()
                    .set_TARGET(i_target)
                    .set_SYNDROME(l_syndrome),
                    "Syndrome ECC is unknown. %2X", l_syndrome);

        FAPI_DBG("syndrome_col = %u", l_syndrome_col);
    }
    else
    {
        l_syndrome_col = 0;
    }

    ////////////////////////////////////////////////////////////////////////
    // Determine member
    ////////////////////////////////////////////////////////////////////////
    FAPI_TRY(l_trace_array[ l_rd_cmd_cycle].extractToRight( l_member, 48, 4 ),
             "extractToRight() - Member returns an error.");

    ////////////////////////////////////////////////////////////////////////
    // Determine bank and real address(46:57)
    ////////////////////////////////////////////////////////////////////////
    if (l_rd_cmd & 0x8)
    {
        o_err_data.bank = 0;
        FAPI_TRY(l_trace_array[ l_rd_cmd_cycle].extractToRight( l_addr46_57,  0,  12 ),
                 "extractToRight() - l_addr46_57 returns an error.");
    }

    if (l_rd_cmd & 0x4)
    {
        o_err_data.bank = 1;
        FAPI_TRY(l_trace_array[ l_rd_cmd_cycle].extractToRight( l_addr46_57,  12,  12 ),
                 "extractToRight() - l_addr46_57 returns an error.");
    }

    if (l_rd_cmd & 0x2)
    {
        o_err_data.bank = 2;
        FAPI_TRY(l_trace_array[ l_rd_cmd_cycle].extractToRight( l_addr46_57,  24,  12 ),
                 "extractToRight() - l_addr46_57 returns an error.");
    }

    if (l_rd_cmd & 0x1)
    {
        o_err_data.bank = 3;
        FAPI_TRY(l_trace_array[ l_rd_cmd_cycle].extractToRight( l_addr46_57,  36,  12 ),
                 "extractToRight() - l_addr46_57 returns an error.");
    }

    ////////////////////////////////////////////////////////////////////////
    // Determine which half of cacheline the error is on
    //   6 cycles back AND a57 = 1 --> odd
    //   6 cycles back AND a57 = 0 --> even
    //   7 cycles back AND a57 = 1 --> even
    //   7 cycles back AND a57 = 0 --> odd
    ////////////////////////////////////////////////////////////////////////
    if ((l_rd_cmd_cycle == l_indexes[6]) && ((l_addr46_57 & 0x1) == 1))
    {
        o_err_data.cl_half = 1;
    }

    if ((l_rd_cmd_cycle == l_indexes[6]) && ((l_addr46_57 & 0x1) == 0))
    {
        o_err_data.cl_half = 0;
    }

    if ((l_rd_cmd_cycle == l_indexes[7]) && ((l_addr46_57 & 0x1) == 1))
    {
        o_err_data.cl_half = 0;
    }

    if ((l_rd_cmd_cycle == l_indexes[7]) && ((l_addr46_57 & 0x1) == 0))
    {
        o_err_data.cl_half = 1;
    }

    ////////////////////////////////////////////////////////////////////////
    // Print output info
    ////////////////////////////////////////////////////////////////////////
    o_err_data.ce_ue = l_err_is_ce ? L3ERR_CE : L3ERR_UE;
    o_err_data.member = l_member;
    o_err_data.dw = l_dw;
    o_err_data.syndrome_col = l_syndrome_col;
    o_err_data.real_address_46_57 = l_addr46_57;

    FAPI_DBG("   ce_ue: %u", o_err_data.ce_ue);
    FAPI_DBG("   member: %u", o_err_data.member);
    FAPI_DBG("   dw: %u", o_err_data.dw);
    FAPI_DBG("   rd_cmd: %u  bank: %u", l_rd_cmd, o_err_data.bank);
    FAPI_DBG("   cl_half: %s", o_err_data.cl_half ? "odd" : "even");
    FAPI_DBG("   syndrome_col: %u", o_err_data.syndrome_col);
    FAPI_DBG("   ra 46 to 57: 0x%X", o_err_data.real_address_46_57);

    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p10_l3err_extract...");
    return fapi2::current_err;
} // p10_l3err_extract
