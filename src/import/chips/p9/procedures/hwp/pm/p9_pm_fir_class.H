/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_fir_class.H $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_pm_fir_class.H
/// @brief  common .H file for all FIRINITS
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

#ifndef _P9_PM_FIR_CLASS_H_
#define _P9_PM_FIR_CLASS_H_
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_perv_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <p9_misc_scom_addresses.H>

namespace p9pmFIR
{

//--------------------------------------------------------------------------
// Constants and class definition
//--------------------------------------------------------------------------

//FIR types
enum FIRType
{
    FIRTYPE_OCC_LFIR = 0x00000001, // OCC LFIR
    FIRTYPE_PBA_LFIR = 0x00000002, // PBA LFIR
    FIRTYPE_CME_LFIR = 0x00000003, // CME LFIR
    FIRTYPE_PPM_LFIR = 0x00000004  // PPM LFIR
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
    BASE_WAND_INCR  = 1,
    BASE_WOR_INCR   = 2,
    MASK_INCR       = 3,
    MASK_WAND_INCR  = 4,
    MASK_WOR_INCR   = 5,
    ACTION0_INCR    = 6,
    ACTION1_INCR    = 7
};

// Target type
enum Target
{
    PROC_TARGET,
    EX_TARGET,
    EQ_TARGET,
    CORE_TARGET
};
/*

typedef struct FIRDetails_t
{
    uint32_t    bit_number;
    char        bit_name[64];
};

typedef struct FIRDef_t
{
    uint64_t    base_fir_address;
    char        fir_name[64];
    uint32_t    number_of_bits;
    std::vectorchar*       bit_names[];
};
*/

template <FIRType Ftype>
class PMFir
{
        // Fapi Targets for the FIRs and Error masks
        fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP > iv_proc;
        fapi2::Target < fapi2::TARGET_TYPE_EX > iv_ex;
        fapi2::Target < fapi2::TARGET_TYPE_EQ > iv_eq;
        fapi2::Target < fapi2::TARGET_TYPE_CORE > iv_core;

        // Buffers to hold the FIR, masks and action register data
        fapi2::buffer<uint64_t> iv_fir;
        fapi2::buffer<uint64_t> iv_action0;
        fapi2::buffer<uint64_t> iv_action1;
        fapi2::buffer<uint64_t> iv_mask;

        // Addresses of the FIRs, Masks, and action registers
        uint64_t iv_fir_address;
        uint64_t iv_action0_address;
        uint64_t iv_action1_address;
        uint64_t iv_mask_address;

        // Flags if class value was modified
        bool iv_fir_write;
        bool iv_action0_write;
        bool iv_action1_write;
        bool iv_mask_write;

        uint8_t iv_targetType;

    public:

        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target);
        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_EX >& i_target);
        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target);
        PMFir(const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target);

        fapi2::ReturnCode get(const regType i_reg);

        fapi2::ReturnCode put();

        fapi2::ReturnCode setCheckStop(const uint32_t i_bit);

        fapi2::ReturnCode setRecvAttn(const uint32_t i_bit);

        fapi2::ReturnCode setRecvIntr(const uint32_t i_bit);

        fapi2::ReturnCode setMalfAlert(const uint32_t i_bit);

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
template < FIRType Ftype >
PMFir<Ftype>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
}

/// @brief The constructor for FIR class for OCC FIR
///
/// @param [in] <FIRTYPE_OCC_LFIR>  FIR Type for OCC
/// @param [in] i_target            Chip Target
///
template <>
PMFir<FIRTYPE_OCC_LFIR>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
    iv_fir_address = PERV_TP_OCC_SCOM_OCCLFIR;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_proc = i_target;
    iv_targetType = PROC_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_write = false;
}

/// @brief The constructor for FIR class for PBA FIR
///
/// @param [in] <FIRTYPE_PBA_LFIR>  FIR Type for PBA
/// @param [in] i_target            Chip Target
///
template <>
PMFir<FIRTYPE_PBA_LFIR>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >& i_target)
{
    iv_fir_address = PU_PBAFIR;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_proc = i_target;
    iv_targetType = PROC_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_write = false;
}

/// @brief Base constructor for FIR class to build object based on FIR type
///
/// @param [in] <F>              FIR type (template parameter)
/// @param [in] i_target         EX Target
///
template < FIRType Ftype >
PMFir<Ftype>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EX >& i_target)
{
}

/// @brief The constructor for FIR class for CME FIR
///
/// @param [in] <FIRTYPE_CME_LFIR>  FIR Type for CME
/// @param [in] i_target            EX Target
///
template <>
PMFir<FIRTYPE_CME_LFIR>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EX >& i_target)
{
    uint8_t l_chpltNumber = 0;

    // Fetch the position of the EX Target
    fapi2::ReturnCode l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,
                                           l_chpltNumber);
    FAPI_DBG("EX number = %d", l_chpltNumber);

    iv_fir_address =  EX_CME_SCOM_LFIR;
    iv_action0_address = iv_fir_address + ACTION0_INCR;
    iv_action1_address = iv_fir_address + ACTION1_INCR;
    iv_mask_address = iv_fir_address + MASK_INCR;
    iv_ex = i_target;
    iv_targetType = EX_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_write = false;
}

/// @brief Base constructor for FIR class to build object based on FIR type
///
/// @param [in] <F>              FIR type (template parameter)
/// @param [in] i_target         EQ Target
///
template < FIRType Ftype >
PMFir<Ftype>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target)
{
}

/// @brief The constructor for FIR class for PPM Error
///
/// @param [in] <FIRTYPE_PPM_LFIR>  FIR Type for PPM
/// @param [in] i_target            EQ Target
///
template <>
PMFir<FIRTYPE_PPM_LFIR>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ >& i_target)
{
    uint8_t l_chpltNumber = 0;

    // Fetch the position of the EQ Target
    fapi2::ReturnCode l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,
                                           l_chpltNumber);
    FAPI_DBG("EQ number = %d", l_chpltNumber);

    iv_mask_address = EQ_QPPM_ERRMSK;
    iv_eq = i_target;
    iv_targetType = EQ_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_write = false;
}

/// @brief Base constructor for FIR class to build object based on FIR type
///
/// @param [in] <F>              FIR type (template parameter)
/// @param [in] i_target         Core Target
///
template < FIRType Ftype >
PMFir<Ftype>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target)
{
}

/// @brief The constructor for FIR class for PPM Error
///
/// @param [in] <FIRTYPE_PPM_LFIR>  FIR Type for PPM
/// @param [in] i_target            Core Target
///
template <>
PMFir<FIRTYPE_PPM_LFIR>::PMFir(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target)
{
    uint8_t l_chpltNumber = 0;

    // Fetch the position of the CORE Target
    fapi2::ReturnCode l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,
                                           l_chpltNumber);
    FAPI_DBG("CORE number = %d", l_chpltNumber);

    iv_mask_address = C_CPPM_ERRMSK;
    iv_core = i_target;
    iv_targetType = CORE_TARGET;
    iv_fir_write = false;
    iv_action0_write = false;
    iv_action1_write = false;
    iv_mask_write = false;
}

/// @brief Get the values of FIRs, FIR masks & FIR actions
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::get(const regType i_reg)
{
    if (iv_targetType == PROC_TARGET)
    {
        if (i_reg == REG_FIR || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_proc, iv_fir_address, iv_fir));
            iv_fir_write = false;
        }

        if(i_reg == REG_ACTION0 || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_proc, iv_action0_address, iv_action0));
            iv_action0_write = false;
        }

        if(i_reg == REG_ACTION1 || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_proc, iv_action1_address, iv_action1));
            iv_action1_write = false;
        }

        if(i_reg == REG_FIRMASK || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_proc, iv_mask_address, iv_mask));
            iv_mask_write = false;
        }
    }

    else if (iv_targetType == EX_TARGET)
    {
        if (i_reg == REG_FIR || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_ex, iv_fir_address, iv_fir));
            iv_fir_write = false;
        }

        if(i_reg == REG_ACTION0 || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_ex, iv_action0_address, iv_action0));
            iv_action0_write = false;
        }

        if(i_reg == REG_ACTION1 || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_ex, iv_action1_address, iv_action1));
            iv_action1_write = false;
        }

        if(i_reg == REG_FIRMASK || i_reg == REG_ALL)
        {
            FAPI_TRY(fapi2::getScom(iv_ex, iv_mask_address, iv_mask));
            iv_mask_write = false;
        }
    }

    else if (iv_targetType == EQ_TARGET)
    {
        if (i_reg == REG_ERRMASK)
        {
            FAPI_TRY(fapi2::getScom(iv_eq, iv_mask_address, iv_mask));
            iv_mask_write = false;
        }
    }

    else if (iv_targetType == CORE_TARGET)
    {
        if (i_reg == REG_ERRMASK)
        {
            FAPI_TRY(fapi2::getScom(iv_core, iv_mask_address, iv_mask));
            iv_mask_write = false;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Put the modified values to the registers
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::put()
{
    uint64_t l_address = 0;

    if (iv_targetType == PROC_TARGET)
    {
        if (iv_fir_write == true)
        {
            l_address = iv_fir_address + BASE_WOR_INCR;
            FAPI_TRY(putScom(iv_proc, l_address, iv_fir));
        }

        if (iv_action0_write == true)
        {
            FAPI_TRY(putScom(iv_proc, iv_action0_address, iv_action0));
        }

        if (iv_action1_write == true)
        {
            FAPI_TRY(putScom(iv_proc, iv_action1_address, iv_action1));
        }

        if (iv_mask_write == true)
        {
            l_address = iv_fir_address + MASK_WOR_INCR;
            FAPI_TRY(putScom(iv_proc, l_address, iv_mask));
        }
    }

    else if (iv_targetType == EX_TARGET)
    {
        if (iv_fir_write == true)
        {
            l_address = iv_fir_address + BASE_WOR_INCR;
            FAPI_TRY(putScom(iv_ex, l_address, iv_fir));
        }

        if (iv_action0_write == true)
        {
            FAPI_TRY(putScom(iv_ex, iv_action0_address, iv_action0));
        }

        if (iv_action1_write == true)
        {
            FAPI_TRY(putScom(iv_ex, iv_action1_address, iv_action1));
        }

        if (iv_mask_write == true)
        {
            l_address = iv_fir_address + MASK_WOR_INCR;
            FAPI_TRY(putScom(iv_ex, l_address, iv_mask));
        }
    }

    else if (iv_targetType == EQ_TARGET)
    {
        if (iv_mask_write == true)
        {
            FAPI_TRY(fapi2::putScom(iv_eq, iv_mask_address, iv_mask));
        }
    }

    else if (iv_targetType == CORE_TARGET)
    {
        if (iv_mask_write == true)
        {
            FAPI_TRY(fapi2::putScom(iv_core, iv_mask_address, iv_mask));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Set FIR bit action to checkstop (00)
///
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::setCheckStop(const uint32_t i_bit)
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
///
/// @param [in] i_bit  FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::setRecvAttn(const uint32_t i_bit)
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
///
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::setRecvIntr(const uint32_t i_bit)
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
///
/// @param [in] i_bit       FIR bit to act upon
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::setMalfAlert(const uint32_t i_bit)
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
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::mask(const uint32_t i_bit)
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
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::unmask(const uint32_t i_bit)
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
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::setAllRegBits(const regType i_reg)
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
template <FIRType Ftype>
fapi2::ReturnCode PMFir<Ftype>::clearAllRegBits(const regType i_reg)
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
template < FIRType Ftype >
fapi2::ReturnCode PMFir<Ftype>::saveMask()
{
    return fapi2::current_err;
}

/// @brief Save the present OCC LFIR mask into attribute
///
/// @param [in] <FIRTYPE_OCC_LFIR> OCC FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_OCC_LFIR>::saveMask()
{
    uint32_t l_mask;
    iv_mask.extract<0, 32>(l_mask);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_OCC_LFIR, iv_proc, l_mask),
             "ERROR: Failed to save OCC LFIR");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Save the present PBA LFIR mask into attribute
///
/// @param [in] <FIRTYPE_PBA_LFIR> PBA FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_PBA_LFIR>::saveMask()
{
    uint32_t l_mask;
    iv_mask.extract<0, 32>(l_mask);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PBA_LFIR, iv_proc, l_mask),
             "ERROR: Failed to save PBA LFIR");
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Save the present CME LFIR mask into attribute
///
/// @param [in] <FIRTYPE_CME_LFIR> CME FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_CME_LFIR>::saveMask()
{
    uint32_t l_mask;
    iv_mask.extract<0, 32>(l_mask);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CME_LOCAL_FIRMASK, iv_ex, l_mask),
             "ERROR: Failed to save CME LFIR");
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Save the present PPM Error mask into attribute
///
/// @param [in] <FIRTYPE_PPM_LFIR> PPM FIR Type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_PPM_LFIR>::saveMask()
{
    uint32_t l_mask;
    iv_mask.extract<0, 32>(l_mask);

    if (iv_targetType == EQ_TARGET)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_QUAD_PPM_ERRMASK, iv_eq, l_mask),
                 "ERROR: Failed to save Quad Error mask");
    }
    else if (iv_targetType == CORE_TARGET)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CORE_PPM_ERRMASK, iv_core, l_mask),
                 "ERROR: Failed to save Core Error mask");
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
template < FIRType Ftype >
fapi2::ReturnCode PMFir<Ftype>::restoreSavedMask()
{
    return fapi2::current_err;
}

/// @brief Restore saved OCC LFIR Mask
///
/// @param [in] <FIRTYPE_OCC_LFIR> OCC LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_OCC_LFIR>::restoreSavedMask()
{
    uint32_t l_mask;
    uint32_t l_tempMask;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCC_LFIR, iv_proc, l_mask),
             "ERROR: Failed to retrieve saved OCC LFIR");
    iv_mask.extract<0, 32>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 32>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved PBA LFIR Mask
///
/// @param [in] <FIRTYPE_PBA_LFIR> PBA LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_PBA_LFIR>::restoreSavedMask()
{
    uint32_t l_mask;
    uint32_t l_tempMask;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PBA_LFIR, iv_proc, l_mask),
             "ERROR: Failed to retrieve saved PBA LFIR");
    iv_mask.extract<0, 32>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 32>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved CME LFIR Mask
///
/// @param [in] <FIRTYPE_CME_LFIR> CME LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_CME_LFIR>::restoreSavedMask()
{
    uint32_t l_mask;
    uint32_t l_tempMask;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CME_LOCAL_FIRMASK, iv_ex, l_mask),
             "ERROR: Failed to retrieve saved CME LFIR mask");
    iv_mask.extract<0, 32>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 32>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Restore saved PPM Error Mask
///
/// @param [in] <FIRTYPE_PPM_LFIR> PPM LFIR type
///
/// @return FAPI2_RC_SUCCESS if success, else error code
///
template <>
fapi2::ReturnCode PMFir<FIRTYPE_PPM_LFIR>::restoreSavedMask()
{
    uint32_t l_mask;
    uint32_t l_tempMask;

    if (iv_targetType == EQ_TARGET)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_QUAD_PPM_ERRMASK, iv_eq, l_mask),
                 "ERROR: Failed to retrieve saved Quad Error Mask");
    }
    else if (iv_targetType == CORE_TARGET)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CORE_PPM_ERRMASK, iv_core, l_mask),
                 "ERROR: Failed to retrieve saved Core Error Mask");
    }

    iv_mask.extract<0, 32>(l_tempMask);
    l_mask |= l_tempMask;
    iv_mask.insertFromRight<0, 32>(l_mask);
    iv_mask_write = true;

fapi_try_exit:
    return fapi2::current_err;
}

}
#endif //_P9_PM_FIR_CLASS_H_
