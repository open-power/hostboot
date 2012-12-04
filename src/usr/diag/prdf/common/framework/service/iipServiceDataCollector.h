/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipServiceDataCollector.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1998,2013              */
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

#ifndef iipServiceDataCollector_h
#define iipServiceDataCollector_h
// Class Description *************************************************
//
//  Name:  ServiceDataCollector
//  Base class: None
//
//  Description:
//  Usage:
//
// End Class Description *********************************************

#ifndef PRDF_SDC_FLAGS_MAP_ONLY
    #define PRDF_SDC_FLAGS_MAP \
        enum Flag {
    #define PRDF_SDC_FLAG(name, value) \
            name = value,
    #define PRDF_SDC_FLAGS_MAP_END \
        };
#endif

#ifndef PRDF_SDC_FLAGS_MAP_ONLY

#if !defined(ErrorSignature_h)
#include <prdfErrorSignature.H>
#endif

#if !defined(iipCaptureData_h)
#include <iipCaptureData.h>
#endif

#include <vector>
#include <time.h>

#include <prdfCallouts.H>
#include <prdfMain.H>

#if !defined(PRDFTIMER_H) // dg08
#include <prdfTimer.H>    // dg08
#endif                    // dg08

#if !defined(xspprdGardResolution_h)
#include <xspprdGardResolution.h>     // for ErrorType
#endif

#include <prdfAssert.h>
#if( !defined(CONTEXT_x86_nfp) && !defined(_NFP) ) //only for ppc context (@54)
#include <prdfPlatServices.H>
#include <iipsdbug.h>
#endif

#ifndef __HOSTBOOT_MODULE

#include <hdctContent.H>

#if( !defined(CONTEXT_x86_nfp) && !defined(_NFP) ) //only for ppc context (@54)
#include <hcdbEntryStates.H>
#include <hcdbCompSubType.H>
#include <fips_comp_id.H>
#endif

#endif
#include <list>
#include <prdfExtensibleChip.H>

namespace PRDF
{

struct SdcCallout {
  PRDcallout callout;
  PRDpriority priority;
  //bool gard;
  SdcCallout() : callout(NULL), priority(MRU_LOW) {}
  SdcCallout(PRDcallout & mru, PRDpriority p)
    : callout(mru), priority(p)
  {}
  SdcCallout(TARGETING::TargetHandle_t i_pcalloutHandle , PRDpriority p)
    : callout(i_pcalloutHandle), priority(p)
  {}
};

typedef std::vector<SdcCallout> SDC_MRU_LIST;

#ifndef __HOSTBOOT_MODULE

struct HcdbChangeItem {
  TARGETING::TargetHandle_t iv_phcdbtargetHandle ;
  hcdb::comp_subtype_t iv_compSubType;
  comp_id_t            iv_compType;
  HcdbChangeItem() : iv_phcdbtargetHandle(NULL), iv_compSubType(hcdb::LBST_ABIST) {}
  HcdbChangeItem(TARGETING::TargetHandle_t i_pTargetHandle, hcdb::comp_subtype_t i_compSubType, comp_id_t i_compType)
      : iv_phcdbtargetHandle(i_pTargetHandle), iv_compSubType(i_compSubType), iv_compType(i_compType){}
};

typedef std::vector<HcdbChangeItem> HCDB_CHANGE_LIST;

#endif

struct SignatureList {
  TARGETING::TargetHandle_t           iv_pSignatureHandle;
  uint32_t                            iv_signature;
  SignatureList() : iv_pSignatureHandle(NULL), iv_signature(0) {}
  SignatureList(TARGETING::TargetHandle_t i_pTargetHandle , uint32_t i_signature)
      : iv_pSignatureHandle(i_pTargetHandle), iv_signature(i_signature){}
};

typedef std::vector<SignatureList> PRDF_SIGNATURES;

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
 Collecter of service data
 @version fips1
 @author Douglas R. Gilbert
 */
class ServiceDataCollector
{
public:

#endif // PRDF_SDC_FLAGS_MAP_ONLY


  //mk03c
  PRDF_SDC_FLAGS_MAP        // flag positions
    PRDF_SDC_FLAG(FORCE_LATENT_CS,         0x80000)                // mp07
    PRDF_SDC_FLAG(USING_SAVED_SDC,         0x40000)                // mp05
    PRDF_SDC_FLAG(PROC_CORE_CS,            0x20000)                // mp03
    PRDF_SDC_FLAG(UNIT_CS,                 0x20000)                // mp06 a (Note this is intentionally the same value as PROC_CORE_CS)
    PRDF_SDC_FLAG(THERMAL_EVENT,           0x10000)                // pw01
    PRDF_SDC_FLAG(MP_DUMP_REQ,             0x08000)                // rc09
    PRDF_SDC_FLAG(MP_RESET_REQ,            0x04000)             // dg08
    PRDF_SDC_FLAG(MP_FATAL,                0x02000)              // dg08
    PRDF_SDC_FLAG(DONT_COMMIT_ERRL,        0x01000)        // mp02
    PRDF_SDC_FLAG(DUMP,                    0x00800)              // dg04
    PRDF_SDC_FLAG(UERE,                    0x00400)              // dg02
    PRDF_SDC_FLAG(SUE,                     0x00200)              // dg02
    PRDF_SDC_FLAG(CRUMB,                   0x00100)
    PRDF_SDC_FLAG(AT_THRESHOLD,            0x00080)
    PRDF_SDC_FLAG(DEGRADED,                0x00040)
    PRDF_SDC_FLAG(SERVICE_CALL,            0x00020)
    PRDF_SDC_FLAG(TRACKIT,                 0x00010)
    PRDF_SDC_FLAG(TERMINATE,               0x00008)
    PRDF_SDC_FLAG(LOGIT,                   0x00004)
    PRDF_SDC_FLAG(MEMORY_STEERED,          0x00002)
    PRDF_SDC_FLAG(FLOODING,                0x00001)
  PRDF_SDC_FLAGS_MAP_END

#ifndef PRDF_SDC_FLAGS_MAP_ONLY


  /**
   CTOR
   <ul>
   <br><b>Parameters:  </b> none
   <br><b>Returns:     </b> none
   <br><b>Requirements:</b> none
   <br><b>Promises:    </b> Object created
   <ul><li>             IsServiceCall() == false
   <li>                 IsAtThreshold() == false
   <li>                 terminate() == false
   <li>                 IsDegraded() == false
   <li>                 IsServiceCall() == false
   <li>                 IsMemorySteered == false
   <li>                 IsMfgTracking() == true
   <li>                 IsLogging() == true
   </ul>
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ServiceDataCollector();

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes: Default destructor is sufficient  (for now)
  //
  // End Function Specification ****************************************
  //~ServiceDataCollector();

  /**
   Get access to the error signature object
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> ErrorSignature *
   <br><b>Requirements:</b> none
   <br><b>Promises:    </b> none
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ErrorSignature * GetErrorSignature() {return(&error_signature);}

    /**
     * @brief Sets a new signature in the error signature object.
     * @param i_signature The new signature.
     */
    void SetErrorSig( uint32_t i_signature )
    {  error_signature.setSigId( i_signature );  }

  /**
   Get access to the captureData object
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> Capture Data *
   <br><b>Requirements:</b> none
   <br><b>Promises:    </b> none
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  CaptureData & GetCaptureData() {return(captureData);}

  /**
   Add a mru to the Callout list
   <ul>
   <br><b>Parameters:  </b> a valid PRDcallout & PRDpriority
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> GetMruList().GetCount()++
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> No implementation for Apache or Northstar
   </ul><br>
   */
  void SetCallout( PRDcallout mru, PRDpriority priority = MRU_MED );

  /**
   Add a change to the prd signature List
   */
  void AddSignatureList(TARGETING::TargetHandle_t i_ptargetHandle =NULL,
                          uint32_t  i_signature = 0x00000000);

  /**
   Access the list of Mrus
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> SDC_MRU_LIST
   @see MruListClass
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> No implementation for Apache or Northstar
   </ul><br>
   */
  SDC_MRU_LIST & GetMruList(void);  // dg07

  PRDF_SIGNATURES & GetSignatureList(void);  // jl00

  /**
   Clear the list of MruCallouts
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b>
   <br><b>Promises:    </b> GetCallouts().size() == 0
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void ClearCallouts(void);

  void ClearSignatureList(void);
  /**
   Query for threshold
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsAtThreshold(void) const { return (flags & AT_THRESHOLD)!=0 ? true:false; }

  /**
   Query for need to terminate is machine
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool Terminate(void) const { return (flags & TERMINATE) != 0 ? true:false; }

  /**
   Set the global attention type
   <ul>
   <br><b>Parameters:  </b> attention type.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetAttentionType() == attention,
                            If(attention == MACHINE_CHECK) IsServiceCall() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetAttentionType(ATTENTION_TYPE attention);

  /**
   Set the cause attention type
   <ul>
   <br><b>Parameters:  </b> attention type.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetCauseAttentionType() == attention
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetCauseAttentionType(ATTENTION_TYPE attention);  // rc09a

  /**
   Get the global attention type
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> Attention type [MACHINE_CHECK | RECOVERABLE | SPECIAL]
   <br><b>Requirements:</b> SetAttentionType()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ATTENTION_TYPE GetAttentionType(void) const { return attentionType; }

  /**
   Get the cause attention type
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> Attention type [MACHINE_CHECK | RECOVERABLE | SPECIAL]
   <br><b>Requirements:</b> SetCauseAttentionType()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  ATTENTION_TYPE GetCauseAttentionType(void) const { return causeAttentionType; }  // rc09a

  /**
   Set the mask id of the error to mask at threshold
   <ul>
   <br><b>Parameters:  </b> Mask id
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> GetThresholdMaskId() == mask_id,
                            IsDegraded() == true,
                            IsAtThreshold() == true,
                            IsServiceCall() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetThresholdMaskId(uint32_t mask_id);

  /**
   Query for Hardware running deraded
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsDegraded(void) const { return (flags & DEGRADED)!=0 ? true:false; }

  /**
   Get the mask ID to mask off the error when thresholding
   <ul>
   <br><b>Parameters:  </b> none
   <br><b>Returns:     </b> Mask id
   <br><b>Requirements:</b> SetThresholdMaskId(...)
   <br><b>Promises:    </b> none.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint32_t GetThresholdMaskId(void) const;

  /**
   Indicate that no tracking is needed in the manufacturing log
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> IsMfgTracking() == false
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void NoMfgTracking(void) { flags &= ~TRACKIT; }

  /**
   Query for need to track in manufacturing log
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsMfgTracking(void) const { return (flags & TRACKIT)!=0 ? true:false; }

  /**
   Indicate that no system log should be generated
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> none.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> IsLogging() == false
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void Nologging(void) { flags &= ~LOGIT; }

  /**
   Query for need to make a system error log
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsLogging(void) const { return (flags & LOGIT)!=0 ? true:false; }

    /**
     * @brief Sets flag to indicate not to commit the error log.
     */
    void DontCommitErrorLog() { flags |= DONT_COMMIT_ERRL; }

    /**
     * @brief  Queries if the 'Don't Commit Error Log' flag is on.
     * @return TRUE if DONT_COMMIT_ERRL flag is set, FALSE otherwise.
     */
    bool IsDontCommitErrl() const
    {
        #ifndef ESW_SIM_COMPILE
        return ( 0 != (flags & DONT_COMMIT_ERRL) );
        #else
        return false;
        #endif
    }

  /**
   Indicate that a service is needed
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> none.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> IsServiceCall() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetServiceCall(void) { flags |= SERVICE_CALL; }

  /**
   Query for need of a Service Call
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsServiceCall(void) const { return (flags & SERVICE_CALL)!=0 ? true:false; }

// dg12d - start
  /*
   Indicate that mainstore has had redundent memory steered in
   <ul>
   <br><b>Parameter:   </b> offset: offset in card vpd to write bitPos
   <br><b>Parameter:   </b> bitPos: bit position steered in this extent
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> IsMemorySteered() == true, this object contains
                            VPD data that needs to be transferred to VPD
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
//  void SetMemorySteered(uint32_t offset, uint32_t bitPos);

  /**
   Query for mainstore redundent steering
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetRbsVpdData() returns new data to be
                            transfered to VPD
   <br><b>Notes:       </b> Depreciated - always returns false
   </ul><br>
   */
  bool IsMemorySteered(void) const { return (flags & MEMORY_STEERED)!=0 ? true:false; }

  /*
   Get the latest RBS vpd data
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> Bitstring
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> if SetMemorySteered() has not been called or
                            IsMemorySteered() == false then this
                            returns data that indicates that nothing has
                            been steered
   </ul><br>
   */
//  const BIT_STRING_CLASS & GetRbsVpdData(void) const { return rbsVpd; }
// dg12d - end

  /**
   Indicate the chip where analysis begain
   <ul>
   <br><b>Parameters:  </b> i_pchipHandle
   <br><b>Returns:     </b> none.
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> GetStartingChip() == chid
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetStartingChip(TARGETING::TargetHandle_t i_pchipHandle)
  {
    startingPoint =  i_pchipHandle;
  }

  /**
   Get the chip id of the chip PRD picked as a starting point
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> chip id
   <br><b>Requirements:</b> SetStartingChip()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  TARGETING::TargetHandle_t GetStartingChip(void) const {return startingPoint;}

  /**
   Set the number of times this error has been seen since IPL
   <ul>
   <br><b>Parameters:  </b> hit count
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetHits() == inhits
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetHits(uint8_t inhits) { hitCount = inhits; }

  /**
   Get the number of times this error has been seen since IPL
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> hit count
   <br><b>Requirements:</b> SetHits()
   <br><b>Promises:    </b> None
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint8_t GetHits(void) const { return hitCount; }

  /**
   Indicate the threshold for this error
   <ul>
   <br><b>Parameters:  </b> threshold
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetThreshold() == inthold
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetThreshold(uint8_t inthold) { threshold = inthold; }

  /**
   Get the threshold value for this error
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> threshold value
   <br><b>Requirements:</b> SetThreshold()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> optional
   </ul><br>
   */
  uint8_t GetThreshold(void) const { return threshold; }

  //mp04 a Start
  /**
   Indicate the Reason Code (for the SRC) for this error
   <ul>
   <br><b>Parameters:  </b> reasonCode
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetReasonCode() == i_reasonCode
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetReasonCode(uint16_t i_reasonCode) { reasonCode = i_reasonCode; }

  /**
   Get the Reason Code value for this error
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> reasonCode value
   <br><b>Requirements:</b> SetReasonCode()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> optional
   </ul><br>
   */
  uint16_t GetReasonCode(void) const { return reasonCode; }
  //mp04 a Stop

  /**
   Indicate that PRD is being called faster than SP can send error logs
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> IsFlooding() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetFlooding(void) { flags |= FLOODING; }

  /**
   Query for flooding
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsFlooding(void) const { return (flags & FLOODING)!=0 ? true:false; }

  /**
   Set ErrorType for Gard
   <ul>
   <br><b>Parameter    </b> GardResolution::ErrorType
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None
   <br><b>Promises     </b> QueryRepeatGard() == et
   <br><b>Notes:       </b>
   </ul><br>
   */
  void Gard(GardResolution::ErrorType et) { errorType = et; }

  /**
   Query for RepeatGard ErrorType
   <ul>
   <br><b>Paramters    </b> None.
   <br><b>Returns:     </b> GardResolution::ErrorType
   <br><b>Requirements:</b> SetAttentionType()
   <br><b>Promises     </b> ErrorType set by Gard or NoGard
   <br><b>Notes:       </b>
   </ul><br>
   */
  GardResolution::ErrorType QueryGard(void);

  /**
   Indicate that there may be a valid "Cookie Crumb" from I/O initialization
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> None
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> MaybeCrumb() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SeekCrumb(void) { flags |= CRUMB; }

  /**
   Indicates wether service should look for a "cookie crumb" from I/O init
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> [true(1)|false(0)]
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> None
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool MaybeCrumb(void) const { return (flags & CRUMB)!=0 ? true:false;}

  // dg02 - start
  /**
   Set Error type as Special Uncorrectable Error SUE
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> IsSUE() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetSUE(void) { flags |= SUE; }

  /**
   Query for Special Uncorrectable Error (SUE)
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsSUE(void) const { return (flags & SUE)!=0 ? true:false; }

  /**
   Set Error type as Uncorrectable Recoverable Error
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> IsUERE() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetUERE(void) { flags |= UERE; }

  /**
   Query for Uncorrectable Recoverable Error (UERE)
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsUERE(void) const { return (flags & UERE)!=0 ? true:false;}

  // dg02 - end

  /**
   Set a flag
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector::Flag
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> ServiceDataCollector::Flag is true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetFlag(Flag flag) { flags |= flag ;}  //mk03a

  /**
   Get a flag
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector::Flag
   <br><b>Returns:     </b> boolean.
   <br><b>Requirements:</b> None
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool GetFlag(Flag flag) { return ((flags & flag)!=0);}


  /**
   Clear a flag
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector::Flag
   <br><b>Returns:     </b> Nothing.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> ServiceDataCollector::Flag is false
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void ClearFlag(Flag flag) { flags &= ~flag ;}  // rc09a

  // dg08 - start
  /**
   Get a PRD timer value based on the time of this error
   <ul>
   <br><b>Paramter:    </b> None
   <br><b>Returns:     </b> Timer
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  Timer GetTOE(void) { return ivCurrentEventTime; }

  /**
   Set Time of Error
   @parm set PRD timer value
   @returns nothing
   */
  void SetTOE(Timer& theTime) { ivCurrentEventTime = theTime; }

  /**
   Is this an MP Fatal error
   <ul>
   <br><b>Paramter:    </b> None
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsMpFatal(void) const { return (flags & MP_FATAL)!=0 ? true:false; }

  /**
   Is an MP Reset requested?
   <ul>
   <br><b>Paramter:    </b> None
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsMpResetReq(void) const { return (flags & MP_RESET_REQ)!=0 ? true:false; }
  // dg08 end

  /**
   Is an MP Dump requested?
   */
  bool IsMpDumpReq(void) const { return (flags & MP_DUMP_REQ) != 0 ? true:false; } // rc09a

  /** Is an Thermal Event Flag on? */
  bool IsThermalEvent(void) const { return (flags & THERMAL_EVENT) != 0 ? true:false; }

  /** Is a Proc Core CS flag on? */
  bool IsProcCoreCS (void) const { return (flags & PROC_CORE_CS) != 0 ? true:false; }

  /** Is a Unit CS flag on? */
  bool IsUnitCS (void) const { return (flags & UNIT_CS) != 0 ? true:false; }

  /** Is a Using Saved SDC on? */
  bool IsUsingSavedSdc (void) const { return (flags & USING_SAVED_SDC) != 0 ? true:false; }

  /** Is a Force Lantent Check Stop flag on? */
  bool IsForceLatentCS (void) const { return (flags & FORCE_LATENT_CS) != 0 ? true:false; }

#ifndef __HOSTBOOT_MODULE

  /**
   Flatten the service data collector
   <ul>
   <br><b>Paramter:    </b> i_buffer ptr to buffer
   <br><b>Paramter:    </b> io_size = buffer size
   <br><b>Returns:     </b> [SUCCESS(0) | returncode]; io_size = # bytes written to buffer
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> None.
   <br><b>Notes:       </b>
   return != SUCCESS means buffer size was insufficient to save enough data for reconstruction.
   return == SUCCESS means enough data is available for reconstruction, but some data could
   have been truncated if there was not enough space.
   Flattened data is network byte ordered
   </ul><br>
   */
  uint32_t Flatten(uint8_t * i_buffer, uint32_t & io_size) const;

  ServiceDataCollector & operator=(const uint8_t * i_flatdata);
  // ServiceDataCollector & operator=(const ServiceDataCollector &scd)-compiler default is sufficent

#endif

  /**
   * Get the Handle of the chip/core that detected the thermal event.
   */
  TARGETING::TargetHandle_t  GetThermalChipId() { return ivpThermalChipHandle; }; //pw01

  /**
   * Set the Handle of the chip/core that detected the thermal event.
   * @note As a side effect, the THERMAL_EVENT flag is set.
   */
  void SetThermalChipId(TARGETING::TargetHandle_t i_pchipHandle) // pw01
  {
      ivpThermalChipHandle = i_pchipHandle;
      SetFlag(THERMAL_EVENT);
  };

private:  // functions
  friend class TerminateResolution;

  /**
   Indicate that the machine should be taken down for this error
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Terminate() == true, IsServiceCall() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetTerminate(void);
  int32_t getxMRUListSizeinMem(void)const ;

private:  // Data

  #ifndef __HOSTBOOT_MODULE
  HCDB_CHANGE_LIST   iv_HcdbChangeList;
  hwTableContent ivDumpRequestContent;
  #endif

  ErrorSignature     error_signature;
  CaptureData        captureData;
  SDC_MRU_LIST       xMruList;          // dg07
  PRDF_SIGNATURES    iv_SignatureList; // jl00
  uint32_t           maskId;
  ATTENTION_TYPE     attentionType;    // MCK,REC,SPCL

  uint32_t       flags;        //mp01 c from  uint16_t
  uint8_t       hitCount;
  uint8_t       threshold;
  uint16_t       reasonCode;   //mp04
  TARGETING::TargetHandle_t   startingPoint;
// dg12d  BIT_STRING_BUFFER_CLASS rbsVpd;
  GardResolution::ErrorType errorType;
  Timer ivCurrentEventTime;
  TARGETING::TargetHandle_t ivpDumpRequestChipHandle;
  ATTENTION_TYPE causeAttentionType;    // MCK,REC,SPCL

  TARGETING::TargetHandle_t ivpThermalChipHandle;
  //RTC: 60553 Eventually we shall use hostboot implementation of stack istead
  //of std:list
  static std::list< ExtensibleChip *> cv_ruleChipStack ;
public:
  /**
   * @brief   get the rulechip  under analysis
   * @param   None
   * @return  RuleChip currently under analysis
   */
  static  ExtensibleChip* getChipAnalyzed()
  {
    return cv_ruleChipStack.back( );
  }
  /**
   * @brief   pushes the rulechip under analysis in a list
   * @param   i_analyzingChip RuleChip under analysis
   * @return  None
   */
  static void  pushChipAnalyzed( ExtensibleChip* i_analyzingChip )
  {
    cv_ruleChipStack.push_back( i_analyzingChip );
  }
  /**
   * @brief   pops the last rulechip under analysis from  list
   * @param   i_analyzingChip RuleChip under analysis
   * @return  None
   */
  static void popChipAnalyzed( )
  {
    cv_ruleChipStack.pop_back();
  }

  /**
   * @brief     Clears the list containing pointers to all the RuleChip under
   *            analysis
   */
  static void clearChipStack( )
  {
      cv_ruleChipStack.clear();
  }
// --------------------------------------
// FSP only functions begin
// --------------------------------------
#ifndef __HOSTBOOT_MODULE

  /**
    * @brief Add a change to the Hcdb Change List
    */
  void AddChangeForHcdb(TARGETING::TargetHandle_t i_ptargetHandle = NULL,//Need top level target
                        hcdb::comp_subtype_t i_testType = hcdb::SUBTYPE_NONE,
                        comp_id_t i_compType = MDIA_COMP_ID);

  HCDB_CHANGE_LIST & GetHcdbList(void);

  void ClearHcdbList(void);
#endif

  /**
   SetDump - Specifiy dump of a callout
   <ul>
   <br><b>Paramter:    </b> dumpRequestContent
   <br><b>Returns:     </b> Nothing
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> IsDump() == true
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
#ifdef __HOSTBOOT_MODULE
  void SetDump(/*FIXME: hwTableContent iDumpRequestContent,*/
               TARGETING::TargetHandle_t iDumpRequestChipHandle =NULL)
  {
    SetFlag(DUMP);
    /* FIXME: ivDumpRequestContent = iDumpRequestContent;*/
    ivpDumpRequestChipHandle = iDumpRequestChipHandle;
  }
#else
  void SetDump(hwTableContent iDumpRequestContent,
               TARGETING::TargetHandle_t iDumpRequestChipHandle =NULL)
  {
    SetFlag(DUMP);
    ivDumpRequestContent = iDumpRequestContent;
    ivpDumpRequestChipHandle = iDumpRequestChipHandle;
  }
#endif

  /**
   Has a Dump been requested
   <ul>
   <br><b>Paramter:    </b> None
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirments: </b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  bool IsDump(void) const { return (flags & DUMP)!=0 ? true:false; }

  /**
   Get the dump Id
   <ul>
   <br><b>Paramter:    </b> None
   <br><b>Return:      </b> dumpRequestType [DUMP_HARDWARE_ONLY | DUMP_HARDWARE_MAINSTORE | DUMP_NO_DUMP]
   <br><b>Return:      </b> dumpRequestContent [DUMP_HW_ABBR | DUMP_SW_ABBR]
   <br><b>Return:      </b> oDumpRequestChipId [Handle]
   <br><b>Requirments: </b> none
   <br><b>Promises:    </b> None.
   <br><b>Notes:       </b> If IsDump()==false than dumpRequestType returned is DUMP_NO_DUMP
   </ul><br>
   */
#ifdef __HOSTBOOT_MODULE
  void GetDumpRequest(  /*FIXME: hwTableContent & oDumpRequestContent,*/
                        TARGETING::TargetHandle_t&
                        opDumpRequestChipHandle) const
  {
    /*FIXME: oDumpRequestContent = ivDumpRequestContent;*/
    opDumpRequestChipHandle = ivpDumpRequestChipHandle;
  }
#else
  void GetDumpRequest(  hwTableContent & oDumpRequestContent,
                        TARGETING::TargetHandle_t&
                        opDumpRequestChipHandle) const
  {
    oDumpRequestContent = ivDumpRequestContent;
    opDumpRequestChipHandle = ivpDumpRequestChipHandle;
  }

#endif

// --------------------------------------
// FSP only functions end
// --------------------------------------

};


/**
 * @brief   limits the scope of RuleChip pointer in stack to a given scope.
 *
 * This class basically binds the scope of a given RuleChip pointer in SDC chip
 * stack to certain scope. When an instance of this class is created, RuleChip
 * is pushed to stack.In destructor,same gets popped.As a result, the scpoe of
 * this  RuleChip pointer gets tied to scope of ChipScopeLock instance.
 * PRDF_DEFINE_CHIP_SCOPE encapsulates instantiation of ScopeChipLock.

 */

#define PRDF_DEFINE_CHIP_SCOPE( ARG ) \
                                ChipScopeLock csl( ARG )
class ChipScopeLock
{
    public:
    /**
     * @brief     Constructor
     * @param     i_pChipAnalyzed    Chip for which scope is to be locked
     */
    ChipScopeLock( ExtensibleChip * i_pChipAnalyzed )
    {
        ServiceDataCollector::pushChipAnalyzed( i_pChipAnalyzed );
    }
    /**
     * @brief     Destructor
     */
    ~ChipScopeLock()
    {
        ServiceDataCollector::popChipAnalyzed( );
    }
};




} // end namespace PRDF

#include "iipServiceDataCollector.inl"

#endif // PRDF_SDC_FLAGS_MAP_ONLY

#endif /* iipServiceDataCollector_h */
