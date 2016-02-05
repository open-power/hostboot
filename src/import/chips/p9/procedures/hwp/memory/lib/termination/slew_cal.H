/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/termination/slew_cal.H $   */
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
/// @file slew_cal.H
/// @brief  Runs the slew calibration engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SLEW_CAL_H_
#define _MSS_SLEW_CAL_H_

#include <fapi2.H>

namespace mss
{

// bits: 58:59 DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR0_SLEW_DONE_STATUS(0:1)
enum slew_done_status
{
    SLEW_CAL_NOT_DONE = 0b00, ///< Not complete
    SLEW_CAL_ERRORS   = 0b01, ///< Complete, but with errors - didn't reach alignment
    SLEW_CAL_WARNING  = 0b10, ///< Complete, but with warnings - slew cntl is 0b0000
    SLEW_CAL_SUCCESS  = 0b11, ///< OK
};

// Used for tagging slew rate information in the table. We use enums for tags rather than
// strings for a few reasons, not the least of which it simplifies putting the tags into error logs.
enum tags_t
{
    TAG_DATA = 0,
    TAG_ADR = 1,

    TAG_3VNS   = 3,
    TAG_4VNS   = 4,
    TAG_5VNS   = 5,
    TAG_6VNS   = 6,
    TAG_MAXVNS = 7,

    TAG_15OHM = 15,
    TAG_20OHM = 20,
    TAG_24OHM = 24,
    TAG_30OHM = 30,
    TAG_34OHM = 34,
    TAG_40OHM = 40,

    TAG_1066MHZ = 1066,
    TAG_1333MHZ = 1333,
    TAG_1600MHZ = 1600,
    TAG_1866MHZ = 1866,
    TAG_2400MHZ = 2400,
};

///
/// @brief find the attribute array index of a tag
/// @param[in] i_type whether this is an adr or dq lookup
/// @param[in] i_tag tags_t the tag to find the index of
/// @return size_t the attribute array index
///
inline size_t index(const tags_t& i_type, const tags_t& i_tag)
{
    // Static table to map some tags to indexes.
    // First are the indexes for DATA, second are the indexes for ADR
    static const size_t map[2][41] =
    {
        // DATA
        //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
        {
            0, 1, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            // 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 3
        },

        // ADR
        //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
        {
            0, 1, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            // 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40
            0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3
        }
    };

    fapi2::Assert((i_type == TAG_ADR) || (i_type == TAG_DATA));
    fapi2::Assert(i_tag <= TAG_40OHM);
    return map[i_type][i_tag];
}


typedef std::pair<tags_t, uint64_t> slew_rate_t;

// Some types to help us keep track of the slew information
///< slew(3)3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
typedef std::vector< slew_rate_t > slew_rates_t;

///< imped(4)24ohms=0, 30ohms=1, 34ohms=2, 40ohms=3 for DQ/DQS
///< imped(4)15ohms=0, 20ohms=1, 30ohms=2, 40ohms=3 for ADR driver
typedef std::vector< std::pair<tags_t, slew_rates_t> > slew_per_imp_t;

///< speed(4)1066=0, 1333=1, 1600=2, 1866=3
typedef std::vector< std::pair<tags_t, slew_per_imp_t> > slew_table_t;

///
/// @brief Run the sle calibration engine
/// @param[in] i_target the MCBIST
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode slew_cal(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target);

///
/// @brief Process FFDC for slew calibration
/// @param[in] i_target MCA (port) target
/// @param[in] -_where_am_i a vector of the steps which came before me
/// @param[in] l_slew_rate the slew table to be operated on
/// @param[in] i_status the calibration status
/// @param[in] i_reg the register value
/// @return A fapi2::ReturnCode, appropriate for the calibration status
///
fapi2::ReturnCode slew_cal_status(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                  std::vector<tags_t>& i_where_am_i,
                                  const uint64_t l_slew_rate,
                                  const uint64_t i_status,
                                  const fapi2::buffer<uint64_t>& i_reg);
}
#endif
