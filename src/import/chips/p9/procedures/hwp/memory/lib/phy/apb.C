/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/apb.C $                */
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
/// @file apb.C
/// @brief Subroutines for the PHY APB registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <phy/apb.H>
#include <lib/utils/scom.H>
#include <lib/utils/c_str.H>
#include <lib/utils/index.H>

namespace mss
{

namespace apb
{

///
/// @brief APB block FIR check, MCA style
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if no FIR
///
template<>
fapi2::ReturnCode fir_check(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef apbTraits<fapi2::TARGET_TYPE_MCA> TT;

    fapi2::buffer<uint64_t> l_data;

    // Check with f/w - do they want the first, or should we be logging these and returning ... the last? BRS
    {
        FAPI_TRY( read_error_status0(i_target, l_data) );

        FAPI_ASSERT( l_data.getBit<TT::INVALID_ADDRESS>() == false,
                     fapi2::MSS_APB_INVALID_ADDRESS().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting an invalid address on %s", mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::WRITE_PARITY_ERR>() == false,
                     fapi2::MSS_APB_WR_PAR_ERR().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a read/write parity error on %s", mss::c_str(i_target) );
    }

    {
        uint64_t l_dp16 = 0;

        FAPI_TRY( read_fir_err0(i_target, l_data) );

        FAPI_ASSERT( l_data.getBit<TT::FATAL_FSM>() == false,
                     fapi2::MSS_FATAL_FSM_PHYTOP().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a fatal FSM error in PHYTOP %s", mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::FATAL_PARITY>() == false,
                     fapi2::MSS_FATAL_PARITY_PHYTOP().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a fatal parity error in PHYTOP %s", mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::FSM>() == false,
                     fapi2::MSS_FSM_PHYTOP().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a recoverable FSM error in PHYTOP %s", mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::PARITY>() == false,
                     fapi2::MSS_PARITY_PHYTOP().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a recoverable parity error in PHYTOP %s", mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::FATAL_ADR52_MASTER>() == false,
                     fapi2::MSS_FATAL_ADR52_MASTER().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a fatal register parity error in ADR52 master side logic %s",
                     mss::c_str(i_target) );

        FAPI_ASSERT( l_data.getBit<TT::FATAL_ADR52_SLAVE>() == false,
                     fapi2::MSS_FATAL_ADR52_SLAVE().set_PORT_POSITION(mss::fapi_pos(i_target)).set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a fatal register parity error in ADR52 slave side logic %s",
                     mss::c_str(i_target) );

        l_data.extractToRight<TT::FSM_DP16, TT::FSM_DP16_LEN>(l_dp16);
        FAPI_ASSERT( l_dp16 == 0,
                     fapi2::MSS_FSM_DP16()
                     .set_PORT_POSITION(mss::fapi_pos(i_target))
                     .set_DP16_POSITION(l_dp16)
                     .set_TARGET_IN_ERROR(i_target),
                     "APB interface is reporting a recoverable FSM state checker error in DP16 %s 0x%x",
                     mss::c_str(i_target), l_dp16 );
    }

fapi_try_exit:
    return fapi2::current_err;
}
} // close namespace apb
} // close namespace mss
