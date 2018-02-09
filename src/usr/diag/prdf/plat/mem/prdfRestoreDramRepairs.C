/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfRestoreDramRepairs.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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

/** @file prdfDramRepairs.C */

#include <diag/prdf/prdfMain.H>
#include <prdf_service_codes.H>
#include "common/iipconst.h"
#include <iipSystem.h>
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <prdfErrlUtil.H>
#include "common/prdfEnums.H"
#include "common/plat/mem/prdfMemCaptureData.H"
#include "common/plat/mem/prdfMemDqBitmap.H"
#include "common/plat/mem/prdfMemMark.H"
#include "common/plat/mem/prdfP9McaExtraSig.H"
#include "common/plat/mem/prdfMemSymbol.H"
#include "common/plat/mem/prdfMemoryMru.H"
#include <prdfPlatServices.H>

using namespace HWAS;
using namespace std;
using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace RDR // local utility functions to support PRDF::restoreDramRepairs()
{

// Creates and returns an error log.
errlHndl_t createErrl( uint32_t i_reasonCode, TargetHandle_t i_trgt,
                       uint32_t i_signature )
{
    uint64_t userdata12 = PRDF_GET_UINT64_FROM_UINT32( getHuid(i_trgt), 0 );
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
template<TARGETING::TYPE T>
void commitErrl( errlHndl_t i_errl, TargetHandle_t i_trgt )
{
    if ( NULL != i_errl )
    {
        // Add capture data
        MemCaptureData::addEccData<T>( i_trgt, i_errl );

        // Add traces
        i_errl->collectTrace( PRDF_COMP_NAME, 512 );

        // Commit the error log
        ERRORLOG::errlCommit( i_errl, PRDF_COMP_ID );
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, DIMMS_PER_RANK D>
void __calloutDimm( errlHndl_t & io_errl, TargetHandle_t i_portTrgt,
                    TargetHandle_t i_dimmTrgt )
{
    #define PRDF_FUNC "[RDR::__calloutDimm] "

    PRDF_ASSERT( nullptr != i_portTrgt );
    PRDF_ASSERT( T == getTargetType(i_portTrgt) );

    PRDF_ASSERT( nullptr != i_dimmTrgt );
    PRDF_ASSERT( TYPE_DIMM == getTargetType(i_dimmTrgt) );

    // Callout the DIMM.
    io_errl->addHwCallout( i_dimmTrgt, HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DELAYED_DECONFIG, HWAS::GARD_Predictive );

    // Clear the VPD on this DIMM. The DIMM has been garded, but it is possible
    // the customer will want to ungard the DIMM. Without clearing the VPD, the
    // DIMM will be permanently garded because the customer has no ability to
    // clear the VPD. Therefore, we will clear the VPD on this DIMM. If the
    // customer takes the risk of ungarding the DIMM (that they should replace),
    // the repairs will need to be rediscovered.

    std::vector<MemRank> ranks;
    getMasterRanks<T>( i_portTrgt, ranks, getDimmSlct<T>(i_dimmTrgt) );

    uint8_t data[D][DQ_BITMAP::BITMAP_SIZE];
    memset( data, 0x00, sizeof(data) );

    for ( auto & rank : ranks )
    {
        MemDqBitmap<D> dqBitmap { i_portTrgt, rank, data };

        if ( SUCCESS != setBadDqBitmap<D>(i_portTrgt, rank, dqBitmap) )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap<%d>(0x%08x,0x%02x) failed",
                      D, getHuid(i_portTrgt), rank.getKey() );
            continue;
        }
    }

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// If there were analysis errors, will create and commit an error log with 2nd
// level support callout.
template<TARGETING::TYPE T>
void commitSoftError( uint32_t i_reasonCode, TargetHandle_t i_trgt,
                      uint32_t i_signature, bool i_analysisErrors )
{
    if ( i_analysisErrors )
    {
        errlHndl_t errl = createErrl( i_reasonCode, i_trgt, i_signature );
        errl->addProcedureCallout( HWAS::EPUB_PRC_LVL_SUPP,
                                   HWAS::SRCI_PRIORITY_HIGH );
        commitErrl<T>( errl, i_trgt );
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool processRepairedRanks( TargetHandle_t i_trgt, uint8_t i_repairedRankMask );

template<>
bool processRepairedRanks<TYPE_MCA>( TargetHandle_t i_trgt,
                                     uint8_t i_repairedRankMask )
{
    #define PRDF_FUNC "[processRepairedRanks] "

    // The bits in i_repairedRankMask represent ranks that have repairs. Query
    // hardware and compare against RAS policies.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    do
    {
        if ( (false == g_initialized) || (nullptr == systemPtr) )
        {
            errl = noLock_initialize();
            if ( nullptr != errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to initialize PRD" );
                break;
            }
        }

        // Keep a list of DIMMs to callout. Note that we are using a map with
        // the DIMM target as the key so that we can maintain a unique list. The
        // map value has no significance.
        std::map<TargetHandle_t, uint32_t> calloutList;

        ExtensibleChip * mcaChip = (ExtensibleChip *)systemPtr->GetChip(i_trgt);

        for ( uint8_t r = 0; r < MASTER_RANKS_PER_PORT; ++r )
        {
            if ( 0 == (i_repairedRankMask & (0x80 >> r)) )
            {
                continue; // this rank didn't have any repairs
            }

            MemRank rank ( r );

            MemMark cm;
            if ( SUCCESS != MarkStore::readChipMark<TYPE_MCA>( mcaChip, rank,
                                                               cm ) )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MCA>(0x%08x,0x%02x) "
                          "failed", mcaChip->getHuid(), rank.getKey() );
                continue; // skip this rank
            }

            MemMark sm;
            if ( SUCCESS != MarkStore::readSymbolMark<TYPE_MCA>( mcaChip, rank,
                                                                 sm ) )
            {
                PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_MCA>(0x%08x,0x%02x) "
                          "failed", mcaChip->getHuid(), rank.getKey() );
                continue; // skip this rank
            }

            if ( cm.isValid() && sm.isValid() ) // CM and SM used
            {
                // All repairs on the rank have been used. Callout all repairs.

                if ( NULL == errl )
                {
                    errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_trgt,
                                       PRDFSIG_RdrRepairsUsed );
                }

                std::vector<MemSymbol> symList;
                symList.push_back( cm.getSymbol() );
                symList.push_back( sm.getSymbol() );

                for ( auto & sym : symList )
                {
                    if ( !sym.isValid() ) continue;

                    MemoryMru mm( i_trgt, rank, sym );

                    // Add all parts to the error log.
                    for ( auto & dimm : mm.getCalloutList() )
                    {
                        calloutList[dimm] = 1;
                    }

                    // Add the MemoryMru to the capture data.
                    MemCaptureData::addExtMemMruData( mm, errl );
                }

                o_calloutMade = true;
            }
        }

        // Callout all DIMMs in the map.
        for ( auto const & dimm : calloutList )
        {
            __calloutDimm<TYPE_MCA, DIMMS_PER_RANK::MCA>( errl, i_trgt,
                                                          dimm.first );
        }

        // Commit the error log, if needed.
        commitErrl<TYPE_MCA>( errl, i_trgt );

        // Commit an additional error log indicating something failed in the
        // analysis, if needed.
        commitSoftError<TYPE_MCA>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
            PRDFSIG_RdrInternalFail, analysisErrors );
    }while(0);

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
bool processRepairedRanks<TYPE_MBA>( TargetHandle_t i_trgt,
                                     uint8_t i_repairedRankMask )
{
    #define PRDF_FUNC "[processRepairedRanks] "

    // The bits in i_repairedRankMask represent ranks that have repairs. Query
    // hardware and compare against RAS policies.

    bool o_calloutMade  = false;

    /* TODO RTC 178743
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    bool isCen = false;
    int32_t l_rc = isMembufOnDimm( i_mba, isCen );
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "isMembufOnDimm() failed" );
        analysisErrors = true;
    }
    else
    {
        bool isX4 = isDramWidthX4( i_mba );

        for ( uint8_t r = 0; r < MASTER_RANKS_PER_PORT; ++r )
        {
            if ( 0 == (i_repairedRankMask & (0x80 >> r)) )
            {
                continue; // this rank didn't have any repairs
            }

            CenRank rank ( r );
            CenMark mark;

            if ( SUCCESS != mssGetMarkStore(i_mba, rank, mark) )
            {
                PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed: MBA=0x%08x "
                          "rank=%d", getHuid(i_mba), rank.getMaster() );
                analysisErrors = true;
                continue; // skip this rank
            }

            CenSymbol sp0, sp1, ecc;

            if ( SUCCESS != mssGetSteerMux(i_mba, rank, sp0, sp1, ecc) )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed: MBA=0x%08x "
                          "rank=%d", getHuid(i_mba), rank.getMaster() );
                analysisErrors = true;
                continue; // skip this rank
            }

            bool isCm  = mark.getCM().isValid();            // chip mark
            bool isSm  = mark.getSM().isValid();            // symbol mark
            bool isSp  = (sp0.isValid() || sp1.isValid());  // either DRAM spare
            bool isEcc = ecc.isValid();                     // ECC spare

            if ( isCm &&                                    // CM used
                 ( ( isCen && isSp && (!isX4 || isEcc)) ||  // all spares used
                   (!isCen &&         ( isSm || isEcc)) ) ) // SM or ECC used
            {
                // All repairs on the rank have been used. Callout all repairs.

                if ( NULL == errl )
                {
                    errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_mba,
                                       PRDFSIG_RdrRepairsUsed );
                }

                std::vector<CenSymbol> list;
                list.push_back( mark.getCM() );
                list.push_back( mark.getSM() );
                list.push_back( sp0          );
                list.push_back( sp1          );
                list.push_back( ecc          );

                for ( std::vector<CenSymbol>::iterator it = list.begin();
                      it != list.end(); it++ )
                {
                    if ( !it->isValid() ) continue;

                    // Add all parts to the error log.
                    TargetHandleList partList = i_memmru.getCalloutList();
                    for ( auto &part : partList )
                    {
                        errl->addHwCallout( part, MRU_HIGH,
                                            HWAS::DELAYED_DECONFIG,
                                            HWAS::GARD_Predictive );
                    }

                    // Add the MemoryMru to the capture data.
                    MemCaptureData::addExtMemMruData( i_memmru, errl );
                }

                o_calloutMade = true;
            }
        }
    }

    // Commit the error log, if needed.
    commitErrl( errl, i_mba );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                     PRDFSIG_RdrInternalFail, analysisErrors );
    */

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------


template<TARGETING::TYPE T>
bool processBadDimms( TargetHandle_t i_trgt, uint8_t i_badDimmMask );

template<>
bool processBadDimms<TYPE_MCA>( TargetHandle_t i_trgt, uint8_t i_badDimmMask )
{
    #define PRDF_FUNC "[processBadDimms] "

    // The bits in i_badDimmMask represent DIMMs that have exceeded the
    // available repairs. Callout these DIMMs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    // Iterate the list of all DIMMs
    TargetHandleList dimms = getConnected( i_trgt, TYPE_DIMM );
    for ( auto & dimm : dimms )
    {
        // i_badDimmMask is defined as a 2-bit mask where a bit set means that
        // DIMM had more bad bits than could be repaired. Note: the value is
        // actually a 4-bit field for use with Centaur, but we only use the
        // first 2 bits of that field here.
        uint8_t mask = 0x80 >> getDimmSlct<TYPE_MCA>(dimm);

        if ( 0 != (i_badDimmMask & mask) )
        {
            if ( NULL == errl )
            {
                errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_trgt,
                                   PRDFSIG_RdrRepairUnavail );
            }

            __calloutDimm<TYPE_MCA, DIMMS_PER_RANK::MCA>( errl, i_trgt, dimm );

            o_calloutMade = true;
        }
    }

    // Commit the error log, if needed.
    commitErrl<TYPE_MCA>( errl, i_trgt );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError<TYPE_MCA>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                               PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
bool processBadDimms<TYPE_MBA>( TargetHandle_t i_trgt, uint8_t i_badDimmMask )
{
    #define PRDF_FUNC "[processBadDimms] "

    // The bits in i_badDimmMask represent DIMMs that have exceeded the
    // available repairs. Callout these DIMMs.

    bool o_calloutMade  = false;

    /* TODO RTC 178743
    bool analysisErrors = false;

    errlHndl_t errl = NULL; // Initially NULL, will create if needed.

    // Iterate the list of all DIMMs be
    TargetHandleList dimms = getConnected( i_mba, TYPE_DIMM );
    for ( TargetHandleList::iterator i = dimms.begin(); i < dimms.end(); i++ )
    {
        uint8_t port = 0, dimm = 0;

        if ( SUCCESS != getMbaPort(*i, port) )
        {
            PRDF_ERR( PRDF_FUNC "getMbaPort() failed: DIMM=0x%08x", getHuid(*i));
            analysisErrors = true;
            continue; // skip this dimm
        }

        if ( SUCCESS != getMbaDimm(*i, dimm) )
        {
            PRDF_ERR( PRDF_FUNC "getMbaDimm() failed: DIMM=0x%08x", getHuid(*i));
            analysisErrors = true;
            continue; // skip this dimm
        }

        // The 4 bits of i_badDimmMask is defined as p0d0, p0d1, p1d0, and p1d1.
        uint8_t mask = 0x8 >> (port * MBA_DIMMS_PER_RANK + dimm);

        if ( 0 != (i_badDimmMask & mask) )
        {
            if ( NULL == errl )
            {
                errl = createErrl( PRDF_DETECTED_FAIL_HARDWARE, i_mba,
                                   PRDFSIG_RdrRepairUnavail );
            }

            o_calloutMade = true;
            errl->addHwCallout( *i, MRU_HIGH, HWAS::DELAYED_DECONFIG,
                                HWAS::GARD_Predictive );
        }
    }

    // Commit the error log, if needed.
    commitErrl( errl, i_mba );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_mba,
                     PRDFSIG_RdrInternalFail, analysisErrors );
    */

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<DIMMS_PER_RANK T>
bool screenBadDqs( TargetHandle_t i_trgt, const std::vector<MemRank> & i_ranks )
{
    #define PRDF_FUNC "[screenBadDqs<T>] "

    // Callout any attached DIMMs that have any bad DQs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    for ( auto & rank : i_ranks )
    {
        // The HW procedure to read the bad DQ attribute will callout the DIMM
        // if it has DRAM Repairs VPD and the DISABLE_DRAM_REPAIRS MNFG policy
        // flag is set. PRD will simply need to iterate through all the ranks
        // to ensure all DIMMs are screen and the procedure will do the rest.

        MemDqBitmap<T> bitmap;
        if ( SUCCESS != getBadDqBitmap<T>(i_trgt, rank, bitmap) )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: TRGT=0x%08x "
                      "rank=0x%02x", getHuid(i_trgt), rank.getKey() );
            analysisErrors = true;
            continue; // skip this rank
        }
    }

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    if ( DIMMS_PER_RANK::MBA == T )
    {
        commitSoftError<TYPE_MBA>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                                   PRDFSIG_RdrInternalFail, analysisErrors );
    }
    else
    {
        commitSoftError<TYPE_MCA>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                                   PRDFSIG_RdrInternalFail, analysisErrors  );
    }

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void deployDramSpares( TargetHandle_t i_mba,
                       const std::vector<CenRank> & i_ranks )
{
    /* TODO RTC 178743
    bool x4 = isDramWidthX4(i_mba);

    bool cenDimm = false;
    if ( SUCCESS != isMembufOnDimm(i_mba, cenDimm) )
    {
        // Traces will be printed. Assume no spare DRAMs for now.
        cenDimm = false;
    }

    for ( std::vector<CenRank>::const_iterator rank = i_ranks.begin();
          rank != i_ranks.end(); rank++ )
    {
        // Doesn't matter which DRAM is spared as long as they are all spared.
        // Also, make sure the ECC spare is on a different DRAM than the spare
        // DRAM.
        CenSymbol symPort0 = CenSymbol::fromSymbol( i_mba, *rank, 71 );
        CenSymbol symPort1 = CenSymbol::fromSymbol( i_mba, *rank, 53 );
        CenSymbol symEccSp = CenSymbol::fromSymbol( i_mba, *rank, 67 );

        int32_t l_rc = SUCCESS;

        if ( cenDimm )
        {
            l_rc |= mssSetSteerMux( i_mba, *rank, symPort0, false );
            l_rc |= mssSetSteerMux( i_mba, *rank, symPort1, false );
        }

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
    */
}

} // end namespace RDR

//------------------------------------------------------------------------------
// External functions - declared in prdfMain.H
//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t restoreDramRepairs( TargetHandle_t i_trgt );

template<>
uint32_t restoreDramRepairs<TYPE_MCA>( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "PRDF::restoreDramRepairs<TYPE_MCA>"

    PRDF_ENTER( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    bool calloutMade = false;

    do
    {
        std::vector<MemRank> ranks;
        getMasterRanks<TYPE_MCA>( i_trgt, ranks );

        if ( areDramRepairsDisabled() )
        {
            // DRAM Repairs are disabled in MNFG mode, so screen all DIMMs with
            // VPD information.
            if ( RDR::screenBadDqs<DIMMS_PER_RANK::MCA>(i_trgt, ranks) )
                calloutMade = true;

            // No need to continue because there will not be anything to
            // restore.
            break;
        }

        uint8_t rankMask = 0, dimmMask = 0;
        if ( SUCCESS != mssRestoreDramRepairs<TYPE_MCA>(i_trgt, rankMask,
                                                                dimmMask) )
        {
            // Can't check anything if this doesn't work.
            PRDF_ERR( "[" PRDF_FUNC "] mssRestoreDramRepairs() failed" );
            break;
        }

        // Callout DIMMs with too many bad bits and not enough repairs available
        if ( RDR::processBadDimms<TYPE_MCA>(i_trgt, dimmMask) )
            calloutMade = true;

        // Check repaired ranks for RAS policy violations.
        if ( RDR::processRepairedRanks<TYPE_MCA>(i_trgt, rankMask) )
            calloutMade = true;

    } while(0);

    PRDF_EXIT( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    return calloutMade ? FAIL : SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t restoreDramRepairs<TYPE_MBA>( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "PRDF::restoreDramRepairs<TYPE_MBA>"

    PRDF_ENTER( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    bool calloutMade = false;

    /* TODO RTC 178743
    do
    {
        std::vector<CenRank> ranks;
        int32_t l_rc = getMasterRanks( i_trgt, ranks );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( "[" PRDF_FUNC "] getMasterRanks() failed" );

            RDR::commitSoftError( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                                  PRDFSIG_RdrInternalFail, true );

            break; // Assume user meant to disable DRAM repairs.
        }

        bool spareDramDeploy = mnfgSpareDramDeploy();

        if ( spareDramDeploy )
        {
            // Deploy all spares for MNFG corner tests.
            RDR::deployDramSpares( i_trgt, ranks );
        }

        if ( areDramRepairsDisabled() )
        {
            // DRAM Repairs are disabled in MNFG mode, so screen all DIMMs with
            // VPD information.
            if ( RDR::screenBadDqs(i_trgt, ranks) ) calloutMade = true;

            // No need to continue because there will not be anything to
            // restore.
            break;
        }

        if ( spareDramDeploy )
        {
            // This is an error. The MNFG spare DRAM deply bit is set, but DRAM
            // Repairs have not been disabled.

            PRDF_ERR( "[" PRDF_FUNC "] MNFG spare deploy enabled, but DRAM "
                      "repairs are not disabled" );

            RDR::commitSoftError( PRDF_INVALID_CONFIG, i_trgt,
                                  PRDFSIG_RdrInvalidConfig, true );

            break; // Assume user meant to disable DRAM repairs.
        }

        uint8_t rankMask = 0, dimmMask = 0;
        if ( SUCCESS != mssRestoreDramRepairs(i_trgt, rankMask, dimmMask) )
        {
            // Can't check anything if this doesn't work.
            PRDF_ERR( "[" PRDF_FUNC "] mssRestoreDramRepairs() failed" );
            break;
        }

        // Callout DIMMs with too many bad bits and not enough repairs available
        if ( RDR::processBadDimms(i_trgt, dimmMask) ) calloutMade = true;

        // Check repaired ranks for RAS policy violations.
        if ( RDR::processRepairedRanks(i_trgt, rankMask) ) calloutMade = true;

    } while(0);
    */

    PRDF_EXIT( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    return calloutMade ? FAIL : SUCCESS;

    #undef PRDF_FUNC
}


} // end namespace PRDF

