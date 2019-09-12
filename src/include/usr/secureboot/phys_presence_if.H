/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/phys_presence_if.H $               */
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
/**
 * @file phys_presence_if.H
 *
 * @brief Interfaces to Detect and Open Physical Presence Windows
 *
 */
#ifndef __PHYS_PRESENCE_H
#define __PHYS_PRESENCE_H
// -----------------------------------------------
// Includes
// -----------------------------------------------

#include <errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <config.h>

namespace SECUREBOOT
{
    /**
     * @brief Checks if the Physical Presence Window was opened and if
     *        Physical Presence was asserted.
     *
     * @post  Will ensure the window is closed at the end of the function
     *
     * @return errlHndl_t nullptr on success; non-nullptr on error.
     */
    errlHndl_t detectPhysPresence(void);

    /**
     * @brief Handle Physical Presence Window first checks to see if a physical
     *        presence window should be opened.  Then, if necessary, it sets up
     *        the physical presence detect circuit and then shuts down the
     *        system.
     *
     * @post If successful, this function will shutdown the system
     *
     * @return errlHndl_t nullptr on success; non-nullptr on error.
     */
    errlHndl_t handlePhysPresenceWindow(void);

} // namespace SECUREBOOT


#endif // __PHYS_PRESENCE_H
