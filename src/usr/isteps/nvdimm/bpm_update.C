/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/bpm_update.C $                          */
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

#include "nvdimm.H"
#include "bpm_update.H"
#include "nvdimm_update.H"

#include <errl/hberrltypes.H>
#include <endian.h>
#include <sys/time.h>
#include <hbotcompid.H>
#include <trace/interface.H>
#include <targeting/common/targetservice.H>

namespace NVDIMM
{
namespace BPM
{

trace_desc_t* g_trac_bpm = nullptr;
TRAC_INIT(&g_trac_bpm, BPM_COMP_NAME, 2*KILOBYTE);

// For debug traces
#define TRACUCOMP(args...)
//#define TRACUCOMP(args...) TRACFCOMP(args)

// See bpm_update.H for more info on these constants.
const size_t MAX_PAYLOAD_SIZE = 26;
const size_t MAX_PAYLOAD_DATA_SIZE = 16;
const size_t MAX_PAYLOAD_OTHER_DATA_SIZE = 10;
const uint8_t PAYLOAD_HEADER_SIZE = 4;
const uint8_t SYNC_BYTE = 0x80;

// These constants are kept out of the header file since they aren't relevant
// outside of this file.
const uint16_t BPM_ADDRESS_ZERO = 0;

// In order to disable write protection on the BPM to perform updates a sequence
// of characters must be written. The hex represenation of those characters are
// defined by this constant. The sequence is SMOD
const uint8_t BPM_PASSWORD[] = {0x53, 0x4D, 0x4F, 0x44};
const size_t BPM_PASSWORD_LENGTH = 4;
const size_t NUM_MAGIC_REGISTERS = 2;

/**
 * @brief A helper function used in assert statements to verify the correct
 *        BSP commands were passed into the correct function arguments.
 *
 * @param[in]   i_command    The command that will verified to be a BSP command.
 *
 * @return      bool         true if i_command is a BSP command.
 *                           false if it's not a BSP command.
 */
bool isBspCommand(const uint8_t i_command)
{
    bool result = ((i_command == BPM_PASSTHROUGH) || (i_command == BPM_LOCAL))
                  ? true : false;

    return result;
}

/**
 * @brief A helper function used in assert statements to verify the correct
 *        BCL commands were passed into the correct function arguments.
 *
 * @param[in]   i_command    The command that will verified to be a BCL command.
 *
 * @return      bool         true if i_command is a BCL command.
 *                           false if it's not a BCL command.
 */
bool isBclCommand(const uint8_t i_command)
{
    bool result = false;
    switch(i_command)
    {
        case BCL_ENTER_BSL_MODE:
        case BCL_IS_BSL_MODE:
        case BCL_WRITE_REG:
        case BCL_START_UPDATE:
        case BCL_END_UPDATE:
        case BCL_IS_UPDATE_IN_PROGRESS:
        {
            result = true;
            break;
        }
        default:
        {
            result = false;
            break;
        }
    }

    return result;
}

/**
 * @brief A helper function used in assert statements to verify the correct
 *        BSL commands were passed into the correct function arguments.
 *
 * @param[in]   i_command    The command that will verified to be a BSL command.
 *
 * @return      bool         true if i_command is a BSL command.
 *                           false if it's not a BSL command.
 */
bool isBslCommand(const uint8_t i_command)
{
    bool result = false;
    switch(i_command)
    {
        case BSL_RX_DATA_BLOCK:
        case BSL_RX_PASSWORD:
        case BSL_ERASE_SEGMENT:
        case BSL_TOGGLE_INFO:
        case BSL_ERASE_BLOCK:
        case BSL_MASS_ERASE:
        case BSL_CRC_CHECK:
        case BSL_LOAD_PC:
        case BSL_TX_DATA_BLOCK:
        case BSL_TX_BSL_VERSION:
        case BSL_TX_BUFFER_SIZE:
        case BSL_RX_DATA_BLOCK_FAST:
        case BSL_RESET_DEVICE:
        case BSL_VERIFY_BLOCK:
        {
            result = true;
            break;
        }
        default:
        {
            result = false;
            break;
        }
    }

    return result;
}

// =============================================================================
//                      BpmFirmwareLidImage Class Functions
// =============================================================================

BpmFirmwareLidImage::BpmFirmwareLidImage(void * const i_lidImageAddr,
                                         size_t i_size)
    : iv_lidImage(i_lidImageAddr), iv_lidImageSize(i_size)
{
}

uint16_t BpmFirmwareLidImage::getVersion() const
{
    uint16_t version = INVALID_VERSION;

    if (iv_lidImageSize >= sizeof(firmware_image_header_t))
    {
        const firmware_image_header_t * header =
            reinterpret_cast<const firmware_image_header_t*>(iv_lidImage);

        version = TWO_UINT8_TO_UINT16(header->iv_versionMajor,
                                      header->iv_versionMinor);
    }

    return version;
}

uint16_t BpmFirmwareLidImage::getNumberOfBlocks() const
{
    uint16_t numberOfBlocks = 0;

    if (iv_lidImageSize >= sizeof(firmware_image_header_t))
    {
        const firmware_image_header_t * header =
            reinterpret_cast<const firmware_image_header_t*>(iv_lidImage);

        numberOfBlocks = header->iv_numberOfBlocks;
    }

    return numberOfBlocks;
}

void const * BpmFirmwareLidImage::getFirstBlock() const
{
    void * block = nullptr;

    if (getNumberOfBlocks() > 0)
    {
        block = reinterpret_cast<uint8_t* const>(iv_lidImage)
                + sizeof(firmware_image_header_t);
    }

    return block;
}

// =============================================================================
//                           Bpm Class Functions
// =============================================================================

Bpm::Bpm(const TARGETING::TargetHandle_t i_nvdimm)
    : iv_nvdimm(i_nvdimm), iv_bslVersion(0)
{
    assert((i_nvdimm != nullptr) && (isNVDIMM(i_nvdimm)),
          "An nvdimm target must be given.");
}

errlHndl_t Bpm::readBslVersion()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::readBslVersion()");
    errlHndl_t errl = nullptr;

    do {
        // Command to get the version is a BSL command, so it has to be sent as
        // a payload.
        payload_t payload;
        errl = setupPayload(payload, BSL_TX_BSL_VERSION, BPM_ADDRESS_ZERO);
        if (errl != nullptr)
        {
            break;
        }

        // Issue the BSL command
        errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        // Get the result from the BPM.
        // First clear the error status register
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_ERR_STATUS,
                              0x00);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                      "Failed to clear error status register");
            break;
        }

        // Set the payload length
        uint8_t data = payload.size();
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_PAYLOAD_LENGTH,
                              data);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                      "Failed to set payload length");
            break;
        }

        // Setup the command status register
        command_status_register_t commandStatus;
        commandStatus.bits.Bsp_Cmd_In_Progress = 1;
        commandStatus.bits.Operator_Type = READ;
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_CMD_STATUS,
                              commandStatus.value);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                      "Failed to setup command status register");
            break;
        }

        // Setup command type.
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_CMD,
                              BPM_PASSTHROUGH);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                      "Failed to setup command type. "
                      "Read BSL version command was not sent to BPM.");
            break;
        }

        errl = waitForCommandStatusBitReset(commandStatus);

        // Read out the version payload.
        payload_t versionPayload;

        const size_t VERSION_PAYLOAD_SIZE = 7;
        const size_t VERSION_PAYLOAD_VERSION_INDEX = 4;
        for (size_t i = 0; i < VERSION_PAYLOAD_SIZE; ++i)
        {
            uint8_t data = 0;
            errl = nvdimmReadReg(iv_nvdimm,
                                (BPM_REG_PAYLOAD_START + (i * sizeof(uint8_t))),
                                data);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                          "Failed to read version payload");
                break;
            }

            versionPayload.push_back(data);
        }
        if (errl != nullptr)
        {
            break;
        }

        iv_bslVersion = versionPayload[VERSION_PAYLOAD_VERSION_INDEX];

        TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): BSL Version is 0x%X",
                  iv_bslVersion);

    } while(0);

    return errl;
}

errlHndl_t Bpm::getFwVersion(uint16_t & o_fwVersion) const
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::getFwVersion()");
    errlHndl_t errl = nullptr;

    do {
        uint8_t bpmMajor = 0, bpmMinor = 0;
        errl = nvdimmReadReg(iv_nvdimm,
                             ES_FWREV1,
                             bpmMajor);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::getFwVersion(): "
                      "Failed to read BPM major version byte");
            break;
        }

        errl = nvdimmReadReg(iv_nvdimm,
                             ES_FWREV0,
                             bpmMinor);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::getFwVersion(): "
                      "Failed to read BPM minor version byte");
            break;
        }

        o_fwVersion = TWO_UINT8_TO_UINT16(bpmMajor, bpmMinor);

    } while(0);

    return errl;
}

errlHndl_t Bpm::issueCommand(const uint8_t i_bspCommand,
                             const uint8_t i_command,
                             const uint8_t i_opType)
{
    assert(isBspCommand(i_bspCommand),
           "i_bspCommand must be a valid BSP command");
    assert(isBclCommand(i_command),
           "i_command must be a valid BCL command");
    // i_opType gets set in the BPM_CMD_STATUS register where it is only given
    // two bits. So any value above 3 is not valid.
    assert(i_opType <= 3, "i_opType can only range between 0 and 3");

    errlHndl_t errl = nullptr;

    // i_command must be sent in BPM_REG_PAYLOAD_START, but it doesn't need to
    // be formatted into a typical payload since the command isn't a BSL
    // command. So, just create a payload_t, push_back the command, and let the
    // issueCommand function that takes a payload_t parameter handle the rest.
    payload_t payloadCommand;
    payloadCommand.push_back(i_command);

    errl = issueCommand(i_bspCommand, payloadCommand, i_opType);

    return errl;
}

errlHndl_t Bpm::issueCommand(const uint8_t i_command,
                             payload_t     i_payload,
                             const uint8_t i_opType)
{
    assert(isBspCommand(i_command),
           "i_bspCommand must be a valid BSP command");

    // i_opType gets set in the BPM_CMD_STATUS register where it is only given
    // two bits. So any value above 3 is not valid.
    assert(i_opType <= 3, "i_opType can only range between 0 and 3");

    errlHndl_t errl = nullptr;

    do {

        if (i_payload.size() > MAX_PAYLOAD_SIZE)
        {
            //@TODO RTC 212447: Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::issueCommand(): "
                     "payload size %d exceeds max payload size of %d",
                     i_payload.size(), MAX_PAYLOAD_SIZE);
            break;
        }

        // Load the payload
        int i = 0;
        for (const auto& byte : i_payload)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                (BPM_REG_PAYLOAD_START + (i * sizeof(uint8_t))),
                                  byte);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::issueCommand(): "
                          "Failed to write payload to BPM_REG_PAYLOAD_START");
                break;
            }

            ++i;
        }
        if (errl != nullptr)
        {
            break;
        }

        // Clear the error status register
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_ERR_STATUS,
                              0x00);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::issueCommand(): "
                      "Failed to clear error status register");
            break;
        }

        // Set the payload length
        uint8_t data = i_payload.size();
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_PAYLOAD_LENGTH,
                              data);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::issueCommand(): "
                      "Failed to set payload length");
            break;
        }

        // Setup the command status register
        command_status_register_t commandStatus;
        commandStatus.bits.Bsp_Cmd_In_Progress = 1;
        commandStatus.bits.Operator_Type = i_opType;
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_CMD_STATUS,
                              commandStatus.value);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::issueCommand(): "
                      "Failed to setup the command status register");
            break;
        }

        // Setup command type. The basically executes the command
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_CMD,
                              i_command);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::issueCommand(): "
                      "Failed to set the command type. "
                      "The command was not issued to the BPM");
            break;
        }

        errl = waitForCommandStatusBitReset(commandStatus);
        if (errl != nullptr)
        {
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::runUpdate(BpmFirmwareLidImage i_image)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::runUpdate(): "
              "Running BPM Update for NVDIMM 0x%.8X",
               TARGETING::get_huid(iv_nvdimm));

    errlHndl_t errl = nullptr;
    do {

        // Check the version on the BPM against the version in the image.
        uint16_t bpmFwVersion = INVALID_VERSION;
        errl = getFwVersion(bpmFwVersion);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runUpdate(): "
                     "Could not determine firmware version on BPM "
                     "Skipping update.");
            break;
        }

        if (i_image.getVersion() == bpmFwVersion)
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                     "Firmware version on the BPM matches the version in the "
                     "image. Skipping update.");

            // @TODO RTC 212448: disable forced updates.
            //break;
        }

        TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                  "Firmware version on the BPM 0x%.4X, "
                  "Firmware version of image 0x%.4X. Running Updates",
                  bpmFwVersion, i_image.getVersion());

        // Enter Update mode
        errl = enterUpdateMode();
        if (errl != nullptr)
        {
            break;
        }

        // Verify in Update mode
        errl = inUpdateMode();
        if (errl != nullptr)
        {
            break;
        }

        // Enter Bootstrap Loader (BSL) mode to perform firmware update
        errl = enterBootstrapLoaderMode();
        if (errl != nullptr)
        {
            break;
        }

        // Unlock the device. This is a BSL command so we must already be in
        // BSL mode to execute it.
        errl = unlockDevice();
        if (errl != nullptr)
        {
            break;
        }

        // Depending on the BSL version a CRC check may be necessary
        // @TODO RTC 212446: Add CRC check to update procedure
        errl = readBslVersion();
        if (errl != nullptr)
        {
            break;
        }

        // Run Firmware Update
        errl = updateFirmware(i_image);
        if (errl != nullptr)
        {
            break;
        }



        // @TODO RTC 212446 Config Update
        // Perform the configuration data segment updates.
        // This is done via SCAP Registers and not the BSL interface.

//        // Reset the device. This will exit BSL mode.
//        errl = resetDevice();
//        if (errl != nullptr)
//        {
//            break;
//        }
//
//        // Enter BSL mode to reset the device
//        errl = enterBootstrapLoaderMode();
//        if (errl != nullptr)
//        {
//            break;
//        }
//
//        // Unlock the device. This is a BSL command so we must already be in
//        // BSL mode to execute it.
//        errl = unlockDevice();
//        if (errl != nullptr)
//        {
//            break;
//        }

    } while(0);

    // Reset the device. This will exit BSL mode.
    errlHndl_t exitErrl = resetDevice();
    if (exitErrl != nullptr)
    {
        //@TODO RTC 212447 Do something with the error.
        delete exitErrl;
    }

    // Exit update mode
    exitErrl = exitUpdateMode();
    if (exitErrl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runUpdate(): "
                  "Failed to exit update mode");
        //@TODO RTC 212447 Do something with the error.
        delete exitErrl;
    }

    // To see the BPM firmware level updated we must reset the controller
    exitErrl = nvdimmWriteReg(iv_nvdimm,
                              NVDIMM_MGT_CMD0,
                              0x01);
    if (exitErrl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runUpdate(): "
                 "Could not reset NVDIMM Controller");
        //@TODO RTC 212447: Do something with the error.
        delete exitErrl;
    }

    TRACFCOMP(g_trac_bpm, "Bpm::runUpdate(): "
              "Reset command sent to NVDIMM controller, sleep for 15 seconds");
    nanosleep(15,0);

    uint16_t bpmFwVersion = INVALID_VERSION;
    exitErrl = getFwVersion(bpmFwVersion);
    if (exitErrl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runUpdate(): "
                 "Could not determine firmware version on the BPM");
        //@TODO RTC 212447 Do something with the error.
        delete exitErrl;
    }

    // @TODO RTC 212446: Depending on BSL version, need to do CRC check.
    if (i_image.getVersion() == bpmFwVersion)
    {
        TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                 "Firmware version on the BPM matches the version in the "
                 "image. Update Successful.");
    }

    TRACFCOMP(g_trac_bpm, EXIT_MRK"Bpm::runUpdate(): "
              "Concluding BPM Update for NVDIMM 0x%.8X",
              TARGETING::get_huid(iv_nvdimm));

    return errl;
}

errlHndl_t Bpm::inUpdateMode()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::inUpdateMode()");
    errlHndl_t errl = nullptr;

    do {

        errl = issueCommand(BPM_LOCAL, BCL_IS_UPDATE_IN_PROGRESS, READ);
        if (errl != nullptr)
        {
            break;
        }

        uint8_t isUpdateInProgress = 0;
        errl = nvdimmReadReg(iv_nvdimm,
                             BPM_REG_ERR_STATUS,
                             isUpdateInProgress);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::inUpdateMode(): "
                      "Failed to read error status register");
            break;
        }

        if (!isUpdateInProgress)
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::inUpdateMode(): "
                     "Failed to enter update mode");
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::enterUpdateMode()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::enterUpdateMode()");
    errlHndl_t errl = nullptr;

    do {

        // The following write sequence to the I2C_REG_PROTECT register removes
        // write protection from registers 0x40-0x7F on page 4.
        for ( size_t i = 0; i < BPM_PASSWORD_LENGTH; ++i)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                  I2C_REG_PROTECT,
                                  BPM_PASSWORD[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::enterUpdateMode(): "
                          "Failed to write the unlock sequence to "
                          "I2C_REG_PROTECT");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // Make sure protection was removed
        uint8_t data = 0;
        errl = nvdimmReadReg(iv_nvdimm,
                             I2C_REG_PROTECT,
                             data);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::enterUpdateMode(): "
                      "Failed to verify that write protection was removed");
            break;
        }

        if (!(data & SYNC_BYTE))
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::enterUpdateMode(): "
                      "Failed to disable write protection. I2C_REG_PROTECT");
            break;
        }

        // Write the magic values to enable nvdimm-bpm interface
        const uint8_t magic_values[NUM_MAGIC_REGISTERS] = {0xB0, 0xDA};
        const uint16_t magic_registers[NUM_MAGIC_REGISTERS] =
            {BPM_MAGIC_REG1, BPM_MAGIC_REG2};

        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                  magic_registers[i],
                                  magic_values[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::enterUpdateMode(): "
                          "Failed to write magic numbers that enable "
                          "update mode");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // Verify the magic values were written
        uint8_t magic_data[NUM_MAGIC_REGISTERS] = {};
        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmReadReg(iv_nvdimm,
                                 magic_registers[i],
                                 magic_data[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::enterUpdateMode(): "
                          "Failed to read back values in magic registers to "
                          "verfiy that update mode was enabled");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // If either of the magic values stored in magic_data don't match the
        // corresponding expected values in magic_values then an error occurred.
        if (  (magic_data[0] != magic_values[0])
           || (magic_data[1] != magic_values[1]))
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::enterUpdateMode(): "
                     "Magic values read from BPM didn't match expected values "
                     "BPM_MAGIC_REG1 Expected 0x%.2X Actual 0x%.2X "
                     "BPM_MAGIC_REG2 Expected 0x%.2X Actual 0x%.2X",
                     magic_values[0], magic_data[0],
                     magic_values[1], magic_data[1]);
            break;
        }

        errl = issueCommand(BPM_LOCAL, BCL_START_UPDATE, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        nanosleep(2,0);

    } while(0);

    return errl;
}

errlHndl_t Bpm::exitUpdateMode()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::exitUpdateMode()");
    errlHndl_t errl = nullptr;

    do {

        errl = issueCommand(BPM_LOCAL, BCL_END_UPDATE, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        // Write back the production magic values
        const uint8_t magic_values[NUM_MAGIC_REGISTERS] = {0x55, 0xAA};
        const uint16_t magic_registers[NUM_MAGIC_REGISTERS] =
            {BPM_MAGIC_REG1, BPM_MAGIC_REG2};

        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                  magic_registers[i],
                                  magic_values[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::exitUpdateMode(): "
                          "Failed to write the production magic values to "
                          "disable update mode.");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // Verify the magic values were written
        uint8_t magic_data[NUM_MAGIC_REGISTERS] = {};
        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmReadReg(iv_nvdimm,
                                 magic_registers[i],
                                 magic_data[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::exitUpdateMode(): "
                          "Failed to read back magic values to verify that "
                          "update mode was disabled.");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // If either of the magic values stored in magic_data don't match the
        // corresponding expected values in magic_values then an error occurred.
        if (  (magic_data[0] != magic_values[0])
           || (magic_data[1] != magic_values[1]))
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::exitUpdateMode(): "
                     "Magic values read from BPM didn't match expected values "
                     "BPM_MAGIC_REG1 Expected 0x%.2X Actual 0x%.2X "
                     "BPM_MAGIC_REG2 Expected 0x%.2X Actual 0x%.2X",
                     magic_values[0], magic_data[0],
                     magic_values[1], magic_data[1]);
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::updateFirmware(BpmFirmwareLidImage i_image)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::updateFirmware()");
    errlHndl_t errl = nullptr;

    const uint16_t MAIN_PROGRAM_ADDRESS = 0x8000;
    const uint16_t NUMBER_OF_BLOCKS = i_image.getNumberOfBlocks();

    char const * data =
        reinterpret_cast<char const *>(i_image.getFirstBlock());

    firmware_image_block_t const * block =
        reinterpret_cast<firmware_image_block_t const *>
            (data);

    for(size_t i = 0; i < NUMBER_OF_BLOCKS; ++i)
    {
        // This is done once at the main program address.
        if (block->iv_addressOffset == MAIN_PROGRAM_ADDRESS)
        {
            payload_t payload;
            errl = setupPayload(payload, BSL_MASS_ERASE, MAIN_PROGRAM_ADDRESS);
            if (errl != nullptr)
            {
                break;
            }

            errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
            if (errl != nullptr)
            {
                break;
            }

            TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                      "Performing BSL_MASS_ERASE, sleep for 5 seconds.");
            nanosleep(5,0);
        }

        // Construct the payload for this block in the image
        payload_t payload;
        errl = setupPayload(payload, block, BSL_RX_DATA_BLOCK);
        if (errl != nullptr)
        {
            break;
        }

        // Send the payload data over as a pass-through command
        errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        // Sleep for 0.01 second
        nanosleep(0, 0.1 * NS_PER_MSEC);

        // Move to the next block
        // iv_blocksize doesn't include the sizeof itself. So, add another byte
        // for it.
        data += block->iv_blockSize + sizeof(uint8_t);

        block = reinterpret_cast<firmware_image_block_t const *>(data);
    }

    return nullptr;
}

errlHndl_t Bpm::enterBootstrapLoaderMode()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::enterBootstrapLoaderMode()");
    errlHndl_t errl = nullptr;

    do {

        // Entering BSL mode depends on the state of the BPM and it may need
        // several retries in order to successfully enter BSL mode.
        int retry = 10;
        bool inBslMode = false;

        while (retry != 0)
        {

            errl = issueCommand(BPM_LOCAL, BCL_IS_BSL_MODE, WRITE);
            if (errl != nullptr)
            {
                break;
            }

            uint8_t data = 0;
            errl = nvdimmReadReg(iv_nvdimm,
                                 BPM_REG_ERR_STATUS,
                                 data);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::enterBootstrapLoaderMode(): "
                          "Failed to read BPM_REG_ERR_STATUS to verify that "
                          "BSL mode was enabled.");
                break;
            }
            // data will be 1 if the BPM successfully entered BSL mode.
            if (data == 1)
            {
                inBslMode = true;
                TRACFCOMP(g_trac_bpm, "Bpm::enterBootstrapLoaderMode(): "
                          "BSL Mode entered, sleep for 5 seconds.");
                nanosleep(5,0);
                break;
            }

            TRACUCOMP(g_trac_bpm, "Bpm::enterBootstrapLoaderMode(): "
                      "Unable to enter BSL Mode, retries remaining %d. "
                      "Sleep for 2 seconds before trying again.",
                      (retry - 1));

            nanosleep(2,0);

            errl = issueCommand(BPM_LOCAL, BCL_ENTER_BSL_MODE, WRITE);

            --retry;

            // Sleep for 0.01 second before next attempt.
            nanosleep(0, 0.1 * NS_PER_MSEC);
        }

        if (!inBslMode)
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::enterBootstrapLoaderMode(): "
                     "Failed to enter BSL mode on the BPM");

            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::setupPayload(payload_t       & o_payload,
                             const uint8_t     i_command,
                             const uint16_t    i_address,
                             const uint8_t     i_data[],
                             const size_t      i_length)
{
    // Enforce sane inputs
    assert((    (i_data == nullptr && i_length == 0)
             || (i_data != nullptr && i_length != 0)),
          "if i_length is non-zero then i_data must not be nullptr, otherwise i_data must be nullptr.");
    assert(isBslCommand(i_command),
           "i_command must be a valid BSL command");

    errlHndl_t errl = nullptr;

    // Calculate the block size.
    size_t blockSize = sizeof(uint16_t) + i_length;

    // Allocate memory for the block
    firmware_image_block_t* myBlock = reinterpret_cast<firmware_image_block_t*>(
        malloc(sizeof(firmware_image_block_t) + i_length));

    // Setup the block "header" info
    myBlock->iv_blockSize = blockSize;
    myBlock->iv_addressOffset = i_address;

    // Copy the data if any exists.
    if (i_data != nullptr)
    {
        memcpy(&myBlock->iv_data, i_data, i_length);
    }

    // Setup the return payload
    errl = setupPayload(o_payload, myBlock, i_command);

    // Block is no longer needed.
    free(myBlock);

    return errl;
}

errlHndl_t Bpm::setupPayload(payload_t                    & o_payload,
                             const firmware_image_block_t * i_block,
                             const uint8_t                  i_command)
{
    assert(i_block != nullptr, "i_block must not be nullptr.");
    assert(isBslCommand(i_command),
           "i_command must be a valid BSL command");

    errlHndl_t errl = nullptr;

    // The data size in the block is the total block size
    // minus the 2 bytes for the address offset.
    const uint8_t blockDataSize = i_block->iv_blockSize - sizeof(uint16_t);

    // The header plus payload data section size. This excludes the address
    // offset, extra bytes, and CRC bytes.
    const uint8_t headerDataSize = PAYLOAD_HEADER_SIZE + blockDataSize;

    do {

    if (blockDataSize > MAX_PAYLOAD_DATA_SIZE)
    {
        // @TODO RTC 212447 Error
        TRACFCOMP(g_trac_bpm, ERR_MRK
                 "Bpm::setupPayload(): Block Data Size %d exceeds max payload "
                 "size of %d",
                 blockDataSize,
                 MAX_PAYLOAD_DATA_SIZE);
        break;
    }

    // Create the payload with the exact size needed.
    payload_t payload(MAX_PAYLOAD_OTHER_DATA_SIZE + blockDataSize);

    // Instead of using push_back, use a pointer to an element in the vector.
    // Since the size of the vector is declared and intialized to zero ahead of
    // time push_back will not work. Also, some of the data is larger than
    // uint8_t and so it's easier to just use memcpy for insertion.
    // NOTE: Because push_back isn't being used the size() of the vector doesn't
    //       change along with the data being added to the vector. This was
    //       corrected by explicitly setting the payload size in the constructor
    //       call above.
    uint8_t * payloadIterator = payload.data();

    // According to SMART, we must supply the header + data size twice.
    uint8_t header[PAYLOAD_HEADER_SIZE] = { SYNC_BYTE,
                                            i_command,
                                            headerDataSize,
                                            headerDataSize };

    memcpy(payloadIterator, &header, PAYLOAD_HEADER_SIZE);

    // Move past the header
    payloadIterator += PAYLOAD_HEADER_SIZE;

    // Write the address offset in little endian form.
    uint16_t addressLE = htole16(i_block->iv_addressOffset);
    uint8_t* addressOffset = reinterpret_cast<uint8_t*>(&addressLE);
    memcpy(payloadIterator, addressOffset, sizeof(uint16_t));

    // Move past the address
    payloadIterator += sizeof(uint16_t);

    // The extra bytes vary based on the given command.
    // These are the extra bytes for their corresponding bootstrap loader
    // commands. They are arranged in little endian form so that no byte
    // swapping is required.
    const uint8_t BSL_ERASE_SEGMENT_EXTRA_BYTES[] = {0x02, 0xA5};
    const uint8_t BSL_MASS_ERASE_EXTRA_BYTES[]    = {0x06, 0xA5};
    switch(i_command)
    {
        case BSL_ERASE_SEGMENT:
        {
            memcpy(payloadIterator,
                   &BSL_ERASE_SEGMENT_EXTRA_BYTES,
                   sizeof(uint16_t));

            break;
        }
        case BSL_MASS_ERASE:
        {
            memcpy(payloadIterator,
                   &BSL_MASS_ERASE_EXTRA_BYTES,
                   sizeof(uint16_t));
            break;
        }
        default:
        {
            // Give the size of the data section as a uint16_t in little
            // endian form.
            uint8_t dataLength[] = {blockDataSize, 0x0};
            memcpy(payloadIterator, &dataLength, sizeof(uint16_t));
            break;
        }
    }

    // Move past the payload's extra bytes.
    payloadIterator += sizeof(uint16_t);

    if (blockDataSize > 0)
    {
        // Copy the payload data from the LID image block to the payload's data
        // section.
        memcpy(payloadIterator, &i_block->iv_data, blockDataSize);

        // Move past the payload's data section.
        payloadIterator += blockDataSize;
    }

    // Calculate the CRC bytes
    // Pass in the size of the payload excluding the two reserved bytes
    // for the CRC.
    uint16_t crc = htole16(crc16_calc(payload.data(), payload.size()-2));

    // Write the CRC bytes
    uint8_t* crcBytes = reinterpret_cast<uint8_t*>(&crc);
    memcpy(payloadIterator, crcBytes, sizeof(uint16_t));

    // The sync byte is automatically sent by the NVDIMM to the BPM so
    // including it in the payload isn't necessary. It is only needed to
    // calculate the CRC bytes.
    payload.erase(payload.begin());
    // Force the returned payload to have the exact capacity and size of the
    // payload.
    o_payload.swap(payload);

    } while(0);

    return errl;
}

errlHndl_t Bpm::unlockDevice()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::unlockDevice()");
    errlHndl_t errl = nullptr;

    do {

        // This is a BSL command, so it must be formatted into a payload.
        payload_t payload;

        // This command must send the password in order to unlock the device.
        errl = setupPayload(payload,
                            BSL_RX_PASSWORD,
                            BPM_ADDRESS_ZERO,
                            BPM_PASSWORD,
                            BPM_PASSWORD_LENGTH);
        if (errl != nullptr)
        {
            break;
        }

        errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::resetDevice()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::resetDevice()");
    errlHndl_t errl = nullptr;

    do {

        // This is a BSL command, so it must be formatted into a payload.
        payload_t payload;
        errl = setupPayload(payload, BSL_RESET_DEVICE, BPM_ADDRESS_ZERO);
        if (errl != nullptr)
        {
            break;
        }

        errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }


        TRACFCOMP(g_trac_bpm, "Bpm::resetDevice(): "
                  "Resetting BPM for NVDIMM 0x%.8X, sleep for 10 seconds.",
                  TARGETING::get_huid(iv_nvdimm));
        nanosleep(10,0);

    } while(0);

    return errl;
}

errlHndl_t Bpm::waitForCommandStatusBitReset(
    command_status_register_t i_commandStatus)
{
    errlHndl_t errl = nullptr;

    do {
        // Wait until the COMMAND_IN_PROGRESS bit is reset
        errl = nvdimmReadReg(iv_nvdimm,
                             BPM_CMD_STATUS,
                             i_commandStatus.value);
        if (errl != nullptr)
        {
            break;
        }

        int retry = 10;

        while (i_commandStatus.bits.Bsp_Cmd_In_Progress)
        {
            nanosleep(0, 1 * NS_PER_MSEC);
            errl = nvdimmReadReg(iv_nvdimm,
                                 BPM_CMD_STATUS,
                                 i_commandStatus.value);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::waitForCommandStatusBitReset(): "
                          "Failed to read BPM_CMD_STATUS register");
                break;
            }

            if (--retry <= 0)
            {
                //@TODO RTC 212447: Error
                TRACFCOMP(g_trac_bpm, ERR_MRK
                         "BPM::waitForCommandStatusBitReset(): "
                         "BSP_CMD_IN_PROGRESS bit has not reset in allotted "
                         "number of retries. Cancel update procedure");
                break;
            }

        }
        if (errl != nullptr)
        {
            break;
        }

        // Check for error
        if (i_commandStatus.bits.Error_Flag)
        {
            uint8_t error = 0;
            errl = nvdimmReadReg(iv_nvdimm,
                                 BPM_REG_ERR_STATUS,
                                 error);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::waitForCommandStatusBitReset(): "
                          "Failed to read BPM_REG_ERR_STATUS");
                break;
            }

            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::getBslVersion(): "
                      "BPM_CMD_STATUS Error Flag is set");
            break;

        }

    } while(0);

    return errl;
}

uint16_t Bpm::crc16_calc(const void* i_ptr, int i_size)
{
    uint16_t crc = 0xFFFF;
    const uint8_t* data = reinterpret_cast<const uint8_t*>(i_ptr);

    assert(*data == SYNC_BYTE,
          "The first byte of data pointed to by i_ptr must be the SYNC_BYTE "
          "in order to calculate the correct CRC16");

    while (--i_size >= 0)
    {
        crc = crc ^ *(data++) << 8;
        for (size_t i = 0; i < 8; ++i)
        {
            if (crc & 0x8000)
            {
                crc = crc << 1 ^ 0x1021;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }

    return (crc & 0xFFFF);
}

}; // End of BPM namespace
}; // End of NVDIMM namespace
