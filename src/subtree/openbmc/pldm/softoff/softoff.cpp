#include "softoff.hpp"

#include "common/instance_id.hpp"
#include "common/transport.hpp"
#include "common/utils.hpp"

#include <libpldm/entity.h>
#include <libpldm/platform.h>
#include <libpldm/state_set.h>

#include <phosphor-logging/lg2.hpp>
#include <sdbusplus/bus.hpp>
#include <sdeventplus/clock.hpp>
#include <sdeventplus/exception.hpp>
#include <sdeventplus/source/io.hpp>
#include <sdeventplus/source/time.hpp>

#include <array>
#include <filesystem>
#include <fstream>

PHOSPHOR_LOG2_USING;

namespace pldm
{
using namespace sdeventplus;
using namespace sdeventplus::source;
namespace fs = std::filesystem;
constexpr auto clockId = sdeventplus::ClockId::RealTime;
using Clock = Clock<clockId>;
using Timer = Time<clockId>;

using sdbusplus::exception::SdBusError;

// Shutdown effecter terminus ID, set when we look up the effecter
pldm::pdr::TerminusID TID = 0;

namespace sdbusRule = sdbusplus::bus::match::rules;

SoftPowerOff::SoftPowerOff(sdbusplus::bus_t& bus, sd_event* event,
                           pldm::InstanceIdDb& instanceIdDb) :
    bus(bus), timer(event), instanceIdDb(instanceIdDb)
{
    auto jsonData = parseConfig();

    if (jsonData.is_discarded())
    {
        error("Failed to parse softoff config JSON file");
        return;
    }

    getHostState();
    if (hasError || completed)
    {
        return;
    }
    const std::vector<Json> emptyJsonList{};
    auto entries = jsonData.value("entries", emptyJsonList);
    for (const auto& entry : entries)
    {
        TID = entry.value("tid", 0);
        pldm::pdr::EntityType entityType = entry.value("entityType", 0);
        pldm::pdr::StateSetId stateSetId = entry.value("stateSetId", 0);

        bool effecterFound = getEffecterID(entityType, stateSetId);
        if (effecterFound)
        {
            auto rc = getSensorInfo(entityType, stateSetId);
            if (rc != PLDM_SUCCESS)
            {
                error("Failed to get Sensor PDRs, response code '{RC}'", "RC",
                      lg2::hex, rc);
                hasError = true;
                return;
            }
            break;
        }
        else
        {
            continue;
        }
    }

    // Matches on the pldm StateSensorEvent signal
    pldmEventSignal = std::make_unique<sdbusplus::bus::match_t>(
        bus,
        sdbusRule::type::signal() + sdbusRule::member("StateSensorEvent") +
            sdbusRule::path("/xyz/openbmc_project/pldm") +
            sdbusRule::interface("xyz.openbmc_project.PLDM.Event"),
        std::bind(std::mem_fn(&SoftPowerOff::hostSoftOffComplete), this,
                  std::placeholders::_1));
}

int SoftPowerOff::getHostState()
{
    try
    {
        pldm::utils::PropertyValue propertyValue =
            pldm::utils::DBusHandler().getDbusPropertyVariant(
                "/xyz/openbmc_project/state/host0", "CurrentHostState",
                "xyz.openbmc_project.State.Host");

        if ((std::get<std::string>(propertyValue) !=
             "xyz.openbmc_project.State.Host.HostState.Running") &&
            (std::get<std::string>(propertyValue) !=
             "xyz.openbmc_project.State.Host.HostState.TransitioningToOff"))
        {
            // Host state is not "Running", this app should return success
            completed = true;
            return PLDM_SUCCESS;
        }
    }
    catch (const std::exception& e)
    {
        error(
            "PLDM remote terminus soft off. Can't get current remote terminus state, error - {ERROR}",
            "ERROR", e);
        hasError = true;
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

void SoftPowerOff::hostSoftOffComplete(sdbusplus::message_t& msg)
{
    pldm::pdr::TerminusID msgTID;
    pldm::pdr::SensorID msgSensorID;
    pldm::pdr::SensorOffset msgSensorOffset;
    pldm::pdr::EventState msgEventState;
    pldm::pdr::EventState msgPreviousEventState;

    // Read the msg and populate each variable
    msg.read(msgTID, msgSensorID, msgSensorOffset, msgEventState,
             msgPreviousEventState);

    if (msgSensorID == sensorID && msgSensorOffset == sensorOffset &&
        msgEventState == PLDM_SW_TERM_GRACEFUL_SHUTDOWN && msgTID == TID)
    {
        // Receive Graceful shutdown completion event message. Disable the timer
        auto rc = timer.stop();
        if (rc < 0)
        {
            error(
                "Failure to STOP the timer of PLDM soft off, response code '{RC}'",
                "RC", rc);
        }

        // This marks the completion of pldm soft power off.
        completed = true;
    }
}

Json SoftPowerOff::parseConfig()
{
    fs::path softoffConfigJson(
        fs::path(SOFTOFF_CONFIG_JSON) / "softoff_config.json");

    if (!fs::exists(softoffConfigJson) || fs::is_empty(softoffConfigJson))
    {
        error(
            "Failed to parse softoff config JSON file '{PATH}', file does not exist",
            "PATH", softoffConfigJson);
        return PLDM_ERROR;
    }

    std::ifstream jsonFile(softoffConfigJson);
    return Json::parse(jsonFile);
}

bool SoftPowerOff::getEffecterID(pldm::pdr::EntityType& entityType,
                                 pldm::pdr::StateSetId& stateSetId)
{
    auto& bus = pldm::utils::DBusHandler::getBus();
    try
    {
        std::vector<std::vector<uint8_t>> response{};
        auto method = bus.new_method_call(
            "xyz.openbmc_project.PLDM", "/xyz/openbmc_project/pldm",
            "xyz.openbmc_project.PLDM.PDR", "FindStateEffecterPDR");
        method.append(TID, entityType, stateSetId);
        auto responseMsg = bus.call(method, dbusTimeout);

        responseMsg.read(response);
        if (response.size())
        {
            for (auto& rep : response)
            {
                auto softoffPdr =
                    reinterpret_cast<pldm_state_effecter_pdr*>(rep.data());
                effecterID = softoffPdr->effecter_id;
            }
        }
        else
        {
            return false;
        }
    }
    catch (const sdbusplus::exception_t& e)
    {
        error("Failed to get softPowerOff PDR, error - {ERROR}", "ERROR", e);
        return false;
    }
    return true;
}

int SoftPowerOff::getSensorInfo(pldm::pdr::EntityType& entityType,
                                pldm::pdr::StateSetId& stateSetId)
{
    try
    {
        auto& bus = pldm::utils::DBusHandler::getBus();
        std::vector<std::vector<uint8_t>> Response{};
        auto method = bus.new_method_call(
            "xyz.openbmc_project.PLDM", "/xyz/openbmc_project/pldm",
            "xyz.openbmc_project.PLDM.PDR", "FindStateSensorPDR");
        method.append(TID, entityType, stateSetId);

        auto ResponseMsg = bus.call(method, dbusTimeout);

        ResponseMsg.read(Response);

        if (Response.size() == 0)
        {
            error("No sensor PDR has been found that matches the criteria");
            return PLDM_ERROR;
        }

        pldm_state_sensor_pdr* pdr = nullptr;
        for (auto& rep : Response)
        {
            pdr = reinterpret_cast<pldm_state_sensor_pdr*>(rep.data());
            if (!pdr)
            {
                error("Failed to get state sensor PDR.");
                return PLDM_ERROR;
            }
        }

        sensorID = pdr->sensor_id;

        auto compositeSensorCount = pdr->composite_sensor_count;
        auto possibleStatesStart = pdr->possible_states;

        for (auto offset = 0; offset < compositeSensorCount; offset++)
        {
            auto possibleStates =
                reinterpret_cast<state_sensor_possible_states*>(
                    possibleStatesStart);
            auto setId = possibleStates->state_set_id;
            auto possibleStateSize = possibleStates->possible_states_size;

            if (setId == PLDM_STATE_SET_SW_TERMINATION_STATUS)
            {
                sensorOffset = offset;
                break;
            }
            possibleStatesStart +=
                possibleStateSize + sizeof(setId) + sizeof(possibleStateSize);
        }
    }
    catch (const sdbusplus::exception_t& e)
    {
        error("Failed to get state sensor PDR during soft-off, error - {ERROR}",
              "ERROR", e);
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

int SoftPowerOff::hostSoftOff(sdeventplus::Event& event)
{
    constexpr uint8_t effecterCount = 1;
    PldmTransport pldmTransport{};
    uint8_t instanceID;
    uint8_t mctpEID;

    mctpEID = pldm::utils::readHostEID();
    // TODO: fix mapping to work around OpenBMC ecosystem deficiencies
    pldm_tid_t pldmTID = static_cast<pldm_tid_t>(mctpEID);

    std::array<uint8_t,
               sizeof(pldm_msg_hdr) + sizeof(effecterID) +
                   sizeof(effecterCount) + sizeof(set_effecter_state_field)>
        requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    set_effecter_state_field stateField{
        PLDM_REQUEST_SET, PLDM_SW_TERM_GRACEFUL_SHUTDOWN_REQUESTED};
    instanceID = instanceIdDb.next(pldmTID);
    auto rc = encode_set_state_effecter_states_req(
        instanceID, effecterID, effecterCount, &stateField, request);
    if (rc != PLDM_SUCCESS)
    {
        instanceIdDb.free(pldmTID, instanceID);
        error(
            "Failed to encode set state effecter states request message, response code '{RC}'",
            "RC", lg2::hex, rc);
        return PLDM_ERROR;
    }

    // Add a timer to the event loop, default 30s.
    auto timerCallback = [=, this](Timer& /*source*/,
                                   Timer::TimePoint /*time*/) mutable {
        if (!responseReceived)
        {
            instanceIdDb.free(pldmTID, instanceID);
            error(
                "PLDM soft off failed, can't get the response for the PLDM request msg. Time out! Exit the pldm-softpoweroff");
            exit(-1);
        }
        return;
    };
    Timer time(event, (Clock(event).now() + std::chrono::seconds{30}),
               std::chrono::seconds{1}, std::move(timerCallback));

    // Add a callback to handle EPOLLIN on fd
    auto callback = [=, &pldmTransport,
                     this](IO& io, int fd, uint32_t revents) mutable {
        if (fd != pldmTransport.getEventSource())
        {
            return;
        }

        if (!(revents & EPOLLIN))
        {
            return;
        }

        void* responseMsg = nullptr;
        size_t responseMsgSize{};
        pldm_tid_t srcTID = pldmTID;

        auto rc = pldmTransport.recvMsg(pldmTID, responseMsg, responseMsgSize);
        if (rc)
        {
            error(
                "Failed to receive pldm data during soft-off, response code '{RC}'",
                "RC", rc);
            return;
        }

        std::unique_ptr<void, decltype(std::free)*> responseMsgPtr{
            responseMsg, std::free};

        // We've got the response meant for the PLDM request msg that was
        // sent out
        io.set_enabled(Enabled::Off);
        auto response = reinterpret_cast<pldm_msg*>(responseMsgPtr.get());

        if (srcTID != pldmTID ||
            !pldm_msg_hdr_correlate_response(&request->hdr, &response->hdr))
        {
            /* This isn't the response we were looking for */
            return;
        }

        /* We have the right response, release the instance ID and process */
        io.set_enabled(Enabled::Off);
        instanceIdDb.free(pldmTID, instanceID);

        if (response->payload[0] != PLDM_SUCCESS)
        {
            error("Getting the wrong response, response code '{RC}'", "RC",
                  response->payload[0]);
            exit(-1);
        }

        responseReceived = true;

        // Start Timer
        using namespace std::chrono;
        auto timeMicroseconds =
            duration_cast<microseconds>(seconds(SOFTOFF_TIMEOUT_SECONDS));

        auto ret = startTimer(timeMicroseconds);
        if (ret < 0)
        {
            error(
                "Failure to start remote terminus soft off wait timer, Exit the pldm-softpoweroff with response code:{NUM}",
                "NUM", ret);
            exit(-1);
        }
        else
        {
            error(
                "Timer started waiting for remote terminus soft off, timeout in sec '{TIMEOUT_SEC}'",
                "TIMEOUT_SEC", SOFTOFF_TIMEOUT_SECONDS);
        }
        return;
    };
    IO io(event, pldmTransport.getEventSource(), EPOLLIN, std::move(callback));

    // Asynchronously send the PLDM request
    rc = pldmTransport.sendMsg(pldmTID, requestMsg.data(), requestMsg.size());
    if (0 > rc)
    {
        instanceIdDb.free(pldmTID, instanceID);
        error(
            "Failed to send message/receive response, response code '{RC}' and error - {ERROR}",
            "RC", rc, "ERROR", errno);
        return PLDM_ERROR;
    }

    // Time out or soft off complete
    while (!isCompleted() && !isTimerExpired())
    {
        try
        {
            event.run(std::nullopt);
        }
        catch (const sdeventplus::SdEventError& e)
        {
            instanceIdDb.free(pldmTID, instanceID);
            error(
                "Failed to process request while remote terminus soft off, error - {ERROR}",
                "ERROR", e);
            return PLDM_ERROR;
        }
    }

    return PLDM_SUCCESS;
}

int SoftPowerOff::startTimer(const std::chrono::microseconds& usec)
{
    return timer.start(usec);
}
} // namespace pldm
