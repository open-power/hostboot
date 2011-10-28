#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/parser/scanforsrcs.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
#  IBM_PROLOG_END
#
# Purpose: Scan the hostboot source code to extract the doxygen like tags
#          and generate a header file for the error log parser to include.
#

use strict;
use File::Find ();
use Time::localtime;
use File::Path;

# Vairables
my $DEBUG = 0;
my $component = "VOID";
my $sandBase = $ENV{HOSTBOOTROOT};

my $arg;
my %Comps;
my $wordn = "userdata1";
my $wordnd = 1;
my $NA = 1;
my $fh;

my $argOutput = "";
my $output = "";

# Arrays
my @compHeaders;
my %namespaceList;
my @reasonCodeFiles;

while( $ARGV = shift )
{
    if( $ARGV =~ m/-b/ )
    {
        $sandBase = shift;
    }
    elsif( $ARGV =~ m/-o/i )
    {
        $argOutput = shift;
    }
    elsif( $ARGV =~ m/-h/i )
    {
        usage();
    }
    elsif( $ARGV =~ m/-d/i )
    {
        $DEBUG = 1;
    }
    else
    {
        usage();
    }
}

# Variables depending on input parameters
if( $argOutput eq "" )
{
    $output = "$sandBase/obj/genfiles";
}
else
{
    $output = $argOutput; 
}
my $comp_id = "$sandBase/src/include/usr/hbotcompid.H";

# Setup all the different paths that need to be searched
my $sourcebasePath = $sandBase."/src/usr";
my $includePath = $sandBase."/src/include/usr";
my $genfilesPath = $sandBase."/obj/genfiles";

# Get the listing of components
opendir my( $dir ), $sourcebasePath or die "Couldn't open directory $sourcebasePath, $!";
my @components = readdir $dir;
closedir $dir;

my %sourcebase;
my %sourcebaseInc;
my %sourcebaseGenfiles;

my @fileList;

################################################################
# Debug Printing
################################################################
debugMsg( "Comp id file: $comp_id" );
debugMsg( "Source Base Path: $sourcebasePath" );
debugMsg( "Sandbox Base Dir: $sandBase" );
debugMsg( "Output Dir: $output" );
################################################################

foreach( @components )
{
    # Both src/usr directories as well as src/include/usr directories
    # are done here to make sure they line up with the same "component"
    # generated files will be done after this loop under the "genfiles"
    # component name.
    $component = $_;
    debugMsg( "Component: $component" );

    # Print components for debug.
    my $compDir = "$sourcebasePath/$component";
    debugMsg( "Component Dir: $compDir" );

    # Skip files and dirs . and ..
    if( -d "$compDir" )
    {
        if( ($component eq ".") ||
            ($component eq ".." ) ||
            ($component eq "example" ) )
        {
            debugMsg( "exiting..." );
            next;
        }
    }
    else
    {
        debugMsg( "exiting-->" );
        next;
    }

    # Check to be sure the main src directory is available
    if( -e "$compDir" )
    {
        # Get a list of files to be scanned
        %sourcebase = getFiles( $compDir );
    }
    else
    {
        # Exit since the path of the user code wasn't found.
        die( "\nERROR!  Path ($compDir) does not exist.  Cannot run!\n" );
    }

    # Get the associated component include files
    my $incCompDir = "$includePath/$component";
    debugMsg( "Include Path: $incCompDir" );

    # Skip files and dirs . and ..
    if( -d "$incCompDir" )
    {
        # Do nothing, we want the directories
    }
    else
    {
        debugMsg( "exiting-->" );
        next;
    }

    # if include dir exists, get the files
    if( -e "$incCompDir" )
    {
        # Add the include files
        %sourcebaseInc = getFiles( $incCompDir );
    }
    else
    {
        # Exit since the path of the user code wasn't found.
        die( "\nERROR!  Path ($incCompDir) does not exist. Cannot run!\n" );
    }

    # Put each file on list to be scanned
    foreach( values %sourcebase )
    {
        push( @fileList, $_ );
        debugMsg( "File: $_" );

        # Delete hash entry
        delete $sourcebase{$_};
    }

    # Put each file on list to be scanned
    foreach( values %sourcebaseInc )
    {
        push( @fileList, $_ );
        debugMsg( "File (include): $_" );

        # Delete hash entry
        delete $sourcebaseInc{$_};
    }

    foreach( @fileList )
    {
        debugMsg( "Calling extractTags for file: $_" );
        extractTags( $_, $component );
    }

    # Clear the file list so we don't reuse them
    @fileList = ();
}

# Scan the generated files and add to file list
if( -e $genfilesPath )
{
    %sourcebaseGenfiles = getFiles( $genfilesPath );
    foreach( values %sourcebaseGenfiles )
    {
        push( @fileList, $_ );
        debugMsg( "File (genfiles): $_" );
        delete $sourcebaseGenfiles{$_};
    }

    foreach( @fileList )
    {
        debugMsg( "Calling extractTags for file: $_" );
        extractTags( $_, "genfiles" );
    }
}
else
{
    die( "\nERROR! Path($genfilesPath) does not exist.  Cannot continue!\n" );
}

# Get the file open
$fh = openHeaderFile();

# Start writing the main header file that will be included by errlparser.C
startMainHeaderFile( $fh );

# Write each case statement for printing
foreach my $key (sort(keys(%Comps)))
{
    writePrintStatement( $fh, $key, \@{$Comps{$key}} );
}

# Finish writing the header
finishMainHeaderFile( $fh );

exit 0;

#=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#  End of Main program
#=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

################################################################################
#
# Print the Usage message
#
################################################################################

sub usage
{
    print "Usage: $0 < -b base > <-d> < -o output dir >\"\n";
    print "\n";
    print "-b:     base directory ( default is pwd )\n";
    print "-o:     Used as the output directory where header file is dropped\n";
    print "-d      Enable Debug messages.\n";
    print "-h      Display usage message.\n";
    print "\n\n";
    exit 1;
}


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
# Extracts each tag and description from each entry for the given file.
#
################################################################################

sub extractTags
{
    my $data;
    my ($file, $comp) = @_;
    debugMsg( "extractTags: Component: $comp" );
    local *FH;

    debugMsg( "Processing: $file" );

    open(FH, "$file") or die("Cannot open: $file: $!");
    read(FH, $data, -s FH) or die("Error reading $file: $!");
    close FH;

    # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    # Capture everything from opening '/*@' to end of tags '*/'
    #
    # Example:
    #   /*@
    #     * @errortype
    #     * @reasoncode     I2C_INVALID_OP_TYPE
    #     * @severity       ERRL_SEV_UNRECOVERABLE
    #     * @moduleid       I2C_PERFORM_OP
    #     * @userdata1      i_opType
    #     * @userdata2      addr
    #     * @devdesc        Invalid Operation type.
    #     */
    # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    while ($data =~ /\/\*\@((.|\n)+?)\*\//mgo )
    {
        debugMsg( "Found New Error Tag!" );

        my $text = $1;
        debugMsg( "Text1: $text" );
        my %hash = $text =~ /\@(\S+)(?:\s+|\.+)\b(.+?)$/gm;
        my $tmp;
        my $tmpKey;

        foreach my $key (sort keys %hash)
        {
            $tmpKey = AddSlashes( $key );
            debugMsg( "Key: $tmpKey" );
            # Extract multi-line string
            $text =~ /\@$tmpKey(?:\s+|\.+)(.+?)(?:\@|$).*/s;
            debugMsg( "Text3: $text" );
            $tmp = $1;
            debugMsg( "Tmp: $tmp" );
            $tmp =~ s/\s*\*\s*/ \n/gm;
            debugMsg( "Tmp again: $tmp" );
            $tmp = stripWhitespace( $tmp );
            debugMsg( "Tmp trimmed: $tmp" );
            $hash{$key} = $tmp;
	    debugMsg( "Assigning '$key' = '$tmp'" );
        }

        push @{$Comps{$comp}}, \%hash;
    }
}


################################################################################
#
# getFiles - find *.H or *.C files
# This recursively searches the input directory passed in for all C/H files.
#
################################################################################

sub getFiles
{
    my ($l_input_dir) = @_;
    my @dir_entry;
    my %l_input_files;
    local *DH;

    debugMsg( "Getting Files for dir: $l_input_dir" );

    # Open the directory and read all entry names.
    opendir(DH, $l_input_dir) or die("Cannot open $l_input_dir: $!");
    # skip the dots
    @dir_entry = grep { !/^\./ } readdir(DH);
    #@dir_entry = readdir(DH);
    closedir(DH);
    while (@dir_entry)
    {
        my $l_entry = shift(@dir_entry);
        my $full_path = "$l_input_dir/$l_entry";

        debugMsg( "getFiles: Full Path: $full_path" );

#        if ($full_path =~ /\/$comp\/test/g)  # skip the test dirs
#        {
#            debugMsg( "Found test dir - next!!" );
#            next;
#        }
#        elsif ($l_entry =~ /\.[H|C]$/)
        if ($l_entry =~ /\.[H|C]$/)
        {
            $l_input_files{$l_entry} = $full_path;
            debugMsg( "getFiles: Adding file: $full_path" );
        }
        elsif (-d $full_path)
        {
            # recursive here
            my %local_hash = getFiles($full_path);
            my @keys = keys(%local_hash);

            foreach(@keys)
            {
                $l_input_files{$_} = $local_hash{$_};
            }
        }
    }
    return(%l_input_files);
}


################################################################################
#
# Add escape characters to strings
#
################################################################################

sub AddSlashes 
{
    my ($text) = @_;
    ## Make sure to do the backslash first!
    $text =~ s/\\/\\\\/g;
    $text =~ s/'/\\'/g;
    $text =~ s/"/\\"/g;
    $text =~ s/\\0/\\\\0/g;

    $text =~ s/\[/\\[/g;
    $text =~ s/\]/\\]/g;
    return $text;
}


################################################################################
#
# Strip whitespace from beginning/end of string
#
################################################################################

sub stripWhitespace
{
    my ($text) = @_;

    $text =~ s/^\s+//;  # strip leading spaces
    $text =~ s/\s+$//;  # strip trailing spaces

    return $text;
}

################################################################################
#
# Look for the components reasoncode file and include it
#
################################################################################

sub includeReasonCodes
{
    my ( $fh,$incPath,$level ) = @_;

    debugMsg( "includeReasonCodes incpath: $incPath" );
    debugMsg( "includeReasonCodes level: $level" );

    my @incDirs = glob( $incPath );
    my $incFileName = "";

    foreach my $file( @incDirs )
    {
        debugMsg( "includeReasonCodes file: $file" );
        my @allDirs = split( '/', $file );
#        $tmpParent = pop @allDirs;

#        if( $parentDir ne "" )
#        {
#            $parentDir = $parentDir."/$tmpParent";
#        }
#        else
#        {
#            $parentDir = $tmpParent;
#        }
#        debugMsg( "includeReasonCodes parent dir: $parentDir" );
#        debugMsg( "includeReasonCodes tmpparent: $tmpParent" );

        if( $file =~ m/reasoncodes/i )
        {
            for( my $count = 0; $count < $level; $count++ )
            {
                my $tmpTxt = pop @allDirs;

                if( $incFileName ne "" )
                {
                    $incFileName = $tmpTxt . "/$incFileName";
                }
                else
                {
                    $incFileName = $tmpTxt;
                }
            }
            debugMsg( "ReasonCode file: $file" );
            debugMsg( "Include string: $incFileName" );

            print $fh "#include <$incFileName>\n";
#            print $fh "#include <$parentDir>\n";

            # Find the namespace of the reason codes
            findNameSpace( $file )
        }
        elsif( -d $file )
        {
            debugMsg( "includeReasonCodes recursion" );
            # Recursion is done here.
            includeReasonCodes( $fh, $file."/*", ($level+1) );
        }

#        $parentDir = "";
#        $tmpParent = "";
    }
}


################################################################################
#
# Build the main header file that errlparser.C will use to include all of
# the generated header files.
#
################################################################################

sub startMainHeaderFile
{
    my ($fh) = @_;
    my $timestamp = ctime();
    my $imageId = getImageId();

    print $fh <<EOF;
/*
 * Automatically generated by src/usr/errl/parser/scanforsrcs.pl
 *
 * TimeStamp:   $timestamp
 * Image Id:    $imageId
 *
*/


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
EOF

    # Add the includes - start in src/include/usr
    my $startDir = $sandBase."/src/include/usr/*";
    includeReasonCodes( $fh, $startDir, 1 );

    print $fh <<EOF;


/*****************************************************************************/
// N a m e s p a c e s
/*****************************************************************************/
EOF

    foreach( values %namespaceList )
    {
        my $namespace = $_;
        print $fh "using namespace $namespace;\n"
    }

    print $fh <<EOF;


static void printErrorTags ( uint64_t i_src,
                             uint64_t i_modId )
{
    uint64_t error = (i_src << 8) | i_modId;

    switch( error )
    {
EOF
}


################################################################################
#
# Finish writing main header file
#
################################################################################

sub finishMainHeaderFile
{
    my ($fh) = @_;

    print $fh <<EOF;

        default:
            uint32_t src = i_src & 0xFFFFFFFF;
            uint32_t modId = i_modId & 0xFFFFFFFF;
            printf( "\\nThere was not a valid Errorlog tag found for the given error combination!\\n" );
            printf( "   Reason: 0x%04x, Module Id: 0x%02x\\n\\n", src, modId );
            break;

    };
}
EOF
}


################################################################################
#
# Open generated header file
#
################################################################################

sub openHeaderFile
{
    my $filename = "$output/hostBootSrcParse.H";
    my $fh;

    if (! -e $output)
    {
        debugMsg( "Creating directory $output" );
        eval { mkpath($output) };

        if ($@)
        {
            die("Couldn't create $output: $@");
        }
    }

    if (-e $filename)
    {
        chmod(0777, $filename);
    }

    open($fh, ">$filename") or die("Cannot open $filename: $!");
    return $fh;
}


################################################################################
#
# Write the print statements to the header
#
################################################################################

sub writePrintStatement
{
    my ($fh, $compName, $aref) = @_;
    my $wordstart = "userdata1";
    my $modId;
    my $reasonCode;
    my $caseValue;
    my $line;

    my %caseHash = ();

    foreach my $href ( @$aref )
    {
        # Get the ModId and Reasoncode tags
        foreach my $tag ( sort keys %$href )
        {
            $href->{$tag} =~ s/\"/\\\"/g;
            my @lines = split /^/, $href->{$tag};

            if( scalar( @lines ) > 1 )
            {
                foreach $line( @lines )
                {
                    $line =~ s/\n//g;
                }
            }
            else
            {
                $line = $href->{$tag};
                $line =~ s/\n//g;
            }

            $line = stripWhitespace( $line );
            if( "moduleid" eq $tag )
            {
                $modId = $line;
            }
            elsif( "reasoncode" eq $tag )
            {
                $reasonCode = $line;
            }
        }
        debugMsg( "Comp Name: $compName" );
        debugMsg( "Module Id: $modId" );
        debugMsg( "Reason Code: $reasonCode" );

        # If we've got a duplicate Module Id/Reason code go, on to the
        # next one.  We can't have duplicates, and its been asked that
        # we don't have compile errors because of it.
        if( "$modId.$reasonCode" eq $caseHash{ $compName } )
        {
            debugMsg( "Hash exists, skip subsequent." );

            # Print a warning message
            print "\n#################################################################\n";
            print "  WARNING - Duplicate hash found for:\n";
            print "      component     $compName\n";
            print "      module id     $modId\n";
            print "      reason code   $reasonCode\n";
            print "#################################################################\n";
            next;
        }
        else
        {
            $caseHash{ $compName } = "$modId.$reasonCode";
        }


        # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        #
        # This check will be used to exclude module Ids which aren't set
        # in stone...  I think they should be, but ...
        # So, as more oddities show up, this will need to be modified
        # to accomodate.
        #
        # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        if( ($modId =~ /see/i) &&
            ($modId =~ /task/i) )
        {
            # Move to the next loop if this tag is invalid.
            debugMsg( "Invalid Mod Id: $modId" );
            next;
        }
        # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

        print $fh "         case \(\($reasonCode \<\< 8\) \| $modId\) \:\n";
        print $fh "             printf( \"\\n\" \)\;\n";
        foreach my $tag ( sort keys %$href )
        {
            $href->{$tag} =~ s/\"/\\\"/g;
            my @lines = split /^/, $href->{$tag};

            if( scalar( @lines ) > 1 )
            {
                print $fh "             printf( \"\%-20s";
                foreach my $line( @lines )
                {
                    $line =~ s/\n//g;
                    print $fh "$line";
                }
                print $fh "\\n\"\, \"$tag\" \)\;\n";
            }
            else
            {
                my $line = $href->{$tag};
                $line =~ s/\n//g;
                print $fh "             printf( \"\%-20s$line\\n\"\, \"$tag\" \)\;\n";
            }
        }
        print $fh "             break;\n\n";
    }
}


################################################################################
#
# find the namespace of the file.
#
################################################################################

sub findNameSpace
{
    my ( $file ) = @_;
    my $data;
    open(FH, "$file") or die("Cannot open: $file: $!");
    read(FH, $data, -s FH) or die("Error reading $file: $!");
    close FH;

    # get the namespace
    my $namespace = "VOID";
    while( $data =~ /^namespace(.+?\n)/gm )
    {
        $namespace = $1;
        $namespace =~ s/\;+$//;     # strip trailing semicolon
        $namespace =~ s/\{+$//;     # strip opening bracket
        $namespace = stripWhitespace( $namespace );
        $namespaceList{$namespace} = $namespace;
    }
    debugMsg( "Namespace: $namespace" );
    debugMsg( "   from File: $file" );
}


################################################################################
#
# Get the Image id
#
################################################################################
sub getImageId
{
    my $imageId = `git describe --dirty || echo Unknown-Image \`git rev-parse --short HEAD\``;
    chomp $imageId;

    if (($imageId =~ m/Unknown-Image/) ||  	# Couldn't find git describe tag.
        ($imageId =~ m/dirty/) ||	 	# Find 'dirty' commit.
        ($imageId =~ m/^.{15}-[1-9]+/))	# Found commits after a tag.
    {
        $imageId = $imageId."/".$ENV{"USER"};
    }

    return $imageId;
}
