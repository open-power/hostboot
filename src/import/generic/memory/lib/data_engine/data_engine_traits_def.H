/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_traits_def.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file data_engine_traits_def.H
/// @brief Class to set preliminary eff_config attributes
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_DATA_ENGINE_TRAITS_DEF_H_
#define _MSS_DATA_ENGINE_TRAITS_DEF_H_

#include <cstring>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits
/// @tparam MC the memory controller type
///
template< mss::mc_type MC >
class dimmPosTraits;

///
/// @brief Forward declartion of traits for attrEngineTraits
/// @class attrEngineTraits
/// @tparam P processor type (e.g. Nimbus, Axone, etc.)
/// @tparam ET enum type
/// @tparam T enum value
///
template < proc_type P, typename ET, ET T = ET::DISPATCHER>
struct attrEngineTraits;

namespace gen
{
///
/// @brief Template recursive algorithm for setting attrs
/// @class attr_engine
/// @tparam P processor type (e.g. Nimbus, Axone, etc.)
/// @tparam ET enum type - conceptually a list of attrs to set
/// @tparam F enum value - the specific attr value from ET to set
/// @tparam TT associated traits for attr_engine
/// @tparam B dispatch tag - defaulted to false
///
template < proc_type P,
           typename ET,
           ET F = ET::DISPATCHER,
           typename TT = attrEngineTraits<P, ET, F>,
           bool B = false>
struct attr_engine;
}// gen
}// mss

#endif
