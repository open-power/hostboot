/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipScanCommRegisterAccess.h $ */
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

#ifndef iipScanCommRegisterAccess_h
#define iipScanCommRegisterAccess_h

// Class Specification *************************************************
//
// Class name:   ScanCommRegisterAccess
// Parent class: SCAN_COMM_REGISTER_CLASS
//
// Summary: This class provides access to the Scan Comm Register
//          physical hardware.  The member functions Read() and Write()
//          both call the common function Access().  Access() is
//          implemented to use a MopRegisterAccessScanComm instance to
//          access the hardware.
//
//          This class contains an instance of the CcSynch class.  This
//          data member is used to ensure that the Read() function will
//          only call the Access() function once for any given synch
//          value.  An external thread must ensure that the synch value
//          is advanced at appropriate times.  AN eclosed class id is
//          used to ensure that the class template CcSynch
//          specialization is unique. See the specification of the
//          CcSynch class for more details
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
//   void foo(ScanCommRegisterAccess & scr)
//     {
//     scr.Read();
//     scr.Write();
//     }
//
//
// End Class Specification *********************************************


// Includes
#ifndef IIPSCR_H
#include <iipscr.h>
#endif

#ifndef CcSynch_h
#include <CcSynch.h>
#endif

#if !defined(IIPCONST_H)
#include <iipconst.h>
#endif

#ifndef iipMopRegisterAccess_h
#include <iipMopRegisterAccess.h>
#endif

namespace PRDF
{

// // Forward References
// #ifdef _USE_IOSTREAMS_
// class ostream;
// #endif

class ScanCommRegisterAccess : public SCAN_COMM_REGISTER_CLASS
{
public:

  struct id {};
  typedef CcSynch<uint16_t, id> SynchType;

   /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> ar: Scan Comm Register address.
   <br><b>Parameter:   </b> mopsAccess object
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Heap memory may be allocated
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ScanCommRegisterAccess(uint64_t ra, MopRegisterAccess &hopsAccessor);

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
  //  ScanCommRegisterAccess(const ScanCommRegisterAccess & scr);

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
  // virtual ~ScanCommRegisterAccess(void);

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
  //  ScanCommRegisterAccess & operator=(const ScanCommRegisterAccess & scr);

  //  virtual const uint32_t * GetChipSelectValues(       retired
  //    unsigned int & chipSelectCount) const = 0;     retired

  // Function Specification ********************************************
  //
  // Purpose:      This function returns the size (in bytes) of the
  //               buffer needed for accesses.
  // Parameters:   None.
  // Returns:      Buffer size.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  //
  // End Function Specification ****************************************
  //  virtual unsigned int GetBufferByteSize(void) const;

  // dg00 start
  /**
   Read hardware register (pure virtual)
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [SUCCESS | MOPs return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string represents the value of the
   hardware register (if rc == SUCCESS)
   <br><b>Sideaffects: </b> Value guarrenteed to be read from hardware.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual uint32_t ForceRead(void);
  // dg00 end

  /**
   Read hardware register
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [SUCCESS | MOPs return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string represents the value of the
                            hardware register (if rc == SUCCESS)
   <br><b>Sideaffects: </b> The bit string value may or may not be retrieved
                            from hardware; a buffered copy may be used.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual uint32_t Read(void);

  /**
   Unsynchronize the register access to recollect reg contents.
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [SUCCESS]
   <br><b>Requirements:</b> None.
   </ul><br>
   */
  virtual uint32_t UnSync(void);

   /**
   Write hardware register
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [SUCCESS | MOPs return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string value written to hardware
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> If internal bitstring was never read/set/modified then
                            zeros are written to corresponding hardware register.
   </ul><br>
   */
  virtual uint32_t Write(void);

  /**
   Access a copy of the short id for signatures.
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> ID.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual uint16_t GetId(void) const { return cv_shortId; };

  /**
   Set the short id for signatures.
   <ul>
   <br><b>Parameters:  </b> ID.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> For virtual registers, this is not required to have
                            any effect.
   </ul><br>
   */
  virtual void SetId(uint16_t i_id) { cv_shortId = i_id; };


   /**
   Access the chipid(s) of the chip
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> ptr to const array of chipIds
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  const TARGETING::TargetHandle_t * GetChipIds(int & chipCount) const
  { return hops->GetChipIds(chipCount); }

  const MopRegisterAccess & GetHops(void)const { return *hops; }

protected:
  ScanCommRegisterAccess() : SCAN_COMM_REGISTER_CLASS(0xffffffff), hops(NULL) {}
private:  // Functions

  /**
   This function reads or writes the hardware according to the specified operation.
   <ul>
   <br><b>Parameter:   </b> bufferPtr: Pointer to buffer for input
   <br><b>Parameter:   </b> (write operation) or output (read operation)
   <br><b>Paramter:    </b> op: Indicates either read or write operation
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> Buffer must be valid.
   <br><b>Promises:    </b> For read operation, buffer is modified.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint32_t Access(BIT_STRING_CLASS & bs, uint64_t registerId,
                       MopRegisterAccess::Operation op) const;

// #ifdef _USE_IOSTREAMS_

//   friend ostream & operator<<(ostream & out,
//                               const ScanCommRegisterAccess & scr);

// #endif

private: // Data

//  enum
//  {
//    BUFFER_BYTE_SIZE = 12
//  };
  SynchType                        synch;

  MopRegisterAccess * hops;

  uint16_t cv_shortId;
};

} // end namespace PRDF

// #ifdef _USE_IOSTREAMS_

//   // Function Specification ********************************************
//   //
//   // Purpose:      This function outputs the Scan Comm Register data
//   //               members to the specified output stream.
//   // Parameters:   out: Output Stream
//   //               scr: Reference to a Scan Comm Register instance
//   // Returns:      Parameter output stream
//   // Requirements: None.
//   // Promises:     Output stream will be written to.
//   // Exceptions:   None.
//   // Concurrency:  Reentrant.
//   //
//   // End Function Specification ****************************************
// ostream & operator<<(ostream & out,
//                      const ScanCommRegisterAccess & scr);

// #endif

#include <iipScanCommRegisterAccess.inl>

#endif
