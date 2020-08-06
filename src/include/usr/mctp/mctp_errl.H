/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_errl.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

/* @file   mctp_errl.H
 *
 * @brief  Contains definitions for error-related utility functions.
 */

#ifndef MCTP_ERRL_H__
#define MCTP_ERRL_H__

#include <errl/errlentry.H>

namespace MCTP
{

/* @brief addBmcAndHypErrorCallouts
 *
 *        Collect MCTP traces, and add a high-priority callout to the BMC,
 *        a medium-priority callout to the hypervsior, and a low-priority
 *        callout to Hostboot to the error log.
 *
 * @param[in] i_errl  Error log to modify
 */
inline void addBmcAndHypErrorCallouts(const errlHndl_t i_errl)
{
    assert(i_errl != nullptr,
           "i_errl is nullptr in addBmcErrorCallouts");

    i_errl->collectTrace(MCTP_COMP_NAME);
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

}

#endif
