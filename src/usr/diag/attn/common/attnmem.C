/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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

// Attention bit positions in CHIFIR 16, 19,20,21
const uint64_t  ATTN_CEN_CHECKSTOP = 0x0000800000000000ull ;
const uint64_t  ATTN_CEN_RECOV     = 0x0000100000000000ull ;
const uint64_t  ATTN_CEN_SPECIAL   = 0x0000080000000000ull ;
const uint64_t  ATTN_CEN_MAINT_CMD = 0x0000040000000000ull ;



// @TODO RTC: 180469
//  Move to target services part and then update all the CXX testing
TargetHandle_t attnGetMembuf( const TargetHandle_t &i_mc,
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
                    errlCommit(l_err, ATTN_COMP_ID);
                }  // if elog

            } // end one membuf found

        } // end if correct DMI target

    } // end for on DMI targets


    return(membuf);

} // end attnGetMembuf


bool MemOps::resolve(
        PRDF::AttnData &  i_AttnData,
        const uint32_t  i_mcNumber )
{
    errlHndl_t  l_err = 0;
    bool        l_attnFound = false;
    uint64_t    l_firData  = 0;
    uint64_t    l_maskData = 0;
    uint64_t    l_intData  = 0;
    uint32_t    l_mcNum    = 0;
    uint32_t    l_dmi_0to7 = 0;


    TargetHandleList l_mcTargetList;
    getAllChiplets(l_mcTargetList, TYPE_MC, true );

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
                                        ATTN_TRACE(
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
                        errlCommit(l_err, ATTN_COMP_ID);
                    }  // if elog

                    // Found attn match so get out
                    break;
                } // end if attention matches

            } // end for thru chiplet FIRs

            // We handle attns one at a time
            break;
        } // end if found MC chiplet

    } // end for on MC chiplets


    return l_attnFound;
}

MemOps::MemOps()
{

}

MemOps::~MemOps()
{

}
}
