/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfMain_ipl.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
 * @file  prdfMain_ipl.C
 * @brief PRD code used by external components (IPL only).
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfMain.H>

//#include <prdfCenMbaDataBundle.H> TODO RTC 136128
#include <prdfExtensibleChip.H>
#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
//#include <prdfMbaDomain.H> TODO RTC 136128

// Custom compile configs
#include <config.h>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <prdfFileRegisterAccess.H>
#endif

using namespace TARGETING;
using namespace HWAS;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Forward references
//------------------------------------------------------------------------------

extern errlHndl_t noLock_refresh();

//------------------------------------------------------------------------------
// External functions - declared in prdfMain.H
//------------------------------------------------------------------------------

int32_t analyzeIplCEStats( TargetHandle_t i_mba, bool &o_calloutMade )
{
    #define PRDF_FUNC "PRDF::analyzeIplCEStats"

    int32_t o_rc = SUCCESS;

    PRDF_ENTER( PRDF_FUNC "(0x%08x)", getHuid(i_mba) );

/* TODO RTC 136128
    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    o_calloutMade = false;

    ExtensibleChip * mbaChip = (ExtensibleChip *)systemPtr->GetChip( i_mba );
    CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );

    o_rc = mbadb->getIplCeStats()->analyzeStats( o_calloutMade );

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[" PRDF_FUNC "] analyzeStats() failed");

        // Get user data
        uint64_t ud12 = PRDF_GET_UINT64_FROM_UINT32( getHuid(i_mba),      0 );
        uint64_t ud34 = PRDF_GET_UINT64_FROM_UINT32( PRDFSIG_MnfgIplFail, 0 );

        // Create error log
        errlHndl_t errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE, // severity
                                PRDF_MNFG_IPL_CE_ANALYSIS,     // module ID
                                PRDF_DETECTED_FAIL_SOFTWARE,   // reason code
                                ud12, ud34 );                  // user data 1-4

        // Add 2nd level support
        errl->addProcedureCallout( EPUB_PRC_LVL_SUPP, SRCI_PRIORITY_HIGH );

        // Add traces
        errl->collectTrace( PRDF_COMP_NAME, 512 );

        // Commit the error log
        ERRORLOG::errlCommit( errl, PRDF_COMP_ID );
    }
*/

    PRDF_EXIT( PRDF_FUNC "(0x%08x), o_calloutMade:%u",
               getHuid(i_mba), o_calloutMade );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

errlHndl_t startScrub()
{
    #define PRDF_FUNC "[PRDF::startScrub] "
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t o_errl = NULL;

    int32_t l_rc = SUCCESS;
    HUID nodeId = INVALID_HUID;

/* TODO RTC 136126
    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    do
    {
        // Since the last refresh is in istep10 host_prd_hwreconfig,
        // it may be good to call it again here at istep16 mss_scrub
        // to remove any non-functional MBAs from PRD system model.
        o_errl = noLock_refresh();
        // This shouldn't return any error but if it does, break out
        if(NULL != o_errl)
        {
            PRDF_ERR( PRDF_FUNC "noLock_refresh() failed" );
            break;
        }

        // This is run in Hostboot so there should only be one node.
        TargetHandleList list = getFunctionalTargetList( TYPE_NODE );
        if ( 1 != list.size() )
        {
            PRDF_ERR( PRDF_FUNC "getFunctionalTargetList(TYPE_NODE) failed" );
            l_rc = FAIL; break;
        }
        nodeId = getHuid(list[0]);

        PRDF_ENTER( PRDF_FUNC "HUID=0x%08x", nodeId );

        // Start scrubbing on all MBAs.
        MbaDomain * domain = (MbaDomain *)systemPtr->GetDomain(MBA_DOMAIN);
        if ( NULL == domain )
        {
            PRDF_ERR( PRDF_FUNC "MBA_DOMAIN not found. nodeId=0x%08x", nodeId );
            l_rc = FAIL; break;
        }
        l_rc = domain->startScrub();

        PRDF_EXIT( PRDF_FUNC "HUID=0x%08x", nodeId );

    } while (0);
*/

    if (( SUCCESS != l_rc ) && (NULL == o_errl))
    {
        // Get user data
        uint64_t ud12 = PRDF_GET_UINT64_FROM_UINT32( nodeId, __LINE__ );
        uint64_t ud34 = PRDF_GET_UINT64_FROM_UINT32( 0,      0        );

        // Create error log
        o_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE, // severity
                            PRDF_START_SCRUB,                 // module ID
                            PRDF_DETECTED_FAIL_SOFTWARE,      // reason code
                            ud12, ud34 );                     // user data 1-4

        // Add 2nd level support
        o_errl->addProcedureCallout( EPUB_PRC_LVL_SUPP, SRCI_PRIORITY_HIGH );

        // Add traces
        o_errl->collectTrace( PRDF_COMP_NAME, 512 );
    }

    PRDF_EXIT( PRDF_FUNC );

    return o_errl;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS

errlHndl_t analyzeCheckStop( ATTENTION_VALUE_TYPE i_attentionType,
                             const AttnList & i_attnList )
{
    PRDF_ENTER( "PRDF::analyzeCheckStop() Global attnType=%04X",
                i_attentionType );

    // install file Scom Accessor
    FileScomAccessor * fileScomAccessor = new FileScomAccessor();
    getScomService().setScomAccessor( *fileScomAccessor);

    // Call main to analyze checkstop
    errlHndl_t errl = main( i_attentionType, i_attnList );

    // Uninstall file scom. setScomAccessor() will also free up
    // memory for fileScomAccessor.
    ScomAccessor * scomAccessor = new ScomAccessor();
    getScomService().setScomAccessor( *scomAccessor);

    return errl;
}

#endif // CONFIG_ENABLE_CHECKSTOP_ANALYSIS

} // end namespace PRDF
