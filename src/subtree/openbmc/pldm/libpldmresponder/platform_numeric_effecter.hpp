#pragma once

#include "common/utils.hpp"
#include "libpldmresponder/pdr.hpp"
#include "pdr_utils.hpp"
#include "pldmd/handler.hpp"

#include <libpldm/platform.h>
#include <libpldm/states.h>

#include <phosphor-logging/lg2.hpp>

#include <cmath>
#include <cstdint>
#include <map>
#include <optional>

PHOSPHOR_LOG2_USING;

namespace pldm
{
namespace responder
{
namespace platform_numeric_effecter
{
/** @brief Function to get the effecter value by PDR factor coefficient, etc.
 *  @param[in] pdr - The structure of pldm_numeric_effecter_value_pdr.
 *  @param[in] effecterValue - effecter value.
 *  @param[in] propertyType - type of the D-Bus property.
 *
 *  @return - std::pair<int, std::optional<PropertyValue>> - rc:Success or
 *          failure, PropertyValue: The value to be set
 */
template <typename T>
std::pair<int, std::optional<pldm::utils::PropertyValue>>
    getEffecterRawValue(const pldm_numeric_effecter_value_pdr* pdr,
                        T& effecterValue, std::string propertyType)
{
    // X = Round [ (Y - B) / m ]
    // refer to DSP0248_1.2.0 27.8
    int rc = 0;
    pldm::utils::PropertyValue value;
    switch (pdr->effecter_data_size)
    {
        case PLDM_EFFECTER_DATA_SIZE_UINT8:
        {
            auto rawValue = static_cast<uint8_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_u8 < pdr->max_settable.value_u8 &&
                (rawValue < pdr->min_settable.value_u8 ||
                 rawValue > pdr->max_settable.value_u8))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            if (propertyType == "uint64_t")
            {
                auto tempValue = std::get<uint8_t>(value);
                value = static_cast<uint64_t>(tempValue);
            }
            else if (propertyType == "uint32_t")
            {
                auto tempValue = std::get<uint8_t>(value);
                value = static_cast<uint32_t>(tempValue);
            }
            break;
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT8:
        {
            auto rawValue = static_cast<int8_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_s8 < pdr->max_settable.value_s8 &&
                (rawValue < pdr->min_settable.value_s8 ||
                 rawValue > pdr->max_settable.value_s8))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            break;
        }
        case PLDM_EFFECTER_DATA_SIZE_UINT16:
        {
            auto rawValue = static_cast<uint16_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_u16 < pdr->max_settable.value_u16 &&
                (rawValue < pdr->min_settable.value_u16 ||
                 rawValue > pdr->max_settable.value_u16))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            if (propertyType == "uint64_t")
            {
                auto tempValue = std::get<uint16_t>(value);
                value = static_cast<uint64_t>(tempValue);
            }
            else if (propertyType == "uint32_t")
            {
                auto tempValue = std::get<uint16_t>(value);
                value = static_cast<uint32_t>(tempValue);
            }
            break;
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT16:
        {
            auto rawValue = static_cast<int16_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_s16 < pdr->max_settable.value_s16 &&
                (rawValue < pdr->min_settable.value_s16 ||
                 rawValue > pdr->max_settable.value_s16))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            if (propertyType == "uint64_t")
            {
                auto tempValue = std::get<int16_t>(value);
                value = static_cast<uint64_t>(tempValue);
            }
            else if (propertyType == "uint32_t")
            {
                auto tempValue = std::get<int16_t>(value);
                value = static_cast<uint32_t>(tempValue);
            }
            break;
        }
        case PLDM_EFFECTER_DATA_SIZE_UINT32:
        {
            auto rawValue = static_cast<uint32_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_u32 < pdr->max_settable.value_u32 &&
                (rawValue < pdr->min_settable.value_u32 ||
                 rawValue > pdr->max_settable.value_u32))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            if (propertyType == "uint64_t")
            {
                auto tempValue = std::get<uint32_t>(value);
                value = static_cast<uint64_t>(tempValue);
            }
            else if (propertyType == "uint32_t")
            {
                auto tempValue = std::get<uint32_t>(value);
                value = static_cast<uint32_t>(tempValue);
            }
            break;
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT32:
        {
            auto rawValue = static_cast<int32_t>(
                round(effecterValue - pdr->offset) / pdr->resolution);
            if (pdr->min_settable.value_s32 < pdr->max_settable.value_s32 &&
                (rawValue < pdr->min_settable.value_s32 ||
                 rawValue > pdr->max_settable.value_s32))
            {
                rc = PLDM_ERROR_INVALID_DATA;
            }
            value = rawValue;
            if (propertyType == "uint64_t")
            {
                auto tempValue = std::get<int32_t>(value);
                value = static_cast<uint64_t>(tempValue);
            }
            else if (propertyType == "uint32_t")
            {
                auto tempValue = std::get<int32_t>(value);
                value = static_cast<uint32_t>(tempValue);
            }
            break;
        }
    }

    return {rc, std::make_optional(std::move(value))};
}

/** @brief Function to convert the D-Bus value by PDR factor and effecter value.
 *  @param[in] pdr - The structure of pldm_numeric_effecter_value_pdr.
 *  @param[in] effecterDataSize - effecter value size.
 *  @param[in,out] effecterValue - effecter value.
 *  @param[in] propertyType - type of the D-Bus property.
 *
 *  @return std::pair<int, std::optional<PropertyValue>> - rc:Success or
 *          failure, PropertyValue: The value to be set
 */
std::pair<int, std::optional<pldm::utils::PropertyValue>> convertToDbusValue(
    const pldm_numeric_effecter_value_pdr* pdr, uint8_t effecterDataSize,
    uint8_t* effecterValue, std::string propertyType)
{
    if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT8)
    {
        uint8_t currentValue = *(reinterpret_cast<uint8_t*>(&effecterValue[0]));
        return getEffecterRawValue<uint8_t>(pdr, currentValue, propertyType);
    }
    else if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT8)
    {
        int8_t currentValue = *(reinterpret_cast<int8_t*>(&effecterValue[0]));
        return getEffecterRawValue<int8_t>(pdr, currentValue, propertyType);
    }
    else if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT16)
    {
        uint16_t currentValue =
            *(reinterpret_cast<uint16_t*>(&effecterValue[0]));
        return getEffecterRawValue<uint16_t>(pdr, currentValue, propertyType);
    }
    else if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT16)
    {
        int16_t currentValue = *(reinterpret_cast<int16_t*>(&effecterValue[0]));
        return getEffecterRawValue<int16_t>(pdr, currentValue, propertyType);
    }
    else if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_UINT32)
    {
        uint32_t currentValue =
            *(reinterpret_cast<uint32_t*>(&effecterValue[0]));
        return getEffecterRawValue<uint32_t>(pdr, currentValue, propertyType);
    }
    else if (effecterDataSize == PLDM_EFFECTER_DATA_SIZE_SINT32)
    {
        int32_t currentValue = *(reinterpret_cast<int32_t*>(&effecterValue[0]));
        return getEffecterRawValue<int32_t>(pdr, currentValue, propertyType);
    }
    else
    {
        error("Unknown Effecter Size {SIZE}", "SIZE", effecterDataSize);
        return {PLDM_ERROR, {}};
    }
}

/** @brief Function to set the effecter value requested by pldm requester
 *  @tparam[in] DBusInterface - DBus interface type
 *  @tparam[in] Handler - pldm::responder::platform::Handler
 *  @param[in] dBusIntf - The interface object of DBusInterface
 *  @param[in] handler - The interface object of
 *             pldm::responder::platform::Handler
 *  @param[in] effecterId - Effecter ID sent by the requester to act on
 *  @param[in] effecterDataSize - The bit width and format of the setting
 * 				value for the effecter
 *  @param[in] effecter_value - The setting value of numeric effecter being
 * 				requested.
 *  @param[in] effecterValueLength - The setting value length of numeric
 *              effecter being requested.
 *  @return - Success or failure in setting the states. Returns failure in
 * terms of PLDM completion codes if at least one state fails to be set
 */
template <class DBusInterface, class Handler>
int setNumericEffecterValueHandler(
    const DBusInterface& dBusIntf, Handler& handler, uint16_t effecterId,
    uint8_t effecterDataSize, uint8_t* effecterValue,
    size_t effecterValueLength)
{
    constexpr auto effecterValueArrayLength = 4;
    pldm_numeric_effecter_value_pdr* pdr = nullptr;

    std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)>
        numericEffecterPdrRepo(pldm_pdr_init(), pldm_pdr_destroy);
    if (!numericEffecterPdrRepo)
    {
        error("Failed to instantiate numeric effecter PDR repository");
        return PLDM_ERROR;
    }
    pldm::responder::pdr_utils::Repo numericEffecterPDRs(
        numericEffecterPdrRepo.get());
    pldm::responder::pdr::getRepoByType(handler.getRepo(), numericEffecterPDRs,
                                        PLDM_NUMERIC_EFFECTER_PDR);
    if (numericEffecterPDRs.empty())
    {
        error("The Numeric Effecter PDR repo is empty.");
        return PLDM_ERROR;
    }

    // Get the pdr structure of pldm_numeric_effecter_value_pdr according
    // to the effecterId
    pldm::responder::pdr_utils::PdrEntry pdrEntry{};
    auto pdrRecord = numericEffecterPDRs.getFirstRecord(pdrEntry);
    while (pdrRecord)
    {
        pdr = reinterpret_cast<pldm_numeric_effecter_value_pdr*>(pdrEntry.data);
        if (pdr->effecter_id != effecterId)
        {
            pdr = nullptr;
            pdrRecord = numericEffecterPDRs.getNextRecord(pdrRecord, pdrEntry);
            continue;
        }

        break;
    }

    if (!pdr)
    {
        return PLDM_PLATFORM_INVALID_EFFECTER_ID;
    }

    if (effecterValueLength != effecterValueArrayLength)
    {
        error("Incorrect effecter data size {SIZE}", "SIZE",
              effecterValueLength);
        return PLDM_ERROR_INVALID_DATA;
    }

    try
    {
        const auto& [dbusMappings, dbusValMaps] =
            handler.getDbusObjMaps(effecterId);
        pldm::utils::DBusMapping dbusMapping{
            dbusMappings[0].objectPath, dbusMappings[0].interface,
            dbusMappings[0].propertyName, dbusMappings[0].propertyType};

        // convert to dbus effectervalue according to the factor
        auto [rc, dbusValue] = convertToDbusValue(
            pdr, effecterDataSize, effecterValue, dbusMappings[0].propertyType);
        if (rc != PLDM_SUCCESS)
        {
            return rc;
        }
        try
        {
            dBusIntf.setDbusProperty(dbusMapping, dbusValue.value());
        }
        catch (const std::exception& e)
        {
            error(
                "Failed to set property '{PROPERTY}', interface '{INTERFACE}' and path '{PATH}', error - {ERROR}",
                "PROPERTY", dbusMapping.propertyName, "INTERFACE",
                dbusMapping.interface, "PATH", dbusMapping.objectPath, "ERROR",
                e);
            return PLDM_ERROR;
        }
    }
    catch (const std::out_of_range& e)
    {
        error("Unknown effecter ID '{EFFECTERID}', error - {ERROR}",
              "EFFECTERID", effecterId, "ERROR", e);
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

/** @brief Function to convert the D-Bus value based on effecter data size
 *         and create the response for getNumericEffecterValue request.
 *  @param[in] PropertyValue - D-Bus Value
 *  @param[in] effecterDataSize - effecter value size.
 *  @param[in,out] responsePtr - Response of getNumericEffecterValue.
 *  @param[in] responsePayloadLength - response length.
 *  @param[in] instanceId - instance id for response
 *
 *  @return PLDM_SUCCESS/PLDM_ERROR
 */
template <typename T>
int getEffecterValue(T propertyValue, uint8_t effecterDataSize,
                     pldm_msg* responsePtr, size_t responsePayloadLength,
                     uint8_t instanceId)
{
    switch (effecterDataSize)
    {
        case PLDM_EFFECTER_DATA_SIZE_UINT8:
        {
            uint8_t value = static_cast<uint8_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING, &value, &value,
                responsePtr, responsePayloadLength));
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT8:
        {
            int8_t value = static_cast<int8_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
                reinterpret_cast<uint8_t*>(&value),
                reinterpret_cast<uint8_t*>(&value), responsePtr,
                responsePayloadLength));
        }
        case PLDM_EFFECTER_DATA_SIZE_UINT16:
        {
            uint16_t value = static_cast<uint16_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
                reinterpret_cast<uint8_t*>(&value),
                reinterpret_cast<uint8_t*>(&value), responsePtr,
                responsePayloadLength));
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT16:
        {
            int16_t value = static_cast<int16_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
                reinterpret_cast<uint8_t*>(&value),
                reinterpret_cast<uint8_t*>(&value), responsePtr,
                responsePayloadLength));
        }
        case PLDM_EFFECTER_DATA_SIZE_UINT32:
        {
            uint32_t value = static_cast<uint32_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
                reinterpret_cast<uint8_t*>(&value),
                reinterpret_cast<uint8_t*>(&value), responsePtr,
                responsePayloadLength));
        }
        case PLDM_EFFECTER_DATA_SIZE_SINT32:
        {
            int32_t value = static_cast<int32_t>(propertyValue);
            return (encode_get_numeric_effecter_value_resp(
                instanceId, PLDM_SUCCESS, effecterDataSize,
                EFFECTER_OPER_STATE_ENABLED_NOUPDATEPENDING,
                reinterpret_cast<uint8_t*>(&value),
                reinterpret_cast<uint8_t*>(&value), responsePtr,
                responsePayloadLength));
        }
        default:
        {
            error("Unknown Effecter Size {SIZE}", "SIZE", effecterDataSize);
            return PLDM_ERROR;
        }
    }
}

/** @brief Function to convert the D-Bus value to the effector data size value
 *  @param[in] PropertyType - String contains the dataType of the Dbus value.
 *  @param[in] PropertyValue - Variant contains the D-Bus Value
 *  @param[in] effecterDataSize - effecter value size.
 *  @param[in,out] responsePtr - Response of getNumericEffecterValue.
 *  @param[in] responsePayloadLength - response length.
 *  @param[in] instanceId - instance id for response
 *
 *  @return PLDM_SUCCESS/PLDM_ERROR
 */
int getNumericEffecterValueHandler(
    const std::string& propertyType, pldm::utils::PropertyValue propertyValue,
    uint8_t effecterDataSize, pldm_msg* responsePtr,
    size_t responsePayloadLength, uint8_t instanceId)
{
    if (propertyType == "uint8_t")
    {
        uint8_t propVal = std::get<uint8_t>(propertyValue);
        return getEffecterValue<uint8_t>(propVal, effecterDataSize, responsePtr,
                                         responsePayloadLength, instanceId);
    }
    else if (propertyType == "uint16_t")
    {
        uint16_t propVal = std::get<uint16_t>(propertyValue);
        return getEffecterValue<uint16_t>(propVal, effecterDataSize,
                                          responsePtr, responsePayloadLength,
                                          instanceId);
    }
    else if (propertyType == "uint32_t")
    {
        uint32_t propVal = std::get<uint32_t>(propertyValue);
        return getEffecterValue<uint32_t>(propVal, effecterDataSize,
                                          responsePtr, responsePayloadLength,
                                          instanceId);
    }
    else if (propertyType == "uint64_t")
    {
        uint64_t propVal = std::get<uint64_t>(propertyValue);
        return getEffecterValue<uint64_t>(propVal, effecterDataSize,
                                          responsePtr, responsePayloadLength,
                                          instanceId);
    }
    else
    {
        error("Property type '{TYPE}' not supported", "TYPE", propertyType);
    }
    return PLDM_ERROR;
}

/** @brief Function to get the effecter details as data size, D-Bus property
 *         type, D-Bus Value
 *  @tparam[in] DBusInterface - DBus interface type
 *  @tparam[in] Handler - pldm::responder::platform::Handler
 *  @param[in] dBusIntf - The interface object of DBusInterface
 *  @param[in] handler - The interface object of
 *             pldm::responder::platform::Handler
 *  @param[in] effecterId - Effecter ID sent by the requester to act on
 *  @param[in] effecterDataSize - The bit width and format of the setting
 *             value for the effecter
 *  @param[in] propertyType - The data type of the D-Bus value
 *  @param[in] propertyValue - The value of numeric effecter being
 *                             requested.
 *  @return - Success or failure in getting the D-Bus property or the
 *  effecterId not found in the PDR repo
 */
template <class DBusInterface, class Handler>
int getNumericEffecterData(const DBusInterface& dBusIntf, Handler& handler,
                           uint16_t effecterId, uint8_t& effecterDataSize,
                           std::string& propertyType,
                           pldm::utils::PropertyValue& propertyValue)
{
    pldm_numeric_effecter_value_pdr* pdr = nullptr;

    std::unique_ptr<pldm_pdr, decltype(&pldm_pdr_destroy)>
        numericEffecterPdrRepo(pldm_pdr_init(), pldm_pdr_destroy);
    pldm::responder::pdr_utils::Repo numericEffecterPDRs(
        numericEffecterPdrRepo.get());
    pldm::responder::pdr::getRepoByType(handler.getRepo(), numericEffecterPDRs,
                                        PLDM_NUMERIC_EFFECTER_PDR);
    if (numericEffecterPDRs.empty())
    {
        error("The Numeric Effecter PDR repo is empty.");
        return PLDM_ERROR;
    }

    // Get the pdr structure of pldm_numeric_effecter_value_pdr according
    // to the effecterId
    pldm::responder::pdr_utils::PdrEntry pdrEntry{};
    auto pdrRecord = numericEffecterPDRs.getFirstRecord(pdrEntry);

    while (pdrRecord)
    {
        pdr = reinterpret_cast<pldm_numeric_effecter_value_pdr*>(pdrEntry.data);
        if (pdr->effecter_id != effecterId)
        {
            pdr = nullptr;
            pdrRecord = numericEffecterPDRs.getNextRecord(pdrRecord, pdrEntry);
            continue;
        }
        effecterDataSize = pdr->effecter_data_size;
        break;
    }

    if (!pdr)
    {
        error("Failed to find numeric effecter ID {EFFECTERID}", "EFFECTERID",
              effecterId);
        return PLDM_PLATFORM_INVALID_EFFECTER_ID;
    }

    pldm::utils::DBusMapping dbusMapping{};
    try
    {
        const auto& [dbusMappings, dbusValMaps] =
            handler.getDbusObjMaps(effecterId);
        if (dbusMappings.size() > 0)
        {
            dbusMapping = {
                dbusMappings[0].objectPath, dbusMappings[0].interface,
                dbusMappings[0].propertyName, dbusMappings[0].propertyType};

            propertyValue = dBusIntf.getDbusPropertyVariant(
                dbusMapping.objectPath.c_str(),
                dbusMapping.propertyName.c_str(),
                dbusMapping.interface.c_str());
            propertyType = dbusMappings[0].propertyType;
        }
    }
    catch (const std::exception& e)
    {
        error(
            "Failed to do dbus mapping or the dbus query for the effecter ID '{EFFECTERID}', error - {ERROR}",
            "EFFECTERID", effecterId, "ERROR", e);
        error(
            "Dbus Details path [{PATH}], interface [{INTERFACE}] and  property [{PROPERTY}]",
            "PATH", dbusMapping.objectPath, "INTERFACE", dbusMapping.interface,
            "PROPERTY", dbusMapping.propertyName);
        return PLDM_ERROR;
    }

    return PLDM_SUCCESS;
}

} // namespace platform_numeric_effecter
} // namespace responder
} // namespace pldm
