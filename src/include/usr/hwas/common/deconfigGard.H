/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/deconfigGard.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

#include <targeting/common/commontargeting.H>

class HwasGardTest;

namespace HWAS
{

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

    // Allow HwasGardTest to access private methods.
    friend class ::HwasGardTest;

public:

    // enums for events codes for Gard events
    // used by platLogEvent() function
    enum GardEvent
    {                       // if GARD record:
        GARD_APPLIED,       //  applied
        MFG,                //  not applied due to MFG policy
        PREDICTIVE,         //  not applied due to predictive policy
        PREDICATE,          //  not applied due to predicate
        GARD_NOT_APPLIED,   //  not applied for other reason
    };

    // enums to indicate to deconfigureTarget() specific RUNTIME behaviors
    enum DeconfigureRuntime
    {
        NOT_AT_RUNTIME,     // non-runtime behavior - if the system is at
                            // runtime, no deconfigs happen;

                            // runtime behaviors:
        FULLY_AT_RUNTIME,   // - functional=false,dumpfunctional=false
        DUMP_AT_RUNTIME,    // - functional=false,dumpfunctional=true
    };

    // enums to indicate non-error reason for a targets deconfiguration.
    //  used in TARGETING::HwasSate.deconfiguredByEid
    enum DeconfiguredByReason
    {
        DECONFIGURED_BY_CODE_BASE               = 0x0000FF00,

        // set when GARD_User_Manual
        DECONFIGURED_BY_MANUAL_GARD,            // BASE | 0x01

        // set by processFieldCoreOverride() in hwas/common/deconfigGard.C
        DECONFIGURED_BY_FIELD_CORE_OVERRIDE,    // BASE | 0x02

        // set by call_mss_getecid() in dmi_training.c
        DECONFIGURED_BY_MEMORY_CONFIG,          // BASE | 0x03

        // set by discover_targets() when mcs is disabled b/c there
        // is a non functional membuf
        DECONFIGURED_BY_NO_CHILD_MEMBUF,        // BASE | 0x04

        // set by deconfigureAssocProc() in hwas/common/deconfigGard.C
        DECONFIGURED_BY_BUS_DECONFIG,           // BASE | 0x05

        // set by prd code, deconfigures at runtime
        DECONFIGURED_BY_PRD,                    // BASE | 0x06

        // set for PHYP initiated deconfigure
        DECONFIGURED_BY_PHYP,                   // BASE | 0x07

        // set for SPCN initiated deconfigure
        DECONFIGURED_BY_SPCN,                   // BASE | 0x08

        // set by discoverTargets() when functional children
        // are found connected to a non-functional Centaur
        DECONFIGURED_BY_NO_PARENT_MEMBUF,       // BASE | 0x09

        // set by presentByAssoc() when a MEMBUF has no DIMMs
        DECONFIGURED_BY_NO_CHILD_DIMM,          // BASE | 0x0A

        // set by presentByAssoc() when a MEMBUF has no MCS
        DECONFIGURED_BY_NO_PARENT_MCS,          // BASE | 0x0B

        // mask - these bits mean it's a PLID and not an enum
        DECONFIGURED_BY_PLID_MASK                = 0xFFFF0000,
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
        uint32_t              iv_errlogEid;
        uint8_t               iv_errorType; //from hwasCallout.H GARD_ErrorType
        uint8_t               iv_ResourceRecovery;
        uint8_t               iv_padding[6];
    };

    typedef std::vector<GardRecord> GardRecords_t;
    typedef std::vector<GardRecord>::iterator GardRecordsItr_t;
    typedef std::vector<GardRecord>::const_iterator GardRecordsCItr_t;
    typedef struct GardRecord GardRecord;
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
        uint32_t            iv_errlogEid; // plid OR deconfigReason value
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
     * @brief Re-log the PEL which caused the input Gard event
     *
     * @param  i_gardRecord    Reference to the Gard Record which will be
     *                         re-logged
     *
     * Called by HWAS common as part of the deconfigure targets from Gard
     * Records for IPL. Caller must pass distinct Gard PEL.
     *
     * @return errlHndl_t. Error log Handle
     * */
     errlHndl_t platReLogGardError(GardRecord &i_gardRecord);
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
     * @param[in]  i_target   Reference to Target to deconfigure.
     * @param[in]  i_errlEid Error log EID to store in Deconfigure Record.
     * @param[out] o_targetDeconfigured - if pointer is valid, bool is set
     *                  to true if target was deconfigured; NOT SET OTHERWISE
     * @param[in]  i_runTimeDeconfigRule Deconfigure Runtime options -
     *              default not at runtime
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTarget(TARGETING::Target & i_target,
                           const uint32_t i_errlEid,
                           bool *o_targetDeconfigured = NULL,
                           const DeconfigureRuntime i_runTimeDeconfigRule =
                                    NOT_AT_RUNTIME);

    /**
     * @brief Registers a Deferred Deconfigure
     *
     * Called from errludcallout, which is called
     * by hwasCallout when the user requests a
     * Deferred Deconfigure request.
     *
     * Create a deconfigure record, which will be handled in the function
     * processDeferredDeconfig().
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     *
     */
    void registerDeferredDeconfigure(const TARGETING::Target & i_target,
                                 const uint32_t i_errlEid);

    /**
     * @brief Platform specific function that
     *          logs a special trace event
     *
     * @param[in] i_pTarget  Pointer to Target
     * @param[in] i_eventType GardEvent enum
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t platLogEvent(const TARGETING::Target * const i_pTarget,
                                const GardEvent i_eventType);

    /**
     * @brief Platform specific function that
     *          Creates a GARD Record for a Target.
     *
     * @param[in] i_pTarget  Pointer to Target to create GARD Record for.
     * @param[in] i_errlEid Error log EID to store in GARD Record.
     * @param[in] i_errorType error type of the GARD Record.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t platCreateGardRecord(const TARGETING::Target * const i_pTarget,
                                const uint32_t i_errlEid,
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
     * @brief Maximum number of A/X bus endpoints. Used to initialize
     *        ProcInfo structs.
     */
    static const uint8_t NUM_A_BUSES = 3; // Max number of ABus links
    static const uint8_t NUM_X_BUSES = 4; // Max number of XBus links

    /**
     * @brief  Struct representing a particular processor.  Used by
     * _invokeDeconfigureAssocProc to populate a vector of procInfo's
     * effectively describing the current system state for subsequent use by
     * _deconfigureAssocProc
     */
    struct ProcInfo
    {
        // target for this chip
        TARGETING::Target * iv_pThisProc;
        TARGETING::ATTR_HUID_type procHUID;
        TARGETING::ATTR_FABRIC_NODE_ID_type procFabricNode;
        TARGETING::ATTR_FABRIC_CHIP_ID_type procFabricChip;
        bool iv_masterCapable;
        bool iv_deconfigured;

        // targets defining A link connected chips
        ProcInfo * iv_pAProcs[NUM_A_BUSES];
        bool iv_ADeconfigured[NUM_A_BUSES];

        // targets defining X link connected chips
        ProcInfo * iv_pXProcs[NUM_X_BUSES];
        bool iv_XDeconfigured[NUM_X_BUSES];
    };

    // Structure populated in _invokeDeconfigureAssocProc() for use in
    // _deconfigureAssocProc()
    typedef std::vector<ProcInfo> ProcInfoVector;

    /**
     * @brief Deconfigures Targets by association.
     *
     * @param[in] i_target   Reference to base Target.
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     * @param[in] i_runTimeDeconfigRule Deconfigure Runtime options -
     *              default not at runtime
     */
    void _deconfigureByAssoc(TARGETING::Target & i_target,
                             const uint32_t i_errlEid,
                             const DeconfigureRuntime i_runTimeDeconfigRule =
                                    NOT_AT_RUNTIME);

    /**
     * @brief Deconfigures a Target.
     *
     * This will Deconfigure the Target (set state to non-functional, do any
     * Deconfigure actions and create a Deconfigure Record).
     *
     * @param[in] i_target   Reference to Target to deconfigure.
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     * @param[out] o_targetDeconfigured - if pointer is valid, bool is set
     *                  to true if target was deconfigured; NOT SET OTHERWISE
     * @param[in] i_runTimeDeconfigRule Deconfigure Runtime options -
     *              default not at runtime
     */
    void _deconfigureTarget(TARGETING::Target & i_target,
                            const uint32_t i_errlEid,
                            bool *o_targetDeconfigured = NULL,
                            const DeconfigureRuntime i_runTimeDeconfigRule =
                                    NOT_AT_RUNTIME);

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
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     */
    void _createDeconfigureRecord(const TARGETING::Target & i_target,
                                  const uint32_t i_errlEid);


    /**
     *  @brief Invokes _deconfigureAssocProc
     *
     *  Called by deconfigureAssocProc and
     *  deconfigureTargetsFromGardRecordsForIpl. This function queries the
     *  system and populates a vector of structs which represent
     *  processors.  This vector is then passed to _deconfigureAssocProc
     *  which systematically marks processors to be deconfigured based
     *  on previously deconfigured bus endpoint chiplets.  Upon
     *  completion of _deconfigureAssocProc, this function iterates
     *  through the returned vector and deconfigures any proc marked
     *  for deconfiguration.
     *
     *  @param[in] i_node           restrict processing - only apply algorithm
     *                              to targets that match the predicate
     *  @param[in] i_doAbusDeconfig indicates if abus logic should be considered
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    errlHndl_t _invokeDeconfigureAssocProc(
                TARGETING::ConstTargetHandle_t i_node = NULL,
                bool i_doAbusDeconfig = true);

    /**
     *  @brief _deconfigureAssocProc deconfigures procs based on
     *         deconfigured x/a buses.
     *
     *  Run once per logical node, this algorithm systematically
     *  marks processors, by setting deconfigured booleans in a
     *  vector of structs which represent the processors, for
     *  deconfiguration based on previously deconfigured bus endpoint
     *  chiplets. Upon completion, this function then calls
     *  _symmetryValidation to ensure all logical nodes are symmetric
     *  from an available processor standpoint.
     *
     *  @param[in/out]  io_procInfo  Reference to vector of ProcInfo struct
     *                               pointers which contain the pertinant
     *                               information about a particular processor
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    static errlHndl_t _deconfigureAssocProc(ProcInfoVector &io_procInfo);

    /**
     *  @brief Performs SMP node balancing
     *
     *  Called by _deconfigureAssocProc.
     *  This function examines a vector of structs representing
     *  processors, and systematically marks processors to be
     *  deconfigured based on the state of the master-proc-containing
     *  logical node to ensure symmetry from an available processor
     *  standpoint.
     *
     *  @param[in/out]  io_procInfo  Reference to vector of ProcInfo struct
     *                               pointers which contain the pertinant
     *                               information about a particular processor
     *
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    static errlHndl_t _symmetryValidation(ProcInfoVector &io_procInfo);

    /**
     *  @brief Clear all Deconfigure due to Field Core Override
     *
     *  Called by processFieldCoreOverride.
     *  This function clears the deconfiguration based on
     *  field core override and prepare for applying filed core override
     *  again.
     *
     *  @param[in]  i_nodeTarget Node which FCO to be cleared.
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    static void _clearFCODeconfigure(
                TARGETING::ConstTargetHandle_t i_nodeTarget);

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
     *  @brief processDeferredDeconfig process any deferred deconfigure
     *              callouts that might have been 'queued' up.
     *              This is called from the istep dispatcher
     */
    void processDeferredDeconfig();

    /**
     *  @brief Starts deconfiguration of procs based on deconfigured
     *  bus endpoints process
     *
     *  Called by call_host_startprd_pbus (istep 8.6).  This function
     *  calls _invokeDeconfigureAssocProc to begin the calculated
     *  deconfiguration of processors based on previously deconfigured
     *  bus endpoint chiplets.
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    errlHndl_t deconfigureAssocProc();

    /**
     *  @brief Sets iv_XABusEndpointDeconfigured
     *
     *  @param[in] deconfig Allows iv_XABusEndpointDeconfigured to be set
     *                      to true/false
     *
     */
    void setXABusEndpointDeconfigured(bool deconfig);

private:

    // Mutex for thread safety
    HWAS_MUTEX_TYPE iv_mutex;

    // The Deconfigure Records
    DeconfigureRecords_t iv_deconfigureRecords;

    // pointer to plat specific data
    // platform functions can malloc space here if needed;
    // deconfigGard dtor will free()
    void *iv_platDeconfigGard;

    /**
     * @brief  Flag indicating if _deconfigureTarget has deconfigured an
     * x/a bus endpoint.
     *
     * Used by _invokeDeconfigureAssocProc.  If true,
     * _invokeDeconfigureAssocProc will execute and then call
     * _deconfigureAssocProc.  If false, there is no work to be done
     * and _invokeDeconfigureAssocProc will break and return.
     */
    bool iv_XABusEndpointDeconfigured;


}; // DeconfigGard
HWAS_DECLARE_SINGLETON(HWAS::DeconfigGard,theDeconfigGardSingleton);

}

#endif
