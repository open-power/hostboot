/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPhbUtils.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file prdfPhbUtils.C */

#include <prdfPhbUtils.H>

#include <prdfPlatServices.H>
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{

int32_t getConfiguredPHB( TargetHandle_t i_procTrgt, uint32_t i_iopciIdx,
                          uint32_t i_clkIdx, TargetHandle_t & o_phbTrgt )
{
    #define PRDF_FUNC "[Proc::getConfiguredPHB] "

    int32_t o_rc = SUCCESS;

    o_phbTrgt = NULL;

    enum TableBounds
    {
        MAX_CONFIGS = 14,
        MAX_FIRS    =  2,
        MAX_CLOCKS  =  2,

        // Array index for the processor models.
        MURANO_IDX = 0,
        VENICE_IDX,
        MAX_MODELS,
    };

    enum TableValues
    {
        // These PHB enums must match the PHB position number.
        PHB0 = 0,
        PHB1,
        PHB2,

        // The dSMP connections are not used but we will still list them in the
        // table just in case the are needed later.
        NONE = MAX_PHB_PER_PROC,
        SMP0 = MAX_PHB_PER_PROC,
        SMP1 = MAX_PHB_PER_PROC,
    };

    static const uint8_t table[MAX_CONFIGS][MAX_MODELS][MAX_FIRS][MAX_CLOCKS] =
    {
        //----------Murano------------||-----------Venice-----------||
        //--IOPCIFIR-0-||-IOPCIFIR-1--||--IOPCIFIR-0-||-IOPCIFIR-1--||
        //----A--|--B--||--A--|--B----||----A--|--B--||--A--|--B----||
        { { {PHB0,PHB0}, {PHB1,NONE} }, { {PHB0,PHB0}, {PHB1,PHB1} }, }, // 0x0
        { { {PHB0,PHB0}, {PHB1,NONE} }, { {PHB0,PHB0}, {PHB1,PHB2} }, }, // 0x1
        { { {PHB0,NONE}, {PHB1,NONE} }, { {PHB0,NONE}, {PHB1,PHB1} }, }, // 0x2
        { { {PHB0,PHB2}, {PHB1,NONE} }, { {PHB0,NONE}, {PHB1,PHB2} }, }, // 0x3
        { { {PHB0,SMP0}, {PHB1,NONE} }, { {PHB0,SMP0}, {PHB1,PHB1} }, }, // 0x4
        { { {PHB0,SMP0}, {PHB1,NONE} }, { {PHB0,SMP0}, {PHB1,PHB2} }, }, // 0x5
        { { {PHB1,PHB1}, {SMP1,NONE} }, { {SMP1,PHB0}, {PHB1,PHB1} }, }, // 0x6
        { { {PHB1,PHB2}, {SMP1,NONE} }, { {SMP1,PHB0}, {PHB1,PHB2} }, }, // 0x7
        { { {SMP1,SMP0}, {PHB1,NONE} }, { {SMP1,SMP0}, {PHB1,PHB1} }, }, // 0x8
        { { {SMP1,SMP0}, {PHB1,NONE} }, { {SMP1,SMP0}, {PHB1,PHB2} }, }, // 0x9
        { { {SMP1,PHB2}, {SMP0,NONE} }, { {SMP1,SMP0}, {PHB1,PHB2} }, }, // 0xA
        { { {PHB1,SMP0}, {SMP1,NONE} }, { {SMP1,SMP0}, {PHB1,PHB2} }, }, // 0xB
        { { {SMP1,PHB2}, {PHB1,NONE} }, { {SMP1,PHB0}, {PHB1,PHB2} }, }, // 0xC
    };

    do
    {
        // Check parameters
        if ( MAX_FIRS <= i_iopciIdx )
        {
            PRDF_ERR( PRDF_FUNC"i_iopciIdx is unsupported: %d", i_iopciIdx );
            o_rc = FAIL; break;
        }

        if ( MAX_CLOCKS <= i_clkIdx )
        {
            PRDF_ERR( PRDF_FUNC"i_clkIdx is unsupported: %d", i_clkIdx );
            o_rc = FAIL; break;
        }

        // Get the processor model and config table.
        MODEL model = getProcModel( i_procTrgt );
        uint32_t modelIdx = MAX_MODELS;
        switch ( model )
        {
            case MODEL_MURANO: modelIdx = MURANO_IDX; break;
            case MODEL_VENICE: modelIdx = VENICE_IDX; break;
            default:
                PRDF_ERR( PRDF_FUNC"unsupported processor model: %d", model );
                o_rc = FAIL;
        }
        if ( SUCCESS != o_rc ) break;

        // Get the PHB configuration.
        uint32_t phbConfig = getPhbConfig( i_procTrgt );
        if ( MAX_CONFIGS <= phbConfig )
        {
            PRDF_ERR( PRDF_FUNC"unsupportd PHB config: %d", phbConfig );
            o_rc = FAIL; break;
        }

        // Get the PHB target, if it exists.
        uint8_t phbPos = table[phbConfig][modelIdx][i_iopciIdx][i_clkIdx];
        if ( MAX_PHB_PER_PROC > phbPos )
        {
            o_phbTrgt = getConnectedChild( i_procTrgt, TYPE_PCI, phbPos );
            if ( NULL == o_phbTrgt ) // Target should exist.
            {
                PRDF_ERR( PRDF_FUNC"getConnectedChild(%d) failed", phbPos );
                o_rc = FAIL; break;
            }
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_procTrgt=0x%08x i_iopciIdx=%d "
                  "i_clkIdx=%d", getHuid(i_procTrgt), i_iopciIdx, i_clkIdx );
    }

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace Proc

} // end namespace PRDF

