/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimRasServices.C $                 */
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

#include "prdfsimRasServices.H"
#include "prdfsimServices.H"
#include "stdio.h"
#include <targeting/common/targetservice.H>

using namespace TARGETING;

namespace PRDF
{

errlHndl_t SimErrDataService::GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                              ServiceDataCollector & io_sdc )
{
    using namespace TARGETING;
    using namespace PlatServices;

    PRDF_ENTER("SimErrDataService::GenerateSrcPfa()");
    errlHndl_t errLog = nullptr;

    // call the actual ras services function
    errLog = ErrDataService::GenerateSrcPfa( i_attnType, io_sdc );

    ErrorSignature * esig = io_sdc.GetErrorSignature();

    // report the actual signature
    getSimServices().reportSig(esig->getChipId(), esig->getSigId());

    PRDF_EXIT("SimErrDataService::GenerateSrcPfa()");

    return errLog;

}

} // End namespace PRDF
