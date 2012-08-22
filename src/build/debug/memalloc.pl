#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/memalloc.pl $
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

# Usage:
#    In order to use this tooling, you must recompile at least the src/lib
#    directory with the environment variable HOSTBOOT_MEMORY_LEAKS=1.
#    You need to 'make clean' to ensure this variable takes effect.
#
#    The resulting image can be executed in simics, which will cause magic
#    instructions to be triggered on each memory allocation (malloc, realloc,
#    free).  The simics debug tooling will catch the haps from the magic
#    instructions and create a data file 'hb_memoryleak.dat'.  This file
#    can be fed to this script to analyse leaks or all memory analysis.
#
#    If you desire to do memory analysis of just a certain portion of
#    Hostboot execution (ex. a single istep), you may delete the
#    'hb_memoryleak.dat' file while simics is paused.
#

use strict;

# Parse parameters.
if ($#ARGV < 0)
{
    die "memalloc.pl [--all] <datafile>\n";
}

my $all_allocations = 0;
my $file = shift;
if ($file eq "--all")
{
    $all_allocations = 1;
    $file = shift;
}

# Open data file and parse.
open (MEMORY_LOG, "< $file") or die "Cannot open $file.\n";

my $lines = [];

while(my $line = <MEMORY_LOG>)
{
    # Format: FUNCTION 0dSIZE 0xPTR1 0xPTR2 [ 0xLR 0xLR ... ]
    if ($line =~ m/([A-Z]*) ([0-9]*) (0x[0-9a-f]*) (0x[0-9a-f]*) \[(.*)\]/)
    {
        my $parsed = {};
        $parsed->{"type"} = $1;
        $parsed->{"size"} = int $2;
        $parsed->{"ptr"} = hex $3;
        $parsed->{"ptr2"} = hex $4;

        # Parse stack frame addresses.
        my $stack_addrs = [];
        my $stack = $5;
        $parsed->{"stack_str"} = $stack;
        while ($stack =~ m/(0x[0-9a-f]+) (.*)/)
        {
            push @{$stack_addrs}, (hex $1);
            $stack = $2;
        }
        $parsed->{"stack"} = $stack_addrs;
        push @{$lines}, $parsed;
    }
}
close MEMORY_LOG;

# Parse symbol file.
my %symbol_address = ();
my %symbol_isfunc = ();

my $gensyms = $ENV{"HOSTBOOTROOT"}."/img/hbicore_test.syms";
open (GENSYMS, "< $gensyms") or die "Cannot find syms file: $gensyms\n";
while (my $line = <GENSYMS>)
{
    chomp $line;
    my ($is_func,$code_addr,$addr,$function);

    $line =~ m/(.*?),(.*?),(.*?),(.*?),(.*)/;
    $is_func = "F" eq $1;
    $addr = hex $2;
    $function = $5;

    if (not defined $symbol_address{$addr})
    {
	$symbol_address{$addr} = ();
    }
    push @{$symbol_address{$addr}}, $function;
    $symbol_isfunc{$function} = $is_func;
}
my @symbol_sorted_addrs = sort { $a <=> $b} keys %symbol_address;
# End parse symbol file.


# Filter out malloc/free pairs.
if (not $all_allocations)
{
    $lines = leaks_only($lines);
}

# Display total memory usage (or leaks).
my $size = 0;
foreach my $line (@{$lines})
{
    $size += $line->{"size"};
}
print "Total Memory: ".$size." bytes\n";

# Group allocations with the same stack back-trace.
my %stacks = ();
foreach my $line (@{$lines})
{
    next if ($line->{"type"} ne "MALLOC");

    if (defined $stacks{$line->{"stack_str"}})
    {
        $stacks{$line->{"stack_str"}}->{"size"} += $line->{"size"};
        $stacks{$line->{"stack_str"}}->{"blocks"} += 1;
    }
    else
    {
        my $stack_loc = {};
        $stack_loc->{"blocks"} = 1;
        $stack_loc->{"size"} = $line->{"size"};
        $stack_loc->{"stack"} = $line->{"stack"};
        $stacks{$line->{"stack_str"}} = $stack_loc;
    }
}

# Display all stacks (and their memory allocations).
foreach my $stack (sort {$stacks{$b}->{"size"} <=> $stacks{$a}->{"size"}}
                    (keys %stacks))
{
    print "-------------------------------------------------------\n";
    print $stacks{$stack}->{"blocks"}." blocks for a total of ";
    print $stacks{$stack}->{"size"}." bytes.\n";
    foreach my $addr (@{$stacks{$stack}->{"stack"}})
    {
        print (sprintf "\t%s (0x%x)\n",
                       find_symbol_name($addr, 0, \%symbol_address,
                                        \@symbol_sorted_addrs,
                                        \%symbol_isfunc),
                       $addr
              );
    }
}

# Function: leaks_only
# Brief: Filters out malloc / free pairs with the same address.
sub leaks_only
{
    my $allocs = {};
    my $lines = shift;

    foreach my $line (@{$lines})
    {
        if ($line->{"type"} eq "MALLOC")
        {
            $allocs->{$line->{"ptr"}} = $line;
        }
        elsif ($line->{"type"} eq "REALLOC")
        {
            undef $allocs->{$line->{"ptr2"}};
            $allocs->{$line->{"ptr"}} = $line;
        }
        elsif ($line->{"type"} eq "FREE")
        {
            undef $allocs->{$line->{"ptr"}};
        }
    }

    my @values = values %{$allocs};

    return \@values;
}

# Function: find_symbol_name
# Brief: Determines an appropriate symbol name based on the syms file and
#        an address.  (code came from genlist)
sub find_symbol_name
{
    my ($offset, $require_function, $symbol_addrs,
        $symbol_sorted_addrs, $symbol_funcs) = @_;

    if (defined $symbol_addrs->{$offset})
    {
	for my $sym (@{$symbol_addrs->{$offset}})
	{
	    if ($symbol_funcs->{$sym})
	    {
		return $sym;
	    }
	}
	if ($require_function)
	{
	    return 0;
	}
	return @{$symbol_addrs->{$offset}}[0];
    }
    if ($require_function)
    {
	return 0;
    }

    my $prevoffset = -1;
    my $search_first = 0;
    my $search_last = $#$symbol_sorted_addrs;
    while ($search_first != $search_last)
    {
        my $search_mid = int ($search_first + $search_last) / 2;
        if ($search_mid == $search_first)
        {
            if (@$symbol_sorted_addrs[$search_last] <= $offset)
            {
                $search_first = $search_last;
            }
            else
            {
                $search_last = $search_first;
            }
        }
        elsif (@$symbol_sorted_addrs[$search_mid] <= $offset)
        {
            $search_first = $search_mid;
        }
        else
        {
            $search_last = $search_mid;
        }
    }
    if (@$symbol_sorted_addrs[$search_first] <= $offset)
    {
        $prevoffset = @$symbol_sorted_addrs[$search_first];
    }

    if (defined $symbol_addrs->{$prevoffset})
    {
	for my $sym (@{$symbol_addrs->{$prevoffset}})
	{
	    if ($symbol_funcs->{$sym})
	    {
		return sprintf "%s+0x%x", $sym, ($offset - $prevoffset);
	    }
	}
	return sprintf "%s+0x%x", @{$symbol_addrs->{$prevoffset}}[0],
			($offset - $prevoffset);
    }
    return sprintf "Unknown @ 0x%x", $offset;
}

