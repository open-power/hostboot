#include "host_pdr_handler.hpp"

#include <libpldm/fru.h>
#ifdef OEM_IBM
#include <libpldm/oem/ibm/fru.h>
#endif
#include "dbus/custom_dbus.hpp"

#include <nlohmann/json.hpp>
#include <phosphor-logging/lg2.hpp>
#include <sdeventplus/clock.hpp>
#include <sdeventplus/exception.hpp>
#include <sdeventplus/source/io.hpp>
#include <sdeventplus/source/time.hpp>

#include <cassert>
#include <fstream>
#include <type_traits>

PHOSPHOR_LOG2_USING;

namespace pldm
{
using namespace pldm::responder::events;
using namespace pldm::utils;
using namespace sdbusplus::bus::match::rules;
using namespace pldm::responder::pdr_utils;
using namespace pldm::hostbmc::utils;
using Json = nlohmann::json;
namespace fs = std::filesystem;
using namespace pldm::dbus;
const Json emptyJson{};

template <typename T>
uint16_t extractTerminusHandle(std::vector<uint8_t>& pdr)
{
    T* var = nullptr;
    if (std::is_same<T, pldm_pdr_fru_record_set>::value)
    {
        var = (T*)(pdr.data() + sizeof(pldm_pdr_hdr));
    }
    else
    {
        var = (T*)(pdr.data());
    }
    if (var != nullptr)
    {
        return var->terminus_handle;
    }
    return TERMINUS_HANDLE;
}

template <typename T>
void updateContainerId(pldm_entity_association_tree* entityTree,
                       std::vector<uint8_t>& pdr)
{
    T* t = nullptr;
    if (entityTree == nullptr)
    {
        return;
    }
    if (std::is_same<T, pldm_pdr_fru_record_set>::value)
    {
        t = (T*)(pdr.data() + sizeof(pldm_pdr_hdr));
    }
    else
    {
        t = (T*)(pdr.data());
    }
    if (t == nullptr)
    {
        return;
    }

    pldm_entity entity{t->entity_type, t->entity_instance, t->container_id};
    auto node = pldm_entity_association_tree_find_with_locality(
        entityTree, &entity, true);
    if (node)
    {
        pldm_entity e = pldm_entity_extract(node);
        t->container_id = e.entity_container_id;
    }
}

HostPDRHandler::HostPDRHandler(
    int /* mctp_fd */, uint8_t mctp_eid, sdeventplus::Event& event,
    pldm_pdr* repo, const std::string& eventsJsonsDir,
    pldm_entity_association_tree* entityTree,
    pldm_entity_association_tree* bmcEntityTree,
    pldm::InstanceIdDb& instanceIdDb,
    pldm::requester::Handler<pldm::requester::Request>* handler) :
    mctp_eid(mctp_eid), event(event), repo(repo),
    stateSensorHandler(eventsJsonsDir), entityTree(entityTree),
    instanceIdDb(instanceIdDb), handler(handler),
    entityMaps(parseEntityMap(ENTITY_MAP_JSON)), oemUtilsHandler(nullptr)
{
    mergedHostParents = false;
    hostOffMatch = std::make_unique<sdbusplus::bus::match_t>(
        pldm::utils::DBusHandler::getBus(),
        propertiesChanged("/xyz/openbmc_project/state/host0",
                          "xyz.openbmc_project.State.Host"),
        [this, repo, entityTree, bmcEntityTree](sdbusplus::message_t& msg) {
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
                    // Delete all the remote terminus information
                    std::erase_if(tlPDRInfo, [](const auto& item) {
                        const auto& [key, value] = item;
                        return key != TERMINUS_HANDLE;
                    });
                    pldm_pdr_remove_remote_pdrs(repo);
                    pldm_entity_association_tree_destroy_root(entityTree);
                    pldm_entity_association_tree_copy_root(bmcEntityTree,
                                                           entityTree);
                    this->sensorMap.clear();
                    this->responseReceived = false;
                    this->mergedHostParents = false;
                }
            }
        });
}

void HostPDRHandler::fetchPDR(PDRRecordHandles&& recordHandles)
{
    pdrRecordHandles.clear();
    modifiedPDRRecordHandles.clear();

    if (isHostPdrModified)
    {
        modifiedPDRRecordHandles = std::move(recordHandles);
    }
    else
    {
        pdrRecordHandles = std::move(recordHandles);
    }

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

    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_GET_PDR_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    uint32_t recordHandle{};
    if (!nextRecordHandle && (!modifiedPDRRecordHandles.empty()) &&
        isHostPdrModified)
    {
        recordHandle = modifiedPDRRecordHandles.front();
        modifiedPDRRecordHandles.pop_front();
    }
    else if (!nextRecordHandle && (!pdrRecordHandles.empty()))
    {
        recordHandle = pdrRecordHandles.front();
        pdrRecordHandles.pop_front();
    }
    else
    {
        recordHandle = nextRecordHandle;
    }
    auto instanceId = instanceIdDb.next(mctp_eid);

    auto rc =
        encode_get_pdr_req(instanceId, recordHandle, 0, PLDM_GET_FIRSTPART,
                           UINT16_MAX, 0, request, PLDM_GET_PDR_REQ_BYTES);
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb.free(mctp_eid, instanceId);
        error("Failed to encode get pdr request, response code '{RC}'", "RC",
              rc);
        return;
    }

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_PLATFORM, PLDM_GET_PDR,
        std::move(requestMsg),
        std::bind_front(&HostPDRHandler::processHostPDRs, this));
    if (rc)
    {
        error(
            "Failed to send the getPDR request to remote terminus, response code '{RC}'",
            "RC", rc);
    }
}

int HostPDRHandler::handleStateSensorEvent(const StateSensorEntry& entry,
                                           pdr::EventState state)
{
    auto rc = stateSensorHandler.eventAction(entry, state);
    if (rc != PLDM_SUCCESS)
    {
        error("Failed to fetch and update D-bus property, response code '{RC}'",
              "RC", rc);
        return rc;
    }
    return PLDM_SUCCESS;
}

void HostPDRHandler::mergeEntityAssociations(
    const std::vector<uint8_t>& pdr, [[maybe_unused]] const uint32_t& size,
    [[maybe_unused]] const uint32_t& record_handle)
{
    size_t numEntities{};
    pldm_entity* entities = nullptr;
    bool merged = false;
    auto entityPdr = reinterpret_cast<pldm_pdr_entity_association*>(
        const_cast<uint8_t*>(pdr.data()) + sizeof(pldm_pdr_hdr));

    if (oemPlatformHandler &&
        oemPlatformHandler->checkRecordHandleInRange(record_handle))
    {
        // Adding the remote range PDRs to the repo before merging it
        uint32_t handle = record_handle;
        pldm_pdr_add(repo, pdr.data(), size, true, 0xFFFF, &handle);
    }

    pldm_entity_association_pdr_extract(pdr.data(), pdr.size(), &numEntities,
                                        &entities);
    if (numEntities > 0)
    {
        pldm_entity_node* pNode = nullptr;
        if (!mergedHostParents)
        {
            pNode = pldm_entity_association_tree_find_with_locality(
                entityTree, &entities[0], false);
        }
        else
        {
            pNode = pldm_entity_association_tree_find_with_locality(
                entityTree, &entities[0], true);
        }
        if (!pNode)
        {
            return;
        }

        Entities entityAssoc;
        entityAssoc.push_back(pNode);
        for (size_t i = 1; i < numEntities; ++i)
        {
            bool isUpdateContainerId = true;
            if (oemPlatformHandler)
            {
                isUpdateContainerId =
                    checkIfLogicalBitSet(entities[i].entity_container_id);
            }
            auto node = pldm_entity_association_tree_add_entity(
                entityTree, &entities[i], entities[i].entity_instance_num,
                pNode, entityPdr->association_type, true, isUpdateContainerId,
                0xFFFF);
            if (!node)
            {
                continue;
            }
            merged = true;
            entityAssoc.push_back(node);
        }

        mergedHostParents = true;
        if (merged)
        {
            entityAssociations.push_back(entityAssoc);
        }
    }

    if (merged)
    {
        // Update our PDR repo with the merged entity association PDRs
        pldm_entity_node* node = nullptr;
        pldm_find_entity_ref_in_tree(entityTree, entities[0], &node);
        if (node == nullptr)
        {
            error("Failed to find reference of the entity in the tree");
        }
        else
        {
            int rc = 0;
            if (oemPlatformHandler)
            {
                auto record = oemPlatformHandler->fetchLastBMCRecord(repo);

                uint32_t record_handle =
                    pldm_pdr_get_record_handle(repo, record);

                rc =
                    pldm_entity_association_pdr_add_from_node_with_record_handle(
                        node, repo, &entities, numEntities, true,
                        TERMINUS_HANDLE, (record_handle + 1));
            }
            else
            {
                rc = pldm_entity_association_pdr_add_from_node(
                    node, repo, &entities, numEntities, true, TERMINUS_HANDLE);
            }

            if (rc)
            {
                error(
                    "Failed to add entity association PDR from node, response code '{RC}'",
                    "RC", rc);
            }
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
        error(
            "Failed to encode pldm pdr repository change event data, response code '{RC}'",
            "RC", rc);
        return;
    }
    auto instanceId = instanceIdDb.next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
        actualSize);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    rc = encode_platform_event_message_req(
        instanceId, 1, TERMINUS_ID, PLDM_PDR_REPOSITORY_CHG_EVENT,
        eventDataVec.data(), actualSize, request,
        actualSize + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES);
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb.free(mctp_eid, instanceId);
        error(
            "Failed to encode platform event message request, response code '{RC}'",
            "RC", rc);
        return;
    }

    auto platformEventMessageResponseHandler = [](mctp_eid_t /*eid*/,
                                                  const pldm_msg* response,
                                                  size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error(
                "Failed to receive response for the PDR repository changed event");
            return;
        }

        uint8_t completionCode{};
        uint8_t status{};
        auto responsePtr = reinterpret_cast<const struct pldm_msg*>(response);
        auto rc = decode_platform_event_message_resp(responsePtr, respMsgLen,
                                                     &completionCode, &status);
        if (rc || completionCode)
        {
            error(
                "Failed to decode platform event message response, response code '{RC}' and completion code '{CC}'",
                "RC", rc, "CC", completionCode);
        }
    };

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_PLATFORM, PLDM_PLATFORM_EVENT_MESSAGE,
        std::move(requestMsg), std::move(platformEventMessageResponseHandler));
    if (rc)
    {
        error(
            "Failed to send the PDR repository changed event request, response code '{RC}'",
            "RC", rc);
    }
}

void HostPDRHandler::parseStateSensorPDRs(const PDRList& stateSensorPDRs)
{
    for (const auto& pdr : stateSensorPDRs)
    {
        SensorEntry sensorEntry{};
        const auto& [terminusHandle, sensorID, sensorInfo] =
            responder::pdr_utils::parseStateSensorPDR(pdr);
        sensorEntry.sensorID = sensorID;
        try
        {
            sensorEntry.terminusID = std::get<0>(tlPDRInfo.at(terminusHandle));
        }
        // If there is no mapping for terminusHandle assign the reserved TID
        // value of 0xFF to indicate that.
        catch (const std::out_of_range&)
        {
            sensorEntry.terminusID = PLDM_TID_RESERVED;
        }
        sensorMap.emplace(sensorEntry, std::move(sensorInfo));
    }
}

void HostPDRHandler::processHostPDRs(
    mctp_eid_t /*eid*/, const pldm_msg* response, size_t respMsgLen)
{
    static bool merged = false;
    static PDRList stateSensorPDRs{};
    static PDRList fruRecordSetPDRs{};
    uint32_t nextRecordHandle{};
    uint8_t tlEid = 0;
    bool tlValid = true;
    uint32_t rh = 0;
    uint16_t terminusHandle = 0;
    uint16_t pdrTerminusHandle = 0;
    uint8_t tid = 0;

    uint8_t completionCode{};
    uint32_t nextDataTransferHandle{};
    uint8_t transferFlag{};
    uint16_t respCount{};
    uint8_t transferCRC{};
    if (response == nullptr || !respMsgLen)
    {
        error("Failed to receive response for the GetPDR command");
        pldm::utils::reportError(
            "xyz.openbmc_project.PLDM.Error.GetPDR.PDRExchangeFailure");
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
        error(
            "Failed to decode getPDR response for next record handle '{NEXT_RECORD_HANDLE}', response code '{RC}'",
            "NEXT_RECORD_HANDLE", nextRecordHandle, "RC", rc);
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
            error(
                "Failed to decode getPDR response for next record handle '{NEXT_RECORD_HANDLE}', next data transfer handle '{DATA_TRANSFER_HANDLE}' and transfer flag '{FLAG}', response code '{RC}' and completion code '{CC}'",
                "NEXT_RECORD_HANDLE", nextRecordHandle, "DATA_TRANSFER_HANDLE",
                nextDataTransferHandle, "FLAG", transferFlag, "RC", rc, "CC",
                completionCode);
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
                this->mergeEntityAssociations(pdr, respCount, rh);
                merged = true;
            }
            else
            {
                if (pdrHdr->type == PLDM_TERMINUS_LOCATOR_PDR)
                {
                    pdrTerminusHandle =
                        extractTerminusHandle<pldm_terminus_locator_pdr>(pdr);
                    auto tlpdr =
                        reinterpret_cast<const pldm_terminus_locator_pdr*>(
                            pdr.data());

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
                    for (const auto& terminusMap : tlPDRInfo)
                    {
                        if ((terminusHandle == (terminusMap.first)) &&
                            (get<1>(terminusMap.second) == tlEid) &&
                            (get<2>(terminusMap.second) == tlpdr->validity))
                        {
                            // TL PDR already present with same validity don't
                            // add the PDR to the repo just return
                            return;
                        }
                    }
                    tlPDRInfo.insert_or_assign(
                        tlpdr->terminus_handle,
                        std::make_tuple(tlpdr->tid, tlEid, tlpdr->validity));
                }
                else if (pdrHdr->type == PLDM_STATE_SENSOR_PDR)
                {
                    pdrTerminusHandle =
                        extractTerminusHandle<pldm_state_sensor_pdr>(pdr);
                    updateContainerId<pldm_state_sensor_pdr>(entityTree, pdr);
                    stateSensorPDRs.emplace_back(pdr);
                }
                else if (pdrHdr->type == PLDM_PDR_FRU_RECORD_SET)
                {
                    pdrTerminusHandle =
                        extractTerminusHandle<pldm_pdr_fru_record_set>(pdr);
                    updateContainerId<pldm_pdr_fru_record_set>(entityTree, pdr);
                    fruRecordSetPDRs.emplace_back(pdr);
                }
                else if (pdrHdr->type == PLDM_STATE_EFFECTER_PDR)
                {
                    pdrTerminusHandle =
                        extractTerminusHandle<pldm_state_effecter_pdr>(pdr);
                    updateContainerId<pldm_state_effecter_pdr>(entityTree, pdr);
                }
                else if (pdrHdr->type == PLDM_NUMERIC_EFFECTER_PDR)
                {
                    pdrTerminusHandle =
                        extractTerminusHandle<pldm_numeric_effecter_value_pdr>(
                            pdr);
                    updateContainerId<pldm_numeric_effecter_value_pdr>(
                        entityTree, pdr);
                }
                // if the TLPDR is invalid update the repo accordingly
                if (!tlValid)
                {
                    pldm_pdr_update_TL_pdr(repo, terminusHandle, tid, tlEid,
                                           tlValid);

                    if (!isHostUp())
                    {
                        // The terminus PDR becomes invalid when the terminus
                        // itself is down. We don't need to do PDR exchange in
                        // that case, so setting the next record handle to 0.
                        nextRecordHandle = 0;
                    }
                }
                else
                {
                    rc = pldm_pdr_add(repo, pdr.data(), respCount, true,
                                      pdrTerminusHandle, &rh);
                    if (rc)
                    {
                        // pldm_pdr_add() assert()ed on failure to add a PDR.
                        throw std::runtime_error("Failed to add PDR");
                    }
                }
            }
        }
    }
    if (!nextRecordHandle)
    {
        updateEntityAssociation(entityAssociations, entityTree, objPathMap,
                                entityMaps, oemPlatformHandler);
        if (oemUtilsHandler)
        {
            oemUtilsHandler->setCoreCount(entityAssociations, entityMaps);
        }
        /*received last record*/
        this->parseStateSensorPDRs(stateSensorPDRs);
        this->createDbusObjects(fruRecordSetPDRs);
        if (isHostUp())
        {
            this->setHostSensorState(stateSensorPDRs);
        }
        stateSensorPDRs.clear();
        fruRecordSetPDRs.clear();
        entityAssociations.clear();

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
        if (modifiedPDRRecordHandles.empty() && isHostPdrModified)
        {
            isHostPdrModified = false;
        }
        else
        {
            deferredFetchPDREvent =
                std::make_unique<sdeventplus::source::Defer>(
                    event,
                    std::bind(
                        std::mem_fn((&HostPDRHandler::_processFetchPDREvent)),
                        this, nextRecordHandle, std::placeholders::_1));
        }
    }
}

void HostPDRHandler::_processPDRRepoChgEvent(
    sdeventplus::source::EventBase& /*source */)
{
    deferredPDRRepoChgEvent.reset();
    this->sendPDRRepositoryChgEvent(
        std::vector<uint8_t>(1, PLDM_PDR_ENTITY_ASSOCIATION),
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
    if (isHostPdrModified && (!this->modifiedPDRRecordHandles.empty()))
    {
        nextRecordHandle = this->modifiedPDRRecordHandles.front();
        this->modifiedPDRRecordHandles.pop_front();
    }
    this->getHostPDR(nextRecordHandle);
}

void HostPDRHandler::setHostFirmwareCondition()
{
    responseReceived = false;
    auto instanceId = instanceIdDb.next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_GET_VERSION_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    auto rc = encode_get_version_req(instanceId, 0, PLDM_GET_FIRSTPART,
                                     PLDM_BASE, request);
    if (rc != PLDM_SUCCESS)
    {
        error("Failed to encode GetPLDMVersion, response code {RC}", "RC",
              lg2::hex, rc);
        instanceIdDb.free(mctp_eid, instanceId);
        return;
    }

    auto getPLDMVersionHandler = [this](mctp_eid_t /*eid*/,
                                        const pldm_msg* response,
                                        size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error(
                "Failed to receive response for getPLDMVersion command, Host seems to be off");
            return;
        }
        info("Getting the response code '{RC}'", "RC", lg2::hex,
             response->payload[0]);
        this->responseReceived = true;
    };
    rc = handler->registerRequest(mctp_eid, instanceId, PLDM_BASE,
                                  PLDM_GET_PLDM_VERSION, std::move(requestMsg),
                                  std::move(getPLDMVersionHandler));
    if (rc)
    {
        error(
            "Failed to discover remote terminus state. Assuming remote terminus as off");
    }
}

bool HostPDRHandler::isHostUp()
{
    return responseReceived;
}

void HostPDRHandler::setHostSensorState(const PDRList& stateSensorPDRs)
{
    for (const auto& stateSensorPDR : stateSensorPDRs)
    {
        auto pdr = reinterpret_cast<const pldm_state_sensor_pdr*>(
            stateSensorPDR.data());

        if (!pdr)
        {
            error("Failed to get state sensor PDR");
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
            return;
        }

        uint16_t sensorId = pdr->sensor_id;

        for (const auto& [terminusHandle, terminusInfo] : tlPDRInfo)
        {
            if (terminusHandle == pdr->terminus_handle)
            {
                if (std::get<2>(terminusInfo) == PLDM_TL_PDR_VALID)
                {
                    mctp_eid = std::get<1>(terminusInfo);
                }

                bitfield8_t sensorRearm;
                sensorRearm.byte = 0;
                uint8_t tid = std::get<0>(terminusInfo);

                auto instanceId = instanceIdDb.next(mctp_eid);
                std::vector<uint8_t> requestMsg(
                    sizeof(pldm_msg_hdr) +
                    PLDM_GET_STATE_SENSOR_READINGS_REQ_BYTES);
                auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
                auto rc = encode_get_state_sensor_readings_req(
                    instanceId, sensorId, sensorRearm, 0, request);

                if (rc != PLDM_SUCCESS)
                {
                    instanceIdDb.free(mctp_eid, instanceId);
                    error(
                        "Failed to encode get state sensor readings request for sensorID '{SENSOR_ID}' and  instanceID '{INSTANCE}', response code '{RC}'",
                        "SENSOR_ID", sensorId, "INSTANCE", instanceId, "RC",
                        rc);
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
                        error(
                            "Failed to receive response for get state sensor reading command for sensorID '{SENSOR_ID}' and  instanceID '{INSTANCE}'",
                            "SENSOR_ID", sensorId, "INSTANCE", instanceId);
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
                        error(
                            "Failed to decode get state sensor readings response for sensorID '{SENSOR_ID}' and  instanceID '{INSTANCE}', response code'{RC}' and completion code '{CC}'",
                            "SENSOR_ID", sensorId, "INSTANCE", instanceId, "RC",
                            rc, "CC", completionCode);
                        pldm::utils::reportError(
                            "xyz.openbmc_project.bmc.pldm.InternalFailure");
                    }

                    uint8_t eventState;
                    uint8_t previousEventState;

                    for (uint8_t sensorOffset = 0;
                         sensorOffset < comp_sensor_count; sensorOffset++)
                    {
                        eventState = stateField[sensorOffset].present_state;
                        previousEventState =
                            stateField[sensorOffset].previous_state;

                        emitStateSensorEventSignal(tid, sensorId, sensorOffset,
                                                   eventState,
                                                   previousEventState);

                        SensorEntry sensorEntry{tid, sensorId};

                        pldm::pdr::EntityInfo entityInfo{};
                        pldm::pdr::CompositeSensorStates
                            compositeSensorStates{};
                        std::vector<pldm::pdr::StateSetId> stateSetIds{};

                        try
                        {
                            std::tie(entityInfo, compositeSensorStates,
                                     stateSetIds) =
                                lookupSensorInfo(sensorEntry);
                        }
                        catch (const std::out_of_range&)
                        {
                            try
                            {
                                sensorEntry.terminusID = PLDM_TID_RESERVED;
                                std::tie(entityInfo, compositeSensorStates,
                                         stateSetIds) =
                                    lookupSensorInfo(sensorEntry);
                            }
                            catch (const std::out_of_range&)
                            {
                                error("No mapping for the events");
                            }
                        }

                        if ((compositeSensorStates.size() > 1) &&
                            (sensorOffset > (compositeSensorStates.size() - 1)))
                        {
                            error(
                                "Error Invalid data, Invalid sensor offset '{SENSOR_OFFSET}'",
                                "SENSOR_OFFSET", sensorOffset);
                            return;
                        }

                        const auto& possibleStates =
                            compositeSensorStates[sensorOffset];
                        if (possibleStates.find(eventState) ==
                            possibleStates.end())
                        {
                            error(
                                "Error invalid_data, Invalid event state '{STATE}'",
                                "STATE", eventState);
                            return;
                        }
                        const auto& [containerId, entityType, entityInstance] =
                            entityInfo;
                        auto stateSetId = stateSetIds[sensorOffset];
                        pldm::responder::events::StateSensorEntry
                            stateSensorEntry{containerId,    entityType,
                                             entityInstance, sensorOffset,
                                             stateSetId,     false};
                        handleStateSensorEvent(stateSensorEntry, eventState);
                    }
                };

                rc = handler->registerRequest(
                    mctp_eid, instanceId, PLDM_PLATFORM,
                    PLDM_GET_STATE_SENSOR_READINGS, std::move(requestMsg),
                    std::move(getStateSensorReadingRespHandler));

                if (rc != PLDM_SUCCESS)
                {
                    error(
                        "Failed to send request to get state sensor reading on remote terminus for sensorID '{SENSOR_ID}' and  instanceID '{INSTANCE}', response code '{RC}'",
                        "SENSOR_ID", sensorId, "INSTANCE", instanceId, "RC",
                        rc);
                }
            }
        }
    }
}

void HostPDRHandler::getFRURecordTableMetadataByRemote(
    const PDRList& fruRecordSetPDRs)
{
    auto instanceId = instanceIdDb.next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_GET_FRU_RECORD_TABLE_METADATA_REQ_BYTES);

    // GetFruRecordTableMetadata
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    auto rc = encode_get_fru_record_table_metadata_req(
        instanceId, request, requestMsg.size() - sizeof(pldm_msg_hdr));
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb.free(mctp_eid, instanceId);
        error(
            "Failed to encode get fru record table metadata request, response code '{RC}'",
            "RC", lg2::hex, rc);
        return;
    }

    auto getFruRecordTableMetadataResponseHandler = [this, fruRecordSetPDRs](
                                                        mctp_eid_t /*eid*/,
                                                        const pldm_msg*
                                                            response,
                                                        size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error(
                "Failed to receive response for the get fru record table metadata");
            return;
        }

        uint8_t cc = 0;
        uint8_t fru_data_major_version, fru_data_minor_version;
        uint32_t fru_table_maximum_size, fru_table_length;
        uint16_t total_record_set_identifiers;
        uint16_t total;
        uint32_t checksum;

        auto rc = decode_get_fru_record_table_metadata_resp(
            response, respMsgLen, &cc, &fru_data_major_version,
            &fru_data_minor_version, &fru_table_maximum_size, &fru_table_length,
            &total_record_set_identifiers, &total, &checksum);

        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            error(
                "Failed to decode get fru record table metadata response, response code '{RC}' and completion code '{CC}'",
                "RC", lg2::hex, rc, "CC", cc);
            return;
        }

        // pass total to getFRURecordTableByRemote
        this->getFRURecordTableByRemote(fruRecordSetPDRs, total);
    };

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_FRU, PLDM_GET_FRU_RECORD_TABLE_METADATA,
        std::move(requestMsg),
        std::move(getFruRecordTableMetadataResponseHandler));
    if (rc != PLDM_SUCCESS)
    {
        error(
            "Failed to send the the set state effecter states request, response code '{RC}'",
            "RC", rc);
    }

    return;
}

void HostPDRHandler::getFRURecordTableByRemote(const PDRList& fruRecordSetPDRs,
                                               uint16_t totalTableRecords)
{
    fruRecordData.clear();

    if (!totalTableRecords)
    {
        error("Failed to get fru record table");
        return;
    }

    auto instanceId = instanceIdDb.next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES);

    // send the getFruRecordTable command
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    auto rc = encode_get_fru_record_table_req(
        instanceId, 0, PLDM_GET_FIRSTPART, request,
        requestMsg.size() - sizeof(pldm_msg_hdr));
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb.free(mctp_eid, instanceId);
        error(
            "Failed to encode get fru record table request, response code '{RC}'",
            "RC", lg2::hex, rc);
        return;
    }

    auto getFruRecordTableResponseHandler = [totalTableRecords, this,
                                             fruRecordSetPDRs](
                                                mctp_eid_t /*eid*/,
                                                const pldm_msg* response,
                                                size_t respMsgLen) {
        if (response == nullptr || !respMsgLen)
        {
            error("Failed to receive response for the get fru record table");
            return;
        }

        uint8_t cc = 0;
        uint32_t next_data_transfer_handle = 0;
        uint8_t transfer_flag = 0;
        size_t fru_record_table_length = 0;
        std::vector<uint8_t> fru_record_table_data(
            respMsgLen - sizeof(pldm_msg_hdr));
        auto responsePtr = reinterpret_cast<const struct pldm_msg*>(response);
        auto rc = decode_get_fru_record_table_resp(
            responsePtr, respMsgLen, &cc, &next_data_transfer_handle,
            &transfer_flag, fru_record_table_data.data(),
            &fru_record_table_length);

        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            error(
                "Failed to decode get fru record table resp, response code '{RC}' and completion code '{CC}'",
                "RC", lg2::hex, rc, "CC", cc);
            return;
        }

        fruRecordData = responder::pdr_utils::parseFruRecordTable(
            fru_record_table_data.data(), fru_record_table_length);

        if (totalTableRecords != fruRecordData.size())
        {
            fruRecordData.clear();

            error("Failed to parse fru record data format.");
            return;
        }

        this->setFRUDataOnDBus(fruRecordSetPDRs, fruRecordData);
    };

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_FRU, PLDM_GET_FRU_RECORD_TABLE,
        std::move(requestMsg), std::move(getFruRecordTableResponseHandler));
    if (rc != PLDM_SUCCESS)
    {
        error("Failed to send the the set state effecter states request");
    }
}

std::optional<uint16_t> HostPDRHandler::getRSI(const PDRList& fruRecordSetPDRs,
                                               const pldm_entity& entity)
{
    for (const auto& pdr : fruRecordSetPDRs)
    {
        auto fruPdr = reinterpret_cast<const pldm_pdr_fru_record_set*>(
            const_cast<uint8_t*>(pdr.data()) + sizeof(pldm_pdr_hdr));

        if (fruPdr->entity_type == entity.entity_type &&
            fruPdr->entity_instance == entity.entity_instance_num &&
            fruPdr->container_id == entity.entity_container_id)
        {
            return fruPdr->fru_rsi;
        }
    }

    return std::nullopt;
}

void HostPDRHandler::setFRUDataOnDBus(
    [[maybe_unused]] const PDRList& fruRecordSetPDRs,
    [[maybe_unused]] const std::vector<
        responder::pdr_utils::FruRecordDataFormat>& fruRecordData)
{
#ifdef OEM_IBM
    for (const auto& entity : objPathMap)
    {
        pldm_entity node = pldm_entity_extract(entity.second);
        auto fruRSI = getRSI(fruRecordSetPDRs, node);

        for (const auto& data : fruRecordData)
        {
            if (!fruRSI || *fruRSI != data.fruRSI)
            {
                continue;
            }

            if (data.fruRecType == PLDM_FRU_RECORD_TYPE_OEM)
            {
                for (const auto& tlv : data.fruTLV)
                {
                    if (tlv.fruFieldType ==
                        PLDM_OEM_FRU_FIELD_TYPE_LOCATION_CODE)
                    {
                        CustomDBus::getCustomDBus().setLocationCode(
                            entity.first,
                            std::string(reinterpret_cast<const char*>(
                                            tlv.fruFieldValue.data()),
                                        tlv.fruFieldLen));
                    }
                }
            }
        }
    }
#endif
}
void HostPDRHandler::createDbusObjects(const PDRList& fruRecordSetPDRs)
{
    // TODO: Creating and Refreshing dbus hosted by remote PLDM entity Fru PDRs
    for (const auto& entity : objPathMap)
    {
        pldm_entity node = pldm_entity_extract(entity.second);
        switch (node.entity_type)
        {
            case PLDM_ENTITY_PROC | 0x8000:
                CustomDBus::getCustomDBus().implementCpuCoreInterface(
                    entity.first);
                break;
            case PLDM_ENTITY_SLOT:
                CustomDBus::getCustomDBus().implementPCIeSlotInterface(
                    entity.first);
                break;
            case PLDM_ENTITY_CARD:
                CustomDBus::getCustomDBus().implementPCIeDeviceInterface(
                    entity.first);
                break;
            case PLDM_ENTITY_SYS_BOARD:
                CustomDBus::getCustomDBus().implementMotherboardInterface(
                    entity.first);
                break;
            default:
                break;
        }
    }
    getFRURecordTableMetadataByRemote(fruRecordSetPDRs);
}

} // namespace pldm
