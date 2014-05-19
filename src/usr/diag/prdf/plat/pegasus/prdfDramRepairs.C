/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfDramRepairs.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

/** @file prdfDramRepairs.C */

#include <diag/prdf/prdfMain.H>
#include <diag/prdf/common/prdf_service_codes.H>
#include "common/iipconst.h"
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <prdfErrlUtil.H>
#include "common/prdfEnums.H"
#include "common/plat/pegasus/prdfCenMbaCaptureData.H"
#include "common/plat/pegasus/prdfCalloutUtil.H"
#include "common/plat/pegasus/prdfCenDqBitmap.H"
#include "common/plat/pegasus/prdfCenMarkstore.H"
#include "common/plat/pegasus/prdfCenMbaExtraSig.H"
#include "common/plat/pegasus/prdfCenSymbol.H"
#include "common/plat/pegasus/prdfMemoryMru.H"
#include "framework/service/prdfPlatServices.H"
#include "plat/pegasus/prdfPlatCalloutUtil.H"

using namespace HWAS;
using namespace std;
using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace RDR // local utility functions to support PRDF::restoreDramRepairs()
{

// Creates and returns an error log.
errlHndl_t createErrl( uint32_t i_reasonCode, TargetHandle_t i_mba,
                       uint32_t i_signature )
{
    uint64_t userdata12 = PRDF_GET_UINT64_FROM_UINT32( getHuid(i_mba), 0 );
    uint64_t userdata34 = PRDF_GET_UINT64_FROM_UINT32( i_signature,    0 );

    // Note that the error log tags are not needed because PRD uses its own
    // signature parser.

    return new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,  // severity
                            PRDF_RESTORE_DRAM_REPAIR,       // module ID
                            i_reasonCode,                   // reason code
                            userdata12,                     // user data 1 & 2
                            userdata34 );                   // user data 3 & 4
}

//------------------------------------------------------------------------------

// If an error log is given, will add DRAM repairs FFDC and traces to error log,
// then commit the error log.
void commitErrl( errlHndl_t i_errl, TargetHandle_t i_mba )
{
    if ( NULL != i_errl )
    {
        // Add capture data
        CenMbaCaptureData::addMemEccData( i_mba, i_errl );

        // Add traces
        i_errl->collectTrace( PRDF_COMP_NAME, 512 );

        // Commit the error log
        ERRORLOG::errlCommit( i_errl, PRDF_COMP_ID );
    }
}

//------------------------------------------------------------------------------

// If there were analysis errors, will create and commit an error log with 2nd
// level support callout.
void commitSoftError( uint32_t i_reasonCode, TargetHandle_t i_mba,
                      uint32_t i_signature, bool i_analysisErrors )
{
    if ( i_analysisErrors )
    {
        errlHndl_t errl = createErrl( i_reasonCode, i_mba, i_signature );
        errl->addProcedureCallout( EPUB_PRC_LVL_SUPP, SRCI_PRIORITY_HIGH );
        commitErrl( errl, i_mba );
    }
}

//------------------------------------------------------------------------------

bool processRepairedRanks( TargetHandle_t i_mba, uint8_t i_repairedRankMask )
{
    #define PRDF_FUNC "[processRepairedRanks] "

    // The bits in i_repairedRankMask represent ranks that have repairs. Query
    // hardware and compare against RAS policies.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    for ( uint8_t r = 0; r < MASTER_RANKS_PER_MBA; ++r )
    {
        if ( 0 == (i_repairedRankMask & (0x80 >> r)) )
        {
            continue; // this rank didn't have any repairs
        }

        CenRank rank ( r );
        CenMark mark;

        if ( SUCCESS != mssGetMarkStore(i_mba, rank, mark) )
        {
            PRDF_ERR( PRDF_FUNC"mssGetMarkStore() failed: MBA=0x%08x rank=%d",
                      getHuid(i_mba), rank.getMaster() );
            analysisErrors = true;
            continue; // skip this rank
        }

        CenSymbol sp0, sp1, sp;

        if ( SUCCESS != mssGetSteerMux(i_mba, rank, sp0, sp1, sp))
        {
            PRDF_ERR( PRDF_FUNC"mssGetSteerMux() failed: MBA=0x%08x rank=%d",
                      getHuid(i_mba), rank.getMaster() );
            analysisErrors = true;
            continue; // skip this rank
        }

        if ( (sp0.isValid() || sp1.isValid() || sp.isValid()) &&
             mark.getCM().isValid() )
        {
            // This rank has both a steer and a chip mark. Call out the DIMM
            // with the chip mark.

            if ( NULL == errl )
            {
                errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_mba,
                                   PRDFSIG_RdrRepairsUsed );
            }

            MemoryMru memoryMru( i_mba, rank, mark.getCM() );
            CalloutUtil::calloutMemoryMru( errl, memoryMru,
                                           SRCI_PRIORITY_HIGH,
                                           HWAS::DELAYED_DECONFIG,
                                           HWAS::GARD_Predictive );
            o_calloutMade = true;
        }
    }

    // Commit the error log, if needed.
    commitErrl( errl, i_mba );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                     PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool processBadDimms( TargetHandle_t i_mba, uint8_t i_badDimmMask )
{
    #define PRDF_FUNC "[processBadDimms] "

    // The bits in i_badDimmMask represent DIMMs that have exceeded the
    // available repairs. Callout these DIMMs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    // Iterate the list of all DIMMs be
    TargetHandleList dimms = getConnected( i_mba, TYPE_DIMM );
    for ( TargetHandleList::iterator i = dimms.begin(); i < dimms.end(); i++ )
    {
        uint8_t port = 0, dimm = 0;

        if ( SUCCESS != getMbaPort(*i, port) )
        {
            PRDF_ERR( PRDF_FUNC"getMbaPort() failed: DIMM=0x%08x", getHuid(*i));
            analysisErrors = true;
            continue; // skip this dimm
        }

        if ( SUCCESS != getMbaDimm(*i, dimm) )
        {
            PRDF_ERR( PRDF_FUNC"getMbaDimm() failed: DIMM=0x%08x", getHuid(*i));
            analysisErrors = true;
            continue; // skip this dimm
        }

        // The 4 bits of i_badDimmMask is defined as p0d0, p0d1, p1d0, and p1d1.
        uint8_t mask = 0x8 >> (port * PORT_SLCT_PER_MBA + dimm);

        if ( 0 != (i_badDimmMask & mask) )
        {
            if ( NULL == errl )
            {
                errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_mba,
                                   PRDFSIG_RdrRepairUnavail );
            }

            o_calloutMade = true;
            errl->addHwCallout( *i, SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG,
                                HWAS::GARD_Predictive );
        }
    }

    // Commit the error log, if needed.
    commitErrl( errl, i_mba );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                     PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool screenBadDqs( TargetHandle_t i_mba, const std::vector<CenRank> & i_ranks )
{
    #define PRDF_FUNC "[screenBadDqs] "

    // Callout any attached DIMMs that have any bad DQs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    for ( std::vector<CenRank>::const_iterator rank = i_ranks.begin();
          rank != i_ranks.end(); rank++ )
    {
        // The HW procedure to read the bad DQ attribute will callout the DIMM
        // if it has DRAM Repairs VPD and the DISABLE_DRAM_REPAIRS MNFG policy
        // flag is set. PRD will simply need to iterate through all the ranks
        // to ensure all DIMMs are screen and the procedure will do the rest.

        CenDqBitmap bitmap;
        if ( SUCCESS != getBadDqBitmap(i_mba, *rank, bitmap, true) )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed: MBA=0x%08x rank=%d",
                      getHuid(i_mba), rank->getMaster() );
            analysisErrors = true;
            continue; // skip this rank
        }
    }

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                     PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void deployDramSpares( TargetHandle_t i_mba,
                       const std::vector<CenRank> & i_ranks )
{
    bool x4 = isDramWidthX4(i_mba);

    for ( std::vector<CenRank>::const_iterator rank = i_ranks.begin();
          rank != i_ranks.end(); rank++ )
    {
        // Doesn't matter which DRAM is spared as long as they are all spared.
        // Also, make sure the ECC spare is on a different DRAM than the spare
        // DRAM.
        CenSymbol symPort0 = CenSymbol::fromDimmDq( i_mba, *rank, 0, 0 );
        CenSymbol symPort1 = CenSymbol::fromDimmDq( i_mba, *rank, 0, 1 );
        CenSymbol symEccSp = CenSymbol::fromDimmDq( i_mba, *rank, 8, 0 );

        int32_t l_rc = SUCCESS;

        l_rc  = mssSetSteerMux( i_mba, *rank, symPort0, false );
        l_rc |= mssSetSteerMux( i_mba, *rank, symPort1, false );

        if ( x4 )
            l_rc |= mssSetSteerMux( i_mba, *rank, symEccSp, true );

        if ( SUCCESS != l_rc )
        {
            // mssSetSteerMux() will print a trace and commit the error log,
            // however, we need to handle the return code or we get a compile
            // warning in Hostboot.
            continue;
        }
    }
}

} // end namespace RDR

//------------------------------------------------------------------------------
// External functions - declared in prdfMain.H
//------------------------------------------------------------------------------

int32_t restoreDramRepairs( TargetHandle_t i_mba )
{
    #define PRDF_FUNC "PRDF::restoreDramRepairs"

    PRDF_ENTER( PRDF_FUNC"(0x%08x)", getHuid(i_mba) );

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    bool calloutMade = false;

    do
    {
        std::vector<CenRank> ranks;
        int32_t l_rc = getMasterRanks( i_mba, ranks );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( "["PRDF_FUNC"] getMasterRanks() failed" );

            RDR::commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                                  PRDFSIG_RdrInternalFail, true );

            break; // Assume user meant to disable DRAM repairs.
        }

        bool spareDramDeploy = mnfgSpareDramDeploy();

        if ( spareDramDeploy )
        {
            // Deploy all spares for MNFG corner tests.
            RDR::deployDramSpares( i_mba, ranks );
        }

        if ( areDramRepairsDisabled() )
        {
            // DRAM Repairs are disabled in MNFG mode, so screen all DIMMs with
            // VPD information.
            if ( RDR::screenBadDqs(i_mba, ranks) ) calloutMade = true;

            // No need to continue because there will not be anything to
            // restore.
            break;
        }

        if ( spareDramDeploy )
        {
            // This is an error. The MNFG spare DRAM deply bit is set, but DRAM
            // Repairs have not been disabled.

            PRDF_ERR( "["PRDF_FUNC"] MNFG spare deploy enabled, but DRAM "
                      "repairs are not disabled" );

            RDR::commitSoftError( PRDF_INVALID_CONFIG, i_mba,
                                  PRDFSIG_RdrInvalidConfig, true );

            break; // Assume user meant to disable DRAM repairs.
        }

        uint8_t rankMask = 0, dimmMask = 0;
        if ( SUCCESS != mssRestoreDramRepairs(i_mba, rankMask, dimmMask) )
        {
            // Can't check anything if this doesn't work.
            PRDF_ERR( "["PRDF_FUNC"] mssRestoreDramRepairs() failed" );
            break;
        }

        // Callout DIMMs with too many bad bits and not enough repairs available
        if ( RDR::processBadDimms(i_mba, dimmMask) ) calloutMade = true;

        // Check repaired ranks for RAS policy violations.
        if ( RDR::processRepairedRanks(i_mba, rankMask) ) calloutMade = true;

    } while(0);

    PRDF_EXIT( PRDF_FUNC"(0x%08x)", getHuid(i_mba) );

    return calloutMade ? FAIL : SUCCESS;

    #undef PRDF_FUNC
}

} // end namespace PRDF

