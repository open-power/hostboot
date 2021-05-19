#include "file_io_type_cert.hpp"

#include "libpldm/base.h"
#include "oem/ibm/libpldm/file_io.h"

#include "common/utils.hpp"

#include <stdint.h>

#include <iostream>

namespace pldm
{
namespace responder
{

static constexpr auto certFilePath = "/var/lib/ibm/bmcweb/";

CertMap CertHandler::certMap;

int CertHandler::writeFromMemory(uint32_t offset, uint32_t length,
                                 uint64_t address,
                                 oem_platform::Handler* /*oemPlatformHandler*/)
{
    auto it = certMap.find(certType);
    if (it == certMap.end())
    {
        std::cerr << "file for type " << certType << " doesn't exist\n";
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
        std::cerr << "file for type " << certType << " doesn't exist\n";
        return PLDM_ERROR;
    }

    auto fd = std::get<0>(it->second);
    int rc = lseek(fd, offset, SEEK_SET);
    if (rc == -1)
    {
        std::cerr << "lseek failed, ERROR=" << errno << ", OFFSET=" << offset
                  << "\n";
        return PLDM_ERROR;
    }
    rc = ::write(fd, buffer, length);
    if (rc == -1)
    {
        std::cerr << "file write failed, ERROR=" << errno
                  << ", LENGTH=" << length << ", OFFSET=" << offset << "\n";
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
                std::cerr << "failed to set Client certificate, "
                             "ERROR="
                          << e.what() << "\n";
                return PLDM_ERROR;
            }
            PropertyValue valueStatus{
                "xyz.openbmc_project.Certs.Entry.State.Complete"};
            DBusMapping dbusMappingStatus{certObjPath +
                                              std::to_string(fileHandle),
                                          certEntryIntf, "Status", "string"};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMappingStatus,
                                                           valueStatus);
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "failed to set status property of certicate entry, "
                       "ERROR="
                    << e.what() << "\n";
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
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "failed to set status property of certicate entry, "
                       "ERROR="
                    << e.what() << "\n";
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
        std::cerr << "failed to open file for type " << certType
                  << " ERROR=" << errno << "\n";
        return PLDM_ERROR;
    }
    certMap.emplace(certType, std::tuple(fileFd, length));
    return PLDM_SUCCESS;
}

} // namespace responder
} // namespace pldm
