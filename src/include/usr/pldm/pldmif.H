/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldmif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef PLDMIF_H
#define PLDMIF_H

#include <sys/msg.h>
namespace PLDM
{

    /**
    * @brief This function is intended to be used by the MCTP resource
    *        provider when they find a PLDM message and want the PLDM
    *        resource provider to handle it
    *
    * @param[in] i_msg  ptr to PLDM message
    * @param[in] i_len  length of buffer containing PLDM message
    * @return void
    */
    void routeInboundMessage(uint8_t * i_msg, size_t i_len);
}

#endif