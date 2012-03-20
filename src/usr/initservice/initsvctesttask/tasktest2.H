//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/initsvcunittesttask2/tasktest2.H $
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
