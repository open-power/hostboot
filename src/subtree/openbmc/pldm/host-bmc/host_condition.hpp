#pragma once

#include "host-bmc/host_pdr_handler.hpp"

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Condition/HostFirmware/server.hpp>

namespace pldm
{
namespace dbus_api
{

using HostIntf = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Condition::server::HostFirmware>;

class Host : public HostIntf
{
  public:
    Host() = delete;
    Host(const Host&) = delete;
    Host& operator=(const Host&) = delete;
    Host(Host&&) = delete;
    Host& operator=(Host&&) = delete;
    virtual ~Host() = default;

    Host(sdbusplus::bus::bus& bus, const std::string& path) :
        HostIntf(bus, path.c_str()){};

    /** @brief Override reads to CurrentFirmwareCondition */
    FirmwareCondition currentFirmwareCondition() const override;

    /** @brief Store shared pointer to host PDR instance */
    void setHostPdrObj(std::shared_ptr<HostPDRHandler> obj)
    {
        hostPdrObj = obj;
    }

  private:
    std::shared_ptr<HostPDRHandler> hostPdrObj;
};
} // namespace dbus_api
} // namespace pldm
