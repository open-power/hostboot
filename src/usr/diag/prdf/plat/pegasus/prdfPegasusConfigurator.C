/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPegasusConfigurator.C $    */
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

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <iipglobl.h>
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

//------------------------------------------------------------------------------

// Resolution for no chips at attention.
CallAttnResolution PrdfPegasusConfigurator::noAttnResolution;

//------------------------------------------------------------------------------

System * PrdfPegasusConfigurator::build()
{
    using namespace TARGETING;

    PRDF_ENTER( "PrdfPegasusConfigurator::build()" );

    // Create System object to populate with domains.
    System * l_system = new System(noAttnResolution);

    // Create domains.
    FabricDomain     * l_procDomain   = new FabricDomain(     FABRIC_DOMAIN );
    PrdfExDomain     * l_exDomain     = new PrdfExDomain(     EX_DOMAIN     );
    PrdfMcsDomain    * l_mcsDomain    = new PrdfMcsDomain(    MCS_DOMAIN    );
    PrdfMembufDomain * l_membufDomain = new PrdfMembufDomain( MEMBUF_DOMAIN );
    PrdfMbaDomain    * l_mbaDomain    = new PrdfMbaDomain(    MBA_DOMAIN    );

    // Add chips to domains.
    addDomainChips( TYPE_PROC,   l_procDomain   );
    addDomainChips( TYPE_EX,     l_exDomain     );
    addDomainChips( TYPE_MCS,    l_mcsDomain    );
    addDomainChips( TYPE_MEMBUF, l_membufDomain );
    addDomainChips( TYPE_MBA,    l_mbaDomain    );

    // Add domains to domain list. NOTE: Order is important because this is the
    // order the domains will be analyzed.
    sysDmnLst.push_back( l_procDomain   );
    sysDmnLst.push_back( l_exDomain     );
    sysDmnLst.push_back( l_mcsDomain    );
    sysDmnLst.push_back( l_membufDomain );
    sysDmnLst.push_back( l_mbaDomain    );

    // Add chips to the system.
    Configurator::chipList & chips = getChipList();
    l_system->AddChips( chips.begin(), chips.end() );

    // Add domains to the system.
    Configurator::domainList & domains = getDomainList();
    l_system->AddDomains( domains.begin(), domains.end() );

    PRDF_EXIT( "PrdfPegasusConfigurator::build()" );

    return l_system;
}

//------------------------------------------------------------------------------

void PrdfPegasusConfigurator::addDomainChips( TARGETING::TYPE i_type,
                                              PrdfRuleChipDomain * io_domain )
{
    using namespace TARGETING;
    using namespace PRDF;

    int32_t l_rc = SUCCESS;

    // Get references to factory objects.
    ScanFacility      & scanFac = ScanFacility::Access();
    ResolutionFactory & resFac  = ResolutionFactory::Access();

    // Get rule filename based on type.
    const char * fileName = "";
    switch ( i_type )
    {
        case TYPE_PROC:   fileName = PRDF::Proc;   break;
        case TYPE_EX:     fileName = PRDF::Ex;     break;
        case TYPE_MCS:    fileName = PRDF::Mcs;    break;
        case TYPE_MEMBUF: fileName = PRDF::Membuf; break;
        case TYPE_MBA:    fileName = PRDF::Mba;    break;

        default:
            // Print a trace statement, but do not fail the build.
            PRDF_ERR( "[addDomainChips] Unsupported target type: %d", i_type );
            l_rc = FAIL;
    }

    if ( SUCCESS == l_rc )
    {
        /*
        // Test code to vary the size of the target config
        // so we can still run one simic system type but
        // get different configs for memory measurements

        uint32_t PROC_LIMIT = 16; // set to no limit for now
        uint32_t MEMBUF_PER_PROC_LIMIT = 4;
        uint32_t CONFIG_LIMIT = 0;
        uint32_t count = 0;
        switch ( i_type )
        {
            case TYPE_PROC:   CONFIG_LIMIT = PROC_LIMIT;   break;
            case TYPE_EX:     CONFIG_LIMIT = 6 * PROC_LIMIT;   break;
            case TYPE_ABUS:   CONFIG_LIMIT = 3 * PROC_LIMIT;   break;
            case TYPE_XBUS:   CONFIG_LIMIT = 4 * PROC_LIMIT;   break;
            case TYPE_MCS:    CONFIG_LIMIT = MEMBUF_PER_PROC_LIMIT * PROC_LIMIT;   break;
            case TYPE_MEMBUF: CONFIG_LIMIT = MEMBUF_PER_PROC_LIMIT * PROC_LIMIT;   break;
            case TYPE_MBA:    CONFIG_LIMIT = 2 * MEMBUF_PER_PROC_LIMIT * PROC_LIMIT;   break;

            default: break;
        }
        //end Test code
        */

        // Get all targets of specified type and add to given domain.
        TargetHandleList list = PlatServices::getFunctionalTargetList( i_type );
        for ( TargetHandleList::const_iterator itr = list.begin();
              itr != list.end(); ++itr )
        {
            if ( NULL == *itr ) continue;

            // Test code to vary the target config
            //if(count < CONFIG_LIMIT)
            //{

//            PRDF_TRAC( "[addDomainChips] build rule chip target: 0x%08x",
//                       PlatServices::getHuid(*itr) );

            PrdfRuleChip * chip = new PrdfRuleChip( fileName, *itr,
                                                    scanFac, resFac );
            sysChipLst.push_back( chip );
            io_domain->AddChip(   chip );

            //}
            //count++;
        }

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();

    }
}

