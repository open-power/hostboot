/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnfakeipoll.C $                      */
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
 * @file attnfakeipoll.C
 *
 * @brief HBATTN fake Ipoll mask register class method definitions.
 */

#include "attnfakeipoll.H"
#include "attnfakesys.H"
#include "attnfakepresenter.H"
#include "../attntarget.H"

using namespace PRDF;
using namespace TARGETING;
using namespace std;

namespace ATTN
{

struct InterruptProperties
{
    FakeSystem * system;

    FakeIpoll * inst;
};

errlHndl_t FakeIpoll::processPutReg(
        FakeSystem & i_sys,
        TARGETING::TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_new,
        uint64_t i_old)
{
    errlHndl_t err = NULL;

    // check for a gfir bit turning on, or
    // if ipoll is unmasked while gfir is high
    // then raise an interrupt

    uint64_t ipollContent = i_address == IPOLL::address
        ? i_new
        : i_sys.getReg(i_target, IPOLL::address);

    uint64_t content = i_address == iv_address
        ? i_new
        : i_sys.getReg(i_target, iv_address);

    bool masked = (ipollContent & iv_ipollbits);
    bool hi = (content & iv_gfirbits);

    bool unmasked = i_address == IPOLL::address
        ? ~ipollContent & i_old & iv_ipollbits
        : false;

    bool set = false;

    if(i_address == GP1::address)
    {
            set = i_new != i_old;
    }
    else if(i_address != IPOLL::address)
    {
        set = ((content & iv_gfirbits) && !(i_old & iv_gfirbits));
    }

    if((set && !masked)
            || (unmasked && hi))
    {
        err = i_sys.modifyReg(
                i_target,
                IPOLL_STATUS_REG,
                iv_ipollbits,
                SCOM_OR);

        interrupt(i_sys, i_target, ATTENTION);
    }
    else
    {
        err = i_sys.modifyReg(
                i_target,
                IPOLL_STATUS_REG,
                ~iv_ipollbits,
                SCOM_AND);
    }

    return err;
}

void FakeIpoll::processEoi(
        FakeSystem & i_sys,
        TARGETING::TargetHandle_t i_source,
        MessageType i_type)
{
    // if gfir is still high and unmasked raise
    // another interrupt...

    uint64_t ipollContent = i_sys.getReg(i_source, IPOLL::address);
    uint64_t content = i_sys.getReg(i_source, iv_address);

    bool masked = ipollContent & iv_ipollbits;
    bool high = content & iv_gfirbits;

    if(high && !masked && iv_address != GP1::address)
    {
        interrupt(i_sys, i_source, ATTENTION);
    }
}

void FakeIpoll::callback(
        TargetHandle_t i_source,
        MessageType i_type,
        void * i_properties)
{
    InterruptProperties * p = static_cast<InterruptProperties *>(i_properties);

    FakeSystem & f = *p->system;
    FakeIpoll & inst = *p->inst;

    inst.processEoi(f, i_source, i_type);

    delete p;
}

void FakeIpoll::interrupt(
        FakeSystem & i_system,
        TargetHandle_t i_source,
        MessageType i_type)
{
    // instruct the presenter to raise an interrupt, using
    // our callback

    InterruptProperties * p = new InterruptProperties;

    p->inst = this;
    p->system = & i_system;

    iv_presenter->interrupt(i_source, i_type, p, &callback);
}

void FakeIpoll::install(FakeSystem & i_sys)
{
    // monitor ipoll
    i_sys.addReg(IPOLL::address, *this);

    // monitor signal being masked by ipoll
    i_sys.addReg(iv_address, *this);
}

void getMask(uint64_t i_pos, void * i_data)
{
    uint64_t & mask = *static_cast<uint64_t *>(i_data);

    uint64_t tmp = 0;
    GP1::getCheckbits(i_pos, tmp);

    mask |= tmp;
}

FakeIpoll::FakeIpoll(
        uint64_t i_type,
        FakePresenter & i_presenter) :
     iv_address(0),
     iv_gfirbits(0),
     iv_ipollbits(0),
     iv_presenter(&i_presenter)
{
    if(i_type == HOST)
    {
        // figure out what bits to monitor
        // in the nest gp1 register, if
        // this instance is monitoring
        // HOST attentions.

        GP1::forEach(0xffffffffffffffffull, &iv_gfirbits, &getMask);
        iv_address = GP1::address;
    }

    else
    {
        GFIR::getAddress(i_type, iv_address);
        GFIR::getCheckbits(i_type, iv_gfirbits);
    }

    IPOLL::getCheckbits(i_type, iv_ipollbits);
}
}
