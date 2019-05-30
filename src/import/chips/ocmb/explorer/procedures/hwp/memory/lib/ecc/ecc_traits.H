/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/ecc_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file ecc_traits_explorer.H
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_TRAITS_EXPLORER_H_
#define _MSS_ECC_TRAITS_EXPLORER_H_

#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>


namespace mss
{

///
/// @class eccTraits
/// @brief a collection of traits associated with the MC ECC interface
/// @tparam T fapi2::TargetType representing the memory controller
///
template< fapi2::TargetType T >
class eccTraits;

///
/// @class eccTraits
/// @brief a collection of traits associated with the OCMB explorer MC ECC interface
///
// TODO: Need to implement this
template<>
class eccTraits<fapi2::TARGET_TYPE_MEM_PORT>
{

    public:
        // Fields, can be any size.
        enum
        {
            FIRMWARE_MS_ADDRESS = EXPLR_RDF_FWMS0_ADDRESS,
            FIRMWARE_MS_ADDRESS_LEN = EXPLR_RDF_FWMS0_ADDRESS_LEN,

            // Address trap format
            TRAP_ADDRESS_PORT = 0,
            TRAP_ADDRESS_PORT_LEN = 0,
            TRAP_ADDRESS_DIMM = 1,
            TRAP_ADDRESS_DIMM_LEN = 1,
            TRAP_ADDRESS_MRANK = 2,
            TRAP_ADDRESS_MRANK_LEN = 2,
            TRAP_ADDRESS_SRANK = 4,
            TRAP_ADDRESS_SRANK_LEN = 3,
            TRAP_ADDRESS_ROW = 7,
            TRAP_ADDRESS_ROW_LEN = 18,
            TRAP_ADDRESS_COL = 25,
            // MCBIST address only need col(3 to 9) although address trap can provide col(2 to 9)
            TRAP_ADDRESS_COL_LEN = 7,
            TRAP_ADDRESS_BANK = 33,
            TRAP_ADDRESS_BANK_LEN = 3,
            TRAP_ADDRESS_BANK_GROUP = 36,
            TRAP_ADDRESS_BANK_GROUP_LEN = 2,

            TRAP_ADDRESS = 0,
            TRAP_ADDRESS_LEN = 38,
        };
};

} // close namespace mss

#endif
