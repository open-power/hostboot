#include "bios_string_attribute.hpp"

#include "common/utils.hpp"

#include <phosphor-logging/lg2.hpp>

#include <iostream>
#include <tuple>
#include <variant>

PHOSPHOR_LOG2_USING;

using namespace pldm::utils;

namespace pldm
{
namespace responder
{
namespace bios
{
BIOSStringAttribute::BIOSStringAttribute(const Json& entry,
                                         DBusHandler* const dbusHandler) :
    BIOSAttribute(entry, dbusHandler)
{
    std::string strTypeTmp = entry.at("string_type");
    auto iter = strTypeMap.find(strTypeTmp);
    if (iter == strTypeMap.end())
    {
        error(
            "Wrong string type, STRING_TYPE={STR_TYPE} ATTRIBUTE_NAME={ATTR_NAME}",
            "STR_TYP", strTypeTmp, "ATTR_NAME", name);
        throw std::invalid_argument("Wrong string type");
    }
    stringInfo.stringType = static_cast<uint8_t>(iter->second);

    stringInfo.minLength = entry.at("minimum_string_length");
    stringInfo.maxLength = entry.at("maximum_string_length");
    stringInfo.defLength = entry.at("default_string_length");
    stringInfo.defString = entry.at("default_string");

    pldm_bios_table_attr_entry_string_info info = {
        0,
        readOnly,
        stringInfo.stringType,
        stringInfo.minLength,
        stringInfo.maxLength,
        stringInfo.defLength,
        stringInfo.defString.data(),
    };

    const char* errmsg;
    auto rc = pldm_bios_table_attr_entry_string_info_check(&info, &errmsg);
    if (rc != PLDM_SUCCESS)
    {
        error(
            "Wrong field for string attribute, ATTRIBUTE_NAME={ATTR_NAME} ERRMSG={ERR_MSG} MINIMUM_STRING_LENGTH={MIN_LEN} MAXIMUM_STRING_LENGTH={MAX_LEN} DEFAULT_STRING_LENGTH={DEF_LEN} DEFAULT_STRING={DEF_STR}",
            "ATTR_NAME", name, "ERR_MSG", errmsg, "MIN_LEN",
            stringInfo.minLength, "MAX_LEN", stringInfo.maxLength, "DEF_LEN",
            stringInfo.defLength, "DEF_STR", stringInfo.defString);
        throw std::invalid_argument("Wrong field for string attribute");
    }
}

void BIOSStringAttribute::setAttrValueOnDbus(
    const pldm_bios_attr_val_table_entry* attrValueEntry,
    const pldm_bios_attr_table_entry*, const BIOSStringTable&)
{
    if (!dBusMap.has_value())
    {
        return;
    }

    PropertyValue value =
        table::attribute_value::decodeStringEntry(attrValueEntry);
    dbusHandler->setDbusProperty(*dBusMap, value);
}

std::string BIOSStringAttribute::getAttrValue()
{
    if (!dBusMap.has_value())
    {
        return stringInfo.defString;
    }
    try
    {
        return dbusHandler->getDbusProperty<std::string>(
            dBusMap->objectPath.c_str(), dBusMap->propertyName.c_str(),
            dBusMap->interface.c_str());
    }
    catch (const std::exception& e)
    {
        error("Get String Attribute Value Error: AttributeName = {ATTR_NAME}",
              "ATTR_NAME", name);
        return stringInfo.defString;
    }
}

void BIOSStringAttribute::constructEntry(
    const BIOSStringTable& stringTable, Table& attrTable, Table& attrValueTable,
    std::optional<std::variant<int64_t, std::string>> optAttributeValue)
{
    pldm_bios_table_attr_entry_string_info info = {
        stringTable.findHandle(name), readOnly,
        stringInfo.stringType,        stringInfo.minLength,
        stringInfo.maxLength,         stringInfo.defLength,
        stringInfo.defString.data(),
    };

    auto attrTableEntry = table::attribute::constructStringEntry(attrTable,
                                                                 &info);
    auto [attrHandle, attrType,
          _] = table::attribute::decodeHeader(attrTableEntry);

    std::string currStr{};
    if (optAttributeValue.has_value())
    {
        auto attributeValue = optAttributeValue.value();
        if (attributeValue.index() == 1)
        {
            currStr = std::get<std::string>(attributeValue);
        }
        else
        {
            currStr = getAttrValue();
        }
    }
    else
    {
        currStr = getAttrValue();
    }

    table::attribute_value::constructStringEntry(attrValueTable, attrHandle,
                                                 attrType, currStr);
}

int BIOSStringAttribute::updateAttrVal(Table& newValue, uint16_t attrHdl,
                                       uint8_t attrType,
                                       const PropertyValue& newPropVal)
{
    try
    {
        const auto& newStringValue = std::get<std::string>(newPropVal);
        table::attribute_value::constructStringEntry(newValue, attrHdl,
                                                     attrType, newStringValue);
    }
    catch (const std::bad_variant_access& e)
    {
        error("invalid value passed for the property, error: {ERR_EXCEP}",
              "ERR_EXCEP", e.what());
        return PLDM_ERROR;
    }
    return PLDM_SUCCESS;
}

void BIOSStringAttribute::generateAttributeEntry(
    const std::variant<int64_t, std::string>& attributevalue,
    Table& attrValueEntry)
{
    std::string value = std::get<std::string>(attributevalue);
    uint16_t len = value.size();

    attrValueEntry.resize(sizeof(pldm_bios_attr_val_table_entry) +
                          sizeof(uint16_t) + len - 1);

    auto entry = reinterpret_cast<pldm_bios_attr_val_table_entry*>(
        attrValueEntry.data());

    entry->attr_type = 1;
    memcpy(entry->value, &len, sizeof(uint16_t));
    memcpy(entry->value + sizeof(uint16_t), value.c_str(), value.size());
}

} // namespace bios
} // namespace responder
} // namespace pldm
