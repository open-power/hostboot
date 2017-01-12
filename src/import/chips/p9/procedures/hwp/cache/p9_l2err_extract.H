/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l2err_extract.H $ */
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
//------------------------------------------------------------------------------
// *|
// *! TITLE       : p9_l2err_extract.H
// *! DESCRIPTION : Parse and extract error information from L2 trace array (FAPI)
// *!
// *! OWNER NAME  : Chen Qian           Email: qianqc@cn.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
// *! Parses the contents of the L2_T0 trace array for L2 error data.
// *! Will look for occurances of an L2 CE or UE and capture associated data.
// *!
// *! Assume that the L2 trace array is set up to capture CEs/UEs, and
// *! that it is NOT running in banked mode. Also trace must have been set to
// *! stop on error.
// *|
// *! NOTE: Trace entries must be provided within data buffer from oldest->youngest entry.
// *!
// *! NOTE: This procedure only looks for the oldest error in the trace array. Other
// *! errors can be present in the first or second beat of data, or for datawords
// *! greater than the one with the first error.
//------------------------------------------------------------------------------

#ifndef _P9_L2ERR_EXTRACT_H_
#define _P9_L2ERR_EXTRACT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// enum used to denote what type of error occured or which we want to find
enum p9_l2err_extract_err_type
{
    L2ERR_CE,
    L2ERR_UE,
    L2ERR_CE_UE
};

// structure to document control/data registers for each supported trace array
struct p9_l2err_extract_err_data
{
    p9_l2err_extract_err_type       ce_ue;
    uint8_t                         member;  //3-bit
    uint8_t                         dw;      //3-bit
    uint8_t                         macro;   //2-bit d0-d2
    uint8_t                         bank;    //1-bit
    uint8_t                         ow_select;//1-bit
    uint8_t                         bitline; //decimal 0-99
    bool                            is_top_sa; //top or bottom subarray
    bool                            is_left_sa; //left or right subarray
    uint16_t                        address;//10 bits addr48_57
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_l2err_extract_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_EX>&,
                          const fapi2::variable_buffer&,
                          p9_l2err_extract_err_type,
                          p9_l2err_extract_err_data&,
                          bool&);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

// function: FAPI2 p9_l2err_extract HWP entry point
//           Parse and extract L2 error information from provided
//           L2_T0 trace array that has been stopped on an L2 CE or UE.
// parameters: i_target      => chiplet target for callouts
//             i_ta_data     => ecmdDataBufferBase that contains the trace data
//             i_err_type    => type of error that is to be extracted (CE,UE,both)
//             o_err_data    => failing location information for CE or UE
//             o_error_found => error is found

    fapi2::ReturnCode p9_l2err_extract(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                       const fapi2::variable_buffer& i_ta_data,
                                       p9_l2err_extract_err_type i_err_type,
                                       p9_l2err_extract_err_data& o_err_data,
                                       bool& o_error_found);

} // extern "C"

#endif // _P9_L2ERR_EXTRACT_H_

