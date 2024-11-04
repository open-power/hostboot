#include "dbus_to_event_handler.hpp"

#include "libpldmresponder/pdr.hpp"

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

namespace pldm
{
using namespace pldm::responder;
using namespace pldm::responder::pdr;
using namespace pldm::responder::pdr_utils;
using namespace pldm::utils;
using namespace sdbusplus::bus::match::rules;

namespace state_sensor
{
const std::vector<uint8_t> pdrTypes{PLDM_STATE_SENSOR_PDR};

DbusToPLDMEvent::DbusToPLDMEvent(
    int /* mctp_fd */, uint8_t mctp_eid, pldm::InstanceIdDb& instanceIdDb,
    pldm::requester::Handler<pldm::requester::Request>* handler) :
    mctp_eid(mctp_eid), instanceIdDb(instanceIdDb), handler(handler)
{}

void DbusToPLDMEvent::sendEventMsg(uint8_t eventType,
                                   const std::vector<uint8_t>& eventDataVec)
{
    auto instanceId = instanceIdDb.next(mctp_eid);
    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
        eventDataVec.size());
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_platform_event_message_req(
        instanceId, 1 /*formatVersion*/, TERMINUS_ID /*tId*/, eventType,
        eventDataVec.data(), eventDataVec.size(), request,
        eventDataVec.size() + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES);
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
            error("Failed to receive response for platform event message");
            return;
        }
        uint8_t completionCode{};
        uint8_t status{};
        auto rc = decode_platform_event_message_resp(response, respMsgLen,
                                                     &completionCode, &status);
        if (rc || completionCode)
        {
            error(
                "Failed to decode response of platform event message, response code '{RC}' and completion code '{CC}'",
                "RC", rc, "CC", completionCode);
        }
    };

    rc = handler->registerRequest(
        mctp_eid, instanceId, PLDM_PLATFORM, PLDM_PLATFORM_EVENT_MESSAGE,
        std::move(requestMsg), std::move(platformEventMessageResponseHandler));
    if (rc)
    {
        error("Failed to send the platform event message, response code '{RC}'",
              "RC", rc);
    }
}

void DbusToPLDMEvent::sendStateSensorEvent(SensorId sensorId,
                                           const DbusObjMaps& dbusMaps)
{
    // Encode PLDM platform event msg to indicate a state sensor change.
    // DSP0248_1.2.0 Table 19
    if (!dbusMaps.contains(sensorId))
    {
        // this is not an error condition, if we end up here
        // that means that the sensor with the sensor id has
        // custom behaviour(or probably an oem sensor) in
        // sending events that cannot be captured via standard
        // dbus-json infastructure
        return;
    }

    size_t sensorEventSize = PLDM_SENSOR_EVENT_DATA_MIN_LENGTH + 1;
    const auto& [dbusMappings, dbusValMaps] = dbusMaps.at(sensorId);
    for (size_t offset = 0; offset < dbusMappings.size(); ++offset)
    {
        std::vector<uint8_t> sensorEventDataVec{};
        sensorEventDataVec.resize(sensorEventSize);
        auto eventData = reinterpret_cast<struct pldm_sensor_event_data*>(
            sensorEventDataVec.data());
        eventData->sensor_id = sensorId;
        eventData->sensor_event_class_type = PLDM_STATE_SENSOR_STATE;
        eventData->event_class[0] = static_cast<uint8_t>(offset);
        eventData->event_class[1] = PLDM_SENSOR_UNKNOWN;
        eventData->event_class[2] = PLDM_SENSOR_UNKNOWN;

        const auto& dbusMapping = dbusMappings[offset];
        const auto& dbusValueMapping = dbusValMaps[offset];
        auto stateSensorMatch = std::make_unique<sdbusplus::bus::match_t>(
            pldm::utils::DBusHandler::getBus(),
            propertiesChanged(dbusMapping.objectPath.c_str(),
                              dbusMapping.interface.c_str()),
            [this, sensorEventDataVec, dbusValueMapping, dbusMapping, sensorId,
             offset](auto& msg) mutable {
                DbusChangedProps props{};
                std::string intf;
                uint8_t previousState = PLDM_SENSOR_UNKNOWN;
                msg.read(intf, props);
                if (!props.contains(dbusMapping.propertyName))
                {
                    return;
                }
                for (const auto& itr : dbusValueMapping)
                {
                    bool findValue = false;
                    if (dbusMapping.propertyType == "string")
                    {
                        std::string src = std::get<std::string>(itr.second);
                        std::string dst = std::get<std::string>(
                            props.at(dbusMapping.propertyName));

                        auto values = pldm::utils::split(src, "||", " ");
                        for (const auto& value : values)
                        {
                            if (value == dst)
                            {
                                findValue = true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        findValue =
                            itr.second == props.at(dbusMapping.propertyName)
                                ? true
                                : false;
                    }

                    if (findValue)
                    {
                        auto eventData =
                            reinterpret_cast<struct pldm_sensor_event_data*>(
                                sensorEventDataVec.data());
                        eventData->event_class[1] = itr.first;
                        if (sensorCacheMap.contains(sensorId) &&
                            sensorCacheMap[sensorId][offset] !=
                                PLDM_SENSOR_UNKNOWN)
                        {
                            previousState = sensorCacheMap[sensorId][offset];
                        }
                        else
                        {
                            previousState = itr.first;
                        }
                        eventData->event_class[2] = previousState;
                        this->sendEventMsg(PLDM_SENSOR_EVENT,
                                           sensorEventDataVec);
                        updateSensorCacheMaps(sensorId, offset, previousState);
                        break;
                    }
                }
            });
        stateSensorMatchs.emplace_back(std::move(stateSensorMatch));
    }
}

void DbusToPLDMEvent::listenSensorEvent(const pdr_utils::Repo& repo,
                                        const DbusObjMaps& dbusMaps)
{
    const std::map<Type, sensorEvent> sensorHandlers = {
        {PLDM_STATE_SENSOR_PDR,
         [this](SensorId sensorId, const DbusObjMaps& dbusMaps) {
             this->sendStateSensorEvent(sensorId, dbusMaps);
         }}};

    pldm_state_sensor_pdr* pdr = nullptr;
    std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)> sensorPdrRepo(
        pldm_pdr_init(), pldm_pdr_destroy);
    if (!sensorPdrRepo)
    {
        throw std::runtime_error("Unable to instantiate sensor PDR repository");
    }

    for (auto pdrType : pdrTypes)
    {
        Repo sensorPDRs(sensorPdrRepo.get());
        getRepoByType(repo, sensorPDRs, pdrType);
        if (sensorPDRs.empty())
        {
            return;
        }

        PdrEntry pdrEntry{};
        auto pdrRecord = sensorPDRs.getFirstRecord(pdrEntry);
        while (pdrRecord)
        {
            pdr = reinterpret_cast<pldm_state_sensor_pdr*>(pdrEntry.data);
            SensorId sensorId = LE16TOH(pdr->sensor_id);
            if (sensorHandlers.contains(pdrType))
            {
                sensorHandlers.at(pdrType)(sensorId, dbusMaps);
            }

            pdrRecord = sensorPDRs.getNextRecord(pdrRecord, pdrEntry);
        }
    }
}

} // namespace state_sensor
} // namespace pldm
