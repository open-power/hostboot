#pragma once

#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"

#include <vector>

namespace pldm
{
namespace responder
{
namespace platform
{

/** @brief To send BIOS attribute update event
 *
 *  When the attribute value changes for any BIOS attribute, then
 *  PlatformEventMessage command with OEM event type
 *  PLDM_EVENT_TYPE_OEM_EVENT_BIOS_ATTRIBUTE_UPDATE is send to host with the
 *  list of BIOS attribute handles.
 *
 *  @param[in] eid - MCTP EID of host firmware
 *  @param[in] requester - pointer to Requester object
 *  @param[in] handles - List of BIOS attribute handles
 *  @param[in] handler - PLDM request handler
 */
int sendBiosAttributeUpdateEvent(
    uint8_t eid, dbus_api::Requester* requester,
    const std::vector<uint16_t>& handles,
    pldm::requester::Handler<pldm::requester::Request>* handler);

} // namespace platform

} // namespace responder

} // namespace pldm
