/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/deconfigGard.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
 *  @file deconfigGard.C
 *
 *  @brief Implements the DeconfigGard class
 */
#include <stdint.h>

#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>

// Trace definition
#define __COMP_TD__ g_trac_deconf

// TODO The DeconfigGard code needs to trace a target. The current recommended
// way is to get the Target's PHYS_PATH attribute and do a binary trace.
// However, the size of a TARGETING::EntityPath is more than 16 bytes. This code
// will trace only the first 16 bytes (which in most cases is enough) to avoid a
// multi-line binary trace. This all seems a little convoluted. Is there a
// better way to trace a Target
#define DG_TRAC_TARGET(string, pPath) \
    HWAS_DBG_BIN(string, pPath, sizeof(TARGETING::EntityPath) - 1)

// TODO There are a number of error logs created in this file. Most of them
// should include the target identifier (PHYS_PATH). There is a plan in RTC
// story 4110 to provide a way to easily add a target to an error log. When that
// is done need to update the error logs

namespace HWAS
{

using namespace HWAS::COMMON;

errlHndl_t collectGard(const TARGETING::PredicateBase *i_pPredicate)
{
    HWAS_INF("collectGard entry" );

    errlHndl_t errl = theDeconfigGard().clearGardRecordsForReplacedTargets();

    if (errl)
    {
        HWAS_ERR("ERROR: collectGard failed to clear GARD Records for "
                    "replaced Targets");
    }
    else
    {
        errl = theDeconfigGard().
                    deconfigureTargetsFromGardRecordsForIpl(i_pPredicate);

        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to deconfigure Targets "
                        "from GARD Records for IPL");
        }
        else
        {
            HWAS_INF("collectGard completed successfully");
        }
    }
    return errl;
}

//******************************************************************************
DeconfigGard & theDeconfigGard()
{
    return HWAS_GET_SINGLETON(theDeconfigGardSingleton);
}

//******************************************************************************
DeconfigGard::DeconfigGard()
: iv_nextGardRecordId(0),
  iv_maxGardRecords(0),
  iv_pGardRecords(NULL)
{
    HWAS_INF("DeconfigGard Constructor");
    HWAS_MUTEX_INIT(iv_mutex);
}

//******************************************************************************
DeconfigGard::~DeconfigGard()
{
    HWAS_INF("DeconfigGard Destructor");
    HWAS_MUTEX_DESTROY(iv_mutex);
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecordsForReplacedTargets()
{
    HWAS_INF("****TBD****Usr Request: Clear GARD Records for replaced Targets");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = NULL;

    // TODO

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTargetsFromGardRecordsForIpl(
        const TARGETING::PredicateBase *i_pPredicate)
{
    HWAS_INF("Usr Request: Deconfigure Targets from GARD Records for IPL");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = NULL;
    GardRecords_t l_gardRecords;

    // TODO If deconfiguring all Targets with a GARD Record will result in a
    //      configuration that cannot IPL then need to figure out which
    //      subset of Targets to deconfigure to give the best chance of IPL
    //      This is known as Resource Recovery

    // Get all GARD Records
    l_pErr = _getGardRecords(GET_ALL_GARD_RECORDS, l_gardRecords);

    if (l_pErr)
    {
        HWAS_ERR("Error from _getGardRecords");
    }
    else
    {
        HWAS_INF("%d GARD Records found", l_gardRecords.size());

        // For each GARD Record
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end(); ++l_itr)
        {
            // Find the associated Target
            TARGETING::Target * l_pTarget =
                TARGETING::targetService().toTarget((*l_itr).iv_targetId);

            if (l_pTarget == NULL)
            {
                DG_TRAC_TARGET(ERR_MRK "Could not find Target for",
                               &((*l_itr).iv_targetId));

                /*@
                 * @errortype
                 * @moduleid     HWAS::MOD_DECONFIG_GARD
                 * @reasoncode   HWAS::RC_TARGET_NOT_FOUND_FOR_GARD_RECORD
                 * @devdesc      GARD Record could not be mapped to a Target
                 */
                l_pErr = hwasError(
                    ERRL_SEV_INFORMATIONAL,
                    HWAS::MOD_DECONFIG_GARD,
                    HWAS::RC_TARGET_NOT_FOUND_FOR_GARD_RECORD);
                errlCommit(l_pErr, HWAS_COMP_ID);
            }
            else
            {
                if (i_pPredicate)
                {
                    // if this does NOT match, continue to next in loop
                    if ((*i_pPredicate)(l_pTarget) == false)
                    {
                        HWAS_INF("skipping %.8X - predicate didn't match",
                                TARGETING::get_huid(l_pTarget));
                        continue;
                    }
                }

                // Deconfigure the Target
                _deconfigureTarget(*l_pTarget, (*l_itr).iv_errlogPlid,
                                   DECONFIG_CAUSE_GARD_RECORD);

                // Deconfigure other Targets by association
                _deconfigureByAssoc(*l_pTarget, (*l_itr).iv_errlogPlid);
            }
        }
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTarget(TARGETING::Target & i_target,
                                           const uint32_t i_errlPlid)
{
    HWAS_INF("Usr Request: Deconfigure Target");
    HWAS_MUTEX_LOCK(iv_mutex);

    // Deconfigure the Target
    _deconfigureTarget(i_target, i_errlPlid, DECONFIG_CAUSE_FIRMWARE_REQ);

    // Deconfigure other Targets by association
    _deconfigureByAssoc(i_target, i_errlPlid);

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return NULL;
}

//******************************************************************************
errlHndl_t DeconfigGard::createGardRecord(const TARGETING::Target & i_target,
                                          const uint32_t i_errlPlid,
                                          const GARD_ErrorType i_errorType)
{
    HWAS_INF("Usr Request: Create GARD Record");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = _createGardRecord(i_target, i_errlPlid, i_errorType);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getDeconfigureRecords(
    const TARGETING::EntityPath * i_pTargetId,
    DeconfigureRecords_t & o_records)
{
    HWAS_INF("Usr Request: Get Deconfigure Record(s)");
    HWAS_MUTEX_LOCK(iv_mutex);
    _getDeconfigureRecords(i_pTargetId, o_records);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return NULL;
}


//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(const uint32_t i_recordId)
{
    HWAS_INF("Usr Request: Clear GARD Record(s) by Record ID");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = _clearGardRecords(i_recordId);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(
    const TARGETING::EntityPath & i_targetId)
{
    HWAS_INF("Usr Request: Clear GARD Record(s) by Target ID");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = _clearGardRecords(i_targetId);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const uint32_t i_recordId,
    GardRecords_t & o_records)
{
    HWAS_INF("Usr Request: Get GARD Record(s) by Record ID");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = _getGardRecords(i_recordId, o_records);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const TARGETING::EntityPath & i_targetId,
    GardRecords_t & o_records)
{
    HWAS_INF("Usr Request: Get GARD Record(s) by Target ID");
    HWAS_MUTEX_LOCK(iv_mutex);
    errlHndl_t l_pErr = _getGardRecords(i_targetId, o_records);
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
void DeconfigGard::_deconfigureByAssoc(TARGETING::Target & i_target,
                                       const uint32_t i_errlPlid)
{
    HWAS_INF("****TBD****: Deconfiguring by Association for: %.8X",
                   TARGETING::get_huid(&i_target));

    // TODO
}

//******************************************************************************
void DeconfigGard::_deconfigureTarget(TARGETING::Target & i_target,
                                      const uint32_t i_errlPlid,
                                      const DeconfigCause i_cause)
{
    HWAS_INF("Deconfiguring Target %.8X",
            TARGETING::get_huid(&i_target));

    if (!i_target.getAttr<TARGETING::ATTR_DECONFIG_GARDABLE>())
    {
        // Target is not Deconfigurable. Commit an error
        HWAS_ERR("Target %.8X not Deconfigurable",
            TARGETING::get_huid(&i_target));

        /*@
         * @errortype
         * @moduleid     HWAS::MOD_DECONFIG_GARD
         * @reasoncode   HWAS::RC_TARGET_NOT_DECONFIGURABLE
         * @devdesc      Attempt to deconfigure a target that is not
         *               deconfigurable
         * @userdata1    HUID of input target
         */
        const uint64_t userdata1 = static_cast<uint64_t>
                (TARGETING::get_huid(&i_target)) << 32;
        errlHndl_t l_pErr = hwasError(
            ERRL_SEV_INFORMATIONAL,
            HWAS::MOD_DECONFIG_GARD,
            HWAS::RC_TARGET_NOT_DECONFIGURABLE,
            userdata1);
        errlCommit(l_pErr,HWAS_COMP_ID);
    }
    else
    {
        // Set the Target state to non-functional. The assumption is that it is
        // not possible for another thread (other than deconfigGard) to be
        // updating HWAS_STATE concurrently.
        TARGETING::HwasState l_state =
            i_target.getAttr<TARGETING::ATTR_HWAS_STATE>();

        if (!l_state.functional)
        {
            HWAS_DBG("Target HWAS_STATE already non-functional");
        }
        else
        {
            HWAS_INF("Setting Target HWAS_STATE to non-functional");
            l_state.functional = 0;
            i_target.setAttr<TARGETING::ATTR_HWAS_STATE>(l_state);
        }

        // Do any necessary Deconfigure Actions
        _doDeconfigureActions(i_target);

        // Create a Deconfigure Record
        _createDeconfigureRecord(i_target, i_errlPlid, i_cause);
    }
}

//******************************************************************************
void DeconfigGard::_doDeconfigureActions(TARGETING::Target & i_target)
{
    // TODO
}

//******************************************************************************
void DeconfigGard::_createDeconfigureRecord(
    const TARGETING::Target & i_target,
    const uint32_t i_errlPlid,
    const DeconfigCause i_cause)
{
    // Get the Target's ID
    TARGETING::EntityPath l_id = i_target.getAttr<TARGETING::ATTR_PHYS_PATH>();

    // Look for an existing Deconfigure Record for the Target
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();

    for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
    {
        if ((*l_itr).iv_targetId == l_id)
        {
            break;
        }
    }

    if (l_itr != iv_deconfigureRecords.end())
    {
        HWAS_DBG("Not creating a Deconfigure Record, one already exists");
    }
    else
    {
        // Create a DeconfigureRecord
        HWAS_INF("Creating a Deconfigure Record");

        DeconfigureRecord l_record;
        l_record.iv_targetId = l_id;
        l_record.iv_errlogPlid = i_errlPlid;
        l_record.iv_cause = i_cause;
        l_record.iv_padding[0] = 0;
        l_record.iv_padding[1] = 0;
        l_record.iv_padding[2] = 0;
        l_record.iv_deconfigureTime = 0; // TODO Get epoch time

        iv_deconfigureRecords.push_back(l_record);
    }
}

//******************************************************************************
void DeconfigGard::_clearDeconfigureRecords(
        const TARGETING::EntityPath * i_pTargetId)
{
    if (i_pTargetId == NULL)
    {
        HWAS_INF("Clearing all %d Deconfigure Records",
                 iv_deconfigureRecords.size());
        iv_deconfigureRecords.clear();
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        bool l_foundRecord = false;

        for (DeconfigureRecordsItr_t l_itr = iv_deconfigureRecords.begin();
             l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_targetId == *i_pTargetId)
            {
                DG_TRAC_TARGET(INFO_MRK "Clearing Deconfigure Record for: ",
                                i_pTargetId);
                iv_deconfigureRecords.erase(l_itr);
                l_foundRecord = true;
                break;
            }
        }

        if (!l_foundRecord)
        {
            DG_TRAC_TARGET(INFO_MRK "Did not find a Deconfigure Record to clear for: ",
                           i_pTargetId);
        }
    }
}

//******************************************************************************
void DeconfigGard::_getDeconfigureRecords(
    const TARGETING::EntityPath * i_pTargetId,
    DeconfigureRecords_t & o_records) const
{
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();
    o_records.clear();

    if (i_pTargetId == NULL)
    {
        HWAS_INF("Getting all %d Deconfigure Records",
                 iv_deconfigureRecords.size());

        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            o_records.push_back(*l_itr);
        }
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_targetId == *i_pTargetId)
            {
                DG_TRAC_TARGET(INFO_MRK "Getting Deconfigure Record for: ",
                               i_pTargetId);
                o_records.push_back(*l_itr);
                break;
            }
        }

        if (l_itr == iv_deconfigureRecords.end())
        {
            DG_TRAC_TARGET(INFO_MRK "Did not find a Deconfigure Record to get for: ",
                           i_pTargetId);
        }
    }
}

//******************************************************************************
errlHndl_t DeconfigGard::_createGardRecord(const TARGETING::Target & i_target,
                                           const uint32_t i_errlPlid,
                                           const GARD_ErrorType i_errorType)
{
    errlHndl_t l_pErr = NULL;

    TARGETING::EntityPath l_id = i_target.getAttr<TARGETING::ATTR_PHYS_PATH>();
    HWAS_INF("Creating GARD Record for %.8X",
            TARGETING::get_huid(&i_target));

    do
    {

        if (!i_target.getAttr<TARGETING::ATTR_DECONFIG_GARDABLE>())
        {
            // Target is not GARDable. Commit an error
            HWAS_ERR("Target not GARDable");

            /*@
             * @errortype
             * @moduleid     HWAS::MOD_DECONFIG_GARD
             * @reasoncode   HWAS::RC_TARGET_NOT_GARDABLE
             * @devdesc      Attempt to create a GARD Record for a target that is
             *               not GARDable
             * @userdata1    HUID of input target
             */
            const uint64_t userdata1 =
                (uint64_t)(TARGETING::get_huid(&i_target)) << 32;
            l_pErr = hwasError(
                ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_GARDABLE,
                userdata1);
            errlCommit(l_pErr,HWAS_COMP_ID);
            break;
        }

        bool l_gardEnabled;
        GardAddress l_GardAddress(l_gardEnabled);

        if (!l_gardEnabled)
        {
            HWAS_ERR("Error from l_GardAddress");
            break;
        }

        GardRecord * l_pRecord = NULL;

        // Find an empty GARD Record slot
        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            if (iv_pGardRecords[i].iv_recordId == EMPTY_GARD_RECORDID)
            {
                l_pRecord = &(iv_pGardRecords[i]);
                break;
            }
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
             * @userdata1    HUID of input target
             */
            const uint64_t userdata1 =
                (uint64_t)(TARGETING::get_huid(&i_target)) << 32;
            l_pErr = hwasError(
                ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_GARD_REPOSITORY_FULL,
                userdata1);
            break;
        }

        l_pRecord->iv_recordId = iv_nextGardRecordId++;
        l_pRecord->iv_targetId = l_id;
        // TODO Setup iv_cardMruSn or iv_chipMruEcid
        l_pRecord->iv_errlogPlid = i_errlPlid;
        l_pRecord->iv_errorType = i_errorType;
        l_pRecord->iv_padding[0] = 0;
        l_pRecord->iv_padding[1] = 0;
        l_pRecord->iv_padding[2] = 0;
        l_pRecord->iv_gardTime = 0; // TODO Get epoch time

        l_GardAddress.writeRecord((void *)l_pRecord);

    }
    while (0);

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_clearGardRecords(const uint32_t i_recordId)
{
    errlHndl_t l_pErr = NULL;

    bool l_gardEnabled;
    GardAddress l_GardAddress(l_gardEnabled);

    if (l_gardEnabled)
    {
        if (i_recordId == CLEAR_ALL_GARD_RECORDS)
        {
            HWAS_INF("Clearing all GARD Records");

            // Only clear valid GARD Records to avoid excessive PNOR access
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
                {
                    // clear iv_recordId
                    iv_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    l_GardAddress.writeRecord(&iv_pGardRecords[i]);
                }
            }
        }
        else
        {
            uint32_t i = 0;
            for (; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId == i_recordId)
                {
                    HWAS_INF("Clearing GARD Record ID 0x%x", i_recordId);
                    // clear iv_recordId
                    iv_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    l_GardAddress.writeRecord(&iv_pGardRecords[i]);
                    break;
                }
            }

            if (i == iv_maxGardRecords)
            {
                HWAS_INF("No GARD Record ID 0x%x to clear", i_recordId);
            }
        }
    }
    else
    {
        HWAS_ERR("Error from l_GardAddress");
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_clearGardRecords(
    const TARGETING::EntityPath & i_targetId)
{
    errlHndl_t l_pErr = NULL;

    bool l_gardEnabled;
    GardAddress l_GardAddress(l_gardEnabled);

    if (l_gardEnabled)
    {
        bool l_gardRecordsCleared = false;

        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            if ((iv_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID) &&
                (iv_pGardRecords[i].iv_targetId == i_targetId)
               )
            {
                DG_TRAC_TARGET(INFO_MRK "Clearing GARD Record for: ",
                               &i_targetId);
                // clear iv_recordId
                iv_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                l_gardRecordsCleared = true;
                l_GardAddress.writeRecord(&iv_pGardRecords[i]);
            }
        }

        if (!l_gardRecordsCleared)
        {
            DG_TRAC_TARGET(INFO_MRK "No GARD Records to clear for: ",
                           &i_targetId);
        }
    }
    else
    {
        HWAS_ERR("Error from l_GardAddress");
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_getGardRecords(const uint32_t i_recordId,
                                         GardRecords_t & o_records)
{
    errlHndl_t l_pErr = NULL;
    o_records.clear();

    bool l_gardEnabled;
    GardAddress l_GardAddress(l_gardEnabled);

    if (l_gardEnabled)
    {
        if (i_recordId == GET_ALL_GARD_RECORDS)
        {
            HWAS_DBG("Getting all GARD Records");
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
                {
                    HWAS_DBG("Getting GARD Record ID 0x%x",
                             iv_pGardRecords[i].iv_recordId);
                    o_records.push_back(iv_pGardRecords[i]);
                }
            }
        }
        else
        {
            uint32_t i = 0;
            for (; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId == i_recordId)
                {
                    HWAS_DBG("Getting GARD Record ID 0x%x", i_recordId);
                    o_records.push_back(iv_pGardRecords[i]);
                    break;
                }
            }

            if (i == iv_maxGardRecords)
            {
                HWAS_DBG("No GARD Record ID 0x%x to get", i_recordId);
            }
        }
    }
    else
    {
        HWAS_ERR("Error from l_GardAddress");
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_getGardRecords(
    const TARGETING::EntityPath & i_targetId,
    GardRecords_t & o_records)
{
    errlHndl_t l_pErr = NULL;
    o_records.clear();

    bool l_gardEnabled;
    GardAddress l_GardAddress(l_gardEnabled);

    if (l_gardEnabled)
    {
        bool l_gardRecordsGot = false;

        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            if ((iv_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID) &&
                (iv_pGardRecords[i].iv_targetId == i_targetId)
               )
            {
                DG_TRAC_TARGET(INFO_MRK "Getting GARD Record for: ",
                               &i_targetId);
                o_records.push_back(iv_pGardRecords[i]);
                l_gardRecordsGot = true;
            }
        }

        if (!l_gardRecordsGot)
        {
            DG_TRAC_TARGET(INFO_MRK "No GARD Records to get for: ",
                           &i_targetId);
        }
    }
    else
    {
        HWAS_ERR("Error from l_GardAddress");
    }

    return l_pErr;
}

//******************************************************************************
void DeconfigGard::_GardRecordIdSetup(uint32_t i_size)
{
    if (iv_maxGardRecords == 0)
    {
        // hasn't been computed yet
        HWAS_INF("GardRecordIdSetup(size=%d)", i_size);

        iv_maxGardRecords = i_size / sizeof(GardRecord);

        // Figure out the next GARD Record ID to use
        uint32_t l_numGardRecords = 0;
        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            // if this gard record is already fill out:
            if (iv_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
            {
                // count how many gard records are already defined
                l_numGardRecords++;

                // find the 'last' recordId, so that we can start after it
                if (iv_pGardRecords[i].iv_recordId > iv_nextGardRecordId)
                {
                    iv_nextGardRecordId = iv_pGardRecords[i].iv_recordId;
                }
            }
        } // for

        // next record will start after the highest Id we found
        iv_nextGardRecordId++;

        HWAS_INF("GARD setup. maxRecords %d nextID %d numRecords %d",
                 iv_maxGardRecords, iv_nextGardRecordId, l_numGardRecords);
    }
}

} // namespce HWAS
