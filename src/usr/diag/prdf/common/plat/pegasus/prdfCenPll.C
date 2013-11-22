/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenPll.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

/** @file  prdfCenPLL.C
 *  @brief Contains all common plugin code for the Centaur PLL logic.
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

namespace PRDF
{

namespace Membuf
{

enum
{
    PLL_DETECT_CENT_NEST = 19,  // nest PLL error bit
    PLL_DETECT_CENT_MEM  = 20   // mem PLL error bit
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


} // end namespace Membuf

} // end namespace PRDF
