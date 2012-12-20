/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeight.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef PRDFFLYWEIGHT_H
#define PRDFFLYWEIGHT_H
/**
   @file prdfFlyWeight.H
   @brief Description
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <stdint.h>
#include <vector>
#include <iipglobl.h>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
//
//
namespace PRDF
{
/**
    **One line Class description**
    @author Doug Gilbert
    @par T is the type of object to flyweight, S is the size (# of T's) in an allocation
         unit (minimum number of T's to reserve space for when more storage is needed)
    @code
    @endcode
*/
template <class T, uint32_t S>
class FlyWeight
{
public:
  /**
    Constructor
    @param
    @returns
    @pre
    @post
    @see
    @note
  */
  FlyWeight() : iv_nextOpen(NULL)  {}

  /**
    Destructor
  */
  ~FlyWeight();

  /**
   clear all entries
   @param - none
   @pre none
   @post all instances of T are deleted.
   @note any ponters or references to any of the instances should be reset
   */
  void clear();

  /**
   Get the flyweight version of T - add it if it does not yet exist
   @param key to search for
   @returns Reference to T in the flyweight
   @pre none
   @post FlyWeight contains one instance of key
   */
  T & get(const T & key);

#ifdef  FLYWEIGHT_PROFILING
  /**
   * @brief   prints the memory occupied by objects in flyweight.
   */

  virtual void printStats(void);

#endif

private:  // functions
private:  // Data

  typedef std::vector< void* > HeapType;

  HeapType iv_heap;  // vector of arrays of T
  T * iv_nextOpen;
};

} //End namespace PRDF
#endif /* PRDFFLYWEIGHT_H */

// Change Log *****************************************************************
//
//  Flag Reason    Vers    Date     Coder    Description
//  ---- --------- ------- -------- -------- ------------------------------------
//                                  dgilbert Initial Creation
//                 fips222 09/14/04 dgilbert  Add clear()
//
// End Change Log *************************************************************
