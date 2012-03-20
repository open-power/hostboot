//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/istepdispatcher.H $
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

#include    <errl/errlentry.H>
#include    <initservice/taskargs.H>
#include    <initservice/initsvcreasoncodes.H>
#include    <initservice/initsvcstructs.H>

#include    "../baseinitsvc/initservice.H"

#include    "splesscommon.H"


namespace   INITSERVICE
{

// using namespace SPLESS;

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

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
     *  @brief  Provide an entry function into the class, called from _start()
     *
     *  @param[in]  io_rtaskRetErrl  -   ref to errlHndl_t passed back to _start().
     *
     *  @return nothing
     */
    void            init( errlHndl_t    &io_rtaskRetErrl );


    /**
     * @brief Handle an istep break point
     * @param[in] i_info, @TODO - location/info
     * @pre iv_sts contains current istep status + seqnum or
     *      0 if not in step mode
     * @note blocks until an outside istep cmd to resume is recieved.
     */
    void handleBreakPoint( uint32_t info);

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
     * @brief   getIStepMode - return value of IStep Mode
     *
     *  @return bool - value of iv_istepmodeflag
     *  @retval false if IStep Mode is "OFF"
     *          true if IStep Mode is "ON"
     */
    bool getIStepMode( )    const;


    /**
     * @brief   Find a TaskInfo struct in the global istep list(s),
     *          addressed by { IStep, SubStep }
     *
     * @param[in]       i_IStep         -   IStepNumber
     * @param[in]       i_SubStep       -   SubStepNumber
     *
     * @return  pointer to a TaskInfo struct
     * @retval  pointer to a TaskInfo struct, or NULL
     *
     */
    const TaskInfo *findTaskInfo(
                                    const uint16_t i_IStep,
                                    const uint16_t i_SubStep ) const;

    /**
     * @brief   Command 0: Run the requested IStep/SubStep
     *
     * param[in]    i_rcmd  -   ref to a filled in SPLessCmd struct
     * @post       iv_sts   set to current istep status
     *
     * @return  none
     */
    void    processSingleIStepCmd( SPLESS::SPLessCmd &i_rcmd);


     /**
      * @brief  singleStepISteps
      *
      * Stop and wait for SP to send the next IStep to run.  Run that, then
      * wait for the next one.
      * @param[in,out]  -   ref to an errlHndl_t that can be passed back to
      *                     ExtInitSvc .
      *
      * @return none
      */
     void   singleStepISteps( errlHndl_t    &io_rtaskRetErrl ) ;


     /**
      * @brief  runAllISteps
      *
      * Run all available ISteps sequentially.
      * If an IStep gets an error, report it and stop.
      * Otherwise, return.
      *
      * @param[in,out]  -   ref to an errlHndl_t that can be passed back to
      *                     ExtInitSvc .
      *
      * @return none
      */
     void   runAllISteps( errlHndl_t    &io_rtaskRetErrl )  const;


    /**
     * @brief   getCanContinueProcedure
     *  If an IStep fails, this routine will fetch the recovery procedure
     *  This is only used in "normal" mode, it will not be used when IStep Mode
     *  is ON (i.e. it will not be used when single-stepping).
     *
     *  @param[in]      i_failingIStep  -   ref to IStepInfo struct for failing
     *                                      Istep
     *  @param[in]      i_failingError  -   ref to errorlog for the failure
     *  @param[in,out]  io_nextIStep    -   ref to TaskInfo struct for next
     *                                      IStep to run.  struct will be filled
     *                                      out with info on the next IStep to
     *                                      run.
     *
     *  @return     bool
     *  @retval     false if there is no Can-Continue procedure,
     *                  true otherwise
     *
     *  @todo   2011-08-22 currently the defs for this procedure are pretty
     *          vague - requirements for Can-Continue behaviour have not been
     *          defined yet.
     */
    bool getCanContinueProcedure(
                            const TaskInfo  &i_failingIStep,
                            errlHndl_t      &i_failingError,
                            TaskInfo        &io_nextIStep  ) const;


    //  -----   internal vars   -----------------------------

    mutex_t             iv_poll_mutex;  //!< protect who's polling istep cmds
    SPLESS::SPLessSts   iv_sts;         //!< Current status of istep mode

};  //  class IStepDispatcher


} // namespace

#endif
