/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attnfakereg.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
 * @file attnfakereg.C
 *
 * @brief HBATTN fake register class method definitions.
 */

#include "../../common/attnlist.H"
#include "../../common/attntrace.H"
#include "../../common/attntarget.H"
#include "attnfakereg.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;

namespace ATTN
{

errlHndl_t FakeRegSvc::putScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{

    ATTN_DBG("FakeRegSvc::putScom: huid: 0x%08X, add: %016x, data: %016x",
            get_huid(i_target), i_address, i_data);

    iv_regs[i_target][i_address] = i_data;


    return NULL;
}

errlHndl_t FakeRegSvc::getScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t & o_data)
{
    o_data = iv_regs[i_target][i_address];

    return NULL;
}

errlHndl_t FakeRegSvc::modifyScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                uint64_t & o_data,
                ScomOp i_op)
{
    errlHndl_t err = 0;

    uint64_t data = iv_regs[i_target][i_address];


    uint64_t changedData = i_op == SCOM_OR
        ? (data | i_data)
        : (data & i_data);

    bool changed = changedData != data;

    if(changed)
    {
        putScom(
                i_target,
                i_address,
                changedData);

    }

    return err;
}
}

