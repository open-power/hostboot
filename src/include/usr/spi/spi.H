/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/spi/spi.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

#ifndef __SPI_H
#define __SPI_H

/**
 *
 * @file spi.H
 *
 * @brief Provides the interfaces for the Serial Peripheral Interface (SPI)
 *        related functions. For the device driver interface, see spidd.H
 *
 */

#include <vector>
#include <stdint.h>

namespace TARGETING
{
class Target;
}

// Forward Declaration of HDAT SPI Device Info Structure
namespace HDAT
{
    struct hdatSpiDevData_t;
};

namespace SPI
{

struct spiEepromScomInfo
{
    enum scom_address_t : uint64_t
    {
        SCOM_ADDRESS_NOT_APPLICABLE = 0
    };

    uint64_t scomAddress = SCOM_ADDRESS_NOT_APPLICABLE;

    enum scom_bit_position_t : uint8_t
    {
        SCOM_BIT_INVALID = 0xFF
    };

    // This field designates the bit that controls security for this device, as
    // an offset from the most-significant bit. Range of values is 0-63, or
    // SCOM_PROTECTION_INVALID. Not valid when scomAddress equals
    // SCOM_ADDRESS_NOT_APPLICABLE.
    uint8_t secureBitPosition = SCOM_BIT_INVALID;

    enum polarity_t : uint8_t
    {
        POLARITY_0_LOCKED = 0,
        POLARITY_1_LOCKED = 1
    };

    // This field designates the value of the bit given by
    // scomReadAccessControlBitPosition in the deviceScomAddress register when
    // the eeprom range protection is active. Only valid when
    // scomAccessControlBitPosition is not SCOM_PROTECTION_INVALID.
    polarity_t bitPolarity = POLARITY_1_LOCKED;

    bool sticky = true;
};

/* The info contained in this structure is described in the Hypervisor Interface
 * Data Specification. */
struct spiEepromPartition
{
    enum class partitionPurpose_t : uint32_t
    {
        MODULE_VPD_PRIMARY            = 0x01,
        MODULE_VPD_SECONDARY          = 0x02,
        SBE_BOOT_SEEPROM_PRIMARY      = 0x03,
        SBE_BOOT_SEEPROM_SECONDARY    = 0x04,
        MEASUREMENT_SEEPROM_PRIMARY   = 0x05,
        MEASUREMENT_SEEPROM_SECONDARY = 0x06,
        WOF_DATA                      = 0x07,
        KEYSTORE_HB                   = 0x08,
        KEYSTORE_PHYP                 = 0x09,
        KEYSTORE_OPAL_VAR_BANK_0      = 0x0A,
        KEYSTORE_OPAL_VAR_BANK_1      = 0x0B,
        KEYSTORE_OPAL_QUEUE           = 0x0C,

        UNKNOWN                       = 0xFF
    };

    partitionPurpose_t partitionPurpose = partitionPurpose_t::UNKNOWN;

    enum deviceOffset_t : uint32_t
    {
        DEVICE_OFFSET_NOT_APPLICABLE = 0xFFFFFFFFu
    };

    uint32_t offsetBytes = deviceOffset_t::DEVICE_OFFSET_NOT_APPLICABLE;
    uint32_t sizeBytes = 0;

    spiEepromScomInfo readAccessControl;
    spiEepromScomInfo writeAccessControl;
};

struct spiSlaveDevice
{
    union spiDeviceId
    {
        /*
          SPI device ID – This is a unique number for each SPI device entry which
          can be used as cross reference in other structures.
        */
        uint32_t word = 0;

        struct
        {
            // Byte 0 : System level Ordinal ID of Node (0..3)
            uint8_t nodeOrdinal;
            // Byte 1 : Node level Processor Sequence ID (0..3)
            uint8_t procId;
            // Rolling counter, unique to each physical SPI device.
            uint16_t uniqueId;
        };
    };

    // This is a unique number for each SPI device entry which can
    // be used as cross reference in other structures.
    spiDeviceId deviceId;

    uint8_t masterEngine = 0;
    uint8_t masterPort = 0;
    uint32_t busSpeedKhz = 0;

    enum class slaveDeviceType_t : uint8_t
    {
        TCG_SPI_TPM               = 0x01,
        SEEPROM_MICROCHIP_25CSM04 = 0x02,

        UNKNOWN                   = 0xFF
    };

    slaveDeviceType_t deviceType = slaveDeviceType_t::UNKNOWN;

    enum class slaveDevicePurpose_t : uint8_t
    {
        TPM     = 0x01,
        SEEPROM = 0x02,

        UNKNOWN = 0xFF
    };

    slaveDevicePurpose_t devicePurpose = slaveDevicePurpose_t::UNKNOWN;

    /*
      SLCA Index of the FRU on which this SPI device is residing (Only
      applicable to FSP based systems). Value is set to zero for BMC based
      systems.
    */
    uint16_t residentFruSlcaIndex = 0;

    std::vector<spiEepromPartition> partitions;

    struct deviceDescription_t
    {
        /*
          Null terminated strings describing the SPI device

          Format for SEEPROMS:
            <Vendor>, <device type>,<data type>,<hw subsystem>
          Format for TPM:
            <vendor>,<device type>,<purpose>,<scope>
        */

        /* These are NON-owning pointers and the strings are statically allocated;
         * client does not need to deallocate them. */
        const char* vendor = nullptr,
                  * deviceType = nullptr,
                  * dataTypeOrPurpose = nullptr,
                  * hwSubsystemOrScope = nullptr;
    };

    deviceDescription_t description;
};

// A functor that compares two spi devices to determine if they are the same device.
class CompareSlaveDevice
{
private:
    // Internal tracking for device to compare against. Useful when passing functor to std::find_if, etc.
    spiSlaveDevice iv_device;

public:

    // @brief Constructor that extracts required info from HDAT representation of SPI Slave Device Info
    CompareSlaveDevice(const HDAT::hdatSpiDevData_t*& i_hdatSpiDevInfo);

    // @brief Constructor that stores passed spiSlaveDevice as device to compare others against
    CompareSlaveDevice(const spiSlaveDevice& i_spiDevInfo);

    // @brief Used to compare the given SPI device to the internally held one.
    //
    // @param[in]  i_spiDevice    A spiSlaveDevice to be compared to internal member.
    //
    // @return   bool             TRUE: If spi devices are the same. That is to say, many unique fields between
    //                                  the two devices are the same.
    //                            FALSE: Not enough uniquely indentifiable info matches.
    bool operator()(const spiSlaveDevice& i_spiDevice);

    // @brief Used to compare one SPI device to another to see if they are the same
    //
    // @param[in]  i_spiDevice1   A spiSlaveDevice
    // @param[in]  i_spiDevice2   Another spiSlaveDevice to be compared to first.
    //
    // @return   bool             TRUE: If spi devices are the same. That is to say, many unique fields between
    //                                  the two devices are the same.
    //                            FALSE: Not enough uniquely indentifiable info matches.
    bool operator()(const spiSlaveDevice& i_spiDevice1, const spiSlaveDevice& i_spiDevice2);
};

/**
 * @brief getSpiDeviceInfo
 *
 *        Retrieve info about each SPI device in the system and add it
 *        to the given list.
 *
 * param[out] o_deviceInfo      The list to store SPI device info in
 * param[in]  i_spiMaster       The SPI master target to query for devices
 *                              (use nullptr for all devices in system)
 */
void getSpiDeviceInfo(std::vector<spiSlaveDevice>& o_deviceInfo,
                      TARGETING::Target* i_spiMaster = nullptr);

/**
 * @brief spiAccess_t
 *        SPI access can be either FSI/CFAM or PIB
 */
enum spiAccess_t : uint8_t
{
    FSI_ACCESS = 0,
    PIB_ACCESS = 1
};

/**
 *  @brief Configures a SPI engine for use.  Currently updates the given SPI
 *      engine's clock config register for FSI SPI engines only.  It will lock
 *      SPI access to the given processor, init the engine, and release the
 *      locks.  ATTR_SCOM_SWITCHES will control whether the FSI or PIB engine
 *      will be initialized.
 *
 *  @param[in] i_pProc Processor target to initialize the SPI engine on
 *  @param[in] i_engine SPI engine to init
 *
 *  @return errlHndl_t nullptr on success, otherwise valid error log handle
 */
errlHndl_t spiInitEngine(
          TARGETING::Target* i_pProc,
    const uint8_t            i_engine);

/**
 * @brief spiSetAccessMode
 *
 *        Change the access method used by SPI for the given processor.
 *        This will grab locks for the processor, update SPI ROOT_CTRL_8
 *        register to new access method, update ATTR_SPI_SWITCHES,
 *        and then unlock.
 *        Subsequent SPI operations to this processor will use this
 *        new access method
 *
 *        Note that this function will not switch the main boot seeprom
 *        to FSI mode, but setting the method type to PIB will switch
 *        all engines to PIB mode
 *
 * @param[in] i_spiMasterProc   SPI master processor to associate access method
 * @param[in] i_type  Access method type (FSI or PIB)
 * @return  error if access change failed
 */
errlHndl_t spiSetAccessMode(TARGETING::Target * i_spiMasterProc,
                            spiAccess_t i_type);


/**
 * @brief spiLockProcessor
 *
 *        Prevent Hostboot from using this target by grabbing lock.
 *        Release the lock when it is safe to resume SPI operations.
 *
 * @param[in] i_processor   SPI processor to lock/unlock
 * @param[in] i_lock        true = lock, false = unlock
 * @return error if lock operation failed
 */
errlHndl_t spiLockProcessor(TARGETING::Target * i_processor, bool i_lock);

/**
 * @brief spiPresence
 *
 *        Determines presence of SPI EEPROMs by reading the manufacturer id and if there is no error and the id isn't all zeroes
 *        then the EEPROM is considered present.
 *
 * @param[in]  i_target       SPI processor to attempt presence detection on
 * @param[in]  i_engine       The engine to attempt presence detection on. Only supports MVPD engines (2 & 3)
 * @param[out] o_present      TRUE: EEPROM is present
 *                            FALSE: EEPROM is not present or an error occurred during attempted detection.
 *
 * @return errlHndl_t         nullptr or an error log if an error occurred.
 */
errlHndl_t spiPresence(TARGETING::Target* i_target,
                       uint8_t            i_engine,
                       bool&              o_present);

}

#endif
