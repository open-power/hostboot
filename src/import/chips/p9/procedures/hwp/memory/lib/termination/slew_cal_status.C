/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/termination/slew_cal_status.C $ */
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
/// @file slew_cal_status.C
/// @brief Process the status from slew calibration. This is it's own function
/// and file as it gets messey considering there are FFDC object per port ...
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/termination/slew_cal.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;

using fapi2::TARGET_STATE_FUNCTIONAL;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief Process FFDC for slew calibration
/// @param[in] MCA (port) target
/// @param[in] a vector of the steps which came before me
/// @param[in] the slew table to be operated on
/// @param[in] the calibration status
/// @param[in] the register value
/// @return A fapi2::ReturnCode, appropriate for the calibration status
///
fapi2::ReturnCode slew_cal_status(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                  std::vector<tags_t>& i_where_am_i,
                                  const uint64_t l_slew_rate,
                                  const uint64_t i_status,
                                  const fapi2::buffer<uint64_t>& i_reg)
{
    // Some short-hand for this subroutine
    const char* l_type = i_where_am_i[0] == TAG_ADR ? "adr" : "data";
    const uint64_t& l_speed = i_where_am_i[1];
    const uint64_t& l_ohm = i_where_am_i[2];
    const uint64_t& l_vns = i_where_am_i[3];

    // Write up the message/error string once.
    FAPI_INF("Slew calibration: %s slew %s, %lumhz %luohm %luV/ns: %d",
             mss::c_str(i_target), l_type, l_speed, l_ohm, l_vns, l_slew_rate);

    switch (i_status)
    {
        case SLEW_CAL_SUCCESS:
            FAPI_DBG("Slew calibration success");
            break;

        case SLEW_CAL_WARNING:
            FAPI_ERR("Slew calibration warning");
            break;

        case SLEW_CAL_NOT_DONE:
            FAPI_ASSERT(false, fapi2::MSS_SLEW_CAL_TIMEOUT()
                        .set_PORT(mss::pos(i_target))
                        .set_DATA_ADR(i_where_am_i[0])
                        .set_IMP(l_ohm)
                        .set_SLEW(l_slew_rate)
                        .set_STAT_REG(i_reg)
                        .set_TARGET_IN_ERROR(i_target),
                        "Slew calibration timeout");
            break;

        case SLEW_CAL_ERRORS:
            FAPI_ASSERT(false, fapi2::MSS_SLEW_CAL_ERROR()
                        .set_PORT(mss::pos(i_target))
                        .set_DATA_ADR(i_where_am_i[0])
                        .set_IMP(l_ohm)
                        .set_SLEW(l_slew_rate)
                        .set_STAT_REG(i_reg)
                        .set_TARGET_IN_ERROR(i_target),
                        "Slew calibration error");
            break;
    };

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}
