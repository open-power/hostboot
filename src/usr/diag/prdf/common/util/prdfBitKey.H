/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitKey.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

/*!  /file prdfBitKey.H
 *   /brief prdfBitKey class Declairation
 *
 */
#ifndef PRDFBITLKEY_H
#define PRDFBITLKEY_H

#include <prdf_types.h>

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

class prdfBitString;

//! prdfBitKey
/*!
    prdfBitKey provides the representation of bit positions that are
    set ('1') In a string of bits. It has the same iterface as the prdfBitList or BIT_LIST_CLASS.

\remarks The object this class creates is meant to be used as a key in a map or table and
         as such represents the "typical" key as efficiently as possible. It can,
         however, represent large lists without penalizing the size of all the
         keys in a map or table.  This implementation assumes the standard bit string capacity
         is 64 bits, but supports sized up to 2^32 bits. The size of the object is always 12 bytes.

\notes
 This class is a replacement of a BitListClass which is meant be viewed as a list of bit positions,
 though BitKey is not implemented that way internally. The following shows how a BitString and a
 BitList represent that same bit string. (ie BitString == BitList)
\verbatim
   BitString representation ->  '001011001'b
   BitList   representation -> {2,4,5,8}
   BitList.getListValue(0) returns 2;
   BitList.getListValue(1) returns 4;
   BitList.getListValue(3) returns 5; etc
   BitList.getListValue(n) returns the bit position of the nth bit that is set
\endverbatim

 The setBit() and/or assignment operators are used to place
 values (bit positions) in the list.  Values can be assigned directly from
 Bit String bit positions (0 to n from left to right).  The
 maximum value (bit position) that can be stored in BitKey is 2^32.
\verbatim

 0 1 2 3 .... n

 B B B B .... B
\endverbatim

 The assingment operator is overloaded to provide setting
 the bit positions form a NULL terminated character
 string.  Since the string is NULL terminated with 0 and
 this a valid bit position, each character value is
 converted to an unsigned character and decremented to
 obtain the actual bit position.  The character string
 assignment is limited to the maximum bit position (254)
 that can be represented.  As an example, the following
 are equivalent Bit Lists.

 Bit String:        10010001
 Character String:  "\x01\x04\x08"

 The equality operator and isSubset() function are used to
 compare Bit Lists. An empty Bit List can be
 represented and two empty Bit Lists are considered equal.

\par       Space Complexity:  Linear.
            K + Mn where K and M are constants and n is the
            number of bit psotions in the list

\sa         prdfBitString
*/
class prdfBitKey
  {
  public:

    //! Default Constructor
    /*!
        This function initializes the string to NULL (empty bit list)
     */
    prdfBitKey(void);

    //! Constructor
    /*!
        This function initializes the bit list with one value;
     */
    prdfBitKey(uint32_t i_bitPos);

    //! Constructor
    /*!
     This function initializes an bit list from an array of uint8_t
     \param i_array ptr to array of bit list values
     \param i_size  size of the array
     */
    prdfBitKey(const uint8_t * i_array,uint8_t i_size);

    /*!
     Constructor - from a bit list encoding
     \param i_ble ptr to Bit list encoding
     */
    prdfBitKey(const char * i_ble);

    //! Copy Constructor
    prdfBitKey (const prdfBitKey & bit_list);

    //! Destructor
    ~prdfBitKey(void);

    //! Assignment operator from prdfBitKey
    /*!
     \post *this == bit_list
     */
    prdfBitKey & operator=(const prdfBitKey & bit_list);

    //! Assignment operator from prdfBitString
    /*!
     This function assigns the specified Bit String bit
     positions to this Bit List.  Bit positions are set
     from left to right.
     */
    prdfBitKey & operator=(const prdfBitString & bit_string);

    //! Assignment operator from c string (char *)
    /*!
     This function assigns the specified pointer to
     character string representation of a Bit List to this
     Bit List.  Since the string is NULL terminated with 0
     and thus a valid bit position, each character value is
     decremented to obtain the actual bit position.
    */
    prdfBitKey & operator=(const char * string_ptr);

    //! Equality operator
    /*!
     This function determines if the specified Bit List
     is equal to this Bit List.  The associated string
     representations are tested for equality.  The lists
     must have the same length and corresponding bit
     positions.  If both Bit Lists are empty, they are
     considered equal.
     */
    bool operator==(const prdfBitKey & bit_list) const;

    //! Is Subset
    /*!
     This function determines if the specified Bit List
     is a subset of this Bit List.  If this Bit List
     contains every bit position that is contained in the
     specified Bit List, then it is a subset.

     \verbatim
     Examples:
     ("1") IS a subset of ("1", "5", "31");
     ("1") IS NOT a subset of ("5", "31");
     ("2", "7") IS NOT a subset of ("2", "5", "31");
     ("2", "7") IS a subset of ("2", "7", "31");
     An empty list is a subset of an empty list.
     An empty list is NOT a subset of a non-empty list
     A non-empty list is NOT as subset of an empty list
     \endverbatim
     */
    bool isSubset(const prdfBitKey & bit_list) const;

    //! Get Bit List Value
    /*!
     This function returns the bit position of the nth bit that is set
     \pre   bit_list_offset < size(),  size() > 0
     \post  None.
     */
    uint32_t getListValue(uint32_t n) const;

    //! Get Bit List Length
    /*!
     \return the  # of bits set (Length of list of set bits positions)
     \pre  None.
     \post None.
     */
    uint32_t size(void) const ;

    /*!
     This function removes the nth set bit from the Bit List.

     \pre bit_list_offset < size()
     */
    void removeBit(uint32_t n);

    /*!
     Remove the highest bitpos that is set
     \pre none
     \post none
     \ if this is already empty then nothing happens
     */
    void removeBit(void);

    /*!
     Remove the bit positions from this list specified in the paramter list
     \pre none
     \post bit list may be modified
     */
    void removeBits(const prdfBitKey & i_bk);


    /*!
     Add a bit to the bit position List
     */
    void setBit(uint32_t i_bitValue);

  private: // DATA

    uint32_t iv_Capacity;
    uint32_t iv_storage1;
    /*!
     \union REPRESENTATION_UNION
     Representation stored in representaion.value when IsDirect() == true
     otherwise additional storage allocated and pointed to by buffer
     */
    union REPRESENTATION_UNION
    {
      uint32_t  storage2;
      uint32_t * buffer;
    } iv_rep;



    enum
    {
      REPRESENTATION_BIT_POSTION_COUNT = 64
    };

  private: // Functions
    //! Is Direct
    /*!
     This function indicates if the direct representation can be used.
    */
    bool IsDirect(void) const
    {
      return( iv_Capacity <= REPRESENTATION_BIT_POSTION_COUNT);
    }

    //! Set String
    /*!
     This function allocates storage for keys bigger keys (IsDirect() == false)
     \return number of uint32_t words allocated
     \post
     If the string is NULL, then it is allocated.
     If the string length is not equal to the specified
     length, then the string is re-allocated.
     */
    void ReAllocate(uint32_t bit_pos);

    uint32_t * DataPtr(void)
    {
      uint32_t * ptr = NULL;
      if(IsDirect()) ptr = &iv_storage1;
      else ptr = iv_rep.buffer;
      return ptr;
    }

    const uint32_t * cDataPtr(void) const
    {
      const uint32_t * ptr = NULL;
      if(IsDirect()) ptr = &iv_storage1;
      else ptr = iv_rep.buffer;
      return ptr;
    }

  };

#endif

// Change Log *************************************************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- ---------------------------------------------------------
//                              dgilbert Initial Creation
//
// End Change Log *********************************************************************************
