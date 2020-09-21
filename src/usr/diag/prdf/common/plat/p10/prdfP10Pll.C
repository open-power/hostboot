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
#include <prdfRegisterCache.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_proc
{

// Target bits in the TP_LOCAL_FIR
enum
{
    PCB_SLAVE   = 28,
    OSC_ERR_0   = 42,
    OSC_ERR_1   = 43,
    UNLOCKDET_0 = 44,
    UNLOCKDET_1 = 45,
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

//------------------------------------------------------------------------------

bool __queryPllUnlock(ExtensibleChip* i_chip)
{
    // Use the broadcast OR register to get a summary of the xx_PCBSLV_ERROR
    // register on each chiplet.

    SCAN_COMM_REGISTER_CLASS* err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");

    if (SUCCESS != err->Read())
    {
        // If BC_OR_PCBSLV_ERROR[24:31] has a non-zero value, there is at least
        // one PLL unlock error on this chip.
        if (0 != err->GetBitFieldJustified(24, 8))
        {
            // PLL unlock error found.
            return true;
        }
    }

    return false; // no PLL unlock found.
}

/**
 * @brief  Queries for all PLL error types that occurred on this chip.
 * @param  i_chip     A PROC chip.
 * @param  o_errTypes The types of errors found.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t queryPllErrTypes(ExtensibleChip* i_chip, PllErrTypes& o_errTypes)
{
    // RCS OSC errors have the potential of generating PLL unlock errors, but it
    // is also possible the PLL unlock errors could have asserted on their own.
    // Regardless, the callouts should be the same for the two error types. So
    // to avoid complicated analysis code with many potential race conditions,
    // the decision is to handle each error type individually.

    // Similarly, certain PLL unlock errors have the potential of causing RCS
    // unlock detect errors, but again it is also possible the two errors could
    // have asserted on their own. So the decision is to once again treat each
    // error type individually.

    // RCS unlock detect errors only have meaning if found on the non-primary
    // clock. It is possible that by the time PRD has been able to analyze an
    // RCS unlock detect attention, a clock could have failed over one or more
    // times. This could make PRD analysis complicated and, again, may have many
    // potential race conditions.  Therefore, the decision is that RCS unlock
    // detect errors will only be handled when there are no active RCS OSC
    // errors on either side.

    int32_t rc = SUCCESS;

    o_errTypes.clear();

    SCAN_COMM_REGISTER_CLASS* fir = i_chip->getRegister("TP_LOCAL_FIR");
    SCAN_COMM_REGISTER_CLASS* msk = i_chip->getRegister("TP_LOCAL_FIR_MASK");

    do
    {
        rc = fir->Read();
        if (SUCCESS != rc) break;

        rc = msk->Read();
        if (SUCCESS != rc) break;

        // PLL unlock errors are reported via the "PCB slave error" bit.
        if (fir->IsBitSet(PCB_SLAVE) && !msk->IsBitSet(PCB_SLAVE) &&
            __queryPllUnlock(i_chip))
        {
            o_errTypes.set(PllErrTypes::PLL_UNLOCK);
        }

        // RCS OSC error on clock 0.
        if (fir->IsBitSet(OSC_ERR_0) && !msk->IsBitSet(OSC_ERR_0))
        {
            o_errTypes.set(PllErrTypes::RCS_OSC_ERROR_0);
        }

        // RCS OSC error on clock 1.
        if (fir->IsBitSet(OSC_ERR_1) && !msk->IsBitSet(OSC_ERR_1))
        {
            o_errTypes.set(PllErrTypes::RCS_OSC_ERROR_1);
        }

        // RCS unlock detect errors are only valid if there are no RCS OSC
        // errors.
        if (!o_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0) &&
            !o_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
        {
            // RCS unlock detect on clock 0.
            if (fir->IsBitSet(UNLOCKDET_0) && !msk->IsBitSet(UNLOCKDET_0))
            {
                o_errTypes.set(PllErrTypes::RCS_UNLOCKDET_0);
            }

            // RCS unlock detect on clock 1.
            if (fir->IsBitSet(UNLOCKDET_1) && !msk->IsBitSet(UNLOCKDET_1))
            {
                o_errTypes.set(PllErrTypes::RCS_UNLOCKDET_1);
            }
        }

    } while (0);

    return rc;
}
PRDF_PLUGIN_DEFINE(p10_proc, queryPllErrTypes);

/**
 * @brief  Queries for PLL errors on this chip.
 * @param  i_chip   A PROC chip.
 * @param  o_result True, if errors found. False, otherwise.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t QueryPll(ExtensibleChip * i_chip, bool & o_result)
{
    o_result = false;

    PllErrTypes errTypes;
    if (SUCCESS == queryPllErrTypes(i_chip, errTypes))
    {
        o_result = errTypes.any();
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

/* TODO: Currently disabling PLL error analysis until we are able to update
 *       it for P10.
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
*/

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

//##############################################################################
//## All of the following functions are Hosbtoot only since we are not allowed
//## to modify hardware from the FSP.
//##############################################################################

#ifdef __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

void __clearPllUnlock(ExtensibleChip* i_chip)
{
    // Use the broadcast OR register to write the same value to the
    // xx_PCBSLV_ERROR register on each chiplet. These registers are
    // "write-to-clear". So setting a bit to 1 will tell hardware to clear
    // the bit.

    SCAN_COMM_REGISTER_CLASS* err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");

    // Clear only the PLL unlock errors.
    err->clearAllBits();
    err->SetBitFieldJustified(24, 8, 0xFF);

    err->Write();

    // Since hardware will change the value of the xx_PCBSLV_ERROR registers,
    // clear them out of the cache so that subsequent reads will refresh the
    // cache.

    RegDataCache& cache = RegDataCache::getCachedRegisters();
    cache.flush(i_chip, err);

    FOR_EACH_REG_PAIR(i_chip)
        cache.flush(chip, chip->getRegister(pair.second));
    END_FOR_EACH_REG_PAIR
}

//------------------------------------------------------------------------------

void __clearRcsAttns(ExtensibleChip* i_chip, bool i_clearOsc0, bool i_clearOsc1)
{
    do
    {
        if (!i_clearOsc0 && !i_clearOsc1) break; // nothing to do

        // Since hardware will change the value of OSC_SENSE_1, clear it out of
        // the cache so that subsequent reads will refresh the cache.
        RegDataCache& cache = RegDataCache::getCachedRegisters();
        cache.flush(i_chip, i_chip->getRegister("OSC_SENSE_1"));

        // We must toggle (set high, then low) ROOT_CTRL5[6:7] to clear the RCS
        // attentions because the OSC_SENSE_1 register is read-only.

        SCAN_COMM_REGISTER_CLASS* ctrl = i_chip->getRegister("ROOT_CTRL5");
        if (SUCCESS != ctrl->Read()) break;

        // Set the target bits high.
        if (i_clearOsc0) ctrl->SetBit(6);
        if (i_clearOsc1) ctrl->SetBit(7);

        if (SUCCESS != ctrl->Write()) break;

        // Set the target bits low.
        if (i_clearOsc0) ctrl->ClearBit(6);
        if (i_clearOsc1) ctrl->ClearBit(7);

        if (SUCCESS != ctrl->Write()) break;

    } while (0);
}

//------------------------------------------------------------------------------

/**
 * @brief  Clears attentions for the given error types.
 * @param  i_chip     A PROC chip.
 * @param  io_sc      The step code data struct.
 * @param  i_errTypes The types of errors to clear.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t clearPllErrTypes(ExtensibleChip* i_chip, const PllErrTypes& i_errTypes)
{
    SCAN_COMM_REGISTER_CLASS* fir = i_chip->getRegister("TP_LOCAL_FIR_AND");
    fir->setAllBits();

    if (i_errTypes.query(PllErrTypes::PLL_UNLOCK))
    {
        // Clear all of the underlying PLL errors in each chiplet.
        __clearPllUnlock(i_chip);

        // Clear the PCB slave error bit in the TP_LOCAL_FIR.
        fir->ClearBit(PCB_SLAVE);
    }

    // When we clear an RCS OSC error on EITHER side, we will also clear RCS
    // unlock detect attentions on BOTH sides to ensure a clean slate for the
    // next attention. See notes in queryPllErrTypes() regarding the reason why.

    // When clearing the underlying bits in the OSC_SENSE_1 register for a
    // specific clock, hardware will clear both the RCS OSC error and the RCS
    // unlock detect for that clock. There is no way to separate this.
    // Therefore, it is possible we may clear the underlying bits for a FIR
    // attention we have not handled yet. For example, say there is an RCS OSC
    // error on clock 0. Then during analysis of that error, but before clearing
    // the error, there is an RCS OSC error on clock 1. When clearing the RCS
    // unlock detect on clock 1 for the first attention, it will also clear the
    // underlying bit for the RCS OSC error on clock 1. This should be fine for
    // analysis of the second attention because we will still have the FIR bit.
    // It just may look weird not seeing the underlying bit in the FFDC (if
    // anyone is paying attention to that).

    bool clearOsc0 = false;
    bool clearOsc1 = false;

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0))
    {
        // Clear the underlying bits in the OSC_SENSE_1 register.
        clearOsc0 = true;
        clearOsc1 = true; // to clear unlock detect on clock 1

        // Clear this RCS OSC error bit and both RCS unlock detect bits in the
        // TP_LOCAL_FIR.
        fir->ClearBit(OSC_ERR_0);
        fir->ClearBit(UNLOCKDET_0);
        fir->ClearBit(UNLOCKDET_1);
    }

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
    {
        // Clear the underlying bits in the OSC_SENSE_1 register.
        clearOsc0 = true; // to clear unlock detect on clock 1
        clearOsc1 = true;

        // Clear this RCS OSC error bit and both RCS unlock detect bits in the
        // TP_LOCAL_FIR.
        fir->ClearBit(OSC_ERR_1);
        fir->ClearBit(UNLOCKDET_0);
        fir->ClearBit(UNLOCKDET_1);
    }

    if (i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_0))
    {
        // Clear the underlying bits in the OSC_SENSE_1 register.
        clearOsc0 = true;

        // Clear this RCS unlock detect bit in the TP_LOCAL_FIR.
        fir->ClearBit(UNLOCKDET_0);
    }

    if (i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_1))
    {
        // Clear the underlying bits in the OSC_SENSE_1 register.
        clearOsc1 = true;

        // Clear this RCS unlock detect bit in the TP_LOCAL_FIR.
        fir->ClearBit(UNLOCKDET_1);
    }

    // Clear the underlying RCS attentions, if needed.
    __clearRcsAttns(i_chip, clearOsc0, clearOsc1);

    // Clear the target TP_LOCAL_FIR bits.
    fir->Write();

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, clearPllErrTypes);

//------------------------------------------------------------------------------

void __maskPllUnlock(ExtensibleChip* i_chip)
{
    // Mask PLL unlock attentions by setting xx_PCBSLV_CONFIG[12:19] to all
    // 1's using a read-modify-write.

    FOR_EACH_REG_PAIR(i_chip)

        SCAN_COMM_REGISTER_CLASS* cfg = chip->getRegister(pair.first);

        if (SUCCESS != cfg->Read()) continue;

        cfg->SetBitFieldJustified(12, 8, 0xFF);

        cfg->Write();

    END_FOR_EACH_REG_PAIR
}

//------------------------------------------------------------------------------

/**
 * @brief  Masks attentions for the given error types.
 * @param  i_chip     A PROC chip.
 * @param  io_sc      The step code data struct.
 * @param  i_errTypes The types of errors to mask.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t maskPllErrTypes(ExtensibleChip* i_chip, const PllErrTypes& i_errTypes)
{
    SCAN_COMM_REGISTER_CLASS* msk = i_chip->getRegister("TP_LOCAL_FIR_MASK_OR");
    msk->clearAllBits();

    if (i_errTypes.query(PllErrTypes::PLL_UNLOCK))
    {
        // Mask all of the underlying PLL errors in each chiplet.
        __maskPllUnlock(i_chip);

        // Do NOT mask the PCB slave error bit in the TP_LOCAL_FIR because that
        // bit also reports parity errors. Masking the underlying bits should
        // be enough.
    }

    // When we mask an RCS OSC error on EITHER side, it will also mask RCS
    // unlock detect attentions on BOTH sides. See notes in queryPllErrTypes()
    // regarding the reason why.

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0))
    {
        // Mask this RCS OSC error bit and both RCS unlock detect bits in the
        // TP_LOCAL_FIR.
        msk->SetBit(OSC_ERR_0);
        msk->SetBit(UNLOCKDET_0);
        msk->SetBit(UNLOCKDET_1);
    }

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
    {
        // Mask this RCS OSC error bit and both RCS unlock detect bits in the
        // TP_LOCAL_FIR.
        msk->SetBit(OSC_ERR_1);
        msk->SetBit(UNLOCKDET_0);
        msk->SetBit(UNLOCKDET_1);
    }

    if (i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_0))
    {
        // Mask this RCS unlock detect bit in the TP_LOCAL_FIR.
        msk->SetBit(UNLOCKDET_0);
    }

    if (i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_1))
    {
        // Mask this RCS unlock detect bit in the TP_LOCAL_FIR.
        msk->SetBit(UNLOCKDET_1);
    }

    // Mask the target TP_LOCAL_FIR bits.
    msk->Write();

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, maskPllErrTypes);

//------------------------------------------------------------------------------

#endif // __HOSTBOOT_MODULE

//##############################################################################
//## This plugin is required for both FSP and Hostboot because there is no
//## mechanism to declare an optional function call from the rule code.
//##############################################################################

/**
 * @brief  Clears PCB slave parity errors on this chip.
 * @param  i_chip A PROC chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on failure. SUCCESS, otherwise.
 */
int32_t clearPcbSlaveParityError(ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc)
{
    #ifdef __HOSTBOOT_MODULE // only allowed to modify hardware from the host

    // Use the broadcast OR register to write the same value to the
    // xx_PCBSLV_ERROR register on each chiplet. These registers are
    // "write-to-clear". So setting a bit to 1 will tell hardware to clear
    // the bit.

    SCAN_COMM_REGISTER_CLASS* err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");

    // Clear all bits in the register except the PLL unlock errors.
    err->setAllBits();
    err->SetBitFieldJustified(24, 8, 0);

    err->Write();

    // Since hardware will change the value of the xx_PCBSLV_ERROR registers,
    // clear them out of the cache so that subsequent reads will refresh the
    // cache.

    RegDataCache& cache = RegDataCache::getCachedRegisters();
    cache.flush(i_chip, err);

    FOR_EACH_REG_PAIR(i_chip)
        cache.flush(chip, chip->getRegister(pair.second));
    END_FOR_EACH_REG_PAIR

    #endif // __HOSTBOOT_MODULE

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, clearPcbSlaveParityError);

//------------------------------------------------------------------------------

} // end namespace p10_proc

} // end namespace PRDF
