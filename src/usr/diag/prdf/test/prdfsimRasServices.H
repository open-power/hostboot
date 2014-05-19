/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimRasServices.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
   Create an SRC, PFA data, and Error log for the ServiceData provided
   <ul>
   <br><b>Parameter:   </b> attn_type  (see iipsdbug.h)
   <br><b>Parameter:   </b> sdc  (see iipServiceData.h)
   <br><b>Returns:     </b> Error Log - Null if successfully committed
   <br><b>Requirements:</b> SetErrorTod()?
   <br><b>Promises:    </b> Error log(s) build and logged, SRC built, etc.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type, ServiceDataCollector & sdc);


private:  // functions


private:  // Data



};

} // End namespace PRDF

#endif
