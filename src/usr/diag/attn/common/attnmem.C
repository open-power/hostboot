/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#include <targeting/common/utilFilter.H>

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

void MemOps::resolveOcmbs( const TargetHandle_t i_proc,
                           AttentionList & io_attentions )
{
    // Check the attribute whether we are at a point in the IPL where we can
    // get attentions from the OCMBs but will not get interrupts.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget( sys );
    assert( sys != nullptr );
    if ( 0 == sys->getAttr<ATTR_ATTN_CHK_OCMBS>() )
    {
        return;
    }

    // Check whether we are at a point in the IPL where we are unsure whether
    // scoms to the OCMBs will work. In that case, we need to poll the
    // PRD_HWP_PLID attribute to see whether we can do any OCMB scoms.
    uint8_t pollData = 0;
    bool pollPlid = false;
    if (sys->tryGetAttr<ATTR_ATTN_POLL_PLID>(pollData) && (pollData != 0))
    {
        ATTN_SLOW( "MemOps::resolveOcmbs PRD_HWP_PLID must be polled" );
        pollPlid = true;
    }

    // Get the list of OCMBs connected to the input proc
    TargetHandleList ocmbList;

    PredicateCTM          predOcmb( CLASS_CHIP, TYPE_OCMB_CHIP );
    PredicateIsFunctional functional;
    PredicatePostfixExpr  pred;
    pred.push(&predOcmb).push(&functional).And();

    targetService().getAssociated( ocmbList, i_proc,
                                   TARGETING::TargetService::CHILD_BY_AFFINITY,
                                   TARGETING::TargetService::ALL, &pred );

    // Vector to denote the chiplet FIRs on the OCMB along with their respective
    // masks and what attention type they check. NOTE: The order of the firList
    // should be in order from highest to lowest priority attention to ensure
    // the first attention we find is the highest priority one.
    struct firInfo
    {
        uint32_t firAddr;
        uint32_t firMask;
        ATTENTION_VALUE_TYPE attnType;
    };
    static const std::vector<firInfo> firList
    {
        { 0x08040000, 0x08040002, UNIT_CS     }, // OCMB_CHIPLET_CS_FIR
        { 0x08040001, 0x08040002, RECOVERABLE }, // OCMB_CHIPLET_RE_FIR
        { 0x08040004, 0x08040007, HOST_ATTN   }, // OCMB_CHIPLET_SPA_FIR
    };

    bool attnFound = false;
    for ( const auto & ocmb : ocmbList )
    {
        if ( iv_ocmbChnlFail[ocmb] )
        {
            // We've already handled a channel fail on this OCMB, so skip it
            ATTN_SLOW( "MemOps::resolveOcmbs Channel fail attention already "
                       "handled on ocmb 0x%08x, skipping further analysis",
                       get_huid(ocmb) );
            continue;
        }

        if ( pollPlid )
        {
            uint32_t plid = 0;
            if ( ocmb->tryGetAttr<ATTR_PRD_HWP_PLID>(plid) && (0 == plid) )
            {
                // If the attribute is not set, skip this OCMB
                ATTN_SLOW( "MemOps::resolveOcmbs PRD_HWP_PLID not set" );
                continue;
            }
        }
        for ( const auto & fir : firList )
        {
            // Get the data from the chiplet FIR
            uint64_t firData = 0;
            errlHndl_t err = getScom( ocmb, fir.firAddr, firData );
            if ( err )
            {
                ATTN_SLOW( "MemOps::resolveOcmbs FIR getScom failed" );
                errlCommit( err, ATTN_COMP_ID );
                break;
            }

            // Get the data from the chiplet FIR mask
            uint64_t firMaskData = 0;
            err = getScom( ocmb, fir.firMask, firMaskData );
            if ( err )
            {
                ATTN_SLOW( "MemOps::resolveOcmbs mask getScom failed" );
                errlCommit( err, ATTN_COMP_ID );
                break;
            }

            // Account for recoverable bits shifting
            if ( RECOVERABLE == fir.attnType )
            {
                firData = firData >> 2;
            }
            // Check for any FIR bits on
            if ( firData & ~firMaskData )
            {
                // If FIR bits are on, add the OCMB attn to the attn list
                AttnData newData( ocmb, fir.attnType );
                io_attentions.add( Attention(newData, this) );
                attnFound = true;

                // If the attention was a UNIT_CS then update iv_ocmbChnlFail
                if ( UNIT_CS == fir.attnType )
                {
                    iv_ocmbChnlFail[ocmb] = true;
                }
                break;
            }
        }
        if ( attnFound ) break;
    }

    ATTN_SLOW( "MemOps::resolveOcmbs end" );
}

MemOps::MemOps()
{

}

MemOps::~MemOps()
{

}
}
