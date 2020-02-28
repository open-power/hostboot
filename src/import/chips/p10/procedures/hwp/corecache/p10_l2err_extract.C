/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l2err_extract.C $ */
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
/// @file p10_l2err_extract.C
///
/// @brief Parse and extract error information from L2 trace array (FAPI)
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_l2err_extract.H>
#include <p10_proc_gettracearray.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t P10_L2ERR_EXTRACT_ECC_PAT[73] =
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
fapi2::ReturnCode p10_l2err_extract(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const fapi2::variable_buffer& i_ta_data,
    p10_l2err_extract_err_type i_err_type,
    p10_l2err_extract_err_data& o_err_data,
    bool& o_error_found)
{
    bool                    l_error_found = false;
    bool                    l_ce_ue = true; //ce or ue flag
    int32_t                 l_trace_index = 0;

    //the index into the trace entry that is N cycles before the fail
    uint32_t                l_indexes[L2ERR_MAX_CYCLES_BACK];
    fapi2::variable_buffer  l_trace_array[P10_TRACEARRAY_NUM_ROWS];
    uint8_t                 l_syndrome = 0;
    uint8_t                 l_dw = 0;
    uint32_t                l_ta_length = i_ta_data.getBitLength();
    uint32_t                l_exp_ta_length = P10_TRACEARRAY_NUM_ROWS *
            P10_TRACEARRAY_BITS_PER_ROW;
    bool                    l_back_of_2to1_nextcycle = false;
    uint8_t                 l_syndrome_col = 0;
    uint8_t                 l_addr47_54 = 0;
    uint8_t                 l_addr55_56 = 0;
    uint16_t                l_addr47_56 = 0;
    fapi2::variable_buffer  l_address( 10 );
    uint8_t                 l_member = 0;
    uint8_t                 l_bank = 0;
    bool                    l_found_dw = false;
    int32_t                 l_ce_trace_index = 0;
    uint32_t                l_indexes_index = 0;
    uint32_t                l_cycles = 0;


    // mark function entry
    FAPI_DBG("Entering p10_l2err_extract...");

    // check if the supplied data is the correct size, used mostly for
    // manual tool input
    FAPI_ASSERT(l_ta_length == l_exp_ta_length,
                fapi2::P10_L2ERR_EXTRACT_TA_WRONG_SIZE_ERR()
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
    // L2 Trace                                                           //
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
    //    |  70:71 | address 55:56 (56=bank, 4 cycles back)             | //
    //    |  72:79 | address 47:54 (4 cycles back)                      | //
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
    l_error_found = false;
    l_trace_index = P10_TRACEARRAY_NUM_ROWS; // the last entry in the array is the newest
    FAPI_DBG("l_trace_index = %X", l_trace_index);

    while( !l_error_found && (l_trace_index > 0) )
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
            l_error_found = false;
            l_ce_ue = true;
            break;
        }

        // Only look at data entries (ie ignore compression entries for now)
        if( !l_trace_array[l_trace_index].isBitClear( 88, 7 ) )
        {
            // Check for CE first if we are not explicitly looking for a UE
            if ( l_trace_array[l_trace_index].isBitSet(64) &&
                 !(i_err_type == L2ERR_UE) )
            {
                FAPI_DBG("Found CE at trace index %i", l_trace_index);
                FAPI_DBG("%2X: 0x%016llX%016llX",
                         l_trace_index,
                         l_trace_array[l_trace_index].get<uint64_t>( 0 ),
                         l_trace_array[l_trace_index].get<uint64_t>( 1 ));
                l_error_found = true;
                l_ce_ue = true;
                break;
            }

            // Check for UE second if we are not explicitly looking for a CE
            if ( l_trace_array[l_trace_index].isBitSet(65) &&
                 !(i_err_type == L2ERR_CE) )
            {
                FAPI_DBG("Found UE at trace index %i", l_trace_index);
                l_error_found = true;
                l_ce_ue = false;
                break;
            }
        }

    } //end loop looking for CE/UE

    FAPI_DBG("Found UE or CE: l_error_found = %i", l_error_found);
    o_error_found = l_error_found;

    // Return if error not found.
    if (!l_error_found)
    {
        FAPI_DBG("No error is found!");
        return fapi2::current_err;
    }

    // Generate compression indexes, we will use these to look back for data
    l_ce_trace_index = l_trace_index;

    while( (l_indexes_index < L2ERR_MAX_CYCLES_BACK) &&
           (l_ce_trace_index >= 0) )
    {
        FAPI_TRY(l_trace_array[l_ce_trace_index].extractToRight( l_cycles, 88, 7 ), //LFSR
                 "buffer extractToRight() call returns an error.");

        if( l_cycles != 0 )
        {
            //This is a data entry with LFSR data
            //convert LFSR to cycle count
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

                // Only need to find a total of 4 cycles, so anything not above works
                default:
                    l_cycles = 5;
                    break;
            }

            FAPI_DBG("cycles = %x", l_cycles);

            // Put "l_trace_index" into "l_indexes" up to "cycles" number of times
            for( ; (l_cycles > 0) && (l_indexes_index < L2ERR_MAX_CYCLES_BACK);
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


    for ( int8_t i = L2ERR_MAX_CYCLES_BACK - 1; i >= 0; i--)
    {
        FAPI_DBG("uncomp %i cycles back: 0x%016llX%016llX",
                 i, l_trace_array[l_indexes[i]].get<uint64_t>( 0 ),
                 l_trace_array[l_indexes[i]].get<uint64_t>( 1 ));
    }

    // Find what cycle the CE occured on and calculate location of DW data
    l_back_of_2to1_nextcycle = l_trace_array[l_trace_index + 1].isBitSet( 66 );

    //Get syndrome which is the cycle after the CE
    FAPI_TRY(l_trace_array[ l_trace_index + 1 ].extractToRight( l_syndrome,  80,  8 ),
             "extractToRight() Syndrome data call returns an error.");

    FAPI_ASSERT(!(l_ce_ue && (l_syndrome == 0)),
                fapi2::P10_L2ERR_EXTRACT_SYNDROME_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_1(l_trace_array[ l_trace_index + 1 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_2(l_trace_array[ l_trace_index + 1 ].get<uint64_t>( 1 ))
                .set_TRACE_ARRAY_3(l_trace_array[ l_trace_index + 2 ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_4(l_trace_array[ l_trace_index + 2 ].get<uint64_t>( 1 )),
                "Error: could not find syndrome. Trace cycle CE+1= 0x%016llX%016llX; "
                "Trace cycle CE+2=%016llX%016llX",
                l_trace_array[ l_trace_index + 1 ].get<uint64_t>( 0 ),
                l_trace_array[ l_trace_index + 1 ].get<uint64_t>( 1 ),
                l_trace_array[ l_trace_index + 2 ].get<uint64_t>( 0 ),
                l_trace_array[ l_trace_index + 2 ].get<uint64_t>( 1 ));

    FAPI_DBG("Found syndrome: %2X", l_syndrome);

    // Look up column from syndrome
    if ( l_ce_ue )
    {
        // Decodes the specified syndrome into a column offset
        bool found = false;

        // Use the ECC lookup to find what column the error occured
        for( uint8_t i = 0;
             i < (uint8_t)(sizeof(P10_L2ERR_EXTRACT_ECC_PAT) / sizeof(uint8_t));
             i++)
        {
            if( l_syndrome == P10_L2ERR_EXTRACT_ECC_PAT[i] )
            {
                l_syndrome_col = i;
                found = true;
                break;
            }
        }

        FAPI_ASSERT(found,
                    fapi2::P10_L2ERR_EXTRACT_UNKNOWN_SYNDROME_ECC()
                    .set_TARGET(i_target)
                    .set_SYNDROME(l_syndrome),
                    "Syndrome ECC is unknown. %2X", l_syndrome);

        FAPI_DBG("syndrome_col = %u", l_syndrome_col);
    }
    else
    {
        l_syndrome_col = 0;
    }

    // Get member and address data
    FAPI_TRY(l_trace_array[ l_indexes[ 2 ]].extractToRight( l_member, 67, 3 ),      // 2 cycles back
             "extractToRight() - Member returns an error.");
    FAPI_TRY(l_trace_array[ l_indexes[ 4 ]].extractToRight( l_addr47_54,  72,  8 ), // 4 cycles back
             "extractToRight() - addr48_55 returns an error.");
    FAPI_TRY(l_trace_array[ l_indexes[ 4 ]].extractToRight( l_addr55_56, 70, 2 ),   // 4 cycles back
             "extractToRight() - addr56_57 returns an error.");

    FAPI_TRY(l_address.insertFromRight( l_addr47_54, 0, 8 ),
             "insertFromRight() - addr47_54 returns an error.");
    FAPI_TRY(l_address.insertFromRight( l_addr55_56, 8, 2 ),
             "insertFromRight() - addr55_56 returns an error.");
    FAPI_TRY(l_address.extractToRight( l_addr47_56, 0, 10 ),
             "extractToRight() - addr47_56 returns an error.");

    // extract bank
    l_bank = l_addr47_56 & 0x7;

    FAPI_DBG("Found member: %i", l_member);
    FAPI_DBG("addr47_54=%X, addr55_56=%X, l_address47_56=%X", l_addr47_54, l_addr55_56, l_addr47_56);
    FAPI_DBG("bank = %i", l_bank);

    //find DW
    for( l_dw = 0; l_dw < L2ERR_NUM_DWS; l_dw++ )
    {
        if((l_trace_array[ l_indexes[ 1 ] ].isBitSet( (56 + l_dw))))
        {
            l_found_dw = true;
            break;
        }
    }

    FAPI_ASSERT(l_found_dw,
                fapi2::P10_L2ERR_EXTRACT_DW_NOT_FOUND()
                .set_TARGET(i_target)
                .set_TRACE_ARRAY_1(l_trace_array[ l_indexes[ 1 ] ].get<uint64_t>( 0 ))
                .set_TRACE_ARRAY_2(l_trace_array[ l_indexes[ 1 ] ].get<uint64_t>( 1 )),
                "Error: could not find DW.\nTrace cycle CE 1 cycle back = 0x%016llX%016llX",
                l_trace_array[ l_indexes[ 1 ] ].get<uint64_t>( 0 ),
                l_trace_array[ l_indexes[ 1 ] ].get<uint64_t>( 1 ));

    FAPI_DBG("Found DW=%i", l_dw);

    // print out error location information
    if( l_ce_ue )
    {
        FAPI_DBG("CE Location Information");
    }
    else
    {
        FAPI_DBG("UE Location Information");
    }

    FAPI_DBG("\tMember   = %u", l_member);
    FAPI_DBG("\tDW       = %u", l_dw);
    FAPI_DBG("\tBank     = %u", l_bank);
    FAPI_DBG("\tBack2to1 = %s", l_back_of_2to1_nextcycle ? "true" : "false");
    FAPI_DBG("\tSyndrome_col = %u", l_syndrome_col);
    FAPI_DBG("\tAddress   = 0x%X", l_addr47_56);

    o_err_data.ce_ue = l_ce_ue ? L2ERR_CE : L2ERR_UE;
    o_err_data.member = l_member;
    o_err_data.dw = l_dw;
    o_err_data.bank = l_bank;
    o_err_data.back_of_2to1_nextcycle = l_back_of_2to1_nextcycle;
    o_err_data.syndrome_col = l_syndrome_col;
    o_err_data.real_address_47_56 = l_addr47_56;

    // mark HWP exit
fapi_try_exit:
    FAPI_INF("Exiting p10_l2err_extract...");
    return fapi2::current_err;
} // p10_l2err_extract
