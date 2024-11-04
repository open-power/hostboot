#include "pcie_device.hpp"

namespace pldm
{
namespace dbus
{

auto PCIeDevice::generationInUse() const -> Generations
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
        PCIeDevice::generationInUse();
}

auto PCIeDevice::generationInUse(Generations value) -> Generations
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
        PCIeDevice::generationInUse(value);
}

size_t PCIeDevice::lanesInUse() const
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
        PCIeDevice::lanesInUse();
}

size_t PCIeDevice::lanesInUse(size_t value)
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
        PCIeDevice::lanesInUse(value);
}

} // namespace dbus
} // namespace pldm
