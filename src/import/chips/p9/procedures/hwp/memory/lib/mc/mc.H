/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mc/mc.H $                  */
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
/// @file mc.H
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MC_H_
#define _MSS_MC_H_

#include <fapi2.H>

#include "p9_mc_scom_addresses.H"
#include "p9_mc_scom_addresses_fld.H"
#include "mss_attribute_accessors.H"
#include "../utils/scom.H"

namespace mss
{

// I have a dream that the xlate code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class mcTraits
/// @brief a collection of traits associated with the MC
/// @tparam T, fapi2::TargetType representing the MC
///
template< fapi2::TargetType T >
class mcTraits;

///
/// @class mcTraits
/// @brief a collection of traits associated with the Centaur controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MEMBUF_CHIP>
{
};

///
/// @class mcTraits
/// @brief a collection of traits associated with the Nimbus controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MCS>
{
    public:
        // Array of registers indexed by MCA position
        static const uint64_t xlate0_reg[2];
        static const uint64_t xlate1_reg[2];
        static const uint64_t xlate2_reg[2];

        enum
        {
            SLOT0_VALID = MCS_PORT02_MCP0XLT0_SLOT0_VALID,
            SLOT0_ROW15_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID,
            SLOT0_M1_VALID = MCS_PORT02_MCP0XLT0_SLOT0_M1_VALID,
            M1_BIT_MAP = MCS_PORT02_MCP0XLT0_M1_BIT_MAP,
            M1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN,
            D_BIT_MAP = MCS_PORT02_MCP0XLT0_D_BIT_MAP,
            D_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN,
            R15_BIT_MAP = MCS_PORT02_MCP0XLT0_R15_BIT_MAP,
            R15_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN,
            COL4_BIT_MAP = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
            COL4_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN,
            COL5_BIT_MAP = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
            COL5_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN,
            COL6_BIT_MAP = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
            COL6_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN,
            COL7_BIT_MAP = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
            COL7_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN,
            COL8_BIT_MAP = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
            COL8_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN,
            COL9_BIT_MAP = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
            COL9_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN,
            BANK0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
            BANK0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN,
            BANK1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
            BANK1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN,
            BANK_GROUP0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
            BANK_GROUP0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN,
            BANK_GROUP1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
            BANK_GROUP1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN,
        };

};

// Why two enums? Two reasons. First, we need these to be contiguous, and
// we can't always guarentee the symbols will be generated as such. Second,
// we want to be 0'based so that we can use a static array as a table and
// it's probably not possible for the symbols to be 0'based.
enum
{
    THIS_ENTRY_VALID = 0,
    VALUE_OF_D_BIT_INDEX = 1,
    GB12_ENABLE_INDEX = 2,
    MASTER_BIT_0_VALID_INDEX = 3,
    MASTER_BIT_1_VALID_INDEX = 4,
    SLAVE_BIT_0_VALID_INDEX = 5,
    SLAVE_BIT_1_VALID_INDEX = 6,
    SLAVE_BIT_2_VALID_INDEX = 7,
    ROW_BIT_15_VALID_INDEX = 8,
    ROW_BIT_16_VALID_INDEX = 9,
    ROW_BIT_17_VALID_INDEX = 10,
    BANK_BIT_2_VALID_INDEX = 11,
    DIMM_BIT_INDEX = 12,
    MASTER_BIT_0_INDEX = 13,
    MASTER_BIT_1_INDEX = 14,
    SLAVE_BIT_0_INDEX = 15,
    SLAVE_BIT_1_INDEX = 16,
    SLAVE_BIT_2_INDEX = 17,
    ROW_17_INDEX = 18,
    ROW_16_INDEX = 19,
    COLUMN_4_INDEX = 20,
    COLUMN_5_INDEX = 21,
    COLUMN_6_INDEX = 22,
    COLUMN_7_INDEX = 23,
    COLUMN_8_INDEX = 24,
    COLUMN_9_INDEX = 25,
    BANK_0_INDEX = 26,
    BANK_1_INDEX = 27,
    BANK_2_INDEX = 28,
    BANK_GROUP_0_BIT_INDEX = 29,
    BANK_GROUP_1_BIT_INDEX = 30,
    MAX_TRANSLATIONS = 31,
};

///
/// @class mss::mc
/// @brief The memory controller class
/// @tparam T the fapi2::TargetType of the controller
///
template< fapi2::TargetType T >
class mc
{

    public:
        ///
        /// @brief Perform initializations for the MC
        /// @tparam T the fapi2::TargetType
        /// @param[in] i_target the target which has the MCs to initialize
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode scominit(const fapi2::Target<T>& i_target);

        ///
        /// @brief Perform initializations of the MC translation
        /// @tparam P the fapi2::TargetType of the port
        /// @tparam TT the typename of the traits
        /// @param[in] i_target the target which has the MCA to map
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template< fapi2::TargetType P, typename TT = mcTraits<T> >
        fapi2::ReturnCode setup_xlate_map(const fapi2::Target<P>& i_target);

};

}

#endif
