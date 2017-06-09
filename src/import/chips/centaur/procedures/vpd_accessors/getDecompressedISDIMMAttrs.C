/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getDecompressedISDIMMAttrs.C $ */
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
///  @file getDecompressedISDIMMAttrs.C
///  @brief Decompresses the ISDIMMToC4DQ and DQS Attributes for proper use
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <getDecompressedISDIMMAttrs.H>

///
///  @brief Un-permeates the decimal input into an array of variable size
///  @param[in] i_permNum   - Decimal number to un-permeate
///  @param[out] o_array    - Created Array of un-permeated numbers
///  @param[in] i_finalSize - Final Size of the variable array
///
void antiPermutation(const int i_permNum, int* o_array, const int i_finalSize)
{
    int l_factorialIndex = 1;
    int l_factorialNum = 1;
    int l_permNum = i_permNum;
    int l_size;

    //find the largest factorial needed to represent this number
    //(need to find whether we're antiPermuting an array with length 4 or 9)

    while(i_permNum > l_factorialNum)
    {
        l_factorialIndex = l_factorialIndex + 1;
        l_factorialNum = l_factorialNum * l_factorialIndex;
    }

    if(i_permNum != l_factorialNum && i_permNum != 0)
    {
        l_factorialNum = l_factorialNum / l_factorialIndex;
        l_factorialIndex = l_factorialIndex - 1;
    }

    //now make the array to match the size
    l_size = i_finalSize - 1;

    //fill the array
    //first with 0's
    for(int l_arrayIndex = 0; l_arrayIndex < i_finalSize; l_arrayIndex++)
    {
        o_array[l_arrayIndex] = 0;
    }

    while(l_permNum >= l_factorialNum || l_factorialIndex > 0)
    {
        if(l_permNum < l_factorialNum)
        {
            l_factorialNum = l_factorialNum / l_factorialIndex;
            l_factorialIndex = l_factorialIndex - 1;
        }
        else
        {
            o_array[l_size - l_factorialIndex] =
                o_array[l_size - l_factorialIndex] + 1;
            l_permNum = l_permNum - l_factorialNum;
        }
    }
}

///
///  @brief Translates the array from the condensed version to the
///         actual information
///  @note example: [1,0,0,5,1,1,1,1,0] -> [1,0,2,8,4,5,6,7,3]
///  @param[in] i_array   - condensed array of information
///  @param[in] i_size    - size of array
///  @param[out] o_result - translated array of information
///
void unPermeateToVector(const int* i_array, const int i_size, std::vector<int>& o_result)
{
    std::vector<int> l_allNumbers;

    for(int l_allNumIndex = 0; l_allNumIndex < i_size; l_allNumIndex++)
    {
        l_allNumbers.push_back(l_allNumIndex);
    }

    o_result.clear();

    for(int l_arrayIndex = 0; l_arrayIndex < i_size; l_arrayIndex++)
    {
        o_result.push_back(l_allNumbers.at(i_array[l_arrayIndex]));
        l_allNumbers.erase(l_allNumbers.begin() + i_array[l_arrayIndex]);
    }
}

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
                            int* o_nibSwap, int* o_nibToNib, int* o_nibSwapDQS)
{
    uint32_t o_byteToByte = 0;

    for(int l_nibSwapIndex = 0; l_nibSwapIndex < 9; l_nibSwapIndex++)
    {
        //the nibble bits are bits 31 to 39
        uint32_t l_DQ_index_bit = l_nibSwapIndex + 31;
        uint32_t l_DQS_index_bit = l_nibSwapIndex + 7;
        o_nibSwap[l_nibSwapIndex] = i_toSeparateDQ.isBitSet(l_DQ_index_bit);
        o_nibSwapDQS[l_nibSwapIndex] = i_separateDQS.isBitSet(l_DQS_index_bit);

    }

    uint32_t l_toAdd = 1;

    //@todo-RTC:117985
    for(int l_byteIndex = 23; l_byteIndex >= 2; l_byteIndex--)
    {
        //byte to byte is bits 2-23
        uint32_t l_currentBit = i_toSeparateDQ.isBitSet(l_byteIndex);

        if(l_currentBit == 1)
        {
            o_byteToByte = o_byteToByte + l_toAdd;
        }

        l_toAdd = l_toAdd * 2;
    }

    for(int l_nibbleIndex = 0; l_nibbleIndex < 18; l_nibbleIndex++)
    {
        uint32_t l_currentSum = 0;
        uint32_t l_toAddNibble = 1;

        //nibble to Nibble is 46-135
        for(int l_bitIndex = 4; l_bitIndex >= 0; l_bitIndex--)
        {
            uint32_t l_currentBit = i_toSeparateDQ.isBitSet((l_nibbleIndex * 5) +
                                    46 + l_bitIndex);

            if(l_currentBit == 1)
            {
                l_currentSum = l_currentSum + l_toAddNibble;
            }

            l_toAddNibble = l_toAddNibble * 2;
        }

        o_nibToNib[l_nibbleIndex] = l_currentSum;
    }

    return o_byteToByte;

}

///
///  @brief Converts all information into the final DQ 80-byte array
///  @param[out] o_final80Array   - completed decompressed array
///  @param[in] i_byteNums        - translated relationship between the bytes
///  @param[in] i_nibbleSwap      - translated DQ nibble swap information
///  @param[in] i_nibbleToNibNums - translated relationship between the nibbles
///
void convertToFinal80Array(uint8_t* o_final80Array,
                           const std::vector<int>& i_byteNums, const int* i_nibbleSwap,
                           const std::vector<std::vector<int> >& i_nibbleToNibNums)
{
    int l_byteIndex;
    int l_zeroSeven;

    for(l_byteIndex = 0; l_byteIndex < 9; l_byteIndex++)
    {
        for(l_zeroSeven = 0; l_zeroSeven < 8; l_zeroSeven++)
        {
            o_final80Array[(l_byteIndex * 8) + l_zeroSeven] =
                (i_byteNums.at(l_byteIndex) * 8) + l_zeroSeven;
        }
    }

    //nibble switch now.
    for(int l_nibIndex = 0; l_nibIndex < 9; l_nibIndex++)
    {
        if(i_nibbleSwap[l_nibIndex] == 1)
        {
            for(int l_bitIndex = 0; l_bitIndex < 4; l_bitIndex++)
            {
                char l_placeHolder = o_final80Array[(l_nibIndex * 8) +
                                                    l_bitIndex];
                o_final80Array[(l_nibIndex * 8) + l_bitIndex] =
                    o_final80Array[(l_nibIndex * 8) + l_bitIndex + 4];
                o_final80Array[(l_nibIndex * 8) + l_bitIndex + 4] =
                    l_placeHolder;
            }
        }
    }

    //nibble order now.
    for(int l_nibOrderIndex = 0; l_nibOrderIndex < 18; l_nibOrderIndex++)
    {
        std::vector<int> l_currentNibSet =
            i_nibbleToNibNums.at(l_nibOrderIndex);
        o_final80Array[(l_nibOrderIndex * 4) + 1] =
            o_final80Array[(l_nibOrderIndex * 4)] + l_currentNibSet.at(1);
        o_final80Array[(l_nibOrderIndex * 4) + 2] =
            o_final80Array[(l_nibOrderIndex * 4)] + l_currentNibSet.at(2);
        o_final80Array[(l_nibOrderIndex * 4) + 3] =
            o_final80Array[(l_nibOrderIndex * 4)] + l_currentNibSet.at(3);
        o_final80Array[(l_nibOrderIndex * 4)] =
            o_final80Array[(l_nibOrderIndex * 4)] + l_currentNibSet.at(0);
    }

    for(int l_finalIndex = 72; l_finalIndex < 80; l_finalIndex++)
    {
        o_final80Array[l_finalIndex] = 255;
    }
}

///
///  @brief Converts all the information into the final dQS 20-byte array
///  @param[out] o_final20Array - completed decompressed array
///  @param[in] i_byteNums      - translated relationship between the bytes
///  @param[in] i_nibbleSwap    - translated DQS nibble swap information
///
void convertToFinal20Array(uint8_t* o_final20Array,
                           const std::vector<int>& i_byteNums, const int* i_nibbleSwap)
{
    int l_byteIndex;
    int l_zeroOne;

    for(l_byteIndex = 0; l_byteIndex < 9; l_byteIndex++)
    {
        for(l_zeroOne = 0; l_zeroOne < 2; l_zeroOne++)
        {
            o_final20Array[(l_byteIndex * 2) + l_zeroOne] =
                (i_byteNums.at(l_byteIndex) * 2) + l_zeroOne;
        }
    }

    //nibble switch now
    for(int l_nibIndex = 0; l_nibIndex < 9; l_nibIndex++)
    {
        if(i_nibbleSwap[l_nibIndex] == 1)
        {
            char l_placeHolder = o_final20Array[(l_nibIndex * 2)];
            o_final20Array[(l_nibIndex * 2)] = o_final20Array[(l_nibIndex * 2) + 1];
            o_final20Array[(l_nibIndex * 2) + 1] = l_placeHolder;
        }
    }

    o_final20Array[18] = 255;
    o_final20Array[19] = 255;
}

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
                       uint8_t* o_finalDQSArray)
{
    int l_byteArray[9] = {};
    int l_nibbleSwap[9] = {};
    int l_nibOrder[18] = {};
    int l_nibbleSwapDQS[9] = {};
    int l_byteOrder = getSeparatedInformation(i_dataDQ, i_dataDQS, l_nibbleSwap,
                      l_nibOrder, l_nibbleSwapDQS);
    int l_sizeByte = 9;
    int l_sizeNibble = 4;

    antiPermutation(l_byteOrder, l_byteArray, l_sizeByte);
    std::vector<int> l_byteAllNumbers;
    unPermeateToVector(l_byteArray, l_sizeByte, l_byteAllNumbers);

    int l_nibOrderArray[18][4] = {};

    std::vector<std::vector<int> > l_nibToNibAllNums;

    for(int l_eachNibble = 0; l_eachNibble < 18; l_eachNibble++)
    {
        antiPermutation(l_nibOrder[l_eachNibble],
                        l_nibOrderArray[l_eachNibble], l_sizeNibble);
        std::vector<int> l_currentNibToNib;
        unPermeateToVector(l_nibOrderArray[l_eachNibble],
                           l_sizeNibble, l_currentNibToNib);
        l_nibToNibAllNums.push_back(l_currentNibToNib);
    }

    convertToFinal80Array(o_finalArray, l_byteAllNumbers,
                          l_nibbleSwap, l_nibToNibAllNums);
    convertToFinal20Array(o_finalDQSArray, l_byteAllNumbers, l_nibbleSwapDQS);
}


