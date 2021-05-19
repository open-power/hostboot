#include "libpldmresponder/fru_parser.hpp"

#include <gtest/gtest.h>
TEST(FruParser, allScenarios)
{
    using namespace pldm::responder::fru_parser;

    FruParser parser{"./fru_jsons/good"};

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
         "xyz.openbmc_project.Inventory.Item.Board.Motherboard",
         "xyz.openbmc_project.Inventory.Item.Panel",
         "xyz.openbmc_project.Inventory.Item.PowerSupply",
         "xyz.openbmc_project.Inventory.Item.Vrm",
         "xyz.openbmc_project.Inventory.Item.Cpu",
         "xyz.openbmc_project.Inventory.Item.Bmc",
         "xyz.openbmc_project.Inventory.Item.Dimm",
         "xyz.openbmc_project.Inventory.Item.Tpm",
         "xyz.openbmc_project.Inventory.Item.System"}};
    auto dbusInfo = parser.inventoryLookup();
    ASSERT_EQ(dbusInfo == lookupInfo, true);

    ASSERT_THROW(
        parser.getRecordInfo("xyz.openbmc_project.Inventory.Item.DIMM"),
        std::exception);
}
