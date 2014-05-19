/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8McsDataBundle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef __prdfP8McsDataBundle_H
#define __prdfP8McsDataBundle_H

/** @file  prdfP8McsDataBundle.H
 *  @brief Contains the data bundle for a P8 MCS object.
 */

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/**
 * @brief The P8 Centaur MBA data bundle.
 */
class P8McsDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mcsChip The MCS chip.
     */
    explicit P8McsDataBundle( ExtensibleChip * i_mcsChip ) :
        iv_mcsChip(i_mcsChip), iv_membChip(NULL)
    {}

    /**
     * @brief Destructor.
     */
    ~P8McsDataBundle() {}

    /** @return The connected MEMBUF chip. */
    ExtensibleChip * getMembChip()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        if ( NULL == iv_membChip )
        {
            TargetHandle_t mcs = iv_mcsChip->GetChipHandle();

            TargetHandle_t memb = getConnectedChild( mcs, TYPE_MEMBUF, 0 );
            if ( NULL != memb )
                iv_membChip = (ExtensibleChip *)systemPtr->GetChip( memb );
        }

        return iv_membChip;
    }

  private: // functions

    P8McsDataBundle( const P8McsDataBundle & );
    const P8McsDataBundle & operator=( const P8McsDataBundle & );

  private: // instance variables

    ExtensibleChip * iv_mcsChip;  ///< This MCS chip
    ExtensibleChip * iv_membChip; ///< The connected MEMBUF chip
};

//------------------------------------------------------------------------------

/**
 * @brief  Wrapper function for the P8McsDataBundle.
 * @param  i_mcsChip The MCS chip.
 * @return This MBA's data bundle.
 */
inline P8McsDataBundle * getMcsDataBundle( ExtensibleChip * i_mcsChip )
{
    return static_cast<P8McsDataBundle *>(i_mcsChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfP8McsDataBundle_H

