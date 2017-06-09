/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getDecompressedISDIMMAttrs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///  @file getDecompressedISDIMMAttrs.H
///  @brief Decompresses the ISDIMMToC4DQ and DQS Attributes for proper use
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <fapi2.H>
extern "C"
{

///
///  @brief Un-permeates the decimal input into an array of variable size
///  @param[in] i_permNum   - Decimal number to un-permeate
///  @param[out] o_array    - Created Array of un-permeated numbers
///  @param[in] i_finalSize - Final Size of the variable array
///
    void antiPermutation(const int i_permNum,
                         int* o_array,
                         const int i_finalSize);

///
///  @brief Translates the array from the condensed version to the
///         actual information
///  @note example: [1,0,0,5,1,1,1,1,0] -> [1,0,2,8,4,5,6,7,3]
///  @param[in] i_array   - condensed array of information
///  @param[in] i_size    - size of array
///  @param[out] o_result - translated array of information
///
    void unPermeateToVector(const int* i_array,
                            const int i_size,
                            std::vector<int>& o_result);

///
///  @brief Separates the input into the 4 needed parts; nibble swap, nibble
///         to nibble relationship, DQS nibble swap, and the byte to
///         byte relationship
///  @param[in] i_toSeparateDQ  - contains all the information for DQ
///  @param[in] i_toSeparateDQS - contains all the information for DQS
///  @param[out] o_nibSwap      - DQ nibble swap information
///  @param[out] o_nibToNib     - nibble to nibble relationship
///  @param[out[ o_nibSwapDQS   - DQS nibble swap information
///  @return int - byte to byte relationship information
///
    int getSeparatedInformation(const fapi2::variable_buffer i_toSeparateDQ,
                                const fapi2::variable_buffer i_separateDQS,
                                int* o_nibSwap,
                                int* o_nibToNib,
                                int* o_nibSwapDQS);

///
///  @brief Converts all information into the final DQ 80-byte array
///  @param[out] o_final80Array   - completed decompressed array
///  @param[in] i_byteNums        - translated relationship between the bytes
///  @param[in] i_nibbleSwap      - translated DQ nibble swap information
///  @param[in] i_nibbleToNibNums - translated relationship between the nibbles
///
    void convertToFinal80Array(int* o_final80Array,
                               const std::vector<int>& i_byteNums,
                               const int* i_nibbleSwap,
                               const std::vector<std::vector<int> >& i_nibbleToNibNums);

///
///  @brief Converts all the information into the final dQS 20-byte array
///  @param[out] o_final20Array - completed decompressed array
///  @param[in] i_byteNums      - translated relationship between the bytes
///  @param[in] i_nibbleSwap    - translated DQS nibble swap information
///
    void convertToFinal20Array(int* o_final20Array,
                               const std::vector<int>& i_byteNums,
                               const int* i_nibbleSwap);

///
///  @brief Controls the flow of data from the different functions
///  @param[in] i_dataDQ         - original DQ information before any processing
///  @param[in] i_dataDQS        - original DQS information before any processing
///  @param[out] o_finalArray    - completed DQ decompressed array
///  @param[out] o_finalDQSArray - completed DQS decompressed array
///
    void decodeISDIMMAttrs(const fapi2::variable_buffer i_dataDQ,
                           const fapi2::variable_buffer i_dataDQS,
                           uint8_t* o_finalArray,
                           uint8_t* o_finalDQSArray);

}
