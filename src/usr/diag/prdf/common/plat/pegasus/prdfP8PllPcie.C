/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8PllPcie.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 * @file prdfP8PLL.C
 * @brief chip Plug-in code for proc pll pcie support
 */

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfBitString.H>
#include <iipscr.h>
#include <prdfPlatServices.H>
#include <prdfErrlUtil.H>
#include <iipSystem.h>
#include <prdfGlobal_common.H>
#include <prdfP8DataBundle.H>
#include <UtilHash.H>
#include <prdfP8PllPcie.H>
#include <prdfFsiCapUtil.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PLL;
using namespace PlatServices;

namespace Proc
{

int32_t isPllUnlockCausedByPciOscFo( ExtensibleChip * i_chip,
                                     uint32_t i_activeOscPos,
                                     bool & o_pciOscSwitchCausedPllError )
{
    #define PRDF_FUNC "Proc::isPllUnlockCausedByPciOscFo "
    int32_t o_rc = SUCCESS;
    o_pciOscSwitchCausedPllError = false;

    #ifndef __HOSTBOOT_MODULE

    do
    {
        uint32_t u32Data = 0;
        o_rc = getCfam( i_chip, 0x00002819, u32Data );

        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "PCI Status register Read failed 0x%08x",
                      i_chip->GetId() );
            break;
        }

        uint32_t pciOscMask = ( 0 == i_activeOscPos ) ? 0x00000C00 : 0x00000300;

        if( !(u32Data & pciOscMask) )
        {
            // PLL unlock error has occurred due to problem in secondary or
            // backup pci osc.
            o_pciOscSwitchCausedPllError = true;
        }
    }while(0);

    #endif
    #undef PRDF_FUNC

    return o_rc;
}

/**
  * @brief Query the PLL chip for a PCI PLL error
  * @param i_chip P8 Pci chip
  * @param o_result set to true in the presence of PLL error
  * @returns Failure or Success of query.
  */
int32_t QueryPciPll( ExtensibleChip * i_chip,
                        bool & o_result)
{
    #define PRDF_FUNC "[Proc::QueryPciPll] "

    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * pciErrReg =
                i_chip->getRegister("PCI_ERROR_REG");
    SCAN_COMM_REGISTER_CLASS * pciConfigReg =
                i_chip->getRegister("PCI_CONFIG_REG");

    do
    {
        rc = pciErrReg->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "PCI_ERROR_REG read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        rc = pciConfigReg->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "PCI_CONFIG_REG read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        if(pciErrReg->IsBitSet(PLL_ERROR_BIT) &&
           !pciConfigReg->IsBitSet(PLL_ERROR_MASK))
        {
            o_result = true;
        }

    } while(0);

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC "failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, QueryPciPll );

/**
  * @brief Query the PLL chip for a PLL error on P8
  * @param  i_chip P8 Pci chip
  * @param o_result set to true in the presence of PLL error
  * @returns Failure or Success of query.
  * @note
  */
int32_t QueryPllIo( ExtensibleChip * i_chip,
                        bool & o_result)
{
    #define PRDF_FUNC "[Proc::QueryPllIo] "

    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR =
                i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIRmask =
                i_chip->getRegister("TP_LFIR_MASK");

    do
    {
        rc = TP_LFIR->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        rc = TP_LFIRmask->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_MASK read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        if (( TP_LFIRmask->IsBitSet(PLL_DETECT_P8) ) ||
            ( ! TP_LFIR->IsBitSet(PLL_DETECT_P8) ))
        {
            // if global pll bit is not set, break out
            break;
        }

        rc = QueryPciPll( i_chip, o_result );
        if ((rc != SUCCESS) || (true == o_result)) break;

    } while(0);

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC "failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, QueryPllIo );


/**
  * @brief  Clear the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  */
int32_t ClearPllIo( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::ClearPllIo] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        // Clear pci osc error reg bit
        int32_t tmpRC = SUCCESS;
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
                i_chip->getRegister("PCI_ERROR_REG");

        tmpRC = pciErrReg->Read();
        if (tmpRC != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "PCI_ERROR_REG read failed"
                     "for chip: 0x%08x", i_chip->GetId());
            rc |= tmpRC;
        }

        if( pciErrReg->IsBitSet( PLL_ERROR_BIT ) )
        {
            pciErrReg->clearAllBits();
            pciErrReg->SetBit(PLL_ERROR_BIT);
            tmpRC = pciErrReg->Write();

            if ( SUCCESS != tmpRC )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on PCI Error register: "
                          "proc=0x%08x", i_chip->GetId() );
                rc |= tmpRC;
            }
        }

        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIRand =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIRand->setAllBits();
        TP_LFIRand->ClearBit(PLL_DETECT_P8);
        tmpRC = TP_LFIRand->Write();
        if (tmpRC != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "TP_LFIR_AND write failed"
                     "for chip: 0x%08x", i_chip->GetId());
            rc |= tmpRC;
        }

        SCAN_COMM_REGISTER_CLASS * oscCerrReg =
                i_chip->getRegister("OSCERR");

        tmpRC = oscCerrReg->Read();
        if (tmpRC != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "OSCERR read failed"
                     "for 0x%08x", i_chip->GetId());
            rc |= tmpRC;
        }
        oscCerrReg->ClearBit(4);
        oscCerrReg->ClearBit(5);
        tmpRC = oscCerrReg->Write();
        if (tmpRC != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "oscCerrReg write failed"
                     "for chip: 0x%08x", i_chip->GetId());
            rc |= tmpRC;
        }

    }

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC "failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, ClearPllIo );

/**
  * @brief Mask the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @param  i_oscPos active osc position
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPllIo( ExtensibleChip * i_chip,
                 STEP_CODE_DATA_STRUCT & i_sc,
                 uint32_t i_oscPos )
{
    #define PRDF_FUNC "[Proc::MaskPllIo] "

    int32_t rc = SUCCESS;

    do
    {
        if (CHECK_STOP == i_sc.service_data->GetAttentionType())
        {
            break;
        }

        if ( i_oscPos >= MAX_PCIE_OSC_PER_NODE )
        {
            PRDF_ERR(PRDF_FUNC "invalid oscPos: %d for chip: "
                     "0x%08x", i_oscPos, i_chip->GetId());
            rc = FAIL;
            break;
        }

        uint32_t oscPos = getIoOscPos( i_chip, i_sc );

        if ( oscPos != i_oscPos )
        {
            PRDF_DTRAC(PRDF_FUNC "skip masking for chip: 0x%08x, "
                      "oscPos: %d, i_oscPos: %d",
                      i_chip->GetId(), oscPos, i_oscPos);
            break;
        }

        // fence off pci osc error reg bit
        SCAN_COMM_REGISTER_CLASS * pciConfigReg =
            i_chip->getRegister("PCI_CONFIG_REG");

        rc = pciConfigReg->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "PCI_CONFIG_REG read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        if(!pciConfigReg->IsBitSet(PLL_ERROR_MASK))
        {
            pciConfigReg->SetBit(PLL_ERROR_MASK);
            rc = pciConfigReg->Write();
            if (rc != SUCCESS)
            {
                PRDF_ERR(PRDF_FUNC "PCI_CONFIG_REG write failed"
                         "for chip: 0x%08x",
                         i_chip->GetId());
            }
        }

        // Since TP_LFIR bit is the collection of all of the
        // pll error reg bits, we can't mask it or we will not
        // see any PLL errors reported from the error regs

    } while(0);

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, MaskPllIo );

/**
 * @brief   capture additional PLL FFDC
 * @param   i_chip   P8 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t capturePllFfdcIo( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    // Add FSI Osc reg
    captureFsiStatusReg( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, capturePllFfdcIo );

/**
 * @brief   calling out active pcie osc connected to this proc
 * @param   i_chip   P8 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t CalloutPllIo( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Proc::CalloutPllIo] "

    int32_t rc = SUCCESS;

    do
    {
        uint32_t oscPos = getIoOscPos( i_chip, io_sc );
        bool pllUnlockDuetoOscSwitch;
        rc = isPllUnlockCausedByPciOscFo( i_chip, oscPos,
                                          pllUnlockDuetoOscSwitch );

        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "PCI Osc switch analysis failed" );
            break;
        }

        if( pllUnlockDuetoOscSwitch )
        {
            // PLL unlock has occurred due to PCI OSC switchover. We can ignore
            // this error. It shall be handled seprately as PC OSC switchover
            // event.
            break;
        }

        // oscPos will be checked inside getClockId and in case
        // a connected osc is not found, will use the proc target
        // this is the hostboot path since it's used the proc
        // target and clock type.
        TargetHandle_t connectedOsc = getClockId( i_chip->GetChipHandle(),
                                                  TYPE_OSCPCICLK,
                                                  oscPos );

        if ( NULL == connectedOsc )
        {
            PRDF_ERR(PRDF_FUNC "Failed to get connected PCIe OSC for "
                 "chip 0x%08x, oscPos: %d",i_chip->GetId(), oscPos );
            connectedOsc = i_chip->GetChipHandle();
        }

        PRDF_DTRAC(PRDF_FUNC "PCIe OSC: 0x%08x connected to "
                 "proc: 0x%08x", getHuid(connectedOsc), i_chip->GetId());

        // callout the clock source
        // HB does not have the osc target modeled
        // so we need to use the proc target with
        // osc clock type to call out
        #ifndef __HOSTBOOT_MODULE
        io_sc.service_data->SetCallout(connectedOsc);
        #else
        io_sc.service_data->SetCallout(
                            PRDcallout(connectedOsc,
                            PRDcalloutData::TYPE_PCICLK));
        #endif

    } while(0);

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, CalloutPllIo );

} // end namespace Proc

namespace PLL
{

uint32_t getIoOscPos( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc)
{
    #define PRDF_FUNC "[PLL::getIoOscPos] "
    uint32_t o_oscPos = MAX_PCIE_OSC_PER_NODE;

    do
    {
        int32_t rc = SUCCESS;

        SCAN_COMM_REGISTER_CLASS * pcieOscSwitchReg =
                i_chip->getRegister("PCIE_OSC_SWITCH");

        rc = pcieOscSwitchReg->Read();
        if (rc != SUCCESS)
        {
            PRDF_ERR(PRDF_FUNC "PCIE_OSC_SWITCH read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        // [ 16 ] == 1    ( OSC 0 is active )
        // [ 16 ] == 0    ( OSC 1 is active )
        if(pcieOscSwitchReg->IsBitSet(16))
        {
            o_oscPos = 0;
        }
        else
        {
            o_oscPos = 1;
        }

    } while(0);

    return o_oscPos;

    #undef PRDF_FUNC
}

}// namespace PLL

} // end namespace PRDF
