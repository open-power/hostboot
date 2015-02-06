/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/disableSW.H $                                    */
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
#ifndef __HANDLESPECIALWAKEUP_H
#define __HANDLESPECIALWAKEUP_H

#include <stdint.h>

extern "C"
{
/**
 * @brief This function handles the enable and disable of the special
 *        wakeup that allows scom operations on idle cores.
 *
 * @param[in] i_exTarget      - EX Target core
 * @param[in] i_enableDisable - enable (true), disable (false)
 *
 * @return errlHndl_t         - error handle
 */
errlHndl_t handleSpecialWakeup(TARGETING::Target* i_exTarget,
                               bool i_enableDisable);
}

#endif
