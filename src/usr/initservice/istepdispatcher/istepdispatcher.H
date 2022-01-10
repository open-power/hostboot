/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __ISTEPDISPATCHER_ISTEPDISPATCHER_H
#define __ISTEPDISPATCHER_ISTEPDISPATCHER_H
/**
 *  @file istepdispatcher.H
 *
 *  IStep Dispatcher interface.  Launched from Extended Initialization Service
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <time.h>
#include <vector>
#include <util/singleton.H>
#include <sys/msg.h>
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/initsvcstructs.H>
#include <isteps/hwpisteperror.H>
#include "../baseinitsvc/initservice.H"
#include "splesscommon.H"
#include "istep_mbox_msgs.H"

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/**
 * @brief the maximum time (seconds) runProgressThread() waits to send the next
 *      progress code (FSP requires a message every 15 sec). Picking 10 sec
 *      is a good choice because it is sufficiently less than 15.
 */
const uint64_t MAX_WAIT_TIME_SEC = 10;

/**
 * @brief constant value that defines the infinite pause for the istepPauseSet
 *      method.
 */
const uint64_t ISTEP_PAUSE_SET_INFINITE = 0xFF;

#ifdef CONFIG_RECONFIG_LOOP_TESTS_ENABLE
/**
 * @brief The Maximum number of elements in the ATTR_RECONFIG_LOOP_TESTS
 *      attribute array.  This number MUST be the same as the length of
 *      the ATTR_RECONFIG_LOOP_TESTS attritute array defined in the
 *      attribute_types.xml file.
 */
const uint64_t MAX_RCL_TESTS = 5;
#endif //CONFIG_RECONFIG_LOOP_TESTS_ENABLE

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/**
 * @brief   detached task (daemon) to handle communication from
 *          VPO / Simics user console.
 *
 * @param[in,out]    -   pointer to any args
 *
 * @return  NULL
 */
void* spTask ( void *io_pArgs );

/**
 *  @class  IStepDispatcher
 *
 *  Dispatch ISteps and handle return codes, errorlogs, etc.
 *
 */
class IStepDispatcher
{

public:

    /**
     * @brief Get singleton instance of this class.
     *
     * @return the (one and only) instance of IStepDispatcher
     */
    static IStepDispatcher& getTheInstance();

    /**
     * @brief Initialize
     *
     * IStep Mode:     Waits for messages
     * Non-IStep Mode: Executes all ISteps
     *
     * @param[in/out] io_rtaskRetErrl - Errorlog pointer to be returned for
     *      any errors that might have been encountered.
     */
    void init (errlHndl_t &io_rtaskRetErrl);

    /**
     * @brief Send a SyncPoint
     *
     * Called by an IStep to send a sync point message to the FSP. A message
     * is not sent in IStep mode or SPLess mode.
     *
     * @return errlHndl_t
     */
    errlHndl_t sendSyncPoint();

    /**
     * @brief Wait for a SyncPoint
     *
     * Called by an IStep to wait for a sync point message from the FSP. This
     * returns immediately in IStep mode or SPLess mode because no sync points
     * will be sent
     */
    void waitForSyncPoint();

    /**
     * @brief Sends a progress message from Hostboot to Fsp.
     *
     * param[in] i_needsLock flag to acquire mutex or not
     *
     * @return errlHndl_t
     */
    errlHndl_t sendProgressCode(bool i_needsLock = true);

    /**
     * @brief Sends an IStepComplete message
     *
     * Only called by ISteps that do not return and need to respond to the
     * IStep request message (i.e. start_payload), this should only be called
     * in IStep mode.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t sendIstepCompleteMsg();

    /**
     * @brief Handles a breakpoint request from an IStep
     *
     * Sends a BREAKPOINT message to the FSP and waits for a response
     *
     * @param[in] i_info - Unique breakpoint numbering value.
     */
    void iStepBreakPoint(uint32_t i_info);

    /**
     * @brief This function sends a progress message if an istep/substep takes
     *      longer than MAX_WAIT_TIME_SEC. This function never returns and
     *      should only be called on a new thread by the startProgressThread
     *      function
     */
    void runProgressThread();

    /**
     * @brief This function will return the current istep and substep.
     *
     * @param[out] o_iStep - The current Istep value.
     *
     * @param[out] o_subStep - The current SubStep value.
     *
     */
    void getIstepInfo ( uint8_t & o_iStep,
                        uint8_t & o_subStep );

    /**
     * @brief This function determines if a shutdown was requested or not
     *
     * @return bool - true if shutdown requested, false if not
     */
    bool isShutdownRequested();

    /**
     * @brief This function determines if a future shutdown request
     *        has happened where the future istep has been reached

     * @return bool - true if shutdown requested, false if not
     */
    bool isFutureShutdownRequested();

    void setAcceptIstepMessages(bool accept);

    /**
     * @brief This function will set a boolean true which states a new gard
     * record has been written.
     */
    void setNewGardRecord();

    /**
     * @brief This function will stop the istep dispacher from continuing to
     * execute steps
     */
    void stop();

    /**
     * @brief Trigger a reboot. The function will figure out which reboot
     *    mechanism it needs to use to reboot the system (PLDM
     *    message, or shutdown() call)
     *
     * @param[in] i_reason the reason for reboot (gets printed to the console)
     */
    void requestReboot(const char* i_reason = nullptr);

    /**
     * @brief  For a given istep/substep combo, calculate (destructively)
     *         the next istep/substep.
     *
     * @param[in,out] io_istep   The istep to be used as input to destructively
     *                           calculate the istep for the next istep/substep
     *                           combo and returned as the istep output
     *                           parameter.
     *
     * @param[in,out] io_substep The substep to be used as input to
     *                           destructively calculate the substep for the
     *                           next istep/substep combo and returned as the
     *                           substep output paremeter.
     *
     * @return 0 indicates there were no more isteps
     *         1 indicates istep successfully incremented
     */
    int getNextIStep(uint8_t& io_istep, uint8_t& io_substep);

    /**
     * @brief Send attn_chipid_msg to alert ATTN code on the FSP to
     *        start monitoring these chips
     *
     * param[in] i_huid_list - HUID list of chips for ATTN to watch
     *
     * @return errlHndl_t - NULL if successful,
     *                      otherwise a pointer to the error log.
     */
    errlHndl_t sendAttnMonitorChipIdMsg(
                  const std::vector<TARGETING::ATTR_HUID_type> & i_huid_list );

protected:

    /**
     * @brief Constructor for the IStepDispatcher object.
     */
    IStepDispatcher();

    /**
     * @brief Destructor for the IStepDispatcher object.
     */
    ~IStepDispatcher();

private:

    /**
     * @note Disable copy constructor and assignment operator
     */
    IStepDispatcher(const IStepDispatcher& i_right);
    IStepDispatcher& operator=(const IStepDispatcher& i_right);

#ifdef CONFIG_PLDM
    /**
     *  @brief Read in current values of PLDM BIOS attributes from the BMC and
     *      write them into associated targeting attributes
     *
     *  @param[in] io_stepError Object to track terminating errors.
     */
    void parsePLDMBiosAttrs(ISTEP_ERROR::IStepError& io_stepError);
#endif

    /**
     * @brief Executes all ISteps
     *
     * @return errlHndl_t
     */
    errlHndl_t executeAllISteps();

    /**
     * @brief Executes the given istep
     *
     * @param[in]  i_istep      The istep to be executed.
     * @param[in]  i_substep    The substep to be executed.
     * @param[out] o_doReconfig True if something occurred that requires a
     *                          reconfigure, false otherwise
     */
    errlHndl_t doIstep(uint32_t i_istep,
                       uint32_t i_substep,
                       bool & o_doReconfig);

    /**
     * @brief Handles all messages from the FSP or SPless user console
     */
    void msgHndlr();

    /**
     * @brief Handles a SyncPointReached message.
     *
     * Signals any IStep thread waiting for a SyncPoint
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handleSyncPointReachedMsg(msg_t * & io_pMsg);

    /**
     * @brief Handles a shutdown request message.
     *
     * Sets iv_shutdown and Signals any IStep thread
     * waiting for a SyncPoint.
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handleShutdownMsg(msg_t * & io_pMsg);

    /**
     * @brief Initiates the shutdown process based on an FSP request.
     *
     * Called by waitForSyncPoint or executeAllISteps if shutdown message
     * has been received by the msgHndlr, this function creates and
     * commits an error log indicating shutdown due to FSP request, and
     * then initiates a TI.
     */
    void shutdownDuringIpl();

    /**
     * @brief Handles a ProcFabIovalid message.
     *
     * Executes the processing required for the sys_proc_fab_iovalid istep
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handleProcFabIovalidMsg(msg_t * & io_pMsg);

    /**
     * @brief Handles the CoalesceHost message.
     *
     * Executes the processing required for the host_coalesce_host istep
     *
     * @return errlHndl_t - the error log generated
     */
    errlHndl_t handleCoalesceHostMsg();

    /**
     * @brief Handles an IStepRequest message
     *
     * Executes the requested IStep and returns result in response message
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handleIStepRequestMsg(msg_t * & io_pMsg);

    /**
     * @brief Handles a PERST request message.
     *
     * Calls p9_perst_phb() to perform the requested function
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handlePerstMsg(msg_t * & io_pMsg);

    /**
     * @brief This function will be used to query the istep master list and the
     *      other istep headers to know what functions/tasks need to be started
     *      for the Istep/Substep that we are in.
     *
     * @param[in] i_IStep - The Istep to run.
     * @param[in] i_SubStep - The SubStep to run.
     *
     * @return TaskInfo - The task info for the task to start as a result of the
     *      requested Istep/Substep.
     */
    const TaskInfo * findTaskInfo(const uint32_t i_IStep,
                                  const uint32_t i_SubStep);

    /**
     * @brief This function loads the modules for each new Istep
     */
    void loadModules(uint32_t istepNumber) const;

    /**
     * @brief This function unloads the modules for each new Istep
     */
    void unLoadModules(uint32_t istepNumber) const;

    /**
     * @brief This function will check if FSP attribute sync is enabled
     *
     * @return bool - True if sync is enabled, false otherwise.
     */
    bool isAttrSyncEnabled() const;

    /**
     * @brief Checks if a deconfigure happened inside a set of isteps and can be
     *        reconfigured to try again.
     *
     *  @param[in]  i_curIstep   current istep
     *  @param[in]  i_curSubstep current substep
     *  @param[out] o_newIstep   new Istep to run, if necessary
     *  @param[out] o_newSubstep new Substep to run, if necessary
     *
     *  @return  bool - True if the reconfigure happened inside the set of
     *      necessary isteps and needs to be retried, false otherwise
     */
    static bool checkReconfig(const uint8_t i_curIstep,
                              const uint8_t i_curSubstep,
                              uint8_t & o_newIstep,
                              uint8_t & o_newSubstep);

    /**
     * @brief This function is called on a dedicated task to post progress codes
     *
     * param[in] p Pointer to any args
     */
    static void * startProgressThread ( void * p);

    /**
     * @brief This function is called on a dedicated task to run the MsgHndlr
     *
     * param[in] p Pointer to any args
     */
    static void * startMsgHndlrThread ( void * p);

    /**
     * @brief Create a common error log indicating a failure due to deconfig.
     *
     * @param[in] i_step - Current istep.
     * @param[in] i_substep - Current substep.
     * @param[in] i_dStep - Desired istep if we could do a reconfig.
     * @param[in] i_dSubstep - Desired substep if we could do a reconfig.
     * @param[in] i_istepMode - Pass true if in istep mode. Default is false.
     */
    static errlHndl_t failedDueToDeconfig(uint8_t i_step, uint8_t i_substep,
                                          uint8_t i_dStep, uint8_t i_dSubstep,
                                          const bool i_istepMode = false);

    // Instance variables

    // Mutexes
    mutable mutex_t iv_bkPtMutex; // Used to throttle breakpoints
    mutable mutex_t iv_mutex;     //used to synchronize access to all instance
                                  //variables

    // Used for waiting for and signalling Sync Points
    mutable sync_cond_t iv_cond;
    bool iv_syncPointReached;

    // Set once in the constructor, mutex protection not needed
    bool iv_mpiplMode;
    bool iv_istepMode;
    bool iv_spBaseServicesEnabled;
    bool iv_mailboxEnabled;

    // Used in only one thread,  mutex protection not needed
    uint32_t iv_istepModulesLoaded;
    bool iv_progressThreadStarted;
    uint8_t iv_highestIStepDone;
    uint8_t iv_highestSubstepDone;

    // Used in multiple threads, mutex protection needed
    uint8_t iv_curIStep;                // Current Step
    uint8_t iv_curSubStep;              // Current SubStep
    msg_t* iv_pIstepMsg;                // External Istep request message
    timespec_t iv_lastProgressMsgTime;  // Last time progress message sent
    bool iv_shutdown;                   // Shutdown request has been received
                                        // from the FSP
    bool iv_futureShutdown;
    uint8_t iv_istepToCompleteBeforeShutdown;
    uint8_t iv_substepToCompleteBeforeShutdown;

    // Instance variable stating whether this istepdispatcher instance should
    //   accept istep messages or not
    bool iv_acceptIstepMessages;

    // Instance variable to state if a new gard record was committed
    bool iv_newGardRecord;

    // Instance variable to state if the PHB Perst libraries are loaded
    bool iv_p9_phbPerstLibLoaded;

    // Message Queue for receiving message from SP or SPless user console
    msg_q_t iv_msgQ;

#ifdef CONFIG_RECONFIG_LOOP_TESTS_ENABLE
    // Reconfigure Loop Test data structure for accessing the
    // ATTR_RECONFIG_LOOP_TESTS attribute array elements (64-bit elements)
    typedef struct
    {
        struct
        {
            uint8_t reserved;  // Reserved for future use
            uint8_t majorStep; // Major step that corresponds to the test
            uint8_t minorStep; // Sub step that corresponds to the test
            uint8_t lastTest;  // Indicates that this is the last test in the
                               // array. This allows the tester to run n number
                               // of tests where n can be less than
                               // MAX_RCL_TESTS
            uint32_t deconfigTargetHuid; // The HUID of the target that will be
                                         // deconfigured as part of the test in
                                         // order to induce a reconfig loop
        } test[MAX_RCL_TESTS];
    } reconfigLoopTests_t;

    /**
     * @brief Decodes and executes the tests in the ATTR_RECONFIG_LOOP_TESTS
     * test attribute.  The data in ATTR_RECONFIG_LOOP_TESTS is populated
     * via attribute overrides.  If no data is present or if the attribute is
     * missing the tests will be not be executed.
     *
     * @param[i] i_step - Current istep
     * @param[i] i_substep - Current substep
     * @param[o] o_err - Returned error handle
     */
    void reconfigLoopTestRunner(uint8_t i_step,
                                uint8_t i_substep,
                                errlHndl_t & o_err);

    /**
     * @brief Induces a Reconfig loop by generating an error log.
     * The error log contains a HW callout with a pointer to a target handle
     * that is to be deconfigured.
     *
     * @param[i] i_pDeconfigTarget - Pointer to handle of target that is to be
     *                               deconfigured
     * @param[o] o_err - Returned error handle
     */
    void reconfigLoopInduce(TARGETING::Target* i_pDeconfigTarget,
                            errlHndl_t & o_err);
#endif // CONFIG_RECONFIG_LOOP_TESTS_ENABLE

    // istep pause configuration data structure for accessing the settings in
    // ATTR_ISTEP_PAUSE_CONFIG (64-bit attribute)
    typedef struct
    {
        uint8_t majorStep; // Target istep where pause will be applied
        uint8_t minorStep;
        uint8_t pauseLen;  // The number of seconds before IPL resumes from
                           // pause state
        uint8_t fullStopEn; // Enable full stop. When set to 0x01 the IPL stops
                            // indefinately until resumed using an outside
                            // command
        uint32_t bpTagInfo; // Tag value passed to the iStepBreakPoint
                            // function
    } istepPauseConfig_t;

    /**
     * @brief Decodes the ATTR_ISTEP_PAUSE_CONFIG attribute and applies either a
     * pause or full stop *before* the specified istep.
     * Whether a pause or full stop is applied depends on the settings in
     * ATTR_ISTEP_PAUSE_CONFIG which are set via attribute override.
     *
     * @param[i] i_step - Current istep
     * @param[i] i_substep - Current substep
     */
    void istepPauseSet(uint8_t i_step, uint8_t i_substep);

    /**
     * @brief A helper function to wait the specified amount of time.
     *        The function sends regular heartbeats while it waits (only
     *        if PLDM is enalbed). To wait an infinite amount of time,
     *        pass ISTEP_PAUSE_SET_INFINITE as a parameter.
     *
     * @param[in] i_waitSec the amount of time (in seconds) to wait.
     *            Pass ISTEP_PAUSE_SET_INFINITE to wait forever.
     */
    void doWait(uint16_t i_waitSec);
};
} // namespace

#endif
