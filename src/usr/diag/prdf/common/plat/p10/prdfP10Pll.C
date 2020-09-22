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
#include <prdfPllDomain.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_proc
{

// PLL detect bits in TPLFIR
enum
{
    PLL_UNLOCK = 21,
    OSC_SW_SYS_REF = 36,
};

//------------------------------------------------------------------------------

ExtensibleChipList __getChipList(ExtensibleChip * i_chip,
                                 TARGETING::TYPE i_type)
{
    ExtensibleChipList list;

    if (TYPE_PROC == i_type)
    {
        list.push_back(i_chip);
    }
    else
    {
        list = getConnectedChildren(i_chip, i_type);
    }

    return list;
}

//------------------------------------------------------------------------------

static const
std::map< TARGETING::TYPE,
          std::vector< std::pair<const char*, const char*> > > g_pcbslvRegs =
{
    { TYPE_PROC, { { "TP_PCBSLV_CONFIG",   "TP_PCBSLV_ERROR"   },
                   { "N0_PCBSLV_CONFIG",   "N0_PCBSLV_ERROR"   },
                   { "N1_PCBSLV_CONFIG",   "N1_PCBSLV_ERROR"   }, } },
    { TYPE_PEC,  { { "PEC_PCBSLV_CONFIG",  "PEC_PCBSLV_ERROR"  }, } },
    { TYPE_MC,   { { "MC_PCBSLV_CONFIG",   "MC_PCBSLV_ERROR"   }, } },
    { TYPE_PAUC, { { "PAUC_PCBSLV_CONFIG", "PAUC_PCBSLV_ERROR" }, } },
    { TYPE_IOHS, { { "IOHS_PCBSLV_CONFIG", "IOHS_PCBSLV_ERROR" }, } },
    { TYPE_EQ,   { { "EQ_PCBSLV_CONFIG",   "EQ_PCBSLV_ERROR"   }, } },
};

#define FOR_EACH_CHIPLET(CHIP) \
    for ( const auto& map : g_pcbslvRegs ) \
    { \
        for ( const auto& chip : __getChipList(CHIP, map.first) ) \
        {

#define END_FOR_EACH_CHIPLET \
        } \
    }

#define FOR_EACH_REG_PAIR(CHIP) \
    FOR_EACH_CHIPLET(CHIP) \
        for ( const auto& pair : map.second ) \
        {

#define END_FOR_EACH_REG_PAIR \
        } \
    END_FOR_EACH_CHIPLET

//------------------------------------------------------------------------------

void getChpltList ( ExtensibleChip * i_chip,
                    TARGETING::TYPE i_chpltType,
                    const char * &o_errRegStr,
                    const char * &o_cfgRegStr,
                    ExtensibleChipList & o_chpltList )
{
    #define PRDF_FUNC "[p10_proc::getChpltList ]"
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

    o_chpltList = __getChipList(i_chip, i_chpltType);

    #undef PRDF_FUNC
}

void ClearChipletParityError(ExtensibleChip * i_chip,
                             TARGETING::TYPE i_chpltType)
{
    #define PRDF_FUNC "[p10_proc::ClearChipletParityError ]"

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
    #define PRDF_FUNC "[p10_proc::ClearChipletPll] "

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
    #define PRDF_FUNC "[p10_proc::MaskChipletPll] "

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
    #define PRDF_FUNC "[p10_proc::CheckChipletPll] "

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
 * @brief  Queries for all PLL error types that occurred on this chip.
 * @param  i_chip    A PROC chip.
 * @param  o_errType The types of errors found.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t CheckErrorType(ExtensibleChip * i_chip, PllErrTypes& o_errType)
{
    #define PRDF_FUNC "[p10_proc::CheckErrorType] "
    int32_t rc = SUCCESS;

    o_errType.clear();

/* TODO: Currently disabling PLL error analysis until we are able to update
 *       it for P10.
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
        }
    } while (0);
*/

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE(p10_proc, CheckErrorType);

/**
 * @brief  Clears PCB slave parity errors on this chip.
 * @param  i_chip A PROC chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t clearParityError(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    #define PRDF_FUNC "[p10_proc::clearParityError] "

    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
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
PRDF_PLUGIN_DEFINE(p10_proc, clearParityError);

/**
 * @brief  Queries for PLL errors on this chip.
 * @param  i_chip   A PROC chip.
 * @param  o_result True, if errors found. False, otherwise.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t QueryPll(ExtensibleChip * i_chip, bool & o_result)
{
    o_result = false;

    PllErrTypes errType;
    if (SUCCESS == CheckErrorType(i_chip, errType))
    {
        o_result = errType.any();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, QueryPll);

/**
 * @brief  Clears PLL errors on this chip.
 * @param  i_chip A PROC chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t ClearPll(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{
    #define PRDF_FUNC "[p10_proc::ClearPll] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != io_sc.service_data->getPrimaryAttnType())
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
PRDF_PLUGIN_DEFINE(p10_proc, ClearPll);

/**
 * @brief  Masks PLL errors on this chip.
 * @param  i_chip    A PROC chip.
 * @param  io_sc     The step code data struct.
 * @param  i_errType The types of errors to mask.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t MaskPll(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                const PllErrTypes& i_errType)
{
/* TODO: Currently disabling PLL error analysis until we are able to update
 *       it for P10.
    int32_t rc = SUCCESS;

    if (SYS_PLL_UNLOCK & i_errType)
    {
        MaskChipletPll(i_chip, TYPE_PROC);
        MaskChipletPll(i_chip, TYPE_XBUS);
        MaskChipletPll(i_chip, TYPE_OBUS);
        MaskChipletPll(i_chip, TYPE_MC);
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
            PRDF_ERR("[p10_proc::MaskPll] TP_LFIR_MSK write failed"
                     "for chip: 0x%08x", i_chip->getHuid());
        }
    }
*/

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, MaskPll);

//------------------------------------------------------------------------------

/**
 * @brief  Captures PLL registers for FFDC.
 * @param  i_chip A PROC chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t capturePllFfdc(ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & io_sc)
{
    // Note that the 'default_pll_ffdc' capture group (PLL error analysis) or
    // the 'default' capture group (normal analysis) should have been captured
    // before calling this function.

    // Capture the FSI status registers.
    PLL::captureFsiStatusReg<TYPE_PROC>( i_chip, io_sc );

    // Capture the PLL FFDC for all sub-units of this chip.
    FOR_EACH_CHIPLET(i_chip)

        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("pll_ffdc"));

    END_FOR_EACH_CHIPLET

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, capturePllFfdc);

} // end namespace p10_proc

} // end namespace PRDF
