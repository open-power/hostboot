#pragma once

#include "common/transport.hpp"
#include "requester/request.hpp"

#include <libpldm/transport.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace pldm
{

namespace requester
{

class MockRequest : public RequestRetryTimer
{
  public:
    MockRequest(PldmTransport* /*pldmTransport*/, mctp_eid_t /*eid*/,
                sdeventplus::Event& event, pldm::Request&& /*requestMsg*/,
                uint8_t numRetries, std::chrono::milliseconds responseTimeOut,
                bool /*verbose*/) :
        RequestRetryTimer(event, numRetries, responseTimeOut)
    {}

    MOCK_METHOD(int, send, (), (const, override));
};

} // namespace requester

} // namespace pldm
