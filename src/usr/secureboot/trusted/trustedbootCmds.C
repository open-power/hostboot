/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootCmds.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 * @file trustedbootCmds.C
 *
 * @brief Trusted boot TPM command interfaces
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <i2c/tpmddif.H>
#include <secureboot/trustedbootif.H>
#include <i2c/tpmddreasoncodes.H>
#include "trustedboot.H"
#include "trustedTypes.H"
#include <secureboot/trustedboot_reasoncodes.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)

namespace TRUSTEDBOOT
{


errlHndl_t tpmTransmitCommand(TRUSTEDBOOT::TpmTarget & io_target,
                              uint8_t* io_buffer,
                              size_t i_bufsize )
{
    errlHndl_t err = NULL;
    uint8_t* transmitBuf = NULL;
    size_t cmdSize = 0;
    size_t dataSize = 0;
    TRUSTEDBOOT::TPM2_BaseIn* cmd =
        reinterpret_cast<TRUSTEDBOOT::TPM2_BaseIn*>(io_buffer);
    TRUSTEDBOOT::TPM2_BaseOut* resp =
        reinterpret_cast<TRUSTEDBOOT::TPM2_BaseOut*>(io_buffer);

    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"TPM TRANSMIT CMD START : BufLen %d : %016llx",
               i_bufsize,
               *(reinterpret_cast<uint64_t*>(io_buffer))  );

    do
    {
        transmitBuf = new uint8_t[MAX_TRANSMIT_SIZE];

        // Marshal the data into a byte array for transfer to the TPM
        err = tpmMarshalCommandData(cmd,
                                    transmitBuf,
                                    MAX_TRANSMIT_SIZE,
                                    cmdSize);
        if (NULL != err)
        {
            break;
        }


        // Send to the TPM
        dataSize = MAX_TRANSMIT_SIZE;
        err = deviceRead(io_target.nodeTarget,
                         transmitBuf,
                         dataSize,
                         DEVICE_TPM_ADDRESS( io_target.chip,
                                             TPMDD::TPM_OP_TRANSMIT,
                                             cmdSize));
        if (NULL != err)
        {
            break;
        }

        // Unmarshal the response
        err = tpmUnmarshalResponseData(cmd->commandCode,
                                       transmitBuf,
                                       dataSize,
                                       resp,
                                       i_bufsize);


    } while ( 0 );


    delete transmitBuf;

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmTransmitCommand() - %s",
               ((NULL == err) ? "No Error" : "With Error") );
    return err;
}

errlHndl_t tpmMarshalCommandData(TRUSTEDBOOT::TPM2_BaseIn* i_cmd,
                                 uint8_t* o_outbuf,
                                 size_t i_bufsize,
                                 size_t & o_cmdSize)
{
    errlHndl_t err = NULL;
    uint8_t* sBuf = o_outbuf;
    o_cmdSize = 0;
    int stage = 0;
    TRUSTEDBOOT::TPM2_BaseIn* baseCmd =
        reinterpret_cast<TRUSTEDBOOT::TPM2_BaseIn*>(o_outbuf);

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmMarshalCommandData()" );
    do
    {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM MARSHAL START : BufLen %d : %016llx",
                   i_bufsize,
                   *(reinterpret_cast<uint64_t*>(i_cmd))  );

        // Start with the command header
        sBuf = i_cmd->marshal(sBuf, i_bufsize, o_cmdSize);
        if (NULL == sBuf)
        {
            break;
        }


        // Marshal the handles
        stage = 1;


        // Marshal the authorizations
        stage = 2;

        // Marshal the parameters
        stage = 3;
        switch (i_cmd->commandCode)
        {
            // Two byte parm fields
          case TRUSTEDBOOT::TPM_CC_Startup:
              {
                  TRUSTEDBOOT::TPM2_2ByteIn* cmdPtr =
                      reinterpret_cast<TRUSTEDBOOT::TPM2_2ByteIn*>(i_cmd);
                  sBuf = cmdPtr->marshal(sBuf,
                                         i_bufsize,
                                         o_cmdSize);
              }
              break;

          case TRUSTEDBOOT::TPM_CC_GetCapability:
              {
                  TRUSTEDBOOT::TPM2_GetCapabilityIn* cmdPtr =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityIn*>(i_cmd);
                  sBuf = cmdPtr->marshal(sBuf,
                                         i_bufsize,
                                         o_cmdSize);
              }
              break;

          default:
              {
                  // Command code not supported
                  TRACFCOMP( g_trac_trustedboot,
                             "TPM MARSHAL INVALID COMMAND : %X",
                             i_cmd->commandCode );
                  sBuf = NULL;
                  /*@
                   * @errortype
                   * @reasoncode     RC_TPM_MARSHAL_INVALID_CMD
                   * @severity       ERRL_SEV_UNRECOVERABLE
                   * @moduleid       MOD_TPM_MARSHALCMDDATA
                   * @userdata1      Command Code
                   * @userdata2      0
                   * @devdesc        Unsupported command code during marshal
                   */
                  err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_MARSHALCMDDATA,
                                           RC_TPM_MARSHAL_INVALID_CMD,
                                           i_cmd->commandCode,
                                           0,
                                           true /*Add HB SW Callout*/ );

                  err->collectTrace( SECURE_COMP_NAME );
              }
              break;
        };

        if (NULL != err)
        {
            break;
        }


        // Lastly now that we know the size update the byte stream
        baseCmd->commandSize = o_cmdSize;

    } while ( 0 );

    if (NULL == sBuf && NULL == err)
    {
        TRACFCOMP( g_trac_trustedboot,
                   "TPM MARSHAL FAILURE : Stage %d", stage);
        /*@
         * @errortype
         * @reasoncode     RC_TPM_MARSHALING_FAIL
         * @severity       ERRL_SEV_UNRECOVERABLE
         * @moduleid       MOD_TPM_MARSHALCMDDATA
         * @userdata1      stage
         * @userdata2      0
         * @devdesc        Marshaling error detected
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_TPM_MARSHALCMDDATA,
                                       RC_TPM_MARSHALING_FAIL,
                                       stage,
                                       0,
                                       true /*Add HB SW Callout*/ );

        err->collectTrace( SECURE_COMP_NAME );

    }

    TRACUBIN(g_trac_trustedboot, "Marshal Out",
             o_outbuf, o_cmdSize);

    TRACUCOMP( g_trac_trustedboot,
               "TPM MARSHAL END   : CmdSize: %d : %016llx ",  o_cmdSize,
               *(reinterpret_cast<uint64_t*>(o_outbuf))  );

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmMarshalCommandData()" );

    return err;
}

errlHndl_t tpmUnmarshalResponseData(uint32_t i_commandCode,
                                    uint8_t* i_respBuf,
                                    size_t i_respBufSize,
                                    TRUSTEDBOOT::TPM2_BaseOut* o_outBuf,
                                    size_t i_outBufSize)
{
    errlHndl_t err = NULL;
    uint8_t* sBuf = i_respBuf;
    int stage = 0;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmUnmarshalResponseData()" );

    do {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM UNMARSHAL START : RespBufLen %d : OutBufLen %d",
                   i_respBufSize, i_outBufSize);
        TRACUBIN(g_trac_trustedboot,"Unmarshal In",
                 i_respBuf, i_respBufSize);


        // Start with the response header
        stage = 1;
        sBuf = o_outBuf->unmarshal(sBuf, i_respBufSize, i_outBufSize);
        if (NULL == sBuf)
        {
            break;
        }

        // If the TPM returned a failure it will not send the rest
        // Let the caller deal with the RC
        if (TRUSTEDBOOT::TPM_SUCCESS != o_outBuf->responseCode)
        {
            break;
        }


        // Unmarshal the parameters
        stage = 2;
        switch (i_commandCode)
        {
            // Empty response commands
          case TRUSTEDBOOT::TPM_CC_Startup:
            // Nothing to do
            break;

          case TRUSTEDBOOT::TPM_CC_GetCapability:
              {
                  TRUSTEDBOOT::TPM2_GetCapabilityOut* respPtr =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityOut*>
                      (o_outBuf);
                  sBuf = respPtr->unmarshal(sBuf, i_respBufSize, i_outBufSize);

              }
              break;

          default:
              {
                  // Command code not supported
                  TRACFCOMP( g_trac_trustedboot,
                             "TPM UNMARSHAL INVALID COMMAND : %X",
                             i_commandCode );
                  sBuf = NULL;

                  /*@
                   * @errortype
                   * @reasoncode     RC_TPM_UNMARSHAL_INVALID_CMD
                   * @severity       ERRL_SEV_UNRECOVERABLE
                   * @moduleid       MOD_TPM_UNMARSHALRESPDATA
                   * @userdata1      commandcode
                   * @userdata2      stage
                   * @devdesc        Unsupported command code during unmarshal
                   */
                  err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_UNMARSHALRESPDATA,
                                           RC_TPM_UNMARSHAL_INVALID_CMD,
                                           i_commandCode,
                                           stage,
                                           true /*Add HB SW Callout*/ );

                  err->collectTrace( SECURE_COMP_NAME );
              }
              break;
        }


    } while ( 0 );

    if (NULL == sBuf && NULL == err)
    {
        TRACFCOMP( g_trac_trustedboot,
                   "TPM UNMARSHAL FAILURE : Stage %d", stage);
        /*@
         * @errortype
         * @reasoncode     RC_TPM_UNMARSHALING_FAIL
         * @severity       ERRL_SEV_UNRECOVERABLE
         * @moduleid       MOD_TPM_UNMARSHALRESPDATA
         * @userdata1      Stage
         * @userdata2      Remaining response buffer size
         * @devdesc        Unmarshaling error detected
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_TPM_UNMARSHALRESPDATA,
                                       RC_TPM_UNMARSHALING_FAIL,
                                       stage,
                                       i_respBufSize,
                                       true /*Add HB SW Callout*/ );

        err->collectTrace( SECURE_COMP_NAME );


    }

    TRACUCOMP( g_trac_trustedboot,
               "TPM UNMARSHAL END   : %016llx ",
               *(reinterpret_cast<uint64_t*>(o_outBuf))  );

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmUnmarshalResponseData()" );

    return err;
}

errlHndl_t tpmCmdStartup(TRUSTEDBOOT::TpmTarget & io_target)
{
    errlHndl_t err = NULL;
    uint8_t dataBuf[BUFSIZE];

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmCmdStartup()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmCmdStartup() tgt=0x%X chip=%d",
               TARGETING::get_huid(io_target.nodeTarget),
               io_target.chip);

    do
    {
        // Send the TPM startup command
        // Build our command block for a startup
        memset(dataBuf, 0, sizeof(dataBuf));

        TRUSTEDBOOT::TPM2_BaseOut* resp =
            reinterpret_cast<TRUSTEDBOOT::TPM2_BaseOut*>(dataBuf);

        TRUSTEDBOOT::TPM2_2ByteIn* cmd =
            reinterpret_cast<TRUSTEDBOOT::TPM2_2ByteIn*>(dataBuf);

        cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_Startup;
        cmd->param = TRUSTEDBOOT::TPM_SU_CLEAR;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (NULL != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP transmit Fail %X : ",
                       err->reasonCode() );
            break;

        }
        else if (TRUSTEDBOOT::TPM_SUCCESS != resp->responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP OP Fail %X : ",
                       resp->responseCode);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_START_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_STARTUP
             * @userdata1      node
             * @userdata2      responseCode
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_CMD_STARTUP,
                                           RC_TPM_START_FAIL,
                                           TARGETING::get_huid(
                                              io_target.nodeTarget),
                                           resp->responseCode,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            break;
        }


    } while ( 0 );


    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmCmdStartup() - %s",
               ((NULL == err) ? "No Error" : "With Error") );
    return err;
}

errlHndl_t tpmCmdGetCapFwVersion(TRUSTEDBOOT::TpmTarget & io_target)
{
    errlHndl_t err = NULL;
    uint8_t dataBuf[BUFSIZE];
    size_t dataSize = BUFSIZE;
    uint16_t fwVersion[4] = {0xFF, 0xFF, 0xFF, 0xFF};

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmCmdGetCapFwVersion()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmCmdGetCapFwVersion() tgt=0x%X chip=%d",
               TARGETING::get_huid(io_target.nodeTarget),
               io_target.chip);

    do
    {

        // Build our command block for a get capability of the FW version
        memset(dataBuf, 0, dataSize);

        TRUSTEDBOOT::TPM2_GetCapabilityOut* resp =
            reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityOut*>(dataBuf);
        TRUSTEDBOOT::TPM2_GetCapabilityIn* cmd =
            reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityIn*>(dataBuf);

        cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
        cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
        cmd->property = TRUSTEDBOOT::TPM_PT_FIRMWARE_VERSION_1;
        cmd->propertyCount = 1;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (NULL != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP Transmit Fail %X : ",
                       err->reasonCode() );
            break;

        }

        if (TRUSTEDBOOT::TPM_SUCCESS != resp->base.responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP OP Fail %X Size(%d) ",
                       resp->base.responseCode,
                       dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
             * @userdata1      node
             * @userdata2[0:31] responseCode
             * @userdata2[32:63] dataSize
             * @devdesc        Command failure reading TPM FW version.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_CMD_GETCAPFWVERSION,
                                           RC_TPM_GETCAP_FAIL,
                                           TARGETING::get_huid(
                                              io_target.nodeTarget),
                                           resp->base.responseCode,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            break;
        }
        else
        {
            // Walk the reponse data to pull the high order bytes out

            if (resp->capData.capability != TPM_CAP_TPM_PROPERTIES ||
                resp->capData.data.tpmProperties.count != 1 ||
                resp->capData.data.tpmProperties.tpmProperty[0].property !=
                TPM_PT_FIRMWARE_VERSION_1) {

                TRACFCOMP( g_trac_trustedboot,
                           "TPM GETCAP FW INVALID DATA "
                           "Cap(%X) Cnt(%X) Prop(%X)",
                           resp->capData.capability,
                           resp->capData.data.tpmProperties.count,
                           resp->capData.data.tpmProperties.
                           tpmProperty[0].property);

                /*@
                 * @errortype
                 * @reasoncode     RC_TPM_GETCAP_FW_INVALID_RESP
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
                 * @userdata1      node
                 * @userdata2[0:31] capability
                 * @userdata2[32:63] propery
                 * @devdesc        Command failure reading TPM FW version.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             MOD_TPM_CMD_GETCAPFWVERSION,
                             RC_TPM_GETCAP_FW_INVALID_RESP,
                             TARGETING::get_huid(
                                  io_target.nodeTarget),
                             ((uint64_t)resp->capData.capability << 32) |
                                           resp->capData.data.tpmProperties.
                                           tpmProperty[0].property,
                             true /*Add HB SW Callout*/ );

                err->collectTrace( SECURE_COMP_NAME );
                break;
            }
            else
            {
                fwVersion[0] =
                    (resp->capData.data.
                     tpmProperties.tpmProperty[0].value >> 16);
                fwVersion[1] =
                    (resp->capData.data.
                     tpmProperties.tpmProperty[0].value & 0xFFFF);
            }

        }

        // Read part 2 of the version
        dataSize = BUFSIZE;
        memset(dataBuf, 0, dataSize);

        cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
        cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
        cmd->property = TRUSTEDBOOT::TPM_PT_FIRMWARE_VERSION_2;
        cmd->propertyCount = 1;


        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (NULL != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP2 Transmit Fail %X : ",
                       err->reasonCode() );
            break;

        }

        if ((sizeof(TRUSTEDBOOT::TPM2_GetCapabilityOut) > dataSize) ||
            (TRUSTEDBOOT::TPM_SUCCESS != resp->base.responseCode))
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP2 OP Fail %X Size(%d) ",
                       resp->base.responseCode,
                       dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP2_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
             * @userdata1      node
             * @userdata2[0:31] responseCode
             * @userdata2[32:63] dataSize
             * @devdesc        Command failure reading TPM FW version.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_CMD_GETCAPFWVERSION,
                                           RC_TPM_GETCAP2_FAIL,
                                           TARGETING::get_huid(
                                              io_target.nodeTarget),
                                           resp->base.responseCode,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            break;
        }
        else
        {
            // Walk the reponse data to pull the high order bytes out

            if (resp->capData.capability != TPM_CAP_TPM_PROPERTIES ||
                resp->capData.data.tpmProperties.count != 1 ||
                resp->capData.data.tpmProperties.tpmProperty[0].property !=
                TPM_PT_FIRMWARE_VERSION_2) {

                TRACFCOMP( g_trac_trustedboot,
                           "TPM GETCAP2 FW INVALID DATA "
                           "Cap(%X) Cnt(%X) Prop(%X)",
                           resp->capData.capability,
                           resp->capData.data.tpmProperties.count,
                           resp->capData.data.tpmProperties.
                             tpmProperty[0].property);

                /*@
                 * @errortype
                 * @reasoncode     RC_TPM_GETCAP2_FW_INVALID_RESP
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
                 * @userdata1      node
                 * @userdata2[0:31] capability
                 * @userdata2[32:63] propery
                 * @devdesc        Command failure reading TPM FW version.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_TPM_CMD_GETCAPFWVERSION,
                              RC_TPM_GETCAP2_FW_INVALID_RESP,
                              TARGETING::get_huid(
                                         io_target.nodeTarget),
                              ((uint64_t)resp->capData.capability << 32) |
                                resp->capData.data.tpmProperties.
                                tpmProperty[0].property,
                              true /*Add HB SW Callout*/ );

                err->collectTrace( SECURE_COMP_NAME );
                break;
            }
            else
            {
                fwVersion[2] =
                    (resp->capData.data.tpmProperties.
                     tpmProperty[0].value >> 16);
                fwVersion[3] =
                    (resp->capData.data.tpmProperties.
                     tpmProperty[0].value & 0xFFFF);
            }
            // Trace the response
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP FW Level %d.%d.%d.%d",
                       fwVersion[0],fwVersion[1],fwVersion[2],fwVersion[3]
                       );
        }


    } while ( 0 );


    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmCmdGetCapFwVersion() - %s",
               ((NULL == err) ? "No Error" : "With Error") );
    return err;
}




} // end TRUSTEDBOOT
