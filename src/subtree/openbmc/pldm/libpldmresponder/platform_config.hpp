#pragma once
#include "common/utils.hpp"
#include "pldmd/handler.hpp"

namespace pldm
{
namespace responder
{

namespace platform_config
{
using namespace pldm::utils;

static constexpr auto compatibleInterface =
    "xyz.openbmc_project.Inventory.Decorator.Compatible";
static constexpr auto namesProperty = "Names";

using SystemTypeCallback = std::function<void(const std::string&, bool)>;

class Handler : public CmdHandler
{
  public:
    Handler(const fs::path sysDirPath = {}) : sysDirPath(sysDirPath)
    {
        systemCompatibleMatchCallBack =
            std::make_unique<sdbusplus::bus::match_t>(
                pldm::utils::DBusHandler::getBus(),
                sdbusplus::bus::match::rules::interfacesAdded() +
                    sdbusplus::bus::match::rules::sender(
                        "xyz.openbmc_project.EntityManager"),
                std::bind(&Handler::systemCompatibleCallback, this,
                          std::placeholders::_1));
        sysTypeCallback = nullptr;
    }

    /** @brief Interface to get the system type information using Dbus query
     *
     *  @return - the system type information
     */
    virtual std::optional<std::filesystem::path> getPlatformName();

    /** @brief D-Bus Interface added signal match for Entity Manager */
    void systemCompatibleCallback(sdbusplus::message_t& msg);

    /** @brief Registers the callback from other objects */
    void registerSystemTypeCallback(SystemTypeCallback callback);

  private:
    /** @brief Interface to get the first available directory
     *         from the received list
     *
     *  @param[in] dirPath  - Directory path to search system specific directory
     *  @param[in] dirNames - System names retrieved from remote application
     *  @return - The system type information
     */
    std::optional<std::string> getSysSpecificJsonDir(
        const fs::path& dirPath, const std::vector<std::string>& dirNames);

    /** @brief system type/model */
    std::string systemType;

    /** @brief D-Bus Interface added signal match for Entity Manager */
    std::unique_ptr<sdbusplus::bus::match_t> systemCompatibleMatchCallBack;

    /** @brief Registered Callback */
    SystemTypeCallback sysTypeCallback;

    /** @brief system specific json file directory path */
    fs::path sysDirPath;
};

} // namespace platform_config

} // namespace responder

} // namespace pldm
