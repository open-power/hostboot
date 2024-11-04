#pragma once

#include "libpldmresponder/platform.hpp"

#include <libpldm/pdr.h>
#include <libpldm/platform.h>

#include <sdbusplus/bus/match.hpp>
#include <sdeventplus/event.hpp>
#include <sdeventplus/utility/timer.hpp>

#include <memory>

namespace pldm
{

using namespace sdbusplus::bus::match::rules;

namespace responder
{

using ObjectPath = std::string;
using AssociatedEntityMap = std::map<ObjectPath, pldm_entity>;

/** @class SlotHandler
 *
 *  @brief This class performs the necessary operation in pldm for
 *         Slot Enable operation. That includes taking actions on the
 *         setStateEffecterStates calls from Host and also sending
 *         notification to inventory manager application
 */
class SlotHandler
{
  public:
    SlotHandler() = delete;
    ~SlotHandler() = default;
    SlotHandler(const SlotHandler&) = delete;
    SlotHandler& operator=(const SlotHandler&) = delete;
    SlotHandler(SlotHandler&&) = delete;
    SlotHandler& operator=(SlotHandler&&) = delete;

    /** @brief SlotHandler Constructor
     *
     * @param[in] event - reference for the main event loop
     * @param[in] repo - pointer to the BMC's Primary PDR repo
     *
     */
    SlotHandler(const sdeventplus::Event& event, pldm_pdr* repo) :
        timer(event,
              std::bind(std::mem_fn(&SlotHandler::timeOutHandler), this)),
        pdrRepo(repo)
    {
        fruPresenceMatch = nullptr;
        currentOnGoingSlotEntity.entity_type = 0;
        currentOnGoingSlotEntity.entity_instance_num = 0;
        currentOnGoingSlotEntity.entity_container_id = 0;
    }

    /** @brief Method to be called when enabling a Slot for ADD/REMOVE/REPLACE
     *  @param[in] effecterID - The effecter ID of the effecter that is set from
     *                          host
     *  @param[in] fruAssociationMap - the dbus path to pldm entity stored while
     *                                 creating the pldm fru records
     *  @param[in] stateFieldValue - the current Effecter stateFieldValue
     */
    void enableSlot(uint16_t effecterId,
                    const AssociatedEntityMap& fruAssociationMap,
                    uint8_t stateFieldValue);

    /** @brief Method to be used for fetching the slot sensor value
     *  @param[in] slotObjectPath - the dbus object path for slot object
     *  @return - returns the sensor state for the respective slot sensor
     */
    uint8_t fetchSlotSensorState(const std::string& slotObjectPath);

    /** @brief Method to set the oem platform handler in SlotHandler class
     *  @param[in] handler - pointer to the oem platform handler
     */
    void setOemPlatformHandler(pldm::responder::oem_platform::Handler* handler);

  private:
    /** @brief call back method called when the timer is expired. This handler
     *  is called when the change of state cannot be made for a slot.
     */
    void timeOutHandler();

    /** @brief Abstracted method for obtaining the entityID from effecterID
     *  @param[in]  effecterID - The effecterID of the BMC effecter
     *  @return - pldm entity ID for the given effecter ID
     */
    pldm_entity getEntityIDfromEffecterID(uint16_t effecterID);

    /** @brief Abstracted method for processing the Slot Operations
     *  @param[in] slotObjPath - The slot dbus object path
     *  @param[in] entity - the current slot pldm entity under operation
     *  @param[in] stateFieldValue - the current Effecter stateFieldValue
     */
    void processSlotOperations(const std::string& slotObjectPath,
                               const pldm_entity& entity,
                               uint8_t stateFieldValue);

    /** @brief Method to obtain the Adapter dbus Object Path from Slot Adapter
     * path
     *  @param[in] slotObjPath - The slot dbus object path
     *  @return - if Successfull, returns the adapter dbus object path
     */
    std::optional<std::string>
        getAdapterObjPath(const std::string& slotObjPath);

    /** @brief Method to call VPD collection & VPD removal API's
     *  @param[in] adapterObjectPath - The adapter D-Bus object path
     *  @param[in] stateFieldvalue - The current stateField value from set
     *                               effecter call
     */
    void callVPDManager(const std::string& adapterObjPath,
                        uint8_t stateFieldValue);

    /** @brief Method to create a matcher to catch the property change signal
     *  @param[in] adapterObjectPath - The adapter D-Bus object path
     *  @param[in] stateFieldvalue - The current stateField value from set
     *                               effecter call
     *  @param[in] entity - the current slot pldm entity under operation
     */
    void createPresenceMatch(const std::string& adapterObjectPath,
                             const pldm_entity& entity,
                             uint8_t stateFieldValue);

    /** @brief Method to process the Property change signal from Preset Property
     *  @param[in] presentValue - The current value of present Value
     *  @param[in] stateFieldvalue - The current stateField value from set
     *                               effecter call
     *  @param[in] entity - the current slot pldm entity under operation
     */
    void processPresentPropertyChange(
        bool presentValue, uint8_t stateFieldvalue, const pldm_entity& entity);

    /** @brief Get the sensor state from D-Bus
     *  @param[in] adapterObjectPath - reference of the Adapter dbus object path
     *  @return - Boolean value of sensor state
     */

    bool fetchSensorStateFromDbus(const std::string& adapterObjectPath);

    /* @brief Method to send a state sensor event to Host from SlotHandler class
     * @param[in] sensorId - sensor id for the event
     * @param[in] sensorEventClass - sensor event class wrt DSP0248
     * @param[in] sensorOffset - sensor offset
     * @param[in] eventState - new event state
     * @param[in] prevEventState - previous state
     */
    void sendStateSensorEvent(uint16_t sensorId,
                              enum sensor_event_class_states sensorEventClass,
                              uint8_t sensorOffset, uint8_t eventState,
                              uint8_t prevEventState);

    pldm::responder::oem_platform::Handler* oemPlatformHandler =
        nullptr; //!< oem platform handler

    /** @brief pointer to tha matcher for Present State for adapter object*/
    std::unique_ptr<sdbusplus::bus::match_t> fruPresenceMatch;

    /** @brief Timer used for Slot VPD Collection operation */
    sdeventplus::utility::Timer<sdeventplus::ClockId::Monotonic> timer;

    /** @brief pointer to BMC's primary PDR repo */
    const pldm_pdr* pdrRepo;

    /** @brief variable to store the current slot entity under operation */
    pldm_entity currentOnGoingSlotEntity;
};

} // namespace responder
} // namespace pldm
