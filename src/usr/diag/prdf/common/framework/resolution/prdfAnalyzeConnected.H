/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfAnalyzeConnected.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2012              */
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

#ifndef PRDFANALYZECONNECTED_H
#define PRDFANALYZECONNECTED_H
/**
   @file prdfAnalyzeConnected.H
   @brief A resolution to analyze a connected chip determined at the time of
   the error.
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipResolution.h>
#include <prdfPlatServices.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;

/**
    This resolution calls out a connected MRU.
    @author Patrick Williams
    @par
      This resolution calls out a connected chip, but waits until the time of
      the error to determine what's connected.  This allows for runtime GARD,
      dynamic failover and concurrent maintainance - without having to call
      PRD to re-build itself.
*/
class PrdfAnalyzeConnected : public Resolution
{
public:
  /**
   default ctor
   */
  PrdfAnalyzeConnected(void);

  /**
   Constructor
   @param   i_psourceHandle       target handle of connection source
   @param   i_targetType          i_targetType of desired unit that's connected to i_psourceHandle
   @param   i_idx:                index into getConnected list of chip.
   */
  PrdfAnalyzeConnected(TARGETING::TargetHandle_t i_psourceHandle ,
                       TARGETING::TYPE i_targetType,
                       uint32_t i_idx =0xffffffff );

  // ~prdfAnalyzeConnected(); default dtor is sufficient

  /**
   Determine chip object for current connected unit and call its analyze func.
   @param service data collector
   @pre None
   @return SUCCESS | non-zero if chip not found.
   @note if the call to getConnected yeilds an invalid homId than the altResolution is called. If the
         altResolution is NULL than the source is added to the callout list.
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & io_service_data);

  virtual bool operator==(const PrdfAnalyzeConnected & r) const;

private:  // functions
private:  // Data

  TARGETING::TargetHandle_t iv_psourceHandle;
  TARGETING::TYPE iv_targetType;
  uint32_t  iv_idx;
};

inline PrdfAnalyzeConnected::PrdfAnalyzeConnected(void)
                            : iv_psourceHandle(NULL),
                              iv_targetType(TARGETING::TYPE_NA),
                              iv_idx(0xffffffff)
{
}

inline PrdfAnalyzeConnected::PrdfAnalyzeConnected(
                                TARGETING::TargetHandle_t i_psourceHandle,
                                TARGETING::TYPE i_targetType,
                                uint32_t i_idx)
                                : iv_psourceHandle(i_psourceHandle),
                                iv_targetType(i_targetType),
                                iv_idx(i_idx)
{
}

inline bool PrdfAnalyzeConnected::operator==(const PrdfAnalyzeConnected & r) const
{
  return (iv_psourceHandle == r.iv_psourceHandle &&
          iv_targetType == r.iv_targetType &&
          iv_idx == r.iv_idx);
}

#endif /* PRDFANALYZECONNECTED_H */

// Change Log *****************************************************************
//
//  Flag Reason    Vers  Date     Coder    Description
//  ---- --------- ----- -------- -------- ------------------------------------
//       498293    f310  03/31/05 iawillia Initial Creation
// End Change Log *************************************************************
