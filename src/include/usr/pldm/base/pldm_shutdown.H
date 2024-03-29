/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/base/pldm_shutdown.H $                   */
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

/**
 * @file pldm_shutdown.H
 *
 * @brief Contains declarations for PLDM the shutdown interface.
 */

namespace PLDM
{

/** @brief Types of soft poweroffs for requestSoftPowerOff.
 */
enum poweroff_initiator_t
{
    POWEROFF_BMC_INITIATED,
    POWEROFF_HOST_INITIATED
};

/* @brief  Initiate an asynchronous graceful poweroff.
 *
 * @param[in] i_initiator  Who initiated the poweroff.
 *
 * @note If the BMC initiates a graceful poweroff, then the host will leave
 * cutting the chassis power to the BMC. If the host initiates the poweroff,
 * then the host itself is responsible for requesting to cut the chassis power
 * when it is done shutting down. This function fully handles both of these cases.
 */
void requestSoftPowerOff(poweroff_initiator_t i_initiator);

}
