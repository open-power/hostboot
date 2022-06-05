/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10CoreDataBundle.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#ifndef _PRDFP10COREDATABUNDLE_H
#define _PRDFP10COREDATABUNDLE_H

/** @file  prdfP10CoreDataBundle.H
 *  @brief Contains the data bundle for a P10 Core object.
 */

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfThresholdUtils.H>
#include <prdfLineDelete.H>

namespace PRDF
{

/**
 * @brief The P10 Core data bundle.
 */
class P10CoreDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_coreChip The core chip.
     */
    explicit P10CoreDataBundle( ExtensibleChip * i_coreChip ) :
        iv_L2LDCount(0), iv_L3LDCount(0), iv_coreChip(i_coreChip)
    {
        // Set up thresholds for line deletes.
        iv_L2CETable = new LineDelete::PrdfCacheCETable(
          ThresholdResolution::ThresholdPolicy(PlatServices::mfgMode() ? 1 : 2,
                                               ThresholdResolution::ONE_DAY));
        iv_L3CETable = new LineDelete::PrdfCacheCETable(
          ThresholdResolution::ThresholdPolicy(PlatServices::mfgMode() ? 1 : 2,
                                               ThresholdResolution::ONE_DAY));
    };

    /**
     * @brief Destructor.
     */
    ~P10CoreDataBundle()
    {
        delete iv_L2CETable;
        delete iv_L3CETable;
    };
    // Current counts for L2 line deletes.
    uint8_t iv_L2LDCount;
    LineDelete::PrdfCacheCETable * iv_L2CETable;

    // Current counts for L3 line deletes.
    uint8_t  iv_L3LDCount;
    LineDelete::PrdfCacheCETable * iv_L3CETable;

  private:
    ExtensibleChip * iv_coreChip;  ///< This core chip

    P10CoreDataBundle( const P10CoreDataBundle & );
    const P10CoreDataBundle & operator=( const P10CoreDataBundle & );

};

/**
 * @brief  Wrapper function for the P10CoreDataBundle.
 * @param  i_coreChip The core chip.
 * @return This core's data bundle.
 */
inline P10CoreDataBundle * getCoreDataBundle( ExtensibleChip * i_coreChip )
{
    return static_cast<P10CoreDataBundle *>(i_coreChip->getDataBundle());
}

} // end namespace PRDF

#endif /* _PRDFP10COREDATABUNDLE_H */
