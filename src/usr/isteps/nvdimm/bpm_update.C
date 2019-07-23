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
#include <initservice/istepdispatcherif.H>

namespace NVDIMM
{
namespace BPM
{

trace_desc_t* g_trac_bpm = nullptr;
TRAC_INIT(&g_trac_bpm, BPM_COMP_NAME, 4*KILOBYTE);

// For debug traces
#define TRACUCOMP(args...)
//#define TRACUCOMP(args...) TRACFCOMP(args)

// See bpm_update.H for more info on these constants.
const size_t MAX_PAYLOAD_SIZE            = 26;
const size_t MAX_PAYLOAD_DATA_SIZE       = 16;
const size_t MAX_PAYLOAD_OTHER_DATA_SIZE = 10;
const uint8_t PAYLOAD_HEADER_SIZE        = 4;
const uint8_t SYNC_BYTE                  = 0x80;

// These constants are kept out of the header file since they aren't relevant
// outside of this file.
const uint16_t BPM_ADDRESS_ZERO = 0;
const uint16_t BPM_CONFIG_START_ADDRESS = 0x1800;

// In order to disable write protection on the BPM to perform updates a sequence
// of characters must be written. The hex represenation of those characters are
// defined by this constant. The sequence is SMOD
const uint8_t BPM_PASSWORD[] = {0x53, 0x4D, 0x4F, 0x44};
const size_t BPM_PASSWORD_LENGTH = 4;

// These are the production magic values for the BPM that should be written in
// BPM_MAGIC_REG1 and BPM_MAGIC_REG2 respectively.
const uint8_t PRODUCTION_MAGIC_VALUES[NUM_MAGIC_REGISTERS] = {0x55, 0xAA};

// These are the segment codes used to dump out a particular config data segment
// on the BPM.
const uint16_t DEFAULT_REG_PAGE     = 0x905E;
const uint16_t SEGMENT_A_CODE       = 0x9A5E;
const uint16_t SEGMENT_B_CODE       = 0x9B5E;
const uint16_t SEGMENT_C_CODE       = 0x9C5E;
const uint16_t SEGMENT_D_CODE       = 0x9D5E;

// Starting addresses relative to address 0x1800.
// Segments appear in reverse order on BPM.
// Each segment is SEGMENT_SIZE long.
const size_t SEGMENT_D_START_ADDR = 0x000;
const size_t SEGMENT_C_START_ADDR = 0x080;
const size_t SEGMENT_B_START_ADDR = 0x100;
const size_t SEGMENT_A_START_ADDR = 0x180;

const std::map<uint16_t, size_t> segmentMap
{
    {SEGMENT_A_CODE, SEGMENT_A_START_ADDR},
    {SEGMENT_B_CODE, SEGMENT_B_START_ADDR},
    {SEGMENT_C_CODE, SEGMENT_C_START_ADDR},
    {SEGMENT_D_CODE, SEGMENT_D_START_ADDR},
};

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

/**
 *  @brief  Helper function to extract the Segement ID from the segment code.
 *
 *  @param[in]  i_segmentCode       The Segment code to pull the segment ID from
 *
 *  @return     uint8_t             The Segment ID (A, B, C, D) as a hex value.
 *                                  For example 0xA, 0xB, etc.
 */
uint8_t getSegmentIdentifier(uint16_t i_segmentCode)
{
    uint8_t segmentId = (i_segmentCode >> 8) & 0xF;
    return segmentId;
}

/**
 *  @brief Helper function to sleep for longer durations in 5 second increments.
 *
 *  @param[in]      i_sleepInSeconds    How many seconds to sleep.
 */
void longSleep(uint8_t const i_sleepInSeconds)
{
    int iterations = i_sleepInSeconds / 5;
    do
    {
        // Send progress code.
        INITSERVICE::sendProgressCode();

        // Sleep for 5 seconds
        nanosleep(5, 0);

        --iterations;
    } while (iterations > 0);
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
//                      BpmConfigLidImage Class Functions
// =============================================================================

BpmConfigLidImage::BpmConfigLidImage(void * const i_lidImageAddr,
                                     size_t       i_size)
    : iv_lidImage(i_lidImageAddr), iv_lidImageSize(i_size)
{
    assert(i_lidImageAddr != nullptr,
          "BPM::BpmConfigLidImage(): Provided LID image must not be nullptr");
}

uint16_t BpmConfigLidImage::getVersion() const
{
    uint16_t version = INVALID_VERSION;

    if (iv_lidImageSize >= sizeof(config_image_header_t))
    {
        const config_image_header_t * header =
            reinterpret_cast<const config_image_header_t*>(iv_lidImage);

        version = TWO_UINT8_TO_UINT16(header->iv_versionMajor,
                                      header->iv_versionMinor);
    }

    return version;
}

uint16_t BpmConfigLidImage::getNumberOfFragments() const
{
    uint16_t numberOfFragments = 0;

    if (iv_lidImageSize >= sizeof(config_image_header_t))
    {
        const config_image_header_t * header =
            reinterpret_cast<const config_image_header_t*>(iv_lidImage);

        numberOfFragments = header->iv_numberOfFragments;
    }

    return numberOfFragments;
}

void const * BpmConfigLidImage::getFirstFragment() const
{
    void * fragment = nullptr;

    if (getNumberOfFragments() > 0)
    {
        fragment = reinterpret_cast<uint8_t* const>(iv_lidImage)
                 + sizeof(config_image_header_t);
    }

    return fragment;
}

// =============================================================================
//                           Bpm Class Functions
// =============================================================================

Bpm::Bpm(const TARGETING::TargetHandle_t i_nvdimm)
    : iv_nvdimm(i_nvdimm),
      iv_bslVersion(0),
      iv_firmwareStartAddress(0),
      iv_attemptAnotherUpdate(false),
      iv_segmentDMerged(false),
      iv_segmentBMerged(false)
{
    assert((i_nvdimm != nullptr) && (isNVDIMM(i_nvdimm)),
          "BPM::Bpm(): An nvdimm target must be given.");

    memset(&iv_segmentD, 0, SEGMENT_SIZE);
    memset(&iv_segmentB, 0, SEGMENT_SIZE);

}

bool Bpm::attemptAnotherUpdate()
{
    return iv_attemptAnotherUpdate;
}

const TARGETING::TargetHandle_t Bpm::getNvdimm()
{
    return iv_nvdimm;
}

errlHndl_t Bpm::readBslVersion()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::readBslVersion()");
    errlHndl_t errl = nullptr;

    do {
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
        errl = getResponse(&iv_bslVersion, sizeof(uint8_t));
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): "
                     "Failed to determine BSL Version.");
            break;
        }

        TRACFCOMP(g_trac_bpm, "Bpm::readBslVersion(): BSL Version is 0x%X",
                  iv_bslVersion);

        // Reset the device. This will exit BSL mode.
        errlHndl_t exitErrl = resetDevice();
        if (exitErrl != nullptr)
        {
            break;
        }

        // Exit update mode
        exitErrl = exitUpdateMode();
        if (exitErrl != nullptr)
        {
            break;
        }


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

errlHndl_t Bpm::runUpdate(BpmFirmwareLidImage i_fwImage,
                          BpmConfigLidImage i_configImage)
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

        if (i_fwImage.getVersion() == bpmFwVersion)
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                     "Firmware version on the BPM matches the version in the "
                     "image. Skipping update.");

            // @TODO RTC 212448: disable forced updates.
            //break;
        }

        // Depending on the BSL version a CRC check may be necessary
        errl = readBslVersion();
        if (errl != nullptr)
        {
            break;
        }

        // If the BSL version read from the BPM isn't a supported version then
        // don't perform the updates as the update flow may have changed between
        // BSL versions.
        if (iv_bslVersion != BSL_VERSION_1_4)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::runUpdate(): "
                      "Unsupported BSL Version 0x%.2X detected on BPM. "
                      "Skipping Update.");

            break;
        }

        TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                  "Firmware version on the BPM 0x%.4X, "
                  "Firmware version of image 0x%.4X. Running Update",
                  bpmFwVersion, i_fwImage.getVersion());

        // Before the update begins, we must do some preprocessing prior to the
        // config part of the update. Segment D and B need to be dumped from the
        // BPM into buffers and then the config data from the image needs to be
        // inserted into them. This must happen before enterUpdateMode() as both
        // tamper with the BPM_MAGIC_REGs. Additionally, to dump segment data,
        // it is required to have working firmware which will not be the case
        // during update.
        errl = preprocessSegments(i_configImage);
        if (errl != nullptr)
        {
            break;
        }

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

        // Run Firmware Update
        errl = updateFirmware(i_fwImage);
        if (errl != nullptr)
        {
            break;
        }

        // Perform the configuration data segment updates.
        // As of BSL 1.4 this is done via the BSL interface instead of SCAP
        // registers.
        errl = updateConfig();
        if (errl != nullptr)
        {
            break;
        }

        errl = checkFirmwareCrc();
        if (errl != nullptr)
        {
            // @TODO RTC 212447: Add support for multiple update attempts.
            TRACFCOMP(g_trac_bpm, "Bpm:: runUpdate(): "
                     "Final CRC check failed. Attempting update again...");
            break;
        }

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
    longSleep(15);

    uint16_t bpmFwVersion = INVALID_VERSION;
    exitErrl = getFwVersion(bpmFwVersion);
    if (exitErrl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runUpdate(): "
                 "Could not determine firmware version on the BPM");
        //@TODO RTC 212447 Do something with the error.
        delete exitErrl;
    }

    if (i_fwImage.getVersion() == bpmFwVersion)
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

        // Disable write protection on the BPM. Otherwise, we can't write the
        // magic values that enable the nvdimm-bpm interface.
        errl = disableWriteProtection();
        if (errl != nullptr)
        {
            break;
        }

        // Write the magic values to enable nvdimm-bpm interface
        const uint8_t magic_values[NUM_MAGIC_REGISTERS] = {0xB0, 0xDA};
        errl = writeToMagicRegisters(magic_values);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::enterUpdateMode(): "
                      "Failed to write magic numbers that enable "
                      "update mode");
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
        errl = writeToMagicRegisters(PRODUCTION_MAGIC_VALUES);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::exitUpdateMode(): "
                      "Failed to write the production magic values to "
                      "disable update mode.");
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::updateFirmware(BpmFirmwareLidImage i_image)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::updateFirmware()");
    errlHndl_t errl = nullptr;

    // There are two potential start addresses for the firmware section.
    // They are:
    const uint16_t MAIN_PROGRAM_ADDRESS = 0x8000;
    const uint16_t MAIN_PROGRAM_ADDRESS_ALT = 0xA000;

    bool mainAddressEncountered = false;

    // Get the number of blocks in the image
    const uint16_t NUMBER_OF_BLOCKS = i_image.getNumberOfBlocks();

    char const * data =
        reinterpret_cast<char const *>(i_image.getFirstBlock());

    firmware_image_block_t const * block =
        reinterpret_cast<firmware_image_block_t const *>
            (data);

    for(size_t i = 0; i < NUMBER_OF_BLOCKS; ++i)
    {
        // This is done once at the main program address.
        if ( ((block->iv_addressOffset == MAIN_PROGRAM_ADDRESS)
           || (block->iv_addressOffset == MAIN_PROGRAM_ADDRESS_ALT))
           && !mainAddressEncountered)
        {
            // Only execute this once.
            mainAddressEncountered = true;

            // Save the firmware start address for later. This will be needed
            // for the final CRC check when the update is completed.
            iv_firmwareStartAddress = block->iv_addressOffset;

            payload_t payload;
            errl = setupPayload(payload,
                                BSL_MASS_ERASE,
                                iv_firmwareStartAddress);
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
            longSleep(5);
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

        // Sleep for 0.001 second
        nanosleep(0, 1 * NS_PER_MSEC);

        // Move to the next block
        // iv_blocksize doesn't include the sizeof itself. So, add another byte
        // for it.
        data += block->iv_blockSize + sizeof(uint8_t);
        block = reinterpret_cast<firmware_image_block_t const *>(data);
    }

    return errl;
}

errlHndl_t Bpm::updateConfig()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::updateConfig()");
    errlHndl_t errl = nullptr;

    do {

        // Erase Segment D on the BPM via the BSL interface.
        errl = eraseSegment(SEGMENT_D_CODE);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::updateConfig(): "
                      "Failed to erase Segment D.");
            break;
        }

        // Write the updated Segment D buffer to the BPM via the BSL interface.
        errl = writeSegment(iv_segmentD, SEGMENT_D_CODE);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::updateConfig(): "
                      "Failed to write Segment D.");
            break;
        }

        // Erase Segment B on the BPM via the BSL interface.
        errl = eraseSegment(SEGMENT_B_CODE);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::updateConfig(): "
                      "Failed to erase Segment B.");
            break;
        }

        // Write the updated Segment B buffer to the BPM via the BSL interface.
        errl = writeSegment(iv_segmentB, SEGMENT_B_CODE);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::updateConfig(): "
                      "Failed to write Segment B.");
            break;
        }

    } while(0);

    return errl;
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
                longSleep(5);
                break;
            }

            // Sleep for 0.001 second.
            nanosleep(0, 1 * NS_PER_MSEC);

            errl = issueCommand(BPM_LOCAL, BCL_ENTER_BSL_MODE, WRITE);
            if (errl != nullptr)
            {
                break;
            }

            TRACUCOMP(g_trac_bpm, "Bpm::enterBootstrapLoaderMode(): "
                      "Unable to enter BSL Mode, retries remaining %d. "
                      "Sleep for 2 seconds before trying again.",
                      (retry - 1));
            nanosleep(2,0);
            --retry;

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
        longSleep(10);

    } while(0);

    return errl;
}

errlHndl_t Bpm::readViaScapRegister(uint8_t const i_reg, uint8_t & io_data)
{
    TRACUCOMP(g_trac_bpm, ENTER_MRK"Bpm::readViaScapRegister()");
    errlHndl_t errl = nullptr;

    do {

        // Wait for the SCAP_STATUS Busy bit to be zero.
        errl = waitForBusyBit();
        if (errl != nullptr)
        {
            break;
        }

        // Write to SCAP register which register we're attempting to access on
        // the BPM
        errl = nvdimmWriteReg(iv_nvdimm,
                              SCAP_REG,
                              i_reg);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::readViaScapRegister(): "
                      "Failed to set SCAP_REG to register 0x%.2X",
                      i_reg);
            break;
        }

        // Wait for the SCAP_STATUS Busy bit to be zero.
        errl = waitForBusyBit();
        if (errl != nullptr)
        {
            break;
        }

        // Read out the data from the requested register
        errl = nvdimmReadReg(iv_nvdimm,
                             SCAP_DATA,
                             io_data);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "BPM::readViaScapRegister(): "
                     "Failed to read data from SCAP_DATA for register 0x%.2X.",
                     i_reg);
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::writeViaScapRegister(uint8_t const i_reg, uint8_t const i_data)
{
    TRACUCOMP(g_trac_bpm, ENTER_MRK"Bpm::writeViaScapRegister()");
    errlHndl_t errl = nullptr;

    do {

        // Wait for the SCAP_STATUS Busy bit to be zero.
        errl = waitForBusyBit();
        if (errl != nullptr)
        {
            break;
        }

        // Write to SCAP register which register we're attempting to access on
        // the BPM
        errl = nvdimmWriteReg(iv_nvdimm,
                              SCAP_REG,
                              i_reg);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::writeViaScapRegister(): "
                      "Failed to set SCAP_REG to register 0x%.2X",
                      i_reg);
            break;
        }

        // Wait for the SCAP_STATUS Busy bit to be zero.
        errl = waitForBusyBit();
        if (errl != nullptr)
        {
            break;
        }

        // Write the data to the register we're attempting to access on the BPM.
        errl = nvdimmWriteReg(iv_nvdimm,
                              SCAP_DATA,
                              i_data);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "BPM::writeViaScapRegister(): "
                     "Failed to write data 0x%.2X to SCAP_DATA for "
                     "register 0x%.2X.",
                     i_data,
                     i_reg);
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::disableWriteProtection()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::disableWriteProtection()");
    errlHndl_t errl = nullptr;

    do {

        // The following write sequence to the I2C_REG_PROTECT register
        // indirectly removes write protection from registers 0x40-0x7F on
        // page 4.
        for ( size_t i = 0; i < BPM_PASSWORD_LENGTH; ++i)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                  I2C_REG_PROTECT,
                                  BPM_PASSWORD[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::disableWriteProtection(): "
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
            TRACFCOMP(g_trac_bpm, "Bpm::disableWriteProtection(): "
                      "Failed to verify that write protection was removed");
            break;
        }
        const uint8_t WRITE_PROTECT_DISABLED = 0x80;
        if (!(data & WRITE_PROTECT_DISABLED))
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::disableWriteProtection(): "
                      "Failed to disable write protection. I2C_REG_PROTECT");
            //@TODO RTC 212447 Error
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::writeToMagicRegisters(
        uint8_t const (&i_magicValues)[NUM_MAGIC_REGISTERS])
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::writeToMagicRegisters()");
    errlHndl_t errl = nullptr;

    do {
        const uint16_t magic_registers[NUM_MAGIC_REGISTERS] =
            {BPM_MAGIC_REG1, BPM_MAGIC_REG2};

        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmWriteReg(iv_nvdimm,
                                  magic_registers[i],
                                  i_magicValues[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::writeToMagicRegisters(): "
                          "Failed to write the magic values to the magic "
                          "registers");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // Verify the magic values were written
        uint8_t magic_data[NUM_MAGIC_REGISTERS] = {0};
        for (size_t i = 0; i < NUM_MAGIC_REGISTERS; ++i)
        {
            errl = nvdimmReadReg(iv_nvdimm,
                                 magic_registers[i],
                                 magic_data[i]);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::writeToMagicRegisters(): "
                          "Failed to read back magic values to verify that "
                          "they were written.");
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }

        // If either of the magic values stored in magic_data don't match the
        // corresponding expected values in magic_values then an error occurred.
        if (  (magic_data[0] != i_magicValues[0])
           || (magic_data[1] != i_magicValues[1]))
        {
            // @TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::writeToMagicRegisters(): "
                     "Magic values read from BPM didn't match expected values "
                     "BPM_MAGIC_REG1 Expected 0x%.2X Actual 0x%.2X "
                     "BPM_MAGIC_REG2 Expected 0x%.2X Actual 0x%.2X",
                     i_magicValues[0], magic_data[0],
                     i_magicValues[1], magic_data[1]);
            break;
        }

        TRACUCOMP(g_trac_bpm, "Bpm::writeToMagicRegisters(): "
                 "Magic values successfully written to BPM "
                 "BPM_MAGIC_REG1 0x%.2X "
                 "BPM_MAGIC_REG2 0x%.2X ",
                 magic_data[0],
                 magic_data[1]);

    } while(0);

    return errl;
}

errlHndl_t Bpm::dumpSegment(uint16_t const i_segmentCode,
                            uint8_t  (&o_buffer)[SEGMENT_SIZE])
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::dumpSegment(): Segment %X",
              getSegmentIdentifier(i_segmentCode));
    errlHndl_t errl = nullptr;

    memset(&o_buffer, 0, SEGMENT_SIZE);

    const uint8_t SPECIAL_CONTROL_COMMAND1 = 0x3E;
    const uint8_t SPECIAL_CONTROL_COMMAND2 = 0x3F;

    bool isSegmentPageOpen = false, magicValuesChanged = false;

    do {
        // We cannot be in BSL mode when dumping the config segments. Verify we
        // aren't in BSL mode by checking SCAP_STATUS
        scap_status_register_t status;
        errl = nvdimmReadReg(iv_nvdimm,
                             SCAP_STATUS,
                             status.full);
        if (errl != nullptr)
        {
            break;
        }

        if (status.bit.Bpm_Bsl_Mode)
        {
            //@TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::dumpSegment(): "
                     "Couldn't dump Segment %X. BSL Mode is enabled.",
                     getSegmentIdentifier(i_segmentCode));
            break;
        }

        // First the NVDIMM MAGIC registers BPM_MAGIC_REG1 and BPM_MAGIC_REG2
        // must be programmed to 0xBA and 0xAB respectively.
        const uint8_t magic_values[NUM_MAGIC_REGISTERS] = {0xBA, 0xAB};
        errl = writeToMagicRegisters(magic_values);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                      "Failed to write magic numbers that enable "
                      "reading of segment data.");
            break;
        }

        // Magic values were changed. Need to write back production values.
        magicValuesChanged = true;

        // Next, switch to the desired BPM segment by writing the segment code
        // to the BPM's Special Control Command registers.
        //
        // Since the SCAP_DATA register can only hold 1 byte at a time we must
        // do this in two steps.
        // According to SMART, the segment code must be written in the following
        // form to those registers:
        // Register 0x3E gets LO(i_segmentCode) byte
        // Register 0x3F gets HI(i_segmentCode) byte
        // Example: 0x9D5E is the segment code for Segment D. It must be written
        //          as follows
        // 0x3E, 0x5E
        // 0x3F, 0x9D
        const uint8_t loSegCode = i_segmentCode & 0xFF;
        const uint8_t hiSegCode = (i_segmentCode >> 8) & 0xFF;

        TRACUCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                 "Writing 0x%.2X to SPECIAL_CONTROL_COMMAND1 and "
                 "0x%.2X to SPECIAL_CONTROL_COMMAND2",
                 loSegCode,
                 hiSegCode);

        // Write the LO segment code first.
        errl = writeViaScapRegister(SPECIAL_CONTROL_COMMAND1, loSegCode);
        if (errl != nullptr)
        {
            break;
        }

        // Write the HI segment code next.
        errl = writeViaScapRegister(SPECIAL_CONTROL_COMMAND2, hiSegCode);
        if (errl != nullptr)
        {
            break;
        }

        // Request to open segment page is sent.
        // Wait 2 seconds for the operation to complete.
        nanosleep(2,0);
        isSegmentPageOpen = true;

        TRACFCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                 "Dumping Segment %X to buffer.",
                 getSegmentIdentifier(i_segmentCode));

        // Dump the segment data
        for (uint8_t reg = 0; reg < SEGMENT_SIZE; ++reg)
        {
            errl = readViaScapRegister(reg, o_buffer[reg]);
            if (errl != nullptr)
            {
                break;
            }
        }
        if (errl != nullptr)
        {
            break;
        }


    } while(0);

    do {
        errlHndl_t closeSegmentErrl = nullptr;
        if (isSegmentPageOpen)
        {
            // Close the segment by writing the DEFAULT_REG_PAGE code to the
            // BPM's SPECIAL_CONTROL_COMMAND registers.
            // This must also be done as described above
            const uint8_t lo = DEFAULT_REG_PAGE & 0xFF;
            const uint8_t hi = (DEFAULT_REG_PAGE >> 8) & 0xFF;

            TRACFCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                     "Closing Segment %X's page.",
                     getSegmentIdentifier(i_segmentCode));
            TRACUCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                     "Writing 0x%.2X to SPECIAL_CONTROL_COMMAND1 and "
                     "0x%.2X to SPECIAL_CONTROL_COMMAND2",
                     lo,
                     hi);

            // Write the LO segment code first.
            closeSegmentErrl = writeViaScapRegister(SPECIAL_CONTROL_COMMAND1,
                                                    lo);
            if (closeSegmentErrl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::dumpSegment(): "
                         "Failed to write DEFAULT_REG_PAGE low byte!! "
                         "NVDIMM will be stuck on this segment's page!!");
                // @TODO RTC 212447 Do something with the error.
                break;
            }

            // Write the HI segment code next.
            closeSegmentErrl = writeViaScapRegister(SPECIAL_CONTROL_COMMAND2,
                                                    hi);
            if (closeSegmentErrl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::dumpSegment(): "
                         "Failed to write DEFAULT_REG_PAGE high byte!! "
                         "NVDIMM will be stuck on this segment's page!!");
                // @TODO RTC 212447 Do something with the error.
                break;
            }

            // Sleep for 2 seconds to allow time for segment page to close.
            nanosleep(2, 0);
        }
    } while(0);

    if (magicValuesChanged)
    {
        // Write back the production magic values.
        errlHndl_t magicErrl = writeToMagicRegisters(PRODUCTION_MAGIC_VALUES);
        if (magicErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                      "Failed to write production magic numbers.");
            // @TODO RTC 212447 Do something with the error.
        }
    }

    return errl;
}

errlHndl_t Bpm::mergeSegment(BpmConfigLidImage const i_configImage,
                             uint16_t const i_segmentCode,
                             uint8_t (&o_buffer)[SEGMENT_SIZE])
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::mergeSegment(): Segment %X",
              getSegmentIdentifier(i_segmentCode));
    errlHndl_t errl = nullptr;

    size_t segmentStartOffset = 0;
    auto it = segmentMap.find(i_segmentCode);
    if (it != segmentMap.end())
    {
        segmentStartOffset = it->second;
    }
    else
    {
        //@TODO RTC 212447 Error
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::mergeSegment(): "
                 "Couldn't find start offset for Segment %X",
                 getSegmentIdentifier(i_segmentCode));
    }

    TRACFCOMP(g_trac_bpm, "Bpm::mergeSegment(): "
             "Segment %X Start offset: 0x%X",
             getSegmentIdentifier(i_segmentCode),
             segmentStartOffset);

    memset(&o_buffer, 0, SEGMENT_SIZE);

    do {

        // Dump the segment into a buffer.
        errl = dumpSegment(i_segmentCode, o_buffer);
        if (errl != nullptr)
        {
            break;
        }

        const size_t NUMBER_OF_FRAGMENTS = i_configImage.getNumberOfFragments();
        char const * data = reinterpret_cast<char const *>(
                i_configImage.getFirstFragment());

        config_image_fragment_t const * fragment =
            reinterpret_cast<config_image_fragment_t const *>(data);

        TRACUCOMP(g_trac_bpm, "mergeSegment(): "
                 "NUMBER_OF_FRAGMENTS = 0x%.4X", NUMBER_OF_FRAGMENTS);

        for(size_t i = 0; i < NUMBER_OF_FRAGMENTS; ++i)
        {
            // The fragment offsets are given as offsets within the
            // configuration segment data. So, if the fragment offset is less
            // than the starting offset of this segment then the fragment is not
            // relevant to this segment.
            if (fragment->iv_offset < segmentStartOffset)
            {
                // This fragment is not for the segment we are dealing with.
                TRACUCOMP(g_trac_bpm, "mergeSegment(): "
                         "Fragment with offset 0x%.4X not related to "
                         "Segment %X, skipping",
                         fragment->iv_offset,
                         getSegmentIdentifier(i_segmentCode));

                // Move to the next fragment
                data += sizeof(config_image_fragment_t)
                      + fragment->iv_fragmentSize;
                fragment =
                    reinterpret_cast<config_image_fragment_t const *>(data);
                continue;
            }
            // Each segment is 128 bytes in size. So, if the offset given for
            // the fragment is greater than the upper boundry then no more
            // fragments exist for this segment.
            if (fragment->iv_offset >= segmentStartOffset + SEGMENT_SIZE)
            {
                // This fragment and all other fragments afterward are not for
                // this segment.
                TRACUCOMP(g_trac_bpm, "mergeSegment(): "
                         "Fragment with offset 0x%.4X greater than/equal to "
                         "Segment %X ending offset, skipping",
                         fragment->iv_offset,
                         getSegmentIdentifier(i_segmentCode));
                break;
            }

            // The fragment offset may be out of bounds for the buffer so
            // scale it down to be within the buffer size.
            size_t offset = fragment->iv_offset % SEGMENT_SIZE;

            // Overwrite the BPM segment data at the offset specified by the
            // fragment.
            memcpy(&o_buffer[offset],
                   &(fragment->iv_data),
                   fragment->iv_fragmentSize);

            // Move to the next fragment
            data += sizeof(config_image_fragment_t) + fragment->iv_fragmentSize;
            fragment = reinterpret_cast<config_image_fragment_t const *>(data);
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::eraseSegment(uint16_t i_segmentCode)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::eraseSegment(): Segment %X",
              getSegmentIdentifier(i_segmentCode));
    errlHndl_t errl = nullptr;

    do {

        payload_t payload;
        errl = setupPayload(payload, BSL_ERASE_SEGMENT, i_segmentCode);
        if (errl != nullptr)
        {
            break;
        }

        errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        // Wait 1 second for the operation to complete.
        TRACFCOMP(g_trac_bpm, "Bpm::eraseSegment(): "
                  "Erasing Segment %X. "
                  "Waiting 1 second for operation to complete.",
                  getSegmentIdentifier(i_segmentCode));
        nanosleep(1,0);

    } while(0);

    return errl;
}

errlHndl_t Bpm::writeSegment(uint8_t const (&i_buffer)[SEGMENT_SIZE],
                             uint16_t const i_segmentCode)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::writeSegment(): Segment %X",
              getSegmentIdentifier(i_segmentCode));
    errlHndl_t errl = nullptr;

    do {

        auto it = segmentMap.find(i_segmentCode);
        size_t segmentStartOffset = 0;
        if (it != segmentMap.end())
        {
            segmentStartOffset = it->second;
        }

        // To update the given segment, we have to send over the data as
        // payloads. Since the max size of a payload's data is 16 bytes, there
        // will be 8 payloads sent to update a given segment because each
        // segment is 128 bytes.
        for (size_t offset = 0;
             offset < SEGMENT_SIZE;
             offset += MAX_PAYLOAD_DATA_SIZE)
        {
            // Construct a payload for the data at this offset up to the
            // MAX_PAYLOAD_DATA_SIZE.
            payload_t payload;
            // Each segment is 128 bytes and the segment start addresses
            // are their relative position to BPM_CONFIG_START_ADDRESS. To
            // arrive at the correct address offset for this data we must
            // calculate the addressOffset in the following way.
            uint16_t addressOffset = BPM_CONFIG_START_ADDRESS
                                   + segmentStartOffset
                                   + offset;
            errl = setupPayload(payload,
                                BSL_RX_DATA_BLOCK,
                                addressOffset,
                                &i_buffer[offset],
                                MAX_PAYLOAD_DATA_SIZE);

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

            // Sleep for 0.001 second.
            nanosleep(0, 1 * NS_PER_MSEC);
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::preprocessSegments(BpmConfigLidImage const i_configImage)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::preprocessSegments()");
    errlHndl_t errl = nullptr;

    do {

        if (iv_attemptAnotherUpdate && iv_segmentDMerged && iv_segmentBMerged)
        {
            // The segment data has already been merged with the flash image
            // data. Doing it again has the potential to fail depending on where
            // the last update attempt failed.
            TRACFCOMP(g_trac_bpm, "Bpm::preprocessSegments(): "
                      "Segment data was merged in a previous update attempt, "
                      "skipping preprocessing and using existing data.");
            break;
        }

        // Disable write protection on the BPM. Otherwise, we can't write the
        // magic values that will enable segment preprocessing.
        errl = disableWriteProtection();
        if (errl != nullptr)
        {
            break;
        }

        // Merge the fragments for D with the data from the BPM.
        if (!iv_segmentDMerged)
        {
            errl = mergeSegment(i_configImage, SEGMENT_D_CODE, iv_segmentD);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::preprocessSegments(): "
                          "Failed to merge Segment D.");
                break;
            }
            iv_segmentDMerged = true;
        }
        else
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::preprocessSegments(): "
                     "Segment %X has been merged already. Skipping merge...",
                     getSegmentIdentifier(SEGMENT_D_CODE));
        }

        // Merge the fragments for B with the data from the BPM.
        if (!iv_segmentBMerged)
        {
            errl = mergeSegment(i_configImage, SEGMENT_B_CODE, iv_segmentB);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::preprocessSegments(): "
                          "Failed to merge Segment B.");
                break;
            }
            iv_segmentBMerged = true;
        }
        else
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::preprocessSegments(): "
                     "Segment %X has been merged already. Skipping merge...",
                     getSegmentIdentifier(SEGMENT_B_CODE));
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::getResponse(uint8_t * const o_responseData,
                            uint8_t   const i_responseSize)
{
    TRACUCOMP(g_trac_bpm, ENTER_MRK"Bpm::getResponse()");

    errlHndl_t errl = nullptr;
    memset(o_responseData, 0xFF, i_responseSize);

    do {

        // Get the result from the BPM.
        // First clear the error status register
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_ERR_STATUS,
                              0x00);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::getResponse(): "
                      "Failed to clear error status register");
            break;
        }

        // Set the payload length
        // The 4 header bytes plus 2 CRC bytes make up the other data size in
        // the response payload.
        const uint8_t RESPONSE_PAYLOAD_OTHER_DATA_SIZE = 6;
        uint8_t responsePayloadSize = RESPONSE_PAYLOAD_OTHER_DATA_SIZE
                                    + i_responseSize;

        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_PAYLOAD_LENGTH,
                              responsePayloadSize);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::getResponse(): "
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
            TRACFCOMP(g_trac_bpm, "Bpm::getResponse(): "
                      "Failed to setup command status register");
            break;
        }

        // Setup command type.
        errl = nvdimmWriteReg(iv_nvdimm,
                              BPM_REG_CMD,
                              BPM_PASSTHROUGH);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::getResponse(): "
                      "Failed to setup command type.");
            break;
        }

        errl = waitForCommandStatusBitReset(commandStatus);
        if (errl != nullptr)
        {
            break;
        }

        // Read out the response payload.
        payload_t responsePayload;

        for (size_t i = 0; i < responsePayloadSize; ++i)
        {
            uint8_t data = 0;
            errl = nvdimmReadReg(iv_nvdimm,
                                (BPM_REG_PAYLOAD_START + (i * sizeof(uint8_t))),
                                data);
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::getResponse(): "
                          "Failed to read response payload");
                break;
            }

            responsePayload.push_back(data);
        }
        if (errl != nullptr)
        {
            break;
        }

        // Verify the data from the response was good.
        uint8_t* responseIterator = responsePayload.data();
        uint16_t responseCrc = *(reinterpret_cast<uint16_t *>
                (&responseIterator[PAYLOAD_HEADER_SIZE + i_responseSize]));
        // The BPM is going to give the response CRC in LE. So convert it to BE.
        responseCrc = le16toh(responseCrc);
        uint16_t expectedCrc = crc16_calc(responseIterator,
                                          PAYLOAD_HEADER_SIZE + i_responseSize);
        if (responseCrc != expectedCrc)
        {
            // @TODO RTC 212447: Error, invalid data read from BPM.
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::getResponse(): "
                      "Response CRC verification failed. "
                      "Received invalid data from BPM.");
            break;
        }

        // Write the data to the output buffer
        for (size_t i = 0; i < i_responseSize; ++i)
        {
            // Only copy the response data from the payload to the output buffer
            o_responseData[i] = responsePayload[i + PAYLOAD_HEADER_SIZE];
        }

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

errlHndl_t Bpm::waitForBusyBit()
{
    errlHndl_t errl = nullptr;
    int retry = 10;
    scap_status_register_t status;

    while (retry > 0)
    {

        errl = nvdimmReadReg(iv_nvdimm,
                             SCAP_STATUS,
                             status.full);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::waitForBusyBit(): "
                      "Failed to read from SCAP_STATUS to determine "
                      "state of Busy bit.");
            break;
        }

        if (!status.bit.Busy)
        {
            // SCAP Register is no longer busy. Stop retries.
            break;
        }

        if (retry <= 0)
        {
            //@TODO RTC 212447 Error
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::waitForBusyBit(): "
                      "SCAP_STATUS Busy bit failed to reset to 0 "
                      "in 10 retries.");
            break;
        }

        --retry;
        nanosleep(0, 2 * NS_PER_MSEC);
    }

    return errl;
}

errlHndl_t Bpm::checkFirmwareCrc()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::checkFirmwareCrc()");
    errlHndl_t errl = nullptr;

    // The COMMAND_CRC_CHECK would return a 3 byte response in the following
    // format:
    //
    //  ========================================================================
    //          [Status Code]         [Computed_CRC_Lo] [Computed_CRC_Hi]
    //  ========================================================================
    //  BSL_LOCKED                          0x00             0x00
    //  PARAMETER_ERROR                     0x00             0x00
    //  MAIN_FW_NOT_SUPPORT_CRC_CHECK       0x00             0x00
    //  MEMORY_WRITE_CHECK_FAILED           CRC_Low          CRC_Hi
    //  WRITE_FORBIDDEN                     CRC_Low          CRC_Hi
    //  VERIFY_MISMATCH                     CRC_Low          CRC_Hi
    //  SUCCESSFUL_OPERATION                CRC_Low          CRC_Hi
    //
    //  For status codes BSL_LOCKED, PARAMETER_ERROR, and
    //  MAIN_FW_NOT_SUPPORT_CRC_CHECK the response CRC values are considered
    //  as DONT CARE.
    //
    //  For the remainder of the status codes the CRC values are the
    //  computed CRC of the image.
    //
    //  For SUCCESSFUL_OPERATION, the RESET_VECTOR was written.
    //  See bpm_update.H for more info on the status codes
    const uint8_t CRC_CHECK_RESPONSE_SIZE = 3;
    uint8_t responseData[CRC_CHECK_RESPONSE_SIZE] = {0};

    do {

         TRACFCOMP(g_trac_bpm, "Bpm::checkFirmwareCrc(): "
                  "Performing final CRC check.");
         payload_t crcPayload;
         errl = setupPayload(crcPayload,
                             BSL_CRC_CHECK,
                             iv_firmwareStartAddress);
         if (errl != nullptr)
         {
             break;
         }

         errl = issueCommand(BPM_PASSTHROUGH, crcPayload, WRITE);
         if (errl != nullptr)
         {
             break;
         }

        // Wait 10 seconds for the CRC check to complete.
         TRACFCOMP(g_trac_bpm, "Bpm::checkFirmwareCrc(): "
                  "Allow CRC check to complete on BPM by waiting 10 seconds.");
        longSleep(10);

        errl = getResponse(responseData, CRC_CHECK_RESPONSE_SIZE);
        if (errl != nullptr)
        {
            break;
        }

        TRACFCOMP(g_trac_bpm, "Bpm::checkFirmwareCrc(): "
                  "CRC check status = 0x%.X, CRC_Low = 0x%.X, CRC_Hi = 0x%.X",
                  responseData[0],
                  responseData[1],
                  responseData[2]);

        if (responseData[0] != SUCCESSFUL_OPERATION)
        {
            // @TODO RTC 212447 Error
            break;
        }

    } while(0);

    if (errl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::checkFirmwareCrc(): "
                  "Error occurred during BPM Firmware CRC check. "
                  "Firmware image will not load on BPM and update must be "
                  "attempted again.");
    }

    return errl;
}

uint16_t Bpm::crc16_calc(const void* i_ptr, int i_size)
{
    uint16_t crc = 0xFFFF;
    const uint8_t* data = reinterpret_cast<const uint8_t*>(i_ptr);

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
