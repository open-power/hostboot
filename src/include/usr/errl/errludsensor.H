/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludsensor.H $                         */
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
#ifndef ERRL_UDSENSOR_H
#define ERRL_UDSENSOR_H

/**
 *  @file errludsensor.H
 *
 *  Defines the ErrlUserDetailsSensor class that adds fault sensor
 *  information to an error log as user detail data
 */

#include <errl/errluserdetails.H>
#include <stdint.h>


//Forward reference
namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsSensor
 *
 * Adds fault sensor number and fru id to an error log as user detail data
 */
class ErrlUserDetailsSensor : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  @param i_fru_id: FRU ID of part called out
     *  @param i_sensor_number: faulty sensor number
     *  @param i_priority: Priority callout of the part
     *
     *  Creates a Fault Sensor UserDetail, storing the faulty sensor
     *  number for the hw callout. User must call addToLog() in order
     *  to push the data to the error log.
     */
    ErrlUserDetailsSensor(TARGETING::ATTR_FRU_ID_type i_fru_id,
                          uint8_t i_sensor_number,
                          HWAS::callOutPriority i_priority);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsSensor();

private:
    // Disabled
    ErrlUserDetailsSensor(const ErrlUserDetailsSensor &);
    ErrlUserDetailsSensor & operator=(const ErrlUserDetailsSensor &);
};

}

#endif
