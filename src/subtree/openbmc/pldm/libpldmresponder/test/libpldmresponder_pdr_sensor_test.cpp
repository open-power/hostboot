#include "libpldm/platform.h"

#include "common/test/mocked_utils.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "libpldmresponder/platform.hpp"

#include <sdbusplus/test/sdbus_mock.hpp>
#include <sdeventplus/event.hpp>

#include <gtest/gtest.h>

using namespace pldm::responder;
using namespace pldm::responder::platform;
using namespace pldm::responder::pdr;
using namespace pldm::responder::pdr_utils;

using ::testing::_;
using ::testing::Return;
using ::testing::StrEq;

TEST(GeneratePDRByStateSensor, testGoodJson)
{
    std::array<uint8_t, sizeof(pldm_msg_hdr) + PLDM_GET_PDR_REQ_BYTES>
        requestPayload{};
    auto req = reinterpret_cast<pldm_msg*>(requestPayload.data());
    size_t requestPayloadLength = requestPayload.size() - sizeof(pldm_msg_hdr);

    MockdBusHandler mockedUtils;
    EXPECT_CALL(mockedUtils, getService(StrEq("/foo/bar"), _))
        .Times(1)
        .WillRepeatedly(Return("foo.bar"));

    auto inPDRRepo = pldm_pdr_init();
    auto outPDRRepo = pldm_pdr_init();
    Repo outRepo(outPDRRepo);
    auto event = sdeventplus::Event::get_default();
    Handler handler(&mockedUtils, "./pdr_jsons/state_sensor/good", inPDRRepo,
                    nullptr, nullptr, nullptr, nullptr, event);
    handler.getPDR(req, requestPayloadLength);
    Repo inRepo(inPDRRepo);
    getRepoByType(inRepo, outRepo, PLDM_STATE_SENSOR_PDR);

    // 1 entries
    ASSERT_EQ(outRepo.getRecordCount(), 1);

    // Check first PDR
    pdr_utils::PdrEntry e;
    auto record = pdr::getRecordByHandle(outRepo, 2, e);
    ASSERT_NE(record, nullptr);

    pldm_state_sensor_pdr* pdr =
        reinterpret_cast<pldm_state_sensor_pdr*>(e.data);
    EXPECT_EQ(pdr->hdr.record_handle, 2);
    EXPECT_EQ(pdr->hdr.version, 1);
    EXPECT_EQ(pdr->hdr.type, PLDM_STATE_SENSOR_PDR);
    EXPECT_EQ(pdr->hdr.record_change_num, 0);
    EXPECT_EQ(pdr->hdr.length, 17);

    EXPECT_EQ(pdr->sensor_id, 1);

    const auto& [dbusMappings, dbusValMaps] =
        handler.getDbusObjMaps(pdr->sensor_id, TypeId::PLDM_SENSOR_ID);
    ASSERT_EQ(dbusMappings[0].objectPath, "/foo/bar");
    ASSERT_EQ(dbusMappings[0].interface, "xyz.openbmc_project.Foo.Bar");
    ASSERT_EQ(dbusMappings[0].propertyName, "propertyName");
    ASSERT_EQ(dbusMappings[0].propertyType, "string");

    pldm_pdr_destroy(inPDRRepo);
    pldm_pdr_destroy(outPDRRepo);
}

TEST(GeneratePDR, testMalformedJson)
{
    std::array<uint8_t, sizeof(pldm_msg_hdr) + PLDM_GET_PDR_REQ_BYTES>
        requestPayload{};
    auto req = reinterpret_cast<pldm_msg*>(requestPayload.data());
    size_t requestPayloadLength = requestPayload.size() - sizeof(pldm_msg_hdr);

    MockdBusHandler mockedUtils;
    EXPECT_CALL(mockedUtils, getService(StrEq("/foo/bar"), _))
        .Times(1)
        .WillRepeatedly(Return("foo.bar"));

    auto inPDRRepo = pldm_pdr_init();
    auto outPDRRepo = pldm_pdr_init();
    Repo outRepo(outPDRRepo);
    auto event = sdeventplus::Event::get_default();
    Handler handler(&mockedUtils, "./pdr_jsons/state_sensor/good", inPDRRepo,
                    nullptr, nullptr, nullptr, nullptr, event);
    handler.getPDR(req, requestPayloadLength);
    Repo inRepo(inPDRRepo);
    getRepoByType(inRepo, outRepo, PLDM_STATE_SENSOR_PDR);

    ASSERT_EQ(outRepo.getRecordCount(), 1);
    ASSERT_THROW(pdr_utils::readJson("./pdr_jsons/state_sensor/malformed"),
                 std::exception);

    pldm_pdr_destroy(inPDRRepo);
    pldm_pdr_destroy(outPDRRepo);
}
