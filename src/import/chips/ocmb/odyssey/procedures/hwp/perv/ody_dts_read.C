/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_dts_read.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
/// @file  ody_dts_read.C
/// @brief Read the (single) DTS on Odyssey and return a calibrated temp value
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_dts_read.H>
#include <ody_scom_perv_tcmc.H>
#include <target_filters.H>

SCOMT_PERV_USE_TCMC_EPS_DTS_MEASURE_REQ;
SCOMT_PERV_USE_TCMC_EPS_DTS_CLEAR_RESULTS;
SCOMT_PERV_USE_TCMC_EPS_DTS0123_RAW;

using namespace fapi2;
using namespace scomt::perv;

enum ODY_DTS_READ_Private_Constants
{
    DATA_POLL_COUNT  = 20,
    DATA_POLL_NS     = 100 * 1000,
    DATA_POLL_CYCLES = 20000,

    DTS_COEFFICIENTS_FUSE_ADDRESS = 0x18020,
};

ReturnCode ody_dts_read(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target,
    int16_t& o_temperature)
{
    TCMC_EPS_DTS_MEASURE_REQ_t l_measure_req;
    TCMC_EPS_DTS_CLEAR_RESULTS_t l_clear_results;
    TCMC_EPS_DTS0123_RAW_t l_raw_data;
    buffer<uint64_t> l_fuse_value;
    ody_dts_calib_coeffs l_coeffs;

    FAPI_INF("Entering ...");

    const auto l_mc = i_target.getChildren<TARGET_TYPE_PERV>(TARGET_FILTER_MC, TARGET_STATE_PRESENT)[0];

    FAPI_INF("Triggering DTS read-out");
    l_clear_results = 0;
    l_clear_results.set_PCB_WRITE_CLEAR_RESULTS(1);
    FAPI_TRY(l_clear_results.putScom(l_mc));

    l_measure_req = 0;
    FAPI_TRY(l_measure_req.putScom(l_mc));
    l_measure_req.set_DTS_MEASURE_REQUEST(1);
    FAPI_TRY(l_measure_req.putScom(l_mc));

    FAPI_INF("Waiting for raw DTS result");

    for (int l_timeout = DATA_POLL_COUNT; l_timeout;)
    {
        FAPI_TRY(l_raw_data.getScom(l_mc));

        if (l_raw_data.get_DTS0_DTR0_RAW_VALID())
        {
            break;
        }

        l_timeout--;

        FAPI_ASSERT(l_timeout,
                    ODY_DTS_READ_DATA_TIMEOUT()
                    .set_TARGET_CHIP(i_target)
                    .set_TARGET_MC(l_mc)
                    .set_TIMEOUT(DATA_POLL_COUNT)
                    .set_DATA_REG(l_raw_data),
                    "DTS read timed out");

        delay(DATA_POLL_NS, DATA_POLL_CYCLES);
    }

    // Clear measure request bit after measurement is complete
    l_measure_req = 0;
    FAPI_TRY(l_measure_req.putScom(l_mc));

    FAPI_INF("Reading calibration coefficients from OTPROM");
    FAPI_TRY(getScom(i_target, DTS_COEFFICIENTS_FUSE_ADDRESS, l_fuse_value));
    ody_dts_decode_calib_coeffs(l_fuse_value, l_coeffs);

    FAPI_INF("Calculating calibrated temperature");
    o_temperature = ody_dts_get_calibrated_temp(l_raw_data.get_DTS0_DTR0_RAW_VALUE(), l_coeffs);

    FAPI_INF("Raw reading: %d, P/M/B: %d/%d/%d",
             l_raw_data.get_DTS0_DTR0_RAW_VALUE(),
             l_coeffs.p, l_coeffs.m, l_coeffs.b);
    FAPI_INF("    => Temperature: %d", o_temperature);

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}
