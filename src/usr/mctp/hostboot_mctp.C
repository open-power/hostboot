/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/hostboot_mctp.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

// Headers from local directory
#include "hostboot_mctp.H"
// Userspace Headers
#include <devicefw/userif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <lpc/lpc_const.H>
#include <lpc/lpcif.H>
#include <sys/time.h>
#include <trace/interface.H>
#include <initservice/initserviceif.H>
#include <console/consoleif.H>

extern trace_desc_t* g_trac_mctp;

int __mctp_hostlpc_hostboot_kcs_read(void *arg,
                                     enum mctp_binding_astlpc_kcs_reg reg,
                                     uint8_t *val)
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);

    // Do not put any traces in the function as poll_kcs_status will poll the status
    // register ever 200 ms with this function so the traces get super spammy
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
                                      enum mctp_binding_astlpc_kcs_reg reg,
                                      uint8_t val)
{
    errlHndl_t l_err = NULL;
    size_t l_len = sizeof(uint8_t);

    TRACDCOMP(g_trac_mctp, "kcs write:: write 0x%lx to 0x%x ", val, reg );
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
    TRACDCOMP(g_trac_mctp, "kcs write:: done ");
    return l_rc;
}

int __mctp_hostlpc_hostboot_lpc_read(void *arg,
                                     void * buf,
                                     long offset,
                                     size_t len)
{
    errlHndl_t l_err = nullptr;
    TRACDCOMP(g_trac_mctp, "lpc read:: read from 0x%lx , len 0x%lx: ", offset, len );
    // Read a given length from a given offset in the MCTP window of LPC space
    l_err = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                static_cast<uint8_t*>(buf),
                                len,
                                DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                  offset + LPC::LPCHC_MCTP_PLDM_BASE));
    size_t i = 0;
    while(i < len)
    {
       size_t print_amt = len - i > 1024 ? 1024: len - i;
       TRACDBIN(g_trac_mctp, "lpc read: ", static_cast<uint8_t*>(buf) + i, print_amt);
       i += print_amt;
    }
    int l_rc = 0;
    if(l_err)
    {
        l_rc = 1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }
    TRACDCOMP(g_trac_mctp, "lpc read:: done" );
    return l_rc;
}

int __mctp_hostlpc_hostboot_lpc_write(void *arg,
                                      const void * buf,
                                      long offset,
                                      size_t len)
{
    errlHndl_t l_err = nullptr;
    TRACDCOMP(g_trac_mctp, "lpc write:: write to 0x%lx , length 0x%lx", offset, len );

    // Write a given value to a given offset in the MCTP window of LPC space
    l_err = DeviceFW::deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                 const_cast<void *>(buf),
                                 len,
                                 DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                    offset + LPC::LPCHC_MCTP_PLDM_BASE));

    int l_rc = 0;
    if(l_err)
    {
        l_rc = 1;
        ERRORLOG::errlCommit(l_err, MCTP_COMP_ID);
    }
    TRACDCOMP(g_trac_mctp, "lpc write:: done ");
    return l_rc;
}

void __mctp_hostlpc_hostboot_nanosleep(uint64_t i_sec,
                                       uint64_t i_nsec)
{
    nanosleep(i_sec, i_nsec);

    return;
}

void __mctp_hostlpc_hostboot_do_shutdown(uint64_t i_status)
{
    INITSERVICE::doShutdown(i_status);
}

void __mctp_hostlpc_hostboot_console_print(const char* i_message)
{
    CONSOLE::displayf(CONSOLE::DEFAULT, nullptr, i_message);
}

