/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expscom/i2cscomdd.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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
 *  @file i2cscomdd.C
 *
 *  @brief Implementation of I2C SCOM operations to OCMB chip             */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>      // errlCommit
#include <lib/i2c/exp_i2c_scom.H>  // i2c_get_scom
#include <errl/errludtarget.H>     // ErrlUserDetailsTarget
#include <hwpf/fapi2/include/fapi2_hwp_executor.H> // FAPI_EXEC_HWP
#include <expscom/expscom_reasoncodes.H> //  EXPSCOM::MOD_I2CSCOM_PERFORM_OP
#include "i2cscomdd.H" //i2cScomPerformOp
#include "expscomtrace.H" //g_trac_expscom

namespace I2CSCOMDD
{

constexpr uint64_t FIRST_4_BYTES = 0xFFFFFFFF00000000;

/**
 * @brief Performs validation of params passed into i2cScomPerformOp function
 * This function checks that the target type, the address format, the buffer length
 * and the op type are all valid. A unique error will be created for each violation.
 * If multiple error are found the last error will be returned and all previous errors
 * found will be committed as new errors are found (see function).
 *
 * @param[in]   i_opType      Operation type, see DeviceFW::OperationType
 *                            in driverif.H
 * @param[in]   i_target      TARGETING::Target passed to i2cScomPerformOp
 * @param[in]   i_buflen      size of buffer passed to i2cScomPerformOp
 *                            (i_buflen is expected to be 8 bytes)
 * @param[in]   i_scomAddr    Scom address operation will be performed on

 * @return  errlHndl_t        nullptr on success, non-null ptr on error
 */
errlHndl_t validateInputs(DeviceFW::OperationType i_opType,
                          const TARGETING::Target* i_target,
                          size_t i_buflen,
                          uint64_t i_scomAddr);

///////////////////////////////////////////////////////////////////////////////
// See header for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t i2cScomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    // The only extra arg should be the scomAddress
    uint64_t l_scomAddr = va_arg(i_args,uint64_t);

    // The fapi2 put/get i2cScom interfaces require a fapi2::buffer so convert
    // to a uint64_t buffer (for IBM scom) and uint32_t buffer (for Microchip scoms)
    fapi2::buffer<uint64_t> l_fapi2Buffer64(*reinterpret_cast<uint64_t *>(io_buffer));
    fapi2::buffer<uint32_t> l_fapi2Buffer32;
    l_fapi2Buffer64.extractToRight<32,32>(l_fapi2Buffer32);

    do
    {
        // First make sure the inputs are valid
        l_err = validateInputs ( i_opType, i_target, l_scomAddr, io_buflen);

        if(l_err)
        {
            break;
        }

        // Check if this is a IBM_SCOM address by &ing the address with IBM_SCOM_INDICATOR
        // If the indicator is not set, then we will assume this is a microChip address
        if( (l_scomAddr & mss::exp::i2c::IBM_SCOM_INDICATOR) == mss::exp::i2c::IBM_SCOM_INDICATOR)
        {
            // READ and WRITE equates to i2c_get_scom and i2c_put_scom respectively. any other OP is invalid
            // i/o data is expected to be 8 bytes for IBM scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_get_scom,
                              i_target, static_cast<uint32_t>(l_scomAddr),
                              l_fapi2Buffer64);

                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> i2c_get_scom failed for HUID 0x%x Address 0x%lx ",
                               TARGETING::get_huid(i_target), l_scomAddr );
                }
                else
                {
                    // Copy contents of what we read to io_buffer
                    memcpy(io_buffer, reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()), sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_put_scom, i_target, static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer64);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> i2c_put_scom failed for HUID 0x%x Address 0x%lx ",
                               TARGETING::get_huid(i_target), l_scomAddr );
                }
            }
        }
        else
        {
            // READ and WRITE equates to i2c_get_scom and i2c_put_scom respectively. any other OP is invalid
            // i/o data is expected to be 4 bytes for Microchip scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_get_scom, i_target, static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> i2c_get_scom failed for HUID 0x%x Address 0x%lx ",
                              TARGETING::get_huid(i_target), l_scomAddr );
                }
                else
                {
                    // Put the contexts of the 32 bit buffer right justified into the 64 bit buffer
                    l_fapi2Buffer64.flush<0>();
                    l_fapi2Buffer64.insertFromRight<32,32>(l_fapi2Buffer32);
                    // Copy contents of 64 bit buffer to io_buffer
                    memcpy(io_buffer, reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()), sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_put_scom, i_target, static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> i2c_put_scom failed for HUID 0x%x Address 0x%lx ",
                              TARGETING::get_huid(i_target), l_scomAddr );
                }
            }

        }

    } while (0);
    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
// See above for doxygen documentation
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

    // Only target we can perform i2c scoms on like this are explorer OCMB chip targets
    if( l_targetModel != TARGETING::MODEL_EXPLORER )
    {
        TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> Invalid model type : l_targetModel=%d", l_targetModel );
        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_I2CSCOM_PERFORM_OP
          * @reasoncode   EXPSCOM::RC_INVALID_MODEL_TYPE
          * @userdata1          SCOM Address
          * @userdata2[0:31]    Model Type
          * @userdata2[32:63]   Target Huid
          * @devdesc      i2cScomPerformOp> Invalid target type (!= OCMB_CHP)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid target type for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_I2CSCOM_PERFORM_OP,
                                        EXPSCOM::RC_INVALID_MODEL_TYPE,
                                        i_scomAddr,
                                        TWO_UINT32_TO_UINT64(l_targetModel,
                                                             TARGETING::get_huid(i_target)),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(EXPSCOM_COMP_NAME);
        ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
          addToLog(l_err);
        l_commonPlid = l_err->plid();
    }
    // The address is really only 32 bits, we will cast it to 32 bits before passing to
    // the fapi2 i2c_get_scom function but just to be safe make sure that first 4 bytes are 0s
    if( i_scomAddr & FIRST_4_BYTES )
    {
        TRACFCOMP( g_trac_expscom,
                    ERR_MRK "i2cScomPerformOp> Invalid address : i_scomAddr=0x%lx , first 32 bits should be 0's",
                    i_scomAddr );

        // If there is already an error from prev checks, then commit it
        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_I2CSCOM_PERFORM_OP
          * @reasoncode   EXPSCOM::RC_INVALID_ADDRESS
          * @userdata1    SCOM Address
          * @userdata2    Target HUID
          * @devdesc      i2cScomPerformOp> Invalid scom address, first 4
          *               bytes should be 0's
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid address for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_I2CSCOM_PERFORM_OP,
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

    // The buffer passed into i2cScomPerformOp should ALWAYS be 8 bytes.
    // If it is an IBM scom then all 8 bytes are used. If its microchip scom
    // then only the last 4 bytes are used.
    if (i_buflen != sizeof(uint64_t))
    {
        TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> Invalid data length : io_buflen=%d ,"
                    " expected sizeof(uint64_t)", i_buflen );

        // If there is already an error from prev checks, then commit it
        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_I2CSCOM_PERFORM_OP
          * @reasoncode   EXPSCOM::RC_INVALID_LENGTH
          * @userdata1    SCOM Address
          * @userdata2    Data Length
          * @devdesc      i2cScomPerformOp> Invalid data length (!= 8 bytes)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid data length for a SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_I2CSCOM_PERFORM_OP,
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
        TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> Invalid operation type : i_opType=%d", i_opType );

        if(l_err)
        {
            errlCommit(l_err, EXPSCOM_COMP_ID);
        }

        /*@
          * @errortype
          * @moduleid     EXPSCOM::MOD_I2CSCOM_PERFORM_OP
          * @reasoncode   EXPSCOM::RC_INVALID_OPTYPE
          * @userdata1    SCOM Address
          * @userdata2    Op Type
          * @devdesc      i2cScomPerformOp> Invalid operation type (!= READ or WRITE)
          * @custdesc     A problem occurred during the IPL of the system:
          *               Invalid SCOM operation.
          */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EXPSCOM::MOD_I2CSCOM_PERFORM_OP,
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


DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::I2CSCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      i2cScomPerformOp);


}