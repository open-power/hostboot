/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Ex.C $            */
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

#include <iipglobl.h>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

namespace PRDF
{
namespace Ex
{

/**
 * @brief Set the cause attention type to UNIT_CS for further analysis.
 * @param i_chip Ex chip.
 * @param i_stepcode Step Code data struct
 * @return SUCCESS
 */
int32_t SetCoreCheckstopCause( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_stepcode )
{
    i_stepcode.service_data->SetCauseAttentionType(UNIT_CS);

    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Ex, SetCoreCheckstopCause);

/**
 * @brief Determine if there is a core unit checkstop and perform appropriate
 * action.
 *
 * 1) Set error to predictive / at threshold.
 * 2) Wait for PHYP to evacuate core.
 * 3) Terminate if PHYP doesn't evacuate.
 * @param i_chip Ex chip.
 * @param i_stepcode Step Code data struct
 * @return PRD return code
 */
int32_t CheckCoreCheckstop( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & i_stepcode )
{
    int32_t l_rc = SUCCESS;
#ifndef __HOSTBOOT_MODULE
    static const uint32_t CORECS_SECONDS_TO_SLEEP = 10;

    do
    {
        // Skip if we're already at core checkstop in SDC.
        if (i_stepcode.service_data->GetFlag(ServiceDataCollector::UNIT_CS))
            break;

        // Read core checkstop bit in chiplet RER.
        SCAN_COMM_REGISTER_CLASS * l_coreRER
                                    = i_chip->getRegister("EX_CHIPLET_RE_FIR");
        l_rc = l_coreRER->ForceRead();
        if (SUCCESS != l_rc)
            break;

        // Check core checkstop bit.
        if (!l_coreRER->IsBitSet(0))
            break;

        // We must be at core checkstop.
        i_stepcode.service_data->SetFlag(ServiceDataCollector::UNIT_CS);
        i_stepcode.service_data->SetThresholdMaskId(0);

        SCAN_COMM_REGISTER_CLASS * l_coreHMEER
                                            = i_chip->getRegister("COREHMEER");
        l_rc = l_coreHMEER->Read();
        if (SUCCESS != l_rc)
            break;

        // Check if PHYP has enabled core checkstop (HMEER[0]).
        if (!l_coreHMEER->IsBitSet(0))
        {
            // FIXME - (RTC: 51693) isCM_FUNCTIONAL not available yet
            //if (!prdfHomServices::isCM_FUNCTIONAL(i_chip->GetChipEnum()))
            //{
            // Core checkstop not enabled, terminate.
            i_stepcode.service_data->SetFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, be sure to get SH content.
            i_stepcode.service_data->SetDump(CONTENT_SH,
                                             i_chip->GetChipHandle());
            //}
            break;
        };

        // Wait for PHYP evacuation by checking SPATTN register.
        SCAN_COMM_REGISTER_CLASS * l_coreSPAttn
                                            = i_chip->getRegister("SPATTN_0");

        bool l_spAttnCleared = false;
        uint32_t l_secondsToSleep = CORECS_SECONDS_TO_SLEEP;

        do
        {
            // Don't sleep on first time through.
            if (l_secondsToSleep != CORECS_SECONDS_TO_SLEEP)
            {
                sleep(1);
            }
            l_secondsToSleep--;

            l_rc = l_coreSPAttn->ForceRead();
            if (SUCCESS == l_rc)
            {
                if (!l_coreSPAttn->IsBitSet(2))
                {
                    l_spAttnCleared = 1;
                }
            }
        } while ((l_secondsToSleep != 0) && (!l_spAttnCleared));

        // If we weren't able to read the register, abort.
        //    Don't want to terminate if FSP couldn't read register.
        if (SUCCESS != l_rc)
            break;

        // If we waited and never cleared, terminate machine.
        if (!l_spAttnCleared)
        {
            // FIXME - (RTC: 51693) isCM_FUNCTIONAL not available yet
            //if (!prdfHomServices::isCM_FUNCTIONAL(i_chip->GetChipEnum()))
            //{
            i_stepcode.service_data->SetFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, be sure to get SH content.
            i_stepcode.service_data->SetDump(CONTENT_SH,
                                             i_chip->GetChipHandle());

            //}
        };

    } while (0);
#endif
    return l_rc;

} PRDF_PLUGIN_DEFINE(Ex, CheckCoreCheckstop);

/**
 * @brief Mask errors from the core chiplet
 * @param i_chip Ex chip.
 * @param i_stepcode Step Code data struct
 * @return PRD return code
 */
int32_t MaskIfCoreCheckstop( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_stepcode )
{
    int32_t l_rc = SUCCESS;

    // Only mask if Proc CS present.
    if (! i_stepcode.service_data->IsProcCoreCS() ||
        i_stepcode.service_data->GetCauseAttentionType() == MACHINE_CHECK)
        return SUCCESS;

    // Get core global mask register.
    SCAN_COMM_REGISTER_CLASS * l_coreFirMask =
      i_chip->getRegister("EX_CHIPLET_FIR_MASK");

    // Read value.
    l_rc = l_coreFirMask->Read();

    if (SUCCESS == l_rc)
    {
        // Mask bit 4.
        l_coreFirMask->SetBit(4);
        l_rc = l_coreFirMask->Write();
    }

    return l_rc;
} PRDF_PLUGIN_DEFINE(Ex, MaskIfCoreCheckstop);

} // end namespace Ex
} // end namespace PRDF
