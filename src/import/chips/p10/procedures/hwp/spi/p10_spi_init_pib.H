/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_init_pib.H $  */
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
///
/// @file p10_spi_init_pib.H
/// @brief Execute hostboot isteps from istep mode by writing to mailbox scratch
///        register 4.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Raybuck <matthew.raybuck@ibm.com>
/// *HWP Consumed by: Hostboot
#ifndef _P10_SPI_INIT_PIB_H_
#define _P10_SPI_INIT_PIB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------

typedef fapi2::ReturnCode (*p10_spi_init_pib_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

extern "C"
{
    /*
     * @brief This hardware procedure will accept a given processor target and
     *        set the root control register's muxes to use PIB instead of CFAM.
     *
     * @param[in]   i_target    The processor target to operate on.
     */
    fapi2::ReturnCode p10_spi_init_pib(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern C

#endif
