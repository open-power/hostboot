#pragma once

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Inventory/Item/CpuCore/server.hpp>

#include <string>

namespace pldm
{
namespace dbus
{
using CoreIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Inventory::Item::server::CpuCore>;

class CPUCore : public CoreIntf
{
  public:
    CPUCore() = delete;
    ~CPUCore() = default;
    CPUCore(const CPUCore&) = delete;
    CPUCore& operator=(const CPUCore&) = delete;
    CPUCore(CPUCore&&) = delete;
    CPUCore& operator=(CPUCore&&) = delete;

    CPUCore(sdbusplus::bus_t& bus, const std::string& objPath) :
        CoreIntf(bus, objPath.c_str())
    {}

    /** Get value of Microcode */
    uint32_t microcode() const override;

    /** Set value of Microcode */
    uint32_t microcode(uint32_t value) override;
};

} // namespace dbus
} // namespace pldm
