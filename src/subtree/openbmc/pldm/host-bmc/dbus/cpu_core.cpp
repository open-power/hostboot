#include "cpu_core.hpp"

namespace pldm
{
namespace dbus
{

uint32_t CPUCore::microcode() const
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::CpuCore::
        microcode();
}

uint32_t CPUCore::microcode(uint32_t value)
{
    return sdbusplus::xyz::openbmc_project::Inventory::Item::server::CpuCore::
        microcode(value);
}

} // namespace dbus
} // namespace pldm
