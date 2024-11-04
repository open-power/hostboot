#pragma once

#include "pldmd/dbus_impl_pdr.hpp"
#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"

#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Led/Group/server.hpp>

#include <string>

using namespace pldm::dbus_api;

namespace pldm
{
namespace led
{

using LEDGroupObj = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Led::server::Group>;

class HostLampTestInterfaces
{
  public:
    virtual ~HostLampTestInterfaces() {}

    virtual uint16_t getEffecterID() = 0;
    virtual uint8_t setHostStateEffecter(uint16_t effecterID) = 0;
};

/** @class HostLampTest
 *  @brief Manages group of Host lamp test LEDs
 */
class HostLampTest : public HostLampTestInterfaces, public LEDGroupObj
{
  public:
    HostLampTest() = delete;
    ~HostLampTest() = default;
    HostLampTest(const HostLampTest&) = delete;
    HostLampTest& operator=(const HostLampTest&) = delete;
    HostLampTest(HostLampTest&&) = delete;
    HostLampTest& operator=(HostLampTest&&) = delete;

    /** @brief Constructs LED Group
     *
     * @param[in] bus           - Handle to system dbus
     * @param[in] objPath       - The D-Bus path that hosts LED group
     * @param[in] mctp_fd       - MCTP file descriptor
     * @param[in] mctp_eid      - MCTP EID
     * @param[in] instanceIdDb  - InstanceIdDb object to obtain instance id
     * @param[in] repo          - pointer to BMC's primary PDR repo
     * @param[in] handler       - PLDM request handler
     */
    HostLampTest(sdbusplus::bus_t& bus, const std::string& objPath,
                 uint8_t mctp_eid, pldm::InstanceIdDb& instanceIdDb,
                 pldm_pdr* repo,
                 pldm::requester::Handler<pldm::requester::Request>* handler) :
        LEDGroupObj(bus, objPath.c_str()), path(objPath), mctp_eid(mctp_eid),
        instanceIdDb(instanceIdDb), pdrRepo(repo), handler(handler)
    {}

    /** @brief Property SET Override function
     *
     *  @param[in]  value   -  True or False
     *  @return             -  Success or exception thrown
     */
    bool asserted(bool value) override;

    /** @brief Property GET Override function
     *
     *  @return             -  True or False
     */
    bool asserted() const override;

    /** @brief Get effecterID from PDRs.
     *
     *  @return effecterID
     */
    uint16_t getEffecterID() override;

    /** @brief Set state effecter states to PHYP.
     *
     *  @param[in]  effecterID   -  effecterID
     *
     *  @return  rc              -  PLDM completion codes
     */
    uint8_t setHostStateEffecter(uint16_t effecterID) override;

  private:
    /** @brief Path of the group instance */
    std::string path;

    /** @brief MCTP EID of host firmware */
    uint8_t mctp_eid;

    /** @brief Reference to the InstanceIdDb object to obtain instance id
     */
    pldm::InstanceIdDb& instanceIdDb;

    /** @brief pointer to BMC's primary PDR repo */
    const pldm_pdr* pdrRepo;

    /** @brief Effecter ID */
    uint16_t effecterID = 0;

    /** @brief PLDM request handler */
    pldm::requester::Handler<pldm::requester::Request>* handler;
};

} // namespace led
} // namespace pldm
