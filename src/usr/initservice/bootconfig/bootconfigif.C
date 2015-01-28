/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfigif.C $               */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include <lpc/lpcif.H>
#include <devicefw/userif.H>
#include <config.h>
#include <errl/errlentry.H>
#include <initservice/bootconfigif.H>
#include "bootconfig.H"
#include "bootconfig_ast2400.H"
#include <config.h>

namespace INITSERVICE
{
namespace BOOTCONFIG
{
    enum
    {
        UNINITIALIZED = 0xFE,
    };

    uint8_t CURRENT_CONFIG_VERSION = UNINITIALIZED;

    // declare storage for isteps_trace!
    trace_desc_t * g_bc_trace = NULL;

    TRAC_INIT(&g_bc_trace, "BOOT_CFG", 2*KILOBYTE);

    class ConfigFactory
    {
        public:

            ~ConfigFactory(){};

            static BootConfig&  getConfigObject( uint8_t config_version )
            {
                {
                    #if CONFIG_BMC_AST2400
                    return Singleton<AST2400BootConfig>::instance();
                    #else
                    return Singleton<BootConfig>::instance();
                    #endif
                }
            }

    private:
    ConfigFactory(){};

    };


    errlHndl_t readAndProcessBootConfig()
    {
        return ConfigFactory::getConfigObject(
                            CURRENT_CONFIG_VERSION).readAndProcessBootConfig();
    }

    errlHndl_t readIstepControl( BOOTCONFIG::istepControl_t & o_stepInfo )
    {
        return ConfigFactory::getConfigObject(
                        CURRENT_CONFIG_VERSION ).readIstepControl(o_stepInfo);
    }

    errlHndl_t writeIstepControl( BOOTCONFIG::istepControl_t & i_stepInfo )
    {
        return ConfigFactory::getConfigObject(
                        CURRENT_CONFIG_VERSION ).writeIstepControl(i_stepInfo);
    }

};
};
