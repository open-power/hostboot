/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_fir_class.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
///
/// @file p10_pm_fir_class.H
/// @brief  common .H file for all FIRINITS
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *Team                : PM
// *Consumed by         : HB
// *Level               : 3
///

#ifndef _P10_PM_FIR_CLASS_H_
#define _P10_PM_FIR_CLASS_H_
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm.H>
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>

using namespace scomt;
using namespace proc;
using namespace eq;

#define FIR_CHECKSTOP_ERROR "ERROR: Failed to set CheckStop action"
#define FIR_MASK_ERROR      "ERROR: Failed to set mask action"
#define FIR_UNMASK_ERROR    "ERROR: Failed to set unmask action"
#define FIR_REC_ATTN_ERROR  "ERROR: Failed to set recoverable attn action"
#define FIR_REC_INTR_ERROR  "ERROR: Failed to set recoverable interrupt action"
#define FIR_MALF_ALRT_ERROR "ERROR: Failed to set malfunction alert action"
#define FIR_QME_INTR_ERROR  "ERROR: Failed to set QME interrupt action"
#define FIR_PIG_ALRT_ERROR  "ERROR: Failed to set PIG action"
namespace pmFIR
{

//--------------------------------------------------------------------------
// Constants and class definition
//--------------------------------------------------------------------------

//FIR types
enum FIRType
{
    FIRTYPE_OCC_LFIR = 0x00000001, // OCC LFIR
    FIRTYPE_PBAO_LFIR = 0x00000002, // PBAO LFIR
    FIRTYPE_PBAF_LFIR = 0x00000003, // PBAF LFIR
    FIRTYPE_QME_LFIR = 0x00000004, // QME LFIR
};

// Register
enum regType
{
    REG_ACTION0,
    REG_ACTION1,
    REG_FIR,
    REG_FIRMASK,
    REG_ALL,
    REG_ERRMASK
};

//FIR register offset from base
enum FIROffset
{
    MASK_INCR       = 3,
    MASK_WAND_INCR  = 4,
    MASK_WOR_INCR   = 5,
    ACTION0_INCR    = 6,
    ACTION1_INCR    = 7,
    EQ_MASK_INCR       = 4,
    EQ_MASK_WAND_INCR  = 5,
    EQ_MASK_WOR_INCR   = 6,
    EQ_ACTION0_INCR    = 8,
    EQ_ACTION1_INCR    = 12,
};

// Target type
enum Target
{
    PROC_TARGET,
    EQ_TARGET,
    CORE_TARGET
};


template <FIRType Ftype, fapi2::TargetType K>
class PMFir
{
        // Fapi Targets for the FIRs and Error masks
        fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP > iv_proc;
        fapi2::Target < fapi2::TARGET_TYPE_EQ > iv_eq;
        fapi2::Target < fapi2::TARGET_TYPE_CORE > iv_core;

        fapi2::Target <K> iv_target;

        // Buffers to hold the FIR, masks and action register data
        fapi2::buffer<uint64_t> iv_fir;
        fapi2::buffer<uint64_t> iv_action0;
        fapi2::buffer<uint64_t> iv_action1;
        fapi2::buffer<uint64_t> iv_mask;
        fapi2::buffer<uint64_t> iv_and_mask;
        fapi2::buffer<uint64_t> iv_or_mask;

        // Addresses of the FIRs, Masks, and action registers
        uint64_t iv_fir_address;
        uint64_t iv_action0_address;
        uint64_t iv_action1_address;
        uint64_t iv_mask_address;
        uint64_t iv_mask_and_address;
        uint64_t iv_mask_or_address;

        // Flags if class value was modified
        bool iv_fir_write;
        bool iv_action0_write;
        bool iv_action1_write;
        bool iv_mask_and_write;
        bool iv_mask_or_write;
        bool iv_mask_write;

        uint8_t iv_targetType;

    public:

        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target);
        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target);
        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target);

        fapi2::ReturnCode get(const regType i_reg);

        fapi2::ReturnCode put();

        fapi2::ReturnCode setCheckStop(const uint32_t i_bit);

        fapi2::ReturnCode setRecvAttn(const uint32_t i_bit);

        fapi2::ReturnCode setRecvIntr(const uint32_t i_bit);

        fapi2::ReturnCode setMalfAlert(const uint32_t i_bit);

        fapi2::ReturnCode setQMEIntr(const uint32_t i_bit);

        fapi2::ReturnCode setPIG(const uint32_t i_bit);

        fapi2::ReturnCode mask(const uint32_t i_bit);

        fapi2::ReturnCode unmask(const uint32_t i_bit);

        fapi2::ReturnCode setAllRegBits(const regType i_reg);

        fapi2::ReturnCode clearAllRegBits(const regType i_reg);

        fapi2::ReturnCode saveMask();

        fapi2::ReturnCode restoreSavedMask();

};


/// @brief Base constructor for FIR class to build object based on FIR type
///
/// @param [in] <F>              FIR type (template parameter)
/// @param [in] i_target         Chip Target
///
template < FIRType Ftype , fapi2::TargetType K>
PMFir<Ftype, K>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
}

/// @brief The constructor for FIR class for OCC FIR
///
/// @param [in] <FIRTYPE_OCC_LFIR>  FIR Type for OCC
/// @param [in] i_target            Chip Target
///
template <> inline
PMFir<FIRTYPE_OCC_LFIR, fapi2::TARGET_TYPE_PROC_CHIP>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
    iv_target = i_target;
    iv_fir_address = TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_mask_and_address = iv_fir_address + MASK_WAND_INCR;
    iv_mask_or_address = iv_fir_address + MASK_WOR_INCR;
    iv_proc = i_target;
    iv_targetType = PROC_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_and_write = false;
    iv_mask_or_write = false;
}

/// @brief The constructor for FIR class for PBA FIR
///
/// @param [in] <FIRTYPE_PBAO_LFIR>  FIR Type for PBAO
/// @param [in] i_target            Chip Target
///
template <> inline
PMFir<FIRTYPE_PBAO_LFIR, fapi2::TARGET_TYPE_PROC_CHIP>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
    iv_target = i_target;
    iv_fir_address = TP_TPBR_PBA_PBAO_PBAFIR_RW;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_mask_and_address = iv_fir_address + MASK_WAND_INCR;
    iv_mask_or_address = iv_fir_address + MASK_WOR_INCR;
    iv_proc = i_target;
    iv_targetType = PROC_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_and_write = false;
    iv_mask_or_write = false;
}

/// @brief The constructor for FIR class for PBAF FIR
///
/// @param [in] <FIRTYPE_PBAF_LFIR>  FIR Type for PBAF
/// @param [in] i_target            Chip Target
///
template <> inline
PMFir<FIRTYPE_PBAF_LFIR, fapi2::TARGET_TYPE_PROC_CHIP>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
    iv_target = i_target;
    iv_fir_address = TP_TPBR_PBA_PBAF_PBAFIR_RW;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_mask_and_address = iv_fir_address + MASK_WAND_INCR;
    iv_mask_or_address = iv_fir_address + MASK_WOR_INCR;
    iv_proc = i_target;
    iv_targetType = PROC_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_and_write = false;
    iv_mask_or_write = false;
}
/// @brief Base constructor for FIR class to build object based on FIR type
///
/// @param [in] <F>              FIR type (template parameter)
/// @param [in] i_target         EQ Target
///
template < FIRType Ftype, fapi2::TargetType K >
PMFir<Ftype, K>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target)
{
}

/// @brief The constructor for FIR class for QME FIR
///
/// @param [in] <FIRTYPE_QME_LFIR>  FIR Type for QME
/// @param [in] i_target            EQ Target
///
template <> inline
PMFir<FIRTYPE_QME_LFIR, fapi2::TARGET_TYPE_EQ>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target)
{
    uint8_t l_chpltNumber = 0;

    iv_target = i_target;
    // Fetch the position of the EQ Target
    fapi2::ReturnCode l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,
                                           l_chpltNumber);

    iv_fir_address =  QME_LFIR_RW;
    iv_action0_address = iv_fir_address + EQ_ACTION0_INCR;
    iv_action1_address = iv_fir_address + EQ_ACTION1_INCR;
    iv_mask_address = iv_fir_address + EQ_MASK_INCR;
    iv_mask_and_address = iv_fir_address + EQ_MASK_WAND_INCR;
    iv_mask_or_address = iv_fir_address + EQ_MASK_WOR_INCR;
    FAPI_DBG("EQ number = %d %08x %08x", l_chpltNumber, iv_action0_address, l_rc);
    iv_eq = i_target;
    iv_targetType = EQ_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_and_write = false;
    iv_mask_or_write = false;
}

/// @brief Get the values of FIRs, FIR masks & FIR actions
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::get(const regType i_reg)
{
    if (i_reg == REG_FIR || i_reg == REG_ALL)
    {
        FAPI_TRY(fapi2::getScom(iv_target, iv_fir_address, iv_fir));
        iv_fir_write = false;
    }

    if(i_reg == REG_ACTION0 || i_reg == REG_ALL)
    {
        FAPI_TRY(fapi2::getScom(iv_target, iv_action0_address, iv_action0));
        iv_action0_write = false;
    }

    if(i_reg == REG_ACTION1 || i_reg == REG_ALL)
    {
        FAPI_TRY(fapi2::getScom(iv_target, iv_action1_address, iv_action1));
        iv_action1_write = false;
    }

    if(i_reg == REG_FIRMASK || i_reg == REG_ALL)
    {
        FAPI_TRY(fapi2::getScom(iv_target, iv_mask_address, iv_mask));
        FAPI_INF("Mask Address %08X, Mask value %16llx", iv_mask_address, iv_mask);
        iv_and_mask = iv_mask;
        iv_or_mask = iv_mask;
        iv_mask_and_write = false;
        iv_mask_or_write = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Put the modified values to the registers
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::put()
{
    uint64_t l_address = 0;

    if (iv_fir_write == true)
    {
        l_address = iv_fir_address;
        FAPI_TRY(putScom(iv_target, l_address, iv_fir));
    }

    if (iv_action0_write == true)
    {
        FAPI_TRY(putScom(iv_target, iv_action0_address, iv_action0));
    }

    if (iv_action1_write == true)
    {
        FAPI_TRY(putScom(iv_target, iv_action1_address, iv_action1));
    }

    if (iv_mask_or_write == true)
    {
        FAPI_TRY(putScom(iv_target, iv_mask_or_address, iv_or_mask));
    }

    if (iv_mask_and_write == true)
    {
        FAPI_TRY(putScom(iv_target, iv_mask_and_address, iv_and_mask));
    }

    if (iv_mask_write == true)
    {
        FAPI_TRY(putScom(iv_target, iv_mask_address, iv_mask));
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to checkstop (00)
//   Action0    Action1    Mask
///    0          0         0
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setCheckStop(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.clearBit(i_bit));
    FAPI_TRY(iv_action1.clearBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to recoverable attention (01)
//   Action0    Action1    Mask
///    0          1         0
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setRecvAttn(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.clearBit(i_bit));
    FAPI_TRY(iv_action1.setBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to recoverable interrupt (10)
//   Action0    Action1    Mask
///    1          0         0
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setRecvIntr(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.setBit(i_bit));
    FAPI_TRY(iv_action1.clearBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to malfunction alert (11)
//   Action0    Action1    Mask
///    1          1         0
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setMalfAlert(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.setBit(i_bit));
    FAPI_TRY(iv_action1.setBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Set FIR bit action to QME interrupt (10)
//   Action0    Action1    Mask
///    1          0         0
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setQMEIntr(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.setBit(i_bit));
    FAPI_TRY(iv_action1.clearBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to PIG (11)
//   Action0    Action1    Mask
///    1          1         0
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setPIG(const uint32_t i_bit)
{
    FAPI_TRY(iv_action0.setBit(i_bit));
    FAPI_TRY(iv_action1.setBit(i_bit));
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_action0_write = true;
    iv_action1_write = true;
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Mask a given bit
///
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::mask(const uint32_t i_bit)
{
    FAPI_TRY(iv_mask.setBit(i_bit));
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief unmask a given bit
///
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::unmask(const uint32_t i_bit)
{
    FAPI_TRY(iv_mask.clearBit(i_bit));
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set all bits of FIR/MASK/Action
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::setAllRegBits(const regType i_reg)
{
    if (i_reg == REG_FIR || i_reg == REG_ALL)
    {
        iv_fir.flush<1>();
        iv_fir_write = true;
    }

    if(i_reg == REG_ACTION0 || i_reg == REG_ALL)
    {
        iv_action0.flush<1>();
        iv_action0_write = true;
    }

    if(i_reg == REG_ACTION1 || i_reg == REG_ALL)
    {
        iv_action1.flush<1>();
        iv_action1_write = true;
    }

    if(i_reg == REG_FIRMASK || i_reg == REG_ERRMASK || i_reg == REG_ALL)
    {
        iv_mask.flush<1>();
        iv_mask_write = true;
    }

    return fapi2::current_err;
}

/// @brief Clear all bits of FIR/MASK/Action
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::clearAllRegBits(const regType i_reg)
{
    if (i_reg == REG_FIR || i_reg == REG_ALL)
    {
        iv_fir.flush<0>();
        iv_fir_write = true;
    }

    if(i_reg == REG_ACTION0 || i_reg == REG_ALL)
    {
        iv_action0.flush<0>();
        iv_action0_write = true;
    }

    if(i_reg == REG_ACTION1 || i_reg == REG_ALL)
    {
        iv_action1.flush<0>();
        iv_action1_write = true;
    }

    if(i_reg == REG_FIRMASK || i_reg == REG_ERRMASK || i_reg == REG_ALL)
    {
        iv_mask.flush<0>();
        iv_mask_write = true;
    }

    return fapi2::current_err;
}

/// @brief Base function to save the present FIR mask into attribute
///
/// @param [in] <Ftype>  FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype, fapi2::TargetType K>
fapi2::ReturnCode PMFir<Ftype, K>::saveMask()
{
    return fapi2::current_err;
}

/// @brief Save the present OCC LFIR mask into attribute
///
/// @param [in] <FIRTYPE_OCC_LFIR> OCC FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_OCC_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::saveMask()
{
    uint64_t l_mask = 0;
    iv_mask.extract<0, 64>(l_mask);

    if (l_mask != 0xFFFFFFFFFFFFFFFF)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_OCC_LFIRMASK, iv_target, l_mask),
                 "ERROR: Failed to save OCC LFIR");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Save the present PBAO LFIR mask into attribute
///
/// @param [in] <FIRTYPE_PBAO_LFIR> PBAO FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_PBAO_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::saveMask()
{
    uint64_t l_mask = 0;
    iv_mask.extract<0, 64>(l_mask);

    if (l_mask != 0xFFFFFFFFFFFFFFFF)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PBAO_LFIRMASK, iv_target, l_mask),
                 "ERROR: Failed to save PBAO LFIR");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Save the present PBAF LFIR mask into attribute
///
/// @param [in] <FIRTYPE_PBAF_LFIR> PBAF FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_PBAF_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::saveMask()
{
    uint64_t l_mask = 0;
    iv_mask.extract<0, 64>(l_mask);

    if (l_mask != 0xFFFFFFFFFFFFFFFF)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PBAF_LFIRMASK, iv_target, l_mask),
                 "ERROR: Failed to save PBAF LFIR");
    }

fapi_try_exit:
    return fapi2::current_err;
}
/// @brief Save the present CME LFIR mask into attribute
///
/// @param [in] <FIRTYPE_CME_LFIR> CME FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_QME_LFIR,
      fapi2::TARGET_TYPE_EQ>::saveMask()
{
    uint64_t l_mask = 0;
    iv_mask.extract<0, 64>(l_mask);

    if (l_mask != 0xFFFFFFFFFFFFFFFF)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_QME_LFIRMASK, iv_target, l_mask),
                 "ERROR: Failed to save QME LFIR");
    }

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Base function to restore saved value to the FIR Mask
///
/// @param [in] <Ftype>    FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template < FIRType Ftype, fapi2::TargetType K >
fapi2::ReturnCode PMFir<Ftype, K>::restoreSavedMask()
{
    return fapi2::current_err;
}

/// @brief Restore saved OCC LFIR Mask
///
/// @param [in] <FIRTYPE_OCC_LFIR> OCC LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_OCC_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::restoreSavedMask()
{
    uint64_t l_mask = 0;
    uint64_t l_tempMask = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCC_LFIRMASK, iv_target, l_mask),
             "ERROR: Failed to retrieve saved OCC LFIR");
    iv_mask.extract<0, 64>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 64>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved PBAO LFIR Mask
///
/// @param [in] <FIRTYPE_PBAO_LFIR> PBAO LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_PBAO_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::restoreSavedMask()
{
    uint64_t l_mask = 0;
    uint64_t l_tempMask = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PBAO_LFIRMASK, iv_target, l_mask),
             "ERROR: Failed to retrieve saved PBAO LFIR");
    iv_mask.extract<0, 64>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 64>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved PBAF LFIR Mask
///
/// @param [in] <FIRTYPE_PBAF_LFIR> PBAF LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_PBAF_LFIR,
      fapi2::TARGET_TYPE_PROC_CHIP>::restoreSavedMask()
{
    uint64_t l_mask = 0;
    uint64_t l_tempMask = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PBAF_LFIRMASK, iv_target, l_mask),
             "ERROR: Failed to retrieve saved PBAF LFIR");
    iv_mask.extract<0, 64>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 64>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved QME LFIR Mask
///
/// @param [in] <FIRTYPE_QME_LFIR> QME LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <> inline
fapi2::ReturnCode PMFir<FIRTYPE_QME_LFIR,
      fapi2::TARGET_TYPE_EQ>::restoreSavedMask()
{
    uint64_t l_mask = 0;
    uint64_t l_tempMask = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_QME_LFIRMASK, iv_target, l_mask),
             "ERROR: Failed to retrieve saved QME LFIR mask");
    iv_mask.extract<0, 32>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 64>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

}
#endif //_P10_PM_FIR_CLASS_H_
