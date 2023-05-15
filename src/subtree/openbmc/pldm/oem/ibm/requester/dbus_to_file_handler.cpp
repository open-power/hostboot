#include "dbus_to_file_handler.hpp"

#include "common/utils.hpp"

#include <libpldm/file_io.h>
#include <libpldm/pldm.h>

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

static constexpr auto resDumpObjPath =
    "/xyz/openbmc_project/dump/resource/entry";
static constexpr auto resDumpEntry = "com.ibm.Dump.Entry.Resource";
static constexpr auto resDumpProgressIntf =
    "xyz.openbmc_project.Common.Progress";
static constexpr auto resDumpStatus =
    "xyz.openbmc_project.Common.Progress.OperationStatus.Failed";

DbusToFileHandler::DbusToFileHandler(
    int mctp_fd, uint8_t mctp_eid, dbus_api::Requester* requester,
    sdbusplus::message::object_path resDumpCurrentObjPath,
    pldm::requester::Handler<pldm::requester::Request>* handler) :
    mctp_fd(mctp_fd),
    mctp_eid(mctp_eid), requester(requester),
    resDumpCurrentObjPath(resDumpCurrentObjPath), handler(handler)
{}

void DbusToFileHandler::sendNewFileAvailableCmd(uint64_t fileSize)
{
    if (requester == NULL)
    {
        error(
            "Failed to send resource dump parameters as requester is not set");
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = requester->getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_NEW_FILE_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    // Need to revisit this logic at the time of multiple resource dump support
    uint32_t fileHandle = 1;

    auto rc = encode_new_file_req(instanceId,
                                  PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS,
                                  fileHandle, fileSize, request);
    if (rc != PLDM_SUCCESS)
    {
        requester->markFree(mctp_eid, instanceId);
        error("Failed to encode_new_file_req, rc = {RC}", "RC", rc);
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
                "Failed to decode_new_file_resp or Host returned error for new_file_available rc={RC}, cc = {CC}",
                "RC", rc, "CC", static_cast<unsigned>(completionCode));
            reportResourceDumpFailure();
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        error("Failed to send NewFileAvailable Request to Host");
        reportResourceDumpFailure();
    }
}

void DbusToFileHandler::reportResourceDumpFailure()
{
    pldm::utils::reportError("xyz.openbmc_project.bmc.pldm.InternalFailure");

    PropertyValue value{resDumpStatus};
    DBusMapping dbusMapping{resDumpCurrentObjPath, resDumpProgressIntf,
                            "Status", "string"};
    try
    {
        pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
    }
    catch (const std::exception& e)
    {
        error("failed to set resource dump operation status, ERROR={ERR_EXCEP}",
              "ERR_EXCEP", e.what());
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
            "Error {ERR_EXCEP} found in getting current resource dump status while initiating a new resource dump with objPath={DUMP_OBJ_PATH} and intf={DUMP_PROG_INTF}",
            "ERR_EXCEP", e.what(), "DUMP_OBJ_PATH",
            resDumpCurrentObjPath.str.c_str(), "DUMP_PROG_INTF",
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
        error("resource dump file open error:{RES_DUMP_PATH}", "RES_DUMP_PATH",
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
                "failed to set resource dump operation status, ERROR={ERR_EXCEP}",
                "ERR_EXCEP", e.what());
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
        error("cert file open error: {CERT_PATH}", "CERT_PATH",
              certFilePath.c_str());
        return;
    }

    // Add csr to file
    certFile << csr << std::endl;

    certFile.close();
    uint32_t fileSize = fs::file_size(certFilePath);

    newFileAvailableSendToHost(fileSize, (uint32_t)stoi(fileHandle),
                               PLDM_FILE_TYPE_CERT_SIGNING_REQUEST);
}

void DbusToFileHandler::newFileAvailableSendToHost(const uint32_t fileSize,
                                                   const uint32_t fileHandle,
                                                   const uint16_t type)
{
    if (requester == NULL)
    {
        error("Failed to send csr to host.");
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = requester->getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_NEW_FILE_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_new_file_req(instanceId, type, fileHandle, fileSize,
                                  request);
    if (rc != PLDM_SUCCESS)
    {
        requester->markFree(mctp_eid, instanceId);
        error("Failed to encode_new_file_req, rc = {RC}", "RC", rc);
        return;
    }
    auto newFileAvailableRespHandler =
        [](mctp_eid_t /*eid*/, const pldm_msg* response, size_t respMsgLen) {
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
                "Failed to decode_new_file_resp for vmi, or Host returned error for new_file_available rc = {RC}, cc = {CC}",
                "RC", rc, "CC", static_cast<unsigned>(completionCode));
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        error("Failed to send NewFileAvailable Request to Host for vmi");
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
    }
}

} // namespace oem_ibm
} // namespace requester
} // namespace pldm
