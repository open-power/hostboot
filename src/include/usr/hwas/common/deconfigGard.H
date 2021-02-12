/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/deconfigGard.H $                  */
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
#include <targeting/common/targetservice.H>

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
 * @brief   clearGardByType   Common HWAS function to clear all GARD records of
 *                            given type
 *
 *  It will call into hwas platform-specific functions.
 *
 * @param  i_type           Type of records to be cleared
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t clearGardByType(const GARD_ErrorType i_type);

/**
 * @brief  updateAttrPG
 *
 *                                  Common HWAS function to set the PG attribute
 *                                  of a target by updating ATTR_PG.
 *
 * @param  i_target                 The target to update.
 * @param  i_shouldSetFunctional    If true will update ATTR_PG to functional,
 *                                  else it will be set to not-functional.
 */
void updateAttrPG(TARGETING::Target& i_target,
                           const bool i_shouldSetFunctional);

/**
 * @brief getDeconfigMaskedPGValue
 *
 *                          Common HWAS function to get the deconfigured masked
 *                          PG entry value of a target.
 *
 * @param[in] i_target      Target whose masked PG value is calculated.
 *
 * @return pg_entry_t       Masked PG value.
 */
pg_entry_t getDeconfigMaskedPGValue(const TARGETING::Target& i_target);

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
        RESOURCE_RECOVERED  //  Resource recovered
    };

    // enums to indicate to deconfigureTarget() specific behaviors
    enum DeconfigureFlags
    {
        NOT_AT_RUNTIME,     // non-runtime behavior - if the system is at
                            // runtime, no deconfigs happen;

                            // runtime behaviors:
        FULLY_AT_RUNTIME,   // - functional=false,dumpfunctional=false
        DUMP_AT_RUNTIME,    // - functional=false,dumpfunctional=true
        SPEC_DECONFIG,      //speculative deconfig
    };

    // enums to indicate non-error reason for a targets deconfiguration.
    //  used in TARGETING::HwasSate.deconfiguredByEid
    enum DeconfiguredByReason
    {
        INVALID_DECONFIGURED_BY_REASON,

        DECONFIGURED_BY_CODE_BASE               = 0x0000FF00,

        // set when GARD_User_Manual
        DECONFIGURED_BY_MANUAL_GARD,            // BASE | 0x01

        // set by processFieldCoreOverride() in hwas/common/deconfigGard.C
        DECONFIGURED_BY_FIELD_CORE_OVERRIDE,    // BASE | 0x02

        // set by call_mss_getecid() in dmi_training.c
        DECONFIGURED_BY_MEMORY_CONFIG,          // BASE | 0x03

        // set by presentByAssoc() when a MCS has no MCAs
        DECONFIGURED_BY_NO_CHILD_MCA,           // BASE | 0x04
        // TODO RTC 149367 Remove deprecated enumeration once hwsv is not using
        DECONFIGURED_BY_NO_CHILD_MEMBUF =      //Deprecated
           DECONFIGURED_BY_NO_CHILD_MCA,
        DECONFIGURED_BY_NO_CHILD_MEMBUF_OR_MCA =  //Deprecated, but needed by FSP
           DECONFIGURED_BY_NO_CHILD_MCA,

        // set by deconfigureAssocProc() in hwas/common/deconfigGard.C
        DECONFIGURED_BY_BUS_DECONFIG,           // BASE | 0x05

        // set by prd code, deconfigures at runtime
        DECONFIGURED_BY_PRD,                    // BASE | 0x06

        // set for PHYP initiated deconfigure
        DECONFIGURED_BY_PHYP,                   // BASE | 0x07

        // set for SPCN initiated deconfigure
        DECONFIGURED_BY_SPCN,                   // BASE | 0x08

        // set by presentByAssoc() when a MBA has no MEMBUF
        DECONFIGURED_BY_NO_PARENT_MEMBUF,       // BASE | 0x09

        // set by presentByAssoc() when a MBA has no DIMMs
        DECONFIGURED_BY_NO_CHILD_DIMM,          // BASE | 0x0A

        // set by presentByAssoc() when a MEMBUF has no MCS
        DECONFIGURED_BY_NO_PARENT_DMI,          // BASE | 0x0B
        DECONFIGURED_BY_NO_PARENT_MCS =
            DECONFIGURED_BY_NO_PARENT_DMI,
        // set by presentByAssoc() when a MEMBUF has no MBAs
        DECONFIGURED_BY_NO_CHILD_MBA,           // BASE | 0x0C

        // set by presentByAssoc() when a DIMM has no MBA or MCA or MEMPORT
        //@TODO RTC 196804: Rename to
        //                  DECONFIGURED_BY_NO_PARENT_MBA_OR_MCA_OR_MEMPORT
        DECONFIGURED_BY_NO_PARENT_MBA_OR_MCA,   // BASE | 0x0D
        // TODO RTC 149367 Remove deprecated enumeration once hwsv is not using
        DECONFIGURED_BY_NO_PARENT_MBA =         //Deprecated
            DECONFIGURED_BY_NO_PARENT_MBA_OR_MCA,

        CONFIGURED_BY_RESOURCE_RECOVERY,        // BASE | 0x0E
        //
        DECONFIGURED_BY_EQ_DECONFIG,            // BASE | 0x0F
        DECONFIGURED_BY_FC_DECONFIG,            // BASE | 0x10
        DECONFIGURED_BY_CORE_DECONFIG,          // BASE | 0x11
        DECONFIGURED_BY_PHB_DECONFIG,           // BASE | 0x12
        DECONFIGURED_BY_PEC_DECONFIG,           // BASE | 0x13
        DECONFIGURED_BY_NO_CHILD_MCS,           // BASE | 0x14
        DECONFIGURED_BY_NO_PARENT_MCBIST,       // BASE | 0x15
        DECONFIGURED_BY_DISABLED_PORT,          // BASE | 0x16

        DECONFIGURED_BY_NO_CHILD_MI,            // BASE | 0x17
        //@TODO RTC 196804: Rename to DECONFIGURED_BY_NO_CHILD_DMI_OR_MCC
        DECONFIGURED_BY_NO_CHILD_DMI,           // BASE | 0x18
        DECONFIGURED_BY_NO_PARENT_MC,           // BASE | 0x19
        DECONFIGURED_BY_NO_PARENT_MI,           // BASE | 0x1A

        DECONFIGURED_BY_NO_MATCHING_LINK_SET,   // BASE | 0x1B
        //used when we deconfigure unused children of OBUS
        DECONFIGURED_BY_OBUS_MODE,              // BASE | 0x1C
        DECONFIGURED_BY_NO_CHILD_OMI,           // BASE | 0x1D
        DECONFIGURED_BY_NO_PARENT_MCC,          // BASE | 0x1E
        DECONFIGURED_BY_NO_CHILD_MEM_PORT,      // BASE | 0x1F
        DECONFIGURED_BY_NO_PARENT_OMI,          // BASE | 0x20
        DECONFIGURED_BY_NO_CHILD_OCMB_CHIP,     // BASE | 0x21
        DECONFIGURED_BY_NO_PARENT_OCMB_CHIP,    // BASE | 0x22
        DECONFIGURED_BY_NO_PARENT_OMIC,         // BASE | 0x23
        DECONFIGURED_BY_INACTIVE_PAU,           // BASE | 0x24
        DECONFIGURED_BY_NO_CHILD_OMIC,          // BASE | 0x25
        DECONFIGURED_BY_NO_CHILD_MCC,           // BASE | 0x26
        DECONFIGURED_BY_NO_PARENT_MEM_PORT,     // BASE | 0x27
        DECONFIGURED_BY_NO_PARENT_PAUC,         // BASE | 0x28
        DECONFIGURED_BY_NO_CHILD_PMIC,          // BASE | 0x29

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

    // clear ALL gard records will reset to CURRENT
    static const uint8_t PREVIOUS_GARD_VERSION_LAYOUT = 0x0;
    static const uint8_t CURRENT_GARD_VERSION_LAYOUT = 0x1;

    struct GardRecord
    {
        uint32_t              iv_recordId;       // all F's invalid gard record
        TARGETING::EntityPath iv_targetId;       // 21 bytes - Physical path of gard target
        uint32_t              iv_errlogEid;      // Gard initiator ID
        GARD_ErrorType        iv_errorType : 8;  // from hwasCallout.H GARD_ErrorType
        union {
            uint8_t           raw[80];       // 80 bytes
            struct                           // 19 bytes IBM 11S FRU Format
            {
                uint8_t       serialNum[12]; // Serial number of the containing FRU
                uint8_t       partNum[7];    // Part number of the containing FRU
            } PACKED ibm11S;
            struct                           // 22 bytes JEDEC standard DDR3 DIMM
            {
                uint8_t       serialNum[4];  // Serial number of the containing FRU
                uint8_t       partNum[18];   // Part number of the containing FRU
            } PACKED isdimmDDR3;
            struct                           // 24 bytes JEDEC standard DDR4 DIMM
            {
                uint8_t       serialNum[4];  // Serial number of the containing FRU
                uint8_t       partNum[20];   // Part number of the containing FRU
            } PACKED isdimmDDR4;
            struct                           // 34 bytes DDR4 DDIMM
            {
                uint8_t       serialNum[4];  // Serial number of the containing FRU
                uint8_t       partNum[30];   // Part number of the containing FRU
            } PACKED isddimmDDR4;
        } PACKED uniqueId;                   // 80 bytes
        uint8_t               iv_padding[18];
    } PACKED;                                // 128 bytes

    typedef std::vector<GardRecord> GardRecords_t;
    typedef struct GardRecord GardRecord;

    struct GardRecordsBinary
    {
        uint8_t               iv_magicNumber[8]; // magicNumber = GUARDREC
        uint8_t               iv_version;        // Gard records version
        uint8_t               iv_padding[7];
        GardRecord            iv_gardRecords[0];  // 128 bytes each - List of gard records
    } PACKED;

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
     * @brief Apply gard record for a specific target.
     *
     * Called by deconfigureTargetsFromGardRecordsForIpl.
     *
     * @param i_pTarget Target to be garded
     *
     * @param i_gardRecord gard record to be applied
     *
     * @param i_deconfigRule Options for deconfigure
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t applyGardRecord(TARGETING::Target *i_pTarget,
            GardRecord &i_gardRecord,
            const DeconfigureFlags i_deconfigRule =  NOT_AT_RUNTIME);

    /**
     * @brief Clears GARD Records for replaced Targets.
     *
     * Called by HWAS as part of initial IPL steps.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecordsForReplacedTargets();

    /**
     * @brief Clears GARD Records that match requested error type
     *
     * @param i_type error type to clear
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearGardRecordsByType(GARD_ErrorType i_type);

    /**
     * @brief Update HWAS fields for resource recovered targets
     *
     * @param  i_pPredicate     restrict processing - only look at GARD records
     *                          for targets that match the predicate (optional)
     *
     * If a speculatively garded resource has been enabled due to resource
     * recovery then we need to ensure it's HWAS states are properly updated
     * to reflect this.
     *
     * This function should only be called in situations where speculative
     * deconfig/resource recovery is being skipped due to it already being
     * run in a previous boot (i.e. ATTR_BLOCK_SPEC_DECONFIG == 1)
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t updateSpecDeconfigTargetStates(
                const TARGETING::PredicateBase *i_pPredicate = NULL);

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
     * @brief Clears all FCO deconfigures across all nodes, in preparation for
     *     assigning FCO resources.  Must be run prior to applying GARD records
     *     to avoid contention with deconfig by association corner cases.
     */
    void clearFcoDeconfigures();

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
    errlHndl_t platProcessFieldCoreOverride();

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
     * @param[in]  i_deconfigRule Deconfigure options -
     *              default not at runtime
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTarget(TARGETING::Target & i_target,
                           const uint32_t i_errlEid,
                           bool *o_targetDeconfigured = NULL,
                           const DeconfigureFlags i_deconfigRule =
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
     * @brief Dumps all GARD Records for the specified Target.
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
     * @return errlHndl_t     nullptr on success, otherwise valid error log handle.
     */
    errlHndl_t dumpGardRecords(const TARGETING::Target * const i_pTarget,
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

    /**
     * @brief Platform specific function that
     *         Will perform any post-deconfig operations,
     *         such as syncing state with other subsystems
     *
     * @param[in]  i_pTarget  Pointer to target
     */
    void platPostDeconfigureTarget(TARGETING::Target * i_pTarget);

    /**
     * @brief Deconfigures a Target at runtime
     *
     * Called from PRD, in response to a checkstop attention from phyp
     *
     * This function will call the platform specific function to do the
     * deconfigure actions.
     *
     * NOTE: Currently only core targets are supported
     *
     * @param[in]  i_pTarget   pointer to the target to deconfigure
     * @param[in]  i_deconfigureAction Deconfigure options -
     *                                              FULLY_AT_RUNTIME
     * @param[in]  i_deconfigErrl - error log assocated with this deconfig
     *                              request. The error handle is non-null
     *                              the eid of the errorlog will be listed as
     *                              the deconfig reason, otherwise the
     *                              reason will be DECONFIGURED_BY_PRD
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t deconfigureTargetAtRuntime(
            TARGETING::TargetHandle_t i_pTarget,
            const DeconfigureFlags i_deconfigureAction,
            const errlHndl_t i_deconfigErrl);

    /**
     *
     * @brief Deconfigures a Target at runtime
     *
     * Platform specific implementation to deconfgure a target at runtime
     *
     * This function will deconfigure the target, do any
     * post deconfigure actions and will skip deconfiguring any associated
     * child targets. Any errors deconfiguring targets are committed and
     * the function continues. The only errors returned are usage errors.
     *
     * @param[in]  i_pTarget   pointer to Target to deconfigure.
     * @param[in]  i_deconfigureAction Deconfigure options -
     *                                              FULLY_AT_RUNTIME
     * @param[in]  i_deconfigErrl - error log assocated with this deconfig
     *                              request. The error handle is non-null
     *                              the eid of the errorlog will be listed as
     *                              the deconfig reason, otherwise the
     *                              reason will be DECONFIGURED_BY_PRD
     *
     * @return errlHndl_t. Error log handle.
     */

#ifdef __HOSTBOOT_RUNTIME
    errlHndl_t platDeconfigureTargetAtRuntime(
            TARGETING::TargetHandle_t i_pTarget,
            const DeconfigureFlags i_deconfigureAction,
            const errlHndl_t i_deconfigErrl);
#endif

    /**
     * @brief Clears attribute which blocks speculative deconfiguration
     *     (ATTR_BLOCK_SPEC_DECONFIG) so that resource recovery is allowed to
     *     apply speculative deconfigurations / predictive gards.  Attribute
     *     is cleared only if a target has been replaced.
     *
     * @return ATTR_BLOCK_SPEC_DECONFIG.
     */
    uint8_t clearBlockSpecDeconfigForReplacedTargets();

    /**
     * @brief Clears attribute which blocks speculative deconfiguration
     *     (ATTR_BLOCK_SPEC_DECONFIG) so that resource recovery is allowed to
     *     apply speculative deconfigurations / predictive gards.  Attribute
     *     is cleared only if a target had gard applied but no longer does.
     *
     * @param[in/out]  io_blockAttr  ATTR_BLOCK_SPEC_DECONFIG value.
     *
     * @return errlHndl_t. Error log handle.
     */
    errlHndl_t clearBlockSpecDeconfigForUngardedTargets(uint8_t &io_blockAttr);

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
     * @brief Maximum number of endpoints. Used to initialize ProcInfo structs.
     */

    // NUM_OUT_GROUP_BUSES is the max number of bus links that connect procs
    // outside a particular fabric group. For SCM-based systems, "in-group"
    // means within the same drawer, while for DCM-based systems, each processor
    // is in its own group.
    //
    // On a single-node system with 4 DCMs/8 processors: each processor can have
    // a maximum of 5 IOHSes that link to other processors, and each IOHS can
    // have two SMPGROUP children. For a given IOHS, either the IOHS itself will
    // be processed by _deconfigureAssocProc, or else its two SMPGROUP children
    // will be processed, but not both. Therefore there can be a maximum of 5*2
    // = 10 out-group buses.
    static const uint8_t NUM_OUT_GROUP_BUSES = 10;

    // NUM_IN_GROUP_BUSES is the max number of bus links that connect procs
    // within the same fabric group. For SCM-based systems, "in-group" means
    // within the same drawer, while for DCM-based systems, each processor is in
    // its own group.
    //
    // On a multi-node system with 4 SCMs per node: each processor has a
    // maximum of 3 in-group (intra-node) IOHS-SMPX connections and 5 out-group
    // (inter-node) IOHS-SMPA connections. However, SMP-wrap mode on multi-node
    // system turns all the out-group/SMPA connections into in-group/SMPX
    // connections, so there will be a maximum of 2*(3 + 5) = 16 in-group
    // buses.
    static const uint8_t NUM_IN_GROUP_BUSES = 16;

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
        TARGETING::ATTR_FABRIC_GROUP_ID_type procFabricGroup;
        TARGETING::ATTR_FABRIC_CHIP_ID_type procFabricChip;
        bool iv_masterCapable;
        bool iv_deconfigured;

        // targets defining A link connected chips
        ProcInfo * iv_pOutGroupProcInfos[NUM_OUT_GROUP_BUSES];
        bool iv_OutGroupLinkDeconfigured[NUM_OUT_GROUP_BUSES];

        // targets defining X link connected chips
        ProcInfo * iv_pInGroupProcInfos[NUM_IN_GROUP_BUSES];
        bool iv_InGroupLinkDeconfigured[NUM_IN_GROUP_BUSES];
    };

    // Structure populated in _invokeDeconfigureAssocProc() for use in
    // _deconfigureAssocProc()
    typedef std::vector<ProcInfo> ProcInfoVector;

    /**
     * @brief Deconfigures Targets by association.
     *
     * @param[in] i_target   Reference to base Target.
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     * @param[in] i_deconfigRule Deconfigure Runtime options -
     *              default not at runtime
     */
    void _deconfigureByAssoc(TARGETING::Target & i_target,
                             const uint32_t i_errlEid,
                             const DeconfigureFlags i_deconfigRule =
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
     * @param[in] i_deconfigRule Deconfigure Runtime options -
     *                  default not at runtime
     */
    void _deconfigureTarget(TARGETING::Target & i_target,
                            const uint32_t i_errlEid,
                            bool *o_targetDeconfigured = NULL,
                            const DeconfigureFlags i_deconfigRule =
                                    NOT_AT_RUNTIME);

    /**
     * @brief Works deconfig up the parent branch
     *        Handles special cases like FCO deconfig and peer targets
     *
     * @param[in] i_target   Reference to child target
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     * @param[in] i_deconfigRule Deconfigure Runtime options
     */
    void _deconfigParentAssoc(TARGETING::Target & i_target,
                              const uint32_t i_errlEid,
                              const DeconfigureFlags i_deconfigRule);

    /**
     * @brief This rolls up deconfigure of child to its parent level(s)
     *        This is called by _deconfigParentAssoc
     *
     * This will check the immediate affinity parent and
     * deconfigure it if it has no more functional children.
     * If it deconfigures, it will then try to roll up the deconfigure
     * to next parent level.
     *
     * @param[in] i_child   Reference to child target
     * @param[in] i_errlEid Error log EID to store in Deconfigure Record.
     * @param[in] i_deconfigRule Deconfigure Runtime options
     */
    void _deconfigAffinityParent(TARGETING::Target & i_child,
                                 const uint32_t i_errlEid,
                                 const DeconfigureFlags i_deconfigRule);
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
     *
     *  @return errlHndl_t. Error log handle.
     *
     */
    errlHndl_t _invokeDeconfigureAssocProc(TARGETING::ConstTargetHandle_t i_node = NULL);

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

    /**
     *  @brief Return functional state of children
     *
     *  Called by _deconfigureByAssoc().
     *  This function gets list of all children. if state of any
     *  child is functional then returns true.
     *
     *  @param[in] Pointer parent target id
     *  @param[in] Indicates what relationship the result child targets should
     *             have to the parent target in question
     *             TargetService::CHILD or TargetService::CHILD_BY_AFFINITY
     *
     *  @return true if any child state is functional.
     *
     */
    bool anyChildFunctional(
                  TARGETING::Target & i_parent,
                  TARGETING::TargetService::ASSOCIATION_TYPE i_type =
                      TARGETING::TargetService::CHILD );

    /**
     *  @brief Return if any functional child matching the type and class
     *         of the passed in child target is present
     *
     *  Called by _deconfigureByAssoc().
     *  This function gets list of all children. if state of any
     *  child is functional then returns true.
     *
     *  @param[in] i_my_parent - parent target
     *  @param[in] i_child     - child target to match its class/type
     *
     *  @return true if any child state is functional.
     *
     */
    bool anyFunctionalChildLikeMe( const TARGETING::Target * i_my_parent,
                                   const TARGETING::Target * i_child );

    /**
     *  @brief Return FCO state of children
     *
     *  Called by _deconfigureByAssoc().
     *  This function gets list of all children. If state of any
     *  child is deconfig by FCO, then returns true.
     *
     *  @param[in] Pointer parent target id
     *
     *  @return true if any child state is deconfig by FCO.
     *
     */
    bool anyChildFCO(
                TARGETING::Target &  i_parent);

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
     *  @brief Sets iv_XAOBusEndpointDeconfigured
     *
     *  @param[in] deconfig Allows iv_XAOBusEndpointDeconfigured to be set
     *                      to true/false
     *
     */
    void setXAOBusEndpointDeconfigured(bool deconfig);

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
     * x/a/o bus endpoint.
     *
     * Used by _invokeDeconfigureAssocProc.  If true,
     * _invokeDeconfigureAssocProc will execute and then call
     * _deconfigureAssocProc.  If false, there is no work to be done
     * and _invokeDeconfigureAssocProc will break and return.
     */
    bool iv_XAOBusEndpointDeconfigured;


}; // DeconfigGard
HWAS_DECLARE_SINGLETON(HWAS::DeconfigGard,theDeconfigGardSingleton);

}

#endif
