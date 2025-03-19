#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/getbuildinfo.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2025
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

use strict;
use warnings;
use Fcntl qw(SEEK_SET);

use bigint qw/hex/;
use Getopt::Long qw(:config no_ignore_case);
use Data::Dumper qw(Dumper);

# globals
my %data;           # store harvested data for processing
my $commit_parm;
my $query_parm;
my $fips_parm;
my $ut_parm;
my $verbosity;
my $GOOD_RC = undef;
my $AFS_ESW = "/afs/rchland/projects/esw";

################################################################################
# getopts
################################################################################
unless (defined($ARGV[0])) {usage(); exit -1;}

GetOptions("help|?"        => sub {usage(); exit -2;},
            "build=s"       => \my $build_parm,
            "release=s"     => \my $release_parm,
            "commit=s"      => \$commit_parm,
            "defect=s"      => \my $defect_parm,
            "jira=s"        => \my $jira_parm,
            "id=s"          => \my $changeid_parm,
            "Hbbuild=s"     => \my $hbbuild_parm,
            "query"         => sub{$query_parm=1;},
            "fips"          => sub{$fips_parm=1;},
            "UT"            => sub{$ut_parm=1;},
            "Testcase=i"    => \my $tc_parm,
            "Verbosity:i"   => sub{$verbosity=$_[1]?$_[1]:1;}
          )
   or print("Error in command line arguments\n") and exit -3;

unless (defined($release_parm) ||
        defined($build_parm)   ||
        (defined($hbbuild_parm) && $release_parm) ||
        defined($ut_parm)) {usage(); exit -4;}

# truncate the input commit to 10 chars
$commit_parm and $commit_parm =~ s/^\s+|\s+$//g;
$commit_parm and $commit_parm = substr $commit_parm,0,10;

#ensure the release value has fw/fips prefix
if ($release_parm && !($release_parm=~/fw/ || $release_parm=~/fips/))
{
    print "ERROR: The release (-r) parm must have a prefix of fw or fips, like fw1110\n";
    exit 0;
}

#dump the input parms if requested
$verbosity and $build_parm    and print "PARM: build($build_parm)\n";
$verbosity and $release_parm  and print "PARM: release($release_parm)\n";
$verbosity and $commit_parm   and print "PARM: commit($commit_parm)\n";
$verbosity and $defect_parm   and print "PARM: commit($defect_parm)\n";
$verbosity and $jira_parm     and print "PARM: commit($jira_parm)\n";
$verbosity and $changeid_parm and print "PARM: commit($changeid_parm)\n";
$verbosity and $hbbuild_parm  and print "PARM: hbbuild($hbbuild_parm)\n";
$verbosity and $query_parm    and print "PARM: query($query_parm)\n";
$verbosity and $fips_parm     and print "PARM: UT($fips_parm)\n";
$verbosity and $ut_parm       and print "PARM: UT($ut_parm)\n";
$verbosity and $tc_parm       and print "PARM: TC($tc_parm)\n";
$verbosity                    and print "PARM: verbosity($verbosity)\n";

################################################################################
# print help
################################################################################
sub usage
{
    print qq(Usage:\n) .
          qq(  -b [build]             List objects in the build\n) .
          qq(  -r [release]           The release to query\n) .
          qq(  -c [commit]            Show the build and objects for a commit sha\n) .
          qq(  -d [defect]            Show the build and objects for a defect\n) .
          qq(  -j [jira]              Show the build and objects for a jira\n) .
          qq(  -i [Change-Id]         Show the build and objects for a change-Id\n) .
          qq(  -H [Hostboot Release]  Show the build and objects for a Hostboot Release\n) .
          qq(  -q                     Query the list of builds for a release\n) .
          qq(     Examples:\n) .
          qq(     > getbuildinfo -b 1110.2509.20250226a\n) .
          qq(     > getbuildinfo -c 21f42b4f47 -r fw1110\n) .
          qq(     > getbuildinfo -d 620212 -r fw1110\n) .
          qq(     > getbuildinfo -j PFHB-676 -r fw1110\n) .
          qq(     > getbuildinfo -i I618d48586b799007df3bbc545331ae1acbe87dec -r fw1110\n) .
          qq(     > getbuildinfo -H hb0301a_2509.1110 -release fw1110\n) .
          qq(     > getbuildinfo -r fw1110 -q\n) .
          qq(\n) .
          qq(     > getbuildinfo -b b0304a2511.1110\n) .
          qq(     > getbuildinfo -j PFHB-812 -r fips1110\n) .
          qq(     > getbuildinfo -d 678088 -r fips1110\n) .
          qq(     > getbuildinfo -j PFHB-676 -r fips1110\n) .
          qq(     > getbuildinfo -i I618d48586b799007df3bbc545331ae1acbe87dec -r fips1110\n) .
          qq(     > getbuildinfo -H hb0301a_2509.1110 -release fips1110\n) .
          qq(     > getbuildinfo -r fips1110 -q\n) .
          qq(\n);
}

################################################################################
# data for unit tests
# each stanza must be separated by a blank line and have STOP at the end
################################################################################
my $UT_data="
getbuildinfo
Usage
RC=255

getbuildinfo -b
requires an argument
RC=253

getbuildinfo -r
requires an argument
RC=253

getbuildinfo -c
requires an argument
RC=253

getbuildinfo -d
requires an argument
RC=253

getbuildinfo -j
requires an argument
RC=253

getbuildinfo -i
requires an argument
RC=253

getbuildinfo -q
Usage
RC=252

getbuildinfo -c opt
Usage
RC=252

getbuildinfo -d opt
Usage
RC=252

getbuildinfo -j opt
Usage
RC=252

getbuildinfo -i opt
Usage
RC=252

getbuildinfo -b 1110.2509.20250226a
green
opp11.2599.20250226o
op-build-4b725f13
hostboot-p11-bd50e20
hostboot-binaries-hw022425a.opmainp11
sbe-p11-55aaf2b
sbe-odyssey-286ea83
RC=0

getbuildinfo -j PFHB-812 -r fw1110
multiple entries for PFHB-812 were found in git
512c3f8a09
21f42b4f47
1db276da21
2ea245672f
1110.2503.20250109a : FOUND 512c3f8a09
green
opp11.2599.20250109n
op-build-3eb7b388
hostboot-p11-3dc4211
hostboot-binaries-hw010825a.opmainp11
sbe-p11-cee6e89
sbe-odyssey-460466c
RC=0

getbuildinfo -d 678088 -r fw1110
1110.2511.20250304a : FOUND 83f679a285
green
opp11.2599.20250304o
op-build-9d97b6d9
hostboot-p11-a92e428
hostboot-binaries-hw022825a.opmainp11
sbe-p11-9f5eb65
sbe-odyssey-286ea83
RC=0

getbuildinfo -i I385f2f498bf5bf6f783d04f1f260423e3685e4de -r fw1110
1110.2511.20250304a : FOUND bb974f3e8d
green
opp11.2599.20250304o
op-build-9d97b6d9
hostboot-p11-a92e428
hostboot-binaries-hw022825a.opmainp11
sbe-p11-9f5eb65
sbe-odyssey-286ea83
RC=0

getbuildinfo -c 21f42b4f47 -r fw1110
1110.2451.20241210a : FOUND 21f42b4f47
green
opp11.2499.20241210o
op-build-466f8c0a
hostboot-p11-f67b456
hostboot-binaries-hw120624a_ody.1110
sbe-p11-cee6e89
sbe-odyssey-27e3f51
RC=0

getbuildinfo -c 2ea245672f -r fw1110
1110.2437.20240911a : FOUND 2ea245672f
green
opp11.2499.20240911n
hostboot-p11-b1bbcb9
hostboot-binaries-hw090924b_ody.1110
sbe-p11-29fd478
sbe-odyssey-33d6aa4
1110.2437.20240911a : REVERTED with 791e059aab
RC=0

getbuildinfo -r fw1110 -q
1110.2517.20250415a hostboot-p11-5a9cc90 opp11.2599.20250415n sbe-p11-fb08498 hostboot-binaries-hw041525a.opmainp11 green 
1110.2517.20250416a hostboot-p11-703ee67 opp11.2599.20250416n sbe-p11-5ac77c4 hostboot-binaries-hw041525a_ody.1110  
1110.2517.20250417a hostboot-p11-703ee67 opp11.2599.20250417n sbe-p11-5ac77c4 hostboot-binaries-hw041625b.opmainp11 
RC=0

getbuildinfo -b 1110.2509.20250219a
ERROR finding 1110.2509.20250219a in fw1110
RC=251

getbuildinfo -c 394949s -r fw1110
394949s is not found in this repo
RC=251

getbuildinfo -d 49822 -r fw1110
49822 not found
RC=251

getbuildinfo -i 2872398745929384 -r fw1110
2872398745929384 not found
RC=251

getbuildinfo -H hb0301a_2509.1110 -release fw1110
1110.2511.20250304a : FOUND 83f679a285
green
opp11.2599.20250304o
op-build-9d97b6d9
hostboot-p11-a92e428
hostboot-binaries-hw022825a.opmainp11
sbe-p11-9f5eb65
sbe-odyssey-286ea83
RC=0

getbuildinfo -b b0304a2511.1110
green
hb0304a_2510.1110
sbe0226a_2509.1110
hwsv2510_0303a.fips1110
RC=0

getbuildinfo -j PFHB-812 -r fips1110
multiple entries for PFHB-812 were found in git
512c3f8a09
21f42b4f47
1db276da21
2ea245672f
b0130a2505.1110 : FOUND 512c3f8a09
green
hb0125a_2504.1110
sbe0128a_2505.1110
hwsv2505_0129a.fips1110
RC=0

getbuildinfo -d 678088 -r fips1110
b0304a2511.1110 : FOUND 83f679a285
green
hb0304a_2510.1110
sbe0226a_2509.1110
hwsv2510_0303a.fips1110
RC=0

getbuildinfo -i I385f2f498bf5bf6f783d04f1f260423e3685e4de -r fips1110
b0304a2511.1110 : FOUND bb974f3e8d
green
hb0304a_2510.1110
sbe0226a_2509.1110
hwsv2510_0303a.fips1110
RC=0

getbuildinfo -c 21f42b4f47 -r fips1110
b1210a2451.1110 : FOUND 21f42b4f47
green
hb1210a_2450.1110
sbe1209a_2450.1110
hwsv2450_1209a.fips1110
RC=0

getbuildinfo -c 2ea245672f -r fips1110
b1202a2449.1110 : FOUND 2ea245672f
green
hb1128a_2448.1110
sbe1121a_2447.1110
hwsv2448_1127a.fips1110
b1202a2449.1110 : REVERTED with 791e059aab
RC=0

getbuildinfo -q -r fips1110
b0304a2511.1110 hb0304a_2510.1110 sbe0226a_2509.1110 green
b0312a2511.1110 hb0306a_2510.1110 sbe0306a_2510.1110 
b0331a2515.1110 hb0328a_2513.1110 sbe0329a_2513.1110 green
b0403a2515.1110 hb0403a_2514.1110 sbe0401a_2514.1110 
RC=0

getbuildinfo -H hb0301a_2509.1110 -release fips1110
b0304a2511.1110 : FOUND 83f679a285
green
hb0304a_2510.1110
sbe0226a_2509.1110
hwsv2510_0303a.fips1110
RC=0

STOP
";

################################################################################
# execute the unit tests using $UT_data
#  each stanza consists of a command and checks
################################################################################
sub exec_UT
{
    my @lines = split((/\n/),$UT_data);
    my @checks=();
    my @fail=();
    my $fail=0;
    my $line;
    my $cmd;
    my $out;
    my $numcmd=0;
    my $numcheck=0;
    my $error;
    my $check_rc;
    my $rc;

    # loop for each line in $UT_data
    while (@lines)
    {
        $line = shift @lines;

        TRACE3((caller(0))[3], __LINE__, "$line");

        $line and $line eq "STOP" and last; # found STOP so bail

        $line =~ /getbuildinfo/ and $cmd=$line and next; # found command

        if ($line ne "")
        {
            $line =~ s/^\s+|\s+$//g;
            push @checks,$line; # save check line
            next;
        }
        @checks or next; # we have found no checks, so process the next line

        ++$numcmd;

        # Now execute the cmd and use the checks to validate the output
        if ($tc_parm && $tc_parm ne $numcmd)
        {
            TRACE((caller(0))[3], __LINE__, "TC$numcmd - SKIP");
            @checks = ();
            next;
        }

        TRACE2((caller(0))[3], __LINE__, "TC$numcmd: $cmd");
        SHOW_STATUS("Running ","TC$numcmd");

        $out = `$cmd 2>&1`; # run test cmd
        $rc  = $?>>8;

        unless ($out)
        {
            # no output so fail
            push @fail,"TC$numcmd: CHECK$numcheck - FAIL";
            next;
        }
        $verbosity==3 and PRINT($out);
        foreach my $check (@checks) # process the checks on the command output
        {
            ++$numcheck;
            TRACE3((caller(0))[3], __LINE__, "CHECK TC$numcmd $numcheck");

            if ($check =~ /RC=/)
            {
                (undef,$check_rc) = split /RC=/,$check;
                if ($rc != $check_rc)
                {
                    push @fail,"TC$numcmd CHECK$numcheck - FAIL ($rc!=$check_rc)";
                    ++$fail;
                    TRACE((caller(0))[3], __LINE__, "TC$numcmd ($cmd) FAIL");
                }
            }
            else
            {
                if ($out !~ /$check/)
                {
                    push @fail,"TC$numcmd CHECK$numcheck - FAIL";
                    ++$fail;
                    TRACE((caller(0))[3], __LINE__, "FAIL: $fail $cmd");
                }
            }
        }
        while (@fail)
        {
            PRINT(shift @fail);
        }
        @checks   = ();
        @fail     = ();
        $numcheck = 0;
    }
    $fail==0 and PRINT("Unit Tests : SUCCESS");
    $fail    and PRINT("Unit Tests : FAILS=$fail");
    $fail>5  and PRINT("           : UT must be run in main-p11");
    exit 0;
}

################################################################################
# print traces based upon verbosity
################################################################################
sub do_trace
{
    my $i_verbosity = shift @_;
    my $i_subname   = shift @_;
    my $i_lineno    = shift @_;
    my $i_txt       = shift @_;

    $verbosity >= $i_verbosity or return;
    $i_txt or $i_txt="";

    my $line = sprintf "%s:%-5d %s", $i_subname,$i_lineno,$i_txt;
    PRINT($line);
}
sub TRACE
{
   unshift(@_,1);
   do_trace(@_);
}
sub TRACE2
{
   unshift(@_,2);
   do_trace(@_);
}
sub TRACE3
{
   unshift(@_,3);
   do_trace(@_);
}

################################################################################
# print status on the same line
# if verbosity, all lines will show
################################################################################
sub SHOW_STATUS
{
    my $i_txt1 = shift @_;
    my $i_txt2 = shift @_;
    my $suffix="\r";

    $i_txt1 or $i_txt1="";
    $i_txt2 or $i_txt2="";

    $verbosity and $suffix="\n";
    print "                                        " .
          "                                      \r";
    print "$i_txt1: $i_txt2$suffix";
}

################################################################################
# print txt using 80 chars to clobber over any previous status msg
################################################################################
sub PRINT
{
    my $i_txt = shift @_;
    my $line;

    $i_txt or  $i_txt="\n";
    $i_txt and $i_txt="$i_txt\n";

    print "                                        " .
          "                                      \r";
    print "$i_txt";
}

################################################################################
# true if i_build is formatted like a fips build (b0207a2507.1110)
################################################################################
sub is_fips
{
    my $i_build = shift @_;

    $i_build or return 0;
    $i_build =~ /^[a-zA-Z0-9]+\.[a-zA-Z0-9]+\.[a-zA-Z0-9]+/ and return 0;
    return 1;
}

################################################################################
# in : build name
# return prefix + release number
################################################################################
sub get_release_from_build
{
    my $i_build = shift @_;
    my $release;

    $i_build or die "ERROR: get_release_from_build input is undefined\n";

    if (is_fips($i_build))
    {
        ($release, undef) = split '\.', $i_build;
        $release = "fips$release";
    }
    else
    {
        (undef, $release) = split '\.', $i_build;
        $release = "fw$release";
    }
    return $release;
}

################################################################################
# in : release name
# return release number
################################################################################
sub get_release_number
{
    my $i_release = shift @_;
    my $release = $i_release;

    TRACE((caller(0))[3], __LINE__, "i_release: $i_release");

    $i_release or die "ERROR: get_release_number input is undefined\n";

    $i_release =~ /fips/ and $release =~ s/fips//;
    $i_release =~ /fw/   and $release =~ s/fw//;
    return $release;
}

################################################################################
# true if pwd is a git repo
################################################################################
sub check_for_git_repo
{
    TRACE((caller(0))[3], __LINE__);

    my $rc;
    # check we are in a git repo
    my $out = `git rev-parse --is-inside-work-tree 2>&1`;
    $out =~ /true/ or $rc = "Not in a git repo";
    return $rc;
}

################################################################################
# query git for a list of the hb releases (hb0704a_2427.1110)
################################################################################
sub get_hb_release_list
{
    SHOW_STATUS((caller(0))[3], $release_parm);

    my $release = get_release_number($release_parm);

    # get the list of all hb release tags
    my $out = `git tag --sort=-creatordate | grep ^hb| grep "$release\$" 2>&1`;
    @{$data{hb_releases}} = split "\n",$out;

    foreach my $hbrel (@{$data{hb_releases}})
    {
        my @lines = split /\n/, `git show --summary $hbrel 2>&1`;
        @lines = grep /commit/, @lines;
        my (undef,$sha) = split /commit /,$lines[0];
        $data{$hbrel}{commit} = substr($sha, 0, 10);
    }
}

################################################################################
# Look in AFS to get the builds for a release
# i_release - parm used to collect builds
#           - contains the prefix on the release, fw1110/fips1110
################################################################################
sub get_published_fw_build_list
{
    my $i_release = shift @_;
    my @builds;

    SHOW_STATUS((caller(0))[3], $i_release);

    if (! -e "$AFS_ESW/$i_release.html")
    {
        TRACE((caller(0))[3], __LINE__, "ERROR: The data file for $build_parm was not found");
        return;
    }

    my @published = split /\n/, `grep published $AFS_ESW/$i_release.html `;

    foreach my $line (@published)
    {
        my ($undef, $part1) = split "/$AFS_ESW/$i_release/Builds/",$line;
        $part1 or next;
        my ($build_parm, undef) = split '/logs/status.html',$part1;
        my (undef, $part2) = split '/logs/status.html"> ',$line;
        $data{$build_parm}{opp} = (split "> ",$part2)[-1];
        ($line =~ /green/) and $data{$build_parm}{color} = "green";
        push @builds, $build_parm;
    }
    @{$data{published}} = @builds;

    $verbosity>=3 and print Dumper @builds;
}

################################################################################
# Look in AFS to get the builds for a release
# i_release - parm used to collect builds
#           - contains the prefix on the release, fw1110/fips1110
################################################################################
sub get_published_fips_build_list
{
    my $i_release = shift @_;
    my @builds;

    SHOW_STATUS((caller(0))[3], $i_release);

    if (! -e "$AFS_ESW/$i_release.html")
    {
        TRACE((caller(0))[3], __LINE__, "ERROR: The data file for $i_release was not found");
        return;
    }

    my @published = split /\n/,
     `egrep "published|postProcDone" $AFS_ESW/$i_release.html | grep $i_release`;

    foreach my $line (@published)
    {
        my @out1 = split " ",$line;
        my @out2 = split "<b>",$out1[2];
        my ($build,undef) = split "</b>",$out2[1];
        $build or next;
        my ($left,$right) = split '\.',$build;
        $right or next;

        ($line =~ /postProcDone/) and $data{$build}{status} = "postProcDone";
        ($line =~ /published/)    and $data{$build}{status} = "published";
        ($line =~ /green/)        and $data{$build}{color}  = "green";
        push @builds, $build;
    }
    @{$data{published}} = @builds;

    $verbosity>=3 and print Dumper %data;
}

################################################################################
# Look in AFS to get the builds for a release
# i_release - parm used to collect builds
#           - contains the prefix on the release, fw1110/fips1110
################################################################################
sub get_published_build_list
{
    my $i_release = shift @_;

    $i_release =~ /fw/   and get_published_fw_build_list($i_release);
    $i_release =~ /fips/ and get_published_fips_build_list($i_release);
}

################################################################################
# Look in AFS to get the objects in a build
# i_build - parm used to collect objects
################################################################################
sub get_objects_in_fw_build
{
    my $i_build = shift @_;
    my ($release_num, undef, $date) = split '\.', $i_build;
    my $fn = "$AFS_ESW/fw$release_num.html";

    SHOW_STATUS((caller(0))[3], $i_build);

    if (! -e $fn)
    {
        TRACE((caller(0))[3], __LINE__, "ERROR: DNE $fn for $i_build");
        return;
    }

    my $out = `grep $release_num $fn | grep $date | grep "\> opp" 2>&1`;
    my @words = split "/",$out;

    @words or TRACE((caller(0))[3], __LINE__, "DNE $i_build data for $release_num in $fn");
    @words or return;

    my @output = grep /$release_num/, @words;
    $data{$i_build}{opp} = (split " ",$out)[-1];

    my $status_html = "$AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html";
    if (! -e $status_html)
    {
        $data{$i_build}{STATUS_HTML_DNE} = $status_html;
        TRACE((caller(0))[3], __LINE__, "DNE: $status_html");
        return;
    }

    $verbosity>=2 and print "$AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html\n";
    $out = `grep "sbe-odyssey" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html 2>&1`;
    $data{$i_build}{sbe_ody} = (split " ",$out)[-1];
    $out = `grep "sbe-" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html | grep -v odyssey 2>&1`;
    $data{$i_build}{sbe} = (split " ",$out)[-1];
    $out = `grep "hostboot-p" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html 2>&1`;
    $data{$i_build}{hostboot} = (split " ",$out)[-1];
    $out = `grep "hostboot-bin" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html 2>&1`;
    $data{$i_build}{hostboot_bin} = (split " ",$out)[-1];
    $out = `grep "op-build-[0-9]" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html 2>&1`;
    $data{$i_build}{opbuild} = (split " ",$out)[-1];
    $out = `grep "Full path to tree" $AFS_ESW/opp$release_num/Builds/$data{$i_build}{opp}/logs/status.html 2>&1`;
    $data{$i_build}{path} = (split ": ",$out)[-1];

    $verbosity>=3 and print Dumper $data{$i_build};
}

################################################################################
# Look in AFS to get the objects in a build
# i_build - parm used to collect objects
################################################################################
sub get_objects_in_fips_build
{
    my $i_build = shift @_;

    SHOW_STATUS((caller(0))[3], $i_build);

    my (undef, $release_num) = split '\.', $i_build;
    my $dir = "$AFS_ESW/fips$release_num/Builds/$i_build/webFiles";
    my @out = split /\n/, `cat $dir/* | egrep "Level|Hostboot version|OCC build level"`;
    @out or return;

    TRACE3((caller(0))[3], __LINE__, "search $dir");

    my @arr = grep /Level: hb/,@out;
    my ($undef,$part1) = split "Level: ",$arr[0];
    my ($obj,undef)  = split "</h1>", $part1;
    $data{$i_build}{hostboot} = $obj;
    @arr = grep /Level: hwsv/,@out;
    ($undef,$part1) = split "Level: ",$arr[0];
    ($obj,undef)  = split "</h1>", $part1;
    $data{$i_build}{hwsv} = $obj;
    @arr = grep /Level: sbe/,@out;
    ($undef,$part1) = split "Level: ",$arr[0];
    ($obj,undef)  = split "</h1>", $part1;
    $data{$i_build}{sbe} = $obj;
    @arr = grep /^Level: hw/,@out;
    ($undef,$obj) = split "Level: ",$arr[0];
    $data{$i_build}{hwimg} = $obj;
    @arr = grep /OCC build level: /,@out;
    ($undef,$part1) = split "level: ",$arr[0];
    ($obj,undef)  = split "</h2>", $part1;
    $data{$i_build}{occ} = $obj;

    $verbosity>=3 and print Dumper $data{$i_build};
}

################################################################################
# Look in AFS to get the objects in a build
# i_build - parm used to collect objects
################################################################################
sub get_objects_in_build
{
    my $i_build = shift @_;

    !is_fips($i_build) and get_objects_in_fw_build($i_build);
     is_fips($i_build) and get_objects_in_fips_build($i_build);
}

################################################################################
# Print the objects in a build from %data
# i_build - parm used to list objects
################################################################################
sub list_objects_in_build
{
    my $i_build = shift @_;
    my $release_num;

    if (!defined($release_parm))
    {
        if (is_fips($i_build))
        {
            (undef,$release_num) = split '\.', $i_build;
            $release_parm = "fips$release_num";
        }
        else
        {
            ($release_num,undef) = split '\.', $i_build;
            $release_parm = "fw$release_num";
        }
    }
    TRACE((caller(0))[3], __LINE__, "$i_build : $release_parm");

    get_published_build_list($release_parm); # get color
    get_objects_in_build($i_build);          # get objects

    (!defined($data{$i_build}{hostboot})) and return "ERROR finding $i_build in $release_parm\n";

    SHOW_STATUS((caller(0))[3], "dump data for $i_build");

    $data{$i_build}{color}        and PRINT("  $data{$i_build}{color}");
    $data{$i_build}{opp}          and PRINT("    $data{$i_build}{opp}");
    $data{$i_build}{opbuild}      and PRINT("    $data{$i_build}{opbuild}");
    $data{$i_build}{hostboot}     and PRINT("    $data{$i_build}{hostboot}");
    $data{$i_build}{hostboot_bin} and PRINT("    $data{$i_build}{hostboot_bin}");
    $data{$i_build}{sbe}          and PRINT("    $data{$i_build}{sbe}");
    $data{$i_build}{sbe_ody}      and PRINT("    $data{$i_build}{sbe_ody}");
    $data{$i_build}{hwsv}         and PRINT("    $data{$i_build}{hwsv}");
    $data{$i_build}{hwimg}        and PRINT("    $data{$i_build}{hwimg}");
    $data{$i_build}{occ}          and PRINT("    $data{$i_build}{occ}");
    $data{$i_build}{path}         and PRINT("    $data{$i_build}{path}");
    PRINT("");

    return $GOOD_RC;
}

################################################################################
# find and print every hb level where the commit exists
################################################################################
sub list_levels_containing_commit
{
    my $rc = check_for_git_repo();
    $rc and return $rc;

    TRACE((caller(0))[3], __LINE__);

    get_published_build_list($release_parm);

    foreach my $pub_build (@{$data{published}})
    {
        get_objects_in_build($pub_build);
    }

    get_hb_release_list();

    SHOW_STATUS((caller(0))[3], "Get commit title for $commit_parm");

    # get the title of the commit
    my $sha = substr($commit_parm, 0, 10);
    my $title = `git show $sha --format="%s" -s 2>&1`;
    ($title =~ /unknown revision/) and return "commit $commit_parm is not found in this repo";
    ($title =~ /fatal/) and $title ="";
    chomp $title;
    $verbosity>=3 and TRACE((caller(0))[3], __LINE__, "TITLE($title)");

    SHOW_STATUS((caller(0))[3], "revert search for $commit_parm");

    # check if this commit has a revert commit
    my $revert;
    my @reverts = split "\n", `git log --grep Revert --pretty=format:"%h%x09%s"`;
    @reverts = grep /\Q$title/, @reverts;
    @reverts and ($revert,undef) = split " ",$reverts[0];
    $revert or $revert = "";
    chomp $revert;

    TRACE((caller(0))[3], __LINE__, "COMMIT:$sha REVERT:$revert");

    my $revert_orig = "";
    if ($revert)
    {
        SHOW_STATUS((caller(0))[3], "Get original commit for revert $revert");
        # query the revert commit to get the original commit
        # This original revert commit must match the commit we are processing in
        #  order for this revert to be valid
        my @gitlog = split "\n", `git show --summary $revert`;
        @gitlog = grep /commit/, @gitlog;
        @gitlog and (undef,$revert_orig) = split "This reverts commit",$gitlog[1];
        $revert_orig or $revert_orig = "";
        $revert_orig =~ s/^\s+|\s+$//g;
        $revert_orig = substr $revert_orig,0,10;
        if ( ($sha eq $revert) ||
             ($sha ne $revert && $sha ne $revert_orig)
           )
        {
            TRACE((caller(0))[3], __LINE__, "not a revert: $sha $revert $revert_orig");
            @reverts = ();
            $revert = "";
        }
    }

    TRACE((caller(0))[3], __LINE__, "COMMIT:$sha REVERT:$revert REVERT_ORIG:" .
                                    "$revert_orig REVERTS_FOUND:" . @reverts);

    # search through hb releases for the commit and get the releases where the
    # commit exists and has not been reverted
    my $commit_found=0;
    my $reverted_found=0;
    my @lines;
    my $print = 0;
    my $out;
    foreach my $pbld (reverse(@{$data{published}}))
    {
        my $build_commit;

        SHOW_STATUS((caller(0))[3], "Find $commit_parm in $pbld");
        $verbosity>=2 and print Dumper $data{$pbld};

        unless ($data{$pbld}{hostboot})
        {
            TRACE3((caller(0))[3], __LINE__, "DNE $pbld {hostboot}");
            $verbosity and print Dumper($data{$pbld});
            next;
        }

        if (is_fips($pbld))
        {
            my $hb_release = $data{$pbld}{hostboot};
            $build_commit  = $data{$hb_release}{commit};
        }
        else
        {
            (undef, undef, $build_commit) = split '\-', $data{$pbld}{hostboot};
        }
        unless ($build_commit)
        {
            TRACE3((caller(0))[3], __LINE__, "CANNOT parse commit from $data{$pbld}{hostboot}");
            next;
        }

        TRACE2((caller(0))[3], __LINE__, "COMMIT($sha) hostboot($data{$pbld}{hostboot})" .
                                         " SEARCH:$build_commit ($data{$pbld}{hostboot})");

        @lines = ();
        $out = `git rev-list $sha ^$build_commit 2>&1 `;
        $out and $out =~ /unknown revision/ and return "commit $commit_parm is not found";
        $out and @lines = split "\n", $out;

        TRACE((caller(0))[3], __LINE__, ,"git rev-list $sha ^$build_commit (@lines)");

        # first time the commit is found, enable printing
        !$print and !@lines and $print=1;

        # check for a revert commit in the release
        if ($revert)
        {
            @reverts = split "\n", `git rev-list $revert ^$build_commit 2>&1 `;
        }

        TRACE2((caller(0))[3], __LINE__, ">> " . @lines . " " . @reverts . " " .
                                                 $commit_found . " " . $reverted_found);

        # print if the commit exists
        if (!@lines && !@reverts && !$commit_found && !$reverted_found)
        {
            PRINT("$pbld : FOUND $commit_parm");
            $commit_found=1;
            list_objects_in_build($pbld);
        }

        # print if the revert commit exists
        if ($revert && !@reverts && !$reverted_found)
        {
            print "$pbld : REVERTED with $revert\n";
            $reverted_found=1;
        }
    }

    if (!$commit_found)
    {
        my $rc = "commit $commit_parm";
        $jira_parm     and $rc .= " for $jira_parm ";
        $defect_parm   and $rc .= " for $defect_parm ";
        $changeid_parm and $rc .= " for $changeid_parm ";
        $rc .= " is not found in a $release_parm build";
        return $rc;
    }
    return $GOOD_RC;
}

################################################################################
# query git to find the commit for the defect
################################################################################
sub get_commit_for_defect
{
    SHOW_STATUS((caller(0))[3], $defect_parm);

    my $rc = check_for_git_repo();
    $rc and return $rc;

    TRACE((caller(0))[3], __LINE__,'git log |egrep "STG" | grep -B 1 $defect_parm');
    my @lines = split /\n/, `git log |egrep "commit|STG" | grep -B 1 $defect_parm`;
    my $line0 = shift @lines;
    my $line1 = shift @lines;
    ($line0 and $line0 =~ /commit/) or return (undef,"$defect_parm not found");
    ($line1 and $line1 =~ /STG/)    or return (undef,"$defect_parm not found");
    my (undef, $commit) = split "commit ",$line0;
    chomp $commit;
    $commit or return (undef,"$defect_parm not found");
    $commit = substr $commit,0,10;
    TRACE((caller(0))[3], __LINE__,"$defect_parm ($commit)");
    @lines>2 and PRINT("multiple entries for $defect_parm were found in git");
    foreach my $entry (@lines)
    {
        my $c;
        if ($entry =~ /commit/)
        {
            (undef, $c) = split "commit ",$entry;
            $c = substr $c,0,10;
            PRINT("  $c");
        }
    }
    return ($commit,$GOOD_RC);
}

################################################################################
# query git to find the commit for the changeid
################################################################################
sub get_commit_for_change_id
{
    SHOW_STATUS((caller(0))[3], $changeid_parm);

    my $rc = check_for_git_repo();
    $rc and return $rc;

    my @lines = split /\n/, `git log |egrep "commit|Change-Id" | grep -B 1 $changeid_parm`;
    my $line0 = shift @lines;
    my $line1 = shift @lines;
    ($line0 and $line0 =~ /commit/)    or return (undef,"$changeid_parm not found");
    ($line1 and $line1 =~ /Change-Id/) or return (undef,"$changeid_parm not found");
    my (undef, $commit) = split "commit ",$line0;
    chomp $commit;
    $commit or return (undef,"$changeid_parm not found");
    $commit = substr $commit,0,10;
    TRACE((caller(0))[3], __LINE__,"$changeid_parm ($commit)");
    @lines>2 and PRINT("multiple entries for $changeid_parm were found in git");
    foreach my $entry (@lines)
    {
        my $c;
        if ($entry =~ /commit/)
        {
            (undef, $c) = split "commit ",$entry;
            $c = substr $c,0,10;
            PRINT("  $c");
        }
    }
    return ($commit,$GOOD_RC);
}

################################################################################
# query git to find the commit for the jira
################################################################################
sub get_commit_for_jira
{
    SHOW_STATUS((caller(0))[3], $jira_parm);

    my $rc = check_for_git_repo();
    $rc and return $rc;

    my @lines = split /\n/, `git log |egrep "^commit|JIRA" | grep -B 1 $jira_parm`;
    my $line0 = shift @lines;
    my $line1 = shift @lines;
    ($line0 and $line0 =~ /commit/) or return (undef,"$jira_parm not found");
    ($line1 and $line1 =~ /JIRA/)   or return (undef,"$jira_parm not found");
    my (undef, $commit) = split "commit ",$line0;
    chomp $commit;
    $commit or return (undef,"$jira_parm not found");
    $commit = substr $commit,0,10;
    TRACE((caller(0))[3], __LINE__,"$jira_parm ($commit)");
    @lines>2 and PRINT("multiple entries for $jira_parm were found in git");
    @lines>2 and PRINT("  $commit");
    foreach my $entry (@lines)
    {
        my $c;
        if ($entry =~ /commit/)
        {
            (undef, $c) = split "commit ",$entry;
            $c = substr $c,0,10;
            PRINT("  $c");
        }
    }
    return ($commit,$GOOD_RC);
}

################################################################################
# query git to find the commit for the hbbuild tag
################################################################################
sub get_commit_for_hbbuild
{
    SHOW_STATUS((caller(0))[3], $hbbuild_parm);

    my $rc = check_for_git_repo();
    $rc and return $rc;

    TRACE((caller(0))[3], __LINE__,"$hbbuild_parm");

    my @lines = split /\n/, `git tag | grep $hbbuild_parm`;
    @lines or return (undef,"The tag $hbbuild_parm was not found");

    TRACE((caller(0))[3], __LINE__,"$hbbuild_parm");

    @lines = split /\n/, `git show $hbbuild_parm | grep ^Base`;
    my $line = shift @lines;
    ($line and $line =~ /Base/) or return (undef,"$hbbuild_parm has no Base comment");

    my (undef, $commit) = split "Base: ",$line;
    chomp $commit;
    $commit or return (undef,"Parse of Base for $hbbuild_parm was empty");

    $commit = substr $commit,0,10;
    @lines>2 and PRINT("multiple entries for $hbbuild_parm were found in git");
    return ($commit,$GOOD_RC);
}

################################################################################
# list builds in a release
################################################################################
sub query
{
    TRACE((caller(0))[3], __LINE__);

    get_published_build_list($release_parm);

    TRACE((caller(0))[3], __LINE__);

    foreach my $pub_build (@{$data{published}})
    {
        TRACE((caller(0))[3], __LINE__, "$pub_build");
        get_objects_in_build($pub_build);
    }

    TRACE((caller(0))[3], __LINE__);

    foreach my $pbld (reverse(@{$data{published}}))
    {
        print "$pbld ";
        $data{$pbld}{hostboot}     and print "$data{$pbld}{hostboot} ";
        $data{$pbld}{opp}          and print "$data{$pbld}{opp} ";
        $data{$pbld}{sbe}          and print "$data{$pbld}{sbe} ";
        $data{$pbld}{hostboot_bin} and printf "%-37s ", $data{$pbld}{hostboot_bin};
        $data{$pbld}{color}        and print "$data{$pbld}{color} ";
        print "\n";
    }
}

################################################################################
# main
################################################################################
TRACE("main", __LINE__);

my $rc = $GOOD_RC;

SHOW_STATUS("main:", "Checking AFS access");
my $out = `ls $AFS_ESW 2>&1`; # check we have access to AFS
$? and PRINT("No AFS access") and exit -1;
$out = `tokens 2>&1`;
$out =~ /rch/ or PRINT("No tokens exist for rchland") and exit -1;

$ut_parm and exec_UT(); # Unit Tests

# find the commit for the input parm and save
$defect_parm   and ($commit_parm,$rc)=get_commit_for_defect();
$changeid_parm and ($commit_parm,$rc)=get_commit_for_change_id();
$jira_parm     and ($commit_parm,$rc)=get_commit_for_jira();
$hbbuild_parm  and ($commit_parm,$rc)=get_commit_for_hbbuild();

# Check for an error fetching the commit_parm
$commit_parm and $rc and print "$rc\n" and exit -1;

# Do the main work
!$build_parm and !$commit_parm and !$defect_parm and $query_parm and query() and exit 0;
$build_parm  and $rc=list_objects_in_build($build_parm);
$commit_parm and $rc=list_levels_containing_commit();

# Check for failure
$rc and PRINT($rc) and exit -5;

exit 0;
