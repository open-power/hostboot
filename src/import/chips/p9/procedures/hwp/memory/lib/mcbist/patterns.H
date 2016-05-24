/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/patterns.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file patterns.H
/// @brief Static definition of MCBIST patterns
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MCBIST_PATTERNS_
#define _MSS_MCBIST_PATTERNS_

#include <vector>

namespace mss
{
namespace mcbist
{

/// Memory diagnostic Pattern indexes.
// Why not an enum? I want to do math on them to generate a proper index in to a vector of
// patterns and enums really don't like that.
// Couple of extra symbols in here to keep things easy if desired
constexpr uint64_t PATTERN_ZEROS = 0;
constexpr uint64_t PATTERN_0 = PATTERN_ZEROS;
constexpr uint64_t PATTERN_ONES = 1;
constexpr uint64_t PATTERN_1 = PATTERN_ONES;
constexpr uint64_t PATTERN_2 = 2;
constexpr uint64_t PATTERN_3 = 3;
constexpr uint64_t PATTERN_4 = 4;
constexpr uint64_t PATTERN_5 = 5;
constexpr uint64_t PATTERN_6 = 6;
constexpr uint64_t PATTERN_7 = 7;
constexpr uint64_t PATTERN_8 = 8;
constexpr uint64_t PATTERN_RANDOM = PATTERN_8;
constexpr uint64_t LAST_PATTERN = PATTERN_8;

// Don't mess with the patterns
constexpr uint64_t NO_PATTERN = LAST_PATTERN + 1;

/// Vector of cache lines, seaprated in to two 64B chunks
typedef std::pair<uint64_t, uint64_t> cache_line;
typedef std::vector< cache_line > pattern;
extern const std::vector< pattern > patterns;

}

}
#endif

