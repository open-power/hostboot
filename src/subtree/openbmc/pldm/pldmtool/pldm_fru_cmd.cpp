#include "pldm_fru_cmd.hpp"

#include "pldm_cmd_helper.hpp"

#ifdef OEM_IBM
#include "oem/ibm/libpldm/fru.h"
#endif

#include <endian.h>

#include <functional>
#include <tuple>

namespace pldmtool
{

namespace fru
{

namespace
{

using namespace pldmtool::helper;

std::vector<std::unique_ptr<CommandInterface>> commands;

} // namespace

class GetFruRecordTableMetadata : public CommandInterface
{
  public:
    ~GetFruRecordTableMetadata() = default;
    GetFruRecordTableMetadata() = delete;
    GetFruRecordTableMetadata(const GetFruRecordTableMetadata&) = delete;
    GetFruRecordTableMetadata(GetFruRecordTableMetadata&&) = default;
    GetFruRecordTableMetadata&
        operator=(const GetFruRecordTableMetadata&) = delete;
    GetFruRecordTableMetadata& operator=(GetFruRecordTableMetadata&&) = default;

    using CommandInterface::CommandInterface;

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr));
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_fru_record_table_metadata_req(
            instanceId, request, PLDM_GET_FRU_RECORD_TABLE_METADATA_REQ_BYTES);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t cc = 0;
        uint8_t fru_data_major_version, fru_data_minor_version;
        uint32_t fru_table_maximum_size, fru_table_length;
        uint16_t total_record_set_identifiers, total_table_records;
        uint32_t checksum;

        auto rc = decode_get_fru_record_table_metadata_resp(
            responsePtr, payloadLength, &cc, &fru_data_major_version,
            &fru_data_minor_version, &fru_table_maximum_size, &fru_table_length,
            &total_record_set_identifiers, &total_table_records, &checksum);
        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)cc << std::endl;
            return;
        }
        ordered_json output;
        output["FRUDATAMajorVersion"] =
            static_cast<uint32_t>(fru_data_major_version);
        output["FRUDATAMinorVersion"] =
            static_cast<uint32_t>(fru_data_minor_version);
        output["FRUTableMaximumSize"] = fru_table_maximum_size;
        output["FRUTableLength"] = fru_table_length;
        output["Total number of Record Set Identifiers in table"] =
            total_record_set_identifiers;
        output["Total number of records in table"] = total_table_records;
        output["FRU DATAStructureTableIntegrityChecksum"] = checksum;
        pldmtool::helper::DisplayInJson(output);
    }
};

class FRUTablePrint
{
  public:
    explicit FRUTablePrint(const uint8_t* table, size_t table_size) :
        table(table), table_size(table_size)
    {}

    void print()
    {
        auto p = table;
        ordered_json frutable;
        ordered_json output;
        while (!isTableEnd(p))
        {
            auto record =
                reinterpret_cast<const pldm_fru_record_data_format*>(p);
            output["FRU Record Set Identifier"] =
                (int)le16toh(record->record_set_id);
            output["FRU Record Type"] =
                typeToString(fruRecordTypes, record->record_type);
            output["Number of FRU fields"] = (int)record->num_fru_fields;
            output["Encoding Type for FRU fields"] =
                typeToString(fruEncodingType, record->encoding_type);

            p += sizeof(pldm_fru_record_data_format) -
                 sizeof(pldm_fru_record_tlv);

            std::map<uint8_t, std::string> FruFieldTypeMap;
            std::string fruFieldValue;

            ordered_json frudata;
            ordered_json frufielddata;
            frufielddata.emplace_back(output);
            for (int i = 0; i < record->num_fru_fields; i++)
            {
                auto tlv = reinterpret_cast<const pldm_fru_record_tlv*>(p);
                if (record->record_type == PLDM_FRU_RECORD_TYPE_GENERAL)
                {
                    FruFieldTypeMap.insert(fruGeneralFieldTypes.begin(),
                                           fruGeneralFieldTypes.end());
                    if (tlv->type == PLDM_FRU_FIELD_TYPE_IANA)
                    {
                        fruFieldValue =
                            fruFieldParserU32(tlv->value, tlv->length);
                    }
                    else if (tlv->type == PLDM_FRU_FIELD_TYPE_MANUFAC_DATE)
                    {
                        fruFieldValue =
                            fruFieldParserTimestamp(tlv->value, tlv->length);
                    }

                    frudata["FRU Field Type"] =
                        typeToString(FruFieldTypeMap, tlv->type);
                    frudata["FRU Field Length"] = (int)(tlv->length);
                    fruFieldValue =
                        fruFieldValuestring(tlv->value, tlv->length);
                    frudata["FRU Field Value"] = fruFieldValue;
                    frufielddata.emplace_back(frudata);
                }
                else
                {
#ifdef OEM_IBM
                    if (tlv->type == PLDM_OEM_FRU_FIELD_TYPE_RT)
                    {
                        auto oemIPZValue =
                            fruFieldValuestring(tlv->value, tlv->length);

                        if (populateMaps.find(oemIPZValue) !=
                            populateMaps.end())
                        {
                            const std::map<uint8_t, std::string> IPZTypes =
                                populateMaps.at(oemIPZValue);
                            FruFieldTypeMap.insert(IPZTypes.begin(),
                                                   IPZTypes.end());
                        }
                    }
                    else
                    {
                        FruFieldTypeMap.insert(fruOemFieldTypes.begin(),
                                               fruOemFieldTypes.end());
                    }
                    if (tlv->type == PLDM_OEM_FRU_FIELD_TYPE_IANA)
                    {
                        fruFieldValue =
                            fruFieldParserU32(tlv->value, tlv->length);
                    }
                    else if (tlv->type != 2)
                    {
                        fruFieldValue =
                            fruFieldIPZParser(tlv->value, tlv->length);
                    }
                    else
                    {
                        fruFieldValue =
                            fruFieldValuestring(tlv->value, tlv->length);
                    }
                    frudata["FRU Field Type"] =
                        typeToString(FruFieldTypeMap, tlv->type);
                    frudata["FRU Field Length"] = (int)(tlv->length);
                    frudata["FRU Field Value"] = fruFieldValue;
                    frufielddata.emplace_back(frudata);

#endif
                }
                p += sizeof(pldm_fru_record_tlv) - 1 + tlv->length;
            }
            frutable.emplace_back(frufielddata);
        }
        pldmtool::helper::DisplayInJson(frutable);
    }

  private:
    const uint8_t* table;
    size_t table_size;

    bool isTableEnd(const uint8_t* p)
    {
        auto offset = p - table;
        return (table_size - offset) <= 7;
    }

    static inline const std::map<uint8_t, std::string> fruEncodingType{
        {PLDM_FRU_ENCODING_UNSPECIFIED, "Unspecified"},
        {PLDM_FRU_ENCODING_ASCII, "ASCII"},
        {PLDM_FRU_ENCODING_UTF8, "UTF8"},
        {PLDM_FRU_ENCODING_UTF16, "UTF16"},
        {PLDM_FRU_ENCODING_UTF16LE, "UTF16LE"},
        {PLDM_FRU_ENCODING_UTF16BE, "UTF16BE"}};

    static inline const std::map<uint8_t, std::string> fruGeneralFieldTypes{
        {PLDM_FRU_FIELD_TYPE_CHASSIS, "Chassis"},
        {PLDM_FRU_FIELD_TYPE_MODEL, "Model"},
        {PLDM_FRU_FIELD_TYPE_PN, "Part Number"},
        {PLDM_FRU_FIELD_TYPE_SN, "Serial Number"},
        {PLDM_FRU_FIELD_TYPE_MANUFAC, "Manufacturer"},
        {PLDM_FRU_FIELD_TYPE_MANUFAC_DATE, "Manufacture Date"},
        {PLDM_FRU_FIELD_TYPE_VENDOR, "Vendor"},
        {PLDM_FRU_FIELD_TYPE_NAME, "Name"},
        {PLDM_FRU_FIELD_TYPE_SKU, "SKU"},
        {PLDM_FRU_FIELD_TYPE_VERSION, "Version"},
        {PLDM_FRU_FIELD_TYPE_ASSET_TAG, "Asset Tag"},
        {PLDM_FRU_FIELD_TYPE_DESC, "Description"},
        {PLDM_FRU_FIELD_TYPE_EC_LVL, "Engineering Change Level"},
        {PLDM_FRU_FIELD_TYPE_OTHER, "Other Information"},
        {PLDM_FRU_FIELD_TYPE_IANA, "Vendor IANA"}};

    static inline const std::map<uint8_t, std::string> fruRecordTypes{
        {PLDM_FRU_RECORD_TYPE_GENERAL, "General"},
        {PLDM_FRU_RECORD_TYPE_OEM, "OEM"}};

#ifdef OEM_IBM
    static inline const std::map<uint8_t, std::string> fruOemFieldTypes{
        {PLDM_OEM_FRU_FIELD_TYPE_IANA, "Vendor IANA"},
        {PLDM_OEM_FRU_FIELD_TYPE_RT, "RT"},
        {PLDM_OEM_FRU_FIELD_TYPE_LOCATION_CODE, "Location Code"}};

    static inline const std::map<uint8_t, std::string> VINIFieldTypes{
        {2, "RT"},  {3, "B3"},  {4, "B4"},  {5, "B7"},  {6, "CC"},  {7, "CE"},
        {8, "CT"},  {9, "DR"},  {10, "FG"}, {11, "FN"}, {12, "HE"}, {13, "HW"},
        {14, "HX"}, {15, "PN"}, {16, "SN"}, {17, "TS"}, {18, "VZ"}};

    static inline const std::map<uint8_t, std::string> VSYSFieldTypes{
        {2, "RT"},  {3, "BR"},  {4, "DR"},  {5, "FV"},  {6, "ID"},
        {7, "MN"},  {8, "NN"},  {9, "RB"},  {10, "RG"}, {11, "SE"},
        {12, "SG"}, {13, "SU"}, {14, "TM"}, {15, "TN"}, {16, "WN"}};

    static inline const std::map<uint8_t, std::string> LXR0FieldTypes{
        {2, "RT"}, {3, "LX"}, {4, "VZ"}};

    static inline const std::map<uint8_t, std::string> VW10FieldTypes{
        {2, "RT"}, {3, "DR"}, {4, "GD"}};

    static inline const std::map<uint8_t, std::string> VR10FieldTypes{
        {2, "RT"}, {3, "DC"}, {4, "DR"}, {5, "FL"}, {6, "WA"}};

    static inline const std::map<std::string,
                                 const std::map<uint8_t, std::string>>
        populateMaps{{"VINI", VINIFieldTypes},
                     {"VSYS", VSYSFieldTypes},
                     {"LXR0", LXR0FieldTypes},
                     {"VWX10", VW10FieldTypes},
                     {"VR10", VR10FieldTypes}};
#endif

    std::string typeToString(std::map<uint8_t, std::string> typeMap,
                             uint8_t type)
    {
        auto typeString = std::to_string(type);
        try
        {
            return std::string(typeMap.at(type)) + "(" + typeString + ")";
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }

    std::string fruFieldValuestring(const uint8_t* value, uint8_t length)
    {
        return std::string(reinterpret_cast<const char*>(value), length);
    }

    static std::string fruFieldParserU32(const uint8_t* value, uint8_t length)
    {
        assert(length == 4);
        uint32_t v;
        std::memcpy(&v, value, length);
        return std::to_string(le32toh(v));
    }

    static std::string fruFieldParserTimestamp(const uint8_t*, uint8_t)
    {
        return std::string("TODO");
    }

    static std::string fruFieldIPZParser(const uint8_t* value, uint8_t length)
    {
        std::ostringstream tempStream;
        for (int i = 0; i < int(length); ++i)
        {
            tempStream << "0x" << std::setfill('0') << std::setw(2) << std::hex
                       << (unsigned)value[i] << " ";
        }
        return tempStream.str();
    }
};

class GetFRURecordByOption : public CommandInterface
{
  public:
    ~GetFRURecordByOption() = default;
    GetFRURecordByOption() = delete;
    GetFRURecordByOption(const GetFRURecordByOption&) = delete;
    GetFRURecordByOption(GetFruRecordTableMetadata&&) = delete;
    GetFRURecordByOption& operator=(const GetFRURecordByOption&) = delete;
    GetFRURecordByOption& operator=(GetFRURecordByOption&&) = delete;

    explicit GetFRURecordByOption(const char* type, const char* name,
                                  CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option("-i, --identifier", recordSetIdentifier,
                        "Record Set Identifier\n"
                        "Possible values: {All record sets = 0, Specific "
                        "record set = 1 – 65535}")
            ->required();
        app->add_option("-r, --record", recordType,
                        "Record Type\n"
                        "Possible values: {All record types = 0, Specific "
                        "record types = 1 – 255}")
            ->required();
        app->add_option("-f, --field", fieldType,
                        "Field Type\n"
                        "Possible values: {All record field types = 0, "
                        "Specific field types = 1 – 15}")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        if (fieldType != 0 && recordType == 0)
        {
            throw std::invalid_argument("if field type is non-zero, the record "
                                        "type shall also be non-zero");
        }
        if (recordType == 254 && (fieldType > 2 && fieldType < 254))
        {
            throw std::invalid_argument(
                "GetFRURecordByOption is not supported for recordType : 254 "
                "and fieldType > 2");
        }

        auto payloadLength = sizeof(pldm_get_fru_record_by_option_req);

        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) + payloadLength,
                                        0);
        auto reqMsg = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_fru_record_by_option_req(
            instanceId, 0 /* DataTransferHandle */, 0 /* FRUTableHandle */,
            recordSetIdentifier, recordType, fieldType, PLDM_GET_FIRSTPART,
            reqMsg, payloadLength);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t cc;
        uint32_t dataTransferHandle;
        uint8_t transferFlag;
        variable_field fruData;

        auto rc = decode_get_fru_record_by_option_resp(
            responsePtr, payloadLength, &cc, &dataTransferHandle, &transferFlag,
            &fruData);

        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)cc << std::endl;
            return;
        }

        FRUTablePrint tablePrint(fruData.ptr, fruData.length);
        tablePrint.print();
    }

  private:
    uint16_t recordSetIdentifier;
    uint8_t recordType;
    uint8_t fieldType;
};

class GetFruRecordTable : public CommandInterface
{
  public:
    ~GetFruRecordTable() = default;
    GetFruRecordTable() = delete;
    GetFruRecordTable(const GetFruRecordTable&) = delete;
    GetFruRecordTable(GetFruRecordTable&&) = default;
    GetFruRecordTable& operator=(const GetFruRecordTable&) = delete;
    GetFruRecordTable& operator=(GetFruRecordTable&&) = default;

    using CommandInterface::CommandInterface;
    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                        PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc = encode_get_fru_record_table_req(
            instanceId, 0, PLDM_START_AND_END, request,
            requestMsg.size() - sizeof(pldm_msg_hdr));
        return {rc, requestMsg};
    }
    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t cc = 0;
        uint32_t next_data_transfer_handle = 0;
        uint8_t transfer_flag = 0;
        size_t fru_record_table_length = 0;
        std::vector<uint8_t> fru_record_table_data(payloadLength);

        auto rc = decode_get_fru_record_table_resp(
            responsePtr, payloadLength, &cc, &next_data_transfer_handle,
            &transfer_flag, fru_record_table_data.data(),
            &fru_record_table_length);

        if (rc != PLDM_SUCCESS || cc != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)cc << std::endl;
            return;
        }

        FRUTablePrint tablePrint(fru_record_table_data.data(),
                                 fru_record_table_length);
        tablePrint.print();
    }
};

void registerCommand(CLI::App& app)
{
    auto fru = app.add_subcommand("fru", "FRU type command");
    fru->require_subcommand(1);
    auto getFruRecordTableMetadata = fru->add_subcommand(
        "GetFruRecordTableMetadata", "get FRU record table metadata");
    commands.push_back(std::make_unique<GetFruRecordTableMetadata>(
        "fru", "GetFruRecordTableMetadata", getFruRecordTableMetadata));

    auto getFRURecordByOption =
        fru->add_subcommand("GetFRURecordByOption", "get FRU Record By Option");
    commands.push_back(std::make_unique<GetFRURecordByOption>(
        "fru", "GetFRURecordByOption", getFRURecordByOption));

    auto getFruRecordTable =
        fru->add_subcommand("GetFruRecordTable", "get FRU Record Table");
    commands.push_back(std::make_unique<GetFruRecordTable>(
        "fru", "GetFruRecordTable", getFruRecordTable));
}

} // namespace fru

} // namespace pldmtool
