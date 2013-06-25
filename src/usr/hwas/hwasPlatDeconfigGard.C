/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatDeconfigGard.C $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
 *  @file hwasPlatDeconfigGard.C
 *
 *  @brief Platform specific deconfigGard functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/hwasPlat.H>

#include <devicefw/driverif.H>
#include <initservice/taskargs.H>
#include <vpd/mvpdenums.H>
#include <stdio.h>
#include <sys/mm.h>

#include <pnor/pnorif.H>

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

void _flush(void *i_addr);
errlHndl_t _GardRecordIdSetup(void *&io_platDeconfigGard);

errlHndl_t DeconfigGard::platClearGardRecords(
    const Target * const i_pTarget)
{
    errlHndl_t l_pErr = NULL;

    EntityPath l_targetId;
    if (i_pTarget)
    {
        HWAS_INF("Clear GARD Records for %.8X", get_huid(i_pTarget));
        l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
    }
    else
    {
        HWAS_INF("Clear all GARD Records");
    }

    HWAS_MUTEX_LOCK(iv_mutex);
    l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
    if (!l_pErr)
    {
        uint32_t l_gardRecordsCleared = 0;
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord * l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            if (l_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
            {
                // specific or all
                if (i_pTarget)
                {
                    // if we have a match
                    if (l_pGardRecords[i].iv_targetId == l_targetId)
                    {
                        HWAS_INF("Clearing GARD Record for %.8X",
                                get_huid(i_pTarget));
                        l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                        _flush(&l_pGardRecords[i]);
                        l_gardRecordsCleared++;
                        break; // done - can only be 1 GARD record per target
                    }
                }
                else // Clear all records
                {
                    l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    _flush(&l_pGardRecords[i]);
                    l_gardRecordsCleared++;
                }
            }
        } // for

        HWAS_INF("GARD Records to Cleared: %d", l_gardRecordsCleared);
    }
    else
    {
        HWAS_ERR("Error from _GardRecordIdSetup");
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

errlHndl_t DeconfigGard::platGetGardRecords(
        const Target * const i_pTarget,
        GardRecords_t &o_records)
{
    errlHndl_t l_pErr = NULL;
    o_records.clear();

    EntityPath l_targetId;
    if (i_pTarget)
    {
        HWAS_INF("Get GARD Record for %.8X", get_huid(i_pTarget));
        l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
    }
    else
    {
        HWAS_INF("Get all GARD Records");
    }

    HWAS_MUTEX_LOCK(iv_mutex);
    l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
    if (!l_pErr)
    {
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord * l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            if (l_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
            {
                // specific or all
                if (i_pTarget)
                {
                    // if we have a match
                    if (l_pGardRecords[i].iv_targetId == l_targetId)
                    {
                        HWAS_INF("Getting GARD Record for %.8X",
                                get_huid(i_pTarget));
                        o_records.push_back(l_pGardRecords[i]);
                        break; // done - can only be 1 GARD record per target
                    }
                }
                else // get all records
                {
                    o_records.push_back(l_pGardRecords[i]);
                }
            }
        } // for
    }
    else
    {
        HWAS_ERR("Error from _GardRecordIdSetup");
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    HWAS_INF("Get returning %d GARD Records", o_records.size());
    return l_pErr;
}


errlHndl_t DeconfigGard::platCreateGardRecord(
        const Target * const i_pTarget,
        const uint32_t i_errlPlid,
        const GARD_ErrorType i_errorType)
{
    HWAS_INF("Creating GARD Record for %.8X, errl 0x%X",
        get_huid(i_pTarget), i_errlPlid);
    errlHndl_t l_pErr = NULL;

    HWAS_MUTEX_LOCK(iv_mutex);

    do
    {
        l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
        if (l_pErr)
        {
            HWAS_ERR("Error from _GardRecordIdSetup");
            break;
        }

        // Find an empty GARD Record slot
        //  AND check to make sure we don't have a GARD record already
        EntityPath l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
        GardRecord * l_pRecord = NULL;
        bool l_duplicate = false;
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord *l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            if (l_pGardRecords[i].iv_recordId == EMPTY_GARD_RECORDID)
            {
                if (!l_pRecord)
                {
                    // save the first empty location we find
                    l_pRecord = &(l_pGardRecords[i]);
                }
            }
            else
            {
                if (l_pGardRecords[i].iv_targetId == l_targetId)
                {
                    l_duplicate = true;
                    l_pRecord = &(l_pGardRecords[i]);
                    HWAS_INF("Duplicate GARD Record from error 0x%X",
                            l_pGardRecords[i].iv_errlogPlid);
                    break;
                }
            }
        } // for

        if (l_duplicate)
        {
            // there's already a GARD record for this target

            // if this GARD record was a manual gard - overwrite
            //  with this new one
            if (l_pRecord->iv_errorType == GARD_User_Manual)
            {
                HWAS_INF("Duplicate is GARD_User_Manual - overwriting");
                l_pRecord->iv_errlogPlid = i_errlPlid;
                l_pRecord->iv_errorType = i_errorType;
                _flush((void *)l_pRecord);
            }

            // either way, return success
            break;
        }

        if (!l_pRecord)
        {
            HWAS_ERR("GARD Record Repository full");

            /*@
             * @errortype
             * @moduleid     HWAS::MOD_DECONFIG_GARD
             * @reasoncode   HWAS::RC_GARD_REPOSITORY_FULL
             * @devdesc      Attempt to create a GARD Record and the GARD
             *               Repository is full
             * @userdata1    HUID of input target // GARD errlog PLID
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t> (get_huid(i_pTarget)) << 32) |
                i_errlPlid;
            l_pErr = hwasError(
                ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_GARD_REPOSITORY_FULL,
                userdata1);
            break;
        }

        l_pRecord->iv_recordId = l_hbDeconfigGard->iv_nextGardRecordId++;
        l_pRecord->iv_targetId = l_targetId;
        l_pRecord->iv_errlogPlid = i_errlPlid;
        l_pRecord->iv_errorType = i_errorType;
        l_pRecord->iv_padding[0] = 0;
        l_pRecord->iv_padding[1] = 0;
        l_pRecord->iv_padding[2] = 0;
        l_pRecord->iv_padding[3] = 0;
        l_pRecord->iv_padding[4] = 0;
        l_pRecord->iv_padding[5] = 0;

        _flush((void *)l_pRecord);
    }
    while (0);

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}


//******************************************************************************
errlHndl_t _GardRecordIdSetup( void *&io_platDeconfigGard)
{
    HWAS_DBG("_GardRecordIdSetup: io_platDeconfigGard %p", io_platDeconfigGard);
    errlHndl_t l_pErr = NULL;

    do
    {
        // if this is NOT the first time thru here, we're done
        if (io_platDeconfigGard != NULL)
        {
            break;
        }

        // allocate our memory and set things up
        io_platDeconfigGard = malloc(sizeof(HBDeconfigGard));
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)io_platDeconfigGard;

        // get the PNOR address.
        PNOR::SectionInfo_t l_section;
        l_pErr = PNOR::getSectionInfo(PNOR::GUARD_DATA, PNOR::CURRENT_SIDE,
                        l_section);
        if (l_pErr)
        {
            HWAS_ERR("PNOR::getSectionInfo failed!!!");
            // no support for GARD in this configuration.
            break;
        }

        l_hbDeconfigGard->iv_pGardRecords =
            reinterpret_cast<DeconfigGard::GardRecord *> (l_section.vaddr);
        HWAS_DBG("PNOR vaddr=%p size=%d", l_section.vaddr, l_section.size);

        l_hbDeconfigGard->iv_maxGardRecords = l_section.size /
                sizeof(DeconfigGard::GardRecord);
        l_hbDeconfigGard->iv_nextGardRecordId = 0;

        // Figure out the next GARD Record ID to use
        uint32_t l_numGardRecords = 0;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        DeconfigGard::GardRecord *l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            // if this gard record is already filled out
            if (l_pGardRecords[i].iv_recordId
                    != EMPTY_GARD_RECORDID)
            {
                // count how many gard records are already defined
                l_numGardRecords++;

                // find the 'last' recordId, so that we can start after it
                if (l_pGardRecords[i].iv_recordId >
                        l_hbDeconfigGard->iv_nextGardRecordId)
                {
                    l_hbDeconfigGard->iv_nextGardRecordId =
                        l_pGardRecords[i].iv_recordId;
                }
            }
        } // for

        // next record will start after the highest Id we found
        l_hbDeconfigGard->iv_nextGardRecordId++;

        HWAS_INF("GARD setup. maxRecords %d nextID %d numRecords %d",
                 l_hbDeconfigGard->iv_maxGardRecords,
                 l_hbDeconfigGard->iv_nextGardRecordId,
                 l_numGardRecords);
    }
    while (0);

    return l_pErr;
}

void _flush(void *i_addr)
{
    HWAS_DBG("flushing GARD in PNOR: addr=%p", i_addr);
    int l_rc = mm_remove_pages(FLUSH, i_addr,
                sizeof(DeconfigGard::GardRecord));
    if (l_rc)
    {
        HWAS_ERR("mm_remove_pages(FLUSH,%p,%d) returned %d",
                i_addr, sizeof(DeconfigGard::GardRecord),l_rc);
    }
}

} // namespace HWAS
