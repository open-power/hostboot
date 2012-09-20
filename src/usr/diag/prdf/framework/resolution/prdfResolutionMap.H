/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/prdfResolutionMap.H $  */
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
#ifndef prdfResolutionMap_h
#define prdfResolutionMap_h
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <vector>
#include <prdfBitKey.H>
#include <prdfResolutionList.H>
#include <prdfFilters.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;   //dg04c
//! prdfResolutionMap
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
class prdfResolutionMap
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
  prdfResolutionMap(int32_t entryCount, prdfResolution &defaultResolution, prdfFilter * i_fltr = NULL);

  /*
   Destructor - compiler default is ok
   */
  //~prdfprdfResolutionMap();

  // DRGDRG - Should we be returning a ResolutionList? or get rid of Default & use no bits on key???
  /**
   Get the default resolution for this map
   @returns a reference to the default resolution
   @pre None
   @post None
   */
  prdfResolution & GetDefault(void) const;

  /**
   Replace the default Resolution
   @param Reference to new default resolution
   */
  void ReplaceDefaultWith(prdfResolution & r);

  /**
   Add a key,Resolution pair
   @param i_bitPos - bit position
   @param 1 to 6 Resolutions
   */
  void Add(uint8_t i_bitPos,
           prdfResolution * i_res );
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2);
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2, prdfResolution * i_r3);
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2, prdfResolution * i_r3,
           prdfResolution * i_r4);
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2, prdfResolution * i_r3,
           prdfResolution * i_r4, prdfResolution * i_r5);
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2, prdfResolution * i_r3,
           prdfResolution * i_r4, prdfResolution * i_r5, prdfResolution * i_r6);
  void Add(uint8_t i_bitPos,
           prdfResolution * i_r1, prdfResolution * i_r2, prdfResolution * i_r3,
           prdfResolution * i_r4, prdfResolution * i_r5, prdfResolution * i_r6,
           prdfResolution * i_r7);

  /**
   Add a key,prdfResolution pair
   @param i_ble - bit list encoding  (array of bitPos)
   @param i_bleLen length of bit list
   @param 1 to 6 prdfResolutions
   */
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * res );
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * r1, prdfResolution * r2);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4, prdfResolution * r5);
  void Add(const uint8_t *i_ble, uint8_t i_bleLen,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4, prdfResolution * r5, prdfResolution * r6);


  //! Old Add interface
  /*!
   */
  void Add(const char *i_ble,
           prdfResolution * res );
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2);
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2, prdfResolution * r3);
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
           prdfResolution * r4);
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
           prdfResolution * r4, prdfResolution * r5);
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
           prdfResolution * r4, prdfResolution * r5, prdfResolution * r6);
  void Add(const char *i_ble,
           prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
           prdfResolution * r4, prdfResolution * r5, prdfResolution * r6,
           prdfResolution * r7);

  void AddRange(const char *i_ble,prdfResolution * res ) { Add(i_ble,res); }
  void AddRange(const char *i_ble,prdfResolution * r1, prdfResolution * r2) { Add(i_ble,r1,r2); }
  void AddRange(const char *i_ble,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3) { Add(i_ble,r1,r2,r3); }
  void AddRange(const char *i_ble,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4) { Add(i_ble,r1,r2,r3,r4); }
  void AddRange(const char *i_ble,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4, prdfResolution * r5) { Add(i_ble,r1,r2,r3,r4,r5); }
  void AddRange(const char *i_ble,
                prdfResolution * r1, prdfResolution * r2, prdfResolution * r3,
                prdfResolution * r4, prdfResolution * r5, prdfResolution * r6) { Add(i_ble,r1,r2,r3,r4,r5,r6); }
  /**
   Look up a prdfResolution for a bitlist
   @param bitList
   @returns List of all prdfResolutions that match
   @pre none
   @post prdfResolution returned is only valid until the next call to LookUp or this object is destroyed.
   i_bitList may be modified
   @notes if the bitList does not have a match then the defaultprdfResolution is returned.
   */
  void LookUp(prdfResolutionList & o_list, prdfBitKey & io_bitList, STEP_CODE_DATA_STRUCT & scd); //dg04c

  /**
   * @brief Get the stored filter associated with this resolution map.
   * @returns Currently assigned filter.
   */
  prdfFilter * getFilter() { return iv_filter; };

  /**
   * @brief Store a new filter with this resolution map.
   * @param i - Filter to store.
   */
  void setFilter(prdfFilter * i) { iv_filter = i; };

protected:  // functions

private: // functions

  /*!
   Copy prohibited
   */
  prdfResolutionMap(const prdfResolutionMap &);   // Don't allow copy - No defn

  /*!
   Assignment prohibited
   */
  const prdfResolutionMap &operator=(const prdfResolutionMap &); // Don't allow - no defn

private: // Data

  struct RmPair
  {
    prdfBitKey iv_blist;
    prdfResolution * iv_res;
    RmPair(uint8_t i_bitPos, prdfResolution *res) : iv_blist(i_bitPos), iv_res(res) {}
    RmPair(void) : iv_blist(), iv_res(NULL) {}
  };

  typedef std::vector<RmPair> MapList;

  prdfResolution * defaultRes;
  prdfFilter     * iv_filter;

  MapList iv_list;
//  MapList iv_rangeList;

};

inline prdfResolutionMap::prdfResolutionMap(int32_t entryCount,
                                            prdfResolution & defaultResolution,
                                            prdfFilter * i_fltr)
: defaultRes(&defaultResolution), iv_filter(i_fltr), iv_list()
{
  iv_list.reserve(entryCount);
}

inline  prdfResolution & prdfResolutionMap::GetDefault(void) const {return *defaultRes; }
inline  void prdfResolutionMap::ReplaceDefaultWith(prdfResolution & r) { defaultRes = &r; }

#endif /* prdfResolutionMap_h */

// Change Log *************************************************************************************
//
//  Flag Reason   Vers    Date     Coder     Description
//  ---- -------- ------- -------- -------- -------------------------------------------------------
//              v4r1mo    05/02/96  DRG      Initial Creation
//       D49203.5 v4r3    07/30/97  DRG      Add Add() for multiple resolutions
//                fips    03/02/04 dgilbert  Changes the way lookups are done
//       482244   fips225 11/04/04 dgilbert  Add filter
//         F544848  f300    04/03/06 iawillia  Add multi-bit support for rule code
//  dg04 568068   f310    08/29/06 dgilbert  Add STEP_CODE_DATA_STRUCT to LookUp
// End Change Log *********************************************************************************
