/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mc/mc.C $                  */
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
/// @file mc.C
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include "../utils/dump_regs.H"
#include "../utils/scom.H"

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;

namespace mss
{

///
/// @brief Dump the registers of the MC (MCA_MBA, MCS)
/// @param[in] i_target the MCS target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode dump_regs( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
{
    // To generate this vector:
    // grep MCA_MBA chips/p9/common/include/p9_mc_scom_addresses.H | awk '{ print "{\42" $2 "\42,", $2, "}," }'
    static const std::vector< std::pair<char const*, uint64_t> > l_mba_registers =
    {
        {"MCA_MBACALFIRQ", MCA_MBACALFIRQ },
        {"MCA_MBACALFIRQ_AND", MCA_MBACALFIRQ_AND },
        {"MCA_MBACALFIRQ_OR", MCA_MBACALFIRQ_OR },
        {"MCA_MBACALFIR_ACTION0", MCA_MBACALFIR_ACTION0 },
        {"MCA_MBACALFIR_ACTION1", MCA_MBACALFIR_ACTION1 },
        {"MCA_MBACALFIR_MASK", MCA_MBACALFIR_MASK },
        {"MCA_MBACALFIR_MASK_AND", MCA_MBACALFIR_MASK_AND },
        {"MCA_MBACALFIR_MASK_OR", MCA_MBACALFIR_MASK_OR },
        {"MCA_MBAREF0Q", MCA_MBAREF0Q },
        {"MCA_MBAREFAQ", MCA_MBAREFAQ },
        {"MCA_MBARPC0Q", MCA_MBARPC0Q },
        {"MCA_MBASTR0Q", MCA_MBASTR0Q },
        {"MCA_MBA_CAL0Q", MCA_MBA_CAL0Q },
        {"MCA_MBA_CAL1Q", MCA_MBA_CAL1Q },
        {"MCA_MBA_CAL2Q", MCA_MBA_CAL2Q },
        {"MCA_MBA_CAL3Q", MCA_MBA_CAL3Q },
        {"MCA_MBA_DBG0Q", MCA_MBA_DBG0Q },
        {"MCA_MBA_DBG1Q", MCA_MBA_DBG1Q },
        {"MCA_MBA_DSM0Q", MCA_MBA_DSM0Q },
        {"MCA_MBA_ERR_REPORTQ", MCA_MBA_ERR_REPORTQ },
        {"MCA_MBA_FARB0Q", MCA_MBA_FARB0Q },
        {"MCA_MBA_FARB1Q", MCA_MBA_FARB1Q },
        {"MCA_MBA_FARB2Q", MCA_MBA_FARB2Q },
        {"MCA_MBA_FARB3Q", MCA_MBA_FARB3Q },
        {"MCA_MBA_FARB4Q", MCA_MBA_FARB4Q },
        {"MCA_MBA_FARB5Q", MCA_MBA_FARB5Q },
        {"MCA_MBA_FARB6Q", MCA_MBA_FARB6Q },
        {"MCA_MBA_FARB7Q", MCA_MBA_FARB7Q },
        {"MCA_MBA_PMU0Q", MCA_MBA_PMU0Q },
        {"MCA_MBA_PMU1Q", MCA_MBA_PMU1Q },
        {"MCA_MBA_PMU2Q", MCA_MBA_PMU2Q },
        {"MCA_MBA_PMU3Q", MCA_MBA_PMU3Q },
        {"MCA_MBA_PMU4Q", MCA_MBA_PMU4Q },
        {"MCA_MBA_PMU5Q", MCA_MBA_PMU5Q },
        {"MCA_MBA_PMU6Q", MCA_MBA_PMU6Q },
        {"MCA_MBA_PMU7Q", MCA_MBA_PMU7Q },
        {"MCA_MBA_PMU8Q", MCA_MBA_PMU8Q },
        {"MCA_MBA_RRQ0Q", MCA_MBA_RRQ0Q },
        {"MCA_MBA_TMR0Q", MCA_MBA_TMR0Q },
        {"MCA_MBA_TMR1Q", MCA_MBA_TMR1Q },
        {"MCA_MBA_TMR2Q", MCA_MBA_TMR2Q },
        {"MCA_MBA_WRQ0Q", MCA_MBA_WRQ0Q },
    };

    // To generate this vector:
    // grep MCA_M chips/p9/common/include/p9_mc_scom_addresses.H | awk '{ print "{\42" $2 "\42,", $2, "}," }'
    // grep MCS_PORT02 chips/p9/common/include/p9_mc_scom_addresses.H | awk '{ print "{\42" $2 "\42,", $2, "}," }'
    // grep MCS_PORT13 chips/p9/common/include/p9_mc_scom_addresses.H | awk '{ print "{\42" $2 "\42,", $2, "}," }'
    static const std::vector< std::pair<char const*, uint64_t> > l_mcs_registers =
    {
        {"MCS_MCFGP", MCS_MCFGP },
        {"MCS_MCFGPA", MCS_MCFGPA },
        {"MCS_MCFGPM", MCS_MCFGPM },
        {"MCS_MCFGPMA", MCS_MCFGPMA },
        {"MCS_MCFIR", MCS_MCFIR },
        {"MCS_MCFIR_AND", MCS_MCFIR_AND },
        {"MCS_MCFIR_OR", MCS_MCFIR_OR },
        {"MCS_MCFIRACT0", MCS_MCFIRACT0 },
        {"MCS_MCFIRACT1", MCS_MCFIRACT1 },
        {"MCS_MCFIRMASK", MCS_MCFIRMASK },
        {"MCS_MCFIRMASK_AND", MCS_MCFIRMASK_AND },
        {"MCS_MCFIRMASK_OR", MCS_MCFIRMASK_OR },
        {"MCS_MCLFSR", MCS_MCLFSR },
        {"MCS_MCMODE0", MCS_MCMODE0 },
        {"MCS_MCMODE1", MCS_MCMODE1 },
        {"MCS_MCMODE2", MCS_MCMODE2 },
        {"MCS_MCPERF1", MCS_MCPERF1 },
        {"MCS_MCSYNC", MCS_MCSYNC },
        {"MCS_MCTO", MCS_MCTO },
        {"MCS_MCWATCNTL", MCS_MCWATCNTL },

        {"MCS_PORT02_AACR", MCS_PORT02_AACR },
        {"MCS_PORT02_AADR", MCS_PORT02_AADR },
        {"MCS_PORT02_AAER", MCS_PORT02_AAER },
        {"MCS_PORT02_MCAMOC", MCS_PORT02_MCAMOC },
        {"MCS_PORT02_MCBUSYQ", MCS_PORT02_MCBUSYQ },
        {"MCS_PORT02_MCEBUSCL", MCS_PORT02_MCEBUSCL },
        {"MCS_PORT02_MCEPSQ", MCS_PORT02_MCEPSQ },
        {"MCS_PORT02_MCERRINJ", MCS_PORT02_MCERRINJ },
        {"MCS_PORT02_MCP0XLT0", MCS_PORT02_MCP0XLT0 },
        {"MCS_PORT02_MCP0XLT1", MCS_PORT02_MCP0XLT1 },
        {"MCS_PORT02_MCP0XLT2", MCS_PORT02_MCP0XLT2 },
        {"MCS_PORT02_MCPERF0", MCS_PORT02_MCPERF0 },
        {"MCS_PORT02_MCPERF2", MCS_PORT02_MCPERF2 },
        {"MCS_PORT02_MCPERF3", MCS_PORT02_MCPERF3 },
        {"MCS_PORT02_MCWAT", MCS_PORT02_MCWAT },

        {"MCS_PORT13_MCAMOC", MCS_PORT13_MCAMOC },
        {"MCS_PORT13_MCBUSYQ", MCS_PORT13_MCBUSYQ },
        {"MCS_PORT13_MCEBUSCL", MCS_PORT13_MCEBUSCL },
        {"MCS_PORT13_MCEBUSEN0", MCS_PORT13_MCEBUSEN0 },
        {"MCS_PORT13_MCEBUSEN1", MCS_PORT13_MCEBUSEN1 },
        {"MCS_PORT13_MCEBUSEN2", MCS_PORT13_MCEBUSEN2 },
        {"MCS_PORT13_MCEBUSEN3", MCS_PORT13_MCEBUSEN3 },
        {"MCS_PORT13_MCEPSQ", MCS_PORT13_MCEPSQ },
        {"MCS_PORT13_MCERRINJ", MCS_PORT13_MCERRINJ },
        {"MCS_PORT13_MCP0XLT0", MCS_PORT13_MCP0XLT0 },
        {"MCS_PORT13_MCP0XLT1", MCS_PORT13_MCP0XLT1 },
        {"MCS_PORT13_MCP0XLT2", MCS_PORT13_MCP0XLT2 },
        {"MCS_PORT13_MCPERF0", MCS_PORT13_MCPERF0 },
        {"MCS_PORT13_MCPERF2", MCS_PORT13_MCPERF2 },
        {"MCS_PORT13_MCPERF3", MCS_PORT13_MCPERF3 },
        {"MCS_PORT13_MCWAT", MCS_PORT13_MCWAT },
    };

    for (auto r : l_mcs_registers)
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY( mss::getScom(i_target, r.second, l_data) );
        FAPI_DBG("dump %s: 0x%016lx 0x%016lx", r.first, r.second, l_data);
    }

    for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        for (auto r : l_mba_registers)
        {
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY( mss::getScom(p, r.second, l_data) );
            FAPI_DBG("dump %s: 0x%016lx 0x%016lx", r.first, r.second, l_data);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
