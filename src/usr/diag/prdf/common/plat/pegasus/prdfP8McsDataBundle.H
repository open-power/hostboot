/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8McsDataBundle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#ifndef __prdfP8McsDataBundle_H
#define __prdfP8McsDataBundle_H

/** @file  prdfP8McsDataBundle.H
 *  @brief Contains the data bundle for a P8 MCS object.
 */

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfParserEnums.H>

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
        iv_mcsChip(i_mcsChip), iv_membChip(NULL), iv_primMirMcsChip(NULL)
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

    /** @return The primary MCS of a mirrored MCS pair. */
    ExtensibleChip * getPrimaryMirroredMcs()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        do
        {
            if ( NULL != iv_primMirMcsChip ) break; // nothing to do.

            TargetHandle_t mcs = iv_mcsChip->GetChipHandle();
            uint32_t pos       = getTargetPosition(mcs);

            if ( MAX_MCS_PER_PROC <= pos ) break; // can't continue, return NULL

            if ( 0 == (pos & 0x1) ) // This is the primary.
            {
                iv_primMirMcsChip = iv_mcsChip;
            }
            else // The other MCS is the primary.
            {
                pos &= ~0x1; // get even position

                TargetHandle_t proc = getConnectedParent( mcs, TYPE_PROC );
                if ( NULL == proc ) break; // can't continue, return NULL

                TargetHandle_t pmcs = getConnectedChild( proc, TYPE_MCS, pos );
                if ( NULL == pmcs ) break; // can't continue, return NULL

                iv_primMirMcsChip = (ExtensibleChip *)systemPtr->GetChip(pmcs);
            }

        } while (0);

        return iv_primMirMcsChip;
    }

  private: // functions

    P8McsDataBundle( const P8McsDataBundle & );
    const P8McsDataBundle & operator=( const P8McsDataBundle & );

  private: // instance variables

    ExtensibleChip * iv_mcsChip;  ///< This MCS chip
    ExtensibleChip * iv_membChip; ///< The connected MEMBUF chip

    /** The primary MCS of a mirrored MCS pair. */
    ExtensibleChip * iv_primMirMcsChip;
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

