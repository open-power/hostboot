/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Proc.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/** @file  prdfP9Proc.C
 *  @brief Contains all the plugin code for the PRD P9 Proc
 */

// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <xspprdService.h>

#ifdef __HOSTBOOT_MODULE
#include <prdfPlatServices_ipl.H>
#endif

// Platform includes

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Used when the chip has a CHECK_STOP or UNIT_CS attention to check for
 *         the presence of recoverable attentions.
 * @param  i_chip         A P9 chip.
 * @param  o_hasRecovered True if the chip has a recoverable attention.
 * @return SUCCESS
 */
int32_t CheckForRecovered( ExtensibleChip * i_chip,
                           bool & o_hasRecovered )
{
    o_hasRecovered = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_grer = i_chip->getRegister("GLOBAL_RE_FIR");
    l_rc = l_grer->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForRecovered] GLOBAL_RE_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_grer->GetBitFieldJustified(1,55) )
    {
        o_hasRecovered = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, CheckForRecovered );

//------------------------------------------------------------------------------
/**
 * @brief Used when the chip is queried, by the fabric domain, for RECOVERED
 * attentions to assign a severity to the attention for sorting.
 * @param[in]   i_chip - P8 chip
 * @param[out]  o_sev - Priority order (lowest to highest):
 *  1 - Core chiplet checkstop
 *  2 - Core chiplet error
 *  3 - PCB chiplet error (TOD logic)
 *  4 - Other error
 *  5 - Memory controller chiplet
 *
 * @return SUCCESS
 *
 */
int32_t CheckForRecoveredSev(ExtensibleChip * i_chip, uint32_t & o_sev)
{
    int32_t o_rc = SUCCESS;
    bool l_runtime = atRuntime();

    SCAN_COMM_REGISTER_CLASS * l_rer = NULL;

    SCAN_COMM_REGISTER_CLASS * l_unitxstp = NULL;
    if ( l_runtime )
    {
        l_unitxstp = i_chip->getRegister("GLOBAL_UCS_FIR");
        o_rc |= l_unitxstp->Read();
    }

    l_rer = i_chip->getRegister("GLOBAL_RE_FIR");
    o_rc |= l_rer->Read();

    if (o_rc)
    {
        PRDF_ERR( "[CheckForRecoveredSev] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    if (l_rer->GetBitFieldJustified(7,2))
    {
        // errors from MC chiplets
        o_sev = 5;
    }
    else if(l_rer->GetBitFieldJustified(2, 4) ||
            l_rer->GetBitFieldJustified(9, 4) ||
            l_rer->GetBitFieldJustified(13,3) ||
            l_rer->IsBitSet(6))
    {
        // errors from PB, Xbus, OB, or PCI chiplets
        o_sev = 4;
    }
    else if(l_rer->IsBitSet(1))
    {
        // error from TP
        o_sev = 3;
    }
    else if (l_rer->GetBitFieldJustified(16,6))
    {
        // error from EQ
        o_sev = 2;
    }
    else if(l_runtime &&
            (l_rer->GetBitFieldJustified(32,24) &
             l_unitxstp->GetBitFieldJustified(32,24)) == 0 )
    {
        // core recoverable
        o_sev = 2;
    }
    else
    {
        // core checkstop
        o_sev = 1;
    }

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, CheckForRecoveredSev );

/** @func GetCheckstopInfo
 *  To be called from the fabric domain to gather Checkstop information.  This
 *  information is used in a sorting algorithm.
 *
 *  This is a plugin function: GetCheckstopInfo
 *
 *  @param i_chip - The chip.
 *  @param o_wasInternal - True if this chip has an internal checkstop.
 *  @param o_externalChips - List of external fabrics driving checkstop.
 *  @param o_wofValue - Current WOF value (unused for now).
 */
int32_t GetCheckstopInfo( ExtensibleChip * i_chip,
                          bool & o_wasInternal,
                          TargetHandleList & o_externalChips,
                          uint64_t & o_wofValue )
{
    // Clear parameters.
    o_wasInternal = false;
    o_externalChips.clear();
    o_wofValue = 0;

    SCAN_COMM_REGISTER_CLASS * l_globalFir =
      i_chip->getRegister("GLOBAL_CS_FIR");

    SCAN_COMM_REGISTER_CLASS * l_pbXstpFir =
      i_chip->getRegister("N3_CHIPLET_CS_FIR");

    SCAN_COMM_REGISTER_CLASS * l_extXstpFir =
      i_chip->getRegister("PBEXTFIR");

    int32_t o_rc = SUCCESS;
    o_rc |= l_globalFir->Read();
    o_rc |= l_pbXstpFir->Read();
    o_rc |= l_extXstpFir->Read();

    if(o_rc)
    {
        PRDF_ERR( "[GetCheckstopInfo] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    uint8_t l_connectedXstps = l_extXstpFir->GetBitFieldJustified(0,7);

    bool pbXstpFromOtherChip = l_pbXstpFir->IsBitSet(2);

    if ((0 != l_globalFir->GetBitFieldJustified(0,56)) &&
        (!l_globalFir->IsBitSet(5) || !pbXstpFromOtherChip))
        o_wasInternal = true;

    // Get connected chips.
    uint32_t l_positions[] =
    {
        0, // bit 0 - XBUS 0
        1, // bit 1 - XBUS 1
        2, // bit 2 - XBUS 2
        0, // bit 3 - OBUS 0
        1, // bit 4 - OBUS 1
        2, // bit 5 - OBUS 2
        3  // bit 6 - OBUS 3
    };

    for (uint8_t i = 0, j = 0x40; i < 7; i++, j >>= 1)
    {
        if (0 != (j & l_connectedXstps))
        {
            TargetHandle_t l_connectedFab =
              getConnectedPeerProc(i_chip->GetChipHandle(),
                                   i<3 ? TYPE_XBUS : TYPE_OBUS,
                                   l_positions[i]);

            if (NULL != l_connectedFab)
            {
                o_externalChips.push_back(l_connectedFab);
            }
        }
    }

    // Read WOF value.
    SCAN_COMM_REGISTER_CLASS * l_wof = i_chip->getRegister("TODWOF");
    o_rc |= l_wof->Read();

    if(o_rc)
    {
        PRDF_ERR( "[GetCheckstopInfo] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    o_wofValue = l_wof->GetBitFieldJustified(0,64);

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, GetCheckstopInfo );

//------------------------------------------------------------------------------

int32_t checkNimbusDD10( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    TargetHandle_t trgt = i_chip->getTrgt();

    // It does look a little weird to return FAIL when the chip is Nimbus DD1.0,
    // but the purpose of this plugin is to give a non-SUCCESS return code to
    // the 'try' statement in rule code so that it will execute actions
    // specifically for Nimbus DD1.0 in the default branch of the 'try'.
    // statement.

    if ( MODEL_NIMBUS == getChipModel(trgt) && 0x10 == getChipLevel(trgt) )
        return FAIL;
    else
        return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, checkNimbusDD10 );

int32_t checkNotNimbusDD10( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    // Return the opposite of checkNimbusDD10().
    return (FAIL == checkNimbusDD10(i_chip, io_sc)) ? SUCCESS : FAIL;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, checkNotNimbusDD10 );

//------------------------------------------------------------------------------

int32_t isHostAttnFirAccessible(ExtensibleChip * i_chip, bool & o_isOkToAccess)
{
    o_isOkToAccess = false;

    // Host Processor side can always access the 'host' attn reg
    // The FSP can not access it during IPL steps 15 thru 16.2
    // Host attn is only needed for MS diag and runtime case.

    if ( (true == atRuntime())
#ifdef __HOSTBOOT_MODULE
          || (true == isInMdiaMode())
#endif
       )
    {
        o_isOkToAccess = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, isHostAttnFirAccessible );

//------------------------------------------------------------------------------

int32_t isUcsFirAccessible(ExtensibleChip * i_chip, bool & o_isOkToAccess)
{
    o_isOkToAccess = (true == atRuntime()) ? true : false;

    // Host Processor side can always access the 'unitCS' reg
    // The FSP can not access it during IPL steps 15 thru 16.2
    // We  don't really use unitCs at this time.

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, isUcsFirAccessible );

//------------------------------------------------------------------------------

/** Call HW server rtn for Deadman Timer */
int32_t handleDeadmanTimer( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    TARGETING::TargetHandle_t  l_target = i_chip->getTrgt();


    // This routine adds FFDC information to the elog
    // and will also do the callouts as needed.
    deadmanTimerFFDC( l_target, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus, Proc, handleDeadmanTimer );
//------------------------------------------------------------------------------


} // end namespace Proc

} // end namespace PRDF
