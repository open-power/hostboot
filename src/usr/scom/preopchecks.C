/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/preopchecks.C $                                  */
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
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <scom/scomreasoncodes.H>
#include <scom/scomif.H>

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{

/**
 * @brief Common routine that verifies input parameters for *scom accesses.
 *
 * @param[in]   i_opType       Operation type, see driverif.H
 * @param[in]   i_target       Scom target
 * @param[in]   i_buffer       Read: Pointer to output data storage
 *                             Write: Pointer to input data storage
 * @param[in]   i_buflen       Input: size of io_buffer (in bytes)
 * @param[in]   i_addr         Address being accessed (Used for FFDC)
 * @return  errlHndl_t
 */
errlHndl_t scomOpSanityCheck(const DeviceFW::OperationType i_opType,
                             const TARGETING::Target* i_target,
                             const void* i_buffer,
                             const size_t i_buflen,
                             const uint64_t i_addr,
                             const size_t i_minbufsize)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP(g_trac_scom, INFO_MRK
              ">>scomOpSanityCheck: Entering Function");

    do
    {
        // In HOSTBOOT_RUNTIME we rely on OPAL to perform indirect scoms,
        // but PHYP wants us to do it ourselves.  Therefore we need to
        // allow 64-bit addresses to flow through in OPAL/Sapphire mode.
        bool l_allowIndirectScoms = false;
#ifdef __HOSTBOOT_RUNTIME
        if( TARGETING::is_sapphire_load() )
        {
            l_allowIndirectScoms = true;
        }
#endif // __HOSTBOOT_RUNTIME

        // Verify address is not over 32-bits long
        if( (0 != (i_addr & 0xFFFFFFFF00000000))
            && (!l_allowIndirectScoms) )
        {
            TRACFCOMP(g_trac_scom, ERR_MRK
                      "scomOpSanityCheck: Impossible address. i_addr=0x%.16X",
                      i_addr);

            /*@
             * @errortype
             * @moduleid     SCOM_OP_SANITY_CHECK
             * @reasoncode   SCOM_INVALID_ADDR
             * @userdata1    Scom address
             * @userdata2    Scom target
             * @devdesc      The provided address is over 32 bits long
             *               which makes it invalid.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_OP_SANITY_CHECK,
                                  SCOM_INVALID_ADDR,
                                  i_addr,
                                  get_huid(i_target));
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }

        // Verify data buffer
        if ( (i_buflen < i_minbufsize) ||
             (i_buffer == NULL) )
        {
            TRACFCOMP(g_trac_scom, ERR_MRK
                      "scomOpSanityCheck: Invalid buffer. i_buflen=0x%X",
                      i_buflen);
            /*@
             * @errortype
             * @moduleid     SCOM_OP_SANITY_CHECK
             * @reasoncode   SCOM_INVALID_DATA_BUFFER
             * @userdata1[0:31]    Buffer size
             * @userdata1[32:63]   Minimum allowed buffer size
             * @userdata2    Scom address
             * @devdesc      Buffer size is less than allowed
             *               or NULL data buffer
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_OP_SANITY_CHECK,
                                  SCOM_INVALID_DATA_BUFFER,
                                  TWO_UINT32_TO_UINT64(
                                                i_buflen,
                                                i_minbufsize),
                                  i_addr);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }

        // Verify OP type
        if ( (i_opType != DeviceFW::READ) &&
             (i_opType != DeviceFW::WRITE) )
        {
            TRACFCOMP(g_trac_scom, ERR_MRK
                      "scomOpSanityCheck: Invalid opType. i_opType=0x%X",
                      i_opType);
            /*@
             * @errortype
             * @moduleid     SCOM_OP_SANITY_CHECK
             * @reasoncode   SCOM_INVALID_OP_TYPE
             * @userdata1    Operation type
             * @userdata2    Scom address
             * @devdesc      Scom invalid operation type
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_OP_SANITY_CHECK,
                                  SCOM_INVALID_OP_TYPE,
                                  i_opType,
                                  i_addr);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }


    } while(0);

    return l_err;
}

}  // end namespace SCOM
