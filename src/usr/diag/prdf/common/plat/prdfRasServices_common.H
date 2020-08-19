/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfRasServices_common.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <hwas/common/hwasCallout.H>

namespace PRDF
{

#ifndef __HOSTBOOT_MODULE
  const uint32_t sdcBufferSize = CaptureDataSize + 200;
#endif

enum sdcSaveFlagsEnum
{
    SDC_NO_SAVE_FLAGS           = 0x00,
    SDC_ANALYSIS_SAVE_FLAG      = 0x08,
};

class ErrDataService
{
  public:

    /** @brief Constructor */
    ErrDataService() :
        iv_serviceActionCounter(0),
        iv_errl(nullptr)
    {}

    /** @brief Destructor */
    virtual ~ErrDataService() {}

    /** @brief Initializer */
    virtual void Initialize();

    /**
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  io_sdc     Target SDC.
     * @return A non-nullptr error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & io_sdc );

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
     * @brief Creates the initial error log for PRDF::main() analysis path.
     * @param i_attnType Analysis attention type.
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
     * @note   For normal analysis paths only. Will return nullptr if
               createInitialErrl() has not been called in PRDF::main().
     * @return An error log.
     */
    errlHndl_t getErrl() const { return iv_errl; }

  private:

    /** @brief Disable copy. */
    ErrDataService(const ErrDataService &);

    /** @brief Disable assignment. */
    ErrDataService & operator=(const ErrDataService &);

    /**
     * @brief Initializes the PFA data.
     * @param i_sdc      The service data collector.
     * @param o_pfa      The PFA data struct.
     * @param o_dumpTrgt The DUMP target.
     */
    void initPfaData( const ServiceDataCollector & i_sdc,
                      uint32_t i_attnType, bool i_deferDeconfig,
                      uint32_t i_errlAct, uint32_t i_errlSev,
                      uint32_t i_prdGardType,
                      PfaData & o_pfa, TARGETING::TargetHandle_t & o_dumpTrgt );

    /**
     * @brief Adds a callout to the PFA data MRU list.
     * @param io_pfa     The PFA data struct.
     * @param i_callout  Target callout.
     * @param i_priority Target callout priority.
     * @param i_gardType Target callout GARD type.
     */
    void addCalloutToPfaData( PfaData & io_pfa,
                              PRDcallout i_callout, PRDpriority i_priority,
                              HWAS::GARD_ErrorType i_gardType );

    /**
     * @brief Deallocate DIMMS represented in mru list.
     *
     * This function will get all DIMMS behind MCS, MEMBUF, MBA
     * in callout list. It will find unique DIMMS per DIMM pair
     * and send message to PHYP to deallocate memory behind these DIMMS.
     *
     * @param i_mruList   MRU callout list.
     */
    void deallocateDimms( const SDC_MRU_LIST & i_mruList );

    /**
     * @brief Checks for terminate conditions during non mnfg conditions.
     * @param i_sdc       The service data collector.
     * @param i_dumpTrgt  Dump Target.
     * @param io_pfa      The PFA data struct.
     * @return  True if PRD should terminate system, False otherwise.
     */
    bool checkForceTerm( const ServiceDataCollector & i_sdc,
                         TARGETING::TargetHandle_t i_dumpTrgt,
                         PfaData &io_pfaData );

    /**
     * @brief commits error log based on platform.
     * @param io_errl       reference to error log handle.
     * @param i_pfaData     Pfa struct
     */
    void commitErrLog( errlHndl_t & io_errl, const PfaData & i_pfaData );

  private:

    uint32_t iv_serviceActionCounter;

    errlHndl_t iv_errl;

};

/** Interface to RAS services provided to PRD */
class RasServices : public ServiceGeneratorClass
{
  public:

    /** @brief Constructor */
    RasServices();

    /** @brief Destructor */
    ~RasServices();

    /** @brief Initializer */
    virtual void Initialize();

    /**
     * @brief Sets the ErrDataService to be used.
     * @param i_eds Target ErrDataService.
     */
    virtual void setErrDataService( ErrDataService & i_eds );

    /**
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  io_sdc     Target SDC.
     * @return A non-nullptr error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & io_sdc );

    /**
     * @brief Creates the initial error log for PRDF::main() analysis path.
     * @param i_attnType Analysis attention type.
     */
    virtual void createInitialErrl( ATTENTION_TYPE i_attnType );

    /**
     * @brief  Return error log associated with current analysis flow.
     * @note   For normal analysis paths only. Will return nullptr if
               createInitialErrl() has not been called in PRDF::main().
     * @return An error log.
     */
    virtual errlHndl_t getErrl() const;

  private: // instance variables

    ErrDataService * iv_eds; ///< Actual or simulated ErrDataService.

};

} // End namespace PRDF

#endif // __prdfRasServices_common_H
