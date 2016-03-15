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
#include "mc.H"

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;

namespace mss
{

const uint64_t mcTraits<TARGET_TYPE_MCS>::xlate0_reg[] = {MCS_PORT02_MCP0XLT0, MCS_PORT13_MCP0XLT0};
const uint64_t mcTraits<TARGET_TYPE_MCS>::xlate1_reg[] = {MCS_PORT02_MCP0XLT1, MCS_PORT13_MCP0XLT1};
const uint64_t mcTraits<TARGET_TYPE_MCS>::xlate2_reg[] = {MCS_PORT02_MCP0XLT2, MCS_PORT13_MCP0XLT2};

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

///
/// @brief Perform initializations for the MC (MCA)
/// @param[in] i_target, the MCA to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode mc<TARGET_TYPE_MCA>::scominit(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    uint32_t l_throttle_denominator = 0;
    FAPI_TRY( mss::runtime_mem_m_dram_clocks(i_target, l_throttle_denominator) );

    // #Register Name  Final Arb Parms
    // #Mnemonic       MBA_FARB0Q
    // #Attributes     PAR:EVEN        Bit     Field Mnemonic  Attribute or Setting to use
    // #Description    FARB command control
    // #1. FARB0 bit 38: cfg_parity_after_cmd
    // #       - set this bit if DDR3 and (RDIMM or LDRIMM)
    //
    // #       - clear this bit if DDR4 and (RDIMM or LDRIMM)
    // #2. FARB0 bit 60: cfg_ignore_rcd_parity_err
    // #       - clear this bit if (RDIMM or LDRIMM)
    // #3. FARB0 bit 61: cfg_enable_rcd_rw_retry
    // #       - set this bit if  (RDIMM or LDRIMM)

    // Nimbus is always LR/RDIMM, DDR4.
    // Not sure what happened to cfg_ignore_rcd_parity_err, cfg_enable_rcd_rw_retry - perhaps they're always ok since we don't
    // support anything else?
    {
        fapi2::buffer<uint64_t> l_data;

        l_data.setBit<MCA_MBA_FARB0Q_CFG_PARITY_AFTER_CMD>();
        FAPI_TRY( mss::putScom(i_target, MCA_MBA_FARB0Q, l_data) );
    }

    {
        // FABR1Q - Chip ID bits
    }
    {
        // FARB2Q - ODT bits
    }

    // #Register Name  N/M Throttling Control
    // #Mnemonic       MBA_FARB3Q
    // #Attributes     PAR:EVEN        Bit     Field Mnemonic  Attribute or Setting to use
    // #Description    N/M throttling control (Centaur only)
    // #               0:14    cfg_nm_n_per_mba        MSS_MEM_THROTTLED_N_COMMANDS_PER_MBA (Centaur)
    // #               15:30   cfg_nm_n_per_chip       MSS_MEM_THROTTLED_N_COMMANDS_PER_CHIP (Centaur)
    // #               0:14    cfg_nm_n_per_slot       MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT (Nimbus)
    // #               15:30   cfg_nm_n_per_port       MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT (Nimbus)
    // #               31:44   cfg_nm_m        MSS_MEM_THROTTLED_M_DRAM_CLOCKS
    // #               51      cfg_nm_per_slot_enabled 1 (not on Nimbus?)
    // #               52      cfg_nm_count_other_mba_dis      Set to 0 for CDIMM, Set to 1 for everything else (not on Nimbus?)
    // #cfg_nm_ras_weight, bits 45:47 = ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT
    // #cfg_nm_cas_weight, bits 48:50 = ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT
    {
        fapi2::buffer<uint64_t> l_data;
        uint32_t l_throttle_per_slot = 0;
        uint32_t l_throttle_per_port = 0;
        uint8_t l_ras_weight = 0;
        uint8_t l_cas_weight = 0;

        FAPI_TRY( mss::runtime_mem_throttled_n_commands_per_slot(i_target, l_throttle_per_slot) );
        FAPI_TRY( mss::runtime_mem_throttled_n_commands_per_port(i_target, l_throttle_per_port) );
        FAPI_TRY( mss::throttle_control_ras_weight(i_target, l_ras_weight) );
        FAPI_TRY( mss::throttle_control_cas_weight(i_target, l_cas_weight) );

        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT, MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN>(l_throttle_per_slot);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT, MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN>(l_throttle_per_port);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_M, MCA_MBA_FARB3Q_CFG_NM_M_LEN>(l_throttle_denominator);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT, MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT_LEN>(l_ras_weight);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT, MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT_LEN>(l_ras_weight);

        FAPI_TRY( mss::putScom(i_target, MCA_MBA_FARB3Q, l_data) );
    }

    // Doesn't appear to be a row-hammer-mode in Nimbus
    // #   -- bits 27:41 (cfg_emer_n) = ATTR_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_SLOT
    // #   -- bits 42:55 (cfg_emer_m) = ATTR_MRW_MEM_THROTTLED_M_DRAM_CLOCKS
    {
        fapi2::buffer<uint64_t> l_data;
        uint32_t l_throttle_per_slot = 0;

        FAPI_TRY( mss::mrw_safemode_mem_throttled_n_commands_per_slot(l_throttle_per_slot) );

        l_data.insertFromRight<MCA_MBA_FARB4Q_EMERGENCY_M, MCA_MBA_FARB4Q_EMERGENCY_M_LEN>(l_throttle_denominator);
        l_data.insertFromRight<MCA_MBA_FARB4Q_EMERGENCY_N, MCA_MBA_FARB4Q_EMERGENCY_N_LEN>(l_throttle_per_slot);

        FAPI_TRY( mss::putScom(i_target, MCA_MBA_FARB4Q, l_data) );
    }

    {
        // TMR0Q - DDR data bus timing parameters
    }

    {
        // TMR1Q - DDR bank busy parameters
    }

    {
        // DSM0Q - Data State Machine Configurations
    }

    {
        // MBAREF0Q   mba01 refresh settings
    }

    {
        // MBAPC0Q    power control settings reg 0
        // MBAPC1Q    power control settings reg 1
    }

    {
        // MBAREF1Q   MBA01 Rank-to-primary-CKE mapping table
        // Doesn't exist in Nimbus. Leaving this as a comment to note that we didn't forget it.
        // CKEs are fixed to chip selects for all P9 configs
    }

    {
        // CAL0Q (this timer to be used for zq cal)
        // CAL1Q (this timer to be used for mem cal)
        // CAL3Q (this timer to be used for mem cal)
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
