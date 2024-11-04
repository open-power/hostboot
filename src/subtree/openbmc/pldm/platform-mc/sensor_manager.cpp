#include "sensor_manager.hpp"

#include "manager.hpp"
#include "terminus_manager.hpp"

#include <phosphor-logging/lg2.hpp>

#include <exception>

namespace pldm
{
namespace platform_mc
{

SensorManager::SensorManager(sdeventplus::Event& event,
                             TerminusManager& terminusManager,
                             TerminiMapper& termini, Manager* manager) :
    event(event), terminusManager(terminusManager), termini(termini),
    pollingTime(SENSOR_POLLING_TIME), manager(manager)
{}

void SensorManager::startPolling(pldm_tid_t tid)
{
    if (!termini.contains(tid))
    {
        return;
    }

    /* tid already initializes roundRobinSensors list */
    if (sensorPollTimers.contains(tid))
    {
        lg2::info("Terminus ID {TID}: sensor poll timer already exists.", "TID",
                  tid);
        return;
    }
    // numeric sensor
    auto terminus = termini[tid];
    for (auto& sensor : terminus->numericSensors)
    {
        roundRobinSensors[tid].push(sensor);
    }

    updateAvailableState(tid, true);

    if (!roundRobinSensors[tid].size())
    {
        lg2::info("Terminus ID {TID}: no sensors to poll.", "TID", tid);
        return;
    }

    sensorPollTimers[tid] = std::make_unique<sdbusplus::Timer>(
        event.get(),
        std::bind_front(&SensorManager::doSensorPolling, this, tid));

    try
    {
        if (sensorPollTimers[tid] && !sensorPollTimers[tid]->isRunning())
        {
            sensorPollTimers[tid]->start(
                duration_cast<std::chrono::milliseconds>(
                    std::chrono::milliseconds(pollingTime)),
                true);
        }
    }
    catch (const std::exception& e)
    {
        lg2::error(
            "Terminus ID {TID}: Failed to start sensor polling timer. Exception: {EXCEPTION}",
            "TID", tid, "EXCEPTION", e);
        return;
    }
}

void SensorManager::stopPolling(pldm_tid_t tid)
{
    /* Stop polling timer */
    if (sensorPollTimers.contains(tid))
    {
        sensorPollTimers[tid]->stop();
        sensorPollTimers.erase(tid);
    }

    roundRobinSensors.erase(tid);

    if (doSensorPollingTaskHandles.contains(tid))
    {
        auto& [scope, rcOpt] = doSensorPollingTaskHandles[tid];
        scope.request_stop();
        doSensorPollingTaskHandles.erase(tid);
    }

    availableState.erase(tid);
}

void SensorManager::doSensorPolling(pldm_tid_t tid)
{
    auto it = doSensorPollingTaskHandles.find(tid);
    if (it != doSensorPollingTaskHandles.end())
    {
        auto& [scope, rcOpt] = it->second;
        if (!rcOpt.has_value())
        {
            return;
        }
        doSensorPollingTaskHandles.erase(tid);
    }

    auto& [scope, rcOpt] =
        doSensorPollingTaskHandles
            .emplace(std::piecewise_construct, std::forward_as_tuple(tid),
                     std::forward_as_tuple())
            .first->second;
    scope.spawn(
        stdexec::just() | stdexec::let_value([this, &rcOpt,
                                              tid] -> exec::task<void> {
            auto res =
                co_await stdexec::stopped_as_optional(doSensorPollingTask(tid));
            if (res.has_value())
            {
                rcOpt = *res;
            }
            else
            {
                lg2::info("Stopped polling for Terminus ID {TID}", "TID", tid);
                try
                {
                    if (sensorPollTimers.contains(tid) &&
                        sensorPollTimers[tid] &&
                        sensorPollTimers[tid]->isRunning())
                    {
                        sensorPollTimers[tid]->stop();
                    }
                }
                catch (const std::exception& e)
                {
                    lg2::error(
                        "Terminus ID {TID}: Failed to stop polling timer. Exception: {EXCEPTION}",
                        "TID", tid, "EXCEPTION", e);
                }
                rcOpt = PLDM_SUCCESS;
            }
        }),
        exec::default_task_context<void>(exec::inline_scheduler{}));
}

exec::task<int> SensorManager::doSensorPollingTask(pldm_tid_t tid)
{
    uint64_t t0 = 0;
    uint64_t t1 = 0;
    uint64_t elapsed = 0;
    uint64_t pollingTimeInUsec = pollingTime * 1000;
    uint8_t rc = PLDM_SUCCESS;

    do
    {
        if ((!sensorPollTimers.contains(tid)) ||
            (sensorPollTimers[tid] && !sensorPollTimers[tid]->isRunning()))
        {
            co_return PLDM_ERROR;
        }

        sd_event_now(event.get(), CLOCK_MONOTONIC, &t0);

        /**
         * Terminus is not available for PLDM request.
         * The terminus manager will trigger recovery process to recovery the
         * communication between the local terminus and the remote terminus.
         * The sensor polling should be stopped while recovering the
         * communication.
         */
        if (!getAvailableState(tid))
        {
            lg2::info(
                "Terminus ID {TID} is not available for PLDM request from {NOW}.",
                "TID", tid, "NOW", pldm::utils::getCurrentSystemTime());
            co_await stdexec::just_stopped();
        }

        if (!termini.contains(tid))
        {
            co_return PLDM_SUCCESS;
        }

        auto& terminus = termini[tid];

        if (manager && terminus->pollEvent)
        {
            co_await manager->pollForPlatformEvent(
                tid, terminus->pollEventId, terminus->pollDataTransferHandle);
        }

        sd_event_now(event.get(), CLOCK_MONOTONIC, &t1);
        auto toBeUpdated = roundRobinSensors[tid].size();
        while (((t1 - t0) < pollingTimeInUsec) && (toBeUpdated > 0))
        {
            if (!getAvailableState(tid))
            {
                lg2::info(
                    "Terminus ID {TID} is not available for PLDM request from {NOW}.",
                    "TID", tid, "NOW", pldm::utils::getCurrentSystemTime());
                co_await stdexec::just_stopped();
            }

            auto sensor = roundRobinSensors[tid].front();

            sd_event_now(event.get(), CLOCK_MONOTONIC, &t1);
            elapsed = t1 - sensor->timeStamp;
            if ((sensor->updateTime <= elapsed) || (!sensor->timeStamp))
            {
                rc = co_await getSensorReading(sensor);

                if ((!sensorPollTimers.contains(tid)) ||
                    (sensorPollTimers[tid] &&
                     !sensorPollTimers[tid]->isRunning()))
                {
                    co_return PLDM_ERROR;
                }
                sd_event_now(event.get(), CLOCK_MONOTONIC, &t1);
                if (rc == PLDM_SUCCESS)
                {
                    sensor->timeStamp = t1;
                }
                else
                {
                    lg2::error(
                        "Failed to get sensor value for terminus {TID}, error: {RC}",
                        "TID", tid, "RC", rc);
                }
            }

            toBeUpdated--;
            if (roundRobinSensors.contains(tid))
            {
                roundRobinSensors[tid].pop();
                roundRobinSensors[tid].push(std::move(sensor));
            }
            sd_event_now(event.get(), CLOCK_MONOTONIC, &t1);
        }

        sd_event_now(event.get(), CLOCK_MONOTONIC, &t1);
    } while ((t1 - t0) >= pollingTimeInUsec);

    co_return PLDM_SUCCESS;
}

exec::task<int>
    SensorManager::getSensorReading(std::shared_ptr<NumericSensor> sensor)
{
    if (!sensor)
    {
        lg2::error("Call `getSensorReading` with null `sensor` pointer.");
        co_return PLDM_ERROR_INVALID_DATA;
    }

    auto tid = sensor->tid;
    auto sensorId = sensor->sensorId;
    Request request(sizeof(pldm_msg_hdr) + PLDM_GET_SENSOR_READING_REQ_BYTES);
    auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
    auto rc = encode_get_sensor_reading_req(0, sensorId, false, requestMsg);
    if (rc)
    {
        lg2::error(
            "Failed to encode request GetSensorReading for terminus ID {TID}, sensor Id {ID}, error {RC}.",
            "TID", tid, "ID", sensorId, "RC", rc);
        co_return rc;
    }

    if (!getAvailableState(tid))
    {
        lg2::info(
            "Terminus ID {TID} is not available for PLDM request from {NOW}.",
            "TID", tid, "NOW", pldm::utils::getCurrentSystemTime());
        co_await stdexec::just_stopped();
    }

    const pldm_msg* responseMsg = nullptr;
    size_t responseLen = 0;
    rc = co_await terminusManager.sendRecvPldmMsg(tid, request, &responseMsg,
                                                  &responseLen);
    if (rc)
    {
        lg2::error(
            "Failed to send GetSensorReading message for terminus {TID}, sensor Id {ID}, error {RC}",
            "TID", tid, "ID", sensorId, "RC", rc);
        co_return rc;
    }

    if ((!sensorPollTimers.contains(tid)) ||
        (sensorPollTimers[tid] && !sensorPollTimers[tid]->isRunning()))
    {
        co_return PLDM_ERROR;
    }

    uint8_t completionCode = PLDM_SUCCESS;
    uint8_t sensorDataSize = PLDM_SENSOR_DATA_SIZE_SINT32;
    uint8_t sensorOperationalState = 0;
    uint8_t sensorEventMessageEnable = 0;
    uint8_t presentState = 0;
    uint8_t previousState = 0;
    uint8_t eventState = 0;
    union_sensor_data_size presentReading;
    rc = decode_get_sensor_reading_resp(
        responseMsg, responseLen, &completionCode, &sensorDataSize,
        &sensorOperationalState, &sensorEventMessageEnable, &presentState,
        &previousState, &eventState,
        reinterpret_cast<uint8_t*>(&presentReading));
    if (rc)
    {
        lg2::error(
            "Failed to decode response GetSensorReading for terminus ID {TID}, sensor Id {ID}, error {RC}.",
            "TID", tid, "ID", sensorId, "RC", rc);
        sensor->handleErrGetSensorReading();
        co_return rc;
    }

    if (completionCode != PLDM_SUCCESS)
    {
        lg2::error(
            "Error : GetSensorReading for terminus ID {TID}, sensor Id {ID}, complete code {CC}.",
            "TID", tid, "ID", sensorId, "CC", completionCode);
        co_return completionCode;
    }

    double value = std::numeric_limits<double>::quiet_NaN();
    switch (sensorOperationalState)
    {
        case PLDM_SENSOR_ENABLED:
            break;
        case PLDM_SENSOR_DISABLED:
            sensor->updateReading(false, true, value);
            co_return completionCode;
        case PLDM_SENSOR_FAILED:
            sensor->updateReading(true, false, value);
            co_return completionCode;
        case PLDM_SENSOR_UNAVAILABLE:
        default:
            sensor->updateReading(false, false, value);
            co_return completionCode;
    }

    switch (sensorDataSize)
    {
        case PLDM_SENSOR_DATA_SIZE_UINT8:
            value = static_cast<double>(presentReading.value_u8);
            break;
        case PLDM_SENSOR_DATA_SIZE_SINT8:
            value = static_cast<double>(presentReading.value_s8);
            break;
        case PLDM_SENSOR_DATA_SIZE_UINT16:
            value = static_cast<double>(presentReading.value_u16);
            break;
        case PLDM_SENSOR_DATA_SIZE_SINT16:
            value = static_cast<double>(presentReading.value_s16);
            break;
        case PLDM_SENSOR_DATA_SIZE_UINT32:
            value = static_cast<double>(presentReading.value_u32);
            break;
        case PLDM_SENSOR_DATA_SIZE_SINT32:
            value = static_cast<double>(presentReading.value_s32);
            break;
        default:
            value = std::numeric_limits<double>::quiet_NaN();
            break;
    }

    sensor->updateReading(true, true, value);
    co_return completionCode;
}

} // namespace platform_mc
} // namespace pldm
