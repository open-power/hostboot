/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/exttools/attroverride/attrTextToBinaryBlob.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 * @Description - This file performs the operation of converting a text file
 *                containing various attributes into their binary
 *                representations and outputing that data into a .bin file. The
 *                program uses a lot of the functionality/logic present in
 *                /hostboot/src/usr/hwpf/plat/fapiPlatAttrOverrideSync in order
 *                to parse the input attribute text file into corresponding
 *                data. This tool takes in an attribute override text file
 *                as input and outputs an ECC protected binary blob containing
 *                the data for the given input attribute overrides.
 *
 *                output file name: attrOverride.bin
 */
//******************************************************************************
// Includes
//******************************************************************************

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <endian.h>
#include <unistd.h>
#include <hwpf/fapi/fapiTarget.H>
#include <attributeenums.H>
#include <pnor/ecc.H>

#include "attrTextToBinaryBlob.H"



AttributeTank::AttributeHeader::AttributeHeader() :
    iv_attrId(0), iv_targetType(0), iv_pos(0), iv_unitPos(0), iv_flags(0),
    iv_node(0), iv_valSize(0)
{
}



namespace AttrOverrideSyncConstants
{
// Constants used for processing all attribute related text files
const size_t MIN_ATTRIBUTE_SIZE = 32; //Every attribute has AT LEAST 32 bytes
const size_t ATTRIBUTE_HEADER_SIZE = 16;
//******************************************************************************
// Constants used for processing FAPI Attribute Text files
// See the header file for the format
//******************************************************************************
const char * const ATTR_FILE_ATTR_START_STR = "ATTR_";
const char * const ATTR_FILE_TARGET_HEADER_STR = "target";
const char * const ATTR_FILE_TARGET_EXT_HEADER_STR = "target = k0";
const char * const ATTR_FILE_TARGET_EXT_FOOTER_STR = ":s0:";
const char * const ATTR_CONST = "CONST";
const char * const TARGET_NODE_HEADER_STR = ":n";
const char * const TARGET_POS_HEADER_STR = ":p";
const char * const TARGET_UNIT_POS_HEADER_STR = ":c";
const char * const TARGET_NODE_ALL_STR = "all";
const char * const TARGET_POS_ALL_STR = "all";


// Used to translate target strings in FAPI Attribute Info files to the value
// in a FAPI or TARG Layer AttributeTanks
const struct TargStrToType
{
    const char * iv_pString;
    uint32_t iv_fapiType;
    uint32_t iv_targType;
} TARG_STR_TO_TYPE [] = {
    {"p8.ex",           fapi::TARGET_TYPE_EX_CHIPLET,   TARGETING::TYPE_EX},
    {"centaur.mba",     fapi::TARGET_TYPE_MBA_CHIPLET,  TARGETING::TYPE_MBA},
    {"p8.mcs",          fapi::TARGET_TYPE_MCS_CHIPLET,  TARGETING::TYPE_MCS},
    {"p8.xbus",         fapi::TARGET_TYPE_XBUS_ENDPOINT,TARGETING::TYPE_XBUS},
    {"p8.abus",         fapi::TARGET_TYPE_ABUS_ENDPOINT,TARGETING::TYPE_ABUS},
    {"centaur",         fapi::TARGET_TYPE_MEMBUF_CHIP,  TARGETING::TYPE_MEMBUF},
    {"p8",              fapi::TARGET_TYPE_PROC_CHIP,    TARGETING::TYPE_PROC},
    {"dimm",            fapi::TARGET_TYPE_DIMM,         TARGETING::TYPE_DIMM}
};

bool operator==(const TargStrToType& i, const std::string& v)
{
    return 0 == strcmp(v.c_str(), i.iv_pString);
}

const char * const ATTR_INFO_FILE_UINT8_STR = "u8";
const char * const ATTR_INFO_FILE_UINT16_STR = "u16";
const char * const ATTR_INFO_FILE_UINT32_STR = "u32";
const char * const ATTR_INFO_FILE_UINT64_STR = "u64";

}

template <typename T>
int compareAttribute(const T& l, const T& r)
{
    return strcmp(l.iv_name, r.iv_name);
}

template <typename T> bool operator<(const T&, const T&);

template <>
bool operator< <AttributeData>(const AttributeData& l, const AttributeData& r)
{
    return compareAttribute(l, r) < 0;
}

template <>
bool operator< <AttributeEnum>(const AttributeEnum& l, const AttributeEnum& r)
{
    return compareAttribute(l, r) < 0;
}

template <typename T>
const T* findAttribute(const T* array,
                       size_t arraySize,
                       const char* attrName)
{
    T constant; constant.iv_name = attrName;

    const T* element =
        std::lower_bound(&array[0], &array[arraySize], constant);

    if ((&array[arraySize] == element) ||
        (0 != compareAttribute(*element, constant)))
    {
        return NULL;
    }

    return element;
}

//global to allow debug logs
bool g_showDebugLogs = false;

using namespace AttrOverrideSyncConstants;


//******************************************************************************
bool AttrTextToBinaryBlob::writeDataToBuffer(
                            AttributeTank::AttributeHeader & i_attrData,
                            AttributeTank::TankLayer i_tankLayer,
                            uint8_t * i_pVal,
                            FILE * io_attrFile,
                            uint8_t *& io_buffer,
                            size_t & io_totalSize )
{
    bool l_err = false;
    FILE * l_data;
    uint64_t l_size;
    int l_success;
    uint32_t * l_bytes;
    uint32_t l_padding = 0x00000000;
    uint32_t l_tankLayer;
    uint32_t l_valSize = i_attrData.iv_valSize;
    size_t l_index;
    size_t l_attributeSize;


    //First update index to copy into buffer
    l_index = io_totalSize;
    //Now, update the total size of the blob
    l_attributeSize = (MIN_ATTRIBUTE_SIZE + l_valSize);
    io_totalSize += l_attributeSize;

    //update the size of our buffer
    io_buffer =(uint8_t *)realloc(io_buffer, io_totalSize);


    // Add tank layer to blob
    l_tankLayer = htonl(static_cast<uint32_t>(i_tankLayer));
    memcpy(&io_buffer[l_index], &l_tankLayer, sizeof(uint32_t));
    l_index += sizeof(uint32_t);

    //add 4 bytes of padding
    memcpy(&io_buffer[l_index], &l_padding, sizeof(uint32_t));
    l_index += sizeof(uint32_t);

    //First need to find out the size of the attribute's data.
    l_size = sizeof(i_attrData) + i_attrData.iv_valSize;

    //convert size to big endian
    l_size = htobe64(l_size);

    //write size to buffer
    memcpy(&io_buffer[l_index], &l_size, sizeof(uint64_t));
    l_index += sizeof(uint64_t);


    //Flatten AttributeHeader into stream of bytes
    flattenAttributeHeader(i_attrData, l_bytes);

    //Write the AttributeHeader data into the blob
    memcpy(&io_buffer[l_index], l_bytes, ATTRIBUTE_HEADER_SIZE);
    l_index += ATTRIBUTE_HEADER_SIZE;

    //Write the value of the attribute into the blob.

    memcpy(&io_buffer[l_index], i_pVal, l_valSize);
    l_index += l_valSize;


    return l_err;
}

//******************************************************************************
void AttrTextToBinaryBlob::flattenAttributeHeader(
                                  AttributeTank::AttributeHeader & i_attrHeader,
                                  uint32_t *& o_data)
{

    i_attrHeader.iv_attrId = htonl(i_attrHeader.iv_attrId);
    i_attrHeader.iv_targetType = htonl(i_attrHeader.iv_targetType);
    i_attrHeader.iv_pos = htons(i_attrHeader.iv_pos);
    i_attrHeader.iv_valSize = htonl(i_attrHeader.iv_valSize);

    o_data = reinterpret_cast<uint32_t *>(&i_attrHeader);

    return;
}




//******************************************************************************
bool AttrTextToBinaryBlob::attrFileIsAttrLine(
    const std::string & i_line,
    std::string & o_attrString)
{
    /*
     * e.g. "target = k0:n0:s0:centaur.mba:pall:call" - false
     *      "ATTR_MSS_DIMM_MFG_ID_CODE[0][0] u32[2][2] 0x12345678" - true
     */
    bool l_isAttrLine = false;

    if (0 == i_line.find(ATTR_FILE_ATTR_START_STR))
    {
        // The attribute ID string terminates with either '[' or ' '
        size_t l_pos = i_line.find_first_of("[ ");

        if (l_pos != std::string::npos)
        {
            o_attrString = i_line.substr(0, l_pos);
            l_isAttrLine = true;
        }
    }

    return l_isAttrLine;
}



//******************************************************************************
bool AttrTextToBinaryBlob::attrFileIsTargLine(
    const std::string & i_line)
{
    /*
     * e.g. "target = k0:n0:s0:centaur.mba:pall:call" - true
     *      "ATTR_MSS_DIMM_MFG_ID_CODE[0][0] u32[2][2] 0x12345678" - false
     */
    return 0 == i_line.find(ATTR_FILE_TARGET_HEADER_STR);
}


//******************************************************************************
bool AttrTextToBinaryBlob::attrFileAttrLineToFields(
    const std::string & i_line,
    std::string & o_attrString,
    size_t (& o_dims)[ATTR_MAX_DIMS],
    std::string & o_valStr,
    bool & o_const)
{
    /*
     * e.g. "ATTR_MSS_DIMM_MFG_ID_CODE[0][1] u32[2][2] 0x12345678"
     * - o_attrString = "ATTR_MSS_DIMM_MFG_ID_CODE"
     * - o_dims = {0, 1, 0, 0}
     * - o_valStr = "0x12345678"
     * - o_const = false
     */
    bool l_success = false;
    bool l_break = false;
    o_const = false;
    size_t l_pos1 = 0;
    size_t l_pos2 = 0;

    for (size_t i = 0; i < ATTR_MAX_DIMS; i++)
    {
        o_dims[i] = 0;
    }

    // Copy input string into a local string and strip of any newline
    std::string l_line(i_line);


    if (l_line[l_line.size() - 1] == '\n')
    {
        l_line = l_line.substr(0, l_line.size() - 1);
    }

    do
    {
        // Find the first field: attribute string
        l_pos2 = l_line.find_first_of(" \t");

        if (l_pos2 == std::string::npos)
        {
            printf(
            "attrFileAttrLineToFields:"
            " Could not find end of attr str in '%s'\n",
                l_line.c_str());
            break;
        }

        // Found the attribute-string
        //


        std::string l_attrString = l_line.substr(0, l_pos2);


        // Find if the attribute string contains array dimensions
        size_t l_pos = l_attrString.find('[');
        o_attrString = l_attrString.substr(0, l_pos);

        size_t l_dim = 0;

        while ((l_pos != std::string::npos) && (l_dim < ATTR_MAX_DIMS))
        {
            l_attrString = l_attrString.substr(l_pos + 1);
            o_dims[l_dim++] = strtoul(l_attrString.c_str(), NULL, 0);

            if(l_dim > ATTR_MAX_DIMS)
            {
                printf("MAX_DIMS exceeded! Exiting... "
                        "attrTextToBinaryBlob::attrFileAttrLineToFields");
                l_break = true;
                break;
            }

            l_pos = l_attrString.find('[');
        }

        if( l_break )
        {
            break;
        }

        // Find the second field: type (optional) or value
        l_pos1 = l_line.find_first_not_of(" \t", l_pos2);

        if (l_pos1 == std::string::npos)
        {
            printf(
                "attrFileAttrLineToFields:"
                " Could not find start of second field in '%s'\n",
                l_line.c_str());
            break;
        }

        l_pos2 = l_line.find_first_of(" \t", l_pos1);

        if (l_pos2 == std::string::npos)
        {
            // The second and last string must be the value string
            o_valStr = l_line.substr(l_pos1);
            l_success = true;
            break;
        }

        // Found the second field
        o_valStr = l_line.substr(l_pos1, l_pos2 - l_pos1);

        // If the second field is the optional and unused type field then
        // the next field is the val string
        if ( (o_valStr.find(ATTR_INFO_FILE_UINT8_STR) != std::string::npos) ||
             (o_valStr.find(ATTR_INFO_FILE_UINT16_STR) != std::string::npos) ||
             (o_valStr.find(ATTR_INFO_FILE_UINT32_STR) != std::string::npos) ||
             (o_valStr.find(ATTR_INFO_FILE_UINT64_STR) != std::string::npos) )
        {
            l_pos1 = l_line.find_first_not_of(" \t", l_pos2);

            if (l_pos1 == std::string::npos)
            {
                printf(
                    "attrFileAttrLineToFields:"
                    " Could not find start of val field in '%s'\n",
                    l_line.c_str());
                break;
            }

            l_pos2 = l_line.find_first_of(" \t", l_pos1);

            if (l_pos2 == std::string::npos)
            {
                // The third and last string must be the value string
                o_valStr = l_line.substr(l_pos1);
                l_success = true;
            }
            else
            {
                o_valStr = l_line.substr(l_pos1, l_pos2 - l_pos1);
                l_success = true;
            }
        }
        else
        {
            l_success = true;
        }

        if (l_pos2 != std::string::npos)
        {
            // Find the final const field if it exists
            l_pos1 = l_line.find_first_not_of(" \t", l_pos2);

            if (l_pos1 == std::string::npos)
            {
                break;
            }

            std::string l_constStr = l_line.substr(l_pos1);

            if (0 == l_constStr.find(ATTR_CONST))
            {
                o_const = true;
            }
        }

    } while (0);
    return l_success;
}



//******************************************************************************
void AttrTextToBinaryBlob::attrFileTargetLineToData(
    const std::string & i_line,
    const AttributeTank::TankLayer i_tankLayer,
    uint32_t & o_targetType,
    uint16_t & o_targetPos,
    uint8_t & o_targetUnitPos,
    uint8_t & o_targetNode)
{
    /*
     * e.g. "target = k0:n0:s0:centaur.mba:p02:c1"
     * - o_targetType = 0x00000001
     * - o_targetPos = 2
     * - o_targetUnitPos = 1
     */

    // If the target string is not decoded into a non-system target and
    // explicit positions are not found then the caller will get these defaults
    bool l_sysTarget = true;
    if (i_tankLayer == AttributeTank::TANK_LAYER_FAPI)
    {
        o_targetType = fapi::TARGET_TYPE_SYSTEM;
    }
    else
    {
        o_targetType = TARGETING::TYPE_SYS;
    }

    o_targetNode = AttributeTank:: ATTR_NODE_NA;
    o_targetPos = AttributeTank:: ATTR_POS_NA;
    o_targetUnitPos = AttributeTank::ATTR_UNIT_POS_NA;

    // Find the node, target type, pos and unit-pos
    if (0 == i_line.find(ATTR_FILE_TARGET_EXT_HEADER_STR))
    {
        // Create a local string and remove the target header
        std::string l_line =
            i_line.substr(strlen(ATTR_FILE_TARGET_EXT_HEADER_STR));

        // Figure out the node number
        if (0 == l_line.find(TARGET_NODE_HEADER_STR))
        {
            l_line = l_line.substr(strlen(TARGET_NODE_HEADER_STR));

            if (0 == l_line.find(TARGET_NODE_ALL_STR))
            {
                l_line = l_line.substr(strlen(TARGET_NODE_ALL_STR));
            }
            else
            {
                o_targetNode = strtoul(l_line.c_str(), NULL, 10);

                size_t l_pos = l_line.find(':');

                if (l_pos != std::string::npos)
                {
                    l_line = l_line.substr(l_pos);
                }
                else
                {
                    l_line.clear();
                }
            }
        }

        if (0 == l_line.find(ATTR_FILE_TARGET_EXT_FOOTER_STR))
        {
            // Remove the target footer
            l_line = l_line.substr(strlen(ATTR_FILE_TARGET_EXT_FOOTER_STR));
        }

        // Figure out the target type
        const TargStrToType* last =
            &TARG_STR_TO_TYPE[sizeof(TARG_STR_TO_TYPE)/sizeof(TargStrToType)];

        const TargStrToType* item =
            std::find(&TARG_STR_TO_TYPE[0], last, l_line);

        if (item != last)
        {
            o_targetType = (i_tankLayer == AttributeTank::TANK_LAYER_TARG ?
                            item->iv_targType : item->iv_fapiType);
            l_line = l_line.substr(strlen(item->iv_pString));
            l_sysTarget = false;
        }

        // For a non-system target, figure out the position and unit position
        if (l_sysTarget == false)
        {
            // Figure out the target's position
            if (0 == l_line.find(TARGET_POS_HEADER_STR))
            {
                l_line = l_line.substr(strlen(TARGET_POS_HEADER_STR));

                if (0 == l_line.find(TARGET_POS_ALL_STR))
                {
                    l_line = l_line.substr(strlen(TARGET_POS_ALL_STR));
                }
                else
                {
                    o_targetPos = strtoul(l_line.c_str(), NULL, 10);

                    size_t l_pos = l_line.find(':');

                    if (l_pos != std::string::npos)
                    {
                        l_line = l_line.substr(l_pos);
                    }
                    else
                    {
                        l_line.clear();
                    }
                }
            }

            // Figure out the target's unit position
            if (0 == l_line.find(TARGET_UNIT_POS_HEADER_STR))
            {
                l_line = l_line.substr(strlen(TARGET_UNIT_POS_HEADER_STR));

                if (0 == l_line.find(TARGET_POS_ALL_STR))
                {
                    l_line = l_line.substr(strlen(TARGET_POS_ALL_STR));
                }
                else
                {
                    o_targetUnitPos = strtoul(l_line.c_str(), NULL, 10);
                }
            }
        }
    }

    // System targets must have an NA node
    if (l_sysTarget)
    {
        o_targetNode = AttributeTank::ATTR_NODE_NA;
    }

}

//******************************************************************************
bool AttrTextToBinaryBlob::attrFileAttrLinesToData(
    std::vector<std::string> & i_lines,
    uint32_t & o_attrId,
    uint32_t & o_valSizeBytes,
    uint8_t * & o_pVal,
    bool & o_const,
    AttributeTank::TankLayer & o_tankLayer)
{
    bool l_pErr = false;
    size_t l_numElements = 0;
    // Data for the attribute
    uint32_t l_attrElemSizeBytes = 0;
    size_t d[ATTR_MAX_DIMS] = {0}; // dimensions of the attribute

    // Data for this line. Note that this function expects all lines to be for
    // the same attr (in the case of an array attribute)
    std::string l_attrString;
    size_t td[ATTR_MAX_DIMS] = {0}; // dimensions of this line's element
    std::string l_valString;
    uint64_t l_attrVal = 0;

    std::vector<std::string>::const_iterator l_itr;

    // Iterate over each line
    for (l_itr = i_lines.begin(); l_itr != i_lines.end(); ++l_itr)
    {
        // Split the attribute line into fields
        bool l_success = attrFileAttrLineToFields(*l_itr, l_attrString, td,
            l_valString, o_const);


        if (!l_success)
        {
            printf(
                "attrFileAttrLinesToData: "
                "Error. Could not break into fields (%s)\n",
                (*l_itr).c_str());
            break;
        }

        if (o_pVal == NULL)
        {

            l_success = getAttrDataFromMap(l_attrString.c_str(),
                               o_attrId,
                               l_attrElemSizeBytes,
                               d,
                               o_tankLayer);
            if(!l_success)
            {
                printf("There was a problem getting data for %s\n",
                        l_attrString.c_str());
                break;
            }

            o_valSizeBytes = l_attrElemSizeBytes * d[0] * d[1] * d[2] * d[3];
            o_pVal = new uint8_t[o_valSizeBytes];
        }

        // Check that the attribute isn't overflowing an array


        for(size_t i = 0; i < ATTR_MAX_DIMS; i++)
        {
            if(td[i] >= d[i])
            {
                printf("attrFileAttrLinesToData: Error. Array Overflow (%s)\n",
                         (*l_itr).c_str());
                break;
            }
        }

        if ((l_valString[0] == '0') && (l_valString[1] == 'x'))
        {
            // Value string is a value
            l_attrVal = strtoull(l_valString.c_str(), NULL, 0);
        }
        else
        {
            // Value string is an enumerator, it is decoded using <attr>_<enum>
            l_valString = l_attrString + "_" + l_valString;


            l_success = getAttrEnumDataFromMap(l_valString.c_str(), l_attrVal);

            if(!l_success)
            {
                printf("An error occurred when retrieving the enum value for"
                       " %s\n", l_valString.c_str());
                break;
            }

        }

        // Write the element to the correct place in the buffer
        size_t l_size = sizeof(d)/sizeof(size_t);
        size_t l_elem = 0;
        for(size_t idx = 0; idx < l_size; idx++)
        {
            l_elem *= d[idx];
            l_elem += td[idx];
        }


        if (l_attrElemSizeBytes == sizeof(uint8_t))
        {
            o_pVal[l_elem] = l_attrVal;
            l_numElements++;
        }
        else if (l_attrElemSizeBytes == sizeof(uint16_t))
        {
            uint16_t * l_pVal = reinterpret_cast<uint16_t *>(o_pVal);
            l_pVal[l_elem] = htobe16(l_attrVal);
            l_numElements++;
        }
        else if (l_attrElemSizeBytes == sizeof(uint32_t))
        {
            uint32_t * l_pVal = reinterpret_cast<uint32_t *>(o_pVal);
            l_pVal[l_elem] = htobe32(l_attrVal);
            l_numElements++;
        }
        else
        {
            uint64_t * l_pVal = reinterpret_cast<uint64_t *>(o_pVal);
            l_pVal[l_elem] = htobe64(l_attrVal);
            l_numElements++;
        }

    }
    return l_pErr;
}

//******************************************************************************
void AttrTextToBinaryBlob::padToNextPage( uint8_t *& io_buffer,
                                                    size_t & io_bufSize )
{

    size_t l_pageSize = 0x1000;
    size_t l_overUnder = io_bufSize%l_pageSize;
    size_t l_paddingSize = l_pageSize - l_overUnder;
    size_t l_startPoint = io_bufSize;

    io_bufSize += l_paddingSize;
    io_buffer = (uint8_t *)realloc(io_buffer, io_bufSize);
    memset(&io_buffer[l_startPoint], 0xff, l_paddingSize);
    return;
}



//******************************************************************************
bool AttrTextToBinaryBlob::attrTextToBinaryBlob( std::ifstream& i_file,
                                                 bool i_injectECC )
{
    bool l_pErr = false;

    // Attribute Data
    uint32_t l_attrId = 0;
    uint32_t l_targetType = 0;
    uint16_t l_pos = AttributeTank::ATTR_POS_NA;
    uint8_t l_unitPos = AttributeTank::ATTR_UNIT_POS_NA;
    uint8_t l_node = AttributeTank::ATTR_NODE_NA;
    uint32_t l_valSize = 0;
    uint8_t * l_pVal = NULL;
    bool l_const = false;
    size_t l_fwriteSuccess;
    AttributeTank::TankLayer l_tankLayer =
                                  AttributeTank::TANK_LAYER_NONE;
    std::string l_line;
    std::string l_targetLine;
    std::string l_attrString;
    std::string l_thisAttrString;
    std::vector<std::string> l_attrLines;
    AttributeTank::AttributeHeader l_attrData;

    uint8_t * l_buffer = NULL;
    uint8_t * l_writeBuffer;
    size_t l_totalSize = 0;
    size_t l_newSize;
    size_t l_whitespacePos;


    //File name subject to change on request
    const char * l_blobName = "attrOverride.bin";
    FILE * l_attrBlob;
    l_attrBlob = fopen(l_blobName, "wb");

    // Iterate over all lines in the file.
    do
    {
        // Iterate over all attribute lines for the same attribute. For
        // multi-dimensional attributes, there is a line for each element
        l_attrString.clear();
        l_attrLines.clear();

        do
        {
            // Read next line.
            if (!l_line.length())
            {
                std::getline(i_file, l_line);
                if (!l_line.length())
                {
                    break;
                }
            }

            //Remove any leading whitespace
            l_whitespacePos = l_line.find_first_not_of(" \t");
            l_line = l_line.substr(l_whitespacePos, l_line.size());

            // Process the line.  Could be:
            //    * Target line.
            //    * Attribute line.
            //    * other line.
            if (attrFileIsTargLine(l_line))
            {
                if (l_attrString.empty())
                {
                    // Not currently processing attribute lines, save the target
                    // line, it is for following attribute lines
                    l_targetLine = l_line;
                    l_line.clear();
                }
                else
                {
                    // Currently processing attribute lines. Break out of the
                    // loop to process the current set and look at this target
                    // line in the next iteration
                    break;
                }
            }
            else if (attrFileIsAttrLine(l_line, l_thisAttrString))
            {
                // Found an Attribute line.
                if (l_attrString.empty())
                {
                    // First attribute of the set
                    l_attrString = l_thisAttrString;
                }
                else if (l_attrString != l_thisAttrString)
                {
                    // This attribute is different from the current set. Break
                    // out of the loop to process the current set and look at
                    // this new attribute in the next iteration
                    break;
                }

                // Add the attribute line to the vector and get the next line
                l_attrLines.push_back(l_line);
                l_line.clear();
            }
            else
            {
                // Not a target or attribute line, get the next line
                // If CLEAR line, just get next line since we arent
                // directly dealing with any tanks.
                l_line.clear();
            }
        }
        while(1);

        if (l_attrLines.size())
        {
            // Get the attribute data for this attribute
            l_pErr = attrFileAttrLinesToData(l_attrLines, l_attrId, l_valSize,
                l_pVal, l_const, l_tankLayer);

            // Get the Target Data for this attribute
            attrFileTargetLineToData(l_targetLine, l_tankLayer, l_targetType,
                l_pos, l_unitPos, l_node);

            if (l_pErr)
            {
                printf("attrTextToBinaryBlob:"
                       " Error getting attribute data\n");
                break;
            }

            // Figure out the attribute flags
            uint8_t l_flags = 0;
            if (l_const)
            {
                l_flags = AttributeTank::ATTR_FLAG_CONST;
            }


            //Add data to AttributeHeader
            l_attrData.iv_attrId = l_attrId;
            l_attrData.iv_targetType = l_targetType;
            l_attrData.iv_pos = l_pos;
            l_attrData.iv_unitPos = l_unitPos;
            l_attrData.iv_node = l_node;
            l_attrData.iv_flags = l_flags;
            l_attrData.iv_valSize = l_valSize;


            if( g_showDebugLogs )
            {
                //Print information
                printf("attrTextToBinaryBlob: ATTR override "
                         "Id: 0x%08x, TargType: 0x%08x, Pos: 0x%04x, "
                         "UPos: 0x%02x\n",
                         l_attrId, l_targetType, l_pos, l_unitPos);
                printf("attrTextToBinaryBlob: ATTR override "
                         "Node: 0x%02x, Flags: 0x%02x, Size: 0x%08x",
                         l_node, l_flags, l_valSize);
                printf(" Val: 0x");
                //print the value
                for(int i = 0; i < l_valSize; i++)
                {
                    printf("%x", l_pVal[i]);
                }
                printf("\n\n");
            }

            //write attribute data into a buffer
            l_pErr = writeDataToBuffer( l_attrData,
                                      l_tankLayer,
                                      l_pVal,
                                      l_attrBlob,
                                      l_buffer,
                                      l_totalSize );

            if( l_pErr )
            {
                printf("An error occured in writeDataToBuffer\n");
            }
            delete[] l_pVal;
            l_pVal = NULL;
        }
    } while (!i_file.eof());

    //The Attribute text file has been processed and written into a buffer

    //pad the buffer up to the next multiple of 0x1000 (page size).
    padToNextPage( l_buffer,
                   l_totalSize );

    //inject ECC protection bytes if desired
    if( i_injectECC )
    {
        l_newSize = (l_totalSize/8)*9;
        l_writeBuffer = (uint8_t *) malloc((l_newSize));
        PNOR::ECC::injectECC( l_buffer, l_totalSize, l_writeBuffer );
    }
    else
    {
        l_newSize = l_totalSize;
        l_writeBuffer = l_buffer;
    }

    //write the overrides to the file
    l_fwriteSuccess = fwrite(l_writeBuffer, 1, l_newSize, l_attrBlob);
    if( l_fwriteSuccess != l_newSize )
    {
        printf("There was an error writing to the file!\n");
    }

    if (!l_pErr)
    {
        // Successfully processed the attribute file, close it
        i_file.close();

        // Close attribute blob file
        int l_fclose = fclose(l_attrBlob);

        if(l_fclose != 0 )
        {
            printf("attrTextToBinaryBlob: Error closing blob file\n");
        }

        // free allocated memory
        free(l_buffer);

        //free the ECC buffer if we used it.
        if( i_injectECC )
        {
            free(l_writeBuffer);
        }

    }

    return l_pErr;
}





//******************************************************************************
bool AttrTextToBinaryBlob::getAttrDataFromMap(const char * i_attrString,
                         uint32_t & o_attrId,
                         uint32_t & o_attrElemSizeBytes,
                         size_t (& o_dims)[4],
                         AttributeTank::TankLayer & o_tankLayer)
{
    bool l_success = true;
    do
    {
        const AttributeData* currentAttr = NULL;
        // Check for attribute inside attribute data maps. Must search
        // the TARG map first because for an attribute that exists in both FAPI
        // and TARG maps (i.e. a FAPI Attribute that is implemented by a TARG
        // attribute), an override should be stored in the TARG override tank.
        currentAttr = findAttribute(g_TargAttrs,
                                    sizeof(g_TargAttrs)/sizeof(AttributeData),
                                    i_attrString);
        o_tankLayer = AttributeTank::TANK_LAYER_TARG;

        if (NULL == currentAttr)
        {
            currentAttr =
                      findAttribute(g_FapiAttrs,
                                    sizeof(g_FapiAttrs)/sizeof(AttributeData),
                                    i_attrString);
            o_tankLayer = AttributeTank::TANK_LAYER_FAPI;
        }

        if (NULL == currentAttr)
        {
            printf("Attribute data not present for the attribute %s!\n",
                    i_attrString);
            l_success = false;
            break;
        }

        o_attrId = currentAttr->iv_attrId;
        o_attrElemSizeBytes = currentAttr->iv_attrElemSizeBytes;
        for(size_t i = 0; i < sizeof(o_dims)/sizeof(size_t); ++i)
        {
            o_dims[i] = currentAttr->iv_dims[i];
        }

    }while( 0 );

    return l_success;
}

bool AttrTextToBinaryBlob::getAttrEnumDataFromMap(const char * i_attrString,
                                                  uint64_t & o_enumVal)
{
    bool l_success = true;

    do
    {
        const AttributeEnum* currentAttr = NULL;
        currentAttr = findAttribute(g_FapiEnums,
                                    sizeof(g_FapiEnums)/sizeof(AttributeEnum),
                                    i_attrString);

        if (NULL == currentAttr)
        {
            printf("Could not find the ENUM value for %s\n", i_attrString);
            l_success = false;
            break;
        }

        o_enumVal = currentAttr->iv_value;

    }while( 0 );
    return l_success;
}



int main(int argc, char *argv[])
{
    std::ifstream l_attributeFile;
    bool err = false;
    bool l_injectECC = true;
    char * l_option;
    const char * l_attributeString;

    int opt;
    while((opt = getopt(argc, argv, "dfht")) != -1)
    {
        switch (opt)
        {
            case 'd':
                g_showDebugLogs = true;
                break;
            case 'f':
                l_injectECC = false;
                break;

            case 't':
                l_injectECC = true;
                break;

            case 'h':
                printf("%s [options] <file>:\n", argv[0]);
                printf("\nExpected args:\n\t Attribute text file of the "
                        "following format: \n\n\t\t # This is a comment\n\n"
                        "\t\tCLEAR\n\n"
                        "\t\ttarget = k0:n0:s0:\n"
                        "\t\tATTR_SCRATCH_UINT8_1 0x12\n"
                        "\t\tATTR_SCRATCH_UINT32_1 0x12345678\n"
                        "\t\tATTR_SCRATCH_UINT64_1 0x8000000000000001 CONST\n\n"
                        "\t\ttarget = k0:n0:s0:centaur:p06\n"
                        "\t\tATTR_MSS_CACHE_ENABLE 0x0 CONST\n\n"
                        "\t\ttarget = k0:n0:s0:centaur.mba:p06:c1\n"
                        "\t\tATTR_MSS_FREQ 0x00000640 CONST\n"
                        "\t\tATTR_MSS_VOLT 0x00000546 CONST\n"
                        "\t\tATTR_EFF_CEN_DRV_IMP_CNTL[0] OHM15 CONST\n"
                        "\t\tATTR_EFF_CEN_DRV_IMP_CNTL[1] OHM15 CONST\n\n"
                        "\t\ttarget = k0:n0:s0:centaur.mba:pall:call\n"
                        "\t\tATTR_MSS_DIMM_MFG_ID_CODE[0][0] 0x12345678\n"
                        "\t\tATTR_MSS_DIMM_MFG_ID_CODE[0][1] 0x12345678\n"
                        "\t\tATTR_MSS_DIMM_MFG_ID_CODE[1][0] 0x12345678\n"
                        "\t\tATTR_MSS_DIMM_MFG_ID_CODE[1][1] 0x12345678\n\n");

                printf("\tOne of the following options:\n\n"
                       "\t\t'-d' - allow debug logs.\n"
                       "\t\t'-h' - display help text.\n"
                       "\t\t'-f' - prevent ECC bytes from being inserted.\n"
                       "\t\t'-t' - allow ECC bytes to be inserted.\n"
                       "\t\tno option - same as 't' option.\n\n");

                return 0;
        }
    }

    if (optind == argc)
    {
        printf("Attribute text file not given! Aborting...\n");
        return -1;
    }

    do{

        l_attributeString = argv[optind];
        l_attributeFile.open(l_attributeString);

        err = AttrTextToBinaryBlob::attrTextToBinaryBlob( l_attributeFile,
                                                          l_injectECC );

        if( err )
        {
            printf("An Error occurred!\n");
        }

        if( g_showDebugLogs )
        {
            printf("Attribute overrides successfully written to "
                   "attrOverride.bin\n");
        }
    }while( 0 );

    return (err ? -1 : 0);
}

