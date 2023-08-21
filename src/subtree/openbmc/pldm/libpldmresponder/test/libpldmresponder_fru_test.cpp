#include "common/utils.hpp"
#include "libpldmresponder/fru.hpp"
#include "libpldmresponder/fru_parser.hpp"

#include <config.h>
#include <libpldm/pdr.h>

#include <sdbusplus/message.hpp>

#include <gtest/gtest.h>

TEST(FruParser, allScenarios)
{
    using namespace pldm::responder::fru_parser;

    FruParser parser{"./fru_jsons/good",
                     "./fru_jsons/fru_master/fru_master.json"};

    // Get an item with a single PLDM FRU record
    FruRecordInfos cpu{
        {1,
         1,
         {{"xyz.openbmc_project.Inventory.Decorator.Asset", "Model", "string",
           2},
          {"xyz.openbmc_project.Inventory.Decorator.Asset", "PartNumber",
           "string", 3},
          {"xyz.openbmc_project.Inventory.Decorator.Asset", "SerialNumber",
           "string", 4},
          {"xyz.openbmc_project.Inventory.Decorator.Asset", "Manufacturer",
           "string", 5},
          {"xyz.openbmc_project.Inventory.Item", "PrettyName", "string", 8},
          {"xyz.openbmc_project.Inventory.Decorator.AssetTag", "AssetTag",
           "string", 11},
          {"xyz.openbmc_project.Inventory.Decorator.Revision", "Version",
           "string", 10}}},
        {1,
         1,
         {{"xyz.openbmc_project.Inventory.Decorator.Asset", "PartNumber",
           "string", 3},
          {"xyz.openbmc_project.Inventory.Decorator.Asset", "SerialNumber",
           "string", 4}}}};
    auto cpuInfos =
        parser.getRecordInfo("xyz.openbmc_project.Inventory.Item.Cpu");
    ASSERT_EQ(cpuInfos.size(), 2);
    ASSERT_EQ(cpu == cpuInfos, true);

    // Get an item type with 3 PLDM FRU records
    auto boardInfos =
        parser.getRecordInfo("xyz.openbmc_project.Inventory.Item.Board");
    ASSERT_EQ(boardInfos.size(), 3);

    // D-Bus lookup info for FRU information
    DBusLookupInfo lookupInfo{
        "xyz.openbmc_project.Inventory.Manager",
        "/xyz/openbmc_project/inventory",
        {"xyz.openbmc_project.Inventory.Item.Chassis",
         "xyz.openbmc_project.Inventory.Item.Board",
         "xyz.openbmc_project.Inventory.Item.PCIeDevice",
         "xyz.openbmc_project.Inventory.Item.Board.Motherboard",
         "xyz.openbmc_project.Inventory.Item.Dimm",
         "xyz.openbmc_project.Inventory.Item.Panel",
         "xyz.openbmc_project.Inventory.Item.DiskBackplane",
         "xyz.openbmc_project.Inventory.Item.Fan",
         "xyz.openbmc_project.Inventory.Item.PowerSupply",
         "xyz.openbmc_project.Inventory.Item.Battery",
         "xyz.openbmc_project.Inventory.Item.Vrm",
         "xyz.openbmc_project.Inventory.Item.Cpu",
         "xyz.openbmc_project.Inventory.Item.Bmc",
         "xyz.openbmc_project.Inventory.Item.Connector",
         "xyz.openbmc_project.Inventory.Item.PCIeSlot",
         "xyz.openbmc_project.Inventory.Item.System",
         "xyz.openbmc_project.Inventory.Item.Tpm"}};
    auto dbusInfo = parser.inventoryLookup();
    ASSERT_EQ(dbusInfo == lookupInfo, true);

    ASSERT_THROW(
        parser.getRecordInfo("xyz.openbmc_project.Inventory.Item.DIMM"),
        std::exception);
}

TEST(FruImpl, updateAssociationTreeTest)
{
    using namespace pldm::responder;
    using namespace pldm::responder::fru_parser;
    using namespace pldm::responder::dbus;
    std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)> pdrRepo(
        pldm_pdr_init(), pldm_pdr_destroy);
    std::unique_ptr<pldm_entity_association_tree,
                    decltype(&pldm_entity_association_tree_destroy)>
        entityTree(pldm_entity_association_tree_init(),
                   pldm_entity_association_tree_destroy);
    std::unique_ptr<pldm_entity_association_tree,
                    decltype(&pldm_entity_association_tree_destroy)>
        bmcEntityTree(pldm_entity_association_tree_init(),
                      pldm_entity_association_tree_destroy);

    ObjectValueTree objects{
        {sdbusplus::message::object_path(
             "/xyz/openbmc_project/inventory/system"),
         {{"xyz.openbmc_project.Inventory.Item.System", {}}}},
        {sdbusplus::message::object_path(
             "/xyz/openbmc_project/inventory/system/chassis"),
         {{"xyz.openbmc_project.Inventory.Item.Chassis", {}}}},
        {sdbusplus::message::object_path(
             "/xyz/openbmc_project/inventory/system/chassis/motherboard"),
         {{"xyz.openbmc_project.Inventory.Item.Board.Motherboard", {}}}}};

    typedef struct test_pldm_entity_node
    {
        pldm_entity entity;
        pldm_entity parent;
        uint16_t host_container_id;
        pldm_entity_node* first_child;
        pldm_entity_node* next_sibling;
        uint8_t association_type;
    } test_pldm_entity_node;

    pldm::responder::FruImpl mockedFruHandler(FRU_JSONS_DIR, FRU_MASTER_JSON,
                                              pdrRepo.get(), entityTree.get(),
                                              bmcEntityTree.get());

    pldm_entity systemEntity{0x2d01, 1, 0};
    pldm_entity chassisEntity{0x2d, 1, 1};
    pldm_entity motherboardEntity{0x40, 1, 2};
    pldm_entity panelEntity{0x45, 1, 3};

    dbus::InterfaceMap systemIface{
        {"xyz.openbmc_project.Inventory.Item.System", {}}};
    dbus::InterfaceMap chassisIface{
        {"xyz.openbmc_project.Inventory.Item.Chassis", {}}};
    dbus::InterfaceMap motherboardIface{
        {"xyz.openbmc_project.Inventory.Item.Board.Motherboard", {}}};

    mockedFruHandler.updateAssociationTree(
        objects, "/xyz/openbmc_project/inventory/system/chassis/motherboard");

    pldm_entity_node* node = pldm_entity_association_tree_find(entityTree.get(),
                                                               &systemEntity);
    EXPECT_TRUE(node != NULL);

    node = pldm_entity_association_tree_find(entityTree.get(), &chassisEntity);
    EXPECT_TRUE(node != NULL);
    test_pldm_entity_node* test_node = (test_pldm_entity_node*)node;
    EXPECT_TRUE((test_node->parent).entity_type == systemEntity.entity_type);

    node = pldm_entity_association_tree_find(entityTree.get(),
                                             &motherboardEntity);
    EXPECT_TRUE(node != NULL);
    test_node = (test_pldm_entity_node*)node;
    EXPECT_TRUE((test_node->parent).entity_type == chassisEntity.entity_type);

    node = pldm_entity_association_tree_find(entityTree.get(), &panelEntity);
    EXPECT_TRUE(node == NULL);
}

TEST(FruImpl, entityByObjectPath)
{
    using namespace pldm::responder::dbus;
    std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)> pdrRepo(
        pldm_pdr_init(), pldm_pdr_destroy);
    std::unique_ptr<pldm_entity_association_tree,
                    decltype(&pldm_entity_association_tree_destroy)>
        entityTree(pldm_entity_association_tree_init(),
                   pldm_entity_association_tree_destroy);
    std::unique_ptr<pldm_entity_association_tree,
                    decltype(&pldm_entity_association_tree_destroy)>
        bmcEntityTree(pldm_entity_association_tree_init(),
                      pldm_entity_association_tree_destroy);

    InterfaceMap iface = {{"xyz.openbmc_project.Inventory.Item.Chassis", {}}};
    pldm::responder::FruImpl mockedFruHandler(FRU_JSONS_DIR, FRU_MASTER_JSON,
                                              pdrRepo.get(), entityTree.get(),
                                              bmcEntityTree.get());

    // Good path
    auto entityPtr = mockedFruHandler.getEntityByObjectPath(iface);
    pldm_entity entity = *entityPtr;
    EXPECT_TRUE(entity.entity_type == 45);
    // Bad Path
    InterfaceMap invalidIface = {
        {"xyz.openbmc_project.Inventory.Item.Motherboard", {}}};
    entityPtr = mockedFruHandler.getEntityByObjectPath(invalidIface);
    ASSERT_TRUE(!entityPtr);
}
