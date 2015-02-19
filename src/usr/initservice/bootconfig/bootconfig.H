/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfig.H $                 */
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
#ifndef __INITSERVICE_BOOTCONFIG_H
#define __INITSERVICE_BOOTCONFIG_H

#include <initservice/bootconfigif.H>
#include <errl/errlentry.H>
namespace INITSERVICE
{
namespace BOOTCONFIG
{

    extern uint8_t CURRENT_CONFIG_VERSION;

/**
 *  @brief  BootConfig Class
 *     This is the base class used to configure hostboot via external methods,
 *     an example is using a set of shared registers between hostboot and the
 *     BMC.  The base class is a no-op, any actual configuration should be done
 *     in a subclass - see AST2400BootConfig as an example.

 */
    class BootConfig
    {
        public:

            BootConfig();

            virtual ~BootConfig();

    /**
     * @brief Read and process the Boot configuration info specific to this
     *        platform. - base class implementation is a no-op
     */
           virtual errlHndl_t readAndProcessBootConfig();

    /**
     * @brief Read the istep control data from the platform specific location
     *          NOTE: base class implemetation is a no-op
     *
     * @param[out] o_istepInfo - ISTEP control structure containing the
     *                           next control action as well as next istep
     *                           information.
     */
           virtual errlHndl_t readIstepControl(
                                        BOOTCONFIG::istepControl_t & o_info);

     /**
     * @brief Write the istep control data
     *          NOTE: base class implemetation is a no-op
     *
     * @param[in] i_istepInfo - ISTEP control structure containing the
     *                           next control action
     */

           virtual errlHndl_t writeIstepControl(
                                        BOOTCONFIG::istepControl_t   i_info );

    };


};// end namespace
};

#endif


