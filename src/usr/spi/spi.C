/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spi.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

/**
 *
 * @file spi.C
 *
 * @brief Provides the implementation for the Serial Peripheral Interface (SPI)
 *        related functions. For the device driver implementation, see spidd.C
 *
 */

// Standard includes
#include <map>

// Trace
#include <trace/interface.H>

// Targeting
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>
#include <targeting/common/predicates/predicates.H>

// Initservice
#include <initservice/taskargs.H>

// SPI
#include <spi/spi.H>

// Max node and proc constants from these headers
#include <sys/internode.h>
#include <sys/misc.h>

// Numerical conversions
#include <conversions.H>

// SCOM addresses/bitfields
#include <p10_scom_perv_8.H>

using namespace TARGETING;
using namespace SPI;
using namespace UTIL;
using namespace CONVERSIONS;
using namespace scomt::perv;

extern trace_desc_t* g_trac_spi;

namespace
{

/* @brief calcSpiSlavePartitionDescription
 *
 *        Populates the description for the given spiSlaveDevice
 *
 * @param[in/out] io_deviceInfo  The device to calculate the name for
 */
void calcSpiDeviceDescription(spiSlaveDevice& io_deviceInfo)
{
    const char* vendor = "unknown",
              * deviceType = "unknown",
              * dataTypeOrPurpose = "unknown",
              * hwSubsystemOrScope = "unknown";

    using slaveDeviceType_t = spiSlaveDevice::slaveDeviceType_t;

    switch (io_deviceInfo.deviceType)
    {
    case slaveDeviceType_t::SEEPROM_MICROCHIP_25CSM04:
        vendor = "microchip";
        deviceType = "25CSM04";
        dataTypeOrPurpose = "seeprom";
        hwSubsystemOrScope = "processor";
        break;
    case slaveDeviceType_t::TCG_SPI_TPM:
        vendor = "tcg";
        deviceType = "tpm_tis-spi";
        dataTypeOrPurpose = "tpm";
        hwSubsystemOrScope = "host";
        break;
    case slaveDeviceType_t::UNKNOWN:
        break;
    default:
        TRACFCOMP(g_trac_spi,
                  ERR_MRK"calcSpiDeviceDescription: Unknown SPI deviceType 0x%08x",
                  io_deviceInfo.deviceType);
        break;
    }

    io_deviceInfo.description.vendor = vendor;
    io_deviceInfo.description.deviceType = deviceType;
    io_deviceInfo.description.dataTypeOrPurpose = dataTypeOrPurpose;
    io_deviceInfo.description.hwSubsystemOrScope = hwSubsystemOrScope;
}

/* @brief lbusFrequencyHz
 *
 *        Calculates the frequency of the LBUS in hertz, used in calculating the
 *        SPI bus frequency
 *
 * @returns uint64_t  LBUS frequency
 */
uint64_t lbusFrequencyHz()
{
    // pib_frequency = nest_frequency / 4           (nest frequency comes from FREQ_PAU_MHZ)
    // local_bus_frequency = pib_frequency / 2      [P10]
    static const int NEST_LBUS_FREQ_RATIO = 8;

    return
        assertGetToplevelTarget()->getAttr<TARGETING::ATTR_FREQ_PAU_MHZ>()
        * HZ_PER_MHZ
        / NEST_LBUS_FREQ_RATIO;
}

/* @brief spiSerialClock
 *
 *        Calculates the frequency of the SPI serial clock
 *
 * @param[in] i_lbusFreq   Frequency of LBUS
 * @param[in] i_sckDivider The SPI serial clock divider
 * @returns uint64_t       SPI SCK frequency
 */
uint64_t spiSerialClock(const uint64_t i_lbusFreq, const uint64_t i_sckDivider)
{
    // This formula is from the P10 SPI Pervasive Workbook, section "Clock
    // Configuration, Trace Select, Reset Control, ECC Enable".
    return i_lbusFreq / (2 * (i_sckDivider + 1));
}

/*
  There are a bunch of SPI_*_INFO attributes that all have the same structure,
  but each attribute gets its own C struct so they're technically different
  types. To maintain type-safety but also be able to write code to handle them
  generically, we have this genericSpiInfo struct, and its templated constructor
  converts each attribute-specific struct into this one.
*/
struct genericSpiInfo
{
    template<typename T>
    genericSpiInfo(const T& i_spiInfo)
    {
        static_assert(sizeof(T) == sizeof(genericSpiInfo),
                      "Cannot convert type to genericSpiInfo");

        spiMasterPath = i_spiInfo.spiMasterPath;
        engine = i_spiInfo.engine;
        dataOffsetKB = i_spiInfo.dataOffsetKB;
        dataSizeKB = i_spiInfo.dataSizeKB;
        eepromContentType = i_spiInfo.eepromContentType;
    }

    EntityPath spiMasterPath;
    uint8_t engine;
    uint16_t dataOffsetKB;
    uint16_t dataSizeKB;
    uint8_t eepromContentType;
} PACKED;

/* @brief collectSpiSlavePartitionInfo
 *
 *        Collects information about a spiEepromPartition from an attribute that
 *        contains the information.
 *
 * @param[in] i_sourceAttribute  The attribute ID that i_spiinfo was obtained from
 * @param[in] i_spiinfo          An attribute structure describing an SPI device (e.g.
 *                               the value of ATTR_SPI_EEPROM_VPD_PRIMARY_INFO)
 * @param[in] i_device           The device to which this partition belongs
 * @returns spiEepromPartition   The slave partition described by i_spiinfo
 */
spiEepromPartition collectSpiSlavePartitionInfo(const ATTRIBUTE_ID i_sourceAttribute,
                                                const genericSpiInfo& i_spiinfo,
                                                const spiSlaveDevice& i_device)
{
    using partitionPurpose_t = spiEepromPartition::partitionPurpose_t;

    spiEepromPartition partInfo { };

    partInfo.offsetBytes = i_spiinfo.dataOffsetKB * BYTES_PER_KB;
    partInfo.sizeBytes = i_spiinfo.dataSizeKB * BYTES_PER_KB;

    // Determine partition purpose
    switch (i_sourceAttribute)
    {
    case ATTR_SPI_MVPD_PRIMARY_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::MODULE_VPD_PRIMARY;
        break;
    case ATTR_SPI_MVPD_BACKUP_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::MODULE_VPD_SECONDARY;
        break;
    case ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::SBE_BOOT_SEEPROM_PRIMARY;
        break;
    case ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::SBE_BOOT_SEEPROM_SECONDARY;
        break;
    case ATTR_SPI_SBE_MEASUREMENT_CODE_PRIMARY_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::MEASUREMENT_SEEPROM_PRIMARY;
        break;
    case ATTR_SPI_SBE_MEASUREMENT_CODE_BACKUP_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::MEASUREMENT_SEEPROM_SECONDARY;
        break;
    case ATTR_SPI_WOF_DATA_INFO:
        partInfo.partitionPurpose = partitionPurpose_t::WOF_DATA;
        break;
    case ATTR_SPI_KEYSTORE_INFO_OPAL_0:
        partInfo.partitionPurpose = partitionPurpose_t::KEYSTORE_OPAL_VAR_BANK_0;
        break;
    case ATTR_SPI_KEYSTORE_INFO_OPAL_1:
        partInfo.partitionPurpose = partitionPurpose_t::KEYSTORE_OPAL_VAR_BANK_1;
        break;
    case ATTR_SPI_KEYSTORE_INFO_OPAL_2:
        partInfo.partitionPurpose = partitionPurpose_t::KEYSTORE_OPAL_QUEUE;
        break;
    case ATTR_SPI_KEYSTORE_INFO_PHYP:
        partInfo.partitionPurpose = partitionPurpose_t::KEYSTORE_PHYP;
        break;
    case ATTR_SPI_KEYSTORE_INFO_HOSTBOOT:
        partInfo.partitionPurpose = partitionPurpose_t::KEYSTORE_HB;
        break;
    default:
        TRACFCOMP(g_trac_spi,
                  ERR_MRK"collectSpiSlavePartitionInfo: Unknown SPI partition info attribute 0x%08x",
                  i_sourceAttribute);
        assert(false, "collectSpiSlavePartitionInfo: Unknown SPI partition info attribute");
        break;
    }

    // Keystore partitions have SCOM access controls and a firmware owner, so
    // fill out that info here
    do
    {
        uint8_t keystore_lock_number = 0xFF;

        switch (partInfo.partitionPurpose)
        {
        case partitionPurpose_t::KEYSTORE_OPAL_VAR_BANK_0:
            keystore_lock_number = 0;
            break;
        case partitionPurpose_t::KEYSTORE_OPAL_VAR_BANK_1:
            keystore_lock_number = 1;
            break;
        case partitionPurpose_t::KEYSTORE_OPAL_QUEUE:
            keystore_lock_number = 2;
            break;
        case partitionPurpose_t::KEYSTORE_PHYP:
            keystore_lock_number = 3;
            break;
        case partitionPurpose_t::KEYSTORE_HB:
            keystore_lock_number = 4;
            break;
        default:
            // Not a keystore info attribute
            break;
        }

        partInfo.writeAccessControl.scomAddress = OTPC_M_SECURITY_SWITCH_REGISTER;
        partInfo.writeAccessControl.secureBitPosition =
            (OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT
             + keystore_lock_number * 2);
        partInfo.writeAccessControl.bitPolarity = spiEepromScomInfo::POLARITY_1_LOCKED;
        partInfo.writeAccessControl.sticky = true;

        partInfo.readAccessControl = partInfo.writeAccessControl;
        // Read bit is directly adjacent to the write bit
        partInfo.readAccessControl.secureBitPosition += 1;
    } while (0);

    return partInfo;
}

/* @brief collectSpiSlaveDeviceInfo
 *
 *        Collects information about a spiSlaveDevice from an attribute that
 *        contains the information.
 *
 * @param[out] o_devInfo       The spiSlaveDevice structure to populate
 * @param[in] i_masterTarget   The SPI master for the SPI device
 * @param[in] i_spiinfo        An attribute structure describing an SPI device
 * @param[in] i_node           The node on which the SPI master resides
 */
void collectSpiSlaveDeviceInfo(spiSlaveDevice& o_devInfo,
                               Target* const i_masterTarget,
                               const genericSpiInfo& i_spiinfo,
                               Target* const i_node)
{
    auto nodeOrdinal = i_node->getAttr<ATTR_ORDINAL_ID>();
    auto procId = i_masterTarget->getAttr<ATTR_POSITION>();

    assert(0 <= nodeOrdinal && nodeOrdinal < MAX_NODES_PER_SYS,
           "collectSpiSlaveDeviceInfo: Invalid node ordinal");
    assert(0 <= procId && procId < P10_MAX_PROCS,
           "collectSpiSlaveDeviceInfo: Invalid proc ID");

    o_devInfo.masterEngine = i_spiinfo.engine;
    o_devInfo.masterPort = 0; // P10 only has one slave device per master

    const uint64_t SCK_DIVIDER = i_masterTarget->getAttr<ATTR_SPI_BUS_DIV_REF>();

    o_devInfo.busSpeedKhz = spiSerialClock(lbusFrequencyHz(), SCK_DIVIDER) / HZ_PER_KHZ;

    switch (i_spiinfo.engine)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        o_devInfo.deviceType = spiSlaveDevice::slaveDeviceType_t::SEEPROM_MICROCHIP_25CSM04;
        o_devInfo.devicePurpose = spiSlaveDevice::slaveDevicePurpose_t::SEEPROM;
        break;
    case 4:
        o_devInfo.deviceType = spiSlaveDevice::slaveDeviceType_t::TCG_SPI_TPM;
        o_devInfo.devicePurpose = spiSlaveDevice::slaveDevicePurpose_t::TPM;
        break;
    default:
        o_devInfo.deviceType = spiSlaveDevice::slaveDeviceType_t::UNKNOWN;
        o_devInfo.devicePurpose = spiSlaveDevice::slaveDevicePurpose_t::UNKNOWN;
        break;
    }

    o_devInfo.deviceId.nodeOrdinal = nodeOrdinal;
    o_devInfo.deviceId.procId = procId;
    // The device ID will be calculated after collecting the device list
    o_devInfo.deviceId.uniqueId = 0;

    o_devInfo.residentFruSlcaIndex = 0; // Always 0 for BMC-based systems

    calcSpiDeviceDescription(o_devInfo);
}

/* @brief getTargetSpiDeviceInfo
 *
 *        Reads the SPI device-related attributes from the given target and
 *        populates a list of devices described by them.
 *
 * @param[in] i_spiTarget    The target to read SPI attributes from
 * @param[out] o_deviceInfo   List to populate with devices
 */
void getTargetSpiDeviceInfo(Target* const i_spiTarget,
                            std::vector<spiSlaveDevice>& o_deviceInfo)
{
    Target* const parentNode = getParent(i_spiTarget, TYPE_NODE);
    Target* const spiMaster = (i_spiTarget->getAttr<ATTR_TYPE>() == TYPE_PROC
                               ? i_spiTarget
                               : getParent(i_spiTarget, TYPE_PROC));

    std::map<uint8_t, spiSlaveDevice> engineToDevice;

    // Physical devices
    // If we add an attribute that contains SPI layout info for another HW
    // device, just add the attribute name to the list below.
    tryGetAttributes<ATTR_SPI_EEPROM_VPD_PRIMARY_INFO,
                     ATTR_SPI_EEPROM_VPD_BACKUP_INFO,
                     ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO,
                     ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO>
        ::get(i_spiTarget,
              [spiMaster, parentNode, &o_deviceInfo, &engineToDevice]
              (ATTRIBUTE_ID, const genericSpiInfo& value) {
                  if (targetService().toTarget(value.spiMasterPath) == spiMaster)
                  {
                      collectSpiSlaveDeviceInfo(engineToDevice[value.engine], spiMaster, value, parentNode);
                  }
              });

    // Logical devices
    // If we add an attribute that contains SPI layout info for another SPI
    // partition, just add the attribute name to the list below.
    tryGetAttributes<ATTR_SPI_MVPD_PRIMARY_INFO,
                     ATTR_SPI_MVPD_BACKUP_INFO,
                     ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO, // SBE SEEPROM info is the same for physical
                     ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO,  // and logical, so it appears here too.
                     ATTR_SPI_SBE_MEASUREMENT_CODE_BACKUP_INFO,
                     ATTR_SPI_SBE_MEASUREMENT_CODE_PRIMARY_INFO,
                     ATTR_SPI_WOF_DATA_INFO,
                     ATTR_SPI_KEYSTORE_INFO_OPAL_0,
                     ATTR_SPI_KEYSTORE_INFO_OPAL_1,
                     ATTR_SPI_KEYSTORE_INFO_OPAL_2,
                     ATTR_SPI_KEYSTORE_INFO_PHYP,
                     ATTR_SPI_KEYSTORE_INFO_HOSTBOOT>
        ::get(i_spiTarget,
              [spiMaster, parentNode, &o_deviceInfo, &engineToDevice]
              (ATTRIBUTE_ID srcAttr, const genericSpiInfo& value) {
                  if (targetService().toTarget(value.spiMasterPath) == spiMaster)
                  {
                      if (engineToDevice.find(value.engine) == end(engineToDevice))
                      {
                          // more details on the EEPROM partition that doesn't have a matching engine
                          TRACFCOMP(g_trac_spi, ERR_MRK"getTargetSpiDeviceInfo:"
                             "master SPI 0x%.8X, engine %d, dataOffsetKB = 0x%04X, "
                             "dataSizeKB = 0x%04X, eepromContentType = %d",
                             get_huid(spiMaster), value.engine,
                             value.dataOffsetKB, value.dataSizeKB,
                             value.eepromContentType);

                          assert(false, "EEPROM partition belongs to nonexistent engine %d", value.engine);
                      }
                      else
                      {
                          engineToDevice[value.engine].partitions.push_back(
                              collectSpiSlavePartitionInfo(srcAttr, value, engineToDevice[value.engine])
                          );
                      }
                  }
              });

    for (const auto& p : engineToDevice)
    {
        o_deviceInfo.push_back(p.second);
    }
}

/* @brief assignUniqueIds
 *
 *        Assigns unique ascending IDs to a list of SPI devices.
 *
 * @param[in/out] io_devices  List of SPI devices to assign unique IDs
 */
void assignUniqueIds(std::vector<spiSlaveDevice>& io_devices)
{
    uint16_t next_id = 0;

    for (spiSlaveDevice& device : io_devices)
    {
        device.deviceId.uniqueId = next_id;
        ++next_id;
    }
}

}

namespace SPI {

void getSpiDeviceInfo(std::vector<spiSlaveDevice>& o_deviceInfo,
                      Target* const i_spiMaster)
{
    std::vector<Target*> spimasters;

    if (i_spiMaster)
    {
        spimasters.push_back(i_spiMaster);
    }
    else
    {
        // If no SPI master was specified, then get all targets that have SPI
        // info attributes.

        PredicateCTM procChipFilter(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);
        PredicateCTM tpmChipFilter(TARGETING::CLASS_CHIP,TARGETING::TYPE_TPM);
        PredicateHwas isPresent;
        isPresent.present(true);
        PredicatePostfixExpr spiTargetFilter;
        // This predicate means: (PROC || TPM) && PRESENT
        spiTargetFilter.push(&procChipFilter).push(&tpmChipFilter).Or().push(&isPresent).And();

        targetService().getAssociated(spimasters,
                                      assertGetToplevelTarget(),
                                      TARGETING::TargetService::CHILD,
                                      TARGETING::TargetService::ALL,
                                      &spiTargetFilter);
    }

    // First read all the SPI device and partition info from the targets
    for (Target* const spimaster : spimasters)
    {
        getTargetSpiDeviceInfo(spimaster, o_deviceInfo);
    }

    assignUniqueIds(o_deviceInfo);
}

}
