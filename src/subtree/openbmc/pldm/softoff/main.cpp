#include "common/utils.hpp"
#include "softoff.hpp"

#include <iostream>

int main()
{
    // Get a default event loop
    auto event = sdeventplus::Event::get_default();

    // Get a handle to system D-Bus.
    auto& bus = pldm::utils::DBusHandler::getBus();

    // Attach the bus to sd_event to service user requests
    bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

    pldm::SoftPowerOff softPower(bus, event.get());

    if (softPower.isError())
    {
        std::cerr << "Host failed to gracefully shutdown, exiting "
                     "pldm-softpoweroff app\n";
        return -1;
    }

    if (softPower.isCompleted())
    {
        std::cerr << "Host current state is not Running, exiting "
                     "pldm-softpoweroff app\n";
        return 0;
    }

    // Send the gracefully shutdown request to the host and
    // wait the host gracefully shutdown.
    if (softPower.hostSoftOff(event))
    {
        std::cerr << "pldm-softpoweroff:Failure in sending soft off request to "
                     "the host. Exiting pldm-softpoweroff app\n";

        return -1;
    }

    if (softPower.isTimerExpired() && softPower.isReceiveResponse())
    {
        pldm::utils::reportError(
            "pldm soft off: Waiting for the host soft off timeout");
        std::cerr
            << "PLDM host soft off: ERROR! Wait for the host soft off timeout."
            << "Exit the pldm-softpoweroff "
            << "\n";
        return -1;
    }

    return 0;
}
