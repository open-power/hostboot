/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPegasusConfigurator.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef prdfPegasusConfigurator_H
#define prdfPegasusConfigurator_H

/** @file  prdfPegasusConfigurator.H
 *  @brief Builds the PRD system model for Pegasus (P8 based systems).
 */

#include <iipConfigurator.h>
#include <iipCallAttnResolution.h> // For CallAttnResolution
#include <prdfPllDomain.H>

namespace PRDF
{

class RuleChipDomain;
typedef std::vector< PllDomain  *> PllDomainList;
typedef std::vector< CHIP_CLASS *> PllChipList;
/** @brief PRD configurator for Pegasus (P8 systems) */
class PegasusConfigurator : public Configurator
{
  public:

    /**
     * @brief Constructor
     */
    PegasusConfigurator() :
        Configurator( RuleChipDomain::TOTAL_CHIPS,
                      RuleChipDomain::TOTAL_DOMAINS )
    {}

    /**
     * @brief Destructor
     * @note  This configurator does not delete the objects it created during
     *        build(); that is the responsibility of the system object.
     */
    ~PegasusConfigurator() {}

    /**
     * @brief  Create the PRD system object, all chip instances, and all domain
     *         instances.
     * @return error log handle
     * @note   The caller of this function owns the responsiblity of deleting
     *         the system object created.
     */
    virtual errlHndl_t   build();

  private: // functions

    /** @brief Copy not allowed. */
    PegasusConfigurator( const PegasusConfigurator & right );

    /** @brief Assignment not allowed. */
    const PegasusConfigurator & operator=( const PegasusConfigurator & right );

    /**
     * @brief Will add all chips of a given type to a domain.
     * @parm    i_type    The specified target type.
     * @parm    io_domain The associated domain.
     * @parm    io_pllDomains The associated PLL domain (optional for some)
     * @return  error log handle
     */
    errlHndl_t addDomainChips( TARGETING::TYPE  i_type,
                            RuleChipDomain * io_domain,
                            PllDomainList  * io_pllDomains = NULL );

    /**
     *  @brief  Add chip to its Pll Domain.
     *  @param i_domainId          - Domain Id (CLOCK_DOMAIN_FAB/_MEMBUF)
     *  @param i_fabricPllDomains  - List of Pll Domains
     *  @param i_chip              - Pointer to chip.
     *  @param i_pTarget           - chip target.
     *  @param i_scanFac           - Scan Facility.
     *  @param i_resFac            - Resolution Factory.
     */
    void addChipsToPllDomain(
         DOMAIN_ID                    i_domainId,
         PllDomainList              * io_fabricPllDomains,
         RuleChip                   * i_chip,
         TARGETING::TargetHandle_t    i_pTarget,
         ScanFacility               & i_scanFac,
         ResolutionFactory          & i_resFac);

  /**
   *  @brief Add Pll Domains to the System.
   *  @param i_fabricPllDomains  - List of Fabric Pll Domains
   *  @param i_membPllDomains    - List of Membuf Pll Domains
   */
  void addPllDomainsToSystem(
        PllDomainList  & i_fabricPllDomains,
        PllDomainList  & i_membPllDomains );

  private: // data

    static CallAttnResolution noAttnResolution;
};

} // end namespace PRDF

#endif
