
/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/piberror.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
 *
 * @param[in]  i_target        Operation target
 * @param[in]  i_pibErrStatus  Error Status bits retrieved
 * @param[in/out] io_errl      Originating errorlog that we will add Fru
 *                             Callouts to.
 * @return none
 */
void addFruCallouts(TARGETING::Target* i_target,
                    uint32_t  i_pibErrStatus,
                    errlHndl_t& io_errl)
{
   switch (i_pibErrStatus)
   {
     case  PIB::PIB_CHIPLET_OFFLINE:
     case  PIB::PIB_PARTIAL_GOOD:
     case  PIB::PIB_INVALID_ADDRESS:
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);

       break;
     case PIB::PIB_PARITY_ERROR:
     case PIB::PIB_TIMEOUT:
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL );
       break;
     case  PIB::PIB_CLOCK_ERROR:
        if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_PROC)
        {
            io_errl->addClockCallout(i_target,
                                HWAS::OSCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_LOW);
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
       break;

   }
}

} // end of namespace
