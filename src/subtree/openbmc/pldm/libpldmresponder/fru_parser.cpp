#include "fru_parser.hpp"

#include <nlohmann/json.hpp>
#include <xyz/openbmc_project/Common/error.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>

using namespace pldm::responder::dbus;

namespace pldm
{

namespace responder
{

namespace fru_parser
{

using Json = nlohmann::json;
using InternalFailure =
    sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure;

const Json emptyJson{};
const std::vector<Json> emptyJsonList{};
const std::vector<std::string> emptyStringVec{};

FruParser::FruParser(const std::string& dirPath,
                     const fs::path& fruMasterJsonPath)
{
    if (fs::exists(fruMasterJsonPath))
    {
        setupDefaultDBusLookup(fruMasterJsonPath);
    }
    setupDefaultFruRecordMap();

    fs::path dir(dirPath);
    if (fs::exists(dir) && !fs::is_empty(dir))
    {
        setupFruRecordMap(dirPath);
    }
}

void FruParser::setupDefaultDBusLookup(const fs::path& masterJsonPath)
{
    constexpr auto service = "xyz.openbmc_project.Inventory.Manager";
    constexpr auto rootPath = "/xyz/openbmc_project/inventory";
    std::ifstream jsonFile(masterJsonPath);
    auto data = Json::parse(jsonFile, nullptr, false);
    if (data.is_discarded())
    {
        std::cerr << "Parsing FRU Dbus Lookup Map config file failed, FILE="
                  << masterJsonPath;
        std::abort();
    }
    std::map<Interface, EntityType> defIntfToEntityType;
    auto dbusMap = data.value("FruDBusLookupMap", emptyJson);
    for (const auto& element : dbusMap.items())

    {
        try
        {
            defIntfToEntityType[static_cast<Interface>(element.key())] =
                static_cast<EntityType>(element.value());
        }
        catch (const std::exception& e)
        {
            std::cerr << "FRU DBus lookup map format error\n";
            throw InternalFailure();
        }
    }

    Interfaces interfaces{};
    for (auto [intf, entityType] : defIntfToEntityType)
    {
        intfToEntityType[intf] = entityType;
        interfaces.emplace(intf);
    }

    lookupInfo.emplace(service, rootPath, std::move(interfaces));
}

void FruParser::setupDefaultFruRecordMap()
{
    const FruRecordInfo generalRecordInfo = {
        1, // generalRecordType
        1, // encodingTypeASCII
        {
            // DSP0257 Table 5 General FRU Record Field Type Definitions
            {"xyz.openbmc_project.Inventory.Decorator.Asset", "Model", "string",
             2},
            {"xyz.openbmc_project.Inventory.Decorator.Asset", "PartNumber",
             "string", 3},
            {"xyz.openbmc_project.Inventory.Decorator.Asset", "SerialNumber",
             "string", 4},
            {"xyz.openbmc_project.Inventory.Decorator.Asset", "Manufacturer",
             "string", 5},
            {"xyz.openbmc_project.Inventory.Item", "PrettyName", "string", 8},
            {"xyz.openbmc_project.Inventory.Decorator.AssetTag", "AssetTag",
             "string", 11},
            {"xyz.openbmc_project.Inventory.Decorator.Revision", "Version",
             "string", 10},
        }};

    for (auto [intf, entityType] : intfToEntityType)
    {
        recordMap[intf] = {generalRecordInfo};
    }
}

void FruParser::setupFruRecordMap(const std::string& dirPath)
{
    for (auto& file : fs::directory_iterator(dirPath))
    {
        auto fileName = file.path().filename().string();
        std::ifstream jsonFile(file.path());
        auto data = Json::parse(jsonFile, nullptr, false);
        if (data.is_discarded())
        {
            std::cerr << "Parsing FRU config file failed, FILE=" << file.path();
            throw InternalFailure();
        }

        try
        {
            auto record = data.value("record_details", emptyJson);
            auto recordType =
                static_cast<uint8_t>(record.value("fru_record_type", 0));
            auto encType =
                static_cast<uint8_t>(record.value("fru_encoding_type", 0));
            auto dbusIntfName = record.value("dbus_interface_name", "");
            auto entries = data.value("fru_fields", emptyJsonList);
            std::vector<FieldInfo> fieldInfo;

            for (const auto& entry : entries)
            {
                auto fieldType =
                    static_cast<uint8_t>(entry.value("fru_field_type", 0));
                auto dbus = entry.value("dbus", emptyJson);
                auto interface = dbus.value("interface", "");
                auto property = dbus.value("property_name", "");
                auto propType = dbus.value("property_type", "");
                fieldInfo.emplace_back(
                    std::make_tuple(std::move(interface), std::move(property),
                                    std::move(propType), std::move(fieldType)));
            }

            FruRecordInfo fruInfo;
            fruInfo =
                std::make_tuple(recordType, encType, std::move(fieldInfo));

            auto search = recordMap.find(dbusIntfName);

            // PLDM FRU can have multiple records for the same FRU like General
            // FRU record and multiple OEM FRU records. If the FRU item
            // interface name is already in the map, that indicates a record
            // info is already added for the FRU, so append the new record info
            // to the same data.
            if (search != recordMap.end())
            {
                search->second.emplace_back(std::move(fruInfo));
            }
            else
            {
                FruRecordInfos recordInfos{fruInfo};
                recordMap.emplace(dbusIntfName, recordInfos);
            }
        }
        catch (const std::exception& e)
        {
            continue;
        }
    }
}

} // namespace fru_parser

} // namespace responder

} // namespace pldm
