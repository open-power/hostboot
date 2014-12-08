/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfParentDomain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#include <prdfGlobal.H>
#include <iipDomain.h>
#include <prdfPllDomain.H>

#include <prdfParentDomain.H>
#include <prdfExtensibleDomain.H>
#include <prdfPluginDef.H>

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

namespace PRDF
{

//Constructor
template<class T>
ParentDomain<T>::ParentDomain()
{
  VectorOfDomainPointerType iv_childrenDomains();
}


//This code is primarily for the configurator.
template<class T>
int32_t ParentDomain<T>::AddChild(TARGETING::TargetHandle_t i_pchipHandle, T * i_childDomain)
{
  int32_t l_rc = SUCCESS;

  ChipToDomainPointerPairType  l_chipDomPtrPair
        = ChipToDomainPointerPairType(i_pchipHandle, i_childDomain);
  iv_childrenDomains.push_back(l_chipDomPtrPair);
  return(l_rc);
}

//Just getting an iterator to go through the vector of chip/domain pairs.
template<class T>
typename ParentDomain<T>::iterator ParentDomain<T>::getBeginIterator()
{
  return(iv_childrenDomains.begin());
}

template<class T>
typename ParentDomain<T>::iterator ParentDomain<T>::getEndIterator()
{
  return(iv_childrenDomains.end());
}


//This instance of ParentDomain has to remain after the definition
//  of the Templated class function or it won't link correctly.
template class ParentDomain<ExtensibleDomain>;

} // end namespace PRDF
