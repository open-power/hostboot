/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_dyninit_bitvec.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file  p10_dyninit_bitvec.H
/// @brief Structures/enums for p10 dynamic init management
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer   : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#ifndef _P10_DYNINIT_BITVEC_H_
#define _P10_DYNINIT_BITVEC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_ipl_image.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

///
/// @enum p10_dyninit_bitvec_source
///
/// @brief Documents origin of bit vector content
///
enum p10_dyninit_bitvec_source
{
    HW_IMAGE = 0,    ///< HW image provided information only
    PLAT = 1,        ///< Platform provided information only
    MERGED = 2,      ///< Combined view of HW image + platform information
};

///
/// @enum p10_dyninit_bitvec_source
///
/// @brief Documents type of bit vector content
///
enum p10_dyninit_bitvec_type
{
    MODE = P9_XIP_SECTION_HW_DYN_SERV,     ///< Dynamic init mode/services
    FEATURE = P9_XIP_SECTION_HW_DYN_FEAT,  ///< Dynamic init features
};

///
/// @struct p10_dyninit_bitvec
///
/// @brief This structure encapsulates a variable size bit vector used
///        in the management of dynamic init modes and features
///
struct p10_dyninit_bitvec
{
    std::vector<uint64_t> iv_bits;        //< variable sized bit vector
    uint16_t iv_bit_count;                //< precise bit count
    p10_dyninit_bitvec_source iv_source;  //< source
    p10_dyninit_bitvec_type iv_type;      //< type
};

#endif // _P10_DYNINIT_BITVEC_H_
