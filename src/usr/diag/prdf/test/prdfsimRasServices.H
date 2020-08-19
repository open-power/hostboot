/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimRasServices.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

/** Interface to RAS services provided to PRD */
class SimErrDataService : public ErrDataService
{
  public:

    /** @brief Constructor */
    inline SimErrDataService() {}

    /** @brief Destructor */
    inline virtual ~SimErrDataService() {}

    /**
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  io_sdc      Target SDC.
     * @return A non-nullptr error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & io_sdc );

};

} // End namespace PRDF

#endif
