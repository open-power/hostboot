/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutConnected.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

namespace PRDF
{

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
     CalloutConnected iv_callout(PROC, TYPE_MCS ....);
     // ......
     // This will add the MCSs thats connected to this PROC to the callout list
     iv_callout.Resolve(serviceData);
    @endcode
    @note Don't use this class to callout clocks - use prdfClockResolution
*/
class CalloutConnected : public Resolution
{
public:
  /**
   default ctor
   */
  CalloutConnected(void);

  /**
   * @brief       Constructor
   * @param[in]   i_targetType      type of desired unit that's connected to
   *                                i_psourceHandle
   * @param[in]   i_idx             index into getConnected list to callout
   *                                (i_idx = 0xffffffff means callout the first
   *                                valid target)
   * @param[in]   i_priority        callout priority  @see srci.H for priority
   *                                values
   * @param[in]   i_altResolution   to use if the connection does not exist or
   *                                is invalid.
   *                                If NULL than source is called out
   * @note        Don't use this class to callout clocks - use ClockResolution
   */
  CalloutConnected( TARGETING::TYPE i_targetType,
                    uint32_t i_idx =0xffffffff ,
                    PRDpriority i_priority = MRU_MED,
                    Resolution * i_altResolution = NULL );

  // ~CalloutConnected(); default dtor is sufficient

  /**
   * @brief     calls out the target connected to target under analysis.
   * @param[io] io_service_data  Reference to STEP_CODE_DATA_STRUCT
   * @post      service_data is complete
   * @return    SUCCESS | non-zero
   * @note      if the call to getConnected yields an invalid  target then
   *            altResolution is called. If the altResolution is NULL than the
   *            source is added to the callout list.
   */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_service_data );

  virtual bool operator==(const CalloutConnected & r) const;

private:  // functions
private:  // Data

  TARGETING::TYPE iv_targetType;
  uint32_t iv_idx;
  PRDF::PRDpriority iv_priority;
  Resolution * iv_altResolution;
};

inline CalloutConnected::CalloutConnected(void)
: iv_targetType(TARGETING::TYPE_NA),
  iv_idx(0xffffffff ),
  iv_priority(MRU_LOW),
  iv_altResolution(NULL)
{}

inline CalloutConnected::CalloutConnected( TARGETING::TYPE i_targetType,
                                           uint32_t i_idx,
                                           PRDpriority i_priority,
                                           Resolution * i_altResolution ):
                                           iv_targetType( i_targetType ),
                                           iv_idx( i_idx ),
                                           iv_priority( i_priority ),
                                           iv_altResolution( i_altResolution )
{ }

inline bool CalloutConnected::operator == ( const CalloutConnected & r ) const
{
    return ( ( iv_targetType == r.iv_targetType ) && ( iv_idx == r.iv_idx ) &&
            ( iv_priority == r.iv_priority ) &&
            ( ( iv_altResolution == r.iv_altResolution ) ||
            ( &iv_altResolution == &r.iv_altResolution ) ) );
}

} // end namespace PRDF

#endif /* PRDFCALLOUTCONNECTED_H */
