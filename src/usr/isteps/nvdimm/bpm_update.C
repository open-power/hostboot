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
#include <errl/errlmanager.H>
#include <endian.h>
#include <sys/time.h>
#include <hbotcompid.H>
#include <trace/interface.H>
#include <initservice/istepdispatcherif.H>
#include <isteps/nvdimm/bpmreasoncodes.H>

#include <targeting/common/targetservice.H>
#include <attributeenums.H>

namespace NVDIMM
{
namespace BPM
{

trace_desc_t* g_trac_bpm = nullptr;
TRAC_INIT(&g_trac_bpm, BPM_COMP_NAME, 4*KILOBYTE);

// For debug traces
#define TRACUCOMP(args...)
//#define TRACUCOMP(args...) TRACFCOMP(args)

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
// These magic values to enable nvdimm-bpm interface. They must be written to
// the magic registers BEFORE writing flash updates to the BPM in BSL mode.
const uint8_t UPDATE_MODE_MAGIC_VALUES[NUM_MAGIC_REGISTERS] = {0xB0, 0xDA};

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

const size_t MAX_RETRY = 3;

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
 *  @brief Helper function to handle two potential errors that might occur in a
 *         function that only returns a single error log. If the return error is
 *         not nullptr then the second error will be linked to it and committed.
 *         Otherwise, the return error will point to the second's error and the
 *         second error will point to nullptr.
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
void handleMultipleErrors(errlHndl_t& io_returnErrl, errlHndl_t& io_secondErrl)
{
    if (io_returnErrl != nullptr)
    {
        io_secondErrl->plid(io_returnErrl->plid());
        TRACFCOMP(g_trac_bpm, "Committing second error eid=0x%X with plid of "
                 "returned error: 0x%X",
                 io_secondErrl->eid(),
                 io_returnErrl->plid());
        io_secondErrl->collectTrace(BPM_COMP_NAME);
        ERRORLOG::errlCommit(io_secondErrl, BPM_COMP_ID);
    }
    else
    {
        io_returnErrl = io_secondErrl;
        io_secondErrl = nullptr;
    }


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

void runBpmUpdates(bpmList_t           * const i_16gb_BPMs,
                   bpmList_t           * const i_32gb_BPMs,
                   BpmFirmwareLidImage * const i_16gb_fwImage,
                   BpmFirmwareLidImage * const i_32gb_fwImage,
                   BpmConfigLidImage   * const i_16gb_configImage,
                   BpmConfigLidImage   * const i_32gb_configImage)
{

    assert(   (i_16gb_BPMs == nullptr)
           ||  i_16gb_BPMs->empty()
           || ((i_16gb_fwImage != nullptr) && (i_16gb_configImage != nullptr)),
           "BPM::runBpmUpdates(): Update images for 16gb BPMs was nullptr and "
           "there are 16gb BPMs in the system to may require updates.");
    assert(   (i_32gb_BPMs == nullptr)
           ||  i_32gb_BPMs->empty()
           || ((i_32gb_fwImage != nullptr) && (i_32gb_configImage != nullptr)),
           "BPM::runBpmUpdates(): Update images for 32gb BPMs was nullptr and "
           "there are 32gb BPMs in the system to may require updates.");

    errlHndl_t errl = nullptr;

    do {
        // @TODO RTC 212448 Enable updates once everything works
        break;

        if (   (i_16gb_BPMs != nullptr)
            && (i_16gb_fwImage != nullptr)
            && (i_16gb_configImage != nullptr))
        {
            TRACFCOMP(g_trac_bpm,
                     "Check/update %d BPMs on 16GB_TYPE NVDIMMs",
                     i_16gb_BPMs->size());

            for(auto& bpm : *i_16gb_BPMs)
            {
                errl = bpm.runUpdate(*i_16gb_fwImage, *i_16gb_configImage);
                if (errl != nullptr)
                {
                    uint32_t nvdimmHuid = TARGETING::get_huid(bpm.getNvdimm());
                    if (bpm.attemptAnotherUpdate())
                    {
                        TRACFCOMP(g_trac_bpm, ERR_MRK
                                 "An error occurred during a 16GB_TYPE BPM "
                                 "update for NVDIMM 0x%.8X. "
                                 "Commit and try again.",
                                 nvdimmHuid);
                        ERRORLOG::errlCommit(errl, BPM_COMP_ID);

                        errl = bpm.runUpdate(*i_16gb_fwImage,
                                             *i_16gb_configImage);
                        if (errl != nullptr)
                        {
                            TRACFCOMP(g_trac_bpm, ERR_MRK
                                     "Another error occurred while attempting "
                                     "to update the same 16GB_TYPE BPM for "
                                     "NVDIMM 0x%.8X. Commit and move onto the "
                                     "next BPM",
                                     nvdimmHuid);
                        }
                    }
                    else
                    {
                        TRACFCOMP(g_trac_bpm, ERR_MRK
                                 "An error occurred during a 16GB_TYPE BPM "
                                 "update for NVDIMM 0x%.8X. "
                                 "Commit and move onto the next BPM",
                                 nvdimmHuid);
                    }
                    ERRORLOG::errlCommit(errl, BPM_COMP_ID);
                }
            }
        }

        if (  (i_32gb_BPMs != nullptr)
           && (i_32gb_fwImage != nullptr)
           && (i_32gb_configImage != nullptr))
        {
            TRACFCOMP(g_trac_bpm,
                     "Check/update %d BPMs on 32GB_TYPE NVDIMMs",
                     i_32gb_BPMs->size());

            for(auto& bpm : *i_32gb_BPMs)
            {
                errl = bpm.runUpdate(*i_32gb_fwImage, *i_32gb_configImage);
                if (errl != nullptr)
                {
                    uint32_t nvdimmHuid = TARGETING::get_huid(bpm.getNvdimm());
                    if (bpm.attemptAnotherUpdate())
                    {
                        TRACFCOMP(g_trac_bpm, ERR_MRK
                                 "An error occurred during a 32GB_TYPE BPM "
                                 "update for NVDIMM 0x%.8X. "
                                 "Commit and try again.",
                                 nvdimmHuid);
                        ERRORLOG::errlCommit(errl, BPM_COMP_ID);

                        errl = bpm.runUpdate(*i_32gb_fwImage,
                                             *i_32gb_configImage);
                        if (errl != nullptr)
                        {
                            TRACFCOMP(g_trac_bpm, ERR_MRK
                                     "Another error occurred while attempting "
                                     "to update the same 32GB_TYPE BPM for "
                                     "NVDIMM 0x%.8X. Commit and move onto the "
                                     "next BPM",
                                     nvdimmHuid);
                        }
                    }
                    else
                    {
                        TRACFCOMP(g_trac_bpm, ERR_MRK
                                 "An error occurred during a 32GB_TYPE BPM "
                                 "update for NVDIMM 0x%.8X. "
                                 "Commit and move onto the next BPM",
                                 nvdimmHuid);
                    }
                    ERRORLOG::errlCommit(errl, BPM_COMP_ID);
                }
            }
        }
    } while(0);
}

// =============================================================================
//                      BpmFirmwareLidImage Class Functions
// =============================================================================

BpmFirmwareLidImage::BpmFirmwareLidImage(void * const i_lidImageAddr,
                                         size_t i_size)
    : iv_lidImage(i_lidImageAddr), iv_lidImageSize(i_size)
{
    assert(i_lidImageAddr != nullptr,
          "BPM::BpmFirmwareLidImage(): Provided LID image must not be nullptr");
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
      iv_segmentBMerged(false),
      iv_updateAttempted(false)
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

void Bpm::setAttemptAnotherUpdate()
{

    if (iv_updateAttempted)
    {
        // Since iv_updateAttempted is true that means that this function was
        // called on a subsequent update attempt, meaning we should no longer
        // attempt updates if the current attempt fails.
        iv_attemptAnotherUpdate = false;
    }
    else
    {
        // Since iv_updateAttempted is false that means that this function was
        // called on the first update attempt because by default
        // iv_updateAttempted is false and is only set to true as the last part
        // of the update procedure.
        iv_attemptAnotherUpdate = true;
    }

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
    } while(0);

    do {
        // Reset the device. This will exit BSL mode.
        errlHndl_t exitErrl = resetDevice();
        if (exitErrl != nullptr)
        {
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        // Exit update mode
        exitErrl = exitUpdateMode();
        if (exitErrl != nullptr)
        {
            handleMultipleErrors(errl, exitErrl);
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

        // Check the full payload size to make sure it's not too large. Add the
        // size of the SYNC_BYTE that was dropped during payload creation to
        // verify that the full payload sent by the NVDIMM won't exceed the max
        // size the BPM is able to receive.
        if ((i_payload.size() + SYNC_BYTE_SIZE) > MAX_PAYLOAD_SIZE)
        {
            uint8_t payloadSize = i_payload.size() + SYNC_BYTE_SIZE;
            uint8_t payloadHeaderDataSize =
                i_payload[PAYLOAD_HEADER_DATA_LENGTH_INDEX];
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::issueCommand(): "
                     "payload size %d exceeds max payload size of %d",
                     payloadSize, MAX_PAYLOAD_SIZE);
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_ISSUE_COMMAND
            * @reasoncode       BPM_RC::BPM_INVALID_PAYLOAD_SIZE
            * @userdata1[00:31] Full Payload Size, including SYNC_BYTE
            * @userdata1[32:63] MAX_PAYLOAD_SIZE
            * @userdata2[00:31] Payload Header + Data size
            * @userdata2[32:63] NVDIMM Target HUID associated with this BPM
            * @devdesc          The maximum payload size to be sent to the BPM
            *                   was exceeded.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           BPM_RC::BPM_ISSUE_COMMAND,
                                           BPM_RC::BPM_INVALID_PAYLOAD_SIZE,
                                           TWO_UINT16_TO_UINT32(payloadSize,
                                                    MAX_PAYLOAD_SIZE),
                                           TWO_UINT32_TO_UINT64(
                                               payloadHeaderDataSize,
                                               TARGETING::get_huid(iv_nvdimm))
                                           );
            errl->collectTrace(BPM_COMP_NAME);
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

        // Set the payload length. This is the actual length of the payload
        // excluding the size of the SYNC_BYTE that was dropped during payload
        // creation which is already missing from size().
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

        // Get the sys target to check for attribute overrides.
        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);

        auto updateOverride =
            sys->getAttr<TARGETING::ATTR_BPM_UPDATE_OVERRIDE>();

        // Determine if updates are necessary and save that decision to
        // influence attribute override behavior.
        bool shouldPerformUpdate = true;

        TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                  "Firmware version on the BPM 0x%.4X, "
                  "Firmware version of image 0x%.4X.",
                  bpmFwVersion, i_fwImage.getVersion());

        if (i_fwImage.getVersion() == bpmFwVersion)
        {
            shouldPerformUpdate = false;
            if (updateOverride == TARGETING::BPM_UPDATE_BEHAVIOR_DEFAULT_ALL)
            {
                TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                         "Firmware version on the BPM matches the version in "
                         "the image. Skipping update.");
                break;
            }
        }

        if (updateOverride == TARGETING::BPM_UPDATE_BEHAVIOR_SKIP_ALL)
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                     "ATTR_BPM_UPDATE_OVERRIDE set to SKIP_ALL. "
                     "Skipping update.");
            break;
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
                      "Cancelling Update.");

            break;
        }

        uint16_t configOverrideFlag = (updateOverride & 0x00FF);
        if ((shouldPerformUpdate
                || (configOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_FORCE_CONFIG))
           && !(configOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_SKIP_CONFIG))
        {
            if (configOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_FORCE_CONFIG)
            {
                TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                         "ATTR_BPM_UPDATE_OVERRIDE set to force config "
                         "portion of BPM updates. Running Config Update...");
            }
            errl = runConfigUpdates(i_configImage);
            if (errl != nullptr)
            {
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                     "ATTR_BPM_UPDATE_OVERRIDE set to skip config "
                     "portion of BPM updates. Skipping Config Update...");
        }

        uint16_t firmwareOverrideFlag = (updateOverride & 0xFF00);
        if ((shouldPerformUpdate
                || (firmwareOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_FORCE_FW))
           && !(firmwareOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_SKIP_FW))
        {
            if (firmwareOverrideFlag == TARGETING::BPM_UPDATE_BEHAVIOR_FORCE_FW)
            {
                TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                         "ATTR_BPM_UPDATE_OVERRIDE set to force firmware "
                         "portion of BPM updates. Running Firmware Update...");
            }

            errl = runFirmwareUpdates(i_fwImage);
            if (errl != nullptr)
            {
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runUpdate(): "
                     "ATTR_BPM_UPDATE_OVERRIDE set to skip firmware "
                     "portion of BPM updates. Skipping Firmware Update...");
        }

    } while(0);

    TRACFCOMP(g_trac_bpm, EXIT_MRK"Bpm::runUpdate(): "
              "Concluding BPM Update for NVDIMM 0x%.8X %s",
              TARGETING::get_huid(iv_nvdimm),
              (errl != nullptr) ? "with errors" : "without errors");

    // An update has been attempted at least once. Set member variable to true
    // to dictate future update attempts. This variable should only be set at
    // the end of the update procedure in order to properly control future
    // update attempts.
    iv_updateAttempted = true;

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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::inUpdateMode(): "
                     "Failed to enter update mode");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_IN_UPDATE_MODE
            * @reasoncode       BPM_RC::BPM_UPDATE_MODE_VERIFICATION_FAIL
            * @userdata1        NVDIMM Target HUID associated with this BPM
            * @devdesc          Failed to verify update mode was entered using
            *                   the BSL interface.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                     BPM_RC::BPM_IN_UPDATE_MODE,
                                     BPM_RC::BPM_UPDATE_MODE_VERIFICATION_FAIL,
                                     TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
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
        errl = writeToMagicRegisters(UPDATE_MODE_MAGIC_VALUES);
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

        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
        * @moduleid         BPM_RC::BPM_START_UPDATE
        * @reasoncode       BPM_RC::BPM_ENTER_UPDATE_MODE
        * @userdata1        NVDIMM Target HUID associated with this BPM
        * @devdesc          BPM has entered update mode.
        * @custdesc         Informational log associated with DIMM updates.
        */
        errlHndl_t infoErrl = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            BPM_RC::BPM_START_UPDATE,
                                            BPM_RC::BPM_ENTER_UPDATE_MODE,
                                            TARGETING::get_huid(iv_nvdimm));
        infoErrl->collectTrace(BPM_COMP_NAME);
        ERRORLOG::errlCommit(infoErrl, BPM_COMP_ID);

    } while(0);

    return errl;
}

errlHndl_t Bpm::exitUpdateMode()
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::exitUpdateMode()");
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

        if (isUpdateInProgress)
        {
            errl = issueCommand(BPM_LOCAL, BCL_END_UPDATE, WRITE);
            if (errl != nullptr)
            {
                break;
            }
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

        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
        * @moduleid         BPM_RC::BPM_END_UPDATE
        * @reasoncode       BPM_RC::BPM_EXIT_UPDATE_MODE
        * @userdata1        NVDIMM Target HUID associated with this BPM
        * @devdesc          BPM has exited update mode.
        * @custdesc         Informational log associated with DIMM updates.
        */
        errlHndl_t infoErrl = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            BPM_RC::BPM_END_UPDATE,
                                            BPM_RC::BPM_EXIT_UPDATE_MODE);
        infoErrl->collectTrace(BPM_COMP_NAME);
        ERRORLOG::errlCommit(infoErrl, BPM_COMP_ID);

    } while(0);

    return errl;
}

errlHndl_t Bpm::updateFirmware(BpmFirmwareLidImage i_image)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::updateFirmware()");
    errlHndl_t errl = nullptr;

    // There are two potential start addresses for the firmware section.
    // They are:
    const uint16_t MAIN_PROGRAM_ADDRESS     = 0x8000;
    const uint16_t MAIN_PROGRAM_ADDRESS_ALT = 0xA000;

    // The reset vector address is near the end of the firmware section.
    // We must do a special operation on it when it shows up during the update.
    const uint16_t RESET_VECTOR_ADDRESS     = 0xFFFE;

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
                      "Performing BSL_MASS_ERASE on BPM, sleep for 5 seconds.",
                      iv_firmwareStartAddress);
            longSleep(5);

            TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                     "Begin writing flash image to BPM "
                     "with a starting address of 0x%.4X",
                     iv_firmwareStartAddress);

        }

        if (block->iv_addressOffset % 0x400 == 0)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                     "Writing to address offset 0x%.4X. "
                     "Firmware blocks written: %d; Remaining: %d",
                     block->iv_addressOffset,
                     i, NUMBER_OF_BLOCKS);
        }

        // Construct the payload for this block in the image
        payload_t payload;
        errl = setupPayload(payload, block, BSL_RX_DATA_BLOCK);
        if (errl != nullptr)
        {
            break;
        }

        if (block->iv_addressOffset == RESET_VECTOR_ADDRESS)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                     "Encountered RESET_VECTOR_ADDRESS 0x%.4X. "
                     "Attempt to write RESET_VECTOR to BPM up to %d times.",
                     RESET_VECTOR_ADDRESS,
                     MAX_RETRY);
            // Attempting to BSL_VERIFY_BLOCK on the reset vector data will
            // fail. To verify that this data is written correctly we will check
            // the response packet sent by the BPM.
            const uint8_t RESET_VECTOR_RECEIVE_SUCCESS = 0x80;
            uint8_t retry = 1;
            do
            {
                // Issue the write command to the BPM.
                errl = issueCommand(BPM_PASSTHROUGH, payload, WRITE);
                if (errl != nullptr)
                {
                    break;
                }

                // Get the response packet and verify that the status is
                // RESET_VECTOR_RECEIVE_SUCCESS.
                //
                // Any status besides RESET_VECTOR_RECEIVE_SUCCESS is considered
                // a fail. So, assume a failure and check.
                uint8_t status = 0xFF;
                errl = getResponse(&status,
                                   sizeof(uint8_t));
                if (errl != nullptr)
                {
                    break;
                }

                if (status != RESET_VECTOR_RECEIVE_SUCCESS)
                {
                    TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                             "status %d from BPM was not "
                             "RESET_VECTOR_RECEIVE_SUCCESS value of %d. "
                             "Retrying...",
                             status,
                             RESET_VECTOR_RECEIVE_SUCCESS);

                    if (++retry > MAX_RETRY)
                    {
                        TRACFCOMP(g_trac_bpm, "Bpm::updateFirmware(): "
                                  "Never received RESET_VECTOR_RECEIVE_SUCCESS "
                                  "status from BPM in three attempts. "
                                  "Aborting Update");
                        /*@
                        * @errortype
                        * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
                        * @moduleid         BPM_RC::BPM_UPDATE_FIRMWARE
                        * @reasoncode       BPM_RC::BPM_RESET_VECTOR_NEVER_RECEIVED
                        * @userdata1        NVDIMM Target HUID associated with this BPM
                        * @devdesc          RESET_VECTOR_RECEIVE_SUCCESS status was not
                        *                   received in three attempts.
                        * @custdesc         A problem occurred during IPL of the system.
                        */
                        errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                                        BPM_RC::BPM_UPDATE_FIRMWARE,
                                        BPM_RC::BPM_RESET_VECTOR_NEVER_RECEIVED,
                                        TARGETING::get_huid(iv_nvdimm));
                        errl->collectTrace(BPM_COMP_NAME);

                        // Change the state of iv_attemptAnotherUpdate to signal
                        // if another update attempt should occur.
                        setAttemptAnotherUpdate();

                        break;
                    }
                }
                else
                {
                    // RESET_VECTOR was written and received successfully.
                    // Exit retry loop.
                    break;
                }

                // Sleep for 0.001 second before attempting again.
                nanosleep(0, 1 * NS_PER_MSEC);

            } while(retry <= MAX_RETRY);
            if (errl != nullptr)
            {
                break;
            }
        }
        else
        {
            // Attempt to write the data using a retry loop. This will also
            // verify that the data was correctly written to the BPM.
            errl = blockWrite(payload);
            if (errl != nullptr)
            {
                break;
            }
        }

        // Move to the next block
        // iv_blocksize doesn't include the sizeof itself. So, add another byte
        // for it.
        data += block->iv_blockSize + sizeof(uint8_t);
        block = reinterpret_cast<firmware_image_block_t const *>(data);
    }

    TRACFCOMP(g_trac_bpm, EXIT_MRK"Bpm::updateFirmware(): "
             "Firmware flash image write and verification completed "
             "%s",
             (errl == nullptr) ? "without errors" : "with errors");

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
        int retry = 5;
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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::enterBootstrapLoaderMode(): "
                     "Failed to enter BSL mode on the BPM");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_ENTER_BSL_MODE
            * @reasoncode       BPM_RC::BPM_FAILED_TO_ENTER_BSL_MODE
            * @userdata1[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          Failed to enter BSL mode after several attempts.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           BPM_RC::BPM_ENTER_BSL_MODE,
                                           BPM_RC::BPM_FAILED_TO_ENTER_BSL_MODE,
                                           TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
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
        TRACFCOMP(g_trac_bpm, ERR_MRK
                 "Bpm::setupPayload(): Block Data Size %d exceeds max payload "
                 "size of %d",
                 blockDataSize,
                 MAX_PAYLOAD_DATA_SIZE);
        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
        * @moduleid         BPM_RC::BPM_SETUP_PAYLOAD
        * @reasoncode       BPM_RC::BPM_INVALID_PAYLOAD_DATA_SIZE
        * @userdata1[0:7]   Block Data Size
        * @userdata1[8:15]  MAX_PAYLOAD_DATA_SIZE
        * @userdata2[0:63]  NVDIMM Target HUID associated with this BPM
        * @devdesc          Failed to enter BSL mode after several attempts.
        * @custdesc         A problem occurred during IPL of the system.
        */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_SETUP_PAYLOAD,
                                       BPM_RC::BPM_INVALID_PAYLOAD_DATA_SIZE,
                                       TWO_UINT8_TO_UINT16(blockDataSize,
                                           MAX_PAYLOAD_DATA_SIZE),
                                       TARGETING::get_huid(iv_nvdimm));
        errl->collectTrace(BPM_COMP_NAME);
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
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_DISABLE_WRITE_PROTECTION
            * @reasoncode       BPM_RC::BPM_DISABLE_WRITE_PROTECTION_FAILED
            * @userdata1        NVDIMM Target HUID associated with this BPM
            * @devdesc          Failed to enter BSL mode after several attempts.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                 BPM_RC::BPM_DISABLE_WRITE_PROTECTION,
                                 BPM_RC::BPM_DISABLE_WRITE_PROTECTION_FAILED,
                                 TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::writeToMagicRegisters(): "
                     "Magic values read from BPM didn't match expected values "
                     "BPM_MAGIC_REG1 Expected 0x%.2X Actual 0x%.2X "
                     "BPM_MAGIC_REG2 Expected 0x%.2X Actual 0x%.2X",
                     i_magicValues[0], magic_data[0],
                     i_magicValues[1], magic_data[1]);

            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_WRITE_MAGIC_REG
            * @reasoncode       BPM_RC::BPM_WRITE_TO_MAGIC_REG_FAILED
            * @userdata1[0:7]   BPM_MAGIC_REG1 expected value
            * @userdata1[8:15]  BPM_MAGIC_REG1 actual value
            * @userdata1[16:23] BPM_MAGIC_REG2 expected value
            * @userdata1[24:31] BPM_MAGIC_REG2 actual value
            * @userdata2[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          Failed to write values to the magic registers on
            *                   the BPM.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                     BPM_RC::BPM_WRITE_MAGIC_REG,
                                     BPM_RC::BPM_WRITE_TO_MAGIC_REG_FAILED,
                                     TWO_UINT16_TO_UINT32(
                                        TWO_UINT8_TO_UINT16(i_magicValues[0],
                                            magic_data[0]),
                                        TWO_UINT8_TO_UINT16(i_magicValues[1],
                                            magic_data[1])),
                                     TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::dumpSegment(): "
                     "BSL Mode is enabled. Attempting to exit BSL mode.");

            // Try to exit BSL mode. This function will exit BSL.
            errl = resetDevice();
            if (errl != nullptr)
            {
                break;
            }

            // To maintain proper update flow we must exit and re-enter update
            // mode.
            errl = exitUpdateMode();
            if (errl != nullptr)
            {
                break;
            }

            errl = enterUpdateMode();
            if (errl != nullptr)
            {
                break;
            }

            errl = nvdimmReadReg(iv_nvdimm,
                                 SCAP_STATUS,
                                 status.full);
            if (errl != nullptr)
            {
                break;
            }
            if (status.bit.Bpm_Bsl_Mode)
            {
                TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::dumpSegment(): "
                         "Couldn't dump Segment %X. BSL Mode is enabled.",
                         getSegmentIdentifier(i_segmentCode));

                /*@
                * @errortype
                * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
                * @moduleid         BPM_RC::BPM_DUMP_SEGMENT
                * @reasoncode       BPM_RC::BPM_BSL_MODE_ENABLED
                * @userdata1[0:63]  NVDIMM Target HUID associated with this BPM
                * @devdesc          Couldn't dump segment data because BSL mode
                *                   was enabled.
                * @custdesc         A problem occurred during IPL of the system.
                */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               BPM_RC::BPM_DUMP_SEGMENT,
                                               BPM_RC::BPM_BSL_MODE_ENABLED,
                                               TARGETING::get_huid(iv_nvdimm));
                errl->collectTrace(BPM_COMP_NAME);

                break;
            }
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
                handleMultipleErrors(errl, closeSegmentErrl);
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
                handleMultipleErrors(errl, closeSegmentErrl);
                break;
            }

            // Sleep for 2 seconds to allow time for segment page to close.
            nanosleep(2, 0);
        }
    } while(0);

    if (magicValuesChanged)
    {
        // Write back the production magic values.
        errlHndl_t magicErrl = writeToMagicRegisters(UPDATE_MODE_MAGIC_VALUES);
        if (magicErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::dumpSegment(): "
                      "Failed to write update mode magic numbers.");
            handleMultipleErrors(errl, magicErrl);
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
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::mergeSegment(): "
                 "Couldn't find start offset for Segment %X",
                 getSegmentIdentifier(i_segmentCode));
        assert(false, "Add the missing Segment %X Start Offset to the offset map", getSegmentIdentifier(i_segmentCode));
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

    TRACFCOMP(g_trac_bpm, EXIT_MRK"Bpm::eraseSegment(): "
             "Segment %X erase operation completed "
             "%s",
             getSegmentIdentifier(i_segmentCode),
             (errl == nullptr) ? "without errors" : "with errors");

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

            if (addressOffset % 0x20 == 0)
            {
                TRACFCOMP(g_trac_bpm, "Bpm::writeSegment(): "
                         "Writing to address offset 0x%.4X. "
                         "Config bytes written: 0x%X; Remaining: 0x%X",
                         addressOffset,
                         offset, SEGMENT_SIZE);
            }

            // Attempt to write the payload using a retry loop.
            errl = blockWrite(payload);
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

    TRACFCOMP(g_trac_bpm, EXIT_MRK"Bpm::writeSegment(): "
             "Segment %X write and verification completed "
             "%s",
             getSegmentIdentifier(i_segmentCode),
             (errl == nullptr) ? "without errors" : "with errors");

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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::getResponse(): "
                      "Response CRC verification failed. "
                      "Received invalid data from BPM.");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_GET_RESPONSE
            * @reasoncode       BPM_RC::BPM_RESPONSE_CRC_MISMATCH
            * @userdata1[0:15]  Expected Response CRC
            * @userdata1[16:31] Actual Response CRC
            * @userdata2[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          The response CRC calculated by the BPM didn't
            *                   match the CRC calculated by hostboot.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           BPM_RC::BPM_GET_RESPONSE,
                                           BPM_RC::BPM_RESPONSE_CRC_MISMATCH,
                                           TWO_UINT16_TO_UINT32(expectedCrc,
                                               responseCrc),
                                           TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
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

errlHndl_t Bpm::verifyBlockWrite(payload_t  i_payload,
                            uint8_t    i_dataLength,
                            uint8_t  & o_status)
{
    errlHndl_t errl = nullptr;
    // Assume a bad status.
    o_status = 0xFF;

    do {

        // Pull the address to verify out of the payload. It was inserted in
        // little endian form so it needs to be converted back to big endian
        // because setupPayload expects an address in big endian.
        uint16_t address = (i_payload[PAYLOAD_ADDRESS_START_INDEX])
                         | (i_payload[PAYLOAD_ADDRESS_START_INDEX + 1] << 8);

        // The data section of the payload is organized in the following way:
        // 2 bytes: uint16_t size of data to verify in little endian format
        // 2 bytes: CRC of the data to be verified on the BPM in little endian.
        const size_t VERIFY_BLOCK_PAYLOAD_DATA_SIZE = 4;
        uint8_t data[VERIFY_BLOCK_PAYLOAD_DATA_SIZE] = {0};

        // Since the data length is stored as uint16_t but the length we deal
        // with is uint8_t we can easily convert this to little endian by
        // storing our uint8_t data length in the first index of the array and
        // leaving the next index 0.
        data[0] = i_dataLength;

        // Calculate the uint16_t CRC for the data that was written to the BPM.
        // The BPM will compare its calculated CRC with this one to verify if
        // the block was written correctly.
        uint16_t crc = htole16(crc16_calc(&i_payload[PAYLOAD_DATA_START_INDEX],
                                  i_dataLength));

        memcpy(&data[2], &crc, sizeof(uint16_t));

        payload_t verifyPayload;
        errl = setupPayload(verifyPayload,
                            BSL_VERIFY_BLOCK,
                            address,
                            data,
                            VERIFY_BLOCK_PAYLOAD_DATA_SIZE);
        if (errl != nullptr)
        {
            break;
        }

        // Issue the command to the BPM.
        errl = issueCommand(BPM_PASSTHROUGH, verifyPayload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        errl = getResponse(&o_status, sizeof(uint8_t));
        if (errl != nullptr)
        {
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::blockWrite(payload_t i_payload)
{
    assert(i_payload[PAYLOAD_COMMAND_INDEX] == BSL_RX_DATA_BLOCK,
          "Bpm::blockWrite(): "
          "Can only retry for BSL_RX_DATA_BLOCK commands");

    errlHndl_t errl = nullptr;
    uint8_t retry = 0;

    // Any status from verifyBlockWrite that is non-zero is considered a
    // fail. So, assume a fail and check.
    uint8_t wasVerified = 0xFF;
    do {

        // Send the payload data over as a pass-through command
        errl = issueCommand(BPM_PASSTHROUGH, i_payload, WRITE);
        if (errl != nullptr)
        {
            break;
        }

        // Sleep for 0.001 second
        nanosleep(0, 1 * NS_PER_MSEC);

        uint8_t dataLength = i_payload[PAYLOAD_HEADER_DATA_LENGTH_INDEX]
                           - PAYLOAD_HEADER_SIZE;
        errl = verifyBlockWrite(i_payload,
                                dataLength,
                                wasVerified);
        if (errl != nullptr)
        {
            break;
        }

        if (wasVerified != 0)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::blockWrite(): "
                     "BSL_VERIFY_BLOCK failed. Attempt %d/%d",
                     (retry + 1),
                     MAX_RETRY);
        }
        else
        {
            break;
        }

    } while (++retry < MAX_RETRY);
    if ((retry >= MAX_RETRY) && (wasVerified != 0))
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::blockWrite(): "
                 "Failed to write payload data to BPM after %d retries.",
                 MAX_RETRY);
        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
        * @moduleid         BPM_RC::BPM_RETRY_BLOCK_WRITE
        * @reasoncode       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT
        * @userdata1[0:63]  NVDIMM Target HUID associated with this BPM
        * @devdesc          The block of data to be written to the BPM
        *                   failed to write successfully in the given number
        *                   of retries.
        * @custdesc         A problem occurred during IPL of the system.
        */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_RETRY_BLOCK_WRITE,
                                       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT,
                                       TARGETING::get_huid(iv_nvdimm));
        errl->collectTrace(BPM_COMP_NAME);

        // Change the state of iv_attemptAnotherUpdate. This will signal
        // another update attempt or cease further attempts.
        setAttemptAnotherUpdate();
    }

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

        // Give the BPM 20 seconds to complete any given command before we time
        // out and cancel the update procedure.
        int retry = 20 * MS_PER_SEC;

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
                TRACFCOMP(g_trac_bpm, ERR_MRK
                         "BPM::waitForCommandStatusBitReset(): "
                         "BSP_CMD_IN_PROGRESS bit has not reset in allotted "
                         "number of retries. Cancel update procedure");
                /*@
                * @errortype
                * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
                * @moduleid         BPM_RC::BPM_WAIT_FOR_CMD_BIT_RESET
                * @reasoncode       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT
                * @userdata1[0:63]  NVDIMM Target HUID associated with this BPM
                * @devdesc          The command status bit failed to reset in
                *                   the given number of retries.
                * @custdesc         A problem occurred during IPL of the system.
                */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           BPM_RC::BPM_WAIT_FOR_CMD_BIT_RESET,
                                           BPM_RC::BPM_EXCEEDED_RETRY_LIMIT,
                                           TARGETING::get_huid(iv_nvdimm));
                errl->collectTrace(BPM_COMP_NAME);
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

            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::waitForCommandStatusBitReset(): "
                      "BPM_CMD_STATUS Error Flag is set");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_WAIT_FOR_CMD_BIT_RESET
            * @reasoncode       BPM_RC::BPM_CMD_STATUS_ERROR_BIT_SET
            * @userdata1[0:7]   Error status code returned by BPM
            * @userdata2[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          The command status register returned an error.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_WAIT_FOR_CMD_BIT_RESET,
                                       BPM_RC::BPM_CMD_STATUS_ERROR_BIT_SET,
                                       error,
                                       TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
            break;

        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::verifyGoodBpmState()
{
    errlHndl_t errl = nullptr;
    int retry = 100;
    scap_status_register_t status;
    const uint8_t BPM_PRESENT_AND_ENABLED = 0x11;

    while (retry > 0)
    {

        errl = nvdimmReadReg(iv_nvdimm,
                             SCAP_STATUS,
                             status.full);
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, "Bpm::verifyGoodBpmState(): "
                      "Failed to read SCAP_STATUS to determine "
                      "state of BPM.");
            break;
        }

        if ((status.full & 0xFF) == BPM_PRESENT_AND_ENABLED)
        {
            // BPM is present and enabled. Stop retries.
            break;
        }

        if (retry <= 0)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::verifyGoodBpmState(): "
                      "BPM failed to become present and enabled "
                      "in 100 retries.");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_VERIFY_GOOD_BPM_STATE
            * @reasoncode       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT
            * @userdata1        NVDIMM Target HUID associated with this BPM
            * @userdata2        SCAP_STATUS register contents. See nvdimm.H
            *                   for bits associated with this register.
            * @devdesc          The BPM did not become present and enabled
            *                   in given number of retries.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_VERIFY_GOOD_BPM_STATE,
                                       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT,
                                       TARGETING::get_huid(iv_nvdimm),
                                       status.full);
            errl->collectTrace(BPM_COMP_NAME);
            break;
        }

        --retry;
        nanosleep(0, 1 * NS_PER_MSEC);
    }

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
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::waitForBusyBit(): "
                      "SCAP_STATUS Busy bit failed to reset to 0 "
                      "in 10 retries.");
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_WAIT_FOR_BUSY_BIT_RESET
            * @reasoncode       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT
            * @userdata1[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          The SCAP status register busy bit failed to
            *                   reset in given number of retries.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_WAIT_FOR_BUSY_BIT_RESET,
                                       BPM_RC::BPM_EXCEEDED_RETRY_LIMIT,
                                       TARGETING::get_huid(iv_nvdimm));
            errl->collectTrace(BPM_COMP_NAME);
            break;
        }

        --retry;
        nanosleep(0, 2 * NS_PER_MSEC);
    }

    return errl;
}

errlHndl_t Bpm::runConfigUpdates(BpmConfigLidImage i_configImage)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"Bpm::runConfigUpdates()");
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

        // Before the entering BSL mode, we must do preprocessing prior to the
        // config part of the update. Segment D and B need to be dumped from the
        // BPM into buffers and then the config data from the image needs to be
        // inserted into them. To dump segment data, it is required to have
        // working firmware which will not be the case during BSL mode.
        errl = preprocessSegments(i_configImage);
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

        // Perform the configuration data segment updates.
        // As of BSL 1.4 this is done via the BSL interface instead of SCAP
        // registers.
        errl = updateConfig();
        if (errl != nullptr)
        {
            break;
        }

    } while(0);

    do {

        // Reset the device. This will exit BSL mode.
        errlHndl_t exitErrl = resetDevice();
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runConfigUpdates(): "
                      "Failed to reset the device");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        // Exit update mode
        exitErrl = exitUpdateMode();
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runConfigUpdates(): "
                      "Failed to exit update mode");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

    } while(0);

    return errl;
}

errlHndl_t Bpm::runFirmwareUpdates(BpmFirmwareLidImage i_image)
{
    TRACFCOMP(g_trac_bpm, ENTER_MRK"bpm::runFirmwareUpdates()");
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

        // Run Firmware Update
        errl = updateFirmware(i_image);
        if (errl != nullptr)
        {
            break;
        }

        TRACFCOMP(g_trac_bpm, "Bpm::runFirmwareUpdates(): "
                 "Perform final CRC check on entire BPM flash to load "
                 "new firmware.");

        errl = checkFirmwareCrc();
        if (errl != nullptr)
        {
            setAttemptAnotherUpdate();
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm:: runFirmwareUpdates(): "
                     "Final CRC check failed. %s ",
                     (iv_attemptAnotherUpdate == false) ?
                     "Attempt another update..."
                     : "Attempts to update the BPM have failed. Firmware will not load.");
            break;
        }

    } while(0);

    do {

        // Reset the device. This will exit BSL mode.
        errlHndl_t exitErrl = resetDevice();
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runFirmwareUpdates(): "
                      "Failed to reset the device");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        // Exit update mode
        exitErrl = exitUpdateMode();
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runFirmwareUpdates(): "
                      "Failed to exit update mode");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        // If the update was successful then we must wait for 10 seconds before
        // polling the status of the BPM since it has to finish updating its
        // firmware and resetting.
        TRACFCOMP(g_trac_bpm, "Bpm::runFirmwareUpdates(): "
                  "Wait for the BPM to finish update and reset procedure, "
                  "sleep for 15 seconds");
        longSleep(15);

        // Poll SCAP_STATUS register for BPM state before we check final
        // firmware version.
        exitErrl = verifyGoodBpmState();
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runFirmwareUpdates(): "
                     "Could not verify that BPM was present and enabled!");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        uint16_t bpmFwVersion = INVALID_VERSION;
        exitErrl = getFwVersion(bpmFwVersion);
        if (exitErrl != nullptr)
        {
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::runFirmwareUpdates(): "
                     "Could not determine firmware version on the BPM");
            handleMultipleErrors(errl, exitErrl);
            break;
        }

        TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runFirmwareUpdates(): "
                  "Firmware version on the BPM 0x%.4X, "
                  "Firmware version of image 0x%.4X.",
                  bpmFwVersion, i_image.getVersion());

        if (i_image.getVersion() == bpmFwVersion)
        {
            TRACFCOMP(g_trac_bpm, INFO_MRK"Bpm::runFirmwareUpdates(): "
                     "Firmware version on the BPM matches the version in the "
                     "image. Update Successful.");
            iv_attemptAnotherUpdate = false;
        }
        else
        {
            // Attempt another update if one hasn't already been attempted.
            setAttemptAnotherUpdate();
            TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm:: runFirmwareUpdates(): "
                     "Version on BPM didn't match image. %s ",
                     iv_attemptAnotherUpdate ?
                     "Attempt another update..."
                     : "Attempts to update the BPM have failed.");
            if (iv_attemptAnotherUpdate == false)
            {
                /*@
                * @errortype
                * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid         BPM_RC::BPM_RUN_FW_UPDATES
                * @reasoncode       BPM_RC::BPM_VERSION_MISMATCH
                * @userdata1[00:31] Version on the BPM
                * @userdata1[32:63] Version of the flash image
                * @userdata2        NVDIMM Target HUID associated with this BPM
                * @devdesc          The version on the BPM didn't match the
                *                   version in the flash image.
                * @custdesc         A problem occurred during IPL of the system.
                */
                exitErrl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           BPM_RC::BPM_RUN_FW_UPDATES,
                                           BPM_RC::BPM_VERSION_MISMATCH,
                                           TWO_UINT32_TO_UINT64(bpmFwVersion,
                                               i_image.getVersion()),
                                           TARGETING::get_huid(iv_nvdimm));
                exitErrl->collectTrace(BPM_COMP_NAME);
                handleMultipleErrors(errl, exitErrl);
            }
        }

    } while(0);

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
                  "Response Packet CRC check status = 0x%X, CRC_Low = 0x%X, "
                  "CRC_Hi = 0x%X",
                  responseData[0],
                  responseData[1],
                  responseData[2]);

        if (responseData[0] != SUCCESSFUL_OPERATION)
        {
            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid         BPM_RC::BPM_CHECK_FIRMWARE_CRC
            * @reasoncode       BPM_RC::BPM_FIRMWARE_CRC_VERIFY_FAILURE
            * @userdata1[0:7]   CRC check response status code. See bpm_update.H
            * @userdata1[8:15]  CRC low byte
            * @userdata1[16:23] CRC high byte
            * @userdata2[0:63]  NVDIMM Target HUID associated with this BPM
            * @devdesc          The firmware CRC check failed. Cross check the
            *                   CRC check response status code for more details.
            * @custdesc         A problem occurred during IPL of the system.
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       BPM_RC::BPM_CHECK_FIRMWARE_CRC,
                                       BPM_RC::BPM_FIRMWARE_CRC_VERIFY_FAILURE,
                                       FOUR_UINT8_TO_UINT32(responseData[0],
                                                             responseData[1],
                                                             responseData[2],
                                                             0),
                                       TARGETING::get_huid(iv_nvdimm));
            break;
        }

    } while(0);

    if (errl != nullptr)
    {
        TRACFCOMP(g_trac_bpm, ERR_MRK"Bpm::checkFirmwareCrc(): "
                  "Error occurred during BPM Firmware CRC check. "
                  "Firmware image will not load on BPM and update must be "
                  "attempted again.");
        errl->collectTrace(BPM_COMP_NAME);
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
