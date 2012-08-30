#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/tools/hwp_id.pl $
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

use strict;
use File::Find ();
use File::Path;

# Variables
my $DIR = ".";
my $DEBUG = 0;
my @outputFnVn;

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
    "src/usr/hwpf/hwp",
    "src/usr/pore/poreve/model",
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
        if ( $DIR = shift )
        {
            print("Using directory: $DIR\n");
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


# make sure we're in the correct place
chdir "$DIR";

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
        $imageId = `git describe --dirty || echo Unknown-Image \`git rev-parse --short HEAD\``;
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

# do the work - for each directory, check the files...
foreach( @dirList )
{
    if ($SHOW_INFO & SHOW_HTML)
    {
        print("<h2>HWP files in $_</h2>\n");
    }
    else
    {
        print("[HWP files in $_]\n");
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

    @outputFnVn = ();
    checkFiles( $_ );
    foreach( sort(@outputFnVn) )
    {
        print( "$_\n" );
    }

    if ($SHOW_INFO & SHOW_HTML)
    {
        print "</table>\n";
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
# checkFiles - find *.[hHcC] and *.initfile files that are hwp files
# and prints out their filename and version from the $Id: string.
# This recursively searches the input directory passed in for all files.
#
################################################################################

sub checkFiles
{
    my ($l_input_dir) = @_;

    debugMsg( "Getting Files for dir: $l_input_dir" );

    # Open the directory and read all entry names.
    local *DH;
    opendir(DH, $l_input_dir) or die("Cannot open $l_input_dir: $!");
    # skip the dots
    my @dir_entry;
    @dir_entry = grep { !/^\./ } readdir(DH);
    closedir(DH);
    while (@dir_entry)
    {
        my $l_entry = shift(@dir_entry);
        my $full_path = "$l_input_dir/$l_entry";

        debugMsg( "checkFiles: Full Path: $full_path" );

        # if this is valid file:
        if (($l_entry =~ /\.[H|h|C|c]$/) ||
            ($l_entry =~ /\.initfile$/))
        {
            local *FH;
            open(FH, "$full_path") or die("Cannot open: $full_path: $!");
            my $data;
            read(FH, $data, -s FH) or die("Error reading $full_path: $!");
            close FH;

            # look for special string to skip file
            if ($data =~ /HWP_IGNORE_VERSION_CHECK/ )
            {
                debugMsg( "checkFiles: found HWP_IGNORE_VERSION_CHECK in: $full_path" );
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
                if ($SHOW_INFO & SHOW_FULLPATH)
                {
                    $display_name = $full_path;
                }
                else
                {
                    $display_name = $fn;
                }
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

                # sanity check that fn is how it's in hb
                if ($fn ne $l_entry)
                {
                    print( "  note!! File: $fn in hostboot as: $full_path\n" );
                }

            }
            else
            {
                debugMsg( "checkFiles: MISSING \$Id tag: $full_path" );
                if ($SHOW_INFO & SHOW_MISSING)
                {
                    if ($SHOW_INFO & SHOW_VERSION)
                    {
                        print( "File: $full_path  Version: \$Id is MISSING\n" );
                    }
                    elsif ($SHOW_INFO & SHOW_SHORT)
                    {
                        print( "$full_path,MISSING\n" );
                    }
                    elsif ($SHOW_INFO & SHOW_HTML)
                    {
                        print( "<tr><td>$full_path</td><td>\$Id is MISSING</td></tr>\n" );
                    }
                }
                elsif ($SHOW_INFO & SHOW_ONLYMISS)
                {
                    print( "File: $full_path  Version: \$Id is MISSING\n" );
                }
            }
        }
        # else if this is a directory
        elsif (-d $full_path)
        {
            # recursive here
            checkFiles($full_path);
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
    print "Usage: $0 <option>\n";
    print "\n";
    print "Default - show name and version for hwp files with \$Id string.\n";
    print "-D dir  Use dir as top of build.\n";
    print "-d      Enable Debug messages.\n";
    print "-f      Show full hostboot pathname of all files.\n";
    print "-h      Display usage message.\n";
    print "-I lvl  Show hostboot ImageId value as supplied lvl\n";
    print "-i      Show hostboot ImageId value.\n";
    print "-m      Include files that are missing Id strings.\n";
    print "\n";
    print " output is in one of 4 formats:\n";
    print "-l      Output in html table.\n";
    print "-s      Show short \"filename,version\" format.\n";
    print "-v      Show longer \"File: f Version: v\" format. (default)\n";
    print "-M      Only show files that are missing Id strings.\n";
    print "\n";
    exit 1;
}
