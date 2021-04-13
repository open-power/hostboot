#pragma once

#include "config.h"

#include "libpldm/platform.h"
#include "libpldm/states.h"
#include "pdr.h"

#include "common/utils.hpp"
#include "event_parser.hpp"
#include "fru.hpp"
#include "host-bmc/dbus_to_event_handler.hpp"
#include "host-bmc/host_pdr_handler.hpp"
#include "libpldmresponder/pdr.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "oem_handler.hpp"
#include "pldmd/handler.hpp"

#include <stdint.h>

#include <map>

namespace pldm
{
namespace responder
{
namespace platform
{

using namespace pldm::utils;
using namespace pldm::responder::pdr_utils;
using namespace pldm::state_sensor;

using generatePDR =
    std::function<void(const pldm::utils::DBusHandler& dBusIntf,
                       const Json& json, pdr_utils::RepoInterface& repo)>;

using EffecterId = uint16_t;
using DbusObjMaps =
    std::map<EffecterId,
             std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps>>;
using DbusPath = std::string;
using EffecterObjs = std::vector<DbusPath>;
using EventType = uint8_t;
using EventHandler = std::function<int(
    const pldm_msg* request, size_t payloadLength, uint8_t formatVersion,
    uint8_t tid, size_t eventDataOffset)>;
using EventHandlers = std::vector<EventHandler>;
using EventMap = std::map<EventType, EventHandlers>;
using AssociatedEntityMap = std::map<DbusPath, pldm_entity>;

class Handler : public CmdHandler
{
  public:
    Handler(const pldm::utils::DBusHandler* dBusIntf,
            const std::string& pdrJsonsDir, pldm_pdr* repo,
            HostPDRHandler* hostPDRHandler,
            DbusToPLDMEvent* dbusToPLDMEventHandler, fru::Handler* fruHandler,
            pldm::responder::oem_platform::Handler* oemPlatformHandler,
            sdeventplus::Event& event, bool buildPDRLazily = false,
            const std::optional<EventMap>& addOnHandlersMap = std::nullopt) :
        pdrRepo(repo),
        hostPDRHandler(hostPDRHandler),
        dbusToPLDMEventHandler(dbusToPLDMEventHandler), fruHandler(fruHandler),
        dBusIntf(dBusIntf), oemPlatformHandler(oemPlatformHandler),
        event(event), pdrJsonsDir(pdrJsonsDir), pdrCreated(false)
    {
        if (!buildPDRLazily)
        {
            generateTerminusLocatorPDR(pdrRepo);
            generate(*dBusIntf, pdrJsonsDir, pdrRepo);
            pdrCreated = true;
        }

        handlers.emplace(PLDM_GET_PDR,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getPDR(request, payloadLength);
                         });
        handlers.emplace(PLDM_SET_NUMERIC_EFFECTER_VALUE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->setNumericEffecterValue(
                                 request, payloadLength);
                         });
        handlers.emplace(PLDM_SET_STATE_EFFECTER_STATES,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->setStateEffecterStates(request,
                                                                 payloadLength);
                         });
        handlers.emplace(PLDM_PLATFORM_EVENT_MESSAGE,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->platformEventMessage(request,
                                                               payloadLength);
                         });
        handlers.emplace(PLDM_GET_STATE_SENSOR_READINGS,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getStateSensorReadings(request,
                                                                 payloadLength);
                         });

        // Default handler for PLDM Events
        eventHandlers[PLDM_SENSOR_EVENT].emplace_back(
            [this](const pldm_msg* request, size_t payloadLength,
                   uint8_t formatVersion, uint8_t tid, size_t eventDataOffset) {
                return this->sensorEvent(request, payloadLength, formatVersion,
                                         tid, eventDataOffset);
            });
        eventHandlers[PLDM_PDR_REPOSITORY_CHG_EVENT].emplace_back(
            [this](const pldm_msg* request, size_t payloadLength,
                   uint8_t formatVersion, uint8_t tid, size_t eventDataOffset) {
                return this->pldmPDRRepositoryChgEvent(request, payloadLength,
                                                       formatVersion, tid,
                                                       eventDataOffset);
            });

        // Additional OEM event handlers for PLDM events, append it to the
        // standard handlers
        if (addOnHandlersMap)
        {
            auto addOnHandlers = addOnHandlersMap.value();
            for (EventMap::iterator iter = addOnHandlers.begin();
                 iter != addOnHandlers.end(); ++iter)
            {
                auto search = eventHandlers.find(iter->first);
                if (search != eventHandlers.end())
                {
                    search->second.insert(std::end(search->second),
                                          std::begin(iter->second),
                                          std::end(iter->second));
                }
                else
                {
                    eventHandlers.emplace(iter->first, iter->second);
                }
            }
        }
    }

    pdr_utils::Repo& getRepo()
    {
        return this->pdrRepo;
    }

    /** @brief Add D-Bus mapping and value mapping(stateId to D-Bus) for the
     *         Id. If the same id is added, the previous dbusObjs will
     *         be "over-written".
     *
     *  @param[in] Id - effecter/sensor id
     *  @param[in] dbusObj - list of D-Bus object structure and list of D-Bus
     *                       property value to attribute value
     *  @param[in] typeId - the type id of enum
     */
    void addDbusObjMaps(
        uint16_t id,
        std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps> dbusObj,
        TypeId typeId = TypeId::PLDM_EFFECTER_ID);

    /** @brief Retrieve an id -> D-Bus objects mapping
     *
     *  @param[in] Id - id
     *  @param[in] typeId - the type id of enum
     *
     *  @return std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps> -
     *          list of D-Bus object structure and list of D-Bus property value
     *          to attribute value
     */
    const std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps>&
        getDbusObjMaps(uint16_t id,
                       TypeId typeId = TypeId::PLDM_EFFECTER_ID) const;

    uint16_t getNextEffecterId()
    {
        return ++nextEffecterId;
    }

    uint16_t getNextSensorId()
    {
        return ++nextSensorId;
    }

    /** @brief Parse PDR JSONs and build PDR repository
     *
     *  @param[in] dBusIntf - The interface object
     *  @param[in] dir - directory housing platform specific PDR JSON files
     *  @param[in] repo - instance of concrete implementation of Repo
     */
    void generate(const pldm::utils::DBusHandler& dBusIntf,
                  const std::string& dir, Repo& repo);

    /** @brief Parse PDR JSONs and build state effecter PDR repository
     *
     *  @param[in] json - platform specific PDR JSON files
     *  @param[in] repo - instance of state effecter implementation of Repo
     */
    void generateStateEffecterRepo(const Json& json, Repo& repo);

    /** @brief map of PLDM event type to EventHandlers
     *
     */
    EventMap eventHandlers;

    /** @brief Handler for GetPDR
     *
     *  @param[in] request - Request message payload
     *  @param[in] payloadLength - Request payload length
     *  @param[out] Response - Response message written here
     */
    Response getPDR(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for setNumericEffecterValue
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @return Response - PLDM Response message
     */
    Response setNumericEffecterValue(const pldm_msg* request,
                                     size_t payloadLength);

    /** @brief Handler for getStateSensorReadings
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @return Response - PLDM Response message
     */
    Response getStateSensorReadings(const pldm_msg* request,
                                    size_t payloadLength);

    /** @brief Handler for setStateEffecterStates
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @return Response - PLDM Response message
     */
    Response setStateEffecterStates(const pldm_msg* request,
                                    size_t payloadLength);

    /** @brief Handler for PlatformEventMessage
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @return Response - PLDM Response message
     */
    Response platformEventMessage(const pldm_msg* request,
                                  size_t payloadLength);

    /** @brief Handler for event class Sensor event
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @param[in] formatVersion - Version of the event format
     *  @param[in] tid - Terminus ID of the event's originator
     *  @param[in] eventDataOffset - Offset of the event data in the request
     *                               message
     *  @return PLDM completion code
     */
    int sensorEvent(const pldm_msg* request, size_t payloadLength,
                    uint8_t formatVersion, uint8_t tid, size_t eventDataOffset);

    /** @brief Handler for pldmPDRRepositoryChgEvent
     *
     *  @param[in] request - Request message
     *  @param[in] payloadLength - Request payload length
     *  @param[in] formatVersion - Version of the event format
     *  @param[in] tid - Terminus ID of the event's originator
     *  @param[in] eventDataOffset - Offset of the event data in the request
     *                               message
     *  @return PLDM completion code
     */
    int pldmPDRRepositoryChgEvent(const pldm_msg* request, size_t payloadLength,
                                  uint8_t formatVersion, uint8_t tid,
                                  size_t eventDataOffset);

    /** @brief Handler for extracting the PDR handles from changeEntries
     *
     *  @param[in] changeEntryData - ChangeEntry data from changeRecord
     *  @param[in] changeEntryDataSize - total size of changeEntryData
     *  @param[in] numberOfChangeEntries - total number of changeEntries to
     *                                     extract
     *  @param[out] pdrRecordHandles - std::vector where the extracted PDR
     *                                 handles are placed
     *  @return PLDM completion code
     */
    int getPDRRecordHandles(const ChangeEntry* changeEntryData,
                            size_t changeEntryDataSize,
                            size_t numberOfChangeEntries,
                            PDRRecordHandles& pdrRecordHandles);

    /** @brief Function to set the effecter requested by pldm requester
     *  @param[in] dBusIntf - The interface object
     *  @param[in] effecterId - Effecter ID sent by the requester to act on
     *  @param[in] stateField - The state field data for each of the states,
     * equal to composite effecter count in number
     *  @return - Success or failure in setting the states. Returns failure in
     * terms of PLDM completion codes if atleast one state fails to be set
     */
    template <class DBusInterface>
    int setStateEffecterStatesHandler(
        const DBusInterface& dBusIntf, uint16_t effecterId,
        const std::vector<set_effecter_state_field>& stateField)
    {
        using namespace pldm::responder::pdr;
        using namespace pldm::utils;
        using StateSetNum = uint8_t;

        state_effecter_possible_states* states = nullptr;
        pldm_state_effecter_pdr* pdr = nullptr;
        uint8_t compEffecterCnt = stateField.size();

        std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)>
            stateEffecterPdrRepo(pldm_pdr_init(), pldm_pdr_destroy);
        Repo stateEffecterPDRs(stateEffecterPdrRepo.get());
        getRepoByType(pdrRepo, stateEffecterPDRs, PLDM_STATE_EFFECTER_PDR);
        if (stateEffecterPDRs.empty())
        {
            std::cerr << "Failed to get record by PDR type\n";
            return PLDM_PLATFORM_INVALID_EFFECTER_ID;
        }

        PdrEntry pdrEntry{};
        auto pdrRecord = stateEffecterPDRs.getFirstRecord(pdrEntry);
        while (pdrRecord)
        {
            pdr = reinterpret_cast<pldm_state_effecter_pdr*>(pdrEntry.data);
            if (pdr->effecter_id != effecterId)
            {
                pdr = nullptr;
                pdrRecord =
                    stateEffecterPDRs.getNextRecord(pdrRecord, pdrEntry);
                continue;
            }

            states = reinterpret_cast<state_effecter_possible_states*>(
                pdr->possible_states);
            if (compEffecterCnt > pdr->composite_effecter_count)
            {
                std::cerr << "The requester sent wrong composite effecter"
                          << " count for the effecter, EFFECTER_ID="
                          << effecterId << "COMP_EFF_CNT=" << compEffecterCnt
                          << "\n";
                return PLDM_ERROR_INVALID_DATA;
            }
            break;
        }

        if (!pdr)
        {
            return PLDM_PLATFORM_INVALID_EFFECTER_ID;
        }

        int rc = PLDM_SUCCESS;
        try
        {
            const auto& [dbusMappings, dbusValMaps] =
                effecterDbusObjMaps.at(effecterId);
            for (uint8_t currState = 0; currState < compEffecterCnt;
                 ++currState)
            {
                std::vector<StateSetNum> allowed{};
                // computation is based on table 79 from DSP0248 v1.1.1
                uint8_t bitfieldIndex =
                    stateField[currState].effecter_state / 8;
                uint8_t bit =
                    stateField[currState].effecter_state - (8 * bitfieldIndex);
                if (states->possible_states_size < bitfieldIndex ||
                    !(states->states[bitfieldIndex].byte & (1 << bit)))
                {
                    std::cerr
                        << "Invalid state set value, EFFECTER_ID=" << effecterId
                        << " VALUE=" << stateField[currState].effecter_state
                        << " COMPOSITE_EFFECTER_ID=" << currState
                        << " DBUS_PATH=" << dbusMappings[currState].objectPath
                        << "\n";
                    rc = PLDM_PLATFORM_SET_EFFECTER_UNSUPPORTED_SENSORSTATE;
                    break;
                }
                const DBusMapping& dbusMapping = dbusMappings[currState];
                const StatestoDbusVal& dbusValToMap = dbusValMaps[currState];

                if (stateField[currState].set_request == PLDM_REQUEST_SET)
                {
                    try
                    {
                        dBusIntf.setDbusProperty(
                            dbusMapping,
                            dbusValToMap.at(
                                stateField[currState].effecter_state));
                    }
                    catch (const std::exception& e)
                    {
                        std::cerr
                            << "Error setting property, ERROR=" << e.what()
                            << " PROPERTY=" << dbusMapping.propertyName
                            << " INTERFACE="
                            << dbusMapping.interface << " PATH="
                            << dbusMapping.objectPath << "\n";
                        return PLDM_ERROR;
                    }
                }
                uint8_t* nextState =
                    reinterpret_cast<uint8_t*>(states) +
                    sizeof(state_effecter_possible_states) -
                    sizeof(states->states) +
                    (states->possible_states_size * sizeof(states->states));
                states = reinterpret_cast<state_effecter_possible_states*>(
                    nextState);
            }
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "the effecterId does not exist. effecter id: "
                      << effecterId << e.what() << '\n';
        }

        return rc;
    }

    /** @brief Build BMC Terminus Locator PDR
     *
     *  @param[in] repo - instance of concrete implementation of Repo
     */
    void generateTerminusLocatorPDR(Repo& repo);

    /** @brief Get std::map associated with the entity
     *         key: object path
     *         value: pldm_entity
     *
     *  @return std::map<ObjectPath, pldm_entity>
     */
    inline const AssociatedEntityMap& getAssociateEntityMap() const
    {
        if (fruHandler == nullptr)
        {
            throw InternalFailure();
        }
        return fruHandler->getAssociateEntityMap();
    }

    /** @brief process the actions that needs to be performed after a GetPDR
     *         call is received
     *  @param[in] source - sdeventplus event source
     */
    void _processPostGetPDRActions(sdeventplus::source::EventBase& source);

  private:
    pdr_utils::Repo pdrRepo;
    uint16_t nextEffecterId{};
    uint16_t nextSensorId{};
    DbusObjMaps effecterDbusObjMaps{};
    DbusObjMaps sensorDbusObjMaps{};
    HostPDRHandler* hostPDRHandler;
    DbusToPLDMEvent* dbusToPLDMEventHandler;
    fru::Handler* fruHandler;
    const pldm::utils::DBusHandler* dBusIntf;
    pldm::responder::oem_platform::Handler* oemPlatformHandler;
    sdeventplus::Event& event;
    std::string pdrJsonsDir;
    bool pdrCreated;
    std::unique_ptr<sdeventplus::source::Defer> deferredGetPDREvent;
};

/** @brief Function to check if a sensor falls in OEM range
 *         A sensor is considered to be oem if either of entity
 *         type or state set or both falls in oem range
 *
 *  @param[in] handler - the interface object
 *  @param[in] sensorId - sensor id
 *  @param[in] sensorRearmCount - sensor rearm count
 *  @param[out] compSensorCnt - composite sensor count
 *  @param[out] entityType - entity type
 *  @param[out] entityInstance - entity instance number
 *  @param[out] stateSetId - state set id
 *
 *  @return true if the sensor is OEM. All out parameters are invalid
 *               for a non OEM sensor
 */
bool isOemStateSensor(Handler& handler, uint16_t sensorId,
                      uint8_t sensorRearmCount, uint8_t& compSensorCnt,
                      uint16_t& entityType, uint16_t& entityInstance,
                      uint16_t& stateSetId);

/** @brief Function to check if an effecter falls in OEM range
 *         An effecter is considered to be oem if either of entity
 *         type or state set or both falls in oem range
 *
 *  @param[in] handler - the interface object
 *  @param[in] effecterId - effecter id
 *  @param[in] compEffecterCnt - composite effecter count
 *  @param[out] entityType - entity type
 *  @param[out] entityInstance - entity instance number
 *  @param[out] stateSetId - state set id
 *
 *  @return true if the effecter is OEM. All out parameters are invalid
 *               for a non OEM effecter
 */
bool isOemStateEffecter(Handler& handler, uint16_t effecterId,
                        uint8_t compEffecterCnt, uint16_t& entityType,
                        uint16_t& entityInstance, uint16_t& stateSetId);

} // namespace platform
} // namespace responder
} // namespace pldm
