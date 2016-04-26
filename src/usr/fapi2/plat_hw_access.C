/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_hw_access.C $                              */
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
/// @file plat_hw_access.C
///
/// @brief Implements hardware-access functions for the platform layer.
///

#include <stdint.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <return_code.H>
#include <buffer.H>
#include <target.H>
#include <target_types.H>
#include <hw_access_def.H>
#include <plat_utils.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2/plat_hw_access.H>

#include <scan/scanif.H>
#include <hw_access_def.H>


namespace fapi2
{

// Bits 7-15 are address portion
const uint32_t CFAM_ADDRESS_MASK = 0x1FF;

// Bits 0-6 are engine offset
const uint32_t CFAM_ENGINE_OFFSET = 0xFE00;

// Function prototypes
uint64_t platGetDDScanMode(const uint32_t i_ringMode);

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation called by getScom()
ReturnCode platGetScom(const Target<TARGET_TYPE_ALL>& i_target,
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

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

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
                  l_targName, i_address);
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        uint64_t l_data = (uint64_t)o_data;
        FAPI_SCAN("TRACE : GETSCOM     :  %s : %.16llX %.16llX",
                  l_targName,
                  i_address,
                  l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScom()
ReturnCode platPutScom(const Target<TARGET_TYPE_ALL>& i_target,
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

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

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
                  l_targName, i_address);
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        FAPI_SCAN("TRACE : PUTSCOM     :  %s : %.16llX %.16llX",
                  l_targName,
                  i_address,
                  l_data);
    }

    FAPI_DBG(EXIT_MRK "platPutScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScomUnderMask()
ReturnCode platPutScomUnderMask(const Target<TARGET_TYPE_ALL>& i_target,
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

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

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
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
       FAPI_ERR("platPutScomUnderMask failed - Target %s, Addr %.16llX",
                l_targName, i_address);
    }

    if( l_traceit )
    {
        uint64_t l_data = i_data;
        uint64_t l_mask = i_mask;
        FAPI_SCAN( "TRACE : PUTSCOMMASK : %s : %.16llX %.16llX %.16llX",
                   l_targName,
                   i_address,
                   l_data,
                   l_mask);
    }

    FAPI_DBG(EXIT_MRK "platPutScomUnderMask");
    return l_rc;
}

/// @brief Verify target of a cfam access
errlHndl_t verifyCfamAccessTarget(const TARGETING::Target* i_target,
                                  const uint32_t i_address)
{
    errlHndl_t l_err = NULL;

    // Can't access cfam engine on the master processor
    TARGETING::Target* l_pMasterProcChip = NULL;
    TARGETING::targetService().
      masterProcChipTargetHandle( l_pMasterProcChip );

    if( l_pMasterProcChip == i_target )
    {
        FAPI_ERR("verifyCfamAccessTarget: Attempt to access CFAM register %.8X on the master processor chip",
                 i_address);
        /*@
         * @errortype
         * @moduleid     fapi2::MOD_FAPI2_VERIFYCFAMACCESSTARGET
         * @reasoncode   fapi2::RC_INVALID_TARG_TARGET
         * @userdata1    CFAM Address
         * @userdata2    HUID of input target
         * @devdesc      verifyCfamAccessTarget> Attempt to access CFAM
         *               on the master processor
         * @custdesc     Internal firmware error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   fapi2::MOD_FAPI2_VERIFYCFAMACCESSTARGET,
                                   fapi2::RC_INVALID_TARG_TARGET,
                                   i_address,
                                   TARGETING::get_huid(i_target),
                                   true /*SW error*/);
        l_err->collectTrace(FAPI_TRACE_NAME);
    }

    return l_err;
}

/// @brief Internal function that gets the chip target for cfam access
errlHndl_t getCfamChipTarget(const TARGETING::Target* i_target,
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

/// @brief Platform-level implementation called by getCfamRegister()
ReturnCode platGetCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                               const uint32_t i_address,
                               buffer<uint32_t>& o_data)
{
    FAPI_DBG(ENTER_MRK "platGetCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the target pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: getCfamChipTarget returns error!");
            FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X",
                      l_targName, i_address);
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: verifyCfamAccessTarget returns error!");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM read via FSI
        // Address needs to be multiply by 4 because register addresses are
        //  word offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset in the top byte
        uint64_t l_addr = ((i_address & CFAM_ADDRESS_MASK) << 2) |
            (i_address & CFAM_ENGINE_OFFSET);
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &o_data(),
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: deviceRead returns error!");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while(0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
       FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X",
                 l_targName, i_address);
    }

    if( l_traceit )
    {
        uint32_t l_data = (uint32_t)o_data;
        FAPI_SCAN( "TRACE : GETCFAMREG  : %s : %.8X %.8X",
                   l_targName,
                   i_address,
                   l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetCfamRegister");
    return l_rc;
}

/// @brief Platform-level implementation called by putCfamRegister()
ReturnCode platPutCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                               const uint32_t i_address,
                               const buffer<uint32_t> i_data)
{
    FAPI_DBG(ENTER_MRK "platPutCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: getCfamChipTarget returns error!");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: verifyCfamAccessTarget returns error!");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM write via FSI
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets
        // However, we need to preserve the engine's offset in the top byte
        uint64_t l_addr = ((i_address & CFAM_ADDRESS_MASK) << 2) |
            (i_address & CFAM_ENGINE_OFFSET);
        size_t l_size = sizeof(uint32_t);
        uint32_t l_data  = static_cast<uint32_t>(i_data);
        l_err = deviceWrite(l_myChipTarget,
                            &l_data,
                            l_size,
                            DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: deviceWrite returns error!");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("platPutCfamRegister failed - Target %s, Addr %.8X",
                 l_targName, i_address);
    }

    if( l_traceit )
    {
        uint32_t l_data = i_data;
        FAPI_SCAN( "TRACE : PUTCFAMREG  : %s : %.8X %.8X",
                   l_targName,
                   i_address,
                   l_data);
    }

    FAPI_DBG(EXIT_MRK "platPutCfamRegister");
    return l_rc;
}


/// @brief   Modifying input 32-bit data with the specified mode
void platProcess32BitModifyMode( const ChipOpModifyMode i_modifyMode,
                                 const buffer<uint32_t> i_origDataBuf,
                                 buffer<uint32_t>& io_modifiedData )
{
    switch( i_modifyMode )
    {
            // OR operation
        case( fapi2::CHIP_OP_MODIFY_MODE_OR ):
            io_modifiedData |= i_origDataBuf;
            break;
            // AND operation
        case( fapi2::CHIP_OP_MODIFY_MODE_AND ):
            io_modifiedData &= i_origDataBuf;
            break;
            // XOR operation
        case( fapi2::CHIP_OP_MODIFY_MODE_XOR ):
            io_modifiedData ^= i_origDataBuf;
            break;

            // deliberately have no default case to catch new modes
            //  at compile time
    }
    return;
}

/// @brief   String translation for modify mode
const char* platModeString( const ChipOpModifyMode i_modifyMode )
{
    const char* l_modString = "???";
    switch( i_modifyMode )
    {
            // OR operation
        case( fapi2::CHIP_OP_MODIFY_MODE_OR ):
            l_modString = "OR";
            break;
            // AND operation
        case( fapi2::CHIP_OP_MODIFY_MODE_AND ):
            l_modString = "AND";
            break;
            // XOR operation
        case( fapi2::CHIP_OP_MODIFY_MODE_XOR ):
            l_modString = "XOR";
            break;

            // deliberately have no default case to catch new modes
            //  at compile time
    }
    return l_modString;
}

/// @brief Platform-level implementation of modifyCfamRegister()
ReturnCode platModifyCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                                  const uint32_t i_address,
                                  const buffer<uint32_t> i_data,
                                  const ChipOpModifyMode i_modifyMode)
{
    FAPI_DBG(ENTER_MRK "platModifyCfamRegister");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    bool l_traceit = platIsScanTraceEnabled();
    const char* l_modeString = platModeString(i_modifyMode);

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(i_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: verifyCfamAccessTarget returns error!");
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
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

        // Read current value
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000
        uint64_t l_addr = ((i_address & CFAM_ADDRESS_MASK) << 2) |
            (i_address & CFAM_ENGINE_OFFSET);
        buffer<uint32_t> l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &l_data(),
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: deviceRead returns error!");
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
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("platModifyCfamRegister failed - Target %s, Addr %.8X",
                  l_targName, i_address);
    }

    if( l_traceit )
    {
        uint32_t l_data = (uint32_t)i_data;
        FAPI_SCAN( "TRACE : MODCFAMREG  : %s : %.8X %.8X %s",
                   l_targName,
                   i_address,
                   l_data,
                   l_modeString );
    }

    FAPI_DBG(EXIT_MRK "platModifyCfamRegister");
    return l_rc;
}

/// @brief Platform-level implementation called by getRing()
ReturnCode platGetRing(const Target<TARGET_TYPE_ALL>& i_target,
                       const scanRingId_t i_address,
                       variable_buffer& o_data,
                       const RingMode i_ringMode)
{
    FAPI_DBG(ENTER_MRK "platGetRing");

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    // Output buffer must be set to ring's len by user
    uint64_t l_ringLen = o_data.getBitLength();
    uint64_t l_flag = platGetDDScanMode(i_ringMode);
    size_t l_size = o_data.getLength<uint8_t>();
    l_err = deviceRead(l_target,
                       o_data.pointer(),
                       l_size,
                       DEVICE_SCAN_ADDRESS(i_address, l_ringLen, l_flag));
    if (l_err)
    {
        FAPI_ERR("platGetRing: deviceRead returns error!");
        FAPI_ERR("fapiGetRing failed - Target %s, Addr %.16llX",
                  l_targName, i_address);
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        uint64_t l_data = o_data.get<uint64_t>();
        FAPI_SCAN("TRACE : GETRING     :  %s : %.16llX %.16llX",
                  l_targName,
                  i_address,
                  l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetRing");
    return l_rc;
}


// This will be used in future Cumulus code
/// @brief Platform-level implementation called by putRing()
inline ReturnCode platPutRing(const Target<TARGET_TYPE_ALL>& i_target,
                              const scanRingId_t i_address,
                              variable_buffer& i_data,
                              const RingMode i_ringMode)
{
    FAPI_DBG(ENTER_MRK "platPutRing");
    ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    // Output buffer must be set to ring's len by user
    uint64_t l_ringLen = i_data.getBitLength();
    uint64_t l_flag = platGetDDScanMode(i_ringMode);
    size_t l_size = i_data.getLength<uint8_t>();
    l_err = deviceWrite(l_target,
                        i_data.pointer(),
                        l_size,
                        DEVICE_SCAN_ADDRESS(i_address, l_ringLen, l_flag));
    if (l_err)
    {
        FAPI_ERR("platPutRing: deviceRead returns error!");
        FAPI_ERR("fapiPutRing failed - Target %s, Addr %.16llX",
                  l_targName, i_address);
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    if (l_traceit)
    {
        uint64_t l_data = i_data.get<uint64_t>();
        FAPI_SCAN("TRACE : PUTRING     :  %s : %.16llX %.16llX",
                  l_targName,
                  i_address,
                  l_data);
    }

    FAPI_DBG(EXIT_MRK "platPutRing");
    return l_rc;
}


/// @brief Platform-level implementation called by modifyRing()
ReturnCode platModifyRing(const Target<TARGET_TYPE_ALL>& i_target,
                          const scanRingId_t i_address,
                          const variable_buffer& i_data,
                          const ChipOpModifyMode i_modifyMode,
                          const RingMode i_ringMode)
{
    FAPI_DBG(ENTER_MRK "platModifyRing");

    // TODO RTC:152489 - story to finish this modifyRing
    FAPI_ERR("platModifyRing: not supported yet");
    assert(0,"platModifyRing not supported yet.");

    ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    variable_buffer l_current_data(i_data);

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // --------------------
        // Read current value
        // --------------------
        uint64_t l_ringLen = l_current_data.getBitLength();
        uint64_t l_flag = platGetDDScanMode(i_ringMode);
        size_t l_size = l_current_data.getLength<uint8_t>();
        l_err = deviceRead(l_target,
                           l_current_data.pointer(),
                           l_size,
                           DEVICE_SCAN_ADDRESS(i_address, l_ringLen, l_flag));
        if (l_err)
        {
            FAPI_ERR("platModifyRing: deviceRead returns error!");
            FAPI_ERR("platModifyRing failed - Target %s, Addr %.16llX",
                  l_targName, i_address);

            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));

            // break out if read fails
            break;
        }

        // ----------------------
        // Applying modification
        // ----------------------
        /* TODO-RTC:151261 - re-enable when variable_buffer operations supported
        if (fapi2::CHIP_OP_MODIFY_MODE_OR == i_modifyMode)
        {
            l_current_data |= i_data;
        }
        else if (fapi2::CHIP_OP_MODIFY_MODE_AND == i_modifyMode)
        {
            l_current_data &= i_data;
        }
        else
        {
            l_current_data ^= i_data;
        } */


        // -------------------------
        // Write back updated data
        // -------------------------
        l_err = deviceWrite(l_target,
                        l_current_data.pointer(),
                        l_size,
                        DEVICE_SCAN_ADDRESS(i_address, l_ringLen, l_flag));
        if (l_err)
        {
            FAPI_ERR("platModifyRing: deviceWrite returns error!");
            FAPI_ERR("platModifyRing failed - Target %s, Addr %.16llX",
                  l_targName, i_address);
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    if (l_traceit)
    {
        uint64_t l_data = l_current_data.get<uint64_t>();
        FAPI_SCAN("TRACE : MODIFYRING  :  %s : %.16llX %.16llX",
                  l_targName,
                  i_address,
                  l_data);
    }
    FAPI_DBG(EXIT_MRK "platModifyRing");
    return l_rc;
}


ReturnCode platPutRing(const Target<TARGET_TYPE_ALL>& i_target,
                       const RingID i_ringID,
                       const RingMode i_ringMode)
{
    FAPI_DBG(ENTER_MRK "platPutRing with RingID");
    ReturnCode l_rc;

    // TODO-RTC:132654:Use SBE to drive scans

    FAPI_DBG(EXIT_MRK "platPutRing with RingID");
    return l_rc;
}

//******************************************************************************
// platGetDDScanMode function
//******************************************************************************
uint64_t platGetDDScanMode(const uint32_t i_ringMode)
{
    uint32_t l_scanMode = 0;

    if ( ((i_ringMode & fapi2::RING_MODE_SET_PULSE_NO_OPCG_COND) ==
         fapi2::RING_MODE_SET_PULSE_NO_OPCG_COND) ||
         ((i_ringMode & fapi2::RING_MODE_SET_PULSE_NSL) ==
         fapi2::RING_MODE_SET_PULSE_NSL) ||
         ((i_ringMode & fapi2::RING_MODE_SET_PULSE_SL) ==
         fapi2::RING_MODE_SET_PULSE_SL) ||
         ((i_ringMode & fapi2::RING_MODE_SET_PULSE_ALL) ==
         fapi2::RING_MODE_SET_PULSE_ALL) )
    {
        l_scanMode |= SCAN::SET_PULSE;
    }

    // Header Check
    if ((i_ringMode & fapi2::RING_MODE_NO_HEADER_CHECK) ==
         fapi2::RING_MODE_NO_HEADER_CHECK )
    {
        l_scanMode |= SCAN::NO_HEADER_CHECK;
    }

    return l_scanMode;
}

// --------------------------------------------------------------------------
// NOTE:
// No spy access interface as HB doesn't allow spy access.
// --------------------------------------------------------------------------


} // End namespace

