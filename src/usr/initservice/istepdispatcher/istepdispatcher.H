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

#ifndef __ISTEP_DISPATCHER_H
#define __ISTEP_DISPATCHER_H
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
#include <sys/vfs.h>            // VFS_MODULE_NAME_MAX

#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <initservice/initsvcreasoncodes.H>

#include "../baseinitsvc/initservice.H"
#include "../common/initsvcstructs.H"


namespace   INITSERVICE
{


/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/******************************************************************************/
//  Class
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
     *  @param[in]  i_pargs  pointer to any arguments passed in from
     *                      _start().
     */
    void            init( void *i_pargs);

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
     * @brief   getIStepMode
     *  call into PNOR and fetch the "IStepMode flag" .
     *  This will tell us if we are locked to the SP (IStepMode=ON) or
     *  can run all the ISteps available (IStepMode=OFF).
     *
     *  @return false if IStep Mode is "OFF"
     *          true if IStep Mode is "ON"
     */
    bool getIStepMode( ) const;


    /**
     * @brief   getCanContinueProcedure
     *  If an IStep fails, this routine will fetch the recovery procedure
     *
     *  @param[in]      reference to IStepInfo struct for failing Istep
     *  @param[in]      reference to errorlog for the failure
     *  @param[in,out]  reference to IStepInfo struct for next IStep to run
     *
     *  @return         false if there is no Can-Continue procedure
     *                  true otherwise
     *
     */
    bool getCanContinueProcedure(   const TaskInfo  &i_failingIStep,
                                    errlHndl_t      &i_failingError,
                                    TaskInfo        &io_nextIstep  ) const;

    /**
     * @brief   reportIStepErrorLog
     * If an IStep returns an error log, commit it.
     *
     * @todo Later there may be some decision about whether to report it
     * based on the IStep.
     */
    void reportIStepErrorLog(   const TaskInfo  *i_failingIStep,
                                errlHndl_t      io_errl );


    bool        iv_istepmodeflag;
    uint64_t    iv_nextistep;
    bool        iv_cancontinueflag;

};  //  class IStepDispatcher

} // namespace

#endif
