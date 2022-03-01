/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSendMemConfig.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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

#include <errl/errlmanager.H>                  // errlHndl_t
#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips
#include <sbeio/sbeioreasoncodes.H>            // SBEIO_PSU, SBEIO_PSU_SEND
#include <sbeio/sbeioif.H>
#include <sys/mm.h>                            // mm_virt_to_phys
#include <errno.h>
#include <sbeio/sbe_utils.H>                   // SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES
#include <errl/errlreasoncodes.H>              // ERRL_UDT_NOFORMAT
#include <targeting/common/mfgFlagAccessors.H> // areAllSrcsTerminating

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio, "getMemConfigInfo: " printf_string,##args)

namespace SBEIO
{
using namespace TARGETING;

// See below for function description, this is the forward declaration
uint32_t getMemConfigInfo(const TargetHandle_t i_pProc,
                           CLASS i_class,
                           TYPE i_type,
                           uint32_t i_max_number,
                           SbePsu::MemConfigData_t * io_buffer);


 /** @brief Get PMIC Health Check Data from the SBE
 *
 *  @return nullptr if no error else an error log
 */
errlHndl_t getPmicHlthCheckData()
{
    errlHndl_t l_err(nullptr);
    bool l_pmic_health_log = true;

    TRACFCOMP(g_trac_sbeio, ENTER_MRK"getPmicHlthCheckData");

    //Allocate and align memory due to SBE requirements
    void* l_sbeMemAlloc = nullptr;
    SBEIO::sbeAllocationHandle_t l_alignedMemHandle { };
    uint64_t l_pmicHlthCheckDataSize = SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES;
    l_alignedMemHandle = sbeMalloc(l_pmicHlthCheckDataSize, l_sbeMemAlloc);

    do
    {
        TargetHandleList functionalProcChipList;
        getAllChips(functionalProcChipList, TYPE_PROC, true);
        for (const auto & l_pProc: functionalProcChipList)
        {
            union versionUnion{
                uint32_t sbe_version_combo;
                uint16_t sbe_sub_version[2];
            };
            versionUnion sbe_version_data = { };
            auto l_sbeVersion = l_pProc->getAttr<ATTR_SBE_VERSION_INFO>();
            sbe_version_data.sbe_version_combo = l_sbeVersion;
            TRACDCOMP(g_trac_sbeio, "MAJOR sbe_sub_version[0]=0x%X", sbe_version_data.sbe_sub_version[0]);
            TRACDCOMP(g_trac_sbeio, "MINOR sbe_sub_version[1]=0x%X", sbe_version_data.sbe_sub_version[1]);

            TargetHandleList l_TargetList;
            // Get the targets associated with the PROC target based on i_class and i_type
            // UTIL_FILTER_FUNCTIONAL for the Health Check Data
            getChildAffinityTargetsByState( l_TargetList,
                                            l_pProc,
                                            CLASS_NA,
                                            TYPE_OCMB_CHIP,
                                            UTIL_FILTER_FUNCTIONAL);
            TRACFCOMP( g_trac_sbeio, "getPmicHlthCheckData PROC HUID=0x%X OCMB_CHIP targets found=%d",
                get_huid(l_pProc), l_TargetList.size());
            for (const auto & l_Target: l_TargetList)
            {
                l_pmic_health_log = true; // loop each time to maybe get something
                const ATTR_FAPI_POS_type l_fapiPos = l_Target->getAttr<ATTR_FAPI_POS>();
                uint8_t l_InstanceId = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;
                TRACFCOMP( g_trac_sbeio, "getPmicHlthCheckData PROC HUID=0x%X OCMB HUID=0x%X l_InstanceId=%d",
                    get_huid(l_pProc), get_huid(l_Target), l_InstanceId);
                // Create a PSU command message and initialize it with Health Check specific flags
                SbePsu::psuCommand l_psuCommand(
                    SbePsu::SBE_REQUIRE_RESPONSE,                 // control flag
                    SbePsu::SBE_PSU_GENERIC_MESSAGE,              // command class
                    SbePsu::SBE_CMD_PMIC_HEALTH_CHECK_DATA);      // command (0x0C)
                memset(l_alignedMemHandle.dataPtr, 0, l_pmicHlthCheckDataSize);

                // SBE consumes a physical address
                // Assume the virtual pages returned by malloc() are backed by contiguous physical pages

                TRACFCOMP(g_trac_sbeio, "getPmicHlthCheckData: SBE indirect data at physical address 0x%lx "
                    "dataPtr=0x%X SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES=%d SBE_TARGET_TYPE_OCMB_CHIP=0x%X l_sbeMemAlloc=0x%X",
                    l_alignedMemHandle.physAddr, l_alignedMemHandle.dataPtr, SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES,
                    SBE_TARGET_TYPE_OCMB_CHIP, l_sbeMemAlloc);

                l_psuCommand.cd7_getPmicHlthCheckData_DataAddr = l_alignedMemHandle.physAddr;
                l_psuCommand.cd7_getPmicHlthCheckData_MbxReg1_OCMB_TYPE = SBE_TARGET_TYPE_OCMB_CHIP;
                l_psuCommand.cd7_getPmicHlthCheckData_MbxReg1_InstanceId = l_InstanceId;

                // Create a PSU response message
                SbePsu::psuResponse l_psuResponse;

                bool command_unsupported = false;

                // Make the call to perform the PSU Chip Operation
                l_err = SbePsu::getTheInstance().performPsuChipOp(
                            l_pProc,
                            &l_psuCommand,
                            &l_psuResponse,
                            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                            SbePsu::SBE_HEALTH_CHECK_DATA_REQ_USED_REGS,
                            SbePsu::SBE_HEALTH_CHECK_DATA_RSP_USED_REGS,
                            SbePsu::COMMAND_SUPPORT_OPTIONAL,
                            &command_unsupported);

                if ( command_unsupported )
                {
                    // Traces have already been logged
                    TRACFCOMP( g_trac_sbeio, ERR_MRK"getPmicHlthCheckData: SBE firmware "
                               "does not support PSU getPmicHlthCheckData information for "
                               "PROC HUID=0x%X OCMB HUID=0x%X", get_huid(l_pProc), get_huid(l_Target));
                    break;
                }

                if (l_err)
                {
                    TRACFCOMP( g_trac_sbeio, ERR_MRK"getPmicHlthCheckData: ERROR: "
                               "Call to performPsuChipOp failed, error returned for PROC HUID=0x%X "
                               "OCMB HUID=0x%X l_InstanceId=%d",
                               get_huid(l_pProc), get_huid(l_Target), l_InstanceId);
                    l_pmic_health_log = false;
                    l_err->collectTrace(SBEIO_COMP_NAME);
                    errlCommit(l_err, SBEIO_COMP_ID);

                    // We will log the data later to show an entry for this Target even though we had
                    // a problem getting its Health Check Data so we will show an entry, otherwise it will
                    // be a missing entry and lead to tracking down the why it is missing versus we know
                    // it is missing due to the l_pmic_health_log flag saying we were unable to get any good data, etc.
                }

                uint8_t l_pmic_revision = 0;
                uint8_t l_pmic_status = 0;

                TRACFCOMP ( g_trac_sbeio, "getPmicHlthCheckData: l_psuResponse.pmic_health_check_data_size=%d",
                    l_psuResponse.pmic_health_check_data_size);

                if (l_psuResponse.pmic_health_check_data_size > 0)
                {
                    l_pmic_revision = reinterpret_cast<SbePsu::pmic_health_data_t *>(l_alignedMemHandle.dataPtr)->pmic_revision;
                    l_pmic_status = reinterpret_cast<SbePsu::pmic_health_data_t *>(l_alignedMemHandle.dataPtr)->pmic_status;
                }
                else
                {
                    // We have no data to log, but no explicit ERRORS
                    l_pmic_health_log = false; // we will log PMIC Health Check Data -NOT- available
                }

                TRACFCOMP( g_trac_sbeio, "getPmicHlthCheckData: l_pmic_revision=0x%X l_pmic_status=0x%X",
                    l_pmic_revision, l_pmic_status);

                // See HWSV hwcoSbeSvc.C
                if ((l_pmic_status == SbePsu::SBE_N_MODE) || (l_pmic_status == SbePsu::SBE_LOST) ||
                   (l_pmic_status == SbePsu::SBE_GI2C_FAIL) || (l_pmic_status == SbePsu::SBE_DIMM_NOT_4U))
                {
                    l_pmic_health_log = false; // flag PMIC Health Check Data to aide in problem determination
                    if (l_pmic_status != SbePsu::SBE_DIMM_NOT_4U)
                    {
                        // Produce a visible log in Mfg Mode for failed health check
                        if (TARGETING::areAllSrcsTerminating())
                        {
                            /*@
                             * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                             * @reasoncode       SBEIO_PMIC_FAILED_HEALTH_CHECK
                             * @userdata1[00:31] PROC Target HUID
                             * @userdata1[32:63] OCMB Target HUID
                             * @userdata2[00:07] l_pmic_revision
                             * @userdata2[08:15] l_pmic_status
                             * @userdata2[16:23] l_InstanceId
                             * @userdata2[24:31] l_pmic_health_log <-- True if we should have non-zero addFFDC data
                             * @userdata2[32:47] l_psuResponse.primaryStatus
                             * @userdata2[48:63] l_psuResponse.secondaryStatus
                             * @devdesc          PMIC Health Check Data Failed in Mfg Mode
                             * @custdesc         PMIC Health Check Data Failed in Mfg Mode
                             */
                            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                             SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                             SBEIO_PMIC_FAILED_HEALTH_CHECK,
                                                             TWO_UINT32_TO_UINT64(
                                                                         get_huid(l_pProc),
                                                                         get_huid(l_Target)),
                                                             TWO_UINT32_TO_UINT64(
                                                                         FOUR_UINT8_TO_UINT32(
                                                                             l_pmic_revision,
                                                                             l_pmic_status,
                                                                             l_InstanceId,
                                                                             l_pmic_health_log),
                                                                         TWO_UINT16_TO_UINT32(
                                                                             l_psuResponse.primaryStatus,
                                                                             l_psuResponse.secondaryStatus)));

                            // If MFG mode add a HW Callout to properly identify the location code,
                            // but continue to create the Health Check Data entry to show a complete
                            // set of expected logs for OCMBs as usual, additional data logged may
                            // aide in root cause problem determination
                            //
                            // Identify this OCMB for the MFG check failure
                            l_err->addHwCallout( l_Target,
                                                 HWAS::SRCI_PRIORITY_HIGH,
                                                 HWAS::NO_DECONFIG,
                                                 HWAS::GARD_NULL);
                            l_err->collectTrace(SBEIO_COMP_NAME);
                            errlCommit(l_err, SBEIO_COMP_ID);
                        }
                    }
                }

                // Currently primaryStatus and secondaryStatus return zeros
                // even when Non functional targets are selected, seems like it should return
                // SBE_PRI_INVALID_DATA (SBE_SEC_OCMB_TARGET_NOT_FUNCTIONAL)
                //
                // See sbecmdpmictelemetry.C
                //
                // *NOTE* - even if the primaryStatus and secondaryStatus get fixed/changed
                // this logic will handle both current implementation and any future mods
                //
                // Summary - We are logging all the data we can to aide analysis
                TRACFCOMP( g_trac_sbeio, ERR_MRK"getPmicHlthCheckData: PMIC "
                           "Health Check Data for "
                           "PROC HUID=0x%X OCMB HUID=0x%X "
                           "l_psuResponse.pmic_health_check_data_size=%d "
                           "l_pmic_revision=0x%X l_pmic_status=0x%X "
                           "l_InstanceId=%d l_pmic_health_log=%d "
                           "l_psuResponse.primaryStatus=0x%X "
                           "l_psuResponse.secondaryStatus=0x%X",
                            get_huid(l_pProc), get_huid(l_Target),
                            l_psuResponse.pmic_health_check_data_size,
                            l_pmic_revision, l_pmic_status,
                            l_InstanceId, l_pmic_health_log,
                            l_psuResponse.primaryStatus,
                            l_psuResponse.secondaryStatus);
                /*@
                 * @moduleid         SBEIO_PSU_PMIC_HEALTH_CHECK
                 * @reasoncode       SBEIO_PMIC_HEALTH_CHECK_DATA
                 * @userdata1[00:31] PROC Target HUID
                 * @userdata1[32:63] OCMB Target HUID
                 * @userdata2[00:07] l_pmic_revision
                 * @userdata2[08:15] l_pmic_status
                 * @userdata2[16:23] l_InstanceId
                 * @userdata2[24:31] l_pmic_health_log <-- True if we should have non-zero addFFDC data
                 * @userdata2[32:47] l_psuResponse.primaryStatus
                 * @userdata2[48:63] l_psuResponse.secondaryStatus
                 * @devdesc          PMIC Health Check Data
                 * @custdesc         PMIC Health Check Data
                 */
                l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                 SBEIO_PSU_PMIC_HEALTH_CHECK,
                                                 SBEIO_PMIC_HEALTH_CHECK_DATA,
                                                 TWO_UINT32_TO_UINT64(
                                                             get_huid(l_pProc),
                                                             get_huid(l_Target)),
                                                 TWO_UINT32_TO_UINT64(
                                                             FOUR_UINT8_TO_UINT32(
                                                                 l_pmic_revision,
                                                                 l_pmic_status,
                                                                 l_InstanceId,
                                                                 l_pmic_health_log),
                                                             TWO_UINT16_TO_UINT32(
                                                                 l_psuResponse.primaryStatus,
                                                                 l_psuResponse.secondaryStatus)));
                // Identify this OCMB for the Health Check Data Log
                l_err->addHwCallout( l_Target,
                                     HWAS::SRCI_PRIORITY_LOW,
                                     HWAS::NO_DECONFIG,
                                     HWAS::GARD_NULL);

                if (l_psuResponse.pmic_health_check_data_size > 0)
                {
                    l_err->addFFDC( SBEIO_COMP_ID,
                                l_alignedMemHandle.dataPtr,
                                l_psuResponse.pmic_health_check_data_size,
                                1,                           // Version
                                ERRORLOG::ERRL_UDT_NOFORMAT, // parser ignores data
                                false );                     // merge
                }

                l_err->collectTrace(SBEIO_COMP_NAME);
                l_err->updateActionFlags(ERRORLOG::ERRL_ACTIONS_CALL_HOME);
                errlCommit(l_err, SBEIO_COMP_ID);

            } // end for l_Target
        } // end for l_pProc
    } while (0);
    // Free the buffer
    sbeFree(l_alignedMemHandle);

    TRACFCOMP(g_trac_sbeio, EXIT_MRK "getPmicHlthCheckData");

    return l_err;
}; // getPmicHlthCheckData


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
    }

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
        for (const auto & l_Target: l_TargetList)
        {
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
            if (l_Target->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_dynamic_i2cInfo.devAddr))
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
