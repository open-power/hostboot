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

// Singleton definition
class IStepDispatcher;
typedef Singleton<IStepDispatcher> theIStepDispatcher;


/**
 *  @class  IStepDispatcher Singleton Class
 *
 */
class IStepDispatcher   :   public InitService
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
    bool getCanContinueProcedure(   TaskInfo    &i_failingIStep,
                                    errlHndl_t  &i_failingError,
                                    TaskInfo    &io_nextIstep  ) const;



    bool        iv_istepmodeflag;
    uint64_t    iv_nextistep;
    bool        iv_cancontinueflag;

};  //  class IStepDispatcher

} // namespace ISTEPDISP

#endif
