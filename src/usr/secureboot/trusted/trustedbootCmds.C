/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootCmds.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <secureboot/trustedbootif.H>
#include "tpmLogMgr.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

errlHndl_t tpmTransmitCommand(TpmTarget * io_target,
                              uint8_t* io_buffer,
                              size_t i_bufsize,
                              tpm_locality_t i_locality)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t* transmitBuf = NULL;
    size_t cmdSize = 0;
    size_t dataSize = 0;
    TPM2_BaseIn* cmd = (TPM2_BaseIn*)io_buffer;
    TPM2_BaseOut* resp = (TPM2_BaseOut*)io_buffer;

    TRACUCOMP( g_trac_trustedboot,
               ">>TPM TRANSMIT CMD START : BufLen %d : %016llx",
               (int)i_bufsize,
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
                          dataSize,
                          i_locality);

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
    uint32_t* sSizePtr = NULL;
    size_t curSize = 0;
    int stage = 0;
    TPM2_BaseIn* baseCmd =
        (TPM2_BaseIn*)o_outbuf;
    TPMS_AUTH_COMMAND cmdAuth;

    *o_cmdSize = 0;

    TRACDCOMP( g_trac_trustedboot,
               ">>tpmMarshalCommandData()" );
    do
    {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM MARSHAL START : BufLen %d : %016llx",
                   (int)i_bufsize,
                   *((uint64_t*)i_cmd)  );

        // Start with the command header
        sBuf = TPM2_BaseIn_marshal(i_cmd, sBuf, i_bufsize, o_cmdSize);
        if (NULL == sBuf)
        {
            break;
        }

        // Marshal the handles
        stage = 1;
        if (TPM_CC_PCR_Extend == i_cmd->commandCode)
        {
            TPM2_ExtendIn* cmdPtr = (TPM2_ExtendIn*)i_cmd;
            sBuf = TPM2_ExtendIn_marshalHandle(cmdPtr,
                                               sBuf,
                                               i_bufsize,
                                               o_cmdSize);
            if (NULL == sBuf)
            {
                break;
            }
        }

        // Marshal the authorizations
        stage = 2;
        if (TPM_CC_PCR_Extend == i_cmd->commandCode)
        {
            // Insert a password authorization with a null pw
            // Make room for the 4 byte size field at the beginning
            sSizePtr = (uint32_t*)sBuf;
            sBuf += sizeof(uint32_t);
            *o_cmdSize += sizeof(uint32_t);
            i_bufsize -= sizeof(uint32_t);
            curSize = *o_cmdSize;

            cmdAuth.sessionHandle = TPM_RS_PW;
            cmdAuth.nonceSize = 0;
            cmdAuth.sessionAttributes = 0;
            cmdAuth.hmacSize = 0;

            sBuf = TPMS_AUTH_COMMAND_marshal(&cmdAuth, sBuf, i_bufsize,
                                             o_cmdSize);

            if (NULL == sBuf)
            {
                break;
            }
            // Put in the size of the auth area
            *sSizePtr = (*o_cmdSize - curSize);

        }

        // Marshal the command parameters
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
          case TPM_CC_PCR_Read:
              {
                  TPM2_PcrReadIn* cmdPtr = (TPM2_PcrReadIn*)i_cmd;
                  sBuf = TPM2_PcrReadIn_marshal(cmdPtr, sBuf,
                                                i_bufsize - (sBuf - o_outbuf),
                                                o_cmdSize);
              }
              break;

          case TPM_CC_PCR_Extend:
              {
                  TPM2_ExtendIn* cmdPtr = (TPM2_ExtendIn*)i_cmd;
                  sBuf = TPM2_ExtendIn_marshalParms(cmdPtr, sBuf,
                                                    i_bufsize, o_cmdSize);
              }
              break;

          case TPM_CC_GetRandom:
              {
                  auto cmdPtr = reinterpret_cast<TPM2_2ByteIn*>(i_cmd);
                  sBuf = TPM2_2ByteIn_marshal(cmdPtr, sBuf,
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
                   * @custdesc       Failure detected in security subsystem
                   */
                  err = tpmCreateErrorLog(MOD_TPM_MARSHALCMDDATA,
                                          RC_TPM_MARSHAL_INVALID_CMD,
                                          i_cmd->commandCode,
                                          0);
              }
              break;
        };

        if (TB_SUCCESS != err || NULL == sBuf)
        {
            break;
        }

        // Do a verification that the cmdSize equals what we used
        if (((size_t)(sBuf - o_outbuf)) != *o_cmdSize)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM MARSHAL MARSHAL SIZE MISMATCH : %d %d",
                       (int)(sBuf - o_outbuf), (int)(*o_cmdSize) );
            sBuf = NULL;
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
         * @custdesc       Failure detected in security subsystem
         */
        err = tpmCreateErrorLog(MOD_TPM_MARSHALCMDDATA,
                                RC_TPM_MARSHALING_FAIL,
                                stage,
                                0 );

    }

    TRACUBIN(g_trac_trustedboot, "Marshal Out",
             o_outbuf, *o_cmdSize);

    TRACUCOMP( g_trac_trustedboot,
               "TPM MARSHAL END   : CmdSize: %d : %016llx ",
               (int)(*o_cmdSize),
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
    const uint8_t* sBuf = i_respBuf;
    int stage = 0;

    TRACDCOMP( g_trac_trustedboot,
               ">>tpmUnmarshalResponseData()" );

    do {

        TRACUCOMP( g_trac_trustedboot,
                   "TPM UNMARSHAL START : RespBufLen %d : OutBufLen %d",
                   (int)i_respBufSize, (int)i_outBufSize);
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
          case TPM_CC_CreatePrimary:
          case TPM_CC_FlushContext:
          case TPM_CC_Startup:
          case TPM_CC_PCR_Extend:
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

          case TPM_CC_PCR_Read:
              {
                  TPM2_PcrReadOut* respPtr = (TPM2_PcrReadOut*)o_outBuf;
                  sBuf = TPM2_PcrReadOut_unmarshal(respPtr, sBuf,
                                                   &i_respBufSize,
                                                   i_outBufSize);
              }
              break;

          case TPM_CC_GetRandom:
              {
                  auto respPtr = reinterpret_cast<TPM2_GetRandomOut*>(o_outBuf);
                  sBuf = TPM2B_DIGEST_unmarshal(&respPtr->randomBytes, sBuf,
                                                &i_respBufSize);
              }
              break;

          case TPM_CC_NV_Read:
              {
                  // Read out the TPM NV Data
                  TPM2_NVReadOut* l_respPtr =
                                    reinterpret_cast<TPM2_NVReadOut*>(o_outBuf);
                  TPM2_NVReadOut* l_tpmRespData =
                                   reinterpret_cast<TPM2_NVReadOut*>(i_respBuf);
                  l_respPtr->authSessionSize = l_tpmRespData->authSessionSize;
                  memcpy(reinterpret_cast<uint8_t*>(&l_tpmRespData->data),
                         reinterpret_cast<uint8_t*>(&l_respPtr->data),
                         sizeof(l_tpmRespData->data));
              }
              break;

          case TPM_CC_Quote:
              {
                  // Pass back the quote data
                  TPM2_QuoteOut* l_respPtr =
                                reinterpret_cast<TPM2_QuoteOut*>(o_outBuf);
                  TPM2_QuoteOut* l_tpmRespData =
                                reinterpret_cast<TPM2_QuoteOut*>(i_respBuf);
                  l_respPtr->authSessionSize = l_tpmRespData->authSessionSize;
                  memcpy(l_respPtr->quoteData,
                         l_tpmRespData->quoteData,
                         sizeof(l_tpmRespData->base.responseSize));
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
                   * @custdesc       Failure detected in security subsystem
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
         * @custdesc       Failure detected in security subsystem
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

#ifdef __HOSTBOOT_MODULE
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
                                 sizeof(dataBuf),
                                 TPM_LOCALITY_0);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP transmit Fail");
            break;

        }
        else if (TPM_SUCCESS == resp->responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                ERR_MRK"TPM STARTUP - TPM not initialized by SBE" );
            /*@
             * @errortype
             * @reasoncode      RC_TPM_START_SBE_SETUP_FAILED
             * @severity        ERRL_SEV_UNRECOVERABLE
             * @moduleid        MOD_TPM_CMD_STARTUP
             * @userdata1       responseCode
             * @userdata2       TPM HUID
             * @devdesc         SBE failed to setup the TPM
             * @custdesc        Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_STARTUP,
                                    RC_TPM_START_SBE_SETUP_FAILED,
                                    resp->responseCode,
                                    TARGETING::get_huid(io_target),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }
        else if (TPM_RC_INITIALIZE == resp->responseCode)
        {
            // SBE should initalize the TPM so this is normal path
            TRACFCOMP( g_trac_trustedboot,
                      "TPM STARTUP - TPM already initialized" );
        }
        else
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP OP Fail Ret(0x%X) : ",
                       resp->responseCode);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_START_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_STARTUP
             * @userdata1      responseCode
             * @userdata2      TPM HUID
             * @devdesc        TPM_Startup operation failure.
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_STARTUP,
                                    RC_TPM_START_FAIL,
                                    resp->responseCode,
                                    TARGETING::get_huid(io_target),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
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
                                 sizeof(dataBuf),
                                 TPM_LOCALITY_0);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP Transmit Fail");
            break;

        }

        if (TPM_SUCCESS != resp->base.responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP OP Fail Ret(0x%X) Size(%d) ",
                       resp->base.responseCode,
                       (int)dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Command failure reading TPM FW version.
             * @custdesc       Failure detected in security subsystem
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
                 * @custdesc       Failure detected in security subsystem
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
                                 sizeof(dataBuf),
                                 TPM_LOCALITY_0);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP2 Transmit Fail");
            break;

        }

        if ((sizeof(TPM2_GetCapabilityOut) > dataSize) ||
            (TPM_SUCCESS != resp->base.responseCode))
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP2 OP Fail Ret(0x%X) Size(%d) ",
                       resp->base.responseCode,
                       (int)dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP2_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPFWVERSION
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Command failure reading TPM FW version.
             * @custdesc       Failure detected in security subsystem
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
                 * @custdesc       Failure detected in security subsystem
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

errlHndl_t tpmCmdGetCapNvIndexValidate(TpmTarget* io_target)
{
    errlHndl_t err = TB_SUCCESS;
    uint8_t dataBuf[BUFSIZE];
    size_t dataSize = BUFSIZE;
    TPM2_GetCapabilityOut* resp =
        (TPM2_GetCapabilityOut*)dataBuf;
    TPM2_GetCapabilityIn* cmd =
        (TPM2_GetCapabilityIn*)dataBuf;
    bool foundRSAEKCert = false;
    bool foundECCP256EKCert = false;
    bool foundECCP384EKCert = false;
    bool foundPlatCert0 = false;
    bool foundPlatCert1 = false;
    bool foundPlatCert2 = false;
    bool moreData = false;

    TRACUCOMP( g_trac_trustedboot,
               ">>tpmCmdGetCapNvIndexValidate()" );

    do
    {

        // Build our command block for a get capability of the FW version
        memset(dataBuf, 0, dataSize);

        cmd->base.tag = TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TPM_CC_GetCapability;
        cmd->capability = TPM_CAP_HANDLES;
        cmd->property = TPM_HT_NV_INDEX;
        cmd->propertyCount = MAX_TPML_HANDLES;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf),
                                 TPM_LOCALITY_0);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP Transmit Fail");
            break;

        }

        if (TPM_SUCCESS != resp->base.responseCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP OP Fail Ret(0x%X) Size(%d) ",
                       resp->base.responseCode,
                       (int)dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPNVINDEX
             * @userdata1      responseCode
             * @userdata2      0
             * @devdesc        Command failure reading TPM capability.
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPNVINDEX,
                                    RC_TPM_GETCAP_FAIL,
                                    resp->base.responseCode,
                                    0);

            break;
        }

        // Walk the reponse data to pull the high order bytes out

        if (resp->capData.capability != TPM_CAP_HANDLES) {

            TRACFCOMP( g_trac_trustedboot,
                       "TPM GETCAP NVINDEX INVALID DATA "
                       "Cap(0x%X) Cnt(0x%X) ",
                       resp->capData.capability,
                       resp->capData.data.tpmHandles.count);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_GETCAP_FW_INVALID_RESP
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_GETCAPNVINDEX
             * @userdata1      capability
             * @userdata2      0
             * @devdesc        Command failure reading TPM NV indexes.
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_GETCAPNVINDEX,
                                    RC_TPM_GETCAP_FW_INVALID_RESP,
                                    resp->capData.capability, 0);

            break;
        }

        for (size_t idx = 0; idx < resp->capData.data.tpmHandles.count;
             ++idx)
        {
            // Check for specific handles we expect to be setup
            // by manufacturing provisioning
            switch (resp->capData.data.tpmHandles.handles[idx])
            {
              case NVIDX_RSAEKCERT:
                foundRSAEKCert = true;
                break;
              case NVIDX_ECC_P256_EKCERT:
                foundECCP256EKCert = true;
                break;
              case NVIDX_ECC_P384_EKCERT:
                foundECCP384EKCert = true;
                break;
              case NVIDX_IBMPLATCERT0:
                foundPlatCert0 = true;
                break;
              case NVIDX_IBMPLATCERT1:
                foundPlatCert1 = true;
                break;
              case NVIDX_IBMPLATCERT2:
                foundPlatCert2 = true;
                break;
                // Ignore any other handles
            }
        }
        // More Data implies the TPM could have returned more then
        //  we asked for
        moreData = resp->moreData;

    } while ( 0 );

    // Validate we found all we needed.  Note that TPMs can be provisioned with
    // different ECC EK certificates (P256 or P384) and at least one of them is
    // required.
    if ((NULL == err) &&
        (   (foundRSAEKCert == false)
         || (   (foundECCP256EKCert == false)
             && (foundECCP384EKCert == false))
         || (foundPlatCert0 == false)
         || (foundPlatCert1 == false)
         // @TODO CQ:SW542165: Reenable IBM platform certificate 2 enforcement
         // || (foundPlatCert2 == false)
         || moreData == true))
    {
        TRACFCOMP( g_trac_trustedboot,
                   "TPM GETCAP NVINDEX MISSING INDEX "
                   "RSAEK(%d) ECCP256EK(%d) ECCP384EK(%d) PLAT0(%d) PLAT1(%d) "
                   "PLAT2(%d) MD(%d)",
                   foundRSAEKCert, foundECCP256EKCert, foundECCP384EKCert,
                   foundPlatCert0, foundPlatCert1, foundPlatCert2,
                   moreData);

        /*@
         * @errortype
         * @reasoncode       RC_TPM_NVINDEX_VALIDATE_FAIL
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_TPM_CMD_GETCAPNVINDEX
         * @userdata1[0:7]   foundRSAEKCert
         * @userdata1[8:15]  ECC EK cert found mask (0x80/0x40 = P256/P384)
         * @userdata1[16:23] Plat cert found mask (0x80/0x40/0x20 = cert 0/1/2)
         * @userdata1[24:31] moreData
         * @userdata1[32:63] 0
         * @devdesc          Command failure reading TPM NV indexes.
         *                   TPM is likely provisioned incorrectly.
         * @custdesc         Failure detected in security subsystem.
         */
        err = tpmCreateErrorLog(
            MOD_TPM_CMD_GETCAPNVINDEX,
            RC_TPM_NVINDEX_VALIDATE_FAIL,
            TWO_UINT32_TO_UINT64(
                FOUR_UINT8_TO_UINT32(
                    foundRSAEKCert,
                    ((foundECCP256EKCert << 7) | (foundECCP384EKCert << 6)),
                    ((foundPlatCert0 << 7) | (foundPlatCert1 << 6) | (foundPlatCert2 << 5)),
                    moreData),
                0),
            0,
            ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

        // Likely a TPM provisioning issue
        err->addHwCallout(io_target,
                          HWAS::SRCI_PRIORITY_HIGH,
                          HWAS::NO_DECONFIG,
                          HWAS::GARD_NULL);

        // Small chance HB code failed to check the provisoning
        // correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);
    }

    TRACDCOMP( g_trac_trustedboot,
               "<<tpmCmdGetCapNvIndexValidate() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;
}
#endif // HOSTBOOT

errlHndl_t tpmCmdPcrExtend(TpmTarget * io_target,
                           TPM_Pcr i_pcr,
                           TPM_Alg_Id i_algId,
                           const uint8_t* i_digest,
                           size_t  i_digestSize)
{
    return tpmCmdPcrExtend2Hash(io_target, i_pcr,
                                i_algId, i_digest, i_digestSize,
                                TPM_ALG_INVALID_ID, NULL, 0);
}

errlHndl_t tpmCmdPcrExtend2Hash(TpmTarget * io_target,
                                TPM_Pcr i_pcr,
                                TPM_Alg_Id i_algId_1,
                                const uint8_t* i_digest_1,
                                size_t  i_digestSize_1,
                                TPM_Alg_Id i_algId_2,
                                const uint8_t* i_digest_2,
                                size_t  i_digestSize_2)
{
    errlHndl_t err = NULL;
    uint8_t dataBuf[sizeof(TPM2_ExtendIn)];
    size_t dataSize = sizeof(dataBuf);
    size_t fullDigestSize_1 = 0;
    size_t fullDigestSize_2 = 0;
    TPM2_BaseOut* resp = (TPM2_BaseOut*)dataBuf;
    TPM2_ExtendIn* cmd = (TPM2_ExtendIn*)dataBuf;


    TRACDCOMP( g_trac_trustedboot,
               ">>tpmCmdPcrExtend2Hash()" );
    if (NULL == i_digest_2)
    {
        TRACUCOMP( g_trac_trustedboot,
                   ">>tpmCmdPcrExtend2Hash() Pcr(%d) Alg(%X) DS(%d)",
                   i_pcr, i_algId_1, (int)i_digestSize_1);
    }
    else
    {
        TRACUCOMP( g_trac_trustedboot,
                   ">>tpmCmdPcrExtend2Hash() Pcr(%d) Alg(%X:%X) DS(%d:%d)",
                   i_pcr, i_algId_1, i_algId_2,
                   (int)i_digestSize_1, (int)i_digestSize_2);
    }

    do
    {

        fullDigestSize_1 = getDigestSize(i_algId_1);
        if (NULL != i_digest_2)
        {
            fullDigestSize_2 = getDigestSize(i_algId_2);
        }

        // Build our command block
        memset(dataBuf, 0, sizeof(dataBuf));

        // Argument verification
        if (fullDigestSize_1 == 0 ||
            NULL == i_digest_1 ||
            IMPLEMENTATION_PCR < i_pcr ||
            (NULL != i_digest_2 && fullDigestSize_2 == 0)
            )
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCR EXTEND ARG FAILURE FDS(%d:%d) DS(%d:%d) "
                       "PCR(%d)",
                       (int)fullDigestSize_1, (int)fullDigestSize_2,
                       (int)i_digestSize_1, (int)i_digestSize_2, i_pcr);
            /*@
             * @errortype
             * @reasoncode     RC_TPM_INVALID_ARGS
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_PCREXTEND
             * @userdata1      Digest Ptr
             * @userdata2[0:15] Full Digest Size 1
             * @userdata2[16:31] Full Digest Size 2
             * @userdata2[32:63] PCR
             * @devdesc        PCR Extend invalid arguments detected
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_PCREXTEND,
                                    RC_TPM_INVALID_ARGS,
                                    (uint64_t)i_digest_1,
                                    (fullDigestSize_1 << 48) |
                                    (fullDigestSize_2 << 32) |
                                    i_pcr);
            break;
        }

        // Log the input PCR value
        TRACUBIN(g_trac_trustedboot, "PCR In",
                 i_digest_1, fullDigestSize_1);

        cmd->base.tag = TPM_ST_SESSIONS;
        cmd->base.commandCode = TPM_CC_PCR_Extend;
        cmd->pcrHandle = i_pcr;
        cmd->digests.count = 1;
        cmd->digests.digests[0].algorithmId = i_algId_1;
        memcpy(&(cmd->digests.digests[0].digest), i_digest_1,
               (i_digestSize_1 < fullDigestSize_1 ?
                i_digestSize_1 : fullDigestSize_1) );

// If only 1 hash algorithm is supported, this branch is not able to compile
#if HASH_COUNT > 1
        if (NULL != i_digest_2)
        {
            cmd->digests.count = 2;
            cmd->digests.digests[1].algorithmId = i_algId_2;
            memcpy(&(cmd->digests.digests[1].digest), i_digest_2,
                   (i_digestSize_2 < fullDigestSize_2 ?
                    i_digestSize_2 : fullDigestSize_2));
        }
#endif

        tpm_locality_t tpmLocality = TPM_LOCALITY_0;

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf),
                                 tpmLocality);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCRExtend Transmit Fail");
            break;

        }
        else if ((sizeof(TPM2_BaseOut) > dataSize)
                 || (TPM_SUCCESS != resp->responseCode))
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCRExtend OP Fail Ret(0x%X) ExSize(%d) Size(%d) ",
                       resp->responseCode,
                       (int)sizeof(TPM2_BaseOut),
                       (int)dataSize);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_COMMAND_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_PCREXTEND
             * @userdata1      responseCode
             * @userdata2      dataSize
             * @devdesc        Command failure performing PCR extend.
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_PCREXTEND,
                                    RC_TPM_COMMAND_FAIL,
                                    resp->responseCode,
                                    dataSize);
            break;

        }

    } while ( 0 );


    TRACUCOMP( g_trac_trustedboot,
               "<<tpmCmdPcrExtend() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;

}

errlHndl_t tpmCmdPcrRead(TpmTarget* io_target,
                         TPM_Pcr i_pcr,
                         TPM_Alg_Id i_algId,
                         uint8_t* o_digest,
                         size_t  i_digestSize)
{
    errlHndl_t err = NULL;
    uint8_t dataBuf[sizeof(TPM2_PcrReadOut)];
    size_t dataSize = sizeof(dataBuf);
    size_t fullDigestSize = 0;
    TPM2_PcrReadOut* resp = (TPM2_PcrReadOut*)dataBuf;
    TPM2_PcrReadIn* cmd = (TPM2_PcrReadIn*)dataBuf;


    TRACDCOMP( g_trac_trustedboot,
               ">>tpmCmdPcrRead()" );
    TRACUCOMP( g_trac_trustedboot,
               ">>tpmCmdPcrRead() Pcr(%d) DS(%d)",
               i_pcr, (int)i_digestSize);

    do
    {

        fullDigestSize = getDigestSize(i_algId);

        // Build our command block
        memset(dataBuf, 0, sizeof(dataBuf));

        // Argument verification
        if (fullDigestSize > i_digestSize ||
            NULL == o_digest ||
            IMPLEMENTATION_PCR < i_pcr
            )
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCR READ ARG FAILURE FDS(%d) DS(%d) PCR(%d)",
                       (int)fullDigestSize, (int)i_digestSize, i_pcr);
            /*@
             * @errortype
             * @reasoncode     RC_TPM_INVALID_ARGS
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_PCRREAD
             * @userdata1      Digest Ptr
             * @userdata2[0:31] Full Digest Size
             * @userdata2[32:63] PCR
             * @devdesc        pcr read invalid arguments
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_PCRREAD,
                                    RC_TPM_INVALID_ARGS,
                                    (uint64_t)o_digest,
                                    (fullDigestSize << 32) |
                                    i_pcr);

            break;
        }

        cmd->base.tag = TPM_ST_NO_SESSIONS;
        cmd->base.commandCode = TPM_CC_PCR_Read;
        cmd->pcrSelectionIn.count = 1; // One algorithm
        cmd->pcrSelectionIn.pcrSelections[0].algorithmId = i_algId;
        cmd->pcrSelectionIn.pcrSelections[0].sizeOfSelect = PCR_SELECT_MAX;
        memset(cmd->pcrSelectionIn.pcrSelections[0].pcrSelect, 0,
               sizeof(cmd->pcrSelectionIn.pcrSelections[0].pcrSelect));
        cmd->pcrSelectionIn.pcrSelections[0].pcrSelect[i_pcr / 8] =
            0x01 << (i_pcr % 8);

        err = tpmTransmitCommand(io_target,
                                 dataBuf,
                                 sizeof(dataBuf),
                                 TPM_LOCALITY_0);

        if (TB_SUCCESS != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCRRead Transmit Fail ");
            break;

        }
        else if ((sizeof(TPM2_BaseOut) > dataSize) ||
                 (TPM_SUCCESS != resp->base.responseCode) ||
                 (resp->pcrValues.count != 1) ||
                 (resp->pcrValues.digests[0].size != fullDigestSize))
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM PCRRead OP Fail Ret(0x%X) ExSize(%d) "
                       "Size(%d) Cnt(%d) DSize(%d)",
                       resp->base.responseCode,
                       (int)sizeof(TPM2_BaseOut),
                       (int)dataSize,
                       resp->pcrValues.count,
                       resp->pcrValues.digests[0].size);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_COMMAND_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_CMD_PCRREAD
             * @userdata1      responseCode
             * @userdata2      dataSize
             * @devdesc        Command failure performing PCR read.
             * @custdesc       Failure detected in security subsystem
             */
            err = tpmCreateErrorLog(MOD_TPM_CMD_PCRREAD,
                                    RC_TPM_COMMAND_FAIL,
                                    resp->base.responseCode,
                                    dataSize);
            break;
        }
        else
        {

            memcpy(o_digest, resp->pcrValues.digests[0].buffer, fullDigestSize);

            // Log the PCR value
            TRACUBIN(g_trac_trustedboot, "PCR Out",
                     o_digest, fullDigestSize);

        }

    } while ( 0 );


    TRACUCOMP( g_trac_trustedboot,
               "<<tpmCmdPcrRead() - %s",
               ((TB_SUCCESS == err) ? "No Error" : "With Error") );
    return err;

}

errlHndl_t tpmCmdCreateAttestationKeys(TpmTarget* i_target)
{
    TRACFCOMP(g_trac_trustedboot,
              ENTER_MRK"tpmCmdCreateAttestationKeys()");
    errlHndl_t l_errl = nullptr;

    uint8_t l_dataBuf[BUFSIZE] = {};
    TPM2_CreatePrimaryIn* l_cmd =
                             reinterpret_cast<TPM2_CreatePrimaryIn*>(l_dataBuf);
    TPM2_BaseOut* l_resp = reinterpret_cast<TPM2_BaseOut*>(l_dataBuf);

    do {
    uint64_t l_cmdData[] = { 0x0000000000000400,
                             0x0000000018002300,
                             0x0B00050472000000,
                             0x100018000B000300,
                             0x1000000000000000,
                             0 };
    l_cmd->base.tag = TPM_ST_SESSIONS;
    l_cmd->base.commandSize = TPM_CREATE_PRIMARY_SIZE;
    l_cmd->base.commandCode = TPM_CC_CreatePrimary;
    l_cmd->primaryHandle = TPM_RH_PLATFORM;
    l_cmd->inSensitive.size = TPM_IN_SENSITIVE_SIZE;
    l_cmd->inSensitive.sensitive.userAuth = TPM_RS_PW;

    memcpy(l_cmd->inSensitive.sensitive.data, l_cmdData, sizeof(l_cmdData));

    size_t l_dataSize = MAX_TRANSMIT_SIZE;

    l_errl = tpmTransmit(i_target,
                         l_dataBuf,
                         l_cmd->base.commandSize,
                         l_dataSize,
                         TPM_LOCALITY_0);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdCreateAttestationKeys: could not transmit TPM command");
        break;
    }

    l_errl = tpmUnmarshalResponseData(TPM_CC_CreatePrimary,
                                      l_dataBuf,
                                      l_dataSize,
                                      l_resp,
                                      l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdCreateAttestationKeys: could not unmarshal response data");
        break;
    }

    // Check response return code
    if(TPM_SUCCESS != l_resp->responseCode)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdCreateAttestationKeys: TPM (HUID 0x%x) returned a nonzero return code. Expected RC 0x%x, actual RC 0x%x", TARGETING::get_huid(i_target), TPM_SUCCESS, l_resp->responseCode);
        /*@
         * @errortype         ERRL_SEV_UNRECOVERABLE
         * @reasoncode        RC_TPM_BAD_RESP
         * @moduleid          MOD_TPM_CMD_CREATE_ATTEST
         * @userdata1         TPM HUID
         * @userdata2[0..31]  Expected response RC
         * @userdata2[32..63] Actual response RC
         * @devdesc           Incorrect response from TPM_CC_CreatePrimary
         *                    command (see logs for TPM HUID)
         * @custdesc          Trusted boot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_CREATE_ATTEST,
                                   RC_TPM_BAD_RESP,
                                   TARGETING::get_huid(i_target),
                                   TWO_UINT32_TO_UINT64(
                                        TPM_SUCCESS,
                                        l_resp->responseCode));
        break;
    }

    } while(0);

    TRACFCOMP(g_trac_trustedboot,
              EXIT_MRK"tpmCmdCreateAttestationKeys()");
    return l_errl;
}

errlHndl_t tpmCmdReadAKCertificate(TpmTarget* i_target, TPM2B_MAX_NV_BUFFER* o_data)
{
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"tpmCmdReadAKCertificate()");
    errlHndl_t l_errl = nullptr;

    size_t l_dataSize = MAX_TRANSMIT_SIZE;

    uint8_t l_dataBuf[l_dataSize] = {};
    TPM2_NVReadIn* l_cmd = reinterpret_cast<TPM2_NVReadIn*>(l_dataBuf);
    TPM2_BaseOut* l_resp = reinterpret_cast<TPM2_BaseOut*>(l_dataBuf);

    do {
    uint64_t l_cmdData[] = { 0x01C1018101C10181,
                             0x0000000940000009,
                             0x000000000001F400,
                             0, };
    l_cmd->base.tag = TPM_ST_SESSIONS;
    l_cmd->base.commandSize = TPM_NV_READ_SIZE;
    l_cmd->base.commandCode = TPM_CC_NV_Read;

    memcpy(l_cmd->data, l_cmdData, sizeof(l_cmdData));

    l_errl = tpmTransmit(i_target,
                         l_dataBuf,
                         l_cmd->base.commandSize,
                         l_dataSize,
                         TPM_LOCALITY_0);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmUnmarshalResponseData(TPM_CC_NV_Read,
                                      l_dataBuf,
                                      l_dataSize,
                                      l_resp,
                                      l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdReadAKCertificate: could not unmarshal response data");
        break;
    }

    // Look for Specific TPM_RC_HANDLE return code as it indicates that the
    // NV index isn't valied.  This means that the TPM is unprovisioned.
    if (TPM_RC_HANDLE == l_resp->responseCode )
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdReadAKCertificate: TPM (HUID 0x%x) returned TPM_RC_HANDLE (0x%x), indicating an unprovisioned TPM.", TARGETING::get_huid(i_target), l_resp->responseCode);
        /*@
         * @errortype         ERRL_SEV_UNRECOVERABLE
         * @reasoncode        RC_AK_CERT_NOT_AVAIL
         * @moduleid          MOD_TPM_CMD_READ_AK_CERT
         * @userdata1         TPM HUID
         * @userdata2[0..31]  TPM_RC_HANDLE response RC
         * @userdata2[32..63] Actual response RC
         * @devdesc           TPM_RC_HANDLE response from TPM_CC_NV_Read
         *                    indicates unprovisioned TPM (see logs for TPM HUID)
         * @custdesc          Trusted boot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_READ_AK_CERT,
                                   RC_AK_CERT_NOT_AVAIL,
                                   TARGETING::get_huid(i_target),
                                   TWO_UINT32_TO_UINT64(
                                        TPM_RC_HANDLE,
                                        l_resp->responseCode),
                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

        // If TPM is Required, guard and deconfigure this part out as the user will not be able
        // to recover from this on their own
        if(TRUSTEDBOOT::isTpmRequired())
        {
            l_errl->addHwCallout(i_target,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DECONFIG,
                                 HWAS::GARD_Fatal);
        }

        break;
    }
    else if(TPM_SUCCESS != l_resp->responseCode)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdReadAKCertificate: TPM (HUID 0x%x) returned a nonzero return code. Expected RC 0x%x, actual RC 0x%x", TARGETING::get_huid(i_target), TPM_SUCCESS, l_resp->responseCode);
        /*@
         * @errortype         ERRL_SEV_UNRECOVERABLE
         * @reasoncode        RC_TPM_BAD_RESP
         * @moduleid          MOD_TPM_CMD_READ_AK_CERT
         * @userdata1         TPM HUID
         * @userdata2[0..31]  Expected response RC
         * @userdata2[32..63] Actual response RC
         * @devdesc           Incorrect response from TPM_CC_NV_Read
         *                    command (see logs for TPM HUID)
         * @custdesc          Trusted boot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_READ_AK_CERT,
                                   RC_TPM_BAD_RESP,
                                   TARGETING::get_huid(i_target),
                                   TWO_UINT32_TO_UINT64(
                                        TPM_SUCCESS,
                                        l_resp->responseCode));
        break;
    }

    TPM2_NVReadOut* l_read = reinterpret_cast<TPM2_NVReadOut*>(l_resp);
    // NVRAM holds the AK certificate. Copy out the size and the certificate
    memcpy(reinterpret_cast<uint8_t*>(o_data),
           reinterpret_cast<uint8_t*>(&l_read->data),
           sizeof(*o_data));

    }while(0);

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK"tpmCmdReadAKCertificate()");
    return l_errl;
}

errlHndl_t tpmCmdGenerateQuote(TpmTarget* i_target,
                               const TpmNonce_t* const i_nonce,
                               QuoteDataOut* o_data)
{
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"tpmCmdGenerateQuote()");
    errlHndl_t l_errl = nullptr;

    size_t l_dataSize = MAX_TRANSMIT_SIZE;
    uint8_t l_dataBuf[l_dataSize] = {};
    TPM2_QuoteIn* l_cmd = reinterpret_cast<TPM2_QuoteIn*>(l_dataBuf);
    TPM2_BaseOut* l_resp = reinterpret_cast<TPM2_BaseOut*>(l_dataBuf);

    do {
    uint64_t l_tpmiDhObject[] = { 0x8000000000000009,
                                  0x4000000900000000,
                                  0x0000200000000000 };
    uint16_t l_data = 0x0018;

    l_cmd->base.tag = TPM_ST_SESSIONS;
    l_cmd->base.commandSize = TPM_QUOTE_SIZE;
    l_cmd->base.commandCode = TPM_CC_Quote;

    memcpy(l_cmd->quoteData.tpmiDhObject,l_tpmiDhObject,sizeof(l_tpmiDhObject));

    memcpy(l_cmd->quoteData.nonce,
           *i_nonce,
           TPM_NONCE_SIZE_BYTES);

    l_cmd->quoteData.data = l_data;
    l_cmd->quoteData.inScheme = TPM_ALG_SHA256;

    l_cmd->quoteData.pcrSelection.count = 1;
    l_cmd->quoteData.pcrSelection.pcrSelections[0].algorithmId = TPM_ALG_SHA256;
    l_cmd->quoteData.pcrSelection.pcrSelections[0].sizeOfSelect =PCR_SELECT_MAX;

    memset(l_cmd->quoteData.pcrSelection.pcrSelections[0].pcrSelect, 0,
           sizeof(l_cmd->quoteData.pcrSelection.pcrSelections[0].pcrSelect));

    for(size_t i = PCR_0; i < FW_USED_PCR_COUNT; ++i)
    {
        l_cmd->quoteData.pcrSelection.pcrSelections[0].pcrSelect[i/8] |=
            0x01 << (i % 8);
    }

    l_errl = tpmTransmit(i_target,
                         l_dataBuf,
                         l_cmd->base.commandSize,
                         l_dataSize,
                         TPM_LOCALITY_0);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdGenerateQuote(): could not transmit TPM command");
        break;
    }

    l_errl = tpmUnmarshalResponseData(TPM_CC_Quote,
                                      l_dataBuf,
                                      l_dataSize,
                                      l_resp,
                                      l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdGenerateQuote(): could not unmarshal response data");
        break;
    }

    if(TPM_SUCCESS != l_resp->responseCode)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdGenerateQuote: TPM (HUID 0x%x) returned a nonzero return code. Expected RC 0x%x, actual RC 0x%x", TARGETING::get_huid(i_target), TPM_SUCCESS, l_resp->responseCode);
        /*@
         * @errortype         ERRL_SEV_UNRECOVERABLE
         * @reasoncode        RC_TPM_BAD_RESP
         * @moduleid          MOD_TPM_CMD_GEN_QUOTE
         * @userdata1         TPM HUID
         * @userdata2[0..31]  Expected response RC
         * @userdata2[32..63] Actual response RC
         * @devdesc           Incorrect response from TPM_CC_Quote
         *                    command (see logs for TPM HUID)
         * @custdesc          Trusted boot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_GEN_QUOTE,
                                   RC_TPM_BAD_RESP,
                                   TARGETING::get_huid(i_target),
                                   TWO_UINT32_TO_UINT64(
                                        TPM_SUCCESS,
                                        l_resp->responseCode));
        break;
    }

    TPM2_QuoteOut* l_read = reinterpret_cast<TPM2_QuoteOut*>(l_resp);
    void* l_quoteDataPtr = &l_read->quoteData;

    // The response size contains the size of the base response structure too,
    // so subtract that size from the size of the actual quote data.
    o_data->size = l_read->base.responseSize -
                   sizeof(l_read->base) -
                   sizeof(l_read->authSessionSize);
    memcpy(o_data->data, l_quoteDataPtr, o_data->size);

    } while(0);

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK"tpmCmdGenerateQuote()");
    return l_errl;
}

errlHndl_t tpmCmdFlushContext(TpmTarget* i_target)
{
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"tpmCmdFlushContext()");
    errlHndl_t l_errl = nullptr;

    size_t l_dataSize = MAX_TRANSMIT_SIZE;
    uint8_t l_dataBuf[l_dataSize] = {};

    TPM2_FlushContextIn* l_cmd =
                              reinterpret_cast<TPM2_FlushContextIn*>(l_dataBuf);
    TPM2_BaseOut* l_resp = reinterpret_cast<TPM2_BaseOut*>(l_dataBuf);
    do {
    l_cmd->base.tag = TPM_ST_NO_SESSIONS;
    l_cmd->base.commandSize = TPM_FLUSH_CONTEXT_SIZE;
    l_cmd->base.commandCode = TPM_CC_FlushContext;

    l_cmd->flushHandle = TPM_HT_TRANSIENT;

    l_errl = tpmTransmit(i_target,
                         l_dataBuf,
                         l_cmd->base.commandSize,
                         l_dataSize,
                         TPM_LOCALITY_0);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdFlushContext(): could not transmit TPM command");
        break;
    }

    l_errl = tpmUnmarshalResponseData(TPM_CC_FlushContext,
                                      l_dataBuf,
                                      l_dataSize,
                                      l_resp,
                                      l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdFlushContext(): could not unmarshal response data");
        break;
    }

    if(TPM_SUCCESS != l_resp->responseCode)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdFlushContext: TPM (HUID 0x%x) returned a nonzero return code. Expected RC 0x%x, actual RC 0x%x", TARGETING::get_huid(i_target), TPM_SUCCESS, l_resp->responseCode);
        /*@
         * @errortype         ERRL_SEV_UNRECOVERABLE
         * @reasoncode        RC_TPM_BAD_RESP
         * @moduleid          MOD_TPM_CMD_FLUSH_CONTEXT
         * @userdata1         TPM HUID
         * @userdata2[0..31]  Expected response RC
         * @userdata2[32..63] Actual response RC
         * @devdesc           Incorrect response from TPM2_FlushContext
         *                    command (see logs for TPM HUID)
         * @custdesc          Trusted boot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_FLUSH_CONTEXT,
                                   RC_TPM_BAD_RESP,
                                   TARGETING::get_huid(i_target),
                                   TWO_UINT32_TO_UINT64(
                                        TPM_SUCCESS,
                                        l_resp->responseCode));
        break;
    }

    } while(0);

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK"tpmCmdFlushContext()");
    return l_errl;
}

errlHndl_t tpmCmdExpandTpmLog(TpmTarget* i_target)
{
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"tpmCmdExpandTpmLog()");
    errlHndl_t l_errl = nullptr;

    do {
    auto l_tpmLogMgr = getTpmLogMgr(i_target);
    if(!l_tpmLogMgr)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmCmdExpandTpmLog: could not fetch TPM log manager for TPM HUID 0x%x", TARGETING::get_huid(i_target));
        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @reasoncode RC_NO_TPM_LOG_MGR
         * @moduleid   MOD_TPM_CMD_EXPAND_TPM_LOG
         * @userdata1  TPM HUID
         * @devdesc    Could not fetch the TPM log manager
         * @custdesc   trustedboot failure
         */
        l_errl = tpmCreateErrorLog(MOD_TPM_CMD_EXPAND_TPM_LOG,
                                   RC_NO_TPM_LOG_MGR,
                                   TARGETING::get_huid(i_target),
                                   0);
        break;
    }

    mutex_lock(&l_tpmLogMgr->logMutex);

    assert(l_tpmLogMgr->eventLogInMem == nullptr, "tpmCmdExpandTpmLog: the TPM log manager has already been moved/expanded");
    l_tpmLogMgr->eventLogInMem = new uint8_t[TPMLOG_DEVTREE_SIZE]();
    l_tpmLogMgr->logMaxSize = TPMLOG_DEVTREE_SIZE;

    memcpy(l_tpmLogMgr->eventLogInMem,
           l_tpmLogMgr->eventLog,
           l_tpmLogMgr->logSize);

    l_tpmLogMgr->newEventPtr = l_tpmLogMgr->eventLogInMem +l_tpmLogMgr->logSize;

    // Remove the old log
    memset(l_tpmLogMgr->eventLog, 0, l_tpmLogMgr->logSize);

    mutex_unlock(&l_tpmLogMgr->logMutex);
    } while(0);
    TRACFCOMP(g_trac_trustedboot, EXIT_MRK"tpmCmdExpandTpmLog()");
    return l_errl;
}

#ifdef __cplusplus
} // end TRUSTEDBOOT
#endif
