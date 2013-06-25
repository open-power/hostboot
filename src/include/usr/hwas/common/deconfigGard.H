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
 *  @brief processDeferredDeconfig process any deferred deconfigure callouts
 *              that might have been 'queued' up.
 *
 *  This is outside of the DeconfigGard class because it is called
 *
 *  @return bool true if there were deferred deconfigure callouts;
 *               false if there were NO deferred deconfigure callouts;
 */
bool processDeferredDeconfig();

/**
 * @brief   collectGard   Common HWAS function to collect the GARD info
 *
 *  It will call into hwas platform-specific functions.
 *
 * @param  i_pPredicate     restrict processing - only look at GARD records
 *                          for targets that match the predicate (optional)
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t collectGard(const TARGETING::PredicateBase *i_pPredicate = NULL);

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

public:

    enum
    {
        CLEAR_ALL_GARD_RECORDS = EMPTY_GARD_RECORDID,
        GET_ALL_GARD_RECORDS = EMPTY_GARD_RECORDID,
    };

    // enums to indicated non-error reason for a targets deconfiguration.
    //  used in TARGETING::HwasSate.deconfiguredByPlid
    enum
    {
        DECONFIGURED_BY_CODE_BASE               = 0x0000FF00,

        // set when GARD_User_Manual
        DECONFIGURED_BY_MANUAL_GARD,            // BASE | 0x01

        // set by processFieldCoreOverride() in hwas/common/deconfigGard.C
        DECONFIGURED_BY_FIELD_CORE_OVERRIDE,    // BASE | 0x02

        // set by call_mss_getecid() in dmi_training.c
        DECONFIGURED_BY_MEMORY_CONFIG,          // BASE | 0x03
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
        uint32_t              iv_errlogPlid;
        uint8_t               iv_errorType; //from hwasCallout.H GARD_ErrorType
        uint8_t               iv_ResourceRecovery;
        uint8_t               iv_padding[6];
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
        const TARGETING::Target * iv_target;
        uint32_t            iv_errlogPlid; // plid OR deconfigReason value
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
     * @param  i_pPredicate     restrict processing - only look at GARD records
     *                          for targets that match the predicate (optional)
     *
     * Called by HWAS as part of initial IPL steps.
     *
     * If deconfiguring all such Targets will result in a configuration that is
     * unable to IPL then it figures out which subset of Targets to deconfigure
     * to give the best chance of IPL (Resource Recovery).
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTargetsFromGardRecordsForIpl(
                const TARGETING::PredicateBase *i_pPredicate = NULL);

    /**
     * @brief Processes the Field Core Override attribute
     *
     * Called by HWAS as part of initial IPL steps.
     *
     * if the Field Core Override is non-zero, then functional cores will
     * be made non-functional, until the number of functional cores is equal
     * to the FCO value;
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t processFieldCoreOverride();

    /**
     * @brief Deconfigures a Target.
     *
     * Called from processCallout, which is called
     * by ErrlManager when committing an error log containing a
     * Deconfigure request.
     *
     * This will Deconfigure the Target (set state to non-functional, do any
     * Deconfigure actions and create a Deconfigure Record) and Deconfigure
     * Targets by association. Any errors deconfiguring targets are committed
     * and the function continues. The only errors returned are usage errors.
     * By default, targets are NOT deconfigured if the system is at Runtime.
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     * @param[in] i_evenAtRunTime Deconfigure even if at RunTime
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTarget(TARGETING::Target & i_target,
                                 const uint32_t i_errlPlid,
                                 bool i_evenAtRunTime = false);
    /**
     * @brief Registers a Deferred Deconfigure
     *
     * Called from errludcallout, which is called
     * by hwasCallout when the user requests a
     * Deferred Deconfigure request.
     *
     * For now, just put a mark on the wall indicating that we got a deferred
     * deconfigure callout
     * TODO RTC: 45781
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlPlid Error log PLID to store in Deconfigure Record.
     *
     */
    void registerDeferredDeconfigure(const TARGETING::Target & i_target,
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
     * @param[in] i_pTarget   Pointer to Target to create GARD Record for.
     * @param[in] i_errlPlid Error log PLID to store in GARD Record.
     * @param[in] i_errorType error type of the GARD Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t createGardRecord(const TARGETING::Target * const i_pTarget,
                                const uint32_t i_errlPlid,
                                const GARD_ErrorType i_errorType);

    /**
     * @brief Platform specific function that
     *          Creates a GARD Record for a Target.
     *
     * @param[in] i_pTarget  Pointer to Target to create GARD Record for.
     * @param[in] i_errlPlid Error log PLID to store in GARD Record.
     * @param[in] i_errorType error type of the GARD Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t platCreateGardRecord(const TARGETING::Target * const i_pTarget,
                                const uint32_t i_errlPlid,
                                const GARD_ErrorType i_errorType);

    /**
     * @brief Clears GARD Record for the specified Target, or ALL GARD
     *          records.
     *
     * Called by an administrator to clear GARD records manually.
     *
     * If no GARD Records exist for the Target then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in] i_pTarget Pointer to Target to clear GARD record for.
     *              If NULL, then ALL GARD Records will be cleared.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecords(const TARGETING::Target * const i_pTarget);

    /**
     * @brief Platform specific function that
     *          Clears Record for the specified Target.
     *
     * @param[in] i_pTarget Pointer to Target to clear GARD record for.
     *              If NULL, then ALL GARD Records will be cleared.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t platClearGardRecords(const TARGETING::Target * const i_pTarget);

    /**
     * @brief Gets all GARD Records for the specified Target.
     *
     * Called by an administrator to view GARD Records.
     *
     * If no GARD Records exist for the Target then no error is returned. The
     * only errors returned are usage errors and errors accessing the GARD
     * Records.
     *
     * @param[in]  i_pTarget  Pointer to Sys or Node Target
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t getGardRecords(const TARGETING::Target * const i_pTarget,
                              GardRecords_t & o_records);

    /**
     * @brief Platform specific function that
     *          Gets all GARD Records for the specified Target.
     *
     * @param[in]  i_pTarget  Pointer to Sys or Node Target
     * @param[out] o_records  Reference to vector of GardRecords that is cleared
     *                        then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t platGetGardRecords(const TARGETING::Target * const i_pTarget,
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
     */
    void _deconfigureTarget(TARGETING::Target & i_target,
                            const uint32_t i_errlPlid);

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
     */
    void _createDeconfigureRecord(const TARGETING::Target & i_target,
                                  const uint32_t i_errlPlid);

public:

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
     * @note Provided for unit test only. Production code should not be
     *       clearing Deconfigure Records.
     *
     * @param[in]  i_pTargetId Pointer to the Target ID to get the Deconfigure
     *                         Record for. If NULL then all Deconfigure Records
     *                         are retrieved.
     * @param[out] o_records   Reference to vector of DeconfigureRecords that is
     *                         cleared then filled in with records.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t _getDeconfigureRecords(const TARGETING::Target * const i_pTarget,
                                     DeconfigureRecords_t & o_records);

    /**
     * @brief Clears the specified Deconfigure Records.
     *
     * @param[in] i_pTargetId Pointer to the Target ID to clear Deconfigure
     *                        Records for. If NULL then all Deconfigure Records
     *                        are cleared.
     */
    void clearDeconfigureRecords(const TARGETING::Target * const i_pTarget);


    /**
     *  @brief _processDeferredDeconfig process any deferred deconfigure
     *              callouts that might have been 'queued' up.
     *
     *  @return bool true if there were deferred deconfigure callouts;
     *               false if there were NO deferred deconfigure callouts;
     */
    bool _processDeferredDeconfig();

private:

    // Mutex for thread safety
    HWAS_MUTEX_TYPE iv_mutex;

    // The Deconfigure Records
    DeconfigureRecords_t iv_deconfigureRecords;

    // pointer to plat specific data
    // platform functions can malloc space here if needed;
    // deconfigGard dtor will free()
    void *iv_platDeconfigGard;

}; // DeconfigGard
HWAS_DECLARE_SINGLETON(HWAS::DeconfigGard,theDeconfigGardSingleton);

}

#endif
