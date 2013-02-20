/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfDramRepairs.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file prdfDramRepairs.C */

#include <diag/prdf/prdfMain.H>
#include <diag/prdf/common/prdf_service_codes.H>
#include "common/iipconst.h"
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <prdfErrlUtil.H>
#include "common/prdfEnums.H"
#include "common/plat/pegasus/prdfCenMbaCaptureData.H"
#include "common/plat/pegasus/prdfCenSymbol.H"
#include "common/plat/pegasus/prdfMemoryMru.H"
#include "framework/service/prdfPlatServices.H"

using namespace HWAS;
using namespace std;
using namespace TARGETING;

namespace PRDF
{

static const uint8_t INVALID_SYMBOL = 0xff;

bool validSymbol(uint8_t i_symbol)
{
    return i_symbol != INVALID_SYMBOL;
}

bool commitRestoreCallout( bool (*i_func)(errlHndl_t &, void *), void * i_data,
                           TargetHandle_t i_mba )
{
    PRDF_DENTER("commitRestoreCallout");

    errlHndl_t err = NULL;
    bool o_term = false;

    PRDF_HW_CREATE_ERRL(
            err,
            ERRL_SEV_PREDICTIVE,
            ERRL_ETYPE_NOT_APPLICABLE,
            SRCI_MACH_CHECK,
            SRCI_NO_ATTR,
            PRDF_RESTORE_DRAM_REPAIR,
            FSP_DEFAULT_REFCODE,
            PRDF_DETECTED_FAIL_HARDWARE_PROBABLE,
            0, 0, 0, 0, // user data
            HOM_SYS_NO_TERMINATE,
            false); // no pld check

    // add the callout

    if((*i_func)(err, i_data))
    {
        o_term = true;
    }

    bool term = false;

    CenMbaCaptureData::addDramRepairsData( i_mba, err );

    PRDF_HW_COMMIT_ERRL(
            term,
            err,
            HWSV::HWSV_DECONFIG_DEFER,
            ERRL_ACTION_REPORT,
            HOM_CONTINUE);

    if(term)
    {
        // FIXME...this is a little goofy.
        // Should be scrubbed with RTC 51552

        PRDF_COMMIT_ERRL(err, ERRL_ACTION_REPORT);
    }

    return o_term;
}

bool addMemMruCallout(errlHndl_t & io_log, void * i_memMru)
{
    PRDF_DENTER("addMemMruCallout");

    bool o_term = false;

    if ( NULL != i_memMru )
    {
        MemoryMru *memMru = static_cast<MemoryMru *>(i_memMru);

        TargetHandleList partList = memMru->getCalloutList();
        for ( TargetHandleList::iterator it = partList.begin();
              it != partList.end(); it++ )
        {
            PRDF_HW_ADD_CALLOUT(
                        o_term,
                        *it,
                        SRCI_PRIORITY_HIGH,
                        HWSV::HOM_DECONFIG,
                        HWSV::HOM_DECONFIG_GARD,
                        io_log,
                        false, // don't write src to vpd
                        GARD_Predictive,
                        ERRL_SEV_PREDICTIVE,
                        false); // don't update hcdb
        }
    }

    return o_term;
}

bool addDimmCallout(errlHndl_t & io_log, void * i_dimm)
{
    PRDF_DENTER("addDimmCallout");

    bool o_term = false;

    PRDF_HW_ADD_CALLOUT(
            o_term,
            static_cast<TargetHandle_t>(i_dimm),
            SRCI_PRIORITY_HIGH,
            HWSV::HOM_DECONFIG,
            HWSV::HOM_DECONFIG_GARD,
            io_log,
            false, // don't write src to vpd
            GARD_Predictive,
            ERRL_SEV_PREDICTIVE,
            false); // don't update hcdb

    return o_term;
}

bool processRepairedRanks( TargetHandle_t i_mba, uint8_t i_repairedRankMask )
{
    PRDF_DENTER("processRepairedRanks: %p, 0x%02x",
            i_mba, i_repairedRankMask);

    // check the argument ranks for repairs
    // that violate RAS policy

    errlHndl_t err = NULL;

    bool calloutMade = false;

    // check each rank for repairs
    // that violate RAS policy

    for ( uint8_t rankNumber = 0;
            rankNumber < DIMM_DQ_MAX_MBAPORT_DIMMS * DIMM_DQ_MAX_DIMM_RANKS;
            ++rankNumber )
    {
        if(0 == ((0x80 >> rankNumber) & i_repairedRankMask))
        {
            // this rank didn't have any repairs

            continue;
        }

        uint8_t sm = INVALID_SYMBOL,
                cm = INVALID_SYMBOL;

        if(SUCCESS != PlatServices::mssGetMarkStore(
                    i_mba, rankNumber, cm, sm))
        {
            // skip this rank

            continue;
        }

        uint8_t sp0 = INVALID_SYMBOL,
                sp1 = INVALID_SYMBOL,
                sp = INVALID_SYMBOL;

        if(SUCCESS != PlatServices::mssGetSteerMux(
                i_mba,
                rankNumber,
                sp0, sp1, sp))
        {
            // skip this rank

            PRDF_COMMIT_ERRL(err, ERRL_ACTION_REPORT);
            continue;
        }

        if ( (validSymbol(sp0) || validSymbol(sp1) || validSymbol(sp)) &&
             validSymbol(cm) )
        {
            // This rank has both a steer and a chip mark. Call out the DIMM
            // with the chip mark.

            CenRank rank ( rankNumber );

            CenSymbol symbol;
            int32_t rc = CenSymbol::fromSymbol( i_mba, rank, cm,
                                                CenSymbol::BOTH_SYMBOL_DQS,
                                                symbol );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( "[processRepairedRanks] CenSymbol::fromSymbol() "
                          "failed: HUID=0x%08x rank=%d symbol=%d",
                          PlatServices::getHuid(i_mba), rank.flatten(), cm );
                continue;
            }

            MemoryMru  memoryMru( i_mba, rank, symbol );

            commitRestoreCallout( &addMemMruCallout, &memoryMru, i_mba );

            calloutMade = true;
        }
    }

    PRDF_DEXIT("processRepairedRanks");

    return calloutMade;
}

bool processBadDimms(TargetHandle_t i_mba, uint8_t i_badDimmMask)
{
    PRDF_DENTER("processBadDimms: %p, 0x%02x", i_mba, i_badDimmMask);

    const struct DimmPortAssoc
    {
        uint8_t port;
        uint8_t dimm;
        uint8_t enc;

    } dimmPortAssoc[] = {

        {0, 0, 0x8},
        {0, 1, 0x4},
        {1, 0, 0x2},
        {1, 1, 0x1},
    };

    uint64_t calloutCount = 0;

    // callout the argument dimms

    // get all the dimms connected to this MBA

    TARGETING::TargetHandleList dimms = PlatServices::getConnected(
            i_mba, TARGETING::TYPE_DIMM);

    // convert the encoded dimms that had too many repairs to
    // dimm targets

    TargetHandleList::iterator dit = dimms.end();

    while(dit-- != dimms.begin())
    {
        uint8_t port = 0, dimm = 0;

        if(SUCCESS != PlatServices::getMbaPort(*dit, port))
        {
            // skip this dimm
            continue;
        }

        if(SUCCESS != PlatServices::getMbaDimm(*dit, dimm))
        {
            // skip this dimm
            continue;
        }

        // see if the passed in dimm
        // was flagged as bad by the restore procedure

        bool match = false;

        const DimmPortAssoc * it = dimmPortAssoc
            + sizeof(dimmPortAssoc)/sizeof(*dimmPortAssoc);

        while(!match && it-- != dimmPortAssoc)
        {
            if(i_badDimmMask & it->enc
                    && port == it->port
                    && dimm == it->dimm)
            {
                // this dimm is a match

                match = true;
            }
        }

        // call them out

        if(match)
        {
            ++calloutCount;
            commitRestoreCallout( &addDimmCallout, *dit, i_mba );
        }
    }

    PRDF_DEXIT("processBadDimms: bad dimm count: %d", calloutCount);

    return 0 != calloutCount;
}

bool processDq(TargetHandle_t i_mba)
{
    PRDF_DENTER("processDq: %p", i_mba);

    // callout any dimms on the argument MBA
    // that have any bad dq

    uint64_t calloutCount = 0;

    // get all the dimms connected to this MBA

    TARGETING::TargetHandleList dimms = PlatServices::getConnected(
            i_mba, TARGETING::TYPE_DIMM);

    TargetHandleList::iterator dit = dimms.end();

    // call them out if they have any bad dq

    while(dit-- != dimms.begin())
    {
        uint8_t port = 0, dimm = 0;

        if(SUCCESS != PlatServices::getMbaPort(*dit, port))
        {
            // skip this dimm
            continue;
        }

        if(SUCCESS != PlatServices::getMbaDimm(*dit, dimm))
        {
            // skip this dimm
            continue;
        }

        bool badDq = false;
        uint8_t bitmap[DIMM_DQ_RANK_BITMAP_SIZE];

        uint64_t rankNumber = DIMM_DQ_MAX_DIMM_RANKS;

        while(rankNumber-- && !badDq)
        {
            if(SUCCESS != PlatServices::getBadDqBitmap(
                        i_mba,
                        port,
                        dimm,
                        rankNumber,
                        bitmap))
            {
                // skip this rank
                continue;
            }

            uint8_t * it = bitmap + DIMM_DQ_RANK_BITMAP_SIZE;

            while(!badDq && it-- != bitmap)
            {
                if(*it)
                {
                    badDq = true;
                }
            }
        }

        if(badDq)
        {
            ++calloutCount;
            commitRestoreCallout( &addDimmCallout, *dit, i_mba );
        }
    }

    PRDF_DEXIT("processDq: bad dq dimm count: %d", calloutCount);

    return 0 != calloutCount;
}

//------------------------------------------------------------------------------
// External functions - declared in prdfMain.H
//------------------------------------------------------------------------------

int32_t restoreDramRepairs( TargetHandle_t i_mba )
{
    PRDF_ENTER( "restoreDramRepairs(0x%08x)", PlatServices::getHuid(i_mba) );

    bool calloutMade = false;

    uint8_t repairedRankMask = 0, badDimmMask = 0;

    do {

        if(PlatServices::isMemoryPreservingIpl())
        {
            // nothing to do in MPIPL

            break;
        }

        // in mfg mode, check dq and don't restore anything

        if(PlatServices::areDramRepairsDisabled()
                && processDq(i_mba))
        {
            calloutMade = true;

            break;
        }

        if(SUCCESS != PlatServices::mssRestoreDramRepairs(
                    i_mba,
                    repairedRankMask,
                    badDimmMask))
        {
            // can't check anything if
            // this doesn't work

            PRDF_ERR( "[restoreDramRepairs] "
                    "PlatServices::mssRestoreDramRepairs failed" );

            break;
        }

        // callout bad dimms

        if(processBadDimms(
                    i_mba,
                    badDimmMask))
        {
            calloutMade = true;
        }

        // check repaired ranks for
        // RAS policy violations

        if(processRepairedRanks(
                    i_mba,
                    repairedRankMask))
        {
            calloutMade = true;
        }

    } while(0);

    PRDF_EXIT( "restoreDramRepairs(0x%08x)", PlatServices::getHuid(i_mba) );

    return calloutMade ? FAIL : SUCCESS;
}

} // end namespace PRDF

