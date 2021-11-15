#include "inventory_manager.hpp"

#include "libpldm/firmware_update.h"

#include "common/utils.hpp"
#include "xyz/openbmc_project/Software/Version/server.hpp"

#include <functional>

namespace pldm
{

namespace fw_update
{

void InventoryManager::discoverFDs(const std::vector<mctp_eid_t>& eids)
{
    for (const auto& eid : eids)
    {
        auto instanceId = requester.getInstanceId(eid);
        Request requestMsg(sizeof(pldm_msg_hdr) +
                           PLDM_QUERY_DEVICE_IDENTIFIERS_REQ_BYTES);
        auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
        auto rc = encode_query_device_identifiers_req(
            instanceId, PLDM_QUERY_DEVICE_IDENTIFIERS_REQ_BYTES, request);
        if (rc)
        {
            requester.markFree(eid, instanceId);
            std::cerr << "encode_query_device_identifiers_req failed, EID="
                      << unsigned(eid) << ", RC=" << rc << "\n";
            continue;
        }

        rc = handler.registerRequest(
            eid, instanceId, PLDM_FWUP, PLDM_QUERY_DEVICE_IDENTIFIERS,
            std::move(requestMsg),
            std::move(std::bind_front(&InventoryManager::queryDeviceIdentifiers,
                                      this)));
        if (rc)
        {
            std::cerr << "Failed to send QueryDeviceIdentifiers request, EID="
                      << unsigned(eid) << ", RC=" << rc << "\n ";
        }
    }
}

void InventoryManager::queryDeviceIdentifiers(mctp_eid_t eid,
                                              const pldm_msg* response,
                                              size_t respMsgLen)
{
    if (response == nullptr || !respMsgLen)
    {
        std::cerr << "No response received for QueryDeviceIdentifiers, EID="
                  << unsigned(eid) << "\n";
        return;
    }

    uint8_t completionCode = PLDM_SUCCESS;
    uint32_t deviceIdentifiersLen = 0;
    uint8_t descriptorCount = 0;
    uint8_t* descriptorPtr = nullptr;

    auto rc = decode_query_device_identifiers_resp(
        response, respMsgLen, &completionCode, &deviceIdentifiersLen,
        &descriptorCount, &descriptorPtr);
    if (rc)
    {
        std::cerr << "Decoding QueryDeviceIdentifiers response failed, EID="
                  << unsigned(eid) << ", RC=" << rc << "\n";
        return;
    }

    if (completionCode)
    {
        std::cerr << "QueryDeviceIdentifiers response failed with error "
                     "completion code, EID="
                  << unsigned(eid) << ", CC=" << unsigned(completionCode)
                  << "\n";
        return;
    }

    Descriptors descriptors{};
    while (descriptorCount-- && (deviceIdentifiersLen > 0))
    {
        uint16_t descriptorType = 0;
        variable_field descriptorData{};

        rc = decode_descriptor_type_length_value(
            descriptorPtr, deviceIdentifiersLen, &descriptorType,
            &descriptorData);
        if (rc)
        {
            std::cerr
                << "Decoding descriptor type, length and value failed, EID="
                << unsigned(eid) << ", RC=" << rc << "\n ";
            return;
        }

        if (descriptorType != PLDM_FWUP_VENDOR_DEFINED)
        {
            std::vector<uint8_t> descData(
                descriptorData.ptr, descriptorData.ptr + descriptorData.length);
            descriptors.emplace(descriptorType, std::move(descData));
        }
        else
        {
            uint8_t descriptorTitleStrType = 0;
            variable_field descriptorTitleStr{};
            variable_field vendorDefinedDescriptorData{};

            rc = decode_vendor_defined_descriptor_value(
                descriptorData.ptr, descriptorData.length,
                &descriptorTitleStrType, &descriptorTitleStr,
                &vendorDefinedDescriptorData);
            if (rc)
            {
                std::cerr
                    << "Decoding Vendor-defined descriptor value failed, EID="
                    << unsigned(eid) << ", RC=" << rc << "\n ";
                return;
            }

            auto vendorDefinedDescriptorTitleStr =
                utils::toString(descriptorTitleStr);
            std::vector<uint8_t> vendorDescData(
                vendorDefinedDescriptorData.ptr,
                vendorDefinedDescriptorData.ptr +
                    vendorDefinedDescriptorData.length);
            descriptors.emplace(descriptorType,
                                std::make_tuple(vendorDefinedDescriptorTitleStr,
                                                vendorDescData));
        }
        auto nextDescriptorOffset =
            sizeof(pldm_descriptor_tlv().descriptor_type) +
            sizeof(pldm_descriptor_tlv().descriptor_length) +
            descriptorData.length;
        descriptorPtr += nextDescriptorOffset;
        deviceIdentifiersLen -= nextDescriptorOffset;
    }

    descriptorMap.emplace(eid, std::move(descriptors));

    // Send GetFirmwareParameters request
    sendGetFirmwareParametersRequest(eid);
}

void InventoryManager::sendGetFirmwareParametersRequest(mctp_eid_t eid)
{
    auto instanceId = requester.getInstanceId(eid);
    Request requestMsg(sizeof(pldm_msg_hdr) +
                       PLDM_GET_FIRMWARE_PARAMETERS_REQ_BYTES);
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());
    auto rc = encode_get_firmware_parameters_req(
        instanceId, PLDM_GET_FIRMWARE_PARAMETERS_REQ_BYTES, request);
    if (rc)
    {
        requester.markFree(eid, instanceId);
        std::cerr << "encode_get_firmware_parameters_req failed, EID="
                  << unsigned(eid) << ", RC=" << rc << "\n";
        return;
    }

    rc = handler.registerRequest(
        eid, instanceId, PLDM_FWUP, PLDM_GET_FIRMWARE_PARAMETERS,
        std::move(requestMsg),
        std::move(
            std::bind_front(&InventoryManager::getFirmwareParameters, this)));
    if (rc)
    {
        std::cerr << "Failed to send GetFirmwareParameters request, EID="
                  << unsigned(eid) << ", RC=" << rc << "\n ";
    }
}

void InventoryManager::getFirmwareParameters(mctp_eid_t eid,
                                             const pldm_msg* response,
                                             size_t respMsgLen)
{
    if (response == nullptr || !respMsgLen)
    {
        std::cerr << "No response received for GetFirmwareParameters, EID="
                  << unsigned(eid) << "\n";
        descriptorMap.erase(eid);
        return;
    }

    pldm_get_firmware_parameters_resp fwParams{};
    variable_field activeCompImageSetVerStr{};
    variable_field pendingCompImageSetVerStr{};
    variable_field compParamTable{};

    auto rc = decode_get_firmware_parameters_resp(
        response, respMsgLen, &fwParams, &activeCompImageSetVerStr,
        &pendingCompImageSetVerStr, &compParamTable);
    if (rc)
    {
        std::cerr << "Decoding GetFirmwareParameters response failed, EID="
                  << unsigned(eid) << ", RC=" << rc << "\n";
        return;
    }

    if (fwParams.completion_code)
    {
        std::cerr << "GetFirmwareParameters response failed with error "
                     "completion code, EID="
                  << unsigned(eid)
                  << ", CC=" << unsigned(fwParams.completion_code) << "\n";
        return;
    }

    auto compParamPtr = compParamTable.ptr;
    auto compParamTableLen = compParamTable.length;
    pldm_component_parameter_entry compEntry{};
    variable_field activeCompVerStr{};
    variable_field pendingCompVerStr{};

    ComponentInfo componentInfo{};
    while (fwParams.comp_count-- && (compParamTableLen > 0))
    {
        auto rc = decode_get_firmware_parameters_resp_comp_entry(
            compParamPtr, compParamTableLen, &compEntry, &activeCompVerStr,
            &pendingCompVerStr);
        if (rc)
        {
            std::cerr << "Decoding component parameter table entry failed, EID="
                      << unsigned(eid) << ", RC=" << rc << "\n";
            return;
        }

        auto compClassification = compEntry.comp_classification;
        auto compIdentifier = compEntry.comp_identifier;
        componentInfo.emplace(
            std::make_pair(compClassification, compIdentifier),
            compEntry.comp_classification_index);
        compParamPtr += sizeof(pldm_component_parameter_entry) +
                        activeCompVerStr.length + pendingCompVerStr.length;
        compParamTableLen -= sizeof(pldm_component_parameter_entry) +
                             activeCompVerStr.length + pendingCompVerStr.length;
    }
    componentInfoMap.emplace(eid, std::move(componentInfo));
}

} // namespace fw_update

} // namespace pldm