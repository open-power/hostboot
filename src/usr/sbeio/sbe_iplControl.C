/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_iplControl.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
* @file  sbe_iplControl.C
* @brief Contains the IPL Control Messages for SBE FIFO
*
*/

#include <chipids.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"IplControl: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"IplControl: " printf_string,##args)

using namespace TARGETING;

namespace SBEIO
{

    /**
    * @brief @TODO JIRA PFHB-302
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendIstepRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_ISTEP);
            if(errl)
            {
                break;
            }

            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendIstepRequest");

        }while(0);

        SBE_TRACD(EXIT_MRK "sendIstepRequest");
        return errl;
    };


    /**
     * @Brief Send the IO or MEMORY HWP request to the SBE.  This function
     *        is called by one of two wrapper functions which perform initial
     *        checking of the parameters and then call this function to send
     *        the HWP request.
     *
     * @param[in]  i_chipTarget The Odyssey chip to perform the chipop on
     * @param[in]  i_hwpClass   The HWP class, either IO or MEM
     * @param[in]  i_hwpNumber  The specific HWP number to execute
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  uint8_t i_hwpClass,
                                  uint8_t i_hwpNumber)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Input target / HWP class / HWP number have been
            // verified by the preceding wrapper functions

            // set up FIFO request message
            SbeFifo::fifoExecuteHardwareProcedureRequest l_fifoRequest;
            SbeFifo::fifoStandardResponse l_fifoResponse;
            l_fifoRequest.hwpClass      = i_hwpClass;
            l_fifoRequest.hwpNumber     = i_hwpNumber;

            SBE_TRACF( "sendExecHWPRequest: "
                       "target=0x%.8X, hwpClass=0x%X, hwpNumber=0x%X",
                       TARGETING::get_huid(i_chipTarget),
                       l_fifoRequest.hwpClass,
                       l_fifoRequest.hwpNumber );

            errl = SbeFifo::getTheInstance().performFifoChipOp(
                                i_chipTarget,
                                reinterpret_cast<uint32_t*>(&l_fifoRequest),
                                reinterpret_cast<uint32_t*>(&l_fifoResponse),
                                sizeof(SbeFifo::fifoStandardResponse));

        }while(0);

        SBE_TRACD(EXIT_MRK "sendExecHWPRequest");
        return errl;
    } // end sendExecHWPRequest


    // Wrapper for an Odyssey IO HWP
    // See sbeioif.H for definition
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureIo i_hwpNumber)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Make sure the target is Odyssey
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                     SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Send the HWP request
            errl = sendExecHWPRequest(i_chipTarget,
                                      SBE_FIFO_EXEC_HWP_CLASS_IO,
                                      i_hwpNumber);
            if(errl)
            {
                break;
            }

        } while(0);

        return errl;
    } // end sendExecHWPRequest for IO class


    // Wrapper for an Odyssey MEMORY HWP
    // See sbeioif.H for definition
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureMemory i_hwpNumber)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Make sure the target is Odyssey
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                     SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Send the HWP request
            errl = sendExecHWPRequest(i_chipTarget,
                                      SBE_FIFO_EXEC_HWP_CLASS_MEMORY,
                                      i_hwpNumber);
            if(errl)
            {
                break;
            }

        } while(0);

        return errl;
    } // end sendExecHWPRequest for MEMORY class

} //end namespace SBEIO

