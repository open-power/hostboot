#include "config.h"

#include "bios_attribute.hpp"

#include "bios_config.hpp"
#include "common/utils.hpp"

#include <iostream>
#include <variant>

using namespace pldm::utils;

namespace pldm
{
namespace responder
{
namespace bios
{

BIOSAttribute::BIOSAttribute(const Json& entry,
                             DBusHandler* const dbusHandler) :
    name(entry.at("attribute_name")),
    readOnly(false), displayName(entry.at("displayName")),
    helpText(entry.at("helpText")), dbusHandler(dbusHandler)
{
    try
    {
        readOnly = entry.at("readOnly");
    }
    catch (const std::exception& e)
    {
        // No action required, readOnly is initialised to false
    }

    if (!readOnly)
    {
        try
        {
            std::string objectPath = entry.at("dbus").at("object_path");
            std::string interface = entry.at("dbus").at("interface");
            std::string propertyName = entry.at("dbus").at("property_name");
            std::string propertyType = entry.at("dbus").at("property_type");

            dBusMap = {objectPath, interface, propertyName, propertyType};
        }
        catch (const std::exception& e)
        {
            // No action required, dBusMap whill have no value
        }
    }
}

std::optional<DBusMapping> BIOSAttribute::getDBusMap()
{
    return dBusMap;
}

} // namespace bios
} // namespace responder
} // namespace pldm
