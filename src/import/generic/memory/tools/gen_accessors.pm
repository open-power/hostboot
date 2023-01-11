#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/generic/memory/tools/gen_accessors.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2023
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

# @file gen_accessors.pm
# @brief Contains subroutines for generating attribute accessors from XML
#
# *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
# *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>

# *HWP Team: Memory
# *HWP Level: 2
# *HWP Consumed by: Memory

use strict;
use warnings;
use English;
use Carp qw( croak );

# Uncomment to enable debug output
use Data::Dumper;

use constant {
    TARGET_TYPES => {
        P10 => {
            PORT_GROUP => 'TARGET_TYPE_OCMB_CHIP',
            PORT       => 'TARGET_TYPE_MEM_PORT',
            DIMM       => 'TARGET_TYPE_DIMM',
        },
    },

    DIMM_PER_PORT => { P10 => 2, },

    PORTS_PER_GROUP => { P10 => 1, },

    # Size, in bytes, of the various value-types
    BYTE_SIZE => {
        'uint8'  => 1,
        'uint16' => 2,
        'uint32' => 4,
        'uint64' => 8,
        'int8'   => 1,
        'int16'  => 2,
        'int32'  => 4,
        'int64'  => 8,
    },

    # Special attributes which are multi-demensional but the second dimension doesn't represent the DIMM but
    # rather the data on the port
    PER_PORT_ATTRIBUTES => {
        "ATTR_MSS_VPD_DQ_MAP" => 1,
        "ATTR_MEM_VPD_DQ_MAP" => 1,
    },

    # Special attributes which are multi-demensional but the second dimension doesn't represent the PORT but
    # rather the data on the port group
    PER_PORT_GROUP_ATTRIBUTES => { "ATTR_MSS_MEM_MVPD_FWMS" => 1, },

    # Constants for code generation subroutines
    NO_TARGET           => 0,
    ARRAY_DATA          => 1,
    SCALAR_DATA         => 0,
    NO_INDEX            => 0,
    NO_LOCALS           => 0,
    PORT                => 1,
    PORT_GROUP          => 2,
    PORT_AND_PORT_GROUP => 3,
    GETTERS             => 0,
    SETTERS             => 1,
};

#
# @brief Get array dimensions from an attribute reference
# @param[in] attr - reference to the attribute to process
# @param[out] dims_ref - reference to array of dimensions
# @return array dimensions string
#
sub get_array_dimensions
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::get_array_dimensions" if ( @ARG != 2 );

    my ( $attr, $dims_ref ) = @ARG;

    my $arrayDimensions = "";

    if ( $attr->{array} )
    {
        # Remove leading whitespace
        my $dimText = $attr->{array};
        $dimText =~ s/^\s+//;

        # Split on commas or whitespace
        @{$dims_ref} = split( /\s*,\s*|\s+/, $dimText );

        foreach my $val ( @{$dims_ref} )
        {
            $arrayDimensions .= "[${val}]";
        }
    }

    return $arrayDimensions;
}

#
# @brief Format attribute description from an attribute reference
# @param[in] attr - reference to the attribute to process
#
sub format_attr_description
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::format_attr_description" if ( @ARG != 1 );

    my ($attr) = @ARG;

    if ( !$attr->{description} )
    {
        # Use "no description" if the resulting description is empty
        $attr->{description} = "No description";
    }
    else
    {
        # Remove all newline characters from the string
        $attr->{description} =~ s/^\n\s*//;
        $attr->{description} =~ s/\s*\n\s*/ /g;

        # Word wrap the string by consuming the first 79 characters, stopping at the next whitespace
        $attr->{description} =~ s/(.{79}[^\s]*)\s+/$1\n/g;

        # Insert Doxy style comments at newlines
        $attr->{description} =~ s!\n!\n    /// !g;
    }
}

#
# @brief Generate Doxygen string and param list for accessor function
# @param[in] attr - reference to the attribute to process
# @param[in] target - target string if target is an input param, NO_TARGET if not
# @param[in] array - reference to output array dimensions if the accessor data is an array, SCALAR_DATA if it's a scalar value
# @param[in] subroutine_name - name of generator subroutine
# @param[in] g_parameter - reference to hash of getter parameters
# @param[in] s_parameter - reference to hash of setter parameters
#
sub create_params_doxy
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::create_params_doxy" if ( @ARG != 6 );

    my ( $attr, $target, $array, $subroutine_name, $g_parameter, $s_parameter ) = @ARG;

    if ( $target ne NO_TARGET )
    {
        $g_parameter->{headerString} .= "    /// \@param[in] const ref to the $target\n";
        $s_parameter->{headerString} .= "    /// \@param[in] const ref to the $target\n";
        $g_parameter->{subString}    .= "const fapi2::Target<fapi2::$target>& i_target, ";
        $s_parameter->{subString}    .= "const fapi2::Target<fapi2::$target>& i_target, ";
    }

    if ( ref($array) )
    {
        my $dims = "";
        foreach my $dim ( @{$array} )
        {
            $dims .= "[$dim]";
        }
        $g_parameter->{headerString} .=
            "    /// \@param[out] $attr->{valueType}_t&[] array reference to store the value\n";
        $s_parameter->{headerString} .= "    /// \@param[in] $attr->{valueType}_t&[] ref to array of values to set\n";
        $g_parameter->{subString}    .= "$attr->{valueType}_t (&o_array)$dims";
        $s_parameter->{subString}    .= "$attr->{valueType}_t (&i_array)$dims";
    }
    else
    {
        $g_parameter->{headerString} .= "    /// \@param[out] $attr->{valueType}_t& reference to store the value\n";
        $s_parameter->{headerString} .= "    /// \@param[in] $attr->{valueType}_t the value to set\n";
        $g_parameter->{subString}    .= "$attr->{valueType}_t& o_value";
        $s_parameter->{subString}    .= "$attr->{valueType}_t i_value";
    }

    $g_parameter->{headerString} .= "    /// \@note Generated by gen_accessors.pl $subroutine_name\n";
    $s_parameter->{headerString} .= "    /// \@note Generated by gen_accessors.pl $subroutine_name\n";
}

#
# @brief Generate code for attribute fetch and store
# @param[in] attr - reference to the attribute to process
# @param[in] target - attribute target variable string
# @param[in] array - ARRAY_DATA if data is an array, or SCALAR_DATA if data is a scalar value
# @param[in] index - array index of output value if the accessor data is a scalar, or NO_INDEX if not needed
# @param[in] g_parameter - reference to hash of getter parameters
# @param[in] s_parameter - reference to hash of setter parameters
#
sub create_attr_access_code
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::create_attr_access_code" if ( @ARG != 6 );

    my ( $attr, $target, $array, $index, $g_parameter, $s_parameter ) = @ARG;

    $g_parameter->{fetchString} .= "FAPI_ATTR_GET(fapi2::$attr->{id}, $target, ";

    if ( $array == ARRAY_DATA )
    {
        $g_parameter->{fetchString} .= "l_value)";
        $s_parameter->{fetchString} .= "FAPI_ATTR_GET(fapi2::$attr->{id}, $target, l_value)";
        $s_parameter->{storeString} .= "FAPI_ATTR_SET(fapi2::$attr->{id}, $target, l_value)";
    }
    else
    {
        if ( $index eq NO_INDEX )
        {
            # Getter can just fetch to output param if it's not an array
            $g_parameter->{fetchString} .= "o_value)";
            $g_parameter->{noLocals} = 1;

            # Setter can just write to the attr if data is not an array
            $s_parameter->{storeString} .= "FAPI_ATTR_SET(fapi2::$attr->{id}, $target, i_value)";
            $s_parameter->{noLocals} = 1;
        }
        else
        {
            $g_parameter->{fetchString} .= "l_value)";
            $s_parameter->{fetchString} .= "FAPI_ATTR_GET(fapi2::$attr->{id}, $target, l_value)";
            $s_parameter->{storeString} .= "FAPI_ATTR_SET(fapi2::$attr->{id}, $target, l_value)";
        }
    }
}

#
# @brief Generate code for copying local variable data to output param if needed (and vice versa for setters)
# @param[in] array - reference string of beginning of local array, or SCALAR_DATA if data is a scalar value
# @param[in] size - array size in bytes if the accessor data is an array
# @param[in] index - array index of output value if the accessor data is a scalar, or NO_INDEX if not needed
# @param[in] g_parameter - reference to hash of getter parameters
# @param[in] s_parameter - reference to hash of setter parameters
#
sub create_execute_code
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::create_execute_code" if ( @ARG != 5 );

    my ( $array, $size, $index, $g_parameter, $s_parameter ) = @ARG;

    if ( $array ne SCALAR_DATA )
    {
        $g_parameter->{exeString} = "memcpy(o_array, $array, $size);\n";
        $s_parameter->{exeString} = "memcpy($array, i_array, $size);\n";
    }
    elsif ( $index ne NO_INDEX )
    {
        $g_parameter->{exeString} = "o_value = $index;\n";
        $s_parameter->{exeString} = "$index = i_value;\n";
    }
}

#
# @brief Generate code for local target variables if needed
# @param[in] system - system type
# @param[in] locals - selects which locals are needed, can be any of: NO_LOCALS, PORT, PORT_GROUP, PORT_AND_PORT_GROUP
# @param[in] g_parameter - reference to hash of getter parameters
# @param[in] s_parameter - reference to hash of setter parameters
#
sub create_locals_code
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::create_locals_code" if ( @ARG != 4 );

    my ( $system, $locals, $g_parameter, $s_parameter ) = @ARG;

    if ( $locals == PORT )
    {
        my $target_type = ${ +TARGET_TYPES }{$system}{PORT};
        $g_parameter->{localsString} .= "const auto l_port = i_target.getParent<fapi2::$target_type>();\n";
        $s_parameter->{localsString} .= "const auto l_port = i_target.getParent<fapi2::$target_type>();\n";
    }
    elsif ( $locals == PORT_GROUP )
    {
        my $target_type = ${ +TARGET_TYPES }{$system}{PORT_GROUP};
        $g_parameter->{localsString} .= "const auto l_port_group = i_target.getParent<fapi2::$target_type>();\n";
        $s_parameter->{localsString} .= "const auto l_port_group = i_target.getParent<fapi2::$target_type>();\n";
    }
    elsif ( $locals == PORT_AND_PORT_GROUP )
    {
        my $target_type = ${ +TARGET_TYPES }{$system}{PORT};
        $g_parameter->{localsString} .= "const auto l_port = i_target.getParent<fapi2::$target_type>();\n";
        $s_parameter->{localsString} .= "const auto l_port = i_target.getParent<fapi2::$target_type>();\n";

        $target_type = ${ +TARGET_TYPES }{$system}{PORT_GROUP};
        $g_parameter->{localsString} .= "        const auto l_port_group = l_port.getParent<fapi2::$target_type>();\n";
        $s_parameter->{localsString} .= "        const auto l_port_group = l_port.getParent<fapi2::$target_type>();\n";
    }
}

#
# @brief Generate paramaters to create methods for 'other' attributes
# @param[in] system - system type
# @param[in] attr - reference to the attribute to process
# @param[in] dims_ref - reference to array of dimensions
# @param[in] g_parameters - reference to array of getter parameters
# @param[in] s_parameters - reference to array of setter parameters
#
sub generate_other_attr_params
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::generate_other_attr_params" if ( @ARG != 5 );

    my ( $system, $attr, $dims_ref, $g_parameters, $s_parameters ) = @ARG;

    my @dims = @{$dims_ref};

    my $g_parameter     = {};
    my $s_parameter     = {};
    my $target_type     = "";
    my $target_variable = "";

    # See what type of target we have, since we need slightly different code for system targets
    if ( $attr->{targetType} eq "TARGET_TYPE_SYSTEM" )
    {
        $target_type     = NO_TARGET;
        $target_variable = "fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>()";
    }
    else
    {
        $target_type     = $attr->{targetType};
        $target_variable = "i_target";
    }

    # If we have no array ...
    if ( scalar(@dims) == 0 )
    {
        create_params_doxy( $attr, $target_type, SCALAR_DATA, "generate_other_attr_params", $g_parameter,
            $s_parameter );
        create_attr_access_code( $attr, $target_variable, SCALAR_DATA, NO_INDEX, $g_parameter, $s_parameter );
        create_execute_code( SCALAR_DATA, 0, NO_INDEX, $g_parameter, $s_parameter );
        create_locals_code( $system, NO_LOCALS, $g_parameter, $s_parameter );
    }

    # ... we have an array
    else
    {
        my $size = 1;

        # Calculate the size of the last dimensions - these are all we'll copy
        for my $dim_size (@dims)
        {
            $size *= $dim_size;
        }

        # Our true size in bytes is multiplied by the size of our valueType
        $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

        create_params_doxy( $attr, $target_type, \@dims, "generate_other_attr_params", $g_parameter, $s_parameter );
        create_attr_access_code( $attr, $target_variable, ARRAY_DATA, NO_INDEX, $g_parameter, $s_parameter );
        create_execute_code( "&l_value", $size, NO_INDEX, $g_parameter, $s_parameter );
        create_locals_code( $system, NO_LOCALS, $g_parameter, $s_parameter );
    }

    push @{$g_parameters}, $g_parameter;
    push @{$s_parameters}, $s_parameter;
}

#
# @brief Generate paramaters to create methods for OCMB_CHIP and MEM_PORT attributes
# @param[in] system - system type
# @param[in] attr - reference to the attribute to process
# @param[in] dims_ref - reference to array of dimensions
# @param[in] g_parameters - reference to array of getter parameters
# @param[in] s_parameters - reference to array of setter parameters
#
sub generate_mc_port_params
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::generate_mc_port_params" if ( @ARG != 5 );

    my ( $system, $attr, $dims_ref, $g_parameters, $s_parameters ) = @ARG;

    my @dims = @{$dims_ref};

    # Check to see how many array dimensions we have. A controller should have at most
    # 2 - one for the port and one for the dimm. Other dimensions we don't know - they
    # could be rank or they could be bits ... If we have more than 2 dimensions, we
    # return back a pointer to the other dimensions. If a controller only has one port
    # per phy or one dimm per port it will have one fewer dimension, so we calculate
    # that here.
    my $port_dimensions = ( ${ +DIMM_PER_PORT }{$system} > 1 ) ? 1 : 0;
    my $port_group_dimensions = ( ${ +PORTS_PER_GROUP }{$system} > 1 ) ? $port_dimensions + 1 : $port_dimensions;

    if ( scalar(@dims) == 0 )
    {
        my %g_parameter = ();
        my %s_parameter = ();

        create_params_doxy( $attr, $attr->{targetType}, SCALAR_DATA, "generate_mc_port_params", \%g_parameter,
            \%s_parameter );
        create_attr_access_code( $attr, "i_target", SCALAR_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
        create_execute_code( SCALAR_DATA, 0, NO_INDEX, \%g_parameter, \%s_parameter );
        create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

        push @{$g_parameters}, \%g_parameter;
        push @{$s_parameters}, \%s_parameter;
    }

    # Array per DIMM elements with PORT_GROUP target
    if (   ( $attr->{targetType} eq ${ +TARGET_TYPES }{$system}{PORT_GROUP} )
        && ( scalar(@dims) > $port_group_dimensions ) )
    {
        #
        # By DIMM
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            my @dim_subset = @dims[ $port_group_dimensions .. ( scalar(@dims) - 1 ) ];
            for my $i (@dim_subset)
            {
                $size *= $i;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{DIMM},
                \@dim_subset, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "l_port_group", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&(l_value[mss::index(l_port)][mss::index(i_target)][0])",
                $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, PORT_AND_PORT_GROUP, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

        #
        # By Port
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            my @dim_subset = @dims[ $port_dimensions .. ( scalar(@dims) - 1 ) ];
            for my $i (@dim_subset)
            {
                $size *= $i;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT},
                \@dim_subset, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "l_port_group", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&(l_value[mss::index(i_target)][0])", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, PORT_GROUP, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

        #
        # The whole enchilada
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            for my $dim_size (@dims)
            {
                $size *= $dim_size;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT_GROUP},
                \@dims, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "i_target", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&l_value", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }
    }

    # Array per DIMM elements with PORT target
    elsif (( $attr->{targetType} eq ${ +TARGET_TYPES }{$system}{PORT} )
        && ( scalar(@dims) > $port_dimensions ) )
    {
        #
        # By DIMM
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            my @dim_subset = @dims[ $port_dimensions .. ( scalar(@dims) - 1 ) ];
            for my $i (@dim_subset)
            {
                $size *= $i;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{DIMM},
                \@dim_subset, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "l_port", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&(l_value[mss::index(i_target)][0])", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, PORT, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

        #
        # By Port
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            for my $dim_size (@dims)
            {
                $size *= $dim_size;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT},
                \@dims, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "i_target", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&l_value", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }
    }

    # Per Port elements with PORT_GROUP target
    elsif (( $attr->{targetType} eq ${ +TARGET_TYPES }{$system}{PORT_GROUP} )
        && ( scalar(@dims) == $port_dimensions ) )
    {
        # Canary to tell us if we have a per-controller attribute we're not handling
        die "$attr->{targetType} is not indexed by port?" if !$attr->{mssAccessor} =~ m/PORT/;

        #
        # Per Port
        #
        {
            # There are some attributes which are multidimensional arrays, but aren't [port][dimm] but rather
            # [data], meaning they're 'per port group' attributes. MVPD_FWMS is one example; it doesn't make
            # sense to map FWMS different for different ports.
            # So check to see if we have one of those attributes, as we force the caller to ask for the attribute
            # per-port group as that's what the attribute represents.
            if ( !${ +PER_PORT_GROUP_ATTRIBUTES }{ $attr->{id} } )
            {
                my %g_parameter = ();
                my %s_parameter = ();
                my $parent_type = ${ +TARGET_TYPES }{$system}{PORT_GROUP};

                create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT},
                    SCALAR_DATA, "generate_mc_port_params", \%g_parameter, \%s_parameter );
                create_attr_access_code(
                    $attr, "i_target.getParent<fapi2::$parent_type>()",
                    SCALAR_DATA, "l_value[mss::index(i_target)]",
                    \%g_parameter, \%s_parameter
                );
                create_execute_code( SCALAR_DATA, 0, "l_value[mss::index(i_target)]", \%g_parameter, \%s_parameter );
                create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

                push @{$g_parameters}, \%g_parameter;
                push @{$s_parameters}, \%s_parameter;
            }
        }

        #
        # Per DIMM (just return the value set for my port)
        #
        {
            if ( !${ +PER_PORT_GROUP_ATTRIBUTES }{ $attr->{id} } )
            {
                my %g_parameter = ();
                my %s_parameter = ();
                my $parent_type = ${ +TARGET_TYPES }{$system}{PORT_GROUP};

                create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{DIMM},
                    SCALAR_DATA, "generate_mc_port_params", \%g_parameter, \%s_parameter );
                create_attr_access_code( $attr, "l_port.getParent<fapi2::$parent_type>()",
                    SCALAR_DATA, "l_value[mss::index(l_port)]", \%g_parameter, \%s_parameter );
                create_execute_code( SCALAR_DATA, 0, "l_value[mss::index(l_port)]", \%g_parameter, \%s_parameter );
                create_locals_code( $system, PORT, \%g_parameter, \%s_parameter );

                push @{$g_parameters}, \%g_parameter;
                push @{$s_parameters}, \%s_parameter;
            }
        }

        #
        # The whole enchilada
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            for my $dim_size (@dims)
            {
                $size *= $dim_size;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT_GROUP},
                \@dims, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "i_target", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&l_value", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

    }

    # Per dimm elements with PORT_GROUP target
    elsif (( $attr->{targetType} eq ${ +TARGET_TYPES }{$system}{PORT_GROUP} )
        && ( scalar(@dims) == $port_group_dimensions ) )
    {
        #
        # By DIMM
        #
        {
            # There are some attributes which are 2 dimensional arrays, but aren't [port][dimm] but rather
            # [port][data], meaning they're 'per port' attributes. DQ mapping is one example; it doesn't make
            # sense to map DQ different for DIMM on a port; they terminate in the same place on the MC.
            # So check to see if we have one of those attributes, as we force the caller to ask for the attribute
            # per-port as that's what the attribute represents.
            if ( !${ +PER_PORT_ATTRIBUTES }{ $attr->{id} } )
            {
                my %g_parameter = ();
                my %s_parameter = ();

                create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{DIMM},
                    SCALAR_DATA, "generate_mc_port_params", \%g_parameter, \%s_parameter );
                create_attr_access_code( $attr, "l_port_group", SCALAR_DATA,
                    "l_value[mss::index(l_port)][mss::index(i_target)]",
                    \%g_parameter, \%s_parameter );
                create_execute_code( SCALAR_DATA, 0, "l_value[mss::index(l_port)][mss::index(i_target)]",
                    \%g_parameter, \%s_parameter );
                create_locals_code( $system, PORT_AND_PORT_GROUP, \%g_parameter, \%s_parameter );

                push @{$g_parameters}, \%g_parameter;
                push @{$s_parameters}, \%s_parameter;
            }
        }

        #
        # By Port
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            my @dim_subset = @dims[ $port_dimensions .. ( scalar(@dims) - 1 ) ];
            for my $i (@dim_subset)
            {
                $size *= $i;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT},
                \@dim_subset, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "l_port_group", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&(l_value[mss::index(i_target)][0])", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, PORT_GROUP, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

        #
        # The whole enchilada
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            for my $dim_size (@dims)
            {
                $size *= $dim_size;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT_GROUP},
                \@dims, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "i_target", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&l_value", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }
    }

    # Per dimm elements with PORT target
    elsif (( $attr->{targetType} eq ${ +TARGET_TYPES }{$system}{PORT} )
        && ( scalar(@dims) == $port_dimensions ) )
    {
        #
        # By DIMM
        #
        {
            # There are some attributes which are 2 dimensional arrays, but aren't [port][dimm] but rather
            # [port][data], meaning they're 'per port' attributes. DQ mapping is one example; it doesn't make
            # sense to map DQ different for DIMM on a port; they terminate in the same place on the MC.
            # So check to see if we have one of those attributes, as we force the caller to ask for the attribute
            # per-port as that's what the attribute represents.
            if ( !${ +PER_PORT_ATTRIBUTES }{ $attr->{id} } )
            {
                my %g_parameter = ();
                my %s_parameter = ();

                create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{DIMM},
                    SCALAR_DATA, "generate_mc_port_params", \%g_parameter, \%s_parameter );
                create_attr_access_code( $attr, "l_port", SCALAR_DATA, "l_value[mss::index(i_target)]",
                    \%g_parameter, \%s_parameter );
                create_execute_code( SCALAR_DATA, 0, "l_value[mss::index(i_target)]", \%g_parameter, \%s_parameter );
                create_locals_code( $system, PORT, \%g_parameter, \%s_parameter );

                push @{$g_parameters}, \%g_parameter;
                push @{$s_parameters}, \%s_parameter;
            }
        }

        #
        # The whole enchilada
        #
        {
            my %g_parameter = ();
            my %s_parameter = ();
            my $size        = 1;

            # Calculate the size of the last dimensions - these are all we'll copy
            for my $dim_size (@dims)
            {
                $size *= $dim_size;
            }

            # Our true size in bytes is multiplied by the size of our valueType
            $size *= ${ +BYTE_SIZE }{ $attr->{valueType} };

            create_params_doxy( $attr, ${ +TARGET_TYPES }{$system}{PORT},
                \@dims, "generate_mc_port_params", \%g_parameter, \%s_parameter );
            create_attr_access_code( $attr, "i_target", ARRAY_DATA, NO_INDEX, \%g_parameter, \%s_parameter );
            create_execute_code( "&l_value", $size, NO_INDEX, \%g_parameter, \%s_parameter );
            create_locals_code( $system, NO_LOCALS, \%g_parameter, \%s_parameter );

            push @{$g_parameters}, \%g_parameter;
            push @{$s_parameters}, \%s_parameter;
        }

    }
}

#
# @brief Generate getter method from the paramaters
# @param[in] attr - reference to the attribute to process
# @param[in] dimString - string for array dimensions
# @param[in] parameters_ref - reference to array of accessor parameters
# @return attribute accessor getter string
#
sub generate_getters
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::generate_getters" if ( @ARG != 3 );

    my ( $attr, $dimString, $parameters_ref ) = @ARG;

    my @parameters = @{$parameters_ref};

    my $getterString = "";

    foreach my $parameter (@parameters)
    {
        $getterString .= "    ///\n";
        $getterString .= "    /// \@brief $attr->{id} getter\n";
        $getterString .= $parameter->{headerString};
        $getterString .= "    /// \@return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK\n";
        $getterString .= "    /// \@note  $attr->{description}\n";
        $getterString .= "    ///\n";

        $getterString .= "    inline fapi2::ReturnCode get_$attr->{mssAccessorName}(" . $parameter->{subString} . ")\n";
        $getterString .= "    {\n";

        $getterString .= "        " . $attr->{valueType} . "_t l_value$dimString = {};\n" if !$parameter->{noLocals};
        $getterString .= "        " . $parameter->{localsString}                          if $parameter->{localsString};
        $getterString .= "\n";

        $getterString .= "        FAPI_TRY( " . $parameter->{fetchString} . " );\n" if $parameter->{fetchString};
        $getterString .= "        " . $parameter->{exeString}                       if $parameter->{exeString};
        $getterString .= "\n";
        $getterString .= "    fapi_try_exit:\n";

        $getterString .= "        return fapi2::current_err;\n";
        $getterString .= "    }\n\n";
    }

    return $getterString;

}

#
# @brief Generate setter method from the paramaters
# @param[in] attr - reference to the attribute to process
# @param[in] dimString - string for array dimensions
# @param[in] parameters_ref - reference to array of accessor parameters
# @return attribute accessor setter string
#
sub generate_setters
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::generate_setters" if ( @ARG != 3 );

    my ( $attr, $dimString, $parameters_ref ) = @ARG;

    my @parameters = @{$parameters_ref};

    my $setterString = "";

    foreach my $parameter (@parameters)
    {
        $setterString .= "    ///\n";
        $setterString .= "    /// \@brief $attr->{id} setter\n";
        $setterString .= $parameter->{headerString};
        $setterString .= "    /// \@return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK\n";
        $setterString .= "    /// \@note  $attr->{description}\n";
        $setterString .= "    ///\n";

        $setterString .= "    inline fapi2::ReturnCode set_$attr->{mssAccessorName}(" . $parameter->{subString} . ")\n";
        $setterString .= "    {\n";

        $setterString .= "        " . $attr->{valueType} . "_t l_value$dimString = {};\n" if !$parameter->{noLocals};
        $setterString .= "        " . $parameter->{localsString}                          if $parameter->{localsString};
        $setterString .= "\n";

        $setterString .= "        FAPI_TRY( " . $parameter->{fetchString} . " );\n" if $parameter->{fetchString};
        $setterString .= "        " . $parameter->{exeString}                       if $parameter->{exeString};
        $setterString .= "        FAPI_TRY( " . $parameter->{storeString} . " );\n" if $parameter->{storeString};
        $setterString .= "\n";
        $setterString .= "    fapi_try_exit:\n";

        $setterString .= "        return fapi2::current_err;\n";
        $setterString .= "    }\n\n";
    }

    return $setterString;

}

#
# @brief Helper function to idenitify if we're an MC port target
# @param[in] system - system type
# @return reference to an array of target types
#
sub identify_mc_port_helper
{

    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::identify_mc_port_helper" if ( @ARG != 1 );

    my ($system) = @ARG;

    my @mc_port_target_types = ();
    foreach my $type ( keys( %{ ${ +TARGET_TYPES }{$system} } ) )
    {
        push( @mc_port_target_types, ${ +TARGET_TYPES }{$system}{$type} ) if ( $type ne "DIMM" );
    }

    return \@mc_port_target_types;
}

#
# @brief Generate accessor methods for a given attribute
# @param[in] system - system type
# @param[in] attr - reference to the attribute to process
# @param[in] dims_ref - reference to array of dimensions
# @param[in] array_dimensions - array dimensions string
# @param[in,out] getter_methods_ref - reference to hash of accessor methods
# @param[in,out] setter_methods_ref - reference to hash of setter methods
#
sub generate_accessor_methods
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::generate_accessor_methods" if ( @ARG != 6 );

    my ( $system, $attr, $dims_ref, $array_dimensions, $getter_methods_ref, $setter_methods_ref ) = @ARG;

    my @g_parameters = ();
    my @s_parameters = ();

    # Generate parameter info depending on target type
    my @target_types = @{ identify_mc_port_helper($system) };

    my $attr_type = $attr->{targetType};
    if ( grep( /^$attr_type$/, @target_types ) )
    {
        generate_mc_port_params( $system, $attr, $dims_ref, \@g_parameters, \@s_parameters );
    }
    else
    {
        generate_other_attr_params( $system, $attr, $dims_ref, \@g_parameters, \@s_parameters );
    }

    # Generate getter method(s)
    my $method_string = generate_getters( $attr, $array_dimensions, \@g_parameters );
    $getter_methods_ref->{ $attr->{targetType} } .= $method_string;

    # Generate setter method(s) only if the attribute has the writeable tag
    if ( exists( $attr->{writeable} ) )
    {
        $method_string = generate_setters( $attr, $array_dimensions, \@s_parameters );
        $setter_methods_ref->{ $attr->{targetType} } .= $method_string;
    }
}

#
# @brief Generate attribute file text
# @param[in] getters_or_setters - either GETTERS or SETTERS depending on which file to produce
# @param[in] output_dir - directory of output header file to write
# @param[in] output_file_prefix - filename prefix for output header file
# @param[in] method_string - string of getter methods
# @return entire file string to print to header file
#
sub generate_header_file
{
    # Gets input and checks to make sure it's valid
    croak "Incorrect number of inputs passed into gen_accessors::print_header_file" if ( @ARG != 4 );

    my ( $getters_or_setters, $output_dir, $output_file_prefix, $method_string ) = @ARG;

    # If we have no methods, just return
    croak "ERROR: no methods found in method_string" if ( $method_string eq "" );

    my $header_file_name = "";
    my $header_define    = "";
    my $file_string      = "";

    if ( $getters_or_setters == GETTERS )
    {
        $header_file_name = $output_file_prefix . "_attribute_getters.H";
        $header_define    = uc( $output_file_prefix . "_ATTR_GETTERS_H_" );
    }
    else
    {
        $header_file_name = $output_file_prefix . "_attribute_setters.H";
        $header_define    = uc( $output_file_prefix . "_ATTR_SETTERS_H_" );
    }

    #------------------------------------------------------------------------------
    # Start of file information
    #------------------------------------------------------------------------------
    $file_string .= "// " . $header_file_name . "\n";
    $file_string .= "#ifndef " . $header_define . "\n";
    $file_string .= "#define " . $header_define . "\n";
    $file_string .= "\n";
    $file_string .= "#include <fapi2.H>\n";
    $file_string .= "#include <generic/memory/lib/utils/index.H>\n";
    $file_string .= "#include <generic/memory/lib/utils/c_str.H>\n";
    $file_string .= "\n";
    $file_string .= "\n\nnamespace mss\n{\n";
    $file_string .= "namespace attr\n{\n";

    #------------------------------------------------------------------------------
    # Getter Methods
    #------------------------------------------------------------------------------
    $file_string .= $method_string;

    #------------------------------------------------------------------------------
    # End of file information
    #------------------------------------------------------------------------------
    $file_string .= "} // attr\n";
    $file_string .= "} // mss\n\n";
    $file_string .= "#endif\n";

    return $file_string;
}

return 1;
