/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

typedef struct
{
    uint32_t              chipletFir;
    uint32_t              chipletFirMask;
    ATTENTION_VALUE_TYPE  attnType;

    // First of four bits to check
    // (2 bits apart)
    uint64_t              intrBitToChk;
} attnMemoryFirs_t;


const attnMemoryFirs_t  ATTN_MEM_CHIPLET_FIRS[] =
{
    { 0x07040009, 0x0704001A,
          HOST_ATTN,   0x4000000000000000ull },  // Host    1,3,5,7
    { 0x07040018, 0x07040019,
          UNIT_CS,     0x4000000000000000ull },  // unit CS  1,3,5,7
    { 0x07040001, 0x07040002,
          RECOVERABLE, 0x0800000000000000ull },  // Recov   4,6,8,10
    { 0x07040000, 0x07040002,
          CHECK_STOP,  0x0800000000000000ull }   // chkstop  4,6,8,10
};

// 4 DMI units per MC
const uint32_t  ATTN_MAX_DMI_INTRS = 4;

// Processor FIR set when MemBuffer raises attention
const uint32_t  ATTN_ADDR_CHIFIR_DATA = 0x07010900;
const uint32_t  ATTN_ADDR_CHIFIR_MASK = 0x07010903;
const uint32_t  ATTN_ADDR_CHIFIR_ACT0 = 0x07010906;
const uint32_t  ATTN_ADDR_CHIFIR_ACT1 = 0x07010907;

// Attention bit positions in CHIFIR 16, 19,20,21
const uint64_t  ATTN_CEN_CHECKSTOP = 0x0000800000000000ull ;
const uint64_t  ATTN_CEN_RECOV     = 0x0000100000000000ull ;
const uint64_t  ATTN_CEN_SPECIAL   = 0x0000080000000000ull ;
const uint64_t  ATTN_CEN_MAINT_CMD = 0x0000040000000000ull ;



// @TODO RTC: 180469
//  Move to target services part and then update all the CXX testing
TargetHandle_t MemOps::attnGetMembuf( const TARGETING::TargetHandle_t &i_mc,
                                      const uint32_t i_dmi,
                                      const ATTENTION_VALUE_TYPE i_attnType )
{
    // where i_dmi is 0:7 value
    TargetHandle_t    membuf   = NULL;
    TargetHandleList  l_dmiList;
    errlHndl_t        l_err = NULL;
    uint64_t          l_chifirData = 0;
    uint64_t          l_chifirMask = 0;
    uint64_t          l_chifirIntr = 0;


    // Get the list of DMI units for MC unit passed in
    getChildChiplets(l_dmiList, i_mc, TYPE_DMI);

    for ( auto  l_dmiTarg : l_dmiList )
    {
        ATTN_TRACE("   MemRes(%d) - DMI:%d chiplet from MC",
                   i_dmi, l_dmiTarg->getAttr<ATTR_CHIP_UNIT>() );

        if ( i_dmi == l_dmiTarg->getAttr<ATTR_CHIP_UNIT>() )
        {
            ATTN_SLOW("    MemOps::resolve - DMI Match:%d",
                      i_dmi  );

            // Get mem buffer associated with the DMI chiplet
            TargetHandleList  l_memBufList;
            getChildAffinityTargets( l_memBufList, l_dmiTarg,
                                     CLASS_CHIP, TYPE_MEMBUF );

            if (l_memBufList.size() == 1)
            {
                // Validate Centaur actually raised attention
                l_err = getScom( l_dmiTarg,
                                 ATTN_ADDR_CHIFIR_DATA,
                                 l_chifirData );

                if (NULL == l_err)
                {
                    l_err = getScom( l_dmiTarg,
                                     ATTN_ADDR_CHIFIR_MASK,
                                     l_chifirMask );
                } // end if no error on getscom CHIFIR

                if (NULL == l_err)
                {
                    // Check for active attention
                    l_chifirIntr = l_chifirData & ~l_chifirMask;

                    ATTN_SLOW("    MemOps::res - CenAttn:%016llx ::%X",
                               l_chifirIntr, i_attnType );

                    // Is it attn we are looking for ?
                    if ( ( (i_attnType == HOST_ATTN) &&
                           ((l_chifirIntr & ATTN_CEN_SPECIAL) ||
                            (l_chifirIntr & ATTN_CEN_MAINT_CMD)
                           )
                         )  ||

                         ( (i_attnType == RECOVERABLE) &&
                           (l_chifirIntr & ATTN_CEN_RECOV)
                         )  ||
                         ( (i_attnType == CHECK_STOP) &&
                           (l_chifirIntr & ATTN_CEN_CHECKSTOP)
                         )  ||

                         ( (i_attnType == UNIT_CS) &&
                           (l_chifirIntr & ATTN_CEN_CHECKSTOP)
                         )
                       )
                    {
                        membuf = l_memBufList[0];
                        // Found right DMI and memory buffer
                        // so stop loooping
                        break;
                    } // end if matching attention in membuf

                } // end if no error on getscom CHIFIR Mask


                // Handle any elog
                if (NULL != l_err)
                {
                    l_err->collectTrace("ATTN_SLOW" , 512 );
                    errlCommit(l_err, ATTN_COMP_ID);
                }  // if elog

            } // end one membuf found

        } // end if correct DMI target

    } // end for on DMI targets


    return(membuf);

} // end attnGetMembuf


uint64_t MemOps::chkMembufAttn( TARGETING::TargetHandle_t  i_memBuf,
                                const ATTENTION_VALUE_TYPE i_attnType )
{
    errlHndl_t  l_err = NULL;
    uint64_t    l_scomData = 0;
    uint64_t    l_scomAddr = 0;


    // Which broadcast FIR should we be checking ?
    switch (i_attnType)
    {
        // These are the same for memBuf
        case  UNIT_CS:
            l_scomAddr = 0x500f001c;
            break;

        case  RECOVERABLE:
            l_scomAddr = 0x500f001b;
            break;

        // These are the same for memBuf
        case  HOST_ATTN:
            l_scomAddr = 0x500f001a;
            break;

        default:
            // invalid attn type
            break;

    } // end switch on attn type


    if (0 != l_scomAddr)
    {
        // Read the global broadcast FIR from memory buffer
        l_err = getScom(i_memBuf, l_scomAddr, l_scomData);
        // Any active bits indicates it has attn pending

        if (NULL != l_err)
        {
            ATTN_SLOW("Failed membuf readAddr:%016llx",
                       l_scomAddr);

            // ensure we don't have anything active
            l_scomData = 0;
            l_err->collectTrace("ATTN_SLOW" , 512 );
            errlCommit(l_err, ATTN_COMP_ID);
        }  // if elog

    } // if valid attn type/valid addr

    return(l_scomData);

} // end chkMembufAttn


bool MemOps::attnCmpAttnType( TARGETING::TargetHandle_t  i_dmiTarg,
                              const ATTENTION_VALUE_TYPE i_attnType )
{
    errlHndl_t  l_err = NULL;
    bool        l_validAttnType = false;
    uint64_t    l_chifirData = 0;
    uint64_t    l_chifirMask = 0;
    uint64_t    l_chifirAct0 = 0;
    uint64_t    l_chifirAct1 = 0;
    uint64_t    l_result = 0;


    // Get the actual CHIFIR data
    l_err = getScom(i_dmiTarg, ATTN_ADDR_CHIFIR_DATA, l_chifirData);

    if (NULL == l_err)
    {
        l_err = getScom(i_dmiTarg, ATTN_ADDR_CHIFIR_MASK, l_chifirMask);
    } // end if no error on getscom CHIFIR data

    if (NULL == l_err)
    {
        l_err = getScom(i_dmiTarg, ATTN_ADDR_CHIFIR_ACT0, l_chifirAct0);
    } // end if no error on getscom CHIFIR mask

    if (NULL == l_err)
    {
        l_err = getScom(i_dmiTarg, ATTN_ADDR_CHIFIR_ACT1, l_chifirAct1);
    } // end if no error on getscom CHIFIR action0

    if (NULL == l_err)
    {
        // Actions:00 CS, 01 REC, 10 SPEC/HOST, 11 UCS

        // Will modify the actions appropriately so we can just
        // AND them with the FIR data.
        switch (i_attnType)
        {
            case CHECK_STOP:
                l_chifirAct0 = ~l_chifirAct0;
                l_chifirAct1 = ~l_chifirAct1;
                break;

            case RECOVERABLE:
                l_chifirAct0 = ~l_chifirAct0;
                break;

            case HOST_ATTN:
            case SPECIAL:
                l_chifirAct1 = ~l_chifirAct1;
                break;

            case UNIT_CS:
                // actions are fine as is ('11')
                break;

            default:
                // Not valid attn type
                // so won't match on anything
                l_chifirAct0 = 0;
                l_chifirAct1 = 0;
                break;

        } // end switch on attnType

        // Validate if specified attention does exist in
        // CHIFIR and it is not masked.
        l_result = l_chifirData & ~l_chifirMask & l_chifirAct0 & l_chifirAct1;

        if (0 != l_result)
        {
            l_validAttnType = true;
        }

    } // end if no error on getscom CHIFIR action1


    if (NULL != l_err)
    {
        ATTN_SLOW("Failed attnCmpAttnType scom");
        l_err->collectTrace("ATTN_SLOW" , 512 );
        errlCommit(l_err, ATTN_COMP_ID);
    }  // if elog


    return(l_validAttnType);

} // end attnCmpAttnType


bool MemOps::resolve(
        PRDF::AttnData &  i_AttnData,
        const uint32_t  i_mcNumber,
        TARGETING::TargetHandle_t  i_procTarg )
{
    errlHndl_t  l_err = 0;
    bool        l_attnFound = false;
    uint64_t    l_firData  = 0;
    uint64_t    l_maskData = 0;
    uint64_t    l_intData  = 0;
    uint32_t    l_mcNum    = 0;
    uint32_t    l_dmi_0to7 = 0;


    TargetHandleList l_mcTargetList;

    // predicate of functional MC units
    PredicateCTM           l_unitMatch(CLASS_UNIT, TYPE_MC);
    PredicateIsFunctional  l_functional;
    PredicatePostfixExpr   l_pred;

    l_pred.push(&l_unitMatch).push(&l_functional).And();

    // Get all MC units associated with input processor
    targetService().getAssociated(
            l_mcTargetList,
            i_procTarg,
            TARGETING::TargetService::CHILD_BY_AFFINITY,
            TARGETING::TargetService::ALL,
            &l_pred);


    // Find correct MC chiplet
    for ( auto  l_mc : l_mcTargetList )
    {
        ATTN_TRACE("MemOps::resolve - MC chiplet:%d", i_mcNumber);
        l_mcNum = l_mc->getAttr<ATTR_CHIP_UNIT>();

        if (l_mcNum == i_mcNumber)
        {
            // Check for attention using chiplet summary registers
            uint32_t  l_numFirs = sizeof(ATTN_MEM_CHIPLET_FIRS) /
                                  sizeof(attnMemoryFirs_t);

            for ( uint32_t l_cFir=0; (l_cFir < l_numFirs); l_cFir++ )
            {
                // Verify the attention type
                if (i_AttnData.attnType ==
                               ATTN_MEM_CHIPLET_FIRS[l_cFir].attnType)
                {
                    // get chiplet FIR data
                    l_err = getScom(l_mc,
                                    ATTN_MEM_CHIPLET_FIRS[l_cFir].chipletFir,
                                    l_firData);

                    if (NULL == l_err)
                    {
                        // Get chiplet MASK
                        l_err = getScom(l_mc,
                                  ATTN_MEM_CHIPLET_FIRS[l_cFir].chipletFirMask,
                                  l_maskData);

                        ATTN_SLOW(
                           "...MemRes:cAddr:%016llx cFir:%016llx cMask:%016llx",
                           ATTN_MEM_CHIPLET_FIRS[l_cFir].chipletFir,
                           l_firData, l_maskData );

                        if (NULL == l_err)
                        {
                            // Recoverable FIR & MASK are 2 bits off
                            // so need to handle this here
                            if (RECOVERABLE == i_AttnData.attnType)
                            {
                                l_firData = l_firData >> 2;
                            } // end if recoverable

                            // Check for active attention
                            l_intData  = l_firData & ~l_maskData;

                            ATTN_TRACE("...resolve - IntrActive::%016llx ",
                                        l_intData );

                            // Interrupts are in various bit positions,
                            // so will shift a mask 2 bit positions for each DMI
                            for ( uint32_t l_intNum=0;
                                   (l_intNum < ATTN_MAX_DMI_INTRS); l_intNum++)
                            {
                                // Check for active DMI interrupt
                                if ( l_intData &
                                     (ATTN_MEM_CHIPLET_FIRS[l_cFir].intrBitToChk
                                                            >> (l_intNum*2)) )
                                {
                                    // Heirarchy:  MC -> MI -> DMI -> Centaur
                                    // Valid active interrupt on DMI Bus
                                    // Need  membuf targ for passing to PRD

                                    // Determine DMI chiplet - 0 thru 7 value
                                    l_dmi_0to7 = (l_mcNum * ATTN_MAX_DMI_INTRS)
                                                  + l_intNum;

                                    AttnData d;
                                    // add membuf target if found
                                    d.targetHndl = attnGetMembuf(l_mc,
                                                          l_dmi_0to7,
                                                          i_AttnData.attnType);

                                    if (NULL != d.targetHndl)
                                    {
                                        ATTN_SLOW(
                                        "     MemOpsRes -Got membuf Attn:%d",
                                        ATTN_MEM_CHIPLET_FIRS[l_cFir].attnType);

                                        i_AttnData.targetHndl = d.targetHndl;
                                        l_attnFound = true;
                                        // handle the one attention
                                        break;
                                    } // end if valid memory buffer target

                                } // end if active DMI Interrupt

                            } // end for loop thru all potential DMI interrupts

                        } // if ok reading mask data
                        else
                        {
                            ATTN_ERR("Mem:Resolve FirMask Fail Addr:%08X",
                                 ATTN_MEM_CHIPLET_FIRS[l_cFir].chipletFirMask);
                        } // end else failed reading mask

                    } // if ok reading FIR data
                    else
                    {
                        ATTN_ERR("Mem:Resolve Fir Fail Addr:%08X",
                                 ATTN_MEM_CHIPLET_FIRS[l_cFir].chipletFir);
                    } // end else failed reading FIR

                    // Handle any elog
                    if (NULL != l_err)
                    {
                        l_err->collectTrace("ATTN_SLOW" , 512 );
                        l_err->collectTrace("ATTN_ERR" , 512 );
                        errlCommit(l_err, ATTN_COMP_ID);
                    }  // if elog

                    // Found attn match so get out
                    break;
                } // end if attention matches

                else if (UNIT_CS == i_AttnData.attnType)
                {
                    // ------------------------------------------------------
                    // The membuf may not be able to set the chkstop bit in
                    // CHIFIR under these circumstances. Hence, we need to
                    // see if there are any unit chkstops present in CHIFIR
                    // and then we'll check if the membuf has one active.
                    // ------------------------------------------------------

                    // We only know the MC chiplet at this point and
                    // so we need to check all DMI chiplets off this MC.
                    TargetHandleList  l_dmiList;
                    getChildChiplets(l_dmiList, l_mc, TYPE_DMI);

                    // Validate CHIFIR with mask/action regs
                    // using our DMI chiplet list.
                    for ( auto  l_dmiTarg : l_dmiList )
                    {
                        if (true == attnCmpAttnType(l_dmiTarg, UNIT_CS))
                        {
                            // Check the membuf to see if it chkstop'd
                            uint64_t          l_attnRaised = 0;
                            TargetHandleList  l_memBufList;
                            getChildAffinityTargets(l_memBufList, l_dmiTarg,
                                                    CLASS_CHIP, TYPE_MEMBUF);

                            if (l_memBufList.size() == 1)
                            {
                                // Check if membuf raised a matching attn
                                l_attnRaised = chkMembufAttn(l_memBufList[0],
                                                             UNIT_CS);

                                if (l_attnRaised)
                                {
                                    ATTN_SLOW(
                                    "   membuf UCS HUID:%08X Data:%016llx",
                                    get_huid(l_memBufList[0]), l_attnRaised );

                                    i_AttnData.targetHndl = l_memBufList[0];
                                    l_attnFound = true;

                                    // Exit loop on DMI targets
                                    break;

                                } // end if attn raised

                             } // end if membuf found

                        } // end if UCS active in CHIFIR

                    } // end for on DMI list

                    if (true == l_attnFound)
                    {
                        // Exit loop thru chiplet FIRs
                        // since we have valid attn to process
                        break;
                    } // end if found valid UCS on membuf

                } // end else no ATTN match but else we have UCS

            } // end for thru chiplet FIRs

            // We handle attns one at a time
            break;
        } // end if found MC chiplet

    } // end for on MC chiplets


    return l_attnFound;
}

void MemOps::resolveOcmbs( const TargetHandle_t i_proc,
                           AttentionList & io_attentions )
{

    ATTN_SLOW( "MemOps::resolveOcmbs start" );

    // Check the attribute whether we are at a point in the IPL where we can
    // get attentions from the OCMBs but will not get interrupts.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget( sys );
    assert( sys != nullptr );
    if ( 0 == sys->getAttr<ATTR_ATTN_CHK_OCMBS>() )
    {
        ATTN_SLOW( "MemOps::resolveOcmbs ATTN_CHK_OCMBS not set" );
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

    ATTN_SLOW( "MemOps::resolveOcmbs ATTN_CHK_OCMBS ocmbList size=%d",
               ocmbList.size() );
    bool attnFound = false;
    for ( const auto & ocmb : ocmbList )
    {
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
                ATTN_SLOW( "MemOps::resolveOcmbs found attn" );
                // If FIR bits are on, add the OCMB attn to the attn list
                AttnData newData( ocmb, fir.attnType );
                io_attentions.add( Attention(newData, this) );
                attnFound = true;
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
