#include "bios_attribute.hpp"

#include "bios_config.hpp"
#include "common/utils.hpp"

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
    name(entry.at("attribute_name")), readOnly(false),
    displayName(entry.at("display_name")), helpText(entry.at("help_text")),
    dbusHandler(dbusHandler)
{
    try
    {
        readOnly = entry.at("read_only");
    }
    catch (const std::exception&)
    {
        // No action required, readOnly is initialised to false
    }

    try
    {
        std::string objectPath = entry.at("dbus").at("object_path");
        std::string interface = entry.at("dbus").at("interface");
        std::string propertyName = entry.at("dbus").at("property_name");
        std::string propertyType = entry.at("dbus").at("property_type");

        dBusMap = {objectPath, interface, propertyName, propertyType};
    }
    catch (const std::exception&)
    {
        // No action required, dBusMap will have no value
    }
}

std::optional<DBusMapping> BIOSAttribute::getDBusMap()
{
    return dBusMap;
}

} // namespace bios
} // namespace responder
} // namespace pldm
