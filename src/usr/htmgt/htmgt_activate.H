/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_activate.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef HTMGT_ACTIVATE_H
#define HTMGT_ACTIVATE_H

#include <stdint.h>
#include "htmgt_occ.H"
#include <errl/errlmanager.H>


// TODO RTC 118875
//#define SIMICS_TESTING


namespace HTMGT
{

    /**
     * @brief Wait for all OCCs to go to the target state
     *
     * @return  NULL if all OCCs reached target state, else error handle
     */
    errlHndl_t waitForOccState();


    /**
     * @brief Set active sensors for all OCCs so BMC can start communication
     *
     * @return  NULL if all sensors were updated, else error handle
     */
    errlHndl_t setOccActiveSensors();


    /**
     * @brief Sends the User selected Power Cap to the master OCC.
     */
    errlHndl_t sendOccUserPowerCap();


} // end namespace
#endif
