/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9ExDataBundle.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

#ifndef _PRDFP9EXDATABUNDLE_H
#define _PRDFP9EXDATABUNDLE_H

/** @file  prdfP9ExDataBundle.H
 *  @brief Contains the data bundle for a P9 Ex object.
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
 * @brief The P9 EX data bundle.
 */
class P9ExDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_exChip The ex chip.
     */
    explicit P9ExDataBundle( ExtensibleChip * i_exChip ) :
        iv_L2LDCount(0), iv_L3LDCount(0), 
        iv_exChip(i_exChip)
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
    ~P9ExDataBundle()
    {
        delete iv_L2CETable;
        delete iv_L3CETable;
    };
    // Current counts for L2 line deletes.
    uint8_t iv_L2LDCount;
    LineDelete::PrdfCacheCETable * iv_L2CETable;

    // Current counts for L3 line deletes.
    uint8_t iv_L3LDCount;
    LineDelete::PrdfCacheCETable * iv_L3CETable;

  private:
    ExtensibleChip * iv_exChip;  ///< This ex chip

    P9ExDataBundle( const P9ExDataBundle & );
    const P9ExDataBundle & operator=( const P9ExDataBundle & );

};

/**
 * @brief  Wrapper function for the P9ExDataBundle.
 * @param  i_exChip The ex chip.
 * @return This ex's data bundle.
 */
inline P9ExDataBundle * getExDataBundle( ExtensibleChip * i_exChip )
{
    return static_cast<P9ExDataBundle *>(i_exChip->getDataBundle());
}

} // end namespace PRDF

#endif /* _PRDFP9EXDATABUNDLE_H */
