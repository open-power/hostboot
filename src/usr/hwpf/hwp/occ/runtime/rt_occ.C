/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/runtime/rt_occ.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#include <hwpf/hwp/occ/occ_common.H>

#include <vmmconst.h>
#include <sys/misc.h>
#include <errno.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <util/utillidmgr.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/util.H>
#include    <runtime/rt_targeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatTrace.H>
#include    <hwpf/hwpf_reasoncodes.H>

// Procedures
#include <p8_occ_control.H>
#include <p8_pba_bar_config.H>
#include <p8_pm_init.H>
#include <p8_pm_prep_for_reset.H>

using namespace TARGETING;
// Trace

extern trace_desc_t* g_fapiTd; // defined in rt_fapiPlatUtil.C

namespace RT_OCC
{
    typedef std::vector<TARGETING::Target *> target_list_t;

    //------------------------------------------------------------------------

    void occ_error (uint64_t i_chipId)
    {
        do
        {
            TARGETING::Target* l_failedOccTarget = NULL;
            errlHndl_t l_errl =RT_TARG::getHbTarget(i_chipId,l_failedOccTarget);
            if (l_errl)
            {
                TRACFCOMP (g_fapiTd, "occ_error: getHbTarget failed at %d chipId", i_chipId);
                errlCommit (l_errl, HWPF_COMP_ID);
                break;
            }
            //TODO RTC: 114906
            //HTMGT::htmgtProcessOccError(l_failedOccTarget);
        } while (0);
    }

    //------------------------------------------------------------------------

    int executeLoadOCC(uint64_t i_homer_addr_phys,
                       uint64_t i_homer_addr_va,
                       uint64_t i_common_addr_phys,
                       uint64_t i_common_addr_va,
                       uint64_t i_proc_chip)
    {
        errlHndl_t err = NULL;
        int rc = 0;

        TRACFCOMP( g_fapiTd,
                   "LoadOCC: homer paddr=%016llx vaddr=%016llx. "
                   " common paddr=%016lx vaddr=%016llx. RtProcChip=%llx",
                   i_homer_addr_phys,
                   i_homer_addr_va,
                   i_common_addr_phys,
                   i_common_addr_va,
                   i_proc_chip);

        do
        {
            // Utility to convert i_proc_chip to Target
            TARGETING::Target* proc_target = NULL;
            err = RT_TARG::getHbTarget(i_proc_chip, proc_target);
            if(err)
            {
                rc = EINVAL;
                break;
            }
            err = HBOCC::loadOCC(proc_target,
                                        i_homer_addr_phys,
                                        i_homer_addr_va,
                                        i_common_addr_phys);
            if( err )
            {
                break;
            }

            void* occHostVirt = reinterpret_cast <void *> (i_homer_addr_va +
                                HOMER_OFFSET_TO_OCC_HOST_DATA);
            err = HBOCC::loadHostDataToHomer(occHostVirt);
            if( err != NULL )
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loading Host Data Area failed!" );
                break;
            }

        } while(0);

        if ( err )
        {
            uint64_t status = err->plid();
            errlCommit( err, HWPF_COMP_ID );

            if(g_hostInterfaces &&
               g_hostInterfaces->report_failure)
            {

                g_hostInterfaces->report_failure(status,
                                                 i_proc_chip);
            }

            if(rc == 0)
            {
                rc = -1;
            }
        }
        return rc;
    }

    //------------------------------------------------------------------------

    int executeOnDcms(HBOCC::occAction_t i_action,
                      uint64_t * i_proc_chip,
                      size_t i_num_chips)
    {
        errlHndl_t err = NULL;
        int rc = 0;
        TARGETING::Target* l_failedTarget = NULL;
        TRACFCOMP( g_fapiTd,
                   "Action=%d, number of procs = %d ",
                   i_action,
                   i_num_chips);

        for(size_t i = 0; i < i_num_chips; ++i)
        {
            TRACFCOMP( g_fapiTd, "\tRtProcChip %llx", i_proc_chip[i]);
        }

        do
        {
            if(i_num_chips < 1 || i_proc_chip == NULL)
            {
                rc = EINVAL;
                break;
            }

            // Convert chipIds to HB targets
            target_list_t targets;
            targets.reserve(i_num_chips);

            for(size_t i = 0; i < i_num_chips; ++i)
            {
                TARGETING::Target* proc_target = NULL;
                err = RT_TARG::getHbTarget(i_proc_chip[i], proc_target);
                if( err )
                {
                    rc = EINVAL;
                    break;
                }
                targets.push_back(proc_target);
            }
            if (err)
            {
                break;
            }

            // If there are no DCMs INSTALLED the do on each proc
            target_list_t::iterator itarg = targets.begin();
            if (0 == (*itarg)->getAttr<ATTR_PROC_DCM_INSTALLED>())
            {
                for(itarg = targets.begin();
                    itarg != targets.end();
                    ++itarg)
                {
                    if(i_action == HBOCC::OCC_START)
                    {
                        err = HBOCC::startOCC(*itarg, NULL, l_failedTarget);
                    }
                    else if(i_action == HBOCC::OCC_STOP)
                    {
                        err = HBOCC::stopOCC(*itarg, NULL);
                    }

                    if( err )
                    {
                        uint64_t status = err->plid();
                        errlCommit( err, HWPF_COMP_ID );

                        if(g_hostInterfaces &&
                           g_hostInterfaces->report_failure)
                        {
                            RT_TARG::rtChipId_t proc_chip = 0;
                            errlHndl_t err2 =
                                RT_TARG::getRtTarget(*itarg, proc_chip);

                            if(err2) // should never happen
                            {
                                TRACFCOMP
                                    (g_fapiTd, ERR_MRK
                                     "Error converting target to RT chipID");
                                errlCommit( err2, HWPF_COMP_ID );
                            }

                            g_hostInterfaces->report_failure(status,
                                                             proc_chip);
                        }
                        err = NULL;
                        rc = -1;
                        // keep going
                    }
                }
                break;  // done
            }

            // continue here only if have DCMs
            // Sort the target list by node then pos
            std::sort(targets.begin(),
                      targets.end(),
                      orderByNodeAndPosition);

            for(itarg = targets.begin();
                itarg != targets.end();
                ++itarg)
            {
                TARGETING::Target* t0 = *itarg;
                TARGETING::Target* t1 = NULL;
                if((itarg+1) != targets.end())
                {
                    if((t0->getAttr<ATTR_FABRIC_NODE_ID>()) ==
                       ((*(itarg+1))->getAttr<ATTR_FABRIC_NODE_ID>()))
                    {
                        ++itarg;
                        t1 = *itarg;
                    }
                }
                if(i_action == HBOCC::OCC_START)
                {
                    err = HBOCC::startOCC(t0,t1, l_failedTarget);
                }
                else if(i_action == HBOCC::OCC_STOP)
                {
                    err = HBOCC::stopOCC(t0,t1);
                }

                if( err )
                {
                    uint64_t status = err->plid();
                    errlCommit( err, HWPF_COMP_ID );

                    if(g_hostInterfaces &&
                       g_hostInterfaces->report_failure)
                    {
                        RT_TARG::rtChipId_t proc_chip = 0;
                        errlHndl_t err2 =
                            RT_TARG::getRtTarget(t0, proc_chip);

                        if(err2) // should never happen
                        {
                            TRACFCOMP
                                (g_fapiTd, ERR_MRK
                                 "Error converting target to RT chipID");
                            errlCommit( err2, HWPF_COMP_ID );
                        }

                        g_hostInterfaces->report_failure(status,
                                                         proc_chip);

                        if(t1)
                        {
                            err2 = RT_TARG::getRtTarget(t1, proc_chip);
                            if(err2) // should never happen
                            {
                                TRACFCOMP
                                    (g_fapiTd, ERR_MRK
                                     "Error converting target to RT chipID");
                                errlCommit( err2, HWPF_COMP_ID );
                            }

                            g_hostInterfaces->report_failure(status,
                                                             proc_chip);
                        }
                    }
                    err = NULL;
                    rc = -1;
                    // keep going
                }
            }
            if( err )
            {
                break;
            }

        } while(0);


        if( err )
        {
            errlCommit( err, HWPF_COMP_ID );
            if(rc == 0)
            {
                rc = -1;
            }
        }

        return rc;
    }

    int executeStartOCCs(uint64_t* i_proc_chip,
                         size_t i_num_chips)
    {
        return executeOnDcms(HBOCC::OCC_START,
                             i_proc_chip,
                             i_num_chips);
    }

    int executeStopOCCs(uint64_t* i_proc_chip,
                        size_t i_num_chips)
    {
        return executeOnDcms(HBOCC::OCC_STOP,
                             i_proc_chip,
                             i_num_chips);
    }

    //------------------------------------------------------------------------

    struct registerOcc
    {
        registerOcc()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->get_lid_list = &UtilLidMgr::getLidList;
            rt_intf->occ_load = &executeLoadOCC;
            rt_intf->occ_start = &executeStartOCCs;
            rt_intf->occ_stop = &executeStopOCCs;
            rt_intf->occ_error  = &occ_error;

            // If we already loaded OCC during the IPL we need to fix up
            //  the virtual address because we're now not using virtual
            //  memory
            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (TargetHandleList::iterator itr = procChips.begin();
                 itr != procChips.end();
                 ++itr)
            {
                uint64_t addr = (*itr)->getAttr<ATTR_HOMER_PHYS_ADDR>();
                (*itr)->setAttr<ATTR_HOMER_VIRT_ADDR>(addr);
            }
        }
    };

    registerOcc g_registerOcc;
}

