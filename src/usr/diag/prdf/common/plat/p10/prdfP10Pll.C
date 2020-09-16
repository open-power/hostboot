/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Pll.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 * @file prdfP10PLL.C
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
#include <prdfP10Pll.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace PLL;

namespace Proc
{

// PLL detect bits in TPLFIR
enum
{
    PLL_UNLOCK = 21,
    OSC_SW_SYS_REF = 36,
    OSC_SW_MF_REF  = 37,
};

void getChpltList ( ExtensibleChip * i_chip,
                    TARGETING::TYPE i_chpltType,
                    const char * &o_errRegStr,
                    const char * &o_cfgRegStr,
                    ExtensibleChipList & o_chpltList )
{
    #define PRDF_FUNC "[Proc::getChpltList ]"
    switch (i_chpltType)
    {
        case TYPE_PROC:
            o_errRegStr = "TP_ERROR_REG";
            o_cfgRegStr = "TP_CONFIG_REG";
            break;
        case TYPE_OBUS:
            o_errRegStr = "OBUS_ERROR_REG";
            o_cfgRegStr = "OBUS_CONFIG_REG";
            break;
        case TYPE_XBUS:
            o_errRegStr = "XBUS_ERROR_REG";
            o_cfgRegStr = "XBUS_CONFIG_REG";
            break;
        case TYPE_PEC:
            o_errRegStr = "PCI_ERROR_REG";
            o_cfgRegStr = "PCI_CONFIG_REG";
            break;
        case TYPE_MC:
            o_errRegStr = "MC_ERROR_REG";
            o_cfgRegStr = "MC_CONFIG_REG";
            break;
        case TYPE_EQ:
            o_errRegStr = "EQ_ERROR_REG";
            o_cfgRegStr = "EQ_CONFIG_REG";
            break;
        case TYPE_CORE:
            o_errRegStr = "EC_ERROR_REG";
            o_cfgRegStr = "EC_CONFIG_REG";
            break;
        default:
            PRDF_ERR(PRDF_FUNC "Unexpected chiplet type %x for for 0x%08x",
                     i_chpltType, i_chip->getHuid());
            PRDF_ASSERT(false);
    }

    if ( i_chpltType == TYPE_PROC || i_chpltType == TYPE_XBUS )
    {
        o_chpltList.push_back(i_chip);
    }
    else
    {
        o_chpltList = PlatServices::getConnectedChildren(i_chip, i_chpltType);
    }

    #undef PRDF_FUNC
}

void ClearChipletParityError(ExtensibleChip * i_chip,
                             TARGETING::TYPE i_chpltType)
{
    #define PRDF_FUNC "[Proc::ClearChipletParityError ]"

    int32_t rc = SUCCESS;
    const char * errRegStr = nullptr;
    const char * cfgRegStr = nullptr;
    ExtensibleChipList chpltList;

    getChpltList( i_chip, i_chpltType, errRegStr, cfgRegStr, chpltList );

    for ( auto chplt : chpltList )
    {
        SCAN_COMM_REGISTER_CLASS * errReg = chplt->getRegister(errRegStr);

        errReg->setAllBits();
        rc = errReg->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s write failed for 0x%08x",
                errRegStr, chplt->getHuid());
            continue;
        }
    }
    #undef PRDF_FUNC
}

void ClearChipletPll(ExtensibleChip * i_chip, TARGETING::TYPE i_chpltType)
{
    #define PRDF_FUNC "[Proc::ClearChipletPll] "

    int32_t rc = SUCCESS;
    const char * errRegStr = nullptr;
    const char * cfgRegStr = nullptr;
    ExtensibleChipList chpltList;

    getChpltList( i_chip, i_chpltType, errRegStr, cfgRegStr, chpltList );

    for ( auto chplt : chpltList )
    {
        SCAN_COMM_REGISTER_CLASS * errReg = chplt->getRegister(errRegStr);

        rc = errReg->ForceRead();

        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s read failed for 0x%08x",
            errRegStr, chplt->getHuid());
            continue;
        }

        // Clear PLL error bits by writing 1's
        errReg->SetBitFieldJustified(25, 4, 0xF);
        rc = errReg->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s write failed for 0x%08x",
                errRegStr, chplt->getHuid());
            continue;
        }
    }

    #undef PRDF_FUNC
}

void MaskChipletPll(ExtensibleChip * i_chip, TARGETING::TYPE i_chpltType)
{
    #define PRDF_FUNC "[Proc::MaskChipletPll] "

    int32_t rc = SUCCESS;
    const char * errRegStr = nullptr;
    const char * cfgRegStr = nullptr;
    ExtensibleChipList chpltList;

    getChpltList( i_chip, i_chpltType, errRegStr, cfgRegStr, chpltList );

    for ( auto chplt : chpltList )
    {
        SCAN_COMM_REGISTER_CLASS * cfgReg = chplt->getRegister(cfgRegStr);
        rc = cfgReg->Read();

        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s read failed for 0x%08x", chplt->getHuid());
            continue;
        }

        cfgReg->SetBit(12);
        rc = cfgReg->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s write failed for 0x%08x",
                     cfgRegStr, chplt->getHuid());
            continue;
        }
    }
    #undef PRDF_FUNC
}

bool CheckChipletPll(ExtensibleChip * i_chip, TARGETING::TYPE i_chpltType)
{
    #define PRDF_FUNC "[Proc::CheckChipletPll] "

    int32_t rc = SUCCESS;
    bool pllErrFound = false;
    const char * errRegStr = nullptr;
    const char * cfgRegStr = nullptr;
    ExtensibleChipList chpltList;

    getChpltList( i_chip, i_chpltType, errRegStr, cfgRegStr, chpltList );

    for ( auto chplt : chpltList )
    {
        SCAN_COMM_REGISTER_CLASS * errReg = chplt->getRegister(errRegStr);
        SCAN_COMM_REGISTER_CLASS * cfgReg = chplt->getRegister(cfgRegStr);

        rc  = errReg->ForceRead();
        rc |= cfgReg->Read();

        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "%s read failed for 0x%08x",
                     errRegStr, chplt->getHuid());
            continue;
        }

        if ( i_chpltType == TYPE_PROC )
        {
            // Check only bits 26, 28 in TP error register
            if ( (errReg->IsBitSet(26) || errReg->IsBitSet(28)) &&
                 (! cfgReg->IsBitSet(12)) )
            {
                pllErrFound = true;
                break;
            }
        }
        else
        {
            // Check if chiplet is reporting a PLL unlock in bits 25-28
            if ((errReg->GetBitFieldJustified(25, 4) != 0) &&
                (! cfgReg->IsBitSet(12))) // And not masked
            {
                pllErrFound = true;
                break;
            }
        }

        // If we're looking at the PEC chiplet (MF-ref errors), also check TP
        if ( i_chpltType == TYPE_PEC )
        {
            // Check bits 25, 27 in TP error reg
            errReg = i_chip->getRegister("TP_ERROR_REG");
            cfgReg = i_chip->getRegister("TP_CONFIG_REG");

            rc  = errReg->ForceRead();
            rc |= cfgReg->Read();

            if (rc != SUCCESS)
            {
                PRDF_ERR(PRDF_FUNC "TP_ERR_REG read failed for 0x%08x",
                         i_chip->getHuid());
                continue;
            }

            if ( (errReg->IsBitSet(25) || errReg->IsBitSet(27)) &&
                 (! cfgReg->IsBitSet(12)) )
            {
                pllErrFound = true;
                break;
            }
        }
    }
    return pllErrFound;
    #undef PRDF_FUNC
}

/**
 *  @brief Examine chiplets to determine which type of PLL error has ocurred
 *  @param i_chip P9 chip
 *  @param o_errType enum indicating which type of PLL error is detected
 *  @returns Failure or Success
 */
int32_t CheckErrorType( ExtensibleChip * i_chip, uint32_t & o_errType )
{
    #define PRDF_FUNC "[Proc::CheckErrorType] "
    int32_t rc = SUCCESS;

    // TODO: Currently disabling PLL error analysis until we are able to update
    //       it for P10.
    return SUCCESS;

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

        if ((! TP_LFIRmask->IsBitSet(OSC_SW_SYS_REF)) &&
             TP_LFIR->IsBitSet(OSC_SW_SYS_REF))
        {
            o_errType |= SYS_OSC_FAILOVER;
        }

        if ((! TP_LFIRmask->IsBitSet(OSC_SW_MF_REF)) &&
             TP_LFIR->IsBitSet(OSC_SW_MF_REF))
        {
            o_errType |= PCI_OSC_FAILOVER;
        }

        if ((! TP_LFIRmask->IsBitSet(PLL_UNLOCK)) &&
             TP_LFIR->IsBitSet(PLL_UNLOCK))
        {
            // Check TP, XBUS, OBUS and MC Chiplets for sys ref unlock
            if (CheckChipletPll(i_chip, TYPE_PROC) ||
                CheckChipletPll(i_chip, TYPE_XBUS) ||
                CheckChipletPll(i_chip, TYPE_OBUS) ||
                CheckChipletPll(i_chip, TYPE_MC))
            {
                o_errType |= SYS_PLL_UNLOCK;
            }

            // Check PCIE chiplet for MF ref unlock
            if (CheckChipletPll(i_chip, TYPE_PEC))
            {
                o_errType |= PCI_PLL_UNLOCK;
            }
        }
    } while (0);

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, CheckErrorType );

/**
 * @brief Clear Chiplet PCB slave reg parity errors
 * @param i_chip P9 chip
 * @returns Failure or Success
 */
int32_t clearParityError( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Proc::clearParityError] "

    if ( CHECK_STOP != i_sc.service_data->getPrimaryAttnType() )
    {
        // Clear Chiplet parity error bits
        ClearChipletParityError(i_chip, TYPE_PROC);
        ClearChipletParityError(i_chip, TYPE_XBUS);
        ClearChipletParityError(i_chip, TYPE_OBUS);
        ClearChipletParityError(i_chip, TYPE_MC);
        ClearChipletParityError(i_chip, TYPE_PEC);
        ClearChipletParityError(i_chip, TYPE_EQ);
        ClearChipletParityError(i_chip, TYPE_CORE);
    }

    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, clearParityError );

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

    uint32_t errType = 0;

    rc = CheckErrorType(i_chip, errType);

    if (rc == SUCCESS)
    {
        o_result = (errType != 0);
    }
    else
    {
        PRDF_ERR(PRDF_FUNC "failed for proc: 0x%.8X",
                 i_chip->getHuid());
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, QueryPll );

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
        // Clear Pll bits in chiplet PCB Slave error regs
        ClearChipletPll(i_chip, TYPE_PROC);
        ClearChipletPll(i_chip, TYPE_XBUS);
        ClearChipletPll(i_chip, TYPE_OBUS);
        ClearChipletPll(i_chip, TYPE_MC);

        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIRand =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIRand->setAllBits();
        TP_LFIRand->ClearBit(PLL_UNLOCK);
        TP_LFIRand->ClearBit(OSC_SW_SYS_REF);

        rc = TP_LFIRand->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_AND write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, ClearPll );

int32_t ClearMfPll( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::ClearMfPll] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->getPrimaryAttnType())
    {
        // Clear Pll bits in chiplet PCB Slave error regs
        ClearChipletPll(i_chip, TYPE_PEC);

        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIRand =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIRand->setAllBits();
        TP_LFIRand->ClearBit(PLL_UNLOCK);
        TP_LFIRand->ClearBit(OSC_SW_MF_REF);
        rc = TP_LFIRand->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_AND write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, ClearMfPll );

/**
  * @brief Mask the PLL error for P9 Plugin
  * @param  i_chip P9 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPll( ExtensibleChip * i_chip,
                 STEP_CODE_DATA_STRUCT & i_sc,
                 uint32_t i_errType )
{
    int32_t rc = SUCCESS;

    if (SYS_PLL_UNLOCK & i_errType)
    {
        MaskChipletPll(i_chip, TYPE_PROC);
        MaskChipletPll(i_chip, TYPE_XBUS);
        MaskChipletPll(i_chip, TYPE_OBUS);
        MaskChipletPll(i_chip, TYPE_MC);
    }

    if (PCI_PLL_UNLOCK & i_errType)
    {
        MaskChipletPll(i_chip, TYPE_PROC);
        MaskChipletPll(i_chip, TYPE_PEC);
    }

    if (SYS_OSC_FAILOVER & i_errType)
    {
        SCAN_COMM_REGISTER_CLASS * tpmask_or =
            i_chip->getRegister("TP_LFIR_MASK_OR");
        tpmask_or->clearAllBits();
        tpmask_or->SetBit(OSC_SW_SYS_REF);
        rc = tpmask_or->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR("[Proc::MaskPll] TP_LFIR_MSK write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }

    if (PCI_OSC_FAILOVER & i_errType)
    {
        SCAN_COMM_REGISTER_CLASS * tpmask_or =
            i_chip->getRegister("TP_LFIR_MASK_OR");
        tpmask_or->clearAllBits();
        tpmask_or->SetBit(OSC_SW_MF_REF);
        rc = tpmask_or->Write();
        if (rc != SUCCESS)
        {
            PRDF_ERR("[Proc::MaskPll] TP_LFIR_MSK write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, MaskPll );

void __capturePll(ExtensibleChip * i_procChip, STEP_CODE_DATA_STRUCT & io_sc,
                  TARGETING::TYPE i_unitType)
{
    for (const auto& chip : getConnectedChildren(i_procChip, i_unitType))
    {
        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("pll_ffdc"));
    }
}

/**
 * @brief   Captures additional PLL registers for FFDC
 * @param   i_chip   P9 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t capturePllFfdc( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    // Add FSI status reg
    PLL::captureFsiStatusReg<TYPE_PROC>( i_chip, io_sc );

    // Get the PLL registers for each unit on this chip. Note that the PROC
    // registers are already captured at this point.
    __capturePll(i_chip, io_sc, TYPE_MC);
    __capturePll(i_chip, io_sc, TYPE_EQ);
    __capturePll(i_chip, io_sc, TYPE_PAUC);
    __capturePll(i_chip, io_sc, TYPE_IOHS);

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,   Proc, capturePllFfdc );

} // end namespace Proc

} // end namespace PRDF
