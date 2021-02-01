/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/sbeio_vpd_override.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
*  @file sbeio_vpd_override.C
*
*  @brief implements sbeApplyVpdOverrides(). Invoked as an SBE_MSG passthrough
*         during hbrt to apply overrides to MVPD. Currently, overriding SPD and
*         WOF data sections are not supported, but the hooks are in place to add
*         that support in the future
*/

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/vpd_if.H>
#include <targeting/common/util.H>
#include <devicefw/driverif.H>
#include <secureboot/service.H>

#include <sbeio/runtime/sbeio_vpd_override.H>

#include <eeprom/eepromif.H>

#include <sbeio/runtime/sbe_msg_passing.H>

extern trace_desc_t* g_trac_vpd;

using namespace ERRORLOG;
using namespace VPD;


namespace SBE_MSG
{


//-------------------------------------------------------------------------
errlHndl_t sbeApplyVpdOverrides(TARGETING::TargetHandle_t i_procTgt,
                                uint32_t   i_reqDataSize,
                                uint8_t  * i_reqData,
                                uint32_t * o_rspStatus,
                                uint32_t * o_rspDataSize,
                                uint8_t  * o_rspData )
{

    TRACFCOMP( g_trac_vpd, "sbeApplyVpdOverrides");

    errlHndl_t l_errhdl(nullptr);
    *o_rspStatus = 0;
    *o_rspDataSize = 0; //No return data

    do {

    bool l_allowOverrides = true;

    #ifdef CONFIG_SECUREBOOT
    l_allowOverrides = SECUREBOOT::allowAttrOverrides();
    #endif

    if (!l_allowOverrides)
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: skipping override due "
                                       "to SECUREBOOT enablement");
        /*@
         * @errortype
         * @moduleid          VPD_RT_OVERRIDE
         * @reasoncode        VPD_OVERRIDE_NOT_ALLOWED
         * @userdata1         <unused>
         * @userdata2         <unused>
         * @devdesc           Skipping VPD override because of
         *                    secureboot enablement
         * @custdesc          VPD overrides are not allowed in
         *                    secure mode
         */
        l_errhdl = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                  VPD_RT_OVERRIDE,
                                  VPD_OVERRIDE_NOT_ALLOWED,
                                  0,
                                  0,
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // if the i_reqDataSize is less than or exactly equal to vpdCmdHeader_t size
    // then that means there isn't any data to write so error out
    if (i_reqDataSize <= sizeof(vpdCmdHeader_t))
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: i_reqDataSize too small. "
                               "Expected size strictly > %d bytes, received i_reqDataSize = %d",
                                sizeof(vpdCmdHeader_t), i_reqDataSize);
        /*@
         * @errortype
         * @moduleid          VPD_RT_OVERRIDE
         * @reasoncode        VPD_SHORT_REQUEST
         * @userdata1[0:31]   size of the incoming request
         * @userdata1[32:63]  minimum request size
         * @userdata2         huid of the target
         * @devdesc           the incoming request is too small
         * @custdesc          Invalid client API request
         */
        l_errhdl = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                  VPD_RT_OVERRIDE,
                                  VPD_SHORT_REQUEST,
                                  TWO_UINT32_TO_UINT64(i_reqDataSize,
                                                       sizeof(vpdCmdHeader_t) + 1),
                                  TARGETING::get_huid(i_procTgt),
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // extract the data from the i_reqData blob
    vpdOverwriteCmd_t overwriteCmd(i_reqData, i_reqDataSize);

    // if the upper 4 bits are all 0's, then a write is requested
    // if any of the upper 4 bits of dataSectionAndMethod are set, assume the request is a read
    /** reads in this function should only be used for excercising test cases **/
    bool isRead = (overwriteCmd.header->dataSectionAndMethod & READ_CMD_MASK) != 0;

    // disable writes to HW and FSP, allowing client to
    // perform writes only to the cached data stores
    EEPROM::setAllowVPDOverrides(true);

    if((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == MVPD_KEYWORD_RECORD ||
       (overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == SPD_KEYWORD_RECORD)
    {
        const char * record  = reinterpret_cast<char * >(&overwriteCmd.header->record);
        const char * keyword = reinterpret_cast<char * >(&overwriteCmd.header->keyword);

        uint32_t l_recordEnum = 0;
        uint32_t l_keywordEnum = 0;
        l_errhdl = mvpdRecordStringtoEnum(record, l_recordEnum);

        if (l_errhdl)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: recordStringtoEnum "
                                           "failed for %s", record);
            break;
        }

        l_errhdl = mvpdKeywordStringtoEnum(keyword, l_keywordEnum);

        if (l_errhdl)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: keywordStringtoEnum "
                                           "failed for %s", keyword);
            break;
        }

        if ((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == MVPD_KEYWORD_RECORD)
        {

            TARGETING::AttributeTraits<TARGETING::ATTR_TYPE>::Type
                l_targetType = i_procTgt->getAttr<TARGETING::ATTR_TYPE>();
            // call device write if the target is TYPE_PROC
            if (TARGETING::TYPE_PROC == l_targetType)
            {
                size_t l_size = overwriteCmd.dataSizeBytes;
                if (isRead)
                {
                    l_errhdl = deviceRead(i_procTgt, o_rspData, l_size,
                                          DEVICE_MVPD_ADDRESS(l_recordEnum, l_keywordEnum));
                    *o_rspDataSize = l_size;
                }
                else
                {
                    l_errhdl = deviceWrite(i_procTgt, overwriteCmd.data, l_size,
                                          DEVICE_MVPD_ADDRESS(l_recordEnum, l_keywordEnum));
                }

                if (l_errhdl)
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: device%s on record "
                                                   "= %s, keyword = %s failed",
                                                    isRead ? "Read" : "Write",
                                                    record, keyword);
                    break;
                }

            }
            else
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: MVPD override is not "
                                               "supported for non-proc targets, HUID = 0x%X",
                                                TARGETING::get_huid(i_procTgt));
                /*@
                 * @errortype
                 * @moduleid   VPD_RT_OVERRIDE_MVPD_REC_KEY
                 * @reasoncode VPD_TARGET_NOT_TYPE_PROC
                 * @userdata1  HUID of the target
                 * @userdata2  ATTR_TYPE of the target
                 * @devdesc    writing to non PROC targets is not supported
                 * @custdesc   Invalid client API request
                 */
                l_errhdl = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                          VPD_RT_OVERRIDE_MVPD_REC_KEY,
                                          VPD_TARGET_NOT_TYPE_PROC,
                                          TARGETING::get_huid(i_procTgt),
                                          l_targetType,
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            }
        }
        else if ((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == SPD_KEYWORD_RECORD)
        {
            TRACFCOMP( g_trac_vpd, INFO_MRK "sbeApplyVpdOverrides: SPD_KEYWORD_RECORD writes "
                                            "not yet supported");
        }
    }
    else if((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == MVPD_OFFSET_NUM_BYTES ||
            (overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == SPD_OFFSET_NUM_BYTES  ||
            (overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == WOF_OFFSET_NUM_BYTES)
    {
        uint64_t l_offset = overwriteCmd.header->keyword;
        uint64_t l_writeNumBytes = overwriteCmd.header->write_len;

        if((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == MVPD_OFFSET_NUM_BYTES)
        {

            TARGETING::AttributeTraits<TARGETING::ATTR_TYPE>::Type
                l_targetType = i_procTgt->getAttr<TARGETING::ATTR_TYPE>();
            if (TARGETING::TYPE_PROC == l_targetType)
            {
                if ((l_writeNumBytes != overwriteCmd.dataSizeBytes) && !isRead)
                {
                    // if we are attempting to write,
                    // but l_writeNumBytes calculated != overwriteCmd.dataSizeBytes specified,
                    // then error out
                    TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: Number of bytes "
                                                   "to write != overwriteCmd.dataSizeBytes, "
                                                   "%d != %d", l_writeNumBytes,
                                                    overwriteCmd.dataSizeBytes);
                    /*@
                     * @errortype
                     * @moduleid   VPD_RT_OVERRIDE_MVPD_OFFSET
                     * @reasoncode VPD_BYTES_TO_WRITE_MISMATCH
                     * @userdata1  number of bytes to write specified by caller
                     * @userdata2  size in bytes of the data to write
                     * @devdesc    Number of bytes to write != data size bytes
                     * @custdesc   Invalid client API request
                     */
                    l_errhdl = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                              VPD_RT_OVERRIDE_MVPD_OFFSET,
                                              VPD_BYTES_TO_WRITE_MISMATCH,
                                              l_writeNumBytes,
                                              overwriteCmd.dataSizeBytes,
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    break;

                }

                if (isRead)
                {
                    l_errhdl = DeviceFW::deviceOp( DeviceFW::READ,
                                                   i_procTgt,
                                                   o_rspData,
                                                   l_writeNumBytes,
                                                   DEVICE_EEPROM_ADDRESS(
                                                       EEPROM::VPD_AUTO,
                                                       l_offset,
                                                       EEPROM::AUTOSELECT) );
                    *o_rspDataSize = l_writeNumBytes;
                }
                else
                {
                    l_errhdl = DeviceFW::deviceOp( DeviceFW::WRITE,
                                                   i_procTgt,
                                                   overwriteCmd.data,
                                                   l_writeNumBytes,
                                                   DEVICE_EEPROM_ADDRESS(
                                                       EEPROM::VPD_AUTO,
                                                       l_offset,
                                                       EEPROM::AUTOSELECT) );
                }

                if (l_errhdl)
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: MVPD deviceWrite to offset "
                                                   "= 0x%X failed", l_offset);
                    break;
                }

            }
            else
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: MVPD override is not "
                                               "supported for non-proc targets, HUID = 0x%X",
                                                TARGETING::get_huid(i_procTgt));
                /*@
                 * @errortype
                 * @moduleid   VPD_RT_OVERRIDE_MVPD_OFFSET
                 * @reasoncode VPD_TARGET_NOT_TYPE_PROC
                 * @userdata1  HUID of the target
                 * @userdata2  unused
                 * @devdesc    writing to the MVPD of a non-PROC target is not supported
                 * @custdesc   Invalid client API request
                 */
                l_errhdl = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                          VPD_RT_OVERRIDE_MVPD_OFFSET,
                                          VPD_TARGET_NOT_TYPE_PROC,
                                          TARGETING::get_huid(i_procTgt),
                                          0,
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }
        }
        else if ((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == SPD_OFFSET_NUM_BYTES)
        {
            TRACFCOMP( g_trac_vpd, INFO_MRK "sbeApplyVpdOverrides: SPD_OFFSET_NUM_BYTES writes "
                                            "not yet supported");
        }
        else if ((overwriteCmd.header->dataSectionAndMethod & DATA_SECTION_MASK) == WOF_OFFSET_NUM_BYTES)
        {
            TRACFCOMP( g_trac_vpd, INFO_MRK "sbeApplyVpdOverrides: WOF_OFFSET_NUM_BYTES writes "
                                            "not yet supported");
        }
    }
    else
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK "sbeApplyVpdOverrides: invalid dataSectionAndMethodFlag = 0x%X",
                                        overwriteCmd.header->dataSectionAndMethod);
        /*@
         * @errortype
         * @moduleid   VPD_RT_OVERRIDE
         * @reasoncode VPD_INVALID_METHOD_OR_DATA_SECTION
         * @userdata1  the invalid value for the method and data section to write to
         * @userdata2  unused
         * @devdesc    invalid data section/write method enum was passed
         * @custdesc   Invalid client API request
         */
        l_errhdl = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                                  VPD_RT_OVERRIDE,
                                  VPD_INVALID_METHOD_OR_DATA_SECTION,
                                  overwriteCmd.header->dataSectionAndMethod,
                                  0,
                                  ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

        l_errhdl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_LOW);
    }


    } while(0);

    if (l_errhdl)
    {   // if error, return a bad status
        *o_rspStatus = 0xFFFFFFFF; // -1
        *o_rspDataSize = 0;
    }

    return l_errhdl;
} // end sbeApplyVpdOverrides


}//End namespace SBE_MSG
