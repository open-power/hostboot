/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipDomainContainer.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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
// Description: This module provides the implementation for the PRD
//              DomainContainer class.
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <iipServiceDataCollector.h>
#include <prdfErrorSignature.H>
#include <iipDomainContainer.h>

#include <prdfRuleChip.H>
#include <prdfPluginDef.H>
#include <prdfPlatServices.H>
#include <algorithm>

namespace PRDF
{

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

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

// @jl02 a Start
// This is used with the CHIP_CLASS vectors to remove one that matches a chipID
// Predicate function for comparing chip IDs.  This is required by remove_if from STL.
// TODO:FIXME: Add compiler directives or some method to make sure the type handling here
// is generic enough or correct enough to handle future use of this functionality.
class prdfCompareChipIds: public std::unary_function<void*&, bool>
{
  public:
    //Constructor allows a value to be passed in to compare against.
    inline prdfCompareChipIds(TARGETING::TargetHandle_t cid) : __cid(cid) {};
    //This operator is the one I'd like to call straight.  But, because of the void ptr type
    // I cannot call it directly.  C++ won't allow it because of "strong typing" rules.
    inline bool operator() (CHIP_CLASS& i)
    {
       return (__cid == i.GetChipHandle());
    };
    //Really fancy caste for the benefit of the compiler.
    inline bool operator() (void*& i)
    {
        //Anonymous Union for calling void ptr a CHIP_CLASS.
        union {CHIP_CLASS* c; void* v;} cptr;
        //assign value passed in to it's void ptr type.
        cptr.v = i;
        //pass CHIP_CLASS type to inline overloaded operator above.
        return this->operator()(*cptr.c);
    };
  private:
    //Private storage for value passed in.
    TARGETING::TargetHandle_t __cid;
};
// @jl02 a Stop

template<class T>
inline
DomainContainer<T>::DomainContainer(DOMAIN_ID domainId, unsigned int size) :
Domain(domainId),
chips()  // dg04 - remove size from arg list
{
  chips.reserve(size); // dg04
}

template<class T>
inline
bool DomainContainer<T>::Query(ATTENTION_TYPE attentionType)     // DG03
{
  bool rc = false;

  SYSTEM_DEBUG_CLASS sysdebug;
  unsigned int size = GetSize();
  for(unsigned int i = 0;(i < size) && (rc == false);i++)
  {
    TARGETING::TargetHandle_t l_pchipHandle = LookUp(i)->GetChipHandle();
    if(sysdebug.IsAttentionActive(l_pchipHandle) == true)
    {
      if(sysdebug.GetAttentionType(l_pchipHandle) == attentionType) rc = true;
    }
  }

  return(rc);
}

template<class T>
inline
int32_t DomainContainer<T>::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                                    ATTENTION_TYPE attentionType)
{
  serviceData.service_data->GetErrorSignature()->clear();
  Order(attentionType);                    // DG01 DG02
  return(LookUp(0)->Analyze(serviceData, attentionType));
}

template<class T>
inline
void DomainContainer<T>::Swap(unsigned int index1, unsigned int index2)
{
  void * ptr = chips[index1];
  chips[index1] = chips[index2];
  chips[index2] = ptr;
}

template<class T> // pw01 - Added function.
inline
void DomainContainer<T>::MoveToFront(unsigned int index)
{
    for (unsigned int i = index; i > 0; i--)
    {
        Swap(i, i-1);
    }
}

template<class T>
inline
void DomainContainer<T>::Remove(TARGETING::TargetHandle_t i_pChipHandle)
{
    // erase and remove_if functions are from the STL and require begin end and predicate functions to work.
    // This will iterate thru the vectors and remove any vectors with chip ID that matches the i_chip.
    chips.erase(std::remove_if(chips.begin(), chips.end(), prdfCompareChipIds(i_pChipHandle)), chips.end());
}

} // end namespace PRDF

