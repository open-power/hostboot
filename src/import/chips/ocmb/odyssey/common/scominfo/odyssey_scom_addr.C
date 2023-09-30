/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_scom_addr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
///
/// @file odyssey_scom_addr.C
/// @brief ODYSSEY chip unit SCOM address platform translation code
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB
///

// includes
#include "odyssey_scom_addr.H"

#define ODYSSEY_SCOM_ADDR_C

extern "C"
{
    /// See function description in header file

    // #####################################
    bool odyssey_scom_addr::isPervTarget()
    {
        bool l_pervTarget = false;

        if (getChipletId() <= 0x1)  // Allow PIB (0x00) and Perv chiplet (0x01)
        {
            if (getEndpoint() == ODY_PSCOM_ENDPOINT)            // 0x1
            {
                if ( (getRingId() == ODY_PSCOM_RING_ID) ||    // 0x0
                     (getRingId() == ODY_PERV_RING_ID) )    // 0x1
                {
                    l_pervTarget = true;
                }
            }
            else if (getEndpoint() == ODY_CLOCK_CTRL_ENDPOINT)  // 0x3
            {
                l_pervTarget = true;
            }
            // Check if Endpoint is a PERV endpoint
            else if ( (getEndpoint() == ODY_CHIPLET_CTRL_ENDPOINT) ||     // 0x0
                      (getEndpoint() == ODY_FIR_ENDPOINT)          ||     // 0x4
                      (getEndpoint() == ODY_THERMAL_ENDPOINT)      ||     // 0x5
                      (getEndpoint() == ODY_PCBSLV_ENDPOINT) )            // 0xF
            {
                if ( getRingId() == ODY_PSCOM_RING_ID)                    // 0x0
                {
                    l_pervTarget = true;
                }
            }
        }

        return l_pervTarget;
    }

    // #####################################
    uint8_t odyssey_scom_addr::getPervTargetInstance()
    {
        return getChipletId();
    }

    // #####################################
    bool odyssey_scom_addr::isOmiTarget()
    {
        bool l_omiTarget = false;

        if ( ( getRingId() == ODY_OMI0_RING_ID ||
               getRingId() == ODY_DLX_RING_ID ) && ( getChipletId() == ODY_MEM_CHIPLET_ID ) )
        {
            l_omiTarget = true;
        }

        return l_omiTarget;
    }

    // #####################################
    uint8_t odyssey_scom_addr::getOmiTargetInstance()
    {
        uint8_t l_instance = 0;
        return l_instance;
    }

    // #####################################
    bool odyssey_scom_addr::isMemportTarget()
    {
        bool l_memportTarget = false;

        if ( (getChipletId() == ODY_MEM_CHIPLET_ID) &&
             ( (getRingId() == ODY_MEMPORT0_RING_ID) ||
               (getRingId() == ODY_MEMPORT1_RING_ID) ||
               (getRingId() == ODY_MEMPORT0_PHY_RING_ID) ||
               (getRingId() == ODY_MEMPORT1_PHY_RING_ID) ))
        {
            l_memportTarget = true;
        }

        return l_memportTarget;
    }

    // #####################################
    uint8_t odyssey_scom_addr::getMemportTargetInstance()
    {
        uint8_t l_instance = 0;

        if (getRingId() == ODY_MEMPORT1_RING_ID)
        {
            l_instance = 1;
        }

        if (getRingId() == ODY_MEMPORT1_PHY_RING_ID)
        {
            l_instance = 1;
        }

        return l_instance;
    }


} // extern "C"

#undef ODYSSEY_SCOM_ADDR_C
