/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/runtime/sbe_msg_passing.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef SBE_MSG_PASSING_H
#define SBE_MSG_PASSING_H

#include <stdint.h>
#include <map>
#include <errl/errlmanager.H>
#include <targeting/common/target.H>

//Determine the Data Offset of an SBE Message
#define SBE_MSG_DATA_OFFSET \
static_cast<uint32_t>((reinterpret_cast<uint64_t>(\
 (((const SBE_MSG::sbeMessage_t*)(0))->data)) - \
reinterpret_cast<uint64_t>( \
&(((const SBE_MSG::sbeMessage_t*)(0))->cmdHdr))))

namespace SBE_MSG
{
    // SBE Communication Buffer for Pass-through commands
    /**
     * @brief SBE Communication package size in number of pages
     */
    const uint8_t SBE_COMM_PKG_SIZE = 2;

    /**
     * @brief SBE Communication buffer size
     */
    const uint32_t SBE_COMM_BUFFER_SIZE = SBE_COMM_PKG_SIZE * PAGESIZE;

    /**
     * @brief SBE Message size / Pass-through Command size
     */
    const uint32_t SBE_MSG_SIZE = SBE_COMM_BUFFER_SIZE;


    // SBE Header Version enums for SBE Header version field
    enum sbeHdrVersion
    {
        SBEHDRVER_FIRST             = 0x00010000, // First SBE Header version
        // NOTE: Update SBEHDRVER_LATEST with each new version
        SBEHDRVER_LATEST            = SBEHDRVER_FIRST
    };

    #define ENUM_SBEHDRVER_CHECK(version) (((version) >= SBEHDRVER_FIRST) \
                                        && ((version) <= SBEHDRVER_LATEST))


    // Command Header Version enums for Command Header version field
    enum cmdHdrVersion
    {
        CMDHDRVER_FIRST             = 0x00010000, // First Command Hdr version
        // NOTE: Update CMDHDRVER_LATEST with each new version
        CMDHDRVER_LATEST            = CMDHDRVER_FIRST
    };

    #define ENUM_CMDHDRVER_CHECK(version) (((version) >= CMDHDRVER_FIRST) \
                                        && ((version) <= CMDHDRVER_LATEST))


    // Pass-Through Command enums for Command Header command field
    enum passThruCmds
    {
        // Command Class 0xE0 - HTMGT Messages
        PASSTHRU_HTMGT_GENERIC      = 0x00E00001, // HTMGT Generic Message
        PASSTHRU_HTMGT_GET_PSTATE   = 0x00E00002, // HTMGT Get PState Table
        // Command Class 0xE1 - HBRT Messages
        PASSTHRU_HBRT_GET_PSTATE    = 0x00E10001, // HBRT Get PState Table
        PASSTHRU_HBRT_OVERRIDE_ATTR = 0x00E10002, // HBRT Apply Override
                                                  // attributes
        PASSTHRU_HBRT_OVERRIDE_VPD  = 0x00E10003, // HBRT Apply VPD Override
    };


    // SBE Header at start of SBE Message
    typedef struct sbeHeader
    {
        uint32_t version;        // SBE header version
        uint32_t msgSize;        // Message size (Pass-through cmd or rsp)
                                 // Size includes SBE and Command Headers
        uint32_t seqId;          // Sequence ID
    } PACKED sbeHeader_t;

    // Command Header following SBE Header in SBE Message
    typedef struct cmdHeader
    {
        uint32_t version;        // Command header version
        uint32_t status;         // Status of processing (rsp only)
        uint32_t dataOffset;     // Data offset (cmd or rsp)
                                 // Offset is from beginning of Command Header
        uint32_t dataSize;       // Data size (cmd or rsp)
                                 // Size does NOT include ANY Header fields
        uint32_t command;        // Pass-through command
    } PACKED cmdHeader_t;

    // Max Pass-through command/response data size
    const uint32_t SBE_MSG_MAX_DATA =
        SBE_MSG_SIZE - sizeof(sbeHeader_t) - sizeof(cmdHeader_t);

    // SBE Message (Pass-through command or response)
    typedef struct sbeMessage
    {
        sbeHeader_t sbeHdr;              // SBE header
        cmdHeader_t cmdHdr;              // Command header
        uint8_t data[SBE_MSG_MAX_DATA];  // Pass-through command/response data
    } sbeMessage_t;


    /**
     * @brief Function to process pass-through command from SBE message
     *
     * @param[in]  i_procTgt      HB processor target
     * @param[in]  i_reqDataSize  Pass-through command request data size
     * @param[in]  i_reqData      Pass-through command request data
     * @param[out] o_rspStatus    Pass-through command response status
     * @param[out] o_rspDataSize  Pass-through command response data size
     * @param[out] o_rspData      Pass-through command response data
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    typedef errlHndl_t (*processCmdFunction_t)(TARGETING::TargetHandle_t,
                                            uint32_t,
                                            uint8_t*,
                                            uint32_t*,
                                            uint32_t*,
                                            uint8_t*);

    // Process Command Map of pass-through command to function used to process
    typedef std::map<uint32_t, processCmdFunction_t> ProcessCmdMap_t;

    /**
     * @brief Set process pass-through command function in Process Command Map
     *
     * @param[in]  i_command      Process pass-through command
     * @param[in]  i_function     Function to process pass-through command
     *
     * @return int    Return code.
     */
    int setProcessCmdFunction(enum passThruCmds    i_command,
                              processCmdFunction_t i_function);

    /**
     * @brief Erase process pass-through command function in Process Command Map
     *
     * @param[in]  i_command      Process pass-through command
     *
     * @return int    Return code.
     */
    int eraseProcessCmdFunction(enum passThruCmds i_command);

    //------------------------------------------------------------------------
    // Constants for setting/clearing status in SBE message update register
    //------------------------------------------------------------------------
    enum sbe_msg_processing_state_t
    {
        SBE_MSG_NONE          = 0,
        SBE_MSG_IN_PROGRESS   = 1 << 0,
        SBE_MSG_COMPLETE      = 1 << 1
    };

    /**
     *  @brief SBE message update bit(s) in CFAM register
     *
     *  @details This is a call that will update bit(s) in Mailbox
     *           Scratch register 4.
     *
     *  @param[in]  i_proc        HB processor target
     *  @param[in]  i_state       New state of the SBE message
     *
     *  @returns  errlHndl_t  NULL on success
     */
    errlHndl_t process_sbe_msg_update_cfam(TARGETING::TargetHandle_t i_proc,
                                           sbe_msg_processing_state_t i_state);

    enum dataSectionAndMethodFlag : uint8_t {
        MVPD_KEYWORD_RECORD            = 0x00,
        MVPD_OFFSET_NUM_BYTES          = 0x01,

        SPD_KEYWORD_RECORD             = 0x02,
        SPD_OFFSET_NUM_BYTES           = 0x03,

        WOF_OFFSET_NUM_BYTES           = 0x04,

        DATA_SECTION_MASK              = 0x0F,
        READ_CMD_MASK                  = 0xF0,
        INVALID_DATA_SECTION_OR_METHOD = 0xFF,
    };

    // header at the start of i_reqData from a processCmdFunction_t for sbeApplyVpdOverrides
    // dataSectionAndMethod - a dataSectionAndMethodFlag enum
    // ecmdTargetString     - 32 character ecmd ascii string of the target to
    //                        write (ie "ddimm:n0:p3"). NULL terminated, left justified
    // keyword              - 8 byte string literal keyword name, NULL terminated, left justified
    // record               - 8 byte string literal record name, NULL terminated, left justified
    //
    // offset               - offset into the given logical section to start writting (ie 0 is
    //                        the start of MVPD/SPD/WOF section)
    // write_len            - number of bytes to write, starting at offset, into the data section
    typedef struct vpdCmdHeader {

        dataSectionAndMethodFlag dataSectionAndMethod;
        char ecmdTargetString[32];

        union {
            struct // record/keyword
            {
                uint64_t keyword;
                uint64_t record;
            } PACKED;
            struct // offset/write_len
            {
                uint64_t offset;
                uint64_t write_len;
            } PACKED;
        };

    } PACKED vpdCmdHeader_t;


    typedef struct vpdOverwriteCmd {
        vpdCmdHeader * header;
        size_t dataSizeBytes; // size in bytes that 'data' points to
        uint8_t * data;       // binary data to write to a VPD record

        /**
         * @brief vpdOverwriteCmd constructor
         *
         * @param[in] i_reqData     - pointer to a vpdCmdHeader_t + data blob
         * @param[in] i_reqDataSize - size of i_reqData in byte
         *
         * @return int    Return code
         */
        vpdOverwriteCmd (uint8_t * i_reqData, uint32_t i_reqDataSize)
        {
            header = reinterpret_cast<vpdCmdHeader *>(i_reqData);
            data = (i_reqData + sizeof(vpdCmdHeader));
            dataSizeBytes = i_reqDataSize - sizeof(vpdCmdHeader);
        }

    } PACKED vpdOverwriteCmd_t;



} // namespace SBE_MSG


#endif
