#pragma once

#include "fw-update/update_manager.hpp"

#include <sdbusplus/bus.hpp>
#include <xyz/openbmc_project/Object/Delete/server.hpp>
#include <xyz/openbmc_project/Software/Activation/server.hpp>
#include <xyz/openbmc_project/Software/ActivationProgress/server.hpp>

#include <string>

namespace pldm
{

namespace fw_update
{

using ActivationIntf = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Software::server::Activation>;
using ActivationProgressIntf = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Software::server::ActivationProgress>;
using DeleteIntf = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Object::server::Delete>;

/** @class ActivationProgress
 *
 *  Concrete implementation of xyz.openbmc_project.Software.ActivationProgress
 *  D-Bus interface
 */
class ActivationProgress : public ActivationProgressIntf
{
  public:
    /** @brief Constructor
     *
     * @param[in] bus - Bus to attach to
     * @param[in] objPath - D-Bus object path
     */
    ActivationProgress(sdbusplus::bus::bus& bus, const std::string& objPath) :
        ActivationProgressIntf(bus, objPath.c_str(),
                               action::emit_interface_added)
    {
        progress(0);
    }
};

/** @class Delete
 *
 *  Concrete implementation of xyz.openbmc_project.Object.Delete D-Bus interface
 */
class Delete : public DeleteIntf
{
  public:
    /** @brief Constructor
     *
     *  @param[in] bus - Bus to attach to
     *  @param[in] objPath - D-Bus object path
     *  @param[in] updateManager - Reference to FW update manager
     */
    Delete(sdbusplus::bus::bus& bus, const std::string& objPath,
           UpdateManager* updateManager) :
        DeleteIntf(bus, objPath.c_str(), action::emit_interface_added),
        updateManager(updateManager)
    {}

    /** @brief Delete the Activation D-Bus object for the FW update package */
    void delete_() override
    {
        updateManager->clearActivationInfo();
    }

  private:
    UpdateManager* updateManager;
};

/** @class Activation
 *
 *  Concrete implementation of xyz.openbmc_project.Object.Activation D-Bus
 *  interface
 */
class Activation : public ActivationIntf
{
  public:
    /** @brief Constructor
     *
     *  @param[in] bus - Bus to attach to
     *  @param[in] objPath - D-Bus object path
     *  @param[in] updateManager - Reference to FW update manager
     */
    Activation(sdbusplus::bus::bus& bus, std::string objPath,
               Activations activationStatus, UpdateManager* updateManager) :
        ActivationIntf(bus, objPath.c_str(), true),
        bus(bus), objPath(objPath), updateManager(updateManager)
    {
        activation(activationStatus);
        deleteImpl = std::make_unique<Delete>(bus, objPath, updateManager);
        emit_object_added();
    }

    using sdbusplus::xyz::openbmc_project::Software::server::Activation::
        activation;
    using sdbusplus::xyz::openbmc_project::Software::server::Activation::
        requestedActivation;

    /** @brief Overriding Activation property setter function
     */
    Activations activation(Activations value) override
    {
        if (value == Activations::Activating)
        {
            deleteImpl.reset();
            updateManager->activatePackage();
        }
        else if (value == Activations::Active || value == Activations::Failed)
        {
            if (!deleteImpl)
            {
                deleteImpl =
                    std::make_unique<Delete>(bus, objPath, updateManager);
            }
        }

        return ActivationIntf::activation(value);
    }

    /** @brief Overriding RequestedActivations property setter function
     */
    RequestedActivations
        requestedActivation(RequestedActivations value) override
    {
        if ((value == RequestedActivations::Active) &&
            (requestedActivation() != RequestedActivations::Active))
        {
            if ((ActivationIntf::activation() == Activations::Ready))
            {
                activation(Activations::Activating);
            }
        }
        return ActivationIntf::requestedActivation(value);
    }

  private:
    sdbusplus::bus::bus& bus;
    const std::string objPath;
    UpdateManager* updateManager;
    std::unique_ptr<Delete> deleteImpl;
};

} // namespace fw_update

} // namespace pldm
