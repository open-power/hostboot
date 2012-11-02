/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfResolutionMap.H $ */
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

/*! /file prdfResolutionMap.H
 *  /brief Map Bit List encodings to Resolutions
 */
#ifndef ResolutionMap_h
#define ResolutionMap_h
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <vector>
#include <prdfBitKey.H>
#include <prdfResolutionList.H>
#include <prdfFilters.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;   //dg04c
//! ResolutionMap
/*!
 This class prvodes mapping of a bitList key to a resolution list
 @code
 Callout callout = { PU0_HIGH , MSCTLR0_HIGH } ;
 FinalResolution default_resolution(&callout);
 FinalResolution error_type1(&callout);
 ResolutionMap Resolutions(expected_size=10,&default_resolution);
 Resolutions.Add(BIT_LIST_STRING_15,&error_type1); // Add resolution for error bit 15
 //...
 foo(ScanCommRegister *scr, ResolutionMap &rm, STEP_CODE_DATA_STRUCT & error_data)
 {
    scr->Read();
    BIT_LIST_CLASS bl = *scr->GetBitString();
    Resolution & r = rm.LookUp(bl);
    r.Resolve(error_data);
 }
 @endcode
*/
class ResolutionMap
{
public:
  /**
   Constructor
   @param entryCount expected (estimated) number of entries
   @param defaultResolution Resolution of use if LookUp failes
   @param ptr to a filter to apply to the bitKey before it is looked up
   @pre None
   @post Object created & space reserved
   */
  ResolutionMap(int32_t entryCount, Resolution &defaultResolution, FilterClass * i_fltr = NULL);

  /*
   Destructor - compiler default is ok
   */
  //~ResolutionMap();

  // DRGDRG - Should we be returning a ResolutionList? or get rid of Default & use no bits on key???
  /**
   Get the default resolution for this map
   @returns a reference to the default resolution
   @pre None
   @post None
   */
  Resolution & GetDefault(void) const;

  /**
   Replace the default Resolution
   @param Reference to new default resolution
   */
  void ReplaceDefaultWith(Resolution & r);

  /**
   Add a key,Resolution pair
   @param i_bitPos - bit position
   @param 1 to 6 Resolutions
   */
  void Add(uint8_t i_bitPos,
           Resolution * i_res );
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2);
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2, Resolution * i_r3);
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2, Resolution * i_r3,
           Resolution * i_r4);
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2, Resolution * i_r3,
           Resolution * i_r4, Resolution * i_r5);
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2, Resolution * i_r3,
           Resolution * i_r4, Resolution * i_r5, Resolution * i_r6);
  void Add(uint8_t i_bitPos,
           Resolution * i_r1, Resolution * i_r2, Resolution * i_r3,
           Resolution * i_r4, Resolution * i_r5, Resolution * i_r6,
           Resolution * i_r7);

  /**
   Add a key,Resolution pair
   @param i_ble - bit list encoding  (array of bitPos)
   @param i_bleLen length of bit list
   @param 1 to 6 Resolutions
   */
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * res );
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * r1, Resolution * r2);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * r1, Resolution * r2, Resolution * r3);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4, Resolution * r5);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4, Resolution * r5, Resolution * r6);


  //! Old Add interface
  /*!
   */
  void Add(const char *i_ble,
           Resolution * res );
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2);
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2, Resolution * r3);
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2, Resolution * r3,
           Resolution * r4);
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2, Resolution * r3,
           Resolution * r4, Resolution * r5);
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2, Resolution * r3,
           Resolution * r4, Resolution * r5, Resolution * r6);
  void Add(const char *i_ble,
           Resolution * r1, Resolution * r2, Resolution * r3,
           Resolution * r4, Resolution * r5, Resolution * r6,
           Resolution * r7);

  void AddRange(const char *i_ble,Resolution * res ) { Add(i_ble,res); }
  void AddRange(const char *i_ble,Resolution * r1, Resolution * r2) { Add(i_ble,r1,r2); }
  void AddRange(const char *i_ble,
                Resolution * r1, Resolution * r2, Resolution * r3) { Add(i_ble,r1,r2,r3); }
  void AddRange(const char *i_ble,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4) { Add(i_ble,r1,r2,r3,r4); }
  void AddRange(const char *i_ble,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4, Resolution * r5) { Add(i_ble,r1,r2,r3,r4,r5); }
  void AddRange(const char *i_ble,
                Resolution * r1, Resolution * r2, Resolution * r3,
                Resolution * r4, Resolution * r5, Resolution * r6) { Add(i_ble,r1,r2,r3,r4,r5,r6); }
  /**
   Look up a Resolution for a bitlist
   @param bitList
   @returns List of all Resolutions that match
   @pre none
   @post Resolution returned is only valid until the next call to LookUp or this object is destroyed.
   i_bitList may be modified
   @notes if the bitList does not have a match then the defaultResolution is returned.
   */
    void LookUp( ResolutionList & o_list, BitKey & io_bitList,
                 STEP_CODE_DATA_STRUCT & scd );

  /**
   * @brief Get the stored filter associated with this resolution map.
   * @returns Currently assigned filter.
   */
  FilterClass * getFilter() { return iv_filter; };

  /**
   * @brief Store a new filter with this resolution map.
   * @param i - Filter to store.
   */
  void setFilter(FilterClass * i) { iv_filter = i; };

protected:  // functions

private: // functions

  /*!
   Copy prohibited
   */
  ResolutionMap(const ResolutionMap &);   // Don't allow copy - No defn

  /*!
   Assignment prohibited
   */
  const ResolutionMap &operator=(const ResolutionMap &); // Don't allow - no defn

private: // Data

  struct RmPair
  {
    BitKey iv_blist;
    Resolution * iv_res;
    RmPair(uint8_t i_bitPos, Resolution *res) : iv_blist(i_bitPos), iv_res(res) {}
    RmPair(void) : iv_blist(), iv_res(NULL) {}
  };

  typedef std::vector<RmPair> MapList;

  Resolution  * defaultRes;
  FilterClass * iv_filter;

  MapList iv_list;
//  MapList iv_rangeList;

};

inline ResolutionMap::ResolutionMap( int32_t entryCount,
                                     Resolution & defaultResolution,
                                     FilterClass * i_fltr ) :
    defaultRes(&defaultResolution), iv_filter(i_fltr), iv_list()
{
    iv_list.reserve(entryCount);
}

inline  Resolution & ResolutionMap::GetDefault(void) const {return *defaultRes; }
inline  void ResolutionMap::ReplaceDefaultWith(Resolution & r) { defaultRes = &r; }

} // end namespace PRDF

#endif /* ResolutionMap_h */

