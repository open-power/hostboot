/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdDumpResolution.h $ */
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
#include <iipResolution.h>

#ifndef __HOSTBOOT_MODULE

#include <hdctContent.H>

#endif

#include <prdfPlatServices.H>

namespace PRDF
{

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
   * @brief     Constructor
   * @param[in] iDumpRequestContent
   * @return    Non-SUCCESS in internal function fails, SUCCESS otherwise.
   */
  #ifdef __HOSTBOOT_MODULE
  DumpResolution(/*FIXME: hwTableContent iDumpRequestContent = CONTENT_HW, */)
  #else
  DumpResolution( hwTableContent iDumpRequestContent = CONTENT_HW )
    : ivDumpContent( iDumpRequestContent )
  #endif
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
   * @brief     updates  the dump flag in service data collector
   * @param[io] io_serviceData Reference to STEP_CODE_DATA_STRUCT
   * @return    Non-SUCCESS in internal function fails, SUCCESS otherwise.
   */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_serviceData );

#ifndef __HOSTBOOT_MODULE

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator == (const DumpResolution & r) const
  {
    return ( ivDumpContent  == r.ivDumpContent );
  }

#endif

private:  // functions
private:  // Data

  #ifndef __HOSTBOOT_MODULE
  hwTableContent ivDumpContent;
  #endif

};

} // end namespace PRDF

#endif /* xspprdDumpResolution_h */

