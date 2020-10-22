#pragma once

#include "libpldm/requester/pldm.h"

#include "common/types.hpp"

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <sdbusplus/timer.hpp>
#include <sdeventplus/event.hpp>

namespace pldm
{

/** @class SoftPowerOff
 *  @brief Responsible for coordinating Host SoftPowerOff operation
 */
class SoftPowerOff
{
  public:
    /** @brief Constructs SoftPowerOff object.
     *
     *  @param[in] bus       - system D-Bus handler
     *  @param[in] event     - sd_event handler
     */
    SoftPowerOff(sdbusplus::bus::bus& bus, sd_event* event);

    /** @brief Is the pldm-softpoweroff has error.
     * if hasError is true, that means the pldm-softpoweroff failed to
     * trigger the host soft off,so the pldm-softpoweroff will exit.
     */
    inline bool isError()
    {
        return hasError;
    }

    /** @brief Is the timer expired.
     */
    inline bool isTimerExpired()
    {
        return timer.isExpired();
    }

    /** @brief Is the host soft off completed.
     */
    inline bool isCompleted()
    {
        return completed;
    }

    /** @brief Is receive the response for the PLDM request msg.
     */
    inline bool isReceiveResponse()
    {
        return responseReceived;
    }

    /** @brief Send PLDM Set State Effecter States command and
     * wait the host gracefully shutdown.
     *
     *  @param[in] event - The event loop.
     *
     *  @return PLDM_SUCCESS or PLDM_ERROR.
     */
    int hostSoftOff(sdeventplus::Event& event);

  private:
    /** @brief Getting the host current state.
     */
    int getHostState();

    /** @brief Stop the timer.
     */
    inline auto stopTimer()
    {
        return timer.stop();
    }

    /** @brief When host soft off completed, stop the timer and
     *         set the completed to true.
     *
     *  @param[in] msg - Data associated with subscribed signal
     */
    void hostSoftOffComplete(sdbusplus::message::message& msg);

    /** @brief Start the timer.
     *
     *  @param[in] usec - Time to wait for the Host to gracefully shutdown.
     *
     *  @return Success or exception thrown
     */
    int startTimer(const std::chrono::microseconds& usec);

    /** @brief Get effecterID from PDRs.
     *
     *  @return PLDM_SUCCESS or PLDM_ERROR
     */
    int getEffecterID();

    /** @brief Get VMM/SystemFirmware Sensor info from PDRs.
     *
     *  @return PLDM_SUCCESS or PLDM_ERROR
     */
    int getSensorInfo();

    /** @brief effecterID
     */
    uint16_t effecterID;

    /** @brief sensorID.
     */
    pldm::pdr::SensorID sensorID;

    /** @brief sensorOffset.
     */
    pldm::pdr::SensorOffset sensorOffset;

    /** @brief Failed to send host soft off command flag.
     */
    bool hasError = false;

    /** @brief Host soft off completed flag.
     */
    bool completed = false;

    /** @brief The response for the PLDM request msg is received flag.
     */
    bool responseReceived = false;

    /** @brief Is the Virtual Machine Manager/VMM state effecter available.
     */
    bool VMMPdrExist = true;

    /* @brief sdbusplus handle */
    sdbusplus::bus::bus& bus;

    /** @brief Reference to Timer object */
    phosphor::Timer timer;

    /** @brief Used to subscribe to dbus pldm StateSensorEvent signal
     * When the host soft off is complete, it sends an platform event message
     * to BMC's pldmd, and the pldmd will emit the StateSensorEvent signal.
     **/
    std::unique_ptr<sdbusplus::bus::match_t> pldmEventSignal;
};

} // namespace pldm
