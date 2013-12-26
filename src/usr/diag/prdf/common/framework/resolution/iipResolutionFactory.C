/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolutionFactory.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2014              */
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

/**
 @file iipResolutionFactory.h
 @brief ResolutionFactory definition
 */
// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipResolutionFactory_C

#include <iipResolutionFactory.h>
#include <prdfFlyWeight.C>            // dg01
#include <prdfFlyWeightS.C>
#include <prdfPlatServices.H>

#undef iipResolutionFactory_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  class static Variables
//----------------------------------------------------------------------

// dg01 - delete 4 lines of code
// pw01 - This stuff doesn't appear to be needed anymore.
/*class CalloutFW;                      // dg01
class ResolutionLinkFW;             // dg01
class ThresholdResolutionList;    // dg02
class MaskResolutionFW;             // dg02
class ConnectedFW;            // dg04a
class AnalyzeCFW;              // dg05a
class PluginCallFW;                // dg06a
class ThresholdSigFW;             // dg06a
class EregResolutionFW;        // dg06a
class TryResolutionFW;          // dg06a
class FlagResolutionFW;        // dg06a
class DumpResolutionFW;        // dg06a
class GardResolutionFW;        // dg06a
*/

namespace PRDF
{

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

ResolutionFactory & ResolutionFactory::Access(void)
{
  static ResolutionFactory rf;
  return(rf);
}

//---------------------------------------------------------------------

ResolutionFactory::~ResolutionFactory()
{
}

// ---------------------------------------------------------------------

Resolution & ResolutionFactory::GetCalloutResolution(PRDcallout callout,
                                                     PRDpriority p)
{
  // search for existing callout
  // dg01 start
  CalloutResolution key(callout,p);
  return iv_Callouts.get(key);
  // dg01 end
}

// ----------------------------------------------------------------------

Resolution & ResolutionFactory::LinkResolutions(Resolution & r1,
                                                Resolution & r2)
{
  // dg01 start
  // search for existing link
  ResolutionFactory::ResolutionLink key(r1,r2);
  return iv_Links.get(key);
  // dg01 end
}

// ---------------------------------------------------------------------

int32_t ResolutionFactory::ResolutionLink::Resolve(
                                           STEP_CODE_DATA_STRUCT & serviceData )
{
  int32_t rc = xlnk1->Resolve(serviceData);
  if (rc == SUCCESS) rc = xlnk2->Resolve(serviceData);
  return rc;
}

// dg02a - start
MaskResolution & ResolutionFactory::GetThresholdResolution( uint32_t maskId,
                        const ThresholdResolution::ThresholdPolicy & policy,
                        const ThresholdResolution::ThresholdPolicy & mfgPolicy )
{
  MaskResolution * r = NULL;
  if ( !PlatServices::mfgMode() )
  {
    r = &iv_thresholdResolutions.get(ThresholdResolution(maskId,policy));
  }
  else
  {
    r = &iv_thresholdResolutions.get(ThresholdResolution(maskId,mfgPolicy));
  }
  return *r;
}

MaskResolution & ResolutionFactory::GetThresholdResolution( uint32_t maskId,
                        const ThresholdResolution::ThresholdPolicy & policy )
{
  MaskResolution * r = NULL;
  if ( !PlatServices::mfgMode() &&
       !(policy == ThresholdResolution::cv_mnfgDefault) )
  {
    r = &iv_thresholdResolutions.get(ThresholdResolution(maskId,policy));
  }
  else
  {
    r = &iv_maskResolutions.get(MaskResolution(maskId));
  }

  return *r;
}

MaskResolution & ResolutionFactory::GetThresholdResolution(uint32_t maskId)
{
  MaskResolution * r = NULL;
  if ( !PlatServices::mfgMode() )
  {
    r = &iv_thresholdResolutions.get(
                    ThresholdResolution(maskId,
                                        ThresholdResolution::cv_fieldDefault) );
  }
  else
  {
    r = &iv_maskResolutions.get(MaskResolution(maskId));
  }

  return *r;
}

Resolution & ResolutionFactory::GetConnectedCalloutResolution(
                                    TARGETING::TYPE i_targetType,
                                    uint32_t i_idx,
                                    PRDpriority i_priority,
                                    Resolution * i_altResolution,
                                    TARGETING::TYPE i_peerConnType )
{
    CalloutConnected key(   i_targetType,
                            i_idx,
                            i_priority,
                            i_altResolution,
                            i_peerConnType );

    return iv_connectedCallouts.get(key);
}

Resolution & ResolutionFactory::GetAnalyzeConnectedResolution(
                                    TARGETING::TYPE i_targetType,
                                    uint32_t i_idx )
{
    AnalyzeConnected key( i_targetType, i_idx );

    return iv_analyzeConnected.get(key);
}

Resolution & ResolutionFactory::GetPluginCallResolution(
                                    ExtensibleChipFunction * i_function )
{
    return iv_pluginCallFW.get( PluginCallResolution( i_function ) );
}

Resolution & ResolutionFactory::GetThresholdSigResolution(
                        const ThresholdResolution::ThresholdPolicy & policy )
{
    return iv_thresholdSigFW.get(ThresholdSigResolution(policy));
}

Resolution & ResolutionFactory::GetEregResolution(ErrorRegisterType & i_er)
{
    return iv_eregResolutionFW.get(EregResolution(i_er));
}

Resolution & ResolutionFactory::GetTryResolution( Resolution & i_tryRes,
                                                  Resolution & i_defaultRes )
{
    return iv_tryResolutionFW.get(TryResolution(i_tryRes,i_defaultRes));
}

Resolution & ResolutionFactory::GetFlagResolution(
                                    ServiceDataCollector::Flag i_flag )
{
    return iv_flagResolutionFW.get( FlagResolution( i_flag ) );
}

Resolution & ResolutionFactory::GetDumpResolution(
                                    hwTableContent iDumpRequestContent )
{
    return iv_dumpResolutionFW.get(DumpResolution( iDumpRequestContent ) );
}

Resolution & ResolutionFactory::GetGardResolution(GardAction::ErrorType et)
{
    return iv_gardResolutionFW.get(GardResolution(et));
}

Resolution & ResolutionFactory::GetCaptureResolution( int32_t i_group )
{
    return iv_captureResolutionFW.get( CaptureResolution( i_group ) );
}

Resolution & ResolutionFactory::GetClockResolution(
                                    TARGETING::TargetHandle_t i_pClockHandle,
                                    TARGETING::TYPE i_targetType )
{
    return iv_clockResolutionFW.get( ClockResolution( i_pClockHandle,
                                                      i_targetType ) );
}

void ResolutionFactory::Reset()
{
  PRDF_INF( "ResolutionFactory.Reset()" );

  iv_thresholdResolutions.clear();
  // we must clear this because it could have links to Thresholds
  iv_Links.clear();
  iv_pluginCallFW.clear();
  iv_thresholdSigFW.clear();
  iv_eregResolutionFW.clear();
  iv_tryResolutionFW.clear();
  iv_captureResolutionFW.clear();
  /*Clear because the "alt resolution" could have be a link or other cleared
  resolution.*/
  iv_connectedCallouts.clear();
  iv_clockResolutionFW.clear();

}

#ifdef FLYWEIGHT_PROFILING

void ResolutionFactory::printStats()
{
    PRDF_TRAC("Callout");
    iv_Callouts.printStats( );
    PRDF_TRAC("Link Resolution");
    iv_Links.printStats( );
    PRDF_TRAC("ThresholdResolutionList");
    iv_thresholdResolutions.printStats( );
    PRDF_TRAC("MaskResolution");
    iv_maskResolutions.printStats( );
    PRDF_TRAC("ConnectedCallout");
    iv_connectedCallouts.printStats( );
    PRDF_TRAC("AnalyzeConnectedCallout");
    iv_analyzeConnected.printStats( );
    PRDF_TRAC("pluginCallFW");
    iv_pluginCallFW.printStats( );
    PRDF_TRAC("Threshhold");
    iv_thresholdSigFW.printStats( );
    PRDF_TRAC("EregResolution");
    iv_eregResolutionFW.printStats( );
    PRDF_TRAC("TryResolution");
    iv_tryResolutionFW.printStats( );
    PRDF_TRAC("FlagResolution");
    iv_flagResolutionFW.printStats( );
    PRDF_TRAC("dumpResolution");
    iv_dumpResolutionFW.printStats( );
    PRDF_TRAC("gardResolution");
    iv_gardResolutionFW.printStats( );
    PRDF_TRAC("captureResolution");
    iv_captureResolutionFW.printStats( );
    PRDF_TRAC("clockResolution");
    iv_clockResolutionFW.printStats( );

}
#endif
} // end namespace PRDF

