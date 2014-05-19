/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaDataBundle_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef PRDF_CEN_MBA_DATABUNDLE_COMMON_H
#define PRDF_CEN_MBA_DATABUNDLE_COMMON_H

/** @file  prdfCenMbaDataBundle_common.H
 *  @brief Contains the common data bundle for a Centaur MBA object.
 */

// Framework includes
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenMbaTdCtlr.H>
#include <prdfCenMbaUeTable.H>
#include <prdfCenMbaCeTable.H>
#include <prdfCenMbaRceTable.H>

namespace PRDF
{

/**
 * @brief The P8 Centaur MBA data bundle.
 */
class CenMbaDataBundleCommon : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mbaChip The MBA chip.
     */
    explicit CenMbaDataBundleCommon( ExtensibleChip * i_mbaChip ) :
        iv_mbaChip(i_mbaChip), iv_membChip(NULL), iv_tdCtlr(i_mbaChip),
        iv_ueTable( i_mbaChip->GetChipHandle()),
        iv_ceTable( i_mbaChip->GetChipHandle()),
        iv_rceTable(i_mbaChip->GetChipHandle())
    {}

    /**
     * @brief Destructor.
     */
    ~CenMbaDataBundleCommon() {}

    /** @return The connected MEMBUF chip. */
    ExtensibleChip * getMembChip()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        if ( NULL == iv_membChip )
        {
            TargetHandle_t mba = iv_mbaChip->GetChipHandle();

            TargetHandle_t memb = getConnectedParent( mba, TYPE_MEMBUF );
            if ( NULL != memb )
                iv_membChip = (ExtensibleChip *)systemPtr->GetChip( memb );
        }

        return iv_membChip;
    }

  private: // functions

    CenMbaDataBundleCommon( const CenMbaDataBundleCommon & );
    const CenMbaDataBundleCommon & operator=( const CenMbaDataBundleCommon & );

  protected: // instance variables

    ExtensibleChip * iv_mbaChip;  ///< This MBA chip

  private: // instance variables

    ExtensibleChip * iv_membChip; ///< The connected MEMBUF chip

  public: // instance variables

    CenMbaTdCtlr   iv_tdCtlr;      ///< Targeted Diagnostics Controller
    CenMbaUeTable  iv_ueTable;     ///< UE table for FFDC
    CenMbaCeTable  iv_ceTable;     ///< CE table for FFDC
    CenMbaRceTable iv_rceTable;    ///< RCE table for FFDC

};

} // end namespace PRDF

#endif // PRDF_CEN_MBA_DATABUNDLE_COMMON_H

