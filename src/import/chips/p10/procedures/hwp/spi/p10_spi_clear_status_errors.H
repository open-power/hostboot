/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_clear_status_errors.H $ */
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
// EKB-Mirror-To: hostboot


///
/// @file p10_spi_clear_status_errors.H
/// @brief Clears the status register of the given SPI Master
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Raybuck <matthew.raybuck@ibm.com>
/// *HWP Consumed by: Hostboot

#ifndef P10_SPI_CLEAR_STATUS_ERRORS_H
#define P10_SPI_CLEAR_STATUS_ERRORS_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "p10_sbe_spi_cmd.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// @brief Clears all the error bits in the SPI master status register. Some of the bits
//        are sticky and must be explicitly cleared.
//
// @param[in] i_spiHandle  A handle to the spi master which will have its status register cleared.
//
// @return    FAPI_RC_SUCCESS if status register was cleared successfully. Otherwise an error code.
    fapi2::ReturnCode p10_spi_clear_status_errors(const SpiControlHandle& i_spiHandle);

} // extern "C"


#endif // P10_SPI_CLEAR_STATUS_ERRORS_H
