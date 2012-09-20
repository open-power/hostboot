/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfP8Proc.C $                 */
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

/** @file  prdfP8Proc.C
 *  @brief Contains all the plugin code for the PRD P8 Proc
 */
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

namespace PRDF
{
namespace Proc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Mba data bundle.
 * @param  i_chip P8 chip.
 * @return SUCCESS
 */
int32_t Initialize( PrdfExtensibleChip * i_chip )
{
    // FIXME: Add proper initialization as per requirement
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, Initialize );

/**
 * @fn CheckForRecovered
 * @brief Used when the chip has a CHECK_STOP attention to check for the
 * presence of recovered errors.
 */
int32_t CheckForRecovered(PrdfExtensibleChip * i_chip,
                          bool & o_hasRecovered)
{
    //FIXME: need to fully implement for P8
    o_hasRecovered = false;

    return SUCCESS;
} PRDF_PLUGIN_DEFINE( Proc, CheckForRecovered );



//------------------------------------------------------------------------------
/**
 * @fn prdCheckForRecoveredSev
 * @brief Used when the chip is queried, by the fabric domain, for RECOVERED
 * attentions to assign a severity to the attention for sorting.
 * @param[in]   i_chip - P8 chip
 * @param[out]  o_sev - Priority order (lowest to highest):
 *  1 - Core chiplet checkstop
 *  2 - Core chiplet error
 *  3 - PCB chiplet error (TOD logic)
 *  4 - Other error
 *  5 - Memory controller chiplet
 *
 * @return SUCCESS
 *
 */
int32_t CheckForRecoveredSev(PrdfExtensibleChip * i_chip,
                             uint32_t & o_sev)
{
    //FIXME: need to fully implement for P8
    o_sev = 1;

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Proc, CheckForRecoveredSev );

/** @func GetCheckstopInfo
 *  To be called from the fabric domain to gather Checkstop information.  This
 *  information is used in a sorting algorithm.
 *
 *  This is a plugin function: GetCheckstopInfo
 *
 *  @param i_chip - The chip.
 *  @param o_wasInternal - True if this chip has an internal checkstop.
 *  @param o_externalChips - List of external fabrics driving checkstop.
 *  @param o_wofValue - Current WOF value (unused for now).
 */
int32_t GetCheckstopInfo(PrdfExtensibleChip * i_chip,
                   bool & o_wasInternal,
                   TARGETING::TargetHandleList & o_externalChips,
                   uint64_t & o_wofValue)
{
    // Clear parameters.
    o_wasInternal = true; //FIXME: default to true until fabric sorting is done
    o_externalChips.erase(o_externalChips.begin(), o_externalChips.end());
    o_wofValue = 0;

    // FIXME: this will need to implement under fabric sorting algo

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Proc, GetCheckstopInfo );

} // end namespace Proc
} // end namespace PRDF
