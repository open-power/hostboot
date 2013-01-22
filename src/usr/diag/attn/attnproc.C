/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnproc.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
/**
 * @file attnproc.C
 *
 * @brief HBATTN Processor attention operations function definitions.
 */

#include <errl/errlmanager.H>
#include "attnproc.H"
#include "attnlist.H"
#include "attntrace.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t ProcOps::mask(const AttnData & i_data)
{
    errlHndl_t err = 0;

    uint64_t ipollMaskWriteBits = 0;

    IPOLL::getCheckbits(i_data.attnType, ipollMaskWriteBits);

    err = modifyScom(i_data.targetHndl, IPOLL::address,
            ipollMaskWriteBits, SCOM_OR);

    return err;
}

errlHndl_t ProcOps::unmask(const AttnData & i_data)
{
    errlHndl_t err = 0;

    uint64_t ipollMaskWriteBits = 0;

    IPOLL::getCheckbits(i_data.attnType, ipollMaskWriteBits);

    err = modifyScom(i_data.targetHndl, IPOLL::address,
                ~ipollMaskWriteBits, SCOM_AND);
    return err;
}

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
