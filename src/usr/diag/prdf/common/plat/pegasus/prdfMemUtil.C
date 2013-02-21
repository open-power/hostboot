/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfMemUtil.C $         */
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

/** @file prdfMemUtil.C */

#include <prdfMemUtil.H>

#include <iipconst.h>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>

namespace PRDF
{
namespace MemUtil
{

#ifdef __HOSTBOOT_MODULE

int32_t clearHostAttns( ExtensibleChip * i_memChip,
                        STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;

    int32_t o_rc = SUCCESS;

    TargetHandle_t memHandle = i_memChip->GetChipHandle();

    do
    {
        // Get the attached MCS chip.
        ExtensibleChip * mcsChip = i_memChip;
        if ( TYPE_MCS != PlatServices::getTargetType(memHandle) )
        {
            TargetHandleList list = PlatServices::getConnected( memHandle,
                                                                TYPE_MCS );
            if ( 1 == list.size() )
                mcsChip = (ExtensibleChip *)systemPtr->GetChip( list[0] );
            else
            {
                PRDF_ERR( "[MemUtil::clearHostAttns] getConnected() failed" );
                o_rc = FAIL;
                break;
            }
        }

        // Clear FIR bits based on the cause attention type.
        // Note: The cause attention type is different than the global attention
        //       type, in that it is the attention type that we actually
        //       isolated to. For example, the global attention type could be
        //       CHECK_STOP but the cause atttention type could be RECOVERABLE.
        SCAN_COMM_REGISTER_CLASS * firand = mcsChip->getRegister("MCIFIR_AND");
        firand->setAllBits();

        ATTENTION_TYPE l_attnType = i_sc.service_data->GetCauseAttentionType();
        switch ( l_attnType )
        {
            case CHECK_STOP:  firand->ClearBit(12); break;
            case RECOVERABLE: firand->ClearBit(15); break;
            case SPECIAL:     firand->ClearBit(16);
                              firand->ClearBit(17); break;
            default:
                PRDF_ERR( "[MemUtil::clearHostAttns] Invalid attention type %d",
                          l_attnType );
                o_rc = FAIL;
                break;
        }
        if ( SUCCESS != o_rc ) break;

        o_rc = firand->Write();
        if ( SUCCESS != o_rc)
        {
            PRDF_ERR( "[MemUtil::clearHostAttns] MCIFIR_AND write failed" );
            break;
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[MemUtil::clearHostAttns] Failed: i_memChip=0x%08x",
                  PlatServices::getHuid(memHandle) );
    }

    return o_rc;
}

#endif // __HOSTBOOT_MODULE

} // end namespace MemUtil
} // end namespace PRDF

