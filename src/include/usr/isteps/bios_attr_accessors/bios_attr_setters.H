/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/bios_attr_accessors/bios_attr_setters.H $ */
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

/** @file  bios_attr_setters.H
 *  @brief This file contains the declarations of the functions that
 *         determines the value that needs to be set to a PLDM BIOS attribute
 *         Then uses the appropriate API from hb_bios_attrs.H to set it.
 *
 *  @note  All APIs defined in this header should have the same parameters.
 *         These functions are intended to be used in call_<substep>.C files
 *         in the istep module.
 */

// System Includes
#include <stdint.h>
#include <vector>

// Forward Declarations
namespace ISTEP_ERROR
{
class IStepError;
}

namespace ISTEP
{
/**
 * @brief Determine the max number of huge pages the system can support given
 *        its current configuration and set the hb_max_num_huge_page PLDM BIOS
 *        attribute to inform the BMC of the determination.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void set_hb_max_number_huge_pages(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  ISTEP_ERROR::IStepError & io_stepError);
}
