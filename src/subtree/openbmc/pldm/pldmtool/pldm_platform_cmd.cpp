#include "libpldm/entity.h"
#include "libpldm/state_set.h"

#include "common/types.hpp"
#include "pldm_cmd_helper.hpp"

namespace pldmtool
{

namespace platform
{

namespace
{

using namespace pldmtool::helper;

static const std::map<uint8_t, std::string> sensorPresState{
    {PLDM_SENSOR_UNKNOWN, "Sensor Unknown"},
    {PLDM_SENSOR_NORMAL, "Sensor Normal"},
    {PLDM_SENSOR_WARNING, "Sensor Warning"},
    {PLDM_SENSOR_CRITICAL, "Sensor Critical"},
    {PLDM_SENSOR_FATAL, "Sensor Fatal"},
    {PLDM_SENSOR_LOWERWARNING, "Sensor Lower Warning"},
    {PLDM_SENSOR_LOWERCRITICAL, "Sensor Lower Critical"},
    {PLDM_SENSOR_LOWERFATAL, "Sensor Lower Fatal"},
    {PLDM_SENSOR_UPPERWARNING, "Sensor Upper Warning"},
    {PLDM_SENSOR_UPPERCRITICAL, "Sensor Upper Critical"},
    {PLDM_SENSOR_UPPERFATAL, "Sensor Upper Fatal"}};

static const std::map<uint8_t, std::string> sensorOpState{
    {PLDM_SENSOR_ENABLED, "Sensor Enabled"},
    {PLDM_SENSOR_DISABLED, "Sensor Disabled"},
    {PLDM_SENSOR_UNAVAILABLE, "Sensor Unavailable"},
    {PLDM_SENSOR_STATUSUNKOWN, "Sensor Status Unknown"},
    {PLDM_SENSOR_FAILED, "Sensor Failed"},
    {PLDM_SENSOR_INITIALIZING, "Sensor Sensor Intializing"},
    {PLDM_SENSOR_SHUTTINGDOWN, "Sensor Shutting down"},
    {PLDM_SENSOR_INTEST, "Sensor Intest"}};

std::vector<std::unique_ptr<CommandInterface>> commands;

} // namespace

using ordered_json = nlohmann::ordered_json;

class GetPDR : public CommandInterface
{
  public:
    ~GetPDR() = default;
    GetPDR() = delete;
    GetPDR(const GetPDR&) = delete;
    GetPDR(GetPDR&&) = default;
    GetPDR& operator=(const GetPDR&) = delete;
    GetPDR& operator=(GetPDR&&) = default;

    using CommandInterface::CommandInterface;

    explicit GetPDR(const char* type, const char* name, CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-d,--data", recordHandle,
               "retrieve individual PDRs from a PDR Repository\n"
               "eg: The recordHandle value for the PDR to be retrieved and 0 "
               "means get first PDR in the repository.")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(sizeof(pldm_msg_hdr) +
                                        PLDM_GET_PDR_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        auto rc =
            encode_get_pdr_req(instanceId, recordHandle, 0, PLDM_GET_FIRSTPART,
                               UINT16_MAX, 0, request, PLDM_GET_PDR_REQ_BYTES);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t recordData[UINT16_MAX] = {0};
        uint32_t nextRecordHndl = 0;
        uint32_t nextDataTransferHndl = 0;
        uint8_t transferFlag = 0;
        uint16_t respCnt = 0;
        uint8_t transferCRC = 0;

        auto rc = decode_get_pdr_resp(
            responsePtr, payloadLength, &completionCode, &nextRecordHndl,
            &nextDataTransferHndl, &transferFlag, &respCnt, recordData,
            sizeof(recordData), &transferCRC);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }

        printPDRMsg(nextRecordHndl, respCnt, recordData);
    }

  private:
    const std::map<pldm::pdr::EntityType, std::string> entityType = {
        {PLDM_ENTITY_COMM_CHANNEL, "Communication Channel"},
        {PLDM_ENTITY_SYS_FIRMWARE, "System Firmware"},
        {PLDM_ENTITY_VIRTUAL_MACHINE_MANAGER, "Virtual Machine Manager"},
        {PLDM_ENTITY_SYSTEM_CHASSIS, "System chassis (main enclosure)"},
        {PLDM_ENTITY_SYS_BOARD, "System Board"},
        {PLDM_ENTITY_DRIVE_BACKPLANE, "Drive backplane"},
        {PLDM_ENTITY_MEMORY_MODULE, "Memory Module"},
        {PLDM_ENTITY_PROC_MODULE, "Processor Module"},
        {PLDM_ENTITY_CHASSIS_FRONT_PANEL_BOARD,
         "Chassis front panel board (control panel)"},
        {PLDM_ENTITY_POWER_CONVERTER, "Power converter"},
        {PLDM_ENTITY_PROC, "Processor"},
        {PLDM_ENTITY_MGMT_CONTROLLER, "Management Controller"},
        {PLDM_ENTITY_CONNECTOR, "Connector"},
        {PLDM_ENTITY_FAN, "Fan"},
        {PLDM_ENTITY_SOLID_STATE_SRIVE, "Solid State Drive"},
        {PLDM_ENTITY_POWER_SUPPLY, "Power Supply"},
        {PLDM_ENTITY_MEMORY_CHIP, "Memory chip"},
        {PLDM_ENTITY_REAL_TIME_CLOCK, "Real Time Clock (RTC)"},
        {PLDM_ENTITY_SLOT, "Slot"},
        {PLDM_ENTITY_CABLE, "Cable (electrical or optical)"},
        {11521, "System (logical)"},
    };

    const std::map<uint16_t, std::string> stateSet = {
        {PLDM_STATE_SET_HEALTH_STATE, "Health State"},
        {PLDM_STATE_SET_AVAILABILITY, "Availability"},
        {PLDM_STATE_SET_OPERATIONAL_STATUS, "Operational Status"},
        {PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
         "Operational Running Status"},
        {PLDM_STATE_SET_PRESENCE, "Presence"},
        {PLDM_STATE_SET_CONFIGURATION_STATE, "Configuration State"},
        {PLDM_STATE_SET_LINK_STATE, "Link State"},
        {PLDM_STATE_SET_SW_TERMINATION_STATUS, "Software Termination Status"},
        {PLDM_STATE_SET_BOOT_RESTART_CAUSE, "Boot/Restart Cause"},
        {PLDM_STATE_SET_BOOT_PROGRESS, "Boot Progress"},
        {PLDM_STATE_SET_SYSTEM_POWER_STATE, "System Power State"},
    };

    const std::array<std::string_view, 4> sensorInit = {
        "noInit", "useInitPDR", "enableSensor", "disableSensor"};

    const std::array<std::string_view, 4> effecterInit = {
        "noInit", "useInitPDR", "enableEffecter", "disableEffecter"};

    const std::map<uint8_t, std::string> pdrType = {
        {PLDM_TERMINUS_LOCATOR_PDR, "Terminus Locator PDR"},
        {PLDM_NUMERIC_SENSOR_PDR, "Numeric Sensor PDR"},
        {PLDM_NUMERIC_SENSOR_INITIALIZATION_PDR,
         "Numeric Sensor Initialization PDR"},
        {PLDM_STATE_SENSOR_PDR, "State Sensor PDR"},
        {PLDM_STATE_SENSOR_INITIALIZATION_PDR,
         "State Sensor Initialization PDR"},
        {PLDM_SENSOR_AUXILIARY_NAMES_PDR, "Sensor Auxiliary Names PDR"},
        {PLDM_OEM_UNIT_PDR, "OEM Unit PDR"},
        {PLDM_OEM_STATE_SET_PDR, "OEM State Set PDR"},
        {PLDM_NUMERIC_EFFECTER_PDR, "Numeric Effecter PDR"},
        {PLDM_NUMERIC_EFFECTER_INITIALIZATION_PDR,
         "Numeric Effecter Initialization PDR"},
        {PLDM_STATE_EFFECTER_PDR, "State Effecter PDR"},
        {PLDM_STATE_EFFECTER_INITIALIZATION_PDR,
         "State Effecter Initialization PDR"},
        {PLDM_EFFECTER_AUXILIARY_NAMES_PDR, "Effecter Auxiliary Names PDR"},
        {PLDM_EFFECTER_OEM_SEMANTIC_PDR, "Effecter OEM Semantic PDR"},
        {PLDM_PDR_ENTITY_ASSOCIATION, "Entity Association PDR"},
        {PLDM_ENTITY_AUXILIARY_NAMES_PDR, "Entity Auxiliary Names PDR"},
        {PLDM_OEM_ENTITY_ID_PDR, "OEM Entity ID PDR"},
        {PLDM_INTERRUPT_ASSOCIATION_PDR, "Interrupt Association PDR"},
        {PLDM_EVENT_LOG_PDR, "PLDM Event Log PDR"},
        {PLDM_PDR_FRU_RECORD_SET, "FRU Record Set PDR"},
        {PLDM_OEM_DEVICE_PDR, "OEM Device PDR"},
        {PLDM_OEM_PDR, "OEM PDR"},
    };

    std::string getEntityName(pldm::pdr::EntityType type)
    {
        try
        {
            return entityType.at(type);
        }
        catch (const std::out_of_range& e)
        {
            return std::to_string(static_cast<unsigned>(type)) + "(OEM)";
        }
    }

    std::string getStateSetName(uint16_t id)
    {
        auto typeString = std::to_string(id);
        try
        {
            return stateSet.at(id) + "(" + typeString + ")";
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }

    std::string getPDRType(uint8_t type)
    {
        auto typeString = std::to_string(type);
        try
        {
            return pdrType.at(type);
        }
        catch (const std::out_of_range& e)
        {
            return typeString;
        }
    }

    void printCommonPDRHeader(const pldm_pdr_hdr* hdr, ordered_json& output)
    {
        output["recordHandle"] = hdr->record_handle;
        output["PDRHeaderVersion"] = unsigned(hdr->version);
        output["PDRType"] = getPDRType(hdr->type);
        output["recordChangeNumber"] = hdr->record_change_num;
        output["dataLength"] = hdr->length;
    }

    std::string printPossibleStates(uint8_t possibleStatesSize,
                                    const bitfield8_t* states)
    {
        uint8_t possibleStatesPos{};
        std::string data;
        auto printStates = [&possibleStatesPos, &data](const bitfield8_t& val) {
            std::stringstream pstates;
            for (int i = 0; i < CHAR_BIT; i++)
            {
                if (val.byte & (1 << i))
                {
                    pstates << " " << (possibleStatesPos * CHAR_BIT + i);
                    data.append(pstates.str());
                    pstates.str("");
                }
            }
            possibleStatesPos++;
        };
        std::for_each(states, states + possibleStatesSize, printStates);
        return data;
    }

    void printStateSensorPDR(const uint8_t* data, ordered_json& output)
    {
        auto pdr = reinterpret_cast<const pldm_state_sensor_pdr*>(data);
        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["sensorID"] = pdr->sensor_id;
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = pdr->entity_instance;
        output["containerID"] = pdr->container_id;
        output["sensorInit"] = sensorInit[pdr->sensor_init];
        output["sensorAuxiliaryNamesPDR"] =
            (pdr->sensor_auxiliary_names_pdr ? true : false);
        output["compositeSensorCount"] = unsigned(pdr->composite_sensor_count);

        auto statesPtr = pdr->possible_states;
        auto compCount = pdr->composite_sensor_count;

        while (compCount--)
        {
            auto state = reinterpret_cast<const state_sensor_possible_states*>(
                statesPtr);
            output.emplace(("stateSetID[" + std::to_string(compCount) + "]"),
                           getStateSetName(state->state_set_id));
            output.emplace(
                ("possibleStatesSize[" + std::to_string(compCount) + "]"),
                state->possible_states_size);
            output.emplace(
                ("possibleStates[" + std::to_string(compCount) + "]"),
                printPossibleStates(state->possible_states_size,
                                    state->states));

            if (compCount)
            {
                statesPtr += sizeof(state_sensor_possible_states) +
                             state->possible_states_size - 1;
            }
        }
    }

    void printPDRFruRecordSet(uint8_t* data, ordered_json& output)
    {
        if (data == NULL)
        {
            return;
        }

        data += sizeof(pldm_pdr_hdr);
        pldm_pdr_fru_record_set* pdr =
            reinterpret_cast<pldm_pdr_fru_record_set*>(data);
        if (!pdr)
        {
            std::cerr << "Failed to get the FRU record set PDR" << std::endl;
            return;
        }

        output["PLDMTerminusHandle"] = unsigned(pdr->terminus_handle);
        output["FRURecordSetIdentifier"] = unsigned(pdr->fru_rsi);
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = unsigned(pdr->entity_instance_num);
        output["containerID"] = unsigned(pdr->container_id);
    }

    void printPDREntityAssociation(uint8_t* data, ordered_json& output)
    {
        const std::map<uint8_t, const char*> assocationType = {
            {PLDM_ENTITY_ASSOCIAION_PHYSICAL, "Physical"},
            {PLDM_ENTITY_ASSOCIAION_LOGICAL, "Logical"},
        };

        if (data == NULL)
        {
            return;
        }

        data += sizeof(pldm_pdr_hdr);
        pldm_pdr_entity_association* pdr =
            reinterpret_cast<pldm_pdr_entity_association*>(data);
        if (!pdr)
        {
            std::cerr << "Failed to get the PDR eneity association"
                      << std::endl;
            return;
        }

        output["containerID"] = int(pdr->container_id);
        if (assocationType.contains(pdr->association_type))
        {
            output["associationType"] =
                assocationType.at(pdr->association_type);
        }
        else
        {
            std::cout << "Get associationType failed.\n";
        }
        output["containerEntityType"] =
            getEntityName(pdr->container.entity_type);
        output["containerEntityInstanceNumber"] =
            int(pdr->container.entity_instance_num);
        output["containerEntityContainerID"] =
            int(pdr->container.entity_container_id);
        output["containedEntityCount"] =
            static_cast<unsigned>(pdr->num_children);

        auto child = reinterpret_cast<pldm_entity*>(&pdr->children[0]);
        for (int i = 0; i < pdr->num_children; ++i)
        {
            output.emplace("containedEntityType[" + std::to_string(i + 1) + "]",
                           getEntityName(child->entity_type));
            output.emplace("containedEntityInstanceNumber[" +
                               std::to_string(i + 1) + "]",
                           unsigned(child->entity_instance_num));
            output.emplace("containedEntityContainerID[" +
                               std::to_string(i + 1) + "]",
                           unsigned(child->entity_container_id));

            ++child;
        }
    }

    void printNumericEffecterPDR(uint8_t* data, ordered_json& output)
    {
        struct pldm_numeric_effecter_value_pdr* pdr =
            (struct pldm_numeric_effecter_value_pdr*)data;
        if (!pdr)
        {
            std::cerr << "Failed to get numeric effecter PDR" << std::endl;
            return;
        }

        output["PLDMTerminusHandle"] = int(pdr->terminus_handle);
        output["effecterID"] = int(pdr->effecter_id);
        output["entityType"] = int(pdr->entity_type);
        output["entityInstanceNumber"] = int(pdr->entity_instance);
        output["containerID"] = int(pdr->container_id);
        output["effecterSemanticID"] = int(pdr->effecter_semantic_id);
        output["effecterInit"] = unsigned(pdr->effecter_init);
        output["effecterAuxiliaryNames"] =
            (unsigned(pdr->effecter_auxiliary_names) ? true : false);
        output["baseUnit"] = unsigned(pdr->base_unit);
        output["unitModifier"] = unsigned(pdr->unit_modifier);
        output["rateUnit"] = unsigned(pdr->rate_unit);
        output["baseOEMUnitHandle"] = unsigned(pdr->base_oem_unit_handle);
        output["auxUnit"] = unsigned(pdr->aux_unit);
        output["auxUnitModifier"] = unsigned(pdr->aux_unit_modifier);
        output["auxrateUnit"] = unsigned(pdr->aux_rate_unit);
        output["auxOEMUnitHandle"] = unsigned(pdr->aux_oem_unit_handle);
        output["isLinear"] = (unsigned(pdr->is_linear) ? true : false);
        output["effecterDataSize"] = unsigned(pdr->effecter_data_size);
        output["resolution"] = unsigned(pdr->resolution);
        output["offset"] = unsigned(pdr->offset);
        output["accuracy"] = unsigned(pdr->accuracy);
        output["plusTolerance"] = unsigned(pdr->plus_tolerance);
        output["minusTolerance"] = unsigned(pdr->minus_tolerance);
        output["stateTransitionInterval"] =
            unsigned(pdr->state_transition_interval);
        output["TransitionInterval"] = unsigned(pdr->transition_interval);

        switch (pdr->effecter_data_size)
        {
            case PLDM_EFFECTER_DATA_SIZE_UINT8:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_u8);
                output["minSettable"] = unsigned(pdr->min_set_table.value_u8);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT8:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_s8);
                output["minSettable"] = unsigned(pdr->min_set_table.value_s8);
                break;
            case PLDM_EFFECTER_DATA_SIZE_UINT16:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_u16);
                output["minSettable"] = unsigned(pdr->min_set_table.value_u16);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT16:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_s16);
                output["minSettable"] = unsigned(pdr->min_set_table.value_s16);
                break;
            case PLDM_EFFECTER_DATA_SIZE_UINT32:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_u32);
                output["minSettable"] = unsigned(pdr->min_set_table.value_u32);
                break;
            case PLDM_EFFECTER_DATA_SIZE_SINT32:
                output["maxSettable"] = unsigned(pdr->max_set_table.value_s32);
                output["minSettable"] = unsigned(pdr->min_set_table.value_s32);
                break;
            default:
                break;
        }

        output["rangeFieldFormat"] = unsigned(pdr->range_field_format);
        output["rangeFieldSupport"] = unsigned(pdr->range_field_support.byte);

        switch (pdr->range_field_format)
        {
            case PLDM_RANGE_FIELD_FORMAT_UINT8:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u8);
                output["normalMax"] = unsigned(pdr->normal_max.value_u8);
                output["normalMin"] = unsigned(pdr->normal_min.value_u8);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u8);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u8);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT8:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s8);
                output["normalMax"] = unsigned(pdr->normal_max.value_s8);
                output["normalMin"] = unsigned(pdr->normal_min.value_s8);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s8);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s8);
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT16:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u16);
                output["normalMax"] = unsigned(pdr->normal_max.value_u16);
                output["normalMin"] = unsigned(pdr->normal_min.value_u16);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u16);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u16);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT16:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s16);
                output["normalMax"] = unsigned(pdr->normal_max.value_s16);
                output["normalMin"] = unsigned(pdr->normal_min.value_s16);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s16);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s16);
                break;
            case PLDM_RANGE_FIELD_FORMAT_UINT32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_u32);
                output["normalMax"] = unsigned(pdr->normal_max.value_u32);
                output["normalMin"] = unsigned(pdr->normal_min.value_u32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_u32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_u32);
                break;
            case PLDM_RANGE_FIELD_FORMAT_SINT32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_s32);
                output["normalMax"] = unsigned(pdr->normal_max.value_s32);
                output["normalMin"] = unsigned(pdr->normal_min.value_s32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_s32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_s32);
                break;
            case PLDM_RANGE_FIELD_FORMAT_REAL32:
                output["nominalValue"] = unsigned(pdr->nominal_value.value_f32);
                output["normalMax"] = unsigned(pdr->normal_max.value_f32);
                output["normalMin"] = unsigned(pdr->normal_min.value_f32);
                output["ratedMax"] = unsigned(pdr->rated_max.value_f32);
                output["ratedMin"] = unsigned(pdr->rated_min.value_f32);
                break;
            default:
                break;
        }
    }

    void printStateEffecterPDR(const uint8_t* data, ordered_json& output)
    {
        auto pdr = reinterpret_cast<const pldm_state_effecter_pdr*>(data);

        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["effecterID"] = pdr->effecter_id;
        output["entityType"] = getEntityName(pdr->entity_type);
        output["entityInstanceNumber"] = pdr->entity_instance;
        output["containerID"] = pdr->container_id;
        output["effecterSemanticID"] = pdr->effecter_semantic_id;
        output["effecterInit"] = effecterInit[pdr->effecter_init];
        output["effecterDescriptionPDR"] =
            (pdr->has_description_pdr ? true : false);
        output["compositeEffecterCount"] =
            unsigned(pdr->composite_effecter_count);

        auto statesPtr = pdr->possible_states;
        auto compEffCount = pdr->composite_effecter_count;

        while (compEffCount--)
        {
            auto state =
                reinterpret_cast<const state_effecter_possible_states*>(
                    statesPtr);
            output.emplace(("stateSetID[" + std::to_string(compEffCount) + "]"),
                           getStateSetName(state->state_set_id));
            output.emplace(
                ("possibleStatesSize[" + std::to_string(compEffCount) + "]"),
                state->possible_states_size);
            output.emplace(
                ("possibleStates[" + std::to_string(compEffCount) + "]"),
                printPossibleStates(state->possible_states_size,
                                    state->states));

            if (compEffCount)
            {
                statesPtr += sizeof(state_effecter_possible_states) +
                             state->possible_states_size - 1;
            }
        }
    }

    void printTerminusLocatorPDR(const uint8_t* data, ordered_json& output)
    {
        const std::array<std::string_view, 4> terminusLocatorType = {
            "UID", "MCTP_EID", "SMBusRelative", "systemSoftware"};

        auto pdr = reinterpret_cast<const pldm_terminus_locator_pdr*>(data);

        output["PLDMTerminusHandle"] = pdr->terminus_handle;
        output["validity"] = (pdr->validity ? "valid" : "notValid");
        output["TID"] = unsigned(pdr->tid);
        output["containerID"] = pdr->container_id;
        output["terminusLocatorType"] =
            terminusLocatorType[pdr->terminus_locator_type];
        output["terminusLocatorValueSize"] =
            unsigned(pdr->terminus_locator_value_size);

        if (pdr->terminus_locator_type == PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID)
        {
            auto locatorValue =
                reinterpret_cast<const pldm_terminus_locator_type_mctp_eid*>(
                    pdr->terminus_locator_value);
            output["EID"] = unsigned(locatorValue->eid);
        }
    }

    void printPDRMsg(const uint32_t nextRecordHndl, const uint16_t respCnt,
                     uint8_t* data)
    {
        if (data == NULL)
        {
            std::cerr << "Failed to get PDR message" << std::endl;
            return;
        }

        ordered_json output;
        output["nextRecordHandle"] = nextRecordHndl;
        output["responseCount"] = respCnt;

        struct pldm_pdr_hdr* pdr = (struct pldm_pdr_hdr*)data;
        if (!pdr)
        {
            return;
        }
        printCommonPDRHeader(pdr, output);

        switch (pdr->type)
        {
            case PLDM_TERMINUS_LOCATOR_PDR:
                printTerminusLocatorPDR(data, output);
                break;
            case PLDM_STATE_SENSOR_PDR:
                printStateSensorPDR(data, output);
                break;
            case PLDM_NUMERIC_EFFECTER_PDR:
                printNumericEffecterPDR(data, output);
                break;
            case PLDM_STATE_EFFECTER_PDR:
                printStateEffecterPDR(data, output);
                break;
            case PLDM_PDR_ENTITY_ASSOCIATION:
                printPDREntityAssociation(data, output);
                break;
            case PLDM_PDR_FRU_RECORD_SET:
                printPDRFruRecordSet(data, output);
                break;
            default:
                break;
        }
        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint32_t recordHandle;
};

class SetStateEffecter : public CommandInterface
{
  public:
    ~SetStateEffecter() = default;
    SetStateEffecter() = delete;
    SetStateEffecter(const SetStateEffecter&) = delete;
    SetStateEffecter(SetStateEffecter&&) = default;
    SetStateEffecter& operator=(const SetStateEffecter&) = delete;
    SetStateEffecter& operator=(SetStateEffecter&&) = default;

    // compositeEffecterCount(value: 0x01 to 0x08) * stateField(2)
    static constexpr auto maxEffecterDataSize = 16;

    // compositeEffecterCount(value: 0x01 to 0x08)
    static constexpr auto minEffecterCount = 1;
    static constexpr auto maxEffecterCount = 8;
    explicit SetStateEffecter(const char* type, const char* name,
                              CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --id", effecterId,
               "A handle that is used to identify and access the effecter")
            ->required();
        app->add_option("-c, --count", effecterCount,
                        "The number of individual sets of effecter information")
            ->required();
        app->add_option(
               "-d,--data", effecterData,
               "Set effecter state data\n"
               "eg: requestSet0 effecterState0 noChange1 dummyState1 ...")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        if (effecterCount > maxEffecterCount ||
            effecterCount < minEffecterCount)
        {
            std::cerr << "Request Message Error: effecterCount size "
                      << effecterCount << "is invalid\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        if (effecterData.size() > maxEffecterDataSize)
        {
            std::cerr << "Request Message Error: effecterData size "
                      << effecterData.size() << "is invalid\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        auto stateField = parseEffecterData(effecterData, effecterCount);
        if (!stateField)
        {
            std::cerr << "Failed to parse effecter data, effecterCount size "
                      << effecterCount << "\n";
            auto rc = PLDM_ERROR_INVALID_DATA;
            return {rc, requestMsg};
        }

        auto rc = encode_set_state_effecter_states_req(
            instanceId, effecterId, effecterCount, stateField->data(), request);
        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        auto rc = decode_set_state_effecter_states_resp(
            responsePtr, payloadLength, &completionCode);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode << "\n";
            return;
        }

        ordered_json data;
        data["Response"] = "SUCCESS";
        pldmtool::helper::DisplayInJson(data);
    }

  private:
    uint16_t effecterId;
    uint8_t effecterCount;
    std::vector<uint8_t> effecterData;
};

class SetNumericEffecterValue : public CommandInterface
{
  public:
    ~SetNumericEffecterValue() = default;
    SetNumericEffecterValue() = delete;
    SetNumericEffecterValue(const SetNumericEffecterValue&) = delete;
    SetNumericEffecterValue(SetNumericEffecterValue&&) = default;
    SetNumericEffecterValue& operator=(const SetNumericEffecterValue&) = delete;
    SetNumericEffecterValue& operator=(SetNumericEffecterValue&&) = default;

    explicit SetNumericEffecterValue(const char* type, const char* name,
                                     CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --id", effecterId,
               "A handle that is used to identify and access the effecter")
            ->required();
        app->add_option("-s, --size", effecterDataSize,
                        "The bit width and format of the setting value for the "
                        "effecter. enum value: {uint8, sint8, uint16, sint16, "
                        "uint32, sint32}\n")
            ->required();
        app->add_option("-d,--data", maxEffecterValue,
                        "The setting value of numeric effecter being "
                        "requested\n")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) +
            PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 3);

        uint8_t* effecterValue = (uint8_t*)&maxEffecterValue;

        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
        size_t payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES;

        if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT16 ||
            effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT16)
        {
            payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 1;
        }
        if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT32 ||
            effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT32)
        {
            payload_length = PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES + 3;
        }
        auto rc = encode_set_numeric_effecter_value_req(
            0, effecterId, effecterDataSize, effecterValue, request,
            payload_length);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        auto rc = decode_set_numeric_effecter_value_resp(
            responsePtr, payloadLength, &completionCode);

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }

        ordered_json data;
        data["Response"] = "SUCCESS";
        pldmtool::helper::DisplayInJson(data);
    }

  private:
    uint16_t effecterId;
    uint8_t effecterDataSize;
    uint64_t maxEffecterValue;
};

class GetStateSensorReadings : public CommandInterface
{
  public:
    ~GetStateSensorReadings() = default;
    GetStateSensorReadings() = delete;
    GetStateSensorReadings(const GetStateSensorReadings&) = delete;
    GetStateSensorReadings(GetStateSensorReadings&&) = default;
    GetStateSensorReadings& operator=(const GetStateSensorReadings&) = delete;
    GetStateSensorReadings& operator=(GetStateSensorReadings&&) = default;

    explicit GetStateSensorReadings(const char* type, const char* name,
                                    CLI::App* app) :
        CommandInterface(type, name, app)
    {
        app->add_option(
               "-i, --sensor_id", sensorId,
               "Sensor ID that is used to identify and access the sensor")
            ->required();
        app->add_option("-r, --rearm", sensorRearm,
                        "Each bit location in this field corresponds to a "
                        "particular sensor")
            ->required();
    }

    std::pair<int, std::vector<uint8_t>> createRequestMsg() override
    {
        std::vector<uint8_t> requestMsg(
            sizeof(pldm_msg_hdr) + PLDM_GET_STATE_SENSOR_READINGS_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

        uint8_t reserved = 0;
        bitfield8_t bf;
        bf.byte = sensorRearm;
        auto rc = encode_get_state_sensor_readings_req(instanceId, sensorId, bf,
                                                       reserved, request);

        return {rc, requestMsg};
    }

    void parseResponseMsg(pldm_msg* responsePtr, size_t payloadLength) override
    {
        uint8_t completionCode = 0;
        uint8_t compSensorCount = 0;
        std::array<get_sensor_state_field, 8> stateField{};
        auto rc = decode_get_state_sensor_readings_resp(
            responsePtr, payloadLength, &completionCode, &compSensorCount,
            stateField.data());

        if (rc != PLDM_SUCCESS || completionCode != PLDM_SUCCESS)
        {
            std::cerr << "Response Message Error: "
                      << "rc=" << rc << ",cc=" << (int)completionCode
                      << std::endl;
            return;
        }
        ordered_json output;
        output["compositeSensorCount"] = (int)compSensorCount;

        for (size_t i = 0; i < compSensorCount; i++)
        {
            if (sensorOpState.contains(stateField[i].sensor_op_state))
            {
                output.emplace(("sensorOpState[" + std::to_string(i) + "]"),
                               sensorOpState.at(stateField[i].sensor_op_state));
            }

            if (sensorPresState.contains(stateField[i].present_state))
            {
                output.emplace(("presentState[" + std::to_string(i) + "]"),
                               sensorPresState.at(stateField[i].present_state));
            }

            if (sensorPresState.contains(stateField[i].previous_state))
            {
                output.emplace(
                    ("previousState[" + std::to_string(i) + "]"),
                    sensorPresState.at(stateField[i].previous_state));
            }

            if (sensorPresState.contains(stateField[i].event_state))
            {
                output.emplace(("eventState[" + std::to_string(i) + "]"),
                               sensorPresState.at(stateField[i].event_state));
            }
        }

        pldmtool::helper::DisplayInJson(output);
    }

  private:
    uint16_t sensorId;
    uint8_t sensorRearm;
};

void registerCommand(CLI::App& app)
{
    auto platform = app.add_subcommand("platform", "platform type command");
    platform->require_subcommand(1);

    auto getPDR =
        platform->add_subcommand("GetPDR", "get platform descriptor records");
    commands.push_back(std::make_unique<GetPDR>("platform", "getPDR", getPDR));

    auto setStateEffecterStates = platform->add_subcommand(
        "SetStateEffecterStates", "set effecter states");
    commands.push_back(std::make_unique<SetStateEffecter>(
        "platform", "setStateEffecterStates", setStateEffecterStates));

    auto setNumericEffecterValue = platform->add_subcommand(
        "SetNumericEffecterValue", "set the value for a PLDM Numeric Effecter");
    commands.push_back(std::make_unique<SetNumericEffecterValue>(
        "platform", "setNumericEffecterValue", setNumericEffecterValue));

    auto getStateSensorReadings = platform->add_subcommand(
        "GetStateSensorReadings", "get the state sensor readings");
    commands.push_back(std::make_unique<GetStateSensorReadings>(
        "platform", "getStateSensorReadings", getStateSensorReadings));
}

} // namespace platform
} // namespace pldmtool
