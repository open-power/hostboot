/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/bld_devtree.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
/* [+] Google Inc.                                                        */
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

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/attrrp.H>
#include <devtree/devtree_reasoncodes.H>
#include <devtree/devtreeif.H>
#include "devtree.H"
#include <sys/mmio.h> //THIRTYTWO_GB
#include <vpd/vpd_if.H>
#include <stdio.h>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <util/align.H>
#include <vector>
#include <vfs/vfs.H>
#include <fsi/fsiif.H>
#include <config.h>
#include <devicefw/userif.H>
#include <vpd/pvpdenums.H>
#include <i2c/i2cif.H>
#include <i2c/eepromif.H>
#include <intr/interrupt.H>

#include <ipmi/ipmisensor.H>

//@TODO RTC:143092
//#include <fapi.H>
//#include <fapiPlatHwpInvoker.H> // for fapi::fapiRcToErrl()
#include <vpd/mvpdenums.H>
#include <arch/pirformat.H>

trace_desc_t *g_trac_devtree = NULL;
TRAC_INIT(&g_trac_devtree, "DEVTREE", 4096);

namespace DEVTREE
{
using   namespace   TARGETING;

typedef std::pair<uint64_t,uint64_t> homerAddr_t;

enum BuildConstants
{
    DEVTREE_DATA_ADDR   =0xFF00000,    /*256MB - 1MB*/
    DEVTREE_SPACE_SIZE  =0x40000,      /*256KB*/
    XSCOM_NODE_SHIFT    =38,           /*Node pos is 25, so 63-25=38*/
    XSCOM_CHIP_SHIFT    =35,           /*Chip pos is 28, so 63-28=35*/
    CHIPID_NODE_SHIFT   =3,            /*CHIPID is NNNNCCC, shift 3*/
    CHIPID_PROC_MASK    =0x7,          /*CHIPID is NNNNCCC, shift 3*/
    PHB0_MASK           =0x80,
    MAX_PHBs            =4,            /*Max PHBs per chip is 4*/
    THREADPERCORE       =8,            /*8 threads per core*/
    MHZ                 =1000000,

    /* The Cache unit address (and reg property) is mostly free-for-all
     * as long as there is no collisions. On HDAT machines we use the
     * following encoding which I encourage you to also follow to limit
     * surprises:
     *
     * L2   :  (0x20 << 24) | PIR (PIR is PIR value of thread 0 of core)
     * L3   :  (0x30 << 24) | PIR
     * L3.5 :  (0x35 << 24) | PIR */
    L2_HDR              = (0x20 << 24),
    L3_HDR              = (0x30 << 24),
    CEN_ID_SHIFT        = 4,
    CEN_ID_TAG          = 0x80000000,
};

//   Opal will set this FIR bit any time a non-checkstop hardware error
//   leads to a crash.  PRD will use this FIR bit to analyze appropriately.
void bld_swCheckstopFir (devTree * i_dt, dtOffset_t & i_parentNode)
{
    const uint32_t PBEASTFIR_OR       = 0x02010c82;
    const uint32_t PBEASTFIR_MASK_AND = 0x02010c84;
    const uint32_t PBEASTFIR_ACT0     = 0x02010c86;
    const uint32_t PBEASTFIR_ACT1     = 0x02010c87;
    uint64_t BIT_31_MASK        = 0xfffffffeffffffff;
    uint64_t l_data = 0;
    size_t opsize = sizeof(uint64_t);

    errlHndl_t l_errl = NULL;

    do
    {
        // unmask all functional proc chip targets
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

        for (size_t proc = 0; proc < l_procTargetList.size(); proc++)
        {
            TARGETING::Target * l_proc = l_procTargetList[proc];

            // clear PBEASTFIR_ACT0 bit 31
            l_errl = deviceRead( l_proc,
                        &l_data,
                        opsize,
                        DEVICE_SCOM_ADDRESS(PBEASTFIR_ACT0) );
            if (l_errl) break;
            l_data &= BIT_31_MASK;
            l_errl = deviceWrite( l_proc,
                        &l_data,
                        opsize,
                        DEVICE_SCOM_ADDRESS(PBEASTFIR_ACT0) );
            if (l_errl) break;

            // clear PBEASTFIR_ACT1 bit 31
            l_errl = deviceRead( l_proc,
                        &l_data,
                        opsize,
                        DEVICE_SCOM_ADDRESS(PBEASTFIR_ACT1) );
            if (l_errl) break;
            l_data &= BIT_31_MASK;
            l_errl = deviceWrite( l_proc,
                        &l_data,
                        opsize,
                        DEVICE_SCOM_ADDRESS(PBEASTFIR_ACT1) );
            if (l_errl) break;

            // clear PBEASTFIR_MASK bit 31 using the AND register
            l_errl = deviceWrite( l_proc,
                        &BIT_31_MASK,
                        opsize,
                        DEVICE_SCOM_ADDRESS(PBEASTFIR_MASK_AND) );
            if (l_errl) break;
        }

        // add devtree property
        uint32_t cellProperties [2] = {PBEASTFIR_OR,31};  // PBEASTFIR[31]
        i_dt->addPropertyCells32(i_parentNode,
                                 "ibm,sw-checkstop-fir",
                                 cellProperties, 2);
    } while (0);

    if (l_errl) // commit error and keep going
    {
        errlCommit(l_errl, DEVTREE_COMP_ID);
    }
}

//@todo-RTC:123043 -- Should use the functions in RT_TARG
uint32_t getProcChipId(const TARGETING::Target * i_pProc)
{
    uint32_t l_fabId = i_pProc->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
    uint32_t l_procPos = i_pProc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
    return ( (l_fabId << CHIPID_NODE_SHIFT) + l_procPos);
}

//@todo-RTC:123043 -- Should use the functions in RT_TARG
uint32_t getMembChipId(const TARGETING::Target * i_pMemb)
{
    PredicateCTM l_mcs(CLASS_UNIT,TYPE_MCS, MODEL_NA);
    TargetHandleList mcs_list;
    targetService().getAssociated(mcs_list,
                                  i_pMemb,
                                  TargetService::PARENT_BY_AFFINITY,
                                  TargetService::ALL,
                                  &l_mcs);

    if( mcs_list.size() != 1 )
    {
        //should never happen
        return 0;
    }
    Target* l_parentMCS = *(mcs_list.begin());
    uint32_t l_procId = getProcChipId(getParentChip(l_parentMCS));
    uint32_t l_membId = CEN_ID_TAG | (l_procId << CEN_ID_SHIFT);
    l_membId |= l_parentMCS->getAttr<ATTR_CHIP_UNIT>();
    return l_membId;
}

uint64_t getOccCommonAddr()
{
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t l_physAddr = sys->getAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>();
    return l_physAddr;
}

homerAddr_t getHomerPhysAddr(const TARGETING::Target * i_pProc)
{
    uint64_t l_homerPhysAddrBase = i_pProc->getAttr<ATTR_HOMER_PHYS_ADDR>();
    uint8_t  l_Pos = i_pProc->getAttr<ATTR_POSITION>();

    TRACFCOMP( g_trac_devtree, "proc ChipID [%X] HOMER is at %.16X"
                               " instance %d",
               getProcChipId(i_pProc), l_homerPhysAddrBase, l_Pos );

    return homerAddr_t(l_homerPhysAddrBase, l_Pos);
}

void add_i2c_info( const TARGETING::Target* i_targ,
                   devTree* i_dt,
                   dtOffset_t i_node )
{
    TRACFCOMP(g_trac_devtree,"add_i2c_info(%X)",TARGETING::get_huid(i_targ));

    //get list of all I2C Masters
    std::list<I2C::MasterInfo_t> l_i2cInfo;
    I2C::getMasterInfo( i_targ, l_i2cInfo );

    //find all of the EEPROMs connected via i2c
    std::list<EEPROM::EepromInfo_t> l_eepromInfo;
    EEPROM::getEEPROMs( l_eepromInfo );

    //add any other i2c devices here as needed, e.g. TPM, etc

    //figure out what kind of chip we're talking about
    TARGETING::TYPE l_master_type = i_targ->getAttr<TARGETING::ATTR_TYPE>();
    const char* l_masterName = "ibm,unknown";
    const char* l_chipname = "xx";
    uint32_t l_chipid = 0x0;
    if( l_master_type == TARGETING::TYPE_PROC )
    {
        l_masterName = "ibm,power8-i2cm";
        l_chipid = getProcChipId(i_targ);
        l_chipname = "p8";
    }
    else if( l_master_type == TARGETING::TYPE_MEMBUF )
    {
        l_masterName = "ibm,centaur-i2cm";
        l_chipid = getMembChipId(i_targ);
        l_chipname = "cen";
    }

    //compatible devices to make Opal/Linux happy
    static const struct
    {
        const char* name;
        size_t byteSize;
        size_t addrBytes;
    } atmel_ids[] = {
        { "atmel,24c128", 16*KILOBYTE, 2 },
        { "atmel,24c256", 32*KILOBYTE, 2 },
        { "atmel,24c02",  256,         1 },

        //Currently our minimum is 1KB, even for the 256 byte SPD
        { "atmel,24c02",  1*KILOBYTE,  1 },
    };

    /*
     Devtree hierarchy is like so
         i2cm@12345 {
             i2c-bus@0 {
                 eeprom@12 {
                 }
             }
             i2c-bus@1 {
                 eeprom@12 {
                 }
                 eeprom@34 {
                 }
             }
         }
     */
    for( std::list<I2C::MasterInfo_t>::iterator i2cm = l_i2cInfo.begin();
         i2cm != l_i2cInfo.end();
         ++i2cm )
    {
        /*
         i2cm@a0020 {
             reg = <0xa0020 0x20>; << scom address space
             chip-engine# = <0x1>; << i2c engine
             compatible = "ibm,power8-i2cm"; << what Opal wants
             clock-frequency = <0x2faf080>; << local bus in Hz
             #address-cells = <0x1>;
             phandle = <0x10000062>; << auto-filled
             #size-cells = <0x0>;
             linux,phandle = <0x10000062>; << Opal fills in
         }
         */
        dtOffset_t l_i2cNode = i_dt->addNode(i_node,
                                             "i2cm", i2cm->scomAddr);
        uint32_t l_i2cProp[2] = {
            static_cast<uint32_t>(i2cm->scomAddr),
            0x20 }; //0x20 is number of scom regs per engine
        i_dt->addPropertyCells32(l_i2cNode, "reg", l_i2cProp, 2);
        i_dt->addPropertyCell32(l_i2cNode, "chip-engine#", i2cm->engine);
        const char* l_i2cCompatStrs[] = {l_masterName, NULL};
        i_dt->addPropertyStrings(l_i2cNode, "compatible", l_i2cCompatStrs);
        i_dt->addPropertyCell32(l_i2cNode, "clock-frequency", i2cm->freq);
        i_dt->addPropertyCell32(l_i2cNode, "#address-cells", 1);
        i_dt->addPropertyCell32(l_i2cNode, "#size-cells", 0);


        /*I2C busses*/
        std::list<EEPROM::EepromInfo_t>::iterator eep = l_eepromInfo.begin();
        while( eep != l_eepromInfo.end() )
        {
            // ignore the devices that aren't on the current target
            if( eep->i2cMaster != i_targ )
            {
                eep = l_eepromInfo.erase(eep);
                continue;
            }
            // skip the devices that are on a different engine
            else if( eep->engine != i2cm->engine )
            {
                ++eep;
                continue;
            }

            /*
             i2c-bus@0 {
                 reg = <0x0>;
                 bus-frequency = <0x61a80>;
                 compatible = "ibm,power8-i2c-port", << Opal fills in
                              "ibm,opal-i2c"; << Opal fills in
                 ibm,opal-id = <0x1>; << Opal fills in
                 ibm,port-name = "p8_00000000_e1p0"; << chip_chipid_eng_port
                 #address-cells = <0x1>;
                 phandle = <0x10000063>; << auto-filled
                 #size-cells = <0x0>;
                 linux,phandle = <0x10000063>;
             }
             */
            dtOffset_t l_busNode = i_dt->addNode( l_i2cNode,
                                                  "i2c-bus", eep->port );
            i_dt->addPropertyCell32(l_busNode, "reg", eep->port);
            i_dt->addPropertyCell32(l_busNode, "bus-frequency", eep->busFreq);
            i_dt->addPropertyCell32(l_busNode, "#address-cells", 1);
            i_dt->addPropertyCell32(l_busNode, "#size-cells", 0);
            char portname[20];
            sprintf( portname, "%s_%.8X_e%dp%d",
                     l_chipname,
                     l_chipid,
                     eep->engine,
                     eep->port );
            i_dt->addPropertyString(l_busNode,
                                    "ibm,port-name",
                                    portname);

            // find any other devices on the same port so we can add them
            //  all at once
            EEPROM::EepromInfo_t cur_eep = *eep;
            std::list<EEPROM::EepromInfo_t>::iterator eep2 = eep;
            while( eep2 != l_eepromInfo.end() )
            {
                // skip the devices for other busses
                if( !((cur_eep.i2cMaster == eep2->i2cMaster)
                      && (cur_eep.engine == eep2->engine)
                      && (cur_eep.port == eep2->port)) )
                {
                    ++eep2;
                    continue;
                }

                /*
                eeprom@50 {
                    reg = <0x50>; << right-justified 7-bit addr
                    label = "system-vpd"; << arbitrary name
                    compatible = "atmel,24c64"; << use table above
                    status = "ok"; << Opal fills in
                    phandle = <0x10000065>; << auto-filled
                    linux,phandle = <0x10000065>; << Opal fills in
                 }
                */
                dtOffset_t l_eepNode = i_dt->addNode( l_busNode,
                                                      "eeprom",
                                                      eep2->devAddr >> 1 );
                i_dt->addPropertyCell32(l_eepNode, "reg", eep2->devAddr >> 1);
                char l_label[30];
                TARGETING::TYPE l_type = TARGETING::TYPE_NA;
                l_type = eep2->assocTarg->getAttr<TARGETING::ATTR_TYPE>();
                if( (l_type == TARGETING::TYPE_SYS)
                    || (l_type == TARGETING::TYPE_NODE) )
                {
                    sprintf( l_label, "system-vpd" );
                }
                else if( l_type == TARGETING::TYPE_PROC )
                {
                    const char* l_type = "vpd";
                    switch( eep2->device )
                    {
                        case(EEPROM::VPD_PRIMARY):
                            l_type = "proc-vpd";
                            break;
                        case(EEPROM::VPD_BACKUP):
                            l_type = "proc-vpd-backup";
                            break;
                        case(EEPROM::SBE_PRIMARY):
                            l_type = "sbe0";
                            break;
                        case(EEPROM::SBE_BACKUP):
                            l_type = "sbe1";
                            break;
                        default:
                            break;
                    }
                    sprintf( l_label, "%s-%d",
                             l_type,
                             eep2->assocTarg
                             ->getAttr<TARGETING::ATTR_POSITION>() );
                }
                else if( l_type == TARGETING::TYPE_MEMBUF )
                {
                    sprintf( l_label, "memb-vpd-%d",
                             eep2->assocTarg
                             ->getAttr<TARGETING::ATTR_POSITION>() );
                }
                else if( l_type == TARGETING::TYPE_DIMM )
                {
                    sprintf( l_label, "dimm-spd-%d",
                             eep2->assocTarg
                             ->getAttr<TARGETING::ATTR_POSITION>() );
                }
                else
                {
                    sprintf( l_label, "unknown" );
                }
                i_dt->addPropertyString(l_eepNode, "label", l_label);

                // fill in atmel compatible
                const char* l_compat = "unknown";
                bool l_foundit = false;
                for( size_t a = 0;
                     a < (sizeof(atmel_ids)/sizeof(atmel_ids[0]));
                     a++ )
                {
                    if( (atmel_ids[a].byteSize == (KILOBYTE*eep2->sizeKB))
                        || (atmel_ids[a].addrBytes == eep2->addrBytes) )
                    {
                        l_compat = atmel_ids[a].name;
                        l_foundit = true;
                        break;
                    }
                }
                if( !l_foundit )
                {
                    TRACFCOMP( g_trac_devtree, "Could not find matching eeprom device for %s : size=%d,addr=%d", l_label, eep2->sizeKB, eep2->addrBytes );
                }
                i_dt->addPropertyString(l_eepNode, "compatible", l_compat);

                // need to increment the outer loop if we're going to
                //  remove the element it points to
                if( eep == eep2 )
                {
                    ++eep;
                }
                // now remove the device we added so we don't add it again
                eep2 = l_eepromInfo.erase(eep2);
            }
        }
    }

}

void bld_getSideInfo(PNOR::SideId i_side,
                     uint32_t     o_TOCaddress[2],
                     uint8_t    & o_count,
                     bool       & o_isGolden)
{
    errlHndl_t  errhdl = NULL;
    PNOR::SideInfo_t  l_info;

    o_count = 0;
    o_isGolden = false;

    errhdl = getSideInfo (i_side, l_info);
    if (!errhdl)
    {
        // return the valid TOC offsets & count of valid TOCs
        if (PNOR::INVALID_OFFSET != l_info.primaryTOC)
        {
            o_TOCaddress[o_count++] = l_info.primaryTOC;
        }
        if (PNOR::INVALID_OFFSET != l_info.backupTOC)
        {
            o_TOCaddress[o_count++] = l_info.backupTOC;
        }
        o_isGolden      = l_info.isGolden;
    }
    else
    {
        // commit error and return 0 TOC offsets
        errlCommit(errhdl, DEVTREE_COMP_ID);
    }

    return;
}

void bld_fdt_pnor(devTree *   i_dt,
                  dtOffset_t  i_parentNode)
{
    do
    {
        uint32_t l_active[2]    = {PNOR::INVALID_OFFSET,PNOR::INVALID_OFFSET};
        uint32_t l_golden[2]    = {PNOR::INVALID_OFFSET,PNOR::INVALID_OFFSET};
        uint8_t  l_count = 0;
        bool     l_isGolden = false;
        bool     l_goldenFound = false;
        uint8_t  l_goldenCount = 0;
        PNOR::PnorInfo_t l_pnorInfo;

        //Get pnor address and size
        getPnorInfo (l_pnorInfo);

        dtOffset_t l_pnorNode = i_dt->addNode(i_parentNode,
                                              "pnor",
                                              l_pnorInfo.mmioOffset);

        const uint8_t l_isaLinkage = 0; // 0==Mem
        uint32_t pnor_prop[3] = {l_isaLinkage,
                                 l_pnorInfo.mmioOffset,
                                 l_pnorInfo.flashSize};
        i_dt->addPropertyCells32(l_pnorNode, "reg", pnor_prop, 3);

        //Add Working/Active parition
        bld_getSideInfo(PNOR::WORKING,l_active,l_count,l_isGolden);
        if (l_count) // valid TOCs present
        {
            i_dt->addPropertyCells32(l_pnorNode,
                                 "active-image-tocs", l_active, l_count);
            // capture golden
            if (l_isGolden)
            {
                l_golden[0] = l_active[0];
                l_golden[1] = l_active[1];
                l_goldenCount = l_count;
                l_goldenFound = true;
            }
        }

#if CONFIG_PNOR_TWO_SIDE_SUPPORT
        //Add Alternate parition
        uint32_t l_alternate[2] = {PNOR::INVALID_OFFSET,PNOR::INVALID_OFFSET};

        bld_getSideInfo(PNOR::ALTERNATE,l_alternate,l_count,l_isGolden);
        if (l_count) // valid TOCs present
        {
            i_dt->addPropertyCells32(l_pnorNode,
                                 "alternate-image-tocs",l_alternate,l_count);
            // capture golden
            if (l_isGolden)
            {
                l_golden[0] = l_alternate[0];
                l_golden[1] = l_alternate[1];
                l_goldenCount = l_count;
                l_goldenFound = true;
            }
        }
#endif

        //Include golden if there is one
        if (l_goldenFound)
        {
            i_dt->addPropertyCells32(l_pnorNode,
                                 "golden-image-tocs",l_golden,l_goldenCount);
        }

    } while (0);

    return;
}

void bld_xscom_node(devTree * i_dt, dtOffset_t & i_parentNode,
                    const TARGETING::Target * i_pProc,
                    uint32_t i_chipid,
                    bool i_smallTree)
{
    const char* xscomNodeName = "xscom";
    const char* todNodeName = "chiptod";
    const char* pciNodeName = "pbcq";

    // Grab a system object to work with
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);

    uint64_t l_xscomBaseAddr =
      sys->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

    /**********************************************************/
    /*                   Xscom node                           */
    /**********************************************************/
    //@todo-Fix for P9-RTC:128077
    uint64_t l_xscomAddr = l_xscomBaseAddr +
      (static_cast<uint64_t>(i_chipid) << XSCOM_CHIP_SHIFT);

    dtOffset_t xscomNode = i_dt->addNode(i_parentNode, xscomNodeName,
                                         l_xscomAddr);

    i_dt->addPropertyCell32(xscomNode, "#address-cells", 1);
    i_dt->addPropertyCell32(xscomNode, "#size-cells", 1);
    i_dt->addProperty(xscomNode, "scom-controller");
    const char* xscom_compatStrs[] = {"ibm,xscom","ibm,power8-xscom",NULL};
    i_dt->addPropertyStrings(xscomNode, "compatible", xscom_compatStrs);

    i_dt->addPropertyCell32(xscomNode, "ibm,chip-id", i_chipid);

    uint64_t xscom_prop[2] = { l_xscomAddr,  THIRTYTWO_GB};
    i_dt->addPropertyCells64(xscomNode, "reg", xscom_prop, 2);

    // Do not need anything else for small tree
    if (i_smallTree)
    {
        return;
    }

    // Add proc chip ECIDs
    ATTR_ECID_type ecid;
    i_pProc->tryGetAttr<ATTR_ECID>(ecid);
    char ecid_ascii[33];
    sprintf(ecid_ascii, "%.16llX%.16llX", ecid[0], ecid[1]);
    i_dt->addPropertyString(xscomNode, "ecid", ecid_ascii);
    CPPASSERT(sizeof(ATTR_ECID_type) == 16);

    /*PSI Host Bridge*/
    uint32_t l_psiInfo = 0x2010900; /*PSI Host Bridge Scom addr*/
    dtOffset_t psiNode = i_dt->addNode(xscomNode, "psihb", l_psiInfo);
    const char* psi_compatStrs[] = {"ibm,power8-psihb-x",
    "ibm,psihb-x", NULL};
    i_dt->addPropertyStrings(psiNode, "compatible", psi_compatStrs);
    uint32_t psi_prop[2] = { l_psiInfo, 0x20 }; //# of scoms in range
    i_dt->addPropertyCells32(psiNode, "reg", psi_prop, 2);
    i_dt->addPropertyString(psiNode, "status", "ok");

    /*ChipTod*/
    uint32_t l_todInfo = 0x40000; /*Chip tod Scom addr*/
    dtOffset_t todNode = i_dt->addNode(xscomNode, todNodeName, l_todInfo);
    const char* tod_compatStrs[] = {"ibm,power-chiptod",
    "ibm,power8-chiptod", NULL};
    i_dt->addPropertyStrings(todNode, "compatible", tod_compatStrs);
    uint32_t tod_prop[2] = { l_todInfo, 0x34 }; //# of scoms in range
    i_dt->addPropertyCells32(todNode, "reg", tod_prop, 2);

    //Mark TOD pri/sec
    uint8_t l_role = i_pProc->getAttr<ATTR_TOD_ROLE>();
    if(l_role & TARGETING::TOD_ROLE_PRIMARY)
    {
        i_dt->addProperty(todNode, "primary");
    }
    if(l_role & TARGETING::TOD_ROLE_SECONDARY)
    {
        i_dt->addProperty(todNode, "secondary");
    }

    if(i_chipid == 0x0) //Master chip
    {
        uint32_t l_lpcInfo = 0xB0020; /*ECCB FW addr*/
        dtOffset_t lpcNode = i_dt->addNode(xscomNode,"isa",l_lpcInfo);
        i_dt->addPropertyString(lpcNode, "compatible", "ibm,power8-lpc");
        uint32_t lpc_prop[2] = { l_lpcInfo, 0x4 }; //# of scoms in range
        i_dt->addPropertyCells32(lpcNode, "reg", lpc_prop, 2);
        i_dt->addPropertyCell32(lpcNode, "#address-cells", 2);
        i_dt->addPropertyCell32(lpcNode, "#size-cells", 1);

        bld_fdt_pnor (i_dt, lpcNode);

    }

    /*NX*/
    uint32_t l_nxInfo = 0x2010000; /*NX Scom addr*/
    dtOffset_t nxNode = i_dt->addNode(xscomNode, "nx", l_nxInfo);
    const char* nx_compatStrs[] = {"ibm,power-nx",
    "ibm,power8-nx", NULL};
    i_dt->addPropertyStrings(nxNode, "compatible", nx_compatStrs);
    uint32_t nx_prop[2] = { l_nxInfo, 0x4000 }; //# of scoms in range
    i_dt->addPropertyCells32(nxNode, "reg", nx_prop, 2);


    /*PCIE*/
    uint8_t l_phbActive =
        i_pProc->getAttr<TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>();
    TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_type l_laneEq = {{0}};
    assert(i_pProc->tryGetAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION>(
        l_laneEq));

    TRACFCOMP( g_trac_devtree, "Chip %X PHB Active mask %X",
               i_chipid, l_phbActive);

    for(uint32_t l_phb =0; l_phb < MAX_PHBs; l_phb++)
    {
        if(!(l_phbActive & (PHB0_MASK>>l_phb)))
        {
            continue;
        }

        TRACFCOMP( g_trac_devtree, "Adding PHB %d", l_phb);

        /*PHB is active, add to Xscom map*/
        uint32_t l_peInfo   = 0x02012000 + (l_phb * 0x400);
        uint32_t l_pciInfo  = 0x09012000 + (l_phb * 0x400);
        uint32_t l_spciInfo = 0x09013c00 + (l_phb * 0x40);
        dtOffset_t pcieNode = i_dt->addNode(xscomNode,pciNodeName,l_peInfo);
        const char* pcie_compatStrs[] = {"ibm,power8-pbcq", NULL};
        i_dt->addPropertyStrings(pcieNode, "compatible", pcie_compatStrs);
        uint32_t pcie_prop[6] = { l_peInfo, 0x20, //# of scoms in range
        l_pciInfo, 0x5, //# of scoms in range
        l_spciInfo, 0x15}; //# of scoms in range
        i_dt->addPropertyCells32(pcieNode, "reg", pcie_prop, 6);
        i_dt->addPropertyCell32(pcieNode, "ibm,phb-index", l_phb);
        i_dt->addProperty(pcieNode, "ibm,use-ab-detect");
        i_dt->addPropertyCells32(pcieNode, "ibm,lane-eq",
            reinterpret_cast<uint32_t*>(l_laneEq[l_phb]),
            (sizeof(l_laneEq[l_phb])/sizeof(uint32_t)));
    }

    /*I2C Masters*/
    add_i2c_info( i_pProc, i_dt, xscomNode );

}

uint32_t bld_l3_node(devTree * i_dt, dtOffset_t & i_parentNode,
                     uint32_t i_pir)
{
    uint32_t l3Id = i_pir | L3_HDR;

    /* Build L3 Cache information */
    dtOffset_t l3Node = i_dt->addNode(i_parentNode, "l3-cache",l3Id);
    i_dt->addPropertyString(l3Node, "device_type", "cache");
    i_dt->addPropertyCell32(l3Node, "reg", l3Id);
    i_dt->addProperty(l3Node, "cache-unified");
    i_dt->addPropertyCell32(l3Node, "d-cache-sets", 0x8);
    i_dt->addPropertyCell32(l3Node, "i-cache-sets", 0x8);
    i_dt->addPropertyCell32(l3Node, "d-cache-size", 0x800000); //8MB
    i_dt->addPropertyCell32(l3Node, "i-cache-size", 0x800000); //8MB
    i_dt->addPropertyString(l3Node, "status", "okay");

    return i_dt->getPhandle(l3Node);
}

uint32_t bld_l2_node(devTree * i_dt, dtOffset_t & i_parentNode,
                     uint32_t i_pir, uint32_t i_nextCacheHandle)
{
    uint32_t l2Id = i_pir | L2_HDR;

    /* Build l2 Cache information */
    dtOffset_t l2Node = i_dt->addNode(i_parentNode, "l2-cache",l2Id);
    i_dt->addPropertyString(l2Node, "device_type", "cache");
    i_dt->addPropertyCell32(l2Node, "reg", l2Id);
    i_dt->addProperty(l2Node, "cache-unified");
    i_dt->addPropertyCell32(l2Node, "d-cache-sets", 0x8);
    i_dt->addPropertyCell32(l2Node, "i-cache-sets", 0x8);
    i_dt->addPropertyCell32(l2Node, "d-cache-size", 0x80000); //512KB
    i_dt->addPropertyCell32(l2Node, "i-cache-size", 0x80000); //512KB
    i_dt->addPropertyString(l2Node, "status", "okay");
    i_dt->addPropertyCell32(l2Node, "next-level-cache", i_nextCacheHandle);


    return i_dt->getPhandle(l2Node);
}

uint32_t bld_cpu_node(devTree * i_dt, dtOffset_t & i_parentNode,
                      const TARGETING::Target * i_ex,
                      PIR_t i_pir, uint32_t i_chipId,
                      uint32_t i_nextCacheHandle)
{
    /*
     * The following node must exist for each *core* in the system. The unit
     * address (number after the @) is the hexadecimal HW CPU number (PIR value)
     * of thread 0 of that core.
     */

    uint32_t paFeatures[2] = { 0x0600f63f, 0xc70080c0 };
    uint32_t pageSizes[4] = { 0xc, 0x10, 0x18, 0x22 };
    uint32_t segmentSizes[4] = { 0x1c, 0x28, 0xffffffff, 0xffffffff };
    uint32_t segmentPageSizes[] =
    {
        12, 0x0, 3,   /* 4k SLB page size, L,LP = 0,x1, 3 page size encodings */
        12, 0x0,      /* 4K PTE page size, L,LP = 0,x0 */
        16, 0x7,      /* 64K PTE page size, L,LP = 1,x7 */
        24, 0x38,     /* 16M PTE page size, L,LP = 1,x38 */
        16, 0x110, 2, /* 64K SLB page size, L,LP = 1,x1, 2 page size encodings*/
        16, 0x1,      /* 64K PTE page size, L,LP = 1,x1 */
        24, 0x8,      /* 16M PTE page size, L,LP = 1,x8 */
        20, 0x130, 1, /* 1M SLB page size, L,LP = 1,x3, 1 page size encoding */
        20, 0x2,      /* 1M PTE page size, L,LP = 1,x2 */
        24, 0x100, 1, /* 16M SLB page size, L,LP = 1,x0, 1 page size encoding */
        24, 0x0,      /* 16M PTE page size, L,LP = 1,x0 */
        34, 0x120, 1, /* 16G SLB page size, L,LP = 1,x2, 1 page size encoding */
        34, 0x3       /* 16G PTE page size, L,LP = 1,x3 */
    };


    dtOffset_t cpuNode = i_dt->addNode(i_parentNode, "PowerPC,POWER8",
                                       i_pir.word);
    i_dt->addPropertyString(cpuNode, "device_type", "cpu");
    i_dt->addProperty(cpuNode, "64-bit");
    i_dt->addProperty(cpuNode, "32-64-bridge");
    i_dt->addProperty(cpuNode, "graphics");
    i_dt->addProperty(cpuNode, "general-purpose");
    i_dt->addPropertyString(cpuNode, "status", "okay");
    i_dt->addPropertyCell32(cpuNode, "reg", i_pir.word);
    i_dt->addPropertyCell32(cpuNode, "ibm,pir", i_pir.word);
    i_dt->addPropertyCell32(cpuNode, "ibm,chip-id", i_chipId);

    uint32_t numThreads = 0;
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

    uint32_t interruptServerNum[THREADPERCORE];
    for(size_t i = 0; i < THREADPERCORE ; i++)
    {
        if (en_threads & (0x8000000000000000 >> i))
        {
            i_pir.threadId = i;
            interruptServerNum[numThreads++] = i_pir.word;
        }
    }
    i_dt->addPropertyCells32(cpuNode, "ibm,ppc-interrupt-server#s",
                             interruptServerNum, numThreads);

    /* Fill in the actual PVR of chip -- it is only a 32 bit reg*/
    uint32_t l_pvr = mmio_pvr_read() & 0xFFFFFFFF;
    i_dt->addPropertyCell32(cpuNode, "cpu-version", l_pvr);

    i_dt->addPropertyCells32(cpuNode, "ibm,processor-segment-sizes",
                             segmentSizes,
                             sizeof(segmentSizes) / sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,processor-page-sizes",
                             pageSizes,
                             sizeof(pageSizes) / sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,segment-page-sizes",
                             segmentPageSizes,
                             sizeof(segmentPageSizes)/sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,pa-features",
                             paFeatures,
                             sizeof(paFeatures)/sizeof(uint32_t));

    i_dt->addPropertyCell32(cpuNode, "ibm,slb-size", 32);
    i_dt->addPropertyCell32(cpuNode, "ibm,dfp", 1);
    i_dt->addPropertyCell32(cpuNode, "ibm,vmx", 2);
    i_dt->addPropertyCell32(cpuNode, "ibm,purr", 1);
    i_dt->addPropertyCell32(cpuNode, "ibm,spurr", 1);

    //Set core clock freq
    uint64_t freq = 0;

#ifdef CONFIG_HTMGT
    if(sys->getAttr<TARGETING::ATTR_HTMGT_SAFEMODE>())
    {
        // Safe mode on, OCC failed to load.  Set safe freq
        freq = sys->getAttr<TARGETING::ATTR_BOOT_FREQ_MHZ>();
    }
    else
    {
        // Safe mode off, set nominal freq
        freq = sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
    }
#elif CONFIG_SET_NOMINAL_PSTATE
    // Set nominal core freq if CONFIG_SET_NOMINAL_PSTATE is enabled
    freq = sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
#else
    // Else, set safe core freq
    freq = sys->getAttr<TARGETING::ATTR_BOOT_FREQ_MHZ>();
#endif

    freq *= MHZ;

    uint32_t ex_freq[2] = {static_cast<uint32_t>(freq >> 32),
    static_cast<uint32_t>(freq & 0xFFFFFFFF)};
    if(ex_freq[0] == 0) //Only create if fits into 32 bits
    {
        i_dt->addPropertyCell32(cpuNode, "clock-frequency", ex_freq[1]);
    }
    i_dt->addPropertyCells32(cpuNode, "ibm,extended-clock-frequency",
                             ex_freq, 2);

    uint32_t timebase_freq[2] = {0, 512000000};
    i_dt->addPropertyCell32(cpuNode, "timebase-frequency", timebase_freq[1]);
    i_dt->addPropertyCells32(cpuNode, "ibm,extended-timebase-frequency",
                             timebase_freq, 2);


    i_dt->addPropertyCell32(cpuNode, "reservation-granule-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "d-tlb-size", 0x800);
    i_dt->addPropertyCell32(cpuNode, "i-tlb-size", 0x0);
    i_dt->addPropertyCell32(cpuNode, "tlb-size", 0x800);
    i_dt->addPropertyCell32(cpuNode, "d-tlb-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "i-tlb-sets", 0x0);
    i_dt->addPropertyCell32(cpuNode, "tlb-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "d-cache-block-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "i-cache-block-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "d-cache-size", 0x10000);
    i_dt->addPropertyCell32(cpuNode, "i-cache-size", 0x8000);
    i_dt->addPropertyCell32(cpuNode, "i-cache-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "d-cache-sets", 0x8);
    i_dt->addPropertyCell64(cpuNode, "performance-monitor", 0x1);
    i_dt->addPropertyCell32(cpuNode, "next-level-cache", i_nextCacheHandle);

    return i_dt->getPhandle(cpuNode);
}

uint32_t bld_intr_node(devTree * i_dt, dtOffset_t & i_parentNode,
                      const TARGETING::Target * i_ex,
                      PIR_t i_pir)

{
    /*
     * Interrupt presentation controller (ICP) nodes
     *
     * There is some flexibility as to how many of these are presents since
     * a given node can represent multiple ICPs. When generating from HDAT we
     * chose to create one per core
     */

    uint64_t l_ibase = INTR::getIntpAddr(i_ex, 0);     //IBASE ADDRESS

    dtOffset_t intNode = i_dt->addNode(i_parentNode, "interrupt-controller",
                                       l_ibase);

    const char* intr_compatStrs[] = {"ibm,ppc-xicp", "ibm,power8-xicp",NULL};
    i_dt->addPropertyStrings(intNode, "compatible", intr_compatStrs);
    i_dt->addProperty(intNode,"interrupt-controller");
    i_dt->addPropertyCell32(intNode, "#address-cells", 0);
    i_dt->addPropertyCell32(intNode, "#interrupt-cells", 1);
    i_dt->addPropertyString(intNode, "device_type",
                            "PowerPC-External-Interrupt-Presentation");

    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();
    uint32_t numThreads = 0;

    uint64_t intr_prop[THREADPERCORE][2];
    for(size_t i=0; i < THREADPERCORE; i++)
    {
        if (en_threads & (0x8000000000000000 >> i))
        {
            intr_prop[numThreads][0] = INTR::getIntpAddr(i_ex, i);
            intr_prop[numThreads][1] = 0x1000;
            numThreads++;
        }
    }
    i_dt->addPropertyCells64(intNode, "reg",
                             reinterpret_cast<uint64_t*>(intr_prop),
                             numThreads * 2);

    uint32_t int_serv[2] = { i_pir.word, numThreads};
    i_dt->addPropertyCells32(intNode, "ibm,interrupt-server-ranges",
                             int_serv, 2);

    return i_dt->getPhandle(intNode);
}


void add_reserved_mem(devTree * i_dt,
                      std::vector<homerAddr_t>& i_homerAddr,
                      uint64_t i_extraAddr[],
                      uint64_t i_extraSize[],
                      const char* i_extraStr[],
                      uint64_t i_extraCnt)
{
    /*
     * TODO RTC: 131056 remove non-node reserved memory entries
     *     - reserved-names and reserved-ranges
     *     - reserved map ??
     *     hints are provided for the scope of code to remove
     * The reserved-names and reserve-ranges properties work hand in hand.
     * The first one is a list of strings providing a "name" for each entry
     * in the second one using the traditional "vendor,name" format.
     *
     * The reserved-ranges property contains a list of ranges, each in the
     * form of 2 cells of address and 2 cells of size (64-bit x2 so each
     * entry is 4 cells) indicating regions of memory that are reserved
     * and must not be overwritten by skiboot or subsequently by the Linux
     * Kernel.
     *
     * Corresponding entries must also be created in the "reserved map" part
     * of the flat device-tree (which is a binary list in the header of the
     * fdt).
     * **** remove to here
     *
     * Reserved memory is passed in a node-based format. An instance
     * number distinquishes homer regions.
     *
     * Unless a component (skiboot or Linux) specifically knows about a region
     * (usually based on its name) and decides to change or remove it, all
     * these regions are passed as-is to Linux and to subsequent kernels
     * across kexec and are kept preserved.
     */

    dtOffset_t rootNode = i_dt->findNode("/");

    size_t l_num = i_homerAddr.size();

    // 131056: Won't need these
    const char* homerStr = "ibm,slw-occ-image";
    const char* reserve_strs[l_num+i_extraCnt+1];
    uint64_t ranges[l_num+i_extraCnt][2];
    uint64_t cell_count = sizeof(ranges) / sizeof(uint64_t);
    uint64_t res_mem_addrs[l_num+i_extraCnt];
    uint64_t res_mem_sizes[l_num+i_extraCnt];

    // create the nodes for the node based format
    dtOffset_t rootMemNode = i_dt->addNode(rootNode, "ibm,hostboot");
    i_dt->addPropertyCell32(rootMemNode, "#address-cells", 2);
    i_dt->addPropertyCell32(rootMemNode, "#size-cells", 2);
    dtOffset_t reservedMemNode = i_dt->addNode(rootMemNode, "reserved-memory");
    i_dt->addPropertyCell32(reservedMemNode, "#address-cells", 2);
    i_dt->addPropertyCell32(reservedMemNode, "#size-cells", 2);
    i_dt->addProperty(reservedMemNode, "ranges");

    for(size_t i = 0; i<l_num; i++)
    {
        uint64_t l_homerAddr = i_homerAddr[i].first;
        uint64_t l_homerInstance = i_homerAddr[i].second;
        TRACFCOMP( g_trac_devtree, "Reserved Region %s @ %lx, %lx instance %d",
                       homerStr,
                       l_homerAddr,
                       VMM_HOMER_INSTANCE_SIZE,
                       l_homerInstance);

        // 131056: Won't need these
        reserve_strs[i] = homerStr;
        ranges[i][0] = l_homerAddr;
        ranges[i][1] = VMM_HOMER_INSTANCE_SIZE;
        res_mem_addrs[i] = l_homerAddr;
        res_mem_sizes[i] = VMM_HOMER_INSTANCE_SIZE;

        // add node style inclulding homer instance.
        dtOffset_t homerNode = i_dt->addNode(reservedMemNode,
                                               "ibm,homer-image",
                                               l_homerAddr);
        uint64_t propertyCells[2]={l_homerAddr, VMM_HOMER_INSTANCE_SIZE};
        i_dt->addPropertyCells64(homerNode, "reg", propertyCells, 2);
        const char* propertyStrs[] = {"ibm,homer-image", NULL};
        i_dt->addPropertyStrings(homerNode, "ibm,prd-label",propertyStrs);
        i_dt->addPropertyCell32(homerNode, "ibm,prd-instance",
                                            l_homerInstance);
    }

    for(size_t i = 0; i < i_extraCnt; i++)
    {
        if (i_extraAddr[i])
        {
            TRACFCOMP( g_trac_devtree, "Reserved Region %s @ %lx, %lx",
                       i_extraStr[i], i_extraAddr[i], i_extraSize[i]);

            // 131056: Won't need these
            reserve_strs[l_num] = i_extraStr[i];
            ranges[l_num][0] = i_extraAddr[i];
            ranges[l_num][1] = i_extraSize[i];
            res_mem_addrs[l_num] = i_extraAddr[i];
            res_mem_sizes[l_num] = i_extraSize[i];
            l_num++;

            // add node style entry
            dtOffset_t extraNode = i_dt->addNode(reservedMemNode,
                                               i_extraStr[i],
                                               i_extraAddr[i]);
            uint64_t propertyCells[2]={i_extraAddr[i],i_extraSize[i]};
            i_dt->addPropertyCells64(extraNode, "reg", propertyCells, 2);
            const char* propertyStrs[] = {i_extraStr[i], NULL};
            i_dt->addPropertyStrings(extraNode, "ibm,prd-label",propertyStrs);
        }
        else
        {
            cell_count -= sizeof(ranges[0]);
        }
    }
    // add node style occ common node
    const char* occStr = "ibm,occ-common-area";
    uint64_t l_occCommonPhysAddr = getOccCommonAddr();
    uint64_t l_occCommonPhysSize = VMM_OCC_COMMON_SIZE;
    TRACFCOMP( g_trac_devtree, "Reserved Region %s @ %lx, %lx",
                       occStr, l_occCommonPhysAddr, l_occCommonPhysSize);
    dtOffset_t occNode = i_dt->addNode(reservedMemNode,
                                       occStr,
                                       l_occCommonPhysAddr);
    uint64_t propertyCells[2]={l_occCommonPhysAddr, l_occCommonPhysSize};
    i_dt->addPropertyCells64(occNode, "reg", propertyCells, 2);
    const char* propertyStrs[] = {occStr, NULL};
    i_dt->addPropertyStrings(occNode, "ibm,prd-label",propertyStrs);

    // 131056: Won't need the rest
    reserve_strs[l_num] = NULL;
    i_dt->addPropertyStrings(rootNode, "reserved-names", reserve_strs);
    i_dt->addPropertyCells64(rootNode, "reserved-ranges",
                             reinterpret_cast<uint64_t*>(ranges),
                             cell_count);

    // added per comment from Dean Sanner
    // cell_count has limit of DT_MAX_MEM_RESERVE  = 16. Is this enough
    // for all processors + 1 vpd area + 1 target area?
    i_dt->populateReservedMem(res_mem_addrs, res_mem_sizes, cell_count);
}

void load_hbrt_image(uint64_t& io_address)
{
    errlHndl_t l_errl = NULL;

    do
    {

        PNOR::SectionInfo_t l_pnorInfo;
        l_errl = getSectionInfo( PNOR::HB_RUNTIME , l_pnorInfo);
        if (l_errl) { break; }

            // Find start of image.
            //     For Secureboot we might need to deal with the header but
            //     for now that is hidden by the PNOR-RP.
        uint64_t image_start = l_pnorInfo.vaddr;

            // The "VFS_LAST_ADDRESS" variable is 2 pages in.
        uint64_t vfs_last_address =
                *reinterpret_cast<uint64_t*>(image_start + 2*PAGE_SIZE);

            // At the end of the image are the relocations, get the number.
        uint64_t relocate_count =
                *reinterpret_cast<uint64_t*>(image_start + vfs_last_address);

            // Sum up the total size.
        uint64_t image_size = vfs_last_address +
                              (relocate_count+1)*sizeof(uint64_t);

        TRACFCOMP(g_trac_devtree, "HBRT image: start = %lx, size = %lx",
                  image_start, image_size);
        io_address -= ALIGN_PAGE(image_size);
        // Align to 64KB for Opal
        io_address = ALIGN_DOWN_X(io_address,64*KILOBYTE);

            // Copy image.
        void* memArea = mm_block_map(reinterpret_cast<void*>(io_address),
                                     ALIGN_PAGE(image_size));
        memcpy(memArea, reinterpret_cast<void*>(image_start), image_size);
        mm_block_unmap(memArea);

    } while (0);

    if (l_errl)
    {
        io_address = 0;
        errlCommit(l_errl, DEVTREE_COMP_ID);
    }
}


errlHndl_t bld_fdt_system(devTree * i_dt, bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    dtOffset_t rootNode = i_dt->findNode("/");

    //Common settings
    /* Define supported power states -- options:
                         nap, deep-sleep, fast-sleep, rvwinkle*/
    const char* pmode_compatStrs[] = {"nap", "fast-sleep", "rvwinkle", NULL};
    i_dt->addPropertyStrings(rootNode, "ibm,enabled-idle-states",
                             pmode_compatStrs);

    // Nothing to do for small trees currently.
    if (!i_smallTree)
    {
        /* Add devtree property for checkstop escalation  */
        bld_swCheckstopFir(i_dt,rootNode);

        //===== compatible =====
        /* Fetch the MRW-defined compatible model from attributes */
        ATTR_OPAL_MODEL_type l_model = {0};
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        sys->tryGetAttr<TARGETING::ATTR_OPAL_MODEL>(l_model);

        /* Add compatibility value */
        const char* l_compats[] = { "ibm,powernv", l_model, NULL };
        i_dt->addPropertyStrings(rootNode, "compatible", l_compats);

        //===== model =====
        /* Add system model value
           Depending on the vintage of the planar VPD, there are 3 places
           we need to look for this data.
           1) OSYS:MM
           2) OPFR:DR
           3) Default to 'unknown'
         */
        bool foundvpd = false;
        TARGETING::TargetHandleList l_nodeTargetList;
        PredicateCTM predNode(CLASS_ENC, TYPE_NODE);
        PredicateHwas predFunctional;
        predFunctional.functional(true);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode).push(&predFunctional).And();

        targetService().getAssociated(l_nodeTargetList, sys,
                    TargetService::CHILD, TargetService::IMMEDIATE,
                    &nodeCheckExpr);

        //if can't find a node for the PVPD, default to unknown
        if (l_nodeTargetList.size())
        {
            TARGETING::Target * l_pNode = l_nodeTargetList[0];
            size_t vpdSize = 0x0;

            // Note: First read with NULL for o_buffer sets vpdSize to the
            // correct length
            errhdl = deviceRead( l_pNode,
                                 NULL,
                                 vpdSize,
                                 DEVICE_PVPD_ADDRESS( PVPD::OSYS,
                                                      PVPD::MM ));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't get OSYS:MM size for HUID=0x%.8X",
                          TARGETING::get_huid(l_pNode));

                // Try the OPFR record
                errlHndl_t opfr_errhdl = deviceRead( l_pNode,
                                           NULL,
                                           vpdSize,
                                           DEVICE_PVPD_ADDRESS( PVPD::OPFR,
                                                                PVPD::DR ));
                if(opfr_errhdl)
                {
                    TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't get OPFR:DR size for HUID=0x%.8X",
                              TARGETING::get_huid(l_pNode));
                    delete opfr_errhdl; //delete OPFR log, VPD is just bad
                }
                else
                {
                    delete errhdl; //ignore lack of OSYS due to older vpd
                    errhdl = NULL;
                    char drBuf[vpdSize+1];
                    memset(&drBuf, 0x0, (vpdSize+1)); //null terminated str
                    errhdl = deviceRead( l_pNode,
                                         reinterpret_cast<void*>( &drBuf ),
                                         vpdSize,
                                         DEVICE_PVPD_ADDRESS( PVPD::OPFR,
                                                              PVPD::DR ));

                    if(errhdl)
                    {
                        TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't read OPFR:DR for HUID=0x%.8X",
                                  TARGETING::get_huid(l_pNode));
                    }
                    else
                    {
                        foundvpd = true;
                        i_dt->addPropertyString(rootNode, "model", drBuf);
                    }
                }
            }
            else
            {
                char mmBuf[vpdSize+1];
                memset(&mmBuf, 0x0, (vpdSize+1)); //ensure null terminated str
                errhdl = deviceRead( l_pNode,
                                     reinterpret_cast<void*>( &mmBuf ),
                                     vpdSize,
                                     DEVICE_PVPD_ADDRESS( PVPD::OSYS,
                                                          PVPD::MM ));

                if(errhdl)
                {
                    TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't read OSYS:MM for HUID=0x%.8X",
                              TARGETING::get_huid(l_pNode));
                }
                else
                {
                    foundvpd = true;
                    i_dt->addPropertyString(rootNode, "model", mmBuf);
                }
            }
        }

        // just commit any errors we get, this isn't critical
        if( errhdl )
        {
            errlCommit(errhdl, DEVTREE_COMP_ID); //commit original OSYS log
        }

        if( !foundvpd ) //chassis info not found, default to unknown
        {
            TRACFCOMP(g_trac_devtree,ERR_MRK" VPD not found, model defaulted to unknown");
            i_dt->addPropertyString(rootNode, "model", "unknown");
        }

        //===== system-id =====
        /* Add system-id value
           1) OSYS:SS
           2) Default to 'unavailable'
         */
        foundvpd = false;
        if( l_nodeTargetList.size() )
        {
            TARGETING::Target * l_pNode = l_nodeTargetList[0];
            size_t vpdSize = 0x0;

            // Note: First read with NULL for o_buffer sets vpdSize to the
            // correct length
            errhdl = deviceRead( l_pNode,
                                 NULL,
                                 vpdSize,
                                 DEVICE_PVPD_ADDRESS( PVPD::OSYS,
                                                      PVPD::SS ));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't get OSYS:SS size for HUID=0x%.8X",
                          TARGETING::get_huid(l_pNode));
                // Note - not supporting old vpd versions without OSYS here
            }
            else
            {
                char ssBuf[vpdSize+1];
                memset(&ssBuf, 0x0, (vpdSize+1)); //ensure null terminated str
                errhdl = deviceRead( l_pNode,
                                     reinterpret_cast<void*>( &ssBuf ),
                                     vpdSize,
                                     DEVICE_PVPD_ADDRESS( PVPD::OSYS,
                                                          PVPD::SS ));

                if(errhdl)
                {
                    TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't read OSYS:SS for HUID=0x%.8X",
                              TARGETING::get_huid(l_pNode));
                }
                else
                {
                    foundvpd = true;
                    i_dt->addPropertyString(rootNode, "system-id", ssBuf);
                }
            }
        }
        // just delete any errors we get, this isn't critical
        if( errhdl )
        {
            // since there are old parts out in the wild without
            //  this data, we can't log an error
            delete errhdl;
            errhdl = NULL;
        }
        if( !foundvpd ) //serial number not found, default to unavailable
        {
            i_dt->addPropertyString(rootNode, "system-id", "unavailable");
        }
    }

    return errhdl;
}


errlHndl_t bld_fdt_cpu(devTree * i_dt,
                       std::vector<homerAddr_t>& o_homerRegions,
                       bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    /* Find the / node and add a cpus node under it. */
    dtOffset_t rootNode = i_dt->findNode("/");
    dtOffset_t cpusNode = NULL;
    if (!i_smallTree)
    {
        cpusNode = i_dt->addNode(rootNode, "cpus");

        /* Add the # address & size cell properties to /cpus. */
        i_dt->addPropertyCell32(cpusNode, "#address-cells", 1);
        i_dt->addPropertyCell32(cpusNode, "#size-cells", 0);
    }

    // Get all functional proc chip targets
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for (size_t proc = 0; (!errhdl) && (proc < l_procTargetList.size()); proc++)
    {
        const TARGETING::Target * l_pProc = l_procTargetList[proc];

        uint32_t l_chipid = getProcChipId(l_pProc);

        // For small tree, only add xscom if master processor
        TARGETING::Target* l_pMasterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProc);
        if((!i_smallTree) || (l_pProc == l_pMasterProc) )
        {
            bld_xscom_node(i_dt, rootNode, l_pProc, l_chipid, i_smallTree);
        }
        if (i_smallTree) // nothing else for small tree
        {
            continue;
        }

        //Each processor will have a HOMER image that needs
        //to be reserved -- save it away
        o_homerRegions.push_back(getHomerPhysAddr(l_pProc));

        TARGETING::TargetHandleList l_corelist;
        getChildChiplets( l_corelist, l_pProc, TYPE_CORE );
        for (size_t core = 0; core < l_corelist.size(); core++)
        {
            const TARGETING::Target * l_core = l_corelist[core];
            if(l_core->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
            {
                continue; //Not functional
            }

            /* Proc ID Reg is GG GGCC CPPP PPTT Where
                              GGGG           is Group number
                                  CCC        is Chip
                                     PPPPP   is the core number
                                          TT is Thread num
             */
            uint32_t l_coreNum = l_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            PIR_t pir(0);
            pir.groupId = PIR_t::groupFromChipId(l_chipid);
            pir.chipId = PIR_t::chipFromChipId(l_chipid);
            pir.coreId = l_coreNum;

            TRACFCOMP( g_trac_devtree, "Added pir[%x] chipid 0x%x core %d",
                       pir.word, l_chipid, l_coreNum );

            cpusNode = i_dt->findNode("/cpus");

            uint32_t l3pHandle = bld_l3_node(i_dt, cpusNode, pir.word);
            uint32_t l2pHandle = bld_l2_node(i_dt, cpusNode, pir.word,
                                             l3pHandle);
            bld_cpu_node(i_dt, cpusNode, l_core, pir, l_chipid, l2pHandle);

            rootNode = i_dt->findNode("/");
            bld_intr_node(i_dt, rootNode, l_core, pir);
        }
    }

    return errhdl;
}

errlHndl_t bld_fdt_reserved_mem(devTree * i_dt,
                                std::vector<homerAddr_t>& i_homerRegions,
                                bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    // VPD
    uint64_t l_vpd_addr = 0;

    errhdl = VPD::vpd_load_rt_image(l_vpd_addr);

    // Targeting
    uint64_t l_targ_addr = l_vpd_addr;
    TARGETING::AttrRP::save(l_targ_addr);

    // HBRT image
    uint64_t l_hbrt_addr = l_targ_addr;
    load_hbrt_image(l_hbrt_addr);

    uint64_t l_extra_addrs[] = { l_vpd_addr, l_targ_addr, l_hbrt_addr };
    uint64_t l_extra_sizes[] = { VMM_RT_VPD_SIZE,
                                 l_vpd_addr - l_targ_addr,
                                 l_targ_addr - l_hbrt_addr};
    const char* l_extra_addrs_str[] =
                    { "ibm,hbrt-vpd-image" ,
                      "ibm,hbrt-target-image",
                      "ibm,hbrt-code-image" };
    size_t l_extra_addr_cnt = sizeof(l_extra_addrs) / sizeof(uint64_t);

    //Add in reserved memory for HOMER images and HBRT sections.
    add_reserved_mem(i_dt,
                     i_homerRegions,
                     l_extra_addrs,
                     l_extra_sizes,
                     l_extra_addrs_str,
                     l_extra_addr_cnt);

    return errhdl;

}

errlHndl_t bld_fdt_mem(devTree * i_dt, bool i_smallTree)
{
    // Nothing to do for small trees currently.
    if (i_smallTree) { return NULL; }

    errlHndl_t errhdl = NULL;
    bool rc;

    /*
     * The "memory" nodes represent physical memory in the system. They
     * do not represent DIMMs, memory controllers or Centaurs, thus will
     * be expressed separately.
     *
     * In order to be able to handle affinity propertly, we require that
     * a memory node is created for each range of memory that has a different
     * "affinity", which in practice means for each chip since we don't
     * support memory interleaved across multiple chips on P8.
     *
     * Additionally, it is *not* required that one chip = one memory node,
     * it is perfectly acceptable to break down the memory of one chip into
     * multiple memory nodes (typically skiboot does that if the two MCs
     * are not interlaved).
     */

    do
    {
        /* Find the / node and add a memory node(s) under it. */
        dtOffset_t rootNode = i_dt->findNode("/");

        // Grab a system object to work with
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for ( size_t proc = 0;
              (!errhdl) && (proc < l_cpuTargetList.size()); proc++ )
        {
            const TARGETING::Target * l_pProc = l_cpuTargetList[proc];

            uint64_t l_bases[8] = {0,};
            uint64_t l_sizes[8] = {0,};
            rc = l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_bases);
            if(!rc)
            {
                /*@
                 * @errortype
                 * @reasoncode       DEVTREE::RC_ATTR_MEMBASE_GET_FAIL
                 * @moduleid         DEVTREE::MOD_DEVTREE_BLD_MEM
                 * @userdata1        Return code from ATTR_GET
                 * @userdata2        Attribute Id that failed
                 * @devdesc          Error retrieving attribute
                 */
                errhdl=new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_DEVTREE_BLD_MEM,
                                               RC_ATTR_MEMBASE_GET_FAIL,
                                               rc,
                                               ATTR_PROC_MEM_BASES);
                break;
            }

            rc = l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_sizes);
            if(!rc)
            {
                /*@
                 * @errortype
                 * @reasoncode       DEVTREE::RC_ATTR_MEMSIZE_GET_FAIL
                 * @moduleid         DEVTREE::MOD_DEVTREE_BLD_MEM
                 * @userdata1        Return code from ATTR_GET
                 * @userdata2        Attribute Id that failed
                 * @devdesc          Error retrieving attribute
                 */
                errhdl=new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_DEVTREE_BLD_MEM,
                                               RC_ATTR_MEMSIZE_GET_FAIL,
                                               rc,
                                               ATTR_PROC_MEM_SIZES);
                break;
            }

            for (size_t i=0; i< 8; i++)
            {
                if(l_sizes[i]) //non zero means that there is memory present
                {
                    dtOffset_t memNode = i_dt->addNode(rootNode, "memory",
                                                       l_bases[i]);
                    i_dt->addPropertyString(memNode, "device_type","memory");
                    uint64_t propertyCells[2] = {l_bases[i],l_sizes[i]};
                    i_dt->addPropertyCells64(memNode, "reg", propertyCells, 2);

                    //Add the attached proc chip for affinity
                    i_dt->addPropertyCell32(memNode, "ibm,chip-id",
                                            getProcChipId(l_pProc));

                }
            }
        }

        /***************************************************************/
        /* Now loop on all the centaurs in the system and add their    */
        /* inband scom address                                         */
        /***************************************************************/
        rootNode = i_dt->findNode("/");

        // Get all functional memb chip targets
        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        for ( size_t memb = 0;
              (!errhdl) && (memb < l_memBufList.size()); memb++ )
        {
            TARGETING::Target * l_pMemB = l_memBufList[memb];

            //Get MMIO Offset from parent MCS attribute.
            PredicateCTM l_mcs(CLASS_UNIT,TYPE_MCS, MODEL_NA);

            TargetHandleList mcs_list;
            targetService().getAssociated(mcs_list,
                            l_pMemB,
                            TargetService::PARENT_BY_AFFINITY,
                            TargetService::ALL,
                            &l_mcs);

            if( mcs_list.size() != 1 )
            {
                //This error should have already been caught in
                //the inband Scom DD.... going to skip creating node
                //if true
                TRACFCOMP(g_trac_devtree,ERR_MRK" MCS for 0x%x not found",
                          TARGETING::get_huid(l_pMemB));
                continue;
            }
            Target* parentMCS = *(mcs_list.begin());
            uint64_t l_ibscomBase =
              parentMCS->getAttr<ATTR_IBSCOM_MCS_BASE_ADDR>();


            dtOffset_t membNode = i_dt->addNode(rootNode, "memory-buffer",
                                               l_ibscomBase);
            uint64_t propertyCells[2] = {l_ibscomBase,THIRTYTWO_GB};
            i_dt->addPropertyCells64(membNode, "reg", propertyCells, 2);
            i_dt->addPropertyCell32(membNode, "#address-cells", 1);
            i_dt->addPropertyCell32(membNode, "#size-cells", 1);

            uint32_t l_ec = l_pMemB->getAttr<ATTR_EC>();
            char cenVerStr[32];
            snprintf(cenVerStr, 32, "ibm,centaur-v%.2x", l_ec);
            const char* intr_compatStrs[] = {"ibm,centaur", cenVerStr,NULL};
            i_dt->addPropertyStrings(membNode, "compatible", intr_compatStrs);


            if(l_pMemB->
               getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useInbandScom == 0x0)
            {
                i_dt->addProperty(membNode,"use-fsi");
            }

            //Add the attached proc chip for affinity
            uint32_t l_procId = getProcChipId(getParentChip(parentMCS));
            i_dt->addPropertyCell32(membNode, "ibm,fsi-master-chip-id",
                                    l_procId);

            uint32_t l_cenId = getMembChipId(l_pMemB);
            i_dt->addPropertyCell32(membNode, "ibm,chip-id",l_cenId);

            //Add the CMFSI (which CMFSI 0 or 1) and port
            FSI::FsiLinkInfo_t linkinfo;
            FSI::getFsiLinkInfo( l_pMemB, linkinfo );
            uint32_t cmfsiCells[2] =
                           {linkinfo.mPort,linkinfo.link};
            i_dt->addPropertyCells32(membNode, "ibm,fsi-master-port",
                                     cmfsiCells, 2);

            //Add any I2C devices hanging off this chip
            add_i2c_info( l_pMemB, i_dt, membNode );

            // Add membuf ECIDs
            ATTR_ECID_type ecid;
            l_pMemB->tryGetAttr<ATTR_ECID>(ecid);
            char ecid_ascii[33];
            sprintf(ecid_ascii, "%.16llX%.16llX", ecid[0], ecid[1]);
            i_dt->addPropertyString(membNode, "ecid", ecid_ascii);
            CPPASSERT(sizeof(ATTR_ECID_type) == 16);
        }


    }while(0);
    return errhdl;
}


#ifdef CONFIG_BMC_IPMI
enum
{
    ENTITY_ID_MASK      = 0x00FF,
    SENSOR_TYPE_MASK    = 0xFF00,
};

/* create a node for each IPMI sensor in the system, the sensor unit number
   corresponds to the BMC assigned sensor number */
uint32_t bld_sensor_node(devTree * i_dt, const dtOffset_t & i_parentNode,
                         const uint16_t sensorData[],
                         uint32_t instance, uint32_t chipId )
{

    SENSOR::sensorReadingType readType;

    // pass in the sensor name to get back the supported offsets and the event
    // reading type for this sensor.
    uint32_t offsets = SENSOR::getSensorOffsets(
             static_cast<TARGETING::SENSOR_NAME>(
                 sensorData[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET]),
             readType);

    const uint16_t sensorNumber = sensorData[
                        TARGETING::IPMI_SENSOR_ARRAY_NUMBER_OFFSET];

    // the sensor name is a combination of the sensor type + entity ID
    const uint16_t sensorType = (
        sensorData[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET]
                    & SENSOR_TYPE_MASK) >> 8;

    const uint16_t entityId =
        sensorData[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET] & ENTITY_ID_MASK;

    /* Build sensor node based on sensor number */
    dtOffset_t sensorNode = i_dt->addNode(i_parentNode, "sensor", sensorNumber);

    /* compatibility strings -- currently only one */
    const char* compatStr[] = {"ibm,ipmi-sensor", NULL};

    i_dt->addPropertyStrings(sensorNode, "compatible", compatStr);

    i_dt->addPropertyCell32(sensorNode, "reg", sensorNumber);

    // add sensor type
    i_dt->addPropertyCell32(sensorNode, "ipmi-sensor-type", sensorType);
    i_dt->addPropertyCell32(sensorNode, "ipmi-entity-id", entityId);
    i_dt->addPropertyCell32(sensorNode, "ipmi-entity-instance", instance);
    i_dt->addPropertyCell32(sensorNode, "ipmi-sensor-offsets", offsets);
    i_dt->addPropertyCell32(sensorNode, "ipmi-sensor-reading-type", readType);

    // currently we only add the chip ID to the OCC sensor
    if(chipId != 0xFF )
    {
        i_dt->addPropertyCell32(sensorNode, "ibm,chip-id", chipId);
    }

    /* return the phandle for this sensor */
    return i_dt->getPhandle(sensorNode);
}


// build the sensor node for a given target
uint32_t bld_sensor_node(devTree * i_dt, const dtOffset_t & i_sensorNode,
        TARGETING::Target * i_pTarget )
{

    AttributeTraits<ATTR_IPMI_SENSORS>::Type  l_sensors;
    uint16_t array_rows = (sizeof(l_sensors)/sizeof(l_sensors[0]));

    /* if there is an IPMI_SENSORS attribute, parse it and create a node
     * for each sensor */
    if ( i_pTarget->tryGetAttr<ATTR_IPMI_SENSORS>(l_sensors) )
    {
        uint32_t chipId = 0xFF;

        AttributeTraits<ATTR_IPMI_INSTANCE>::Type l_instance;

        l_instance = i_pTarget->getAttr<TARGETING::ATTR_IPMI_INSTANCE>();

        // add the chip id to the OCC sensor since OPAL needs it to figure out
        // which OCC it is.
        if( TARGETING::TYPE_OCC == i_pTarget->getAttr<TARGETING::ATTR_TYPE>())
        {
            ConstTargetHandle_t proc = getParentChip(i_pTarget);

            chipId = getProcChipId( proc );
        }

        for(uint16_t i=0; i< array_rows; i++)
        {
            /*  if the sensor number is 0xFF move on */
            if( l_sensors[i][IPMI_SENSOR_ARRAY_NUMBER_OFFSET] != 0xFF )
            {
                /* use this row to create the next sensor node - ignoring
                 * return value for now */
                bld_sensor_node(i_dt, i_sensorNode, l_sensors[i],
                        l_instance , chipId );
            }
            else
            {
                /* move on to the next target */
                break;
            }
        }
    }

    // return the phandle
    return i_dt->getPhandle(i_sensorNode);
}


/*
* The "sensors" node contains sub-nodes for each of the IPMI sensors known to
* the BMC.
*/
errlHndl_t bld_fdt_sensors(devTree * i_dt, const dtOffset_t & i_parentNode,
                            const bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    /* Nothing to do for small trees currently. */
    if (i_smallTree) { return NULL; }

    const char* sensorNodeName = "sensors";

    /* add the Sensors node to the BMC node */
    dtOffset_t sensorNode = i_dt->addNode(i_parentNode, sensorNodeName);

    i_dt->addPropertyString(sensorNode, "name", sensorNodeName );

    /* Add the # address & size cell properties to /sensors node. */
    i_dt->addPropertyCell32(sensorNode, "#address-cells", 1);
    i_dt->addPropertyCell32(sensorNode, "#size-cells", 0);

    /*  loop through all the targets and get the IPMI sensor data if it
        exists */
    for (TargetIterator itr = TARGETING::targetService().begin();
         itr != TARGETING::targetService().end(); ++itr)
    {
        /* create node entries for this targets sensors if they exist
        *  ignoring return value for now */
        bld_sensor_node(i_dt, sensorNode, *itr );
    }

    return errhdl;
}

/* add the BMC node to the device tree, this node will hold any BMC info needed
   in the device tree */
errlHndl_t bld_fdt_bmc(devTree * i_dt, bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    /* Nothing to do for small trees currently. */
    if (i_smallTree) { return NULL; }

    /* Find the root node. */
    dtOffset_t rootNode = i_dt->findNode("/");

    const char* bmcNodeName = "bmc";

    /* add the BMC node under the root node */
    dtOffset_t bmcNode = i_dt->addNode(rootNode, bmcNodeName);

    /* Add the # address & size cell properties to /bmc node. */
    i_dt->addPropertyCell32(bmcNode, "#address-cells", 1);
    i_dt->addPropertyCell32(bmcNode, "#size-cells", 0);

    i_dt->addPropertyString(bmcNode, "name", bmcNodeName );

    /* create a node to hold the sensors */
    errhdl = bld_fdt_sensors( i_dt, bmcNode, i_smallTree );

    return errhdl;
}
#endif

errlHndl_t bld_fdt_vpd(devTree * i_dt, bool i_smallTree)
{
    // Nothing to do for small trees currently.
    if (i_smallTree) { return NULL; }

    errlHndl_t errhdl = NULL;
    size_t vpdSize;

    do
    {
        /* Find the / node and add a vpd node under it. */
        dtOffset_t rootNode = i_dt->findNode("/");
        dtOffset_t vpdNode = i_dt->addNode(rootNode, "vpd");

        // Grab a system object to work with
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);


        /***************************************************************/
        /* Add the ibm,vpd for all functional procs                    */
        /***************************************************************/
        // Add vpd (VINI record) for all functional procs
        // and #V for all functional cores
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for ( size_t proc = 0;
              (!errhdl) && (proc < l_cpuTargetList.size()); proc++ )
        {
            TARGETING::Target * l_pProc = l_cpuTargetList[proc];

            uint32_t l_procId = getProcChipId(l_pProc);
            dtOffset_t procNode = i_dt->addNode(vpdNode, "processor",
                                               l_procId);

            // Read entire VINI record to stuff in devtree
            // Note: First read with NULL for o_buffer sets vpdSize to the
            // correct length
            errhdl = deviceRead( l_pProc,
                              NULL,
                              vpdSize,
                              DEVICE_MVPD_ADDRESS( MVPD::VINI,
                                                   MVPD::FULL_RECORD ));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't get VINI size for HUID=0x%.8X",
                          TARGETING::get_huid(l_pProc));
                break;
            }

            uint8_t viniBuf[vpdSize];

            errhdl = deviceRead( l_pProc,
                              reinterpret_cast<void*>( &viniBuf ),
                              vpdSize,
                              DEVICE_MVPD_ADDRESS( MVPD::VINI,
                                                   MVPD::FULL_RECORD ));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't read VINI for HUID=0x%.8X",
                          TARGETING::get_huid(l_pProc));
                break;
            }

            //Add the proc chips vpd
            i_dt->addPropertyBytes(procNode, "ibm,vpd", viniBuf, vpdSize);

            /***************************************************************/
            /* Add the #V bucket for each functional core                  */
            /***************************************************************/

            //@TODO RTC:143092
#if 0
            TARGETING::TargetHandleList l_corelist;
            fapi::Target l_pFapiProc(fapi::TARGET_TYPE_PROC_CHIP,
                            (const_cast<TARGETING::Target*>(l_pProc) ));

            getChildChiplets( l_corelist, l_pProc, TYPE_CORE );
            for (size_t core = 0; core < l_corelist.size(); core++)
            {
                const TARGETING::Target * l_core = l_corelist[core];

                uint32_t l_coreNum =
                  l_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                PIR_t pir(0);
                pir.groupId = PIR_t::groupFromChipId(l_procId);
                pir.chipId = PIR_t::chipFromChipId(l_procId);
                pir.coreId = l_coreNum;

                // Get #V bucket data
                uint32_t l_record = (uint32_t) MVPD::LRP0 + l_coreNum;
                fapi::voltageBucketData_t l_poundVdata = {0};
                fapi::ReturnCode l_rc = fapiGetPoundVBucketData(l_pFapiProc,
                                                                l_record,
                                                                l_poundVdata);
                if(l_rc)
                {
                    TRACFCOMP( g_trac_devtree,ERR_MRK"Error getting #V data for HUID:"
                               "0x%08X",
                               l_pProc->getAttr<TARGETING::ATTR_HUID>());

                    // Convert fapi returnCode to Error handle
                    errhdl = fapiRcToErrl(l_rc);
                    break;
                }

                //Add the attached core
                dtOffset_t coreNode = i_dt->addNode(procNode, "cpu",
                                                    pir.word);

                i_dt->addPropertyBytes(coreNode, "frequency,voltage",
                                     reinterpret_cast<uint8_t*>( &l_poundVdata),
                                     sizeof(fapi::voltageBucketData_t));
            }
            if(errhdl)
            {
                break;
            }
#endif
        }
        if(errhdl)
        {
            break;
        }

#if 0   //TODO RTC123250 -- re-enable once fixed
        /***************************************************************/
        /* Now loop on all the dimms in the system and add their spd   */
        /***************************************************************/

        // Get all functional dimm targets
        TARGETING::TargetHandleList l_dimmList;
        getAllLogicalCards(l_dimmList, TYPE_DIMM);
        size_t spdSize;

        for ( size_t dimm = 0;
              (!errhdl) && (dimm < l_dimmList.size()); dimm++ )
        {
            TARGETING::Target * l_pDimm = l_dimmList[dimm];
            uint32_t l_huid = TARGETING::get_huid(l_pDimm);

            dtOffset_t dimmNode = i_dt->addNode(vpdNode, "dimm",
                                                l_huid);

            // Read entire SPD record to stuff in devtree
            // Note: First read with NULL for o_buffer sets spdSize to the
            // correct length
            errhdl = deviceRead( l_pDimm,
                                 NULL,
                                 spdSize,
                                 DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't get SPD size for HUID=0x%.8X",
                          TARGETING::get_huid(l_pDimm));
                break;
            }

            uint8_t spdBuf[spdSize];

            errhdl = deviceRead( l_pDimm,
                                 reinterpret_cast<void*>( &spdBuf ),
                                 spdSize,
                                 DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));

            if(errhdl)
            {
                TRACFCOMP(g_trac_devtree,ERR_MRK" Couldn't read SPD for HUID=0x%.8X",
                          TARGETING::get_huid(l_pDimm));
                break;
            }

            //Add the dimm spd
            i_dt->addPropertyBytes(dimmNode, "spd", spdBuf, spdSize);
        }
        if(errhdl)
        {
            break;
        }
#endif

    }while(0);

    return errhdl;
}

errlHndl_t build_flatdevtree( uint64_t i_dtAddr, size_t i_dtSize,
                              bool i_smallTree )
{
    errlHndl_t errhdl = NULL;
    devTree * dt = &Singleton<devTree>::instance();
    bool devTreeVirtual = true;

    do
    {
        if (0 == i_dtAddr)
        {
            i_dtAddr = DEVTREE_DATA_ADDR;
            i_dtSize = DEVTREE_SPACE_SIZE;
            devTreeVirtual = false;
        }

        TRACFCOMP( g_trac_devtree, "---devtree init---" );
        dt->initialize(i_dtAddr, i_dtSize, devTreeVirtual);
        errhdl = bld_fdt_system(dt, i_smallTree);
        if (errhdl)
        {
            break;
        }

        std::vector<homerAddr_t> l_homerRegions;

        TRACFCOMP( g_trac_devtree, "---devtree cpu ---" );
        errhdl = bld_fdt_cpu(dt, l_homerRegions, i_smallTree);
        if(errhdl)
        {
            break;
        }

#ifndef CONFIG_DISABLE_HOSTBOOT_RUNTIME
        TRACFCOMP( g_trac_devtree, "---devtree reserved mem ---" );
        errhdl = bld_fdt_reserved_mem(dt, l_homerRegions, i_smallTree);
        if(errhdl)
        {
            break;
        }
#endif
        TRACFCOMP( g_trac_devtree, "---devtree mem ---" );
        errhdl = bld_fdt_mem(dt, i_smallTree);
        if(errhdl)
        {
            break;
        }

#ifdef CONFIG_BMC_IPMI
        TRACFCOMP( g_trac_devtree, "---devtree BMC ---" );
        errhdl = bld_fdt_bmc(dt, i_smallTree);
        if(errhdl)
        {
            break;
        }
#endif

        TRACFCOMP( g_trac_devtree, "---devtree vpd ---" );
        errhdl = bld_fdt_vpd(dt, i_smallTree);
        if(errhdl)
        {
            break;
        }
    }while(0);

    return errhdl;
}


uint64_t get_flatdevtree_phys_addr()
{
    return Singleton<devTree>::instance().getBlobPhys();
}

}
