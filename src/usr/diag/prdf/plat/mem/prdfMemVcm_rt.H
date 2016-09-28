/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm_rt.H $                  */
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

/** @file prdfMemVcm_rt.H */

#ifndef __prdfMemVcm_rt_H
#define __prdfMemVcm_rt_H

// Platform includes
#include <prdfMemTdQueue.H>

namespace PRDF
{

// Only implement specializations of VcmEvent.
template<TARGETING::TYPE T> class VcmEvent;

// TODO: RTC 136126 Actual implementation of this procedure will be done later.
/** @brief Verify chip mark procedure for MCA (RT only). */
template <>
class VcmEvent<TARGETING::TYPE_MCA> : public TdEntry
{
  public: // functions

    /** @brief Constructor */
    VcmEvent<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip, MemRank i_rank ) :
        TdEntry(VCM_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
/** @brief Verify chip mark procedure for MBA (RT only). */
template <>
class VcmEvent<TARGETING::TYPE_MBA> : public TdEntry
{
  public: // functions

    /** @brief Constructor */
    VcmEvent<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip, MemRank i_rank ) :
        TdEntry(VCM_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

} // end namespace PRDF

#endif // __prdfMemVcm_rt_H

