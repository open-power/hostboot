/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occAccess.C $                            */
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

#include    <stdint.h>

#include    <errl/errlentry.H>
#include    <occ/occAccess.H>
#include    <targeting/common/utilFilter.H>

// Fapi
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <isteps/hwpf_reasoncodes.H>

// Procedures
#include <p8_ocb_init.H>
#include <p8_ocb_indir_setup_linear.H>
#include <p8_ocb_indir_access.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace HBOCC
{

// Passed target should be either a PROC or an OCC target
// If passed an OCC, then use it's parent PROC
// If passed a PROC, then use it
errlHndl_t getChipTarget(const TARGETING::Target* i_target,
                            TARGETING::Target* & o_pChipTarget)
{
    errlHndl_t l_errl = NULL;
    TARGETING::TYPE  l_type  = TARGETING::TYPE_NA;
    bool l_found = false;    //error if no chip target found
    uint32_t l_huid = 0xFFFFFFFF;  //read for error FFDC

    do
    {
        if(NULL == i_target) //unexpected error
        {
            TRACFCOMP( g_fapiTd, ERR_MRK"getChipTarget: null target passed");
            break; // log and return error
        }

        l_type  = i_target->getAttr<TARGETING::ATTR_TYPE> ();
        if (TARGETING::TYPE_OCC == l_type) // if OCC, use parent PROC
        {
            const TARGETING::Target * l_pChipTarget = getParentChip(
                      const_cast<TARGETING::Target *>(i_target));
            o_pChipTarget =  const_cast<TARGETING::Target *>(l_pChipTarget);
            if (NULL == o_pChipTarget)
            {
                l_huid  = i_target->getAttr<TARGETING::ATTR_HUID>();
                TRACFCOMP( g_fapiTd, ERR_MRK"getChipTarget:"
                " Error OCC target has no parent"
                " Target type: 0x%X huid:0x%X",
                l_type, l_huid);
                break; // log and return error
            }
            l_found = true;
        }
        else if (TARGETING::TYPE_PROC == l_type) //use passed PROC target
        {
            o_pChipTarget =  const_cast<TARGETING::Target *>(i_target);
            l_found = true;
        }
        else // unexpected target type
        {
            l_huid  = i_target->getAttr<TARGETING::ATTR_HUID>();
            TRACFCOMP( g_fapiTd, ERR_MRK"getChipTarget:"
                 " Error Unexpected target type. Not PROC or"
                 " OCC. Target is of type: 0x%X huid:0x%X",
                 l_type, l_huid);
            break; // log and return error
        }

    }
    while (0);

    if (!l_found)
    {
        /*@
         * @errortype
         * @moduleid     fapi::MOD_GET_OCC_CHIP_TARGET
         * @reasoncode   fapi::RC_TARGET_UNSUPPORTED
         * @userdata1    Target Type
         * @userdata2    Target HUID
         * @devdesc      PROC or OCC expected
         * @custdesc     A problem occurred during the IPL
         *               of the system.
         */
        const bool hbSwError = true;
        l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi::MOD_GET_OCC_CHIP_TARGET,
                                fapi::RC_TARGET_UNSUPPORTED,
                                l_type,
                                l_huid,
                                hbSwError);
    }

    return l_errl;
}

// common wrapper to p8_ocb_indir_access to access an OCB indirect channel
enum accessOCBIndirectCmd
{
    ACCESS_OCB_READ_LINEAR,
    ACCESS_OCB_WRITE_LINEAR,
    ACCESS_OCB_WRITE_CIRCULAR,
};

errlHndl_t accessOCBIndirectChannel(accessOCBIndirectCmd i_cmd,
              const TARGETING::Target * i_pTarget,
              const uint32_t       i_addr,
              ecmdDataBufferBase & io_dataBuf)
{
    errlHndl_t l_errl = NULL;
    uint32_t   l_len  = 0;
    TARGETING::Target* l_pChipTarget = NULL;

    uint32_t   l_channel = OCB_CHAN0;  // OCB channel (0,1,2,3)
    uint32_t   l_operation = OCB_GET;  // Operation(Get, Put)
    bool       l_ociAddrValid = true;  // use oci_address
    bool       l_setup=true;           // set up linear

    TRACUCOMP( g_fapiTd, ENTER_MRK"accessOCBIndirectChannel cmd=%d",i_cmd);

    switch (i_cmd)
    {
        case (ACCESS_OCB_READ_LINEAR):
            break; // use defaults
        case (ACCESS_OCB_WRITE_LINEAR):
            l_operation = OCB_PUT;
            break;
        case (ACCESS_OCB_WRITE_CIRCULAR):
            l_channel = OCB_CHAN1;
            l_operation = OCB_PUT;
            l_ociAddrValid = false;
            l_setup = false;
            break;
    }

    TRACUCOMP( g_fapiTd, INFO_MRK"accessOCBIndirectChannel"
           " channel=%d operation=%d addrValid=%d",
           l_channel,l_operation,l_ociAddrValid);
    do
    {
        l_errl = getChipTarget(i_pTarget,l_pChipTarget);
        if (l_errl)
        {
            break; //exit with error
        }
        TRACUCOMP( g_fapiTd, INFO_MRK"accessOCBIndirectChannel:"
                    " target=%.8x type=%d",
                    get_huid(l_pChipTarget),
                    l_pChipTarget->getAttr<TARGETING::ATTR_TYPE>());

        fapi::Target l_fapiTarget(fapi::TARGET_TYPE_PROC_CHIP,
                 reinterpret_cast<void *> (l_pChipTarget) );

        // buffer must be multiple of bytes
        if(io_dataBuf.getByteLength()%8 != 0)
        {
            TRACFCOMP( g_fapiImpTd, ERR_MRK"accessOCBIndirectChannel:"
                    " Error Improper data size:%d(in bytes),size of data"
                    " requested to be read is not aligned in size of 8 Bytes",
                    io_dataBuf.getByteLength());
            /*@
             * @errortype
             * @moduleid     fapi::MOD_ACCESS_OCB_INDIRECT_CHANNEL
             * @reasoncode   fapi::RC_INVALID_DATA_BUFFER_LENGTH
             * @userdata1    Length of requested buffer size(in Bytes) to
             *               perform read operation.
             * @userdata2    OCI address
             * @devdesc      Improper data size, data is not 8 byte aligned.
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            const bool hbSwError = true;
            l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi::MOD_ACCESS_OCB_INDIRECT_CHANNEL,
                                fapi::RC_INVALID_DATA_BUFFER_LENGTH,
                                io_dataBuf.getByteLength(),
                                i_addr,
                                hbSwError);
            break; // return with error
        }

        // TODO RTC: 116027 To be consistent with FSP code hwcoOCC.C,
        // p8_ocb_indir_setup_linear is always called for read and write
        // linear and not called for write circular.
        // a) linear read and write set up may only be needed once
        // b) circular write may need to be set up once
        if (l_setup)
        {
            FAPI_INVOKE_HWP(l_errl, p8_ocb_indir_setup_linear, l_fapiTarget,
                    OCB_CHAN0, OCB_TYPE_LINSTR, i_addr);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"accessOCBIndirectChannel:"
                       " Error [0x%X] in call to "
                       " FAPI_INVOKE_HWP(p8_ocb_indir_setup_linear)",
                       l_errl->reasonCode());
                break; // return with error
            }
        }

        // perform operation
        FAPI_INVOKE_HWP(l_errl, p8_ocb_indir_access, l_fapiTarget,
                    l_channel,l_operation,io_dataBuf.getByteLength()/8,
                    io_dataBuf,l_len,l_ociAddrValid,i_addr);
        if(l_errl)
        {
            TRACFCOMP( g_fapiImpTd, ERR_MRK"accessOCBIndirectChannel:"
                   " Error [0x%X] in call to"
                   " FAPI_INVOKE_HWP(p8_ocb_indir_access)",
                   l_errl->reasonCode());
            break; // return with error
        }

    }
    while (0);

    TRACUCOMP( g_fapiTd, EXIT_MRK"accessOCBIndirectChannel");

    return l_errl;
}

// Read OCC SRAM
errlHndl_t readSRAM(const TARGETING::Target * i_pTarget,
                             const uint32_t i_addr,
                             ecmdDataBufferBase & io_dataBuf)
{
    errlHndl_t l_errl = NULL;
    l_errl = accessOCBIndirectChannel(ACCESS_OCB_READ_LINEAR,
                                        i_pTarget,
                                        i_addr,
                                        io_dataBuf);
    return l_errl;
}

// Write OCC SRAM
errlHndl_t writeSRAM(const TARGETING::Target * i_pTarget,
                             const uint32_t i_addr,
                             ecmdDataBufferBase & i_dataBuf)
{
    errlHndl_t l_errl = NULL;
    l_errl = accessOCBIndirectChannel(ACCESS_OCB_WRITE_LINEAR,
                                        i_pTarget,
                                        i_addr,
                                        i_dataBuf);
    return l_errl;
}

// Write OCC Circular Buffer
errlHndl_t writeCircularBuffer(const TARGETING::Target * i_pTarget,
                             ecmdDataBufferBase & i_dataBuf)
{
    errlHndl_t l_errl = NULL;
    l_errl = accessOCBIndirectChannel(ACCESS_OCB_WRITE_CIRCULAR,
                                        i_pTarget,
                                        0,
                                        i_dataBuf);
    return l_errl;
}

}  //end OCC namespace
