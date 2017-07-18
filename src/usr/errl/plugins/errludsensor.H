/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludsensor.H $                         */
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
 *  Defines the ErrlUserDetailsParserSensor class that parses faulty
 *  sensor user detail in an error log
 */

#include "errluserdetails.H"
#include <targeting/common/target.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserSensor
 *
 * Parses Faulty sensor type and number  user detail in an error log
 */
class ErrlUserDetailsParserSensor :public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserSensor() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserSensor() {}

    /**
     *  @brief Parses sensor user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing sesnor detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        typedef struct {
            TARGETING::ATTR_FRU_ID_type fru;
            uint8_t pad[3];
            uint8_t sensorNum;
            HWAS::callOutPriority priority;
        } sensorDetails_t;

        if(i_buflen == sizeof(sensorDetails_t))
        {
            sensorDetails_t* outputData =
                                static_cast<sensorDetails_t*>(i_pBuffer);
            i_parser.PrintNumber("Faulty FRU ID", "0x%02X",
                                ntohl(outputData->fru));
            i_parser.PrintNumber("Faulty Sensor Number", "0x%02X",
                                outputData->sensorNum);

            switch (ntohl(outputData->priority))
            {
#define case_PRIORITY(_type) \
case HWAS::_type: i_parser.PrintString( "Priority", #_type); break;
                case_PRIORITY(SRCI_PRIORITY_NONE)
                case_PRIORITY(SRCI_PRIORITY_LOW)
                case_PRIORITY(SRCI_PRIORITY_MEDC)
                case_PRIORITY(SRCI_PRIORITY_MEDB)
                case_PRIORITY(SRCI_PRIORITY_MEDA)
                case_PRIORITY(SRCI_PRIORITY_MED)
                case_PRIORITY(SRCI_PRIORITY_HIGH)
            default:
                i_parser.PrintNumber( "Priority", "UNKNOWN: 0x%X",
                                    ntohl(outputData->priority) );
                break;
            } // switch priority
#undef case_PRIORITY

        }
        else
        {
            i_parser.PrintNumber("Sensor Buffer length", "0x%X", i_buflen);
            i_parser.PrintNumber("Expected length", "0x%X",
                                sizeof(sensorDetails_t));
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserSensor(const ErrlUserDetailsParserSensor &);
    ErrlUserDetailsParserSensor & operator=(
        const ErrlUserDetailsParserSensor &);
};

}

#endif
