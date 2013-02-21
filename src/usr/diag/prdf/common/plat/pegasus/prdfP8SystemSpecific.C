/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8SystemSpecific.C $ */
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

#include <prdfSystemSpecific.H>
#include <prdfGlobal.H>
#include <prdfPegasusConfigurator.H>
#include <prdfPlatServices.H>

namespace PRDF
{

namespace SystemSpecific
{
    PRDF::Configurator * getConfiguratorPtr()
    {
        return new PRDF::PegasusConfigurator;
    }

    void postAnalysisWorkarounds(STEP_CODE_DATA_STRUCT & i_sdc)
    {
        return;
    }
};

} // end namespace PRDF
