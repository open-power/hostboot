/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/hwp/mvpd_accessors/compressionTool/DQCompressionLib.C,v $ */
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
//$Id: DQCompressionLib.C,v 1.6 2014/11/12 19:53:08 pragupta Exp $
/**
 * @file  DQCompressionLib.C
 * @brief Defines utility functions which calculates the encoding for DQ
 *        or DQS arrays
 *
 * Wiring Rules:
 * - On a port any byte may be wired to any byte on the DIMM connector
 *   i.e. bytes must remain whole and undivided
 *
 * - In a Byte the Upper and Lower Nibble my be swapped.
 *   This includes the DQ and the DQS
 *
 * - In a Nibble any connection of the DQ is allowed.
 *    i.e. Nibbles must remain whole and undivided
 *
 * - The DQS may be swapped from the upper and lower nibbles
 *   in a byte without swapping the DQ.
 */
#include <DQCompressionLib.H>
#include "DQCompressionConsts.H"

using namespace DQCompression;
/**
 * @brief  Checks whether the input follows the wiring rules or not
 * @param  i_data DQ or DQS array as a vector
 * @param  i_arrayType DQ = 1 and DQS = 2
 */
int validateInputData (const std::vector<uint8_t>& i_data,
                uint32_t i_arrayType)
{
    int  l_rc = NO_ERR;
    do
    {
        l_rc = ((i_data.size() == 80) || (i_data.size() == 20)) ?
                NO_ERR : INVALID_INPUT;
        if (l_rc != NO_ERR)
        {
                DQ_TRAC("Input data size is: %d. Size should be 80 or 20\n",
                                (int)i_data.size());
                break;
        }
        uint32_t l_grpSize = (i_arrayType == DQS) ? 2: BYTE_LENGTH;

        //Check that the bytes are whole and undivided
        //Check that the nibbles are whole and undivided
        std::vector<uint8_t> l_data (i_data);

        std::vector<uint8_t>::iterator l_itBegin  = l_data.begin();
        std::vector<uint8_t>::iterator l_itMiddle = l_itBegin + (l_grpSize/2);
        std::vector<uint8_t>::iterator l_itEnd    = l_itBegin + l_grpSize;

        uint32_t l_loopCnts = l_data.size()-l_grpSize;
        for(uint32_t i = 0; (i < l_loopCnts); i += l_grpSize)
        {
            //Sort nibbles at a time
            std::sort(l_itBegin, l_itMiddle);
            std::sort(l_itMiddle,l_itEnd);

            //Check the first nibble
            for (std::vector<uint8_t>::iterator j = l_itBegin;
                                j < l_itMiddle-1; j++)
            {
                if (*(j+1) != (*j)+1)
                {
                    l_rc = INVALID_INPUT;
                    DQ_TRAC("First nibble of byte %d is not together\n",i);
                    break;
                }
            }
            if (l_rc)
            {
                break;
            }

            //Check the second nibble
            for (std::vector<uint8_t>::iterator j = l_itMiddle;
                                (j < l_itEnd-1); j++)
            {
                if (*(j+1) != (*j)+1)
                {
                    l_rc = INVALID_INPUT;
                    DQ_TRAC("Second nibble of byte %d is not together\n",i);
                    break;
                }
            }
            if (l_rc)
            {
                break;
            }

            //Check that first and second nibble are part of the same byte
            uint8_t l_inc = l_grpSize/2;
            if (((*l_itBegin+l_inc) != *l_itMiddle) &&
                                ((*l_itBegin-l_inc) != *l_itMiddle))
            {
                l_rc = INVALID_INPUT;
                DQ_TRAC("Byte %d is not together\n", i);
                break;
            }

            l_itBegin += l_grpSize;
            l_itMiddle+= l_grpSize;
            l_itEnd   += l_grpSize;
       } //end for loop
    } while (0);
    return l_rc;
}


/**
 * @brief  Calculates the byte-to-byte mapping for ISDIMM to Centaur
 * @param  i_data DQ or DQS array as a vector
 * @param  o_byteMap: vector that will hold the byte-to-byte mapping
 */
void byte_mapping (std::vector<uint8_t>& i_data,
                std::vector<uint8_t>& o_byteMap)
{
    uint32_t l_size = i_data.size() - BYTE_LENGTH;

    for(uint32_t i = 0; i < l_size; i += BYTE_LENGTH)
    {
        o_byteMap.push_back(i_data[i]/BYTE_LENGTH);
    }
}

/**
 * @brief  Calculates the permutation of a sequence between two iterators
 * @param  i_itBegin iterator to the beginning of the sequence
 * @param  i_itEnd   iterator to the end of the sequence
 * @retval uint32_t code: 24 bits of code for byte permuatation
 *         and 5 bits of code for nibble permutation
 */
uint32_t permutation (const std::vector<uint8_t>::iterator i_itBegin,
                const std::vector<uint8_t>::iterator i_itEnd)
{
    std::vector<uint8_t> l_sequence (i_itBegin, i_itEnd);
    std::vector<uint8_t> l_permutation;
    std::vector<uint8_t> l_index (l_sequence);
    size_t l_seqSize = l_sequence.size();

    //We want the sorted list of sequence to determine
    //the index for lehmer's code
    std::sort(l_index.begin(), l_index.end());

    for(uint32_t i = 0; i < l_seqSize; i++)
    {
        //find the index of the value in sequence in the index array
        std::vector<uint8_t> ::iterator it = std::find (l_index.begin(),
                        l_index.end(), l_sequence.at(i));

        //Add that index to another array
        uint8_t l_idx = it-l_index.begin();
        l_permutation.push_back(l_idx);

        //Delete that value from the array and shift
        //This will change the indices for the rest of
        //the values each iteration
        l_index.erase(l_index.begin() + l_idx);
    }

    //Skip the last element as it is always zero
    l_permutation.pop_back();

    uint32_t l_code = 0;
    uint32_t l_factorial = 1;

    //Generate the variable base code
    //Since, the last element will always be zero.
    //we start multiplying by 1!
    for (uint32_t i = 1; i < l_seqSize; i++)
    {
        l_factorial *= i;
        l_code += l_factorial * l_permutation.back();
        l_permutation.pop_back();
    }
    return l_code;
}

/**
 * @brief  Figures out if the nibbles within a byte are swapped or not
 * @param  i_data DQ or DQS array as a vector
 * @param  l_grpSize: 8 for DQ and 2 for DQS
 * @retval uint32_t which has 1 for the byte whose nibble is swapped
 *         or 0 if the nibbles are not swapped
 */
uint32_t nibble_swap (std::vector<uint8_t>& i_data, uint32_t l_grpSize)
{
    uint32_t o_swap = 0;
    //Skip the last one as it is unused
    for(uint32_t i = 0; i < i_data.size() - l_grpSize; i+= l_grpSize)
    {
        if (i_data.at(i) > i_data.at(i+(l_grpSize/2)))
        {
            o_swap |= 1;
        }
        o_swap <<= 1;
    }
    return (o_swap>>1);
}

/**
 * @brief  Insert data in ecmdDataBuffer one byte at a time to preserve
 *         endianess
 * @param  o_encodedData: buffer to insert the data into
 * @param  i_data:        value to be inserted in ecmdDataBuffer
 * @param  i_size:        number of bytes to insert
 * @param  i_startBit:    Bit to start inserting the data from
 * @retval errl:          NULL for no-err and BUFFER_OVERFLOW
 *                        if error inserting in ecmdDataBuffer
 */
int insertEncodedData (ecmdDataBufferBase& o_encodedData, uint32_t i_data,
                uint32_t i_size, uint32_t i_startBit)
{
    DQ_TRAC("Entering insertEncodedData i_data:%X, i_size:%d, i_startBit:%d\n",
                i_data, i_size, i_startBit);
    int  l_rc = NO_ERR;
    //Insert one byte at a time to take care of endianess
    for(int i = i_size; i > 0; i--)
    {
        uint32_t l_datatobeinserted = (i_data>>((i-1)*BYTE_LENGTH))&0xFF;
        l_rc = o_encodedData.insertFromRight(l_datatobeinserted,
                        i_startBit, BYTE_LENGTH);
        if (l_rc)
        {
            l_rc = ECMD_OPER_ERROR;
            DQ_TRAC("ECMD errored while writing %d data ;startbit=%d\n",
                                l_datatobeinserted, i_startBit);
            break;
        }
        i_startBit += BYTE_LENGTH;
    }
    return l_rc;
}

/**
 * @brief  Calculates the encoding for ISDIMM to C4DQ or C4DQS
 * @param  i_data    DQ or DQS array as a vector
 * @param  i_arrayType DQ = 1 and DQS = 2
 * @param  o_encodedData buffer to insert the encoded data into
 * @retval error codes
 */
int DQCompression::encodeDQ (std::vector<uint8_t>& i_data,
                uint32_t i_arrayType, ecmdDataBufferBase& o_encodedData)
{
    int l_rc = NO_ERR;
    uint8_t l_grpSize;

    DQ_TRAC("Entering encodeDQ\n");
    do
    {
        l_rc = validateInputData (i_data, i_arrayType);
        if(l_rc)
        {
            DQ_TRAC ("validateInputData errored\n");
            break;
        }
        if (i_arrayType == DQ)
        {
            l_grpSize = DQ_GROUP_SIZE;
            //allocate the buffers with right length
            o_encodedData.setByteLength(DQ_CODE_LENGTH);

            //Determine the byte-to-byte mapping
            std::vector<uint8_t> l_byteMap;
            byte_mapping(i_data, l_byteMap);

            //Determine the permutation for byte mapping
            uint32_t l_byteCode = permutation(l_byteMap.begin(),
                        l_byteMap.end());

            //Check if the nibbles are swapped within a byte
            uint32_t l_nibbleSwap = nibble_swap(i_data, l_grpSize);

            //Copy everything into the o_encodedData buffer
            //Copy encoded data for byte-to-byte mapping
            uint32_t l_startBit = 0;
            DQ_TRAC("Writing byte-to-byte mapping to ecmdBuffer\n");
            l_rc = insertEncodedData (o_encodedData, l_byteCode,
                        BYTE_CODE_LENGTH,l_startBit);
            if (l_rc)
            {
                DQ_TRAC("Error writing byte-to-byte mapping to ecmdBuffer\n");
                break;
            }

            //Copy the data for nibbleSwap
            DQ_TRAC("Writing nibbleSwap data to ecmdBuffer\n");
            l_startBit += (BYTE_CODE_LENGTH * BYTE_LENGTH);
            l_rc = insertEncodedData (o_encodedData, l_nibbleSwap,
                            NIBBLE_SWAP_LENGTH,l_startBit);
            if (l_rc)
            {
                DQ_TRAC("Error writing nibbleSwap data to ecmdBuffer\n");
                break;
            }

            //Nibble Permutations - setup
            std::vector<uint8_t>::iterator l_itBegin = i_data.begin();
            std::vector<uint8_t>::iterator l_itEnd = l_itBegin +
                (l_grpSize/2);

            int l_numNibbles = ((i_data.size()/l_grpSize) - 1)*2;
            l_startBit += NIBBLE_SWAP_LENGTH*BYTE_LENGTH;

            //Add 0 padding - to round up the nibble perms to next byte
            DQ_TRAC("Writing the 0 padding\n");
            uint32_t l_temp = 0;
            l_rc = o_encodedData.insertFromRight(l_temp,l_startBit,
                        SIX_BIT_ZERO_PADDING);
            if (l_rc)
            {
                DQ_TRAC("Error writing 6-bit 0 padding to ecmdDataBuffer\n");
                break;
            }
            l_startBit += SIX_BIT_ZERO_PADDING;

            DQ_TRAC("Starting nibble permutations\n");
            for(int i = 0; i < l_numNibbles; i++)
            {
                //Find the permutation of the nibble
                uint32_t l_nibblePerm = permutation(l_itBegin, l_itEnd);
                //Store it in the encode data buffer
                l_rc = o_encodedData.insertFromRight(l_nibblePerm,
                                l_startBit,NIBBLE_PERM_LENGTH);
                if (l_rc)
                {
                    DQ_TRAC("Error writing nibblePerm data to ecmdBuffer\n",
                            i);
                    break;
                }
                l_startBit += NIBBLE_PERM_LENGTH;

                //Setup iterators for the next iteration
                l_itBegin  += (l_grpSize/2);
                l_itEnd    += (l_grpSize/2);
            }

            if (l_rc)
            {
                break;
            }
        }
        else if (i_arrayType == DQS)
        {
            l_grpSize = DQS_GROUP_SIZE;

            o_encodedData.setByteLength(DQS_CODE_LENGTH);
            uint32_t l_nibbleSwap = nibble_swap(i_data, l_grpSize);
            l_rc = insertEncodedData (o_encodedData, l_nibbleSwap,
                        NIBBLE_SWAP_LENGTH,0);
            if (l_rc)
            {
                DQ_TRAC("Error writing DQS data to ecmdDataBuffer\n");
                break;
            }
        }
        else
        {
            l_rc = INVALID_ARRAY_TYPE;
            DQ_TRAC("Data type does not match DQ or DQS\n");
            break;
        }
    } while (0);

    DQ_TRAC("Exiting encodeDQ\n");
    return l_rc;
}
