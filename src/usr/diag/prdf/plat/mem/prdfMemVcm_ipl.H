/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm_ipl.H $                 */
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

/** @file prdfMemVcm_ipl.H */

#ifndef __prdfMemVcm_ipl_H
#define __prdfMemVcm_ipl_H

// Platform includes
#include <prdfMemTdQueue.H>

namespace PRDF
{

// Only implement specializations of VcmEvent.
template<TARGETING::TYPE T> class VcmEvent;

// TODO: RTC 157608 Actual implementation of this procedure will be done later.
/** @brief Verify chip mark procedure for MCBIST (IPL only). */
template <>
class VcmEvent<TARGETING::TYPE_MCBIST> : public TdEntry<TARGETING::TYPE_MCBIST>
{
  public: // functions

    /** @brief Constructor */
    VcmEvent<TARGETING::TYPE_MCBIST>( ExtensibleChip * i_chip,
                                      MemRank i_rank, uint8_t i_port ) :
        TdEntry<TARGETING::TYPE_MCBIST>(VCM_EVENT, i_chip, i_rank, i_port)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
/** @brief Verify chip mark procedure for MBA (IPL only). */
template <>
class VcmEvent<TARGETING::TYPE_MBA> : public TdEntry<TARGETING::TYPE_MBA>
{
  public: // functions

    /** @brief Constructor */
    VcmEvent<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip, MemRank i_rank ) :
        TdEntry<TARGETING::TYPE_MBA>(VCM_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

} // end namespace PRDF

#endif // __prdfMemVcm_ipl_H

