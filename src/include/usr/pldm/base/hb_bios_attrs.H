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

namespace PLDM
{
    const char PLDM_BIOS_HB_HYP_SWITCH_STRING[] = "hb-hyp-switch";

    /** @brief Given a string describing the name of a PLDM bios attribute
    *          Hostboot wants to read from the BMC, retrieve the value
    *          and value type of that attribute
    *
    * @param[in] i_attr_string
    *                String representing PLDM Bios attribute we want
    *                the value of. Consts should be defined in this header.
    *
    * @param[out] o_attr_type
    *                Type of PLDM attribute, See bios.h.
    * @param[out] o_attr_val
      *              Expected to be empty on input, will be cleared
    *                during the function. If no error then will
    *                contain bios attribute value when
    *                function completes.
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getCurrentAttrValue(const char *i_attr_string,
                                  pldm_bios_attribute_type& o_attr_type,
                                  std::vector<uint8_t>& o_attr_val);
}

#endif