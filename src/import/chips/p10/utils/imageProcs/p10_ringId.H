/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ringId.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#ifndef _P10_RINGID_H_
#define _P10_RINGID_H_

#ifdef WIN32
    #include "win32_stdint.h"
#else
    #include <stdint.h>
    #include <stddef.h>
#endif
#include <p10_ring_id.H>
#include <common_ringId.H>


enum Chiplets
{
    PERV_TYPE,
    N0_TYPE,
    N1_TYPE,
    PCI_TYPE,
    MC_TYPE,
    AXON_TYPE,
    EQ_TYPE,
    SBE_NUM_CHIPLETS
};

const ChipletType_t QME_NUM_CHIPLETS = 1;


namespace PERV
{
enum RingOffset
{
    // Common Rings
    perv_fure     = 0,
    perv_gptr     = 1,
    perv_lbst     = 2,
    perv_abst     = 3,
    perv_time     = 4,
    perv_bndy     = 5,
    // Instance Rings
    perv_repr     = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x01,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    6,  // 6 common rings for pervasive chiplet
    1,  // 1 instance specific rings for pervasive chiplet
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace PERV

namespace N0
{
enum RingOffset
{
    // Common Rings
    n0_fure      = 0,
    n0_gptr      = 1,
    n0_lbst      = 2,
    n0_abst      = 3,
    n0_time      = 4,
    n0_bndy      = 5,
    // Instance Rings
    n0_repr      = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x02,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    6,  // 6 common rings for N0 Chiplet
    1,  // 1 instance specific rings for N0 chiplet
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace N1
{
enum RingOffset
{
    // Common Rings
    n1_fure      = 0,
    n1_gptr      = 1,
    n1_lbst      = 2,
    n1_abst      = 3,
    n1_time      = 4,
    n1_bndy      = 5,
    // Instance Rings
    n1_repr       = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x03,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    6 , // 6 common rings for N1 Chiplet
    1,  // 1 instance specific rings for N1 chiplet
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace PCI
{
enum RingOffset
{
    // Common Rings
    pci_fure = 0,
    pci_gptr = 1,
    pci_lbst = 2,
    pci_abst = 3,
    pci_time = 4,
    pci_bndy = 5,
    // Instance Rings
    pci_repr = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x08, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    6,  // 6 common rings for PCI0 chiplet
    1,  // 1 instance specific rings for PCI0 chiplet
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace MC
{
enum RingOffset
{
    // Common Rings
    mc_fure       = 0,
    mc_gptr       = 1,
    mc_lbst       = 2,
    mc_abst       = 3,
    mc_time       = 4,
    mc_bndy       = 5,
    // Instance Rings
    mc_repr        = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x0C,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    6,  // 6 common rings for MC Chiplet
    1,  // 1 instance specific rings for each MC instance
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace MC

namespace AXON
{
enum RingOffset
{
    // Common Rings
    iohs_fure       = 0,
    iohs_gptr       = 1,
    iohs_lbst       = 2,
    iohs_abst       = 3,
    iohs_time       = 4,
    iohs_bndy       = 5,
    // Instance Rings
    iohs_repr        = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x18,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    6,  // 6 common rings for MC Chiplet
    1,  // 1 instance specific rings for each MC instance
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace AXON

namespace EQ
{
enum RingOffset
{
    // Common Rings
    eq_fure         = 0,
    eq_gptr         = 1,
    eq_lbst         = 2,
    eq_abst         = 3,
    eq_time         = 4,
    eq_bndy         = 5,
    ec_cl2_fure     = 6,
    ec_cl2_gptr     = 7,
    ec_cl2_lbst     = 8,
    ec_cl2_abst     = 9,
    ec_cl2_time     = 10,
    ec_cl2_bndy     = 11,
    // Instance Rings
    eq_repr         = (0 | INSTANCE_RING_MARK),
    ec_cl2_repr     = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x20, // Base chiplet/instance ID.
    8,    // Number of chiplet instances
    12, // 12 common rings for Quad chiplet.
    2,  // 2 instance specific rings for EQ chiplet
    7,  // 7 common ring variants: BASE, CC, RL, RL2/3/4/5
    {
        RV_BASE,
        RV_CC,
        RV_RL,
        RV_RL2,
        RV_RL3,
        RV_RL4,
        RV_RL5
    }
};

}; // end of namespace EQ


#ifndef __PPE__

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { "perv_fure"               , 0x0103400F, PERV::perv_fure             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 0
    { "perv_gptr"               , 0x01034002, PERV::perv_gptr             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 1
    { "perv_lbst"               , 0x01034004, PERV::perv_lbst             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 2
    { "perv_abst"               , 0x01034005, PERV::perv_abst             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 3
    { "perv_repr"               , 0x01034006, PERV::perv_repr             , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 4
    { "perv_time"               , 0x01034007, PERV::perv_time             , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 5
    { "perv_bndy"               , 0x01034008, PERV::perv_bndy             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 6
    { "n0_fure"                 , 0x0203600F, N0::n0_fure                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 7
    { "n0_gptr"                 , 0x02036002, N0::n0_gptr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 8
    { "n0_lbst"                 , 0x02036004, N0::n0_lbst                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 9
    { "n0_abst"                 , 0x02036005, N0::n0_abst                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 10
    { "n0_repr"                 , 0x02036006, N0::n0_repr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 11
    { "n0_time"                 , 0x02036007, N0::n0_time                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 12
    { "n0_bndy"                 , 0x02036008, N0::n0_bndy                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 13
    { "n1_fure"                 , 0x0303700F, N1::n1_fure                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 14
    { "n1_gptr"                 , 0x03037002, N1::n1_gptr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 15
    { "n1_lbst"                 , 0x03037004, N1::n1_lbst                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 16
    { "n1_abst"                 , 0x03037005, N1::n1_abst                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 17
    { "n1_repr"                 , 0x03037006, N1::n1_repr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 18
    { "n1_time"                 , 0x03037007, N1::n1_time                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 19
    { "n1_bndy"                 , 0x08037008, N1::n1_bndy                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 20
    { "pci_fure"                , 0x0803500F, PCI::pci_fure               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 21
    { "pci_gptr"                , 0x08035002, PCI::pci_gptr               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 22
    { "pci_lbst"                , 0x08035004, PCI::pci_lbst               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 23
    { "pci_abst"                , 0x08035005, PCI::pci_abst               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 24
    { "pci_repr"                , 0x08035006, PCI::pci_repr               , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 25
    { "pci_time"                , 0x08035007, PCI::pci_time               , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 26
    { "pci_bndy"                , 0x08035008, PCI::pci_bndy               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 27
    { "mc_fure"                 , 0x0C03500F, MC::mc_fure                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 28
    { "mc_gptr"                 , 0x0C035002, MC::mc_gptr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 29
    { "mc_lbst"                 , 0x0C035004, MC::mc_lbst                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 30
    { "mc_abst"                 , 0x0C035005, MC::mc_abst                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 31
    { "mc_repr"                 , 0x0C035006, MC::mc_repr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 32
    { "mc_time"                 , 0x0C035007, MC::mc_time                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 33
    { "mc_bndy"                 , 0x0C035008, MC::mc_bndy                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 34
    { "iohs_fure"               , 0x1803600F, AXON::iohs_fure             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 35
    { "iohs_gptr"               , 0x18036002, AXON::iohs_gptr             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 36
    { "iohs_lbst"               , 0x18036004, AXON::iohs_lbst             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 37
    { "iohs_abst"               , 0x18036005, AXON::iohs_abst             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 38
    { "iohs_repr"               , 0x18036006, AXON::iohs_repr             , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 39
    { "iohs_time"               , 0x18036007, AXON::iohs_time             , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 40
    { "iohs_bndy"               , 0x18036008, AXON::iohs_bndy             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 41
    { "eq_fure"                 , 0x2003400F, EQ::eq_fure                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 42
    { "eq_gptr"                 , 0x20034002, EQ::eq_gptr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 43
    { "eq_lbst"                 , 0x20034004, EQ::eq_lbst                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 44
    { "eq_abst"                 , 0x20034005, EQ::eq_abst                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 45
    { "eq_repr"                 , 0x20034006, EQ::eq_repr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 46
    { "eq_time"                 , 0x20034007, EQ::eq_time                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 47
    { "eq_bndy"                 , 0x20034008, EQ::eq_bndy                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 48
    { "ec_cl2_fure"             , 0x2003200F, EQ::ec_cl2_fure             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 49
    { "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 50
    { "ec_cl2_lbst"             , 0x20032004, EQ::ec_cl2_lbst             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 51
    { "ec_cl2_abst"             , 0x20032005, EQ::ec_cl2_abst             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 52
    { "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 53
    { "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 54
    { "ec_cl2_bndy"             , 0x20032008, EQ::ec_cl2_bndy             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 55
};
#endif

#ifdef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { PERV::perv_fure             , PERV_TYPE }, // 0
    { PERV::perv_gptr             , PERV_TYPE }, // 1
    { PERV::perv_lbst             , PERV_TYPE }, // 2
    { PERV::perv_abst             , PERV_TYPE }, // 3
    { PERV::perv_repr             , PERV_TYPE }, // 4
    { PERV::perv_time             , PERV_TYPE }, // 5
    { PERV::perv_bndy             , PERV_TYPE }, // 6
    { N0::n0_fure                 , N0_TYPE   }, // 7
    { N0::n0_gptr                 , N0_TYPE   }, // 8
    { N0::n0_lbst                 , N0_TYPE   }, // 9
    { N0::n0_abst                 , N0_TYPE   }, // 10
    { N0::n0_repr                 , N0_TYPE   }, // 11
    { N0::n0_time                 , N0_TYPE   }, // 12
    { N0::n0_bndy                 , N0_TYPE   }, // 13
    { N1::n1_fure                 , N1_TYPE   }, // 14
    { N1::n1_gptr                 , N1_TYPE   }, // 15
    { N1::n1_lbst                 , N1_TYPE   }, // 16
    { N1::n1_abst                 , N1_TYPE   }, // 17
    { N1::n1_repr                 , N1_TYPE   }, // 18
    { N1::n1_time                 , N1_TYPE   }, // 19
    { N1::n1_bndy                 , N1_TYPE   }, // 20
    { PCI::pci_fure               , PCI_TYPE  }, // 21
    { PCI::pci_gptr               , PCI_TYPE  }, // 22
    { PCI::pci_lbst               , PCI_TYPE  }, // 23
    { PCI::pci_abst               , PCI_TYPE  }, // 24
    { PCI::pci_repr               , PCI_TYPE  }, // 25
    { PCI::pci_time               , PCI_TYPE  }, // 26
    { PCI::pci_bndy               , PCI_TYPE  }, // 27
    { MC::mc_fure                 , MC_TYPE   }, // 28
    { MC::mc_gptr                 , MC_TYPE   }, // 29
    { MC::mc_lbst                 , MC_TYPE   }, // 30
    { MC::mc_abst                 , MC_TYPE   }, // 31
    { MC::mc_repr                 , MC_TYPE   }, // 32
    { MC::mc_time                 , MC_TYPE   }, // 33
    { MC::mc_bndy                 , MC_TYPE   }, // 34
    { AXON::iohs_fure             , AXON_TYPE }, // 35
    { AXON::iohs_gptr             , AXON_TYPE }, // 36
    { AXON::iohs_lbst             , AXON_TYPE }, // 37
    { AXON::iohs_abst             , AXON_TYPE }, // 38
    { AXON::iohs_repr             , AXON_TYPE }, // 39
    { AXON::iohs_time             , AXON_TYPE }, // 40
    { AXON::iohs_bndy             , AXON_TYPE }, // 41
    { EQ::eq_fure                 , EQ_TYPE   }, // 42
    { EQ::eq_gptr                 , EQ_TYPE   }, // 43
    { EQ::eq_lbst                 , EQ_TYPE   }, // 44
    { EQ::eq_abst                 , EQ_TYPE   }, // 45
    { EQ::eq_repr                 , EQ_TYPE   }, // 46
    { EQ::eq_time                 , EQ_TYPE   }, // 47
    { EQ::eq_bndy                 , EQ_TYPE   }, // 48
    { EQ::ec_cl2_fure             , EQ_TYPE   }, // 49
    { EQ::ec_cl2_gptr             , EQ_TYPE   }, // 50
    { EQ::ec_cl2_lbst             , EQ_TYPE   }, // 51
    { EQ::ec_cl2_abst             , EQ_TYPE   }, // 52
    { EQ::ec_cl2_repr             , EQ_TYPE   }, // 53
    { EQ::ec_cl2_time             , EQ_TYPE   }, // 54
    { EQ::ec_cl2_bndy             , EQ_TYPE   }, // 55
};
#endif


// Returns data structure assocated with chipletType
int
ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData);


#endif
