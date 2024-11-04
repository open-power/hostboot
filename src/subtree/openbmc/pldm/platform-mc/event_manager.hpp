#pragma once

#include "libpldm/platform.h"
#include "libpldm/pldm.h"

#include "common/types.hpp"
#include "numeric_sensor.hpp"
#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"
#include "terminus.hpp"
#include "terminus_manager.hpp"

namespace pldm
{
namespace platform_mc
{

using EventType = uint8_t;
using HandlerFunc =
    std::function<int(pldm_tid_t tid, uint16_t eventId,
                      const uint8_t* eventData, size_t eventDataSize)>;
using EventMap = std::map<EventType, HandlerFunc>;

/**
 * @brief EventManager
 *
 * This class manages PLDM events from terminus. The function includes providing
 * the API for process event data and using phosphor-logging API to log the
 * event.
 *
 */
class EventManager
{
  public:
    EventManager() = delete;
    EventManager(const EventManager&) = delete;
    EventManager(EventManager&&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    EventManager& operator=(EventManager&&) = delete;
    virtual ~EventManager() = default;

    explicit EventManager(TerminusManager& terminusManager,
                          TerminiMapper& termini) :
        terminusManager(terminusManager), termini(termini)
    {
        // Default response handler for PollForPlatFormEventMessage
        registerPolledEventHandler(
            PLDM_MESSAGE_POLL_EVENT,
            [this](pldm_tid_t tid, uint16_t eventId, const uint8_t* eventData,
                   size_t eventDataSize) {
                return this->handlePlatformEvent(tid, eventId,
                                                 PLDM_MESSAGE_POLL_EVENT,
                                                 eventData, eventDataSize);
            });
        registerPolledEventHandler(
            PLDM_CPER_EVENT,
            [this](pldm_tid_t tid, uint16_t eventId, const uint8_t* eventData,
                   size_t eventDataSize) {
                return this->handlePlatformEvent(tid, eventId, PLDM_CPER_EVENT,
                                                 eventData, eventDataSize);
            });
    };

    /** @brief Handle platform event
     *
     *  @param[in] tid - tid where the event is from
     *  @param[in] eventId - event Id
     *  @param[in] eventClass - event class
     *  @param[in] eventData - event data
     *  @param[in] eventDataSize - size of event data
     *  @return PLDM completion code
     */
    int handlePlatformEvent(pldm_tid_t tid, uint16_t eventId,
                            uint8_t eventClass, const uint8_t* eventData,
                            size_t eventDataSize);

    /** @brief Set available state of terminus for pldm request.
     *
     *  @param[in] tid - terminus ID
     *  @param[in] state - Terminus available state for PLDM request messages
     */
    void updateAvailableState(pldm_tid_t tid, Availability state)
    {
        availableState[tid] = state;
    };

    /** @brief Get available state of terminus for pldm request.
     *
     *  @param[in] tid - terminus ID
     */
    bool getAvailableState(pldm_tid_t tid)
    {
        if (!availableState.contains(tid))
        {
            return false;
        }
        return availableState[tid];
    };

    /** @brief A Coroutine to poll all events from terminus
     *
     *  @param[in] tid - the destination TID
     *  @param[in] pollDataTransferHandle - the dataTransferHandle from
     *             pldmMessagePollEvent event
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> pollForPlatformEventTask(pldm_tid_t tid,
                                             uint32_t pollDataTransferHandle);

    /** @brief Register response handler for the polled events from
     *         PollForPlatFormEventMessage
     */
    void registerPolledEventHandler(uint8_t eventClass, HandlerFunc function)
    {
        eventHandlers.insert_or_assign(eventClass, std::move(function));
    }

  protected:
    /** @brief Helper method to process the PLDM Numeric sensor event class
     *
     *  @param[in] tid - tid where the event is from
     *  @param[in] sensorId - Sensor ID which is the source of event
     *  @param[in] sensorData - Numeric sensor event data
     *  @param[in] sensorDataLength - event data length
     *
     *  @return PLDM completion code
     */
    int processNumericSensorEvent(pldm_tid_t tid, uint16_t sensorId,
                                  const uint8_t* sensorData,
                                  size_t sensorDataLength);

    /** @brief Helper method to process the PLDM CPER event class
     *
     *  @param[in] tid - tid where the event is from
     *  @param[in] eventId - Event ID which is the source of event
     *  @param[in] eventData - CPER event data
     *  @param[in] eventDataSize - event data length
     *
     *  @return PLDM completion code
     */
    virtual int processCperEvent(pldm_tid_t tid, uint16_t eventId,
                                 const uint8_t* eventData,
                                 const size_t eventDataSize);

    /** @brief Helper method to create CPER dump log
     *
     *  @param[in] dataType - CPER event data type
     *  @param[in] dataPath - CPER event data fault log file path
     *  @param[in] typeName - Terminus name which creates CPER event
     *
     *  @return PLDM completion code
     */
    int createCperDumpEntry(const std::string& dataType,
                            const std::string& dataPath,
                            const std::string& typeName);

    /** @brief Send pollForPlatformEventMessage and return response
     *
     *  @param[in] tid - Destination TID
     *  @param[in] formatVersion - format Version
     *  @param[in] transferOpFlag - Transfer Operation Flag
     *  @param[in] dataTransferHandle - Data transfer handle
     *  @param[in] eventIdToAcknowledge - Event ID
     *  @param[out] completionCode - the complete code of response message
     *  @param[out] eventTid - Event terminus ID
     *  @param[out] eventId - Event ID
     *  @param[out] nextDataTransferHandle - Next handle to get next data part
     *  @param[out] transferFlag - transfer Flag of response data
     *  @param[out] eventClass - event class
     *  @param[out] eventDataSize - data size of event response message
     *  @param[out] eventData - event data of response message
     *  @param[out] eventDataIntegrityChecksum - check sum of final event
     *
     *  @return coroutine return_value - PLDM completion code
     */
    exec::task<int> pollForPlatformEventMessage(
        pldm_tid_t tid, uint8_t formatVersion, uint8_t transferOperationFlag,
        uint32_t dataTransferHandle, uint16_t eventIdToAcknowledge,
        uint8_t& completionCode, uint8_t& eventTid, uint16_t& eventId,
        uint32_t& nextDataTransferHandle, uint8_t& transferFlag,
        uint8_t& eventClass, uint32_t& eventDataSize, uint8_t*& eventData,
        uint32_t& eventDataIntegrityChecksum);

    /** @brief Get the parameters for next pollForPlatformEventMessage to get
     *         the remaining part of event if has
     *
     *  @param[in] eventId - Event ID
     *  @param[in] eventMessage - event data of response message
     *  @param[in] transferFlag - transfer Flag of response data
     *  @param[in] eventDataIntegrityChecksum - check sum of final event
     *  @param[in] nextDataTransferHandle - Next handle to get next data part
     *  @param[out] transferOperationFlag - transfer Flag of next request data
     *  @param[out] dataTransferHandle - Data transfer handle
     *  @param[out] eventIdToAcknowledge - Event ID
     *
     *  @return return_value - PLDM completion code
     */
    int getNextPartParameters(
        uint16_t eventId, std::vector<uint8_t> eventMessage,
        uint8_t transferFlag, uint32_t eventDataIntegrityChecksum,
        uint32_t nextDataTransferHandle, uint8_t* transferOperationFlag,
        uint32_t* dataTransferHandle, uint32_t* eventIdToAcknowledge);

    /** @brief Reference of terminusManager */
    TerminusManager& terminusManager;

    /** @brief List of discovered termini */
    TerminiMapper& termini;

    /** @brief Available state for pldm request of terminus */
    std::unordered_map<pldm_tid_t, Availability> availableState;

    /** @brief map of PLDM event type of polled event to EventHandlers */
    pldm::platform_mc::EventMap eventHandlers;
};
} // namespace platform_mc
} // namespace pldm
