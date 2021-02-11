/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfRestoreDramRepairs.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#include "common/plat/mem/prdfMemExtraSig.H"
#include "common/plat/mem/prdfMemSymbol.H"
#include "common/plat/mem/prdfMemoryMru.H"
#include <prdfPlatServices.H>
#include <fapi2.H>

using namespace HWAS;
using namespace std;
using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace RDR // local utility functions to support PRDF::restoreDramRepairs()
{

// Creates and returns an error log.
template<TARGETING::TYPE T>
errlHndl_t createErrl( uint32_t i_reasonCode, TargetHandle_t i_trgt,
                       uint32_t i_signature )
{
    uint64_t userdata12 = PRDF_GET_UINT64_FROM_UINT32( getHuid(i_trgt), 0 );
    uint64_t userdata34 = PRDF_GET_UINT64_FROM_UINT32( i_signature,    0 );

    // Note that the error log tags are not needed because PRD uses its own
    // signature parser.

    errlHndl_t errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,  // severity
                            PRDF_RESTORE_DRAM_REPAIR,       // module ID
                            i_reasonCode,                   // reason code
                            userdata12,                     // user data 1 & 2
                            userdata34 );                   // user data 3 & 4

    // Add capture data. Need to do this now before the DIMM callouts are made
    // because the VPD is cleared if a DIMM is added to the callout list.
    MemCaptureData::addEccData<T>( i_trgt, errl );

    return errl;
}

//------------------------------------------------------------------------------

// If an error log is given, will add DRAM repairs FFDC and traces to error log,
// then commit the error log.
template<TARGETING::TYPE T>
void commitErrl( errlHndl_t i_errl, TargetHandle_t i_trgt )
{
    if ( nullptr != i_errl )
    {
        // Add traces
        i_errl->collectTrace( PRDF_COMP_NAME, 512 );

        // Commit the error log
        ERRORLOG::errlCommit( i_errl, PRDF_COMP_ID );
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __calloutDimm( errlHndl_t & io_errl, TargetHandle_t i_portTrgt,
                    TargetHandle_t i_dimmTrgt, bool i_nvdimmNoGard = false )
{
    #define PRDF_FUNC "[RDR::__calloutDimm] "

    PRDF_ASSERT( nullptr != i_portTrgt );
    PRDF_ASSERT( T == getTargetType(i_portTrgt) );

    PRDF_ASSERT( nullptr != i_dimmTrgt );
    PRDF_ASSERT( TYPE_DIMM == getTargetType(i_dimmTrgt) );

    HWAS::DeconfigEnum deconfigPolicy = HWAS::DELAYED_DECONFIG;
    HWAS::GARD_ErrorType gardPolicy   = HWAS::GARD_Predictive;

    #ifdef CONFIG_NVDIMM
    // For the "RDR: All repairs used" case, If the DIMM is an NVDIMM, change
    // the gard and deconfig options to no gard/deconfig and call
    // nvdimmNotifyProtChange to indicate a save/restore may work.
    if ( i_nvdimmNoGard )
    {
        deconfigPolicy = HWAS::NO_DECONFIG;
        gardPolicy     = HWAS::GARD_NULL;

        uint32_t l_rc = PlatServices::nvdimmNotifyProtChange( i_dimmTrgt,
            NVDIMM::NVDIMM_RISKY_HW_ERROR );
        if ( SUCCESS != l_rc )
        {
            PRDF_TRAC( PRDF_FUNC "nvdimmNotifyProtChange(0x%08x) "
                       "failed.", PlatServices::getHuid(i_dimmTrgt) );
        }
    }
    #endif

    io_errl->addHwCallout( i_dimmTrgt, HWAS::SRCI_PRIORITY_HIGH,
                           deconfigPolicy, gardPolicy );


    // Clear the VPD on this DIMM. The DIMM has been garded, but it is possible
    // the customer will want to ungard the DIMM. Without clearing the VPD, the
    // DIMM will be permanently garded because the customer has no ability to
    // clear the VPD. Therefore, we will clear the VPD on this DIMM. If the
    // customer takes the risk of ungarding the DIMM (that they should replace),
    // the repairs will need to be rediscovered.

    // Do not clear the VPD if we had an NVDIMM that we avoided garding.
    if ( !i_nvdimmNoGard )
    {
        std::vector<MemRank> ranks;
        getMasterRanks<T>( i_portTrgt, ranks, getDimmSlct(i_dimmTrgt) );

        for ( auto & rank : ranks )
        {
            if ( SUCCESS != clearBadDqBitmap(i_portTrgt, rank) )
            {
                PRDF_ERR( PRDF_FUNC "clearBadDqBitmap(0x%08x,0x%02x) failed",
                          getHuid(i_portTrgt), rank.getKey() );
                continue;
            }
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
        errlHndl_t errl = createErrl<T>( i_reasonCode, i_trgt, i_signature );
        errl->addProcedureCallout( HWAS::EPUB_PRC_LVL_SUPP,
                                   HWAS::SRCI_PRIORITY_HIGH );
        commitErrl<T>( errl, i_trgt );
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool processRepairedRanks( TargetHandle_t i_trgt, uint8_t i_repairedRankMask )
{
    #define PRDF_FUNC "[processRepairedRanks] "

    // The bits in i_repairedRankMask represent ranks that have repairs. Query
    // hardware and compare against RAS policies.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = nullptr; // Initially nullptr, will create if needed.

    do
    {
        // Keep a list of DIMMs to callout. Note that we are using a map with
        // the DIMM target as the key so that we can maintain a unique list. The
        // map value has no significance.
        std::map<TargetHandle_t, uint32_t> calloutList;

        ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip(i_trgt);

        for ( uint8_t r = 0; r < MASTER_RANKS_PER_PORT; ++r )
        {
            if ( 0 == (i_repairedRankMask & (0x80 >> r)) )
            {
                continue; // this rank didn't have any repairs
            }

            MemRank rank ( r );

            MemMark cm;
            if ( SUCCESS != MarkStore::readChipMark<T>( chip, rank, cm ) )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,0x%02x) "
                          "failed", chip->getHuid(), rank.getKey() );
                continue; // skip this rank
            }

            MemMark sm;
            if ( SUCCESS != MarkStore::readSymbolMark<T>( chip, rank, sm ) )
            {
                PRDF_ERR( PRDF_FUNC "readSymbolMark<T>(0x%08x,0x%02x) "
                          "failed", chip->getHuid(), rank.getKey() );
                continue; // skip this rank
            }

            // Check whether sparing is enabled
            // TODO RTC 210072 - support for multiple ports
            bool spareEnable = false;
            if ( SUCCESS !=
                 isDramSparingEnabled<T>(i_trgt, rank, 0, spareEnable) )
            {
                PRDF_ERR( PRDF_FUNC "isDramSparingEnabled(0x%08x, 0x%02x) "
                          "failed", getHuid(i_trgt), rank.getKey() );
                break;
            }

            // If sparing is enabled, we only check if the chip mark was used.
            // If sparing is not enabled we check if both the chip and symbol
            // marks are used.
            if ( cm.isValid() && ( sm.isValid() || spareEnable ) )
            {
                // All repairs on the rank have been used. Callout all repairs.

                if ( nullptr == errl )
                {
                    errl = createErrl<T>( PRDF_DETECTED_FAIL_HARDWARE,
                                          i_trgt, PRDFSIG_RdrRepairsUsed );
                }

                std::vector<MemSymbol> symList;
                symList.push_back( cm.getSymbol() );

                if ( sm.isValid() )
                {
                    symList.push_back( sm.getSymbol() );
                }

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
            bool nvdimmNoGard = false;
            #ifdef CONFIG_NVDIMM
            if ( isNVDIMM(dimm.first) ) nvdimmNoGard = true;
            #endif

            __calloutDimm<T>( errl, i_trgt, dimm.first, nvdimmNoGard );
        }

        // Commit the error log, if needed.
        commitErrl<T>( errl, i_trgt );

        // Commit an additional error log indicating something failed in the
        // analysis, if needed.
        commitSoftError<T>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                            PRDFSIG_RdrInternalFail, analysisErrors );
    }while(0);

    return o_calloutMade;

    #undef PRDF_FUNC
}

template
bool processRepairedRanks<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                           uint8_t i_repairedRankMask );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool processBadDimms( TargetHandle_t i_trgt, uint8_t i_badDimmMask )
{
    #define PRDF_FUNC "[processBadDimms] "

    // The bits in i_badDimmMask represent DIMMs that have exceeded the
    // available repairs. Callout these DIMMs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    errlHndl_t errl = nullptr; // Initially nullptr, will create if needed.

    // Iterate the list of all DIMMs
    TargetHandleList dimms = getConnectedChildren( i_trgt, TYPE_DIMM );
    for ( auto & dimm : dimms )
    {
        // i_badDimmMask is defined as a 2-bit mask where a bit set means that
        // DIMM had more bad bits than could be repaired. Note: the value is
        // actually a 4-bit field for use with Centaur, but we only use the
        // first 2 bits of that field here.
        uint8_t mask = 0x80 >> getDimmSlct(dimm);

        if ( 0 != (i_badDimmMask & mask) )
        {
            if ( nullptr == errl )
            {
                errl = createErrl<T>( PRDF_DETECTED_FAIL_HARDWARE,
                                      i_trgt, PRDFSIG_RdrRepairUnavail );
            }

            __calloutDimm<T>( errl, i_trgt, dimm );

            o_calloutMade = true;
        }
    }

    // Commit the error log, if needed.
    commitErrl<T>( errl, i_trgt );

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError<T>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                        PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

template
bool processBadDimms<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                      uint8_t i_badDimmMask );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
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
        MemDqBitmap bitmap;
        if ( SUCCESS != getBadDqBitmap(i_trgt, rank, bitmap) )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: TRGT=0x%08x "
                      "rank=0x%02x", getHuid(i_trgt), rank.getKey() );
            analysisErrors = true;
            continue; // skip this rank
        }
    }

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    commitSoftError<T>( PRDF_DETECTED_FAIL_SOFTWARE, i_trgt,
                        PRDFSIG_RdrInternalFail, analysisErrors );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE>
void deployDramSpares( TargetHandle_t i_trgt,
                       const std::vector<MemRank> & i_ranks );

template<>
void deployDramSpares<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                       const std::vector<MemRank> & i_ranks )
{
    for ( auto & rank : i_ranks )
    {
        MemSymbol sym = MemSymbol::fromSymbol( i_trgt, rank, 71 );

        int32_t l_rc = mssSetSteerMux<TYPE_OCMB_CHIP>(i_trgt, rank, sym);
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

template<TARGETING::TYPE T>
uint32_t restoreDramRepairs( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "PRDF::restoreDramRepairs<T>"

    PRDF_ENTER( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    bool calloutMade = false;

    do
    {
        // Will need the chip and system objects initialized for several parts
        // of this function and sub-functions.
        if ( (false == g_initialized) || (nullptr == systemPtr) )
        {
            errlHndl_t errl = noLock_initialize();
            if ( nullptr != errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to initialize PRD" );
                RDR::commitErrl<T>( errl, i_trgt );
                break;
            }
        }

        std::vector<MemRank> ranks;
        getMasterRanks<T>( i_trgt, ranks );

        bool spareDramDeploy = mnfgSpareDramDeploy();

        if ( spareDramDeploy )
        {
            // Deploy all spares for MNFG corner tests.
            RDR::deployDramSpares<T>( i_trgt, ranks );
        }

        if ( areDramRepairsDisabled() )
        {
            // DRAM Repairs are disabled in MNFG mode, so screen all DIMMs with
            // VPD information.
            if ( RDR::screenBadDqs<T>(i_trgt, ranks) )
                calloutMade = true;

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

            RDR::commitSoftError<T>( PRDF_INVALID_CONFIG, i_trgt,
                                     PRDFSIG_RdrInvalidConfig, true );

            break; // Assume user meant to disable DRAM repairs.
        }

        uint8_t rankMask = 0, dimmMask = 0;
        if ( SUCCESS != mssRestoreDramRepairs<T>( i_trgt, rankMask,
                                                  dimmMask) )
        {
            // Can't check anything if this doesn't work.
            PRDF_ERR( "[" PRDF_FUNC "] mssRestoreDramRepairs() failed" );
            break;
        }

        // Callout DIMMs with too many bad bits and not enough repairs available
        if ( RDR::processBadDimms<T>(i_trgt, dimmMask) )
            calloutMade = true;

        // Check repaired ranks for RAS policy violations.
        if ( RDR::processRepairedRanks<T>(i_trgt, rankMask) )
            calloutMade = true;

    } while(0);

    PRDF_EXIT( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    return calloutMade ? FAIL : SUCCESS;

    #undef PRDF_FUNC
}

template
uint32_t restoreDramRepairs<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt );

//------------------------------------------------------------------------------

} // end namespace PRDF

