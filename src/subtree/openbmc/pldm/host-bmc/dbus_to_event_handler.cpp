#include "dbus_to_event_handler.hpp"

#include "libpldm/requester/pldm.h"

#include "libpldmresponder/pdr.hpp"

namespace pldm
{

using namespace pldm::responder::pdr;
using namespace pldm::utils;
using namespace sdbusplus::bus::match::rules;

namespace state_sensor
{
const std::vector<uint8_t> pdrTypes{PLDM_STATE_SENSOR_PDR};

DbusToPLDMEvent::DbusToPLDMEvent(int mctp_fd, uint8_t mctp_eid,
                                 Requester& requester) :
    mctp_fd(mctp_fd),
    mctp_eid(mctp_eid), requester(requester)
{}

void DbusToPLDMEvent::sendEventMsg(uint8_t eventType,
                                   const std::vector<uint8_t>& eventDataVec)
{
    auto instanceId = requester.getInstanceId(mctp_eid);
    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
                                    eventDataVec.size());
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_platform_event_message_req(
        instanceId, 1 /*formatVersion*/, 0 /*tId*/, eventType,
        eventDataVec.data(), eventDataVec.size(), request,
        eventDataVec.size() + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES);
    if (rc != PLDM_SUCCESS)
    {
        requester.markFree(mctp_eid, instanceId);
        std::cerr << "Failed to encode_platform_event_message_req, rc = " << rc
                  << std::endl;
        return;
    }

    uint8_t* responseMsg = nullptr;
    size_t responseMsgSize{};

    auto requesterRc =
        pldm_send_recv(mctp_eid, mctp_fd, requestMsg.data(), requestMsg.size(),
                       &responseMsg, &responseMsgSize);
    std::unique_ptr<uint8_t, decltype(std::free)*> responseMsgPtr{responseMsg,
                                                                  std::free};

    requester.markFree(mctp_eid, instanceId);
    if (requesterRc != PLDM_REQUESTER_SUCCESS)
    {
        std::cerr
            << "Failed to send msg to report state sensor event changes, rc = "
            << requesterRc << std::endl;
        return;
    }
    uint8_t completionCode{};
    uint8_t status{};
    auto responsePtr = reinterpret_cast<struct pldm_msg*>(responseMsgPtr.get());
    rc = decode_platform_event_message_resp(
        responsePtr, responseMsgSize - sizeof(pldm_msg_hdr), &completionCode,
        &status);

    if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
    {
        std::cerr << "Failed to decode_platform_event_message_resp: "
                  << "rc=" << rc
                  << ", cc=" << static_cast<unsigned>(completionCode)
                  << std::endl;
    }
}

void DbusToPLDMEvent::sendStateSensorEvent(SensorId sensorId,
                                           const DbusObjMaps& dbusMaps)
{
    // Encode PLDM platform event msg to indicate a state sensor change.
    // DSP0248_1.2.0 Table 19
    size_t sensorEventSize = PLDM_SENSOR_EVENT_DATA_MIN_LENGTH + 1;
    const auto& [dbusMappings, dbusValMaps] = dbusMaps.at(sensorId);
    for (uint8_t offset = 0; offset < dbusMappings.size(); ++offset)
    {
        std::vector<uint8_t> sensorEventDataVec{};
        sensorEventDataVec.resize(sensorEventSize);
        auto eventData = reinterpret_cast<struct pldm_sensor_event_data*>(
            sensorEventDataVec.data());
        eventData->sensor_id = sensorId;
        eventData->sensor_event_class_type = PLDM_STATE_SENSOR_STATE;
        eventData->event_class[0] = offset;
        eventData->event_class[1] = PLDM_SENSOR_UNKNOWN;
        eventData->event_class[2] = PLDM_SENSOR_UNKNOWN;

        const auto& dbusMapping = dbusMappings[offset];
        const auto& dbusValueMapping = dbusValMaps[offset];
        auto stateSensorMatch = std::make_unique<sdbusplus::bus::match::match>(
            pldm::utils::DBusHandler::getBus(),
            propertiesChanged(dbusMapping.objectPath.c_str(),
                              dbusMapping.interface.c_str()),
            [this, sensorEventDataVec, dbusValueMapping](auto& msg) mutable {
                DbusChangedProps props{};
                std::string intf;
                msg.read(intf, props);
                const auto& first = props.begin();
                for (const auto& itr : dbusValueMapping)
                {
                    if (itr.second == first->second)
                    {
                        auto eventData =
                            reinterpret_cast<struct pldm_sensor_event_data*>(
                                sensorEventDataVec.data());
                        eventData->event_class[1] = itr.first;
                        eventData->event_class[2] = itr.first;
                        this->sendEventMsg(PLDM_SENSOR_EVENT,
                                           sensorEventDataVec);
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
            sensorHandlers.at(pdrType)(sensorId, dbusMaps);
            pdrRecord = sensorPDRs.getNextRecord(pdrRecord, pdrEntry);
        }
    }
}

} // namespace state_sensor
} // namespace pldm
