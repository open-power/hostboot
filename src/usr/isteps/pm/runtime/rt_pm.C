/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/rt_pm.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#include <htmgt/htmgt.H>

#include <runtime/interface.h>        // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <runtime/runtime_reasoncodes.H>

#include <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/mfgFlagAccessors.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/runtime/rt_targeting.H>
#include    <targeting/translateTarget.H>
#include    <targeting/targplatutil.H>

#include <scom/scomif.H>
#include <scom/wakeup.H>

using namespace TARGETING;
using namespace RUNTIME;
using namespace ERRORLOG;
extern trace_desc_t* g_trac_hbrt;

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
        if(io_rc == 0)
        {
            io_rc = ERRL_GETRC_SAFE(i_err);
        }

        errlCommit( i_err, RUNTIME_COMP_ID );
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

        TRACFCOMP( g_trac_hbrt,ENTER_MRK
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

        TRACFCOMP( g_trac_hbrt,EXIT_MRK
                   "load_pm_complex:rc=0x%X", rc );
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

        TRACFCOMP( g_trac_hbrt,ENTER_MRK
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

#ifdef CONFIG_HTMGT
            HTMGT::processOccStartStatus(true, // i_startCompleted
                                         nullptr); // failed proc
#endif

        } while(0);

        if ( l_err )
        {
            pm_complex_error(l_err,
                             rc);
        }

        TRACFCOMP( g_trac_hbrt,EXIT_MRK
                   "start_pm_complex:rc=0x%X", rc );
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

        TRACFCOMP( g_trac_hbrt,ENTER_MRK
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

        TRACFCOMP( g_trac_hbrt,EXIT_MRK
                   "reset_pm_complex:rc=0x%X", rc );
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
            const TARGETING::Target * l_pChipTarget =
                getParentChip(const_cast<TARGETING::Target *>(i_target));

            // Check to see if hcode is loaded
            uint8_t l_hcode_loaded =
                l_pChipTarget->getAttr<ATTR_HOMER_HCODE_LOADED>();

            if(l_hcode_loaded == HBPM::HCODE_NOT_LOADED)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"hcode_update: HCODE not loaded."
                          " Target 0x%llX section 0x%X "
                          "operation 0x%X scomAddr 0x%llX scomData 0x%llX",
                          get_huid(i_target), i_section,
                          i_operation, i_rel_scom_addr, i_scom_data);
                break;
            }

            if( g_hostInterfaces == NULL ||
                ( g_hostInterfaces->hcode_scom_update == NULL &&
                  g_hostInterfaces->firmware_request == NULL ))
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"hcode_update: Hypervisor hcode_scom_update"
                                 "/firmware_request interface not linked");
                /*@
                * @errortype
                * @severity         ERRL_SEV_INFORMATIONAL
                * @moduleid         MOD_PM_RT_HCODE_UPDATE
                * @reasoncode       RC_PM_RT_INTERFACE_ERR
                * @userdata1[0:31]  Target HUID
                * @userdata1[32:63] SCOM restore section
                * @userdata2        SCOM address
                * @devdesc          HCODE scom update runtime
                *                   interface not linked.
                */
                l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                     MOD_PM_RT_HCODE_UPDATE,
                                     RC_PM_RT_INTERFACE_ERR,
                                     TWO_UINT32_TO_UINT64(
                                              TARGETING::get_huid(i_target),
                                              i_section),
                                     i_rel_scom_addr);
                break;
            }

            // Enable special wakeup
            l_err = handleSpecialWakeup(i_target,WAKEUP::ENABLE);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: "
                           "handleSpecialWakeup enable ERROR" );
                break;
            }

            // Get the Proc Chip Id
            TARGETING::rtChipId_t l_chipId = 0;

            l_err = TARGETING::getRtTarget(l_pChipTarget, l_chipId);
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

            // If hcode_scom_update is not NULL then use that method
            // else use firmware_request.  hcode_scom_update takes
            // precedence over firmware_request
            if (g_hostInterfaces->hcode_scom_update != nullptr)
            {
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
                            "rc: 0x%X, target: 0x%llX, chipId: 0x%llX, "
                            "section: 0x%X, operation: 0x%X, scomAddr: 0x%llX, "
                            "scomData: 0x%llX",
                            rc, get_huid(i_target), l_chipId, i_section,
                            i_operation, l_scomAddr, i_scom_data);

                   /*@
                   * @errortype
                   * @severity     ERRL_SEV_INFORMATIONAL
                   * @moduleid     MOD_PM_RT_HCODE_UPDATE
                   * @reasoncode   RC_PM_RT_HCODE_UPDATE_ERR
                   * @userdata1    Hypervisor return code
                   * @userdata2    SCOM address
                   * @devdesc      HCODE SCOM update error
                   */
                   l_err = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                          MOD_PM_RT_HCODE_UPDATE,
                                          RC_PM_RT_HCODE_UPDATE_ERR,
                                          rc,
                                          l_scomAddr);
                   break;
               }
            }
            else if (g_hostInterfaces->firmware_request != nullptr)
            {
               // Create the firmware_request request struct to send data
               hostInterfaces::hbrt_fw_msg l_req_fw_msg;
               uint64_t l_req_fw_msg_size = sizeof(l_req_fw_msg);
               memset(&l_req_fw_msg, 0, l_req_fw_msg_size);

               // Populate the firmware_request request struct with given data
               l_req_fw_msg.io_type =
                         hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE;
               l_req_fw_msg.req_hcode_update.i_chipId = l_chipId;
               l_req_fw_msg.req_hcode_update.i_section = i_section;
               l_req_fw_msg.req_hcode_update.i_operation = i_operation;
               l_req_fw_msg.req_hcode_update.i_scomAddr = l_scomAddr;
               l_req_fw_msg.req_hcode_update.i_scomData = i_scom_data;

               // Trace out firmware request info
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         INFO_MRK"HCODE update firmware request info: "
                         "io_type:%d, chipId:0x%llX, section:0x%X, "
                         "operation:0x%X, scomAddr:0x%llX, scomData:0x%llX",
                           l_req_fw_msg.io_type,
                           l_req_fw_msg.req_hcode_update.i_chipId,
                           l_req_fw_msg.req_hcode_update.i_section,
                           l_req_fw_msg.req_hcode_update.i_operation,
                           l_req_fw_msg.req_hcode_update.i_scomAddr,
                           l_req_fw_msg.req_hcode_update.i_scomData);

               // Create the firmware_request response struct to receive data
               hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
               uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
               memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

                // Make the firmware_request call
               l_err = firmware_request_helper(l_req_fw_msg_size,
                                                &l_req_fw_msg,
                                                &l_resp_fw_msg_size,
                                                &l_resp_fw_msg);

               if (l_err)
               {
                   // If error, break out of encompassing while loop
                   break;
               }
            } // END else if (g_hostInterfaces->firmware_request != nullptr)

            // Disable special wakeup
            l_err = handleSpecialWakeup(i_target,WAKEUP::DISABLE);
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"hcode_update: "
                           "handleSpecialWakeup disable ERROR" );
                break;
            }

        } while (0);

        if (l_err)
        {
            l_err->collectTrace(ISTEP_COMP_NAME,1024);
        }
        return l_err;
    }

    void load_and_start_pm_complex()
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ENTER_MRK"load_and_start_pm_complex");
#ifdef CONFIG_AUTO_START_PM_COMPLEX_FOR_PHYP

        int l_rc = 0;
        errlHndl_t l_errl = nullptr;
        Target* l_failedProc = nullptr;
        bool l_attemptedLoadAndStart = false;

        Target* l_sys = UTIL::assertGetToplevelTarget();
        auto pm_type = l_sys->getAttr<ATTR_PM_COMPLEX_LOAD_REQ>();

        // Load and start the PM Complex/OCCs on PHYP systems
        if(is_phyp_load())
        {
            if ((pm_type == PM_COMPLEX_LOAD_TYPE_LOAD) ||
                (pm_type == PM_COMPLEX_LOAD_TYPE_RELOAD))
            {

                bool l_start_completed = true;
                l_attemptedLoadAndStart = true;
                l_errl = HBPM::loadAndStartPMAll(
                              (pm_type == PM_COMPLEX_LOAD_TYPE_LOAD)
                                ? HBPM::PM_LOAD : HBPM::PM_RELOAD,
                              l_failedProc);
                if(l_errl)
                {
                    pm_complex_error(l_errl, l_rc);
                    l_start_completed = false;
                }

                if(l_failedProc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"load_and_start_pm_complex: could not load/start PM Complex on proc HUID 0x%08x",
                              get_huid(l_failedProc));
                    l_start_completed = false;
                }

#ifdef CONFIG_HTMGT
                // Notify HTMGT of the PM Complex start status.
                // HTMGT will attempt recovery if necessary.
                HTMGT::processOccStartStatus(l_start_completed,
                                             l_failedProc);
#else
                // Verify all OCCs completed their init and reached checkpoint
                if (l_start_completed)
                {
                    l_errl = HBPM::verifyOccChkptAll();
                    if(l_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  ERR_MRK"load_and_start_pm_complex: verifyOccChkptAll failed!");
                        pm_complex_error(l_errl, l_rc);
                    }
                }
#endif
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          INFO_MRK"load_and_start_pm_complex: skipping (re)load due to pm_type=0x%X",
                          pm_type);
            }
        }

        if(l_rc)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"load_and_start_pm_complex: error occurred; rc: %d", l_rc);
        }

        if (l_attemptedLoadAndStart == true)
        {
            // Only ever try to load or reload once, so always change to "Do Not Load" here
            pm_type = PM_COMPLEX_LOAD_TYPE_DO_NOT_LOAD;
            l_sys->setAttr<ATTR_PM_COMPLEX_LOAD_REQ>(pm_type);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                      "load_and_start_pm_complex: Attempted. Setting ATTR_PM_COMPLEX_LOAD_REQ to "
                      "PM_COMPLEX_LOAD_TYPE_DO_NOT_LOAD (0x%X) to not (re)load again",
                      pm_type);
        }
#endif
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  EXIT_MRK"load_and_start_pm_complex");
    }

    //------------------------------------------------------------------------

    struct registerPm
    {
        registerPm()
        {
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->load_pm_complex = DISABLE_MCTP_WRAPPER(load_pm_complex);
            rt_intf->start_pm_complex = DISABLE_MCTP_WRAPPER(start_pm_complex);

#ifdef CONFIG_FSP_BUILD
            // reset_pm_complex interface only used on FSP systems
            rt_intf->reset_pm_complex = &reset_pm_complex;
#endif

            // If we already loaded OCC during the IPL we need to fix up
            //  the virtual address because we're now not using virtual
            //  memory

            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            for (TargetHandleList::iterator itr = procChips.begin();
                 itr != procChips.end();
                 ++itr)
            {
                // Note: the instance we use to retrieve the data must
                //   match the value we used to populate HDAT originally
                uint32_t l_instance = (*itr)->getAttr<ATTR_HBRT_HYP_ID>();
                uint64_t l_homerAddr = g_hostInterfaces->
                            get_reserved_mem(HBRT_RSVD_MEM__HOMER,
                                             l_instance);
                (*itr)->setAttr<ATTR_HOMER_VIRT_ADDR>(l_homerAddr);
            }
        }
    };

    registerPm g_registerPm;
};
