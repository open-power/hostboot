/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/fapi2/hbbl_plat_attribute_service.C $          */
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
///
/// @file hbbl_plat_attribute_service.C
///
/// @brief Implements the plat_attribute_service.H attribute functions.
///
/// Note that platform code must provide the implementation.
///

#include <stdint.h>
#include <plat_attribute_service.H>
#include <return_code.H>

namespace fapi2
{

namespace platAttrSvc
{

// Bootloader Attribute Bank
// - Globals used inside Bootloader code for _GETMACRO and _SETMACRO calls
//   from src/include/bootloader/plat_attribute_service.H

// Set default value of ATTR_TPM_SPI_BUS_DIV to 0x0157 in case there isn't a
// valid override in scratch register 13
extern uint16_t g_attr_tpm_spi_bus_div;
uint16_t g_attr_tpm_spi_bus_div = 0x0157;


} // end namespace platAttrSvc

} // end namespace fapi2
