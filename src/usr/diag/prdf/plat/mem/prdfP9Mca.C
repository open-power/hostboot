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

enum nvdimmRegOffset
{
    MODULE_HEALTH = 0x0A0,
    MODULE_HEALTH_STATUS0 = 0x0A1,
    MODULE_HEALTH_STATUS1 = 0x0A2,
    ERROR_THRESHOLD_STATUS = 0x0A5,
    WARNING_THRESHOLD_STATUS = 0x0A7,
};

/**
 * @brief  Gets a map list of which bits are set from a uint8_t bit list (7:0)
 * @param  i_data uint8_t bit list (7:0)
 * @return map<uint8_t, bool> with which bits were set in the bit list.
 */
std::map<uint8_t,bool> __nvdimmGetActiveBits( uint8_t i_data )
{
    // NOTE: Bit position in i_data that we get from the NVDIMM status register
    //       will be right justified (7:0), ie ordered 7 to 0 (left to right).
    std::map<uint8_t,bool> bitList;
    for ( uint8_t n = 0; n < 8; n++ )
    {
        if ( i_data & (0x01 << n) ) bitList[n] = true;
    }
    return bitList;
}

/**
 * @brief  Analyze NVDIMM Health Status0 Register for errors
 * @param  io_sc  The step code data struct.
 * @param  i_dimm The target dimm.
 * @return errl - fail if unable to read register
 */
uint32_t __analyzeHealthStatus0Reg( STEP_CODE_DATA_STRUCT & io_sc,
                                    TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[__analyzeHealthStatus0Reg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Health Status0 Register (0xA1) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(MODULE_HEALTH_STATUS0) );
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
            // TODO
        }
        // BIT 1: VDD Lost
        if ( bitList.count(1) )
        {
            // TODO
        }
        // BIT 2: VPP Lost
        if ( bitList.count(2) )
        {
            // TODO
        }
        // BIT 3: VTT Lost
        if ( bitList.count(3) )
        {
            // TODO
        }
        // BIT 4: DRAM not Self Refresh
        if ( bitList.count(4) )
        {
            // TODO
        }
        // BIT 5: Controller HW Error
        if ( bitList.count(5) )
        {
            // TODO
        }
        // BIT 6: NV Controller HW Error
        if ( bitList.count(6) )
        {
            // TODO
        }
        // BIT 7: NVM Lifetime Error
        if ( bitList.count(7) )
        {
            // TODO
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Analyze NVDIMM Health Status1 Register for errors
 * @param  io_sc  The step code data struct.
 * @param  i_dimm The target dimm.
 * @return errl - fail if unable to read register
 */
uint32_t __analyzeHealthStatus1Reg( STEP_CODE_DATA_STRUCT & io_sc,
                                    TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[__analyzeHealthStatus1Reg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Health Status1 Register (0xA2) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(MODULE_HEALTH_STATUS1) );
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
            // TODO
        }
        // BIT 1: Invalid Firmware
        if ( bitList.count(1) )
        {
            // TODO
        }
        // BIT 2: Configuration Data Error
        if ( bitList.count(2) )
        {
            // TODO
        }
        // BIT 3: No Energy Source
        if ( bitList.count(3) )
        {
            // TODO
        }
        // BIT 4: Energy Policy Not Set
        if ( bitList.count(4) )
        {
            // TODO
        }
        // BIT 5: Energy Source HW Error
        if ( bitList.count(5) )
        {
            // TODO
        }
        // BIT 6: Energy Source Health Assessment Error
        if ( bitList.count(6) )
        {
            // TODO
        }
        // BIT 7: Reserved

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Analyze NVDIMM Error Threshold Status Register for errors
 * @param  io_sc  The step code data struct.
 * @param  i_dimm The target dimm.
 * @return errl - fail if unable to read register
 */
uint32_t __analyzeErrorThrStatusReg( STEP_CODE_DATA_STRUCT & io_sc,
                                     TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[__analyzeErrorThrStatusReg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Error Threshold Status Register (0xA5) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(ERROR_THRESHOLD_STATUS) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Error Threshold Status Reg. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: NVM Lifetime Error
        if ( bitList.count(0) )
        {
            // TODO
        }
        // BIT 1: ES Lifetime Error
        if ( bitList.count(1) )
        {
            // TODO
        }
        // BIT 2: ES Temperature Error
        if ( bitList.count(2) )
        {
            // TODO
        }
        // BIT 3:7: Reserved

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

/**
 * @brief  Analyze NVDIMM Warning Threshold Status Register for errors
 * @param  io_sc  The step code data struct.
 * @param  i_dimm The target dimm.
 * @return errl - fail if unable to read register
 */
uint32_t __analyzeWarningThrStatusReg( STEP_CODE_DATA_STRUCT & io_sc,
                                       TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[__analyzeWarningThrStatusReg] "

    uint32_t o_rc = SUCCESS;
    uint8_t data = 0;

    do
    {
        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Warning Threshold Status Register (0xA7) 7:0
        errlHndl_t errl = deviceRead( i_dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(WARNING_THRESHOLD_STATUS) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read Warning Threshold Status Reg. "
                      "HUID: 0x%08x", getHuid(i_dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }
        std::map<uint8_t,bool> bitList = __nvdimmGetActiveBits( data );

        // BIT 0: NVM Lifetime Warning
        if ( bitList.count(0) )
        {
            // TODO
        }
        // BIT 1: ES Lifetime Warning
        if ( bitList.count(1) )
        {
            // TODO
        }
        // BIT 2: ES Temperature Warning
        if ( bitList.count(2) )
        {
            // TODO
        }
        // BIT 3:7: Unused

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

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

    uint32_t l_rc = SUCCESS;

    // We need to check both dimms for errors
    for ( auto & dimm : getConnected(i_chip->getTrgt(), TYPE_DIMM) )
    {
        uint8_t data = 0;

        // NVDIMM health status registers size = 1 byte
        size_t NVDIMM_SIZE = 1;

        // Read the Module Health Register (0xA0) 7:0
        errlHndl_t errl = deviceRead( dimm, &data, NVDIMM_SIZE,
            DEVICE_NVDIMM_ADDRESS(MODULE_HEALTH) );
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
            l_rc = __analyzeHealthStatus0Reg( io_sc, dimm );
            if ( SUCCESS != l_rc ) continue;
            l_rc = __analyzeHealthStatus1Reg( io_sc, dimm );
            if ( SUCCESS != l_rc ) continue;
            l_rc = __analyzeErrorThrStatusReg( io_sc, dimm );
            if ( SUCCESS != l_rc ) continue;
        }
        // BIT 1: Warning Threshold Exceeded
        if ( bitList.count(1) )
        {
            // Analyze Warning Threshold Status Reg
            l_rc = __analyzeWarningThrStatusReg( io_sc, dimm );
            if ( SUCCESS != l_rc ) continue;
        }
        // BIT 2: Persistency Restored
        if ( bitList.count(2) )
        {
            // TODO
        }
        // BIT 3: Below Warning Threshold
        if ( bitList.count(3) )
        {
            // TODO
        }
        // BIT 4: Hardware Failure
        if ( bitList.count(4) )
        {
            // TODO
        }
        // BIT 5: EVENT_N_LOW
        if ( bitList.count(5) )
        {
            // TODO
        }
        // BIT 6:7: Unused

    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( nimbus_mca, AnalyzeNvdimmHealthStatRegs );

} // end namespace nimbus_mca

} // end namespace PRDF

