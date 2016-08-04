/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file adr.H
/// @brief Subroutines for the PHY ADR registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ADR_H_
#define _MSS_ADR_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class adrTraits
/// @brief a collection of traits associated with the PHY ADR interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class adrTraits;

///
/// @class adrTraits
/// @brief a collection of traits associated with the Centaur PHY ADR interface
///
template<>
class adrTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class adrTraits
/// @brief a collection of traits associated with the Nimbus PHY ADR
///
template<>
class adrTraits<fapi2::TARGET_TYPE_MCA>
{
    public:

        enum
        {
            // Each register has two fields. One for the even lane and one for the odd lane.
            ADR_DELAY_EVEN = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01,
            ADR_DELAY_ODD = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01_DELAY1,
            ADR_DELAY_LEN = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01_DELAY1_LEN,
        };

};

///
/// @brief A structure to represent an adr operation
///
struct adr_data
{
    // The register
    uint64_t iv_reg;

    // One function gets the even lanes attribute, the other gets the odd lanes
    fapi2::ReturnCode (*iv_even_func)(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&, uint8_t&);
    fapi2::ReturnCode (*iv_odd_func)(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&, uint8_t&);
};

namespace adr
{

///
/// @brief Reset the ADR Delay Lines
/// @param[in] i_target the fapi2 target of the MCA
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note reads VPD and resets the delay lines. This is very controller specific, so we have
/// a one function for each controller (er ... but just one now)
///
fapi2::ReturnCode reset_delay( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

} // close namespace adr

} // close namespace mss

#endif
