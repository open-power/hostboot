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
#include <attributetraits.H>

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/hberrltypes.H>
#include <errl/errludstring.H>

#include <trace/interface.H>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <hbotcompid.H>
#include <util/utilmem.H>
#include <util/utilstream.H>
#include <errl/errludstring.H>

namespace POWER_SEQUENCER
{
namespace TI
{
namespace UCD // UCD Series
{

trace_desc_t* g_trac_ucd = nullptr;
TRAC_INIT(&g_trac_ucd, UCD_COMP_NAME, 2*KILOBYTE);

// Switch to turn on and off debug traces:
#define TRACUCOMP(args...)  TRACDCOMP(args)


class Ucd
{
private:

    enum DEVICE_OP_LENGTH : size_t
    {
        MFR_REVISION_MAX_SIZE = 12,
        DEVICE_ID_MAX_SIZE    = 32,
    };

    /**
     *  @brief Range enumerations for the PAGE command
     */
    enum PAGE_CMD_RESTRICTIONS : uint8_t
    {
        INVALID_PAGE_RANGE_MIN = 12,  ///< First invalid page
        INVALID_PAGE_RANGE_MAX = 254, ///< Last invalid page
    };

    enum COMMAND : uint8_t
    {
        // PMBUS Specificiation
        PAGE         = 0x00, // Common, 1 byte page ID
        MFR_REVISION = 0x9B, // Common, max 12 ASCII bytes

        // Manufacturer specific (0xD0-> 0xFD)
        MFR_STATUS   = 0xF3, // Page, 4 bytes for UCD9090 and UCD90120A
        DEVICE_ID    = 0xFD, // Common. max 32 ASCII bytes
    };

    const TARGETING::TargetHandle_t iv_pUcd;
    char* iv_deviceId;
    uint16_t iv_mfrRevision;
    TARGETING::TargetHandle_t iv_pI2cMaster;
    TARGETING::I2cControlInfo iv_i2cInfo;

    /*
     *  @brief         This function creates a new ErrlEntry with the supplied
     *                 parameters, adds an I2C callout, a software callout, and
     *                 collects traces for UCD_COMP_NAME.
     *
     * @param[in]   i_sev           Log's severity. See errltypes.H for
     *                              available values
     * @param[in]   i_modId         The module (interface) where this log is
     *                              created from.
     * @param[in]   i_reasonCode    Bits 00-07: Component Id
     *                              Bits 08-15: Reason code
     * @param[in]   i_user1         64 bits of user data which are placed
     *                              in the primary SRC. Defaults to zero.
     * @param[in]   i_user2         64 bits of user data which are placed
     *                              in the secondary SRC. Defaults to zero.
     */
    errlHndl_t ucdError(const ERRORLOG::errlSeverity_t i_sev,
                        const uint8_t i_modId,
                        const uint16_t i_reasonCode,
                        const uint64_t i_user1,
                        const uint64_t i_user2)
    {
        errlHndl_t err = nullptr;

        err = new ERRORLOG::ErrlEntry(i_sev,
                                      i_modId,
                                      i_reasonCode,
                                      i_user1,
                                      i_user2);

        // Add a callout for the I2C master.
        err->addI2cDeviceCallout(iv_pI2cMaster,
                                 iv_i2cInfo.engine,
                                 iv_i2cInfo.port,
                                 iv_i2cInfo.devAddr,
                                 HWAS::SRCI_PRIORITY_HIGH);

        // Add a callout for hostboot code.
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);

        err->collectTrace(UCD_COMP_NAME);
        err->collectTrace(I2C_COMP_NAME);
        return err;
    }

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

    /**
     *  @brief Write the UCD page
     *
     *  @par Detailed Description:
     *      Writes the UCD page, an index that selects a specific voltage
     *      rail (or 'all' voltage rails) to receive later write requests.
     *      Status not specific to a rail is available for read on any
     *      valid page (other than the 'all' page).
     *
     *      Page to rail decoding (see section 6.1 of
     *          http://www.ti.com/lit/ug/slvu352f/slvu352f.pdf):
     *
     *        Page 0 => Output rail 1
     *        ...
     *        Page 11 => Output rail 12
     *        Page 12-254 => Always invalid (enforced by assertion)
     *        Page 255 => All rails (but only for writes, this is never valid
     *            for any read operations)
     *
     *  @param[in] i_page Page to switch to
     *
     *  @return errlHndl_t Error handle indicating success or failure
     *  @retval nullptr Set the requested page successfully
     *  @retval !nullptr Error setting the requested page; handle points to
     *      valid error log
     */
    errlHndl_t writePage(const uint8_t i_page) const
    {
        errlHndl_t pError = nullptr;

        do {

        assert((   (i_page < INVALID_PAGE_RANGE_MIN)
                || (i_page > INVALID_PAGE_RANGE_MAX)),
               "Invalid page request of %d; must be < %d or > %d",
               i_page,INVALID_PAGE_RANGE_MIN,INVALID_PAGE_RANGE_MAX);

        auto page = i_page;
        size_t size = sizeof(page);
        const auto expSize = size;

        pError = deviceOp(DeviceFW::WRITE,
                          iv_pI2cMaster,
                          &page,
                          size,
                          DEVICE_I2C_SMBUS_BYTE(iv_i2cInfo.engine,
                                                iv_i2cInfo.port,
                                                iv_i2cInfo.devAddr,
                                                PAGE,
                                                iv_i2cInfo.i2cMuxBusSelector,
                                                &iv_i2cInfo.i2cMuxPath));

        // @TODO RTC 205982: Handle the PEC byte if it exists.
        if(pError)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::writePage(): Could not write PAGE %d to UCD with "
                "HUID of 0x%08X", page, get_huid(iv_pUcd));
            break;
        }

        assert(size == expSize, "Ucd::writePage(): Actual size written of %lu "
            "did not match expected size of %lu ",size,expSize);

        } while(0);

        return pError;
    }

public:

    /**
     *  @brief MFR_STATUS bits
     *
     *  @note: See http://www.ti.com/lit/ug/slvu352f/slvu352f.pdf
     *      table 90
     */
    struct MfrStatus
    {
        // UCD bit 0 is rightmost bit in the uint32_t
        uint32_t Reserved_31_24          : 8; // Bit 31-24
        uint32_t GPI8Fault               : 1; // Bit 23
        uint32_t GPI7Fault               : 1; // Bit 22
        uint32_t GPI6Fault               : 1; // Bit 21
        uint32_t GPI5Fault               : 1; // Bit 20
        uint32_t GPI4Fault               : 1; // Bit 19
        uint32_t GPI3Fault               : 1; // Bit 18
        uint32_t GPI2Fault               : 1; // Bit 17
        uint32_t GPI1Fault               : 1; // Bit 16
        uint32_t Reserved_15_13          : 3; // Bit 15-13
        uint32_t NEW_LOGGED_FAULT_DETAIL : 1; // Bit 12
        uint32_t SYSTEM_WATCHDOG_TIMEOUT : 1; // Bit 11
        uint32_t STORE_DEFAULT_ALL_ERROR : 1; // Bit 10
        uint32_t STORE_DEFAULT_ALL_DONE  : 1; // Bit 9
        uint32_t WATCHDOG_TIMEOUT        : 1; // Bit 8
        uint32_t INVALID_LOGS            : 1; // Bit 7
        uint32_t LOGGED_FAULT_DETAIL_FULL: 1; // Bit 6
        uint32_t RESEQUENCE_ERROR        : 1; // Bit 5
        uint32_t PKGID_MISMATCH          : 1; // Bit 4
        uint32_t HARDCODED_PARMS         : 1; // Bit 3
        uint32_t SEQ_OFF_TIMEOUT         : 1; // Bit 2
        uint32_t SEQ_ON_TIMEOUT          : 1; // Bit 1
        uint32_t SAVED_FAULT             : 1; // Bit 0

    } PACKED;

    /**
     *  @brief Union simplifying manipulation of the MFR_STATUS value
     */
    union MfrStatusUnion
    {
        uint32_t value;   // Raw MFR_STATUS value
        MfrStatus status; // Struct breaking out all status bits of MFR_STATUS

        /**
         *  @brief Constructor
         */
        MfrStatusUnion()
            : value(0)
        {
        }

    } PACKED;

    /**
     *  @brief Read UCD MFR_STATUS
     *
     *  @par Detailed Description:
     *      Reads the UCD MFR_STATUS register which return various errors/faults
     *      for the UCD.
     *
     *  @note: Output variable is always cleared to all 0's
     *
     *  @param[out] o_mfrStatus Bit field containing the MFR_STATUS bits
     *
     *  @return errlHndl_t Error handle indicating success or failure
     *  @retval nullptr Returned MFR_STATUS bit field is valid
     *  @retval !nullptr Error reading MFR_STATUS; handle points to valid error
     *      log
     */
    errlHndl_t readMfrStatus(MfrStatus& o_mfrStatus) const
    {
        errlHndl_t pError = nullptr;

        MfrStatusUnion mfrStatus;
        o_mfrStatus = mfrStatus.status;

        do {

        // Assumption is that reading the bits for confirming flash update
        // success will work from any valid rail 1-12 (page 0-11), so
        // arbitrarily use the lowest valid page of 0.  If Hostboot ever needs
        // status from from specific voltage rails, the API/function must change
        // to accept a rail ID.
        pError = writePage(0);
        if(pError)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::readMfrStatus(): failed in call to writePage(0) for "
                "UCD with HUID of 0x%08X",
                TARGETING::get_huid(iv_pUcd));
            break;
        }

        size_t size = sizeof(mfrStatus.value);
        const auto expSize = size;

        pError = deviceOp(DeviceFW::READ,
                          iv_pI2cMaster,
                          &mfrStatus.value,
                          size,
                          DEVICE_I2C_SMBUS_BLOCK(iv_i2cInfo.engine,
                                                 iv_i2cInfo.port,
                                                 iv_i2cInfo.devAddr,
                                                 MFR_STATUS,
                                                 iv_i2cInfo.i2cMuxBusSelector,
                                                 &iv_i2cInfo.i2cMuxPath));

        // @TODO RTC 205982: Handle the PEC byte if it exists.
        if (pError)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::readMfrStatus(): Could not read MFR_STATUS from UCD with "
                "HUID of 0x%08X", get_huid(iv_pUcd));
            break;
        }

        assert(size == expSize, "Ucd::readMfrStatus(): Actual size read of %lu "
            "did not match expected size of %lu",size,expSize);

        o_mfrStatus = mfrStatus.status;

        } while(0);

        return pError;
    }

    /**
     *  @brief Verify that the UCD flash updated correctly, according to
     *      manufacturer recommendations
     *
     *  @par Detailed Description:
     *      Checks the MFR_STATUS to determine if the flash update completed,
     *      and if so, whether it completed with an error or not.  If it
     *      completed successfully, the UCD update is considered complete.
     *      Otherwise, return an error.  See section 6.3 of
     *      http://www.ti.com/lit/ug/slvu352f/slvu352f.pdf for discussion of
     *      this check.
     *
     *  @return errlHndl_t Error handle indicating success or failure
     *  @retval nullptr Verified that UCD flash updated correctly
     *  @retval !nullptr UCD flash update error; handle points to valid error
     *      log
     */
    errlHndl_t verifyUpdate(void) const
    {
        TRACFCOMP(g_trac_ucd, ENTER_MRK "Ucd::verifyUpdate");

        errlHndl_t pError = nullptr;

        do {

        MfrStatusUnion mfrStatus;
        pError = readMfrStatus(mfrStatus.status);
        if(pError)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::verifyUpdate(): failed in call to readMfrStatus() for "
                "UCD with HUID of 0x%08X",
                TARGETING::get_huid(iv_pUcd));
            break;
        }

        TRACFCOMP(g_trac_ucd, INFO_MRK
            "Ucd::verifyUpdate(): Got MFR_STATUS of 0x%08X for "
            "UCD with HUID of 0x%08X.  Store done = %d, store error = %d",
            mfrStatus.value,
            TARGETING::get_huid(iv_pUcd),
            mfrStatus.status.STORE_DEFAULT_ALL_DONE,
            mfrStatus.status.STORE_DEFAULT_ALL_ERROR);

        if(!mfrStatus.status.STORE_DEFAULT_ALL_DONE)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::verifyUpdate(): UCD with HUID of 0x%08X did not complete "
                "flash update.  Status = 0x%08X",
                TARGETING::get_huid(iv_pUcd),
                mfrStatus.value);

            /*@
             * @errortype
             * @severity   ERRL_SEV_PREDICTIVE
             * @moduleid   UCD_RC::MOD_VERIFY_UPDATE
             * @reasoncode UCD_RC::UCD_TIMEDOUT_STORING_TO_FLASH
             * @devdesc    The "store default all" operation, which commits
             *     configuration changes to the UCD flash, did not complete
             * @custdesc   PCIE hotplug controller flash update failure
             * @userdata1[00:31] MFR_STATUS value
             * @userdata2        HUID of the UCD
             */
            pError = ucdError(
                ERRORLOG::ERRL_SEV_PREDICTIVE,
                UCD_RC::MOD_VERIFY_UPDATE,
                UCD_RC::UCD_TIMEDOUT_STORING_TO_FLASH,
                TWO_UINT32_TO_UINT64(mfrStatus.value, 0),
                get_huid(iv_pUcd));
            break;
        }

        if(mfrStatus.status.STORE_DEFAULT_ALL_ERROR)
        {
            TRACFCOMP(g_trac_ucd, ERR_MRK
                "Ucd::verifyUpdate(): UCD with HUID of 0x%08X completed "
                "flash update with errors.  Status = 0x%08X",
                TARGETING::get_huid(iv_pUcd),
                mfrStatus.value);

            /*@
             * @errortype
             * @severity   ERRL_SEV_PREDICTIVE
             * @moduleid   UCD_RC::MOD_VERIFY_UPDATE
             * @reasoncode UCD_RC::UCD_ERROR_STORING_TO_FLASH
             * @devdesc    The "store default all" operation, which commits
             *     configuration changes to the UCD flash, completed but with
             *     errors
             * @custdesc   PCIE hotplug controller flash update failure
             * @userdata1[00:31] MFR_STATUS value
             * @userdata2        HUID of the UCD
             */
            pError = ucdError(
                ERRORLOG::ERRL_SEV_PREDICTIVE,
                UCD_RC::MOD_VERIFY_UPDATE,
                UCD_RC::UCD_ERROR_STORING_TO_FLASH,
                TWO_UINT32_TO_UINT64(mfrStatus.value, 0),
                get_huid(iv_pUcd));
            break;
        }

        TRACFCOMP(g_trac_ucd, INFO_MRK
            "Ucd::verifyUpdate(): UCD with HUID of 0x%08X completed "
            "flash update with no update specific errors.  Status = 0x%08X",
            TARGETING::get_huid(iv_pUcd),
            mfrStatus.value);

        } while(0);

        TRACFCOMP(g_trac_ucd, EXIT_MRK "Ucd::verifyUpdate");

        return pError;
    }

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

        // Get the I2C info for this UCD.
        memset(&iv_i2cInfo, 0, sizeof(iv_i2cInfo));
        iv_i2cInfo = iv_pUcd->getAttr<TARGETING::ATTR_I2C_CONTROL_INFO>();

        iv_pI2cMaster =
            TARGETING::targetService().toTarget(iv_i2cInfo.i2cMasterPath);

        assert(iv_pI2cMaster != nullptr, "i2cMaster for UCD 0x%.8X was nullptr",
                  get_huid(iv_pUcd));

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
            char deviceIdBuffer[DEVICE_ID_MAX_SIZE]{};

            size_t size = sizeof(deviceIdBuffer);

            err = deviceOp(DeviceFW::READ,
                           iv_pI2cMaster,
                           deviceIdBuffer,
                           size,
                           DEVICE_I2C_SMBUS_BLOCK(iv_i2cInfo.engine,
                                                  iv_i2cInfo.port,
                                                  iv_i2cInfo.devAddr,
                                                  DEVICE_ID,
                                                  iv_i2cInfo.i2cMuxBusSelector,
                                                  &iv_i2cInfo.i2cMuxPath)
                          );

            // @TODO RTC 205982: Handle the PEC byte if it exists.
            if (err)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Could not "
                          "read DEVICE_ID from UCD "
                          "0x%.8X", get_huid(iv_pUcd));
                break;
            }

            // Verify that the buffer is not larger than the MAX_SIZE we expect
            // (It is possible to receive a smaller size than MAX_SIZE)
            if (size > DEVICE_ID_MAX_SIZE)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Read from "
                          "UCD 0x%.8X for DEVICE_ID returned "
                          "size larger than expected. "
                          "Actual %d, expected %d",
                          get_huid(iv_pUcd),
                          size, DEVICE_ID_MAX_SIZE);
                /*@
                 * @errortype
                 * @severity           ERRL_SEV_PREDICTIVE
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
                err = ucdError(ERRORLOG::ERRL_SEV_PREDICTIVE,
                               UCD_RC::MOD_UCD_INIT,
                               UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_DEVICE_ID,
                               TWO_UINT32_TO_UINT64(DEVICE_ID_MAX_SIZE, size),
                               get_huid(iv_pUcd));

                break;
            }

            // Verify there is a null terminator at the end of the buffer.
            if (deviceIdBuffer[DEVICE_ID_MAX_SIZE-1] != '\0')
            {
                deviceIdBuffer[DEVICE_ID_MAX_SIZE-1] = '\0';
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
                uint8_t str[MFR_REVISION_MAX_SIZE];
            } mfrBuf;

            size = MFR_REVISION_MAX_SIZE;

            // Read the MFR revision from the UCD device.
            err = deviceOp(DeviceFW::READ,
                           iv_pI2cMaster,
                           mfrBuf.str,
                           size,
                           DEVICE_I2C_SMBUS_BLOCK(iv_i2cInfo.engine,
                                                  iv_i2cInfo.port,
                                                  iv_i2cInfo.devAddr,
                                                  MFR_REVISION,
                                                  iv_i2cInfo.i2cMuxBusSelector,
                                                  &iv_i2cInfo.i2cMuxPath)
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

            // Verify that the buffer is not larger than the MAX_SIZE we expect
            // (It is possible to receive a smaller size than MAX_SIZE)
            if (size > MFR_REVISION_MAX_SIZE)
            {
                TRACFCOMP(g_trac_ucd, ERR_MRK"Ucd::Initialize(): Read from UCD "
                          "0x%.8X for MFR Revision returned "
                          "size larger than expected. "
                          "Actual %d, expected %d",
                          get_huid(iv_pUcd),
                          size, MFR_REVISION_MAX_SIZE);
                /*@
                 * @errortype
                 * @severity         ERRL_SEV_PREDICTIVE
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
                err = ucdError(ERRORLOG::ERRL_SEV_PREDICTIVE,
                            UCD_RC::MOD_UCD_INIT,
                            UCD_RC::RC_DEVICE_READ_UNEXPECTED_SIZE_MFR_REVISION,
                            TWO_UINT32_TO_UINT64(MFR_REVISION_MAX_SIZE, size),
                            get_huid(iv_pUcd));

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
    } // end of initialize()

    /**
     *  @brief smbus_op_t struct to hold on SMBUS operation
     */
    struct smbus_op_t
    {
        uint64_t  addr;
        uint64_t  cmd;
        uint64_t  pec_byte;
        std::vector<uint8_t> vData;

        /**
         *  @brief smbus_op_t constructor
         */
        smbus_op_t()
        : addr(0),
          cmd(0),
          pec_byte(0)
        {
        }

    };

    /**
     *  @brief Processes a command line from a UCD update file for
     *         WriteByte, WriteWord, and BlockWrite operations
     *
     *  @param[in]  i_str  Pointer to the start of the 2nd field of the command
     *                     NOTE: This parameter is not a const - it is updated
     *  @param[out] o_op   Output structure with the derived info
     *
     *  @note There is an expected layout for the 2nd, 3rd, and 4th fields for
     *        these operations.  Any detected deviation will result in an assert
     *
     *  @return void
     */
    void convertStringToOp(char * i_str, smbus_op_t & o_op)
    {
        // PEC byte is calculated on all message bytes, including
        //  addresses and Read/Write bit.
        // SMBus Fields are Request,Address,Command,Data with PEC byte
        // For reads, the last field is what is expected back from the device
        assert(i_str != nullptr, "convertStringToOp: i_str is nullptr");

        // Second Field is Address
        auto pDelimiter = strchr(i_str, ',' );
        if (pDelimiter != nullptr)
        {
            *pDelimiter = '\0';
        }
        else
        {
            assert(false,"convertStringToOp: pDelimiter for 2nd field is nullptr");
        }
        o_op.addr = strtoul(i_str, nullptr, 16);

        // Move Past Second Field
        i_str = pDelimiter+1;

        // Third Field is Command
        pDelimiter = strchr(i_str, ',' );
        if (pDelimiter != nullptr)
        {
            *pDelimiter = '\0';
        }
        else
        {
            assert(false,"convertStringToOp: pDelimiter for 3rd field is nullptr");
        }
        o_op.cmd = strtoul(i_str, nullptr, 16 );

        // Move Past Third Field
        i_str = pDelimiter+1;

        // Fourth field is Data + PEC byte
        // - should already have '\0' at it from above
        o_op.vData.clear();
        char char_byte[] = "\0\0\0";

        // Skip the expected "0x" at the start of the data stream
        i_str += 2;

        while (*i_str != '\0')
        {
            char_byte[0] = *(i_str++);  // Get 1st nibble then increment
            char_byte[1] = *(i_str++);  // Get 2nd nibble then increment
            o_op.vData.push_back(strtoul(char_byte, nullptr, 16));
        }

        // Last byte is pec byte
        o_op.pec_byte = o_op.vData.back();
        o_op.vData.pop_back();

        // Ignore checking pec byte for now as SMBUS Device Op calculates it

        // Setup data
        TRACDCOMP(g_trac_ucd,"convertStringToOp: data size=%d, byte0=0x%.2X",
                  o_op.vData.size(), o_op.vData[0]);

        return;
    }

    /**
     *  @brief Updates a UCD target's flash image
     *
     *  @param[in] i_pFlashImage pointer to the start of the data flash
     *      image for this UCD target.  Must not be nullptr.
     *  @param[in] i_size Size of i_pFlashImage
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Successfully updated the UCD's data flash image
     *  @retval !nullptr Failed to update the UCD's data flash image.  Handle
     *      points to valid error log
     */
    errlHndl_t updateUcdFlash(const void*  i_pFlashImage,
                                    size_t i_size)
    {
        errlHndl_t err = nullptr;

        TRACFCOMP(g_trac_ucd, ENTER_MRK"updateUcdFlash: ucd_tgt=0x%.08X, "
                  "i2cInfo: e%d/p%d/da=0x%X. i_pFlashImage=%p, i_size=0x%X",
                  TARGETING::get_huid(iv_pUcd),
                  iv_i2cInfo.engine, iv_i2cInfo.port, iv_i2cInfo.devAddr,
                  i_pFlashImage, i_size);

        TRACDBIN(g_trac_ucd,"updateUcdFlash: Start of i_pFlashImage",
                 i_pFlashImage, 128);

        size_t char_count = 0;
        size_t op_count = 1;
        char * tmp_str = reinterpret_cast<char*>(
                              const_cast<void*>(i_pFlashImage));

        while (char_count < i_size)
        {
            size_t size=0;
            size_t expSize = 0;

            // Each op is one line in the processed .csv file
            auto pDelimiter = strchr(tmp_str, '\n' );
            if (pDelimiter != nullptr)
            {
                *pDelimiter = '\0';
            }
            else
            {
                TRACFCOMP(g_trac_ucd,"updateUcdFlash: op=%d: "
                          "found nullptr: tmp_str=%p, pDelimiter=%p",
                          op_count, tmp_str, pDelimiter);
                /*@
                 * @errortype
                 * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @reasoncode UCD_RC::UCD_INVALID_COMMANDLINE
                 * @moduleid   UCD_RC::MOD_UPDATE_UCD_FLASH_IMAGE
                 * @userdata1  HUID of UCD Target
                 * @userdata2  The order of this operation
                 * @devdesc    A 'new line' character was not found while
                 *             processing this UCD flash image's command line
                 * @custdesc   Unexpected IPL firmware data format error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    UCD_RC::MOD_UPDATE_UCD_FLASH_IMAGE,
                    UCD_RC::UCD_INVALID_COMMANDLINE,
                    TARGETING::get_huid(iv_pUcd),
                    op_count,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                break;
            }

            size_t op_str_length = strlen(tmp_str);
            char_count += op_str_length+1;

            TRACUCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s "
                      "(len=%d, count=%d, total=%d)",
                      op_count, tmp_str, op_str_length, char_count, i_size);
            char * next_op = tmp_str + op_str_length + 1;

            // Process First Field - the Operation Type (or "Request")
            pDelimiter = strchr(tmp_str, ',' );
            if (pDelimiter != nullptr)
            {
                *pDelimiter = '\0';
            }
            else
            {
                assert(false,"updateUcdFlash: pDelimiter for 1st field is nullptr");
            }
            // Save start for if-check and tracing purposes
            char * op_type = tmp_str;

            // Move past first field
            tmp_str = pDelimiter+1;

            // Majority of ops need this structure
            smbus_op_t op{};

            // Look for expected Operation Types
            if (strcmp(op_type,"WriteByte") == 0)
            {
                // Convert the other fields to address, command, and data
                convertStringToOp(tmp_str, op);

                // Data size == 1 is checked by SMBUS Device Operation
                TRACUCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s: "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, data=0x%.2X, "
                          "pec=0x%.2X", op_count, op_type, op.addr, op.cmd,
                          op.vData.size(), op.vData[0], op.pec_byte);

                size = op.vData.size();
                expSize = size;

                err = deviceOp(DeviceFW::WRITE,
                           iv_pI2cMaster,
                           reinterpret_cast<void*>(op.vData.data()),
                           size,
                           DEVICE_I2C_SMBUS_BYTE(iv_i2cInfo.engine,
                                                 iv_i2cInfo.port,
                                                 iv_i2cInfo.devAddr,
                                                 op.cmd,
                                                 iv_i2cInfo.i2cMuxBusSelector,
                                                 &iv_i2cInfo.i2cMuxPath));

                if (err)
                {
                    TRACFCOMP(g_trac_ucd,ERR_MRK"updateUcdFlash: op=%d: %s: "
                          "DEVICE_I2C_SMBUS_BYTE Failed: err plid=0x%.8X. "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, data=0x%.2X, "
                          "pec=0x%.2X", op_count, op_type, err->plid(),
                          op.addr, op.cmd, op.vData.size(), op.vData[0],
                          op.pec_byte);
                    break;
                }
                assert(size==expSize, "updateUcdFlash: DEVICE_I2C_SMBUS_BYTE size mismatch: returned %d, but expected %d",
                       size, expSize);
            }
            else if (strcmp(op_type,"WriteWord") == 0)
            {
                // Convert the other fields to address, command, and data
                convertStringToOp(tmp_str, op);

                // Data size == 2 is checked by SMBUS Device Operation

                TRACUCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s: "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, "
                          "data=0x%.2X 0x%.2X, pec=0x%.2X",
                          op_count, op_type, op.addr, op.cmd, op.vData.size(),
                          op.vData[0], op.vData[1], op.pec_byte);

                size = op.vData.size();
                expSize = size;

                err = deviceOp(DeviceFW::WRITE,
                           iv_pI2cMaster,
                           reinterpret_cast<void*>(op.vData.data()),
                           size,
                           DEVICE_I2C_SMBUS_WORD(iv_i2cInfo.engine,
                                                 iv_i2cInfo.port,
                                                 iv_i2cInfo.devAddr,
                                                 op.cmd,
                                                 iv_i2cInfo.i2cMuxBusSelector,
                                                 &iv_i2cInfo.i2cMuxPath));

                if (err)
                {
                    TRACFCOMP(g_trac_ucd,ERR_MRK"updateUcdFlash: op=%d: %s: "
                          "DEVICE_I2C_SMBUS_WORD Failed: err plid=0x%.8X. "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, data=0x%.2X "
                          "0x%.2X, pec=0x%.2X", op_count, op_type, err->plid(),
                          op.addr, op.cmd, op.vData.size(), op.vData[0],
                          op.vData[1], op.pec_byte);
                    break;
                }
                assert(size==expSize, "updateUcdFlash: DEVICE_I2C_SMBUS_WORD size mismatch: returned %d, but expected %d",
                       size, expSize);
            }
            else if (strcmp(op_type,"BlockWrite") == 0)
            {
                // Convert the other fields to address, command, and data
                convertStringToOp(tmp_str, op);

                // Flash image file for BlockWrite has length as the first data
                // element, but that element should not get passed into the
                // I2C Device Driver calls as it already calculates the proper
                // length based on what is being passed in.  Also, this element
                // needs to be removed so that the I2C DD can calculate the PEC
                // byte correctly.
                op.vData.erase(op.vData.begin());

                TRACUCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, data0=0x%.2X, "
                          "pec=0x%X", op_count, op_type, op.addr, op.cmd,
                          op.vData.size(), op.vData[0], op.pec_byte);

                size = op.vData.size();
                expSize = size;

                err = deviceOp(DeviceFW::WRITE,
                           iv_pI2cMaster,
                           reinterpret_cast<void*>(op.vData.data()),
                           size,
                           DEVICE_I2C_SMBUS_BLOCK(iv_i2cInfo.engine,
                                                  iv_i2cInfo.port,
                                                  iv_i2cInfo.devAddr,
                                                  op.cmd,
                                                  iv_i2cInfo.i2cMuxBusSelector,
                                                  &iv_i2cInfo.i2cMuxPath));

                if (err)
                {
                    TRACFCOMP(g_trac_ucd,ERR_MRK"updateUcdFlash: op=%d: %s: "
                          "DEVICE_I2C_SMBUS_BLOCK Failed. err plid=0x%.8X. "
                          "addr=0x%.2X, cmd=0x%.2X data_size=%d, data0=0x%.2X, "
                          "pec=0x%X", op_count, op_type, err->plid(), op.addr,
                          op.cmd, op.vData.size(), op.vData[0], op.pec_byte);
                    break;
                }
                assert(size==expSize, "updateUcdFlash: DEVICE_I2C_SMBUS_BLOCK size mismatch: returned %d, but expected %d",
                       size, expSize);
            }
            else if (strcmp(op_type,"SendByte") == 0)
            {
                // Second Field is Address
                pDelimiter = strchr(tmp_str, ',' );
                if (pDelimiter != nullptr)
                {
                    *pDelimiter = '\0';
                }
                else
                {
                    assert(false,"updateUcdFlash: SendByte: pDelimiter for 2nd field is nullptr");
                }
                uint64_t addr = strtoul(tmp_str, nullptr, 16);

                // Move Past Second Field
                tmp_str = pDelimiter+1;

                // Third Field is Command and ends with a nullptr already
                uint8_t cmd = strtoul(tmp_str, nullptr, 16 );

                // There is no additional data, which is why convertStringToOp()
                // is not being used
                TRACUCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s: "
                          "addr=0x%.2X, cmd=0x%.2X",
                          op_count, op_type, addr, cmd);

                // For this operation, the 'cmd' is the actual data sent, but
                // we use the following API without the cmd field
                size = sizeof(uint8_t);
                expSize = size;

                err = deviceOp(DeviceFW::WRITE,
                           iv_pI2cMaster,
                           &cmd,
                           size,
                           DEVICE_I2C_SMBUS_SEND_OR_RECV(iv_i2cInfo.engine,
                                                  iv_i2cInfo.port,
                                                  iv_i2cInfo.devAddr,
                                                  iv_i2cInfo.i2cMuxBusSelector,
                                                  &iv_i2cInfo.i2cMuxPath));

                if (err)
                {
                    TRACFCOMP(g_trac_ucd,ERR_MRK"updateUcdFlash: op=%d: %s: "
                          "DEVICE_I2C_SMBUS_SEND_OR_RECV Failed. err plid="
                          "0x%.8X. addr=0x%.2X, cmd=0x%.2X",
                          op_count, op_type, err->plid(), op.addr, op.cmd);
                    break;
                }
                assert(size==expSize, "updateUcdFlash: DEVICE_I2C_SMBUS_SEND_OR_RECV size mismatch: returned %d, but expected %d",
                       size, expSize);
            }
            else if (strcmp(op_type,"Pause") == 0)
            {
                // 2nd field is decimal value of ms to wait
                pDelimiter = strchr(tmp_str, ',' );
                if (pDelimiter != nullptr)
                {
                    *pDelimiter = '\0';
                }
                else
                {
                    assert(false,"updateUcdFlash: Pause: pDelimiter for 2nd field is nullptr");
                }

                // NOTE: Hostboot's implementation of strtoul only supports
                // base 16 so have to do this in a clunky way
                uint64_t sleep_ms = 0;

                while (*tmp_str != '\0')
                {
                    // Another numeral found so shift previous result
                    // by multiplying by 10 and then add in the current
                    // value, where *tmp_str will be in ASCII so you need
                    // to subtract ASCII '0' which is 0x30
                    sleep_ms = (10 * sleep_ms) + (*(tmp_str++) - 0x30);
                }

                // Important to trace this pause so users know why there is a
                // gap in the trace output
                TRACFCOMP(g_trac_ucd,"updateUcdFlash: op=%d: %s: "
                          "Sleep for %d ms", op_count, op_type, sleep_ms);
                nanosleep(0, sleep_ms * NS_PER_MSEC);
            }
            else
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK"updateUcdFlash: op=%d: "
                          "Unrecognized Requested Operation: %s",
                          op_count, op_type);

                /*@
                 * @errortype
                 * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @reasoncode UCD_RC::UCD_UNSUPPORTED_OPERATION_REQUEST
                 * @moduleid   UCD_RC::MOD_UPDATE_UCD_FLASH_IMAGE
                 * @userdata1  HUID of UCD Target
                 * @userdata2  The order of the operation
                 * @devdesc    The UCD flash image commandline is not supported
                 * @custdesc   Unexpected IPL firmware data format error
                 */
                err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    UCD_RC::MOD_UPDATE_UCD_FLASH_IMAGE,
                    UCD_RC::UCD_UNSUPPORTED_OPERATION_REQUEST,
                    TARGETING::get_huid(iv_pUcd),
                    op_count,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                ERRORLOG::ErrlUserDetailsString(op_type).addToLog(err);
                break;
            }

            // Set up tmp_str for next op
            ++op_count;
            tmp_str = next_op;

        }  // end of while loop

        if (err)
        {
            err->collectTrace(UCD_COMP_NAME);
        }


        TRACFCOMP(g_trac_ucd,"updateUcdFlash: End of op loop: "
                  "op_count=%d, char_count=%d, total=%d): %s",
                  op_count, char_count, i_size,
                  err ? "ERROR" : "No Error")

        return err;

    } // end of updateUcdFlash()


    /*
     * @brief                     Gets the Device ID from the UCD member of this
     *                            class.
     *
     * @return                    A constant pointer to the device id string.
     *
     */
    const char* getDeviceId() const
    {
        return iv_deviceId;
    }

    /* @brief                     Gets the MFR Revision from the UCD member
     *                            of this class.
     *
     * @return                    The ASCII MFR revision as a uint16_t.
     */
    uint16_t getMfrRevision() const
    {
        return iv_mfrRevision;
    }

}; // end of class Ucd

/**
 *  @brief Header for the UCD flash image content
 */
struct TocHeader
{
    uint64_t eyecatcher;   //< Eyecatcher, see TOC_CONSTS::EYECATCHER
    uint32_t majorVersion; //< Major header version; increases for incompatible
                           //< changes
    uint32_t minorVersion; //< Minor version; increases for compatible changes
                           //< relative to a major version
    uint32_t tocEntries;   //< Number of TOC entries
    uint32_t tocEntrySize; //< Size of TOC entry in bytes
    uint32_t tocOffset;    //< Offset of 0th TOC entry from beginning of
                           //< flash image

    /**
     *  @brief TOC header constructor
     */
    TocHeader()
        : eyecatcher(0),
          majorVersion(0),
          minorVersion(0),
          tocEntries(0),
          tocEntrySize(0),
          tocOffset(0)
    {
    }
};

/**
 *  @brief Enumeration of UCD sub-flash image types
 */
enum IMAGE_TYPE : uint8_t
{
    DATA_FLASH_IMAGE = 0x00, ///< UCD data sub-flash image
    UNKNOWN          = 0xFF, ///< Unknown UCD sub-flash image type
};

/**
 *  @brief Miscellaneous constants used by the UCD flash image TOC and TOC
 *      entries
 */
enum TOC_CONSTS : uint64_t
{
    EYECATCHER                = 0x554344464C534800ULL, //< UCDFLSH + 0x00
    DEVICE_ID_NULL_BYTE_INDEX = 31, //< Max size of device ID not including NULL
    DEVICE_ID_MAX_SIZE        = DEVICE_ID_NULL_BYTE_INDEX+1, //< Max size of
                                                             //< device ID
    CURRENT_VERSION           = 0x01, //< First supported version is 0x01
};

/**
 *  @brief Table of contents entry used by UCD flash image
 */
struct TocEntry
{
    char       deviceId[DEVICE_ID_MAX_SIZE]; //< NULL terminated ASCII device ID
                                             //< string
    IMAGE_TYPE imageType;    //< Type of sub-flash image
    uint8_t    procPosition; //< Position of processor acting as I2C master
    uint8_t    i2cEngine;    //< Engine driving the I2C device relative to
                             //< the I2C master target
    uint8_t    i2cPort;      //< Port driving the I2C device relative to its
                             //< engine
    uint8_t    i2cAddress;   //< I2C address the device responds at
    uint8_t    reserved1;    //< Reserved for future use
    uint16_t   mfrRevision;  //< A vendor supplied set of two ASCII
                             //< bytes which versions the flash content.
                             //< Hostboot updates the device's flash image
                             //< whenever the MFR_REVISION of the device differs
                             //< from the one in the TOC entry.
    uint32_t   imageOffset;  //< Offset of sub-flash image from start of flash
                             //< image, in bytes
    uint32_t   imageSize;    //< Size of sub-flash image, in bytes

    /**
     *  TOC entry constructor
     */
    TocEntry()
        : imageType(UNKNOWN),
          procPosition(0),
          i2cEngine(0),
          i2cPort(0),
          i2cAddress(0),
          reserved1(0),
          mfrRevision(0),
          imageOffset(0),
          imageSize(0)
    {
        memset(deviceId,0x00,sizeof(deviceId));
    }
};

errlHndl_t updateAllUcdFlashImages(
    const TARGETING::TargetHandleList& i_powerSequencers,
          UtilMem&                     i_image)
{
    TRACFCOMP(g_trac_ucd, ENTER_MRK
              "updateAllUcdFlashImages: # UCDs = %d",
              i_powerSequencers.size());

    errlHndl_t pError = nullptr;

    do {

    // Read in the critical portions of the header
    TocHeader header;
    i_image.read(&header.eyecatcher,sizeof(header.eyecatcher));
    i_image >> header.majorVersion >> header.minorVersion;
    pError=i_image.getLastError();
    if(pError)
    {
        TRACFCOMP(g_trac_ucd,ERR_MRK
            "updateAllUcdFlashImages: Failed to read enough data from UCD "
            "flash image to populate the minor version in the TOC header. "
            "Image size reported as %d",i_image.size());
        break;
    }

    // Validate eyecatcher, major, minor
    if(header.eyecatcher != EYECATCHER)
    {
        TRACFCOMP(g_trac_ucd,ERR_MRK
            "updateAllUcdFlashImages: UCD flash image has bad eyecatcher; "
            "Expected 0x%16llX but found 0x%016llX",
            EYECATCHER,header.eyecatcher);
        /*@
         * @errortype
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @reasoncode UCD_RC::UCD_INVALID_EYECATCHER
         * @moduleid   UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES
         * @userdata1  Expected eyecatcher
         * @userdata2  Actual eyecatcher
         * @devdesc    The UCD flash image's eyecatcher did not match
         *     the expected value
         * @custdesc   Unexpected IPL firmware data format error
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES,
            UCD_RC::UCD_INVALID_EYECATCHER,
            EYECATCHER,
            header.eyecatcher,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    if(header.majorVersion != CURRENT_VERSION)
    {
        TRACFCOMP(g_trac_ucd,ERR_MRK
            "updateAllUcdFlashImages: UCD flash image version not supported. "
            "Image version is 0x%08X but boot firmware only supports 0x%08X",
            header.majorVersion,
            CURRENT_VERSION);
        /*@
         * @errortype
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @reasoncode UCD_RC::UCD_INVALID_MAJOR_VER
         * @moduleid   UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES
         * @userdata1  Current major version supported
         * @userdata2  Advertised major version
         * @devdesc    The UCD flash image's major version number is
         *     not supported.
         * @custdesc   Unexpected IPL firmware data format error
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES,
            UCD_RC::UCD_INVALID_MAJOR_VER,
            CURRENT_VERSION,
            header.majorVersion,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // Placeholder for future minor version checks.  Currently should
    // be able to handle any minor version when major version is 1

    // Read in the TOC info
    i_image >> header.tocEntries >> header.tocEntrySize >> header.tocOffset;
    pError=i_image.getLastError();
    if(pError)
    {
        TRACFCOMP(g_trac_ucd,ERR_MRK
            "updateAllUcdFlashImages: Failed to read enough data from UCD "
            "flash image to populate full TOC header");
        break;
    }

    // Each TOC entry should be at least the size of the entry that major
    // version 1 knows about.  This code can, however, handle larger entries if
    // needed
    if(header.tocEntrySize < sizeof(TocEntry))
    {
        TRACFCOMP(g_trac_ucd,ERR_MRK
            "updateAllUcdFlashImages: TOC entry size %d smaller than minimum "
            "of %d",
            header.tocEntrySize, sizeof(TocEntry));
        /*@
         * @errortype
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @reasoncode UCD_RC::UCD_TOC_ENTRY_TOO_SMALL
         * @moduleid   UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES
         * @userdata1  Minimum required TOC entry size
         * @userdata2  Advertised TOC entry size
         * @devdesc    The UCD flash image's TOC entry size is smaller
         *     than expected.
         * @custdesc   Unexpected IPL firmware data format error
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES,
            UCD_RC::UCD_TOC_ENTRY_TOO_SMALL,
            sizeof(TocEntry),
            header.tocEntrySize,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // Check to see if each power sequencer needs to be updated
    for(auto powerSequencer : i_powerSequencers)
    {
        const auto model = powerSequencer->getAttr<TARGETING::ATTR_MODEL>();

        do {

        // If we ever let new UCDs into the object model of a type
        // not supported, we'd want to introduce some attribute here
        // indicating if it supports firmware update/etc.  For now
        // the model only has UCDs that can be updatable.

        const auto i2cInfo =
            powerSequencer->getAttr<TARGETING::ATTR_I2C_CONTROL_INFO>();

        const char* pMasterPath = i2cInfo.i2cMasterPath.toString();
        TRACFCOMP(g_trac_ucd, INFO_MRK
            "updateAllUcdFlashImages: Found functional power sequencer: "
            "HUID = 0x%08X, Model = 0x%08X, I2C master = %s, "
            "e/p/a = %d/%d/0x%02X",
            TARGETING::get_huid(powerSequencer),
            model,
            pMasterPath, i2cInfo.engine, i2cInfo.port, i2cInfo.devAddr);
        free(const_cast<char*>(pMasterPath));
        pMasterPath = nullptr;

        auto pI2cMasterTarget =
            TARGETING::targetService().toTarget(i2cInfo.i2cMasterPath);
        assert(pI2cMasterTarget != nullptr,"nullptr I2C master target for UCD "
            "with HUID of 0x%08X",
            TARGETING::get_huid(powerSequencer));

        // Check that pI2cMasterTarget is functional because otherwise the UCD
        // can't be accessed
        TARGETING::HwasState l_hwasState =
            pI2cMasterTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if (l_hwasState.functional != true)
        {
            TRACFCOMP(g_trac_ucd, INFO_MRK
            "updateAllUcdFlashImages: Skipping update on power sequencer HUID "
            "= 0x%08X because its I2C Master HUID = 0x%08X is non-functional",
            TARGETING::get_huid(powerSequencer),
            TARGETING::get_huid(pI2cMasterTarget));

            break;
        }

        const auto position = pI2cMasterTarget->
            getAttr<TARGETING::ATTR_POSITION>();

        // @TODO RTC 205982 Reset UCD if needed to put it in a good state

        Ucd ucd(powerSequencer);
        pError=ucd.initialize();
        if(pError)
        {
            TRACFCOMP(g_trac_ucd,ERR_MRK
                "updateAllUcdFlashImages: Failed in Ucd::initialize() for UCD "
                "with HUID of 0x%08X",
                TARGETING::get_huid(powerSequencer));
            // @TODO: RTC 205982 mark non-functional, more FFDC
            pError->collectTrace(UCD_COMP_NAME);
            errlCommit(pError,UCD_COMP_ID);
            break;
        }

        const auto* const deviceId = ucd.getDeviceId();

        const auto mfrRevision = ucd.getMfrRevision();

        i_image.seek(header.tocOffset,UtilStream::START);

        for(size_t entry = 0 ; entry < header.tocEntries; ++entry)
        {
            bool nextUcd=false;

            do {

            TocEntry tocEntry;
            i_image.read(&tocEntry,sizeof(TocEntry));
            pError=i_image.getLastError();
            if(pError)
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK
                    "updateAllUcdFlashImages: Failed to read enough data from "
                    "UCD flash image to populate TOC entry %d. ",
                    entry);
                break;
            }

            if(   (tocEntry.procPosition != position)
               || (tocEntry.i2cEngine    != i2cInfo.engine)
               || (tocEntry.i2cPort      != i2cInfo.port)
               || (tocEntry.i2cAddress   != i2cInfo.devAddr))
            {
                // Did not find the UCD, move on to next TOC entry
                break;
            }

            // No matter what, last byte has to be 0 to prevent runaway
            // parsing
            tocEntry.deviceId[DEVICE_ID_NULL_BYTE_INDEX] = 0x00;

            if(strncmp(tocEntry.deviceId,deviceId,
               sizeof(tocEntry.deviceId))!=0)
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK
                    "updateAllUcdFlashImages: Mismatched device ID for UCD "
                    "with HUID of 0x%08X. "
                    "Expected device ID %s, got device ID of %s",
                    TARGETING::get_huid(powerSequencer),
                    tocEntry.deviceId,deviceId);
                /*@
                 * @errortype
                 * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @reasoncode UCD_RC::UCD_UNSUPPORTED_DEVICE_ID
                 * @moduleid   UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES
                 * @userdata1  UCD's HUID
                 * @devdesc    The UCD device's device ID did not match the
                 *     expected device ID from the UCD sub-flash image.  This
                 *     likely implies an escape of new parts into systems
                 *     that are not supported by firmware.  UCD will be
                 *     marked as non-functional.
                 * @custdesc   Unsupported device found during firmware IPL
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES,
                    UCD_RC::UCD_UNSUPPORTED_DEVICE_ID,
                    TARGETING::get_huid(powerSequencer),
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                ERRORLOG::ErrlUserDetailsStringSet deviceIds;
                deviceIds.add("Expected device ID",tocEntry.deviceId);
                deviceIds.add("Actual device ID",deviceId);
                deviceIds.addToLog(pError);
                // @TODO: RTC 205982 set non-functional, deconfig
                pError->collectTrace(UCD_COMP_NAME);
                errlCommit(pError,UCD_COMP_ID);
                nextUcd=true;
                break;
            }

            if(tocEntry.mfrRevision == mfrRevision)
            {
               TRACFCOMP(g_trac_ucd,INFO_MRK
                    "updateAllUcdFlashImages: Device has MFR revision of "
                    "0x%04X which matches incoming UCD sub-flash image "
                    "version, so inhibit flash update",
                    mfrRevision);
                nextUcd=true;
                break;
            }
            else
            {
              TRACFCOMP(g_trac_ucd,INFO_MRK
                    "updateAllUcdFlashImages: Device has different MFR revision"
                    " (0x%04X) than the incoming UCD sub-flash image "
                    "version (0x%04X), so perform flash update",
                    mfrRevision, tocEntry.mfrRevision);
            }

            // Turns out doing the check via UtilMem is not that easy,
            // so for feeding the image to the updater, use manual
            // calculation
            if(tocEntry.imageOffset+tocEntry.imageSize > i_image.size())
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK
                    "updateAllUcdFlashImages: UCD sub-flash image exceeds "
                    "upper boundary of UCD flash image. Offset=0x%08X, "
                    "size=0x%08X, lID size = 0%08X",
                    tocEntry.imageOffset,tocEntry.imageSize,i_image.size());
                /*@
                 * @errortype
                 * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @reasoncode UCD_RC::UCD_EOF
                 * @moduleid   UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES
                 * @userdata1  UCD's HUID
                 * @devdesc    Advertised UCD sub-flash image offset+size would
                 *     pass the end of the UCD flash image.
                 * @custdesc   Unexpected boot firmware data format error
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    UCD_RC::MOD_UPDATE_ALL_UCD_FLASH_IMAGES,
                    UCD_RC::UCD_EOF,
                    TARGETING::get_huid(powerSequencer),
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            // Either way we'll be advancing to next UCD after the update
            // attempt
            nextUcd=true;

            // Update the UCD data flash
            pError = ucd.updateUcdFlash(
                           reinterpret_cast<const uint8_t*>(i_image.base())
                             + tocEntry.imageOffset,
                           tocEntry.imageSize);
            if(pError)
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK
                    "updateAllUcdFlashImages: Failed in call to "
                    "updateUcdFlash for UCD with HUID of "
                    " 0x%08X.",
                    TARGETING::get_huid(powerSequencer));
                // @TODO: RTC 205982  Deconfigure UCD, call it out, etc.
                pError->collectTrace(UCD_COMP_NAME);
                errlCommit(pError,UCD_COMP_ID);
                break;
            }

            pError = ucd.verifyUpdate();
            if(pError)
            {
                TRACFCOMP(g_trac_ucd,ERR_MRK
                    "updateAllUcdFlashImages: Failed in call to "
                    "Ucd::verifyUpdate() for UCD with HUID of "
                    " 0x%08X.",
                    TARGETING::get_huid(powerSequencer));
                pError->collectTrace(UCD_COMP_NAME);
                errlCommit(pError,UCD_COMP_ID);
            }

            TRACFCOMP(g_trac_ucd,INFO_MRK
                "updateAllUcdFlashImages: Successfully updated UCD "
                "with HUID of 0x%08X.",
                TARGETING::get_huid(powerSequencer));

            } while(0); // End do/while processing individual TOC entry

            if(pError || nextUcd)
            {
                break;
            }

            // Eat the delta between end of our TOC entry knowledge and the
            // indicated TOC size
            i_image.seek(header.tocEntrySize-sizeof(TocEntry),
                         UtilStream::CURRENT);

        } // End for loop searching for matching TOC entry

        if(pError)
        {
            break;
        }

        // If failed to find TOC entry ...

        } while(0); // End do/while processing individual power sequencer

        if(pError)
        {
            break;
        }


    } // End loop through all power sequencers

    } while(0);

    // Seek back to the beginning so caller gets identical state back
    i_image.seek(0,UtilStream::START);

    TRACFCOMP(g_trac_ucd, EXIT_MRK
              "updateAllUcdFlashImages");

    return pError;
}

} // End namespace UCD

} // End namespace TI

} // End namespace POWER_SEQUENCER
