/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.H $       */
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
#ifndef __ISTEPDISPATCHER_ISTEPDISPATCHER_H
#define __ISTEPDISPATCHER_ISTEPDISPATCHER_H
/**
 *  @file istepdispatcher.H
 *
 *  IStep Dispatcher interface.  Launched from Extended Initialization Service
 *
 */

/**
 * @page    IStepDispatcher IStep Dispatcher
 *
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <util/singleton.H>
#include    <sys/msg.h>
#include    <sys/sync.h>
#include    <errl/errlentry.H>
#include    <initservice/taskargs.H>
#include    <initservice/initsvcreasoncodes.H>
#include    <initservice/initsvcstructs.H>
#include    "../baseinitsvc/initservice.H"
#include    "splesscommon.H"
#include    "istep_mbox_msgs.H"

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/


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
 * @brief enums for whether the messages IStepdispatcher sends are synchronus
 *      or asynchronous.
 */
enum IStepSync_t
{
    ISTEP_SYNC,
    ISTEP_ASYNC,
};


/******************************************************************************/
//  Class IStepDispatcher
/******************************************************************************/

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
     *  @return the (one and only) instance of IStepDispatcher
     */
    static IStepDispatcher& getTheInstance();

    /**
     * @brief This function is what is called to startup the main istep
     *      dispatcher thread.
     *
     * @param[in/out] io_rtaskRetErrl - Errorlog pointer to be returned for
     *      any errors that might have been encountered.
     *
     * @return NONE.
     */
    void init ( errlHndl_t &io_rtaskRetErrl );

    /**
     * @brief This function is used to send a sync point message from Hostboot
     *      to the Fsp.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t sendSyncPoint ( void );

    /**
     * @brief This function is used for calling code to be held off waiting
     *      for a syncpoint message from an external source.  Anyone calling
     *      this will be blocked on this call until ANY sync point message is
     *      received.  Once received, each caller in succession will be
     *      released.
     *
     * @return NONE.
     */
    void waitForSyncPoint ( void );

    /**
     * @brief This function when called will send a Istep complete mailbox
     *      message to the Fsp to indicate that the current Istep is complete.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t sendIstepCompleteMsg ( void );

    /**
     * @brief This function will handle all breakpoint requests from the
     *      running istep code.  The running istep code would be initiated via
     *      the istep dispatcher worker thread.  Thus, holding off the worker
     *      thread.
     *
     * @param[in] i_info - TODO - this needs to be decided yet.  But it seems
     *      at least preliminarily that this will contain a unique breakpoint
     *      numbering value.
     *
     * @return NONE.
     */
    void handleBreakpoint ( uint32_t i_info );

    /**
     * @brief This function will return the current istep and substep.
     *
     * @param[out] o_iStep - The current Istep value.
     *
     * @param[out] o_subStep - The current SubStep value.
     *
     * @return NONE.
     */
    void getIstepInfo ( uint8_t & o_iStep,
                        uint8_t & o_subStep );

    /**
     * @brief This function will return whether or not we are in MPIPL mode  
     *
     *  @return bool - flag indicating whether we're in MPIPL mode
     *  @retval false if not in  MPIPL mode
     *          true if in MPIPL mode
     */
    bool isMpiplMode( void ) const;

    /**
     * @brief   getIStepMode - return value of IStep Mode
     *
     *  @return bool - value of iv_istepmodeflag
     *  @retval false if IStep Mode is "OFF"
     *          true if IStep Mode is "ON"
     */
    bool getIStepMode( ) const;

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
     * @note   Disable copy constructor and assignment operator
     */
    IStepDispatcher(const IStepDispatcher& i_right);
    IStepDispatcher& operator=(const IStepDispatcher& i_right);


    /**
     * @brief This function will start at istep 0, substep 0, and cycle
     *      through all possible isteps, returning when complete, or an error
     *      is hit.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to an
     *      error log.
     */
    errlHndl_t executeAllISteps ( void );

    /**
     * @brief This function is the main handler loop for the Istep Dispatcher.
     *      it receives all messages from outside sources and initiates the
     *      proper action and response (if required).
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to an
     *      error log.
     */
    errlHndl_t msgHndlr ( void );

    /**
     * @brief This function is used to send mailbox messages to the Fsp.
     *
     * @param[in] i_sendSync - The sync type of message to send.  Whether
     *      synchronous or asynchronous.
     *
     * @param[in] i_msg - The message to send to the Fsp.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to an
     *      error log.
     */
    errlHndl_t sendMboxMsg ( IStepSync_t i_sendSync,
                             msg_t * i_msg );

    /**
     * @brief This function is used for all of the Syncpoint message handling.
     *
     * @return NONE.
     */
    void handleSyncPointReachedMsg ( void );

    /**
     * @brief This function is used to handle the message from the worker
     *      thread requesting more work.
     *
     * @param[in] i_first - TRUE for the very first call. FALSE afterward
     *
     * @return NONE.
     */
    void handleMoreWorkNeededMsg ( bool i_first );

    /**
     * @brief This function is used to handle the single Istep requests from
     *      outside sources.
     *
     * @return NONE.
     */
    void handleIStepRequestMsg ( void );

    /**
     * @brief This function is used to set the current Istep and Substep
     *      values for what is currently running.
     *
     * @return NONE.
     */
    void setIstepInfo ( uint16_t i_type );

    /**
     * @brief This function will return whether or not we are SPless
     *
     * @return bool - whether we are SPLESS.
     */
    bool spLess ( void );
     
    /**
     * @brief This function will check whether or not we are in MPIPL mode  
     *
     *  @return bool - flag indicating whether we're in MPIPL mode
     *  @retval false if not in  MPIPL mode
     *          true if in MPIPL mode
     */
    bool checkMpiplMode ( void ) const;


    //  -----   internal vars   -----------------------------

    mutex_t iv_bkPtMutex;
    mutex_t iv_syncMutex;
    mutex_t iv_stepMutex;
    sync_cond_t iv_syncHit;
    uint8_t iv_curIStep;
    uint8_t iv_curSubStep;
    bool iv_sync;
    bool iv_mpipl_mode;     //flag indicating whether we're in MPIPL mode
    msg_q_t iv_msgQ;
    msg_t* iv_workerMsg;    // More work Needed Msg from Worker
    msg_t* iv_Msg;          // All other Msgs that need to be saved
};  //  class IStepDispatcher


} // namespace

#endif
