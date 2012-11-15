/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipDomainContainer.inl $ */
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

#ifndef iipDomainContainer_inl
#define iipDomainContainer_inl


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
  return((T *) ((i_chipIndex < chips.size()) ? chips[i_chipIndex] : NULL));
}

template<class T>
inline
T * DomainContainer<T>::LookUp(unsigned int i_chipIndex)
{
  return((T *) ((i_chipIndex < chips.size()) ? chips[i_chipIndex] : NULL));
}

template<class T>
inline
uint32_t DomainContainer<T>::GetSize(void) const
{
  return(chips.size());
}

#endif

