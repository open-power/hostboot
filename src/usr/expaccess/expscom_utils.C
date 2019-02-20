/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/expscom_utils.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
 *  @file expscom_utls.C
 *
 *  @brief Provides the common utility functions for i2c and mmio
 *         Explorer OCMB scom drivers
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>        // errlCommit
#include <errl/errludtarget.H>       // ErrlUserDetailsTarget
#include <devicefw/driverif.H>       // OperationType
#include <expscom/expscom_reasoncodes.H> // ReasonCodes/ModuleIds
#include "expscom_trace.H" //g_trac_expscom
#include "expscom_utils.H" //validateInputs

namespace EXPSCOM
{

constexpr uint64_t FIRST_4_BYTES = 0xFFFFFFFF00000000;

///////////////////////////////////////////////////////////////////////////////
// See header file for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t validateInputs(DeviceFW::OperationType i_opType,
                          const TARGETING::Target* i_target,
                          size_t i_buflen,
                          uint64_t i_scomAddr)
{
    errlHndl_t l_err = nullptr;
    uint32_t l_commonPlid = 0;  // If there are multiple issues found link logs with first

    TARGETING::ATTR_MODEL_type l_targetModel =
                    i_target->getAttr<TARGETING::ATTR_MODEL>();

    // Only target we can perform ocmb scoms on are explorer OCMB chip targets
    if( l_targetModel != TARGETING::MODEL_EXPLORER )
    {
        TRACFCOMP( g_trac_expscom, ERR_MRK "validateInputs> Invalid target type : l_targetModel=%d", l_targetModel );
        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_OCMB_UTILS
          * @reasoncode   EXPSCOM::RC_INVALID_MODEL_TYPE
          * @userdata1    SCOM Address
          * @userdata2    Model Type
          * @devdesc      validateInputs> Invalid target type (!= OCMB_CHP)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid target type for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_OCMB_UTILS,
                                        EXPSCOM::RC_INVALID_MODEL_TYPE,
                                        i_scomAddr,
                                        l_targetModel,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(EXPSCOM_COMP_NAME);
        ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
          addToLog(l_err);
        l_commonPlid = l_err->plid();
    }

    // The address passed to the OCMB scom functions is really only 32 bits
    //  just to be safe make sure that first 4 bytes are 0s
    if( i_scomAddr & FIRST_4_BYTES )
    {
        TRACFCOMP( g_trac_expscom,
                    ERR_MRK "validateInputs> Invalid address : i_scomAddr=0x%lx , first 32 bits should be 0's",
                    i_scomAddr );

        // If there is already an error from prev checks, then commit it
        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_OCMB_UTILS
          * @reasoncode   EXPSCOM::RC_INVALID_ADDRESS
          * @userdata1    SCOM Address
          * @userdata2    Target HUID
          * @devdesc      validateInputs> Invalid scom address, first 4
          *               bytes should be 0's
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid address for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_OCMB_UTILS,
                                        EXPSCOM::RC_INVALID_ADDRESS,
                                        i_scomAddr,
                                        TARGETING::get_huid(i_target),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(EXPSCOM_COMP_NAME);
        ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
          addToLog(l_err);

        if(l_commonPlid == 0)
        {
            l_commonPlid = l_err->plid();
        }
        else
        {
            l_err->plid(l_commonPlid);
        }
    }

    // The buffer passed into validateInputs should ALWAYS be 8 bytes.
    // If it is an IBM scom then all 8 bytes are used. If its microchip scom
    // then only the last 4 bytes are used.
    if (i_buflen != sizeof(uint64_t))
    {
        TRACFCOMP( g_trac_expscom, ERR_MRK "validateInputs> Invalid data length : io_buflen=%d ,"
                    " expected sizeof(uint64_t)", i_buflen );

        // If there is already an error from prev checks, then commit it
        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_OCMB_UTILS
          * @reasoncode   EXPSCOM::RC_INVALID_LENGTH
          * @userdata1    SCOM Address
          * @userdata2    Data Length
          * @devdesc      validateInputs> Invalid data length (!= 8 bytes)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid data length for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_OCMB_UTILS,
                                        EXPSCOM::RC_INVALID_LENGTH,
                                        i_scomAddr,
                                        TO_UINT64(i_buflen),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(EXPSCOM_COMP_NAME);
        ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
          addToLog(l_err);

        if(l_commonPlid == 0)
        {
            l_commonPlid = l_err->plid();
        }
        else
        {
            l_err->plid(l_commonPlid);
        }
    }

    // The only valid operations are READ and WRITE if anything else comes in we need to error out
    if (i_opType != DeviceFW::READ && i_opType != DeviceFW::WRITE )
    {
        TRACFCOMP( g_trac_expscom, ERR_MRK "validateInputs> Invalid operation type : i_opType=%d", i_opType );

        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_OCMB_UTILS
          * @reasoncode   EXPSCOM::RC_INVALID_OPTYPE
          * @userdata1    SCOM Address
          * @userdata2    Access Type
          * @devdesc      validateInputs> Invalid OP type (!= READ or WRITE)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid operation type for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_OCMB_UTILS,
                                        EXPSCOM::RC_INVALID_OPTYPE,
                                        i_scomAddr,
                                        i_opType,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(EXPSCOM_COMP_NAME);
        ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
          addToLog(l_err);

        if(l_commonPlid == 0)
        {
            l_commonPlid = l_err->plid();
        }
        else
        {
            l_err->plid(l_commonPlid);
        }
    }

    return l_err;
}

} // End namespace EXPSCOM
