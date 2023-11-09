/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/errlud_sbeio.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
 *  @file errlud_sbeio.C
 *
 *  @brief Implementation of classes to log sbeio FFDC
 */
#include <errl/errlmanager.H>
#include <sbeio/errlud_sbeio.H>
#include <sbeio/sbeioreasoncodes.H> // SBEIO_UDT_PARAMETERS

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
            TRACFCOMP(g_trac_sbeio, printf_string,##args)

using namespace TARGETING;

namespace SBEIO
{

//------------------------------------------------------------------------------
//  SPPE Code Levels User Details
//------------------------------------------------------------------------------
UdSPPECodeLevels::UdSPPECodeLevels( TARGETING::Target * i_ocmb )
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Check for NULL target
        if( nullptr == i_ocmb )
        {
            TRACFCOMP(g_trac_sbeio, ERR_MRK"UdSPPECodeLevels: OCMB target is NULL");
            /*@
            * @errortype
            * @moduleid        SBEIO_ERRLUD_SPPE_CODE_LEVELS
            * @reasoncode      SBEIO_OCMB_NULL_TARGET
            * @userdata1       unused
            * @userdata2       unused
            * @devdesc         Null target passed
            * @custdesc        Firmware error
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SBEIO_ERRLUD_SPPE_CODE_LEVELS,
                                            SBEIO_OCMB_NULL_TARGET,
                                            0,
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
            l_err->collectTrace(SBEIO_COMP_NAME);
            ERRORLOG::errlCommit(l_err, SBE_COMP_ID);
            break;
        }

        // Set up Ud instance variables
        iv_CompId = SBEIO_COMP_ID;
        iv_Version = 1;
        iv_SubSection = SBEIO_UDT_SPPE_CODE_LEVELS;

        //***** Memory Layout *****
        // 4 bytes  : OCMB HUID
        // 4 bytes  : ATTR_SBE_VERSION_INFO
        // 4 bytes  : ATTR_SBE_COMMIT_ID
        // 64 bytes : ATTR_SBE_BOOTLOADER_CODELEVEL
        // 64 bytes : ATTR_SBE_RUNTIME_CODELEVEL
        // 21 bytes : ATTR_SBE_RELEASE_TAG
        // 21 bytes : ATTR_SBE_BUILD_TAG
        // 21 bytes : ATTR_SBE_EKB_BUILD_TAG

        auto l_ocmbHuid = get_huid(i_ocmb);

        ATTR_SBE_VERSION_INFO_type l_sbeVersionInfo;
        i_ocmb->tryGetAttr<ATTR_SBE_VERSION_INFO>(l_sbeVersionInfo);

        ATTR_SBE_COMMIT_ID_type l_sbeCommitId;
        i_ocmb->tryGetAttr<ATTR_SBE_COMMIT_ID>(l_sbeCommitId);

        ATTR_SBE_BOOTLOADER_CODELEVEL_type l_sbeBldrCodeLvl;
        i_ocmb->tryGetAttr<ATTR_SBE_BOOTLOADER_CODELEVEL>(l_sbeBldrCodeLvl);

        ATTR_SBE_RUNTIME_CODELEVEL_type l_sbeRntmCodeLvl;
        i_ocmb->tryGetAttr<ATTR_SBE_RUNTIME_CODELEVEL>(l_sbeRntmCodeLvl);

        ATTR_SBE_RELEASE_TAG_type l_sbeRelTag;
        i_ocmb->tryGetAttr<ATTR_SBE_RELEASE_TAG>(l_sbeRelTag);

        ATTR_SBE_BUILD_TAG_type l_sbeBldTag;
        i_ocmb->tryGetAttr<ATTR_SBE_BUILD_TAG>(l_sbeBldTag);

        ATTR_SBE_EKB_BUILD_TAG_type l_sbeEkbBldTag;
        i_ocmb->tryGetAttr<ATTR_SBE_EKB_BUILD_TAG>(l_sbeEkbBldTag);

        uint8_t * l_pBuf = reallocUsrBuf(sizeof(uint32_t)*3
                                        +sizeof(uint8_t)*64*2
                                        +sizeof(char)*21*3 );

        // HUID (uint32_t)
        memcpy(l_pBuf, &l_ocmbHuid, sizeof(uint32_t));
        l_pBuf += sizeof(uint32_t);

        // ATTR_SBE_VERSION_INFO (uint32_t)
        memcpy(l_pBuf, &l_sbeVersionInfo, sizeof(uint32_t));
        l_pBuf += sizeof(uint32_t);

        // ATTR_SBE_COMMIT_ID (uint32_t)
        memcpy(l_pBuf, &l_sbeCommitId, sizeof(uint32_t));
        l_pBuf += sizeof(uint32_t);

        // ATTR_SBE_BOOTLOADER_CODELEVEL (uint8_t[64])
        memcpy(l_pBuf, &l_sbeBldrCodeLvl[0], sizeof(uint8_t)*64);
        l_pBuf += sizeof(uint8_t)*64;

        // ATTR_SBE_RUNTIME_CODELEVEL (uint8_t[64])
        memcpy(l_pBuf, &l_sbeRntmCodeLvl[0], sizeof(uint8_t)*64);
        l_pBuf += sizeof(uint8_t)*64;

        // ATTR_SBE_RELEASE_TAG (char[21])
        memcpy(l_pBuf, &l_sbeRelTag[0], sizeof(char)*21);
        l_pBuf += sizeof(char)*21;

        // ATTR_SBE_BUILD_TAG (char[21])
        memcpy(l_pBuf, &l_sbeBldTag[0], sizeof(char)*21);
        l_pBuf += sizeof(char)*21;

        // ATTR_SBE_EKB_BUILD_TAG (char[21])
        memcpy(l_pBuf, &l_sbeEkbBldTag[0], sizeof(char)*21);
        l_pBuf += sizeof(char)*21;

    } while(0);
}

//------------------------------------------------------------------------------
UdSPPECodeLevels::~UdSPPECodeLevels()
{
}

} // end SBEIO namespace
