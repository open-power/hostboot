/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlat.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __HWAS_PLAT_H
#define __HWAS_PLAT_H

/**
 *  @file hwas/hwasPlat.H
 *  @brief hostboot platform specific HWAS functions
 */

namespace HWAS
{

/**
 * @brief   hwasChangeDetection   hostboot function
 *
 *  This routine will do 'what is needed' to see if any hardware has
 *      changed (ie, look at ECID or serial numbers..)
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t hwasChangeDetection();

/**
 * @brief   hwasPLDDetection   hostboot function
 *
 *  This routine will do 'what is needed' to see if there were any
 *      Power Line Disturbance (PLD) issues
 *
 * @param  none
 *
 * @return bool     true if there were PLD issues, false otherwise
 */
bool hwasPLDDetection();

}

#endif // __HWAS_PLAT_H
