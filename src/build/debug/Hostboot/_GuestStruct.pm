# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/_GuestStruct.pm $
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

# This module defines a simple interface for reading structures from guest memory
# without having to calculate addresses manually.
#
# For example:
#
#  my $struct = _GuestStruct->new([
#     [ 'a', UINT32 ],
#     [ 'b', UINT64 ],
#     [ 'c', UINT32, 10 ],
#  ]);
#
# defines a structure equivalent to:
#
#  struct {
#     uint32_t a;
#     uint64_t b;
#     uint32_t c[10];
#  };
#
# Padding is calculated as in C (i.e. the offset of member 'b' in both cases is
# 8, not 4) unless the PACKED parameter is passed after the list of
# members. Right now only UINT32 and UINT64 variables are supported.
#
# To indicate that a structure of the type exists at a guest address, use
# createInstance (no guest memory is actually read until a specific member is
# accessed, and then only the memory for that member is read):
#
#  my $addr = 0x1234; ### whatever address
#  my $instance = $struct->createInstance($addr);
#
# To read the value of a member, use the structure like a hash ref, and call the last one
# like a function ref. Arrays take a number as an argument.
#
#  my $b = $instance->{b}->();
#  my $arrayvalue = $instance->c->(3);
#
# Structure nesting is supported.

package Hostboot::_GuestStruct;

use strict;
use warnings;

use constant GCOV_EXTENDED_IMAGE_ADDRESS => (1024 * 1024 * 1024);

use Hostboot::_DebugFrameworkVMM qw(NotFound NotPresent getPhysicalAddr);

use Exporter 'import';
our @EXPORT_OK = ('UINT8', 'UINT16', 'UINT32', 'UINT64',
                  'padding', 'PACKED', 'NOT_PACKED', 'read32', 'read64', 'readBytes');

use List::Util qw(max);

use constant UINT8 => 1;
use constant UINT16 => 2;
use constant UINT32 => 4;
use constant UINT64 => 8;

use constant PAGESIZE => 4096;

use constant NOT_PACKED => 0;
use constant PACKED => 1;

sub padding
{
    my $amt = shift;

    return [ '', $amt ];
}

sub createInstance
{
    my $self = shift;
    my $addr = shift;

    my $obj = { };

    my $fields = $self->{fields};

    foreach my $fieldName (keys %$fields)
    {
        $obj->{$fieldName} = sub
        {
            my $arridx = shift;

            return $self->{fields}->{$fieldName}->($addr, $arridx);
        };
    }

    return $obj;
}

sub roundUp
{
    my $num = shift;
    my $nearest = shift;

    return int(int($num + ($nearest - 1)) / $nearest) * $nearest;
}

sub align
{
    my $self = shift;
    return $self->{align};
}

sub size
{
    my $self = shift;
    return $self->{size};
}

sub new
{
    my $class = shift;
    my $fields = shift;
    my $packed = shift // NOT_PACKED;

    my $self = { };
    bless $self, $class;

    $self->{fields} = { };

    my $nextFieldOffset = 0;
    my $align = 1;

    foreach my $field (@$fields)
    {
        my $fieldName = $field->[0];
        my $fieldType = $field->[1];
        my $arraySize = $field->[2] // 1;
        my $fieldAlignment;

        if ($packed == PACKED)
        {
            $fieldAlignment = 1;
        }
        else
        {
            $fieldAlignment = ref($fieldType) && $fieldType->align() || $fieldType;
        }

        $align = max($align, $fieldAlignment);
        my $fieldSize = ((ref($fieldType) && $fieldType->size() || $fieldType)
                         * $arraySize);
        my $fieldOffset = roundUp($nextFieldOffset, $fieldAlignment);
        $nextFieldOffset = $fieldOffset + $fieldSize;

        $self->{fields}->{"$fieldName"} = sub
        {
            my $base = shift;
            my $arridx = shift // 0;

            my $fieldAddr = $base + $fieldOffset + $arridx * $fieldSize;

            if (ref($fieldType))
            {
                return $fieldType->createInstance($fieldAddr);
            }
            elsif ($fieldSize == 4)
            {
                return read32($fieldAddr);
            }
            elsif ($fieldSize == 8)
            {
                return read64($fieldAddr);
            }
            else
            {
                die "Can't read field $fieldName of unsupported size $fieldSize";
            }
        };
    }

    $self->{size} = $nextFieldOffset;
    $self->{align} = $align;

    return $self;
}

# Determine whether an address is virtual.
sub isVirtualAddress
{
    my $addr = shift;

    return ($addr >= GCOV_EXTENDED_IMAGE_ADDRESS);
}

sub translateAddr
{
    my $addr = shift;

    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            return NotFound;
        }
    }

    return $addr;
}

sub read64
{
    my $addr = shift;

    $addr = translateAddr($addr);

    if (NotFound eq $addr)
    {
        return NotFound;
    }

    return ::read64($addr);
}

sub read32
{
    my $addr = shift;

    $addr = translateAddr($addr);

    if (NotFound eq $addr)
    {
        return NotFound;
    }

    return ::read32($addr);
}

sub readBytes
{
    my $addr = shift;
    my $size = shift;

    if (isVirtualAddress($addr))
    {
        my $result = "";

        while ($size > 0)
        {
            my $amount = $size;

            if ((($addr % PAGESIZE) + $size) > PAGESIZE)
            {
                $amount = PAGESIZE - ($addr % PAGESIZE);
            }

            my $paddr = getPhysicalAddr($addr);

            if ((NotFound eq $paddr) || (NotPresent eq $paddr))
            {
                return undef;
            }
            else
            {
                $result = $result . ::readData($paddr, $amount);
            }

            $size = $size - $amount;
        }

        return $result;
    }

    my $data = ::readData($addr, $size);

    if (length($data) != $size)
    {
        return undef;
    }

    return $data;
}

1;
