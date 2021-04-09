/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnscom.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
 * @file attnscom.C
 *
 * @brief HBATTN ATTN SCOM abstraction layer function definitions.
 */

#include "common/attnscom.H"
#include "common/attntrace.H"
#include <devicefw/userif.H>
#include <mmio/mmio_reasoncodes.H>
#include <scom/scomreasoncodes.H>

using namespace TARGETING;
using namespace DeviceFW;

namespace ATTN
{

errlHndl_t getScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t & o_data)
{
    errlHndl_t err = getScomWrapper().getScom(i_target, i_address, o_data);

    ATTN_DBG("getScom: tgt: %p, add: 0x%.16x, data: 0x%.16x",
            i_target, i_address, o_data);

    return err;
}

errlHndl_t putScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{
    ATTN_DBG("putScom: tgt: %p, add: 0x%.16x, data: 0x%.16x",
            i_target, i_address, i_data);

    return getScomWrapper().putScom(i_target, i_address, i_data);
}

errlHndl_t modifyScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data,
        ScomOp i_op)
{
    uint64_t data = 0;

    errlHndl_t err = getScomWrapper().modifyScom(
            i_target,
            i_address,
            i_data,
            data,
            i_op);

    ATTN_DBG("getScom: tgt: %p, add: 0x%.16x, data: 0x%.16x",
            i_target, i_address, data);

    bool changed = (i_op == SCOM_OR
            ? (data | i_data) != data
            : (data & i_data) != data);

    if(changed)
    {
        ATTN_DBG("putScom: tgt: %p, add: 0x%.16x, data: 0x%.16x",
                i_target,
                i_address,
                i_op == SCOM_OR ? data | i_data : data & i_data);
    }

    return err;
}

errlHndl_t ScomImpl::putScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{
    size_t size = sizeof(i_data);

    errlHndl_t errlH =
          deviceWrite(i_target, &i_data, size, DEVICE_SCOM_ADDRESS(i_address));

    if( ( NULL != errlH ) &&
        ( MMIO::RC_MMIO_CHAN_CHECKSTOP ) == errlH->reasonCode() )
    {
        errlCommit( errlH, ATTN_COMP_ID );
        ATTN_DBG( "deviceWrite failed with reason code RC_MMIO_CHAN_CHECKSTOP."
                  " Trying again, Target HUID:0x%08X Register 0x%016X",
                  get_huid( i_target), i_address );

        errlH = deviceWrite( i_target, &i_data,
                             size, DEVICE_SCOM_ADDRESS(i_address));
    }
    return errlH;
}

errlHndl_t ScomImpl::getScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t & o_data)
{
    size_t size = sizeof(o_data);

    errlHndl_t errlH =
        deviceRead(i_target, &o_data, size, DEVICE_SCOM_ADDRESS(i_address));

#ifdef __HOSTBOOT_RUNTIME
    if ( ( NULL != errlH ) &&
         ( SCOM::SCOM_RUNTIME_HYP_ERR == errlH->reasonCode() )
       )
#else
    if ( ( NULL != errlH ) &&
         (MMIO::RC_MMIO_CHAN_CHECKSTOP ) == errlH->reasonCode()
       )
#endif
    {
        errlCommit( errlH, ATTN_COMP_ID );
        ATTN_DBG( "deviceRead() failed with reason code %X."
                  " Trying again, Target HUID:0x%08X Register 0x%016X",
                  errlH->reasonCode(),
                  get_huid( i_target), i_address );

        errlH = deviceRead( i_target, &o_data, size,
                            DEVICE_SCOM_ADDRESS(i_address));
    }
    return errlH;
}

errlHndl_t ScomImpl::modifyScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data,
        uint64_t & o_data,
        ScomOp i_op)
{
    errlHndl_t err = 0;

    err = getScom(i_target, i_address, o_data);

    if(!err && i_op == SCOM_OR
            ? (o_data | i_data) != o_data
            : (o_data & i_data) != o_data)
    {
        err = putScom(i_target, i_address,
                i_op == SCOM_OR ? o_data | i_data : o_data & i_data);
    }

    return err;
}

void ScomImpl::installScomImpl()
{
    getScomWrapper().setImpl(*this);
}

ScomImpl::~ScomImpl()
{
    // restore the default

    ScomWrapper & wrapper = getScomWrapper();
    ScomImpl * defaultImpl = &Singleton<ScomImpl>::instance();

    if(wrapper.iv_impl == this)
    {
        if(this != defaultImpl)
        {
            wrapper.setImpl(*defaultImpl);
        }
    }
}

errlHndl_t ScomWrapper::putScom(TargetHandle_t i_target, uint64_t i_address,
        uint64_t i_data)
{
    return iv_impl->putScom(i_target, i_address, i_data);
}

errlHndl_t ScomWrapper::getScom(TargetHandle_t i_target, uint64_t i_address,
        uint64_t & o_data)
{
    return iv_impl->getScom(i_target, i_address, o_data);
}

errlHndl_t ScomWrapper::modifyScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data,
        uint64_t & o_data,
        ScomOp i_op)
{
    return iv_impl->modifyScom(i_target, i_address, i_data, o_data, i_op);
}

ScomWrapper::ScomWrapper()
    : iv_impl(&Singleton<ScomImpl>::instance())
{

}

ScomWrapper & getScomWrapper()
{
    static ScomWrapper w;
    return w;
}
}
