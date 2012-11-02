/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCaptureResolution.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

#ifndef iipCaptureResolution_h
#define iipCaptureResolution_h

/**
 @file iipCaptureResolution.h
 @brief CaptureResolution class definition
*/

#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#if !defined(iipCaptureData_h)
#include <iipCaptureData.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class SCAN_COMM_REGISTER_CLASS;

/**
 CaptureResolution captures the data from a scan comm register.
 @code
    // see xspmopenum.h for defn of chipIds
    class SomeChipClass {
    public:
       CaptureResolution iv_captureScr;
       CalloutResolution calloutSomething;
       ResolutionMap someResolutionMap;
    // ....
    };

    //  in SomeChipClass.C
    const int8_t SCR_ID = 0x01;

    SomeChipClass::SomeChipClass(...)
    : iv_captureScr(SPIN0_ENUM, SCR_ID, someScr),
      calloutComething(...),
      someResolutionMap(...)
    {
      // ....
      someResolutionMap.Add(BIT_LIST_STRING_10, &calloutSomething, &iv_captureScr);
      // ...
    }
 @endcode
 @see iipResolutionMap.h
*/
class CaptureResolution : public Resolution
{
public:

  /**
   Constructor
   @param chipId id of the chip - see xspmopenum.h
   @param scrRegId  developer defined 8bit id for this register
   @param scr reference to ScanCommRegister
   @param p placement of capturedatat (FRONT or BACK) see iipCaptureData.h
   @see iipCaptureData.h
   */
  CaptureResolution(uint32_t chipId,
                    uint8_t scrRegId,
                    SCAN_COMM_REGISTER_CLASS & scr,
                    CaptureData::Place p = CaptureData::BACK);

  // compiler default destructor is sufficient
  /**
   Resolve - perform the capture
   @pre none
   @post CaptureData sent to ServiceDataCollector
   @return error - ServiceDataCollector
   @return returncode [SUCCESS | mop return code]
   @No definition exist for this until we prove we need it again!
  */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

  private:  // functions
  private:  // Data

    uint32_t chid;
    SCAN_COMM_REGISTER_CLASS & xScr;
    CaptureData::Place  pos;              // FRONT || BACK
    uint8_t scrId;

};

inline
CaptureResolution::CaptureResolution(uint32_t chipId,
                                     uint8_t scrRegId,
                                     SCAN_COMM_REGISTER_CLASS & scr,
                                     CaptureData::Place p = CaptureData::BACK);
:
Resolution(),
chid(chipId),
scrId(scrRegId),
xScr(scr),
pos(p)
{}

} // end namespace PRDF

#endif /* iipCaptureResolution_h */

