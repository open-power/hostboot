#include "libpldm/base.h"
#include "libpldm/bios.h"
#include "libpldm/fru.h"
#include "libpldm/platform.h"

#include "common/instance_id.hpp"
#include "common/types.hpp"
#include "mock_terminus_manager.hpp"
#include "platform-mc/terminus_manager.hpp"
#include "requester/handler.hpp"
#include "requester/mctp_endpoint_discovery.hpp"
#include "requester/request.hpp"
#include "test/test_instance_id.hpp"

#include <sdbusplus/timer.hpp>
#include <sdeventplus/event.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::AtLeast;
using ::testing::Between;
using ::testing::Exactly;
using ::testing::NiceMock;
using ::testing::Return;

class TerminusManagerTest : public testing::Test
{
  protected:
    TerminusManagerTest() :
        bus(pldm::utils::DBusHandler::getBus()),
        event(sdeventplus::Event::get_default()), instanceIdDb(),
        reqHandler(pldmTransport, event, instanceIdDb, false,
                   std::chrono::seconds(1), 2, std::chrono::milliseconds(100)),
        terminusManager(event, reqHandler, instanceIdDb, termini, nullptr,
                        pldm::BmcMctpEid),
        mockTerminusManager(event, reqHandler, instanceIdDb, termini, nullptr)
    {}

    PldmTransport* pldmTransport = nullptr;
    sdbusplus::bus_t& bus;
    sdeventplus::Event event;
    TestInstanceIdDb instanceIdDb;
    pldm::requester::Handler<pldm::requester::Request> reqHandler;
    pldm::platform_mc::TerminusManager terminusManager;
    pldm::platform_mc::MockTerminusManager mockTerminusManager;
    std::map<pldm_tid_t, std::shared_ptr<pldm::platform_mc::Terminus>> termini;
};

TEST_F(TerminusManagerTest, mapTidTest)
{
    pldm::MctpInfo mctpInfo1(8, "", "", 0);

    auto mappedTid1 = terminusManager.mapTid(mctpInfo1);
    EXPECT_NE(mappedTid1, std::nullopt);

    auto tid1 = terminusManager.toTid(mctpInfo1);
    EXPECT_NE(tid1, std::nullopt);

    auto mctpInfo2 = terminusManager.toMctpInfo(tid1.value());
    EXPECT_EQ(mctpInfo1, mctpInfo2.value());

    auto ret = terminusManager.unmapTid(tid1.value());
    EXPECT_EQ(ret, true);

    tid1 = terminusManager.toTid(mctpInfo1);
    EXPECT_EQ(tid1, std::nullopt);
}

TEST_F(TerminusManagerTest, negativeMapTidTest)
{
    // map null EID(0) to TID
    pldm::MctpInfo m0(0, "", "", 0);
    auto mappedTid = terminusManager.mapTid(m0);
    EXPECT_EQ(mappedTid, std::nullopt);

    // map broadcast EID(0xff) to TID
    pldm::MctpInfo m1(0xff, "", "", 0);
    mappedTid = terminusManager.mapTid(m1);
    EXPECT_EQ(mappedTid, std::nullopt);

    // map EID to tid which has been assigned
    pldm::MctpInfo m2(9, "", "", 1);
    pldm::MctpInfo m3(10, "", "", 1);
    auto mappedTid2 = terminusManager.mapTid(m2);
    auto mappedTid3 = terminusManager.storeTerminusInfo(m3, mappedTid2.value());
    EXPECT_NE(mappedTid2, std::nullopt);
    EXPECT_EQ(mappedTid3, std::nullopt);

    // map two mctpInfo with same EID but different network Id
    pldm::MctpInfo m4(12, "", "", 1);
    pldm::MctpInfo m5(12, "", "", 2);
    auto mappedTid4 = terminusManager.mapTid(m4);
    auto mappedTid5 = terminusManager.mapTid(m5);
    EXPECT_NE(mappedTid4.value(), mappedTid5.value());

    // map same mctpInfo twice
    pldm::MctpInfo m6(12, "", "", 3);
    auto mappedTid6 = terminusManager.mapTid(m6);
    auto mappedTid6_1 = terminusManager.mapTid(m6);
    EXPECT_EQ(mappedTid6.value(), mappedTid6_1.value());

    // look up an unmapped MctpInfo to TID
    pldm::MctpInfo m7(1, "", "", 0);
    auto mappedTid7 = terminusManager.toTid(m7);
    EXPECT_EQ(mappedTid7, std::nullopt);

    // look up reserved TID(0)
    auto mappedEid = terminusManager.toMctpInfo(0);
    EXPECT_EQ(mappedEid, std::nullopt);

    // look up reserved TID(0xff)
    mappedEid = terminusManager.toMctpInfo(0xff);
    EXPECT_EQ(mappedEid, std::nullopt);

    // look up an unmapped TID
    terminusManager.unmapTid(1);
    mappedEid = terminusManager.toMctpInfo(1);
    EXPECT_EQ(mappedEid, std::nullopt);

    // unmap reserved TID(0)
    auto ret = terminusManager.unmapTid(0);
    EXPECT_EQ(ret, false);

    // unmap reserved TID(0)
    ret = terminusManager.unmapTid(0xff);
    EXPECT_EQ(ret, false);
}

TEST_F(TerminusManagerTest, discoverMctpTerminusTest)
{
    const size_t getTidRespLen = PLDM_GET_TID_RESP_BYTES;
    const size_t setTidRespLen = PLDM_SET_TID_RESP_BYTES;
    const size_t getPldmTypesRespLen = PLDM_GET_TYPES_RESP_BYTES;

    // 0.discover a mctp list
    auto rc = mockTerminusManager.clearQueuedResponses();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp0{
        0x00, 0x02, 0x02, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp0.data()), sizeof(getTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    std::array<uint8_t, sizeof(pldm_msg_hdr) + setTidRespLen> setTidResp0{
        0x00, 0x02, 0x01, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp0.data()), sizeof(setTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmTypesRespLen>
        getPldmTypesResp0{0x00, 0x02, 0x04, 0x00, 0x01, 0x00,
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmTypesResp0.data()),
        sizeof(getPldmTypesResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::MctpInfos mctpInfos{};
    mctpInfos.emplace_back(pldm::MctpInfo(12, "", "", 1));
    mockTerminusManager.discoverMctpTerminus(mctpInfos);
    EXPECT_EQ(1, termini.size());

    // 1.discover the same mctp list again
    rc = mockTerminusManager.clearQueuedResponses();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp1{
        0x00, 0x02, 0x02, 0x00, 0x01};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp1.data()), sizeof(getTidResp1));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp0.data()), sizeof(setTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmTypesResp0.data()),
        sizeof(getPldmTypesResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    mockTerminusManager.discoverMctpTerminus(mctpInfos);
    EXPECT_EQ(1, termini.size());

    // 2.discover an empty mctp list
    rc = mockTerminusManager.clearQueuedResponses();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    mockTerminusManager.removeMctpTerminus(mctpInfos);
    EXPECT_EQ(0, termini.size());
}

TEST_F(TerminusManagerTest, negativeDiscoverMctpTerminusTest)
{
    const size_t getTidRespLen = PLDM_GET_TID_RESP_BYTES;
    const size_t setTidRespLen = PLDM_SET_TID_RESP_BYTES;
    const size_t getPldmTypesRespLen = PLDM_GET_TYPES_RESP_BYTES;

    // 0.terminus returns reserved tid
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp0{
        0x00, 0x02, 0x02, 0x00, PLDM_TID_RESERVED};
    auto rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp0.data()), sizeof(getTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::MctpInfos mctpInfos{};
    mctpInfos.emplace_back(pldm::MctpInfo(12, "", "", 1));
    mockTerminusManager.discoverMctpTerminus(mctpInfos);
    EXPECT_EQ(0, termini.size());

    // 1.terminus return cc=pldm_error for set tid
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp1{
        0x00, 0x02, 0x02, 0x00, 0x00};
    std::array<uint8_t, sizeof(pldm_msg_hdr) + setTidRespLen> setTidResp1{
        0x00, 0x02, 0x01, PLDM_ERROR};

    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp1.data()), sizeof(getTidResp1));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp1.data()), sizeof(setTidResp1));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    mockTerminusManager.removeMctpTerminus(mctpInfos);
    EXPECT_EQ(0, termini.size());

    // 2.terminus return cc=unsupported_pldm_cmd for set tid cmd and return
    // cc=pldm_error for get pldm types cmd
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp2{
        0x00, 0x02, 0x02, 0x00, 0x00};
    std::array<uint8_t, sizeof(pldm_msg_hdr) + setTidRespLen> setTidResp2{
        0x00, 0x02, 0x01, PLDM_ERROR_UNSUPPORTED_PLDM_CMD};
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmTypesRespLen>
        getPldmTypesResp2{0x00, 0x02, 0x04, PLDM_ERROR, 0x01, 0x00,
                          0x00, 0x00, 0x00, 0x00,       0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp2.data()), sizeof(getTidResp2));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp2.data()), sizeof(setTidResp2));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmTypesResp2.data()),
        sizeof(getPldmTypesResp2));
    EXPECT_EQ(rc, PLDM_SUCCESS);
    mockTerminusManager.removeMctpTerminus(mctpInfos);
    EXPECT_EQ(0, termini.size());
}

TEST_F(TerminusManagerTest, doesSupportTypeTest)
{
    const size_t getTidRespLen = PLDM_GET_TID_RESP_BYTES;
    const size_t setTidRespLen = PLDM_SET_TID_RESP_BYTES;
    const size_t getPldmTypesRespLen = PLDM_GET_TYPES_RESP_BYTES;

    // 0.discover a mctp list
    auto rc = mockTerminusManager.clearQueuedResponses();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp0{
        0x00, 0x02, 0x02, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp0.data()), sizeof(getTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + setTidRespLen> setTidResp0{
        0x00, 0x02, 0x01, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp0.data()), sizeof(setTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    uint8_t supportedType1Byte =
        (1 << (PLDM_BASE % 8)) + (1 << (PLDM_PLATFORM % 8)) +
        (1 << (PLDM_BIOS % 8)) + (1 << (PLDM_FRU % 8));
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmTypesRespLen>
        getPldmTypesResp0{0x00, 0x02, 0x04, 0x00, supportedType1Byte,
                          0x00, 0x00, 0x00, 0x00, 0x00,
                          0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmTypesResp0.data()),
        sizeof(getPldmTypesResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::MctpInfos mctpInfos{};
    mctpInfos.emplace_back(pldm::MctpInfo(12, "", "", 1));
    mockTerminusManager.discoverMctpTerminus(mctpInfos);
    EXPECT_EQ(1, termini.size());

    EXPECT_EQ(true, termini.contains(1));
    EXPECT_EQ(false, termini.contains(0));
    EXPECT_EQ(false, termini.contains(2));

    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_BASE));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_PLATFORM));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_BIOS));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_FRU));
    EXPECT_EQ(false, termini[1]->doesSupportType(PLDM_FWUP));
    EXPECT_EQ(false, termini[1]->doesSupportType(PLDM_OEM));
}

TEST_F(TerminusManagerTest, doesSupportCommandTest)
{
    const size_t getTidRespLen = PLDM_GET_TID_RESP_BYTES;
    const size_t setTidRespLen = PLDM_SET_TID_RESP_BYTES;
    const size_t getPldmTypesRespLen = PLDM_GET_TYPES_RESP_BYTES;
    const size_t getPldmCommandRespLen = PLDM_GET_COMMANDS_RESP_BYTES;

    // 0.discover a mctp list
    auto rc = mockTerminusManager.clearQueuedResponses();
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + getTidRespLen> getTidResp0{
        0x00, 0x02, 0x02, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getTidResp0.data()), sizeof(getTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::array<uint8_t, sizeof(pldm_msg_hdr) + setTidRespLen> setTidResp0{
        0x00, 0x02, 0x01, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(setTidResp0.data()), sizeof(setTidResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    uint8_t byte0 = (1 << (PLDM_BASE % 8)) + (1 << (PLDM_PLATFORM % 8)) +
                    (1 << (PLDM_BIOS % 8)) + (1 << (PLDM_FRU % 8));
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmTypesRespLen>
        getPldmTypesResp0{0x00, 0x02, 0x04, 0x00, byte0, 0x00,
                          0x00, 0x00, 0x00, 0x00, 0x00,  0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmTypesResp0.data()),
        sizeof(getPldmTypesResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    /* Response GetPLDMCommand BASE, CC=0,
     * SetTID/GetTID/GetPLDMTypes/GetPLDMCommands */
    byte0 = (1 << (PLDM_SET_TID % 8)) + (1 << (PLDM_GET_TID % 8)) +
            (1 << (PLDM_GET_PLDM_TYPES % 8)) +
            (1 << (PLDM_GET_PLDM_COMMANDS % 8));
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmCommandRespLen>
        getPldmCommandBaseResp0{
            0x00, 0x02, 0x05, 0x00, byte0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmCommandBaseResp0.data()),
        sizeof(getPldmCommandBaseResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    /* Response GetPLDMCommand PLATFORM, CC=0,
     * SetEventReceiver/PlatformEventMessage/GetSensorReading/SetNumericEffecterValue/GetNumericEffecterValue/GetPDR
     */
    /* byte0 command from 0x00 to 0x07 */
    byte0 = (1 << (PLDM_SET_EVENT_RECEIVER % 8)); // byte0 = 0x10
    /* byte1 command from 0x08 to 0xf */
    uint8_t byte1 = (1 << (PLDM_PLATFORM_EVENT_MESSAGE % 8)) +
                    (1 << (PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE % 8)) +
                    (1 << (PLDM_EVENT_MESSAGE_SUPPORTED % 8)) +
                    (1 << (PLDM_EVENT_MESSAGE_BUFFER_SIZE % 8)); // byte1 = 0x3c
    /* byte2 command from 0x10 to 0x17 */
    uint8_t byte2 = (1 << (PLDM_GET_SENSOR_READING % 8)); // byte2 = 0x02
    /* byte3 command from 0x18 to 0x1f */
    /* byte4 command from 0x20 to 0x27 */
    uint8_t byte4 = (1 << (PLDM_GET_STATE_SENSOR_READINGS % 8)); // byte4 = 0x02
    /* byte5 command from 0x28 to 0x2f */
    /* byte6 command from 0x30 to 0x37 */
    uint8_t byte6 =
        (1 << (PLDM_SET_NUMERIC_EFFECTER_VALUE % 8)) +
        (1 << (PLDM_GET_NUMERIC_EFFECTER_VALUE % 8)); // byte6 = 0x06
    /* byte7 command from 0x38 to 0x3f */
    uint8_t byte7 = (0 << (PLDM_SET_STATE_EFFECTER_STATES % 8)); // byte7 = 0
    /* byte8 command from 0x40 to 0x47 */
    /* byte9 command from 0x48 to 0x4f */
    /* byte10 command from 0x50 to 0x57 */
    uint8_t byte10 = (1 << (PLDM_GET_PDR_REPOSITORY_INFO % 8)) +
                     (1 << (PLDM_GET_PDR % 8)); // byte10 = 0x03
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmCommandRespLen>
        getPldmCommandPlatResp0{
            0x00, 0x02,  0x05,  0x00, byte0, byte1,  byte2, 0x00, byte4,
            0x00, byte6, byte7, 0x00, 0x00,  byte10, 0x00,  0x00, 0x00,
            0x00, 0x00,  0x00,  0x00, 0x00,  0x00,   0x00,  0x00, 0x00,
            0x00, 0x00,  0x00,  0x00, 0x00,  0x00,   0x00,  0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmCommandPlatResp0.data()),
        sizeof(getPldmCommandPlatResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    /* Response GetPLDMCommand BIOS, CC=0, GetDateTime/SetDateTime */
    /* byte0 command from 1 to 7 */
    byte0 = (0 << (PLDM_GET_BIOS_TABLE % 8)) +
            (0 << (PLDM_SET_BIOS_TABLE % 8)) +
            (0 << (PLDM_SET_BIOS_ATTRIBUTE_CURRENT_VALUE % 8));
    /* byte1 command from 8 to 15 */
    byte1 = (0 << (PLDM_GET_BIOS_ATTRIBUTE_CURRENT_VALUE_BY_HANDLE % 8)) +
            (1 << (PLDM_GET_DATE_TIME % 8)) + (1 << (PLDM_SET_DATE_TIME % 8));
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmCommandRespLen>
        getPldmCommandBiosResp0{
            0x00, 0x02, 0x05, 0x00, byte0, byte1, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00,  0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00,  0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00,  0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmCommandBiosResp0.data()),
        sizeof(getPldmCommandBiosResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    /* Response GetPLDMCommand FRU, CC=0,
     * GetFRURecordTableMetadata/GetFRURecordTable */
    /* byte0 command from 1 to 7 */
    byte0 = (1 << (PLDM_GET_FRU_RECORD_TABLE_METADATA % 8)) +
            (1 << (PLDM_GET_FRU_RECORD_TABLE % 8)) +
            (0 << (PLDM_SET_FRU_RECORD_TABLE % 8)) +
            (0 << (PLDM_GET_FRU_RECORD_BY_OPTION % 8));
    /* byte0 command from 8 to 15 */
    byte1 = 0;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPldmCommandRespLen>
        getPldmCommandFruResp0{
            0x00, 0x02, 0x05, 0x00, byte0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPldmCommandFruResp0.data()),
        sizeof(getPldmCommandFruResp0));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    pldm::MctpInfos mctpInfos{};
    mctpInfos.emplace_back(pldm::MctpInfo(12, "", "", 1));
    mockTerminusManager.discoverMctpTerminus(mctpInfos);
    EXPECT_EQ(1, termini.size());
    EXPECT_EQ(true, termini.contains(1));
    EXPECT_EQ(false, termini.contains(0));
    EXPECT_EQ(false, termini.contains(2));

    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_BASE));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_PLATFORM));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_BIOS));
    EXPECT_EQ(true, termini[1]->doesSupportType(PLDM_FRU));
    /* Check PLDM Base commands */
    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_BASE, PLDM_SET_TID));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_BASE, PLDM_GET_TID));
    EXPECT_EQ(false,
              termini[1]->doesSupportCommand(PLDM_BASE, PLDM_GET_PLDM_VERSION));
    EXPECT_EQ(true,
              termini[1]->doesSupportCommand(PLDM_BASE, PLDM_GET_PLDM_TYPES));

    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_BASE,
                                                   PLDM_GET_PLDM_COMMANDS));
    EXPECT_EQ(false, termini[1]->doesSupportCommand(PLDM_BASE,
                                                    PLDM_MULTIPART_RECEIVE));

    /* Check PLDM Platform commands */
    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_PLATFORM,
                                                   PLDM_SET_EVENT_RECEIVER));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_PLATFORM_EVENT_MESSAGE));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_POLL_FOR_PLATFORM_EVENT_MESSAGE));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_EVENT_MESSAGE_SUPPORTED));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_EVENT_MESSAGE_BUFFER_SIZE));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_PLATFORM,
                                                   PLDM_GET_SENSOR_READING));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_GET_STATE_SENSOR_READINGS));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_SET_NUMERIC_EFFECTER_VALUE));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_GET_NUMERIC_EFFECTER_VALUE));
    EXPECT_EQ(false, termini[1]->doesSupportCommand(
                         PLDM_PLATFORM, PLDM_SET_STATE_EFFECTER_STATES));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_PLATFORM, PLDM_GET_PDR_REPOSITORY_INFO));
    EXPECT_EQ(true,
              termini[1]->doesSupportCommand(PLDM_PLATFORM, PLDM_GET_PDR));

    /* Check PLDM Bios commands */
    EXPECT_EQ(false,
              termini[1]->doesSupportCommand(PLDM_BIOS, PLDM_GET_BIOS_TABLE));
    EXPECT_EQ(false,
              termini[1]->doesSupportCommand(PLDM_BIOS, PLDM_SET_BIOS_TABLE));
    EXPECT_EQ(false, termini[1]->doesSupportCommand(
                         PLDM_BIOS, PLDM_SET_BIOS_ATTRIBUTE_CURRENT_VALUE));
    EXPECT_EQ(false,
              termini[1]->doesSupportCommand(
                  PLDM_BIOS, PLDM_GET_BIOS_ATTRIBUTE_CURRENT_VALUE_BY_HANDLE));
    EXPECT_EQ(true,
              termini[1]->doesSupportCommand(PLDM_BIOS, PLDM_GET_DATE_TIME));
    EXPECT_EQ(true,
              termini[1]->doesSupportCommand(PLDM_BIOS, PLDM_SET_DATE_TIME));

    /* Check PLDM Fru commands */
    EXPECT_EQ(true, termini[1]->doesSupportCommand(
                        PLDM_FRU, PLDM_GET_FRU_RECORD_TABLE_METADATA));
    EXPECT_EQ(true, termini[1]->doesSupportCommand(PLDM_FRU,
                                                   PLDM_GET_FRU_RECORD_TABLE));
    EXPECT_EQ(false, termini[1]->doesSupportCommand(PLDM_FRU,
                                                    PLDM_SET_FRU_RECORD_TABLE));
    EXPECT_EQ(false, termini[1]->doesSupportCommand(
                         PLDM_FRU, PLDM_GET_FRU_RECORD_BY_OPTION));
}
