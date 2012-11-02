/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfRuleChipDomain.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2012              */
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

#include <prdfRuleChipDomain.H>

//#include <iipstep.h>
//#include <iipsdbug.h>
//#include <iipErrorRegister.h>
//#include <iipServiceDataCollector.h>
//#include <iipCallResolutionTemplate.h>

//------------------------------------------------------------------------------

namespace PRDF
{

bool RuleChipDomain::Query( ATTENTION_TYPE i_attnType )
{
    bool o_rc = false;

    using PluginDef::bindParm;
    SYSTEM_DEBUG_CLASS sysdbug;

    for ( uint32_t i = 0; i < GetSize(); i++ )
    {
        RuleChip * chip = LookUp(i);
        TARGETING::TargetHandle_t l_pchipHandle = LookUp(i)->GetChipHandle();

        if ( sysdbug.IsAttentionActive(l_pchipHandle) )
        {
            // First check if this chip is reporting the correct attention type.
            if ( sysdbug.GetAttentionType(l_pchipHandle) == i_attnType )
            {
                    // If the attention type is a checkstop, check if the chip is
                // reporting based on an externally signaled error condition. If
                // so, ignore this chip (the chip reporting the checkstop will
                // be found later).

                // If the attention type is RECOVERABLE and if the SN chip has an
                // attached MC with a checkstop, ignore this Rec attn.
                //mp01 c Start
                const char * funcName;

                switch(i_attnType)
                {
                    case CHECK_STOP:
                    case UNIT_CS:
                        funcName = "IgnoreCheckstopAttn";
                        break;
                    case RECOVERABLE:
                        funcName = "IgnoreRecoveredAttn";
                        break;
                    case SPECIAL:
                        funcName = "IgnoreSpecialAttn";
                        break;
                    default:
                        continue;
                }

                ExtensibleChipFunction * ef
                  = chip->getExtensibleFunction( funcName, true );

                bool ignore = false;
                (*ef)( chip, bindParm<bool &, const ATTENTION_TYPE>
                       (ignore, i_attnType) );

                if ( ignore )
                    continue;

                o_rc = true;
                break;
                //mp01 c Stop

            }

            // If the attention type is recoverable and this chip is reporting a
            // checkstop, check for recovereable errors on this chip.
            if ( (i_attnType == RECOVERABLE) &&
                 ( (sysdbug.GetAttentionType(l_pchipHandle) == CHECK_STOP) ||
                   (sysdbug.GetAttentionType(l_pchipHandle) == UNIT_CS) ) )
            {
                ExtensibleChipFunction * ef
                           = chip->getExtensibleFunction("CheckForRecovered");
                (*ef)(chip, bindParm<bool &>(o_rc));

                if ( o_rc ) break;
            }
        }
    }

    return o_rc;
}

//------------------------------------------------------------------------------

void RuleChipDomain::Order( ATTENTION_TYPE i_attnType )
{
    using PluginDef::bindParm;
    SYSTEM_DEBUG_CLASS sysdbug;
    const char * funcName;     //mp01 a


    for ( int32_t i = (GetSize() - 1); i >= 0; i-- )
    {
        RuleChip * chip = LookUp(i);
        TARGETING::TargetHandle_t l_pchipHandle = LookUp(i)->GetChipHandle();

        if ( sysdbug.IsAttentionActive(l_pchipHandle) )
        {
            // Move the first chip with this attention type to the front of the
            // list.
            if ( sysdbug.GetAttentionType(l_pchipHandle) == i_attnType )
            {
                   // If the attention type is a checkstop, check if the chip is
                // reporting based on an externally signaled error condition. If
                // so, ignore this chip (the chip reporting the checkstop will
                // be found later).

                // If the attention type is RECOVERABLE and if the SN chip has an
                // attached MC with a checkstop, ignore this Rec attn.
                //mp01 c Start
                switch(i_attnType)
                {
                    case CHECK_STOP:
                    case UNIT_CS:
                        funcName = "IgnoreCheckstopAttn";
                        break;
                    case RECOVERABLE:
                        funcName = "IgnoreRecoveredAttn";
                        break;
                    case SPECIAL:
                        funcName = "IgnoreSpecialAttn";
                        break;
                    default:
                        continue;
                }

                ExtensibleChipFunction * ef
                  = chip->getExtensibleFunction( funcName, true );

                bool ignore = false;
                (*ef)( chip, bindParm<bool &, const ATTENTION_TYPE>
                       (ignore, i_attnType) );

                if ( ignore )
                    continue;

                MoveToFront(i);
                break;
                //mp01 c Stop
            }

            // If the attention type is recoverable and this chip is reporting a
            // checkstop, check for recovereable errors on this chip.
            if ( (i_attnType == RECOVERABLE) &&
                 ( (sysdbug.GetAttentionType(l_pchipHandle) == CHECK_STOP) ||
                   (sysdbug.GetAttentionType(l_pchipHandle) == UNIT_CS) ) )
            {
                ExtensibleChipFunction * ef
                           = chip->getExtensibleFunction("CheckForRecovered");
                bool hasRer = false;
                (*ef)(chip, bindParm<bool &>(hasRer));

                if ( hasRer )
                {
                    MoveToFront(i);
                    break;
                }
            }
        }
    }
}

} // end namespace PRDF
