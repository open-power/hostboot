/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfPllDomain.H $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2006,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef prdfPllDomain_H
#define prdfPllDomain_H

#include <iipDomain.h>
#include <iipResolutionFactory.h>
#include <prdfExtensibleDomain.H>
#include <prdfParentDomain.H>
#include <prdfRuleChipDomain.H>
#include <prdfThresholdResolutions.H>

#ifndef __HOSTBOOT_MODULE
  #include <hdctContent.H> // for hwTableContent
#endif

namespace PRDF
{

//------------------------------------------------------------------------------

class PllDomain : public RuleChipDomain, public ExtensibleDomain,
                  public ParentDomain<ExtensibleDomain>
{
  public:

#ifdef __HOSTBOOT_MODULE

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct clock source
     *  @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

#else // not __HOSTBOOT_MODULE

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct clock source
     *  @param Dump content
     *  @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               hwTableContent i_hwdc,
               const ThresholdResolution::ThresholdPolicy & i_mfgThresh );

#endif // not __HOSTBOOT_MODULE

  /**
   Perform any initialization required by the hardware
   @returns error code
   @post  PLL errors cleared in hardware.
   */
  virtual int32_t Initialize(void);

  /**
   Query if anything in this domain is at the attention type specified
   @param Attention type to query for. (@see iipsdbug.h)
   @returns [true|false]
   @pre Initialize()
   @post NONE
   */
  virtual bool Query(ATTENTION_TYPE attentionType);

  /**
   Analyze errors within the domain
   @param service data collector
   @param attentiont type (@see iipsdbug.h)
   @returns service data collector - completed
   @return return code
   @pre Initialize(); Query() == true
   @post domain element order may be modified.
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
                             STEP_CODE_DATA_STRUCT i_sc );

    /**
     * @brief  Domain level plugin function used to mask PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @return SUCCESS
     */
    static int32_t MaskPll( ExtensibleDomain * i_domain,
                            STEP_CODE_DATA_STRUCT i_sc );

protected:

  /**
   Order the domain - with detecting element at the top
   @param Attention type (@see iipsdbug.h)
   @post domain elemenet order may be altered
   @note this is called by Analyze()
   */
  virtual void Order(ATTENTION_TYPE attentionType);

private:  // functions
private:  // Data

  enum {CONTAINER_SIZE = 8, PRDF_PLL_ERROR = 0xed};

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
{}

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
{}

#endif // not __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif /* prdfPllDomain_H */

