/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipCaptureData.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef iipCaptureData_h
#define iipCaptureData_h

// Class Specification *************************************************
//
// Class name:   CaptureData
// Parent class: None.
//
// Summary: This class provides a queue-like buffer for recording Scan
//          Comm Register data.
//
//          When this class is constructed or the Clear() member
//          function is called, the buffer is empty.  The Add()
//          function adds data to the front or back of this buffer.
//          The data is ordered according to the sequence of Add()
//          calls and the Place parameter (FRONT or BACK).  A Scan
//          Comm Register is passed to the Add() function and the
//          register is read during the Add() function.  The data is
//          then stored internally.  Whenever the Copy() member
//          function is called, the current internal data is copied to
//          the specified buffer with respect to the current ordering.
//          Only the number of bytes specified are copied.  Therefore,
//          any data that MUST be copied should be added using the
//          FRONT placement.
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Linear based on the number of Add() calls
//   Time Complexity:  All member functions constant unless otherwise
//                     stated.
//
// Usage Examples:
//
// BIT8 data[BUFFER_SIZE];
//
// void foo(TARGETING::TargetHandle_t chipId, ScanCommRegisterAccess & scr)
//   {
//   CaptureData captureData;
//
//   captureData.Add(chipId, scr, CaptureData::FRONT);
//   captureData.Add(chipId, scr, CaptureData::BACK);
//
//   int bytesCopied = captureData.Copy(data, BUFFER_SIZE);
//   }
//
// End Class Specification *********************************************

/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/

#include <list>

#include <iipconst.h>
#include <prdfPlatServices.H>
#include <functional>  // @jl04 a Needed for the unary function in new predicate.

#include <endian.h>

namespace PRDF
{

// Forward Declarations
class SCAN_COMM_REGISTER_CLASS;
class ScanCommRegisterAccess;
class BitString;

// @jl04 a start
// @jl04 a Added this enumeration for error log compression, elimination of secondary regs.
  enum RegType
  {
    PRIMARY   = 1,
    SECONDARY = 2
  };
// @jl04 a Stop

/**
 Capture data class
 @author Doug Gilbert
 @version V5R2
*/
class CaptureData
{
public:

  enum Place
  {
    FRONT,
    BACK
  };

  enum
  {
    INITIAL_DATA_COUNT = 80,
    ENTRY_FIXED_SIZE = 8,
    MAX_ENTRY_SIZE = 128
  };

  /**
   Constructor
   */
  CaptureData(void);

  /*
   Copy constructor - default is ok
   */
//  CaptureData(const CaptureData & c);

  /*
   Assignment operator - default is ok
   */
//  CaptureData & operator=(const CaptureData & c);

  /**
   Destructor
   */
// dg05d  ~CaptureData(void);   // compiler default is ok

  /**
   Clear out capture data
   <ul>
   <br><b>Parameters:None
   <br><b>Returns:Nothing
   <br><b>Requirments:None.
   <br><b>Promises: All capture data cleared ( copy(...) == 0 )
   </ul><br>
   */
  void Clear(void);

  // dg00 start
  /**
   Add scr & data to capture log
   <ul>
   <br><b>Parameter:  chipHandle     target handle of chip object
   <br><b>Parameter:  scan comm id (unique one btye code representing scan comm address)
   <br><b>Parameter:  Scan comm register object
   <br><b>Parameter:  Optional location in capure vector [FRONT | BACK] def = BACK
   <br><b>Returns:   Nothing
   <br><b>Requires:  Nothing
   <br><b>Promises:  scr.Read()
   <br><b>Notes:     This is the required Add() method for Regatta and beyond
   </ul><br>
   */
  void Add( TARGETING::TargetHandle_t i_pchipHandle, int scomId,
            SCAN_COMM_REGISTER_CLASS & scr, Place place = BACK,
            RegType type = PRIMARY);  // @jl04 c. Changed this to add the type to the end of the parms.
  // dg00 end

  /*  REMOVE for FSP
   Add scr & data to capture log
   <ul>
   <br><b>Parameter:  chipHandle     target handle of chip object
   <br><b>Parameter:  Scan comm register object
   <br><b>Parameter:  Optional location in capure vector [FRONT | BACK] def = BACK
   <br><b>Returns:   Nothing
   <br><b>Requires:  Nothing
   <br><b>Promises:  scr.Read()
   <br><b>Notes:     This is the required Add() method for pre-Regatta
   </ul><br>

  void Add(TARGETING::TargetHandle_t chipId, SCAN_COMM_REGISTER_CLASS & scr,
      Place place = BACK);
*/

  // dg02 start
  /**
   Add scr & data to capture log
   <ul>
   <br><b>Parameter:  i_pchipHandle Handle of chip object
   <br><b>Parameter:  scan comm id (unique one btye code representing scan comm address)
   <br><b>Parameter:  BitString
   <br><b>Parameter:  Optional location in capure vector [FRONT | BACK] def = BACK
   <br><b>Returns:   Nothing
   <br><b>Requires:  Nothing
   <br><b>Promises:
   <br><b>Notes:     This is available for Regatta and beyond. Not implemented on Condor
   </ul><br>
   */
  void Add( TARGETING::TargetHandle_t i_pchipHandle, int scomId,
            const BitString & bs, Place place = BACK);

  // dg02 end

// start @jl04a
  /**
   Drop scr & data from capture log
   <ul>
   <br><b>Parameter:  Type of capture vector [PRIMARY | SECONDARY] def = PRIMARY. SECONDARIES dropped on connected.
   <br><b>Returns:   Nothing
   <br><b>Requires:  Nothing
   <br><b>Promises:
   </ul><br>
   */
void Drop(RegType type);  //@jl04a
// end @jl04a

    /**
     * @brief  Copies the capture data to a buffer.
     *
     * The capture data is copied to the buffer in the order it exists in the
     * vector until all entries have been added or until the buffer is full.
     *
     * @param  i_buffer     Pointer to buffer.
     * @param  i_bufferSize Maximum size of the buffer.
     * @return The actual size of the data buffer. The value will always be less
     *         than or equal to the maximum buffer size.
     */
    uint32_t Copy( uint8_t * i_buffer, uint32_t i_bufferSize ) const;

  // dg08a -->
  /**
   Reconstruct data from flat data
   <ul>
   <br><b>Parameter:  i_flatdata ptr to flat data
   <br><b>Returns:   reference to the new capture data
   <br><b>Requirements: None
   <br><b>Promises:  CaptureData created form flatdata
   <br><b>Note:  i_flatdata -> (uin32_t)size + data created by Copy()
                 data is network ordered bytes.
   <ul><br>
   */
  CaptureData & operator=(const uint8_t *i_flatdata);
  // <-- dg08a

private:

  // Notes *************************************************************
  //
  // Instead of maintaining an actual data buffer, an auxiliary data
  // structure is used to maintain data in a specific order.  The main
  // reason for this is that since data can be entered in the front or
  // back of the buffer, the data must be copied to maintain the order.
  // It is more efficient to copy a number of pointers than a large
  // data buffer.  However, there is added complexity since the data
  // structure contains a pointer to dynamic data that must be
  // allocated/deallocated properly.
  //
  // A vector of data structures is maintained that is given an initial
  // size.  The vector can grow dynamically, but this can be expensive
  // in terms of copying and memory fragmentation.  To prevent this, the
  // number of calls to Add() between calls to Clear() should not exceed
  // the enum INITIAL_DATA_COUNT.
  //
  // End Notes *********************************************************

  class Data
  {
  public:
    // Ctor
    Data(TARGETING::TargetHandle_t i_pchipHandle= nullptr,   // dg01
         uint16_t a = 0,
         uint16_t  dbl = 0,
         uint8_t * dPtr = nullptr)
    :
    chipHandle(i_pchipHandle),
    address(a),
    dataByteLength(dbl),
    dataPtr(dPtr)
    {}

    ~Data(void)                     // dg05a
    {                               // dg05a
      if(dataPtr != nullptr)           // dg05a
      {                             // dg05a
        delete [] dataPtr;          // pw01
      }                             // dg05a
    }                               // dg05a
    // Data
    TARGETING::TargetHandle_t  chipHandle;
    uint16_t address;
    uint16_t  dataByteLength;
    uint8_t * dataPtr;

    RegType registerType;          // @jl04a

    Data(const Data & d);
    Data & operator=(const Data & d);
  };

// We should probably use a link list instead of a vector
  typedef std::list<Data> DataContainerType;
  typedef DataContainerType::iterator DataIterator;
  typedef DataContainerType::const_iterator ConstDataIterator;

  DataContainerType             data;

    /** Private function to facilitate the adding of caputre data to the
     *  internal vector */
    void AddDataElement( TARGETING::TargetHandle_t i_trgt, int i_scomId,
                         const BitString * i_bs, Place i_place,
                         RegType i_type = PRIMARY );

  // Predicate for deciding to delete an element of data from a Capture Data list.
  class prdfCompareCaptureDataType : public std::unary_function<Data &, bool>
  {
    public:
      prdfCompareCaptureDataType(RegType i_ctor_input) : __private_storage(i_ctor_input){};
      bool operator() (Data &i)
      {
        return (i.registerType == __private_storage);
      };


    private:
    //Private storage for value passed in.
      RegType __private_storage;
    //Constructor allows a value to be passed in to compare against.
  };

  // Predicate for deciding whether to delete an
  // element of data from a Capture Data list.
  class prdfCompareCaptureDataEntry :
      public std::unary_function<Data &, bool>
  {
    public:
      prdfCompareCaptureDataEntry(
                    TARGETING::TargetHandle_t chipHandle,
                    uint16_t address) :
                    __chipHandle(chipHandle),
                    __address(address) {};
      bool operator() (Data &i)
      {
        return ((i.chipHandle == __chipHandle) &&
                (i.address    == __address));
      };

    private:
      TARGETING::TargetHandle_t  __chipHandle;
      uint16_t __address;
  };

public:

  /**
   * @brief   Merge scom register data from two captures
   * @param   i_cd  secondary capture data to merge
   */
  void mergeData(CaptureData & i_cd);

  /**
   * @brief   Get the Scom data pointer
   * @return  the Scom data pointer
   */
  DataContainerType * getData() { return &data; }



};

} // end namespace PRDF

#endif
