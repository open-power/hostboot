/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfRepairHealth.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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

#include <prdfRepairHealth.H>
#include <svpdextstructs.H>
#include <svpdextinterface.H>
#include <limits.h>

//#include <prdfP7McRepairHealth.H>

tracDesc_t g_asmTracDesc;
#ifdef __HOSTBOOT_MODULE
TRAC_INIT( &g_asmTracDesc, PRDF_COMP_NAME, KILOBYTE );
#else
TRAC_INIT( &g_asmTracDesc, PRDF_COMP_NAME, 4096 );
#endif

/* prdfGetRepairHealthStatus
 *         Get repair objects for FRU.
 */
errlHndl_t prdfGetRepairHealthStatus(uint32_t i_rid,
                            std::vector<PrdfRepairHealthStatus> & o_repairs)
{
    o_repairs.clear();

    errlHndl_t l_errl = NULL;
/*
    svpd_FruEnum l_fruType;

    do
    {

        // Determine RID's FRU type.
        l_errl = SVPD_get_frutype(i_rid, &l_fruType);
        if (NULL != l_errl) break;

        switch(l_fruType)
        {
            case FRU_MS:
                prdfP7McGetDimmRepairHealthStatus( i_rid, o_repairs );
                break;

            case FRU_PF:
            prdfP7McGetInterfaceRepairHealthStatus( i_rid, o_repairs);
            break;

            default:
                break;
        }
    } while (false);
*/
    return l_errl;
}

