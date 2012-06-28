#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/targeting/xmltohb/genHwsvMrwXml.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
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

open (FH, "<$mrwdir/${sysname}-cec-chips.xml") ||
    die "ERROR: unable to open $mrwdir/${sysname}-cec-chips.xml\n";
close (FH);

my $devpath = XMLin("$mrwdir/${sysname}-cec-chips.xml",
                        KeyAttr=>'instance-path');

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
my @Targets;
foreach my $i (@{$eTargets->{target}}) 
{
    push @Targets, [ $i->{'ecmd-common-name'}, $i->{node}, $i->{position},
                     $i->{'chip-unit'}, $i->{'instance-path'}, $i->{location} ];
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
my @Membuses;
foreach my $i (@{$memBus->{'memory-bus'}}) 
{
    push @Membuses, [
         "n$i->{mcs}->{target}->{node}:p$i->{mcs}->{target}->{position}:mcs" .
         $i->{mcs}->{target}->{chipUnit},
         "n$i->{mba}->{target}->{node}:p$i->{mba}->{target}->{position}:mba" .
         $i->{mba}->{target}->{chipUnit},
         "n$i->{dimm}->{target}->{node}:p$i->{dimm}->{target}->{position}",
         $i->{dimm}->{'instance-path'}, $i->{'fsi-link'} ];
}

# Sort physical DIMM order
my @Memfields;
my @SMembuses;
for my $i ( 0 .. $#Membuses )
{
    for (my $j = 0; $j <= $#Membuses; $j++ )
    {
        my $k = $Membuses[$j][DIMM_PATH_FIELD];
        $k =~ s/.*dimm-(.*).*$/$1/;
        if ($k == $i)
        {
            for my $l ( 0 .. CFSI_LINK_FIELD )
            {
                $Memfields[$l] = $Membuses[$j][$l];
            }
            push @SMembuses, [ @Memfields ];
            $j = $#Membuses;
        }
    }
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

my @fields;
my @STargets;
for my $i ( 0 .. $#Targets )
{
    if ($Targets[$i][NAME_FIELD] eq "pu")
    {
        for my $k ( 0 .. LOC_FIELD )
        {
            $fields[$k] = $Targets[$i][$k];
        }
        push @STargets, [ @fields ];

        my $position = $Targets[$i][POS_FIELD];

        for my $j ( 0 .. $#Targets )
        {
            if (($Targets[$j][NAME_FIELD] eq "ex") &&
                ($Targets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. LOC_FIELD )
                {
                    $fields[$k] = $Targets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }

        for my $j ( 0 .. $#Targets )
        {
            if (($Targets[$j][NAME_FIELD] eq "mcs") &&
                ($Targets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. LOC_FIELD )
                {
                    $fields[$k] = $Targets[$j][$k];
                }
                push @STargets, [ @fields ];
            }
        }
    }
}

for my $i ( 0 .. $#Targets )
{
    if ($Targets[$i][NAME_FIELD] eq "memb")
    {
        for my $k ( 0 .. LOC_FIELD )
        {
            $fields[$k] = $Targets[$i][$k];
        }
        push @STargets, [ @fields ];

        my $position = $Targets[$i][POS_FIELD];

        for my $j ( 0 .. $#Targets )
        {
            if (($Targets[$j][NAME_FIELD] eq "mba") &&
                ($Targets[$j][POS_FIELD] eq $position))
            {
                for my $k ( 0 .. LOC_FIELD )
                {
                    $fields[$k] = $Targets[$j][$k];
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

# Third, generate the proc, ex-chiplet, mcs-chiplet, pervasive-bus, powerbus,
# pcie bus and A/X-bus.
my $ex_count = 0;
my $mcs_count = 0;
for (my $do_core = 0, my $i = 0; $i <= $#STargets; $i++)
{
    if ($STargets[$i][NAME_FIELD] eq "pu")
    {
        my $proc = $STargets[$i][POS_FIELD];
        my $ipath = $STargets[$i][PATH_FIELD];
        if ($proc eq $Mproc)
        {
            generate_master_proc($proc, $ipath);
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
            generate_slave_proc($proc, $fsi, $ipath);
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
            generate_ex($proc, $ex);
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
            generate_ex_core($proc,$ex);
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
        generate_mcs($proc,$mcs);
        $mcs_count++;
        if (($STargets[$i+1][NAME_FIELD] eq "pu") ||
            ($STargets[$i+1][NAME_FIELD] eq "memb"))
        {
            $mcs_count = 0;
            generate_pervasive_bus($proc);
            generate_powerbus($proc);
            generate_pcies($proc);
            generate_ax_buses($proc, "A");
            generate_ax_buses($proc, "X");
        }
    }
}

# Fourth, generate the Centaur, MBS, and MBA

my $memb;
my $membMcs;

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
        generate_centaur( $memb, $membMcs, $cfsi, $ipath );
    }
    elsif ($STargets[$i][NAME_FIELD] eq "mba")
    {
        my $mba = $STargets[$i][UNIT_FIELD];
        generate_mba( $memb, $membMcs, $mba );
        if ($mba == 1)
        {
            print "\n<!-- $SYSNAME Centaur n${node}p${memb} : end -->\n"
        }
    }
}

# Fifth, generate DIMM targets

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
    print "\n<!-- C-DIMM n${node}:p${pos} -->\n";
    for my $id ( 0 .. 7 )
    {
        my $dimmid = $dimm;
        $dimmid <<= 3;
        $dimmid |= $id;
        $dimmid = sprintf ("%d", $dimmid);
        generate_dimm( $proc, $mcs, $ctaur, $pos, $dimmid, $id );
    }
}

print "\n</attributes>\n";

# All done!
#close ($outFH);
exit 0;

##########   Subroutines    ##############

sub generate_sys
{
    my $proc_refclk = $policy->{'required-policy-settings'}->{'processor-refclock-frequency'}->{content};
    my $mem_refclk = $policy->{'required-policy-settings'}->{'memory-refclock-frequency'}->{content};

    print "
<!-- $SYSNAME System -->

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
        <id>PROC_EPS_TABLE_TYPE</id>
        <default>EPS_TYPE_LE</default>
    </attribute>
    <attribute>
        <id>PROC_FABRIC_PUMP_MODE</id>
        <default>MODE1</default>
    </attribute>
    <attribute>
        <id>PROC_X_BUS_WIDTH</id>
        <default>W8BYTE</default>
    </attribute>
    <attribute>
        <id>ALL_MCS_IN_INTERLEAVING_GROUP</id>
        <default>1</default>
    </attribute>
    <attribute>
        <id>FREQ_PROC_REFCLOCK</id>
        <default>$proc_refclk</default>
    </attribute>
    <attribute>
        <id>FREQ_MEM_REFCLOCK</id>
        <default>$mem_refclk</default>
    </attribute>
    <attribute>
        <id>FREQ_CORE_FLOOR</id>
        <default>2500</default>
    </attribute>
    <attribute>
        <id>SP_FUNCTIONS</id>
        <default>
            <field><id>fsiSlaveInit</id><value>1</value></field>
            <field><id>mailboxEnabled</id><value>1</value></field>
            <field><id>reserved</id><value>0</value></field>
        </default>
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
        <id>MSS_CACHE_ENABLE</id>
        <default>1</default>
    </attribute>
    <attribute>
        <id>MSS_PREFETCH_ENABLE</id>
        <default>1</default>
    </attribute>
    <attribute>
        <id>MSS_CLEANER_ENABLE</id>
        <default>1</default>
    </attribute>
</targetInstance>
";
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
    </attribute>
</targetInstance>
";
}

sub generate_master_proc
{
    my ($proc, $ipath) = @_;
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
    my $uidstr = sprintf("0x%02X07%04X",${node},${proc}+${node}*8);
    print "
<!-- $SYSNAME n${node}p${proc} processor chip -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}</id>
    <type>chip-processor-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>${proc}</default></attribute>
    <attribute><id>SCOM_SWITCHES</id>
        <default>
            <field><id>useFsiScom</id><value>0</value></field>
            <field><id>useXscom</id><value>1</value></field>
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
        <default>$node</default>
    </attribute>
    <attribute>
        <id>FABRIC_CHIP_ID</id>
        <default>$proc</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$proc</default></attribute>";

    if ($build eq "fsp")
    {
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
    print "\n</targetInstance>\n";
}

sub generate_slave_proc
{
    my ($proc, $fsi, $ipath) = @_;
    my $uidstr = sprintf("0x%02X07%04X",${node},$proc+${node}*8);
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
<!-- $SYSNAME n${node}p$proc processor chip -->

<targetInstance>
    <id>sys${sys}node${node}proc$proc</id>
    <type>chip-processor-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute><id>POSITION</id><default>$proc</default></attribute>
    <attribute><id>SCOM_SWITCHES</id>
        <default>
            <field><id>useFsiScom</id><value>1</value></field>
            <field><id>useXscom</id><value>0</value></field>
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
        <default>$node</default>
    </attribute>
    <attribute>
        <id>FABRIC_CHIP_ID</id>
        <default>$proc</default>
    </attribute>
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
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$proc</default></attribute>";

    if ($build eq "fsp")
    {
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
    print "\n</targetInstance>\n";
}

sub generate_ex
{
    my ($proc, $ex) = @_;
    my $uidstr = sprintf("0x%02X0A%04X",${node},$ex+$proc*16+${node}*8*16);
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
    </attribute>
</targetInstance>
";
}

sub generate_ex_core
{
    my ($proc, $ex) = @_;
    my $uidstr = sprintf("0x%02X0B%04X",${node},$ex+$proc*16+${node}*8*16);
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
    </attribute>
</targetInstance>
";
}

sub generate_mcs
{
    my ($proc, $mcs) = @_;
    my $uidstr = sprintf("0x%02X0F%04X",${node},$mcs+$proc*8+${node}*8*8);
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
</targetInstance>
";
}

sub generate_pervasive_bus
{
    my $proc = shift;
    my $uidstr = sprintf("0x%02X13%04X",${node},$proc+${node}*8);
    print "
<!-- $SYSNAME n${node}p$proc pervasive unit -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}pervasive0</id>
    <type>unit-pervasive-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/pervasive-0</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/pervasive-0</default>
    </attribute>
</targetInstance>
";
}

sub generate_powerbus
{
    my $proc = shift;
    my $uidstr = sprintf("0x%02X14%04X",${node},$proc+${node}*8);
    print "
<!-- $SYSNAME n${node}p$proc powerbus unit -->

<targetInstance>
    <id>sys${sys}node${node}proc${proc}powerbus0</id>
    <type>unit-powerbus-murano</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/proc-$proc/powerbus-0</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/powerbus-0</default>
    </attribute>
</targetInstance>
";
}

sub generate_pcies
{
    my $proc = shift;
    my $proc_name = "n${node}:p${proc}";
    print "\n<!-- $SYSNAME n${node}p${proc} PCI units -->\n";
    for my $i ( 0 .. 2 )
    {
        generate_a_pcie( $proc, $i );
    }
}

sub generate_a_pcie
{
    my ($proc, $phb) = @_;
    my $uidstr = sprintf("0x%02X17%04X",${node},$phb+$proc*3+${node}*8*3);
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
    </attribute>
</targetInstance>
";
}

sub generate_ax_buses
{
    my ($proc, $type) = @_;

    my $proc_name = "n${node}p${proc}";
    print "\n<!-- $SYSNAME $proc_name ${type}BUS units -->\n";
    my $maxbus = ($type eq "A") ? 2 : 3;
    my $typenum = ($type eq "A") ? 0x16 : 0x15;
    $type = lc( $type );
    for my $i ( 0 .. $maxbus )
    {
	my $uidstr = sprintf( "0x%02X%02X%04X",
			     ${node},
			       $typenum,
			       $i+$proc*($maxbus+1)+${node}*8*($maxbus+1));
        my $peer = 0;
        my $p_proc = 0;
        my $p_port = 0;
        foreach my $j ( @pbus )
        {
            if ($j->[0] eq "n${node}:p${proc}:${type}${i}")
            {
                #$peer = 1;
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
        <id>PEER_TARGET<id>
        <default>affinity:sys-$sys/node-$node/proc-$p_proc/${type}bus-$p_port</default>
    </attribute>";
        }
        print "\n</targetInstance>\n";
    }
}

sub generate_centaur
{
    my ($ctaur, $mcs, $cfsi, $ipath) = @_;
    my $scompath = $devpath->{chip}->{$ipath}->{'scom-path'};
    my $scanpath = $devpath->{chip}->{$ipath}->{'scan-path'};
    my $scomsize = length($scompath) + 1;
    my $scansize = length($scanpath) + 1;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    my $uidstr = sprintf("0x%02X06%04X",${node},$mcs+$proc*8+${node}*8*8);

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
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/membuf-$ctaur</default>
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
    </attribute>";
    }
    print "\n</targetInstance>\n";

    $uidstr = sprintf("0x%02X10%04X",${node},$mcs+$proc*8+${node}*8*8);
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
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/membuf-$ctaur/mbs-0</default>
    </attribute>
</targetInstance>
";
}

sub generate_mba
{
    my ($ctaur, $mcs, $mba) = @_;
    my $proc = $mcs;
    $proc =~ s/.*:p(.*):.*/$1/g;
    $mcs =~ s/.*:.*:mcs(.*)/$1/g;

    if ($mba == 0)
    {
        print "\n<!-- $SYSNAME Centaur MBAs affiliated with membuf$ctaur -->\n";
    }

    my $uidstr = sprintf("0x%02X11%04X",${node},$mba+$mcs*2+$proc*8*2+${node}*8*8*2);

    print "
<targetInstance>
    <id>sys${sys}node${node}membuf${ctaur}mbs0mba$mba</id>
    <type>unit-mba-centaur</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/membuf-$ctaur/mbs-0/mba-$mba</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/membuf-$ctaur/mbs-0/mba-$mba</default>
    </attribute>
    <attribute>
        <id>CHIP_UNIT</id>
        <default>$mba</default>
    </attribute>
</targetInstance>
";
}

# Since each Centaur has only one dimm, it is assumed to be attached to port 0
# of the MBA0 chiplet.
sub generate_dimm
{
    my ($proc, $mcs, $ctaur, $pos, $dimm, $id) = @_;

    my $x = $id;
    $x = int ($x / 4);
    my $y = $id;
    $y = int(($y - 4 * $x) / 2);
    my $z = $id;
    $z = $z % 2;
    #$x = sprintf ("%d", $x);
    #$y = sprintf ("%d", $y);
    #$z = sprintf ("%d", $z);
    my $uidstr = sprintf("0x%02X03%04X",${node},$dimm+${node}*512);

    # Calculate the VPD Record number value
    my $vpdRec = 0;

    # Set offsets based on mba, mem_port, and dimm values
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

    # Adjust offset based on MCS value
    $vpdRec = ($mcs * 8) + $vpdRec;
    # Adjust offset basedon processor value
    $vpdRec = ($proc * 64) + $vpdRec;

    print "
<targetInstance>
    <id>sys${sys}node${node}dimm$dimm</id>
    <type>lcard-dimm-cdimm</type>
    <attribute><id>HUID</id><default>${uidstr}</default></attribute>
    <attribute>
        <id>POSITION</id>
        <default>$dimm</default>
    </attribute>
    <attribute>
        <id>PHYS_PATH</id>
        <default>physical:sys-$sys/node-$node/dimm-$dimm</default>
    </attribute>
    <attribute>
        <id>AFFINITY_PATH</id>
        <default>affinity:sys-$sys/node-$node/proc-$proc/mcs-$mcs/membuf-$pos/mbs-0/mba-$x/mem_port-$y/dimm-$z</default>
    </attribute>
    <attribute>
        <id>MBA_PORT</id>
        <default>$y</default>
    </attribute>
    <attribute>
        <id>MBA_DIMM</id>
        <default>$z</default>
    </attribute>
    <attribute><id>VPD_REC_NUM</id><default>$vpdRec</default></attribute>
</targetInstance>
";
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
