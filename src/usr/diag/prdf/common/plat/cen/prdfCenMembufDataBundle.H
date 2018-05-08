/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/cen/prdfCenMembufDataBundle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

#ifndef __prdfCenMembufDataBundle_H
#define __prdfCenMembufDataBundle_H

// Framework includes
#include <prdfExtensibleChip.H>

namespace PRDF
{

/** @brief Centaur MEMBUF data bundle. */
class MembufDataBundle : public DataBundle
{
  public:

    /**
     * @brief Constructor.
     * @param i_chip The MEMBUF chip.
     */
    explicit MembufDataBundle( ExtensibleChip * i_chip ) : iv_chip(i_chip) {}

    /** @brief Destructor */
    ~MembufDataBundle() {}

  private: // functions

    MembufDataBundle( const MembufDataBundle & );
    const MembufDataBundle & operator=( const MembufDataBundle & );

  private: // instance variables

    /** The MEMBUF chip associated with this data bundle. */
    ExtensibleChip * const iv_chip;

  public: // instance variables

    /** If there is a channel failure detected on this bus, there will be some
     *  required cleanup after analysis to mask off all further attentions from
     *  the bus. A channel failure could occur on either side of the bus and it
     *  is possible the cleanup function could be called in multiple
     *  PostAnalysis plugins depending on where the channel failure occurred.
     *  Since we only want to do one cleanup, we will use this variable to
     *  indicate if a cleanup is still required or has already been done. */
    bool iv_doChnlFailCleanup = false;
};

/**
 * @brief  Wrapper function for the MembufDataBundle.
 * @param  i_membChip The centaur chip.
 * @return This centaur's data bundle.
 */
inline MembufDataBundle * getMembufDataBundle( ExtensibleChip * i_membChip )
{
    return static_cast<MembufDataBundle *>(i_membChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfCenMembufDataBundle_H

