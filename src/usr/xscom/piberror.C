/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/piberror.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/**
 *  @file piberror.C
 *
 *  @brief Utility functions to handle PIB errors
 */


#include <errl/errlentry.H>
#include <xscom/piberror.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>

namespace PIB
{

/**
 * @brief Add callouts to an errorlog based on the type of PIB error could be a
 *             hardware or procedure callout
 */
void addFruCallouts(TARGETING::Target* i_target,
                    uint32_t  i_pibErrStatus,
                    uint64_t i_scomAddr,
                    errlHndl_t& io_errl)
{
   switch (i_pibErrStatus)
   {
     case  PIB::PIB_CHIPLET_OFFLINE: //b010
       //Offline should just be a code bug, but it seems that there are
       //  cases where bad hardware can also cause this problem
       //Since we assume code is good before going out, make the
       //  hw callout a higher priority
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
       break;

     case  PIB::PIB_PARTIAL_GOOD: //b011
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
       break;

     case  PIB::PIB_INVALID_ADDRESS: //b100
       //Invalid Address should just be a code bug, but it seems that there
       //  are cases where bad hardware can also cause this problem
       //Since we assume code is good before going out, make the
       //  hw callout a higher priority
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
       break;

     case PIB::PIB_PARITY_ERROR: //b110
     case PIB::PIB_TIMEOUT: //b111
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL );
       break;

     case  PIB::PIB_CLOCK_ERROR: //b101
        if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_PROC)
        {
            //check for PCI range
            if( ((i_scomAddr & 0xFF000000) == 0x09000000)
                && ((i_scomAddr & 0x00FF0000) != 0x000F0000) )
            {
                io_errl->addClockCallout(i_target,
                                         HWAS::OSCPCICLK_TYPE,
                                         HWAS::SRCI_PRIORITY_LOW);
            }
            //for everything else blame the ref clock
            else
            {
                io_errl->addClockCallout(i_target,
                                         HWAS::OSCREFCLK_TYPE,
                                         HWAS::SRCI_PRIORITY_LOW);
            }
        }
        else if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_MEMBUF)
        {
            io_errl->addClockCallout(i_target,
                                     HWAS::MEMCLK_TYPE,
                                     HWAS::SRCI_PRIORITY_LOW);
        }
        else // for anything else, just blame the refclock
        {
            io_errl->addClockCallout(i_target,
                                HWAS::OSCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_LOW);
        }
       break;

     default:
       // Anything else would most likely be a code bug
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
       break;

   }
}

} // end of namespace
