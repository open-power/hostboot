#pragma once

#include "file_io_by_type.hpp"

#include <sys/mman.h>

#include <unordered_map>

namespace pldm
{
namespace responder
{
/* Topology enum definitions*/

extern std::unordered_map<uint8_t, std::string> linkStateMap;
extern std::unordered_map<uint8_t, std::string> linkSpeed;
extern std::unordered_map<uint8_t, size_t> linkWidth;

enum class linkTypeData : uint8_t
{
    Primary = 0x0,
    Secondary = 0x1,
    OpenCAPI = 0x2,
    Unknown = 0xFF
};

struct slotLocCode
{
    uint8_t numSlotLocCodes;
    uint8_t slotLocCodesCmnPrtSize;
    uint8_t slotLocCodesCmnPrt[1];
} __attribute__((packed));

struct slotLocCodeSuf
{
    uint8_t slotLocCodeSz;
    uint8_t slotLocCodeSuf[1];
} __attribute__((packed));

struct pcieLinkEntry
{
    uint16_t entryLength;
    uint8_t version;
    uint8_t reserved1;
    uint16_t linkId;
    uint16_t parentLinkId;
    uint32_t linkDrcIndex;
    uint32_t hubDrcIndex;
    uint8_t linkStatus;
    pldm::responder::linkTypeData linkType;
    uint16_t reserved2;
    uint8_t linkSpeed;
    uint8_t linkWidth;
    uint8_t pcieHostBridgeLocCodeSize;
    uint16_t pcieHostBridgeLocCodeOff;
    uint8_t topLocalPortLocCodeSize;
    uint16_t topLocalPortLocCodeOff;
    uint8_t bottomLocalPortLocCodeSize;
    uint16_t bottomLocalPortLocCodeOff;
    uint8_t topRemotePortLocCodeSize;
    uint16_t topRemotePortLocCodeOff;
    uint8_t bottomRemotePortLocCodeSize;
    uint16_t bottomRemotePortLocCodeOff;
    uint16_t slotLocCodesOffset;
    uint8_t pciLinkEntryLocCode[1];
} __attribute__((packed));

struct topologyBlob
{
    uint32_t totalDataSize;
    int16_t numPcieLinkEntries;
    uint16_t reserved;
    pcieLinkEntry pciLinkEntry[1];
} __attribute__((packed));

using LinkId = uint16_t;
using LinkStatus = std::string;
using LinkType = uint8_t;
using LinkSpeed = uint8_t;
using LinkWidth = int64_t;
using PcieHostBridgeLoc = std::string;
using LocalPortTop = std::string;
using LocalPortBot = std::string;
using LocalPort = std::pair<LocalPortTop, LocalPortBot>;
using RemotePortTop = std::string;
using RemotePortBot = std::string;
using RemotePort = std::pair<RemotePortTop, RemotePortBot>;
using IoSlotLocation = std::vector<std::string>;
using CableLinkNum = unsigned short int;
using LocalPortLocCode = std::string;
using IoSlotLocationCode = std::string;
using CablePartNum = std::string;
using CableLength = double;
using CableType = std::string;
using CableStatus = std::string;

/* Cable Attributes Info */

extern std::unordered_map<uint8_t, double> cableLengthMap;
extern std::unordered_map<uint8_t, std::string> cableTypeMap;
extern std::unordered_map<uint8_t, std::string> cableStatusMap;

struct pcieLinkCableAttr
{
    uint16_t entryLength;
    uint8_t version;
    uint8_t reserved1;
    uint16_t linkId;
    uint16_t reserved2;
    uint32_t linkDrcIndex;
    uint8_t cableLength;
    uint8_t cableType;
    uint8_t cableStatus;
    uint8_t hostPortLocationCodeSize;
    uint8_t ioEnclosurePortLocationCodeSize;
    uint8_t cablePartNumberSize;
    uint16_t hostPortLocationCodeOffset;
    uint16_t ioEnclosurePortLocationCodeOffset;
    uint16_t cablePartNumberOffset;
    uint8_t cableAttrLocCode[1];
};

struct cableAttributesList
{
    uint32_t lengthOfResponse;
    uint16_t numOfCables;
    uint16_t reserved;
    pcieLinkCableAttr pciLinkCableAttr[1];
};

/** @class PCIeInfoHandler
 *
 *  @brief Inherits and implements FileHandler. This class is used to handle the
 *  pcie topology file and cable information from remote PLDM terminus to the
 *  bmc
 */
class PCIeInfoHandler : public FileHandler
{
  public:
    /** @brief PCIeInfoHandler constructor
     */
    PCIeInfoHandler(uint32_t fileHandle, uint16_t fileType);

    virtual int writeFromMemory(uint32_t offset, uint32_t length,
                                uint64_t address,
                                oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int write(const char* buffer, uint32_t offset, uint32_t& length,
                      oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int fileAck(uint8_t fileStatus);

    virtual int readIntoMemory(uint32_t /*offset*/, uint32_t /*length*/,
                               uint64_t /*address*/,
                               oem_platform::Handler* /*oemPlatformHandler*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int read(uint32_t /*offset*/, uint32_t& /*length*/,
                     Response& /*response*/,
                     oem_platform::Handler* /*oemPlatformHandler*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int newFileAvailable(uint64_t /*length*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int fileAckWithMetaData(
        uint8_t /*fileStatus*/, uint32_t /*metaDataValue1*/,
        uint32_t /*metaDataValue2*/, uint32_t /*metaDataValue3*/,
        uint32_t /*metaDataValue4*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int newFileAvailableWithMetaData(
        uint64_t /*length*/, uint32_t /*metaDataValue1*/,
        uint32_t /*metaDataValue2*/, uint32_t /*metaDataValue3*/,
        uint32_t /*metaDataValue4*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    /** @brief method to parse the pcie topology information */
    virtual void parseTopologyData();

    /** @brief method to parse the cable information */
    virtual void parseCableInfo();

    /** @brief PCIeInfoHandler destructor
     */
    ~PCIeInfoHandler() {}

  private:
    uint16_t infoType; //!< type of the information

    /**
     * @brief Map contains Topology data
     *
     * This static unordered map associates link IDs with link attributes.
     * Key - LinkID (LinkId)
     * Value - Tuple
     *         link status (LinkStatus)
     *         link type (LinkType)
     *         link speed (LinkSpeed)
     *         link width (LinkWidth)
     *         PCIe host bridge location (PcieHostBridgeLoc)
     *         Local port (LocalPort - Pair of local port top and bottom)
     *         Remote port (RemotePort - Pair of remote port top and bottom)
     *         I/O slot location (IoSlotLocation - Vector of strings)
     */
    static std::unordered_map<
        LinkId, std::tuple<LinkStatus, linkTypeData, LinkSpeed, LinkWidth,
                           PcieHostBridgeLoc, LocalPort, RemotePort,
                           IoSlotLocation, LinkId>>
        topologyInformation;
    /**
     * @brief Static unordered map containing cable information.
     *
     * This map associates cable link numbers with a tuple containing various
     * cable attributes.
     *
     * Key - CableLinkID (CableLinkNum)
     * Value - Tuple
     *         Link ID (LinkId)
     *         Local port location code (LocalPortLocCode)
     *         I/O slot location code (IoSlotLocationCode)
     *         Cable part number (CablePartNum)
     *         Cable length (CableLength)
     *         Cable type (CableType)
     *         Cable status (CableStatus)
     */

    static std::unordered_map<
        CableLinkNum,
        std::tuple<LinkId, LocalPortLocCode, IoSlotLocationCode, CablePartNum,
                   CableLength, CableType, CableStatus>>
        cableInformation;
    /**
     * @brief Static unordered map containing linkId to link type information.
     *
     * This map associates link numbers to the link type
     *
     * Key - LinkID (LinkId)
     * Value - linkTypeData (linkTypeData)
     */
    static std::unordered_map<LinkId, linkTypeData> linkTypeInfo;

    /** @brief A static unordered map storing information about received files.
     *
     *  This unordered map associates file type with a boolean value indicating
     *  whether the file of that type has been received or not.
     */
    static std::unordered_map<uint16_t, bool> receivedFiles;
};

} // namespace responder
} // namespace pldm
