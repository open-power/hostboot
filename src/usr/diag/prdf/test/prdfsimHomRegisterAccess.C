/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimHomRegisterAccess.C $           */
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

#include "prdfsimHomRegisterAccess.H"
#include "prdfsimServices.H"
#include "prdfsimScrDB.H"
#include <prdfTrace.H>

namespace PRDF
{

SimScomAccessor::SimScomAccessor()
: ScomAccessor()
{}

SimScomAccessor::~SimScomAccessor()
{

}

uint32_t SimScomAccessor::Access(TARGETING::TargetHandle_t i_target,
                                     BIT_STRING_CLASS & bs,
                                     uint64_t registerId,
                                     MopRegisterAccess::Operation operation) const
{
    PRDF_DENTER("SimScomAccessor::Access()");
    uint32_t rc = SUCCESS;
    ScrDB::SimOp l_op = ScrDB::MAX_OP;

    do
    {
// Don't want to issue actual scom op to HW
//        rc = HomRegisterAccessScom::Access( bs, registerId, operation);
        switch (operation)
            {
        case MopRegisterAccess::WRITE: l_op = ScrDB::WRITE; break;
        case MopRegisterAccess::READ:  l_op = ScrDB::READ;  break;
        default:
            PRDF_ERR( "SimScomAccessor::Access() unsupported operation: 0x%X", operation );
            break;
            }
        getSimServices().processCmd(i_target, bs, registerId, l_op);

    } while(0);

    PRDF_DEXIT("SimScomAccessor::Access()");

    return rc;
}

} // End namespace PRDF
