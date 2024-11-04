#include "manager.hpp"

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace platform_mc
{
exec::task<int> Manager::beforeDiscoverTerminus()
{
    // Add any setup or checks needed before discovering a terminus
    // If any setup/check fails, return the appropriate error code
    // For now, we assume everything is successful
    co_return PLDM_SUCCESS;
}

exec::task<int> Manager::afterDiscoverTerminus()
{
    auto rc = co_await platformManager.initTerminus();
    if (rc != PLDM_SUCCESS)
    {
        lg2::error("Failed to initialize platform manager, error {RC}", "RC",
                   rc);
    }
    else
    {
        lg2::info("Successfully initialized platform manager");
    }
    co_return rc;
}

exec::task<int> Manager::pollForPlatformEvent(
    pldm_tid_t tid, uint16_t /* pollEventId */, uint32_t pollDataTransferHandle)
{
    auto it = termini.find(tid);
    if (it != termini.end())
    {
        auto& terminus = it->second;
        co_await eventManager.pollForPlatformEventTask(tid,
                                                       pollDataTransferHandle);
        terminus->pollEvent = false;
    }
    co_return PLDM_SUCCESS;
}

} // namespace platform_mc
} // namespace pldm
