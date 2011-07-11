#ifndef __EXTINITSVC_EXTINITSVC_H
#define __EXTINITSVC_EXTINITSVC_H
/**
 *  @file extinitsvc.H
 *
 *  Extended initialization service, inherited from initservice base class
 *  perform extended init service functions in the extended image.
 *  launched by initservice.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <util/singleton.H>
#include <sys/vfs.h>            // VFS_MODULE_NAME_MAX

#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <initservice/initsvcreasoncodes.H>

#include "../baseinitsvc/initservice.H"

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/



/******************************************************************************/
// ExtInitSvc Class
/******************************************************************************/

// Singleton definition
class ExtInitSvc;
typedef Singleton<ExtInitSvc> theExtInitSvc;

/**
 *  @class  ExtInitSvc Singleton Class
 *
 *  This extended image module is launched by InitService
 *
 */
class ExtInitSvc  : public InitService
{

public:

    friend  class ExtInitSvcTest;

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of InitService
     */
    static ExtInitSvc& getTheInstance();

    /**
     *  @brief  Provide an entry function into the class, called from _start()
     *
     *  @param[in]  i_args    pointer to any arguments passed in from
     *                      _start() and by extension the kernel,
     *                      currently this is NULL .
     *
     */
    void            init( void *i_args);


    /**
     * @todo    ExtInitSvcTest should be able to find protected functions.
     */
    // $$protected:

    /**
     * @brief   start a extended image task.
     *
     *  @param[in]      i_ptask     pointer to a TaskInfo struct
     *  @param[in]      i_pargs     pointer to args struct
     *  @param[inout]   i_rerrl     reference to an errorlog handle.
     *                              errorlog will be filled out if error,
     *                              otherwise untouched.
     *
     *  @return NULL if success, errorlog handle for failure
     *
     */
    errlHndl_t     startTask(   const TaskInfo *i_ptask,
                                TaskArgs::TaskArgs *i_pargs,
                                errlHndl_t &i_rerrl ) const;


protected:
    /**
     * @brief Constructor for the InitService object.
     */
    ExtInitSvc();

    /**
     * @brief Destructor for the InitService object.
     */
    ~ExtInitSvc();



private:



};  //  class ExtInitSvc

} // namespace EXTINITSVC

#endif
