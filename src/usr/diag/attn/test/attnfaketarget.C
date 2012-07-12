/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfaketarget.C $
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
 * @file attnfaketarget.C
 *
 * @brief HBATTN fake targeting class method definitions.
 */

#include "attnfaketarget.H"
#include "../attntrace.H"

using namespace TARGETING;
using namespace std;

namespace ATTN
{

TargetHandle_t FakeProcTargetService::getProcFromPos(uint64_t i_pos)
{
    return i_pos < iv_procs.size() ? iv_procs[i_pos] : 0;
}

uint64_t FakeProcTargetService::getProcFromTarget(TargetHandle_t i_proc)
{
    return distance(
            iv_procs.begin(),
            find(iv_procs.begin(), iv_procs.end(), i_proc));
}

FakeProcTargetService::FakeProcTargetService(uint64_t i_count)
{
    for(uint64_t i = 0; i < i_count; ++i)
    {
        iv_procs.push_back(reinterpret_cast<TargetHandle_t>(i));
    }
}

void FakeProcTargetService::getAllChips(
        TargetHandleList & o_list,
        TYPE i_type,
        bool i_functional)
{
    switch (i_type)
    {
        case TYPE_PROC:

            o_list = iv_procs;
            break;

        default:
            break;
    }
}

void FakeMemTargetService::getAllChips(
        TargetHandleList & o_list,
        TYPE i_type,
        bool i_functional)
{
    switch (i_type)
    {
        case TYPE_PROC:

            FakeProcTargetService::getAllChips(o_list, i_type, i_functional);
            break;

        case TYPE_MEMBUF:

            o_list = iv_membufs;
            break;

        default:
            break;
    };
}

void FakeMemTargetService::getMcsList(
        TargetHandle_t i_proc,
        TargetHandleList & o_list)
{
    TargetHandleList::iterator mcsBegin = iv_mcses.begin()
        + getProcFromTarget(i_proc) * cv_membufsPerProc;

    o_list.insert(o_list.end(), mcsBegin, mcsBegin + cv_membufsPerProc);
}

TargetHandle_t FakeMemTargetService::getProc(
        TargetHandle_t i_membuf)
{
    return getProcFromPos(
            distance(
                iv_membufs.begin(),
                find(iv_membufs.begin(), iv_membufs.end(), i_membuf))
            / cv_membufsPerProc);
}

TargetHandle_t FakeMemTargetService::getMcs(
        TargetHandle_t i_membuf)
{
    return *(iv_mcses.begin() + distance(
                iv_membufs.begin(),
                find(iv_membufs.begin(), iv_membufs.end(), i_membuf)));
}

TargetHandle_t FakeMemTargetService::getMcs(
        TargetHandle_t i_proc,
        uint64_t i_pos)
{
    return *(iv_mcses.begin() + i_pos + getProcFromTarget(i_proc) * cv_membufsPerProc);
}

void FakeMemTargetService::getMcsPos(
                TARGETING::TargetHandle_t i_mcs,
                uint64_t & o_pos)
{
    o_pos = distance(
            iv_mcses.begin(),
            find(iv_mcses.begin(), iv_mcses.end(), i_mcs))
        % cv_membufsPerProc;
}

TargetHandle_t FakeMemTargetService::getMembuf(
        TargetHandle_t i_mcs)
{
    return *(iv_membufs.begin() + distance(
                iv_mcses.begin(),
                find(iv_mcses.begin(), iv_mcses.end(), i_mcs)));
}

TYPE FakeMemTargetService::getType(TargetHandle_t i_target)
{
    return find(iv_mcses.begin(), iv_mcses.end(), i_target) != iv_mcses.end()
        ? TYPE_MCS
        : (find(iv_membufs.begin(), iv_membufs.end(), i_target) != iv_membufs.end()
                ? TYPE_MEMBUF
                : FakeProcTargetService::getType(i_target));
}

void FakeMemTargetService::dump()
{
    for(uint64_t i = 0; i < iv_membufs.size() / cv_membufsPerProc; ++i)
    {
        TargetHandle_t proc = getProcFromPos(i);

        ATTN_DBG("FakeMemTargetService::dump: proc: %p", proc);

        for(uint64_t j = 0; j < cv_membufsPerProc; ++j)
        {
            TargetHandle_t mcs = getMcs(proc, j);
            TargetHandle_t membuf = getMembuf(mcs);

            if(mcs && membuf)
            {
                ATTN_DBG("FakeMemTargetService::dump:     mcs%d: %p", j, mcs);
                ATTN_DBG("FakeMemTargetService::dump:     membuf%d: %p", j, membuf);
            }
        }
    }
}

FakeMemTargetService::~FakeMemTargetService()
{

}

FakeMemTargetService::FakeMemTargetService(
        uint64_t i_count) :
    FakeProcTargetService(i_count)
{
    for(uint64_t i = 0; i < i_count * cv_membufsPerProc; ++i)
    {
        iv_mcses.push_back(reinterpret_cast<TargetHandle_t>(i + i_count));
        iv_membufs.push_back(reinterpret_cast<TargetHandle_t>(i + i_count * cv_membufsPerProc + i_count));
    }
}
}
