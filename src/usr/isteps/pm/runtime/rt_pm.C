/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/rt_pm.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#include <stdint.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errno.h>
#include <sys/misc.h>
#include <trace/interface.H>
#include <util/utillidmgr.H>

#include <pm/pm_common.H>
#include <isteps/pm/pm_common_ext.H>

#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
#include <runtime/runtime_reasoncodes.H>

#include <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>

#include <scom/scomif.H>
#include "handleSpecialWakeup.H"

using namespace TARGETING;
using namespace RUNTIME;

namespace ISTEPS_TRACE
{
    // declare storage for isteps_trace!
    trace_desc_t * g_trac_isteps_trace = nullptr;
    TRAC_INIT(&ISTEPS_TRACE::g_trac_isteps_trace, "ISTEPS_TRACE", 2*KILOBYTE);
}

namespace RTPM
{
    /**
     *  @brief Process error log created while running a PM Complex function
     *  @param[in]      i_err      Error handle
     *  @param[in/out]  io_rc      Return code
     */
    void pm_complex_error( errlHndl_t i_err,
                           int &io_rc )
    {
        errlCommit( i_err, RUNTIME_COMP_ID );

        if(io_rc == 0)
        {
            io_rc = -1;
        }

        return;
    }


    /**
     *  @brief Load OCC/HCODE images into mainstore
     *  @param[in]  i_chip              Processor Chip ID
     *  @param[in]  i_homer_addr        Homer physical address
     *  @param[in]  i_occ_common_addr   OCC common area physical address
     *  @param[in]  i_mode              PM load / reload
     *  @return                         Return Code
     */
    int load_pm_complex( uint64_t i_chip,
                         uint64_t i_homer_addr,
                         uint64_t i_occ_common_addr,
                         uint32_t i_mode )
    {
        Target* proc_target = nullptr;
        errlHndl_t l_err = nullptr;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "load_pm_complex: homer addr=%016llx. "
                   "occ common addr=%016lx. RtProcChip=%llx. mode=%d",
                   i_homer_addr,
                   i_occ_common_addr,
                   i_chip,
                   i_mode);

        do
        {
            // Utility to convert i_chip to Target
            l_err = RT_TARG::getHbTarget(i_chip, proc_target);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "convert Chip to Target failed!" );
                rc = EINVAL;
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "load_pm_complex: "
                           "proc Target HUID=0x%08X",
                            get_huid(proc_target));
            }

            HBPM::loadPmMode l_hb_mode = HBPM::PM_UNKNOWN;
            switch (i_mode)
            {
                case HBRT_PM_LOAD:
                    l_hb_mode = HBPM::PM_LOAD;
                    break;
                case HBRT_PM_RELOAD:
                    l_hb_mode = HBPM::PM_RELOAD;
                    break;
                default:
                    /*@
                    * @errortype
                    * @moduleid     MOD_PM_RT_LOAD_PM_COMPLEX
                    * @reasoncode   RC_PM_RT_UNKNOWN_MODE
                    * @userdata1    HBRT PM Mode
                    * @userdata2    HUID
                    * @devdesc      PM load complex unknown mode
                    */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    MOD_PM_RT_LOAD_PM_COMPLEX,
                                    RC_PM_RT_UNKNOWN_MODE,
                                    i_mode,
                                    get_huid(proc_target));
                    break;
            }
            if( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"load_pm_complex: "
                          "Unknown Mode 0x%X for HUID=0x%08X",
                          i_mode, get_huid(proc_target));
                break;
            }

            l_err = HBPM::loadPMComplex(proc_target,
                                        i_homer_addr,
                                        i_occ_common_addr,
                                        l_hb_mode);
            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "load PM complex failed!" );
                break;
            }

        } while(0);

        if (l_err)
        {
            pm_complex_error(l_err,
                             rc);
        }

        return rc;
    }


    /**
     *  @brief Start OCC/HCODE on the specified chip
     *  @param[in]  i_chip              Processor Chip ID
     *  @return                         Return Code
     */
    int start_pm_complex( uint64_t i_chip )
    {
        Target* proc_target = nullptr;
        errlHndl_t l_err = nullptr;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "start_pm_complex: RtProcChip %llx", i_chip);

        do
        {
            // Utility to convert i_chip to Target
            l_err = RT_TARG::getHbTarget(i_chip, proc_target);
            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"start_pm_complex: "
                           "convert Chip to Target failed!" );
                rc = EINVAL;
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "start_pm_complex: "
                           "proc Target HUID=0x%08X",
                           get_huid(proc_target));
            }

            l_err = HBPM::startPMComplex(proc_target);
            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"start_pm_complex: "
                           "start PM complex failed!" );
                break;
            }

        } while(0);

        if ( l_err )
        {
            pm_complex_error(l_err,
                             rc);
        }

        return rc;
    }


    /**
     *  @brief Reset OCC/HCODE on the specified chip
     *  @param[in]  i_chip              Processor Chip ID
     *  @return                         Return Code
     */
    int reset_pm_complex( uint64_t i_chip )
    {
        Target* proc_target = nullptr;
        errlHndl_t l_err = nullptr;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "reset_pm_complex: RtProcChip %llx", i_chip);

        do
        {
            // Utility to convert i_chip to Target
            l_err = RT_TARG::getHbTarget(i_chip, proc_target);
            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"reset_pm_complex: "
                           "convert Chip to Target failed!" );
                rc = EINVAL;
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "reset_pm_complex: "
                           "proc Target HUID=0x%08X",
                           get_huid(proc_target));
            }

            l_err = HBPM::resetPMComplex(proc_target);
            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"reset_pm_complex: "
                           "reset PM complex failed!" );
                break;
            }
        } while(0);

        if ( l_err )
        {
            pm_complex_error(l_err,
                             rc);
        }

        return rc;
    }


    /**
    * @brief HCODE update operation
    */
    errlHndl_t hcode_update( uint32_t i_section,
                             uint32_t i_operation,
                             Target*  i_target,
                             uint64_t i_rel_scom_addr,
                             uint64_t i_scom_data )
    {
        errlHndl_t l_err = NULL;
        int rc = 0;

        do {
            if( g_hostInterfaces == NULL ||
                g_hostInterfaces->hcode_scom_update == NULL )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"hcode_update: "
                          "Hypervisor hcode_scom_update interface not linked");
                /*@
                * @errortype
                * @moduleid         MOD_PM_RT_HCODE_UPDATE
                * @reasoncode       RC_PM_RT_INTERFACE_ERR
                * @userdata1[0:31]  Target HUID
                * @userdata1[32:63] SCOM restore section
                * @userdata2        SCOM address
                * @devdesc      HCODE scom update runtime interface not linked.
                */
                l_err= new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                               MOD_PM_RT_HCODE_UPDATE,
                                               RC_PM_RT_INTERFACE_ERR,
                                               TWO_UINT32_TO_UINT64(
                                                 TARGETING::get_huid(i_target),
                                                 i_section),
                                               i_rel_scom_addr);
                break;
            }

            // Enable special wakeup
            l_err = handleSpecialWakeup(i_target,true);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: "
                           "handleSpecialWakeup enable ERROR" );
                break;
            }

            // Get the Proc Chip Id
            const TARGETING::Target * l_pChipTarget =
                getParentChip(const_cast<TARGETING::Target *>(i_target));
            RT_TARG::rtChipId_t l_chipId = 0;

            l_err = RT_TARG::getRtTarget(l_pChipTarget, l_chipId);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: getRtTarget ERROR" );
                break;
            }

            // Translate the scom address
            uint64_t l_scomAddr = i_rel_scom_addr;
            bool l_needsWakeup = false;     // Ignored - SW already enabled

            l_err = SCOM::scomTranslate(i_target,
                                        l_scomAddr,
                                        l_needsWakeup);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: scomTranslate ERROR" );
                break;
            }

            rc = g_hostInterfaces->hcode_scom_update(l_chipId,
                                                     i_section,
                                                     i_operation,
                                                     l_scomAddr,
                                                     i_scom_data);
            if(rc)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"hcode_update: "
                          "HCODE scom update failed. "
                          "rc 0x%X target 0x%llX chipId 0x%llX section 0x%X "
                          "operation 0x%X scomAddr 0x%llX scomData 0x%llX",
                          rc, get_huid(i_target), l_chipId, i_section,
                          i_operation, l_scomAddr, i_scom_data);

                // convert rc to error log
                /*@
                * @errortype
                * @moduleid     MOD_PM_RT_HCODE_UPDATE
                * @reasoncode   RC_PM_RT_HCODE_UPDATE_ERR
                * @userdata1    Hypervisor return code
                * @userdata2    SCOM address
                * @devdesc      HCODE SCOM update error
                */
                l_err=new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                              MOD_PM_RT_HCODE_UPDATE,
                                              RC_PM_RT_HCODE_UPDATE_ERR,
                                              rc,
                                              l_scomAddr);
                break;
            }

            // Disable special wakeup
            l_err = handleSpecialWakeup(i_target,false);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: "
                           "handleSpecialWakeup disable ERROR" );
                break;
            }

        } while (0);

        return l_err;
    }


    //------------------------------------------------------------------------

    struct registerPm
    {
        registerPm()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->load_pm_complex = &load_pm_complex;
            rt_intf->start_pm_complex = &start_pm_complex;
            rt_intf->reset_pm_complex = &reset_pm_complex;

            // If we already loaded OCC during the IPL we need to fix up
            //  the virtual address because we're now not using virtual
            //  memory

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (TargetHandleList::iterator itr = procChips.begin();
                 itr != procChips.end();
                 ++itr)
            {
                (*itr)->setAttr<ATTR_HOMER_VIRT_ADDR>(0);
            }
        }
    };

    registerPm g_registerPm;
};
