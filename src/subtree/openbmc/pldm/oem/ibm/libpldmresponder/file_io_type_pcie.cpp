#include "file_io_type_pcie.hpp"

#include <libpldm/base.h>
#include <libpldm/oem/ibm/file_io.h>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace responder
{

std::unordered_map<uint8_t, std::string> linkStateMap{
    {0x00, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Operational"},
    {0x01, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Degraded"},
    {0x02, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Unused"},
    {0x03, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Unused"},
    {0x04, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Failed"},
    {0x05, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Open"},
    {0x06, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Inactive"},
    {0x07, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Unused"},
    {0xFF, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Status.Unknown"}};

std::unordered_map<uint8_t, std::string> linkSpeed{
    {0x00, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen1"},
    {0x01, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen2"},
    {0x02, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen3"},
    {0x03, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen4"},
    {0x04, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Gen5"},
    {0x10, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Unknown"},
    {0xFF, "xyz.openbmc_project.Inventory.Item.PCIeSlot.Generations.Unknown"}};

std::unordered_map<uint8_t, size_t> linkWidth{
    {0x01, 1},  {0x02, 2},        {0x04, 4}, {0x08, 8},
    {0x10, 16}, {0xFF, UINT_MAX}, {0x00, 0}};

std::unordered_map<uint8_t, double> cableLengthMap{
    {0x00, 0},  {0x01, 2},  {0x02, 3},
    {0x03, 10}, {0x04, 20}, {0xFF, std::numeric_limits<double>::quiet_NaN()}};

std::unordered_map<uint8_t, std::string> cableTypeMap{
    {0x00, "optical"}, {0x01, "copper"}, {0xFF, "Unknown"}};

std::unordered_map<uint8_t, std::string> cableStatusMap{
    {0x00, "xyz.openbmc_project.Inventory.Item.Cable.Status.Inactive"},
    {0x01, "xyz.openbmc_project.Inventory.Item.Cable.Status.Running"},
    {0x02, "xyz.openbmc_project.Inventory.Item.Cable.Status.PoweredOff"},
    {0xFF, "xyz.openbmc_project.Inventory.Item.Cable.Status.Unknown"}};

static constexpr auto pciePath = "/var/lib/pldm/pcie-topology/";
constexpr auto topologyFile = "topology";
constexpr auto cableInfoFile = "cableinfo";

// Slot location code structure contains multiple slot location code
// suffix structures.
// Each slot location code suffix structure is as follows
// {Slot location code suffix size(uint8_t),
//  Slot location code suffix(variable size)}
constexpr auto sizeOfSuffixSizeDataMember = 1;

// Each slot location structure contains
// {
//   Number of slot location codes (1byte),
//   Slot location code Common part size (1byte)
//   Slot location common part (Var)
// }
constexpr auto slotLocationDataMemberSize = 2;

namespace fs = std::filesystem;

std::unordered_map<uint16_t, bool> PCIeInfoHandler::receivedFiles;
std::unordered_map<LinkId, std::tuple<LinkStatus, linkTypeData, LinkSpeed,
                                      LinkWidth, PcieHostBridgeLoc, LocalPort,
                                      RemotePort, IoSlotLocation, LinkId>>
    PCIeInfoHandler::topologyInformation;
std::unordered_map<
    CableLinkNum, std::tuple<LinkId, LocalPortLocCode, IoSlotLocationCode,
                             CablePartNum, CableLength, CableType, CableStatus>>
    PCIeInfoHandler::cableInformation;
std::unordered_map<LinkId, linkTypeData> PCIeInfoHandler::linkTypeInfo;

PCIeInfoHandler::PCIeInfoHandler(uint32_t fileHandle, uint16_t fileType) :
    FileHandler(fileHandle), infoType(fileType)
{
    receivedFiles.emplace(infoType, false);
}

int PCIeInfoHandler::writeFromMemory(
    uint32_t offset, uint32_t length, uint64_t address,
    oem_platform::Handler* /*oemPlatformHandler*/)
{
    if (!fs::exists(pciePath))
    {
        fs::create_directories(pciePath);
        fs::permissions(pciePath,
                        fs::perms::others_read | fs::perms::owner_write);
    }

    fs::path infoFile(fs::path(pciePath) / topologyFile);
    if (infoType == PLDM_FILE_TYPE_CABLE_INFO)
    {
        infoFile = (fs::path(pciePath) / cableInfoFile);
    }

    try
    {
        std::ofstream pcieData(infoFile, std::ios::out | std::ios::binary);
        auto rc = transferFileData(infoFile, false, offset, length, address);
        if (rc != PLDM_SUCCESS)
        {
            error("TransferFileData failed in PCIeTopology with error {ERROR}",
                  "ERROR", rc);
            return rc;
        }
        return PLDM_SUCCESS;
    }
    catch (const std::exception& e)
    {
        error("Create/Write data to the File type {TYPE}, failed {ERROR}",
              "TYPE", infoType, "ERROR", e);
        return PLDM_ERROR;
    }
}

int PCIeInfoHandler::write(const char* buffer, uint32_t, uint32_t& length,
                           oem_platform::Handler* /*oemPlatformHandler*/)
{
    fs::path infoFile(fs::path(pciePath) / topologyFile);
    if (infoType == PLDM_FILE_TYPE_CABLE_INFO)
    {
        infoFile = (fs::path(pciePath) / cableInfoFile);
    }

    try
    {
        std::ofstream pcieData(infoFile, std::ios::out | std::ios::binary |
                                             std::ios::app);

        if (!buffer)
        {
            pcieData.write(buffer, length);
        }
        pcieData.close();
    }
    catch (const std::exception& e)
    {
        error("Create/Write data to the File type {TYPE}, failed {ERROR}",
              "TYPE", infoType, "ERROR", e);
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

int PCIeInfoHandler::fileAck(uint8_t /*fileStatus*/)
{
    receivedFiles[infoType] = true;
    try
    {
        if (receivedFiles.at(PLDM_FILE_TYPE_CABLE_INFO) &&
            receivedFiles.at(PLDM_FILE_TYPE_PCIE_TOPOLOGY))
        {
            receivedFiles.clear();
            // parse the topology data and cache the information
            // for further processing
            parseTopologyData();
        }
    }
    catch (const std::out_of_range& e)
    {
        info("Received only one of the topology file");
    }
    return PLDM_SUCCESS;
}

void PCIeInfoHandler::parseTopologyData()
{
    int fd = open((fs::path(pciePath) / topologyFile).string().c_str(),
                  O_RDONLY, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Topology file not present");
        return;
    }
    pldm::utils::CustomFD topologyFd(fd);
    // Reading the statistics of the topology file, to get the size.
    // stat sb is the out parameter provided to fstat
    struct stat sb;
    if (fstat(fd, &sb) == -1)
    {
        perror("Could not get topology file size");
        return;
    }

    if (sb.st_size == 0)
    {
        error("Topology file Size is 0");
        return;
    }

    auto topologyCleanup = [sb](void* fileInMemory) {
        munmap(fileInMemory, sb.st_size);
    };

    // memory map the topology file into pldm memory
    void* fileInMemory =
        mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, topologyFd(), 0);
    if (MAP_FAILED == fileInMemory)
    {
        error("mmap on topology file failed with error {RC}", "RC", -errno);
        return;
    }

    std::unique_ptr<void, decltype(topologyCleanup)> topologyPtr(
        fileInMemory, topologyCleanup);

    auto pcieLinkList = reinterpret_cast<struct topologyBlob*>(fileInMemory);
    uint16_t numOfLinks = 0;
    if (!pcieLinkList)
    {
        error("Parsing of topology file failed : pcieLinkList is null");
        return;
    }

    // The elements in the structure that were being parsed from the obtained
    // files via write() and writeFromMemory() were written by IBM enterprise
    // host firmware which runs on big-endian format. The DMA engine in BMC
    // (aspeed-xdma device driver) which is responsible for exposing the data
    // shared by the host in the shared VGA memory has no idea of the structure
    // of the data it's copying from host. So it's up to the consumers of the
    // data to deal with the endianness once it has been copied to user space &
    // and as pldm is the first application layer that interprets the data
    // provided by host reading from the sysfs interface of xdma-engine & also
    // since pldm application runs on BMC which could be little/big endian, its
    // essential to swap the endianness to agreed big-endian format (htobe)
    // before using the data.

    numOfLinks = htobe16(pcieLinkList->numPcieLinkEntries);

    // To fetch the PCIe link from the topology data, moving the pointer
    // by 8 bytes based on the size of other elements of the structure
    struct pcieLinkEntry* singleEntryData =
        reinterpret_cast<struct pcieLinkEntry*>(
            reinterpret_cast<uint8_t*>(pcieLinkList) + 8);

    if (!singleEntryData)
    {
        error("Parsing of topology file failed : single_link is null");
        return;
    }

    auto singleEntryDataCharStream = reinterpret_cast<char*>(singleEntryData);

    // iterate over every pcie link and get the link specific attributes
    for ([[maybe_unused]] const auto& link :
         std::views::iota(0) | std::views::take(numOfLinks))
    {
        // get the link id
        auto linkId = htobe16(singleEntryData->linkId);

        // get parent link id
        auto parentLinkId = htobe16(singleEntryData->parentLinkId);

        // get link status
        auto linkStatus = singleEntryData->linkStatus;

        // get link type
        auto type = singleEntryData->linkType;
        if (type != pldm::responder::linkTypeData::Unknown)
        {
            linkTypeInfo[linkId] = type;
        }

        // get link speed
        auto linkSpeed = singleEntryData->linkSpeed;

        // get link width
        auto width = singleEntryData->linkWidth;

        // get the PCIe Host Bridge Location
        size_t pcieLocCodeSize = singleEntryData->pcieHostBridgeLocCodeSize;
        std::vector<char> pcieHostBridgeLocation(
            singleEntryDataCharStream +
                htobe16(singleEntryData->pcieHostBridgeLocCodeOff),
            singleEntryDataCharStream +
                htobe16(singleEntryData->pcieHostBridgeLocCodeOff) +
                static_cast<int>(pcieLocCodeSize));
        std::string pcieHostBridgeLocationCode(pcieHostBridgeLocation.begin(),
                                               pcieHostBridgeLocation.end());

        // get the local port - top location
        size_t localTopPortLocSize = singleEntryData->topLocalPortLocCodeSize;
        std::vector<char> localTopPortLocation(
            singleEntryDataCharStream +
                htobe16(singleEntryData->topLocalPortLocCodeOff),
            singleEntryDataCharStream +
                htobe16(singleEntryData->topLocalPortLocCodeOff) +
                static_cast<int>(localTopPortLocSize));
        std::string localTopPortLocationCode(localTopPortLocation.begin(),
                                             localTopPortLocation.end());

        // get the local port - bottom location
        size_t localBottomPortLocSize =
            singleEntryData->bottomLocalPortLocCodeSize;
        std::vector<char> localBottomPortLocation(
            singleEntryDataCharStream +
                htobe16(singleEntryData->bottomLocalPortLocCodeOff),
            singleEntryDataCharStream +
                htobe16(singleEntryData->bottomLocalPortLocCodeOff) +
                static_cast<int>(localBottomPortLocSize));
        std::string localBottomPortLocationCode(localBottomPortLocation.begin(),
                                                localBottomPortLocation.end());

        // get the remote port - top location
        size_t remoteTopPortLocSize = singleEntryData->topRemotePortLocCodeSize;
        std::vector<char> remoteTopPortLocation(
            singleEntryDataCharStream +
                htobe16(singleEntryData->topRemotePortLocCodeOff),
            singleEntryDataCharStream +
                htobe16(singleEntryData->topRemotePortLocCodeOff) +
                static_cast<int>(remoteTopPortLocSize));
        std::string remoteTopPortLocationCode(remoteTopPortLocation.begin(),
                                              remoteTopPortLocation.end());

        // get the remote port - bottom location
        size_t remoteBottomLocSize =
            singleEntryData->bottomRemotePortLocCodeSize;
        std::vector<char> remoteBottomPortLocation(
            singleEntryDataCharStream +
                htobe16(singleEntryData->bottomRemotePortLocCodeOff),
            singleEntryDataCharStream +
                htobe16(singleEntryData->bottomRemotePortLocCodeOff) +
                static_cast<int>(remoteBottomLocSize));
        std::string remoteBottomPortLocationCode(
            remoteBottomPortLocation.begin(), remoteBottomPortLocation.end());

        struct slotLocCode* slotData = reinterpret_cast<struct slotLocCode*>(
            (reinterpret_cast<uint8_t*>(singleEntryData)) +
            htobe16(singleEntryData->slotLocCodesOffset));
        if (!slotData)
        {
            error("Parsing the topology file failed : slotData is null");
            return;
        }
        // get the Slot location code common part
        size_t numOfSlots = slotData->numSlotLocCodes;
        size_t slotLocCodeCompartSize = slotData->slotLocCodesCmnPrtSize;
        std::vector<char> slotLocation(
            reinterpret_cast<char*>(slotData->slotLocCodesCmnPrt),
            (reinterpret_cast<char*>(slotData->slotLocCodesCmnPrt) +
             static_cast<int>(slotLocCodeCompartSize)));
        std::string slotLocationCode(slotLocation.begin(), slotLocation.end());

        uint8_t* suffixData =
            reinterpret_cast<uint8_t*>(slotData) + slotLocationDataMemberSize +
            slotData->slotLocCodesCmnPrtSize;
        if (!suffixData)
        {
            error("slot location suffix data is nullptr");
            return;
        }

        // create the full slot location code by combining common part and
        // suffix part
        std::string slotSuffixLocationCode;
        std::vector<std::string> slotFinaLocationCode{};
        for ([[maybe_unused]] const auto& slot :
             std::views::iota(0) | std::views::take(numOfSlots))
        {
            struct slotLocCodeSuf* slotLocSufData =
                reinterpret_cast<struct slotLocCodeSuf*>(suffixData);
            if (!slotLocSufData)
            {
                error("slot location suffix data is nullptr");
                break;
            }

            size_t slotLocCodeSuffixSize = slotLocSufData->slotLocCodeSz;
            if (slotLocCodeSuffixSize > 0)
            {
                std::vector<char> slotSuffixLocation(
                    reinterpret_cast<char*>(slotLocSufData) + 1,
                    reinterpret_cast<char*>(slotLocSufData) + 1 +
                        static_cast<int>(slotLocCodeSuffixSize));
                std::string slotSuffLocationCode(slotSuffixLocation.begin(),
                                                 slotSuffixLocation.end());

                slotSuffixLocationCode = slotSuffLocationCode;
            }
            std::string slotFullLocationCode =
                slotLocationCode + slotSuffixLocationCode;
            slotFinaLocationCode.push_back(slotFullLocationCode);

            // move the pointer to next slot
            suffixData += sizeOfSuffixSizeDataMember + slotLocCodeSuffixSize;
        }

        // store the information into a map
        topologyInformation[linkId] = std::make_tuple(
            linkStateMap[linkStatus], type, linkSpeed, linkWidth[width],
            pcieHostBridgeLocationCode,
            std::make_pair(localTopPortLocationCode,
                           localBottomPortLocationCode),
            std::make_pair(remoteTopPortLocationCode,
                           remoteBottomPortLocationCode),
            slotFinaLocationCode, parentLinkId);

        // move the pointer to next link
        singleEntryData = reinterpret_cast<struct pcieLinkEntry*>(
            reinterpret_cast<uint8_t*>(singleEntryData) +
            htobe16(singleEntryData->entryLength));
    }
    // Need to call cable info at the end , because we dont want to parse
    // cable info without parsing the successful topology successfully
    // Having partial information is of no use.
    parseCableInfo();
}

void PCIeInfoHandler::parseCableInfo()
{
    int fd = open((fs::path(pciePath) / cableInfoFile).string().c_str(),
                  O_RDONLY, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("CableInfo file not present");
        return;
    }
    pldm::utils::CustomFD cableInfoFd(fd);
    struct stat sb;

    if (fstat(fd, &sb) == -1)
    {
        perror("Could not get cableinfo file size");
        return;
    }

    if (sb.st_size == 0)
    {
        error("Topology file Size is 0");
        return;
    }

    auto cableInfoCleanup = [sb](void* fileInMemory) {
        munmap(fileInMemory, sb.st_size);
    };

    void* fileInMemory =
        mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, cableInfoFd(), 0);

    if (MAP_FAILED == fileInMemory)
    {
        int rc = -errno;
        error("mmap on cable ifno file failed, RC={RC}", "RC", rc);
        return;
    }

    std::unique_ptr<void, decltype(cableInfoCleanup)> cablePtr(
        fileInMemory, cableInfoCleanup);

    auto cableList =
        reinterpret_cast<struct cableAttributesList*>(fileInMemory);

    // get number of cable links
    auto numOfCableLinks = htobe16(cableList->numOfCables);

    struct pcieLinkCableAttr* cableData =
        reinterpret_cast<struct pcieLinkCableAttr*>(
            (reinterpret_cast<uint8_t*>(cableList)) +
            (sizeof(struct cableAttributesList) - 1));

    if (!cableData)
    {
        error("Cable info parsing failed , cableData = nullptr");
        return;
    }

    // iterate over each pci cable link
    for (const auto& cable :
         std::views::iota(0) | std::views::take(numOfCableLinks))
    {
        // get the link id
        auto linkId = htobe16(cableData->linkId);
        char* cableDataPtr = reinterpret_cast<char*>(cableData);

        std::string localPortLocCode(
            cableDataPtr + htobe16(cableData->hostPortLocationCodeOffset),
            cableData->hostPortLocationCodeSize);

        std::string ioSlotLocationCode(
            cableDataPtr +
                htobe16(cableData->ioEnclosurePortLocationCodeOffset),
            cableData->ioEnclosurePortLocationCodeSize);

        std::string cablePartNum(
            cableDataPtr + htobe16(cableData->cablePartNumberOffset),
            cableData->cablePartNumberSize);

        // cache the data into a map
        cableInformation[cable] = std::make_tuple(
            linkId, localPortLocCode, ioSlotLocationCode, cablePartNum,
            cableLengthMap[cableData->cableLength],
            cableTypeMap[cableData->cableType],
            cableStatusMap[cableData->cableStatus]);
        // move the cable data pointer

        cableData = reinterpret_cast<struct pcieLinkCableAttr*>(
            (reinterpret_cast<uint8_t*>(cableData)) +
            htobe16(cableData->entryLength));
    }
}

} // namespace responder
} // namespace pldm
