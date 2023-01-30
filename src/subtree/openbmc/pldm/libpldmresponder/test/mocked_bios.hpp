#include "libpldmresponder/bios_table.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::ElementsAreArray;

class MockBIOSStringTable : public pldm::responder::bios::BIOSStringTable
{
  public:
    MockBIOSStringTable() : BIOSStringTable({})
    {}

    MOCK_METHOD(uint16_t, findHandle, (const std::string&), (const override));

    MOCK_METHOD(std::string, findString, (const uint16_t), (const override));
};

void checkHeader(const pldm::responder::bios::Table& attrEntry,
                 const pldm::responder::bios::Table& attrValueEntry)
{
    auto attrHeader = pldm::responder::bios::table::attribute::decodeHeader(
        reinterpret_cast<const pldm_bios_attr_table_entry*>(attrEntry.data()));
    auto attrValueHeader =
        pldm::responder::bios::table::attribute_value::decodeHeader(
            reinterpret_cast<const pldm_bios_attr_val_table_entry*>(
                attrValueEntry.data()));

    EXPECT_EQ(attrHeader.attrHandle, attrValueHeader.attrHandle);
}

void checkEntry(pldm::responder::bios::Table& entry,
                pldm::responder::bios::Table& expectedEntry)
{
    /** backup the attr handle */
    auto attr0 = entry[0], eAttr0 = expectedEntry[0];
    auto attr1 = entry[1], eAttr1 = expectedEntry[1];

    /** attr handle is computed by libpldm, set it to 0 to test */
    entry[0] = 0, expectedEntry[0] = 0;
    entry[1] = 0, expectedEntry[1] = 0;

    EXPECT_THAT(entry, ElementsAreArray(expectedEntry));

    /** restore the attr handle */
    entry[0] = attr0, expectedEntry[0] = eAttr0;
    entry[1] = attr1, expectedEntry[1] = eAttr1;
}

void checkConstructEntry(pldm::responder::bios::BIOSAttribute& attribute,
                         pldm::responder::bios::BIOSStringTable& stringTable,
                         pldm::responder::bios::Table& expectedAttrEntry,
                         pldm::responder::bios::Table& expectedAttrValueEntry)
{
    pldm::responder::bios::Table attrEntry, attrValueEntry;
    attribute.constructEntry(stringTable, attrEntry, attrValueEntry);

    checkHeader(attrEntry, attrValueEntry);
    checkEntry(attrEntry, expectedAttrEntry);
    checkEntry(attrValueEntry, expectedAttrValueEntry);
}