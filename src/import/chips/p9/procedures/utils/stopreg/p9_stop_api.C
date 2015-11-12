/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/utils/stopreg/p9_stop_api.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file   p9_stop_api.C
/// @brief  implements STOP API which  create/manipulate STOP image.
///
// *HWP HW Owner    :  Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team        :  PM
// *HWP Level       :  2
// *HWP Consumed by :  HB:HYP

#include "p9_stop_api.H"
#include "p9_cpu_reg_restore_instruction.H"
#include "p9_stop_data_struct.H"
#include <string.h>
#include "p9_stop_util.H"
#include <stdio.h>

#ifdef __FAPI_2_
    #include <fapi2.H>
#endif

#ifdef __cplusplus
extern "C" {
#endif

namespace stopImageSection
{
const StopSprReg_t g_sprRegister[] =
{
    { P9_STOP_SPR_HSPRG0,    true  },
    { P9_STOP_SPR_HRMOR,     false },
    { P9_STOP_SPR_LPCR,      true  },
    { P9_STOP_SPR_HMEER,     false },
    { P9_STOP_SPR_PSSCR,     true  },
    { P9_STOP_SPR_PMCR,      false },
    { P9_STOP_SPR_HID,       false },
    { P9_STOP_SPR_MSR,       true  },
    { P9_STOP_SPR_DAWR,      true  },
};

const uint32_t MAX_SPR_SUPPORTED =
    sizeof ( g_sprRegister ) / sizeof( StopSprReg_t );

//-----------------------------------------------------------------------------

/**
 * @brief   validates input arguments provided by STOP API caller.
 * @param[in]       i_pImage    pointer to beginning of chip's HOMER image.
 * @param[in]       i_regId             SPR register id
 * @param[in]       i_coreId            core id
 * @param[in|out]   io_threadId         thread id
 * @param[in|out]   io_threadLevelReg   true if register is of thread scope, false if of
 *                                      core scope.
 * @return  STOP_SAVE_SUCCESS if arguments found valid, error code otherwise.
 * @note    for register of scope core, function shall force io_threadId to
 *          zero.
 */
StopReturnCode_t validateSprImageInputs( void*   const i_pImage,
        const CpuReg_t i_regId,
        const uint32_t  i_coreId,
        uint32_t&    io_threadId,
        bool& io_threadLevelReg )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;
    bool sprSupported = false;
    io_threadLevelReg = false;

    do
    {
        if( NULL == i_pImage )
        {
            // Error: HOMER image start location is not valid
            // Cannot proceed further. So, let us exit.
            l_rc = STOP_SAVE_ARG_INVALID_IMG;
            MY_ERR( "invalid image location " );

            break;
        }

        // STOP API manages STOP image based on physical core Id. PIR value
        // is interpreted to calculate the physical core number and virtual
        // thread number.
        if( MAX_CORE_ID_SUPPORTED < i_coreId )
        {
            // Error: invalid core number. given core number exceeds maximum
            // cores supported by chip.

            // Physical core number is calculated based on following formula:
            // core id = 4 * quad id (0..5) + core no within quad ( 0..3)
            l_rc = STOP_SAVE_ARG_INVALID_CORE;
            MY_ERR( "invalid core id " );
            break;
        }

        if( MAX_THREAD_ID_SUPPORTED < io_threadId )
        {
            //Error: invalid core thread. Given core thread exceeds maximum
            //threads supported in a core.

            // 64 bit PIR value is interpreted to calculate virtual thread
            // Id. In fuse mode, b61 and b62 gives virtual thread id whereas in
            // non fuse mode, b62 and b63 is read to determine the same.

            l_rc = STOP_SAVE_ARG_INVALID_THREAD;
            MY_ERR( "invalid thread " );
            break;
        }

        for( uint32_t index = 0; index < MAX_SPR_SUPPORTED; ++index )
        {
            if( i_regId == g_sprRegister[index].sprId )
            {
                // given register is in the list of register supported
                sprSupported = true;
                io_threadLevelReg = g_sprRegister[index].isThreadScope;
                io_threadId = io_threadLevelReg ? io_threadId : 0;
                break;
            }
        }

        if( !sprSupported )
        {
            // Following SPRs are supported
            // trace out all registers supported
            MY_ERR("Register not supported" );
            // error code to caller.
            l_rc = STOP_SAVE_ARG_INVALID_REG;
            break;
        }

    }
    while(0);

    if( l_rc )
    {
        MY_ERR( "image 0x%08x, regId %08d, coreId %d, "
                "threadId %d return code 0x%08x", i_pImage, i_regId,
                i_coreId, io_threadId, l_rc  );
    }

    return l_rc;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates ori instruction code.
 * @param[in]   i_Rs    Source register number
 * @param[in]   i_Ra    destination regiser number
 * @param[in]   i_data  16 bit immediate data
 * @return  returns 32 bit instruction representing ori instruction.
 */
uint32_t getOriInstruction( const uint16_t i_Rs, const uint16_t i_Ra,
                            const uint16_t i_data )
{
    uint32_t oriInstOpcode = 0;
    oriInstOpcode = 0;
    oriInstOpcode = ORI_OPCODE << 26;
    oriInstOpcode |= i_Rs << 21;
    oriInstOpcode |= i_Rs << 16;
    oriInstOpcode |= i_data;

    return SWIZZLE_4_BYTE(oriInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief generates 32 bit key used for SPR lookup in core section.
 */
uint32_t genKeyForSprLookup( const CpuReg_t i_regId )
{
    return getOriInstruction( 0, 0, (uint16_t) i_regId );
}

//-----------------------------------------------------------------------------

/**
 * @brief generates xor instruction code.
 * @param[in] i_Rs  source register number for xor operation
 * @param[in] i_Ra  destination register number for xor operation result
 * @param[in] i_Rb source register number for xor operation
 * @return returns 32 bit instruction representing xor  immediate instruction.
 */
uint32_t getXorInstruction( const uint16_t i_Ra, const uint16_t i_Rs,
                            const uint16_t i_Rb )
{
    uint32_t xorRegInstOpcode;
    xorRegInstOpcode = XOR_CONST << 1;
    xorRegInstOpcode |= OPCODE_31 << 26;
    xorRegInstOpcode |= i_Rs << 21;
    xorRegInstOpcode |= i_Rs << 16;
    xorRegInstOpcode |= i_Rb << 11;

    return SWIZZLE_4_BYTE(xorRegInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief generates xor instruction code.
 * @param[in] i_Rs      source register number
 * @param[in] i_Ra      destination register number
 * @param[in] i_data    16 bit immediate data
 * @return returns 32 bit instruction representing xor  immediate instruction.
 */
uint32_t getOrisInstruction( const uint16_t i_Rs, const uint16_t i_Ra,
                             const uint16_t i_data )
{
    uint32_t orisInstOpcode;
    orisInstOpcode = 0;
    orisInstOpcode = ORIS_OPCODE << 26;
    orisInstOpcode |= ( i_Rs & 0x001F ) << 21 | ( i_Ra & 0x001F ) << 16;
    orisInstOpcode |= i_data;

    return SWIZZLE_4_BYTE(orisInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mtspr
 * @param[in] i_Rs      source register number
 * @param[in] i_Spr represents spr where data is to be moved.
 * @return returns 32 bit instruction representing mtspr instruction.
 */
uint32_t getMtsprInstruction( const uint16_t i_Rs, const uint16_t i_Spr )
{
    uint32_t mtsprInstOpcode = 0;
    uint32_t temp = (( i_Spr & 0x03FF ) << 11);
    mtsprInstOpcode = ( temp  & 0x0000F800 ) << 5;
    mtsprInstOpcode |= ( temp & 0x001F0000 ) >> 5;
    mtsprInstOpcode |= MTSPR_BASE_OPCODE;

    return SWIZZLE_4_BYTE(mtsprInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief generates xor instruction code.
 * @param[in] i_Rs      source register number
 * @param[in] i_Ra      destination register number
 * @param[in] i_sh1     position by which contents of i_Rs are to be shifted
 * @param[in] i_MB      shift poistion start
 * @return returns 32 bit instruction representing rldimi instruction.
 */
uint32_t getRldimiInstruction( const uint16_t i_Rs, const uint16_t i_Ra,
                               const uint16_t i_sh1, uint16_t i_MB )
{
    // limited support of this instruction
    uint32_t rldimiInstOpcode = 0;
    rldimiInstOpcode = 0;
    rldimiInstOpcode = ((RLDIMI_OPCODE << 26 ) | ( i_Rs << 21 ) | ( i_Ra << 16 ));
    rldimiInstOpcode |= ( ( i_sh1 & 0x001F ) << 11 ) | (RLDIMI_CONST << 2 );
    rldimiInstOpcode |= (( i_sh1 & 0x0020 ) >> 4);
    rldimiInstOpcode |= (i_MB & 0x003F ) << 5;
    return SWIZZLE_4_BYTE(rldimiInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mtmsr instruction.
 * @param[in]   i_Rs      source register number
 * @return  returns 32 bit instruction representing mtmsr instruction.
 * @note    moves contents of register i_Rs to MSR register.
 */
uint32_t getMtmsrdInstruction( const uint16_t i_Rs )
{
    uint32_t mtmsrdInstOpcode = 0;
    mtmsrdInstOpcode = 0;
    mtmsrdInstOpcode = OPCODE_31 << 26;
    mtmsrdInstOpcode |= i_Rs << 21 | ( MTMSRD_CONST1 << 1 );

    return SWIZZLE_4_BYTE(mtmsrdInstOpcode);
}

//-----------------------------------------------------------------------------

/**
 * @brief looks up entry for given SPR in given thread/core section.
 * @param[in]   i_pThreadSectLoc    start of given thread section or core section.
 * @param[in]   i_lookUpKey         search key for lookup of given SPR entry.
 * @param[in]   i_isCoreReg         true if register is of scope core, false
 *                                  otherwise.
 * @param[in|out] io_pSprEntryLoc   Input:  NULL
 *                                  Output: location of given entry or end of table.
 * @return      STOP_SAVE_SUCCESS if entry is found, STOP_SAVE_FAIL in case of
 *              an error.
 */
StopReturnCode_t lookUpSprInImage( uint32_t* i_pThreadSectLoc,
                                   const uint32_t i_lookUpKey,
                                   const bool i_isCoreReg,
                                   void*& io_pSprEntryLoc )
{
    StopReturnCode_t l_rc = STOP_SAVE_FAIL;
    uint32_t temp = i_isCoreReg ? CORE_SPR_SECTN_SIZE : THREAD_SECTN_SIZE;
    uint32_t* i_threadSectEnd = i_pThreadSectLoc + temp;
    uint32_t bctr_inst = SWIZZLE_4_BYTE(BLR_INST);
    io_pSprEntryLoc = NULL;

    do
    {
        if( !i_pThreadSectLoc )
        {
            break;
        }

        temp = 0;

        while( ( i_pThreadSectLoc <= i_threadSectEnd ) &&
               ( temp != bctr_inst ) )
        {
            temp = *i_pThreadSectLoc;

            if( ( temp == i_lookUpKey ) || ( temp == bctr_inst ) )
            {
                io_pSprEntryLoc = i_pThreadSectLoc;
                l_rc = STOP_SAVE_SUCCESS;
                break;
            }

            i_pThreadSectLoc = i_pThreadSectLoc + SIZE_PER_SPR_RESTORE_INST;
        }

    }
    while(0);

    return l_rc;
}

//-----------------------------------------------------------------------------

/**
 * @brief updates an SPR STOP image entry.
 * @param[in] i_pSprEntryLocation location of entry.
 * @param[in] i_regId       register Id associated with SPR.
 * @param[in] i_regData     data needs to be written to SPR entry.
 * @return    STOP_SAVE_SUCCESS if update works, STOP_SAVE_FAIL otherwise.
 */
StopReturnCode_t updateSprEntryInImage( uint32_t* i_pSprEntryLocation,
                                        const CpuReg_t i_regId,
                                        const uint64_t i_regData )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;
    uint32_t tempInst = 0;
    typedef  union
    {
        uint64_t regData;
        uint16_t dataBit[4];
    } RegData;

    do
    {
        if( !i_pSprEntryLocation )
        {
            MY_ERR("invalid location of SPR image entry" );
            l_rc = STOP_SAVE_FAIL;
            break;
        }

        RegData regValue;
        regValue.regData = i_regData;

        tempInst = genKeyForSprLookup( i_regId );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getXorInstruction( 0, 0, 0 );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getOrisInstruction( 0, 0, regValue.dataBit[0] );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getOriInstruction( 0, 0, regValue.dataBit[1] );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getRldimiInstruction(0, 0, 32, 0);
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getOrisInstruction( 0, 0, regValue.dataBit[2] );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = getOriInstruction( 0, 0, regValue.dataBit[3] );
        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        if( P9_STOP_SPR_MSR == i_regId )
        {
            tempInst = getMtmsrdInstruction( 0 );
        }
        else if (P9_STOP_SPR_HRMOR == i_regId )
        {
            tempInst = SWIZZLE_4_BYTE(MR_INT);
        }
        else
        {
            tempInst =
                getMtsprInstruction( 0, (uint16_t)i_regId );
        }

        *i_pSprEntryLocation = tempInst;
        i_pSprEntryLocation += SIZE_PER_SPR_RESTORE_INST;

        tempInst = SWIZZLE_4_BYTE(BLR_INST);
        *i_pSprEntryLocation = tempInst;

    }
    while(0);

    return l_rc;
}

//-----------------------------------------------------------------------------

StopReturnCode_t p9_stop_save_cpureg(  void* const i_pImage,
                                       const CpuReg_t  i_regId,
                                       const uint64_t  i_regData,
                                       const uint64_t  i_pir )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;    // procedure return code
    HomerSection_t* chipHomer = NULL;

    do
    {
        uint32_t threadId = 0;
        uint32_t coreId   = 0;
        uint32_t lookUpKey = 0;
        void* pSprEntryLocation = NULL;   // an offset w.r.t. to start of image
        void* pThreadLocation = NULL;
        bool threadScopeReg = false;

        l_rc = getCoreAndThread( i_pImage, i_pir, coreId, threadId );
        MY_INF( " PIR 0x%016llx coreId %d threadid %d "
                " registerId %d", i_pir, coreId,
                threadId, i_regId );
        // First of all let us validate all input arguments.
        l_rc =  validateSprImageInputs( i_pImage,
                                        i_regId,
                                        coreId,
                                        threadId,
                                        threadScopeReg );

        if( l_rc )
        {
            // Error: bad argument traces out error code
            MY_ERR("Bad input argument rc %d", l_rc );

            break;
        }

        chipHomer = ( HomerSection_t*)i_pImage;

        if( threadScopeReg )
        {
            pThreadLocation =
                &(chipHomer->coreThreadRestore[coreId][threadId].threadArea[0]);
        }
        else
        {
            pThreadLocation =
                &(chipHomer->coreThreadRestore[coreId][threadId].coreArea[0]);
        }

        if( SWIZZLE_4_BYTE(ATTN_OPCODE) == *(uint32_t*)pThreadLocation )
        {
            // table for given core id doesn't exit. It needs to be
            // defined.
            pSprEntryLocation = pThreadLocation;
        }
        else
        {
            // an SPR restore section for given core already exists
            lookUpKey = genKeyForSprLookup( i_regId );
            l_rc = lookUpSprInImage( (uint32_t*)pThreadLocation,
                                     lookUpKey,
                                     threadScopeReg,
                                     pSprEntryLocation );
        }


        if( l_rc )
        {
            MY_ERR("Invalid or corrupt SPR entry. CoreId 0x%08x threadId ",
                   "0x%08x regId 0x%08x lookUpKey 0x%08x pThreadLocation 0x%08x"
                   , coreId, threadId, i_regId, lookUpKey, pThreadLocation );
            break;
        }

        l_rc = updateSprEntryInImage( (uint32_t*) pSprEntryLocation,
                                      i_regId,
                                      i_regData );

        if( l_rc )
        {
            MY_ERR( " Failed to update the SPR entry of PIR 0x%08x reg"
                    "0x%08x", i_pir, i_regId );
            break;
        }

    }
    while(0);

    return l_rc;
}

//-----------------------------------------------------------------------------

/**
 * @brief validates all the input arguments.
 * @param[in]   i_pImage       pointer to start of HOMER of image for proc chip.
 * @param[in]   i_scomAddress SCOM address of register.
 * @param[in]   i_chipletId   core or cache chiplet id
 * @param[in]   i_operation   operation requested for SCOM entry.
 * @param[in]   i_section     image section on which operation is to be performed
 * @return      STOP_SAVE_SUCCESS if arguments found valid, error code otherwise.
 * @note        Function does not validate that the given SCOM address really
 *              belongs to the given section.
 */
StopReturnCode_t validateScomImageInputs( void* const i_pImage,
        const uint32_t i_scomAddress,
        const uint8_t i_chipletId,
        const ScomOperation_t i_operation,
        const ScomSection_t i_section )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;

    do
    {
        if( !i_pImage )
        {
            //Error Invalid image pointer
            l_rc = STOP_SAVE_ARG_INVALID_IMG;
            MY_ERR("invalid image location ");
            break;
        }

        if( 0 == i_scomAddress )
        {
            l_rc = STOP_SAVE_SCOM_INVALID_ADDRESS;
            MY_ERR("invalid SCOM address");
            break;
        }

        if(( CACHE_CHIPLET_ID_MIN > i_chipletId ) ||
           ( CORE_CHIPLET_ID_MAX < i_chipletId ))
        {
            l_rc = STOP_SAVE_SCOM_INVALID_CHIPLET;
            MY_ERR("chiplet id not in range");
            break;
        }

        if(( CORE_CHIPLET_ID_MIN >  i_chipletId ) &&
           ( CACHE_CHIPLET_ID_MAX < i_chipletId ))
        {
            l_rc = STOP_SAVE_SCOM_INVALID_CHIPLET;
            MY_ERR("chiplet id not valid");
            break;
        }

        if(( P9_STOP_SCOM_OP_MIN >= i_operation ) ||
           ( P9_STOP_SCOM_OP_MAX <= i_operation ))
        {
            //invalid SCOM image operation requested
            l_rc = STOP_SAVE_SCOM_INVALID_OPERATION;
            MY_ERR("invalid SCOM image operation");
            break;
        }

        if(( P9_STOP_SECTION_MIN >= i_section ) ||
           ( P9_STOP_SECTION_MAX <= i_section ))
        {
            // invalid cache sub section specified
            l_rc = STOP_SAVE_SCOM_INVALID_SECTION;
            MY_ERR("invalid section");
            break;
        }

        if(( i_operation == P9_STOP_SCOM_RESET ) &&
           ( i_chipletId <  CORE_CHIPLET_ID_MIN ))
        {
            // replace requested with a cache chiplet Id
            l_rc = STOP_SAVE_SCOM_INVALID_OPERATION;
            MY_ERR( "reset not supported for cache. chiplet Id 0x%08x",
                    i_chipletId );
            break;
        }

    }
    while(0);

    if( l_rc )
    {
        MY_ERR("image 0x%08x SCOMAddress 0x%08x chipletId 0x%08x operation"
               "0x%08x section 0x%08x", i_pImage, i_scomAddress, i_chipletId,
               i_operation, i_section );
    }

    return l_rc;
}

//-----------------------------------------------------------------------------

/**
 * @brief   edit SCOM entry associated with the given core.
 * @param[in]   i_scomAddr       SCOM address of register.
 * @param[in]   i_scomData      data associated with SCOM register.
 * @param[in]   i_pEntryLocation points to a SCOM entry in HOMER image.
 * @param[in]   i_operation     operation to be performed on SCOM entry.
 * @return      STOP_SAVE_SUCCESS if existing entry is updated, STOP_SAVE_FAIL
 *              otherwise.
 */
StopReturnCode_t editScomEntry( uint32_t i_scomAddr, uint64_t i_scomData,
                                ScomEntry_t* i_pEntryLocation,
                                uint32_t i_operation )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;

    do
    {
        if( !i_pEntryLocation )
        {
            //Error: location of SCOM entry is not known
            //therefore no point moving forward
            MY_ERR("SCOM entry location not valid");
            l_rc = STOP_SAVE_FAIL;
            break;
        }

        switch( i_operation )
        {
            case P9_STOP_SCOM_OR:
                i_pEntryLocation->scomEntryData |= i_scomData;
                break;

            case P9_STOP_SCOM_AND:
                i_pEntryLocation->scomEntryData &= i_scomData;
                break;

            case P9_STOP_SCOM_NOOP:
                {
                    uint32_t nopInst = getOriInstruction( 0, 0, 0 );
                    i_pEntryLocation->scomEntryHeader = SCOM_ENTRY_START;
                    i_pEntryLocation->scomEntryData = nopInst;
                    i_pEntryLocation->scomEntryAddress = nopInst;
                }
                break;

            case P9_STOP_SCOM_APPEND:
                i_pEntryLocation->scomEntryHeader = SCOM_ENTRY_START;
                i_pEntryLocation->scomEntryData = i_scomData;
                i_pEntryLocation->scomEntryAddress = i_scomAddr;
                break;
        }

    }
    while(0);

    return l_rc;
}

//-----------------------------------------------------------------------------

/**
 * @brief   update SCOM entry associated with the given core.
 * @param[in]   i_scomAddr   SCOM address of register.
 * @param[in]   i_scomData   data associated with SCOM register.
 * @param[in]   i_scomEntry  points to a SCOM entry in cache section of HOMER image.
 * @return      STOP_SAVE_SUCCESS if new  entry is added, STOP_SAVE_FAIL otherwise.
 * @note        adds an entry at a given location. It can be used to add entry in
 *              place of NOP, at the end of table or as first entry of the cache
 *              sub-section(L2, L3 or NC ).
 */
StopReturnCode_t updateScomEntry( uint32_t i_scomAddr, uint64_t i_scomData,
                                  ScomEntry_t* i_scomEntry   )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;

    do
    {
        if( !i_scomEntry )
        {
            MY_ERR( "cache entry cannot be located");
            l_rc = STOP_SAVE_SCOM_ENTRY_UPDATE_FAILED;
            break;
        }

        i_scomEntry->scomEntryHeader = SCOM_ENTRY_START; // done for now
        i_scomEntry->scomEntryAddress = i_scomAddr;
        i_scomEntry->scomEntryData = i_scomData;

    }
    while(0);

    return l_rc;
}

//-----------------------------------------------------------------------------

StopReturnCode_t p9_stop_save_scom( void* const   i_pImage,
                                    const uint32_t i_scomAddress,
                                    const uint64_t i_scomData,
                                    const ScomOperation_t i_operation,
                                    const ScomSection_t i_section )
{
    StopReturnCode_t l_rc = STOP_SAVE_SUCCESS;
    StopCacheSection_t* pStopCacheScomStart = NULL;
    ScomEntry_t* pScomEntry = NULL;
    uint32_t entryLimit = 0;
    uint8_t chipletId = 0;

    do
    {
        chipletId = i_scomAddress >> 24;
        chipletId = chipletId & 0x3F;

        l_rc = validateScomImageInputs( i_pImage,
                                        i_scomAddress,
                                        chipletId,
                                        i_operation,
                                        i_section );

        if( l_rc )
        {
            MY_ERR( "invalid argument: aborting");
            break;
        }

        if( chipletId >= CORE_CHIPLET_ID_MIN )
        {
            // chiplet is core. So, let us find the start address of SCOM area
            // pertaining to a core in STOP image.
            pScomEntry = CORE_ID_SCOM_START(i_pImage,
                                            chipletId )
                         entryLimit = MAX_CORE_SCOM_ENTRIES;
        }
        else
        {
            // chiplet is a cache. let us find start address of cache section
            // associated with given chiplet. A cache section associated with
            // given chiplet is split in to L2, L3 and NC area.
            pStopCacheScomStart = CACHE_SECTN_START(i_pImage,
                                                    chipletId);
        }

        if(( !pStopCacheScomStart ) && ( !pScomEntry) )
        {
            //Error invalid pointer to SCOM entry in cache or core section
            //of STOP image.
            MY_ERR("invalid start location for chiplet %d",
                   chipletId );
            break;
        }

        switch( i_section )
        {
            case P9_STOP_SECTION_NC:
                pScomEntry = pStopCacheScomStart->nonCacheArea;
                entryLimit = MAX_NC_SCOM_ENTRIES;
                break;

            case P9_STOP_SECTION_L2:
                pScomEntry = pStopCacheScomStart->l2CacheArea;
                entryLimit = MAX_L2_SCOM_ENTRIES;
                break;

            case P9_STOP_SECTION_L3:
                pScomEntry = pStopCacheScomStart->l3CacheArea;
                entryLimit = MAX_L3_SCOM_ENTRIES;
                break;

            case P9_STOP_SECTION_CORE_SCOM:
                //macro CORE_ID_SCOM_START already gives start of scom
                //entry for given core. entry limit too is assigned thereafter.
                //Handling for core and cache segment is different for scom
                //entries. It is because scom entries are organized differently
                //in core and cache segment.
                break;

            default:
                l_rc = STOP_SAVE_SCOM_INVALID_SECTION;
                break;
        }

        if(( !pScomEntry ) || ( l_rc ) )
        {
            // Error Invalid pointer to cache entry
            MY_ERR("invalid subsection %d or internal firmware failure",
                   i_section );
            l_rc = STOP_SAVE_FAIL;
            break;
        }

        uint32_t nopInst = getOriInstruction( 0, 0, 0 );

        ScomEntry_t* pEntryLocation = NULL;
        ScomEntry_t* pNopLocation = NULL;
        ScomEntry_t* pTableEndLocationtable = NULL;
        uint32_t swizzleAddr = SWIZZLE_4_BYTE(i_scomAddress);
        uint64_t swizzleData = SWIZZLE_8_BYTE(i_scomData);
        uint32_t swizzleAttn = SWIZZLE_4_BYTE(ATTN_OPCODE);
        uint32_t index = 0;

        for( index = 0; index < entryLimit; ++index )
        {
            if( ( swizzleAddr == pScomEntry[index].scomEntryAddress ) &&
                ( !pEntryLocation ) )

            {
                pEntryLocation = &pScomEntry[index];
            }

            if( (( nopInst == pScomEntry[index].scomEntryAddress ) ||
                 ( swizzleAttn == pScomEntry[index].scomEntryAddress )) &&
                ( !pNopLocation ) )
            {
                pNopLocation = &pScomEntry[index];
            }

            if( SCOM_ENTRY_START == pScomEntry[index].scomEntryHeader )
            {
                continue;
            }

            pTableEndLocationtable = &pScomEntry[index];
            break;
        }

        if( ( !pEntryLocation ) && ( !pTableEndLocationtable ) )
        {
            MY_ERR(" exhausted all location available for section"
                   "0x%08x scom address 0x%08x",
                   i_section, i_scomAddress );
            l_rc = STOP_SAVE_SCOM_ENTRY_UPDATE_FAILED;
            break;
        }

        switch( i_operation )
        {
            case P9_STOP_SCOM_APPEND:
                {
                    ScomEntry_t* pScomAppend = NULL;

                    if( pNopLocation )
                    {
                        pScomAppend = pNopLocation;
                    }
                    else
                    {
                        pScomAppend = pTableEndLocationtable;
                    }

                    l_rc = updateScomEntry ( swizzleAddr,
                                             swizzleData, pScomAppend );
                }
                break;

            case P9_STOP_SCOM_REPLACE:
                {
                    ScomEntry_t* scomReplace = NULL;

                    if( pEntryLocation )
                    {
                        scomReplace = pEntryLocation;
                    }
                    else
                    {
                        scomReplace = pTableEndLocationtable;
                    }

                    l_rc = updateScomEntry( swizzleAddr,
                                            swizzleData, scomReplace );
                }
                break;

            case P9_STOP_SCOM_OR:
            case P9_STOP_SCOM_AND:
            case P9_STOP_SCOM_NOOP:

                if( pEntryLocation )
                {
                    l_rc = editScomEntry( swizzleAddr,
                                          swizzleData,
                                          pEntryLocation,
                                          i_operation );
                }
                else
                {
                    //Invalid operation requested.
                    MY_ERR( "entry not found edit chiplet Id 0x%08x "
                            "swizzle addr 0x%08x ",
                            chipletId, swizzleAddr );

                    l_rc = STOP_SAVE_SCOM_INVALID_OPERATION;
                }

                break;

            case P9_STOP_SCOM_RESET:
                memset( pScomEntry, nopInst, SCOM_SIZE_PER_CORE  );
                break;

            case P9_STOP_SCOM_OR_APPEND:
            case P9_STOP_SCOM_AND_APPEND:
                {
                    uint32_t tempOperation = P9_STOP_SCOM_APPEND;
                    ScomEntry_t* editAppend = NULL;

                    if( NULL == pEntryLocation )
                    {
                        editAppend = pTableEndLocationtable;
                    }
                    else
                    {
                        editAppend = pEntryLocation;

                        if( P9_STOP_SCOM_OR_APPEND == i_operation )
                        {
                            tempOperation = P9_STOP_SCOM_OR;
                        }
                        else
                        {
                            tempOperation = P9_STOP_SCOM_AND;
                        }
                    }

                    l_rc = editScomEntry( swizzleAddr,
                                          swizzleData,
                                          editAppend,
                                          tempOperation );
                }
                break;

            default:
                l_rc = STOP_SAVE_SCOM_INVALID_OPERATION;
                break;
        }

    }
    while(0);

    if( l_rc )
    {
        MY_ERR("SCOM image operation 0x%08x failed for chiplet 0x%08x addr"
               "0x%08x", i_operation, chipletId ,
               i_scomAddress );
    }

    return l_rc;
}


} //namespace stopImageSection ends

#ifdef __cplusplus
}  //extern "C"
#endif
