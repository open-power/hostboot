/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakegp1.C $
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
 * @file attnfakegp1.C
 *
 * @brief HBATTN fake GP1 class method definitions.
 */

#include "attnfakegp1.H"
#include "attnfakesys.H"
#include "../attntarget.H"

using namespace TARGETING;
using namespace PRDF;
using namespace std;

namespace ATTN
{

void setFlag(uint64_t i_type, void * i_data)
{
    bool * f = static_cast<bool *>(i_data);

    *f = true;
}

struct FindMcsArgs
{
    bool reporting;
    uint64_t pos;
};

void findMcs(uint64_t i_pos, void * i_data)
{
    FindMcsArgs * args = static_cast<FindMcsArgs *>(i_data);

    if(i_pos == args->pos)
    {
        args->reporting = true;
    }
}

errlHndl_t FakeGp1::processPutReg(
            FakeSystem & i_sys,
            TargetHandle_t i_target,
            uint64_t i_address,
            uint64_t i_new,
            uint64_t i_old)
{
    errlHndl_t err = 0;
    uint64_t mcsPos;

    TargetHandle_t membuf = getTargetService().getMembuf(i_target);
    TargetHandle_t proc = getTargetService().getProc(membuf);

    getTargetService().getMcsPos(i_target, mcsPos);

    uint64_t gp1Content = i_sys.getReg(proc, GP1::address);

    bool set = false, cleared = false, on = false;

    // these mci bits turned on
    MCI::forEach(i_new & ~i_old, &set, &setFlag);

    // these mci bits turned off
    MCI::forEach(~i_new & i_old, &cleared, &setFlag);

    // these mci bits are on
    MCI::forEach(i_new, &on, &setFlag);

    // whether or not the mcs is reporting

    FindMcsArgs args;

    args.reporting = false;
    args.pos = mcsPos;
    GP1::forEach(gp1Content, &args, &findMcs);

    uint64_t writebits;
    GP1::getCheckbits(mcsPos, writebits);

    if(args.reporting && cleared && !on)
    {
        // this mcs is reporting, but all the bits in the MCI FIR
        // have turned off.

        err = i_sys.modifyReg(
                proc,
                GP1::address,
                ~writebits,
                SCOM_AND);
    }

    else if(!args.reporting && set)
    {
        // this mcs wasn't reporting before, but now a bit is on

        err = i_sys.modifyReg(
                proc,
                GP1::address,
                writebits,
                SCOM_OR);
    }

    return err;
}

void FakeGp1::install(FakeSystem & i_sys)
{
    // monitor changes to mci firs

    i_sys.addReg(MCI::address, *this);
}
}
