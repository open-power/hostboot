#include "config.h"

#include "host_pdr_handler.hpp"

#include "libpldm/requester/pldm.h"

#include <assert.h>

#include <nlohmann/json.hpp>
#include <sdeventplus/clock.hpp>
#include <sdeventplus/exception.hpp>
#include <sdeventplus/source/io.hpp>
#include <sdeventplus/source/time.hpp>

#include <fstream>

namespace pldm
{

using namespace pldm::dbus_api;
using namespace pldm::responder::events;
using namespace pldm::utils;
using namespace sdbusplus::bus::match::rules;
using Json = nlohmann::json;
namespace fs = std::filesystem;
constexpr auto fruJson = "host_frus.json";
const Json emptyJson{};
const std::vector<Json> emptyJsonList{};

HostPDRHandler::HostPDRHandler(
    int mctp_fd, uint8_t mctp_eid, sdeventplus::Event& event, pldm_pdr* repo,
    const std::string& eventsJsonsDir, pldm_entity_association_tree* entityTree,
    pldm_entity_association_tree* bmcEntityTree, Requester& requester,
    pldm::requester::Handler<pldm::requester::Request>* handler) :
    mctp_fd(mctp_fd),
    mctp_eid(mctp_eid), event(event), repo(repo),
    stateSensorHandler(eventsJsonsDir), entityTree(entityTree),
    bmcEntityTree(bmcEntityTree), requester(requester), handler(handler)
{
    fs::path hostFruJson(fs::path(HOST_JSONS_DIR) / fruJson);
    if (fs::exists(hostFruJson))
    {
        // Note parent entities for entities sent down by the host firmware.
        // This will enable a merge of entity associations.
        try
        {
            std::ifstream jsonFile(hostFruJson);
            auto data = Json::parse(jsonFile, nullptr, false);
            if (data.is_discarded())
            {
                std::cerr << "Parsing Host FRU json file failed" << std::endl;
            }
            else
            {
                auto entities = data.value("entities", emptyJsonList);
                for (auto& entity : entities)
                {
                    EntityType entityType = entity.value("entity_type", 0);
                    auto parent = entity.value("parent", emptyJson);
                    pldm_entity p{};
                    p.entity_type = parent.value("entity_type", 0);
                    p.entity_instance_num = parent.value("entity_instance", 0);
                    parents.emplace(entityType, std::move(p));
                }
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Parsing Host FRU json file failed, exception = "
                      << e.what() << std::endl;
        }
    }

    hostOffMatch = std::make_unique<sdbusplus::bus::match::match>(
        pldm::utils::DBusHandler::getBus(),
        propertiesChanged("/xyz/openbmc_project/state/host0",
                          "xyz.openbmc_project.State.Host"),
        [this, repo, entityTree,
         bmcEntityTree](sdbusplus::message::message& msg) {
            DbusChangedProps props{};
            std::string intf;
            msg.read(intf, props);
            const auto itr = props.find("CurrentHostState");
            if (itr != props.end())
            {
                PropertyValue value = itr->second;
                auto propVal = std::get<std::string>(value);
                if (propVal == "xyz.openbmc_project.State.Host.HostState.Off")
                {
                    pldm_pdr_remove_remote_pdrs(repo);
                    pldm_entity_association_tree_destroy_root(entityTree);
                    pldm_entity_association_tree_copy_root(bmcEntityTree,
                                                           entityTree);
                    this->sensorMap.clear();
                    this->responseReceived = false;
                }
            }
        });
}

void HostPDRHandler::fetchPDR(PDRRecordHandles&& recordHandles)
{
    pdrRecordHandles.clear();
    pdrRecordHandles = std::move(recordHandles);

    // Defer the actual fetch of PDRs from the host (by queuing the call on the
    // main event loop). That way, we can respond to the platform event msg from
    // the host firmware.
    pdrFetchEvent = std::make_unique<sdeventplus::source::Defer>(
        event, std::bind(std::mem_fn(&HostPDRHandler::_fetchPDR), this,
                         std::placeholders::_1));
}

void HostPDRHandler::_fetchPDR(sdeventplus::source::EventBase& /*source*/)
{
    getHostPDR();
}

void HostPDRHandler::getHostPDR(uint32_t nextRecordHandle)
{
    pdrFetchEvent.reset();

    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_GET_PDR_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    uint32_t recordHandle{};
    if (!nextRecordHandle)
    {
        if (!pdrRecordHandles.empty())
        {
            recordHandle = pdrRecordHandles.front();
            pdrRecordHandles.pop_front();
        }
    }
    else
    {
        recordHandle = nextRecordHandle;
    }
    auto instanceId = requester.getInstanceId(mctp_eid);

    auto rc =
        encode_get_pdr_req(instanceId, recordHandle, 0, PLDM_GET_FIRSTPART,
                           UINT16_MAX, 0, request, PLDM_GET_PDR_REQ_BYTES);
    if (rc != PLDM_SUCCESS)
    {
        requester.markFree(mctp_eid, instanceId);
        std::cerr << "Failed to encode_get_pdr_req, rc = " << rc << std::endl;
        return;
    }

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_PLATFORM, PLDM_GET_PDR,
        std::move(requestMsg),
        std::move(std::bind_front(&HostPDRHandler::processHostPDRs, this)));
    if (rc)
    {
        std::cerr << "Failed to send the GetPDR request to Host \n";
    }
}

int HostPDRHandler::handleStateSensorEvent(const StateSensorEntry& entry,
                                           pdr::EventState state)
{
    auto rc = stateSensorHandler.eventAction(entry, state);
    if (rc != PLDM_SUCCESS)
    {
        std::cerr << "Failed to fetch and update D-bus property, rc = " << rc
                  << std::endl;
        return rc;
    }
    return PLDM_SUCCESS;
}
bool HostPDRHandler::getParent(EntityType type, pldm_entity& parent)
{
    auto found = parents.find(type);
    if (found != parents.end())
    {
        parent.entity_type = found->second.entity_type;
        parent.entity_instance_num = found->second.entity_instance_num;
        return true;
    }

    return false;
}

void HostPDRHandler::mergeEntityAssociations(const std::vector<uint8_t>& pdr)
{
    size_t numEntities{};
    pldm_entity* entities = nullptr;
    bool merged = false;
    auto entityPdr = reinterpret_cast<pldm_pdr_entity_association*>(
        const_cast<uint8_t*>(pdr.data()) + sizeof(pldm_pdr_hdr));

    pldm_entity_association_pdr_extract(pdr.data(), pdr.size(), &numEntities,
                                        &entities);
    for (size_t i = 0; i < numEntities; ++i)
    {
        pldm_entity parent{};
        if (getParent(entities[i].entity_type, parent))
        {
            auto node = pldm_entity_association_tree_find(entityTree, &parent);
            if (node)
            {
                pldm_entity_association_tree_add(entityTree, &entities[i],
                                                 0xFFFF, node,
                                                 entityPdr->association_type);
                merged = true;
            }
        }
    }

    if (merged)
    {
        // Update our PDR repo with the merged entity association PDRs
        pldm_entity_node* node = nullptr;
        pldm_find_entity_ref_in_tree(entityTree, entities[0], &node);
        if (node == nullptr)
        {
            std::cerr
                << "\ncould not find referrence of the entity in the tree \n";
        }
        else
        {
            pldm_entity_association_pdr_add_from_node(node, repo, &entities,
                                                      numEntities, true);
        }
    }
    free(entities);
}

void HostPDRHandler::sendPDRRepositoryChgEvent(std::vector<uint8_t>&& pdrTypes,
                                               uint8_t eventDataFormat)
{
    assert(eventDataFormat == FORMAT_IS_PDR_HANDLES);

    // Extract from the PDR repo record handles of PDRs we want the host
    // to pull up.
    std::vector<uint8_t> eventDataOps{PLDM_RECORDS_ADDED};
    std::vector<uint8_t> numsOfChangeEntries(1);
    std::vector<std::vector<ChangeEntry>> changeEntries(
        numsOfChangeEntries.size());
    for (auto pdrType : pdrTypes)
    {
        const pldm_pdr_record* record{};
        do
        {
            record = pldm_pdr_find_record_by_type(repo, pdrType, record,
                                                  nullptr, nullptr);
            if (record && pldm_pdr_record_is_remote(record))
            {
                changeEntries[0].push_back(
                    pldm_pdr_get_record_handle(repo, record));
            }
        } while (record);
    }
    if (changeEntries.empty())
    {
        return;
    }
    numsOfChangeEntries[0] = changeEntries[0].size();

    // Encode PLDM platform event msg to indicate a PDR repo change.
    size_t maxSize = PLDM_PDR_REPOSITORY_CHG_EVENT_MIN_LENGTH +
                     PLDM_PDR_REPOSITORY_CHANGE_RECORD_MIN_LENGTH +
                     changeEntries[0].size() * sizeof(uint32_t);
    std::vector<uint8_t> eventDataVec{};
    eventDataVec.resize(maxSize);
    auto eventData =
        reinterpret_cast<struct pldm_pdr_repository_chg_event_data*>(
            eventDataVec.data());
    size_t actualSize{};
    auto firstEntry = changeEntries[0].data();
    auto rc = encode_pldm_pdr_repository_chg_event_data(
        eventDataFormat, 1, eventDataOps.data(), numsOfChangeEntries.data(),
        &firstEntry, eventData, &actualSize, maxSize);
    if (rc != PLDM_SUCCESS)
    {
        std::cerr
            << "Failed to encode_pldm_pdr_repository_chg_event_data, rc = "
            << rc << std::endl;
        return;
    }
    auto instanceId = requester.getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
                                    actualSize);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    rc = encode_platform_event_message_req(
        instanceId, 1, 0, PLDM_PDR_REPOSITORY_CHG_EVENT, eventDataVec.data(),
        actualSize, request,
        actualSize + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES);
    if (rc != PLDM_SUCCESS)
    {
        requester.markFree(mctp_eid, instanceId);
        std::cerr << "Failed to encode_platform_event_message_req, rc = " << rc
                  << std::endl;
        return;
    }

    auto platformEventMessageResponseHandler = [](mctp_eid_t /*eid*/,
                                                  const pldm_msg* response,
                                                  size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            std::cerr << "Failed to receive response for the PDR repository "
                         "changed event"
                      << "\n";
            return;
        }

        uint8_t completionCode{};
        uint8_t status{};
        auto responsePtr = reinterpret_cast<const struct pldm_msg*>(response);
        auto rc = decode_platform_event_message_resp(responsePtr, respMsgLen,
                                                     &completionCode, &status);
        if (rc || completionCode)
        {
            std::cerr << "Failed to decode_platform_event_message_resp: "
                      << "rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << std::endl;
        }
    };

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_PLATFORM, PLDM_PLATFORM_EVENT_MESSAGE,
        std::move(requestMsg), std::move(platformEventMessageResponseHandler));
    if (rc)
    {
        std::cerr << "Failed to send the PDR repository changed event request"
                  << "\n";
    }
}

void HostPDRHandler::parseStateSensorPDRs(const PDRList& stateSensorPDRs,
                                          const TLPDRMap& tlpdrInfo)
{
    for (const auto& pdr : stateSensorPDRs)
    {
        SensorEntry sensorEntry{};
        const auto& [terminusHandle, sensorID, sensorInfo] =
            responder::pdr_utils::parseStateSensorPDR(pdr);
        sensorEntry.sensorID = sensorID;
        try
        {
            sensorEntry.terminusID = tlpdrInfo.at(terminusHandle);
        }
        // If there is no mapping for terminusHandle assign the reserved TID
        // value of 0xFF to indicate that.
        catch (const std::out_of_range& e)
        {
            sensorEntry.terminusID = PLDM_TID_RESERVED;
        }
        sensorMap.emplace(sensorEntry, std::move(sensorInfo));
    }
}

void HostPDRHandler::processHostPDRs(mctp_eid_t /*eid*/,
                                     const pldm_msg* response,
                                     size_t respMsgLen)
{
    static bool merged = false;
    static PDRList stateSensorPDRs{};
    static TLPDRMap tlpdrInfo{};
    uint32_t nextRecordHandle{};
    std::vector<TlInfo> tlInfo;
    uint8_t tlEid = 0;
    bool tlValid = true;
    uint32_t rh = 0;
    uint16_t terminusHandle = 0;
    uint8_t tid = 0;

    uint8_t completionCode{};
    uint32_t nextDataTransferHandle{};
    uint8_t transferFlag{};
    uint16_t respCount{};
    uint8_t transferCRC{};
    if (response == nullptr || !respMsgLen)
    {
        std::cerr << "Failed to receive response for the GetPDR"
                     " command \n";
        return;
    }

    auto rc = decode_get_pdr_resp(
        response, respMsgLen /*- sizeof(pldm_msg_hdr)*/, &completionCode,
        &nextRecordHandle, &nextDataTransferHandle, &transferFlag, &respCount,
        nullptr, 0, &transferCRC);
    std::vector<uint8_t> responsePDRMsg;
    responsePDRMsg.resize(respMsgLen + sizeof(pldm_msg_hdr));
    memcpy(responsePDRMsg.data(), response, respMsgLen + sizeof(pldm_msg_hdr));
    if (rc != PLDM_SUCCESS)
    {
        std::cerr << "Failed to decode_get_pdr_resp, rc = " << rc << std::endl;
        return;
    }
    else
    {
        std::vector<uint8_t> pdr(respCount, 0);
        rc = decode_get_pdr_resp(response, respMsgLen, &completionCode,
                                 &nextRecordHandle, &nextDataTransferHandle,
                                 &transferFlag, &respCount, pdr.data(),
                                 respCount, &transferCRC);
        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Failed to decode_get_pdr_resp: "
                      << "rc=" << rc
                      << ", cc=" << static_cast<unsigned>(completionCode)
                      << std::endl;
            return;
        }
        else
        {
            // when nextRecordHandle is 0, we need the recordHandle of the last
            // PDR and not 0-1.
            if (!nextRecordHandle)
            {
                rh = nextRecordHandle;
            }
            else
            {
                rh = nextRecordHandle - 1;
            }

            auto pdrHdr = reinterpret_cast<pldm_pdr_hdr*>(pdr.data());
            if (!rh)
            {
                rh = pdrHdr->record_handle;
            }

            if (pdrHdr->type == PLDM_PDR_ENTITY_ASSOCIATION)
            {
                this->mergeEntityAssociations(pdr);
                merged = true;
            }
            else
            {
                if (pdrHdr->type == PLDM_TERMINUS_LOCATOR_PDR)
                {
                    auto tlpdr =
                        reinterpret_cast<const pldm_terminus_locator_pdr*>(
                            pdr.data());
                    tlpdrInfo.emplace(
                        static_cast<pldm::pdr::TerminusHandle>(
                            tlpdr->terminus_handle),
                        static_cast<pldm::pdr::TerminusID>(tlpdr->tid));

                    terminusHandle = tlpdr->terminus_handle;
                    tid = tlpdr->tid;
                    auto terminus_locator_type = tlpdr->terminus_locator_type;
                    if (terminus_locator_type ==
                        PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID)
                    {
                        auto locatorValue = reinterpret_cast<
                            const pldm_terminus_locator_type_mctp_eid*>(
                            tlpdr->terminus_locator_value);
                        tlEid = static_cast<uint8_t>(locatorValue->eid);
                    }
                    if (tlpdr->validity == 0)
                    {
                        tlValid = false;
                    }
                    tlInfo.emplace_back(
                        TlInfo{tlpdr->validity, static_cast<uint8_t>(tlEid),
                               tlpdr->tid, tlpdr->terminus_handle});
                }
                else if (pdrHdr->type == PLDM_STATE_SENSOR_PDR)
                {
                    stateSensorPDRs.emplace_back(pdr);
                }

                // if the TLPDR is invalid update the repo accordingly
                if (!tlValid)
                {
                    pldm_pdr_update_TL_pdr(repo, terminusHandle, tid, tlEid,
                                           tlValid);
                }
                else
                {
                    pldm_pdr_add(repo, pdr.data(), respCount, rh, true);
                }
            }
        }
    }
    if (!nextRecordHandle)
    {
        /*received last record*/
        this->parseStateSensorPDRs(stateSensorPDRs, tlpdrInfo);
        if (isHostUp())
        {
            this->setHostSensorState(stateSensorPDRs, tlInfo);
        }
        stateSensorPDRs.clear();
        tlpdrInfo.clear();
        if (merged)
        {
            merged = false;
            deferredPDRRepoChgEvent =
                std::make_unique<sdeventplus::source::Defer>(
                    event,
                    std::bind(
                        std::mem_fn((&HostPDRHandler::_processPDRRepoChgEvent)),
                        this, std::placeholders::_1));
        }
    }
    else
    {
        deferredFetchPDREvent = std::make_unique<sdeventplus::source::Defer>(
            event,
            std::bind(std::mem_fn((&HostPDRHandler::_processFetchPDREvent)),
                      this, nextRecordHandle, std::placeholders::_1));
    }
}

void HostPDRHandler::_processPDRRepoChgEvent(
    sdeventplus::source::EventBase& /*source */)
{
    deferredPDRRepoChgEvent.reset();
    this->sendPDRRepositoryChgEvent(
        std::move(std::vector<uint8_t>(1, PLDM_PDR_ENTITY_ASSOCIATION)),
        FORMAT_IS_PDR_HANDLES);
}

void HostPDRHandler::_processFetchPDREvent(
    uint32_t nextRecordHandle, sdeventplus::source::EventBase& /*source */)
{
    deferredFetchPDREvent.reset();
    if (!this->pdrRecordHandles.empty())
    {
        nextRecordHandle = this->pdrRecordHandles.front();
        this->pdrRecordHandles.pop_front();
    }
    this->getHostPDR(nextRecordHandle);
}

void HostPDRHandler::setHostFirmwareCondition()
{
    responseReceived = false;
    auto instanceId = requester.getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_GET_VERSION_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    auto rc = encode_get_version_req(instanceId, 0, PLDM_GET_FIRSTPART,
                                     PLDM_BASE, request);
    if (rc != PLDM_SUCCESS)
    {
        std::cerr << "GetPLDMVersion encode failure. PLDM error code = "
                  << std::hex << std::showbase << rc << "\n";
        requester.markFree(mctp_eid, instanceId);
        return;
    }

    auto getPLDMVersionHandler = [this](mctp_eid_t /*eid*/,
                                        const pldm_msg* response,
                                        size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            std::cerr << "Failed to receive response for "
                      << "getPLDMVersion command, Host seems to be off \n";
            return;
        }
        std::cout << "Getting the response. PLDM RC = " << std::hex
                  << std::showbase
                  << static_cast<uint16_t>(response->payload[0]) << "\n";
        this->responseReceived = true;
        getHostPDR();
    };
    rc = handler->registerRequest(mctp_eid, instanceId, PLDM_BASE,
                                  PLDM_GET_PLDM_VERSION, std::move(requestMsg),
                                  std::move(getPLDMVersionHandler));
    if (rc)
    {
        std::cerr << "Failed to discover Host state. Assuming Host as off \n";
    }
}

bool HostPDRHandler::isHostUp()
{
    return responseReceived;
}

void HostPDRHandler::setHostSensorState(const PDRList& stateSensorPDRs,
                                        const std::vector<TlInfo>& tlinfo)
{
    for (const auto& stateSensorPDR : stateSensorPDRs)
    {
        auto pdr = reinterpret_cast<const pldm_state_sensor_pdr*>(
            stateSensorPDR.data());

        if (!pdr)
        {
            std::cerr << "Failed to get State sensor PDR" << std::endl;
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
            return;
        }

        uint16_t sensorId = pdr->sensor_id;

        for (auto info : tlinfo)
        {
            if (info.terminusHandle == pdr->terminus_handle)
            {
                if (info.valid == PLDM_TL_PDR_VALID)
                {
                    mctp_eid = info.eid;
                }

                bitfield8_t sensorRearm;
                sensorRearm.byte = 0;
                uint8_t tid = info.tid;

                auto instanceId = requester.getInstanceId(mctp_eid);
                std::vector<uint8_t> requestMsg(
                    sizeof(pldm_msg_hdr) +
                    PLDM_GET_STATE_SENSOR_READINGS_REQ_BYTES);
                auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
                auto rc = encode_get_state_sensor_readings_req(
                    instanceId, sensorId, sensorRearm, 0, request);

                if (rc != PLDM_SUCCESS)
                {
                    requester.markFree(mctp_eid, instanceId);
                    std::cerr << "Failed to "
                                 "encode_get_state_sensor_readings_req, rc = "
                              << rc << std::endl;
                    pldm::utils::reportError(
                        "xyz.openbmc_project.bmc.pldm.InternalFailure");
                    return;
                }

                auto getStateSensorReadingRespHandler = [=, this](
                                                            mctp_eid_t /*eid*/,
                                                            const pldm_msg*
                                                                response,
                                                            size_t respMsgLen) {
                    if (response == nullptr || !respMsgLen)
                    {
                        std::cerr << "Failed to receive response for "
                                     "getStateSensorReading command \n";
                        return;
                    }
                    std::array<get_sensor_state_field, 8> stateField{};
                    uint8_t completionCode = 0;
                    uint8_t comp_sensor_count = 0;

                    auto rc = decode_get_state_sensor_readings_resp(
                        response, respMsgLen, &completionCode,
                        &comp_sensor_count, stateField.data());

                    if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
                    {
                        std::cerr
                            << "Failed to "
                               "decode_get_state_sensor_readings_resp, rc = "
                            << rc
                            << " cc=" << static_cast<unsigned>(completionCode)
                            << std::endl;
                        pldm::utils::reportError(
                            "xyz.openbmc_project.bmc.pldm.InternalFailure");
                    }

                    uint8_t eventState;
                    uint8_t previousEventState;
                    uint8_t sensorOffset = comp_sensor_count - 1;

                    for (size_t i = 0; i < comp_sensor_count; i++)
                    {
                        eventState = stateField[i].present_state;
                        previousEventState = stateField[i].previous_state;

                        emitStateSensorEventSignal(tid, sensorId, sensorOffset,
                                                   eventState,
                                                   previousEventState);

                        SensorEntry sensorEntry{tid, sensorId};

                        pldm::pdr::EntityInfo entityInfo{};
                        pldm::pdr::CompositeSensorStates
                            compositeSensorStates{};

                        try
                        {
                            std::tie(entityInfo, compositeSensorStates) =
                                lookupSensorInfo(sensorEntry);
                        }
                        catch (const std::out_of_range& e)
                        {
                            try
                            {
                                sensorEntry.terminusID = PLDM_TID_RESERVED;
                                std::tie(entityInfo, compositeSensorStates) =
                                    lookupSensorInfo(sensorEntry);
                            }
                            catch (const std::out_of_range& e)
                            {
                                std::cerr << "No mapping for the events"
                                          << std::endl;
                            }
                        }

                        if (sensorOffset > compositeSensorStates.size())
                        {
                            std::cerr
                                << " Error Invalid data, Invalid sensor offset"
                                << std::endl;
                            return;
                        }

                        const auto& possibleStates =
                            compositeSensorStates[sensorOffset];
                        if (possibleStates.find(eventState) ==
                            possibleStates.end())
                        {
                            std::cerr
                                << " Error invalid_data, Invalid event state"
                                << std::endl;
                            return;
                        }
                        const auto& [containerId, entityType, entityInstance] =
                            entityInfo;
                        pldm::responder::events::StateSensorEntry
                            stateSensorEntry{containerId, entityType,
                                             entityInstance, sensorOffset};
                        handleStateSensorEvent(stateSensorEntry, eventState);
                    }
                };

                rc = handler->registerRequest(
                    mctp_eid, instanceId, PLDM_PLATFORM,
                    PLDM_GET_STATE_SENSOR_READINGS, std::move(requestMsg),
                    std::move(getStateSensorReadingRespHandler));

                if (rc != PLDM_SUCCESS)
                {
                    std::cerr << " Failed to send request to get State sensor "
                                 "reading on Host "
                              << std::endl;
                }
            }
        }
    }
}
} // namespace pldm
