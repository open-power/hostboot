/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatP8Ex.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

} // end namespace Ex
} // end namespace PRDF
