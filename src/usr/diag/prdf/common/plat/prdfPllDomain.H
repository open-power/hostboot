/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPllDomain.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef prdfPllDomain_H
#define prdfPllDomain_H

#include <iipDomain.h>
#include <iipResolutionFactory.h>
#include <prdfExtensibleDomain.H>
#include <prdfRuleChipDomain.H>
#include <prdfThresholdResolutions.H>

#ifndef __HOSTBOOT_MODULE
  #include <hdctContent.H> // for hwTableContent
#endif

namespace PRDF
{

//------------------------------------------------------------------------------

class PllDomain : public RuleChipDomain, public ExtensibleDomain
{
  public:

#ifdef __HOSTBOOT_MODULE

    /**
     * @brief Constructor
     * @param DOMAIN_ID  the domain ID
     * @param Resolution to callout the correct clock source
     * @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

    /**
     * @brief Constructor
     * @param DOMAIN_ID  the domain ID
     * @param Resolution to callout the correct second clock source
     * @param Resolution to callout the correct clock source
     * @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & secondClockSource,
               Resolution & clockSource,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

#else // not __HOSTBOOT_MODULE

    /**
     * @brief Constructor
     * @param DOMAIN_ID  the domain ID
     * @param Resolution to callout the correct clock source
     * @param Dump content
     * @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               hwTableContent i_hwdc,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

    /**
     * @brief Constructor
     * @param DOMAIN_ID  the domain ID
     * @param Resolution to callout the correct second clock source
     * @param Resolution to callout the correct clock source
     * @param Dump content
     * @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & secondClockSource,
               Resolution & clockSource,
               hwTableContent i_hwdc,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

#endif // not __HOSTBOOT_MODULE

  /**
   *  @brief Perform any initialization required by the hardware
   *  @returns error code
   *  @post  PLL errors cleared in hardware.
   */
  virtual int32_t Initialize(void);

  /**
   * @brief Query if anything in this domain is at the attention type specified
   * @param Attention type to query for. (@see iipsdbug.h)
   * @returns [true|false]
   * @pre Initialize()
   */
  virtual bool Query(ATTENTION_TYPE attentionType);

  /**
   * @brief Analyze errors within the domain
   * @param service data collector
   * @param attentiont type (@see iipsdbug.h)
   * @returns service data collector - completed
   * @return return code
   * @pre Initialize(); Query() == true
   * @post domain element order may be modified.
   */
  virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & serviceData,
                           ATTENTION_TYPE attentionType );

    /**
     * @brief  Domain level plugin function used to clear PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @return SUCCESS
     */
    static int32_t ClearPll( ExtensibleDomain * i_domain,
                             STEP_CODE_DATA_STRUCT & i_sc );

    /**
     * @brief  Domain level plugin function used to mask PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @param  i_errType type of PLL error needing masking
     * @return SUCCESS
     */
    static int32_t MaskPll( ExtensibleDomain * i_domain,
                            STEP_CODE_DATA_STRUCT & i_sc,
                            uint32_t i_errType );

    /**
     * @brief  Domain level plugin function used to mask PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @param  i_oscPos osc position (only used by IO pcie domain)
     * @return SUCCESS
     */
    static int32_t MaskPllIo( ExtensibleDomain * i_domain,
                            STEP_CODE_DATA_STRUCT & i_sc,
                            uint32_t i_oscPos );

protected:

  /**
   * @brief Order the domain - with detecting element at the top
   * @param Attention type (@see iipsdbug.h)
   * @post domain elemenet order may be altered
   * @note this is called by Analyze()
   */
  virtual void Order(ATTENTION_TYPE attentionType);

private:  // Data

  enum { CONTAINER_SIZE = 8 };

  Resolution & closeClockSource;
  Resolution & farClockSource;

  Resolution & iv_threshold;

#ifndef __HOSTBOOT_MODULE
    hwTableContent iv_dumpContent;
#endif

};

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    RuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    ExtensibleDomain("PllDomain"),
    closeClockSource(clockSource),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) )
{
}

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & secondClockSource,
                      Resolution & clockSource,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    RuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    ExtensibleDomain("PllDomain"),
    closeClockSource(secondClockSource),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) )
{
}

#else // not __HOSTBOOT_MODULE

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
                      hwTableContent i_hwdc,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    RuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    ExtensibleDomain("PllDomain"),
    closeClockSource(clockSource),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) ),
    iv_dumpContent(i_hwdc)
{
}

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & secondClockSource,
                      Resolution & clockSource,
                      hwTableContent i_hwdc,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    RuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    ExtensibleDomain("PllDomain"),
    closeClockSource(secondClockSource),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) ),
    iv_dumpContent(i_hwdc)
{
}

#endif // not __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif /* prdfPllDomain_H */

