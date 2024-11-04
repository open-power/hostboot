#include "common/instance_id.hpp"
#include "mock_terminus_manager.hpp"
#include "platform-mc/platform_manager.hpp"
#include "test/test_instance_id.hpp"

#include <sdeventplus/event.hpp>

#include <bitset>

#include <gtest/gtest.h>

class PlatformManagerTest : public testing::Test
{
  protected:
    PlatformManagerTest() :
        bus(pldm::utils::DBusHandler::getBus()),
        event(sdeventplus::Event::get_default()), instanceIdDb(),
        reqHandler(pldmTransport, event, instanceIdDb, false,
                   std::chrono::seconds(1), 2, std::chrono::milliseconds(100)),
        mockTerminusManager(event, reqHandler, instanceIdDb, termini, nullptr),
        platformManager(mockTerminusManager, termini)
    {}

    PldmTransport* pldmTransport = nullptr;
    sdbusplus::bus_t& bus;
    sdeventplus::Event event;
    TestInstanceIdDb instanceIdDb;
    pldm::requester::Handler<pldm::requester::Request> reqHandler;
    pldm::platform_mc::MockTerminusManager mockTerminusManager;
    pldm::platform_mc::PlatformManager platformManager;
    std::map<pldm_tid_t, std::shared_ptr<pldm::platform_mc::Terminus>> termini;
};

TEST_F(PlatformManagerTest, initTerminusTest)
{
    // Add terminus
    auto mappedTid = mockTerminusManager.mapTid(pldm::MctpInfo(10, "", "", 1));
    auto tid = mappedTid.value();
    termini[tid] = std::make_shared<pldm::platform_mc::Terminus>(
        tid, 1 << PLDM_BASE | 1 << PLDM_PLATFORM);
    auto terminus = termini[tid];

    /* Set supported command by terminus */
    auto size = PLDM_MAX_TYPES * (PLDM_MAX_CMDS_PER_TYPE / 8);
    std::vector<uint8_t> pldmCmds(size);
    uint8_t type = PLDM_PLATFORM;
    uint8_t cmd = PLDM_GET_PDR;
    auto idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + (cmd / 8);
    pldmCmds[idx] = pldmCmds[idx] | (1 << (cmd % 8));
    cmd = PLDM_GET_PDR_REPOSITORY_INFO;
    idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + (cmd / 8);
    pldmCmds[idx] = pldmCmds[idx] | (1 << (cmd % 8));
    termini[tid]->setSupportedCommands(pldmCmds);

    // queue getPDRRepositoryInfo response
    const size_t getPDRRepositoryInfoLen =
        PLDM_GET_PDR_REPOSITORY_INFO_RESP_BYTES;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPDRRepositoryInfoLen>
        getPDRRepositoryInfoResp{
            0x0, 0x02, 0x50, PLDM_SUCCESS,
            0x0,                                     // repositoryState
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // updateTime
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // OEMUpdateTime
            2,   0x0,  0x0,  0x0,                    // recordCount
            0x0, 0x1,  0x0,  0x0,                    // repositorySize
            59,  0x0,  0x0,  0x0,                    // largestRecordSize
            0x0 // dataTransferHandleTimeout
        };
    auto rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPDRRepositoryInfoResp.data()),
        sizeof(getPDRRepositoryInfoResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // queue getPDR responses
    const size_t getPdrRespLen = 81;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrRespLen> getPdrResp{
        0x0, 0x02, 0x51, PLDM_SUCCESS, 0x1, 0x0, 0x0, 0x0, // nextRecordHandle
        0x0, 0x0, 0x0, 0x0, // nextDataTransferHandle
        0x5,                // transferFlag
        69, 0x0,            // responseCount
        // numeric Sensor PDR
        0x0, 0x0, 0x0,
        0x0,                     // record handle
        0x1,                     // PDRHeaderVersion
        PLDM_NUMERIC_SENSOR_PDR, // PDRType
        0x0,
        0x0,                     // recordChangeNumber
        PLDM_PDR_NUMERIC_SENSOR_PDR_FIXED_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_SENSOR_DATA_SIZE_MIN_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_RANGE_FIELD_MIN_LENGTH,
        0,                             // dataLength
        0,
        0,                             // PLDMTerminusHandle
        0x1,
        0x0,                           // sensorID=1
        120,
        0,                             // entityType=Power Supply(120)
        1,
        0,                             // entityInstanceNumber
        0x1,
        0x0,                           // containerID=1
        PLDM_NO_INIT,                  // sensorInit
        false,                         // sensorAuxiliaryNamesPDR
        PLDM_SENSOR_UNIT_DEGRESS_C,    // baseUint(2)=degrees C
        1,                             // unitModifier = 1
        0,                             // rateUnit
        0,                             // baseOEMUnitHandle
        0,                             // auxUnit
        0,                             // auxUnitModifier
        0,                             // auxRateUnit
        0,                             // rel
        0,                             // auxOEMUnitHandle
        true,                          // isLinear
        PLDM_SENSOR_DATA_SIZE_UINT8,   // sensorDataSize
        0, 0, 0xc0,
        0x3f,                          // resolution=1.5
        0, 0, 0x80,
        0x3f,                          // offset=1.0
        0,
        0,                             // accuracy
        0,                             // plusTolerance
        0,                             // minusTolerance
        2,                             // hysteresis
        0,                             // supportedThresholds
        0,                             // thresholdAndHysteresisVolatility
        0, 0, 0x80,
        0x3f,                          // stateTransistionInterval=1.0
        0, 0, 0x80,
        0x3f,                          // updateInverval=1.0
        255,                           // maxReadable
        0,                             // minReadable
        PLDM_RANGE_FIELD_FORMAT_UINT8, // rangeFieldFormat
        0,                             // rangeFieldsupport
        0,                             // nominalValue
        0,                             // normalMax
        0,                             // normalMin
        0,                             // warningHigh
        0,                             // warningLow
        0,                             // criticalHigh
        0,                             // criticalLow
        0,                             // fatalHigh
        0                              // fatalLow
    };
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrResp.data()), sizeof(getPdrResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    const size_t getPdrAuxNameRespLen = 39;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrAuxNameRespLen>
        getPdrAuxNameResp{
            0x0, 0x02, 0x51, PLDM_SUCCESS, 0x0, 0x0, 0x0,
            0x0,                // nextRecordHandle
            0x0, 0x0, 0x0, 0x0, // nextDataTransferHandle
            0x5,                // transferFlag
            0x1b, 0x0,          // responseCount
            // Common PDR Header
            0x1, 0x0, 0x0,
            0x0,                             // record handle
            0x1,                             // PDRHeaderVersion
            PLDM_ENTITY_AUXILIARY_NAMES_PDR, // PDRType
            0x1,
            0x0,                             // recordChangeNumber
            0x11,
            0,                               // dataLength
            /* Entity Auxiliary Names PDR Data*/
            3,
            0x80, // entityType system software
            0x1,
            0x0,  // Entity instance number =1
            0,
            0,    // Overall system
            0,    // shared Name Count one name only
            01,   // nameStringCount
            0x65, 0x6e, 0x00,
            0x00, // Language Tag "en"
            0x53, 0x00, 0x30, 0x00,
            0x00  // Entity Name "S0"
        };
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrAuxNameResp.data()),
        sizeof(getPdrAuxNameResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    stdexec::sync_wait(platformManager.initTerminus());
    EXPECT_EQ(true, terminus->initialized);
    EXPECT_EQ(2, terminus->pdrs.size());
    EXPECT_EQ(1, terminus->numericSensors.size());
    EXPECT_EQ("S0", terminus->getTerminusName().value());
}

TEST_F(PlatformManagerTest, parseTerminusNameTest)
{
    // Add terminus
    auto mappedTid = mockTerminusManager.mapTid(pldm::MctpInfo(10, "", "", 1));
    auto tid = mappedTid.value();
    termini[tid] = std::make_shared<pldm::platform_mc::Terminus>(
        tid, 1 << PLDM_BASE | 1 << PLDM_PLATFORM);
    auto terminus = termini[tid];

    /* Set supported command by terminus */
    auto size = PLDM_MAX_TYPES * (PLDM_MAX_CMDS_PER_TYPE / 8);
    std::vector<uint8_t> pldmCmds(size);
    uint8_t type = PLDM_PLATFORM;
    uint8_t cmd = PLDM_GET_PDR;
    auto idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + (cmd / 8);
    pldmCmds[idx] = pldmCmds[idx] | (1 << (cmd % 8));
    cmd = PLDM_GET_PDR_REPOSITORY_INFO;
    idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + (cmd / 8);
    pldmCmds[idx] = pldmCmds[idx] | (1 << (cmd % 8));
    termini[tid]->setSupportedCommands(pldmCmds);

    // queue getPDRRepositoryInfo response
    const size_t getPDRRepositoryInfoLen =
        PLDM_GET_PDR_REPOSITORY_INFO_RESP_BYTES;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPDRRepositoryInfoLen>
        getPDRRepositoryInfoResp{
            0x0, 0x02, 0x50, PLDM_SUCCESS,
            0x0,                                     // repositoryState
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // updateTime
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // OEMUpdateTime
            2,   0x0,  0x0,  0x0,                    // recordCount
            0x0, 0x1,  0x0,  0x0,                    // repositorySize
            59,  0x0,  0x0,  0x0,                    // largestRecordSize
            0x0 // dataTransferHandleTimeout
        };
    auto rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPDRRepositoryInfoResp.data()),
        sizeof(getPDRRepositoryInfoResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // queue getPDR responses
    const size_t getPdrRespLen = 81;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrRespLen> getPdrResp{
        0x0, 0x02, 0x51, PLDM_SUCCESS, 0x1, 0x0, 0x0, 0x0, // nextRecordHandle
        0x0, 0x0, 0x0, 0x0, // nextDataTransferHandle
        0x5,                // transferFlag
        69, 0x0,            // responseCount
        // numeric Sensor PDR
        0x0, 0x0, 0x0,
        0x0,                     // record handle
        0x1,                     // PDRHeaderVersion
        PLDM_NUMERIC_SENSOR_PDR, // PDRType
        0x0,
        0x0,                     // recordChangeNumber
        PLDM_PDR_NUMERIC_SENSOR_PDR_FIXED_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_SENSOR_DATA_SIZE_MIN_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_RANGE_FIELD_MIN_LENGTH,
        0,                             // dataLength
        0,
        0,                             // PLDMTerminusHandle
        0x1,
        0x0,                           // sensorID=1
        120,
        0,                             // entityType=Power Supply(120)
        1,
        0,                             // entityInstanceNumber
        0x1,
        0x0,                           // containerID=1
        PLDM_NO_INIT,                  // sensorInit
        false,                         // sensorAuxiliaryNamesPDR
        PLDM_SENSOR_UNIT_DEGRESS_C,    // baseUint(2)=degrees C
        1,                             // unitModifier = 1
        0,                             // rateUnit
        0,                             // baseOEMUnitHandle
        0,                             // auxUnit
        0,                             // auxUnitModifier
        0,                             // auxRateUnit
        0,                             // rel
        0,                             // auxOEMUnitHandle
        true,                          // isLinear
        PLDM_SENSOR_DATA_SIZE_UINT8,   // sensorDataSize
        0, 0, 0xc0,
        0x3f,                          // resolution=1.5
        0, 0, 0x80,
        0x3f,                          // offset=1.0
        0,
        0,                             // accuracy
        0,                             // plusTolerance
        0,                             // minusTolerance
        2,                             // hysteresis
        0,                             // supportedThresholds
        0,                             // thresholdAndHysteresisVolatility
        0, 0, 0x80,
        0x3f,                          // stateTransistionInterval=1.0
        0, 0, 0x80,
        0x3f,                          // updateInverval=1.0
        255,                           // maxReadable
        0,                             // minReadable
        PLDM_RANGE_FIELD_FORMAT_UINT8, // rangeFieldFormat
        0,                             // rangeFieldsupport
        0,                             // nominalValue
        0,                             // normalMax
        0,                             // normalMin
        0,                             // warningHigh
        0,                             // warningLow
        0,                             // criticalHigh
        0,                             // criticalLow
        0,                             // fatalHigh
        0                              // fatalLow
    };
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrResp.data()), sizeof(getPdrResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    const size_t getPdrAuxNameRespLen = 39;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrAuxNameRespLen>
        getPdrAuxNameResp{
            0x0, 0x02, 0x51, PLDM_SUCCESS, 0x0, 0x0, 0x0,
            0x0,                // nextRecordHandle
            0x0, 0x0, 0x0, 0x0, // nextDataTransferHandle
            0x5,                // transferFlag
            0x1b, 0x0,          // responseCount
            // Common PDR Header
            0x1, 0x0, 0x0,
            0x0,                             // record handle
            0x1,                             // PDRHeaderVersion
            PLDM_ENTITY_AUXILIARY_NAMES_PDR, // PDRType
            0x1,
            0x0,                             // recordChangeNumber
            0x11,
            0,                               // dataLength
            /* Entity Auxiliary Names PDR Data*/
            3,
            0x80, // entityType system software
            0x1,
            0x0,  // Entity instance number =1
            0,
            0,    // Overall system
            0,    // shared Name Count one name only
            01,   // nameStringCount
            0x65, 0x6e, 0x00,
            0x00, // Language Tag "en"
            0x53, 0x00, 0x30, 0x00,
            0x00  // Entity Name "S0"
        };
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrAuxNameResp.data()),
        sizeof(getPdrAuxNameResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    stdexec::sync_wait(platformManager.initTerminus());
    EXPECT_EQ(true, terminus->initialized);
    EXPECT_EQ(2, terminus->pdrs.size());
    EXPECT_EQ("S0", terminus->getTerminusName().value());
}

TEST_F(PlatformManagerTest, initTerminusDontSupportGetPDRTest)
{
    // Add terminus
    auto mappedTid = mockTerminusManager.mapTid(pldm::MctpInfo(10, "", "", 1));
    auto tid = mappedTid.value();
    termini[tid] = std::make_shared<pldm::platform_mc::Terminus>(
        tid, 1 << PLDM_BASE | 1 << PLDM_PLATFORM);
    auto terminus = termini[tid];

    /* Set supported command by terminus */
    auto size = PLDM_MAX_TYPES * (PLDM_MAX_CMDS_PER_TYPE / 8);
    std::vector<uint8_t> pldmCmds(size);
    uint8_t type = PLDM_PLATFORM;
    uint8_t cmd = PLDM_GET_PDR_REPOSITORY_INFO;
    auto idx = type * (PLDM_MAX_CMDS_PER_TYPE / 8) + (cmd / 8);
    pldmCmds[idx] = pldmCmds[idx] | (1 << (cmd % 8));
    termini[tid]->setSupportedCommands(pldmCmds);

    // queue getPDRRepositoryInfo response
    const size_t getPDRRepositoryInfoLen =
        PLDM_GET_PDR_REPOSITORY_INFO_RESP_BYTES;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPDRRepositoryInfoLen>
        getPDRRepositoryInfoResp{
            0x0, 0x02, 0x50, PLDM_SUCCESS,
            0x0,                                     // repositoryState
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // updateTime
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, 0x0,
            0x0, 0x0,  0x0,  0x0,          0x0, 0x0, // OEMUpdateTime
            1,   0x0,  0x0,  0x0,                    // recordCount
            0x0, 0x1,  0x0,  0x0,                    // repositorySize
            59,  0x0,  0x0,  0x0,                    // largestRecordSize
            0x0 // dataTransferHandleTimeout
        };
    auto rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPDRRepositoryInfoResp.data()),
        sizeof(getPDRRepositoryInfoResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // queue getPDR responses
    const size_t getPdrRespLen = 81;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrRespLen> getPdrResp{
        0x0, 0x02, 0x51, PLDM_SUCCESS, 0x0, 0x0, 0x0, 0x0, // nextRecordHandle
        0x0, 0x0, 0x0, 0x0, // nextDataTransferHandle
        0x5,                // transferFlag
        69, 0x0,            // responseCount
        // numeric Sensor PDR
        0x1, 0x0, 0x0,
        0x0,                     // record handle
        0x1,                     // PDRHeaderVersion
        PLDM_NUMERIC_SENSOR_PDR, // PDRType
        0x0,
        0x0,                     // recordChangeNumber
        PLDM_PDR_NUMERIC_SENSOR_PDR_FIXED_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_SENSOR_DATA_SIZE_MIN_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_RANGE_FIELD_MIN_LENGTH,
        0,                             // dataLength
        0,
        0,                             // PLDMTerminusHandle
        0x1,
        0x0,                           // sensorID=1
        120,
        0,                             // entityType=Power Supply(120)
        1,
        0,                             // entityInstanceNumber
        0x1,
        0x0,                           // containerID=1
        PLDM_NO_INIT,                  // sensorInit
        false,                         // sensorAuxiliaryNamesPDR
        PLDM_SENSOR_UNIT_DEGRESS_C,    // baseUint(2)=degrees C
        1,                             // unitModifier = 1
        0,                             // rateUnit
        0,                             // baseOEMUnitHandle
        0,                             // auxUnit
        0,                             // auxUnitModifier
        0,                             // auxRateUnit
        0,                             // rel
        0,                             // auxOEMUnitHandle
        true,                          // isLinear
        PLDM_SENSOR_DATA_SIZE_UINT8,   // sensorDataSize
        0, 0, 0xc0,
        0x3f,                          // resolution=1.5
        0, 0, 0x80,
        0x3f,                          // offset=1.0
        0,
        0,                             // accuracy
        0,                             // plusTolerance
        0,                             // minusTolerance
        2,                             // hysteresis
        0,                             // supportedThresholds
        0,                             // thresholdAndHysteresisVolatility
        0, 0, 0x80,
        0x3f,                          // stateTransistionInterval=1.0
        0, 0, 0x80,
        0x3f,                          // updateInverval=1.0
        255,                           // maxReadable
        0,                             // minReadable
        PLDM_RANGE_FIELD_FORMAT_UINT8, // rangeFieldFormat
        0,                             // rangeFieldsupport
        0,                             // nominalValue
        0,                             // normalMax
        0,                             // normalMin
        0,                             // warningHigh
        0,                             // warningLow
        0,                             // criticalHigh
        0,                             // criticalLow
        0,                             // fatalHigh
        0                              // fatalLow
    };
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrResp.data()), sizeof(getPdrResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    stdexec::sync_wait(platformManager.initTerminus());
    EXPECT_EQ(true, terminus->initialized);
    EXPECT_EQ(0, terminus->pdrs.size());
}

TEST_F(PlatformManagerTest, negativeInitTerminusTest1)
{
    // terminus doesn't Type2 support
    auto mappedTid = mockTerminusManager.mapTid(pldm::MctpInfo(10, "", "", 1));
    auto tid = mappedTid.value();
    termini[tid] =
        std::make_shared<pldm::platform_mc::Terminus>(tid, 1 << PLDM_BASE);
    auto terminus = termini[tid];

    stdexec::sync_wait(platformManager.initTerminus());
    EXPECT_EQ(true, terminus->initialized);
    EXPECT_EQ(0, terminus->pdrs.size());
    EXPECT_EQ(0, terminus->numericSensors.size());
}

TEST_F(PlatformManagerTest, negativeInitTerminusTest2)
{
    // terminus responses error
    auto mappedTid = mockTerminusManager.mapTid(pldm::MctpInfo(10, "", "", 1));
    auto tid = mappedTid.value();
    termini[tid] = std::make_shared<pldm::platform_mc::Terminus>(
        tid, 1 << PLDM_BASE | 1 << PLDM_PLATFORM);
    auto terminus = termini[tid];

    // queue getPDRRepositoryInfo response cc=PLDM_ERROR
    const size_t getPDRRepositoryInfoLen = 1;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPDRRepositoryInfoLen>
        getPDRRepositoryInfoResp{0x0, 0x02, 0x50, PLDM_ERROR};
    auto rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPDRRepositoryInfoResp.data()),
        sizeof(getPDRRepositoryInfoResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    // queue getPDR responses cc=PLDM_ERROR
    const size_t getPdrRespLen = 1;
    std::array<uint8_t, sizeof(pldm_msg_hdr) + getPdrRespLen> getPdrResp{
        0x0, 0x02, 0x51, PLDM_ERROR};
    rc = mockTerminusManager.enqueueResponse(
        reinterpret_cast<pldm_msg*>(getPdrResp.data()), sizeof(getPdrResp));
    EXPECT_EQ(rc, PLDM_SUCCESS);

    stdexec::sync_wait(platformManager.initTerminus());
    EXPECT_EQ(true, terminus->initialized);
    EXPECT_EQ(0, terminus->pdrs.size());
    EXPECT_EQ(0, terminus->numericSensors.size());
}
