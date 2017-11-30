/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9Mcbist.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/** @file  prdfP9Mcbist.C
 *  @brief Contains plugin code for MCBIST on Hostboot (IPL and runtime).
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfPlatServices.H>
#include <prdfP9McbistDataBundle.H>
#include <prdfP9McbistExtraSig.H>
#include <prdfMemScrubUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p9_mcbist
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_mcbChip An MCBIST chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mcbChip )
{
    i_mcbChip->getDataBundle() = new McbistDataBundle( i_mcbChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p9_mcbist, Initialize );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mcbChip An MCBIST chip.
 * @param  io_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mcbChip,
                      STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mcbist::PostAnalysis] "


    #ifdef __HOSTBOOT_RUNTIME

    // Maintenance IUEs in mnfg mode do not use MCAECCFIR[37], instead we stop
    // background scrub on RCE ETEs with a threshold of 1 and the IUE is handled
    // via command complete attention. Similar to our normal IUE handling, we
    // want to trigger a port fail after the error log has been committed. See
    // the comments in PostAnalysis in prdfP9Mca.C for a full explanation of why
    // we trigger the port fail here

    // if in mnfg mode
    if ( mfgMode() )
    {
        ExtensibleChipList mcaList = getConnected( i_mcbChip, TYPE_MCA );
        // loop through all MCAs
        for ( auto & mca : mcaList )
        {
            uint32_t l_rc = SUCCESS;
            uint32_t eccAttns;
            l_rc = checkEccFirs<TYPE_MCA>( mca, eccAttns );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEccFirs<T>(0x%08x) failed",
                          mca->getHuid() );
                break;
            }

            // if there's an IUE and we've reached threshold trigger a port fail
            if ( (eccAttns & MAINT_IUE) &&
                 MemEcc::queryIueTh<TYPE_MCA>(mca, io_sc) )
            {
                if ( SUCCESS != MemEcc::triggerPortFail<TYPE_MCA>(mca) )
                {
                    PRDF_ERR( PRDF_FUNC "triggerPortFail(0x%08x) failed",
                              mca->getHuid() );
                }
            }
        }
    }

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mcbist, PostAnalysis );

//##############################################################################
//
//                                 MCBISTFIR
//
//##############################################################################

/**
 * @brief  MCBIST[10] - MCBIST Command Complete.
 * @param  i_mcbChip An MCBIST chip.
 * @param  io_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t McbistCmdComplete( ExtensibleChip * i_mcbChip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mcbist::McbistCmdComplete] "

    // Tell the TD controller there was a command complete attention.
    McbistDataBundle * db = getMcbistDataBundle( i_mcbChip );
    if ( SUCCESS != db->getTdCtlr()->handleCmdComplete(io_sc) )
    {
        // Something failed. It is possible the command complete attention has
        // not been cleared. Make the rule code do it.
        return SUCCESS;
    }
    else
    {
        // Everything was successful. Whether we started a new command or told
        // MDIA to do it, the command complete bit has already been cleared.
        // Don't do it again.
        return PRD_NO_CLEAR_FIR_BITS;
    }

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mcbist, McbistCmdComplete );

/**
 * @brief  MCBIST[12] - MCBIST Command Complete Nimbus DD1.0 workaround.
 * @param  i_mcbChip An MCBIST chip.
 * @param  io_sc     The step code data struct.
 * @return SUCCESS or PRD_NO_CLEAR_FIR_BITS
 */
int32_t CmdCompleteDd1Workaround( ExtensibleChip * i_mcbChip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mcbist::CmdCompleteDd1Workaround] "

    int32_t o_rc = SUCCESS; // Returned to rule code.

    #ifndef __HOSTBOOT_RUNTIME

    TargetHandle_t mcbTrgt = i_mcbChip->getTrgt();

    // This workaround should only be seen during super fast MCBIST commands,
    // which are only run during Memory Diagnostics. Also, the workaround only
    // applies to P9 Nimbus DD1.0.
    PRDF_ASSERT( isInMdiaMode() );
    PRDF_ASSERT( (MODEL_NIMBUS == getChipModel(mcbTrgt)) &&
                 (0x10         == getChipLevel(mcbTrgt)) );

    int32_t l_rc = SUCCESS; // For local rc handling.

    SCAN_COMM_REGISTER_CLASS * mcbmcat = i_mcbChip->getRegister("MCBMCAT");

    do
    {
        //read MCBMCAT from cache first then from HW
        l_rc = mcbmcat->Read();
        if (SUCCESS != l_rc)
        {
            PRDF_ERR(PRDF_FUNC "Read() failed on MCBMCAT");
            break;
        }
        uint64_t tmp1 = mcbmcat->GetBitFieldJustified(0, 64);

        l_rc = mcbmcat->ForceRead();
        if (SUCCESS != l_rc)
        {
            PRDF_ERR(PRDF_FUNC "ForceRead() failed on MCBMCAT");
            break;
        }
        uint64_t tmp2 = mcbmcat->GetBitFieldJustified(0, 64);

        //compare the two values to determine if the command is completed

        //if the values are the same the command has completed
        if (tmp1 == tmp2)
        {
            // This plugin is only called when MCBISTFIR[12] is on by itself,
            // however, there is a small window where MCBISTFIR[10] could be set
            // after the initial register capture, but before this point in the
            // code. So clear MCBISTFIR[10] just in case. Also, do this before
            // handling the command complete attention to ease complication in
            // error path handling.
            SCAN_COMM_REGISTER_CLASS * mcbFirAnd =
                i_mcbChip->getRegister("MCBISTFIR_AND");
            mcbFirAnd->setAllBits();

            mcbFirAnd->ClearBit(10);

            l_rc = mcbFirAnd->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR" );
                break;
            }

            //handle like a normal command complete
            o_rc = McbistCmdComplete( i_mcbChip, io_sc );
        }
        //if the values are different the command has not completed yet
        else
        {
            //sleep for a bit - hopefully will be enough for the cmd to complete
            PlatServices::milliSleep(0, 20);

            //do not commit the errl - it won't have useful data
            io_sc.service_data->setDontCommitErrl();

            //return PRD_NO_CLEAR_FIR_BITS so PRD is called again
            o_rc = PRD_NO_CLEAR_FIR_BITS;
        }

    } while(0);

    // There is some error path handling that needs to be done if there is a
    // local error.
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed on 0x%08x", i_mcbChip->getHuid() );

        // Change signature indicating there was an error in analysis.
        io_sc.service_data->SetErrorSig( PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH );
        io_sc.service_data->setServiceCall();

        // Tell MDIA to skip further analysis on this target.
        l_rc = mdiaSendEventMsg( mcbTrgt, MDIA::STOP_TESTING );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
    }

    #endif // not __HOSTBOOT_RUNTIME

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mcbist, CmdCompleteDd1Workaround );

//------------------------------------------------------------------------------

/**
 * @brief  MCBISTFIR[1] - COMMAND_ADDRESS_TIMEOUT.
 * @param  i_chip An MCBIST chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t commandAddrTimeout( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mcbist::commandAddrTimeout] "

    // The current MCBIST command is hung and will not complete. All conditions
    // that would cause this are contained within the MCAs in which the command
    // was executed. Restarting the command will likely fail with the same
    // issue. Callout and gard all MCAs in which the command was executed.

    std::vector<ExtensibleChip *> mcaList;

    if ( SUCCESS != getMcbistMaintPort(i_chip, mcaList) )
    {
        PRDF_ERR( PRDF_FUNC "getMcbistMaintPort(0x%08x) failed",
                  i_chip->getHuid() );
    }
    else
    {
        for ( auto & mcaChip : mcaList )
        {
            io_sc.service_data->SetCallout( mcaChip->getTrgt() );
        }
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mcbist, commandAddrTimeout );

//------------------------------------------------------------------------------

} // end namespace p9_mcbist

} // end namespace PRDF

