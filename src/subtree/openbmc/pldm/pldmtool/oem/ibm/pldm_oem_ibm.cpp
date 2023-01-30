#include "pldm_oem_ibm.hpp"

#include "../../pldm_cmd_helper.hpp"

#include <endian.h>
#include <libpldm/file_io.h>
#include <libpldm/host.h>
#include <libpldm/pldm_types.h>

#include <iostream>
#include <string>
namespace pldmtool
{

namespace oem_ibm
{
namespace
{

using namespace pldmtool::helper;

std::vector<std::unique_ptr<CommandInterface>> commands;

const std::map<const char*, pldm_fileio_table_type> pldmFileIOTableTypes{
    {"AttributeTable", PLDM_FILE_ATTRIBUTE_TABLE},
};

constexpr uint8_t CHKSUM_PADDING = 8;

} // namespace

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

        std::stringstream re;
        std::stringstream pcn;
        ordered_json data;
        re << "0x" << std::setfill('0') << std::setw(8) << std::hex
           << (int)rack_entry;
        pcn << "0x" << std::setfill('0') << std::setw(8) << std::hex
            << (int)pri_cec_node;
        data["rack entry"] = re.str();
        data["pri cec node"] = pcn.str();
        pldmtool::helper::DisplayInJson(data);
    }

  private:
    uint8_t versionId;
};

class GetFileTable : public CommandInterface
{
  public:
    ~GetFileTable() = default;
    GetFileTable() = delete;
    GetFileTable(const GetFileTable&) = delete;
    GetFileTable(GetFileTable&&) = default;
    GetFileTable& operator=(const GetFileTable&) = delete;
    GetFileTable& operator=(GetFileTable&&) = default;

    using CommandInterface::CommandInterface;

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        return {PLDM_ERROR, {}};
    }

    void parseResponseMsg(pldm_msg*, size_t) override
    {}
    void exec()
    {
        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                        PLDM_GET_FILE_TABLE_REQ_BYTES);

        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_file_table_req(instanceId, 0, PLDM_GET_FIRSTPART,
                                            0, request);
        if (rc != PLDM_SUCCESS)
        {
            std::cerr << "PLDM: Request Message Error, rc =" << rc << std::endl;
            return;
        }

        std::vector<uint8_t> responseMsg;
        rc = pldmSendRecv(requestMsg, responseMsg);
        if (rc != PLDM_SUCCESS)
        {
            std::cerr << "PLDM: Communication Error, rc =" << rc << std::endl;
            return;
        }

        uint8_t cc = 0;
        uint8_t transferFlag = 0;
        uint32_t nextTransferHandle = 0;
        size_t fileTableDataLength = 0;
        uint8_t table_data_start_offset;
        auto responsePtr =
            reinterpret_cast<struct pldm_msg*>(responseMsg.data());
        auto payloadLength = responseMsg.size() - sizeof(pldm_msg_hdr);

        rc = decode_get_file_table_resp(
            responsePtr, payloadLength, &cc, &nextTransferHandle, &transferFlag,
            &table_data_start_offset, &fileTableDataLength);

        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << ", rc=" << rc << ", cc=" << (int)cc << std::endl;
            return;
        }

        auto tableData = reinterpret_cast<uint8_t*>((responsePtr->payload) +
                                                    table_data_start_offset);
        printFileAttrTable(tableData, fileTableDataLength);
    }

    void printFileAttrTable(uint8_t* data, size_t length)
    {
        if (data == NULL || length == 0)
        {
            return;
        }

        auto startptr = data;
        auto endptr = startptr + length - CHKSUM_PADDING;
        ordered_json kwVal;

        while (startptr < endptr)
        {
            ordered_json fdata;
            auto filetableData =
                reinterpret_cast<pldm_file_attr_table_entry*>(startptr);
            fdata["FileHandle"] = std::to_string(filetableData->file_handle);
            startptr += sizeof(filetableData->file_handle);

            auto nameLength = filetableData->file_name_length;
            fdata["FileNameLength"] = nameLength;
            startptr += sizeof(filetableData->file_name_length);

            fdata["FileName"] = (std::string(
                reinterpret_cast<char const*>(startptr), nameLength));
            startptr += nameLength;

            auto fileSize = *(reinterpret_cast<uint32_t*>(startptr));
            fdata["FileSize"] = le32toh(fileSize);
            startptr += sizeof(fileSize);

            auto fileTraits =
                (*(reinterpret_cast<bitfield32_t*>(startptr))).value;
            fdata["FileTraits"] = le32toh(fileTraits);
            startptr += sizeof(fileTraits);
            kwVal.emplace_back(fdata);
        }
        pldmtool::helper::DisplayInJson(kwVal);
    }
};

void registerCommand(CLI::App& app)
{
    auto oem_ibm = app.add_subcommand("oem-ibm", "oem type command");
    oem_ibm->require_subcommand(1);

    auto getAlertStatus = oem_ibm->add_subcommand(
        "GetAlertStatus", "get alert status descriptor");
    commands.push_back(std::make_unique<GetAlertStatus>(
        "oem_ibm", "getAlertStatus", getAlertStatus));

    auto getFileTable =
        oem_ibm->add_subcommand("GetFileTable", "get file table");

    commands.push_back(std::make_unique<GetFileTable>("oem_ibm", "getFileTable",
                                                      getFileTable));
}
} // namespace oem_ibm
} // namespace pldmtool
