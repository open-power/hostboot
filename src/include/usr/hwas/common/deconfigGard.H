/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/deconfigGard.H $                  */
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
 *  @file deconfigGard.H
 *
 *  @brief Defines the DeconfigGard class that provides functions to deconfigure
 *  and create GARD records for Targets
 */

#ifndef DECONFIGGARD_H_
#define DECONFIGGARD_H_

#include <vector>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <targeting/common/attributes.H>
#include <hwas/hwasPlatDeconfigGard.H>
#include <hwas/hwasPlatThread.H>

namespace HWAS
{

/**
 * @brief   collectGard   Common HWAS function to collect the GARD info
 *
 *  It will call into hwas platform-specific functions.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t collectGard();

/**
 * @brief Returns a reference to the DeconfigGard singleton.
 */
class DeconfigGard;
DeconfigGard & theDeconfigGard();

/**
 * @class DeconfigGard
 *
 * This class defines the singleton that handles Deconfigure and GARD Record
 * functionality
 */
class DeconfigGard
{

    // allow GardAddress to access private methods.
    friend class GardAddress;

public:

    /**
     * @enum DeconfigCause
     *
     * Defines the possible causes for the creation of a Deconfigure Record
     */
    enum DeconfigCause
    {
        DECONFIG_CAUSE_GARD_RECORD       = 1,  // Existence of GARD Record
        DECONFIG_CAUSE_FIRMWARE_REQ      = 2,  // Firmware Request
        DECONFIG_CAUSE_DECONFIG_BY_ASSOC = 3,  // Deconfigure by Association
    };

    enum 
    {
        CLEAR_ALL_GARD_RECORDS = EMPTY_GARD_RECORDID,
        GET_ALL_GARD_RECORDS = EMPTY_GARD_RECORDID,
    };

    /**
     * @struct GardRecord
     *
     * Defines a GARD Record.
     * 
     * Multiple GARD Records can exist for a specific Target
     */
    struct GardRecord
    {
        uint32_t              iv_recordId;
        TARGETING::EntityPath iv_targetId;
        union
        {
            char iv_cardMruSn[12]; // TODO is there a SN type?
            uint32_t iv_chipMruEcid; // TODO is there an ECID type?
        };
        uint32_t              iv_errlogPlid;
        uint8_t               iv_errorType; // Value from GARD_ErrorType
        uint8_t               iv_padding[3];
        uint32_t              iv_gardTime;
    };

    typedef std::vector<GardRecord> GardRecords_t;
    typedef std::vector<GardRecord>::iterator GardRecordsItr_t;
    typedef std::vector<GardRecord>::const_iterator GardRecordsCItr_t;

    /**
     * @struct DeconfigureRecord
     *
     * Defines a Deconfigure Record for deferred deconfigures
     * 
     * Only one Deconfigure Record can exist for a specific Target
     */
    struct DeconfigureRecord
    {
        TARGETING::EntityPath iv_targetId;
        uint32_t              iv_errlogPlid;
        uint8_t               iv_cause; // Value from DeconfigCause
        uint8_t               iv_padding[3];
        uint32_t              iv_deconfigureTime;
    };

    typedef std::vector<DeconfigureRecord> DeconfigureRecords_t;
    typedef std::vector<DeconfigureRecord>::iterator DeconfigureRecordsItr_t;
    typedef std::vector<DeconfigureRecord>::const_iterator DeconfigureRecordsCItr_t;

    /**
     * @brief Destructor.
     */
    ~DeconfigGard();

    /**
     * @brief Clears GARD Records for replaced Targets.
     *
     * Called by HWAS as part of initial IPL steps.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecordsForReplacedTargets();

    /**
     * @brief Deconfigures Targets that have GARD Records in preparation to IPL.
     *
     * Called by HWAS as part of initial IPL steps.
     *
     * If deconfiguring all such Targets will result in a configuration that is
     * unable to IPL then it figures out which subset of Targets to deconfigure
     * to give the best chance of IPL (Resource Recovery).
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTargetsFromGardRecordsForIpl();

    /**
     * @brief Deconfigures a Target.
     *
     * Called by ErrlManager when committing an error log containing a
     * Deconfigure request.
     * 
     * This will Deconfigure the Target (set state to non-functional, do any
     * Deconfigure actions and create a Deconfigure Record) and Deconfigure
     * Targets by association. Any errors deconfiguring targets are committed
     * and the function continues. The only errors returned are usage errors.
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTarget(TARGETING::Target & i_target,
                                 const uint32_t i_errlPlid);

    /**
     * @brief Creates a GARD Record for a Target.
     *
     * Called by ErrlManager when committing an error log containing a
     * GARD Record request.
     * 
     * Called by an administrator to manually create a GARD Record.
     * 
     * Any error creating the GARD Record will be returned to the user.
     *
     * @param[in] i_target   Reference to Target to create GARD Record for.
     * @param[in] i_errlPlid Error log PLID to store in GARD Record.
     * @param[in] i_errorType error type of the GARD Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t createGardRecord(const TARGETING::Target & i_target,
                                const uint32_t i_errlPlid,
                                const GARD_ErrorType i_errorType);

    /**
     * @brief Gets the specified Deconfigure Records.
     *
     * Called by an administrator to view Deconfigure Records. There can only be
     * one Deconfiguration Record per Target.
     * 
     * If the specified record does not exist then no error is returned. The
     * only errors returned are usage errors and errors accessing the
     * Deconfigure Records.
     *
     * @param[in]  i_pTargetId Pointer to the Target ID to get the Deconfigure
     *                         Record for. If NULL then all Deconfigure Records
     *                         are retrieved.
     * @param[out] o_records   Reference to vector of DeconfigureRecords that is
     *                         cleared then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t getDeconfigureRecords(const TARGETING::EntityPath * i_pTargetId,
                                     DeconfigureRecords_t & o_records);
    
    /**
     * @brief Clears the specified GARD Records.
     *
     * Called by an administrator to clear GARD records manually.
     * 
     * If the specified record does not exist then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in] i_recordId RecordId to clear. If zero (CLEAR_ALL_GARD_RECORDS)
     *                          then all GARD Records cleared.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecords(const uint32_t i_recordId);

    /**
     * @brief Clears all GARD Records for the specified Target.
     *
     * Called by an administrator to clear GARD records manually.
     * 
     * If no GARD Records exist for the Target then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in] i_targetId Reference to Target ID to clear GARD Records for.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecords(const TARGETING::EntityPath & i_targetId);

    /**
     * @brief Gets the specified GARD Records.
     *
     * Called by an administrator to view GARD Records.
     * 
     * If the specified record does not exist then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in]  i_recordId RecordId to get. If zero then all GARD Records are
     *                        retrieved.
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t getGardRecords(const uint32_t i_recordId,
                              GardRecords_t & o_records);

    /**
     * @brief Gets all GARD Records for the specified Target.
     *
     * Called by an administrator to view GARD Records.
     * 
     * If no GARD Records exist for the Target then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in]  i_targetId Reference to Target ID to get GARD Records for.
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t getGardRecords(const TARGETING::EntityPath & i_targetId,
                              GardRecords_t & o_records);
    
protected:

    /**
     * @brief Default constructor
     * 
     * Can only be called by Singleton
     */
    DeconfigGard();

private:

    // Copy constructor and assignment operator disabled
    DeconfigGard(const DeconfigGard & i_right);
    DeconfigGard & operator=(const DeconfigGard & i_right);

    /**
     * @brief Deconfigures Targets by association.
     *
     * @param[in] i_target   Reference to base Target.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     */
    void _deconfigureByAssoc(TARGETING::Target & i_target,
                             const uint32_t i_errlPlid);
    
    /**
     * @brief Deconfigures a Target.
     *
     * This will Deconfigure the Target (set state to non-functional, do any
     * Deconfigure actions and create a Deconfigure Record).
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     * @param[in] i_cause    Deconfigure cause.
     */
    void _deconfigureTarget(TARGETING::Target & i_target,
                            const uint32_t i_errlPlid,
                            const DeconfigCause i_cause);
    
    /**
     * @brief Performs Deconfigure Actions.
     *
     * @param[in] i_target Reference to Target to perform actions on.
     */
    void _doDeconfigureActions(TARGETING::Target & i_target);

    /**
     * @brief Creates a Deconfigure Record
     *
     * @param[in] i_target   Reference to Target to create record for.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     * @param[in] i_cause    Deconfigure cause.
     */
    void _createDeconfigureRecord(const TARGETING::Target & i_target,
                                  const uint32_t i_errlPlid,
                                  const DeconfigCause i_cause);
    
public:
    
    /**
     * @brief Clears the specified Deconfigure Records.
     * 
     * @note Provided for unit test only. Production code should not be
     *       clearing Deconfigure Records.
     *
     * @param[in] i_pTargetId Pointer to the Target ID to clear Deconfigure
     *                        Records for. If NULL then all Deconfigure Records
     *                        are cleared.
     */
    void _clearDeconfigureRecords(const TARGETING::EntityPath * i_pTargetId);
    
private:
    /**
     * @brief Gets the specified Deconfigure Records.
     *
     * @param[in]  i_pTargetId Pointer to the Target ID to get the Deconfigure
     *                         Record for. If NULL then all Deconfigure Records
     *                         are retrieved.
     * @param[out] o_records   Reference to vector of DeconfigureRecords that is
     *                         cleared then filled in with records.
     */
    void _getDeconfigureRecords(const TARGETING::EntityPath * i_pTargetId,
                                DeconfigureRecords_t & o_records) const;
    
    /**
     * @brief Creates a GARD Record for a Target.
     * 
     * @param[in] i_target   Reference to Target to create GARD Record for.
     * @param[in] i_errlPlid Error log PLID to store in GARD Record.
     * @param[in] i_errorType Error Type of the GARD Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _createGardRecord(const TARGETING::Target & i_target,
                                 const uint32_t i_errlPlid,
                                 const GARD_ErrorType i_errorType);
    
    /**
     * @brief Clears the specified GARD Records.
     *
     * @param[in] i_recordId RecordId to clear. If zero (CLEAR_ALL_GARD_RECORDS)
     *                          then all GARD Records cleared.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _clearGardRecords(const uint32_t i_recordId);
    
    /**
     * @brief Clears all GARD Records for the specified Target.
     *
     * @param[in] i_targetId Reference to Target ID to clear GARD Records for.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _clearGardRecords(const TARGETING::EntityPath & i_targetId);

    /**
     * @brief Gets the specified GARD Records.
     *
     * @param[in]  i_recordId RecordId to get. If zero then all GARD Records are
     *                        retrieved.
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _getGardRecords(const uint32_t i_recordId,
                               GardRecords_t & o_records);
    
    /**
     * @brief Gets all GARD Records for the specified Target.
     *
     *
     * @param[in]  i_targetId Reference to Target ID to get GARD Records for.
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _getGardRecords(const TARGETING::EntityPath & i_targetId,
                               GardRecords_t & o_records);
    
    /**
     * @brief sets the maxGardRecords and nextGardRecordId variables
     * 
     * @param[in]  i_size size of GARD area in PNOR/memory
     */
    void _GardRecordIdSetup(uint32_t i_size);

    // Mutex for thread safety
    HWAS_MUTEX_TYPE iv_mutex;

    // GARD Record Data
    uint32_t iv_nextGardRecordId;   // Next GARD Record ID to use
    uint32_t iv_maxGardRecords;     // Maximum number of GARD Records
    GardRecord * iv_pGardRecords;   // Pointer to the GARD Records in PNOR

    // The Deconfigure Records
    DeconfigureRecords_t iv_deconfigureRecords;


}; // DeconfigGard
HWAS_DECLARE_SINGLETON(HWAS::DeconfigGard,theDeconfigGardSingleton);

// The HWAS Common code needs to allow for the fact that the platforms
//  may need to know when the DeconfigGard functions are done using the
//  PNOR area for GARD record access. To this end, GardAddress is an
//  object that the common code will create when it needs to use the
//  address to the GARD records data (iv_pGardRecords). When this object
//  goes out of scope, the destructor will get called, and the platform
//  code will know that access to the PNOR area is complete.
class GardAddress
{
public:

    /**
     * @brief Constructor.
     *  PLATFORM must implement this function
     *
     * @param[in]  o_gardEnabled  boolean returned:
     *                  true - reading/writing of gard records is enabled;
     *                  false - not enabled
     */
    GardAddress(bool &o_gardEnabled);

    /**
     * @brief Destructor.
     *  PLATFORM must implement this function
     */
    ~GardAddress();

    /**
     * @brief writeRecord. Add the indicated address to a vector, so
     *  that the destructor knows which GARD records were updated.
     *
     * @param[in]  i_addr  address of GARD record that was updated.
     */
    void writeRecord(void *i_addr)
    {
        if (i_addr !=NULL)
        {
            iv_addr.push_back(i_addr);
        }
    }

protected:

    std::vector<void *>iv_addr;

}; // GardAddress
}

#endif
