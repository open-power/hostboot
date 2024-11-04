#pragma once

#include "platform-mc/event_manager.hpp"

#include <gmock/gmock.h>

namespace pldm
{
namespace platform_mc
{

class MockEventManager : public EventManager
{
  public:
    MockEventManager(TerminusManager& terminusManager, TerminiMapper& termini) :
        EventManager(terminusManager, termini) {};

    MOCK_METHOD(int, processCperEvent,
                (pldm_tid_t tid, uint16_t eventId, const uint8_t* eventData,
                 size_t eventDataSize),
                (override));
};

} // namespace platform_mc
} // namespace pldm
