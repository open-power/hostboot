#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/genHwsvMrwXml.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
# Author:   Van Lee    vanlee@us.ibm.com
#
# Usage:
#
# genHwsvMrwXml.pl --system=systemname --mrwdir=pathname
#                  [--build=hb] [--outfile=XmlFilename]
#        --system=systemname
#              Specify which system MRW XML to be generated
#        --mrwdir=pathname
#              Specify the complete dir pathname of the MRW.
#        --build=hb
#              Specify HostBoot build (hb)
#        --outfile=XmlFilename
#              Specify the filename for the output XML. If omitted, the output
#              is written to STDOUT which can be saved by redirection.
#
# Purpose:
#
#   This perl script processes the various xml files of the MRW to
#   extract the needed information for generating the final xml file.
#
use strict;
use XML::Simple;
use Data::Dumper;

################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------
use constant CHIP_NODE_INDEX => 0; # Position in array of chip's node
use constant CHIP_POS_INDEX => 1; # Position in array of chip's position
use constant CHIP_ATTR_START_INDEX => 2; # Position in array of start of attrs

our $mrwdir = "";
my $sysname = "";
my $usage = 0;
my $DEBUG = 0;
my $outFile = "";
my $build = "fsp";
use Getopt::Long;
GetOptions( "mrwdir:s"  => \$mrwdir,
            "system:s"  => \$sysname,
            "outfile:s" => \$outFile,
            "build:s"   => \$build,
            "DEBUG"     => \$DEBUG,
            "help"      => \$usage, );

if ($usage || ($mrwdir eq ""))
{
    display_help();
    exit 0;
}

our %hwsvmrw_plugins;
# FSP-specific functions
if ($build eq "fsp")
{
    eval("use genHwsvMrwXml_fsp; return 1;");
    genHwsvMrwXml_fsp::return_plugins();
}

if ($outFile ne "")
{
    open OUTFILE, '+>', $outFile ||
                die "ERROR: unable to create $outFile\n";
    select OUTFILE;
}

my $SYSNAME = uc($sysname);
my $CHIPNAME = "";
my $MAXNODE = 0;
if ($sysname eq "brazos")
{
    $MAXNODE = 4;
}

open (FH, "<$mrwdir/${sysname}-mru-ids.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-mru-ids.xml\n";
close (FH);
my $mruAttr = XMLin("$mrwdir/${sysname}-mru-ids.xml");
#------------------------------------------------------------------------------
# Process the system-policy MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-system-policy.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-system-policy.xml\n";
close (FH);
my $sysPolicy = XMLin("$mrwdir/${sysname}-system-policy.xml");
my $reqPol = $sysPolicy->{"required-policy-settings"};

my @systemAttr; # Repeated {ATTR, VAL, ATTR, VAL, ATTR, VAL...}

#@TODO RTC: 66365
# Setting ALL_MCS_IN_INTERLEAVING_GROUP to zero. Need to replace with:
# $reqPol->{'all_mcs_in_interleaving_group"}

#No mirroring supported yet so the policy is just based on multi-node or not
my $placement = 0x0; #NORMAL
if ($sysname eq "brazos")
{
    $placement = 0x3; #DRAWER
}


push @systemAttr,
[
    "FREQ_PROC_REFCLOCK", $reqPol->{'processor-refclock-frequency'}->{content},
    "FREQ_PROC_REFCLOCK_KHZ",
        $reqPol->{'processor-refclock-frequency-khz'}->{content},
    "FREQ_MEM_REFCLOCK", $reqPol->{'memory-refclock-frequency'}->{content},
    "ALL_MCS_IN_INTERLEAVING_GROUP", "0",
    "BOOT_FREQ_MHZ", $reqPol->{'boot-frequency'}->{content},
    "FREQ_A", $reqPol->{'proc_a_frequency'}->{content},
    "FREQ_PB", $reqPol->{'proc_pb_frequency'}->{content},
    "NEST_FREQ_MHZ", $reqPol->{'proc_pb_frequency'}->{content},
    "FREQ_PCIE", $reqPol->{'proc_pcie_frequency'}->{content},
    "FREQ_X", $reqPol->{'proc_x_frequency'}->{content},
    "MSS_CLEANER_ENABLE", $reqPol->{'mss_cleaner_enable'},
    "MSS_MBA_ADDR_INTERLEAVE_BIT", $reqPol->{'mss_mba_addr_interleave_bit'},
    "MSS_MBA_CACHELINE_INTERLEAVE_MODE",
        $reqPol->{'mss_mba_cacheline_interleave_mode'},
    "MSS_PREFETCH_ENABLE", $reqPol->{'mss_prefetch_enable'},
    "PROC_EPS_TABLE_TYPE", $reqPol->{'proc_eps_table_type'},
    "PROC_FABRIC_PUMP_MODE", $reqPol->{'proc_fabric_pump_mode'},
    "PROC_X_BUS_WIDTH", $reqPol->{'proc_x_bus_width'},
    "X_EREPAIR_THRESHOLD_FIELD", $reqPol->{'x-erepair-threshold-field'},
    "A_EREPAIR_THRESHOLD_FIELD", $reqPol->{'a-erepair-threshold-field'},
    "DMI_EREPAIR_THRESHOLD_FIELD", $reqPol->{'dmi-erepair-threshold-field'},
    "X_EREPAIR_THRESHOLD_MNFG", $reqPol->{'x-erepair-threshold-mnfg'},
    "A_EREPAIR_THRESHOLD_MNFG", $reqPol->{'a-erepair-threshold-mnfg'},
    "DMI_EREPAIR_THRESHOLD_MNFG", $reqPol->{'dmi-erepair-threshold-mnfg'},
    "MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA",
        $reqPol->{'safemode_mem_throttle_numerator_per_mba'},
    "MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR",
        $reqPol->{'safemode_mem_throttle_denominator'},
    "MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP",
        $reqPol->{'safemode_mem_throttle_numerator_per_chip'},
    "MRW_THERMAL_MEMORY_POWER_LIMIT", $reqPol->{'thermal_memory_power_limit'},
    "PM_EXTERNAL_VRM_STEPSIZE", $reqPol->{'pm_external_vrm_stepsize'},
    "PM_EXTERNAL_VRM_STEPDELAY", $reqPol->{'pm_external_vrm_stepdelay'},
    "PM_SPIVID_FREQUENCY", $reqPol->{'pm_spivid_frequency'}->{content},
    "PM_SAFE_FREQUENCY", $reqPol->{'pm_safe_frequency'}->{content},
    "PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY",
        $reqPol->{'pm_resonant_clock_full_clock_sector_buffer_frequency'}->
            {content},
    "PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY",
        $reqPol->{'pm_resonant_clock_low_band_lower_frequency'}->{content},
    "PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY",
        $reqPol->{'pm_resonant_clock_low_band_upper_frequency'}->{content},
    "PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY",
        $reqPol->{'pm_resonant_clock_high_band_lower_frequency'}->{content},
    "PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY",
        $reqPol->{'pm_resonant_clock_high_band_upper_frequency'}->{content},
    "PM_SPIPSS_FREQUENCY", $reqPol->{'pm_spipss_frequency'}->{content},
    "PROC_R_LOADLINE_VDD", $reqPol->{'proc_r_loadline_vdd'},
    "PROC_R_DISTLOSS_VDD", $reqPol->{'proc_r_distloss_vdd'},
    "PROC_VRM_VOFFSET_VDD", $reqPol->{'proc_vrm_voffset_vdd'},
    "PROC_R_LOADLINE_VCS", $reqPol->{'proc_r_loadline_vcs'},
    "PROC_R_DISTLOSS_VCS", $reqPol->{'proc_r_distloss_vcs'},
    "PROC_VRM_VOFFSET_VCS", $reqPol->{'proc_vrm_voffset_vcs'},
    "MEM_MIRROR_PLACEMENT_POLICY", $placement,
];

#------------------------------------------------------------------------------
# Process the pm-settings MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-pm-settings.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-pm-settings.xml\n";
close (FH);
my $pmSettings = XMLin("$mrwdir/${sysname}-pm-settings.xml");

my @pmChipAttr; # Repeated [NODE, POS, ATTR, VAL, ATTR, VAL, ATTR, VAL...]

foreach my $i (@{$pmSettings->{'processor-settings'}})
{
    push @pmChipAttr,
    [
        $i->{target}->{node}, $i->{target}->{position},
        "PM_UNDERVOLTING_FRQ_MINIMUM",
            $i->{pm_undervolting_frq_minimum}->{content},
        "PM_UNDERVOLTING_FREQ_MAXIMUM",
            $i->{pm_undervolting_frq_maximum}->{content},
        "PM_SPIVID_PORT_ENABLE", $i->{pm_spivid_port_enable},
        "PM_APSS_CHIP_SELECT", $i->{pm_apss_chip_select},
        "PM_PBAX_NODEID", $i->{pm_pbax_nodeid},
        "PM_PBAX_CHIPID", $i->{pm_pbax_chipid},
        "PM_PBAX_BRDCST_ID_VECTOR", $i->{pm_pbax_brdcst_id_vector},
        "PM_SLEEP_ENTRY", $i->{pm_sleep_entry},
        "PM_SLEEP_EXIT", $i->{pm_sleep_exit},
        "PM_SLEEP_TYPE", $i->{pm_sleep_type},
        "PM_WINKLE_ENTRY", $i->{pm_winkle_entry},
        "PM_WINKLE_EXIT", $i->{pm_winkle_exit},
        "PM_WINKLE_TYPE", $i->{pm_winkle_type},
    ]
}

my @SortedPmChipAttr = sort byNodePos @pmChipAttr;

if ((scalar @SortedPmChipAttr) == 0)
{
    # For all systems without a populated <sys>-pm-settings file, this script
    # defaults the values.
    # Orlena: Platform dropped so there will never be a populated
    #         orlena-pm-settings file
    # Brazos: SW231069 raised to get brazos-pm-settings populated
    print STDOUT "WARNING: No data in $mrwdir/${sysname}-pm-settings.xml. Defaulting values\n";
}

#------------------------------------------------------------------------------
# Process the proc-pcie-settings MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-proc-pcie-settings.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-proc-pcie-settings.xml\n";
close (FH);
my $ProcPcie = XMLin("$mrwdir/${sysname}-proc-pcie-settings.xml");

# Repeated [NODE, POS, ATTR, IOP0-VAL, IOP1-VAL, ATTR, IOP0-VAL, IOP1-VAL]
my @procPcie;
foreach my $i (@{$ProcPcie->{'processor-settings'}})
{
    push @procPcie, [$i->{target}->{node},
                     $i->{target}->{position},
                     "PROC_PCIE_IOP_G2_PLL_CONTROL0",
                     $i->{proc_pcie_iop_g2_pll_control0_iop0},
                     $i->{proc_pcie_iop_g2_pll_control0_iop1},
                     "PROC_PCIE_IOP_G3_PLL_CONTROL0",
                     $i->{proc_pcie_iop_g3_pll_control0_iop0},
                     $i->{proc_pcie_iop_g3_pll_control0_iop1},
                     "PROC_PCIE_IOP_PCS_CONTROL0",
                     $i->{proc_pcie_iop_pcs_control0_iop0},
                     $i->{proc_pcie_iop_pcs_control0_iop1},
                     "PROC_PCIE_IOP_PCS_CONTROL1",
                     $i->{proc_pcie_iop_pcs_control1_iop0},
                     $i->{proc_pcie_iop_pcs_control1_iop1},
                     "PROC_PCIE_IOP_PLL_GLOBAL_CONTROL0",
                     $i->{proc_pcie_iop_pll_global_control0_iop0},
                     $i->{proc_pcie_iop_pll_global_control0_iop1},
                     "PROC_PCIE_IOP_PLL_GLOBAL_CONTROL1",
                     $i->{proc_pcie_iop_pll_global_control1_iop0},
                     $i->{proc_pcie_iop_pll_global_control1_iop1},
                     "PROC_PCIE_IOP_RX_PEAK",
                     $i->{proc_pcie_iop_rx_peak_iop0},
                     $i->{proc_pcie_iop_rx_peak_iop1},
                     "PROC_PCIE_IOP_RX_SDL",
                     $i->{proc_pcie_iop_rx_sdl_iop0},
                     $i->{proc_pcie_iop_rx_sdl_iop1},
                     "PROC_PCIE_IOP_RX_VGA_CONTROL2",
                     $i->{proc_pcie_iop_rx_vga_control2_iop0},
                     $i->{proc_pcie_iop_rx_vga_control2_iop1},
                     "PROC_PCIE_IOP_TX_BWLOSS1",
                     $i->{proc_pcie_iop_tx_bwloss1_iop0},
                     $i->{proc_pcie_iop_tx_bwloss1_iop1},
                     "PROC_PCIE_IOP_TX_FIFO_OFFSET",
                     $i->{proc_pcie_iop_tx_fifo_offset_iop0},
                     $i->{proc_pcie_iop_tx_fifo_offset_iop1},
                     "PROC_PCIE_IOP_TX_RCVRDETCNTL",
                     $i->{proc_pcie_iop_tx_rcvrdetcntl_iop0},
                     $i->{proc_pcie_iop_tx_rcvrdetcntl_iop1},
                     "PROC_PCIE_IOP_ZCAL_CONTROL",
                     $i->{proc_pcie_iop_zcal_control_iop0},
                     $i->{proc_pcie_iop_zcal_control_iop1}];
}

my @SortedPcie = sort byNodePos @procPcie;

#------------------------------------------------------------------------------
# Process the chip-ids MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-chip-ids.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-chip-ids.xml\n";
close (FH);
my $chipIds = XMLin("$mrwdir/${sysname}-chip-ids.xml");

use constant CHIP_ID_NODE => 0;
use constant CHIP_ID_POS  => 1;
use constant CHIP_ID_PATH => 2;
use constant CHIP_ID_NXPX => 3;

my @chipIDs;
foreach my $i (@{$chipIds->{'chip-id'}})
{
    push @chipIDs, [ $i->{node}, $i->{position}, $i->{'instance-path'},
                     "n$i->{target}->{node}:p$i->{target}->{position}" ];
}

#------------------------------------------------------------------------------
# Process the power-busses MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-power-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-power-busses.xml\n";
close (FH);
my $powerbus = XMLin("$mrwdir/${sysname}-power-busses.xml");

my @pbus;
use constant PBUS_FIRST_END_POINT_INDEX => 0;
use constant PBUS_SECOND_END_POINT_INDEX => 1;
use constant PBUS_DOWNSTREAM_INDEX => 2;
use constant PBUS_UPSTREAM_INDEX => 3;
use constant PBUS_TX_MSB_LSB_SWAP => 4;
use constant PBUS_RX_MSB_LSB_SWAP => 5;
use constant PBUS_ENDPOINT_INSTANCE_PATH => 6;
foreach my $i (@{$powerbus->{'power-bus'}})
{
    # Pull out the connection information from the description
    # example: n0:p0:A2 to n0:p2:A2

    my $endp1 = $i->{'description'};
    my $endp2 = "null";
    my $dwnstrm_swap = 0;
    my $upstrm_swap = 0;

    my $present = index $endp1, 'not connected';
    if ($present eq -1)
    {
       $endp2 = $endp1;
       $endp1 =~ s/^(.*) to.*/$1/;
       $endp2 =~ s/.* to (.*)\s*$/$1/;

       # Grab the lane swap information
       $dwnstrm_swap = $i->{'downstream-n-p-lane-swap-mask'};
       $upstrm_swap =  $i->{'upstream-n-p-lane-swap-mask'};
    }
    else
    {
       $endp1 =~ s/^(.*) unit.*/$1/;
       $endp2 = "invalid";


       # Set the lane swap information to 0 to avoid junk
       $dwnstrm_swap = 0;
       $upstrm_swap =  0;
    }

    my $bustype = $endp1;
    $bustype =~ s/.*:p.*:(.).*/$1/;
    my $tx_swap = 0;
    my $rx_swap = 0;
    if (lc($bustype) eq "a")
    {
        $tx_swap =  $i->{'tx-msb-lsb-swap'};
        $rx_swap =  $i->{'rx-msb-lsb-swap'};
        $tx_swap = ($tx_swap eq "false") ? 0 : 1;
        $rx_swap = ($rx_swap eq "false") ? 0 : 1;
    }

    my $endpoint1_ipath = $i->{'endpoint'}[0]->{'instance-path'};
    my $endpoint2_ipath = $i->{'endpoint'}[1]->{'instance-path'};
    #print STDOUT "powerbus: $endp1, $endp2, $dwnstrm_swap, $upstrm_swap\n";
    push @pbus, [ lc($endp1), lc($endp2), $dwnstrm_swap,
                  $upstrm_swap, $tx_swap, $rx_swap, $endpoint1_ipath ];
    push @pbus, [ lc($endp2), lc($endp1), $dwnstrm_swap,
                  $upstrm_swap, $tx_swap, $rx_swap, $endpoint2_ipath ];
}

#------------------------------------------------------------------------------
# Process the dmi-busses MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-dmi-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-dmi-busses.xml\n";
close (FH);
my $dmibus = XMLin("$mrwdir/${sysname}-dmi-busses.xml");

my @dbus_mcs;
use constant DBUS_MCS_NODE_INDEX => 0;
use constant DBUS_MCS_PROC_INDEX => 1;
use constant DBUS_MCS_UNIT_INDEX => 2;
use constant DBUS_MCS_DOWNSTREAM_INDEX => 3;
use constant DBUS_MCS_TX_SWAP_INDEX => 4;
use constant DBUS_MCS_RX_SWAP_INDEX => 5;
use constant DBUS_MCS_SWIZZLE_INDEX => 6;

my @dbus_centaur;
use constant DBUS_CENTAUR_NODE_INDEX => 0;
use constant DBUS_CENTAUR_MEMBUF_INDEX => 1;
use constant DBUS_CENTAUR_UPSTREAM_INDEX => 2;
use constant DBUS_CENTAUR_TX_SWAP_INDEX => 3;
use constant DBUS_CENTAUR_RX_SWAP_INDEX => 4;
foreach my $dmi (@{$dmibus->{'dmi-bus'}})
{
    # First grab the MCS information
    # MCS is always master so it gets downstream
    my $node = $dmi->{'mcs'}->{'target'}->{'node'};
    my $proc = $dmi->{'mcs'}->{'target'}->{'position'};
    my $mcs = $dmi->{'mcs'}->{'target'}->{'chipUnit'};
    my $swap = $dmi->{'downstream-n-p-lane-swap-mask'};
    my $tx_swap = $dmi->{'tx-msb-lsb-swap'};
    my $rx_swap = $dmi->{'rx-msb-lsb-swap'};
    $tx_swap = ($tx_swap eq "false") ? 0 : 1;
    $rx_swap = ($rx_swap eq "false") ? 0 : 1;
    my $swizzle = $dmi->{'mcs-refclock-enable-mapping'};
    #print STDOUT "dbus_mcs: n$node:p$proc:mcs:$mcs swap:$swap\n";
    push @dbus_mcs, [ $node, $proc, $mcs, $swap, $tx_swap, $rx_swap, $swizzle ];

    # Now grab the centuar chip information
    # Centaur is always slave so it gets upstream
    my $node = $dmi->{'centaur'}->{'target'}->{'node'};
    my $membuf = $dmi->{'centaur'}->{'target'}->{'position'};
    my $swap = $dmi->{'upstream-n-p-lane-swap-mask'};
    my $tx_swap = $dmi->{'rx-msb-lsb-swap'};
    my $rx_swap = $dmi->{'tx-msb-lsb-swap'};
    $tx_swap = ($tx_swap eq "false") ? 0 : 1;
    $rx_swap = ($rx_swap eq "false") ? 0 : 1;
    #print STDOUT "dbus_centaur: n$node:cen$membuf swap:$swap\n";
    push @dbus_centaur, [ $node, $membuf, $swap, $tx_swap, $rx_swap ];
}

#------------------------------------------------------------------------------
# Process the cent-vrds MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-cent-vrds.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-cent-vrds.xml\n";
close (FH);
my $vmemCentaur = XMLin("$mrwdir/${sysname}-cent-vrds.xml");

# Capture all pnor attributes into the @unsortedPnorTargets array
use constant VMEM_DEV_PATH_FIELD => 0;
use constant VMEM_I2C_ADDR_FIELD => 1;
use constant VMEM_ID_FIELD => 2;
use constant VMEM_NODE_FIELD => 3;
use constant VMEM_POS_FIELD => 4;

my $vmemId = 0x0;

my @unsortedVmem;
my @vmemArray;
my @vmemDevAddr;
my $vmemValue =0;
my $found=0;
my $loc=0;
my $newValue =0;

foreach my $i (@{$vmemCentaur->{'centaur-vrd-connection'}})
{
    my $vmemDev = $i->{'vrd'}->{'i2c-dev-path'};
    my $vmemAddr = $i->{'vrd'}->{'i2c-address'};

    for my $j (0 .. $#vmemDevAddr)
    {
        if ( ($vmemDev eq $vmemDevAddr[$j][VMEM_DEV_PATH_FIELD]) &&
             ($vmemAddr eq $vmemDevAddr[$j][VMEM_I2C_ADDR_FIELD]) )
        {
            $found =1;
            $vmemValue=$vmemDevAddr[$j][VMEM_ID_FIELD];
            last;
        }
        else
        {
            $found=0;
        }
    }
    if ($found ==0)
    {
        $vmemValue=$newValue++;
        push (@vmemDevAddr,[$vmemDev, $vmemAddr, $vmemValue]);
    }


    my $vmemNode = $i->{'centaur'}->{'target'}->{'node'};
    my $vmemPosition = $i->{'centaur'}->{'target'}->{'position'};

    push (@unsortedVmem,[$vmemDev, $vmemAddr, $vmemValue, $vmemNode,
                         $vmemPosition]);
}


my @SortedVmem = sort byVmemNodePos @unsortedVmem;

#------------------------------------------------------------------------------
# Process the cec-chips and pcie-busses MRW files
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-cec-chips.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-cec-chips.xml\n";
close (FH);
my $devpath = XMLin("$mrwdir/${sysname}-cec-chips.xml",
                        KeyAttr=>'instance-path');

open (FH, "<$mrwdir/${sysname}-pcie-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-pcie-busses.xml\n";
close (FH);
my $pcie_buses = XMLin("$mrwdir/${sysname}-pcie-busses.xml");

our %pcie_list;

foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{
    if(!exists($pcie_bus->{'switch'}))
    {
        foreach my $lane_set (0,1)
        {
            $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                                            {source}->{iop}}->{$lane_set}->
                                            {'lane-mask'} = 0;
            $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                                            {source}->{iop}}->{$lane_set}->
                                            {'dsmp-capable'} = 0;
            $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                                            {source}->{iop}}->{$lane_set}->
                                            {'lane-swap'} = 0;
            $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                                            {source}->{iop}}->{$lane_set}->
                                            {'lane-reversal'} = 0;
            $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                                            {source}->{iop}}->{$lane_set}->
                                            {'is-slot'} = 0;
        }
    }
}

foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{
    if(!exists($pcie_bus->{'switch'}))
    {
        my $dsmp_capable = 0;
        my $is_slot = 0;
        if((exists($pcie_bus->{source}->{'dsmp-capable'}))&&
          ($pcie_bus->{source}->{'dsmp-capable'} eq 'Yes'))
        {

            $dsmp_capable = 1;
        }

        if((exists($pcie_bus->{endpoint}->{'is-slot'}))&&
          ($pcie_bus->{endpoint}->{'is-slot'} eq 'Yes'))
        {

            $is_slot = 1;
        }
        my $lane_set = 0;
        if(($pcie_bus->{source}->{'lane-mask'} eq '0xFFFF')||
           ($pcie_bus->{source}->{'lane-mask'} eq '0xFF00'))
        {
            $lane_set = 0;
        }
        else
        {
            if($pcie_bus->{source}->{'lane-mask'} eq '0x00FF')
            {
                $lane_set = 1;
            }

        }
        $pcie_list{$pcie_bus->{source}->{'instance-path'}}->
            {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-mask'}
                = $pcie_bus->{source}->{'lane-mask'};
        $pcie_list{$pcie_bus->{source}->{'instance-path'}}->
            {$pcie_bus->{source}->{iop}}->{$lane_set}->{'dsmp-capable'}
                = $dsmp_capable;
        $pcie_list{$pcie_bus->{source}->{'instance-path'}}->
            {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-swap'}
                = oct($pcie_bus->{source}->{'lane-swap-bits'});
        $pcie_list{$pcie_bus->{source}->{'instance-path'}}->
            {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-reversal'}
                = oct($pcie_bus->{source}->{'lane-reversal-bits'});
        $pcie_list{$pcie_bus->{source}->{'instance-path'}}->
            {$pcie_bus->{source}->{iop}}->{$lane_set}->{'is-slot'} = $is_slot;
    }
}
our %bifurcation_list;
foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{
    if(!exists($pcie_bus->{'switch'}))
    {
        foreach my $lane_set (0,1)
        {
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-mask'}= 0;
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-swap'}= 0;
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                {$pcie_bus->{source}->{iop}}->{$lane_set}->{'lane-reversal'}= 0;
        }
    }
}
foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{
    if(   (!exists($pcie_bus->{'switch'}))
       && (exists($pcie_bus->{source}->{'bifurcation-settings'})))
    {
        my $bi_cnt = 0;
        foreach my $bifurc (@{$pcie_bus->{source}->{'bifurcation-settings'}->
                                                   {'bifurcation-setting'}})
        {
            my $lane_swap = 0;
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                             {$pcie_bus->{source}->{iop}}{$bi_cnt}->
                             {'lane-mask'} =  $bifurc->{'lane-mask'};
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                             {$pcie_bus->{source}->{iop}}{$bi_cnt}->
                             {'lane-swap'} =  oct($bifurc->{'lane-swap-bits'});
            $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->
                             {$pcie_bus->{source}->{iop}}{$bi_cnt}->
                             {'lane-reversal'} = oct($bifurc->
                             {'lane-reversal-bits'});
            $bi_cnt++;

        }


    }
}

#------------------------------------------------------------------------------
# Process the targets MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-targets.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-targets.xml\n";
close (FH);
my $eTargets = XMLin("$mrwdir/${sysname}-targets.xml");

# Capture all targets into the @Targets array
use constant NAME_FIELD => 0;
use constant NODE_FIELD => 1;
use constant POS_FIELD  => 2;
use constant UNIT_FIELD => 3;
use constant PATH_FIELD => 4;
use constant LOC_FIELD  => 5;
use constant ORDINAL_FIELD  => 6;
use constant FRU_PATH => 7;
use constant PLUG_POS => 8;
my @Targets;
foreach my $i (@{$eTargets->{target}})
{
    my $plugPosition = $i->{'plug-xpath'};
    my $frupath = "";
    $plugPosition =~ s/.*mrw:position\/text\(\)=\'(.*)\'\]$/$1/;
    if (exists $devpath->{chip}->{$i->{'instance-path'}}->{'fru-instance-path'})
    {
        $frupath = $devpath->{chip}->{$i->{'instance-path'}}->
                                          {'fru-instance-path'};
    }

    push @Targets, [ $i->{'ecmd-common-name'}, $i->{node}, $i->{position},
                     $i->{'chip-unit'}, $i->{'instance-path'}, $i->{location},
                      0,$frupath, $plugPosition ];

    if (($i->{'ecmd-common-name'} eq "pu") && ($CHIPNAME eq ""))
    {
        $CHIPNAME = $i->{'description'};
        $CHIPNAME =~ s/Instance of (.*) cpu/$1/g;
        $CHIPNAME = lc($CHIPNAME);
    }
}

#------------------------------------------------------------------------------
# Process the fsi-busses MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-fsi-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-fsi-busses.xml\n";
close (FH);
my $fsiBus = XMLin("$mrwdir/${sysname}-fsi-busses.xml");

# Capture all FSI connections into the @Fsis array
# Save the FSP node id
use constant FSI_TYPE_FIELD   => 0;
use constant FSI_LINK_FIELD   => 1;
use constant FSI_TARGET_FIELD => 2;
use constant FSI_MASTER_FIELD => 3;
use constant FSI_TARGET_TYPE  => 4;
my @Fsis;

# Build all the FSP chip targets / attributes
my %FSPs = ();
foreach my $fsiBus (@{$fsiBus->{'fsi-bus'}})
{
    # FSP always has master type of FSP master; Add unique ones
    my $instancePathKey = $fsiBus->{master}->{'instance-path'};
    if (    (lc($fsiBus->{master}->{type}) eq "fsp master")
        && !(exists($FSPs{$instancePathKey})))
    {
        my $node = $fsiBus->{master}->{target}->{node};
        my $position = $fsiBus->{master}->{target}->{position};
        my $huid = sprintf("0x%02X15%04X",$node,$position);
        my $rid = sprintf("0x%08X", 0x200 + $position);
        my $sys = "0";
        $FSPs{$instancePathKey} = {
            'sys'         => $sys,
            'node'        => $node,
            'position'    => $position,
            'ordinalId'   => $position,
            'instancePath'=> $fsiBus->{master}->{'instance-path'},
            'huid'        => $huid,
            'rid'         => $rid,
        };
    }

    push @Fsis, [ $fsiBus->{master}->{type}, $fsiBus->{master}->{link},
        "n$fsiBus->{slave}->{target}->{node}:"
        . "p$fsiBus->{slave}->{target}->{position}",
        "n$fsiBus->{master}->{target}->{node}:"
         . "p$fsiBus->{master}->{target}->{position}",
        $fsiBus->{slave}->{target}->{name} ];
}

#------------------------------------------------------------------------------
# Process the psi-busses MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-psi-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-psi-busses.xml\n";
close (FH);
our $psiBus = XMLin("$mrwdir/${sysname}-psi-busses.xml",
                      forcearray=>['psi-bus']);

# Capture all PSI connections into the @hbPSIs array
use constant HB_PSI_MASTER_CHIP_POSITION_FIELD  => 0;
use constant HB_PSI_MASTER_CHIP_UNIT_FIELD      => 1;
use constant HB_PSI_PROC_NODE_FIELD             => 2;
use constant HB_PSI_PROC_POS_FIELD              => 3;

my @hbPSIs;
foreach my $i (@{$psiBus->{'psi-bus'}})
{
    push @hbPSIs, [
                  $i->{fsp}->{'psi-unit'}->{target}->{position},
                  $i->{fsp}->{'psi-unit'}->{target}->{chipUnit},
                  $i->{processor}->{target}->{node},
                  $i->{processor}->{target}->{position},
                ];
}

#------------------------------------------------------------------------------
# Process the memory-busses MRW file
#------------------------------------------------------------------------------
open (FH, "<$mrwdir/${sysname}-memory-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-memory-busses.xml\n";
close (FH);
my $memBus = XMLin("$mrwdir/${sysname}-memory-busses.xml");

# Capture all memory buses info into the @Membuses array
use constant MCS_TARGET_FIELD     => 0;
use constant CENTAUR_TARGET_FIELD => 1;
use constant DIMM_TARGET_FIELD    => 2;
use constant DIMM_PATH_FIELD      => 3;
use constant CFSI_LINK_FIELD      => 4;
use constant BUS_NODE_FIELD       => 5;
use constant BUS_POS_FIELD        => 6;
use constant BUS_ORDINAL_FIELD    => 7;
use constant DIMM_POS_FIELD       => 8;

use constant CDIMM_RID_NODE_MULTIPLIER => 32;

my @Membuses;
foreach my $i (@{$memBus->{'memory-bus'}})
{
    push @Membuses, [
         "n$i->{mcs}->{target}->{node}:p$i->{mcs}->{target}->{position}:mcs" .
         $i->{mcs}->{target}->{chipUnit},
         "n$i->{mba}->{target}->{node}:p$i->{mba}->{target}->{position}:mba" .
         $i->{mba}->{target}->{chipUnit},
         "n$i->{dimm}->{target}->{node}:p$i->{dimm}->{target}->{position}",
         $i->{dimm}->{'instance-path'}, $i->{'fsi-link'},
         $i->{mcs}->{target}->{node},
         $i->{mcs}->{target}->{position}, 0,
         $i->{dimm}->{'instance-path'} ];
}

# Sort the memory busses, based on their Node, Pos & instance paths
my @SMembuses = sort byDimmNodePos @Membuses;
my $BOrdinal_ID = 0;

# Increment the Ordinal ID in sequential order for dimms.
for my $i ( 0 .. $#SMembuses )
{
    $SMembuses[$i] [BUS_ORDINAL_FIELD] = $BOrdinal_ID;
    $BOrdinal_ID += 1;
}

# Rewrite each DIMM instance path's DIMM instance to be indexed from 0
for my $i ( 0 .. $#SMembuses )
{
    $SMembuses[$i][DIMM_PATH_FIELD] =~ s/[0-9]*$/$i/;
}

# Generate @STargets array from the @Targets array to have the order as shown
# belows. The rest of the codes assume that this order is in place
#
#   pu
#   ex  (one or more EX of pu before it)
#   core
#   mcs (one or more MCS of pu before it)
#   (Repeat for remaining pu)
#   memb
#   mba (to for membuf before it)
#   L4
#   (Repeat for remaining membuf)
#

# Sort the target array based on Target Type,Node,Position and Chip-Unit.
my @SortedTargets = sort byTargetTypeNodePosChipunit @Targets;
my $Type = $SortedTargets[0][NAME_FIELD];
my $ordinal_ID = 0;

# Increment the Ordinal ID in sequential order for same family Type.
for my $i ( 0 .. $#SortedTargets )
{
    if($SortedTargets[$i][NAME_FIELD] ne $Type)
    {
       $ordinal_ID = 0;
    }
    $SortedTargets[$i] [ORDINAL_FIELD] = $ordinal_ID;
    $Type = $SortedTargets[$i][NAME_FIELD];
    $ordinal_ID += 1;
}

my @fields;
my @STargets;
for my $i ( 0 .. $#SortedTargets )
{
    if ($SortedTargets[$i][NAME_FIELD] eq "pu")
    {
        for my $k ( 0 .. PLUG_POS )
        {
            $fields[$k] = $SortedTargets[$i][$k];
        }
        push @STargets, [ @fields ];

        my $node = $SortedTargets[$i][NODE_FIELD];
        my $position = $SortedTargets[$i][POS_FIELD];

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "ex") &&
                ($SortedTargets[$j][NODE_FIELD] eq $node) &&
                ($SortedTargets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. PLUG_POS )
                {
                    $fields[$k] = $SortedTargets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "core") &&
                ($SortedTargets[$j][NODE_FIELD] eq $node) &&
                ($SortedTargets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. PLUG_POS )
                {
                    $fields[$k] = $SortedTargets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "mcs") &&
                ($SortedTargets[$j][NODE_FIELD] eq $node) &&
                ($SortedTargets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. PLUG_POS )
                {
                    $fields[$k] = $SortedTargets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }
    }
}

for my $i ( 0 .. $#SortedTargets )
{
    if ($SortedTargets[$i][NAME_FIELD] eq "memb")
    {
        for my $k ( 0 .. PLUG_POS )
        {
            $fields[$k] = $SortedTargets[$i][$k];
        }
        push @STargets, [ @fields ];

        my $node = $SortedTargets[$i][NODE_FIELD];
        my $position = $SortedTargets[$i][POS_FIELD];

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "mba") &&
                ($SortedTargets[$j][NODE_FIELD] eq $node) &&
                ($SortedTargets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. PLUG_POS )
                {
                    $fields[$k] = $SortedTargets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }

        for my $p ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$p][NAME_FIELD] eq "L4") &&
                ($SortedTargets[$p][NODE_FIELD] eq $node) &&
                ($SortedTargets[$p][POS_FIELD] eq $position))
            {
                for my $q ( 0 .. PLUG_POS )
                {
                    $fields[$q] = $SortedTargets[$p][$q];
                }
                push @STargets, [ @fields ];
            }
        }
    }
}

# Finally, generate the xml file.
print "<!-- Source path = $mrwdir -->\n";

print "<attributes>\n";

# First, generate system target (always sys0)
my $sys = 0;
generate_sys();

my $node = 0;
my $Mproc = 0;
my $fru_id = 0;
my @fru_paths;
my $hasProc = 0;
my $hash_ax_buses;
my $axBusesHuidInit = 0;
my $vmem_count =0;

for (my $curnode = 0; $curnode <= $MAXNODE; $curnode++)
{

$node = $curnode;
$hasProc = 0;

# find master proc of this node
for my $i ( 0 .. $#Fsis )
{
    my $nodeId = lc($Fsis[$i][FSI_TARGET_FIELD]);
    $nodeId =~ s/.*n(.*):.*$/$1/;
    if ((lc($Fsis[$i][FSI_TYPE_FIELD]) eq "fsp master") &&
        (($Fsis[$i][FSI_TARGET_TYPE]) eq "pu") &&
        ($nodeId eq $node))
    {
        $Mproc = $Fsis[$i][FSI_TARGET_FIELD];
        $Mproc =~ s/.*p(.*)/$1/;
        $hasProc = 1;
        last;
    }
}

# Second, generate system node

generate_system_node();

# Third, generate the FSP chip(s)
foreach my $fsp ( keys %FSPs )
{
    if( $FSPs{$fsp}{node} eq $node )
    {
        my $fspChipHashRef = (\%FSPs)->{$fsp};
        do_plugin('fsp_chip', $fspChipHashRef);
    }
}

if ($hasProc == 0)
{
    next;
}

#preCalculate HUID for A-Bus
if($axBusesHuidInit == 0)
{
    $axBusesHuidInit = 1;
    for (my $my_curnode = 0; $my_curnode <= $MAXNODE; $my_curnode++)
    {
        for (my $do_core = 0, my $i = 0; $i <= $#STargets; $i++)
        {
            if ($STargets[$i][NODE_FIELD] != $my_curnode)
            {
                next;
            }
            if ($STargets[$i][NAME_FIELD] eq "mcs")
            {
                my $proc = $STargets[$i][POS_FIELD];
                if (($STargets[$i+1][NAME_FIELD] eq "pu") ||
                        ($STargets[$i+1][NAME_FIELD] eq "memb"))
                {
                    preCalculateAxBusesHUIDs($my_curnode, $proc, "A");
                    preCalculateAxBusesHUIDs($my_curnode, $proc, "X");
                }
            }
        }
    }
}

# Fourth, generate the proc, occ, ex-chiplet, mcs-chiplet
# unit-tp (if on fsp), pcie bus and A/X-bus.
my $ex_count = 0;
my $ex_core_count = 0;
my $mcs_count = 0;
my $proc_ordinal_id =0;
#my $fru_id = 0;
#my @fru_paths;
my $hwTopology =0;

for (my $do_core = 0, my $i = 0; $i <= $#STargets; $i++)
{
    if ($STargets[$i][NODE_FIELD] != $node)
    {
        next;
    }

    my $ipath = $STargets[$i][PATH_FIELD];
    if ($STargets[$i][NAME_FIELD] eq "pu")
    {
        my $fru_found = 0;
        my $fru_path = $STargets[$i][FRU_PATH];
        my $proc = $STargets[$i][POS_FIELD];
        $proc_ordinal_id = $STargets[$i][ORDINAL_FIELD];

        use constant FRU_PATHS => 0;
        use constant FRU_ID => 1;

        $hwTopology = $STargets[$i][NODE_FIELD] << 12;
        $fru_path  =~ m/.*-([0-9]*)$/;
        $hwTopology |= $1 <<8;
        $ipath =~ m/.*-([0-9]*)$/;
        $hwTopology |= $1 <<4;
        my $lognode;
        my $logid;
        for (my $j = 0; $j <= $#chipIDs; $j++)
        {
            if ($chipIDs[$j][CHIP_ID_PATH] eq $ipath)
            {
                $lognode = $chipIDs[$j][CHIP_ID_NODE];
                $logid = $chipIDs[$j][CHIP_ID_POS];
                last;
            }
        }

        if($#fru_paths < 0)
        {
            $fru_id = 0;
            push @fru_paths, [ $fru_path, $fru_id ];
        }
        else
        {
            for (my $k = 0; $k <= $#fru_paths; $k++)
            {
                if ( $fru_paths[$k][FRU_PATHS] eq $fru_path)
                {
                    $fru_id =  $fru_paths[$k][FRU_ID];
                    $fru_found = 1;
                    last;
                }

            }
            if ($fru_found == 0)
            {
                $fru_id = $#fru_paths + 1;
                push @fru_paths, [ $fru_path, $fru_id ];
            }
        }
        if ($proc eq $Mproc)
        {
            generate_proc($proc, $ipath, $lognode, $logid,
                                 $proc_ordinal_id, 1, 0, 0,$fru_id,$hwTopology);
        }
        else
        {
            my $fsi;
            for (my $j = 0; $j <= $#Fsis; $j++)
            {
                if (($Fsis[$j][FSI_TARGET_FIELD] eq "n${node}:p$proc") &&
                    ($Fsis[$j][FSI_TARGET_TYPE] eq "pu") &&
                    ($Fsis[$j][FSI_MASTER_FIELD] eq "n${node}:p$Mproc"))
                {
                    $fsi = $Fsis[$j][FSI_LINK_FIELD];
                    last;
                }
            }
            generate_proc($proc, $ipath, $lognode, $logid,
                          $proc_ordinal_id, 0, 1, $fsi,$fru_id,$hwTopology);
        }

        # call to do any fsp per-proc targets (ie, occ, psi)
        do_plugin('fsp_proc_targets', $proc, $i, $proc_ordinal_id,
                    $STargets[$i][NODE_FIELD], $STargets[$i][POS_FIELD]);
    }
    elsif ($STargets[$i][NAME_FIELD] eq "ex")
    {
        my $proc = $STargets[$i][POS_FIELD];
        my $ex = $STargets[$i][UNIT_FIELD];

        if ($ex_count == 0)
        {
            print "\n<!-- $SYSNAME n${node}p$proc EX units -->\n";
        }
        generate_ex($proc, $ex, $STargets[$i][ORDINAL_FIELD], $ipath);
        $ex_count++;
        if ($STargets[$i+1][NAME_FIELD] eq "core")
        {
            $ex_count = 0;
        }
    }
    elsif ($STargets[$i][NAME_FIELD] eq "core")
    {
        my $proc = $STargets[$i][POS_FIELD];
        my $ex = $STargets[$i][UNIT_FIELD];

        if ($ex_core_count == 0)
        {
            print "\n<!-- $SYSNAME n${node}p$proc core units -->\n";
        }
        generate_ex_core($proc,$ex,$STargets[$i][ORDINAL_FIELD], $STargets[$i][PATH_FIELD]);
        $ex_core_count++;
        if ($STargets[$i+1][NAME_FIELD] eq "mcs")
        {
            $ex_core_count = 0;
        }
    }
    elsif ($STargets[$i][NAME_FIELD] eq "mcs")
    {
        my $proc = $STargets[$i][POS_FIELD];
        my $mcs = $STargets[$i][UNIT_FIELD];
        if ($mcs_count == 0)
        {
            print "\n<!-- $SYSNAME n${node}p$proc MCS units -->\n";
        }
        generate_mcs($proc,$mcs, $STargets[$i][ORDINAL_FIELD], $ipath);
        $mcs_count++;
        if (($STargets[$i+1][NAME_FIELD] eq "pu") ||
            ($STargets[$i+1][NAME_FIELD] eq "memb"))
        {
            $mcs_count = 0;
            generate_pcies($proc,$proc_ordinal_id);
            generate_ax_buses($proc, "A",$proc_ordinal_id);
            generate_ax_buses($proc, "X",$proc_ordinal_id);
            generate_nx($proc,$proc_ordinal_id,$node);
            generate_pore($proc,$proc_ordinal_id,$node);
        }
    }
}

# Fifth, generate the Centaur, L4, and MBA

my $memb;
my $membMcs;
my $mba_count = 0;
my $vmem_id =0;

for my $i ( 0 .. $#STargets )
{
    if ($STargets[$i][NODE_FIELD] != $node)
    {
        next;
    }

    my $ipath = $STargets[$i][PATH_FIELD];
    if ($STargets[$i][NAME_FIELD] eq "memb")
    {
        $memb = $STargets[$i][POS_FIELD];
        my $centaur = "n${node}:p${memb}";
        my $found = 0;
        my $cfsi;
        for my $j ( 0 .. $#Membuses )
        {
            my $mba = $Membuses[$j][CENTAUR_TARGET_FIELD];
            $mba =~ s/(.*):mba.*$/$1/;
            if ($mba eq $centaur)
            {
                $membMcs = $Membuses[$j][MCS_TARGET_FIELD];
                $cfsi = $Membuses[$j][CFSI_LINK_FIELD];
                $found = 1;
                last;
            }
        }
        if ($found == 0)
        {
            die "ERROR. Can't locate Centaur from memory bus table\n";
        }

        my $relativeCentaurRid = $STargets[$i][PLUG_POS]
            + (CDIMM_RID_NODE_MULTIPLIER * $STargets[$i][NODE_FIELD]);

        #should note that the $SortedVmem is sorted by node and position and
        #currently $STargets is also sorted by node and postion. If this ever
        #changes then will need to make a modification here
        my $vmemDevPath=$SortedVmem[$vmem_count][VMEM_DEV_PATH_FIELD];
        my $vmemAddr=$SortedVmem[$vmem_count][VMEM_I2C_ADDR_FIELD];
        my $vmem_id=$SortedVmem[$vmem_count][VMEM_ID_FIELD];
        $vmem_count++;

        generate_centaur( $memb, $membMcs, $cfsi, $ipath,
                               $STargets[$i][ORDINAL_FIELD],$relativeCentaurRid,
                               $vmem_id, $vmemDevPath, $vmemAddr, $ipath);
    }
    elsif ($STargets[$i][NAME_FIELD] eq "mba")
    {
        if ($mba_count == 0)
        {
            print "\n";
            print "<!-- $SYSNAME Centaur MBAs affiliated with membuf$memb -->";
            print "\n";
        }
        my $mba = $STargets[$i][UNIT_FIELD];
        generate_mba( $memb, $membMcs, $mba,
            $STargets[$i][ORDINAL_FIELD], $ipath);
        $mba_count += 1;
        if ($mba_count == 2)
        {
            $mba_count = 0;
            print "\n<!-- $SYSNAME Centaur n${node}p${memb} : end -->\n"
        }
    }
    elsif ($STargets[$i][NAME_FIELD] eq "L4")
    {
        print "\n";
        print "<!-- $SYSNAME Centaur L4 affiliated with membuf$memb -->";
        print "\n";

        my $l4 = $STargets[$i][UNIT_FIELD];
        generate_l4( $memb, $membMcs, $l4, $STargets[$i][ORDINAL_FIELD],
                     $ipath );

        print "\n<!-- $SYSNAME Centaur n${node}p${l4} : end -->\n"
    }
}

# Sixth, generate DIMM targets

print "\n<!-- $SYSNAME Centaur DIMMs -->\n";

for my $i ( 0 .. $#SMembuses )
{
    if ($SMembuses[$i][BUS_NODE_FIELD] != $node)
    {
        next;
    }

    my $ipath = $SMembuses[$i][DIMM_PATH_FIELD];
    my $proc = $SMembuses[$i][MCS_TARGET_FIELD];
    my $mcs = $proc;
    $proc =~ s/.*:p(.*):.*/$1/;
    $mcs =~ s/.*mcs(.*)/$1/;
    my $ctaur = $SMembuses[$i][CENTAUR_TARGET_FIELD];
    my $mba = $ctaur;
    $ctaur =~ s/.*:p(.*):mba.*$/$1/;
    $mba =~ s/.*:mba(.*)$/$1/;
    my $pos = $SMembuses[$i][DIMM_TARGET_FIELD];
    $pos =~ s/.*:p(.*)/$1/;
    my $dimm = $SMembuses[$i][DIMM_PATH_FIELD];
    $dimm =~ s/.*dimm-(.*)/$1/;
    my $relativeDimmRid = $dimm;
    my $dimmPos = $SMembuses[$i][DIMM_POS_FIELD];
    $dimmPos =~ s/.*dimm-(.*)/$1/;
    my $relativePos = $dimmPos;
    print "\n<!-- C-DIMM n${node}:p${pos} -->\n";
    for my $id ( 0 .. 7 )
    {
        my $dimmid = $dimm;
        $dimmid <<= 3;
        $dimmid |= $id;
        $dimmid = sprintf ("%d", $dimmid);
        generate_dimm( $proc, $mcs, $ctaur, $pos, $dimmid, $id,
                             ($SMembuses[$i][BUS_ORDINAL_FIELD]*8)+$id,
                              $relativeDimmRid, $relativePos, $ipath);
    }
}

# call to do pnor attributes
do_plugin('all_pnors', $node);

# call to do refclk attributes
do_plugin('all_refclk');
}

print "\n</attributes>\n";

# All done!
#close ($outFH);
exit 0;

##########   Subroutines    ##############

################################################################################
# utility function used to preCalculate the AX Buses HUIDs
################################################################################

sub preCalculateAxBusesHUIDs
{
    my ($my_node, $proc, $type) = @_;

    my ($minbus, $maxbus, $numperchip, $typenum, $type) =
            getBusInfo($type, $CHIPNAME);

    for my $i ( $minbus .. $maxbus )
    {
        my $uidstr = sprintf( "0x%02X%02X%04X",
            ${my_node},
            $typenum,
            $i+$proc*($numperchip)+${my_node}*8*($numperchip));
        my $phys_path =
            "physical:sys-$sys/node-$my_node/proc-$proc/${type}bus-$i";
        $hash_ax_buses->{$phys_path} = $uidstr;
        #print STDOUT "Phys Path = $phys_path, HUID = $uidstr\n";
    }
}

################################################################################
# utility function used to call plugins. if none exists, call is skipped.
################################################################################

sub do_plugin
{
    my $step = shift;
    if (exists($hwsvmrw_plugins{$step}))
    {
        $hwsvmrw_plugins{$step}(@_);
    }
    elsif ($DEBUG && ($build eq "fsp"))
    {
        print STDERR "build is $build but no plugin for $step\n";
    }
}

################################################################################
# Compares two MRW Targets based on the Type,Node,Position & Chip-Unit #
################################################################################

sub byTargetTypeNodePosChipunit ($$)
{
    # Operates on two Targets, based on the following parameters Targets will
    # get sorted,
    # 1.Type of the Target.Ex; pu , ex , mcs ,mba etc.
    # 2.Node of the Target.Node instance number, integer 0,1,2 etc.
    # 3.Position of the Target, integer 0,1,2 etc.
    # 4.ChipUnit of the Target , integer 0,1,2 etc.
    # Note the above order is sequential & comparison is made in the same order.

    #Assume always $lhsInstance < $rhsInstance, will reduce redundant coding.
    my $retVal = -1;

    # Get just the instance path for each supplied memory bus
    my $lhsInstance_Type = $_[0][NAME_FIELD];
    my $rhsInstance_Type = $_[1][NAME_FIELD];

    if($lhsInstance_Type eq $rhsInstance_Type)
    {
       my $lhsInstance_Node = $_[0][NODE_FIELD];
       my $rhsInstance_Node = $_[1][NODE_FIELD];

       if(int($lhsInstance_Node) eq int($rhsInstance_Node))
       {
           my $lhsInstance_Pos = $_[0][POS_FIELD];
           my $rhsInstance_Pos = $_[1][POS_FIELD];

           if(int($lhsInstance_Pos) eq int($rhsInstance_Pos))
           {
               my $lhsInstance_ChipUnit = $_[0][UNIT_FIELD];
               my $rhsInstance_ChipUnit = $_[1][UNIT_FIELD];

               if(int($lhsInstance_ChipUnit) eq int($rhsInstance_ChipUnit))
               {
                   die "ERROR: Duplicate Targets: 2 Targets with same \
                    TYPE: $lhsInstance_Type NODE: $lhsInstance_Node \
                    POSITION: $lhsInstance_Pos \
                    & CHIP-UNIT: $lhsInstance_ChipUnit\n";
               }
               elsif(int($lhsInstance_ChipUnit) > int($rhsInstance_ChipUnit))
               {
                   $retVal = 1;
               }
           }
           elsif(int($lhsInstance_Pos) > int($rhsInstance_Pos))
           {
               $retVal = 1;
           }
         }
         elsif(int($lhsInstance_Node) > int($rhsInstance_Node))
         {
            $retVal = 1;
         }
    }
    elsif($lhsInstance_Type gt $rhsInstance_Type)
    {
        $retVal = 1;
    }
    return $retVal;
}

################################################################################
# Compares two MRW DIMMs based on the Node,Position & DIMM instance #
################################################################################

sub byDimmNodePos($$)
{
    # Operates on two Targets, based on the following parameters Targets will
    # get sorted,
    # 1.Node of the Target.Node instance number, integer 0,1,2 etc.
    # 2.Position of the Target, integer 0,1,2 etc.
    # 3.On two DIMM instance paths, each in the form of:
    #     assembly-0/shilin-0/dimm-X
    #
    # Assumes that "X is always a decimal number, and that every DIMM in the
    # system has a unique value of "X", including for multi-node systems and for
    # systems whose DIMMs are contained on different parts of the system
    # topology
    #
    # Note, in the path example above, the parts leading up to the dimm-X could
    # be arbitrarily deep and have different types/instance values
    #
    # Note the above order is sequential & comparison is made in the same order.

    #Assume always $lhsInstance < $rhsInstance, will reduce redundant coding.
    my $retVal = -1;

    my $lhsInstance_node = $_[0][BUS_NODE_FIELD];
    my $rhsInstance_node = $_[1][BUS_NODE_FIELD];
    if(int($lhsInstance_node) eq int($rhsInstance_node))
    {
         my $lhsInstance_pos = $_[0][BUS_POS_FIELD];
         my $rhsInstance_pos = $_[1][BUS_POS_FIELD];
         if(int($lhsInstance_pos) eq int($rhsInstance_pos))
         {
            # Get just the instance path for each supplied memory bus
            my $lhsInstance = $_[0][DIMM_PATH_FIELD];
            my $rhsInstance = $_[1][DIMM_PATH_FIELD];
            # Replace each with just its DIMM instance value (a string)
            $lhsInstance =~ s/.*-([0-9]*)$/$1/;
            $rhsInstance =~ s/.*-([0-9]*)$/$1/;

            if(int($lhsInstance) eq int($rhsInstance))
            {
                die "ERROR: Duplicate Dimms: 2 Dimms with same TYPE, \
                    NODE: $lhsInstance_node POSITION: $lhsInstance_pos & \
                    PATH FIELD: $lhsInstance\n";
            }
            elsif(int($lhsInstance) > int($rhsInstance))
            {
               $retVal = 1;
            }
         }
         elsif(int($lhsInstance_pos) > int($rhsInstance_pos))
         {
             $retVal = 1;
         }
    }
    elsif(int($lhsInstance_node) > int($rhsInstance_node))
    {
        $retVal = 1;
    }
    return $retVal;
}

################################################################################
# Compares two MRW DIMM instance paths based only on the DIMM instance #
################################################################################

sub byDimmInstancePath ($$)
{
    # Operates on two DIMM instance paths, each in the form of:
    #     assembly-0/shilin-0/dimm-X
    #
    # Assumes that "X is always a decimal number, and that every DIMM in the
    # system has a unique value of "X", including for multi-node systems and for
    # systems whose DIMMs are contained on different parts of the system
    # topology
    #
    # Note, in the path example above, the parts leading up to the dimm-X could
    # be arbitrarily deep and have different types/instance values

    # Get just the instance path for each supplied memory bus
    my $lhsInstance = $_[0][DIMM_PATH_FIELD];
    my $rhsInstance = $_[1][DIMM_PATH_FIELD];

    # Replace each with just its DIMM instance value (a string)
    $lhsInstance =~ s/.*-([0-9]*)$/$1/;
    $rhsInstance =~ s/.*-([0-9]*)$/$1/;

    # Convert each DIMM instance value string to int, and return comparison
    return int($lhsInstance) <=> int($rhsInstance);
}

################################################################################
# Compares two arrays based on chip node and position
################################################################################
sub byNodePos($$)
{
    my $retVal = -1;

    my $lhsInstance_node = $_[0][CHIP_NODE_INDEX];
    my $rhsInstance_node = $_[1][CHIP_NODE_INDEX];
    if(int($lhsInstance_node) eq int($rhsInstance_node))
    {
         my $lhsInstance_pos = $_[0][CHIP_POS_INDEX];
         my $rhsInstance_pos = $_[1][CHIP_POS_INDEX];
         if(int($lhsInstance_pos) eq int($rhsInstance_pos))
         {
                die "ERROR: Duplicate chip positions: 2 chip with same
                    node and position, \
                    NODE: $lhsInstance_node POSITION: $lhsInstance_pos\n";
         }
         elsif(int($lhsInstance_pos) > int($rhsInstance_pos))
         {
             $retVal = 1;
         }
    }
    elsif(int($lhsInstance_node) > int($rhsInstance_node))
    {
        $retVal = 1;
    }
    return $retVal;
}

################################################################################
# Compares two Vmem instances based on the node and position #
################################################################################
sub byVmemNodePos($$)
{
    my $retVal = -1;

    my $lhsInstance_node = $_[0][VMEM_NODE_FIELD];
    my $rhsInstance_node = $_[1][VMEM_NODE_FIELD];
    if(int($lhsInstance_node) eq int($rhsInstance_node))
    {
         my $lhsInstance_pos = $_[0][VMEM_POS_FIELD];
         my $rhsInstance_pos = $_[1][VMEM_POS_FIELD];
         if(int($lhsInstance_pos) eq int($rhsInstance_pos))
         {
                die "ERROR: Duplicate vmem positions: 2 vmem with same
                    node and position, \
                    NODE: $lhsInstance_node POSITION: $lhsInstance_pos\n";
         }
         elsif(int($lhsInstance_pos) > int($rhsInstance_pos))
         {
             $retVal = 1;
         }
    }
    elsif(int($lhsInstance_node) > int($rhsInstance_node))
    {
        $retVal = 1;
    }
    return $retVal;
}

sub generate_sys
{
    my $plat = 0;
    if ($build eq "fsp")
    {
        $plat = 2;
    }
    elsif ($build eq "hb")
    {
        $plat = 1;
    }

    print "
<!-- $SYSNAME System with new values-->

<targetInstance>
    <id>sys$sys</id>
    <type>sys-sys-power8</type>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:sys-$sys</default>
    </compileAttribute>
    <attribute>
        <id>EXECUTION_PLATFORM</id>
        <default>$plat</default>
    </attribute>\n";

    print "    <!-- System Attributes from MRW -->\n";
    addSysAttrs();
    print "    <!-- End System Attributes from MRW -->\n";

    print "
    <attribute>
        <id>SP_FUNCTIONS</id>
        <default>
            <field><id>baseServices</id><value>1</value></field>
            <field><id>fsiSlaveInit</id><value>1</value></field>
            <field><id>mailboxEnabled</id><value>1</value></field>
            <field><id>fsiMasterInit</id><value>1</value></field>
            <field><id>hardwareChangeDetection</id><value>1</value></field>
            <field><id>powerLineDisturbance</id><value>1</value></field>
            <field><id>reserved</id><value>0</value></field>
        </default>
    </attribute>
        <attribute>
        <id>HB_SETTINGS</id>
        <default>
            <field><id>traceContinuous</id><value>0</value></field>
            <field><id>traceScanDebug</id><value>0</value></field>
            <field><id>reserved</id><value>0</value></field>
        </default>
    </attribute>
    <attribute>
        <id>PAYLOAD_KIND</id>
        <default>PHYP</default>
    </attribute>
    <!-- TODO. These must be from MRW. Hardcoded for now -->
    <attribute>
        <id>PAYLOAD_BASE</id>
        <default>256</default>
    </attribute>
    <attribute>
        <id>PAYLOAD_ENTRY</id>
        <default>0x180</default>
    </attribute>
    <attribute>
        <id>MSS_MBA_ADDR_INTERLEAVE_BIT</id>
        <default>24</default>
    </attribute>
    <attribute>
        <id>MSS_MBA_CACHELINE_INTERLEAVE_MODE</id>
        <default>1</default>
    </attribute>
    <attribute>
        <id>MSS_PREFETCH_ENABLE</id>
        <default>1</default>
    </attribute>
    <attribute>
        <id>MSS_CLEANER_ENABLE</id>
        <default>1</default>
    </attribute>";
    generate_max_config();

    # HDAT drawer number (physical node) to
    # HostBoot Instance number (logical node) map
    # Index is the hdat drawer number, value is the HB instance number
    # Only the max drawer system needs to be represented.
    if ($sysname eq "brazos")
    {
        print "
    <!-- correlate HDAT drawer number to Hostboot Instance number -->
    <attribute><id>FABRIC_TO_PHYSICAL_NODE_MAP</id>
        <default>0,1,2,3,255,255,255,255</default>
    </attribute>
";
    }
    else # single drawer
    {
        print "
    <!-- correlate HDAT drawer number to Hostboot Instance number -->
    <attribute><id>FABRIC_TO_PHYSICAL_NODE_MAP</id>
        <default>0,255,255,255,255,255,255,255</default>
    </attribute>
";
    }

    # call to do any fsp per-sys attributes
    do_plugin('fsp_sys', $sys, $sysname, 0);

print "
</targetInstance>

";
}

sub generate_max_config
{
    my $maxMcs_Per_System = 0;
    my $maxChiplets_Per_Proc = 0;
    my $maxProcChip_Per_Node =0;
    my $maxEx_Per_Proc =0;
    my $maxDimm_Per_MbaPort =0;
    my $maxMbaPort_Per_Mba =0;
    my $maxMba_Per_MemBuf =0;

    # MBA Ports Per MBA is 2 in P8 and is hard coded here
    use constant MBA_PORTS_PER_MBA => 2;

    # MAX Chiplets Per Proc is 32 and is hard coded here
    use constant CHIPLETS_PER_PROC => 32;

    # MAX Mba Per MemBuf is 2 and is hard coded here
    # PNEW_TODO to change if P9 different
    use constant MAX_MBA_PER_MEMBUF => 2;

    # MAX Dimms Per MBA PORT is 2 and is hard coded here
    # PNEW_TODO to change if P9 different
    use constant MAX_DIMMS_PER_MBAPORT => 2;

    for (my $i = 0; $i < $#STargets; $i++)
    {
        if ($STargets[$i][NAME_FIELD] eq "pu")
        {
            if ($node == 0)
            {
                $maxProcChip_Per_Node += 1;
            }
        }
        elsif ($STargets[$i][NAME_FIELD] eq "ex")
        {
            my $proc = $STargets[$i][POS_FIELD];
            if (($proc == 0) && ($node == 0))
            {
                $maxEx_Per_Proc += 1;
            }
        }
        elsif ($STargets[$i][NAME_FIELD] eq "mcs")
        {
            $maxMcs_Per_System += 1;
        }
    }

    # loading the hard coded value
    $maxMbaPort_Per_Mba = MBA_PORTS_PER_MBA;

    # loading the hard coded value
    $maxChiplets_Per_Proc = CHIPLETS_PER_PROC;

    # loading the hard coded value
    $maxMba_Per_MemBuf = MAX_MBA_PER_MEMBUF;

    # loading the hard coded value
    $maxDimm_Per_MbaPort = MAX_DIMMS_PER_MBAPORT;

    print "
    <attribute>
        <id>MAX_PROC_CHIPS_PER_NODE</id>
        <default>$maxProcChip_Per_Node</default>
    </attribute>
    <attribute>
        <id>MAX_EXS_PER_PROC_CHIP</id>
        <default>$maxEx_Per_Proc</default>
    </attribute>
    <attribute>
        <id>MAX_MBAS_PER_MEMBUF_CHIP</id>
        <default>$maxMba_Per_MemBuf</default>
    </attribute>
    <attribute>
        <id>MAX_MBA_PORTS_PER_MBA</id>
        <default>$maxMbaPort_Per_Mba</default>
    </attribute>
    <attribute>
        <id>MAX_DIMMS_PER_MBA_PORT</id>
        <default>$maxDimm_Per_MbaPort</default>
    </attribute>
    <attribute>
        <id>MAX_CHIPLETS_PER_PROC</id>
        <default>$maxChiplets_Per_Proc</default>
    </attribute>
    <attribute>
        <id>MAX_MCS_PER_SYSTEM</id>
        <default>$maxMcs_Per_System</default>
    </attribute>";
}

my $computeNodeInit = 0;
my %computeNodeList = ();
sub generate_compute_node_ipath
{
    open (FH, "<$::mrwdir/${sysname}-location-codes.xml") ||
        die "ERROR: unable to open $::mrwdir/${sysname}-location-codes.xml\n";
    close (FH);

    my $nodeTargets = XMLin("$::mrwdir/${sysname}-location-codes.xml");

    #get the node (compute) ipath details
    foreach my $Target (@{$nodeTargets->{'location-code-entry'}})
    {
        if($Target->{'assembly-type'} eq "compute")
        {
            my $ipath = $Target->{'instance-path'};
            my $assembly = $Target->{'assembly-type'};
            my $position = $Target->{position};

            $computeNodeList{$position} = {
                'position'     => $position,
                'assembly'     => $assembly,
                'instancePath' => $ipath,
            }
        }
    }
}

sub generate_system_node
{
    # Get the node ipath info
    if ($computeNodeInit == 0)
    {
        generate_compute_node_ipath;
        $computeNodeInit = 1;
    }

    # Brazos node4 is the fsp node and we'll let the fsp
    # MRW parser handle that.
    if( !( ($sysname eq "brazos") && ($node == $MAXNODE) ) )
    {
        print "
<!-- $SYSNAME System node $node -->

<targetInstance>
    <id>sys${sys}node${node}</id>
    <type>enc-node-power8</type>
    <attribute><id>HUID</id><default>0x0${node}020000</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$computeNodeList{$node}->{'instancePath'}</default>
    </compileAttribute>";
        # add fsp extensions
        do_plugin('fsp_node_add_extensions', $node);
        print "
</targetInstance>
";
    }
    else
    {
        # create fsp control node
        do_plugin('fsp_control_node', $node);
    }

    # call to do any fsp per-system_node targets
    do_plugin('fsp_system_node_targets', $node);
}

sub generate_proc
{
    my ($proc, $ipath, $lognode, $logid, $ordinalId, $master, $slave, $fsi,
        $fruid,$hwTopology) = @_;
    my $uidstr = sprintf("0x%02X05%04X",${node},${proc});
    my $vpdnum = ${proc};
    my $position = ${proc};
    my $scompath = $devpath->{chip}->{$ipath}->{'scom-path'};
    my $scanpath = $devpath->{chip}->{$ipath}->{'scan-path'};
    my $scomsize = length($scompath) + 1;
    my $scansize = length($scanpath) + 1;
    my $mboxpath = "";
    my $mboxsize = 0;
    if (exists $devpath->{chip}->{$ipath}->{'mailbox-path'})
    {
        $mboxpath = $devpath->{chip}->{$ipath}->{'mailbox-path'};
        $mboxsize = length($mboxpath) + 1;
    }

    my $psichip = 0;
    my $psilink = 0;
    for my $psi ( 0 .. $#hbPSIs )
    {
        if(($node eq $hbPSIs[$psi][HB_PSI_PROC_NODE_FIELD]) &&
           ($proc eq $hbPSIs[$psi][HB_PSI_PROC_POS_FIELD] ))
        {
            $psichip = $hbPSIs[$psi][HB_PSI_MASTER_CHIP_POSITION_FIELD];
            $psilink = $hbPSIs[$psi][HB_PSI_MASTER_CHIP_UNIT_FIELD];
            last;
        }
    }

    #default to murano (s1_) values and change later if for venice (p8_)
    my $ex_func_l3      = 48826;

    if($CHIPNAME eq "venice")
    {
        $ex_func_l3      = 49020;
    }

    #MURANO=DCM installed, VENICE=SCM
    my $dcm_installed = 0;
    if($CHIPNAME eq "murano")
    {
        $dcm_installed = 1;
    }

    my $mruData = get_mruid($ipath);
    print "
    <!-- $SYSNAME n${node}p${proc} processor chip -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}</id>
    <type>chip-processor-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>${position}</default></attribute>
    <attribute><id>SCOM_SWITCHES</id>
        <default>
            <field><id>useFsiScom</id><value>$slave</value></field>
            <field><id>useXscom</id><value>$master</value></field>
            <field><id>useInbandScom</id><value>0</value></field>
            <field><id>reserved</id><value>0</value></field>
        </default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>FABRIC_NODE_ID</id>
        <default>$lognode</default>
    </attribute>
    <attribute>
        <id>FABRIC_CHIP_ID</id>
        <default>$logid</default>
    </attribute>
    <attribute>
        <id>FRU_ID</id>
        <default>$fruid</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$vpdnum</default></attribute>

    <!-- workaround for SW196865 - see  RTC:69918 for additional details -->
    <attribute>
    <id>PROC_EX_FUNC_L3_LENGTH</id>
        <default>$ex_func_l3</default>
    </attribute>
    <attribute><id>PROC_DCM_INSTALLED</id>
        <default>$dcm_installed</default>
    </attribute>";

    if ($master)
    {
        print "
    <!-- Master Proc attribute -->
    <attribute>
        <id>PROC_MASTER_TYPE</id>
        <default>ACTING_MASTER</default>
    </attribute>";

    }
    if ($slave)
    {
        print "
    <!-- Slave Proc attribute -->
    <!-- FSI is connected via node${node}:proc${Mproc}:MFSI-$fsi -->
    <attribute>
        <id>FSI_MASTER_CHIP</id>
        <default>physical:sys-$sys/node-$node/proc-$Mproc</default>
    </attribute>
    <attribute>
        <id>FSI_MASTER_TYPE</id>
        <default>MFSI</default>
    </attribute>
    <attribute>
        <id>FSI_MASTER_PORT</id>
        <default>$fsi</default>
    </attribute>
    <attribute>
        <id>FSI_SLAVE_CASCADE</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>FSI_OPTION_FLAGS</id>
        <default>0</default>
    </attribute>";
    }

    #TODO RTC [59707]
    #Update Lane equalization values

    # add EEPROM attributes
    addEeproms($sys, $node, $proc);


    # fsp-specific proc attributes
    do_plugin('fsp_proc', $scompath, $scomsize, $scanpath, $scansize,
            $node, $proc, $fruid, $ipath, $hwTopology, $mboxpath, $mboxsize,
            $ordinalId );

    # Data from PHYP Memory Map
    print "\n";
    print "    <!-- Data from PHYP Memory Map -->\n";

    # Calculate the FSP and PSI BRIGDE BASE ADDR
    my $fspBase = 0;
    my $psiBase = 0;
    foreach my $i (@{$psiBus->{'psi-bus'}})
    {
        if (($i->{'processor'}->{target}->{position} eq $proc) &&
            ($i->{'processor'}->{target}->{node} eq $node ))
        {
            $fspBase = 0x0003FFE000000000 + 0x400000000*$lognode + 0x100000000*$logid;
            $psiBase = 0x0003FFFE80000000 + 0x400000*$psichip + 0x100000*$psilink;
            last;
        }
    }

    # Starts at 1024TB - 128GB, 4GB per proc
    printf( "    <attribute><id>FSP_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n", $fspBase );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 6GB, 1MB per link/proc
    printf( "    <attribute><id>PSI_BRIDGE_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n", $psiBase );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 2GB, 1MB per proc
    printf( "    <attribute><id>INTP_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n",
       0x0003FFFF80000000 + 0x400000*$lognode + 0x100000*$logid );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 7GB, 1MB per PHB (=4MB per proc)
    printf( "    <attribute><id>PHB_BASE_ADDRS</id>\n" );
    printf( "        <default>\n" );
    printf( "            0x%016X,0x%016X,\n",
       0x0003FFFE40000000 + 0x1000000*$lognode + 0x400000*$logid + 0x100000*0,
         0x0003FFFE40000000 + 0x1000000*$lognode + 0x400000*$logid + 0x100000*1 );
    printf( "            0x%016X,0x%016X\n",
       0x0003FFFE40000000 + 0x1000000*$lognode + 0x400000*$logid + 0x100000*2,
         0x0003FFFE40000000 + 0x1000000*$lognode + 0x400000*$logid + 0x100000*3 );
    printf( "        </default>\n" );
    printf( "    </attribute>\n" );

    # Starts at 976TB, 64GB per PHB (=256GB per proc)
    printf( "    <attribute><id>PCI_BASE_ADDRS</id>\n" );
    printf( "        <default>\n" );
    printf( "            0x%016X,0x%016X,\n",
       0x0003D00000000000 + 0x10000000000*$lognode + 0x4000000000*$logid + 0x1000000000*0,
         0x0003D00000000000 + 0x10000000000*$lognode + 0x4000000000*$logid + 0x1000000000*1 );
    printf( "            0x%016X,0x%016X\n",
       0x0003D00000000000 + 0x10000000000*$lognode + 0x4000000000*$logid + 0x1000000000*2,
         0x0003D00000000000 + 0x10000000000*$lognode + 0x4000000000*$logid + 0x1000000000*3 );
    printf( "        </default>\n" );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 3GB
    printf( "    <attribute><id>RNG_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n",
       0x0003FFFF40000000 + 0x4000*$lognode + 0x1000*$logid );
    printf( "    </attribute>\n" );

    # Starts at 992TB - 128GB per MCS/Centaur
    printf( "    <attribute><id>IBSCOM_PROC_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n",
       0x0003E00000000000 + 0x40000000000*$lognode + 0x10000000000*$logid );
    printf( "    </attribute>\n" );

    print "    <!-- End PHYP Memory Map -->\n\n";
    # end PHYP Memory Map

    print "    <!-- PROC_PCIE_ attributes -->\n";
    addProcPcieAttrs( $proc, $node );
    print "    <!-- End PROC_PCIE_ attributes -->\n";

    print "
    <!-- The default value of the following three attributes are written by -->
    <!-- the FSP. They are included here because VBU/VPO uses faked PNOR.   -->
    <attribute>
        <id>PROC_PCIE_IOP_CONFIG</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IOP_SWAP</id>
        <default>$pcie_list{$ipath}{0}{0}{'lane-swap'},
                 $pcie_list{$ipath}{1}{0}{'lane-swap'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_PHB_ACTIVE</id>
        <default>0</default>
    </attribute>\n";

    if ((scalar @SortedPmChipAttr) == 0)
    {
        # Default the values.
        print "    <!-- PM_ attributes (default values) -->\n";
        print "    <attribute>\n";
        print "        <id>PM_UNDERVOLTING_FRQ_MINIMUM</id>\n";
        print "        <default>0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_UNDERVOLTING_FREQ_MAXIMUM</id>\n";
        print "        <default>0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_SPIVID_PORT_ENABLE</id>\n";
        if( $proc % 2 == 0 ) # proc0 of DCM
        {
            print "        <default>0x4</default><!-- PORT0NONRED -->\n";
        }
        else # proc1 of DCM
        {
            print "        <default>0x0</default><!-- NONE -->\n";
        }
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_APSS_CHIP_SELECT</id>\n";
        if( $proc % 2 == 0 ) # proc0 of DCM
        {
            print "        <default>0x00</default><!-- CS0 -->\n";
        }
        else # proc1 of DCM
        {
            print "        <default>0xFF</default><!-- NONE -->\n";
        }
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_PBAX_NODEID</id>\n";
        print "        <default>0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_PBAX_CHIPID</id>\n";
        print "        <default>$logid</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_PBAX_BRDCST_ID_VECTOR</id>\n";
        print "        <default>$lognode</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_SLEEP_ENTRY</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_SLEEP_EXIT</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_SLEEP_TYPE</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_WINKLE_ENTRY</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_WINKLE_EXIT</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <attribute>\n";
        print "        <id>PM_WINKLE_TYPE</id>\n";
        print "        <default>0x0</default>\n";
        print "    </attribute>\n";
        print "    <!-- End PM_ attributes (default values) -->\n";
    }
    else
    {
        print "    <!-- PM_ attributes -->\n";
        addProcPmAttrs( $proc, $node );
        print "    <!-- End PM_ attributes -->\n";
    }

    print "    </targetInstance>\n";

}

sub generate_ex
{
    my ($proc, $ex, $ordinalId, $ipath) = @_;
    my $uidstr = sprintf("0x%02X06%04X",${node},$ex+$proc*16);
    my $mruData = get_mruid($ipath);
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}ex$ex</id>
    <type>unit-ex-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/ex-$ex</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/ex-$ex</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$ex</default>
    </attribute>";

    # call to do any fsp per-ex attributes
    do_plugin('fsp_ex', $proc, $ex, $ordinalId );

    print "
</targetInstance>
";
}

sub generate_ex_core
{
    my ($proc, $ex, $ordinalId, $ipath) = @_;
    my $uidstr = sprintf("0x%02X07%04X",${node},$ex+$proc*16);
    my $mruData = get_mruid($ipath);
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}ex${ex}core0</id>
    <type>unit-core-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/ex-$ex/core-0</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/ex-$ex/core-0</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$ex</default>
    </attribute>";

    # call to do any fsp per-ex_core attributes
    do_plugin('fsp_ex_core', $proc, $ex, $ordinalId );

    print "
</targetInstance>
";
}

sub generate_mcs
{
    my ($proc, $mcs, $ordinalId, $ipath) = @_;
    my $uidstr = sprintf("0x%02X0B%04X",${node},$mcs+$proc*8+${node}*8*8);
    my $mruData = get_mruid($ipath);

    my $lognode;
    my $logid;
    for (my $j = 0; $j <= $#chipIDs; $j++)
    {
        if ($chipIDs[$j][CHIP_ID_NXPX] eq "n${node}:p${proc}")
        {
            $lognode = $chipIDs[$j][CHIP_ID_NODE];
            $logid = $chipIDs[$j][CHIP_ID_POS];
            last;
        }
    }

    #IBSCOM address range starts at 0x0003E00000000000 (992 TB)
    #128GB per MCS/Centaur
    #Addresses assigned by logical node, not physical node
    my $mscStr = sprintf("0x%016X", 0x0003E00000000000 +
                   0x40000000000*$lognode +
                   0x10000000000*$logid + 0x2000000000*$mcs);

    my $lane_swap = 0;
    my $msb_swap = 0;
    my $swizzle = 0;
    foreach my $dmi ( @dbus_mcs )
    {
        if (($dmi->[DBUS_MCS_NODE_INDEX] eq ${node} ) &&
            ( $dmi->[DBUS_MCS_PROC_INDEX] eq $proc  ) &&
            ($dmi->[DBUS_MCS_UNIT_INDEX] eq  $mcs   ))
        {
            $lane_swap = $dmi->[DBUS_MCS_DOWNSTREAM_INDEX];
            $msb_swap = $dmi->[DBUS_MCS_TX_SWAP_INDEX];
            $swizzle = $dmi->[DBUS_MCS_SWIZZLE_INDEX];
            last;
        }
    }

    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}mcs$mcs</id>
    <type>unit-mcs-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/mcs-$mcs</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$mcs</default>
    </attribute>
    <attribute><id>IBSCOM_MCS_BASE_ADDR</id>
        <!-- baseAddr = 0x0003E00000000000, 128GB per MCS -->
        <default>$mscStr</default>
    </attribute>
    <attribute><id>DMI_REFCLOCK_SWIZZLE</id>
        <default>$swizzle</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_MSBSWAP</id>
        <default>$msb_swap</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_LANE_INVERT</id>
        <default>$lane_swap</default>
    </attribute>";

    # call to do any fsp per-mcs attributes
    do_plugin('fsp_mcs', $proc, $mcs, $ordinalId );

    print "
</targetInstance>
";
}

sub generate_pcies
{
    my ($proc,$ordinalId) = @_;
    my $proc_name = "n${node}:p${proc}";
    print "\n<!-- $SYSNAME n${node}p${proc} PCI units -->\n";
    for my $i ( 0 .. 2 )
    {
        generate_a_pcie( $proc, $i, ($ordinalId*3)+$i );
    }
}

my $phbInit = 0;
my %phbList = ();
sub generate_phb
{
    open (FH, "<$::mrwdir/${sysname}-targets.xml") ||
        die "ERROR: unable to open $::mrwdir/${sysname}-targets.xml\n";
    close (FH);

    my $phbTargets = XMLin("$::mrwdir/${sysname}-targets.xml");

    #get the PHB details
    foreach my $Target (@{$phbTargets->{target}})
    {
        if($Target->{'ecmd-common-name'} eq "phb")
        {
            my $node     = $Target->{'node'};
            my $proc     = $Target->{'position'};
            my $chipUnit = $Target->{'chip-unit'};
            my $ipath    = $Target->{'instance-path'};


            $phbList{$node}{$proc}{$chipUnit} = {
                'node'        => $node,
                'proc'        => $proc,
                'phbChipUnit' => $chipUnit,
                'phbIpath'    => $ipath,
            }
        }
    }
}

sub generate_a_pcie
{
    my ($proc, $phb, $ordinalId) = @_;
    my $uidstr = sprintf("0x%02X10%04X",${node},$phb+$proc*3+${node}*8*3);

    # Get the PHB info
    if ($phbInit == 0)
    {
        generate_phb;
        $phbInit = 1;
    }

    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}pci${phb}</id>
    <type>unit-pci-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/pci-$phb</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/pci-$phb</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$phbList{$node}{$proc}{$phb}->{'phbIpath'}</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$phb</default>
    </attribute>";

    # call to do any fsp per-pcie attributes
    do_plugin('fsp_pcie', $proc, $phb, $ordinalId );

    print "
</targetInstance>
";
}

sub getBusInfo
{
    my($type, $chipName) = @_;

    my $minbus = ($type eq "A") ? 0 : ($chipName eq "murano") ? 1 : 0;
    my $maxbus = ($type eq "A") ? 2 : ($chipName eq "murano") ? 1 : 3;
    my $numperchip = ($type eq "A") ? 3 : 4;
    my $typenum = ($type eq "A") ? 0x0F : 0x0E;
    $type = lc( $type );

    return ($minbus, $maxbus, $numperchip, $typenum, $type);
}

sub generate_ax_buses
{
    my ($proc, $type, $ordinalId) = @_;

    my $proc_name = "n${node}p${proc}";
    print "\n<!-- $SYSNAME $proc_name ${type}BUS units -->\n";

    my ($minbus, $maxbus, $numperchip, $typenum, $type) =
            getBusInfo($type, $CHIPNAME);

    for my $i ( $minbus .. $maxbus )
    {
        my $c_ordinalId = $i+($ordinalId*($numperchip));

        my $peer = 0;
        my $p_node = 0;
        my $p_proc = 0;
        my $p_port = 0;
        my $lane_swap = 0;
        my $msb_swap = 0;
        my $ipath = "abus_or_xbus:TO_BE_ADDED";
        foreach my $pbus ( @pbus )
        {
            if ($pbus->[PBUS_FIRST_END_POINT_INDEX] eq
                "n${node}:p${proc}:${type}${i}" )
            {
                $ipath = $pbus->[PBUS_ENDPOINT_INSTANCE_PATH];
                if ($pbus->[PBUS_SECOND_END_POINT_INDEX] ne "invalid")
                {
                    $peer = 1;
                    $p_proc = $pbus->[PBUS_SECOND_END_POINT_INDEX];
                    $p_port = $p_proc;
                    $p_node = $pbus->[PBUS_SECOND_END_POINT_INDEX];
                    $p_node =~ s/^n(.*):p.*:.*$/$1/;
                    $p_proc =~ s/^.*:p(.*):.*$/$1/;
                    $p_port =~ s/.*:p.*:.(.*)$/$1/;

                    # Calculation from Pete Thomsen for 'master' chip
                    if(((${node}*100) + $proc) < (($p_node*100) + $p_proc))
                    {
                        # This chip is lower so it's master so it gets
                        # the downstream data.
                        $lane_swap = $pbus->[PBUS_DOWNSTREAM_INDEX];
                        $msb_swap = $pbus->[PBUS_TX_MSB_LSB_SWAP];
                    }
                    else
                    {
                        # This chip is higher so it's the slave chip
                        # and gets the upstream
                        $lane_swap = $pbus->[PBUS_UPSTREAM_INDEX];
                        $msb_swap = $pbus->[PBUS_RX_MSB_LSB_SWAP];
                    }
                    last;
                }
            }
        }
        my $mruData = get_mruid($ipath);
        my $phys_path =
            "physical:sys-${sys}/node-${node}/proc-${proc}/${type}bus-${i}";
        print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}${type}bus$i</id>
    <type>unit-${type}bus-$CHIPNAME</type>
    <attribute>
        <id>HUID</id>
        <default>$hash_ax_buses->{$phys_path}</default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>$phys_path</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/${type}bus-$i</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$i</default>
    </attribute>";
        if ($peer)
        {
            my $peerPhysPath = "physical:sys-${sys}/node-${p_node}/"
                ."proc-${p_proc}/${type}bus-${p_port}";
            print "
    <attribute>
        <id>PEER_TARGET</id>
        <default>$peerPhysPath</default>
    </attribute>
    <compileAttribute>
        <id>PEER_HUID</id>
        <default>$hash_ax_buses->{$peerPhysPath}</default>
    </compileAttribute>";
            if ($type eq "a")
            {
                print "
    <attribute>
        <id>PEER_PATH</id>
        <default>physical:sys-$sys/node-$p_node/proc-$p_proc/"
            . "${type}bus-$p_port</default>
    </attribute>";
            }
            if (($node != $p_node) && ($type eq "a"))
            {
               print "
    <attribute>
        <id>IS_INTER_ENCLOSURE_BUS</id>
        <default>1</default>
    </attribute>";
            }
        }
        else
        {
            if ($type eq "a")
            {
                print "
    <attribute>
        <id>PEER_PATH</id>
        <default>physical:na</default>
    </attribute>";
            }
        }

        # call to do any fsp per-axbus attributes
        do_plugin('fsp_axbus', $proc, $type, $i, $c_ordinalId );

        if($type eq "a")
        {
            print "
    <attribute>
        <id>EI_BUS_TX_LANE_INVERT</id>
        <default>$lane_swap</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_MSBSWAP</id>
        <default>$msb_swap</default>
    </attribute>";
        }

        print "\n</targetInstance>\n";
    }
}

my $poreNxInit = 0;
my %poreList = ();
my %nxList = ();
sub generate_pore_nx_ipath
{
    #get the PORE ipath detail using previously computed $eTargets
    foreach my $Target (@{$eTargets->{target}})
    {
        if($Target->{'ecmd-common-name'} eq "pore")
        {
            my $ipath = $Target->{'instance-path'};
            my $node = $Target->{node};
            my $position = $Target->{position};

            $poreList{$node}{$position} = {
                'node'         => $node,
                'position'     => $position,
                'instancePath' => $ipath,
            }
        }
        #get the nx ipath detail
        if($Target->{'ecmd-common-name'} eq "nx")
        {
            my $ipath = $Target->{'instance-path'};
            my $node = $Target->{node};
            my $position = $Target->{position};

            $nxList{$node}{$position} = {
                'node'         => $node,
                'position'     => $position,
                'instancePath' => $ipath,
            }
        }
    }
}

sub generate_nx
{
    my ($proc, $ordinalId, $node) = @_;
    my $uidstr = sprintf("0x%02X1E%04X",${node},$proc);

    # Get the nx and PORE info
    if ($poreNxInit == 0)
    {
        generate_pore_nx_ipath;
        $poreNxInit = 1;
    }

    my $ipath = $nxList{$node}{$proc}->{'instancePath'};
    my $mruData = get_mruid($ipath);

    print "\n<!-- $SYSNAME n${node}p$proc NX units -->\n";
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}nx0</id>
    <type>unit-nx-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/nx-0</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/nx-0</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>0</default>
    </attribute>";

    # call to do any fsp per-nx attributes
    do_plugin('fsp_nx', $proc, $ordinalId );

    print "
</targetInstance>
";
}

sub generate_pore
{
    my ($proc, $ordinalId, $node) = @_;
    my $uidstr = sprintf("0x%02X1F%04X",${node},$proc);

    # Get the nx and PORE info
    if ($poreNxInit == 0)
    {
        generate_pore_nx_ipath;
        $poreNxInit = 1;
    }

    my $ipath = $poreList{$node}{$proc}->{'instancePath'};
    my $mruData = get_mruid($ipath);

    print "\n<!-- $SYSNAME n${node}p$proc PORE units -->\n";
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}pore0</id>
    <type>unit-pore-$CHIPNAME</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/pore-0</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/pore-0</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>0</default>
    </attribute>";

    # call to do any fsp per-pore attributes
    do_plugin('fsp_pore', $proc, $ordinalId );

    print "
</targetInstance>
";
}

my $logicalDimmInit = 0;
my %logicalDimmList = ();
sub generate_logicalDimms
{
    open (FH, "<$::mrwdir/${sysname}-memory-busses.xml") ||
        die "ERROR: unable to open $::mrwdir/${sysname}-memory-busses.xml\n";
    close (FH);

    my $dramTargets = XMLin("$::mrwdir/${sysname}-memory-busses.xml");

    #get the DRAM details
    foreach my $Target (@{$dramTargets->{drams}->{dram}})
    {
        my $node = $Target->{'assembly-position'};
        my $ipath = $Target->{'dram-instance-path'};
        my $dimmIpath = $Target->{'dimm-instance-path'};
        my $mbaIpath = $Target->{'mba-instance-path'};
        my $mbaPort = $Target->{'mba-port'};
        my $mbaSlot = $Target->{'mba-slot'};

        my $dimm = substr($dimmIpath, index($dimmIpath, 'dimm-')+5);
        my $mba = substr($mbaIpath, index($mbaIpath, 'mba')+3);

        $logicalDimmList{$node}{$dimm}{$mba}{$mbaPort}{$mbaSlot} = {
                'node'             => $node,
                'dimmIpath'        => $dimmIpath,
                'mbaIpath'         => $mbaIpath,
                'dimm'             => $dimm,
                'mba'              => $mba,
                'mbaPort'          => $mbaPort,
                'mbaSlot'          => $mbaSlot,
                'logicalDimmIpath' => $ipath,
        }
    }
}

sub generate_centaur
{
    my ($ctaur, $mcs, $cfsi, $ipath, $ordinalId, $relativeCentaurRid,
            $vmemId, $vmemDevPath, $vmemAddr, $ipath) = @_;
    my $scompath = $devpath->{chip}->{$ipath}->{'scom-path'};
    my $scanpath = $devpath->{chip}->{$ipath}->{'scan-path'};
    my $scomsize = length($scompath) + 1;
    my $scansize = length($scanpath) + 1;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $mruData = get_mruid($ipath);
    my $uidstr = sprintf("0x%02X04%04X",${node},$mcs+$proc*8+${node}*8*8);

    my $lane_swap = 0;
    my $msb_swap = 0;
    foreach my $dmi ( @dbus_centaur )
    {
        if (($dmi->[DBUS_CENTAUR_NODE_INDEX] eq ${node} ) &&
            ($dmi->[DBUS_CENTAUR_MEMBUF_INDEX] eq $ctaur) )
        {
            $lane_swap = $dmi->[DBUS_CENTAUR_UPSTREAM_INDEX];
            $msb_swap = $dmi->[DBUS_CENTAUR_RX_SWAP_INDEX];
            last;
        }
    }

    # Get the logical DIMM info
    if ($logicalDimmInit == 0)
    {
        generate_logicalDimms;
        $logicalDimmInit = 1;
    }

    print "
<!-- $SYSNAME Centaur n${node}p${ctaur} : start -->

<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}</id>
    <type>chip-membuf-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>$ctaur</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>VMEM_ID</id>
        <default>$vmemId</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_MSBSWAP</id>
        <default>$msb_swap</default>
    </attribute>

    <!-- FSI is connected via proc$proc:cMFSI-$cfsi -->
    <attribute>
        <id>FSI_MASTER_CHIP</id>
        <default>physical:sys-$sys/node-$node/proc-$proc</default>
    </attribute>
    <attribute>
        <id>FSI_MASTER_TYPE</id>
        <default>CMFSI</default>
    </attribute>
    <attribute>
        <id>FSI_MASTER_PORT</id>
        <default>$cfsi</default>
    </attribute>
    <attribute>
        <id>FSI_SLAVE_CASCADE</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>FSI_OPTION_FLAGS</id>
        <default>0</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$ctaur</default></attribute>
    <attribute>
        <id>EI_BUS_TX_LANE_INVERT</id>
        <default>$lane_swap</default>
    </attribute>";

    # call to do any fsp per-centaur attributes
    do_plugin('fsp_centaur', $scompath, $scomsize, $scanpath, $scansize,
                $vmemDevPath, $vmemAddr, $relativeCentaurRid, $ordinalId);

    print "\n</targetInstance>\n";

}

sub generate_mba
{
    my ($ctaur, $mcs, $mba, $ordinalId, $ipath) = @_;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $uidstr = sprintf("0x%02X0D%04X",
                          ${node},$mba+$mcs*2+$proc*8*2+${node}*8*8*2);
    my $mruData = get_mruid($ipath);

    print "
<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}mba$mba</id>
    <type>unit-mba-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur/"
            . "mba-$mba</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur/mba-$mba</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$mba</default>
    </attribute>";

    # call to do any fsp per-mba attributes
    do_plugin('fsp_mba', $ctaur, $mba, $ordinalId );

    print "
</targetInstance>
";
}

sub generate_l4
{
    my ($ctaur, $mcs, $l4, $ordinalId, $ipath) = @_;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $uidstr = sprintf("0x%02X0C%04X",${node},$mcs+$proc*8+${node}*8*8);
    my $mruData = get_mruid($ipath);

    print "
<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}l4${l4}</id>
    <type>unit-l4-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur/"
            . "l4-$l4</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur/l4-$l4</default>
    </attribute>
    <attribute>
        <id>MRU_ID</id>
        <default>$mruData</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>instance:$ipath</default>
    </compileAttribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$l4</default>
    </attribute>";

    # call to do any fsp per-centaur_l4 attributes
    do_plugin('fsp_centaur_l4', $ctaur, $ordinalId );

    print "</targetInstance>";
}

# Since each Centaur has only one dimm, it is assumed to be attached to port 0
# of the MBA0 chiplet.
sub generate_dimm
{
    my ($proc, $mcs, $ctaur, $pos, $dimm, $id, $ordinalId, $relativeDimmRid, $relativePos)
        = @_;

    my $x = $id;
    $x = int ($x / 4);
    my $y = $id;
    $y = int(($y - 4 * $x) / 2);
    my $z = $id;
    $z = $z % 2;
    my $zz = $id;
    $zz = $zz % 4;
    #$x = sprintf ("%d", $x);
    #$y = sprintf ("%d", $y);
    #$z = sprintf ("%d", $z);
    #$zz = sprintf ("%d", $zz);
    my $uidstr = sprintf("0x%02X03%04X",${node},$dimm+${node}*512);

    # Calculate the VPD Record number value
    my $vpdRec = 0;

    # Set offsets based on mba and dimm values
    if( 1 == $x )
    {
        $vpdRec = $vpdRec + 4;
    }
    if( 1 == $y )
    {
        $vpdRec = $vpdRec + 2;
    }
    if( 1 == $z )
    {
        $vpdRec = $vpdRec + 1;
    }

    my $position = ($proc * 64) + 8 * $mcs + $vpdRec;

    # Adjust offset based on MCS value
    $vpdRec = ($mcs * 8) + $vpdRec;
    # Adjust offset basedon processor value
    $vpdRec = ($proc * 64) + $vpdRec;

    my $dimmHex = sprintf("0xD0%02X",$relativePos
        + (CDIMM_RID_NODE_MULTIPLIER * ${node}));

    #MBA numbers should be 01 and 23
    my $mbanum=0;
    if (1 ==$x )
    {
        $mbanum = '23';
    }
    else
    {
        $mbanum = '01';
    }

    my $logicalDimmInstancePath = "instance:"
        . $logicalDimmList{$node}{$relativePos}{$mbanum}{$y}{$z}->{'logicalDimmIpath'};

    print "
<targetInstance>
    <id>sys${sys}node${node}dimm$dimm</id>
    <type>lcard-dimm-cdimm</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>$position</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/dimm-$dimm</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$pos/mba-$x/dimm-$zz</default>
    </attribute>
    <compileAttribute>
        <id>INSTANCE_PATH</id>
        <default>$logicalDimmInstancePath</default>
    </compileAttribute>
    <attribute>
        <id>MBA_DIMM</id>
        <default>$z</default>
    </attribute>
    <attribute>
        <id>MBA_PORT</id>
        <default>$y</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$vpdRec</default></attribute>";

    # call to do any fsp per-dimm attributes
    do_plugin('fsp_dimm', $proc, $ctaur, $dimm, $ordinalId, $dimmHex );

print "\n</targetInstance>\n";
}

sub addSysAttrs
{
    for my $i (0 .. $#systemAttr)
    {
        my $j =0;
        my $sysAttrArraySize=$#{$systemAttr[$i]};
        while ($j<$sysAttrArraySize)
        {
            print "    <attribute>\n";
            print "        <id>$systemAttr[$i][$j]</id>\n";
            $j++;
            print "        <default>$systemAttr[$i][$j]</default>\n";
            print "    </attribute>\n";
            $j++;
        }
    }
}

sub addProcPmAttrs
{
    my ($position,$nodeId) = @_;

    for my $i (0 .. $#SortedPmChipAttr)
    {
        if (($SortedPmChipAttr[$i][CHIP_POS_INDEX] == $position) &&
            ($SortedPmChipAttr[$i][CHIP_NODE_INDEX] == $node) )
        {
            #found the corresponding proc and node
            my $j =0;
            my $arraySize=$#{$SortedPmChipAttr[$i]} - CHIP_ATTR_START_INDEX;
            while ($j<$arraySize)
            {
                print "    <attribute>\n";
                print "        <id>$SortedPmChipAttr[$i][CHIP_ATTR_START_INDEX+$j]</id>\n";
                $j++;
                print "        <default>$SortedPmChipAttr[$i][CHIP_ATTR_START_INDEX+$j]</default>\n";
                print "    </attribute>\n";
                $j++;
            }
        }
    }
}

sub addProcPcieAttrs
{
    my ($position,$nodeId) = @_;

    for my $i (0 .. $#SortedPcie)
    {
        if (($SortedPcie[$i][CHIP_POS_INDEX] == $position) &&
            ($SortedPcie[$i][CHIP_NODE_INDEX] == $node) )
        {
            #found the corresponding proc and node
            my $j =0;
            my $arraySize=$#{$SortedPcie[$i]} - CHIP_ATTR_START_INDEX;
            while ($j<$arraySize)
            {
                print "    <attribute>\n";
                print "        <id>$SortedPcie[$i][CHIP_ATTR_START_INDEX+$j]</id>\n";
                $j++;
                print "        <default>\n";
                print "            $SortedPcie[$i][CHIP_ATTR_START_INDEX+$j]";
                print ",";
                $j++;
                print "$SortedPcie[$i][CHIP_ATTR_START_INDEX+$j]\n";
                print "        </default>\n";
                print "    </attribute>\n";
                $j++;
            }
        }
    }
}

# RTC 80614 - these values will eventually be pulled from the MRW
sub addEeproms
{
    my ($sys, $node, $proc) = @_;

    my $id_name eq "";
    my $port = 0;
    my $devAddr = 0x00;
    my $mur_num = $proc % 2;


    for my $i (0 .. 3)
    {
        # Loops on $i
        # %i = 0 -> EEPROM_VPD_PRIMARY_INFO
        # %i = 1 -> EEPROM_VPD_BACKUP_INFO
        # %i = 2 -> EEPROM_SBE_PRIMARY_INFO
        # %i = 3 -> EEPROM_SBE_BACKUP_INFO

        # no EEPROM_VPD_BACKUP on Murano
        if ( ($i eq 1) && ($CHIPNAME eq "murano"))
        {
            next;
        }


        if($CHIPNAME eq "murano")
        {
            if ($i eq 0 )
            {
                $id_name = "EEPROM_VPD_PRIMARY_INFO";
                $port    = 1;

                if ($mur_num eq 0)
                {
                    $devAddr = 0xA4;
                }
                else
                {
                    $devAddr = 0xA6;
                }
            }

            # $i = 1: EEPROM_VPD_BACKUP_INFO skipped above

            elsif ($i eq 2 )
            {
                $id_name = "EEPROM_SBE_PRIMARY_INFO";
                $port    = 0;
                $devAddr = 0xAC;
            }
            elsif ($i eq 3 )
            {
                $id_name = "EEPROM_SBE_BACKUP_INFO";
                $port    = 0;
                $devAddr = 0xAE;
            }
        }

        elsif ($CHIPNAME eq "venice")
        {
            if ($i eq 0 )
            {
                $id_name = "EEPROM_VPD_PRIMARY_INFO";
                $port    = 0;
                $devAddr = 0xA0;
            }
            elsif ($i eq 1 )
            {
                $id_name = "EEPROM_VPD_BACKUP_INFO";
                $port    = 1;
                $devAddr = 0xA0;
            }
            elsif ($i eq 2 )
            {
                $id_name = "EEPROM_SBE_PRIMARY_INFO";
                $port    = 0;
                $devAddr = 0xA2;
            }
            elsif ($i eq 3 )
            {
                $id_name = "EEPROM_SBE_BACKUP_INFO";
                $port    = 1;
                $devAddr = 0xA2;
            }
        }

        # make devAddr show as a hex number
        my $devAddr_hex = sprintf("0x%02X", $devAddr);

        print "    <attribute>\n";
        print "        <id>$id_name</id>\n";
        print "        <default>\n";
        print "            <field><id>i2cMasterPath</id><value>physical:sys-$sys/node-$node/proc-$proc</value></field>\n";
        print "             <field><id>port</id><value>$port</value></field>\n";
        print "             <field><id>devAddr</id><value>$devAddr_hex</value></field>\n";
        print "             <field><id>engine</id><value>0</value></field>\n";
        print "             <field><id>byteAddrOffset</id><value>0x02</value></field>\n";
        print "             <field><id>maxMemorySizeKB</id><value>0x40</value></field>\n";
        print "             <field><id>writePageSize</id><value>0x80</value></field>\n";
        print "        </default>\n";
        print "    </attribute>\n";
    }

}
sub get_mruid
{
    my($ipath) = @_;
    my $mruData = 0;
    foreach my $i (@{$mruAttr->{'mru-id'}})
    {
        if ($ipath eq $i->{'instance-path'})
        {
            $mruData = $i->{'mrid-value'};
            last;
        }
    }
    return $mruData;
}

sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Usage:

    $scriptname --help
    $scriptname --system=sysname --mrwdir=pathname
                     [--build=hb] [--outfile=XmlFilename]
        --system=systemname
              Specify which system MRW XML to be generated
        --mrwdir=pathname
              Specify the complete dir pathname of the MRW.
        --build=hb
              Specify HostBoot build (hb)
        --outfile=XmlFilename
              Specify the filename for the output XML. If omitted, the output
              is written to STDOUT which can be saved by redirection.
\n";
}
