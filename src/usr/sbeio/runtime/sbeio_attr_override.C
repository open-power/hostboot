/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/sbeio_attr_override.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <sbeio/runtime/sbeio_attr_override.H>

#include <runtime/interface.h>
#include <sbeio/sbeioreasoncodes.H>

extern trace_desc_t* g_trac_sbeio;

using namespace ERRORLOG;

namespace SBE_MSG
{

//-------------------------------------------------------------------------
errlHndl_t sbeApplyAttrOverrides(
                                 TARGETING::TargetHandle_t i_procTgt,
                                 uint32_t   i_reqDataSize,
                                 uint8_t  * i_reqData,
                                 uint32_t * o_rspStatus,
                                 uint32_t * o_rspDataSize,
                                 uint8_t  * o_rspData
                                )
{
    errlHndl_t errl{};

    do
    {
        *o_rspDataSize = 0; //No return data

        runtimeInterfaces_t *rt_intf = getRuntimeInterfaces();

        if(nullptr == rt_intf)
        {
           TRACFCOMP( g_trac_sbeio,
                      ERR_MRK"sbeApplyAttrOverrides: "
                      "Unable to get runtime interfaces."
                    );

           /*@
            * @errortype
            * @moduleid     SBEIO::SBEIO_RUNTIME_ATTR_OVERRIDE
            * @reasoncode   SBEIO::SBEIO_RT_NO_INTERFACE_POINTER
            * @userdata1    Processor HUID
            * @userdata2    Reserved
            *
            * @devdesc      SBEIO RT Process Pass-through command RuntimeRT
            *                Interface pointer not set.
            * @custdesc     Firmware error communicating with boot device
            */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 SBEIO::SBEIO_RUNTIME_ATTR_OVERRIDE,
                                 SBEIO::SBEIO_RT_NO_INTERFACE_POINTER,
                                 get_huid(i_procTgt),
                                 0
                                 );

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);

            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }
        else if(nullptr == rt_intf->apply_attr_override)
        {
            TRACFCOMP( g_trac_sbeio,
                       ERR_MRK"sbeApplyAttrOverrides: "
                       "Function pointer to apply_attr_override not set."
                     );
            /*@
            * @errortype
            * @moduleid     SBEIO::SBEIO_RUNTIME_ATTR_OVERRIDE
            * @reasoncode   SBEIO::SBEIO_RT_NO_APPLY_ATTR_FUNCTION
            * @userdata1    Processor HUID
            * @userdata2    Reserved
            *
            * @devdesc      SBEIO RT Process Pass-through command RuntimeRT
            *               Interface pointer for apply_attr_override not set.
            * @custdesc     Firmware error communicating with boot device
            */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 SBEIO::SBEIO_RUNTIME_ATTR_OVERRIDE,
                                 SBEIO::SBEIO_RT_NO_APPLY_ATTR_FUNCTION,
                                 get_huid(i_procTgt),
                                 0
                                 );

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        //apply_attr_override will take care of handling errors it encounters.
        *o_rspStatus = rt_intf->apply_attr_override(i_reqData, i_reqDataSize);
    }
    while(0);

    return errl;
}

}//End namespace
