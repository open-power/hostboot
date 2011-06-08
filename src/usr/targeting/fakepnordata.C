
/**
 *  @file fakepnordata.C
 *
 *  @brief Generates a fake PNOR image for supporting host boot while PNOR
 *      is not available (i.e. bringup)
*/

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <vector>

// Other components
#include <util/singleton.H>
#include <trace/interface.H>

// This component
#include <targeting/attributes.H>
#include <targeting/target.H>
#include "fakepnordata.H"
#include "trace.H"

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "PnorBuilderService::"



//******************************************************************************
// PnorBuilderService::~PnorBuilderService
//******************************************************************************

PnorBuilderService::~PnorBuilderService()
{
    free(iv_pPnor);
    free(iv_pHeap);
}

//******************************************************************************
// PnorBuilderService::heapBase
//******************************************************************************

uint8_t* PnorBuilderService::heapBase() const
{
    return reinterpret_cast<uint8_t*>(iv_pHeap);
}

//******************************************************************************
// PnorBuilderService::pnorBase
//******************************************************************************

uint8_t* PnorBuilderService::pnorBase() const
{
    return reinterpret_cast<uint8_t*>(iv_pPnor);
}

//******************************************************************************
// PnorBuilderService::clearPnorSection
//******************************************************************************

void PnorBuilderService::clearPnorSection()
{
    memset(pnorBase(),0x00,PNOR_SIZE);
}

//******************************************************************************
// PnorBuilderService::clearHeapSection
//******************************************************************************

void PnorBuilderService::clearHeapSection()
{
    memset(heapBase(),0x00,HEAP_SIZE);
}

//******************************************************************************
// PnorBuilderService::populateValidAttrIds
//******************************************************************************

void PnorBuilderService::populateValidAttrIds(
          uint8_t*&              i_pPnor,
    const std::vector<AttrInfo>& i_attrInfo,
          ATTRIBUTE_ID*&         o_pAttrNames)
{
    uint32_t l_numAttr = i_attrInfo.size();
    *(reinterpret_cast<uint32_t*>(i_pPnor)) = l_numAttr;
    i_pPnor+=sizeof(l_numAttr);
    ATTRIBUTE_ID (*l_pAttr)[] = (ATTRIBUTE_ID (*)[])i_pPnor;
    for(uint32_t i=0; i<l_numAttr; ++i)
    {
        memcpy(i_pPnor,&i_attrInfo[i].attrId,sizeof(i_attrInfo[i].attrId));
        i_pPnor+=sizeof(i_attrInfo[i].attrId);
    }
    o_pAttrNames = (ATTRIBUTE_ID*)l_pAttr;
}

//******************************************************************************
// PnorBuilderService::populateAttrs
//******************************************************************************

void PnorBuilderService::populateAttrs(
           const ATTRIBUTE_ID*     i_pAttrNames,
           uint8_t*&               i_pPnor,
           uint8_t*&               i_pHeap,
           std::vector< Target* >& o_targets,
     const std::vector<AttrInfo>&  i_attrInfo)
{
    void* (*l_pAttrValues)[] = (void* (*)[])i_pPnor;

    // Reserve space for number of pointers
    i_pPnor += sizeof(void*) * i_attrInfo.size();

    // Iterate through the data
    for(uint32_t i=0; i<i_attrInfo.size(); ++i)
    {
        void* l_pData = (i_attrInfo[i].location == PNOR)
            ? (void*)i_pPnor : (void*)i_pHeap;
        memcpy(l_pData,i_attrInfo[i].pData,i_attrInfo[i].size);
        if(i_attrInfo[i].location == PNOR)
        {
            i_pPnor+=i_attrInfo[i].size;
        }
        else
        {
            i_pHeap+=i_attrInfo[i].size;
        }
        (*l_pAttrValues)[i] = l_pData;
    }

    Target* l_pTarget = new Target();
    l_pTarget->iv_attrs = i_attrInfo.size();
    l_pTarget->iv_pAttrNames = (ATTRIBUTE_ID (*)[])i_pAttrNames;
    l_pTarget->iv_pAttrValues = l_pAttrValues;
    o_targets.push_back(l_pTarget);
}

//******************************************************************************
// PnorBuilderService::buildTargetingImage
//******************************************************************************

void PnorBuilderService::buildTargetingImage()
{
    #define TARG_FN "buildTargetingImage()"

    TARG_INF(">>Build targeting image");

    clearPnorSection();
    clearHeapSection();

    std::vector<Target*> l_targets;

    uint8_t* l_pPnor = pnorBase();
    uint8_t* l_pHeap = heapBase();
    ATTRIBUTE_ID* l_pAttrNames = NULL;

    uint32_t** l_numTargets = (uint32_t**)l_pPnor;
    l_pPnor+=sizeof(uint32_t*);
    std::vector<AttrInfo> l_attrs;

    TARG_INF("Populate sys 0");

    // Populate the system target
    SysSysPower8 l_sysSysPower8_0;
    EntityPath l_sysContainment(EntityPath::PATH_PHYSICAL);
    EntityPath l_sysAffinity(EntityPath::PATH_AFFINITY);
    l_sysContainment.addLast(TYPE_SYS,0);
    l_sysAffinity.addLast(TYPE_SYS,0);
    l_sysSysPower8_0.iv_physicalPath.set(l_sysContainment);
    l_sysSysPower8_0.iv_affinityPath.set(l_sysAffinity);
    l_sysSysPower8_0.iv_xscomBaseAddr.set(0x300000000000);
    l_sysSysPower8_0.getAttrInfo(l_attrs);
    populateValidAttrIds(l_pPnor,l_attrs,l_pAttrNames);
    populateAttrs(l_pAttrNames,l_pPnor,l_pHeap,l_targets,l_attrs);
    l_attrs.clear();

    // Populate the sys0/node0 target
    EncNodePower8 l_encNodePower8_0;
    EntityPath l_nodeContainment = l_sysContainment;
    l_nodeContainment.addLast(TYPE_NODE,0);
    EntityPath l_nodeAffinity = l_sysAffinity;
    l_nodeAffinity.addLast(TYPE_NODE,0);
    l_encNodePower8_0.iv_physicalPath.set(l_nodeContainment);
    l_encNodePower8_0.iv_affinityPath.set(l_nodeAffinity);
    l_encNodePower8_0.getAttrInfo(l_attrs);
    populateValidAttrIds(l_pPnor,l_attrs,l_pAttrNames);
    populateAttrs(l_pAttrNames,l_pPnor,l_pHeap,l_targets,l_attrs);
    l_attrs.clear();

//    // Populate the sys0/node0/SCM0 target
//    CardScmPower8 l_cardScmPower8_0;
//    EntityPath l_scmContainment = l_nodeContainment;
//    l_scmContainment.addLast(TYPE_SCM,0);
//    EntityPath l_scmAffinity = l_nodeAffinity;
//    l_scmAffinity.addLast(TYPE_SCM,0);
//    l_cardScmPower8_0.iv_physicalPath.set(l_scmContainment);
//    l_cardScmPower8_0.iv_affinityPath.set(l_scmAffinity);
//    l_cardScmPower8_0.getAttrInfo(l_attrs);
//    populateValidAttrIds(l_pPnor,l_attrs,l_pAttrNames);
//    populateAttrs(l_pAttrNames,l_pPnor,l_pHeap,l_targets,l_attrs);
//    l_attrs.clear();

    TARG_INF("Populate proc 0");

    // Populate the sys0/node0/proc0 Salerno processor chip targets
    ProcChipSalerno l_procChipSalerno_0;
    EntityPath l_procContainment = l_nodeContainment;
    l_procContainment.addLast(TYPE_PROC,0);
    EntityPath l_procAffinity = l_nodeAffinity;
    l_procAffinity.addLast(TYPE_PROC,0);
    l_procChipSalerno_0.iv_physicalPath.set(l_procContainment);
    l_procChipSalerno_0.iv_affinityPath.set(l_procAffinity);
    XscomChipInfo l_xscomChipInfo = {0,0};
    l_procChipSalerno_0.iv_xscomChipInfo.set(l_xscomChipInfo);
    l_procChipSalerno_0.getAttrInfo(l_attrs);
    populateValidAttrIds(l_pPnor,l_attrs,l_pAttrNames);
    populateAttrs(l_pAttrNames,l_pPnor,l_pHeap,l_targets,l_attrs);



#define EX_PER_SALERNO 6

    ATTRIBUTE_ID* l_pExAttrNames   = NULL;
    ATTRIBUTE_ID* l_pCoreAttrNames = NULL;
    ATTRIBUTE_ID* l_pL2AttrNames   = NULL;
    ATTRIBUTE_ID* l_pL3AttrNames   = NULL;
    TARG_INF("Populate EXs and sub-units");

    for(int i=0; i<EX_PER_SALERNO; ++i)
    {
        TARG_INF("Populate EX");
        std::vector<AttrInfo> l_exInstAttrs;
        UnitExSalerno l_unitExSalerno;

        // Customize
        EntityPath l_exContainment = l_procContainment;
        l_exContainment.addLast(TYPE_EX,i);
        EntityPath l_exAffinity = l_procAffinity;
        l_exAffinity.addLast(TYPE_EX,i);
        l_unitExSalerno.iv_physicalPath.set(l_exContainment);
        l_unitExSalerno.iv_affinityPath.set(l_exAffinity);
        l_unitExSalerno.getAttrInfo(l_exInstAttrs);

        // If valid attributes are empty for this class
        if(l_pExAttrNames == NULL)
        {
            populateValidAttrIds(l_pPnor,l_exInstAttrs,l_pExAttrNames);
        }

        populateAttrs(l_pExAttrNames,l_pPnor,l_pHeap,l_targets,l_exInstAttrs);

        TARG_INF("Populate Core");

        // Populate core
        std::vector<AttrInfo> l_coreInstAttrs;
        UnitCoreSalerno l_unitCoreSalerno;
        EntityPath l_coreContainment = l_procContainment;
        l_coreContainment.addLast(TYPE_CORE,i);
        EntityPath l_coreAffinity = l_exAffinity;
        l_coreAffinity.addLast(TYPE_CORE,0);
        l_unitCoreSalerno.iv_physicalPath.set(l_coreContainment);
        l_unitCoreSalerno.iv_affinityPath.set(l_coreAffinity);
        l_unitCoreSalerno.getAttrInfo(l_coreInstAttrs);
        if(l_pCoreAttrNames == NULL)
        {
            populateValidAttrIds(l_pPnor,l_coreInstAttrs,l_pCoreAttrNames);
        }
        populateAttrs(l_pCoreAttrNames,l_pPnor,l_pHeap,l_targets,l_coreInstAttrs);

        TARG_INF("Populate L2");

        // Populate L2
        std::vector<AttrInfo> l_l2InstAttrs;
        UnitL2Salerno l_unitL2Salerno;
        EntityPath l_l2Containment = l_procContainment;
        l_l2Containment.addLast(TYPE_L2,i);
        EntityPath l_l2Affinity = l_exAffinity;
        l_l2Affinity.addLast(TYPE_L2,0);
        l_unitL2Salerno.iv_physicalPath.set(l_l2Containment);
        l_unitL2Salerno.iv_affinityPath.set(l_l2Affinity);
        l_unitL2Salerno.getAttrInfo(l_l2InstAttrs);
        if(l_pL2AttrNames == NULL)
        {
            populateValidAttrIds(l_pPnor,l_l2InstAttrs,l_pL2AttrNames);
        }
        populateAttrs(l_pL2AttrNames,l_pPnor,l_pHeap,l_targets,l_l2InstAttrs);

        TARG_INF("Populate L3");

        // Populate L3
        std::vector<AttrInfo> l_l3InstAttrs;
        UnitL3Salerno l_unitL3Salerno;
        EntityPath l_l3Containment = l_procContainment;
        l_l3Containment.addLast(TYPE_L3,i);
        EntityPath l_l3Affinity = l_exAffinity;
        l_l3Affinity.addLast(TYPE_L3,0);
        l_unitL3Salerno.iv_physicalPath.set(l_l3Containment);
        l_unitL3Salerno.iv_affinityPath.set(l_l3Affinity);
        l_unitL3Salerno.getAttrInfo(l_l3InstAttrs);
        if(l_pL3AttrNames == NULL)
        {
            populateValidAttrIds(l_pPnor,l_l3InstAttrs,l_pL3AttrNames);
        }
        populateAttrs(l_pL3AttrNames,l_pPnor,l_pHeap,l_targets,l_l3InstAttrs);
    }


    // Populate Mcs
    ATTRIBUTE_ID* l_pMcsAttrNames   = NULL;

    std::vector<AttrInfo> l_McsInstAttrs;
    UnitMcsSalerno l_unitMcsSalerno;
    EntityPath l_McsContainment = l_procContainment;
    l_McsContainment.addLast(TYPE_MCS,0);
    EntityPath l_McsAffinity = l_procAffinity;
    l_McsAffinity.addLast(TYPE_MCS,0);
    l_unitMcsSalerno.iv_physicalPath.set(l_McsContainment);
    l_unitMcsSalerno.iv_affinityPath.set(l_McsAffinity);
    l_unitMcsSalerno.getAttrInfo(l_McsInstAttrs);
    if(l_pMcsAttrNames == NULL)
    {
        populateValidAttrIds(l_pPnor,l_McsInstAttrs,l_pMcsAttrNames);
    }
    populateAttrs(l_pMcsAttrNames,l_pPnor,l_pHeap,l_targets,l_McsInstAttrs);

    ATTRIBUTE_ID* l_pMbaAttrNames   = NULL;
    ATTRIBUTE_ID* l_pMemPortAttrNames   = NULL;

    for(int i=0; i<2; ++i)
    {
        // Populate MBAs
        std::vector<AttrInfo> l_MbaInstAttrs;
        UnitMbaSalerno l_unitMbaSalerno;
        EntityPath l_mbaContainment = l_procContainment;
        l_mbaContainment.addLast(TYPE_MBA,i);
        EntityPath l_mbaAffinity = l_McsAffinity;
        l_mbaAffinity.addLast(TYPE_MBA,i);
        l_unitMbaSalerno.iv_physicalPath.set(l_mbaContainment);
        l_unitMbaSalerno.iv_affinityPath.set(l_mbaAffinity);
        l_unitMbaSalerno.getAttrInfo(l_MbaInstAttrs);
        if(l_pMbaAttrNames == NULL)
        {
            populateValidAttrIds(l_pPnor,l_MbaInstAttrs,l_pMbaAttrNames);
        }
        populateAttrs(l_pMbaAttrNames,l_pPnor,l_pHeap,l_targets,l_MbaInstAttrs);

        for(uint32_t l_ports=0; l_ports<1; ++l_ports)
        {
            // Populate Memory Ports
            std::vector<AttrInfo> l_MemPortInstAttrs;
            UnitMemPortSalerno l_unitMemPortSalerno;
            EntityPath l_MemPortContainment = l_procContainment;
            l_MemPortContainment.addLast(TYPE_MEM_PORT,i);
            EntityPath l_MemPortAffinity = l_mbaAffinity;
            l_MemPortAffinity.addLast(TYPE_MEM_PORT,l_ports);
            l_unitMemPortSalerno.iv_physicalPath.set(l_MemPortContainment);
            l_unitMemPortSalerno.iv_affinityPath.set(l_MemPortAffinity);
            l_unitMemPortSalerno.getAttrInfo(l_MemPortInstAttrs);
            if(l_pMemPortAttrNames == NULL)
            {
                populateValidAttrIds(l_pPnor,l_MemPortInstAttrs,l_pMemPortAttrNames);
            }
            populateAttrs(l_pMemPortAttrNames,l_pPnor,l_pHeap,l_targets,l_MemPortInstAttrs);

            // DIMMs will get linked up later
        }
    }

    // Populate Pervasive Unit
    ATTRIBUTE_ID* l_pPervasiveAttrNames   = NULL;
    std::vector<AttrInfo> l_PervasiveInstAttrs;
    UnitPervasiveSalerno l_unitPervasiveSalerno;
    EntityPath l_PervasiveContainment = l_procContainment;
    l_PervasiveContainment.addLast(TYPE_PERVASIVE,0);
    EntityPath l_PervasiveAffinity = l_procAffinity;
    l_PervasiveAffinity.addLast(TYPE_PERVASIVE,0);
    l_unitPervasiveSalerno.iv_physicalPath.set(l_PervasiveContainment);
    l_unitPervasiveSalerno.iv_affinityPath.set(l_PervasiveAffinity);
    l_unitPervasiveSalerno.getAttrInfo(l_PervasiveInstAttrs);
    if(l_pPervasiveAttrNames == NULL)
    {
       populateValidAttrIds(l_pPnor,l_PervasiveInstAttrs,l_pPervasiveAttrNames);
    }
    populateAttrs(l_pPervasiveAttrNames,l_pPnor,l_pHeap,l_targets,l_PervasiveInstAttrs);

    // Populate Powerbus Unit
    ATTRIBUTE_ID* l_pPowerbusAttrNames   = NULL;
    std::vector<AttrInfo> l_PowerbusInstAttrs;
    UnitPowerbusSalerno l_unitPowerbusSalerno;
    EntityPath l_PowerbusContainment = l_procContainment;
    l_PowerbusContainment.addLast(TYPE_POWERBUS,0);
    EntityPath l_PowerbusAffinity = l_procAffinity;
    l_PowerbusAffinity.addLast(TYPE_POWERBUS,0);
    l_unitPowerbusSalerno.iv_physicalPath.set(l_PowerbusContainment);
    l_unitPowerbusSalerno.iv_affinityPath.set(l_PowerbusAffinity);
    l_unitPowerbusSalerno.getAttrInfo(l_PowerbusInstAttrs);
    if(l_pPowerbusAttrNames == NULL)
    {
       populateValidAttrIds(l_pPnor,l_PowerbusInstAttrs,l_pPowerbusAttrNames);
    }
    populateAttrs(l_pPowerbusAttrNames,l_pPnor,l_pHeap,l_targets,l_PowerbusInstAttrs);

    // Populate PCI Units
    ATTRIBUTE_ID* l_pPciAttrNames   = NULL;

    for(int i=0; i<3; ++i)
    {
        std::vector<AttrInfo> l_PciInstAttrs;
        UnitPciSalerno l_unitPciSalerno;
        EntityPath l_pciContainment = l_procContainment;
        l_pciContainment.addLast(TYPE_PCI,i);
        EntityPath l_pciAffinity = l_procAffinity;
        l_pciAffinity.addLast(TYPE_PCI,i);
        l_unitPciSalerno.iv_physicalPath.set(l_pciContainment);
        l_unitPciSalerno.iv_affinityPath.set(l_pciAffinity);
        l_unitPciSalerno.getAttrInfo(l_PciInstAttrs);
        if(l_pPciAttrNames == NULL)
        {
           populateValidAttrIds(l_pPnor,l_PciInstAttrs,l_pPciAttrNames);
        }
        populateAttrs(l_pPciAttrNames,l_pPnor,l_pHeap,l_targets,l_PciInstAttrs);
    }


    /*
    TARG_INF("Populate proc 1");


    // Populate the sys0/node0/DCM0/proc1 Salerno processor chip targets
    ProcChipSalerno l_procChipSalerno_1;
    l_containment.removeLast();
    l_affinity.removeLast();
    l_containment.addLast(TYPE_PROC,1);
    l_affinity.addLast(TYPE_PROC,1);
    l_procChipSalerno_1.iv_physicalPath.set(l_containment);
    l_procChipSalerno_1.iv_affinityPath.set(l_affinity);
    std::vector<AttrInfo> l_attrs1;
    l_procChipSalerno_1.getAttrInfo(l_attrs1);
    populateAttrs(l_pAttrNames,l_pPnor,l_pHeap,l_targets,l_attrs1);
    l_attrs.clear();
    l_attrs1.clear();
    */

    TARG_INF("Finalize PNOR");

    // Populate pointer to total # of targets at beginning of
    // targeting section
    *l_numTargets = (uint32_t*)l_pPnor;

    // Add number of targets
    uint32_t l_instance = l_targets.size();
    memcpy(l_pPnor,&l_instance,sizeof(l_instance));
    l_pPnor+= sizeof(l_instance);

    // Add actual targets
    for(uint32_t i=0; i<l_targets.size(); ++i)
    {
        memcpy(l_pPnor,l_targets[i],sizeof(Target));
        l_pPnor+=sizeof(Target);
    }

    // Compute the actual PNOR and heap sizes and reallocate the memory
    uint32_t l_pnorSize = (l_pPnor - pnorBase());
    uint32_t l_heapSize = (l_pHeap - heapBase());
 //   realloc(iv_pPnor,l_pnorSize);
  //  realloc(iv_pHeap,l_heapSize);

    TARG_INF(
        "Targeting PNOR size = %d bytes, "
        "heap size = %d bytes, "
        "est stack size = %d bytes",l_pnorSize,l_heapSize,
        (uint32_t)((uint64_t)&l_targets-(uint64_t)&l_heapSize));


    // PNOR/HEAP image now ready for bringup use

    #undef TARG_FN
}

//******************************************************************************
// PnorBuilderService::getTargetingImageBaseAddress
//******************************************************************************

void PnorBuilderService::getTargetingImageBaseAddress(
    const void*& o_pTargetsArea)
{
    o_pTargetsArea = reinterpret_cast<void*>(iv_pPnor);
}

//******************************************************************************
// PnorBuilderService::PnorBuilderService
//******************************************************************************

PnorBuilderService::PnorBuilderService()
{
    TARG_INF(">>PnorBuilderService");


    iv_pPnor = reinterpret_cast<uint8_t*>(malloc(PNOR_SIZE));

    TARG_INF(">>malloc(HEAP_SIZE)");

    iv_pHeap = reinterpret_cast<uint8_t*>(malloc(HEAP_SIZE));

    TARG_INF("Calling buildTargetingImage");

    (void)buildTargetingImage();

    TARG_INF("<<PnorBuilderService");

}

#undef TARG_NAMESPACE
#undef TARG_CLASS

} // End namespace TARGETING

