/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_spi_clear_status_errors.C $ */
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

#include "p10_spi_clear_status_errors.H"
#include <p10_scom_proc.H>

fapi2::ReturnCode p10_spi_clear_status_errors (
    const SpiControlHandle& i_spiHandle)
{
    fapi2::buffer<uint64_t> data64 = 0;

    // The base_addr is either the FSI or PIB address.
    const uint32_t statusRegAddr = i_spiHandle.base_addr + SPIM_STATUSREG;

    FAPI_TRY(fapi2::getScom(i_spiHandle.target_chip,
                            statusRegAddr,
                            data64));

    // Clear the following bits
    // Bits 1 to 3
    data64.clearBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_RDR_OVER_STATUS, 3>();
    // Bits 5 to 7
    data64.clearBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_TDR_OVER_STATUS, 3>();
    // Bits 32 to 63
    data64.clearBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_32, 32>();

    FAPI_TRY(fapi2::putScom(i_spiHandle.target_chip,
                            statusRegAddr,
                            data64));

fapi_try_exit:
    FAPI_INF("p10_spi_clear_status_errors: Exit");
    return fapi2::current_err;
}
