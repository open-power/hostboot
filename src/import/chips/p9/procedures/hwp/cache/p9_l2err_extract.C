/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l2err_extract.C $ */
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

///----------------------------------------------------------------------------
///
/// @file p9_l2err_extract.C
///
/// @brief Parse and extract error information from L2 trace array (FAPI)
///        See header file for additional comments
///
/// *HWP HWP Owner   : Chen Qian <qianqc@cn.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : PRDF
/// *HWP Level       : 3
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l2err_extract.H>
#include <p9_proc_gettracearray.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t P9_L2ERR_EXTRACT_ECC_PAT[73] =
{
    0xc4, 0x8c, 0x94, 0xd0, 0xf4, 0xb0, 0xa8, 0xe0,
    0x62, 0x46, 0x4a, 0x68, 0x7a, 0x58, 0x54, 0x70,
    0x31, 0x23, 0x25, 0x34, 0x3d, 0x2c, 0x2a, 0x38,
    0x98, 0x91, 0x92, 0x1a, 0x9e, 0x16, 0x15, 0x1c,
    0x4c, 0xc8, 0x49, 0x0d, 0x4f, 0x0b, 0x8a, 0x0e,
    0x26, 0x64, 0xa4, 0x86, 0xa7, 0x85, 0x45, 0x07,
    0x13, 0x32, 0x52, 0x43, 0xd3, 0xc2, 0xa2, 0x83,
    0x89, 0x19, 0x29, 0xa1, 0xe9, 0x61, 0x51, 0xc1,
    0xc7, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01
};

const uint8_t L2ERR_MAX_CYCLES_BACK = 5;
const uint8_t L2ERR_NUM_DWS = 8;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point
fapi2::ReturnCode p9_l2err_extract(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const fapi2::variable_buffer& i_ta_data,
    p9_l2err_extract_err_type i_err_type,
    p9_l2err_extract_err_data& o_err_data,
    bool& o_error_found)
{
    bool                    error_found = false;
    bool                    ce_ue = true; //ce or ue flag
    int32_t                 trace_index = 0;

    //the index into the trace entry that is N cycles before the fail
    uint32_t                indexes[L2ERR_MAX_CYCLES_BACK];
    fapi2::variable_buffer  trace_array[P9_TRACEARRAY_NUM_ROWS];
    uint8_t                 syndrome = 0;
    uint8_t                 dw = 0;
    uint32_t                ta_length = i_ta_data.getBitLength();
    uint32_t                exp_ta_length = P9_TRACEARRAY_NUM_ROWS *
                                            P9_TRACEARRAY_BITS_PER_ROW;
    bool                    back_of_2to1_nextcycle = false;
    uint8_t                 syndrome_col = 0;
    uint8_t                 addr48_55 = 0;
    uint8_t                 addr56_57 = 0;
    uint8_t                 addr48 = 0;
    uint8_t                 addr49 = 0;
    uint16_t                addr48_57 = 0;
    uint16_t                addr48_56 = 0;
    uint16_t                cgc = 0;
    uint32_t                addrBit2 = 0;
    fapi2::variable_buffer  address( 10 );
    uint8_t                 member = 0;
    uint8_t                 bank = 0;
    uint8_t                 ow_select = 0;
    bool                    found_dw = false;
    uint8_t                 macro = 0;
    uint8_t                 column = 0;
    uint8_t                 bitline = 0;
    bool                    is_top_sa = false;
    bool                    is_left_sa = false;
    bool                    odd_way = false;
    uint8_t                 way_bitline_offset = 0;
    uint32_t                physical_offset = 0;
    int32_t                 l_ce_trace_index = 0;
    uint32_t                indexes_index = 0;
    uint32_t                cycles = 0;


    // mark function entry
    FAPI_DBG("Entering p9_l2err_extract...");

    // check if the supplied data is the correct size, used mostly for
    // manual tool input
    FAPI_ASSERT(ta_length == exp_ta_length,
                fapi2::P9_L2ERR_EXTRACT_TA_WRONG_SIZE_ERR()
                .set_TARGET(i_target)
                .set_TA_DATA_SIZE(ta_length)
                .set_EXP_TA_DATA_SIZE(exp_ta_length),
                "Specified trace array length (%u) does not match expected length (%u)",
                ta_length, exp_ta_length);

    // build the indexable array and print out contents at the same time for debug
    for(uint8_t i = 0; i < P9_TRACEARRAY_NUM_ROWS; i++)
    {
        trace_array[i].resize(P9_TRACEARRAY_BITS_PER_ROW);
        FAPI_TRY(i_ta_data.extract(trace_array[i],
                                   P9_TRACEARRAY_BITS_PER_ROW * i,
                                   P9_TRACEARRAY_BITS_PER_ROW),
                 "buffer extract() call returns an error.");
        FAPI_DBG("%2X: 0x%016llX%016llX",
                 i, trace_array[i].get<uint64_t>( 0 ),
                 trace_array[i].get<uint64_t>( 1 ));
    }

    //********************************************************************//
    // L2 Trace (scom 0x10012000 & 0x10012001)                            //
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
    //     added to the repeat count of the previous data entry. Since we //
    //     only care about a 12 cycle window, we can ignore compression   //
    //     stamps, safe in the knowledge that the data entry itself will  //
    //     have a repeat count of more than 12 cycles.                    //
    //                                                                    //
    //    =============================================================== //
    //    |  Bits  |  Trace data format                                 | //
    //    |--------+----------------------------------------------------| //
    //    |   0:55 | Don't Care (debug data)                            | //
    //    |  56:63 | DW (Encoded, always 1 cycle back)                  | //
    //    |     64 | CE Occurred                                        | //
    //    |     65 | UE Occurred                                        | //
    //    |     66 | back_of_2to1 bit (Determines # cycles after read)  | //
    //    |  67:69 | Member (2 cycles back)                             | //
    //    |  70:71 | address 56:57 (56=bank, 4 cycles back)             | //
    //    |  72:79 | address 48:55 (4 cycles back)                      | //
    //    |  80:87 | Syndrome for lowesti # DW                          | //
    //    |  88:94 | LFSR (counts cycles)                               | //
    //    |     95 | Error (FIR bit has been set)                       | //
    //    |     96 | tied to 0                                          | //
    //    | 97:103 | Trace array address (auto-increments on scom read) | //
    //    |    104 | Which trace bank is valid in banked mode           | //
    //    |        |    0 = addresses 0-63 are valid                    | //
    //    |        |    1 = addresses 64-127 are valid                  | //
    //    |    105 | tied to 0                                          | //
    //    |106:111 | trace address when bank was switched in bank mode  | //
    //    |112:127 | tied to 0                                          | //
    //    =============================================================== //
    //                                                                    //
    //********************************************************************//

    // look for CE/UE
    error_found = false;
    trace_index = P9_TRACEARRAY_NUM_ROWS; // the last entry in the array is the newest
    FAPI_DBG("trace_index = %X", trace_index);

    while( !error_found && (trace_index > 0) )
    {
        trace_index--;

        if (p9_tracearray_is_trace_start_marker(trace_array[trace_index]) ==
            fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_DBG("Head found at trace index %i", trace_index);
            FAPI_DBG("%2X: 0x%016llX%016llX",
                     trace_index,
                     trace_array[trace_index].get<uint64_t>( 0 ),
                     trace_array[trace_index].get<uint64_t>( 1 ));
            error_found = false;
            ce_ue = true;
            break;
        }

        // Only look at data entries (ie ignore compression entries for now)
        if( !trace_array[trace_index].isBitClear( 88, 7 ) )
        {
            // Check for CE first if we are not explicitly looking for a UE
            if ( trace_array[trace_index].isBitSet(64) &&
                 !(i_err_type == L2ERR_UE) )
            {
                FAPI_DBG("Found CE at trace index %i", trace_index);
                FAPI_DBG("%2X: 0x%016llX%016llX",
                         trace_index,
                         trace_array[trace_index].get<uint64_t>( 0 ),
                         trace_array[trace_index].get<uint64_t>( 1 ));
                error_found = true;
                ce_ue = true;
                break;
            }

            // Check for UE second if we are not explicitly looking for a CE
            if ( trace_array[trace_index].isBitSet(65) &&
                 !(i_err_type == L2ERR_CE) )
            {
                FAPI_DBG("Found UE at trace index %i", trace_index);
                error_found = true;
                ce_ue = false;
                break;
            }
        }

    } //end loop looking for CE/UE

    FAPI_DBG("Found UE or CE: error_found = %i", error_found);
    o_error_found = error_found;

    // Return if error not found.
    if (!error_found)
    {
        FAPI_DBG("No error is found!");
        return fapi2::current_err;
    }

    // Generate compression indexes, we will use these to look back for data
    l_ce_trace_index = trace_index;

    while( (indexes_index < L2ERR_MAX_CYCLES_BACK) &&
           (l_ce_trace_index >= 0) )
    {
        FAPI_TRY(trace_array[l_ce_trace_index].extractToRight( cycles, 88, 7 ), //LFSR
                 "buffer extractToRight() call returns an error.");

        if( cycles != 0 )
        {
            //This is a data entry with LFSR data
            //convert LFSR to cycle count
            switch( cycles )
            {
                case 0x7F:
                    cycles = 1;
                    break;

                case 0x3F:
                    cycles = 2;
                    break;

                case 0x5F:
                    cycles = 3;
                    break;

                case 0x2F:
                    cycles = 4;
                    break;

                case 0x57:
                    cycles = 5;
                    break;

                // Only need to find a total of 4 cycles, so anything not above works
                default:
                    cycles = 5;
                    break;
            }

            FAPI_DBG("cycles = %x", cycles);

            // Put "trace_index" into "indexes" up to "cycles" number of times
            for( ; (cycles > 0) && (indexes_index < L2ERR_MAX_CYCLES_BACK);
                 cycles-- )
            {
                indexes[indexes_index] = l_ce_trace_index;
                indexes_index++;
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


    for ( int8_t i = L2ERR_MAX_CYCLES_BACK - 1; i >= 0; i--)
    {
        FAPI_DBG("uncomp %i cycles back: 0x%016llX%016llX",
                 i, trace_array[indexes[i]].get<uint64_t>( 0 ),
                 trace_array[indexes[i]].get<uint64_t>( 1 ));
    }

    // Find what cycle the CE occured on and calculate location of DW data
    // p9 updated find the next cycle of back_of_2to1 CE/UE trigger
    back_of_2to1_nextcycle = trace_array[trace_index + 1].isBitSet( 66 );

    //Get syndrome which is the cycle after the CE
    FAPI_TRY(trace_array[ trace_index + 1 ].extractToRight( syndrome,  80,  8 ),
             "extractToRight() Syndrome data call returns an error.");




    FAPI_ASSERT(!(ce_ue && (syndrome == 0)),
                fapi2::P9_L2ERR_EXTRACT_SYNDROME_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_1(trace_array[ trace_index + 1 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_2(trace_array[ trace_index + 1 ].get<uint64_t>( 1 ))
                .set_TRACE_ARRAY_3(trace_array[ trace_index + 2 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_4(trace_array[ trace_index + 2 ].get<uint64_t>( 1 )),
                "Error: could not find syndrome. Trace cycle CE+1= 0x%016llX%016llX; "
                "Trace cycle CE+2=%016llX%016llX",
                trace_array[ trace_index + 1 ].get<uint64_t>( 0 ),
                trace_array[ trace_index + 1 ].get<uint64_t>( 1 ),
                trace_array[ trace_index + 2 ].get<uint64_t>( 0 ),
                trace_array[ trace_index + 2 ].get<uint64_t>( 1 ));

    FAPI_DBG("Found syndrome: %2X", syndrome);

    // Look up column from syndrome
    if ( ce_ue )
    {
        // Decodes the specified syndrome into a column offset
        bool found = false;

        // Use the ECC lookup to find what column the error occured
        for( uint8_t i = 0;
             i < (uint8_t)(sizeof(P9_L2ERR_EXTRACT_ECC_PAT) / sizeof(uint8_t));
             i++)
        {
            if( syndrome == P9_L2ERR_EXTRACT_ECC_PAT[i] )
            {
                syndrome_col = i;
                found = true;
                break;
            }
        }

        FAPI_ASSERT(found,
                    fapi2::P9_L2ERR_EXTRACT_UNKNOWN_SYNDROME_ECC()
                    .set_TARGET(i_target)
                    .set_SYNDROME(syndrome),
                    "Syndrome ECC is unknown. %2X", syndrome);

        FAPI_DBG("syndrome_col = %u", syndrome_col);
    }
    else
    {
        syndrome_col = 0;
    }

    // Get member and address data
    FAPI_TRY(trace_array[ indexes[ 2 ]].extractToRight( member, 67, 3 ),      // 2 cycles back
             "extractToRight() - Member returns an error.");
    FAPI_TRY(trace_array[ indexes[ 4 ]].extractToRight( addr48_55,  72,  8 ), // 4 cycles back
             "extractToRight() - addr48_55 returns an error.");
    FAPI_TRY(trace_array[ indexes[ 4 ]].extractToRight( addr56_57, 70, 2 ),   // 4 cycles back
             "extractToRight() - addr56_57 returns an error.");

    FAPI_TRY(address.insertFromRight( addr48_55, 0, 8 ),
             "insertFromRight() - addr48_55 returns an error.");
    FAPI_TRY(address.insertFromRight( addr56_57, 8, 2 ),
             "insertFromRight() - addr56_57 returns an error.");
    FAPI_TRY(address.extractToRight( addr48_57, 0, 10 ),
             "extractToRight() - addr48_57 returns an error.");
    FAPI_TRY(address.extractToRight( addr48_56, 0, 9 ),
             "extractToRight() - addr48_56 returns an error.");

    // extract bank, cgc, addrBit2 from the address value
    bank = addr56_57 / 2;
    cgc = addr48_55;
    addrBit2 = ( cgc & 0x20) >> 5;

    FAPI_DBG("Found member: %i", member);
    FAPI_DBG("addr48_55=%X, addr56_57=%X, address48_57=%X", addr48_55, addr56_57, addr48_57);
    FAPI_DBG("bank = %i", bank);

    // calculate ow_select, determines which beat the error occurred on, first(0) or second(1)

    // then error occurred on second beat, otherwise first beat
    // ow_select is determined by next cycle back_of_2to1
    if(!back_of_2to1_nextcycle)
    {
        ow_select = !(addr56_57 % 2);
    }
    else
    {
        ow_select = (addr56_57 % 2);
    }

    FAPI_DBG("addr56_57=%u", addr56_57);

    //find DW
    for( dw = 0; dw < L2ERR_NUM_DWS; dw++ )
    {
        if((trace_array[ indexes[ 1 ] ].isBitSet( (56 + dw))))
        {
            found_dw = true;
            break;
        }
    }

    FAPI_ASSERT(found_dw,
                fapi2::P9_L2ERR_EXTRACT_DW_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_1(trace_array[ indexes[ 1 ] ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_2(trace_array[ indexes[ 1 ] ].get<uint64_t>( 1 )),
                "Error: could not find DW.\nTrace cycle CE 1 cycle back = 0x%016llX%016llX",
                trace_array[ indexes[ 1 ] ].get<uint64_t>( 0 ),
                trace_array[ indexes[ 1 ] ].get<uint64_t>( 1 ));

    FAPI_DBG("Found DW=%i", dw);

    //calculate macro
    if( syndrome_col <= 23 )
    {
        macro = 0;
    }
    else if( syndrome_col <= 47)
    {
        macro = 1;
    }
    else
    {
        macro = 2;
    }

    //calculate macro-specific column
    column = syndrome_col - ( macro * 24 );

    //calculate top/bottom subarray
    addr48 = addr48_57 >> 9; //bit 48, cgc0-127 is top, cgc128-255 is bottom
    addr49 = (addr48_57) >> 8 & 0x01;
    FAPI_DBG("addr49 = %u", addr49);
    FAPI_DBG("addr48 = %u", addr48);

    // The submacros are named top_left, top_right, bottom_left, and bottom_right. A directory entry is spread across a left/right pair.
    // The top macros include congruence classes 0-127, the bottom include 128-255.
    // Parse addr48_49 to get the top/bottom, right/left information
    // Top_left = 0x00, top_right = 0x01, bottom_left = 0x10, bottom_right = 0x11. First bit is top/bottom, last bit is left/right
    if( addr48 == 0 )
    {
        is_top_sa = true;
    }
    else
    {
        is_top_sa = false;
    }

    if( addr49 == 0 )
    {
        is_left_sa = true;
    }
    else
    {
        is_left_sa = false;
    }

    FAPI_DBG("L2 fail is from %s macro.", (is_top_sa) ? "top" : "bottom");

    // calculate bitline
    physical_offset = 2 +   4 * ( ow_select  % 2) +   addrBit2    +   ((member & 0x1) << 1);
    bitline =   physical_offset + 8 * column;

    FAPI_DBG("addrBit2=%u", addrBit2);
    FAPI_DBG("physical_offset=%u", physical_offset);
    FAPI_DBG("cgc=%u", cgc);
    FAPI_DBG("odd_way=%u", odd_way);
    FAPI_DBG("member=%u", member);
    FAPI_DBG("ow_select=%u", ow_select);
    FAPI_DBG("way_bitline_offset=%u", way_bitline_offset);
    FAPI_DBG("column=%u", column);
    FAPI_DBG("Found bitline=%u", bitline);
    FAPI_DBG("ce_ue value = %u", ce_ue);

    // print out error location information
    if( ce_ue )
    {
        FAPI_DBG("CE Location Information");
    }
    else
    {
        FAPI_DBG("UE Location Information");
    }

    FAPI_DBG("\tDW     = %u", dw);
    FAPI_DBG("\tBank   = %u", bank);
    FAPI_DBG("\tMember = %u", member);
    FAPI_DBG("\tMacro  = %u", macro);
    FAPI_DBG("\tOW_Sel = %u", ow_select);
    FAPI_DBG("\tTop SA = %s", is_top_sa ? "true" : "false");
    FAPI_DBG("\tLeft SA = %s", is_left_sa ? "true" : "false");
    FAPI_DBG("\tAddress = 0x%X", addr48_55);
    FAPI_DBG("\tBitline = %u", bitline);
    o_err_data.ce_ue = ce_ue ? L2ERR_CE : L2ERR_UE;
    o_err_data.member = member;
    o_err_data.dw = dw;
    o_err_data.macro = macro;
    o_err_data.bank = bank;
    o_err_data.ow_select = ow_select;
    o_err_data.is_top_sa = is_top_sa;
    o_err_data.is_left_sa = is_left_sa;
    o_err_data.bitline = bitline;
    o_err_data.address = addr48_55;


    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p9_l2err_extract...");
    return fapi2::current_err;
} // p9_l2err_extract
