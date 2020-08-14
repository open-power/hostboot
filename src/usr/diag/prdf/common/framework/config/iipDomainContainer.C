/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipDomainContainer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

// This is used with the CHIP_CLASS vectors to remove one that matches a chipID
// Predicate function for comparing chip IDs.  This is required by remove_if from STL.
class prdfCompareChipIds: public std::unary_function<void*&, bool>
{
  public:
    //Constructor allows a value to be passed in to compare against.
    inline prdfCompareChipIds(TARGETING::TargetHandle_t cid) : __cid(cid) {};
    //This operator is the one I'd like to call straight.  But, because of the void ptr type
    // I cannot call it directly.  C++ won't allow it because of "strong typing" rules.
    inline bool operator() (CHIP_CLASS& i)
    {
       return (__cid == i.getTrgt());
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
bool DomainContainer<T>::Query( ATTENTION_TYPE attentionType )
{
    bool o_rc = false;
    SYSTEM_DEBUG_CLASS sysdebug;
    unsigned int size = GetSize();

    for( unsigned int i = 0; i < size; i++ )
    {
        TARGETING::TargetHandle_t l_pchipHandle = LookUp(i)->getTrgt();
        o_rc =
            sysdebug.isActiveAttentionPending( l_pchipHandle, attentionType );
        if( true == o_rc ) break;
    }

    return(o_rc);
}

template<class T>
inline
int32_t DomainContainer<T>::Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                                    ATTENTION_TYPE attentionType)
{
    SYSTEM_DEBUG_CLASS sysdebug;
    serviceData.service_data->GetErrorSignature()->clear();
    Order(attentionType);
    ExtensibleChip * l_chip = LookUp(0);
    int32_t o_rc = ( l_chip->Analyze( serviceData, attentionType ) );
    sysdebug.clearAttnPendingStatus( l_chip->getTrgt(), attentionType );

    return o_rc;
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

