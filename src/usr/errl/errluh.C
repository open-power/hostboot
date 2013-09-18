/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errluh.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
  iv_ssid( EPUB_FIRMWARE_SUBSYS  ),   // 0x80 here yields SRC B180xxxx
  iv_domain( ERRL_DOMAIN_DEFAULT ),
  iv_vector( ERRL_VECTOR_DEFAULT ),
  iv_actions( ERRL_ACTION_NONE ),
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

}  // namespace
