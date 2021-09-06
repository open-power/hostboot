#include "platform_oem_ibm.hpp"

#include "libpldm/platform_oem_ibm.h"
#include "libpldm/requester/pldm.h"

#include "common/utils.hpp"
#include "libpldmresponder/pdr.hpp"

#include <iostream>

namespace pldm
{
namespace responder
{
namespace platform
{

int sendBiosAttributeUpdateEvent(
    uint8_t eid, dbus_api::Requester* requester,
    const std::vector<uint16_t>& handles,
    pldm::requester::Handler<pldm::requester::Request>* handler)
{
    constexpr auto hostStatePath = "/xyz/openbmc_project/state/host0";
    constexpr auto hostStateInterface =
        "xyz.openbmc_project.State.Boot.Progress";
    constexpr auto hostStateProperty = "BootProgress";

    try
    {
        auto propVal = pldm::utils::DBusHandler().getDbusPropertyVariant(
            hostStatePath, hostStateProperty, hostStateInterface);
        const auto& currHostState = std::get<std::string>(propVal);
        if ((currHostState != "xyz.openbmc_project.State.Boot.Progress."
                              "ProgressStages.SystemInitComplete") &&
            (currHostState != "xyz.openbmc_project.State.Boot.Progress."
                              "ProgressStages.OSRunning") &&
            (currHostState != "xyz.openbmc_project.State.Boot.Progress."
                              "ProgressStages.OSStart"))
        {
            return PLDM_SUCCESS;
        }
    }
    catch (const sdbusplus::exception::exception& e)
    {
        std::cerr << "Error in getting current host state, continue ... \n";
    }

    auto instanceId = requester->getInstanceId(eid);

    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + sizeof(pldm_bios_attribute_update_event_req) -
            1 + (handles.size() * sizeof(uint16_t)),
        0);

    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_bios_attribute_update_event_req(
        instanceId, PLDM_PLATFORM_EVENT_MESSAGE_FORMAT_VERSION,
        pldm::responder::pdr::BmcMctpEid, handles.size(),
        reinterpret_cast<const uint8_t*>(handles.data()),
        requestMsg.size() - sizeof(pldm_msg_hdr), request);
    if (rc != PLDM_SUCCESS)
    {
        std::cerr << "Message encode failure 1. PLDM error code = " << std::hex
                  << std::showbase << rc << "\n";
        requester->markFree(eid, instanceId);
        return rc;
    }

    if (requestMsg.size())
    {
        std::ostringstream tempStream;
        for (int byte : requestMsg)
        {
            tempStream << std::setfill('0') << std::setw(2) << std::hex << byte
                       << " ";
        }
        std::cout << tempStream.str() << std::endl;
    }

    auto platformEventMessageResponseHandler = [](mctp_eid_t /*eid*/,
                                                  const pldm_msg* response,
                                                  size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            std::cerr
                << "Failed to receive response for platform event message \n";
            return;
        }
        uint8_t completionCode{};
        uint8_t status{};
        auto rc = decode_platform_event_message_resp(response, respMsgLen,
                                                     &completionCode, &status);
        if (rc || completionCode)
        {
            std::cerr << "Failed to decode_platform_event_message_resp: "
                      << "rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << std::endl;
        }
    };
    rc = handler->registerRequest(
        eid, instanceId, PLDM_PLATFORM, PLDM_PLATFORM_EVENT_MESSAGE,
        std::move(requestMsg), std::move(platformEventMessageResponseHandler));
    if (rc)
    {
        std::cerr << "Failed to send the platform event message \n";
    }

    return rc;
}

} // namespace platform

} // namespace responder

} // namespace pldm
