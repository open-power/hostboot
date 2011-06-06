/**
 *  @file initservice.H
 *
 *      - Manage high-level host boot IPL flow
 *      - Perform can-continue processing
 *      - Perform automatic and manual Istep execution
 *      - Handle flow errors as appropriate.
 *
 */

/**
 * High-level todo list
 *
 * @todo    SP3:    move startTask() and reportError() to private
 * @todo    SP3:    remove ADUDD, not used
 * @todo    SP3:    add (NULL) detection to printk
 * @todo    SP3:    reevaluate all trace calls - TRACF are field traces, - ERR_MRK etc macros
 * @todo    SP3:    change InitService::start() to init(), document this as a standard.
 * @todo    SP3:    initservice/makefile    remove trailing tabs
 * @todo    SP3:    Disable copy CTOR/assignment operator; this would have caught an illegal copy by assignment elsewhere
 * @@todo           Add more macros to trace, discuss with Andrew and Nick
 *
 *
 */

#ifndef __INIT_SERVICE_H
#define __INIT_SERVICE_H

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <util/singleton.H>
#include <sys/vfs.h>            // VFS_MODULE_NAME_MAX

#include    <errl/errlentry.H>
#include    <initservice/initsvcreasoncodes.H>

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/
/**
 * @enum    ModuleType
 *  -   BASE_MODULE == module in the base image
 *  -   EXT_MODULE == module in the extended image
 */
enum    ModuleType
{
    BASE_MODULE =   0,
    EXT_MODULE,
};


/**
 * @struct  TaskFlags
 *
 *  - run _start() function on start
 *  - module type, BASE_MODULE or EXT_MODULE
 *  - module_id for errorlog if task fails
 *
 * @todo revisit these flags in sprint3
 */
struct  TaskFlags
{
    bool                startflag;          // this is a task, run _start() function
    ModuleType          module_type;        // BASE_MODULE_TYPE or EXT_MODULE_TYPE
    InitServiceModuleID module_id;          // module id for errorlog
};

/**
 * @struct  _TaskInfo
 *
 * Holds information on each task in the system.
 *      - taskname
 *      - execution flags, see TaskFlags above
 *
 */
struct  TaskInfo
{
    const char taskname[VFS_MODULE_NAME_MAX];
    TaskFlags   taskflags;

}   PACKED;


/******************************************************************************/
// InitService Class
/******************************************************************************/

// Singleton definition
class InitService;
typedef Singleton<InitService> theInitService;

/**
 *  @class  InitService Singleton Class
 *
 *  This class is launched by _start() (see initservicetaskentry.C),
 *  which is launched by the kernel (init_main.C).
 *
 *  Once started, it handles the rest of HostBoot Initialization.
 *
 *  @returns    none
 */
class InitService
{

public:

    friend  class InitServiceTest;

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of InitService
     */
    static InitService& getTheInstance();

    /**
     *  @brief  Provide an entry function into the class, called from _start()
     *
     *  @param[in]  i_args    pointer to any arguments passed in from
     *                      _start() and by extension the kernel,
     *                      currently this is NULL .
     *
     *  @todo   Sprint 3:  pass in ptr to errorlog struct?
     *  @todo   document any changes for args
     */
    void    start( void *i_args);

    /**
     * @brief Constructor for the InitService object.
     */
    InitService();

    /**
     * @brief Destructor for the InitService object.
     */
    ~InitService();

    /**
      * @brief   start a task
      *
      *  @param[in]  i_rtask   reference to a TaskInfo struct
      *  @param[inout]  i_rerrl   reference to an errorlog struct.
      *                         struct will be filled out if error,
      *                         otherwise untouched.
      *
      *  @return child id if success, < 0 for failure
      *
      *  @todo  return errorlog handle in sprint3
      */
     tid_t  startTask( const TaskInfo &i_rtask, errlHndl_t &i_rerrl ) const;

     /**
      * @brief   report Error to the system.
      *
      * @param[in]  io_errl - errlHndl_t pointer to a filled-out error entry
      *                                 errorlog will be committed, errorlog
      *                                 will be deleted, and pointer will be
      *                                 set to NULL on exit
      *
      * @return  nothing
      */
     void    reportError( errlHndl_t  &io_rerrl) const;


private:



    /**
     * @brief   Initialize the Trace module
     *
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startTrace( errlHndl_t &i_rerrl )   const;

    /**
     * @brief   Initialize the ErrorLog module
     *
     *     *
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startErrLog( errlHndl_t &i_rerrl )  const;

    /**
     * @brief   Initialize the XSCOM Device Driver module
     *
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startXSCOMDD( errlHndl_t &i_rerrl )  const;

    /**
     * @brief   Initialize the PNOR Device Driver module
     *
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startPNORDD(  errlHndl_t &i_rerrl ) const;

    /**
     * @brief   Initialize the second stage of VFS module
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */

    void    startVFS_2(  errlHndl_t &i_rerrl )  const;

    /**
     * @brief   Initialize the Targetting DD module
     *
     * @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startTargetting(  errlHndl_t &i_rerrl ) const;

    /**
     * @brief   get the Master Chip Target
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    getMasterChipTarget(  errlHndl_t &i_rerrl ) const;

    /**
     * @brief   Initialize the Mailbox Device Driver
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startMailboxDD(  errlHndl_t &i_rerrl )      const;

    /**
     * @brief   Initialize SP Communications
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startSPComm(  errlHndl_t &i_rerrl )     const;

    /**
     * @brief   Turn on Streaming Trace, if the PNOR flag is set
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    enableStreamingTrace(  errlHndl_t &i_rerrl )    const;

    /**
     * @brief   Start reporting progress codes.
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startProgressCodes(  errlHndl_t &i_rerrl )      const;

    /**
     * @brief   Initialize the FSI Device Driver module
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startFSIDD(  errlHndl_t &i_rerrl )          const;

    /**
     * @brief   Set up links to the slaves
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    setupSlaveLinks( errlHndl_t &i_rerrl )      const;

    /**
     * @brief   Initialize FSI SCOM
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startFSISCOM(  errlHndl_t &i_rerrl )        const;

    /**
     * @brief   Initialize FSI I2C
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startFSII2C(  errlHndl_t &i_rerrl )     const;

    /**
     * @brief   Initialize HWP
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    startHWPF(  errlHndl_t &i_rerrl )       const;

    /**
     * @brief   Read Configuration from PNOR
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    readMaxConfigfromPNOR(  errlHndl_t &i_rerrl )   const;

    /**
     * @brief   apply Presence Detect
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    applyPresenceDetect(  errlHndl_t &i_rerrl )     const;

    /**
     * @brief   apply Partial Bad
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    applyPartialBad(  errlHndl_t &i_rerrl )     const;
    /**
     * @brief   apply Gard
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    applyGard(  errlHndl_t &i_rerrl )       const;

    /**
     * @brief   Collect HW IDEC info
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    collectHWIDEC(  errlHndl_t &i_rerrl )       const;

    /**
     * @brief   verify the IDEC info
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    verifyIDEC(  errlHndl_t &i_rerrl )          const;

    /**
     * @brief   Disable the HW watchdog
     *
     *  @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    disableWatchDog(  errlHndl_t &i_rerrl )     const;

    /**
     * @brief   Execute the IStep module to communicate with SP and run
     *          the isteps.
     *
     *           @param[in,out]   i_rerrl - errorlog handle.
     *                  Success:  handle is untouched
     *                  Failure:  will point to a filled-out errorlog
     *
     * @return  none
     */
    void    executeISteps(  errlHndl_t &i_rerrl )       const;


};  //  class InitService

} // namespace INITSERVICE

#endif
