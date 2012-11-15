/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdf_ras_services.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2012              */
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

#ifndef PRDF_RAS_SERVICES_H
#define PRDF_RAS_SERVICES_H
/**
   @file prdf_ras_services.H
   @brief Description
*/

#include <xspprdService.h>
#include <errlentry.H>
#include <iipServiceDataCollector.h>

#ifndef __HOSTBOOT_MODULE
  #include <tmgt.H>
  #include <prdfPfa5Data.h>   //for prdfPfaCalloutListStruct
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
        savedLatentSdc(false),
        serviceActionCounter(0),
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
      @brief Set the TOD of the current error and check for latent Machine check
      @param[in] the_attention (see iipsdbug.h)
      @param[in,out] is_latent [true | false]
      @param[in,out] sdc
      @pre None.
      @post Error timestamped with TOD, latency state modifed
      @note Uses the SPC interface to get the TOD
      */
    virtual void SetErrorTod(ATTENTION_TYPE the_attention,bool *is_latent,ServiceDataCollector & sdc);

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
    void AddCapData(ServiceDataCollector & i_sdc, errlHndl_t i_errHdl);

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

  private:

    bool loggingBufferFull;
    bool latentMachineCheck;
    bool savedLatentSdc;

    uint32_t serviceActionCounter;

    int32_t savedPrdReturnCode;

    ServiceDataCollector sdc;
    ServiceDataCollector latentSdc;

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
   @brief Set the TOD of the current error and check for latent Machine check
   @param[in] the_attention (see iipsdbug.h)
   @param[in,out] is_latent [true | false]
   @param[in,out] sdc
   @pre None.
   @post Error timestamped with TOD, latency state modifed
   @note Uses the SPC interface to get the TOD
   */
  virtual void SetErrorTod(ATTENTION_TYPE the_attention,bool *is_latent,ServiceDataCollector & sdc);

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
  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type, ServiceDataCollector & sdc); //mp01 c

#ifndef __HOSTBOOT_MODULE
  /**
   @brief Add Trace Data to File for Manufacturing.
   @param[in] ErrorSignature
   @return None.
   @pre None.
   @post None.
   @exception None.
   */
  void MnfgTrace(ErrorSignature * l_esig);
#endif

  static void SetTerminateOnCheckstop(bool setting)
  {
      ErrDataService::SetTerminateOnCheckstop(setting);
  }


private:  // Data

  // actual or sim err data service
  ErrDataService * iv_ErrDataService;

};

} // End namespace PRDF

#endif // PRDF_RAS_SERVICES_H
