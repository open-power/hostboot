/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/sbeio_nvdimm_operation.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
#include <sbeio/runtime/sbeio_nvdimm_operation.H>

#include <runtime/interface.h>
#include <util/runtime/rt_fwnotify.H>
#include <sbeio/sbeioreasoncodes.H>
#include <errl/errlentry.H>

extern trace_desc_t* g_trac_sbeio;

using namespace ERRORLOG;

namespace SBE_MSG
{

//-------------------------------------------------------------------------
errlHndl_t sbeNvdimmOperation( TARGETING::TargetHandle_t i_procTgt,
                               uint32_t   i_reqDataSize,
                               uint8_t  * i_reqData,
                               uint32_t * o_rspStatus,
                               uint32_t * o_rspDataSize,
                               uint8_t  * o_rspData )
{
    errlHndl_t errl{};

    do
    {
        *o_rspDataSize = 0; //No return data
        o_rspData = nullptr;

        // doNvDimmOperation will take care of handling errors it encounters.
        hostInterfaces::nvdimm_operation_t* l_nvdimmOp =
            reinterpret_cast<hostInterfaces::nvdimm_operation_t*>(i_reqData);
        *o_rspStatus = doNvDimmOperation(*l_nvdimmOp);
    }
    while(0);

    return errl;
}

}//End namespace
