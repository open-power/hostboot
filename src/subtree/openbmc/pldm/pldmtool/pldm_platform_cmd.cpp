#include "common/types.hpp"
#include "pldm_cmd_helper.hpp"

#include <libpldm/entity.h>
#include <libpldm/platform.h>
#include <libpldm/state_set.h>

#include <algorithm>
#include <cstddef>
#include <format>
#include <map>
#include <memory>
#include <ranges>

#ifdef OEM_IBM
#include "oem/ibm/oem_ibm_state_set.hpp"
#endif

using namespace pldm::utils;

namespace pldmtool
{
namespace platform
{
namespace
{
using namespace pldmtool::helper;

static const std::map<uint8_t, std::string> sensorPresState{
    {PLDM_SENSOR_UNKNOWN, "Sensor Unknown"},
    {PLDM_SENSOR_NORMAL, "Sensor Normal"},
    {PLDM_SENSOR_WARNING, "Sensor Warning"},
    {PLDM_SENSOR_CRITICAL, "Sensor Critical"},
    {PLDM_SENSOR_FATAL, "Sensor Fatal"},
    {PLDM_SENSOR_LOWERWARNING, "Sensor Lower Warning"},
    {PLDM_SENSOR_LOWERCRITICAL, "Sensor Lower Critical"},
    {PLDM_SENSOR_LOWERFATAL, "Sensor Lower Fatal"},
    {PLDM_SENSOR_UPPERWARNING, "Sensor Upper Warning"},
    {PLDM_SENSOR_UPPERCRITICAL, "Sensor Upper Critical"},
    {PLDM_SENSOR_UPPERFATAL, "Sensor Upper Fatal"}};

static const std::map<uint8_t, std::string> sensorOpState{
    {PLDM_SENSOR_ENABLED, "Sensor Enabled"},
    {PLDM_SENSOR_DISABLED, "Sensor Disabled"},
    {PLDM_SENSOR_UNAVAILABLE, "Sensor Unavailable"},
    {PLDM_SENSOR_STATUSUNKOWN, "Sensor Status Unknown"},
    {PLDM_SENSOR_FAILED, "Sensor Failed"},
    {PLDM_SENSOR_INITIALIZING, "Sensor Sensor Initializing"},
    {PLDM_SENSOR_SHUTTINGDOWN, "Sensor Shutting down"},
    {PLDM_SENSOR_INTEST, "Sensor Intest"}};

const std::map<uint8_t, std::string> effecterOpState{
    {EFFECTER_OPER_STATE_ENABLED_UPDATEPENDING,
     "Effecter Enabled Update Pending"},
    {EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
     "Effecter Enabled No Update Pending"},
    {EFFECTER_OPER_STATE_DISABLED, "Effecter Disabled"},
    {EFFECTER_OPER_STATE_UNAVAILABLE, "Effecter Unavailable"},
    {EFFECTER_OPER_STATE_STATUSUNKNOWN, "Effecter Status Unknown"},
    {EFFECTER_OPER_STATE_FAILED, "Effecter Failed"},
    {EFFECTER_OPER_STATE_INITIALIZING, "Effecter Initializing"},
    {EFFECTER_OPER_STATE_SHUTTINGDOWN, "Effecter Shutting Down"},
    {EFFECTER_OPER_STATE_INTEST, "Effecter In Test"}};

std::string getEffecterOpState(uint8_t state)
{
    return effecterOpState.contains(state) ? effecterOpState.at(state)
                                           : std::to_string(state);
}

std::vector<std::unique_ptr<CommandInterface>> commands;

} // namespace

using ordered_json = nlohmann::ordered_json;

class GetPDR : public CommandInterface
{
  public:
    ~GetPDR() = default;
    GetPDR() = delete;
    GetPDR(const GetPDR&) = delete;
    GetPDR(GetPDR&&) = default;
    GetPDR& operator=(const GetPDR&) = delete;
    GetPDR& operator=(GetPDR&&) = delete;

    using CommandInterface::CommandInterface;

    explicit GetPDR(const char* type, const char* name, CLI::App* app) :
        CommandInterface(type, name, app), dataTransferHandle(0),
        operationFlag(PLDM_GET_FIRSTPART), requestCount(UINT16_MAX),
        recordChangeNumber(0), nextPartRequired(false)
    {
        auto pdrOptionGroup = app->add_option_group(
            "Required Option",
            "Retrieve individual PDR, all PDRs, PDRs of a requested type or retrieve all PDRs of the requested terminusID");
        pdrOptionGroup->add_option(
            "-d,--data", recordHandle,
            "retrieve individual PDRs from a PDR Repository\n"
            "eg: The recordHandle value for the PDR to be retrieved and 0 "
            "means get first PDR in the repository.");
        pdrRecType = "";
        pdrOptionGroup->add_option(
            "-t, --type", pdrRecType,
            "retrieve all PDRs of the requested type\n"
            "supported types:\n"
            "[terminusLocator, stateSensor, "
            "numericEffecter, stateEffecter, "
            "compactNumericSensor, sensorauxname, "
            "efffecterAuxName, numericsensor, "
            "EntityAssociation, fruRecord, ... ]");

        getPDRGroupOption = pdrOptionGroup->add_option(
            "-i, --terminusID", pdrTerminus,
            "retrieve all PDRs of the requested terminusID\n"
            "supported IDs:\n [1, 2, 208...]");

        allPDRs = false;
        pdrOptionGroup->add_flag("-a, --all", allPDRs,
                                 "retrieve all PDRs from a PDR repository");

        pdrOptionGroup->require_option(1);
    }

    void parseGetPDROptions()
    {
        optTIDSet = false;
        if (getPDRGroupOption->count() > 0)
        {
            optTIDSet = true;
            getPDRs();
        }
    }

    void getPDRs()
    {
        // start the array
        std::cout << "[";

        recordHandle = 0;
        do
        {
            CommandInterface::exec();
        } while (recordHandle != 0);

        // close the array
        std::cout << "]\n";

        if (handleFound)
        {
            recordHandle = 0;
            uint32_t prevRecordHandle = 0;
            do
            {
                CommandInterface::exec();
                if (recordHandle == prevRecordHandle)
                {
                    return;
                }
                prevRecordHandle = recordHandle;
            } while (recordHandle != 0);
        }
    }

    void exec() override
    {
        if (allPDRs || !pdrRecType.empty())
        {
            if (!pdrRecType.empty())
            {
                std::transform(pdrRecType.begin(), pdrRecType.end(),
                               pdrRecType.begin(), tolower);
            }

            // start the array
            std::cout << "[\n";

            // Retrieve all PDR records starting from the first
            recordHandle = 0;
            uint32_t prevRecordHandle = 0;
            std::map<uint32_t, uint32_t> recordsSeen;
            do
            {
                CommandInterface::exec();
                // recordHandle is updated to nextRecord when
                // CommandInterface::exec() is successful.
                // In case of any error, return.
                if (recordHandle == prevRecordHandle && !nextPartRequired)
                {
                    return;
                }

                // check for circular references.
                auto result =
                    recordsSeen.emplace(recordHandle, prevRecordHandle);
                if (!result.second && !nextPartRequired)
                {
                    std::cerr
                        << "Record handle " << recordHandle
                        << " has multiple references: " << result.first->second
                        << ", " << prevRecordHandle << "\n";
                    return;
                }
                prevRecordHandle = recordHandle;

                if (recordHandle != 0)
                {
                    // close the array
                    std::cout << ",";
                }
            } while (recordHandle != 0);

            // close the array
            std::cout << "]\n";
        }
        else
        {
            do
            {
                CommandInterface::exec();
            } while (nextPartRequired);
        }
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_PDR_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_pdr_req(
            instanceId, recordHandle, dataTransferHandle, operationFlag,
            requestCount, recordChangeNumber, request, PLDM_GET_PDR_REQ_BYTES);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t respRecordData[UINT16_MAX] = {0};
        uint32_t nextRecordHndl = 0;
        uint32_t nextDataTransferHndl = 0;
        uint8_t transferFlag = 0;
        uint16_t respCnt = 0;
        uint8_t transferCRC = 0;

        auto rc = decode_get_pdr_resp(
            responsePtr, payloadLength, &completionCode, &nextRecordHndl,
            &nextDataTransferHndl, &transferFlag, &respCnt, respRecordData,
            sizeof(respRecordData), &transferCRC);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            nextPartRequired = false;
            return;
        }

        if (optTIDSet && !handleFound)
        {
            terminusHandle = getTerminusHandle(respRecordData, pdrTerminus);
            if (terminusHandle.has_value())
            {
                recordHandle = 0;
                return;
            }
            else
            {
                recordHandle = nextRecordHndl;
                return;
            }
        }
        else
        {
            recordData.insert(recordData.end(), respRecordData,
                              respRecordData + respCnt);

            // End or StartAndEnd
            if (transferFlag == PLDM_PLATFORM_TRANSFER_END ||
                transferFlag == PLDM_PLATFORM_TRANSFER_START_AND_END)
            {
                printPDRMsg(nextRecordHndl, respCnt, recordData.data(),
                            terminusHandle);
                nextPartRequired = false;
                recordHandle = nextRecordHndl;
                dataTransferHandle = 0;
                recordChangeNumber = 0;
                operationFlag = PLDM_GET_FIRSTPART;
                recordData.clear();
            }
            else
            {
                nextPartRequired = true;
                dataTransferHandle = nextDataTransferHndl;
                struct pldm_pdr_hdr* pdr_hdr =
                    reinterpret_cast<struct pldm_pdr_hdr*>(respRecordData);
                recordChangeNumber = pdr_hdr->record_change_num;
                operationFlag = PLDM_GET_NEXTPART;
            }
        }
    }

  private:
    const std::map<pldm::pdr::EntityType, std::string> entityType = {
        {PLDM_ENTITY_UNSPECIFIED, "Unspecified"},
        {PLDM_ENTITY_OTHER, "Other"},
        {PLDM_ENTITY_NETWORK, "Network"},
        {PLDM_ENTITY_GROUP, "Group"},
        {PLDM_ENTITY_REMOTE_MGMT_COMM_DEVICE,
         "Remote Management Communication Device"},
        {PLDM_ENTITY_EXTERNAL_ENVIRONMENT, "External Environment"},
        {PLDM_ENTITY_COMM_CHANNEL, " Communication Channel"},
        {PLDM_ENTITY_TERMINUS, "PLDM Terminus"},
        {PLDM_ENTITY_PLATFORM_EVENT_LOG, " Platform Event Log"},
        {PLDM_ENTITY_KEYPAD, "keypad"},
        {PLDM_ENTITY_SWITCH, "Switch"},
        {PLDM_ENTITY_PUSHBUTTON, "Pushbutton"},
        {PLDM_ENTITY_DISPLAY, "Display"},
        {PLDM_ENTITY_INDICATOR, "Indicator"},
        {PLDM_ENTITY_SYS_MGMT_SW, "System Management Software"},
        {PLDM_ENTITY_SYS_FIRMWARE, "System Firmware"},
        {PLDM_ENTITY_OPERATING_SYS, "Operating System"},
        {PLDM_ENTITY_VIRTUAL_MACHINE_MANAGER, "Virtual Machine Manager"},
        {PLDM_ENTITY_OS_LOADER, "OS Loader"},
        {PLDM_ENTITY_DEVICE_DRIVER, "Device Driver"},
        {PLDM_ENTITY_MGMT_CONTROLLER_FW, "Management Controller Firmware"},
        {PLDM_ENTITY_SYSTEM_CHASSIS, "System chassis (main enclosure)"},
        {PLDM_ENTITY_SUB_CHASSIS, "Sub-chassis"},
        {PLDM_ENTITY_DISK_DRIVE_BAY, "Disk Drive Bay"},
        {PLDM_ENTITY_PERIPHERAL_BAY, "Peripheral Bay"},
        {PLDM_ENTITY_DEVICE_BAY, "Device bay"},
        {PLDM_ENTITY_DOOR, "Door"},
        {PLDM_ENTITY_ACCESS_PANEL, "Access Panel"},
        {PLDM_ENTITY_COVER, "Cover"},
        {PLDM_ENTITY_BOARD, "Board"},
        {PLDM_ENTITY_CARD, "Card"},
        {PLDM_ENTITY_MODULE, "Module"},
        {PLDM_ENTITY_SYS_MGMT_MODULE, "System management module"},
        {PLDM_ENTITY_SYS_BOARD, "System Board"},
        {PLDM_ENTITY_MEMORY_BOARD, "Memory Board"},
        {PLDM_ENTITY_MEMORY_MODULE, "Memory Module"},
        {PLDM_ENTITY_PROC_MODULE, "Processor Module"},
        {PLDM_ENTITY_ADD_IN_CARD, "Add-in Card"},
        {PLDM_ENTITY_CHASSIS_FRONT_PANEL_BOARD,
         "Chassis front panel board(control panel)"},
        {PLDM_ENTITY_BACK_PANEL_BOARD, "Back panel board"},
        {PLDM_ENTITY_POWER_MGMT, "Power management board"},
        {PLDM_ENTITY_POWER_SYS_BOARD, "Power system board"},
        {PLDM_ENTITY_DRIVE_BACKPLANE, "Drive backplane"},
        {PLDM_ENTITY_SYS_INTERNAL_EXPANSION_BOARD,
         "System internal expansion board"},
        {PLDM_ENTITY_OTHER_SYS_BOARD, "Other system board"},
        {PLDM_ENTITY_CHASSIS_BACK_PANEL_BOARD, "Chassis back panel board"},
        {PLDM_ENTITY_PROCESSING_BLADE, "Processing blade"},
        {PLDM_ENTITY_CONNECTIVITY_SWITCH, "Connectivity switch"},
        {PLDM_ENTITY_PROC_MEMORY_MODULE, "Processor/Memory Module"},
        {PLDM_ENTITY_IO_MODULE, "I/O Module"},
        {PLDM_ENTITY_PROC_IO_MODULE, "Processor I/O Module"},
        {PLDM_ENTITY_COOLING_DEVICE, "Cooling device"},
        {PLDM_ENTITY_COOLING_SUBSYSTEM, "Cooling subsystem"},
        {PLDM_ENTITY_COOLING_UNIT, "Cooling Unit"},
        {PLDM_ENTITY_FAN, "Fan"},
        {PLDM_ENTITY_PELTIER_COOLING_DEVICE, "Peltier Cooling Device"},
        {PLDM_ENTITY_LIQUID_COOLING_DEVICE, "Liquid Cooling Device"},
        {PLDM_ENTITY_LIQUID_COOLING_SUBSYSTEM, "Liquid Colling Subsystem"},
        {PLDM_ENTITY_OTHER_STORAGE_DEVICE, "Other Storage Device"},
        {PLDM_ENTITY_FLOPPY_DRIVE, "Floppy Drive"},
        {PLDM_ENTITY_FIXED_DISK_HARD_DRIVE, "Hard Drive"},
        {PLDM_ENTITY_CD_DRIVE, "CD Drive"},
        {PLDM_ENTITY_CD_DVD_DRIVE, "CD/DVD Drive"},
        {PLDM_ENTITY_OTHER_SILICON_STORAGE_DEVICE,
         "Other Silicon Storage Device"},
        {PLDM_ENTITY_SOLID_STATE_SRIVE, "Solid State Drive"},
        {PLDM_ENTITY_POWER_SUPPLY, "Power supply"},
        {PLDM_ENTITY_BATTERY, "Battery"},
        {PLDM_ENTITY_SUPER_CAPACITOR, "Super Capacitor"},
        {PLDM_ENTITY_POWER_CONVERTER, "Power Converter"},
        {PLDM_ENTITY_DC_DC_CONVERTER, "DC-DC Converter"},
        {PLDM_ENTITY_AC_MAINS_POWER_SUPPLY, "AC mains power supply"},
        {PLDM_ENTITY_DC_MAINS_POWER_SUPPLY, "DC mains power supply"},
        {PLDM_ENTITY_PROC, "Processor"},
        {PLDM_ENTITY_CHIPSET_COMPONENT, "Chipset Component"},
        {PLDM_ENTITY_MGMT_CONTROLLER, "Management Controller"},
        {PLDM_ENTITY_PERIPHERAL_CONTROLLER, "Peripheral Controller"},
        {PLDM_ENTITY_SEEPROM, "SEEPROM"},
        {PLDM_ENTITY_NVRAM_CHIP, "NVRAM Chip"},
        {PLDM_ENTITY_FLASH_MEMORY_CHIP, "FLASH Memory chip"},
        {PLDM_ENTITY_MEMORY_CHIP, "Memory Chip"},
        {PLDM_ENTITY_MEMORY_CONTROLLER, "Memory Controller"},
        {PLDM_ENTITY_NETWORK_CONTROLLER, "Network Controller"},
        {PLDM_ENTITY_IO_CONTROLLER, "I/O Controller"},
        {PLDM_ENTITY_SOUTH_BRIDGE, "South Bridge"},
        {PLDM_ENTITY_REAL_TIME_CLOCK, "Real Time Clock (RTC)"},
        {PLDM_ENTITY_FPGA_CPLD_DEVICE, "FPGA/CPLD Configurable Logic Device"},
        {PLDM_ENTITY_OTHER_BUS, "Other Bus"},
        {PLDM_ENTITY_SYS_BUS, "System Bus"},
        {PLDM_ENTITY_I2C_BUS, "I2C Bus"},
        {PLDM_ENTITY_SMBUS_BUS, "SMBus Bus"},
        {PLDM_ENTITY_SPI_BUS, "SPI Bus"},
        {PLDM_ENTITY_PCI_BUS, "PCI Bus"},
        {PLDM_ENTITY_PCI_EXPRESS_BUS, "PCI Express Bus"},
        {PLDM_ENTITY_PECI_BUS, "PECI Bus"},
        {PLDM_ENTITY_LPC_BUS, "LPC Bus"},
        {PLDM_ENTITY_USB_BUS, "USB Bus"},
        {PLDM_ENTITY_FIREWIRE_BUS, "FireWire Bus"},
        {PLDM_ENTITY_SCSI_BUS, "SCSI Bus"},
        {PLDM_ENTITY_SATA_SAS_BUS, "SATA/SAS Bus"},
        {PLDM_ENTITY_PROC_FRONT_SIDE_BUS, "Processor/Front-side Bus"},
        {PLDM_ENTITY_INTER_PROC_BUS, "Inter-processor Bus"},
        {PLDM_ENTITY_CONNECTOR, "Connector"},
        {PLDM_ENTITY_SLOT, "Slot"},
        {PLDM_ENTITY_CABLE, "Cable(electrical or optical)"},
        {PLDM_ENTITY_INTERCONNECT, "Interconnect"},
        {PLDM_ENTITY_PLUG, "Plug"},
        {PLDM_ENTITY_SOCKET, "Socket"},
    };

    const std::map<uint16_t, std::string> stateSet = {
        {PLDM_STATE_SET_HEALTH_STATE, "Health State"},
        {PLDM_STATE_SET_AVAILABILITY, "Availability"},
        {PLDM_STATE_SET_PREDICTIVE_CONDITION, "Predictive Condition"},
        {PLDM_STATE_SET_REDUNDANCY_STATUS, "Redundancy Status"},
        {PLDM_STATE_SET_HEALTH_REDUNDANCY_TREND, "Health/Redundancy Trend"},
        {PLDM_STATE_SET_GROUP_RESOURCE_LEVEL, "Group Resource Level"},
        {PLDM_STATE_SET_REDUNDANCY_ENTITY_ROLE, "Redundancy Entity Role"},
        {PLDM_STATE_SET_OPERATIONAL_STATUS, "Operational Status"},
        {PLDM_STATE_SET_OPERATIONAL_STRESS_STATUS, "Operational Stress Status"},
        {PLDM_STATE_SET_OPERATIONAL_FAULT_STATUS, "Operational Fault Status"},
        {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
         "Operational Running Status"},
        {PLDM_STATE_SET_OPERATIONAL_CONNECTION_STATUS,
         "Operational Connection Status"},
        {PLDM_STATE_SET_PRESENCE, "Presence"},
        {PLDM_STATE_SET_PERFORMANCE, "Performance"},
        {PLDM_STATE_SET_CONFIGURATION_STATE, "Configuration State"},
        {PLDM_STATE_SET_CHANGED_CONFIGURATION, "Changed Configuration"},
        {PLDM_STATE_SET_IDENTIFY_STATE, "Identify State"},
        {PLDM_STATE_SET_VERSION, "Version"},
        {PLDM_STATE_SET_ALARM_STATE, "Alarm State"},
        {PLDM_STATE_SET_DEVICE_INITIALIZATION, "Device Initialization"},
        {PLDM_STATE_SET_THERMAL_TRIP, "Thermal Trip"},
        {PLDM_STATE_SET_HEARTBEAT, "Heartbeat"},
        {PLDM_STATE_SET_LINK_STATE, "Link State"},
        {PLDM_STATE_SET_SMOKE_STATE, "Smoke State"},
        {PLDM_STATE_SET_HUMIDITY_STATE, "Humidity State"},
        {PLDM_STATE_SET_DOOR_STATE, "Door State"},
        {PLDM_STATE_SET_SWITCH_STATE, "Switch State"},
        {PLDM_STATE_SET_LOCK_STATE, "Lock State"},
        {PLDM_STATE_SET_PHYSICAL_SECURITY, "Physical Security"},
        {PLDM_STATE_SET_DOCK_AUTHORIZATION, "Dock Authorization"},
        {PLDM_STATE_SET_HW_SECURITY, "Hardware Security"},
        {PLDM_STATE_SET_PHYSICAL_COMM_CONNECTION,
         "Physical Communication Connection"},
        {PLDM_STATE_SET_COMM_LEASH_STATUS, "Communication Leash Status"},
        {PLDM_STATE_SET_FOREIGN_NW_DETECTION_STATUS,
         "Foreign Network Detection Status"},
        {PLDM_STATE_SET_PASSWORD_PROTECTED_ACCESS_SECURITY,
         "Password-Protected Access Security"},
        {PLDM_STATE_SET_SECURITY_ACCESS_PRIVILEGE_LEVEL,
         "Security Access –PrivilegeLevel"},
        {PLDM_STATE_SET_SESSION_AUDIT, "PLDM Session Audit"},
        {PLDM_STATE_SET_SW_TERMINATION_STATUS, "Software Termination Status"},
        {PLDM_STATE_SET_STORAGE_MEDIA_ACTIVITY, "Storage Media Activity"},
        {PLDM_STATE_SET_BOOT_RESTART_CAUSE, "Boot/Restart Cause"},
        {PLDM_STATE_SET_BOOT_RESTART_REQUEST, "Boot/Restart Request"},
        {PLDM_STATE_SET_ENTITY_BOOT_STATUS, "Entity Boot Status"},
        {PLDM_STATE_SET_BOOT_ERROR_STATUS, "Boot ErrorStatus"},
        {PLDM_STATE_SET_BOOT_PROGRESS, "Boot Progress"},
        {PLDM_STATE_SET_SYS_FIRMWARE_HANG, "System Firmware Hang"},
        {PLDM_STATE_SET_POST_ERRORS, "POST Errors"},
        {PLDM_STATE_SET_LOG_FILL_STATUS, "Log Fill Status"},
        {PLDM_STATE_SET_LOG_FILTER_STATUS, "Log Filter Status"},
        {PLDM_STATE_SET_LOG_TIMESTAMP_CHANGE, "Log Timestamp Change"},
        {PLDM_STATE_SET_INTERRUPT_REQUESTED, "Interrupt Requested"},
        {PLDM_STATE_SET_INTERRUPT_RECEIVED, "Interrupt Received"},
        {PLDM_STATE_SET_DIAGNOSTIC_INTERRUPT_REQUESTED,
         "Diagnostic Interrupt Requested"},
        {PLDM_STATE_SET_DIAGNOSTIC_INTERRUPT_RECEIVED,
         "Diagnostic Interrupt Received"},
        {PLDM_STATE_SET_IO_CHANNEL_CHECK_NMI_REQUESTED,
         "I/O Channel Check NMI Requested"},
        {PLDM_STATE_SET_IO_CHANNEL_CHECK_NMI_RECEIVED,
         "I/O Channel Check NMI Received"},
        {PLDM_STATE_SET_FATAL_NMI_REQUESTED, "Fatal NMI Requested"},
        {PLDM_STATE_SET_FATAL_NMI_RECEIVED, "Fatal NMI Received"},
        {PLDM_STATE_SET_SOFTWARE_NMI_REQUESTED, "Software NMI Requested"},
        {PLDM_STATE_SET_SOFTWARE_NMI_RECEIVED, "Software NMI Received"},
        {PLDM_STATE_SET_SMI_REQUESTED, "SMI Requested"},
        {PLDM_STATE_SET_SMI_RECEIVED, "SMI Received"},
        {PLDM_STATE_SET_PCI_PERR_REQUESTED, "PCI PERR Requested"},
        {PLDM_STATE_SET_PCI_PERR_RECEIVED, "PCI PERR Received"},
        {PLDM_STATE_SET_PCI_SERR_REQUESTED, "PCI SERR Requested "},
        {PLDM_STATE_SET_PCI_SERR_RECEIVED, "PCI SERR Received"},
        {PLDM_STATE_SET_BUS_ERROR_STATUS, "Bus Error Status"},
        {PLDM_STATE_SET_WATCHDOG_STATUS, "Watchdog Status"},
        {PLDM_STATE_SET_POWER_SUPPLY_STATE, "Power Supply State"},
        {PLDM_STATE_SET_DEVICE_POWER_STATE, "Device Power State"},
        {PLDM_STATE_SET_ACPI_POWER_STATE, "ACPI Power State"},
        {PLDM_STATE_SET_BACKUP_POWER_SOURCE, "Backup Power Source"},
        {PLDM_STATE_SET_SYSTEM_POWER_STATE, "System Power State "},
        {PLDM_STATE_SET_BATTERY_ACTIVITY, "Battery Activity"},
        {PLDM_STATE_SET_BATTERY_STATE, "Battery State"},
        {PLDM_STATE_SET_PROC_POWER_STATE, "Processor Power State"},
        {PLDM_STATE_SET_POWER_PERFORMANCE_STATE, "Power-Performance State"},
        {PLDM_STATE_SET_PROC_ERROR_STATUS, "Processor Error Status"},
        {PLDM_STATE_SET_BIST_FAILURE_STATUS, "BIST FailureStatus"},
        {PLDM_STATE_SET_IBIST_FAILURE_STATUS, "IBIST FailureStatus"},
        {PLDM_STATE_SET_PROC_HANG_IN_POST, "Processor Hang in POST"},
        {PLDM_STATE_SET_PROC_STARTUP_FAILURE, "Processor Startup Failure"},
        {PLDM_STATE_SET_UNCORRECTABLE_CPU_ERROR, "Uncorrectable CPU Error"},
        {PLDM_STATE_SET_MACHINE_CHECK_ERROR, "Machine Check Error"},
        {PLDM_STATE_SET_CORRECTED_MACHINE_CHECK, "Corrected Machine Check"},
        {PLDM_STATE_SET_CACHE_STATUS, "Cache Status"},
        {PLDM_STATE_SET_MEMORY_ERROR_STATUS, "Memory Error Status"},
        {PLDM_STATE_SET_REDUNDANT_MEMORY_ACTIVITY_STATUS,
         "Redundant Memory Activity Status"},
        {PLDM_STATE_SET_ERROR_DETECTION_STATUS, "Error Detection Status"},
        {PLDM_STATE_SET_STUCK_BIT_STATUS, "Stuck Bit Status"},
        {PLDM_STATE_SET_SCRUB_STATUS, "Scrub Status"},
        {PLDM_STATE_SET_SLOT_OCCUPANCY, "Slot Occupancy"},
        {PLDM_STATE_SET_SLOT_STATE, "Slot State"},
    };

    const std::array<std::string_view, 4> sensorInit = {
        "noInit", "useInitPDR", "enableSensor", "disableSensor"};

    const std::array<std::string_view, 4> effecterInit = {
        "noInit", "useInitPDR", "enableEffecter", "disableEffecter"};

    const std::map<uint8_t, std::string> pdrType = {
        {PLDM_TERMINUS_LOCATOR_PDR, "Terminus Locator PDR"},
        {PLDM_NUMERIC_SENSOR_PDR, "Numeric Sensor PDR"},
        {PLDM_NUMERIC_SENSOR_INITIALIZATION_PDR,
         "Numeric Sensor Initialization PDR"},
        {PLDM_STATE_SENSOR_PDR, "State Sensor PDR"},
        {PLDM_STATE_SENSOR_INITIALIZATION_PDR,
         "State Sensor Initialization PDR"},
        {PLDM_SENSOR_AUXILIARY_NAMES_PDR, "Sensor Auxiliary Names PDR"},
        {PLDM_OEM_UNIT_PDR, "OEM Unit PDR"},
        {PLDM_OEM_STATE_SET_PDR, "OEM State Set PDR"},
        {PLDM_NUMERIC_EFFECTER_PDR, "Numeric Effecter PDR"},
        {PLDM_NUMERIC_EFFECTER_INITIALIZATION_PDR,
         "Numeric Effecter Initialization PDR"},
        {PLDM_COMPACT_NUMERIC_SENSOR_PDR, "Compact Numeric Sensor PDR"},
        {PLDM_STATE_EFFECTER_PDR, "State Effecter PDR"},
        {PLDM_STATE_EFFECTER_INITIALIZATION_PDR,
         "State Effecter Initialization PDR"},
        {PLDM_EFFECTER_AUXILIARY_NAMES_PDR, "Effecter Auxiliary Names PDR"},
        {PLDM_EFFECTER_OEM_SEMANTIC_PDR, "Effecter OEM Semantic PDR"},
        {PLDM_PDR_ENTITY_ASSOCIATION, "Entity Association PDR"},
        {PLDM_ENTITY_AUXILIARY_NAMES_PDR, "Entity Auxiliary Names PDR"},
        {PLDM_OEM_ENTITY_ID_PDR, "OEM Entity ID PDR"},
        {PLDM_INTERRUPT_ASSOCIATION_PDR, "Interrupt Association PDR"},
        {PLDM_EVENT_LOG_PDR, "PLDM Event Log PDR"},
        {PLDM_PDR_FRU_RECORD_SET, "FRU Record Set PDR"},
        {PLDM_OEM_DEVICE_PDR, "OEM Device PDR"},
        {PLDM_OEM_PDR, "OEM PDR"},
    };

    static inline const std::map<uint8_t, std::string> setThermalTrip{
        {PLDM_STATE_SET_THERMAL_TRIP_STATUS_NORMAL, "Normal"},
        {PLDM_STATE_SET_THERMAL_TRIP_STATUS_THERMAL_TRIP, "Thermal Trip"}};

    static inline const std::map<uint8_t, std::string> setIdentifyState{
        {PLDM_STATE_SET_IDENTIFY_STATE_UNASSERTED, "Identify State Unasserted"},
        {PLDM_STATE_SET_IDENTIFY_STATE_ASSERTED, "Identify State Asserted"}};

    static inline const std::map<uint8_t, std::string> setBootProgressState{
        {PLDM_STATE_SET_BOOT_PROG_STATE_NOT_ACTIVE, "Boot Not Active"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_COMPLETED, "Boot Completed"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_MEM_INITIALIZATION,
         "Memory Initialization"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_SEC_PROC_INITIALIZATION,
         "Secondary Processor(s) Initialization"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_PCI_RESORUCE_CONFIG,
         "PCI Resource Configuration"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_STARTING_OP_SYS,
         "Starting Operating System"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_BASE_BOARD_INITIALIZATION,
         "Baseboard Initialization"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_PRIMARY_PROC_INITIALIZATION,
         "Primary Processor Initialization"},
        {PLDM_STATE_SET_BOOT_PROG_STATE_OSSTART, "OSStart"}};

    static inline const std::map<uint8_t, std::string> setOpFaultStatus{
        {PLDM_STATE_SET_OPERATIONAL_FAULT_STATUS_NORMAL, "Normal"},
        {PLDM_STATE_SET_OPERATIONAL_FAULT_STATUS_ERROR, "Error"},
        {PLDM_STATE_SET_OPERATIONAL_FAULT_STATUS_NON_RECOVERABLE_ERROR,
         "Non Recoverable Error"}};

    static inline const std::map<uint8_t, std::string> setSysPowerState{
        {PLDM_STATE_SET_SYS_POWER_STATE_OFF_SOFT_GRACEFUL,
         "Off-Soft Graceful"}};

    static inline const std::map<uint8_t, std::string> setSWTerminationStatus{
        {PLDM_SW_TERM_GRACEFUL_RESTART_REQUESTED,
         "Graceful Restart Requested"}};

    static inline const std::map<uint8_t, std::string> setAvailability{
        {PLDM_STATE_SET_AVAILABILITY_REBOOTING, "Rebooting"}};

    static inline const std::map<uint8_t, std::string> setHealthState{
        {PLDM_STATE_SET_HEALTH_STATE_NORMAL, "Normal"},
        {PLDM_STATE_SET_HEALTH_STATE_NON_CRITICAL, "Non-Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_CRITICAL, "Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_FATAL, "Fatal"},
        {PLDM_STATE_SET_HEALTH_STATE_UPPER_NON_CRITICAL, "Upper Non-Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_LOWER_NON_CRITICAL, "Lower Non-Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_UPPER_CRITICAL, "Upper Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_LOWER_CRITICAL, "Lower Critical"},
        {PLDM_STATE_SET_HEALTH_STATE_UPPER_FATAL, "Upper Fatal"},
        {PLDM_STATE_SET_HEALTH_STATE_LOWER_FATAL, "Lower Fatal"}};

    static inline const std::map<uint8_t, std::string>
        setOperationalRunningState{
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STARTING, "Starting"},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPING, "Stopping"},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPED, "Stopped"},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_IN_SERVICE,
             "In Service"},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_ABORTED, "Aborted"},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_DORMANT, "Dormant"}};

    static inline const std::map<uint8_t, std::string> setPowerDeviceState{
        {PLDM_STATE_SET_ACPI_DEVICE_POWER_STATE_UNKNOWN, "Unknown"},
        {PLDM_STATE_SET_ACPI_DEVICE_POWER_STATE_FULLY_ON, "Fully-On"},
        {PLDM_STATE_SET_ACPI_DEVICE_POWER_STATE_INTERMEDIATE_1,
         "Intermediate State-1"},
        {PLDM_STATE_SET_ACPI_DEVICE_POWER_STATE_INTERMEDIATE_2,
         "Intermediate State-2"},
        {PLDM_STATE_SET_ACPI_DEVICE_POWER_STATE_OFF, "Off"}};

    static inline const std::map<uint16_t, const std::map<uint8_t, std::string>>
        populatePStateMaps{
            {PLDM_STATE_SET_THERMAL_TRIP, setThermalTrip},
            {PLDM_STATE_SET_IDENTIFY_STATE, setIdentifyState},
            {PLDM_STATE_SET_BOOT_PROGRESS, setBootProgressState},
            {PLDM_STATE_SET_OPERATIONAL_FAULT_STATUS, setOpFaultStatus},
            {PLDM_STATE_SET_SYSTEM_POWER_STATE, setSysPowerState},
            {PLDM_STATE_SET_SW_TERMINATION_STATUS, setSWTerminationStatus},
            {PLDM_STATE_SET_AVAILABILITY, setAvailability},
            {PLDM_STATE_SET_HEALTH_STATE, setHealthState},
            {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
             setOperationalRunningState},
            {PLDM_STATE_SET_DEVICE_POWER_STATE, setPowerDeviceState},
        };

    const std::map<std::string, uint8_t> strToPdrType = {
        {"terminuslocator", PLDM_TERMINUS_LOCATOR_PDR},
        {"statesensor", PLDM_STATE_SENSOR_PDR},
        {"sensorauxname", PLDM_SENSOR_AUXILIARY_NAMES_PDR},
        {"numericeffecter", PLDM_NUMERIC_EFFECTER_PDR},
        {"efffecterauxname", PLDM_EFFECTER_AUXILIARY_NAMES_PDR},
        {"numericsensor", PLDM_NUMERIC_SENSOR_PDR},
        {"compactnumericsensor", PLDM_COMPACT_NUMERIC_SENSOR_PDR},
        {"stateeffecter", PLDM_STATE_EFFECTER_PDR},
        {"entityassociation", PLDM_PDR_ENTITY_ASSOCIATION},
        {"frurecord", PLDM_PDR_FRU_RECORD_SET},
        // Add other types
    };

    bool isLogicalBitSet(const uint16_t entity_type)
    {
        return entity_type & 0x8000;
    }

    uint16_t getEntityTypeForLogicalEntity(const uint16_t logical_entity_type)
    {
        return logical_entity_type & 0x7FFF;
    }

    std::string getEntityName(pldm::pdr::EntityType type)
    {
        uint16_t entityNumber = type;
        std::string entityName = "[Physical] ";

        if (isLogicalBitSet(type))
        {
            entityName = "[Logical] ";
            entityNumber = getEntityTypeForLogicalEntity(type);
        }

        try
        {
            return entityName + entityType.at(entityNumber);
        }
        catch (const std::out_of_range& e)
        {
            auto OemString =
                std::to_string(static_cast<unsigned>(entityNumber));
            if (type >= PLDM_OEM_ENTITY_TYPE_START &&
                type <= PLDM_OEM_ENTITY_TYPE_END)
            {
#ifdef OEM_IBM
                if (OemIBMEntityType.contains(entityNumber))
                {
                    return entityName + OemIBMEntityType.at(entityNumber) +
                           "(OEM)";
                }
#endif
                return entityName + OemString + "(OEM)";
            }
            return OemString;
        }
    }

    std::string getStateSetName(uint16_t id)
    {
        auto typeString = std::to_string(id);
        try
        {
            return stateSet.at(id) + "(" + typeString + ")";
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }

    std::vector<std::string> getStateSetPossibleStateNames(
        uint16_t stateId, const std::vector<uint8_t>& value)
    {
        std::vector<std::string> data{};

        for (const auto& s : value)
        {
            std::map<uint8_t, std::string> stateNameMaps;
            auto pstr = std::to_string(s);

#ifdef OEM_IBM
            if (stateId >= PLDM_OEM_STATE_SET_ID_START &&
                stateId < PLDM_OEM_STATE_SET_ID_END)
            {
                if (populateOemIBMStateMaps.contains(stateId))
                {
                    const std::map<uint8_t, std::string> stateNames =
                        populateOemIBMStateMaps.at(stateId);
                    stateNameMaps.insert(stateNames.begin(), stateNames.end());
                }
            }
#endif
            if (populatePStateMaps.contains(stateId))
            {
                const std::map<uint8_t, std::string> stateNames =
                    populatePStateMaps.at(stateId);
                stateNameMaps.insert(stateNames.begin(), stateNames.end());
            }
            if (stateNameMaps.contains(s))
            {
                data.push_back(stateNameMaps.at(s) + "(" + pstr + ")");
            }
            else
            {
                data.push_back(pstr);
            }
        }
        return data;
    }

    std::string getPDRType(uint8_t type)
    {
        auto typeString = std::to_string(type);
        try
        {
            return pdrType.at(type);
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }

    void printCommonPDRHeader(const pldm_pdr_hdr* hdr, ordered_json& output)
    {
        output["recordHandle"] = hdr->record_handle;
        output["PDRHeaderVersion"] = unsigned(hdr->version);
        output["PDRType"] = getPDRType(hdr->type);
        output["recordChangeNumber"] = hdr->record_change_num;
        output["dataLength"] = hdr->length;
    }

    std::vector<uint8_t> printPossibleStates(uint8_t possibleStatesSize,
                                             const bitfield8_t* states)
    {
        uint8_t possibleStatesPos{};
        std::vector<uint8_t> data{};
        auto printStates = [&possibleStatesPos, &data](const bitfield8_t& val) {
            std::stringstream pstates;
            for (int i = 0; i < CHAR_BIT; i++)
            {
                if (val.byte & (1 << i))
                {
                    pstates << (possibleStatesPos * CHAR_BIT + i);
                    data.push_back(
                        static_cast<uint8_t>(std::stoi(pstates.str())));
                    pstates.str("");
                }
            }
            possibleStatesPos++;
        };
        std::for_each(states, states + possibleStatesSize, printStates);
        return data;
    }

    void printStateSensorPDR(const uint8_t* data, ordered_json& output)
    {
        auto pdr = reinterpret_cast<const pldm_state_sensor_pdr*>(data);
        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["sensorID"] = pdr->sensor_id;
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = pdr->entity_instance;
        output["containerID"] = pdr->container_id;
        output["sensorInit"] = sensorInit[pdr->sensor_init];
        output["sensorAuxiliaryNamesPDR"] =
            (pdr->sensor_auxiliary_names_pdr ? true : false);
        output["compositeSensorCount"] = unsigned(pdr->composite_sensor_count);

        auto statesPtr = pdr->possible_states;
        auto compCount = pdr->composite_sensor_count;

        while (compCount--)
        {
            auto state = reinterpret_cast<const state_sensor_possible_states*>(
                statesPtr);
            output.emplace(("stateSetID[" + std::to_string(compCount) + "]"),
                           getStateSetName(state->state_set_id));
            output.emplace(
                ("possibleStatesSize[" + std::to_string(compCount) + "]"),
                state->possible_states_size);
            output.emplace(
                ("possibleStates[" + std::to_string(compCount) + "]"),
                getStateSetPossibleStateNames(
                    state->state_set_id,
                    printPossibleStates(state->possible_states_size,
                                        state->states)));

            if (compCount)
            {
                statesPtr += sizeof(state_sensor_possible_states) +
                             state->possible_states_size - 1;
            }
        }
    }

    void printPDRFruRecordSet(uint8_t* data, ordered_json& output)
    {
        if (data == NULL)
        {
            return;
        }

        data += sizeof(pldm_pdr_hdr);
        pldm_pdr_fru_record_set* pdr =
            reinterpret_cast<pldm_pdr_fru_record_set*>(data);
        if (!pdr)
        {
            std::cerr << "Failed to get the FRU record set PDR" << std::endl;
            return;
        }

        output["PLDMTerminusHandle"] = unsigned(pdr->terminus_handle);
        output["FRURecordSetIdentifier"] = unsigned(pdr->fru_rsi);
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = unsigned(pdr->entity_instance);
        output["containerID"] = unsigned(pdr->container_id);
    }

    void printPDREntityAssociation(uint8_t* data, ordered_json& output)
    {
        const std::map<uint8_t, const char*> assocationType = {
            {PLDM_ENTITY_ASSOCIAION_PHYSICAL, "Physical"},
            {PLDM_ENTITY_ASSOCIAION_LOGICAL, "Logical"},
        };

        if (data == NULL)
        {
            return;
        }

        data += sizeof(pldm_pdr_hdr);
        pldm_pdr_entity_association* pdr =
            reinterpret_cast<pldm_pdr_entity_association*>(data);
        if (!pdr)
        {
            std::cerr << "Failed to get the PDR eneity association"
                      << std::endl;
            return;
        }

        output["containerID"] = int(pdr->container_id);
        if (assocationType.contains(pdr->association_type))
        {
            output["associationType"] =
                assocationType.at(pdr->association_type);
        }
        else
        {
            std::cout << "Get associationType failed.\n";
        }
        output["containerEntityType"] =
            getEntityName(pdr->container.entity_type);
        output["containerEntityInstanceNumber"] =
            int(pdr->container.entity_instance_num);
        output["containerEntityContainerID"] =
            int(pdr->container.entity_container_id);
        output["containedEntityCount"] =
            static_cast<unsigned>(pdr->num_children);

        auto child = reinterpret_cast<pldm_entity*>(&pdr->children[0]);
        for (int i = 0; i < pdr->num_children; ++i)
        {
            output.emplace("containedEntityType[" + std::to_string(i + 1) + "]",
                           getEntityName(child->entity_type));
            output.emplace("containedEntityInstanceNumber[" +
                               std::to_string(i + 1) + "]",
                           unsigned(child->entity_instance_num));
            output.emplace("containedEntityContainerID[" +
                               std::to_string(i + 1) + "]",
                           unsigned(child->entity_container_id));

            ++child;
        }
    }

    /** @brief Format the Sensor/Effecter Aux Name PDR types to json output
     *
     *  @param[in] data - reference to the Sensor/Effecter Aux Name PDR
     *  @param[out] output - PDRs data fields in Json format
     */
    void printAuxNamePDR(uint8_t* data, ordered_json& output)
    {
        constexpr uint8_t nullTerminator = 0;
        struct pldm_effecter_aux_name_pdr* auxNamePdr =
            (struct pldm_effecter_aux_name_pdr*)data;

        if (!auxNamePdr)
        {
            std::cerr << "Failed to get Aux Name PDR" << std::endl;
            return;
        }

        std::string sPrefix = "effecter";
        if (auxNamePdr->hdr.type == PLDM_SENSOR_AUXILIARY_NAMES_PDR)
        {
            sPrefix = "sensor";
        }
        output["terminusHandle"] = int(auxNamePdr->terminus_handle);
        output[sPrefix + "Id"] = int(auxNamePdr->effecter_id);
        output[sPrefix + "Count"] = int(auxNamePdr->effecter_count);

        const uint8_t* ptr = auxNamePdr->effecter_names;
        for (auto i : std::views::iota(0, (int)auxNamePdr->effecter_count))
        {
            const uint8_t nameStringCount = static_cast<uint8_t>(*ptr);
            ptr += sizeof(uint8_t);
            for (auto j : std::views::iota(0, (int)nameStringCount))
            {
                std::string nameLanguageTagKey =
                    sPrefix + std::to_string(j) + "_nameLanguageTag" +
                    std::to_string(i);
                std::string entityAuxNameKey =
                    sPrefix + std::to_string(j) + "_entityAuxName" +
                    std::to_string(i);
                std::string nameLanguageTag(reinterpret_cast<const char*>(ptr),
                                            0, PLDM_STR_UTF_8_MAX_LEN);
                ptr += nameLanguageTag.size() + sizeof(nullTerminator);
                std::u16string u16NameString(
                    reinterpret_cast<const char16_t*>(ptr), 0,
                    PLDM_STR_UTF_16_MAX_LEN);
                ptr += (u16NameString.size() + sizeof(nullTerminator)) *
                       sizeof(uint16_t);
                std::transform(u16NameString.cbegin(), u16NameString.cend(),
                               u16NameString.begin(),
                               [](uint16_t utf16) { return be16toh(utf16); });
                std::string nameString =
                    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,
                                         char16_t>{}
                        .to_bytes(u16NameString);
                output[nameLanguageTagKey] = nameLanguageTag;
                output[entityAuxNameKey] = nameString;
            }
        }
    }

    void printNumericEffecterPDR(uint8_t* data, ordered_json& output)
    {
        struct pldm_numeric_effecter_value_pdr* pdr =
            (struct pldm_numeric_effecter_value_pdr*)data;
        if (!pdr)
        {
            std::cerr << "Failed to get numeric effecter PDR" << std::endl;
            return;
        }

        output["PLDMTerminusHandle"] = int(pdr->terminus_handle);
        output["effecterID"] = int(pdr->effecter_id);
        output["entityType"] = int(pdr->entity_type);
        output["entityInstanceNumber"] = int(pdr->entity_instance);
        output["containerID"] = int(pdr->container_id);
        output["effecterSemanticID"] = int(pdr->effecter_semantic_id);
        output["effecterInit"] = unsigned(pdr->effecter_init);
        output["effecterAuxiliaryNames"] =
            (unsigned(pdr->effecter_auxiliary_names) ? true : false);
        output["baseUnit"] = unsigned(pdr->base_unit);
        output["unitModifier"] = unsigned(pdr->unit_modifier);
        output["rateUnit"] = unsigned(pdr->rate_unit);
        output["baseOEMUnitHandle"] = unsigned(pdr->base_oem_unit_handle);
        output["auxUnit"] = unsigned(pdr->aux_unit);
        output["auxUnitModifier"] = unsigned(pdr->aux_unit_modifier);
        output["auxrateUnit"] = unsigned(pdr->aux_rate_unit);
        output["auxOEMUnitHandle"] = unsigned(pdr->aux_oem_unit_handle);
        output["isLinear"] = (unsigned(pdr->is_linear) ? true : false);
        output["effecterDataSize"] = unsigned(pdr->effecter_data_size);
        output["resolution"] = unsigned(pdr->resolution);
        output["offset"] = unsigned(pdr->offset);
        output["accuracy"] = unsigned(pdr->accuracy);
        output["plusTolerance"] = unsigned(pdr->plus_tolerance);
        output["minusTolerance"] = unsigned(pdr->minus_tolerance);
        output["stateTransitionInterval"] =
            unsigned(pdr->state_transition_interval);
        output["TransitionInterval"] = unsigned(pdr->transition_interval);

        switch (pdr->effecter_data_size)
        {
            case PLDM_EFFECTER_DATA_SIZE_UINT8:
                output["maxSettable"] = unsigned(pdr->max_settable.value_u8);
                output["minSettable"] = unsigned(pdr->min_settable.value_u8);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT8:
                output["maxSettable"] = unsigned(pdr->max_settable.value_s8);
                output["minSettable"] = unsigned(pdr->min_settable.value_s8);
                break;
            case PLDM_EFFECTER_DATA_SIZE_UINT16:
                output["maxSettable"] = unsigned(pdr->max_settable.value_u16);
                output["minSettable"] = unsigned(pdr->min_settable.value_u16);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT16:
                output["maxSettable"] = unsigned(pdr->max_settable.value_s16);
                output["minSettable"] = unsigned(pdr->min_settable.value_s16);
                break;
            case PLDM_EFFECTER_DATA_SIZE_UINT32:
                output["maxSettable"] = unsigned(pdr->max_settable.value_u32);
                output["minSettable"] = unsigned(pdr->min_settable.value_u32);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT32:
                output["maxSettable"] = unsigned(pdr->max_settable.value_s32);
                output["minSettable"] = unsigned(pdr->min_settable.value_s32);
                break;
            default:
                break;
        }

        output["rangeFieldFormat"] = unsigned(pdr->range_field_format);
        output["rangeFieldSupport"] = unsigned(pdr->range_field_support.byte);

        switch (pdr->range_field_format)
        {
            case PLDM_RANGE_FIELD_FORMAT_UINT8:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u8);
                output["normalMax"] = unsigned(pdr->normal_max.value_u8);
                output["normalMin"] = unsigned(pdr->normal_min.value_u8);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u8);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u8);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT8:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s8);
                output["normalMax"] = unsigned(pdr->normal_max.value_s8);
                output["normalMin"] = unsigned(pdr->normal_min.value_s8);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s8);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s8);
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT16:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u16);
                output["normalMax"] = unsigned(pdr->normal_max.value_u16);
                output["normalMin"] = unsigned(pdr->normal_min.value_u16);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u16);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u16);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT16:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s16);
                output["normalMax"] = unsigned(pdr->normal_max.value_s16);
                output["normalMin"] = unsigned(pdr->normal_min.value_s16);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s16);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s16);
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u32);
                output["normalMax"] = unsigned(pdr->normal_max.value_u32);
                output["normalMin"] = unsigned(pdr->normal_min.value_u32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u32);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s32);
                output["normalMax"] = unsigned(pdr->normal_max.value_s32);
                output["normalMin"] = unsigned(pdr->normal_min.value_s32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s32);
                break;
            case PLDM_RANGE_FIELD_FORMAT_REAL32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_f32);
                output["normalMax"] = unsigned(pdr->normal_max.value_f32);
                output["normalMin"] = unsigned(pdr->normal_min.value_f32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_f32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_f32);
                break;
            default:
                break;
        }
    }

    void printStateEffecterPDR(const uint8_t* data, ordered_json& output)
    {
        auto pdr = reinterpret_cast<const pldm_state_effecter_pdr*>(data);

        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["effecterID"] = pdr->effecter_id;
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = pdr->entity_instance;
        output["containerID"] = pdr->container_id;
        output["effecterSemanticID"] = pdr->effecter_semantic_id;
        output["effecterInit"] = effecterInit[pdr->effecter_init];
        output["effecterDescriptionPDR"] =
            (pdr->has_description_pdr ? true : false);
        output["compositeEffecterCount"] =
            unsigned(pdr->composite_effecter_count);

        auto statesPtr = pdr->possible_states;
        auto compEffCount = pdr->composite_effecter_count;

        while (compEffCount--)
        {
            auto state =
                reinterpret_cast<const state_effecter_possible_states*>(
                    statesPtr);
            output.emplace(("stateSetID[" + std::to_string(compEffCount) + "]"),
                           getStateSetName(state->state_set_id));
            output.emplace(
                ("possibleStatesSize[" + std::to_string(compEffCount) + "]"),
                state->possible_states_size);
            output.emplace(
                ("possibleStates[" + std::to_string(compEffCount) + "]"),
                getStateSetPossibleStateNames(
                    state->state_set_id,
                    printPossibleStates(state->possible_states_size,
                                        state->states)));

            if (compEffCount)
            {
                statesPtr += sizeof(state_effecter_possible_states) +
                             state->possible_states_size - 1;
            }
        }
    }

    bool checkTerminusHandle(const uint8_t* data,
                             std::optional<uint16_t> terminusHandle)
    {
        struct pldm_pdr_hdr* pdr = (struct pldm_pdr_hdr*)data;

        if (pdr->type == PLDM_TERMINUS_LOCATOR_PDR)
        {
            auto tlpdr =
                reinterpret_cast<const pldm_terminus_locator_pdr*>(data);

            if (tlpdr->terminus_handle != terminusHandle)
            {
                return true;
            }
        }
        else if (pdr->type == PLDM_STATE_SENSOR_PDR)
        {
            auto sensor = reinterpret_cast<const pldm_state_sensor_pdr*>(data);

            if (sensor->terminus_handle != terminusHandle)
            {
                return true;
            }
        }
        else if (pdr->type == PLDM_NUMERIC_EFFECTER_PDR)
        {
            auto numericEffecter =
                reinterpret_cast<const pldm_numeric_effecter_value_pdr*>(data);

            if (numericEffecter->terminus_handle != terminusHandle)
            {
                return true;
            }
        }

        else if (pdr->type == PLDM_STATE_EFFECTER_PDR)
        {
            auto stateEffecter =
                reinterpret_cast<const pldm_state_effecter_pdr*>(data);
            if (stateEffecter->terminus_handle != terminusHandle)
            {
                return true;
            }
        }
        else if (pdr->type == PLDM_PDR_FRU_RECORD_SET)
        {
            data += sizeof(pldm_pdr_hdr);
            auto fru = reinterpret_cast<const pldm_pdr_fru_record_set*>(data);

            if (fru->terminus_handle != terminusHandle)
            {
                return true;
            }
        }
        else
        {
            // Entity association PDRs does not have terminus handle
            return true;
        }

        return false;
    }

    void printTerminusLocatorPDR(const uint8_t* data, ordered_json& output)
    {
        const std::array<std::string_view, 4> terminusLocatorType = {
            "UID", "MCTP_EID", "SMBusRelative", "systemSoftware"};

        auto pdr = reinterpret_cast<const pldm_terminus_locator_pdr*>(data);

        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["validity"] = (pdr->validity ? "valid" : "notValid");
        output["TID"] = unsigned(pdr->tid);
        output["containerID"] = pdr->container_id;
        output["terminusLocatorType"] =
            terminusLocatorType[pdr->terminus_locator_type];
        output["terminusLocatorValueSize"] =
            unsigned(pdr->terminus_locator_value_size);

        if (pdr->terminus_locator_type == PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID)
        {
            auto locatorValue =
                reinterpret_cast<const pldm_terminus_locator_type_mctp_eid*>(
                    pdr->terminus_locator_value);
            output["EID"] = unsigned(locatorValue->eid);
        }
    }

    std::optional<uint16_t> getTerminusHandle(uint8_t* data,
                                              std::optional<uint8_t> tid)
    {
        struct pldm_pdr_hdr* pdr = (struct pldm_pdr_hdr*)data;
        if (pdr->type == PLDM_TERMINUS_LOCATOR_PDR)
        {
            auto pdr = reinterpret_cast<const pldm_terminus_locator_pdr*>(data);
            if (pdr->tid == tid)
            {
                handleFound = true;
                return pdr->terminus_handle;
            }
        }
        return std::nullopt;
    }

    /** @brief Format the Numeric Sensor PDR types to json output
     *
     *  @param[in] data - reference to the Numeric Sensor PDR
     *  @param[in] data_length - number of PDR data bytes
     *  @param[out] output - PDRs data fields in Json format
     */
    void printNumericSensorPDR(const uint8_t* data, const uint16_t data_length,
                               ordered_json& output)
    {
        struct pldm_numeric_sensor_value_pdr pdr;
        int rc =
            decode_numeric_sensor_pdr_data(data, (size_t)data_length, &pdr);
        if (rc != PLDM_SUCCESS)
        {
            std::cerr << "Failed to get numeric sensor PDR" << std::endl;
            return;
        }
        output["PLDMTerminusHandle"] = pdr.terminus_handle;
        output["sensorID"] = pdr.sensor_id;
        output["entityType"] = getEntityName(pdr.entity_type);
        output["entityInstanceNumber"] = pdr.entity_instance_num;
        output["containerID"] = pdr.container_id;
        output["sensorInit"] = pdr.sensor_init;
        output["sensorAuxiliaryNamesPDR"] =
            (pdr.sensor_auxiliary_names_pdr) ? true : false;
        output["baseUnit"] = pdr.base_unit;
        output["unitModifier"] = pdr.unit_modifier;
        output["rateUnit"] = pdr.rate_unit;
        output["baseOEMUnitHandle"] = pdr.base_oem_unit_handle;
        output["auxUnit"] = pdr.aux_unit;
        output["auxUnitModifier"] = pdr.aux_unit_modifier;
        output["auxrateUnit"] = pdr.aux_rate_unit;
        output["rel"] = pdr.rel;
        output["auxOEMUnitHandle"] = pdr.aux_oem_unit_handle;
        output["isLinear"] = (pdr.is_linear) ? true : false;
        output["sensorDataSize"] = pdr.sensor_data_size;
        output["resolution"] = pdr.resolution;
        output["offset"] = pdr.offset;
        output["accuracy"] = pdr.accuracy;
        output["plusTolerance"] = pdr.plus_tolerance;
        output["minusTolerance"] = pdr.minus_tolerance;

        switch (pdr.sensor_data_size)
        {
            case PLDM_SENSOR_DATA_SIZE_UINT8:
                output["hysteresis"] = pdr.hysteresis.value_u8;
                output["maxReadable"] = pdr.max_readable.value_u8;
                output["minReadable"] = pdr.min_readable.value_u8;
                break;
            case PLDM_SENSOR_DATA_SIZE_SINT8:
                output["hysteresis"] = pdr.hysteresis.value_s8;
                output["maxReadable"] = pdr.max_readable.value_s8;
                output["minReadable"] = pdr.min_readable.value_s8;
                break;
            case PLDM_SENSOR_DATA_SIZE_UINT16:
                output["hysteresis"] = pdr.hysteresis.value_u16;
                output["maxReadable"] = pdr.max_readable.value_u16;
                output["minReadable"] = pdr.min_readable.value_u16;
                break;
            case PLDM_SENSOR_DATA_SIZE_SINT16:
                output["hysteresis"] = pdr.hysteresis.value_s16;
                output["maxReadable"] = pdr.max_readable.value_s16;
                output["minReadable"] = pdr.min_readable.value_s16;
                break;
            case PLDM_SENSOR_DATA_SIZE_UINT32:
                output["hysteresis"] = pdr.hysteresis.value_u32;
                output["maxReadable"] = pdr.max_readable.value_u32;
                output["minReadable"] = pdr.min_readable.value_u32;
                break;
            case PLDM_SENSOR_DATA_SIZE_SINT32:
                output["hysteresis"] = pdr.hysteresis.value_s32;
                output["maxReadable"] = pdr.max_readable.value_s32;
                output["minReadable"] = pdr.min_readable.value_s32;
                break;
            default:
                break;
        }

        output["supportedThresholds"] = pdr.supported_thresholds.byte;
        output["thresholAndHysteresisVolatility"] =
            pdr.threshold_and_hysteresis_volatility.byte;
        output["stateTransitionInterval"] = pdr.state_transition_interval;
        output["updateInterval"] = pdr.update_interval;
        output["rangeFieldFormat"] = pdr.range_field_format;
        output["rangeFieldSupport"] = pdr.range_field_support.byte;

        switch (pdr.range_field_format)
        {
            case PLDM_RANGE_FIELD_FORMAT_UINT8:
                output["nominalValue"] = pdr.nominal_value.value_u8;
                output["normalMax"] = pdr.normal_max.value_u8;
                output["normalMin"] = pdr.normal_min.value_u8;
                output["warningHigh"] = pdr.warning_high.value_u8;
                output["warningLow"] = pdr.warning_low.value_u8;
                output["criticalHigh"] = pdr.critical_high.value_u8;
                output["criticalLow"] = pdr.critical_low.value_u8;
                output["fatalHigh"] = pdr.fatal_high.value_u8;
                output["fatalLeow"] = pdr.fatal_low.value_u8;
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT8:
                output["nominalValue"] = pdr.nominal_value.value_s8;
                output["normalMax"] = pdr.normal_max.value_s8;
                output["normalMin"] = pdr.normal_min.value_s8;
                output["warningHigh"] = pdr.warning_high.value_s8;
                output["warningLow"] = pdr.warning_low.value_s8;
                output["criticalHigh"] = pdr.critical_high.value_s8;
                output["criticalLow"] = pdr.critical_low.value_s8;
                output["fatalHigh"] = pdr.fatal_high.value_s8;
                output["fatalLeow"] = pdr.fatal_low.value_s8;
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT16:
                output["nominalValue"] = pdr.nominal_value.value_u16;
                output["normalMax"] = pdr.normal_max.value_u16;
                output["normalMin"] = pdr.normal_min.value_u16;
                output["warningHigh"] = pdr.warning_high.value_u16;
                output["warningLow"] = pdr.warning_low.value_u16;
                output["criticalHigh"] = pdr.critical_high.value_u16;
                output["criticalLow"] = pdr.critical_low.value_u16;
                output["fatalHigh"] = pdr.fatal_high.value_u16;
                output["fatalLeow"] = pdr.fatal_low.value_u16;
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT16:
                output["nominalValue"] = pdr.nominal_value.value_s16;
                output["normalMax"] = pdr.normal_max.value_s16;
                output["normalMin"] = pdr.normal_min.value_s16;
                output["warningHigh"] = pdr.warning_high.value_s16;
                output["warningLow"] = pdr.warning_low.value_s16;
                output["criticalHigh"] = pdr.critical_high.value_s16;
                output["criticalLow"] = pdr.critical_low.value_s16;
                output["fatalHigh"] = pdr.fatal_high.value_s16;
                output["fatalLeow"] = pdr.fatal_low.value_s16;
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT32:
                output["nominalValue"] = pdr.nominal_value.value_u32;
                output["normalMax"] = pdr.normal_max.value_u32;
                output["normalMin"] = pdr.normal_min.value_u32;
                output["warningHigh"] = pdr.warning_high.value_u32;
                output["warningLow"] = pdr.warning_low.value_u32;
                output["criticalHigh"] = pdr.critical_high.value_u32;
                output["criticalLow"] = pdr.critical_low.value_u32;
                output["fatalHigh"] = pdr.fatal_high.value_u32;
                output["fatalLeow"] = pdr.fatal_low.value_u32;
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT32:
                output["nominalValue"] = pdr.nominal_value.value_s32;
                output["normalMax"] = pdr.normal_max.value_s32;
                output["normalMin"] = pdr.normal_min.value_s32;
                output["warningHigh"] = pdr.warning_high.value_s32;
                output["warningLow"] = pdr.warning_low.value_s32;
                output["criticalHigh"] = pdr.critical_high.value_s32;
                output["criticalLow"] = pdr.critical_low.value_s32;
                output["fatalHigh"] = pdr.fatal_high.value_s32;
                output["fatalLeow"] = pdr.fatal_low.value_s32;
                break;
            case PLDM_RANGE_FIELD_FORMAT_REAL32:
                output["nominalValue"] = pdr.nominal_value.value_f32;
                output["normalMax"] = pdr.normal_max.value_f32;
                output["normalMin"] = pdr.normal_min.value_f32;
                output["warningHigh"] = pdr.warning_high.value_f32;
                output["warningLow"] = pdr.warning_low.value_f32;
                output["criticalHigh"] = pdr.critical_high.value_f32;
                output["criticalLow"] = pdr.critical_low.value_f32;
                output["fatalHigh"] = pdr.fatal_high.value_f32;
                output["fatalLeow"] = pdr.fatal_low.value_f32;
                break;
            default:
                break;
        }
    }

    /** @brief Format the Compact Numeric Sensor PDR types to json output
     *
     *  @param[in] data - reference to the Compact Numeric Sensor PDR
     *  @param[out] output - PDRs data fields in Json format
     */
    void printCompactNumericSensorPDR(const uint8_t* data, ordered_json& output)
    {
        struct pldm_compact_numeric_sensor_pdr* pdr =
            (struct pldm_compact_numeric_sensor_pdr*)data;
        if (!pdr)
        {
            std::cerr << "Failed to get compact numeric sensor PDR"
                      << std::endl;
            return;
        }
        output["PLDMTerminusHandle"] = int(pdr->terminus_handle);
        output["sensorID"] = int(pdr->sensor_id);
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = int(pdr->entity_instance);
        output["containerID"] = int(pdr->container_id);
        output["sensorNameStringByteLength"] = int(pdr->sensor_name_length);
        if (pdr->sensor_name_length == 0)
        {
            output["Name"] = std::format("PLDM_Device_TID{}_SensorId{}",
                                         unsigned(pdr->terminus_handle),
                                         unsigned(pdr->sensor_id));
        }
        else
        {
            std::string sTemp(reinterpret_cast<const char*>(pdr->sensor_name),
                              pdr->sensor_name_length);
            output["Name"] = sTemp;
        }
        output["baseUnit"] = unsigned(pdr->base_unit);
        output["unitModifier"] = signed(pdr->unit_modifier);
        output["occurrenceRate"] = unsigned(pdr->occurrence_rate);
        output["rangeFieldSupport"] = unsigned(pdr->range_field_support.byte);
        if (pdr->range_field_support.bits.bit0)
        {
            output["warningHigh"] = int(pdr->warning_high);
        }
        if (pdr->range_field_support.bits.bit1)
        {
            output["warningLow"] = int(pdr->warning_low);
        }
        if (pdr->range_field_support.bits.bit2)
        {
            output["criticalHigh"] = int(pdr->critical_high);
        }
        if (pdr->range_field_support.bits.bit3)
        {
            output["criticalLow"] = int(pdr->critical_low);
        }
        if (pdr->range_field_support.bits.bit4)
        {
            output["fatalHigh"] = int(pdr->fatal_high);
        }
        if (pdr->range_field_support.bits.bit5)
        {
            output["fatalLow"] = int(pdr->fatal_low);
        }
    }

    void printPDRMsg(uint32_t& nextRecordHndl, const uint16_t respCnt,
                     uint8_t* data, std::optional<uint16_t> terminusHandle)
    {
        if (data == NULL)
        {
            std::cerr << "Failed to get PDR message" << std::endl;
            return;
        }

        ordered_json output;
        output["nextRecordHandle"] = nextRecordHndl;
        output["responseCount"] = respCnt;

        struct pldm_pdr_hdr* pdr = (struct pldm_pdr_hdr*)data;
        if (!pdr)
        {
            return;
        }

        if (!pdrRecType.empty())
        {
            // Need to return if the requested PDR type
            // is not supported
            if (!strToPdrType.contains(pdrRecType))
            {
                std::cerr << "PDR type '" << pdrRecType
                          << "' is not supported or invalid\n";
                // PDR type not supported, setting next record handle to
                // 0 to avoid looping through all PDR records
                nextRecordHndl = 0;
                return;
            }

            // Do not print PDR record if the current record
            // PDR type does not match with requested type
            if (pdr->type != strToPdrType.at(pdrRecType))
            {
                return;
            }
        }

        if (pdrTerminus.has_value())
        {
            if (checkTerminusHandle(data, terminusHandle))
            {
                std::cerr << "The Terminus handle doesn't match return"
                          << std::endl;
                return;
            }
        }

        printCommonPDRHeader(pdr, output);

        switch (pdr->type)
        {
            case PLDM_TERMINUS_LOCATOR_PDR:
                printTerminusLocatorPDR(data, output);
                break;
            case PLDM_STATE_SENSOR_PDR:
                printStateSensorPDR(data, output);
                break;
            case PLDM_NUMERIC_EFFECTER_PDR:
                printNumericEffecterPDR(data, output);
                break;
            case PLDM_NUMERIC_SENSOR_PDR:
                printNumericSensorPDR(data, respCnt, output);
                break;
            case PLDM_SENSOR_AUXILIARY_NAMES_PDR:
            case PLDM_EFFECTER_AUXILIARY_NAMES_PDR:
                printAuxNamePDR(data, output);
                break;
            case PLDM_STATE_EFFECTER_PDR:
                printStateEffecterPDR(data, output);
                break;
            case PLDM_PDR_ENTITY_ASSOCIATION:
                printPDREntityAssociation(data, output);
                break;
            case PLDM_PDR_FRU_RECORD_SET:
                printPDRFruRecordSet(data, output);
                break;
            case PLDM_COMPACT_NUMERIC_SENSOR_PDR:
                printCompactNumericSensorPDR(data, output);
                break;
            default:
                break;
        }
        pldmtool::helper::DisplayInJson(output);
    }

  private:
    bool optTIDSet = false;
    uint32_t recordHandle;
    bool allPDRs;
    std::string pdrRecType;
    std::optional<uint8_t> pdrTerminus;
    std::optional<uint16_t> terminusHandle;
    bool handleFound = false;
    CLI::Option* getPDRGroupOption = nullptr;
    uint32_t dataTransferHandle;
    uint8_t operationFlag;
    uint16_t requestCount;
    uint16_t recordChangeNumber;
    std::vector<uint8_t> recordData;
    bool nextPartRequired;
};

class SetStateEffecter : public CommandInterface
{
  public:
    ~SetStateEffecter() = default;
    SetStateEffecter() = delete;
    SetStateEffecter(const SetStateEffecter&) = delete;
    SetStateEffecter(SetStateEffecter&&) = default;
    SetStateEffecter& operator=(const SetStateEffecter&) = delete;
    SetStateEffecter& operator=(SetStateEffecter&&) = delete;

    // compositeEffecterCount(value: 0x01 to 0x08) * stateField(2)
    static constexpr auto maxEffecterDataSize = 16;

    // compositeEffecterCount(value: 0x01 to 0x08)
    static constexpr auto minEffecterCount = 1;
    static constexpr auto maxEffecterCount = 8;
    explicit SetStateEffecter(const char* type, const char* name,
                              CLI::App* app) : CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --id", effecterId,
               "A handle that is used to identify and access the effecter")
            ->required();
        app->add_option("-c, --count", effecterCount,
                        "The number of individual sets of effecter information")
            ->required();
        app->add_option(
               "-d,--data", effecterData,
               "Set effecter state data\n"
               "eg: requestSet0 effecterState0 noChange1 dummyState1 ...")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        if (effecterCount > maxEffecterCount ||
            effecterCount < minEffecterCount)
        {
            std::cerr << "Request Message Error: effecterCount size "
                      << effecterCount << "is invalid\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        if (effecterData.size() > maxEffecterDataSize)
        {
            std::cerr << "Request Message Error: effecterData size "
                      << effecterData.size() << "is invalid\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        auto stateField = parseEffecterData(effecterData, effecterCount);
        if (!stateField)
        {
            std::cerr << "Failed to parse effecter data, effecterCount size "
                      << effecterCount << "\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        auto rc = encode_set_state_effecter_states_req(
            instanceId, effecterId, effecterCount, stateField->data(), request);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        auto rc = decode_set_state_effecter_states_resp(
            responsePtr, payloadLength, &completionCode);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode << "\n";
            return;
        }

        ordered_json data;
        data["Response"] = "SUCCESS";
        pldmtool::helper::DisplayInJson(data);
    }

  private:
    uint16_t effecterId;
    uint8_t effecterCount;
    std::vector<uint8_t> effecterData;
};

class SetNumericEffecterValue : public CommandInterface
{
  public:
    ~SetNumericEffecterValue() = default;
    SetNumericEffecterValue() = delete;
    SetNumericEffecterValue(const SetNumericEffecterValue&) = delete;
    SetNumericEffecterValue(SetNumericEffecterValue&&) = default;
    SetNumericEffecterValue& operator=(const SetNumericEffecterValue&) = delete;
    SetNumericEffecterValue& operator=(SetNumericEffecterValue&&) = delete;

    explicit SetNumericEffecterValue(const char* type, const char* name,
                                     CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --id", effecterId,
               "A handle that is used to identify and access the effecter")
            ->required();
        app->add_option("-s, --size", effecterDataSize,
                        "The bit width and format of the setting value for the "
                        "effecter. enum value: {uint8, sint8, uint16, sint16, "
                        "uint32, sint32}\n")
            ->required();
        app->add_option("-d,--data", maxEffecterValue,
                        "The setting value of numeric effecter being "
                        "requested\n")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) +
            PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 3);

        uint8_t* effecterValue = (uint8_t*)&maxEffecterValue;

        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
        size_t payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES;

        if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT16 ||
            effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT16)
        {
            payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 1;
        }
        if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT32 ||
            effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT32)
        {
            payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 3;
        }
        auto rc = encode_set_numeric_effecter_value_req(
            0, effecterId, effecterDataSize, effecterValue, request,
            payload_length);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        auto rc = decode_set_numeric_effecter_value_resp(
            responsePtr, payloadLength, &completionCode);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }

        ordered_json data;
        data["Response"] = "SUCCESS";
        pldmtool::helper::DisplayInJson(data);
    }

  private:
    uint16_t effecterId;
    uint8_t effecterDataSize;
    uint64_t maxEffecterValue;
};

class GetStateSensorReadings : public CommandInterface
{
  public:
    ~GetStateSensorReadings() = default;
    GetStateSensorReadings() = delete;
    GetStateSensorReadings(const GetStateSensorReadings&) = delete;
    GetStateSensorReadings(GetStateSensorReadings&&) = default;
    GetStateSensorReadings& operator=(const GetStateSensorReadings&) = delete;
    GetStateSensorReadings& operator=(GetStateSensorReadings&&) = delete;

    explicit GetStateSensorReadings(const char* type, const char* name,
                                    CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --sensor_id", sensorId,
               "Sensor ID that is used to identify and access the sensor")
            ->required();
        app->add_option("-r, --rearm", sensorRearm,
                        "Each bit location in this field corresponds to a "
                        "particular sensor")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_STATE_SENSOR_READINGS_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        uint8_t reserved = 0;
        bitfield8_t bf;
        bf.byte = sensorRearm;
        auto rc = encode_get_state_sensor_readings_req(instanceId, sensorId, bf,
                                                       reserved, request);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t compSensorCount = 0;
        std::array<get_sensor_state_field, 8> stateField{};
        auto rc = decode_get_state_sensor_readings_resp(
            responsePtr, payloadLength, &completionCode, &compSensorCount,
            stateField.data());

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }
        ordered_json output;
        output["compositeSensorCount"] = (int)compSensorCount;

        for (size_t i = 0; i < compSensorCount; i++)
        {
            if (sensorOpState.contains(stateField[i].sensor_op_state))
            {
                output.emplace(("sensorOpState[" + std::to_string(i) + "]"),
                               sensorOpState.at(stateField[i].sensor_op_state));
            }

            if (sensorPresState.contains(stateField[i].present_state))
            {
                output.emplace(("presentState[" + std::to_string(i) + "]"),
                               sensorPresState.at(stateField[i].present_state));
            }

            if (sensorPresState.contains(stateField[i].previous_state))
            {
                output.emplace(
                    ("previousState[" + std::to_string(i) + "]"),
                    sensorPresState.at(stateField[i].previous_state));
            }

            if (sensorPresState.contains(stateField[i].event_state))
            {
                output.emplace(("eventState[" + std::to_string(i) + "]"),
                               sensorPresState.at(stateField[i].event_state));
            }
        }

        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint16_t sensorId;
    uint8_t sensorRearm;
};

class GetSensorReading : public CommandInterface
{
  public:
    ~GetSensorReading() = default;
    GetSensorReading() = delete;
    GetSensorReading(const GetSensorReading&) = delete;
    GetSensorReading(GetSensorReading&&) = default;
    GetSensorReading& operator=(const GetSensorReading&) = delete;
    GetSensorReading& operator=(GetSensorReading&&) = delete;

    explicit GetSensorReading(const char* type, const char* name,
                              CLI::App* app) : CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --sensor_id", sensorId,
               "Sensor ID that is used to identify and access the sensor")
            ->required();
        app->add_option("-r, --rearm", rearm,
                        "Manually re-arm EventState after "
                        "responding to this request")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_SENSOR_READING_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc =
            encode_get_sensor_reading_req(instanceId, sensorId, rearm, request);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t sensorDataSize = 0;
        uint8_t sensorOperationalState = 0;
        uint8_t sensorEventMessageEnable = 0;
        uint8_t presentState = 0;
        uint8_t previousState = 0;
        uint8_t eventState = 0;
        std::array<uint8_t, sizeof(uint32_t)>
            presentReading{}; // maximum size for the present Value is uint32
                              // according to spec DSP0248

        auto rc = decode_get_sensor_reading_resp(
            responsePtr, payloadLength, &completionCode, &sensorDataSize,
            &sensorOperationalState, &sensorEventMessageEnable, &presentState,
            &previousState, &eventState, presentReading.data());

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }

        ordered_json output;
        output["sensorDataSize"] =
            getSensorState(sensorDataSize, &sensorDataSz);
        output["sensorOperationalState"] =
            getSensorState(sensorOperationalState, &sensorOpState);
        output["sensorEventMessageEnable"] =
            getSensorState(sensorEventMessageEnable, &sensorEventMsgEnable);
        output["presentState"] = getSensorState(presentState, &sensorPresState);
        output["previousState"] =
            getSensorState(previousState, &sensorPresState);
        output["eventState"] = getSensorState(eventState, &sensorPresState);

        switch (sensorDataSize)
        {
            case PLDM_SENSOR_DATA_SIZE_UINT8:
            {
                output["presentReading"] =
                    *(reinterpret_cast<uint8_t*>(presentReading.data()));
                break;
            }
            case PLDM_SENSOR_DATA_SIZE_SINT8:
            {
                output["presentReading"] =
                    *(reinterpret_cast<int8_t*>(presentReading.data()));
                break;
            }
            case PLDM_SENSOR_DATA_SIZE_UINT16:
            {
                output["presentReading"] =
                    *(reinterpret_cast<uint16_t*>(presentReading.data()));
                break;
            }
            case PLDM_SENSOR_DATA_SIZE_SINT16:
            {
                output["presentReading"] =
                    *(reinterpret_cast<int16_t*>(presentReading.data()));
                break;
            }
            case PLDM_SENSOR_DATA_SIZE_UINT32:
            {
                output["presentReading"] =
                    *(reinterpret_cast<uint32_t*>(presentReading.data()));
                break;
            }
            case PLDM_SENSOR_DATA_SIZE_SINT32:
            {
                output["presentReading"] =
                    *(reinterpret_cast<int32_t*>(presentReading.data()));
                break;
            }
            default:
            {
                std::cerr << "Unknown Sensor Data Size : "
                          << static_cast<int>(sensorDataSize) << std::endl;
                break;
            }
        }

        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint16_t sensorId;
    uint8_t rearm;

    const std::map<uint8_t, std::string> sensorDataSz = {
        {PLDM_SENSOR_DATA_SIZE_UINT8, "uint8"},
        {PLDM_SENSOR_DATA_SIZE_SINT8, "uint8"},
        {PLDM_SENSOR_DATA_SIZE_UINT16, "uint16"},
        {PLDM_SENSOR_DATA_SIZE_SINT16, "uint16"},
        {PLDM_SENSOR_DATA_SIZE_UINT32, "uint32"},
        {PLDM_SENSOR_DATA_SIZE_SINT32, "uint32"}};

    static inline const std::map<uint8_t, std::string> sensorEventMsgEnable{
        {PLDM_NO_EVENT_GENERATION, "Sensor No Event Generation"},
        {PLDM_EVENTS_DISABLED, "Sensor Events Disabled"},
        {PLDM_EVENTS_ENABLED, "Sensor Events Enabled"},
        {PLDM_OP_EVENTS_ONLY_ENABLED, "Sensor Op Events Only Enabled"},
        {PLDM_STATE_EVENTS_ONLY_ENABLED, "Sensor State Events Only Enabled"}};

    std::string getSensorState(uint8_t state,
                               const std::map<uint8_t, std::string>* cont)
    {
        auto typeString = std::to_string(state);
        try
        {
            return cont->at(state);
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }
};

class GetStateEffecterStates : public CommandInterface
{
  public:
    ~GetStateEffecterStates() = default;
    GetStateEffecterStates() = delete;
    GetStateEffecterStates(const GetStateEffecterStates&) = delete;
    GetStateEffecterStates(GetStateEffecterStates&&) = default;
    GetStateEffecterStates& operator=(const GetStateEffecterStates&) = delete;
    GetStateEffecterStates& operator=(GetStateEffecterStates&&) = delete;

    explicit GetStateEffecterStates(const char* type, const char* name,
                                    CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --effecter_id", effecter_id,
               "Effecter ID that is used to identify and access the effecter")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_STATE_EFFECTER_STATES_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_state_effecter_states_req(
            instanceId, effecter_id, request,
            PLDM_GET_STATE_EFFECTER_STATES_REQ_BYTES);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        struct pldm_get_state_effecter_states_resp resp;
        auto rc = decode_get_state_effecter_states_resp(responsePtr,
                                                        payloadLength, &resp);

        if (rc || resp.completion_code != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc="
                      << static_cast<int>(resp.completion_code) << std::endl;
            return;
        }
        ordered_json output;
        auto comp_effecter_count = static_cast<int>(resp.comp_effecter_count);
        output["compositeEffecterCount"] = comp_effecter_count;

        for (auto i : std::views::iota(0, comp_effecter_count))
        {
            output[std::format("effecterOpState[{}])", i)] =
                getEffecterOpState(resp.field[i].effecter_op_state);

            output[std::format("pendingState[{}]", i)] =
                resp.field[i].pending_state;

            output[std::format("presentState[{}]", i)] =
                resp.field[i].present_state;
        }

        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint16_t effecter_id;
};

class GetNumericEffecterValue : public CommandInterface
{
  public:
    ~GetNumericEffecterValue() = default;
    GetNumericEffecterValue() = delete;
    GetNumericEffecterValue(const GetNumericEffecterValue&) = delete;
    GetNumericEffecterValue(GetNumericEffecterValue&&) = default;
    GetNumericEffecterValue& operator=(const GetNumericEffecterValue&) = delete;
    GetNumericEffecterValue& operator=(GetNumericEffecterValue&&) = delete;

    explicit GetNumericEffecterValue(const char* type, const char* name,
                                     CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --effecter_id", effecterId,
               "A handle that is used to identify and access the effecter")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_NUMERIC_EFFECTER_VALUE_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_numeric_effecter_value_req(instanceId, effecterId,
                                                        request);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t effecterDataSize = 0;
        uint8_t effecterOperationalState = 0;
        std::array<uint8_t, sizeof(uint32_t)>
            pendingValue{}; // maximum size for the pending Value is uint32
                            // according to spec DSP0248
        std::array<uint8_t, sizeof(uint32_t)>
            presentValue{}; // maximum size for the present Value is uint32
                            // according to spec DSP0248

        auto rc = decode_get_numeric_effecter_value_resp(
            responsePtr, payloadLength, &completionCode, &effecterDataSize,
            &effecterOperationalState, pendingValue.data(),
            presentValue.data());

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc="
                      << static_cast<int>(completionCode) << std::endl;
            return;
        }

        ordered_json output;
        output["effecterDataSize"] = static_cast<int>(effecterDataSize);
        output["effecterOperationalState"] =
            getEffecterOpState(effecterOperationalState);

        switch (effecterDataSize)
        {
            case PLDM_EFFECTER_DATA_SIZE_UINT8:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<uint8_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<uint8_t*>(presentValue.data()));
                break;
            }
            case PLDM_EFFECTER_DATA_SIZE_SINT8:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<int8_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<int8_t*>(presentValue.data()));
                break;
            }
            case PLDM_EFFECTER_DATA_SIZE_UINT16:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<uint16_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<uint16_t*>(presentValue.data()));
                break;
            }
            case PLDM_EFFECTER_DATA_SIZE_SINT16:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<int16_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<int16_t*>(presentValue.data()));
                break;
            }
            case PLDM_EFFECTER_DATA_SIZE_UINT32:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<uint32_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<uint32_t*>(presentValue.data()));
                break;
            }
            case PLDM_EFFECTER_DATA_SIZE_SINT32:
            {
                output["pendingValue"] =
                    *(reinterpret_cast<int32_t*>(pendingValue.data()));
                output["presentValue"] =
                    *(reinterpret_cast<int32_t*>(presentValue.data()));
                break;
            }
            default:
            {
                std::cerr << "Unknown Effecter Data Size : "
                          << static_cast<int>(effecterDataSize) << std::endl;
                break;
            }
        }

        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint16_t effecterId;
};

void registerCommand(CLI::App& app)
{
    auto platform = app.add_subcommand("platform", "platform type command");
    platform->require_subcommand(1);

    auto getPDR =
        platform->add_subcommand("GetPDR", "get platform descriptor records");
    commands.push_back(std::make_unique<GetPDR>("platform", "getPDR", getPDR));

    auto setStateEffecterStates = platform->add_subcommand(
        "SetStateEffecterStates", "set effecter states");
    commands.push_back(std::make_unique<SetStateEffecter>(
        "platform", "setStateEffecterStates", setStateEffecterStates));

    auto setNumericEffecterValue = platform->add_subcommand(
        "SetNumericEffecterValue", "set the value for a PLDM Numeric Effecter");
    commands.push_back(std::make_unique<SetNumericEffecterValue>(
        "platform", "setNumericEffecterValue", setNumericEffecterValue));

    auto getStateSensorReadings = platform->add_subcommand(
        "GetStateSensorReadings", "get the state sensor readings");
    commands.push_back(std::make_unique<GetStateSensorReadings>(
        "platform", "getStateSensorReadings", getStateSensorReadings));

    auto getNumericEffecterValue = platform->add_subcommand(
        "GetNumericEffecterValue", "get the numeric effecter value");
    commands.push_back(std::make_unique<GetNumericEffecterValue>(
        "platform", "getNumericEffecterValue", getNumericEffecterValue));

    auto getSensorReading = platform->add_subcommand(
        "GetSensorReading", "get the numeric sensor reading");
    commands.push_back(std::make_unique<GetSensorReading>(
        "platform", "getSensorReading", getSensorReading));

    auto getStateEffecterStates = platform->add_subcommand(
        "GetStateEffecterStates", "get the state effecter states");
    commands.push_back(std::make_unique<GetStateEffecterStates>(
        "platform", "getStateEffecterStates", getStateEffecterStates));
}

void parseGetPDROption()
{
    for (const auto& command : commands)
    {
        if (command.get()->getPLDMType() == "platform" &&
            command.get()->getCommandName() == "getPDR")
        {
            auto getPDR = dynamic_cast<GetPDR*>(command.get());
            getPDR->parseGetPDROptions();
        }
    }
}

} // namespace platform
} // namespace pldmtool
