/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdrErrlPluginsSupt.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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

#include <prdrErrlPluginsSupt.H>

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{
PrdrRegIdTable & GetRegisterIdTable()
{
    static PrdrRegIdTable l_idTable = PrdrRegIdTable();
    return l_idTable;
}

PrdrErrSigTable & GetErrorSigTable()
{
    static PrdrErrSigTable l_sigTable = PrdrErrSigTable();
    return l_sigTable;
}

} // namespace FSP/HOSTBBOT
} // end namespace PRDF
