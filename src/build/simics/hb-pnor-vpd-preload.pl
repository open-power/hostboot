#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/hb-pnor-vpd-preload.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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
use strict;
use File::Temp qw/ tempfile tempdir /;

my $DEBUG = 0;

my $numProcs;
my $numCentPerProc;
my $dataPath = ".";
my $outputPath = ".";
my $machine = "MURANO";
my $procConfig = "uninit";
my $maxProcs = 8;

# Create temp file for MVPD
my $emptyMVPDfh;
my $emptyMVPD;
($emptyMVPDfh, $emptyMVPD) = tempfile();

# Create temp file for SPD
my $emptySPDfh;
my $emptySPD;
($emptySPDfh, $emptySPD) = tempfile();

# Create temp file for CVPD
my $emptyCVPDfh;
my $emptyCVPD;
($emptyCVPDfh, $emptyCVPD) = tempfile();

my $mvpdFile = "procmvpd.dat";
my $cvpdFile = "cvpd.dat";
my $spdFile = "dimmspd.dat";
my $sysMVPD = "sysmvpd.dat";
my $sysCVPD = "syscvpd.dat";
my $sysSPD = "sysspd.dat";

my $MAX_CENT_PER_PROC = 8;
my $MAX_DIMMS_PER_CENT = 8;
my $MAX_MCS = 8;

my @mcsArray = ( 0,0,0,0,0,0,0,0 );


while( $ARGV = shift )
{
    if( $ARGV =~ m/--numProcs/ ||
        $ARGV =~ m/-np/ )
    {
        $numProcs = shift;
        debugMsg( "Num Procs: $numProcs" );
    }
    elsif( $ARGV =~ m/--maxProcs/ ||
           $ARGV =~ m/-mp/ )
    {
        $maxProcs = shift;
    }
    elsif( $ARGV =~ m/--numCentPerProc/ ||
           $ARGV =~ m/-ncpp/ )
    {
        $numCentPerProc = shift;
        debugMsg( "Num Centaurs Per Proc: $numCentPerProc" );
    }
    elsif( $ARGV =~ m/--dataPath/ ||
        $ARGV =~ m/-dp/ )
    {
        $dataPath = shift;
        debugMsg( "Data Path: $dataPath" );
    }
    elsif( $ARGV =~ m/--machine/ ||
        $ARGV =~ m/-m/ )
    {
        $machine = shift;
        debugMsg( "Machine: $machine" );
    }
    elsif( $ARGV =~ m/--outputPath/ ||
           $ARGV =~ m/-op/ )
    {
        $outputPath = shift;
    }
    elsif( $ARGV =~ m/--forceProc/ ||
           $ARGV =~ m/-fp/ )
    {
        $procConfig = shift;
    }
    else
    {
        usage();
    }
}

#figure out default procConfig if one was not specified.
#if procConfig was specified, validate it's length.
if( $procConfig =~ m/uninit/ )
{
    $procConfig = "";
    for( my $proc = 0; $proc < $maxProcs; $proc++ )
    {
        if( $proc < $numProcs )
        {
            $procConfig = $procConfig."1";
        }
        else
        {
            $procConfig = $procConfig."0";
        }
    }
}
elsif(length($procConfig) != $maxProcs)
{
    print "ERROR: forceProc arg must specify presence of same number of procs as indicated by maxProcs($maxProcs)\n";
    exit 1;
}

getCentaurConfig();
createMVPDData();
createCVPDData();
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
    print "Usage: $0 --numProcs <value> --numCentPerProc <value>\n";
    print "         [--dataPath <path> ] [-m | --machine <value>]\n";
    print "         [-mp | --maxProcs <value>\n";
    print "         [-fp | --forceProc <value ] [-h | --help]\n";
    print "\n";
    print "  -np    --numProcs        Number of Processors in the drawer.\n";
    print "  -mp    --maxProcs        Max number of Proc records created.\n";
    print "  -fp    --forceProc       Force specific procs to be present.\n";
    print "  -ncpp  --numCentPerProc  Number of Centaurs per Processor.\n";
    print "  -m     --machine         Text machine to build data for.\n";
    print "                              Default: MURANO\n";
    print "  -dp    --dataPath        Path to VPD data files.\n";
    print "  -op    --outputPath      Path where VPD files should end up.\n";
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
    my $sysMVPDFile = "$outputPath/$sysMVPD";

    if( -e $sysMVPDFile )
    {
        # Cleanup any existing files
        system( "rm -rf $sysMVPDFile" );
    }

    # Currently it looks like all processors are populated in the order that
    # they are numbered.  The following logic should work for every platform.
    # If this ever changes, building the MVPD data and SPD data will need to
    # be combined to not duplicate the logic for determining which processors
    # have which DIMMs.
    
    # Create empty processor MVPD chunk.
    $cmd = "echo \"00FFFF: 00\" \| xxd -r \> $emptyMVPD";
    system( $cmd ) == 0 or die "Creating $emptyMVPD failed!";

    for( my $proc = 0; $proc < $maxProcs; $proc++ )
    {
        if( substr($procConfig,$proc,1) =~ /1/ )
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
# Create the CVPD data for PNOR
#====================================================================
sub createCVPDData
{
    print "Creating CVPD Data...\n";

    my $cmd;
    my $result;
    my $sourceFile;
    my $sysCVPDFile = "$outputPath/$sysCVPD";

    if( -e $sysCVPDFile )
    {
        # Cleanup any existing files
        system( "rm -rf $sysCVPDFile" );
    }

    #Centaurs are populated based on populated Processors and special
    #MCS plugging rules.  We can look at $procConfig and $maxProcs
    #to determine processor config.  Centaur plugging is contained
    #in $mcsArray, populated by getCentaurConfig()

    # Create empty CVPD data chunk
    $cmd = " echo \"000FFF: 00\" \| xxd -r \> $emptyCVPD";
    system( $cmd ) == 0 or die "Creating $emptyCVPD failed!";

    for( my $proc = 0; $proc < $maxProcs; $proc++ )
    {
        for( my $cent = 0; $cent < $MAX_CENT_PER_PROC; $cent++ )
        {
            if( ($mcsArray[$cent] == 1) &&
                substr($procConfig,$proc,1) =~ /1/ )
            {
                debugMsg( "$machine( $proc, $cent): Real File" );
                # Use the real data to the full image
                $sourceFile = "$dataPath/$cvpdFile";
            }
            else
            {
                debugMsg( "$machine( $proc, $cent): Empty file" );
                # No Centaur, use empty data chunk
                $sourceFile = $emptyCVPD;
            }

            $result = `dd if=$sourceFile of=$sysCVPDFile conv=notrunc oflag=append 2>&1 1>/dev/null`;
            if( $? )
            {
                die "Error building CVPD file! proc=$proc cent=$cent\n";
            }

        }
    }

    if( -e $sysCVPDFile )
    {
        system( "chmod 775 $sysCVPDFile" );
    }
    debugMsg( "CVPD Done." );
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
    my $sysSPDFile = "$outputPath/$sysSPD";

    if( -e $sysSPDFile )
    {
        # Cleanup any existing files
        system( "rm -rf $sysSPDFile" );
    }

    # Create empty SPD data chunk
    $cmd = " echo \"0001FF: 00\" \| xxd -r \> $emptySPD";
    system( $cmd ) == 0 or die "Creating $emptySPD failed!";

    for( my $proc = 0; $proc < $maxProcs; $proc++ )
    {
        for( my $cent = 0; $cent < $MAX_CENT_PER_PROC; $cent++ )
        {
            for( my $dimm = 0; $dimm < $MAX_DIMMS_PER_CENT; $dimm++ )
            {
                if( ($mcsArray[$cent] == 1) &&
                    substr($procConfig,$proc,1) =~ /1/ )
                {
                    debugMsg( "$machine( $proc, $cent, $dimm ): Real File" );
                    # Use the real data to the full image
                    $sourceFile = "$dataPath/$spdFile";
                }
                else
                {
                    debugMsg( "$machine( $proc, $cent, $dimm ): Empty file" );
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


sub getCentaurConfig
{
    debugMsg( "getCentaurConfig $machine" );

    for( my $mcs = 0; $mcs < $MAX_MCS; $mcs++ )
    {
        debugMsg( "Mcs: $mcs" );
        if( $machine eq "MURANO" )
        {
            # Plugging order is:
            #   Processor 0 - 3
            #   MCS 4 - 7 (1 Centaur/MCS)
            if( $mcs >= 4 &&
                $mcs <= (4 + ($numCentPerProc - 1)) )
            {
                $mcsArray[$mcs] = 1;
            }
        }
        elsif( $machine eq "VENICE" )
        {
            # Plugging order is:
            #   Processor 0 - 7
            #   MCS 4 - 7, then 0 - 3
            if( ($numCentPerProc <= 4) &&
                ($mcs >= 4) &&
                ($mcs <= (4 + ($numCentPerProc - 1))) )
            {
                $mcsArray[$mcs] = 1;
            }
            elsif( $numCentPerProc > 4 )
            {
                if( $mcs >= 4 &&
                    $mcs <= 7 )
                {
                    $mcsArray[$mcs] = 1;
                }
                elsif( $mcs >= 0 &&
                       $mcs < ($numCentPerProc - 4) )
                   {
                       $mcsArray[$mcs] = 1;
                   }
            }
        }
        elsif( $machine eq "TULETA" )
        {
            # Plugging order is:
            #   Processor 0 - 3
            #   MCS 4 - 7, then 0 - 3 (1 Centaur/MCS)
            if( ($numCentPerProc <= 4) &&
                ($mcs >= 4) &&
                ($mcs <= (4 + ($numCentPerProc - 1))) )
            {
                $mcsArray[$mcs] = 1;
            }
            elsif( $numCentPerProc > 4 )
            {
                if( $mcs >= 4 &&
                    $mcs <= 7 )
                {
                    $mcsArray[$mcs] = 1;
                }
                elsif( $mcs >= 0 &&
                       $mcs < ($numCentPerProc - 4) )
                   {
                       $mcsArray[$mcs] = 1;
                   }
            }
        }
        else
        {
            die "Invalid machine ($machine)!!!  Cannot preload DIMM VPD \
            data...exiting.";
        }
    }

    debugMsg( "@mcsArray" );


}
