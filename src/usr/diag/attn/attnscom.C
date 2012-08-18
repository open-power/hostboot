/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnscom.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file attnscom.C
 *
 * @brief HBATTN ATTN SCOM abstraction layer function definitions.
 */

#include "attnscom.H"
#include "attntrace.H"
#include <devicefw/userif.H>

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

    return deviceWrite(i_target, &i_data, size, DEVICE_SCOM_ADDRESS(i_address));
}

errlHndl_t ScomImpl::getScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t & o_data)
{
    size_t size = sizeof(o_data);

    return deviceRead(i_target, &o_data, size, DEVICE_SCOM_ADDRESS(i_address));
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
