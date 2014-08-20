/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/hwp/mvpd_accessors/compressionTool/DQCompressionConsts.H,v $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: DQCompressionConsts.H,v 1.1 2014/11/12 19:55:07 pragupta Exp $
#ifndef _DQCOMPRESSIONCONSTS_H_
#define _DQCOMPRESSIONCONSTS_H_

namespace DQCompression
{
/* Constants to be used by compression and decompression */
    const uint32_t DQarray_size         = 80;
    const uint32_t DQSarray_size        = 20;
    const uint32_t BYTE_LENGTH          =  8;
    const uint32_t BYTE_CODE_LENGTH     =  3; //bytes
    const uint32_t NIBBLE_SWAP_LENGTH   =  2; //bytes
    const uint32_t NIBBLE_PERM_LENGTH   =  5; //bits
    const uint32_t DQ_CODE_LENGTH       =  17;//bytes
    const uint32_t DQS_CODE_LENGTH      =  2; //bytes
    const uint32_t SIX_BIT_ZERO_PADDING =  6;

    const uint32_t DQ_GROUP_SIZE        =  8;
    const uint32_t DQS_GROUP_SIZE       =  2;
    //DQ and DQS Flag - to determine the input type
    const uint8_t DQ = 1;
    const uint8_t DQS= 2;
}
#endif
