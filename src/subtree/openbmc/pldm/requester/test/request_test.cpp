#include "libpldm/base.h"

#include "mock_request.hpp"

#include <sdbusplus/timer.hpp>
#include <sdeventplus/event.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace pldm::requester;
using namespace std::chrono;
using ::testing::AtLeast;
using ::testing::Between;
using ::testing::Exactly;
using ::testing::Return;

class RequestIntfTest : public testing::Test
{
  protected:
    RequestIntfTest() : event(sdeventplus::Event::get_default())
    {}

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

    int fd = 0;
    mctp_eid_t eid = 0;
    sdeventplus::Event event;
    std::vector<uint8_t> requestMsg;
};

TEST_F(RequestIntfTest, 0Retries100msTimeout)
{
    MockRequest request(fd, eid, event, std::move(requestMsg), 0,
                        milliseconds(100), false);
    EXPECT_CALL(request, send())
        .Times(Exactly(1))
        .WillOnce(Return(PLDM_SUCCESS));
    auto rc = request.start();
    EXPECT_EQ(rc, PLDM_SUCCESS);
}

TEST_F(RequestIntfTest, 2Retries100msTimeout)
{
    MockRequest request(fd, eid, event, std::move(requestMsg), 2,
                        milliseconds(100), false);
    // send() is called a total of 3 times, the original plus two retries
    EXPECT_CALL(request, send()).Times(3).WillRepeatedly(Return(PLDM_SUCCESS));
    auto rc = request.start();
    EXPECT_EQ(rc, PLDM_SUCCESS);
    waitEventExpiry(milliseconds(500));
}

TEST_F(RequestIntfTest, 9Retries100msTimeoutRequestStoppedAfter1sec)
{
    MockRequest request(fd, eid, event, std::move(requestMsg), 9,
                        milliseconds(100), false);
    // send() will be called a total of 10 times, the original plus 9 retries.
    // In a ideal scenario send() would have been called 10 times in 1 sec (when
    // the timer is stopped) with a timeout of 100ms. Because there are delays
    // in dispatch, the range is kept between 5 and 10. This recreates the
    // situation where the Instance ID expires before the all the retries have
    // been completed and the timer is stopped.
    EXPECT_CALL(request, send())
        .Times(Between(5, 10))
        .WillRepeatedly(Return(PLDM_SUCCESS));
    auto rc = request.start();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    auto requestStopCallback = [&](void) { request.stop(); };
    phosphor::Timer timer(event.get(), requestStopCallback);
    timer.start(duration_cast<microseconds>(seconds(1)));

    waitEventExpiry(milliseconds(500));
}

TEST_F(RequestIntfTest, 2Retries100msTimeoutsendReturnsError)
{
    MockRequest request(fd, eid, event, std::move(requestMsg), 2,
                        milliseconds(100), false);
    EXPECT_CALL(request, send()).Times(Exactly(1)).WillOnce(Return(PLDM_ERROR));
    auto rc = request.start();
    EXPECT_EQ(rc, PLDM_ERROR);
}
