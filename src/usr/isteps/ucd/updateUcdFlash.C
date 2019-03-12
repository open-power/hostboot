/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ucd/updateUcdFlash.C $                         */
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

#include <config.h>
#include <isteps/ucd/updateUcdFlash.H>
#include <ucd/ucd_reasoncodes.H>
#include <devicefw/driverif.H>

#include <hwas/common/hwasCallout.H>

#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/hberrltypes.H>

#include <trace/interface.H>
#include <string.h>
#include <hbotcompid.H>

namespace POWER_SEQUENCER
{
namespace TI
{
namespace UCD // UCD Series
{

trace_desc_t* g_trac_ucd = nullptr;
TRAC_INIT(&g_trac_ucd, UCD_COMP_NAME, 2*KILOBYTE);

class Ucd
{
private:

    enum DEVICE_OP_LENGTH : size_t
    {
        MFR_REVISION_SIZE = 12,
        DEVICE_ID_SIZE = 32,
    };

    enum COMMAND : uint8_t
    {
        // PMBUS Specificiation
        MFR_REVISION = 0x9B, // Common, max 12 ASCII bytes

        // Manufacturer specific (0xD0-> 0xFD)
        DEVICE_ID    = 0xFD, // Common. max 32 ASCII bytes
    };

    const TARGETING::TargetHandle_t iv_pUcd;
    char* iv_deviceId;
    uint16_t iv_mfrRevision;

    /*
     *  Delete Copy Constructor
     */
    Ucd(const Ucd&) = delete;

    /*
     *  Delete Copy Assignment
     */
    Ucd& operator=(const Ucd&) = delete;

    /*
     *  Delete Move Constructor
     */
    Ucd (Ucd&&) = delete;

    /*
     *  Delete Move Assignment
     */
    Ucd& operator=(Ucd&&) = delete;

public:

    /* @brief      Constructor that takes a UCD target and sets up all of the
     *             instance variables. Will assert if a nullptr is given or if
     *             the given target is not of type POWER_SEQUENCER.
     *
     * @param[in] i_ucd      A pointer to the UCD target. Must not be nullptr
     *                       and must be of type POWER_SEQUENCER.
     */
    Ucd(const TARGETING::TargetHandle_t i_ucd)
        : iv_pUcd(i_ucd), iv_deviceId(nullptr), iv_mfrRevision(0)
    {
        assert(i_ucd != nullptr, "i_ucd must not be nullptr");
        assert(i_ucd->getAttr<TARGETING::ATTR_TYPE>()
                == TARGETING::TYPE_POWER_SEQUENCER,
                "i_ucd must be of type POWER_SEQUENCER");
    }

    /* @brief           Destructor that cleans up the iv_deviceId instance
     *                  variable.
     *
     */
    ~Ucd()
    {
        delete[] iv_deviceId;
        iv_deviceId = nullptr;
    }

    /*
     * @brief           Sets up the device id and mfr revision instance
     *                  variables by performing two device reads on the UCD.
     *
     * @return          nullptr on success. Otherwise, a error that occurred.
     *
     */
    errlHndl_t initialize()
    {
        errlHndl_t err = nullptr;

        // Wipe out the instance variables in case this function is called
        // multiple times. That way if we fail during one of those attempts
        // old values aren't preserved.
        delete[] iv_deviceId;
        iv_deviceId = nullptr;
        iv_mfrRevision = 0;

        do
        {
            char deviceIdBuffer[DEVICE_ID_SIZE]{};

            // Get the I2C info for this UCD.
            const auto i2cInfo = iv_pUcd->
                getAttr<TARGETING::ATTR_I2C_CONTROL_INFO>();

            TARGETING::TargetHandle_t i2cMaster =
                TARGETING::targetService().toTarget(i2cInfo.i2cMasterPath);

           assert(i2cMaster != nullptr, "i2cMaster for UCD 0x%.8X was nullptr",
                  get_huid(iv_pUcd));

            size_t size = sizeof(deviceIdBuffer);

            err = deviceOp(DeviceFW::READ,
                           i2cMaster,
                           deviceIdBuffer,
                           size,
                           DEVICE_I2C_SMBUS_BLOCK(i2cInfo.engine,
                                                  i2cInfo.port,
                                                  i2cInfo.devAddr,
                                                  DEVICE_ID,
                                                  i2cInfo.i2cMuxBusSelector,
                                                  &i2cInfo.i2cMuxPath)
                          );

            // @TODO RTC 205982: Handle the PEC byte if it exists.
            if (err)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Could not "
                          "read DEVICE_ID from UCD "
                          "0x%.8X", get_huid(iv_pUcd));
                break;
            }

            // Verify that the buffer is the size the we expected to get.
            if (size != DEVICE_ID_SIZE)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Read from "
                          "UCD 0x%.8X returned "
                          "size different than requested. "
                          "Actual %d, expected %d",
                          get_huid(iv_pUcd),
                          size, DEVICE_ID_SIZE);

                /*@
                 * @errortype
                 * @severity           ERRL_SEV_UNRECOVERABLE
                 * @moduleid           UCD_RC::MOD_UCD_INIT
                 * @reasoncode         UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_DEVICE_ID
                 * @devdesc            A device read from the UCD didn't read
                 *                     the expected number of bytes.
                 * @custdesc           A problem occurred during the IPL of the
                 *                     system: Internal Firmware Error
                 * @userdata1[00:31]   Expected read size
                 * @userdata1[32:63]   Actual read size
                 * @userdata2          HUID of the UCD
                 */
                err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              UCD_RC::MOD_UCD_INIT,
                              UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_DEVICE_ID,
                              TWO_UINT32_TO_UINT64(DEVICE_ID_SIZE, size),
                              get_huid(iv_pUcd)
                          );

                err->addI2cDeviceCallout(i2cMaster,
                                         i2cInfo.engine,
                                         i2cInfo.port,
                                         i2cInfo.devAddr,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);


                break;
            }

            // Verify there is a null terminator at the end of the buffer.
            if (deviceIdBuffer[DEVICE_ID_SIZE-1] != '\0')
            {
                deviceIdBuffer[DEVICE_ID_SIZE-1] = '\0';
            }

            // Since the format of the buffer will be: Device Id|..|..|..
            // Replace the first occurence of the | symbol with null to
            // exclude irrelevant info.
            auto pDelimiter = strchr(deviceIdBuffer, '|');

            if (pDelimiter != nullptr)
            {
                *pDelimiter = '\0';
            }

            // Copy the device id into the instance variable.
            iv_deviceId = new char[strlen(deviceIdBuffer)+1]();
            strcpy(iv_deviceId, deviceIdBuffer);

            TRACFCOMP(g_trac_ucd, INFO_MRK
                     "Ucd::Initialize(): DEVICE_ID read from UCD 0x%.8X as %s",
                     get_huid(iv_pUcd),
                     iv_deviceId);

            // This is the buffer that will be used to read the MFR Revision
            // from the UCD device.
            union mfrRevisionBuffer
            {
                // The MFR Revision represented as a value.
                uint16_t value;
                // The MFR Revision represented as ASCII characters excluding
                // null terminator.
                uint8_t str[MFR_REVISION_SIZE];
            } mfrBuf;

            size = MFR_REVISION_SIZE;

            // Read the MFR revision from the UCD device.
            err = deviceOp(DeviceFW::READ,
                           i2cMaster,
                           mfrBuf.str,
                           size,
                           DEVICE_I2C_SMBUS_BLOCK(i2cInfo.engine,
                                                  i2cInfo.port,
                                                  i2cInfo.devAddr,
                                                  MFR_REVISION,
                                                  i2cInfo.i2cMuxBusSelector,
                                                  &i2cInfo.i2cMuxPath)
                          );

            // @TODO RTC 205982: Need to handle the case where a bad PEC byte
            //                   is returned
            if (err)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initializei(): Could not "
                          "read MFR_REVISION from UCD 0x%.8X",
                          get_huid(iv_pUcd));
                break;
            }

            // Verify that the buffer is the size the we expected to get.
            if (size != MFR_REVISION_SIZE)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Read from UCD "
                          "0x%.8X returned "
                          "size different than requested. "
                          "Actual %d, expected %d",
                          get_huid(iv_pUcd),
                          size, MFR_REVISION_SIZE);

                /*@
                 * @errortype
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         UCD_RC::MOD_UCD_INIT
                 * @reasoncode       UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_MFR_REVISION
                 * @devdesc          A device read from the UCD didn't read
                 *                   the expected number of bytes.
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system: Internal Firmware Error
                 * @userdata1[00:31] Expected read size
                 * @userdata1[32:63] Actual read size
                 * @userdata2        HUID of the UCD
                 */
                err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            UCD_RC::MOD_UCD_INIT,
                            UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_MFR_REVISION,
                            TWO_UINT32_TO_UINT64(MFR_REVISION_SIZE, size),
                            get_huid(iv_pUcd));

                err->addI2cDeviceCallout(i2cMaster,
                                         i2cInfo.engine,
                                         i2cInfo.port,
                                         i2cInfo.devAddr,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);
                break;
            }

            // Convert the ASCII MFR revision to unsigned int.
            iv_mfrRevision = mfrBuf.value;

            TRACFCOMP(g_trac_ucd, INFO_MRK
                      "Ucd::Initialize(): MFR_REVISION read from UCD 0x%.8X "
                      "as 0x%.4X",
                      get_huid(iv_pUcd),
                      mfrBuf.value);

        } while(0);

        return err;
    }

    /*
     * @brief                     Gets the Device ID for the UCD member of this
     *                            struct.
     *
     * @return                    A constant pointer to the device id string.
     *
     */
    const char* getDeviceId() const
    {
        return iv_deviceId;
    }

    /* @brief                     Will get the MFR Revision for the UCD member
     *                            of this struct.
     *
     * @return                    The ASCII MFR revision as a uint16_t.
     */
    uint16_t getMfrRevision() const
    {
        return iv_mfrRevision;
    }

};


errlHndl_t updateUcdFlash(
          TARGETING::Target* i_pUcd,
    const void*              i_pFlashImage)
{
    errlHndl_t pError = nullptr;

    // Stub for future additional support

    return pError;
}

} // End namespace UCD

} // End namespace TI

} // End namespace POWER_SEQUENCER
