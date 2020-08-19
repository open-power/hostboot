/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Configurator.C $       */
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
#include <prdfP9McDomain.H>
#include <prdfP9MccDomain.H>
#include <prdfP9MiDomain.H>
#include <prdfP9NpuDomain.H>
#include <prdfP9ObusDomain.H>
#include <prdfOcmbChipDomain.H>
#include <prdfP9OmicDomain.H>
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

    errlHndl_t errl = nullptr;

    // Create System object to populate with domains.
    systemPtr = new System(cv_noAttnResolution);

    // Create domains.
    ProcDomain     * procDomain     = new ProcDomain(   PROC_DOMAIN   );
    OcmbChipDomain * ocmbChipDomain = nullptr;

    std::map<TARGETING::TYPE, RuleChipDomain *> unitMap;
    unitMap[TYPE_EQ  ] = new EqDomain(   EQ_DOMAIN   );
    unitMap[TYPE_EX  ] = new ExDomain(   EX_DOMAIN   );
    unitMap[TYPE_CORE] = new EcDomain(   EC_DOMAIN   );
    unitMap[TYPE_CAPP] = new CappDomain( CAPP_DOMAIN );
    unitMap[TYPE_PEC ] = new PecDomain(  PEC_DOMAIN  );
    unitMap[TYPE_PHB ] = new PhbDomain(  PHB_DOMAIN  );
    unitMap[TYPE_XBUS] = new XbusDomain( XBUS_DOMAIN );
    unitMap[TYPE_OBUS] = new ObusDomain( OBUS_DOMAIN );

    switch ( getChipModel(getMasterProc()) )
    {
        case MODEL_AXONE:
            unitMap[TYPE_NPU ] = new NpuDomain(      NPU_DOMAIN  );
            unitMap[TYPE_MC ]  = new McDomain(       MC_DOMAIN   );
            unitMap[TYPE_MI ]  = new MiDomain(       MI_DOMAIN   );
            unitMap[TYPE_MCC ] = new MccDomain(      MCC_DOMAIN  );
            unitMap[TYPE_OMIC] = new OmicDomain(     OMIC_DOMAIN );
            ocmbChipDomain     = new OcmbChipDomain( OCMB_DOMAIN );

            break;

        default:
            PRDF_ERR( "[PlatConfigurator::build] Unsupported master proc "
                      "type %d", getChipModel(getMasterProc()) );
            PRDF_ASSERT(false);
    };

    PllDomainMapList pllDmnMapLst;

    do
    {
        // First, add all chips to the domains.
        // NOTE: Order is important so that the PLL domains are added in the
        //       correct order.
        // NOTE: We should ensure that if build fails midway, deleting System
        //       should be enough to clean up the partial model.

        errl = addDomainChips( TYPE_PROC, procDomain, pllDmnMapLst );
        if ( nullptr != errl ) break;

        if ( nullptr != ocmbChipDomain )
        {
            errl = addDomainChips( TYPE_OCMB_CHIP, ocmbChipDomain,
                                   pllDmnMapLst );
            if ( nullptr != errl ) break;
        }

        // Order does not matter because they are not added to the PLL domains.
        for ( auto & d : unitMap )
        {
            errl = addDomainChips( d.first, d.second, pllDmnMapLst );
            if ( nullptr != errl ) break;
        }

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
    if ( nullptr != ocmbChipDomain ) sysDmnLst.push_back( ocmbChipDomain );

    // Processor chip domains are always third.
    sysDmnLst.push_back( procDomain );

    // ATTN only calls PRD with a list of chips. For performance improvements
    // during System::Analyze() add all chiplet domains after the chip domains.
    // Note that order of the chiplet domains does not matter because analysis
    // originates from the chip domains above.
    for ( auto & d : unitMap )
    {
        sysDmnLst.push_back( d.second );
    }

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

    if ( nullptr != errl )
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
    errlHndl_t errl = nullptr;

    std::map<uint32_t, std::map<TARGETING::TYPE, const char *>> fnMap =
    {
        { MODEL_AXONE,    { { TYPE_PROC,   axone_proc     },
                            { TYPE_EQ,     axone_eq       },
                            { TYPE_EX,     axone_ex       },
                            { TYPE_CORE,   axone_ec       },
                            { TYPE_CAPP,   axone_capp     },
                            { TYPE_PEC,    axone_pec      },
                            { TYPE_PHB,    axone_phb      },
                            { TYPE_XBUS,   axone_xbus     },
                            { TYPE_OBUS,   axone_obus     },
                            { TYPE_NPU,    axone_npu      },
                            { TYPE_MC,     axone_mc       },
                            { TYPE_MI,     axone_mi       },
                            { TYPE_MCC,    axone_mcc      },
                            { TYPE_OMIC,   axone_omic     }, } },
        #ifdef __HOSTBOOT_MODULE
        { POWER_CHIPID::EXPLORER_16, { { TYPE_OCMB_CHIP, explorer_ocmb }, } },
        #endif
        // OCMB is not supported on FSP, however we need support here for the
        // MODEL_OCMB model for our simulator to work.
        #ifdef ESW_SIM_COMPILE
        { MODEL_OCMB, { { TYPE_OCMB_CHIP, explorer_ocmb }, } },
        #endif
    };

    // Get references to factory objects.
    ScanFacility      & scanFac = ScanFacility::Access();
    ResolutionFactory & resFac  = ResolutionFactory::Access();

    // Generic empty PLL domain map
    PllDomainMap sysRefPllDmnMap;
    PllDomainMap mfRefPllDmnMap;

    // Iterate all the targets for this type and add to given domain.
    for ( const auto & trgt : getFunctionalTargetList(i_type) )
    {
        uint32_t model = getChipModel( trgt );

        #ifdef __HOSTBOOT_MODULE
        // Special case for OCMBs (hostboot only issue for P9).
        if ( MODEL_OCMB == model )
        {
             // Use the chip ID instead of model.
            model = getChipId( trgt );

            // Skip Gemini OCMBs. They can exist, but PRD won't support them.
            if ( POWER_CHIPID::GEMINI_16 == model ) continue;
        }
        #endif

        // Ensure this model is supported.
        if ( fnMap.end() == fnMap.find(model) )
        {
            PRDF_ERR( "[addDomainChips] Unsupported chip model %d for type %d",
                      model, i_type );
            PRDF_ASSERT( false );
        }

        // Ensure this type is supported for this model.
        if ( (fnMap[model]).end() == (fnMap[model]).find(i_type) )
        {
            PRDF_ERR( "[addDomainChips] Unsupported type %d for chip model %d",
                      i_type, model );
            PRDF_ASSERT( false );
        }

        // Get the file name for this model/type.
        const char * fileName = fnMap[model][i_type];

        // Get the rule chip.
        RuleChip * chip = new RuleChip( fileName, trgt, scanFac, resFac, errl );
        if ( nullptr != errl )
        {
            delete chip;
            break; // Return the error log.
        }

        // Add it to the chip list and domain.
        sysChipLst.push_back( chip );
        io_domain->AddChip(   chip );

        // Add to the PLL domains, if needed.
        switch ( i_type )
        {
            case TYPE_PROC:
                addChipToPllDomain( CLOCK_DOMAIN_FAB, sysRefPllDmnMap,
                                    chip, trgt, TYPE_PROC,
                                    scanFac, resFac );
                addChipToPllDomain( CLOCK_DOMAIN_IO, mfRefPllDmnMap,
                                    chip, trgt, TYPE_PEC,
                                    scanFac, resFac );
                break;

            default: ;
        }
    }

    // Add the PLL domain maps to the PLL domain map list.
    if ( !sysRefPllDmnMap.empty() )
        io_pllDmnLst.push_back( sysRefPllDmnMap );
    if ( !mfRefPllDmnMap.empty() )
        io_pllDmnLst.push_back( mfRefPllDmnMap );

    // Flush rule table cache since objects are all built.
    Prdr::LoadChipCache::flushCache();

    return errl;
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
    // TODO: RTC 155673 - The position used here should be based on clock
    //       domains. In the past there happened to be one clock source for each
    //       node. In which case, we just used the node position. Unfortunately,
    //       that is not very maintainable code. Instead, we should be querying
    //       clock domain attributes so that this code does not need to be
    //       modified if the clock domains change.
    uint32_t pos = getTargetPosition( getConnectedParent( i_trgt, TYPE_NODE ) );

    if ( io_pllDmnMap.end() == io_pllDmnMap.find(pos) )
    {
        Resolution & clock = i_resFac.GetClockResolution( i_trgt, i_type );

        #ifdef __HOSTBOOT_MODULE
        io_pllDmnMap[pos] = new PllDomain( i_domainId, clock,
                                     ThresholdResolution::cv_mnfgDefault );
        #else
        io_pllDmnMap[pos] = new PllDomain( i_domainId, clock, CONTENT_HW,
                                     ThresholdResolution::cv_mnfgDefault );
        #endif
    }

    io_pllDmnMap[pos]->AddChip( i_chip );
}

//------------------------------------------------------------------------------

void PlatConfigurator::addPllDomainsToSystem( const PllDomainMapList & i_list )
{
    for ( PllDomainMapList::const_iterator lit = i_list.begin();
          lit != i_list.end(); ++lit )
    {
        for ( PllDomainMap::const_iterator mit = lit->begin();
              mit != lit->end(); ++mit )
        {
            sysDmnLst.push_back( mit->second );
        }
    }
}

} // end namespace PRDF
