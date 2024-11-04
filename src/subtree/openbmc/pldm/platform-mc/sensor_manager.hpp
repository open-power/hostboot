#pragma once

#include "libpldm/platform.h"
#include "libpldm/pldm.h"

#include "common/types.hpp"
#include "requester/handler.hpp"
#include "terminus.hpp"
#include "terminus_manager.hpp"

#include <map>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

namespace pldm
{
namespace platform_mc
{

/**
 * @brief SensorManager
 *
 * This class manages the sensors found in terminus and provides
 * function calls for other classes to start/stop sensor monitoring.
 *
 */
class SensorManager
{
  public:
    SensorManager() = delete;
    SensorManager(const SensorManager&) = delete;
    SensorManager(SensorManager&&) = delete;
    SensorManager& operator=(const SensorManager&) = delete;
    SensorManager& operator=(SensorManager&&) = delete;
    virtual ~SensorManager() = default;

    explicit SensorManager(sdeventplus::Event& event,
                           TerminusManager& terminusManager,
                           TerminiMapper& termini, Manager* manager);

    /** @brief starting sensor polling task
     */
    void startPolling(pldm_tid_t tid);

    /** @brief stopping sensor polling task
     */
    void stopPolling(pldm_tid_t tid);

    /** @brief Set available state of terminus for pldm request.
     */
    void updateAvailableState(pldm_tid_t tid, Availability state)
    {
        availableState[tid] = state;
    };

    /** @brief Get available state of terminus for pldm request.
     */
    bool getAvailableState(pldm_tid_t tid)
    {
        if (!availableState.contains(tid))
        {
            return false;
        }
        return availableState[tid];
    };

  protected:
    /** @brief start a coroutine for polling all sensors.
     */
    virtual void doSensorPolling(pldm_tid_t tid);

    /** @brief polling all sensors in each terminus
     *
     *  @param[in] tid - Destination TID
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> doSensorPollingTask(pldm_tid_t tid);

    /** @brief Sending getSensorReading command for the sensor
     *
     *  @param[in] sensor - the sensor to be updated
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> getSensorReading(std::shared_ptr<NumericSensor> sensor);

    /** @brief Reference to to PLDM daemon's main event loop.
     */
    sdeventplus::Event& event;

    /** @brief reference of terminusManager */
    TerminusManager& terminusManager;

    /** @brief List of discovered termini */
    TerminiMapper& termini;

    /** @brief sensor polling interval in ms. */
    uint32_t pollingTime;

    /** @brief sensor polling timers */
    std::map<pldm_tid_t, std::unique_ptr<sdbusplus::Timer>> sensorPollTimers;

    /** @brief coroutine handle of doSensorPollingTasks */
    std::map<pldm_tid_t, std::pair<exec::async_scope, std::optional<int>>>
        doSensorPollingTaskHandles;

    /** @brief Available state for pldm request of terminus */
    std::map<pldm_tid_t, Availability> availableState;

    /** @brief round robin sensor list */
    std::map<pldm_tid_t, std::queue<std::shared_ptr<NumericSensor>>>
        roundRobinSensors;

    /** @brief pointer to Manager */
    Manager* manager;
};
} // namespace platform_mc
} // namespace pldm
