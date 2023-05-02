/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/bpm_update.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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

/*
 * All of the various commands used for the BPM update. All commands can only be
 * sent after write protection on the BPM has been disabled and the update magic
 * values have been written to the BPM's magic registers.
 *
 * BSL: Bootstrap Loader commands
 * BPM: Backup Power Module
*/
enum COMMAND : uint8_t
{
    // A payload sent with this command will be interpreted and processed by the
    // NVDIMM module.
    BPM_LOCAL                 = 0xFF,

    /*
     * These are LOCAL commands. These commands MUST be sent only outside of BSL
     * mode and must be paired with the BSP command BPM_LOCAL. Otherwise,
     * unpredicatable errors will occur.
     *
     * When using issueCommand() for these commands they should always be sent
     * with a 0 ms delay. This will ensure that the response packet is not
     * checked from the BPM. Since these are processed by the NVDIMM it makes
     * no sense to get a response from the BPM and attempting to do so will
     * cause errors.
     */
    BCL_ENTER_BSL_MODE        = 0x01,
    BCL_IS_BSL_MODE           = 0x02,
    BCL_WRITE_REG             = 0x03,
    BCL_START_UPDATE          = 0x04,
    BCL_END_UPDATE            = 0x05,
    BCL_IS_UPDATE_IN_PROGRESS = 0x06,

    // A payload sent with this command will be sent transparently to the BPM.
    // This command must only be used while the BPM is in BSL mode.
    BPM_PASSTHROUGH           = 0xFE,

    /*
     * These are PASSTHROUGH commands. These commands MUST be sent only while in
     * BSL mode and must be paired with BSP command BPM_PASSTHROUGH. Otherwise,
     * unpredicatable errors will occur.
     */
    // Writes a block of data to the BPM.
    // Delay 1ms (default)
    BSL_RX_DATA_BLOCK         = 0x10,
    // Unlocks the BPM that is in BSL mode so that updates can occur.
    // Delay 1ms (default)
    BSL_RX_PASSWORD           = 0x11,
    // Erases 128 bytes at the given address offset.
    // WARNING: Due to BSL memory limitations, BSL cannot verify the address
    //          is a valid config segment address offset and will blindly
    //          erase 128 bytes of data starting at that offset. If an invalid
    //          address is sent then the BPM will be bricked in a very
    //          unpredicatable/unrecoverable way.
    // Delay 250ms
    BSL_ERASE_SEGMENT         = 0x12,
    // Unknown, unused.
    // Delay 0ms
    BSL_TOGGLE_INFO           = 0x13,
    // Unknown, unused.
    // Delay 1ms (default)
    BSL_ERASE_BLOCK           = 0x14,
    // Erases the full firmware section on the BPM. The start of the firmware
    // address must be supplied with this command.
    // WARNING: Due to BSL memory limitations, BSL cannot verify the address
    //          is a valid firmware address offset and will blindly erase 128
    //          data starting at that offset. If an invalid address is sent
    //          then the BPM will be bricked in a very
    //          unpredicatable/unrecoverable way.
    // Delay 250ms
    BSL_MASS_ERASE            = 0x15,
    // Sends the command to the BPM to perform the final CRC check on the
    // firmware written to the BPM. If the CRC check doesn't match the expected
    // CRC in the flash image then the firmware will not load on the BPM and it
    // will remain in BSL mode until new firmware is loaded onto it.
    //
    // Delay 0
    // The response packet must be checked externally from the issueCommand()
    // function because the response packet returned from this command is unique
    // to this command and will return the results of this command. For more
    // info see the checkFirmwareCrc() function description, implementation, and
    // the COMMAND_BSL_CRC_CHECK_RESPONSE_CODES enum.
    BSL_CRC_CHECK             = 0x16,
    // Unknown, unused.
    // Delay 1ms (default)
    BSL_LOAD_PC               = 0x17,
    // Unknown, unused.
    // Delay 1ms (default)
    BSL_TX_DATA_BLOCK         = 0x18,
    // Checks the Bootstrap Loader mode version on the BPM. Depending on this
    // version, some parts of the update procedure may have changed.
    //
    // Delay 0ms
    // The response packet must be checked externally from the issueCommand()
    // function because the response packet returned from this command is unique
    // to this command and will return the results of this command. For more
    // info see the readBslVersion() function description and implementation.
    BSL_TX_BSL_VERSION        = 0x19,
    // Unknown, unused.
    // Delay 1ms (default)
    BSL_TX_BUFFER_SIZE        = 0x1A,
    // Unknown, unused.
    // Delay 1ms (default)
    BSL_RX_DATA_BLOCK_FAST    = 0x1B,
    // Resets the BPM and exits BSL mode.
    // Delay 0ms
    // Never check for a response packet from the BPM after sending the reset
    // command because the BPM may not be back up and if it is it will not be
    // in BSL mode anymore. If the response packet is checked then errors will
    // occur.
    BSL_RESET_DEVICE          = 0x1C,
    // Verifies the block of data written to the BPM flash is identical to what
    // was sent to it in a prior write. For more information see the
    // verifyBlockWrite() description and implementation.
    //
    // Delay 0ms
    // The response packet must be checked externally from the issueCommand()
    // function because the response packet returned from this command is unique
    // to this command and will return the results of this command.
    BSL_VERIFY_BLOCK          = 0x1D,
};

// These consts serve as reminders in the code for what was explained in the
// COMMAND enum.
const int NO_DELAY_NO_RESPONSE       = 0;
const int NO_DELAY_EXTERNAL_RESPONSE = 0;
const int ERASE_SEGMENT_DELAY        = 250;
const int ERASE_FIRMWARE_DELAY       = 250;

// These are the various response codes returned by the BPM after the
// BSL_CRC_CHECK command is sent at the end of the update procedure.
enum COMMAND_BSL_CRC_CHECK_RESPONSE_CODES : uint16_t
{
    // The updated firmware is set up with all necessary loading parameters to
    // load and execute upon reset.
    SUCCESSFUL_OPERATION          = 0x00,

    // Error setting up the necessary loading parameters for the updated
    // firmware image.
    MEMORY_WRITE_CHECK_FAILED     = 0x01,

    // The command was attempted without unlocking the BSL with the password.
    BSL_LOCKED                    = 0x04,

    // Error setting up the necessary loading parameters for the updated
    // firmware image.
    WRITE_FORBIDDEN               = 0x06,

    // The checksum validation of the updated firmware image failed. The
    // calculated checksum doesn't match the checksum data provided @FF7A in the
    // firmware image file.
    VERIFY_MISMATCH               = 0x09,

    // The firmware image start address given for the command is wrong.
    PARAMETER_ERROR               = 0x0A,

    // Firmware image file used for the update doesn't hae the checksum data
    // defined @FF7A
    MAIN_FW_NOT_SUPPORT_CRC_CHECK = 0x0B,
};

//  BSL versions that this code supports.
const uint8_t BSL_VERSION_1_4 = 0x14;

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


// Used to overlay onto the LID image
struct config_image_fragment
{
    // The fragment size is the size of iv_data.
    uint8_t iv_fragmentSize;

    // The offset where the first byte in iv_data should begin overwritting the
    // BPM config data in the BPM configuration segment dump buffer.
    uint16_t iv_offset;

    // A variable sized array of config segment data.
    char iv_data[0];

} PACKED;

typedef config_image_fragment config_image_fragment_t;


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
constexpr size_t MAX_PAYLOAD_SIZE = 26;

// Max number of bytes data section of payload can be.
constexpr size_t MAX_PAYLOAD_DATA_SIZE = 16;

// Number of bytes for header, address, extra, and CRC
constexpr size_t MAX_PAYLOAD_OTHER_DATA_SIZE = 10;

// Number of bytes for the header.
constexpr uint8_t PAYLOAD_HEADER_SIZE = 4;

// Indices of where to find certain data within a constructed payload.
// These indices have been subtracted by 1 from the given payload format because
// after a payload is constructed the sync byte is removed from the front.
constexpr uint8_t PAYLOAD_COMMAND_INDEX = 0;
constexpr uint8_t PAYLOAD_ADDRESS_START_INDEX = 3;
constexpr uint8_t PAYLOAD_DATA_START_INDEX = 7;
constexpr uint8_t PAYLOAD_HEADER_DATA_LENGTH_INDEX = 1;

// The sync byte that must always be at the front of a BPM payload. This is used
// calculate the CRC of the payload and then removed because the nvdimm
// automatically sends the sync byte ahead of the payload.
constexpr uint8_t SYNC_BYTE = 0x80;
constexpr uint8_t SYNC_BYTE_SIZE = sizeof(uint8_t);

// Maximum size of any segment in the config data section
constexpr size_t SEGMENT_SIZE = 128;

// Maximum size of the config data section.
constexpr size_t ALL_SEGMENTS_SIZE = 512;

// Number of magic registers for the BPM
constexpr size_t NUM_MAGIC_REGISTERS = 2;

// These are the production magic values for the BPM that should be written in
// BPM_MAGIC_REG1 and BPM_MAGIC_REG2 respectively.
const uint8_t PRODUCTION_MAGIC_VALUES[NUM_MAGIC_REGISTERS] = {0x55, 0xAA};
// These magic values to enable nvdimm-bpm interface. They must be written to
// the magic registers BEFORE writing flash updates to the BPM in BSL mode.
const uint8_t UPDATE_MODE_MAGIC_VALUES[NUM_MAGIC_REGISTERS] = {0xB0, 0xDA};
// These are the segment read magic values that allow dumping of the segment
// data from the BPM.
const uint8_t SEGMENT_READ_MAGIC_VALUES[NUM_MAGIC_REGISTERS] = {0xBA, 0xAB};

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


class BpmConfigLidImage
{
public:

    /**
    * @brief Constructor that sets access to LID information
    *
    * @param[in] i_lidImageAddr  virtual address where LID was loaded
    * @param[in] i_size          size of the loaded LID
    */
    BpmConfigLidImage(void * const i_lidImageAddr, size_t i_size);

    /**
    * @brief Returns the version of the config binary as a uint16_t. There isn't
    *        a way to check the version of the config data on the BPM but the
    *        config binary still has the version of the flash image it
    *        originally came from.
    *
    * @return uint16_t   version of the firmware image as MMmm.
    *                    MM = major version, mm = minor.
    */
    uint16_t getVersion() const;

    /**
    * @brief Returns the number of fragments in the LID image.
    *
    */
    uint16_t getNumberOfFragments() const;

    /**
     * @brief Returns a pointer to the first fragment in LID image.
     */
    void const * getFirstFragment() const;

    /*   The binary will be organized in the following way:
     *   Byte 1:     Major version number (MM)
     *   Byte 2:     Minor version number (mm)
     *   Byte 3:     N number of fragments in the file (NN)
     *   Byte 4-EOF: Fragments of the form:
     *             FRAGMENT_SIZE   Byte 1:   X number of bytes in fragment data
     *                                       section. (XX)
     *             INDEX_OFFSET    Byte 2-3: Each BPM's config section is unique
     *                                       to itself. So, during the update
     *                                       the contents of a BPM's config data
     *                                       will be dumped into a buffer.
     *                                       These two bytes will be used as an
     *                                       offset into that buffer from which
     *                                       overwritting will take place.
     *                                       (IN DX)
     *             DATA_BYTES      Byte 4-X: Fragment data bytes to be written
     *                                       at the INDEX_OFFSET in the dumped
     *                                       config data buffer. (DD)
     *
     *   Example file output:
     *      01 05 01 04 01 28 6a 14 31 80
     *      MM mm NN XX IN DX DD DD DD DD
     */
    typedef struct config_image_header
    {
        uint8_t iv_versionMajor;
        uint8_t iv_versionMinor;
        uint16_t iv_numberOfFragments;
    } config_image_header_t;

private:

    // Pointer to the LID image allocated outside of the class
    void * const iv_lidImage;

    // The size of the LID image.
    size_t iv_lidImageSize;
};

class Bpm
{
    /*
     * The Bpm can either be in Bootstrap Loader (BSL) mode or not. Many of
     * member functions utilize BSL mode for the update procedure and must
     * therefore be in BSL mode to succeed. Other functions perform operations
     * that will not work in BSL mode since that mode is strictly for updating
     * the device and turns of some functionality while in that mode. The "mode"
     * the BPM must be in is given in the function brief description.
     */
public:


    explicit Bpm(const TARGETING::TargetHandle_t i_nvdimm);

    // Force User to supply a nvdimm target.
    Bpm() = delete;


#ifndef __HOSTBOOT_RUNTIME

    /**
     * @brief Runs the BPM firmware update using the given image.
     *
     * @param[in] i_image The BPM firmware image.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t runUpdate(BpmFirmwareLidImage i_fwImage,
                         BpmConfigLidImage   i_configImage);

    /**
     *  @brief At most, one full update retry should occur in some
     *         circumstances. If one of those occurances happens then the
     *         member iv_attemptAnotherUpdate will be set to true. Otherwise, it
     *         will remain false.
     *
     *  @return     bool        true if another update should be attempted.
     *                          Otherwise, false.
     */
    bool attemptAnotherUpdate();

    /**
     *  @brief Returns if an update has been attempted on this BPM.
     *
     *  @return     bool        true if an update has been attempted before.
     *                          Otherwise, false.
     */
    bool hasAttemptedUpdate();

#endif //#ifndef __HOSTBOOT_RUNTIME

    /**
     *  @brief returns the nvdimm that is associated with this BPM.
     */
    const TARGETING::TargetHandle_t getNvdimm();

    /**
     * @brief returns the BPM serial number
     *
     * @param[in] o_serial The BPM serial number.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t readSerialNumber( uint8_t o_serial[7] );

private:

    // The nvdimm whose battery firmware will be updated.
    const TARGETING::TargetHandle_t iv_nvdimm;

#ifndef __HOSTBOOT_RUNTIME
    // The Bootstrap Loader version of the BPM
    uint8_t iv_bslVersion;

    // The firmware address for the BPM image can be either 0x8000 or 0xA000.
    // This member will keep track of which one it is.
    uint16_t iv_firmwareStartAddress;

    // Keeps track of if the update should be attempted again.
    bool iv_attemptAnotherUpdate;

    // Buffers for the segment data in case another update attempt is needed.
    // If the first update fails there won't be any running firmware on the
    // device which is required to dump the segment data.
    uint8_t iv_segmentD[SEGMENT_SIZE];
    uint8_t iv_segmentB[SEGMENT_SIZE];

    // Keeps track if the segments have been merged with the flash image data
    // yet.
    bool iv_segmentDMerged;
    bool iv_segmentBMerged;

    // Keeps track of if an update has been attempted at least once.
    bool iv_updateAttempted;

     /**
      * @brief Determines if another update attempt should occur for this BPM.
      */
    void setAttemptAnotherUpdate();

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
     * @param[in]   i_msDelay   How long to wait before the response from the
     *                          BPM should be checked. Default 1 ms. If a delay
     *                          of 0 ms is given then the response will not be
     *                          read and it is the caller's responsibilty to
     *                          check the response status. See COMMAND enum for
     *                          required delays.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t issueCommand(uint8_t i_command,
                            payload_t i_payload,
                            uint8_t i_opType,
                            int     i_msDelay = 1);

    /**
     * @brief This function issues a BSP command to the BPM by setting up a
     *        payload containing only that command and then calling the
     *        issueCommand function that accepts a payload as an argument.
     *
     *        NOTE: Since the BSP command is not a BSL command, it doesn't need
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
     * @param[in]   i_msDelay   How long to wait before the response from the
     *                          BPM should be checked. Default 1 ms. If a delay
     *                          of 0 ms is given then the response will not be
     *                          read and it is the caller's responsibilty to
     *                          check the response status. See COMMAND enum for
     *                          required delays.
     *
     * @return  errlHndl_t  nullptr on success. Otherwise, pointer to an
     *                      errlEntry.
     */
    errlHndl_t issueCommand(uint8_t i_bspCommand,
                            uint8_t i_command,
                            uint8_t i_opType,
                            int     i_msDelay = 1);

    /**
     * @brief This function checks if the BPM has entered update mode
     *
     * @return  errlHndl_t  nullptr on success.
     *                      Otherwise, pointer to an errlEntry.
     */
    errlHndl_t inUpdateMode();

    /**
     * @brief Transitions the BPM from normal mode to update mode to allow
     *        updates to the device firmware and segment data. Since the
     *        ordering of the "Enter Update Mode" command and BSL mode entry
     *        commands must be executed in the correct sequence this function
     *        ensures that all the various enter and exit update modes are
     *        all executing in the same order.
     *
     *  @return     errlHndl_t   nullptr if no errors. Otherwise, pointer to
     *                           error.
     */
    errlHndl_t transitionToUpdateMode();

    /**
     * @brief Transitions the BPM from update mode to normal mode to return
     *        BPM to normal operational state. Since the ordering of the device
     *        reset and exit update command must be executed in the correct
     *        sequence this function ensures that all the various enter and exit
     *        update modes are all executing in the same order.
     *
     *  @return     errlHndl_t   nullptr if no errors. Otherwise, pointer to
     *                           error.
     */
    errlHndl_t transitionToNormalMode();

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
     * @brief Helper function that executes the firmware portion of the BPM
     *        update by calling all necessary functions in order.
     *
     * @param[in]   i_image     The BPM firmware LID image to apply to the BPM.
     *
     * @return  errlHndl_t  nullptr if no errors occurred.
     *                      Otherwise, pointer to an errlEntry.
     */
    errlHndl_t runFirmwareUpdates(BpmFirmwareLidImage i_image);

    /**
     *  @brief Executes the config portion of the BPM update.
     *
     *  @return errlHndl_t  nullptr on success. Otherwise, an Error.
     */
    errlHndl_t updateConfig();

    /**
     *  @brief Helper function that executes the config portion of the BPM
     *         update by calling all necessary functions in order.
     *
     * @param[in]   i_image     The BPM config LID image to apply to the BPM.
     *
     *  @return errlHndl_t  nullptr on success. Otherwise, an Error.
     */
    errlHndl_t runConfigUpdates(BpmConfigLidImage i_image);

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
     *  @brief Many operations performed on the BPM require the magic registers
     *         to have specific values written in them. This function acts as a
     *         helper to facilitate that process.
     *
     *         NOTE: Write protection on the BPM must be disabled, otherwise
     *               this function will fail.
     *
     *  @param[in]  i_magicValues   The pair of magic values to be written to
     *                              BPM_MAGIC_REG1 and BPM_MAGIC_REG2
     *                              respectively.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t writeToMagicRegisters(
            uint8_t const (&i_magicValues)[NUM_MAGIC_REGISTERS]);

    /**
     *  @brief Switches the page on the BPM to the given page. This function
     *         must be executed only after the segment read magic values have
     *         been written to the BPM's magic registers.
     *
     *  @param[in]  i_segmentCode   The segment code that corresponds to the
     *                              page to switch to on the BPM.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error
     *
     */
    errlHndl_t switchBpmPage(uint16_t i_segmentCode);

    /**
     *  @brief Dumps the given segment data from the BPM. CANNOT be in BSL mode.
     *
     *  @param[in]  i_segmentCode   The segment code that corresponds to the
     *                              segment to dump from the BPM.
     *
     *  @param[out] o_buffer        A pointer to the buffer to fill with segment
     *                              data. Must be SEGMENT_SIZE in size.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error
     *
     */
    errlHndl_t dumpSegment(uint16_t i_segmentCode,
                           uint8_t  (&o_buffer)[SEGMENT_SIZE]);

    /**
     *  @brief Merges the segment data dumped from the BPM with the segment data
     *         fragments present in the BpmConfigLidImage that correspond to the
     *         given segment code.
     *
     *  @param[in]  i_configImage      The image that holds the fragments of
     *                                 segment data.
     *
     *  @param[in]  i_segmentCode      The segment code that corresponds to the
     *                                 segment to dump from the BPM.
     *
     *  @param[out] o_buffer           The merged segment data for the BPM.
     *                                 Must be SEGMENT_SIZE in length.
     *
     *  @return     errlHndl_t         nullptr on success. Otherwise, an error.
     */
    errlHndl_t mergeSegment(BpmConfigLidImage i_configImage,
                            uint16_t          i_segmentCode,
                            uint8_t           (&o_buffer)[SEGMENT_SIZE]);

    /**
     *  @brief Commands the BPM to erase the segment data on the BPM using the
     *         given segment code to tell it which to erase.
     *         The BPM must be in BSL mode for this function to work.
     *
     *  @param[in]  i_segmentCode   The segment from the config data section to
     *                              erase.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t eraseSegment(uint16_t i_segmentCode);

    /**
     *  @brief Writes the segment data from the buffer to the BPM using the
     *         given segment code to determine which segment the data belongs
     *         to. The BPM must be in BSL mode for this function to work.
     *
     *  @param[in]  i_buffer        The segment data to write to the BPM.
     *
     *  @param[in]  i_segmentCode   The segment from the config data section the
     *                              data belongs to.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t writeSegment(uint8_t const (&i_buffer)[SEGMENT_SIZE],
                            uint16_t i_segmentCode);

    /**
     *  @brief Dumps segment D and B data from the BPM and merges it with the
     *         data from the config image to create the unique updated segments
     *         for this BPM. The BPM CANNOT be in BSL mode for this function to
     *         work because the data is dumped using SCAP registers. There must
     *         also be working firmware on the device otherwise this will fail.
     *
     *  @param[in]  i_configImage   The config image that has the fragments to
     *                              merge into the BPM's existing segment data.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t preprocessSegments(BpmConfigLidImage i_configImage);

    /**
     *  @brief  Verifies that the data written into the flash on the BPM is what
     *          was sent by hostboot in a payload.
     *
     *  @param[in]  i_payload       The payload that was just sent to the BPM to
     *                              be verified.
     *
     *  @param[in]  i_dataLength    The length of the data section of the
     *                              payload.
     *
     *  @param[in]  o_status        The status code returned from the BPM.
     *                              A status of 0 indicates success, all other
     *                              values are a failure.
     *
     *  @return     errlHndl_t      nullptr if no errors. Otherwise, an error.
     */
    errlHndl_t verifyBlockWrite(payload_t i_payload,
                                uint8_t   i_dataLength,
                                uint8_t & o_status);

    /**
     *  @brief Attempts a BSL_RX_DATA_BLOCK command up to three times by calling
     *         blockWriteRetry.
     *
     *  @param[in]  i_payload       The payload containing the BSL_RX_DATA_BLOCK
     *                              command and the data to be attempted to be
     *                              written.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t blockWrite(payload_t i_payload);

    /**
     *  @brief Attempts a BSL_RX_DATA_BLOCK command up to three times.
     *
     *  @param[in]  i_payload       The payload containing the BSL_RX_DATA_BLOCK
     *                              command and the data to be attempted to be
     *                              written.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t blockWriteRetry(payload_t i_payload);

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

    errlHndl_t verifyGoodBpmState();

    /**
     *  @brief Starting with BSL version 1.4 it is necessary to check the CRC of
     *         the firmware image once it has been written to the BPM. If this
     *         is not done or fails to succeed then the firmware image will not
     *         be loaded and executed by the BPM. If the CRC check fails then
     *         the update must be attempted again.
     *         Must be in BSL mode.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t checkFirmwareCrc();

    /**
     *  @brief After a command is sent to the BPM to request info from it this
     *         function processes the response and returns it to the caller.
     *         A response packet can only be received once per command sent to
     *         the BPM. Which means that the caller must resend the command
     *         again to get another response packet. Simply calling the function
     *         repeatedly will not work. BPM must be in BSL mode.
     *
     *  @param[in]  o_responseData      The buffer to be filled with the
     *                                  response data from the BPM.
     *
     *  @param[in]  i_responseSize      The size of the buffer to be filled.
     *
     *  @return     errlHndl_t          nullptr on success. Otherwise, an error.
     */
    errlHndl_t getResponse(uint8_t * o_responseData,
                           uint8_t   i_responseSize);


    /**
     *  @brief Helper function to handle two potential errors that might occur in a
     *         function that only returns a single error log. If the return error is
     *         not nullptr then the second error will be linked to it and committed
     *         if this is the final update attempt. Otherwise, it will be deleted
     *         since the update procedure will occur again and may be successful.
     *         If the return error is nullptr then the return error will point to
     *         the second's error and the second error will point to nullptr.
     *
     *  @param[in/out]      io_returnErrl   A pointer to the error that would be
     *                                      returned by the function that called
     *                                      this one. If nullptr, then it will be
     *                                      set point to the secondary error and
     *                                      that error will become nullptr.
     *
     *  @param[in/out]     io_secondErrl    The secondary error that occurred which
     *                                      in addition to the usual returned error.
     */
    void handleMultipleErrors(errlHndl_t& io_returnErrl,
                              errlHndl_t& io_secondErrl);

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

#endif //#ifndef __HOSTBOOT_RUNTIME

    /**
     *  @brief Helper function for the SCAP register functions that will poll
     *         the busy bit in SCAP_STATUS until it is zero.
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t waitForBusyBit();

    /**
     *  @brief Write to the BPM register via the SCAP registers
     *
     *  @param[in]      i_reg       The BPM register to write to.
     *
     *  @param[in]      i_data      The data to write to the given register.
     *
     *  @return         errlHndl_t  nullptr on success. Otherwise, an error.
     */
    errlHndl_t writeViaScapRegister(uint8_t i_reg, uint8_t i_data);

    /**
     *  @brief Reads the BPM register via the SCAP registers
     *
     *  @param[in]      i_reg       The BPM register to read from.
     *
     *  @param[in/out]  io_data     The data that was in the given register.
     *
     *  @return         errlHndl_t  nullptr on success. Otherwise, an error.
     */
    errlHndl_t readViaScapRegister(uint8_t i_reg, uint8_t & io_data);

    /**
     *  @brief Disables write protection on the BPM by sending the password
     *         sequence to I2C_REG_PROTECT
     *
     *  @return     errlHndl_t      nullptr on success. Otherwise, an error.
     */
    errlHndl_t disableWriteProtection();

};

typedef std::vector<Bpm> bpmList_t;

/**
 * @brief Runs the firmware and config updates on the list of BPMs given.
 *
 * @param[in] i_16gb_BPMs   The list of BPMs sitting on 16gb NVDIMMs that
 *                          potentially need to be updated.
 *
 * @param[in] i_32gb_BPMs   The list of BPMs sitting on 32gb NVDIMMs that
 *                          potentially need to be updated.
 *
 * @param[in] i_16gb_fwImage    The firmware image associated with BPMs sitting
 *                              on 16gb NVDIMMs.
 *
 * @param[in] i_32gb_fwImage    The firmware image associated with BPMs sitting
 *                              on 32gb NVDIMMs.
 *
 * @param[in] i_16gb_configImage    The configuration data associated with BPMs
 *                                  sitting on 16gb NVDIMMs.
 *
 * @param[in] i_32gb_configImage    The configuration data associated with BPMs
 *                                  sitting on 32gb NVDIMMs.
 *
 */
void runBpmUpdates(bpmList_t * const i_16gb_BPMs,
                   bpmList_t * const i_32gb_BPMs,
                   BpmFirmwareLidImage * const i_16gb_fwImage,
                   BpmFirmwareLidImage * const i_32gb_fwImage,
                   BpmConfigLidImage * const i_16gb_configImage,
                   BpmConfigLidImage * const i_32gb_configImage);

}; // end of BPM namespace
}; // end of NVDIMM namespace

#endif

