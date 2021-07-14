/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_init_fsi.C $  */
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
/// @file p10_spi_init_fsi.C
/// @brief Set the root control register for the given proc to use FSI mux path
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Derksen <mderkse1@us.ibm.com>
/// *HWP Consumed by: Hostboot

#include "p10_spi_init_fsi.H"
#include <p10_scom_perv.H>

fapi2::ReturnCode p10_spi_init_fsi(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<SPI_ENGINE_PART>& i_engines)
{
    // Give these constants more managable names.
    // Use this atomic set register to set bits in ROOT_CTRL_8 register
    // Need to use the FSI register
    const uint32_t ROOT_CTRL_8_SET =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_SET_FSI;

    fapi2::buffer<uint32_t> root_ctrl_set_buffer;

    // Force root control reg 8 to use FSI for SPI Master for all engines
    // in the vector i_engines
    // SET function: for setting individual bits to logical '1' value, take
    // corresponding SET address of the given register and write a '1' into
    // that bit positions that needs to be set. ('1' setting = FSI CFAM mode)
    // bit 0 = PRIMARY BOOT SEEPROM
    // bit 1 = BACKUP BOOT SEEPROM
    // bit 2 = PRIMARY MVPD SEEPROM
    // bit 3 = BACKUP MVPD SEEPROM
    if (i_engines.empty()) // empty vector means swap every engine to FSI
    {
        for (size_t i = SPI_ENGINE_PRIMARY_BOOT_SEEPROM; i < SPI_ENGINE_TPM; i++)
        {
            root_ctrl_set_buffer.setBit(i);
        }
    }
    else
    {
        for (size_t i : i_engines)
        {
            // No associated SPI engine
            FAPI_ASSERT(i < SPI_ENGINE_TPM, fapi2::INVALID_SPI_ENGINE()
                        .set_CHIP_TARGET(i_target),
                        "Error trying to switch SPI mux to FSI");


            root_ctrl_set_buffer.setBit(i);
        }
    }

    // Update ROOT_CTRL_8 register via its atomic set register
    FAPI_TRY(fapi2::putCfamRegister(
                 i_target,
                 ROOT_CTRL_8_SET,
                 root_ctrl_set_buffer));

fapi_try_exit:
    FAPI_INF("p10_spi_init_fsi: Exit");
    return fapi2::current_err;

}
