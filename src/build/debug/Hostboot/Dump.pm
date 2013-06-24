#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Dump.pm $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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

package Hostboot::Dump;
use Exporter;
our @EXPORT_OK = ('main');

use Fcntl qw(SEEK_SET);

use constant    MEMSTATE_NO_MEM => 0x0;
use constant    MEMSTATE_HALF_CACHE => 0x4;
use constant    MEMSTATE_FULL_CACHE => 0x8;
use constant    MEMSTATE_MS_32MEG => 0x20;
use constant    MEMSTATE_PRE_SECURE_BOOT => 0xff;

use constant    _KB => 1024;
use constant    _MB => 1024 * 1024;

# Map the available memory at each state.
our %memory_maps = (
    MEMSTATE_NO_MEM() =>
        # No memory has been initialized so we can only dump our static
        # code load up to 512 - 4k.  The 4k is a reserved space for the
        # Secureboot Header.
        [ 0,                            (512 - 4) * _KB
        ],
    MEMSTATE_PRE_SECURE_BOOT() =>
        # Until the early secureboot operations have been done, we can
        # only access the top 512k of each 1MB column.  Need to avoid
        # the hole for the MBOX DMA buffers (64K @ 3MB + 256K).
        [ (512 - 4) * _KB,              4 * _KB,
          1 * _MB,                      512 * _KB,
          2 * _MB,                      512 * _KB,
          3 * _MB,                      256 * _KB,
          3 * _MB + (256 + 64) * _KB,   (256 - 64) * _KB
        ],
    MEMSTATE_HALF_CACHE() =>
        # All of the first 4MB can now be read (except reserved MBOX).
        [ 512 * _KB,                    512 * _KB,
          1 * _MB + 512 * _KB,          512 * _KB,
          2 * _MB + 512 * _KB,          512 * _KB,
          3 * _MB + 512 * _KB,          512 * _KB
        ],
    MEMSTATE_FULL_CACHE() =>
        # Add next full 4MB after we expand to the full cache.
        [ 4 * _MB,                      1 * _MB,
          5 * _MB,                      1 * _MB,
          6 * _MB,                      1 * _MB,
          7 * _MB,                      1 * _MB
        ],
    MEMSTATE_MS_32MEG() =>
        # Add next 24MB after we expand to memory.
        [ 8 * _MB,                      24 * _MB
        ]
);

# Map the current state to the combined states available.
our %memory_states = (
    MEMSTATE_NO_MEM() => [ MEMSTATE_NO_MEM ],
    MEMSTATE_PRE_SECURE_BOOT() => [ MEMSTATE_NO_MEM, MEMSTATE_PRE_SECURE_BOOT ],
    MEMSTATE_HALF_CACHE() => [ MEMSTATE_NO_MEM, MEMSTATE_PRE_SECURE_BOOT,
                             MEMSTATE_HALF_CACHE ],
    MEMSTATE_FULL_CACHE() => [ MEMSTATE_NO_MEM, MEMSTATE_PRE_SECURE_BOOT,
                             MEMSTATE_HALF_CACHE, MEMSTATE_FULL_CACHE ],
    MEMSTATE_MS_32MEG() => [ MEMSTATE_NO_MEM, MEMSTATE_PRE_SECURE_BOOT,
                             MEMSTATE_HALF_CACHE, MEMSTATE_FULL_CACHE,
                             MEMSTATE_MS_32MEG ]
);

sub main
{
    my ($packName,$args) = @_;

    # Parse 'debug' option.
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    # Read the current memory state.
    my ($memstate_addr, $memstate_size) =
        ::findSymbolAddress("KernelMemState::state");
    my $memstate = ::read32($memstate_addr + 4);  # only need bottom 32 bits
    ::userDisplay (sprintf "Current state is %x\n", $memstate) if $debug;

    #Get current timestamp and open a corresponding file.
    my $timeStamp = `date +%Y%m%d%H%M`;
    chomp $timeStamp;
    my  $hbDumpFile =   "hbdump.$timeStamp";

    ::userDisplay "Dumping Hostboot to Open output file $hbDumpFile\n";
    open( OUTFH, ">$hbDumpFile" )   or die "can't open $hbDumpFile: $!\n";
    binmode(OUTFH);

    # Read memory regions and output to file.
    foreach my $state (@{$memory_states{int $memstate}})
    {
        my $regions = $memory_maps{int $state};

        while (scalar(@{$regions}))
        {
            my $start = shift @{$regions};
            my $length = shift @{$regions};
            ::userDisplay (sprintf "\t%x@%x\n", $length, $start) if $debug;

            my $data = ::readData($start, $length);
            seek OUTFH, $start, SEEK_SET;
            print OUTFH $data;
        }
    }

    # Close file.
    close OUTFH;

    #Check if hbDumpFile exists and is not empty
    if (-s "$hbDumpFile" )
    {
        ::userDisplay "\nHostBoot dump saved to $hbDumpFile.\n";
        ::userDisplay "Use the hb-dump-debug program to parse the dump.\n";
    }
    else
    {
        ::userDisplay "\nWARNING: Cannot dump HB.  Did you stop instructions?\n\n";
        unlink $hbDumpFile;
    }
}

sub helpInfo
{
    my %info = (
        name => "Dump",
        intro => ["Dumps the entire Hostboot buffer to a file."],
    );
}
