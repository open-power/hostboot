/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_init_fsi.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file   p10_spi_init_fsi.H
/// @brief  Set root control register's muxes to use FSI CFAM instead of PIB
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Derksen <mderkse1@us.ibm.com>
/// *HWP Consumed by: Hostboot
#ifndef _P10_SPI_INIT_FSI_H_
#define _P10_SPI_INIT_FSI_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "p10_sbe_spi_cmd.H"

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------

typedef fapi2::ReturnCode (*p10_spi_init_fsi_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<SPI_ENGINE_PART>& i_engines);

extern "C"
{
    /*
     * @brief This hardware procedure will accept a given processor target and
     *        set the root control register's muxes to use FSI instead of PIB.
     *        Note that if no engines are passed in, then all 4 engines will
     *        be switched to FSI mode
     *
     *        valid enum values passed in to i_engines:
     *        SPI_ENGINE_PRIMARY_BOOT_SEEPROM = 0
     *        SPI_ENGINE_BACKUP_BOOT_SEEPROM = 1
     *        SPI_ENGINE_PRIMARY_MVPD_SEEPROM = 2
     *        SPI_ENGINE_BACKUP_MVPD_SEEPROM = 3
     *
     * @param[in]   i_target    The processor target to operate on.
     * @param[in]   i_engines   List of engines to swap over to FSI.
     */
    fapi2::ReturnCode p10_spi_init_fsi(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const std::vector<SPI_ENGINE_PART>& i_engines = {});

} // extern C

#endif
