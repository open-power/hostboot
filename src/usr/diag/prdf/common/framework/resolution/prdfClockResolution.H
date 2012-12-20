/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfClockResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#ifndef prdfClockResolution_H
#define prdfClockResolution_H
// Class Description *************************************************
//
//  Name:  ClockResolution
//  Base class: Resolution
//
//  Description: Set dump information in Service Data Collector
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#include <prdfPlatServices.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class ServiceDataCollector;

/**
 Set dump information in the Service Data Collector
 @author Mike Kobler
 */
class ClockResolution : public Resolution
{
public:
  /**
   * @brief     constructor
   * @param[in] i_pTargetHandle  target pointer for clock source
   * @param[in] i_targetType  type of target connected to clock source
   * @return    Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    // FIXME: The default target type needs to be set to a PROC clock card.
    ClockResolution( TARGETING::TargetHandle_t i_pTargetHandle = NULL,
                         TARGETING::TYPE i_targetType = TARGETING::TYPE_PROC ) :
                         iv_ptargetClock( i_pTargetHandle ),
                         iv_targetType( i_targetType )
    { }

  /**
   * @brief     Resolve by adding MRU callout to the service data collector
   * @param[io] io_data Reference to STEP_CODE_DATA_STRUCT
   * @return    Non-SUCCESS if an internal function fails, SUCCESS otherwise
  */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_data );

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator==(const ClockResolution & r) const
  {
    return ( ( iv_ptargetClock == r.iv_ptargetClock ) &&
             ( iv_targetType == r.iv_targetType ) );
  }

private:  // functions
private:  // Data

  TARGETING::TargetHandle_t iv_ptargetClock;
  TARGETING::TYPE iv_targetType ;
};

} // end namespace PRDF

#endif /* prdfClockResolution_H */

