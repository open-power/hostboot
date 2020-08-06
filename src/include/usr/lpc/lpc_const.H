/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/lpc/lpc_const.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#ifndef LPC_CONST_H
#define LPC_CONST_H

#include <stdint.h>
#include <builtins.h>

namespace LPC
{
    /**
     * @brief Some general constants
     *
     */
    enum {
        LPCHC_FW_SPACE  = 0xF0000000, /**< LPC Host Controller FW Space */
        LPCHC_MEM_SPACE = 0xE0000000, /**< LPC Host Controller Mem Space */
        LPCHC_IO_SPACE  = 0xD0010000, /**< LPC Host Controller I/O Space */
        LPCHC_REG_SPACE = 0xC0012000, /**< LPC Host Ctlr Register Space */
        LPCHC_ERR_SPACE = 0xC0010000, /**< LPC Host Ctlr Err Register Space */

        /* LPC Host Controller MCTP/PLDM base address */
        LPCHC_MCTP_PLDM_BASE =  0x0FF00000,

        /** Physical addr of the start of LPC address space*/
        LPC_PHYS_BASE = 0x6030000000000,

        FW_WINDOW_SIZE =  0x10000000, //Size of FW Window

        OPB_ERROR_MASK = 0x20000FC3, /**< OPBM Error Bits MASK */

        /* Keyboard Controller Style (KCS) data register address
         * NOTE: This can be found in the IPMI spec
         */
        KCS_DATA_REG =          0xCA2,

        /* Keyboard Controller Style (KCS) status register address
         * NOTE: This can be found in the IPMI spec
         */
        KCS_STATUS_REG =        0xCA3,

        /* Serial IRQ number for KCS interface
         * (provided by hypervisor team)
         */
        KCS_SERIAL_IRQ =        11,

    };
}

#endif
