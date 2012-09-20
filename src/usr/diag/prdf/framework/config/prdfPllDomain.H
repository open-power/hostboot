/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfPllDomain.H $          */
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
#include <prdfRuleChipDomain.H>
#include <prdfParentDomain.H>

#ifndef iipResolutionFactory_h
#include <iipResolutionFactory.h>
#endif

#include <prdfThresholdResolutions.H>
#include <hdctContent.H> // for hwTableContent

#include <prdfExtensibleDomain.H>

namespace PRDF
{

//------------------------------------------------------------------------------

class PllDomain : public PrdfRuleChipDomain, public PrdfExtensibleDomain,
                  public ParentDomain<PrdfExtensibleDomain>
{
  public:

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct clock source
     *  @param Dump content
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               hwTableContent i_hwdc );

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct repower clock logic
     *  @param Resolution to callout the correct clock source
     *  @param Dump content
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockRpwr,
               Resolution & clockSource, hwTableContent i_hwdc );

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct clock source
     *  @param Dump content
     *  @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
               hwTableContent i_hwdc,
               const ThresholdResolution::ThresholdPolicy& i_mfgThresh);

    /** @fn PllDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param Resolution to callout the correct repower clock logic
     *  @param Resolution to callout the correct clock source
     *  @param Dump content
     *  @param ThresholdResolution::ThresholdPolicy
     */
    PllDomain( DOMAIN_ID domain_id, Resolution & clockRpwr,
               Resolution & clockSource, hwTableContent i_hwdc,
               const ThresholdResolution::ThresholdPolicy& i_mfgThresh);
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
  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & serviceData,
                         ATTENTION_TYPE attentionType);

    /**
     * @brief  Domain level plugin function used to clear PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @return SUCCESS
     */
    static int32_t ClearPll( PllDomain * i_domain,
                             STEP_CODE_DATA_STRUCT i_sc );

    /**
     * @brief  Domain level plugin function used to mask PLL attentions in a
     *         domain and its subdomains.
     * @param  i_domain The target PLL domain.
     * @param  i_sc The step code data struct.
     * @return SUCCESS
     */
    static int32_t MaskPll( PllDomain * i_domain,
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

  enum {CONTAINER_SIZE = 8, PRDF_PLL_ERROR = 0xed};      //dg03

  Resolution & closeClockSource;
  Resolution & farClockSource;

//  int threshold;      dg05d
  Resolution & iv_threshold;  // dg05a dg06c
  hwTableContent iv_dumpContent; //dg08a

};

//------------------------------------------------------------------------------

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
                      hwTableContent i_hwdc ) :
    PrdfRuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    PrdfExtensibleDomain("PllDomain"),
    closeClockSource(clockSource),
    farClockSource(clockSource),   // dg06c
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                ThresholdResolution::cv_mnfgDefault ) ),
    iv_dumpContent(i_hwdc)   // dg08a
{ }

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockRpwr,
                      Resolution & clockSource, hwTableContent i_hwdc ) :
    PrdfRuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    PrdfExtensibleDomain("PllDomain"),
    closeClockSource(clockRpwr),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                ThresholdResolution::cv_mnfgDefault )),
    iv_dumpContent(i_hwdc)   //dg08a
{}

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockSource,
                      hwTableContent i_hwdc,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    PrdfRuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    PrdfExtensibleDomain("PllDomain"),
    closeClockSource(clockSource),
    farClockSource(clockSource),   // dg06c
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) ),
    iv_dumpContent(i_hwdc)   // dg08a
{ }

inline
PllDomain::PllDomain( DOMAIN_ID domain_id, Resolution & clockRpwr,
                      Resolution & clockSource, hwTableContent i_hwdc,
                      const ThresholdResolution::ThresholdPolicy& i_mfgThresh) :
    PrdfRuleChipDomain( domain_id, PllDomain::CONTAINER_SIZE ),
    PrdfExtensibleDomain("PllDomain"),
    closeClockSource(clockRpwr),
    farClockSource(clockSource),
    iv_threshold( ResolutionFactory::Access().GetThresholdResolution( 1,
                                ThresholdResolution::cv_pllDefault,
                                i_mfgThresh ) ),
    iv_dumpContent(i_hwdc)   //dg08a
{}

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif /* prdfPllDomain_H */

