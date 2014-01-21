/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatP8Proc.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file  prdfPlatP8Proc.C
 *  @brief Contains the hostboot specific plugin code for P8 Proc
 */


#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfCalloutUtil.H>

using namespace TARGETING;

namespace PRDF
{

namespace Proc
{

/**
 * @brief Call  HWP and set the right dump type
 * @param  i_chip P8 chip
 * @param  i_sc   The step code data struct
 * @returns Failure or Success
 * @note
 */
int32_t analyzeMpIPL( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    PRDF_ERR( "analyzeMpIPL functionality not supported during hostboot: "
               "PROC = 0x%08x", i_chip->GetId() );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, analyzeMpIPL );


/**
 * @brief Handle SLW Malfunction alert
 * @param i_chip P8 chip
 * @param  i_sc   The step code data struct
 * @returns Failure or Success
 * @note
 */
int32_t slwRecovery( ExtensibleChip * i_chip,
                     STEP_CODE_DATA_STRUCT & i_sc )
{
    PRDF_ERR( "slwRecovery functionality not supported during hostboot: "
               "PROC = 0x%08x", i_chip->GetId() );
    CalloutUtil::defaultError( i_sc );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, slwRecovery );

}//namespace Proc ends

}//namespace PRDF ends
