/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfRestoreDramRepairs.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
                       uint32_t i_signature, uint8_t i_port )
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
void __calloutDimm( errlHndl_t & io_errl, TargetHandle_t i_ocmbTrgt,
    TargetHandle_t i_dimmTrgt, bool i_nvdimmNoGard = false );

template<>
void __calloutDimm<TYPE_OCMB_CHIP>( errlHndl_t & io_errl,
    TargetHandle_t i_ocmbTrgt, TargetHandle_t i_dimmTrgt, bool i_nvdimmNoGard )
{
    #define PRDF_FUNC "[RDR::__calloutDimm] "

    PRDF_ASSERT( nullptr != i_ocmbTrgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmbTrgt) );

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

        TargetHandle_t memport = getConnectedParent(i_dimmTrgt, TYPE_MEM_PORT);
        uint8_t port = memport->getAttr<ATTR_REL_POS>();
        getMasterRanks<TYPE_OCMB_CHIP>( i_ocmbTrgt, port, ranks,
                                        getDimmSlct(i_dimmTrgt) );

        for ( const auto & rank : ranks )
        {
            if ( SUCCESS != clearBadDqBitmap<TYPE_MEM_PORT>(memport, rank) )
            {
                PRDF_ERR( PRDF_FUNC "clearBadDqBitmap(0x%08x,0x%02x) failed",
                          getHuid(memport), rank.getKey() );
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
                      uint32_t i_signature, bool i_analysisErrors,
                      uint8_t i_port )
{
    if ( i_analysisErrors )
    {
        errlHndl_t errl = createErrl<T>( i_reasonCode, i_trgt, i_signature,
                                         i_port );
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

            // The i_repairedRankMask we get back from the HWP does not specify
            // which port the repair was on, so we check both for repairs.
            uint8_t maxPorts = MAX_PORT_PER_EXP_OCMB;
            if (isOdysseyOcmb(i_trgt))
            {
                maxPorts = MAX_PORT_PER_ODY_OCMB;
            }

            for (uint8_t port = 0; port < maxPorts; port++)
            {
                // Double check the MEM_PORT target actually exists
                TargetHandle_t memport = getConnectedChild(i_trgt,
                                                           TYPE_MEM_PORT, port);
                if (nullptr == memport) continue;

                MemMark cm;
                if (SUCCESS != MarkStore::readChipMark<T>(chip, rank, port, cm))
                {
                    PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,0x%02x,%x) "
                            "failed", chip->getHuid(), rank.getKey(), port );
                    continue; // skip this rank
                }

                MemMark sm;
                if (SUCCESS != MarkStore::readSymbolMark<T>(chip, rank, port,
                                                            sm))
                {
                    PRDF_ERR( PRDF_FUNC "readSymbolMark<T>(0x%08x,0x%02x,%x) "
                            "failed", chip->getHuid(), rank.getKey(), port );
                    continue; // skip this rank
                }

                // Check whether sparing is enabled
                bool spareEnable = false;
                if ( SUCCESS != isDramSparingEnabled<T>(i_trgt, rank, port,
                                                        spareEnable) )
                {
                    PRDF_ERR(PRDF_FUNC "isDramSparingEnabled(0x%08x,0x%02x,%x) "
                             "failed", getHuid(i_trgt), rank.getKey(), port);
                    break;
                }

                // If sparing is enabled, we only check if the chip mark was
                // used. If sparing is not enabled we check if both the chip and
                // symbol marks are used.
                if ( cm.isValid() && ( sm.isValid() || spareEnable ) )
                {
                    // All repairs on the rank have been used. Callout all repairs.

                    if ( nullptr == errl )
                    {
                        errl = createErrl<T>( PRDF_DETECTED_FAIL_HARDWARE,
                                              i_trgt, PRDFSIG_RdrRepairsUsed,
                                              port );
                    }

                    std::vector<MemSymbol> symList;
                    symList.push_back( cm.getSymbol() );

                    if ( sm.isValid() )
                    {
                        symList.push_back( sm.getSymbol() );
                    }

                    for ( const auto & sym : symList )
                    {
                        if ( !sym.isValid() ) continue;

                        MemoryMru mm( i_trgt, rank, port, sym );

                        // Add all parts to the error log.
                        for ( const auto & dimm : mm.getCalloutList() )
                        {
                            calloutList[dimm] = 1;
                        }

                        // Add the MemoryMru to the capture data.
                        MemCaptureData::addExtMemMruData( mm, errl );
                    }

                    o_calloutMade = true;
                }
            }
        }

        // Callout all DIMMs in the map.
        for ( const auto & dimm : calloutList )
        {
            bool nvdimmNoGard = false;
            #ifdef CONFIG_NVDIMM
            if ( isNVDIMM(dimm.first) ) nvdimmNoGard = true;
            #endif

            __calloutDimm<T>( errl, i_trgt, dimm.first, nvdimmNoGard );
        }

        // Commit the error log, if needed.
        commitErrl<T>( errl, i_trgt );

    }while(0);

    return o_calloutMade;

    #undef PRDF_FUNC
}

template
bool processRepairedRanks<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                           uint8_t i_repairedRankMask );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool processBadDimms( TargetHandle_t i_trgt, uint8_t i_badDimmMask );

template<>
bool processBadDimms<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                      uint8_t i_badDimmMask )
{
    #define PRDF_FUNC "[processBadDimms] "

    // The bits in i_badDimmMask represent DIMMs that have exceeded the
    // available repairs. Callout these DIMMs.

    bool o_calloutMade  = false;

    errlHndl_t errl = nullptr; // Initially nullptr, will create if needed.

    // Iterate the list of all DIMMs
    TargetHandleList dimms = getConnectedChildren( i_trgt, TYPE_DIMM );
    for ( const auto & dimm : dimms )
    {
        // i_badDimmMask is defined as a 2-bit (left-justified) mask where a bit
        // set means that DIMM had more bad bits than could be repaired.
        // For Odyssey this means the first bit indicates the DIMM on port0 and
        // the second bit indicates the DIMM on port1, so we need to shift based
        // on the port value.
        uint8_t mask = 0x80 >> getDimmPort(dimm);

        if ( 0 != (i_badDimmMask & mask) )
        {
            if ( nullptr == errl )
            {
                uint8_t port = getDimmPort(dimm);
                errl = createErrl<TYPE_OCMB_CHIP>( PRDF_DETECTED_FAIL_HARDWARE,
                    i_trgt, PRDFSIG_RdrRepairUnavail, port );
            }

            __calloutDimm<TYPE_OCMB_CHIP>( errl, i_trgt, dimm );

            o_calloutMade = true;
        }
    }

    // Commit the error log, if needed.
    commitErrl<TYPE_OCMB_CHIP>( errl, i_trgt );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE  T>
bool screenBadDqs(TargetHandle_t i_memport, const std::vector<MemRank> & i_ranks);

template<>
bool screenBadDqs<TYPE_MEM_PORT>( TargetHandle_t i_memport,
                                  const std::vector<MemRank> & i_ranks )
{
    #define PRDF_FUNC "[screenBadDqs<TYPE_MEM_PORT>] "

    // Callout any attached DIMMs that have any bad DQs.

    bool o_calloutMade  = false;
    bool analysisErrors = false;

    for ( const auto & rank : i_ranks )
    {
        // The HW procedure to read the bad DQ attribute will callout the DIMM
        // if it has DRAM Repairs VPD and the DISABLE_DRAM_REPAIRS MNFG policy
        // flag is set. PRD will simply need to iterate through all the ranks
        // to ensure all DIMMs are screen and the procedure will do the rest.
        MemDqBitmap bitmap;
        if ( SUCCESS != getBadDqBitmap<TYPE_MEM_PORT>(i_memport, rank, bitmap) )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: TRGT=0x%08x "
                      "rank=0x%02x", getHuid(i_memport), rank.getKey() );
            analysisErrors = true;
            continue; // skip this rank
        }
    }

    // Commit an additional error log indicating something failed in the
    // analysis, if needed.
    uint8_t port = i_memport->getAttr<ATTR_REL_POS>();
    TargetHandle_t ocmb = getConnectedParent(i_memport, TYPE_OCMB_CHIP);
    commitSoftError<TYPE_OCMB_CHIP>( PRDF_DETECTED_FAIL_SOFTWARE, ocmb,
                                     PRDFSIG_RdrInternalFail, analysisErrors,
                                     port );

    return o_calloutMade;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE>
void deployDramSpares( TargetHandle_t i_memport,
                       const std::vector<MemRank> & i_ranks );

template<>
void deployDramSpares<TYPE_MEM_PORT>( TargetHandle_t i_memport,
                                      const std::vector<MemRank> & i_ranks )
{
    for ( const auto & rank : i_ranks )
    {
        MemSymbol sym = MemSymbol::fromSymbol( i_memport, rank, 71 );

        int32_t l_rc = mssSetSteerMux<TYPE_MEM_PORT>(i_memport, rank, sym);
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

template<>
uint32_t restoreDramRepairs<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "PRDF::restoreDramRepairs<TYPE_OCMB_CHIP>"

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
                RDR::commitErrl<TYPE_OCMB_CHIP>( errl, i_trgt );
                break;
            }
        }

        std::vector<MemRank> ranks;

        // Loop through all ports
        uint8_t maxPorts = MAX_PORT_PER_EXP_OCMB;
        if (isOdysseyOcmb(i_trgt))
        {
            maxPorts = MAX_PORT_PER_ODY_OCMB;
        }

        for (uint8_t port = 0; port < maxPorts; port++)
        {
            // Check if the port target actually exists, if it doesn't, skip it.
            TargetHandle_t memport = getConnectedChild(i_trgt, TYPE_MEM_PORT,
                                                       port);
            if (nullptr == memport)
                continue;

            getMasterRanks<TYPE_OCMB_CHIP>( i_trgt, port, ranks );

            bool spareDramDeploy = mnfgSpareDramDeploy();

            if ( spareDramDeploy )
            {
                // Deploy all spares for MNFG corner tests.
                RDR::deployDramSpares<TYPE_MEM_PORT>( memport, ranks );
            }

            if ( areDramRepairsDisabled() )
            {
                // DRAM Repairs are disabled in MNFG mode, so screen all DIMMs with
                // VPD information.
                if ( RDR::screenBadDqs<TYPE_MEM_PORT>(memport, ranks) )
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

                RDR::commitSoftError<TYPE_OCMB_CHIP>( PRDF_INVALID_CONFIG,
                    i_trgt, PRDFSIG_RdrInvalidConfig, true, port );

                break; // Assume user meant to disable DRAM repairs.
            }
        }
        uint8_t rankMask = 0, dimmMask = 0;
        if ( SUCCESS != mssRestoreDramRepairs<TYPE_OCMB_CHIP>(i_trgt, rankMask,
             dimmMask) )
        {
            // Can't check anything if this doesn't work.
            PRDF_ERR( "[" PRDF_FUNC "] mssRestoreDramRepairs() failed" );
            break;
        }

        // Callout DIMMs with too many bad bits and not enough repairs available
        if ( RDR::processBadDimms<TYPE_OCMB_CHIP>(i_trgt, dimmMask) )
            calloutMade = true;

        // Check repaired ranks for RAS policy violations.
        if ( RDR::processRepairedRanks<TYPE_OCMB_CHIP>(i_trgt, rankMask) )
            calloutMade = true;

    } while(0);

    PRDF_EXIT( PRDF_FUNC "(0x%08x)", getHuid(i_trgt) );

    return calloutMade ? FAIL : SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

