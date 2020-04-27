/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_init_pib.C $  */
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
/// @file p10_spi_init_pib.C
/// @brief Set the root control register for the given proc to use PIB mux path
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Raybuck <matthew.raybuck@ibm.com>
/// *HWP Consumed by: Hostboot

#include "p10_spi_init_pib.H"
#include <p10_scom_perv.H>

fapi2::ReturnCode p10_spi_init_pib(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // Give these constants more managable names.
    // Use this atomic clear register to set 0 bits in ROOT_CTRL_8 register
    const uint64_t ROOT_CTRL_8_CLEAR =
        static_cast<uint64_t>(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_WO_CLEAR);

    // Select SPIM_0 for BOOT0 SEEPROM
    const uint64_t SPIM0_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST0_PORT_MUX_SEL_DC;

    // Select SPIM_1 for BOOT1 SEEPROM
    const uint64_t SPIM1_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST1_PORT_MUX_SEL_DC;

    // Select SPIM_2 for MVPD/KEYSTORE SEEPROM
    const uint64_t SPIM2_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST2_PORT_MUX_SEL_DC;

    // Select SPIM_3 for MEASUREMENT ROM
    const uint64_t SPIM3_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_CLEAR_TPFSI_SPIMST3_PORT_MUX_SEL_DC;


    fapi2::buffer<uint64_t> root_ctrl_clear_buffer;

    // Force root control reg 8 to use PIB for SPI Master for all 4 SPI engines
    // CLEAR function: for clearing individual bits
    // (set logical '0' value = PIB mode), take corresponding CLEAR address
    // of the given register and write a '1' into that bit positions that
    // needs to be cleared.
    root_ctrl_clear_buffer.setBit<SPIM0_PORT_MUX_SELECT>();
    root_ctrl_clear_buffer.setBit<SPIM1_PORT_MUX_SELECT>();
    root_ctrl_clear_buffer.setBit<SPIM2_PORT_MUX_SELECT>();
    root_ctrl_clear_buffer.setBit<SPIM3_PORT_MUX_SELECT>();

    // Update ROOT_CTRL_8 register via its atomic clear register
    FAPI_TRY(fapi2::putScom(
                 i_target,
                 ROOT_CTRL_8_CLEAR,
                 root_ctrl_clear_buffer));

fapi_try_exit:
    FAPI_INF("p10_spi_init_pib: Exit");
    return fapi2::current_err;

}
