/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimRasServices.H $                 */
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

#ifndef PRDFSIM_RAS_SERVICES_H
#define PRDFSIM_RAS_SERVICES_H

/** @file prdfsimRasServices.H */

#include <prdfRasServices.H>

namespace PRDF
{

/**
 Interface to RAS services provided to PRD
*/
class SimErrDataService: public ErrDataService
{

  public:

  /**
   Default ctor
   */
  inline SimErrDataService() {}

  /**
   Default dtor
   */
  inline virtual ~SimErrDataService() {}

  /**
   @brief Create an SRC, PFA data, and Error log for the ServiceData provided
   @param[in] attn_type  (see iipsdbug.h)
   @param[in,out] sdc  (see iipServiceData.h)
   @param[out] o_initiateHwudump whether or not to initiate hwudump
   @param[out] o_dumpTrgt The DUMP target.
   @param[out] o_dumpErrl The DUMP error handle
   @param[out] o_dumpErrlActions DUMP error action flags
   @return Error Log - Null if successfully committed
   @pre SetErrorTod()?
   @post Error log(s) build and logged, SRC built, etc.
   @exception None.
   */
  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type,
                                    ServiceDataCollector & sdc,
                                    bool & o_initiateHwudump,
                                    TARGETING::TargetHandle_t & o_dumpTrgt,
                                    errlHndl_t & o_dumpErrl,
                                    uint32_t & o_dumpErrlActions );

private:  // functions


private:  // Data



};

} // End namespace PRDF

#endif
