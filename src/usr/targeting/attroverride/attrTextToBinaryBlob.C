/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attroverride/attrTextToBinaryBlob.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#include <target_types.H>
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
const char * const ATTR_CAGE_NUMBER = "k0";
const char * const ATTR_FILE_TARGET_EXT_FOOTER_STR = ":s0:";
const char * const ATTR_CONST = "CONST";
const char * const TARGET_NODE_HEADER_STR = ":n";
const char * const TARGET_POS_HEADER_STR = ":p";
const char * const TARGET_UNIT_POS_HEADER_STR = ":c";
const char * const TARGET_NODE_ALL_STR = "all";
const char * const TARGET_POS_ALL_STR = "all";


// Used to translate target strings in FAPI Attribute Info files to the value
// in a FAPI or TARG Layer AttributeTanks
struct TargStrToType
{
    const char * iv_pString;
    uint32_t iv_fapiType;
    uint32_t iv_targType;
};


TargStrToType CHIP_TYPE_TARG_STR_TO_TYPE [] =
{
    {"p9n"        , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"p9c"        , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"pu"         , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"centaur"    , fapi2::TARGET_TYPE_MEMBUF_CHIP , TARGETING::TYPE_MEMBUF},
    {"dimm"       , fapi2::TARGET_TYPE_DIMM        , TARGETING::TYPE_DIMM},
    {"p8"         , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"p9"         , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"LAST"       , 0                              , 0}

};

TargStrToType CHIP_UNIT_TYPE_TARG_STR_TO_TYPE [] =
{
    {"c"        , fapi2::TARGET_TYPE_CORE       , TARGETING::TYPE_CORE},
    {"ex"       , fapi2::TARGET_TYPE_EX         , TARGETING::TYPE_EX},
    {"eq"       , fapi2::TARGET_TYPE_EQ         , TARGETING::TYPE_EQ},
    {"mcs"      , fapi2::TARGET_TYPE_MCS        , TARGETING::TYPE_MCS},
    {"mca"      , fapi2::TARGET_TYPE_MCA        , TARGETING::TYPE_MCA},
    {"mcbist"   , fapi2::TARGET_TYPE_MCBIST     , TARGETING::TYPE_MCBIST},
    {"xbus"     , fapi2::TARGET_TYPE_XBUS       , TARGETING::TYPE_XBUS},
    {"abus"     , fapi2::TARGET_TYPE_ABUS       , TARGETING::TYPE_ABUS},
    {"obus"     , fapi2::TARGET_TYPE_OBUS       , TARGETING::TYPE_OBUS},
    {"obrick"   , fapi2::TARGET_TYPE_OBUS_BRICK , TARGETING::TYPE_OBUS_BRICK},
    {"sbe"      , fapi2::TARGET_TYPE_SBE        , TARGETING::TYPE_SBE},
    {"ppe"      , fapi2::TARGET_TYPE_PPE        , TARGETING::TYPE_PPE},
    {"perv"     , fapi2::TARGET_TYPE_PERV       , TARGETING::TYPE_PERV},
    {"pec"      , fapi2::TARGET_TYPE_PEC        , TARGETING::TYPE_PEC},
    {"phb"      , fapi2::TARGET_TYPE_PHB        , TARGETING::TYPE_PHB},
    {"capp"     , fapi2::TARGET_TYPE_CAPP       , TARGETING::TYPE_CAPP},
    {"mba"      , fapi2::TARGET_TYPE_MBA        , TARGETING::TYPE_MBA},
    {"dmi"      , fapi2::TARGET_TYPE_DMI        , TARGETING::TYPE_DMI},
    {"mi"       , fapi2::TARGET_TYPE_MI         , TARGETING::TYPE_MI},
    {"LAST"     , 0                             , 0}
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

const AttributeData * findAttributeForId( const AttributeData * array,
                                          size_t arraySize,
                                          uint32_t attrId )
{
    const AttributeData * pOutElement = NULL;
    for // loop thru the attribute data table
      ( int i = 0;
        i < arraySize;
        i++ )
    {
        if // element contains input Id
          ( array[i].iv_attrId == attrId )
        {
            // element found
            pOutElement = &array[i];
            break;
        }
    }

    return pOutElement;
}

//global to allow debug logs
bool g_showDebugLogs = false;

//global to indicate if tool is generated permanent overrides
bool g_permOverride = false;

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
void AttrTextToBinaryBlob::updateLabels(
                                    std::vector<target_label> & io_labels,
                                    const target_label & i_label_override)
{
    for (auto & l_label : io_labels)
    {
        if (i_label_override.node != AttributeTank::ATTR_NODE_NA)
        {
            l_label.node = i_label_override.node;
        }
        if (i_label_override.targetPos != AttributeTank::ATTR_POS_NA)
        {
            l_label.targetPos = i_label_override.targetPos;
        }
        if (i_label_override.unitPos != AttributeTank::ATTR_UNIT_POS_NA)
        {
            l_label.unitPos = i_label_override.unitPos;
        }
    }
}

//******************************************************************************
bool AttrTextToBinaryBlob::attrFileTargetLineToData(
    const std::string & i_line,
    const AttributeTank::TankLayer i_tankLayer,
    uint32_t & o_targetType,
    std::vector<target_label> & o_targetLabels)
{
    /*
     * e.g. "target = k0:n0:s0:centaur.mba:p02:c1"
     * - o_targetType = 0x00000001
     * - 1 target specified:
     *     node: 0, targetPos: 2, unitPos: 1
     *
     *
     * e.g. "target = k0:n0:s0:centaur.mba:p0,3:c1"
     * - o_targetType = 0x00000001
     * - 2 targets specified:
     *     node: 0, targetPos: 0, unitPos: 1
     *     node: 0, targetPos: 3, unitPos: 1
     */

    // create a generic label
    target_label l_label;

    // always start with no targets
    o_targetLabels.clear();

    // find positions
    size_t l_comma_pos;
    size_t l_colon_pos;

    bool l_err = false;
    // If the target string is not decoded into a non-system target and
    // explicit positions are not found then the caller will get these defaults
    bool l_sysTarget = true;

    do
    {
        if (i_tankLayer == AttributeTank::TANK_LAYER_FAPI)
        {
            o_targetType = fapi2::TARGET_TYPE_SYSTEM;
        }
        else
        {
            o_targetType = TARGETING::TYPE_SYS;
        }

        // Find the node, target type, pos and unit-pos
        int l_cageIndex = i_line.find(ATTR_CAGE_NUMBER);
        if(l_cageIndex != std::string::npos )
        {
            // Create a local string and remove the target header
            std::string l_line =
                i_line.substr(l_cageIndex + strlen(ATTR_CAGE_NUMBER));

            // Figure out the node number
            if (0 == l_line.find(TARGET_NODE_HEADER_STR))
            {
                l_line = l_line.substr(strlen(TARGET_NODE_HEADER_STR));

                if (0 == l_line.find(TARGET_NODE_ALL_STR))
                {
                    // add a new target label node number
                    o_targetLabels.push_back(l_label);
                    l_line = l_line.substr(strlen(TARGET_NODE_ALL_STR));
                }
                else
                {
                    l_colon_pos = l_line.find(':');
                    l_comma_pos = l_line.find(',');

                    // make sure comma comes before ending colon
                    while ((l_comma_pos != std::string::npos) &&
                           (l_comma_pos < l_colon_pos))
                    {
                        // grab number (stops at first non-numerical character)
                        l_label.node = strtoul(l_line.c_str(), NULL, 10);

                        // add a new target label node number
                        o_targetLabels.push_back(l_label);

                        // increment line past the comma
                        l_line = l_line.substr(l_comma_pos+1);

                        // search for next potential comma
                        l_comma_pos = l_line.find(',');
                    }
                    // grab number (stops at first non-numerical character)
                    l_label.node = strtoul(l_line.c_str(), NULL, 10);

                    // add the last target label node number
                    o_targetLabels.push_back(l_label);

                    // turn off overriding node
                    l_label.node = AttributeTank::ATTR_NODE_NA;

                    // line may have changed size so refind the ending colon
                    // for the node part
                    l_colon_pos = l_line.find(':');
                    if (l_colon_pos != std::string::npos)
                    {
                        l_line = l_line.substr(l_colon_pos);
                    }
                    else
                    {
                        l_line.clear();
                    }
                }
            } // end figure out target node

            if (0 == l_line.find(ATTR_FILE_TARGET_EXT_FOOTER_STR))
            {
                // Remove the target footer
                l_line = l_line.substr(strlen(ATTR_FILE_TARGET_EXT_FOOTER_STR));
            }

            // Figure out the target type
            // Remove the end of the target string (position and unitpos) before
            // using the line to search for target types
            l_colon_pos = l_line.find(":");

            std::string l_targetType;
            std::string l_origTargetType;

            TargStrToType* chip_type_first = NULL;
            TargStrToType* chip_type_last = NULL;


            TargStrToType* item = NULL;
            if( l_colon_pos != std::string::npos)
            {
                // save the full target type name
                l_origTargetType = l_line.substr(0, l_colon_pos);

                // put it into an alterable target type
                l_targetType = l_origTargetType;

                auto l_dotIndex = l_targetType.find(".");

                if(l_dotIndex != std::string::npos)
                {
                    // "." found, meaning both chip type and chip unit are specified
                    // Isolate the chip unit type
                    l_targetType = l_targetType.substr(l_dotIndex + 1);

                    // Save range to search in correct target type array
                    chip_type_first = &CHIP_UNIT_TYPE_TARG_STR_TO_TYPE[0];
                    chip_type_last = &CHIP_UNIT_TYPE_TARG_STR_TO_TYPE
                    [(sizeof(CHIP_UNIT_TYPE_TARG_STR_TO_TYPE)/sizeof(TargStrToType))-1];
                }
                else
                {
                    // Only chip type specified
                    // Save range to search in correct target type array
                    chip_type_first = &CHIP_TYPE_TARG_STR_TO_TYPE[0];
                    chip_type_last = &CHIP_TYPE_TARG_STR_TO_TYPE
                    [(sizeof(CHIP_TYPE_TARG_STR_TO_TYPE)/sizeof(TargStrToType))-1];

                }

                //Search for target type
                item = std::find( chip_type_first,
                                  chip_type_last, l_targetType.c_str());

                if( item != chip_type_last )
                {
                    // Target type found
                    // choose fapi2 or targeting type
                    o_targetType = ( i_tankLayer == AttributeTank::TANK_LAYER_TARG ?
                                     item->iv_targType : item->iv_fapiType);

                    // skip past the full target type name
                    l_line = l_line.substr(l_origTargetType.length());
                    l_sysTarget = false;
                }
                else
                {
                    printf("Error: Could not find matching target type for given target string(%s)\n",
                            l_targetType.c_str());
                    l_err = true;
                    break;
                }
            }
            else
            {
                // no target type specified, so default to sys target
                l_sysTarget = true;
            }


            // For a non-system target,
            // figure out the position and unit position
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
                        bool firstPos = true;
                        l_colon_pos = l_line.find(':');
                        l_comma_pos = l_line.find(',');
                        std::vector<target_label> origCopy;

                        while ((l_comma_pos != std::string::npos) &&
                               (l_comma_pos < l_colon_pos))
                        {
                            // grab targetPos number
                            // (stops at first non-numerical character)
                            l_label.targetPos =
                                strtoul(l_line.c_str(), NULL, 10);

                            if (firstPos)
                            {
                                // save a copy of current targets before
                                // adding targetPos
                                origCopy = o_targetLabels;

                                // update targetPos of current targets
                                updateLabels(o_targetLabels, l_label);
                                firstPos = false;
                            }
                            else
                            {
                                // update targetPos of original targets
                                updateLabels(origCopy, l_label);

                                // add these new targetPos targets to
                                // current target list
                                o_targetLabels.insert( o_targetLabels.end(),
                                                       origCopy.begin(),
                                                       origCopy.end() );
                            }

                            // skip past the comma
                            l_line = l_line.substr(l_comma_pos+1);

                            // now look for next potential comma
                            l_comma_pos = l_line.find(',');
                        }

                        // grab number (stops at first non-numerical character)
                        l_label.targetPos = strtoul(l_line.c_str(), NULL, 10);
                        if (firstPos)
                        {
                            // no comma found, so just update
                            // current target list
                            updateLabels(o_targetLabels, l_label);
                        }
                        else
                        {
                            // last targetPos in comma list
                            // update targetPos of original targets
                            updateLabels(origCopy, l_label);

                            // add these new targetPos targets to
                            // the current target list
                            o_targetLabels.insert(o_targetLabels.end(),
                                                  origCopy.begin(),
                                                  origCopy.end());
                        }
                        l_label.targetPos = AttributeTank::ATTR_POS_NA;

                        // line may have changed size so refind the ending colon
                        // for targetPos part
                        l_colon_pos = l_line.find(':');
                        if (l_colon_pos != std::string::npos)
                        {
                            l_line = l_line.substr(l_colon_pos);
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
                        bool firstPos = true;
                        l_comma_pos = l_line.find(',');
                        std::vector<target_label> origCopy;

                        while (l_comma_pos != std::string::npos)
                        {
                            // grab unitPos number
                            // (stops at first non-numerical character)
                            l_label.unitPos = strtoul(l_line.c_str(), NULL, 10);
                            if (firstPos)
                            {
                                // save a copy of current targets
                                // before adding unitPos
                                origCopy = o_targetLabels;

                                // update unitPos of current targets
                                updateLabels(o_targetLabels, l_label);
                                firstPos = false;
                            }
                            else
                            {
                                // update unitPos of original targets
                                updateLabels(origCopy, l_label);

                                // add these new unitPos targets to
                                // the current target list
                                o_targetLabels.insert( o_targetLabels.end(),
                                                       origCopy.begin(),
                                                       origCopy.end() );
                            }
                            // skip past the comma
                            l_line = l_line.substr(l_comma_pos+1);

                            // now look for next potential comma
                            l_comma_pos = l_line.find(',');
                        }

                        // grab number (stops at first non-numerical character)
                        l_label.unitPos = strtoul(l_line.c_str(), NULL, 10);
                        if (firstPos)
                        {
                            // no comma found, so just update
                            // current target list
                            updateLabels(o_targetLabels, l_label);
                        }
                        else
                        {
                            // last unitPos in comma list
                            // update unitPos of original targets
                            updateLabels(origCopy, l_label);

                            // add these new unitPos targets to
                            // the current target list
                            o_targetLabels.insert(o_targetLabels.end(),
                                                  origCopy.begin(),
                                                  origCopy.end());
                        }
                    }
                }
            }
        } // else, the "k0" string was not found. Process as system target

        // System targets must have an NA node
        if (l_sysTarget)
        {
            if (o_targetLabels.size() == 0)
            {
                o_targetLabels.push_back(l_label);
            }
        }

    } while( 0 );

    return l_err;
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

        // Expect 0x<> for unsigned and -<> for signed attribute
        if ((l_valString[0] == '0') && (l_valString[1] == 'x') ||
           (l_valString[0] == '-'))
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
bool AttrTextToBinaryBlob::validateTargLine( const std::string & i_line )
{
    // input line :
    //  - has previously had leading white space stripped
    //  - begins with string "target"
    std::string l_line = i_line;

    bool isValidLine = true;

    // determine target type:
    //  - system
    //     target  <blank>
    //     target = k0:n0:s0 <blank>
    //     target = k0:n0:s0: <blank>
    //
    //  - chip
    //     system || chip string
    //
    //        note : system string is of form kx:ny:sz
    //        note : x may be 0-9
    //        note : y may be :
    //                - single digit 0-9
    //                - comma separated list of digits 0-9
    //                   -- 2 or more items in list
    //                   -- no ordering dependencies
    //                   e.g. 0,4
    //                   e.g. 5,3,9
    //                - all
    //        note : z = 0
    //

    // remove "target" label from line
    l_line = l_line.substr(6, l_line.size());

    // strip leading white space
    int l_nextTextPos = l_line.find_first_not_of(" \t");
    l_line = l_line.substr(l_nextTextPos, l_line.size());

    do
    {
        if // all white space
          ( l_nextTextPos == std::string::npos )
        {
            // target is system target, encoded correctly
            break;
        }

        else if // missing "=" but contains other garbage
          ( (l_line.substr(0, 1)) != "=" )
        {
            // bad encoding
            isValidLine = false;
            printf("validateTargLine : Error : Missing = \n" );
            break;
        }

        else
        {
            // strip the "="
            l_line = l_line.substr(1, l_line.size());
            l_nextTextPos = l_line.find_first_not_of(" \t");

            if // no parms follow "="
              (l_nextTextPos == std::string::npos)
            {
                // bad encoding
                isValidLine = false;
                printf("validateTargLine : Error : "
                        "Missing Header String \n" );
                break;
            }
            else
            {
                // strip proceeding white space
                l_line = l_line.substr(l_nextTextPos, l_line.size());
            }
        }

        // at this point the "target =" and
        //  any preceeding white space has been stripped
        // the header encoding needs to be validated for a System Target
        TargetTypeRc tgtTypeRc = validateSysSubstr( l_line );

        if // System target was found
          ( tgtTypeRc == TargetTypeRcSystem )
        {
            // target is system target, encoded correctly
            break;
        }
        else if // encoding error
          ( tgtTypeRc == TargetTypeRcError )
        {
            // bad encoding (err msg already printed)
            isValidLine = false;
            break;
        }
        else
        {
            // (chip target - keep going)
        }

        //------------------------------
        // check for terms without values
        //------------------------------
        int curColonPosn = l_line.find_first_of(":", 0);

        for ( int nextColonPosn = 0;
                curColonPosn != std::string::npos;
                curColonPosn = nextColonPosn )
        {
            nextColonPosn = l_line.find_first_of(":", curColonPosn+1);

            if // no colon found
              ( nextColonPosn == std::string::npos)
            {
                if // last term was missing a value
                ( (l_line.size() - curColonPosn) < 3 )
                {
                    // bad encoding
                    isValidLine = false;
                    printf("validateTargLine : Error : "
                            "Parameter is missing a Value \n" );
                    break;
                }
                else
                {
                    // (all done checking)
                }
            }

            else if // term is too small to hold a value
              ( (nextColonPosn - curColonPosn) < 3  )
            {
                // bad encoding
                isValidLine = false;
                printf("validateTargLine : Error : "
                        "Parameter is missing a Value \n" );
                break;
            }
            else if // blank follows the colon
              (l_line.substr(nextColonPosn+1,1) == " ")
            {
                // bad encoding
                isValidLine = false;
                printf("validateTargLine : Error : "
                        "Blank Parm follows : \n" );
                break;
            }
            else
            {
                // keep looping
            }
        } // end loop thru string

        if // validation failed
        ( isValidLine == false )
        {
            // all done
            break;
        }
        else
        {
            // (keep checking)
        }

        //------------------------------
        // end check for terms without values
        //------------------------------


        //------------------------------
        // check chip targets for nonsense parms
        //------------------------------

        for ( int i = 0;
              i < ( sizeof(CHIP_TYPE_TARG_STR_TO_TYPE) /
                    sizeof(CHIP_TYPE_TARG_STR_TO_TYPE[0]) );
              i++ )
        {
            TargStrToType * pEntry = &CHIP_TYPE_TARG_STR_TO_TYPE[i];

            if // entry is a processor or memory buffer
              ( (pEntry->iv_targType == TARGETING::TYPE_PROC) ||
                (pEntry->iv_targType == TARGETING::TYPE_MEMBUF) )
            {
                // prepend ":" to chip string to create search string
                std::string l_searchString = ":";
                l_searchString = l_searchString + pEntry->iv_pString;

                int chipPosn = l_line.find( l_searchString );

                // jump over the string
                int skipChipPosn;
                if  ( chipPosn == std::string::npos )
                {
                  skipChipPosn = l_line.size();
                }
                else
                {
                  skipChipPosn = chipPosn + l_searchString.size();
                }

                if // (chip string is in the target string) AND
                   // (is not at the end of the target string) AND
                   // (is not followed by ".")
                  ( (chipPosn != std::string::npos) &&
                    (skipChipPosn < l_line.size()) &&
                    ((l_line.substr(skipChipPosn, 1)) != "." ) )
                {
                    std::string l_trlParmLine =
                            l_line.substr(skipChipPosn, l_line.size());

                    if // ":c" parm exists
                      ( l_trlParmLine.find( ":c" ) != std::string::npos )
                    {
                        // bad encoding
                        isValidLine = false;
                        printf("validateTargLine : Error : "
                                "Nonsense parm :c in processor or "
                                "memory buffer target \n" );
                        break;
                    }
                    else
                    {
                        // keep looking
                    }
                } // end chip string found
                else
                {
                    // (keep looking)
                }
            } // end processor or memory buffer
            else
            {
                // skip entry
            }
        } // end walk thru chip targets

        // this next clause isn't really needed right now
        // but is added for safety in case other checking is
        // added below at a later time.

        if // validation failed
          ( isValidLine == false )
        {
            // all done
            break;
        }
        else
        {
            // (keep checking)
        }

        //------------------------------
        // end check chip targets for nonsense parms
        //------------------------------


    } while ( 0 );

    return isValidLine;
}

//******************************************************************************
AttrTextToBinaryBlob::TargetTypeRc
   AttrTextToBinaryBlob::validateSysSubstr( const std::string & i_line )
{
    // input line :
    //  - "target =" and any preceeding white space has been stripped
    std::string l_line = i_line;

    AttrTextToBinaryBlob::TargetTypeRc rc;

    // determine target type:
    //  - system
    //     k0:n0:s0 <blank>
    //     k0:n0:s0: <blank>
    //
    //  - chip
    //     system || chip string
    //
    //        note : system string is of form kx:ny:sz
    //        note : x may be 0-9
    //        note : y may be :
    //                - single digit 0-9
    //                - comma separated list of digits 0-9
    //                   -- 2 or more items in list
    //                   -- no ordering dependencies
    //                   e.g. 0,4
    //                   e.g. 5,3,9
    //                - all
    //        note : z = 0
    //

    do
    {
        int l_lineSize = l_line.size();
        size_t kPosn = (l_line.substr(0, 1) == "k") ?
                0 : l_line.find( ":k", 0);
        size_t nPosn = (l_line.substr(0, 1) == "n") ?
                0 : l_line.find( ":n", 0);
        size_t sPosn = (l_line.substr(0, 1) == "s") ?
                0 : l_line.find( ":s", 0);

        if // system string is too short
          ( l_lineSize < 8 )
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "System string is too short \n" );
            break;
        }

        else if // missing k, n, or s term
          ( (kPosn == std::string::npos) ||
            (nPosn == std::string::npos) ||
            (sPosn == std::string::npos) )        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "System Substring is missing k, n or s \n" );
            break;
        }

        else if // system string does not begin with k
          ( (l_line.substr(0, 1) != "k") )
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "System Substring does not begin with"
                    "k \n" );
            break;
        }

        else if // terms are not in k/n/s order
        ( (kPosn >= nPosn) ||
          (kPosn >= sPosn) ||
          (nPosn >= sPosn) )
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "k / n / s terms are out of order \n" );
            break;

        }

        else if // k, n, s parm values are not 0
          ( (l_line.substr(1, 2) != "0:") ||
            (l_line.substr(4, 2) != "0:") ||
            (l_line.substr(7, 1) != "0") )
        {
            if // string is long enough to hold chip parms
              ( l_lineSize > 9 )
            {
              // (target is a potential chip target)
            }
            else
            {
                // bad encoding
                rc = TargetTypeRcError;
                printf("validateSysSubstr : Error : "
                        "System Target String k, n, s must be 0 \n" );
                break;
            }
        }

        else if // k0, n0, s0 and no more
          ( l_lineSize == 8 )
        {
            // target is system target, encoded correctly
            rc = TargetTypeRcSystem;
            break;
        }

        else if // k0, n0, s0, : and no more
          ( (l_lineSize == 9) &&
            (l_line.substr(8, 1) == ":" ) )
        {
            // target is system target, encoded correctly
            rc = TargetTypeRcSystem;
            break;
        }

        else
        {
            // (potential chip target)
        }


        //  Only Potential Chip Targets get to this point
        //        note : Kx/Ny/Sz terms may be in any order
        //        note : x may be 0-9
        //        note : y may be 0-9; 0-8, 1-9;  or all
        //        note : z = 0

        size_t kValStartPosn = (kPosn == 0) ? 1 : kPosn+2;
        size_t kValEndPosn = l_line.find( ":", kValStartPosn ) - 1;

        size_t nValStartPosn = (nPosn == 0) ? 1 : nPosn+2;
        size_t nValEndPosn = l_line.find( ":", nValStartPosn ) - 1;

        size_t sValStartPosn = (sPosn == 0) ? 1 : sPosn+2;
        size_t sValEndPosn = l_line.find( ":", sValStartPosn ) - 1;

        std::string kValString =
                i_line.substr( kValStartPosn, (kValEndPosn-kValStartPosn)+1 );

        std::string nValString =
                i_line.substr( nValStartPosn, (nValEndPosn-nValStartPosn)+1 );

        std::string sValString =
                i_line.substr( sValStartPosn, (sValEndPosn-sValStartPosn)+1 );

        if // s parameter value is not valid
          ( (sValStartPosn != sValEndPosn) ||
            (sValString != "0") )
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "Invalid s value. s must be 0 \n" );
            break;
        }

        else if // k parameter value is not valid
          ( (kValStartPosn != kValEndPosn) ||
            (kValString < "0") ||
            (kValString > "9")         )
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "Invalid k value. k must be 0 - 9\n" );
            break;
        }

        else if // n parameter value = all
          (nValString == "all")
        {
            // valid chip target encoding
            rc = TargetTypeRcChip;
            break;
        }

        else if // n has a single character parameter value
          ( nValStartPosn == nValEndPosn )
        {
            if // parameter value is between 0 and 9
              ( (nValString >= "0") &&
                (nValString <= "9") )
            {
                // valid chip target encoding
                rc = TargetTypeRcChip;
                break;
            }
            else
            {
                // bad encoding
                rc = TargetTypeRcError;
                printf("validateSysSubstr : Error : "
                        "Invalid n value. n must be 0 - 9\n" );
                break;
            }
        }

        else if // no comma separated n values
          (nValString.find(",", 0) == std::string::npos)
        {
            // bad encoding
            rc = TargetTypeRcError;
            printf("validateSysSubstr : Error : "
                    "Invalid n value. n must be 0 - 9 or all\n" );
            break;
        }

        else
        {
            // assume a valid chip encoding
            rc = TargetTypeRcChip;

            // (check for comma separated list)
            size_t nValCurPosn = nValStartPosn;
            size_t nValNextPosn = nValCurPosn;

            for // loop thru the potential comma separated list
              ( int i = nValStartPosn;
                i <= nValEndPosn;
                )
            {
                size_t commaPosn = nValString.find(",", i);
                if // comma not found
                  ( commaPosn != std::string::npos)
                {
                    // this is the last term
                    i = nValEndPosn + 1;
                    commaPosn =  nValEndPosn + 1;
                }
                else
                {
                    // end of intermediary term
                    i = commaPosn + 1;
                }

                if // parameter value is not valid
                  ( (nValString.substr(nValCurPosn, commaPosn) < "0") ||
                    (nValString.substr(nValCurPosn, commaPosn) > "9") )
                {
                    // bad encoding
                    rc = TargetTypeRcError;
                    printf("validateSysSubstr : Error : "
                            "Invalid n value. n list value must be 0 - 9\n" );
                    break;
                }
                else
                {
                    // keep walking the list
                    nValCurPosn = i;
                }
            } // end loop thru comma separated list
        } // end check n is comma separated list

    } while ( 0 );

    return rc;
}

//******************************************************************************
bool AttrTextToBinaryBlob::validateBinaryXlate( const uint8_t * i_buffer,
                                                size_t  i_bufSize )
{
    bool isValid = true;

    // strip out and display binary term by term
    int hdrLen = 16;
    int termHdrLen = sizeof(AttributeTank::AttributeHeader);
    int valueLen = 0;

    int maxOffset = i_bufSize - 1;

    printf("\nvalidateBinaryXlate: Echo Output\n" );

    for // walk thru the bfr
      ( int curOffset = 0;
        curOffset <= maxOffset;
        curOffset+=(hdrLen + termHdrLen + valueLen) )
    {
        // hdr contents - Big Endian encoded
        //  00-03 :  Tank
        //  04-07 :  pad
        //  08-0F : length of the proceeding attribute term
        const uint8_t * pHdr = i_buffer + curOffset;
        uint32_t tank = be32toh( *((const uint32_t *)(pHdr)) );
        uint32_t pad = be32toh( *((const uint32_t *)(pHdr+4)) );
        uint64_t termLen = be64toh( *((const uint64_t *)(pHdr+8)) );

        // term contents - Big Endian encoded Attribute Header
        //  00-03 : attribute ID
        const AttributeTank::AttributeHeader * pTerm =
                (const AttributeTank::AttributeHeader *)(pHdr + hdrLen);

        uint32_t attrId = be32toh( pTerm->iv_attrId );
        uint32_t targetType = be32toh( pTerm->iv_targetType );
        uint16_t pos = be16toh( pTerm->iv_pos );
        uint8_t unitPos = pTerm->iv_unitPos;

        const uint8_t * pNodeFlags = (&(pTerm->iv_unitPos)) + 1;

        uint8_t node = (*pNodeFlags) >> 4;  // isolate hi nibble
        uint8_t flags = (*pNodeFlags) & 0x0F;  // isolate lo nibble

        uint32_t valSize = be32toh( pTerm->iv_valSize );
        valueLen = valSize;

        const AttributeData * pAttrData =
            findAttributeForId( g_TargAttrs,
                                sizeof(g_TargAttrs)/sizeof(AttributeData),
                                attrId);

        if (NULL == pAttrData)
        {
            pAttrData =
                findAttributeForId( g_FapiAttrs,
                                    sizeof(g_FapiAttrs)/sizeof(AttributeData),
                                    attrId );

            if // no match for attribute ID
              ( pAttrData == NULL )
            {
                // something went wrong
                printf("validateBinaryXlate: unknown Attribute ID - %.8X\n",
                        attrId);
                isValid = false;
                break;
            }
        }

        std::string l_line = pAttrData->iv_name;

        printf("\nvalidateBinaryXlate: Attribute Term =  %s\n",
                l_line.c_str() );

        printf("validateBinaryXlate: Term Hdr: "
                "Tank = %.8X  Pad = %.8X  Attribute Length = %.16lX\n",
                tank, pad, termLen );

        printf("validateBinaryXlate: Attribute Hdr: "
                "ID = %.8X  Target Type = %.8X  Positon = %.4X  "
                "Unit Position = %.2X  node = %.1X  flags = %.1X  "
                "Parm Length = %.8X\n",
                attrId, targetType, pos, unitPos, node, flags, valSize);

        if // parm value exists
          ( valSize > 0 )
        {
            // value contents - Big Endian encoded
            const uint8_t * pValue = ((const uint8_t *)pTerm) + termHdrLen;

            if // 1 byte parm
              (valSize == 1)
            {
                uint8_t value8 = *pValue;
                printf("validateBinaryXlate: Parm Value: %.2X\n", value8 );
            }

            else if // 2 byte parm
              (valSize == 2)
            {
                uint16_t value16 = be16toh( *((const uint16_t *)pValue) );
                printf("validateBinaryXlate: Parm Value: %.4X\n", value16 );
            }

            else if // 4 byte parm
              (valSize == 4)
            {
                uint32_t value32 = be32toh( *((const uint32_t *)pValue) );
                printf("validateBinaryXlate: Parm Value: %.8X\n", value32 );
            }

            else if // 8 byte parm
              (valSize == 8)
            {
                uint64_t value64 = be64toh( *((const uint64_t *)pValue) );
                printf("validateBinaryXlate: Parm Value: %.16lX\n", value64 );
            }
            else
            {
                printf("validateBinaryXlate: WARNING : Parm to large to format\n" );
            }
        } // end parm value
    } // end walk thru output buffer

    return( isValid );
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
    std::vector<target_label> l_targetLabels;

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
    uint8_t * l_writeBuffer = NULL;
    size_t l_totalSize = 0;
    size_t l_newSize;
    size_t l_whitespacePos;


    //File name subject to change on request
    const char * l_blobName = "attrOverride.bin";
    FILE * l_attrBlob;
    l_attrBlob = fopen(l_blobName, "wb");

    printf("attrTextToBinaryBlob:"
           " Reading Attribute Override File\n");

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

                //Remove any leading whitespace
                l_whitespacePos = l_line.find_first_not_of(" \t");
                l_line = l_line.substr(l_whitespacePos, l_line.size());

                printf("attrTextToBinaryBlob: Echo Input - %s\n",
                        l_line.c_str() );
            }

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

            if (l_pErr)
            {
                printf("attrTextToBinaryBlob:"
                       " Error getting attribute data\n");
                break;
            }

            // verify target line is encoded correctly
            bool isTgtLineValid = validateTargLine( l_targetLine );

            if // target line is good
              (isTgtLineValid)
            {
                // (keep going)
            }
            else
            {
                // all done
                l_pErr = true;
                printf("attrTextToBinaryBlob:"
                       " Target Line is incorrectly coded\n");
                break;
            }

            // Get the Target Data for this attribute
            l_pErr = attrFileTargetLineToData(l_targetLine,
                                              l_tankLayer,
                                              l_targetType,
                                              l_targetLabels);

            if (l_pErr)
            {
                printf("attrTextToBinaryBlob:"
                       " Error parsing target string\n");
                break;
            }

            // Figure out the attribute flags
            uint8_t l_flags = 0;
            if (l_const)
            {
                l_flags = AttributeTank::ATTR_FLAG_CONST;
            }

            if // no output data was generated
              ( l_targetLabels.size() == 0 )
            {
                // Silent Error
                l_pErr = true;
                printf("attrTextToBinaryBlob:"
                       " Silent Error, no output generated\n");
                break;
            }

            for (const auto & l_label : l_targetLabels)
            {
                l_pos = l_label.targetPos;
                l_unitPos = l_label.unitPos;
                l_node = l_label.node;

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
                    printf("attrTextToBinaryBlob:"
                           " An error occured in writeDataToBuffer\n");
                    break;
                }
            }  // End of target labels

            if // no errors occurred during parsing
              (l_pErr == false)
            {
                if // parm value buffer exists
                ( l_pVal != NULL )
                {
                    // delete it
                    delete[] l_pVal;
                    l_pVal = NULL;
                }
                else
                {
                    // (no buffer to delete)
                }
            }
            else
            {
                // (all done)
                break;
            }
        } // end attribute line found
    } while (!i_file.eof());

    if // no errors occurred during parsing
      (l_pErr == false )
    {
        //The Attribute text file has been processed and written into a buffer

        // validate the text to binary translation
        bool isBinaryValid = validateBinaryXlate( l_buffer,
                                                  l_totalSize);

        if // binary is good
        (isBinaryValid)
        {
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
        } // end valid binary
        else
        {
            // error - terminate
            l_pErr = true;
            printf("attrTextToBinaryBlob:"
                   " Error in encoded binary\n");
        }
    } // end no parsing errors
    else
    {
    } // end parsing errors

    // deallocate temp bfrs as needed
    if ( l_pVal != NULL )
    {
        delete[] l_pVal;
        l_pVal = NULL;
    }
    else
    {}

    if ( l_buffer != NULL )
    {
        free(l_buffer);
    }
    else
    {}

    if ( (l_writeBuffer != NULL) &&
         (l_writeBuffer != l_buffer) )
    {
        free(l_writeBuffer);
    }
    else
    {}

    // Close attribute blob file
    int l_fclose = fclose(l_attrBlob);

    if(l_fclose != 0 )
    {
        printf("attrTextToBinaryBlob: Error closing blob file\n");
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

        // If generating a permanent override, set tank layer accordingly
        if (g_permOverride)
        {
            if (o_tankLayer == AttributeTank::TANK_LAYER_FAPI)
            {
                printf("Cannot create a permanent override for FAPI attributes - attr = %s\n",
                    i_attrString);
                l_success = false;
                break;
            }
            else
            {
                o_tankLayer = AttributeTank::TANK_LAYER_PERM;
            }
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
    bool l_injectECC = false;
    char * l_option;
    const char * l_attributeString;

    int opt;
    while((opt = getopt(argc, argv, "dfhtp")) != -1)
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
            case 'p':
                g_permOverride = true;
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
                        "\t\tATTR_MSS_VOLT_VDDR_MILLIVOLTS 0x00000546 CONST\n"
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
                       "\t\t'-p' - permanent override. [FAPI attributes not allowed]\n"
                       "\t\tno option - same as '-f' option.\n\n");

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

        l_attributeFile.close();

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

