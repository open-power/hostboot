/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_secureHwp.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
* @file sbe_secureHwp.C
* @brief Send request to perform a HWP securely on SBE
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"secureHwp: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"secureHwp: " printf_string,##args)


namespace SBEIO
{
    //List out name of valid hwps that have chipop equivalents
    //these static variable will be used by
    static const char* test_hwp = "p9_pm_ocb_indir_access"; // SBE_FIFO_CMD_PLACEHOLDER_HWP

    /**
    * @brief Convert a hwp name passed in as a string to a chipOp code
    * @param[in]  i_hwpName         name of hwp as a string
    * @return fifoSecureHwpMessage  returns a chipOp representing the HWP, if found
    *                               otherwise returns UNSUPPORTED_HWP enum
    */
    SbeFifo::fifoSecureHwpMessage convertHwpStringToOpCode(char* i_hwpName)
    {
        //Default to undefined HWP
        SbeFifo::fifoSecureHwpMessage l_hwpOpCode = SbeFifo::fifoSecureHwpMessage::SBE_FIFO_CMD_UNSUPPORTED_HWP;

        //If we find a match, set the return value
        if(strcmp(i_hwpName,test_hwp) == 0)
        {
            l_hwpOpCode = SbeFifo::fifoSecureHwpMessage::SBE_FIFO_CMD_PLACEHOLDER_HWP;
        }
        return l_hwpOpCode;
    }

    /**
    * @brief Request the SBE to do a specific chip op
    *
    * @param[in] i_target       The target of which the HWP is intended to be called on,
    *                           this must be the first param of the request HWP
    *
    * @param[in] i_dataPointer  Pointer to a blob of data that contains additional parameters
    *                           for the requests HWP
    *
    * @param[in] i_dataSize     Size of blob of data that contains additional parameters
    *                           for the requests HWP
    *
    * @param[in] i_hwpStringLen size of the hwp name string at beginning of data pointer
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSecureHwpRequest(TARGETING::Target * i_target,
                                    uint8_t * i_dataPointer,
                                    uint64_t i_dataSize,
                                    uint64_t i_hwpStringLen)
    {
        errlHndl_t errl = nullptr;
        do
        {
            SBE_TRACD(ENTER_MRK "sendSecureHwpRequest");
            auto l_targType =  i_target->getAttr<TARGETING::ATTR_TYPE>();
            TARGETING::Target * l_proc;

            //Copy out the hwp name string into a local buffer
            char l_hwpName[i_hwpStringLen];
            memcpy(l_hwpName, i_dataPointer, i_hwpStringLen);

            if(l_targType == TARGETING::TYPE_PROC)
            {
                l_proc = i_target;
            }
            else
            {
                l_proc = const_cast<TARGETING::Target *>(getParentChip(i_target));
            }

            SbeFifo::fifoSecureHwpRequest       l_fifoRequest(i_dataSize, i_hwpStringLen, i_dataPointer);
            SbeFifo::fifoStandardResponse       l_fifoResponse;

            //Command is computed by converting hwp string to function
            l_fifoRequest.command      = convertHwpStringToOpCode(l_hwpName);
            l_fifoRequest.targetType   = translateToSBETargetType(i_target);
            l_fifoRequest.chipletId    = getChipletIDForSBE(i_target);

            SBE_TRACD(ENTER_MRK "requesting secureHwp %d on proc %d HB -> SBE  ",
                        l_fifoRequest.command,
                        l_proc->getAttr<TARGETING::ATTR_POSITION>());

            errl = SbeFifo::getTheInstance().performFifoChipOp(l_proc,
                                                                (uint32_t *)&l_fifoRequest,
                                                                (uint32_t *)&l_fifoResponse,
                                                                 sizeof(SbeFifo::fifoStandardResponse));

            SBE_TRACD(EXIT_MRK "sendSecureHwpRequest");

        }while(0);

        return errl;
    };

} //end namespace SBEIO

