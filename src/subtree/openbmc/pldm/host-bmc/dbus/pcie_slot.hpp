#pragma once

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Inventory/Item/PCIeSlot/server.hpp>

#include <string>

namespace pldm
{
namespace dbus
{
using ItemSlot = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Inventory::Item::server::PCIeSlot>;

/**
 * @class PCIeSlot
 * @brief PCIeSlot support includes the slot properties and functions
 */
class PCIeSlot : public ItemSlot
{
  public:
    PCIeSlot() = delete;
    ~PCIeSlot() = default;
    PCIeSlot(const PCIeSlot&) = delete;
    PCIeSlot& operator=(const PCIeSlot&) = delete;

    PCIeSlot(sdbusplus::bus_t& bus, const std::string& objPath) :
        ItemSlot(bus, objPath.c_str())
    {}

    /** Get value of Generation */
    Generations generation() const override;

    /** Set value of Generation */
    Generations generation(Generations value) override;

    /** Get value of Lanes */
    size_t lanes() const override;

    /** Set value of Lanes */
    size_t lanes(size_t value) override;

    /** Get value of SlotType */
    SlotTypes slotType() const override;

    /** Set value of SlotType */
    SlotTypes slotType(SlotTypes value) override;

    /** Get value of HotPluggable */
    bool hotPluggable() const override;

    /** Set value of HotPluggable */
    bool hotPluggable(bool value) override;
};

} // namespace dbus
} // namespace pldm
