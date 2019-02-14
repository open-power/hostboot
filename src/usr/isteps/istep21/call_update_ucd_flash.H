/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_update_ucd_flash.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef  __CALL_UPDATE_UCD_FLASH_H
#define  __CALL_UPDATE_UCD_FLASH_H

namespace POWER_SEQUENCER
{

namespace TI // Texas Instruments devices
{

namespace UCD // UCD* series
{
    /**
     *  @brief Updates the data flash of applicable Texas Instruments UCD
     *      power sequencer ASICs.
     */
    void call_update_ucd_flash();

} // End UCD namespace

} // End TI namespace

} // End POWER_SEQUENCER namespace

#endif
