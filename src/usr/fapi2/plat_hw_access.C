/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_hw_access.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <fapi2/plat_utils.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <scom/scomreasoncodes.H>
#include <fapi2/plat_hw_access.H>
#include <scom/errlud_pib.H>

#include <hw_access_def.H>
#include <arch/ppc.H>

#include <multicast_group_defs.H>
#include <multicast_defs.H>
#include <return_code_defs.H>
#include <hbotcompid.H>

namespace fapi2
{

// Bits 7-15 are address portion
const uint32_t CFAM_ADDRESS_MASK = 0x1FF;

// Bits 0-6 are engine offset
const uint32_t CFAM_ENGINE_OFFSET = 0xFE00;

// Operational mode for scom operations (ignore errors, wakeup core, etc.)
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
thread_local OpModes opMode = NORMAL;
#else
OpModes opMode = NORMAL;
#endif

// Bitmap of PIB errors to ignore during a PIB oeration
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
thread_local uint8_t pib_err_mask = 0x00;
#else
uint8_t pib_err_mask = 0x00;
#endif

// Multicast address parts
enum MulticastMasks : uint32_t
{
    CORE_SELECT_MASK       = 0x0000F000,
    MULTICAST_GROUP_MASK   = 0x07000000,
    MULTICAST_OP_MASK      = 0x38000000,
    MULTICAST_BIT          = 0x40000000,
};

enum MulticastOffsets : uint8_t
{
    CORE_SELECT_OFFSET     = 12,
    MULTICAST_GROUP_OFFSET = 24,
    MULTICAST_OP_OFFSET    = 27,
    MULTICAST_BIT_OFFSET   = 30,
};

// The MulticastGroup to hwValue (bits in the multicast address) map.
// There are only 3 multicast group bits in the multicast address,
// so the right side of the map must be <= 7.
std::map<MulticastGroup, uint32_t> g_multicastGroupMap = {
        {MCGROUP_ALL,        0x7},
        {MCGROUP_GOOD_NO_TP, 0x1},
        {MCGROUP_GOOD_MC,    0x2},
        {MCGROUP_GOOD_IOHS,  0x3},
        {MCGROUP_GOOD_PAU,   0x4},
        {MCGROUP_GOOD_PCI,   0x5},
        {MCGROUP_GOOD_EQ,    0x6} };

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation called by getScom()
ReturnCode platGetScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       buffer<uint64_t>& o_data)
{
    ReturnCode l_rc = FAPI2_RC_SUCCESS;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platGetScom");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Extract the component pointer
    TARGETING::Target* l_target = i_target.get();

    do
    {

    if (l_target == nullptr)
    {
        o_data = 0;

        /*@
         * @errortype
         * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_SCOM
         * @reasoncode   fapi2::RC_INVALID_TARG_TARGET
         * @userdata1    SCOM address being read
         * @devdesc      NULL target pointer given to platGetScom
         * @custdesc     Internal firmware error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_GET_SCOM,
                                        fapi2::RC_INVALID_TARG_TARGET,
                                        i_address,
                                        0,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        addErrlPtrToReturnCode(l_rc, l_err);
        l_rc.setRC(fapi2::FAPI2_RC_INVALID_PARAMETER);
        break;
    }

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

     uint64_t l_scomAddr = i_address;
     if(i_target.get().isMulticast())
     {
         // Compose the multicast address based on multicast params
         l_scomAddr = fapi2::getMulticastAddr(l_scomAddr,
                                             i_target.get().getMulticastGroup(),
                                             i_target.get().getMulticastOp(),
                                             i_target.get().getCoreSelect());
     }

    // Perform SCOM read
    size_t l_size = sizeof(uint64_t);
    l_err = deviceRead(l_target,
                       &o_data(),
                       l_size,
                       DEVICE_SCOM_ADDRESS(l_scomAddr, opMode));

    //If an error occured durring the device read and a pib_err_mask is set,
    // then we will check if the err matches the mask, if it does we
    // ignore the error
    if(l_err && (pib_err_mask != 0x00))
    {
        checkPibMask(l_err);
    }

    if (l_err)
    {
        if(opMode & fapi2::IGNORE_HW_ERROR)
        {
            delete l_err;
            l_err = nullptr;
        }
        else
        {
            FAPI_ERR("platGetScom: deviceRead returns error!");
            FAPI_ERR("fapiGetScom failed - Target %s, Addr %.16llX",
                     l_targName, l_scomAddr);
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            if(l_err->getErrorType() == SCOM::SCOM_MULTICAST_MISCOMPARE)
            {
                l_rc.setRC(fapi2::FAPI2_RC_PLAT_MISCOMPARE);
            }
        }
    }

    if (l_traceit)
    {
        uint64_t l_data = (uint64_t)o_data;
        FAPI_SCAN("TRACE : GETSCOM     :  %s : %.16llX %.16llX",
                  l_targName,
                  l_scomAddr,
                  l_data);
    }

    } while (false);

    FAPI_DBG(EXIT_MRK "platGetScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScom()
ReturnCode platPutScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       const buffer<uint64_t> i_data)
{
    ReturnCode l_rc = FAPI2_RC_SUCCESS;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platPutScom");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_hw_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Extract the component pointer
    TARGETING::Target* l_target = i_target.get();

    do
    {

    if (l_target == nullptr)
    {
        /*@
         * @errortype
         * @moduleid     fapi2::MOD_FAPI2_PLAT_PUT_SCOM
         * @reasoncode   fapi2::RC_INVALID_TARG_TARGET
         * @userdata1    SCOM address being written
         * @devdesc      NULL target pointer given to platPutScom
         * @custdesc     Internal firmware error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_PUT_SCOM,
                                        fapi2::RC_INVALID_TARG_TARGET,
                                        i_address,
                                        0,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        addErrlPtrToReturnCode(l_rc, l_err);
        l_rc.setRC(fapi2::FAPI2_RC_INVALID_PARAMETER);
        break;
    }

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    uint64_t l_scomAddr = i_address;

    if(i_target.get().isMulticast())
    {
        // Compose the multicast address based on multicast params
        l_scomAddr = fapi2::getMulticastAddr(l_scomAddr,
                                             i_target.get().getMulticastGroup(),
                                             i_target.get().getMulticastOp(),
                                             i_target.get().getCoreSelect());
    }

    // Perform SCOM write
    size_t l_size = sizeof(uint64_t);
    uint64_t l_data  = static_cast<uint64_t>(i_data);
    l_err = deviceWrite(l_target,
                        &l_data,
                        l_size,
                        DEVICE_SCOM_ADDRESS(l_scomAddr, opMode));

    //If an error occured durring the device write and a pib_err_mask is set,
    // then we will check if the err matches the mask, if it does we
    // ignore the error
    if(l_err && (pib_err_mask != 0x00))
    {
        checkPibMask(l_err);
    }

    if (l_err)
    {
        if(opMode & fapi2::IGNORE_HW_ERROR)
        {
            delete l_err;
            l_err = nullptr;
        }
        else
        {
            FAPI_ERR("platPutScom: deviceWrite returns error!");
            FAPI_ERR("platPutScom failed - Target %s, Addr %.16llX",
                     l_targName, l_scomAddr);
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
        }
    }

    if (l_traceit)
    {
        FAPI_SCAN("TRACE : PUTSCOM     :  %s : %.16llX %.16llX",
                  l_targName,
                  l_scomAddr,
                  l_data);
    }

    } while (false);

    FAPI_DBG(EXIT_MRK "platPutScom");
    return l_rc;
}

/// @brief Platform-level implementation called by putScomUnderMask()
ReturnCode platPutScomUnderMask(const Target<TARGET_TYPE_ALL>& i_target,
                                const uint64_t i_address,
                                const buffer<uint64_t> i_data,
                                const buffer<uint64_t> i_mask)
{
    ReturnCode l_rc = FAPI2_RC_SUCCESS;
    errlHndl_t l_err = nullptr;

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
        TARGETING::Target* l_target = i_target.get();

        // Get current value from HW
        uint64_t l_data = 0;
        size_t l_size = sizeof(uint64_t);
        l_err = deviceRead(l_target,
                           &l_data,
                           l_size,
                           DEVICE_SCOM_ADDRESS(i_address,opMode));
        if (l_err && !(opMode & fapi2::IGNORE_HW_ERROR))
        {
            FAPI_ERR("platPutScomUnderMask: deviceRead returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            break;
        }
        else if(l_err)
        {
            delete l_err;
            l_err = nullptr;
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
                            DEVICE_SCOM_ADDRESS(i_address,opMode));
        if (l_err && !(opMode & fapi2::IGNORE_HW_ERROR))
        {
            FAPI_ERR("platPutScomUnderMask: deviceWrite returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            break;
        }
        else if (l_err)
        {
            delete l_err;
            l_err = nullptr;
            break;

        }

    } while (0);

    if(l_err && (pib_err_mask != 0x00))
    {
        checkPibMask(l_err);
    }

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
    errlHndl_t l_err = nullptr;

    // Can't access cfam engine on the master processor
    TARGETING::Target* l_pMasterProcChip = nullptr;
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
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_err->collectTrace(FAPI_TRACE_NAME);
    }

    return l_err;
}

/// @brief takes in an error log and looks for user details sections
///        with a compId of SCOM_COMP_ID. If one of those is found and
///        the pib err attatched to it matches the pib_err_mask, then
///        we delete the err.
void checkPibMask(errlHndl_t& io_errLog )
{
    //Delete the error if the mask matches the pib err
    for(auto data : io_errLog->getUDSections(SCOM_COMP_ID, SCOM::SCOM_UDT_PIB))
    {
        //We get the raw data from the userdetails section, which in this
        //case is the pib_err itself so just check it.
        if(*reinterpret_cast<uint8_t *>(data) == pib_err_mask)
        {
            FAPI_ERR( "Ignoring error %.8X due to pib_err_mask=%.1X", io_errLog->plid(), pib_err_mask );
            delete io_errLog;
            io_errLog = nullptr;
            break;
        }
    }
    return;
}

/// @brief Internal function that gets the chip target for cfam access
errlHndl_t getCfamChipTarget(const TARGETING::Target* i_target,
                             TARGETING::Target*& o_chipTarget)
{
    errlHndl_t l_err = nullptr;

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
            /*@
            * @errortype
            * @moduleid     fapi2::MOD_FAPI2_GET_CHIP_CFAM_TARGET
            * @reasoncode   fapi2::RC_INVALID_PARENT_TARGET_FOUND
            * @userdata1    Number of parent proc chips found
            * @userdata2    HUID of input target
            * @devdesc      Detecting more than 1 parent proc targets
            * @custdesc     Internal firmware error
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            fapi2::MOD_FAPI2_GET_CHIP_CFAM_TARGET,
                                            fapi2::RC_INVALID_PARENT_TARGET_FOUND,
                                            l_list.size(),
                                            TARGETING::get_huid(i_target),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_err->collectTrace(FAPI_TRACE_NAME);
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
    errlHndl_t l_err = nullptr;
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the target pointer
        TARGETING::Target* l_target = i_target.get();

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = nullptr;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: getCfamChipTarget returns error!");
            FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X",
                      l_targName, i_address);

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            break;
        }

        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(l_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platGetCfamRegister: verifyCfamAccessTarget returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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
    errlHndl_t l_err = nullptr;
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the component pointer
        TARGETING::Target* l_target = i_target.get();

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = nullptr;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: getCfamChipTarget returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            break;
        }

        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(l_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platPutCfamRegister: verifyCfamAccessTarget returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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
    errlHndl_t l_err = nullptr;
    bool l_traceit = platIsScanTraceEnabled();
    const char* l_modeString = platModeString(i_modifyMode);

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do
    {
        // Extract the component pointer
        TARGETING::Target* l_target = i_target.get();

        // Can't access cfam engine on master processor
        l_err = verifyCfamAccessTarget(l_target,i_address);
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: verifyCfamAccessTarget returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
            break;
        }

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = nullptr;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            FAPI_ERR("platModifyCfamRegister: getCfamChipTarget returns error!");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_err);
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
            addErrlPtrToReturnCode(l_rc, l_err);
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

//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

void platSetOpMode(const OpModes i_mode)
{
    FAPI_INF("Setting fapi2::opMode to be 0x%x", i_mode);
    opMode = static_cast<OpModes>(
            static_cast<uint8_t>(opMode) | static_cast<uint8_t>(i_mode)
            );
    return;
}

OpModes platGetOpMode(void)
{
    return opMode;
}

//--------------------------------------------------------------------------
// PIB Error Mask Functions
//--------------------------------------------------------------------------

void platSetPIBErrorMask(const uint8_t i_mask)
{
    assert(i_mask <= 7, "PIB Err Mask must be between 0 and 7");
    pib_err_mask = i_mask;
    return;
}

uint8_t platGetPIBErrorMask(void)
{
    return pib_err_mask;
}


// --------------------------------------------------------------------------
// NOTE:
// No spy access interface as HB doesn't allow spy access.
// --------------------------------------------------------------------------

/**
 * @brief Determine if a given target is on the boot proc chip
 * @param[in]  i_Target   TARGETING::Target which op is being called on
 * @param[out] i_isMaster True if on boot proc chip, false if not
 * @return errlHndl_t
 */
errlHndl_t isOnBootProc(TARGETING::Target * i_target, bool & o_isBootProc)
{
    errlHndl_t l_errl = nullptr;
    assert(i_target != nullptr, "isOnBootProc:: Cannot pass nullptr target to isOnBootProc");
    TARGETING::Target* l_pBootProcChip = nullptr;
    TARGETING::Target* l_pParentProcChip = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle( l_pBootProcChip );
    assert(l_pBootProcChip != nullptr, "isOnBootProc:: Unable to find the system's boot proc chip target handle");
    o_isBootProc = false;

    // Target can be a chiplet or a proc, get the parent proc in case it's a chiplet
    l_errl = getCfamChipTarget(i_target, l_pParentProcChip);
    if(l_errl == nullptr)
    {
        if(l_pBootProcChip == l_pParentProcChip)
        {
            o_isBootProc = true;
        }
    }
    return l_errl;
}

uint32_t getPlatMCGroup(const MulticastGroup i_group)
{
    assert(i_group < MCGROUP_COUNT, "getPlatMCGroup: invalid i_group");
    auto l_iterator = g_multicastGroupMap.find(i_group);
    assert(l_iterator != g_multicastGroupMap.end(),
          "getPlatMCGroup: could not find Multicast Group mapping for group %d",
          i_group);
    return l_iterator->second;
}

uint64_t getMulticastAddr(uint64_t i_addr,
                          const MulticastGroup i_group,
                          const MulticastType i_op,
                          const MulticastCoreSelect i_coreSelect)
{
    uint64_t l_resultingAddress = i_addr;
    // Set the mulitcast bit (bit 1)
    l_resultingAddress |= MULTICAST_BIT;
    // Copy in the op (bits 2, 3, 4)
    l_resultingAddress &= ~MULTICAST_OP_MASK;
    l_resultingAddress |= (i_op << MULTICAST_OP_OFFSET);
    // Copy in the group (bits 5, 6, 7)
    l_resultingAddress &= ~MULTICAST_GROUP_MASK;
    l_resultingAddress |= (getPlatMCGroup(i_group) << MULTICAST_GROUP_OFFSET);

    if(i_coreSelect != MCCORE_NONE)
    {
        // Copy in the core select (bits 16, 17, 18, 19)
        l_resultingAddress &= ~CORE_SELECT_MASK;
        l_resultingAddress |= (i_coreSelect << CORE_SELECT_OFFSET);
    }
    return l_resultingAddress;
}

bool isMulticastBitSet(const uint32_t i_scomAddr)
{
    return ((i_scomAddr & MULTICAST_BIT) >> MULTICAST_BIT_OFFSET);
}

MulticastGroup getMulticastGroup(const uint32_t i_multicastScomAddr)
{
    return static_cast<MulticastGroup>(
                ((i_multicastScomAddr & MULTICAST_GROUP_MASK) >>
                    MULTICAST_GROUP_OFFSET));
}

MulticastType getMulticastOp(const uint32_t i_multicastScomAddr)
{
    return static_cast<MulticastType>(
                ((i_multicastScomAddr & MULTICAST_OP_MASK) >>
                    MULTICAST_OP_OFFSET));
}

MulticastCoreSelect getCoreSelect(const uint32_t i_multicastScomAddr)
{
    return static_cast<MulticastCoreSelect>(
                ((i_multicastScomAddr & CORE_SELECT_MASK) >>
                    CORE_SELECT_OFFSET));
}

} // End namespace
