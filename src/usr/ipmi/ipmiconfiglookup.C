/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiconfiglookup.C $                             */
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
#include <ipmi/ipmiconfiglookup.H>

#include <algorithm>
#include <assert.h>

#include <attributeenums.H>
#include <ipmi/ipmi_reasoncodes.H>
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t * g_trac_ipmi;

namespace IPMI
{

//-----------------------------------------------------------------------------
// Private method used to lookup sensor information from the IPMI_SENSOR_ARRAY
// attribute of the i_target parameter.
//
// Returns true if the sensor was found, false otherwise.
//-----------------------------------------------------------------------------
bool IpmiConfigLookup::lookupIPMISensorInfo(TARGETING::Target * i_target,
                                            uint32_t i_sensorNumber,
                                            uint8_t& o_sensorType,
                                            uint8_t& o_entityId,
                                            TARGETING::SENSOR_NAME& o_sensorName
                                            )
{
    using IPMI_ARRAY_ELEMENT = uint16_t[2];
    bool l_result{false};

    assert(nullptr != i_target);
    assert(TARGETING::UTIL::INVALID_IPMI_SENSOR != i_sensorNumber);

    //Get the IPMI_SENSOR_ARRAY attribute from i_target.
    TARGETING::AttributeTraits<TARGETING::ATTR_IPMI_SENSORS>::Type l_ipmiArray;
    if(!i_target->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(l_ipmiArray))
    {
        return l_result;
    }

    //Search the IPMI_SENSOR_ARRAY for the desired sensor.
    uint32_t elementCount = (sizeof(l_ipmiArray)/sizeof(l_ipmiArray[0]));
    const IPMI_ARRAY_ELEMENT * begin = &l_ipmiArray[0];
    const IPMI_ARRAY_ELEMENT * end = &l_ipmiArray[elementCount];
    const IPMI_ARRAY_ELEMENT * itr{nullptr};

    itr = std::find_if(begin,
                       end,
                       [i_sensorNumber] (const IPMI_ARRAY_ELEMENT& a)
                       {
                        return a[TARGETING::IPMI_SENSOR_ARRAY_NUMBER_OFFSET]
                                                             == i_sensorNumber;
                       }
                      );

    if(itr != end)
    {
        l_result = true;
        uint16_t l_sensorName = (*itr)
                                [TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET];
        o_sensorName = static_cast<TARGETING::SENSOR_NAME>(l_sensorName);
        o_sensorType = static_cast<uint8_t>((l_sensorName >> 8) & 0x00FF);
        o_entityId = static_cast<uint8_t>(l_sensorName & 0x00FF);
    }

    return l_result;
}


//-----------------------------------------------------------------------------
// Private method used to lookup sensor information from the GPU_SENSORS
// array attribute of the i_target parameter.
//
// Returns true if the sensor was found, false otherwise.
//-----------------------------------------------------------------------------
bool IpmiConfigLookup::lookupGPUSensorInfo(TARGETING::Target * i_target,
                                            uint32_t i_sensorNumber,
                                            uint8_t& o_sensorType,
                                            uint8_t& o_entityId,
                                            TARGETING::SENSOR_NAME& o_sensorName
                                            )
{
    using GPU_ARRAY_ELEMENT = uint16_t[7];
    bool l_result{false};

    assert(nullptr != i_target);
    assert(TARGETING::UTIL::INVALID_IPMI_SENSOR != i_sensorNumber);

    // Get the GPU_SENSORS array attribute from i_target
    TARGETING::AttributeTraits<TARGETING::ATTR_GPU_SENSORS>::Type
                                                                l_sensorArray;
    if(!i_target->tryGetAttr<TARGETING::ATTR_GPU_SENSORS>(l_sensorArray))
    {
        return l_result;
    }

    //Search the sensor array for the desired sensor
    uint32_t elementCount = (sizeof(l_sensorArray)/sizeof(l_sensorArray[0]));
    const GPU_ARRAY_ELEMENT * begin = &l_sensorArray[0];
    const GPU_ARRAY_ELEMENT * end = &l_sensorArray[elementCount];
    const GPU_ARRAY_ELEMENT * itr{nullptr};

    itr = std::find_if(begin,
                       end,
                       [i_sensorNumber] (const GPU_ARRAY_ELEMENT& a)
                       {
                           return (
         (a[TARGETING::GPU_SENSOR_ARRAY_FUNC_ID_OFFSET] == i_sensorNumber) ||
         (a[TARGETING::GPU_SENSOR_ARRAY_TEMP_ID_OFFSET] == i_sensorNumber) ||
         (a[TARGETING::GPU_SENSOR_ARRAY_MEM_TEMP_ID_OFFSET] == i_sensorNumber));
                       }
                      );

    if(itr != end)
    {
        l_result = true;
        uint16_t l_sensorName;
        if (*itr[TARGETING::GPU_SENSOR_ARRAY_FUNC_ID_OFFSET] == i_sensorNumber)
        {
            l_sensorName = *itr[TARGETING::GPU_SENSOR_ARRAY_FUNC_OFFSET];
        }
        else if
        (*itr[TARGETING::GPU_SENSOR_ARRAY_TEMP_ID_OFFSET] == i_sensorNumber)
        {
            l_sensorName = *itr[TARGETING::GPU_SENSOR_ARRAY_TEMP_ID_OFFSET];
        }
        else
        {
            l_sensorName = *itr[TARGETING::GPU_SENSOR_ARRAY_MEM_TEMP_ID_OFFSET];
        }

        o_sensorName = static_cast<TARGETING::SENSOR_NAME>(l_sensorName);
        o_sensorType = static_cast<uint8_t>((l_sensorName >> 8) & 0x00FF);
        o_entityId = static_cast<uint8_t>(l_sensorName & 0x00FF);
    }

    return l_result;
}

//--------------------------------------------------------------------------
//Given a sensor number, lookup and parse SENSOR_NAME into SENSOR_TYPE
//and ENTITY_ID values.
//--------------------------------------------------------------------------
bool IpmiConfigLookup::getIPMISensorInfo(uint32_t i_sensorNumber,
                                         uint8_t * o_sensorType,
                                         uint8_t * o_entityId,
                                         TARGETING::SENSOR_NAME * o_sensorName,
                                         TARGETING::Target * i_sensorTarget
                                        )
{
    bool l_result{false};

    //Ensure that the sensor number is not the invalid id.
    assert(TARGETING::UTIL::INVALID_IPMI_SENSOR != i_sensorNumber);

    TARGETING::SENSOR_NAME l_sensorName =
                            static_cast<TARGETING::SENSOR_NAME>(0);
    uint8_t l_sensorType = TARGETING::SENSOR_TYPE_NA;
    uint8_t l_entityId = TARGETING::ENTITY_ID_NA;

    //Ensure that at least one optional out parameter was given.
    assert(nullptr != o_sensorType ||
           nullptr != o_sensorName ||
           nullptr != o_entityId);

    //If the caller passed in a target then find sensor data within the
    //context of the passed in target.
    if(i_sensorTarget)
    {
        if(doesTargetHaveIpmiSensorAttr(i_sensorTarget))
        {
            l_result = lookupIPMISensorInfo(i_sensorTarget,
                                            i_sensorNumber,
                                            l_sensorType,
                                            l_entityId,
                                            l_sensorName);
        }
    }
    else
    {
        //The caller did not supply a target context for the sensor.
        //Search for the sensor amoung all targets.
        for(auto itr = TARGETING::targetService().begin();
            itr != TARGETING::targetService().end(); ++itr)
        {
            if(doesTargetHaveIpmiSensorAttr(*itr))
            {
                l_result = lookupIPMISensorInfo((*itr),
                                                i_sensorNumber,
                                                l_sensorType,
                                                l_entityId,
                                                l_sensorName);
                if(l_result)
                {
                    break;
                }
            }
            else if (doesTargetHaveGPUSensorsAttr(*itr))
            {
                l_result = lookupGPUSensorInfo((*itr),
                                                i_sensorNumber,
                                                l_sensorType,
                                                l_entityId,
                                                l_sensorName);
                if (l_result)
                {
                    break;
                }

            }
        }
    }

    //set any out parameters that are desired by the caller.
    if(o_sensorName)
    {
        *o_sensorName = l_sensorName;
    }

    if(o_sensorType)
    {
        *o_sensorType = l_sensorType;
    }

    if(o_entityId)
    {
        *o_entityId = l_entityId;
    }

    return l_result;
}

//------------------------------------------------------------------
errlHndl_t IpmiConfigLookup::getSensorType(uint32_t i_sensorNumber,
                                            uint8_t &  o_sensorType,
                                 TARGETING::Target * i_sensorTarget
                                           )
{
    errlHndl_t l_errl{};

    //Ensure that the sensor number is not the invalid id.
    if(TARGETING::UTIL::INVALID_IPMI_SENSOR == i_sensorNumber)
    {
        TRACFCOMP(g_trac_ipmi,
                  ERR_MRK"The i_sensorNumber parameter "
                         "is the invalid sensor number (%X).",
                         i_sensorNumber
                 );
        /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_TYPE
        * @reasoncode   IPMI::RC_INVALID_SENSOR_NUMBER
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The passed in sensor number is not valid.
        * @custdesc     The passed in sensor number is not valid.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             IPMI::MOD_IPMISENSOR_TYPE,
                                             IPMI::RC_INVALID_SENSOR_NUMBER,
                                             i_sensorNumber,
                                             0,
                                             false);
        return l_errl;
    }

    bool l_rc = getIPMISensorInfo(i_sensorNumber,
                                  &o_sensorType,
                                  nullptr,
                                  nullptr,
                                  i_sensorTarget
                                  );

    if(!l_rc)
    {

       TRACFCOMP(g_trac_ipmi,
                 ERR_MRK"Did not find a sensor with number %X.",
                 i_sensorNumber);

       /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_TYPE
        * @reasoncode   IPMI::RC_SENSOR_NOT_FOUND
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The sensor could not be found based upon
        *               the sensor number.
        * @custdesc     Unable to determine sensor information.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         IPMI::MOD_IPMISENSOR_TYPE,
                                         IPMI::RC_SENSOR_NOT_FOUND,
                                         i_sensorNumber,
                                         0,
                                         false);
    }

    return l_errl;
}

//--------------------------------------------------------------------------
errlHndl_t IpmiConfigLookup::getEntityId(uint32_t i_sensorNumber,
                                         uint8_t & o_entityId,
                                         TARGETING::Target * i_sensorTarget
                                        )
{
    errlHndl_t l_errl{};

    if(TARGETING::UTIL::INVALID_IPMI_SENSOR == i_sensorNumber)
    {

        TRACFCOMP(g_trac_ipmi,
                  ERR_MRK"The i_sensorNumber parameter "
                         "is an invalid sensor number (%X).",
                         i_sensorNumber
                 );
        /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_ENTITY_ID
        * @reasoncode   IPMI::RC_INVALID_SENSOR_NUMBER
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The passed in sensor number is not valid.
        * @custdesc     The passed in sensor number is not valid.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             IPMI::MOD_IPMISENSOR_ENTITY_ID,
                                             IPMI::RC_INVALID_SENSOR_NUMBER,
                                             i_sensorNumber,
                                             0,
                                             false);
        return l_errl;
    }

    bool l_rc = getIPMISensorInfo(i_sensorNumber,
                                  nullptr,
                                  &o_entityId,
                                  nullptr,
                                  i_sensorTarget
                                 );

    if(!l_rc)
    {

       TRACFCOMP(g_trac_ipmi,
                 ERR_MRK"Did not find a sensor with number %X.",
                 i_sensorNumber);

       /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_ENTITY_ID
        * @reasoncode   IPMI::RC_SENSOR_NOT_FOUND
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The sensor could not be found based upon
        *               the sensor number.
        * @custdesc     Unable to determine sensor information.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         IPMI::MOD_IPMISENSOR_ENTITY_ID,
                                         IPMI::RC_SENSOR_NOT_FOUND,
                                         i_sensorNumber,
                                         0,
                                         false);
    }

    return l_errl;
}

//-----------------------------------------------------------------------
errlHndl_t IpmiConfigLookup::getSensorName(uint32_t i_sensorNumber,
                         TARGETING::SENSOR_NAME & o_sensorName,
                         TARGETING::Target * i_sensorTarget
                        )
{
    errlHndl_t l_errl{};

    if(TARGETING::UTIL::INVALID_IPMI_SENSOR == i_sensorNumber)
    {

        TRACFCOMP(g_trac_ipmi,
                  ERR_MRK"The i_sensorNumber parameter "
                         "is an invalid sensor number (%X).",
                         i_sensorNumber
                 );

        /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_NAME
        * @reasoncode   IPMI::RC_INVALID_SENSOR_NUMBER
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The passed in sensor number is not valid.
        * @custdesc     The passed in sensor number is not valid.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         IPMI::MOD_IPMISENSOR_NAME,
                                         IPMI::RC_INVALID_SENSOR_NUMBER,
                                         i_sensorNumber,
                                         0,
                                         false);
        return l_errl;
    }

    bool l_rc = getIPMISensorInfo(i_sensorNumber,
                                  nullptr,
                                  nullptr,
                                  &o_sensorName,
                                  i_sensorTarget
                                 );

    if(!l_rc)
    {

       TRACFCOMP(g_trac_ipmi,
                 ERR_MRK"Did not find a sensor with number %X.",
                 i_sensorNumber);

       /*@
        * @errortype    ERRL_SEV_UNRECOVERABLE
        * @moduleid     IPMI::MOD_IPMISENSOR_NAME
        * @reasoncode   IPMI::RC_SENSOR_NOT_FOUND
        * @userdata1    IPMI Sensor Number
        * @userdata2    <unused>
        * @devdesc      The sensor could not be found based upon
        *               the sensor number.
        * @custdesc  Unable to determine sensor information.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         IPMI::MOD_IPMISENSOR_NAME,
                                         IPMI::RC_SENSOR_NOT_FOUND,
                                         i_sensorNumber,
                                         0,
                                         false);
    }

    return l_errl;
}

} //End namespace

