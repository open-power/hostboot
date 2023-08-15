/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrTextOverride.C $                        */
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
 * @Description - This file parses the ATTR_TMP attribute override section as
 *                ascii text data and sets the attributes in the corresponding
 *                attribute tank.
 */

//---------
// Includes
//---------
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <endian.h>
#include <target_types.H>
#include <attributeenums.H>
#include <pnor/ecc.H>
#include <pnor/pnorif.H>

#include <console/consoleif.H>
#include <errl/errlmanager.H>
#include <util/utilfile.H>
#include <targeting/attrTextOverride.H>
#include <targeting/targplatreasoncodes.H>

#include <targAttrOverrideData.H>
#include <fapi2AttrOverrideData.H>
#include <fapi2AttrOverrideEnums.H>


namespace AttrOverrideSyncConstants
{

/**
 * Structure used to translate target strings in FAPI Attribute Info
 * files to the value in FAPI or TARG Layer AttributeTanks
 */
struct TargStrToType
{
    const char * pString;
    uint64_t fapiType;
    uint64_t targType;
};


TargStrToType CHIP_TYPE_TARG_STR_TO_TYPE [] =
{
    {"pu"         , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"dimm"       , fapi2::TARGET_TYPE_DIMM        , TARGETING::TYPE_DIMM},
    {"p10"        , fapi2::TARGET_TYPE_PROC_CHIP   , TARGETING::TYPE_PROC},
    {"ocmb"       , fapi2::TARGET_TYPE_OCMB_CHIP   , TARGETING::TYPE_OCMB_CHIP},
    {"tpm"        , 0                              , TARGETING::TYPE_TPM},
    {"LAST"       , 0                              , 0}
};


TargStrToType CHIP_UNIT_TYPE_TARG_STR_TO_TYPE [] =
{
    {"c"        , fapi2::TARGET_TYPE_CORE       , TARGETING::TYPE_CORE},
    {"eq"       , fapi2::TARGET_TYPE_EQ         , TARGETING::TYPE_EQ},
    {"perv"     , fapi2::TARGET_TYPE_PERV       , TARGETING::TYPE_PERV},
    {"pec"      , fapi2::TARGET_TYPE_PEC        , TARGETING::TYPE_PEC},
    {"phb"      , fapi2::TARGET_TYPE_PHB        , TARGETING::TYPE_PHB},
    {"mi"       , fapi2::TARGET_TYPE_MI         , TARGETING::TYPE_MI},
    {"omi"      , fapi2::TARGET_TYPE_OMI        , TARGETING::TYPE_OMI},
    {"omic"     , fapi2::TARGET_TYPE_OMIC       , TARGETING::TYPE_OMIC},
    {"mcc"      , fapi2::TARGET_TYPE_MCC        , TARGETING::TYPE_MCC},
    {"mp"       , fapi2::TARGET_TYPE_MEM_PORT   , TARGETING::TYPE_MEM_PORT},
    {"iohs"     , fapi2::TARGET_TYPE_IOHS       , TARGETING::TYPE_IOHS},
    {"iolink"   , fapi2::TARGET_TYPE_IOLINK     , TARGETING::TYPE_SMPGROUP},
    {"mds"      , fapi2::TARGET_TYPE_MDS_CTLR   , TARGETING::TYPE_MDS_CTLR},
    {"fc"       , fapi2::TARGET_TYPE_FC         , TARGETING::TYPE_FC},
    {"nmmu"     , fapi2::TARGET_TYPE_NMMU       , TARGETING::TYPE_NMMU},
    {"pau"      , fapi2::TARGET_TYPE_PAU        , TARGETING::TYPE_PAU},
    {"pauc"     , fapi2::TARGET_TYPE_PAUC       , TARGETING::TYPE_PAUC},
    {"pmic"     , fapi2::TARGET_TYPE_PMIC       , TARGETING::TYPE_PMIC},
    {"LAST"     , 0                             , 0}
};


bool operator==(const TargStrToType& i, const char * v)
{
    return 0 == strcmp(v, i.pString);
}

} // namespace AttrOverrideSyncConstants


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
        return nullptr;
    }

    return element;
}


const AttributeData * findAttributeForId( const AttributeData * array,
                                          size_t arraySize,
                                          uint32_t attrId )
{
    const AttributeData * pOutElement = nullptr;
    for // loop thru the attribute data table
      ( uint32_t i = 0;
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


using namespace AttrOverrideSyncConstants;

namespace TARGETING
{

const bool OVERRIDE_DEBUG_ENABLED = false;
const size_t CONST_INVALID = 0xFFFFFFFF;
const size_t ATTR_MAX_DIMS = 4;
const size_t MAX_TRACE_LENGTH = 1024;
const size_t MAX_OVD_LINE_LENGTH = 256;
const size_t MAX_ATTR_NAME_LENGTH = 100;
const size_t MAX_ATTR_VAL_LENGTH = 32;

// Global trace pointer and trace macro for console traces.
// Avoids creating a trace buffer in each function or passing
// the pointer to each function.
char * g_ovd_trace = nullptr;
#define OVD_TRACE( _fmt_, _args_...) \
   snprintf( g_ovd_trace, MAX_TRACE_LENGTH-1, _fmt_, ##_args_ ); \
   CONSOLE::displayf(CONSOLE::DEFAULT, "TARG", "%s", g_ovd_trace);

/**
 * @brief Check if input char is the new-line character
 *
 * @param[in]  i_char   Input char
 *
 * @return True if input char is new-line, else false
 */
bool isNewLine(char i_char)
{
    return (i_char == '\n');
}


/**
 * @brief Check if input char is the end-of-string character
 *
 * @param[in]  i_char   Input char
 *
 * @return True if input char is end-of-string, else false
 */
bool isEndStr(char i_char)
{
    return (i_char == '\0');
}


/**
 * @brief Check if input char is a tab character
 *
 * @param[in]  i_char   Input char
 *
 * @return True if input char is a tab, else false
 */
bool isTab(char i_char)
{
    return (i_char == '\t');
}


/**
 * @brief Return string pointer to next char that is not white space
 *
 * @param[in]  i_strPtr   Input string pointer
 *
 * @return Pointer to next visible char
 */
char* nextVisibleChar( char* i_strPtr )
{
    while(isspace(*i_strPtr) ||
          isTab(*i_strPtr))
    {
        i_strPtr++;
    }
    return i_strPtr;
}


/**
 * @brief Return string pointer to next white space char
 *
 * @param[in]  i_strPtr   Input string pointer
 *
 * @return Pointer to next whitespace char
 */
char* nextWhiteSpaceChar( char* i_strPtr )
{
    while(isprint(*i_strPtr) &&
          !isspace(*i_strPtr) &&
          !isTab(*i_strPtr))
    {
        i_strPtr++;
    }
    return i_strPtr;
}


/**
 * @brief Remove any spaces or tabs at the end of the input string
 *
 * @param[in]  i_strPtr   Input string pointer
 *
 */
void removeTrailingWhiteSpace( char* i_strPtr )
{
    // The strlen value is the index of the end-of-string char,
    // subtract one to get the last char of the string
    size_t l_strLen = strlen(i_strPtr);

    // Only process for non-zero strlen, if strlen = 0 there is no trailing
    // white space, will also prevent the array index from going negative
    if (l_strLen)
    {
        while ( isspace(i_strPtr[l_strLen-1]) ||
                isTab(i_strPtr[l_strLen-1]) )
        {
            // Make the last char the end-of-string
            // then get the new strlen
            i_strPtr[l_strLen-1] = '\0';
            l_strLen = strlen(i_strPtr);
        }
    }
}


/**
 * @brief Return the starting position of the second string within
 *        the first string
 *        strStrPos("one two three","three") = 8
 *
 * @param[in]  i_strOne   String to be searched
 * @param[out] i_strTwo   String to search for
 *
 * @return Start position or CONST_INVALID if string not found
 */
size_t strStrPos( const char * i_strOne, const char * i_strTwo)
{
    size_t l_pos = CONST_INVALID;

    const char * l_strPtr = strstr(i_strOne, i_strTwo);

    if (l_strPtr)
    {
        l_pos = l_strPtr - i_strOne;
    }

    return l_pos;
}


/**
 * @brief Returns true if an input line defines an attribute
 *
 * @param[in]  i_line       String containing input line
 *
 * @return true if the line is an attribute line
 */
bool isAttrLine( const char * i_line )
{
    //
    // e.g. "target = k0:n0:s0:tpm:p00" - false
    //      "ATTR_FORCE_TPM_NOT_PRESENT 0x1 CONST" - true
    //

    // Check for the start of an attribute line
    return (!strncmp(i_line, "ATTR_", 5));
}


/**
 * @brief Removes the unused type field from attribute line
 *        i.e. u8 or u32[4] or u64[2][2]
 *
 * @param[in]  i_line       String containing input line
 *
 */
void removeUnusedTypeField(char * i_line)
{
    char * l_secondFieldPtr = nullptr;
    char * l_thirdFieldPtr = nullptr;
    size_t l_copyLength = 0;

    // Find the end of the attr name
    l_secondFieldPtr = nextWhiteSpaceChar(i_line);

    // Find ther start of the second field
    l_secondFieldPtr = nextVisibleChar(l_secondFieldPtr);

    // Check for the optional and unused type field
    if ( (strncmp(l_secondFieldPtr,"u8" , 2) == 0) ||
         (strncmp(l_secondFieldPtr,"u16", 3) == 0) ||
         (strncmp(l_secondFieldPtr,"u32", 3) == 0) ||
         (strncmp(l_secondFieldPtr,"u64", 3) == 0) )
    {
        // Find the end of the type field value
        l_thirdFieldPtr = nextWhiteSpaceChar(l_secondFieldPtr);

        // Find the start of the third field
        l_thirdFieldPtr = nextVisibleChar(l_thirdFieldPtr);

        // Copy length is the strlen + 1 for the end string char
        l_copyLength = strlen(l_thirdFieldPtr) + 1;

        // Use memmove to remove the type field from the string
        memmove(l_secondFieldPtr, l_thirdFieldPtr, l_copyLength);
    }
}


/**
 * @brief Gets attribute name from attribute line
 *
 * @param[in]  i_line       String containing input line
 * @param[out] o_attrName   Filled in with the Attribute Name
 *
 * @return Pointer to error else nullptr
 */
errlHndl_t getAttrName( const char * i_line, char * o_attrName)
{
    errlHndl_t l_err = nullptr;

    // The attribute ID string terminates with either '[' or ' '
    // ATTR_EXAMPLE[4]... l_nameLen = 12
    size_t l_nameLen = strcspn(i_line, "[ ");

    // Found [ or space
    // Check the name length, don't want to over-run the name string
    if (l_nameLen+1 > MAX_ATTR_NAME_LENGTH)
    {
        OVD_TRACE("Attribute Override: ***ERROR*** Attribute name exceeds max name length %d: %s", MAX_ATTR_NAME_LENGTH, i_line);
        /*@
         * @errortype
         * @moduleid  TARG_MOD_ATTR_TEXT_OVERRIDE
         * @reasoncode TARG_RC_MAX_ATTR_NAME_LENGTH
         * @userdata1 Current attribute name length
         * @userdata2 Max attribute name length
         * @devdesc   Attribute name exceeds max name length
         * @custdesc  Informational firmware error occurred
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_TEXT_OVERRIDE,
                                TARG_RC_MAX_ATTR_NAME_LENGTH,
                                l_nameLen+1,
                                MAX_ATTR_NAME_LENGTH,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }
    else
    {
        strncpy(o_attrName, i_line, l_nameLen);
        o_attrName[l_nameLen] = '\0';
    }

ERROR_EXIT:
    return l_err;
}


/**
 * @brief Determines if the input line is a target line
 *
 * @param[in] i_line Input line to be analyzed
 *
 * @return true if the line is a target line
 */
bool isTargLine(const char * i_line)
{
    //
    // e.g. "target = k0:n0:s0:tpm:p00" - false
    //      "ATTR_FORCE_TPM_NOT_PRESENT 0x1 CONST" - true
    //
    return (!strncmp(i_line, "target", 6));
}


/**
 * @brief Checks the attribute value's length against the max allowed.
 *        Don't want to overrun any strings.
 *
 * @param[in]  i_length     Size of attribute value string, not including
 *                          null terminator
 *
 * @return errlHndl_t       Error log handle
 */
errlHndl_t checkAttrValueLength(size_t i_length)
{
    errlHndl_t l_err = nullptr;

    // Making the assumption that the length passed in does not include the
    // null terminator so add 1 to allow for it
    if ((i_length+1) > MAX_ATTR_VAL_LENGTH)
    {
        OVD_TRACE("Attribute Override: ***ERROR*** Override value exceeds max value length %d %d", MAX_ATTR_VAL_LENGTH, i_length+1 );
        /*@
         * @errortype
         * @moduleid  TARG_MOD_ATTR_TEXT_OVERRIDE
         * @reasoncode TARG_RC_MAX_ATTR_VAL_LENGTH
         * @userdata1 Current attribute value length
         * @userdata2 Max attribute value length
         * @devdesc   Override value exceeds max value length
         * @custdesc  Informational firmware error occurred
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_TEXT_OVERRIDE,
                                TARG_RC_MAX_ATTR_VAL_LENGTH,
                                i_length,
                                MAX_ATTR_VAL_LENGTH,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    return l_err;
}


/**
 * @brief Splits an attribute line into fields
 *
 * @param[in]  i_line       Input line string
 * @param[out] o_attrName   Set to Attr name
 * @param[out] o_attrDims   Set to attribute dimensions
 *                          Each element is 0 for unused dimensions
 * @param[out] o_attrVal    Set to attr value, this can be a literal
 *                          or an enumerator
 * @param[out] o_attrConst  True if CONST (only used for overrides)
 *
 * @return errlHndl_t       Error log handle
 */
errlHndl_t attrLineToFields( char * i_line,
                             char * o_attrName,
                             size_t (& o_attrDims)[ATTR_MAX_DIMS],
                             char * o_attrVal,
                             bool & o_attrConst )
{
    //
    // Note: at this point the type field has already been removed (u32[2][2])
    // e.g. "ATTR_MSS_DIMM_MFG_ID_CODE[0][1] u32[2][2] 0x12345678 CONST"
    //                <field 1>                        <field 2>  <field 3 >
    // - o_attrName = "ATTR_MSS_DIMM_MFG_ID_CODE"
    // - o_attrDims = {0, 1, 0, 0}
    // - o_attrVal = "0x12345678"
    // - o_attrConst = true
    //

    errlHndl_t l_err = nullptr;

    char * l_endLinePtr = i_line + strlen(i_line);

    // First field: attribute name
    char * l_namePtr = nullptr;
    size_t l_nameLen = 0;

    // Second field: attribute value
    char * l_valuePtr = nullptr;
    size_t l_valueLen = 0;

    // Third field: const
    char * l_constPtr = nullptr;

    // Attribute dimensions
    size_t l_dim = 0;
    size_t l_dimchars = 0;
    size_t l_openOffset = 0;
    size_t l_closeOffset = 0;

    // Set the field pointers and lengths
    // First field: attribute name
    l_namePtr = i_line;

    // Find the end of the attr name
    l_valuePtr = nextWhiteSpaceChar(l_namePtr);

    // Calculate the attr name length
    l_nameLen = l_valuePtr - l_namePtr;

    // Second field: value string
    l_valuePtr = nextVisibleChar(l_valuePtr);

    // Attribute value is required
    if (l_valuePtr == l_endLinePtr)
    {
        l_constPtr = l_endLinePtr;

        OVD_TRACE("Attribute Override: ***ERROR*** Missing attribute value %s", i_line );
        /*@
            * @errortype
            * @moduleid  TARG_MOD_ATTR_LINE_TO_FIELDS
            * @reasoncode TARG_RC_ATTR_VALUE_MISSING
            * @userdata1 <unused>
            * @userdata2 <unused>
            * @devdesc   Missing attribute value
            * @custdesc  Informational firmware error occurred
            */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_LINE_TO_FIELDS,
                                TARG_RC_ATTR_VALUE_MISSING,
                                0,
                                0,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }

    // Find the end of the value string
    l_constPtr = nextWhiteSpaceChar(l_valuePtr);

    // Calculate the value string length
    l_valueLen = l_constPtr - l_valuePtr;

    // Third field: const, may be empty
    l_constPtr = nextVisibleChar(l_constPtr);

    if (l_constPtr == l_endLinePtr)
    {
        l_constPtr = l_endLinePtr;
    }

    // Save the attribute name, ignore any array dimensions
    l_openOffset = strStrPos(l_namePtr, "[");
    l_closeOffset = strStrPos(l_namePtr, "]");

    if (l_openOffset != CONST_INVALID)
    {
        // Found an open bracket, copy up to open bracket
        strncpy(o_attrName, l_namePtr, l_openOffset);
    }
    else
    {
        // Not an array attr, copy the whole attr name
        strncpy(o_attrName, l_namePtr, l_nameLen);
    }

    // Make it a valid string
    o_attrName[l_nameLen] = '\0';

    // Get the attr dimensions
    while (l_openOffset != CONST_INVALID)
    {
        l_dimchars = l_closeOffset - l_openOffset;
        char l_dimstring[l_dimchars] = {0};
        strncpy(l_dimstring, l_namePtr+l_openOffset+1, l_dimchars);
        o_attrDims[l_dim] = strtoul(l_dimstring, nullptr, 10);
        l_dim++;

        if(l_dim > ATTR_MAX_DIMS)
        {
            OVD_TRACE("Attribute Override: ***ERROR*** Override exceeds max dimensions %d: %s", ATTR_MAX_DIMS, i_line );
            /*@
                * @errortype
                * @moduleid  TARG_MOD_ATTR_LINE_TO_FIELDS
                * @reasoncode TARG_RC_ATTR_MAX_DIMENSIONS
                * @userdata1 ATTR_MAX_DIMS
                * @userdata2 Attribute dimensions
                * @devdesc   Override exceeds max dimensions
                * @custdesc  Informational firmware error occurred
                */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    TARG_MOD_ATTR_LINE_TO_FIELDS,
                                    TARG_RC_ATTR_MAX_DIMENSIONS,
                                    ATTR_MAX_DIMS,
                                    l_dim,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            goto ERROR_EXIT;
        }

        l_openOffset = strStrPos(l_namePtr+l_closeOffset+1, "[");
        l_closeOffset = strStrPos(l_namePtr+l_closeOffset+1, "]");
    }

    // Check the value length, don't want to over-run the value string
    l_err = checkAttrValueLength(l_valueLen);
    if (l_err)
    {
        goto ERROR_EXIT;
    }

    // Save the output attr value
    strncpy(o_attrVal, l_valuePtr, l_valueLen);

    // Make it a valid string
    o_attrVal[l_valueLen] = '\0';

    // The third field is const
    if (strstr(l_constPtr, "CONST") != nullptr)
    {
        o_attrConst = true;
    }

ERROR_EXIT:
    return l_err;
}


/**
 * @brief Helper function that updates label list
 *
 * @param[in/out] io_labels         Label list to be updated
 * @param[in]     i_label_override  Specifies override values to
 *                                   apply to each label in list
 *
 */
void updateLabels(std::vector<target_label> & io_labels,
                  const target_label & i_label_override)
{
    for (std::vector<target_label>::iterator it = io_labels.begin();
         it != io_labels.end();
         ++it)
    {
        if (i_label_override.node != AttributeTank::ATTR_NODE_NA)
        {
            it->node = i_label_override.node;
        }
        if (i_label_override.targetPos != AttributeTank::ATTR_POS_NA)
        {
            it->targetPos = i_label_override.targetPos;
        }
        if (i_label_override.unitPos != AttributeTank::ATTR_UNIT_POS_NA)
        {
            it->unitPos = i_label_override.unitPos;
        }
    }
}


/**
 * @brief Converts a target line to data
 *
 * @param[in]  i_line          Input target line
 * @param[in]  i_tankLayer     Firmware layer containing the tank
 * @param[out] o_targetType    Target Type (as stored in tank)
 * @param[out] o_targetLabels  List of target labels
 *
 * @return errlHndl_t          Error log handle
 */
errlHndl_t targetLineToData(char * i_line,
                            const AttributeTank::TankLayer i_tankLayer,
                            uint32_t & o_targetType,
                            std::vector<target_label> & o_targetLabels)
{
    // Future enhancement: this function is large, try to add subfunctions
    // e.g. "target = k0:s0:n0:ocmb:p04
    // - o_targetType = 0x0000004b
    // - 1 target specified:
    //     node: 0, targetPos: 4, unitPos: 0xff
    //
    //
    // e.g. "target = p10.iohs:k0:n0:s0:p0,1:c2"
    // - o_targetType = 0x00000051
    // - 2 targets specified:
    //     node: 0, targetPos: 0, unitPos: 2
    //     node: 0, targetPos: 1, unitPos: 2
    //

    errlHndl_t l_err = nullptr;

    // Create a generic label
    target_label l_label;

    // Always start with no targets
    o_targetLabels.clear();

    // Find positions
    size_t l_comma_pos = 0;
    size_t l_colon_pos = 0;

    // If the target string is not decoded into a non-system target and
    // explicit positions are not found then the caller will get these defaults
    bool l_sysTarget = true;

    // Set the default output target type
    if (i_tankLayer == AttributeTank::TANK_LAYER_FAPI)
    {
        o_targetType = fapi2::TARGET_TYPE_SYSTEM;
    }
    else
    {
        o_targetType = TARGETING::TYPE_SYS;
    }

    // Get whatever follows the "target = k0:s0" string
    const char * l_linePtr = strstr(i_line, ":s0");
    l_linePtr += 3;

    // If all that remains is a single ':' char then move the pointer
    // and continue (e.g started with k0:s0:<blanks>)
    // otherwise the ':' is part of a parameter term
    if ( (strlen(l_linePtr) == 1) &&
            (l_linePtr[0] == ':') )
    {
        l_linePtr += 1;
    }

    // Figure out the node number
    auto l_nPosition = strStrPos(l_linePtr, ":n");
    if (l_nPosition == 0)
    {
        // If ":n" is present, the target is at least at the node level
        // NOTE:  FAPI targets do not suport node level
        if (i_tankLayer != AttributeTank::TANK_LAYER_FAPI)
        {
            o_targetType = TARGETING::TYPE_NODE;
        }

        // Move the pointer after ":n"
        l_linePtr += 2;

        if (!strncmp(l_linePtr, "all", 3))
        {
            // Add a new target label node number
            o_targetLabels.push_back(l_label);
            // Move the pointer after "all"
            l_linePtr += 3;
        }
        else
        {
            l_colon_pos = strStrPos(l_linePtr, ":");
            l_comma_pos = strStrPos(l_linePtr, ",");

            // Make sure comma comes before ending colon
            while ((l_comma_pos != CONST_INVALID) &&
                    (l_comma_pos < l_colon_pos))
            {
                // Grab number (stops at first non-numerical character)
                l_label.node = strtoul(l_linePtr, nullptr, 10);

                // Add a new target label node number
                o_targetLabels.push_back(l_label);

                // Move the pointer after the comma
                l_linePtr += l_comma_pos+1;

                // Look for next potential comma
                l_comma_pos = strStrPos(l_linePtr, ",");
            }

            // Grab number (stops at first non-numerical character)
            l_label.node = strtoul(l_linePtr, nullptr, 10);

            // Add the last target label node number
            o_targetLabels.push_back(l_label);

            // Turn off overriding node
            l_label.node = AttributeTank::ATTR_NODE_NA;

            // Find the ending colon for the node part
            l_colon_pos = strStrPos(l_linePtr, ":");
            if (l_colon_pos != CONST_INVALID)
            {
                // Move pointer to the next colon
                l_linePtr += l_colon_pos;
            }
            else
            {
                // No colon found after node,
                // move the pointer to end-of-string
                l_linePtr = i_line + strlen(i_line);
            }
        }
    } // End figure out target node

    if (strlen(l_linePtr))
    {
        // Move the pointer after ":" that trails the n value
        l_linePtr += 1;
    }

    // Figure out the target type
    // Remove the end of the target string (position and unitpos) before
    // using the line to search for target types
    l_colon_pos = strStrPos(l_linePtr, ":");

    char l_targetType[strlen(l_linePtr)] = {0};
    char l_origTargetType[strlen(l_linePtr)] = {0};
    char * l_tTypePtr = l_targetType;

    TargStrToType* chip_type_first = nullptr;
    TargStrToType* chip_type_last = nullptr;

    TargStrToType* l_item = nullptr;
    if( l_colon_pos != CONST_INVALID)
    {
        // Save the full target type name
        strncpy(l_origTargetType, l_linePtr, l_colon_pos);

        // Put it into an alterable target type
        strcpy(l_targetType, l_origTargetType);

        auto l_dotIndex = strStrPos(l_tTypePtr, ".");

        if(l_dotIndex != CONST_INVALID)
        {
            // Found ".", meaning both chip type and chip unit are specified
            // Isolate the chip unit type
            l_tTypePtr += l_dotIndex + 1;

            // Save range to search in correct target type array
            chip_type_first = &CHIP_UNIT_TYPE_TARG_STR_TO_TYPE[0];
            chip_type_last = &CHIP_UNIT_TYPE_TARG_STR_TO_TYPE
                [(sizeof(CHIP_UNIT_TYPE_TARG_STR_TO_TYPE) /
                        sizeof(TargStrToType))-1];
        }
        else
        {
            // Only chip type specified
            // Save range to search in correct target type array
            chip_type_first = &CHIP_TYPE_TARG_STR_TO_TYPE[0];
            chip_type_last = &CHIP_TYPE_TARG_STR_TO_TYPE
                    [(sizeof(CHIP_TYPE_TARG_STR_TO_TYPE) /
                            sizeof(TargStrToType))-1];

        }

        // Search for target type
        l_item = std::find( chip_type_first, chip_type_last, l_tTypePtr);

        if( l_item != chip_type_last )
        {
            // Target type found
            // Choose fapi2 or targeting type
            o_targetType = ( i_tankLayer == AttributeTank::TANK_LAYER_TARG ?
                                l_item->targType : l_item->fapiType );

            // Move pointer after the full target type name
            l_linePtr += strlen(l_origTargetType);
            l_sysTarget = false;
        }
        else
        {
            const uint64_t* l_strAsUint1Ptr =
                reinterpret_cast<const uint64_t*>(l_targetType);
            const uint64_t* l_strAsUint2Ptr = l_strAsUint1Ptr + 1;

            OVD_TRACE("Attribute Override: ***ERROR*** Could not find attribute override target, %s", i_line );
            /*@
                * @errortype
                * @moduleid  TARG_MOD_ATTR_TARGET_LINE_TO_DATA
                * @reasoncode TARG_RC_ATTR_TARGET_NOT_FOUND
                * @userdata1 Target ascii string
                * @userdata2 Target ascii string continued
                * @devdesc   Could not find attribute override target
                * @custdesc  Informational firmware error occurred
                */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    TARG_MOD_ATTR_TARGET_LINE_TO_DATA,
                                    TARG_RC_ATTR_TARGET_NOT_FOUND,
                                    *l_strAsUint1Ptr,
                                    *l_strAsUint2Ptr,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            goto ERROR_EXIT;
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
        if (l_nPosition == CONST_INVALID)
        {
            // missing n term, need to add a default label
            o_targetLabels.push_back(l_label);
        }
        else
        {
            // (labels already exist)
        }

        // Figure out the target's position
        std::vector<target_label> l_origCopy;
        if (!strncmp(l_linePtr, ":p", 2))
        {
            // Move the pointer after ":p"
            l_linePtr += 2;

            if (!strncmp(l_linePtr, "all", 3))
            {
                // Move the pointer after "all"
                l_linePtr += 3;
            }
            else
            {
                bool firstPos = true;
                l_colon_pos = strStrPos(l_linePtr, ":");
                l_comma_pos = strStrPos(l_linePtr, ",");

                while ((l_comma_pos != CONST_INVALID) &&
                        (l_comma_pos < l_colon_pos))
                {
                    // Grab targetPos number
                    // (stops at first non-numerical character)
                    l_label.targetPos = strtoul(l_linePtr, nullptr, 10);

                    if (firstPos)
                    {
                        // Save a copy of current targets before
                        // adding targetPos
                        l_origCopy = o_targetLabels;

                        // Update targetPos of current targets
                        updateLabels(o_targetLabels, l_label);
                        firstPos = false;
                    }
                    else
                    {
                        // Update targetPos of original targets
                        updateLabels(l_origCopy, l_label);

                        // Add these new targetPos targets to
                        // current target list
                        o_targetLabels.insert(
                                o_targetLabels.end(),
                                l_origCopy.begin(),
                                l_origCopy.end() );
                    }

                    // Move the pointer after the comma
                    l_linePtr += l_comma_pos+1;

                    // Look for next potential comma
                    l_comma_pos = strStrPos(l_linePtr, ",");
                }

                // Grab number (stops at first non-numerical character)
                l_label.targetPos = strtoul(l_linePtr, nullptr, 10);
                if (firstPos)
                {
                    // No comma found, so just update
                    // current target list
                    updateLabels(o_targetLabels, l_label);
                }
                else
                {
                    // Last targetPos in comma list
                    // update targetPos of original targets
                    updateLabels(l_origCopy, l_label);

                    // add these new targetPos targets to
                    // the current target list
                    o_targetLabels.insert(
                            o_targetLabels.end(),
                            l_origCopy.begin(),
                            l_origCopy.end());
                }

                // Turn off overriding targetPos
                l_label.targetPos = AttributeTank::ATTR_POS_NA;

                // Find the ending colon for the targetPos part
                l_colon_pos = strStrPos(l_linePtr, ":");
                if (l_colon_pos != CONST_INVALID)
                {
                    // Move pointer to the next colon
                    l_linePtr += l_colon_pos;
                }
                else
                {
                    // No colon found after targetPos,
                    // move the pointer to end-of-string
                    l_linePtr = i_line + strlen(i_line);
                }
            }
        }

        // Figure out the target's unit position
        if (!strncmp(l_linePtr, ":c", 2))
        {
            // Move the pointer after ":c"
            l_linePtr += 2;

            if (!strncmp(l_linePtr, "all", 3))
            {
                // Move the pointer after "all"
                l_linePtr += 3;
            }
            else
            {
                bool firstPos = true;
                l_comma_pos = strStrPos(l_linePtr, ",");

                while (l_comma_pos != CONST_INVALID)
                {
                    // Grab unitPos number
                    // (stops at first non-numerical character)
                    l_label.unitPos = strtoul(l_linePtr, nullptr, 10);
                    if (firstPos)
                    {
                        // Save a copy of current targets
                        // before adding unitPos
                        l_origCopy = o_targetLabels;

                        // Update unitPos of current targets
                        updateLabels(o_targetLabels, l_label);
                        firstPos = false;
                    }
                    else
                    {
                        // Update unitPos of original targets
                        updateLabels(l_origCopy, l_label);

                        // Add these new unitPos targets to
                        // the current target list
                        o_targetLabels.insert(
                                o_targetLabels.end(),
                                l_origCopy.begin(),
                                l_origCopy.end() );
                    }

                    // Move the pointer after the comma
                    l_linePtr += l_comma_pos+1;

                    // Look for next potential comma
                    l_comma_pos = strStrPos(l_linePtr, ",");
                }

                // Grab number (stops at first non-numerical character)
                l_label.unitPos = strtoul(l_linePtr, nullptr, 10);
                if (firstPos)
                {
                    // No comma found, so just update
                    // current target list
                    updateLabels(o_targetLabels, l_label);
                }
                else
                {
                    // Last unitPos in comma list
                    // update unitPos of original targets
                    updateLabels(l_origCopy, l_label);

                    // Add these new unitPos targets to
                    // the current target list
                    o_targetLabels.insert(
                            o_targetLabels.end(),
                            l_origCopy.begin(),
                            l_origCopy.end());
                }
            }
        }
    }

    // System targets must have an NA node
    if (l_sysTarget)
    {
        if (o_targetLabels.size() == 0)
        {
            o_targetLabels.push_back(l_label);
        }
    }

    if (o_targetLabels.size() == 0)
    {
        // No output data was generated
        OVD_TRACE("Attribute Override: ***ERROR*** No attribute override target output generated: %s", i_line );
        /*@
            * @errortype
            * @moduleid  TARG_MOD_ATTR_TARGET_LINE_TO_DATA
            * @reasoncode TARG_RC_NO_OUTPUT_GENERATED
            * @userdata1 <unused>
            * @userdata2 <unused>
            * @devdesc   No attribute override target output generated
            * @custdesc  Informational firmware error occurred
            */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_TARGET_LINE_TO_DATA,
                                TARG_RC_NO_OUTPUT_GENERATED,
                                0,
                                0,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }

ERROR_EXIT:
    return l_err;
}


/**
 * @brief This function retrieves the attribute enum value from a generated
 *        map and returns that value
 *
 * @param[in] i_attrName - The name of the attribute to get the data for
 * @param[out] o_enumVal - The value of the enum for the given attribute.
 *
 * @return errlHndl_t   Error log handle
 */
errlHndl_t getAttrEnumDataFromMap(const char * i_attrName,
                                  uint64_t & o_enumVal)
{
    errlHndl_t l_err = nullptr;

    const AttributeEnum* currentAttr = nullptr;
    currentAttr = findAttribute(g_FapiEnums,
                                sizeof(g_FapiEnums)/sizeof(AttributeEnum),
                                i_attrName);

    if (nullptr == currentAttr)
    {
        const uint64_t* l_strAsUint1Ptr =
            reinterpret_cast<const uint64_t*>(i_attrName);
        const uint64_t* l_strAsUint2Ptr = l_strAsUint1Ptr + 1;

        OVD_TRACE("Attribute Override: ***ERROR*** Could not find attribute to override: %s", i_attrName );
        /*@
            * @errortype
            * @moduleid  TARG_MOD_ATTR_ENUM_DATA_FROM_MAP
            * @reasoncode TARG_RC_ATTR_NOT_FOUND
            * @userdata1 Target ascii string
            * @userdata2 Target ascii string continued
            * @devdesc   Could not find attribute to override
            * @custdesc  Informational firmware error occurred
            */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_ENUM_DATA_FROM_MAP,
                                TARG_RC_ATTR_NOT_FOUND,
                                *l_strAsUint1Ptr,
                                *l_strAsUint2Ptr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }

    o_enumVal = currentAttr->iv_value;

ERROR_EXIT:
    return l_err;
}


/**
 * @brief This function retrieves the attribute data from a generated map
 *        and returns the relevant data
 *
 * @param[in] i_attrName - The name of the attribute to get the data for
 * @param[out] o_attrId - The attribute ID
 * @param[out] o_attrElemSizeBytes - The size of the element in bytes
 * @param[out] o_attrDims[] - an array containing the dimensional information
 *                        of the attribute
 * @param[out] o_tankLayer - The tank layer for the attribute
 * @param[in] i_attrMap - The pregenerated std::map containing the
 *                        attributeData
 *
 * @return errlHndl_t   Error log handle
 */
errlHndl_t getAttrDataFromMap(const char * i_attrName,
                              uint32_t & o_attrId,
                              uint32_t & o_attrElemSizeBytes,
                              size_t (& o_attrDims)[4],
                              AttributeTank::TankLayer & o_tankLayer)
{
    errlHndl_t l_err = nullptr;

    const AttributeData* currentAttr = nullptr;

    // Check for attribute inside attribute data maps. Must search
    // the TARG map first because for an attribute that exists in both FAPI
    // and TARG maps (i.e. a FAPI Attribute that is implemented by a TARG
    // attribute), an override should be stored in the TARG override tank.
    currentAttr = findAttribute(g_TargAttrs,
                                sizeof(g_TargAttrs)/sizeof(AttributeData),
                                i_attrName);
    o_tankLayer = AttributeTank::TANK_LAYER_TARG;

    if (nullptr == currentAttr)
    {
        currentAttr =
                    findAttribute(g_FapiAttrs,
                                sizeof(g_FapiAttrs)/sizeof(AttributeData),
                                i_attrName);
        o_tankLayer = AttributeTank::TANK_LAYER_FAPI;
    }

    if (nullptr == currentAttr)
    {
        const uint64_t* l_strAsUint1Ptr =
            reinterpret_cast<const uint64_t*>(i_attrName);
        const uint64_t* l_strAsUint2Ptr = l_strAsUint1Ptr + 1;

        OVD_TRACE("Attribute Override: ***ERROR*** Could not find attribute data: %s", i_attrName );
        /*@
            * @errortype
            * @moduleid  TARG_MOD_ATTR_GET_DATA_FROM_MAP
            * @reasoncode TARG_RC_ATTR_DATA_NOT_FOUND
            * @userdata1 Attribute name as ascii string
            * @userdata2 Attribute name as ascii string continued
            * @devdesc   Could not find attribute data
            * @custdesc  Informational firmware error occurred
            */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_GET_DATA_FROM_MAP,
                                TARG_RC_ATTR_DATA_NOT_FOUND,
                                *l_strAsUint1Ptr,
                                *l_strAsUint2Ptr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }

    o_attrId = currentAttr->iv_attrId;
    o_attrElemSizeBytes = currentAttr->iv_attrElemSizeBytes;
    for(size_t i = 0; i < sizeof(o_attrDims)/sizeof(size_t); ++i)
    {
        o_attrDims[i] = currentAttr->iv_dims[i];
    }

ERROR_EXIT:
    return l_err;
}


/**
 * @brief Converts a set of attribute lines (all for the same attribute) to data
 *
 * Note that this function allocates data in o_pAttrVal which must be freed
 * by the caller using delete[]
 *
 * @param[in]  i_lines        Ref to vector of attribute line strings
 * @param[out] o_attrId       Filled in with the attr id (as stored in tank)
 * @param[out] o_valSizeBytes Size of the attribute value
 * @param[out] o_pAttrVal     Pointer to buffer allocated by this function
 *                            and filled in with the attribute value
 * @param[out] o_attrConst    True if the attribute is a const override
 * @param[out] o_tankLayer    The tank layer for the current attribute
 *
 * @return errlHndl_t         Error log handle
 */
errlHndl_t attrLinesToData(
                std::vector<char*> i_lines,
                uint32_t & o_attrId,
                uint32_t & o_valSizeBytes,
                uint8_t * & o_pAttrVal,
                bool & o_attrConst,
                AttributeTank::TankLayer & o_tankLayer )
{
    errlHndl_t l_err = nullptr;

    size_t l_numElements = 0;
    // Data for the attribute
    uint32_t l_attrElemSizeBytes = 0;
    size_t l_attrDims[ATTR_MAX_DIMS] = {0}; // dimensions of the attribute

    // Data for this line. Note that this function expects all lines to be for
    // the same attr (in the case of an array attribute)
    char l_attrString[MAX_ATTR_NAME_LENGTH] = {0};
    size_t l_td[ATTR_MAX_DIMS] = {0}; // dimensions of this line's element
    char l_valString[MAX_ATTR_VAL_LENGTH] = {0};
    uint64_t l_attrVal = 0;

    std::vector<char*>::const_iterator l_itr;

    // Iterate over each line
    for (l_itr = i_lines.begin(); l_itr != i_lines.end(); ++l_itr)
    {
        // Split the attribute line into fields
        l_err = attrLineToFields(*l_itr,
                                 l_attrString,
                                 l_td,
                                 l_valString,
                                 o_attrConst);

        if (l_err)
        {
            goto ERROR_EXIT;
        }

        if (o_pAttrVal == nullptr)
        {

            l_err = getAttrDataFromMap(l_attrString,
                                       o_attrId,
                                       l_attrElemSizeBytes,
                                       l_attrDims,
                                       o_tankLayer);
            if(l_err)
            {
                goto ERROR_EXIT;
            }

            o_valSizeBytes = l_attrElemSizeBytes
                * l_attrDims[0] * l_attrDims[1] * l_attrDims[2] * l_attrDims[3];
            o_pAttrVal = new uint8_t[o_valSizeBytes];
            memset(o_pAttrVal, 0, o_valSizeBytes);
        }

        // Check that the attribute isn't overflowing an array
        for(size_t i = 0; i < ATTR_MAX_DIMS; i++)
        {
            if(l_td[i] >= l_attrDims[i])
            {
                break;
            }
        }

        // Expect 0x<> for unsigned and -<> for signed attribute
        if (((l_valString[0] == '0') && (l_valString[1] == 'x')) ||
             (l_valString[0] == '-'))
        {
            l_attrVal = strtoul(l_valString, nullptr, 16);
        }
        else
        {
            // Value string is an enumerator, it is decoded using <attr>_<enum>
            strcat(l_attrString, "_");
            strcat(l_attrString, l_valString);

            l_err = getAttrEnumDataFromMap(l_attrString, l_attrVal);

            if(l_err)
            {
                goto ERROR_EXIT;
            }

        }

        // Write the element to the correct place in the buffer
        size_t l_size = sizeof(l_attrDims)/sizeof(size_t);
        size_t l_elem = 0;
        for(size_t idx = 0; idx < l_size; idx++)
        {
            l_elem *= l_attrDims[idx];
            l_elem += l_td[idx];
        }

        if (l_attrElemSizeBytes == sizeof(uint8_t))
        {
            o_pAttrVal[l_elem] = l_attrVal;
            l_numElements++;
        }
        else if (l_attrElemSizeBytes == sizeof(uint16_t))
        {
            uint16_t * l_pVal = reinterpret_cast<uint16_t *>(o_pAttrVal);
            l_pVal[l_elem] = htobe16(l_attrVal);
            l_numElements++;
        }
        else if (l_attrElemSizeBytes == sizeof(uint32_t))
        {
            uint32_t * l_pVal = reinterpret_cast<uint32_t *>(o_pAttrVal);
            l_pVal[l_elem] = htobe32(l_attrVal);
            l_numElements++;
        }
        else
        {
            uint64_t * l_pVal = reinterpret_cast<uint64_t *>(o_pAttrVal);
            l_pVal[l_elem] = htobe64(l_attrVal);
            l_numElements++;
        }

    }

ERROR_EXIT:
    return l_err;
}


/**
 * @brief This function converts obsolete format target line to
 *         current format.
 *        Will not change current format target line.
 *
 * @param[in] i_line Reference to string containing line
 * @param[out] o_convertedLine - Filled in with converted string
 *
 * @return errlHndl_t   Error log handle
 */
errlHndl_t convertTargLine( const char * i_line,
                            char * o_convertedLine )
{
    // Input string begins with "target"
    // e.g. "target = ocmb:k0:n0:s0:p04"

    errlHndl_t l_err = nullptr;

    char * l_strPtr = nullptr;
    char l_line[strlen(i_line)+1] = {0};
    strcpy(l_line, i_line);

    do
    {
        size_t l_kPosn = strStrPos(l_line, "k");
        size_t l_kColonPosn = strStrPos(l_line, ":k");
        size_t l_sPosn = strStrPos(l_line, ":s");

        // Check for only white space after "target", old format
        l_strPtr = nextVisibleChar(l_line + 6);
        if (l_strPtr == l_line + strlen(l_line))
        {
            strcpy(o_convertedLine, "target = k0:s0");
            break;
        }

        // Check for missing params
        if ( (l_kPosn == CONST_INVALID) || (l_sPosn == CONST_INVALID) )
        {
            strcpy(o_convertedLine, i_line);
            break;
        }

        // Check for correct k/s order
        if ( l_kPosn > l_sPosn )
        {
            strcpy(o_convertedLine, i_line);
            break;
        }

        // Check if a param preceeds the k term
        if ( l_kColonPosn != CONST_INVALID )
        {
            // Check for missing "="
            size_t eqPos = strcspn(l_line,"=\0");
            if (eqPos == strlen(l_line))
            {
                strcpy(o_convertedLine, i_line);
                break;
            }

            // Preamble may be <chiptype> || [.<chip unit type>] || :
            l_strPtr = nextVisibleChar(l_line + eqPos + 1);
            size_t l_preambleStart = l_strPtr - l_line;

            // Remove trailing colon, prepend colon, postpend end-of-string
            size_t l_preambleLen = l_kColonPosn - l_preambleStart;
            char l_preamble[l_preambleLen+2] = {0};
            strncpy( l_preamble + 1,
                     l_line + l_preambleStart,
                     l_preambleLen );
            l_preamble[0] = ':';
            l_preamble[l_preambleLen+1] = '\0';

            // k0:s0 term ( or k0:nz:s0 ) is next
            size_t l_sysStrLen = (l_sPosn + 3) - (l_kColonPosn + 1);
            char l_sysStr[l_sysStrLen+1] = {0};
            strncpy( l_sysStr,
                     l_line + l_kColonPosn + 1,
                     l_sysStrLen );
            l_sysStr[l_sysStrLen] = '\0';

            char l_nStr[strlen(l_sysStr)] = {0};

            // Check for non standard k0:nz:s0 format
            size_t l_nStart = strStrPos(l_sysStr, ":n");

            if (l_nStart != CONST_INVALID)
            {
                // Extract n term and compress system string
                char l_nPrefix[l_nStart+1] = {0};
                strncpy(l_nPrefix, l_sysStr, l_nStart);
                l_nPrefix[l_nStart] = '\0';

                size_t l_nPost = strStrPos(l_sysStr + l_nStart + 1, ":");

                char l_nPostFix[strlen(l_sysStr)] = {0};

                if ( l_nPost != CONST_INVALID)
                {
                    // Extract n string & post fix
                    strncpy(l_nStr, l_sysStr + l_nStart, l_nPost + 1);
                    l_nStr[l_nPost+1] = '\0';
                    strcpy(l_nPostFix, l_sysStr + l_nStart + l_nPost + 1);
                }
                else
                {
                    // Extract n string, no post fix
                    strcpy(l_nStr, l_sysStr + l_nStart);
                }

                // Rebuild the system string
                strcpy(l_sysStr, l_nPrefix);
                strcat(l_sysStr, l_nPostFix);
                strcat(l_sysStr, l_nStr);

                // Clear the n string
                memset(l_nStr, 0, strlen(l_sysStr));
            } // End extract n term

            char l_trlStr[strlen(l_line)] = {0};

            // Look for next term
            size_t l_trlStart = strStrPos(l_line + l_sPosn + 3,":");

            if (l_trlStart != CONST_INVALID)
            {
                // From start of l_line
                l_trlStart += l_sPosn + 3;

                // Step over optional :n term
                if (l_line[l_trlStart] == ':' && l_line[l_trlStart+1] == 'n')
                {
                    // Locate the end of the n term
                    l_nStart = l_trlStart;
                    l_trlStart = strStrPos(l_line + l_nStart + 1, ":");

                    if ( l_trlStart != CONST_INVALID)
                    {
                        // Create n and trl strings
                        strncpy(l_nStr, l_line+l_nStart, l_trlStart-l_nStart);
                        strncpy(l_trlStr, l_line+l_trlStart, strlen(l_line));
                    }
                    else
                    {
                        // No trl string, create n string
                        strncpy(l_nStr, l_line+l_nStart, strlen(l_line));
                    }
                } // End step over n term
                else
                {
                    // No n string, create trl string
                    strncpy(l_trlStr, l_line+l_trlStart, strlen(l_line));
                }
            } // End no trailer found

            // Assemble the converted line
            strcpy(o_convertedLine, "target = ");
            strcat(o_convertedLine, l_sysStr);
            strcat(o_convertedLine, l_nStr);
            strcat(o_convertedLine, l_preamble);
            strcat(o_convertedLine, l_trlStr);

            break;
        }

        else if ( l_sPosn == (l_kPosn + 2) )
        {
            // kx:sy new format, no conversion needed
            break;
        }

        else
        {
            // (old format, or possibly k0:s0:nX format)
        }

        // (old format, convert to new format.  see header file)

        // Locate k & s term strings
        // "overflow" is the position right after the term string
        //   and is the beginning of the next term string
        size_t l_kPosn_overflow = strStrPos(l_line + l_kPosn, ":");
        size_t l_kStrSize = 0;
        if (l_kPosn_overflow != CONST_INVALID)
        {
            l_kPosn_overflow += l_kPosn;
            l_kStrSize = l_kPosn_overflow - l_kPosn;
        }
        else
        {
            l_kStrSize = strlen(l_line) - l_kPosn;
        }
        char l_kStr[l_kStrSize+1] = {0};
        strncpy(l_kStr, l_line + l_kPosn, l_kStrSize);
        l_kStr[l_kStrSize] = '\0';

        size_t l_sPosn_overflow = strStrPos(l_line + l_sPosn + 1, ":");
        size_t l_sStrSize;
        if (l_sPosn_overflow != CONST_INVALID)
        {
            l_sPosn_overflow += l_sPosn + 1;
            l_sStrSize = l_sPosn_overflow - l_sPosn;
        }
        else
        {
            l_sStrSize = strlen(l_line) - l_sPosn;
            l_sPosn_overflow = l_sPosn + l_sStrSize;
        }

        char l_sStr[l_sStrSize+1] = {0};
        strncpy(l_sStr, l_line + l_sPosn, l_sStrSize);
        l_sStr[l_sStrSize] = '\0';

        // Strip out the k & s terms to create a postamble string
        char l_postAmble[strlen(l_line)] = {0};
        strncpy(l_postAmble,
                l_line + l_kPosn_overflow,
                l_sPosn - l_kPosn_overflow);
        strncat(l_postAmble,
                l_line + l_sPosn_overflow,
                strlen(l_line) - l_sPosn_overflow);

        strcpy(o_convertedLine, "target = ");
        strcat(o_convertedLine, l_kStr);
        strcat(o_convertedLine, l_sStr);
        if ( !strcmp(l_postAmble, ":n0"   ) ||
             !strcmp(l_postAmble, ":n0:"  ) ||
             !strcmp(l_postAmble, ":nall" ) ||
             !strcmp(l_postAmble, ":nall:") )
        {
            // Add postamble when not a legacy system target
            strcat(o_convertedLine, l_postAmble);
        }
        else
        {
            // Re-order to kX:sX:nX, and strip ":" if it's at the end
            // (this simplifies processing later in this file)
            if (l_postAmble[strlen(l_postAmble)-1] == ':')
            {
                l_postAmble[strlen(l_postAmble)-1] = '\0';
            }

            strcat(o_convertedLine, l_postAmble);
        }

    } while ( 0 );

    return l_err;
}


/**
 * @brief Checks if a valid System substring exists
 *
 * @param[in] i_line Reference to string containing line
 *
 * @return true if a valid System substring exists
 */
TargetTypeRc validateSysSubstr( char * i_line )
{
    // Input line :
    //  - "target =" and any preceeding white space has been stripped
    //  - any trailing white space has been stripped
    char * l_line = i_line;

    TargetTypeRc rc = TARGET_TYPE_RC_NONE;

    // n values
    size_t l_nValStartPosn = 0;
    size_t l_nValOverflowPosn = 0;
    size_t l_nValCurPosn = 0;
    size_t l_nValLen = 0;
    char * l_nValString = nullptr;

    // Determine target type:  rules are listed in attrTextOverride.H
    //  - system
    //     target = k0:s0[:] <blank>
    //
    //  - chip
    //     system || chip string
    //

    size_t l_strLen = strlen(l_line);

    // Input line is too short to be a system string
    if ( l_strLen < 5 )
    {
        // Bad encoding
        OVD_TRACE("Attribute Override: ***ERROR*** Invalid target line: %s", i_line );
        rc = TARGET_TYPE_RC_ERROR;
        goto ERROR_EXIT;
    }

    // Input line is too short to be a chip target
    else if ( l_strLen <= 6 )
    {
        // Check for valid system target string
        if ( (strcmp(l_line, "k0:s0")  == 0) ||
                (strcmp(l_line, "k0:s0:") == 0) )
        {
            // Target is system target, encoded correctly
            rc = TARGET_TYPE_RC_SYSTEM;
            goto ERROR_EXIT;
        }
        else
        {
            // Bad encoding
            OVD_TRACE("Attribute Override: ***ERROR*** Invalid system target line: %s", i_line );
            rc = TARGET_TYPE_RC_ERROR;
            goto ERROR_EXIT;
        }
    }

    else
    {
        // (potential node or chip target)
    }

    //  Only Potential Node or Chip Targets get to this point
    // System string is not correct
    if ( strStrPos(i_line, "k0:s0") != 0)
    {
        // Bad encoding
        OVD_TRACE("Attribute Override: ***ERROR*** Unexpected system target: %s", i_line );
        rc = TARGET_TYPE_RC_ERROR;
        goto ERROR_EXIT;
    }

    // Optional n term does not exist
    if ( strStrPos(i_line, ":n") != 5 )
    {
        // Valid chip target encoding
        rc = TARGET_TYPE_RC_CHIP;
        goto ERROR_EXIT;
    }

    // Optional end Term exists, check n parm value(s)
    //  step over the k0:s0:n chars then isolate the
    //   size/value of the n parm
    l_nValStartPosn = 7;
    l_nValOverflowPosn = strStrPos(l_line + l_nValStartPosn, ":");
    if ( l_nValOverflowPosn != CONST_INVALID)
    {
        l_nValOverflowPosn += l_nValStartPosn;
    }

    // Chip string does not follow optional n term - must be a node target
    if ( l_nValOverflowPosn == CONST_INVALID )
    {
        // Valid node target
        rc = TARGET_TYPE_RC_NODE;
        goto ERROR_EXIT;
    }

    l_nValLen = l_nValOverflowPosn - l_nValStartPosn;
    l_nValString = new char[l_nValLen+1];
    memset(l_nValString, 0, l_nValLen+1);
    strncpy(l_nValString, l_line + l_nValStartPosn, l_nValLen);
    l_nValString[l_nValLen] = '\0';

    // n value = all
    if ( strcmp(l_nValString,"all") == 0)
    {
        // Valid chip target encoding
        rc = TARGET_TYPE_RC_CHIP;
        goto ERROR_EXIT;
    }

    // n has a single character parameter value
    if ( l_nValLen == 1 )
    {
        // Parameter value is between 0 and 9
        if ( (l_nValString[0] >= '0') &&
                (l_nValString[0] <= '9') )
        {
            // Valid chip target encoding
            rc = TARGET_TYPE_RC_CHIP;
            goto ERROR_EXIT;
        }
        else
        {
            // Bad encoding
            OVD_TRACE("Attribute Override: ***ERROR*** Invalid node in target line: %s", i_line );
            rc = TARGET_TYPE_RC_ERROR;
            goto ERROR_EXIT;
        }
    }

    // No comma separated n values
    if (strStrPos(l_nValString, ",") == CONST_INVALID)
    {
        // Bad encoding
        OVD_TRACE("Attribute Override: ***ERROR*** Invalid node list in target line: %s", i_line );
        rc = TARGET_TYPE_RC_ERROR;
        goto ERROR_EXIT;
    }

    // n value is a comma separated list
    rc = TARGET_TYPE_RC_NODE;

    // Check for comma separated list
    // Loop thru the comma separated list
    for( size_t i = 0; i < l_nValLen; )
    {
        size_t l_commaPosn = strStrPos(l_nValString + i, ",");
        // Check for comma not found
        if ( l_commaPosn != CONST_INVALID)
        {
            // This is the last term
            i = l_nValLen;
            l_commaPosn =  l_nValLen;
        }
        else
        {
            // End of intermediary term
            i = l_commaPosn + 1;
        }

        // Check for parameter value not valid
        if ( (l_nValString[l_nValCurPosn] < '0') ||
                (l_nValString[l_nValCurPosn] > '9') )
        {
            // Bad encoding
            OVD_TRACE("Attribute Override: ***ERROR*** Invalid node in target line: %s", i_line );
            rc = TARGET_TYPE_RC_ERROR;
            goto ERROR_EXIT;
        }
        else
        {
            // Keep walking the list
            l_nValCurPosn = i;
        }
    } // End loop thru comma separated list

    if (l_nValString)
    {
        delete l_nValString;
        l_nValString = nullptr;
    }

ERROR_EXIT:
    return rc;
}


/**
 * @brief Checks if a Target line is encoded correctly
 *
 * @param[in] i_line Input line string
 *
 * @return False if validation failed, else true
 */
bool validateTargLine(char * i_line )
{
    // Input line :
    //  - has previously had leading white space stripped
    //  - begins with string "target"
    //  - has been converted from obsolete format to current format
    char * l_line = i_line;
    bool l_isValidLine = true;
    uint32_t l_curColonPosn = 0;
    uint32_t l_nextColonPosn = 0;
    TargetTypeRc l_tgtTypeRc = TARGET_TYPE_RC_NONE;

    // Determine target type:  rules are listed in attrTextOverride.H
    //  - system
    //     target = k0:s0[:] <blank>
    //
    //  - chip
    //     system || chip string
    //

    // Skip "target" label and whitespace
    l_line = nextVisibleChar(l_line + 6);

    if ( l_line[0] != '=' )
    {
        // Missing "=" but contains other garbage
        l_isValidLine = false;
        goto ERROR_EXIT;
    }
    else
    {
        // Skip the "=" and whitespace
        l_line = nextVisibleChar(l_line + 1);

        if (isNewLine(l_line[0]) ||
            isEndStr(l_line[0]))
        {
            // No parms follow "="
            l_isValidLine = false;
            goto ERROR_EXIT;
        }
    }

    // At this point the "target =" and
    //  any preceeding white space has been stripped

    // Strip off trailing white space
    removeTrailingWhiteSpace(l_line);

    // The header encoding needs to be validated for a System Target
    l_tgtTypeRc = validateSysSubstr( l_line );

    if ( l_tgtTypeRc == TARGET_TYPE_RC_SYSTEM )
    {
        // Target is system target, encoded correctly
        goto ERROR_EXIT;
    }
    else if ( l_tgtTypeRc == TARGET_TYPE_RC_ERROR )
    {
        // Bad encoding (err msg already printed)
        l_isValidLine = false;
        goto ERROR_EXIT;
    }
    else
    {
        // (chip target - keep going)
    }

    //------------------------------
    // Check for terms without values
    //------------------------------

    // Remove trailing ':' if it is the last character
    if ( l_line[strlen(l_line)-1] == ':' )
    {
        l_line[strlen(l_line)-1] = '\0';
    }

    // Skip the system string portion k0:s0
    l_line = l_line + 5;

    l_curColonPosn = strStrPos(l_line, ":");

    for ( l_nextColonPosn = 0;
          l_curColonPosn != CONST_INVALID;
          l_curColonPosn = l_nextColonPosn )
    {
        l_nextColonPosn = strStrPos(l_line + l_curColonPosn + 1, ":");
        if (l_nextColonPosn != CONST_INVALID)
        {
            l_nextColonPosn += l_curColonPosn + 1;
        }

        if ( l_nextColonPosn == CONST_INVALID)
        {
            // No colon found
            if ( (strlen(l_line) - l_curColonPosn) < 3 )
            {
                // Last term was missing a value
                // Bad encoding - need more than just a ":X"
                l_isValidLine = false;
                goto ERROR_EXIT;
            }
            else if (isspace(l_line[l_curColonPosn+1]))
            {
                // Blank follows the colon
                // Bad encoding
                l_isValidLine = false;
                goto ERROR_EXIT;
            }
            else
            {
                // (all done checking)
            }
        }

        else if ( (l_nextColonPosn - l_curColonPosn) < 3  )
        {
            // Not enough characters to hold a value
            // Bad encoding
            l_isValidLine = false;
            goto ERROR_EXIT;
        }
        else if (isspace(l_line[l_nextColonPosn+1]))
        {
            // Blank follows the colon
            // Bad encoding
            l_isValidLine = false;
            goto ERROR_EXIT;
        }
        else
        {
            // Keep looping
        }
    } // End loop thru string

    //------------------------------
    // End check for terms without values
    //------------------------------

    //------------------------------
    // Check chip targets for nonsense parms
    //------------------------------
    for ( uint32_t i = 0;
          i < ( sizeof(CHIP_TYPE_TARG_STR_TO_TYPE) /
                sizeof(CHIP_TYPE_TARG_STR_TO_TYPE[0]) );
          i++ )
    {
        TargStrToType * pEntry = &CHIP_TYPE_TARG_STR_TO_TYPE[i];

        // Entry is a processor or ocmb
        if ( (pEntry->targType == TARGETING::TYPE_PROC) ||
                (pEntry->targType == TARGETING::TYPE_OCMB_CHIP) )
        {
            // Prepend ":" to chip string to create search string
            char l_searchString[2+strlen(pEntry->pString)] = ":";
            strcat(l_searchString, pEntry->pString);

            uint32_t chipPosn = strStrPos(l_line, l_searchString);

            // Jump over the string
            uint32_t skipChipPosn;
            if ( chipPosn == CONST_INVALID )
            {
                skipChipPosn = strlen(l_line);
            }
            else
            {
                skipChipPosn = chipPosn + strlen(l_searchString);
            }

            if ( chipPosn == CONST_INVALID )
            {
                // Chip string is not in the target string
                // Keep looking
            }
            else if ( (skipChipPosn >= strlen(l_line)) ||
                      (l_line[skipChipPosn] == '.') )
            {
                // Chip string is at the end of the target string OR
                //   is followed by "."
                // Done searching thru chip strings
                break;
            }
            else
            {
                char * l_trlParmLine = l_line + skipChipPosn;

                if ( strStrPos(l_trlParmLine, ":c") != CONST_INVALID)
                {
                    // ":c" parm does not exist
                    // Bad encoding
                    l_isValidLine = false;
                    goto ERROR_EXIT;
                }
                else
                {
                    // (done searching thru chip strings)
                    break;
                }
            } // End else
        } // End processor or memory buffer
        else
        {
            // Skip entry
        }
    } // End walk thru chip targets

    //------------------------------
    // End check chip targets for nonsense parms
    //------------------------------

ERROR_EXIT:
    return l_isValidLine;
}


/**
 * @brief This function checks for no data in the pnor section then
 *        calculates the size of the pnor attr override data
 *
 * @param[in] i_pnorData    Pointer to the pnor data
 *
 * @param[out] o_dataSize   Size of attribute data
 *
 * @return errlHndl_t       Error log handle.
 */
errlHndl_t pnorAttrDataCheck( const char * i_pnorData, size_t& o_dataSize )
{
    errlHndl_t l_err = nullptr;
    o_dataSize = 0;

    // Find the end of the attribute override data by checking each byte
    // until l_pPnorAttrData is no longer pointing to an ascii char of
    // some type. Save the data size.
    do
    {
        if (isprint(*i_pnorData) ||
            isNewLine(*i_pnorData))
        {
            o_dataSize++;
        }
        else
        {
            break;
        }
        i_pnorData += 1;

    } while(1);

    if (o_dataSize == 0)
    {
        // No printable or newline ascii char found in the override data
        OVD_TRACE("Attribute Override: ***ERROR*** No printable or newline ascii char found in the override data" );
        /*@
         * @errortype
         * @moduleid  TARG_MOD_ATTR_TEXT_OVERRIDE
         * @reasoncode TARG_RC_ATTR_DATA_NOT_FOUND
         * @userdata1 <unused>
         * @userdata2 <unused>
         * @devdesc   No override data
         * @custdesc  Informational firmware error occurred
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARG_MOD_ATTR_TEXT_OVERRIDE,
                                TARG_RC_ATTR_DATA_NOT_FOUND,
                                0,
                                0,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    return l_err;
}


/**
 * @brief This function parses the attribute override text data from the
 *        PNOR and sets them in the corresponding attribute tank
 *
 * @param[in] i_sectionInfo   PNOR::SectionInfo_t to look for overrides
 *
 * @return errlHndl_t         Error log handle.
 */
errlHndl_t attrTextOverride( const PNOR::SectionInfo_t &i_sectionInfo )
{
    errlHndl_t l_err = nullptr;

    char l_trace[MAX_TRACE_LENGTH] = {0};
    g_ovd_trace = l_trace;

    // Attribute Data
    uint32_t l_attrId = 0;
    uint32_t l_targetType = 0;
    uint16_t l_pos = AttributeTank::ATTR_POS_NA;
    uint8_t l_unitPos = AttributeTank::ATTR_UNIT_POS_NA;
    uint8_t l_node = AttributeTank::ATTR_NODE_NA;
    std::vector<target_label> l_targetLabels;

    uint32_t l_valSize = 0;
    uint8_t * l_pVal = nullptr;
    bool l_const = false;
    AttributeTank::TankLayer l_tankLayer = AttributeTank::TANK_LAYER_NONE;
    std::vector<char*> l_attrLines;

    char l_curAttrString[MAX_ATTR_NAME_LENGTH] = {0};
    char l_saveAttrString[MAX_ATTR_NAME_LENGTH] = {0};
    bool l_lastLine = false;
    bool l_validTargLine = false;
    char l_line[MAX_OVD_LINE_LENGTH] = {0};
    char * l_targetLine = new char[MAX_OVD_LINE_LENGTH];
    memset(l_targetLine, 0, MAX_OVD_LINE_LENGTH);
    const char * l_pPnorAttrData = reinterpret_cast<char*>(i_sectionInfo.vaddr);
    size_t l_attrDataSize = 0;
    size_t l_lineCount = 0;
    char * l_curStrPtr = nullptr;
    bool l_addNewline = false;

    // Check for valid attribute override data in the pnor section
    // Always send a trace to the console to indicate ascii overrides
    l_err = pnorAttrDataCheck(l_pPnorAttrData, l_attrDataSize);
    if (l_err)
    {
        OVD_TRACE("Attribute Override: No ASCII attribute overrides found" );
        goto ERROR_EXIT;
    }
    if (l_attrDataSize)
    {
        OVD_TRACE("Attribute Override: Found ASCII attribute overrides" );
    }

    // In order to process the last line correctly it must end with a newline
    // character, if it does not then add it and increment the data size
    if (l_pPnorAttrData[l_attrDataSize-1] != '\n')
    {
        l_addNewline = true;
        l_attrDataSize++;
    }

    // Copy the attribute override data to a local string
    // and add the end-of-string character and newline if needed
    l_curStrPtr = new char[l_attrDataSize+1];
    memset(l_curStrPtr, 0, l_attrDataSize+1);
    strncpy(l_curStrPtr, l_pPnorAttrData, l_attrDataSize);
    l_curStrPtr[l_attrDataSize] = '\0';
    if (l_addNewline)
    {
        l_curStrPtr[l_attrDataSize-1] = '\n';
    }

    // do-while(1) loop
    // Continue until last line is detected
    do
    {
        // Reset the saved attr string and the attr lines vector
        memset(l_saveAttrString, 0, sizeof l_saveAttrString);
        l_attrLines.clear();

        // Number of chars in this line, not counting the newline char
        size_t l_newlineOffset = 0;

        // Flag to indicat we need to reprocess this line
        bool l_redoThisLine = false;

        // do-while(1) loop
        // Iterate over target + attribute lines for the same attribute. For
        // multi-dimensional attributes, there is a line for each element
        do
        {
            // Skip any leading whitespace
            l_curStrPtr = nextVisibleChar(l_curStrPtr);

            // Get the offset to the next newline
            // Ex: "any given line\n" l_newlineOffset = 14
            l_newlineOffset = strcspn(l_curStrPtr, "\n");

            // Check for last line
            // Add 1 to l_newlineOffset to account for the newline character
            if (l_newlineOffset+1 == strlen(l_curStrPtr))
            {
                l_lastLine = true;
                if ( OVERRIDE_DEBUG_ENABLED )
                {
                    OVD_TRACE("attrTextOverride: Last line");
                }
            }

            // Check the line size so we don't over-run the allocated string
            if (l_newlineOffset+1 > MAX_OVD_LINE_LENGTH)
            {
                OVD_TRACE("Attribute Override: ***ERROR*** Override line exceeds max line length %d: %s", MAX_OVD_LINE_LENGTH, l_curStrPtr );
                /*@
                 * @errortype
                 * @moduleid  TARG_MOD_ATTR_TEXT_OVERRIDE
                 * @reasoncode TARG_RC_MAX_OVD_LINE_LENGTH
                 * @userdata1 Current line size
                 * @userdata2 Max override line size
                 * @devdesc   Override line exceeds max line length
                 * @custdesc  Informational firmware error occurred
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        TARG_MOD_ATTR_TEXT_OVERRIDE,
                                        TARG_RC_MAX_OVD_LINE_LENGTH,
                                        l_newlineOffset+1,
                                        MAX_OVD_LINE_LENGTH,
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                goto ERROR_CONTINUE;
            }

            // Save this line to a separate string for processing
            strncpy(l_line, l_curStrPtr, l_newlineOffset+1);
            l_lineCount++;

            // Change the newline character to the end-of-string character
            l_line[l_newlineOffset] = '\0';

            if ( OVERRIDE_DEBUG_ENABLED )
            {
                OVD_TRACE("attrTextOverride: Line %d: %s",l_lineCount,l_line);
            }

            // Process the line.  Could be:
            //    * Target line.
            //    * Attribute line.
            //    * other line.
            if (isTargLine(l_line))
            {
                if (isEndStr(l_saveAttrString[0]))
                {
                    // Not currently processing attribute lines, save the
                    // target line, it is for following attribute lines
                    strcpy(l_targetLine, l_line);

                    l_err = convertTargLine(l_line, l_targetLine);
                    if (l_err)
                    {
                        goto ERROR_CONTINUE;
                    }

                    // Verify target line is encoded correctly
                    l_validTargLine = validateTargLine( l_targetLine );
                    if (l_validTargLine == false)
                    {
                        OVD_TRACE("Attribute Override: ***ERROR*** Override target validation failed: %s", l_targetLine );
                        /*@
                        * @errortype
                        * @moduleid  TARG_MOD_ATTR_TEXT_OVERRIDE
                        * @reasoncode TARG_RC_ATTR_TARGET_VALIDATION
                        * @userdata1 <unused>
                        * @userdata2 <unused>
                        * @devdesc   Override target validation failed
                        * @custdesc  Informational firmware error occurred
                        */
                        l_err = new ERRORLOG::ErrlEntry(
                                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                TARG_MOD_ATTR_TEXT_OVERRIDE,
                                                TARG_RC_ATTR_TARGET_VALIDATION,
                                                0,
                                                0,
                                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                        goto ERROR_CONTINUE;
                    }
                }
                else
                {
                    // Currently processing attribute lines. Break out of the
                    // loop to process the current set and redo this target
                    // line in the next iteration. Decrement the line counter.
                    l_redoThisLine = true;
                    l_lineCount--;
                    break;
                }
            }

            // Attribute line
            else if (isAttrLine(l_line))
            {
                // Remove the unused type field, i.e. u32
                removeUnusedTypeField(l_line);

                // Found an Attribute line, get the attr name
                l_err = getAttrName(l_line, l_curAttrString);
                if ( l_err )
                {
                    goto ERROR_CONTINUE;
                }

                if (isEndStr(l_saveAttrString[0]))
                {
                    // First attribute of a possible set
                    strcpy(l_saveAttrString, l_curAttrString);
                }
                else if (strcmp(l_saveAttrString, l_curAttrString) != 0)
                {
                    // This attribute is different from the current set. Break
                    // out of the loop to process the current set and redo
                    // this new attribute line in the next iteration
                    l_redoThisLine = true;
                    l_lineCount--;
                    break;
                }

                // Add the attribute line to the vector
                char * l_saveLine = nullptr;
                l_saveLine = new char[strlen(l_line)+1];
                memset(l_saveLine, 0, strlen(l_line)+1);
                strcpy(l_saveLine, l_line);
                l_attrLines.push_back(l_saveLine);

                // Reset the line string
                memset(l_line, 0, sizeof l_line);

                // Last attr read, break out and apply it
                if (l_lastLine)
                {
                    break;
                }
            }
            else
            {
                // Not a target or attribute line, skip to the next line.
                // Comment or empty line might be the last line, exit.
                if (l_lastLine)
                {
                    break;
                }
            }

            // Move pointer to the next line
            l_curStrPtr += l_newlineOffset+1;

        } while(1); // Loop through target + attrs with the same name


        if (l_attrLines.size())
        {
            // Get the attribute data for this attribute
            l_err = attrLinesToData(l_attrLines, l_attrId, l_valSize,
                                    l_pVal, l_const, l_tankLayer);
            if (l_err)
            {
                goto ERROR_CONTINUE;
            }

            // Get the Target Data for this attribute
            // Get the attribute data for this attribute
            l_err = targetLineToData(l_targetLine,
                                     l_tankLayer,
                                     l_targetType,
                                     l_targetLabels);
            if (l_err)
            {
                goto ERROR_CONTINUE;
            }

            // Figure out the attribute flags
            uint8_t l_flags = 0;
            if (l_const)
            {
                l_flags = AttributeTank::ATTR_FLAG_CONST;
            }

            // Set the data in the attribute tank AttributeHeader
            for (std::vector<target_label>::iterator it = l_targetLabels.begin();
                it != l_targetLabels.end(); ++it)
            {
                target_label l_label = *it;

                l_pos = l_label.targetPos;
                l_unitPos = l_label.unitPos;
                l_node = l_label.node;

                // Set the attribute in the override tank
                AttributeTank* l_pTargTank = &Target::theTargOverrideAttrTank();
                l_pTargTank->setAttribute( l_attrId,
                                           l_targetType,
                                           l_pos,
                                           l_unitPos,
                                           l_node,
                                           l_flags,
                                           l_valSize,
                                           l_pVal);

                if (OVERRIDE_DEBUG_ENABLED)
                {
                    // Print the override info for this attribute
                    sprintf( g_ovd_trace,
                        "\t Id: 0x%08x, TargType: 0x%08x, Pos: 0x%04x, UPos: 0x%02x",
                        l_attrId, l_targetType, l_pos, l_unitPos );
                    CONSOLE::displayf(CONSOLE::DEFAULT,"TARG",g_ovd_trace);
                    sprintf( g_ovd_trace,
                        "\t Node: 0x%02x, Flags: 0x%02x, Size: 0x%08x",
                        l_node, l_flags, l_valSize );
                    CONSOLE::displayf(CONSOLE::DEFAULT,"TARG",g_ovd_trace);
                    sprintf( g_ovd_trace, "\t Val: 0x");
                    for(uint32_t i = 0; i < l_valSize; i++)
                    {
                        sprintf(g_ovd_trace + strlen(g_ovd_trace), "%x", l_pVal[i]);
                    }
                    sprintf( g_ovd_trace + strlen(g_ovd_trace), "\n");
                    OVD_TRACE(g_ovd_trace);
                }

            }  // End of target labels

        } // End attribute line found

ERROR_CONTINUE:
        // Deallocate temp buffer as needed
        if ( l_pVal != nullptr )
        {
            delete[] l_pVal;
            l_pVal = nullptr;
        }

        // Deallocate attr data
        while ( l_attrLines.size())
        {
            char * l_attrPtr = l_attrLines.back();
            delete[] l_attrPtr;
            l_attrLines.pop_back();
        }

        // Exit check
        if ( l_lastLine && !l_redoThisLine )
        {
            break;
        }

        // Skip to the next line but only if redo is not set
        if ( !l_redoThisLine )
        {
            l_curStrPtr += l_newlineOffset+1;
        }

    } while(1); // Loop until all lines are read

ERROR_EXIT:
    g_ovd_trace = nullptr;

    return l_err;
}

} // namespace TARGETING