#include "file_io_type_cert.hpp"

#include "common/utils.hpp"

#include <libpldm/base.h>
#include <libpldm/file_io.h>
#include <stdint.h>

#include <phosphor-logging/lg2.hpp>

#include <iostream>

PHOSPHOR_LOG2_USING;

namespace pldm
{
using namespace utils;

namespace responder
{
constexpr auto certObjPath = "/xyz/openbmc_project/certs/ca/entry/";
constexpr auto certEntryIntf = "xyz.openbmc_project.Certs.Entry";
static constexpr auto certFilePath = "/var/lib/ibm/bmcweb/";

CertMap CertHandler::certMap;

int CertHandler::writeFromMemory(uint32_t offset, uint32_t length,
                                 uint64_t address,
                                 oem_platform::Handler* /*oemPlatformHandler*/)
{
    auto it = certMap.find(certType);
    if (it == certMap.end())
    {
        error(
            "CertHandler::writeFromMemory:file for type {CERT_TYPE} doesn't exist",
            "CERT_TYPE", certType);
        return PLDM_ERROR;
    }

    auto fd = std::get<0>(it->second);
    auto& remSize = std::get<1>(it->second);
    auto rc = transferFileData(fd, false, offset, length, address);
    if (rc == PLDM_SUCCESS)
    {
        remSize -= length;
        if (!remSize)
        {
            close(fd);
            certMap.erase(it);
        }
    }
    return rc;
}

int CertHandler::readIntoMemory(uint32_t offset, uint32_t& length,
                                uint64_t address,
                                oem_platform::Handler* /*oemPlatformHandler*/)
{
    std::string filePath = certFilePath;
    filePath += "CSR_" + std::to_string(fileHandle);
    if (certType != PLDM_FILE_TYPE_CERT_SIGNING_REQUEST)
    {
        return PLDM_ERROR_INVALID_DATA;
    }
    auto rc = transferFileData(filePath.c_str(), true, offset, length, address);
    fs::remove(filePath);
    if (rc)
    {
        return PLDM_ERROR;
    }
    return PLDM_SUCCESS;
}

int CertHandler::read(uint32_t offset, uint32_t& length, Response& response,
                      oem_platform::Handler* /*oemPlatformHandler*/)
{
    info(
        "CertHandler::read:Read file response for Sign CSR, file handle: {FILE_HANDLE}",
        "FILE_HANDLE", fileHandle);
    std::string filePath = certFilePath;
    filePath += "CSR_" + std::to_string(fileHandle);
    if (certType != PLDM_FILE_TYPE_CERT_SIGNING_REQUEST)
    {
        return PLDM_ERROR_INVALID_DATA;
    }
    auto rc = readFile(filePath.c_str(), offset, length, response);
    fs::remove(filePath);
    if (rc)
    {
        return PLDM_ERROR;
    }
    return PLDM_SUCCESS;
}

int CertHandler::write(const char* buffer, uint32_t offset, uint32_t& length,
                       oem_platform::Handler* /*oemPlatformHandler*/)
{
    auto it = certMap.find(certType);
    if (it == certMap.end())
    {
        error("CertHandler::write:file for type {CERT_TYPE} doesn't exist",
              "CERT_TYPE", certType);
        return PLDM_ERROR;
    }

    auto fd = std::get<0>(it->second);
    int rc = lseek(fd, offset, SEEK_SET);
    if (rc == -1)
    {
        error("CertHandler::write:lseek failed, ERROR={ERR}, OFFSET={OFFSET}",
              "ERR", errno, "OFFSET", offset);
        return PLDM_ERROR;
    }
    rc = ::write(fd, buffer, length);
    if (rc == -1)
    {
        error(
            "CertHandler::write:file write failed, ERROR={ERR}, LENGTH={LEN}, OFFSET={OFFSET}",
            "ERR", errno, "LEN", length, "OFFSET", offset);
        return PLDM_ERROR;
    }
    length = rc;
    auto& remSize = std::get<1>(it->second);
    remSize -= length;
    if (!remSize)
    {
        close(fd);
        certMap.erase(it);
    }

    if (certType == PLDM_FILE_TYPE_SIGNED_CERT)
    {
        constexpr auto certObjPath = "/xyz/openbmc_project/certs/ca/entry/";
        constexpr auto certEntryIntf = "xyz.openbmc_project.Certs.Entry";

        std::string filePath = certFilePath;
        filePath += "ClientCert_" + std::to_string(fileHandle);

        std::ifstream inFile;
        inFile.open(filePath);
        std::stringstream strStream;
        strStream << inFile.rdbuf();
        std::string str = strStream.str();
        inFile.close();

        if (!str.empty())
        {
            PropertyValue value{str};

            DBusMapping dbusMapping{certObjPath + std::to_string(fileHandle),
                                    certEntryIntf, "ClientCertificate",
                                    "string"};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                error(
                    "CertHandler::write:failed to set Client certificate, ERROR={ERR_EXCEP}",
                    "ERR_EXCEP", e.what());
                return PLDM_ERROR;
            }
            PropertyValue valueStatus{
                "xyz.openbmc_project.Certs.Entry.State.Complete"};
            DBusMapping dbusMappingStatus{certObjPath +
                                              std::to_string(fileHandle),
                                          certEntryIntf, "Status", "string"};
            try
            {
                info(
                    "CertHandler::write:Client cert write, status: complete. File handle: {FILE_HANDLE}",
                    "FILE_HANDLE", fileHandle);
                pldm::utils::DBusHandler().setDbusProperty(dbusMappingStatus,
                                                           valueStatus);
            }
            catch (const std::exception& e)
            {
                error(
                    "CertHandler::write:failed to set status property of certicate entry, ERROR={ERR_EXCEP}",
                    "ERR_EXCEP", e.what());
                return PLDM_ERROR;
            }
            fs::remove(filePath);
        }
        else
        {
            PropertyValue value{"xyz.openbmc_project.Certs.Entry.State.BadCSR"};
            DBusMapping dbusMapping{certObjPath + std::to_string(fileHandle),
                                    certEntryIntf, "Status", "string"};
            try
            {
                info(
                    "CertHandler::write:Client cert write, status: Bad CSR. File handle: {FILE_HANDLE}",
                    "FILE_HANDLE", fileHandle);
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                error(
                    "CertHandler::write:failed to set status property of certicate entry, {ERR_EXCEP}",
                    "ERR_EXCEP", e.what());
                return PLDM_ERROR;
            }
        }
    }
    return PLDM_SUCCESS;
}

int CertHandler::newFileAvailable(uint64_t length)
{
    fs::create_directories(certFilePath);
    fs::permissions(certFilePath,
                    fs::perms::others_read | fs::perms::owner_write);
    int fileFd = -1;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    std::string filePath = certFilePath;

    if (certType == PLDM_FILE_TYPE_CERT_SIGNING_REQUEST)
    {
        return PLDM_ERROR_INVALID_DATA;
    }
    if (certType == PLDM_FILE_TYPE_SIGNED_CERT)
    {
        info(
            "CertHandler::newFileAvailable:new file available client cert file, file handle: {FILE_HANDLE}",
            "FILE_HANDLE", fileHandle);
        fileFd = open(
            (filePath + "ClientCert_" + std::to_string(fileHandle)).c_str(),
            flags, S_IRUSR | S_IWUSR);
    }
    else if (certType == PLDM_FILE_TYPE_ROOT_CERT)
    {
        fileFd =
            open((filePath + "RootCert").c_str(), flags, S_IRUSR | S_IWUSR);
    }
    if (fileFd == -1)
    {
        error(
            "CertHandler::newFileAvailable:failed to open file for type {CERT_TYPE} ERROR={ERR}",
            "CERT_TYPE", certType, "ERR", errno);
        return PLDM_ERROR;
    }
    certMap.emplace(certType, std::tuple(fileFd, length));
    return PLDM_SUCCESS;
}

int CertHandler::newFileAvailableWithMetaData(uint64_t length,
                                              uint32_t metaDataValue1,
                                              uint32_t /*metaDataValue2*/,
                                              uint32_t /*metaDataValue3*/,
                                              uint32_t /*metaDataValue4*/)
{
    fs::create_directories(certFilePath);
    fs::permissions(certFilePath,
                    fs::perms::others_read | fs::perms::owner_write);
    int fileFd = -1;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    std::string filePath = certFilePath;

    if (certType == PLDM_FILE_TYPE_CERT_SIGNING_REQUEST)
    {
        return PLDM_ERROR_INVALID_DATA;
    }
    if (certType == PLDM_FILE_TYPE_SIGNED_CERT)
    {
        if (metaDataValue1 == PLDM_SUCCESS)
        {
            error(
                "CertHandler::newFileAvailableWithMetaData:new file available client cert file, file handle: {FILE_HANDLE}",
                "FILE_HANDLE", fileHandle);
            fileFd = open(
                (filePath + "ClientCert_" + std::to_string(fileHandle)).c_str(),
                flags, S_IRUSR | S_IWUSR);
        }
        else if (metaDataValue1 == PLDM_INVALID_CERT_DATA)
        {
            error(
                "newFileAvailableWithMetaData:client cert file Invalid data, file handle: {FILE_HANDLE}",
                "FILE_HANDLE", fileHandle);
            DBusMapping dbusMapping{certObjPath + std::to_string(fileHandle),
                                    certEntryIntf, "Status", "string"};
            std::string status = "xyz.openbmc_project.Certs.Entry.State.BadCSR";
            PropertyValue value{status};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                error(
                    "newFileAvailableWithMetaData:Failed to set status property of certicate entry, ERROR= {ERR_EXCEP}",
                    "ERR_EXCEP", e.what());
                return PLDM_ERROR;
            }
        }
    }
    else if (certType == PLDM_FILE_TYPE_ROOT_CERT)
    {
        fileFd =
            open((filePath + "RootCert").c_str(), flags, S_IRUSR | S_IWUSR);
    }
    if (fileFd == -1)
    {
        error(
            "newFileAvailableWithMetaData:failed to open file for type {CERT_TYPE} ERROR={ERR}",
            "CERT_TYPE", certType, "ERR", errno);
        return PLDM_ERROR;
    }
    certMap.emplace(certType, std::tuple(fileFd, length));
    return PLDM_SUCCESS;
}

int CertHandler::fileAckWithMetaData(uint8_t fileStatus,
                                     uint32_t /*metaDataValue1*/,
                                     uint32_t /*metaDataValue2*/,
                                     uint32_t /*metaDataValue3*/,
                                     uint32_t /*metaDataValue4*/)
{
    if (certType == PLDM_FILE_TYPE_CERT_SIGNING_REQUEST)
    {
        DBusMapping dbusMapping{certObjPath + std::to_string(fileHandle),
                                certEntryIntf, "Status", "string"};
        PropertyValue value = "xyz.openbmc_project.Certs.Entry.State.Pending";
        if (fileStatus == PLDM_ERROR_INVALID_DATA)
        {
            value = "xyz.openbmc_project.Certs.Entry.State.BadCSR";
        }
        else if (fileStatus == PLDM_ERROR_NOT_READY)
        {
            value = "xyz.openbmc_project.Certs.Entry.State.Pending";
        }
        try
        {
            pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
        }
        catch (const std::exception& e)
        {
            error(
                "CertHandler::fileAckWithMetaData:Failed to set status property of certicate entry, ERROR={ERR_EXCEP}",
                "ERR_EXCEP", e.what());
            return PLDM_ERROR;
        }
    }
    return PLDM_SUCCESS;
}

} // namespace responder
} // namespace pldm
