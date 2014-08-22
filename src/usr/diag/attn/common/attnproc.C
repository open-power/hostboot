/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnproc.C $                         */
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
/**
 * @file attnproc.C
 *
 * @brief HBATTN Processor attention operations function definitions.
 */

#include <errl/errlmanager.H>
#include "common/attnproc.H"
#include "common/attnlist.H"
#include "common/attntrace.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t ProcOps::query(const AttnData & i_attnToCheck, bool & o_active)
{
    errlHndl_t err = 0;

    uint64_t address = 0, checkbits = 0, scomData = 0;

    GFIR::getAddress(i_attnToCheck.attnType, address);

    GFIR::getCheckbits(i_attnToCheck.attnType, checkbits);

    err = getScom(i_attnToCheck.targetHndl, address, scomData);

    if(!err)
    {
        if(scomData & checkbits)
        {
            o_active = true;
        }
        else
        {
            o_active = false;
        }
    }

    return err;
}

errlHndl_t ProcOps::resolveIpoll(
        TargetHandle_t i_proc,
        AttentionList & o_attentions)
{
    errlHndl_t err = NULL;
    uint64_t on = 0;
    uint64_t observed = 0;
    bool active = false;
    AttnData d;

    // very unlikely, but look for any
    // supported bits on in the
    // status register, in case the other
    // thread hasn't masked it yet

    err = getScom(i_proc, IPOLL_STATUS_REG, on);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }

    // also look for any supported bits on in the
    // mask register, indicating that the other thread
    // saw the error and masked it.

    err = getScom(i_proc, IPOLL::address, observed);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }

    for(uint64_t type = INVALID_ATTENTION_TYPE;
            type != END_ATTENTION_TYPE;
            ++type)
    {
        uint64_t supported = 0;

        if(!IPOLL::getCheckbits(type, supported))
        {
            // this object doesn't support
            // this attention type

            continue;
        }

        // analysis should be done if the bit for this
        // attention type is either on in the status reg
        // or masked in the mask reg

        if(!(supported & (on | observed)))
        {
            continue;
        }

        d.attnType = static_cast<ATTENTION_VALUE_TYPE>(type);
        d.targetHndl = i_proc;

        // to be sure, query corresponding GFIR
        err = query(d, active);
        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }
        else if(active)
        {
            o_attentions.add(Attention(d, this));
            break;
        }
    }

    return err;
}

errlHndl_t ProcOps::resolve(
        TargetHandle_t i_proc,
        uint64_t i_typeMask,
        AttentionList & o_attentions)
{
    errlHndl_t err = 0;

    bool active = false;
    AttnData d;
    d.targetHndl = i_proc;

    uint64_t ignored;

    for(uint64_t type = INVALID_ATTENTION_TYPE;
            type != END_ATTENTION_TYPE;
            ++type)
    {
        if(!enabled())
        {
            break;
        }

        if(!GFIR::getCheckbits(type, ignored))
        {
            // this object doesn't support
            // this attention type

            continue;
        }

        uint64_t mask = 0;

        IPOLL::getCheckbits(type, mask);

        if(!(mask & ~i_typeMask))
        {
            // this attention type is masked

            continue;
        }

        d.attnType = static_cast<ATTENTION_VALUE_TYPE>(type);

        err = query(d, active);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }

        else if(active)
        {
            o_attentions.add(Attention(d, this));
            break;
        }
    }

    return err;
}
}
