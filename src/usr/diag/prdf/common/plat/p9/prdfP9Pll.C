/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Pll.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/**
 * @file prdfP9PLL.C
 * @brief chip Plug-in code for proc pll support
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfBitString.H>
#include <iipscr.h>
#include <prdfPlatServices.H>
#include <prdfErrlUtil.H>
#include <iipSystem.h>
#include <prdfGlobal_common.H>
#include <UtilHash.H>
#include <prdfFsiCapUtil.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{

// PLL detect bits in TPLFIR
enum
{
    PLL_UNLOCK = 21,
    OSC_SW_SYS_REF = 36,
    OSC_SW_MF_REF  = 37,
};

/**
  * @brief Query the PLL chip for a PLL error on P9
  * @param  i_chip P9 chip
  * @param o_result set to true in the presence of PLL error
  * @returns Failure or Success of query.
  * @note
  */
int32_t QueryPll( ExtensibleChip * i_chip,
                        bool & o_result)
{
    #define PRDF_FUNC "[Proc::QueryPll] "

    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR =
                i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIRmask =
                i_chip->getRegister("TP_LFIR_MASK");

    do
    {
        rc = TP_LFIR->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR read failed"
                     "for 0x%08x", i_chip->getHuid());
            break;
        }

        rc = TP_LFIRmask->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_MASK read failed"
                     "for 0x%08x", i_chip->getHuid());
            break;
        }

        if ( ((! TP_LFIRmask->IsBitSet(PLL_UNLOCK)) &&
             TP_LFIR->IsBitSet(PLL_UNLOCK))     ||
             ((! TP_LFIRmask->IsBitSet(OSC_SW_SYS_REF)) &&
             TP_LFIR->IsBitSet(OSC_SW_SYS_REF)) ||
             ((! TP_LFIRmask->IsBitSet(OSC_SW_MF_REF)) &&
             TP_LFIR->IsBitSet(OSC_SW_MF_REF)) )

        {
            o_result = true;
        }

    } while(0);

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC "failed for proc: 0x%.8X",
                 i_chip->getHuid());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, QueryPll );

/**
  * @brief  Clear the PLL error for P9 Plugin
  * @param  i_chip P9 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  */
int32_t ClearPll( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::ClearPll] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->getPrimaryAttnType())
    {
        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIRand =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIRand->setAllBits();
        TP_LFIRand->ClearBit(PLL_UNLOCK);
        TP_LFIRand->ClearBit(OSC_SW_SYS_REF);
        TP_LFIRand->ClearBit(OSC_SW_MF_REF);

        rc = TP_LFIRand->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_AND write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, ClearPll );

/**
  * @brief Mask the PLL error for P9 Plugin
  * @param  i_chip P9 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPll( ExtensibleChip * i_chip,
                 STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;
    SCAN_COMM_REGISTER_CLASS * tpmask_or =
        i_chip->getRegister("TP_LFIR_MASK_OR");
    tpmask_or->clearAllBits();
    tpmask_or->SetBit(PLL_UNLOCK);
    tpmask_or->SetBit(OSC_SW_SYS_REF);
    tpmask_or->SetBit(OSC_SW_MF_REF);

    rc = tpmask_or->Write();
    if (rc != SUCCESS)
    {
        PRDF_ERR("[Proc::MaskPll] TP_LFIR_AND write failed"
                 "for chip: 0x%08x", i_chip->getHuid());
    }

    return rc;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, MaskPll );

/**
 * @brief   capture additional PLL FFDC
 * @param   i_chip   P9 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t capturePllFfdc( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Proc::capturePllFfdc] "

    // Add FSI status reg
    PLL::captureFsiStatusReg( i_chip, io_sc );

    // Add EX scom data
    TargetHandleList exList = getConnected(i_chip->getTrgt(), TYPE_CORE);
    ExtensibleChip * exChip;
    TargetHandleList::iterator itr = exList.begin();
    for( ; itr != exList.end(); ++itr)
    {
        exChip = (ExtensibleChip *)systemPtr->GetChip(*itr);
        if( NULL == exChip ) continue;

        exChip->CaptureErrorData(
                io_sc.service_data->GetCaptureData(),
                Util::hashString("PllFIRs"));
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, capturePllFfdc );


} // end namespace Proc

} // end namespace PRDF
