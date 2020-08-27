/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10Iohs.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>

#include <prdfPlatServices.H>
#include <prdfP10IohsExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_iohs
{

/**
 * @brief  Calls out an entire SMPGROUP bus with the given IOHS link.
 * @param  i_chip IOHS processor unit.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS always.
 */
int32_t __smp_callout(ExtensibleChip* i_chip, unsigned int i_link,
                      STEP_CODE_DATA_STRUCT& io_sc)
{
    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_IOHS == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_IOHS);

    // SMP callouts need to determine if the link is down. This can be done by
    // querying the link quality status register. A zero value indicates the
    // link has failed.

    // TODO: Uncomment once below is supported.
    //HWAS::CalloutFlag_t calloutFlag = HWAS::FLAG_NONE;

    const char* reg_str = (0 == i_link) ? "IOHS_DLP_LINK0_QUALITY"
                                        : "IOHS_DLP_LINK1_QUALITY";
    SCAN_COMM_REGISTER_CLASS* reg = i_chip->getRegister(reg_str);
    if (SUCCESS == reg->Read() && reg->BitStringIsZero())
    {
        // TODO: Uncomment once below is supported.
        //calloutFlag = HWAS::FLAG_LINK_DOWN;

        // Indicate in the multi-signature section that the link has failed.
        io_sc.service_data->AddSignatureList(i_chip->getTrgt(),
                                             PRDFSIG_LinkFailed);

        // Make the error log predictive.
        io_sc.service_data->setPredictive();
    }

    // TODO: Remove once below is supported.
    io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED, NO_GARD);
/* TODO: RTC 259316 - See action items below.
    // Get the connected SMPGROUP target.
    // TODO: Need to add the following to the connMap map in getConnectedChild()
    //       so we can get an SMPGROUP from an IOHS.
    //          { {TYPE_IOHS, TYPE_SMPGROUP}, MAX_LINK_PER_IOHS },
    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_SMPGROUP,
                                              i_link);
    PRDF_ASSERT(nullptr != rxTrgt);

    // Get the peer SMPGROUP target.
    // TODO: Need to update getConnectedPeerTarget() to allow SMPGROUP targets.
    TargetHandle_t txTrgt = getConnectedPeerTarget(rxTrgt);
    PRDF_ASSERT(nullptr != txTrgt);

    // Callout the entire bus interface.
    // TODO: What type should we use for IOHS? Do we need differentiate between
    //       X or A link types or can we use a generic new IOHS type?
    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::???, calloutFlag);
*/

    return SUCCESS;
}

int32_t smp_callout_l0(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return __smp_callout(i_chip, 0, io_sc);
}
PRDF_PLUGIN_DEFINE(p10_iohs, smp_callout_l0);

int32_t smp_callout_l1(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return __smp_callout(i_chip, 1, io_sc);
}
PRDF_PLUGIN_DEFINE(p10_iohs, smp_callout_l1);

/**
 * @brief  Additional handling for SMP link failures.
 * @param  i_chip IOHS processor unit.
 * @param  i_link IOHS link.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS always.
 */
int32_t __smp_failure(ExtensibleChip* i_chip, unsigned int i_link,
                      STEP_CODE_DATA_STRUCT& io_sc)
{
    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_IOHS == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_IOHS);

    // Clear all side effect attentions due to the link failure.
    SCAN_COMM_REGISTER_CLASS* reg = i_chip->getRegister("IOHS_DLP_FIR_AND");
    reg->setAllBits();

    reg->ClearBit( 6 + i_link); // crc error
    reg->ClearBit( 8 + i_link); // nak received
    reg->ClearBit(14 + i_link); // sl ecc ce
    reg->ClearBit(16 + i_link); // sl ecc ue
    reg->ClearBit(42 + i_link); // no spare lane available
    reg->ClearBit(44 + i_link); // spare done
    reg->ClearBit(46 + i_link); // too many crc errors
    reg->ClearBit(56 + i_link); // training failure
    reg->ClearBit(58 + i_link); // unrecoverable error

    reg->Write();

    return SUCCESS;
}

int32_t smp_failure_l0(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return __smp_failure(i_chip, 0, io_sc);
}
PRDF_PLUGIN_DEFINE(p10_iohs, smp_failure_l0);

int32_t smp_failure_l1(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return __smp_failure(i_chip, 1, io_sc);
}
PRDF_PLUGIN_DEFINE(p10_iohs, smp_failure_l1);

} // namespace p10_iohs

} // namespace PRDF

