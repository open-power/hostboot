#pragma once

#include "fru_parser.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "oem_handler.hpp"
#include "pldmd/handler.hpp"

#include <libpldm/fru.h>
#include <libpldm/pdr.h>

#include <sdbusplus/message.hpp>

#include <map>
#include <string>
#include <variant>
#include <vector>

namespace pldm
{

namespace responder
{

namespace dbus
{

using Value = std::variant<bool, uint8_t, int16_t, uint16_t, int32_t, uint32_t,
                           int64_t, uint64_t, double, std::string,
                           std::vector<uint8_t>, std::vector<std::string>>;
using PropertyMap = std::map<Property, Value>;
using InterfaceMap = std::map<Interface, PropertyMap>;
using ObjectValueTree = std::map<sdbusplus::message::object_path, InterfaceMap>;
using ObjectPath = std::string;
using AssociatedEntityMap = std::map<ObjectPath, pldm_entity>;

} // namespace dbus

/** @class FruImpl
 *
 *  @brief Builds the PLDM FRU table containing the FRU records
 */
class FruImpl
{
  public:
    /* @brief Header size for FRU record, it includes the FRU record set
     *        identifier, FRU record type, Number of FRU fields, Encoding type
     *        of FRU fields
     */
    static constexpr size_t recHeaderSize =
        sizeof(struct pldm_fru_record_data_format) -
        sizeof(struct pldm_fru_record_tlv);

    /** @brief Constructor for FruImpl, the configPath is consumed to build the
     *         FruParser object.
     *
     *  @param[in] configPath - path to the directory containing config files
     *                          for PLDM FRU
     *  @param[in] fruMasterJsonPath - path to the file containing the FRU D-Bus
     *                                 Lookup Map
     *  @param[in] pdrRepo - opaque pointer to PDR repository
     *  @param[in] entityTree - opaque pointer to the entity association tree
     *  @param[in] bmcEntityTree - opaque pointer to bmc's entity association
     *                             tree
     *  @param[in] oemFruHandler - OEM fru handler
     */
    FruImpl(const std::string& configPath,
            const std::filesystem::path& fruMasterJsonPath, pldm_pdr* pdrRepo,
            pldm_entity_association_tree* entityTree,
            pldm_entity_association_tree* bmcEntityTree) :
        parser(configPath, fruMasterJsonPath), pdrRepo(pdrRepo),
        entityTree(entityTree), bmcEntityTree(bmcEntityTree)
    {}

    /** @brief Total length of the FRU table in bytes, this includes the pad
     *         bytes and the checksum.
     *
     *  @return size of the FRU table
     */
    uint32_t size() const
    {
        return table.size();
    }

    /** @brief The checksum of the contents of the FRU table
     *
     *  @return checksum
     */
    uint32_t checkSum() const
    {
        return checksum;
    }

    /** @brief Number of record set identifiers in the FRU tables
     *
     *  @return number of record set identifiers
     */
    uint16_t numRSI() const
    {
        return rsi;
    }

    /** @brief The number of FRU records in the table
     *
     *  @return number of FRU records
     */
    uint16_t numRecords() const
    {
        return numRecs;
    }

    /** @brief Get the FRU table
     *
     *  @param[out] - Populate response with the FRU table
     */
    void getFRUTable(Response& response);

    /** @brief Get the Fru Table MetaData
     *
     */
    void getFRURecordTableMetadata();

    /** @brief Get FRU Record Table By Option
     *  @param[out] response - Populate response with the FRU table got by
     *                         options
     *  @param[in] fruTableHandle - The fru table handle
     *  @param[in] recordSetIdentifer - The record set identifier
     *  @param[in] recordType - The record type
     *  @param[in] fieldType - The field type
     */
    int getFRURecordByOption(Response& response, uint16_t fruTableHandle,
                             uint16_t recordSetIdentifer, uint8_t recordType,
                             uint8_t fieldType);

    /** @brief FRU table is built by processing the D-Bus inventory namespace
     *         based on the config files for FRU. The table is populated based
     *         on the isBuilt flag.
     */
    void buildFRUTable();

    /** @brief Get std::map associated with the entity
     *         key: object path
     *         value: pldm_entity
     *
     *  @return std::map<ObjectPath, pldm_entity>
     */
    inline const pldm::responder::dbus::AssociatedEntityMap&
        getAssociateEntityMap() const
    {
        return associatedEntityMap;
    }

    /** @brief Get pldm entity by the object path
     *
     *  @param[in] intfMaps - D-Bus interfaces and the associated property
     *                        values for the FRU
     *
     *  @return pldm_entity
     */
    std::optional<pldm_entity>
        getEntityByObjectPath(const dbus::InterfaceMap& intfMaps);

    /** @brief Update pldm entity to association tree
     *
     *  @param[in] objects - std::map The object value tree
     *  @param[in] path    - Object path
     *
     *  Ex: Input path =
     *  "/xyz/openbmc_project/inventory/system/chassis/motherboard/powersupply0"
     *
     *  Get the parent class in turn and store it in a temporary vector
     *
     *  Output tmpObjPaths = {
     *  "/xyz/openbmc_project/inventory/system",
     *  "/xyz/openbmc_project/inventory/system/chassis/",
     *  "/xyz/openbmc_project/inventory/system/chassis/motherboard",
     *  "/xyz/openbmc_project/inventory/system/chassis/motherboard/powersupply0"}
     *
     */
    void updateAssociationTree(const dbus::ObjectValueTree& objects,
                               const std::string& path);

    /* @brief Method to populate the firmware version ID
     *
     * @return firmware version ID
     */
    std::string populatefwVersion();

    /* @brief Method to resize the table
     *
     * @return resized table
     */
    std::vector<uint8_t> tableResize();

    /* @brief set FRU Record Table
     *
     * @param[in] fruData - the data of the fru
     *
     * @return PLDM completion code
     */
    int setFRUTable(const std::vector<uint8_t>& fruData);

    /* @brief Method to set the oem platform handler in fru handler class
     *
     * @param[in] handler - oem fru handler
     */
    inline void setOemFruHandler(pldm::responder::oem_fru::Handler* handler)
    {
        oemFruHandler = handler;
    }

  private:
    uint16_t nextRSI()
    {
        return ++rsi;
    }

    uint32_t nextRecordHandle()
    {
        return ++rh;
    }

    uint32_t rh = 0;
    uint16_t rsi = 0;
    uint16_t numRecs = 0;
    uint8_t padBytes = 0;
    std::vector<uint8_t> table;
    uint32_t checksum = 0;
    bool isBuilt = false;

    fru_parser::FruParser parser;
    pldm_pdr* pdrRepo;
    pldm_entity_association_tree* entityTree;
    pldm_entity_association_tree* bmcEntityTree;
    pldm::responder::oem_fru::Handler* oemFruHandler = nullptr;
    dbus::ObjectValueTree objects;

    std::map<dbus::ObjectPath, pldm_entity_node*> objToEntityNode{};

    /** @brief populateRecord builds the FRU records for an instance of FRU and
     *         updates the FRU table with the FRU records.
     *
     *  @param[in] interfaces - D-Bus interfaces and the associated property
     *                          values for the FRU
     *  @param[in] recordInfos - FRU record info to build the FRU records
     *  @param[in/out] entity - PLDM entity corresponding to FRU instance
     */
    void populateRecords(const dbus::InterfaceMap& interfaces,
                         const fru_parser::FruRecordInfos& recordInfos,
                         const pldm_entity& entity);

    /** @brief Associate sensor/effecter to FRU entity
     */
    dbus::AssociatedEntityMap associatedEntityMap;
};

namespace fru
{

class Handler : public CmdHandler
{
  public:
    Handler(const std::string& configPath,
            const std::filesystem::path& fruMasterJsonPath, pldm_pdr* pdrRepo,
            pldm_entity_association_tree* entityTree,
            pldm_entity_association_tree* bmcEntityTree) :
        impl(configPath, fruMasterJsonPath, pdrRepo, entityTree, bmcEntityTree)
    {
        handlers.emplace(
            PLDM_GET_FRU_RECORD_TABLE_METADATA,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getFRURecordTableMetadata(request, payloadLength);
            });
        handlers.emplace(
            PLDM_GET_FRU_RECORD_TABLE,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getFRURecordTable(request, payloadLength);
            });
        handlers.emplace(
            PLDM_GET_FRU_RECORD_BY_OPTION,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getFRURecordByOption(request, payloadLength);
            });
        handlers.emplace(
            PLDM_SET_FRU_RECORD_TABLE,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->setFRURecordTable(request, payloadLength);
            });
    }

    /** @brief Handler for Get FRURecordTableMetadata
     *
     *  @param[in] request - Request message payload
     *  @param[in] payloadLength - Request payload length
     *
     *  @return PLDM response message
     */
    Response getFRURecordTableMetadata(const pldm_msg* request,
                                       size_t payloadLength);

    /** @brief Handler for GetFRURecordTable
     *
     *  @param[in] request - Request message payload
     *  @param[in] payloadLength - Request payload length
     *
     *  @return PLDM response message
     */
    Response getFRURecordTable(const pldm_msg* request, size_t payloadLength);

    /** @brief Build FRU table is bnot already built
     *
     */
    void buildFRUTable()
    {
        impl.buildFRUTable();
    }

    /** @brief Get std::map associated with the entity
     *         key: object path
     *         value: pldm_entity
     *
     *  @return std::map<ObjectPath, pldm_entity>
     */
    const pldm::responder::dbus::AssociatedEntityMap&
        getAssociateEntityMap() const
    {
        return impl.getAssociateEntityMap();
    }

    /** @brief Handler for GetFRURecordByOption
     *
     *  @param[in] request - Request message payload
     *  @param[in] payloadLength - Request payload length
     *
     *  @return PLDM response message
     */
    Response getFRURecordByOption(const pldm_msg* request,
                                  size_t payloadLength);

    /** @brief Handler for SetFRURecordTable
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *
     *  @return PLDM response message
     */
    Response setFRURecordTable(const pldm_msg* request, size_t payloadLength);

    /* @brief Method to set the oem platform handler in fru handler class
     *
     * @param[in] handler - oem fru handler
     */
    void setOemFruHandler(pldm::responder::oem_fru::Handler* handler)
    {
        impl.setOemFruHandler(handler);
    }

    using Table = std::vector<uint8_t>;

  private:
    FruImpl impl;
};

} // namespace fru

} // namespace responder

} // namespace pldm
