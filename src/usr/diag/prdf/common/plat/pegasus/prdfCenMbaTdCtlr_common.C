/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_common.C $ */
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

#include <prdfCenMbaTdCtlr_common.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::cleanupPrevCmd()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::cleanupPrevCmd] "

    int32_t o_rc = SUCCESS;

    // Clean up the current maintenance command. This must be done whenever
    // maintenance command will no longer be executed.
    if ( NULL != iv_mssCmd )
    {
        o_rc = iv_mssCmd->cleanupCmd();
        if ( SUCCESS != o_rc )
            PRDF_ERR( PRDF_FUNC"cleanupCmd() failed" );

        delete iv_mssCmd; iv_mssCmd = NULL;
    }

    // Clear the command complete attention. This must be done before starting
    // the next maintenance command.
    SCAN_COMM_REGISTER_CLASS * firand = iv_mbaChip->getRegister("MBASPA_AND");
    firand->setAllBits();

    firand->ClearBit(0); // Maintenance command complete
    firand->ClearBit(8); // Maintenance command complete (DD1.0 workaround)

    int32_t l_rc = firand->Write();
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Write() failed on MBASPA_AND" );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::chipMarkCleanup()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::chipMarkCleanup] "

    int32_t o_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * ddrPhyAndFir =
                                 iv_mbaChip->getRegister( "MBADDRPHYFIR_AND" );
        ddrPhyAndFir->setAllBits();

        ddrPhyAndFir->ClearBit(50); // Calibration Error RE 0
        ddrPhyAndFir->ClearBit(58); // Calibration Error RE 1

        o_rc = ddrPhyAndFir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBADDRPHYFIR_AND" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool CenMbaTdCtlrCommon::isInTdMode()
{
    return ( (NO_OP != iv_tdState) && (MAX_TD_STATE > iv_tdState) );
}

} // end namespace PRDF

