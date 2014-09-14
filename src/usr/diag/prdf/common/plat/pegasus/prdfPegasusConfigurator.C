/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPegasusConfigurator.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

#include <prdfGlobal.H>
#include <prdfPegasusConfigurator.H>
#include <prdfRuleFiles.H>

#include <prdfRuleChip.H>
#include <iipDomainContainer.h>
#include <prdfScanFacility.H>
#include <iipResolutionFactory.h>

#include <prdfFabricDomain.H>
#include <prdfExDomain.H>
#include <prdfMcsDomain.H>
#include <prdfMembufDomain.H>
#include <prdfMbaDomain.H>
#include <prdfPlatServices.H>
#include <iipSystem.h>
#include <prdrLoadChipCache.H>  // To flush chip-file cache.

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

// Resolution for no chips at attention.
CallAttnResolution PegasusConfigurator::noAttnResolution;

//------------------------------------------------------------------------------
// Local Helper functions

/**
 * @brief Return max number of nodes in the system
 *        Note that Hostboot only has node view.
 * @return max number of nodes
 *         always return 1 in Hostboot
 */
uint32_t _getMaxNumNodes()
{
    #ifdef __HOSTBOOT_MODULE
        return 1; // only one node in Hostboot
    #else
        return MAX_NODE_PER_SYS;
    #endif
}

/**
 * @brief   Returns the position of a node in which the given target is
 *          contained.
 * @param   i_target Any target.
 * @return  The position of the connected node.
 *          Hostboot only has node view so it always returns 0.
 */
uint32_t _getNodePosition( TARGETING::TargetHandle_t i_pTarget )
{
    using namespace TARGETING;

    uint32_t o_pos = 0;

    #ifndef __HOSTBOOT_MODULE

    o_pos = PlatServices::getNodePosition(i_pTarget);

    #endif

    return o_pos;
}

//------------------------------------------------------------------------------

errlHndl_t PegasusConfigurator::build()
{
    using namespace TARGETING;

    PRDF_ENTER( "PegasusConfigurator::build()" );

    errlHndl_t errl = NULL;

    // Create System object to populate with domains.
    systemPtr = new System(noAttnResolution);

    // Create domains.
    FabricDomain * l_procDomain   = new FabricDomain( FABRIC_DOMAIN );
    ExDomain     * l_exDomain     = new ExDomain(     EX_DOMAIN     );
    McsDomain    * l_mcsDomain    = new McsDomain(    MCS_DOMAIN    );
    MembufDomain * l_membufDomain = new MembufDomain( MEMBUF_DOMAIN );
    MbaDomain    * l_mbaDomain    = new MbaDomain(    MBA_DOMAIN    );

    uint32_t l_maxNodeCount = _getMaxNumNodes();
    // PLL domains
    PllDomainList l_fabricPllDomains(l_maxNodeCount, NULL);
    PllDomainList l_pciePllDomains(l_maxNodeCount, NULL);
    PllDomainList l_membPllDomains(  l_maxNodeCount, NULL);

    do
    {
        // Idea of build is to add chips to domain and add domains to System
        // Also, we should ensure that if build fails in mid way, deleting
        // System should be enough to clean up th partial model.

        // Add chips to domains.
        errl = addDomainChips( TYPE_MEMBUF, l_membufDomain, &l_membPllDomains );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MBA, l_mbaDomain );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_PROC, l_procDomain,
                               &l_fabricPllDomains, &l_pciePllDomains );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_EX, l_exDomain );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MCS, l_mcsDomain );
        if ( NULL != errl ) break;

    } while (0);

        //Note: we are adding these domains to system regardles of error log
        //handle status. We are doing it simply because in case error handle is
        //not NULL, we want to clean up the partial object model by simply
        //deleting the system. If we add domain to system with or without chips
        //( error scenario ), we can do the clean up quite easily.

        // Add domains to domain list. NOTE: Order is important because this is
        // the order the domains will be analyzed.

        addPllDomainsToSystem( l_fabricPllDomains,
                               l_pciePllDomains,
                               l_membPllDomains );

        //MemBuf domain added after PLL domain
        sysDmnLst.push_back( l_membufDomain );
        //Proc domain added after Membuf domain
        sysDmnLst.push_back( l_procDomain   );
        //In real HW, ATTN only calls PRD with Centaur or Proc chip. For
        //performance improvement during System::Analyze add all domains
        //after membuf/Proc domain.
        sysDmnLst.push_back( l_exDomain );
        sysDmnLst.push_back( l_mcsDomain );
        sysDmnLst.push_back( l_mbaDomain );

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
        PRDF_ERR( "PegasusConfigurator::build() failed to build"
                  " object model" );
    }

    PRDF_EXIT( "PegasusConfigurator::build()" );

    return errl;
}

//------------------------------------------------------------------------------

errlHndl_t PegasusConfigurator::addDomainChips( TARGETING::TYPE  i_type,
                                          RuleChipDomain * io_domain,
                                          PllDomainList  * io_pllDomains,
                                          PllDomainList  * io_pllDomains2)
{
    using namespace TARGETING;
    int32_t l_rc = SUCCESS;
    errlHndl_t l_errl = NULL ;

    // Get references to factory objects.
    ScanFacility      & scanFac = ScanFacility::Access();
    ResolutionFactory & resFac  = ResolutionFactory::Access();

    // Get rule filename based on type.
    const char * fileName = "";
    switch ( i_type )
    {
        case TYPE_PROC:   fileName = Proc;   break;
        case TYPE_EX:     fileName = Ex;     break;
        case TYPE_MCS:    fileName = Mcs;    break;
        case TYPE_MEMBUF: fileName = Membuf; break;
        case TYPE_MBA:    fileName = Mba;    break;

        default:
            // Print a trace statement, but do not fail the build.
            PRDF_ERR( "[addDomainChips] Unsupported target type: %d", i_type );
            l_rc = FAIL;
    }

    if ( SUCCESS == l_rc )
    {
        // Get all targets of specified type and add to given domain.
        TargetHandleList list = PlatServices::getFunctionalTargetList( i_type );

        if ( 0 == list.size() )
        {
            PRDF_ERR( "[addDomainChips] getFunctionalTargetList "
                      "returned empty list for i_type=%d", i_type );
        }

        for ( TargetHandleList::const_iterator itr = list.begin();
              itr != list.end(); ++itr )
        {
            if ( NULL == *itr ) continue;

            RuleChip * chip = new RuleChip( fileName, *itr,
                                            scanFac, resFac,l_errl );
            if( NULL != l_errl )
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
                    addChipsToPllDomain(CLOCK_DOMAIN_FAB,
                                        io_pllDomains,
                                        chip,
                                        *itr,
                                        scanFac,
                                        resFac);
                    addChipsToPllDomain(CLOCK_DOMAIN_IO,
                                        io_pllDomains2,
                                        chip,
                                        *itr,
                                        scanFac,
                                        resFac);
                    break;
                case TYPE_MEMBUF:
                    addChipsToPllDomain(CLOCK_DOMAIN_MEMBUF,
                                        io_pllDomains,
                                        chip,
                                        *itr,
                                        scanFac,
                                        resFac);
                    break;
                default:
                    break;
            }
        }

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();

    }

    return  l_errl;
}

void PegasusConfigurator::addChipsToPllDomain(
 DOMAIN_ID                    i_domainId,
 PllDomainList              * io_pllDomains,
 RuleChip                   * i_chip,
 TARGETING::TargetHandle_t    i_pTarget,
 ScanFacility               & i_scanFac,
 ResolutionFactory          & i_resFac)
{
    do
    {
        uint32_t l_node = _getNodePosition(i_pTarget);

        // Fabric PLL - only one per node as all fabs
        // on node have same clock source
        if(NULL != io_pllDomains)
        {
            if(NULL == (*io_pllDomains)[l_node])
            {
                if(CLOCK_DOMAIN_FAB == i_domainId)
                {
                    Resolution & procClock = i_resFac.GetClockResolution(
                                                    i_pTarget, TYPE_PROC);

                    #ifdef __HOSTBOOT_MODULE
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, procClock,
                                        ThresholdResolution::cv_mnfgDefault );
                    #else
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, procClock,
                                        CONTENT_HW,
                                        ThresholdResolution::cv_mnfgDefault );
                    #endif
                }
                else if(CLOCK_DOMAIN_IO == i_domainId)
                {
                    Resolution & ioClock = i_resFac.GetClockResolution(
                                                    i_pTarget, TYPE_PCI);
                    #ifdef __HOSTBOOT_MODULE
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, ioClock,
                                        ThresholdResolution::cv_mnfgDefault );
                    #else
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, ioClock,
                                        CONTENT_HW,
                                        ThresholdResolution::cv_mnfgDefault );
                    #endif
                }
                else if(CLOCK_DOMAIN_MEMBUF == i_domainId)
                {
                    Resolution & clock = i_resFac.GetClockResolution(
                                                 i_pTarget, TYPE_MEMBUF);

                    #ifdef __HOSTBOOT_MODULE
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, clock,
                                        ThresholdResolution::cv_mnfgDefault );
                    #else
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, clock, CONTENT_HW,
                                        ThresholdResolution::cv_mnfgDefault );
                    #endif
                }
                else
                {
                    PRDF_ERR( "[addChipsToPllDomain] Unsupported PLL Domain: "
                              "0x%08x", i_domainId );
                    break;
                }
            }

            (*io_pllDomains)[l_node]->AddChip(i_chip);
        }

    } while(0);
}

void PegasusConfigurator::addPllDomainsToSystem(
       PllDomainList  & i_fabricPllDomains,
       PllDomainList  & i_pciePllDomains,
       PllDomainList  & i_membPllDomains)
{
    uint32_t l_maxNodeCount = _getMaxNumNodes();

    //Add Fabric Pll Domains to the system.
    for(uint32_t n = 0; n < l_maxNodeCount; ++n)
    {
        if(NULL != i_fabricPllDomains[n])
        {
            sysDmnLst.push_back(i_fabricPllDomains[n]);
        }
    }

    //Add PCIe Pll Domains to the system.
    for(uint32_t n = 0; n < l_maxNodeCount; ++n)
    {
        if(NULL != i_pciePllDomains[n])
        {
            sysDmnLst.push_back(i_pciePllDomains[n]);
        }
    }

    //Add Membuf Pll Domains to the system.
    for(uint32_t n = 0; n < l_maxNodeCount; ++n)
    {
        if(NULL != i_membPllDomains[n])
        {
            sysDmnLst.push_back(i_membPllDomains[n]);
        }
    }
}

} // end namespace PRDF
