#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/runtime/common/create_hsvc_data.pl $
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

# This script will parse a set of attribute xml files and HWP
#  source files in order to discover the list of required
#  attributes to push up to the Host Services code from Hostboot.
# The ouput is a set of 3 data files that are used by the code
#  that populates mainstore.
#
# Note that this implementation is currently incomplete, it will
#  be finished as part of RTC:50411

use strict;

my $debug = 0;
my $warning = 0;
my @input_files;

for (my $i=0; $i < $#ARGV + 1; $i++)
{
    if ($ARGV[$i] =~ /-h/)
    {
        print_usage();
        exit;
    }
    elsif ($ARGV[$i] =~ /-d/)
    {
        $debug = 1;
        print "Debug Mode\n";
    }
    elsif ($ARGV[$i] =~ /-w/)
    {
        $warning = 1;
        print "Warnings enabled\n";
    }
    else
    {
        # must be the input filename
        push @input_files, $ARGV[$i];
    }
}

my $date = chopit(`date`);
my $user = chopit(`whoami`);

## Open up all of the output files 
if( -e "hsvc_sysdata.C" ) {
    die("hsvc_sysdata.C file already exists\n");
}
open SYS_FILE, ">hsvc_sysdata.C", or die("Could not create hsvc_sysdata.C\n");
print SYS_FILE "// Generated on $date by $user from \n";

if( -e "hsvc_procdata.C" ) {
    die("hsvc_procdata.C file already exists\n");
}
open PROC_FILE, ">hsvc_procdata.C", or die("Could not create hsvc_procdata.C\n");
print PROC_FILE "// Generated on $date by $user from \n";

if( -e "hsvc_exdata.C" ) {
    die("hsvc_exdata.C file already exists\n");
}
open EX_FILE, ">hsvc_exdata.C", or die("Could not create hsvc_exdata.C\n");
print EX_FILE "// Generated on $date by $user from \n";

# Keep a list for each type of attribute ever to find dupes
my @sys_all;
my @proc_all;;
my @ex_all;

## Loop through all of the XML input files
foreach my $ifile (@input_files)
{
    # Skip any non-XML files in this loop
    if( !($ifile =~ /xml/) )
    {
        next;
    }

    # Open the file
    print "Processing: $ifile\n";
    open IN_FILE, $ifile or die("Cannot open $ifile\n");

    # Keep a list for each type of attribute in this file
    my @sys;
    my @proc;
    my @ex;

    # Loop through the files and print out each line based on timestamp
    my $linenum = 0;
    my $id = "";
    my $target = "";
    while(my $curline = <IN_FILE>)
    {
        $linenum++;
        if( $curline =~ /<attribute>/ )
        {

        }
        elsif( $curline =~ /<id>/ )
        {
            #    <id>ATTR_PM_POWER_PROXY_TRACE_TIMER</id>
            my @divide = split( /[<>]/, $curline );
            #print "xx:$divide[0],$divide[1],$divide[2],$divide[3]:xx\n";
            $id = $divide[2];
            if($debug){print "id=$id.\n";}
        }
        elsif( $curline =~ /<targetType>/ )
        {
            #     <targetType>TARGET_TYPE_PROC_CHIP</targetType>
            my @divide = split( /[<>]/, $curline );
            #print "xx:$divide[0],$divide[1],$divide[2],$divide[3]:xx\n";
            $target = $divide[2];
            if($debug){print "target=$target.\n";}
        }
        elsif( $curline =~ /<\/attribute>/ )
        {
            # MVPD attributes are read live by HostServices code
            if( $id =~ /MVPD/ )
            {
                if($debug){print "Skipping MVPD: %id\n";}
            }
            elsif( $target =~ /TARGET_TYPE_PROC_CHIP/ )
            {
                if($debug){print "PROC_CHIP: $id.\n";}
                if( check_for_dupe($id,\@proc_all) )
                {
                    if( $warning ) {
                        print "Duplicate attribute found for PROC '$id' in $ifile\n";
                    }
                }
                else
                {
                    push @proc, $id;
                    push @proc_all, $id;
                }
            }
            elsif( $target =~ /TARGET_TYPE_SYSTEM/ )
            {
                if($debug){print "SYSTEM: $id.\n";}
                push @sys, $id;
                push @sys_all, $id;
            }
            elsif( $target =~ /TARGET_TYPE_EX_CHIPLET/ )
            {
                if($debug){print "EX_CHIPLET: $id.\n";}
                push @ex, $id;
                push @ex_all, $id;
            }
            else
            {
                die("UNKNOWN targetType : $target\n");
            }
        }

    }

    close IN_FILE;

    # Now print out the 3 files

    # sysdata
    print SYS_FILE "// -- Input: $ifile --\n";
    if( $#sys > 0 )
    {
        @sys = sort(@sys);
        foreach my $attr (@sys)
        {
            # HSVC_LOAD_ATTR( ATTR_FREQ_PB );	
            print SYS_FILE "HSVC_LOAD_ATTR( $attr );\n";
        }
    }
    else
    {
        print SYS_FILE "// No attributes found\n";
    }

    # procdata
    print PROC_FILE "// -- Input: $ifile --\n";
    if( $#proc > 0 )
    {
        @sys = sort(@proc);
        foreach my $attr (@proc)
        {
            # HSVC_LOAD_ATTR( ATTR_FREQ_PB );	
            print PROC_FILE "HSVC_LOAD_ATTR( $attr );\n";
        }
    }
    else
    {
        print PROC_FILE "// No attributes found\n";
    }

    # exdata
    print EX_FILE "// -- Input: $ifile --\n";
    if( $#ex > 0 )
    {
        @sys = sort(@ex);
        foreach my $attr (@ex)
        {
            # HSVC_LOAD_ATTR( ATTR_FREQ_PB );	
            print EX_FILE "HSVC_LOAD_ATTR( $attr );\n";
        }
    }
    else
    {
        print EX_FILE "// No attributes found\n";
    }

}


## Loop through all of the HWP input files
foreach my $ifile (@input_files)
{
    # Skip any XML files in this loop
    if( $ifile =~ /xml/ )
    {
        next;
    }

    # Open the file
    print "Processing: $ifile\n";
    open IN_FILE, $ifile or die("Cannot open $ifile\n");

    # Keep a list for each type of attribute in this file
    my @missing;

    # Loop through the files and print out each line based on timestamp
    my $linenum = 0;
    while(my $curline = <IN_FILE>)
    {
        $linenum++;

        if( substr($curline,0,2) eq "//" )
        {
            next;
        }
        #@todo - Ignore calls inside block comments RTC:48350

        my $startnum = index( $curline, "FAPI_ATTR_" );
        if( $startnum == -1 )
        {
            next;
        }

        my $attrstart = index( $curline, "ATTR_", $startnum+10 );
        if( $attrstart == -1 )
        {
            if($debug) {
                print "Something is odd with the procedure call\n";
                print "   ".$linenum.":".$curline;
            }
            next;
        }
        my $attrstop = index( $curline, ",", $attrstart );
        my $id = chopit( substr( $curline, $attrstart, $attrstop-$attrstart ) );
        #print "id=$id.\n";

        # MVPD attributes are read live by HostServices code
        if( $id =~ /MVPD/ )
        {
            if($debug){print "Skipping MVPD: %id\n";}
        }
        else
        {
            if( check_for_dupe($id,\@proc_all) 
               || check_for_dupe($id,\@ex_all) 
               || check_for_dupe($id,\@sys_all) )
            {
                push @missing, $id;
            }
            else 
            {
                if( !check_for_dupe($id,\@missing) )
                {
                    print "Missing attribute: $id.\n";
                }
                if($debug){print "   ".$linenum.":".$curline;}
            }
        }

    }

    close IN_FILE;
}


close SYS_FILE;
close PROC_FILE;
close EX_FILE;

exit;

##################################################

# remove all leading and trailing whitespace
sub chopit
{
    my $temp = shift(@_);
    $temp =~ s/^\s+//;
    $temp =~ s/\s+$//;
    return $temp;
}

# look for duplicate attributes
sub check_for_dupe
{
    my $attr = shift(@_);
    my @list = @{shift(@_)};

    foreach my $entry (@list)
    {
        if( $entry eq $attr )
        {
            return 1;
        }
    }
    return 0;
}

# print usage help
sub print_usage
{
    print "Generate the hscv_xxxdata.C files for Hostboot\n";
    print "Usage: create_hsvc_data.pl [-d] [-w] [filename1] [filename2] ...\n";
    print "  -d : Enable debug tracing\n";
    print "  -w : Enable tracing of warning messages, e.g. duplicate attributes\n";
    print "  filenameX : 1 or more input attribute xml files\n";
}
