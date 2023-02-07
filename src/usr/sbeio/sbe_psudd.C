/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psudd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
 * @file sbe_psudd.C
 * @brief SBE PSU device driver
 */

#include <sys/time.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <errl/errlreasoncodes.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <arch/magic.H>
#include <kernel/pagemgr.H>
#include <sbeio/sbeioif.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_extract_sbe_rc.H>
#include <errl/errludlogregister.H>
#include <sbeio/sbe_retry_handler.H>
#include <initservice/initserviceif.H>
#include <intr/interrupt.H>
#include <errno.h>
#include <sys/time.h>
#include <errl/errludprintk.H>
#include <vfs/vfs.H> // module_is_loaded
#include <util/misc.H>
#include <sbe/sbeif.H>
#include <isteps/istep_reasoncodes.H>

trace_desc_t* g_trac_sbeio;
TRAC_INIT(&g_trac_sbeio, SBEIO_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);

// used to uniquely identify the SBE PSU message queue
const char* SBE_PSU_MSG_Q = "sbepsuq";

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"psudd: " printf_string,##args)


using namespace ERRORLOG;

namespace SBEIO
{

sbeAllocationHandle_t sbeMalloc(const size_t i_bytes)
{
    // The buffer must be a multiple of SBE_ALIGNMENT_SIZE_IN_BYTES
    // bytes in size, and it must be aligned to a
    // SBE_ALIGNMENT_SIZE_IN_BYTES byte boundary.
    const size_t l_totalAlignedSize =
      (ALIGN_X(i_bytes, SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES)
       + (SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES - 1));

    // Create buffer with enough size to be properly aligned
    void* const l_sbeBuffer = malloc(l_totalAlignedSize);

    // Align the buffer
    const uint64_t l_sbeBufferAligned =
      ALIGN_X(reinterpret_cast<uint64_t>(l_sbeBuffer),
              SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES);

    // Return a handle so we can free() the buffer later
    return {
        l_sbeBuffer,
        l_sbeBufferAligned,
        reinterpret_cast<void*>(l_sbeBufferAligned),
        mm_virt_to_phys(reinterpret_cast<void*>(l_sbeBufferAligned))
    };
}

sbeAllocationHandle_t sbeMalloc(const size_t i_bytes, void*& o_allocation)
{
    sbeAllocationHandle_t l_hndl = sbeMalloc(i_bytes);
    o_allocation = reinterpret_cast<void*>(l_hndl.dataPtr);
    return l_hndl;
}

void sbeFree(sbeAllocationHandle_t& i_handle)
{
    free(i_handle.bufPtr);
    i_handle.bufPtr = nullptr;
    i_handle.aligned = 0;
    i_handle.physAddr = 0;
}

void * SbePsu::msg_handler(void *unused)
{
    Singleton<SbePsu>::instance().msgHandler();
    return nullptr;
}

/**
 * @brief  Constructor
 **/
SbePsu::SbePsu()
    :
    iv_earlyErrorOccurred(false),
    iv_psuResponse(nullptr),
    iv_responseReady(false),
    iv_shutdownInProgress(false)
{
    errlHndl_t l_err = nullptr;
    size_t rc = 0;

    //Create message queue
    iv_msgQ = msg_q_create();

    //Register message queue with unique identifier
    rc = msg_q_register(iv_msgQ, SBE_PSU_MSG_Q);

    if(rc)   // could not register msgQ with kernel
    {
        SBE_TRACF(ERR_MRK "SbePsu() Could not register"
                  "message queue with kernel");

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        SBEIO_PSU
         * @reasoncode      SBEIO_RC_KERNEL_REG_FAILED
         * @userdata1       rc from msq_q_register
         * @devdesc         Could not register mailbox message queue
         */
        l_err = new ErrlEntry
            (
                ERRL_SEV_CRITICAL_SYS_TERM,
                SBEIO_PSU,
                SBEIO_RC_KERNEL_REG_FAILED,    //  reason Code
                rc,                        // rc from msg_send
                0,
                ErrlEntry::ADD_SW_CALLOUT
                );
    }

    if (!l_err)
    {

        // create task before registering the msgQ so any waiting interrupts get
        // handled as soon as the msgQ is registered with the interrupt service
        // provider
        task_create(SbePsu::msg_handler, NULL);

        //Register message queue with INTRP for Interrupts
        //   of type LSI_PSU. The INTRP will route messages
        //   to this queue when interrupts of that type are
        //   detected
        l_err = INTR::registerMsgQ(iv_msgQ,
                                   MSG_INTR,
                                   INTR::ISN_PSU);
    }

    if (l_err)
    {
        SBE_TRACF(ERR_MRK"Error in SbePsu Constructor");
        l_err->collectTrace(INTR_COMP_NAME, 256);
        // save off reason code before committing
        auto l_reason = l_err->reasonCode();
        errlCommit(l_err, SBEIO_COMP_ID);
        INITSERVICE::doShutdown(l_reason);
    }
}

/**
 * @brief  Destructor
 **/
SbePsu::~SbePsu()
{
    INTR::unRegisterMsgQ(INTR::ISN_PSU);
    msg_q_destroy(iv_msgQ);

    std::map<TARGETING::Target *, void *>::iterator l_iter;
    for(l_iter = iv_ffdcPackageBuffer.begin();
        l_iter != iv_ffdcPackageBuffer.end(); l_iter++)
    {
        if(l_iter->second != NULL)
        {
            freePage(l_iter->second);
            l_iter->second = nullptr;
        }
    }

    commonDestructor();
}

void SbePsu::msgHandler()
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    errlHndl_t l_err = nullptr;

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        //Message should never be nullptr
        assert(msg != nullptr,"SbePsu::msgHandle: msg is nullptr");

        switch(msg->type)
        {
        case MSG_INTR:
        {
            if (msg->data[0] == INTR::SHUT_DOWN)
            {
                iv_shutdownInProgress = true;
                SBE_TRACF("SbePsu::msgHandler Handle Shutdown");
                //respond so INTRP can continue
                // with shutdown procedure
                msg_respond(iv_msgQ,msg);
            }
            else
            {
                //Handle the interrupt message -- pass the PIR of the
                // proc causing the interrupt
                SBE_TRACF("SbePsu::msgHandler got MSG_INTR message");
                l_err = handleInterrupt(msg->data[1]);

                if (l_err)
                {
                    SBE_TRACF("SbePsu::msgHandler handleInterrupt returned an error");
                    l_err->collectTrace(SBEIO_COMP_NAME);
                    l_err->collectTrace(INTR_COMP_NAME, 256);
                    errlCommit(l_err, SBEIO_COMP_ID);
                }

                // Respond to the interrupt handler regardless of error
                INTR::sendEOI(iv_msgQ,msg);
            }
        }
        break;
        default:
            msg->data[1] = -EINVAL;
            msg_respond(iv_msgQ, msg);
        }
    }

}

errlHndl_t SbePsu::forceSbeUpdate(Target* const i_target)
{
    if (TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_SBE_UPDATE_DISABLE>())
    {
        // In this case we expect the caller to create an error and
        // kill the boot..
        SBE_TRACF(INFO_MRK"forceSbeUpdate: The SBE on 0x%08x needs to be updated after an unsupported SBE PSU operation, but SBE updates have been disabled via ATTR_SBE_UPDATE_DISABLE",
                  get_huid(i_target));
        return nullptr;
    }

    errlHndl_t errl = SBE::updateProcessorSbeSeeproms();

    if (errl)
    {
        SBE_TRACF(ERR_MRK"forceSbeUpdate: updateProcessorSbeSeeproms returned "
                  "an error for processor 0x%08x: "
                  TRACE_ERR_FMT,
                  get_huid(i_target),
                  TRACE_ERR_ARGS(errl));
        errl->collectTrace(SBEIO_COMP_NAME);
    }
    else
    {
        SBE_TRACF(ERR_MRK"forceSbeUpdate: updateProcessorSbeSeeproms returned "
                  "without an error on processor 0x%08x",
                  get_huid(i_target));

        /*@
         * @errortype
         * @moduleid     SBEIO_PSU
         * @reasoncode   ISTEP::RC_SBE_UPDATE_UNEXPECTEDLY_FAILED
         * @devdesc      Failed to update the SBE after an unsupported PSU operation error
         * @custdesc     SBE update failed
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             SBEIO_PSU,
                             ISTEP::RC_SBE_UPDATE_UNEXPECTEDLY_FAILED,
                             0,
                             0,
                             ErrlEntry::ADD_SW_CALLOUT);

        errl->addHwCallout(i_target,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL);

        errl->collectTrace(TARG_COMP_NAME);
        errl->collectTrace(SBE_COMP_NAME);
        errl->collectTrace(ISTEP_COMP_NAME);
        errl->collectTrace(SBEIO_COMP_NAME);
    }

    return errl;
}

errlHndl_t SbePsu::handleInterrupt(PIR_t i_pir)
{
    errlHndl_t errl = nullptr;
    SBE_TRACD(ENTER_MRK "SbePsu::handleInterrupt");

    do
    {
        uint64_t l_intrTopoID = PIR_t::topologyIdFromPir(i_pir.word);
        // Find the chip that presented the interrupt
        TARGETING::Target* l_intrChip = nullptr;
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TARGETING::TYPE_PROC, false);
        for (auto & l_chip: l_procTargetList)
        {
            auto l_topoId =
                (l_chip)->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();
            if(l_topoId == l_intrTopoID)
            {
                l_intrChip = (l_chip);
                break;
            }
        }
        assert(l_intrChip != nullptr,
                   "SbePsu::handleInterrupt: l_intrChip is nullptr");

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        // In order to test the runtime PSU operations, we need to
        //  short-circuit the interrupt handling of the IPL code
        //  that is still resident.
        if( iv_ignoreInterrupts )
        {
            SBE_TRACF("SbePsu::handleInterrupt> Ignoring interrupt from %.8X caused by HBRT testcases",
                      TARGETING::get_huid(l_intrChip));
            break;
        }
#endif //#idef CONFIG_COMPILE_CXXTEST_HOOKS

        errl = handleMessage(l_intrChip);
        if( errl )
        {
            break;
        }

        //Clear the rest of the PSU Scom Reg Interrupt Status register
        //  This clears the PSU interrupt condition to avoid any other
        //  spurious interrupts
        uint64_t l_data = HOST_CLEAR_OTHER_BITS;
        errl = writeScom(l_intrChip,PSU_HOST_DOORBELL_REG_AND,&l_data);
        if (errl)
        {
            break;
        }

    } while (0);

    SBE_TRACD(EXIT_MRK "SbePsu::handleInterrupt");

    return errl;
}

void* SbePsu::allocatePage( size_t i_pageCount )
{
    return PageManager::allocatePage(i_pageCount,true);
}

void SbePsu::freePage(void*  i_page)
{
    PageManager::freePage(i_page);
}

/**
 * @brief allocates buffer and sets ffdc address for the proc
 */

errlHndl_t SbePsu::allocateFFDCBuffer(TARGETING::Target * i_target)
{
    static mutex_t l_alloMux = MUTEX_INITIALIZER;

    uint32_t l_bufSize = getSbeFFDCBufferSize();
    errlHndl_t errl = NULL;

    uint32_t l_huid = TARGETING::get_huid(i_target);

    // Check to see if the buffer has been allocated before allocating
    // and setting FFDC address
    mutex_lock(&l_alloMux);

    if(iv_ffdcPackageBuffer.find(i_target) == iv_ffdcPackageBuffer.end())
    {
        sbeAllocationHandle_t l_ffdcHandle = sbeMalloc( l_bufSize );
        memset(l_ffdcHandle.dataPtr, 0x00, l_bufSize);

        errl = sendSetFFDCAddr(l_bufSize,
                          0,
                          l_ffdcHandle.physAddr,
                          0,
                          i_target);

        //Make the corresponding platform attribute match what we sent to SBE
        //Things will work without setting these attributes, just to reduce
        //confusion during debug in the future we will set them here.
        i_target->setAttr<TARGETING::ATTR_SBE_FFDC_ADDR>(l_ffdcHandle.physAddr);
        i_target->setAttr<TARGETING::ATTR_SBE_COMM_ADDR>(0);

        if(errl)
        {
            sbeFree(l_ffdcHandle);
            SBE_TRACF(ERR_MRK"Error setting FFDC address for "
                      "proc huid=0x%08lx", l_huid);
        }
        else
        {
            iv_ffdcPackageBuffer.insert(std::pair<TARGETING::Target *, void *>
                          (i_target, l_ffdcHandle.dataPtr));
            SBE_TRACD("Allocated FFDC buffer for proc huid=0x%08lx", l_huid);
        }
    }

    mutex_unlock(&l_alloMux);
    return errl;
}


#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
void SbePsu::ignoreInterrupts(bool i_ignore)
{
    SBE_TRACF("CXXTEST setting ignoreInterrupts=%d, look for a match to make sure in sync", i_ignore);
    iv_ignoreInterrupts = i_ignore;

    if( i_ignore )
    {
        INTR::unRegisterMsgQ(INTR::ISN_PSU);
    }
    else
    {
        //Re-rRegister message queue with INTRP for Interrupts.
        errlHndl_t l_err = INTR::registerMsgQ(iv_msgQ,
                                              MSG_INTR,
                                              INTR::ISN_PSU);
        if( l_err )
        {
            SBE_TRACF("CXXTEST Error restoring interrupt handler");
            l_err->collectTrace(SBEIO_COMP_NAME);
            l_err->collectTrace(INTR_COMP_NAME, 256);
            errlCommit(l_err, SBEIO_COMP_ID);
        }
    }
}
#endif //#ifdef CONFIG_COMPILE_CXXTEST_HOOKS

} //end of namespace SBEIO
