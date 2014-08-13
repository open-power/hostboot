/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatP8Ex.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfP8Ex.C
 *  @brief Contains all the plugin code for the PRD P8 EX chiplet
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfCalloutUtil.H>

namespace PRDF
{
namespace Ex
{
/**
 * @brief Set the cause attention type to UNIT_CS for further analysis.
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return SUCCESS
 */
int32_t SetCoreCheckstopCause( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    PRDF_ERR( "[SetCoreCheckstopCause] Unexpected attention in Hostboot: "
              "HUID=0x%08x", i_chip->GetId() );
    CalloutUtil::defaultError( i_sc );
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, SetCoreCheckstopCause);

/**
 * @brief No-op in hostboot
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t CheckCoreCheckstop( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & i_sc )
{
    return SUCCESS;

} PRDF_PLUGIN_DEFINE(Ex, CheckCoreCheckstop);

/**
 * @brief No-op in hostboot
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t MaskIfCoreCheckstop( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, MaskIfCoreCheckstop);

/**
 * @brief Restart Trace Arrays that have been stopped on error
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t RestartTraceArray( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, RestartTraceArray);

/**
 * @brief Handle an L3 UE
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t L3UE( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return SUCCESS;

} PRDF_PLUGIN_DEFINE(Ex, L3UE);

/**
 * @brief Handle an L3 CE
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t L3CE( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    // We can get these errors during hostboot, but will wait for runtime
    // to attempt repairs
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, L3CE);

/**
 * @brief Handle an L2 UE
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t L2UE( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, L2UE);

/**
 * @brief Handle an L2 CE
 * @param i_chip Ex chip.
 * @param i_sc Step Code data struct
 * @return PRD return code
 */
int32_t L2CE( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    // We can get these errors during hostboot, but will wait for runtime
    // to attempt repairs
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, L2CE);

/**
 * @brief Check if we're running in hostboot
 * @param i_chip Ex chip.
 * @param i_stepcode Step Code data struct
 * @return SUCCESS because this is the Hostboot file
 */
int32_t InHostboot( ExtensibleChip * i_chip,
                    STEP_CODE_DATA_STRUCT & i_stepcode )
{
    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, InHostboot);

/**
 * @brief check if both core CS and RE are on at the same time
 *        and core recoverable is set in COREFIRWOF
 * @param i_chip Ex chip.
 * @param i_stepcode Step Code data struct
 * @return SUCCESS in Hostboot since we don't want to analyze core CS
 */
int32_t CoreRePresent( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & i_stepcode )
{
    return SUCCESS;

} PRDF_PLUGIN_DEFINE(Ex, CoreRePresent);

} // end namespace Ex
} // end namespace PRDF
