/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getDecompressedISDIMMAttrs.C $ */
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
// $ID: getDecompressedISDIMMAttrs.C, v 1.1 2014/9/26 09:22:00 eliner Exp $

/**
 *  @file getDecompressedISDIMMAttrs.C
 *
 *  @brief Decompresses the ISDIMMToC4DQ and DQS Attributes for proper use
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ecmdDataBufferBase.H>
#include <getDecompressedISDIMMAttrs.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
using namespace TARGETING;

void antiPermutation(int i_permNum, int* o_array,int i_finalSize)
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
        l_factorialNum = l_factorialNum/l_factorialIndex;
        l_factorialIndex = l_factorialIndex - 1;
    }

    //now make the array to match the size
    l_size = i_finalSize -1;

    //fill the array
    //first with 0's
    for(int l_arrayIndex = 0; l_arrayIndex<i_finalSize;l_arrayIndex++)
    {
        o_array[l_arrayIndex] = 0;
    }

    while(l_permNum >= l_factorialNum || l_factorialIndex > 0)
    {
        if(l_permNum < l_factorialNum){
            l_factorialNum = l_factorialNum/l_factorialIndex;
            l_factorialIndex = l_factorialIndex - 1;
        }else{
            o_array[l_size-l_factorialIndex] =
                    o_array[l_size-l_factorialIndex]+1;
            l_permNum = l_permNum - l_factorialNum;
        }
    }
}

void unPermeateToVector(int* i_array, int i_size,std::vector<int>& o_result)
{
    std::vector<int> l_allNumbers;
    for(int l_allNumIndex=0;l_allNumIndex<i_size;l_allNumIndex++)
    {
        l_allNumbers.push_back(l_allNumIndex);
    }

    o_result.clear();
    for(int l_arrayIndex = 0; l_arrayIndex<i_size;l_arrayIndex++)
    {
        o_result.push_back(l_allNumbers.at(i_array[l_arrayIndex]));
        l_allNumbers.erase(l_allNumbers.begin()+i_array[l_arrayIndex]);
    }
}

int getSeparatedInformation(ecmdDataBufferBase& i_toSeparateDQ,
                            ecmdDataBufferBase& i_separateDQS,
                            int* o_nibSwap,int* o_nibToNib,int* o_nibSwapDQS)
{
    uint32_t o_byteToByte = 0;

    for(int l_nibSwapIndex=0;l_nibSwapIndex<9;l_nibSwapIndex++)
    {
        //the nibble bits are bits 31 to 39
        uint32_t l_DQ_index_bit = l_nibSwapIndex+31;
        uint32_t l_DQS_index_bit = l_nibSwapIndex+7;
        o_nibSwap[l_nibSwapIndex] = i_toSeparateDQ.getBit(l_DQ_index_bit);
        o_nibSwapDQS[l_nibSwapIndex] = i_separateDQS.getBit(l_DQS_index_bit);

    }
    uint32_t l_toAdd = 1;
    //@todo-RTC:117985
    for(int l_byteIndex=23;l_byteIndex>=2;l_byteIndex--)
    {
        //byte to byte is bits 2-23
        uint32_t l_currentBit = i_toSeparateDQ.getBit(l_byteIndex);
        if(l_currentBit == 1)
        {
            o_byteToByte = o_byteToByte + l_toAdd;
        }
        l_toAdd = l_toAdd * 2;
    }
    for(int l_nibbleIndex=0;l_nibbleIndex<18;l_nibbleIndex++)
    {
        uint32_t l_currentSum = 0;
        uint32_t l_toAddNibble = 1;
        //nibble to Nibble is 46-135
        for(int l_bitIndex=4;l_bitIndex>=0;l_bitIndex--)
        {
            uint32_t l_currentBit = i_toSeparateDQ.getBit((l_nibbleIndex*5)+
                            46+l_bitIndex);
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

void convertToFinal80Array(uint8_t* o_final80Array,
                std::vector<int>& i_byteNums,int* i_nibbleSwap,
                std::vector<std::vector<int> >& i_nibbleToNibNums)
{
    int l_byteIndex;
    int l_zeroSeven;

    for(l_byteIndex = 0; l_byteIndex < 9; l_byteIndex++)
    {
        for(l_zeroSeven = 0; l_zeroSeven<8; l_zeroSeven++)
        {
            o_final80Array[(l_byteIndex*8)+l_zeroSeven] =
                    (i_byteNums.at(l_byteIndex)*8) + l_zeroSeven;
        }
    }
    //nibble switch now.
    for(int l_nibIndex = 0; l_nibIndex<9;l_nibIndex++)
    {
        if(i_nibbleSwap[l_nibIndex] == 1)
        {
            for(int l_bitIndex = 0; l_bitIndex<4;l_bitIndex++)
            {
                char l_placeHolder = o_final80Array[(l_nibIndex*8) +
                        l_bitIndex];
                o_final80Array[(l_nibIndex*8) + l_bitIndex] =
                        o_final80Array[(l_nibIndex*8) + l_bitIndex + 4];
                o_final80Array[(l_nibIndex*8) + l_bitIndex + 4] =
                        l_placeHolder;
            }
        }
    }
    //nibble order now.
    for(int l_nibOrderIndex = 0; l_nibOrderIndex<18; l_nibOrderIndex++)
    {
        std::vector<int> l_currentNibSet =
                i_nibbleToNibNums.at(l_nibOrderIndex);
        o_final80Array[(l_nibOrderIndex*4)+1] =
                o_final80Array[(l_nibOrderIndex*4)] + l_currentNibSet.at(1);
        o_final80Array[(l_nibOrderIndex*4)+2] =
                o_final80Array[(l_nibOrderIndex*4)] + l_currentNibSet.at(2);
        o_final80Array[(l_nibOrderIndex*4)+3] =
                o_final80Array[(l_nibOrderIndex*4)] + l_currentNibSet.at(3);
        o_final80Array[(l_nibOrderIndex*4)] =
                o_final80Array[(l_nibOrderIndex*4)] + l_currentNibSet.at(0);
    }
    for(int l_finalIndex = 72; l_finalIndex<80;l_finalIndex++)
    {
        o_final80Array[l_finalIndex] = 255;
    }
}

void convertToFinal20Array(uint8_t* o_final20Array,
                std::vector<int>& i_byteNums,int* i_nibbleSwap)
{
    int l_byteIndex;
    int l_zeroOne;

    for(l_byteIndex = 0; l_byteIndex < 9; l_byteIndex++)
    {
        for(l_zeroOne = 0; l_zeroOne < 2; l_zeroOne++)
        {
            o_final20Array[(l_byteIndex*2)+l_zeroOne] =
                    (i_byteNums.at(l_byteIndex)*2) + l_zeroOne;
        }
    }
    //nibble switch now
    for(int l_nibIndex = 0;l_nibIndex<9;l_nibIndex++)
    {
        if(i_nibbleSwap[l_nibIndex] == 1)
        {
            char l_placeHolder = o_final20Array[(l_nibIndex*2)];
            o_final20Array[(l_nibIndex*2)] = o_final20Array[(l_nibIndex*2)+1];
            o_final20Array[(l_nibIndex*2) + 1] = l_placeHolder;
        }
    }

    o_final20Array[18] = 255;
    o_final20Array[19] = 255;
}

void decodeISDIMMAttrs(ecmdDataBufferBase& i_dataDQ,
                ecmdDataBufferBase& i_dataDQS,uint8_t* o_finalArray,
                uint8_t* o_finalDQSArray)
{
    int l_byteArray[9];
    int l_nibbleSwap[9];
    int l_nibOrder[18];
    int l_nibbleSwapDQS[9];
    int l_byteOrder = getSeparatedInformation(i_dataDQ,i_dataDQS,l_nibbleSwap,
                    l_nibOrder,l_nibbleSwapDQS);
    int l_sizeByte = 9;
    int l_sizeNibble = 4;

    antiPermutation(l_byteOrder,l_byteArray,l_sizeByte);
    std::vector<int> l_byteAllNumbers;
    unPermeateToVector(l_byteArray,l_sizeByte,l_byteAllNumbers);

    int l_nibOrderArray[18][4];

    std::vector<std::vector<int> > l_nibToNibAllNums;
    for(int l_eachNibble=0;l_eachNibble<18;l_eachNibble++)
    {
        antiPermutation(l_nibOrder[l_eachNibble],
                        l_nibOrderArray[l_eachNibble],l_sizeNibble);
        std::vector<int> l_currentNibToNib;
        unPermeateToVector(l_nibOrderArray[l_eachNibble],
                           l_sizeNibble,l_currentNibToNib);
        l_nibToNibAllNums.push_back(l_currentNibToNib);
    }

    convertToFinal80Array(o_finalArray,l_byteAllNumbers,
                    l_nibbleSwap,l_nibToNibAllNums);
    convertToFinal20Array(o_finalDQSArray,l_byteAllNumbers,l_nibbleSwapDQS);
}


