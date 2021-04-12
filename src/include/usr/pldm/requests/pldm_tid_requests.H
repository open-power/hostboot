/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_tid_requests.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef PLDM_TID_REQUESTS_H
#define PLDM_TID_REQUESTS_H

/* @file pldm_tid_requests.H
 *
 * This file defines the APIs for PLDM TID (Terminus ID) operations
 */

#include <errl/errlentry.H>

namespace PLDM
{

/*
 * @brief Requests the BMC's Terminus ID (TID). Upon the receipt of this
 * request, the BMC will send back a setEventReceiver command to HB.
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t getTID();

} //namespace PLDM
#endif
