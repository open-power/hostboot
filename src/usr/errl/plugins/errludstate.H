/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludstate.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#ifndef ERRL_UDSTATEP_H
#define ERRL_UDSTATEP_H

/**
 *  @file errludsensor.H
 *
 *  Defines the ErrlUserDetailsParserState class that parses system
 *  state info from user detail in an error log
 */

#include "errluserdetails.H"
#ifndef LOGPARSER
#include <targeting/common/target.H>
#endif
namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserSysState
 *
 * Parses System state information from user detail in an error log
 */
class ErrlUserDetailsParserSysState :public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserSysState() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserSysState() {}

    /**
     *  @brief Parses State user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing Istep state data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(const errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * const i_pBuffer,
                       const uint32_t i_buflen) const
    {
        const uint8_t* const l_data = static_cast<uint8_t*>(i_pBuffer);

        if (i_version == 2)
        {
            //***** Memory Layout *****
            // 1 bytes  : Major Istep
            // 1 bytes  : Minor Istep
            // 1 bytes  : IPL type
            const size_t TOTAL_SIZE = 3;
            const uint8_t IPL_TYPE_UNAVAILABLE = 0xFF;

            if( i_buflen >= TOTAL_SIZE )
            {
                i_parser.PrintNumber("Current Major Istep", "%d",
                                     l_data[0]);
                i_parser.PrintNumber("Current Minor Istep", "%d",
                                     l_data[1]);

                if (l_data[2] == IPL_TYPE_UNAVAILABLE)
                {
                    i_parser.PrintString("MPIPL mode?", "Unknown");
                }
                else
                {
                    i_parser.PrintNumber("MPIPL mode?", "%d",
                                         l_data[2]);
                }

                if( i_buflen > TOTAL_SIZE )
                {
                    // Print out extra data as hex so that an old parser will
                    //  still display new data that gets logged in the code
                    i_parser.PrintHexDump( (l_data+TOTAL_SIZE), i_buflen-TOTAL_SIZE );
                }
            }
            else
            {
                // Just print out whatever we have if it is less than
                //  the data size we are aware of
                i_parser.PrintNumber("State Buffer length", "0x%X", i_buflen);
                i_parser.PrintNumber("Expected length", "0x%X", TOTAL_SIZE);
                i_parser.PrintHexDump(i_pBuffer, i_buflen);
            }
        }
        else // version 1
        {
            //***** Memory Layout *****
            // 1 bytes  : Major Istep
            // 1 bytes  : Minor Istep
            const size_t TOTAL_SIZE = 2;

            if( i_buflen >= TOTAL_SIZE )
            {
                i_parser.PrintNumber("Current Major Istep", "%d",
                                     l_data[0]);
                i_parser.PrintNumber("Current Minor Istep", "%d",
                                     l_data[1]);

                if( i_buflen > TOTAL_SIZE )
                {
                    // Print out extra data as hex so that an old parser will
                    //  still display new data that gets logged in the code
                    i_parser.PrintHexDump( (l_data+TOTAL_SIZE), i_buflen-TOTAL_SIZE );
                }
            }
            else
            {
                // Just print out whatever we have if it is less than
                //  the data size we are aware of
                i_parser.PrintNumber("State Buffer length", "0x%X", i_buflen);
                i_parser.PrintNumber("Expected length", "0x%X", TOTAL_SIZE);
                i_parser.PrintHexDump(i_pBuffer, i_buflen);
            }
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserSysState(const ErrlUserDetailsParserSysState &);
    ErrlUserDetailsParserSysState & operator=(
        const ErrlUserDetailsParserSysState &);
};

}

#endif
