#pragma once

#include "libpldm/platform.h"

#include "libpldmresponder/pdr_utils.hpp"
#include "pldmd/dbus_impl_requester.hpp"

#include <map>

using namespace pldm::dbus_api;
using namespace pldm::responder;

namespace pldm
{

using SensorId = uint16_t;
using DbusObjMaps =
    std::map<SensorId,
             std::tuple<pdr_utils::DbusMappings, pdr_utils::DbusValMaps>>;
using sensorEvent =
    std::function<void(SensorId sensorId, const DbusObjMaps& dbusMaps)>;

namespace state_sensor
{
/** @class DbusToPLDMEvent
 *  @brief This class can listen to the state sensor PDRs and send PLDM event
 *         msg when a D-Bus property changes
 */
class DbusToPLDMEvent
{
  public:
    DbusToPLDMEvent() = delete;
    DbusToPLDMEvent(const DbusToPLDMEvent&) = delete;
    DbusToPLDMEvent(DbusToPLDMEvent&&) = delete;
    DbusToPLDMEvent& operator=(const DbusToPLDMEvent&) = delete;
    DbusToPLDMEvent& operator=(DbusToPLDMEvent&&) = delete;
    ~DbusToPLDMEvent() = default;

    /** @brief Constructor
     *  @param[in] mctp_fd - fd of MCTP communications socket
     *  @param[in] mctp_eid - MCTP EID of host firmware
     *  @param[in] requester - reference to Requester object
     */
    explicit DbusToPLDMEvent(int mctp_fd, uint8_t mctp_eid,
                             Requester& requester);

  public:
    /** @brief Listen all of the state sensor PDRs
     *  @param[in] repo - pdr utils repo object
     *  @param[in] dbusMaps - The map of D-Bus mapping and value
     */
    void listenSensorEvent(const pdr_utils::Repo& repo,
                           const DbusObjMaps& dbusMaps);

  private:
    /** @brief Send state sensor event msg when a D-Bus property changes
     *  @param[in] sensorId - sensor id
     */
    void sendStateSensorEvent(SensorId sensorId, const DbusObjMaps& dbusMaps);

    /** @brief Send all of sensor event
     *  @param[in] eventType - PLDM Event types
     *  @param[in] eventDataVec - std::vector, contains send event data
     */
    void sendEventMsg(uint8_t eventType,
                      const std::vector<uint8_t>& eventDataVec);

    /** @brief fd of MCTP communications socket */
    int mctp_fd;

    /** @brief MCTP EID of host firmware */
    uint8_t mctp_eid;

    /** @brief reference to Requester object, primarily used to access API to
     *  obtain PLDM instance id.
     */
    Requester& requester;

    /** @brief D-Bus property changed signal match */
    std::vector<std::unique_ptr<sdbusplus::bus::match::match>>
        stateSensorMatchs;
};

} // namespace state_sensor
} // namespace pldm
