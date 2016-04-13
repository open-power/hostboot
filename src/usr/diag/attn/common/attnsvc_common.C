/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnsvc_common.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
 * @file attnsvc_common.C
 *
 * @brief HBATTN common service class function definitions.
 */

#include <errl/errlmanager.H>
#include "common/attnsvc_common.H"
#include "common/attntrace.H"
#include "common/attnprd.H"
#include "common/attnproc.H"
#include "common/attnmem.H"
#include "common/attntarget.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{
enum
{
    // interrupts to host bridge -IPOLL MASK
    ROUTE_TO_HOST      = 0x0400000000000000ull
};



/**
 * @brief calculated mask cache for ipoll
 */
class HostMask
{
    uint64_t iv_hostMask;
    uint64_t iv_nonHostMask;

    HostMask() : iv_hostMask(0), iv_nonHostMask(0)
    {
        uint64_t  l_hostMask;

        // Get attentions only reported on proc/host side
        IPOLL::getCheckbits(UNIT_CS,   l_hostMask);
        IPOLL::getCheckbits(HOST_ATTN, iv_hostMask);
        iv_hostMask |= l_hostMask;

        IPOLL::forEach(~0, &iv_nonHostMask, &getIpollMask);

        iv_nonHostMask = iv_nonHostMask & ~iv_hostMask;
    }

    static void getIpollMask(uint64_t i_type, void * i_data)
    {
        uint64_t & mask = *static_cast<uint64_t *>(i_data);

        uint64_t tmp = 0;
        IPOLL::getCheckbits(i_type, tmp);

        mask |= tmp;
    }

    static HostMask & get()
    {
        static HostMask hm;

        return hm;
    }

    public:

    static uint64_t host()
    {
        return get().iv_hostMask;
    }

    static uint64_t nonHost()
    {
        return get().iv_nonHostMask;
    }
};

errlHndl_t ServiceCommon::configureInterrupts(
        ConfigureMode i_mode)
{
    errlHndl_t err = NULL;
    TargetHandleList  procs;
    getTargetService().getAllChips(procs, TYPE_PROC);
    TargetHandleList::iterator it = procs.begin();


    while(it != procs.end())
    {
        // enable/disable MCSes
        //@TODO: RTC:150944  Do we need to enable/disable MCS ? Doubt it
        //       Seems to be related strictly to that GPIO P8 workaround


        #ifndef __HOSTBOOT_RUNTIME
        uint64_t  mask = 0;
        // enable attentions in ipoll mask
        mask = HostMask::nonHost();
        mask |= HostMask::host();

        // We never messed with FSP mask bits in P8, so
        // not doing it on P9 either.
        mask |= ATTN::ROUTE_TO_HOST;

        // this doesn't have an and/or reg for some reason...
        err = modifyScom(*it,
                         IPOLL::address,
                         i_mode == UP ? ~mask : mask,
                         i_mode == UP ? SCOM_AND : SCOM_OR);

        if(err)
        {
            break;
        }

        #endif // NOT  __HOSTBOOT_RUNTIME

        ++it;
    }

    return err;
}

void ServiceCommon::processAttnPreAck(const TargetHandle_t i_proc)
{
    uint64_t hostMask = HostMask::host();
    uint64_t nonHostMask = HostMask::nonHost();
    uint64_t data = 0;

    // do the minimum that is required
    // for sending EOI without getting
    // another interrupt.  for host attentions
    // this is clearing the gpio interrupt
    // type status register
    // and for xstp,rec,spcl this is
    // masking the appropriate bit in
    // ipoll mask

    // read the ipoll status register
    // to determine the interrupt was
    // caused by host attn or something
    // else (xstp,rec,spcl)

    errlHndl_t err = getScom(i_proc, IPOLL_STATUS_REG, data);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);

        // assume everything is on

        data = hostMask | nonHostMask;
    }

    if(data & nonHostMask)
    {
        // mask local proc xstp,rec and/or special attns if on.

        // the other thread might be trying to unmask
        // on the same target.  The mutex ensures
        // neither thread corrupts the register.

        mutex_lock(&iv_mutex);

        err = modifyScom(i_proc, IPOLL::address, data & nonHostMask, SCOM_OR);

        mutex_unlock(&iv_mutex);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }
    }
}

void ServiceCommon::processAttentions(const TargetHandleList & i_procs)
{
    errlHndl_t err = NULL;
    AttentionList attentions;

    MemOps & memOps = getMemOps();
    ProcOps & procOps = getProcOps();

    do {

        attentions.clear();

        // enumerate the highest priority pending attention
        // on every chip and then give the entire set to PRD

        TargetHandleList::const_iterator pit = i_procs.end();

        while(pit-- != i_procs.begin())
        {
            // enumerate proc local attentions (xstp,spcl,rec).
            err = procOps.resolveIpoll(*pit, attentions);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }

            // enumerate host attentions and convert
            // to centaur targets  (NOOP for now on P9)
            err = memOps.resolve(*pit, attentions);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }
        }

        err = getPrdWrapper().callPrd(attentions);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }

        // unmask proc local attentions
        // (xstp,rec,special) in ipoll mask

        // any pending attentions will be found
        // on the next pass

        pit = i_procs.end();

        while(pit-- != i_procs.begin())
        {
            mutex_lock(&iv_mutex);

            // the other thread might be trying to mask
            // on the same target.  The mutex ensures
            // neither thread corrupts the register.

            err = modifyScom(
                    *pit,
                    IPOLL::address,
                    ~HostMask::nonHost(),
                    SCOM_AND);

            mutex_unlock(&iv_mutex);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }
        }

        // if on a given Centaur with a pending attention
        // on an MBA, an attention comes on in the other MBA
        // we don't get an interrupt for that.  So make another
        // pass and check for that.

    } while(!attentions.empty());

}

ServiceCommon::ServiceCommon()
{
    mutex_init(&iv_mutex);
}

ServiceCommon::~ServiceCommon()
{
    mutex_destroy(&iv_mutex);
}

errlHndl_t ServiceCommon::handleAttentions(const TargetHandle_t i_proc)
{
    errlHndl_t err = NULL;
    AttentionList attentions;

    MemOps & memOps = getMemOps();
    ProcOps & procOps = getProcOps();

    do {

       attentions.clear();

       // query the proc resolver for active attentions
       err = procOps.resolve(i_proc, 0, attentions);

       if(err)
       {
           ATTN_ERR("procOps.resolve() returned error.HUID:0X%08X ",
                     get_huid( i_proc ));
           break;
       }

       // query the mem resolver for active attentions

       err = memOps.resolve(i_proc, attentions);

       if(err)
       {
           ATTN_ERR("memOps.resolve() returned error.HUID:0X%08X ",
                     get_huid( i_proc ));
           break;
       }

       ATTN_TRACE("handleAttns %d active( PRD)", attentions.size() );
       if(!attentions.empty())
       {
           err = getPrdWrapper().callPrd(attentions);
       }

       if(err)
       {
           ATTN_ERR("callPrd() returned error." )
           break;
       }
       #ifdef __HOSTBOOT_RUNTIME
       // During runtime, we will only handle one attention at a time
       //and give control back to OPAL.
       break;
       #endif //__HOSTBOOT_RUNTIME

   } while(!attentions.empty());

   return err;
}
}
