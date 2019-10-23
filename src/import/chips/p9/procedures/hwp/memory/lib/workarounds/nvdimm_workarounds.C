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

// Note: Since the scoms are executed at the chip, it needs the dedicated
// address for each MCA

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

// MCB_MCBAGRAQ
constexpr const uint64_t MCB_MCBAGRAQ_REG[] =
{
    MCBIST_0_MCBAGRAQ,
    MCBIST_1_MCBAGRAQ,
};

// CCS_MODEQ
constexpr const uint64_t CCS_MODEQ_REG[] =
{
    MCBIST_0_CCS_MODEQ,
    MCBIST_1_CCS_MODEQ,
};

// CCS_CNTLQ
constexpr const uint64_t CCS_CNTLQ_REG[] =
{
    MCBIST_0_CCS_CNTLQ,
    MCBIST_1_CCS_CNTLQ,
};

constexpr uint8_t PORTS_PER_MODULE = 8;
constexpr uint8_t PORTS_PER_MCBIST = 4;
constexpr uint8_t MCBISTS_PER_PROC = 2;

///
/// @brief Program the necessary scom regs to prepare for CSAVE
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mcbist - mcbist position relative to the proc
/// @param[out] o_addresses - list of addresses that require restore
/// @param[out] o_data - data to restore to o_addresses
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode prep_for_csave( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const uint8_t i_mcbist,
                                  std::vector<uint64_t>& o_addresses,
                                  std::vector<fapi2::buffer<uint64_t>>& o_data)
{
    fapi2::buffer<uint64_t> l_mcbcntlq_data;
    fapi2::buffer<uint64_t> l_mcbagraq_data;
    fapi2::buffer<uint64_t> l_ccs_modeq_data;

    // Stop mcbist first otherwise it can kick the DIMM out of STR
    FAPI_TRY(fapi2::getScom(i_target, MCB_CNTLQ_REG[i_mcbist], l_mcbcntlq_data));
    l_mcbcntlq_data.setBit<MCBIST_CCS_CNTLQ_STOP>();
    FAPI_TRY(fapi2::putScom(i_target, MCB_CNTLQ_REG[i_mcbist], l_mcbcntlq_data));

    // Backup the address and data for the following scoms to restore later

    // Disable maint. address mode
    FAPI_TRY(fapi2::getScom(i_target, MCB_MCBAGRAQ_REG[i_mcbist], l_mcbagraq_data));
    o_addresses.push_back(MCB_MCBAGRAQ_REG[i_mcbist]);
    o_data.push_back(l_mcbagraq_data);
    l_mcbagraq_data.clearBit<MCBIST_MCBAGRAQ_CFG_MAINT_ADDR_MODE_EN>();
    FAPI_TRY(fapi2::putScom(i_target, MCB_MCBAGRAQ_REG[i_mcbist], l_mcbagraq_data));

    // Required for CCS to drive RESETn
    FAPI_TRY(fapi2::getScom(i_target, CCS_MODEQ_REG[i_mcbist], l_ccs_modeq_data));
    o_addresses.push_back(CCS_MODEQ_REG[i_mcbist]);
    o_data.push_back(l_ccs_modeq_data);
    l_ccs_modeq_data.setBit<MCBIST_CCS_MODEQ_IDLE_PAT_BANK_2>();
    FAPI_TRY(fapi2::putScom(i_target, CCS_MODEQ_REG[i_mcbist], l_ccs_modeq_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Start or stop CCS
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mcbist - mcbist position relative to the proc
/// @param[in] i_start_stop - start or stop CCS
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode start_stop_ccs( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const uint8_t i_mcbist,
                                  const uint8_t i_start_stop)
{
    fapi2::buffer<uint64_t> l_data;
    constexpr uint8_t START = 1;

    FAPI_TRY(fapi2::getScom(i_target, CCS_CNTLQ_REG[i_mcbist], l_data));
    FAPI_TRY(fapi2::putScom(i_target, CCS_CNTLQ_REG[i_mcbist],
                            i_start_stop == START ? l_data.setBit<MCBIST_CCS_CNTLQ_START>() : l_data.setBit<MCBIST_CCS_CNTLQ_STOP>()));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Select which port to run CCS on
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mca - mca position relative to the proc
/// @param[out] o_addresses - list of addresses that require restore
/// @param[out] o_data - data to restore to o_addresses
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode select_port(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                              const uint8_t i_mca,
                              std::vector<uint64_t>& o_addresses,
                              std::vector<fapi2::buffer<uint64_t>>& o_data)
{
    FAPI_ASSERT((i_mca < PORTS_PER_MODULE),
                fapi2::MSS_SELECT_PORT_MCA_OUT_OF_RANGE().
                set_PROC_TARGET(i_target).
                set_MCA_POS(i_mca),
                "Invalid port number %u provided", i_mca);
    {
        // MCB_CNTLQ[2:5]. Default to port 0 then shift right as needed
        constexpr uint8_t PORT_0 = 0b1000;
        const uint64_t l_port_sel = PORT_0 >> (i_mca % PORTS_PER_MCBIST);
        const uint8_t l_mcbist = i_mca < PORTS_PER_MCBIST ? 0 : 1;
        fapi2::buffer<uint64_t> l_data;

        FAPI_TRY(fapi2::getScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_data));
        l_data.insertFromRight<MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL, MCBIST_MCB_CNTLQ_MCBCNTL_PORT_SEL_LEN>(l_port_sel);
        FAPI_TRY(fapi2::putScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_data));

        // For each port, set the address mux to CCS and enable CCS to drive RESETn
        FAPI_TRY(fapi2::getScom(i_target, FARB5Q_REG[i_mca], l_data));
        o_addresses.push_back(FARB5Q_REG[i_mca]);
        o_data.push_back(l_data);
        l_data.setBit<MCA_MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL>();
        l_data.setBit<MCA_MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target, FARB5Q_REG[i_mca], l_data));
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
    constexpr uint8_t START = 1;
    constexpr uint8_t STOP = 0;
    constexpr uint64_t MS_IN_NS = 1000000;
    const uint64_t DELAY_20MS_IN_NS = 20 * MS_IN_NS;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SBE_NVDIMM_IN_PORT, i_target, l_nvdimm_port_bitmap) );

    // Invalidate the BAR temporarily. This prevents any memory access (proc, IO, etc.) from
    // remove the port out of STR
    FAPI_TRY( change_bar_valid_state(i_target, l_nvdimm_port_bitmap, INVALID));

    // Get all the mcbists/mcas with NVDIMM
    for (uint8_t l_mcbist = 0; l_mcbist < MCBISTS_PER_PROC; l_mcbist++)
    {
        std::vector<uint8_t> l_mcas;
        std::vector<uint64_t> l_addresses;
        std::vector<fapi2::buffer<uint64_t>> l_data;
        const uint8_t MCA_STARTING_POS = (PORTS_PER_MCBIST * l_mcbist);

        // For each mcbist, gather a list of mcas with nvdimm installed
        for (uint8_t l_mca_pos = 0 + MCA_STARTING_POS;
             l_mca_pos < PORTS_PER_MCBIST + MCA_STARTING_POS;
             l_mca_pos++)
        {
            if (l_nvdimm_port_bitmap.getBit(l_mca_pos) == fapi2::ENUM_ATTR_SBE_NVDIMM_IN_PORT_YES)
            {
                l_mcas.push_back(l_mca_pos);
            }
        }

        // Nothing to do
        if (l_mcas.empty())
        {
            FAPI_DBG("No mca with nvdimm detect. l_mcbist = 0x%x, l_mcas.size = %u",
                     l_mcbist, l_mcas.size());
            continue;
        }

        // Prep mcbist/ccs for csave
        FAPI_TRY( prep_for_csave(i_target, l_mcbist, l_addresses, l_data));

        // Start and stop CCS, one port at a time.
        for (const auto l_mca : l_mcas)
        {
            FAPI_TRY( select_port(i_target, l_mca, l_addresses, l_data), "Error returned from select_port(). l_mca = %u", l_mca);
            FAPI_TRY( start_stop_ccs(i_target, l_mcbist, START), "Error to START from start_stop_ccs()");
            FAPI_TRY( fapi2::delay(DELAY_20MS_IN_NS, 0), "Error returned from fapi2::delay call");
            FAPI_TRY( start_stop_ccs(i_target, l_mcbist, STOP), "Error to STOP from start_stop_ccs()");
        }

        // Restore the original value. This is a don't care for poweroff/warm reboot,
        // needed for MPIPL
        for (size_t index = 0; index < l_addresses.size(); index++)
        {
            FAPI_TRY(fapi2::putScom(i_target, l_addresses[index], l_data[index]));
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
