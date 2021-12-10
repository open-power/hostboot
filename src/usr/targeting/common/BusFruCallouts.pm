# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/BusFruCallouts.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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

# This file defines the function BusFruCallouts::setupBusses which
# sets attributes on targets related to calling out targets that
# represent intermediate FRUs for different kinds of bus connections.
#
# When an error occurs over a hardware bus (such as an XBUS or SPI
# connection), any field-replaceable unit (FRU) between the two
# endpoints of the bus connection could be the cause of the
# problem. Therefore, when a Hostboot error calls out bus endpoints, the
# system should also call out each FRU that is in between the endpoints.
#
# On FSP systems, Hardware Server adds these intermediate callouts. For
# BMC systems, Hostboot needs to add them.
#
# The intermediate FRUs are provided in the FRU_PATH tag in the MRW bus
# connection descriptions. For example:
#
# <bus>
#   <bus_id>proc_socket-0/godel-0/power10-1/pauc3/iohs6/xbus6/groupxA => proc_socket-1/godel-0/power10-1/pauc3/iohs7/xbus7/groupxA</bus_id>
#   <bus_type>XBUS</bus_type>
#   <source_path>proc_socket-0/godel-0/power10-1/pauc3/iohs6/xbus6/</source_path>
#   <source_target>groupxA</source_target>
#   <dest_path>proc_socket-1/godel-0/power10-1/pauc3/iohs7/xbus7/</dest_path>
#   <dest_target>groupxA</dest_target>
#   <bus_attribute>
#     <id>FRU_PATH</id>
#     <default>L:/sys-0/node-0/nisqually-0,H:/sys-0/node-0/nisqually-0/proc_socket-0/godel-0(power10),H:/sys-0/node-0/nisqually-0/proc_socket-1/godel-0(power10)</default>
#   </bus_attribute>
# </bus>
#
# This describes an XBUS connection between two processors in
# different sockets, and the FRU_PATH bus attribute gives a list of
# all the FRUs to call out in case of an error.
# BusFruCallouts::setupBuseses parses this data and stores it on
# various targets depending on the type of bus.
#
# Below is a table of bus types correlated with where the FRU callout
# data is stored.
#
# | Bus type           | Callout arguments  | Callout attribute host | Callout attribute(s)                    |
# |--------------------+--------------------+------------------------+-----------------------------------------|
# | XBUS               | XBUS <-> XBUS      | SMPGROUP target        | FRU_PATH                                |
# | OMI                | OMI <-> OCMB       | OMI target             | FRU_PATH                                |
# | SPI SEEPROM (MVPD) | PROC               | PROC target            | SPI_MVPD_PRIMARY_INFO_CALLOUTS          |
# | SPI SEEPROM (SBE)  | PROC               | PROC target            | SPI_SBE_BOOT_CODE_PRIMARY_INFO_CALLOUTS |
# | SPI TPM            | TPM                | TPM target             | FRU_PATH                                |
# | I2C                | PROC + I2C address | DIMM target            | I2C_CALLOUTS                            |
# | FSI                | PROC <-> PROC      | PROC target            | FRU_PATH                                |

package BusFruCallouts;

use strict;
use XML::Simple;
use XML::Parser;
use Data::Dumper;
use File::Spec;

use Targets;

# This is a list of bus types in the MRW that connect targets that
# host the FRU callout attributes themselves. (Some MRW busses connect
# targets that won't hold the FRU callout info directly, and those are
# not stored here.) Callouts for bus types listed here will end up in
# the target's FRU_PATH attribute.
my %TARGET_BUSSES = (
    OMI => 1,
    XBUS => 1,
);

# This is a list of rules that apply to busses that the MRW connects
# which need to store attributes on other targets than the ones
# mentioned in the bus connection. (Some busses connect targets that
# will hold the attributes directly, those are listed above in
# TARGET_BUSSES.)
#
# For each bus type, there are multiple entries. The form of each entry is
#
#   PATTERN => RULE
#
# If PATTERN matches the bus_id element of the MRW bus description, then the rule applies.
#
# Each RULE is of the form
#
#   [ BUS TARGET, PARENT TARGET TYPE, ATTRIBUTE ]
#
# The RULE describes how to find the target to set the ATTRIBUTE on.
#
# We start with BUS TARGET (the XML element in the bus description
# that has the root target for this rule), then go up to the first
# parent with the type PARENT TARGET TYPE and set the attribute on
# that target.
my %ATTRIBUTE_BUSSES = (
    I2C =>
    {
        'ocmb' => [ 'DEST_TARGET', 'DIMM', 'I2C_CALLOUTS' ]
    },
    SPI =>
    {
        'spi-tpm' => [ 'DEST_TARGET', 'TPM', 'FRU_PATH' ],

        'spi-sbepri' => [ 'SOURCE_TARGET', 'PROC', 'SPI_SBE_BOOT_CODE_PRIMARY_INFO_CALLOUTS' ],
        'spi-sbebup' => [ 'SOURCE_TARGET', 'PROC', 'SPI_SBE_BOOT_CODE_BACKUP_CALLOUTS' ],
        'spi-mvpd' => [ 'SOURCE_TARGET', 'PROC', 'SPI_MVPD_PRIMARY_INFO_CALLOUTS' ],
        'spi-meas' => [ 'SOURCE_TARGET', 'PROC', 'SPI_MVPD_BACKUP_INFO_CALLOUTS' ],
    },
    FSIM =>
    {
        'fsim' => [ 'DEST_TARGET', 'PROC', 'FRU_PATH' ]
    }
);

# @brief Get the location code of the given target, or of the nearest parent that has one.
#
# @param[in] $targetObj  - The global target object.
# @param[in] $target     - The target to get the location code for.
# @return                - A location code, or the empty string if not found.
sub getClosestLocationCode
{
    my ($targetObj, $target) = @_;

    if ($target eq '')
    {
        return '';
    }

    # Ignore errors when fetching this attribute
    my $code = eval '$targetObj->getAttribute($target, "STATIC_ABS_LOCATION_CODE")';

    return $code || getClosestLocationCode($targetObj, $targetObj->getTargetParent($target));
}

# @brief Translate the value of a FRU_PATH attribute (of the form
# PRIORITY1:PATH1,PRIORITY2:PATH2 where PRIORITYx is a priority letter
# and PATHy is an MRW target path) into a list of location codes (in
# the same form).
#
# @param[in] $targetObj  - The global target object.
# @param[in] $fruPath    - The value of a bus' FRU_PATH tag.
# @return                - A string of callouts with priority and location code.
sub getCalloutLocationCodesString
{
    my ($targetObj, $fruPath) = @_;

    my @callouts = split(',', $fruPath);

    my @codes;

    foreach my $callout (@callouts)
    {
        # This pattern should match things like H:/path/to/target
        # Some target paths end with a parenthetical comment which we
        # want to ignore.
        if ($callout =~ /(.):([^\(]+)/)
        {
            my ($priority, $calloutpath) = ($1, $2);

            my $location = getClosestLocationCode($targetObj, $calloutpath);

            push(@codes, ("$priority:$location"));
        }
    }

    return join(',', reverse(@codes));
}

# @brief Set the intermediate bus FRU callout attributes for a bus
# that stores its attributes directly on the bus target.
#
# @param[in] $targetObj  - The global target object.
# @param[in] $busType    - The type of the bus connection (OMI, XBUS, etc).
sub setupBusWithTarget
{
    my ($targetObj, $busType) = @_;

    foreach my $connections ($targetObj->{data}->{BUSSES}->{$busType})
    {
        foreach my $conn (@$connections)
        {
            my $callouts = getCalloutLocationCodesString($targetObj, $conn->{BUS_TARGET}->{bus_attribute}->{FRU_PATH}->{default});

            my $target = $conn->{SOURCE_TARGET};

            # Redirect attribute values from the XBUS targets to the
            # ABUS targets. See processMrw.pl for rationale.
            $target =~ s/xbus/abus/;
            $target =~ s/groupx/group/;

            $targetObj->setAttribute($target, 'FRU_PATH', $callouts);
        }
    }
}

# @brief Set the intermediate bus FRU callout attributes for a bus
# that stores its attributes on another target than the one the MRW
# bus description names.
#
# @param[in] $targetObj  - The global target object.
# @param[in] $busType    - The type of the bus connection (I2C, SPI, etc).
sub setupBusWithParentTarget
{
    my ($targetObj, $busType) = @_;

    foreach my $connections ($targetObj->{data}->{BUSSES}->{$busType})
    {
        foreach my $conn (@$connections)
        {
            foreach my $pattern (keys %{$ATTRIBUTE_BUSSES{$busType}})
            {
                if ($conn->{BUS_TARGET}->{bus_id} =~ /$pattern/)
                {
                    my ($busPath, $targetType, $attrname) = @{$ATTRIBUTE_BUSSES{$busType}->{$pattern}};

                    my $parent = $targetObj->findParentByType($conn->{$busPath}, $targetType, 0);

                    if ($parent eq '')
                    {
                        die "setupBusWithParentTarget: $conn->{$busPath} has no parent of type $targetType";
                    }

                    my $attributeHolderTarget = $parent;
                    my $callouts = getCalloutLocationCodesString($targetObj, $conn->{BUS_TARGET}->{bus_attribute}->{FRU_PATH}->{default});

                    $targetObj->setAttribute($attributeHolderTarget, $attrname, $callouts);

                    last;
                }
            }
        }
    }
}

# @brief Set up all the intermediate bus FRU callout attributes on all
# targets.
#
# @param[in] $targetObj  - The global target object.
sub setupBusses
{
    my $targetObj = shift;

    my $ebmc_system = 0;

    # FSP-based systems handle bus callouts on the FSP, but for eBMC
    # systems Hostboot adds callouts to intermediate FRUs for bus
    # errors, so we package the data for bus callouts into the
    # targeting data itself.
    foreach my $target (keys %{ $targetObj->getAllTargets() })
    {
        if ($targetObj->getType($target) eq 'BMC')
        {
            $ebmc_system = 1;
            last;
        }
    }

    if ($ebmc_system)
    {
        foreach my $busType (keys(%{ $targetObj->{data}->{BUSSES} }))
        {
            if ($TARGET_BUSSES{$busType})
            {
                setupBusWithTarget($targetObj, $busType);
            }
            elsif ($ATTRIBUTE_BUSSES{$busType})
            {
                setupBusWithParentTarget($targetObj, $busType);
            }
        }
    }
}
