/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <sys/mmio.h>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <arch/ppc.H>

#include <mmio/mmio.H>

namespace MMIO
{

void mmioSetup()
{
}

// Direct OCMB reads and writes to the device's memory mapped memory.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::MMIO,
                      TARGETING::TYPE_OCMB_CHIP,
                      mmioPerformOp);

errlHndl_t mmioPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::TargetHandle_t i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    errlHndl_t l_err         = nullptr;

    return l_err;
}

}; // end namespace MMIO
