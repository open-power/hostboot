/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_port.H
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef __MSS_EXP_PORT_H_
#define __MSS_EXP_PORT_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>

namespace mss
{

//////////////////////////////////////////////////////////////
// Traits values for EXPLORER
//////////////////////////////////////////////////////////////
///
/// @class Traits and policy class for port code - specialization for Explorer. The target of registers is TARGET_TYPE_OCMB_CHIP
///
template<>
class portTraits< mss::mc_type::EXPLORER >
{
    public:
        // PORT_TYPE
        static constexpr fapi2::TargetType PORT_TYPE = fapi2::TARGET_TYPE_MEM_PORT;

        // scom register definition
        static constexpr uint64_t MBARPC0Q_REG = EXPLR_SRQ_MBARPC0Q;

        static constexpr uint64_t FARB0Q_REG = EXPLR_SRQ_MBA_FARB0Q;
        static constexpr uint64_t FARB5Q_REG = EXPLR_SRQ_MBA_FARB5Q;
        static constexpr uint64_t FARB6Q_REG = EXPLR_SRQ_MBA_FARB6Q;
        static constexpr uint64_t FARB9Q_REG = EXPLR_SRQ_MBA_FARB9Q;
        static constexpr uint64_t REFRESH_REG = EXPLR_SRQ_MBAREF0Q;
        static constexpr uint64_t ECC_REG = EXPLR_RDF_RECR;
        static constexpr uint64_t DSM0Q_REG = EXPLR_SRQ_MBA_DSM0Q;
        static constexpr uint64_t FWMS_REG = EXPLR_RDF_FWMS0;

        static constexpr uint64_t RRQ_REG = EXPLR_SRQ_MBA_RRQ0Q;
        static constexpr uint64_t WRQ_REG = EXPLR_SRQ_MBA_WRQ0Q;

        static constexpr uint64_t MAGIC_NUMBER_SIM = 765;
        static constexpr uint64_t MAGIC_NUMBER_NOT_SIM = 196605;

        // scom register field definition
        enum
        {
            CFG_MIN_MAX_DOMAINS_ENABLE = EXPLR_SRQ_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE,
            CFG_CCS_INST_RESET_ENABLE = EXPLR_SRQ_MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE,
            CFG_DDR_RESETN = EXPLR_SRQ_MBA_FARB5Q_CFG_DDR_RESETN,
            CFG_CCS_ADDR_MUX_SEL = EXPLR_SRQ_MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL,
            //TODO: It's not defined in scom register header file. Change this once it's available in scom address header file
            CFG_INIT_COMPLETE = 32, //EXPLR_SRQ_MBA_FARB6Q_CFG_INIT_COMPLETE,
            CFG_ZQ_PER_CAL_ENABLE = EXPLR_SRQ_MBA_FARB9Q_CFG_ZQ_PER_CAL_ENABLE,

            REFRESH_ENABLE = EXPLR_SRQ_MBAREF0Q_CFG_REFRESH_ENABLE,

            ECC_CHECK_DISABLE = EXPLR_RDF_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CHECK_CORRECT,
            ECC_CORRECT_DISABLE = EXPLR_RDF_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CORRECT,
            ECC_USE_ADDR_HASH = EXPLR_RDF_RECR_MBSECCQ_USE_ADDRESS_HASH,

            PORT_FAIL_DISABLE = EXPLR_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE,
            DFI_INIT_START = EXPLR_SRQ_MBA_FARB0Q_CFG_INIT_START,
            RCD_RECOVERY_DISABLE = EXPLR_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY,

            RECR_ENABLE_UE_NOISE_WINDOW = EXPLR_RDF_RECR_MBSECCQ_ENABLE_UE_NOISE_WINDOW,
            RECR_TCE_CORRECTION = EXPLR_RDF_RECR_MBSECCQ_ENABLE_TCE_CORRECTION,
            RECR_MBSECCQ_DATA_INVERSION = EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION,
            RECR_MBSECCQ_DATA_INVERSION_LEN = EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION_LEN,

            DSM0Q_RDTAG_DLY = EXPLR_SRQ_MBA_DSM0Q_CFG_RDTAG_DLY,
            DSM0Q_RDTAG_DLY_LEN = EXPLR_SRQ_MBA_DSM0Q_CFG_RDTAG_DLY_LEN,
            DSM0Q_WRDONE_DLY = EXPLR_SRQ_MBA_DSM0Q_CFG_WRDONE_DLY,
            DSM0Q_WRDONE_DLY_LEN = EXPLR_SRQ_MBA_DSM0Q_CFG_WRDONE_DLY_LEN,
            FARB0Q_RCD_PROTECTION_TIME = EXPLR_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME,
            FARB0Q_RCD_PROTECTION_TIME_LEN = EXPLR_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN,

            FWMS0_MARK = EXPLR_RDF_FWMS0_MARK,
            FWMS0_MARK_LEN = EXPLR_RDF_FWMS0_MARK_LEN,
            FWMS0_EXIT_1 = EXPLR_RDF_FWMS0_EXIT_1,

            RRQ_FIFO_MODE = EXPLR_SRQ_MBA_RRQ0Q_CFG_RRQ_FIFO_MODE,
            WRQ_FIFO_MODE = EXPLR_SRQ_MBA_WRQ0Q_CFG_WRQ_FIFO_MODE,
        };
};

///
/// @brief ATTR_MSS_MEM_MVPD_FWMS getter
/// @param[in] const ref to the TARGET_TYPE_OCMB_CHIP
/// @param[out] uint32_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Mark store records from OCMB VPD. The array dimension is [port][mark]. Explorer
/// only has one port so only [0][mark] is used in explorer.
///
template<>
inline fapi2::ReturnCode mvpd_fwms< mss::mc_type::EXPLORER >(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint32_t (&o_array)[mss::MARK_STORE_COUNT])
{
    return mss::attr::get_mvpd_fwms(i_target, o_array);
}

/// @brief Get the attributes for the reorder queue setting
/// @param[in] const ref to the mc target
/// @param[out] uint8_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Contains the settings for write/read reorder
/// queue
///
template< >
inline fapi2::ReturnCode reorder_queue_setting<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint8_t& o_value)
{
    return mss::attr::get_reorder_queue_setting(i_target, o_value);
}

}// mss

#endif
