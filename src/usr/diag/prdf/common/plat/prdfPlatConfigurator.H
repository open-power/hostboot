/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatConfigurator.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __prdfPlatConfigurator_H
#define __prdfPlatConfigurator_H

/** @file  prdfPlatConfigurator.H
 *  @brief Builds the PRD system model.
 */

#include <vector>
#include <map>

#include <iipConfigurator.h>
#include <iipCallAttnResolution.h> // For CallAttnResolution
#include <prdfPllDomain.H>
#include <prdfRuleChipDomain.H>

namespace PRDF
{

/** @brief PRD configurator */
class PlatConfigurator : public Configurator
{
  public:

    /**
     * @brief Constructor
     */
    PlatConfigurator() :
        Configurator( RuleChipDomain::TOTAL_CHIPS,
                      RuleChipDomain::TOTAL_DOMAINS )
    {}

    /**
     * @brief Destructor
     * @note  This configurator does not delete the objects it created during
     *        build(); that is the responsibility of the system object.
     */
    ~PlatConfigurator() {}

    /**
     * @brief  Create the PRD system object, all chip instances, and all domain
     *         instances.
     * @return error log handle
     * @note   The caller of this function owns the responsibility of deleting
     *         the system object created.
     */
    virtual errlHndl_t build();

  private: // data

    typedef std::map<uint32_t, PllDomain *> PllDomainMap;
    typedef std::vector<PllDomainMap> PllDomainMapList;

  private: // functions

    /** @brief Copy not allowed. */
    PlatConfigurator( const PlatConfigurator & right );

    /** @brief Assignment not allowed. */
    const PlatConfigurator & operator=( const PlatConfigurator & right );

    /**
     * @brief  Adds all chips of a given target type to a domain.
     * @parm   i_type       The specified target type.
     * @parm   io_domain    The associated domain.
     * @parm   io_pllDmnLst The PLL domain map list.
     * @return An error log on error, otherwise nullptr.
     */
    errlHndl_t addDomainChips( TARGETING::TYPE  i_type,
                               RuleChipDomain * io_domain,
                               PllDomainMapList & io_pllDmnLst );

    /**
     * @brief Adds a chip to its Pll Domain.
     * @param i_domainId   PLL Domain ID (CLOCK_DOMAIN_FAB/_MEMBUF)
     * @param io_pllDmnMap PLL domain map for this clock type.
     * @param i_chip       Chip to add.
     * @param i_trgt       Chip's target handle.
     * @param i_type       Clock type.
     * @param i_scanFac    Scan Facility.
     * @param i_resFac     Resolution Factory.
     */
    void addChipToPllDomain( DOMAIN_ID                   i_domainId,
                             PllDomainMap              & io_pllDmnMap,
                             RuleChip                  * i_chip,
                             TARGETING::TargetHandle_t   i_trgt,
                             TARGETING::TYPE             i_type,
                             ScanFacility              & i_scanFac,
                             ResolutionFactory         & i_resFac );

    /**
     *  @brief Add PLL all of the PLL domains to System.
     *  @param i_list List of PLL domain maps to add to System.
     */
    void addPllDomainsToSystem( const PllDomainMapList & i_list );

  private: // data

    static CallAttnResolution cv_noAttnResolution;
};

} // end namespace PRDF

#endif
