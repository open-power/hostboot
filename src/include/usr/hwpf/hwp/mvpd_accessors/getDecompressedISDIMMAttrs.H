/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getDecompressedISDIMMAttrs.H $ */
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
// $ID: getDecompressedISDIMMAttrs.H, v 1.1 2014/9/26 09:22:00 eliner Exp $
/**
 *  @file getDecompressedISDIMMAttrs.H
 *
 *  @brief Decompresses the ISDIMMToC4DQ and DQS Attributes for proper use
 */
extern "C"
{

/**
 *  @brief Un-permeates the decimal input into an array of variable size
 *
 *  @param[in] i_permNum   - Decimal number to un-permeate
 *  @param[in] i_finalSize - Final Size of the variable array
 *  @param[out] o_array    - Created Array of un-permeated numbers
 */
void antiPermutation(int i_permNum, int* o_array,int i_finalSize);

/**
 *  @brief Translates the array from the condensed version to the
 *         actual information
 *  example: [1,0,0,5,1,1,1,1,0] -> [1,0,2,8,4,5,6,7,3]
 *
 *  @param[in] i_array   - condensed array of information
 *  @param[in] i_size    - size of array
 *  @param[out] o_result - translated array of information
 */
void unPermeateToVector(int* i_array, int i_size, std::vector<int>& o_result);

/**
 *  @brief Separates the input into the 4 needed parts; nibble swap, nibble
 *         to nibble relationship, DQS nibble swap, and the byte to
 *         byte relationship
 *
 *  @param[in] i_toSeparateDQ  - contains all the information for DQ
 *  @param[in] i_toSeparateDQS - contains all the information for DQS
 *  @param[out] o_nibSwap      - DQ nibble swap information
 *  @param[out] o_nibToNib     - nibble to nibble relationship
 *  @param[out[ o_nibSwapDQS   - DQS nibble swap information
 *
 *  @return int - byte to byte relationship information
 */
int getSeparatedInformation(ecmdDataBufferBase& i_toSeparateDQ,
                ecmdDataBufferBase& i_separateDQS,
                int* o_nibSwap,int* o_nibToNib,int* o_nibSwapDQS);

/**
 *  @brief Converts all information into the final DQ 80-byte array
 *
 *  @param[out] o_final80Array   - completed decompressed array
 *  @param[in] i_byteNums        - translated relationship between the bytes
 *  @param[in] i_nibbleSwap      - translated DQ nibble swap information
 *  @param[in] i_nibbleToNibNums - translated relationship between the nibbles
 */
void convertToFinal80Array(int* o_final80Array,
                std::vector<int>& i_byteNums,int* i_nibbleSwap,
                std::vector<std::vector<int> >& i_nibbleToNibNums);

/**
 *  @brief Converts all the information into the final dQS 20-byte array
 *
 *  @param[out] o_final20Array - completed decompressed array
 *  @param[in] i_byteNums      - translated relationship between the bytes
 *  @param[in] i_nibbleSwap    - translated DQS nibble swap information
 */
void convertToFinal20Array(int* o_final20Array,std::vector<int>& i_byteNums,
                int* i_nibbleSwap);

/**
 *  @brief Controls the flow of data from the different functions
 *
 *  @param[in] i_dataDQ         - original DQ information before any processing
 *  @param[in] i_dataDQS        - original DQS information before any processing
 *  @param[out] o_finalArray    - completed DQ decompressed array
 *  @param[out] o_finalDQSArray - completed DQS decompressed array
 */
void decodeISDIMMAttrs(ecmdDataBufferBase& i_dataDQ,
                ecmdDataBufferBase& i_dataDQS,
                uint8_t* o_finalArray, uint8_t* o_finalDQSArray);

}




