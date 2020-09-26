/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolutionFactory.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef iipResolutionFactory_h
#define iipResolutionFactory_h

/**
 @file iipResolutionFactory.h
 @brief ResolutionFactory declairation
 */
// Class Description *************************************************
//
//  Name:  ResolutionFactory
//  Base class: None
//
//  Description: Maintains a pool of Analysis Resolutions such that only
//               one instance of a particular Resolution object exists.
//               (flyweight)
//  Usage:
//
//    ResolutionFactory & resolutionPool = ResolutionFactory::Access();
//
//
// End Class Description *********************************************

//#include <xspprdIfCondor.h>     // #define CSP_CONDOR

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipconst.h>
#include <prdfGlobal.H>
#include <prdfFlyWeight.H>
#include <prdfFlyWeightS.H>
#include <prdfThresholdResolutions.H>
#include <prdfAnalyzeConnected.H>
#include <prdfPluginCallResolution.H>
#include <iipEregResolution.h>
#include <xspprdTryResolution.h>
#include <xspprdFlagResolution.h>
#include <prdDumpResolution.H>
#include <prdfCaptureResolution.H>
#include <prdfCalloutGard.H>
#include <prdfCalloutConnectedGard.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 "Flyweight" factory of resolutions (singlton)
 @version V4R5
 @author Douglas R. Gilbert
*/
class ResolutionFactory
{
public:

  /**
   * @brief         Accesses the ResolutionFactory singleton
   * @return        Resolution factory
   */
  static ResolutionFactory & Access(void);

  /**
   * @brief         Destructor
   */
  ~ResolutionFactory();


  // dg03a start
  /**
   * @brief         Reset after a re-ipl
   *                Clear the resolution lists that need clearing on a re-ipl
   * @note          currently clears the threshold resolution list and the link
   *                resolution list
   */
  void Reset();

  /**
   * @brief         Returns resolution that callouts target. But it may or
                    may not gard it.
   * @param         PRDcallout  (see prdfCallouts.H)
   * @param         PRDpriority (see prdfCallouts.H)
   * @param         gard policy associated with target.
   * @return        Resolution &
   */
  Resolution & getCalloutGardResol( PRDcallout callout,
                                    PRDpriority p = PRDF::MRU_MED,
                                    GARD_POLICY i_gard = GARD );

  /**
   * @brief         Get a threshold Resolution
   * @param[in]     maskId      MaskId to set when threshold is reached
   * @param[in]     policy      policy during normal runtime
   * @param[in]     mfgPolicy   policy for manufactoring mode ( default is
   *                            threshold one,infinate interval )
   * @return        reference to a resolution
   * @post          appropriate Resolution created.
   * @note          the iv_thresholdResoltion FlyWeight is cleared by
   *                this->Reset()
   */
  MaskResolution & GetThresholdResolution(uint32_t maskId,
                    const ThresholdResolution::ThresholdPolicy& policy,
                    const ThresholdResolution::ThresholdPolicy& mfgPolicy);

  MaskResolution & GetThresholdResolution(uint32_t maskId,
                    const ThresholdResolution::ThresholdPolicy& policy);

  MaskResolution & GetThresholdResolution(uint32_t maskId);
  MaskResolution & GetThresholdResolution(uint32_t maskId,
                            const ThresholdResolution::ThresholdPolicy* policy);

  /**
   * @brief     Returns an instance of CalloutConnectedGard.
   * @param     i_targetType    Type of target  connected to i_source
   * @param     idx             index in GetConnected list to use
   * @param     i_priority      @see prdfCallouts.H
   * @param     i_altResolution resolution for failure scenarios
   * @param     i_peerConnType  Type of target which connects to peer
                                of i_targetType
   * @param     i_gardState     gard policy associated with callout target
   * @return    reference to a resolution
   * @note      This resolution callouts a connected target. There is an option
   *            to specify the gard policy for the callout target.
   */
  Resolution & getConnCalloutGardResol(
                                    TARGETING::TYPE i_targetType,
                                    uint32_t i_idx = 0,
                                    PRDpriority i_priority = MRU_MED,
                                    Resolution * i_altResolution = nullptr,
                                    TARGETING::TYPE i_peerConnType =
                                                    TARGETING::TYPE_NA,
                                    GARD_POLICY i_gardState = GARD );

  /**
   * @brief     GetAnalyzeConnectedResoltuion
   * @param[in] i_targetType type of unit that's connected to the source
   * @param[in] i_dx         index in GetConnected list to analyze
   * @return    reference to a resolution
   */
  Resolution & GetAnalyzeConnectedResolution( TARGETING::TYPE i_targetType,
                                             uint32_t i_idx =0xffffffff );
        // dg05a - end
  // dg06a - start
  /**
   * @brief     Returns object of PluginCallResolution
   * @param[in] i_function pointer to ExtensibleFunction
   * @return    reference to a resolution
   * @post      one instance with these params will exist
   * @note      This flyweight is cleared by this->Reset()
   */
  Resolution & GetPluginCallResolution( ExtensibleChipFunction * i_function );

  /**
   * @brief     Get a threshold signature resolution
   * @param[in] i_policy Reference to ThresholdPolicy struct
   * @return    reference to a resolution
   * @post      one instance with this policy will exist
   * @note      This flyweight is cleared by this->Reset()
   */
  Resolution & GetThresholdSigResolution( const ThresholdResolution::
                                            ThresholdPolicy& i_policy );


  /**
   * @brief     Get an EregResolution
   * @param[in] i_er    Error register
   * @return    reference to a resolution
   * @post      one instance with the param will exist
   * @note      the error register provided must remain in scope as long as the
   *            Resolution Factory
   * @note      This Flyweight is cleared by this->Reset()
   */
  Resolution & GetEregResolution(ErrorRegisterType & i_er);

  /**
   * @brief     Get a TryResolution
   * @param[in] i_tryRes    Resolution to try
   * @param[in] i_defaultRes    Resolution to use if the first one returns a
   *                            non-zero return code
   * @return    reference to a resolution
   * @post      one instance with these params will exist
   * @note      The resolutions provided must remain in scope as long as the
   *            Resolution Factory
   * @note      This Flyweight is cleared by this->Reset()
   */
  Resolution & GetTryResolution(Resolution &i_tryRes, Resolution & i_defaultRes);

  /**
   * @brief     Get a FlagResolution
   * @param[in] i_flag
   * @return    reference to a resolution
   * @post      only one instance of this object with this param will exist
   */
  Resolution & GetFlagResolution(ServiceDataCollector::Flag i_flag);

  /**
   * @brief     Get a DumpResolution
   * @param[in] iDumpRequestContent
   * @return    reference to a resolution
   * @post      only one instance of this obect with these paramaters will exist
   */
  Resolution & GetDumpResolution( hwTableContent iDumpRequestContent =
                                    CONTENT_HW );

  /**
   * @brief     Get a Capture Resolution
   * @param[in] i_group  The group to capture.
   * @return    reference to a resolution
   * @post      only one instance of this object with this param will exist
   */
  Resolution & GetCaptureResolution( int32_t i_group );

/**
   Link resolutions to form a single resolution performing the actions of them all
   <ul>
   <br><b>Parameters:  </b> Resolutions
   <br><b>Returns:     </b> Resolution &
   <br><b>Requirements:</b> Valid resolutions given
   <br><b>Promises:    </b> LinkResolutions(r1,r2...).Resolve();  ==
                            r1.Resolve(), r2.Resolve(), ...;
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Do not call this method from a static object
   <br><b>Notes:       </b> The iv_Links Flyweight is cleared by this->Reset()
   </ul><br>
   */
  Resolution & LinkResolutions(Resolution &r1, Resolution &r2);
  /**
   Link resolutions to form a single resolution performing the actions of them all
   <ul>
   <br><b>Parameters:  </b> Resolutions
   <br><b>Returns:     </b> Resolution &
   <br><b>Requirements:</b> Valid resolutions given
   <br><b>Promises:    </b> LinkResolutions(r1,r2...).Resolve();  ==
                            r1.Resolve(), r2.Resolve(), ...;
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Do not call this method from a static object
   </ul><br>
   */
  Resolution & LinkResolutions(Resolution &r1, Resolution &r2, Resolution &r3);
  /**
   Link resolutions to form a single resolution performing the actions of them all
   <ul>
   <br><b>Parameters:  </b> Resolutions
   <br><b>Returns:     </b> Resolution &
   <br><b>Requirements:</b> Valid resolutions given
   <br><b>Promises:    </b> LinkResolutions(r1,r2...).Resolve();  ==
                            r1.Resolve(), r2.Resolve(), ...;
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Do not call this method from a static object
   </ul><br>
   */
  Resolution & LinkResolutions(Resolution &r1, Resolution &r2, Resolution &r3,
                               Resolution &r4);
  /**
   Link resolutions to form a single resolution performing the actions of them all
   <ul>
   <br><b>Parameters:  </b> Resolutions
   <br><b>Returns:     </b> Resolution &
   <br><b>Requirements:</b> Valid resolutions given
   <br><b>Promises:    </b> LinkResolutions(r1,r2...).Resolve();  ==
                            r1.Resolve(), r2.Resolve(), ...;
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Do not call this method from a static object
   </ul><br>
   */
  Resolution & LinkResolutions(Resolution &r1, Resolution &r2, Resolution &r3,
                               Resolution &r4, Resolution &r5);

private:  // functions

  /**
   private CTOR
   <ul>
   <br><b>Requirements:</b> May only be called once
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ResolutionFactory() {}

  ResolutionFactory(const ResolutionFactory &f); // not allowed
  ResolutionFactory & operator=(const ResolutionFactory &f); // not allowed

public:
  /**
   Link resolutions together
   @author Douglas R. Gilbert
   @version V4R3
   */
  class ResolutionLink: public Resolution
  {
  public:
    ResolutionLink(): Resolution(), xlnk1(nullptr), xlnk2(nullptr) {}
    ResolutionLink(Resolution & r1, Resolution & r2)
      : Resolution(), xlnk1(&r1), xlnk2(&r2) {}
    ResolutionLink(const ResolutionLink & rl)
      : xlnk1(rl.xlnk1), xlnk2(rl.xlnk2) {}
    bool operator==(const ResolutionLink & r) const
    { return (xlnk1 == r.xlnk1 && xlnk2 == r.xlnk2); };
    bool operator<(const ResolutionLink & r) const
    {
        if (xlnk1 == r.xlnk1)
            return xlnk2 < r.xlnk2;
        return xlnk1 < r.xlnk1;
    };
    bool operator>=(const ResolutionLink & r) const
    {
        if (xlnk1 == r.xlnk1)
            return xlnk2 >= r.xlnk2;
        return xlnk1 >= r.xlnk1;
    };

    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & serviceData,
                            bool i_default = false);
  private: // data
    Resolution * xlnk1;
    Resolution * xlnk2;
  };
#ifdef FLYWEIGHT_PROFILING
/**
 * @brief       prints memory allocated for object residing in flyweight
 */
  void printStats();
#endif

private:  // Data

  typedef FlyWeightS< ResolutionLink, 50> ResolutionLinkFW;        // dg01a

  typedef FlyWeight< ThresholdResolution, 50 > ThresholdResolutionList;  // dg02a
  typedef FlyWeight< MaskResolution, 50 > MaskResolutionFW;           // dg02a

  typedef FlyWeight< AnalyzeConnected, 20 > AnalyzeCFW;          // dg05a
  typedef FlyWeight< PluginCallResolution, 10 > PluginCallFW;    // dg06a
  typedef FlyWeight< ThresholdSigResolution, 10 > ThresholdSigFW;    // dg06a
  typedef FlyWeight< EregResolution, 50 > EregResolutionFW;          // dg06a
  typedef FlyWeight< TryResolution, 20 > TryResolutionFW;            // dg06a
  typedef FlyWeight< FlagResolution, 5 > FlagResolutionFW;           // dg06a
  typedef FlyWeight< DumpResolution, 5 > DumpResolutionFW;           // dg06a
  typedef FlyWeight< CaptureResolution, 5> CaptureResolutionFW;  // pw01
  typedef FlyWeight< CalloutGardResolution, 50 > CalloutGardResolFW;
  typedef FlyWeight< CalloutConnectedGard, 25> CalloutConnectedGardResolFW;

  ResolutionLinkFW iv_Links;                        // dg01a

  ThresholdResolutionList iv_thresholdResolutions;  // dg02a
  MaskResolutionFW iv_maskResolutions;            // dg02a
  // dg01 - end
  AnalyzeCFW iv_analyzeConnected;              // dg05a
  PluginCallFW iv_pluginCallFW;                // dg06a
  ThresholdSigFW iv_thresholdSigFW;             // dg06a
  EregResolutionFW iv_eregResolutionFW;        // dg06a
  TryResolutionFW iv_tryResolutionFW;          // dg06a
  FlagResolutionFW iv_flagResolutionFW;        // dg06a
  DumpResolutionFW iv_dumpResolutionFW;        // dg06a
  CaptureResolutionFW iv_captureResolutionFW;  // pw01
  CalloutGardResolFW iv_calloutGardFW; ///<  stores CalloutGardResolution
  CalloutConnectedGardResolFW iv_connCalloutGardFW; ///< CalloutConnectedGard

};

inline
Resolution & ResolutionFactory::LinkResolutions(Resolution &r1,
                                                Resolution &r2,
                                                Resolution &r3)
{
  return LinkResolutions(LinkResolutions(r1,r2),r3);
}

inline
Resolution & ResolutionFactory::LinkResolutions(Resolution &r1,
                                                Resolution &r2,
                                                Resolution &r3,
                                                Resolution &r4)
{
  return LinkResolutions(LinkResolutions(r1,r2),LinkResolutions(r3,r4));
}

inline
Resolution & ResolutionFactory::LinkResolutions(Resolution &r1,
                                                Resolution &r2,
                                                Resolution &r3,
                                                Resolution &r4,
                                                Resolution &r5)
{
  return LinkResolutions(LinkResolutions(r1,r2),LinkResolutions(r3,r4,r5));
}

} // end namespace PRDF

#endif /* iipResolutionFactory_h */
