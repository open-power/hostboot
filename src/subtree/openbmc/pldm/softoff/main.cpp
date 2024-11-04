#include "common/instance_id.hpp"
#include "common/utils.hpp"
#include "softoff.hpp"

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

int main()
{
    // Get a default event loop
    auto event = sdeventplus::Event::get_default();

    // Get a handle to system D-Bus.
    auto& bus = pldm::utils::DBusHandler::getBus();

    // Obtain the instance database
    pldm::InstanceIdDb instanceIdDb;

    // Attach the bus to sd_event to service user requests
    bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

    pldm::SoftPowerOff softPower(bus, event.get(), instanceIdDb);

    if (softPower.isError())
    {
        error(
            "Failure in gracefully shutdown by remote terminus, exiting pldm-softpoweroff app");
        return -1;
    }

    if (softPower.isCompleted())
    {
        error(
            "Remote terminus current state is not Running, exiting pldm-softpoweroff app");
        return 0;
    }

    // Send the gracefully shutdown request to the host and
    // wait the host gracefully shutdown.
    if (softPower.hostSoftOff(event))
    {
        error(
            "Failure in sending soft off request to the remote terminus. Exiting pldm-softpoweroff app");
        return -1;
    }

    if (softPower.isTimerExpired() && softPower.isReceiveResponse())
    {
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.SoftPowerOff.HostSoftOffTimeOut");
        error(
            "ERROR! Waiting for the host soft off timeout. Exit the pldm-softpoweroff");
        return -1;
    }

    return 0;
}
