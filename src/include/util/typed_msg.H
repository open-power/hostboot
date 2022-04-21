/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/typed_msg.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/* @brief Implements a strongly typed overlay for Hostboot's weakly typed
 *        message passing API.
 */

#ifndef TYPED_MSG_H
#define TYPED_MSG_H

#include <sys/msg.h>
#include <memory>

namespace Util
{

/* @brief A unidirectional strongly-typed message queue. Management of the
 *        underlying message queue object is left to the owner of this object.
 */
template<typename T>
class unipipe
{
public:
    unipipe(const unipipe&) = default;

    unipipe() : iv_msgq(msg_q_create()) { }

    unipipe(msg_q_t i_q) : iv_msgq(i_q) { }

    /* @brief Returns the underlying queue. */
    msg_q_t queue() const
    {
        return iv_msgq;
    }

    /* @brief Set the underlying queue. */
    void queue(const msg_q_t i_q)
    {
        iv_msgq = i_q;
    }

    /* @brief Send a message. Transfers ownership to the recipient of the
     *        message.
     *
     * @param[in] i_msg  The data to send.
     */
    void send(std::unique_ptr<T> i_msg) const
    {
        msg_t* msg = msg_allocate();
        msg->extra_data = i_msg.get();

        const int rc = msg_send(iv_msgq, msg);

        assert(rc == 0, "unipipe::send: msg_send returned %d", rc);

        if (rc)
        {
            msg_free(msg);
            msg = nullptr;
        }
        else
        {
            i_msg.release();
        }
    }

    /* @brief Receive a message. Transfers ownership of the message to the
     *        caller.
     */
    std::unique_ptr<T> wait() const
    {
        msg_t* const msg = msg_wait(iv_msgq);

        assert(msg, "unipipe::wait: msg_wait returned null");

        std::unique_ptr<T> storage(reinterpret_cast<T*>(msg->extra_data));

        msg->extra_data = nullptr;
        msg_free(msg);

        return storage;
    }

    /* @brief Convert a msg_t instance to the value type of this
     *        queue. Transfers ownership of the data to the caller.
     */
    std::unique_ptr<T> convert_response(msg_t*& msg) const
    {
        std::unique_ptr<T> storage(reinterpret_cast<T*>(msg->extra_data));

        msg->extra_data = nullptr;
        msg_free(msg);
        msg = nullptr;

        return storage;
    }

private:
    msg_q_t iv_msgq;
};

/* @brief This structure is used as a deallocator with the unique_ptr class. If
 *        this deallocator is invoked, it triggers an assertion failure. This is
 *        used to ensure that if someone receives a message that expects a
 *        response, then they must respond to it.
 */
template<typename T>
struct must_respond
{
    void operator()(void*) const
    {
        assert(false, "A message was received but the receiver never responded");
    }
};

/* @brief A bidirectional strongly typed message queue. Management of the
 *        underlying message queue object is left to the owner of this object.
 */
template<typename Send, typename Recv>
class bipipe
{
public:
    bipipe() : iv_msgq(msg_q_create()) { }

    bipipe(const msg_q_t i_q) : iv_msgq(i_q) { }

    bipipe(const bipipe&) = default;

    /* @brief Retrieve the underlying queue. */
    msg_q_t queue() const
    {
        return iv_msgq;
    }

    /* @brief Set the underlying queue. */
    void queue(const msg_q_t i_q)
    {
        iv_msgq = i_q;
    }

    /* @brief Send a message and receive a response. Ownership of the sent
     *        message is transferred to the receiver. Ownership of the response is
     *        transferred to the caller.
     * @param[in] i_msg       The message to send.
     * @param[out] o_data0    data[0] member from the response message.
     * @param[out] o_data1    data[1] member from the response message.
     * @param[out] o_type     type member from the response message.
     * @return The response message value.
     */
    std::unique_ptr<Recv> sendrecv(std::unique_ptr<Send> i_msg,
                                   uint64_t& o_data0,
                                   uint64_t& o_data1,
                                   uint64_t& o_type) const
    {
        msg_t* msg = msg_allocate();
        msg->extra_data = i_msg.get();

        const int rc = msg_sendrecv(iv_msgq, msg);

        assert(rc == 0, "bipipe::sendrecv: msg_sendrecv() returned %d", rc);

        std::unique_ptr<Recv> result(reinterpret_cast<Recv*>(msg->extra_data));

        o_data0 = msg->data[0];
        o_data0 = msg->data[1];
        o_type = msg->type;

        msg->extra_data = nullptr;
        msg_free(msg);
        msg = nullptr;

        i_msg.release(); // ownership transferred to message recipient

        return result;
    }

    /* @brief Send a message and receive a response. See the documentation for
     *        sendrecv above. */
    std::unique_ptr<Recv> sendrecv(std::unique_ptr<Send> i_msg,
                                   uint64_t& o_data0,
                                   uint64_t& o_data1) const
    {
        uint64_t type = 0;
        return sendrecv(move(i_msg), o_data0, o_data1, type);
    }

    /* @brief Send a message and receive a response. See the documentation for
     *        sendrecv above. */
    std::unique_ptr<Recv> sendrecv(std::unique_ptr<Send> i_msg,
                                   uint64_t& o_data0) const
    {
        uint64_t type = 0, data1 = 0;
        return sendrecv(move(i_msg), o_data0, data1, type);
    }

    /* @brief Send a message and receive a response. See the documentation for
     *        sendrecv above. */
    std::unique_ptr<Recv> sendrecv(std::unique_ptr<Send> i_msg) const
    {
        uint64_t type = 0, data1 = 0, data0;
        return sendrecv(move(i_msg), data0, data1, type);
    }

    /* @brief Receive a message. The message received MUST be responded to,
     *        exactly once, otherwise an assertion failure will occur.
     *
     * @param[out] o_result  The message that was received.
     * @param[out] o_data0   data[0] member from the received message.
     * @param[out] o_data1   data[1] member from the received message.
     * @param[out] o_type    type member from the received message.
     *
     * @return A handle used to respond to this message. If the handle is not
     * used to respond to the received message exactly once, an assertion
     * failure will be triggered.
     */
    std::unique_ptr<msg_t, must_respond<Recv>> wait(std::unique_ptr<Send>& o_result,
                                                    uint64_t& o_data0,
                                                    uint64_t& o_data1,
                                                    uint64_t& o_type) const
    {
        msg_t* const msg = msg_wait(iv_msgq);

        assert(msg, "bipipe::wait: msg_wait() returned null");

        o_result.reset(reinterpret_cast<Send*>(msg->extra_data));

        msg->extra_data = nullptr;

        o_data0 = msg->data[0];
        o_data1 = msg->data[1];
        o_type = msg->type;

        return std::unique_ptr<msg_t, must_respond<Recv>> { msg };
    }

    /* @brief Receive a message. See the documentation for wait above. */
    std::unique_ptr<msg_t, must_respond<Recv>> wait(std::unique_ptr<Send>& o_result,
                                                    uint64_t& o_data0,
                                                    uint64_t& o_data1) const
    {
        uint64_t type = 0;
        return wait(o_result, o_data0, o_data1, type);
    }

    /* @brief Receive a message. See the documentation for wait above. */
    std::unique_ptr<msg_t, must_respond<Recv>> wait(std::unique_ptr<Send>& o_result,
                                                    uint64_t& o_data0) const
    {
        uint64_t type = 0, data1 = 0;
        return wait(o_result, o_data0, data1, type);
    }

    /* @brief Receive a message. See the documentation for wait above. */
    std::unique_ptr<msg_t, must_respond<Recv>> wait(std::unique_ptr<Send>& o_result) const
    {
        uint64_t type = 0, data0 = 0, data1 = 0;
        return wait(o_result, data0, data1, type);
    }

    /* @brief Respond to a message. This function MUST be used to respond to
     *        messages received by wait() exactly once; otherwise an assertion
     *        failure will occur.
     *
     * @param[in] i_msg       The message to respond to.
     * @param[in] i_response  The response to send.
     * @param[in] i_data0     The .data[0] member of the message to send.
     * @param[in] i_data1     The .data[1] member of the message to send.
     * @param[in] i_type      The .type member of the message to send.
     */
    void respond(std::unique_ptr<msg_t, must_respond<Recv>> i_msg,
                 std::unique_ptr<Recv> i_response,
                 const uint64_t i_data0 = 0,
                 const uint64_t i_data1 = 0,
                 const uint64_t i_type = 0) const
    {
        assert(i_msg.get(), "Message was responded to twice");

        i_msg->type = i_type;
        i_msg->data[0] = i_data0;
        i_msg->data[1] = i_data1;
        i_msg->extra_data = i_response.get();

        msg_respond(iv_msgq, i_msg.get());

        i_msg.release();
        i_response.release();
    }

private:
    msg_q_t iv_msgq = nullptr;
};

}

#endif
