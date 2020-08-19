/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipDomainContainer.inl $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 1996,2020                        */
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

#ifndef iipDomainContainer_inl
#define iipDomainContainer_inl

namespace PRDF
{

template<class T>
inline
void DomainContainer<T>::AddChip(T * chipPtr)
{
  chips.push_back((T *) chipPtr);
}

template<class T>
inline
const T * DomainContainer<T>::LookUp(unsigned int i_chipIndex) const
{
  return((T *) ((i_chipIndex < chips.size()) ? chips[i_chipIndex] : nullptr));
}

template<class T>
inline
T * DomainContainer<T>::LookUp(unsigned int i_chipIndex)
{
  return((T *) ((i_chipIndex < chips.size()) ? chips[i_chipIndex] : nullptr));
}

template<class T>
inline
uint32_t DomainContainer<T>::GetSize(void) const
{
  return(chips.size());
}

} // end namespace PRDF

#endif

