/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/lpc/lpc_const.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

/**
 * @file lpc_const.H
 *
 * @brief Defines constants describing the LPC address space
 *
 */

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
    enum : uint64_t
    {
        /* LPC Host Controller FW Space */
        LPCHC_FW_SPACE =        0xF0000000,

        /* LPC Host Controller MCTP/PLDM base address */
        LPCHC_MCTP_PLDM_BASE =  0x0FF00000,

        /* LPC Host Controller Mem Space */
        LPCHC_MEM_SPACE =       0xE0000000,

        /* LPC Host Controller I/O Space */
        LPCHC_IO_SPACE  =       0xD0010000,

        /* LPC Host Ctlr Internal Register Space */
        LPCHC_INT_REG_SPACE =   0xC0012000,

        /* LPC Host Ctlr Err Register Space */
        LPCHC_ERR_SPACE =       0xC0010000,

        /* Physical addr of the start of LPC address space */
        LPC_PHYS_BASE =         0x6030000000000,

        /* Size of FW Window */
        FW_WINDOW_SIZE =        0x10000000,

        /* OPBM Error Bits MASK */
        OPB_ERROR_MASK =        0x20000FC3,

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

        // KCS2 - Interface to initiate a soft reset to BMC from Host in AST2600
        /* Keyboard Controller Style (KCS) data register address
         * (provided by hypervisor team)
         */
        KCS2_DATA_REG =          0xCA8,

        /* Keyboard Controller Style (KCS) status register address
         * (provided by hypervisor team)
         */
        KCS2_STATUS_REG =        0xCA9,

        /* Serial IRQ number for KCS interface
         * (provided by hypervisor team)
         */
        KCS2_SERIAL_IRQ =        12,

    };
}


    /**
      * @brief More general constants not tied to LPC namespace
      *
      */
    enum : uint32_t
    {
        /** Start of LPC Addr within the memory mapped space*/
        LPC_ADDR_START = 0xC0000000,

        /** Size that LPC takes up (0xC0000000 to 0xFFFFFFFF)*/
        LPC_SPACE_SIZE = 0x40000000,

        /**< OPB LPCM Sync FIR Reg WOX_AND - used to clear the FIR */
        OPB_LPCM_FIR_WOX_AND_REG = 0x01010C01,

        /**< OPB LPCM Sync FIR Mask Reg WO_OR - used to set the mask */
        OPB_LPCM_FIR_MASK_WO_OR_REG = 0x01010C05,

        // LPCHC reset-related registers
        OPB_MASTER_LS_CONTROL_REG = 0x008, /**<OPBM LS Control Reg */

        LPCHC_SYNC_CYCLE_COUNTER_INFINITE = 0xFF000000,

        /** OPB Master Accumulated Status Register - used to check error bits*/
        OPBM_ACCUM_STATUS_REG = 0x0,

        /** OPB Master Actual Status Register */
        OPBM_STATUS_REG = 0x004C,

        /** LPC Host Controller Status Register - used to check error bits*/
        LPCHC_REG = 0x2038,

        /** LPC Host Controller Error Addr Register - used to check error bits*/
        LPCHC_ERROR_ADDR_REG = 0x2040,

        /** LPC Host Controller Reset Register */
        LPCHC_LPC_BUS_ABORT_REG = 0x20F8,

        /** LPC Host Controller Reset Register */
        LPCHC_RESET_REG = 0x20FC,

        LPCHC_ERROR_MASK = 0x000004FC /**< LPCHC Error Bits MASK */

    };

    /**
     * @brief  OPB Master Status Register Layout
     */
    union OpbmErrReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved : 2;    // 0:1 reserved
            uint32_t rxctgtel : 1;    // 2 - OPB master timeout
            uint32_t rxfwrdcv : 1;    // 3 - FW read cache valid(status only)
            uint32_t reserved1 : 16;  // 4:19 reserved
            uint32_t rxits : 1;      // 20 - Invalid Transfer Size
            uint32_t rxicmd : 1;     // 21 - Invalid Command
            uint32_t rxiaa : 1;      // 22 - Invalid address alignment
            uint32_t rxiaddr : 1;    // 23 - Invalid address
            uint32_t rxopbe : 1;     // 24 - OPB error acknowledge
            uint32_t rxopbt : 1;     // 25 - OPB timeout
            uint32_t reserved2 : 4;  // 26:29 reserved
            uint32_t rxicmdb : 1;    // 30 - Command buffer parity error
            uint32_t rxidatab : 1;   // 31 - Data buffer parity error

        };
        OpbmErrReg_t() : data32(0) {};
    };

    /**
     * @brief  LPCHC Status Register Layout
     */
    union LpchcErrReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved : 17;    // 0:16 IRQSER status - not used
            uint32_t reserved1 : 4;    // 17:20 reserved
            uint32_t lreset : 1;       // 21 - Lreset Event
            uint32_t reserved2 : 2;    // 22:23 reserved
            uint32_t syncab : 1;       // 24 - Sync Abnormal
            uint32_t syncnr : 1;       // 25 - Sync no response
            uint32_t syncne : 1;       // 26 - Sync normal error
            uint32_t syncto : 1;       // 27 - Sync timeout
            uint32_t tctar : 1;        // 28 - Target cycle TAR error
            uint32_t mctar : 1;        // 29 - LPC bus master cycle TAR error
            uint32_t mzeror : 1;       // 30 - LPC bus master 0 request
            uint32_t moner : 1;        // 31 - LPC bus master 1 request
        };
        LpchcErrReg_t() : data32(0) {};
    };

    /**
      * @brief Enums for different levels of resetting PNOR communication levels
      */
    enum ResetLevels : uint32_t
    {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_OPB_LPCHC_SOFT = 0x00000001, /**< OPB LPCHC Clear Errors */
        RESET_OPB_LPCHC_HARD = 0x00000002, /**< OPB LPCHC Reset Logic */
        RESET_INIT           = 0x00000004, /**< Initial HW setup */
    };

#endif
