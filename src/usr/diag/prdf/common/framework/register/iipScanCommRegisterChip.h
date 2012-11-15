/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipScanCommRegisterChip.h $ */
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

#ifndef iipScanCommRegisterChip_h
#define iipScanCommRegisterChip_h

// Class Specification *************************************************
//
// Class name:   ScanCommRegisterChip
// Parent class: ScanCommRegisterAccess
//
// Summary: This class provides access to a Scan Comm Register
//          associated with a specific chip.
//
//          A pointer to a CHIP_CLASS is maintained.  The member
//          function GetChipSelectValues() is implemented to use the
//          CHIP_CLASS instance to return the values.
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Constant
//   Time Complexity:  All member functions constant unless otherwise
//                     stated.
//
// Usage Examples:
//
//   void foo(CHIP_CLASS * chipPtr, unsigned int registerAddress,
//     unsigned int bitLength)
//     {
//     ScanCommRegisterChip scr(chipPtr, registerAddress, bitLength);
//     scr.Read();
//     scr.Write();
//     }
//
// End Class Specification *********************************************

// Includes
#if !defined(iipScanCommRegisterAccess_h)
#include <iipScanCommRegisterAccess.h>
#endif

#if !defined(IIPBITS_H)
#include <iipbits.h>
#endif


// Forward References
class CHIP_CLASS;
class MopsRegisterAccess;

class ScanCommRegisterChip : public ScanCommRegisterAccess
{
public:

  ScanCommRegisterChip(uint64_t ra,
                       unsigned int bl,
                       MopRegisterAccess &hopsAccess);
  ScanCommRegisterChip() : ScanCommRegisterAccess(), xBitString((uint32_t)0) {}
  // Function Specification ********************************************
  //
  // Purpose:      Initialization (preferred Ctor)
  // Parameters:   chid: Chip Id of chip on which the hardware register resides
  //               ra: Scan com register address or Register Id
  //               bl: Number of bits in register
  //               hopsAccess: object to access Hardware Ops
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized
  // Exceptions:   None.
  // Concurrency:  N/A
  //
  // End Function Specification //////////////////////////////////////


  //ScanCommRegisterChip(const ScanCommRegisterChip & scr);
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

  //virtual ~ScanCommRegisterChip(void);
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

  //  ScanCommRegisterChip & operator=(const ScanCommRegisterChip & scr);
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

//  virtual const uint32_t * GetChipSelectValues(unsigned int & chipSelectCount) const;
  // Function Specification ********************************************
  //
  // Purpose:      This function returns the chip select values.
  // Parameters:   chipSelectCount: Number of chip select values in
  //                                returned array
  // Returns:      Pointer to an array of chip select values
  // Requirements: None.
  // Promises:     Parameter chipSelectCount is modified.
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  // Notes:  If the chipPtr is NULL, then the count will be zero and
  //         NULL is returned.
  //
  // End Function Specification ****************************************

  virtual const BIT_STRING_CLASS * GetBitString(ATTENTION_TYPE i_type = PRDF::INVALID_ATTENTION_TYPE) const
  { return &xBitString; }
  // Function Specification ********************************************
  //
  // Purpose:      Access the bit string
  // Parameters:   None
  // Returns:      the bit string
  // Requirements: none
  // Promises:     a bit string
  // Exceptions:   None.
  // Notes:
  //
  // End Function Specification ****************************************

  virtual void SetBitString(const BIT_STRING_CLASS * bs);
  // Function Specification ********************************************
  //
  // Purpose:      Modify the internal bit string
  // Parameters:   a Bit string
  // Returns:      Nothing
  // Requirements: none
  // Promises:     Internal bit string == *bs for first len bits where
  //               len is the smaller of the two lengths
  // Exceptions:   None.
  // Notes:
  //
  // End Function Specification ****************************************

protected: // Functions

  virtual BIT_STRING_CLASS & AccessBitString(void) { return(xBitString); }
  // Function Specification ********************************************
  //
  // Purpose:      Get non-cost referece to bit string
  // Parameters:   None.
  // Returns:      BIT_STRING_CLASS &
  // Requirements: none.
  // Promises:     Direct access to the Bit string
  // Exceptions:   None
  // Notes:
  //
  // End Function Specification ****************************************


private: // functions

  friend class CaptureData;

private: // Data

//  CHIP_CLASS * chipPtr;
  BIT_STRING_BUFFER_CLASS  xBitString;
//  MopRegisterAccessScanCommSingle  xHopsAccess;

};

// Change Log **********************************************************
//
//  Flag  PTR/DCR#  Userid    Date      Description
//  ----  --------  --------  --------  -----------
//  n/a   n/a       JST       04/18/95  Created.
//        D49127.7  DGILBERT  09/20/96  Added xBitString, Get/SetBitString()
//                                      AccessBitString()
//                  DGILBERT  05/27/97  V4R3 changes
//                  dgilbert  10/02/02  fips changes
//
// End Change Log ******************************************************


#endif
