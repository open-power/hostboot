/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/bpm_update.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef BPM_UPDATE_H
#define BPM_UPDATE_H

/* @file bpm_update.H
 *
 *
 */

#include <vector>
#include <errl/errlentry.H>
#include <targeting/common/util.H>

namespace NVDIMM
{
namespace BPM
{

// All of the various commands used for the BPM update
// BSL: Bootstrap Loader commands
// BPM: Backup Power Module
enum COMMAND : uint8_t
{
    BCL_ENTER_BSL_MODE        = 0x01,
    BCL_IS_BSL_MODE           = 0x02,
    BCL_WRITE_REG             = 0x03,
    BCL_START_UPDATE          = 0x04,
    BCL_END_UPDATE            = 0x05,
    BCL_IS_UPDATE_IN_PROGRESS = 0x06,
    BSL_RX_DATA_BLOCK         = 0x10,
    BSL_RX_PASSWORD           = 0x11,
    BSL_ERASE_SEGMENT         = 0x12,
    BSL_TOGGLE_INFO           = 0x13,
    BSL_ERASE_BLOCK           = 0x14,
    BSL_MASS_ERASE            = 0x15,
    BSL_CRC_CHECK             = 0x16,
    BSL_LOAD_PC               = 0x17,
    BSL_TX_DATA_BLOCK         = 0x18,
    BSL_TX_BSL_VERSION        = 0x19,
    BSL_TX_BUFFER_SIZE        = 0x1A,
    BSL_RX_DATA_BLOCK_FAST    = 0x1B,
    BSL_RESET_DEVICE          = 0x1C,
    BSL_VERIFY_BLOCK          = 0x1D,
    BPM_PASSTHROUGH           = 0xFE,
    BPM_LOCAL                 = 0xFF,
};

// The operator types for the BPM_CMD_STATUS register
enum COMMAND_STATUS_REGISTER_OP_TYPES : uint8_t
{
    NOP        = 0x00,
    READ       = 0x01,
    WRITE      = 0x02,
    NO_TRASFER = 0x03,
};

// Used to overlay onto the LID image
struct firmware_image_block
{
    // The block size is the sizeof(iv_addressOffset) plus sizeof(iv_data).
    uint8_t iv_blockSize;

    // The address offset where the first byte in iv_data came from in the
    // firmware image.
    uint16_t iv_addressOffset;

    // A variable sized array of firmware data. The size of which is always
    // iv_blockSize - sizeof(iv_addressOffset) and the max this can be is
    // MAX_PAYLOAD_SIZE.
    char iv_data[0];

} PACKED;

typedef firmware_image_block firmware_image_block_t;


/*    Max payload size is 26 bytes
 *    4 bytes: header
 *        1 byte: sync byte
 *        1 byte: command
 *        1 byte: header size + data size
 *        1 byte: header size + data size
 *    2 bytes: address
 *    2 bytes: extra
 *    16 bytes: data
 *    2 bytes: CRC
 */
extern const size_t MAX_PAYLOAD_SIZE;

// Max number of bytes data section of payload can be.
extern const size_t MAX_PAYLOAD_DATA_SIZE;

// Number of bytes for header, address, extra, and CRC
extern const size_t MAX_PAYLOAD_OTHER_DATA_SIZE;

// Number of bytes for the header.
extern const uint8_t PAYLOAD_HEADER_SIZE;

// The sync byte that must always be at the front of a BPM payload. This is used
// calculate the CRC of the payload and then removed because the nvdimm
// automatically sends the sync byte ahead of the payload.
extern const uint8_t SYNC_BYTE;

typedef std::vector<uint8_t> payload_t;


/**
 *  @brief BPM_CMD_STATUS register bits
 */
struct command_status_register_bits
{
    uint8_t Abort_Request       : 1; // Bit 7
    uint8_t Abort_Acknowledge   : 1; // Bit 6
    uint8_t Reserved1           : 1; // Bit 5
    uint8_t Reserved2           : 1; // Bit 4
    uint8_t Error_Flag          : 1; // Bit 3
    uint8_t Bsp_Cmd_In_Progress : 1; // Bit 2
    uint8_t Operator_Type       : 2; // Bit 1-0
} PACKED;

/**
 *  @brief Union simplifying manipulation of REG_CMD_STATUS value
 */
union command_status_register_union
{
    uint8_t value;
    command_status_register_bits bits;

    /**
     *  @brief Constructor
     */
    command_status_register_union()
    : value(0)
    {}

} PACKED;

typedef command_status_register_union command_status_register_t;

class BpmFirmwareLidImage
{
public:

    /**
    * @brief Constructor that sets access to LID information
    *
    * @param[in] i_lidImageAddr  virtual address where LID was loaded
    * @param[in] i_size          size of the loaded LID
    */
    BpmFirmwareLidImage(void * const i_lidImageAddr, size_t i_size);

    /**
    * @brief Returns the version of the firmware binary as a uint16_t
    *
    * @return uint16_t   version of the firmware image as MMmm.
    *                    MM = major version, mm = minor.
    */
    uint16_t getVersion() const;

    /**
    * @brief Returns the number of blocks in the LID image.
    *
    */
    uint16_t getNumberOfBlocks() const;

    /**
     * @brief Returns a pointer to the first block in LID image.
     */
    void const * getFirstBlock() const;

    /* Layout of the BPM Firmware image
    *  Byte 1:     Major version number (MM)
    *  Byte 2:     Minor version number (mm)
    *  Byte 3-4:   N number of blocks in the file (NN NN)
    *  Byte 5-EOF: Blocks of the form:
    *            BLOCK_SIZE      Byte 1: X number of bytes in block excluding
    *                                    this byte. (XX)
    *            ADDRESS_OFFSET  Byte 2-3: Original address offset of the
    *                                      first data byte. (AD DR)
    *            DATA_BYTES      Byte 4-X: Firmware data bytes (DD)
    *
    *  Example file:
    *     01 03 00 01 06 80 00 6a 14 31 80
    *     MM mm NN NN XX AD DR DD DD DD DD
    */
    typedef struct firmware_image_header
    {
        uint8_t iv_versionMajor;
        uint8_t iv_versionMinor;
        uint16_t iv_numberOfBlocks;
    } firmware_image_header_t;

private:

    // Pointer to the LID image allocated outside of the class
    void * const iv_lidImage;

    // The size of the LID image.
    size_t iv_lidImageSize;
};

class Bpm
{
public:


    explicit Bpm(const TARGETING::TargetHandle_t i_nvdimm);

    // Force User to supply a nvdimm target.
    Bpm() = delete;

    /**
     * @brief Runs the BPM firmware update using the given image.
     *
     * @param[in] i_image The BPM firmware image.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t runUpdate(BpmFirmwareLidImage i_image);

private:

    // The nvdimm whose battery firmware will be updated.
    const TARGETING::TargetHandle_t iv_nvdimm;

    // The Bootstrap Loader version of the BPM
    uint8_t iv_bslVersion;

    /**
     * @brief Gets the BSL version from the BPM and sets the iv_bslVersion
     *        member. Only needs to be called once.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t readBslVersion();

    /**
     * @brief Gets the Firmware version from the BPM
     *
     * @param[out]  o_fwVersion     The firmware version currently on the BPM.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t getFwVersion(uint16_t & o_fwVersion) const;

    /**
     * @brief This function issues a command to the BPM using a payload as the
     *        means of sending the command.
     *
     * @param[in]   i_command   The BSP command to send to the BPM.
     * @param[in]   i_payload   The payload to write to the
     *                          BPM_REG_PAYLOAD_START register.
     * @param[in]   i_opType    The operation type of the command. Must be one
     *                          of the COMMAND_STATUS_REGISTER_OP_TYPES
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t issueCommand(uint8_t i_command,
                            payload_t i_payload,
                            uint8_t i_opType);

    /**
     * @brief This function issues a BCL command to the BPM by setting up a
     *        payload containing only that command and then calling the
     *        issueCommand function that accepts a payload as an argument.
     *
     *        NOTE: Since the BCL command is not a BSL command, it doesn't need
     *        to be formatted as a BSL payload but it still must be written to
     *        the BPM_REG_PAYLOAD_START register.
     *
     * @param[in]   i_bspCommand   The BSP command to send to the BPM.
     * @param[in]   i_command      The BCL command to be written to the
     *                             BPM_REG_PAYLOAD_START register. Must be one
     *                             of the BCL_ commands.
     * @param[in]   i_opType       The operation type of the BSP command. Must
     *                             be a COMMAND_STATUS_REGISTER_OP_TYPES
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t issueCommand(uint8_t i_bspCommand,
                            uint8_t i_command,
                            uint8_t i_opType);

    /**
     * @brief This function checks if the BPM has entered update mode
     *
     * @return  errlHndl_t  nullptr on success.
     *                      Otherwise, pointer to an errlEntry.
     */
    errlHndl_t inUpdateMode();

    /**
     * @brief Send the command to the BPM to enter update mode
     *
     * @return  errlHndl_t  nullptr if no errors occurred during command
     *                      execution. Otherwise, pointer to an errlEntry.
     */
    errlHndl_t enterUpdateMode();

    /**
     * @brief Send the command to the BPM to exit update mode
     *
     * @return  errlHndl_t  nullptr if no errors occurred during command
     *                      execution. Otherwise, pointer to an errlEntry.
     */
    errlHndl_t exitUpdateMode();

    /**
     * @brief Executes the firmware portion of the BPM update.
     *
     * @param[in]   i_image     The BPM firmware LID image to apply to the BPM.
     *
     * @return  errlHndl_t  nullptr if no errors occurred.
     *                      Otherwise, pointer to an errlEntry.
     */
    errlHndl_t updateFirmware(BpmFirmwareLidImage i_image);

    /**
     * @brief Commands the BPM to enter BSL mode to allow for BSL commands to be
     *        executed.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t enterBootstrapLoaderMode();

    /**
     * @brief Creates a valid BSL payload given a firmware_image_block_t.
     *
     * @param[out]  o_payload   The BSL payload
     * @param[in]   i_block     A pointer to a firmware image block.
     * @param[in]   i_command   The BSL command to be included with the payload
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t setupPayload(payload_t                    & o_payload,
                            const firmware_image_block_t * i_block,
                            uint8_t                        i_command);

    /**
     * @brief Creates a valid BSL payload given a BSL command, address, and
     *        optionally data to include with the command. This function is used
     *        to create firmware_image_block_t objects which are then passed
     *        onto the version of setupPayload that turns them into payloads.
     *
     * @param[out]  o_payload   The BSL payload
     * @param[in]   i_command   The BSL command to be included with the payload
     * @param[in]   i_address   The address to execute the command from. This
     *                          will be zero or the address to execute the
     *                          command from.
     * @param[in]   i_data      The array of data to be included with the BSL
     *                          command. Default nullptr.
     * @param[in]   i_length    Length of the i_data array parameter. Default 0.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t setupPayload(payload_t & o_payload,
                            uint8_t     i_command,
                            uint16_t    i_address,
                      const uint8_t     i_data[] = nullptr,
                            size_t      i_length = 0);

    /**
     * @brief This function unlocks the BPM.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t unlockDevice();

    /**
     * @brief This function will send the command to reset the BPM. This will
     *        exit BSL mode if the BPM was in that mode.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t resetDevice();

    /**
     * @brief A helper function used to wait for the command status bit to reset
     *        after a command is executed.
     *
     * @param[in]   i_commandStatus     The command status register union made
     *                                  by the caller to identify the type of
     *                                  command that was sent.
     *
     * @return      errlHndl_t          nullptr on success. Otherwise, an error.
     */
    errlHndl_t waitForCommandStatusBitReset(
            command_status_register_t i_commandStatus);

    /**
     * @brief Calculates the CRC16 bytes for the BSL payload. This CRC differs
     *        from the NVDIMM CRC calculation in that the initial value is
     *        0xFFFF instead of 0x0000.
     *
     *        NOTE: To calculate a correct CRC for the BSL payload the SYNC_BYTE
     *              must be included in the payload despite the fact that it
     *              should be removed from the payload before sending to the BPM
     *              because the NVDIMM sends the SYNC_BYTE automatically.
     *
     * @param[in]   i_ptr    A pointer to the start of the data to calculate the
     *                       CRC for.
     * @param[in]   i_size   This size of the data pointed at by i_ptr.
     *
     * @return      uint16_t The CRC bytes.
     */
    uint16_t crc16_calc(const void* const i_ptr, int i_size);


};


}; // end of BPM namespace
}; // end of NVDIMM namespace

#endif

