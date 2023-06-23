/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_fifodd.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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

#ifndef __SBE_FIFODD_H
#define __SBE_FIFODD_H

/**
 * @file sbe_fifodd.H
 * @brief SBE service provider declaration
 */

#include <stdint.h>
#include <builtins.h>
#include <sys/time.h>

#include <errl/errlentry.H>
#include <util/singleton.H>
#include <error_info_defs.H>
#include <sbeio/sbe_utils.H>

#include <ody_sbe_attribute_data_size.H>

namespace SBEIO
{

// forward declare
class SbeFifoRespBuffer;

//-----------------------------------------------------------------------------
//  Interfaces to the SBE FIFO device driver to be used by clients
//  within this component.
//-----------------------------------------------------------------------------

/** @class SbeFifo
 *  *  @brief Class for SBE/FIFO communication
 *  */

class SbeFifo
{
public:

    /**
     * @brief get the instance of this class
     *
     * @return the (one and only) instance of SbeFifo
     */

    static SbeFifo & getTheInstance();

    /**
     * @brief enums for SBE command class
     */
    enum fifoCommandClass
    {
        SBE_FIFO_CLASS_UNKNOWN              = 0,
        SBE_FIFO_CLASS_IPL_CONTROL          = 0xA1,
        SBE_FIFO_CLASS_SCOM_ACCESS          = 0xA2,
        SBE_FIFO_CLASS_RING_ACCESS          = 0xA3, // Unsupported by Hostboot, included here for completeness.
        SBE_FIFO_CLASS_MEMORY_ACCESS        = 0xA4,
        SBE_FIFO_CLASS_REGISTER_ACCESS      = 0xA5,
        SBE_FIFO_CLASS_ARRAY_ACCESS         = 0xA6,
        SBE_FIFO_CLASS_INSTRUCTION_CONTROL  = 0xA7,
        SBE_FIFO_CLASS_GENERIC_MESSAGE      = 0xA8,
        SBE_FIFO_CLASS_MPIPL_COMMANDS       = 0xA9,
        SBE_FIFO_CLASS_DUMP_MESSAGES        = 0xAA,
        SBE_FIFO_CLASS_HOST_COMMANDS        = 0xAB,
        SBE_FIFO_CLASS_TELEMETRY_COMMANDS   = 0xAC,
        SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES   = 0xAD, // Only supported on Odyssey chips
        SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES = 0xAE, // Only supported on Odyssey chips
    };

    /**
     * @brief enums for IPL Control Messages
     */
    enum fifoIplControlMessages
    {
        SBE_FIFO_CMD_EXECUTE_ISTEP = 0x01,
        SBE_FIFO_CMD_EXECUTE_HWP   = 0x04, // Odyssey only
    };

    /**
     * @brief enums for FIFO SCOM Access Messages
     */
    enum fifoScomAccessMessage
    {
        SBE_FIFO_CMD_GET_SCOM            = 0x01,
        SBE_FIFO_CMD_PUT_SCOM            = 0x02,
        SBE_FIFO_CMD_MODIFY_SCOM         = 0x03, // Deprecated for Odyssey
        SBE_FIFO_CMD_PUT_SCOM_UNDER_MASK = 0x04, // Deprecated for Odyssey
    };

    /**
     * @brief enums for FIFO MEMORY Access Messages
     */
    enum fifoMemoryAccessMessage
    {
        SBE_FIFO_CMD_GETMEM            = 0x01,
        SBE_FIFO_CMD_PUTMEM            = 0x02,
        /**
         *   Command buffer layout (6 32-bit words)
         *  |                 Length                       |
         *  |  reserved  |   reserved   | 0xA4   |   0x02  |
         *  | Chiplet Id | ECC override |      Flags       |
         *  |              Address 0:31                    |
         *  |             Address 32:63                    |
         *  |          Length of data (in bytes)           |
         *  |              Data....                        |
         **/
        PUTMEM_CMD_BUF_LEN_IN_WORDS    = 6,
        BYTES_PER_WORD                 = 4,
    };

    /**
     * @brief enums for FIFO PUT SRAM Messages
     */
    enum fifoPutSramMessage
    {
        SBE_FIFO_CMD_PUTSRAM           = 0x04,
        /**
         *   Command buffer layout (6 32-bit words)
         *  |                 Length                          |
         *  |  reserved  |   reserved   | 0xA4      |   0x04  |
         *  |       Chiplet Id          | reserved* |   mode  |
         *  |            SRAM Address 0:31                    |
         *  |            SRAM Address 32:63                   |
         *  |          Length of data (in bytes)              |
         *  |              Data....                           |
         *
         *  reserved* has multicast bit as 0th bit
         **/
        PUTSRAM_CMD_BUF_LEN_IN_WORDS    = 6,
    };

    /**
     * @brief enums for FIFO Generic Messages
     */
    enum fifoGenericMessage
    {
        SBE_FIFO_CMD_GET_SBE_FFDC        = 0x01,
        SBE_FIFO_CMD_GET_CAPABILITIES    = 0x02,
        SBE_FIFO_CMD_GET_CAPABILITIES_2  = 0x07, // Deprecated for Odyssey
    };

    /**
     * @brief enums for FIFO MPIPL Messages
     */
    enum fifoMpiplMessage
    {
        SBE_FIFO_CMD_ENTER_MPIPL         = 0x01,
        SBE_FIFO_CMD_CONTINUE_MPIPL      = 0x02,
        SBE_FIFO_CMD_STOP_CLOCKS         = 0x03,
    };

    enum fifoDumpMessage
    {
        SBE_FIFO_CMD_GET_DUMP            = 0x01,
    };

    /**
     * @brief enums for FIFO Host Messages
     */
    enum fifoHostMessage
    {
        SBE_FIFO_CMD_HOST_HALT           = 0x01,
    };

    enum fifoAttributeMessage
    {
        SBE_FIFO_CMD_ATTRIBUTE_DUMP   = 0x01,
        SBE_FIFO_CMD_ATTRIBUTE_LIST   = 0x02,
        SBE_FIFO_CMD_ATTRIBUTE_UPDATE = 0x03,
    };

    enum fifoCodeUpdateMessage
    {
        SBE_FIFO_CMD_GET_CODE_LEVELS  = 0x01,
        SBE_FIFO_CMD_UPDATE_IMAGE     = 0x02,
        SBE_FIFO_CMD_SYNC_CODE_LEVELS = 0x03,
    };

    /**
     * @brief enums for Telemetry Commands
     */
    enum fifoTelemetryMessage
    {
        SBE_FIFO_CMD_THERMAL_SENSOR_AND_DQA_POLLING = 0x02,
    };

    ///////////////////////////////////////////////////////////////////////
    //
    //                     SBE FIFO Requests/Responses
    //
    ///////////////////////////////////////////////////////////////////////
    /**
     * @brief enums for FIFO Magic values
     */
    enum fifoMagic
    {
        FIFO_STATUS_MAGIC   = 0xC0DE,
        FIFO_FFDC_MAGIC     = 0xFFDC,
        FIFO_ODY_FFDC_MAGIC = 0xFBAD,
    };

    /**
     * @brief Struct for FIFO status
     *
     */
    struct statusHeader
    {
        uint16_t  magic;     // set to 0xC0DE
        uint8_t   commandClass;
        uint8_t   command;
        uint16_t  primaryStatus;
        uint16_t  secondaryStatus;
    } PACKED;

    /**
     * @brief Struct for FIFO FFDC
     *
     */
    struct ffdcHeader
    {
        uint16_t  magic;     // set to 0xFFDC
        uint16_t  lengthWords;
        uint16_t  sequenceId;
        uint8_t   commandClass;
        uint8_t   command;
        uint32_t  returnCode;
    } PACKED;

    /**
     * @brief Struct for a standardFIFO response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoStandardResponse
    {
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoStandardResponse() {}  // do nothing
        ~fifoStandardResponse() {} // do nothing

        private:
        //Make copy ctor and assignment operator private to
        //avoid misuse
        fifoStandardResponse(const fifoStandardResponse&);
        fifoStandardResponse& operator=(const fifoStandardResponse&);
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     IPL Control Messages
    ///////////////////////////////////////////////////////////////////////
    /**
     * @brief Struct for FIFO Execute Istep request. Istep requests use the fifoStandardResponse.
     *
     */
    struct fifoExecuteIstepRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId; // Odyssey only, reserved field for P10
        uint8_t  commandClass;
        uint8_t  command;
        uint8_t  reserved2;
        uint8_t  istepMajorNum;
        uint8_t  reserved3;
        uint8_t  istepMinorNum;
        fifoExecuteIstepRequest() :
            wordCnt(3),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_IPL_CONTROL),
            command(SBE_FIFO_CMD_EXECUTE_ISTEP),
            reserved2(0),
            istepMajorNum(0),
            reserved3(0),
            istepMinorNum(0)
        {
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Execute Hardware Procedure. This message type is only supported on Odyssey chips.
     */
    struct fifoExecuteHardwareProcedureRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint8_t  reserved2;
        uint8_t  hwpClass;
        uint8_t  reserved3;
        uint8_t  hwpNumber;
        fifoExecuteHardwareProcedureRequest() :
            wordCnt(3),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_IPL_CONTROL),
            command(SBE_FIFO_CMD_EXECUTE_HWP),
            reserved2(0),
            hwpClass(0),
            reserved3(0),
            hwpNumber(0)
        {}

    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     SCOM Access Messages
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO Get SCOM request
     *
     */
    struct fifoGetScomRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId; // Odyssey only, reserved field for P10
        uint8_t  commandClass;
        uint8_t  command;
        uint64_t address;  // Register Address (0..31) + (32..63)
        fifoGetScomRequest() :
            wordCnt(4),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_SCOM_ACCESS),
            command(SBE_FIFO_CMD_GET_SCOM),
            address(0)
        {
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Get SCOM response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoGetScomResponse
    {
        uint64_t     data;          // Data (0..31) + (32..63)
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoGetScomResponse() {}
    } PACKED;

    /**
     * @brief Struct for FIFO Put SCOM request.
     *
     */
    struct fifoPutScomRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId; // Odyssey only, reserved field for P10
        uint8_t  commandClass;
        uint8_t  command;
        uint64_t address;     // Register Address (0..31) + (32..63)
        uint64_t data;        // Data (0..31) + (32..63)
        fifoPutScomRequest() :
            wordCnt(6),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_SCOM_ACCESS),
            command(SBE_FIFO_CMD_PUT_SCOM),
            address(0),
            data(0)
        {
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Put SCOM and Put SCOM under mask response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoPutScomResponse
    {
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoPutScomResponse() {}
    } PACKED;

    /**
     * @brief Struct for FIFO Put SCOM Under Mask request. This message type is not supported on Odyssey chips.
     *
     */
    struct fifoPutScomUnderMaskRequest
    {
        uint32_t wordCnt;
        uint16_t  reserved;
        uint8_t  commandClass;
        uint8_t  command;
        uint64_t address;     // Register Address (0..31) + (32..63)
        uint64_t data;        // Data (0..31) + (32..63)
        uint64_t mask;        // Mask Data (0..31) + (32..63)
        fifoPutScomUnderMaskRequest() :
            wordCnt(8),
            reserved(0),
            data(0),
            mask(0)
        {
        }
    } PACKED;
    ///////////////////////////////////////////////////////////////////////
    //                     Memory Access Messages
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO PutMem request. This message type is not supported on Odyssey chips.
     *
     */
    struct fifoPutMemRequest
    {
        // Note:
        // The SBE putMem command used in HB is not a 'real' putMem command.
        // It is used to tell SBE to run part of existing HWPs, via the flag
        // settings in order to avoid creating new SBE chip-op.
        // Therefore, coreChipletId and ECC_override are not used
        // and default to 0.
        // This is done so that HB doesn't invoke ADU SMP HWPs that access
        // black-listed registers as part of Secure boot work.
        uint32_t wordCnt;
        uint16_t  reserved;
        uint8_t  commandClass;
        uint8_t  command;
        uint8_t  coreChipletId;
        uint8_t  ECC_override;
        uint16_t flags;
        uint32_t address[2]; // address[0] = Address bits 0:31
        // address[1] = Address bits 32:63
        uint32_t dataLen;
        uint32_t *dataPtr;

        fifoPutMemRequest() :
            wordCnt(0),
            reserved(0),
            commandClass(SBE_FIFO_CLASS_MEMORY_ACCESS),
            command(SBE_FIFO_CMD_PUTMEM),
            coreChipletId(0),
            ECC_override(0),
            flags(0),
            dataLen(0),
            dataPtr(NULL)
        {
            address[0] = 0;
            address[1] = 0;
        }
        ~fifoPutMemRequest()
        {
        };
    } PACKED;

    /**
     * @brief Struct for FIFO PutMem response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoPutMemResponse
    {
        uint32_t     len_written; // Length of Mainstore Data actually written in bytes ( includes ECC and TAG )
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoPutMemResponse() {}
    } PACKED;

    /**
     * @brief Struct for FIFO PutSram request. This message type is not supported on Odyssey chips.
     *
     */
    struct fifoPutSramRequest
    {
        uint32_t wordCnt;
        uint16_t  reserved;
        uint8_t  commandClass;
        uint8_t  command;
        uint16_t pervChipletId;
        uint8_t  mcast : 1;
        uint8_t  reserved1 : 7;
        uint8_t  mode;
        uint32_t address[2];   // address[0] = Address bits 0:31
        // address[1] = Address bits 32:63
        uint32_t dataLenBytes; // Must be multiple of 8 bytes
        uint32_t data[];

        fifoPutSramRequest() :
            wordCnt(0),
            reserved(0),
            commandClass(SBE_FIFO_CLASS_MEMORY_ACCESS),
            command(SBE_FIFO_CMD_PUTSRAM),
            pervChipletId(0),
            mcast(0),
            reserved1(0),
            mode(0),
            dataLenBytes(0)
        {
            address[0] = 0;
            address[1] = 0;
        }
        ~fifoPutSramRequest()
        {
        };
    } PACKED;

    /**
     * @brief Struct for FIFO PutSram response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoPutSramResponse
    {
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoPutSramResponse() {}
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     Generic Access Messages
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO Get SBE FFDC request
     *
     */
    struct fifoGetSbeFfdcRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId; // Odyssey only, reserved field for P10
        uint8_t  commandClass;
        uint8_t  command;
        fifoGetSbeFfdcRequest() :
            wordCnt(2),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_GENERIC_MESSAGE),
            command(SBE_FIFO_CMD_GET_SBE_FFDC)
        {
        }
    } PACKED;


    /**
     * @brief Struct for FIFO Get Capabilities Request. This message type is only supported for Odyssey chips. P10 chips
     *        will continue to use fifoGetCapabilities2Request.
     *
     *        Struct for FIFO Get Capabilities response end uses fifoStandardResponse
     *        A variation of sbeCapabilities_t comes before that struct.
     *
     */
    struct fifoGetCapabilitiesRequest
    {
        uint32_t wordCnt;       // 0x02 (The number of 32 bits in msg)
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;  // (SBE_FIFO_CLASS_GENERIC_MESSAGE)
        uint8_t  command;       // (SBE_FIFO_CMD_GET_CAPABILITIES)
        fifoGetCapabilitiesRequest() :
            wordCnt(2),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_GENERIC_MESSAGE),
            command(SBE_FIFO_CMD_GET_CAPABILITIES)
        {
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Get Capabilities 2 Request including new additions. This message type is not supported for
     *        Odyssey chips. Odyssey chips should use fifoGetCapabilitiesRequest (note the lack of the 2).
     *
     *        Struct for FIFO Get Capabilities response end uses fifoStandardResponse
     *        A variation of sbeCapabilities2_t comes before that struct.
     *
     * Complies with document FipS_SBE_Interface_Specification_v1.5b-1.pdf
     */
    struct fifoGetCapabilities2Request
    {
        uint32_t wordCnt;       // 0x02 (The number of 32 bits in msg)
        uint16_t  reserved;
        uint8_t  commandClass;  // 0xA8 (SBE_FIFO_CLASS_GENERIC_MESSAGE)
        uint8_t  command;       // 0x07 (SBE_FIFO_CMD_GET_CAPABILITIES_2)
        fifoGetCapabilities2Request() :
            wordCnt(2)
            , reserved(0)
            , commandClass(SBE_FIFO_CLASS_GENERIC_MESSAGE)
            , command(SBE_FIFO_CMD_GET_CAPABILITIES_2)
        {
        }
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     MPIPL Messages
    ///////////////////////////////////////////////////////////////////////
    /**
     * @brief Struct for FIFO Continue MPIPL request. This message type is not supported for Odyssey chips.
     *
     */
    struct fifoContinueMpiplRequest
    {
        uint32_t wordCnt;
        uint16_t  reserved;
        uint8_t  commandClass;
        uint8_t  command;
        fifoContinueMpiplRequest() :
            wordCnt(2),
            reserved(0),
            commandClass(SBE_FIFO_CLASS_MPIPL_COMMANDS),
            command(SBE_FIFO_CMD_CONTINUE_MPIPL)
        {
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Continue MPIPL response
     *
     * The actual number of returned words varies based on whether there was
     * an error.
     */
    struct fifoContinueMpiplResponse
    {
        statusHeader status;
        struct       fapi2::ffdc_struct ffdc;  // ffdc data
        uint32_t     status_distance; // distance to status
        fifoContinueMpiplResponse() {}
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     Host FIFO Messages
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO Host Commands request. This message type is not supported for Odyssey chips
     *
     */
    struct fifoHostCommandsRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        fifoHostCommandsRequest() :
            wordCnt(2),
            reserved(0),
            commandClass(SBE_FIFO_CLASS_HOST_COMMANDS),
            command(SBE_FIFO_CMD_HOST_HALT)
        {
        }
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     Dump Messages
    ///////////////////////////////////////////////////////////////////////

    enum fifoDumpFastArray
    {
        SBE_FIFO_DUMP_COLLECT_FAST_ARRAYS = 0x0,
        SBE_FIFO_DUMP_SKIP_FAST_ARRAYS    = 0x1,
    };

    enum fifoDumpClockState
    {
        SBE_FIFO_DUMP_CLOCKS_ON  = 0x1,
        SBE_FIFO_DUMP_CLOCKS_OFF = 0x2,
    };

    enum fifoDumpType
    {
        SBE_FIFO_DUMP_SYSTEM_CHECK_STOP     = 0x01,
        SBE_FIFO_DUMP_MEMORY_PRESERVING_IPL = 0x02,
        SBE_FIFO_DUMP_SYSTEM_PERFORMANCE    = 0x03,
        SBE_FIFO_DUMP_CORE_CHECK_STOP       = 0x04,
        SBE_FIFO_DUMP_HOSTBOOT              = 0x05,
    };

    /**
     * @brief Struct for FIFO Dump request
     */
    struct fifoGetDumpRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId; // Odyssey only, reserved field for P10
        uint8_t  commandClass;
        uint8_t  command;
        uint8_t  reserved2;
        uint8_t  collectFastArray;
        uint8_t  clockState;
        uint8_t  dumpType;
        fifoGetDumpRequest() :
            wordCnt(3),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_DUMP_MESSAGES),
            command(SBE_FIFO_CMD_GET_DUMP),
            reserved2(0),
            collectFastArray(0),
            clockState(0),
            dumpType(0)
        {}
    } PACKED;



    ///////////////////////////////////////////////////////////////////////
    //     Telemetry command to control thermal sensor & DQA Polling
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO "Control Thermal Sensor Polling & DQA Tracking" Cmd
     */
    struct fifoExecuteControlThermalSensorRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint32_t interval;
        uint8_t  reserved1;
        uint8_t  reserved2;
        uint8_t  reserved3;
        uint8_t  dqa;

        fifoExecuteControlThermalSensorRequest() :
            wordCnt(0x4),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_TELEMETRY_COMMANDS),
            command(SBE_FIFO_CMD_THERMAL_SENSOR_AND_DQA_POLLING),
            reserved1(0),
            reserved2(0),
            reserved3(0)
        {}
    } PACKED;


    ///////////////////////////////////////////////////////////////////////
    //                     Attribute Messages
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief Struct for FIFO Attribute Raw Dump request. This message type is only supported on Odyssey chips.
     */
    struct fifoAttrRawDumpRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        fifoAttrRawDumpRequest() :
            wordCnt(2),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES),
            command(SBE_FIFO_CMD_ATTRIBUTE_DUMP)
        {}
    } PACKED;

    /**
     * @brief Struct for FIFO Attribute List request. This message type is only supported on Odyssey chips.
     */
    struct fifoAttrListRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint32_t AttrListRequest[];
        fifoAttrListRequest() :
            wordCnt(0),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES),
            command(SBE_FIFO_CMD_ATTRIBUTE_LIST)
        {}
    } PACKED;

    /**
     * @brief Struct for FIFO Attribute List response. This message type is only supported on Odyssey chips.
     */
    struct fifoAttrListResponse
    {
        uint8_t AttrListResponse[ODY_ATTR_LIST_CHIPOP_MAX_SIZE];
        fifoAttrListResponse() {}
    } PACKED;

    /**
     * @brief Struct for FIFO Attribute Update request. This message type is only supported on Odyssey chips.
     */
    struct fifoAttrUpdateRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint8_t AttrUpdateRequest[ODY_GENERATE_ATTR_DATA_SIZE];
        fifoAttrUpdateRequest() :
            wordCnt(0),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_ATTRIBUTE_MESSAGES),
            command(SBE_FIFO_CMD_ATTRIBUTE_UPDATE)
        {}
    } PACKED;

    /**
     * @brief Struct for FIFO Attribute Update response. This message type is only supported on Odyssey chips.
     */
    struct fifoAttrUpdateResponse
    {
        uint8_t AttrUpdateResponse[ODY_GENERATE_ATTR_DATA_SIZE];
        fifoAttrUpdateResponse() {}
    } PACKED;

    ///////////////////////////////////////////////////////////////////////
    //                     Code Update Access Messages
    ///////////////////////////////////////////////////////////////////////

    enum fifoUpdateImageType
    {
        SBE_FIFO_UPDATE_IMAGE_BOOTLOADER = 0x0001,
        SBE_FIFO_UPDATE_IMAGE_RUNTIME    = 0x0002,
        SBE_FIFO_UPDATE_BMC_OVERRIDE     = 0x0003,
        SBE_FIFO_UPDATE_HOST_VERRIDE     = 0x0004,
    };

    /**
     * @brief Struct for FIFO Get Code Levels request. This message type is only
     *        supported on Odyssey chips.
     */
    struct fifoGetCodeLevelsRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        fifoGetCodeLevelsRequest() :
            wordCnt(2),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES),
            command(SBE_FIFO_CMD_GET_CODE_LEVELS)
        {}
    } PACKED;

    /**
     * @brief Struct for FIFO Update Image request. Uses fifoStandardResponse. This message type is only supported on
     *        Odyssey chips.
     */
    struct fifoUpdateImageRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint16_t reserved2;
        uint16_t imageType;
        uint32_t imageSize;

        fifoUpdateImageRequest(const uint16_t i_image_type, const size_t i_image_size_bytes)
        {
            wordCnt = (sizeof(fifoUpdateImageRequest) + i_image_size_bytes) / sizeof(uint32_t);
            reserved = 0;
            chipId = 0;
            commandClass = SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES;
            command = SBE_FIFO_CMD_UPDATE_IMAGE;
            reserved2 = 0;
            imageType = i_image_type;
            imageSize = i_image_size_bytes / sizeof(uint32_t);
        }
    } PACKED;

    /**
     * @brief Struct for FIFO Sync Code Levels request. Uses fifoStandardResponse. This message type is only supported
     *        on Odyssey chips.
     */
    struct fifoSyncCodeLevelsRequest
    {
        uint32_t wordCnt;
        uint8_t  reserved;
        uint8_t  chipId;
        uint8_t  commandClass;
        uint8_t  command;
        uint16_t reserved2;
        uint16_t force_sync;

        fifoSyncCodeLevelsRequest(const uint16_t i_force_sync) :
            wordCnt(sizeof(fifoSyncCodeLevelsRequest) / sizeof(uint32_t)),
            reserved(0),
            chipId(0),
            commandClass(SBE_FIFO_CLASS_CODE_UPDATE_MESSAGES),
            command(SBE_FIFO_CMD_SYNC_CODE_LEVELS),
            reserved2(),
            force_sync(i_force_sync)
        {}
    } PACKED;
    ///////////////////////////////////////////////////////////////////////
    //
    //              End SBE FIFO Requests/Responses Section
    //
    ///////////////////////////////////////////////////////////////////////

    /**
     * @brief FIFO CFAM register addresses.
     *        These enums are used as input to an accessor method to get
     *        the addrs for a particular FIFO
     */
    enum fifoRegAddr
    {
        FIFO_UPFIFO_DATA_IN,
        FIFO_UPFIFO_STATUS,
        FIFO_UPFIFO_SIG_EOT,
        FIFO_UPFIFO_REQ_RESET,
        FIFO_DNFIFO_DATA_OUT,
        FIFO_DNFIFO_STATUS,
        FIFO_DNFIFO_RESET,
        FIFO_DNFIFO_ACK_EOT,
        FIFO_DNFIFO_MAX_TSFR,
    };

    /**
     * @brief FIFO CFAM register types
     *        These enums are used as input to an accessor method to get
     *        the addrs for a particular FIFO
     */
    enum fifoRegType
    {
        FIFO_SBE,
        FIFO_SPPE,
        FIFO_PIPE,
    };

    /**
     * @brief get the CFAM FIFO register addr from i_type/i_reg
     *
     * @param[in]  i_type    type of FIFO for addr
     * @param[in]  i_reg     register for the FIFO
     * @return     uint32_t  value of the register
     *                       0 - ERROR, no register found
     */
    uint32_t getFifoRegValue(fifoRegType i_type, fifoRegAddr i_reg);

    /**
     * @Brief perform SBE FIFO chip-op
     *
     * @param[in]  i_target        Target to access
     * @param[in]  i_pFifoRequest  Pointer to request
     * @param[in]  i_pFifoResponse Pointer to response
     * @param[in]  i_responseSize  Size of response in bytes
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t performFifoChipOp(TARGETING::Target * i_target,
            uint32_t * i_pFifoRequest,
            uint32_t * i_pFifoResponse,
            uint32_t   i_responseSize);

    /**
     * @brief A structure that provides a stream of data for writing
     *        to the SBE FIFO for chipops.
     */
    class fifo_chipop_data_stream
    {
    public:
        /**
         * @brief Attempt to read the given number of bytes from the
         *        stream.
         *
         * @param[out] o_buf  The output buffer for the data read.
         * @param[in]  i_amt  The maximum amount of data to read.
         * @return            The amount of data actually read.
         *                    If 0, the stream is at its end. This
         *                    may be less than i_amt, but if it is
         *                    greater than 0 it still does not
         *                    indicate end-of-stream.
         */
        virtual int read(void* o_buf, int i_amt) = 0;

        virtual ~fifo_chipop_data_stream() { }

        fifo_chipop_data_stream() = default;

        fifo_chipop_data_stream(const fifo_chipop_data_stream&) = delete;
        fifo_chipop_data_stream& operator=(const fifo_chipop_data_stream&) = delete;

        fifo_chipop_data_stream(fifo_chipop_data_stream&&) = default;
        fifo_chipop_data_stream& operator=(fifo_chipop_data_stream&&) = default;
    };

    /**
     * @Brief perform SBE FIFO chip-op and stream the request data.
     *
     * @param[in]  i_target         Target to access
     * @param[in]  i_requestStream  Request stream. Ownership is
     *                              taken by this function.
     * @param[in]  i_pFifoResponse  Pointer to response
     * @param[in]  i_responseSize   Size of response in bytes
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t performFifoChipOp(TARGETING::Target * i_target,
            fifo_chipop_data_stream&& i_requestStream,
            uint32_t * i_pFifoResponse,
            uint32_t   i_responseSize);

    /**
     * @Brief perform SBE FIFO reset
     *
     *        NOT to be used on running SBE -- only for IPL
     *
     * @param[in]  i_target        Target to access
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t performFifoReset(TARGETING::Target * i_target);

    /**
     * @Brief Setup the Access Control for the FIFO PIPE
     *
     *        NOT to be used on running SBE -- only for IPL
     *
     * @param[in]  i_target        Target to access
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t setupPipeAccess(TARGETING::Target *i_target);

protected:

    /**
     * @Brief Constructor
     */

    SbeFifo();

    /**
     * @Brief Destructor
     */

    ~SbeFifo();

    /**
     * @brief populate the iv_ffdcPackageBuffer
     * @param[in]  i_data        FFDC error data
     * @param[in]  i_len         data buffer len to copy
     */

    void writeFFDCBuffer(const void * i_data, uint32_t i_len);

private:

    /**
     * @brief Write FFDC package buffer - holds information exchanged
     * between SBE and HB
     */
    void * iv_ffdcPackageBuffer;

    /**
     * @brief zero out the FFDC package buffer
     */
    void initFFDCPackageBuffer();

    //-------------------------------------------------------------------
    // Local definitions for the device driver
    //-------------------------------------------------------------------

    /**
     * @brief get the register addr from the enum index
     *
     *        SBE FIFO CFAM register addresses. These addresses will be
     *        translated at the FSI device driver layer into their byte address
     *        equivalents which is what the SBE FIFO expects to receive.
     *
     * @param[in] i_reg     index of the register value to return
     * @return    uint32_t  value of the register
     *                      0 - ERROR, no register found
     */
    uint32_t getSbeFifoRegValue(fifoRegAddr i_reg);

    /**
     * @brief get the register addr from the enum index
     *
     *        SPPE FIFO CFAM register addresses. These addresses will be
     *        translated at the FSI device driver layer into their byte address
     *        equivalents which is what the SBE FIFO expects to receive.
     *
     * @param[in] i_reg     index of the register value to return
     * @return    uint32_t  value of the register
     *                      0 - ERROR, no register found
     */
    uint32_t getSppeFifoRegValue(fifoRegAddr i_reg);

    /**
     * @brief get the register addr from the enum index
     *
     *        PIPE FIFO CFAM register addresses. These addresses will be
     *        translated at the FSI device driver layer into their byte address
     *        equivalents which is what the SBE FIFO expects to receive.
     *
     * @param[in] i_reg     index of the register value to return
     * @return    uint32_t  value of the register
     *                      0 - ERROR, no register found
     */
    uint32_t getPipeFifoRegValue(fifoRegAddr i_reg);

    /**
     * @brief send a request via SBE FIFO using a data stream.
     *
     * @param[in]  i_target         Target to access
     * @param[in]  i_stream         Stream for request data.
     *                              First word has count of uint32_t words.
     * @param[out] o_request_header The first two words of the request.
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t writeRequest(TARGETING::Target * i_target,
                            fifo_chipop_data_stream& i_stream,
                            std::array<uint32_t, 2>& o_request_header);

    /**
     * @brief read the response via SBE FIFO
     *
     * @param[in]  i_target         Target to access
     * @param[in]  i_pFifoRequest   Pointer to FIFO request.
     * @param[out] o_pFifoResponse  Pointer to FIFO response.
     * @param[in]  i_responseSize   Size of response buffer in bytes.
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t readResponse(TARGETING::Target * i_target,
            uint32_t * i_pFifoRequest,
            uint32_t * o_pFifoResponse,
            uint32_t   i_responseSize);

    /**
     * @brief poll until uplift Fifo has room to write into
     *
     * @param[in]  i_target         Target to access
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t waitUpFifoReady(TARGETING::Target * i_target);

    /**
     * @brief  Wait for data in downstream fifo to receive, hit EOT, or timeout.
     *         Add each entry to the RespBuffer and do the RespBuffer
     *         completeMessage upon receiving EOT.
     *
     * @param[in]  i_target         Target to access
     * @param[out] o_status         Down load door bell status
     * @param[out] o_EOT            indicates if an EOT was received
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t waitDnFifoReady(TARGETING::Target   * i_target,
                          SBEIO::SbeFifoRespBuffer & o_fifoBuffer,
                                          bool     & o_EOT);

    /**
     * @brief Read and parse the receive side FIFO register(s)
     *
     * @param[in]  i_target         Target to access
     * @param[out] o_data           Down load door bell data
     * @param[out] o_status         Down load door bell status
     * @param[out] o_EMPTY          indicates if an entry was received
     * @param[out] o_EOT            indicates if an EOT was received
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t parseDataOutReg(TARGETING::Target   *i_target,
                                          uint32_t &o_data,
                                          uint32_t &o_status,
                                          bool     &o_EMPTY,
                                          bool     &o_EOT);

    /**
     * @brief Encapsulates a FIFO read.
     *
     * @param[in]  i_target         Target to access
     * @param[in]  i_addrIdx        FIFO address enum index
     * @param[out] o_pData          Pointer to receive data
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t readFifoReg(TARGETING::Target   *i_target,
                                    fifoRegAddr i_addrIdx,
                                      uint32_t *o_pData);

    errlHndl_t readFifoReg64(TARGETING::Target     *i_target,
                                        fifoRegAddr i_addrIdx,
                                        uint64_t   *o_pData);

    /**
     * @brief Encapsulates a Fifo write.
     *
     * @param[in]  i_target         Target to access
     * @param[in]  i_addrIdx        FIFO address enum index
     * @param[in]  i_pData          Pointer to receive data
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t writeFifoReg(TARGETING::Target   *i_target,
                                     fifoRegAddr i_addrIdx,
                                       uint32_t *i_pData);

    enum sbeFifoUpstreamStatus
    {
        // Reserved
        UPFIFO_STATUS_RESERVED0 =0xC0000000,
        // Parity Error: dequeuing operation has detected a data parity error
        UPFIFO_STATUS_PARITY_ERROR =0x20000000,
        // Reserved
        UPFIFO_STATUS_RESERVED3 =0x1C000000,
        // External Service Processor (SP) is requesting a FIFO reset
        UPFIFO_STATUS_REQ_RESET_FR_SP =0x02000000,
        // SBE is requesting a FIFO reset through downstream path
        UPFIFO_STATUS_REQ_RESET_FR_SBE =0x01000000,
        // A fifo entry has been dequeued with set EOT flag
        UPFIFO_STATUS_DEQUEUED_EOT_FLAG =0x00800000,
        // Reserved
        UPFIFO_STATUS_RESERVED9 =0x00400000,
        // Upstream FIFO is full
        UPFIFO_STATUS_FIFO_FULL =0x00200000,
        // Upstream FIFO is empty
        UPFIFO_STATUS_FIFO_EMPTY =0x00100000,
        // Number of entries currently in FIFO
        UPFIFO_STATUS_FIFO_ENTRY_COUNT =0x000F0000,
        // Valid flags of entries currently in FIFO
        UPFIFO_STATUS_FIFO_VALID_FLAGS =0x0000FF00,
        // EOT flags of entries currently in FIFO
        UPFIFO_STATUS_FIFO_EOT_FLAGS =0x000000FF,
    };

    enum sbeUpstreamEot
    {
        FSB_UPFIFO_SIG_EOT =0x80000000,
    };

    enum sbeFifoReqUpstreamFifoReset
    {
        FSB_UPFIFO_REQ_RESET =0x80000000,
    };

    enum sbeFifoDownstreamStatus
    {
        // Reserved
        DNFIFO_STATUS_RESERVED0 =0xC0000000,
        // Parity Error: dequeuing operation has detected a data parity error
        DNFIFO_STATUS_PARITY_ERROR =0x20000000,
        // Reserved
        DNFIFO_STATUS_RESERVED3 =0x1C000000,
        // SBE is requesting a FIFO reset
        DNFIFO_STATUS_REQ_RESET_FR_SP =0x02000000,
        // Service Processor (SP) is requesting a FIFO reset
        // through downstream path
        DNFIFO_STATUS_REQ_RESET_FR_SBE =0x01000000,
        // A fifo entry has been dequeued with set EOT flag
        DNFIFO_STATUS_DEQUEUED_EOT_FLAG =0x00800000,
        // Reserved
        DNFIFO_STATUS_RESERVED9 =0x00400000,
        // Downstream FIFO is full
        DNFIFO_STATUS_FIFO_FULL =0x00200000,
        // Downstream FIFO is empty
        DNFIFO_STATUS_FIFO_EMPTY =0x00100000,
        // Number of currently hold entries
        DNFIFO_STATUS_FIFO_ENTRY_COUNT =0x000F0000,
        // Valid flags of ALL currently hold entries
        DNFIFO_STATUS_FIFO_VALID_FLAGS =0x0000FF00,
        // EOT flags of ALL currently hold entries
        DNFIFO_STATUS_FIFO_EOT_FLAGS =0x000000FF,
    };

    enum sbePipeDownstreamStatus
    {
        DNFIFO_STATUS_VALID = 0x80000000,
        DNFIFO_STATUS_EOT   = 0x40000000
    };

    enum sbeFifoReqDownstreamFifoReset
    {
        FSB_DNFIFO_REQ_RESET =0x80000000,
    };

    enum sbeDownstreamEot
    {
        FSB_DNFIFO_ACK_EOT =0x80000000,
    };

    // max wait for a FIFO to have room to write
    enum { MAX_UP_FIFO_TIMEOUT_NS = 90000*NS_PER_MSEC }; //=90s

    // max wait for a FIFO to present data and/or EOT to receive
    enum { MAX_DWN_FIFO_TIMEOUT_NS = 2*90000*NS_PER_MSEC }; //=180s

}; // End of classSbeFifo

/**
 * @brief An SBE FIFO chipop data stream that reads a range of bytes
 *        in memory.
 */
class memory_stream : public SbeFifo::fifo_chipop_data_stream
{
    size_t length = 0, offset = 0;
    const uint8_t* data = nullptr;

public:
    int read(void* const o_buf, const int i_amt) override
    {
        int amt_read = 0;

        if (offset < length)
        {
            amt_read = std::min(length - offset, static_cast<size_t>(i_amt));

            memcpy(o_buf, data + offset, amt_read);
            offset += amt_read;
        }

        return amt_read;
    }

    memory_stream(const void* const i_data, const size_t i_len)
        : length(i_len), data(reinterpret_cast<const uint8_t*>(i_data))
    { }
};

/**
 * @brief An SBE FIFO chipop data stream that combines other streams
 *        in sequence. Constructed with a list of streams, a stream_cat
 *        will return all the data from the first stream, then all the
 *        data from the second stream, etc.
 */
template<size_t NumStreams>
class stream_cat : public SbeFifo::fifo_chipop_data_stream
{
    size_t active_stream = 0;
    std::array<SbeFifo::fifo_chipop_data_stream*, NumStreams> streams;

public:
    template<typename... Args>
    stream_cat(Args&&... args)
        : streams({ std::forward<Args>(args)... })
    { }

    int read(void* const o_buf, const int i_amt) override
    {
        int amt_read = 0;

        if (active_stream < streams.size())
        {
            amt_read = streams[active_stream]->read(o_buf, i_amt);

            if (amt_read == 0)
            {
                ++active_stream;
                return read(o_buf, i_amt);
            }
        }

        return amt_read;
    }
};

/**
 * @brief Convenience function for constructing a stream_cat<N>.
 */
template<typename... Args>
inline stream_cat<sizeof...(Args)> cat_streams(Args&&... args)
{
    return stream_cat<sizeof...(Args)>({ args... });
}

}

#endif
