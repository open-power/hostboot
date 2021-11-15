#pragma once

#include "libpldm/requester/pldm.h"

#include "activation.hpp"
#include "common/types.hpp"
#include "device_updater.hpp"
#include "inventory_manager.hpp"
#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"
#include "update_manager.hpp"

#include <unordered_map>
#include <vector>

namespace pldm
{

namespace fw_update
{

using namespace pldm::dbus_api;

/** @class Manager
 *
 * This class handles all the aspects of the PLDM FW update specification for
 * the MCTP devices
 */
class Manager
{

  public:
    Manager() = delete;
    Manager(const Manager&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager& operator=(Manager&&) = delete;
    ~Manager() = default;

    /** @brief Constructor
     *
     *  @param[in] handler - PLDM request handler
     */
    explicit Manager(Event& event,
                     requester::Handler<requester::Request>& handler,
                     Requester& requester) :
        inventoryMgr(handler, requester, descriptorMap, componentInfoMap),
        updateManager(event, handler, requester, descriptorMap,
                      componentInfoMap)
    {}

    /** @brief Discover MCTP endpoints that support the PLDM firmware update
     *         specification
     *
     *  @param[in] eids - Array of MCTP endpoints
     *
     *  @return return PLDM_SUCCESS on success and PLDM_ERROR otherwise
     */
    void handleMCTPEndpoints(const std::vector<mctp_eid_t>& eids)
    {
        inventoryMgr.discoverFDs(eids);
    }

    /** @brief Handle PLDM request for the commands in the FW update
     *         specification
     *
     *  @param[in] eid - Remote MCTP Endpoint ID
     *  @param[in] command - PLDM command code
     *  @param[in] request - PLDM request message
     *  @param[in] requestLen - PLDM request message length
     *  @return PLDM response message
     */
    Response handleRequest(mctp_eid_t eid, Command command,
                           const pldm_msg* request, size_t reqMsgLen)
    {
        return updateManager.handleRequest(eid, command, request, reqMsgLen);
    }

  private:
    /** Descriptor information of all the discovered MCTP endpoints */
    DescriptorMap descriptorMap;

    /** Component information of all the discovered MCTP endpoints */
    ComponentInfoMap componentInfoMap;

    /** @brief PLDM firmware inventory manager */
    InventoryManager inventoryMgr;

    /** @brief PLDM firmware update manager */
    UpdateManager updateManager;
};

} // namespace fw_update

} // namespace pldm
