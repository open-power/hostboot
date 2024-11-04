#include "event_parser.hpp"

#include <phosphor-logging/lg2.hpp>
#include <xyz/openbmc_project/Common/error.hpp>

#include <filesystem>
#include <fstream>
#include <set>

PHOSPHOR_LOG2_USING;

namespace pldm::responder::events
{
namespace fs = std::filesystem;
using InternalFailure =
    sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure;

const Json emptyJson{};
const std::vector<Json> emptyJsonList{};

const std::set<std::string_view> supportedDbusPropertyTypes = {
    "bool",     "uint8_t", "int16_t",  "uint16_t", "int32_t",
    "uint32_t", "int64_t", "uint64_t", "double",   "string"};

StateSensorHandler::StateSensorHandler(const std::string& dirPath)
{
    fs::path dir(dirPath);
    if (!fs::exists(dir) || fs::is_empty(dir))
    {
        error("Event config directory at '{PATH}' does not exist or empty",
              "PATH", dirPath);
        return;
    }

    for (auto& file : fs::directory_iterator(dirPath))
    {
        std::ifstream jsonFile(file.path());

        auto data = Json::parse(jsonFile, nullptr, false);
        if (data.is_discarded())
        {
            error("Failed to parse event state sensor JSON file at '{PATH}'",
                  "PATH", file.path());
            continue;
        }

        auto entries = data.value("entries", emptyJsonList);
        for (const auto& entry : entries)
        {
            StateSensorEntry stateSensorEntry{};
            stateSensorEntry.containerId =
                static_cast<uint16_t>(entry.value("containerID", 0xFFFF));
            stateSensorEntry.entityType =
                static_cast<uint16_t>(entry.value("entityType", 0));
            stateSensorEntry.entityInstance =
                static_cast<uint16_t>(entry.value("entityInstance", 0));
            stateSensorEntry.sensorOffset =
                static_cast<uint8_t>(entry.value("sensorOffset", 0));
            stateSensorEntry.stateSetid =
                static_cast<uint16_t>(entry.value("stateSetId", 0));

            // container id is not found in the json
            stateSensorEntry.skipContainerId =
                (stateSensorEntry.containerId == 0xFFFF) ? true : false;

            pldm::utils::DBusMapping dbusInfo{};

            auto dbus = entry.value("dbus", emptyJson);
            dbusInfo.objectPath = dbus.value("object_path", "");
            dbusInfo.interface = dbus.value("interface", "");
            dbusInfo.propertyName = dbus.value("property_name", "");
            dbusInfo.propertyType = dbus.value("property_type", "");
            if (dbusInfo.objectPath.empty() || dbusInfo.interface.empty() ||
                dbusInfo.propertyName.empty() ||
                !supportedDbusPropertyTypes.contains(dbusInfo.propertyType))
            {
                error(
                    "Invalid dbus config at '{PATH}', interface '{DBUS_INTERFACE}', property name '{PROPERTY_NAME}' and property type '{PROPERTY_TYPE}'",
                    "PATH", dbusInfo.objectPath, "DBUS_INTERFACE",
                    dbusInfo.interface, "PROPERTY_NAME", dbusInfo.propertyName,
                    "PROPERTY_TYPE", dbusInfo.propertyType);
                continue;
            }

            auto eventStates = entry.value("event_states", emptyJsonList);
            auto propertyValues = dbus.value("property_values", emptyJsonList);
            if ((eventStates.size() == 0) || (propertyValues.size() == 0) ||
                (eventStates.size() != propertyValues.size()))
            {
                error(
                    "Invalid event state JSON config size '{EVENT_STATE_SIZE}' and property value size '{PROPERTY_VALUE_SIZE}'",
                    "EVENT_STATE_SIZE", eventStates.size(),
                    "PROPERTY_VALUE_SIZE", propertyValues.size());
                continue;
            }

            auto eventStateMap = mapStateToDBusVal(eventStates, propertyValues,
                                                   dbusInfo.propertyType);
            eventMap.emplace(
                stateSensorEntry,
                std::make_tuple(std::move(dbusInfo), std::move(eventStateMap)));
        }
    }
}

StateToDBusValue StateSensorHandler::mapStateToDBusVal(
    const Json& eventStates, const Json& propertyValues, std::string_view type)
{
    StateToDBusValue eventStateMap{};
    auto stateIt = eventStates.begin();
    auto propIt = propertyValues.begin();

    for (; stateIt != eventStates.end(); ++stateIt, ++propIt)
    {
        auto propValue = utils::jsonEntryToDbusVal(type, propIt.value());
        eventStateMap.emplace((*stateIt).get<uint8_t>(), std::move(propValue));
    }

    return eventStateMap;
}

int StateSensorHandler::eventAction(const StateSensorEntry& entry,
                                    pdr::EventState state)
{
    try
    {
        const auto& [dbusMapping, eventStateMap] = eventMap.at(entry);
        utils::PropertyValue propValue{};
        try
        {
            propValue = eventStateMap.at(state);
        }
        catch (const std::out_of_range& e)
        {
            error("Invalid event state '{EVENT_STATE}', error - {ERROR}",
                  "EVENT_STATE", state, "ERROR", e);
            return PLDM_ERROR_INVALID_DATA;
        }

        try
        {
            pldm::utils::DBusHandler().setDbusProperty(dbusMapping, propValue);
        }
        catch (const std::exception& e)
        {
            error(
                "Failed to  set property '{PROPERTY}' on interface '{INTERFACE}' at path '{PATH}', error - {ERROR}",
                "PROPERTY", dbusMapping.propertyName, "INTERFACE",
                dbusMapping.interface, "PATH", dbusMapping.objectPath, "ERROR",
                e);
            return PLDM_ERROR;
        }
    }
    catch (const std::out_of_range&)
    {
        // There is no BMC action for this PLDM event
        return PLDM_SUCCESS;
    }
    return PLDM_SUCCESS;
}

} // namespace pldm::responder::events
