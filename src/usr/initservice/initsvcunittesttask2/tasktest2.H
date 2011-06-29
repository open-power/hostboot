#ifndef __INITSVC_TASK_TEST_2_H
#define __INITSVC_TASK_TEST_2_H

/**
 *  @file initsvctasktest2.H
 *
  */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <kernel/console.H>     // printk
#include <util/singleton.H>

namespace   INITSVCTASKTEST2
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
// Singleton definition
class InitSvcTaskTest2;
typedef Singleton<InitSvcTaskTest2> theTask2;

/**
 *  @class  InitSvcTestTask2  Class
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
