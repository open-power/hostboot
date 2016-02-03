/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hw_access.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file plat_hw_access.H
///
/// @brief Defines hardware-access functions for the platform layer.
/// Hardware procedure writers will not call these functions.
/// These platform entry points are called by fapi2 functions from
/// hw_access.H, output scand traces common to all platforms.
/// These functions have the same argument signatures as the
/// fapi-level functions, but the function names her start with
/// "plat."
///

#ifndef PLATHWACCESS_H_
#define PLATHWACCESS_H_

#include <stdint.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <return_code.H>
#include <buffer.H>
#include <target.H>
#include <target_types.H>
#include <hw_access_def.H>
#include <plat_utils.H>

namespace fapi2
{

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

///
/// @brief Platform-level implementation called by getScom()
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  SCOM register address to read from.
/// @param[out] o_date     Buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platGetScom(const Target<K>& i_target,
                              const uint64_t i_address,
                              buffer<uint64_t>& o_data)
{
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    FAPI_DBG(ENTER_MRK "platGetScom");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Extract the component pointer
    TARGETING::Target* l_target =
              reinterpret_cast<TARGETING::Target*>(i_target.get());

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    // Perform SCOM read
    size_t l_size = sizeof(uint64_t);
    l_err = deviceRead(l_target,
                       &o_data(),
                       l_size,
                       DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        FAPI_ERR("platGetScom: deviceRead returns error!");
        FAPI_ERR("fapiGetScom failed - Target %s, Addr %.16llX",
                  tmpScomStr, i_address);
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        uint64_t l_data = (uint64_t)o_data;
        FAPI_SCAN("TRACE : GETSCOM     :  %s : %.16llX %.16llX",
                      tmpScomStr,
                      i_address,
                      l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScom()
/// @Tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode platPutScom(const Target<K>& i_target,
                              const uint64_t i_address,
                              const buffer<uint64_t> i_data)
{
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    FAPI_DBG(ENTER_MRK "platPutScom");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Extract the component pointer
    TARGETING::Target* l_target =
              reinterpret_cast<TARGETING::Target*>(i_target.get());

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    // Perform SCOM write
    size_t l_size = sizeof(uint64_t);
    uint64_t l_data  = static_cast<uint64_t>(i_data);
    l_err = deviceWrite(l_target,
                        &l_data,
                        l_size,
                        DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        FAPI_ERR("platPutScom: deviceRead returns error!");
        FAPI_ERR("platPutScom failed - Target %s, Addr %.16llX",
                  tmpScomStr, i_address);
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        FAPI_SCAN("TRACE : PUTSCOM     :  %s : %.16llX %.16llX",
                  tmpScomStr,
                  i_address,
                  l_data);
    }

    FAPI_DBG(EXIT_MRK "platPutScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScomUnderMask()
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode platPutScomUnderMask(const Target<K>& i_target,
                                       const uint64_t i_address,
                                       const buffer<uint64_t> i_data,
                                       const buffer<uint64_t> i_mask)
{
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    FAPI_DBG(ENTER_MRK "platPutScomUnderMask");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    do
    {
        // Extract the component pointer
        TARGETING::Target* l_target =
                  reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get current value from HW
        uint64_t l_data = 0;
        size_t l_size = sizeof(uint64_t);
        l_err = deviceRead(l_target,
                           &l_data,
                           l_size,
                           DEVICE_SCOM_ADDRESS(i_address));
        if (l_err)
        {
            FAPI_ERR("platPutScomUnderMask: deviceRead returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Calculate new value to write to reg
        uint64_t l_inMaskInverted = ~i_mask;    // Write mask inverted
        uint64_t l_newMask = (i_data & i_mask);  // Retain set data bits

        // l_data = current data set bits
        l_data &= l_inMaskInverted;

        // l_data = current data set bit + set mask bits
        l_data |= l_newMask;

        // Write new value
        l_err = deviceWrite(l_target,
                            &l_data,
                            l_size,
                            DEVICE_SCOM_ADDRESS(i_address));
        if (l_err)
        {
            FAPI_ERR("platPutScomUnderMask: deviceWrite returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
       FAPI_ERR("platPutScomUnderMask failed - Target %s, Addr %.16llX",
                tmpScomStr, i_address);
    }

    if( l_traceit )
    {
        uint64_t l_data = i_data;
        uint64_t l_mask = i_mask;
        FAPI_SCAN( "TRACE : PUTSCOMMASK : %s : %.16llX %.16llX %.16llX",
               tmpScomStr,
               i_address,
               l_data,
               l_mask);
    }

    FAPI_DBG(EXIT_MRK "platPutScomUnderMask");
    return l_rc;
}

///
/// @brief Platform-level implementation of modifyScom()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    SCOM address to modify.
/// @param[out] i_data       64-bit buffer that holds data to modify.
/// @param[in]  i_modifyMode The modify mode (or/and/xor).
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platModifyScom(const Target<K>& i_target,
                                 const uint32_t i_address,
                                 const buffer<uint32_t> i_data,
                                 const fapi2::ChipOpModifyMode i_modifyMode)
{

   // --------------- Will implement when needed --------------------

    FAPI_DBG(ENTER_MRK "platModifyScom");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    FAPI_ERR("platModifyScom: Error: Hostboot not yet support modifyScom function!");

    // Add the error log pointer as data and set the ReturnCode as needed

    FAPI_DBG(EXIT_MRK "platModifyScom");
    return l_rc;
}

///
/// @brief Verify target of a cfam access
/// We can't access the cfam engine of the master processor.
/// Only allow access to the other processors.
/// This function will return an error if the input target is
/// the boot processor.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to read from.
/// @return     errlHndl_t
///
template< TargetType K >
static errlHndl_t verifyCfamAccessTarget(const Target<K>& i_target,
                                         const uint32_t i_address)
{
    errlHndl_t l_err = NULL;

    // Can't access cfam engine on the master processor
    if (i_target.getType() == fapi2::TARGET_TYPE_PROC_CHIP)
    {
        TARGETING::Target* l_pMasterProcChip = NULL;
        TARGETING::targetService().
            masterProcChipTargetHandle( l_pMasterProcChip );

        TARGETING::Target* l_pTarget =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

        if( l_pMasterProcChip == l_pTarget )
        {
            FAPI_ERR("verifyCfamAccessTarget: Attempt to access CFAM register %.8X on the master processor chip",
                     i_address);
        }
    }
    return l_err;
}

///
/// @brief Internal function that gets the chip target for cfam access
/// HW procedures may pass in non-chip targets (such as MBA or
/// MBS as a target), so we need to find the parent chip in order
/// to pass it to the device driver.
/// @param[in]  i_target     HW target to operate on.
/// @param[out] o_chipTarget The output chip target.
/// @return     errlHndl_t
///
static errlHndl_t getCfamChipTarget(const TARGETING::Target* i_target,
                                    TARGETING::Target*& o_chipTarget)
{
    errlHndl_t l_err = NULL;

    // Default to input target
    o_chipTarget = const_cast<TARGETING::Target*>(i_target);

    // Check to see if this is a chiplet
    if (i_target->getAttr<TARGETING::ATTR_CLASS>() == TARGETING::CLASS_UNIT)
    {
        // Look for its chip parent
        TARGETING::PredicateCTM l_chipClass(TARGETING::CLASS_CHIP);
        TARGETING::TargetHandleList l_list;
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        (void) l_targetService.getAssociated(
                l_list,
                i_target,
                TARGETING::TargetService::PARENT,
                TARGETING::TargetService::ALL,
                &l_chipClass);

        if ( l_list.size() == 1 )
        {
            o_chipTarget = l_list[0];
        }
        else
        {
            // Something is wrong here, can't have more than one parent chip
            FAPI_ERR("getCfamChipTarget: Invalid number of parent chip for this target chiplet - # parent chips %d", l_list.size());
        }
    }
    return l_err;
}

///
/// @brief Platform-level implementation called by getCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to read from.
/// @param[out] o_data     32-bit buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platGetCfamRegister(const Target<K>& i_target,
                                      const uint32_t i_address,
                                      buffer<uint32_t>& o_data)
{
    FAPI_DBG(ENTER_MRK "platGetCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    do
    {
        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: verifyCfamAccessTarget returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: getCfamChipTarget returns error!");
            FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X",
                      tmpScomStr, i_address);
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM read via FSI
        // Address needs to be multiply by 4 because register addresses are
        //  word offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &o_data(),
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: deviceRead returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while(0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
       FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X",
                 tmpScomStr, i_address);
    }

    if( l_traceit )
    {
        uint32_t l_data = (uint32_t)o_data;
        FAPI_SCAN( "TRACE : GETCFAMREG  : %s : %.8X %.8X",
               tmpScomStr,
               i_address,
               l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetCfamRegister");
    return l_rc;
}

///
/// @brief Platform-level implementation called by putCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to write to.
/// @param[out] i_data     32-bit buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platPutCfamRegister(const Target<K>& i_target,
                                      const uint32_t i_address,
                                      const buffer<uint32_t> i_data)
{
    FAPI_DBG(ENTER_MRK "platPutCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    do
    {
        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: verifyCfamAccessTarget returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        TARGETING::Target* l_myChipTarget = NULL;
        // Get the chip target if l_target is not a chip
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: getCfamChipTarget returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM write via FSI
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        size_t l_size = sizeof(uint32_t);
        uint32_t l_data  = static_cast<uint32_t>(i_data);
        l_err = deviceWrite(l_myChipTarget,
                            &l_data,
                            l_size,
                            DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: deviceWrite returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("platPutCfamRegister failed - Target %s, Addr %.8X",
                 tmpScomStr, i_address);
    }

    if( l_traceit )
    {
        uint32_t l_data = i_data;
        FAPI_SCAN( "TRACE : PUTCFAMREG  : %s : %.8X %.8X",
                    tmpScomStr,
                    i_address,
                    l_data);
    }

    FAPI_DBG(EXIT_MRK "platPutCfamRegister");
    return l_rc;
}


/// @brief   Modifying input 32-bit data with the specified mode
/// This method modify 32-bit input data (io_modifiedData) by applying the
/// specified modify mode along with the input data (i_origData).
///
/// @param[in]  i_modifyMode         Modification mode
/// @param[in]  i_origData           32-bit data to be used for modification
/// @param[out] io_modifiedData      32-bit data to be modified
///
/// @return void
///
static void platProcess32BitModifyMode(
                                const fapi2::ChipOpModifyMode i_modifyMode,
                                const buffer<uint32_t> i_origDataBuf,
                                buffer<uint32_t>& io_modifiedData)
{

//@TODO RTC:143118 This should be a switch statement

    // OR operation
    if (fapi2::CHIP_OP_MODIFY_MODE_OR == i_modifyMode)
    {
        io_modifiedData |= i_origDataBuf;
    }
    // AND operation
    else if (fapi2::CHIP_OP_MODIFY_MODE_AND == i_modifyMode)
    {
        io_modifiedData &= i_origDataBuf;
    }
    // Must be XOR operation
    else
    {
        io_modifiedData ^= i_origDataBuf;
    }

    return;
}

///
/// @brief Platform-level implementation of modifyCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    CFAM register address to modify.
/// @param[out] i_data       32-bit buffer that holds data to modify.
/// @param[in]  i_modifyMode The modify mode (or/and/xor).
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platModifyCfamRegister(const Target<K>& i_target,
                              const uint32_t i_address,
                              const buffer<uint32_t> i_data,
                              const fapi2::ChipOpModifyMode i_modifyMode)
{
    FAPI_DBG(ENTER_MRK "platModifyCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();

    //TODO: RTC 124195 - Support target::toEcmdString() for SCAN trace
    const char* tmpScomStr = "TargetString";

    do
    {
        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: verifyCfamAccessTarget returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: getCfamChipTarget returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Read current value
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        buffer<uint32_t> l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &l_data(),
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: deviceRead returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Applying modification
        platProcess32BitModifyMode(i_modifyMode, i_data, l_data);

        // Write back
        l_err = deviceWrite(l_target,
                            &l_data(),
                            l_size,
                            DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: deviceWrite returns error!");
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("platModifyCfamRegister failed - Target %s, Addr %.8X",
                  tmpScomStr, i_address);
    }

    if( l_traceit )
    {
        // get string representation of the modify mode
        const char * l_pMode = NULL;

        if (i_modifyMode == fapi2::CHIP_OP_MODIFY_MODE_OR)
        {
            l_pMode = "OR";
        }
        else if (i_modifyMode == fapi2::CHIP_OP_MODIFY_MODE_AND)
        {
            l_pMode = "AND";
        }
        else if (i_modifyMode == fapi2::CHIP_OP_MODIFY_MODE_XOR)
        {
            l_pMode = "XOR";
        }
        else
        {
            l_pMode = "?";
        }

        uint32_t l_data = (uint32_t)i_data;
        FAPI_SCAN( "TRACE : MODCFAMREG  : %s : %.8X %.8X %s",
               tmpScomStr,
               i_address,
               l_data,
               l_pMode );
    }

    FAPI_DBG(EXIT_MRK "platModifyCfamRegister");
    return l_rc;
}

//@TODO RTC:126630 getRing is not yet supported

#if 0

///
/// @brief Platform-level implementation called by fapiGetRing()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  Ring address to read from.
/// @param[out] o_data     Buffer that holds ring data read from HW target.
/// @param[in]  i_ringMode Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K >
inline ReturnCode platGetRing(const Target<K>& i_target,
                              const scanRingId_t i_address,
                              variable_buffer& o_data,
                              const RingMode i_ringMode = 0)
{
    FAPI_DBG(ENTER_MRK "platGetRing");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Output buffer must be set to ring's len by user
    uint64_t l_ringLen = o_data.getBitLength();
    uint64_t l_flag = platGetDDScanMode(i_ringMode);
    size_t l_size = o_data.getByteLength();
    l_err = deviceRead(l_target,
                 ecmdDataBufferBaseImplementationHelper::getDataPtr(&o_data),
                 l_size,
                 DEVICE_SCAN_ADDRESS(i_address, l_ringLen, l_flag));
    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "platGetRing");
    return l_rc;
}


/// @brief Platform-level implementation called by fapiPutRing()
/// Hardware procedures writers will not call this function.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_address  Ring address to write to.
/// @param[in] i_data     Buffer that contains RS4 compressed ring data
///                       to write into address
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode platPutRing(const Target<K>& i_target,
                              const scanRingId_t i_address,
                              variable_buffer& i_data,
                              const RingMode i_ringMode = 0)
{
}

/// @brief Platform-level implementation called by fapiModifyRing()
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor)
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode modifyRing(const Target<K>& i_target,
                             const scanRingId_t i_address,
                             variable_buffer& i_data,
                             const ChipOpModifyMode i_modifyMode,
                             const RingMode i_ringMode = 0)
{
}

#endif // End if 0

// --------------------------------------------------------------------------
// NOTE:
// No spy access interface as HB doesn't allow spy access.
// --------------------------------------------------------------------------


} // End namespace

#endif // PLATHWACCESS_H_
