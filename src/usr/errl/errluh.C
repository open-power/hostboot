/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errluh.C $                                       */
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
 *  @file errluh.C
 *
 *  @brief  Code to manage the contents of the user header
 *  section of an error log.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>




namespace ERRORLOG
{


extern trace_desc_t* g_trac_errl;


/*****************************************************************************/
// Constructor

ErrlUH::ErrlUH( errlSeverity_t i_sev  ) :
  iv_header( ERRL_SID_USER_HEADER,
             ErrlUH::SLEN,
             ErrlUH::VER,
             ErrlUH::SST,
             0),   // Component ID is zero until commit time
  iv_severity( i_sev ),
  iv_etype( ERRL_ETYPE_NOT_APPLICABLE ),
  iv_actions( ERRL_ACTIONS_NONE ),
  iv_ssid( EPUB_FIRMWARE_SUBSYS  ),   // 0x80 here yields SRC B180xxxx
  iv_domain( ERRL_DOMAIN_DEFAULT ),
  iv_vector( ERRL_VECTOR_DEFAULT ),
  iv_scope( ERRL_SCOPE_PLATFORM )
{

}



/***************************************************************************/
// Data Export

uint64_t ErrlUH::flatten( void * io_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t l_rc = 0;


    // compile-type assertion
    CPPASSERT( 24 == sizeof( pelUserHeaderSection_t ));


    if( i_cbBuffer >= iv_header.iv_slen )
    {
        pelUserHeaderSection_t * p;
        p = static_cast<pelUserHeaderSection_t*>(io_pBuffer);
        memset( p, 0, sizeof(*p));

        // Get the ErrlSctnHdr to flatten its data first.
        iv_header.flatten( &p->sectionheader, i_cbBuffer );

        // Set the ErrlUH instance data items in to the
        // flat user header PEL struct.
        p->ssid              = iv_ssid;
        p->scope             = iv_scope;
        p->sev               = iv_severity;
        p->etype             = iv_etype;
        p->domain            = iv_domain;
        p->vector            = iv_vector;
        p->actions           = iv_actions;

        // Return count of bytes flattened
        l_rc = iv_header.iv_slen;
    }
    else
    {
         TRACFCOMP( g_trac_errl, "ErrlUH::flatten: buffer too small" );
    }
    return l_rc;
}

uint64_t ErrlUH::unflatten(const void * i_buf )
{
    const pelUserHeaderSection_t * p =
        static_cast<const pelUserHeaderSection_t *>(i_buf);

    iv_header.unflatten(&(p->sectionheader));
    iv_ssid         = (epubSubSystem_t)p->ssid;
    iv_severity     = (errlSeverity_t)p->sev;

    iv_scope        = (errlScope_t)p->scope;
    iv_etype        = (errlEventType_t)p->etype;
    iv_domain       = (errlDomain_t)p->domain;
    iv_vector       = (errlVector_t)p->vector;
    iv_actions      = p->actions;

    return flatSize();
}

void ErrlUH::setInformationalEvent(errlEventType_t i_etype)
{
    // Update the event type
    iv_etype = i_etype;

    if (i_etype == ERRL_ETYPE_NOT_APPLICABLE)
    {
        if (iv_severity == ERRL_SEV_INFORMATIONAL)
        {
            iv_etype = ERRL_ETYPE_TRACING;
        }
    }
    else
    {
        iv_severity = ERRL_SEV_INFORMATIONAL;
    }
}

}  // namespace
