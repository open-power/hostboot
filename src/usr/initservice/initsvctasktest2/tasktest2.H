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
#include <stdint.h>
#include <util/singleton.H>

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
     * @brief Constructor for the InitService object.
     */
    InitSvcTaskTest2()
    {   }

    /**
     * @brief Destructor for the InitService object.
     */
    ~InitSvcTaskTest2()
    {   }

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of InitService
     */
    static InitSvcTaskTest2& getTheInstance();

    /**
      *  @brief  Provide an entry function into the class, called from _start()
      *
      *  @param[in]  i_args    pointer to any arguments passed in from
      *                      _start() and by extension the kernel,
      *                      currently this is NULL .
      *
      *  @todo   document any changes for args
      */
     void            init( void *i_args);


private:


};  //  class InitSvcTaskTest2

} // namespace INITSVCTASKTEST2

#endif
