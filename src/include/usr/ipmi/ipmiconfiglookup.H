/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmiconfiglookup.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __IPMI_IPMICONFIG_LOOKUP_H
#define __IPMI_IPMICONFIG_LOOKUP_H


#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace IPMI
{

/**
 * @brief - Classs to read IPMI sensor information from the targetting
 *          namespace. This class does not send IPMI messages but rather
 *          looks up static configuration data.
 *
 */
class IpmiConfigLookup
{
 public:

    /**
      * @brief getSensorType. Returns the sensor type of a sensor identified
      *                       by a sensor number.
      *
      * @param[in]   i_sensorNumber. The IPMI sensor whose information we wish
      *                              to gather.
      *
      * @param[out]  o_sensorType. The sensor type as read from the
      *              IPMI_SENSOR_ARRAY.
      *
      * @param[in]  i_sensorTarget. A Target to use for looking up sensor
      *             information. If this parameter is equal to nullptr
      *             then all targets will be searched for the sensor that
      *             matches the supplied sensor number.
      *
      * @return     An errlHndl_t (aka ErrlEntry*) if an error occurred. If
      *             the call was successful, the method returns a NULL
      *             pointer.
      *
      */
    static errlHndl_t getSensorType(uint32_t i_sensorNumber,
                              uint8_t &  o_sensorType,
                              TARGETING::Target * i_sensorTarget = nullptr
                             );

    /**
      * @brief getEntityId. Returns a sensor entity id of a sensor identified
      *                     by a sensor number.
      *
      * @param[in]   i_sensorNumber. The IPMI sensor whose information we wish
      *                              to gather.
      *
      * @param[out]  o_entityId. The sensor entity id as read from the
      *              IPMI_SENSOR_ARRAY.
      *
      * @param[in]  i_sensorTarget. A Target to use for looking up sensor
      *             information. If this parameter is equal to nullptr
      *             then all targets will be searched for the sensor that
      *             matches the supplied sensor number.
      *
      * @return     An errlHndl_t (aka ErrlEntry*) if an error occurred. If
      *             the call was successful, the method returns a NULL
      *             pointer.
      *
      */
    static errlHndl_t getEntityId(uint32_t i_sensorNumber,
                           uint8_t & o_entityId,
                           TARGETING::Target * i_sensorTarget = nullptr
                          );

    /**
      * @brief getSensorName. Returns the sensor name of a sensor identified by
      *                       by a sensor number.
      *
      * @param[in]   i_sensorNumber. The IPMI sensor whose information we wish
      *                              to gather.
      *
      * @param[out] o_sensorName. Optional parameter to the sensor name.
      *              The sensor name by definition will be
      *              (SENSOR_TYPE << 16) | (ENTITY_ID).
      *              Pass nullptr if the caller is not interested in obtaining
      *              this value. At least one of o_sensorType, o_entityId or
      *              o_sensorName must be non-null
      *
      * @param[in]  i_sensorTarget. A Target to use for looking up sensor
      *             information. If this parameter is equal to nullptr
      *             then all targets will be searched for the sensor that
      *             matches the supplied sensor number.
      *
      * @return     An errlHndl_t (aka ErrlEntry*) if an error occurred. If
      *             the call was successful, the method returns a NULL
      *             pointer.
      *
      */
    static errlHndl_t getSensorName(uint32_t i_sensorNumber,
                             TARGETING::SENSOR_NAME & o_sensorName,
                             TARGETING::Target * i_sensorTarget = nullptr
                            );

    /**
     *  @brief getSensorType. Parses a SENSOR_NAME for the sensor type
     *
     *  @param[in]  i_sensorName. SENSOR_NAME (SENSOR_TYPE | ENTITY_ID)
     *
     *  @param[out] o_sensorType. The sensor type parsed from the SENSOR_NAME
     *
     */
    inline static void getSensorType(TARGETING::SENSOR_NAME i_sensorName,
                                     uint8_t &  o_sensorType
                                    )
    {
        o_sensorType = static_cast<uint8_t>(i_sensorName >> 8 & 0x000000FF);
    }

    /**
     *  @brief getEntityId. Parses a SENSOR_NAME for the entity id.
     *
     *  @param[in]  i_sensorName. SENSOR_NAME (SENSOR_TYPE | ENTITY_ID)
     *
     *  @param[out] o_sensorType. The sensor type parsed from the SENSOR_NAME
     */
    inline static void getEntityId(TARGETING::SENSOR_NAME i_sensorName,
                                   uint8_t & o_entityId
                                  )
    {
        o_entityId = static_cast<uint8_t>(i_sensorName & 0x000000FF);
    }

 private:
 /**
 *  @brief Returns parsed IPMI_SENSOR_ARRAY attribute information based upon
 *         a given sensor number.
 *
 *  @param[in] i_sensorNumber. The IPMI sensor whose information we wish
 *             to gather.
 *
 *  @param[out] o_sensorType. Optional parameter to the sensor type as read
 *              from the IPMI_SENSOR_ARRAY. Pass nullptr if the caller is not
 *              interested in obtaining this value. At least one of
 *              o_sensorType, o_entityId or o_sensorName must be non-null.
 *
 *  @param[out] o_entityId. Optional parameter to the entity id associated with
 *              the sensor as read from the IPMI_SENSOR_ARRAY. Pass nullptr if
 *              the caller is not interested in obtaining this value. At least
 *              one of o_sensorType, o_entityId or o_sensorName must be
 *              non-null.
 *
 *  @param[out] o_sensorName. Optional parameter to the sensor name. The sensor
 *              name by definition will be (SENSOR_TYPE << 16) | (ENTITY_ID).
 *              Pass nullptr if the caller is not interested in obtaining this
 *              value. At least one of o_sensorType, o_entityId or o_sensorName
 *              must be non-null.
 *
 * @param[in] i_sensorTarget. A Target to use for looking up sensor information.
 *            If this parameter is equal to nullptr all targets will be searched
 *            for the sensor that matches the supplied sensor number.
 *
 *  @return True if the sensor was found in the IPMI_SENSOR_ARRAY attribute,
 *          false otherwise.
 */
    static bool getIPMISensorInfo(uint32_t i_sensorNumber,
                   uint8_t * o_sensorType,
                   uint8_t * o_entityId = nullptr,
                   TARGETING::SENSOR_NAME * o_sensorName = nullptr,
                   TARGETING::Target * i_sensorTarget = nullptr
                  );

/**
 *  @brief Determines whether the passed in target has the IPMI_SENSOR
 *         attribute.
 *
 *  @param[in] i_tgt. The target to test.
 *
 *  @reurn True if the target has the IPMI_SENSOR attribute, false otherwise.
 *
 */
    inline static bool doesTargetHaveIpmiSensorAttr(TARGETING::Target * i_tgt)
    {
        if(!i_tgt)
        {
            return false;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_IPMI_SENSORS>::Type
                                                                l_ipmiArray;
        return i_tgt->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(l_ipmiArray);
    }

/**
 *  @brief Given a passed in target, looks up IPMI_SENSOR data based upon
 *         the passed in sensor number.
 *
 *  @param[in] i_target. The target whose IPMI_SENSOR attribute will be
 *                       searched for information based upon the passed
 *                       in sensor number.
 *
 *  @param[in] i_sensorNumber. The IPMI sensor whose information we wish
 *                             to gather.
 *
 *  @param[out] o_sensorType. The sensor type as read from the
 *              from the IPMI_SENSOR_ARRAY.
 *
 *  @param[out] o_entityId. The entity id associated with
 *              the sensor as read from the IPMI_SENSOR_ARRAY.
 *
 *  @param[out] o_sensorName. The sensor name as read from
 *                            the IPMI_SENSOR_ARRAY.
 *
 */
    static bool lookupIPMISensorInfo(TARGETING::Target * i_target,
                                     uint32_t i_sensorNumber,
                                     uint8_t& o_sensorType,
                                     uint8_t& o_entityId,
                                     TARGETING::SENSOR_NAME& o_sensorName
                                    );
};

}

#endif
