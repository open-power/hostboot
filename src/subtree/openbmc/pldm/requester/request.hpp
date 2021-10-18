#pragma once

#include "libpldm/base.h"
#include "libpldm/requester/pldm.h"

#include "common/types.hpp"
#include "common/utils.hpp"

#include <sdbusplus/timer.hpp>
#include <sdeventplus/event.hpp>

#include <chrono>
#include <functional>
#include <iostream>

namespace pldm
{

namespace requester
{

/** @class RequestRetryTimer
 *
 *  The abstract base class for implementing the PLDM request retry logic. This
 *  class handles number of times the PLDM request needs to be retried if the
 *  response is not received and the time to wait between each retry. It
 *  provides APIs to start and stop the request flow.
 */
class RequestRetryTimer
{
  public:
    RequestRetryTimer() = delete;
    RequestRetryTimer(const RequestRetryTimer&) = delete;
    RequestRetryTimer(RequestRetryTimer&&) = default;
    RequestRetryTimer& operator=(const RequestRetryTimer&) = delete;
    RequestRetryTimer& operator=(RequestRetryTimer&&) = default;
    virtual ~RequestRetryTimer() = default;

    /** @brief Constructor
     *
     *  @param[in] event - reference to PLDM daemon's main event loop
     *  @param[in] numRetries - number of request retries
     *  @param[in] timeout - time to wait between each retry in milliseconds
     */
    explicit RequestRetryTimer(sdeventplus::Event& event, uint8_t numRetries,
                               std::chrono::milliseconds timeout) :

        event(event),
        numRetries(numRetries), timeout(timeout),
        timer(event.get(), std::bind_front(&RequestRetryTimer::callback, this))
    {}

    /** @brief Starts the request flow and arms the timer for request retries
     *
     *  @return return PLDM_SUCCESS on success and PLDM_ERROR otherwise
     */
    int start()
    {
        auto rc = send();
        if (rc)
        {
            return rc;
        }

        try
        {
            if (numRetries)
            {
                timer.start(duration_cast<std::chrono::microseconds>(timeout),
                            true);
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << "Failed to start the request timer. RC = " << e.what()
                      << "\n";
            return PLDM_ERROR;
        }

        return PLDM_SUCCESS;
    }

    /** @brief Stops the timer and no further request retries happen */
    void stop()
    {
        auto rc = timer.stop();
        if (rc)
        {
            std::cerr << "Failed to stop the request timer. RC = " << rc
                      << "\n";
        }
    }

  protected:
    sdeventplus::Event& event; //!< reference to PLDM daemon's main event loop
    uint8_t numRetries;        //!< number of request retries
    std::chrono::milliseconds
        timeout;           //!< time to wait between each retry in milliseconds
    phosphor::Timer timer; //!< manages starting timers and handling timeouts

    /** @brief Sends the PLDM request message
     *
     *  @return return PLDM_SUCCESS on success and PLDM_ERROR otherwise
     */
    virtual int send() const = 0;

    /** @brief Callback function invoked when the timeout happens */
    void callback()
    {
        if (numRetries--)
        {
            send();
        }
        else
        {
            stop();
        }
    }
};

/** @class Request
 *
 *  The concrete implementation of RequestIntf. This class implements the send()
 *  to send the PLDM request message over MCTP socket.
 *  This class encapsulates the PLDM request message, the number of times the
 *  request needs to retried if the response is not received and the amount of
 *  time to wait between each retry. It provides APIs to start and stop the
 *  request flow.
 */
class Request final : public RequestRetryTimer
{
  public:
    Request() = delete;
    Request(const Request&) = delete;
    Request(Request&&) = default;
    Request& operator=(const Request&) = delete;
    Request& operator=(Request&&) = default;
    ~Request() = default;

    /** @brief Constructor
     *
     *  @param[in] fd - fd of the MCTP communication socket
     *  @param[in] eid - endpoint ID of the remote MCTP endpoint
     *  @param[in] event - reference to PLDM daemon's main event loop
     *  @param[in] requestMsg - PLDM request message
     *  @param[in] numRetries - number of request retries
     *  @param[in] timeout - time to wait between each retry in milliseconds
     *  @param[in] verbose - verbose tracing flag
     */
    explicit Request(int fd, mctp_eid_t eid, sdeventplus::Event& event,
                     pldm::Request&& requestMsg, uint8_t numRetries,
                     std::chrono::milliseconds timeout, bool verbose) :
        RequestRetryTimer(event, numRetries, timeout),
        fd(fd), eid(eid), requestMsg(std::move(requestMsg)), verbose(verbose)
    {}

  private:
    int fd;                   //!< file descriptor of MCTP communications socket
    mctp_eid_t eid;           //!< endpoint ID of the remote MCTP endpoint
    pldm::Request requestMsg; //!< PLDM request message
    bool verbose;             //!< verbose tracing flag

    /** @brief Sends the PLDM request message on the socket
     *
     *  @return return PLDM_SUCCESS on success and PLDM_ERROR otherwise
     */
    int send() const
    {
        if (verbose)
        {
            pldm::utils::printBuffer(pldm::utils::Tx, requestMsg);
        }
        auto rc = pldm_send(eid, fd, requestMsg.data(), requestMsg.size());
        if (rc < 0)
        {
            std::cerr << "Failed to send PLDM message. RC = " << rc
                      << ", errno = " << errno << "\n";
            return PLDM_ERROR;
        }
        return PLDM_SUCCESS;
    }
};

} // namespace requester

} // namespace pldm
