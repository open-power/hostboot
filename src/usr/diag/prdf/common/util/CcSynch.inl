/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/CcSynch.inl $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1995,2012              */
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

#ifndef CcSynch_inl
#define CcSynch_inl

// Includes

template <class STEP_TYPE, class ID>
inline
void CcSynch<STEP_TYPE, ID>::Advance(void)
  {
  step++;
  }

template <class STEP_TYPE, class ID>
inline
CcSynch<STEP_TYPE, ID>::CcSynch(void) :
  myStep(INSTANCE_INITIAL_VALUE)
  {
  }

template <class STEP_TYPE, class ID>
bool CcSynch<STEP_TYPE, ID>::IsCurrent(void)
  {
  bool rc = (step == myStep);

  myStep = step;

  return(rc);
  }

// Change Log **********************************************************
//
//  Flag  PTR/DCR#  Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  n/a   n/a       JST       04/06/95  Created.
//
// End Change Log ******************************************************

#endif

