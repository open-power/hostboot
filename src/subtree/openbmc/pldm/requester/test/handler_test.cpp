#include "common/instance_id.hpp"
#include "common/types.hpp"
#include "common/utils.hpp"
#include "mock_request.hpp"
#include "requester/handler.hpp"
#include "test/test_instance_id.hpp"

#include <libpldm/base.h>
#include <libpldm/transport.h>

#include <sdbusplus/async.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace pldm::requester;
using namespace std::chrono;

using ::testing::AtLeast;
using ::testing::Between;
using ::testing::Exactly;
using ::testing::NiceMock;
using ::testing::Return;

class HandlerTest : public testing::Test
{
  protected:
    HandlerTest() : event(sdeventplus::Event::get_default()), instanceIdDb() {}

    int fd = 0;
    mctp_eid_t eid = 0;
    PldmTransport* pldmTransport = nullptr;
    sdeventplus::Event event;
    TestInstanceIdDb instanceIdDb;

    /** @brief This function runs the sd_event_run in a loop till all the events
     *         in the testcase are dispatched and exits when there are no events
     *         for the timeout time.
     *
     *  @param[in] timeout - maximum time to wait for an event
     */
    void waitEventExpiry(milliseconds timeout)
    {
        while (1)
        {
            auto sleepTime = duration_cast<microseconds>(timeout);
            // Returns 0 on timeout
            if (!sd_event_run(event.get(), sleepTime.count()))
            {
                break;
            }
        }
    }

  public:
    bool nullResponse = false;
    bool validResponse = false;
    int callbackCount = 0;
    bool response2 = false;

    void pldmResponseCallBack(mctp_eid_t /*eid*/, const pldm_msg* response,
                              size_t respMsgLen)
    {
        if (response == nullptr && respMsgLen == 0)
        {
            nullResponse = true;
        }
        else
        {
            validResponse = true;
        }
        callbackCount++;
    }
};

TEST_F(HandlerTest, singleRequestResponseScenario)
{
    Handler<NiceMock<MockRequest>> reqHandler(
        pldmTransport, event, instanceIdDb, false, seconds(1), 2,
        milliseconds(100));
    pldm::Request request{};
    auto instanceId = instanceIdDb.next(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::bind_front(&HandlerTest::pldmResponseCallBack, this));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Response response(sizeof(pldm_msg_hdr) + sizeof(uint8_t));
    auto responsePtr = reinterpret_cast<const pldm_msg*>(response.data());
    reqHandler.handleResponse(eid, instanceId, 0, 0, responsePtr,
                              response.size());

    EXPECT_EQ(validResponse, true);
}

TEST_F(HandlerTest, singleRequestInstanceIdTimerExpired)
{
    Handler<NiceMock<MockRequest>> reqHandler(
        pldmTransport, event, instanceIdDb, false, seconds(1), 2,
        milliseconds(100));
    pldm::Request request{};
    auto instanceId = instanceIdDb.next(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::bind_front(&HandlerTest::pldmResponseCallBack, this));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // Waiting for 500ms so that the instance ID expiry callback is invoked
    waitEventExpiry(milliseconds(500));

    EXPECT_EQ(nullResponse, true);
}

TEST_F(HandlerTest, multipleRequestResponseScenario)
{
    Handler<NiceMock<MockRequest>> reqHandler(
        pldmTransport, event, instanceIdDb, false, seconds(2), 2,
        milliseconds(100));
    pldm::Request request{};
    auto instanceId = instanceIdDb.next(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::bind_front(&HandlerTest::pldmResponseCallBack, this));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Request requestNxt{};
    auto instanceIdNxt = instanceIdDb.next(eid);
    EXPECT_EQ(instanceIdNxt, 1);
    rc = reqHandler.registerRequest(
        eid, instanceIdNxt, 0, 0, std::move(requestNxt),
        std::bind_front(&HandlerTest::pldmResponseCallBack, this));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Response response(sizeof(pldm_msg_hdr) + sizeof(uint8_t));
    auto responsePtr = reinterpret_cast<const pldm_msg*>(response.data());
    reqHandler.handleResponse(eid, instanceId, 0, 0, responsePtr,
                              response.size());
    EXPECT_EQ(validResponse, true);
    EXPECT_EQ(callbackCount, 1);
    validResponse = false;

    // Waiting for 500ms and handle the response for the first request, to
    // simulate a delayed response for the first request
    waitEventExpiry(milliseconds(500));

    reqHandler.handleResponse(eid, instanceIdNxt, 0, 0, responsePtr,
                              response.size());

    EXPECT_EQ(validResponse, true);
    EXPECT_EQ(callbackCount, 2);
}

TEST_F(HandlerTest, singleRequestResponseScenarioUsingCoroutine)
{
    exec::async_scope scope;
    Handler<NiceMock<MockRequest>> reqHandler(
        pldmTransport, event, instanceIdDb, false, seconds(1), 2,
        milliseconds(100));

    auto instanceId = instanceIdDb.next(eid);
    EXPECT_EQ(instanceId, 0);

    scope.spawn(
        stdexec::just() | stdexec::let_value([&] -> exec::task<void> {
            pldm::Request request(sizeof(pldm_msg_hdr) + sizeof(uint8_t), 0);
            const pldm_msg* responseMsg;
            size_t responseLen;
            int rc = PLDM_SUCCESS;

            auto requestPtr = reinterpret_cast<pldm_msg*>(request.data());
            requestPtr->hdr.instance_id = instanceId;

            try
            {
                std::tie(rc, responseMsg, responseLen) =
                    co_await reqHandler.sendRecvMsg(eid, std::move(request));
            }
            catch (...)
            {
                std::rethrow_exception(std::current_exception());
            }

            EXPECT_NE(responseLen, 0);

            this->pldmResponseCallBack(eid, responseMsg, responseLen);

            EXPECT_EQ(validResponse, true);
        }),
        exec::default_task_context<void>(exec::inline_scheduler{}));

    pldm::Response mockResponse(sizeof(pldm_msg_hdr) + sizeof(uint8_t), 0);
    auto mockResponsePtr =
        reinterpret_cast<const pldm_msg*>(mockResponse.data());
    reqHandler.handleResponse(eid, instanceId, 0, 0, mockResponsePtr,
                              mockResponse.size() - sizeof(pldm_msg_hdr));

    stdexec::sync_wait(scope.on_empty());
}

TEST_F(HandlerTest, singleRequestCancellationScenarioUsingCoroutine)
{
    exec::async_scope scope;
    Handler<NiceMock<MockRequest>> reqHandler(
        pldmTransport, event, instanceIdDb, false, seconds(1), 2,
        milliseconds(100));
    auto instanceId = instanceIdDb.next(eid);
    EXPECT_EQ(instanceId, 0);

    bool stopped = false;

    scope.spawn(
        stdexec::just() | stdexec::let_value([&] -> exec::task<void> {
            pldm::Request request(sizeof(pldm_msg_hdr) + sizeof(uint8_t), 0);
            pldm::Response response;

            auto requestPtr = reinterpret_cast<pldm_msg*>(request.data());
            requestPtr->hdr.instance_id = instanceId;

            co_await reqHandler.sendRecvMsg(eid, std::move(request));

            EXPECT_TRUE(false); // unreachable
        }) | stdexec::upon_stopped([&] { stopped = true; }),
        exec::default_task_context<void>(exec::inline_scheduler{}));

    scope.request_stop();

    EXPECT_TRUE(stopped);

    stdexec::sync_wait(scope.on_empty());
}

TEST_F(HandlerTest, asyncRequestResponseByCoroutine)
{
    struct _
    {
        static exec::task<uint8_t>
            getTIDTask(Handler<MockRequest>& handler, mctp_eid_t eid,
                       uint8_t instanceId, uint8_t& tid)
        {
            pldm::Request request(sizeof(pldm_msg_hdr), 0);
            auto requestMsg = reinterpret_cast<pldm_msg*>(request.data());
            const pldm_msg* responseMsg;
            size_t responseLen;

            auto rc = encode_get_tid_req(instanceId, requestMsg);
            EXPECT_EQ(rc, PLDM_SUCCESS);

            std::tie(rc, responseMsg, responseLen) =
                co_await handler.sendRecvMsg(eid, std::move(request));
            EXPECT_NE(responseLen, 0);

            uint8_t cc = 0;
            rc = decode_get_tid_resp(responseMsg, responseLen, &cc, &tid);
            EXPECT_EQ(rc, PLDM_SUCCESS);

            co_return cc;
        }
    };

    exec::async_scope scope;
    Handler<MockRequest> reqHandler(pldmTransport, event, instanceIdDb, false,
                                    seconds(1), 2, milliseconds(100));
    auto instanceId = instanceIdDb.next(eid);

    uint8_t expectedTid = 1;

    // Execute a coroutine to send getTID command. The coroutine is suspended
    // until reqHandler.handleResponse() is received.
    scope.spawn(stdexec::just() | stdexec::let_value([&] -> exec::task<void> {
                    uint8_t respTid = 0;

                    co_await _::getTIDTask(reqHandler, eid, instanceId,
                                           respTid);

                    EXPECT_EQ(expectedTid, respTid);
                }),
                exec::default_task_context<void>(exec::inline_scheduler{}));

    pldm::Response mockResponse(sizeof(pldm_msg_hdr) + PLDM_GET_TID_RESP_BYTES,
                                0);
    auto mockResponseMsg = reinterpret_cast<pldm_msg*>(mockResponse.data());

    // Compose response message of getTID command
    encode_get_tid_resp(instanceId, PLDM_SUCCESS, expectedTid, mockResponseMsg);

    // Send response back to resume getTID coroutine to update respTid by
    // calling  reqHandler.handleResponse() manually
    reqHandler.handleResponse(eid, instanceId, PLDM_BASE, PLDM_GET_TID,
                              mockResponseMsg,
                              mockResponse.size() - sizeof(pldm_msg_hdr));

    stdexec::sync_wait(scope.on_empty());
}
