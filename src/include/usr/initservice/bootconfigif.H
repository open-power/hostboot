/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/bootconfigif.H $                  */
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
#ifndef __INITSERVICE_BOOTCONFIGIF_H
#define __INITSERVICE_BOOTCONFIGIF_H

#include <trace/interface.H>
#include <errl/errlentry.H>

extern trace_desc_t *g_trac_initsvc;
namespace INITSERVICE
{
namespace BOOTCONFIG
{
    /**
     * @brief  Identifier for the first version layout of the SIO register boot
     *         flags.
     */
    const uint8_t BOOT_FLAGS_VERSION_1 = 0x42;

    extern uint8_t CURRENT_CONFIG_VERSION;

    typedef struct
    {
        uint8_t istepControl;
        uint8_t istepMajorNumber;
        uint8_t istepMinorNumber;

    }istepControl_t;

    // This function will call the actual config class created, or the base
    // class if non has been created.
    errlHndl_t readAndProcessBootConfig();

    // Calls the actual subclass or base class if no config class has been
    // created
    errlHndl_t readIstepControl( BOOTCONFIG::istepControl_t & o_info );

    // Calls the actual subclass or base class if no config class has been
    // created
    errlHndl_t writeIstepControl( BOOTCONFIG::istepControl_t &  i_info );

};
};// end namespace
#endif


