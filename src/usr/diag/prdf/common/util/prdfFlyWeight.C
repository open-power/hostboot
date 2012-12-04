/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFlyWeight.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2013              */
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
#include <iipglobl.h>
#include <prdfHeapBucketSize.H>

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
  iv_nextOpen = NULL;
}

//---------------------------------------------------------------------

template < class T , uint32_t S >
T & FlyWeight<T,S>::get(const T & key)
{
  T * result = NULL;
  T * current_array = NULL;

  // search to see if we already have one
  for(typename HeapType::const_iterator i = iv_heap.begin();
      i != iv_heap.end() && (result == NULL); ++i)
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
  if(result == NULL) // didn't find it - add it
  {
    if(iv_nextOpen == NULL) // need a new array
    {
      current_array = new T[RoundBucketSize<T,S>::value];
      if(current_array == NULL)   // dg00a
      {                           // dg00a
        PRDF_TRAC("PRDF Could not get requested memory");  // dg00a
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
    if((current_array != NULL) &&  // Done to fix BEAM error
       (iv_nextOpen == (current_array + RoundBucketSize<T,S>::value))) // this array is full
    {
      iv_nextOpen = NULL;
    }
  }
  return *result;
}
} //End namespace PRDF
#if defined(ESW_SIM_COMPILE)
#include <iostream>
#include <iomanip>

//FlyWeightBase::FlyWeightList FlyWeightBase::cv_fwlist; //mp01d
namespace PRDF
{
template < class T , uint32_t S >
void FlyWeight<T,S>::printStats(void)
{
  using namespace std;
  cout << "FlyWeight Memory allowcated = " << (iv_heap.size() * sizeof(T) * RoundBucketSize<T,S>::value) << endl;
}
} //End namespace PRDF
#endif

