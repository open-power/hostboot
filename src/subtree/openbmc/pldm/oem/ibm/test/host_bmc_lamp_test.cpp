#include "oem/ibm/host-bmc/host_lamp_test.hpp"
#include "pldmd/dbus_impl_requester.hpp"
#include "test/test_instance_id.hpp"

#include <cstring>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace pldm::led;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;

class MockLampTest : public HostLampTest
{
  public:
    MockLampTest(sdbusplus::bus_t& bus, const std::string& objPath,
                 uint8_t mctp_eid, pldm::InstanceIdDb& instanceIdDb,
                 pldm_pdr* repo,
                 pldm::requester::Handler<pldm::requester::Request>* handler) :
        HostLampTest(bus, objPath, mctp_eid, instanceIdDb, repo, handler)
    {}

    MOCK_METHOD(uint16_t, getEffecterID, (), (override));
    MOCK_METHOD(uint8_t, setHostStateEffecter, (uint16_t effecterId),
                (override));
};

TEST(TestLamp, Asserted)
{
    sdbusplus::bus_t bus = sdbusplus::bus::new_default();
    TestInstanceIdDb instanceIdDb;

    MockLampTest lampTest(bus, "/xyz/openbmc_project/led/groups/host_lamp_test",
                          0, instanceIdDb, nullptr, nullptr);

    lampTest.asserted(false);
    EXPECT_EQ(lampTest.asserted(), false);

    EXPECT_CALL(lampTest, getEffecterID())
        .Times(2)
        .WillOnce(Return(0))
        .WillOnce(Return(1));
    EXPECT_CALL(lampTest, setHostStateEffecter(1)).Times(1).WillOnce(Return(0));

    ASSERT_THROW(lampTest.asserted(true), sdbusplus::exception::SdBusError);

    lampTest.asserted(true);
    EXPECT_EQ(lampTest.asserted(), true);
}
