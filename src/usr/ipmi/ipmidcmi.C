/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmidcmi.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 * @file ipmidcmi.C
 * @brief IPMI DCMI command extensions
 */

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <ipmi/ipmiif.H>
#include <ipmi/ipmisensor.H>
#include <ipmi/ipmi_reasoncodes.H>
extern trace_desc_t * g_trac_ipmi;

namespace SENSOR
{
    enum dcmi_cc
    {
        POWER_LIMIT_ACTIVE     = 0x00,
        POWER_LIMIT_NOT_ACTIVE = 0x80,
    };

    // fetch the user defined power limit stored on the BMC
    // using the DCMI Get Power Limit command
    errlHndl_t getUserPowerLimit( uint16_t &o_powerLimit, bool &o_limitActive )
    {
        o_powerLimit = 0;

        // assume the limit has not been activated
        o_limitActive = false;

        errlHndl_t l_err = NULL;

        // per DCMI spec data size is 3 bytes
        size_t len = 3;

        //create request data buffer
        uint8_t* data = new uint8_t[len];

        IPMI::completion_code cc = IPMI::CC_UNKBAD;

        data[0] = 0xDC;  // Group Extension Identification
        data[1] = 0x00;  // reserved
        data[2] = 0x00;  // reserved

        l_err = IPMI::sendrecv(IPMI::get_power_limit(), cc, len, data);

        SENSOR::dcmi_cc l_cc = static_cast<SENSOR::dcmi_cc>(cc);

        if( l_err == NULL )
        {
            // make sure the completion code is good, then read the bytes
            if( (l_cc == POWER_LIMIT_NOT_ACTIVE) ||
                    (l_cc == POWER_LIMIT_ACTIVE) )
            {
                // from the dcmi spec
                // byte 1   completion code
                // byte 2   0xDC
                // byte 3:4 reserved
                // byte 5   exception actions
                // byte 6:7 power limit
                // data[0] is pointing at byte 2 of the dcmi spec description
                // so our offsets will be off by two below
                o_powerLimit = data[5];
                o_powerLimit = ( o_powerLimit << 8 ) + data[4];

                // fetch the derating factor from the BMC, then apply it to
                // the value returned in the getPowerLimit command

                SENSOR::getSensorReadingData o_sensorData;

                // derating factor is held in the system target
                SENSOR::SensorBase(
                        TARGETING::SENSOR_NAME_DERATING_FACTOR,
                        NULL ).readSensorData( o_sensorData );

                // derate the power limit based on the returned value of the
                // sensor - derating factor is returned as a % value and is
                // stored in the event_status field.
                o_powerLimit = ( static_cast<uint64_t>(o_powerLimit) *
                                            o_sensorData.event_status)/100;

                TRACFCOMP(g_trac_ipmi,"Derating factor = %i",o_sensorData.event_status);
                TRACFCOMP(g_trac_ipmi,"Power limit = 0x%i",o_powerLimit);
                TRACFCOMP(g_trac_ipmi,"Power limit is %s", ((cc) ? "not active": "active"));

                // the completion code also tells us if the limit is active
                if(l_cc == POWER_LIMIT_ACTIVE )
                {
                    o_limitActive = true;
                }
            }
            else
            {
                TRACFCOMP(g_trac_ipmi,"bad completion code from BMC=0x%x",cc);

                /* @errorlog tag
                 * @errortype       ERRL_SEV_UNRECOVERABLE
                 * @moduleid        IPMI::MOD_IPMIDCMI
                 * @reasoncode      IPMI::RC_DCMI_CMD_FAILED
                 * @userdata1       BMC IPMI Completion code.
                 * @devdesc         Request to get power limit information
                 *                  failed
                 * @custdesc        The DCMI command to retrieve the power limit
                 *                  data from the BMC has failed, the user
                 *                  defined power limit cannot be applied.
                 *
                 */

                l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        IPMI::MOD_IPMIDCMI,
                        IPMI::RC_DCMI_CMD_FAILED,
                        static_cast<uint64_t>(cc),0, true);

                l_err->collectTrace(IPMI_COMP_NAME);

            }

            delete[] data;
        }

        return l_err;
    }

}; // end name space
