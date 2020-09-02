/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSendOcmbConfig.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
* @file sbe_psuSendOcmbConfig.C
* @brief Send all OCMB configuration information, for a PROC, to the SBE
*/

#include <errl/errlmanager.H>                  // errlHndl_t
#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips
#include <sbeio/sbeioreasoncodes.H>            // SBEIO_PSU, SBEIO_PSU_SEND
#include <sbeio/sbeioif.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio, "getOcmbConfigInfo: " printf_string,##args)

namespace SBEIO
{
using namespace TARGETING;

// Forward declarion of getOcmbConfigInfo
uint32_t getOcmbConfigInfo(const TargetHandle_t i_pProc,
                           SbePsu::psuCommand &o_psuCommand);


 /** @brief Populate the PS Command with OCMB target configuration info
 *          and send to the SBE
 *
 *  @param[in] i_pProc - The PROC target to extract the OCMB targets from
 *  @return nullptr if no error else an error log
 */
errlHndl_t psuSendSbeOcmbConfig(const TargetHandle_t i_pProc)
{
    errlHndl_t l_err(nullptr);

    // Validate and verify that the target passed in is indeed a PROC
    assert( TYPE_PROC == i_pProc->getAttr<ATTR_TYPE>(),
            "Expected a target of type PROC but recieved a target of type 0x%.4X",
            i_pProc->getAttr<ATTR_TYPE>() );

    TRACFCOMP(g_trac_sbeio, ENTER_MRK"psuSendSbeOcmbConfig: PROC target HUID 0x%8X",
                            get_huid(i_pProc) );

    do
    {
        // Create a PSU command message and initialize it with OCMB Config specific flags
        SbePsu::psuCommand l_psuCommand(
                    SbePsu::SBE_REQUIRE_RESPONSE |
                    SbePsu::SBE_REQUIRE_ACK,          // control flags
                    SbePsu::SBE_PSU_GENERIC_MESSAGE,  // command class (0xD7)
                    SbePsu::SBE_PSU_OCMB_CONFIG);     // command (0x09)

        // Populate the body of the PSU command message
        if ( !getOcmbConfigInfo(i_pProc, l_psuCommand) )
        {
            // If no OCMB targets have been processed then no point in continuing
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
                        SbePsu::SBE_REQ_SEND_OCMB_CONFIG_REGS,
                        SbePsu::SBE_RSP_SEND_OCMB_CONFIG_REGS);

        if (l_err)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeOcmbConfig: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );

            break;
        }
        else if ( SBE_PRI_INVALID_COMMAND       == l_psuResponse.primaryStatus   &&
                  SBE_SEC_COMMAND_NOT_SUPPORTED == l_psuResponse.secondaryStatus )
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeOcmbConfig: ERROR: SBE firmware "
                       "does not support PSU sending OCMB configuration information" );

            // Do not pass back any errors
            delete l_err;
            l_err = nullptr;
            break;
        }
        else if (SBE_PRI_OPERATION_SUCCESSFUL != l_psuResponse.primaryStatus)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendSbeOcmbConfig: ERROR: "
                       "Call to performPsuChipOp failed. Returned primary status "
                       "(0x%.4X) and secondary status (0x%.4X)",
                        l_psuResponse.primaryStatus,
                        l_psuResponse.secondaryStatus);

            /*
             * @errortype        ERRL_SEV_UNRECOVERABLE
             * @moduleid         SBEIO_PSU
             * @reasoncode       SBEIO_PSU_SEND
             * @userdata1        The PROC Target HUID
             * @userdata2[00:31] PSU response, primary status
             * @userdata2[32:63] PSU response, secondary status
             * @devdesc          Software problem, call to performPsuChipOp failed
             *                   when sending OCMB configuration info.
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
            SBE_TRACFBIN("Send OCMB config full command:",
                         &l_psuCommand, sizeof(l_psuCommand));
            SBE_TRACFBIN("Send OCMB config full response:",
                         &l_psuResponse, sizeof(l_psuResponse));

            break;
        }


    } while (0);


    TRACFCOMP(g_trac_sbeio, EXIT_MRK "psuSendSbeOcmbConfig");

    return l_err;
}; // psuSendSbeOcmbConfig


 /** @brief Populate the PS Command with OCMB target configuration info
 *
 *  @param[in] i_pProc - The PROC target to extract the OCMB targets from
 *  @param[out] o_psuCommand - Structure to populate with OCMB target config info
 *  @return The number of OCMB target instances processed
 */
uint32_t getOcmbConfigInfo(const TargetHandle_t i_pProc,
                           SbePsu::psuCommand &o_psuCommand)
{
    // Return the number OCMBs found and processed
    uint32_t l_numberOfOcmbsProcessed(0);

    // Create a vector of Target pointers to hold the OCMB targets.
    TargetHandleList l_ocmbTargetList;

    // Get the OCMBs associated with the PROC target
    getChildAffinityTargetsByState( l_ocmbTargetList,
                                    i_pProc,
                                    CLASS_CHIP,
                                    TYPE_OCMB_CHIP,
                                    UTIL_FILTER_ALL);

    if ( l_ocmbTargetList.size() == 0 )
    {
        TRACFCOMP(g_trac_sbeio, INFO_MRK"psuSendSbeOcmbConfig: No OCMB targets found, "
                                "therefore no OCMB config info gathered to send to SBE");
    }
    else
    {
        TRACFCOMP(g_trac_sbeio, INFO_MRK"psuSendSbeOcmbConfig: %d OCMBs found", l_ocmbTargetList.size());

        // Create a convenient handle, into the PSU command, to easily populate the
        // PSU command with the OCMB port info.
        uint8_t * l_ocmbPortArray = static_cast<uint8_t *>
                                      ( &(o_psuCommand.cd7_sendOcmbConfig_I0_port) );

        // Iterate thru the OCMB targets and gather the OCMB config info
        for (const auto & l_ocmbTarget: l_ocmbTargetList)
        {
            // Get the FAPI position of the OCMB target.  The FAPI position will
            // be used as an index into PSU command message.
            const ATTR_FAPI_POS_type l_fapiPos = l_ocmbTarget->getAttr<ATTR_FAPI_POS>();
            uint32_t l_arrayIndex = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS;

            // Get the FAPI I2C control info from the OCMB target. The port info
            // resides within the FAPI I2C control info.
            const ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                = l_ocmbTarget->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

            // Populate the OCMB port array (AKA the port info of the PSU command)
            // with the OCMB port, bounded by the max number of ports.
            l_ocmbPortArray[l_arrayIndex] = static_cast<uint8_t>(l_fapiI2cControlInfo.port);

            // Gather the functional state of the OCMB target
            const HwasState l_currentState = l_ocmbTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
            if (l_currentState.functional)
            {
                // If the OCMB is functional then set the correct bit in the functional state
                const uint16_t l_ocmbIsFunctional = 0x8000;
                o_psuCommand.cd7_sendOcmbConfig_function_state |= (l_ocmbIsFunctional >> l_arrayIndex);
            }

            if (!l_numberOfOcmbsProcessed)
            {
                // This is the first OCMB target being processed therefore populate
                // the PSU command with the OCMB target's engine and device address info
                o_psuCommand.cd7_sendOcmbConfig_engine  = l_fapiI2cControlInfo.engine;
                o_psuCommand.cd7_sendOcmbConfig_devAddr = l_fapiI2cControlInfo.devAddr;
            }
            else
            {
                // Sanity check.  Verify that all OCMB targets share the same engine
                //                and device address.
                assert(o_psuCommand.cd7_sendOcmbConfig_engine == l_fapiI2cControlInfo.engine,
                       "psuSendSbeOcmbConfig: Mismatch in engine");
                assert(o_psuCommand.cd7_sendOcmbConfig_devAddr == l_fapiI2cControlInfo.devAddr,
                       "psuSendSbeOcmbConfig: Mismatch in device address");
            }

            ++l_numberOfOcmbsProcessed;
        } // for (const auto & l_ocmbTarget: l_ocmbTargetList)
    } // if ( l_ocmbTargetList.size() == 0 ) ... else

    return l_numberOfOcmbsProcessed;
} // getOcmbConfigInfo


} // namespace SBEIO
