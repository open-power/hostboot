/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/rt_pm.C $                           */
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

#include <stdint.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errno.h>
#include <sys/misc.h>
#include <trace/interface.H>
#include <util/utillidmgr.H>

#include <pm/pm_common.H>

#include <runtime/interface.h>
#include <runtime/rt_targeting.H>

#include <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>

using namespace TARGETING;

namespace ISTEPS_TRACE
{
    // declare storage for isteps_trace!
    trace_desc_t * g_trac_isteps_trace = NULL;
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


    // @TODO RTC: 148935 Defer creation of publicly accessible version for
    //       HTMGT to consume that also handles the non-runtime case
    /**
     *  @brief Convert HOMER physical address space to a vitual address
     *  @param[in]  i_proc_target  Processsor target
     *  @param[in]  i_phys_addr    Physical address
     *  @return NULL on error, else virtual address
     */
    void *convertHomerPhysToVirt( TARGETING::Target* i_proc_target,
                                  uint64_t i_phys_addr)
    {
        int rc = 0;

        void *l_virt_addr = reinterpret_cast <void*>
            (i_proc_target->getAttr<ATTR_HOMER_VIRT_ADDR>());

        if((i_proc_target->getAttr<ATTR_HOMER_PHYS_ADDR>() != i_phys_addr) ||
            (NULL == l_virt_addr))
        {
            if(NULL != l_virt_addr)
            {
                rc = g_hostInterfaces->unmap_phys_mem(l_virt_addr);
                if(rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"convertHomerPhysToVirt: "
                              "unmap_phys_mem failed, rc=0x%0X",
                              rc);

                    l_virt_addr = NULL;
                }
            }

            l_virt_addr = g_hostInterfaces->map_phys_mem(i_phys_addr,
                                                         4*MEGABYTE);

            // Update the attributes for the current values
            i_proc_target->setAttr<ATTR_HOMER_PHYS_ADDR>(i_phys_addr);
            i_proc_target->setAttr<ATTR_HOMER_VIRT_ADDR>(
                reinterpret_cast<uint64_t>(l_virt_addr));
        }

        return l_virt_addr;
    }


    /**
     *  @brief Load OCC/HCODE images into mainstore
     */
    int load_pm_complex( uint64_t i_chip,
                         uint64_t i_homer_addr,
                         uint64_t i_occ_common_addr,
                         uint32_t i_mode )
    {
        // LOAD == i_mode
        // - HBRT loads OCC lid, writes OCC config data, builds Pstate
        //   Parameter Blocks, and loads Hcode reference image lid
        // RELOAD == i_mode
        // - HBRT reloads OCC lid, rewrites OCC config data, builds Pstate
        //   Parameter Blocks, and rebuilds Hcode

        Target* proc_target = NULL;
        errlHndl_t err = NULL;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "load_pm_complex: homer addr=%016llx. "
                   "occ common addr=%016lx. RtProcChip=%llx. mode=%d",
                   i_homer_addr,
                   i_occ_common_addr,
                   i_chip,
                   i_mode);
/* @TODO RTC: 148935 */
        do
        {
            // Utility to convert i_chip to Target
            err = RT_TARG::getHbTarget(i_chip, proc_target);
            if(err)
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
                            proc_target->getAttr<ATTR_HUID>());
            }

            void* occVirt = convertHomerPhysToVirt(proc_target,
                                                   i_homer_addr);
            if(NULL == occVirt)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "converting physical address to virtual failed!");
                break;
            }

            uint64_t l_homer_addr_va =
                reinterpret_cast <uint64_t>(occVirt);

            err = HBPM::loadOCCSetup(proc_target,
                                     i_homer_addr,
                                     l_homer_addr_va,
                                     i_occ_common_addr);
            if(err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "setting up OCC load failed!" );
                break;
            }

            err = HBPM::loadOCCImageToHomer(proc_target,
                                            i_homer_addr,
                                            l_homer_addr_va);
            if(err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "loading OCC failed!" );
                break;
            }

            void* occHostVirt = reinterpret_cast <void *>(l_homer_addr_va +
                                HOMER_OFFSET_TO_OCC_HOST_DATA);

            err = HBPM::loadHostDataToHomer(proc_target,
                                            occHostVirt);
            if(err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"load_pm_complex: "
                           "loading Host Data Area failed!" );
                break;
            }

            // @TODO RTC:153885 verify parameters on call
            err = HBPM::pstateParameterBuild(proc_target,
                                             occVirt);
            if(err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"load_pm_complex: "
                          "building Pstate Parameter Block failed!");
                break;
            }

            err = HBPM::loadHcode(proc_target,
                                  occVirt,
                                  i_mode);
            if(err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"load_pm_complex: "
                          "loadHcode, %s failed!",
                          (HBRT_PM_LOAD == i_mode) ? "LOAD" : "RELOAD");
                break;
            }
        } while(0);
/* @TODO RTC: 148935 */
        if (err)
        {
            pm_complex_error(err,
                             rc);
        }

        return rc;
    }


    /**
     *  @brief Start OCC/HCODE on the specified chip
     */
    int start_pm_complex( uint64_t i_chip )
    {
        // HBRT executes p9_pm_init(INIT)

        Target* proc_target = NULL;
        errlHndl_t err = NULL;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "start_pm_complex: RtProcChip %llx", i_chip);

        // Run Sheldon's simics command file @TODO RTC: 148935
        /* MAGIC_INSTRUCTION(MAGIC_RUN_COMMAND_FILE); @TODO RTC: 148935 */

/* @TODO RTC: 148935 start */
        do
        {
            // Utility to convert i_chip to Target
            err = RT_TARG::getHbTarget(i_chip, proc_target);
            if( err )
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
                           proc_target->getAttr<ATTR_HUID>());
            }

            err = HBPM::startPMComplex(proc_target);
            if( err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"start_pm_complex: "
                           "starting OCC failed!" );
                break;
            }
        } while(0);
/* end @TODO RTC: 148935 */
        if ( err )
        {
            pm_complex_error(err,
                             rc);
        }

        return rc;
    }


    /**
     *  @brief Reset OCC/HCODE on the specified chip
     */
    int reset_pm_complex( uint64_t i_chip )
    {
        // HBRT executes p9_pm_init(RESET)

        Target* proc_target = NULL;
        errlHndl_t err = NULL;
        int rc = 0;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "reset_pm_complex: RtProcChip %llx", i_chip);
/* @TODO RTC: 148935 start */
        do
        {
            // Utility to convert i_chip to Target
            err = RT_TARG::getHbTarget(i_chip, proc_target);
            if( err )
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
                           proc_target->getAttr<ATTR_HUID>());
            }

            err = HBPM::resetPMComplex(proc_target);
            if( err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"reset_pm_complex: "
                           "stopping OCC failed!" );
                break;
            }
        } while(0);
/* end @TODO RTC: 148935 */
        if ( err )
        {
            pm_complex_error(err,
                             rc);
        }

        return rc;
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
