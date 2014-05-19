/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/CcSynch.inl $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1995,2014              */
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

#ifndef CcSynch_inl
#define CcSynch_inl

// Includes

namespace PRDF
{

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

} // end namespace PRDF

#endif

