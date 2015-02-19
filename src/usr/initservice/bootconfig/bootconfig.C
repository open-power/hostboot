/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfig.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include <lpc/lpcif.H>
#include <devicefw/userif.H>
#include <config.h>
#include <errl/errlentry.H>
#include "bootconfig.H"

namespace INITSERVICE
{
namespace BOOTCONFIG
{

    // declare storage for config trace
    extern trace_desc_t * g_bc_trace;


        BootConfig::BootConfig()
        {};

        BootConfig::~BootConfig()
        {};

        errlHndl_t BootConfig::readAndProcessBootConfig()
        {
            TRACFCOMP(g_bc_trace, "readAndProcessBootConfig() - Default version called no-op");
            return NULL;
        }

        errlHndl_t BootConfig::readIstepControl(istepControl_t & o_stepInfo)
        {
            TRACFCOMP(g_bc_trace, "readIstepControl() - Default version called no-op");
            return NULL;
        }

        errlHndl_t BootConfig::writeIstepControl( istepControl_t  i_stepInfo)
        {
            TRACFCOMP(g_bc_trace, "writeIstepControl() - Default version called no-op");
            return NULL;
        }
};
}; // end namespace
