/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSendMemConfig.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
/**
* @file sbe_psuSendMemConfig.C
* @brief Send Memory configuration information, for a PROC, to the SBE
*/

#include "targeting/common/util.H"
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <trace/interface.H>
#include <algorithm>
#include <cstddef>
#include <errl/errlmanager.H>                  // errlHndl_t
#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips
#include <sbeio/sbeioreasoncodes.H>            // SBEIO_PSU, SBEIO_PSU_SEND
#include <sbeio/sbeioif.H>
#include <sys/mm.h>                            // mm_virt_to_phys
#include <errno.h>
#include <sbeio/sbe_utils.H>                   // SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES
#include <targeting/common/mfgFlagAccessors.H> // areAllSrcsTerminating
#include <vpd/vpd_if.H>
#include <targeting/odyutil.H>                 // isOdysseyChip

#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <pmic_n_mode_detect.H>
#include <pmic_periodic_telemetry_ddr5.H>
#include <pmic_health_check_ddr5.H>
#include <pmic_periodic_telemetry_utils_ddr5.H>
#include <pmic_health_check_utils_ddr5.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio, "getMemConfigInfo: " printf_string,##args)

namespace SBEIO
{
using namespace TARGETING;

/** @brief Determine if the OCMB target should run the Health Check.
 *
 *  @param[in] i_ddr5_health_not_telemetry_check A flag set from the registered
 *             callback which indicates if this is for a DDR5 HWP Health Check
 *  @param[in] i_memType     The memory type
 *  @param[in] i_memModType  The memory module type
 *  @param[in] i_memHeight   The memory height
 *
 *  @return    bool to indicate to run DDR5 Health Check HWPs
 *
 *  Caller must pre-check the context of where this helper can be called.
 *
 *  This helper only validates the conditions for an OCMB target.
 */

bool isDDR5_Health_Check(bool i_ddr5_health_not_telemetry_check, SPD::spdMemType_t i_memType, SPD::spdModType_t i_memModType, SPD::dimmModHeight_t i_memHeight)
{
    bool l_evaluation = false; // Default to not run DDR5 HWP Health Check
    if ((i_ddr5_health_not_telemetry_check) && ((SPD::DDR5_TYPE == i_memType) && (SPD::MOD_TYPE_DDIMM == i_memModType) && (SPD::DDIMM_MOD_HEIGHT_4U == i_memHeight)))
    {
        // DDR5 OCMB should run the HWP for Health Check
        l_evaluation = true;
    }
    return l_evaluation;
}

// See below for function description, this is the forward declaration
uint32_t getMemConfigInfo(const TargetHandle_t i_pProc,
                           CLASS i_class,
                           TYPE i_type,
                           uint32_t i_max_number,
                           SbePsu::MemConfigData_t * io_buffer);

/** @brief Get PMIC Health Check Data from the HWP
 *
 *  @param[in] i_proc   The PROC to query for the related OCMBs.
 *  @param[in] i_ddr5_health_not_telemetry_check
 *                      A flag set from the registered callback which indicates
 *                      if this is for a HWP Health Check or HWP Telemetry Check
 *  @param[in] i_OCMBs  List of OCMBs
    @param[in] i_plid   PLID to associate error logs
 *  @return nullptr if no error else an error log
 */
errlHndl_t getMultiPmicHealthCheckData(Target * i_proc,
                                       bool i_ddr5_health_not_telemetry_check,
                                       const TARGETING::TargetHandleList& i_OCMBs,
                                       const uint32_t i_plid = 0)
{
    errlHndl_t l_err(nullptr); // normal l_err for local error handling

    // l_err_log is a single log, per proc, that will contain pmic telemetry or health
    // check data that is used to provide data analysis and call home information
    // for HMC managed systems.
    errlHndl_t l_err_log(nullptr);

    // DDR4 4U and DDR5 2U and 4U will always log Telemetry data, DDR5 uses this flag to properly manage logging
    // DDR5 Health Check will only create a log if the payload response size is greater than one data unit
    bool l_logs_available = true;

    static constexpr uint8_t DDR4_TELEMETRY_LOC_VERSION = 101;
    static constexpr uint8_t DDR4_TELEMETRY_FFDC_VERSION = 102;
    static constexpr uint8_t DDR5_TELEMETRY_LOC_VERSION = 103;
    static constexpr uint8_t DDR5_TELEMETRY_FFDC_VERSION = 104;
    static constexpr uint8_t DDR5_HEALTH_CHECK_LOC_VERSION = 105;
    static constexpr uint8_t DDR5_HEALTH_CHECK_FFDC_VERSION = 106;
    uint8_t l_version_loc = 0; // to hold the version for logging FFDC
    uint8_t l_version_data = 0; // to hold the version for logging FFDC

    TRACFCOMP(g_trac_sbeio, ENTER_MRK "getMultiPmicHealthCheckData OCMB count = %d", i_OCMBs.size());

    uint8_t l_list_index = 0;
    uint8_t l_pmic_combined_status   = 0; //mask for all pmic statuses for the SRC word 9

    uint32_t l_first_ocmb_huid_num = 0;
    uint32_t l_last_ocmb_huid_num = 0;

    uint32_t l_response_size = 0;

    uint32_t l_ocmb_pmic_data_size = SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES;
    uint8_t l_ocmb_pmic_data[l_ocmb_pmic_data_size] = {0};
    // consolidated_health_check_data is the super structure for DDR5
    static_assert(SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES >= std::max(sizeof(runtime_n_mode_telem_info),
            sizeof(mss::pmic::ddr5::consolidated_health_check_data)),
            "getMultiPmicHealthCheckData SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES TOO SMALL for PMIC structure");

    // Loop through OCMB list to collect PMIC telemetry data.
    for (const auto l_pOcmb: i_OCMBs)
    {
        SPD::spdMemType_t l_memType = SPD::MEM_TYPE_INVALID;
        SPD::spdModType_t l_memModType = SPD::MOD_TYPE_INVALID;
        SPD::dimmModHeight_t l_memHeight = SPD::DDIMM_MOD_HEIGHT_INVALID;
        errlHndl_t l_err = SPD::getMemInfo(l_pOcmb,l_memType,l_memModType,l_memHeight);
        TRACFCOMP( g_trac_sbeio, "getMultiPmicHealthCheckData OCMB HUID=0x%X OCMB_CHIP targets : %d of %d found ERRL=0x%X",
                get_huid(l_pOcmb), l_list_index+1, i_OCMBs.size(), ERRL_GETEID_SAFE(l_err_log));
        TRACFCOMP( g_trac_sbeio, "getMultiPmicHealthCheckData"
                " l_memType=0x%X (DDR4=0x%X DDR5=0x%X) l_memModType=0x%X l_memHeight=0x%X (4U=0x%X)",
                l_memType, SPD::DDR4_TYPE, SPD::DDR5_TYPE, l_memModType, l_memHeight, SPD::DDIMM_MOD_HEIGHT_4U);

        bool l_ddr5_run_health_check = isDDR5_Health_Check(i_ddr5_health_not_telemetry_check, l_memType, l_memModType, l_memHeight);
        TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData l_ddr5_run_health_check=0x%X i_ddr5_health_not_telemetry_check=0x%X",
                   l_ddr5_run_health_check, i_ddr5_health_not_telemetry_check);
        //  GATE KEEPING STEPS
        // If the input parm says we are performing the "Health Check" HWPs and we are not DDR5 4U we want to bail now
        // We do not disable the timers since on a multi-node system, i.e. Denali, we can have both Explorer nodes and/or Odyssey nodes
        //
        // The i_ddr5_health_not_telemetry_check is checking the entry point from the callback,
        // and the l_ddr5_run_health_check is checking if the OCMB qualifies to have the DDR5 Health Check HWPs run.
        //
        // The pair, l_ddr5_run_health_check and i_ddr5_health_not_telemetry_check, together compose the switches
        // to decide on characteristics of running which HWPs, or to bail.
        //
        // If the OCMB is a viable candidate to run the health check, but this is not the health check entry point bail.
        // Only when the DDR5 Telemetry call is requested do we want to proceed if the entry point is the health check.
        // This check qualifies the validity of the entry point in order to proceed.
        //     Entry Point             Type    isDDR5_Health_Check
        //      Telemetry            DDR4 2U            false           <== Will get filtered out later not to run Telemetry
        //      Telemetry            DDR4 4U            false
        //      Telemetry            DDR5 2U            false
        //      Telemetry            DDR5 4U            false
        //      Health Check         DDR4 2U            false
        //      Health Check         DDR4 4U            false
        //      Health Check         DDR5 2U            true
        //      Health Check         DDR5 4U            true
        //
        //  If the OCMB cannot run the health check bail, this kicks out the telemetry timer call for DDR5
        //  If the OCMB can run the health check and this is the health check timer then its allowed to proceed
        //  If we only looked at the qualification for isDDR5_Health_Check we would not allow the Telemetry calls to pass
        //  First clause is saying "its telemetry or not DDR5", second clause is saying "you are asking to come in the health check door"
        if ( (!l_ddr5_run_health_check) && i_ddr5_health_not_telemetry_check )
        {
            return nullptr; // No DDR5 Health Check so bail
        }
        if (l_err)
        {
            // This function is collecting additional "nice to have" data.
            // Since we couldn't get ddimm height, just continue, this is unlikely
            TRACFCOMP(g_trac_sbeio, ERR_MRK"getMultiPmicHealthCheckData: "
                        "Failed to get DDIMM Module height using OCMB[0x%X]. "
                        "Deleting error and leaving.",
                        get_huid(l_pOcmb));
            delete l_err;
            l_err = nullptr;
        }
        else if (((SPD::DDR4_TYPE == l_memType) && (SPD::MOD_TYPE_DDIMM == l_memModType) && (SPD::DDIMM_MOD_HEIGHT_4U == l_memHeight))
                 || ((SPD::DDR5_TYPE == l_memType) && (SPD::MOD_TYPE_DDIMM == l_memModType)))
        {
            // Conditions below rely on the fact that ONLY DDR4 and DDR5 meet the above requirements, any modifications to the above check
            // need to re-evaluate the conditional logic below and any associated helper functions in the future.
            TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData OCMB HUID=0x%X l_ddr5_run_health_check=%d i_ddr5_heatlh_not_telemetry_check=%d l_memHeight=0x%X (2U=0x20 4U=0x80)",
                          get_huid(l_pOcmb), l_ddr5_run_health_check, i_ddr5_health_not_telemetry_check, l_memHeight);
            if (l_err_log == nullptr)
            {
                if (l_ddr5_run_health_check)
                {
                    /*@
                     * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                     * @reasoncode       SBEIO_PMIC_HEALTH_CHECK_DATA_DDR5
                     * @userdata1[00:31] PROC Target HUID
                     * @userdata1[32:63] First OCMB Target HUID
                     * @userdata2[00:31] Last  OCMB Target HUID
                     * @userdata2[32:47] Reserved 0xFFFF default
                     * @userdata2[48:55] Number of OCMBs in log
                     * @userdata2[56:63] Worst pmic status
                     * @devdesc          PMIC Health Check Data
                     * @custdesc         PMIC Health Check Data
                     */
                    l_err_log = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                               SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                               SBEIO_PMIC_HEALTH_CHECK_DATA_DDR5);

                    // We have this here to only set the flag first time when the initial error log is created
                    // Later we will flip this true if DDR5 Health Check returns a payload that is needed to be logged
                    l_logs_available = false;
                }
                else if (SPD::DDR4_TYPE == l_memType)
                {
                    /*@
                     * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                     * @reasoncode       SBEIO_PMIC_HEALTH_CHECK_DATA
                     * @userdata1[00:31] PROC Target HUID
                     * @userdata1[32:63] First OCMB Target HUID
                     * @userdata2[00:31] Last  OCMB Target HUID
                     * @userdata2[32:47] Reserved 0xFFFF default
                     * @userdata2[48:55] Number of OCMBs in log
                     * @userdata2[56:63] Worst pmic status
                     * @devdesc          PMIC Health Check Data
                     * @custdesc         PMIC Health Check Data
                     */
                    l_err_log = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                               SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                               SBEIO_PMIC_HEALTH_CHECK_DATA);
                }
                // HWP for DDR5 Health Check has already been caught in the first conditional logic check
                // DDR4's are caught in above cases, so the ONLY case left is the DDR5 2U and 4U Telemetry check
                else if (!i_ddr5_health_not_telemetry_check) // if i_ddr5_health_not_telemetry check was set this is NOT Telemetry, so this is 2U and 4U Telemetry DDR5
                {
                    /*@
                     * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                     * @reasoncode       SBEIO_PMIC_TELEMETRY_DATA_DDR5
                     * @userdata1[00:31] PROC Target HUID
                     * @userdata1[32:63] First OCMB Target HUID
                     * @userdata2[00:31] Last  OCMB Target HUID
                     * @userdata2[32:47] Reserved 0xFFFF default
                     * @userdata2[48:55] Number of OCMBs in log
                     * @userdata2[56:63] Worst pmic status
                     * @devdesc          PMIC Telemetry Data
                     * @custdesc         PMIC Telemetry Data
                     */
                    l_err_log = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                               SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                               SBEIO_PMIC_TELEMETRY_DATA_DDR5);
                }
                else
                {
                    TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData DDR5 2U Health Check not applicable ERRL=0x%X OCMB HUID=0x%X",
                                   ERRL_GETEID_SAFE(l_err_log), get_huid(l_pOcmb));
                    l_list_index++; // this is just used for output in the traces
                    continue;
                }
            } // nullptr check
            const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2_ocmb_target( l_pOcmb );

            const ATTR_FAPI_POS_type l_fapiPos = l_pOcmb->getAttr<ATTR_FAPI_POS>();
            uint8_t l_InstanceId = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;

            fapi2::hwp_array_ostream l_pmic_data( (uint32_t*) &l_ocmb_pmic_data[0],
                                                    l_ocmb_pmic_data_size);
            fapi2::hwp_array_ostream l_pmic_data_ddr5( (uint32_t*) &l_ocmb_pmic_data[0],
                                                    l_ocmb_pmic_data_size);

            if (l_ddr5_run_health_check)
            {
                FAPI_INVOKE_HWP(l_err,
                                pmic_health_check_ddr5,
                                l_fapi2_ocmb_target,
                                l_pmic_data_ddr5 );
                l_version_loc = DDR5_HEALTH_CHECK_LOC_VERSION;
                l_version_data = DDR5_HEALTH_CHECK_FFDC_VERSION;
            }
            else if (SPD::DDR4_TYPE == l_memType)
            {
                FAPI_INVOKE_HWP(l_err,
                                pmic_n_mode_detect,
                                l_fapi2_ocmb_target,
                                l_pmic_data );
                l_version_loc = DDR4_TELEMETRY_LOC_VERSION;
                l_version_data = DDR4_TELEMETRY_FFDC_VERSION;
            }
            else if (!i_ddr5_health_not_telemetry_check) // DDR5 2U and 4U Telemetry
            {
                FAPI_INVOKE_HWP(l_err,
                                pmic_periodic_telemetry_ddr5,
                                l_fapi2_ocmb_target,
                                l_pmic_data_ddr5 );
                l_version_loc = DDR5_TELEMETRY_LOC_VERSION;
                l_version_data = DDR5_TELEMETRY_FFDC_VERSION;
            }
            // SRC user words must have first OCMB Huid and last OCMB Huid.
            if (l_first_ocmb_huid_num == 0)
            {
                l_first_ocmb_huid_num = get_huid(l_pOcmb);
            }
            // In case of one OCMB both first and last would be the same.
            l_last_ocmb_huid_num = get_huid(l_pOcmb);

            uint8_t l_pmic_revision = 0;
            uint8_t l_pmic_status = N_PLUS_1; // Default to a good redundancy state

            auto l_pmic_health_data =
                * reinterpret_cast<runtime_n_mode_telem_info*>(&l_ocmb_pmic_data[0]);
            auto l_pmic_health_data_ddr5 =
                * reinterpret_cast<mss::pmic::ddr5::periodic_telemetry_data*>(&l_ocmb_pmic_data[0]);
            auto l_pmic_health_data_ddr5_consolidated =
                * reinterpret_cast<mss::pmic::ddr5::consolidated_health_check_data*>(&l_ocmb_pmic_data[0]);

            if (SPD::DDR4_TYPE == l_memType)
            {
                l_pmic_revision = l_pmic_health_data.iv_revision;
                l_pmic_status = l_pmic_health_data.iv_aggregate_error;
                l_response_size = l_pmic_data.getLength() * sizeof(fapi2::hwp_data_unit); // fapi2 ostream requires the unit size multiplication
            }
            else // DDR5_TYPE
            {
                // For DDR5 the consolidated_health_check_data struct is required which
                // is retrieved by calling the HWP pmic_health_check_ddr5
                l_pmic_revision = l_pmic_health_data_ddr5.iv_revision; // use ONLY on periodic_telemetry_data struct
                l_response_size = l_pmic_data_ddr5.getLength() * sizeof(fapi2::hwp_data_unit); // fapi2 ostream requires the unit size multiplication
                // DDR5 Telemetry uses the iv_aggregate_pmic_state, if DDR5 Health Check will be updated in the l_ddr5_run_health_check below
                l_pmic_status = l_pmic_health_data_ddr5.iv_aggregate_pmic_state; // DDR5 Telemetry, use ONLY on periodic_telemetry_data struct
                if (l_ddr5_run_health_check)
                {
                    l_pmic_status = l_pmic_health_data_ddr5_consolidated.iv_health_check.iv_aggregate_state; // use ONLY on consolidated_health_check_data struct
                    l_pmic_revision = l_pmic_health_data_ddr5_consolidated.iv_health_check.iv_revision; // use ONLY on consolidated_health_check_data struct
                    // If the response size is one data unit, then the DDR5 Health Check HWP is indicating for Hostboot not to log anything
                    // For DDR5 Health Check the only logs produced will be if the payload from the HWP comes back greater than one unit (hwp_data_unit)
                    if ( l_response_size > (1 * sizeof(fapi2::hwp_data_unit)) ) // We have something to log from DDR5 Health Check
                    {
                        l_logs_available = true; // flag so we know we should log later, most healthy cases we should not log anything
                    }
                    TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData l_pmic_status=0x%X l_logs_available=%d l_list_index=%d HUID=0x%X ERRL=0x%X",
                                             l_pmic_status, l_logs_available, l_list_index, get_huid(l_pOcmb), ERRL_GETEID_SAFE(l_err_log));
                }
            }

            if (l_err)
            {
                // This function is collecting additional "nice to have" data.
                // Since we couldn't get PMIC telemetry data, commit and try next OCMB.
                TRACFCOMP( g_trac_sbeio, ERR_MRK"PMIC data: ERROR: "
                        "PROC HUID=0x%X  OCMB HUID=0x%X l_InstanceId=%d"
                        "FAPI PLID=0x%X",
                        get_huid(i_proc), get_huid(l_pOcmb), l_InstanceId,
                        l_err->plid());
                l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                // Produce a visible log in Mfg Mode for failed health check
                if( TARGETING::areAllSrcsTerminating() )
                {
                    l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                }
                l_err->collectTrace(SBEIO_COMP_NAME);
                errlCommit(l_err, SBEIO_COMP_ID);
                continue;
            }

            // These traces need to be close to the OCMB HWP execution to prevent trace wrapping.
            l_err_log->collectTrace(SBEIO_COMP_NAME);

            // DDR4 Update mask for this pmic status in the SRC word 9
            // DDR5 l_pmic_status will be set by Telemetry iv_aggregate_pmic_state (periodic_telemetry_data struct)
            //     and Health Check iv_aggregate_state (consolidated_health_check_data struct)
            TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData HUID=0x%X l_pmic_status=0x%X l_pmic_combined_status=0x%X",
                          get_huid(l_pOcmb), l_pmic_status, l_pmic_combined_status);
            if( l_pmic_status > l_pmic_combined_status )
            {
                l_pmic_combined_status = l_pmic_status;
            }

            // DDR4 Produce a visible log in Mfg Mode for failed health check
            // DDR5 Telemetry will NOT trigger this condition, DDR5 Health Check sets the l_pmic_status
            errlHndl_t mfg_err = nullptr;
            if( (l_pmic_status != N_PLUS_1) && TARGETING::areAllSrcsTerminating() )
            {
                /*@
                 * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                 * @reasoncode       SBEIO_PMIC_FAILED_HEALTH_CHECK
                 * @userdata1[00:31] PROC Target HUID
                 * @userdata1[32:63] OCMB Target HUID
                 * @userdata2[00:07] PMIC Revision
                 * @userdata2[08:15] PMIC Status (see pmic_n_mode_detect.H)
                 * @userdata2[16:23] OCMB position relative to proc
                 * @userdata2[24:31] True if we should have non-zero addFFDC data
                 * @userdata2[32:47] deprecated: l_psuResponse.primaryStatus
                 * @userdata2[48:63] deprecated: l_psuResponse.secondaryStatus
                 * @devdesc          PMIC Health Check Data Failed in Mfg Mode
                 * @custdesc         PMIC Health Check Data Failed in Mfg Mode
                 */
                mfg_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                   SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                   SBEIO_PMIC_FAILED_HEALTH_CHECK,
                                                   TWO_UINT32_TO_UINT64(
                                                     get_huid(i_proc),
                                                     get_huid(l_pOcmb)),
                                                   TWO_UINT32_TO_UINT64(
                                                     FOUR_UINT8_TO_UINT32(
                                                       l_pmic_revision,
                                                       l_pmic_status,
                                                       l_InstanceId,
                                                       true),
                                                     0)
                                                   );

                // If MFG mode add a HW Callout to properly identify the location code,
                // but continue to create the Health Check Data entry to show a complete
                // set of expected logs for OCMBs as usual, additional data logged may
                // aide in root cause problem determination
                //
                // Identify this OCMB for the MFG check failure
                mfg_err->addHwCallout( l_pOcmb,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
                mfg_err->collectTrace(FAPI_IMP_TRACE_NAME,256);
                mfg_err->collectTrace(FAPI_TRACE_NAME,384);
            }
            if (l_response_size == 0)
            {
                // We have no data to log, but no explicit ERRORS
                TRACFCOMP(g_trac_sbeio,"getMultiPmicHealthCheckData: l_response_size=%d, informational only, look for OCMB location string",
                                                        l_response_size);
                //NOTE: response size 0 will log the OCMB location string with data of 0
                //        then we will move onto next OCMB
            }

            // Get sudo Location string for OCMB
            //       ND:#-Pxx-Cyy
            //          # is the NODE
            //             Pxx-Cyy is the OCMB location string
            std::vector<char> full_location_code;

            // Add marker 'ND:' to the full_location_code string.
            auto l_node_code = "ND";
            full_location_code.insert(end(full_location_code),
                                    l_node_code,
                                    l_node_code + strlen(l_node_code));

            // Add the node number to the full_location_code string.
            Target * l_parent_node =  getParent(l_pOcmb , TYPE_NODE);
            uint8_t l_position = l_parent_node->getAttr<ATTR_ORDINAL_ID>();
            char l_actual_node[16] = "";
            sprintf( l_actual_node, "%02d", l_position);

            full_location_code.insert(end(full_location_code),
                                    l_actual_node,
                                    l_actual_node + strlen(l_actual_node));

            // Add the hyphen seperator to the full_location_code string.
            full_location_code.push_back('-');

            // Add the OCMB location to the string.
            ATTR_STATIC_ABS_LOCATION_CODE_type static_abs_location_code { };
            if( !l_pOcmb->tryGetAttr
                <TARGETING::ATTR_STATIC_ABS_LOCATION_CODE>(static_abs_location_code)
                        && (strlen(static_abs_location_code) == 0))
            {
                TRACFCOMP(g_trac_sbeio,"getMultiPmicHealthCheckData: part Location"
                        " string failed for OCMB HUID=0x%X", get_huid(l_pOcmb));
            }
            else
            {
                full_location_code.insert(end(full_location_code),
                                        static_abs_location_code,
                                        static_abs_location_code +
                                        strlen(static_abs_location_code));
                full_location_code.push_back('\0');

                // Identify this OCMB for the Health Check Data Log
                l_err_log->addFFDC( SBEIO_COMP_ID,
                        full_location_code.data(),
                        0x10,                      // 16 bytes of location ex:ND:#-Pxx-Cyy
                        l_version_loc,             // Version
                        SBEIO_UDT_LOC,             // parser ignores data
                        false );                   // merge

                // OCMB Health Check Data Log
                l_err_log->addFFDC( SBEIO_COMP_ID,
                        &l_ocmb_pmic_data[0],
                        l_response_size,
                        l_version_data,              // Version
                        SBEIO_UDT_PMIC_HEALTH,       // parser ignores data
                        false );                     // merge

                // Add to mfg log too
                if( mfg_err )
                {
                    // Identify this OCMB for the Health Check Data Log
                    mfg_err->addFFDC( SBEIO_COMP_ID,
                        full_location_code.data(),
                        0x10,                      // 16 bytes of location ex:ND:#-Pxx-Cyy
                        l_version_loc,             // Version
                        SBEIO_UDT_LOC,             // parser ignores data
                        false );                   // merge

                    // OCMB Health Check Data Log
                    mfg_err->addFFDC( SBEIO_COMP_ID,
                        &l_ocmb_pmic_data[0],
                        l_response_size,
                        l_version_data,              // Version
                        SBEIO_UDT_PMIC_HEALTH,       // parser ignores data
                        false );                     // merge
                }
            }

            // Commit the manufacturing log now if we have one
            if( mfg_err )
            {
                mfg_err->collectTrace(SBEIO_COMP_NAME);
                errlCommit(mfg_err, SBEIO_COMP_ID);
            }

            // Summary - We are logging all the data we can to aide analysis
            TRACFCOMP( g_trac_sbeio,"getMultiPmicHealthCheckData: PMIC "
                    "Health Check Data for "
                    "PROC HUID=0x%X OCMB HUID=0x%X "
                    "l_response_size=%d "
                    "pmic_revision=0x%X pmic_status=0x%X "
                    "l_InstanceId=%d OCMB location=%s ",
                    get_huid(i_proc), get_huid(l_pOcmb),
                    l_response_size,
                    l_pmic_revision,
                    l_pmic_status,
                    l_InstanceId,
                    full_location_code.data());


        } // end if DDR4 4U DDIMM, DDR5 4U DDIMM and DDR5 2U DDIMM
        l_list_index++;
    } // end for loop on OCMBs

    TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData ERRL=0x%X l_logs_available=%d", ERRL_GETEID_SAFE(l_err_log), l_logs_available);
    // when no l_err_log we have nothing to log so all good
    // we skipped the 2U Health Checks because they were not applicable (only 4U runs the Health Check calls)
    // l_logs_available is used to manage the DDR5 Health Check logging which is managed by size of the payload returned from HWP
    if (l_err_log && l_logs_available)

    {
        TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData Logs Available ERRL=0x%X", ERRL_GETEID_SAFE(l_err_log));
        uint32_t l_hw_data_request = 0xFFFF0000 | (i_OCMBs.size()<<8) | l_pmic_combined_status;

        uint64_t l_UserData1 = ((uint64_t)get_huid(i_proc) ) << 32 | l_first_ocmb_huid_num;
        l_err_log->addUserData1( l_UserData1 );

        uint64_t l_UserData2 = ((uint64_t)l_last_ocmb_huid_num ) << 32 | l_hw_data_request;
        l_err_log->addUserData2( l_UserData2 );

        // Any collectTrace points have been previously collected (closer to the HWP operation)
        // to ensure the relevant traces are in context and have not been lost by wrapping.

        // This is to attach PLID number to This error log from caller so
        //     they can be associated together
        if (i_plid != 0)
        {
            l_err_log->plid(i_plid);
        }

        errlCommit(l_err_log, SBEIO_COMP_ID);
    } // End telemetry error log add Data/Trace, and PLID if passed in.
    else if (!l_logs_available)
    {
            TRACFCOMP(g_trac_sbeio, "getMultiPmicHealthCheckData No Logs Available ERRL=0x%X", ERRL_GETEID_SAFE(l_err_log));
            delete l_err_log;
            l_err_log = nullptr;
    }

    return l_err;
}; // getMultiPmicHealthCheckData

void getTelemetryData(Target * i_ocmb, const uint32_t i_plid)
{
    // PRD is the primary consumer of this interface.
    // The subsequent call paths NOW support determining if DDR4 or DDR5 and if 2U or 4U supported
    // This is basically a wrapper call to distinguish Telemetry calls versus Health Check calls
    get4uDdimmPmicHealthCheckData(i_ocmb, i_plid); // keeping the existing get4uDdimmPmicHealthCheckData call for backwards compatibility
}

void get4uDdimmPmicHealthCheckData(Target * i_ocmb, const uint32_t i_plid)
{
    do {
        SPD::spdMemType_t l_memType = SPD::MEM_TYPE_INVALID;
        SPD::spdModType_t l_memModType = SPD::MOD_TYPE_INVALID;
        SPD::dimmModHeight_t l_memHeight = SPD::DDIMM_MOD_HEIGHT_INVALID;
        errlHndl_t errl = SPD::getMemInfo(i_ocmb,l_memType,l_memModType,l_memHeight);
        if (errl)
        {
            // This function is collecting additional "nice to have" data.
            // Since we couldn't get ddimm height, just leave.
            TRACFCOMP(g_trac_sbeio, ERR_MRK"get4uDdimmPmicHealthCheckData: "
                      "Failed to get DDIMM Module Height using OCMB[0x%X]. Deleting error and leaving.",
                      get_huid(i_ocmb));
            delete errl;
            errl = nullptr;
            break;
        }

        if (((SPD::DDR4_TYPE == l_memType) && (SPD::MOD_TYPE_DDIMM == l_memModType) && (SPD::DDIMM_MOD_HEIGHT_4U == l_memHeight))
                     || ((SPD::DDR5_TYPE == l_memType) && (SPD::MOD_TYPE_DDIMM == l_memModType)))
        {
            TargetHandleList parentProc;
            getParentAffinityTargetsByState(parentProc,
                                            i_ocmb,
                                            CLASS_NA,
                                            TYPE_PROC,
                                            UTIL_FILTER_ALL);
            if (parentProc.size())
            {
                Target * l_proc = parentProc[0];
                TargetHandleList l_first_TargetList;
                l_first_TargetList.push_back( i_ocmb);
                bool l_ddr5_health_check = false; // DDR5 Health Check flag, we are doing Telemetry calls here so set false
                errl = getMultiPmicHealthCheckData(l_proc, l_ddr5_health_check, l_first_TargetList, i_plid);
                if (errl)
                {
                    // This function is collecting additional "nice to have" data.
                    // If it fails to do so then delete and move on.
                    TRACFCOMP(g_trac_sbeio, ERR_MRK"get4uDdimmPmicHealthCheckData: "
                              "Failed to get PMIC health check data for OCMB[0x%X]. Deleting error and leaving.",
                              get_huid(i_ocmb));
                    delete errl;
                    errl = nullptr;
                    break;
                }
            }
        }
    } while(0);
}

/** @brief Get PMIC Health Check Data from the SBE
 *
 *   @param[in] i_target_proc Either a processor target to perform health checks on a specific processor,
 *              or nullptr to perform health checks on all processors.
 *   @param[in] i_ddr5_health_not_telemetry_check A flag set from the registered
 *              callback which indicates if this is for a HWP Health
 *              Check or HWP Telemetry Check
 *
 *   @return nullptr if no error else an error log
 */
errlHndl_t getPmicHealthCheckData(TargetHandle_t i_target_proc, bool i_ddr5_health_not_telemetry_check)
{
    errlHndl_t l_err(nullptr);
    TargetHandleList l_procs;
    TRACFCOMP(g_trac_sbeio, ENTER_MRK"getPmicHealthCheckData: i_ddr5_health_not_telemetry_check=%d", i_ddr5_health_not_telemetry_check);

    if (i_target_proc == nullptr)
    {
        // If running a check for all processors, gather all chips
        TRACFCOMP(g_trac_sbeio, "getPmicHealthCheckData: Running for ALL processors");
        getAllChips(l_procs, TYPE_PROC, true);
    }
    else
    {
        // If running a check for a specific processor, put it (and only it) into the vector
        TRACFCOMP(g_trac_sbeio, "getPmicHealthCheckData: Running for proc=0x%X", get_huid(i_target_proc));
        l_procs.push_back(i_target_proc);
    }

    // Iterate over all procs in the list
    for (const auto & l_target : l_procs)
    {
        TargetHandleList l_ocmb_list;
        // Get the targets associated with the PROC target based on i_class and i_type
        // UTIL_FILTER_FUNCTIONAL for the Health Check Data
        getChildAffinityTargetsByState( l_ocmb_list,
                                        l_target,
                                        CLASS_NA,
                                        TYPE_OCMB_CHIP,
                                        UTIL_FILTER_FUNCTIONAL);
        TRACFCOMP( g_trac_sbeio, "getPmicHealthCheckData: PROC HUID=0x%X OCMB_CHIP targets found=%d",
        get_huid(l_target), l_ocmb_list.size());

        // Send all OCMBs from this Processor for PMIC to be logged.
        uint8_t l_ocmb_target_list_size = l_ocmb_list.size();

        // Define a variable determining chunk size of
        // OCMBs we want to operate on
        constexpr uint8_t group_size = 4;
        uint8_t l_index = 0;

        while (!l_ocmb_list.empty())
        {
            auto end_chunk = l_ocmb_list.end();

            // if we have more than group_size set next call to appropriate index
            if (l_ocmb_target_list_size > group_size)
            {
                end_chunk = l_ocmb_list.begin() + group_size;
                l_ocmb_target_list_size -= group_size;
            }
            // else we have a list with less than group_size

            // Call this with list beginning until the end. count.
            l_err = getMultiPmicHealthCheckData(i_target_proc, i_ddr5_health_not_telemetry_check, { l_ocmb_list.begin(), end_chunk });

            // Set target list to end to get out of loop.
            //     or to the end of the last OCMB for next pass
            //     through loop.
            l_ocmb_list.erase(l_ocmb_list.begin(), end_chunk);

            // If we had an error, trace that info, but don't commit the error.
            if (l_err)
            {
                TRACFCOMP(g_trac_sbeio, "getPmicHealthCheckData: failed to get health check data for "
                    "OCMBs %d thru %d on processor HUID = %X, reason = %X",
                    l_index, std::min((uint8_t)(l_index + group_size - 1), l_ocmb_target_list_size),
                    get_huid(l_target), l_err->reasonCode());
                delete l_err;
                l_err = nullptr;
            }

            l_index += group_size; // for nice debug counting
        }
    }
    TRACFCOMP(g_trac_sbeio, EXIT_MRK "getPmicHealthCheckData");
    return l_err;
}

 /** @brief Populate the PSU Command with Memory target configuration info
 *          and send to the SBE
 *
 *  @param[in] i_pProc - The PROC target to extract the memory config targets from
 *  @return nullptr if no error else an error log
 */
errlHndl_t psuSendSbeMemConfig(const TargetHandle_t i_pProc)
{
    errlHndl_t l_err(nullptr);

    // Validate and verify that the target passed in is indeed a PROC
    assert( TYPE_PROC == i_pProc->getAttr<ATTR_TYPE>(),
            "psuSendSbeMemConfig: Expected a target of type PROC but received a target of type 0x%.4X",
            i_pProc->getAttr<ATTR_TYPE>() );

    TRACFCOMP(g_trac_sbeio, ENTER_MRK"psuSendSbeMemConfig: PROC target HUID 0x%X",
                            get_huid(i_pProc) );

    //Allocate and align memory due to SBE requirements
    void* l_sbeMemAlloc = nullptr;
    SBEIO::sbeAllocationHandle_t l_MemConfigAlloc { };
    do
    {
        // Create a PSU command message and initialize it with Memory Config specific flags
        SbePsu::psuCommand l_psuCommand(
                    SbePsu::SBE_REQUIRE_RESPONSE |
                    SbePsu::SBE_REQUIRE_ACK,          // control flags
                    SbePsu::SBE_PSU_GENERIC_MESSAGE,  // command class (0xD7)
                    SbePsu::SBE_CMD_MEM_CONFIG);      // command (0x0B)

        l_MemConfigAlloc = sbeMalloc(sizeof(SbePsu::MemConfigData_t), l_sbeMemAlloc);

        // memset the virtual address to zeros to assure data buffer properly initialized
        memset( l_sbeMemAlloc, 0, sizeof(SbePsu::MemConfigData_t));

        // SBE consumes a physical address
        // Assume the virtual pages returned by malloc() are backed by contiguous physical pages

        TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: SBE indirect data at address 0x%lx "
            "l_sbeMemAlloc=0x%X sizeof(MemConfigData_t)=0x%X",
            l_MemConfigAlloc.physAddr, l_sbeMemAlloc, sizeof(SbePsu::MemConfigData_t));

        l_psuCommand.cd7_sendMemConfig_DataAddr = l_MemConfigAlloc.physAddr;

        // Populate the indirect memory buffer to pass in the PSU command message
        // sbeMalloc'd aligned buffer structure packed (MemConfigData_t)
        // so ok to proceed with populating structure alignment friendly
        uint32_t l_total_targets_processed = 0;
        uint32_t l_targets_processed = 0;

        l_targets_processed = getMemConfigInfo(i_pProc, CLASS_NA, TYPE_PMIC,
                                        SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER,
                                        reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));

        l_total_targets_processed = l_targets_processed;

        TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: POST PMICs: current l_targets_processed=%d",
                      l_targets_processed);

        l_targets_processed = getMemConfigInfo(i_pProc, CLASS_NA, TYPE_GENERIC_I2C_DEVICE,
                                  SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER,
                                  reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));
        l_total_targets_processed += l_targets_processed;
        TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: POST GENERIC I2Cs: current l_targets_processed=%d",
                      l_targets_processed);

        l_targets_processed = getMemConfigInfo(i_pProc, CLASS_CHIP, TYPE_OCMB_CHIP,
                                  SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER,
                                  reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));
        l_total_targets_processed += l_targets_processed;
        TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: POST OCMBs: current l_targets_processed=%d",
                      l_targets_processed);

        TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: TOTALS: current l_total_targets_processed=%d",
                      l_total_targets_processed);

        if ( l_total_targets_processed == 0 )
        {
            // If no targets have been processed then skip sending any config info
            TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: Skipped sending any config info, "
                "NO TARGETS processed for PROC HUID=0x%X", get_huid(i_pProc));
            break;
        }

        // Create a PSU response message
        SbePsu::psuResponse l_psuResponse;

        // Make the call to perform the PSU Chip Operation
        l_err = SbePsu::getTheInstance().performPsuChipOp(
                        i_pProc,
                        &l_psuCommand,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_MEM_CONFIG_REQ_USED_REGS,
                        SbePsu::SBE_MEM_CONFIG_RSP_USED_REGS,
                        SbePsu::COMMAND_SUPPORT_OPTIONAL);

        if (l_err)
        {
            // Traces have already been logged
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeMemConfig: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );

            break;
        }
    } while (0);
    // Free the buffer
    sbeFree(l_MemConfigAlloc);

    TRACFCOMP(g_trac_sbeio, EXIT_MRK "psuSendSbeMemConfig");

    return l_err;
}; // psuSendSbeMemConfig


 /** @brief Populate the PS Command with Memory target configuration info
 *
 *  @param[in] i_pProc       - The PROC target to extract the memory targets from
 *  @param[in] i_class       - The CLASS of the targets to query
 *  @param[in] i_type        - The TYPE of the targets to query
 *  @param[in] i_max_number  - The MAX number of possible targets in the model
 *  @param[in/out] io_buffer - The SBE aligned malloc buffer for indirect data send
 *                             Caller must initialize the buffer
 *  @return The number of memory target instances processed
 */
uint32_t getMemConfigInfo(const TargetHandle_t i_pProc,
                           CLASS i_class,
                           TYPE i_type,
                           uint32_t i_max_number,
                           SbePsu::MemConfigData_t * io_buffer)
{

    // Return the number of Targets found and processed
    TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: ENTRY WORKING on "
        "i_type=0x%X PROC HUID=0x%X io_buffer=0x%X",
        i_type, get_huid(i_pProc), io_buffer);
    uint32_t l_numberOfTargetsProcessed(0);
    uint32_t l_max(0);
    bool l_max_exceeded =false;
    TargetHandleList l_TargetList;

    // Get the targets associated with the PROC target based on i_class and i_type
    // UTIL_FILTER_ALL will retrieve ALL BLUEPRINT
    getChildAffinityTargetsByState( l_TargetList,
                                    i_pProc,
                                    i_class,
                                    i_type,
                                    UTIL_FILTER_ALL);

    // Be sure to populate the callers buffer
    // Data population of the callers buffer is done here to contain
    // the buffer management logic in a single location
    // to provide full visibility and maintainability for future

    //  i2c_config_version is consumed by SBE, we only set it here for
    //  later SBE consumption
    io_buffer->i2c_config_version = SbePsu::SBE_PSU_I2C_CONFIG_VERSION_LATEST;

    // see sbe_psudd.H struct MemConfigData_t

    //  i2c_config_types_supported is consumed by SBE, we only set it here for
    //  later SBE consumption for any version/size validations
    io_buffer->i2c_config_types_supported = SbePsu::SBE_PSU_I2C_CONFIG_TYPES_SUPPORTED;

    io_buffer->pmic_chips_max_number = SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER;
    io_buffer->gi2c_chips_max_number = SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER;
    io_buffer->ocmb_chips_max_number = SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;

    TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: version=0x%X config_types_supported=%d",
              io_buffer->i2c_config_version, io_buffer->i2c_config_types_supported);
    TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: Max entries supported for "
              "PMIC=%d GENERIC=%d OCMB=%d",
              io_buffer->pmic_chips_max_number, io_buffer->gi2c_chips_max_number,
              io_buffer->ocmb_chips_max_number);
    TRACFCOMP(g_trac_sbeio, INFO_MRK"sbe_psuSendMemConfig.C:getMemConfigInfo: "
              "PROC HUID=0x%X targets found=%d io_buffer=0x%X i_type=0x%X",
              get_huid(i_pProc), l_TargetList.size(), io_buffer, i_type);

    switch (i_type)
    {
    case (TYPE_PMIC):
    {
        TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig:getMemConfigInfo: Validating MAX entries "
                  "for TYPE_PMIC PMICs found=%d MAX PMICs=%d",
                  l_TargetList.size(), (io_buffer->pmic_chips_max_number));
        if (l_TargetList.size() > (io_buffer->pmic_chips_max_number))
        {
            l_max_exceeded = true;
            l_max = (io_buffer->pmic_chips_max_number);
            TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: Exceeded MAX entries "
                      "for TYPE_PMIC");
        }
        break;
    }
    case (TYPE_GENERIC_I2C_DEVICE):
    {
        TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig:getMemConfigInfo: Validating MAX entries "
                  "for TYPE_GENERIC_I2C_DEVICE GI2Cs found=%d MAX GI2Cs=%d",
                  l_TargetList.size(), (io_buffer->gi2c_chips_max_number));
        if (l_TargetList.size() > (io_buffer->gi2c_chips_max_number))
        {
            l_max_exceeded = true;
            l_max = (io_buffer->gi2c_chips_max_number);
            TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: Exceeded MAX entries "
                      "for TYPE_GENERIC_I2C_DEVICE");
        }
        break;
    }
    case (TYPE_OCMB_CHIP):
    {
        TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig:getMemConfigInfo: Validating MAX entries "
                  "for TYPE_OCMB_CHIP OCMBs found=%d MAX OCMBs=%d",
                  l_TargetList.size(), (io_buffer->ocmb_chips_max_number));
        if (l_TargetList.size() > (io_buffer->ocmb_chips_max_number))
        {
            l_max_exceeded = true;
            l_max = (io_buffer->ocmb_chips_max_number);
            TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: Exceeded MAX entries "
                      "for TYPE_OCMB_CHIP");
        }
        break;
    }
    default:
    {
        TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: DEFAULT for unrecognized MAX Checks");
        // We will SKIP handling the unrecognized case in the next steps below
        break;
    }
    } // end of switch

    if ( (l_TargetList.size() == 0) || l_max_exceeded )
    {
        TRACFCOMP(g_trac_sbeio, INFO_MRK"sbe_psuSendMemConfig.C:getMemConfigInfo: No targets "
                  "found in BLUEPRINT OR TOO many found for i_type=0x%X", i_type);

        if (l_max_exceeded)
        {

            /*@
             * @moduleid         SBEIO_PSU
             * @reasoncode       SBEIO_PSU_COUNT_UNEXPECTED
             * @userdata1[00:31] The PROC Target HUID
             * @userdata1[32:63] l_TargetList.size MAX
             * @userdata2[00:31] i_type TYPE_PMIC TYPE_GENERIC_I2C_DEVICE TYPE_OCMB_CHIP
             * @userdata2[32:63] l_max  How many of the TYPE we expected as MAX
             * @devdesc          Unexpected counts during getMemConfigInfo
             * @custdesc         A software error occurred during system boot
             */
            errlHndl_t l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                        SBEIO_PSU,
                                                        SBEIO_PSU_COUNT_UNEXPECTED,
                                                        TWO_UINT32_TO_UINT64(
                                                            get_huid(i_pProc),
                                                            l_TargetList.size() ),
                                                        TWO_UINT32_TO_UINT64(
                                                            i_type,
                                                            l_max ),
                                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            errlCommit(l_err, SBEIO_COMP_ID);
        }
    }
    else
    {
        TRACFCOMP(g_trac_sbeio, INFO_MRK"sbe_psuSendMemConfig.C:getMemConfigInfo: START WORKING on "
                  "PROC HUID=0x%X targets found=%d io_buffer=0x%X i_type=0x%X",
                  get_huid(i_pProc), l_TargetList.size(), io_buffer, i_type);

        // Iterate thru the targets and gather the config info
        // Please Note:
        // We do not want to tell SBE about the DDR5 parts. The reasons are
        // that the DDR5 Odyssey devices will use a different protocol (I2CR)
        // for SCOM accessess and HW dumps. Also, it helps in keeping the
        // P10 SBE code from having to 'special-case' Odyssey support.
        for (const auto & l_Target: l_TargetList)
        {
            if (i_type == TYPE_OCMB_CHIP)
            {
                // Skip if Odyssey
                if (TARGETING::UTIL::isOdysseyChip(l_Target))
                {
                    TRACFCOMP(g_trac_sbeio, INFO_MRK"sbe_psuSendMemConfig.C:getMemConfigInfo:"
                              " Skipping Odyssey Target HUID=0x%X i_type=0x%X",
                              get_huid(l_Target), i_type);
                    continue;
                }
            }
            else
            {
                // Get the parent OCMB of this target.
                const auto l_parentOCMB = getImmediateParentByAffinity(l_Target);
                // Skip if the parent is an Odyssey chip
                if (TARGETING::UTIL::isOdysseyChip(l_parentOCMB))
                {
                    TRACFCOMP(g_trac_sbeio, INFO_MRK"sbe_psuSendMemConfig.C:getMemConfigInfo:"
                              " Skipping Odyssey Target HUID=0x%X i_type=0x%X parent=0x%x",
                              get_huid(l_Target), i_type, get_huid(l_parentOCMB));
                    continue;
                }
            }

            // Get the FAPI position of the target.  The FAPI position will
            // be used as an index into PSU command message.
            const ATTR_FAPI_POS_type l_fapiPos = l_Target->getAttr<ATTR_FAPI_POS>();
            uint32_t l_arrayIndex = l_fapiPos % i_max_number;

            // Get the FAPI I2C control info from the target. The port, engine and devAddr
            // resides within the FAPI I2C control info.
            ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                = l_Target->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();


            ATTR_FAPI_I2C_CONTROL_INFO_type l_dynamic_i2cInfo = { };

            // If the target has dynamic device address attribute, then use that instead of the
            // read-only address found in ATTR_FAPI_I2C_CONTROL_INFO. We use the dynamic address
            // attribute because ATTR_FAPI_I2C_CONTROL_INFO is not writable and its difficult
            // to override complex attributes.
            if (l_Target->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>
                (l_dynamic_i2cInfo.devAddr))
            {
                l_fapiI2cControlInfo.devAddr = l_dynamic_i2cInfo.devAddr;
            }

            // Gather the functional and present state of the target
            const HwasState l_currentState = l_Target->getAttr<TARGETING::ATTR_HWAS_STATE>();

            switch (i_type)
            {
            case (TYPE_PMIC):
            {
                io_buffer->pmic_chips[l_arrayIndex].i2c_port  = l_fapiI2cControlInfo.port;
                io_buffer->pmic_chips[l_arrayIndex].i2c_engine  = l_fapiI2cControlInfo.engine;
                io_buffer->pmic_chips[l_arrayIndex].i2c_devAddr  = l_fapiI2cControlInfo.devAddr;
                io_buffer->pmic_chips[l_arrayIndex].i2c_functional = l_currentState.functional;
                io_buffer->pmic_chips[l_arrayIndex].i2c_present = l_currentState.present;
                break;
            }
            case (TYPE_GENERIC_I2C_DEVICE):
            {
                io_buffer->gi2c_chips[l_arrayIndex].i2c_port  = l_fapiI2cControlInfo.port;
                io_buffer->gi2c_chips[l_arrayIndex].i2c_engine  = l_fapiI2cControlInfo.engine;
                io_buffer->gi2c_chips[l_arrayIndex].i2c_devAddr  = l_fapiI2cControlInfo.devAddr;
                io_buffer->gi2c_chips[l_arrayIndex].i2c_functional = l_currentState.functional;
                io_buffer->gi2c_chips[l_arrayIndex].i2c_present = l_currentState.present;
                break;
            }
            case (TYPE_OCMB_CHIP):
            {
                io_buffer->ocmb_chips[l_arrayIndex].i2c_port  = l_fapiI2cControlInfo.port;
                io_buffer->ocmb_chips[l_arrayIndex].i2c_engine  = l_fapiI2cControlInfo.engine;
                io_buffer->ocmb_chips[l_arrayIndex].i2c_devAddr  = l_fapiI2cControlInfo.devAddr;
                io_buffer->ocmb_chips[l_arrayIndex].i2c_functional = l_currentState.functional;
                io_buffer->ocmb_chips[l_arrayIndex].i2c_present = l_currentState.present;
                break;
            }
            default:
            {
                TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: Unrecognized "
                          "i_type=0x%X, no data populated", i_type);
                break;
            }
            }

            ++l_numberOfTargetsProcessed;
        } // for (const auto & l_Target: l_TargetList)
    } // if ( l_TargetList.size() == 0 ) ... else

    TRACFCOMP(g_trac_sbeio, "sbe_psuSendMemConfig.C:getMemConfigInfo: EXIT "
        "io_buffer=0x%X l_numberOfTargetsProcessed=%d",
        io_buffer, l_numberOfTargetsProcessed);
    return l_numberOfTargetsProcessed;
} // getMemConfigInfo


} // namespace SBEIO
