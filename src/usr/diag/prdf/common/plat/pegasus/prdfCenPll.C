/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenPll.C $          */
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

/**
 * @file prdfCenPLL.C
 * @brief chip Plug-in code for centaur pll support
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfBitString.H>
#include <iipscr.h>
#include <prdfPlatServices.H>
#include <iipglobl.h>
#include <iipSystem.h>

namespace PRDF
{

namespace Membuf
{


enum
{
    PLL_DETECT_CENT_MEM  = 18,  // mem PLL error bit
    PLL_DETECT_CENT_NEST = 19   // nest PLL error bit
};

/**
  * @brief Query the PLL chip for a PLL error on Centaur Plugin
  * @param  i_chip Centaur chip
  * @param  o_result set to true in the presence of PLL error
  * @returns Failure or Success of query.
  * @note
  */
int32_t QueryPll( ExtensibleChip * i_chip,
                        bool & o_result)
{
    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR = i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIRmask = i_chip->getRegister("TP_LFIR_MASK");

    do
    {
        rc = TP_LFIR->Read();
        if (rc != SUCCESS) break;

        rc = TP_LFIRmask->Read();
        if (rc != SUCCESS) break;

        if((TP_LFIR->IsBitSet(PLL_DETECT_CENT_MEM)  &&
            !(TP_LFIRmask->IsBitSet(PLL_DETECT_CENT_MEM))) ||
           (TP_LFIR->IsBitSet(PLL_DETECT_CENT_NEST) &&
            !(TP_LFIRmask->IsBitSet(PLL_DETECT_CENT_NEST))))
        {
            o_result = true;
        }

    } while(0);

    return rc;

}
PRDF_PLUGIN_DEFINE( Membuf, QueryPll );

/**
  * @brief Clear the PLL error for Centaur Plugin
  * @param  i_chip Centaur chip
  * @param  i_sc   The step code data struct.
  * @returns Failure or Success of query.
  * @note
  */
int32_t ClearPll( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        SCAN_COMM_REGISTER_CLASS * TP_LFIR = i_chip->getRegister("TP_LFIR_AND");
        TP_LFIR->setAllBits();
        TP_LFIR->ClearBit(PLL_DETECT_CENT_MEM);
        TP_LFIR->ClearBit(PLL_DETECT_CENT_NEST);
        rc = TP_LFIR->Write();
    }

    return rc;

}
PRDF_PLUGIN_DEFINE( Membuf, ClearPll );

/**
  * @brief Mask the PLL error for Centaur Plugin
  * @param  i_chip Centaur chip
  * @param Output Unused.
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPll( ExtensibleChip * i_chip,void * unused)
{
    int32_t rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR = i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIR_or = i_chip->getRegister("TP_LFIR_MASK_OR");

    rc = TP_LFIR->Read();
    TP_LFIR_or->clearAllBits();

    if(TP_LFIR->IsBitSet(PLL_DETECT_CENT_MEM))  TP_LFIR_or->SetBit(PLL_DETECT_CENT_MEM);
    if(TP_LFIR->IsBitSet(PLL_DETECT_CENT_NEST)) TP_LFIR_or->SetBit(PLL_DETECT_CENT_NEST);

    rc |= TP_LFIR_or->Write();

    return rc;

}
PRDF_PLUGIN_DEFINE( Membuf, MaskPll );

/**
 * @brief Adds to the callout list for Centaur PLL errors.
 * @param  i_chip Centaur chip.
 * @param  i_sc     The step code data struct.
 * @return SUCCESS.
 */
int32_t CalloutPll( ExtensibleChip * i_chip,
                    STEP_CODE_DATA_STRUCT & i_sc )
{
    // FIXME: RTC: 51628 will address clock target issue
    // set Level 2 callout since we don't have clock target yet
    i_sc.service_data->SetCallout( NextLevelSupport_ENUM );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, CalloutPll );

/**
  Send a PLL error message on Centaur  Plugin.
  @param i_chip the chip that this is for.
  @param i_sc service data.
  @returns Failure Or Success of message call.
  @note
   */
int32_t PllPostAnalysis( ExtensibleChip * i_chip,
                    STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;
    int32_t l_rc = SUCCESS;

// Need to send MBA Skip Message to MDIA in Hostboot only
#ifdef __HOSTBOOT_MODULE

    TargetHandle_t l_cenHandle = i_chip->GetChipHandle();

    do
    {
        TargetHandleList list = PlatServices::getConnected(l_cenHandle , TYPE_MBA);
        if ( 0 == list.size() )
        {
            PRDF_ERR("[PllPostAnalysis] failed to get MBAs connected to this "
                     "Membuf: 0x%08x", PlatServices::getHuid(l_cenHandle) );
            l_rc = FAIL;
            break;
        }

        for (TargetHandleList::iterator mbaIt = list.begin(); mbaIt != list.end(); ++mbaIt)
        {
            // Get the extensible chip for this mba
            ExtensibleChip *l_mbaChip = (ExtensibleChip *)systemPtr->GetChip(*mbaIt);

            //Check to make sure we are at threshold and have something garded.
            if( (NULL != l_mbaChip) &&
                (i_sc.service_data->IsAtThreshold()) &&
                (i_sc.service_data->QueryGard() != GardResolution::NoGard) )
            {
                //Call the Skip Maintanence Command on this mba
                ExtensibleChipFunction * l_skipMbaMsg =
                    l_mbaChip->getExtensibleFunction("SkipMbaMsg", true);

                // This call will return an error if it doesn't complete.
                // Don't fail on error.  keep going.
                l_rc |= (*l_skipMbaMsg)(l_mbaChip,
                        PluginDef::bindParm<STEP_CODE_DATA_STRUCT &>(i_sc));
            }
        }

    } while(0);

#endif // ifdef __HOSTBOOT_MODULE

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Membuf, PllPostAnalysis );


} // end namespace Membuf

} // end namespace PRDF
