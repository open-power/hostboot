/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipMopRegisterAccess.h $ */
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

#ifndef iipMopRegisterAccess_h
#define iipMopRegisterAccess_h

// Class Specification *************************************************
//
// Class name:   MopRegisterAccess
// Parent class: None.
//
// Summary: This class provides access to hardware register via
//          a MOP routine.  A single pure virtual function Access()
//          is declared for this purpose.
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
//   void foo(MopRegisterAccess & mra)
//   {
//     BIT_STRING_BUFFER_CLASS bitString(80);  // 80 bits
//
//     mra.Access(bitString, READ);
//     ...
//
//   }
//
//
// End Class Specification *********************************************

// Includes
#if !defined(IIPCONST_H)
#include <iipconst.h>
#endif
#include <prdfPlatServices.H>

namespace PRDF
{
// Forward References
class BIT_STRING_CLASS;

class MopRegisterAccess
{
public:

  enum Operation
  {
    READ = 0,
    WRITE = 1
  };

  //  MopRegisterAccess(void);
  // Function Specification ********************************************
  //
  // Purpose:      Initialization
  // Parameters:   None.
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Notes:  This constructor is not declared.  This compiler generated
  //         default definition is sufficient.
  //
  // End Function Specification //////////////////////////////////////

  //  MopRegisterAccess(const MopRegisterAccess & scr);
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

  virtual ~MopRegisterAccess(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  N/A
  //
  // End Function Specification ****************************************

  //  MopRegisterAccess & operator=(const MopRegisterAccess & scr);
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
                       uint64_t registerId,
                       Operation operation) const = 0;
  // Function Specification ********************************************
  //
  // Purpose:      This function reads or writes the hardware according
  //               to the specified operation.
  // Parameters:   bs: Bit string to retrieve(for write) or store data
  //               (from read)
  //               registerId: SCR Address or scan offset
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
  //Get Ids and count
  virtual const TARGETING::TargetHandle_t * GetChipIds(int & count) const = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Access Chip Ids and # of chips to access
  // Parameters:   count: Var to return chip count of valid IDs
  // Returns:      ptr to Chip ids
  // Requirements: None
  // Promises:     None
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  //
  // End Function Specification ****************************************

  private:

  };

} // end namespace PRDF

#include <iipMopRegisterAccess.inl>

#endif
