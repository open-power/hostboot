/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scomtrans.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
*  @file scomtrans.C
*
*  @brief Implementation of SCOM operations
*/


// Code up to date for version: p8 1.9/s1 1.3 of p8.chipunit.scominfo

//Flow of the file:
//Call startScomProcess --which calls--> scomTranslate
// --which calls--> p10 translate --which returns to-->
//startScomProcces --which then calls--> SCOM::checkIndirectAndDoScom

/****************************************************************************/
// I n c l u d e s
/****************************************************************************/
#include <string.h>
#include <assert.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "scom.H"
#include "scomtrans.H"
#include <scom/scomif.H>
#include <scom/scomreasoncodes.H>
#include <errl/errludtarget.H>
#include <initservice/initserviceif.H>
#include <p10_scom_addr.H>
#include <p10_scominfo.H>
#include <hw_access_def.H>
#include <fapi2/fapiPlatTrace.H>

#if __HOSTBOOT_RUNTIME
  #include <scom/wakeup.H>
#endif

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{

bool g_wakeupInProgress = false;

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MC,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_FC,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_CORE,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_PERV,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_EQ,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MI,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_PEC,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_PHB,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_OCC,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MCC,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_NMMU,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_IOHS,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_OMIC,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_OMI,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_PAU,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_PAUC,
                      startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MEM_PORT,
                      startScomProcess);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
errlHndl_t startScomProcess(DeviceFW::OperationType i_opType,
                        TARGETING::Target* i_target,
                        void* io_buffer,
                        size_t& io_buflen,
                        int64_t i_accessType,
                        va_list i_args)
{
    errlHndl_t l_err = NULL;

    do {
        //will hold the value of parent chip for indirect scom
        TARGETING::Target* l_parentChip = const_cast<TARGETING::Target *>
                                        (TARGETING::getParentChip(i_target));
        uint64_t l_addr = va_arg(i_args,uint64_t);
        // if opMode is not specified as an argument
        // va_arg will return NULL which=0
        uint64_t l_opMode = va_arg(i_args,uint64_t);
        bool l_needsWakeup = false;

        l_err = scomTranslate(i_target,
                              l_addr,
                              l_needsWakeup,
                              l_opMode);
        if(l_err)
        {
            break;
        }

#if __HOSTBOOT_RUNTIME
        if(l_needsWakeup)
        {
            TRACDCOMP(g_trac_scom,"Special wakeup required, starting now..");
            g_wakeupInProgress = true;

            l_err = WAKEUP::handleSpecialWakeup(i_target,WAKEUP::ENABLE);

            // always clear the global flag, even on error, otherwise we'll
            //  never call wakeup again even for different targets
            g_wakeupInProgress = false;

            if(l_err)
            {
                TRACFCOMP(g_trac_scom, "startScomProcess: "
                          "handleSpecialWakeup enable ERROR");

                //capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                    .addToLog(l_err);

                l_err->collectTrace(SCOM_COMP_NAME);
                break;
            }
        }
#endif

        // call the routine that will do the indirect scom
        // and then call the correct device driver.
        l_err = SCOM::checkIndirectAndDoScom(i_opType,
                                             l_parentChip,
                                             io_buffer,
                                             io_buflen,
                                             i_accessType,
                                             l_addr);

        // @todo RTC:124196 need to move this to a more general location so that
        //       the disable occurs after the HBRT is complete.
#if __HOSTBOOT_RUNTIME
        if(l_needsWakeup && !g_wakeupInProgress)
        {
            g_wakeupInProgress = true;
            errlHndl_t l_errSW = NULL;

            l_errSW = WAKEUP::handleSpecialWakeup(i_target,WAKEUP::DISABLE);

            if(l_err != NULL && l_errSW)
            {
                TRACFCOMP(g_trac_scom, "startScomProcess: "
                          "handleSpecialWakeup disable ERROR");

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errSW);
                errlCommit(l_errSW,RUNTIME_COMP_ID);
            }
            else if(l_errSW)
            {
                l_err = l_errSW;
            }
            g_wakeupInProgress = false;
        }
#endif

    } while (0);

    return l_err;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
errlHndl_t scomTranslate(TARGETING::Target * &i_target,
                         uint64_t & io_addr,
                         bool & o_needsWakeup,
                         uint64_t i_opMode)
{
    errlHndl_t l_err = NULL;

    // Get the type attribute.
    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    // No translation is required for MEM_PORT targets
    if( TARGETING::TYPE_MEM_PORT != l_type )
    {
        l_err = p10_translation(i_target,
                                l_type,
                                io_addr,
                                o_needsWakeup,
                                i_opMode);
    }

    return l_err;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
errlHndl_t p10_translation (TARGETING::Target * &i_target,
                            TARGETING::TYPE i_type,
                            uint64_t &io_addr,
                            bool & o_needsWakeup,
                            uint64_t i_opMode)
{
    errlHndl_t l_err = NULL;
    do  {
        uint64_t l_original_addr = io_addr;
        p10TranslationMode_t l_chip_mode = P10_DEFAULT_MODE;
        bool l_scomAddrIsRelatedToUnit = false;
        bool l_scomAddrAndTargetTypeMatch = false;

        uint16_t l_instance = 0;
        p10ChipUnits_t l_chipUnit = NONE;
        std::vector<p10_chipUnitPairing_t> l_scomPairings;

        //Need to pass the chip/ec level into the translate function
        uint32_t l_chipLevel = getChipLevel(i_target);

        if(getChipUnitP10(i_type, l_chipUnit))
        {
            //Send an errorlog because we are targeting an unsupported type.
            TRACFCOMP(g_trac_scom, "p10_translation.. Invalid P10 target type=0x%X", i_type);

            /*@
            * @errortype
            * @moduleid         SCOM::SCOM_TRANSLATE_P10
            * @reasoncode       SCOM::SCOM_P10_TRANS_INVALID_TYPE
            * @userdata1        Address
            * @userdata2[0:31]  Target's Type
            * @userdata2[32:63] Target's Huid
            * @devdesc          Scom Translate not supported for this type
            * @custdesc         Firmware error during system IPL
            */
            l_err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM_TRANSLATE_P10,
                SCOM_P10_TRANS_INVALID_TYPE,
                io_addr,
                TWO_UINT32_TO_UINT64(i_type, TARGETING::get_huid(i_target)),
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                .addToLog(l_err);

            l_err->collectTrace(SCOM_COMP_NAME);
            break;
        }

        //Make sure that scom addr is related to a chip unit
        uint32_t isChipUnitScomRC
            = p10_scominfo_isChipUnitScom(l_chipUnit,
                                          l_chipLevel,
                                          io_addr,
                                          l_scomAddrIsRelatedToUnit,
                                          l_scomPairings,
                                          l_chip_mode);

        if(isChipUnitScomRC)
        {
                /*@
                * @errortype
                * @moduleid     SCOM::SCOM_TRANSLATE_P10
                * @reasoncode   SCOM::SCOM_ISCHIPUNITSCOM_INVALID
                * @userdata1    Input address
                * @userdata2[0:31] Target huid
                * @userdata2[32:63] Target Type
                * @devdesc      EKB code has detected and error in the scom
                * @custdesc     Firmware error during system IPL
                */
                l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    SCOM_TRANSLATE_P10,
                    SCOM_ISCHIPUNITSCOM_INVALID,
                    l_original_addr,
                    TWO_UINT32_TO_UINT64(
                        i_target->getAttr<TARGETING::ATTR_HUID>(),
                        i_type),
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                    .addToLog(l_err);

                l_err->collectTrace(SCOM_COMP_NAME);
                break;
        }


#if __HOSTBOOT_RUNTIME
        if(((i_type == TARGETING::TYPE_EQ) ||
            (i_type == TARGETING::TYPE_FC) ||
            (i_type == TARGETING::TYPE_CORE)) &&
            (!g_wakeupInProgress) &&
            !(i_opMode & fapi2::DO_NOT_DO_WAKEUP) )
        {
            TRACDCOMP(g_trac_scom,"Determining if Special Wakeup is needed..");
            o_needsWakeup = true;
            for(uint16_t i = 0; i < l_scomPairings.size(); i++)
            {
                if( l_scomPairings[i].chipUnitType == PU_PERV_CHIPUNIT)
                {
                    o_needsWakeup = false;
                    break;
                }
            }
        }
#endif


        if(!l_scomAddrIsRelatedToUnit)
        {
            TRACFCOMP(g_trac_scom, "Address provided does not match any targets.");
            TRACFCOMP(g_trac_scom, "scomTranslate-Invalid Address io_addr=0x%X, Type 0x%.8X, HUID 0x%.8X",
            io_addr, i_type, TARGETING::get_huid(i_target));


            uint32_t userdata32_1 = TWO_UINT16_TO_UINT32(
                                      i_type,
                                      l_instance);
            uint16_t userdata16_1 = TWO_UINT8_TO_UINT16(
                                      l_scomAddrIsRelatedToUnit,
                                      l_scomAddrAndTargetTypeMatch);
            uint16_t userdata16_2 = TWO_UINT8_TO_UINT16(
                                      l_chipUnit,
                                      TARGETING::MODEL_POWER10);
            uint32_t userdata32_2 = TWO_UINT16_TO_UINT32(
                                      userdata16_1,
                                      userdata16_2);
            uint64_t userdata64_1 = TWO_UINT32_TO_UINT64(
                                      userdata32_1,
                                      userdata32_2);
            /*@
            * @errortype
            * @moduleid          SCOM::SCOM_TRANSLATE_P10
            * @reasoncode        SCOM::SCOM_INVALID_ADDR
            * @userdata1         Address
            * @userdata2[0:15]   Target's Type
            * @userdata2[16:31]  Instance of this type
            * @userdata2[32:39]  Is this SCOM addr related to a chip unit?
            * @userdata2[40:47]  Does the target type and addr type match?
            * @userdata2[48:55]  Chip unit of the target
            * @userdata2[56:63]  Model of the target (ex: POWER10)
            * @devdesc           The scom address provided was invalid, check
            *                    to see if the address matches a target in the
            *                    scomdef file.
            * @custdesc          Firmware error during system IPL
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCOM_TRANSLATE_P10,
                                            SCOM_INVALID_ADDR,
                                            io_addr,
                                            userdata64_1,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                .addToLog(l_err);

            l_err->collectTrace(SCOM_COMP_NAME);
            break;
        }

        //Check that the target_type that the scom was requested
        //for matches up with one of the possible targets allowed
        //for this particular scom.
        for(uint32_t i = 0; i < l_scomPairings.size(); i++)
        {
            if( (l_scomPairings[i].chipUnitType == l_chipUnit) &&
                (l_scomPairings[i].chipUnitNum == 0))
            {
                l_scomAddrAndTargetTypeMatch = true;
                break;
            }

        }

        if(!l_scomAddrAndTargetTypeMatch)
        {
            TRACFCOMP(g_trac_scom, "Target type and scom Addr do not match.");
            TRACFCOMP(g_trac_scom, "scomTranslate-Invalid Address io_addr=0x%X, Type 0x%.8X, HUID 0x%.8X",
            io_addr, i_type, TARGETING::get_huid(i_target));
            for(uint32_t i = 0; i < l_scomPairings.size(); i++)
            {
                TRACFCOMP(g_trac_scom, "Scom Pairing: chipUnitType=%d, chipUnitNum=%d",
                          l_scomPairings[i].chipUnitType, l_scomPairings[i].chipUnitNum);
            }


            uint32_t userdata32_1 = TWO_UINT16_TO_UINT32(
                                      i_type,
                                      l_instance);
            uint16_t userdata16_1 = TWO_UINT8_TO_UINT16(
                                      l_scomAddrIsRelatedToUnit,
                                      l_scomAddrAndTargetTypeMatch);
            uint16_t userdata16_2 = TWO_UINT8_TO_UINT16(
                                      l_chipUnit,
                                      TARGETING::MODEL_POWER10);
            uint32_t userdata32_2 = TWO_UINT16_TO_UINT32(
                                      userdata16_1,
                                      userdata16_2);
            uint64_t userdata64_1 = TWO_UINT32_TO_UINT64(
                                      userdata32_1,
                                      userdata32_2);
            /*@
            * @errortype
            * @moduleid          SCOM::SCOM_TRANSLATE_P10
            * @reasoncode        SCOM::SCOM_TARGET_ADDR_MISMATCH
            * @userdata1         Address
            * @userdata2[0:15]   Target's Type
            * @userdata2[16:31]  Instance of this type
            * @userdata2[32:39]  Is this SCOM addr related to a chip unit?
            * @userdata2[40:47]  Does the target type and addr type match?
            * @userdata2[48:55]  Chip unit of the target
            * @userdata2[56:63]  Model of the target (ex: POWER10)
            * @devdesc           The scom target did not match the provided
            *                    address
            * @custdesc          Firmware error during system IPL
            */
            l_err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM_TRANSLATE_P10,
                SCOM_TARGET_ADDR_MISMATCH,
                io_addr,
                userdata64_1,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                .addToLog(l_err);

            l_err->collectTrace(SCOM_COMP_NAME);
            l_err->collectTrace(FAPI_TRACE_NAME, 256 );
            l_err->collectTrace(FAPI_IMP_TRACE_NAME, 384 );
            break;
        }

        l_instance = i_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        io_addr = p10_scominfo_createChipUnitScomAddr(l_chipUnit,
                                                      l_chipLevel,
                                                      l_instance,
                                                      io_addr,
                                                      l_chip_mode);

        if(io_addr == FAILED_TRANSLATION)
        {
            TRACFCOMP(g_trac_scom, "Address failed to translate.");
            TRACFCOMP(g_trac_scom, "Scom Target HUID: 0x%x", TARGETING::get_huid(i_target));
            TRACFCOMP(g_trac_scom, "Scom Address: 0x%lx", io_addr);
            TRACFCOMP(g_trac_scom, "Scom Target Type: 0x%x", i_type);
            for(uint32_t i = 0; i < l_scomPairings.size(); i++)
            {
                TRACFCOMP(g_trac_scom, "Scom Pairing %d: %d",
                          i, l_scomPairings[i].chipUnitType);
            }
            uint32_t userdata32 = TWO_UINT16_TO_UINT32(
                                    l_chipUnit,
                                    l_instance);
            uint64_t userdata64 = TWO_UINT32_TO_UINT64(
                                    userdata32,
                                    TARGETING::get_huid(i_target));
            /*@
            * @errortype
            * @moduleid     SCOM::SCOM_TRANSLATE_P10
            * @reasoncode   SCOM::SCOM_INVALID_TRANSLATION
            * @userdata1    Original Address
            * @userdata2[0:15]  l_chipUnit
            * @userdata2[16:31] instance of target
            * @userdata2[32:63] HUID of target
            * @devdesc      Scom Translation did not modify the address
            */
            l_err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SCOM_TRANSLATE_P10,
                SCOM_INVALID_TRANSLATION,
                l_original_addr,
                userdata64,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                .addToLog(l_err);

            l_err->collectTrace(SCOM_COMP_NAME);
            break;
        }

    } while (0);
    return l_err;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief Gets p10 chip unit for this target type
 */
bool getChipUnitP10 (TARGETING::TYPE i_type,
                     p10ChipUnits_t &o_chipUnit)
{
    bool l_isError = false;
    switch(i_type)
    {
        case(TARGETING::TYPE_CORE) :
        {
            o_chipUnit = PU_C_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PERV) :
        {
            o_chipUnit = PU_PERV_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_EQ) :
        {
            o_chipUnit = PU_EQ_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MI) :
        {
            o_chipUnit = PU_MI_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PEC) :
        {
            o_chipUnit = PU_PEC_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PHB) :
        {
            o_chipUnit = PU_PHB_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MC) :
        {
            o_chipUnit = PU_MC_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MCC) :
        {
            o_chipUnit = PU_MCC_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_OMI) :
        {
            o_chipUnit = PU_OMI_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_NMMU) :
        {
            o_chipUnit = PU_NMMU_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_IOHS) :
        {
            o_chipUnit = PU_IOHS_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_OMIC) :
        {
            o_chipUnit = PU_OMIC_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PAU) :
        {
            o_chipUnit = PU_PAU_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PAUC) :
        {
            o_chipUnit = PU_PAUC_CHIPUNIT;
            break;
        }
        default:
        {
            l_isError = true;
            break;
        }
    }

    return l_isError;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief Computes the chip/ddlevel value to be passed into translator
 */
uint32_t getChipLevel (TARGETING::Target* i_target)
{
    TARGETING::Target* l_chip = i_target;

    TARGETING::Target* l_parentChip = const_cast<TARGETING::Target *>
      (TARGETING::getParentChip(i_target));
    if( l_parentChip )
    {
        l_chip = l_parentChip;
    }

    TARGETING::ATTR_MODEL_type l_model =
      l_chip->getAttr<TARGETING::ATTR_MODEL>();
    TARGETING::ATTR_EC_type l_ec =
      l_chip->getAttr<TARGETING::ATTR_EC>();

    // @TODO RTC 213022: remove this when the EKB constant is available
    const uint32_t P10_DD1_SI_MODE = 0x0;

    // convert to scominfo types
    uint32_t l_chipLevel = 0;
    switch( l_model )
    {
        case(TARGETING::MODEL_POWER10):
            switch(l_ec)
            {
                // @TODO RTC 213022: fix this case and make default the error
                // case when ATTR_EC actually gets set for P10
                default:
                case(0x10):
                    l_chipLevel = P10_DD1_SI_MODE;
                    break;
                //default:
                    TRACFCOMP( g_trac_scom,
                               "Unsupported P10 EC 0x%X", l_ec );
                    assert(false,"Unsupported P10 EC");
            }
            break;
        default:
            TRACFCOMP( g_trac_scom,
                       "Unsupported Chip Type %d", l_model );
            assert(false,"Unsupported Chip Type");
    }

    return l_chipLevel;
}


} // end namespace
