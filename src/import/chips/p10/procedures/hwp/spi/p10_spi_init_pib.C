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
    const uint64_t ROOT_CTRL_8 =
        static_cast<uint64_t>(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_RW);
    const uint64_t SPIM_PORT_MUX_SELECT =
        scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL8_TPFSI_SPIMST0_PORT_MUX_SEL_DC;

    fapi2::buffer<uint64_t> root_ctrl_buffer;

    // Get the contents of root control register 8 which controls whether
    // we're accessing over PIB or FSI.
    FAPI_TRY(fapi2::getScom(
                 i_target,
                 ROOT_CTRL_8,
                 root_ctrl_buffer));

    // Force root control reg 8 to use PIB for SPI Master
    // clearing the bit to 0 forces the SPI Master to use the PIB path.
    root_ctrl_buffer.clearBit<SPIM_PORT_MUX_SELECT>();

    // Write the buffer back to the register.
    FAPI_TRY(fapi2::putScom(
                 i_target,
                 ROOT_CTRL_8,
                 root_ctrl_buffer));

fapi_try_exit:
    FAPI_INF("p10_spi_init_pib: Exit");
    return fapi2::current_err;

}
