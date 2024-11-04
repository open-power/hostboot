#include "dbus_to_file_handler.hpp"

#include "common/utils.hpp"

#include <libpldm/oem/ibm/file_io.h>

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace requester
{
namespace oem_ibm
{
using namespace pldm::utils;
using namespace sdbusplus::bus::match::rules;

static constexpr auto resDumpProgressIntf =
    "xyz.openbmc_project.Common.Progress";
static constexpr auto resDumpStatus =
    "xyz.openbmc_project.Common.Progress.OperationStatus.Failed";

DbusToFileHandler::DbusToFileHandler(
    int /* mctp_fd */, uint8_t mctp_eid, pldm::InstanceIdDb* instanceIdDb,
    sdbusplus::message::object_path resDumpCurrentObjPath,
    pldm::requester::Handler<pldm::requester::Request>* handler) :
    mctp_eid(mctp_eid), instanceIdDb(instanceIdDb),
    resDumpCurrentObjPath(resDumpCurrentObjPath), handler(handler)
{}

void DbusToFileHandler::sendNewFileAvailableCmd(uint64_t fileSize)
{
    if (instanceIdDb == NULL)
    {
        error(
            "Failed to send resource dump parameters as instance ID DB is not set");
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = instanceIdDb->next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_NEW_FILE_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    // Need to revisit this logic at the time of multiple resource dump support
    uint32_t fileHandle = 1;

    auto rc =
        encode_new_file_req(instanceId, PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS,
                            fileHandle, fileSize, request);
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb->free(mctp_eid, instanceId);
        error("Failed to encode new file request with response code '{RC}'",
              "RC", rc);
        return;
    }

    auto newFileAvailableRespHandler = [this](mctp_eid_t /*eid*/,
                                              const pldm_msg* response,
                                              size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error("Failed to receive response for NewFileAvailable command");
            return;
        }
        uint8_t completionCode{};
        auto rc = decode_new_file_resp(response, respMsgLen, &completionCode);
        if (rc || completionCode)
        {
            error(
                "Failed to decode new file available response or remote terminus returned error, response code '{RC}' and completion code '{CC}'",
                "RC", rc, "CC", completionCode);
            reportResourceDumpFailure("DecodeNewFileResp");
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        error(
            "Failed to send NewFileAvailable Request to Host, response code '{RC}'",
            "RC", rc);
        reportResourceDumpFailure("NewFileAvailableRequest");
    }
}

void DbusToFileHandler::reportResourceDumpFailure(const std::string_view& str)
{
    std::string s = "xyz.openbmc_project.PLDM.Error.ReportResourceDumpFail.";
    s += str;

    pldm::utils::reportError(s.c_str());

    PropertyValue value{resDumpStatus};
    DBusMapping dbusMapping{resDumpCurrentObjPath, resDumpProgressIntf,
                            "Status", "string"};
    try
    {
        pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
    }
    catch (const std::exception& e)
    {
        error("Failed to set resource dump operation status, error - {ERROR}",
              "ERROR", e);
    }
}

void DbusToFileHandler::processNewResourceDump(
    const std::string& vspString, const std::string& resDumpReqPass)
{
    try
    {
        std::string objPath = resDumpCurrentObjPath;
        auto propVal = pldm::utils::DBusHandler().getDbusPropertyVariant(
            objPath.c_str(), "Status", resDumpProgressIntf);
        const auto& curResDumpStatus = std::get<ResDumpStatus>(propVal);

        if (curResDumpStatus !=
            "xyz.openbmc_project.Common.Progress.OperationStatus.InProgress")
        {
            return;
        }
    }
    catch (const sdbusplus::exception_t& e)
    {
        error(
            "Error '{ERROR}' found in getting current resource dump status while initiating a new resource dump with object path '{PATH}' and interface {INTERFACE}",
            "ERROR", e, "PATH", resDumpCurrentObjPath, "INTERFACE",
            resDumpProgressIntf);
    }

    namespace fs = std::filesystem;
    const fs::path resDumpDirPath = "/var/lib/pldm/resourcedump";

    if (!fs::exists(resDumpDirPath))
    {
        fs::create_directories(resDumpDirPath);
    }

    // Need to reconsider this logic to set the value as "1" when we have the
    // support to handle multiple resource dumps
    fs::path resDumpFilePath = resDumpDirPath / "1";

    std::ofstream fileHandle;
    fileHandle.open(resDumpFilePath, std::ios::out | std::ofstream::binary);

    if (!fileHandle)
    {
        error("Failed to open resource dump file '{PATH}'", "PATH",
              resDumpFilePath);
        PropertyValue value{resDumpStatus};
        DBusMapping dbusMapping{resDumpCurrentObjPath, resDumpProgressIntf,
                                "Status", "string"};
        try
        {
            pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
        }
        catch (const std::exception& e)
        {
            error(
                "Failed to set resource dump operation status, error - {ERROR}",
                "ERROR", e);
        }
        return;
    }

    // Fill up the file with resource dump parameters and respective sizes
    auto fileFunc = [&fileHandle](auto& paramBuf) {
        uint32_t paramSize = paramBuf.size();
        fileHandle.write((char*)&paramSize, sizeof(paramSize));
        fileHandle << paramBuf;
    };
    fileFunc(vspString);
    fileFunc(resDumpReqPass);

    std::string str;
    if (!resDumpReqPass.empty())
    {
        str = getAcfFileContent();
    }

    fileFunc(str);

    fileHandle.close();
    size_t fileSize = fs::file_size(resDumpFilePath);

    sendNewFileAvailableCmd(fileSize);
}

std::string DbusToFileHandler::getAcfFileContent()
{
    std::string str;
    static constexpr auto acfDirPath = "/etc/acf/service.acf";
    if (fs::exists(acfDirPath))
    {
        std::ifstream file;
        file.open(acfDirPath);
        std::stringstream acfBuf;
        acfBuf << file.rdbuf();
        str = acfBuf.str();
        file.close();
    }
    return str;
}

void DbusToFileHandler::newCsrFileAvailable(const std::string& csr,
                                            const std::string fileHandle)
{
    namespace fs = std::filesystem;
    std::string dirPath = "/var/lib/ibm/bmcweb";
    const fs::path certDirPath = dirPath;

    if (!fs::exists(certDirPath))
    {
        fs::create_directories(certDirPath);
        fs::permissions(certDirPath,
                        fs::perms::others_read | fs::perms::owner_write);
    }

    fs::path certFilePath = certDirPath / ("CSR_" + fileHandle);
    std::ofstream certFile;

    certFile.open(certFilePath, std::ios::out | std::ofstream::binary);

    if (!certFile)
    {
        error("Failed to open certificate file '{PATH}'", "PATH", certFilePath);
        return;
    }

    // Add csr to file
    certFile << csr << std::endl;

    certFile.close();
    uint32_t fileSize = fs::file_size(certFilePath);

    newFileAvailableSendToHost(fileSize, (uint32_t)stoi(fileHandle),
                               PLDM_FILE_TYPE_CERT_SIGNING_REQUEST);
}

void DbusToFileHandler::newFileAvailableSendToHost(
    const uint32_t fileSize, const uint32_t fileHandle, const uint16_t type)
{
    if (instanceIdDb == NULL)
    {
        error("Failed to send csr to remote terminus.");
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = instanceIdDb->next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_NEW_FILE_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc =
        encode_new_file_req(instanceId, type, fileHandle, fileSize, request);
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb->free(mctp_eid, instanceId);
        error("Failed to encode new file request with response code '{RC}'",
              "RC", rc);
        return;
    }
    auto newFileAvailableRespHandler = [](mctp_eid_t /*eid*/,
                                          const pldm_msg* response,
                                          size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error(
                "Failed to receive response for NewFileAvailable command for vmi");
            return;
        }
        uint8_t completionCode{};
        auto rc = decode_new_file_resp(response, respMsgLen, &completionCode);
        if (rc || completionCode)
        {
            error(
                "Failed to decode new file available response for vmi or remote terminus returned error, response code '{RC}' and completion code '{CC}'",
                "RC", rc, "CC", completionCode);
            pldm::utils::reportError(
                "xyz.openbmc_project.PLDM.Error.DecodeNewFileResponseFail");
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        error(
            "Failed to send NewFileAvailable Request to Host for vmi, response code '{RC}'",
            "RC", rc);
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.NewFileAvailableRequestFail");
    }
}

} // namespace oem_ibm
} // namespace requester
} // namespace pldm
