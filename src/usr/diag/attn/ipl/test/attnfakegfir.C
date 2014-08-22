/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attnfakegfir.C $              */
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
 * @file attnfakegfir.C
 *
 * @brief HBATTN fake global FIR class method definitions.
 */

#include "attnfakegfir.H"
#include "attnfakesys.H"
#include "../../common/attntarget.H"

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
