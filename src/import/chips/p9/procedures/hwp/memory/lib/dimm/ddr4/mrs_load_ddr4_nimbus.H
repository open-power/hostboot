/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4_nimbus.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file mrs_load_ddr4_nimbus.H
/// @brief Code to support mrs_load_ddr4_nimbus
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_DDR4_NIMBUS_H_
#define _MSS_MRS_LOAD_DDR4_NIMBUS_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>

namespace mss
{

namespace ddr4
{

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Perform the mrs_load DDR4 operations for nvdimm restore - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load_nvdimm( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   std::vector< ccs::instruction_t >& io_inst);

} // ddr4
} // mss
#endif
