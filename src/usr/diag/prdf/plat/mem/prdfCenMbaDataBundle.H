/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfCenMbaDataBundle.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#ifndef __prdfCenMbaDataBundle_H
#define __prdfCenMbaDataBundle_H

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemTdCtlr.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief Centaur MBA data bundle. */
class MbaDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mbaChip The MBA chip.
     */
    explicit MbaDataBundle( ExtensibleChip * i_mbaChip ) :
        iv_chip(i_mbaChip)
    {}

    /** @brief Destructor. */
    ~MbaDataBundle()
    {
        delete iv_tdCtlr; iv_tdCtlr = nullptr;
    }

    // Don't allow copy or assignment.
    MbaDataBundle( const MbaDataBundle & ) = delete;
    const MbaDataBundle & operator=( const MbaDataBundle & ) = delete;

    /** @return The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_MBA> * getTdCtlr()
    {
        if ( nullptr == iv_tdCtlr )
        {
            iv_tdCtlr = new MemTdCtlr<TARGETING::TYPE_MBA>{iv_chip};
        }

        return iv_tdCtlr;
    }

  private: // instance variables

    /** The MBA chip associated with this data bundle. */
    ExtensibleChip * const iv_chip;

    /** The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_MBA> * iv_tdCtlr = nullptr;
};

/**
 * @brief  Wrapper function for the MbaDataBundle.
 * @param  i_mbaChip The MBA chip.
 * @return This MBA's data bundle.
 */
inline MbaDataBundle * getMbaDataBundle( ExtensibleChip * i_mbaChip )
{
    return static_cast<MbaDataBundle *>(i_mbaChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfCenMbaDataBundle_H

