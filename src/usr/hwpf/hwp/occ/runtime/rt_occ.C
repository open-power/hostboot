/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/runteim/rt_occ.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <runtime/interface.h>
#include <kernel/console.H>
#include <hwpf/hwp/occ/occ.H>
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

// @TODO RTC 98547
// There is potential to share more code with src/hwpf/hwp/occ/occ.C,
// but would require refactoring the HB occ code and modifying the order and
// sequence of some events.

namespace RT_OCC
{
    typedef std::vector<TARGETING::Target *> target_list_t;

    //------------------------------------------------------------------------

    errlHndl_t addHostData(uint64_t i_hostdata_addr)
    {
        errlHndl_t err = NULL;
        //Treat virtual address as starting pointer
        //for config struct
        HBOCC::occHostConfigDataArea_t * config_data =
            reinterpret_cast<HBOCC::occHostConfigDataArea_t *>
            (i_hostdata_addr);

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB>();

        config_data->version = HBOCC::OccHostDataVersion;
        config_data->nestFrequency = nestFreq;

        return err;
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

            // Convert to fapi Target
            fapi::Target fapiTarg( fapi::TARGET_TYPE_PROC_CHIP,
                                   (const_cast<TARGETING::Target*>(proc_target)
                                   ));

            TRACFCOMP( g_fapiTd, "FapiTarget: %s",fapiTarg.toEcmdString());

            // BAR0 is the Entire HOMER, Bar size is in MB
            FAPI_INVOKE_HWP( err,
                             p8_pba_bar_config,
                             fapiTarg,
                             0,                  //BAR0
                             i_homer_addr_phys,
                             VMM_HOMER_INSTANCE_SIZE_IN_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( err )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"Bar0 config failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // BAR1 is what OCC uses to talk to the Centaur. Bar size is in MB
            uint64_t centaur_addr =
                proc_target->getAttr<ATTR_IBSCOM_PROC_BASE_ADDR>();

            FAPI_INVOKE_HWP( err,
                             p8_pba_bar_config,
                             fapiTarg,
                             1,             //BAR1
                             centaur_addr,  //i_pba_bar_addr
                             //i_pba_bar_size
                             (uint64_t)HBOCC::OCC_IBSCOM_RANGE_IN_MB,
                             PBA_CMD_SCOPE_NODAL ); //i_pba_cmd_scope

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"Bar1 config failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // BAR3 is the OCC Common Area
            // Bar size is in MB, obtained value of 8MB from Tim Hallett
            FAPI_INVOKE_HWP( err,
                             p8_pba_bar_config,
                             fapiTarg,
                             3,             //BAR3
                             i_common_addr_phys,
                             VMM_OCC_COMMON_SIZE_IN_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( err )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"Bar3 config failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // Load HOMER image
            UtilLidMgr lidmgr(HBOCC::OCC_LIDID);

            size_t lidSize = 0;
            err = lidmgr.getLidSize(lidSize);
            if( err )
            {
                break;
            }

            err = lidmgr.getLid(reinterpret_cast<void*>(i_homer_addr_va),
                                lidSize);
            if( err )
            {
                break;
            }

            TRACFCOMP( g_fapiTd,
                       "OCC lid loaded. ID:%x size:%d",
                       HBOCC::OCC_LIDID,
                       lidSize);

            // Setup Host Data area of HOMER
            err = addHostData(i_homer_addr_va+HOMER_OFFSET_TO_OCC_HOST_DATA);
            if( err )
            {
                break;
            }

        } while(0);

        if ( err )
        {
            errlCommit( err, HWPF_COMP_ID );
            if(rc == 0)
            {
                rc = -1;
            }
        }
        return rc;
    }

    //------------------------------------------------------------------------

    errlHndl_t start_occ(TARGETING::Target * i_target0,
                         TARGETING::Target * i_target1)
    {
        errlHndl_t err = NULL;
        do
        {
            const fapi::Target
                l_fapiTarg0(fapi::TARGET_TYPE_PROC_CHIP,
                            (const_cast<TARGETING::Target*>(i_target0)));

            fapi::Target l_fapiTarg1;
            if(i_target1)
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_PROC_CHIP);
                l_fapiTarg1.set(const_cast<TARGETING::Target*>(i_target1));

            }
            else
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_NONE);
            }

            FAPI_INVOKE_HWP( err,
                             p8_pm_init,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_CONFIG );

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"p8_pm_init, config failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // Init path
            // p8_pm_init.C enum: PM_INIT
            FAPI_INVOKE_HWP( err,
                             p8_pm_init,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_INIT );

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"p8_pm_init, init failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }
            TRACFCOMP( g_fapiTd,
                       INFO_MRK"OCC Finished: p8_pm_init.C enum: PM_INIT" );


            //==============================
            //Start the OCC on primary chip of DCM
            //==============================
            FAPI_INVOKE_HWP( err,
                             p8_occ_control,
                             l_fapiTarg0,
                             PPC405_RESET_OFF,
                             PPC405_BOOT_MEM );

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"occ_control failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            // Start the OCC on slave chip of DCM
            //==============================
            if ( l_fapiTarg1.getType() != fapi::TARGET_TYPE_NONE )
            {
                FAPI_INVOKE_HWP( err,
                                 p8_occ_control,
                                 l_fapiTarg1,
                                 PPC405_RESET_OFF,
                                 PPC405_BOOT_MEM );

                if ( err != NULL )
                {
                    TRACFCOMP( g_fapiTd,
                               ERR_MRK"occ_control failed!" );
                    err->collectTrace(FAPI_TRACE_NAME,256);
                    err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                    break;
                }
            }
        } while(0);

        return err;
    }

    //------------------------------------------------------------------------

    errlHndl_t stop_occ(TARGETING::Target * i_target0,
                        TARGETING::Target * i_target1)
    {
        errlHndl_t err = NULL;
        do
        {
            const fapi::Target
                l_fapiTarg0(fapi::TARGET_TYPE_PROC_CHIP,
                            (const_cast<TARGETING::Target*>(i_target0)));

            fapi::Target l_fapiTarg1;
            if(i_target1)
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_PROC_CHIP);
                l_fapiTarg1.set(const_cast<TARGETING::Target*>(i_target1));

            }
            else
            {
                l_fapiTarg1.setType(fapi::TARGET_TYPE_NONE);
            }

            FAPI_INVOKE_HWP( err,
                             p8_pm_prep_for_reset,
                             l_fapiTarg0,
                             l_fapiTarg1,
                             PM_RESET );

            if ( err != NULL )
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"p8_pm_prep_for_reset failed!" );
                err->collectTrace(FAPI_TRACE_NAME,256);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

        } while(0);

        return err;
    }

    //------------------------------------------------------------------------

    int executeOnDcms(HBOCC::occAction_t i_action,
                      uint64_t * i_proc_chip,
                      size_t i_num_chips)
    {
        errlHndl_t err = NULL;
        int rc = 0;

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
                        err = start_occ(*itarg, NULL);
                    }
                    else if(i_action == HBOCC::OCC_STOP)
                    {
                        err = stop_occ(*itarg, NULL);
                    }

                    // TODO RTC 101156
                    // error handling still being designed
                    // Need new interface from Sapphire?
                    if( err )
                    {
                        errlCommit( err, HWPF_COMP_ID );
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
                    err = start_occ(t0,t1);
                }
                else if(i_action == HBOCC::OCC_STOP)
                {
                    err = stop_occ(t0,t1);
                }

                // TODO RTC 101156 Error handling still being designed
                // Need new interface from Sapphire?
                if( err )
                {
                    errlCommit( err, HWPF_COMP_ID );
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
            rt_intf->loadOCC = &executeLoadOCC;
            rt_intf->startOCCs = &executeStartOCCs;
            rt_intf->stopOCCs = &executeStopOCCs;
        }
    };

    registerOcc g_registerOcc;
}

