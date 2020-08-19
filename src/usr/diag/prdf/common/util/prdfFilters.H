/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFilters.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
struct STEP_CODE_DATA_STRUCT;

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/**
 * @brief Defines FilterClass
 * Describes  interface for removing unwanted bits from a BitKey.
 * It is a abstract base class.
 * see BitKey
 */
class FilterClass
{
    public:

    /**
     * @brief Destructor. This implementation does nothing
     */
    virtual ~FilterClass(void);

    /**
     * @brief  Applies filter on given bitkey
     * @param  i_bitList  bitkey on which filter acts.
     * @param  io_sdc      reference to STEP_CODE_DATA struct.
     * @return true if bit key is modified false otherwise.
     */
    virtual bool Apply( BitKey & io_bit_list,
                        STEP_CODE_DATA_STRUCT & io_sdc ) = 0;

    /**
     * Undo the filter effect (if possible)
     * @post bit_list may be modified
     * @Return tru if bit_list was modified, otherwise false
     * @note: bit_lists are sometimes used to reset an error register based on
     * the bit that was analyzed. If the Apply() function modifes the bit_list
     * in such a way that make it unusable to reset the error register
     * (eg. moves a bit to a new postition) than the Undo() function should put
     * the bit_list back into a state that can be used to reset an error
     * register.
     */
    virtual bool Undo(BitKey & io_bit_list) { return false; }

    protected:

    /**
     * @brief  Default Constructor
     * @note The default compiler generated copy constructor and assignment
     *       operator are adaquate.
     */
    FilterClass(void) {}

};

/** @brief  description of FilterPriority filter.

 * FilterPriority maintains a "subset" BitKey or a "priority" set of bits.
 * When this filter is applied to a BitKey, If the "priority" BitKey is a subset
 * of the BitKey than the BitKey becomes the priorty BitKey. (The non-priority
 * bits are turned off ).Otherwise the BitKey remains unchanged.

 * Examples:
 * Priority BitKey: ("1")
 * Original BitKey: ("1", "5", "31")
 * Filtered BitKey: ("1")

 * Priority BitKey: ("1")
 * Original BitKey: ("5", "31")
 * Filtered BitKey: ("5", "31")

 * Priority BitKey: ("2", "7")
 * Original BitKey: ("2", "5", "31")
 * Filtered BitKey: ("2", "5", "31")

 * Priority BitKey: ("2", "7")
 * Original BitKey: ("2", "7", "31")
 * Filtered BitKey: ("2", "7")
 */
class FilterPriority : public FilterClass
{
    public:

    /**
     * @brief Constructor
     * @param i_ble ptr bit list string encoding
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

    /**
    * @brief  Applies priority filter on given bitkey.
    * @param  i_bitList  bitkey on which filter acts.
    * @param  io_sdc      reference to STEP_CODE_DATA struct.
    * @return true if bit key is modified false otherwise.
    */
    virtual bool Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc );

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
     * @brief Constructor
     * @param pbls  list of bit positions that have priority
     * @note bit position priority values in pbls are the bit position + 1 of
     * the bit list, thus to prioritize bit positions 0,1, & 2 in the bit list,
     * pbls would = "\x01\x02\x03";
     */
    PrioritySingleBitFilter(const char * pbls = nullptr)
    {
        if (nullptr != pbls)
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
     * @brief  Apply filter to bitkey.
     *         Bit list will only have one value - the one with the highest
     *         priority. If multiple values have equally highest priority then
     *         the first value in the list is used.
     * @param  i_bitList  bitkey on which seondary filter need to act.
     * @param  io_sdc      reference to STEP_CODE_DATA struct.
     * @return true if bit key is modified false otherwise.
     */
    virtual bool Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc );

    private:  // functions
    private:  // Data

    std::vector<uint8_t> iv_bitList;

};

/**
 * @brief  FilterTranspose

 * FilterTranspose transposes an exactly matching key to a single bit. If there
 * is not an exact match, the key is not modified.
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
     * @brief  Applies transpose filter on given bitlist
     *         If the provide BitList exactly matches the internal BitList than
     *         the provid bitlist is modified such that all bits are cleared and
     *         ivSingleBitPos is set.
     * @param  i_bitList  bitkey on which filter acts.
     * @param  io_sdc      reference to STEP_CODE_DATA struct.
     * @return true if bit key is modified false otherwise.
     */
    virtual bool Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc );

    /**
     * Undo the filter Apply()
     * @post bit_list may be modified
     * @Return true if bit_list was modified, otherwise false
     * @Note This function will only Undo the transposition if the transposed
     *       result bit is on
     */
    virtual bool Undo(BitKey & iBitList);

    private:  // functions
    private:  // Data

    uint32_t ivSingleBitPos;

};

/**
 * @brief Description of interface for SingleBitFilter.
 *
 * reduces a BitKey to single bit e.g.
 * ....
 * ErrorRegisterMask ereg(scr,resMap,&sbFilter);
 * rc = ereg.Analyze(serviceData); ( See iipErrorRegisterMask.h )
 * ereg will apply filter before analyzing the error
 */

class SingleBitFilter: public FilterClass
{
    public:

    /**
    @param Constructor
    */
    SingleBitFilter(): FilterClass() {}

    /**
     * @brief  joins two different filter such that one acts after other.
     * @param  i_bitList  bitkey on which SingleBitFilter filter acts.
     * @param  io_sdc      reference to STEP_CODE_DATA struct.
     * @return true if bit key is modified false otherwise.
     */
    virtual bool Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc );

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
     * @brief  Constructor
     * @param  i_f1     first filter. usually existing one.
     * @param  i_f2     second filter. usually the new one.
     */
    FilterLink(FilterClass & f1, FilterClass & f2);

    /**
     * @brief  joins two different filter such that one can act after other.
     * @param  i_bitList  bitkey on which seondary filter need to act.
     * @param  io_sdc      reference to STEP_CODE_DATA struct.
     * @return true if bit key is modified false otherwise.
     */
    virtual bool Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc );

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

inline FilterLink::FilterLink(FilterClass & f1, FilterClass & f2)
: xFilter1(f1), xFilter2(f2) {}

class CsRootCauseFilter: public FilterClass
{
    public:

      /** @brief default constructor */
      CsRootCauseFilter() = default;

      /**
       * @brief   constructor
       * @param   i_bitList  list of bits identifed as cs_root_cause in a FIR
       */
      CsRootCauseFilter( const std::vector<uint8_t> & i_bitList )
      {
          iv_csCauseBitList = i_bitList;
      }

      /**
       * @brief  will only consider bits specified in cs_root_cause filter as
       *         possible checkstop root causes in the given BitKey
       * @param  i_bitList  bitkey on which cs_root_cause filter needs to act
       * @param  io_sdc     reference to STEP_CODE_DATA struct
       * @return true if bit key is modified, false otherwise
       */
      virtual bool Apply( BitKey & io_bitList, STEP_CODE_DATA_STRUCT & io_sdc );

    private: // data

      // list of bit pos marked as cs_root_cause
      std::vector<uint8_t> iv_csCauseBitList;
};

} //End namespace PRDF

#endif

