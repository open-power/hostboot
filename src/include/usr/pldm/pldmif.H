/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldmif.H $                               */
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
#ifndef PLDMIF_H
#define PLDMIF_H

/**
 * @file pldmif.H
 *
 * @brief PLDM's Interface for external userspace modules to call
 *
 */

#include <cstddef>
#include <errl/errlentry.H>

namespace PLDM
{
    /**
    * @brief This function is intended to be used by the MCTP resource
    *        provider when they find a PLDM message and want the PLDM
    *        resource provider to handle it
    *
    * @param[in] i_msg  A ptr to PLDM message, no change of memory ownership.
    *                   Note that this func will assert is i_msg is nullptr.
    * @param[in] i_len  Length of buffer containing PLDM message,
                        i_len must be >= sizeof(pldm_msg_hdr).
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t routeInboundMsg(const uint8_t * i_msg, size_t i_len);
}
#endif
