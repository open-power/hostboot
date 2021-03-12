/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_psudd.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#ifndef __SBE_PSUDD_H
#define __SBE_PSUDD_H

/**
 * @file sbe_psudd.H
 * @brief SBE psu device driver specifics
 */

#include <stdint.h>
#include <builtins.h>
#include <sys/time.h>

#include <errl/errlentry.H>
#include <util/singleton.H>
#include "sbe_sp_intf.H"
#include <map>
#include <arch/pirformat.H>

namespace SBEIO
{
//-----------------------------------------------------------------------------
//  Interfaces to the SBE PSU device driver to be used by clients
//  within this component.
//-----------------------------------------------------------------------------

enum msgq_msg_t
{
    MSG_INTR,
};

/** @class SbePsu
 *  @brief Class for SBE/PSU communication
*/

class SbePsu
{
    public:

        /**
         * @brief The alignment boundary for sending an SBE message
         */
        static constexpr uint32_t SBE_ALIGNMENT_SIZE_IN_BYTES = 128;

        /**
         * @brief get the instance of this class
         *
         * @return the (one and only) instance of SbePsu
         */

        static SbePsu & getTheInstance();

        /**
         * @brief enums for SBE command class
         */

        // BYTE 6 options
        enum psuCommandClass
        {
            SBE_PSU_CLASS_UNKNOWN           = 0,
            SBE_PSU_CLASS_CORE_STATE        = 0xD1,
            SBE_PSU_PUT_RING_FROM_IMAGE_CMD = 0xD3,
            SBE_PSU_CLASS_REGISTER_ACCESS   = 0xD5,
            SBE_PSU_CLASS_SECURITY_CONTROL  = 0xD6,
            SBE_PSU_GENERIC_MESSAGE         = 0xD7,
        };

        /**
         * @brief enums for SBE core state control commands
         */

        // BYTE 7 options
        enum psuCoreStateControlCommands
        {
            SBE_CMD_CONTROL_DEADMAN_LOOP   = 0x01,
            SBE_CMD_EXIT_CACHE_CONTAINED   = 0x02,
        };

        /**
         * @brief enums for SBE core state control commands
         */

        // BYTE 7 options
        enum psuRegisterAccessCommands
        {
            SBE_CMD_GET_HW_REG      = 0x03,
        };

        /**
         * @brief enums for SBEPutRing From Image message commands
         */
          // BYTE 7 options
        enum putRingCommandFromImageCommands
        {
            SBE_CMD_CONTROL_PUTRING        = 0x01
        };

        /**
        * @brief enums for SBE generic message commands
        */
        //BYTE 7 options
        enum psuGenericMessageCommands
        {
            SBE_PSU_MSG_GET_CAPABILITIES     = 0x02,
            SBE_PSU_READ_SEEPROM             = 0x03,
            SBE_PSU_SET_FFDC_ADDRESS         = 0x04,
            SBE_PSU_GENERIC_MSG_QUIESCE      = 0x05,
            SBE_CMD_CONTROL_SYSTEM_CONFIG    = 0x06,
            SBE_PSU_MSG_STASH_KEY_ADDR       = 0x07,
            SBE_PSU_SECURITY_LIST_BIN_DUMP   = 0x08,
            SBE_PSU_OCMB_CONFIG              = 0x09,
            SBE_PSU_TOPOLOGY_ID_TABLE        = 0x0A, //syncFabTopoIdTable
        };

        /**
         * @brief enums for SBE Security Control commands
         */
        //BYTE 7 options
        enum psuSecurityContolCommands
        {
            SBE_PSU_SET_UNSECURE_MEMORY_REGION_CMD  = 0x01,
        };


        /**
         * @brief enums for SBE core state control flags
         */
        //BYTE 2  & 3, Control Flags
        enum psuDeadManControlFlags
        {
            SBE_DMCONTROL_START              = 0x01,
            SBE_DMCONTROL_STOP               = 0x02,
            SBE_DMCONTROL_RESPONSE_REQUIRED  = 0x0100,
            SBE_DMCONTROL_ACK_REQUIRED       = 0x0200,
        };

        /**
        * @brief enums for SBE system config control flags
        */
        //BYTE 2  & 3, Control Flags
        enum psuCommonControlFlags
        {
            SBE_REQUIRE_RESPONSE             = 0x0100,
            SBE_REQUIRE_ACK                  = 0x0200,
        };

        /**
        * @brief enums for SBE Set Unsecure Memory Region control flags
        */
        //BYTE 2  & 3, Control Flags
        enum psuSetUnsecureMemoryRegionControlFlags
        {
            SBE_MEM_REGION_OPEN_READ_ONLY   = 0x0011,
            SBE_MEM_REGION_OPEN_READ_WRITE  = 0x0012,
            SBE_MEM_REGION_CLOSE            = 0x0020,

            // Re-use SBE_REQUIRE_RESPONSE and SBE_REQUIRE_ACK from above
            SBE_MEM_REGION_RESPONSE_REQUIRED = SBE_REQUIRE_RESPONSE,
            SBE_MEM_REGION_ACK_REQUIRED      = SBE_REQUIRE_ACK,
        };

        /**
         * @brief non reserved word enums
         *
         * Shows which of the request and response msg registers are
         * not reserved. Reserved registers do not need to be written
         * or read.
         *
         * This is a 4 bit field, each bit indicates as follows:
         * 0x1 - Reg 0 is non-reserved (read or write this reg)
         * 0x2 - Reg 1 is non-reserved (read or write this reg)
         * 0x4 - Reg 2 is non-reserved (read or write this reg)
         * 0x8 - Reg 3 is non-reserved (read or write this reg)
         */
        enum psuCoreStateControlNonReservedMsgs
        {
            SBE_DMCONTROL_START_REQ_USED_REGS     = 0x0F,
            SBE_DMCONTROL_START_RSP_USED_REGS     = 0x01,
            SBE_DMCONTROL_STOP_REQ_USED_REGS      = 0x01,
            SBE_DMCONTROL_STOP_RSP_USED_REGS      = 0x01,
        };

        /**
         * @brief non reserved word enums
         *
         * Shows which of the request and response msg registers are
         * not reserved. Reserved registers do not need to be written
         * or read.
         *
         * This is a 4 bit field, each bit indicates as follows:
         * 0x1 - Reg 0 is non-reserved (read or write this reg)
         * 0x2 - Reg 1 is non-reserved (read or write this reg)
         * 0x4 - Reg 2 is non-reserved (read or write this reg)
         * 0x8 - Reg 3 is non-reserved (read or write this reg)
         */
        enum psuExitCacheContainedNonReservedMsgs
        {
            // Use Reg 0,1,2 (0x1 + 0x2 + 0x4)
            SBE_EXIT_CACHE_CONTAINED_REQ_USED_REGS  = 0x07,
            // Use Reg 4 (0x1)
            SBE_EXIT_CACHE_CONTAINED_RSP_USED_REGS  = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSystemConfigNonReservedMsgs
        {
            SBE_SYSTEM_CONFIG_REQ_USED_REGS     = 0x03,
            SBE_SYSTEM_CONFIG_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuQuiesceNonReservedMsgs
        {
            SBE_QUIESCE_REQ_USED_REGS     = 0x01,
            SBE_QUIESCE_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuGetCapabilitiesNonReservedMsgs
        {
            SBE_GET_CAPABILITIES_REQ_USED_REGS  = 0x07,  // Use Reg 0 ... Reg 2 (0x1 + 0x2 + 0x4)
            SBE_GET_CAPABILITIES_RSP_USED_REGS  = 0x07,  // Use Reg 0 ... Reg 2 (0x1 + 0x2 + 0x4)
        };

        /**
        * @brief Define which registers are available for transferring data
        *
        * Shows which of the request and response msg registers that are
        * enabled for transferring data and receiving a response. The reserved
        * registers are excluded and therefore do not need to be written to
        * or read from.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - MBOX Reg 0 is non-reserved (read or write this reg)
        * 0x2 - MBOX Reg 1 is non-reserved (read or write this reg)
        * 0x4 - MBOX Reg 2 is non-reserved (read or write this reg)
        * 0x8 - MBOX Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSendOcmbConfig
        {
            // Enable/Use MBOX Regs 0 .. 3 (0x1 + 0x2 + 0x4 + 0x8) to send
            // SBE OCMB updates
            SBE_REQ_SEND_OCMB_CONFIG_REGS  = 0x0F,
            // Enable/Use MBOX Reg 0 (0x1) to receive a response from SBE
            // after sending the OCMB updates
            SBE_RSP_SEND_OCMB_CONFIG_REGS  = 0x01,
            // The maximum number of OCMB config info the PSU command can handle
            SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS = 16,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuReadSeepromMsgs
        {
            SBE_READ_SEEPROM_REQ_USED_REGS     = 0x07,
            SBE_READ_SEEPROM_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuStashKeyAddrNonReservedMsgs
        {
            SBE_STASH_KEY_ADDR_REQ_USED_REGS     = 0x07,
            SBE_STASH_KEY_ADDR_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuGetHwRegNonReservedMsgs
        {
            SBE_GET_HW_REG_REQ_USED_REGS     = 0x07,
            SBE_GET_HW_REG_RSP_USED_REGS     = 0x03,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSetFFDCAddrNonReservedMsgs
        {
            SBE_SET_FFDC_ADDR_REQ_USED_REGS     = 0x0F,
            SBE_SET_FFDC_ADDR_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSetUnsecureMemoryRegionNonReservedMsgs
        {
            SBE_MEM_REGION_REQ_USED_REGS  = 0x07,
            SBE_MEM_REGION_RSP_USED_REGS  = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSecurityListBinDumpNonReservedMsgs
        {
            SBE_SECURITY_LIST_BIN_DUMP_REQ_USED_REGS     = 0x03,
            SBE_SECURITY_LIST_BIN_DUMP_RSP_USED_REGS     = 0x01,
        };

        /**
        * @brief non reserved word enums
        *
        * Shows which of the request and response msg registers are
        * not reserved. Reserved registers do not need to be written
        * or read.
        *
        * This is a 4 bit field, each bit indicates as follows:
        * 0x1 - Reg 0 is non-reserved (read or write this reg)
        * 0x2 - Reg 1 is non-reserved (read or write this reg)
        * 0x4 - Reg 2 is non-reserved (read or write this reg)
        * 0x8 - Reg 3 is non-reserved (read or write this reg)
        */
        enum psuSyncFabTopoIdTable
        {
            SBE_TOPOLOGY_TABLE_REQ_USED_REGS     = 0x07,//reg0,1,2
            SBE_TOPOLOGY_TABLE_RSP_USED_REGS     = 0x01,//reg0
        };


        /**
         * @brief Struct for PSU command message format
         *
         */
        union psuCommand
        {
            struct //raw
            {
                uint64_t mbxReg0;
                uint64_t mbxReg1;
                uint64_t mbxReg2;
                uint64_t mbxReg3;
            } PACKED;
            struct //common and direct fields
            {
                // mbxReg 0
                uint16_t reserved;
                uint16_t controlFlags;
                uint16_t seqID;
                uint8_t  commandClass;
                uint8_t  command;
                // mbxReg 1
                uint32_t dataWord2;
                uint32_t dataWord3;
                // mbxReg 2
                uint32_t dataWord4;
                uint32_t dataWord5;
                // mbxReg 3
                uint32_t dataWord6;
                uint32_t dataWord7;
            } PACKED;
            struct //indirect
            {
                // mbxReg 0
                uint16_t indirect_reserved;
                uint16_t indirect_controlFlags;
                uint16_t indirect_seqID;
                uint8_t  indirect_commandClass;
                uint8_t  indirect_command;
                // mbxReg 1
                uint32_t indirect_dataWord2;
                uint32_t indirect_dataWord3;
                // mbxReg 2
                uint32_t indirect_dataWord4;
                uint32_t indirect_dataWord5;
                // mbxReg 3
                uint64_t indirect_address;  // Data address (Mainstore/PBA)
            } PACKED;
            struct //controlDeadmanLoop
            {
                uint16_t cd1_ControlDeadmanLoop_Reserved;
                uint16_t cd1_ControlDeadmanLoop_ControlFlags;
                uint16_t cd1_ControlDeadmanLoop_SeqID;
                uint8_t  cd1_ControlDeadmanLoop_CommandClass;
                uint8_t  cd1_ControlDeadmanLoop_Command;
                uint64_t cd1_ControlDeadmanLoop_WaitTime;
                uint64_t cd1_ControlDeadmanLoop_ScomRegInitsCount;
                uint64_t cd1_ControlDeadmanLoop_ScomRegInitsAddr;
            } PACKED;

            struct //exitCacheContain
            {
                uint16_t cd1_exitCacheContain_Reserved;
                //0x0300 -- 0x0100 = Response required from SBE
                //       -- 0x0200 = SBE Ack required for this message
                uint16_t cd1_exitCacheContain_ControlFlags;
                uint16_t cd1_exitCacheContain_SeqId;
                uint8_t  cd1_exitCacheContain_CommandClass;  //Mbx Reg 0 -- 0xD8
                uint8_t  cd1_exitCacheContain_Command;       //Mbx Reg 0 -- 0x01
                uint32_t cd1_exitCacheContain_NumXscoms;       // mbxReg1
                uint32_t cd1_exitCacheContain_StepDetails;     // mbxReg1
                uint64_t cd1_exitCacheContain_DataAddr;        // mbxReg2
                uint64_t cd1_exitCacheContain_MbxReg3Reserved; // mbxReg3
            } PACKED;

            struct //setSystemConfig
            {
                uint16_t cd7_SetSystemConfig_Reserved;
                uint16_t cd7_SetSystemConfig_ControlFlags;
                uint16_t cd7_SetSystemConfig_SeqID;
                uint8_t  cd7_SetSystemConfig_CommandClass;
                uint8_t  cd7_SetSystemConfig_Command;
                uint64_t cd7_SetSystemConfig_SystemFabricIdMap;
                uint64_t cd7_SetSystemConfig_MbxReg2reserved;
                uint64_t cd7_SetSystemConfig_MbxReg3reserved;
            } PACKED;

            struct //for 'Put Ring from Image' message
            {
                uint16_t cd3_PutRing_Reserved;      //Mbx Reg 0
                uint16_t cd3_PutRing_ControlFlags;  //Mbx Reg 0
                uint16_t cd3_PutRing_SeqID;         //Mbx Reg 0
                uint8_t  cd3_PutRing_CommandClass;    //Mbx Reg 0
                uint8_t  cd3_PutRing_Command;         //Mbx Reg 0
                uint16_t cd3_PutRing_TargetType;  //Mbx Reg 1
                uint8_t  cd3_PutRing_Reserved1;   //Mbx Reg 1
                uint8_t  cd3_PutRing_ChipletID;   //Mbx Reg 1
                uint16_t cd3_PutRing_RingID;      //Mbx Reg 1
                uint16_t cd3_PutRing_RingMode;    //Mbx Reg 1
                uint64_t cd3_PutRing_ReservedMbxReg2; //Mbx Reg 2
                uint64_t cd3_PutRing_ReservedMbxReg3; //Mbx Reg 3
            } PACKED;

            struct //psuQuiesce
            {
                uint16_t cd7_PsuQuiesce_Reserved;
                uint16_t cd7_PsuQuiesce_ControlFlags;
                uint16_t cd7_PsuQuiesce_SeqID;
                uint8_t  cd7_PsuQuiesce_CommandClass;
                uint8_t  cd7_PsuQuiesce_Command;
                uint64_t cd7_PsuQuiesce_MbxReg1reserved;
                uint64_t cd7_PsuQuiesce_MbxReg2reserved;
                uint64_t cd7_PsuQuiesce_MbxReg3reserved;
            } PACKED;

            struct //securityListBinDump
            {
                uint16_t cd7_securityListBinDump_MbxReg0Reserved;  //Mbx Reg 0
                uint16_t cd7_securityListBinDump_ControlFlags;     //Mbx Reg 0
                uint16_t cd7_securityListBinDump_SeqID;            //Mbx Reg 0
                uint8_t  cd7_securityListBinDump_CommandClass;     //Mbx Reg 0  0xD7 (SBE_PSU_GENERIC_MESSAGE)
                uint8_t  cd7_securityListBinDump_Command;          //Mbx Reg 0  0x08 (SBE_PSU_SECURITY_LIST_BIN_DUMP)
                uint64_t cd7_securityListBinDump_addr;             //Mbx Reg 1
                uint64_t cd7_securityListBinDump_MbxReg2reserved;  //Mbx Reg 2
                uint64_t cd7_securityListBinDump_MbxReg3reserved;  //Mbx Reg 3
            } PACKED;

            struct //stashKeyAddr
            {
                uint16_t cd7_stashKeyAddr_MbxReg0Reserved;  //Mbx Reg 0
                uint16_t cd7_stashKeyAddr_ControlFlags;     //Mbx Reg 0
                uint16_t cd7_stashKeyAddr_SeqID;            //Mbx Reg 0
                uint8_t  cd7_stashKeyAddr_CommandClass;     //Mbx Reg 0
                uint8_t  cd7_stashKeyAddr_Command;          //Mbx Reg 0
                uint32_t cd7_stashKeyAddr_MbxReg1ReservedA; //Mbx Reg 1
                uint16_t cd7_stashKeyAddr_MbxReg1ReservedB; //Mbx Reg 1
                uint8_t  cd7_stashKeyAddr_MbxReg1ReservedC; //Mbx Reg 1
                uint8_t  cd7_stashKeyAddr_Key;              //Mbx Reg 1
                uint64_t cd7_stashKeyAddr_Value;            //Mbx Reg 2
                uint64_t cd7_stashKeyAddr_MbxReg3Reserved;  //Mbx Reg 3
            } PACKED;

            struct // sbeGetHwReg
            {
                uint16_t cd5_getHwReg_MbxReg0Reserved;  //Mbx Reg 0
                uint16_t cd5_getHwReg_ControlFlags;     //Mbx Reg 0
                uint16_t cd5_getHwReg_SeqID;            //Mbx Reg 0
                uint8_t  cd5_getHwReg_CommandClass;     //Mbx Reg 0
                uint8_t  cd5_getHwReg_Command;          //Mbx Reg 0
                uint16_t cd5_getHwReg_TargetType;       //Mbx Reg 1
                uint8_t  cd5_getHwReg_MbxReg1ReservedA; //Mbx Reg 1
                uint8_t  cd5_getHwReg_TargetInstance;   //Mbx Reg 1
                uint32_t cd5_getHwReg_AddressHi;        //Mbx Reg 1
                uint32_t cd5_getHwReg_AddressLow;       //Mbx Reg 2
                uint32_t cd5_getHwReg_MbxReg2Reserved;  //Mbx Reg 2
                uint64_t cd5_getHwReg_MbxReg3Reserved;  //Mbx Reg 3
            } PACKED;

            // Complies with document Host_SBE_Interface_Specification_v0.9e.pdf
            struct // getSbeCapabilities
            {
                uint16_t cd7_getSbeCapabilities_Reserved;      //Mbx Reg 0
                uint16_t cd7_getSbeCapabilities_ControlFlags;  //Mbx Reg 0
                uint16_t cd7_getSbeCapabilities_SeqID;         //Mbx Reg 0
                uint8_t  cd7_getSbeCapabilities_CommandClass;  //Mbx Reg 0: 0xD7 (SBE_PSU_GENERIC_MESSAGE)
                uint8_t  cd7_getSbeCapabilities_Command;       //Mbx Reg 0: 0x02 (SBE_PSU_MSG_GET_CAPABILITIES)
                uint64_t cd7_getSbeCapabilities_CapabilitiesSize; //Mbx Reg 1
                uint64_t cd7_getSbeCapabilities_CapabilitiesAddr; //Mbx Reg 2
                uint64_t cd7_getSbeCapabilities_MbxReg3Reserved;  //Mbx Reg 3
            } PACKED;

            struct //setUnsecureMemoryRegion
            {
                uint16_t cd6_memRegion_Reserved;        //Mbx Reg 0
                uint16_t cd6_memRegion_ControlFlags;    //Mbx Reg 0
                uint16_t cd6_memRegion_SeqID;           //Mbx Reg 0
                uint8_t  cd6_memRegion_CommandClass;    //Mbx Reg 0
                uint8_t  cd6_memRegion_Command;         //Mbx Reg 0
                uint32_t cd6_memRegion_MbxReg1reserved; //Mbx Reg 1
                uint32_t cd6_memRegion_Size;            //Mbx Reg 1
                uint64_t cd6_memRegion_Start_Addr;      //Mbx Reg 2
                uint64_t cd6_memRegion_MbxReg3reserved; //Mbx Reg 3
            } PACKED;

            struct //setFFDCAddress
            {
                uint16_t cd7_setFFDCAddr_Reserved;
                uint16_t cd7_setFFDCAddr_ControlFlags;
                uint16_t cd7_setFFDCAddr_SeqID;
                uint8_t  cd7_setFFDCAddr_CommandClass;
                uint8_t  cd7_setFFDCAddr_Command;
                uint32_t cd7_setFFDCAddr_FFDCSize; // mbxReg1 / dataWord2
                uint32_t cd7_setFFDCAddr_CommSize; // mbxReg1 / dataWord3
                uint64_t cd7_setFFDCAddr_FFDCAddr; // mbxReg2
                uint64_t cd7_setFFDCAddr_CommAddr; // mbxReg3
            } PACKED;

            struct //readSeeprom
            {
                uint16_t cd7_readSeeprom_Reserved;
                uint16_t cd7_readSeeprom_ControlFlags;
                uint16_t cd7_readSeeprom_SeqId;
                uint8_t  cd7_readSeeprom_CommandClass;
                uint8_t  cd7_readSeeprom_Command;
                uint32_t cd7_readSeeprom_SeepromOffset;   // mbxReg1
                uint32_t cd7_readSeeprom_ReadSize;        // mbxReg1
                uint64_t cd7_readSeeprom_DestinationAddr; // mbxReg2
                uint64_t cd7_readSeeprom_MbxReg3Reserved; // mbxReg3
            } PACKED;

            struct // sendOcmbConfig
            {
                // Mailbox Registry 0, Bytes 0..3
                uint16_t cd7_sendOcmbConfig_Reserved0;     // Mbx Reg 0, Bytes 0..1
                uint16_t cd7_sendOcmbConfig_Reserved1;     // Mbx Reg 0, Bytes 2..3
                // Mailbox Registry 0, Bytes 4..7
                uint16_t cd7_sendOcmbConfig_SeqID;         // Mbx Reg 0, Bytes 4..5
                uint8_t  cd7_sendOcmbConfig_CommandClass;  // Mbx Reg 0, Byte 6: 0xD7 (SBE_PSU_GENERIC_MESSAGE)
                uint8_t  cd7_sendOcmbConfig_Command;       // Mbx Reg 0, Byte 7: 0x09 (SBE_PSU_OCMB_CONFIG)

                /// The port information for an OCMB target instance X (IX),
                /// where the OCMB instance is define by FAPI_POS % 16.
                // Mailbox Registry 1, Bytes 0..3
                uint8_t  cd7_sendOcmbConfig_I0_port;       // Mbx Reg 1, Byte 0
                uint8_t  cd7_sendOcmbConfig_I1_port;       // Mbx Reg 1, Byte 1
                uint8_t  cd7_sendOcmbConfig_I2_port;       // Mbx Reg 1, Byte 2
                uint8_t  cd7_sendOcmbConfig_I3_port;       // Mbx Reg 1, Byte 3
                // Mailbox Registry 1, Bytes 4..7
                uint8_t  cd7_sendOcmbConfig_I4_port;       // Mbx Reg 1, Byte 4
                uint8_t  cd7_sendOcmbConfig_I5_port;       // Mbx Reg 1, Byte 5
                uint8_t  cd7_sendOcmbConfig_I6_port;       // Mbx Reg 1, Byte 6
                uint8_t  cd7_sendOcmbConfig_I7_port;       // Mbx Reg 1, Byte 7
                // Mailbox Registry 2, Bytes 0..3
                uint8_t  cd7_sendOcmbConfig_I8_port;       // Mbx Reg 2, Byte 0
                uint8_t  cd7_sendOcmbConfig_I9_port;       // Mbx Reg 2, Byte 1
                uint8_t  cd7_sendOcmbConfig_IA_port;       // Mbx Reg 2, Byte 2
                uint8_t  cd7_sendOcmbConfig_IB_port;       // Mbx Reg 2, Byte 3
                // Mailbox Registry 2, Bytes 4..7
                uint8_t  cd7_sendOcmbConfig_IC_port;       // Mbx Reg 2, Byte 4
                uint8_t  cd7_sendOcmbConfig_ID_port;       // Mbx Reg 2, Byte 5
                uint8_t  cd7_sendOcmbConfig_IE_port;       // Mbx Reg 2, Byte 6
                uint8_t  cd7_sendOcmbConfig_IF_port;       // Mbx Reg 2, Byte 7

                // Mailbox Registry 3, Bytes 0..3
                uint8_t  cd7_sendOcmbConfig_engine;        // Mbx Reg 3, Byte 0
                uint8_t  cd7_sendOcmbConfig_devAddr;       // Mbx Reg 3, Byte 1
                uint16_t cd7_sendOcmbConfig_function_state;  // Mbx Reg 3, Byte 2..3
                // Mailbox Registry 3, Bytes 4..7
                uint32_t cd7_sendOcmbConfig_Reserved2;     // Mbx Reg 3, Byte 4..7
            } PACKED;

            struct //syncFabTopoIdTable D7/0A
            {
                uint16_t cd7_syncFabTopoIdTable_Reserved;
                uint16_t cd7_syncFabTopoIdTable_ControlFlags;
                uint16_t cd7_syncFabTopoIdTable_SeqID;
                uint8_t  cd7_syncFabTopoIdTable_CommandClass;
                uint8_t  cd7_syncFabTopoIdTable_Command;
                uint64_t cd7_syncFabTopoIdTable_Address; // mbxReg1
                uint8_t  cd7_syncFabTopoIdTable_Reserved1[6]; // mbxReg2
                uint16_t cd7_syncFabTopoIdTable_Length; // mbxReg2
                uint64_t cd7_syncFabTopoIdTable_Reserved2; // mbxReg3
            } PACKED;


            psuCommand(uint16_t i_controlFlags, //Mbx Reg 0 input
                       uint8_t  i_commandClass, //Mbx Reg 0 input
                       uint8_t  i_command) :    //Mbx Reg 0 input

                       //setting BYTE 0 & 1     Mbx Reg 0
                       reserved (0),
                       //setting BYTE 2 & 3     Mbx Reg 0
                       controlFlags(i_controlFlags),
                       //setting BYTE 4 & 5     Mbx Reg 0
                       seqID(0),
                       //setting BYTE 6         Mbx Reg 0
                       commandClass(i_commandClass),
                       //setting BYTE 7         Mbx Reg 0
                       command(i_command),
                       //setting BYTE 8- Byte 11 - Mbx Reg 1
                       dataWord2(0),
                       //setting BYTE 12- Byte 15 - Mbx Reg 1
                       dataWord3(0),
                       //setting BYTE 16- Byte 19 - Mbx Reg 2
                       dataWord4(0),
                       //setting BYTE 20- Byte 23 - Mbx Reg 2
                       dataWord5(0),
                       //setting BYTE 24- Byte 27 - Mbx Reg 3
                       dataWord6(0),
                       //setting BYTE 28- Byte 31 - Mbx Reg 3
                       dataWord7(0)
            {
            }

        };  // end union psuCommand

        /**
         * @brief Struct for PSU response message format
         *
         */
        union psuResponse
        {
            struct //raw
            {
                uint64_t mbxReg4;
                uint64_t mbxReg5;
                uint64_t mbxReg6;
                uint64_t mbxReg7;
            } PACKED;
            struct //common and direct fields
            {
                // mbxReg 4
                uint16_t primaryStatus;
                uint16_t secondaryStatus;
                uint16_t seqID;
                uint8_t  commandClass;
                uint8_t  command;
                // mbxReg 5
                uint32_t respWord0;
                uint32_t respWord1;
                // mbxReg 6
                uint32_t respWord2;
                uint32_t respWord3;
                // mbxReg 7
                uint32_t respWord4;
                uint32_t respWord5;
            } PACKED;
            struct // indirect fields
            {
                // mbxReg 4
                uint16_t indirect_primaryStatus;
                uint16_t indirect_secondaryStatus;
                uint16_t indirect_seqID;
                uint8_t  indirect_commandClass;
                uint8_t  indirect_command;
                // mbxReg 5
                uint32_t indirect_respWord0;
                uint32_t indirect_respWord1;
                // mbxReg 6
                uint32_t indirect_respWord2;
                uint32_t indirect_respWord3;
                // mbxReg 7
                uint32_t indirect_reserved;
                uint32_t indirect_size;  //Size in dbl words for Indirect data
            } PACKED;

            // Complies with document Host_SBE_Interface_Specification_v0.9e.pdf
            struct // fields for the SBE Capabilities response
            {
                // mbxReg 4
                uint16_t sbe_primaryStatus;
                uint16_t sbe_secondaryStatus;
                uint16_t sbe_seqID;
                uint8_t  sbe_commandClass;  // 0xD7 (SBE_PSU_GENERIC_MESSAGE)
                uint8_t  sbe_command;       // 0x02 (SBE_PSU_MSG_GET_CAPABILITIES)
                // mbxReg 5
                uint32_t sbe_reserved1;
                uint32_t sbe_capabilities_size;  // Size of Capabilities data returned in bytes
                // mbxReg 6
                uint16_t sbe_major_version;
                uint16_t sbe_minor_version;
                uint32_t sbe_commit_id;
                // mbxReg 7
                uint64_t sbe_reserved2;
            } PACKED;

            struct // fields for the SBE get hw register response
            {
                // mbxReg 4
                uint16_t getHwReg_primaryStatus;
                uint16_t getHwReg_secondaryStatus;
                uint16_t getHwReg_seqID;
                uint8_t  getHwReg_commandClass;
                uint8_t  getHwReg_command;
                // mbxReg 5
                uint64_t getHwReg_value;
                // mbxReg 6
                uint64_t getHwReg_mbx6_reserved;
                // mbxReg 7
                uint64_t getHwReg_mbx7_reserved;
            } PACKED;

            psuResponse() :
                primaryStatus (0xffff),   //invalid status
                secondaryStatus (0xffff), //invalid status
                seqID (0xffff),           //unlikely seq ID
                commandClass (0xff),      //invalid command class
                command (0xff),           //invalid command
                respWord0 (0),
                respWord1 (0),
                respWord2 (0),
                respWord3 (0),
                respWord4 (0),
                respWord5 (0)
            {
            }

        };  // end struct psuResponse

        /**
         * @brief timeout values
         * Making this value big enough to handle being queued up
         *  behind a slow FSP operation (e.g. getmempba)
         */
        static const uint64_t MAX_PSU_SHORT_TIMEOUT_NS=90*NS_PER_SEC; //=90sec

        /**
         * @brief get SBE FFDC buffer size
         *
         * @return const size_t Size of SBE FFDC buffer.
         */
        const size_t getSbeFFDCBufferSize(void)
        {
            return (ffdcPackageSize * PAGESIZE);
        }

        // Structure to give to performPsuChipOp to indicate how unsupported
        // PSU commands should be handled.
        struct unsupported_command_error_severity
        {
            ERRORLOG::errlSeverity_t error_sev = { };
        };

        // Constant error policy instructing performPsuChipOp to not create an
        // error when the command is not supported.
        const static unsupported_command_error_severity COMMAND_SUPPORT_OPTIONAL;

        /**
         * @brief perform SBE PSU chip-op
         *
         * @param[in]  i_target         Proc target to use for PSU Request
         * @param[in]  i_pPsuRequest    Pointer to PSU request commands
         * @param[out] o_pPsuResponse   Pointer to PSU response
         * @param[in]  i_timeout        Time out for response
         * @param[in]  i_reqMsgs        4 bit mask telling which regs to write
         * @param[in]  i_rspMsgs        4 bit mask telling which regs to read
         * @param[in]  i_supportErrSeverity  "Operation not supported" errors will be created with the
         *                                   given severity. COMMAND_SUPPORT_OPTIONAL means no error
         *                                   will be created.
         * @param[out] o_unsupportedOp  Whether the SBE responded with "unsupported operation"
         */
        errlHndl_t performPsuChipOp(TARGETING::Target * i_target,
                                    psuCommand        * i_pPsuRequest,
                                    psuResponse       * o_pPsuResponse,
                                    const uint64_t      i_timeout,
                                    uint8_t             i_reqMsgs,
                                    uint8_t             i_rspMsgs,
                                    unsupported_command_error_severity i_supportErrSeverity
                                        = { ERRORLOG::ERRL_SEV_UNRECOVERABLE },
                                    bool*               o_unsupportedOp = nullptr);

        /**
         * @brief save information from an "early" error
         *
         * If an error occurs before the fapi2 library is loaded, this
         * function will record the error state so it can be reported later.
         *
         *
         * @param[in]  i_plid   Platform log id for the error
         * @param[in]  i_target Proc target for PSU Request that caused an error
         */
        void saveEarlyError(uint32_t i_plid,TARGETING::TargetHandle_t i_target);

        /**
         * @brief Did an error occur before the fapi2 library was loaded?
         */
        bool earlyError() {return iv_earlyErrorOccurred;}

        /**
         * @brief If an "early" error was detected, then record and process it.
         */
        errlHndl_t processEarlyError();

    protected:

        /**
         * @Brief Constructor
         */

        SbePsu();

        /**
         * @Brief Destructor
         */

        ~SbePsu();

        /**
         * Start message handler
         *
         * @note This function is used to spawn a new task.
         *       The args and return value are not used.
         */
        static void* msg_handler(void * unused);

    private:
    //---------------------------------------------------------------------
    // Local definitions for the device driver
    //---------------------------------------------------------------------

        /**
         * @brief Write FFDC package buffer - map of memory allocated
         * for each target's FFDC package.  Indexed by TARGETING
         */
        std::map<TARGETING::Target *, void *> iv_ffdcPackageBuffer;

        /**
         * @brief Variables needed to record an "early" error
         *
         * If an error occurs before the fapi2 library is loaded, then
         * use these variables to record the error for later reporting.
         */
        bool                      iv_earlyErrorOccurred;
        uint32_t                  iv_earlyErrorPlid;
        TARGETING::TargetHandle_t iv_earlyErrorTarget;

        /**
         * @brief FFDC package needs to be 2 pages
         */
        const uint8_t ffdcPackageSize = 2;

        /**
         * @brief Response buffer from SBE
         */
        psuResponse * iv_psuResponse;

        /**
         * @brief Indicator that PSU response is fully populated
         */
        bool iv_responseReady;

        /**
         * @brief SBE PSU Message Queue
         */
        msg_q_t iv_msgQ;

        /**
         * @brief Indicator if HB is shutting down
         */
        bool iv_shutdownInProgress;

        /**
         * The sbe psu message handler.
         */
        void msgHandler();

        /**
         * @brief allocate an ffdc buffer for the proc target
         * @param[in]  i_target       proc to have ffdc buffer allocated
         */
        errlHndl_t allocateFFDCBuffer(TARGETING::Target * i_target);

        /**
         * @brief utility to find an allocated FFDC buffer
         * @param[in]  i_target       proc to that had ffdc buffer allocated
         */
        void * findFFDCBufferByTarget(TARGETING::Target * i_target);

        /**
         * @brief Write request to PSU
         *
         * @param[in]  i_target       Master proc to use for scoms
         * @param[in]  i_pPsuRequest  Pointer to PSU request commands
         * @param[in]  i_reqMsgs      4 bit mask telling which regs to write
         *
         * @return errlHndl_t Error log handle on failure.
         */
        errlHndl_t writeRequest(TARGETING::Target  * i_target,
                                psuCommand         * i_pPsuRequest,
                                uint8_t              i_reqMsgs);
        /**
         * @brief Check response from PSU
         *
         * @param[in]  i_target       Master proc to use for scoms
         * @param[in]  i_pPsuRequest  Pointer to PSU request commands
         * @param[out] o_pPsuResponse Pointer to PSU response
         * @param[in]  i_timeout      Time out for response
         * @param[in]  i_rspMsgs      4 bit mask telling which regs to read
         *
         * @return errlHndl_t Error log handle on failure.
         */
        errlHndl_t checkResponse(TARGETING::Target  * i_target,
                                psuCommand         * i_pPsuRequest,
                                psuResponse        * o_pPsuResponse,
                                const uint64_t       i_timeout,
                                uint8_t              i_rspMsgs);
        /**
         * @brief Poll for response ready to be read
         *
         * @param[in]  i_target       Master proc to use for scoms
         * @param[in]  i_timeout      Time out for response
         * @param[in]  i_pPsuRequest  PSU request (for FFDC)
         *
         * @return errlHndl_t Error log handle on failure.
         */
        errlHndl_t pollForPsuComplete(TARGETING::Target * i_target,
                                      const uint64_t i_timeout,
                                      psuCommand* i_pPsuRequest);
        /**
         * @brief Read Scom wrapper
         *
         * @param[in]  i_target       Master proc to use for scoms
         * @param[in]  i_addr         Scom address
         * @param[out] o_pData        Pointer to returned data
         * @param[in]  i_trace        Trace control to avoid overruning
         *                            trace buffer when polling for
         *                            response ready to be read
         *
         * @return errlHndl_t Error log handle on failure.
         */
        errlHndl_t readScom(TARGETING::Target * i_target,
                             uint64_t   i_addr,
                             uint64_t * o_pData,
                             bool       i_trace=true);

        /**
         * @brief Write Scom wrapper
         *
         * @param[in]  i_target       Master proc to use for scoms
         * @param[in]  i_addr         Scom address
         * @param[in]  i_pData        Pointer to data to write
         *
         * @return errlHndl_t Error log handle on failure.
         */
        errlHndl_t writeScom(TARGETING::Target * i_target,
                              uint64_t   i_addr,
                              uint64_t * i_pData);

        /**
         * @brief Handle PSU Interrupt
         *
         * @param[in] i_pir  The PIR value of the proc that
         *                    has the interrupt condition
         *
         *  @return errlHndl_t Error log handle on failure
         */
        errlHndl_t handleInterrupt(PIR_t i_pir);

        /**
         * @brief SBE PSU register addresses
         */
        enum psuRegs
        {
            PSU_HOST_SBE_MBOX0_REG    = 0x000D0050,
            PSU_HOST_SBE_MBOX1_REG    = 0x000D0051,
            PSU_HOST_SBE_MBOX2_REG    = 0x000D0052,
            PSU_HOST_SBE_MBOX3_REG    = 0x000D0053,
            PSU_HOST_SBE_MBOX4_REG    = 0x000D0054,
            PSU_HOST_SBE_MBOX5_REG    = 0x000D0055,
            PSU_HOST_SBE_MBOX6_REG    = 0x000D0056,
            PSU_HOST_SBE_MBOX7_REG    = 0x000D0057,
            PSU_SBE_DOORBELL_REG_RW   = 0x000D0060,
            PSU_SBE_DOORBELL_REG_AND  = 0x000D0061,
            PSU_SBE_DOORBELL_REG_OR   = 0x000D0062,
            PSU_HOST_DOORBELL_REG_RW  = 0x000D0063,
            PSU_HOST_DOORBELL_REG_AND = 0x000D0064,
            PSU_HOST_DOORBELL_REG_OR  = 0x000D0065,
        };

        /**
         * @brief SBE PSU door bell register
         */
        enum sbeDoorbellReg
        {
            // Doorbell Register to trigger SBE interrupt
            // psu_sbe_interrupt_msg_available. Set by host firmware to inform
            // the SBE about a waiting message in the Host/SBE Mailbox Registers
            SBE_DOORBELL      =0x8000000000000000,
        };
        enum hostDoorbellReg
        {
            // Doorbell Register for Host Bridge interrupt. Set by the SBE to
            // inform host firmware about a response message in the Host/SBE
            // Mailbox Registers
            HOST_RESPONSE_WAITING       = 0x8000000000000000,
            HOST_CLEAR_RESPONSE_WAITING = 0x7FFFFFFFFFFFFFFF,
        };


}; // End of Class SbePsu

} // End of namespace SBEIO

#endif
