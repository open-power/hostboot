/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeight.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2000,2020                        */
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

// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfFlyWeight_C

#include <prdfFlyWeight.H>
#include <tracinterface.H>
#include <prdfHeapBucketSize.H>
#include <prdfTrace.H>
#include <prdfAssert.h>

#undef prdfFlyWeight_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------
namespace PRDF
{
//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------
template < class T , uint32_t S >
FlyWeight<T,S>::~FlyWeight()
{
  clear();
}

//---------------------------------------------------------------------

template < class T, uint32_t S >
void FlyWeight<T,S>::clear()
{
  for(typename HeapType::const_iterator i = iv_heap.begin(); i != iv_heap.end(); ++i)
  {
    delete[] (T*)*i;
  }
  iv_heap.erase(iv_heap.begin(),iv_heap.end());
  iv_nextOpen = nullptr;
}

//---------------------------------------------------------------------

template < class T , uint32_t S >
T & FlyWeight<T,S>::get(const T & key)
{
  T * result = nullptr;
  T * current_array = nullptr;

  // search to see if we already have one
  for(typename HeapType::const_iterator i = iv_heap.begin();
      i != iv_heap.end() && (result == nullptr); ++i)
  {
    current_array = (T*)*i;
    for(T * p = current_array;
        p != (current_array + RoundBucketSize<T,S>::value); ++p)
    {
      if (p == iv_nextOpen)
        break;

      if(*p == key)
      {
        result = p;
        break;
      }
    }
  }
  if(result == nullptr) // didn't find it - add it
  {
    if(iv_nextOpen == nullptr) // need a new array
    {
      current_array = new T[RoundBucketSize<T,S>::value];
      if(current_array == nullptr)   // dg00a
      {                           // dg00a
        PRDF_ERR("PRDF Could not get requested memory");
        PRDF_ASSERT( nullptr != current_array );
      }                           // dg00a
      // if the heap of array ptrs is full(or non-existant) then increase capacity by S dg00a
      if(iv_heap.size() == iv_heap.capacity())     // dg00a
      {                                            // dg00a
        iv_heap.reserve(iv_heap.capacity() + RoundBucketSize<T,S>::value);   // dg00a
      }                                            // dg01a
      iv_heap.push_back(current_array);
      iv_nextOpen = current_array;
    }

    *iv_nextOpen = key;
    result = iv_nextOpen;
    ++iv_nextOpen;
    if((current_array != nullptr) &&  // Done to fix BEAM error
       (iv_nextOpen == (current_array + RoundBucketSize<T,S>::value))) // this array is full
    {
      iv_nextOpen = nullptr;
    }
  }
  return *result;
}
} //End namespace PRDF


#if defined( FLYWEIGHT_PROFILING )

namespace PRDF
{
template < class T , uint32_t S >
void FlyWeight<T,S>::printStats(void)
{

    PRDF_TRAC( "FlyWeight Memory allocated = %d",(iv_heap.size() * sizeof(T) *
                RoundBucketSize<T,S>::value ) );
}

} //End namespace PRDF
#endif

