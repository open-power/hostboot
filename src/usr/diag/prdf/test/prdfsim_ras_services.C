/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsim_ras_services.C $               */
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

#include "prdfsim_ras_services.H"
#include "prdfsimServices.H"
#include "stdio.h"
#include <targeting/common/targetservice.H>


namespace PRDF
{

errlHndl_t SimErrDataService::GenerateSrcPfa(ATTENTION_TYPE attn_type,
                                             ServiceDataCollector & i_sdc)

{
    using namespace TARGETING;
    using namespace PlatServices;

    PRDF_ENTER("SimErrDataService::GenerateSrcPfa()");
    errlHndl_t errLog = NULL;

    // call the actual ras services function
    errLog = ErrDataService::GenerateSrcPfa(attn_type, i_sdc);

    ErrorSignature * esig = i_sdc.GetErrorSignature();

    // report the actual signature
    getSimServices().reportSig(esig->getChipId(), esig->getSigId());

    PRDF_EXIT("SimErrDataService::GenerateSrcPfa()");

    return errLog;

}

} // End namespace PRDF
