/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatP8Proc.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/**
 * @brief   Callout Peer PSI connected to given Proc target
 * @param   i_chip P8 chip
 * @param   i_sc   The step code data struct
 * @returns Failure or Success
 * @note    A NOP version of plugin required by FSP PRDF
 */
int32_t calloutPeerPsiBusTgt( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    PRDF_ERR( "[Proc::calloutPeerPsiBusTgt]  unexpected call: PSI target not "
              "supported in hostboot PROC = 0x%08x", i_chip->GetId() );

    CalloutUtil::defaultError( i_sc );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, calloutPeerPsiBusTgt );

}//namespace Proc ends

}//namespace PRDF ends
