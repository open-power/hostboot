/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/hostboot_mctp.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "hostboot_mctp.H"
#include <devicefw/userif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <lpc/lpc_const.H>
#include <lpc/lpcif.H>
#include <sys/time.h>

int __mctp_hostlpc_hostboot_kcs_read(void *arg,
                                     enum mctp_binding_lpc_kcs_reg reg,
                                     uint8_t *val)
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);

    l_err = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 val,
                                 l_len,
                                 DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                    reg + LPC::KCS_DATA_REG));
    int l_rc = 0;
    if(l_err)
    {
        l_rc = -1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }

    return l_rc;
}

int __mctp_hostlpc_hostboot_kcs_write(void *arg,
                                      enum mctp_binding_lpc_kcs_reg reg,
                                      uint8_t val)
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);

    l_err = DeviceFW::deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &val,
                                  l_len,
                                  DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                     reg + LPC::KCS_DATA_REG));

    int l_rc = 0;
    if(l_err)
    {
        l_rc = -1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }

    return l_rc;
}

int __mctp_hostlpc_hostboot_lpc_read(void *arg,
                                     void * buf,
                                     uint64_t offset,
                                     size_t len)
{
    errlHndl_t l_err = NULL;

    l_err = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                static_cast<uint8_t*>(buf),
                                len,
                                DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                    offset + LPC::LPCHC_MCTP_PLDM_BASE));

    int l_rc = 0;
    if(l_err)
    {
        l_rc = 1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }

    return l_rc;
}

int __mctp_hostlpc_hostboot_lpc_write(void *arg,
                                      void * buf,
                                      uint64_t offset,
                                      size_t len)
{
    errlHndl_t l_err = NULL;

    l_err = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                static_cast<uint8_t*>(buf),
                                len,
                                DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                   offset + LPC::LPCHC_MCTP_PLDM_BASE));

    int l_rc = 0;
    if(l_err)
    {
        l_rc = 1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }

    return l_rc;
}

void __mctp_hostlpc_hostboot_nanosleep(uint64_t i_sec,
                                       uint64_t i_nsec)
{
    nanosleep(i_sec, i_nsec);

    return;
}