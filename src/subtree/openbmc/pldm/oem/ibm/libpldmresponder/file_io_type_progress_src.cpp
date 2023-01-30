#include "file_io_type_progress_src.hpp"

#include "common/utils.hpp"

namespace pldm
{

namespace responder
{

int ProgressCodeHandler::setRawBootProperty(
    const std::tuple<uint64_t, std::vector<uint8_t>>& progressCodeBuffer)
{
    static constexpr auto RawObjectPath =
        "/xyz/openbmc_project/state/boot/raw0";
    static constexpr auto RawInterface = "xyz.openbmc_project.State.Boot.Raw";
    static constexpr auto FreedesktopInterface =
        "org.freedesktop.DBus.Properties";
    static constexpr auto RawProperty = "Value";
    static constexpr auto SetMethod = "Set";

    auto& bus = pldm::utils::DBusHandler::getBus();

    try
    {
        auto service =
            pldm::utils::DBusHandler().getService(RawObjectPath, RawInterface);
        auto method = bus.new_method_call(service.c_str(), RawObjectPath,
                                          FreedesktopInterface, SetMethod);
        method.append(RawInterface, RawProperty,
                      std::variant<std::tuple<uint64_t, std::vector<uint8_t>>>(
                          progressCodeBuffer));

        bus.call_noreply(method);
    }
    catch (const std::exception& e)
    {
        std::cerr << "failed to make a d-bus call to host-postd daemon, ERROR="
                  << e.what() << "\n";
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

int ProgressCodeHandler::write(const char* buffer, uint32_t /*offset*/,
                               uint32_t& length,
                               oem_platform::Handler* /*oemPlatformHandler*/)
{
    static constexpr auto StartOffset = 40;
    static constexpr auto EndOffset = 48;
    if (buffer != nullptr)
    {
        // read the data from the pointed location
        std::vector<uint8_t> secondaryCode(buffer, buffer + length);

        // Get the primary code from the offset 40 bytes in the received buffer

        std::vector<uint8_t> primaryCodeArray(
            secondaryCode.begin() + StartOffset,
            secondaryCode.begin() + EndOffset);
        uint64_t primaryCode = 0;

        // form a uint64_t using uint8_t[8]
        for (int i = 0; i < 8; i++)
            primaryCode |= (uint64_t)primaryCodeArray[i] << 8 * i;

        return setRawBootProperty(std::make_tuple(primaryCode, secondaryCode));
    }
    return PLDM_ERROR;
}

} // namespace responder
} // namespace pldm
