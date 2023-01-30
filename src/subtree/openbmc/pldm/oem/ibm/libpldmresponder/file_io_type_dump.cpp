#include "file_io_type_dump.hpp"

#include "common/utils.hpp"
#include "utils.hpp"
#include "xyz/openbmc_project/Common/error.hpp"

#include <libpldm/base.h>
#include <libpldm/file_io.h>
#include <stdint.h>
#include <systemd/sd-bus.h>
#include <unistd.h>

#include <sdbusplus/server.hpp>
#include <xyz/openbmc_project/Dump/NewDump/server.hpp>

#include <exception>
#include <filesystem>
#include <iostream>
#include <type_traits>

using namespace pldm::responder::utils;
using namespace pldm::utils;

namespace pldm
{
namespace responder
{
static constexpr auto dumpEntry = "xyz.openbmc_project.Dump.Entry";
static constexpr auto dumpObjPath = "/xyz/openbmc_project/dump/system";
static constexpr auto systemDumpEntry = "xyz.openbmc_project.Dump.Entry.System";
static constexpr auto resDumpObjPath = "/xyz/openbmc_project/dump/resource";
static constexpr auto resDumpEntry = "com.ibm.Dump.Entry.Resource";

// Resource dump file path to be deleted once hyperviosr validates the input
// parameters. Need to re-look in to this name when we support multiple
// resource dumps.
static constexpr auto resDumpDirPath = "/var/lib/pldm/resourcedump/1";

int DumpHandler::fd = -1;
namespace fs = std::filesystem;

std::string DumpHandler::findDumpObjPath(uint32_t fileHandle)
{
    static constexpr auto DUMP_MANAGER_BUSNAME =
        "xyz.openbmc_project.Dump.Manager";
    static constexpr auto DUMP_MANAGER_PATH = "/xyz/openbmc_project/dump";
    static constexpr auto OBJECT_MANAGER_INTERFACE =
        "org.freedesktop.DBus.ObjectManager";
    auto& bus = pldm::utils::DBusHandler::getBus();

    // Stores the current resource dump entry path
    std::string curResDumpEntryPath{};

    dbus::ObjectValueTree objects;
    auto method =
        bus.new_method_call(DUMP_MANAGER_BUSNAME, DUMP_MANAGER_PATH,
                            OBJECT_MANAGER_INTERFACE, "GetManagedObjects");

    // Select the dump entry interface for system dump or resource dump
    DumpEntryInterface dumpEntryIntf = systemDumpEntry;
    if ((dumpType == PLDM_FILE_TYPE_RESOURCE_DUMP) ||
        (dumpType == PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS))
    {
        dumpEntryIntf = resDumpEntry;
    }

    try
    {
        auto reply = bus.call(method);
        reply.read(objects);
    }

    catch (const std::exception& e)
    {
        std::cerr << "findDumpObjPath: Error " << e.what()
                  << "found with GetManagedObjects call in findDumpObjPath "
                  << "with objPath=" << DUMP_MANAGER_PATH
                  << " and intf=" << dumpEntryIntf << "\n";
        return curResDumpEntryPath;
    }

    for (const auto& object : objects)
    {
        for (const auto& interface : object.second)
        {
            if (interface.first != dumpEntryIntf)
            {
                continue;
            }

            for (auto& propertyMap : interface.second)
            {
                if (propertyMap.first == "SourceDumpId")
                {
                    auto dumpIdPtr = std::get_if<uint32_t>(&propertyMap.second);
                    if (dumpIdPtr != nullptr)
                    {
                        auto dumpId = *dumpIdPtr;
                        if (fileHandle == dumpId)
                        {
                            curResDumpEntryPath = object.first.str;
                            return curResDumpEntryPath;
                        }
                    }
                    else
                    {
                        std::cerr
                            << "Invalid SourceDumpId in curResDumpEntryPath "
                            << curResDumpEntryPath
                            << " but continuing with next entry for a match..."
                            << "\n";
                    }
                }
            }
        }
    }
    return curResDumpEntryPath;
}

int DumpHandler::newFileAvailable(uint64_t length)
{
    static constexpr auto dumpInterface = "xyz.openbmc_project.Dump.NewDump";
    auto& bus = pldm::utils::DBusHandler::getBus();

    auto notifyObjPath = dumpObjPath;
    if (dumpType == PLDM_FILE_TYPE_RESOURCE_DUMP)
    {
        // Setting the Notify path for resource dump
        notifyObjPath = resDumpObjPath;
    }

    try
    {
        auto service =
            pldm::utils::DBusHandler().getService(notifyObjPath, dumpInterface);
        using namespace sdbusplus::xyz::openbmc_project::Dump::server;
        auto method = bus.new_method_call(service.c_str(), notifyObjPath,
                                          dumpInterface, "Notify");
        method.append(fileHandle, length);
        bus.call_noreply(method);
    }
    catch (const std::exception& e)
    {
        std::cerr << "newFileAvailable: Error " << e.what()
                  << "found while notifying new dump to dump manager "
                  << "with objPath=" << notifyObjPath
                  << " and intf=" << dumpInterface << "\n";
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

std::string DumpHandler::getOffloadUri(uint32_t fileHandle)
{
    auto path = findDumpObjPath(fileHandle);
    if (path.empty())
    {
        return {};
    }

    std::string socketInterface{};

    try
    {
        socketInterface =
            pldm::utils::DBusHandler().getDbusProperty<std::string>(
                path.c_str(), "OffloadUri", dumpEntry);
    }
    catch (const std::exception& e)
    {
        std::cerr << "getOffloadUri: Error " << e.what()
                  << "found while fetching the dump offload URI "
                  << "with objPath=" << path.c_str()
                  << " and intf=" << socketInterface << "\n";
    }

    return socketInterface;
}

int DumpHandler::writeFromMemory(uint32_t, uint32_t length, uint64_t address,
                                 oem_platform::Handler* /*oemPlatformHandler*/)
{
    if (DumpHandler::fd == -1)
    {
        auto socketInterface = getOffloadUri(fileHandle);
        int sock = setupUnixSocket(socketInterface);
        if (sock < 0)
        {
            sock = -errno;
            close(DumpHandler::fd);
            std::cerr
                << "DumpHandler::writeFromMemory: setupUnixSocket() failed"
                << std::endl;
            std::remove(socketInterface.c_str());
            return PLDM_ERROR;
        }

        DumpHandler::fd = sock;
    }
    return transferFileDataToSocket(DumpHandler::fd, length, address);
}

int DumpHandler::write(const char* buffer, uint32_t, uint32_t& length,
                       oem_platform::Handler* /*oemPlatformHandler*/)
{
    int rc = writeToUnixSocket(DumpHandler::fd, buffer, length);
    if (rc < 0)
    {
        rc = -errno;
        close(DumpHandler::fd);
        auto socketInterface = getOffloadUri(fileHandle);
        std::remove(socketInterface.c_str());
        std::cerr << "DumpHandler::write: writeToUnixSocket() failed"
                  << std::endl;
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

int DumpHandler::fileAck(uint8_t fileStatus)
{
    auto path = findDumpObjPath(fileHandle);
    if (dumpType == PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS)
    {
        if (fileStatus != PLDM_SUCCESS)
        {
            std::cerr << "Failue in resource dump file ack" << std::endl;
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");

            PropertyValue value{
                "xyz.openbmc_project.Common.Progress.OperationStatus.Failed"};
            DBusMapping dbusMapping{path, "xyz.openbmc_project.Common.Progress",
                                    "Status", "string"};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                std::cerr << "fileAck: Error " << e.what()
                          << "found while setting the dump progress status as "
                          << "Failed with objPath=" << path.c_str()
                          << " and intf=Common.Progress"
                          << "\n";
            }
        }

        if (fs::exists(resDumpDirPath))
        {
            fs::remove_all(resDumpDirPath);
        }
        return PLDM_SUCCESS;
    }

    if (!path.empty())
    {
        if (fileStatus == PLDM_ERROR_FILE_DISCARDED)
        {
            uint32_t val = 0xFFFFFFFF;
            PropertyValue value = static_cast<uint32_t>(val);
            auto dumpIntf = resDumpEntry;

            if (dumpType == PLDM_FILE_TYPE_DUMP)
            {
                dumpIntf = systemDumpEntry;
            }

            DBusMapping dbusMapping{path.c_str(), dumpIntf, "SourceDumpId",
                                    "uint32_t"};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                std::cerr << "fileAck: Failed to make a d-bus call to DUMP "
                             "manager to reset source dump id of "
                          << path.c_str() << ", with ERROR=" << e.what()
                          << "\n";
                pldm::utils::reportError(
                    "xyz.openbmc_project.bmc.PLDM.fileAck.SourceDumpIdResetFail");
                return PLDM_ERROR;
            }

            auto& bus = pldm::utils::DBusHandler::getBus();
            try
            {
                auto method = bus.new_method_call(
                    "xyz.openbmc_project.Dump.Manager", path.c_str(),
                    "xyz.openbmc_project.Object.Delete", "Delete");
                bus.call(method);
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "fileAck: Failed to make a d-bus method to delete the dump entry "
                    << path.c_str() << ", with ERROR=" << e.what() << "\n";
                pldm::utils::reportError(
                    "xyz.openbmc_project.bmc.PLDM.fileAck.DumpEntryDeleteFail");
                return PLDM_ERROR;
            }
            return PLDM_SUCCESS;
        }

        if (dumpType == PLDM_FILE_TYPE_DUMP ||
            dumpType == PLDM_FILE_TYPE_RESOURCE_DUMP)
        {
            PropertyValue value{true};
            DBusMapping dbusMapping{path, dumpEntry, "Offloaded", "bool"};
            try
            {
                pldm::utils::DBusHandler().setDbusProperty(dbusMapping, value);
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "fileAck: Failed to make a d-bus method to set the dump "
                    << "offloaded property to true with path=" << path.c_str()
                    << "and with ERROR=" << e.what() << "\n";
            }

            auto socketInterface = getOffloadUri(fileHandle);
            std::remove(socketInterface.c_str());
            if (DumpHandler::fd >= 0)
            {
                close(DumpHandler::fd);
                DumpHandler::fd = -1;
            }
        }
        return PLDM_SUCCESS;
    }

    return PLDM_ERROR;
}

int DumpHandler::readIntoMemory(uint32_t offset, uint32_t& length,
                                uint64_t address,
                                oem_platform::Handler* /*oemPlatformHandler*/)
{
    if (dumpType != PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }
    return transferFileData(resDumpDirPath, true, offset, length, address);
}

int DumpHandler::read(uint32_t offset, uint32_t& length, Response& response,
                      oem_platform::Handler* /*oemPlatformHandler*/)
{
    if (dumpType != PLDM_FILE_TYPE_RESOURCE_DUMP_PARMS)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }
    return readFile(resDumpDirPath, offset, length, response);
}

} // namespace responder
} // namespace pldm
