/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfTimer.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef PRDFTIMER_H
#define PRDFTIMER_H
/*!
   @file prdfTimer.H
   @brief PRD timer support
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------


#if !defined(__GNUC__)
  typedef unsigned int uint32_t;

  #include <xsptodtypes.h>

  #if __IBMCPP__ < 500

    #include <bool.h>

  #endif

#endif

namespace PRDF
{
//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
    Timer
    @author Doug Gilbert
    @par A Timer holds the number of seconds since the beginning
    of the year
*/
class Timer
{
public:
  enum
  {
    SEC_IN_DAY = 86400,
    HALF_YEAR = 15768000,  //
    YEAR = 31536000  // except leap year - put we don't that kind of accuracy
//    HALF_WEEK = 302400,   // seconds in a half week
//    WEEK = 604800
  };

  struct prdftm_t
  {
      int sec;
      int min;
      int hour;
      int wday;
      int mday;
      int yday;
      int mon;
      int year;

      prdftm_t() :
      sec(0), min(0), hour(0), wday(0),
      mday(0), yday(0), mon(0), year(0) {}
      prdftm_t(int i_sec,int i_min,int i_hour,int i_wday,
                 int i_mday,int i_yday,int i_mon,int i_year) :
        sec(i_sec), min(i_min), hour(i_hour), wday(i_wday),
        mday(i_mday), yday(i_yday), mon(i_mon), year(i_year) {}
  };

  /**
   Default Constructor
   */
  Timer() :xSec(0),ivTm()
  {
  }


  /**
   Ctor from uint32 seconds since the beginning of the year
   @param seconds since the beginning of the year
   @note If seconds > seconds_in_year then reduced by seconds_in_year
   until seconds < seconds_in_year
   */
  Timer(unsigned int seconds)
    : xSec(seconds % YEAR) {}

#if !defined(__GNUC__)
  /**
   Constructor from a BIN_TIME_TYPE
   @see xsptodtypes.h
   */
  Timer(const BIN_TIME_TYPE & b)
    :xSec( b.seconds +
           (b.minutes * 60) +
           (b.hours * 3600) +
           (b.day_of_month * SEC_IN_DAY +
            month_base[b.month])
           )
  {}
#endif


  /**
   Copy Constructor
   */
  Timer(const Timer & t) : xSec(t.xSec), ivTm(t.ivTm) {}

  /**
   Assignment from another PrdTime object
   */
  const Timer & operator=(const Timer  & t)
  { xSec = t.xSec; ivTm = t.ivTm; return *this; }

#if !defined(__GNUC__)
  /**
   Assignment from a BIN_TIME_TYPE.
   @see xsptodtypes.h
   */
  const Timer & operator=(const BIN_TIME_TYPE & b)
  {
    xSec = b.seconds + (b.minutes * 60) +
      (b.hours * 3600) + (b.day_of_month*SEC_IN_DAY) + month_base[b.month];
    return *this;
  }
#else
  /**
   Assignment from a uint64
   If seconds > seconds_in_year then reduced by seconds_in_year
   until seconds < seconds_in_year
   */
  const Timer & operator=(const uint64_t & b)
  {
    xSec = b % YEAR;
    return *this;
  }
#endif

  /// equivalancy
  bool operator==(const Timer & t) const
  {
    return (xSec == t.xSec);
  }


  /**
   Greater than
   @return true if this > t2 and this - t2 < HALF_YEAR (no wrap)
   OR this < t2 and t2 - xSec > HALF_YEAR (timer wrapped)
   otherwise false
   */
  bool operator>(const Timer & t2) const
  {
    return ( ((xSec > t2.xSec) && (xSec - t2.xSec < HALF_YEAR)) ||
             ((xSec < t2.xSec) && (t2.xSec - xSec > HALF_YEAR)));
  }


  /**
   Add seconds to the timer.
   Internal timer value is wraped as needed
   */
  Timer operator+(unsigned int seconds) const
  {
    seconds = seconds % YEAR;
    seconds += xSec;
    seconds = seconds % YEAR;
    return seconds;
  }

  // diff time
  unsigned int operator-(const Timer & t) const { return (xSec - t.xSec); }

  // get seconds since the beginning of the year
  unsigned int getSec() const { return xSec; }

  // get time struct
  prdftm_t gettm() const { return ivTm; }

  // set time struct
  void settm(prdftm_t& i_tm)
  {
      ivTm = i_tm;
      xSec = ( ivTm.sec +
               (ivTm.min * 60) +
               (ivTm.hour * 3600) +
               (ivTm.yday * SEC_IN_DAY) );
  }

private:  // functions
private:  // Data

  uint32_t xSec; ///< Seconds since the beginning of the year (USA)
  prdftm_t ivTm;

#if !defined(__GNUC__)
static uint32_t month_base[12];   // # of seconds since start of year at start of month
#endif
};

#if !defined(__GNUC__)
#if defined(iipResolution_C)
uint32_t Timer::month_base[12] =
{
  0,
  SEC_IN_DAY * 31,
  SEC_IN_DAY * (31+28),
  SEC_IN_DAY * (31+28+31),
  SEC_IN_DAY * (31+28+31+30),
  SEC_IN_DAY * (31+28+31+30+31),
  SEC_IN_DAY * (31+28+31+30+31+30),
  SEC_IN_DAY * (31+28+31+30+31+30+31),
  SEC_IN_DAY * (31+28+31+30+31+30+31+31),
  SEC_IN_DAY * (31+28+31+30+31+30+31+31+30),
  SEC_IN_DAY * (31+28+31+30+31+30+31+31+30+31),
  SEC_IN_DAY * (31+28+31+30+31+30+31+31+30+31+30)
};
#endif
#endif

} //End namespace PRDF
#endif /* PRDFTIME_H */
