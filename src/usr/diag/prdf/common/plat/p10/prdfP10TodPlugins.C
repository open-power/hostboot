/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10TodPlugins.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/**@file   prdfP9TodPlugins.C
 * @brief  defines all the TOD error plugins
 */

#include <prdfPluginDef.H>
#include <prdfPluginMap.H>
#include <prdfExtensibleChip.H>
#include <iipSystem.h>
#include <prdfP10ProcDomain.H>
#include <prdfGlobal_common.H>
#include <iipServiceDataCollector.h>
#include <prdfRegisterCache.H>
#include <UtilHash.H>
#include <algorithm>
#include <prdfPlatProcConst.H>
#include <prdfCallouts.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace TOD;

// FSP or HBRT only, not Hostboot
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)

/** @struct TodFaultData
 *  TOD Fault isolation information from a chip.
 */
struct TodFaultData
{
    TargetHandle_t chipReportingError; // target reporting tod error
    bool phypDetectedFault; // phyp detected a TOD fault on this chip
                            // (on either topology)
    bool isActiveMdmt;      // Chip is MDMT on active topology
    bool isBackupMdmt;      // MDMT on backup topology
    bool faultDetected[2];  // index 0 for fault on active topo, 1 for backup
    bool isMdmtAndFaulty[2];// chip is MDMT and has a fault on same topo
    bool activeTopologyIsPrimary; //topology selected as active
    TargetHandle_t chipSourcingClk[2];//if not MDMT, which chip is tod clk src
    uint32_t activeMasterPathPosition[2]; // Clock position providing the TOD
                                          // clock source to an MDMT

    /**
     *@brief  Constructor
     */
    explicit TodFaultData( TargetHandle_t i_procTgt ):
        chipReportingError( i_procTgt ),
        phypDetectedFault( false ),
        isActiveMdmt( false ),
        isBackupMdmt( false )
    {
        faultDetected[0]        =   false;
        faultDetected[1]        =   false;
        isMdmtAndFaulty[0]      =   false;
        isMdmtAndFaulty[1]      =   false;
        activeTopologyIsPrimary =   false;
        chipSourcingClk[0]      =   nullptr;
        chipSourcingClk[1]      =   nullptr;
        activeMasterPathPosition[0] = 0;
        activeMasterPathPosition[1] = 0;
    }
};

/** @struct TodFaultData
 * System TOD failover status
 */
struct TopologySwitchDetails
{
    bool masterPathHwFailOver; // hw failover status of master path
    bool phypSwitchedTopology; // topology switch status by Phyp

    /**
     * @brief Constructor
     */
    TopologySwitchDetails():
      masterPathHwFailOver( false ),
      phypSwitchedTopology( false )
    {}
};

#endif // FSP or HBRT only, not Hostboot

namespace Proc
{

// FSP or HBRT only, not Hostboot
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)

/**
 * @brief   Captures all the tod registers of all functional Proc chips.
 * @param   i_stepcode  The step code data struct
 * @return SUCCESS.
 */
int32_t todCaptureRegisters( STEP_CODE_DATA_STRUCT & i_stepcode )
{
    ProcDomain * l_procDomain =
        (ProcDomain*)systemPtr->GetDomain( PROC_DOMAIN );

    for( size_t i = 0; i < l_procDomain->GetSize(); i++ )
    {
        RuleChip * l_chip = l_procDomain->LookUp( i );
        l_chip->CaptureErrorData( i_stepcode.service_data->GetCaptureData(),
                            Util::hashString( "TODReg" ) );
    }
    return SUCCESS;
}

/**
 * @brief  Clears Tod errors register and Tod error bits in TP_LFIR
 * @param  i_stepcode  The step code data struct
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t todCleanUpErrors( STEP_CODE_DATA_STRUCT & i_stepcode )
{
    #define PRDF_FUNC "[Proc::todCleanUpErrors] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_RUNTIME // HBRT only

    ProcDomain * l_procDomain =
        (ProcDomain*)systemPtr->GetDomain( PROC_DOMAIN );

    for( size_t i = 0; i < l_procDomain->GetSize(); i++ )
    {
        int32_t l_rc = SUCCESS;
        RuleChip * l_procChip = l_procDomain->LookUp( i );

        // Clear bits 14,15,16,17,21,39 in TOD Error Register
        // Bits in this register are cleared by writing 1
        SCAN_COMM_REGISTER_CLASS * l_todError =
                    l_procChip->getRegister( "TOD_ERRORREGISTER" );

        l_rc = l_todError->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on TOD_ERRORREGISTER: "
                      "proc=0x%08x", l_procChip->GetId() );

            // Continue to try clearing the other chips
            o_rc = FAIL;
            continue;
        }

        uint64_t l_val = l_todError->GetBitFieldJustified( 0, 64 );
        l_val = l_val & 0x0003C40001000000ull; // bits 14,15,16,17,21,39

        if ( 0 != l_val )
        {
            l_todError->SetBitFieldJustified(  0, 64, l_val );
            l_rc = l_todError->Write();

            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"Write() failed on TOD_ERRORREGISTER: "
                              "proc=0x%08x", l_procChip->GetId() );
                o_rc = FAIL;
                continue;
            }
        }


        // Next read shall cause Force Read
        RegDataCache & regCache = RegDataCache::getCachedRegisters();
        regCache.flush( l_procChip, l_todError );

        // Clear bits 25 and 27 in TPLFIR
        SCAN_COMM_REGISTER_CLASS * l_andTpFir =
                        l_procChip->getRegister( "TP_LOCAL_FIR_AND" );

        l_andTpFir->setAllBits();
        l_andTpFir->ClearBit(25);
        l_andTpFir->ClearBit(27);

        l_rc = l_andTpFir->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on TP_LOCAL_FIR_AND: "
                      "proc=0x%08x", l_procChip->GetId() );
            o_rc = FAIL;
            continue;
        }
    }

    #endif // HBRT only

    return o_rc;

    #undef PRDF_FUNC
}

/**
 * @brief   Investigates if there is a failover initiated by HW.
 * @param   i_chip              chip reporting TOD errors
 * @param   io_faultData        Tod fault info
 * @param   o_failoverStatus    failover status
 */
void checkForHwInitiatedFailover( ExtensibleChip * i_chip,
                                  TodFaultData & io_faultData,
                                  TopologySwitchDetails & o_failoverStatus )
{
    #define PRDF_FUNC   "[Proc::checkForHwInitiatedFailover] "

    // This function detects whether an MDMT chip has switched its master path
    // due to a clock fault. In this case, PRD gets an attention due to a step
    // check error in Master Path 0. The failover modifies bit 12 of the TOD
    // status register. PRD finds that both active and backup topolgy use the
    // same master path (path 1). When PRD checks for faults on each topology
    // we'll be looking at path 1 for both and find no faults there. So this
    // function checks for the master patch failover case and marks the MDMT
    // chip at fault appropriately.

    do
    {
        if( false == io_faultData.isActiveMdmt  ||
            false == io_faultData.isBackupMdmt )
        {
            // don't consider slave procs for this check
            break;
        }

        // Is MDMT in a failover state.
        if(( false == io_faultData.isMdmtAndFaulty[0] &&
             false == io_faultData.isMdmtAndFaulty[1] ))

        {
            // Get TOD Error register.
            SCAN_COMM_REGISTER_CLASS * l_todError =
                        i_chip->getRegister("TOD_ERRORREGISTER");

            uint32_t l_oscPos = 1;

            if ( SUCCESS != l_todError->Read() )
            {
                PRDF_ERR( PRDF_FUNC"Read() failed on TOD_ERRORREGISTER: "
                      "i_chip=0x%08x", i_chip->GetId() );
                break;
            }

            if( l_todError->IsBitSet(14) )
            {
                l_oscPos = 0;
            }

            else if( !l_todError->IsBitSet(15))
            {
                break;
            }

            // We failed to capture a TOD error in master path. This implies
            // a HW path failover has occurred.
            o_failoverStatus.masterPathHwFailOver = true;

            uint32_t topPos =
                 ( true == o_failoverStatus.phypSwitchedTopology )? 1 : 0;

            io_faultData.faultDetected[topPos] = true;
            io_faultData.isMdmtAndFaulty[topPos] = true;
            io_faultData.activeMasterPathPosition[topPos] = l_oscPos;

            PRDF_TRAC( PRDF_FUNC "HW Initiated failover: MDMT 0x%08x "
                       "faulty, mpath pos: %d", i_chip->GetId(),
                       l_oscPos );
        }

    }while(0);

    #undef PRDF_FUNC
}

/**
 * @brief   Analyzes the TOD error of a given proc
 * @param   i_chip      chip reporting TOD errors
 * @param   o_faults    list of Tod fault info
 * @param   i_stepcode  The step code data struct
 * @param   io_failOverStatus   topology  failover status
 * @return  SUCCESS.
 */
int32_t todCollectFaultDataChip(  ExtensibleChip * i_chip,
                                  std::vector<TodFaultData> & o_faults,
                                  STEP_CODE_DATA_STRUCT & i_stepcode,
                                  TopologySwitchDetails & io_failOverStatus )
{
    #define PRDF_FUNC "[Proc::todCollectFaultDataChip] "

    TargetHandle_t l_chipTarget = i_chip->getTrgt();
    TodFaultData l_faultData ( l_chipTarget );

    uint32_t l_rc = FAIL;

    do
    {
        // Check if PHYP reported TOD error
        SCAN_COMM_REGISTER_CLASS * l_pTpLFir =
            i_chip->getRegister( "TP_LOCAL_FIR" );

        l_rc = l_pTpLFir->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on TP_LOCAL_FIR: i_chip=0x%08x",
                      i_chip->GetId() );
            break;
        }

        l_faultData.phypDetectedFault = l_pTpLFir->IsBitSet(27);

        // Deterimine active topology.
        SCAN_COMM_REGISTER_CLASS * l_todStatus =
                i_chip->getRegister("TOD_STATUSREGISTER");

        l_rc = l_todStatus->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on TOD_STATUSREGISTER: "
                      "i_chip=0x%08x", i_chip->GetId() );
            break;
        }

        //Reading TOD_STATUSREGISTER[0:2]
        //0b000 means configuration chosen is Primary
        //0b111 means configuration chosen is Secondary

        bool l_activeIsPrimary =
            ( 0 == l_todStatus->GetBitFieldJustified( 0, 3 ) );
        l_faultData.activeTopologyIsPrimary = l_activeIsPrimary;

        // Get TOD Error register.
        SCAN_COMM_REGISTER_CLASS * l_todError =
                        i_chip->getRegister("TOD_ERRORREGISTER");

        l_rc = l_todError->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on TOD_ERRORREGISTER: "
                      "i_chip=0x%08x", i_chip->GetId() );
            break;
        }

        // Check both topologies, active first.
        for ( int i = 0; i < 2; i++ )
        {
            // Each chip has 2 TOD topologies configured (primary and secondary)
            // One of these is selected as active topology and one as backup
            // In TodFaultData, index 0 is used for the active topology, and 1
            // for the backup. We also need to know whether we looking at the
            // primary or secondary topology, because that will determine
            // the bit positions we used in the TOD registers.
            // So within this for loop, index 0/1 refers to active/backup
            // l_topIsPri identifies whether the current topo was configured
            // in the primary or secondary position.

            bool l_topIsPri =
                    ( ( 0 == i ) ? l_activeIsPrimary : !l_activeIsPrimary );

            bool l_masterTodSelected = false ;
            bool l_masterDrawerSelected = false;

            // Check if MDMT on current topology.
            l_masterTodSelected =
                        l_todStatus->IsBitSet( l_topIsPri ? 13 : 17 );
            l_masterDrawerSelected =
                        l_todStatus->IsBitSet( l_topIsPri ? 14 : 18 );

            // Check master OSC status if MDMT
            if ( ( l_masterTodSelected ) && ( l_masterDrawerSelected ) )
            {
                // Deterimine which OSC card is used.
                bool l_osc0;    //means  master path 0
                bool l_oscFail;

                l_faultData.isActiveMdmt = l_todStatus->IsBitSet(23);
                l_faultData.isBackupMdmt = l_todStatus->IsBitSet(24);

                l_osc0 = !l_todStatus->IsBitSet( l_topIsPri ? 12 : 16 );
                l_faultData.activeMasterPathPosition[i] = l_osc0 ? 0 : 1;

                // Read step check error bit in TOD error register
                l_oscFail = l_todError->IsBitSet( l_osc0 ? 14 : 15 );

                if ( !l_oscFail )
                {
                    // It is possible that the master path select may have
                    // switched before PRD had the chance to analysis. Since we
                    // have no knowledge of when that could have happened,
                    // we'll simply look for a step check error on the other
                    // master path.
                    l_osc0 = !l_osc0;
                    l_oscFail = l_todError->IsBitSet( l_osc0 ? 14 : 15 );
                }

                if ( l_oscFail )
                {
                    // Set fault data.
                    l_faultData.faultDetected[i] = true;
                    l_faultData.isMdmtAndFaulty[i] = true;

                    PRDF_TRAC(PRDF_FUNC " MDMT: 0x%08x at Error, M-Path: %d, "
                              "topology: %c",
                              i_chip->GetId(), l_osc0 ? 0 : 1,
                              i == 0 ?'A':'B' );
                }

            }//if mdmt

            else // Is not MDMT on this topology.
            {
                // Deterimine whether slave chip is using Primary configuration
                // slave path (slave path 0 )or secondary configuration slave
                //path (slave path 1 )
                bool l_slv0 = !l_todStatus->IsBitSet( l_topIsPri ? 15 : 19 );

                // Check if TOD slave path has any step check error.
                // bit 16 and 21  of TOD_ERRORREGISTER indicate if there is any
                // TOD Error in slave path.

                bool l_slvErr = l_todError->IsBitSet( l_slv0 ? 16 : 21 );

                // If there is Step Check Error, we must determine proc sourcing
                // clock to  the chip reporting step check error. We do this by
                // reading PCRP0 for primary configuration and SCRP1 for
                // secondary configuration to determine which bus is being used
                // to transmit tod clock. We can use that to get the peer proc
                // at the other end of the bus.

                if ( l_slvErr )
                {
                    uint32_t l_connection = 0;
                    TargetHandle_t l_procClockSrc = nullptr;

                    uint32_t l_ret = FAIL;
                    l_ret = getTodPortControlReg( l_chipTarget, l_slv0,
                                                  l_connection );
                    if( SUCCESS != l_ret ) continue;

                    // The connection value is in bits 0:2.
                    l_connection >>= 29;
                    if ( l_connection > 7 )
                    {
                        PRDF_ERR( PRDF_FUNC"Configuration error for 0x%08x "
                                  "connection 0x%08x", getHuid(l_chipTarget),
                                  l_connection );
                        continue;
                    }
                    else
                    {
                        TYPE l_busType = TYPE_IOHS;

                        l_procClockSrc = getConnectedPeerProc( l_chipTarget,
                                                              l_busType,
                                                              l_connection );
                    }

                    if( nullptr == l_procClockSrc )
                    {
                        l_procClockSrc = l_chipTarget;
                    }

                    // Set fault data.
                    l_faultData.faultDetected[i] = true;
                    l_faultData.chipSourcingClk[i] = l_procClockSrc;

                    PRDF_TRAC( PRDF_FUNC " Slave 0x%08x at Error S-Path %d,"
                               "topology %c,  clk source is 0x%08x",
                               i_chip->GetId(), l_slv0 ? 0:1,
                               i == 0 ? 'A':'B',
                               getHuid( l_procClockSrc ) );

                } // error in slave
            }//else not mdmt
        }//for topology

        checkForHwInitiatedFailover( i_chip, l_faultData, io_failOverStatus );

        // Check for an internal path error in active topology
        uint32_t topPos = io_failOverStatus.phypSwitchedTopology ? 1 : 0;
        if ( !l_faultData.faultDetected[topPos]  && l_todError->IsBitSet(17) )
        {
            l_faultData.faultDetected[topPos] = true;
            l_faultData.chipSourcingClk[topPos] = l_chipTarget;
        }

        o_faults.push_back( l_faultData );

        l_rc = SUCCESS;

    } while(0);

    return l_rc;

    #undef PRDF_FUNC
}

/**
 * @brief   Collects TOD fault error info for all procs in the system
 * @param   i_chip      chip reporting TOD errors
 * @param   i_stepcode  The step code data struct
 * @param   io_FailoverStatus   hw initiated failover status
 */
void todCollectFaultDataSys( std::vector<TodFaultData> & o_faults,
                             STEP_CODE_DATA_STRUCT & i_stepcode,
                             TopologySwitchDetails & io_FailoverStatus )
{
    ProcDomain * l_procDomain =
        (ProcDomain*)systemPtr->GetDomain( PROC_DOMAIN );

    for( size_t i = 0; i < l_procDomain->GetSize(); i++ )
    {
        RuleChip * l_chip = l_procDomain->LookUp( i );
        uint32_t l_rc = todCollectFaultDataChip( l_chip, o_faults,
                                                 i_stepcode,
                                                 io_FailoverStatus );
        if( SUCCESS != l_rc )
        {
            PRDF_ERR("[todCollectFaultDataSys] Failed to analyze tod errors in"
                     "chip 0x%08x",l_chip->GetId() );
        }

    }
}

/**
 * @brief   Determines if Phyp switched the topology.
 * @return  o_topologySwitch   topology switch status
 */
bool  checkPhypSwitchedTopology(  )
{
    #define PRDF_FUNC "[checkPhypSwitchedTopology] "

    bool o_topologySwitch = false;

    ProcDomain * l_procDomain =
        (ProcDomain*)systemPtr->GetDomain( PROC_DOMAIN );

    for( size_t i = 0; i < l_procDomain->GetSize(); i++ )
    {
        RuleChip * l_chip = l_procDomain->LookUp( i );
        // Get TOD Error register.
        SCAN_COMM_REGISTER_CLASS * l_todError =
                        l_chip->getRegister("TOD_ERRORREGISTER");

        if( SUCCESS != l_todError->Read() )
        {
            PRDF_ERR( PRDF_FUNC"Read  failed for tod  error "
                     "register on 0x%08x", l_chip->GetId() );
            break;
        }

        o_topologySwitch = l_todError->IsBitSet(39);

        if( true == o_topologySwitch )
        {
            break;
        }
    }

    return o_topologySwitch;
    #undef PRDF_FUNC
}

/**
 * @brief Collects FFDC associated with step errors.
 * @param io_todErrorData    contains fault status and data for all chips.
 * @param i_failOverstatus  contains master path and topology failover data.
 * @param o_errorSummary    contains FFDC associated with step errors.
 */
void collectTodErrorFfdc(   std::vector<TodFaultData> & io_todErrorData,
                            TopologySwitchDetails i_failOverstatus,
                            TodErrorSummary & o_errorSummary )
{
    std::vector<TodFaultData> faultyChip;
    o_errorSummary = TodErrorSummary();

    for ( auto & i : io_todErrorData )
    {
        if ( i.phypDetectedFault )
        {
            o_errorSummary.phypDetectedTodError = 1;
        }

        if( i.isActiveMdmt )
        {
            o_errorSummary.activeMdmt = getHuid( i.chipReportingError );
            o_errorSummary.activeTopology =
                                        i.activeTopologyIsPrimary ? 1 : 0;
            // master path position selected for active MDMT
            o_errorSummary.activeTopologyMastPath =
                                        i.activeMasterPathPosition[0];
        }

        if( i.isBackupMdmt )
        {
            o_errorSummary.backUpMdmt = getHuid( i.chipReportingError );
            // master path position selected for backup MDMT
            o_errorSummary.backUpTopologyMastPath =
                                            i.activeMasterPathPosition[1];
        }

        // Add to list if some error is detected.
        if ( i.phypDetectedFault || i.faultDetected[0] ||
             i.faultDetected[1] )
        {
            faultyChip.push_back( i );
        }
    }
    o_errorSummary.topologySwitchByPhyp =
                    i_failOverstatus.phypSwitchedTopology ? 1 :0 ;

    o_errorSummary.hardwareSwitchFlip =
                    i_failOverstatus.masterPathHwFailOver ? 1 : 0;
    o_errorSummary.reserved = 0;

    io_todErrorData.empty();
    io_todErrorData = faultyChip;
}

/**
 * @brief Adds FFDC associated with step error as Capture data.
 * @param i_stepcode        Step Code Data Struct.
 * @param i_chip            Chip reporting TOD step error.
 * @param i_errorSummary    contains FFDC associated with step error.
 */
void addFfdcToCaptureData(  ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & i_stepcode,
                            TodErrorSummary & i_errorSummary )
{
    size_t sz_w = sizeof(CPU_WORD);
    size_t sz_t =
            ((sizeof(TodErrorSummary) + sz_w - 1) / sz_w ) * sz_w;
    uint8_t errorDataBuff[sz_t];
    memset( &errorDataBuff, 0x00, sz_t );
    memcpy( &errorDataBuff, &i_errorSummary, sizeof(TodErrorSummary) );

    #if( __BYTE_ORDER == __LITTLE_ENDIAN )

    for( uint32_t i = 0; i < sz_t / sz_w; i++ )
    {
        ((CPU_WORD *)errorDataBuff)[i] =
                        htobe32(( (CPU_WORD *) errorDataBuff)[i]);
    }

    #endif

    BitString  bs( sz_t * 8, (CPU_WORD *) & errorDataBuff );

    CaptureData & cd = i_stepcode.service_data->GetCaptureData();
    cd.Add( i_chip->getTrgt(), Util::hashString("TOD_ERROR_DATA"), bs );
}

#endif // FSP or HBRT only, not Hostboot

/**
 * @brief   Analyzes the step check error of all procs in the system
 * @param   i_chip      chip reporting TOD errors
 * @param   i_stepcode  The step code data struct
 * @return  SUCCESS.
 */
int32_t todStepCheckFault( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_stepcode )
{
    #define PRDF_FUNC "[Proc::todStepCheckFault] "

    // FSP or HBRT only, not Hostboot
    #if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)

    // When we analyze a step check fault, we will look at all chips in the
    // system--both topologies. After we've collected TOD fault data on each
    // chip, we will categorize the failure as:
    //   - MDMT Clock problem
    //   - Internal path error
    //   - Connection error between chips
    // In case of connection error,we try to minimize the list of chips to the
    // list of most probable chips causing TOD errors. Once all the chips at
    // fault are isolated, hwsv is requested to create a new back up topology.

    // Collect TOD registers for FFDC.
    todCaptureRegisters( i_stepcode );

    // Collect TOD fault data.
    std::vector<TodFaultData> l_faultData;

    // List of chips for HWSV to avoid when constructing a new backup topo
    std::vector< TargetHandle_t > l_chipBlackList;

    // Osc for HWSV to avoid when constructing a new backup topology
    // Since HB doesn't model osc targets, we need a proc and Osc position
    TargetHandle_t procOscTgtBl = nullptr; // Proc target assoc with bad Osc
    uint32_t oscPosBl = 0xFFFFFFFF; // Osc position relative to proc

    TopologySwitchDetails failOverstatus;
    failOverstatus.phypSwitchedTopology = checkPhypSwitchedTopology( );
    todCollectFaultDataSys( l_faultData, i_stepcode, failOverstatus );
    TodErrorSummary todErrorFfdc;
    collectTodErrorFfdc( l_faultData, failOverstatus, todErrorFfdc );

    bool l_phypError = false;
    TargetHandle_t mdmtList[2] = {nullptr, nullptr };
    uint8_t mdmtFailedOscPos[2] = {0xFF, 0xFF};
    uint8_t analysisSummary[2] = { NO_TOD_ERROR, NO_TOD_ERROR };
    bool l_allInternal = true;
    bool l_foundFault = false;

    // Find MDMT chips at fault
    for ( std::vector<TodFaultData>::iterator i = l_faultData.begin();
          i != l_faultData.end(); i++ )
    {
        if ( i->phypDetectedFault )
        {
            l_phypError = true;
        }

        for ( int t = 0; t < 2; t++ )
        {
            if( i->isMdmtAndFaulty[t] )
            {
                mdmtList[t] = i->chipReportingError;
                mdmtFailedOscPos[t] = i->activeMasterPathPosition[t];
            }
        }
    }

    if ( l_phypError )
    {
        i_stepcode.service_data->SetThresholdMaskId(0);
    }

    // Look at both topologies.
    for ( int i = 0; i < 2; i++ )
    {
        // Classifications of topology errors:
        // 1) MDMT clock problem - callout clock or MDMT.
        // 2) Internals only - callout chips.
        // 3) Network error - clear internals, and isolate.

        // MDMT analysis

        if( nullptr != mdmtList[i] )
        {
            // HW initiated failover. Callout the failed OSC.
            if ( failOverstatus.masterPathHwFailOver )
            {
                i_stepcode.service_data->SetThresholdMaskId(0);
            }
            // Add Osc to blacklist
            procOscTgtBl = mdmtList[i];
            oscPosBl = mdmtFailedOscPos[i];

            // Add Proc to blacklist
            l_chipBlackList.push_back( mdmtList[i] );

            // Callout and gard TOD OSC
            i_stepcode.service_data->SetCallout(
                PRDcallout( mdmtList[i], PRDcalloutData::TYPE_TODCLK ) );

            // Callout MDMT chip
            i_stepcode.service_data->SetCallout(mdmtList[i], MRU_MED, NO_GARD);

            //callout a symbolic FRU to replace FRU/interfaces between Proc and
            //TOD OSC card
            i_stepcode.service_data->SetCallout( TOD_CLOCK_ERR, MRU_MED,
                                                 NO_GARD );
            analysisSummary[i] = MASTER_PATH_ERROR;

            // We have analyzed this topology to an MDMT fault, move on to the
            // backup topology
            continue;
        }

        // Collect some information for further classification
        for ( std::vector<TodFaultData>::iterator j = l_faultData.begin();
                j != l_faultData.end(); j++ )
        {
            // If fault on topology.
            if ( j->faultDetected[i] )
            {
                l_foundFault = true;

                // Check if non-internal fault.
                if( j->chipSourcingClk[i] != j->chipReportingError )
                {
                    // ignore internal path errors during hw failover.
                    l_allInternal = false;
                }
            }
        }

        // Skip analysis if this topology has nothing.
        if ( !l_foundFault )
        {
            continue;
        }

        if ( l_allInternal ) // Internal callouts.
        {

            for ( std::vector<TodFaultData>::iterator j = l_faultData.begin();
                    j != l_faultData.end(); j++ )
            {
                if ( j->chipSourcingClk[i] == j->chipReportingError )
                {

                    if ( nullptr != j->chipReportingError )
                    {
                        // update consolidated callout list and
                        //black list for internal path errors
                        i_stepcode.service_data->SetCallout(
                                        j->chipReportingError,MRU_MED );
                        l_chipBlackList.push_back( j->chipReportingError );
                    }
                }
            }

            analysisSummary[i] = INTERNAL_PATH_ERROR;
        }
        else // Network callout.
        {
            // Clear all internal reports and get chips.
            for ( std::vector<TodFaultData>::iterator j = l_faultData.begin();
                    j != l_faultData.end(); j++ )
            {
                if ( j->chipSourcingClk[i] == j->chipReportingError )
                {
                    j->faultDetected[i] = false;
                }
            }

            TargetHandleList l_rootList;
            std::vector<TodFaultData>::iterator itSrc;

            for( itSrc = l_faultData.begin(); itSrc != l_faultData.end();
                 itSrc++ )
            {
                std::vector<TodFaultData>::iterator itReport;
                bool l_badSrc = false;

                if( !itSrc->faultDetected[i] )
                    continue;

                for( itReport = l_faultData.begin();
                     itReport != l_faultData.end();
                     itReport++ )
                {
                    // If proc A is getting its tod clock from proc B and both
                    // are reporting step check errors, we callout only B.
                    if(  itSrc->chipSourcingClk[i] ==
                         itReport->chipReportingError )
                    {
                        if ( true == itReport->faultDetected[i] )
                        {
                            l_badSrc = true;
                            l_rootList.push_back(itReport->chipReportingError);

                            PRDF_TRAC( PRDF_FUNC "Network callout adding clk"
                                       "source chip 0x%08x topology %c",
                                       getHuid(itReport->chipReportingError ),
                                       i == 0 ? 'A':'B' );
                        }
                        break;
                    }
                }

                if( !l_badSrc )
                {
                    l_rootList.push_back( itSrc->chipReportingError );
                    PRDF_TRAC( PRDF_FUNC "Network callout adding chip 0x%08x "
                               "i = %c", getHuid( itSrc->chipReportingError ),
                                i == 0 ? 'A':'B' );
                }
            }

            // Sort, remove unique.
            std::sort( l_rootList.begin(), l_rootList.end() );
            std::vector<TargetHandle_t>::iterator itChip;
            itChip = std::unique(l_rootList.begin(), l_rootList.end());
            l_rootList.erase( itChip,l_rootList.end() );

            //Calling out the final list of chips reporting connection
            //problem in  TOD network.
            for ( auto &failedChip : l_rootList )
            {
                // update the consolidated callout list and
                // black list for hwsv
                i_stepcode.service_data->SetCallout( failedChip, MRU_MED );
                l_chipBlackList.push_back( failedChip );
            } //for l_rootList

            analysisSummary[i] = SLAVE_PATH_NETWORK_ERROR;

        }// else network error

    }//for topology

    std::sort( l_chipBlackList.begin(), l_chipBlackList.end() );
    std::vector<TargetHandle_t>::iterator itBlackList;
    itBlackList = std::unique( l_chipBlackList.begin(), l_chipBlackList.end());
    l_chipBlackList.erase( itBlackList, l_chipBlackList.end() );

    // Now we call HWSV to create a new backup topology. The chips in the black
    // list will not be selected as the new MDMT.
    #ifdef __HOSTBOOT_RUNTIME // HBRT only
    todErrorFfdc.topologyResetRequested = 0;
    if ( i_stepcode.service_data->IsAtThreshold() )
    {
        requestNewTODTopology( oscPosBl, procOscTgtBl,
                               l_chipBlackList, !l_phypError );
        todErrorFfdc.topologyResetRequested = 1;
    }
    #endif  // HBRT only

    // If we never made a callout, call out this chip.
    if ( 0 == i_stepcode.service_data->getMruListSize() )
    {
        i_stepcode.service_data->SetCallout( i_chip->getTrgt() );
        analysisSummary[0] = UNKNOWN_TOD_ERROR;
        analysisSummary[1] = UNKNOWN_TOD_ERROR;
    }

    // Clean up all TOD error reports.
    if ( SUCCESS != todCleanUpErrors( i_stepcode ) )
    {
        PRDF_ERR(PRDF_FUNC "Failed to clear TOD Errors of the"
                 "System" );
    }

    for( auto &blChip : l_chipBlackList )
    {
        PRDF_TRAC( PRDF_FUNC"black list chip HUID: 0x%08x ",
                   getHuid( blChip ) );
    }

    if (procOscTgtBl)
    {
        PRDF_TRAC( PRDF_FUNC "black list osc chip HUID 0x%08x Pos %d",
                   getHuid(procOscTgtBl), oscPosBl );
    }

    // At last, add FFDC as capture data to error log
    todErrorFfdc.activeTopologySummary = analysisSummary[0];
    todErrorFfdc.backUpTopologySummary = analysisSummary[1];
    addFfdcToCaptureData( i_chip, i_stepcode, todErrorFfdc );

    #endif // FSP or HBRT only, not Hostboot

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( p10_proc, Proc, todStepCheckFault );

/**
 * @brief   Request for creation of a new back up topology.
 * @param   i_chip      chip reporting TOD errors
 * @param   i_stepcode  The step code data struct
 * @return  SUCCESS.
 */
int32_t todNewTopologyIfBackupMDMT( ExtensibleChip * i_chip,
                                    STEP_CODE_DATA_STRUCT & i_stepcode )
{
    #ifdef __HOSTBOOT_RUNTIME // HBRT only

    do
    {
        SCAN_COMM_REGISTER_CLASS * l_todStatus =
                        i_chip->getRegister( "TOD_STATUSREGISTER" );

        if( SUCCESS != l_todStatus->Read( ) )
        {
            PRDF_ERR("[todNewTopologyIfBackupMDMT] Failed to read TOD status"
                     "register, address 0x%16llx of proc 0x%08x ",
                     l_todStatus->GetAddress(),i_chip->GetId() );
            break;
        }

        bool primaryIsActive = !( 0 == l_todStatus->GetBitFieldJustified( 0,3 ) );

        /* Check this chips role
         * Topology - 1
         *
         * TOD_STATUS[13]   TOD_STATUS[14]          Inference
         *      1               1                   Mster TOD Master Drawer
         *      0               1                   Slave TOD Master Drawer
         *      0               0                   Slave TOD Slave Drawer
         *      1               0                   Master TOD Slave Drawer

         * Topology - 2
         * TOD_STATUS[17]   TOD_STATUS[18]  Inference
         *
         *   Truth Table is same as above
         */

        // Check for MDMT status.
        bool l_masterTodSelect;
        bool l_masterDrawerSelect;
        l_masterTodSelect = l_todStatus->IsBitSet(
                                       13 + ( primaryIsActive ? 0 : 4 ) );
        l_masterDrawerSelect = l_todStatus->IsBitSet(
                                       14 + ( primaryIsActive ? 0 : 4 ) );

        // If this is the MDMT then request a new topology.
        if( ( l_masterTodSelect ) && ( l_masterDrawerSelect ) )
        {
            TargetHandleList badChipList;
            badChipList.push_back( i_chip->getTrgt() );
            requestNewTODTopology( 0xFFFFFFFF, nullptr, badChipList, false );
        }

    } while(0);

    #endif // HBRT only

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc, Proc, todNewTopologyIfBackupMDMT );


/**
 * @brief   Requests for a toplogy switch in response to logic parity error.
 * @param   i_chip      chip reporting TOD logic parity error.
 * @param   i_stepcode  The step code data struct
 * @return  SUCCESS.
 */
int32_t requestTopologySwitch( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_stepcode )
{
    #ifdef __HOSTBOOT_RUNTIME // HBRT only
    if ( i_stepcode.service_data->IsAtThreshold() )
    {
        // Reconfigure the TOD topology and let PHYP know when backup is good.
        TargetHandleList badChipList;
        badChipList.push_back( i_chip->getTrgt( ) );
        requestNewTODTopology( 0xFFFFFFFF, nullptr, badChipList, true );
    }
    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc, Proc, requestTopologySwitch );

/**
 * @brief   Checks if TOD error analysis is disabled on platform.
 * @param   i_chip      chip reporting TOD error.
 * @param   i_stepcode  The step code data struct.
 * @return  SUCCESS  if TOD analysis is disabled
 */
int32_t isTodDisabled(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    #if !defined(__HOSTBOOT_MODULE) // FSP only

    // For now, assume the system terminated at runtime.

    return PRD_SCAN_COMM_REGISTER_ZERO; // continue TOD analysis

    #elif defined(__HOSTBOOT_RUNTIME) // HBRT only

    // This is HBRT code so we can assume we are at runtime. Ensure PHYP is the
    // hypervisor.
    if (isHyprConfigPhyp() && !isMfgAvpEnabled() && !isMfgHdatAvpEnabled())
    {
        return PRD_SCAN_COMM_REGISTER_ZERO; // continue TOD analysis
    }
    else
    {
        // TOD fault analysis is not supported and we should not get this
        // attention.
        io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED);
        io_sc.service_data->setPredictive();

        return SUCCESS; // analysis done
    }

    #else // Hosbtoot only

    // TOD fault analysis is not supported and we should not get this attention.
    io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED);
    io_sc.service_data->setPredictive();

    return SUCCESS; // analysis done

    #endif
}
PRDF_PLUGIN_DEFINE_NS( p10_proc, Proc, isTodDisabled );

} //namespace Proc ends

} //namespace PRDF ends
