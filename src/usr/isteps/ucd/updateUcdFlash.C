/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ucd/updateUcdFlash.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#include <config.h>
#include <isteps/ucd/updateUcdFlash.H>
#include <devicefw/driverif.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>

namespace POWER_SEQUENCER
{

namespace TI // Texas Instruments
{

namespace UCD // UCD Series
{

trace_desc_t* g_trac_ucd = nullptr;
TRAC_INIT(&g_trac_ucd, UCD_COMP_NAME, 2*KILOBYTE);

errlHndl_t updateUcdFlash(
          TARGETING::Target* i_pUcd,
    const void*              i_pFlashImage)
{
    errlHndl_t pError=nullptr;

    // Stub for future additional support

    return pError;
}

} // End namespace POWER_SEQUENCER

} // End namespace TI

} // End namespace UCD
