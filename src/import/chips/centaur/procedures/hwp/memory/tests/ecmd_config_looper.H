/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/ecmd_config_looper.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file ecmd_config_looper.H
/// @brief Abstraction around the eCMD Config Looper
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#ifndef MSS_ECMD_CONFIG_LOOPER_H_
#define MSS_ECMD_CONFIG_LOOPER_H_

#include <cstdarg>
#include <sys/types.h>
#include <unistd.h>

#include <croClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>

#include <ecmd_facade.H>

namespace mss
{
namespace ecmd
{

///
/// @class ecmd_config_looper
/// @brief Used to loop over ecmd targets.
///
class ecmd_config_looper
{

    public:
        ecmdLooperData iv_looper; ///< Used by ecmdConfigLooper for metadata info.
        uint32_t iv_rc; ///< Last eCmd return code value.

        ///
        /// @brief Constructor
        /// @param[in] i_target structure used to identify the "Top of Target Tree"
        ///
        ecmd_config_looper(ecmdChipTarget& i_target)
            : iv_rc(ecmdConfigLooperInit(i_target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, iv_looper))
        {

            if (iv_rc)
            {
                ecmd_outp(LERR, "Error Initializing chip loop\n");
            }
        }

        ///
        /// @brief Returns the current status of the looping mechansim
        /// @return returns the last status of the eCMD call
        ///
        uint32_t status()
        {
            return iv_rc;
        }

        ///
        /// @brief retrieves the next target
        /// @param[in,out] io_target current target in and upon a 0 return status will be filled in with
        /// the next target.
        /// @return the ecmd return code for the call
        ///
        uint32_t next(ecmdChipTarget& io_target)
        {
            iv_rc = ecmdConfigLooperNext(io_target, iv_looper);

            if(iv_rc)
            {
                if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
                {
                    ecmd_outp(LDBG, "Found eCMD Chip Target on proc k%d:n%d:s%d:p%02d:c%d chip type = %s %s\n",
                              io_target.cage,
                              io_target.node,
                              io_target.slot,
                              io_target.pos,
                              io_target.core,
                              io_target.chipType.c_str(),
                              io_target.chipUnitType.c_str() );
                }
            }

            return iv_rc;
        }
};


} /* ns ecmd */
} /* ns mss */

#endif // MSS_ECMD_CONFIG_LOOPER_H_
