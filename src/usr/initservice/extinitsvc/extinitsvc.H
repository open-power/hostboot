/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM HostBoot Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

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

/**
 * @enum ShutdownStatus
 */
enum ShutdownStatus
{
    SHUTDOWN_STATUS_GOOD         = 0x01230000,
    SHUTDOWN_STATUS_UT_FAILED    = 0x01230001,
    SHUTDOWN_STATUS_ISTEP_FAILED = 0x01230002,
};


/******************************************************************************/
// ExtInitSvc Class
/******************************************************************************/

/**
 *  @class  ExtInitSvc Singleton Class
 *
 *  This extended image module is launched by InitService
 *
 */
class ExtInitSvc
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
    /**
     * @note   Disable copy constructor and assignment operator
     */
    ExtInitSvc(const ExtInitSvc& i_right);
    ExtInitSvc& operator=(const ExtInitSvc& i_right);


};  //  class ExtInitSvc

} // namespace

#endif
