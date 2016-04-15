/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Configurator.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <prdfPlatConfigurator.H>

#include <iipDomainContainer.h>
#include <iipResolutionFactory.h>
#include <iipSystem.h>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfRuleFiles.H>
#include <prdfRuleChip.H>
#include <prdfScanFacility.H>
#include <prdrLoadChipCache.H>  // To flush chip-file cache.

#include <prdfP9CappDomain.H>
#include <prdfP9EcDomain.H>
#include <prdfP9EqDomain.H>
#include <prdfP9ExDomain.H>
#include <prdfP9McaDomain.H>
#include <prdfP9McbistDomain.H>
#include <prdfP9McsDomain.H>
#include <prdfP9ObusDomain.H>
#include <prdfP9PecDomain.H>
#include <prdfP9PhbDomain.H>
#include <prdfP9ProcDomain.H>
#include <prdfP9XbusDomain.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

// Resolution for no chips at attention.
CallAttnResolution PlatConfigurator::cv_noAttnResolution;

//------------------------------------------------------------------------------

errlHndl_t PlatConfigurator::build()
{
    PRDF_ENTER( "PlatConfigurator::build()" );

    errlHndl_t errl = NULL;

    // Create System object to populate with domains.
    systemPtr = new System(cv_noAttnResolution);

    // Create domains.
    ProcDomain   * procDomain   = new ProcDomain(   PROC_DOMAIN   );
    EqDomain     * eqDomain     = new EqDomain(     EQ_DOMAIN     );
    ExDomain     * exDomain     = new ExDomain(     EX_DOMAIN     );
    EcDomain     * ecDomain     = new EcDomain(     EC_DOMAIN     );
    CappDomain   * cappDomain   = new CappDomain(   CAPP_DOMAIN   );
    PecDomain    * pecDomain    = new PecDomain(    PEC_DOMAIN    );
    PhbDomain    * phbDomain    = new PhbDomain(    PHB_DOMAIN    );
    XbusDomain   * xbusDomain   = new XbusDomain(   XBUS_DOMAIN   );
    ObusDomain   * obusDomain   = new ObusDomain(   OBUS_DOMAIN   );
    McbistDomain * mcbistDomain = new McbistDomain( MCBIST_DOMAIN );
    McsDomain    * mcsDomain    = new McsDomain(    MCS_DOMAIN    );
    McaDomain    * mcaDomain    = new McaDomain(    MCA_DOMAIN    );

    PllDomainMapList pllDmnMapLst;

    do
    {
        // First, add all chips to the domains.
        // NOTE: Order is important so that the PLL domains are added in the
        //       correct order.
        // NOTE: We should ensure that if build fails midway, deleting System
        //       should be enough to clean up the partial model.

        errl = addDomainChips( TYPE_PROC,   procDomain,   pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_EQ,     eqDomain,     pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_EX,     exDomain,     pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_CORE,   ecDomain,     pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_CAPP,   cappDomain,   pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_PEC,    pecDomain,    pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_PHB,    phbDomain,    pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_XBUS,   xbusDomain,   pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_OBUS,   obusDomain,   pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MCBIST, mcbistDomain, pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MCS,    mcsDomain,    pllDmnMapLst );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MCA,    mcaDomain,    pllDmnMapLst );
        if ( NULL != errl ) break;

    } while (0);

    // Now, add the domains to system.
    // NOTE: Order is important because this is the order that the domains will
    //       be analyzed.
    // Note: We are adding these domains to system regardless if there was a
    //       failure. We are doing it simply because we want to clean up the
    //       partial object model by simply deleting the system. If we add
    //       domain to system with or without chips (error scenario), we can do
    //       the clean up quite easily.

    // PLL domains are always first.
    addPllDomainsToSystem( pllDmnMapLst );

    // Memory chip domains are always second.
    // TODO: RTC 144056 Cumulus/Centaur systems.

    // Processor chip domains are always third.
    sysDmnLst.push_back( procDomain );

    // ATTN only calls PRD with a list of chips. For performance improvements
    // during System::Analyze() add all chiplet domains after the chip domains.
    // Note that order of the chiplet domains does not matter because analysis
    // originates from the chip domains above.
    sysDmnLst.push_back( eqDomain     );
    sysDmnLst.push_back( exDomain     );
    sysDmnLst.push_back( ecDomain     );
    sysDmnLst.push_back( cappDomain   );
    sysDmnLst.push_back( pecDomain    );
    sysDmnLst.push_back( phbDomain    );
    sysDmnLst.push_back( xbusDomain   );
    sysDmnLst.push_back( obusDomain   );
    sysDmnLst.push_back( mcbistDomain );
    sysDmnLst.push_back( mcsDomain    );
    sysDmnLst.push_back( mcaDomain    );

    // Add chips to the system.
    Configurator::chipList & chips = getChipList();
    systemPtr->AddChips( chips.begin(), chips.end() );

    // Add domains to the system.
    Configurator::domainList & domains = getDomainList();
    systemPtr->AddDomains( domains.begin(), domains.end() );

    #ifdef FLYWEIGHT_PROFILING

    ScanFacility & scanFac = ScanFacility::Access();
    PRDF_TRAC( "printing flyweight register and resolution objects ");
    scanFac.printStats();
    PRDF_TRAC("total chips in the system %d ",chips.size());
    ResolutionFactory & resol = ResolutionFactory::Access( );
    resol.printStats();

    #endif // FLYWEIGHT_PROFILING

    // The underlying list of chips and domains will not be cleaned up until
    // the configurator goes out of scope at the end of PRDF::initialize().
    // It was observed that clearing these lists here will greatly reduced
    // the peak memory usage for the duration of the PRDF::initialize()
    // function.
    chips.clear();
    domains.clear();

    if ( NULL != errl )
    {
        PRDF_ERR( "PlatConfigurator::build() failed to build object model" );
    }

    PRDF_EXIT( "PlatConfigurator::build()" );

    return errl;
}

//------------------------------------------------------------------------------

errlHndl_t PlatConfigurator::addDomainChips( TARGETING::TYPE i_type,
                                             RuleChipDomain * io_domain,
                                             PllDomainMapList & io_pllDmnLst )
{
    errlHndl_t l_errl = NULL;

    // Get references to factory objects.
    ScanFacility      & scanFac = ScanFacility::Access();
    ResolutionFactory & resFac  = ResolutionFactory::Access();

    // Get all targets of specified type and add to given domain.
    TargetHandleList trgtList = getFunctionalTargetList( i_type );

    if ( 0 == trgtList.size() )
    {
        PRDF_ERR( "[addDomainChips] getFunctionalTargetList() "
                  "returned empty list for i_type=%d", i_type );
    }
    else
    {
        // Get rule filename based on type.
        const char * fileName = "";
        switch ( i_type )
        {
            case TYPE_PROC:   fileName = p9_nimbus; break;
            case TYPE_EQ:     fileName = p9_eq;     break;
            case TYPE_EX:     fileName = p9_ex;     break;
            case TYPE_CORE:   fileName = p9_ec;     break;
            case TYPE_CAPP:   fileName = p9_capp;   break;
            case TYPE_PEC:    fileName = p9_pec;    break;
            case TYPE_PHB:    fileName = p9_phb;    break;
            case TYPE_XBUS:   fileName = p9_xbus;   break;
            case TYPE_OBUS:   fileName = p9_obus;   break;
            case TYPE_MCBIST: fileName = p9_mcbist; break;
            case TYPE_MCS:    fileName = p9_mcs;    break;
            case TYPE_MCA:    fileName = p9_mca;    break;

            default:
                // Print a trace statement, but do not fail the build.
                PRDF_ERR( "[addDomainChips] Unsupported target type: %d",
                          i_type );
        }

        // Generic empty PLL domain maps, if they are used.
        PllDomainMap pllDmnMap1, pllDmnMap2;

        // Add each chip to the chip domain.
        for ( const auto & trgt : trgtList )
        {
            if ( NULL == trgt ) continue;

            RuleChip * chip = new RuleChip( fileName, trgt,
                                            scanFac, resFac, l_errl );
            if ( NULL != l_errl )
            {
                delete chip;
                break;
            }

            sysChipLst.push_back( chip );
            io_domain->AddChip(   chip );

            // PLL domains
            switch ( i_type )
            {
                case TYPE_PROC:
                    addChipToPllDomain( CLOCK_DOMAIN_FAB, pllDmnMap1,
                                        chip, trgt, TYPE_PROC,
                                        scanFac, resFac );
                    addChipToPllDomain( CLOCK_DOMAIN_IO,  pllDmnMap2,
                                        chip, trgt, TYPE_PCI,
                                        scanFac, resFac );
                    break;

                case TYPE_MEMBUF:
                    addChipToPllDomain( CLOCK_DOMAIN_MEMBUF, pllDmnMap1,
                                        chip, trgt, TYPE_MEMBUF,
                                        scanFac, resFac );
                    break;

                default: ;
            }
        }

        // Add the PLL domain maps to the PLL domain map list.
        if ( !pllDmnMap1.empty() ) io_pllDmnLst.push_back( pllDmnMap1 );
        if ( !pllDmnMap2.empty() ) io_pllDmnLst.push_back( pllDmnMap2 );

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();
    }

    return l_errl;
}

//------------------------------------------------------------------------------

void PlatConfigurator::addChipToPllDomain( DOMAIN_ID i_domainId,
                                           PllDomainMap & io_pllDmnMap,
                                           RuleChip * i_chip,
                                           TARGETING::TargetHandle_t i_trgt,
                                           TARGETING::TYPE i_type,
                                           ScanFacility & i_scanFac,
                                           ResolutionFactory & i_resFac )
{
    // PROC PLL - only one per node as all fabs on node have same clock source.
    uint32_t node = getNodePosition( i_trgt );

    if ( io_pllDmnMap.end() == io_pllDmnMap.find(node) )
    {
        Resolution & clock = i_resFac.GetClockResolution( i_trgt, i_type );

        #ifdef __HOSTBOOT_MODULE
        io_pllDmnMap[node] = new PllDomain( i_domainId, clock,
                                        ThresholdResolution::cv_mnfgDefault );
        #else
        io_pllDmnMap[node] = new PllDomain( i_domainId, clock, CONTENT_HW,
                                        ThresholdResolution::cv_mnfgDefault );
        #endif
    }

    io_pllDmnMap[node]->AddChip( i_chip );
}

//------------------------------------------------------------------------------

void PlatConfigurator::addPllDomainsToSystem( const PllDomainMapList & i_list )
{
    for ( PllDomainMapList::const_iterator lit = i_list.begin();
          lit != i_list.end(); ++lit )
    {
        for ( PllDomainMap::const_iterator mit = lit->begin();
              mit != lit->begin(); ++mit )
        {
            sysDmnLst.push_back( mit->second );
        }
    }
}

} // end namespace PRDF
