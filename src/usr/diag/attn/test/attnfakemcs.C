/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakemcs.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file attnfakemcs.C
 *
 * @brief HBATTN fake MCS class method definitions.
 */

#include "attnfakemcs.H"
#include "attnfakesys.H"
#include "../attntarget.H"

using namespace TARGETING;
using namespace PRDF;
using namespace std;

namespace ATTN
{

errlHndl_t FakeMcs::processPutReg(
            FakeSystem & i_sys,
            TargetHandle_t i_target,
            uint64_t i_address,
            uint64_t i_new,
            uint64_t i_old)
{
    errlHndl_t err = 0;

    AttnData d;

    d.targetHndl = getTargetService().getMembuf(i_target);
    d.attnType = iv_type;

    // see if the error was cleared but should
    // be turned back on (because of other attentions)

    bool cleared = i_old & ~i_new & iv_writebits;

    if(cleared && i_sys.count(d))
    {
        // turn it back on...

        err = i_sys.modifyReg(
                i_target,
                i_address,
                iv_writebits,
                SCOM_OR);
    }

    return err;
}

errlHndl_t FakeMcs::processPutAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    errlHndl_t err = 0;

    TargetHandle_t mcs = getTargetService().getMcs(
            i_attention.targetHndl);

    // turn the fir bit on (if not already on)

    uint64_t content = i_sys.getReg(mcs, MCI::address);

    if(!(content & iv_writebits))
    {
        err = i_sys.modifyReg(
                mcs,
                MCI::address,
                iv_writebits,
                SCOM_OR);
    }

    return err;
}

errlHndl_t FakeMcs::processClearAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    errlHndl_t err = 0;

    TargetHandle_t mcs = getTargetService().getMcs(
            i_attention.targetHndl);

    if(!i_count)
    {
        // there are no more instances of
        // this attention being reported...
        // turn the fir bit off

        err = i_sys.modifyReg(
                mcs,
                MCI::address,
                ~iv_writebits,
                SCOM_AND);
    }

    return err;
}

void FakeMcs::install(FakeSystem & i_sys)
{
    // monitor all the mci firs

    i_sys.addReg(MCI::address, *this);
    i_sys.addSource(TYPE_MEMBUF, iv_type, *this);
}

FakeMcs::FakeMcs(PRDF::ATTENTION_VALUE_TYPE i_type) :
    iv_type(i_type), iv_writebits(0)
{
    MCI::getCheckbits(i_type, iv_writebits);
}
}
