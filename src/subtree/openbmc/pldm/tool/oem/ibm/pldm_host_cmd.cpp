#include "pldm_host_cmd.hpp"

#include "oem/ibm/libpldm/host.h"

#include "../../pldm_cmd_helper.hpp"

namespace pldmtool
{

namespace oem_ibm
{
namespace power_host
{
using namespace pldmtool::helper;

std::vector<std::unique_ptr<CommandInterface>> commands;

class GetAlertStatus : public CommandInterface
{
  public:
    ~GetAlertStatus() = default;
    GetAlertStatus() = delete;
    GetAlertStatus(const GetAlertStatus&) = delete;
    GetAlertStatus(GetAlertStatus&&) = default;
    GetAlertStatus& operator=(const GetAlertStatus&) = delete;
    GetAlertStatus& operator=(GetAlertStatus&&) = default;

    explicit GetAlertStatus(const char* type, const char* name, CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --id", versionId,
               "Version of the command/response format. 0x00 for this format")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                        PLDM_GET_ALERT_STATUS_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_alert_status_req(instanceId, versionId, request,
                                              PLDM_GET_ALERT_STATUS_REQ_BYTES);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint32_t rack_entry = 0;
        uint32_t pri_cec_node = 0;
        auto rc = decode_get_alert_status_resp(responsePtr, payloadLength,
                                               &completionCode, &rack_entry,
                                               &pri_cec_node);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode << "\n";
            return;
        }

        std::cout << "GetAlertStatus Success: " << std::endl;
        std::cout << "rack entry: 0x" << std::setfill('0') << std::setw(8)
                  << std::hex << (int)rack_entry << std::endl;
        std::cout << "pri cec node: 0x" << std::setfill('0') << std::setw(8)
                  << std::hex << (int)pri_cec_node << std::endl;
    }

  private:
    uint8_t versionId;
};

void registerCommand(CLI::App& app)
{
    auto oem_ibm = app.add_subcommand("oem-ibm", "oem type command");
    oem_ibm->require_subcommand(1);

    auto getAlertStatus = oem_ibm->add_subcommand(
        "GetAlertStatus", "get alert status descriptor");
    commands.push_back(std::make_unique<GetAlertStatus>(
        "oem_ibm", "getAlertStatus", getAlertStatus));
}
} // namespace power_host
} // namespace oem_ibm
} // namespace pldmtool
