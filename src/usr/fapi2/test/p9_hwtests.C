/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_hwtests.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
//------------------------------------------------------------------------------
/// @file  p9_hwtests.C
///
/// @brief These procedures test the fapi2 hw_access interfaces.
//-----------------------------------------------------------------------------

#include <fapi2.H>
#include <fapi2_hw_access.H>


fapi2::ReturnCode p9_scomtest_getscom_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_scomdata = 0;

    FAPI_INF("Entering p9_scomtest_getscom_fail...");

    FAPI_INF("Do getscom on proc target");
    FAPI_TRY(fapi2::getScom(i_target,
                            0x11223344,
                            l_scomdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_scomtest_getscom_fail...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_scomtest_putscom_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_scomdata = 0;

    FAPI_INF("Entering p9_scomtest_putscom_fail...");

    FAPI_INF("Do getscom on proc target");
    FAPI_TRY(fapi2::putScom(i_target,
                            0x22334455,
                            l_scomdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_scomtest_putscom_fail...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_cfamtest_getcfam_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_cfamdata = 0;

    FAPI_INF("Entering p9_cfamtest_getcfam_fail...");

    FAPI_INF("Do getcfam on proc target");
    FAPI_TRY(fapi2::getCfamRegister(i_target,
                                    0x11223344,
                                    l_cfamdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_cfamtest_getcfam_fail...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_cfamtest_putcfam_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_cfamdata = 0;

    FAPI_INF("Entering p9_cfamtest_putcfam_fail...");

    FAPI_INF("Do getcfam on proc target");
    FAPI_TRY(fapi2::putCfamRegister(i_target,
                                    0x22334455,
                                    l_cfamdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_cfamtest_putcfam_fail...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_scomtest_getscom_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_scomdata = 0;

    FAPI_INF("Entering p9_scomtest_getscom_pass...");

    FAPI_INF("Do getscom on proc target");
    FAPI_TRY(fapi2::getScom(i_target,
                            0x02010803, //CXA FIR Mask Register
                            l_scomdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_scomtest_getscom_pass...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_scomtest_putscom_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_scomdata = 0;

    FAPI_INF("Entering p9_scomtest_putscom_pass...");

    FAPI_INF("Do getscom on proc target");
    FAPI_TRY(fapi2::putScom(i_target,
                            0x02010803, //CXA FIR Mask Register
                            l_scomdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_scomtest_putscom_pass...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_cfamtest_getcfam_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_cfamdata = 0;

    FAPI_INF("Entering p9_cfamtest_getcfam_pass...");

    FAPI_INF("Do getcfam on proc target");
    FAPI_TRY(fapi2::getCfamRegister(i_target,
                                    0x1000, //DATA_0 from FSI2PIB
                                    l_cfamdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_cfamtest_getcfam_pass...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_cfamtest_putcfam_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_cfamdata = 0;

    FAPI_INF("Entering p9_cfamtest_putcfam_pass...");

    FAPI_INF("Do getcfam on proc target");
    FAPI_TRY(fapi2::putCfamRegister(i_target,
                                    0x1000, //DATA_0 from FSI2PIB
                                    l_cfamdata));

 fapi_try_exit:

    FAPI_INF("Exiting p9_cfamtest_putcfam_pass...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_ringtest_getring_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::variable_buffer l_ringdata;

    FAPI_INF("Entering p9_ringtest_getring_fail...");

    FAPI_INF("Do getring on proc target");
    FAPI_TRY(fapi2::getRing(i_target,
                            (scanRingId_t)(0x22334455),
                            l_ringdata,
                            fapi2::RING_MODE_HEADER_CHECK));

 fapi_try_exit:

    FAPI_INF("Exiting p9_ringtest_getring_fail...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_ringtest_modring_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::variable_buffer l_ringdata;
    l_ringdata.resize(861);

    FAPI_INF("Entering p9_ringtest_modring_fail...");

    FAPI_INF("Do modifyRing on proc target");
    FAPI_TRY(fapi2::modifyRing(i_target,
                               (scanRingId_t)0x22334455,
                               l_ringdata,
                               fapi2::CHIP_OP_MODIFY_MODE_OR,
                               fapi2::RING_MODE_HEADER_CHECK));

 fapi_try_exit:

    FAPI_INF("Exiting p9_ringtest_modring_fail...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_ringtest_getring_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::variable_buffer l_ringdata;
    l_ringdata.resize(861);

    FAPI_INF("Entering p9_ringtest_getring_pass...");

    FAPI_INF("Do getring on proc target");
    FAPI_TRY(fapi2::getRing(i_target,
                            (scanRingId_t)0x00030088,
                            l_ringdata,
                            fapi2::RING_MODE_HEADER_CHECK));

 fapi_try_exit:

    FAPI_INF("Exiting p9_ringtest_getring_pass...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_ringtest_modring_pass(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    uint32_t bit32_array[861];
    uint32_t length;

    for (length = 0; length < 861; length++)
    {
        bit32_array[length] = length;
    }

    fapi2::variable_buffer l_ringdata(bit32_array, length, 32 * 861);

    FAPI_INF("Entering p9_ringtest_modring_pass...");

    FAPI_INF("Do putring on proc target");
    FAPI_TRY(fapi2::modifyRing(i_target,
                               (scanRingId_t)0x00030088,
                               l_ringdata,
                               fapi2::CHIP_OP_MODIFY_MODE_OR,
                               fapi2::RING_MODE_HEADER_CHECK));

 fapi_try_exit:

    FAPI_INF("Exiting p9_ringtest_modring_pass...");

    return fapi2::current_err;

}
