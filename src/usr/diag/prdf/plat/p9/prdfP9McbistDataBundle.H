/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p9/prdfP9McbistDataBundle.H $          */
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

#ifndef __prdfP9McbistDataBundle_H
#define __prdfP9McbistDataBundle_H

/** @file  prdfP9McbistDataBundle.H
 *  @brief Contains the data bundle for a P9 MCBIST object.
 */

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief P9 MCBIST data bundle. */
class McbistDataBundle : public DataBundle
{
  public: // functions

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief Constructor.
     * @param i_mcbChip The MCBIST chip.
     */
    explicit McbistDataBundle( ExtensibleChip * i_mcbChip ) = default;

    #else

    /**
     * @brief Constructor.
     * @param i_mcbChip The MCBIST chip.
     */
    explicit McbistDataBundle( ExtensibleChip * i_mcbChip ) :
        iv_sendCmdCompleteMsg(false)
    {}

    #endif

    /** @brief Destructor. */
    ~McbistDataBundle() = default;

    // Don't allow copy or assignment.
    McbistDataBundle( const McbistDataBundle & ) = delete;
    const McbistDataBundle & operator=( const McbistDataBundle & ) = delete;

  public: // instance variables

    #ifndef __HOSTBOOT_RUNTIME

    /** TRUE if a message needs to be sent to MDIA in the post analysis plugin,
     *  FALSE otherwise. */
    bool iv_sendCmdCompleteMsg;

    #endif

  private: // instance variables

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

