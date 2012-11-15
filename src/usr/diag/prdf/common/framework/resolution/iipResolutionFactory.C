/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolutionFactory.C $ */
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

using namespace PRDF;

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
  if ( !PRDF::PlatServices::mfgMode() )
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
  if ( !PRDF::PlatServices::mfgMode() &&
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
  if ( !PRDF::PlatServices::mfgMode() )
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
                                    TARGETING::TargetHandle_t  i_psourceHandle,
                                    TARGETING::TYPE i_targetType,
                                    uint32_t i_idx,
                                    PRDpriority i_priority,
                                    Resolution * i_altResolution )
{
    prdfCalloutConnected key( i_psourceHandle,
                              i_targetType,
                              i_idx,
                              i_priority,
                              i_altResolution );

    return iv_connectedCallouts.get(key);
}

Resolution & ResolutionFactory::GetAnalyzeConnectedResolution(
                                    TARGETING::TargetHandle_t  i_psourceHandle,
                                    TARGETING::TYPE i_targetType,
                                    uint32_t i_idx )
{
    PrdfAnalyzeConnected key( i_psourceHandle, i_targetType, i_idx );

    return iv_analyzeConnected.get(key);
}

Resolution & ResolutionFactory::GetPluginCallResolution(
        PrdfExtensibleChip * i_chip, PrdfExtensibleChipFunction * i_function)
{
    return iv_pluginCallFW.get(PrdfPluginCallResolution(i_chip,i_function));
}

Resolution & ResolutionFactory::GetThresholdSigResolution(
                        const ThresholdResolution::ThresholdPolicy & policy )
{
    return iv_thresholdSigFW.get(ThresholdSigResolution(policy));
}

Resolution & ResolutionFactory::GetEregResolution(ErrorRegisterType & er)
{
    return iv_eregResolutionFW.get(EregResolution(er));
}

Resolution & ResolutionFactory::GetTryResolution( Resolution & tryRes,
                                                  Resolution & defaultRes )
{
    return iv_tryResolutionFW.get(TryResolution(tryRes,defaultRes));
}

Resolution & ResolutionFactory::GetFlagResolution(ServiceDataCollector::Flag flag)
{
    return iv_flagResolutionFW.get(FlagResolution(flag));
}

#ifdef __HOSTBOOT_MODULE
Resolution & ResolutionFactory::GetDumpResolution(
                                    /* FIXME: hwTableContent iDumpRequestContent, */
                                    TARGETING::TargetHandle_t i_pDumpHandle )
{
    return iv_dumpResolutionFW.get(DumpResolution(/*FIXME: iDumpRequestContent,*/ i_pDumpHandle));
}
#else
Resolution & ResolutionFactory::GetDumpResolution(
                                    hwTableContent iDumpRequestContent,
                                    TARGETING::TargetHandle_t i_pDumpHandle )
{
    return iv_dumpResolutionFW.get(DumpResolution(iDumpRequestContent, i_pDumpHandle));
}
#endif

Resolution & ResolutionFactory::GetGardResolution(GardResolution::ErrorType et)
{
    return iv_gardResolutionFW.get(GardResolution(et));
}

Resolution & ResolutionFactory::GetCaptureResolution
    (PrdfExtensibleChip * i_chip,
     uint32_t i_group)
{
    return iv_captureResolutionFW.get(PrdfCaptureResolution(i_chip,i_group));
}

Resolution & ResolutionFactory::GetClockResolution(
                                    TARGETING::TargetHandle_t i_pClockHandle,
                                    TARGETING::TYPE i_targetType )
{
    return iv_clockResolutionFW.get( PrdfClockResolution(i_pClockHandle,
                                                         i_targetType) );
}

void ResolutionFactory::Reset()
{
  PRDF_INF( "ResolutionFactory.Reset()" );

  iv_thresholdResolutions.clear();
  iv_Links.clear(); // we must clear this because it could have links to Thresholds
  iv_pluginCallFW.clear();
  iv_thresholdSigFW.clear();
  iv_eregResolutionFW.clear();
  iv_tryResolutionFW.clear();
  iv_captureResolutionFW.clear(); //dgxx
  iv_connectedCallouts.clear(); // Clear because the "alt resolution" could have be a link or other cleared resolution.
  iv_clockResolutionFW.clear(); //jl01a

}
// dg03a end
// Change Log *************************************************************************************
//
//  Flag Reason    Vers Date     Coder    Description
//  ---- --------- ---- -------- -------- ---------------------------------------------------------
//                      02/28/97 DGILBERT Initial Creation
//       D49274.11 v4r5 01/20/99 SERAFIN  Increased MAX_CALLOUT_RESOLUTIONS and MAX_LINKS
//       D49420.1  v5r2 07/17/00 mkobler  Add interface which uses ChipEnums
//       d49420.2  v5r2 09/20/00 dgilbert increase link vector size
//       d49420.7  v5r2 11/10/00 dgilbert move GetCalloutResolution(CHIP_ID...)
//                                        to xspprdCondorOnly.C
//       d49420.7  v5r2 11/20/00 mkobler  change default list/link size
//       d49420.10 v5r2 01/16/00 mkobler  change default callout list size
//  dg00 p4907689  v5r2 02/22/01 dgilbert link/list size += 1000
//                 csp  07/11/01 dgilbert rewrite to solve size problem
//  dg01           fips 08/09/02 dgilbert rewrite using FlyWeight template
//  dg02 400647    fips 03/24/03 dgilbert add GetThresholdResolution()
//  dg04 493306    235  03/01/05 dgilbert Add prdfCalloutConnected
//       497866    235  03/29/05 dgilbert add idx & priority to prdfCalloutConnected
//  dg05 498293    310  04/06/05 dgilbert add analyzeConnected
//  pw01 F527129   f300 10/31/05 iawillia Move inlined code to .C so it compiles.
//  ecdf F550548   f300 05/04/06 iawillia eClipz DUMP flags support.
//  dg05           f310 05/18/07 dgilbert Clear iv_captureResolutoinFW to prevent memory leak.
// End Change Log *********************************************************************************
