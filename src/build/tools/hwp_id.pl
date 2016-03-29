#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/hwp_id.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
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
use File::Find ();
use File::Path;
use Cwd;

# Variables
my $DEBUG = 0;
my @outputFnVn;
my @foundFn;
my $baseDir = ".";
my $basePath;
my @searchFiles;
my @searchDirs;

my $SHOW_INFO = 0;
# a bit for each:
use constant SHOW_IMAGEID    => 0x01;
use constant SHOW_MISSING    => 0x02;
use constant SHOW_VERSION    => 0x04;
use constant SHOW_SHORT      => 0x08;
use constant SHOW_FULLPATH   => 0x10;
use constant SHOW_HTML       => 0x20;
use constant SHOW_ONLYMISS   => 0x40;

# directories that we'll check for files:
my @dirList = (
    "src/usr/hwpf",                 # hostboot
    "src/include/usr/hwpf",         # hostboot
    "src/usr/pore",                 # hostboot
    "src/hwsv/server/hwpf/hwp",     # fsp, should be full tree
    "src/base.pgm/HostServices/hwpf/hwp",       # hostservices
    "src/base.pgm/HostServices/hwpf/shared_hwp",# hostservices
    "src/base.pgm/Hypervisor/Slw",              # hostservices
    ) ;

# set defaults
my $imageId = "";
$SHOW_INFO = SHOW_VERSION;

while( $ARGV = shift )
{
    if( $ARGV =~ m/-h/ )
    {
        usage();
    }
    elsif( $ARGV =~ m/-D/ )
    {
        if ( $baseDir = shift )
        {
            print("Using directory(s): $baseDir\n");
        }
        else
        {
            usage();
        }
    }
    elsif( $ARGV =~ m/-d/ )
    {
        $DEBUG = 1;
    }
    elsif( $ARGV =~ m/-f/ )
    {
        $SHOW_INFO |= SHOW_FULLPATH;
    }
    elsif( $ARGV =~ m/-F/ )
    {
        # no directory, list of files
        $baseDir = "";
        @searchFiles = @ARGV;
        last; # done with options
    }
    elsif( $ARGV =~ m/-I/ )
    {
        $SHOW_INFO |= SHOW_IMAGEID;
        if ( $imageId = shift )
        {
            debugMsg("using supplied Hostboot version: $imageId\n");
        }
        else
        {
            usage();
        }
    }
    elsif( $ARGV =~ m/-i/ )
    {
        $SHOW_INFO |= SHOW_IMAGEID;
    }
    elsif( $ARGV =~ m/-l/ )
    {
        $SHOW_INFO |= SHOW_HTML;
        $SHOW_INFO &= ~SHOW_VERSION;
        $SHOW_INFO &= ~SHOW_SHORT;
    }
    elsif( $ARGV =~ m/-M/ )
    {
        $SHOW_INFO |= SHOW_ONLYMISS;
    }
    elsif( $ARGV =~ m/-m/ )
    {
        $SHOW_INFO |= SHOW_MISSING;
    }
    elsif( $ARGV =~ m/-s/ )
    {
        $SHOW_INFO |= SHOW_SHORT;
        $SHOW_INFO &= ~SHOW_VERSION;
        $SHOW_INFO &= ~SHOW_HTML;
    }
    elsif( $ARGV =~ m/-v/ )
    {
        $SHOW_INFO |= SHOW_VERSION;
        $SHOW_INFO &= ~SHOW_SHORT;
        $SHOW_INFO &= ~SHOW_HTML;
    }
    else
    {
        usage();
    }
}

if ($SHOW_INFO & SHOW_ONLYMISS)
{
    $SHOW_INFO &= ~SHOW_VERSION;
    $SHOW_INFO &= ~SHOW_SHORT;
    $SHOW_INFO &= ~SHOW_HTML;
}

# generate starting html if needed
if ($SHOW_INFO & SHOW_HTML)
{
    print "<html>\n";
    print "    <head><title>HWP names and version IDs</title></head>\n";
    print <<STYLESHEET;
    <style type="text/css">
        table.hwp_id {
            border-width: 1px;
            border-spacing: 2px;
            border-style: outset;
            border-color: gray;
            border-collapse: separate;
            background-color: white;
        }
        table.hwp_id th {
            border-width: 1px;
            padding: 1px;
            border-style: inset;
            border-color: gray;
            background-color: white;
        }
        table.hwp_id td {
            border-width: 1px;
            padding: 1px;
            border-style: inset;
            border-color: gray;
            background-color: white;
        }
    </style>
STYLESHEET
    print "    <body>\n";
}

# determine what the hbi_ImageId would be, if we were asked to display that
if ($SHOW_INFO & SHOW_IMAGEID)
{
    if ($imageId eq "")
    {
        # copied from src/build/tools/addimgid:
        $imageId = `cd $baseDir; git describe --dirty || echo Unknown-Image \`git rev-parse --short HEAD\``;
        chomp $imageId;
        if (($imageId =~ m/Unknown-Image/) ||   # Couldn't find git describe tag.
            ($imageId =~ m/dirty/) ||           # Find 'dirty' commit.
            ($imageId =~ m/^.{15}-[1-9]+/))     # Found commits after a tag.
        {
            $imageId = $imageId."/".$ENV{"USER"};
        }
    }
    if ($SHOW_INFO & SHOW_HTML)
    {
        print "<h1>Hostboot version: $imageId</h1>\n";
    }
    else
    {
        print("Hostboot version: $imageId\n");
    }
}

# if baseDir - recurse into directories
if ($baseDir)
{
    # there may be multiple base directories
    @searchDirs = split(/:/, $baseDir);

    foreach( @searchDirs )
    {
        # make sure we're in the correct place
        chdir "$_";
        $basePath = $_;

        # do the work - for each directory, check the files...
        foreach( @dirList )
        {
            @outputFnVn = ();
            checkDirs( $_ );

            if (scalar(@outputFnVn) > 0)
            {
                outputFileInfo($_, @outputFnVn);
            }
        }
    }
}
else # list of files
{
    @outputFnVn = ();

    # do the work - for each file, check it
    foreach( @searchFiles )
    {
        findIdVersion( $_ );
    }

    if (scalar(@outputFnVn) > 0)
    {
        my $pwd = getcwd();
        outputFileInfo($pwd, @outputFnVn);
    }
}

# generate closing html if needed
if ($SHOW_INFO & SHOW_HTML)
{
    print "    </body>\n";
    print "</html>\n";
}

#=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#  End of Main program
#=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

################################################################################
#
# Print debug messages if $DEBUG is enabled.
#
################################################################################

sub debugMsg
{
    my ($msg) = @_;
    if( $DEBUG )
    {
        print "DEBUG: $msg\n";
    }
}

################################################################################
#
# outputFileInfo - Print output, as options dictate
#
################################################################################

sub outputFileInfo
{
    my $dir = shift;

    if ($SHOW_INFO & SHOW_HTML)
    {
        print("<h2>HWP files in $basePath/$dir</h2>\n");
    }
    else
    {
        print("[HWP files in $dir]\n");
    }

    if ($SHOW_INFO & SHOW_SHORT)
    {
        print("[Procedure,Revision]\n" );
    }

    if ($SHOW_INFO & SHOW_HTML)
    {
        print "<table class='hwp_id'>\n";
        print "    <tr>\n";
        print "        <th>Filename</th>\n";
        print "        <th>Version</th>\n";
        print "    </tr>\n";
    }

    foreach( sort(@_) )
    {
        print( "$_\n" );
    }

    if ($SHOW_INFO & SHOW_HTML)
    {
        print "</table>\n";
    }
}

################################################################################
#
# findIdVersion - prints out filename and version from the $Id: string.
#
################################################################################

sub findIdVersion
{
    my ($l_file) = @_;
    debugMsg( "finding Id & Version from file: $l_file" );

    local *FH;
    open(FH, "$l_file") or die("Cannot open: $l_file: $!");
    my $data;
    read(FH, $data, -s FH) or die("Error reading $l_file: $!");
    close FH;

    # look for special string to skip file
    if ($data =~ /HWP_IGNORE_VERSION_CHECK/ )
    {
        debugMsg( "findIdVersion: found HWP_IGNORE_VERSION_CHECK in: $l_file" );
        next;
    }

    # look for
    # $Id: - means this IS an hwp - print version and continue
    # else - missing!
    if ($data =~ /\$Id: (.*),v ([0-9.]*) .* \$/mgo )
    {
        my $fn = $1; # filename
        my $vn = $2; # version
        my $display_name;
        my $redundant = 0;
        if ($SHOW_INFO & SHOW_FULLPATH)
        {
            $display_name = $l_file;
        }
        else
        {
            $display_name = $fn;
        }
        $redundant = grep { m/^$fn$/ } @foundFn;
        if ( !$redundant )
        {
            push( @foundFn, $display_name );
            debugMsg( "File: $display_name  Version: $vn" );
            if ($SHOW_INFO & SHOW_VERSION)
            {
                push( @outputFnVn, "File: $display_name  Version: $vn" );
            }
            elsif ($SHOW_INFO & SHOW_SHORT)
            {
                push( @outputFnVn, "$display_name,$vn" );
            }
            elsif ($SHOW_INFO & SHOW_HTML)
            {
                push( @outputFnVn, "<tr><td>$display_name</td><td>$vn</td></tr>" );
            }
        }
    }
    else
    {
        debugMsg( "findIdVersion: MISSING \$Id tag: $l_file" );
        if ($SHOW_INFO & SHOW_MISSING)
        {
            if ($SHOW_INFO & SHOW_VERSION)
            {
                print( "File: $l_file  Version: \$Id is MISSING\n" );
            }
            elsif ($SHOW_INFO & SHOW_SHORT)
            {
                print( "$l_file,MISSING\n" );
            }
            elsif ($SHOW_INFO & SHOW_HTML)
            {
                print( "<tr><td>$l_file</td><td>\$Id is MISSING</td></tr>\n" );
            }
        }
        elsif ($SHOW_INFO & SHOW_ONLYMISS)
        {
            print( "File: $l_file  Version: \$Id is MISSING\n" );
        }
    }
}

################################################################################
#
# checkDirs - find hwp files that should contain $Id:
#  filetypes .C .c .H .h .xml .define .initfile .attributes .pl
# and prints out their filename and version from the $Id: string.
# This recursively searches the input directory passed in for all files.
#
################################################################################

sub checkDirs
{
    my ($l_input_dir) = @_;

    debugMsg( "Getting Files for dir: $l_input_dir" );

    # Open the directory and read all entry names.

    local *DH;
    opendir(DH, $l_input_dir) ;#or die("Cannot open $l_input_dir: $!");
    # skip the dots
    my @dir_entry;
    @dir_entry = grep { !/^\./ } readdir(DH);
    closedir(DH);
    while (@dir_entry)
    {
        my $l_entry = shift(@dir_entry);
        my $full_path = "$l_input_dir/$l_entry";

        debugMsg( "checkDirs: Full Path: $full_path" );

        # if this is valid file:
        if (($l_entry =~ /\.[H|h|C|c]$/) ||
            ($l_entry =~ /\.xml$/) ||
            ($l_entry =~ /\.define$/) ||
            ($l_entry =~ /\.attributes$/) ||
            ($l_entry =~ /\.initfile$/) ||
            ($l_entry =~ /\.pl$/))
        {
            findIdVersion($full_path);
        }
        # else if this is a directory
        elsif (-d $full_path)
        {
            # recursive here
            checkDirs($full_path);
        }
        # else we ignore the file.
    }
}

################################################################################
#
# Print the Usage message
#
################################################################################

sub usage
{
    print "Usage: $0 <option> [-F <files>]\n";
    print "\n";
    print "Default - show name and version for hwp files with \$Id string.\n";
    print "-D dirs   Use dir as top of build, may be ':' separated list.\n";
    print "-d        Enable Debug messages.\n";
    print "-f        Show full pathname of all files.\n";
    print "-F files  Search listed full-path files. Must be last parameter.\n";
    print "-h        Display usage message.\n";
    print "-I lvl    Show hostboot ImageId value as supplied lvl\n";
    print "-i        Show hostboot ImageId value.\n";
    print "-m        Include files that are missing Id strings.\n";
    print "\n";
    print " output is in one of 4 formats:\n";
    print "-l        Output in html table.\n";
    print "-s        Show short \"filename,version\" format.\n";
    print "-v        Show longer \"File: f Version: v\" format. (default)\n";
    print "-M        Only show files that are missing Id strings.\n";
    print "\n";
    exit 1;
}
