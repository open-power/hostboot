#include "cable.hpp"

namespace pldm
{
namespace dbus
{

double Cable::length() const
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::Cable::
        length();
}

double Cable::length(double value)
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::Cable::
        length(value);
}

std::string Cable::cableTypeDescription() const
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::Cable::
        cableTypeDescription();
}

std::string Cable::cableTypeDescription(std::string value)
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::Cable::
        cableTypeDescription(value);
}

} // namespace dbus

} // namespace pldm
