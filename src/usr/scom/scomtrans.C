/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scomtrans.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
// --which calls--> p9 translate --which returns to-->
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
#include <scom/scomreasoncodes.H>
#include <errl/errludtarget.H>
#include <initservice/initserviceif.H>
#include <p9_scom_addr.H>
#include <p9_scominfo.H>

#if __HOSTBOOT_RUNTIME
  #include "handleSpecialWakeup.H"
#endif

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{

bool g_wakeupInProgress = false;

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_EX,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MBA,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MCS,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_XBUS,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_ABUS,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MCA,
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
                    TARGETING::TYPE_MCBIST,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_MI,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_DMI,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_OBUS,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_NVBUS,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_SBE,
                    startScomProcess);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                    DeviceFW::SCOM,
                    TARGETING::TYPE_PPE,
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
    TARGETING::Target* l_target_SW = NULL;

    //will hold the value of parent chip for indirect scom
    TARGETING::Target* l_parentChip =
          const_cast<TARGETING::Target *>(TARGETING::getParentChip(i_target));
    uint64_t l_addr = va_arg(i_args,uint64_t);

    l_err = scomTranslate(i_target, l_addr, l_target_SW);


    if (l_err == NULL)
    {
        // call the routine that will do the indirect scom
        // and then call the correct device driver.
        l_err = SCOM::checkIndirectAndDoScom(i_opType,
                                            l_parentChip,
                                            io_buffer,
                                            io_buflen,
                                            i_accessType,
                                            l_addr);
    }

    // @todo RTC:124196 need to move this to a more general location so that
    //       the disable occurs after the HBRT is complete.
#if __HOSTBOOT_RUNTIME
    if(l_target_SW != NULL && !g_wakeupInProgress)
    {
        g_wakeupInProgress = true;
        errlHndl_t l_errSW = NULL;

        l_errSW = handleSpecialWakeup(l_target_SW,false);

        if(l_err != NULL && l_errSW)
        {
            TRACFCOMP(g_trac_scom,"Disable p8_cpu_special_wakeup ERROR");

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_target_SW).addToLog(l_errSW);
            errlCommit(l_errSW,RUNTIME_COMP_ID);
        }
        else if(l_errSW)
        {
            l_err = l_errSW;
        }
        g_wakeupInProgress = false;
    }
#endif
    return l_err;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
errlHndl_t scomTranslate(TARGETING::Target * &i_target,
                        uint64_t & io_addr,
                        TARGETING::Target * io_target_SW)
{
    errlHndl_t l_err = NULL;

    // Get the type attribute.
    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    //Need to support centaur still @TODO RTC: 139953

    l_err = p9_translation(i_target,
                          l_type,
                          io_addr,
                          io_target_SW);

    return l_err;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
errlHndl_t p9_translation (TARGETING::Target * &i_target,
                           TARGETING::TYPE i_type,
                           uint64_t &io_addr,
                           TARGETING::Target * io_target_SW)
{
    errlHndl_t l_err = NULL;
    do  {
        uint64_t l_original_addr = io_addr;
        uint32_t l_chip_mode = STANDARD_MODE;
        bool l_scomAddrIsRelatedToUnit = false;
        bool l_scomAddrAndTargetTypeMatch = false;

        uint16_t l_instance = 0;
        p9ChipUnits_t l_chipUnit = NONE;
        std::vector<p9_chipUnitPairing_t> l_scomPairings;


        //Make sure that scom addr is related to a chip unit
        uint32_t isChipUnitScomRC = p9_scominfo_isChipUnitScom(io_addr,
                                  l_scomAddrIsRelatedToUnit,
                                  l_scomPairings,
                                  l_chip_mode);

        if(isChipUnitScomRC)
        {
                /*@
                * @errortype
                * @moduleid     SCOM::SCOM_TRANSLATE_P9
                * @reasoncode   SCOM::SCOM_ISCHIPUNITSCOM_INVALID
                * @userdata1    Input address
                * @userdata2[0:31] Target huid
                * @userdata2[32:63] Target Type
                * @devdesc      EKB code has detected and error in the scom
                * @custdesc     Firmware error during system IPL
                */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                SCOM_TRANSLATE_P9,
                                                SCOM_ISCHIPUNITSCOM_INVALID,
                                                l_original_addr,
                                                TWO_UINT32_TO_UINT64(
                                                i_target->getAttr<TARGETING::ATTR_HUID>(),
                                                i_type),
                                                true/*SW Error*/);
                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                  .addToLog(l_err);
                l_err->collectTrace(SCOM_COMP_NAME,1024);
                break;
        }


#if __HOSTBOOT_RUNTIME
        //true => FSP present, false =>OP HBRT
        bool isFSP_HBRT = INITSERVICE::spBaseServicesEnabled();

        if(((i_type == TARGETING::TYPE_EX) || (i_type == TARGETING::TYPE_CORE)) &&
            (!g_wakeupInProgress) && (!isFSP_HBRT) )
        {
            bool l_needsWakeup = true;
            for(uint16_t i = 0; i < l_scomPairings.size(); i++)
            {
                if( l_scomPairings[i].chipUnitType == PU_PERV_CHIPUNIT)
                {
                    l_needsWakeup = false;
                    break;
                }
            }
            if(l_needsWakeup)
            {
                g_wakeupInProgress = true;

                l_err = handleSpecialWakeup(i_target,true);
                if(l_err)
                {
                    TRACFCOMP(g_trac_scom,
                              "Enable handleSpecialWakeup ERROR");

                  //capture the target data in the elog
                  ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
                  .addToLog(l_err);
                  l_err->collectTrace(SCOM_COMP_NAME,1024);
                  break;
                }
                io_target_SW = i_target;
                g_wakeupInProgress = false;
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
                                      TARGETING::MODEL_POWER9);
            uint32_t userdata32_2 = TWO_UINT16_TO_UINT32(
                                      userdata16_1,
                                      userdata16_2);
            uint64_t userdata64_1 = TWO_UINT32_TO_UINT64(
                                      userdata32_1,
                                      userdata32_2);
            /*@
            * @errortype
            * @moduleid     SCOM::SCOM_TRANSLATE_P9
            * @reasoncode   SCOM::SCOM_INVALID_ADDR
            * @userdata1    Address
            * @userdata2[0:15] Target's Type
            * @userdata2[16:31] Instance of this type
            * @userdata2[32:39] Is this SCOM addr related to a chip unit?
            * @userdata2[40:47] Does the target type and addr type match?
            * @userdata2[48:55] Chip unit of the target
            * @userdata2[56:63] Model of the target (ex: POWER9)
            * @devdesc      The scom address provided was invalid, check
            *               to see if the address matches a target in the
            *               scomdef file.
            * @custdesc     Firmware error during system IPL
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCOM_TRANSLATE_P9,
                                            SCOM_INVALID_ADDR,
                                            io_addr,
                                            userdata64_1,
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
              .addToLog(l_err);
            l_err->collectTrace(SCOM_COMP_NAME,1024);
            break;
        }

        if(getChipUnit (i_type, l_chipUnit))
        {
            //Send an errorlog because we are targeting an unsupported type.
            TRACFCOMP(g_trac_scom, "SCOM_TRANSLATE.. Invalid target type=0x%X", i_type);

            /*@
            * @errortype
            * @moduleid     SCOM::SCOM_TRANSLATE_P9
            * @reasoncode   SCOM::SCOM_P9_TRANS_INVALID_TYPE
            * @userdata1    Address
            * @userdata2[0:31] Target's Type
            * @userdata2[32:63] Target's Huid
            * @devdesc      Scom Translate not supported for this type
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              SCOM_TRANSLATE_P9,
                                              SCOM_P9_TRANS_INVALID_TYPE,
                                              io_addr,
                                              TWO_UINT32_TO_UINT64(i_type,
                                              TARGETING::get_huid(i_target)),
                                              true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
            .addToLog(l_err);
            l_err->collectTrace(SCOM_COMP_NAME,1024);
            break;
        }

        //check each scom pairing to make sure we have a match
        for(uint32_t i = 0; i < l_scomPairings.size(); i++)
        {
            if( l_scomPairings[i].chipUnitType == l_chipUnit)
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


            uint32_t userdata32_1 = TWO_UINT16_TO_UINT32(
                                      i_type,
                                      l_instance);
            uint16_t userdata16_1 = TWO_UINT8_TO_UINT16(
                                      l_scomAddrIsRelatedToUnit,
                                      l_scomAddrAndTargetTypeMatch);
            uint16_t userdata16_2 = TWO_UINT8_TO_UINT16(
                                      l_chipUnit,
                                      TARGETING::MODEL_POWER9);
            uint32_t userdata32_2 = TWO_UINT16_TO_UINT32(
                                      userdata16_1,
                                      userdata16_2);
            uint64_t userdata64_1 = TWO_UINT32_TO_UINT64(
                                      userdata32_1,
                                      userdata32_2);
            /*@
            * @errortype
            * @moduleid     SCOM::SCOM_TRANSLATE_P9
            * @reasoncode   SCOM::SCOM_TARGET_ADDR_MISMATCH
            * @userdata1    Address
            * @userdata2[0:15]  Target's Type
            * @userdata2[16:31] Instance of this type
            * @userdata2[32:39] Is this SCOM addr related to a chip unit?
            * @userdata2[40:47] Does the target type and addr type match?
            * @userdata2[48:55] Chip unit of the target
            * @userdata2[56:63] Model of the target (ex: POWER9)
            * @devdesc      The scom target did not match the provided
            *               address
            * @custdesc     Firmware error during system IPL
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCOM_TRANSLATE_P9,
                                            SCOM_TARGET_ADDR_MISMATCH,
                                            io_addr,
                                            userdata64_1,
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
              .addToLog(l_err);
            l_err->collectTrace(SCOM_COMP_NAME,1024);
            break;
        }

        l_instance = i_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        io_addr = p9_scominfo_createChipUnitScomAddr(l_chipUnit,
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
            * @moduleid     SCOM::SCOM_TRANSLATE_P9
            * @reasoncode   SCOM::SCOM_INVALID_TRANSLATION
            * @userdata1    Original Address
            * @userdata2[0:15]  l_chipUnit
            * @userdata2[16:31] instance of target
            * @userdata2[32:63] HUID of target
            * @devdesc      Scom Translation did not modify the address
            */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    SCOM_TRANSLATE_P9,
                                    SCOM_INVALID_TRANSLATION,
                                    l_original_addr,
                                    userdata64,
                                    true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
            .addToLog(l_err);
            l_err->collectTrace(SCOM_COMP_NAME,1024);
            break;
        }

    } while (0);
    return l_err;
}

bool getChipUnit (TARGETING::TYPE i_type,
                       p9ChipUnits_t &o_chipUnit)
{
    bool l_isError = false;
    switch(i_type)
    {
        case(TARGETING::TYPE_EX):
        {
            o_chipUnit = PU_EX_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MCS):
        {
            o_chipUnit = PU_MCS_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_XBUS):
        {
            o_chipUnit = PU_XBUS_CHIPUNIT;
            break;
        }
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
        case(TARGETING::TYPE_MCBIST) :
        {
            o_chipUnit = PU_MCBIST_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MCA) :
        {
            o_chipUnit = PU_MCA_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_MI) :
        {
            o_chipUnit = PU_MI_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_DMI) :
        {
            o_chipUnit = PU_DMI_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_OBUS) :
        {
            o_chipUnit = PU_OBUS_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_NVBUS) :
        {
            o_chipUnit = PU_NVBUS_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_SBE) :
        {
            o_chipUnit = PU_SBE_CHIPUNIT;
            break;
        }
        case(TARGETING::TYPE_PPE) :
        {
            o_chipUnit = PU_PPE_CHIPUNIT;
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
        case(TARGETING::TYPE_OCC) :
        {
            o_chipUnit = PU_OCC_CHIPUNIT;
            break;
        }
        //Need to add centaur support for Cumulus
        //@TODO RTC: 139953
        default:
        {
            l_isError = true;
            break;
        }
    }

    return l_isError;
}


} // end namespace
//@TODO RTC: 139953
//Need to support centaur chip translations
// MBA
// SCOM_TRANS_MBA_MASK =     0xFFFFFFFF7FFFFC00,
// SCOM_TRANS_MBA_BASEADDR = 0x0000000003010400,
//
// SCOM_TRANS_TCM_MBA_MASK =     0xFFFFFFFFFFFFFC00
// SCOM_TRANS_TCM_MBA_BASEADDR = 0x0000000003010800
//
//     In the XML.. the
//    <default>physical:sys-0/node-0/membuf-10/mbs-0/mba-1</default>
//
//    Assuming the MBA we are accessing is under the Centaur
//    not the processor.. for now.
//
// 0x00000000_03010400   MBA 0   # MBA01
// 0x00000000_03010C00   MBA 1   # MBA23

// 0x00000000_03010880   MBA 0    # Trace for MBA01
// 0x00000000_030110C0   MBA 1    # Trace for MBA23

// 0x00000000_03011400   MBA 0   # DPHY01 (indirect addressing)
// 0x00000000_03011800   MBA 1   # DPHY23 (indirect addressing)

// 0x80000000_0301143f   MBA  0  # DPHY01 (indirect addressing)
// 0x80000000_0301183f   MBA  1  # DPHY23 (indirect addressing)

// 0x80000000_0701143f   MBA 0   # DPHY01 (indirect addressing)
// 0x80000000_0701183f   MBA 1   # DPHY23 (indirect addressing)
//

// SCOM_TRANS_IND_MBA_MASK =      0x80000000FFFFFFFF,
// SCOM_TRANS_IND_MBA_BASEADDR =  0x800000000301143f,

// check to see that the Address is in the correct direct
// scom MBA address range.