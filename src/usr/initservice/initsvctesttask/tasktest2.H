/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/initsvctesttask/tasktest2.H $             */
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

#ifndef __INITSVC_TASK_TEST_2_H
#define __INITSVC_TASK_TEST_2_H

/**
 *  @file tasktest2.H
 *
 *  dummy file for use in initservice unit tests
 *
  */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <util/singleton.H>


namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/******************************************************************************/
// InitService Class
/******************************************************************************/

/**
 *  @class  InitSvcTestTask2
 *
 *  test module launched
 */
class InitSvcTaskTest2
{

public:

    /**
     * @brief Constructor
     */
    InitSvcTaskTest2()
    {   }

    /**
     * @brief Destructor
     */
    ~InitSvcTaskTest2()
    {   }

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance
     */
    static InitSvcTaskTest2& getTheInstance();

    /**
      *  @brief  Provide an entry function into the class, called from _start()
      *
      *  @param[in,out]  -  reference to an errlHndl_t
      *
      */
     void            init( errlHndl_t &io_taskRetErrl );


private:


};  //  class InitSvcTaskTest2

} // namespace INITSVCTASKTEST2

#endif
