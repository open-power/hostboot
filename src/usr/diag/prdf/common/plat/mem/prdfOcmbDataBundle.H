/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfOcmbDataBundle.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __prdfOcmbDataBundle_H
#define __prdfOcmbDataBundle_H

/** @file  prdfOcmbDataBundle.H
 *  @brief Contains the data bundle for a P9 OCMB_CHIP object.
 */

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfPlatServices.H>
#include <prdfMemCeTable.H>
#include <prdfMemUeTable.H>

#ifdef __HOSTBOOT_MODULE

#include <prdfMemTdFalseAlarm.H>
#include <prdfMemThresholds.H>
#include <prdfMemTdCtlr.H>

#ifndef __HOSTBOOT_RUNTIME
#include <prdfMemIplCeStats.H>
#endif

#endif // __HOSTBOOT_MODULE

namespace PRDF
{

/** @brief P9 OCMB data bundle. */
class OcmbDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_ocmbChip The OCMB chip.
     */
    explicit OcmbDataBundle( ExtensibleChip * i_ocmbChip ) :
        iv_chip(i_ocmbChip), iv_ceTable(i_ocmbChip), iv_ueTable(i_ocmbChip)
    {}

    /** @brief Destructor. */
    ~OcmbDataBundle()
    {
        #ifdef __HOSTBOOT_MODULE
            #ifdef __HOSTBOOT_RUNTIME
                delete iv_vcmFalseAlarmCounter;
                delete iv_tpsFalseAlarmCounter;
            #else // IPL only
                delete iv_iplCeStats;
            #endif
        delete iv_tdCtlr; iv_tdCtlr = nullptr;
        #endif // __HOSTBOOT_MODULE
    }

    // Don't allow copy or assignment.
    OcmbDataBundle( const OcmbDataBundle & ) = delete;
    const OcmbDataBundle & operator=( const OcmbDataBundle & ) = delete;

    #ifdef __HOSTBOOT_MODULE

    /** @return The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_OCMB_CHIP> * getTdCtlr()
    {
        if ( nullptr == iv_tdCtlr )
        {
            iv_tdCtlr = new MemTdCtlr<TARGETING::TYPE_OCMB_CHIP>{iv_chip};
        }

        return iv_tdCtlr;
    }

    /** @return The IMPE threshold counter. */
    VcmFalseAlarm * getImpeThresholdCounter()
    {
        if ( nullptr == iv_impeThresholdCounter )
        {
            iv_impeThresholdCounter = new VcmFalseAlarm(
                                           TimeBasedThreshold { getImpeTh() } );
        }

        return iv_impeThresholdCounter;
    }

    #ifdef __HOSTBOOT_RUNTIME

    /** @return The VCM false alarm counter. */
    VcmFalseAlarm * getVcmFalseAlarmCounter()
    {
        if ( nullptr == iv_vcmFalseAlarmCounter )
        {
            iv_vcmFalseAlarmCounter = new VcmFalseAlarm(
                       TimeBasedThreshold { 4, ThresholdResolution::ONE_DAY } );
        }

        return iv_vcmFalseAlarmCounter;
    }

    /** @return The TPS false alarm counter. */
    TpsFalseAlarm * getTpsFalseAlarmCounter()
    {
        if ( nullptr == iv_tpsFalseAlarmCounter )
        {
            iv_tpsFalseAlarmCounter = new TpsFalseAlarm(
                TimeBasedThreshold{ 3, ThresholdResolution::ONE_DAY } );
        }

        return iv_tpsFalseAlarmCounter;
    }

    #else // IPL only

    /** @return The IPL CE statistics object. */
    MemIplCeStats<TARGETING::TYPE_OCMB_CHIP> * getIplCeStats()
    {
        if ( nullptr == iv_iplCeStats )
        {
            iv_iplCeStats =
                new MemIplCeStats<TARGETING::TYPE_OCMB_CHIP>( iv_chip );
        }

        return iv_iplCeStats;
    }

    #endif

    #endif // __HOSTBOOT_MODULE

  private: // instance variables

    /** The OCMB chip associated with this data bundle. */
    ExtensibleChip * const iv_chip;

    #ifdef __HOSTBOOT_MODULE

    /** The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_OCMB_CHIP> * iv_tdCtlr = nullptr;

    /** IMPE threshold counter. */
    VcmFalseAlarm * iv_impeThresholdCounter = nullptr;

    #endif // __HOSTBOOT_MODULE

  public: // instance variables

    MemCeTable<TARGETING::TYPE_OCMB_CHIP> iv_ceTable; ///< CE table for FFDC
    MemUeTable iv_ueTable;                           ///< UE table for FFDC

    #ifdef __HOSTBOOT_MODULE

    /** Threshold table for RCD parity errors. */
    TimeBasedThreshold iv_rcdParityTh = TimeBasedThreshold( getRcdParityTh() );

    /** Threshold table for IUEs. Threshold per DIMM */
    std::map<uint8_t, TimeBasedThreshold> iv_iueTh;

    /** Bool to indicate if we've triggered a port fail because of IUEs. */
    bool iv_iuePortFail = false;

    #ifdef __HOSTBOOT_RUNTIME

    /** VCM false alarm counter. */
    VcmFalseAlarm * iv_vcmFalseAlarmCounter = nullptr;

    /** TPS false alarm counter. */
    TpsFalseAlarm * iv_tpsFalseAlarmCounter = nullptr;

    /** Set to true if mainline NCEs and TCEs should be permanently masked. This
     *  is checked at the end of targeted diagnostics before background
     *  scrubbing is resumed. */
    bool iv_maskMainlineNceTce = false;

    #else // IPL only

    /** MNFG IPL CE statistics. */
    MemIplCeStats<TARGETING::TYPE_OCMB_CHIP> * iv_iplCeStats = nullptr;

    #endif

    #endif // __HOSTBOOT_MODULE

};

/**
 * @brief  Wrapper function for the OcmbDataBundle.
 * @param i_ocmbChip The OCMB chip.
 * @return This MBA's data bundle.
 */
inline OcmbDataBundle * getOcmbDataBundle( ExtensibleChip * i_ocmbChip )
{
    return static_cast<OcmbDataBundle *>(i_ocmbChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfOcmbDataBundle_H

