/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/errlud_expscom.C $                          */
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
/**
 *  @file errlud_expscom.C
 *  @brief Utility to add Explorer logs to your hostboot error
 */
#include "errlud_expscom.H"
#include "expscom_trace.H"
#include <errl/hberrltypes.H> // pelSectionHeader_t
#include <exp_fw_log_data.H>  // explorer log gathering tools
#include <fapi2/plat_hwp_invoker.H> // FAPI_INVOKE_HWP
#include <expscom/expscom_reasoncodes.H> // user-detail subsections
#include <errl/errlmanager.H> // errlCommit

using namespace EXPSCOM;

// Main function to add Explorer logs to a HB error log
bool EXPSCOM::expAddLog( const exp_log_type i_type,
                         TARGETING::Target * i_ocmb,
                         errlHndl_t & io_errl )
{
    bool l_logsAdded = false;
    explog_section_header_t l_header; // use 0 defaults

    // Meta data included with each section
    const uint32_t META_SECTION_SIZE = sizeof(l_header) +
                                       sizeof(ERRORLOG::pelSectionHeader_t);

    // @todo RTC 214628
    // Hopefully create a way to tell how much room is left in io_errl
    uint32_t l_bytesAvailableInLog = 4 * KILOBYTE;

    if (l_bytesAvailableInLog > META_SECTION_SIZE)
    {
        errlHndl_t l_errl = nullptr;
        std::vector<uint8_t>l_error_log_data; // explorer error entry data
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(i_ocmb);

        // Make HWP call to grab explorer error log data
        if (i_type == EXPSCOM::ACTIVE_LOG)
        {
            TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                            "exp_active_error_log");
            FAPI_INVOKE_HWP( l_errl, exp_active_log,
                             l_fapi_ocmb_target, l_error_log_data );
        }
        else
        {
// TODO RTC:205128 - enable after exp_fw_log_data.H updated in EKB
            TRACFCOMP( g_trac_expscom,
                INFO_MRK "HWP exp_saved_log not supported yet" );
            return false;
//          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
//                    "exp_saved_error_log");

//          FAPI_INVOKE_HWP( l_errl, exp_saved_log,
//                           l_fapi_ocmb_target, l_error_log_data );
        }

        if (l_errl)
        {
            // Unable to grab explorer error log data
            TRACFCOMP( g_trac_expscom, ERR_MRK "Unable to grab explorer error "
                            "log data");
            l_errl->collectTrace(EXPSCOM_COMP_NAME);

            // This error is not a system critical failure, should be just noted
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Associate this error with the original explorer failure log
            l_errl->plid(io_errl->plid());
            errlCommit(l_errl, EXPSCOM_COMP_ID);
        }
        else
        {
            // Cycle through data and add sections to io_errl
            // Most recent error log entries are at the end of the data returned
            // so need to work backwards from the end
            l_header.error_data_size = FIRST_EXPLORER_DATA_SECTION_SIZE;
            uint32_t l_explorer_bytes_left = l_error_log_data.size();
            uint8_t * l_end_ptr = l_error_log_data.data() +
                                    l_explorer_bytes_left;

            // while explorer data to append
            while (l_explorer_bytes_left && l_bytesAvailableInLog)
            {
                // Can we add a full packet size of error data?
                if (l_bytesAvailableInLog >
                    (l_header.error_data_size + META_SECTION_SIZE))
                {
                    // Check if we don't have full packet of explorer error data
                    if (l_explorer_bytes_left < l_header.error_data_size)
                    {
                        // Reduce the packet size to include the last of
                        // explorer error data
                        l_header.error_data_size = l_explorer_bytes_left;
                    }
                }
                // Any room left for another section?
                else if ( l_bytesAvailableInLog > META_SECTION_SIZE )
                {
                    // Is there enough explorer error data for room available?
                    if ( l_explorer_bytes_left >=
                         (l_bytesAvailableInLog - META_SECTION_SIZE) )
                    {
                        // Not enough room is available for all the remaining
                        // explorer error data
                        // Use up the rest of the space available
                        l_header.error_data_size = l_bytesAvailableInLog -
                                                    META_SECTION_SIZE;
                    }
                    else
                    {
                        // Room is available but not enough explorer data for
                        // full packet size
                        // Reduce the packet size to include the last of
                        // explorer error data
                        l_header.error_data_size = l_explorer_bytes_left;
                    }
                }
                else
                {
                    // No more space available in hostboot error log
                    break;
                }

                // Offset into explorer error log data returned
                l_header.offset_exp_log = l_explorer_bytes_left -
                                          l_header.error_data_size;

                // Add the section entry to the HWP error log
                if ( i_type == EXPSCOM::ACTIVE_LOG )
                {
                    ExpscomActiveLogUD(l_header,
                                       (l_end_ptr - l_header.error_data_size)).
                                        addToLog(io_errl);
                }
                else
                {
                    ExpscomSavedLogUD(l_header,
                                      (l_end_ptr - l_header.error_data_size)).
                                        addToLog(io_errl);
                }
                l_logsAdded = true;

                // Update to next packet of Explorer error log data
                // Update to always be the tail of data to add
                l_end_ptr -= l_header.error_data_size;
                l_header.packet_num++;
                l_explorer_bytes_left -= l_header.error_data_size;
                l_bytesAvailableInLog -=
                    (META_SECTION_SIZE + l_header.error_data_size);
                l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
            }
        }
    }
    else
    {
      TRACFCOMP( g_trac_expscom, INFO_MRK
            "expAddErrorLog: Unable to add any %d type error logs,"
            " only have %d bytes available in log",
            i_type, l_bytesAvailableInLog );
    }
    return l_logsAdded;
}

//------------------------------------------------------------------------------
//  Expscom Active Log User Details
//------------------------------------------------------------------------------
ExpscomActiveLogUD::ExpscomActiveLogUD(
                                const explog_section_header_t & i_header_info,
                                const uint8_t * i_data_portion )
{
    // Set up Ud instance variables
    iv_CompId = EXPSCOM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EXPSCOM_UDT_ACTIVE_LOG;

    uint8_t * l_pBuf = reallocUsrBuf( sizeof(i_header_info) +
                                      i_header_info.error_data_size );

    memcpy(l_pBuf, &i_header_info, sizeof(i_header_info));
    l_pBuf += sizeof(i_header_info);
    memcpy(l_pBuf, i_data_portion, i_header_info.error_data_size);
    l_pBuf += i_header_info.error_data_size;
}

ExpscomActiveLogUD::~ExpscomActiveLogUD()
{
}

//------------------------------------------------------------------------------
//  Expscom Saved Log User Details
//------------------------------------------------------------------------------
ExpscomSavedLogUD::ExpscomSavedLogUD(
                                const explog_section_header_t & i_header_info,
                                const uint8_t * i_data_portion )
{
    // Set up Ud instance variables
    iv_CompId = EXPSCOM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EXPSCOM_UDT_SAVED_LOG;

    uint8_t * l_pBuf = reallocUsrBuf( sizeof(i_header_info) +
                                      i_header_info.error_data_size );

    memcpy(l_pBuf, &i_header_info, sizeof(i_header_info));
    l_pBuf += sizeof(i_header_info);
    memcpy(l_pBuf, i_data_portion, i_header_info.error_data_size);
    l_pBuf += i_header_info.error_data_size;
}

ExpscomSavedLogUD::~ExpscomSavedLogUD()
{
}
