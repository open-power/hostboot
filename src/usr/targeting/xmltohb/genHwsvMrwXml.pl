#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/genHwsvMrwXml.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012
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
#   This perl script processes the various xml files of the Tuleta MRW to
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

my $mrwdir = "";
my $sysname = "";
my $usage = 0;
my $outFile = "";
my $build = "fsp";
use Getopt::Long;
GetOptions( "mrwdir:s"  => \$mrwdir,
            "system:s"  => \$sysname,
            "outfile:s" => \$outFile,
            "build:s"   => \$build,
            "help"      => \$usage, );

if ($usage || ($mrwdir eq ""))
{
    display_help();
    exit 0;
}

if ($outFile ne "")
{
    open OUTFILE, '+>', $outFile ||
                die "ERROR: unable to create $outFile\n";
    select OUTFILE;
}

my $SYSNAME = uc($sysname);

open (FH, "<$mrwdir/${sysname}-temp-hwsv-attrs.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-temp-hwsv-attrs.xml\n";
close (FH);

my $FapiAttrs = XMLin("$mrwdir/${sysname}-temp-hwsv-attrs.xml",
                          ForceArray => ['value']);

open (FH, "<$mrwdir/${sysname}-chip-ids.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-chip-ids.xml\n";
close (FH);

my $chipIds = XMLin("$mrwdir/${sysname}-chip-ids.xml");

use constant CHIP_ID_NODE => 0;
use constant CHIP_ID_POS  => 1;
use constant CHIP_ID_PATH => 2;

my @chipIDs;
foreach my $i (@{$chipIds->{'chip-id'}})
{
    push @chipIDs, [ $i->{node}, $i->{position}, $i->{'instance-path'} ];
}

open (FH, "<$mrwdir/${sysname}-power-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-power-busses.xml\n";
close (FH);

my $powerbus = XMLin("$mrwdir/${sysname}-power-busses.xml");

my @pbus;
foreach my $i (@{$powerbus->{'power-bus'}})
{
    my $endp1 = $i->{'description'};
    my $endp2 = $endp1;
    $endp1 =~ s/^(.*) to.*/$1/;
    $endp2 =~ s/.* to (.*)\s*$/$1/;
    push @pbus, [ lc($endp1), lc($endp2) ];
    push @pbus, [ lc($endp2), lc($endp1) ];
}

open (FH, "<$mrwdir/${sysname}-cent-vrds.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-cent-vrds.xml\n";
close (FH);

my $vmemCentaur = XMLin("$mrwdir/${sysname}-cent-vrds.xml");

# Capture all pnor attributes into the @unsortedPnorTargets array
use constant VMEM_DEV_PATH_FIELD => 0;
use constant VMEM_I2C_ADDR_FIELD => 1;
use constant VMEM_NODE_FIELD => 2;
use constant VMEM_POS_FIELD => 3;
use constant VMEM_ID_FIELD => 4;

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
            $vmemValue=$vmemArray[$j];
            last;
        }
        else
        {
            $found=0;
        }
    }
    if ($found ==1)
    {
        push (@vmemArray,$vmemValue);
    }
    else
    {
        $vmemValue=$newValue++;
        push (@vmemArray,$vmemValue);
    }

    push (@vmemDevAddr,[$vmemDev, $vmemAddr]);

    my $vmemNode = $i->{'centaur'}->{'target'}->{'node'};
    my $vmemPosition = $i->{'centaur'}->{'target'}->{'position'};

    push (@unsortedVmem,[$vmemDev, $vmemAddr, $vmemNode, $vmemPosition,
                         $vmemValue]);
}


my @SortedVmem = sort byVmemNodePos @unsortedVmem;


open (FH, "<$mrwdir/${sysname}-lpc2spi.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-lpc2spi.xml\n";
close (FH);

my $pnorPath = XMLin("$mrwdir/${sysname}-lpc2spi.xml",
                      forcearray=>['proc-to-pnor-connection']);

# Capture all pnor attributes into the @unsortedPnorTargets array
use constant PNOR_MTD_CHAR_FIELD => 0;
use constant PNOR_BLOCK_DEV_FIELD => 1;
use constant PNOR_POS_FIELD  => 2;
use constant PNOR_NODE_FIELD => 3;
use constant PNOR_PROC_FIELD => 4;

my @unsortedPnorTargets;
foreach my $i (@{$pnorPath->{'proc-to-pnor-connection'}})
{
    my $mtdCharDev = $i->{'lpc2spi'}->{'fsp-dev-paths'}->{'fsp-dev-path'}->
                         {'character-dev-path'};
    my $mtdBlockDev = $i->{'lpc2spi'}->{'fsp-dev-paths'}->{'fsp-dev-path'}->
                          {'block-dev-path'};

    my $pnorPosition = $i->{'flash'}->{'target'}->{'position'};
    my $nodePosition = $i->{'flash'}->{'target'}->{'node'};

    my $procPosition = $i->{'processor'}->{'target'}->{'position'};

    push (@unsortedPnorTargets,[$mtdCharDev, $mtdBlockDev, $pnorPosition,
                                $nodePosition, $procPosition]);

}

my @SortedPnor = sort byPnorNodePos @unsortedPnorTargets;

open (FH, "<$mrwdir/${sysname}-cec-chips.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-cec-chips.xml\n";
close (FH);

my $devpath = XMLin("$mrwdir/${sysname}-cec-chips.xml",
                        KeyAttr=>'instance-path');

open (FH, "<$mrwdir/${sysname}-pcie-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-pcie-busses.xml\n";
close (FH);

my $pcie_buses = XMLin("$mrwdir/${sysname}-pcie-busses.xml");
my %pcie_list;

foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
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
foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
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
    $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->{source}->
      {iop}}->{$lane_set}->{'lane-mask'} = $pcie_bus->{source}->{'lane-mask'};
    $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->{source}->
      {iop}}->{$lane_set}->{'dsmp-capable'} = $dsmp_capable;
    $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->{source}->
      {iop}}->{$lane_set}->{'lane-swap'} = oct($pcie_bus->{source}->
      {'lane-swap-bits'});
    $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->{source}->
      {iop}}->{$lane_set}->{'lane-reversal'} = oct($pcie_bus->{source}->
      {'lane-reversal-bits'});
    $pcie_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->{source}->
      {iop}}->{$lane_set}->{'is-slot'} = $is_slot;

}
my %bifurcation_list;
foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{
    foreach my $lane_set (0,1)
    {
        $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                         {source}->{iop}}->{$lane_set}->{'lane-mask'}= 0;
        $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                         {source}->{iop}}->{$lane_set}->{'lane-swap'}= 0;
        $bifurcation_list{$pcie_bus->{source}->{'instance-path'}}->{$pcie_bus->
                         {source}->{iop}}->{$lane_set}->{'lane-reversal'}= 0;
    }


}
foreach my $pcie_bus (@{$pcie_buses->{'pcie-bus'}})
{

    if( exists($pcie_bus->{source}->{'bifurcation-settings'}))
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


open (FH, "<$mrwdir/${sysname}-system-policy.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-system-policy.xml\n";
close (FH);

my $policy = XMLin("$mrwdir/${sysname}-system-policy.xml");

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
}

open (FH, "<$mrwdir/${sysname}-fsi-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-fsi-busses.xml\n";
close (FH);

my $fsiBus = XMLin("$mrwdir/${sysname}-fsi-busses.xml");

# Capture all FSI connections into the @Fsis array
use constant FSI_TYPE_FIELD   => 0;
use constant FSI_LINK_FIELD   => 1;
use constant FSI_TARGET_FIELD => 2;
my @Fsis;
foreach my $i (@{$fsiBus->{'fsi-bus'}})
{
    push @Fsis, [ $i->{master}->{type}, $i->{master}->{link},
        "n$i->{slave}->{target}->{node}:p$i->{slave}->{target}->{position}" ];
}

open (FH, "<$mrwdir/${sysname}-psi-busses.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-psi-busses.xml\n";
close (FH);

my $psiBus = XMLin("$mrwdir/${sysname}-psi-busses.xml");

# Capture all PSI connections into the @PSIs array
use constant PSI_FSP_INSTANCE_PATH_FIELD     => 0;
use constant PSI_MASTER_NODE_FIELD           => 1;
use constant PSI_MASTER_POS_FIELD            => 2;
use constant PSI_MASTER_CHIP_UNIT_FIELD      => 3;
use constant PSI_PROC_NODE_FIELD             => 4;
use constant PSI_PROC_POS_FIELD              => 5;
use constant PSI_SLAVE_CHIP_UNIT_FIELD       => 6;
use constant PSI_MASTER_DEV_PATH             => 7;
use constant PSI_ORDINAL_ID                  => 8;


my @PSIs;
foreach my $i (@{$psiBus->{'psi-bus'}})
{
    push @PSIs, [
                  $i->{fsp}->{'instance-path'},
                  $i->{fsp}->{'psi-unit'}->{target}->{node},
                  $i->{fsp}->{'psi-unit'}->{target}->{position},
                  $i->{fsp}->{'psi-unit'}->{target}->{chipUnit},
                  $i->{processor}->{target}->{node},
                  $i->{processor}->{target}->{position},
                  $i->{processor}->{'psi-unit'}->{target}->{chipUnit},
                  $i->{fsp}->{'psi-dev-path'},
                  "",
                ];
}

#Sort PSI array based on Node,Position & Chip Unit.
my @SPSIs = sort byPSINodePosChpUnit @PSIs;

my $PSIOrdinal = 0;
# Increment the Ordinal ID in sequential order for PSI.
for my $i ( 0 .. $#SPSIs )
{
    $SPSIs[$i] [PSI_ORDINAL_ID] = $PSIOrdinal;
    $PSIOrdinal += 2; #Leave the immediate next one for peer (proc) PSI target.
}

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
         $i->{mcs}->{target}->{position}, 0 ];
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

# Find master processor's node and proc. The FSP master is always connected to
# the msater processor. The master processor's node is used as the system node

my $node = 0;
my $Mproc = 0;
for my $i ( 0 .. $#Fsis )
{
    if ((lc($Fsis[$i][FSI_TYPE_FIELD]) eq "fsp master") &&
        (lc($Fsis[$i][FSI_TARGET_FIELD]) eq "n[0-9]+:p[0-9]+"))
    {
        $node = $Fsis[$i][FSI_TARGET_FIELD];
        $Mproc = $node;
        $node =~ s/n(.*):p.*/$1/;
        $Mproc =~ s/.*p(.*)/$1/;
    }
}

# Generate @STargets array from the @Targets array to have the order as shown
# belows. The rest of the codes assume that this order is in place
#
#   pu
#   ex  (one or more EX of pu before it)
#   mcs (one or more MCS of pu before it)
#   (Repeat for remaining pu)
#   memb
#   mba (to for membuf before it)
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

        my $position = $SortedTargets[$i][POS_FIELD];

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "ex") &&
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

        my $position = $SortedTargets[$i][POS_FIELD];

        for my $j ( 0 .. $#SortedTargets )
        {
            if (($SortedTargets[$j][NAME_FIELD] eq "mba") &&
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

# Finally, generate the xml file.
print "<!-- Source path = $mrwdir -->\n";

print "<attributes>\n";

# First, generate system target (always sys0)
my $sys = 0;
generate_sys();

# Second, generate system node using the master processor's node
generate_system_node();

# Third generate the FSP chip
if ($build eq "fsp")
{

    #check if fsp xml is present
    open (FH, "<$mrwdir/${sysname}-fsp.xml") ||
        die "ERROR: unable to open $mrwdir/${sysname}-fsp.xml\n";
    close (FH);

    my $fspXml = XMLin("$mrwdir/${sysname}-fsp.xml");

    #TODO Via 48545
    #IN RFSP scenario, there will be more than one FSP in system XML.
    #Verify it during RFSP design

    # Get MBX dev path from XML and send it as an argument
    generate_system_fsp( $fspXml->{'host-mailbox-dev-path'});
}

# Fourth, generate the proc, occ, ex-chiplet, mcs-chiplet
# unit-tp (if on fsp), pcie bus and A/X-bus.
my $ex_count = 0;
my $mcs_count = 0;
my $proc_ordinal_id =0;
my $fru_id = 0;
my @fru_paths;
my $hwTopology =0;
for (my $do_core = 0, my $i = 0; $i <= $#STargets; $i++)
{
    if ($STargets[$i][NAME_FIELD] eq "pu")
    {
        my $fru_found = 0;
        my $fru_path = $STargets[$i][FRU_PATH];
        my $proc = $STargets[$i][POS_FIELD];
        my $ipath = $STargets[$i][PATH_FIELD];
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
            if ($build eq "fsp")
            {
                generate_occ($proc);
                for my $psi ( 0 .. $#SPSIs )
                {
                    if(($STargets[$i][NODE_FIELD] eq
                           $SPSIs[$psi][PSI_PROC_NODE_FIELD]) &&
                       ($STargets[$i][POS_FIELD] eq
                           $SPSIs[$psi][PSI_PROC_POS_FIELD] ))
                    {
                      my $fsp = 0;
                      if(chop($SPSIs[$psi][PSI_FSP_INSTANCE_PATH_FIELD]) eq '1')
                      {
                         $fsp = 1;
                      }
                      generate_proc_psi($SPSIs[$psi][PSI_PROC_NODE_FIELD],
                                       $SPSIs[$psi][PSI_PROC_POS_FIELD],
                                       $SPSIs[$psi][PSI_SLAVE_CHIP_UNIT_FIELD],
                                       $SPSIs[$psi][PSI_MASTER_NODE_FIELD],
                                       $SPSIs[$psi][PSI_MASTER_CHIP_UNIT_FIELD],
                                       $SPSIs[$psi][PSI_ORDINAL_ID],
                                       $fsp);
                    }
                }
            }
        }
        else
        {
            my $fsi;
            for (my $j = 0; $j <= $#Fsis; $j++)
            {
                if ($Fsis[$j][FSI_TARGET_FIELD] eq "n${node}:p$proc")
                {
                    $fsi = $Fsis[$j][FSI_LINK_FIELD];
                    last;
                }
            }
            generate_proc($proc, $ipath, $lognode, $logid,
                          $proc_ordinal_id, 0, 1, $fsi,$fru_id,$hwTopology);
            if ($build eq "fsp")
            {
                generate_occ($proc);
                for my $psi ( 0 .. $#SPSIs )
                {
                    if(($STargets[$i][NODE_FIELD] eq
                           $SPSIs[$psi][PSI_PROC_NODE_FIELD]) &&
                       ($STargets[$i][POS_FIELD] eq
                           $SPSIs[$psi][PSI_PROC_POS_FIELD] ))
                    {
                      my $fsp = 0;
                      if(chop($SPSIs[$psi][PSI_FSP_INSTANCE_PATH_FIELD]) eq '1')
                      {
                         $fsp = 1;
                      }
                      generate_proc_psi($SPSIs[$psi][PSI_PROC_NODE_FIELD],
                                       $SPSIs[$psi][PSI_PROC_POS_FIELD],
                                       $SPSIs[$psi][PSI_SLAVE_CHIP_UNIT_FIELD],
                                       $SPSIs[$psi][PSI_MASTER_NODE_FIELD],
                                       $SPSIs[$psi][PSI_MASTER_CHIP_UNIT_FIELD],
                                       $SPSIs[$psi][PSI_ORDINAL_ID],
                                       $fsp);
                    }
                }
            }
        }
    }
    elsif ($STargets[$i][NAME_FIELD] eq "ex")
    {
        my $proc = $STargets[$i][POS_FIELD];
        my $ex = $STargets[$i][UNIT_FIELD];
        if ($do_core == 0)
        {
            if ($ex_count == 0)
            {
                print "\n<!-- $SYSNAME n${node}p$proc EX units -->\n";
            }
            generate_ex($proc, $ex, $STargets[$i][ORDINAL_FIELD]);
            $ex_count++;
            if ($STargets[$i+1][NAME_FIELD] eq "mcs")
            {
                $do_core = 1;
                $i -= $ex_count;
                $ex_count = 0;
            }
        }
        else
        {
            if ($ex_count == 0)
            {
                print "\n<!-- $SYSNAME n${node}p$proc core units -->\n";
            }
            generate_ex_core($proc,$ex,$STargets[$i][ORDINAL_FIELD]);
            $ex_count++;
            if ($STargets[$i+1][NAME_FIELD] eq "mcs")
            {
                $do_core = 0;
                $ex_count = 0;
            }
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
        generate_mcs($proc,$mcs, $STargets[$i][ORDINAL_FIELD]);
        $mcs_count++;
        if (($STargets[$i+1][NAME_FIELD] eq "pu") ||
            ($STargets[$i+1][NAME_FIELD] eq "memb"))
        {
            $mcs_count = 0;
            generate_pcies($proc,$proc_ordinal_id);
            generate_ax_buses($proc, "A",$proc_ordinal_id);
            generate_ax_buses($proc, "X",$proc_ordinal_id);
        }
    }
}

# Fifth, generate the Centaur, MBS, and MBA

my $memb;
my $membMcs;
my $mba_count = 0;
my $vmem_id =0;
my $vmem_count =0;
my $vmemAddr_prev="";
my $vmemDevPath_prev="";

for my $i ( 0 .. $#STargets )
{
    if ($STargets[$i][NAME_FIELD] eq "memb")
    {
        $memb = $STargets[$i][POS_FIELD];
        my $ipath = $STargets[$i][PATH_FIELD];
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
        my $relativeCentaurRid = $STargets[$i][PLUG_POS];

        #should note that the $SortedVmem is sorted by node and position and
        #currently $STargets is also sorted by node and postion. If this ever
        #changes then will need to make a modification here
        my $vmemDevPath=$SortedVmem[$vmem_count][VMEM_DEV_PATH_FIELD];
        my $vmemAddr=$SortedVmem[$vmem_count][VMEM_I2C_ADDR_FIELD];
        my $vmem_id=$SortedVmem[$vmem_count][VMEM_ID_FIELD];
        $vmem_count++;

        generate_centaur( $memb, $membMcs, $cfsi, $ipath,
                               $STargets[$i][ORDINAL_FIELD],$relativeCentaurRid,
                               $vmem_id, $vmemDevPath, $vmemAddr);
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
        generate_mba( $memb, $membMcs, $mba, $STargets[$i][ORDINAL_FIELD] );
        $mba_count += 1;
        if ($mba_count == 2)
        {
            $mba_count = 0;
            print "\n<!-- $SYSNAME Centaur n${node}p${memb} : end -->\n"
        }
    }
}

# Sixth, generate DIMM targets

print "\n<!-- $SYSNAME Centaur DIMMs -->\n";

for my $i ( 0 .. $#SMembuses )
{
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
    print "\n<!-- C-DIMM n${node}:p${pos} -->\n";
    for my $id ( 0 .. 7 )
    {
        my $dimmid = $dimm;
        $dimmid <<= 3;
        $dimmid |= $id;
        $dimmid = sprintf ("%d", $dimmid);
        generate_dimm( $proc, $mcs, $ctaur, $pos, $dimmid, $id,
                             ($SMembuses[$i][BUS_ORDINAL_FIELD]*8)+$id,
                              $relativeDimmRid);
    }
}

if ($build eq "fsp")
{
    print "\n<!--$SYSNAME PNOR -->\n";
    for my $i (0 .. $#SortedPnor)
    {
        generate_pnor($sys,$SortedPnor[$i][PNOR_NODE_FIELD],
           $SortedPnor[$i][PNOR_POS_FIELD],$SortedPnor[$i][PNOR_MTD_CHAR_FIELD],
           $SortedPnor[$i][PNOR_BLOCK_DEV_FIELD],
           $SortedPnor[$i][PNOR_PROC_FIELD],$i);
    }
}

print "\n</attributes>\n";

# All done!
#close ($outFH);
exit 0;

##########   Subroutines    ##############

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
# Compares two PNOR instances based on the node and position #
################################################################################
sub byPnorNodePos($$)
{
    my $retVal = -1;

    my $lhsInstance_node = $_[0][PNOR_NODE_FIELD];
    my $rhsInstance_node = $_[1][PNOR_NODE_FIELD];
    if(int($lhsInstance_node) eq int($rhsInstance_node))
    {
         my $lhsInstance_pos = $_[0][PNOR_POS_FIELD];
         my $rhsInstance_pos = $_[1][PNOR_POS_FIELD];
         if(int($lhsInstance_pos) eq int($rhsInstance_pos))
         {
                die "ERROR: Duplicate pnor positions: 2 pnors with same
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

################################################################################
# Compares two PSI Units instances based on the node, position & chip unit #
################################################################################
sub byPSINodePosChpUnit($$)
{
    my $retVal = -1;

    my $lhsInstance_node = $_[0][PSI_MASTER_NODE_FIELD];
    my $rhsInstance_node = $_[1][PSI_MASTER_NODE_FIELD];
    if(int($lhsInstance_node) eq int($rhsInstance_node))
    {
         my $lhsInstance_pos = $_[0][PSI_MASTER_POS_FIELD];
         my $rhsInstance_pos = $_[1][PSI_MASTER_POS_FIELD];
         if(int($lhsInstance_pos) eq int($rhsInstance_pos))
         {
              my $lhsInstance_chip_unit = $_[0][PSI_MASTER_CHIP_UNIT_FIELD];
              my $rhsInstance_chip_unit = $_[1][PSI_MASTER_CHIP_UNIT_FIELD];
              if(int($lhsInstance_chip_unit) eq int($rhsInstance_chip_unit))
              {
                  die "ERROR: Duplicate psi master units : 2 psi units with \
                      same node, position and chip unit \
                      NODE: $lhsInstance_node POSITION: $lhsInstance_pos \
                      CHIP UNIT: $lhsInstance_chip_unit \n";
              }
              elsif(int($lhsInstance_chip_unit) > int($rhsInstance_chip_unit))
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

sub generate_sys
{
    my $proc_refclk = $policy->{'required-policy-settings'}->
                               {'processor-refclock-frequency'}->{content};
    my $mem_refclk = $policy->{'required-policy-settings'}->
                              {'memory-refclock-frequency'}->{content};

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
    <attribute>
        <id>FREQ_PROC_REFCLOCK</id>
        <default>$proc_refclk</default>
    </attribute>
    <attribute>
        <id>FREQ_MEM_REFCLOCK</id>
        <default>$mem_refclk</default>
    </attribute>
    <!-- PAYLOAD_BASE and PAYLOAD_ENTRY should be from FW xml -->
    <attribute>
        <id>PAYLOAD_BASE</id>
        <default>256</default>
    </attribute>
    <attribute>
        <id>PAYLOAD_ENTRY</id>
        <default>0x180</default>
    </attribute>\n";

    print "    <!-- System Attributes from MRW -->\n";
    addSysAttrs();
    print "    <!-- End System Attributes from MRW -->\n";

    print "
    <!-- The default value of the following three attributes are written  -->
    <!-- by the HWP using them. The default values are not from MRW. They -->
    <!-- are included here FYI.                                           -->
    <attribute>
        <id>PROC_EPS_GB_DIRECTION</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>PROC_EPS_GB_PERCENTAGE</id>
        <default>0x14</default>
    </attribute>
    <attribute>
        <id>PROC_FABRIC_ASYNC_SAFE_MODE</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>SP_FUNCTIONS</id>
        <default>
            <field><id>fsiSlaveInit</id><value>1</value></field>
            <field><id>mailboxEnabled</id><value>1</value></field>
            <field><id>fsiMasterInit</id><value>1</value></field>
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
        <id>MSS_MCA_HASH_MODE</id>
        <default>0</default>
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

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>0</default>
    </attribute>";
    }

print "
</targetInstance>

";
}

# TODO via RTC:49504
# Need to support RFSP and dynamically generate HUID,RID and ORDINALID.
sub generate_system_fsp
{
    #get the mailbox dev path
    my ($fspMbxPath) = @_;
    print "
<!-- $SYSNAME System fsp0 -->

<targetInstance>
    <id>sys${sys}node${node}fsp0</id>
    <type>chip-fsp-power8</type>
    <attribute>
        <id>HUID</id>
        <default>0x00150000</default>
    </attribute>
    <attribute>
        <id>POSITION</id>
        <default>0</default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-${sys}/node-${node}/fsp-0</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-${sys}/node-${node}/fsp-0</default>
    </attribute>
    <attribute>
        <id>CHIP_ID</id>
        <default>0xF0F1</default>
    </attribute>
    <attribute>
        <id>EC</id>
        <default>0x10</default>
    </attribute>
    <attribute>
        <id>HOST_MAILBOX_DEV_PATH</id>
        <default>${fspMbxPath}</default>
    </attribute>";

    if ($build eq "fsp")
    {
        print "
    <attribute>
        <id>RID</id>
        <default>0x0200</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>0</default>
    </attribute>";
    }

    print "
</targetInstance>
";

#Create the corresponding the fsp-psi targets.
generate_fsp_psi();

}


sub generate_system_node
{
    print "
<!-- $SYSNAME System node $node -->

<targetInstance>
    <id>sys${sys}node${node}</id>
    <type>enc-node-power8</type>
    <attribute><id>HUID</id><default>0x00020000</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>RID</id>
        <default>0x800</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$node</default>
    </attribute>";
    }

    print "
</targetInstance>
";

    if ($build eq "fsp")
    {
          print "
<!-- APSS For system node $node -->

<targetInstance>
    <id>sys0node0apss0</id>
    <type>apss</type>
    <attribute><id>HUID</id><default>0x00120000</default></attribute>
    <attribute><id>ORDINAL_ID</id><default>$node</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/apss-$node</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/apss-$node</default>
    </attribute>
</targetInstance>

<!-- DPSS For system node $node -->

<targetInstance>
    <id>sys0node0dpss0</id>
    <type>dpss</type>
    <attribute><id>HUID</id><default>0x00110000</default></attribute>
    <attribute><id>ORDINAL_ID</id><default>$node</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/dpss-$node</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$node/node-$node/dpss-$node</default>
    </attribute>
</targetInstance>

";
    }
}

sub generate_proc
{
    my ($proc, $ipath, $lognode, $logid, $ordinalId, $master, $slave, $fsi,
        $fruid,$hwTopology) = @_;
    my $uidstr = sprintf("0x%02X05%04X",${node},${proc}+${node}*8);
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
    print "
<!-- $SYSNAME n${node}p${proc} processor chip -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}</id>
    <type>chip-processor-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>${proc}</default></attribute>
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
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc</default>
    </attribute>
    <attribute>
        <id>FABRIC_NODE_ID</id>
        <default>$lognode</default>
    </attribute>
    <attribute>
        <id>FABRIC_CHIP_ID</id>
        <default>$logid</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$proc</default></attribute>";

    if ($slave)
    {
        print "
    <!-- FSI is connected via proc${Mproc}:MFSI-$fsi -->
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

    if ($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>
    <attribute>
        <id>FSP_SCOM_DEVICE_PATH</id>
        <default>$scompath</default>
        <sizeInclNull>$scomsize</sizeInclNull>
    </attribute>
    <attribute>
        <id>FSP_SCAN_DEVICE_PATH</id>
        <default>$scanpath</default>
        <sizeInclNull>$scansize</sizeInclNull>
    </attribute>
    <attribute>
        <id>RID</id>
        <default>0x100$proc</default>
    </attribute>
    <attribute>
        <id>FRU_ID</id>
        <default>$fruid</default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IOP_SWAP_NON_BIFURCATED</id>
        <default>
            $pcie_list{$ipath}{0}{0}{'lane-swap'},
              $pcie_list{$ipath}{0}{1}{'lane-swap'},
            $pcie_list{$ipath}{1}{0}{'lane-swap'},
              $pcie_list{$ipath}{1}{1}{'lane-swap'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IOP_REVERSAL_NON_BIFURCATED</id>
        <default>
            $pcie_list{$ipath}{0}{0}{'lane-reversal'},
              $pcie_list{$ipath}{0}{1}{'lane-reversal'},
            $pcie_list{$ipath}{1}{0}{'lane-reversal'},
              $pcie_list{$ipath}{1}{1}{'lane-reversal'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_LANE_MASK_NON_BIFURCATED</id>
        <default>
            $pcie_list{$ipath}{0}{0}{'lane-mask'},
              $pcie_list{$ipath}{0}{1}{'lane-mask'},
            $pcie_list{$ipath}{1}{0}{'lane-mask'},
              $pcie_list{$ipath}{1}{1}{'lane-mask'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IOP_SWAP_BIFURCATED</id>
        <default>
            $bifurcation_list{$ipath}{0}{0}{'lane-swap'},
              $bifurcation_list{$ipath}{0}{1}{'lane-swap'},
            $bifurcation_list{$ipath}{1}{0}{'lane-swap'},
              $bifurcation_list{$ipath}{1}{1}{'lane-swap'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_LANE_MASK_BIFURCATED</id>
        <default>
            $bifurcation_list{$ipath}{0}{0}{'lane-mask'},
              $bifurcation_list{$ipath}{0}{1}{'lane-mask'},
            $bifurcation_list{$ipath}{1}{0}{'lane-mask'},
              $bifurcation_list{$ipath}{1}{1}{'lane-mask'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IOP_REVERSAL_BIFURCATED</id>
        <default>
            $bifurcation_list{$ipath}{0}{0}{'lane-reversal'},
              $bifurcation_list{$ipath}{0}{1}{'lane-reversal'},
            $bifurcation_list{$ipath}{1}{0}{'lane-reversal'},
              $bifurcation_list{$ipath}{1}{1}{'lane-reversal'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_DSMP_CAPABLE</id>
        <default>
            $pcie_list{$ipath}{0}{0}{'dsmp-capable'},
              $pcie_list{$ipath}{0}{1}{'dsmp-capable'},
            $pcie_list{$ipath}{1}{0}{'dsmp-capable'},
              $pcie_list{$ipath}{1}{1}{'dsmp-capable'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_IS_SLOT</id>
        <default>
            $pcie_list{$ipath}{0}{0}{'is-slot'},
              $pcie_list{$ipath}{0}{1}{'is-slot'},
            $pcie_list{$ipath}{1}{0}{'is-slot'},
              $pcie_list{$ipath}{1}{1}{'is-slot'}
        </default>
    </attribute>
    <attribute>
        <id>PROC_HW_TOPOLOGY</id>
        <default>$hwTopology</default>
    </attribute>
    <attribute>
        <id>PROC_PCIE_LANE_EQUALIZATION</id>
        <default>0,0,0,0</default>
    </attribute>";
    }

    if (($mboxsize != 0) && ($build eq "fsp"))
    {
        print "
    <attribute>
        <id>FSP_MBOX_DEVICE_PATH</id>
        <default>$mboxpath</default>
        <sizeInclNull>$mboxsize</sizeInclNull>
    </attribute>";
    }

    # Data from PHYP Memory Map
    print "\n";
    print "    <!-- Data from PHYP Memory Map -->\n";

    # Calculate the FSP and PSI BRIGDE BASE ADDR
    my $fspBase = 0;
    my $psiBase = 0;
    foreach my $i (@{$psiBus->{'psi-bus'}})
    {
        if ( $i->{'processor'}->{target}->{position} eq $proc )
        {
            $fspBase = 0x0003FFE000000000 + 0x100000000*$proc;
            $psiBase = 0x0003FFFE80000000 + 0x100000*$proc;
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
       0x0003FFFF80000000 + 0x100000*$proc );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 7GB, 1MB per PHB (=4MB per proc)
    printf( "    <attribute><id>PHB_BASE_ADDRS</id>\n" );
    printf( "        <default>\n" );
    printf( "            0x%016X,0x%016X,\n",
       0x0003FFFE40000000 + 0x400000*$proc + 0x100000*0,
         0x0003FFFE40000000 + 0x400000*$proc + 0x100000*1 );
    printf( "            0x%016X,0x%016X\n",
       0x0003FFFE40000000 + 0x400000*$proc + 0x100000*2,
         0x0003FFFE40000000 + 0x400000*$proc + 0x100000*3 );
    printf( "        </default>\n" );
    printf( "    </attribute>\n" );

    # Starts at 976TB, 64GB per PHB (=256GB per proc)
    printf( "    <attribute><id>PCI_BASE_ADDRS</id>\n" );
    printf( "        <default>\n" );
    printf( "            0x%016X,0x%016X,\n",
       0x0003D00000000000 + 0x4000000000*$proc + 0x1000000000*0,
         0x0003D00000000000 + 0x4000000000*$proc + 0x1000000000*1 );
    printf( "            0x%016X,0x%016X\n",
       0x0003D00000000000 + 0x4000000000*$proc + 0x1000000000*2,
         0x0003D00000000000 + 0x4000000000*$proc + 0x1000000000*3 );
    printf( "        </default>\n" );
    printf( "    </attribute>\n" );

    # Starts at 0, 2TB per proc
    printf( "    <attribute><id>MEM_BASE</id>\n" );
    printf( "        <default>0x%016X</default>\n", 0x20000000000*$proc );
    printf( "    </attribute>\n" );

    # Starts at 512TB, 2TB per proc
    printf( "    <attribute><id>MIRROR_BASE</id>\n" );
    printf( "        <default>0x%016X</default>\n",
       0x0002000000000000 + 0x20000000000*$proc );
    printf( "    </attribute>\n" );

    # Starts at 1024TB - 3GB
    printf( "    <attribute><id>RNG_BASE_ADDR</id>\n" );
    printf( "        <default>0x%016X</default>\n",
       0x0003FFFF40000000 + 0x1000*$proc );
    printf( "    </attribute>\n" );

    print "    <!-- End PHYP Memory Map -->\n\n";
    # end PHYP Memory Map

    print "    <!-- PROC_PCIE_ attributes -->\n";
    addProcPcieAttrs( $proc );
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
    </attribute>
</targetInstance>\n";

}

sub generate_occ
{
    my ($proc) = @_;

    # RTC: 49574
    # The calculations for HUID and ordinal ID are not correct for multi-node
    # configurations, since HUID doesn't take into account the node value, and
    # the oridinal ID repeats on every node.  Fix these with the multi-node
    # story
    my $uidstr = sprintf("0x0013000%01X",$proc);
    my $ordinalId = $proc;

        print "
<!-- $SYSNAME n${node}p${proc} OCC units -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}occ$proc</id>
    <type>occ</type>
        <attribute><id>HUID</id><default>${uidstr}</default></attribute>
        <attribute><id>ORDINAL_ID</id><default>$ordinalId</default></attribute>
        <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/occ-$proc</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/occ-$proc</default>
    </attribute>
</targetInstance>\n";

}

sub generate_fsp_psi
{
  my $fsp = 0;
  my $old_fsp = -1;

    for my $psi ( 0 .. $#SPSIs )
    {
       $fsp = (chop($SPSIs[$psi][PSI_FSP_INSTANCE_PATH_FIELD]) eq '0') ? 0 : 1;
       if($fsp ne $old_fsp)
       {
          print "
<!-- $SYSNAME n${node}fsp${fsp} PSI units -->";
       }

       generate_fsp_psi_units( $SPSIs[$psi][PSI_PROC_NODE_FIELD],
                               $SPSIs[$psi][PSI_PROC_POS_FIELD],
                               $SPSIs[$psi][PSI_SLAVE_CHIP_UNIT_FIELD],
                               $SPSIs[$psi][PSI_MASTER_NODE_FIELD],
                               $SPSIs[$psi][PSI_MASTER_CHIP_UNIT_FIELD],
                               $SPSIs[$psi][PSI_MASTER_DEV_PATH],
                               $SPSIs[$psi][PSI_ORDINAL_ID],
                               $fsp );
      $old_fsp = $fsp;
    }
}

sub generate_fsp_psi_units
{
    my (  $proc_node, $proc_pos,  $proc_chip_unit,
          $fsp_node, $fsp_chip_unit, $dev_path,$psi_ordinal, $fsp ) = @_;

    # RTC: 49574
    # The calculation for HUID is not correct for multi-node
    # configurations, since ordinal ID should not be used in HUID calculations.
    # Instead, the lower byte should repeat for every node.
    # Fix this with the multi-node story
    my $uidstr = sprintf("0x%02X14%04X",${node},$psi_ordinal);

    print "
<targetInstance>
    <id>sys${sys}node${fsp_node}fsp${fsp}psi${fsp_chip_unit}</id>
    <type>unit-psi-power8</type>
    <attribute>
        <id>HUID</id>
        <default>${uidstr}</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>${psi_ordinal}</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>${fsp_chip_unit}</default>
    </attribute>
    <attribute>
        <id>PSI_DEVICE_PATH</id>
        <default>${dev_path}</default>
    </attribute>
    <attribute>
        <id>PRIMARY_CAPABILITIES</id>
        <default>
             <field><id>supportsFsiScom</id><value>0</value></field>
             <field><id>supportsXscom</id><value>0</value></field>
             <field><id>supportsInbandScom</id><value>0</value></field>
             <field><id>reserved</id><value>0</value></field>
        </default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-${sys}/node-${fsp_node}/fsp-${fsp}/"
                        . "psi-${fsp_chip_unit}</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-${sys}/node-${fsp_node}/fsp-${fsp}/"
                        . "psi-${fsp_chip_unit}</default>
    </attribute>
    <attribute>
        <id>PEER_TARGET</id>
        <default>physical:sys-${sys}/node-${proc_node}/proc-${proc_pos}/"
                        . "psi-${proc_chip_unit}</default>
    </attribute>";
if($fsp_chip_unit eq 0)
{
print"
    <attribute>
        <id>PSI_LINK_STATE</id>
        <default>ACTIVE</default>
    </attribute>";
}
print"
</targetInstance>\n";
}

sub generate_proc_psi
{
    my ($proc_node,$proc_pos,$proc_chip_unit,
        $fsp_node,$fsp_chip_unit, $psi_ordinal, $fsp) = @_;
    $psi_ordinal += 1;

    my $uidstr = sprintf("0x%02X14%04X",${node},$psi_ordinal);
        print "
<!-- $SYSNAME n${proc_node}p${proc_pos} PSI units -->

<targetInstance>
    <id>sys${sys}node${proc_node}proc${proc_pos}psi${proc_chip_unit}</id>
    <type>unit-psi-power8</type>
    <attribute>
        <id>HUID</id>
        <default>${uidstr}</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>${psi_ordinal}</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>${proc_chip_unit}</default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-${sys}/node-${proc_node}/proc-${proc_pos}/"
                       . "psi-${proc_chip_unit}</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-${sys}/node-${proc_node}/proc-${proc_pos}/"
                       . "psi-${proc_chip_unit}</default>
    </attribute>
    <attribute>
        <id>PEER_TARGET</id>
        <default>physical:sys-${sys}/node-${fsp_node}/fsp-${fsp}/"
                       . "psi-${fsp_chip_unit}</default>
    </attribute>";
if($fsp_chip_unit eq 0)
{
print"
    <attribute>
        <id>PSI_LINK_STATE</id>
        <default>ACTIVE</default>
    </attribute>";
}
print"
</targetInstance>\n";
}

sub generate_ex
{
    my ($proc, $ex, $ordinalId) = @_;
    my $uidstr = sprintf("0x%02X06%04X",${node},$ex+$proc*16+${node}*8*16);
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}ex$ex</id>
    <type>unit-ex-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/ex-$ex</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/ex-$ex</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$ex</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

    print "
</targetInstance>
";
}

sub generate_ex_core
{
    my ($proc, $ex, $ordinalId) = @_;
    my $uidstr = sprintf("0x%02X07%04X",${node},$ex+$proc*16+${node}*8*16);
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}ex${ex}core0</id>
    <type>unit-core-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/ex-$ex/core-0</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/ex-$ex/core-0</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$ex</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

    print "
</targetInstance>
";
}

sub generate_mcs
{
    my ($proc, $mcs, $ordinalId) = @_;
    my $uidstr = sprintf("0x%02X0B%04X",${node},$mcs+$proc*8+${node}*8*8);

    #IBSCOM address range starts at 0x0003E00000000000 (992 TB)
    #128GB per MCS/Centaur
    #Addresses assigned by logical node, not physical node
    #For Murano, each physical node is 2 logical nodes.
    my $nodeOffset = 0x40*(${node}*2+(int($proc/2)));
    my $procOffset = 0x10*($proc%2);
    my $mcsOffset = $nodeOffset + $procOffset + $mcs*2;
    my $mscStr = sprintf("0x0003E%02X00000000", $mcsOffset);

    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}mcs$mcs</id>
    <type>unit-mcs-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/mcs-$mcs</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$mcs</default>
    </attribute>
    <attribute><id>IBSCOM_MCS_BASE_ADDR</id>
        <!-- baseAddr = 0x0003E00000000000, 128GB per MCS -->
        <default>$mscStr</default>
    </attribute>
    <!-- TODO When MRW provides the information, these two attributes
         should be included. values of X come from MRW.
    <attribute>
        <id>EI_BUS_RX_MSB_LSB_SWAP</id>
        <default>X</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_MSB_LSB_SWAP</id>
        <default>X</default>
    </attribute>
    -->";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

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

sub generate_a_pcie
{
    my ($proc, $phb, $ordinalId) = @_;
    my $uidstr = sprintf("0x%02X10%04X",${node},$phb+$proc*3+${node}*8*3);
    print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}pci${phb}</id>
    <type>unit-pci-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/pci-$phb</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/pci-$phb</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$phb</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

    print "
</targetInstance>
";
}

sub generate_ax_buses
{
    my ($proc, $type, $ordinalId) = @_;

    my $proc_name = "n${node}p${proc}";
    print "\n<!-- $SYSNAME $proc_name ${type}BUS units -->\n";
    my $minbus = ($type eq "A") ? 0 : 1;
    my $maxbus = ($type eq "A") ? 2 : 1;
    my $numperchip = ($type eq "A") ? 3 : 4;
    my $typenum = ($type eq "A") ? 0x0F : 0x0E;
    $type = lc( $type );
    for my $i ( $minbus .. $maxbus )
    {
        my $uidstr = sprintf( "0x%02X%02X%04X",
            ${node},
            $typenum,
            $i+$proc*($numperchip)+${node}*8*($numperchip));
        $ordinalId = $i+($ordinalId*($numperchip));

        my $peer = 0;
        my $p_proc = 0;
        my $p_port = 0;
        foreach my $j ( @pbus )
        {
            if ($j->[0] eq "n${node}:p${proc}:${type}${i}")
            {
                $peer = 1;
                $p_proc = $j->[1];
                $p_port = $p_proc;
                $p_proc =~ s/^.*:p(.*):.*$/$1/;
                $p_port =~ s/.*:p.*:.(.*)$/$1/;
                last;
            }
        }
        print "
<targetInstance>
    <id>sys${sys}node${node}proc${proc}${type}bus$i</id>
    <type>unit-${type}bus-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/${type}bus-$i</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/${type}bus-$i</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$i</default>
    </attribute>";
        if ($peer)
        {
            print "
    <attribute>
        <id>PEER_TARGET</id>
        <default>physical:sys-$sys/node-$node/proc-$p_proc/"
            . "${type}bus-$p_port</default>
    </attribute>";
        }

        if($build eq "fsp")
        {
            print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
        }

        print "\n</targetInstance>\n";
    }
}

sub generate_centaur
{
    my ($ctaur, $mcs, $cfsi, $ipath, $ordinalId, $relativeCentaurRid,
            $vmemId, $vmemDevPath, $vmemAddr) = @_;
    my $scompath = $devpath->{chip}->{$ipath}->{'scom-path'};
    my $scanpath = $devpath->{chip}->{$ipath}->{'scan-path'};
    my $scomsize = length($scompath) + 1;
    my $scansize = length($scanpath) + 1;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $uidstr = sprintf("0x%02X04%04X",${node},$mcs+$proc*8+${node}*8*8);

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
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur</default>
    </attribute>
    <attribute>
        <id>VMEM_ID</id>
        <default>$vmemId</default>
    </attribute>
    <attribute>
        <id>VMEM_ID</id>
        <default>$vmemId</default>
    </attribute>
    <!-- TODO When MRW provides the information, these two attributes
         should be included. values of X come from MRW.
    <attribute>
        <id>EI_BUS_RX_MSB_LSB_SWAP</id>
        <default>X</default>
    </attribute>
    <attribute>
        <id>EI_BUS_TX_MSB_LSB_SWAP</id>
        <default>X</default>
    </attribute>
    -->

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
    </attribute>";

    if ($build eq "fsp")
    {
        my $ridHex=sprintf("0xD0%02X",$relativeCentaurRid);
        print "
    <attribute>
        <id>FSP_SCOM_DEVICE_PATH</id>
        <default>$scompath</default>
        <sizeInclNull>$scomsize</sizeInclNull>
    </attribute>
    <attribute>
        <id>FSP_SCAN_DEVICE_PATH</id>
        <default>$scanpath</default>
        <sizeInclNull>$scansize</sizeInclNull>
    </attribute>
    <attribute>
        <id>RID</id>
        <default>$ridHex</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>
    <attribute>
        <id>FSP_VMEM_DEVICE_PATH</id>
        <default>$vmemDevPath</default>
    </attribute>
    <attribute>
        <id>FSP_VMEM_I2C_ADDR</id>
        <default>$vmemAddr</default>
    </attribute>";
    }
    print "\n</targetInstance>\n";

    $uidstr = sprintf("0x%02X0C%04X",${node},$mcs+$proc*8+${node}*8*8);
    print "
<!-- $SYSNAME Centaur MBS affiliated with membuf$ctaur -->

<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}mbs0</id>
    <type>unit-mbs-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur/mbs-0</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur/mbs-0</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

    print "
</targetInstance>
";
}

sub generate_mba
{
    my ($ctaur, $mcs, $mba, $ordinalId) = @_;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $uidstr = sprintf("0x%02X0D%04X",
                          ${node},$mba+$mcs*2+$proc*8*2+${node}*8*8*2);

    print "
<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}mbs0mba$mba</id>
    <type>unit-mba-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur/mbs-0/"
            . "mba-$mba</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/"
            . "membuf-$ctaur/mbs-0/mba-$mba</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$mba</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

    print "
</targetInstance>
";
}

# Since each Centaur has only one dimm, it is assumed to be attached to port 0
# of the MBA0 chiplet.
sub generate_dimm
{
    my ($proc, $mcs, $ctaur, $pos, $dimm, $id, $ordinalId, $relativeDimmRid)
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

    my $dimmHex=sprintf("0xD0%02X",$relativeDimmRid);
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
            . "membuf-$pos/mbs-0/mba-$x/dimm-$zz</default>
    </attribute>
    <attribute>
        <id>MBA_DIMM</id>
        <default>$z</default>
    </attribute>
    <attribute>
        <id>MBA_PORT</id>
        <default>$y</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$vpdRec</default></attribute>";

    if ($build eq "fsp")
    {
         print"
    <attribute>
        <id>RID</id>
        <default>$dimmHex</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$ordinalId</default>
    </attribute>";
    }

print "\n</targetInstance>\n";
}

sub generate_pnor
{
    my ($sys, $node, $pnor, $charPath, $blockPath,$proc,$count) = @_;

# @TODO via RTC: 48523
# Will need to compute the HUID using the workbook info to determine max # parts
# per node
    my $uidstr = sprintf("0x%02X16%04X",${node},$pnor+${node}*2);

# @TODO via RTC: 37573
# Will need to re-evaluate how to compute the PNOR RID value once
# the new system comes out.  Currently the 0x800 RID value is only
# for the TULETA system
    print "
<targetInstance>
    <id>sys${sys}node${node}pnor${pnor}</id>
    <type>chip-pnor-power8</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>POSITION</id>
        <default>$pnor</default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/pnor-$pnor</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/pnor-$pnor</default>
    </attribute>
    <attribute>
        <id>PRIMARY_CAPABILITIES</id>
        <default>
             <field><id>supportsFsiScom</id><value>0</value></field>
             <field><id>supportsXscom</id><value>0</value></field>
             <field><id>supportsInbandScom</id><value>0</value></field>
             <field><id>reserved</id><value>0</value></field>
        </default>
    </attribute>
    <attribute>
        <id>FSP_A_MTD_DEVICE_PATH</id>
        <default>$charPath</default>
    </attribute>
    <attribute>
        <id>FSP_A_MTDBLOCK_DEVICE_PATH</id>
        <default>$blockPath</default>
    </attribute>";

    if($build eq "fsp")
    {
        print "
    <attribute>
        <id>RID</id>
        <default>0x800</default>
    </attribute>
    <attribute>
        <id>ORDINAL_ID</id>
        <default>$count</default>
    </attribute>";
    }

    print "\n</targetInstance>\n";
}

sub addSysAttrs
{
    my $sys = $FapiAttrs->{sys};
    foreach my $Fapikey (sort keys %{$sys->{attribute}})
    {
        my $delimit = "            ";
        my $Key = $Fapikey;
        $Key =~ s/^ATTR_//g;
        print "    <attribute>\n";
        print "        <id>$Key</id>\n";
        print "        <default>\n";
        foreach my $value (@{$sys->{attribute}{$Fapikey}->{value}})
        {
            print "${delimit}$value";
            $delimit = ",";
        }
        print "\n";
        print "        </default>\n";
        print "    </attribute>\n";
    }
}

sub addProcPcieAttrs
{
    my ($position) = @_;
    foreach my $pu (@{$FapiAttrs->{pu}})
    {
        if ( $position == $pu->{position} )
        {
            foreach my $Fapikey (sort keys %{$pu->{attribute}})
            {
                if ($Fapikey =~ /^ATTR_PROC_PCIE/)
                {
                    my $delimit = "            ";
                    my $Key = $Fapikey;
                    $Key =~ s/^ATTR_//g;
                    print "    <attribute>\n";
                    print "        <id>$Key</id>\n";
                    print "        <default>\n";
                    foreach my $iop (@{$pu->{attribute}{$Fapikey}->{iop}})
                    {
                        foreach my $value (@{$iop->{value}})
                        {
                            print "${delimit}$value";
                            $delimit = ",";
                        }
                    }
                    print "\n";
                    print "        </default>\n";
                    print "    </attribute>\n";
                }
            }
        }
    }
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
