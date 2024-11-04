#pragma once

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Inventory/Item/Board/Motherboard/server.hpp>

#include <string>

namespace pldm
{
namespace dbus
{
using ItemMotherboard =
    sdbusplus::server::object_t<sdbusplus::xyz::openbmc_project::Inventory::
                                    Item::Board::server::Motherboard>;

/** @class Motherboard
 *  @brief This class is mapped to Inventory.Item.Board.Motherboard properties
 *         in D-Bus interface path.
 */
class Motherboard : public ItemMotherboard
{
  public:
    Motherboard() = delete;
    ~Motherboard() = default;
    Motherboard(const Motherboard&) = delete;
    Motherboard& operator=(const Motherboard&) = delete;
    Motherboard(Motherboard&&) = delete;
    Motherboard& operator=(Motherboard&&) = delete;

    Motherboard(sdbusplus::bus_t& bus, const std::string& objPath) :
        ItemMotherboard(bus, objPath.c_str())
    {}
};

} // namespace dbus
} // namespace pldm
