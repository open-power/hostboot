#include "common/types.hpp"
#include "common/utils.hpp"
#include "mock_request.hpp"
#include "pldmd/dbus_impl_requester.hpp"
#include "requester/handler.hpp"
#include "test/test_instance_id.hpp"

#include <libpldm/base.h>

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
    HandlerTest() :
        event(sdeventplus::Event::get_default()), instanceIdDb(),
        dbusImplReq(pldm::utils::DBusHandler::getBus(),
                    "/xyz/openbmc_project/pldm", instanceIdDb)
    {}

    int fd = 0;
    mctp_eid_t eid = 0;
    sdeventplus::Event event;
    TestInstanceIdDb instanceIdDb;
    pldm::dbus_api::Requester dbusImplReq;

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
        fd, event, dbusImplReq, false, 90000, seconds(1), 2, milliseconds(100));
    pldm::Request request{};
    auto instanceId = dbusImplReq.getInstanceId(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::move(std::bind_front(&HandlerTest::pldmResponseCallBack, this)));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Response response(sizeof(pldm_msg_hdr) + sizeof(uint8_t));
    auto responsePtr = reinterpret_cast<const pldm_msg*>(response.data());
    reqHandler.handleResponse(eid, instanceId, 0, 0, responsePtr,
                              sizeof(response));

    EXPECT_EQ(validResponse, true);
}

TEST_F(HandlerTest, singleRequestInstanceIdTimerExpired)
{
    Handler<NiceMock<MockRequest>> reqHandler(
        fd, event, dbusImplReq, false, 90000, seconds(1), 2, milliseconds(100));
    pldm::Request request{};
    auto instanceId = dbusImplReq.getInstanceId(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::move(std::bind_front(&HandlerTest::pldmResponseCallBack, this)));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // Waiting for 500ms so that the instance ID expiry callback is invoked
    waitEventExpiry(milliseconds(500));

    EXPECT_EQ(nullResponse, true);
}

TEST_F(HandlerTest, multipleRequestResponseScenario)
{
    Handler<NiceMock<MockRequest>> reqHandler(
        fd, event, dbusImplReq, false, 90000, seconds(2), 2, milliseconds(100));
    pldm::Request request{};
    auto instanceId = dbusImplReq.getInstanceId(eid);
    EXPECT_EQ(instanceId, 0);
    auto rc = reqHandler.registerRequest(
        eid, instanceId, 0, 0, std::move(request),
        std::move(std::bind_front(&HandlerTest::pldmResponseCallBack, this)));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Request requestNxt{};
    auto instanceIdNxt = dbusImplReq.getInstanceId(eid);
    EXPECT_EQ(instanceIdNxt, 1);
    rc = reqHandler.registerRequest(
        eid, instanceIdNxt, 0, 0, std::move(requestNxt),
        std::move(std::bind_front(&HandlerTest::pldmResponseCallBack, this)));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::Response response(sizeof(pldm_msg_hdr) + sizeof(uint8_t));
    auto responsePtr = reinterpret_cast<const pldm_msg*>(response.data());
    reqHandler.handleResponse(eid, instanceIdNxt, 0, 0, responsePtr,
                              sizeof(response));
    EXPECT_EQ(validResponse, true);
    EXPECT_EQ(callbackCount, 1);
    validResponse = false;

    // Waiting for 500ms and handle the response for the first request, to
    // simulate a delayed response for the first request
    waitEventExpiry(milliseconds(500));

    reqHandler.handleResponse(eid, instanceId, 0, 0, responsePtr,
                              sizeof(response));

    EXPECT_EQ(validResponse, true);
    EXPECT_EQ(callbackCount, 2);
}
