/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file prdfMemVcm.H */

#ifndef __prdfMemVcm_H
#define __prdfMemVcm_H

// Platform includes
#include <prdfMemTdQueue.H>
#include <prdfMemMark.H>

namespace PRDF
{

/** @brief Verify chip mark procedure. */
template <TARGETING::TYPE T>
class VcmEvent : public TdEntry
{
  public: // functions

    /** @brief Constructor */
    VcmEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark ) :
        TdEntry(VCM_EVENT, i_chip, i_rank), iv_mark(i_mark)
    {
        PRDF_ASSERT( i_mark.isValid() );
    }

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

  private: // instance variables
    const MemMark iv_mark;

};

} // end namespace PRDF

#endif // __prdfMemVcm_H

