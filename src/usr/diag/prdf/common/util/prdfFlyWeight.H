/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeight.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2002,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#include <prdfGlobal.H>

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
  FlyWeight() : iv_nextOpen(nullptr)  {}

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
