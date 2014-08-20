/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/DQCompressionLib.H $  */
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
//$Id: DQCompressionLib.H,v 1.7 2014/11/12 20:03:25 pragupta Exp $

/* @file  DQCompressionLib.H
 *
 * @brief Header file DQCompressionLib
 *
 */

#ifndef __DQCOMPRESSIONLIB_H
#define __DQCOMPRESSIONLIB_H

#include <ecmdDataBufferBase.H>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#ifdef DQCOMPRESSION_TEST
#define DQ_TRAC(fmt,args...) FAPI_INF (fmt, ##args)
#else
#define DQ_TRAC(fmt,args...) printf(fmt, ##args)
#endif
namespace DQCompression
{
    //ERROR CODES
    //Mapping of these error codes to error messages
    //are in DQCompressionReasonCodes.H
    enum ErrCodes
    {
        NO_ERR = 0,
        ECMD_OPER_ERROR,
        INVALID_INPUT,
        INVALID_ARRAY_TYPE,
        LAST_ERR,
    };
/**
 * @brief  Calculates the encoding for DQ or DQS arrays for one port
 *         to be stored in VPD
 * @param  i_data DQ or DQS array as a vector
 * @param  i_arrayType type of array being passed in (DQ/DQS)
 * @param  o_encodeData: 17 bytes of data for DQ and
 *         2 bytes of data for DQS
 * @retval ErrCodes Values
 */
   int encodeDQ (std::vector<uint8_t>& i_data,
       uint32_t i_arrayType, ecmdDataBufferBase& o_encodedData);
}
#endif

