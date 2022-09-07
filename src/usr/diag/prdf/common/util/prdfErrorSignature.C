/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrorSignature.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#include <prdfErrorSignature.H>
#include <prdfExtensibleChip.H>
#include <prdfTargetServices.H>
#include <iipSystem.h>
#include <prdfGlobal.H>
#include <iipscr.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

#ifdef __HOSTBOOT_MODULE

void ErrorSignature::writeScratch() const
{
    TargetHandle_t procTrgt = getMasterProc();
    ExtensibleChip * proc = (ExtensibleChip *)systemPtr->GetChip(procTrgt);

    // Write the Chip ID to scratch 9
    SCAN_COMM_REGISTER_CLASS * scratch9 = proc->getRegister("HB_SCRATCH_9");
    scratch9->SetBitFieldJustified(0, 32, getChipId());
    uint32_t rc = scratch9->Write();
    if ( SUCCESS != rc )
    {
        PRDF_ERR( "Write() of data 0x%08x failed on HB_SCRATCH_9 proc=0x%08x",
                  getChipId(), proc->getHuid() );
    }

    // Write the Signature ID to scratch 10
    SCAN_COMM_REGISTER_CLASS * scratch10 = proc->getRegister("HB_SCRATCH_10");
    scratch10->SetBitFieldJustified(0, 32, getSigId());
    rc = scratch10->Write();
    if ( SUCCESS != rc )
    {
        PRDF_ERR( "Write() of data 0x%08x failed on HB_SCRATCH_10 proc=0x%08x",
                  getSigId(), proc->getHuid() );
    }
}

#endif

} // end namespace PRDF
