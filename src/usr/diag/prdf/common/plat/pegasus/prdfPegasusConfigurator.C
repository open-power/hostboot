/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPegasusConfigurator.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

namespace PRDF
{

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
    PllDomainList l_membPllDomains(  l_maxNodeCount, NULL);

    do
    {
        // Add chips to domains.
        errl = addDomainChips( TYPE_PROC, l_procDomain, &l_fabricPllDomains );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_EX, l_exDomain );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MCS, l_mcsDomain );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MEMBUF, l_membufDomain, &l_membPllDomains );
        if ( NULL != errl ) break;

        errl = addDomainChips( TYPE_MBA, l_mbaDomain );
        if ( NULL != errl ) break;

        // Add Pll domains to domain list.
        addPllDomainsToSystem( l_fabricPllDomains, l_membPllDomains );

        // Add domains to domain list. NOTE: Order is important because this is
        // the order the domains will be analyzed.
        sysDmnLst.push_back( l_procDomain   );
        sysDmnLst.push_back( l_exDomain     );
        sysDmnLst.push_back( l_mcsDomain    );
        sysDmnLst.push_back( l_membufDomain );
        sysDmnLst.push_back( l_mbaDomain    );

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

    } while (0);

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
                                          PllDomainList  * io_pllDomains )
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
    using namespace TARGETING;

    do
    {
        uint32_t l_node = _getNodePosition(i_pTarget);

        // Fabric PLL - only one per node as all fabs on node have same clock source
        if(NULL != io_pllDomains)
        {
            if(NULL == (*io_pllDomains)[l_node])
            {
                if((CLOCK_DOMAIN_FAB    == i_domainId) ||
                   (CLOCK_DOMAIN_MEMBUF == i_domainId))
                {
                    Resolution & l_clock =(CLOCK_DOMAIN_FAB == i_domainId) ?
                        i_resFac.GetClockResolution(i_pTarget, TYPE_PROC) :
                        i_resFac.GetClockResolution(i_pTarget, TYPE_MEMBUF);

                    #ifdef __HOSTBOOT_MODULE
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, l_clock,
                                        ThresholdResolution::cv_pllDefault );
                    #else
                    (*io_pllDomains)[l_node] = new PllDomain(
                                        i_domainId, l_clock, CONTENT_HW,
                                        ThresholdResolution::cv_pllDefault );
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
