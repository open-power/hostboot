/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_get_cen_ecid.H $ */
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
/// @file p9c_mss_get_cen_ecid.H
/// @brief HWP for decoding ECID
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup:
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
//////
#ifndef _MSS_GET_CEN_ECID_H_
#define _MSS_GET_CEN_ECID_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <cen_scom_addresses.H>

//defines enumerators
enum mss_get_cen_ecid_ddr_status
{
    MSS_GET_CEN_ECID_DDR_STATUS_ALL_GOOD = 0,
    MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD = 1,
    MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD = 2,
    MSS_GET_CEN_ECID_DDR_STATUS_ALL_BAD = 3,
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
class  ecid_user_struct
{
    public:
        uint8_t  valid;
        uint8_t  i_checkL4CacheEnableUnknown;
        uint8_t  i_ecidContainsPortLogicBadIndication;
        uint8_t  i_bluewaterfall_nwell_broken;
        uint8_t  i_user_defined;
        uint8_t  io_ec;
        uint64_t io_ecid[2];
        uint8_t  o_psro;
        uint8_t  o_bluewaterfall_broken;
        uint8_t  o_nwell_misplacement;

        ecid_user_struct();
};

inline   ecid_user_struct::ecid_user_struct()
{
    valid = 0;
    i_checkL4CacheEnableUnknown = 0;
    i_ecidContainsPortLogicBadIndication = 0;
    i_user_defined = 0;
    io_ec = 0;
    io_ecid[0] = 0;
    io_ecid[1] = 0;
}


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9c_mss_get_cen_ecid_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target, uint8_t& o_ddr_port_status,
                             uint8_t& o_cache_enable,      uint8_t& o_centaur_sub_revision, ecid_user_struct& user_data

                            );


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: FAPI mss_get_cen_ecid HWP entry point
// parameters: i_target => cen chip target
//             &o_ddr_port_status => indicates if the MBA's are bad, with MBA 1 being the rightmost bit and MBA 0 being the next to right most bit
//             &o_cache_enable => what it would have set the cache enable attribute to if it sets attributes
//             &o_centaur_sub_revision => the sub revision indicator between DD1.0 and DD1.01
// returns: FAPI_RC_SUCCESS if FBC stop is deasserted at end of execution
//          else FAPI return code for failing operation
// Updates attributes: ATTR_ECID[2] -> bits 1-64 and 65-128 of the ECID
//                     ATTR_MSS_PSRO -> average PSRO from 85C wafer test
//                     ATTR_MSS_NWELL_MISPLACEMENT -> indicates if nwell defect in hardware
    fapi2::ReturnCode p9c_mss_get_cen_ecid(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        uint8_t& o_ddr_port_status,
        uint8_t& o_cache_enable,
        uint8_t& o_centaur_sub_revision,
        ecid_user_struct& user_data

    );

    fapi2::ReturnCode mss_parse_ecid(
        uint64_t ecid[2], // input ECID in bit order
        const uint8_t l_checkL4CacheEnableUnknown, // input L4CacheEnableUnknown is possible
        const uint8_t l_ecidContainsPortLogicBadIndication, // input logic can be bad
        const uint8_t
        l_bluewaterfall_nwell_broken, // adjustments possibly needed for bluewaterfall and transistor misplaced in the nwell
        uint8_t& ddr_port,  //output ddr ports are non functional
        uint8_t& cache_enable_o,  // output cache is functional or not
        uint8_t& centaur_sub_revision_o,  // output sub revsion number
        uint8_t& o_psro,  // output psro
        uint8_t& o_bluewaterfall_broken,  // output blue waterfall broken
        uint8_t& o_nwell_misplacement    // output nwell misplacement
    );



} // extern "C"

#endif // _MSS_GET_CEN_ECID_H_
