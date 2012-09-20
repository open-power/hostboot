/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/register/iipMopRegisterAccessScanComm.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

#ifndef iipMopRegisterAccessScanComm_h
#define iipMopRegisterAccessScanComm_h

// Class Specification *************************************************
//
// Class name:   MopRegisterAccessScanComm
// Parent class: MopRegisterAccess.
//
// Summary: This class provides access to hardware register data via
//          a MOP Scan Comm routine.
//
// Cardinality: 0
//
// Performance/Implementation:
//   Space Complexity: Constant
//   Time Complexity:  All member functions constant unless otherwise
//                     stated.
//
// Usage Examples:
//
//
//
// End Class Specification *********************************************

// Includes

#pragma interface

#ifndef iipMopRegisterAccess_h
#include <iipMopRegisterAccess.h>
#endif

// Forward References
class MopRegisterAccessScanComm : public MopRegisterAccess
{
public:

  // Function Specification ********************************************
  //
  // Purpose:      CTOR
  // Parameters:   None
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Note:         Multiple chip IDs are for chips that MOPs must
  //               access at the same time when performing a Scan
  //               Comm operation (ie STINGER & ARROW chips)
  //
  // End Function Specification //////////////////////////////////////

  //  MopRegisterAccessScanComm(const MopRegisterAccessScanComm & scr);
  // Function Specification ********************************************
  //
  // Purpose:      Copy
  // Parameters:   scr: Reference to instance to copy
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members will be copied (Deep copy).
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This constructor is not declared.  This compiler generated
  //         default definition is sufficient.
  //
  // End Function Specification ****************************************

  //   virtual ~MopRegisterAccessScanComm(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Notes:  This destructor is not declared.  This compiler generated
  //         default definition is sufficient.
  //
  // End Function Specification ****************************************

  //  MopRegisterAccessScanComm & operator=(const MopRegisterAccessScanComm & scr);
  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   d: Reference to instance to assign from
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members are assigned to
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This assingment operator is not declared.  The compiler
  //         generated default definition is sufficient.
  //
  // End Function Specification ****************************************

  virtual uint32_t Access(BIT_STRING_CLASS & bs,
                          uint32_t registerId,
                          Operation operation) const;
  // Function Specification ********************************************
  //
  // Purpose:      This function reads or writes the hardware according
  //               to the specified operation.
  // Parameters:   bs: Bit string to retrieve(for write) or store data
  //               (from read)
  //               registerId: ScanComm register address
  //               operation: Indicates either read or write operation
  // Returns:      Hardware OPs return code
  // Requirements: bs.Length() == long enough
  // Promises:     For read operation, bs is modified to reflect hardware
  //               register state
  // Exceptions:   None.
  // Concurrency:  Nonreentrant.
  // Note:         The first bs.Length() bits from the Hardware OPs read
  //               are set/reset in bs (from left to right)
  //               For a write, the first bs.Length() bits are written
  //               to the hardware register with right padded 0's if
  //               needed
  //
  // End Function Specification ****************************************


private: // DATA

};

//#include <iipMopRegisterAccessScanComm.inl>  // dg00

// Change Log **********************************************************
//
//  Flag  PTR/DCR#  Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  n/a   n/a       JST       09/08/95  Created.
//        v4r3      DGILBERT  05/19/96  Modified Access()
//  dg00  365764    dgilbert  04/19/02  remove inlines
//
// End Change Log ******************************************************


#endif
