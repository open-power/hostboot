#include "file_io_type_vpd.hpp"

#include "libpldm/base.h"
#include "libpldm/file_io.h"

#include "common/utils.hpp"

#include <stdint.h>

#include <iostream>

typedef uint8_t byte;

namespace pldm
{
namespace responder
{
int keywordHandler::read(uint32_t offset, uint32_t& length, Response& response,
                         oem_platform::Handler* /*oemPlatformHandler*/)
{
    const char* keywrdObjPath =
        "/xyz/openbmc_project/inventory/system/chassis/motherboard";
    const char* keywrdPropName = "PD_D";
    const char* keywrdInterface = "com.ibm.ipzvpd.PSPD";

    std::variant<std::vector<byte>> keywrd;

    try
    {
        auto& bus = pldm::utils::DBusHandler::getBus();
        auto service = pldm::utils::DBusHandler().getService(keywrdObjPath,
                                                             keywrdInterface);
        auto method = bus.new_method_call(service.c_str(), keywrdObjPath,
                                          "org.freedesktop.DBus.Properties",
                                          "Get");
        method.append(keywrdInterface, keywrdPropName);
        auto reply = bus.call(method);
        reply.read(keywrd);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Get keyword error from dbus interface : "
                  << keywrdInterface << " ERROR= " << e.what() << std::endl;
    }

    uint32_t keywrdSize = std::get<std::vector<byte>>(keywrd).size();

    if (length < keywrdSize)
    {
        std::cerr << "length requested is less the keyword size, length: "
                  << length << " keyword size: " << keywrdSize << std::endl;
        return PLDM_ERROR_INVALID_DATA;
    }

    namespace fs = std::filesystem;
    constexpr auto keywrdDirPath = "/tmp/pldm/";
    constexpr auto keywrdFilePath = "/tmp/pldm/vpdKeywrd.bin";

    if (!fs::exists(keywrdDirPath))
    {
        fs::create_directories(keywrdDirPath);
        fs::permissions(keywrdDirPath,
                        fs::perms::others_read | fs::perms::owner_write);
    }

    std::ofstream keywrdFile(keywrdFilePath);
    auto fd = open(keywrdFilePath, std::ios::out | std::ofstream::binary);
    if (!keywrdFile)
    {
        std::cerr << "VPD keyword file open error: " << keywrdFilePath
                  << " errno: " << errno << std::endl;
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.readKeywordHandler.keywordFileOpenError");
        return PLDM_ERROR;
    }

    if (offset > keywrdSize)
    {
        std::cerr << "Offset exceeds file size, OFFSET=" << offset
                  << " FILE_SIZE=" << keywrdSize << std::endl;
        return PLDM_DATA_OUT_OF_RANGE;
    }

    // length of keyword data should be same as keyword data size in dbus object
    length = static_cast<uint32_t>(keywrdSize) - offset;

    auto returnCode = lseek(fd, offset, SEEK_SET);
    if (returnCode == -1)
    {
        std::cerr
            << "Could not find keyword data at given offset. File Seek failed"
            << std::endl;
        return PLDM_ERROR;
    }

    keywrdFile.write((const char*)std::get<std::vector<byte>>(keywrd).data(),
                     keywrdSize);
    if (keywrdFile.bad())
    {
        std::cerr << "Error while writing to file: " << keywrdFilePath
                  << std::endl;
    }
    keywrdFile.close();

    auto rc = readFile(keywrdFilePath, offset, keywrdSize, response);
    fs::remove(keywrdFilePath);
    if (rc)
    {
        std::cerr << "Read error for keyword file with size: " << keywrdSize
                  << std::endl;
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.readKeywordHandler.keywordFileReadError");
        return PLDM_ERROR;
    }
    return PLDM_SUCCESS;
}
} // namespace responder
} // namespace pldm
