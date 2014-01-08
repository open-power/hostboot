/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <util/singleton.H>
#include <sys/msg.h>
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/initsvcstructs.H>
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

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/**
 * @brief   detached task (daemon) to handle communication from
 *          VPO / Simics user console.
 *
 * param[in,out]    -   pointer to any args
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
     * @brief Sends an IStepComplete message
     *
     * Only called by ISteps that do not return and need to repsond to the
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
     * @param[in] i_info - TODO - this needs to be decided yet.  But it seems
     *      at least preliminarily that this will contain a unique breakpoint
     *      numbering value.
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

    /**
     * @brief Executes all ISteps
     *
     * @return errlHndl_t
     */
    errlHndl_t executeAllISteps();

    /**
     * @brief Executes the given istep
     *
     * @param[in]  i_istep     The istep to be executed.
     * @param[in]  i_substep   The substep to be executed.
     * @param[out] o_deconfigs If error returned then true if HW was
     *                         deconfigured during the istep
     * @return errlHndl_t
     */
    errlHndl_t doIstep(uint32_t i_istep,
                       uint32_t i_substep,
                       bool & o_deconfigs);

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
     * @brief Handles an IStepRequest message
     *
     * Executes the requested IStep and returns result in response message
     *
     * @param[io] io_pMsg Reference to pointer to message (cleaned up)
     */
    void handleIStepRequestMsg(msg_t * & io_pMsg);

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
     *      neccessary isteps and needs to be retried, false otherwise
     */
    static bool checkReconfig(const uint8_t i_curIstep,
                              const uint8_t i_curSubstep,
                              uint8_t & o_newIstep,
                              uint8_t & o_newSubstep);

    /**
     * @brief Sends a progress message from Hostboot to Fsp.
     *
     * param[in] i_needsLock flag to acquire mutex or not
     *
     * @return errlHndl_t
     */
    errlHndl_t sendProgressCode(bool i_needsLock = true);

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

    // Used in multiple threads, mutex protection needed
    uint8_t iv_curIStep;               // Current Step
    uint8_t iv_curSubStep;             // Current SubStep
    msg_t* iv_pIstepMsg;               // External Istep request message
    timespec_t iv_lastProgressMsgTime; // Last time progress message sent
    bool iv_shutdown;                  // Shutdown request has been received
                                       // from the FSP

    // Message Queue for receiving message from SP or SPless user console
    msg_q_t iv_msgQ;
};

} // namespace

#endif
