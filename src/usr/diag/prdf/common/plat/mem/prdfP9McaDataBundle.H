/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfP9McaDataBundle.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifndef __prdfP9McaDataBundle_H
#define __prdfP9McaDataBundle_H

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemCeTable.H>
#include <prdfMemUeTable.H>
#include <prdfPlatServices.H>

#ifdef __HOSTBOOT_MODULE
  #include <prdfP9McbistDataBundle.H>
#endif

#if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
  #include <prdfMemIplCeStats.H>
#endif

namespace PRDF
{

/** @brief P9 MCA data bundle. */
class McaDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip An MCA chip.
     */
    explicit McaDataBundle( ExtensibleChip * i_chip ) :
        iv_chip(i_chip), iv_ceTable(i_chip), iv_ueTable(i_chip)
    {}

    /** @brief Destructor */
    ~McaDataBundle() = default;

    #ifdef __HOSTBOOT_MODULE

    /** @return Wrapper to get Targeted Diagnostics controller from MCBIST. */
    MemTdCtlr<TARGETING::TYPE_MCBIST> * getTdCtlr()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        ExtensibleChip * mcbChip = getConnectedParent( iv_chip, TYPE_MCBIST );
        McbistDataBundle * mcbdb = getMcbistDataBundle( mcbChip );
        return mcbdb->getTdCtlr();
    }

    #endif

    #if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

    /** @return The IPL CE statistics object. */
    MemIplCeStats<TARGETING::TYPE_MCA> * getIplCeStats()
    {
        if ( nullptr == iv_iplCeStats )
        {
            iv_iplCeStats = new MemIplCeStats<TARGETING::TYPE_MCA>( iv_chip );
        }

        return iv_iplCeStats;
    }

    #endif

  private: // functions

    // Don't allow copy or assignment.
    McaDataBundle( const McaDataBundle & ) = delete;
    const McaDataBundle & operator=( const McaDataBundle & ) = delete;

  private: // instance variables

    ExtensibleChip * iv_chip; // This MCA.

    #if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

    /** MNFG IPL CE statistics. */
    MemIplCeStats<TARGETING::TYPE_MCA> * iv_iplCeStats = nullptr;

    #endif

  public: // instance variables

    MemCeTable<TARGETING::TYPE_MCA> iv_ceTable; ///< CE table for FFDC
    MemUeTable iv_ueTable;                      ///< UE table for FFDC
};

/**
 * @brief  Wrapper function for the McaDataBundle.
 * @param  i_chip An MCA chip.
 * @return This MBA's data bundle.
 */
inline McaDataBundle * getMcaDataBundle( ExtensibleChip * i_chip )
{
    return static_cast<McaDataBundle *>(i_chip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfP9McaDataBundle_H

