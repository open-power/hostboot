/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/patterns.C $        */
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
/// @file patterns.C
/// @brief Static definition of MCBIST patterns
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>
#include <lib/mcbist/patterns.H>

namespace mss
{

namespace mcbist
{

/// Vector of cache lines, seaprated in to two 64B chunks
// TK Real patterns from Marc representing the proper bits for ECC checking
const std::vector< pattern > patterns =
{
    // Pattern index 0 (Pattern 1 is this inverted)
    {   {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 2 (Pattern 3 is this inverted)
    {   {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
        {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
    },

    // Pattern index 4 (Pattern 5 is this inverted)
    {   {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 6 (Pattern 7 is this inverted)
    {   {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 8 Random Seed
    {   {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
    },
};

}

}
