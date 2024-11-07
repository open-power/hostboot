/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_iplControl.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
* @file  sbe_iplControl.C
* @brief Contains the IPL Control Messages for SBE FIFO
*
*/

#include <chipids.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <fapi2.H>
#include <ody_blame_firs.H>
#include <errldisplay/errldisplay.H>
#include <errl/errlentry.H>
#include <algorithm>
#include <fapi2/plat_hwp_invoker.H>

#include <arch/magic.H>
#include <devicefw/driverif.H>
#include <console/consoleif.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"IplControl: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"IplControl: " printf_string,##args)

using namespace TARGETING;
using namespace fapi2;

namespace SBEIO
{
    /**
    * @brief This function will map the enums defined in sbe (sbeioio.H) with those
    *         defined in ody_blame_firs.H and used by MSS.
    *
    * @param[in] i_sbeHwpClass The HWP Class that SBE uses
    * @param[in] i_sbeHwpNum   The HWP Num that SBE uses
    *
    * @return o_mssHwpNum The HWp Num that MSS understands
    *
    */
    inline mss::ipl_substep mapSbeHwpNum(uint8_t i_sbeHwpClass, uint8_t i_sbeHwpNum)
    {
         mss::ipl_substep o_mssHwpNum = mss::ipl_substep::NO_FIR_STEP;
        if (i_sbeHwpClass == SBE_FIFO_EXEC_HWP_CLASS_IO)
        {
            switch (i_sbeHwpNum)
            {
                case IO_ODY_OMI_TRAIN_CHECK:
                    o_mssHwpNum = mss::ipl_substep::OMI_TRAIN_CHECK;
                    break;
                case IO_ODY_OMI_HSS_LOAD_PPE:
                case IO_ODY_OMI_HSS_CONFIG:
                case IO_ODY_OMI_HSS_START_PPE:
                case IO_ODY_OMI_HSS_BIST_INIT:
                case IO_ODY_OMI_HSS_BIST_START:
                case IO_ODY_OMI_HSS_BIST_POLL:
                case IO_ODY_OMI_HSS_BIST_CLEANUP:
                case IO_ODY_OMI_HSS_INIT:
                case IO_ODY_OMI_HSS_DCCAL_START:
                case IO_ODY_OMI_HSS_DCCAL_POLL:
                case IO_ODY_OMI_HSS_TX_ZCAL:
                case IO_ODY_OMI_PRETRAIN_ADV:
                case IO_ODY_OMI_SETUP:
                case IO_ODY_OMI_TRAIN:
                case IO_ODY_OMI_POSTTRAIN_ADV:
                    break;
            }
        }
        else if (i_sbeHwpClass == SBE_FIFO_EXEC_HWP_CLASS_MEMORY)
        {
            switch (i_sbeHwpNum)
            {
                case  MEM_ODY_SCOMINIT:
                    o_mssHwpNum = mss::ipl_substep::OCMB_OMI_SCOMINIT;
                    break;
                case MEM_ODY_SPPE_DRAMINIT:
                    o_mssHwpNum = mss::ipl_substep::DRAMINIT;
                    break;
                case MEM_ODY_DRAMINIT_MC:
                    o_mssHwpNum = mss::ipl_substep::DRAMINIT_MC;
                    break;
                case  MEM_ODY_DDRPHYINIT:
                case MEM_ODY_DDRPHYINIT_ATE:
                case MEM_ODY_LOAD_IMEM:
                case MEM_ODY_LOAD_DMEM:
                case MEM_ODY_ATE_FW:
                case MEM_ODY_LOAD_PIE:
                case MEM_ODY_ENABLE_ECC:
                case MEM_ODY_THERMAL_INIT:
                    break;
            }
        }
        // else its SBE_FIFO_EXEC_HWP_CLASS_MISC. Just return NO_FIR_STEP
        SBE_TRACF( "mapSbeHwpNum: "
                    "o_mssHwpNum=0x%X, hwpClass=0x%X, hwpNumber=0x%X",
                    o_mssHwpNum, i_sbeHwpClass, i_sbeHwpNum );
        return o_mssHwpNum;
    };



    /**
    * @brief Get all the mem ports associated with the specified target from
    *        the errorlog callouts
    *
    * @param[in] i_target The chip that was used to perform the chipop
    *
    * @param[in] i_errlList  errlHndl_t Error log handle returned by the chipop
    * @return TargetHandleList of mem ports
    *
    */
    TARGETING::TargetHandleList
    queryMemPortsFromCallouts(TARGETING::Target * const i_target,
                              std::vector<errlHndl_t> i_errlList)
    {
        TARGETING::TargetHandleList l_memPortsOfInterest;
        TARGETING::TargetHandleList l_memPorts;
        TARGETING::TargetHandleList l_ocmbList;
        TARGETING::TargetHandleList l_dimms;
        uint8_t l_found = 0;

        SBE_TRACF( "queryMemPortsFromCallouts: input target:0x%x", get_huid(i_target));

        // We have a list of error logs that don't match platform type errors.
        // These are most likely associated with the HWP errors. We need to see
        // if these have the info regarding the failing mem ports. Sometimes the
        // error logs may be for the target OCMB chip or for the dimms. We need
        // to check all these types, ensure it matches the ocmb chip we operated
        // upon and collect the associated mem ports to return to the caller.
        // Care also needs to be taken to check for any duplicates.
        for (auto i_errl : i_errlList)
        {
            // First get all the mem ports in the callout
            l_memPorts.clear();
            l_found = i_errl->queryHwCalloutsOfType(TYPE_MEM_PORT, l_memPorts);
            for (const auto & l_p : l_memPorts)
            {
                SBE_TRACF( "queryMemPortsFromCallouts: port=0x%x", get_huid(l_p));
                getParentAffinityTargets(l_ocmbList, l_p, CLASS_CHIP, TYPE_OCMB_CHIP);
                if ((l_ocmbList.size() == 1) && (l_ocmbList[0] == i_target))
                {
                    // save & report back this mem port
                    l_memPortsOfInterest.push_back(l_p);
                    SBE_TRACF( "Found MEMPORT. Saved memport:0x%x", get_huid(l_p));
                }
                l_ocmbList.clear();
            }

            // Now check for OCMB chips in the callout
            l_ocmbList.clear();
            l_found = i_errl->queryHwCalloutsOfType(TYPE_OCMB_CHIP, l_ocmbList);
            if (l_found)
            {
                for (const auto & l_c : l_ocmbList)
                {
                    SBE_TRACF( "queryMemPortsFromCallouts: ocmb=0x%x", get_huid(l_c));
                    if (l_c == i_target)
                    {
                        // Matched the OCMB chip target, get its children mem ports
                        l_memPorts.clear();

                        getChildAffinityTargets(l_memPorts, l_c, CLASS_UNIT, TYPE_MEM_PORT);
                        for (const auto & l_p : l_memPorts)
                        {
                            // save & report back this mem port if not already in the list
                            if (std::find(l_memPortsOfInterest.begin(),
                                l_memPortsOfInterest.end(), l_p) == l_memPortsOfInterest.end())
                            {
                               l_memPortsOfInterest.push_back(l_p);
                               SBE_TRACF( "Found OCMBs. Saved memport:0x%x", get_huid(l_p));
                            }
                            else
                            {
                               SBE_TRACD( "Found OCMBs. Already saved memport:0x%x", get_huid(l_p));
                            }
                        }
                        break; // we matched our target chip and done
                    }
                }
            }

            // Now check for Dimms in the callout
            l_dimms.clear();
            l_found = i_errl->queryHwCalloutsOfType(TYPE_DIMM, l_dimms);
            if (l_found)
            {
               for (const auto & l_d : l_dimms)
               {
                   SBE_TRACF( "queryMemPortsFromCallouts: dimm=0x%x", get_huid(l_d));
                   // Get the parents of this dimm
                   l_memPorts.clear();

                   getParentAffinityTargets(l_memPorts, l_d, CLASS_UNIT, TYPE_MEM_PORT);
                   for (const auto & l_p : l_memPorts)
                   {
                      // Check if the mem port belongs to the specified ocmb target
                      SBE_TRACF( "queryMemPortsFromCallouts: port=0x%x", get_huid(l_p));
                      l_ocmbList.clear();

                      getParentAffinityTargets(l_ocmbList, l_p, CLASS_CHIP, TYPE_OCMB_CHIP);
                      if ((l_ocmbList.size() == 1) && (l_ocmbList[0] == i_target))
                      {
                         // save & report back this mem port if not already in the list
                         if (std::find(l_memPortsOfInterest.begin(),
                                       l_memPortsOfInterest.end(), l_p) == l_memPortsOfInterest.end())
                         {
                              l_memPortsOfInterest.push_back(l_p);
                              SBE_TRACF( "Found Dimms. Saved memport:0x%x", get_huid(l_p));
                         }
                         else
                         {
                             SBE_TRACD( "Found Dimms. Already saved memport:0x%x", get_huid(l_p));
                         }
                      }
                   }
                }
             }
        }

        return l_memPortsOfInterest;
    }

    /**
    * @brief Send Istep command to the SBE.
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendIstepRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_ISTEP);
            if(errl)
            {
                break;
            }

            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendIstepRequest");

        }while(0);

        SBE_TRACD(EXIT_MRK "sendIstepRequest");
        return errl;
    };


    /**
     * @brief Send the IO or MEMORY HWP request to the SBE.  This function
     *        is called by one of two wrapper functions which perform initial
     *        checking of the parameters and then call this function to send
     *        the HWP request.
     *
     * @param[in]  i_chipTarget The Odyssey chip to perform the chipop on
     * @param[in]  i_hwpClass   The HWP class, either IO or MEM
     * @param[in]  i_hwpNumber  The specific HWP number to execute
     * @param[i/o] io_failHWP   This flag indicates that the HWP call should
     *                          be treated as a failure, despite the lack of
     *                          an error log. This should only be set to true
     *                          if there is an active attention that will be
     *                          caught at the end of the istep or some other
     *                          means of causing the istep to fail.
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  uint8_t i_hwpClass,
                                  uint8_t i_hwpNumber,
                                  bool    &io_failHWP)
    {
        errlHndl_t errl = nullptr;
        io_failHWP = false;

        do
        {
            // Input target / HWP class / HWP number have been
            // verified by the preceding wrapper functions

            // set up FIFO request message
            SbeFifo::fifoExecuteHardwareProcedureRequest l_fifoRequest;
            SbeFifo::fifoStandardResponse l_fifoResponse;
            l_fifoRequest.hwpClass      = i_hwpClass;
            l_fifoRequest.hwpNumber     = i_hwpNumber;

            SBE_TRACF( "sendExecHWPRequest: "
                       "target=0x%.8X, hwpClass=0x%X, hwpNumber=0x%X",
                       TARGETING::get_huid(i_chipTarget),
                       l_fifoRequest.hwpClass,
                       l_fifoRequest.hwpNumber );

            errl = SbeFifo::getTheInstance().performFifoChipOp(
                                i_chipTarget,
                                reinterpret_cast<uint32_t*>(&l_fifoRequest),
                                reinterpret_cast<uint32_t*>(&l_fifoResponse),
                                sizeof(SbeFifo::fifoStandardResponse));

        }while(0);

        if (errl)
        {
            mss::ipl_substep l_hwpNumber = mapSbeHwpNum(i_hwpClass, i_hwpNumber);
            if (l_hwpNumber != mss::ipl_substep::NO_FIR_STEP)
            {
                const auto l_plid = errl->plid();

                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapiOcmb(i_chipTarget);
                std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>> l_fapiMemPorts;
                SBE_TRACF( "sendExecHWPRequest: reasonCode=0x%x", errl->reasonCode());

                // There could be multiple errors logged by the HWP failure.
                // We need to look in all the error logs to see if there is at least
                // one error log that indicates it's NOT a platform error. If we find
                // such a log, it's likely due to the HWP error. In that case, need
                // to check if that is because of some FIR bits set.

                std::vector<errlHndl_t> errlList;

                // All platform errors (i.e. scom or i2c fail) need to be handled normally.
                // All the HWP related errors need to be further analyzed to see if they
                // have fir bits set. The error logs will include both types of errors.
                // Given the current SBE error handling design, unless we actually check
                // for every possible explicit RC, we cannot really differentiate platform
                // errors Vs HWP errors. Current check is to look for all error logs that
                // have SBEIO_ERROR_TYPE_FFDC_PACKAGE type to indicate its HWP returned
                // error. The ones that don't have the mentioned type are likely timeout,
                // hard chipop failure or HB register access failure, for which we do not
                // need to check if fir bits are set!
                errl->getAllErrlOfType(SBEIO_ERROR_TYPE_FFDC_PACKAGE, errlList);
                if (errlList.size())
                {
                    // If there is no platform error, check if FIR bits are set.
                    // First get all the associated "failing" memports from the callout.
                    // If the callouts are associated with the OCMB chip or dimms,
                    // we need to get all the associated mem ports to pass to the
                    // ody_blame_firs() HWP.
                    TARGETING::TargetHandleList l_memPorts =
                                          queryMemPortsFromCallouts(i_chipTarget, errlList);
                    for (const auto & l_p : l_memPorts)
                    {
                         fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_fapiPort(l_p);
                         l_fapiMemPorts.insert(l_fapiMemPorts.begin(), l_fapiPort);
                         SBE_TRACF( "sendExecHWPRequest: port=0x%x l_hwpNumber=0x%x",
                                     get_huid(l_p), l_hwpNumber );
                    }

                    bool l_firActive = 0;
                    errlHndl_t l_odyErrl = nullptr;
                    FAPI_INVOKE_HWP(l_odyErrl, ody_blame_firs, l_fapiOcmb, l_fapiMemPorts,
                                                               l_hwpNumber, l_firActive );
                    if ((l_odyErrl == nullptr) && l_firActive)
                    {
                        // Change the hwp_log to informational and commit
                        // This will cause deconfig/gard to be ignored!
                        errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        ERRORLOG::errlCommit(errl, ISTEP_COMP_ID);

                        // Set the ATTR_PRD_HWP_PLID to trigger PRD
                        // Check for non-zero value in PLID attribute.
                        i_chipTarget->setAttr<TARGETING::ATTR_PRD_HWP_PLID>(l_plid);
                        SBE_TRACF( "sendExecHWPRequest: ody_blame_firs FIR bits set!! "
                                   "target=0x%.8X, hwpClass=0x%X, hwpNumber=0x%X",
                                   TARGETING::get_huid(i_chipTarget),
                                   SBE_FIFO_EXEC_HWP_CLASS_IO, i_hwpNumber );

                        // We committed the error so that PRD can interpret the fir bits.
                        // But we still want this HWP to fail. So indicate that via the
                        // flag.
                        io_failHWP = true;
                        SBE_TRACF( "sendExecHWPRequest: io_failHWP=%d", io_failHWP );
                    }
                    else
                    {
                        SBE_TRACF( "sendExecHWPRequest: fir bits set=%d", l_firActive);
                        // Set the ATTR that says FIR bits NOT set
                        // Please Note: If any operation has a normal (non-FIR) failure, that
                        // overrides the extra PRD checks at the end of the istep. This is necessary
                        // because we don't want PRD to analyze failed parts that are in an unknown state.
                        // If there are both FIR and non-FIR errors present across different chips, the
                        // FIR errors will be ignored and found again in the reconfig loop.
                        UTIL::assertGetToplevelTarget()->setAttr<TARGETING::ATTR_CHECK_ATTN_AFTER_ISTEP_FAIL>
                                                        (TARGETING::CHECK_ATTN_AFTER_ISTEP_FAIL_NO);
                        SBE_TRACF( "sendExecHWPRequest: ody_blame_firs FIR NOT SET!! "
                                   "target=0x%.8X, hwpClass=0x%X, hwpNumber=0x%X",
                                   TARGETING::get_huid(i_chipTarget),
                                   SBE_FIFO_EXEC_HWP_CLASS_IO, i_hwpNumber );

                        if (l_odyErrl != nullptr)
                        {
                            errl->aggregate(l_odyErrl);
                        }
                    }
                }
                else
                {
                     SBE_TRACF( "sendExecHWPRequest: ody_blame_firs NOT INVOKED!"
                                TRACE_ERR_FMT, TRACE_ERR_ARGS(errl));
                }
            }
        }


        SBE_TRACD(EXIT_MRK "sendExecHWPRequest");
        return errl;
    } // end sendExecHWPRequest

    // Wrapper for an Odyssey MISC HWP
    // See sbeioif.H for definition
    errlHndl_t sendExecHWPRequest(TARGETING::Target               *i_chipTarget,
                                  fifoExecuteHardwareProcedureMisc i_hwpNumber,
                                  bool  &io_failHWP)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Send the HWP request
            errl = sendExecHWPRequest(i_chipTarget,
                                      SBE_FIFO_EXEC_HWP_CLASS_MISC,
                                      i_hwpNumber,
                                      io_failHWP);
            if(errl)
            {
                break;
            }

        } while(0);

        return errl;
    }


    // Wrapper for an Odyssey IO HWP
    // See sbeioif.H for definition
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureIo i_hwpNumber,
                                  bool  &io_failHWP)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Make sure the target is Odyssey
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                     SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Send the HWP request
            errl = sendExecHWPRequest(i_chipTarget,
                                      SBE_FIFO_EXEC_HWP_CLASS_IO,
                                      i_hwpNumber,
                                      io_failHWP);
            if(errl)
            {
                break;
            }

        } while(0);

        return errl;
    } // end sendExecHWPRequest for IO class


    // Wrapper for an Odyssey MEMORY HWP
    // See sbeioif.H for definition
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureMemory i_hwpNumber,
                                  bool  &io_failHWP)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget,
                                        SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                        SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Make sure the target is Odyssey
            errl = sbeioOdysseyCheck(i_chipTarget,
                                     SbeFifo::SBE_FIFO_CLASS_IPL_CONTROL,
                                     SbeFifo::SBE_FIFO_CMD_EXECUTE_HWP);
            if(errl)
            {
                break;
            }

            // Send the HWP request
            errl = sendExecHWPRequest(i_chipTarget,
                                      SBE_FIFO_EXEC_HWP_CLASS_MEMORY,
                                      i_hwpNumber,
                                      io_failHWP);
            if(errl)
            {
                break;
            }

        } while(0);

        return errl;
    } // end sendExecHWPRequest for MEMORY class

} //end namespace SBEIO

