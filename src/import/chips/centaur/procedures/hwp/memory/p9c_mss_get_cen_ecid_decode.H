/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_get_cen_ecid_decode.H $ */
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
// Version:|  Author: |  Date:  | Comment:
///
/// @file p9c_mss_get_cen_ecid_decode.H
/// @brief HWP for decoding ecid
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup:
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
//////
#ifndef _MSS_GET_CEN_ECID_DECODE_H_
#define _MSS_GET_CEN_ECID_DECODE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9c_mss_get_cen_ecid.H>



// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9c_mss_get_cen_ecid_decode_FP_t)(uint8_t& i_ddr_port_status, uint8_t& i_cache_enable,
                                    uint8_t& i_centaur_sub_revision, ecid_user_struct& i_user_data, char* o_display_string
                                   );

const int MSS_GET_CEN_ECID_DECODE_STRING_LENGTH = 1000;

//void decode_base_code(uint64_t ecid[2], uint8_t ddr_port, uint8_t cache_enable_o, uint8_t centaur_sub_revision_o, uint8_t o_nwell_misplacement, uint8_t o_bluewaterfall_broken, uint8_t user_defined, uint8_t psro, uint8_t i_ec );
//ReturnCode get_ecid_char(uint8_t c, char *creturn);
//void get_ecid_checksum(char ECID[12]);

enum user_flags
{
    USER_INPUT_ECID = 1,
    CSV = 2,
    COMMENT = 4,
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI mss_get_cen_ecid_decode HWP entry point
// parameters:
//             &o_ddr_port_status => indicates if the MBA's are bad, with MBA 1 being the rightmost bit and MBA 0 being the next to right most bit
//             &o_cache_enable => what it would have set the cache enable attribute to if it sets attributes
//             &o_centaur_sub_revision => the sub revision indicator between DD1.0 and DD1.01
//             &o_user_data => holder for additional information for printing
//             &o_display_string -> output string- max of MSS_GET_CEN_ECID_DECODE_STRING_LENGTH length
// returns: FAPI_RC_SUCCESS if FBC stop is deasserted at end of execution
//          else FAPI return code for failing operation
    fapi2::ReturnCode p9c_mss_get_cen_ecid_decode(
        uint8_t& i_ddr_port_status,
        uint8_t& i_cache_enable,
        uint8_t& i_centaur_sub_revision,
        ecid_user_struct& i_user_data,
        char* o_display_string

    );
    fapi2::ReturnCode get_ecid_char(uint8_t c, char* creturn); // print helping function
    void get_ecid_checksum(char ECID[13]);

} // extern "C"

#endif // _MSS_GET_CEN_ECID_DECODE_H_
