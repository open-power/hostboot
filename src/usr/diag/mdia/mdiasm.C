/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiasm.C $                                  */
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
 * @file mdiasm.C
 * @brief mdia state machine implementation
 */

#include "mdiasm.H"
#include "mdiasmimpl.H"
#include "mdiatrace.H"
#include "mdiaworkitem.H"
#include "mdiamonitor.H"
#include <errl/errlmanager.H>
#include <stdio.h>
#include <mdia/mdiamevent.H>
#include <hbotcompid.H>
//#include <fapi.H>  TODO RTC 145132
//#include <fapiPlatHwpInvoker.H>  TODO RTC 145132
#include <diag/prdf/prdfMain.H>
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <errl/errludlogregister.H>
#include <initservice/istepdispatcherif.H>
#include <ipmi/ipmiwatchdog.H>
#include <config.h>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace std;
using namespace fapi;
using namespace DeviceFW;

namespace MDIA
{

void StateMachine::running(bool & o_running)
{
    mutex_lock(&iv_mutex);

    o_running = !(iv_done || iv_shutdown);

    mutex_unlock(&iv_mutex);
}

void addTimeoutFFDC(TargetHandle_t i_mba, errlHndl_t & io_log)
{
    const uint64_t mbaRegs[] = {
        MBA01_SPA,
        MBA01_SPA_MASK,
        MBA01_CMD_TYPE,
        MBA01_CMD_CONTROL,
        MBA01_CMD_STATUS,
        MBA01_MBMACAQ,
        MBA01_MBMEA,
    };

    const uint64_t membufRegs[] = {
        MEM_SPA_FIR,
        MEM_SPA_FIR_MASK,
    };

    const uint64_t mcsRegs[] = {
        MCI_FIR,
        MCI_FIR_MASK,
        MCI_FIR_ACT0,
        MCI_FIR_ACT1,
        MCS_MODE4,
    };

    const uint64_t procRegs[] = {
        HOST_ATTN_PRES,
        HOST_ATTN_MASK,
        HOST_ATTN_CFG,
        IPOLL_MASK,
        IPOLL_STATUS,
        PBUS_GP1,
        PBUS_GP2,
        GLOBAL_CS_FIR,
        GLOBAL_RE_FIR,
        GLOBAL_SPA,
    };

    // get the parent membuf
    ConstTargetHandle_t membuf = getParentChip(i_mba);

    // get the parent mcs
    TargetHandleList targetList;
    TargetHandle_t mcs = NULL;
    if(membuf)
    {
        getParentAffinityTargets(
                targetList,
                membuf,
                CLASS_UNIT,
                TYPE_MCS);
    }
    if(targetList.size() == 1)
    {
        mcs = targetList[0];
    }

    // get the parent proc
    ConstTargetHandle_t proc = NULL;
    if(mcs)
    {
        proc = getParentChip(mcs);
    }

    const struct Entry
    {
        TARGETING::ConstTargetHandle_t target;
        const uint64_t * begin;
        const uint64_t * end;
    } tables[] = {
        {i_mba, mbaRegs, mbaRegs + sizeof(mbaRegs)/sizeof(*mbaRegs)},
        {membuf,
            membufRegs, membufRegs + sizeof(membufRegs)/sizeof(*membufRegs)},
        {mcs, mcsRegs, mcsRegs + sizeof(mcsRegs)/sizeof(*mcsRegs)},
        {proc, procRegs, procRegs + sizeof(procRegs)/sizeof(*procRegs)},
    };

    for(const Entry * tableIt = tables;
            tableIt != tables + sizeof(tables)/sizeof(*tables);
            ++tableIt)
    {
        if(!tableIt->target)
        {
            continue;
        }

        for(const uint64_t * regIt = tableIt->begin;
                regIt != tableIt->end;
                ++regIt)
        {
            ErrlUserDetailsLogRegister udLogRegister(
                    tableIt->target,
                    DEVICE_SCOM_ADDRESS(*regIt));
            udLogRegister.addToLog(io_log);
        }
    }

    // collect these traces for timeout debugging
    io_log->collectTrace("MDIA_FAST",512);
    io_log->collectTrace(PRDF_COMP_NAME,512);
//    io_log->collectTrace(FAPI_TRACE_NAME,512);  TODO RTC 145132
//    io_log->collectTrace(FAPI_IMP_TRACE_NAME,512);  TODO RTC 145132

}
// Do the setup for CE thresholds
errlHndl_t ceErrorSetup( TargetHandle_t i_mba )
{
    errlHndl_t err = NULL;
/* TODO RTC 145132
    ecmdDataBufferBase buffer(64);

    do
    {
        // get the parent membuf
        TargetHandle_t membuf = const_cast<TargetHandle_t >(getParentChip(
                                            i_mba));
        uint64_t addr = ( ( 0 == i_mba->getAttr<TARGETING::ATTR_CHIP_UNIT>()) ?
                       MEM_MBA0_MBSTR : MEM_MBA1_MBSTR );

        fapi::Target fapiMb(TARGET_TYPE_MEMBUF_CHIP, membuf);
        ReturnCode fapirc = fapiGetScom( fapiMb, addr , buffer);

        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_FAST("ceErrorSetup: fapiGetScom on 0x%08X failed HUID:0x%08X",
                      addr, get_huid(membuf));
            break;
        }

        // set 0-3 bits to  Enable soft, intermittent, hard and Retry CE
        // threshold attention
        // set error threshold to 1 ( set 15,27,39,51 bits ).
        // Enable per-symbol error counters to count soft, intermittent
        // and hard CEs ( set 55, 56, 57 bits ).
        // First clear starting 52 bits and than set relevant bits.

        uint64_t data = ( buffer.getDoubleWord(0) & 0x0000000000000fff )
                        | 0xf0010010010011c0;

        if( ECMD_DBUF_SUCCESS != buffer.setDoubleWord(0, data) )
        {
            MDIA_FAST("ceErrorSetup: setDoubleWord for 0x%08X failed"
                      " HUID:0x%08X data:0x%16X",
                      addr, get_huid(membuf), data);
            break;
        }

        fapirc = fapiPutScom( fapiMb, addr , buffer);
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_FAST("ceErrorSetup: fapiPutScom on 0x%08X failed HUID:0x%08X",
                      addr, get_huid(i_mba));
            break;
        }
    } while(0);
*/

    return err;
}

void StateMachine::processCommandTimeout(const MonitorIDs & i_monitorIDs)
{
    MDIA_FAST("sm: processCommandTimeout");
/*  TODO RTC 145132
    WorkFlowProperties *wkflprop = NULL;
    errlHndl_t err = NULL;

    vector<mss_MaintCmd *> stopCmds;

    mutex_lock(&iv_mutex);

    for(MonitorIDs::const_iterator monitorIt = i_monitorIDs.begin();
            monitorIt != i_monitorIDs.end();
            ++monitorIt)
    {
        for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
                wit != iv_workFlowProperties.end();
                ++wit)
        {
            if((*wit)->timer == *monitorIt)
            {
                TargetHandle_t target = getTarget(**wit);
                ecmdDataBufferBase buffer(64);
                uint64_t mbaspa = 0;
                uint64_t mbaspamask = 0;
                // check MBASPA for maint cmd complete bit
                // if set then don't time out
                fapi::Target fapiMba(TARGET_TYPE_MBA_CHIPLET, target);
                ReturnCode fapirc = fapiGetScom( fapiMba,  MBA01_SPA, buffer);

                err = fapiRcToErrl(fapirc);
                if(err)
                {
                    MDIA_FAST("sm: fapiGetScom on 0x%08X failed HUID:0x%08X",
                              MBA01_SPA, get_huid(target));
                    //commit locally and let it timeout
                    errlCommit(err, MDIA_COMP_ID);
                }
                else
                {
                    mbaspa = buffer.getDoubleWord(0) & 0x8080000000000000;
                }

                if(0 != mbaspa)
                {
                    fapirc = fapiGetScom( fapiMba,  MBA01_SPA_MASK, buffer);

                    err = fapiRcToErrl(fapirc);
                    if(err)
                    {
                        MDIA_FAST("sm: fapiGetScom on 0x%08X failed "
                                  "HUID:0x%08X",
                                  MBA01_SPA_MASK, get_huid(target));
                        //commit locally and let it timeout
                        errlCommit(err, MDIA_COMP_ID);
                    }
                    else
                    {
                        mbaspamask = buffer.getDoubleWord(0);
                    }
                }

                // Pending maint cmd complete, reset timer
                if(mbaspa & ~mbaspamask)
                {
                    // Committing an info log to help debug SW timeout
                    if((*wit)->timeoutCnt >= MBA_TIMEOUT_LOG)
                    {
                        MDIA_FAST("sm: committing a SW timed out info log "
                                  "for %x", get_huid(target));

                        / *@
                         * @errortype
                         * @reasoncode       MDIA::MAINT_COMMAND_SW_TIMED_OUT
                         * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
                         * @moduleid         MDIA::PROCESS_COMMAND_TIMEOUT
                         * @userData1        Associated memory diag work item
                         * @userData2        Target HUID
                         * @devdesc          A maint command SW timed out
                         * /
                        err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                            PROCESS_COMMAND_TIMEOUT,
                                            MAINT_COMMAND_SW_TIMED_OUT,
                                            *((*wit)->workItem),
                                            get_huid(target));

                        // collect ffdc

                        addTimeoutFFDC(target, err);

                        errlCommit(err, MDIA_COMP_ID);

                        // reset for the next logging
                        (*wit)->timeoutCnt = 0;
                    }
                    else
                    {
                        // advance timeout counter
                        (*wit)->timeoutCnt++;
                    }

                    MDIA_FAST("sm: work item %d reset SW timed out on: %x, "
                              "timeoutCnt: %d", *((*wit)->workItem),
                              get_huid(target), (*wit)->timeoutCnt);
                    // register a new timeout monitor
                    uint64_t monitorId =
                        getMonitor().addMonitor(MBA_TIMEOUT);
                    (*wit)->timer = monitorId;

                    break;
                }

                // If maint cmd complete bit is not on, time out

                stopCmds.push_back(static_cast<mss_MaintCmd *>((*wit)->data));
                (*wit)->data = NULL;

                (*wit)->status = COMMAND_TIMED_OUT;
                wkflprop = *wit;

                // log a timeout event
                MDIA_ERR("sm: command %p: %d HW timed out on: %x",
                        stopCmds.back(),
                        *((*wit)->workItem),
                        get_huid(target));

                / *@
                 * @errortype
                 * @reasoncode       MDIA::MAINT_COMMAND_HW_TIMED_OUT
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         MDIA::PROCESS_COMMAND_TIMEOUT
                 * @userData1        Associated memory diag work item
                 * @userData2        Target HUID
                 * @devdesc          A maint command HW timed out
                 * /
                err = new ErrlEntry(
                        ERRL_SEV_UNRECOVERABLE,
                        PROCESS_COMMAND_TIMEOUT,
                        MAINT_COMMAND_HW_TIMED_OUT,
                        *((*wit)->workItem),
                        get_huid(target));

                // collect ffdc

                addTimeoutFFDC(target, err);

                err->addHwCallout(target,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::DELAYED_DECONFIG,
                        HWAS::GARD_NULL);

                errlCommit(err, MDIA_COMP_ID);

                break;
            }
        }

        // if this is the very last command(s), schedule must be called
        // so the waiting istep thread is signaled that we are done.

        // If no match is found (wkflprop), all the attentions came
        // in before the timeout(s) could be processed.  the prd thread
        // will have already started the next command(s), if any.

        if(wkflprop)
        {
            scheduleWorkItem(*wkflprop);
        }
    }

    mutex_unlock(&iv_mutex);

    // try and stop the commands that timed out.

    for(vector<mss_MaintCmd *>::iterator cit = stopCmds.begin();
            cit != stopCmds.end();
            ++cit)
    {
        MDIA_FAST("sm: stopping command: %p", *cit);

        ReturnCode fapirc = (*cit)->stopCmd();
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_ERR("sm: mss_MaintCmd::stopCmd failed");
            errlCommit(err, MDIA_COMP_ID);
        }

        fapirc = (*cit)->cleanupCmd();

        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_ERR("sm: mss_MaintCmd::cleanupCmd failed");
            errlCommit(err, MDIA_COMP_ID);
        }

        delete (*cit);
    }
*/
}

errlHndl_t StateMachine::run(const WorkFlowAssocMap & i_list)
{
    // load the workflow properties

    setup(i_list);

    // start work items

    start();

    // wait for all work items to finish

    wait();

    // act on workFlow errors

    mutex_lock(&iv_mutex);

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((*wit)->log)
        {
            errlCommit((*wit)->log, MDIA_COMP_ID);
        }
    }

    mutex_unlock(&iv_mutex);

    return 0;
}

void StateMachine::setup(const WorkFlowAssocMap & i_list)
{
    // clear out any properties from a previous run

    reset();

    AttributeTraits<TARGETING::ATTR_EFF_DIMM_SIZE>::Type effDimmSizeAttr;

    mutex_lock(&iv_mutex);

    WorkFlowProperties * p = 0;

    for(WorkFlowAssoc it = i_list.begin(); it != i_list.end(); ++it)
    {
        // for each target / workFlow assoc,
        // initialize the workFlow progress indicator
        // to indicate that no work has been done yet
        // for the target

        p = new WorkFlowProperties();

        p->assoc = it;
        p->workItem = getWorkFlow(it).begin();
        p->status = IN_PROGRESS;
        p->log = 0;
        p->timer = 0;
        p->restartCommand = false;
        p->memSize = 0;
        p->timeoutCnt = 0;

        // get the memsize attached to this mba

        if(it->first->tryGetAttr<TARGETING::ATTR_EFF_DIMM_SIZE>(
                    effDimmSizeAttr))
        {
            for(uint64_t port = 0;
                    port < sizeof(effDimmSizeAttr)/sizeof(*effDimmSizeAttr);
                    ++port)
            {
                for(uint64_t dimm = 0;
                        dimm <
                        sizeof(effDimmSizeAttr[0])/sizeof(*effDimmSizeAttr[0]);
                        ++dimm)
                {
                    p->memSize += effDimmSizeAttr[port][dimm];
                }
            }
        }

        p->data = NULL;
        p->chipUnit = it->first->getAttr<ATTR_CHIP_UNIT>();

        iv_workFlowProperties.push_back(p);
    }

    if(iv_workFlowProperties.empty())
    {
        iv_done = true;
    }
    else
    {
        iv_done = false;
    }

    MDIA_FAST("sm: setup complete: target(s): %d, status: %d",
            iv_workFlowProperties.size(), iv_done);

    mutex_unlock(&iv_mutex);
}

void StateMachine::wait()
{
    mutex_lock(&iv_mutex);

    MDIA_FAST("sm: waiting for completion of %d target(s), status: %d",
            iv_workFlowProperties.size(), iv_done);

    // wait for everything to finish

    while(!iv_done && !iv_shutdown)
    {
        sync_cond_wait(&iv_cond, &iv_mutex);
    }

    mutex_unlock(&iv_mutex);
}

void StateMachine::start()
{
    mutex_lock(&iv_mutex);

    MDIA_FAST("sm: starting up");

    iv_shutdown = false;

    // schedule the first work items for all target / workFlow associations

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        scheduleWorkItem(**wit);
    }

    mutex_unlock(&iv_mutex);
}

bool StateMachine::scheduleWorkItem(WorkFlowProperties & i_wfp)
{
    // schedule work items for execution in the thread pool

    // see if the workFlow for this target is complete
    // and see if all phases have completed successfully

    if(i_wfp.workItem == getWorkFlow(i_wfp).end())
    {
        i_wfp.status = COMPLETE;
    }

    // see if the workFlow for this target is done...for better or worse
    // (failed or successful)
    // if it is, also check to see if all workFlows for all targets
    // are complete

    if(i_wfp.status != IN_PROGRESS && allWorkFlowsComplete())
    {
        // Clear BAD_DQ_BIT_SET bit
        TargetHandle_t top = NULL;
        targetService().getTopLevelTarget(top);
        ATTR_RECONFIGURE_LOOP_type reconfigAttr =
            top->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
        reconfigAttr &= ~RECONFIGURE_LOOP_BAD_DQ_BIT_SET;
        top->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(reconfigAttr);

        // all workFlows are finished
        // release the init service dispatcher
        // thread waiting for completion

        MDIA_FAST("sm: all workflows finished");

        iv_done = true;
        sync_cond_broadcast(&iv_cond);
    }

    else if(i_wfp.status == IN_PROGRESS)
    {
        // still work left for this target

        // 1 - get the phase for the target,
        // 2 - create the work item
        // 3 - schedule it

        // determine the priority for the work item to be scheduled
        // the priority is the number of iterations
        // through the memory multiplied by the memory size

        // multiply by memory size
        // assume 1 GB DIMMS if figuring out the memory
        // size failed
        uint64_t priority = getRemainingWorkItems(i_wfp)
            * (i_wfp.memSize ? i_wfp.memSize : 1);

        if(!iv_tp)
        {
            MDIA_FAST("Starting threadPool...");
            iv_tp = new Util::ThreadPool<WorkItem>();
            iv_tp->start();
        }

        TargetHandle_t target = getTarget(i_wfp);

        MDIA_FAST("sm: dispatching work item %d for: %p, priority: %d, "
                "unit: %d", *i_wfp.workItem,
                get_huid(target),
                priority,
                i_wfp.chipUnit);

        iv_tp->insert(new WorkItem(*this, &i_wfp, priority, i_wfp.chipUnit));

        return true;
    }

    return false;
}

bool StateMachine::workItemIsAsync(WorkFlowProperties & i_wfp)
{
    bool async = true;

    switch (*i_wfp.workItem)
    {
        case RESTORE_DRAM_REPAIRS:
        case DUMMY_SYNC_PHASE:
        case CLEAR_HW_CHANGED_STATE:
        case ANALYZE_IPL_MNFG_CE_STATS:

            // no attention associated with these so
            // schedule the next work item now

            async = false;
            break;

        default:

            async = true;
            break;
    }

    return async;
}

bool StateMachine::executeWorkItem(WorkFlowProperties * i_wfp)
{
    bool dispatched = false;

    // thread pool work item entry point

    mutex_lock(&iv_mutex);

    // ensure this thread sees the most recent state

    if(!iv_shutdown)
    {
        bool async = workItemIsAsync(*i_wfp);

        uint64_t workItem = *i_wfp->workItem;

        MDIA_FAST("sm: executing work item %d for: %x",
                workItem, get_huid(getTarget(*i_wfp)));

        mutex_unlock(&iv_mutex);

        errlHndl_t err = 0;
        int32_t rc = 0;

        switch(workItem)
        {
            // do the appropriate thing based on the phase for this target

            case RESTORE_DRAM_REPAIRS:

                rc = PRDF::restoreDramRepairs(getTarget(*i_wfp));

                break;

            case START_PATTERN_0:
            case START_PATTERN_1:
            case START_PATTERN_2:
            case START_PATTERN_3:
            case START_PATTERN_4:
            case START_PATTERN_5:
            case START_PATTERN_6:
            case START_PATTERN_7:
            case START_RANDOM_PATTERN:
            case START_SCRUB:

                err = doMaintCommand(*i_wfp);

                break;

            case CLEAR_HW_CHANGED_STATE:

                mutex_lock(&iv_mutex);

                clearHWStateChanged(getTarget(*i_wfp));

                mutex_unlock(&iv_mutex);

                break;

            case ANALYZE_IPL_MNFG_CE_STATS:
            {
                MDIA_FAST("Executing analyzeIplCEStats");
                bool calloutMade = false;
                TargetHandle_t mba = getTarget( *i_wfp);
                rc = PRDF::analyzeIplCEStats( mba,
                                              calloutMade);
                if( rc)
                {
                    MDIA_FAST("executeWorkItem: PRDF::analyzeIplCEStats failed "
                      "rc:%d HUID:0x%08X", rc, get_huid(mba));
                }
                if( calloutMade )
                {
                    // There is no reason to update HCDB as we are doing
                    // deferred deconfig. HCDB will be updated at end of istep
                    // during deferred deconfig only. Just adding information
                    // message here.
                    MDIA_FAST("PRD performed HW callouts during"
                              "analyzeIplCEStats");
                }

            }
                break;

            default:
                break;
        }

        mutex_lock(&iv_mutex);

        if(err || rc)
        {
            // stop the workFlow for this target

            i_wfp->status = FAILED;
            i_wfp->log = err;
        }

        else if(!async)
        {
            // sync work item -
            // move the workFlow pointer to the next phase
            ++i_wfp->workItem;
        }

        if(err || !async)
        {
            // check to see if this was the last workFlow
            // in progress (if there was an error), or for sync
            // work items, schedule the next work item
            dispatched = scheduleWorkItem(*i_wfp);
        }
    }
    mutex_unlock(&iv_mutex);

    return dispatched;
}

errlHndl_t StateMachine::doMaintCommand(WorkFlowProperties & i_wfp)
{
    // uint64_t timeout = i_wfp.memSize / 1024; // TODO RTC 47590
    errlHndl_t err = NULL;

/* TODO RTC 145132
    uint64_t stopCondition =
                mss_MaintCmd::STOP_END_OF_RANK                  |
                mss_MaintCmd::STOP_ON_MPE                       |
                mss_MaintCmd::STOP_ON_UE                        |
                mss_MaintCmd::STOP_ON_END_ADDRESS               |
                mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

    uint64_t workItem;
    bool restart;
    TargetHandle_t targetMba;
    ecmdDataBufferBase startAddr(64), endAddr(64);
    mss_MaintCmd * cmd = NULL;

    // starting a maint cmd ...  register a timeout monitor
    TargetHandle_t sys = NULL;
    targetService().getTopLevelTarget(sys);

    HbSettings hbSettings = sys->getAttr<ATTR_HB_SETTINGS>();

    uint64_t mbaTO =
        hbSettings.traceContinuous ? MBA_TIMEOUT_LONG : MBA_TIMEOUT;

    mutex_lock(&iv_mutex);

    uint64_t monitorId = CommandMonitor::INVALID_MONITOR_ID;
    i_wfp.timeoutCnt = 0; // reset for new work item
    workItem = *i_wfp.workItem;
    restart = i_wfp.restartCommand;
    targetMba = getTarget(i_wfp);
    cmd = static_cast<mss_MaintCmd *>(i_wfp.data);

    mutex_unlock(&iv_mutex);


    do
    {
        fapi::Target fapiMba(TARGET_TYPE_MBA_CHIPLET, targetMba);
        ReturnCode fapirc;

        // We will always do ce setup though CE calculation
        // is only done during MNFG. This will give use better ffdc.
        err = ceErrorSetup( targetMba );
        if( NULL != err)
        {
            MDIA_FAST("sm: ceErrorSetup failed for mba. HUID:0x%08X",
                            get_huid(targetMba));
            break;
        }

        if( TARGETING::MNFG_FLAG_IPL_MEMORY_CE_CHECKING
            & iv_globals.mfgPolicy )
        {
            // For MNFG mode, check CE also
            stopCondition |= mss_MaintCmd::STOP_ON_HARD_NCE_ETE;
        }
        // setup the address range.
        // assume the full range for now

        fapirc = mss_get_address_range(
                fapiMba,
                MSS_ALL_RANKS,
                startAddr,
                endAddr);
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_FAST("sm: get_address_range failed");
            break;
        }

        if(restart)
        {
            // bump the starting address if we are restarting
            // a command

            mss_IncrementAddress incrementCmd(fapiMba);

            MDIA_FAST("sm: increment address on: %x",
                    get_huid(targetMba));

            fapirc = incrementCmd.setupAndExecuteCmd();

            err = fapiRcToErrl(fapirc);

            if(err)
            {
                MDIA_FAST("sm: setupAndExecuteCmd failed");
                break;
            }

            // read the address out so it can be passed
            // to the command being restarted

            uint64_t address;
            size_t size = sizeof(address);

            err = deviceRead(
                    targetMba,
                    &address,
                    size,
                    DEVICE_SCOM_ADDRESS(MBA01_MBMACAQ));

            if(err)
            {
                MDIA_FAST("sm: reading address failed");

                break;
            }

            startAddr.setDoubleWord(0, address);
            startAddr.insert(static_cast<uint32_t>(0), 40, 24); // addr is 0:39

            switch(workItem)
            {
                case START_RANDOM_PATTERN:
                    static_cast<mss_SuperFastRandomInit *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                case START_SCRUB:
                    static_cast<mss_SuperFastRead *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                case START_PATTERN_0:
                case START_PATTERN_1:
                case START_PATTERN_2:
                case START_PATTERN_3:
                case START_PATTERN_4:
                case START_PATTERN_5:
                case START_PATTERN_6:
                case START_PATTERN_7:
                    static_cast<mss_SuperFastInit *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                default:
                    MDIA_ERR("sm: unrecognized maint command type %d:",
                            workItem);
                    break;
            }
        }

        else
        {
            // new command...use the full range

            switch(workItem)
            {
                case START_RANDOM_PATTERN:
                    cmd = new mss_SuperFastRandomInit(
                            fapiMba,
                            startAddr,
                            endAddr,
                            mss_MaintCmd::PATTERN_RANDOM,
                            stopCondition,
                            false);

                    MDIA_FAST("sm: random init %p on: %x", cmd,
                            get_huid(targetMba));
                    break;

                case START_SCRUB:
                    cmd = new mss_SuperFastRead(
                            fapiMba,
                            startAddr,
                            endAddr,
                            stopCondition,
                            false);

                    MDIA_FAST("sm: scrub %p on: %x", cmd,
                            get_huid(targetMba));
                    break;
                case START_PATTERN_0:
                case START_PATTERN_1:
                case START_PATTERN_2:
                case START_PATTERN_3:
                case START_PATTERN_4:
                case START_PATTERN_5:
                case START_PATTERN_6:
                case START_PATTERN_7:

                    cmd = new mss_SuperFastInit(
                            fapiMba,
                            startAddr,
                            endAddr,
                            static_cast<mss_MaintCmd::PatternIndex>(workItem),
                            stopCondition,
                            false);

                    MDIA_FAST("sm: init %p on: %x", cmd,
                            get_huid(targetMba));
                    break;

                default:
                    break;
            }

            if(!cmd)
            {
                MDIA_ERR("unrecognized maint command type %d on: %x",
                        workItem,
                        get_huid(targetMba));
                break;
            }
        }

        mutex_lock(&iv_mutex);

        i_wfp.data = cmd;

        mutex_unlock(&iv_mutex);

        // Command and address configured.
        // Invoke the command.
        fapirc = cmd->setupAndExecuteCmd();
        err = fapiRcToErrl(fapirc);

        // Start a timeout monitor
        mutex_lock(&iv_mutex);

        monitorId = getMonitor().addMonitor(mbaTO);
        i_wfp.timer = monitorId;

        mutex_unlock(&iv_mutex);

        if(err)
        {
            MDIA_FAST("sm: setupAndExecuteCmd %p failed", cmd);
            break;
        }

    } while(0);

    if(err)
    {
        mutex_lock(&iv_mutex);

        MDIA_FAST("sm: Running Maint Cmd failed");

        getMonitor().removeMonitor(monitorId);

        i_wfp.data = NULL;

        mutex_unlock(&iv_mutex);
    }

    if(err && cmd)
    {
        delete cmd;
    }
*/

    return err;
}

CommandMonitor & StateMachine::getMonitor()
{
    if(!iv_monitor)
    {
        MDIA_FAST("Starting monitor...");

        iv_monitor = new CommandMonitor();
        iv_monitor->start(*this);
    }

    return *iv_monitor;
}

bool StateMachine::processMaintCommandEvent(const MaintCommandEvent & i_event)
{

    enum
    {
        CLEANUP_CMD = 0x8,
        DELETE_CMD = 0x4,
        STOP_CMD = 0x2,
        START_NEXT_CMD = 0x1,
        DISPATCHED = 0x80,
    };

    uint64_t flags = 0;

/* TODO RTC 145132
    mss_MaintCmd * cmd = NULL;
    ReturnCode fapirc;
    errlHndl_t err = NULL;

    mutex_lock(&iv_mutex);

    WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();

    for(; wit != iv_workFlowProperties.end(); ++wit)
    {
        if(getTarget(**wit) == i_event.target)
        {
            break;
        }
    }

    if(wit == iv_workFlowProperties.end())
    {
        MDIA_ERR("sm: did not find target: %x",
                get_huid(i_event.target));
    }

    // if a command finishes (just) after the
    // timeout and we haven't had a chance to stop the
    // command yet, it may end up here.  Ignore it
    // and let the timeout thread do its job.
    // Also ignore when it is in failed state.

    else if(((**wit).status != COMMAND_TIMED_OUT) &&
            ((**wit).status != FAILED))
    {
        WorkFlowProperties & wfp = **wit;

        // always unregister any existing maint cmd monitor

        getMonitor().removeMonitor(wfp.timer);

        cmd = static_cast<mss_MaintCmd *>(wfp.data);

        MDIA_FAST("sm: processing event for: %x, cmd: %p, type: %x",
                get_huid(getTarget(wfp)), cmd, i_event.type);

        MaintCommandEventType eventType = i_event.type;

        // If shutdown is requested and we're not in MNFG mode
        // skip testing on all MBAs
        if(( INITSERVICE::isShutdownRequested() ) &&
           (( COMMAND_COMPLETE == eventType ) ||
            ( COMMAND_STOPPED  == eventType )) &&
           ! (( MNFG_FLAG_ENABLE_EXHAUSTIVE_PATTERN_TEST
                & iv_globals.mfgPolicy) ||
              ( MNFG_FLAG_ENABLE_STANDARD_PATTERN_TEST
                & iv_globals.mfgPolicy) ||
              ( MNFG_FLAG_ENABLE_MINIMUM_PATTERN_TEST
                & iv_globals.mfgPolicy)))
        {
            MDIA_FAST("sm: shutdown requested, overrding event "
                      "for: %x, cmd: %p, type: %x, globals: %x",
                get_huid(getTarget(wfp)), cmd,
                i_event.type, iv_globals.mfgPolicy);

            eventType = SKIP_MBA;
        }

#ifdef CONFIG_BMC_IPMI
        // Reset the watchdog timer after running each pattern
        errlHndl_t err_ipmi = IPMIWATCHDOG::resetWatchDogTimer();

        if(err_ipmi)
        {
            MDIA_FAST("sm executeWorkitem: IPMI reset watchdog failed");
            err_ipmi->collectTrace("MDIA_FAST",1024);
            errlCommit(err_ipmi, MDIA_COMP_ID );

        }
#endif

        switch(eventType)
            case COMMAND_COMPLETE:
            {
                // command stopped or complete at end of last rank

                wfp.restartCommand = false;

                // move to the next command

                ++wfp.workItem;


                // done with this maint command

                flags = DELETE_CMD | START_NEXT_CMD;
                wfp.data = NULL;

                break;
            case COMMAND_STOPPED:

                // command stopped at end of some other rank

                flags = START_NEXT_CMD;
                wfp.restartCommand = true;

                break;

            case SKIP_MBA:

                // stop testing on this mba

                wfp.status = COMPLETE;

                // done with this maint command
                flags = DELETE_CMD | STOP_CMD | START_NEXT_CMD;
                wfp.data = NULL;


                break;

            case RESET_TIMER:
                flags = CLEANUP_CMD;
                break;

            default:
                // this shouldn't happen, but if it does
                // free up the memory
                flags = DELETE_CMD;
                wfp.data = NULL;
                break;
        }

        if(cmd && (flags & STOP_CMD))
        {
            MDIA_FAST("sm: stopping command: %p", cmd);

            fapirc = cmd->stopCmd();
            err = fapiRcToErrl(fapirc);

            if(err)
            {
                MDIA_ERR("sm: mss_MaintCmd::stopCmd failed");
                errlCommit(err, MDIA_COMP_ID);
            }
        }

        if(cmd && (flags & CLEANUP_CMD))
        {
            // restore any init settings that
            // may have been changed by the command

            fapirc = cmd->cleanupCmd();
            err = fapiRcToErrl(fapirc);
            if(err)
            {
                MDIA_ERR("sm: mss_MaintCmd::cleanupCmd failed");
                errlCommit(err, MDIA_COMP_ID);
            }
        }

        // schedule the next work item
        if((flags & START_NEXT_CMD) && !iv_shutdown)
        {
            if(scheduleWorkItem(wfp))
            {
                flags |= DISPATCHED;
            }
        }
    }

    mutex_unlock(&iv_mutex);

    if(cmd && (flags & DELETE_CMD))
    {
        delete cmd;
    }
*/

    return (flags & DISPATCHED);
}

bool StateMachine::allWorkFlowsComplete()
{
    // check to see if all workFlows are complete

    bool allWorkFlowsComplete = true;

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((*wit)->status == IN_PROGRESS)
        {
            allWorkFlowsComplete = false;
            break;
        }
    }

    return allWorkFlowsComplete;
}

void StateMachine::reset()
{
    mutex_lock(&iv_mutex);

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((**wit).log)
        {
            delete (**wit).log;
        }

        delete *wit;
    }

    iv_workFlowProperties.clear();

    mutex_unlock(&iv_mutex);
}

void StateMachine::shutdown()
{
    mutex_lock(&iv_mutex);

    Util::ThreadPool<WorkItem> * tp = iv_tp;
    CommandMonitor * monitor = iv_monitor;

    iv_tp = 0;
    iv_monitor = 0;

    iv_shutdown = true;

    mutex_unlock(&iv_mutex);

    MDIA_FAST("sm: shutting down...");

    if(tp)
    {
        MDIA_FAST("Stopping threadPool...");
        tp->shutdown();
        delete tp;
    }

    if(monitor)
    {
        MDIA_FAST("Stopping monitor...");
        monitor->shutdown();
        delete monitor;
    }

    MDIA_FAST("sm: ...shutdown complete");
}

StateMachine::~StateMachine()
{
    shutdown();

    sync_cond_destroy(&iv_cond);
    mutex_destroy(&iv_mutex);
}

StateMachine::StateMachine() : iv_monitor(0), iv_done(true), iv_shutdown(false),
    iv_tp(0), iv_globals()
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);
}

void StateMachine::setGlobals(Globals & i_globals)
{
    mutex_lock(&iv_mutex);

    iv_globals = i_globals;

    mutex_unlock(&iv_mutex);
}

}
