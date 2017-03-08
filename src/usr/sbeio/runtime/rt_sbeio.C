/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbeio.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <runtime/interface.h>
#include <kernel/console.H>

#include <vmmconst.h>
#include <sys/misc.h>
#include <errno.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

//  targeting support
#include    <targeting/common/target.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
//#include    <targeting/common/targetservice.H>
//#include    <targeting/common/util.H>
#include    <runtime/rt_targeting.H>

//  fapi support
//#include    <isteps/hwpf_reasoncodes.H>


using namespace TARGETING;

// Trace
extern trace_desc_t* g_fapiTd; // defined in rt_fapiPlatUtil.C

namespace RT_SBEIO
{
    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    int process_sbe_msg(uint32_t i_procChipId)
    {
        int rc = 0;
        errlHndl_t err = nullptr;

        // Convert chipId to HB target
        TargetHandle_t l_proc = nullptr;
        err = RT_TARG::getHbTarget(i_procChipId, l_proc);
        if(err)
        {
            rc = err->reasonCode();
            if (0 == rc)
            {
                // If there was a failure, be sure to return non-zero status
                rc = -1;
            }

            TRACFCOMP(g_fapiTd, ERR_MRK"process_sbe_msg: getHbTarget "
                     "returned rc=0x%04X for procChipId: %llx",
                      rc, i_procChipId);

            errlCommit (err, SBE_COMP_ID);
        }

        /* TODO RTC 170760 process SBE message read command */

        /* TODO RTC 170761 call appropriate command processor */

        /* TODO RTC 170762 process SBE message write response */

        /* TODO RTC 170763 assert CFAM register ??? */

        return rc;
    }

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    //------------------------------------------------------------------------

    struct registerSbeio
    {
        registerSbeio()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->sbe_message_passing = &process_sbe_msg;

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (const auto & l_procChip: procChips)
            {
                uint64_t l_instance = l_procChip->getAttr<ATTR_POSITION>();
                uint64_t l_sbeCommAddr =
                         g_hostInterfaces->get_reserved_mem("ibm,sbe-comm",
                                                            l_instance);
                l_procChip->setAttr<ATTR_SBE_COMM_ADDR>(l_sbeCommAddr);

           /*
            * TODO RTC 170758
            *
            * call performPsuChipOp to tell SBE where to write when SBE is ready
            *
            * psuCommand   l_psuCommand(
            *         SBE_REQUIRE_RESPONSE,
            *         SBE_PSU_GENERIC_MESSAGE,
            *         SBE_CMD_CONTROL_SYSTEM_CONFIG);
            *
            * psuResponse  l_psuResponse;
            *
            * // Create FFDCPackage struct in psuCommand union
            * uint64_t cd4_FFDCPackage_MbxReg2reserved = &iv_ffdcPackageBuffer;
            *
            * performPsuChipOp(l_procChip,
            *        &l_psuCommand,
            *        &l_psuResponse,
            *        MAX_PSU_SHORT_TIMEOUT_NS,
            *        SBE_SYSTEM_CONFIG_REQ_USED_REGS,
            *        SBE_SYSTEM_CONFIG_RSP_USED_REGS);
            *
            */
            }
        }
    };

    registerSbeio g_registerSbeio;
}

