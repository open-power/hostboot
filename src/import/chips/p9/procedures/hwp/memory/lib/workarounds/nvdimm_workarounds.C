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
/// @param[in] l_mca_pos - The MCA position relative to the PROC
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                      const uint8_t l_mca_pos)
{
    FAPI_ASSERT((l_mca_pos < PORTS_PER_MODULE),
                fapi2::MSS_SRE_MCA_OUT_OF_RANGE().
                set_PROC_TARGET(i_target).
                set_MCA_POS(l_mca_pos),
                "Invalid port number %u provided", l_mca_pos);

    FAPI_DBG("Entering STR on port %u.", l_mca_pos);

    {
        fapi2::buffer<uint64_t> l_mbarpc0_data, l_mbastr0_data, l_mcbcntlq_data;
        constexpr uint64_t ENABLE = 1;
        constexpr uint64_t DISABLE = 0;
        constexpr uint64_t MAXALL_MIN0 = 0b010;
        constexpr uint64_t STOP = 1;
        constexpr uint64_t PORTS_PER_MCBIST = 4;
        constexpr uint64_t TIME_0 = 0;
        const uint8_t l_mcbist = l_mca_pos < PORTS_PER_MCBIST ? 0 : 1;

        // Stop mcbist first otherwise it can kick the DIMM out of STR
        FAPI_TRY(fapi2::getScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_mcbcntlq_data));
        l_mcbcntlq_data.writeBit<MCBIST_CCS_CNTLQ_STOP>(STOP);
        FAPI_TRY(fapi2::putScom(i_target, MCB_CNTLQ_REG[l_mcbist], l_mcbcntlq_data));

        // Step 1 - In MBARPC0Q, disable power domain control, set domain to MAXALL_MIN0,
        //          and disable minimum domain reduction (allow immediate entry of STR)
        FAPI_TRY(fapi2::getScom(i_target, MBARPC0Q_REG[l_mca_pos], l_mbarpc0_data));
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE>(DISABLE);
        l_mbarpc0_data.insertFromRight<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS, MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_LEN>(MAXALL_MIN0);
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE>(DISABLE);
        FAPI_TRY(fapi2::putScom(i_target, MBARPC0Q_REG[l_mca_pos], l_mbarpc0_data));

        // Step 2 - In MBASTR0Q, enable STR entry
        FAPI_TRY(fapi2::getScom(i_target, MBASTR0Q_REG[l_mca_pos], l_mbastr0_data));
        l_mbastr0_data.writeBit<MCA_MBASTR0Q_CFG_STR_ENABLE>(ENABLE);
        l_mbastr0_data.insertFromRight<MCA_MBASTR0Q_CFG_ENTER_STR_TIME, MCA_MBASTR0Q_CFG_ENTER_STR_TIME_LEN>(TIME_0);
        FAPI_TRY(fapi2::putScom(i_target, MBASTR0Q_REG[l_mca_pos], l_mbastr0_data));

        // Step 3 - In MBARPC0Q, enable power domain control.
        l_mbarpc0_data.writeBit<MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE>(ENABLE);
        FAPI_TRY(fapi2::putScom(i_target, MBARPC0Q_REG[l_mca_pos], l_mbarpc0_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper for trigger_csave. This subroutine assert RESET_n to trigger
/// the backup on nvdimm
/// @param[in] i_target - PROC_CHIP targetdefine
/// @param[in] l_mca_pos - The MCA position relative to the PROC
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode assert_resetn( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target, const uint8_t l_mca_pos)
{
    FAPI_ASSERT((l_mca_pos < PORTS_PER_MODULE),
                fapi2::MSS_RESETN_MCA_OUT_OF_RANGE().
                set_PROC_TARGET(i_target).
                set_MCA_POS(l_mca_pos),
                "Invalid port number %u provided", l_mca_pos);

    FAPI_DBG("Asserting RESETn on port %d.", l_mca_pos);

    {
        fapi2::buffer<uint64_t> l_farb5q_data;
        constexpr uint64_t LOW = 0;

        FAPI_TRY(fapi2::getScom(i_target, FARB5Q_REG[l_mca_pos], l_farb5q_data));
        l_farb5q_data.writeBit<MCA_MBA_FARB5Q_CFG_DDR_RESETN>(LOW);
        FAPI_TRY(fapi2::putScom(i_target, FARB5Q_REG[l_mca_pos], l_farb5q_data));
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

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SBE_NVDIMM_IN_PORT, i_target, l_nvdimm_port_bitmap) );

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

fapi_try_exit:
    return fapi2::current_err;
}

}//ns nvdimm

}//ns workarounds

}//ns mss
