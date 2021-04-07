/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10Iohs.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include <fapi2.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_iohs
{

int32_t smp_callout_l0(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return smp_callout(i_chip, io_sc, 0);
}
PRDF_PLUGIN_DEFINE(p10_iohs, smp_callout_l0);

int32_t smp_callout_l1(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    return smp_callout(i_chip, io_sc, 1);
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

