/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9Mca.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfP9McbistDataBundle.H>
#include <prdfPlatServices.H>
#ifdef __HOSTBOOT_RUNTIME
  #include <prdfMemTps.H>
#endif

#ifdef CONFIG_NVDIMM
    #include <nvdimm.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace nimbus_mca
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An MCA chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[nimbus_mca::PostAnalysis] "

    #ifdef __HOSTBOOT_RUNTIME

    // If the IUE threshold in our data bundle has been reached, we trigger
    // a port fail. Once we trigger the port fail, the system may crash
    // right away. Since PRD is running in the hypervisor, it is possible we
    // may not get the error log. To better our chances, we trigger the port
    // fail here after the error log has been committed.
    if ( MemEcc::queryIueTh<TYPE_MCA>(i_chip, io_sc) )
    {
        if ( SUCCESS != MemEcc::triggerPortFail<TYPE_MCA>(i_chip) )
        {
            PRDF_ERR( PRDF_FUNC "triggerPortFail(0x%08x) failed",
            i_chip->getHuid() );
        }
    }

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( nimbus_mca, PostAnalysis );


//##############################################################################
//
//                               MCACALFIR
//
//##############################################################################

/**
 * @brief  MCACALFIR[4] - RCD Parity Error.
 * @param  i_mcaChip A P9 MCA chip.
 * @param  io_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t RcdParityError( ExtensibleChip * i_mcaChip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[nimbus_mca::RcdParityError] "

    // The callouts have already been made in the rule code. All other actions
    // documented below.

    // Nothing more to do if this is a checkstop attention.
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
        return SUCCESS;

    uint32_t l_rc = SUCCESS;

    // If MCBISTFIR[3] is found to be on at the same time, mask it so it won't
    // be logged as a separate event.
    ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );

    SCAN_COMM_REGISTER_CLASS * mcbistfir = mcbChip->getRegister( "MCBISTFIR" );
    l_rc = mcbistfir->Read();
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR");
    }
    else if ( mcbistfir->IsBitSet(3) )
    {
        SCAN_COMM_REGISTER_CLASS * mcbistfir_mask_or =
            mcbChip->getRegister( "MCBISTFIR_MASK_OR" );
        mcbistfir_mask_or->SetBit(3);
        l_rc = mcbistfir_mask_or->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCBIST_MASK_OR: "
                      "mcbChip=0x%08x", mcbChip->getHuid() );
        }
    }

    #ifdef __HOSTBOOT_RUNTIME // TPS only supported at runtime.

    // Recovery is always enabled during runtime. If the threshold is reached,
    // make the error log predictive and start TPS on all slave ranks behind
    // the MCA.
    if ( getMcaDataBundle(i_mcaChip)->iv_rcdParityTh.inc(io_sc) )
    {
        io_sc.service_data->setServiceCall();

        std::vector<MemRank> list;
        getSlaveRanks<TYPE_MCA>( i_mcaChip->getTrgt(), list );
        PRDF_ASSERT( !list.empty() ); // target configured with no ranks

        for ( auto & r : list )
        {
            TdEntry * entry = new TpsEvent<TYPE_MCA>( i_mcaChip, r );
            MemDbUtils::pushToQueue<TYPE_MCA>( i_mcaChip, entry );
            uint32_t rc = MemDbUtils::handleTdEvent<TYPE_MCA>(i_mcaChip, io_sc);
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "handleTdEvent() failed on 0x%08x",
                          i_mcaChip->getHuid() );

                continue; // Try the other ranks.
            }
        }
    }

    #else // IPL

    SCAN_COMM_REGISTER_CLASS * farb0 = i_mcaChip->getRegister("FARB0");
    if ( SUCCESS != farb0->Read() )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_mcaChip=0x%08x",
                  i_mcaChip->getHuid() );

        // Ensure the reg is zero so that we will use the recovery threshold and
        // guarantee we don't try to do a reconfig.
        farb0->clearAllBits();
    }

    if ( farb0->IsBitSet(54) )
    {
        // Recovery is disabled. Issue a reconfig loop. Make the error log
        // predictive if threshold is reached.
        if ( rcdParityErrorReconfigLoop(i_mcaChip->getTrgt()) )
            io_sc.service_data->setServiceCall();

        if ( isInMdiaMode() )
        {
            SCAN_COMM_REGISTER_CLASS * mask = nullptr;

            // Stop any further commands on this MCBIST to avoid subsequent RCD
            // errors or potential AUEs.
            l_rc = mdiaSendEventMsg( mcbChip->getTrgt(), MDIA::STOP_TESTING );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
            }

            // Mask the maintenance AUE/IAUE attentions on this MCA because they
            // are potential side-effects of the RCD parity errors.
            mask = i_mcaChip->getRegister( "MCAECCFIR_MASK_OR" );
            mask->SetBit(33); // maintenance AUE
            mask->SetBit(36); // maintenance IAUE
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_OR: "
                          "i_mcaChip=0x%08x", i_mcaChip->getHuid() );
            }

            // Mask the maintenance command complete bits to avoid false
            // attentions.
            mask = mcbChip->getRegister( "MCBISTFIR_MASK_OR" );
            mask->SetBit(10); // Command complete
            mask->SetBit(12); // WAT workaround
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_MASK_OR: "
                          "mcbChip=0x%08x", mcbChip->getHuid() );
            }
        }
    }
    else
    {
        // Make the error log predictive if the recovery threshold is reached.
        // Don't bother with TPS on all ranks because it is too complicated to
        // handle during Memory Diagnostics and we don't have time to complete
        // the procedures at any other point during the IPL. The DIMMs will be
        // deconfigured during the IPL anyways. So not really much benefit
        // except for extra FFDC.
        if ( getMcaDataBundle(i_mcaChip)->iv_rcdParityTh.inc(io_sc) )
            io_sc.service_data->setServiceCall();
    }

    #endif

    if ( io_sc.service_data->queryServiceCall() )
    {
        // Mask both RCD parity error bits to prevent any flooding.
        SCAN_COMM_REGISTER_CLASS * mask
                                = i_mcaChip->getRegister( "MCACALFIR_MASK_OR" );
        mask->SetBit( 4);
        mask->SetBit(14);
        if ( SUCCESS != mask->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCACALFIR_MASK_OR: "
                      "i_mcaChip=0x%08x", i_mcaChip->getHuid() );
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( nimbus_mca, RcdParityError );

//------------------------------------------------------------------------------

/**
 * @brief  MCACALFIR[13] - Persistent RCD error, port failed.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t MemPortFailure( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[nimbus_mca::MemPortFailure] "

    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
    {
        // The port is dead. Mask off the entire port.
        uint32_t l_rc = MemEcc::maskMemPort<TYPE_MCA>( i_chip );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemEcc::maskMemPort<TYPE_MCA>(0x%08x) failed",
                      i_chip->getHuid() );
        }
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( nimbus_mca, MemPortFailure );

//##############################################################################
//
//                               NVDIMM
//
//##############################################################################

#ifdef CONFIG_NVDIMM
#ifdef __HOSTBOOT_RUNTIME

/**
 * @brief  Gets a map list of which bits are set from a uint8_t bit list (7:0)
 * @param  i_data uint8_t bit list (7:0)
 * @return map<uint8_t, bool> with which bits were set in the bit list.
 */
std::map<uint8_t,bool> __nvdimmGetActiveBits( uint8_t i_data )
{
    // NOTE: Bit position in i_data that we get from the NVDIMM status register
    //       will be in descending order, ie ordered 7 to 0 (left to right).
    std::map<uint8_t,bool> bitList;
    for ( uint8_t n = 0; n < 8; n++ )
    {
        if ( i_data & (0x01 << n) ) bitList[n] = true;
    }
    return bitList;
}

/**
 * @brief  Adds a callout of the NVDIMM backup power module
 * @param  i_dimm     The target dimm.
 * @param  i_priority The callout priority.
 * @return FAIL if unable to get the global error log, else SUCCESS
 */
uint32_t __addBpmCallout( TargetHandle_t i_dimm,
                          HWAS::callOutPriority i_priority )
{
    #define PRDF_FUNC "[__addBpmCallout] "

    uint32_t o_rc = SUCCESS;

    do
    {
        errlHndl_t mainErrl = nullptr;
        mainErrl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( nullptr == mainErrl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get the global error log." );
            o_rc = FAIL;
            break;
        }

        // addPartCallout will default to GARD_NULL, NO_DECONFIG
        mainErrl->addPartCallout( i_dimm, HWAS::BPM_PART_TYPE,
                                  i_priority );

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief  Adds a callout of the cable connecting an NVDIMM to its
 *         backup power module (BPM)
 * @param  i_dimm     The target dimm.
 * @param  i_priority The callout priority.
 * @return FAIL if unable to get the global error log, else SUCCESS
 */
uint32_t __addNvdimmCableCallout( TargetHandle_t i_dimm,
                                  HWAS::callOutPriority i_priority )
{
    #define PRDF_FUNC "[__addNvdimmCableCallout] "

    uint32_t o_rc = SUCCESS;

    do
    {
        errlHndl_t mainErrl = nullptr;
        mainErrl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( nullptr == mainErrl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get the global error log." );
            o_rc = FAIL;
            break;
        }

        // addPartCallout will default to GARD_NULL, NO_DECONFIG
        mainErrl->addPartCallout( i_dimm, HWAS::BPM_CABLE_PART_TYPE,
                                  i_priority );

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief  If a previous error has been found, add a signature to the
 *         multi-signature list, else set the primary signature.
 * @param  io_sc      The step code data struct.
 * @param  i_trgt     The target.
 * @param  i_errFound Whether an error has already been found or not.
 * @param  i_sig      The signature to be set.
 */
void __addSignature( STEP_CODE_DATA_STRUCT & io_sc, TargetHandle_t i_trgt,
                     bool i_errFound, uint32_t i_sig )
{
    if ( i_errFound )
    {
        io_sc.service_data->AddSignatureList( i_trgt, i_sig );
    }
    else
    {
        io_sc.service_data->setSignature( getHuid(i_trgt), i_sig );
    }
}

/**
 * @brief  Analyze NVDIMM Health Status0 Register for errors
 * @param  io_sc       The step code data struct.
 * @param  i_dimm      The target dimm.
 * @param  io_errFound Whether an error has already been found or not.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __analyzeHealthStatus0Reg(STEP_CODE_DATA_STRUCT & io_sc,
                                   TargetHandle_t i_dimm, bool & io_errFound)
{
    #define PRDF_FUNC "[__analyzeHealthStatus0Reg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    // Get MCA, for signatures
    TargetHandle_t mca = getConnectedParent( i_dimm, TYPE_MCA );

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Health Status0 Register (0xA1) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::MODULE_HEALTH_STATUS0) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Health Status0 Register. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: Voltage Regulator Fail
        if ( bitList.count(0) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_VoltRegFail );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 1: VDD Lost
        if ( bitList.count(1) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_VddLost );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 2: VPP Lost
        if ( bitList.count(2) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_VppLost );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 3: VTT Lost
        if ( bitList.count(3) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_VttLost );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 4: DRAM not Self Refresh
        if ( bitList.count(4) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_NotSelfRefr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 5: Controller HW Error
        if ( bitList.count(5) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_CtrlHwErr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 6: NVM Controller Error
        if ( bitList.count(6) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_NvmCtrlErr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 7: NVM Lifetime Error
        if ( bitList.count(7) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_NvmLifeErr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Analyze NVDIMM Health Status1 Register for errors
 * @param  io_sc       The step code data struct.
 * @param  i_dimm      The target dimm.
 * @param  io_errFound Whether an error has already been found or not.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __analyzeHealthStatus1Reg( STEP_CODE_DATA_STRUCT & io_sc,
                                    TargetHandle_t i_dimm, bool & io_errFound )
{
    #define PRDF_FUNC "[__analyzeHealthStatus1Reg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    // Get MCA, for signatures
    TargetHandle_t mca = getConnectedParent( i_dimm, TYPE_MCA );

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Health Status1 Register (0xA2) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::MODULE_HEALTH_STATUS1) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Health Status1 Register. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: Insufficient Energy
        if ( bitList.count(0) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_InsuffEnergy );

            // Callout BPM (backup power module) high, cable high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;
            o_rc = __addNvdimmCableCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 1: Invalid Firmware
        if ( bitList.count(1) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_InvFwErr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 2: Configuration Data Error
        if ( bitList.count(2) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_CnfgDataErr );
            // Callout NVDIMM on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            io_errFound = true;
        }
        // BIT 3: No Energy Source
        if ( bitList.count(3) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_NoEsPres );

            // Callout BPM (backup power module) high, cable high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;
            o_rc = __addNvdimmCableCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 4: Energy Policy Not Set
        if ( bitList.count(4) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_EsPolNotSet );

            // Callout FW (Level2 Support) High
            io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH, NO_GARD );

            // Callout NVDIMM low on 1st, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 5: Energy Source HW Error
        if ( bitList.count(5) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_EsHwFail );

            // Callout BPM (backup power module) high, cable high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;
            o_rc = __addNvdimmCableCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 6: Energy Source Health Assessment Error
        if ( bitList.count(6) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_EsHlthAssess);

            // Callout BPM (backup power module) high, cable high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;
            o_rc = __addNvdimmCableCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 7: Reserved

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Reads and merges the data from two ES_TEMP registers to get the
 *         correct temperature format.
 * @param  i_dimm       The target nvdimm.
 * @param  i_tempMsbReg The address of the register that contains the most
 *                      significant byte of the temperature data.
 * @param  i_tempLsbReg The address of the register that contains the least
 *                      significant byte of the temperature data.
 * @param  o_tempData   The 16 bit temperature data.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __readTemp( TargetHandle_t i_dimm, uint16_t i_tempMsbReg,
                     uint16_t i_tempLsbReg, uint16_t & o_tempData )
{
    #define PRDF_FUNC "[__readTemp] "

    /*
     * -NOTE: Example showing how to read the temperature format:
     * ES_TEMP1  = 0x03 (MSB: bits 15-8)
     * ES_TEMP0  = 0x48 (LSB: bits 7-0)
     *
     * 0x0348 = 0000 0011 0100 1000 = 52.5 C
     *
     * -NOTE: bit definition:
     * [15:13]Reserved
     * [12]Sign 0 = positive, 1 = negative; 0°C should be expressed as positive
     * [11]  128°C
     * [10]   64°C
     * [9]    32°C
     * [8]    16°C
     * [7]     8°C
     * [6]     4°C
     * [5]     2°C
     * [4]     1°C
     * [3]   0.5°C
     * [2]  0.25°C
     * [1] 0.125°C Optional for temp fields; not used for temp th fields
     * [0]0.0625°C Optional for temp fields; not used for temp th fields
     */
    uint32_t o_rc = SUCCESS;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;
        uint8_t msbData = 0;
        uint8_t lsbData = 0;

        // Read the two inputted temperature registers.
        errlHndl_t errl = deviceRead( i_dimm, &msbData, NVDIMM_SIZE,
                                      DEVICE_NVDIMM_ADDRESS(i_tempMsbReg) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read ES Temperature MSB Register. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        errl = deviceRead( i_dimm, &lsbData, NVDIMM_SIZE,
                           DEVICE_NVDIMM_ADDRESS(i_tempLsbReg) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read ES Temperature LSB Register. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        o_tempData = ((uint16_t)msbData << 8) | lsbData;

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief  Analyze NVDIMM Error Threshold Status Register for errors
 * @param  io_sc       The step code data struct.
 * @param  i_dimm      The target dimm.
 * @param  io_errFound Whether an error has already been found or not.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __analyzeErrorThrStatusReg( STEP_CODE_DATA_STRUCT & io_sc,
                                     TargetHandle_t i_dimm, bool & io_errFound )
{
    #define PRDF_FUNC "[__analyzeErrorThrStatusReg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    // Get MCA, for signatures
    TargetHandle_t mca = getConnectedParent( i_dimm, TYPE_MCA );

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Error Threshold Status Register (0xA5) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::ERROR_THRESHOLD_STATUS) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Error Threshold Status Reg. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: NVM Lifetime Error -- ignore
        // BIT 1: ES Lifetime Error
        if ( bitList.count(1) )
        {
            __addSignature( io_sc, mca, io_errFound, PRDFSIG_EsLifeErr );

            // Callout BPM (backup power module) high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 2: ES Temperature Error
        if ( bitList.count(2) )
        {
            // Read the ES_TEMP and ES_TEMP_ERROR_HIGH_THRESHOLD values
            uint16_t msbEsTempReg = NVDIMM::i2cReg::ES_TEMP1;
            uint16_t lsbEsTempReg = NVDIMM::i2cReg::ES_TEMP0;

            uint16_t esTemp = 0;
            o_rc = __readTemp( i_dimm, msbEsTempReg, lsbEsTempReg, esTemp );
            if ( SUCCESS != o_rc ) break;

            uint16_t msbThReg = NVDIMM::i2cReg::ES_TEMP_ERROR_HIGH_THRESHOLD1;
            uint16_t lsbThReg = NVDIMM::i2cReg::ES_TEMP_ERROR_HIGH_THRESHOLD0;

            uint16_t esTempHighTh = 0;
            o_rc = __readTemp( i_dimm, msbThReg, lsbThReg, esTempHighTh );
            if ( SUCCESS != o_rc ) break;

            // Check to see if the ES_TEMP is negative (bit 12)
            bool esTempNeg = false;
            if ( esTemp & 0x1000 ) esTempNeg = true;

            // If ES_TEMP is equal or above ES_TEMP_ERROR_HIGH_THRESHOLD
            // Just in case ES_TEMP has moved before we read it out, we'll add
            // a 2°C margin when comparing to the threshold.
            if ( (esTemp >= (esTempHighTh - 0x0020)) && !esTempNeg )
            {
                __addSignature( io_sc, mca, io_errFound,
                                PRDFSIG_EsTmpErrHigh );
            }
            // Else assume the warning is because of a low threshold.
            else
            {
                __addSignature( io_sc, mca, io_errFound,
                                PRDFSIG_EsTmpErrLow );
            }

            // Callout BPM (backup power module) high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            io_errFound = true;
        }
        // BIT 3:7: Reserved

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Adjusts the warning threshold so that future warnings are allowed
 *         to report.
 * @param  io_sc       The step code data struct.
 * @param  i_dimm      The target nvdimm.
 * @param  i_warnThReg The address of the relevant warning threshold register.
 * @param  i_errThReg  The address of the relevant error threshold register.
 * @param  o_firstWarn Flag if this is the first warning of this type.
 * @param  o_statusErr Flag to tell if we found an error from checking the
 *                     notification status register.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __adjustThreshold( STEP_CODE_DATA_STRUCT & io_sc,
                            TargetHandle_t i_dimm, uint16_t i_warnThReg,
                            uint16_t i_errThReg, bool & o_firstWarn,
                            bool & o_statusErr )
{
    #define PRDF_FUNC "[__adjustThreshold] "

    uint32_t o_rc = SUCCESS;
    uint16_t notifCmdReg    = NVDIMM::i2cReg::SET_EVENT_NOTIFICATION_CMD;
    uint16_t notifStatusReg = NVDIMM::i2cReg::SET_EVENT_NOTIFICATION_STATUS;
    o_firstWarn = false;
    o_statusErr = false;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the corresponding warning threshold
        uint8_t warnTh = 0;
        errlHndl_t errl = deviceRead( i_dimm, &warnTh, NVDIMM_SIZE,
                                      DEVICE_NVDIMM_ADDRESS(i_warnThReg) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Warning Threshold Reg. HUID: "
                      "0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        // Read the corresponding error threshold
        uint8_t errTh = 0;
        errl = deviceRead( i_dimm, &errTh, NVDIMM_SIZE,
                           DEVICE_NVDIMM_ADDRESS(i_errThReg) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Error Threshold Reg. HUID: "
                      "0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        // If the warning threshold is not set to the error threshold+1,
        // move the threshold.
        if ( warnTh != (errTh+1) )
        {
            o_firstWarn = true;

            // SET_EVENT_NOTIFICATION_CMD is a write only register that is
            // used to change the SET_EVENT_NOTIFICATION_STATUS register.
            // The only bits within it that are used are bits 0 and 1, as such
            // we can safely set the rest to 0. It is defined as:
            // [0]:   Persistency Notification
            // [1]:   Warning Threshold Notification
            // [2]:   Obsolete
            // [3]:   Firmware Activation Notification (Not Used)
            // [4:7]: Reserved

            // Clear SET_EVENT_NOTIFICATION_CMD bit 1 and keep bit 0 set
            uint8_t notifCmd = 0x01;
            errl = deviceWrite( i_dimm, &notifCmd, NVDIMM_SIZE,
                                DEVICE_NVDIMM_ADDRESS(notifCmdReg) );
            if ( errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to clear Set Event Notification "
                          "Cmd Reg. HUID: 0x%08x", getHuid(i_dimm) );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
                break;
            }

            // Check SET_EVENT_NOTIFICATION_STATUS to ensure everything is set
            // as we expect and we don't see any errors.
            uint8_t notifStat = 0;
            errl = deviceRead( i_dimm, &notifStat, NVDIMM_SIZE,
                               DEVICE_NVDIMM_ADDRESS(notifStatusReg) );
            if ( errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to read Set Event Notification "
                          "Status Reg. HUID: 0x%08x", getHuid(i_dimm) );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
                break;
            }
            std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( notifStat );

            // if Bit [1]: SET_EVENT_NOTIFICATION_ERROR = 1
            // or Bit [2]: PERSISTENCY_ENABLED = 0
            // or Bit [3]: WARNING_THRESHOLD_ENABLED = 1
            if ( bitList.count(1)  || !bitList.count(2) || bitList.count(3) )
            {
                o_statusErr = true;

                // Make the log predictive and mask the fir
                io_sc.service_data->SetThresholdMaskId(0);

                // Callout the NVDIMM, no gard
                io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );

                // Send message to PHYP that save/restore may work
                o_rc = PlatServices::nvdimmNotifyProtChange( i_dimm,
                    NVDIMM::NVDIMM_RISKY_HW_ERROR );
                if ( SUCCESS != o_rc ) break;

                break;
            }


            // Set the warning threshold to error threshold + 1
            warnTh = errTh+1;
            errl = deviceWrite( i_dimm, &warnTh, NVDIMM_SIZE,
                                DEVICE_NVDIMM_ADDRESS(i_warnThReg) );
            if ( errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to write Warning Threshold Reg. "
                          "HUID: 0x%08x", getHuid(i_dimm) );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
                break;
            }

            // Set SET_EVENT_NOTIFICATION_CMD bit 1 and keep bit 0 set
            notifCmd = 0x03;
            errl = deviceWrite( i_dimm, &notifCmd, NVDIMM_SIZE,
                                DEVICE_NVDIMM_ADDRESS(notifCmdReg) );
            if ( errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to write Set Event Notification "
                          "Cmd Reg. HUID: 0x%08x", getHuid(i_dimm) );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
                break;
            }

            // Recheck SET_EVENT_NOTIFICATION_STATUS to ensure everything is set
            // as we expect and we don't see any errors.
            errl = deviceRead( i_dimm, &notifStat, NVDIMM_SIZE,
                               DEVICE_NVDIMM_ADDRESS(notifStatusReg) );
            if ( errl )
            {
                PRDF_ERR( PRDF_FUNC "Failed to read Set Event Notification "
                          "Status Reg. HUID: 0x%08x", getHuid(i_dimm) );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
                break;
            }
            bitList = __nvdimmGetActiveBits( notifStat );

            // if Bit [1]: SET_EVENT_NOTIFICATION_ERROR = 1
            // or Bit [2]: PERSISTENCY_ENABLED = 0
            // or Bit [3]: WARNING_THRESHOLD_ENABLED = 0
            if ( bitList.count(1)  || !bitList.count(2) || !bitList.count(3) )
            {
                o_statusErr = true;

                // Make the log predictive and mask the fir
                io_sc.service_data->SetThresholdMaskId(0);

                // Callout the NVDIMM, no gard
                io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );

                // Send message to PHYP that save/restore may work
                o_rc = PlatServices::nvdimmNotifyProtChange( i_dimm,
                    NVDIMM::NVDIMM_RISKY_HW_ERROR );
                if ( SUCCESS != o_rc ) break;

                break;
            }
        }
        // Note: moving the threshold should clear the warning from
        // WARNING_THRESHOLD_STATUS, which allows future warnings to report.

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief  Analyze NVDIMM Warning Threshold Status Register for errors
 * @param  io_sc       The step code data struct.
 * @param  i_dimm      The target dimm.
 * @param  io_errFound Whether an error has already been found or not.
 * @return FAIL if unable to read register, else SUCCESS
 */
uint32_t __analyzeWarningThrStatusReg(STEP_CODE_DATA_STRUCT & io_sc,
                                      TargetHandle_t i_dimm, bool & io_errFound)
{
    #define PRDF_FUNC "[__analyzeWarningThrStatusReg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    // Get MCA, for signatures
    TargetHandle_t mca = getConnectedParent( i_dimm, TYPE_MCA );

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Warning Threshold Status Register (0xA7) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::WARNING_THRESHOLD_STATUS) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Warning Threshold Status Reg. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // Analyze Bit 2 First
        // BIT 2: ES_TEMP_WARNING
        if ( bitList.count(2) )
        {
            // Read the ES_TEMP and ES_TEMP_WARNING_HIGH_THRESHOLD values
            uint16_t msbEsTempReg = NVDIMM::i2cReg::ES_TEMP1;
            uint16_t lsbEsTempReg = NVDIMM::i2cReg::ES_TEMP0;

            uint16_t esTemp = 0;
            o_rc = __readTemp( i_dimm, msbEsTempReg, lsbEsTempReg, esTemp );
            if ( SUCCESS != o_rc ) break;

            uint16_t msbThReg = NVDIMM::i2cReg::ES_TEMP_WARNING_HIGH_THRESHOLD1;
            uint16_t lsbThReg = NVDIMM::i2cReg::ES_TEMP_WARNING_HIGH_THRESHOLD0;

            uint16_t esTempHighTh = 0;
            o_rc = __readTemp( i_dimm, msbThReg, lsbThReg, esTempHighTh );
            if ( SUCCESS != o_rc ) break;

            // Check to see if the ES_TEMP is negative (bit 12)
            bool esTempNeg = false;
            if ( esTemp & 0x1000 ) esTempNeg = true;

            // If ES_TEMP is equal or above ES_TEMP_WARNING_HIGH_THRESHOLD
            // Just in case ES_TEMP has moved before we read it out, we'll add
            // a 2°C margin when comparing to the threshold.
            if ( (esTemp >= (esTempHighTh - 0x0020)) && !esTempNeg )
            {
                __addSignature( io_sc, mca, io_errFound,
                                PRDFSIG_EsTmpWarnHigh );
            }
            // Else assume the warning is because of a low threshold.
            else
            {
                __addSignature( io_sc, mca, io_errFound,
                                PRDFSIG_EsTmpWarnLow );
            }

            // Callout BPM (backup power module) high
            o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != o_rc ) break;

            // Callout NVDIMM low, no gard
            io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );

            // Make the log predictive and mask the FIR.
            io_sc.service_data->SetThresholdMaskId(0);

            // Send message to PHYP that save/restore may work
            o_rc = PlatServices::nvdimmNotifyProtChange( i_dimm,
                NVDIMM::NVDIMM_RISKY_HW_ERROR );
            if ( SUCCESS != o_rc ) break;

            io_errFound = true;
        }
        // BIT 0: NVM_LIFETIME_WARNING
        if ( bitList.count(0) )
        {
            // Adjust warning threshold.
            uint16_t warnThReg = NVDIMM::i2cReg::NVM_LIFETIME_WARNING_THRESHOLD;
            uint16_t errThReg  = NVDIMM::i2cReg::NVM_LIFETIME_ERROR_THRESHOLD;
            bool firstWarn = false;
            bool statusErr = false;
            o_rc = __adjustThreshold( io_sc, i_dimm, warnThReg, errThReg,
                                      firstWarn, statusErr );
            if ( SUCCESS != o_rc ) break;

            // Make the log predictive, but do not mask the FIR
            io_sc.service_data->setServiceCall();

            // If we got a set event notification status error, add the
            // signature for that before adding the signature for the warning.
            // Also do not take our normal callout action since we already will
            // have called out the NVDIMM because of the status error.
            if ( statusErr )
            {
                __addSignature( io_sc, mca, io_errFound, PRDFSIG_NotifStatErr );

                // Need to set io_errFound here so the warning signature is
                // added to the multi-signature list instead of as the primary
                // signature.
                io_errFound = true;
            }
            else
            {
                // Callout NVDIMM on 1st, no gard
                io_sc.service_data->SetCallout( i_dimm, MRU_MED, NO_GARD );
            }

            // Update signature depending on whether this is the first or second
            // warning of this type.
            if ( firstWarn )
            {
                __addSignature( io_sc, mca, io_errFound, PRDFSIG_NvmLifeWarn1 );
            }
            else
            {
                __addSignature( io_sc, mca, io_errFound, PRDFSIG_NvmLifeWarn2 );
            }


            io_errFound = true;
        }
        // BIT 1: ES_LIFETIME_WARNING
        if ( bitList.count(1) )
        {
            // Adjust warning threshold.
            uint16_t warnThReg = NVDIMM::i2cReg::ES_LIFETIME_WARNING_THRESHOLD;
            uint16_t errThReg  = NVDIMM::i2cReg::ES_LIFETIME_ERROR_THRESHOLD;
            bool firstWarn = false;
            bool statusErr = false;
            o_rc = __adjustThreshold( io_sc, i_dimm, warnThReg, errThReg,
                                      firstWarn, statusErr );
            if ( SUCCESS != o_rc ) break;

            // Make the log predictive, but do not mask the FIR
            io_sc.service_data->setServiceCall();

            // If we got a set event notification status error, add the
            // signature for that before adding the signature for the warning.
            // Also do not take our normal callout action since we already will
            // have called out the NVDIMM because of the status error.
            if ( statusErr )
            {
                __addSignature( io_sc, mca, io_errFound, PRDFSIG_NotifStatErr );

                // Need to set io_errFound here so the warning signature is
                // added to the multi-signature list instead of as the primary
                // signature.
                io_errFound = true;
            }
            else
            {
                // Callout BPM (backup power module) high
                o_rc = __addBpmCallout( i_dimm, HWAS::SRCI_PRIORITY_HIGH );
                if ( SUCCESS != o_rc ) break;

                // Callout NVDIMM low, no gard
                io_sc.service_data->SetCallout( i_dimm, MRU_LOW, NO_GARD );
            }

            // Update signature depending on whether this is the first or second
            // warning of this type.
            if ( firstWarn )
            {
                __addSignature(io_sc, mca, io_errFound, PRDFSIG_EsLifeWarn1);
            }
            else
            {
                __addSignature(io_sc, mca, io_errFound, PRDFSIG_EsLifeWarn2);
            }

            io_errFound = true;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief  De-assert the EVENT_N pin by setting bit 2 in NVDIMM_MGT_CMD1 (0x41)
 * @param  i_dimm The target dimm.
 * @return FAIL if unable to read/write register, else SUCCESS
 */
uint32_t __deassertEventN( TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[__deassertEventN] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the NVDIMM_MGT_CMD1 register (0x41) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::NVDIMM_MGT_CMD1) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read NVDIMM_MGT_CMD1. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        // Set bit 2
        data |= 0x04;

        // Write the updated data back to NVDIMM_MGT_CMD1
        errl = deviceWrite( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::NVDIMM_MGT_CMD1) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to write NVDIMM_MGT_CMD1. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }


    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

#endif // HOSTBOOT_RUNTIME
#endif // CONFIG_NVDIMM

/**
 * @brief  MCACALFIR[8] - Error from NVDIMM health status registers
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeNvdimmHealthStatRegs( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[nimbus_mca::AnalyzeNvdimmHealthStatRegs] "

    #ifdef CONFIG_NVDIMM
    #ifdef __HOSTBOOT_RUNTIME

    uint32_t l_rc = SUCCESS;
    bool errFound = false;

    // We need to check both dimms for errors
    for ( auto & dimm : getConnected(i_chip->getTrgt(), TYPE_DIMM) )
    {
        // Skip any non-NVDIMMs
        if ( !isNVDIMM(dimm) ) continue;

        // Add SMART-specific, page 4 registers to FFDC
        errlHndl_t mainErrl = nullptr;
        mainErrl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( nullptr == mainErrl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get the global error log." );
            continue;
        }
        PlatServices::nvdimmAddPage4Ffdc( dimm, mainErrl );

        // De-assert the EVENT_N pin by setting bit 2 in NVDIMM_MGT_CMD1
        l_rc = __deassertEventN( dimm );
        if ( SUCCESS != l_rc ) continue;

        uint8_t data = 0;

        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Module Health Register (0xA0) 7:0
        errlHndl_t errl = deviceRead( dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(NVDIMM::i2cReg::MODULE_HEALTH) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Module Health Register. "
                      "HUID: 0x%08x", getHuid(dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            continue;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: Persistency Lost
        if ( bitList.count(0) )
        {
            // Analyze Health Status0 Reg, Health Status1 Reg,
            // and Error Theshold Status Reg
            l_rc = __analyzeHealthStatus0Reg( io_sc, dimm, errFound );
            if ( SUCCESS != l_rc ) continue;
            l_rc = __analyzeHealthStatus1Reg( io_sc, dimm, errFound );
            if ( SUCCESS != l_rc ) continue;
            l_rc = __analyzeErrorThrStatusReg( io_sc, dimm, errFound );
            if ( SUCCESS != l_rc ) continue;

            // If we didn't find any error, then keep the log hidden.
            if ( !errFound )
            {
                io_sc.service_data->setSignature( i_chip->getHuid(),
                    PRDFSIG_FirEvntGone );
                // Callout NVDIMM
                io_sc.service_data->SetCallout( dimm, MRU_MED, NO_GARD );
                continue;
            }

            // EVENT_N cannot be retriggered on a new PERSISTENCY_LOST_ERROR
            // if a previous PERSISTENCY_LOST_ERROR still exists. Meaning, we
            // cannot detect/report multiple errors that happen at different
            // points in time. As such, mask the EVENT_N bit here (MCACALFIR[8])
            // and make the log predictive.
            io_sc.service_data->SetThresholdMaskId(0);

            // Send message to PHYP that save/restore may work
            l_rc = PlatServices::nvdimmNotifyProtChange( dimm,
                NVDIMM::NVDIMM_RISKY_HW_ERROR );
            if ( SUCCESS != l_rc ) continue;

        }
        // BIT 1: Warning Threshold Exceeded
        else if ( bitList.count(1) )
        {
            l_rc = __analyzeWarningThrStatusReg( io_sc, dimm, errFound );
            if ( SUCCESS != l_rc ) continue;

            if ( !errFound )
            {
                io_sc.service_data->setSignature( i_chip->getHuid(),
                    PRDFSIG_FirEvntGone );
                // Callout NVDIMM
                io_sc.service_data->SetCallout( dimm, MRU_MED, NO_GARD );
                continue;
            }
        }
        // BIT 2: Persistency Restored
        else if ( bitList.count(2) )
        {
            // It would be rare to have an intermittent error that comes and
            // goes so fast we only see PERSISTENCY_RESTORED and not
            // PERSISTENCY_LOST_ERROR. Set predictive on threshold of 32
            // per day (rule code handles the thresholding), else just keep
            // as a hidden log.
            __addSignature( io_sc, i_chip->getTrgt(), errFound,
                            PRDFSIG_NvdimmPersRes );

            // Callout NVDIMM
            io_sc.service_data->SetCallout( dimm, MRU_MED, NO_GARD );
        }
        // BIT 3: Below Warning Threshold
        else if ( bitList.count(3) )
        {
            // Much like the persistency restored bit above, we don't expect
            // to see this, so just make a hidden log.
            __addSignature( io_sc, i_chip->getTrgt(), errFound,
                            PRDFSIG_BelowWarnTh );

            // Callout NVDIMM
            io_sc.service_data->SetCallout( dimm, MRU_MED, NO_GARD );
        }
        // BIT 4: Hardware Failure -- ignore - no logic feeding this
        // BIT 5: EVENT_N_LOW -- ignore
        // BIT 6:7: Unused

        // If we reach a threshold on MCACALFIR[8] of 32 per day, we assume
        // some intermittent error must be triggering the FIR that isn't a
        // persistency lost error which would cause us to mask. The rule code
        // handles the actual thresholding here.
        if ( io_sc.service_data->IsAtThreshold() && !errFound )
        {
            io_sc.service_data->setSignature( i_chip->getHuid(),
                                              PRDFSIG_IntNvdimmErr );

            // callout NVDIMM high, cable high, BPM high, no gard
            io_sc.service_data->SetCallout( dimm, MRU_HIGH, NO_GARD );
            l_rc = __addBpmCallout( dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != l_rc ) continue;
            l_rc = __addNvdimmCableCallout( dimm, HWAS::SRCI_PRIORITY_HIGH );
            if ( SUCCESS != l_rc ) continue;

            // Send message to PHYP that save/restore may work
            l_rc = PlatServices::nvdimmNotifyProtChange( dimm,
                    NVDIMM::NVDIMM_RISKY_HW_ERROR );
            if ( SUCCESS != l_rc ) continue;
        }
    }
    #else // IPL only

    // We don't expect to analyze NVDIMMs during IPL, so callout level 2 support
    PRDF_ERR( PRDF_FUNC "Unexpected call to analyze NVDIMMs at IPL." );
    io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH, NO_GARD );

    #endif // end runtime vs IPL check

    #else // CONFIG_NVDIMM not defined

    PRDF_ERR( PRDF_FUNC "CONFIG_NVDIMM not defined." );
    io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH, NO_GARD );

    #endif // end CONFIG_NVDIMM check

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( nimbus_mca, AnalyzeNvdimmHealthStatRegs );

} // end namespace nimbus_mca

} // end namespace PRDF

