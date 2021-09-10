/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/mdsAccessUtils.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 * @file mdsAccessUtils.C
 *
 * @brief Provides common utility functions for the MDS controller
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include "mdsAccessUtils.H" // validateMdsI2cScomInputs
#include "mdsAccessTrace.H" // g_trac_mdsaccess
#include <errl/errludtarget.H>   // ErrlUserDetailsTarget
#include <mdsaccess/mdsaccess_reasoncodes.H> // MDS access ReasonCodes/ModuleIds

namespace MDS_ACCESS
{

// Mask to extract the 1st 4 bytes of a 64 bit integer
constexpr uint64_t FIRST_4_BYTES = 0xFFFFFFFF00000000;

///////////////////////////////////////////////////////////////////////////////
// See header file for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t validateMdsI2cScomInputs(DeviceFW::OperationType i_opType,
                                    const TARGETING::Target* i_target,
                                    const void* const        i_buffer,
                                    size_t                   i_buflen,
                                    uint64_t                 i_scomAddr)
{
    errlHndl_t l_err = nullptr;

    // Cache user data 1 info, it is all the same for most error logs - target
    // HUID and input buffer length
    uint64_t l_userData1 = TWO_UINT32_TO_UINT64(TARGETING::get_huid(i_target), i_buflen);

    do
    {
        // Cache the Target's TYPE for quick reference
        const auto l_targetType = i_target->getAttr<TARGETING::ATTR_TYPE>();

        // Verify that the target is of type MDS_CTLR.
        // Only target we can perform MDS scoms on, are MDS_CTLR targets
        if( l_targetType != TARGETING::TYPE_MDS_CTLR )
        {
            TRACFCOMP( g_trac_mdsaccess, ERR_MRK "validateMdsI2cScomInputs> Invalid target type: "
                       "received = 0x%.8X, expected = 0x%.8X",
                       l_targetType, TARGETING::TYPE_MDS_CTLR );

            /*@
             * @errortype
             * @moduleid     MDS_ACCESS::MOD_MDS_UTILS
             * @reasoncode   MDS_ACCESS::RC_INVALID_TARGET_TYPE
             * @userdata1[0:31]  Target's HUID
             * @userdata1[32:63] Buffer data length
             * @userdata2    SCOM Address
             * @devdesc      MDS_ACCESS::validateMdsI2cScomInputs> Invalid
             *               target type (!= MDS_CTLR)
             * @custdesc     A firmware problem occurred during IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MDS_ACCESS::MOD_MDS_UTILS,
                                            MDS_ACCESS::RC_INVALID_TARGET_TYPE,
                                            l_userData1,
                                            i_scomAddr,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            ERRORLOG::ErrlUserDetailsTarget(i_target,"MDS SCOM Target").addToLog(l_err);

            // break and return error log to caller
            break;
        } // if( l_targetType != TARGETING::TYPE_MDS_CTLR )

        // The address passed to the MDS scom functions is really only 32 bits.
        // Verify the first 4 bytes are 0s.
        if( i_scomAddr & FIRST_4_BYTES )
        {
            TRACFCOMP( g_trac_mdsaccess,
                        ERR_MRK "validateMdsI2cScomInputs> Invalid SCOM address: received "
                                "= 0x%lX, expected = first 32 bits should be 0's", i_scomAddr );

            /*@
             * @errortype
             * @moduleid     MDS_ACCESS::MOD_MDS_UTILS
             * @reasoncode   MDS_ACCESS::RC_INVALID_SCOM_ADDRESS
             * @userdata1[0:31]  Target's HUID
             * @userdata1[32:63] Buffer data length
             * @userdata2    SCOM Address
             * @devdesc      MDS_ACCESS::validateMdsI2cScomInputs> Invalid scom address, first 4
             *               bytes should be 0's
             * @custdesc     A firmware problem occurred during IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MDS_ACCESS::MOD_MDS_UTILS,
                                            MDS_ACCESS::RC_INVALID_SCOM_ADDRESS,
                                            l_userData1,
                                            i_scomAddr,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            ERRORLOG::ErrlUserDetailsTarget(i_target,"MDS SCOM Target").addToLog(l_err);

            // break and return error log to caller
            break;
        } // if( i_scomAddr & FIRST_4_BYTES )

        // The buffer passed to the MDS scom functions should ALWAYS be 8 bytes.
        if (i_buflen != sizeof(uint64_t))
        {
            TRACFCOMP( g_trac_mdsaccess, ERR_MRK "validateMdsI2cScomInputs> Invalid buffer data "
                       "length: received = %d, expected = sizeof(uint64_t) or %d bytes",
                       i_buflen, sizeof(uint64_t) );

            /*@
             * @errortype
             * @moduleid     MDS_ACCESS::MOD_MDS_UTILS
             * @reasoncode   MDS_ACCESS::RC_INVALID_BUFFER_LENGTH
             * @userdata1[0:31]  Target's HUID
             * @userdata1[32:63] Buffer data length
             * @userdata2    SCOM Address
             * @devdesc      MDS_ACCESS::validateMdsI2cScomInputs> Invalid
             *               buffer data length (!= 8 bytes)
             * @custdesc     A firmware problem occurred during IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MDS_ACCESS::MOD_MDS_UTILS,
                                            MDS_ACCESS::RC_INVALID_BUFFER_LENGTH,
                                            l_userData1,
                                            i_scomAddr,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            ERRORLOG::ErrlUserDetailsTarget(i_target,"MDS SCOM Target").addToLog(l_err);

            // break and return error log to caller
            break;
        } // if (i_buflen != sizeof(uint64_t))

        // Verify that data buffer, whether for input or output, is not NULL
        if (nullptr == i_buffer)
        {
            TRACFCOMP( g_trac_mdsaccess,
                       ERR_MRK "validateMdsI2cScomInputs> Invalid NULL data buffer, "
                               "it should not be NULL");

            /*@
             * @errortype
             * @moduleid     MDS_ACCESS::MOD_MDS_UTILS
             * @reasoncode   MDS_ACCESS::RC_INVALID_DATA_BUFFER
             * @userdata1[0:31]  Target's HUID
             * @userdata1[32:63] Buffer data length
             * @userdata2    SCOM Address
             * @devdesc      MDS_ACCESS::validateMdsI2cScomInputs> Invalid
             *               data buffer (== nullptr)
             * @custdesc     A firmware problem occurred during IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MDS_ACCESS::MOD_MDS_UTILS,
                                            MDS_ACCESS::RC_INVALID_DATA_BUFFER,
                                            l_userData1,
                                            i_scomAddr,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            ERRORLOG::ErrlUserDetailsTarget(i_target,"MDS SCOM Target").addToLog(l_err);

            // break and return error log to caller
            break;
        } // if (nullptr == i_buffer)

        // The only valid operations are READ and WRITE, anything else is an error
        if ( (i_opType != DeviceFW::READ) && (i_opType != DeviceFW::WRITE) )
        {
            TRACFCOMP( g_trac_mdsaccess,
                       ERR_MRK "validateMdsI2cScomInputs> Invalid operation type: "
                               "received = %d, expected = read(%d) or write(%d)",
                               i_opType, DeviceFW::READ, DeviceFW::WRITE  );

            /*@
             * @errortype
             * @moduleid     MDS_ACCESS::MOD_MDS_UTILS
             * @reasoncode   MDS_ACCESS::RC_INVALID_OPTYPE
             * @userdata1[0:31]  Target's HUID
             * @userdata1[32:47] Buffer data length
             * @userdata1[47:63] Operation Type
             * @userdata2    SCOM Address
             * @devdesc      MDS_ACCESS::validateMdsI2cScomInputs> Invalid Operation
             *               type (!= READ or WRITE)
             * @custdesc     A firmware problem occurred during IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MDS_ACCESS::MOD_MDS_UTILS,
                                            MDS_ACCESS::RC_INVALID_OPTYPE,
                                            TWO_UINT32_TO_UINT64(TARGETING::get_huid(i_target),
                                               TWO_UINT16_TO_UINT32(i_buflen, i_opType) ),
                                            i_scomAddr,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            ERRORLOG::ErrlUserDetailsTarget(i_target,"MDS SCOM Target").addToLog(l_err);

            // break and return error log to caller
            break;
        }  // if ( (i_opType != DeviceFW::READ) && (i_opType != DeviceFW::WRITE) )
    } while (0);

    return l_err;
}

} // namespace MDS_ACCESS
