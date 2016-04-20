/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_volt.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_mss_volt.C
/// @brief Calculate and save off rail voltages
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin  <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB



#include <fapi2.H>
#include <mss.H>
#include <p9_mss_volt.H>
#include <vector>


using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{


///
/// @brief Calculate and save off rail voltages
/// @param[in] i_targets vector of controllers (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_volt( const std::vector< fapi2::Target<TARGET_TYPE_MCS> >& i_targets )
    {
        FAPI_INF("Start mss volt");

        // Loop through MCS
        for (const auto& l_mcs : i_targets)
        {
            //Factory cache is per MCS
            std::map<uint32_t, std::shared_ptr<mss::spd::decoder> > l_factory_caches;
            FAPI_TRY( mss::spd::populate_decoder_caches(l_mcs, l_factory_caches),
                      "Failed to populate decoder cache");

            // Get dimms for each MCS
            for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM> (l_mcs))
            {
                const auto& l_dimm_pos = mss::pos(l_dimm);

                // Fiind decoder factory for this dimm position
                auto l_it = l_factory_caches.find(l_dimm_pos);
                // Check to make sure it's valid
                // TODO - RTC 152390 change factory check
                FAPI_TRY( mss::check::spd::invalid_cache(l_dimm,
                          l_it != l_factory_caches.end(),
                          l_dimm_pos),
                          "Failed to get valid cache");
                {
                    uint8_t l_dimm_nominal = 0;
                    uint8_t l_dimm_endurant = 0;

                    // Read nominal and endurant bits from SPD, 0 = 1.2V is not operable and endurant, 1 = 1.2 is valid
                    FAPI_TRY( l_it->second->operable_nominal_voltage(l_dimm, l_dimm_nominal));
                    FAPI_TRY( l_it->second->endurant_nominal_voltage(l_dimm, l_dimm_endurant));

                    //Check to make sure 1.2 V is both operable and endurant, fail if it is not
                    FAPI_ASSERT ( (l_dimm_nominal == mss::spd::OPERABLE) && (l_dimm_endurant == mss::spd::ENDURANT),
                                  fapi2::MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                                  set_DIMM_VOLTAGE(uint64_t(mss::DDR4_NOMINAL_VOLTAGE)).
                                  set_DIMM_TARGET(l_dimm),
                                  "1.2V is not operable");
                } // scope
            } // l_dimm

            // Set the attributes for this MCS, values are in mss_const.H
            // TK : will need to change attribute target according to voltage rails in the future
            FAPI_TRY (mss::set_voltage_attributes (l_mcs,
                                                   uint64_t(mss::DDR4_NOMINAL_VOLTAGE),
                                                   uint64_t(mss::DDR4_VPP_VOLTAGE)),
                      "Failed to set volt attributes");
        } // mcs

        FAPI_INF("End mss volt");
        return FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    } // p9_mss_volt
} //extern "C"
