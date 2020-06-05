/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_decoder_def.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file spd_decoder_def.H
/// @brief SPD decoder definition
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_DECODER_DEF_H_
#define _MSS_SPD_DECODER_DEF_H_

#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

///
/// @class decoder
/// @tparam D device type (DDR4, etc.)
/// @tparam S JEDEC SPD parameters (LRDIMM_MODULE, GEN_SEC, etc.)
/// @tparam R SPD revision (e.g. rev 1.1, 1.2, etc.)
/// @brief Base SPD DRAM decoder
///
template < device_type D, module_params S, rev R >
class decoder;

}// spd
}// mss

#endif //_MSS_SPD_DECODER_DEF_H_
