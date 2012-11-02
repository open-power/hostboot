/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolutionFactory.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2012              */
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
//    FinalResolution & fr = resolutionPool.GetCalloutResolution(EAGLE0_HIGH);
//
//
// End Class Description *********************************************

//#include <xspprdIfCondor.h>     // #define CSP_CONDOR

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(IIPCONST_H)
#include <iipconst.h>
#endif

#if !defined(PRDFFLYWEIGHT_H)                                // dg01
#include <prdfFlyWeight.H>                                   // dg01
#include <prdfFlyWeightS.H>
#endif                                                       // dg01

#if !defined(iipCalloutResolution_h)
#include <iipCalloutResolution.h>
#endif

#if !defined(PRDFTHRESHOLDRESOLUTIONS_H)                    // dg02a
#include <prdfThresholdResolutions.H>                       // dg02a
#endif                                                      // dg02a

#include <prdfCalloutConnected.H>                           // dg04a
#include <prdfAnalyzeConnected.H>                           // dg05a
#include <prdfPluginCallResolution.H>                       // dg06a
#include <iipEregResolution.h>                              // dg06a
#include <xspprdTryResolution.h>                            // dg06a
#include <xspprdFlagResolution.h>                           // dg06a
#include <xspprdDumpResolution.h>                           // dg06a
#include <xspprdGardResolution.h>                           // dg06a
#include <prdfCaptureResolution.H>                            // pw01
#include <prdfClockResolution.H>                            // jl01a

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
   Access the ResolutionFactory singleton
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> Resolution factory
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Object created if it does not already exist
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  static ResolutionFactory & Access(void);

  /**
   DTOR
   <ul>
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Resources released
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ~ResolutionFactory();


  // dg03a start
  /**
   Reset after a re-ipl
   Clear the resolution lists that need clearing on a re-ipl
   @note currently clears the threshold resolution list and the link resolution list
   */
  void Reset();
  // dg03a end

  /**
   Get a resolution that makes a callout
   <ul>
   <br><b>Parameter:   </b> PRDcallout  (see prdfCallouts.H)
   <br><b>Parameter:   </b> PRDpriority (see prdfCallouts.H)
   <br><b>Returns:     </b> Resolution &
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> If a resolution does not exist for this MruCallout
                            then one is created.
   <br><b>Exceptions:  </b> None.
   <br><b>Note:        </b> Regatta CSP use only
   <br><b>Note:        </b> Do not call this method from a static object
   </ul><br>
   */
  Resolution & GetCalloutResolution( PRDcallout callout,
                                     PRDpriority p = PRDF::MRU_MED);

  /**
   Get a threshold Resolution
   @param Mask id to set when threshold is reached
   @param policy (theshold value & time interval) during normal runtime (default is ???)
   @param mfgPolicy for manufactoring mode  (default is threshold one, infinate interval)
   @return reference to a resolution
   @pre None
   @post appropriate Resolution created.
   @note the iv_thresholdResoltion FlyWeight is cleared by this->Reset()
   */
  MaskResolution & GetThresholdResolution(uint32_t maskId,
                                      const ThresholdResolution::ThresholdPolicy& policy,
                                      const ThresholdResolution::ThresholdPolicy& mfgPolicy);

  MaskResolution & GetThresholdResolution(uint32_t maskId,
                                      const ThresholdResolution::ThresholdPolicy& policy);

  MaskResolution & GetThresholdResolution(uint32_t maskId);
  MaskResolution & GetThresholdResolution(uint32_t maskId,
                                      const ThresholdResolution::ThresholdPolicy* policy);

  // dg04a - start
  /**
   GetConnectedCalloutResolution
   @param       i_psourceHandle         handle of connection source
   @param       i_targetType            Type of target  connected to i_source
   @param       idx                     index in GetConnected list to use
   @param       i_priority              @see prdfCallouts.H
   @param       i_altResolution         to use if the connection does not exist, is not functional, or is invalid.
                                        If NULL than the connection source is called-out
   @note Don't use this to callout clocks - use prdfClockResolution
   */
  Resolution & GetConnectedCalloutResolution(TARGETING::TargetHandle_t i_psourceHandle,
                                             TARGETING::TYPE i_targetType,
                                             uint32_t i_idx = 0,
                                             PRDpriority i_priority = MRU_MED,
                                             Resolution * i_altResolution = NULL);
  // dg04a - end

  // dg05a - start
  /**
   * GetAnalyzeConnectedResoltuion
   * @param     i_psourceHandle             handle of connection source
   * @param     i_targetType                type of  desired unit that's connected to the source
   * @param     i_dx                        index in GetConnected list to analyze
   */
  Resolution & GetAnalyzeConnectedResolution(TARGETING::TargetHandle_t i_psourceHandle,
                                             TARGETING::TYPE i_targetType,
                                             uint32_t i_idx =0xffffffff );
        // dg05a - end
  // dg06a - start
  /**
   * Get a PluginCallResolution
   * @param ptr to ExtensibleChip
   * @param ptr to ExtensibleFunction
   * @post one instance with these params will exist
   * @This flyweight is cleared by this->Reset()
   */
  Resolution & GetPluginCallResolution(ExtensibleChip * i_chip,
                                       ExtensibleChipFunction * i_function);

  /**
   * Get a threshold signature resolution
   * @param policy (either enum or uint32_t)
   * @post one instance with this policy will exist
   * @this flyweight is cleared by this->Reset()
   */
  Resolution & GetThresholdSigResolution(const ThresholdResolution::ThresholdPolicy& policy);


  /**
   * Get an EregResolution
   * @param Error register
   * @post one instance with the param will exist
   * @note the error register provided must remain in scope as long as the Resolution Factory
   * @note This Flyweight is cleared by this->Reset()
   */
  Resolution & GetEregResolution(ErrorRegisterType & er);

  /**
   * Get a TryResolution
   * @param Resolution to try
   * @param Resolution to use if the first one returns a non-zero return code
   * @post one instance with these params will exist
   * @note The resolutions provided mus remain in scope as long as the Resolution Factory
   * @note This Flyweight is cleared by this->Reset()
   */
  Resolution & GetTryResolution(Resolution &tryRes, Resolution & defaultRes);

  /**
   * Get a FlagResolution
   * @param servicedatacollector::flag
   * @post only one instance of this object with this param will exist
   */
  Resolution & GetFlagResolution(ServiceDataCollector::Flag flag);

  /**
   * Get a DumpResolution
   * @param dump flags
   * @post only one instance of this obect with these paramaters will exist
   */
  #ifdef __HOSTBOOT_MODULE
  Resolution & GetDumpResolution(/* FIXME: hwTableContent iDumpRequestContent = CONTENT_HW,*/
                                 TARGETING::TargetHandle_t i_pDumpHandle = NULL);
  #else
  Resolution & GetDumpResolution(hwTableContent iDumpRequestContent = CONTENT_HW,
                                 TARGETING::TargetHandle_t i_pDumpHandle = NULL);
  #endif

  /**
   * Get a Gard Resolution
   * @param The Gard Flag
   * @post only one instance of this object with this param will exist
   */
  Resolution & GetGardResolution(GardResolution::ErrorType et);

  // dg06a - end

  /**
   * Get a Capture Resolution
   * @param i_chip - The extensible chip to capture from.
   * @param i_group - The group to capture.
   * @post only one instance of this object with this param will exist
   */
  Resolution & GetCaptureResolution(ExtensibleChip * i_chip,
                                    uint32_t i_group);

    /**
   * Get a ClockResolution
   * @param
   * @post only one instance of this obect with these paramaters will exist
   */
  // FIXME: Need support for clock targets
  // FIXME: Need support for clock targets types
  Resolution & GetClockResolution(TARGETING::TargetHandle_t i_pClockHandle =NULL,
                                  TARGETING::TYPE i_targetType = TARGETING::TYPE_PROC);                                                                                        //should be repla
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
    ResolutionLink(): Resolution(), xlnk1(NULL), xlnk2(NULL) {}
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

    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & serviceData);
  private: // data
    Resolution * xlnk1;
    Resolution * xlnk2;
  };

private:  // Data

  // dg01 - start
  typedef FlyWeight< CalloutResolution, 50> CalloutFW;             // dg01a
  typedef FlyWeightS< ResolutionLink, 50> ResolutionLinkFW;        // dg01a

  typedef FlyWeight< ThresholdResolution, 50 > ThresholdResolutionList;  // dg02a
  typedef FlyWeight< MaskResolution, 50 > MaskResolutionFW;           // dg02a

  typedef FlyWeight< CalloutConnected, 25 > ConnectedFW;         // dg04a
  typedef FlyWeight< AnalyzeConnected, 20 > AnalyzeCFW;          // dg05a
  typedef FlyWeight< PluginCallResolution, 10 > PluginCallFW;    // dg06a
  typedef FlyWeight< ThresholdSigResolution, 10 > ThresholdSigFW;    // dg06a
  typedef FlyWeight< EregResolution, 50 > EregResolutionFW;          // dg06a
  typedef FlyWeight< TryResolution, 20 > TryResolutionFW;            // dg06a
  typedef FlyWeight< FlagResolution, 5 > FlagResolutionFW;           // dg06a
  typedef FlyWeight< DumpResolution, 5 > DumpResolutionFW;           // dg06a
  typedef FlyWeight< GardResolution, 5 > GardResolutionFW;           // dg06a
  typedef FlyWeight< CaptureResolution, 5> CaptureResolutionFW;  // pw01
  typedef FlyWeight< ClockResolution, 8 > ClockResolutionFW;         // jl01a

  CalloutFW iv_Callouts;                            // dg01a
  ResolutionLinkFW iv_Links;                        // dg01a

  ThresholdResolutionList iv_thresholdResolutions;  // dg02a
  MaskResolutionFW iv_maskResolutions;            // dg02a
  // dg01 - end
  ConnectedFW iv_connectedCallouts;            // dg04a
  AnalyzeCFW iv_analyzeConnected;              // dg05a
  PluginCallFW iv_pluginCallFW;                // dg06a
  ThresholdSigFW iv_thresholdSigFW;             // dg06a
  EregResolutionFW iv_eregResolutionFW;        // dg06a
  TryResolutionFW iv_tryResolutionFW;          // dg06a
  FlagResolutionFW iv_flagResolutionFW;        // dg06a
  DumpResolutionFW iv_dumpResolutionFW;        // dg06a
  GardResolutionFW iv_gardResolutionFW;        // dg06a
  CaptureResolutionFW iv_captureResolutionFW;  // pw01
  ClockResolutionFW iv_clockResolutionFW;      // jl01a

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
