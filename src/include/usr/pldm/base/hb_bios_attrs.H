/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/base/hb_bios_attrs.H $                   */
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
#ifndef HB_BIOS_ATTRS_H
#define HB_BIOS_ATTRS_H

/** @file  hb_bios_attrs.H
 *  @brief This file contains the declaration(s) of the function(s) that
 *         are used to get the current value of the PLDM BIOS attributes from
 *         the BMC.
 */

#include <openbmc/pldm/libpldm/bios_table.h>
#include <attributetraits.H>
#include <attributeenums.H>

namespace PLDM
{
    /** @brief Retrieve the current value of the hb-hyp-switch
    *          PLDM bios attribute, convert it to ATTR_PAYLOAD_KIND
    *          enum, and set ATTR_PAYLOAD_KIND on the system target.
    *
    * @param[in,out] io_string_table  A byte vector that if empty will be filled
    *                                 with the string table via a PLDM Bios Table
    *                                 request to the BMC. If it already has contents
    *                                 no request will be made and vector will not
    *                                 be modified.
    *
    * @param[in,out] io_attr_table    A byte vector that if empty will be filled
    *                                 with the attribute table via a PLDM Bios Table
    *                                 request to the BMC. If it already has contents
    *                                 no request will be made and vector will not
    *                                 be modified.
    *
    * @param[out]    o_payloadType    If no error occurs will contain the value
    *                                 we found for hb-hyp-switch translated to
    *                                 terms of ATTR_PAYLOAD_KIND_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getHypervisorMode(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 TARGETING::ATTR_PAYLOAD_KIND_type &o_payloadType);
}

#endif
