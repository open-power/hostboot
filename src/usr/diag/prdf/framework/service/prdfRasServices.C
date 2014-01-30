/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfRasServices.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file  prdfRasServices.C
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

#include <prdfRasServices.H>
#include <prdfMfgSync.H>
#include <prdfErrlUtil.H>

namespace PRDF
{

void ErrDataService::MnfgTrace( ErrorSignature * i_esig,
                                const PfaData & i_pfaData )
{
    #define PRDF_FUNC "[ErrDataService::MnfgTrace] "
    do
    {
        errlHndl_t errl = NULL;
        errl = getMfgSync().syncMfgTraceToFsp(i_esig, i_pfaData);
        if (errl)
        {
            PRDF_ERR(PRDF_FUNC "failed to sync to the FSP");
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
            break;
        }
    }while(0);
    #undef PRDF_FUNC
}

} // end namespace PRDF

