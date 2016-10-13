/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config_thermal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_mss_eff_config_thermal.C
/// @brief Perform thermal calculations as part of the effective configuration
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>
#include <p9_mss_eff_config_thermal.H>
#include <p9_mss_bulk_pwr_throttles.H>
#include <lib/power_thermal/throttle.H>
#include <lib/power_thermal/decoder.H>
#include <lib/dimm/kind.H>
#include <mss.H>
extern "C"
{
///
/// @brief Perform thermal calculations as part of the effective configuration
/// @param[in] i_targets an array of MCS targets all on the same VDDR domain
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_eff_config_thermal( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets )
    {

        FAPI_INF("Start effective config thermal");

        uint16_t l_vddr_slope     [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_vddr_int       [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_total_slope    [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_total_int      [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint32_t l_thermal_power  [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};

        //Gotta convert into fapi2::buffers. Not very elegant
        //Do it here or in the encode and decode functions
        std::vector< uint64_t > l_tslope (mss::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_tintercept (mss::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_tthermal_power_limit (mss::SIZE_OF_THERMAL_ATTR, 0);

        std::vector< fapi2::buffer< uint64_t > > l_slope (mss::SIZE_OF_POWER_CURVES_ATTRS);
        std::vector< fapi2::buffer< uint64_t > > l_intercept  (mss::SIZE_OF_POWER_CURVES_ATTRS);
        std::vector< fapi2::buffer< uint64_t > > l_thermal_power_limit (mss::SIZE_OF_THERMAL_ATTR);

        FAPI_TRY ( mss::mrw_pwr_slope (l_tslope.data() ));
        FAPI_TRY ( mss::mrw_pwr_intercept (l_tintercept.data()) );
        FAPI_TRY ( mss::mrw_thermal_memory_power_limit (l_tthermal_power_limit.data()) );

        for (size_t i = 0; i < l_slope.size(); ++i)
        {
            l_slope[i] = fapi2::buffer<uint64_t> (l_tslope[i]);
            l_intercept[i] = fapi2::buffer<uint64_t>(l_tintercept[i]);
        }

        for ( const auto& l_mcs : i_targets )
        {
            FAPI_TRY (mss::power_thermal::get_power_attrs(l_mcs,
                      l_slope,
                      l_intercept,
                      l_thermal_power_limit,
                      l_vddr_slope,
                      l_vddr_int,
                      l_total_slope,
                      l_total_int,
                      l_thermal_power));

            FAPI_TRY( mss::power_thermal::restore_runtime_throttles(l_mcs));

            //Set the power attribute (TOTAL_PWR) to just VDDR for IPL, restoreto vddr+vpp  later for OCC
            //Set here because bulk_pwr_throttles takes input as attributes, and I can't change which attribute it takes
            //So we have to use TOTAL_PWR_SLOPE
            //Setting here and not in set_power_attrs because get_power_attrs decodes the attributes and stores them
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_SLOPE,
                                    l_mcs,
                                    l_vddr_slope));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_INTERCEPT,
                                    l_mcs,
                                    l_vddr_int));
        }

        //get the thermal limits, done per dimm and set to worst case for the slot and port throttles
        FAPI_TRY (p9_mss_bulk_pwr_throttles(i_targets, THERMAL));

        //Set VDDR+VPP
        for ( const auto& l_mcs : i_targets )
        {
            FAPI_TRY (mss::power_thermal::get_power_attrs(l_mcs,
                      l_slope,
                      l_intercept,
                      l_thermal_power_limit,
                      l_vddr_slope,
                      l_vddr_int,
                      l_total_slope,
                      l_total_int,
                      l_thermal_power));

            FAPI_TRY( mss::power_thermal::restore_runtime_throttles(l_mcs));

            //Set the power attribute (TOTAL_PWR) to just VDDR for IPL, restoreto vddr+vpp  later for OCC
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_SLOPE,
                                    l_mcs,
                                    l_total_slope));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_INTERCEPT,
                                    l_mcs,
                                    l_total_int));
        }


        FAPI_INF("End effective config thermal");

    fapi_try_exit:
        return fapi2::FAPI2_RC_SUCCESS;
    }
} //extern C
