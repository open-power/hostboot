/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/mcbist.H $          */
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
/// @file mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_H_
#define _MSS_MCBIST_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include "../utils/poll.H"
#include "../shared/mss_const.H"

namespace mss
{
namespace mcbist
{

// I have a dream that the MCBIST engine code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the MCBIST engine or hardware
///
template< fapi2::TargetType T >
class mcbistTraits;

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Centaur MCBIST engine or hardware
///
template<>
class mcbistTraits<fapi2::TARGET_TYPE_MEMBUF_CHIP>
{
};

///
/// @class mcbistTraits
/// @brief a collection of traits associated with the Nimbus MCBIST engine or hardware
///
template<>
class mcbistTraits<fapi2::TARGET_TYPE_MCBIST>
{
    public:
        /// MCBIST "memory registers" - config for subtests.
        static const uint64_t MCBMR0_REG = MCBIST_MCBMR0Q;

        enum
        {
            // Subtest control bits. These are the same in all '16 bit subtest' field
            COMPL_1ST_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_1ST_CMD,
            COMPL_2ND_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_2ND_CMD,
            COMPL_3RD_CMD = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_COMPL_3RD_CMD,
            ADDR_REV_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_REV_MODE,
            ADDR_RAND_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_RAND_MODE,
            ECC_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ECC_MODE,
            DATA_MODE = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DATA_MODE,
            DATA_MODE_LEN = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DATA_MODE_LEN,
            ADDR_SEL = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_SEL,
            ADDR_SEL_LEN = MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_ADDR_SEL_LEN,
        };

};

///
/// @class subtest_t
/// @brief encapsulation of an MCBIST subtest.
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
class subtest_t
{
    public:
        /// The mcbist 'memory register' for this subtest.
        // Note that it is only 16 bits.
        // Each 64b memory register contains multiple 16 bit subtest definitions.
        // As we create a vector of subtests, we'll drop them in to their appropriate
        // MCBMR register before executing.
        fapi2::buffer<uint16_t> iv_mcbmr;
};

///
/// @brief A class representing a series of MCBIST subtests, and the
/// MCBIST engine parameters associated with running the subtests
/// @tparam T fapi2::TargetType representing the fapi2 target which
/// contains the MCBIST engine (e.g., fapi2::TARGET_TYPE_MCBIST)
///
template< fapi2::TargetType T >
class program
{
    public:
        // Setup our poll parameters so the CCS executer can see
        // whether to use the delays in the instruction stream or not
        program(): iv_poll(0, 0)
        {}

        // Vector of subtests
        std::vector< subtest_t<T> > iv_subtests;
        poll_parameters             iv_poll;
};

///
/// @brief Complement the data for the first subcommand
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_compliment_1st_cmd( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::COMPL_1ST_CMD>(i_state);
    return;
}

///
/// @brief Complement the data for the second subcommand
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_compliment_2nd_cmd( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::COMPL_2ND_CMD>(i_state);
    return;
}

///
/// @brief Complement the data for the third subcommand
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_compliment_3rd_cmd( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::COMPL_3RD_CMD>(i_state);
    return;
}

///
/// @brief Generate addresses in reverse order
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_addr_rev_mode( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::ADDR_REV_MODE>(i_state);
    return;
}

///
/// @brief Generate addresses in random order
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_addr_rand_mode( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::ADDR_RAND_MODE>(i_state);
    return;
}

///
/// @brief Generate and check data with ECC
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_state the desired state of the function
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_ecc_mode( subtest_t<T>& io_subtest, const mss::states i_state )
{
    io_subtest.iv_mcbmr.template writeBit<TT::ECC_MODE>(i_state);
    return;
}

///
/// @brief Set the data mode for this subtest
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_mode the desired mcbist::data_mode
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_data_mode( subtest_t<T>& io_subtest, const data_mode i_mode )
{
    io_subtest.iv_mcbmr.template insertFromRight<TT::DATA_MODE, TT::DATA_MODE_LEN>(i_mode);
    return;
}

///
/// @brief Configure which address registers to use for this subtest
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mssTraits associtated with T
/// @param[in,out] io_subtest a subtest
/// @param[in] i_index 0 = MCBSA0Q, 1 = MCBSA1Q, ...
/// @note wraps to 0-3 no matter what value you pass in.
/// @return void
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
void change_addr_sel( subtest_t<T>& io_subtest, const uint16_t i_index )
{
    // Roll the index around - tidy support for an index which is out of range.
    static const uint16_t MAX_ADDRESS_START_END_REGISTERS = 3 + 1;
    io_subtest.iv_mcbmr.template insertFromRight<TT::ADDR_SEL, TT::ADDR_SEL_LEN>(i_index % MAX_ADDRESS_START_END_REGISTERS);
    return;
}

} // namespace
} // namespace

#endif
