/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_errl.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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

/* @file   pldm_errl.H
 *
 * @brief  Contains definitions for error-related utility functions.
 */

#ifndef PLDM_ERRL_H__
#define PLDM_ERRL_H__

#include <errl/errlentry.H>
#include <errl/errludstring.H>
#include <errl/errludattribute.H>
#include <openbmc/pldm/libpldm/include/libpldm/base.h>
#include <targeting/common/targetservice.H>

using namespace ERRORLOG;

namespace PLDM
{

/* @brief addBmcErrorCallouts
 *
 *        Collect PLDM traces, and add a high-priority callout to the BMC and a
 *        medium-priority callout to Hostboot to the error log.
 *
 * @param[in] i_errl  Error log to modify
 */
inline void addBmcErrorCallouts(const errlHndl_t i_errl)
{
    assert(i_errl != nullptr,
           "i_errl is nullptr in addBmcErrorCallouts");

    i_errl->collectTrace(PLDM_COMP_NAME);

    // Call out service processor / BMC firmware as high priority
    i_errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                HWAS::SRCI_PRIORITY_HIGH);

    // Call out Hostboot firmware as medium priority
    i_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_MED);
}

/* @brief addBmcAndHypErrorCallouts
 *
 *        Collect PLDM traces, and add a high-priority callout to the BMC,
 *        a medium-priority callout to the hypervsior, and a low-priority
 *        callout to Hostboot to the error log.
 *
 * @param[in] i_errl  Error log to modify
 */
inline void addBmcAndHypErrorCallouts(const errlHndl_t i_errl)
{
    assert(i_errl != nullptr,
           "i_errl is nullptr in addBmcErrorCallouts");

    i_errl->collectTrace(PLDM_COMP_NAME);
    i_errl->collectTrace(RUNTIME_COMP_NAME);

    // Call out service processor / BMC firmware as high priority
    i_errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                HWAS::SRCI_PRIORITY_HIGH);

    // Call out Hypervsior firmware as medium priority
    i_errl->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                HWAS::SRCI_PRIORITY_MED);

    // Call out Hostboot firmware as low priority
    i_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_LOW);
}

#ifndef CONFIG_FSP_BUILD
/* @brief addPdrCounts
 *
 *        Add the current count of PDRs sent to BMC and received from BMC
 *        into to the error log.
 *
 * @param[in] i_errl  Error log to modify
 */
inline void addPdrCounts(const errlHndl_t i_errl)
{
    if (i_errl != nullptr)
    {
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        ErrlUserDetailsAttribute(sys,TARGETING::ATTR_PLDM_BMC_PDR_COUNT).addToLog(i_errl);
        ErrlUserDetailsAttribute(sys,TARGETING::ATTR_PLDM_HB_PDR_COUNT).addToLog(i_errl);
    }
}
#endif

/**
 * @brief Cast raw binary data to a pldm_msg_hdr struct and return the 'type' member
 *
 * @param[in] i_response container holding the pldm response data as raw binary data
 *
 * @return uint8_t PLDM command type found
*/
template <typename container>
uint8_t getCommandType(const container& i_response)
{
    /* sendrecv_pldm_request should return error if response was too small */
    assert(i_response.size() >= sizeof(pldm_msg_hdr));
    return reinterpret_cast<const pldm_msg_hdr *>(i_response.data())->type;
}

/**
 * @brief Cast raw binary data to a pldm_msg_hdr struct and return the 'command' member
 *
 * @param[in] i_response container holding the pldm response data as raw binary data
 *
 * @return uint8_t PLDM command found
*/
template <typename container>
uint8_t getCommand(const container& i_response)
{
    /* sendrecv_pldm_request should return error if response was too small */
    assert(i_response.size() >= sizeof(pldm_msg_hdr));
    return reinterpret_cast<const pldm_msg_hdr *>(i_response.data())->command;
}

/**
 * @brief Lookup the command type, and the command in a PLDM response and attach it to
 *        a given error log as a User Details String.
 *
 * @param[in] i_errl Error log we would like command type and command data attached to
 * @param[in] i_response container holding the pldm response data as raw binary data
 *
 * @return uint8_t PLDM command type found
*/
template <typename container>
void addCmdInfo(const errlHndl_t i_errl,
                const container& i_response)
{
    assert(i_errl != nullptr, "nullptr passed to PLDM::addCmdInfo");
    char message[48] = { };
    snprintf(message, sizeof(message), "Command Type: 0x%x; Command: 0x%x",
             getCommandType(i_response), getCommand(i_response));
    ErrlUserDetailsString(message).addToLog(i_errl);
}

}

#endif
