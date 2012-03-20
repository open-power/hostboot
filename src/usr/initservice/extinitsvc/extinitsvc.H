//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/extinitsvc/extinitsvc.H $
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
#include    <stdint.h>
#include    <util/singleton.H>
#include    <sys/vfs.h>            // VFS_MODULE_NAME_MAX

#include    <errl/errlentry.H>
#include    <initservice/taskargs.H>
#include    <initservice/initsvcreasoncodes.H>

#include    "../baseinitsvc/initservice.H"

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

/**
 *  @class  ExtInitSvc
 *
 *  Singleton Class
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
     *  @param[in]  io_rtaskRetErrl    ref to an errlHndl_t passed back to _start()
     */
    void    init( errlHndl_t  &io_rtaskRetErrl );


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
