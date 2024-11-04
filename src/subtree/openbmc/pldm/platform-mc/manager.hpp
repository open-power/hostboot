#pragma once

#include "libpldm/pldm.h"

#include "common/instance_id.hpp"
#include "common/types.hpp"
#include "event_manager.hpp"
#include "platform_manager.hpp"
#include "requester/handler.hpp"
#include "requester/mctp_endpoint_discovery.hpp"
#include "sensor_manager.hpp"
#include "terminus_manager.hpp"

namespace pldm
{
namespace platform_mc
{

/**
 * @brief Manager
 *
 * This class handles all the aspect of the PLDM Platform Monitoring and Control
 * specification for the MCTP devices
 */
class Manager : public pldm::MctpDiscoveryHandlerIntf
{
  public:
    Manager() = delete;
    Manager(const Manager&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager& operator=(Manager&&) = delete;
    ~Manager() = default;

    explicit Manager(sdeventplus::Event& event, RequesterHandler& handler,
                     pldm::InstanceIdDb& instanceIdDb) :
        terminusManager(event, handler, instanceIdDb, termini, this,
                        pldm::BmcMctpEid),
        platformManager(terminusManager, termini),
        sensorManager(event, terminusManager, termini, this),
        eventManager(terminusManager, termini)
    {}

    /** @brief Helper function to do the actions before discovering terminus
     *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> beforeDiscoverTerminus();

    /** @brief Helper function to do the actions after discovering terminus
     *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> afterDiscoverTerminus();

    /** @brief Helper function to invoke registered handlers for
     *         the added MCTP endpoints
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     */
    void handleMctpEndpoints(const MctpInfos& mctpInfos)
    {
        terminusManager.discoverMctpTerminus(mctpInfos);
    }

    /** @brief Helper function to invoke registered handlers for
     *         the removed MCTP endpoints
     *
     *  @param[in] mctpInfos - list information of the MCTP endpoints
     */
    void handleRemovedMctpEndpoints(const MctpInfos& mctpInfos)
    {
        terminusManager.removeMctpTerminus(mctpInfos);
    }

    /** @brief Helper function to start sensor polling of the terminus TID
     */
    void startSensorPolling(pldm_tid_t tid)
    {
        sensorManager.startPolling(tid);
    }

    /** @brief Helper function to set available state for pldm request (sensor
     *         polling and event polling) of the terminus TID. The `false` state
     *         will trigger stop flow in coroutine of sensor polling/event
     *         polling task to stop.
     */
    void updateAvailableState(pldm_tid_t tid, Availability state)
    {
        if (termini.contains(tid))
        {
            sensorManager.updateAvailableState(tid, state);
            eventManager.updateAvailableState(tid, state);
        }
    }

    /** @brief Helper function to stop sensor polling of the terminus TID
     */
    void stopSensorPolling(pldm_tid_t tid)
    {
        sensorManager.stopPolling(tid);
    }

    /** @brief Sensor event handler function
     *
     *  @param[in] request - Event message
     *  @param[in] payloadLength - Event message payload size
     *  @param[in] tid - Terminus ID
     *  @param[in] eventDataOffset - Event data offset
     *
     *  @return PLDM error code: PLDM_SUCCESS when there is no error in handling
     *          the event
     */
    int handleSensorEvent(const pldm_msg* request, size_t payloadLength,
                          uint8_t /* formatVersion */, uint8_t tid,
                          size_t eventDataOffset)
    {
        auto eventData = reinterpret_cast<const uint8_t*>(request->payload) +
                         eventDataOffset;
        auto eventDataSize = payloadLength - eventDataOffset;
        eventManager.handlePlatformEvent(tid, PLDM_PLATFORM_EVENT_ID_NULL,
                                         PLDM_SENSOR_EVENT, eventData,
                                         eventDataSize);
        return PLDM_SUCCESS;
    }

    /** @brief CPER event handler function
     *
     *  @param[in] request - Event message
     *  @param[in] payloadLength - Event message payload size
     *  @param[in] tid - Terminus ID
     *  @param[in] eventDataOffset - Event data offset
     *
     *  @return PLDM error code: PLDM_SUCCESS when there is no error in handling
     *          the event
     */
    int handleCperEvent(const pldm_msg* request, size_t payloadLength,
                        uint8_t /* formatVersion */, uint8_t tid,
                        size_t eventDataOffset)
    {
        auto eventData =
            const_cast<const uint8_t*>(request->payload) + eventDataOffset;
        auto eventDataSize = payloadLength - eventDataOffset;
        eventManager.handlePlatformEvent(tid, PLDM_PLATFORM_EVENT_ID_NULL,
                                         PLDM_CPER_EVENT, eventData,
                                         eventDataSize);
        return PLDM_SUCCESS;
    }

    /** @brief PLDM POLL event handler function
     *
     *  @param[in] request - Event message
     *  @param[in] payloadLength - Event message payload size
     *  @param[in] tid - Terminus ID
     *  @param[in] eventDataOffset - Event data offset
     *
     *  @return PLDM error code: PLDM_SUCCESS when there is no error in handling
     *          the event
     */
    int handlePldmMessagePollEvent(
        const pldm_msg* request, size_t payloadLength,
        uint8_t /* formatVersion */, uint8_t tid, size_t eventDataOffset)
    {
        auto eventData = reinterpret_cast<const uint8_t*>(request->payload) +
                         eventDataOffset;
        auto eventDataSize = payloadLength - eventDataOffset;
        eventManager.handlePlatformEvent(tid, PLDM_PLATFORM_EVENT_ID_NULL,
                                         PLDM_MESSAGE_POLL_EVENT, eventData,
                                         eventDataSize);
        return PLDM_SUCCESS;
    }

    /** @brief The function to trigger the event polling
     *
     *  @param[in] tid - Terminus ID
     *  @param[in] pollEventId - The source eventID from pldmMessagePollEvent
     *  @param[in] pollDataTransferHandle - The dataTransferHandle from
     *             pldmMessagePollEvent event
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> pollForPlatformEvent(pldm_tid_t tid, uint16_t pollEventId,
                                         uint32_t pollDataTransferHandle);

  private:
    /** @brief List of discovered termini */
    TerminiMapper termini{};

    /** @brief Terminus interface for calling the hook functions */
    TerminusManager terminusManager;

    /** @brief Platform interface for calling the hook functions */
    PlatformManager platformManager;

    /** @brief Store platform manager handler */
    SensorManager sensorManager;

    /** @brief Store event manager handler */
    EventManager eventManager;
};
} // namespace platform_mc
} // namespace pldm
