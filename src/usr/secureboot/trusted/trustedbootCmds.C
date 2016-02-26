/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootCmds.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <stdlib.h>
#ifdef __HOSTBOOT_MODULE
#include <secureboot/trustedboot_reasoncodes.H>
#else
#include "trustedboot_reasoncodes.H"
#endif
#include "trustedbootCmds.H"
#include "trustedbootUtils.H"
#include "trustedboot.H"
#include "trustedTypes.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

errlHndl_t tpmTransmitCommand(TpmTarget * io_target,
                              uint8_t* io_buffer,
                              size_t i_bufsize )
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t* transmitBuf = NULL;
    size_t cmdSize = 0;
    size_t dataSize = 0;
    TPM2_BaseIn* cmd = (TPM2_BaseIn*)io_buffer;
    TPM2_BaseOut* resp = (TPM2_BaseOut*)io_buffer;

    TRACUCOMP( g_trac_trustedboot,
               ">>TPM TRANSMIT CMD START : BufLen %d : %016llx",
               i_bufsize,
               *((uint64_t*)io_buffer)  );

    do
    {
        transmitBuf = (uint8_t*)malloc(MAX_TRANSMIT_SIZE);

        // Marshal the data into a byte array for transfer to the TPM
        err = tpmMarshalCommandData(cmd,
                                    transmitBuf,
                                    MAX_TRANSMIT_SIZE,
                                    &cmdSize);
        if (TB_SUCCESS != err)
        {
            break;
        }

        // Send to the TPM
        dataSize = MAX_TRANSMIT_SIZE;
        err = tpmTransmit(io_target,
                          transmitBuf,
                          cmdSize,
                          dataSize);

        if (TB_SUCCESS != err)
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


    free(transmitBuf);

    TRACUCOMP( g_trac_trustedboot,
               "<<tpmTransmitCommand() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;
}

errlHndl_t tpmMarshalCommandData(TPM2_BaseIn* i_cmd,
                                 uint8_t* o_outbuf,
                                 size_t i_bufsize,
                                 size_t* o_cmdSize)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t* sBuf = o_outbuf;
    int stage = 0;
    TPM2_BaseIn* baseCmd =
        (TPM2_BaseIn*)o_outbuf;
    *o_cmdSize = 0;

    TRACDCOMP( g_trac_trustedboot,
               ">>tpmMarshalCommandData()" );
    do
    {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM MARSHAL START : BufLen %d : %016llx",
                   i_bufsize,
                   *((uint64_t*)i_cmd)  );

        // Start with the command header
        sBuf = TPM2_BaseIn_marshal(i_cmd, sBuf, i_bufsize, o_cmdSize);
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
          case TPM_CC_Startup:
              {
                  TPM2_2ByteIn* cmdPtr =
                      (TPM2_2ByteIn*)i_cmd;
                  sBuf = TPM2_2ByteIn_marshal(cmdPtr, sBuf,
                                              i_bufsize, o_cmdSize);
              }
              break;

          case TPM_CC_GetCapability:
              {
                  TPM2_GetCapabilityIn* cmdPtr =
                      (TPM2_GetCapabilityIn*)i_cmd;
                  sBuf = TPM2_GetCapabilityIn_marshal(cmdPtr,sBuf,
                                                      i_bufsize, o_cmdSize);
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
                  err = tpmCreateErrorLog(MOD_TPM_MARSHALCMDDATA,
                                          RC_TPM_MARSHAL_INVALID_CMD,
                                          i_cmd->commandCode,
                                          0);
              }
              break;
        };

        if (TB_SUCCESS != err)
        {
            break;
        }


        // Lastly now that we know the size update the byte stream
        baseCmd->commandSize = *o_cmdSize;

    } while ( 0 );

    if (NULL == sBuf && TB_SUCCESS == err)
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
        err = tpmCreateErrorLog(MOD_TPM_MARSHALCMDDATA,
                                RC_TPM_MARSHALING_FAIL,
                                stage,
                                0 );

    }

    TRACUBIN(g_trac_trustedboot, "Marshal Out",
             o_outbuf, *o_cmdSize);

    TRACUCOMP( g_trac_trustedboot,
               "TPM MARSHAL END   : CmdSize: %d : %016llx ",  *o_cmdSize,
               *((uint64_t*)o_outbuf)  );

    TRACDCOMP( g_trac_trustedboot,
               "<<tpmMarshalCommandData()" );

    return err;
}

errlHndl_t tpmUnmarshalResponseData(uint32_t i_commandCode,
                                    uint8_t* i_respBuf,
                                    size_t i_respBufSize,
                                    TPM2_BaseOut* o_outBuf,
                                    size_t i_outBufSize)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t* sBuf = i_respBuf;
    int stage = 0;

    TRACDCOMP( g_trac_trustedboot,
               ">>tpmUnmarshalResponseData()" );

    do {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM UNMARSHAL START : RespBufLen %d : OutBufLen %d",
                   i_respBufSize, i_outBufSize);
        TRACUBIN(g_trac_trustedboot,"Unmarshal In",
                 i_respBuf, i_respBufSize);


        // Start with the response header
        stage = 1;
        sBuf = TPM2_BaseOut_unmarshal(o_outBuf, sBuf,
                                      &i_respBufSize, i_outBufSize);
        if (NULL == sBuf)
        {
            break;
        }

        // If the TPM returned a failure it will not send the rest
        // Let the caller deal with the RC
        if (TPM_SUCCESS != o_outBuf->responseCode)
        {
            break;
        }


        // Unmarshal the parameters
        stage = 2;
        switch (i_commandCode)
        {
            // Empty response commands
          case TPM_CC_Startup:
            // Nothing to do
            break;

          case TPM_CC_GetCapability:
              {
                  TPM2_GetCapabilityOut* respPtr =
                      (TPM2_GetCapabilityOut*)o_outBuf;
                  sBuf = TPM2_GetCapabilityOut_unmarshal(respPtr, sBuf,
                                                         &i_respBufSize,
                                                         i_outBufSize);

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
                  err = tpmCreateErrorLog(MOD_TPM_UNMARSHALRESPDATA,
                                          RC_TPM_UNMARSHAL_INVALID_CMD,
                                          i_commandCode,
                                          stage);
              }
              break;
        }


    } while ( 0 );

    if (NULL == sBuf && TB_SUCCESS == err)
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
        err = tpmCreateErrorLog(MOD_TPM_UNMARSHALRESPDATA,
                                RC_TPM_UNMARSHALING_FAIL,
                                stage,
                                i_respBufSize);



    }

    TRACUCOMP( g_trac_trustedboot,
               "TPM UNMARSHAL END   : %016llx ",
               *((uint64_t*)o_outBuf)  );

    TRACDCOMP( g_trac_trustedboot,
               "<<tpmUnmarshalResponseData()" );

    return err;
}

errlHndl_t tpmCmdStartup(TpmTarget* io_target)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t dataBuf[BUFSIZE];

    TPM2_BaseOut* resp =
        (TPM2_BaseOut*)(dataBuf);

    TPM2_2ByteIn* cmd =
        (TPM2_2ByteIn*)(dataBuf);

    TRACUCOMP( g_trac_trustedboot,
               ">>tpmCmdStartup()" );

    do
    {
        // Send the TPM startup command
        // Build our command block for a startup
        memset(dataBuf, 0, sizeof(dataBuf));


        cmd->base.tag = TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TPM_CC_Startup;
        cmd->param = TPM_SU_CLEAR;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP transmit Fail");
            break;

        }
        else if (TPM_SUCCESS != resp->responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP OP Fail %X : ",
                       resp->responseCode);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_START_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_STARTUP
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Invalid operation type.
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_STARTUP,
                                    RC_TPM_START_FAIL,
                                    resp->responseCode,
                                    0);

            break;
        }


    } while ( 0 );


    TRACUCOMP( g_trac_trustedboot,
               "<<tpmCmdStartup() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;
}

errlHndl_t tpmCmdGetCapFwVersion(TpmTarget* io_target)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t dataBuf[BUFSIZE];
    size_t dataSize = BUFSIZE;
    uint16_t fwVersion[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    TPM2_GetCapabilityOut* resp =
        (TPM2_GetCapabilityOut*)dataBuf;
    TPM2_GetCapabilityIn* cmd =
        (TPM2_GetCapabilityIn*)dataBuf;


    TRACUCOMP( g_trac_trustedboot,
               ">>tpmCmdGetCapFwVersion()" );

    do
    {

        // Build our command block for a get capability of the FW version
        memset(dataBuf, 0, dataSize);

        cmd->base.tag = TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TPM_CC_GetCapability;
        cmd->capability = TPM_CAP_TPM_PROPERTIES;
        cmd->property = TPM_PT_FIRMWARE_VERSION_1;
        cmd->propertyCount = 1;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP Transmit Fail");
            break;

        }

        if (TPM_SUCCESS != resp->base.responseCode)
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
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Command failure reading TPM FW version.
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPFWVERSION,
                                    RC_TPM_GETCAP_FAIL,
                                    resp->base.responseCode,
                                    0);

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
                 * @userdata1      capability
                 * @userdata2      property
                 * @devdesc        Command failure reading TPM FW version.
                 */
                err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPFWVERSION,
                                        RC_TPM_GETCAP_FW_INVALID_RESP,
                                        resp->capData.capability,
                                        resp->capData.data.tpmProperties.
                                        tpmProperty[0].property);

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

        cmd->base.tag = TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TPM_CC_GetCapability;
        cmd->capability = TPM_CAP_TPM_PROPERTIES;
        cmd->property = TPM_PT_FIRMWARE_VERSION_2;
        cmd->propertyCount = 1;


        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf));

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP2 Transmit Fail %X");
            break;

        }

        if ((sizeof(TPM2_GetCapabilityOut) > dataSize) ||
            (TPM_SUCCESS != resp->base.responseCode))
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
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Command failure reading TPM FW version.
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPFWVERSION,
                                    RC_TPM_GETCAP2_FAIL,
                                    resp->base.responseCode,
                                    0);

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
                 * @userdata1      capability
                 * @userdata2      property
                 * @devdesc        Command failure reading TPM FW version.
                 */
                err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPFWVERSION,
                                        RC_TPM_GETCAP2_FW_INVALID_RESP,
                                        resp->capData.capability,
                                        resp->capData.data.tpmProperties.
                                        tpmProperty[0].property);
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
               "<<tpmCmdGetCapFwVersion() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;
}




#ifdef __cplusplus
} // end TRUSTEDBOOT
#endif
