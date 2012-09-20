/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfP8Mcs.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

/** @file  prdfP8Mcs.C
 *  @brief Contains all the plugin code for the PRD P8 MCS
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

namespace PRDF
{
namespace Mcs
{

/**
 * @brief  Plugin that initializes the MCS data bundle.
 * @param  i_mcsChip An MCS chip.
 * @return SUCCESS
 */
int32_t Initialize( PrdfExtensibleChip * i_mcsChip )
{
    // FIXME: Add proper initialization as per requirement
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, Initialize );

} // end namespace Mcs
} // end namespace PRDF

