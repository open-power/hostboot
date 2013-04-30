/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Mcs.C $           */
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

/** @file  prdfP8Mcs.C
 *  @brief Contains all the plugin code for the PRD P8 MCS
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>
#include <prdfGlobal.H>
#include <iipSystem.h>

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
int32_t Initialize( ExtensibleChip * i_mcsChip )
{
    // FIXME: Add proper initialization as per requirement
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, Initialize );

/**
 * @brief Check for and handle a Centaur Unit Checkstop
 * @param i_mcsChip An MCS chip.
 * @param i_sc Step Code Data structure
 * @return failure or success
 */
int32_t CheckCentaurCheckstop( ExtensibleChip * i_mcsChip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;

    do
    {
        // Skip if we're already at Unit Checkstop in SDC
        if (i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS))
            break;

        // Check MCIFIR[31] for presence of Centaur checkstop
        SCAN_COMM_REGISTER_CLASS * l_mcifir = i_mcsChip->getRegister("MCIFIR");
        l_rc = l_mcifir->Read();

        if (l_rc)
        {
            PRDF_ERR( "[CheckCentaurCheckstop] SCOM fail on 0x%08x rc=%x",
                      i_mcsChip->GetId(), l_rc);
            break;
        }

        if ( ! l_mcifir->IsBitSet(31) )  { break; }

        // Set Unit checkstop flag
        i_sc.service_data->SetFlag(ServiceDataCollector::UNIT_CS);
        i_sc.service_data->SetThresholdMaskId(0);

        // Set the cause attention type
        i_sc.service_data->SetCauseAttentionType(UNIT_CS);

        // Collect FFDC
        // FIXME: RTC: 63753 (CENT_XSTP_FFDC capture group still needs to be
        // populated with list of registers provided by Marc or Ken).
        i_mcsChip->CaptureErrorData(i_sc.service_data->GetCaptureData(),
                                    Util::hashString("CENT_XSTP_FFDC"));

        ExtensibleChip * l_cent = (ExtensibleChip *)
          systemPtr->GetChip(PlatServices::getConnected(
                                         i_mcsChip->GetChipHandle(),
                                         TARGETING::TYPE_MEMBUF)[0] );
        if (l_cent)
        {
            l_cent->CaptureErrorData(i_sc.service_data->GetCaptureData(),
                                     Util::hashString("CENT_XSTP_FFDC"));
        }

    } while (0);

    return l_rc;
}

/**
 * @brief Analysis code that is called before the main analyze() function.
 * @param i_mcsChip An MCS chip.
 * @param i_sc Step Code Data structure
 * @param o_analyzed TRUE if analysis has been done on this chip
 * @return failure or success
 */
int32_t PreAnalysis ( ExtensibleChip * i_mcsChip, STEP_CODE_DATA_STRUCT & i_sc,
                      bool & o_analyzed )
{
    o_analyzed = false;

    int32_t l_rc = SUCCESS;

    // Check for a Centaur Checkstop
    l_rc = CheckCentaurCheckstop(i_mcsChip, i_sc);

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Mcs, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mcsChip MCS chip
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mcsChip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;

    if (i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS))
    {
        ExtensibleChip * l_cent = (ExtensibleChip *)
          systemPtr->GetChip(PlatServices::getConnected(
                                           i_mcsChip->GetChipHandle(),
                                           TARGETING::TYPE_MEMBUF)[0] );
        if (l_cent)
        {
            // Mask attentions from the Centaur
            SCAN_COMM_REGISTER_CLASS * l_tpfirmask = NULL;
            SCAN_COMM_REGISTER_CLASS * l_nestfirmask = NULL;
            SCAN_COMM_REGISTER_CLASS * l_memfirmask = NULL;
            SCAN_COMM_REGISTER_CLASS * l_memspamask = NULL;

            l_tpfirmask = l_cent->getRegister("TP_CHIPLET_FIR_MASK");
            l_nestfirmask = l_cent->getRegister("NEST_CHIPLET_FIR_MASK");
            l_memfirmask = l_cent->getRegister("MEM_CHIPLET_FIR_MASK");
            l_memspamask = l_cent->getRegister("MEM_CHIPLET_SPA_MASK");

            l_tpfirmask->setAllBits(); l_rc |= l_tpfirmask->Write();
            l_nestfirmask->setAllBits(); l_rc |= l_nestfirmask->Write();
            l_memfirmask->setAllBits(); l_rc |= l_memfirmask->Write();
            l_memspamask->setAllBits(); l_rc |= l_memspamask->Write();
        }
    }
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, PostAnalysis );

} // end namespace Mcs
} // end namespace PRDF

