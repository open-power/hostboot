#pragma once

#include "instance_id.hpp"
#include "xyz/openbmc_project/Common/error.hpp"
#include "xyz/openbmc_project/PLDM/Requester/server.hpp"

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/object.hpp>

#include <map>

namespace pldm
{
namespace dbus_api
{

using RequesterIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::PLDM::server::Requester>;

/** @class Requester
 *  @brief OpenBMC PLDM.Requester implementation.
 *  @details A concrete implementation for the
 *  xyz.openbmc_project.PLDM.Requester DBus APIs.
 */
class Requester : public RequesterIntf
{
  public:
    Requester() = delete;
    Requester(const Requester&) = delete;
    Requester& operator=(const Requester&) = delete;
    Requester(Requester&&) = delete;
    Requester& operator=(Requester&&) = delete;
    virtual ~Requester() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] db - The database to use for allocating instance IDs
     *  @note will throw TooManyResources() if there were no free instance IDs
     *  Throws std::system_category().default_error_condition if there is
     *  something wrong with the instance ID database.
     */
    Requester(sdbusplus::bus_t& bus, const std::string& path,
              InstanceIdDb& db) :
        RequesterIntf(bus, path.c_str()),
        pldmInstanceIdDb(db){};

    /** @brief Implementation for RequesterIntf.GetInstanceId */
    uint8_t getInstanceId(uint8_t eid) override
    {
        int id;

        // Ideally we would be able to look up the TID for a given EID. We don't
        // have that infrastructure in place yet. So use the EID value for the
        // TID. This is an interim step towards the PLDM requester logic moving
        // into libpldm, and eventually this won't be needed.
        try
        {
            id = pldmInstanceIdDb.next(eid);
        }
        catch (const std::runtime_error& e)
        {
            throw sdbusplus::xyz::openbmc_project::Common::Error::
                TooManyResources();
        }

        return id;
    }

    /** @brief Mark an instance id as unused
     *  @param[in] eid - MCTP eid to which this instance id belongs
     *  @param[in] instanceId - PLDM instance id to be freed
     *  @note will throw std::runtime_error if the instance ID was not
     *  previously allocated.
     *  Throws std::system_category().default_error_condition if there is
     *  something wrong with the instance ID database.
     */
    void markFree(uint8_t eid, uint8_t instanceId)
    {
        pldmInstanceIdDb.free(eid, instanceId);
    }

  private:
    InstanceIdDb& pldmInstanceIdDb;
};

} // namespace dbus_api
} // namespace pldm
