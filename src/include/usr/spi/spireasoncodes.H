/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/spi/spireasoncodes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __SPI_REASONCODES_H
#define __SPI_REASONCODES_H

#include <hbotcompid.H>

namespace SPI
{

    enum spiModuleId
    {
        SPI_OP_READ             = 0x01,
        SPI_OP_WRITE            = 0x02,
        SPI_COPY_TO_BUFFER      = 0x03,
        SPI_ENGINE_LOCK_OP      = 0x04,
        SPI_PERFORM_OP          = 0x05,
    };

    enum spiReasonCode
    {
        SPI_BUFFER_SIZE_MISMATCH            = SPI_COMP_ID | 0x01,
        SPI_INVALID_PARAMETERS              = SPI_COMP_ID | 0x02,
        SPI_FAILED_TO_RETRIEVE_ENGINE_MUTEX = SPI_COMP_ID | 0x03,
        SPI_UNKNOWN_OP_TYPE                 = SPI_COMP_ID | 0x04,
        SPI_INVALID_BUFFER_SIZE             = SPI_COMP_ID | 0x05,
    };

    enum SpiUserDetailsTypes
    {
        SPI_EEPROM_UDT_PARAMETERS = 0x01,
        SPI_TPM_UDT_PARAMETERS    = 0x02,
    };

    enum SpiUserDetailsVersions
    {
        SPI_UDT_VERSION_1 = 0x01,
    };

};

#endif
