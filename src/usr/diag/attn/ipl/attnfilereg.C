/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/attnfilereg.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 * @file attnfilereg.C
 *
 * @brief HBATTN file register class method definitions.
 */

#include "common/attnlist.H"
#include "common/attntrace.H"
#include "common/attntarget.H"
#include "attnfilereg.H"

#include <diag/prdf/prdfPnorFirDataReader.H>

using namespace std;
using namespace PRDF;
using namespace TARGETING;

namespace ATTN
{

errlHndl_t FileRegSvc::putScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{

    using namespace PRDF;

    ATTN_DBG("FileRegSvc::putScom: huid: 0x%08X, add: %016x, data: %016x",
             get_huid(i_target), i_address, i_data);

    PnorFirDataReader & firData = PnorFirDataReader::getPnorFirDataReader();
    firData.putScom( i_target, i_address, i_data );

    return NULL;
}

errlHndl_t FileRegSvc::getScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t & o_data)
{
    using namespace PRDF;

    PnorFirDataReader & firData = PnorFirDataReader::getPnorFirDataReader();
    firData.getScom( i_target, i_address, o_data);

    ATTN_DBG("FileRegSvc::getScom: huid: 0x%08X, add: %016x, data: %016x",
             get_huid(i_target), i_address, o_data);

    return NULL;
}

errlHndl_t FileRegSvc::modifyScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                uint64_t & o_data,
                ScomOp i_op)
{
    errlHndl_t err = 0;

    uint64_t data = 0;

    do
    {
        err = getScom( i_target, i_address, data );
        if( err ) break;

        uint64_t changedData = i_op == SCOM_OR
                ? (data | i_data)
                : (data & i_data);

        bool changed = changedData != data;

        if(changed)
        {
            err = putScom( i_target, i_address, changedData);
            if ( err ) break;
        }
    }while( 0 );
    if( NULL != err )
    {
        ATTN_ERR("FileRegSvc::modifyScom() failed. huid: 0x%08X, add: %016x, "
                 "data: %016x", get_huid(i_target), i_address, i_data);
    }
    return err;
}

} // end namespace ATTN

