
#include "platform.hpp"

#include "common/types.hpp"
#include "common/utils.hpp"
#include "event_parser.hpp"
#include "pdr.hpp"
#include "pdr_numeric_effecter.hpp"
#include "pdr_state_effecter.hpp"
#include "pdr_state_sensor.hpp"
#include "pdr_utils.hpp"
#include "platform_numeric_effecter.hpp"
#include "platform_state_effecter.hpp"
#include "platform_state_sensor.hpp"

namespace pldm
{
namespace responder
{
namespace platform
{

using InternalFailure =
    sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure;

static const Json empty{};

void Handler::addDbusObjMaps(
    uint16_t id,
    std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps> dbusObj,
    TypeId typeId)
{
    if (typeId == TypeId::PLDM_SENSOR_ID)
    {
        sensorDbusObjMaps.emplace(id, dbusObj);
    }
    else
    {
        effecterDbusObjMaps.emplace(id, dbusObj);
    }
}

const std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps>&
    Handler::getDbusObjMaps(uint16_t id, TypeId typeId) const
{
    if (typeId == TypeId::PLDM_SENSOR_ID)
    {
        return sensorDbusObjMaps.at(id);
    }
    else
    {
        return effecterDbusObjMaps.at(id);
    }
}

void Handler::generate(const pldm::utils::DBusHandler& dBusIntf,
                       const std::string& dir, Repo& repo)
{
    if (!fs::exists(dir))
    {
        return;
    }

    // A map of PDR type to a lambda that handles creation of that PDR type.
    // The lambda essentially would parse the platform specific PDR JSONs to
    // generate the PDR structures. This function iterates through the map to
    // invoke all lambdas, so that all PDR types can be created.

    const std::map<Type, generatePDR> generateHandlers = {
        {PLDM_STATE_EFFECTER_PDR,
         [this](const DBusHandler& dBusIntf, const auto& json,
                RepoInterface& repo) {
             pdr_state_effecter::generateStateEffecterPDR<
                 pldm::utils::DBusHandler, Handler>(dBusIntf, json, *this,
                                                    repo);
         }},
        {PLDM_NUMERIC_EFFECTER_PDR,
         [this](const DBusHandler& dBusIntf, const auto& json,
                RepoInterface& repo) {
             pdr_numeric_effecter::generateNumericEffecterPDR<
                 pldm::utils::DBusHandler, Handler>(dBusIntf, json, *this,
                                                    repo);
         }},
        {PLDM_STATE_SENSOR_PDR, [this](const DBusHandler& dBusIntf,
                                       const auto& json, RepoInterface& repo) {
             pdr_state_sensor::generateStateSensorPDR<pldm::utils::DBusHandler,
                                                      Handler>(dBusIntf, json,
                                                               *this, repo);
         }}};

    Type pdrType{};
    for (const auto& dirEntry : fs::directory_iterator(dir))
    {
        try
        {
            auto json = readJson(dirEntry.path().string());
            if (!json.empty())
            {
                auto effecterPDRs = json.value("effecterPDRs", empty);
                for (const auto& effecter : effecterPDRs)
                {
                    pdrType = effecter.value("pdrType", 0);
                    generateHandlers.at(pdrType)(dBusIntf, effecter, repo);
                }

                auto sensorPDRs = json.value("sensorPDRs", empty);
                for (const auto& sensor : sensorPDRs)
                {
                    pdrType = sensor.value("pdrType", 0);
                    generateHandlers.at(pdrType)(dBusIntf, sensor, repo);
                }
            }
        }
        catch (const InternalFailure& e)
        {
            std::cerr << "PDR config directory does not exist or empty, TYPE= "
                      << pdrType << "PATH= " << dirEntry
                      << " ERROR=" << e.what() << "\n";
        }
        catch (const Json::exception& e)
        {
            std::cerr << "Failed parsing PDR JSON file, TYPE= " << pdrType
                      << " ERROR=" << e.what() << "\n";
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed parsing PDR JSON file, TYPE= " << pdrType
                      << " ERROR=" << e.what() << "\n";
            pldm::utils::reportError(
                "xyz.openbmc_project.bmc.pldm.InternalFailure");
        }
    }
}

Response Handler::getPDR(const pldm_msg* request, size_t payloadLength)
{
    // Build FRU table if not built, since entity association PDR's are built
    // when the FRU table is constructed.
    if (fruHandler)
    {
        fruHandler->buildFRUTable();
    }

    if (!pdrCreated)
    {
        generateTerminusLocatorPDR(pdrRepo);
        generate(*dBusIntf, pdrJsonsDir, pdrRepo);
        pdrCreated = true;
    }

    Response response(sizeof(pldm_msg_hdr) + PLDM_GET_PDR_MIN_RESP_BYTES, 0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());

    if (payloadLength != PLDM_GET_PDR_REQ_BYTES)
    {
        return CmdHandler::ccOnlyResponse(request, PLDM_ERROR_INVALID_LENGTH);
    }

    uint32_t recordHandle{};
    uint32_t dataTransferHandle{};
    uint8_t transferOpFlag{};
    uint16_t reqSizeBytes{};
    uint16_t recordChangeNum{};

    auto rc = decode_get_pdr_req(request, payloadLength, &recordHandle,
                                 &dataTransferHandle, &transferOpFlag,
                                 &reqSizeBytes, &recordChangeNum);
    if (rc != PLDM_SUCCESS)
    {
        return CmdHandler::ccOnlyResponse(request, rc);
    }

    uint16_t respSizeBytes{};
    uint8_t* recordData = nullptr;
    try
    {
        pdr_utils::PdrEntry e;
        auto record = pdr::getRecordByHandle(pdrRepo, recordHandle, e);
        if (record == NULL)
        {
            return CmdHandler::ccOnlyResponse(
                request, PLDM_PLATFORM_INVALID_RECORD_HANDLE);
        }

        if (reqSizeBytes)
        {
            respSizeBytes = e.size;
            if (respSizeBytes > reqSizeBytes)
            {
                respSizeBytes = reqSizeBytes;
            }
            recordData = e.data;
        }
        response.resize(sizeof(pldm_msg_hdr) + PLDM_GET_PDR_MIN_RESP_BYTES +
                            respSizeBytes,
                        0);
        responsePtr = reinterpret_cast<pldm_msg*>(response.data());
        rc = encode_get_pdr_resp(
            request->hdr.instance_id, PLDM_SUCCESS, e.handle.nextRecordHandle,
            0, PLDM_START_AND_END, respSizeBytes, recordData, 0, responsePtr);
        if (rc != PLDM_SUCCESS)
        {
            return ccOnlyResponse(request, rc);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error accessing PDR, HANDLE=" << recordHandle
                  << " ERROR=" << e.what() << "\n";
        return CmdHandler::ccOnlyResponse(request, PLDM_ERROR);
    }
    return response;
}

Response Handler::setStateEffecterStates(const pldm_msg* request,
                                         size_t payloadLength)
{
    Response response(
        sizeof(pldm_msg_hdr) + PLDM_SET_STATE_EFFECTER_STATES_RESP_BYTES, 0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());
    uint16_t effecterId;
    uint8_t compEffecterCnt;
    constexpr auto maxCompositeEffecterCnt = 8;
    std::vector<set_effecter_state_field> stateField(maxCompositeEffecterCnt,
                                                     {0, 0});

    if ((payloadLength > PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES) ||
        (payloadLength < sizeof(effecterId) + sizeof(compEffecterCnt) +
                             sizeof(set_effecter_state_field)))
    {
        return CmdHandler::ccOnlyResponse(request, PLDM_ERROR_INVALID_LENGTH);
    }

    int rc = decode_set_state_effecter_states_req(request, payloadLength,
                                                  &effecterId, &compEffecterCnt,
                                                  stateField.data());

    if (rc != PLDM_SUCCESS)
    {
        return CmdHandler::ccOnlyResponse(request, rc);
    }

    stateField.resize(compEffecterCnt);
    const pldm::utils::DBusHandler dBusIntf;
    rc = platform_state_effecter::setStateEffecterStatesHandler<
        pldm::utils::DBusHandler, Handler>(dBusIntf, *this, effecterId,
                                           stateField);
    if (rc != PLDM_SUCCESS)
    {
        return CmdHandler::ccOnlyResponse(request, rc);
    }

    rc = encode_set_state_effecter_states_resp(request->hdr.instance_id, rc,
                                               responsePtr);
    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    return response;
}

Response Handler::platformEventMessage(const pldm_msg* request,
                                       size_t payloadLength)
{
    uint8_t formatVersion{};
    uint8_t tid{};
    uint8_t eventClass{};
    size_t offset{};

    auto rc = decode_platform_event_message_req(
        request, payloadLength, &formatVersion, &tid, &eventClass, &offset);
    if (rc != PLDM_SUCCESS)
    {
        return CmdHandler::ccOnlyResponse(request, rc);
    }

    try
    {
        const auto& handlers = eventHandlers.at(eventClass);
        for (const auto& handler : handlers)
        {
            auto rc =
                handler(request, payloadLength, formatVersion, tid, offset);
            if (rc != PLDM_SUCCESS)
            {
                return CmdHandler::ccOnlyResponse(request, rc);
            }
        }
    }
    catch (const std::out_of_range& e)
    {
        return CmdHandler::ccOnlyResponse(request, PLDM_ERROR_INVALID_DATA);
    }

    Response response(
        sizeof(pldm_msg_hdr) + PLDM_PLATFORM_EVENT_MESSAGE_RESP_BYTES, 0);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());

    rc = encode_platform_event_message_resp(request->hdr.instance_id, rc,
                                            PLDM_EVENT_NO_LOGGING, responsePtr);
    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    return response;
}

int Handler::sensorEvent(const pldm_msg* request, size_t payloadLength,
                         uint8_t /*formatVersion*/, uint8_t tid,
                         size_t eventDataOffset)
{
    uint16_t sensorId{};
    uint8_t eventClass{};
    size_t eventClassDataOffset{};
    auto eventData =
        reinterpret_cast<const uint8_t*>(request->payload) + eventDataOffset;
    auto eventDataSize = payloadLength - eventDataOffset;

    auto rc = decode_sensor_event_data(eventData, eventDataSize, &sensorId,
                                       &eventClass, &eventClassDataOffset);
    if (rc != PLDM_SUCCESS)
    {
        return rc;
    }

    auto eventClassData = reinterpret_cast<const uint8_t*>(request->payload) +
                          eventDataOffset + eventClassDataOffset;
    auto eventClassDataSize =
        payloadLength - eventDataOffset - eventClassDataOffset;

    if (eventClass == PLDM_STATE_SENSOR_STATE)
    {
        uint8_t sensorOffset{};
        uint8_t eventState{};
        uint8_t previousEventState{};

        rc = decode_state_sensor_data(eventClassData, eventClassDataSize,
                                      &sensorOffset, &eventState,
                                      &previousEventState);
        if (rc != PLDM_SUCCESS)
        {
            return PLDM_ERROR;
        }

        // Emitting state sensor event signal
        emitStateSensorEventSignal(tid, sensorId, sensorOffset, eventState,
                                   previousEventState);

        // If there are no HOST PDR's, there is no further action
        if (hostPDRHandler == NULL)
        {
            return PLDM_SUCCESS;
        }

        // Handle PLDM events for which PDR is available
        SensorEntry sensorEntry{tid, sensorId};

        pldm::pdr::EntityInfo entityInfo{};
        pldm::pdr::CompositeSensorStates compositeSensorStates{};

        try
        {
            std::tie(entityInfo, compositeSensorStates) =
                hostPDRHandler->lookupSensorInfo(sensorEntry);
        }
        catch (const std::out_of_range& e)
        {
            // If there is no mapping for tid, sensorId combination, try
            // PLDM_TID_RESERVED, sensorId for terminus that is yet to
            // implement TL PDR.
            try
            {
                sensorEntry.terminusID = PLDM_TID_RESERVED;
                std::tie(entityInfo, compositeSensorStates) =
                    hostPDRHandler->lookupSensorInfo(sensorEntry);
            }
            // If there is no mapping for events return PLDM_SUCCESS
            catch (const std::out_of_range& e)
            {
                return PLDM_SUCCESS;
            }
        }

        if (sensorOffset >= compositeSensorStates.size())
        {
            return PLDM_ERROR_INVALID_DATA;
        }

        const auto& possibleStates = compositeSensorStates[sensorOffset];
        if (possibleStates.find(eventState) == possibleStates.end())
        {
            return PLDM_ERROR_INVALID_DATA;
        }

        const auto& [containerId, entityType, entityInstance] = entityInfo;
        events::StateSensorEntry stateSensorEntry{containerId, entityType,
                                                  entityInstance, sensorOffset};
        return stateSensorHandler.eventAction(stateSensorEntry, eventState);
    }
    else
    {
        return PLDM_ERROR_INVALID_DATA;
    }

    return PLDM_SUCCESS;
}

int Handler::pldmPDRRepositoryChgEvent(const pldm_msg* request,
                                       size_t payloadLength,
                                       uint8_t /*formatVersion*/,
                                       uint8_t /*tid*/, size_t eventDataOffset)
{
    uint8_t eventDataFormat{};
    uint8_t numberOfChangeRecords{};
    size_t dataOffset{};

    auto eventData =
        reinterpret_cast<const uint8_t*>(request->payload) + eventDataOffset;
    auto eventDataSize = payloadLength - eventDataOffset;

    auto rc = decode_pldm_pdr_repository_chg_event_data(
        eventData, eventDataSize, &eventDataFormat, &numberOfChangeRecords,
        &dataOffset);
    if (rc != PLDM_SUCCESS)
    {
        return rc;
    }

    PDRRecordHandles pdrRecordHandles;

    if (eventDataFormat == FORMAT_IS_PDR_TYPES)
    {
        return PLDM_ERROR_INVALID_DATA;
    }

    if (eventDataFormat == FORMAT_IS_PDR_HANDLES)
    {
        uint8_t eventDataOperation{};
        uint8_t numberOfChangeEntries{};

        auto changeRecordData = eventData + dataOffset;
        auto changeRecordDataSize = eventDataSize - dataOffset;

        while (changeRecordDataSize)
        {
            rc = decode_pldm_pdr_repository_change_record_data(
                changeRecordData, changeRecordDataSize, &eventDataOperation,
                &numberOfChangeEntries, &dataOffset);

            if (rc != PLDM_SUCCESS)
            {
                return rc;
            }

            if (eventDataOperation == PLDM_RECORDS_ADDED)
            {
                rc = getPDRRecordHandles(
                    reinterpret_cast<const ChangeEntry*>(changeRecordData +
                                                         dataOffset),
                    changeRecordDataSize - dataOffset,
                    static_cast<size_t>(numberOfChangeEntries),
                    pdrRecordHandles);

                if (rc != PLDM_SUCCESS)
                {
                    return rc;
                }
            }

            changeRecordData +=
                dataOffset + (numberOfChangeEntries * sizeof(ChangeEntry));
            changeRecordDataSize -=
                dataOffset + (numberOfChangeEntries * sizeof(ChangeEntry));
        }
    }
    if (hostPDRHandler)
    {
        hostPDRHandler->fetchPDR(std::move(pdrRecordHandles));
    }

    return PLDM_SUCCESS;
}

int Handler::getPDRRecordHandles(const ChangeEntry* changeEntryData,
                                 size_t changeEntryDataSize,
                                 size_t numberOfChangeEntries,
                                 PDRRecordHandles& pdrRecordHandles)
{
    if (numberOfChangeEntries > (changeEntryDataSize / sizeof(ChangeEntry)))
    {
        return PLDM_ERROR_INVALID_DATA;
    }
    for (size_t i = 0; i < numberOfChangeEntries; i++)
    {
        pdrRecordHandles.push_back(changeEntryData[i]);
    }
    return PLDM_SUCCESS;
}

Response Handler::setNumericEffecterValue(const pldm_msg* request,
                                          size_t payloadLength)
{
    Response response(sizeof(pldm_msg_hdr) +
                      PLDM_SET_NUMERIC_EFFECTER_VALUE_RESP_BYTES);
    uint16_t effecterId{};
    uint8_t effecterDataSize{};
    uint8_t effecterValue[4] = {};

    if ((payloadLength > sizeof(effecterId) + sizeof(effecterDataSize) +
                             sizeof(union_effecter_data_size)) ||
        (payloadLength < sizeof(effecterId) + sizeof(effecterDataSize) + 1))
    {
        return ccOnlyResponse(request, PLDM_ERROR_INVALID_LENGTH);
    }

    int rc = decode_set_numeric_effecter_value_req(
        request, payloadLength, &effecterId, &effecterDataSize,
        reinterpret_cast<uint8_t*>(&effecterValue));

    if (rc == PLDM_SUCCESS)
    {
        const pldm::utils::DBusHandler dBusIntf;
        rc = platform_numeric_effecter::setNumericEffecterValueHandler<
            pldm::utils::DBusHandler, Handler>(dBusIntf, *this, effecterId,
                                               effecterDataSize, effecterValue,
                                               sizeof(effecterValue));
    }

    return ccOnlyResponse(request, rc);
}

void Handler::generateTerminusLocatorPDR(Repo& repo)
{
    std::vector<uint8_t> pdrBuffer(sizeof(pldm_terminus_locator_pdr));

    auto pdr = reinterpret_cast<pldm_terminus_locator_pdr*>(pdrBuffer.data());

    pdr->hdr.record_handle = 0;
    pdr->hdr.version = 1;
    pdr->hdr.type = PLDM_TERMINUS_LOCATOR_PDR;
    pdr->hdr.record_change_num = 0;
    pdr->hdr.length = sizeof(pldm_terminus_locator_pdr) - sizeof(pldm_pdr_hdr);
    pdr->terminus_handle = BmcPldmTerminusHandle;
    pdr->validity = PLDM_TL_PDR_VALID;
    pdr->tid = BmcTerminusId;
    pdr->container_id = 0x0;
    pdr->terminus_locator_type = PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID;
    pdr->terminus_locator_value_size =
        sizeof(pldm_terminus_locator_type_mctp_eid);
    auto locatorValue = reinterpret_cast<pldm_terminus_locator_type_mctp_eid*>(
        pdr->terminus_locator_value);
    locatorValue->eid = BmcMctpEid;

    PdrEntry pdrEntry{};
    pdrEntry.data = pdrBuffer.data();
    pdrEntry.size = pdrBuffer.size();
    repo.addRecord(pdrEntry);
}

Response Handler::getStateSensorReadings(const pldm_msg* request,
                                         size_t payloadLength)
{
    uint16_t sensorId{};
    bitfield8_t sensorRearm{};
    uint8_t reserved{};

    if (payloadLength != PLDM_GET_SENSOR_READING_REQ_BYTES)
    {
        return ccOnlyResponse(request, PLDM_ERROR_INVALID_LENGTH);
    }

    int rc = decode_get_state_sensor_readings_req(
        request, payloadLength, &sensorId, &sensorRearm, &reserved);

    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    // 0x01 to 0x08
    uint8_t sensorRearmCout = getBitfieldCount(sensorRearm);
    std::vector<get_sensor_state_field> stateField(sensorRearmCout);
    uint8_t comSensorCnt{};
    const pldm::utils::DBusHandler dBusIntf;
    rc = platform_state_sensor::getStateSensorReadingsHandler<
        pldm::utils::DBusHandler, Handler>(
        dBusIntf, *this, sensorId, sensorRearmCout, comSensorCnt, stateField);

    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    Response response(sizeof(pldm_msg_hdr) +
                      PLDM_GET_STATE_SENSOR_READINGS_MIN_RESP_BYTES +
                      sizeof(get_sensor_state_field) * comSensorCnt);
    auto responsePtr = reinterpret_cast<pldm_msg*>(response.data());
    rc = encode_get_state_sensor_readings_resp(request->hdr.instance_id, rc,
                                               comSensorCnt, stateField.data(),
                                               responsePtr);
    if (rc != PLDM_SUCCESS)
    {
        return ccOnlyResponse(request, rc);
    }

    return response;
}

} // namespace platform
} // namespace responder
} // namespace pldm
