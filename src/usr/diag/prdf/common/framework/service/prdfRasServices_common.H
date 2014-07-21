/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfRasServices_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#ifndef __prdfRasServices_common_H
#define __prdfRasServices_common_H

/** @file  prdfRasServices_common.H
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

#include <xspprdService.h>
#include <errlentry.H>
#include <iipServiceDataCollector.h>
#include <prdfPfa5Data.h>

namespace PRDF
{

#ifndef __HOSTBOOT_MODULE
  const uint32_t sdcBufferSize = CaptureDataSize + 200;
#endif

enum sdcSaveFlagsEnum
{
    SDC_NO_SAVE_FLAGS           = 0x00,
    SDC_ANALYSIS_SAVE_FLAG      = 0x08,
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
        iv_serviceActionCounter(0),
        iv_errl(NULL)
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
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  i_sdc      Target SDC.
     * @param  o_initiateHwudump whether or not to initiate hwudump
     * @param  o_dumpTrgt The DUMP target
     * @param  o_dumpErrl The DUMP error handle
     * @param  o_dumpErrlActions DUMP error action flags
     * @return A non-NULL error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & i_sdc,
                                       bool & o_initiateHwudump,
                                       TARGETING::TargetHandle_t & o_dumpTrgt,
                                       errlHndl_t & o_dumpErrl,
                                       uint32_t & o_dumpErrlActions );

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

    /**
     * @brief Add trace data to file for Manufacturing.
     * @param i_esig    Error signature.
     * @param i_pfaData The PFA data.
     */
    void MnfgTrace( ErrorSignature * i_esig, const PfaData & i_pfaData );

    /**
     * @brief Create initial error log for analyze( attn analysis) code flow.
     * @param i_attnType attention type.
     */
    void createInitialErrl( ATTENTION_TYPE i_attnType );

    /**
     * @brief Update SRC section for initial error log.
     * @param i_user1    User data word 1.
     * @param i_user2    User data word 2.
     * @param i_user3    User data word 3.
     * @param i_user4    User data word 4.
     * @param i_rc       Reason code.
     */
    void updateSrc( uint32_t i_user1, uint32_t i_user2,
                    uint32_t i_user3, uint32_t i_user4,
                    uint16_t i_rc );

    /**
     * @brief  Return error log associated with current analysis flow.
     * @return error log handle.
     */
    errlHndl_t getErrl() { return iv_errl; };

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

    /**
     * @brief Deallocate DIMMS represented in mru list.
     *
     * This function will get all DIMMS behind MCS, MEMBUF, MBA
     * in callout list. It will find unique DIMMS per DIMM pair
     * and send message to PHYP to deallocate memory behind these DIMMS.
     *
     * @param i_mruList   MRU callout list.
     */
    void deallocateDimms( SDC_MRU_LIST & i_mruList );

    /**
     * @brief Must check for MP-IPL eligibility before requesting SW or SH
     *        dumps. Otherwise, the dump content will need to be changed to
     *        HWPROC.
     * @param i_attnType     Primary attention type.
     * @param i_dumpTrgt     Dump target.
     * @param io_dumpContent Dump content.
     */
    void checkMpIplEligibility( ATTENTION_TYPE i_attnType,
                                TARGETING::TargetHandle_t i_dumpTrgt,
                                hwTableContent & io_dumpContent );

    /**
     * @brief Checks for terminate conditions during non mnfg conditions.
     * @param i_sdc       The service data collector.
     * @param i_dumpTrgt  Dump Target.
     * @param io_pfa      The PFA data struct.
     * @return  True if PRD should terminate system, False otherwise.
     */
    bool checkForceTerm( ServiceDataCollector & i_sdc,
                         TARGETING::TargetHandle_t i_dumpTrgt,
                         PfaData &io_pfaData );

    /**
     * @brief Handles unit checkstops.
     * @param i_unitCsTarget chip(let) target.
     * @param o_initiateHwudump whether or not to initiate hwudump
     */
    void handleUnitCS( TARGETING::TargetHandle_t i_unitCsTarget,
                       bool & o_initiateHwudump );

    /**
     * @brief Handles Centaur checkstop.
     * @param i_memTarget memory chip(let) target.
     */
    void handleChannelFail( TARGETING::TargetHandle_t i_memTarget );

    /**
     * @brief Handles Core checkstop.
     * @param i_exTarget EX target.
     * @param o_initiateHwudump whether or not to initiate hwudump
     */
    void handleCoreUnitCS( TARGETING::TargetHandle_t i_exTarget,
                           bool & o_initiateHwudump );

    /**
     * @brief Handles NX checkstops.
     * @param i_nxTarget NX target.
     */
    void handleNxUnitCS( TARGETING::TargetHandle_t i_nxTarget );

  private:

    uint32_t iv_serviceActionCounter;

    ServiceDataCollector sdc;

    errlHndl_t iv_errl;

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
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  i_sdc      Target SDC.
     * @param  o_initiateHwudump whether or not to initiate hwudump
     * @param  o_dumpTrgt The DUMP target
     * @param  o_dumpErrl The DUMP error handle
     * @param  o_dumpErrlActions DUMP error action flags
     * @return A non-NULL error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & i_sdc,
                                       bool & o_initiateHwudump,
                                       TARGETING::TargetHandle_t & o_dumpTrgt,
                                       errlHndl_t & o_dumpErrl,
                                       uint32_t & o_dumpErrlActions );

    /**
     * @brief Create initial error log for analyze( attn analysis) code flow.
     * @param i_attnType attention type.
     */
    void createInitialErrl( ATTENTION_TYPE i_attnType )
    {
        iv_ErrDataService->createInitialErrl( i_attnType );
    }

    /**
     * @brief  Return error log associated with current analysis flow.
     * @return error log handle.
     */
    virtual errlHndl_t getErrl()
    {
        return iv_ErrDataService->getErrl();
    };

private:  // Data
  // actual or sim err data service
  ErrDataService * iv_ErrDataService;

};

} // End namespace PRDF

#endif // __prdfRasServices_common_H
