/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/nodecommif.H $                     */
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
#ifndef __NODECOMMIF_H
#define __NODECOMMIF_H

#include <initservice/mboxRegs.H>
#include <errl/errlentry.H>

namespace SECUREBOOT
{

namespace NODECOMM
{

enum node_comm_link_mbox_info_t
{
    NCDD_MAX_LINK_ID       = 3,
    NCDD_MAX_MBOX_ID       = 1,
    NCDD_INVALID_LINK_MBOX = 0xFF,
};

/**
 *  @brief Execute a single transmission from one proc to another
 *         over the XBUS Link Mailbox facility
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr  Test completed successfully
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t nodeCommXbus2ProcTest(void);

/**
 *  @brief Runs the procedure for the drawers/nodes to exchange messages
 *         over the ABUS Link Mailbox facility
 *
 *  @return errHndl_t Error log handle indicating success or failure
 *  @retval nullptr  Procedure completed successfully
 *  @retval !nullptr Error log providing failure details
 */
errlHndl_t nodeCommAbusExchange(void);


} // End NODECOMM namespace

} // End SECUREBOOT namespace

#endif // End __NODECOMMIF_H

