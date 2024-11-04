#pragma once

#include "libpldmresponder/platform.hpp"

#include <libpldm/base.h>

#include <sdeventplus/source/event.hpp>

#include <cstdint>
#include <vector>

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
    Handler(sdeventplus::Event& event) : event(event)
    {
        handlers.emplace(
            PLDM_GET_PLDM_TYPES,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getPLDMTypes(request, payloadLength);
            });
        handlers.emplace(
            PLDM_GET_PLDM_COMMANDS,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getPLDMCommands(request, payloadLength);
            });
        handlers.emplace(
            PLDM_GET_PLDM_VERSION,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
                return this->getPLDMVersion(request, payloadLength);
            });
        handlers.emplace(
            PLDM_GET_TID,
            [this](pldm_tid_t, const pldm_msg* request, size_t payloadLength) {
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
    void _processSetEventReceiver(sdeventplus::source::EventBase& source);

    /** @brief Handler for getTID
     *
     *  @param[in] request - Request message payload
     *  @param[in] payload_length - Request message payload length
     *  @param[return] Response - PLDM Response message
     */
    Response getTID(const pldm_msg* request, size_t payloadLength);

    /* @brief Method to set the oem platform handler in base handler class
     *
     * @param[in] handler - oem platform handler
     */
    inline void
        setOemPlatformHandler(pldm::responder::oem_platform::Handler* handler)
    {
        oemPlatformHandler = handler;
    }

  private:
    /** @brief reference of main event loop of pldmd, primarily used to schedule
     *  work
     */
    sdeventplus::Event& event;

    /** @brief OEM platform handler */
    pldm::responder::oem_platform::Handler* oemPlatformHandler = nullptr;

    /** @brief sdeventplus event source */
    std::unique_ptr<sdeventplus::source::Defer> survEvent;
};

} // namespace base
} // namespace responder
} // namespace pldm
