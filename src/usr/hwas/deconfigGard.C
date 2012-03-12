//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/deconfigGard.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file deconfigGard.C
 *
 *  @brief Implements the DeconfigGard class
 */

#include <string.h>
#include <targeting/targetservice.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <hwas/deconfigGard.H>
#include <hwas/hwas_reasoncodes.H>
#include <pnor/pnorif.H>

// Trace definition
trace_desc_t* g_trac_deconf = NULL;
#define __COMP_TD__ g_trac_deconf

// TODO The DeconfigGard code needs to trace a target. The current recommended
// way is to get the Target's PHYS_PATH attribute and do a binary trace.
// However, the size of a TARGETING::EntityPath is more than 16 bytes. This code
// will trace only the first 16 bytes (which in most cases is enough) to avoid a
// multi-line binary trace. This all seems a little convoluted. Is there a
// better way to trace a Target
#define DG_TRAC_TARGET(string, pPath) \
    TRACFBIN(g_trac_deconf, string, pPath, sizeof(TARGETING::EntityPath) - 1)

// TODO There are a number of error logs created in this file. Most of them
// should include the target identifier (PHYS_PATH). There is a plan in RTC
// story 4110 to provide a way to easily add a target to an error log. When that
// is done need to update the error logs

namespace HWAS
{

//******************************************************************************
DeconfigGard & theDeconfigGard()
{
    return Singleton<DeconfigGard>::instance();
}

//******************************************************************************
DeconfigGard::DeconfigGard()
: iv_nextGardRecordId(0),
  iv_maxGardRecords(0),
  iv_pGardRecords(NULL)
{
    TRAC_INIT_BUFFER(&g_trac_deconf, "DECONF", 4096);
    TRAC_INF("DeconfigGard Constructor");
    mutex_init(&iv_mutex);
}

//******************************************************************************
DeconfigGard::~DeconfigGard()
{
    TRAC_INF("DeconfigGard Destructor");
    mutex_destroy(&iv_mutex);
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecordsForReplacedTargets()
{
    TRAC_INF("****TBD****Usr Request: Clear GARD Records for replaced Targets");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = NULL;
    
    // TODO

    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTargetsFromGardRecordsForIpl()
{
    TRAC_INF("Usr Request: Deconfigure Targets from GARD Records for IPL");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = NULL;
    GardRecords_t l_gardRecords;
    
    // TODO If deconfiguring all Targets with a GARD Record will result in a
    //      configuration that cannot IPL then need to figure out which
    //      subset of Targets to deconfigure to give the best chance of IPL
    //      This is known as Resource Recovery

    // Get all GARD Records
    l_pErr = _getGardRecords(0, l_gardRecords);

    if (l_pErr)
    {
        TRAC_ERR("Error from _getGardRecords");
    }
    else
    {
        TRAC_INF("%d GARD Records found", l_gardRecords.size());
        
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
                 * @moduleid     MOD_DECONFIG_GARD
                 * @reasoncode   RC_TARGET_NOT_FOUND_FOR_GARD_RECORD
                 * @devdesc      GARD Record could not be mapped to a Target
                 */
                l_pErr = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    MOD_DECONFIG_GARD,
                    RC_TARGET_NOT_FOUND_FOR_GARD_RECORD);
                errlCommit(l_pErr, HWAS_COMP_ID);
            }
            else
            {
                // Deconfigure the Target
                _deconfigureTarget(*l_pTarget, (*l_itr).iv_errlogPlid,
                                   DECONFIG_CAUSE_GARD_RECORD);

                // Deconfigure other Targets by association
                _deconfigureByAssoc(*l_pTarget, (*l_itr).iv_errlogPlid);
            }
        }
    }

    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTarget(TARGETING::Target & i_target,
                                           const uint32_t i_errlPlid)
{
    TRAC_ERR("Usr Request: Deconfigure Target");
    mutex_lock(&iv_mutex);
    
    // Deconfigure the Target
    _deconfigureTarget(i_target, i_errlPlid, DECONFIG_CAUSE_FIRMWARE_REQ);
        
    // Deconfigure other Targets by association
    _deconfigureByAssoc(i_target, i_errlPlid);
        
    mutex_unlock(&iv_mutex);
    return NULL;
}

//******************************************************************************
errlHndl_t DeconfigGard::createGardRecord(const TARGETING::Target & i_target,
                                          const uint32_t i_errlPlid,
                                          const GardSeverity i_severity)
{
    TRAC_ERR("Usr Request: Create GARD Record");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = _createGardRecord(i_target, i_errlPlid, i_severity);
    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getDeconfigureRecords(
    const TARGETING::EntityPath * i_pTargetId,
    DeconfigureRecords_t & o_records) const
{
    TRAC_INF("Usr Request: Get Deconfigure Record(s)");
    mutex_lock(&iv_mutex);
    _getDeconfigureRecords(i_pTargetId, o_records);
    mutex_unlock(&iv_mutex);
    return NULL;
}


//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(const uint32_t i_recordId)
{
    TRAC_INF("Usr Request: Clear GARD Record(s) by Record ID");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = _clearGardRecords(i_recordId);
    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(
    const TARGETING::EntityPath & i_targetId)
{
    TRAC_INF("Usr Request: Clear GARD Record(s) by Target ID");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = _clearGardRecords(i_targetId);
    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const uint32_t i_recordId,
    GardRecords_t & o_records)
{
    TRAC_INF("Usr Request: Get GARD Record(s) by Record ID");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = _getGardRecords(i_recordId, o_records);
    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const TARGETING::EntityPath & i_targetId,
    GardRecords_t & o_records)
{
    TRAC_INF("Usr Request: Get GARD Record(s) by Target ID");
    mutex_lock(&iv_mutex);
    errlHndl_t l_pErr = _getGardRecords(i_targetId, o_records);
    mutex_unlock(&iv_mutex);
    return l_pErr;
}

//******************************************************************************
void DeconfigGard::_deconfigureByAssoc(TARGETING::Target & i_target,
                                       const uint32_t i_errlPlid)
{
    TARGETING::EntityPath l_id = i_target.getAttr<TARGETING::ATTR_PHYS_PATH>();
    DG_TRAC_TARGET(ERR_MRK "****TBD****: Deconfiguring by Association for: ",
                   &l_id);
    
    // TODO
}

//******************************************************************************
void DeconfigGard::_deconfigureTarget(TARGETING::Target & i_target,
                                      const uint32_t i_errlPlid,
                                      const DeconfigCause i_cause)
{
    TARGETING::EntityPath l_id = i_target.getAttr<TARGETING::ATTR_PHYS_PATH>();
    DG_TRAC_TARGET(ERR_MRK "Deconfiguring Target: ", &l_id);
    
    errlHndl_t l_pErr = NULL;
    
    if (!i_target.getAttr<TARGETING::ATTR_DECONFIG_GARDABLE>())
    {
        // Target is not Deconfigurable. Commit an error
        TRAC_ERR("Target not Deconfigurable");
        /*@
         * @errortype
         * @moduleid     MOD_DECONFIG_GARD
         * @reasoncode   RC_TARGET_NOT_DECONFIGURABLE
         * @devdesc      Attempt to deconfigure a target that is not
         *               deconfigurable
         */
        l_pErr = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         MOD_DECONFIG_GARD,
                                         RC_TARGET_NOT_DECONFIGURABLE);
        
        ERRORLOG::ErrlUserDetailsTarget(&i_target).addToLog(l_pErr);
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
            TRAC_ERR("Target HWAS_STATE already non-functional");
        }
        else
        {
            TRAC_ERR("Setting Target HWAS_STATE to non-functional");
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
        TRAC_ERR("Not creating a Deconfigure Record, one already exists");
    }
    else
    {
        // Create a DeconfigureRecord
        TRAC_ERR("Creating a Deconfigure Record");
        
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
        TRAC_INF("Clearing all %d Deconfigure Records",
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
        TRAC_INF("Getting all %d Deconfigure Records",
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
                                           const GardSeverity i_severity)
{
    errlHndl_t l_pErr = NULL;

    TARGETING::EntityPath l_id = i_target.getAttr<TARGETING::ATTR_PHYS_PATH>();
    DG_TRAC_TARGET(ERR_MRK "Creating GARD Record for: ", &l_id);
    
    if (!i_target.getAttr<TARGETING::ATTR_DECONFIG_GARDABLE>())
    {
        // Target is not GARDable. Commit an error
        TRAC_ERR("Target not GARDable");
        /*@
         * @errortype
         * @moduleid     MOD_DECONFIG_GARD
         * @reasoncode   RC_TARGET_NOT_GARDABLE
         * @devdesc      Attempt to create a GARD Record for a target that is
         *               not GARDable
         */
        l_pErr = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_DECONFIG_GARD,
                                         RC_TARGET_NOT_GARDABLE);
       
        ERRORLOG::ErrlUserDetailsTarget(&i_target).addToLog(l_pErr); 
        errlCommit(l_pErr,HWAS_COMP_ID);
    }
    else
    {
        l_pErr = _ensureGardRecordDataSetup();
        
        if (l_pErr)
        {
            TRAC_ERR("Error from _ensureGardRecordDataSetup");
        }
        else
        {
            GardRecord * l_pRecord = NULL;

            // Find an empty GARD Record slot
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId == 0)
                {
                    l_pRecord = &(iv_pGardRecords[i]);
                    break;
                }
            }
            
            if (!l_pRecord)
            {
                TRAC_ERR("GARD Record Repository full");
                /*@
                 * @errortype
                 * @moduleid     MOD_DECONFIG_GARD
                 * @reasoncode   RC_GARD_REPOSITORY_FULL
                 * @devdesc      Attempt to create a GARD Record and the GARD
                 *               Repository is full
                 * @userdata1    Number of GARD Records in repository
                 */
                l_pErr = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 MOD_DECONFIG_GARD,
                                                 RC_GARD_REPOSITORY_FULL,
                                                 iv_maxGardRecords);

                ERRORLOG::ErrlUserDetailsTarget(&i_target).addToLog(l_pErr);
            }
            else
            {
                l_pRecord->iv_recordId = iv_nextGardRecordId++;
                l_pRecord->iv_targetId = l_id;
                // TODO Setup iv_cardMruSn or iv_chipMruEcid    
                l_pRecord->iv_errlogPlid = i_errlPlid;
                l_pRecord->iv_severity = i_severity;
                l_pRecord->iv_padding[0] = 0;
                l_pRecord->iv_padding[1] = 0;
                l_pRecord->iv_padding[2] = 0;
                l_pRecord->iv_gardTime = 0; // TODO Get epoch time
            }
        }
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_clearGardRecords(const uint32_t i_recordId)
{
    errlHndl_t l_pErr = NULL;

    l_pErr = _ensureGardRecordDataSetup();
    
    if (l_pErr)
    {
        TRAC_ERR("Error from _ensureGardRecordDataSetup");
    }
    else
    {
        if (i_recordId == 0)
        {
            TRAC_INF("Clearing all GARD Records");
            
            // Only clear valid GARD Records to avoid excessive PNOR access
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId != 0)
                {
                    memset(&(iv_pGardRecords[i]), 0, sizeof(GardRecord));
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
                    TRAC_INF("Clearing GARD Record ID 0x%x", i_recordId);
                    memset(&(iv_pGardRecords[i]), 0, sizeof(GardRecord));
                    break;
                }
            }
            
            if (i == iv_maxGardRecords)
            {
                TRAC_INF("No GARD Record ID 0x%x to clear", i_recordId);
            }
        }
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_clearGardRecords(
    const TARGETING::EntityPath & i_targetId)
{
    errlHndl_t l_pErr = NULL;

    l_pErr = _ensureGardRecordDataSetup();
    
    if (l_pErr)
    {
        TRAC_ERR("Error from _ensureGardRecordDataSetup");
    }
    else
    {
        bool l_gardRecordsCleared = false;
        
        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            if (iv_pGardRecords[i].iv_targetId == i_targetId)
            {
                DG_TRAC_TARGET(INFO_MRK "Clearing GARD Record for: ",
                               &i_targetId);
                memset(&(iv_pGardRecords[i]), 0, sizeof(GardRecord));
                l_gardRecordsCleared = true;
            }
        }

        if (!l_gardRecordsCleared)
        {
            DG_TRAC_TARGET(INFO_MRK "No GARD Records to clear for: ",
                           &i_targetId);
        }
    }

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_getGardRecords(const uint32_t i_recordId,
                                         GardRecords_t & o_records)
{
    errlHndl_t l_pErr = NULL;
    o_records.clear();
    
    l_pErr = _ensureGardRecordDataSetup();
    
    if (l_pErr)
    {
        TRAC_ERR("Error from _ensureGardRecordDataSetup");
    }
    else
    {
        if (i_recordId == 0)
        {
            TRAC_INF("Getting all GARD Records");
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId != 0)
                {
                    TRAC_INF("Getting GARD Record ID 0x%x",
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
                    TRAC_INF("Getting GARD Record ID 0x%x", i_recordId);
                    o_records.push_back(iv_pGardRecords[i]);
                    break;
                }
            }
            
            if (i == iv_maxGardRecords)
            {
                TRAC_INF("No GARD Record ID 0x%x to get", i_recordId);
            }
        }
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

    l_pErr = _ensureGardRecordDataSetup();
    
    if (l_pErr)
    {
        TRAC_ERR("Error from _ensureGardRecordDataSetup");
    }
    else
    {
        bool l_gardRecordsGot = false;
        
        for (uint32_t i = 0; i < iv_maxGardRecords; i++)
        {
            if (iv_pGardRecords[i].iv_targetId == i_targetId)
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

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_ensureGardRecordDataSetup()
{
    errlHndl_t l_pErr = NULL;
    
    if (iv_pGardRecords == NULL)
    {
        PNOR::SectionInfo_t l_section;

        // TODO Update when PNOR for GARD Records available (change HB_DATA)
        l_pErr = PNOR::getSectionInfo(PNOR::HB_DATA, PNOR::SIDE_A, l_section);
        
        if(l_pErr)
        {
            TRAC_ERR("Error getting GARD Record PNOR section info");
        }
        else
        {
            uint32_t l_numGardRecords = 0;
            iv_pGardRecords = reinterpret_cast<GardRecord *>(l_section.vaddr);
            iv_maxGardRecords = l_section.size / sizeof(GardRecord);
            
            // TODO Remove this section when PNOR for GARD Records available
            // For now, just use a buffer
            iv_pGardRecords = new GardRecord[20];
            memset(iv_pGardRecords, 0, sizeof(GardRecord) * 20);
            iv_maxGardRecords = 20;
            // TODO Remove this section when PNOR for GARD Records available
            
            // Figure out the next GARD Record ID to use
            for (uint32_t i = 0; i < iv_maxGardRecords; i++)
            {
                if (iv_pGardRecords[i].iv_recordId > iv_nextGardRecordId)
                {
                    iv_nextGardRecordId = iv_pGardRecords[i].iv_recordId;
                }
                
                if (iv_pGardRecords[i].iv_recordId != 0)
                {
                    l_numGardRecords++;
                }
            }
            
            iv_nextGardRecordId++;
            
            TRAC_INF("GARD Record data setup. MaxRecords: %d. NextID: %d. NumRecords: %d",
                     iv_maxGardRecords, iv_nextGardRecordId, l_numGardRecords);
        }
    }
    
    return l_pErr;
}

}
