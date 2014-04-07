/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfMain.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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
 * @file  prdfMain.C
 * @brief PRD code used by external components.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfMain.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfExtensibleChip.H>
#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
#include <prdfMbaDomain.H>

using namespace TARGETING;
using namespace HWAS;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Platform specific helper function for PRDF::initialize()
//------------------------------------------------------------------------------

void initPlatSpecific()
{
    // Currently no-op in Hostboot.
}

//------------------------------------------------------------------------------
// External functions - declared in prdfMain.H
//------------------------------------------------------------------------------

int32_t analyzeIplCEStats( TargetHandle_t i_mba, bool &o_calloutMade )
{
    #define PRDF_FUNC "PRDF::analyzeIplCEStats"

    PRDF_ENTER( PRDF_FUNC"(0x%08x)", getHuid(i_mba) );

    PRDF_SYSTEM_SCOPE_MUTEX;

    int32_t o_rc = SUCCESS;
    o_calloutMade = false;

    ExtensibleChip * mbaChip = (ExtensibleChip *)systemPtr->GetChip( i_mba );
    CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );

    o_rc = mbadb->getIplCeStats()->analyzeStats( o_calloutMade );

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "["PRDF_FUNC"] analyzeStats() failed");

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

    PRDF_EXIT( PRDF_FUNC"(0x%08x), o_calloutMade:%u",
               getHuid(i_mba), o_calloutMade );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

errlHndl_t startScrub()
{
    #define PRDF_FUNC "[PRDF::startScrub] "

    errlHndl_t o_errl = NULL;

    int32_t l_rc = SUCCESS;
    HUID nodeId = INVALID_HUID;

    do
    {
        // Since the last refresh is in istep10 host_prd_hwreconfig,
        // it may be good to call it again here at istep16 mss_scrub
        // to remove any non-functional MBAs from PRD system model.
        o_errl = refresh();
        // This shouldn't return any error but if it does, break out
        if(NULL != o_errl)
        {
            PRDF_ERR( PRDF_FUNC"refresh() failed" );
            break;
        }

        // This is run in Hostboot so there should only be one node.
        TargetHandleList list = getFunctionalTargetList( TYPE_NODE );
        if ( 1 != list.size() )
        {
            PRDF_ERR( PRDF_FUNC"getFunctionalTargetList(TYPE_NODE) failed" );
            l_rc = FAIL; break;
        }
        nodeId = getHuid(list[0]);

        PRDF_ENTER( PRDF_FUNC"HUID=0x%08x", nodeId );

        // Start scrubbing on all MBAs.
        MbaDomain * domain = (MbaDomain *)systemPtr->GetDomain(MBA_DOMAIN);
        if ( NULL == domain )
        {
            PRDF_ERR( PRDF_FUNC"MBA_DOMAIN not found. nodeId=0x%08x", nodeId );
            l_rc = FAIL; break;
        }
        l_rc = domain->startScrub();

        PRDF_EXIT( PRDF_FUNC"HUID=0x%08x", nodeId );

    } while (0);

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

    return o_errl;

    #undef PRDF_FUNC
}

} // end namespace PRDF
