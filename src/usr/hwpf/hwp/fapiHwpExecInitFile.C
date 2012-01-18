//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwp.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiHwpExecInitFile.C
 *
 *  @brief Implements a Hardware Procedure to execute an initfile.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          camvanng    09/29/2011  Created.
 *                          andrewg     11/09/2011  Multi-dimension array support
 *                          camvanng    11/16/2011  Support endianness &
 *                                                  32-bit platforms.  Support
 *                                                  system & target attributes.
 *                          camvanng    12/06/2011  Optimize code to check for
 *                                                  endianness at compile time
 *                          camvanng    01/06/2012  Support for writing an
 *                                                  attribute to a SCOM register
 */

#include <fapiHwpExecInitFile.H>
#include <fapiUtil.H>
#include <fapiAttributeService.H>
#include <string.h>
#include <vector>
#include <endian.h>
#include <stdlib.h>

extern "C"
{

//******************************************************************************
// Enumerations
//******************************************************************************

//Flag indicating ANY operand
enum IfAnyFlags
{
    IF_NOT_ANY = 0,
    IF_ANY = 1,
    IF_ONE_SIDED_ANY = 2
};

//Special variables & literals
enum IfSpecialIds
{
    IF_VAL_ANY = 0x4000,
    IF_EXPR    = 0x8000
};

/**
* Offsets of certain elements in the initfile.
*/
enum IfHeader
{
    // Initfile Header
    //-----------------
    IF_VERSION_LOC            = 0,
    IF_CVS_VERSION_LOC        = 4,
    IF_ATTR_TABLE_OFFSET_LOC   = 12,
    IF_LIT_TABLE_OFFSET_LOC   = 16,
    IF_SCOM_SECTION_OFFSET_LOC= 20,
    IF_SCOM_NUM_LOC           = 24,

    IF_VERSION_SIZE            = 4,
    IF_CVS_VERSION_SIZE        = 8,

    IF_ATTR_TABLE_OFFSET_SIZE   = 4,
    IF_LIT_TABLE_OFFSET_SIZE   = 4,
    IF_SCOM_SECTION_OFFSET_SIZE= 4,
    IF_SCOM_NUM_SIZE           = 4,

    // Supported Syntax Version
    IF_SYNTAX_VERSION          = 1,
};

//******************************************************************************
// typedefs and structs
//******************************************************************************

//RPN stack
typedef std::vector<uint64_t> rpnStack_t;

//Array Index Id container for scom data of array attribute type
typedef std::vector<uint64_t> dataArrayIdxId_t;

//InitFile address, size and current offset
typedef struct ifInfo
{
    const char * addr;
    size_t size;
    size_t offset;
}ifInfo_t;

//Attribute Symbol Table entry
typedef struct attrTableEntry
{
    uint8_t  type;
    uint32_t attrId;
}attrTableEntry_t;

//Scom Section Data entry
typedef struct scomData
{
    uint16_t   len;
    uint16_t   offset;
    uint16_t   addrId;  //numeric literal
    uint16_t   numCols;
    uint16_t   numRows;
    uint16_t * dataId;  //attribute or numeric literal
    bool       hasExpr;
    char *     colId;   //expr or an attribute
    char **    rowData;
}scomData_t;

//Init File Data
typedef struct ifData
{
    const fapi::Target *     pTarget;
    uint16_t                 numAttrs;
    uint16_t                 numLits;
    uint32_t                 numScoms;
    attrTableEntry_t *       attrs;
    uint64_t *               numericLits;
    scomData_t *             scoms;
    dataArrayIdxId_t *       dataArrayIdxId;
    rpnStack_t *             rpnStack;
}ifData_t;


//******************************************************************************
// Forward Declarations
//******************************************************************************
void ifSeek(ifInfo_t & io_ifInfo, size_t i_offset);

void ifRead(ifInfo_t & io_ifInfo, void * o_data, uint32_t i_size,
            bool i_swap = true);

void loadAttrSymbolTable(ifInfo_t & io_ifInfo,
                         ifData_t & io_ifData);

void  unloadAttrSymbolTable(ifData_t & io_ifData);

fapi::ReturnCode getAttr(const ifData_t & i_ifData,
                         const uint16_t i_id,
                         uint64_t & o_val,
                         const uint16_t i_arrayIndexIds[MAX_ATTRIBUTE_ARRAY_DIMENSION]);

void loadLitSymbolTable(ifInfo_t & io_ifInfo,
                        ifData_t & io_ifData);

void unloadLitSymbolTable(ifData_t & io_ifData);

fapi::ReturnCode getLit(const ifData_t & i_ifData,
                        const uint16_t i_id,
                        uint64_t & o_val);

void loadScomSection(ifInfo_t & io_ifInfo,
                     ifData_t & io_ifData);

void unloadScomSection(ifData_t & io_ifData);

fapi::ReturnCode executeScoms(ifData_t & io_ifData);

fapi::ReturnCode writeScom(const ifData_t & i_ifData, const uint32_t i_scomNum,
                           const uint16_t i_row);

void rpnPush(rpnStack_t * io_rpnStack, uint64_t i_val);

uint64_t rpnPop(rpnStack_t * io_rpnStack);

void rpnDumpStack(rpnStack_t * i_rpnStack);

uint64_t rpnUnaryOp(IfRpnOp i_op, uint64_t i_val, uint32_t i_any);

uint64_t rpnBinaryOp(IfRpnOp i_op, uint64_t i_val1, uint64_t i_val2,
                     uint32_t i_any);

fapi::ReturnCode rpnDoPush(ifData_t & io_ifData, const uint16_t i_id,
                           uint32_t & io_any, const uint16_t i_arrayIndexIds[MAX_ATTRIBUTE_ARRAY_DIMENSION]);

fapi::ReturnCode rpnDoOp(rpnStack_t * io_rpnStack, IfRpnOp i_op,
                         uint32_t i_any);

fapi::ReturnCode evalRpn(ifData_t & i_ifData, char * i_expr, uint32_t i_len,
                         bool i_hasExpr = false);


//******************************************************************************
// fapiHwpExecInitFile function
//******************************************************************************

/**  @brief Execute the initfile
 *
 * This HWP can be called to execute a binary initfile.
 *
 * @param[in] i_Target  Reference to fapi::Target
 * @param[in] i_file    The binary if filename: <initfile>.if
 *
 * @return ReturnCode. Zero on success.
 */
fapi::ReturnCode fapiHwpExecInitFile(const fapi::Target & i_Target,
                                     const char * i_file)
{
    FAPI_INF(">> fapiHwpExecInitFile: Performing HWP for %s", i_file);

    // Print the ecmd string of the chip
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    i_Target.toString(l_string);
    FAPI_INF("fapiHwpExecInitFile: Target: %s", l_string);

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    fapi::ReturnCode l_tmpRc = fapi::FAPI_RC_SUCCESS;
    size_t l_ifSize = 0;
    const char * l_ifAddr = NULL;

    // Load the binary initfile
    l_rc = fapiLoadInitFile(i_Target, i_file, l_ifAddr, l_ifSize);

    if (l_rc.ok())
    {
        FAPI_DBG("fapiHwpExecInitFile: data module addr = %p, size = %u",
                          l_ifAddr, l_ifSize);

        //Save the data
        ifInfo_t l_ifInfo;
        memset(&l_ifInfo, 0, sizeof(ifInfo_t));
        l_ifInfo.addr = l_ifAddr;
        l_ifInfo.size = l_ifSize;
        l_ifInfo.offset = IF_VERSION_LOC;

        //Check endianness
        #ifdef __BYTE_ORDER
            #if (__BYTE_ORDER == __BIG_ENDIAN)
                FAPI_INF("fapiHwpExecInitFile: big endian mode");
            #elif (__BYTE_ORDER == __LITTLE_ENDIAN)
                FAPI_INF("fapiHwpExecInitFile: little endian mode");
            #else
            #error "Unknown byte order"
            #endif
        #else
        #error "Byte order not defined"
        #endif
        
        //Check the version
        uint32_t l_version;
        ifRead(l_ifInfo, reinterpret_cast<void*>(&l_version), IF_VERSION_SIZE);

        if (IF_SYNTAX_VERSION != l_version)
        {
            FAPI_ERR("fapiHwpExecInitFile: %s Syntax version %u Expected version %u",
                i_file, l_version, IF_SYNTAX_VERSION);

            uint32_t & FFDC_IF_VER = l_version; // GENERIC IDENTIFIER
            FAPI_SET_HWP_ERROR(l_rc, RC_INITFILE_INCORRECT_VER);

            // Unload the initfile, disregard this rc
            l_tmpRc = fapiUnloadInitFile(i_file, l_ifAddr, l_ifSize);
            if (!l_tmpRc.ok())
            {
                //Log error
                fapiLogError(l_tmpRc);
            }
        }
        else
        {
            char l_cvsVersion[IF_CVS_VERSION_SIZE];
            ifRead(l_ifInfo, reinterpret_cast<void*>(&l_cvsVersion), IF_CVS_VERSION_SIZE);

            FAPI_IMP("fapiHwpExecInitFile: %s Syntax version %u CVS version %s",
                i_file, l_version, l_cvsVersion);

            ifData_t l_ifData;
            memset(&l_ifData, 0, sizeof(ifData_t));

            dataArrayIdxId_t l_dataArrayIdxId;
            l_ifData.dataArrayIdxId = &l_dataArrayIdxId;

            //--------------------------------
            // Load the Attribute Symbol Table
            //--------------------------------
            loadAttrSymbolTable(l_ifInfo, l_ifData);
            FAPI_DBG("fapiHwpExecInitFile: Addr of attribute struct %p, "
                     "num attrs %u", l_ifData.attrs, l_ifData.numAttrs);

            //--------------------------------
            // Load the Literal Symbol Table
            //--------------------------------
            loadLitSymbolTable(l_ifInfo, l_ifData);
            FAPI_DBG("fapiHwpExecInitFile: Addr of literal struct %p, "
                     "num lits %u", l_ifData.numericLits, l_ifData.numLits);

            //--------------------------------
            // Load the SCOM Section
            //--------------------------------
            loadScomSection(l_ifInfo, l_ifData);
            FAPI_DBG("fapiHwpExecInitFile: Addr of scom struct %p, "
                     "num scoms %u", l_ifData.scoms, l_ifData.numScoms);

            //--------------------------------
            // Execute SCOMs
            //--------------------------------
            l_ifData.pTarget = &i_Target;

            l_rc = executeScoms(l_ifData);

            //--------------------------------
            // Unload
            //--------------------------------

            // Unload the data array index id container
            l_dataArrayIdxId.clear();
            l_ifData.dataArrayIdxId = NULL;

            // Unload the Attribute Symbol Table
            unloadAttrSymbolTable(l_ifData);

            // Unload the Literal Symbol Table
            unloadLitSymbolTable(l_ifData);

            // Unload the Scom Section
            unloadScomSection(l_ifData);
        }

        // Unload the initfile
        l_tmpRc = fapiUnloadInitFile(i_file, l_ifAddr, l_ifSize);

        // return code from executeScoms takes precedence
        if (l_rc.ok())
        {
            l_rc = l_tmpRc;
        }
        else if (!l_tmpRc.ok())
        {
            //Log error
            fapiLogError(l_tmpRc);
        }
    }

    FAPI_INF("<< fapiHwpExecInitFile: Performing HWP for %s", i_file);
    return l_rc;
}


//******************************************************************************
// Helper functions to read initfiles
//******************************************************************************

/**  @brief Seek to the specified offset in the binary initfile
 *
 * Seeks from the start of the file to the position passed in.
 *
 * @param[in,out] io_ifInfo   Reference to ifInfo_t which contains addr, size,
 *                            and current offset of the initfile
 * @param[in]     i_offset    Position to seek to.
 */
void ifSeek(ifInfo_t & io_ifInfo, size_t i_offset)
{
    if (i_offset > io_ifInfo.size)
    {
        FAPI_ERR("fapiHwpExecInitFile: ifSeek: offset out of range 0x%X", i_offset);

        fapiAssert(false);
    }

    //Advance the offset
    io_ifInfo.offset = i_offset;
}

/**  @brief Reads the initfile
 *
 * Reads the binary initfile at the current offset.
 *
 * @param[in,out] io_ifInfo   Reference to ifInfo_t which contains addr, size,
 *                            and current offset of the initfile
 * @param[out] o_data         Ptr to buffer where data read will be stored
 * @param[in] i_size          number of bytes to read (1, 2, 4 or 8 bytes)
 * @param[in] i_swap          If true, will swap bytes to account for endianness if needed.
 */
void ifRead(ifInfo_t & io_ifInfo, void * o_data, uint32_t i_size, bool i_swap)
{
    if (!((1 == i_size) || (2 == i_size) || (4 == i_size) || (8 == i_size)))
    {
        FAPI_ERR("fapiHwpExecInitFile: ifRead: invalid number of bytes %d", i_size);
        fapiAssert(false);
    }

    if ((io_ifInfo.offset + i_size) > io_ifInfo.size)
    {
        FAPI_ERR("fapiHwpExecInitFile: ifRead: offset 0x%X + size 0x%X out of range",
                 io_ifInfo.offset, i_size);

        fapiAssert(false);
    }

    //Copy the data
    #if (__BYTE_ORDER == __LITTLE_ENDIAN)
    if ((1 < i_size) && (true == i_swap))
    {
        //Account for endianness
        const char * l_pSrc = io_ifInfo.addr + io_ifInfo.offset + i_size - 1;
        char * l_pDst = static_cast<char *>(o_data);
        do
        {
            *l_pDst = *l_pSrc;
            l_pSrc--;
            l_pDst++;
        } while (l_pSrc >= io_ifInfo.addr + io_ifInfo.offset);
    }
    else
    {
        memcpy(o_data, io_ifInfo.addr + io_ifInfo.offset, i_size);
    }
    #else
    memcpy(o_data, io_ifInfo.addr + io_ifInfo.offset, i_size);
    #endif

    //Advance the offset
    io_ifInfo.offset += i_size;
}

//******************************************************************************
// Helper functions for Attributes
//******************************************************************************

/**  @brief Loads the Attribute Symbol Table
 *
 * Loads the Attribute Symbol Table from the binary initfile.
 *
 * @param[in,out] io_ifInfo   Reference to ifInfo_t which contains addr, size,
 *                            and current offset of the initfile
 * @param[in,out] io_ifData   Reference to ifData_t which contains initfile data
 */
void loadAttrSymbolTable(ifInfo_t & io_ifInfo,
                         ifData_t & io_ifData)
{
    FAPI_DBG(">> fapiHwpExecInitFile: loadAttrSymbolTable");

    attrTableEntry_t * l_attrs = NULL;
    uint16_t l_numAttrs = 0;
    uint32_t l_attrTableOffset = 0;

    //Seek to the Attribute Symbol Table offset
    ifSeek(io_ifInfo, IF_ATTR_TABLE_OFFSET_LOC);

    //Read the offset to the Attribute Symbol Table
    ifRead(io_ifInfo, &l_attrTableOffset, IF_ATTR_TABLE_OFFSET_SIZE);

    //Seek to the Attribute Symbol Table
    ifSeek(io_ifInfo, l_attrTableOffset);

    //Read the number of attributes
    ifRead(io_ifInfo, &l_numAttrs, sizeof(l_numAttrs));
    FAPI_DBG("loadAttrSymbolTable: Offset of Attr Symbol Table 0x%X "
             "num attrs %u", l_attrTableOffset, l_numAttrs);

    //Now read the individual attribute entry
    if (0 < l_numAttrs)
    {
        //Allocate memory to hold the attribute data
        l_attrs = reinterpret_cast<attrTableEntry_t *>
            (malloc(l_numAttrs * sizeof(attrTableEntry_t)));
        memset(l_attrs, 0, l_numAttrs * sizeof(attrTableEntry_t));

        for (uint16_t i = 0; i < l_numAttrs; i++)
        {
            //Read the attribute type
            ifRead(io_ifInfo, &(l_attrs[i].type), sizeof(l_attrs[i].type));

            //Read the attribute id
            ifRead(io_ifInfo, &(l_attrs[i].attrId), sizeof(l_attrs[i].attrId));

            FAPI_DBG("loadAttrSymbolTable: attr[%u]: type 0x%x, id 0x%x",
                     i, l_attrs[i].type, l_attrs[i].attrId);
        }
    }

    io_ifData.attrs = l_attrs;
    io_ifData.numAttrs = l_numAttrs;

    FAPI_DBG("<< fapiHwpExecInitFile: loadAttrSymbolTable");
}

/**  @brief Unloads the Attribue Symbol Table from memory
 *
 * Unloads the Attribute Symbol Table from memory
 *
 * @param[in, out] i_ifData   Reference to ifData_t which contains initfile data
 */
void unloadAttrSymbolTable(ifData_t & io_ifData)
{
    FAPI_DBG("fapiHwpExecInitFile: unloadAttrSymbolTable");
    // Deallocate memory
    free(io_ifData.attrs);
    io_ifData.attrs = NULL;
}

/**  @brief Get an InitFile attribute value
 *
 * This function gets a copy of an attribute. In the case of an array attribute,
 * The value in the specified index is retrieved.
 *
 * If there are ever attributes with more than 4 dimensions then this function
 * will need to be updated.
 *
 * @param[in]  i_ifData        Reference to ifData_t which contains initfile data
 * @param[in]  i_id            AttributeID
 * @param[out] o_val           Reference to uint64_t where attribute value is set
 * @param[in]  i_arrayIndexIds Array of attribute array index's (when needed)
 *
 * @return ReturnCode. Zero if success.
 */
//******************************************************************************
fapi::ReturnCode getAttr(const ifData_t & i_ifData,
                         const uint16_t i_id,
                         uint64_t & o_val,
                         const uint16_t i_arrayIndexIds[MAX_ATTRIBUTE_ARRAY_DIMENSION])
{
    FAPI_DBG(">> fapiHwpExecInitFile: getAttr: id 0x%x",
             i_id);

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;

    //Mask out the type & system bits and zero-base
    uint16_t l_id = (i_id & IF_ATTR_ID_MASK) - 1;
    FAPI_DBG("fapiHwpExecInitFile: getAttr: id %u", l_id);

    if (l_id < i_ifData.numAttrs)
    {
        const fapi::Target * l_pTarget = i_ifData.pTarget;

        if (i_id & IF_SYS_ATTR_MASK)
        {
            l_pTarget = NULL;
        }

        fapi::AttributeId l_attrId =
            static_cast<fapi::AttributeId>(i_ifData.attrs[l_id].attrId);
        FAPI_DBG("fapiHwpExecInitFile: getAttr: attrId %u", l_attrId);

        l_rc = fapi::fapiGetInitFileAttr(l_attrId, l_pTarget, o_val,
                                         i_arrayIndexIds[0], i_arrayIndexIds[1],
                                         i_arrayIndexIds[2], i_arrayIndexIds[3]);

        if (l_rc)
        {
            FAPI_ERR("fapiHwpExecInitFile: getAttr: GetInitFileAttr failed rc 0x%x",
                     static_cast<uint32_t>(l_rc));
        }
        else
        {
            FAPI_DBG("fapiHwpExecInitFile: getAttr: val 0x%.16llx", o_val);
        }
    }
    else
    {
        FAPI_ERR("fapiHwpExecInitFile: getAttr: id out of range");

        uint32_t l_ffdc = i_id;
        uint32_t & FFDC_IF_ATTR_ID_OUT_OF_RANGE = l_ffdc; // GENERIC IDENTIFIER
        FAPI_SET_HWP_ERROR(l_rc, RC_INITFILE_ATTR_ID_OUT_OF_RANGE);
    }

    FAPI_DBG("<< fapiHwpExecInitFile: getAttr");
    return l_rc;
}


//******************************************************************************
// Helper functions for Literals
//******************************************************************************

/**  @brief Loads the Literal Symbol Table
 *
 * Loads the Literal Symbol Table from the binary initfile.
 *
 * @param[in,out] io_ifInfo   Reference to ifInfo_t which contains addr, size,
 *                            and current offset of the initfile
 * @param[in,out] io_ifData   Reference to ifData_t which contains initfile data
 */
void loadLitSymbolTable(ifInfo_t & io_ifInfo,
                        ifData_t & io_ifData)
{
    FAPI_DBG(">> fapiHwpExecInitFile: loadLitSymbolTable");

    uint64_t * l_numericLits = NULL;
    uint16_t l_numLits = 0;
    uint32_t l_litTableOffset = 0;

    //Seek to the Literal Symbol Table offset
    ifSeek(io_ifInfo, IF_LIT_TABLE_OFFSET_LOC);

    //Read the offset to the Literal Symbol Table
    ifRead(io_ifInfo, &l_litTableOffset, IF_LIT_TABLE_OFFSET_SIZE);

    //Seek to the Literal Symbol Table
    ifSeek(io_ifInfo, l_litTableOffset);

    //Read the number of literals
    ifRead(io_ifInfo, &l_numLits, sizeof(l_numLits));
    FAPI_DBG("loadLitSymbolTable: Offset of Literal Symbol Table 0x%X "
             "num literals %u", l_litTableOffset, l_numLits);

    if (0 < l_numLits)
    {
        //Now read the individual literal entry

        uint8_t l_litSize = 0;

        l_numericLits =
            reinterpret_cast<uint64_t *>(malloc(l_numLits * sizeof(uint64_t)));
        memset(l_numericLits, 0, l_numLits * sizeof(uint64_t));

        for (uint16_t i = 0; i < l_numLits; i++)
        {
            //Read the literal size in bytes
            ifRead(io_ifInfo, &l_litSize, sizeof(l_litSize));

            if ((l_litSize > 0) && (l_litSize <= sizeof(uint64_t)))
            {
                //Read the literal value
                ifRead(io_ifInfo, &(l_numericLits[i]), l_litSize);

                #if (__BYTE_ORDER == __BIG_ENDIAN)
                //In big endian mode, if the literal is less then 8 bytes,
                //need to right justify so it is a regular 64-byte number.
                //In little endian mode, the bytes are swapped by ifRead()
                //so the literal is already justified.
                l_numericLits[i] >>= (64 - (l_litSize * 8));
                #endif

                FAPI_DBG("loadLitSymbolTable: lit[%u]: size 0x%x, value 0x%016llx",
                         i, l_litSize, l_numericLits[i]);
            }
            else
            {
                //Expect nonzero literal size of 1 to 8 bytes
                FAPI_ERR("loadLitSymbolTable: lit[%u]:  invalid size %u",
                         i, l_litSize);
                fapiAssert(false);
            }
        }
    }

    io_ifData.numericLits = l_numericLits;
    io_ifData.numLits = l_numLits;

    FAPI_DBG("<< fapiHwpExecInitFile: loadLitSymbolTable");
}

/**  @brief Unloads the Literal Symbol Table from memory
 *
 * Unloads the Literal Symbol Table from memory
 *
 * @param[in, out] i_ifData   Reference to ifData_t which contains initfile data
 */
void unloadLitSymbolTable(ifData_t & io_ifData)
{
    FAPI_DBG("fapiHwpExecInitFile: unloadLitSymbolTable");

    // Deallocate memory
    free(io_ifData.numericLits);
    io_ifData.numericLits = NULL;
}

/**  @brief Get an InitFile numeric literal value
 *
 * This function gets a copy of a numeric literal.
 *
 * @param[in]  i_ifData      Reference to ifData_t which contains initfile data
 * @param[in]  i_id          Numeric Literal id
 * @param[out] o_val         Reference to uint64_t where literal value is set
 *
 * @return ReturnCode. Zero if success.
 */
//******************************************************************************
fapi::ReturnCode getLit(const ifData_t & i_ifData,
                        const uint16_t i_id,
                        uint64_t & o_val)
{
    FAPI_DBG(">> fapiHwpExecInitFile: getLit: id 0x%X", i_id);

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;

    //Mask out the type bits and zero-base
    uint16_t l_id = (i_id & (~IF_TYPE_MASK)) - 1;

    if (l_id < i_ifData.numLits)
    {
        o_val = i_ifData.numericLits[l_id];
        FAPI_DBG("fapiHwpExecInitFile: getLit: val 0x%.16llX", o_val);
    }
    else
    {
        FAPI_ERR("fapiHwpExecInitFile: getLit: id out of range");

        uint32_t l_ffdc = i_id;
        uint32_t & FFDC_IF_LIT_ID_OUT_OF_RANGE = l_ffdc; // GENERIC IDENTIFIER
        FAPI_SET_HWP_ERROR(l_rc, RC_INITFILE_LIT_ID_OUT_OF_RANGE);
    }

    return l_rc;
}


//******************************************************************************
// Helper functions for Scoms
//******************************************************************************

/**  @brief Loads the Scom Section
 *
 * Loads the Scom Section from the binary initfile.
 *
 * @param[in,out] io_ifInfo   Reference to ifInfo_t which contains addr, size,
 *                            and current offset of the initfile
 * @param[in,out] io_ifData   Reference to ifData_t which contains initfile data
 */
void loadScomSection(ifInfo_t & io_ifInfo,
                     ifData_t & io_ifData)
{
    FAPI_DBG(">> fapiHwpExecInitFile: loadScomSection");

    scomData_t * l_scoms = NULL;
    uint32_t l_numScoms = 0;
    uint32_t l_scomSectionOffset = 0;

    //Seek to the Scom Section offset
    ifSeek(io_ifInfo, IF_SCOM_SECTION_OFFSET_LOC);

    //Read the offset to the Scom Section
    ifRead(io_ifInfo, &l_scomSectionOffset, IF_SCOM_SECTION_OFFSET_SIZE);

    //Read the number of Scoms
    ifRead(io_ifInfo, &l_numScoms, sizeof(l_numScoms));
    FAPI_DBG("loadScomSection: Offset of Scom Section 0x%X "
             "num scoms %u", l_scomSectionOffset, l_numScoms);

    //Seek to the Scom Section
    ifSeek(io_ifInfo, l_scomSectionOffset);

    if (0 < l_numScoms)
    {
        //------------------------------------
        //Now read the individual SCOM entry
        //------------------------------------

        //Allocate memory to hold the data
        l_scoms = reinterpret_cast<scomData_t *>(malloc(l_numScoms * sizeof(scomData_t)));
        memset(l_scoms, 0, l_numScoms * sizeof(scomData_t));

        for (uint32_t i = 0; i < l_numScoms; i++)
        {
            //Read the SCOM len
            ifRead(io_ifInfo, &(l_scoms[i].len), sizeof(l_scoms[i].len));

            //Read the SCOM offset
            ifRead(io_ifInfo, &(l_scoms[i].offset), sizeof(l_scoms[i].offset));

            //Read the SCOM address id
            ifRead(io_ifInfo, &(l_scoms[i].addrId), sizeof(l_scoms[i].addrId));

            //Expect numeric literal id, 1-based
            if ( ! ((IF_NUM_TYPE == (l_scoms[i].addrId & IF_TYPE_MASK)) &&
                (IF_NUM_TYPE < l_scoms[i].addrId)) )
            {
                FAPI_ERR("loadScomSection: scom[%u]: addrId not a numeric "
                         "literal", i);
                fapiAssert(false);
            }

            //Read the number of columns
            ifRead(io_ifInfo, &(l_scoms[i].numCols), sizeof(l_scoms[i].numCols));

            //Read the number of rows
            ifRead(io_ifInfo, &(l_scoms[i].numRows), sizeof(l_scoms[i].numRows));

            FAPI_DBG("loadScomSection: scom[%u]: len %u, offset %u",
                     i, l_scoms[i].len, l_scoms[i].offset);
            FAPI_DBG("loadScomSection: addr id 0x%x, #cols %u, #rows %u",
                     l_scoms[i].addrId, l_scoms[i].numCols,
                     l_scoms[i].numRows);

            //Expect at least one row
            if (0 >= l_scoms[i].numRows)
            {
                FAPI_ERR("loadScomSection: scom[%u]: num rows %u <= 0",
                         i, l_scoms[i].numRows);
                fapiAssert(false);
            }

            //-----------------------------------
            //Read the scom data ids
            //-----------------------------------

            //Allocate memory to hold the data ids; i.e. attribute or numeric literal ids
            l_scoms[i].dataId =
                reinterpret_cast<uint16_t*>(malloc(l_scoms[i].numRows * sizeof(uint16_t*)));
            memset(l_scoms[i].dataId, 0,
                l_scoms[i].numRows * sizeof(uint16_t*));

            //Read the data ids
            for (uint16_t j = 0; j < l_scoms[i].numRows; j++)
            {
                ifRead(io_ifInfo, &(l_scoms[i].dataId[j]),
                       sizeof(l_scoms[i].dataId[j]));

                FAPI_DBG("loadScomSection: scom[%u]: dataId[%u] 0x%02x",
                         i, j, l_scoms[i].dataId[j]);

                //Check for attribute of array type
                if ((l_scoms[i].dataId[j] & IF_TYPE_MASK) == IF_ATTR_TYPE)
                {
                    //Mask out the type & system bits and zero-based
                    uint16_t l_id = (l_scoms[i].dataId[j] & IF_ATTR_ID_MASK) - 1;
                    if (l_id < io_ifData.numAttrs)
                    {
                        // Get the attribute dimension & shift it to the LS nibble
                        uint8_t l_attrDimension =
                            io_ifData.attrs[l_id].type & ATTR_DIMENSION_MASK;
                        l_attrDimension = l_attrDimension >> 4;

                        FAPI_DBG("loadScomSection: data is an attribute of "
                                 "dimension %u", l_attrDimension);

                        // Read out all dimensions for the attribute
                        for(uint8_t k = 0; k < l_attrDimension; k++)
                        {
                            // Save the array index id
                            uint16_t l_idxId = 0;
                            ifRead(io_ifInfo, &l_idxId, sizeof(uint16_t));
                            io_ifData.dataArrayIdxId->push_back(static_cast<uint64_t>(l_idxId));
                            FAPI_DBG("loadScomSection: array index id %u",
                                     io_ifData.dataArrayIdxId->back());
                        }
                    }
                    else
                    {
                        FAPI_ERR("loadScomSection: scom[%u]: dataId[%u] 0x%02x:"
                                 " index id 0x%02x out of range", i, j,
                                 l_scoms[i].dataId[j], l_id);
                        fapiAssert(false);
                    }
                }
            }

            // Set to default
            l_scoms[i].hasExpr = false;

            //-----------------------------------
            //Load the column data
            //-----------------------------------
            if (0 < l_scoms[i].numCols)
            {
                //Allocate memory to hold the column data
                l_scoms[i].colId =
                    reinterpret_cast<char *>(malloc(l_scoms[i].numCols * sizeof(uint16_t)));
                memset(l_scoms[i].colId, 0,
                    l_scoms[i].numCols * sizeof(uint16_t));

                //Read Column Id
                uint16_t l_colId = 0;
                char *l_pCol = l_scoms[i].colId;
                for (uint16_t j = 0; j < l_scoms[i].numCols; j++)
                {
                    //Don't swap the bytes - colId is parsed by bytes later in code.
                    ifRead(io_ifInfo, l_pCol, sizeof(uint16_t), false);
                    l_colId = *l_pCol++ << 8;
                    l_colId |= *l_pCol++;

                    FAPI_DBG("loadScomSection: scom[%u]: colId[%u] "
                             "0x%02x", i, j, l_colId);
                }

                //Is the last column an EXPR column
                if (IF_EXPR == l_colId)
                {
                    FAPI_DBG("loadScomSection: scom[%u]: has expression", i);
                    l_scoms[i].hasExpr = true;
                }
            }

            //-----------------------------------
            //Load the row data for each columns
            //-----------------------------------
            if (0 == l_scoms[i].numCols)
            {
                // Set the row data ptr to NULL & discard 1-byte row size
                l_scoms[i].rowData = NULL;
                ifSeek(io_ifInfo, io_ifInfo.offset + 1);
            }
            else
            {
                //Allocate memory to hold the row data
                l_scoms[i].rowData =
                    reinterpret_cast<char**>(malloc(l_scoms[i].numRows * sizeof(char**)));
                memset(l_scoms[i].rowData, 0,
                    l_scoms[i].numRows * sizeof(char**));

                // Determine the number of simple columns (not an expr columns)
                uint16_t l_numSimpleCols = l_scoms[i].numCols;
                if (l_scoms[i].hasExpr)
                {
                    l_numSimpleCols--;
                }

                //Read the row data for each row
                uint8_t l_rowSize = 0;
                char * l_rowPtr = NULL;
                uint32_t c;

                for (uint16_t j = 0; j < l_scoms[i].numRows; j++)
                {
                    //Read the row size; i.e. # of bytes
                    ifRead(io_ifInfo, &l_rowSize, sizeof(l_rowSize));

                    //Expect non-zero row size
                    if (0 >= l_rowSize)
                    {
                        FAPI_ERR("loadScomSection: scom[%u]: row size %u",
                                 i, l_rowSize);
                        fapiAssert(false);
                    }

                    //If have expr column, need another byte to store its length
                    if (l_scoms[i].hasExpr)
                    {
                        l_rowSize++;
                    }

                    //Allocate the space
                    l_scoms[i].rowData[j] = reinterpret_cast<char *>(malloc(l_rowSize));
                    l_rowPtr = l_scoms[i].rowData[j];

                    //Read in the simple column entries in the rows
                    for (uint16_t k = 0; k < l_numSimpleCols; k++)
                    {
                        //Keep reading in data until we hit a non push, which
                        //would be an operator
                        while (1)
                        {
                            //Read the first byte of the Push, or an operator
                            ifRead(io_ifInfo, l_rowPtr, sizeof(char));
                            FAPI_DBG("loadScomSection: scom[%u]: rowData[%u] "
                                     "0x%02x", i, j, *l_rowPtr);

                            c = *l_rowPtr++;
                            l_rowSize--;

                            //If it's not a push, then it must be an operator,
                            //so we're done
                            if (!(c & PUSH_MASK))
                            {
                                break;
                            }

                            //It was a push, so read in the 2nd byte of it
                            ifRead(io_ifInfo, l_rowPtr, sizeof(char));
                            FAPI_DBG("loadScomSection: scom[%u]: rowData[%u] "
                                     "0x%02x", i, j, *l_rowPtr);
                            l_rowPtr++;
                            l_rowSize--;
                        }
                    }

                    //After the simple columns comes the expression column,
                    //if present
                    if (l_scoms[i].hasExpr)
                    {
                        l_rowSize--;
                        *l_rowPtr = l_rowSize; //Save the length of the expr
                        FAPI_DBG("loadScomSection: scom[%u]: rowData[%u] "
                                 "expr len 0x%02x", i, j, *l_rowPtr);
                        l_rowPtr++;

                        //Read in the rest of the expression, which goes to the
                        //end of the row
                        while (l_rowSize--)
                        {
                            ifRead(io_ifInfo, l_rowPtr, sizeof(char));
                            FAPI_DBG("loadScomSection: scom[%u]: rowData[%u] "
                                     "0x%02x", i, j, *l_rowPtr);
                            l_rowPtr++;
                        }
                    }
                }
            }
        }
    }

    io_ifData.scoms = l_scoms;
    io_ifData.numScoms = l_numScoms;

    FAPI_DBG("<< fapiHwpExecInitFile: loadScomSection");
}

/**  @brief Unloads the Scom Section from memory
 *
 * @param[in, out] i_ifData   Reference to ifData_t which contains initfile data
 */
void unloadScomSection(ifData_t & io_ifData)
{
    FAPI_DBG(">> fapiHwpExecInitFile: unloadScomSection");

    //Deallocate memory
    for (uint32_t i = 0; i < io_ifData.numScoms; i++)
    {
        free(io_ifData.scoms[i].dataId);
        io_ifData.scoms[i].dataId = NULL;

        free(io_ifData.scoms[i].colId);
        io_ifData.scoms[i].colId = NULL;

        if (NULL != io_ifData.scoms[i].rowData)
        {
            for (uint16_t j = 0; j < io_ifData.scoms[i].numRows; j++)
            {
                free(io_ifData.scoms[i].rowData[j]);
                io_ifData.scoms[i].rowData[j] = NULL;
            }

            free(io_ifData.scoms[i].rowData);
            io_ifData.scoms[i].rowData = NULL;
        }
    }

    free(io_ifData.scoms);
    io_ifData.scoms = NULL;

    FAPI_DBG("<< fapiHwpExecInitFile: unloadScomSection");
}

/**  @brief Execute the Scom Section
 *
 * @param[in] i_ifData   Reference to ifData_t which contains initfile data
 *
 * @return ReturnCode. Zero if success.
 */
fapi::ReturnCode executeScoms(ifData_t & i_ifData)
{
    FAPI_INF(">> fapiHwpExecInitFile: executeScoms");

    fapi::ReturnCode l_rc;
    uint16_t l_numSimpleCols = 0;
    uint8_t l_len = 0;
    char * l_rowExpr = NULL;
    char * l_colExpr = NULL;
    uint16_t l_row;
    bool l_goToNextRow = false;
    rpnStack_t l_rpnStack;
    uint64_t result = 0;

    //Create RPN stack
    l_rpnStack.reserve(128);

    i_ifData.rpnStack = &l_rpnStack;

    for (uint32_t i = 0; i < i_ifData.numScoms; i++)
    {
        //Get the number of simple columns
        l_numSimpleCols = i_ifData.scoms[i].numCols;
        if (i_ifData.scoms[i].hasExpr)
        {
            l_numSimpleCols--;
        }

        FAPI_DBG("fapiHwpExecInitFile: executeScoms: #simple cols %u",
                 l_numSimpleCols);

        for (l_row = 0; l_row < i_ifData.scoms[i].numRows; l_row++)
        {
            //Nothing to check if there are no columns
            //We found a row match
            if ((0 == i_ifData.scoms[i].numCols) ||
                (NULL == i_ifData.scoms[i].rowData))
            {
                FAPI_DBG("fapiHwpExecInitFile: executeScoms: no cols");
                break;
            }

            //Get a pointer to the row expressions
            l_rowExpr = i_ifData.scoms[i].rowData[l_row];

            //Get a pointer to the column expressions
            if (l_numSimpleCols > 0)
            {
                l_colExpr = i_ifData.scoms[i].colId;
            }

            //Evaluate the simple columns (not the 'expr' column)
            for (uint16_t col= 0; col < l_numSimpleCols; col++)
            {
                //This will always be a push
                l_rc = evalRpn(i_ifData, l_colExpr, 2);

                if (l_rc)
                {
                    FAPI_ERR("fapiHwpExecInitFile: Simple Column evalRpn failed");
                    break;
                }

                l_colExpr++; //advance past calculation

                //This might be several pushes or just a push and an operator,
                //so loop to read in the pushes
                //An OP marks the end of a simple column RPN
                while (static_cast<uint32_t>(*l_rowExpr) & PUSH_MASK)
                {
                    // PUSH  (SYMBOL)  always 2 bytes
                    l_rc = evalRpn(i_ifData, l_rowExpr, 2);

                    if (l_rc)
                    {
                        FAPI_ERR("fapiHwpExecInitFile: Simple Column evalRpn failed"
                                 " on scom 0x%X", i_ifData.scoms[i].addrId);
                        break;
                    }

                    l_rowExpr += 2; //advance past the calculation
                }

                if (l_rc)
                {
                    break;
                }

                //If the op is TRUE_OP or FALSE_OP then pop the extra column
                //symbol off the Rpn stack since it won't be consumed by the OP
                if((*l_rowExpr == FALSE_OP) || (*l_rowExpr == TRUE_OP))
                {
                    //Unconditional OP; throw pushed COL symbol away
                    rpnPop(i_ifData.rpnStack);
                    FAPI_DBG("fapiHwpExecInitFile: executeScoms: True or False op");
                }

                l_rc = evalRpn(i_ifData, l_rowExpr, 1);
                l_rowExpr++;

                if (l_rc)
                {
                    FAPI_ERR("fapiHwpExecInitFile: Simple Column evalRpn failed on "
                             "scom 0x%X", i_ifData.scoms[i].addrId);
                    break;
                }

                result = rpnPop(i_ifData.rpnStack);
                FAPI_DBG("fapiHwpExecInitFile: executeScoms: Simple Col: result 0x%llX",
                         result);

                //If zero, continue on to the next row.
                if (0 == result)
                {
                  l_goToNextRow = true;
                  break; //break out of simple column for loop
                }

            } //End looping on simple columns

            if (l_rc)
            {
                break;
            }

            //Skip over to the next row
            if (l_goToNextRow)
            {
                FAPI_DBG("fapiHwpExecInitFile: executeScoms: check next row");
                l_goToNextRow = false;
                continue;
            }

            //Now evaluate the expression, if there is one
            if (i_ifData.scoms[i].hasExpr)
            {
                FAPI_DBG("fapiHwpExecInitFile: Evaluate expr");

                l_len = *((uint8_t*)l_rowExpr);
                l_rowExpr++;
                //l_len--; //remove the length value from the length left

                l_rc = evalRpn(i_ifData, l_rowExpr, l_len, true);

                if (l_rc)
                {
                    FAPI_ERR("fapiHwpExecInitFile: Row expression evalRpn failed on "
                             "scom 0x%X", i_ifData.scoms[i].addrId);
                    break;
                }

                result = rpnPop(i_ifData.rpnStack);
                FAPI_DBG("fapiHwpExecInitFile: executeScoms: Expr: result 0x%llX",
                         result);

                //If nonzero, we're done so break out of row loop, otherwise
                //let it go down to the next row
                if (0 != result)
                {
                  FAPI_DBG("fapiHwpExecInitFile: executeScoms: Expr: found valid row");
                  break;
                }
            }
            else
            {
                //No expression, and we're at the end, so we must
                //have found a match in the columns
                FAPI_DBG("fapiHwpExecInitFile: executeScoms: found valid row");
                break;
            }

        } // end looping for all rows

        if (l_rc)
        {
            break;
        }

        FAPI_DBG("fapiHwpExecInitFile: executeScoms: row %u", l_row);

        //Can tell we found a match by checking if we broke out of the
        //for loop early
        if (l_row < i_ifData.scoms[i].numRows)
        {
            FAPI_DBG("fapiHwpExecInitFile: executeScoms: found valid row %u", l_row);
            // Perform a scom operation on the chip
            l_rc = writeScom(i_ifData, i, l_row);

            if (l_rc)
            {
                break;
            }
        }

    } // end looping for all scoms

    //Clear the stack
    l_rpnStack.clear();

    FAPI_INF("<< fapiHwpExecInitFile: executeScoms");
    return l_rc;
}

/**  @brief Write Scom
 *
 * @param[in] i_ifData   Reference to ifData_t which contains initfile data
 * @param[in] i_scomNum  Scom entry number
 * @param[in] i_row      Scom entry row number
 *
 * @return ReturnCode. Zero if success.
 */
fapi::ReturnCode writeScom(const ifData_t & i_ifData, const uint32_t i_scomNum,
                           const uint16_t i_row)
{
    FAPI_DBG(">> fapiHwpExecInitFile: writeScom");

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

    const fapi::Target l_target = *(i_ifData.pTarget);

    do
    {
        //Get the the scom address
        uint64_t l_addr = 0;
        uint16_t l_id = i_ifData.scoms[i_scomNum].addrId;
        l_rc = getLit(i_ifData, l_id, l_addr);

        if (l_rc)
        {
            break;
        }

        //Get the scom data
        uint64_t l_data = 0;
        l_id = i_ifData.scoms[i_scomNum].dataId[i_row];

        if ((l_id & IF_TYPE_MASK) == IF_ATTR_TYPE) //It's an attribute
        {
            //Check for attribute of array type
            uint16_t l_arrayIndexs[MAX_ATTRIBUTE_ARRAY_DIMENSION] = {0};

            //Mask out the type & system bits and zero-based
            uint16_t l_tmpId = (l_id & IF_ATTR_ID_MASK) - 1;
            if (l_tmpId < i_ifData.numAttrs)
            {
                // Get the attribute dimension & shift it to the LS nibble
                uint8_t l_attrDimension =
                    (i_ifData.attrs[l_tmpId].type & ATTR_DIMENSION_MASK) >> 4;

                if (l_attrDimension)
                {
                    // Read out all dimensions for the attribute
                    for(uint8_t i = 0; i < l_attrDimension; i++)
                    {
                        // Get the array index id
                        uint64_t l_arrayIdxId = i_ifData.dataArrayIdxId->at(i);

                        // Retrieve the actual value for the array index (using it's id)
                        uint64_t l_tmpIdx = 0;
                        l_rc = getLit(i_ifData,l_arrayIdxId,l_tmpIdx);
                        if (l_rc)
                        {
                            break;
                        }
                        l_arrayIndexs[i] = l_tmpIdx;
                    }

                    if (l_rc)
                    {
                        break;
                    }

                    // Remove the array index id(s)
                    i_ifData.dataArrayIdxId->erase(i_ifData.dataArrayIdxId->begin(),
                        i_ifData.dataArrayIdxId->begin() + l_attrDimension);
                }
            }
            else
            {
                FAPI_ERR("fapiHwpExecInitFile: getAttr: id out of range");

                //Set l_rc
                uint32_t l_ffdc = l_id;
                uint32_t & FFDC_IF_ATTR_ID_OUT_OF_RANGE = l_ffdc; // GENERIC IDENTIFIER
                FAPI_SET_HWP_ERROR(l_rc, RC_INITFILE_ATTR_ID_OUT_OF_RANGE);
                break;
            }

            l_rc = getAttr(i_ifData, l_id, l_data, l_arrayIndexs);
        }
        else // It's a numeric literal
        {
            l_rc = getLit(i_ifData, l_id, l_data);
        }

        if (l_rc)
        {
            break;
        }

        FAPI_DBG("fapiHwpExecInitFile: writeScom: addr 0x%.16llX, data 0x%.16llX",
                 l_addr, l_data);

        //Create a 64 bit data buffer
        ecmdDataBufferBase l_scomData(64);

        //Check if this is a bit operation
        if (i_ifData.scoms[i_scomNum].len)
        {
            //Perform a PutScomUnderMask operation on the target

            #ifdef HWPEXECINITFILE_DEBUG
            l_rc = fapiGetScom(l_target, l_addr, l_scomData);
            FAPI_DBG("fapiHwpExecInitFile: writeScom: Data read 0x%.16llX",
                     l_scomData.getDoubleWord(0));
            #endif

            //Create a 64 bit data buffer
            ecmdDataBufferBase l_scomMask(64);

            //Get offset and len
            uint16_t l_offset = i_ifData.scoms[i_scomNum].offset;
            uint16_t l_len = i_ifData.scoms[i_scomNum].len;

            if ((l_id & IF_TYPE_MASK) == IF_ATTR_TYPE) //It's an attribute
            {
                //Attribute data of different sizes is returned from getAttr
                //as a 64bit right-justified number.
                //Shift data to the right offset
                l_data <<= (64 - (l_offset + l_len));
            }
            else // It's a numerical literal
            {
                //Shift data to the right offset
                l_data >>= l_offset;
            }

            //Create mask
            uint64_t l_mask = 0;
            for (uint64_t i = l_offset; i < (l_offset + l_len); i++)
            {
                l_mask |= (0x8000000000000000ll >> i);
            }

            FAPI_DBG("fapiHwpExecInitFile: writeScom: data 0x%.16llX mask 0x%.16llX"
                     " len %u offset %u", l_data, l_mask, l_len, l_offset);

            l_ecmdRc = l_scomData.setDoubleWord(0, l_data);
            l_ecmdRc |= l_scomMask.setDoubleWord(0, l_mask);

            if (l_ecmdRc != ECMD_DBUF_SUCCESS)
            {
                 FAPI_ERR("fapiHwpExecInitFile: writeScom: error from "
                          "ecmdDataBuffer setDoubleWord() - rc 0x%.8X",
                          l_ecmdRc);

                 l_rc = l_ecmdRc;
                 break;
            }

            FAPI_DBG("fapiHwpExecInitFile: writeScom: PutScomUnderMask: "
                     "0x%.16llX = 0x%.16llX mask 0x%.16llX",
                     l_addr, l_scomData.getDoubleWord(0),
                     l_scomMask.getDoubleWord(0));

            l_rc = fapiPutScomUnderMask(l_target, l_addr, l_scomData,
                                        l_scomMask);

            if (l_rc)
            {
                FAPI_ERR("fapiHwpExecInitFile: Error from fapiPutScomUnderMask");
                break;
            }
            #ifdef HWPEXECINITFILE_DEBUG
            else
            {
                l_rc = fapiGetScom(l_target, l_addr, l_scomData);
                FAPI_DBG("fapiHwpExecInitFile: writeScom: Data read 0x%.16llX",
                         l_scomData.getDoubleWord(0));
            }
            #endif
        }
        else
        {
           //Perform a PutScom operation on the target

            #ifdef HWPEXECINITFILE_DEBUG
            l_rc = fapiGetScom(l_target, l_addr, l_scomData);
            FAPI_DBG("fapiHwpExecInitFile: writeScom: Data read 0x%.16llX",
                     l_scomData.getDoubleWord(0));
            #endif

            l_ecmdRc = l_scomData.setDoubleWord(0, l_data);

            if (l_ecmdRc != ECMD_DBUF_SUCCESS)
            {
                 FAPI_ERR("fapiHwpExecInitFile: writeScom: error from "
                          "ecmdDataBuffer setDoubleWord() - rc 0x%.8X",
                          l_ecmdRc);

                 l_rc = fapi::FAPI_RC_ECMD_MASK;
                 break;
            }

            FAPI_DBG("fapiHwpExecInitFile: writeScom: PutScom: 0x%.16llX = 0x%.16llX",
                     l_addr, l_scomData.getDoubleWord(0));

            l_rc = fapiPutScom(l_target, l_addr, l_scomData);

            if (l_rc)
            {
                FAPI_ERR("fapiHwpExecInitFile: Error from fapiPutScom");
            }
            #ifdef HWPEXECINITFILE_DEBUG
            else
            {
                l_rc = fapiGetScom(l_target, l_addr, l_scomData);
                FAPI_DBG("fapiHwpExecInitFile: writeScom: Data read 0x%.16llX",
                         l_scomData.getDoubleWord(0));
            }
            #endif
        }

    } while(0);

    FAPI_DBG("<< fapiHwpExecInitFile: writeScom");
    return l_rc;
}

//******************************************************************************
// RPN Calculator functions
//******************************************************************************

/** @brief Pushes a value onto the RPN stack.
 *
 * @param[in,out] io_rpnStack  Ptr to RPN stack
 * @param[in]     i_val        Value to push
 */
void rpnPush(rpnStack_t * io_rpnStack, uint64_t i_val)
{
    FAPI_DBG("fapiHwpExecInitFile: rpnPush");

    io_rpnStack->push_back(i_val);
}

/** @brief Pops the top value off of the RPN stack.
 *
 * @param[in,out] io_rpnStack  Ptr to RPN stack
 * @return uint64_t            Value from top of stack
 */
uint64_t rpnPop(rpnStack_t * io_rpnStack)
{
    FAPI_DBG("fapiHwpExecInitFile: rpnPop");

    uint64_t l_val = 0;

    if (io_rpnStack->size() != 0)
    {
        l_val = io_rpnStack->back();
        io_rpnStack->pop_back();
    }

    return l_val;
}

/** @brief Dumps out the RPN stack
 *
 * @param[in] i_rpnStack  Ptr to RPN stack
 */
void rpnDumpStack(rpnStack_t * i_rpnStack)
{
    #ifdef HOSTBOOT_DEBUG

    FAPI_DBG(">> fapiHwpExecInitFile: rpnDumpStack: stack size = %d",
             i_rpnStack->size());

    uint64_t l_val = 0;

    for (ssize_t i = i_rpnStack->size() - 1; i >= 0; i--)
    {
        l_val = i_rpnStack->at(i);
        FAPI_DBG("Stack: Value = 0x%llX", l_val);
    }

    FAPI_DBG("<< fapiHwpExecInitFile: rpnDumpStack");

   #endif
}

/** @brief Executes the unary operations - the ones with 1 operand.
 *
 * @param[in] i_op   Operation to perform
 * @param[in] i_val  Value to perform it on
 * @param[in] i_any  Flag indicating if this is an ANY op
 * @return uint64_t  The result
 */
uint64_t rpnUnaryOp(IfRpnOp i_op, uint64_t i_val, uint32_t i_any)
{
    FAPI_DBG("fapiHwpExecInitFile: rpnUnaryOp");
    uint64_t result = 0;

    if (i_op == NOT)
    {
        if (i_any & IF_ANY) //everything returns true
        {
            result = 1;
        }
        else
        {
            result = (i_val == 0) ? 1 : 0;
        }
    }
    else
    {
        FAPI_ERR("fapiHwpExecInitFile: rpnUnaryOp: Invalid Op %u", i_op);
        fapiAssert(false);
    }

    return result;
}

/** @brief Executes the binary operations - the ones with 2 operands.
 *
 * @param[in] IfRpnOp i_op     Operation to perform
 * @param[in] uint64_t i_val1  The first operand
 * @param[in] uint64_t i_val2  The second operand
 * @return uint64_t            The result
 */
uint64_t rpnBinaryOp(IfRpnOp i_op, uint64_t i_val1, uint64_t i_val2,
                     uint32_t i_any)
{
    FAPI_DBG(">> fapiHwpExecInitFile: rpnBinaryOp 0x%X", i_op);

    uint64_t result = 0;

    //If either of these are ANY, then just return nonzero/true
    if (i_any & IF_ANY)
    {
        result = 1;
        FAPI_DBG("fapiHwpExecInitFile: rpnBinaryOp: ANY");
    }
    else
    {
        switch (i_op)
        {
            case (AND):
                result = i_val1 && i_val2;
                break;

            case (OR):
                result = i_val1 || i_val2;
                break;

            case (EQ):
                result = i_val1 == i_val2;
                break;

            case (NE):
                result = i_val1 != i_val2;
                break;

            case (GT):
                result = i_val1 > i_val2;
                break;

            case (GE):
                result = i_val1 >= i_val2;
                break;

            case (LT):
                result = i_val1 < i_val2;
                break;

            case (LE):
                result = i_val1 <= i_val2;
                break;

            case (PLUS):
                result = i_val1 + i_val2;
                break;

            case (MINUS):
                result = i_val1 - i_val2;
                break;

            case (MULT):
                result = i_val1 * i_val2;
                break;

            case (DIVIDE):
                if (0 == i_val2)
                {
                    FAPI_ERR("fapiHwpExecInitFile: rpnBinaryOp: "
                             "Division by zero, i_val1 = 0x%llx", i_val1);
                    fapiAssert(false);
                }

                result = i_val1 / i_val2;
                break;

            case (MOD):
                if (0 == i_val2)
                {
                    FAPI_ERR("fapiHwpExecInitFile: rpnBinaryOp: "
                             "Mod by zero, i_val1 = 0x%llx", i_val1);
                    fapiAssert(false);
                }

                result = i_val1 % i_val2;
                break;

            case (SHIFTLEFT):
                result = i_val1 << i_val2;
                break;

            case (SHIFTRIGHT):
                result = i_val1 >> i_val2;
                break;

            default:
              FAPI_ERR("fapiHwpExecInitFile: rpnBinaryOp, invalid operator %d",
                       i_op);
              fapiAssert(false);
              break;
        }
    }

    FAPI_DBG("<< fapiHwpExecInitFile: rpnBinaryOp: result 0x%llX", result);
    return result;
}

/** @brief Pushes an attribute or literal value onto the RPN stack.
 *
 * Pushes the attribute or literal value specified by i_id onto the RPN stack.
 * It uses the appropriate symbol table to resolve the value first.
 *
 * @param[in,out] io_ifData    Reference to ifData_t which contains initfile data
 * @param[in]     i_id         Id of element to push
 * @param[in,out] io_any       Set if ANY op
 * @param[in] i_arrayIndexIds  Array of attribute array index's
                                (when attribute is array type)
 * @return fapi::ReturnCode    Zero on success
 */
fapi::ReturnCode rpnDoPush(ifData_t & io_ifData, const uint16_t i_id,
                           uint32_t & io_any, const uint16_t i_arrayIndexIds[MAX_ATTRIBUTE_ARRAY_DIMENSION])
{
    FAPI_DBG(">> HwpInitFile: rpnDoPush: id 0x%X", i_id);

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    uint64_t l_val = 0;

    do
    {

        if ((i_id & IF_TYPE_MASK) == IF_ATTR_TYPE) //It's an attribute
        {
            l_rc = getAttr(io_ifData, i_id, l_val, i_arrayIndexIds);
            if (l_rc)
            {
              break;
            }

            FAPI_DBG("fapiHwpExecInitFile: rpnDoPush: getAttr: id = 0x%X, "
                     "value = 0x%llX", i_id, l_val);

            rpnPush(io_ifData.rpnStack, l_val);
        }
        else //It's a literal
        {
            //If it's not 'ANY'
            if (i_id != IF_VAL_ANY)
            {
                l_rc = getLit(io_ifData, i_id, l_val);
                if (l_rc)
                {
                  FAPI_ERR("fapiHwpExecInitFile: rpnDoPush: getLit: id 0x%X failed",
                           i_id);
                  break;
                }

                FAPI_DBG("fapiHwpExecInitFile: rpnDoPush: Literal lookup: "
                         "id = 0x%X, value = 0x%llX", i_id, l_val);

                rpnPush(io_ifData.rpnStack, l_val);
            }
            else //It's 'ANY', which will always return true
            {
                io_any |= IF_ANY;

                l_val = 1;
                rpnPush(io_ifData.rpnStack, l_val);

                //If this is set, then we will see a PUSH ANY on the stack
                //without the 2nd operand for the binary operator EQ.  This
                //happens when parsing the expression column
                if (io_any & IF_ONE_SIDED_ANY)
                {
                   //To get the second operand, push a fake one on the stack
                   uint64_t l_temp = 0;
                   rpnPush(io_ifData.rpnStack, l_temp);
                }

                FAPI_DBG("fapiHwpExecInitFile: rpnDoPush: Literal ANY pushed on "
                         "stack");
            }
        }

    } while(0);

    FAPI_DBG("<< HwpInitFile: rpnDoPush");
    return l_rc;
}

/** @brief Execute the operation
 *
 * Executes the operation passed in, and places the result onto
 *
 * @param[in,out] io_rpnStack  Ptr to RPN stack
 * @param[in,out] i_op         Operation to perform
 * @param[in]     i_any        Set if ANY op
 * @return fapi::ReturnCode    Zero on success
 */
fapi::ReturnCode rpnDoOp(rpnStack_t * io_rpnStack, IfRpnOp i_op, uint32_t i_any)
{
    FAPI_DBG(">> fapiHwpExecInitFile: rpnDoOp 0x%X", i_op);

    rpnDumpStack(io_rpnStack);

    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    uint64_t val1   = 0;
    uint64_t val2   = 0;
    uint64_t result = 0;

    switch (i_op)
    {
        //Do all of the binary ops
        case (AND):
        case (OR):
        case (GT):
        case (GE):
        case (LT):
        case (LE):
        case (EQ):
        case (NE):
        case (PLUS):
        case (MINUS):
        case (MULT):
        case (DIVIDE):
        case (MOD):
        case (SHIFTLEFT):
        case (SHIFTRIGHT):

            //pop the first value
            val2 = rpnPop(io_rpnStack);

            //pop the second value
            val1 = rpnPop(io_rpnStack);

            //Calculate the result
            result = rpnBinaryOp(i_op, val1, val2, i_any);

            //Push the result onto the stack
            rpnPush(io_rpnStack, result);

            break;

        case (NOT):

            //Pop the value
            val1 = rpnPop(io_rpnStack);

            //Calculate the result
            result = rpnUnaryOp(i_op, val1, i_any);

            //Push the result onto the stack
            rpnPush(io_rpnStack, result);

            break;

        case (FALSE_OP):

            result = 0;
            rpnPush(io_rpnStack, result);
            break;

        case (TRUE_OP):

           result = 1;
           rpnPush(io_rpnStack, result);
           break;

        default:
           FAPI_DBG("fapiHwpExecInitFile: rpnDoOp: invalid op 0x%X", i_op);
           fapiAssert(false);
           break;
    }

    FAPI_DBG("<< fapiHwpExecInitFile: rpnDoOp: result %llu", result);
    return l_rc;
}

/** @brief Evaluates the RPN expression
 *
 * Evaluates the expression passed in and places the result on the RPN stack.
 *
 * @param[in,out] io_ifData   Reference to ifData_t which contains initfile data
 * @param[in]     i_expr      Expression to evaluate
 * @param[in]     i_len       Length of expression
 * @param[in]     i_hasExpr   True if EXPR column
 *
 * @return fapi::ReturnCode   Zero on success
 */
fapi::ReturnCode evalRpn(ifData_t & io_ifData, char *i_expr,
                         uint32_t i_len, const bool i_hasExpr)
{
    FAPI_DBG(">> fapiHwpExecInitFile: evalRpn");

    fapi::ReturnCode l_rc;
    IfRpnOp l_op;
    uint16_t l_id;
    uint32_t l_any = IF_NOT_ANY;

    FAPI_DBG("fapiHwpExecInitFile: evalRpn: len %u", i_len);

    //If we're in an expression column, then an 'ANY' will just be one sided,
    //and won't have the 2nd operand needed for the upcoming EQ operator
    if (i_hasExpr)
    {
        FAPI_DBG("fapiHwpExecInitFile: evalRpn: this is an expr");
        l_any = IF_ONE_SIDED_ANY;
    }

    while (i_len--)
    {
        l_op = static_cast<IfRpnOp>((*i_expr++) & OP_MASK);
        FAPI_DBG("fapiHwpExecInitFile: evalRpn: op? 0x%.2X", l_op);

        if (l_op & PUSH_MASK) //Push
        {
            l_id = static_cast<uint16_t>((l_op << 8) | ((*i_expr++) & OP_MASK));
            --i_len;

            FAPI_DBG("fapiHwpExecInitFile: evalRpn: id 0x%.2X", l_id);

            //Check for attribute of array type
            uint16_t l_arrayIndexs[MAX_ATTRIBUTE_ARRAY_DIMENSION] = {0};

            if ((l_id & IF_TYPE_MASK) == IF_ATTR_TYPE)
            {
                //Mask out the type & system bits and zero-based
                uint16_t i = (l_id & IF_ATTR_ID_MASK) - 1;

                // Get the attribute dimension
                uint8_t l_attrDimension = io_ifData.attrs[i].type & ATTR_DIMENSION_MASK;

                // Now shift it to the LS nibble
                l_attrDimension = l_attrDimension >> 4;

                //FAPI_DBG("fapiHwpExecInitFile: evalRpn: Attribute ID:0x%.4X has dimension %u of type 0x%.4X",
                //         l_id,l_attrDimension,io_ifData.attrs[i].type);

                // Read out all dimensions for the attribute
                for(uint8_t j=0; j<l_attrDimension; j++)
                {
                    // Read out array index id
                    uint16_t l_arrayIdxId = 0;
                    l_arrayIdxId = *i_expr++ << 8;
                    l_arrayIdxId |= *i_expr++;

                    uint64_t l_tmpIdx = 0;

                    // Retrieve the actual value for the array index (using it's id)
                    l_rc = getLit(io_ifData,l_arrayIdxId,l_tmpIdx);
                    if (l_rc)
                    {
                        break;
                    }
                    l_arrayIndexs[j] = l_tmpIdx;
                    i_len -= 2;
                }
            }

            // Handle error from above for loop
            if(l_rc)
            {
                break;
            }

            l_rc = rpnDoPush(io_ifData, l_id, l_any, l_arrayIndexs);
        }
        else
        {
            l_rc = rpnDoOp(io_ifData.rpnStack, l_op, l_any);
        }

        if (l_rc)
        {
            break;
        }
    }

    FAPI_DBG("<< fapiHwpExecInitFile: evalRpn");
    return l_rc;
}

} // extern "C"
