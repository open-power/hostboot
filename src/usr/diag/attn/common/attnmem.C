/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.C $                          */
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
 * @file attnmem.C
 *
 * @brief HBATTN Memory attention operations function definitions.
 */

#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include "common/attnmem.H"
#include "common/attnlist.H"
#include "common/attntarget.H"
#include "attntrace.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

struct ResolveMcsArgs
{
    TargetHandle_t proc;
    AttentionList * list;
    MemOps * ops;
};

void resolveMcs(uint64_t i_mcs, void * i_data)
{
    ResolveMcsArgs * args = static_cast<ResolveMcsArgs *>(i_data);

    uint64_t mciFirScomData;

    TargetHandle_t mcs = getTargetService().getMcs(args->proc, i_mcs);

    // read the MCI fir to determine what type of attention
    // centaur reporting

    errlHndl_t err = getScom(mcs, MCI::address, mciFirScomData);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }
    else
    {
        // pick the highest priority attention

        for(uint64_t type = INVALID_ATTENTION_TYPE;
                type != END_ATTENTION_TYPE;
                ++type)
        {
            uint64_t mask;

            if(!MCI::getCheckbits(type, mask))
            {
                // this object doesn't support
                // this attention type

                continue;
            }

            if(mask & mciFirScomData)
            {
                AttnData d;
                d.targetHndl = getTargetService().getMembuf(mcs);

                if(!d.targetHndl)
                {
                    // this membuf not functional
                    // or nothing is attached to this MCS

                    break;
                }

                d.attnType = static_cast<ATTENTION_VALUE_TYPE>(type);

                args->list->add(Attention(d, args->ops));
                break;
            }
        }
    }
}

errlHndl_t MemOps::resolve(
        TargetHandle_t i_proc,
        AttentionList & o_attentions)
{
    errlHndl_t err = 0;

    //@TODO: RTC:150944
    // Don't need this for now as this is Centaur Chip related
    ATTN_TRACE("MemOps::resolve - P9 Noop");

#if 0
    uint64_t gp1ScomData = 0;

    do {

        // get the nest gp1 register content and decode
        // (get a list of membufs reporting attentions)

        err = getScom(i_proc, GP1::address, gp1ScomData);

        if(err)
        {
            break;
        }

        ResolveMcsArgs args;

        args.proc = i_proc;
        args.list = &o_attentions;
        args.ops = this;

        GP1::forEach(gp1ScomData, &args, &resolveMcs);

    } while(0);
#endif

    return err;
}

MemOps::MemOps()
{

}

MemOps::~MemOps()
{

}
}
