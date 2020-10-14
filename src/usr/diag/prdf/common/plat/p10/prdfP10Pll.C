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

bool __queryPllUnlock(ExtensibleChip* i_chip)
{
    // Use the broadcast OR register to get a summary of the xx_PCBSLV_ERROR
    // register on each chiplet.

    SCAN_COMM_REGISTER_CLASS* err = i_chip->getRegister("BC_OR_PCBSLV_ERROR");

    if (SUCCESS == err->Read())
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

        // If there are any RCS OSC error attentions present, there is a high
        // probability that the primary clock has failed over to the secondary
        // clock at least once. Therefore, it would be impossible to determine
        // which clock was the primary at the time a PLL unlock or RCS unlock
        // detect attention occurred. So those attention types will be ignored.
        if (o_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0) ||
            o_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
        {
            break;
        }

        // The current primary clock can be found in RCS_SENSE_1, where:
        //  - If RCS_SENSE_1[12] is set => clock 0 is the primary
        //  - If RCS_SENSE_1[13] is set => clock 1 is the primary

        SCAN_COMM_REGISTER_CLASS* sense = i_chip->getRegister("RCS_SENSE_1");
        rc = sense->Read();
        if (SUCCESS != rc) break;

        // PLL unlock errors are reported via the "PCB slave error" bit.
        if (fir->IsBitSet(PCB_SLAVE) && !msk->IsBitSet(PCB_SLAVE) &&
            __queryPllUnlock(i_chip))
        {
            if (sense->IsBitSet(12)) o_errTypes.set(PllErrTypes::PLL_UNLOCK_0);
            if (sense->IsBitSet(13)) o_errTypes.set(PllErrTypes::PLL_UNLOCK_1);
        }

        // An RCS unlock detect on clock 0 is only valid if on the non-primary
        // clock. Therefore, clock 1 must be primary (RCS_SENSE_1[13]).
        if (fir->IsBitSet(UNLOCKDET_0) && !msk->IsBitSet(UNLOCKDET_0) &&
            sense->IsBitSet(13))
        {
            o_errTypes.set(PllErrTypes::RCS_UNLOCKDET_0);
        }

        // An RCS unlock detect on clock 1 is only valid if on the non-primary
        // clock. Therefore, clock 0 must be primary (RCS_SENSE_1[12]).
        if (fir->IsBitSet(UNLOCKDET_1) && !msk->IsBitSet(UNLOCKDET_1) &&
            sense->IsBitSet(12))
        {
            o_errTypes.set(PllErrTypes::RCS_UNLOCKDET_1);
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

        // Since hardware will change the value of RCS_SENSE_1, clear it out of
        // the cache so that subsequent reads will refresh the cache.
        RegDataCache& cache = RegDataCache::getCachedRegisters();
        cache.flush(i_chip, i_chip->getRegister("RCS_SENSE_1"));

        // We must toggle (set high, then low) ROOT_CTRL5[6:7] to clear the RCS
        // attentions because the RCS_SENSE_1 register is read-only.

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

    // When we clear an RCS OSC error attention on EITHER clock, we will also
    // clear PLL unlock attentions and RCS unlock detect attentions on BOTH
    // sides to ensure a clean slate for the next attention.

    bool rcsOscErrPresent = false;

    // When clearing the underlying bits in the RCS_SENSE_1 register for a
    // specific clock, hardware will clear both the RCS OSC error and the RCS
    // unlock detect for that clock. There is no way to separate this.
    // Therefore, it is possible we may clear the underlying bits for a FIR
    // attention we have not handled yet. For example, say there is an RCS OSC
    // error on clock 0 and RCS unlock detect on clock 1. Then during analysis,
    // but before clearing the errors, there is an RCS OSC error on clock 1.
    // When clearing the RCS unlock detect on clock 1 for the first attention,
    // it will also clear the underlying bit for the RCS OSC error on clock 1.
    // This should be fine for analysis of the second attention because we will
    // still have the FIR bit. It just may look weird not seeing the underlying
    // bit in the FFDC (if anyone is paying attention to that).

    bool clearOsc0 = false;
    bool clearOsc1 = false;

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0))
    {
        rcsOscErrPresent = true;
        clearOsc0 = true;
        fir->ClearBit(OSC_ERR_0);
    }

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
    {
        rcsOscErrPresent = true;
        clearOsc1 = true;
        fir->ClearBit(OSC_ERR_1);
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::PLL_UNLOCK_0) ||
        i_errTypes.query(PllErrTypes::PLL_UNLOCK_1))
    {
        // Clear all of the underlying PLL errors in each chiplet.
        __clearPllUnlock(i_chip);

        // Clear the PCB slave error bit in the TP_LOCAL_FIR.
        fir->ClearBit(PCB_SLAVE);
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_0))
    {
        clearOsc0 = true;
        fir->ClearBit(UNLOCKDET_0);
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_1))
    {
        clearOsc1 = true;
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

    // When we mask an RCS OSC error attention on EITHER clock, we will also
    // mask PLL unlock attentions and RCS unlock detect attentions on BOTH
    // sides to ensure we don't handle side-effect attentions.

    bool rcsOscErrPresent = false;

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_0))
    {
        rcsOscErrPresent = true;
        msk->SetBit(OSC_ERR_0);
    }

    if (i_errTypes.query(PllErrTypes::RCS_OSC_ERROR_1))
    {
        rcsOscErrPresent = true;
        msk->SetBit(OSC_ERR_1);
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::PLL_UNLOCK_0) ||
        i_errTypes.query(PllErrTypes::PLL_UNLOCK_1))
    {
        // Mask all of the underlying PLL errors in each chiplet.
        __maskPllUnlock(i_chip);

        // Do NOT mask the PCB slave error bit in the TP_LOCAL_FIR because that
        // bit also reports parity errors. Masking the underlying bits should
        // be enough.
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_0))
    {
        msk->SetBit(UNLOCKDET_0);
    }

    if (rcsOscErrPresent ||
        i_errTypes.query(PllErrTypes::RCS_UNLOCKDET_1))
    {
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
//## These plugins is required for both FSP and Hostboot because there is no
//## mechanism to declare optional function calls from the rule code.
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

/**
 * @brief  Masks PCB slave parity errors on this chip, if at threshold.
 * @param  i_chip A PROC chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS if at threshold and the PCB slave parity errors
 *         have been masked in the xx_PCBSLV_CONFIG registers. SUCCESS,
 *         otherwise.
 */
int32_t maskPcbSlaveParityError(ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & io_sc)
{
    #ifdef __HOSTBOOT_MODULE // only allowed to modify hardware from the host

    // Mask only at threshold.
    if (io_sc.service_data->IsAtThreshold())
    {
        // Mask the parity errors by setting xx_PCBSLV_CONFIG[8:11] to all 1's
        // using a read-modify-write.

        FOR_EACH_REG_PAIR(i_chip)

            SCAN_COMM_REGISTER_CLASS* cfg = chip->getRegister(pair.first);

            if (SUCCESS != cfg->Read()) continue;

            cfg->SetBitFieldJustified(8, 4, 0xF);

            cfg->Write();

        END_FOR_EACH_REG_PAIR

        // Returning PRD_NO_CLEAR_FIR_BITS below will tell the rule code to not
        // clear the FIR bit. So we will have to do that manually.
        SCAN_COMM_REGISTER_CLASS* fir = i_chip->getRegister("TP_LOCAL_FIR_AND");
        fir->setAllBits();
        fir->ClearBit(PCB_SLAVE);
        fir->Write();

        // Returning this will ensure TP_LOCAL_FIR[28] is not masked. This
        // will allow hardware to continue reporting PLL unlock attentions.
        return PRD_NO_CLEAR_FIR_BITS;
    }

    #endif // __HOSTBOOT_MODULE

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_proc, maskPcbSlaveParityError);

//------------------------------------------------------------------------------

} // end namespace p10_proc

} // end namespace PRDF
