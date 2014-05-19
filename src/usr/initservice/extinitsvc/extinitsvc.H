/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/extinitsvc/extinitsvc.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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


    /**
     * @brief This function will execute the Cxx Unit tests for Hostboot.  It is
     *      to be done here, instead of in Initservice, because when this istep
     *      completes the Payload will be started.
     *
     * @return errlHndl_t - NULL if successfule, otherwise a pointer to the error
     *      log.
     */
    errlHndl_t executeUnitTests ( void );


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
