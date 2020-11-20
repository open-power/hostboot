/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_rsvdtracebufservice.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#include "rt_rsvdtracebufservice.H"
#include <trace/compdesc.H>         // ComponentDes
#include <trace/entry.H>            // Entry
#include <util/runtime/util_rt.H>   // hb_get_rt_rsvd_mem
#include <errl/errlmanager.H>       // errlCommit
#include <runtime/interface.h>      // g_hostInterfaces, postInitCalls_t
#include <runtime/runtime_reasoncodes.H>  // RUNTIME::MOD_INIT_RT_RES_MEM_TRACE_BUF

namespace TRACE
{

/**
 *  ctor
 */
RsvdTraceBufService::RsvdTraceBufService( )
: iv_errl(nullptr)
{
}

/**
 *  init
 */
void RsvdTraceBufService::init()
{
    g_hostInterfaces->puts( " >> RsvdTraceBufService::init\n");

    // Get the size and location of the reserved trace buffer section
    uint64_t l_bufferSize(0);
    uint64_t l_reservedMemory = hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_TRACEBUF,
                                            0, l_bufferSize);

    // The first part of buffer is where the head of a link list will reside.
    // It needs to reside here so if we go down in flames, we can pick
    // up where we left off
    if ( (l_reservedMemory != 0) && (l_bufferSize > sizeof(uintptr_t)) )
    {
        // Get a pointer to where the head of the data is
        uintptr_t *l_addressToHead =
                                reinterpret_cast<uintptr_t *>(l_reservedMemory);

        // The RsvdTraceBuffer is only concerned with the part of the buffer
        // that it will maintain.  Therefore, send the buffer size minus the
        // size of an uintptr_t which is set aside for the first entry of the
        // buffer.  Then add the size of an uintptr_t to the l_reservedMemory
        // (the beginning address of buffer) to get the beginning address of
        // which the RsvdTraceBuffer will be responsible for.
        iv_rsvdTraceBuffer.init(l_bufferSize - sizeof(uintptr_t),
                                l_reservedMemory + sizeof(uintptr_t),
                                l_addressToHead);

        //----------
        // There is a problem with saving pointers in the trace entry
        //   Removing this temporarily until a solution is found
        //----------
        // If the data is not NULL, then retrieve crashed data
        // I want NULL in this case, not nullptr; *l_addressToHead is an int.
        // If I use nullptr; compiler complains
        if (*l_addressToHead != NULL)
        {
            retrieveDataFromLastCrash();
        }

        // After gathering trace info from previous crash, clear buffer data
        iv_rsvdTraceBuffer.clearBuffer();
    }

    g_hostInterfaces->puts(" << RsvdTraceBufService::init\n");
}

/**
 *  retrieveDataFromLastCrash
 */
void RsvdTraceBufService::retrieveDataFromLastCrash()
{
    g_hostInterfaces->puts(
                        " >> RsvdTraceBufService::retrieveDataFromLastCrash\n");

    /*@
     * @errortype    ERRL_SEV_INFORMATIONAL
     * @moduleid     RUNTIME::MOD_INIT_RT_RES_MEM_TRACE_BUF
     * @reasoncode   RUNTIME::RC_RT_RES_TRACE_BUF_DUMPED
     * @userdata1    unused
     * @userdata2    unused
     * @devdesc      Copy of trace buffer from previous HBRT run
     * @custdesc     Informational log containing historic data
     */
    iv_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                     RUNTIME::MOD_INIT_RT_RES_MEM_TRACE_BUF,
                                     RUNTIME::RC_RT_RES_TRACE_BUF_DUMPED,
                                     0,0,true);

    // Note: Set the iv_rsvdTraceBuffer before calling collectTrace()
    // Need to keep trace small enough so it doesn't get dropped from log
    iv_errl->collectTrace("RSVD_MEM_TRACE", 3*KILOBYTE);

    // Can not commit the errl until the ErrlManager gets initialized.
    // Committing will be done in commitRsvdMemTraceErrl() after
    // ErrlManager gets initialized
    g_hostInterfaces->puts(
                        " << RsvdTraceBufService::retrieveDataFromLastCrash\n");
}


/**
 *  commitRsvdMemTraceErrl
 */
bool RsvdTraceBufService::commitRsvdMemTraceErrl()
{
    g_hostInterfaces->puts(" >> RsvdTraceBufService::commitRsvdMemTraceErrl\n");

    bool l_errlCommitted = false;

    // Commit the iv_errl, if valid
    if (iv_errl)
    {
        errlCommit(iv_errl, RUNTIME_COMP_ID);
        l_errlCommitted = true;
    }

    g_hostInterfaces->puts(" << RsvdTraceBufService::commitRsvdMemTraceErrl\n");

    return l_errlCommitted;
}

/**
 *  writeEntry
 */
void RsvdTraceBufService::writeEntry(ComponentDesc* i_componentDesc,
                                     char*          i_data,
                                     uint32_t       i_dataSize)
{
    // Sanity check, make sure user passed in legit data
    if ((nullptr != i_componentDesc) && (nullptr != i_data) && (i_dataSize > 0))
    {
        // Add an entry into the reserved trace buffer
        Entry* l_entry = iv_rsvdTraceBuffer.insertEntry(i_dataSize);
        if (nullptr != l_entry)
        {
            // Assign the component description and entry size.
            l_entry->comp = i_componentDesc;
            l_entry->size = i_dataSize;

            //copy the contents in to the entry's data section
            memcpy(&l_entry->data[0], i_data, i_dataSize);

            // "Commit" entry to buffer.
            l_entry->committed = 1;
        }
    }
}

/**
 *  getBuffer
 */
uint32_t RsvdTraceBufService::getBuffer(void* o_data, uint32_t i_dataSize) const
{
    return iv_rsvdTraceBuffer.getTrace(o_data, i_dataSize);
}

}  //end of namespace

/**
 *  initRsvdTraceBufService
 */
void initRsvdTraceBufService()
{
    g_hostInterfaces->puts(" >> RsvdTraceBufService::initRsvdTraceBufService\n");

    //get the reserved memory and initialize
    Singleton<TRACE::RsvdTraceBufService>::instance().init();

    g_hostInterfaces->puts(" << RsvdTraceBufService::initRsvdTraceBufService\n");

}

/**
 *  commitRsvdTraceBufErrl
 */
void commitRsvdTraceBufErrl()
{
    g_hostInterfaces->puts(" >> RsvdTraceBufService::commitRsvdTraceBufErrl\n");

    // Commit the errl with traces from previous boot, if buffer is valid
    Singleton<TRACE::RsvdTraceBufService>::instance().commitRsvdMemTraceErrl();

    g_hostInterfaces->puts(" << RsvdTraceBufService::commitRsvdTraceBufErrl\n");
}

struct register_initRsvdTraceBufService
{
    register_initRsvdTraceBufService()
    {
        // Register interface for Host to call
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callInitRsvdTraceBufService = &initRsvdTraceBufService;
        rt_post->callCommitRsvdTraceBufErrl = &commitRsvdTraceBufErrl;
    }
};


//create a global object to force initialize the Service & RsvdTraceBufService objects
register_initRsvdTraceBufService g_register_initRsvdTraceBufService;

