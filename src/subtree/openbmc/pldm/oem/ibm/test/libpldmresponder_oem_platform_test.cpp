#include "libpldm/entity.h"

#include "common/test/mocked_utils.hpp"
#include "common/utils.hpp"
#include "libpldmresponder/event_parser.hpp"
#include "libpldmresponder/pdr.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "libpldmresponder/platform.hpp"
#include "oem/ibm/libpldmresponder/inband_code_update.hpp"
#include "oem/ibm/libpldmresponder/oem_ibm_handler.hpp"

#include <sdeventplus/event.hpp>

#include <iostream>

using namespace pldm::utils;
using namespace pldm::responder;
using namespace pldm::responder::pdr;
using namespace pldm::responder::pdr_utils;
using namespace pldm::responder::oem_ibm_platform;

class MockCodeUpdate : public CodeUpdate
{
  public:
    MockCodeUpdate(const pldm::utils::DBusHandler* dBusIntf) :
        CodeUpdate(dBusIntf)
    {}

    MOCK_METHOD(void, setVersions, (), (override));
};

class MockOemPlatformHandler : public oem_ibm_platform::Handler
{
  public:
    MockOemPlatformHandler(const pldm::utils::DBusHandler* dBusIntf,
                           pldm::responder::CodeUpdate* codeUpdate, int mctp_fd,
                           uint8_t mctp_eid, Requester& requester,
                           sdeventplus::Event& event) :
        oem_ibm_platform::Handler(dBusIntf, codeUpdate, mctp_fd, mctp_eid,
                                  requester, event)
    {}
    MOCK_METHOD(uint16_t, getNextEffecterId, ());
    MOCK_METHOD(uint16_t, getNextSensorId, ());
};

TEST(OemSetStateEffecterStatesHandler, testGoodRequest)
{
    uint16_t entityID_ = PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE;
    uint16_t stateSetId_ = PLDM_OEM_IBM_BOOT_STATE;
    uint16_t entityInstance_ = 0;
    uint8_t compSensorCnt_ = 1;
    uint16_t effecterId = 0xA;
    sdbusplus::bus::bus bus(sdbusplus::bus::new_default());
    Requester requester(bus, "/abc/def");
    auto event = sdeventplus::Event::get_default();
    std::vector<get_sensor_state_field> stateField;

    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<oem_platform::Handler> oemPlatformHandler{};

    oemPlatformHandler = std::make_unique<oem_ibm_platform::Handler>(
        mockDbusHandler.get(), mockCodeUpdate.get(), 0x1, 0x9, requester,
        event);

    auto rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_, stateField);

    ASSERT_EQ(rc, PLDM_SUCCESS);
    ASSERT_EQ(stateField.size(), 1);
    ASSERT_EQ(stateField[0].event_state, tSideNum);
    ASSERT_EQ(stateField[0].sensor_op_state, PLDM_SENSOR_ENABLED);
    ASSERT_EQ(stateField[0].present_state, PLDM_SENSOR_UNKNOWN);
    ASSERT_EQ(stateField[0].previous_state, PLDM_SENSOR_UNKNOWN);

    entityInstance_ = 1;

    std::vector<get_sensor_state_field> stateField1;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_, stateField1);
    ASSERT_EQ(stateField1.size(), 1);
    ASSERT_EQ(stateField1[0].event_state, tSideNum);

    entityInstance_ = 2;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_, stateField1);
    ASSERT_EQ(stateField1[0].event_state, PLDM_SENSOR_UNKNOWN);

    entityID_ = 40;
    stateSetId_ = 50;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_, stateField1);
    ASSERT_EQ(rc, PLDM_PLATFORM_INVALID_STATE_VALUE);

    entityID_ = PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE;
    entityInstance_ = 0;
    stateSetId_ = PLDM_OEM_IBM_BOOT_STATE;
    compSensorCnt_ = 1;

    std::vector<set_effecter_state_field> setEffecterStateField;
    setEffecterStateField.push_back({PLDM_REQUEST_SET, pSideNum});

    rc = oemPlatformHandler->oemSetStateEffecterStatesHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_,
        setEffecterStateField, effecterId);
    ASSERT_EQ(rc, PLDM_SUCCESS);

    entityInstance_ = 2;
    rc = oemPlatformHandler->oemSetStateEffecterStatesHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_,
        setEffecterStateField, effecterId);

    ASSERT_EQ(rc, PLDM_PLATFORM_INVALID_STATE_VALUE);

    entityID_ = 34;
    stateSetId_ = 99;
    entityInstance_ = 0;
    rc = oemPlatformHandler->oemSetStateEffecterStatesHandler(
        entityID_, entityInstance_, stateSetId_, compSensorCnt_,
        setEffecterStateField, effecterId);
    ASSERT_EQ(rc, PLDM_PLATFORM_SET_EFFECTER_UNSUPPORTED_SENSORSTATE);
}

TEST(EncodeCodeUpdateEvent, testGoodRequest)
{
    size_t sensorEventSize = PLDM_SENSOR_EVENT_DATA_MIN_LENGTH + 1;
    std::vector<uint8_t> sensorEventDataVec{};
    sensorEventDataVec.resize(sensorEventSize);

    auto eventData = reinterpret_cast<struct pldm_sensor_event_data*>(
        sensorEventDataVec.data());
    eventData->sensor_id = 0xA;
    eventData->sensor_event_class_type = PLDM_SENSOR_OP_STATE;

    auto opStateSensorEventData =
        reinterpret_cast<struct pldm_sensor_event_sensor_op_state*>(
            sensorEventDataVec.data());
    opStateSensorEventData->present_op_state = uint8_t(CodeUpdateState::START);
    opStateSensorEventData->previous_op_state = uint8_t(CodeUpdateState::END);

    std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                    PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
                                    sensorEventDataVec.size());

    auto rc =
        encodeEventMsg(PLDM_SENSOR_EVENT, sensorEventDataVec, requestMsg, 0x1);

    EXPECT_EQ(rc, PLDM_SUCCESS);
}

TEST(EncodeCodeUpdate, testBadRequest)
{
    std::vector<uint8_t> requestMsg;
    std::vector<uint8_t> sensorEventDataVec{};

    auto rc =
        encodeEventMsg(PLDM_SENSOR_EVENT, sensorEventDataVec, requestMsg, 0x1);

    EXPECT_EQ(rc, PLDM_ERROR_INVALID_DATA);
}

TEST(clearDirPath, testClearDirPath)
{
    char dirPath[] = "/tmp/testClearDir/";
    fs::path dir(dirPath);
    fs::create_directories(dir);
    struct stat buffer;
    ASSERT_EQ(stat(dirPath, &buffer), 0);
    char filePath[] = "/tmp/testClearDir/file.txt";
    std::ofstream file(filePath);
    ASSERT_EQ(stat(filePath, &buffer), 0);

    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());

    mockCodeUpdate->clearDirPath(dirPath);
    ASSERT_EQ(stat(filePath, &buffer), -1);
    ASSERT_EQ(stat(dirPath, &buffer), 0);
}

TEST(generateStateEffecterOEMPDR, testGoodRequest)
{
    auto inPDRRepo = pldm_pdr_init();
    sdbusplus::bus::bus bus(sdbusplus::bus::new_default());
    Requester requester(bus, "/abc/def");
    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    auto event = sdeventplus::Event::get_default();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<oem_ibm_platform::Handler> mockoemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(mockDbusHandler.get(),
                                                 mockCodeUpdate.get(), 0x1, 0x9,
                                                 requester, event);
    Repo inRepo(inPDRRepo);

    mockoemPlatformHandler->buildOEMPDR(inRepo);
    ASSERT_EQ(inRepo.empty(), false);

    pdr_utils::PdrEntry e;

    // Test for effecter number 1, for current boot side state
    auto record1 = pdr::getRecordByHandle(inRepo, 1, e);
    ASSERT_NE(record1, nullptr);

    pldm_state_effecter_pdr* pdr =
        reinterpret_cast<pldm_state_effecter_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 1);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_EFFECTER_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 16);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->effecter_semantic_id, 0);
    ASSERT_EQ(pdr->effecter_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->has_description_pdr, false);
    ASSERT_EQ(pdr->composite_effecter_count, 1);
    state_effecter_possible_states* states =
        reinterpret_cast<state_effecter_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32769);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf1{};
    bf1.byte = 6;
    ASSERT_EQ(states->states[0].byte, bf1.byte);

    // Test for effecter number 2, for next boot side state
    auto record2 = pdr::getRecordByHandle(inRepo, 2, e);
    ASSERT_NE(record2, nullptr);

    pdr = reinterpret_cast<pldm_state_effecter_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 2);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_EFFECTER_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 16);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 1);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->effecter_semantic_id, 0);
    ASSERT_EQ(pdr->effecter_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->has_description_pdr, false);
    ASSERT_EQ(pdr->composite_effecter_count, 1);
    states =
        reinterpret_cast<state_effecter_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32769);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf2{};
    bf2.byte = 6;
    ASSERT_EQ(states->states[0].byte, bf2.byte);

    // Test for effecter number 3, for firmware update state control
    auto record3 = pdr::getRecordByHandle(inRepo, 3, e);
    ASSERT_NE(record3, nullptr);

    pdr = reinterpret_cast<pldm_state_effecter_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 3);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_EFFECTER_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 16);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->effecter_semantic_id, 0);
    ASSERT_EQ(pdr->effecter_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->has_description_pdr, false);
    ASSERT_EQ(pdr->composite_effecter_count, 1);
    states =
        reinterpret_cast<state_effecter_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32768);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf3{};
    bf3.byte = 126;
    ASSERT_EQ(states->states[0].byte, bf3.byte);

    pldm_pdr_destroy(inPDRRepo);
}

TEST(generateStateSensorOEMPDR, testGoodRequest)
{
    auto inPDRRepo = pldm_pdr_init();
    sdbusplus::bus::bus bus(sdbusplus::bus::new_default());
    Requester requester(bus, "/abc/def");

    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    auto event = sdeventplus::Event::get_default();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<oem_ibm_platform::Handler> mockoemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(mockDbusHandler.get(),
                                                 mockCodeUpdate.get(), 0x1, 0x9,
                                                 requester, event);
    Repo inRepo(inPDRRepo);
    mockoemPlatformHandler->buildOEMPDR(inRepo);
    ASSERT_EQ(inRepo.empty(), false);

    pdr_utils::PdrEntry e;

    // Test for sensor number 1, for current boot side state
    auto record1 = pdr::getRecordByHandle(inRepo, 5, e);
    ASSERT_NE(record1, nullptr);

    pldm_state_sensor_pdr* pdr =
        reinterpret_cast<pldm_state_sensor_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 5);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_SENSOR_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 14);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->sensor_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->sensor_auxiliary_names_pdr, false);
    ASSERT_EQ(pdr->composite_sensor_count, 1);
    state_sensor_possible_states* states =
        reinterpret_cast<state_sensor_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32769);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf1{};
    bf1.byte = 6;
    ASSERT_EQ(states->states[0].byte, bf1.byte);

    // Test for sensor number 2, for next boot side state
    auto record2 = pdr::getRecordByHandle(inRepo, 6, e);
    ASSERT_NE(record2, nullptr);

    pdr = reinterpret_cast<pldm_state_sensor_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 6);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_SENSOR_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 14);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 1);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->sensor_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->sensor_auxiliary_names_pdr, false);
    ASSERT_EQ(pdr->composite_sensor_count, 1);
    states =
        reinterpret_cast<state_sensor_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32769);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf2{};
    bf2.byte = 6;
    ASSERT_EQ(states->states[0].byte, bf2.byte);

    // Test for sensor number 3, for firmware update state control
    auto record3 = pdr::getRecordByHandle(inRepo, 7, e);
    ASSERT_NE(record3, nullptr);

    pdr = reinterpret_cast<pldm_state_sensor_pdr*>(e.data);

    ASSERT_EQ(pdr->hdr.record_handle, 7);
    ASSERT_EQ(pdr->hdr.version, 1);
    ASSERT_EQ(pdr->hdr.type, PLDM_STATE_SENSOR_PDR);
    ASSERT_EQ(pdr->hdr.record_change_num, 0);
    ASSERT_EQ(pdr->hdr.length, 14);
    ASSERT_EQ(pdr->terminus_handle, BmcPldmTerminusHandle);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 0);
    ASSERT_EQ(pdr->sensor_init, PLDM_NO_INIT);
    ASSERT_EQ(pdr->sensor_auxiliary_names_pdr, false);
    ASSERT_EQ(pdr->composite_sensor_count, 1);
    states =
        reinterpret_cast<state_sensor_possible_states*>(pdr->possible_states);
    ASSERT_EQ(states->state_set_id, 32768);
    ASSERT_EQ(states->possible_states_size, 2);
    bitfield8_t bf3{};
    bf3.byte = 126;
    ASSERT_EQ(states->states[0].byte, bf3.byte);

    pldm_pdr_destroy(inPDRRepo);
}
