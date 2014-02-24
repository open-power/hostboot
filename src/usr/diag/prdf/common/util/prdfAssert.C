/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfAssert.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#define prdfAssert_C

#include <prdfAssert.h>
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <stdlib.h>
#include <errlentry.H>
#include <prdf_service_codes.H>
#include <prdfMain.H>
#include <prdfErrlUtil.H>

#ifdef  __HOSTBOOT_MODULE
  #include <assert.h>
  #include <stdio.h>
#else
  #include <perc.H>
#endif

#undef prdfAssert_C

namespace PRDF
{
//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

void prdfAssert( const char * i_exp, const char * i_file, int i_line )
{
    PRDF_ERR( "prdfAssert(%s) in %s line %d", i_exp, i_file, i_line );

    errlHndl_t errl = NULL;

    /*@
     * @errortype
     * @subsys     EPUB_FIRMWARE_SP
     * @reasoncode PRDF_CODE_FAIL
     * @moduleid   PRDF_ASSERT
     * @userdata1  0
     * @userdata2  Line number of the assert
     * @userdata3  0
     * @userdata4  PRD Return code
     * @devdesc    PRD assert
     * @custDesc   An internal firmware fault.
     * @procedure  EPUB_PRC_SP_CODE
     */
    PRDF_CREATE_ERRL(errl,
                     ERRL_SEV_PREDICTIVE,         // error on diagnostic
                     ERRL_ETYPE_NOT_APPLICABLE,
                     SRCI_ERR_INFO,
                     SRCI_NO_ATTR,
                     PRDF_ASSERT,                 // module id
                     FSP_DEFAULT_REFCODE,         // refcode
                     PRDF_CODE_FAIL,              // Reason code
                     0,                           // user data word 1
                     i_line,                      // user data word 2
                     0,                           // user data word 3
                     PRD_ASSERT);                 // user data word 4

    PRDF_ADD_PROCEDURE_CALLOUT(errl, SRCI_PRIORITY_MED, EPUB_PRC_SP_CODE);
    PRDF_SET_RC(errl, PRD_ASSERT);
    PRDF_COLLECT_TRACE(errl, 256);
    PRDF_SET_TERM_STATE( errl );
    PRDF_COMMIT_ERRL(errl, ERRL_ACTION_SA);

    #ifdef  __HOSTBOOT_MODULE

    assert(0);

    #else

    const size_t sz_msg = 160;
    char msg[sz_msg];
    errlslen_t msize = snprintf( msg, sz_msg, "prdfAssert(%s) in %s line %d",
                                 i_exp, i_file, i_line );

    percAbend(PRDF_COMP_ID, msg, msize+1, 0, 0);
    abort();

    #endif
}

} // end namespace PRDF

