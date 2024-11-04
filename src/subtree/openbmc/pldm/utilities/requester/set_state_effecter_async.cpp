#include "common/transport.hpp"

#include <libpldm/base.h>
#include <libpldm/platform.h>

#include <CLI/CLI.hpp>
#include <phosphor-logging/lg2.hpp>
#include <sdeventplus/event.hpp>
#include <sdeventplus/source/io.hpp>

#include <array>

using namespace sdeventplus;
using namespace sdeventplus::source;
PHOSPHOR_LOG2_USING;

int main(int argc, char** argv)
{
    CLI::App app{"Send PLDM command SetStateEffecterStates"};
    uint8_t mctpEid{};
    app.add_option("-m,--mctp_eid", mctpEid, "MCTP EID")->required();
    uint16_t effecterId{};
    app.add_option("-e,--effecter", effecterId, "Effecter Id")->required();
    uint8_t state{};
    app.add_option("-s,--state", state, "New state value")->required();
    CLI11_PARSE(app, argc, argv);

    pldm_tid_t dstTid = static_cast<pldm_tid_t>(mctpEid);

    // Encode PLDM Request message
    uint8_t effecterCount = 1;
    std::array<uint8_t,
               sizeof(pldm_msg_hdr) + sizeof(effecterId) +
                   sizeof(effecterCount) + sizeof(set_effecter_state_field)>
        requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    set_effecter_state_field stateField{PLDM_REQUEST_SET, state};
    auto rc = encode_set_state_effecter_states_req(0, effecterId, effecterCount,
                                                   &stateField, request);
    if (rc != PLDM_SUCCESS)
    {
        error(
            "Failed to encode set state effecter states request, response code '{RC}'",
            "RC", lg2::hex, rc);
        return -1;
    }

    PldmTransport pldmTransport{};

    // Create event loop and add a callback to handle EPOLLIN on fd
    auto event = Event::get_default();
    auto callback = [=,
                     &pldmTransport](IO& io, int fd, uint32_t revents) mutable {
        if (!(revents & EPOLLIN))
        {
            return;
        }

        if (pldmTransport.getEventSource() != fd)
        {
            return;
        }

        void* responseMsg = nullptr;
        size_t responseMsgSize{};
        pldm_tid_t srcTid;
        auto rc = pldmTransport.recvMsg(srcTid, responseMsg, responseMsgSize);
        pldm_msg* response = reinterpret_cast<pldm_msg*>(responseMsg);
        if (rc || dstTid != srcTid ||
            !pldm_msg_hdr_correlate_response(&request->hdr, &response->hdr))
        {
            return;
        }

        // We've got the response meant for the PLDM request msg that was sent
        // out
        io.set_enabled(Enabled::Off);
        info(
            "Done! Got the response for PLDM request message, response code '{RC}'",
            "RC", lg2::hex, response->payload[0]);
        free(responseMsg);
        exit(EXIT_SUCCESS);
    };
    IO io(event, pldmTransport.getEventSource(), EPOLLIN, std::move(callback));

    rc = pldmTransport.sendMsg(dstTid, requestMsg.data(), requestMsg.size());
    if (0 > rc)
    {
        error(
            "Failed to send message/receive response, response code '{RC}' and error - {ERROR}",
            "RC", rc, "ERROR", errno);
        return -1;
    }

    event.loop();

    return 0;
}
