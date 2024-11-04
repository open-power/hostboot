#include "common/transport.hpp"

#include <libpldm/platform.h>

#include <CLI/CLI.hpp>
#include <phosphor-logging/lg2.hpp>

#include <array>

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
            "Failed to encode set state effecter states request message, response code '{RC}'",
            "RC", lg2::hex, rc);
        return -1;
    }

    PldmTransport pldmTransport{};

    void* responseMsg = nullptr;
    size_t responseMsgSize{};
    // Send PLDM request msg and wait for response
    rc = pldmTransport.sendRecvMsg(static_cast<pldm_tid_t>(mctpEid),
                                   requestMsg.data(), requestMsg.size(),
                                   responseMsg, responseMsgSize);
    if (0 > rc)
    {
        error(
            "Failed to send message/receive response, response code '{RC}' and error - {ERROR}",
            "RC", rc, "ERROR", errno);
        return -1;
    }
    pldm_msg* response = reinterpret_cast<pldm_msg*>(responseMsg);
    info(
        "Done! Got the response for PLDM send receive message request, response code '{RC}'",
        "RC", lg2::hex, response->payload[0]);
    free(responseMsg);

    return 0;
}
