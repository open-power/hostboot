#include "dbus_to_file_handler.hpp"

#include "libpldm/requester/pldm.h"
#include "oem/ibm/libpldm/file_io.h"

#include "common/utils.hpp"

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
        std::cerr << "Failed to send resource dump parameters as requester is "
                     "not set";
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = requester->getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_NEW_FILE_REQ_BYTES + fileSize);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    // Need to revisit this logic at the time of multiple resource dump support
    uint32_t fileHandle = 1;

    auto rc =
        encode_new_file_req(instanceId, PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS,
                            fileHandle, fileSize, request);
    if (rc != PLDM_SUCCESS)
    {
        requester->markFree(mctp_eid, instanceId);
        std::cerr << "Failed to encode_new_file_req, rc = " << rc << std::endl;
        return;
    }

    auto newFileAvailableRespHandler = [this](mctp_eid_t /*eid*/,
                                              const pldm_msg* response,
                                              size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            std::cerr
                << "Failed to receive response for NewFileAvailable command \n";
            return;
        }
        uint8_t completionCode{};
        auto rc = decode_new_file_resp(response, respMsgLen, &completionCode);
        if (rc || completionCode)
        {
            std::cerr << "Failed to decode_new_file_resp or"
                      << " Host returned error for new_file_available"
                      << " rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << "\n";
            reportResourceDumpFailure();
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        std::cerr << "Failed to send NewFileAvailable Request to Host \n";
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
        std::cerr << "failed to set resource dump operation status, "
                     "ERROR="
                  << e.what() << "\n";
    }
}

void DbusToFileHandler::processNewResourceDump(
    const std::string& vspString, const std::string& resDumpReqPass)
{
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
        std::cerr << "resource dump file open error: " << resDumpFilePath
                  << "\n";
        PropertyValue value{resDumpStatus};
        DBusMapping dbusMapping{resDumpCurrentObjPath, resDumpProgressIntf,
                                "Status", "string"};
        try
        {
            pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
        }
        catch (const std::exception& e)
        {
            std::cerr << "failed to set resource dump operation status, "
                         "ERROR="
                      << e.what() << "\n";
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

    fileHandle.close();
    size_t fileSize = fs::file_size(resDumpFilePath);

    sendNewFileAvailableCmd(fileSize);
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
        std::cerr << "cert file open error: " << certFilePath << "\n";
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
        std::cerr << "Failed to send csr to host.";
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
        return;
    }
    auto instanceId = requester->getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_NEW_FILE_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc =
        encode_new_file_req(instanceId, type, fileHandle, fileSize, request);
    if (rc != PLDM_SUCCESS)
    {
        requester->markFree(mctp_eid, instanceId);
        std::cerr << "Failed to encode_new_file_req, rc = " << rc << std::endl;
        return;
    }
    auto newFileAvailableRespHandler = [](mctp_eid_t /*eid*/,
                                          const pldm_msg* response,
                                          size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            std::cerr << "Failed to receive response for NewFileAvailable "
                         "command for vmi \n";
            return;
        }
        uint8_t completionCode{};
        auto rc = decode_new_file_resp(response, respMsgLen, &completionCode);
        if (rc || completionCode)
        {
            std::cerr << "Failed to decode_new_file_resp for vmi, or"
                      << " Host returned error for new_file_available"
                      << " rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << "\n";
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
        }
    };
    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_OEM, PLDM_NEW_FILE_AVAILABLE,
        std::move(requestMsg), std::move(newFileAvailableRespHandler));
    if (rc)
    {
        std::cerr
            << "Failed to send NewFileAvailable Request to Host for vmi \n";
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");
    }
}

} // namespace oem_ibm
} // namespace requester
} // namespace pldm
