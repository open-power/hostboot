#pragma once
#include "libpldm/entity.h"
#include "libpldm/platform.h"
#include "oem/ibm/libpldm/state_set.h"

#include "inband_code_update.hpp"
#include "libpldmresponder/oem_handler.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "libpldmresponder/platform.hpp"
#include "requester/handler.hpp"

typedef ibm_oem_pldm_state_set_firmware_update_state_values CodeUpdateState;

namespace pldm
{
namespace responder
{
namespace oem_ibm_platform
{
static constexpr auto PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE = 24577;
constexpr uint16_t ENTITY_INSTANCE_0 = 0;
constexpr uint16_t ENTITY_INSTANCE_1 = 1;

enum SetEventReceiverCount
{
    SET_EVENT_RECEIVER_SENT = 0x2,
};

class Handler : public oem_platform::Handler
{
  public:
    Handler(const pldm::utils::DBusHandler* dBusIntf,
            pldm::responder::CodeUpdate* codeUpdate, int mctp_fd,
            uint8_t mctp_eid, pldm::dbus_api::Requester& requester,
            sdeventplus::Event& event,
            pldm::requester::Handler<pldm::requester::Request>* handler) :
        oem_platform::Handler(dBusIntf),
        codeUpdate(codeUpdate), platformHandler(nullptr), mctp_fd(mctp_fd),
        mctp_eid(mctp_eid), requester(requester), event(event), handler(handler)
    {
        codeUpdate->setVersions();
        setEventReceiverCnt = 0;

        using namespace sdbusplus::bus::match::rules;
        hostOffMatch = std::make_unique<sdbusplus::bus::match::match>(
            pldm::utils::DBusHandler::getBus(),
            propertiesChanged("/xyz/openbmc_project/state/host0",
                              "xyz.openbmc_project.State.Host"),
            [this](sdbusplus::message::message& msg) {
                pldm::utils::DbusChangedProps props{};
                std::string intf;
                msg.read(intf, props);
                const auto itr = props.find("CurrentHostState");
                if (itr != props.end())
                {
                    pldm::utils::PropertyValue value = itr->second;
                    auto propVal = std::get<std::string>(value);
                    if (propVal ==
                        "xyz.openbmc_project.State.Host.HostState.Off")
                    {
                        hostOff = true;
                        setEventReceiverCnt = 0;
                        disableWatchDogTimer();
                    }
                    else if (propVal ==
                             "xyz.openbmc_project.State.Host.HostState.Running")
                    {
                        hostOff = false;
                    }
                }
            });
    }

    int getOemStateSensorReadingsHandler(
        EntityType entityType, pldm::pdr::EntityInstance entityInstance,
        pldm::pdr::StateSetId stateSetId,
        pldm::pdr::CompositeCount compSensorCnt,
        std::vector<get_sensor_state_field>& stateField);

    int oemSetStateEffecterStatesHandler(
        uint16_t entityType, uint16_t entityInstance, uint16_t stateSetId,
        uint8_t compEffecterCnt,
        std::vector<set_effecter_state_field>& stateField, uint16_t effecterId);

    /** @brief Method to set the platform handler in the
     *         oem_ibm_handler class
     *  @param[in] handler - pointer to PLDM platform handler
     */
    void setPlatformHandler(pldm::responder::platform::Handler* handler);

    /** @brief Method to fetch the effecter ID of the code update PDRs
     *
     * @return platformHandler->getNextEffecterId() - returns the
     *             effecter ID from the platform handler
     */
    virtual uint16_t getNextEffecterId()
    {
        return platformHandler->getNextEffecterId();
    }

    /** @brief Method to fetch the sensor ID of the code update PDRs
     *
     * @return platformHandler->getNextSensorId() - returns the
     *             Sensor ID from the platform handler
     */
    virtual uint16_t getNextSensorId()
    {
        return platformHandler->getNextSensorId();
    }

    /** @brief Method to Generate the OEM PDRs
     *
     * @param[in] repo - instance of concrete implementation of Repo
     */
    void buildOEMPDR(pdr_utils::Repo& repo);

    /** @brief Method to send code update event to host
     * @param[in] sensorId - sendor ID
     * @param[in] sensorEventClass - event class of sensor
     * @param[in] sensorOffset - sensor offset
     * @param[in] eventState - new code update event state
     * @param[in] prevEventState - previous code update event state
     * @return none
     */
    void sendStateSensorEvent(uint16_t sensorId,
                              enum sensor_event_class_states sensorEventClass,
                              uint8_t sensorOffset, uint8_t eventState,
                              uint8_t prevEventState);

    /** @brief Method to send encoded request msg of code update event to host
     *  @param[in] requestMsg - encoded request msg
     *  @param[in] instanceId - instance id of the message
     *  @return PLDM status code
     */
    int sendEventToHost(std::vector<uint8_t>& requestMsg, uint8_t instanceId);

    /** @brief _processEndUpdate processes the actual work that needs
     *  to be carried out after EndUpdate effecter is set. This is done async
     *  after sending response for EndUpdate set effecter
     *  @param[in] source - sdeventplus event source
     */
    void _processEndUpdate(sdeventplus::source::EventBase& source);

    /** @brief _processStartUpdate processes the actual work that needs
     *  to be carried out after StartUpdate effecter is set. This is done async
     *  after sending response for StartUpdate set effecter
     *  @param[in] source - sdeventplus event source
     */
    void _processStartUpdate(sdeventplus::source::EventBase& source);

    /** @brief _processSystemReboot processes the actual work that needs to be
     *  carried out after the System Power State effecter is set to reboot
     *  the system
     *  @param[in] source - sdeventplus event source
     */
    void _processSystemReboot(sdeventplus::source::EventBase& source);

    /*keeps track how many times setEventReceiver is sent */
    void countSetEventReceiver()
    {
        setEventReceiverCnt++;
    }

    /* disables watchdog if running and Host is up */
    void checkAndDisableWatchDog();

    /** @brief To check if the watchdog app is running
     *
     *  @return the running status of watchdog app
     */
    bool watchDogRunning();

    /** @brief Method to reset the Watchdog timer on receiving platform Event
     *  Message for heartbeat elapsed time from Hostboot
     */
    void resetWatchDogTimer();

    /** @brief To disable to the watchdog timer on host poweron completion*/
    void disableWatchDogTimer();

    /** @brief to check the BMC state*/
    int checkBMCState();

    ~Handler() = default;

    pldm::responder::CodeUpdate* codeUpdate; //!< pointer to CodeUpdate object
    pldm::responder::platform::Handler*
        platformHandler; //!< pointer to PLDM platform handler

    /** @brief fd of MCTP communications socket */
    int mctp_fd;

    /** @brief MCTP EID of host firmware */
    uint8_t mctp_eid;

    /** @brief reference to Requester object, primarily used to access API to
     *  obtain PLDM instance id.
     */
    pldm::dbus_api::Requester& requester;
    /** @brief sdeventplus event source */
    std::unique_ptr<sdeventplus::source::Defer> assembleImageEvent;
    std::unique_ptr<sdeventplus::source::Defer> startUpdateEvent;
    std::unique_ptr<sdeventplus::source::Defer> systemRebootEvent;

    /** @brief reference of main event loop of pldmd, primarily used to schedule
     *  work
     */
    sdeventplus::Event& event;

  private:
    /** @brief D-Bus property changed signal match for CurrentPowerState*/
    std::unique_ptr<sdbusplus::bus::match::match> chassisOffMatch;

    /** @brief PLDM request handler */
    pldm::requester::Handler<pldm::requester::Request>* handler;

    /** @brief D-Bus property changed signal match */
    std::unique_ptr<sdbusplus::bus::match::match> hostOffMatch;

    bool hostOff = true;

    int setEventReceiverCnt = 0;
};

/** @brief Method to encode code update event msg
 *  @param[in] eventType - type of event
 *  @param[in] eventDataVec - vector of event data to be sent to host
 *  @param[in/out] requestMsg - request msg to be encoded
 *  @param[in] instanceId - instance ID
 *  @return PLDM status code
 */
int encodeEventMsg(uint8_t eventType, const std::vector<uint8_t>& eventDataVec,
                   std::vector<uint8_t>& requestMsg, uint8_t instanceId);

} // namespace oem_ibm_platform

} // namespace responder

} // namespace pldm
