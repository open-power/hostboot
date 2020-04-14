# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/data/chip_data/lib/BitRange.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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
package BitRange;

use warnings;
use strict;

use Data::Dumper;

#-------------------------------------------------------------------------------

# Takes a string of integers separated by ',' (concat) and ':' (range). Will
# return a sorted list of the expanded strings.
sub expand($)
{
    my ( $str ) = @_;

    my @list;
    for my $e ( split(/,/, $str) )
    {
        if ( $e =~ /([0-9]+):([0-9]+)/ )
        {
            push @list, $_ foreach ( int($1)..int($2) );
        }
        else
        {
            push @list, int($e);
        }
    }

    return @list;
}

#-------------------------------------------------------------------------------

sub __combineConsecutiveRanges($$;$$); # because it is called recursively

sub __combineConsecutiveRanges($$;$$)
{
    my ( $in, $out, $first, $last ) = @_;

    # Check if there are any elements in the input list.
    if ( 0 < scalar @{$in} )
    {
        # Check if we have found any previous range elements.
        if ( defined $first )
        {
            if ( defined $last )
            {
                # We have at least two in a range. Check if the next one is in
                # the consecutive range.
                if ( $last + 1 == $in->[0] )
                {
                    $last = shift @{$in};
                }
                # This range is done. Add to the list and start the next range.
                else
                {
                    push @{$out}, "$first:$last";
                    $first = shift @{$in};
                    $last = undef;
                }
            }
            else
            {
                # Only the first element in the range so far. Check if the next
                # one is in the consecutive range.
                if ( $first + 1 == $in->[0] )
                {
                    $last = shift @{$in};
                }
                # This range is done. Add to the list and start the next range.
                else
                {
                    push @{$out}, "$first";
                    $first = shift @{$in};
                    $last = undef;
                }
            }
        }
        # No previous range elements. Get the first one.
        else
        {
            $first = shift @{$in};
            $last  = undef; # Just in case.
        }

        # Iterate again.
        __combineConsecutiveRanges($in, $out, $first, $last);
    }
    # Nothing else in the input list. Add any trailing range elements.
    elsif ( defined $first )
    {
        push @{$out}, "$first" . ((defined $last) ? ":$last" : "");
    }
}

# Takes a reference to a list of integers. Any set of consecutive integers will
# be combined using the ':' character to represent a range
# (i.e. 0,1,2,3 => 0:3). The remaining non-consecutive integers will be combined
# with ',' character (i.e. 0,2,3,5 => 0,2:3,5).
sub compress($)
{
    my ( $in ) = @_;

    # Next, combine all of the consecutive ranges.
    my $out = [];
    __combineConsecutiveRanges( $in, $out );

    # Now, combine the non-consecutive elements and return the string.
    return join( ',', @{$out} );
}

#-------------------------------------------------------------------------------

1;
