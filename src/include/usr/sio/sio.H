/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sio/sio.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#ifndef __SIO_SIO_H
#define __SIO_SIO_H

#include <errl/errlentry.H>

namespace SIO
{
    /**
     * SIO constants
     */
    enum{
        SIO_DEVICE_SELECT_REG   = 0x07,     /**< Regsiter to select SIO device */
        SIO_ADDR_REG_2E         = 0x2E,     /**< SuperIO address register */
        SIO_DATA_REG_2F         = 0x2F,     /**< SuperIO data register */
        SIO_PASSWORD_REG        = 0xA5,     /**< SuperIO password register (to be unlocked to access SIO) */
        SUART1                  = 0x02,     /**< SIO device */
        iLPC2AHB                = 0x0D,     /**< SIO device */
        KBC                     = 0x05,     /**< SIO device: Keyboard Controller */
        MB                      = 0x0E,     /**< SIO device: Mailbox */
        DONT_CARE               = 0x02,     /**< SIO device: Don't care for boot flags version */
        ENABLE_DEVICE           = 0x01,     /**< Enable SIO device by writing 1 to reg 30 of device */
        DISABLE_DEVICE          = 0x00,     /**< Disable SIO device by writing 0 to reg 30 of device */
        SIO_iLPC2AHB_LENGTH     = 0x02,     /**< SIO to iLPC2AHB length */
        SIO_ILPC2AHB_TRIGGER    = 0xCF,     /**< Read/Write 0xCF to reg FE of iLPC2AHB to trigger read/write for SIO/iLPC2AHB */
        SIO_SCRATCH_REG1        = 0x21,     /**< Scratch Reg */
        SIO_SCRATCH_REG2        = 0x22,     /**< Scratch Reg */
    };

    /**
     * @brief Test if SuperIO is accessible on the LPC bus
     *
     * @param[out] o_available Set true if the SuperIO controller is available,
     *                         false if it explicitly detected as unavailable,
     *                         and unchanged if an unexpected error occurs.
     *
     * @return NULL if the test did not fail unexpectedly, otherwise a pointer
     *         to an errorlog associated with the error.
     */
    errlHndl_t isAvailable(bool& o_available);
}
#endif
