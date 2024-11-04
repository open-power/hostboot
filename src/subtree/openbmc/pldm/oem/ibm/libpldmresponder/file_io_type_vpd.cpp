#include "file_io_type_vpd.hpp"

#include "common/utils.hpp"

#include <libpldm/base.h>
#include <libpldm/oem/ibm/file_io.h>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

PHOSPHOR_LOG2_USING;

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
        auto method =
            bus.new_method_call(service.c_str(), keywrdObjPath,
                                "org.freedesktop.DBus.Properties", "Get");
        method.append(keywrdInterface, keywrdPropName);
        auto reply = bus.call(method, dbusTimeout);
        reply.read(keywrd);
    }
    catch (const std::exception& e)
    {
        error(
            "Get keyword error from dbus interface {INTERFACE}, error - {ERROR}",
            "INTERFACE", keywrdInterface, "ERROR", e);
    }

    uint32_t keywrdSize = std::get<std::vector<byte>>(keywrd).size();
    if (length < keywrdSize)
    {
        error("Length '{LENGTH}' requested is less than keyword size '{SIZE}'",
              "LENGTH", length, "SIZE", keywrdSize);
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
        error(
            "Failed to open VPD keyword file '{PATH}', error number - {ERROR_NUM}",
            "PATH", keywrdFilePath, "ERROR_NUM", errno);
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.readKeywordHandler.keywordFileOpenError");
        return PLDM_ERROR;
    }

    if (offset > keywrdSize)
    {
        error("Offset '{OFFSET}' exceeds file size '{SIZE}'", "OFFSET", offset,
              "SIZE", keywrdSize);
        return PLDM_DATA_OUT_OF_RANGE;
    }

    // length of keyword data should be same as keyword data size in dbus
    // object
    length = static_cast<uint32_t>(keywrdSize) - offset;

    auto returnCode = lseek(fd, offset, SEEK_SET);
    if (returnCode == -1)
    {
        error(
            "Could not find keyword data of length '{LENGTH}' at given offset '{OFFSET}'. File Seek failed with response code '{RC}'",
            "LENGTH", length, "OFFSET", offset, "RC", returnCode);
        return PLDM_ERROR;
    }

    keywrdFile.write((const char*)std::get<std::vector<byte>>(keywrd).data(),
                     keywrdSize);
    if (keywrdFile.bad())
    {
        error("Error while writing to file '{PATH}'", "PATH", keywrdFilePath);
    }
    keywrdFile.close();

    auto rc = readFile(keywrdFilePath, offset, keywrdSize, response);
    fs::remove(keywrdFilePath);
    if (rc)
    {
        error("Read error for keyword file with size '{SIZE}'", "SIZE",
              keywrdSize);
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.readKeywordHandler.keywordFileReadError");
        return PLDM_ERROR;
    }
    return PLDM_SUCCESS;
}
} // namespace responder
} // namespace pldm
