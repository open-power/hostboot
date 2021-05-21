/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSendMemConfig.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#include <sys/mm.h>     // mm_virt_to_phys
#include <errno.h>

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
        // Assumed the virtual pages returned by malloc() are backed by contiguous physical pages

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

        // POPULATED DUMP of indirect BUFFER
        SBE_TRACFBIN("POPULATED l_sbeMemAlloc:",
                     l_sbeMemAlloc, sizeof(SbePsu::MemConfigData_t));

        // DUMP out PSU COMMAND BUFFER
        SBE_TRACFBIN("Send Memory Config full command:",
                     &l_psuCommand, sizeof(l_psuCommand));

        // Create a PSU response message
        SbePsu::psuResponse l_psuResponse;

        bool command_unsupported = false;

        // Make the call to perform the PSU Chip Operation
        l_err = SbePsu::getTheInstance().performPsuChipOp(
                        i_pProc,
                        &l_psuCommand,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_MEM_CONFIG_REQ_USED_REGS,
                        SbePsu::SBE_MEM_CONFIG_RSP_USED_REGS,
                        SbePsu::COMMAND_SUPPORT_OPTIONAL, // No error when operation is unsupported
                        &command_unsupported);

        if (l_err)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeMemConfig: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );

            break;
        }
        else if ( command_unsupported )
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeMemConfig: ERROR: SBE firmware "
                       "does not support PSU sending Memory configuration information" );

            break;
        }
        else if (SBE_PRI_OPERATION_SUCCESSFUL != l_psuResponse.primaryStatus)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeMemConfig: ERROR: "
                       "Call to performPsuChipOp failed. Returned primary status "
                       "(0x%.4X) and secondary status (0x%.4X)",
                        l_psuResponse.primaryStatus,
                        l_psuResponse.secondaryStatus);

            /*
             * @errortype        ERRL_SEV_INFORMATIONAL
             * @moduleid         SBEIO_PSU
             * @reasoncode       SBEIO_PSU_SEND
             * @userdata1        The PROC Target HUID
             * @userdata2[00:31] PSU response, primary status
             * @userdata2[32:63] PSU response, secondary status
             * @devdesc          Software problem, call to performPsuChipOp failed
             *                   when sending Memory configuration info.
             * @custdesc         A software error occurred during system boot
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             SBEIO_PSU,
                                             SBEIO_PSU_SEND,
                                             get_huid(i_pProc),
                                             TWO_UINT32_TO_UINT64(
                                                         l_psuResponse.primaryStatus,
                                                         l_psuResponse.secondaryStatus ),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            // Collect the entire command and response buffers
            SBE_TRACFBIN("Send Memory Config full command:",
                         &l_psuCommand, sizeof(l_psuCommand));
            SBE_TRACFBIN("Send Memory Config full response:",
                         &l_psuResponse, sizeof(l_psuResponse));

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

            /*
             * @errortype        ERRL_SEV_INFORMATIONAL
             * @moduleid         SBEIO_PSU
             * @reasoncode       SBEIO_PSU_COUNT_UNEXPECTED
             * @userdata1        The PROC Target HUID
             * @userdata2[00:31] i_type TYPE_PMIC TYPE_GENERIC_I2C_DEVICE TYPE_OCMB_CHIP
             * @userdata2[32:63] l_max  How many of the TYPE we expected as MAX
             * @devdesc          Unexpected counts during getMemConfigInfo
             * @custdesc         A software error occurred during system boot
             */
            errlHndl_t l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             SBEIO_PSU,
                                             SBEIO_PSU_COUNT_UNEXPECTED,
                                             get_huid(i_pProc),
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
            const ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                = l_Target->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

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
