/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdGardResolution.h $ */
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

#ifndef xspprdGardResolution_h
#define xspprdGardResolution_h

// Class Description *************************************************
//
//  Name:  GardResolution
//  Base class: Resolution
//
//  Description: Set the error type for the failure (determines whether
//               Gard will be called)
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipResolution.h>
#include <prdfGardType.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
 Callout a mru and mark it for Gard (deallocation)
 @author Doug Gilbert
 */
class GardResolution : public Resolution
{
public:

  /**
   * @brief     Constructor
   * @param[in] i_et  error type
   */
  GardResolution( GardAction::ErrorType i_et = GardAction::NoGard )
        : xErrorType( i_et )
  { }

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
  //  ~xspprdGardResolution();

 /**
  * @brief      gard resolution operation
  * @param[io]  io_serviceData   Reference to STEP_CODE_DATA_STRUCT
  * @return     SUCCESS
  */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_serviceData );

  bool operator==(const GardResolution & r) const
  {
    return (xErrorType == r.xErrorType);
  }

private:  // functions
private:  // Data

  GardAction::ErrorType xErrorType;

};

} // end namespace PRDF

#endif /* xspprdGardResolution_h */

