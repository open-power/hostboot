/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfMain_ipl.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2019                        */
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

// Framework includes
#include <iipSystem.h>
#include <prdfErrlUtil.H>
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfPlatServices.H>
#include <prdfP9McaDataBundle.H>
#include <prdfMemBgScrub.H>

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

int32_t analyzeIplCEStats( TargetHandle_t i_trgt, bool &o_calloutMade )
{
    #define PRDF_FUNC "PRDF::analyzeIplCEStats"

    PRDF_ENTER( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    PRDF_SYSTEM_SCOPELOCK; // will unlock when going out of scope

    o_calloutMade = false;

    ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip( i_trgt );
    TYPE             type = getTargetType( i_trgt );

    if ( TYPE_MCBIST == type )
    {
        // Analyze the CE stats for each MCA.
        ExtensibleChipList list = getConnected( chip, TYPE_MCA );
        for ( auto & mcaChip : list )
        {
            McaDataBundle * db = getMcaDataBundle( mcaChip );
            if ( db->getIplCeStats()->analyzeStats() ) o_calloutMade = true;
        }
    }
    else if ( TYPE_MBA == type )
    {
        // Analyze the CE stats for the MBA.
        MbaDataBundle * db = getMbaDataBundle( chip );
        o_calloutMade = db->getIplCeStats()->analyzeStats();
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "Unsupported target type %d", type );
        PRDF_ASSERT( false ); // code bug
    }

    PRDF_EXIT( PRDF_FUNC "(0x%08x), o_calloutMade:%u",
               getHuid(i_trgt), o_calloutMade );

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

errlHndl_t startScrub( const TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "[PRDF::startScrub] "
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t o_errl = nullptr;

    int32_t l_rc = SUCCESS;

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    do
    {
        // Will need the chip and system objects initialized for several parts
        // of this function and sub-functions. If this is MPIPL we may not be
        // initialized yet.
        if ( (false == g_initialized) || (nullptr == systemPtr) )
        {
            o_errl = noLock_initialize();
            if ( nullptr != o_errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to initialize PRD" );
                break;
            }
        }

        // Get the PRD chip object.
        ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip(i_trgt);
        if ( nullptr == chip )
        {
            PRDF_ERR( PRDF_FUNC "unable to find chip object for given target: "
                                "0x%08x", getHuid(i_trgt) );
            l_rc = FAIL; break;
        }

        // Start background scrubbing on this target.
        switch ( chip->getType() )
        {
            case TYPE_MBA:    startInitialBgScrub<TYPE_MBA>(   chip); break;
            case TYPE_MCBIST: startInitialBgScrub<TYPE_MCBIST>(chip); break;
            default:
                PRDF_ERR( PRDF_FUNC "Unsupported maintenance target type "
                          "0x%02x", chip->getType() );
                l_rc = FAIL;
        }
        if ( SUCCESS != l_rc ) break;

    } while (0);

    if ( SUCCESS != l_rc )
    {
        // Get user data
        uint64_t ud12 = PRDF_GET_UINT64_FROM_UINT32( getHuid(i_trgt), 0 );
        uint64_t ud34 = PRDF_GET_UINT64_FROM_UINT32( 0,               0 );

        // Create error log
        o_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE, // severity
                            PRDF_START_SCRUB,                 // module ID
                            PRDF_DETECTED_FAIL_SOFTWARE,      // reason code
                            ud12, ud34 );                     // user data 1-4

        // Add 2nd level support
        o_errl->addProcedureCallout( HWAS::EPUB_PRC_LVL_SUPP,
                                     HWAS::SRCI_PRIORITY_HIGH );

        // Add traces
        o_errl->collectTrace( PRDF_COMP_NAME,      512 );
        o_errl->collectTrace( FAPI_TRACE_NAME,     256 );
        o_errl->collectTrace( FAPI_IMP_TRACE_NAME, 256 );
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
