#pragma once

#include "requester/request.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace pldm
{

namespace requester
{

using namespace std::chrono;

class MockRequest : public RequestRetryTimer
{
  public:
    MockRequest(int /*fd*/, mctp_eid_t /*eid*/, sdeventplus::Event& event,
                pldm::Request&& /*requestMsg*/, uint8_t numRetries,
                milliseconds responseTimeOut) :
        RequestRetryTimer(event, numRetries, responseTimeOut)
    {}

    MOCK_METHOD(int, send, (), (const, override));
};

} // namespace requester

} // namespace pldm