#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/simics/hb-pnor-mvpd-preload.pl $
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
#  IBM_PROLOG_END

use strict;
use File::Temp qw/ tempfile tempdir /;

my $DEBUG = 0;

my $numProcs;
my $numCentPerProc;
my $dataPath = ".";

# Create temp file for MVPD
my $emptyMVPDfh;
my $emptyMVPD;
($emptyMVPDfh, $emptyMVPD) = tempfile();

# Create temp file for SPD
my $emptySPDfh;
my $emptySPD;
($emptySPDfh, $emptySPD) = tempfile();

my $mvpdFile = "procmvpd.dat";
my $spdFile = "dimmspd.dat";
my $sysMVPD = "sysmvpd.dat";
my $sysSPD = "sysspd.dat";

my $MAX_PROCS = 8;
my $MAX_CENT_PER_PROC = 8;
my $MAX_DIMMS_PER_CENT = 8;


while( $ARGV = shift )
{
    if( $ARGV =~ m/--numProcs/ ||
        $ARGV =~ m/-np/ )
    {
        $numProcs = shift;
    }
    elsif( $ARGV =~ m/--numCentPerProc/ ||
           $ARGV =~ m/-ncpp/ )
    {
        $numCentPerProc = shift;
    }
    elsif( $ARGV =~ m/--dataPath/ ||
           $ARGV =~ m/-dp/ )
    {
        $dataPath = shift;
    }
    else
    {
        usage();
    }
}

debugMsg( "numProcs: $numProcs" );
debugMsg( "numCentPerProc: $numCentPerProc" );

createMVPDData();
createSPDData();
cleanup();

print "PNOR VPD Data Build Complete.\n";
exit 0;

############################################
# End of Main program
############################################

#====================================================================
# Usage Message
#====================================================================
sub usage
{
    print "Usage: $0 -numProcs <value> -numCentPerProc <value> [-dataPath]\n";
    print "         [-h | --help]\n";
    print "\n";
    print "  -np    --numProcs        Number of Processors in the drawer.\n";
    print "  -ncpp  --numCentPerProc  Number of Centaurs per Processor.\n";
    print "  -dp    --dataPath        Path to where VPD data files are located.\n";
    print "                              Default: ./\n";
    print "  -h  --help               Help/Usage.\n";
    print "\n\n";
    exit 1;
}

#====================================================================
# Print Debug Messages
#====================================================================
sub debugMsg
{
    my ($msg) = @_;
    if( $DEBUG )
    {
        print "DEBUG: $msg\n";
    }
}

#====================================================================
# Cleanup
#====================================================================
sub cleanup
{
    print "Cleaning up...\n";
    my $cmd = "rm -rf $emptyMVPD $emptySPD";
    system( $cmd ) == 0 or die "Failure to cleanup!";
}

#====================================================================
# Create the MVPD data for PNOR
#====================================================================
sub createMVPDData
{
    print "Creating MVPD Data...\n";

    my $cmd;
    my $result;
    my $sourceFile;
    my $sysMVPDFile = "$dataPath/$sysMVPD";

    if( -e $sysMVPDFile )
    {
        # Cleanup any existing files
        system( "rm -rf $sysMVPDFile" );
    }
    
    # Create empty processor MVPD chunk.
    $cmd = "echo \"00FFFF: 00\" \| xxd -r \> $emptyMVPD";
    system( $cmd ) == 0 or die "Creating $emptyMVPD failed!";

    for( my $proc = 0; $proc < $MAX_PROCS; $proc++ )
    {
        if( $proc < $numProcs )
        {
            # Use real data to the full image.
            $sourceFile = "$dataPath/$mvpdFile";
        }
        else
        {
            # No processor, use empty data chunk.
            $sourceFile = $emptyMVPD;
        }

        $result = `dd if=$sourceFile of=$sysMVPDFile conv=notrunc oflag=append 2>&1 1>/dev/null`;
        if( $? )
        {
            debugMsg( "Failed to create: $sysMVPDFile, using source: $sourceFile" );
            die "Error building MVPD file! $proc\n";
        }
    }

    if( -e $sysMVPDFile )
    {
        system( "chmod 775 $sysMVPDFile" );
    }
    debugMsg( "MVPD Done." );
}

#====================================================================
# Create the SPD data for PNOR
#====================================================================
sub createSPDData
{
    print "Creating SPD Data...\n";

    my $cmd;
    my $result;
    my $sourceFile;
    my $sysSPDFile = "$dataPath/$sysSPD";

    if( -e $sysSPDFile )
    {
        # Cleanup any existing files
        system( "rm -rf $sysSPDFile" );
    }

    # Create empty SPD data chunk
    $cmd = " echo \"0001FF: 00\" \| xxd -r \> $emptySPD";
    system( $cmd ) == 0 or die "Creating $emptySPD failed!";

    for( my $proc = 0; $proc < $MAX_PROCS; $proc++ )
    {
        for( my $cent = 0; $cent < $MAX_CENT_PER_PROC; $cent++ )
        {
            for( my $dimm = 0; $dimm < $MAX_DIMMS_PER_CENT; $dimm++ )
            {
                if( ($cent < $numCentPerProc) &&
                    ($proc < $numProcs) )
                {
                    # Use the real data to the full image
                    $sourceFile = "$dataPath/$spdFile";
                }
                else
                {
                    # No dimm, use empty data chunk
                    $sourceFile = $emptySPD;
                }

                $result = `dd if=$sourceFile of=$sysSPDFile conv=notrunc oflag=append 2>&1 1>/dev/null`;
                if( $? )
                {
                    die "Error building SPD file! $proc  $cent  $dimm\n";
                }
            }
        }
    }

    if( -e $sysSPDFile )
    {
        system( "chmod 775 $sysSPDFile" );
    }
    debugMsg( "SPD Done." );
}
