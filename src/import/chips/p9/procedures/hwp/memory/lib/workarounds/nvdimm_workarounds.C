/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/nvdimm_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
///
/// @file nvdimm_workarounds.C
/// @brief Workarounds for NVDIMM
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:SBE

#include <fapi2.H>
#include <vector>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

namespace mss
{

namespace workarounds
{

namespace nvdimm
{


// MBASTR0Q for each MCA
// Note: Since the scoms are executed at the chip, it needs the dedicated
// address for each MCA
constexpr const uint64_t MBASTR0Q_REG[] =
{
    MCA_0_MBASTR0Q,
    MCA_1_MBASTR0Q,
    MCA_2_MBASTR0Q,
    MCA_3_MBASTR0Q,
    MCA_4_MBASTR0Q,
    MCA_5_MBASTR0Q,
    MCA_6_MBASTR0Q,
    MCA_7_MBASTR0Q,
};

// MBARPC0Q for each MCA
constexpr const uint64_t MBARPC0Q_REG[] =
{
    MCA_0_MBARPC0Q,
    MCA_1_MBARPC0Q,
    MCA_2_MBARPC0Q,
    MCA_3_MBARPC0Q,
    MCA_4_MBARPC0Q,
    MCA_5_MBARPC0Q,
    MCA_6_MBARPC0Q,
    MCA_7_MBARPC0Q,
};

// FARB5Q for each MCA
constexpr const uint64_t FARB5Q_REG[] =
{
    MCA_0_MBA_FARB5Q,
    MCA_1_MBA_FARB5Q,
    MCA_2_MBA_FARB5Q,
    MCA_3_MBA_FARB5Q,
    MCA_4_MBA_FARB5Q,
    MCA_5_MBA_FARB5Q,
    MCA_6_MBA_FARB5Q,
    MCA_7_MBA_FARB5Q,
};

// FARB6Q for each MCA
constexpr const uint64_t FARB6Q_REG[] =
{
    MCA_0_MBA_FARB6Q,
    MCA_1_MBA_FARB6Q,
    MCA_2_MBA_FARB6Q,
    MCA_3_MBA_FARB6Q,
    MCA_4_MBA_FARB6Q,
    MCA_5_MBA_FARB6Q,
    MCA_6_MBA_FARB6Q,
    MCA_7_MBA_FARB6Q,
};

// MCFGP for each MCS
constexpr const uint64_t MCFGP[] =
{
    MCS_0_MCFGP,
    MCS_1_MCFGP,
    MCS_2_MCFGP,
    MCS_3_MCFGP,
};

// MCB_CNTLQ
constexpr const uint64_t MCB_CNTLQ_REG[] =
{
    MCBIST_0_MCB_CNTLQ,
    MCBIST_1_MCB_CNTLQ,
};

constexpr uint8_t PORTS_PER_MODULE = 8;

///
/// @brief Helper for trigger_csave. This subroutine puts the MCA into STR
/// This is the same thing as mss::nvdimm::self_refresh_entry() but rewritten
/// to support SBE
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mca_pos - The MCA position relative to the PROC
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                      const uint8_t i_mca_pos)
{
    FAPI_ASSERT((i_mca_pos < PORTS_PER_MODULE),
                fapi2::MSS_SRE_MCA_OUT_OF_RANGE().
                set_PROC_TARGET(i_target).
                set_MCA_POS(i_mca_pos),
                "Invalid port number %u provided", i_mca_pos);

    FAPI_DBG("Entering STR on port %u.", i_mca_pos);

    {
        fapi2::buffer<uint64_t> l_mbarpc0_data;
        fapi2::buffer<uint64_t> l_mbastr0_data;
        fapi2::buffer<uint64_t> l_mcbcntlq_data;
        fapi2::buffer<uint64_t> l_mcafarb6q_data;
        constexpr uint64_t ENABLE = 1;
        constexpr uint64_t DISABLE = 0;
        constexpr uint64_t MAXALL_MIN0 = 0b010;
        constexpr uint64_t STOP = 1;
        constexpr uint64_t PORTS_PER_MCBIST = 4;
        constexpr uint64_t TIME_0 = 0;
        const uint8_t l_mcbist = i_mca_pos < PORTS_PER_MCBIST ? 0 : 1;

        // Variables for polling. Poll up to a second to make sure the port has entered STR
        // Why a second? No idea. STR is controlled by the sequencer via power control.
        // The settings are set to enter STR ASAP but a poll here would let us know
        // if somehow the port is not in STR.
        constexpr uint64_t POLL_ITERATION = 500;
        constexpr uint64_t DELAY_2MS_IN_NS = 2000000;
        bool l_in_str = false;
        uint8_t l_sim = 0;

        // Stop mcbist first otherwise it can kick the DIMM out of STR
        FAPI_TRY(fapi2::getScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_mcbcntlq_data));
        l_mcbcntlq_data.writeBit<MCBIST_CCS_CNTLQ_STOP>(STOP);
        FAPI_TRY(fapi2::putScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_mcbcntlq_data));

        // Step 1 - In MBARPC0Q, disable power domain control, set domain to MAXALL_MIN0,
        //          and disable minimum domain reduction (allow immediate entry of STR)
        FAPI_TRY(fapi2::getScom(i_target, MBARPC0Q_REG[i_mca_pos], l_mbarpc0_data));
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE>(DISABLE);
        l_mbarpc0_data.insertFromRight<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS, MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_LEN>(MAXALL_MIN0);
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE>(DISABLE);
        FAPI_TRY(fapi2::putScom(i_target, MBARPC0Q_REG[i_mca_pos], l_mbarpc0_data));

        // Step 2 - In MBASTR0Q, enable STR entry
        FAPI_TRY(fapi2::getScom(i_target, MBASTR0Q_REG[i_mca_pos], l_mbastr0_data));
        l_mbastr0_data.writeBit<MCA_MBASTR0Q_CFG_STR_ENABLE>(ENABLE);
        l_mbastr0_data.insertFromRight<MCA_MBASTR0Q_CFG_ENTER_STR_TIME, MCA_MBASTR0Q_CFG_ENTER_STR_TIME_LEN>(TIME_0);
        FAPI_TRY(fapi2::putScom(i_target, MBASTR0Q_REG[i_mca_pos], l_mbastr0_data));

        // Step 3 - In MBARPC0Q, enable power domain control.
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE>(ENABLE);
        FAPI_TRY(fapi2::putScom(i_target, MBARPC0Q_REG[i_mca_pos], l_mbarpc0_data));

#ifndef __PPE__
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );
#endif

        if (!l_sim)
        {
            // Poll to make sure we are in STR before proceeding.
            for (uint8_t i = 0; i < POLL_ITERATION; i++)
            {
                FAPI_TRY(fapi2::delay(DELAY_2MS_IN_NS, 0), "Error returned from fapi2::delay call");
                FAPI_TRY(fapi2::getScom(i_target, FARB6Q_REG[i_mca_pos], l_mcafarb6q_data));

                if (l_mcafarb6q_data.getBit<MCA_MBA_FARB6Q_CFG_STR_STATE>())
                {
                    l_in_str = true;
                    break;
                }
            }

            FAPI_ASSERT(l_in_str,
                        fapi2::MSS_STR_NOT_ENTERED().
                        set_PROC_TARGET(i_target).
                        set_MCA_POS(i_mca_pos).
                        set_MCA_FARB6Q(l_mcafarb6q_data).
                        set_STR_STATE(l_in_str),
                        "STR not entered on port %u", i_mca_pos);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper for trigger_csave. This subroutine assert RESET_n to trigger
/// the backup on nvdimm
/// @param[in] i_target - PROC_CHIP targetdefine
/// @param[in] i_mca_pos - The MCA position relative to the PROC
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode assert_resetn( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target, const uint8_t i_mca_pos)
{
    FAPI_ASSERT((i_mca_pos < PORTS_PER_MODULE),
                fapi2::MSS_RESETN_MCA_OUT_OF_RANGE().
                set_PROC_TARGET(i_target).
                set_MCA_POS(i_mca_pos),
                "Invalid port number %u provided", i_mca_pos);

    FAPI_DBG("Asserting RESETn on port %d.", i_mca_pos);

    {
        fapi2::buffer<uint64_t> l_farb5q_data;
        constexpr uint64_t LOW = 0;

        FAPI_TRY(fapi2::getScom(i_target, FARB5Q_REG[i_mca_pos], l_farb5q_data));
        l_farb5q_data.writeBit<MCA_MBA_FARB5Q_CFG_DDR_RESETN>(LOW);
        FAPI_TRY(fapi2::putScom(i_target, FARB5Q_REG[i_mca_pos], l_farb5q_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief change the BAR valid state on MCS with NVDIMM installed
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_port_bitmap - port bitmap that indicates port with nvdimm
/// @param[in] i_state - BAR state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode change_bar_valid_state( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const fapi2::buffer<uint8_t> i_port_bitmap,
        const uint64_t i_state)
{
    for (uint8_t l_mca_pos = 0; l_mca_pos < PORTS_PER_MODULE; l_mca_pos++)
    {
        if (i_port_bitmap.getBit(l_mca_pos) == fapi2::ENUM_ATTR_SBE_NVDIMM_IN_PORT_YES)
        {
            const uint8_t l_mcs = l_mca_pos / 2;
            fapi2::buffer<uint64_t> l_data;

            FAPI_TRY(fapi2::getScom(i_target, MCFGP[l_mcs], l_data));
            l_data.writeBit<MCS_MCFGP_VALID>(i_state);
            FAPI_TRY(fapi2::putScom(i_target, MCFGP[l_mcs], l_data));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Triggers csave on NVDIMM. This subroutine reads ATTR_SBE_NVDIMM_IN_PORT
/// and fires the trigger to all the ports with NVDIMM plugged. This is written
/// specifically for SBE.
/// @param[in] i_target - PROC_CHIP target
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode trigger_csave( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    fapi2::buffer<uint8_t> l_nvdimm_port_bitmap = 0;
    constexpr uint64_t INVALID = 0;
    constexpr uint64_t VALID = 1;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SBE_NVDIMM_IN_PORT, i_target, l_nvdimm_port_bitmap) );

    // Invalidate the BAR temporarily. This prevents any memory access (proc, IO, etc.) from
    // remove the port out of STR
    FAPI_TRY( change_bar_valid_state(i_target, l_nvdimm_port_bitmap, INVALID));

    for (uint8_t l_mca_pos = 0; l_mca_pos < PORTS_PER_MODULE; l_mca_pos++)
    {
        if (l_nvdimm_port_bitmap.getBit(l_mca_pos) == fapi2::ENUM_ATTR_SBE_NVDIMM_IN_PORT_YES)
        {
            FAPI_DBG("NVDIMM found in port %d ", l_mca_pos);

            // Enter STR
            FAPI_TRY(self_refresh_entry(i_target, l_mca_pos));

            // Assert ddr_resetn
            FAPI_TRY(assert_resetn(i_target, l_mca_pos));
        }
    }

    // Set the BAR back to valid. This is a don't care for the power down but required
    // for MPIPL.
    FAPI_TRY( change_bar_valid_state(i_target, l_nvdimm_port_bitmap, VALID));

fapi_try_exit:
    return fapi2::current_err;
}

}//ns nvdimm

}//ns workarounds

}//ns mss
