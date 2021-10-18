#pragma once

#include "libpldm/base.h"

#include "libpldmresponder/platform.hpp"
#include "pldmd/handler.hpp"
#include "requester/handler.hpp"

#include <stdint.h>

#include <sdeventplus/source/event.hpp>

#include <vector>

using namespace pldm::dbus_api;
using namespace pldm::responder;

namespace pldm
{
namespace responder
{
namespace base
{

class Handler : public CmdHandler
{
  public:
    Handler(uint8_t eid, Requester& requester, sdeventplus::Event& event,
            pldm::responder::oem_platform::Handler* oemPlatformHandler,
            pldm::requester::Handler<pldm::requester::Request>* handler) :
        eid(eid),
        requester(requester), event(event),
        oemPlatformHandler(oemPlatformHandler), handler(handler)
    {
        handlers.emplace(PLDM_GET_PLDM_TYPES,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getPLDMTypes(request, payloadLength);
                         });
        handlers.emplace(PLDM_GET_PLDM_COMMANDS, [this](const pldm_msg* request,
                                                        size_t payloadLength) {
            return this->getPLDMCommands(request, payloadLength);
        });
        handlers.emplace(PLDM_GET_PLDM_VERSION, [this](const pldm_msg* request,
                                                       size_t payloadLength) {
            return this->getPLDMVersion(request, payloadLength);
        });
        handlers.emplace(PLDM_GET_TID,
                         [this](const pldm_msg* request, size_t payloadLength) {
                             return this->getTID(request, payloadLength);
                         });
    }

    /** @brief Handler for getPLDMTypes
     *
     *  @param[in] request - Request message payload
     *  @param[in] payload_length - Request message payload length
     *  @param[return] Response - PLDM Response message
     */
    Response getPLDMTypes(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for getPLDMCommands
     *
     *  @param[in] request - Request message payload
     *  @param[in] payload_length - Request message payload length
     *  @param[return] Response - PLDM Response message
     */
    Response getPLDMCommands(const pldm_msg* request, size_t payloadLength);

    /** @brief Handler for getPLDMCommands
     *
     *  @param[in] request - Request message payload
     *  @param[in] payload_length - Request message payload length
     *  @param[return] Response - PLDM Response message
     */
    Response getPLDMVersion(const pldm_msg* request, size_t payloadLength);

    /** @brief _processSetEventReceiver does the actual work that needs
     *  to be carried out for setEventReceiver command. This is deferred
     *  after sending response for getTID command to the host
     *
     *  @param[in] source - sdeventplus event source
     */
    void processSetEventReceiver(sdeventplus::source::EventBase& source);

    /** @brief Handler for getTID
     *
     *  @param[in] request - Request message payload
     *  @param[in] payload_length - Request message payload length
     *  @param[return] Response - PLDM Response message
     */
    Response getTID(const pldm_msg* request, size_t payloadLength);

  private:
    /** @brief MCTP EID of host firmware */
    uint8_t eid;

    /** @brief reference to Requester object, primarily used to access API to
     *  obtain PLDM instance id.
     */
    Requester& requester;

    /** @brief reference of main event loop of pldmd, primarily used to schedule
     *  work
     */
    sdeventplus::Event& event;

    /** @brief OEM platform handler */
    pldm::responder::oem_platform::Handler* oemPlatformHandler;

    /** @brief PLDM request handler */
    pldm::requester::Handler<pldm::requester::Request>* handler;

    /** @brief sdeventplus event source */
    std::unique_ptr<sdeventplus::source::Defer> survEvent;
};

} // namespace base
} // namespace responder
} // namespace pldm
