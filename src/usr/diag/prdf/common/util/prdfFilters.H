/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFilters.H $                 */
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

#ifndef PRDFFILTER_H
#define PRDFFILTER_H

/**
 @file Filter.H
 @brief FILTER_CLASSes selectivly remove bits from a BitKey type object
*/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#if !defined(PRDFBITLKEY_H)
#include <prdfBitKey.H>
#endif

#include <vector>

namespace PRDF
{
/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

class BitKey;

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/**
 FilterClass Specifies and interface for removing unwanted bits from a BitKey.
 Abstract base class
 @see BitKey
*/
class FilterClass
{
public:


  /**
   Destructor. This implementation does nothing
   */
  virtual ~FilterClass(void);


  /**
   Apply filter to the BitKey.
   @post bit_list may be modified
   @return true if bit_list was modified, otherwise false
   */
  virtual bool Apply(BitKey & io_bit_list) = 0;

  /**
   * Undo the filter effect (if possible)
   * @post bit_list may be modified
   * @Return tru if bit_list was modified, otherwise false
   * @note: bit_lists are sometimes used to reset an error register based on the bit that was
   * analyzed. If the Apply() function modifes the bit_list in such a way that make it unusable
   * to reset the error register (eg. moves a bit to a new postition) than the Undo() function
   * should put the bit_list back into a state that can be used to reset an error register.
   */
  virtual bool Undo(BitKey & io_bit_list) { return false; }

protected:

  /**
   Default Constructor
   @note The default compiler generated copy constructor and assignment operator
   are adaquate.
   */
  FilterClass(void) {}

};

//! FilterPriority
/*!
 FilterPriority maintains a "subset" BitKey or a "priority" set of bits.
 When this filter is applied to a BitKey, If the "priority" BitKey is a subset of the
 BitKey than the BitKey becomes the priorty BitKey. (The non-priority bits are turned off);
 Otherwise the BitKey remains unchanged.

 \verbatim
 Examples:
 Priority BitKey: ("1")
 Original BitKey: ("1", "5", "31")
 Filtered BitKey: ("1")

 Priority BitKey: ("1")
 Original BitKey: ("5", "31")
 Filtered BitKey: ("5", "31")

 Priority BitKey: ("2", "7")
 Original BitKey: ("2", "5", "31")
 Filtered BitKey: ("2", "5", "31")

 Priority BitKey: ("2", "7")
 Original BitKey: ("2", "7", "31")
 Filtered BitKey: ("2", "7")
 \endverbatim
 */
class FilterPriority : public FilterClass
{
public:

  /*!
   Constructor
   \param i_bld ptr bit list string encoding
   */
  FilterPriority(const char * i_ble)
  : ivBitKey(i_ble)
  {}


  /*!
   Constructor
   \param iBitList BitKey
   */
  FilterPriority(const BitKey & iBitList)
  : ivBitKey(iBitList)
  {}

  /*!
   Apply the filter to a bit list
   \param ioBitList to apply filter to
   \returns true if iBitList modified otherwise false
   */
  virtual bool Apply(BitKey & ioBitList);

protected:


  BitKey ivBitKey;

};

//! PrioritySingleBitFilter
/*!
 PrioritySingleBitFilter removes all but one bit from a BitKey object.
 Priority (to not be removed) is given to the bits specified and in the order
 specified.
 @par Example
 @code
      const char * const BIT_LIST_STRING_31_26 = "\x20\x1B"; // priority bits
      PrioritySingleBitFilter psbFilter(BIT_LIST_STRING_31_26);
      ScanCommRegisterChip scr(...);  // see iipScanCommRegisterChip.h
      ResolutionMap resMap(...);      // see iipResolutionMap.h

      // when the error register is read, the resulting list of bits on
      // is passed to psbFilter. the result is used to look up a resolution
      // in the ResultionMapa resMap and the resolution is called
      ErrorRegisterMask ereg(scr,resMap,&psbFilter);
      ...
      rc = ereg.Analyze(serviceData);  // See iipErrorRegisterMask.h
      //   ereg will apply filter prioritizing bit 31 then bit 26
      //   and finally any remaining bits
 @endcode
 @par functionality
 - if no priority bits exist in BitKey object then
   - eliminate all but first entry in list
 - else if priority bits exist then
   - eliminate all non-priority bit entries
   - if multiple priority bit entries exist then elminate all but one,
     favoring the first qualified entry found in the list.
*/
class PrioritySingleBitFilter : public FilterClass
{
public:

  /**
   Constructor
   @param pbls  Priority bit list string: list of bit positions that have priority
   @note bit position priority values in pbls are the bit position + 1 of the bit list,
   thus to prioritize bit positions 0,1, & 2 in the bit list, pbls would = "\x01\x02\x03";
   */
  PrioritySingleBitFilter(const char * pbls = NULL)
    {
        if (NULL != pbls)
        {
            while('\0' != pbls[0])
            {
                iv_bitList.push_back(pbls[0]+1);
                pbls++;
            }
        }
    };

  PrioritySingleBitFilter(const std::vector<uint8_t> & pbls)
    {
        iv_bitList = pbls;
    };


  /**
   Apply filter to bit list
   @param bit_list : the bit list to filter
   @pre none
   @post Bit list will only have one value - the one with the highest
   priority. If multiple values have equally highest priority then the first
   value in the list is used.
   @return true of bit list was modified otherwise false
   @note If the bit list is empty then it will be left empty.
   */
  virtual bool Apply(BitKey & bit_list);

private:  // functions
private:  // Data

  std::vector<uint8_t> iv_bitList;

};

//! FilterTranspose
/*!
 FilterTranspose transposes an exactly matching key to a single bit. If there is not an
 exact match, the key is not modified.
*/
class FilterTranspose : public FilterPriority
{
public:

  /**
   Constructor
   \param i_bitKey  bit list key
   \param iBitPos  bit to set if i_bitKey matches target.
   */
  FilterTranspose(const BitKey &i_bitKey,uint32_t iBitPos)
  : FilterPriority(i_bitKey),ivSingleBitPos(iBitPos)
  {}

  /**
   Apply filter to bit list
   \param bit_list : the bit list to filter
   \pre none
   \post If the provide BitList exactly matches the internal BitList than the provided
   bitlist is modified such that all bits are cleared and ivSingleBitPos is set.
   \return true of bit list was modified otherwise false
   */
  virtual bool Apply(BitKey & iBitList);

  /**
   * Undo the filter Apply()
   * @post bit_list may be modified
   * @Return true if bit_list was modified, otherwise false
   * @Note This function will only Undo the transposition if the transposed result bit is on
   */
  virtual bool Undo(BitKey & iBitList);

private:  // functions
private:  // Data

  uint32_t ivSingleBitPos;

};

//! SingleBitFilter
/*!
 Reduces a BitKey to single bit
 \code
   // usually in chip class header file
   SingleBitFilter sbFilter;
   ScanCommRegisterChip scr;  // @see iipScanCommRegisterChip.h
   ResolutionMap resMap;      // @see prdfResolutionMap.H

   // in ctor of chip class definition
   ErrorRegisterMask ereg(scr,resMap,&sbFilter);
   // ...
   rc = ereg.Analyze(serviceData);  // See iipErrorRegisterMask.h
   //   ereg will apply filter before analyzing the error
 \endcode
 */
class SingleBitFilter: public FilterClass
{
public:
  /*!
   Constructor
   */
  SingleBitFilter(): FilterClass() {}

  /*!
   Remove all but one bit from bit_list
   \param ioBitList Target bit list
   \returns true if ioBitList was modified otherwise false
   */
  virtual bool Apply(BitKey & ioBitList);

private:  // functions
private:  // Data

};


//! FilterLink
/*!
 FilterLink links two FILTER_CLASS types together allowing two filters
 to act on a single BitKey object.
 @code

        Filter * foo(Filter & f1, Filter & f2)
        {
                Filter * joint = new FilterLink(f1,f2);
                return joint;
        }
 @endcode
 */
class FilterLink: public FilterClass
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameters:  </b> Two FilterClasss to be linked
   <br><b>Requirements:</b> parm filters objects must exist and be valid
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> N/A
   <br><b>Notes:       </b>
   </ul><br>
   */
  FilterLink(FilterClass & f1, FilterClass & f2);

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Default is sufficient
   </ul><br>
   */
  //  ~xspprdFilterLink();

  /**
   Apply Filter(s)
   <ul>
   <br><b>Parameters:  </b> reference to a BIT_LIST (see iipbtlst.h)
   <br><b>Returns:     </b> [TRUE | FALSE] - was bit list modified?
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> bit_list is modified (if rc == TRUE)
   <br><b>Exceptions:  </b> N/A
   <br><b>Notes:       </b> calls all the other associated filters
   </ul><br>
   */
  virtual bool Apply ( BitKey & bit_list );

  /**
   * Undo the filter Apply()
   * @post bit_list may be modified
   * @Return true if bit_list was modified, otherwise false
   */
  virtual bool Undo(BitKey & iBitList);

private:  // functions
private:  // Data

  // may be extended to use a vector if needed
  FilterClass & xFilter1;
  FilterClass & xFilter2;
};


class SCAN_COMM_REGISTER_CLASS;

//! ScanCommFilter
/*!
 ScanCommFilter reads a HW scom register to determin which bits to
 removes bits from a BitKey object
 @par Base class Filter
 @code
 //   This class is useful for Error registers whose bits can be
 //   configured to report different ways depending on another
 //   enable register.

 ScanCommRegister enableScr(...);  // see iipScanCommRegisterChip.h
 ScanCommFilter scfFirXstop(enableScr,INVERT);
 ScanCommFilter scfFirRer(enableScr,NONINVERT);
 ScanCommRegister scr(...);  // see iipScanCommRegisterChip.h
 ResolutionMap resMap(...);      // see iipResolutionMap.h
 ErrorRegisterMask eregFirXstop(scr,resMap,&scfFirXstop);
 ErrorRegisterMask eregFirRer(scr,resMap,&scfFirRer);
 ...
 rc = eregFirXstop.Analyze(serviceData);  // See iipErrorRegisterMask.h
 //   ereg will apply filter
 @endcode
 */
class ScanCommFilter: public FilterClass
{
public:

  // Enum for use as the second parameter in the constructor.
  enum InvertValue {
    NONINVERT = 0x0,
    INVERT    = 0x1
  };

  /*!
   Constructor
   \param r Reference to a scan comm register
   \param invert whether or not to bit-wise invert the value from the scan comm read
   */
  ScanCommFilter(SCAN_COMM_REGISTER_CLASS & i_r, InvertValue invert = NONINVERT)
    :
    FilterClass(),
  scr(i_r),
  xInvert(invert)
  { }

  /*!
   Turn off bits in bit list based on contents of scan com register
   @post bit_list may be modified
   @return true if bit_list was modified, otherwise false
   */
   virtual bool Apply(BitKey & bit_list);

private:  // functions
private:  // Data
  SCAN_COMM_REGISTER_CLASS & scr;
  InvertValue xInvert;
};


inline FilterLink::FilterLink(FilterClass & f1, FilterClass & f2)
: xFilter1(f1), xFilter2(f2) {}

} //End namespace PRDF

#endif

