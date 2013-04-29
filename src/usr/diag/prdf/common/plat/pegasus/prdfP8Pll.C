/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Pll.C $           */
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

/**
 * @file prdfP8PLL.C
 * @brief chip Plug-in code for proc pll support
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfBitString.H>
#include <iipscr.h>
#include <prdfPlatServices.H>

namespace PRDF
{

namespace Proc
{


enum
{
    PLL_DETECT_P8 = 19,  //Bit position of the error bit.
};

/**
  * @brief Query the PLL chip for a PLL error on P8 Plugin
  * @param  i_chip P8 chip
  * @param o_result set to true in the presence of PLL error
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

        if(TP_LFIR->IsBitSet(PLL_DETECT_P8) &&
           !(TP_LFIRmask->IsBitSet(PLL_DETECT_P8)))
        {
            o_result = true;
        }

    } while(0);

    return rc;

}
PRDF_PLUGIN_DEFINE( Proc, QueryPll );

/**
  * @brief Clear the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
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
        TP_LFIR->ClearBit(PLL_DETECT_P8);
        rc = TP_LFIR->Write();
    }

    return rc;

}
PRDF_PLUGIN_DEFINE( Proc, ClearPll );

/**
  * @brief Mask the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param Output Unused.
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPll( ExtensibleChip * i_chip,void * unused)
{
    int32_t rc = SUCCESS;
    SCAN_COMM_REGISTER_CLASS * tpmask_or = i_chip->getRegister("TP_LFIR_MASK_OR");
    tpmask_or->clearAllBits();
    tpmask_or->SetBit(PLL_DETECT_P8);
    rc = tpmask_or->Write();
    return rc;

}
PRDF_PLUGIN_DEFINE( Proc, MaskPll );

/**
 * @brief Adds to the callout list for P8 PLL errors.
 * @param  i_chip P8 chip.
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
PRDF_PLUGIN_DEFINE( Proc, CalloutPll );


} // end namespace Proc

} // end namespace PRDF
