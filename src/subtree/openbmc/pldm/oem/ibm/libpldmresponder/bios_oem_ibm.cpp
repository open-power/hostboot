#include "bios_oem_ibm.hpp"

namespace pldm
{
namespace responder
{
namespace oem::ibm::bios
{
/** @brief Method to get the system type information
 *
 *  @return - the system type information
 */
std::optional<std::string>
    pldm::responder::oem::ibm::bios::Handler::getPlatformName()
{
    if (!systemType.empty())
    {
        return systemType;
    }

    static constexpr auto searchpath = "/xyz/openbmc_project/";
    int depth = 0;
    std::vector<std::string> ibmCompatible = {compatibleInterface};
    pldm::utils::GetSubTreeResponse response;
    try
    {
        response = pldm::utils::DBusHandler().getSubtree(searchpath, depth,
                                                         ibmCompatible);
    }
    catch (const sdbusplus::exception_t& e)
    {
        error(
            " getSubtree call failed with, ERROR={ERROR} PATH={PATH} INTERFACE={INTERFACE}",
            "ERROR", e.what(), "PATH", searchpath, "INTERFACE",
            ibmCompatible[0]);
        return std::nullopt;
    }

    for (const auto& [objectPath, serviceMap] : response)
    {
        try
        {
            auto value = pldm::utils::DBusHandler()
                             .getDbusProperty<std::vector<std::string>>(
                                 objectPath.c_str(), namesProperty,
                                 ibmCompatible[0].c_str());
            return value[0];
        }
        catch (const sdbusplus::exception_t& e)
        {
            error(
                " Error getting Names property, ERROR={ERROR} PATH={PATH} INTERFACE={INTERFACE}",
                "ERROR", e.what(), "PATH", searchpath, "INTERFACE",
                ibmCompatible[0]);
        }
    }
    return std::nullopt;
}

/** @brief callback function invoked when interfaces get added from
 *      Entity manager
 *
 *  @param[in] msg - Data associated with subscribed signal
 */
void pldm::responder::oem::ibm::bios::Handler::ibmCompatibleAddedCallback(
    sdbusplus::message_t& msg)
{
    sdbusplus::message::object_path path;

    pldm::utils::InterfaceMap interfaceMap;

    msg.read(path, interfaceMap);

    if (!interfaceMap.contains(compatibleInterface))
    {
        return;
    }
    // Get the "Name" property value of the
    // "xyz.openbmc_project.Configuration.IBMCompatibleSystem" interface
    const auto& properties = interfaceMap.at(compatibleInterface);

    if (!properties.contains(namesProperty))
    {
        return;
    }
    auto names =
        std::get<pldm::utils::Interfaces>(properties.at(namesProperty));

    // get only the first system type
    if (!names.empty())
    {
        systemType = names.front();
    }

    if (!systemType.empty())
    {
        ibmCompatibleMatchConfig.reset();
    }
}

} // namespace oem::ibm::bios
} // namespace responder
} // namespace pldm
