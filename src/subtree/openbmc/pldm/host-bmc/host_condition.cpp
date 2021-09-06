#include "host_condition.hpp"

namespace pldm
{
namespace dbus_api
{

Host::FirmwareCondition Host::currentFirmwareCondition() const
{
    bool hostRunning = false;

    if (hostPdrObj != nullptr)
    {
        hostRunning = hostPdrObj.get()->isHostUp();
    }

    auto value = hostRunning ? Host::FirmwareCondition::Running
                             : Host::FirmwareCondition::Off;

    return value;
}

} // namespace dbus_api
} // namespace pldm
