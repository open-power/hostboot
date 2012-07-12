/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakegfir.C $
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
 * @file attnfakegfir.C
 *
 * @brief HBATTN fake global FIR class method definitions.
 */

#include "attnfakegfir.H"
#include "attnfakesys.H"
#include "../attntarget.H"

using namespace TARGETING;
using namespace PRDF;

namespace ATTN
{

errlHndl_t FakeGfir::processPutReg(
        FakeSystem & i_sys,
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_new,
        uint64_t i_old)
{
    errlHndl_t err = 0;

    AttnData d;

    d.targetHndl = i_target;
    d.attnType = iv_type;

    // see if the error was cleared but should
    // be turned back on (because of other attentions)

    bool cleared = i_old & ~i_new & iv_writebits;

    if(cleared && i_sys.count(d))
    {
        // turn it back on...

        err = i_sys.modifyReg(
                i_target,
                iv_address,
                iv_writebits,
                SCOM_OR);
    }

    return err;
}

errlHndl_t FakeGfir::processPutAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    errlHndl_t err = 0;

    TargetHandle_t target = i_attention.targetHndl;

    uint64_t data = i_sys.getReg(target, iv_address);

    bool off = ~data & iv_writebits;

    // turn the fir bit on (if not already on)

    if(off)
    {
        err = i_sys.modifyReg(
                target,
                iv_address,
                iv_writebits,
                SCOM_OR);
    }

    return err;
}

errlHndl_t FakeGfir::processClearAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    errlHndl_t err = 0;

    TargetHandle_t target = i_attention.targetHndl;

    uint64_t data = i_sys.getReg(target, iv_address);

    bool on = data & iv_writebits;

    if(on && !i_count)
    {
        // there are no more instances of
        // this attention being reported...
        // turn the fir bit off

        err = i_sys.modifyReg(
                target,
                iv_address,
                ~iv_writebits,
                SCOM_AND);
    }

    return err;
}

void FakeGfir::install(FakeSystem & i_sys)
{
    i_sys.addReg(iv_address, *this);
    i_sys.addSource(TYPE_PROC, iv_type, *this);
}

FakeGfir::FakeGfir(ATTENTION_VALUE_TYPE i_type) :
    iv_type(i_type), iv_address(0), iv_writebits(0)
{
    GFIR::getAddress(i_type, iv_address);
    GFIR::getCheckbits(i_type, iv_writebits);
}
}
