/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdDumpResolution.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2013              */
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

// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define xspprdDumpResolution_C

#include <xspprdDumpResolution.h>
#include <iipServiceDataCollector.h>

#undef xspprdDumpResolution_C

namespace PRDF
{

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

int32_t DumpResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
  uint32_t rc = SUCCESS;

  #ifdef __HOSTBOOT_MODULE
  error.service_data->SetDump(/*FIXME: ivDumpContent,*/ iv_pdumpHandle);
  #else
  error.service_data->SetDump(ivDumpContent,iv_pdumpHandle);
  #endif

  return rc;
}

} // end namespace PRDF
