/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfRuleChipDomain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2014              */
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
