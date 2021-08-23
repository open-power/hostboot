/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfOcmbAddrConfig.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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


#ifndef __prdfOcmbAddrConfig_H
#define __prdfOcmbAddrConfig_H

/** @file  prdfOcmbAddrConfig.H
 *  @brief Contains the OcmbAddrConfig object used for storing address
 *         configuration information that will be needed for dynamic memory
 *         deallocation.
 */

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief Ocmb Address Configuration. */
class OcmbAddrConfig
{
  public: // functions

    /** @brief Default constructor. */
    OcmbAddrConfig( ExtensibleChip * i_ocmb ) : iv_ocmb(i_ocmb),
        iv_addr_trans0(64), iv_addr_trans1(64), iv_addr_trans2(64)
    {}

    /**
     * @brief Returns the data stored in iv_mc_addr_trans0, reads from the
     *        MC_ADDR_TRANS register to update if the data is 0.
     * @param o_addr_trans0 The data returned from iv_addr_trans0
     * @return Non-SUCCESS if the scom to the reg fails, SUCCESS otherwise
     */
    uint32_t getMcAddrTrans0( BitStringBuffer & o_addr_trans0 );

    /**
     * @brief Returns the data stored in iv_mc_addr_trans1, reads from the
     *        MC_ADDR_TRANS1 register to update if the data is 0.
     * @param o_addr_trans1 The data returned from iv_addr_trans1
     * @return Non-SUCCESS if the scom to the reg fails, SUCCESS otherwise
     */
    uint32_t getMcAddrTrans1( BitStringBuffer & o_addr_trans1 );

    /**
     * @brief Returns the data stored in iv_mc_addr_trans2, reads from the
     *        MC_ADDR_TRANS2 register to update if the data is 0.
     * @param o_addr_trans2 The data returned from iv_addr_trans2
     * @return Non-SUCCESS if the scom to the reg fails, SUCCESS otherwise
     */
    uint32_t getMcAddrTrans2( BitStringBuffer & o_addr_trans2 );

    /** @brief Returns whether the column3 address bit is valid or not depending
     *         on bit 56 of the MCBCFG register. If the scom fails to the
     *         MCBCFG register, it will assume column3 is not valid.
     * @return True if MCBCFG[56] is set, false if not or the scom fails.
     */
    bool getCol3Valid();

  private: // instance variables

    // The OCMB chip associated with the data stored in this class
    ExtensibleChip * iv_ocmb;

    // These variables will be used to store the information within the
    // MC_ADDR_TRANS registers which will be needed for address translation
    // during dynamic memory deallocation. Information is stored within an
    // object within PRD since certain errors (notably a double PMIC fail) can
    // cause us to lose access to the OCMB, but we still need to perform
    // dynamic memory deallocation on that OCMB.
    BitStringBuffer iv_addr_trans0;
    BitStringBuffer iv_addr_trans1;
    BitStringBuffer iv_addr_trans2;
};

} // end namespace PRDF

#endif // __prdfOcmbAddrConfig_H

