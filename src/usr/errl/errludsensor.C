/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludsensor.C $                                 */
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
/**
 *  @file errludsensor.C
 *
 *  @brief Implementation of ErrlUserDetailsSensor
 */
#include <errl/errludsensor.H>
#include <errl/errlreasoncodes.H>

namespace ERRORLOG
{

    ErrlUserDetailsSensor::ErrlUserDetailsSensor(
                            TARGETING::ATTR_FRU_ID_type i_fru_id,
                            uint8_t i_sensor_number,
                            HWAS::callOutPriority i_priority)
    {
        typedef struct {
            TARGETING::ATTR_FRU_ID_type fru;
            uint8_t pad[3];
            uint8_t sensorNum;
            HWAS::callOutPriority priority;
        } sensorDetails_t;

        sensorDetails_t l_sensorDetails;

        l_sensorDetails.fru = i_fru_id;
        l_sensorDetails.sensorNum = i_sensor_number;
        memset(l_sensorDetails.pad, 0, sizeof(l_sensorDetails.pad));
        l_sensorDetails.priority = i_priority;

        uint8_t* l_buf = reinterpret_cast<uint8_t*>(
                            reallocUsrBuf(sizeof(l_sensorDetails)));
        memcpy(l_buf, &l_sensorDetails, sizeof(l_sensorDetails));

        // Set up ErrlUserDetails instance variables
        iv_CompId = ERRL_COMP_ID;
        iv_Version = 1;
        iv_SubSection = ERRL_UDT_SENSOR;
    }

    ErrlUserDetailsSensor::~ErrlUserDetailsSensor()
    {

    }
}
