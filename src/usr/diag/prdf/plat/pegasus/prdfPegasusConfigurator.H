/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPegasusConfigurator.H $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef prdfPegasusConfigurator_H
#define prdfPegasusConfigurator_H

/** @file  prdfPegasusConfigurator.H
 *  @brief Builds the PRD system model for Pegasus (P8 based systems).
 */

#include <iipConfigurator.h>
#include <iipCallAttnResolution.h> // For CallAttnResolution
#include <prdfRuleChipDomain.H>

/** @brief PRD configurator for Pegasus (P8 systems) */
class PrdfPegasusConfigurator : public Configurator
{
  public:

    /**
     * @brief Constructor
     */
    PrdfPegasusConfigurator() :
        Configurator( PrdfRuleChipDomain::TOTAL_CHIPS,
                      PrdfRuleChipDomain::TOTAL_DOMAINS )
    {}

    /**
     * @brief Destructor
     * @note  This configurator does not delete the objects it created during
     *        build(); that is the responsibility of the system object.
     */
    ~PrdfPegasusConfigurator() {}

    /**
     * @brief  Create the PRD system object, all chip instances, and all domain
     *         instances.
     * @return Pointer to configured system.
     * @note   The caller of this function owns the responsiblity of deleting
     *         the system object created.
     */
    virtual System * build();

  private: // functions

    /** @brief Copy not allowed. */
    PrdfPegasusConfigurator( const PrdfPegasusConfigurator & right );

    /** @brief Assignment not allowed. */
    const PrdfPegasusConfigurator & operator=( const PrdfPegasusConfigurator & right );

    /**
     * @brief Will add all chips of a given type to a domain.
     * @parm  i_type    The specified target type.
     * @parm  io_domain The associated domain.
     */
    void addDomainChips( TARGETING::TYPE i_type,
                         PrdfRuleChipDomain * io_domain );

  private: // data

    static CallAttnResolution noAttnResolution;

};

#endif
