/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemRank.H $             */
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

/** @file  prdfMemRank.H
 *  @brief Memory rank container class for Centaur MBA and P9 MCBIST.
 */

#ifndef __prdfMemRank_H
#define __prdfMemRank_H

#include <prdfAssert.h>
#include <prdf_types.h>

namespace PRDF
{

//------------------------------------------------------------------------------
//  Class MemRank
//------------------------------------------------------------------------------

/** @brief Simple container for a memory rank.
 *  @note  These ranks are relative to the MBA and MCA targets. Therefore, they
 *         do not contain information like the port, which is needed for MCBIST
 *         targets. So that information will need to be derived elsewhere.
 */
class MemRank
{
  public: // enums, constants

    enum
    {
        MAX_DSLCT_PER_PORT  = 2, ///< DIMM select per port
        MAX_RSLCT_PER_DSLCT = 4, ///< rank select per DIMM select

        MAX_MRNK_PER_PORT = MAX_DSLCT_PER_PORT * MAX_RSLCT_PER_DSLCT,
        MAX_SRNK_PER_MRNK = 8,
    };

  public: // functions

    /** @brief Default constructor */
    MemRank() = default;

    /**
     * @brief Constructor from components.
     * @param i_mrank The 3-bit master rank (combined DIMM slct and rank slct).
     * @param i_srank The 3-bit slave rank.
     */
    explicit MemRank( uint8_t i_mrnk, uint8_t i_srnk = 0 ) :
        iv_mrnk(i_mrnk), iv_srnk(i_srnk)
    {
        PRDF_ASSERT( iv_mrnk < MAX_MRNK_PER_PORT  );
        PRDF_ASSERT( iv_srnk < MAX_SRNK_PER_MRNK );
    }

    /** @return The master rank (combined DIMM slct and rank slct). */
    uint8_t getMaster() const { return iv_mrnk; }

    /** @return The slave rank. */
    uint8_t getSlave() const { return iv_srnk; }

    /** @return The master DIMM select. */
    uint8_t getDimmSlct() const { return iv_mrnk >> 2; }

    /** @return The master rank select. */
    uint8_t getRankSlct() const { return iv_mrnk & 0x3; }

    /** @brief '==' operator */
    bool operator==( const MemRank & i_rank ) const
    {
        return ( (this->getMaster() == i_rank.getMaster()) &&
                 (this->getSlave()  == i_rank.getSlave() )    );
    }

    /** @brief '<' operator */
    bool operator<( const MemRank & i_rank ) const
    {
        return ( ( (this->getMaster() <  i_rank.getMaster())    ) ||
                 ( (this->getMaster() == i_rank.getMaster()) &&
                   (this->getSlave()  <  i_rank.getSlave() )    )    );
    }

  private: // data

    uint8_t iv_mrnk = 0; ///< Master rank (combined DIMM slct and rank slct)
    uint8_t iv_srnk = 0; ///< Slave rank
};

} // end namespace PRDF

#endif // __prdfMemRank_H

