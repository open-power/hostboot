/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgThresholdFile.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#include <prdfMfgThresholdFile.H>
#include <prdfGlobal.H>
#include <prdfAssert.h>
#include <prdfMfgThresholdSync.H>
#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

namespace PRDF
{

void MfgThresholdFile::setup()
{
    syncFromFsp();
}

void MfgThresholdFile::syncFromFsp()
{
    #define FUNC "[MfgThresholdFile::syncFromFsp]"
    PRDF_ENTER(FUNC);

    do
    {
        if ( !PlatServices::mfgMode() )
        {
            PRDF_TRAC(" no-op since not in MFG mode");
            break;
        }

        MfgThresholdSync l_syncer;

        errlHndl_t l_err = l_syncer.syncMfgThresholdFromFsp();
        if (l_err)
        {
            PRDF_ERR(FUNC" failed to sync from the FSP");
            PRDF_COMMIT_ERRL(l_err, ERRL_ACTION_REPORT);
            break;
        }

    } while(0);

    PRDF_EXIT(FUNC);
    #undef FUNC
}

void MfgThresholdFile::packThresholdDataIntoBuffer(
                             uint8_t* & o_buffer,
                             uint32_t i_sizeOfBuf)
{
    #define FUNC "[MfgThresholdFile::packThresholdDataIntoBuffer]"

    PRDF_ERR(FUNC" not used in hostboot");

    #undef FUNC
}


} // end namespace PRDF
