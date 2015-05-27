/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenPll.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/** @file  prdfCenPLL.C
 *  @brief Contains all common plugin code for the Centaur PLL logic.
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfFsiCapUtil.H>

namespace PRDF
{

using namespace PLL;
using namespace PlatServices;

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
    #define PRDF_FUNC "[Membuf::QueryPll] "

    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR = i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIRmask = i_chip->getRegister("TP_LFIR_MASK");

    do
    {
        rc = TP_LFIR->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR read failed"
                 "for 0x%08x", i_chip->GetId());
            break;
        }

        rc = TP_LFIRmask->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_MASK read failed"
                 "for 0x%08x", i_chip->GetId());
            break;
        }

        if((TP_LFIR->IsBitSet(PLL_DETECT_CENT_MEM)  &&
            !(TP_LFIRmask->IsBitSet(PLL_DETECT_CENT_MEM))) ||
           (TP_LFIR->IsBitSet(PLL_DETECT_CENT_NEST) &&
            !(TP_LFIRmask->IsBitSet(PLL_DETECT_CENT_NEST))))
        {
            o_result = true;
        }

    } while(0);

    return rc;

    #undef PRDF_FUNC
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
    #define PRDF_FUNC "[Membuf::ClearPll] "
    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        SCAN_COMM_REGISTER_CLASS * TP_LFIR = i_chip->getRegister("TP_LFIR_AND");
        TP_LFIR->setAllBits();
        TP_LFIR->ClearBit(PLL_DETECT_CENT_MEM);
        TP_LFIR->ClearBit(PLL_DETECT_CENT_NEST);
        rc = TP_LFIR->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_AND write failed"
                 "for 0x%08x", i_chip->GetId());
        }
    }

    return rc;

    #undef PRDF_FUNC
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
    #define PRDF_FUNC "[Membuf::MaskPll] "
    int32_t rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR_maskOr =
             i_chip->getRegister("TP_LFIR_MASK_OR");

    TP_LFIR_maskOr->clearAllBits();

    TP_LFIR_maskOr->SetBit(PLL_DETECT_CENT_MEM);
    TP_LFIR_maskOr->SetBit(PLL_DETECT_CENT_NEST);

    rc = TP_LFIR_maskOr->Write();
    if (rc != SUCCESS)
    {
        PRDF_ERR(PRDF_FUNC "TP_LFIR_MASK_OR write failed"
                 "for 0x%08x", i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, MaskPll );

/**
 * @brief   capture additional PLL FFDC
 * @param   i_chip   Membuf chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t capturePllFfdc( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Membuf::capturePllFfdc] "

    // Add FSI status reg
    captureFsiStatusReg( i_chip, io_sc );

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, capturePllFfdc );


} // end namespace Membuf

} // end namespace PRDF
