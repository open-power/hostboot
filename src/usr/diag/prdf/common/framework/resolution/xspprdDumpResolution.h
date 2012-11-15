/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdDumpResolution.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2012              */
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

#ifndef xspprdDumpResolution_h
#define xspprdDumpResolution_h
// Class Description *************************************************
//
//  Name:  DumpResolution
//  Base class: Resolution
//
//  Description: Set dump information in Service Data Collector
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#ifndef __HOSTBOOT_MODULE

#include <hdctContent.H>

#endif

#include <prdfPlatServices.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class ServiceDataCollector;

/**
 Set dump information in the Service Data Collector
 @author Mike Kobler
 */
class DumpResolution : public Resolution
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameters:  </b> Optional: Processor handle value
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  #ifdef __HOSTBOOT_MODULE
  DumpResolution(/*FIXME: hwTableContent iDumpRequestContent = CONTENT_HW, */
                 TARGETING::TargetHandle_t i_pdumpHandle =NULL ) :
  #else
  DumpResolution(hwTableContent iDumpRequestContent = CONTENT_HW,
                 TARGETING::TargetHandle_t i_pdumpHandle =NULL ) :
  ivDumpContent(iDumpRequestContent),
  #endif
  iv_pdumpHandle(i_pdumpHandle)
  {}

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default sufficient
   </ul><br>
   */
  //  ~xspprdDumpResolution();

  /**
   Resolve by adding a the MRU callout to the service data collector
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> serviceData::GetMruList().GetCount()++
   serviceData::QueryDump() == this callout
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

#ifndef __HOSTBOOT_MODULE

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator==(const DumpResolution & r) const
  {
    return ( (ivDumpContent  == r.ivDumpContent) &&
             (iv_pdumpHandle == r.iv_pdumpHandle) );
  }

#endif

private:  // functions
private:  // Data

  #ifndef __HOSTBOOT_MODULE
  hwTableContent ivDumpContent;
  #endif

  TARGETING:: TargetHandle_t iv_pdumpHandle;
};


#endif /* xspprdDumpResolution_h */

