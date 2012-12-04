/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/CcAutoDeletePointer.inl $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1995,2013              */
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

#ifndef CcAutoDeletePointer_inl
#define CcAutoDeletePointer_inl

// Includes

namespace PRDF
{

template<class T>
inline
CcAutoDeletePointer<T>::CcAutoDeletePointer(T * ptr) :
  pointer(ptr)
  {
  }

template<class T>
inline
CcAutoDeletePointer<T>::~CcAutoDeletePointer(void)
  {
  delete pointer;
  }

template<class T>
inline
T * CcAutoDeletePointer<T>::operator->(void) const
  {
  return(pointer);
  }

template<class T>
inline
T & CcAutoDeletePointer<T>::operator*(void) const
  {
  return(*pointer);
  }

template<class T>
inline
CcAutoDeletePointerVector<T>::CcAutoDeletePointerVector(T * ptr) :
  pointer(ptr)
  {
  }

template<class T>
inline
CcAutoDeletePointerVector<T>::~CcAutoDeletePointerVector(void)
  {
  delete [] pointer;
  }

template<class T>
inline
T * CcAutoDeletePointerVector<T>::operator()(void) const
  {
  return(pointer);
  }

} // end namespace PRDF

#endif

