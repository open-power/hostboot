/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipServiceDataCollector.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

#include <prdfErrorSignature.H>
#include <iipCaptureData.h>
#include <vector>
#include <time.h>
#include <prdfCallouts.H>
#include <prdfMain.H>
#if !defined(PRDFTIMER_H)
#include <prdfTimer.H>
#endif
#include <xspprdGardResolution.h>     // for ErrorType
#include <prdfAssert.h>
#if( !defined(CONTEXT_x86_nfp) && !defined(_NFP) ) //only for ppc context (@54)
#include <prdfPlatServices.H>
#include <iipsdbug.h>
#endif

#ifdef __HOSTBOOT_MODULE
#include <prdfGlobal.H>
#else
#include <hdctContent.H>
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

struct SignatureList
{
    TARGETING::TargetHandle_t target;
    uint32_t                  signature;

    SignatureList() : target(NULL), signature(0) {}

    SignatureList( TARGETING::TargetHandle_t i_target, uint32_t i_signature ) :
        target(i_target), signature(i_signature)
    {}
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
    PRDF_SDC_FLAG(DONT_SAVE_SDC,           0x80000)
    PRDF_SDC_FLAG(USING_SAVED_SDC,         0x40000)
    PRDF_SDC_FLAG(PROC_CORE_CS,            0x20000)
    //(Note UNIT_CS is intentionally the same value as PROC_CORE_CS)
    PRDF_SDC_FLAG(UNIT_CS,                 0x20000)
    PRDF_SDC_FLAG(DONT_COMMIT_ERRL,        0x01000)
    PRDF_SDC_FLAG(DUMP,                    0x00800)
    PRDF_SDC_FLAG(UERE,                    0x00400)
    PRDF_SDC_FLAG(SUE,                     0x00200)
    PRDF_SDC_FLAG(AT_THRESHOLD,            0x00080)
    PRDF_SDC_FLAG(DEGRADED,                0x00040)
    PRDF_SDC_FLAG(SERVICE_CALL,            0x00020)
    PRDF_SDC_FLAG(TRACKIT,                 0x00010)
    PRDF_SDC_FLAG(TERMINATE,               0x00008)
    PRDF_SDC_FLAG(LOGIT,                   0x00004)
    PRDF_SDC_FLAG(SECONDARY_ERRORS_FOUND,  0x00002)
  PRDF_SDC_FLAGS_MAP_END

   /** Defines Analysis pass related properties.
     * Flags defined here will be used in framework Analyze leg */
   enum AnalysisFlags
   {
       /** If this flag is set, We are mainly interested in getting signature
        *  for attention. */
       PASS_ISOLATION_ONLY = 0x01,
       /** If this flag is set, only bits not marked as secondary
        *  meaning ( primary ) are taken up for analysis. */
       PASS_PRIMARY        = 0x02,
   };
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
     * @brief  Get access to the traceArrayData object
     *
     * @Return TraceArray Data
     */
    CaptureData & getTraceArrayData() {return iv_traceArrayData;}

  /**
   Add a mru to the Callout list
   <ul>
   <br><b>Parameters:  </b> a valid PRDcallout & PRDpriority
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> getMruList().GetCount()++
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
     * @brief Add input signature to signature list.
     * @param i_sig Signature Object.
     * @note  This is a costly operation as it uses reverse lookup from HUID
     *        to target handle. If possible, use another variant of this
     *        function which takes TargetHandle_t as input.
     */
    void AddSignatureList( ErrorSignature & i_sig );

    /** @return The list of MRUs currently stored in the SDC. */
    const SDC_MRU_LIST & getMruList() const { return xMruList; }

    /** @return The size of the MRU list currently stored in the SDC. */
    size_t getMruListSize() const { return xMruList.size(); }

    /** @return The secondary signature list stored in the SDC. */
    const PRDF_SIGNATURES & getSignatureList() const { return iv_SignatureList;}

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

    /**
     * @brief returns true if code is in isolation only pass.
     */
    bool IsIsolationOnlyPass(void) const { return ( ( analysisFlags &
                                        PASS_ISOLATION_ONLY )!=0 ); }
    /**
     * @brief Sets isolation only flag.
     */
    void setIsolationOnlyPass() { analysisFlags |= PASS_ISOLATION_ONLY ;}

    /**
     * @brief Clears isolation only flag.
     */
    void clearIsolationOnlyPass() { analysisFlags &= !PASS_ISOLATION_ONLY ;}

    /**
     * @brief Returns true if it is a primary analysis phase, false otherwise.
     */
    bool isPrimaryPass(void) const
    { return ( ( analysisFlags & PASS_PRIMARY ) != 0 ) ; }
    /**
     * @brief sets status bit meant for primary analysis pass.
     */
    void setPrimaryPass() { analysisFlags |= PASS_PRIMARY ; }

    /**
     * @brief clears status bit meant for primary analysis pass.
     */
    void clearPrimaryPass() { analysisFlags &= ~PASS_PRIMARY; }

  /**
   Set ErrorType for Gard
   <ul>
   <br><b>Parameter    </b> GardAction::ErrorType
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None
   <br><b>Promises     </b> QueryRepeatGard() == et
   <br><b>Notes:       </b>
   </ul><br>
   */
  void Gard(GardAction::ErrorType et) { errorType = et; }

  /**
   Query for RepeatGard ErrorType
   <ul>
   <br><b>Paramters    </b> None.
   <br><b>Returns:     </b> GardAction::ErrorType
   <br><b>Requirements:</b> SetAttentionType()
   <br><b>Promises     </b> ErrorType set by Gard or NoGard
   <br><b>Notes:       </b>
   </ul><br>
   */
  GardAction::ErrorType QueryGard(void);

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

  /** Is a Proc Core CS flag on? */
  bool IsProcCoreCS (void) const { return (flags & PROC_CORE_CS) != 0 ? true:false; }

  /** Is a Unit CS flag on? */
  bool IsUnitCS (void) const { return (flags & UNIT_CS) != 0 ? true:false; }

  /** Is a Using Saved SDC on? */
  bool IsUsingSavedSdc (void) const { return (flags & USING_SAVED_SDC) != 0 ? true:false; }

  /**
   * @brief     sets flag indicating only secondary error  bit is set in FIR
   */
   void setSecondaryErrFlag( ) { flags |= SECONDARY_ERRORS_FOUND; }

  /**
   * @brief     clears flag indicating only secondary error  bit is set in FIR
   */
   void clearSecondaryErrFlag() { ( flags &= ~SECONDARY_ERRORS_FOUND ); }
   /**
    * @brief    returns true if there is only secondary error.
    * @return   true if secondary is found false otherwise.
    */
   bool isSecondaryErrFound() const
   { return ( ( flags & SECONDARY_ERRORS_FOUND ) != 0 ); }

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

  hwTableContent ivDumpRequestContent;

  ErrorSignature     error_signature;
  CaptureData        captureData;

  // This is used to hold L2/L3/NX trace array data.
  // We need to separate this out from above scom
  // reg captureData in case system runs out of errl
  // storage space and truncates our logs.
  CaptureData        iv_traceArrayData;
  SDC_MRU_LIST       xMruList;          // dg07
  PRDF_SIGNATURES    iv_SignatureList; // jl00
  uint32_t           maskId;
  ATTENTION_TYPE     attentionType;    // MCK,REC,SPCL

  uint32_t       flags;        //mp01 c from  uint16_t
  uint8_t       hitCount;
  uint8_t       threshold;
  uint8_t       analysisFlags;
  TARGETING::TargetHandle_t   startingPoint;
  GardAction::ErrorType errorType;
  Timer ivCurrentEventTime;
  TARGETING::TargetHandle_t ivpDumpRequestChipHandle;
  ATTENTION_TYPE causeAttentionType;    // MCK,REC,SPCL

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

  /**
   * @brief       get Target pointer pertaining to RuleChip under analysis
   * @return      target pointer
   * @note        Should be called only in Analyze leg of code
   */

   static TARGETING::TargetHandle_t  getTargetAnalyzed( );

// --------------------------------------
// FSP only functions begin
// --------------------------------------

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
  void SetDump( hwTableContent iDumpRequestContent,
                TARGETING::TargetHandle_t iDumpRequestChipHandle = NULL )
  {
    SetFlag(DUMP);
    ivDumpRequestContent = iDumpRequestContent;
    ivpDumpRequestChipHandle = iDumpRequestChipHandle;
  }

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
  void GetDumpRequest(  hwTableContent & oDumpRequestContent,
                        TARGETING::TargetHandle_t&
                        opDumpRequestChipHandle ) const
  {
    oDumpRequestContent = ivDumpRequestContent;
    opDumpRequestChipHandle = ivpDumpRequestChipHandle;
  }

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
