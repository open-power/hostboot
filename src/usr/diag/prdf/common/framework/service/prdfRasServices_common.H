/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfRasServices_common.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
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

#ifndef __prdfRasServices_common_H
#define __prdfRasServices_common_H

/** @file  prdfRasServices_common.H
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

#include <xspprdService.h>
#include <errlentry.H>
#include <iipServiceDataCollector.h>
#include <prdfPfa5Data.h>

#ifndef __HOSTBOOT_MODULE
  #include <tmgt.H>
#endif

namespace PRDF
{

#ifndef __HOSTBOOT_MODULE
  const uint32_t thermalCalloutMax = 4;
  const uint32_t sdcBufferSize = CaptureDataSize + 200;
#endif

enum sdcSaveFlagsEnum
{
    SDC_NO_SAVE_FLAGS           = 0x00,
    SDC_ANALYSIS_SAVE_FLAG      = 0x08,
    SDC_THERMAL_SAVE_FLAG       = 0x04,
    SDC_SAVE_UE_FLAG            = 0x02,
    SDC_SAVE_SUE_FLAG           = 0x01
};

class ErrDataService
{
  public:

    /**
     * @brief ctor
     */
    inline ErrDataService() :
        loggingBufferFull(false),
        iv_serviceActionCounter(0),
        savedPrdReturnCode(0)
    {}

    /**
     * @brief dtor
     */
    inline virtual ~ErrDataService() {}

    /**
     * @brief initializer
     */
    virtual void Initialize();

    /**
     @brief Create an SRC, PFA data, and Error log for the ServiceData provided
     @param[in] attn_type  (see iipsdbug.h)
     @param[in,out] sdc  (see iipServiceData.h)
     @return Error Log - Null if successfully committed
     @pre SetErrorTod()?
     @post Error log(s) build and logged, SRC built, etc.
     @exception None.
     @note
     */
    virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type, ServiceDataCollector & sdc);

    /**
      @brief Set the TOD of the current error
      @param[in] the_attention (see iipsdbug.h)
      @param[in,out] sdc
      @pre None.
      @post Error timestamped with TOD, latency state modifed
      @note Uses the SPC interface to get the TOD
      */
    virtual void SetErrorTod( ATTENTION_TYPE the_attention,
                              ServiceDataCollector & sdc );

    /**
      @brief Query if logging buffer full - indicates attention flooding
      @return [true | false]
      @pre None.
      @post None.
      */
    virtual bool QueryLoggingBufferFull(void) const;

    /**
      @brief Save a return code for inclusion in the SRC (something failed)
      @param[in] a return code
      @return none.
      @pre None.
      @post Rc stored
      */
    virtual void SaveRcForSrc(int32_t the_rc);

    /**
      @brief Add the Service Data Collector Capture Data to the User Data of the Error Log.
      @param[in] Service Data Collector
      @param[in,out] Error Log
      @return None.
      @pre None.
      @post None.
      @exception None.
      */
    static void AddCapData( CaptureData & i_cd, errlHndl_t i_errHdl);

    static void SetTerminateOnCheckstop(bool setting)
    {
        terminateOnCheckstop = setting;
    }

  private:

    /**
     * @brief disable copy
     */
    ErrDataService(const ErrDataService &);

    /**
     * @brief disable assignment
     */
    ErrDataService & operator=(const ErrDataService &);

    #ifndef __HOSTBOOT_MODULE

    /**
     @brief Write the Flattened SDC to a File to save for later use. Will also
     immediate sync the File to the Redundant FSP. Update Registry
     value with UE or SUE save status. Note, the Registry is immediately
     synced to the Redundand FSP automatically.
     @param[in] sdcSaveFlagsEnum
     @param[in,out] sdc  (see iipServiceData.h)
     @return return FALSE if success and TRUE if failure
     @pre None.
     @post None.
     @exception None.
     @note
     */
    bool SdcSave(sdcSaveFlagsEnum i_saveFlag, ServiceDataCollector & i_saveSdc);

    /**
      @brief Read the Flattened SDC File based on the sdc Save Flag input.
      @param[in] sdcSaveFlagsEnum
      @param[in,out] buffer data is output to
      @return return FALSE if success and TRUE if failure
      @pre None.
      @post None.
      @exception None.
      @note
      */
    bool SdcRetrieve(sdcSaveFlagsEnum i_saveFlag, void * o_buffer);

    #endif // end if not __HOSTBOOT_MODULE

    /**
     * @brief Add trace data to file for Manufacturing.
     * @param i_esig    Error signature.
     * @param i_pfaData The PFA data.
     */
    void MnfgTrace( ErrorSignature * i_esig, const PfaData & i_pfaData );

    /**
     * @brief Initializes the PFA data.
     * @param i_sdc      The service data collector.
     * @param o_pfa      The PFA data struct.
     * @param o_dumpTrgt The DUMP target.
     */
    void initPfaData( ServiceDataCollector & i_sdc,
                      uint32_t i_attnType, bool i_deferDeconfig,
                      uint32_t i_errlAct, uint32_t i_errlSev,
                      uint32_t i_prdGardType,
                      PfaData & o_pfa, TARGETING::TargetHandle_t & o_dumpTrgt );

    /**
     * @brief Prints debug traces
     */
    void printDebugTraces();

  private:

    bool loggingBufferFull;

    uint32_t iv_serviceActionCounter;

    int32_t savedPrdReturnCode;

    ServiceDataCollector sdc;

    static bool terminateOnCheckstop;

};

/**
 Interface to RAS services provided to PRD
*/
class RasServices: public ServiceGeneratorClass
{
public:

  /**
   @brief Default ctor
   */
  RasServices(void);

  /**
   @brief Default dtor
   */
  ~RasServices();

  // Compiler generated dtor is sufficient

  virtual void Initialize();

  /**
   * @brief set the err data service to be used
   *
   * @param[in] i_ErrDataService new err data service
   */
  virtual void setErrDataService(ErrDataService & i_ErrDataService);

  /**
   @brief Set the TOD of the current error and check for Machine check
   @param[in] the_attention (see iipsdbug.h)
   @param[in,out] sdc
   @pre None.
   @post Error timestamped with TOD, latency state modifed
   @note Uses the SPC interface to get the TOD
   */
  virtual void SetErrorTod( ATTENTION_TYPE the_attention,
                            ServiceDataCollector & sdc );

  /**
   @brief Query if logging buffer full - indicates attention flooding
   @param none.
   @return [true | false]
   @pre None.
   @post None.
   */
  virtual bool QueryLoggingBufferFull(void) const;

  /**
   @brief Save a return code for inclusion in the SRC (something failed)
   @param[in] a return code
   @return none.
   @pre None.
   @post Rc stored
   */
  virtual void SaveRcForSrc(int32_t the_rc);

  /**
   @brief Create an SRC, PFA data, and Error log for the ServiceData provided
   @param[in] attn_type  (see iipsdbug.h)
   @param[in,out] sdc  (see iipServiceData.h)
   @return Error Log - Null if successfully committed
   @pre SetErrorTod()?
   @post Error log(s) build and logged, SRC built, etc.
   @exception None.
   */
  virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE attn_type,
                                    ServiceDataCollector & sdc );

  static void SetTerminateOnCheckstop(bool setting)
  {
      ErrDataService::SetTerminateOnCheckstop(setting);
  }


private:  // Data
  // actual or sim err data service
  ErrDataService * iv_ErrDataService;

};

} // End namespace PRDF

#endif // __prdfRasServices_common_H
