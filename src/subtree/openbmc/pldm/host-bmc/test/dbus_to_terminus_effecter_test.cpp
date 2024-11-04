#include "common/test/mocked_utils.hpp"
#include "common/utils.hpp"
#include "host-bmc/dbus_to_terminus_effecters.hpp"

#include <nlohmann/json.hpp>

#include <gtest/gtest.h>

using namespace pldm::host_effecters;
using namespace pldm::utils;

class MockHostEffecterParser : public HostEffecterParser
{
  public:
    MockHostEffecterParser(int fd, const pldm_pdr* repo,
                           DBusHandler* const dbusHandler,
                           const std::string& jsonPath) :
        HostEffecterParser(nullptr, fd, repo, dbusHandler, jsonPath, nullptr)
    {}

    MOCK_METHOD(int, setHostStateEffecter,
                (size_t, std::vector<set_effecter_state_field>&, uint16_t),
                (override));

    MOCK_METHOD(void, createHostEffecterMatch,
                (const std::string&, const std::string&, size_t, size_t,
                 uint16_t),
                (override));

    const std::vector<EffecterInfo>& gethostEffecterInfo()
    {
        return hostEffecterInfo;
    }
};

TEST(HostEffecterParser, parseEffecterJsonGoodPath)
{
    MockdBusHandler dbusHandler;
    int sockfd{};
    MockHostEffecterParser hostEffecterParserGood(sockfd, nullptr, &dbusHandler,
                                                  "./host_effecter_jsons/good");
    auto hostEffecterInfo = hostEffecterParserGood.gethostEffecterInfo();
    ASSERT_EQ(hostEffecterInfo.size(), 2);
    ASSERT_EQ(hostEffecterInfo[0].effecterPdrType, PLDM_STATE_EFFECTER_PDR);
    ASSERT_EQ(hostEffecterInfo[0].entityInstance, 0);
    ASSERT_EQ(hostEffecterInfo[0].entityType, 33);
    ASSERT_EQ(hostEffecterInfo[0].dbusInfo.size(), 1);
    ASSERT_EQ(hostEffecterInfo[0].checkHostState, true);
    DBusEffecterMapping dbusInfo{
        {"/xyz/openbmc_project/control/host0/boot",
         "xyz.openbmc_project.Control.Boot.Mode", "BootMode", "string"},
        {"xyz.openbmc_project.Control.Boot.Mode.Modes.Regular"},
        {196, {2}}};
    auto& temp = hostEffecterInfo[0].dbusInfo[0];
    ASSERT_EQ(temp.dbusMap.objectPath == dbusInfo.dbusMap.objectPath, true);
    ASSERT_EQ(temp.dbusMap.interface == dbusInfo.dbusMap.interface, true);
    ASSERT_EQ(temp.dbusMap.propertyName == dbusInfo.dbusMap.propertyName, true);
    ASSERT_EQ(temp.dbusMap.propertyType == dbusInfo.dbusMap.propertyType, true);

    /* Check Numeric Effecter in Good Json file */
    ASSERT_EQ(hostEffecterInfo[1].effecterPdrType, PLDM_NUMERIC_EFFECTER_PDR);
    ASSERT_EQ(hostEffecterInfo[1].entityType, 32903);
    ASSERT_EQ(hostEffecterInfo[1].entityInstance, 6);
    ASSERT_EQ(hostEffecterInfo[1].containerId, 4);
    ASSERT_EQ(hostEffecterInfo[1].dbusNumericEffecterInfo.size(), 1);
    ASSERT_EQ(hostEffecterInfo[1].checkHostState, false);
    DBusNumericEffecterMapping dbusInfoNumeric{
        {"/xyz/openbmc_project/effecters/power/PLimit",
         "xyz.openbmc_project.Effecter.Value", "Value", "double"},
        5,
        1,
        0,
        -3,
        100};
    auto& tempNumeric = hostEffecterInfo[1].dbusNumericEffecterInfo[0];
    ASSERT_EQ(tempNumeric.dbusMap.objectPath ==
                  dbusInfoNumeric.dbusMap.objectPath,
              true);
    ASSERT_EQ(tempNumeric.dbusMap.interface ==
                  dbusInfoNumeric.dbusMap.interface,
              true);
    ASSERT_EQ(tempNumeric.dbusMap.propertyName ==
                  dbusInfoNumeric.dbusMap.propertyName,
              true);
    ASSERT_EQ(tempNumeric.dbusMap.propertyType ==
                  dbusInfoNumeric.dbusMap.propertyType,
              true);
    ASSERT_EQ(tempNumeric.dataSize == dbusInfoNumeric.dataSize, true);
    ASSERT_EQ(tempNumeric.resolution == dbusInfoNumeric.resolution, true);
    ASSERT_EQ(tempNumeric.offset == dbusInfoNumeric.offset, true);
    ASSERT_EQ(tempNumeric.unitModifier == dbusInfoNumeric.unitModifier, true);
}

TEST(HostEffecterParser, parseEffecterJsonBadPath)
{
    MockdBusHandler dbusHandler;
    int sockfd{};
    MockHostEffecterParser hostEffecterParser(sockfd, nullptr, &dbusHandler,
                                              "./host_effecter_jsons/no_json");
    ASSERT_THROW(
        hostEffecterParser.parseEffecterJson("./host_effecter_jsons/no_json"),
        std::exception);
    ASSERT_THROW(
        hostEffecterParser.parseEffecterJson("./host_effecter_jsons/malformed"),
        std::exception);
}

TEST(HostEffecterParser, findNewStateValue)
{
    MockdBusHandler dbusHandler;
    int sockfd{};
    MockHostEffecterParser hostEffecterParser(sockfd, nullptr, &dbusHandler,
                                              "./host_effecter_jsons/good");

    PropertyValue val1{std::in_place_type<std::string>,
                       "xyz.openbmc_project.Control.Boot.Mode.Modes.Regular"};
    PropertyValue val2{std::in_place_type<std::string>,
                       "xyz.openbmc_project.Control.Boot.Mode.Modes.Setup"};
    auto newState = hostEffecterParser.findNewStateValue(0, 0, val1);
    ASSERT_EQ(newState, 2);

    ASSERT_THROW(hostEffecterParser.findNewStateValue(0, 0, val2),
                 std::exception);
}

TEST(HostEffecterParser, adjustValue)
{
    MockdBusHandler dbusHandler;
    int sockfd{};
    MockHostEffecterParser hostEffecterParser(sockfd, nullptr, &dbusHandler,
                                              "./host_effecter_jsons/good");

    auto realVal = hostEffecterParser.adjustValue(200, -50, 0.5, -2);
    ASSERT_EQ(realVal, 12500);
    realVal = hostEffecterParser.adjustValue(0, -50, 1, 0);
    ASSERT_EQ(realVal, 50);
    realVal = hostEffecterParser.adjustValue(0, 100, 1, -1);
    ASSERT_EQ(realVal, -1000);
    realVal = hostEffecterParser.adjustValue(2.34, 0, 1, -1);
    ASSERT_EQ(realVal, 23);
    realVal = hostEffecterParser.adjustValue(2.35, 0, 1, -1);
    ASSERT_EQ(realVal, 24);
}
