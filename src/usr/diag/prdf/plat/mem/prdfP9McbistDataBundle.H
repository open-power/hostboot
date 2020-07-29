/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9McbistDataBundle.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __prdfP9McbistDataBundle_H
#define __prdfP9McbistDataBundle_H

/** @file  prdfP9McbistDataBundle.H
 *  @brief Contains the data bundle for a P9 MCBIST object.
 */

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemTdCtlr.H>
#include <prdfPlatServices.H>
#include <prdfThresholdUtils.H>

namespace PRDF
{

/** @brief P9 MCBIST data bundle. */
class McbistDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mcbChip The MCBIST chip.
     */
    explicit McbistDataBundle( ExtensibleChip * i_mcbChip ) :
        iv_chip(i_mcbChip)
    {}

    /** @brief Destructor. */
    ~McbistDataBundle()
    {
        delete iv_tdCtlr; iv_tdCtlr = nullptr;
    }

    // Don't allow copy or assignment.
    McbistDataBundle( const McbistDataBundle & ) = delete;
    const McbistDataBundle & operator=( const McbistDataBundle & ) = delete;

    /** @return The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_MCBIST> * getTdCtlr()
    {
        if ( nullptr == iv_tdCtlr )
        {
            iv_tdCtlr = new MemTdCtlr<TARGETING::TYPE_MCBIST>{iv_chip};
        }

        return iv_tdCtlr;
    }

  private: // instance variables

    /** The MCBIST chip associated with this data bundle. */
    ExtensibleChip * const iv_chip;

    /** The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_MCBIST> * iv_tdCtlr = nullptr;

  public: // instance variables
    #ifdef __HOSTBOOT_RUNTIME

    // These are used to limit the number of times a scrub command will stop
    // on a UE or CE on a rank. This is to prevent potential flooding of
    // maintenance UEs or CEs. The threshold will be 16 per rank for each.
    TimeBasedThreshold iv_ueStopCounter =
        TimeBasedThreshold( 16, ThresholdResolution::SEVEN_HOURS );
    TimeBasedThreshold iv_ceStopCounter =
        TimeBasedThreshold( 16, ThresholdResolution::SEVEN_HOURS );

    // If we stop on a UE or a CE, we will need to store the rank that the
    // error is on so that we can clear our respective thresholds if the
    // next error we stop on is on a different rank.
    MemRank iv_ceUeRank;

    #endif
};

/**
 * @brief  Wrapper function for the McbistDataBundle.
 * @param i_mcbChip The MCBIST chip.
 * @return This MBA's data bundle.
 */
inline McbistDataBundle * getMcbistDataBundle( ExtensibleChip * i_mcbChip )
{
    return static_cast<McbistDataBundle *>(i_mcbChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfP9McbistDataBundle_H

