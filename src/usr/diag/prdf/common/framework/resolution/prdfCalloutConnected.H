/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutConnected.H $ */
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

#ifndef PRDFCALLOUTCONNECTED_H
#define PRDFCALLOUTCONNECTED_H
/**
   @file prdfCalloutConnected.H
   @brief A resolution to callout a connected MRU determined at the time of the error.
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipResolution.h>
#include <prdfPlatServices.H>
#include <prdfCallouts.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;

/**
    This resolution calls out a connected MRU.
    @author Doug Gilbert
    @par
      This resolution calls out a connected MRU, but waits until the time of the error
      to determine whats connected.  This allows for runtime GARD, dynamic failover and concurrent
      maintainance - without having to call PRD to re-build itself.
    @code
     prdfCalloutConnected iv_callout(PROC, TYPE_MCS ....);
     // ......
     // This will add the MCSs thats connected to this PROC to the callout list
     iv_callout.Resolve(serviceData);
    @endcode
    @note Don't use this class to callout clocks - use prdfClockResolution
*/
class prdfCalloutConnected : public Resolution
{
public:
  /**
   default ctor
   */
  prdfCalloutConnected(void);

  /**
   Constructor
   @param       i_psourceHandle             handle of  connection source
   @param       i_targetType                type of desired unit that's connected to i_psourceHandle
   @param       i_idx                       index into getConnected list to callout
                                            (i_idx = 0xffffffff means callout the first valid target)
   @param       i_priority                  callout priority  @see srci.H for priority values
   @param       i_altResolution             to use if the connection does not exist or is invalid.
                                            If NULL than source is called out
   @note Don't use this class to callout clocks - use prdfClockResolution
   */
  prdfCalloutConnected(TARGETING::TargetHandle_t i_psourceHandle,
                       TARGETING::TYPE i_targetType,
                       uint32_t i_idx =0xffffffff ,
                       PRDF::PRDpriority i_priority = PRDF::MRU_MED,
                       Resolution * i_altResolution = NULL);

  // ~prdfCalloutConnected(); default dtor is sufficient

  /**
   Determine callout for current connected unit and add to the service data
   @param service data collector
   @pre None
   @post service_data is complete
   @return SUCCESS | non-zero
   @note if the call to getConnected yeilds an invalid homId than the altResolution is called. If the
         altResolution is NULL than the source is added to the callout list.
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & io_service_data);

  virtual bool operator==(const prdfCalloutConnected & r) const;

private:  // functions
private:  // Data

  TARGETING::TargetHandle_t iv_psourceHandle;
  TARGETING::TYPE iv_targetType;
  uint32_t iv_idx;
  PRDF::PRDpriority iv_priority;
  Resolution * iv_altResolution;
};

inline prdfCalloutConnected::prdfCalloutConnected(void)
: iv_psourceHandle(NULL),
  iv_targetType(TARGETING::TYPE_NA),
  iv_idx(0xffffffff ),
  iv_priority(PRDF::MRU_LOW),
  iv_altResolution(NULL)
{}

inline prdfCalloutConnected::prdfCalloutConnected(TARGETING::TargetHandle_t i_psourceHandle,
                                                  TARGETING::TYPE i_targetType,
                                                  uint32_t i_idx,
                                                  PRDF::PRDpriority i_priority,
                                                  Resolution * i_altResolution)
: iv_psourceHandle(i_psourceHandle),
  iv_targetType(i_targetType),
  iv_idx(i_idx),
  iv_priority(i_priority),
  iv_altResolution(i_altResolution)
{}

inline bool prdfCalloutConnected::operator==(const prdfCalloutConnected & r) const
{
  return (iv_psourceHandle == r.iv_psourceHandle &&
          iv_targetType == r.iv_targetType &&
          iv_idx == r.iv_idx &&
          iv_priority == r.iv_priority &&
          (iv_altResolution == r.iv_altResolution || &iv_altResolution == &r.iv_altResolution));
}

#endif /* PRDFCALLOUTCONNECTED_H */
