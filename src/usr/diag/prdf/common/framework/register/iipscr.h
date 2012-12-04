/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipscr.h $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2013              */
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

#ifndef IIPSCR_H
#define IIPSCR_H

// Module Description **************************************************
//
//  Description:  This module contains the declarations for the
//                Processor Runtime Diagnostics Scan Communication
//                Register class.
//
//  Notes:  Unless stated otherwise, assume that each function
//          specification has no side-effects, no dependencies, and
//          constant time complexity.
//
// End Module Description **********************************************


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <iipbits.h>
#include <iipsdbug.h>
#include <prdfMain.H>

namespace PRDF
{
/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

// Class Specification *************************************************
//
//  Name:  SCAN_COMM_REGISTER_CLASS
//
//  Title:  Scan Communication Register
//
//  Purpose:  SCAN_COMM_REGISTER_CLASS provides the representation
//            and access to a physical register.
//
//  Usage:  This is an abstract base class.
//
//  Side-effects:  Memory is allocated.
//
//  Dependencies:  None.
//
//  Notes: The Scan Communication Register is a model of an actual
// physical register.  The bits in the register are represented by the
// bit_string data member which is modified dynamically as operations
// are preformed.  It acts as a temporarily cached value of the
// register.  When a read is performed, the bit values are updated in
// the bit string. When a write is performed, the current value of the
// bits are used as the value to write.  The current value of this
// cached bit string can be accessed or modified by other objects via
// the public interface.  The physical address and bit length of the
// hardware register are set during intialization and used on all
// acceses.
//
// The basic Read() and Write() functions are virtual.  The
// actual implemenations are dependent on the actual hardware
// and the software Hardware Manual Ops Scan Control Routines.
// These function specifications describe a common behaviour
// that every derived class must follow.  Additional,
// information may also be specified.
//
// A Read() function is also provided that has a Bit String
// mask parameter.  This function calls the virtual Read()
// and then applies the mask so that the internal Bit String
// contains the hardware register contents with certain bits
// ignored (masked off).
//
//  Cardinality:  0
//
//  Space Complexity:  Linear
//                     K + Mn where K and M are constants and n is the
//                     number of bits in the register.
//
// End Class Specification *********************************************
/**
 SCAN_COMM_REGISTER_CLASS
 @author Doug Gilbert
 @V5R2
 */
class SCAN_COMM_REGISTER_CLASS
{
public:

  /**
   Destructor
   */
  virtual ~SCAN_COMM_REGISTER_CLASS(void);

  // dg00 start
  /**
   Read hardware register (virtual)
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [SUCCESS | MOPs return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string represents the value of the
                            hardware register (if rc == SUCCESS)
   <br><b>Sideaffects: </b> Value guarenteed to be read from hardware.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Default is to call Read().  If a child class cannot
                            guarentee hardware access everytime Read() is called
                            then the function ForceRead() should be overridden.
   </ul><br>
   */
  virtual uint32_t ForceRead(void) { return Read(); };
  // dg00 end

  /**
   Read hardware register (pure virtual)
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
  virtual uint32_t Read(void) = 0;

  /**
   Read hardware register and apply a mask
   <ul>
   <br><b>Parameters:  </b> Mask to apply
   <br><b>Returns:     </b> [SUCCESS | MOPs return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string represents the value of the
                            hardware register with the bits turned off as
                            specified by the mask.
   <br><b>Sideaffects: </b> The bit string value may or may not be retrieved
   from hardware. a buffered copy may be used.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> if bits read from hardware = '00110100'
                            and mask =                   '01110000'
                            then internal bit sting =    '00000100'

                            if mask.Length() < GetBitString()->Length()
                            then mask is right extended with 0's
                            if mask.Length() > GetBitString()->Length()
                            then extra mask bits are ignored.
   </ul><br>
   */
  uint32_t Read(BIT_STRING_CLASS & mask);

  /**
   Write hardware register (pure virtual)
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
 virtual uint32_t Write(void) = 0;

  /**
   Access a copy of the scan comm address
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Returns scom address
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual uint64_t GetAddress(void) const {return 0 ;}

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
  virtual uint16_t GetId(void) const = 0;

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
  virtual void SetId(uint16_t) = 0;


  /**
   Access the bit length of the register
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> bit length of the register
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
   virtual uint32_t GetBitLength(void) const { return DEFAULT_BIT_LENGTH ;}

  /**
   Access the internal bit string (pure virtual)
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> ptr to the internal bit string (const)
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> If the internal bit string was never read/modified then
                            all bits are zero
   </ul><br>
   */
  virtual
  const BIT_STRING_CLASS * GetBitString(ATTENTION_TYPE
                                        i_type = INVALID_ATTENTION_TYPE
                                       ) const = 0;

  /**
   Modify the internal bit string (pure virtual)
   <ul>
   <br><b>Parameters:  </b> a bit string
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Internal bit string == *bs for first len bits where
                            len is the smaller of the two lengths.
                            Memory may be (re)allocated
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> The hardware register value is not modified until
                            Write() is called
   </ul><br>
   */
  virtual void SetBitString(const BIT_STRING_CLASS * bs) = 0;

  /**
   SetBit
   <ul>
   <br><b>Parameters:  </b> Position of bit to set (= 1)
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> bit position < GetBitString()->Length()
   <br><b>Promises:    </b> GetBitString()->IsSet(bit_position) == true
   <br><b>Exceptions:  </b> None.
   <br><b> Notes:      </b> Register value is not reflected in hardware until
                            Write() is called
   </ul><br>
   */
  void SetBit(uint32_t bit_position);

  /**
   ClearBit (reset bit)
   <ul>
   <br><b>Parameters:  </b> Position of bit to clear (= 0)
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> bit position < GetBitString()->Length()
   <br><b>Promises:    </b> GetBitString()->IsSet(bit_position) == false
   <br><b>Exceptions:  </b> None.
   <br><b> Notes:      </b> Register value is not reflected in hardware until
                            Write() is called
   </ul><br>
   */
  void ClearBit(uint32_t bit_position);

    /**
     * @brief  Will query if a bit is set.
     * @param  i_bitPos The bit position to query.
     * @pre    The bit position must be less than GetBitString()->Length()
     * @return TRUE if the bit is set, FALSE otherwise.
     */
    bool IsBitSet( uint32_t i_bitPos )
    {  return GetBitString()->IsSet(i_bitPos);  }

    /** @brief Flushes all bits to 0. */
    void clearAllBits();

    /** @brief Flushes all bits to 1. */
    void setAllBits();

  /**
   Get a field within the bitstring (right justified)
   <ul>
   <br><b>Parameters:  </b> start bit position, length of field
   <br><b>Returns:     </b> CPU_WORD containing requested bits (right justified)
   <br><b>Requirements:</b> bit_position < GetBitLength(),
                            length <= sizeof(CPU_WORD) (32 bits for 603/403)
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  CPU_WORD GetBitFieldJustified(uint32_t bit_position,uint32_t length) const
  { return GetBitString()->GetFieldJustify(bit_position,length); }

  /**
   Set a field within the bitstring with a value (from right to left in bit string)
   <ul>
   <br><b>Parameters:  </b> start bit position, length of field, value
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> bit_position < GetBitLength(),
                            length <= sizeof(CPU_WORD) (32 bits for 603/403),
                            length must be large enought to hold the value.
   <br><b>Promises:    </b> GetBitFieldJustified(bitPosition,length) == value
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetBitFieldJustified(uint32_t bitPosition,uint32_t length,CPU_WORD value)
  { AccessBitString().SetFieldJustify(bitPosition,length,value); }

  /**
   Query if bit string is all zeros
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool BitStringIsZero()
  { return GetBitString()->IsZero(); }
   /**
    *@brief    Returns TYPE_NA as type of Target associated with register.Acutal
    *          implementation is expected in derived class
     *@return   TYPE_NA
   */
  virtual TARGETING::TYPE getChipType(void)const { return TARGETING::TYPE_NA; }

protected:

  /**
   Get modifiable reference to internal bit string (don't even thing about making this public!!!)
   <ul>
   <br><b>Paramters:    </b> None.
   <br><b>Returns       </b> Reference to the internal bit string
   <br><b>Requirments   </b> None.
   <br><b>Promises      </b> None.
   </ul><br>
   */
  virtual BIT_STRING_CLASS & AccessBitString(void) = 0;
private: // Data
  static const int DEFAULT_BIT_LENGTH = 64;

  // Enum Specification //////////////////////////////////////////////
  //
  // Purpose:  These enumerated constants specify implementation data.
  //
  // End Enum Specification //////////////////////////////////////////

  enum
  {
    ODD_PARITY_SET_BIT_POSITION = 16
  };

  // Data Specification //////////////////////////////////////////////
  //
  // Purpose:  These data members specify the physical properties of
  //           register.
  //
  // End Data Specification //////////////////////////////////////////


};

}//namespace PRDF

#endif
