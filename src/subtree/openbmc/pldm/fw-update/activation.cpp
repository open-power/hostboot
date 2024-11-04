#include "fw-update/activation.hpp"

#include "fw-update/update_manager.hpp"

namespace pldm
{
namespace fw_update
{

ActivationIntf::Activations
    Activation::activation(ActivationIntf::Activations value)
{
    if (value == ActivationIntf::Activations::Activating)
    {
        deleteImpl.reset();
        updateManager->activatePackage();
    }
    else if (value == ActivationIntf::Activations::Active ||
             value == ActivationIntf::Activations::Failed)
    {
        if (!deleteImpl)
        {
            deleteImpl = std::make_unique<Delete>(bus, objPath, updateManager);
        }
    }

    return ActivationIntf::activation(value);
}

void Delete::delete_()
{
    updateManager->clearActivationInfo();
}
} // namespace fw_update
} // namespace pldm
