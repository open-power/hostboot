/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfParentDomain.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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

#include <iipglobl.h>
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
  //TODO::Do I need to have this here to clear out the vector?
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
