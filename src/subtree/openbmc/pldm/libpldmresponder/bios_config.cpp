#include "bios_config.hpp"

#include "bios_enum_attribute.hpp"
#include "bios_integer_attribute.hpp"
#include "bios_string_attribute.hpp"
#include "bios_table.hpp"
#include "common/bios_utils.hpp"

#include <xyz/openbmc_project/BIOSConfig/Manager/server.hpp>

#include <fstream>
#include <iostream>

#ifdef OEM_IBM
#include "oem/ibm/libpldmresponder/platform_oem_ibm.hpp"
#endif

namespace pldm
{
namespace responder
{
namespace bios
{
namespace
{

using BIOSConfigManager =
    sdbusplus::xyz::openbmc_project::BIOSConfig::server::Manager;

constexpr auto enumJsonFile = "enum_attrs.json";
constexpr auto stringJsonFile = "string_attrs.json";
constexpr auto integerJsonFile = "integer_attrs.json";

constexpr auto stringTableFile = "stringTable";
constexpr auto attrTableFile = "attributeTable";
constexpr auto attrValueTableFile = "attributeValueTable";

} // namespace

BIOSConfig::BIOSConfig(const char* jsonDir, const char* tableDir,
                       DBusHandler* const dbusHandler, int fd, uint8_t eid,
                       dbus_api::Requester* requester) :
    jsonDir(jsonDir),
    tableDir(tableDir), dbusHandler(dbusHandler), fd(fd), eid(eid),
    requester(requester)

{
    fs::create_directories(tableDir);
    constructAttributes();
    listenPendingAttributes();
}

void BIOSConfig::buildTables()
{
    auto stringTable = buildAndStoreStringTable();
    if (stringTable)
    {
        buildAndStoreAttrTables(*stringTable);
    }
}

std::optional<Table> BIOSConfig::getBIOSTable(pldm_bios_table_types tableType)
{
    fs::path tablePath;
    switch (tableType)
    {
        case PLDM_BIOS_STRING_TABLE:
            tablePath = tableDir / stringTableFile;
            break;
        case PLDM_BIOS_ATTR_TABLE:
            tablePath = tableDir / attrTableFile;
            break;
        case PLDM_BIOS_ATTR_VAL_TABLE:
            tablePath = tableDir / attrValueTableFile;
            break;
    }
    return loadTable(tablePath);
}

int BIOSConfig::setBIOSTable(uint8_t tableType, const Table& table,
                             bool updateBaseBIOSTable)
{
    fs::path stringTablePath(tableDir / stringTableFile);
    fs::path attrTablePath(tableDir / attrTableFile);
    fs::path attrValueTablePath(tableDir / attrValueTableFile);

    if (!pldm_bios_table_checksum(table.data(), table.size()))
    {
        return PLDM_INVALID_BIOS_TABLE_DATA_INTEGRITY_CHECK;
    }

    if (tableType == PLDM_BIOS_STRING_TABLE)
    {
        storeTable(stringTablePath, table);
    }
    else if (tableType == PLDM_BIOS_ATTR_TABLE)
    {
        BIOSTable biosStringTable(stringTablePath.c_str());
        if (biosStringTable.isEmpty())
        {
            return PLDM_INVALID_BIOS_TABLE_TYPE;
        }

        auto rc = checkAttributeTable(table);
        if (rc != PLDM_SUCCESS)
        {
            return rc;
        }

        storeTable(attrTablePath, table);
    }
    else if (tableType == PLDM_BIOS_ATTR_VAL_TABLE)
    {
        BIOSTable biosStringTable(stringTablePath.c_str());
        BIOSTable biosStringValueTable(attrTablePath.c_str());
        if (biosStringTable.isEmpty() || biosStringValueTable.isEmpty())
        {
            return PLDM_INVALID_BIOS_TABLE_TYPE;
        }

        auto rc = checkAttributeValueTable(table);
        if (rc != PLDM_SUCCESS)
        {
            return rc;
        }

        storeTable(attrValueTablePath, table);
    }
    else
    {
        return PLDM_INVALID_BIOS_TABLE_TYPE;
    }

    if ((tableType == PLDM_BIOS_ATTR_VAL_TABLE) && updateBaseBIOSTable)
    {
        std::cout << "setBIOSTable:: updateBaseBIOSTableProperty() "
                  << "\n";
        updateBaseBIOSTableProperty();
    }

    return PLDM_SUCCESS;
}

int BIOSConfig::checkAttributeTable(const Table& table)
{
    using namespace pldm::bios::utils;
    auto stringTable = getBIOSTable(PLDM_BIOS_STRING_TABLE);
    for (auto entry :
         BIOSTableIter<PLDM_BIOS_ATTR_TABLE>(table.data(), table.size()))
    {
        auto attrNameHandle =
            pldm_bios_table_attr_entry_decode_string_handle(entry);

        auto stringEnty = pldm_bios_table_string_find_by_handle(
            stringTable->data(), stringTable->size(), attrNameHandle);
        if (stringEnty == nullptr)
        {
            return PLDM_INVALID_BIOS_ATTR_HANDLE;
        }

        auto attrType = static_cast<pldm_bios_attribute_type>(
            pldm_bios_table_attr_entry_decode_attribute_type(entry));

        switch (attrType)
        {
            case PLDM_BIOS_ENUMERATION:
            case PLDM_BIOS_ENUMERATION_READ_ONLY:
            {
                auto pvNum =
                    pldm_bios_table_attr_entry_enum_decode_pv_num(entry);
                std::vector<uint16_t> pvHandls(pvNum);
                pldm_bios_table_attr_entry_enum_decode_pv_hdls(
                    entry, pvHandls.data(), pvHandls.size());
                auto defNum =
                    pldm_bios_table_attr_entry_enum_decode_def_num(entry);
                std::vector<uint8_t> defIndices(defNum);
                pldm_bios_table_attr_entry_enum_decode_def_indices(
                    entry, defIndices.data(), defIndices.size());

                for (size_t i = 0; i < pvHandls.size(); i++)
                {
                    auto stringEntry = pldm_bios_table_string_find_by_handle(
                        stringTable->data(), stringTable->size(), pvHandls[i]);
                    if (stringEntry == nullptr)
                    {
                        return PLDM_INVALID_BIOS_ATTR_HANDLE;
                    }
                }

                for (size_t i = 0; i < defIndices.size(); i++)
                {
                    auto stringEntry = pldm_bios_table_string_find_by_handle(
                        stringTable->data(), stringTable->size(),
                        pvHandls[defIndices[i]]);
                    if (stringEntry == nullptr)
                    {
                        return PLDM_INVALID_BIOS_ATTR_HANDLE;
                    }
                }
                break;
            }
            case PLDM_BIOS_INTEGER:
            case PLDM_BIOS_INTEGER_READ_ONLY:
            case PLDM_BIOS_STRING:
            case PLDM_BIOS_STRING_READ_ONLY:
            case PLDM_BIOS_PASSWORD:
            case PLDM_BIOS_PASSWORD_READ_ONLY:
                break;
            default:
                return PLDM_INVALID_BIOS_ATTR_HANDLE;
        }
    }

    return PLDM_SUCCESS;
}

int BIOSConfig::checkAttributeValueTable(const Table& table)
{
    using namespace pldm::bios::utils;
    auto stringTable = getBIOSTable(PLDM_BIOS_STRING_TABLE);
    auto attrTable = getBIOSTable(PLDM_BIOS_ATTR_TABLE);

    baseBIOSTableMaps.clear();

    for (auto tableEntry :
         BIOSTableIter<PLDM_BIOS_ATTR_VAL_TABLE>(table.data(), table.size()))
    {
        AttributeName attributeName{};
        AttributeType attributeType{};
        ReadonlyStatus readonlyStatus{};
        DisplayName displayName{};
        Description description{};
        MenuPath menuPath{};
        CurrentValue currentValue{};
        DefaultValue defaultValue{};
        Option options{};

        auto attrValueHandle =
            pldm_bios_table_attr_value_entry_decode_attribute_handle(
                tableEntry);
        auto attrType = static_cast<pldm_bios_attribute_type>(
            pldm_bios_table_attr_value_entry_decode_attribute_type(tableEntry));

        auto attrEntry = pldm_bios_table_attr_find_by_handle(
            attrTable->data(), attrTable->size(), attrValueHandle);
        if (attrEntry == nullptr)
        {
            return PLDM_INVALID_BIOS_ATTR_HANDLE;
        }
        auto attrHandle =
            pldm_bios_table_attr_entry_decode_attribute_handle(attrEntry);
        auto attrNameHandle =
            pldm_bios_table_attr_entry_decode_string_handle(attrEntry);

        auto stringEntry = pldm_bios_table_string_find_by_handle(
            stringTable->data(), stringTable->size(), attrNameHandle);
        if (stringEntry == nullptr)
        {
            return PLDM_INVALID_BIOS_ATTR_HANDLE;
        }
        auto strLength =
            pldm_bios_table_string_entry_decode_string_length(stringEntry);
        std::vector<char> buffer(strLength + 1 /* sizeof '\0' */);
        pldm_bios_table_string_entry_decode_string(stringEntry, buffer.data(),
                                                   buffer.size());
        attributeName = std::string(buffer.data(), buffer.data() + strLength);

        if (!biosAttributes.empty())
        {
            readonlyStatus =
                biosAttributes[attrHandle % biosAttributes.size()]->readOnly;
        }

        switch (attrType)
        {
            case PLDM_BIOS_ENUMERATION:
            case PLDM_BIOS_ENUMERATION_READ_ONLY:
            {
                auto getValue = [](uint16_t handle,
                                   const Table& table) -> std::string {
                    auto stringEntry = pldm_bios_table_string_find_by_handle(
                        table.data(), table.size(), handle);

                    auto strLength =
                        pldm_bios_table_string_entry_decode_string_length(
                            stringEntry);
                    std::vector<char> buffer(strLength + 1 /* sizeof '\0' */);
                    pldm_bios_table_string_entry_decode_string(
                        stringEntry, buffer.data(), buffer.size());

                    return std::string(buffer.data(),
                                       buffer.data() + strLength);
                };

                attributeType = "xyz.openbmc_project.BIOSConfig.Manager."
                                "AttributeType.Enumeration";

                auto pvNum =
                    pldm_bios_table_attr_entry_enum_decode_pv_num(attrEntry);
                std::vector<uint16_t> pvHandls(pvNum);
                pldm_bios_table_attr_entry_enum_decode_pv_hdls(
                    attrEntry, pvHandls.data(), pvHandls.size());

                // get possible_value
                for (size_t i = 0; i < pvHandls.size(); i++)
                {
                    options.push_back(
                        std::make_tuple("xyz.openbmc_project.BIOSConfig."
                                        "Manager.BoundType.OneOf",
                                        getValue(pvHandls[i], *stringTable)));
                }

                auto count =
                    pldm_bios_table_attr_value_entry_enum_decode_number(
                        tableEntry);
                std::vector<uint8_t> handles(count);
                pldm_bios_table_attr_value_entry_enum_decode_handles(
                    tableEntry, handles.data(), handles.size());

                // get current_value
                for (size_t i = 0; i < handles.size(); i++)
                {
                    currentValue = getValue(pvHandls[handles[i]], *stringTable);
                }

                auto defNum =
                    pldm_bios_table_attr_entry_enum_decode_def_num(attrEntry);
                std::vector<uint8_t> defIndices(defNum);
                pldm_bios_table_attr_entry_enum_decode_def_indices(
                    attrEntry, defIndices.data(), defIndices.size());

                // get default_value
                for (size_t i = 0; i < defIndices.size(); i++)
                {
                    defaultValue =
                        getValue(pvHandls[defIndices[i]], *stringTable);
                }

                break;
            }
            case PLDM_BIOS_INTEGER:
            case PLDM_BIOS_INTEGER_READ_ONLY:
            {
                attributeType = "xyz.openbmc_project.BIOSConfig.Manager."
                                "AttributeType.Integer";
                currentValue = static_cast<int64_t>(
                    pldm_bios_table_attr_value_entry_integer_decode_cv(
                        tableEntry));

                uint64_t lower, upper, def;
                uint32_t scalar;
                pldm_bios_table_attr_entry_integer_decode(
                    attrEntry, &lower, &upper, &scalar, &def);
                options.push_back(
                    std::make_tuple("xyz.openbmc_project.BIOSConfig.Manager."
                                    "BoundType.LowerBound",
                                    static_cast<int64_t>(lower)));
                options.push_back(
                    std::make_tuple("xyz.openbmc_project.BIOSConfig.Manager."
                                    "BoundType.UpperBound",
                                    static_cast<int64_t>(upper)));
                options.push_back(
                    std::make_tuple("xyz.openbmc_project.BIOSConfig.Manager."
                                    "BoundType.ScalarIncrement",
                                    static_cast<int64_t>(scalar)));
                defaultValue = static_cast<int64_t>(def);
                break;
            }
            case PLDM_BIOS_STRING:
            case PLDM_BIOS_STRING_READ_ONLY:
            {
                attributeType = "xyz.openbmc_project.BIOSConfig.Manager."
                                "AttributeType.String";
                variable_field currentString;
                pldm_bios_table_attr_value_entry_string_decode_string(
                    tableEntry, &currentString);
                currentValue = std::string(
                    reinterpret_cast<const char*>(currentString.ptr),
                    currentString.length);
                auto min = pldm_bios_table_attr_entry_string_decode_min_length(
                    attrEntry);
                auto max = pldm_bios_table_attr_entry_string_decode_max_length(
                    attrEntry);
                auto def =
                    pldm_bios_table_attr_entry_string_decode_def_string_length(
                        attrEntry);
                std::vector<char> defString(def + 1);
                pldm_bios_table_attr_entry_string_decode_def_string(
                    attrEntry, defString.data(), defString.size());
                options.push_back(
                    std::make_tuple("xyz.openbmc_project.BIOSConfig.Manager."
                                    "BoundType.MinStringLength",
                                    static_cast<int64_t>(min)));
                options.push_back(
                    std::make_tuple("xyz.openbmc_project.BIOSConfig.Manager."
                                    "BoundType.MaxStringLength",
                                    static_cast<int64_t>(max)));
                defaultValue = defString.data();
                break;
            }
            case PLDM_BIOS_PASSWORD:
            case PLDM_BIOS_PASSWORD_READ_ONLY:
            {
                attributeType = "xyz.openbmc_project.BIOSConfig.Manager."
                                "AttributeType.Password";
                break;
            }
            default:
                return PLDM_INVALID_BIOS_ATTR_HANDLE;
        }
        baseBIOSTableMaps.emplace(
            std::move(attributeName),
            std::make_tuple(attributeType, readonlyStatus, displayName,
                            description, menuPath, currentValue, defaultValue,
                            std::move(options)));
    }

    return PLDM_SUCCESS;
}

void BIOSConfig::updateBaseBIOSTableProperty()
{
    constexpr static auto biosConfigPath =
        "/xyz/openbmc_project/bios_config/manager";
    constexpr static auto biosConfigInterface =
        "xyz.openbmc_project.BIOSConfig.Manager";
    constexpr static auto biosConfigPropertyName = "BaseBIOSTable";
    constexpr static auto dbusProperties = "org.freedesktop.DBus.Properties";

    if (baseBIOSTableMaps.empty())
    {
        return;
    }

    try
    {
        auto& bus = dbusHandler->getBus();
        auto service =
            dbusHandler->getService(biosConfigPath, biosConfigInterface);
        auto method = bus.new_method_call(service.c_str(), biosConfigPath,
                                          dbusProperties, "Set");
        std::variant<BaseBIOSTable> value = baseBIOSTableMaps;
        method.append(biosConfigInterface, biosConfigPropertyName, value);
        bus.call_noreply(method);
    }
    catch (const std::exception& e)
    {
        std::cerr << "failed to update BaseBIOSTable property, ERROR="
                  << e.what() << "\n";
    }
}

void BIOSConfig::constructAttributes()
{
    load(jsonDir / stringJsonFile, [this](const Json& entry) {
        constructAttribute<BIOSStringAttribute>(entry);
    });
    load(jsonDir / integerJsonFile, [this](const Json& entry) {
        constructAttribute<BIOSIntegerAttribute>(entry);
    });
    load(jsonDir / enumJsonFile, [this](const Json& entry) {
        constructAttribute<BIOSEnumAttribute>(entry);
    });
}

void BIOSConfig::buildAndStoreAttrTables(const Table& stringTable)
{
    BIOSStringTable biosStringTable(stringTable);

    if (biosAttributes.empty())
    {
        return;
    }

    Table attrTable, attrValueTable;

    for (auto& attr : biosAttributes)
    {
        try
        {
            attr->constructEntry(biosStringTable, attrTable, attrValueTable);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Construct Table Entry Error, AttributeName = "
                      << attr->name << std::endl;
        }
    }

    table::appendPadAndChecksum(attrTable);
    table::appendPadAndChecksum(attrValueTable);
    setBIOSTable(PLDM_BIOS_ATTR_TABLE, attrTable);
    setBIOSTable(PLDM_BIOS_ATTR_VAL_TABLE, attrValueTable);
}

std::optional<Table> BIOSConfig::buildAndStoreStringTable()
{
    std::set<std::string> strings;
    auto handler = [&strings](const Json& entry) {
        strings.emplace(entry.at("attribute_name"));
    };

    load(jsonDir / stringJsonFile, handler);
    load(jsonDir / integerJsonFile, handler);
    load(jsonDir / enumJsonFile, [&strings](const Json& entry) {
        strings.emplace(entry.at("attribute_name"));
        auto possibleValues = entry.at("possible_values");
        for (auto& pv : possibleValues)
        {
            strings.emplace(pv);
        }
    });

    if (strings.empty())
    {
        return std::nullopt;
    }

    Table table;
    for (const auto& elem : strings)
    {
        table::string::constructEntry(table, elem);
    }

    table::appendPadAndChecksum(table);
    setBIOSTable(PLDM_BIOS_STRING_TABLE, table);
    return table;
}

void BIOSConfig::storeTable(const fs::path& path, const Table& table)
{
    BIOSTable biosTable(path.c_str());
    biosTable.store(table);
}

std::optional<Table> BIOSConfig::loadTable(const fs::path& path)
{
    BIOSTable biosTable(path.c_str());
    if (biosTable.isEmpty())
    {
        return std::nullopt;
    }

    Table table;
    biosTable.load(table);
    return table;
}

void BIOSConfig::load(const fs::path& filePath, ParseHandler handler)
{
    std::ifstream file;
    Json jsonConf;
    if (fs::exists(filePath))
    {
        try
        {
            file.open(filePath);
            jsonConf = Json::parse(file);
            auto entries = jsonConf.at("entries");
            for (auto& entry : entries)
            {
                try
                {
                    handler(entry);
                }
                catch (const std::exception& e)
                {
                    std::cerr
                        << "Failed to parse JSON config file(entry handler) : "
                        << filePath.c_str() << ", " << e.what() << std::endl;
                }
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed to parse JSON config file : "
                      << filePath.c_str() << std::endl;
        }
    }
}

int BIOSConfig::checkAttrValueToUpdate(
    const pldm_bios_attr_val_table_entry* attrValueEntry,
    const pldm_bios_attr_table_entry* attrEntry, Table&)

{
    auto [attrHandle, attrType] =
        table::attribute_value::decodeHeader(attrValueEntry);

    switch (attrType)
    {
        case PLDM_BIOS_ENUMERATION:
        {
            auto value =
                table::attribute_value::decodeEnumEntry(attrValueEntry);
            auto [pvHdls, defIndex] =
                table::attribute::decodeEnumEntry(attrEntry);
            assert(value.size() == 1);
            if (value[0] >= pvHdls.size())
            {
                std::cerr << "Enum: Illgeal index, Index = " << (int)value[0]
                          << std::endl;
                return PLDM_ERROR_INVALID_DATA;
            }

            return PLDM_SUCCESS;
        }
        case PLDM_BIOS_INTEGER:
        {
            auto value =
                table::attribute_value::decodeIntegerEntry(attrValueEntry);
            auto [lower, upper, scalar, def] =
                table::attribute::decodeIntegerEntry(attrEntry);

            if (value < lower || value > upper)
            {
                std::cerr << "Integer: out of bound, value = " << value
                          << std::endl;
                return PLDM_ERROR_INVALID_DATA;
            }
            return PLDM_SUCCESS;
        }
        case PLDM_BIOS_STRING:
        {
            auto stringConf = table::attribute::decodeStringEntry(attrEntry);
            auto value =
                table::attribute_value::decodeStringEntry(attrValueEntry);
            if (value.size() < stringConf.minLength ||
                value.size() > stringConf.maxLength)
            {
                std::cerr << "String: Length error, string = " << value
                          << " length = " << value.size() << std::endl;
                return PLDM_ERROR_INVALID_LENGTH;
            }
            return PLDM_SUCCESS;
        }
        default:
            std::cerr << "ReadOnly or Unspported type, type = " << attrType
                      << std::endl;
            return PLDM_ERROR;
    };
}

int BIOSConfig::setAttrValue(const void* entry, size_t size,
                             bool updateBaseBIOSTable)
{
    auto attrValueTable = getBIOSTable(PLDM_BIOS_ATTR_VAL_TABLE);
    auto attrTable = getBIOSTable(PLDM_BIOS_ATTR_TABLE);
    auto stringTable = getBIOSTable(PLDM_BIOS_STRING_TABLE);
    if (!attrValueTable || !attrTable || !stringTable)
    {
        return PLDM_BIOS_TABLE_UNAVAILABLE;
    }

    auto attrValueEntry =
        reinterpret_cast<const pldm_bios_attr_val_table_entry*>(entry);

    auto attrValHeader = table::attribute_value::decodeHeader(attrValueEntry);

    auto attrEntry =
        table::attribute::findByHandle(*attrTable, attrValHeader.attrHandle);
    if (!attrEntry)
    {
        return PLDM_ERROR;
    }

    auto rc = checkAttrValueToUpdate(attrValueEntry, attrEntry, *stringTable);
    if (rc != PLDM_SUCCESS)
    {
        return rc;
    }

    auto destTable =
        table::attribute_value::updateTable(*attrValueTable, entry, size);

    if (!destTable)
    {
        return PLDM_ERROR;
    }

    try
    {
        auto attrHeader = table::attribute::decodeHeader(attrEntry);

        BIOSStringTable biosStringTable(*stringTable);
        auto attrName = biosStringTable.findString(attrHeader.stringHandle);

        auto iter = std::find_if(
            biosAttributes.begin(), biosAttributes.end(),
            [&attrName](const auto& attr) { return attr->name == attrName; });

        if (iter == biosAttributes.end())
        {
            return PLDM_ERROR;
        }
        (*iter)->setAttrValueOnDbus(attrValueEntry, attrEntry, biosStringTable);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Set attribute value error: " << e.what() << std::endl;
        return PLDM_ERROR;
    }

    setBIOSTable(PLDM_BIOS_ATTR_VAL_TABLE, *destTable, updateBaseBIOSTable);

    return PLDM_SUCCESS;
}

void BIOSConfig::removeTables()
{
    try
    {
        fs::remove(tableDir / stringTableFile);
        fs::remove(tableDir / attrTableFile);
        fs::remove(tableDir / attrValueTableFile);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Remove the tables error: " << e.what() << std::endl;
    }
}

void BIOSConfig::processBiosAttrChangeNotification(
    const DbusChObjProperties& chProperties, uint32_t biosAttrIndex)
{
    const auto& dBusMap = biosAttributes[biosAttrIndex]->getDBusMap();
    const auto& propertyName = dBusMap->propertyName;
    const auto& attrName = biosAttributes[biosAttrIndex]->name;

    const auto it = chProperties.find(propertyName);
    if (it == chProperties.end())
    {
        return;
    }

    PropertyValue newPropVal = it->second;
    auto stringTable = getBIOSTable(PLDM_BIOS_STRING_TABLE);
    if (!stringTable.has_value())
    {
        std::cerr << "BIOS string table unavailable\n";
        return;
    }
    BIOSStringTable biosStringTable(*stringTable);
    uint16_t attrNameHdl{};
    try
    {
        attrNameHdl = biosStringTable.findHandle(attrName);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << "Could not find handle for BIOS string, ATTRIBUTE="
                  << attrName.c_str() << "\n";
        return;
    }

    auto attrTable = getBIOSTable(PLDM_BIOS_ATTR_TABLE);
    if (!attrTable.has_value())
    {
        std::cerr << "Attribute table not present\n";
        return;
    }
    const struct pldm_bios_attr_table_entry* tableEntry =
        table::attribute::findByStringHandle(*attrTable, attrNameHdl);
    if (tableEntry == nullptr)
    {
        std::cerr << "Attribute not found in attribute table, name= "
                  << attrName.c_str() << "name handle=" << attrNameHdl << "\n";
        return;
    }

    auto [attrHdl, attrType, stringHdl] =
        table::attribute::decodeHeader(tableEntry);

    auto attrValueSrcTable = getBIOSTable(PLDM_BIOS_ATTR_VAL_TABLE);

    if (!attrValueSrcTable.has_value())
    {
        std::cerr << "Attribute value table not present\n";
        return;
    }

    Table newValue;
    auto rc = biosAttributes[biosAttrIndex]->updateAttrVal(
        newValue, attrHdl, attrType, newPropVal);
    if (rc != PLDM_SUCCESS)
    {
        std::cerr << "Could not update the attribute value table for attribute "
                     "handle="
                  << attrHdl << " and type=" << (uint32_t)attrType << "\n";
        return;
    }
    auto destTable = table::attribute_value::updateTable(
        *attrValueSrcTable, newValue.data(), newValue.size());
    if (destTable.has_value())
    {
        storeTable(tableDir / attrValueTableFile, *destTable);
    }
}

uint16_t BIOSConfig::findAttrHandle(const std::string& attrName)
{
    auto stringTable = getBIOSTable(PLDM_BIOS_STRING_TABLE);
    auto attrTable = getBIOSTable(PLDM_BIOS_ATTR_TABLE);

    BIOSStringTable biosStringTable(*stringTable);
    pldm::bios::utils::BIOSTableIter<PLDM_BIOS_ATTR_TABLE> attrTableIter(
        attrTable->data(), attrTable->size());
    auto stringHandle = biosStringTable.findHandle(attrName);

    for (auto entry : pldm::bios::utils::BIOSTableIter<PLDM_BIOS_ATTR_TABLE>(
             attrTable->data(), attrTable->size()))
    {
        auto header = table::attribute::decodeHeader(entry);
        if (header.stringHandle == stringHandle)
        {
            return header.attrHandle;
        }
    }

    throw std::invalid_argument("Unknow attribute Name");
}

void BIOSConfig::constructPendingAttribute(
    const PendingAttributes& pendingAttributes)
{
    std::vector<uint16_t> listOfHandles{};

    for (auto& attribute : pendingAttributes)
    {
        std::string attributeName = attribute.first;
        auto& [attributeType, attributevalue] = attribute.second;

        auto iter = std::find_if(biosAttributes.begin(), biosAttributes.end(),
                                 [&attributeName](const auto& attr) {
                                     return attr->name == attributeName;
                                 });

        if (iter == biosAttributes.end())
        {
            std::cerr << "Wrong attribute name, attributeName = "
                      << attributeName << std::endl;
            continue;
        }

        Table attrValueEntry(sizeof(pldm_bios_attr_val_table_entry), 0);
        auto entry = reinterpret_cast<pldm_bios_attr_val_table_entry*>(
            attrValueEntry.data());

        auto handler = findAttrHandle(attributeName);
        auto type =
            BIOSConfigManager::convertAttributeTypeFromString(attributeType);

        if (type != BIOSConfigManager::AttributeType::Enumeration &&
            type != BIOSConfigManager::AttributeType::String &&
            type != BIOSConfigManager::AttributeType::Integer)
        {
            std::cerr << "Attribute type not supported, attributeType = "
                      << attributeType << std::endl;
            continue;
        }

        entry->attr_handle = htole16(handler);
        listOfHandles.emplace_back(htole16(handler));

        (*iter)->generateAttributeEntry(attributevalue, attrValueEntry);

        setAttrValue(attrValueEntry.data(), attrValueEntry.size(), false);
    }

    if (listOfHandles.size())
    {
#ifdef OEM_IBM
        auto rc = pldm::responder::platform::sendBiosAttributeUpdateEvent(
            fd, eid, requester, listOfHandles);
        if (rc != PLDM_SUCCESS)
        {
            return;
        }
#endif
        updateBaseBIOSTableProperty();
    }
}

void BIOSConfig::listenPendingAttributes()
{
    constexpr auto objPath = "/xyz/openbmc_project/bios_config/manager";
    constexpr auto objInterface = "xyz.openbmc_project.BIOSConfig.Manager";

    using namespace sdbusplus::bus::match::rules;
    auto updateBIOSMatch = std::make_unique<sdbusplus::bus::match::match>(
        pldm::utils::DBusHandler::getBus(),
        propertiesChanged(objPath, objInterface),
        [this](sdbusplus::message::message& msg) {
            constexpr auto propertyName = "PendingAttributes";

            using Value =
                std::variant<std::string, PendingAttributes, BaseBIOSTable>;
            using Properties = std::map<DbusProp, Value>;

            Properties props{};
            std::string intf;
            msg.read(intf, props);

            auto valPropMap = props.find(propertyName);
            if (valPropMap == props.end())
            {
                return;
            }

            PendingAttributes pendingAttributes =
                std::get<PendingAttributes>(valPropMap->second);
            this->constructPendingAttribute(pendingAttributes);
        });

    biosAttrMatch.emplace_back(std::move(updateBIOSMatch));
}

} // namespace bios
} // namespace responder
} // namespace pldm
