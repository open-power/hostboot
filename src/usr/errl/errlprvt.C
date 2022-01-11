/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlprvt.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 *  @file errlprvt.C
 *
 *  @brief Implemenation of ErrlPrvt, a class for the management
 *  of the Private Header (PH) section of PEL.
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <arch/ppc.H>


namespace ERRORLOG
{


extern trace_desc_t* g_trac_errl;



/****************************************************************************/
// Constructor for the private header (PH) section of PEL.

ErrlPrvt::ErrlPrvt( compId_t  i_CreatorCompId ) :
    // contruct the ErrlSctnHdr
    iv_header( ERRL_SID_PRIVATE_HEADER,
               ErrlPrvt::SLEN,
               ErrlPrvt::VER,
               ErrlPrvt::SST,
               i_CreatorCompId ),
    iv_cid( ERRL_CID_HOSTBOOT ),  // 'B' See errlCreator_t in errltypes.H
    iv_sctns( 0 )
{
    iv_committed.date_time.value = 0; // committed time
    iv_committed.timebase = 0;
    // Ask the errl manager for the next ID to assign.
    iv_plid = iv_eid = ERRORLOG::theErrlManager::instance().getUniqueErrId();

    // Set the time of creation.
    // iv_created is in the format 0xYYYYDDMMHHMMSS00
    iv_created.timebase = getTB();
#ifndef __HOSTBOOT_RUNTIME
    // At runtime, the created timestamp will be populated at the time of commit
    iv_created.date_time = ERRORLOG::ErrlManager::getCurrentDateTime();
#endif

}


/*****************************************************************************/
// Data export.
// Flatten the data to the output pointer given as PEL as defined in
// eCLipz and P7 Platform Event Log and SRC PLDD  mcdoc 1675
// Return how many bytes flattened, or else zero for error.


uint64_t ErrlPrvt::flatten( void * o_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t  l_rc = 0;
    uint64_t  l_cb = 0;

    do
    {

        if( i_cbBuffer < iv_header.iv_slen )
        {
            TRACFCOMP( g_trac_errl, "ErrlPrvt::flatten: buffer too small");
            break;
        }

        CPPASSERT( 48 == sizeof( pelPrivateHeaderSection_t ));

        // See errltypes.H for pelPrivateHeaderSection_t
        pelPrivateHeaderSection_t * p;
        p  = static_cast<pelPrivateHeaderSection_t *>(o_pBuffer);
        memset( p, 0, sizeof( *p ));

        // Get the ErrlSctnHdr to flatten its data first.
        l_cb = iv_header.flatten( &p->sectionheader, i_cbBuffer );
        if( 0 == l_cb )
        {
            // Rare.
            TRACFCOMP(g_trac_errl,"ErrlPrvt::flatten: header.flatten problem");
            break;
        }

        // Set the ErrlPrvt instance data items.
#ifndef __HOSTBOOT_RUNTIME
        // Since Hostboot needs to add elapsed seconds to the base date time
        // it gets from BMC, we need to convert the resulting timestamp from
        // decimal to raw BCD format here to display it correctly in the error
        // log.
        p->creationTime   = ErrlManager::dateTimeToRawBCD(iv_created.date_time);
        p->commitTime     = ErrlManager::dateTimeToRawBCD(iv_committed.date_time);
#else
        // Runtime code asks for the BCD date/time directly (it does not need to
        // do any calculations on the date time it receives from PHYP), so we
        // don't need to convert the value here for runtime.
        p->creationTime   = iv_created.date_time.value;
        p->commitTime     = iv_committed.date_time.value;
#endif
        p->creatorId      = iv_cid;
        p->sectionCount   = iv_sctns;
        p->plid           = iv_plid;
        p->eid            = iv_eid;

        // return amount of bytes flattened
        l_rc = iv_header.iv_slen;
    }
    while( 0 );

    return l_rc;
}

uint64_t ErrlPrvt::unflatten( const void * i_buf )
{
    const pelPrivateHeaderSection_t * p =
        static_cast<const pelPrivateHeaderSection_t *>(i_buf);

    iv_header.unflatten(&(p->sectionheader));

    iv_created.date_time.value    = p->creationTime;
    iv_committed.date_time.value  = p->commitTime;
    iv_cid                       = p->creatorId;
    iv_sctns                     = p->sectionCount;
    iv_plid                      = p->plid;
    iv_eid                       = p->eid;

    return flatSize();
}

} // namespace
