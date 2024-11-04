#pragma once

#include "common/utils.hpp"
#include "libpldmresponder/fru.hpp"
#include "libpldmresponder/oem_handler.hpp"
#include "oem/ibm/libpldmresponder/utils.hpp"

#include <libpldm/oem/ibm/fru.h>

namespace pldm
{
namespace responder
{
using ObjectPath = std::string;
using AssociatedEntityMap = std::map<ObjectPath, pldm_entity>;

namespace oem_ibm_fru
{

// structure of the PCIE config space data
struct PcieConfigSpaceData
{
    uint16_t vendorId;
    uint16_t deviceId;
    uint32_t first_reserved;
    uint8_t revisionId;
    std::array<uint8_t, 3> classCode;
    uint32_t second_reserved[8];
    uint16_t subSystemVendorId;
    uint16_t subSystemId;
    uint32_t last_reserved[4];

} __attribute__((packed));

class Handler : public oem_fru::Handler
{
  public:
    Handler(pldm_pdr* repo) : pdrRepo(repo) {}

    /** @brief Method to set the fru handler in the
     *    oem_ibm_handler class
     *
     *  @param[in] handler - pointer to PLDM platform handler
     */
    void setIBMFruHandler(pldm::responder::fru::Handler* handler);

    /** @brief Process OEM FRU table
     *
     *  @param[in] fruData - the data of the fru records
     *
     *  @return success or failure
     */
    int processOEMFRUTable(const std::vector<uint8_t>& fruData);

    virtual const AssociatedEntityMap& getAssociateEntityMap()
    {
        return fruHandler->getAssociateEntityMap();
    }

    ~Handler() = default;

  private:
    /** @brief pointer to BMC's primary PDR repo */
    const pldm_pdr* pdrRepo;

    pldm::responder::fru::Handler* fruHandler; //!< pointer to PLDM fru handler

    /** @brief update the DBus property
     *
     *  @param[in] fruRSI - fru record set identifier
     *  @param[in] fruAssociationMap - the dbus path to pldm entity stored while
     *                                 creating the pldm fru records
     *  @param[in] vendorId - the vendor ID
     *  @param[in] deviceId - the device ID
     *  @param[in] revisionId - the revision ID
     *  @param[in] classCode - the class Code
     *  @param[in] subSystemVendorId - the subSystemVendor ID
     *  @param[in] subSystemId - the subSystem ID
     */
    void updateDBusProperty(
        uint16_t fruRSI, const AssociatedEntityMap& fruAssociationMap,
        const std::string& vendorId, const std::string& deviceId,
        const std::string& revisionId, const std::string& classCode,
        const std::string& subSystemVendorId, const std::string& subSystemId);

    /** @brief DBus Map update
     *
     *  @param[in] adapterObjectPath - the fru object path
     *  @param[in] propertyName - the fru property name
     *  @param[in] propValue - the fru property value
     */
    void dbus_map_update(const std::string& adapterObjectPath,
                         const std::string& propertyName,
                         const std::string& propValue);

    /** @brief setting firmware UAK (Update Access Key)
     *
     *  @param[in] data - value to be set
     */
    void setFirmwareUAK(const std::vector<uint8_t>& data);
};

} // namespace oem_ibm_fru
} // namespace responder
} // namespace pldm
