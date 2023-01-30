#include "update_manager.hpp"

#include "activation.hpp"
#include "common/utils.hpp"
#include "package_parser.hpp"

#include <cassert>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <string>

namespace pldm
{

namespace fw_update
{

namespace fs = std::filesystem;
namespace software = sdbusplus::xyz::openbmc_project::Software::server;

int UpdateManager::processPackage(const std::filesystem::path& packageFilePath)
{
    // If no devices discovered, take no action on the package.
    if (!descriptorMap.size())
    {
        return 0;
    }

    namespace software = sdbusplus::xyz::openbmc_project::Software::server;
    // If a firmware activation of a package is in progress, don't proceed with
    // package processing
    if (activation)
    {
        if (activation->activation() ==
            software::Activation::Activations::Activating)
        {
            std::cerr
                << "Activation of PLDM FW update package already in progress"
                << ", PACKAGE_VERSION=" << parser->pkgVersion << "\n";
            std::filesystem::remove(packageFilePath);
            return -1;
        }
        else
        {
            clearActivationInfo();
        }
    }

    package.open(packageFilePath,
                 std::ios::binary | std::ios::in | std::ios::ate);
    if (!package.good())
    {
        std::cerr << "Opening the PLDM FW update package failed, ERR="
                  << unsigned(errno) << ", PACKAGEFILE=" << packageFilePath
                  << "\n";
        package.close();
        std::filesystem::remove(packageFilePath);
        return -1;
    }

    uintmax_t packageSize = package.tellg();
    if (packageSize < sizeof(pldm_package_header_information))
    {
        std::cerr << "PLDM FW update package length less than the length of "
                     "the package header information, PACKAGESIZE="
                  << packageSize << "\n";
        package.close();
        std::filesystem::remove(packageFilePath);
        return -1;
    }

    package.seekg(0);
    std::vector<uint8_t> packageHeader(sizeof(pldm_package_header_information));
    package.read(reinterpret_cast<char*>(packageHeader.data()),
                 sizeof(pldm_package_header_information));

    auto pkgHeaderInfo =
        reinterpret_cast<const pldm_package_header_information*>(
            packageHeader.data());
    auto pkgHeaderInfoSize = sizeof(pldm_package_header_information) +
                             pkgHeaderInfo->package_version_string_length;
    packageHeader.clear();
    packageHeader.resize(pkgHeaderInfoSize);
    package.seekg(0);
    package.read(reinterpret_cast<char*>(packageHeader.data()),
                 pkgHeaderInfoSize);

    parser = parsePkgHeader(packageHeader);
    if (parser == nullptr)
    {
        std::cerr << "Invalid PLDM package header information"
                  << "\n";
        package.close();
        std::filesystem::remove(packageFilePath);
        return -1;
    }

    // Populate object path with the hash of the package version
    size_t versionHash = std::hash<std::string>{}(parser->pkgVersion);
    objPath = swRootPath + std::to_string(versionHash);

    package.seekg(0);
    packageHeader.resize(parser->pkgHeaderSize);
    package.read(reinterpret_cast<char*>(packageHeader.data()),
                 parser->pkgHeaderSize);
    try
    {
        parser->parse(packageHeader, packageSize);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Invalid PLDM package header"
                  << "\n";
        activation = std::make_unique<Activation>(
            pldm::utils::DBusHandler::getBus(), objPath,
            software::Activation::Activations::Invalid, this);
        package.close();
        parser.reset();
        return -1;
    }

    auto deviceUpdaterInfos =
        associatePkgToDevices(parser->getFwDeviceIDRecords(), descriptorMap,
                              totalNumComponentUpdates);
    if (!deviceUpdaterInfos.size())
    {
        std::cerr
            << "No matching devices found with the PLDM firmware update package"
            << "\n";
        activation = std::make_unique<Activation>(
            pldm::utils::DBusHandler::getBus(), objPath,
            software::Activation::Activations::Invalid, this);
        package.close();
        parser.reset();
        return 0;
    }

    const auto& fwDeviceIDRecords = parser->getFwDeviceIDRecords();
    const auto& compImageInfos = parser->getComponentImageInfos();

    for (const auto& deviceUpdaterInfo : deviceUpdaterInfos)
    {
        const auto& fwDeviceIDRecord =
            fwDeviceIDRecords[deviceUpdaterInfo.second];
        auto search = componentInfoMap.find(deviceUpdaterInfo.first);
        deviceUpdaterMap.emplace(
            deviceUpdaterInfo.first,
            std::make_unique<DeviceUpdater>(
                deviceUpdaterInfo.first, package, fwDeviceIDRecord,
                compImageInfos, search->second, MAXIMUM_TRANSFER_SIZE, this));
    }

    fwPackageFilePath = packageFilePath;
    activation = std::make_unique<Activation>(
        pldm::utils::DBusHandler::getBus(), objPath,
        software::Activation::Activations::Ready, this);
    activationProgress = std::make_unique<ActivationProgress>(
        pldm::utils::DBusHandler::getBus(), objPath);

    return 0;
}

DeviceUpdaterInfos UpdateManager::associatePkgToDevices(
    const FirmwareDeviceIDRecords& fwDeviceIDRecords,
    const DescriptorMap& descriptorMap,
    TotalComponentUpdates& totalNumComponentUpdates)
{
    DeviceUpdaterInfos deviceUpdaterInfos;
    for (size_t index = 0; index < fwDeviceIDRecords.size(); ++index)
    {
        const auto& deviceIDDescriptors =
            std::get<Descriptors>(fwDeviceIDRecords[index]);
        for (const auto& [eid, descriptors] : descriptorMap)
        {
            if (std::includes(descriptors.begin(), descriptors.end(),
                              deviceIDDescriptors.begin(),
                              deviceIDDescriptors.end()))
            {
                deviceUpdaterInfos.emplace_back(std::make_pair(eid, index));
                const auto& applicableComponents =
                    std::get<ApplicableComponents>(fwDeviceIDRecords[index]);
                totalNumComponentUpdates += applicableComponents.size();
            }
        }
    }
    return deviceUpdaterInfos;
}

void UpdateManager::updateDeviceCompletion(mctp_eid_t eid, bool status)
{
    deviceUpdateCompletionMap.emplace(eid, status);
    if (deviceUpdateCompletionMap.size() == deviceUpdaterMap.size())
    {
        for (const auto& [eid, status] : deviceUpdateCompletionMap)
        {
            if (!status)
            {
                activation->activation(
                    software::Activation::Activations::Failed);
                return;
            }
        }

        auto endTime = std::chrono::steady_clock::now();
        std::cerr << "Firmware update time: "
                  << std::chrono::duration<double, std::milli>(endTime -
                                                               startTime)
                         .count()
                  << " ms\n";
        activation->activation(software::Activation::Activations::Active);
    }
    return;
}

Response UpdateManager::handleRequest(mctp_eid_t eid, uint8_t command,
                                      const pldm_msg* request, size_t reqMsgLen)
{
    Response response(sizeof(pldm_msg), 0);
    if (deviceUpdaterMap.contains(eid))
    {
        auto search = deviceUpdaterMap.find(eid);
        if (command == PLDM_REQUEST_FIRMWARE_DATA)
        {
            return search->second->requestFwData(request, reqMsgLen);
        }
        else if (command == PLDM_TRANSFER_COMPLETE)
        {
            return search->second->transferComplete(request, reqMsgLen);
        }
        else if (command == PLDM_VERIFY_COMPLETE)
        {
            return search->second->verifyComplete(request, reqMsgLen);
        }
        else if (command == PLDM_APPLY_COMPLETE)
        {
            return search->second->applyComplete(request, reqMsgLen);
        }
        else
        {
            auto ptr = reinterpret_cast<pldm_msg*>(response.data());
            auto rc = encode_cc_only_resp(
                request->hdr.instance_id, request->hdr.type,
                request->hdr.command, PLDM_ERROR_INVALID_DATA, ptr);
            assert(rc == PLDM_SUCCESS);
        }
    }
    else
    {
        auto ptr = reinterpret_cast<pldm_msg*>(response.data());
        auto rc = encode_cc_only_resp(request->hdr.instance_id,
                                      request->hdr.type, +request->hdr.command,
                                      PLDM_FWUP_COMMAND_NOT_EXPECTED, ptr);
        assert(rc == PLDM_SUCCESS);
    }

    return response;
}

void UpdateManager::activatePackage()
{
    startTime = std::chrono::steady_clock::now();
    for (const auto& [eid, deviceUpdaterPtr] : deviceUpdaterMap)
    {
        deviceUpdaterPtr->startFwUpdateFlow();
    }
}

void UpdateManager::clearActivationInfo()
{
    activation.reset();
    activationProgress.reset();
    objPath.clear();

    deviceUpdaterMap.clear();
    deviceUpdateCompletionMap.clear();
    parser.reset();
    package.close();
    std::filesystem::remove(fwPackageFilePath);
    totalNumComponentUpdates = 0;
    compUpdateCompletedCount = 0;
}

void UpdateManager::updateActivationProgress()
{
    compUpdateCompletedCount++;
    auto progressPercent = static_cast<uint8_t>(std::floor(
        (100 * compUpdateCompletedCount) / totalNumComponentUpdates));
    activationProgress->progress(progressPercent);
}

} // namespace fw_update

} // namespace pldm