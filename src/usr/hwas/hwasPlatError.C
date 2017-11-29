/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatError.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
/**
 *  @file hwasPlatError.C
 *
 *  @brief Platform specific error functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/hwasPlatError.H>

namespace HWAS
{

errlHndl_t hwasError(const uint8_t i_sev,
              const uint8_t i_modId,
              const uint16_t i_reasonCode,
              const uint64_t i_user1,
              const uint64_t i_user2)
{
    errlHndl_t l_pErr;

    l_pErr = new ERRORLOG::ErrlEntry(
                    (ERRORLOG::errlSeverity_t)i_sev, i_modId,
                    i_reasonCode,
                    i_user1, i_user2);
    l_pErr->collectTrace("HWAS_I");
    return l_pErr;
}

void hwasErrorAddProcedureCallout(errlHndl_t                & io_errl,
                                  const HWAS::epubProcedureID i_procedure,
                                  const HWAS::callOutPriority i_priority)
{
    io_errl->addProcedureCallout(i_procedure,
                                 i_priority);
}

void platHwasErrorAddHWCallout(errlHndl_t & io_errl,
                           const TARGETING::ConstTargetHandle_t i_target,
                           const HWAS::callOutPriority i_priority,
                           const HWAS::DeconfigEnum i_deconfigState,
                           const HWAS::GARD_ErrorType i_gardErrorType)
{
    io_errl->addHwCallout(i_target, i_priority,
                          i_deconfigState, i_gardErrorType);
}

void hwasErrorUpdatePlid(errlHndl_t & io_errl,
                         uint32_t & io_plid)
{

    if (io_plid != 0)
    {
        io_errl->plid(io_plid) ;
    }
    else
    {
        io_plid = io_errl->plid();
    }
}


} // namespace HWAS
