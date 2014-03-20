/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Pll.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 * @file prdfP8PLL.C
 * @brief chip Plug-in code for proc pll support
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

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{


enum
{
    // All of the chiplet PLL_ERROR bits below
    // are collected in this TP_LFIR bit
    PLL_DETECT_P8 = 19,
    // Chiplet PLL_ERROR mask and error bits
    PLL_ERROR_MASK  = 12,
    PLL_ERROR_BIT   = 25,
    PB_DMI_RIGHT_PLL_ERROR = 25, // Venice only
    PB_DMI_LEFT_PLL_ERROR  = 26, // Venice and Murano
    // PCB Slave internal parity error
    PARITY_ERROR_MASK  = 8,
    PARITY_ERROR_BIT   = 4,
};

/**
  * @brief this is to get a list of pll error
  *        register data to work on
  * @param  i_chip          P8 chip
  * @param  o_pllErrRegList Pll Err Reg list
  * @note
  */
void GetProcPllErrRegList(ExtensibleChip * i_chip,
                          P8DataBundle::ProcPllErrRegList& o_pllErrRegList)
{
    #define PRDF_FUNC "[Proc::GetProcPllErrRegList] "
    o_pllErrRegList.clear();
    P8DataBundle::PllErrReg entry;

    do
    {
        // PB
        entry.chip      = i_chip;
        entry.type      = P8DataBundle::PB;
        entry.errReg    = i_chip->getRegister("PB_ERROR_REG");
        entry.configReg = i_chip->getRegister("PB_CONFIG_REG");
        o_pllErrRegList.push_back( entry );

        // ABUS
        entry.chip      = i_chip;
        entry.type      = P8DataBundle::ABUS;
        entry.errReg    = i_chip->getRegister("ABUS_ERROR_REG");
        entry.configReg = i_chip->getRegister("ABUS_CONFIG_REG");
        o_pllErrRegList.push_back( entry );

        // EX
        TargetHandleList exList = getConnected(
                            i_chip->GetChipHandle(), TYPE_EX);
        ExtensibleChip * exChip;

        TargetHandleList::iterator itr = exList.begin();
        for( ; itr != exList.end(); ++itr)
        {
            PRDF_DTRAC(PRDF_FUNC"EX: 0x%.8X", getHuid(*itr));
            exChip = (ExtensibleChip *)systemPtr->GetChip( *itr );
            if( NULL == exChip ) continue;

            entry.chip      = exChip;
            entry.type      = P8DataBundle::EX;
            entry.errReg    = exChip->getRegister("EX_ERROR_REG");
            entry.configReg = exChip->getRegister("EX_CONFIG_REG");
            o_pllErrRegList.push_back( entry );
        }

    } while(0);

    #undef PRDF_FUNC
}

/**
  * @brief Query the PLL chip for a Proc PLL error
  * @param  i_chip P8 chip
  * @param o_result set to true in the presence of PLL error
  * @returns Failure or Success of query.
  * @note
  */
int32_t QueryProcPll( ExtensibleChip * i_chip,
                        bool & o_result)
{
    #define PRDF_FUNC "[Proc::QueryProcPll] "

    int32_t rc = SUCCESS;
    o_result = false;

    MODEL procModel = getProcModel( i_chip->GetChipHandle() );

    // Next check for the error reg bits in the chiplets
    P8DataBundle * procdb = getDataBundle( i_chip );
    P8DataBundle::ProcPllErrRegList & procPllErrRegList =
        procdb->getProcPllErrRegList();

    // Always get a list here since this is the entry point
    GetProcPllErrRegList( i_chip, procPllErrRegList );

    do
    {
        P8DataBundle::ProcPllErrRegListIter itr = procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            rc = (*itr).errReg->Read();
            if (rc != SUCCESS) break;

            rc = (*itr).configReg->Read();
            if (rc != SUCCESS) break;

            if( P8DataBundle::PB == (*itr).type )
            {
                if(( (*itr).errReg->IsBitSet(PB_DMI_LEFT_PLL_ERROR) &&
                     !(*itr).configReg->IsBitSet(PLL_ERROR_MASK) ) ||
                   (( MODEL_VENICE == procModel) &&
                    ( (*itr).errReg->IsBitSet(PB_DMI_RIGHT_PLL_ERROR) &&
                      !(*itr).configReg->IsBitSet(PLL_ERROR_MASK) )))
                {
                    o_result = true;
                    break;
                }
            }
            else if((*itr).errReg->IsBitSet(PLL_ERROR_BIT) &&
               !(*itr).configReg->IsBitSet(PLL_ERROR_MASK))
            {
                o_result = true;
                break;
            }
        }

    } while(0);

    // clear the PLL Err Reg list if no pll error was found
    if(false == o_result)
    {
        procPllErrRegList.clear();
    }

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, QueryProcPll );

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
        if (rc != SUCCESS) break;

        rc = pciConfigReg->Read();
        if (rc != SUCCESS) break;

        if(pciErrReg->IsBitSet(PLL_ERROR_BIT) &&
           !pciConfigReg->IsBitSet(PLL_ERROR_MASK))
        {
            o_result = true;
        }

    } while(0);

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
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
int32_t QueryPll( ExtensibleChip * i_chip,
                        bool & o_result)
{
    #define PRDF_FUNC "[Proc::QueryPll] "

    int32_t rc = SUCCESS;
    o_result = false;

    SCAN_COMM_REGISTER_CLASS * TP_LFIR =
                i_chip->getRegister("TP_LFIR");
    SCAN_COMM_REGISTER_CLASS * TP_LFIRmask =
                i_chip->getRegister("TP_LFIR_MASK");

    do
    {
        rc = TP_LFIR->Read();
        if (rc != SUCCESS) break;

        rc = TP_LFIRmask->Read();
        if (rc != SUCCESS) break;

        if( ! (TP_LFIR->IsBitSet(PLL_DETECT_P8) &&
               !TP_LFIRmask->IsBitSet(PLL_DETECT_P8)) )
        {
            // if global pll bit is not set, break out
            break;
        }

        rc = QueryPciPll( i_chip, o_result );
        if ((rc != SUCCESS) || (true == o_result)) break;

        rc = QueryProcPll( i_chip, o_result );
        if ((rc != SUCCESS) || (true == o_result)) break;

    } while(0);

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, QueryPll );


/**
  * @brief  Clear the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  */
int32_t ClearPll( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::ClearPll] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        // Clear proc osc error reg bits
        P8DataBundle * procdb = getDataBundle( i_chip );
        P8DataBundle::ProcPllErrRegList & procPllErrRegList =
                           procdb->getProcPllErrRegList();
        if( procPllErrRegList.empty() )
        {
            GetProcPllErrRegList( i_chip, procPllErrRegList );
        }

        P8DataBundle::ProcPllErrRegListIter itr = procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            (*itr).errReg->ClearBit(PLL_ERROR_BIT);
            if( P8DataBundle::PB == (*itr).type )
            {
                (*itr).errReg->ClearBit(PB_DMI_LEFT_PLL_ERROR);
            }
            rc |= (*itr).errReg->Write();
        }

        // Clear pci osc error reg bit
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
                i_chip->getRegister("PCI_ERROR_REG");
        pciErrReg->ClearBit(PLL_ERROR_BIT);
        rc |= pciErrReg->Write();

        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIR =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIR->setAllBits();
        TP_LFIR->ClearBit(PLL_DETECT_P8);
        rc |= TP_LFIR->Write();

        // Need to clear the PLL Err Reg list so it can
        // be populated with fresh data on the next analysis
        // can do this in error case to save some space
        procPllErrRegList.clear();
    }

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, ClearPll );

/**
  * @brief Mask the PLL error for P8 Plugin
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success of query.
  * @note
  */
int32_t MaskPll( ExtensibleChip * i_chip,
                 STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Proc::MaskPll] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        MODEL procModel = getProcModel( i_chip->GetChipHandle() );
        // fence off proc osc error reg bits
        P8DataBundle * procdb = getDataBundle( i_chip );
        P8DataBundle::ProcPllErrRegList & procPllErrRegList =
            procdb->getProcPllErrRegList();
        if( procPllErrRegList.empty() )
        {
            GetProcPllErrRegList( i_chip, procPllErrRegList );
        }

        P8DataBundle::ProcPllErrRegListIter itr =
                                   procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            // Error is already fenced
            if( (*itr).configReg->IsBitSet(PLL_ERROR_MASK) )
            {
                continue;
            }

            bool needMask = false;
            if( P8DataBundle::PB == (*itr).type )
            {
                if( ((*itr).errReg->IsBitSet(PB_DMI_LEFT_PLL_ERROR)) ||
                    (( MODEL_VENICE == procModel) &&
                     ( (*itr).errReg->IsBitSet(PB_DMI_RIGHT_PLL_ERROR))) )
                {
                    (*itr).configReg->SetBit(PLL_ERROR_MASK);
                    needMask = true;
                }
            }
            else if( (*itr).errReg->IsBitSet(PLL_ERROR_BIT) )
            {
                (*itr).configReg->SetBit(PLL_ERROR_MASK);
                needMask = true;
            }

            if( needMask )
            {
                rc |= (*itr).configReg->Write();
            }
        }

        // fence off pci osc error reg bit
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
            i_chip->getRegister("PCI_ERROR_REG");
        SCAN_COMM_REGISTER_CLASS * pciConfigReg =
            i_chip->getRegister("PCI_CONFIG_REG");

        if(pciErrReg->IsBitSet(PLL_ERROR_BIT) &&
           !pciConfigReg->IsBitSet(PLL_ERROR_MASK))
        {
            pciConfigReg->SetBit(PLL_ERROR_MASK);
            rc |= pciConfigReg->Write();
        }

        // Need to clear the PLL Err Reg list so it can
        // be populated with fresh data on the next analysis
        // can do this in error case to save some space
        procPllErrRegList.clear();

        // Since TP_LFIR bit is the collection of all of the
        // pll error reg bits, we can't mask it or we will not
        // see any PLL errors reported from the error regs

    }  // if not checkstop

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                    i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, MaskPll );

/**
 * @brief  Optional plugin function called after analysis is complete but
 *         before PRD exits.
 * @param  i_chip    P8 chip.
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PllPostAnalysis( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Proc::PllPostAnalysis] "

    // Need to clear the PLL Err Reg list so it can
    // be populated with fresh data on the next analysis
    P8DataBundle * procdb = getDataBundle( i_chip );
    P8DataBundle::ProcPllErrRegList & procPllErrRegList =
                        procdb->getProcPllErrRegList();
    procPllErrRegList.clear();

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, PllPostAnalysis );

/**
 * @brief   capture additional PLL FFDC
 * @param   i_chip   P8 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t capturePllFfdc( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Proc::capturePllFfdc] "

    // Add FSI status reg
    captureFsiStatusReg( i_chip, io_sc );

    // Add EX scom data
    TargetHandleList exList = getConnected(
                        i_chip->GetChipHandle(), TYPE_EX);
    ExtensibleChip * exChip;
    TargetHandleList::iterator itr = exList.begin();
    for( ; itr != exList.end(); ++itr)
    {
        exChip = (ExtensibleChip *)systemPtr->GetChip(*itr);
        if( NULL == exChip ) continue;

        exChip->CaptureErrorData(
                io_sc.service_data->GetCaptureData(),
                Util::hashString("PllFIRs"));
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, capturePllFfdc );

/**
  * @brief   Check PCB Slave internal parity errors
  * @param   i_chip P8 chip
  * @param   o_parityErr true for parity error, false otherwise
  * @param   io_sc  service data collector
  * @returns FAIL or SUCCESS
  */
int32_t CheckParityErr( ExtensibleChip * i_chip,
                        bool & o_parityErr,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Proc::CheckParityErr] "

    int32_t rc = SUCCESS;
    o_parityErr = false;
    P8DataBundle * procdb = getDataBundle( i_chip );
    P8DataBundle::ProcPllErrRegList & procPllErrRegList =
        procdb->getProcPllErrRegList();

    do
    {
        // First check PCI chiplet
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
            i_chip->getRegister("PCI_ERROR_REG");
        SCAN_COMM_REGISTER_CLASS * pciConfigReg =
            i_chip->getRegister("PCI_CONFIG_REG");

        rc = pciErrReg->Read();
        if (rc != SUCCESS) break;

        rc = pciConfigReg->Read();
        if (rc != SUCCESS) break;

        if(pciErrReg->IsBitSet(PARITY_ERROR_BIT) &&
           !pciConfigReg->IsBitSet(PARITY_ERROR_MASK))
        {
            o_parityErr = true;
            break;
        }

        // Next check other chiplets

        // Always get a list here since this is the entry point
        GetProcPllErrRegList( i_chip, procPllErrRegList );

        P8DataBundle::ProcPllErrRegListIter itr = procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            rc = (*itr).errReg->Read();
            if (rc != SUCCESS) break;

            rc = (*itr).configReg->Read();
            if (rc != SUCCESS) break;

            if((*itr).errReg->IsBitSet(PARITY_ERROR_BIT) &&
               !(*itr).configReg->IsBitSet(PARITY_ERROR_MASK))
            {
                o_parityErr = true;
                break;
            }
        }

    } while(0);

    if( ! o_parityErr )
    {
        PRDF_ERR(PRDF_FUNC"no parity error found for proc: 0x%.8X",
                 i_chip->GetId());
    }

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X", i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}


/**
  * @brief Mask the PCB Slave internal parity error
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success
  */
int32_t MaskParityErr( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::MaskParityErr] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        // fence off proc osc error reg bits
        P8DataBundle * procdb = getDataBundle( i_chip );
        P8DataBundle::ProcPllErrRegList & procPllErrRegList =
            procdb->getProcPllErrRegList();

        if( procPllErrRegList.empty() )
        {
            GetProcPllErrRegList( i_chip, procPllErrRegList );
        }

        P8DataBundle::ProcPllErrRegListIter itr =
                                 procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            // Error is already fenced
            if( (*itr).configReg->IsBitSet(PARITY_ERROR_MASK) )
            {
                continue;
            }

            if( (*itr).errReg->IsBitSet(PARITY_ERROR_BIT) )
            {
                (*itr).configReg->SetBit(PARITY_ERROR_MASK);
                rc |= (*itr).configReg->Write();
            }
        }

        // fence off pci parity error
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
            i_chip->getRegister("PCI_ERROR_REG");
        SCAN_COMM_REGISTER_CLASS * pciConfigReg =
            i_chip->getRegister("PCI_CONFIG_REG");

        if(pciErrReg->IsBitSet(PARITY_ERROR_BIT) &&
           !pciConfigReg->IsBitSet(PARITY_ERROR_MASK))
        {
            pciConfigReg->SetBit(PARITY_ERROR_MASK);
            rc |= pciConfigReg->Write();
        }

        // Since TP_LFIR bit is the collection of all of the
        // pll error reg bits, we can't mask it or we will not
        // see any PLL errors reported from the error regs

    } // if not checkstop

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

#undef PRDF_FUNC
}

/**
 * @brief  Clear the Parity errors
 * @param  i_chip P8 chip
 * @param  i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t ClearParityErr( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & i_sc)
{
    #define PRDF_FUNC "[Proc::ClearParityErr] "

    int32_t rc = SUCCESS;

    if (CHECK_STOP != i_sc.service_data->GetAttentionType())
    {
        // Clear proc osc error reg bits
        P8DataBundle * procdb = getDataBundle( i_chip );
        P8DataBundle::ProcPllErrRegList & procPllErrRegList =
                           procdb->getProcPllErrRegList();
        if( procPllErrRegList.empty() )
        {
            GetProcPllErrRegList( i_chip, procPllErrRegList );
        }

        P8DataBundle::ProcPllErrRegListIter itr = procPllErrRegList.begin();
        for( ; itr != procPllErrRegList.end(); ++itr)
        {
            (*itr).errReg->ClearBit(PARITY_ERROR_BIT);
            rc |= (*itr).errReg->Write();
        }

        // Clear pci parity error
        SCAN_COMM_REGISTER_CLASS * pciErrReg =
                i_chip->getRegister("PCI_ERROR_REG");
        pciErrReg->ClearBit(PARITY_ERROR_BIT);
        rc |= pciErrReg->Write();

        // Clear TP_LFIR
        SCAN_COMM_REGISTER_CLASS * TP_LFIR =
                   i_chip->getRegister("TP_LFIR_AND");
        TP_LFIR->setAllBits();
        // Parity error also feeds into this LFIR
        TP_LFIR->ClearBit(PLL_DETECT_P8);
        rc |= TP_LFIR->Write();
    }

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X",
                 i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}


/**
  * @brief   analyze PCB Slave internal parity errors
  * @param   i_chip P8 chip
  * @param   io_sc  service data collector
  * @returns Failure or Success
  */
int32_t AnalyzeParityErr( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Proc::AnalyzeParityErr] "

    int32_t rc = SUCCESS;
    bool found = false;

    do
    {
        rc = CheckParityErr(i_chip, found, io_sc);
        if (rc != SUCCESS) break;

        if(found)
        {
            if(io_sc.service_data->IsAtThreshold())
            {
                MaskParityErr( i_chip, io_sc );
            }

            ClearParityErr( i_chip, io_sc );
        }

    } while(0);

    // clear the PLL Err Reg list
    P8DataBundle * procdb = getDataBundle( i_chip );
    P8DataBundle::ProcPllErrRegList & procPllErrRegList =
                        procdb->getProcPllErrRegList();
    procPllErrRegList.clear();

    if( rc != SUCCESS )
    {
        PRDF_ERR(PRDF_FUNC"failed for proc: 0x%.8X", i_chip->GetId());
    }

    return rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, AnalyzeParityErr );

/**
 * @brief  There are some FIR bits that will be cleared manually and must not be
 *         cleared by the framework code. The plugin forces the rule code to
 *         analyze a special copy of the FIR which will not automatically clear
 *         the FIR bits at attention.
 * @param  i_chip P8 chip.
 * @param  i_sc   The step code data struct.
 * @return PRD_NO_CLEAR_FIR_BITS always.
 */
int32_t NoClearFirBits( ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc )
{
    return PRD_NO_CLEAR_FIR_BITS;
}
PRDF_PLUGIN_DEFINE( Proc, NoClearFirBits );


} // end namespace Proc

} // end namespace PRDF
