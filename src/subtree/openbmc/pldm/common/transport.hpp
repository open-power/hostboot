#pragma once

#include <libpldm/base.h>
#include <libpldm/pldm.h>
#include <poll.h>

#include <cstddef>

struct pldm_transport_mctp_demux;
struct pldm_transport_af_mctp;

union TransportImpl
{
    struct pldm_transport_mctp_demux* mctp_demux;
    struct pldm_transport_af_mctp* af_mctp;
};

/* RAII for pldm_transport */
class PldmTransport
{
  public:
    PldmTransport();
    PldmTransport(const PldmTransport& other) = delete;
    PldmTransport(const PldmTransport&& other) = delete;
    PldmTransport& operator=(const PldmTransport& other) = delete;
    PldmTransport& operator=(const PldmTransport&& other) = delete;
    ~PldmTransport();

    /** @brief Provides a file descriptor that can be polled for readiness.
     *
     * Readiness generally indicates that a call to recvMsg() will immediately
     * yield a message.
     *
     * @return The relevant file descriptor.
     */
    int getEventSource() const;

    /** @brief Asynchronously send a PLDM message to the specified terminus
     *
     * The message may be either a request or a response.
     *
     * @param[in] tid - The terminus ID of the message destination
     * @param[in] tx - The encoded and framed message to send
     * @param[in] len - The length of the buffer pointed-to by tx
     *
     * @return PLDM_REQUESTER_SUCCESS on success, otherwise an appropriate
     *         PLDM_REQUESTER_* error code.
     */
    pldm_requester_rc_t sendMsg(pldm_tid_t tid, const void* tx, size_t len);

    /** @brief Asynchronously receive a PLDM message addressed to the local
     * terminus
     *
     * The message may be either a request or a response.
     *
     * @param[out] tid - The terminus ID of the message source
     * @param[out] rx - A pointer to the received, encoded message
     * @param[out] len - The length of the buffer pointed-to by rx
     *
     * @return PLDM_REQUESTER_SUCCESS on success, otherwise an appropriate
     *         PLDM_REQUESTER_* error code.
     */
    pldm_requester_rc_t recvMsg(pldm_tid_t& tid, void*& rx, size_t& len);

    /** @brief Synchronously exchange a request and response with the specified
     * terminus.
     *
     * sendRecvMsg() is a wrapper for the non-compliant
     * pldm_transport_send_recv_msg() API from libpldm. It is a crutch that may
     * be used for to fulfil a PLDM request until libpldm implements a correct
     * requester flow in accordance with the PLDM base specification (DSP0240).
     *
     * The implementation blocks after the request is sent until a response is
     * received, or the upper time-bound on a PLDM exchange is reached. Control
     * is only handed back to the caller once one of these two outcomes is
     * achieved.
     *
     * @param[in] tid - The terminus ID of the endpoint with which the exchange
     *                  will occur
     * @param[in] tx - The encoded and framed message to send
     * @param[in] txLen - The length of the buffer pointed-to by tx
     * @param[out] rx - A pointer to the received, encoded message
     * @param[out] rxLen - The length of the buffer pointed-to by rx
     *
     * @return PLDM_REQUESTER_SUCCESS on success, otherwise an appropriate
     *         PLDM_REQUESTER_* error code.
     */
    pldm_requester_rc_t sendRecvMsg(pldm_tid_t tid, const void* tx,
                                    size_t txLen, void*& rx, size_t& rxLen);

  private:
    /** @brief A pollfd object for holding a file descriptor from the libpldm
     *         transport implementation
     */
    pollfd pfd;

    /** @brief A union holding an appropriately-typed pointer to the selected
     *         libpldm transport implementation
     */
    TransportImpl impl;

    /** @brief The abstract libpldm transport object for sending and receiving
     *         PLDM messages.
     */
    struct pldm_transport* transport;
};
