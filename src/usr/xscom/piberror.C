/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/piberror.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

/**
 *  @file piberror.C
 *
 *  @brief Utility functions to handle PIB errors
 */


#include <errl/errlentry.H>
#include <xscom/piberror.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>

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
         {
       HWAS::callOutPriority chip_priority = HWAS::SRCI_PRIORITY_HIGH;
       HWAS::DeconfigEnum chip_deconfig = HWAS::DELAYED_DECONFIG;

       //If the OCC circular buffer is full, we will see a scom error
       // with this unexpected pib error.  In that case we do not
       // want to callout the processor, instead point to the OCC.
       if( i_scomAddr == 0x0006B035 )
       {
           if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
           {
               //cannot find the OCC so just callout the chip, but
               // still do not deconfig it
               chip_deconfig = HWAS::NO_DECONFIG;
           }
           else if( i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_PROC )
           {
               //callout the associated OCC target
               TARGETING::TargetHandleList l_occs;
               TARGETING::getChildChiplets(l_occs,
                                           i_target,
                                           TARGETING::TYPE_OCC);
               for( TARGETING::TargetHandleList::const_iterator l_occ
                    = l_occs.begin();
                    l_occ != l_occs.end();
                    ++l_occ )
               {
                   io_errl->addHwCallout( *l_occ,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::NO_DECONFIG,
                                          HWAS::GARD_NULL );
                   chip_priority = HWAS::SRCI_PRIORITY_LOW;
               }
               //Note: if there are no OCC targets, we'll just end
               // up calling out the proc as HIGH
               chip_deconfig = HWAS::NO_DECONFIG;
           }
       }

       //Invalid Address should just be a code bug, but it seems that there
       //  are cases where bad hardware can also cause this problem
       //Since we assume code is good before going out, make the
       //  chip callout a higher priority (unless we hit the OCC case above)
       io_errl->addHwCallout( i_target,
                              chip_priority,
                              chip_deconfig,
                              HWAS::GARD_NULL );
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
       break;
         }
     case PIB::PIB_PARITY_ERROR: //b110
     case PIB::PIB_TIMEOUT: //b111
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL );
       break;

     case  PIB::PIB_CLOCK_ERROR: //b101
        if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            // SENTINEL is a proc so use the OSC path
            io_errl->addClockCallout(i_target,
                                HWAS::OSCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_LOW);
        }
        else if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
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
