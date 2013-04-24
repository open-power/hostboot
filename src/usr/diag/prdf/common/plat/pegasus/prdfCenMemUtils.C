/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMemUtils.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file  prdfCenMemUtils.C
 *  @brief Utility functions related to Centaur
 */

#include <prdfCenMemUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

namespace MemUtils
{

using namespace PlatServices;

const uint8_t CE_REGS_PER_MBA = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

static const char *mbsCeStatReg[][ CE_REGS_PER_MBA ] = {
                       { "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1","MBA0_MBSSYMEC2",
                         "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
                         "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8" },
                       { "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1","MBA1_MBSSYMEC2",
                         "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
                         "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8" }
                          };

int32_t collectCeStats( ExtensibleChip *i_mbaChip, MaintSymbols &o_maintStats,
                      const CenRank & i_rank )
{
    #define PRDF_FUNC "[MemUtils::collectCeStats] "
    int32_t o_rc = SUCCESS;
    do
    {
        TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();
        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip * membufChip = mbadb->getMembChip();
        if ( NULL == membufChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed: MBA=0x%08x",
                      getHuid(mbaTrgt) );
            o_rc = FAIL; break;
        }
        uint8_t mbaPos = getTargetPosition( mbaTrgt );

        for( uint8_t regIdx = 0 ; regIdx < CE_REGS_PER_MBA; regIdx++)
        {
           SCAN_COMM_REGISTER_CLASS * ceReg = membufChip->getRegister(
                                                mbsCeStatReg[mbaPos][regIdx] );

            if( NULL == ceReg )
            {
                PRDF_ERR( PRDF_FUNC"getRegister() Failed for register:%s",
                          mbsCeStatReg[mbaPos][regIdx]);
                break;
            }
            o_rc = ceReg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"%s Read() failed. Target=0x%08x",
                          mbsCeStatReg[mbaPos][regIdx], getHuid(mbaTrgt) );
                break;
            }
            uint8_t baseSymbol = SYMBOLS_PER_CE_REG*regIdx;
            for(uint8_t i = 0 ; i < SYMBOLS_PER_CE_REG; i++)
            {
                uint8_t synCount = ceReg->GetBitFieldJustified( (i*8), 8 );

                if ( 0 == synCount)
                {
                    continue;
                }
                else
                {
                    SymbolData symData;
                    symData.symbol = CenSymbol::fromSymbol( mbaTrgt, i_rank,
                                   baseSymbol+i, CenSymbol::BOTH_SYMBOL_DQS );
                    if ( !symData.symbol.isValid() )
                    {
                        PRDF_ERR( PRDF_FUNC"CenSymbol() failed" );
                        o_rc = FAIL;
                        break;
                    }
                    else
                    {
                        symData.count = synCount;
                        o_maintStats.push_back( symData );
                    }
                }
            }
            if( FAIL == o_rc) break;
        }
        if( FAIL == o_rc) break;
    }while(0);
    return o_rc;
    #undef PRDF_FUNC
}

int32_t getDramSize( ExtensibleChip *i_mbaChip, uint8_t & o_size )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    int32_t o_rc = SUCCESS;
    o_size = SIZE_2GB;

    do
    {
        TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();
        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip * membufChip = mbadb->getMembChip();
        if ( NULL == membufChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed: MBA=0x%08x",
                      getHuid(mbaTrgt) );
            o_rc = FAIL; break;
        }

        uint32_t pos = getTargetPosition(mbaTrgt);
        const char * reg_str = (0 == pos) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";

        SCAN_COMM_REGISTER_CLASS * reg = membufChip->getRegister( reg_str );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s. Target=0x%08x",
                      reg_str, getHuid(mbaTrgt) );
            break;
        }
        o_size = reg->GetBitFieldJustified( 6, 2 );

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace MemUtils

} // end namespace PRDF
