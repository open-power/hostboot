#pragma once
#include "common/utils.hpp"
#include "libpldmresponder/bios.hpp"
#include "libpldmresponder/oem_handler.hpp"

#include <filesystem>

namespace pldm
{
namespace responder
{
namespace oem::ibm::bios
{
static constexpr auto compatibleInterface =
    "xyz.openbmc_project.Configuration.IBMCompatibleSystem";
static constexpr auto namesProperty = "Names";
namespace fs = std::filesystem;
class Handler : public oem_bios::Handler
{
  public:
    Handler(const pldm::utils::DBusHandler* dBusIntf) :
        oem_bios::Handler(dBusIntf)
    {
        ibmCompatibleMatchConfig = std::make_unique<sdbusplus::bus::match_t>(
            dBusIntf->getBus(),
            sdbusplus::bus::match::rules::interfacesAdded() +
                sdbusplus::bus::match::rules::sender(
                    "xyz.openbmc_project.EntityManager"),
            std::bind_front(&Handler::ibmCompatibleAddedCallback, this));
    }

    /** @brief Method to get the system type information
     *
     *  @return - the system type information
     */
    std::optional<std::string> getPlatformName();

  private:
    /** @brief system type/model */
    std::string systemType;

    pldm::responder::bios::Handler* biosHandler;

    /** @brief D-Bus Interface added signal match for Entity Manager */
    std::unique_ptr<sdbusplus::bus::match_t> ibmCompatibleMatchConfig;

    /** @brief D-Bus Interface object*/
    const pldm::utils::DBusHandler* dBusIntf;

    /** @brief callback function invoked when interfaces get added from
     *     Entity manager
     *
     *  @param[in] msg - Data associated with subscribed signal
     */
    void ibmCompatibleAddedCallback(sdbusplus::message_t& msg);
};

} // namespace oem::ibm::bios
} // namespace responder
} // namespace pldm
