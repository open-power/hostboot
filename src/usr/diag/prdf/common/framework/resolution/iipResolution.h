/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolution.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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

#ifndef iipResolution_h
#define iipResolution_h

// Class Description *************************************************
//
//  Name:  Resolution
//  Base class: None
//
//  Description:  This module contains the Processor Runtime
//                  Diagnostics Resolution class declaration.
//                Resolution provides a mechansim to resolve a
//                hardware error and provide service data
//
//  Usage:  Abstract base class
//
//  int32_t foo(STEP_CODE_DATA_STRUCT &serviceData,
//             ResolutionMap &map)
//  {
//    Resolution &r = map.LookUp(BIT_LIST_STRING_21);
//    int32_t rc = r.Resolve(serviceData);
//    return(rc);
//  }
//
// End Class Description *********************************************
/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(PRDF_TYPES_H)
#include <prdf_types.h>
#endif

#if !defined(IIPSTEP_H)
#include <iipstep.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class CalloutResolution;    //dg00


class Resolution
{
public:

  /**
   Destructor
   @pre None
   @post None
   @note This destructor does nothing.  This definitions
         would have the same effect as the compiler generated
         default destructor.  It is declared virtual so that
         derived classes will be destructed properly.
   */
  virtual ~Resolution();

  /**
   Resolve the service data for this error syndrome
   @pre None
   @post service data is complete
   @return SUCCESS | non-zero
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & data) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data for a specific error bit (Pure Virtual)
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     if rc = SUCCESS then data filled with apropriate service data
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************


  // Copy ctor   - compiler default is sufficient
  // Assignment  - compiler default is sufficient

  // dg00 start
  /**
   Comparison
   <ul>
   <br><b>Parameters:  </b> A Resolution
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Each derived class that supports comparison must be listed
   here.
   </ul><br>
   */
  virtual bool operator==(const Resolution & r) const
  { return false; }  // default
  virtual bool operator==(const CalloutResolution & r) const
  { return false; }
  // dg00 end

protected:

  Resolution() {}
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   Pointer to charater string bit list encoding (opt)
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

private:  // functions
private:  // Data


};

} // end namespace PRDF

#endif /* iipResolution_h */

