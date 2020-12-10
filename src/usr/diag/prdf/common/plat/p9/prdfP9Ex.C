/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Ex.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

#include <prdfP9ExDataBundle.H>
#include <prdfP9ExExtraSig.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThreshold.H>
#include <UtilHash.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Ex
{

/**
 * @brief  Plugin that initializes the EX data bundle.
 * @param  i_exChip An ex chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_exChip )
{
    i_exChip->getDataBundle() = new P9ExDataBundle( i_exChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, Initialize );

/**
 * @brief Adds L2 Line Delete/Column Repair FFDC to an SDC.
 * @param i_exChip An ex chip.
 * @param io_sc     Step code data struct.
 */
void addL2LdCrFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                    LD_CR_FFDC::L2LdCrFfdc & i_LdCrFfdc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and
    // adjust the size for endianness.
    static const size_t sz_maxData =
        ((sizeof(LD_CR_FFDC::L2LdCrFfdc) + sz_word-1) / sz_word) * sz_word;

    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );
    memcpy( &data, &i_LdCrFfdc, sz_maxData);

    // Fix endianness issues with non PPC machines.
#if( __BYTE_ORDER == __LITTLE_ENDIAN )

    for ( uint32_t i = 0; i < (sz_maxData/sz_word); i++ )
        ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

#endif

    // Add data to capture data.
    BitString  bs( sz_maxData*8, (CPU_WORD *) &data );
    cd.Add( i_chip->getTrgt(),
            Util::hashString(LD_CR_FFDC::L2TITLE), bs );
}

/**
 * @brief Adds L3 Line Delete/Column Repair FFDC to an SDC.
 * @param i_exChip An ex chip.
 * @param io_sc     Step code data struct.
 */
void addL3LdCrFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                    LD_CR_FFDC::L3LdCrFfdc & i_LdCrFfdc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and
    // adjust the size for endianness.
    static const size_t sz_maxData =
        ((sizeof(LD_CR_FFDC::L3LdCrFfdc) + sz_word-1) / sz_word) * sz_word;

    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );
    memcpy( &data, &i_LdCrFfdc, sz_maxData);

    // Fix endianness issues with non PPC machines.
#if( __BYTE_ORDER == __LITTLE_ENDIAN )

    for ( uint32_t i = 0; i < (sz_maxData/sz_word); i++ )
        ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

#endif

    // Add data to capture data.
    BitString bs( sz_maxData*8, (CPU_WORD *) &data );
    cd.Add( i_chip->getTrgt(),
            Util::hashString(LD_CR_FFDC::L3TITLE), bs );
}


/**
 * @brief  Handle an L2 UE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L2UE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p9_l2err_extract_err_data errorAddr =
        { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL2Err( i_chip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L2UE] HUID: 0x%08x extractL2Err failed",
                  i_chip->GetId());
        return SUCCESS;
    }

    PRDF_TRAC( "[L2UE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d macro=%d ow_select=%x bitline=%x is_top_sa=%x "
               "is_left_sa=%x addr=%x",
               i_chip->GetId(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.macro, errorAddr.ow_select,
               errorAddr.bitline, errorAddr.is_top_sa,
               errorAddr.is_left_sa, errorAddr.address );

    // Add L2 FFDC
    P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
    l_bundle->iv_L2LDCount++;

    LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
    ldcrffdc.L2LDcnt        = l_bundle->iv_L2LDCount;
    ldcrffdc.L2errMember    = errorAddr.member;
    ldcrffdc.L2errDW        = errorAddr.dw;
    ldcrffdc.L2errMacro     = errorAddr.macro;
    ldcrffdc.L2errBank      = errorAddr.bank;
    ldcrffdc.L2errOWSelect  = errorAddr.ow_select;
    ldcrffdc.L2errBitLine   = errorAddr.bitline;
    ldcrffdc.L2errIsTopSA   = errorAddr.is_top_sa;
    ldcrffdc.L2errIsLeftSA  = errorAddr.is_left_sa;
    ldcrffdc.L2errAddress   = errorAddr.address;
    addL2LdCrFfdc( i_chip, io_sc, ldcrffdc );

#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L2UE );

/**
 * @brief  Handle an L3 UE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L3UE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p9_l3err_extract_err_data errorAddr = { L3ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL3Err( i_chip->getTrgt(), errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L3CE] HUID: 0x%08x extractL3Err failed",
                  i_chip->GetId());
        return SUCCESS;
    }

    PRDF_TRAC( "[L3CE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d dataout=%d hashed addr=%x cache addr=%x",
               i_chip->GetId(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.dataout,
               errorAddr.hashed_real_address_45_56,
               errorAddr.cache_read_address );

    // Add L3 FFDC
    P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
    l_bundle->iv_L3LDCount++;

    LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
    ldcrffdc.L3LDcnt           = l_bundle->iv_L3LDCount;
    ldcrffdc.L3errMember       = errorAddr.member;
    ldcrffdc.L3errDW           = errorAddr.dw;
    ldcrffdc.L3errBank         = errorAddr.bank;
    ldcrffdc.L3errDataOut      = errorAddr.dataout;
    ldcrffdc.L3errHshAddress   = errorAddr.hashed_real_address_45_56;
    ldcrffdc.L3errCacheAddress = errorAddr.cache_read_address;
    addL3LdCrFfdc( i_chip, io_sc, ldcrffdc );

#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L3UE );

/**
 * @brief  Handle an L2 CE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L2CE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
#if defined(__HOSTBOOT_RUNTIME) || defined(ESW_SIM_COMPILE)

    do {
        P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
        uint16_t l_maxLineDelAllowed = 0;
        int32_t l_rc = SUCCESS;

#ifdef __HOSTBOOT_RUNTIME
        p9_l2err_extract_err_data errorAddr =
            { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        l_rc = extractL2Err( i_chip->getTrgt(), true, errorAddr );
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L2CE] HUID: 0x%08x extractL2Err failed",
                      i_chip->GetId());
            break;
        }

        PRDF_TRAC( "[L2CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d macro=%d ow_select=%x bitline=%x is_top_sa=%x "
                   "is_left_sa=%x addr=%x",
                   i_chip->GetId(), errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.macro, errorAddr.ow_select,
                   errorAddr.bitline, errorAddr.is_top_sa,
                   errorAddr.is_left_sa, errorAddr.address );

        LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
        ldcrffdc.L2LDcnt        = l_bundle->iv_L2LDCount;
        ldcrffdc.L2errMember    = errorAddr.member;
        ldcrffdc.L2errDW        = errorAddr.dw;
        ldcrffdc.L2errMacro     = errorAddr.macro;
        ldcrffdc.L2errBank      = errorAddr.bank;
        ldcrffdc.L2errOWSelect  = errorAddr.ow_select;
        ldcrffdc.L2errBitLine   = errorAddr.bitline;
        ldcrffdc.L2errIsTopSA   = errorAddr.is_top_sa;
        ldcrffdc.L2errIsLeftSA  = errorAddr.is_left_sa;
        ldcrffdc.L2errAddress   = errorAddr.address;
        addL2LdCrFfdc( i_chip, io_sc, ldcrffdc );
#endif
        if (mfgMode())
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_MNFG_TH_L2_LINE_DELETES>();
        else
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_FIELD_TH_L2_LINE_DELETES>();

        // Ensure we're still allowed to issue repairs
        if (l_bundle->iv_L2LDCount >= l_maxLineDelAllowed)
        {
            PRDF_TRAC( "[L2CE] HUID: 0x%08x No more repairs allowed",
                       i_chip->GetId());

            // MFG wants to be able to ignore these errors
            // If they have LD  allowed set to 0, wait for
            // predictive threshold
            if (!mfgMode() ||
                l_maxLineDelAllowed != 0 )
            {
                io_sc.service_data->SetThresholdMaskId(0);
            }
            break;
        }

        // Add to CE table and Check if we need to issue a repair on this CE
        if (l_bundle->iv_L2CETable->addAddress(l_bundle->iv_L2LDCount,
                                               io_sc) == false)
        {
            // No action required on this CE, we're waiting for additional
            // errors before applying a line delete
            break;
        }

        // Execute the line delete
        PRDF_TRAC( "[L2CE] HUID: 0x%08x apply directed line delete",
                        i_chip->GetId());
#ifdef __HOSTBOOT_RUNTIME
        l_rc = l2LineDelete(i_chip->getTrgt(), errorAddr);
#endif
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L2CE] HUID: 0x%08x l2LineDelete failed",
                      i_chip->GetId());
            // Set signature to indicate L2 Line Delete failed
            io_sc.service_data->SetErrorSig(
                            PRDFSIG_P9EX_L2CE_LD_FAILURE);
        }
        else
        {
            l_bundle->iv_L2LDCount++;

            // Set signature to indicate L2 Line Delete issued
            io_sc.service_data->SetErrorSig(
                                PRDFSIG_P9EX_L2CE_LD_ISSUED);
        }

    } while(0);

#endif

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L2CE );

/**
 * @brief Handle an L3 CE
 * @param i_chip Ex chip.
 * @param io_sc Step Code data struct
 * @return PRD return code
 */
int32_t L3CE( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{

#if defined(__HOSTBOOT_RUNTIME) || defined(ESW_SIM_COMPILE)

    do {
        P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
        uint16_t l_maxLineDelAllowed = 0;
        uint16_t curMem = 0xFFFF;
        int32_t l_rc = SUCCESS;

#ifdef __HOSTBOOT_RUNTIME
        p9_l3err_extract_err_data errorAddr =
            { L3ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        l_rc = extractL3Err( i_chip->getTrgt(), errorAddr );
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L3CE] HUID: 0x%08x extractL3Err failed",
                      i_chip->GetId());
            break;
        }

        PRDF_TRAC( "[L3CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d dataout=%d hashed addr=%x cache addr=%x",
                   i_chip->GetId(), errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.dataout,
                   errorAddr.hashed_real_address_45_56,
                   errorAddr.cache_read_address );

        LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
        ldcrffdc.L3LDcnt           = l_bundle->iv_L3LDCount;
        ldcrffdc.L3errMember       = errorAddr.member;
        ldcrffdc.L3errDW           = errorAddr.dw;
        ldcrffdc.L3errBank         = errorAddr.bank;
        ldcrffdc.L3errDataOut      = errorAddr.dataout;
        ldcrffdc.L3errHshAddress   = errorAddr.hashed_real_address_45_56;
        ldcrffdc.L3errCacheAddress = errorAddr.cache_read_address;
        addL3LdCrFfdc( i_chip, io_sc, ldcrffdc );

        curMem = errorAddr.member;
#endif

        if (mfgMode())
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_MNFG_TH_L3_LINE_DELETES>();
        else
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_FIELD_TH_L3_LINE_DELETES>();

        // Ensure we're still allowed to issue repairs
        if (l_bundle->iv_L3LDCount >= l_maxLineDelAllowed)
        {
            PRDF_TRAC( "[L3CE] HUID: 0x%08x No more repairs allowed",
                       i_chip->GetId());

            // MFG wants to be able to ignore these errors
            // If they have LD  allowed set to 0, wait for
            // predictive threshold
            if (!mfgMode() ||
                l_maxLineDelAllowed != 0 )
            {
                io_sc.service_data->SetThresholdMaskId(0);
            }
            break;
        }

        // Add to CE table and Check if we need to issue a repair on this CE
        if (l_bundle->iv_L3CETable->addAddress(l_bundle->iv_L3LDCount,
                                               io_sc) == false)
        {
            // No action required on this CE, we're waiting for additional
            // errors before applying a line delete
            break;
        }

        // Check for multi-bitline fail
        Timer curTime = io_sc.service_data->GetTOE();
        uint16_t prvMem = l_bundle->iv_prevMember;

        if ( prvMem != 0xFFFF && // we have data saved from a previous LD
             l_bundle->iv_blfTimeout > curTime && // the timer has not expired
             prvMem != curMem ) // the current fail is on a different bitline
        {
            // We have multiple bit lines failing within a 24 hour period
            // Make this predictive
            PRDF_TRAC( "[L3CE] HUID: 0x%08x Multi-bitline fail detected",
                       i_chip->GetId() );
            io_sc.service_data->SetThresholdMaskId(0);
            io_sc.service_data->SetErrorSig( PRDFSIG_P9EX_L3CE_MBF_FAIL );
            break;
        }

        // Update saved bitline data
        l_bundle->iv_prevMember = curMem;
        l_bundle->iv_blfTimeout = curTime + Timer::SEC_IN_DAY;


        PRDF_TRAC( "[L3CE] HUID: 0x%08x apply directed line delete",
                i_chip->GetId());
        #ifdef __HOSTBOOT_RUNTIME
        l_rc = l3LineDelete(i_chip->getTrgt(), errorAddr);
        #endif


        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L3CE] HUID: 0x%08x l3LineDelete failed",
                      i_chip->GetId());
            // Set signature to indicate L3 Line Delete failed
            io_sc.service_data->SetErrorSig(
                            PRDFSIG_P9EX_L3CE_LD_FAILURE);
        }
        else
        {
            l_bundle->iv_L3LDCount++;

            // Set signature to indicate L3 Line Delete issued
            io_sc.service_data->SetErrorSig(
                                PRDFSIG_P9EX_L3CE_LD_ISSUED);
        }

    } while(0);

#endif

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L3CE );

}
}
