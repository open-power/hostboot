#include "fru_oem_ibm.hpp"

#include <com/ibm/VPD/Manager/client.hpp>
#include <phosphor-logging/lg2.hpp>

#include <format>
#include <ranges>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace responder
{
namespace oem_ibm_fru
{

void pldm::responder::oem_ibm_fru::Handler::setIBMFruHandler(
    pldm::responder::fru::Handler* handler)
{
    fruHandler = handler;
}

int pldm::responder::oem_ibm_fru::Handler::processOEMFRUTable(
    const std::vector<uint8_t>& fruData)
{
    uint8_t dataSize = 0;
    const uint8_t* data = fruData.data();

    while (dataSize < fruData.size())
    {
        auto record =
            reinterpret_cast<const pldm_fru_record_data_format*>(data);
        if (!record)
        {
            return PLDM_ERROR_INVALID_DATA;
        }

        auto& entityAssociationMap = getAssociateEntityMap();
        uint16_t fruRSI = le16toh(record->record_set_id);

        dataSize += sizeof(pldm_fru_record_data_format) -
                    sizeof(pldm_fru_record_tlv);
        data += dataSize;

        for ([[maybe_unused]] const auto& i :
             std::views::iota(0, (int)record->num_fru_fields))
        {
            auto tlv = reinterpret_cast<const pldm_fru_record_tlv*>(data);
            if (!tlv)
            {
                return PLDM_ERROR_INVALID_DATA;
            }

            if (tlv->type == PLDM_OEM_FRU_FIELD_TYPE_PCIE_CONFIG_SPACE_DATA)
            {
                auto pcieData =
                    reinterpret_cast<const PcieConfigSpaceData*>(tlv->value);

                if (!pcieData)
                {
                    return PLDM_ERROR_INVALID_DATA;
                }

                auto vendorId =
                    std::format("0x{:04x}", htole16(pcieData->vendorId));
                auto deviceId =
                    std::format("0x{:04x}", htole16(pcieData->deviceId));
                auto revisionId =
                    std::format("0x{:02x}", htole16(pcieData->revisionId));

                std::string classCode = "0x";
                for (const auto& ele : pcieData->classCode)
                {
                    classCode += std::format("{:02x}", ele);
                }

                auto subSystemVendorId = std::format(
                    "0x{:04x}", htole16(pcieData->subSystemVendorId));
                auto subSystemId =
                    std::format("0x{:04x}", htole16(pcieData->subSystemId));

                updateDBusProperty(fruRSI, entityAssociationMap, vendorId,
                                   deviceId, revisionId, classCode,
                                   subSystemVendorId, subSystemId);
            }

            if (tlv->type == PLDM_OEM_IBM_FRU_FIELD_TYPE_FIRMWARE_UAK)
            {
                std::vector<uint8_t> value(&tlv->value[0],
                                           &tlv->value[tlv->length]);
                setFirmwareUAK(value);
            }
            // length of tlv is removed from the structure pldm_fru_record_tlv
            // and the new tlv length is added back.
            dataSize += sizeof(pldm_fru_record_tlv) - sizeof(uint8_t) +
                        tlv->length;
            data += dataSize;
        }
    }

    return PLDM_SUCCESS;
}

void Handler::updateDBusProperty(
    uint16_t fruRSI, const AssociatedEntityMap& fruAssociationMap,
    const std::string& vendorId, const std::string& deviceId,
    const std::string& revisionId, const std::string& classCode,
    const std::string& subSystemVendorId, const std::string& subSystemId)
{
    uint16_t entityType{};
    uint16_t entityInstanceNum{};
    uint16_t containerId{};
    uint16_t terminusHandle{};
    const pldm_pdr_record* record{};

    record = pldm_pdr_fru_record_set_find_by_rsi(
        pdrRepo, fruRSI, &terminusHandle, &entityType, &entityInstanceNum,
        &containerId);

    if (record)
    {
        for (const auto& [key, value] : fruAssociationMap)
        {
            if (entityInstanceNum == value.entity_instance_num &&
                entityType == value.entity_type &&
                containerId == value.entity_container_id)
            {
                if (!(pldm::responder::utils::checkIfIBMFru(key)))
                {
                    pldm::utils::setFruPresence(key, true);
                }
                dbus_map_update(key, "Function0VendorId", vendorId);
                dbus_map_update(key, "Function0DeviceId", deviceId);
                dbus_map_update(key, "Function0RevisionId", revisionId);
                dbus_map_update(key, "Function0ClassCode", classCode);
                dbus_map_update(key, "Function0SubsystemVendorId",
                                subSystemVendorId);
                dbus_map_update(key, "Function0SubsystemId", subSystemId);
            }
        }
    }
}

void Handler::dbus_map_update(const std::string& adapterObjPath,
                              const std::string& propertyName,
                              const std::string& propValue)
{
    pldm::utils::PropertyValue value = propValue;
    pldm::utils::DBusMapping dbusMapping;
    dbusMapping.objectPath = adapterObjPath;
    dbusMapping.interface = "xyz.openbmc_project.Inventory.Item.PCIeDevice";
    dbusMapping.propertyName = propertyName;
    dbusMapping.propertyType = "string";
    try
    {
        pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
    }
    catch (const std::exception& e)
    {
        error(
            "Failed to set property '{PROPERTY} at path '{PATH}' and interface '{INTERFACE}', error - {ERROR}",
            "PROPERTY", propertyName, "PATH", adapterObjPath, "INTERFACE",
            dbusMapping.interface, "ERROR", e);
    }
}

void Handler::setFirmwareUAK(const std::vector<uint8_t>& data)
{
    using VPDManager = sdbusplus::client::com::ibm::vpd::Manager<>;

    static constexpr auto uakObjPath = "/com/ibm/VPD/Manager";
    static constexpr auto fruPath =
        "/xyz/openbmc_project/inventory/system/chassis/motherboard";

    auto& bus = pldm::utils::DBusHandler::getBus();
    try
    {
        auto service = pldm::utils::DBusHandler().getService(
            uakObjPath, VPDManager::interface);
        auto method = bus.new_method_call(
            service.c_str(), uakObjPath, VPDManager::interface, "WriteKeyword");
        method.append(static_cast<sdbusplus::message::object_path>(fruPath),
                      "UTIL", "D8", data);
        bus.call_noreply(method, dbusTimeout);
    }
    catch (const std::exception& e)
    {
        error("Failed to make a DBus call to VPD manager, error - {ERROR}",
              "ERROR", e);
    }
}

} // namespace oem_ibm_fru
} // namespace responder
} // namespace pldm
