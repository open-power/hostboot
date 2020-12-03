/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuGetHwReg.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
* @file sbe_psuGetHwReg.C
* @brief Send command request to SBE for a HW register access (scom) for a given target
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_utils.H>
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuGetHwReg: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuGetHwReg: " printf_string,##args)

using namespace TARGETING;
using namespace ERRORLOG;

namespace SBEIO
{

    /**
    * @brief Sends a PSU chipOp request the SBE to perform a getHwReg
    *        on a given address for a given target. (Works for scom)
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuGetHwRegRequest(TARGETING::Target * i_target,
                                     const uint64_t i_addr,
                                     uint64_t & o_value)
    {
        assert(i_target != nullptr, "sendPsuGetHwRegRequest passed nullptr target");
        errlHndl_t errl = nullptr;
        do{

        SBE_TRACD(ENTER_MRK "sending psu getHwReg request from HB to SBE for target 0x%08x",
                  get_huid(i_target));

        const auto sbe_target_type = translateToSBETargetType(i_target);

        if(sbe_target_type== SBE_TARGET_TYPE_UNKNOWN)
        {
            auto target_type = i_target->getAttr<ATTR_TYPE>();
            SBE_TRACF("Invalid target type 0x%08x found for target with huid 0x%08x , cannot perform getHwReg via sbe on this target",
                      target_type, get_huid(i_target));
            /*@
              * @errortype
              * @moduleid          SBEIO_PSU_GET_HW_REG
              * @reasoncode        SBEIO_PSU_INVALID_TARGET
              * @userdata1[0:31]   Target HUID
              * @userdata1[32:63]  Target Type
              * @userdata2         HwReg Address
              * @devdesc           Invalid target attempted for SBE hw register access
              * @custdesc          A firmware error occurred during system boot
              */
            errl = new ErrlEntry(
                ERRL_SEV_PREDICTIVE,
                SBEIO_PSU_GET_HW_REG,
                SBEIO_PSU_INVALID_TARGET,
                TWO_UINT32_TO_UINT64(
                    get_huid(i_target),
                    target_type),
                i_addr,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // set up PSU command message
        SbePsu::psuCommand l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE |
                                  SbePsu::SBE_REQUIRE_ACK, //control flags
                                  SbePsu::SBE_PSU_CLASS_REGISTER_ACCESS, //command class
                                  SbePsu::SBE_CMD_GET_HW_REG); //command
        SbePsu::psuResponse  l_psuResponse;

        // Set Target Type Field
        l_psuCommand.cd5_getHwReg_TargetType = static_cast<uint16_t>(sbe_target_type);

        // Set Target Instance Field
        const size_t OCMB_PER_PROC = 16;
        l_psuCommand.cd5_getHwReg_TargetInstance =
            i_target->getAttr<TARGETING::ATTR_FAPI_POS>() % OCMB_PER_PROC;

        // Set the AddressHi and AddressLow fields
        l_psuCommand.cd5_getHwReg_AddressHi  = static_cast<uint32_t>(i_addr >> 32);
        l_psuCommand.cd5_getHwReg_AddressLow = static_cast<uint32_t>(i_addr);
        auto proc_chip = getChipForPsuOp(i_target);
        if(proc_chip == nullptr)
        {
            SBE_TRACF("We were unable to find the processor chip to use for this PSU chip op");
            /*@
              * @errortype
              * @moduleid          SBEIO_PSU_GET_HW_REG
              * @reasoncode        SBEIO_NO_PARENT_PROC
              * @userdata1         Target HUID
              * @userdata2         HwReg Address
              * @devdesc           Invalid target attempted for SBE hw register access
              * @custdesc          A firmware error occurred during system boot
              */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 SBEIO_PSU_GET_HW_REG,
                                 SBEIO_NO_PARENT_PROC,
                                 get_huid(i_target),
                                 i_addr,
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        errl = SbePsu::getTheInstance().performPsuChipOp(proc_chip,
                                                         &l_psuCommand,
                                                         &l_psuResponse,
                                                         SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                                                         SbePsu::SBE_GET_HW_REG_REQ_USED_REGS,
                                                         SbePsu::SBE_GET_HW_REG_RSP_USED_REGS,
                                                         SbePsu::unsupported_command_error_severity { ERRL_SEV_PREDICTIVE });
        if(errl)
        {
            // Error log will have already appended SBEIO traces
            SBE_TRACF("An error was returned from the SBE for the previous getHwReg PSU chipop, check error log");
            break;
        }

        o_value = l_psuResponse.getHwReg_value;

        SBE_TRACF(EXIT_MRK "returned value of 0x%016llx", o_value);
        }while(0);

        return errl;
    };

} //end namespace SBEIO
