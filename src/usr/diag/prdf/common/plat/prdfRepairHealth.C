/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfRepairHealth.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2012              */
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

#include <prdfRepairHealth.H>
#include <svpdextstructs.H>
#include <svpdextinterface.H>

//#include <prdfP7McRepairHealth.H>

tracDesc_t g_asmTracDesc;
TRAC_INIT( &g_asmTracDesc, PRDF_COMP_NAME, 4096 );

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

