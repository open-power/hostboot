#include "common/test/mocked_utils.hpp"
#include "common/utils.hpp"
#include "host-bmc/utils.hpp"
#include "libpldmresponder/event_parser.hpp"
#include "libpldmresponder/fru.hpp"
#include "libpldmresponder/pdr.hpp"
#include "libpldmresponder/pdr_utils.hpp"
#include "libpldmresponder/platform.hpp"
#include "oem/ibm/libpldmresponder/collect_slot_vpd.hpp"
#include "oem/ibm/libpldmresponder/inband_code_update.hpp"
#include "oem/ibm/libpldmresponder/oem_ibm_handler.hpp"
#include "oem/ibm/libpldmresponder/utils.hpp"
#include "test/test_instance_id.hpp"

#include <libpldm/entity.h>
#include <libpldm/oem/ibm/entity.h>
#include <libpldm/pdr.h>

#include <nlohmann/json.hpp>
#include <phosphor-logging/lg2.hpp>
#include <sdeventplus/event.hpp>

#include <filesystem>
#include <fstream>

using namespace pldm::utils;
using namespace pldm::responder;
using namespace pldm::responder::pdr;
using namespace pldm::responder::pdr_utils;
using namespace pldm::responder::oem_ibm_platform;
using ::testing::Return;
using ::testing::ReturnRef;

class MockOemUtilsHandler : public oem_ibm_utils::Handler
{
  public:
    MockOemUtilsHandler(const pldm::utils::DBusHandler* dBusIntf) :
        oem_ibm_utils::Handler(dBusIntf)
    {}
};

class MockCodeUpdate : public CodeUpdate
{
  public:
    MockCodeUpdate(const pldm::utils::DBusHandler* dBusIntf) :
        CodeUpdate(dBusIntf)
    {}

    MOCK_METHOD(void, setVersions, (), (override));
};

class MockSlotHandler : public SlotHandler
{
  public:
    MockSlotHandler(const sdeventplus::Event& event, pldm_pdr* repo) :
        SlotHandler(event, repo)
    {}
};

class MockOemPlatformHandler : public oem_ibm_platform::Handler
{
  public:
    MockOemPlatformHandler(const pldm::utils::DBusHandler* dBusIntf,
                           pldm::responder::CodeUpdate* codeUpdate,
                           pldm::responder::SlotHandler* slotHandler,
                           int mctp_fd, uint8_t mctp_eid,
                           pldm::InstanceIdDb& instanceIdDb,
                           sdeventplus::Event& event) :
        oem_ibm_platform::Handler(dBusIntf, codeUpdate, slotHandler, mctp_fd,
                                  mctp_eid, instanceIdDb, event, nullptr)
    {}
    MOCK_METHOD(uint16_t, getNextEffecterId, ());
    MOCK_METHOD(uint16_t, getNextSensorId, ());
    MOCK_METHOD((const AssociatedEntityMap&), getAssociateEntityMap, (),
                (override));
};

TEST(OemSetStateEffecterStatesHandler, testGoodRequest)
{
    uint16_t entityID_ = PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE;
    uint16_t stateSetId_ = PLDM_OEM_IBM_BOOT_STATE;
    uint16_t entityInstance_ = 0;
    uint16_t containerId_ = 0;
    uint8_t compSensorCnt_ = 1;
    uint16_t effecterId = 0xA;
    uint16_t sensorId = 0x1;
    TestInstanceIdDb instanceIdDb;

    sdbusplus::bus_t bus(sdbusplus::bus::new_default());
    auto event = sdeventplus::Event::get_default();
    std::vector<get_sensor_state_field> stateField;

    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<MockOemPlatformHandler> oemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(
            mockDbusHandler.get(), mockCodeUpdate.get(), nullptr, 0x1, 0x9,
            instanceIdDb, event);

    const AssociatedEntityMap associateMap = {};
    EXPECT_CALL(*oemPlatformHandler, getAssociateEntityMap())
        .WillRepeatedly(ReturnRef(associateMap));

    auto rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, containerId_, stateSetId_, compSensorCnt_,
        sensorId, stateField);

    ASSERT_EQ(rc, PLDM_SUCCESS);
    ASSERT_EQ(stateField.size(), 1);
    ASSERT_EQ(stateField[0].event_state, tSideNum);
    ASSERT_EQ(stateField[0].sensor_op_state, PLDM_SENSOR_ENABLED);
    ASSERT_EQ(stateField[0].present_state, PLDM_SENSOR_UNKNOWN);
    ASSERT_EQ(stateField[0].previous_state, PLDM_SENSOR_UNKNOWN);

    entityInstance_ = 1;

    std::vector<get_sensor_state_field> stateField1;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, containerId_, stateSetId_, compSensorCnt_,
        sensorId, stateField1);
    ASSERT_EQ(rc, PLDM_SUCCESS);
    ASSERT_EQ(stateField1.size(), 1);
    ASSERT_EQ(stateField1[0].event_state, tSideNum);

    entityInstance_ = 2;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, containerId_, stateSetId_, compSensorCnt_,
        sensorId, stateField1);
    ASSERT_EQ(rc, PLDM_SUCCESS);
    ASSERT_EQ(stateField1[0].event_state, PLDM_SENSOR_UNKNOWN);

    entityID_ = 40;
    stateSetId_ = 50;
    rc = oemPlatformHandler->getOemStateSensorReadingsHandler(
        entityID_, entityInstance_, containerId_, stateSetId_, compSensorCnt_,
        sensorId, stateField1);
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

    std::vector<uint8_t> requestMsg(
        sizeof(pldm_msg_hdr) + PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES +
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
    const AssociatedEntityMap associateMap = {};
    auto inPDRRepo = pldm_pdr_init();
    sdbusplus::bus_t bus(sdbusplus::bus::new_default());
    TestInstanceIdDb instanceIdDb;
    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    auto event = sdeventplus::Event::get_default();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<MockOemPlatformHandler> mockoemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(
            mockDbusHandler.get(), mockCodeUpdate.get(), nullptr, 0x1, 0x9,
            instanceIdDb, event);
    Repo inRepo(inPDRRepo);

    EXPECT_CALL(*mockoemPlatformHandler, getAssociateEntityMap())
        .WillRepeatedly(ReturnRef(associateMap));

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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 1);
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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 1);
    ASSERT_EQ(pdr->container_id, 1);
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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 1);
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
    const AssociatedEntityMap associateMap = {};
    auto inPDRRepo = pldm_pdr_init();
    sdbusplus::bus_t bus(sdbusplus::bus::new_default());
    TestInstanceIdDb instanceIdDb;

    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    auto event = sdeventplus::Event::get_default();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<MockOemPlatformHandler> mockoemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(
            mockDbusHandler.get(), mockCodeUpdate.get(), nullptr, 0x1, 0x9,
            instanceIdDb, event);
    EXPECT_CALL(*mockoemPlatformHandler, getAssociateEntityMap())
        .WillRepeatedly(ReturnRef(associateMap));
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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 1);
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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 1);
    ASSERT_EQ(pdr->container_id, 1);
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
    ASSERT_EQ(pdr->terminus_handle, TERMINUS_HANDLE);
    ASSERT_EQ(pdr->entity_type, PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE);
    ASSERT_EQ(pdr->entity_instance, 0);
    ASSERT_EQ(pdr->container_id, 1);
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

TEST(updateOemDbusPath, testgoodpath)
{
    TestInstanceIdDb instanceIdDb;
    auto mockDbusHandler = std::make_unique<MockdBusHandler>();
    auto event = sdeventplus::Event::get_default();
    std::unique_ptr<CodeUpdate> mockCodeUpdate =
        std::make_unique<MockCodeUpdate>(mockDbusHandler.get());
    std::unique_ptr<oem_ibm_platform::Handler> mockoemPlatformHandler =
        std::make_unique<MockOemPlatformHandler>(
            mockDbusHandler.get(), mockCodeUpdate.get(), nullptr, 0x1, 0x9,
            instanceIdDb, event);
    std::string dbuspath = "/inventory/system1/chassis1/motherboard1/dcm0";
    mockoemPlatformHandler->updateOemDbusPaths(dbuspath);
    EXPECT_EQ(dbuspath, "/inventory/system/chassis/motherboard/dcm0");

    dbuspath = "/inventory/system/chassis/socket1/motherboard/dcm0";
    mockoemPlatformHandler->updateOemDbusPaths(dbuspath);
    EXPECT_EQ(dbuspath, "/inventory/system/chassis/motherboard/dcm0");
}

TEST(SetCoreCount, testgoodpath)
{
    pldm::utils::EntityMaps entityMaps = pldm::hostbmc::utils::parseEntityMap(
        "../../oem/ibm/test/entitymap_test.json");
    MockdBusHandler mockedDbusUtils;
    pldm_entity entities[9]{};

    entities[0].entity_type = 45;
    entities[0].entity_container_id = 0;

    entities[1].entity_type = 64;
    entities[1].entity_container_id = 1;

    entities[2].entity_type = 67;
    entities[2].entity_container_id = 2;
    entities[3].entity_type = 67;
    entities[3].entity_container_id = 2;

    entities[4].entity_type = 135;
    entities[4].entity_container_id = 3;
    entities[5].entity_type = 135;
    entities[5].entity_container_id = 3;
    entities[6].entity_type = 135;
    entities[6].entity_container_id = 3;
    entities[7].entity_type = 135;
    entities[7].entity_container_id = 3;
    entities[8].entity_type = 32903;
    entities[8].entity_container_id = 3;

    auto tree = pldm_entity_association_tree_init();

    auto l1 = pldm_entity_association_tree_add_entity(
        tree, &entities[0], 1, nullptr, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true,
        true, 0xFFFF);

    auto l2 = pldm_entity_association_tree_add_entity(
        tree, &entities[1], 1, l1, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l3a = pldm_entity_association_tree_add_entity(
        tree, &entities[2], 0, l2, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l3b = pldm_entity_association_tree_add_entity(
        tree, &entities[3], 1, l2, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l4a = pldm_entity_association_tree_add_entity(
        tree, &entities[4], 0, l3a, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l4b = pldm_entity_association_tree_add_entity(
        tree, &entities[5], 1, l3a, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l5a = pldm_entity_association_tree_add_entity(
        tree, &entities[6], 0, l3b, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l5b = pldm_entity_association_tree_add_entity(
        tree, &entities[7], 1, l3b, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l5c = pldm_entity_association_tree_add_entity(
        tree, &entities[8], 0, l5a, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l5ca = pldm_entity_association_tree_add_entity(
        tree, &entities[8], 0, l5b, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    pldm::utils::EntityAssociations entityAssociations = {
        {l1, l2},        {l2, l3a, l3b}, {l3a, l4a, l4b},
        {l3b, l5a, l5b}, {l5a, l5c},     {l5b, l5ca}};

    DBusMapping dbusMapping{"/foo/bar", "xyz.openbmc_project.Foo.Bar",
                            "propertyName", "uint64_t"};
    std::vector<std::string> cpuInterface = {"xyz.openbmc_project.Foo.Bar"};
    auto oemMockedUtils =
        std::make_unique<MockOemUtilsHandler>(&mockedDbusUtils);
    int coreCount =
        oemMockedUtils->setCoreCount(entityAssociations, entityMaps);
    EXPECT_EQ(coreCount, 2);
    pldm_entity_association_tree_destroy(tree);
}
