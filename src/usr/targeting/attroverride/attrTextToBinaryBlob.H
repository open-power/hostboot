/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attroverride/attrTextToBinaryBlob.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
//******************************************************************************
// Interface
//******************************************************************************
#include <cstring>
#include <fstream>

#define STANDALONE_COMPILE
#include <targeting/common/attributeTank.H>


namespace AttrTextToBinaryBlob
{
    /**
     * Constant for the maximum number of array dimensions an attribute can have
     */
    static const uint32_t ATTR_MAX_DIMS = 4;

    /**
     * Constant for number of 32-bit sections in an AttributeHeader struct.
     */
    static const size_t ATTR_HEADER_32_BIT_NUM_SECTIONS = 4;

    /**
     * FAPI/TARG Attribute Text files are used by an engineer to specify
     * attribute overrides and used to communicate attribute syncs between
     * Firmware and Cronus.
     *
     * These files contain :
     *  1) Target lines
     *     a) System Target line - associated attribute applies to
     *                              entire system
     *     b) Unit Target line - associated attribute applies only to
     *                            explicitly identified Unit
     *  2) Attribute Lines  (associated with the most recent target line)
     *
     * ---------------------------------------
     * The format of a System Target Line is :
     *
     *   target = <system string>
     *
     *      <system string>
     *          kx:sy[:]          note: x=0, y=0
     *
     *          Note : some additional obsolete forms have been
     *                  grandfathered in:
     *
     *          blank             note: interpreted as k0:s0
     *          kx:nz:sy[:]       note: x=0, y=0, z=0 or all
     *
     * ---------------------------------------
     * The format of a Unit Target Line is :
     *
     *   target =  <system string> || [:nz] ||
     *              :<chip type> || [.<chip unit type>] ||
     *              :<chip position> || [:<unit position>]
     *
     *       Examples:
     *         target = k0:s0:centaur:p06            // no optional fields
     *         target = k0:s0:n0:centaur.mba:p00:c0  // all optional fields
     *
     *          ---- OR ----
     *   target =  <chip type> || [.<chip unit type>] ||
     *              : <system string> || [:nz] ||
     *              :<chip position> || [:<unit position>]
     *
     *       Examples:
     *         target = centaur:k0:s0:p06            // no optional fields
     *         target = centaur.mba:k0:s0:n0:p00:c0  // all optional fields
     *
     *
     *      <system string> is defined above;  x=0, y=0
     *
     *      nz : optional node number term
     *             z may be :
     *             - single digit 0-9
     *             - comma separated list of digits 0-9
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *      <chip type>
     *         definitions :
     *           src/usr/targeting/attroverride/attrTextToBinaryBlob.C
     *           AttrOverrideSyncConstants::CHIP_TYPE_TARG_STR_TO_TYPE
     *           e.g.  p9n, pu, dimm
     *
     *      <chip unit type>
     *         definitions :
     *           src/usr/targeting/attroverride/attrTextToBinaryBlob.C
     *           AttrOverrideSyncConstants::CHIP_UNIT_TYPE_TARG_STR_TO_TYPE
     *           e.g.  ex, mca, obus
     *
     *      <chip position>
     *         pw
     *            note : w may be :
     *             - single number 0 - 65,534
     *             - comma separated list of digits 0 - 65,534
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *      <unit position>
     *         cv
     *            note : v may be :
     *             - single number 0 - 254
     *             - comma separated list of digits 0 - 254
     *                -- 2 or more items in list
     *                -- no ordering dependencies
     *                e.g. 0,4
     *                e.g. 5,3,9
     *             - all
     *
     *
     * ---------------------------------------
     * The format of an Attribute Line is:
     *
     *   <FAPI-ATTR-ID-STR>[<ARRAY-DIMS>] [<ATTR-TYPE>] <ATTR-VAL> [CONST]
     *
     *     <FAPI-ATTR-ID-STR>
     *       The FAPI Attr ID string for the attribute.
     *       defined in obj/genfiles/attributeenums.H
     *
     *     <ARRAY-DIMS>
     *       The array dimension (if any) within the attribute for this value
     *
     *     <ATTR-TYPE>
     *       The type of the attribute, uint8/16/32/64 and the array dimensions
     *       if any, this is optional
     *
     *     <ATTR-VAL>
     *       Attribute value, literal or enumerator
     *
     *     CONST
     *       If the attribute override is constant
     *
     * ---------------------------------------
     * Example:
     *   CLEAR
     *   # This is a comment
     *   target = k0:s0
     *   ATTR_SCRATCH_UINT8_1 u8 0x12
     *   ATTR_SCRATCH_UINT32_1 u32 0x12345678
     *   ATTR_SCRATCH_UINT64_1 u64 0x8000000000000001 CONST
     *
     *   target = k0:s0:n0:centaur.mba:p00:c0
     *   ATTR_MSS_FREQ 0x00000640 u32 CONST
     *   ATTR_MSS_VOLT_VDDR_MILLIVOLTS 0x00000546 u32 CONST
     *
     *   target = k0:s0:nall:p9:pall
     *   ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO -5 CONST
     *
     *   target = k0:s0:n4:centaur:p06
     *   ATTR_MSS_FREQ 0x00000345 CONST
     *
     *   target = k0:s0:n0,6,9:centaur.mba:p06:c1
     *   ATTR_MSS_FREQ 0x00000640 CONST
     *
     *   ATTR_MSS_VOLT_VDDR_MILLIVOLTS 0x00000546 u32 CONST
     *
     *   target = k0:s0:nall:p9:pall
     *   ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO -5 CONST
     *
     *   target = k0:s0:n4:centaur:p06
     *   ATTR_MSS_FREQ 0x00000345 CONST
     *
     *   target = k0:s0:n0,6,9:centaur.mba:p06:c1
     *   ATTR_MSS_FREQ 0x00000640 CONST
     *
     */


    /**
     * @brief This function writes the data from the attribute into a binary
     *        blob
     *
     * @param[in] i_attrData - Attribute header containing the attribute data
     * @param[in] i_pVal - A pointer to the value of the attribute
     * @param[in] i_tankLayer - The tank layer for the attribute
     * @param[in/out] io_attrFile - The file that will contain the binary data
     *
     * @return bool True if there was an error, False otherwise
     */
    static bool writeDataToBuffer( AttributeTank::AttributeHeader & i_attrData,
                            AttributeTank::TankLayer i_tankLayer,
                            uint8_t * i_pVal,
                            FILE * io_attrFile,
                            uint8_t *& io_buffer,
                            size_t & io_totalSize );

    /**
     * @brief This function flattens an AttributeHeader into a uint32_t array
     * with the proper endianness for the system this code is being run on
     *
     * @param[in] i_attrHeader - The AttributeHeader to flatten
     * @param[out] o_data - The array to store the data in
     *
     * @return uint32_t * - i_attrHeader as an array of uint32_t
     */
    static void flattenAttributeHeader(
                                  AttributeTank::AttributeHeader & i_attrHeader,
                                  uint32_t *& o_data );


    /**
     * @brief Returns if a line from an Attribute text file is a line describing
     *        an attribute
     *
     * @param[in]  i_line       Reference to string containing line
     * @param[out] o_attrString Filled in with the Attribute String
     *
     * @return true if the line is an attribute line
     */
    static bool attrFileIsAttrLine(
        const std::string & i_line,
        std::string & o_attrString);

    /**
     * @brief Returns if a line from an Attribute text file is a line describing
     *        a target
     *
     * @param[in] i_line Reference to string containing line
     *
     * @return true if the line is a target line
     */
    static bool attrFileIsTargLine(
        const std::string & i_line);


    /**
     * @brief This function converts obsolete format target line to
     *         current format.
     *        Will not change current format target line.
     *
     * @param[in] i_line Reference to string containing line
     * @param[out] o_convertedLine - Filled in with converted string
     *
     * @return bool True if there was an error, False otherwise
     */
    static bool convertTargLine( const std::string & i_line,
                                 std::string & o_convertedLine );

    /**
     * @brief Checks if a Target line in an Attribute text file is
     *        encoded correctly
     *
     * @param[in] i_line Reference to string containing line
     *
     * @return true if the line is a correctly encoded target line
     */
    static bool validateTargLine(
                                  const std::string & i_line );

    /**
     * @brief Checks if a valid System substring exists
     *
     * @param[in] i_line Reference to string containing line
     *
     * @return true if a valid System substring exists
     */
    enum TargetTypeRc
    {
        TargetTypeRcSystem,
        TargetTypeRcNode,
        TargetTypeRcChip,
        TargetTypeRcError
    };
    static TargetTypeRc validateSysSubstr(
                                           const std::string & i_line );

    /**
     * @brief Returns if the Binary translation is encoded correctly
     *
     * @param[in] i_buffer - The buffer containing the binary translation
     * @param[in] i_bufSize - The size of the buffer.
     *
     * @return true if the binary is correctly encoded
     */
    static bool validateBinaryXlate( const uint8_t * i_buffer,
                                     size_t  i_bufSize );

    /**
     * @brief Splits an attribute line from an Attribute text file into fields
     *
     * @param[in]  i_line       Reference to string containing line
     * @param[out] o_attrString Filled in with the Attr String
     * @param[out] o_dims       Filled in with the attribute dimensions.
     *                          Each element is 0 for unused dimensions
     * @param[out] o_valStr     Filled in with the value, this can be a literal
     *                          or an enumerrator
     * @param[out] o_const      Filled in with whether the attribute is CONST
     *                          (only used for overrides)
     *
     * @return true if the line was successfully split into fields
     */
    static bool attrFileAttrLineToFields(
        const std::string & i_line,
        std::string & o_attrString,
        size_t (& o_dims)[ATTR_MAX_DIMS],
        std::string & o_valStr,
        bool & o_const);

    /**
     * Structure for target's identification
     *
     * node         Target Node Number
     * targetPos    Target Position (chip position)
     * unitPos      Target Unit Position
     */
    struct target_label
    {
        uint8_t node;
        uint16_t targetPos;
        uint8_t unitPos;
        target_label():node(AttributeTank::ATTR_NODE_NA),
                       targetPos(AttributeTank::ATTR_POS_NA),
                       unitPos(AttributeTank::ATTR_UNIT_POS_NA){}
    };

    /**
     * @brief Helper function that updates label list
     *
     * @param[in/out] io_labels         Label list to be updated
     * @param[in]     i_label_override  Specifies override values to
     *                                   apply to each label in list
     *
     */
    static void updateLabels(std::vector<target_label> & io_labels,
                             const target_label & i_label_override);

    /**
     * @brief Converts a target line from an Attribute Text File to data
     *
     * @param[in]  i_line          Ref to string containing target line
     * @param[in]  i_tankLayer     Firmware layer containing the tank
     * @param[out] o_targetType    Target Type (as stored in tank)
     * @param[out] o_targetLabels  List of target labels
     *
     * @return - true if the target line was successfully parsed, false otherwise
     */
    static bool attrFileTargetLineToData(
        const std::string & i_line,
        const AttributeTank::TankLayer i_tankLayer,
        uint32_t & o_targetType,
        std::vector<target_label> & o_targetLabels);


    /**
     * @brief Converts a set of attribute lines (all for the same attribute)
     *        from an Attribute Text File to data
     *
     * Note that this function allocates data in o_pVal which must be freed
     * by the caller using delete[]
     *
     * @param[in]  i_lines        Ref to vector of attribute line strings
     * @param[out] o_attrId       Filled in with the attr id (as stored in tank)
     * @param[out] o_valSizeBytes Size of the attribute value
     * @param[out] o_pVal         Pointer to buffer allocated by this function
     *                            and filled in with the attribute value
     * @param[out] o_const        True if the attribute is a const override
     * @param[out] o_tankLayer    The tank layer for the current attribute
     *
     * @return bool - True if there was an error, False otherwise
     */
    static bool attrFileAttrLinesToData(
        std::vector<std::string> & i_lines,
        uint32_t & o_attrId,
        uint32_t & o_valSizeBytes,
        uint8_t * & o_pVal,
        bool & o_const,
        AttributeTank::TankLayer & o_tankLayer);

    /**
     * @brief This function checks to see if the given array has a size
     *        that is a multiple of 8 bytes. If not, add bytes up until
     *        size%8 = 0. This is needed due to injectECCs constraint on
     *        size.
     *
     * @param[in/out] io_buffer - The buffer to be potentially resized
     * @param[in/out] io_bufSize - The size of the buffer.
     */
    static void padToNextPage( uint8_t *& io_buffer,
                                         size_t & io_bufSize );




 /**
     * @brief This function retrieves the attribute data from a generated map
     *        and returns the relevant data
     *
     * @param[in] i_attrString - The name of the attribute to get the data for
     * @param[out] o_attrId - The attribute ID
     * @param[out] o_attrElemSizeBytes - The size of the element in bytes
     * @param[out] o_dims[] - an array containing the dimensional information
     *                        of the attribute
     * @param[out] o_tankLayer - The tank layer for the attribute
     * @param[in] i_attrMap - The pregenerated std::map containing the
     *                        attributeData
     *
     * @return bool - True if the attribute data was found, False otherwise.
     */
static bool getAttrDataFromMap(const char * i_attrString,
                         uint32_t & o_attrId,
                         uint32_t & o_attrElemSizeBytes,
                         size_t (& o_dims)[4],
                         AttributeTank::TankLayer & o_tankLayer);


    /**
     * @brief This function retrieves the attribute enum value from a generated
     *        map and returns that value.
     *
     * @param[in] i_attrString - The name of the attribute to get the data for
     * @param[out] o_enumVal - The value of the enum for the given attribute.
     *
     * @return bool - True if the enum value was found, False otherwise.
     */
static bool getAttrEnumDataFromMap(const char * i_attrString,
                               uint64_t & o_enumVal);




    /**
     * @brief Gets Attribute overrides/syncs from the specified file into a
     *        binary blob of attribute data
     *
     * @param[in] i_file Ref to File containing Overrides/Syncs
     * @param[in] i_injectECC Indicates whether to inject ECC
     *
     * @return bool - True if there was an error, False otherwise
     */
     static bool attrTextToBinaryBlob( std::ifstream& i_file,
                                       bool i_injectECC);

};


//Struct used to hold attribute data generated from xmltohb.pl
struct AttributeData
{
    const char* iv_name;
    uint32_t iv_attrId;
    size_t iv_attrElemSizeBytes;
    size_t iv_dims[4];
};

struct AttributeEnum
{
    const char* iv_name;
    uint64_t iv_value;
};
#include <targAttrOverrideData.H>
#include <fapi2AttrOverrideData.H>
#include <fapi2AttrOverrideEnums.H>

