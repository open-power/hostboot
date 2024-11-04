#include "collect_slot_vpd.hpp"

#include "oem_ibm_handler.hpp"

#include <phosphor-logging/lg2.hpp>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace responder
{
using namespace oem_ibm_platform;
void SlotHandler::timeOutHandler()
{
    info(
        "Timer expired waiting for Event from Inventory on following pldm_entity: [ {ENTITY_TYP}, {ENTITY_NUM}, {ENTITY_ID} ]",
        "ENTITY_TYP",
        static_cast<unsigned>(currentOnGoingSlotEntity.entity_type),
        "ENTITY_NUM",
        static_cast<unsigned>(currentOnGoingSlotEntity.entity_instance_num),
        "ENTITY_ID",
        static_cast<unsigned>(currentOnGoingSlotEntity.entity_container_id));
    // Disable the timer
    timer.setEnabled(false);

    // obtain the sensor Id
    auto sensorId = pldm::utils::findStateSensorId(
        pdrRepo, 0, PLDM_ENTITY_SLOT,
        currentOnGoingSlotEntity.entity_instance_num,
        currentOnGoingSlotEntity.entity_container_id,
        PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE);

    // send the sensor event to host with error state
    sendStateSensorEvent(sensorId, PLDM_STATE_SENSOR_STATE, 0,
                         PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_ERROR,
                         PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN);
}

void SlotHandler::enableSlot(uint16_t effecterId,
                             const AssociatedEntityMap& fruAssociationMap,
                             uint8_t stateFileValue)

{
    info("CM: slot enable effecter id: {EFFECTER_ID}", "EFFECTER_ID",
         effecterId);
    const pldm_entity entity = getEntityIDfromEffecterID(effecterId);

    for (const auto& [key, value] : fruAssociationMap)
    {
        if (entity.entity_instance_num == value.entity_instance_num &&
            entity.entity_type == value.entity_type &&
            entity.entity_container_id == value.entity_container_id)
        {
            this->currentOnGoingSlotEntity.entity_type = value.entity_type;
            this->currentOnGoingSlotEntity.entity_instance_num =
                value.entity_instance_num;
            this->currentOnGoingSlotEntity.entity_container_id =
                value.entity_container_id;
            processSlotOperations(key, value, stateFileValue);
        }
    }
}

void SlotHandler::processSlotOperations(const std::string& slotObjectPath,
                                        const pldm_entity& entity,
                                        uint8_t stateFieldValue)
{
    info("CM: processing the slot operations, SlotObject: {SLOT_OBJ}",
         "SLOT_OBJ", slotObjectPath);

    std::string adapterObjPath;
    try
    {
        // get the adapter dbus object path from the slot dbus object path
        adapterObjPath = getAdapterObjPath(slotObjectPath).value();
    }
    catch (const std::bad_optional_access& e)
    {
        error("Failed to get the adapter dbus object ERROR={ERROR}", "ERROR",
              e);
        return;
    }

    info(
        "CM: Found an adapter under the slot, adapter object:{ADAPTER_OBJ_PATH}",
        "ADAPTER_OBJ_PATH", adapterObjPath);
    // create a presence match for the adpter present property
    createPresenceMatch(adapterObjPath, entity, stateFieldValue);

    // call the VPD Manager to collect/remove VPD objects
    callVPDManager(adapterObjPath, stateFieldValue);

    // start the 1 min timer
    timer.restart(std::chrono::seconds(60));
}

void SlotHandler::callVPDManager(const std::string& adapterObjPath,
                                 uint8_t stateFieldValue)
{
    static constexpr auto VPDObjPath = "/com/ibm/VPD/Manager";
    static constexpr auto VPDInterface = "com.ibm.VPD.Manager";
    auto& bus = pldm::utils::DBusHandler::getBus();
    try
    {
        auto service =
            pldm::utils::DBusHandler().getService(VPDObjPath, VPDInterface);
        if (stateFieldValue == PLDM_OEM_IBM_PCIE_SLOT_EFFECTER_ADD)
        {
            auto method = bus.new_method_call(service.c_str(), VPDObjPath,
                                              VPDInterface, "CollectFRUVPD");
            method.append(
                static_cast<sdbusplus::message::object_path>(adapterObjPath));
            bus.call_noreply(method, dbusTimeout);
        }
        else if (stateFieldValue == PLDM_OEM_IBM_PCIE_SLOT_EFFECTER_REMOVE ||
                 stateFieldValue == PLDM_OEM_IBM_PCIE_SLOT_EFFECTER_REPLACE)
        {
            auto method = bus.new_method_call(service.c_str(), VPDObjPath,
                                              VPDInterface, "deleteFRUVPD");
            method.append(
                static_cast<sdbusplus::message::object_path>(adapterObjPath));
            bus.call_noreply(method, dbusTimeout);
        }
    }
    catch (const std::exception& e)
    {
        error(
            "failed to make a d-bus call to VPD Manager , Operation = {STATE_FILED_VAL}, ERROR={ERROR}",
            "STATE_FILED_VAL", (unsigned)stateFieldValue, "ERROR", e);
    }
}

std::optional<std::string>
    SlotHandler::getAdapterObjPath(const std::string& slotObjPath)
{
    static constexpr auto searchpath = "/xyz/openbmc_project/inventory";
    int depth = 0;
    std::vector<std::string> pcieAdapterInterface = {
        "xyz.openbmc_project.Inventory.Item.PCIeDevice"};
    pldm::utils::GetSubTreeResponse response =
        pldm::utils::DBusHandler().getSubtree(searchpath, depth,
                                              pcieAdapterInterface);
    for (const auto& [objPath, serviceMap] : response)
    {
        // An adapter is a child of a PCIe Slot Object
        if (objPath.contains(slotObjPath))
        {
            // Found the Adapter under the slot
            return objPath;
        }
    }
    return std::nullopt;
}

void SlotHandler::createPresenceMatch(const std::string& adapterObjectPath,
                                      const pldm_entity& entity,
                                      uint8_t stateFieldValue)
{
    fruPresenceMatch = std::make_unique<sdbusplus::bus::match_t>(
        pldm::utils::DBusHandler::getBus(),
        propertiesChanged(adapterObjectPath,
                          "xyz.openbmc_project.Inventory.Item"),
        [this, adapterObjectPath, stateFieldValue,
         entity](sdbusplus::message_t& msg) {
            pldm::utils::DbusChangedProps props{};
            std::string intf;
            msg.read(intf, props);
            const auto itr = props.find("Present");
            if (itr != props.end())
            {
                bool value = std::get<bool>(itr->second);
                // Present Property is found
                this->processPresentPropertyChange(value, stateFieldValue,
                                                   entity);
            }
        });
}

void SlotHandler::processPresentPropertyChange(
    bool presentValue, uint8_t stateFiledvalue, const pldm_entity& entity)
{
    // irrespective of true->false or false->true change, we should stop the
    // timer
    timer.setEnabled(false);

    // remove the prence match so that it does not monitor the change
    // even after we captured the property changed signal
    fruPresenceMatch = nullptr;

    // obtain the sensor id attached with this slot
    auto sensorId = pldm::utils::findStateSensorId(
        pdrRepo, 0, PLDM_ENTITY_SLOT, entity.entity_instance_num,
        entity.entity_container_id, PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE);

    uint8_t sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN;
    if (presentValue)
    {
        sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_ENABLED;
    }
    else
    {
        if (stateFiledvalue == PLDM_OEM_IBM_PCIE_SLOT_EFFECTER_REPLACE)
        {
            sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN;
        }
        else
        {
            sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_DISABLED;
        }
    }
    info(
        "CM: processing the property change from VPD Present value and sensor opState: {CURR_VAL} and {SENSOR_OP_STATE}",
        "CURR_VAL", presentValue, "SENSOR_OP_STATE", (unsigned)sensorOpState);
    // set the sensor state based on the stateFieldValue
    this->sendStateSensorEvent(sensorId, PLDM_STATE_SENSOR_STATE, 0,
                               sensorOpState,
                               PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN);
}

pldm_entity SlotHandler::getEntityIDfromEffecterID(uint16_t effecterId)
{
    pldm_entity parentFruEntity{};
    uint8_t* pdrData = nullptr;
    uint32_t pdrSize{};
    const pldm_pdr_record* record{};
    do
    {
        record = pldm_pdr_find_record_by_type(pdrRepo, PLDM_STATE_EFFECTER_PDR,
                                              record, &pdrData, &pdrSize);
        if (record && !pldm_pdr_record_is_remote(record))
        {
            auto pdr = reinterpret_cast<pldm_state_effecter_pdr*>(pdrData);
            auto compositeEffecterCount = pdr->composite_effecter_count;
            auto possible_states_start = pdr->possible_states;

            for (auto effecters = 0x00; effecters < compositeEffecterCount;
                 effecters++)
            {
                auto possibleStates =
                    reinterpret_cast<state_effecter_possible_states*>(
                        possible_states_start);

                if (possibleStates->state_set_id ==
                        PLDM_OEM_IBM_PCIE_SLOT_EFFECTER_STATE &&
                    effecterId == pdr->effecter_id)
                {
                    parentFruEntity.entity_type = pdr->entity_type;
                    parentFruEntity.entity_instance_num = pdr->entity_instance;
                    parentFruEntity.entity_container_id = pdr->container_id;

                    return parentFruEntity;
                }
            }
        }
    } while (record);

    return parentFruEntity;
}

uint8_t SlotHandler::fetchSlotSensorState(const std::string& slotObjectPath)
{
    std::string adapterObjPath;
    uint8_t sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN;

    try
    {
        // get the adapter dbus object path from the slot dbus object path
        adapterObjPath = getAdapterObjPath(slotObjectPath).value();
    }
    catch (const std::bad_optional_access& e)
    {
        error(
            "Failed to get the adapterObjectPath from slotObjectPath : {SLOT_OBJ_PATH} with error ERROR={ERROR}",
            "SLOT_OBJ_PATH", slotObjectPath, "ERROR", e);
        return PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_UNKOWN;
    }

    if (fetchSensorStateFromDbus(adapterObjPath))
    {
        sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_ENABLED;
    }
    else
    {
        sensorOpState = PLDM_OEM_IBM_PCIE_SLOT_SENSOR_STATE_DISABLED;
    }
    return sensorOpState;
}

void SlotHandler::setOemPlatformHandler(
    pldm::responder::oem_platform::Handler* handler)
{
    oemPlatformHandler = handler;
}

void SlotHandler::sendStateSensorEvent(
    uint16_t sensorId, enum sensor_event_class_states sensorEventClass,
    uint8_t sensorOffset, uint8_t eventState, uint8_t prevEventState)
{
    pldm::responder::oem_ibm_platform::Handler* oemIbmPlatformHandler =
        dynamic_cast<pldm::responder::oem_ibm_platform::Handler*>(
            oemPlatformHandler);
    if (oemIbmPlatformHandler)
    {
        oemIbmPlatformHandler->sendStateSensorEvent(
            sensorId, sensorEventClass, sensorOffset, eventState,
            prevEventState);
    }
}

bool SlotHandler::fetchSensorStateFromDbus(const std::string& adapterObjectPath)
{
    static constexpr auto ItemInterface = "xyz.openbmc_project.Inventory.Item";

    try
    {
        auto presentProperty =
            pldm::utils::DBusHandler().getDbusPropertyVariant(
                adapterObjectPath.c_str(), "Present", ItemInterface);
        return std::get<bool>(presentProperty);
    }
    catch (const std::exception& e)
    {
        error(
            "failed to make a d-bus call to Inventory manager from adapterObjectPath : {ADAPTER_OBJ_PATH} with error ERROR={ERROR}",
            "ADAPTER_OBJ_PATH", adapterObjectPath, "ERROR", e);
    }

    return false;
}

} // namespace responder
} // namespace pldm
