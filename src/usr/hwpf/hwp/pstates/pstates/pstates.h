/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstates.h $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __PSTATES_H__
#define __PSTATES_H__

// $Id: pstates.h,v 1.10 2013/10/04 18:38:18 jimyac Exp $

/// \file pstates.h
/// \brief Pstate structures and support routines for OCC product firmware

#include "pgp_common.h"

////////////////////////////////////////////////////////////////////////////
// Global and Local Pstate Tables
////////////////////////////////////////////////////////////////////////////

/// The Global Pstate Table must be 1KB-aligned in SRAM. The alignment is
/// specified in the traditional log2 form.
#define GLOBAL_PSTATE_TABLE_ALIGNMENT 10

/// The Global Pstate table has 128 * 8-byte entries
#define GLOBAL_PSTATE_TABLE_ENTRIES 128

/// The Local Pstate table has 32 x 64-bit entries
#define LOCAL_PSTATE_ARRAY_ENTRIES 32

/// The VDS/VIN table has 32 x 64-bit entries
#define VDSVIN_ARRAY_ENTRIES       64 

/// The VRM-11 VID base voltage in micro-Volts
#define VRM11_BASE_UV 1612500

/// The VRM-11 VID step as an unsigned number (micro-Volts)
#define VRM11_STEP_UV 6250

/// The iVID base voltage in micro-Volts
#define IVID_BASE_UV 600000

/// The iVID step as an unsigned number (micro-Volts)
#define IVID_STEP_UV 6250

///  CPM Inflection Points
#define CPM_RANGES 8

// Error/Panic codes for support routines

#define VRM11_INVALID_VOLTAGE 0x00876101

#define PSTATE_OVERFLOW  0x00778a01
#define PSTATE_UNDERFLOW 0x00778a02

#define PSTATE_LT_PSTATE_MIN 0x00778a03
#define PSTATE_GT_PSTATE_MAX 0x00778a04

#define DPLL_OVERFLOW  0x00d75501
#define DPLL_UNDERFLOW 0x00d75502

#define VID11_OVERFLOW  0x00843101
#define VID11_UNDERFLOW 0x00843102

#define GPST_INVALID_OBJECT      0x00477801
#define GPST_INVALID_ARGUMENT    0x00477802
#define GPST_INVALID_ENTRY       0x00477803
#define GPST_PSTATE_CLIPPED_LOW  0x00477804
#define GPST_PSTATE_CLIPPED_HIGH 0x00477805
#define GPST_BUG                 0x00477806
#define GPST_PSTATE_GT_GPST_PMAX 0x00477807

#define LPST_INVALID_OBJECT      0x00477901 
#define LPST_GPST_WARNING        0x00477902 
#define LPST_INCR_CLIP_ERROR     0x00477903

/// PstateSuperStructure Magic Number
///
/// This magic number identifies a particular version of the
/// PstateSuperStructure and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure. 

#define PSTATE_SUPERSTRUCTURE_MAGIC 0x5053544154453032ull /* PSTATE02 */


/// \defgroup pstate_options Pstate Options
///
/// These are flag bits for the \a options field of the PstateOptions
/// structure.
///
/// @{

/// gpsm_gpst_install() - Bypass copying the Pstate table from the
/// PstateSuperStructure into the aligned global location.
#define PSTATE_NO_COPY_GPST       0x01

/// gpsm_gpst_install() - Bypass Global Pstate Table installation and setup.
#define PSTATE_NO_INSTALL_GPST    0x02

/// gpsm_lpsa_install() - Bylass Local Pstate Array installation and setup
#define PSTATE_NO_INSTALL_LPSA    0x04

/// gpsm_resclk_install - Bypass resonant clocking Pstate limit setup
#define PSTATE_NO_INSTALL_RESCLK  0x08

/// gpsm_enable_pstates() - Force the system to the minimum Pstate at
/// initialization
///
/// This mode is added as a workaround for the case that the SPIVID interface
/// is not working correctly during initial bringup.  This forces Pstate mode
/// to come up at a low frequency.
#define PSTATE_FORCE_INITIAL_PMIN 0x10

/// @}

#ifndef __ASSEMBLER__

#include <stdint.h>

#include <p8_ivrm.H>

/// A Global Pstate Table Entry, in the form of a packed 'firmware register'
///
/// Global Pstate table entries are referenced by OCC firmware, for example
/// in procedures that do 'manual' Pstate manipulation.

typedef union gpst_entry {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t evid_vdd     : 8;
    uint64_t evid_vcs     : 8;
    uint64_t reserved16   : 1;
    uint64_t evid_vdd_eff : 7;
    uint64_t reserved24   : 1;
    uint64_t evid_vcs_eff : 7;
    uint64_t reserved32   : 1;
    uint64_t maxreg_vdd   : 7;
    uint64_t reserved40   : 1;
    uint64_t maxreg_vcs   : 7;
        uint64_t reserved48   : 8;
        uint64_t ecc          : 8;
#else
        uint64_t ecc          : 8;
        uint64_t reserved48   : 8;
    uint64_t maxreg_vcs   : 7;
    uint64_t reserved40   : 1;
    uint64_t maxreg_vdd   : 7;
    uint64_t reserved32   : 1;
    uint64_t evid_vcs_eff : 7;
    uint64_t reserved24   : 1;
    uint64_t evid_vdd_eff : 7;
    uint64_t reserved16   : 1;
    uint64_t evid_vcs     : 8;
    uint64_t evid_vdd     : 8;
#endif // _BIG_ENDIAN
    } fields;

} gpst_entry_t;


/// A Local Pstate Table Entry, in the form of a packed 'firmware register'
///
/// This structure is provided for reference only; Currently the OCC firmware
/// does not manupulate Local Pstate table entries, however it is possible
/// that future lab applications will require this.

typedef union lpst_entry {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t ivid_vdd          : 7;
    uint64_t ivid_vcs          : 7;
    uint64_t vdd_core_pwrratio : 6;
    uint64_t vcs_core_pwrratio : 6;
    uint64_t vdd_eco_pwrratio  : 6;
    uint64_t vcs_eco_pwrratio  : 6;
    uint64_t ps1_vid_incr      : 3;
    uint64_t ps2_vid_incr      : 3; 
    uint64_t ps3_vid_incr      : 3;
    uint64_t reserved47        : 7;
    uint64_t inc_step          : 3;
    uint64_t dec_step          : 3;
    uint64_t reserved60        : 4;
#else
    uint64_t reserved60        : 4;
    uint64_t dec_step          : 3;
    uint64_t inc_step          : 3;
    uint64_t reserved47        : 7;
    uint64_t ps3_vid_incr      : 3;
    uint64_t ps2_vid_incr      : 3; 
    uint64_t ps1_vid_incr      : 3;
    uint64_t vcs_eco_pwrratio  : 6;
    uint64_t vdd_eco_pwrratio  : 6;
    uint64_t vcs_core_pwrratio : 6;
    uint64_t vdd_core_pwrratio : 6;
    uint64_t ivid_vcs          : 7;
    uint64_t ivid_vdd          : 7;
#endif // _BIG_ENDIAN
    } fields;

} lpst_entry_t;


/// A VDS/VIN table Entry

typedef union vdsvin_entry {
    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t ivid0             : 7;
    uint64_t ivid1             : 7;
    uint64_t reserved14        : 2;    
    uint64_t pfet0             : 5; 
    uint64_t pfet1             : 5; 
    uint64_t pfet2             : 5; 
    uint64_t pfet3             : 5; 
    uint64_t pfet4             : 5; 
    uint64_t pfet5             : 5; 
    uint64_t pfet6             : 5; 
    uint64_t pfet7             : 5;
    uint64_t reserved_56       : 8;     
#else
    uint64_t reserved_56       : 8;
    uint64_t pfet7             : 5;    
    uint64_t pfet6             : 5;    
    uint64_t pfet5             : 5;    
    uint64_t pfet4             : 5;    
    uint64_t pfet3             : 5;    
    uint64_t pfet2             : 5;    
    uint64_t pfet1             : 5;    
    uint64_t pfet0             : 5;    
    uint64_t reserved14        : 2;    
    uint64_t ivid1             : 7;    
    uint64_t ivid0             : 7;    
#endif // _BIG_ENDIAN
    } fields;
} vdsvin_entry_t;

/// Standard options controlling Pstate setup and GPSM procedures

typedef struct {

    /// Option flags; See \ref pstate_options
    uint32_t options;

    /// Pad structure to 8 bytes.  Could also be used for other options later.
    uint32_t pad;

} PstateOptions;


/// An abstract Global Pstate table
///
/// The GlobalPstateTable is an abstraction of a set of voltage/frequency
/// operating points along with hardware limits.  Besides the hardware global
/// Pstate table, the abstract table contains enough extra information to make
/// it the self-contained source for setting up and managing voltage and
/// frequency in either Hardware or Firmware Pstate mode.
///
/// When installed in PMC, Global Pstate table indices are adjusted such that
/// the defined Pstates begin with table entry 0. The table need not be full -
/// the \a pmin and \a entries fields define the minimum and maximum Pstates
/// represented in the table.  However at least 1 entry must be defined to
/// create a legal table.
///
/// Note that Global Pstate table structures to be mapped into PMC hardware
/// must be 1KB-aligned.  This requirement is fullfilled by ensuring that
/// instances of this structure are 1KB-aligned.

typedef struct {

    /// The Pstate table
    gpst_entry_t pstate[GLOBAL_PSTATE_TABLE_ENTRIES];

    /// Pstate options
    ///
    /// The options are included as part of the GlobalPstateTable so that they
    /// are available to all procedures after gpsm_initialize().
    PstateOptions options;

    /// The frequency associated with Pstate[0] in KHz
    uint32_t pstate0_frequency_khz;

    /// The frequency step in KHz
    uint32_t frequency_step_khz;

    /// The DPLL frequency code corresponding to Pstate 0
    ///
    /// This frequency code is installed in the PCB Slave as the DPLL Fnom
    /// when the Pstate table is activated. Normally this frequency code is
    /// computed as
    ///
    ///     pstate0_frequency_khz / frequency_step_khz
    ///
    /// however it may be replaced by any other code as a way to
    /// transparently bias frequency on a per-core basis.
    DpllCode pstate0_frequency_code[PGP_NCORES];

    /// The DPLL Fmax bias
    ///
    /// This bias value (default 0, range -8 to +7 frequency ticks) is
    /// installed when the Pstate table is installed.  The value is allowed to
    /// vary per core.  This bias value will usually be set to a small
    /// positive number to provide a small amount of frequency headroom for
    /// the CPM-DPLL voltage control algorithm.
    ///
    /// \bug Hardware currently specifies this field as unsigned for the
    /// computation of frequency stability in
    /// dpll_freqout_mode_en. (HW217404).  This issue will be fixed in
    /// Venice. Since we never plan to use this mode no workaround or
    /// mitigation is provided by GPSM procedures.

    int8_t dpll_fmax_bias[PGP_NCORES];

    /// The number of entries defined in the table.
    uint8_t entries;

    /// The minimum Pstate in the table
    ///
    /// Note that gpsi_min = pmin - PSTATE_MIN, gpsi_max = pmin + entries - 1.
    Pstate pmin;

    /// The "Safe" Global Pstate
    ///
    /// This Pstate is installed in the PMC and represents the safe-mode
    /// voltage.
    Pstate pvsafe;

    /// The "Safe" Local Pstate
    ///
    /// This Pstate is installed in the PCB Slaves and represents the
    /// safe-mode frequency.
    Pstate psafe;

    /// Step size of Global Pstate steps
    uint8_t pstate_stepsize;

    /// The exponent of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_range;

    /// The significand of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_value;

    /// Pad structure to 8-byte alignment
    uint8_t pad;

} GlobalPstateTable;


/// This macro creates a properly-aligned Global Pstate table structure as a
/// static initialization.  

#define GLOBAL_PSTATE_TABLE(x)                                  \
    GlobalPstateTable x                                         \
    ALIGNED_ATTRIBUTE(POW2_32(GLOBAL_PSTATE_TABLE_ALIGNMENT))   \
        SECTION_ATTRIBUTE(".noncacheable")                      \
        = {.entries = 0}


/// An opaque Local Pstate Array
///
/// An array local to each core contains the Local Pstate Table, Vds table and
/// Vin table. The array contents are presented to OCC firmware as an opaque
/// set of 96 x 64-bit entries which are simply installed verbatim into each
/// core. Every core stores the same table.
///
/// When installed in the core, Local Pstate table indices are adjusted such
/// that the defined Pstates begin with table entry 0. The table need not be
/// full - the \a pmin and \a entries fields define the minimum and maximum
/// Pstates represented in the table.  However at least 1 entry must be
/// defined to create a legal table.

typedef struct {

    /// The vdsvin table contents
    vdsvin_entry_t vdsvin[VDSVIN_ARRAY_ENTRIES];

    /// The local pstate table contents
    lpst_entry_t pstate[LOCAL_PSTATE_ARRAY_ENTRIES];

    /// The number of entries defined in the Local Pstate Table
    uint8_t entries;

    /// The minimum Pstate in the Local Pstate table
    ///
    /// Note that lpsi_min = pmin - PSTATE_MIN, lpsi_max = pmin + entries - 1.
    Pstate pmin;

    /// Pstate step delay for rising iVRM voltages
    uint8_t stepdelay_rising;

    /// Pstate step delay for falling iVRM voltages
    uint8_t stepdelay_lowering;

    /// Pad structure to 8-byte alignment
    uint8_t pad[4];

} LocalPstateArray;


/// Resonant Clocking setup parameters
///
/// All Pstate parameters are specified in terms of Pstates as defined in the
/// current PstateSuperStructure.

typedef struct {

    /// Full Clock Sector Buffer Pstate
    Pstate full_csb_ps;

    /// Low-Frequency Resonant Lower Pstate
    Pstate res_low_lower_ps;

    /// Low-Frequency Resonant Upper Pstate
    Pstate res_low_upper_ps;

    /// High-Frequency Resonant Lower Pstate
    Pstate res_high_lower_ps;

    /// High-Frequency Resonant Upper Pstate
    Pstate res_high_upper_ps;

    /// Pad structure to 8-byte alignment
    uint8_t pad[3];

} ResonantClockingSetup;

/// CPM Pstate ranges per mode
///
/// These Pstate range specifications apply to all chiplets operating in the
/// same mode. 

typedef union {

    /// Forces alignment
    uint64_t quad[2];              

    struct {

        /// Lower limit of each CPM calibration range
        ///
        /// The entries in this table are Pstates representing the
        /// lowest-numbered (lowest-voltage) Pstate of each range. This is the
        /// inflection point between range N and range N+1.
        Pstate inflectionPoint[CPM_RANGES];

        /// The number of ranges valid in the \a inflectionPoint table
        ///
        /// Validity here is defined by the original characterization
        /// data. Whether or not OCC will use any particular range is managed
        /// by OCC.
        uint8_t validRanges;

        /// The Pstate corresponding to the upper limit of range 0.
        ///
        /// This is the "CPmax" for the mode. The "CPmin" for this
        /// mode is the value of inflectionPoint[valid_ranges - 1].
        Pstate pMax;
        
        uint8_t pad[6];
    };

} CpmPstateModeRanges;


/// The layout of the data created by the Pstate table creation firmware
///
/// This structure is only used for passing Pstate data from the FSP into OCC,
/// therefore there is no alignment requirement.  The \gpst member is copied
/// to an aligned location, and the \a lpsa and \a resclk members are directly
/// installed in hardware.
///
/// Both the master and slave OCCs (in DCM-mode) install their Pstate tables
/// independently via the API gpsm_initialize().  At that point the
/// PstateSuperStructure can be discarded.

typedef struct {

    /// Magic Number
    uint64_t magic;

    /// Global Pstate Table
    GlobalPstateTable gpst;

    /// Local Pstate Array
    LocalPstateArray lpsa;
    
    /// Resonant Clocking Setup
    ResonantClockingSetup resclk;
    
    /// CPM Pstate ranges
    CpmPstateModeRanges cpmranges;
  
} PstateSuperStructure;


int
vid11_validate(Vid11 vid);

int
bias_pstate(Pstate pstate, int bias, Pstate* biased_pstate);

int
bias_frequency(DpllCode fcode, int bias, DpllCode* biased_fcode);

int
bias_vid11(Vid11 vid, int bias, Vid11* biased_fcode);

int
gpst_entry(const GlobalPstateTable* gpst, 
           const Pstate pstate, 
           const int bias,
           gpst_entry_t* entry);


int 
freq2pState (const GlobalPstateTable* gpst, 
             const uint32_t freq_khz, 
             Pstate* pstate);
             
int
gpst_vdd2pstate(const GlobalPstateTable* gpst, 
                const uint8_t vdd, 
                Pstate* pstate,
                gpst_entry_t* entry);

int
pstate_minmax_chk (const GlobalPstateTable* gpst, 
                   Pstate* pstate);

/// Return the Pmin value associated with a GlobalPstateTable
static inline Pstate
gpst_pmin(const GlobalPstateTable* gpst)
{
    return gpst->pmin;
}


/// Return the Pmax value associated with a GlobalPstateTable
static inline Pstate
gpst_pmax(const GlobalPstateTable* gpst)
{
    return (int)(gpst->pmin) + (int)(gpst->entries) - 1;
}

/// Return the Pmin value associated with a LocalPstateTable
static inline Pstate
lpst_pmin(const LocalPstateArray* lpsa)
{
    return lpsa->pmin;
}


/// Return the Pmax value associated with a GlobalPstateTable
static inline Pstate
lpst_pmax(const LocalPstateArray* lpsa)
{
    return (int)(lpsa->pmin) + (int)(lpsa->entries) - 1;
}

#endif    /* __ASSEMBLER__ */

#endif    /* __PSTATES_H__ */
