/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/plat_attribute_service.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @brief Defines the specialized platform attribute access functions
///
/// Note that platform code must provide the code.
///

#ifndef PLAT_ATTRIBUTE_SERVICE_BOOTLOADER
#define PLAT_ATTRIBUTE_SERVICE_BOOTLOADER

#include <stdint.h>
#include <return_code.H>
#include <fapi2_attribute_service.H>

/******************************************************************************/
// Bootloader Attribute Suppoort
/******************************************************************************/
//
// There will be limited attribute support in Bootloader code.
// At this time, we just need to support the following calls for ATTR_TPM_SPI_BUS_DIV:
// - from p10_sbe_spi_cmd.C:
//     FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_TPM_SPI_BUS_DIV, i_target_chip, l_attr_tpm_spi_bus_div),
//                            "Error from FAPI_ATTR_GET (ATTR_TPM_SPI_BUS_DIV");
//     This maps to ATTR_TPM_SPI_BUS_DIV_GETMACRO below
//
// - from bl_tpm_spidd.C:
//     fapi2::ATTR_TPM_SPI_BUS_DIV_SETMACRO(fapi2::AttributeId::ATTR_TPM_SPI_BUS_DIV,
//                                          l_target_chip,
//                                          l_attr_data);


namespace fapi2
{

namespace platAttrSvc
{

// Bootloader Attribute Bank
// - Globals used inside Bootloader code for _GETMACRO and _SETMACRO calls
//   can be found in src/bootloader/fapi2/hbbl_plat_attribute_services.C
extern uint16_t g_attr_tpm_spi_bus_div; // Global for ATTR_TPM_SPI_BUS_DIV

} // end of namespace platAttrSvc

#define ATTR_TPM_SPI_BUS_DIV_GETMACRO HBBL_ATTR_TPM_SPI_BUS_DIV_GETMACRO
#define ATTR_TPM_SPI_BUS_DIV_SETMACRO HBBL_ATTR_TPM_SPI_BUS_DIV_SETMACRO

inline ReturnCode HBBL_ATTR_TPM_SPI_BUS_DIV_GETMACRO(fapi2::AttributeId ID,
                                              const Target<(fapi2::TargetType)4> TARGET,
                                              uint16_t & VAL)
{
    VAL = platAttrSvc::g_attr_tpm_spi_bus_div;
    return FAPI2_RC_SUCCESS;

}
inline void HBBL_ATTR_TPM_SPI_BUS_DIV_SETMACRO(fapi2::AttributeId ID,
                                                   const fapi2::Target<(fapi2::TargetType)4> TARGET,
                                                   uint16_t VAL)
{
    platAttrSvc::g_attr_tpm_spi_bus_div = VAL;
    return;
}

} // end of namespace fapi2

#endif // PLAT_ATTRIBUTE_SERVICE_BOOTLOADER
