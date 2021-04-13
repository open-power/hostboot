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
    sdbusplus::message::object_path resDumpCurrentObjPath) :
    mctp_fd(mctp_fd),
    mctp_eid(mctp_eid), requester(requester),
    resDumpCurrentObjPath(resDumpCurrentObjPath)
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

    uint8_t* responseMsg = nullptr;
    size_t responseMsgSize{};

    auto requesterRc =
        pldm_send_recv(mctp_eid, mctp_fd, requestMsg.data(), requestMsg.size(),
                       &responseMsg, &responseMsgSize);

    std::unique_ptr<uint8_t, decltype(std::free)*> responseMsgPtr{responseMsg,
                                                                  std::free};

    requester->markFree(mctp_eid, instanceId);
    bool isDecodeNewFileRespFailed = false;
    if (requesterRc != PLDM_REQUESTER_SUCCESS)
    {
        std::cerr << "Failed to send resource dump parameters, rc = "
                  << requesterRc << std::endl;
    }
    else
    {
        uint8_t completionCode{};
        auto responsePtr =
            reinterpret_cast<struct pldm_msg*>(responseMsgPtr.get());

        rc = decode_new_file_resp(responsePtr, PLDM_NEW_FILE_RESP_BYTES,
                                  &completionCode);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Failed to decode_new_file_resp: "
                      << "rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << std::endl;
            isDecodeNewFileRespFailed = true;
        }
    }

    if ((requesterRc != PLDM_REQUESTER_SUCCESS) || (isDecodeNewFileRespFailed))
    {
        pldm::utils::reportError(
            "xyz.openbmc_project.bmc.pldm.InternalFailure");

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
}

void DbusToFileHandler::processNewResourceDump(
    const std::string& vspString, const std::string& resDumpReqPass)
{
    // This needs special handling in later point of time. Resource dump without
    // the vsp string is supposed to be a non-disruptive system dump.
    if (vspString.empty())
    {
        std::cerr << "Empty vsp string"
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

} // namespace oem_ibm
} // namespace requester
} // namespace pldm
