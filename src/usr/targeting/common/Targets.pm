# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/Targets.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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

package Targets;

use strict;
use XML::Simple;
use XML::Parser;
use Data::Dumper;
use feature "state";
use Carp qw( croak confess );
use List::Util qw(max);

# Define a true and false keyword
use constant { true => 1, false => 0 };


#--------------------------------------------------
# @brief The constructor for the object Targets which will contain the
#        target instances along with their attributes.
#--------------------------------------------------
sub new
{
    my $class = shift;
    my $self  = {
        # The following data are associated with the
        # user command line options
        build           => "",
        force           => 0,
        serverwiz_file  => "",  # input xml file
        serverwiz_dir   => "",  # directory of input xml file
        debug           => 0,
        system_config   => "",
        output_file     => "",
        report          => 0,
        run_self_test   => 0,   # run internal test
        stealth_mode    => 0,   # Silence warnings, only print errors

        # The following data are associated with the
        # xml itself
        version      => 0,
        xml          => undef,
        data         => undef,
        targeting    => undef,
        master_proc  => undef,
        huid_idx     => undef,
        mru_idx      => undef,
        xml_version  => 0,
        errorsExist  => 0,
        TOP_LEVEL    => "",
        report_log   => "",
        TOP_LEVEL_HANDLE    => undef,
        TOPOLOGY            => undef,
        NUM_PROCS_PER_NODE  => 0,  # The number of PROCs found/processed
        MAX_MCS             => 0,  # The number of MCSs found/processed
    };
    return bless $self, $class;
}

#--------------------------------------------------
# @brief Set the version of the output file
#
# @details If given a version number, then that will be used for the output
#          file.  If no version number given, then will use the version
#          number from the input file.  If no version given and none can be
#          found, then 0 is used.
#
# @param [in] $self - The global target object.
# @param [in] $version - If given, the version number to set ouput file to.
#--------------------------------------------------
sub setVersion
{
    my $self    = shift;
    my $version = shift;

    # If no version number given, then try input XML file
    if ($version eq undef)
    {
        # Default to 0 if no version number given
        $version = 0;

        # If the input XML file has a version number, then propagate that to the
        # output file, which seems to be the most appropriate thing to do
        # considering that the output file is a product of the input file.
        if (exists $self->{xml}->{version})
        {
            $version = $self->{xml}->{version};
        }
    }

    $self->{version} = $version;
}

sub getData
{
    my $self = shift;
    return $self->{data};
}

## loads ServerWiz XML format
sub loadXML
{
    my $self = shift;
    my $filename = shift;

    $XML::Simple::PREFERRED_PARSER = 'XML::Parser';
    print "Loading MRW XML: $filename\n";
    $self->{xml} =
      XMLin($filename,forcearray => [ 'child_id', 'hidden_child_id', 'bus',
                                      'property', 'field', 'attribute',
                                      'enumerator' ]);

    if (defined($self->{xml}->{'enumerationTypes'}))
    {
          $self->{xml_version} = 1;
    }

    $self->storeEnumerations();
    $self->storeGroups();
    $self->buildHierarchy();
    $self->prune();
    $self->{report_filename}=$filename.".rpt";
    $self->{report_filename}=~s/\.xml//g;
}

################################################
## prints out final XML for HOSTBOOT consumption

sub printXML
{
    my $self = shift;
    my $fh   = shift;
    my $t    = shift;
    my $build= shift;

    my $atTop = 0;
    if ($t eq "top")
    {
        $atTop = 1;
        $t     = $self->{targeting}->{SYS};
        print $fh "<attributes>\n";
        print $fh "<version>" . $self->{version} . "</version>\n";
    }
    if (ref($t) ne "ARRAY")
    {
        return;
    }
    for (my $p = 0; $p < scalar(@{$t}); $p++)
    {
        if (ref($t->[$p]) ne "HASH") { next; }
        my $target = $t->[$p]->{KEY};
        $self->printTarget($fh, $target, $build);
        my $children = $t->[$p];
        foreach my $u (sort(keys %{$children}))
        {
            if ($u ne "KEY")
            {
                $self->printXML($fh, $t->[$p]->{$u}, $build);
            }
        }
    }
    if ($atTop)
    {
        print $fh "</attributes>\n";
    }
}

#--------------------------------------------------
# @brief Dump the attributes of the Target given
#
# @param [in] $self - The global target object.
# @param [in] $target -The target to dump the attributes of.
#--------------------------------------------------
sub dumpTarget
{
    my $self   = shift;
    my $target = shift;

    print "target($target)\n";
    print Dumper($self->getTarget($target));
}

sub printTarget
{
    my $self   = shift;
    my $fh     = shift;
    my $target = shift;
    my $build  = shift;

    my $target_ptr = $self->getTarget($target);

    if ($target eq "")
    {
        return;
    }

    my $target_TYPE = $self->getAttribute($target, "TYPE");

    # Only allow OMI types with MCC parent
    # OMIC_PARENT only exists on an OMI target with MCC parent
    if ($target_TYPE eq "OMI" && !defined($target_ptr->{ATTRIBUTES}->{"OMIC_PARENT"}->{default}))
    {
        return;
    }

    print $fh "<targetInstance>\n";
    my $target_id = $self->getAttribute($target, "PHYS_PATH");
    $target_id = substr($target_id, 9);
    $target_id =~ s/\///g;
    $target_id =~ s/\-//g;

    if ($target_TYPE eq "OCMB_CHIP")
    {
        # If target is of type OCMB_CHIP, then remove "_chip" from target ID
        $target_id =~ s/_chip//g;
    }
    elsif ($target_TYPE eq "MEM_PORT")
    {
        # If target is of type MEM_PORT, then remove "_chip" and "mem_port" from target ID
        $target_id =~ s/_chip//g;
        $target_id =~ s/mem_port/memport/g;
    }

    print $fh "\t<id>" . $target_id . "</id>\n";
    if($self->getTargetType($target) eq 'unit-clk-slave')
    {
        if($target_TYPE eq 'SYSREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-sysclk-slave"."</type>\n";
        }
        elsif($target_TYPE eq 'PCICLKENDPT')
        {
            print $fh "\t<type>"."unit-pciclk-slave"."</type>\n";
        }
        elsif($target_TYPE eq 'LPCREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-lpcclk-slave"."</type>\n";
        }
    }
    elsif($self->getTargetType($target) eq 'unit-clk-master')
    {
        if($target_TYPE eq 'SYSREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-sysclk-master"."</type>\n";
        }
        elsif($target_TYPE eq 'PCICLKENDPT')
        {
            print $fh "\t<type>"."unit-pciclk-master"."</type>\n";
        }
        elsif($target_TYPE eq 'LPCREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-lpcclk-master"."</type>\n";
        }
    }
    elsif($self->getTargetType($target) eq 'enc-node-power9')
    {
        if($target_TYPE eq 'CONTROL_NODE')
        {
            print $fh "\t<type>"."enc-controlnode-power9"."</type>\n";
        }
        else
        {
            print $fh "\t<type>" . $self->getTargetType($target) . "</type>\n";
        }
    }
    else
    {
        print $fh "\t<type>" . $self->getTargetType($target) . "</type>\n";
    }

    ## get attributes
    foreach my $attr (sort (keys %{ $target_ptr->{ATTRIBUTES} }))
    {
        $self->printAttribute($fh, $target_ptr->{ATTRIBUTES}, $attr, $build);
    }
    print $fh "</targetInstance>\n";
}

sub printAttribute
{
    my $self       = shift;
    my $fh         = shift;
    my $target_ptr = shift;
    my $attribute  = shift;
    my $build      = shift;
    my $r          = "";

    # Read the value right away so we can decide if it is even valid
    my $value = $target_ptr->{$attribute}->{default};
    if ($value eq "")
    {
        # Only spew warning if not in stealth mode
        if (0 == $self->{stealth_mode})
        {
            print " Targets.pm> WARNING: empty default tag for attribute : $attribute\n";
        }
        return;
    }

    # TODO RTC: TBD
    # temporary until we converge attribute types
    my %filter;
    $filter{MODEL}                                                  = 1;
    $filter{NUMERIC_POD_TYPE_TEST}                                  = 1;
    if ($filter{$attribute} == 1)
    {
        return;
    }
    if ( $build eq "fsp" && ($attribute eq "INSTANCE_PATH" || $attribute eq "PEER_HUID"))
    {
        print $fh "\t<compileAttribute>\n";
    }
    else
    {
        print $fh "\t<attribute>\n";
    }
    print $fh "\t\t<id>$attribute</id>\n";

    if (ref($value) eq "HASH")
    {
        if (defined($value->{field}))
        {
            print $fh "\t\t<default>\n";
            foreach my $f (sort keys %{ $value->{field} })
            {
                my $v = $value->{field}->{$f}->{value};
                print $fh "\t\t\t<field><id>$f</id><value>$v</value></field>\n";
            }
            print $fh "\t\t</default>\n";
        }
    }
    else
    {
        print $fh "\t\t<default>$value</default>\n";
    }

    if ( $build eq "fsp" && ($attribute eq "INSTANCE_PATH" || $attribute eq "PEER_HUID"))
    {
        print $fh "\t</compileAttribute>\n";
    }
    else
    {
        print $fh "\t</attribute>\n";
    }
}

#--------------------------------------------------
# @brief stores TYPE enumeration values
# @details Takes enumeration types from 'self->{xml}->{enumerationType}'
#          or from 'self->{xml}->{enumerationTypes}->{enumerationType}'
#          and stores them in 'self->{enumeration}'
# example:  (bless represents the self)
#    takes:
#        bless ( { 'xml' =>
#                  { 'enumerationTypes' =>
#                    { 'enumerationType' =>
#                      { 'WOF_POWER_LIMIT' =>
#                        { 'enumerator' =>
#                          { 'NOMINAL' => { 'value' => '0' },
#                            'TURBO' => { 'value' => '1' }
#                          } } } } }
#    and copies to:
#    bless ( { 'enumeration' =>
#              { 'WOF_POWER_LIMIT' =>
#                { 'NOMINAL' => '0',
#                  'TURBO' => '1'
#                } } }
#--------------------------------------------------
sub storeEnumerations
{
    my $self = shift;
    my $baseptr = $self->{xml}->{enumerationType};
    if ($self->{xml_version} == 1)
    {
        $baseptr = $self->{xml}->{enumerationTypes}->{enumerationType};
    }
    foreach my $enumType (keys(%{ $baseptr }))
    {
        foreach my $enum (
            keys(%{$baseptr->{$enumType}->{enumerator}}))
        {
            $self->{enumeration}->{$enumType}->{$enum} =
              $baseptr->{$enumType}->{enumerator}->{$enum}->{value};
        }
    }
}

sub storeGroups
{
    my $self = shift;
    foreach my $grp (keys(%{ $self->{xml}->{attributeGroups}
        ->{attributeGroup} }))
    {
        foreach my $attr (@{$self->{xml}->{attributeGroups}
            ->{attributeGroup}->{$grp}->{'attribute'}})
        {
            $self->{groups}->{$grp}->{$attr} = 1;
        }
    }
}

#--------------------------------------------------
# @brief Set the target instance handle to the given target handle
#
# @note Private method, not for public consumption
#
# @param [in] $self - The global target object.
# @param [in] $targetHndl - The value the target instance handle is set to.
#--------------------------------------------------
sub __setTargetInstanceHandle__
{
    my $self = shift;
    my $targetHndl = shift;

    # Dynamically create and cache a handle to the target instance
    $self->{TARGET_INST_HANDLE} = $targetHndl;
}

#--------------------------------------------------
# @brief Initialize a handle to the target instance.
#
# @details This method locates where the target instance
#          resides and caches it for fast retrieval.
#
# @note Private method, not for public consumption
#
# @post A handle to the target instance is cached or exit
#       stating that the target instance cannot be found.
#
# @param [in] $self - The global target object.
#--------------------------------------------------
sub __initializeTargetInstanceHandle__
{
    my $self = shift;

    if ( (!defined $self->{TARGET_INST_HANDLE}) ||
         ($self->{TARGET_INST_HANDLE} eq "") )
    {
        # Find the location of where target instances reside
        my $targetInstances = $self->{xml}->{'targetInstance'};
        if (!defined $targetInstances)
        {
            # Check one more level for the target instances
            $targetInstances = $self->{xml}->{'targetInstances'}
                                           ->{'targetInstance'};
        }

        # If can't find the target instances, then state so and exit
        if (!defined $targetInstances)
        {
            die "No target instances defined. Check input XML for 'targetInstance' tag.\n";
        }

        $self->__setTargetInstanceHandle__($targetInstances);
    } # end if ( (!defined $self->{TARGET_INST_HANDLE}) ||  ...
}

#--------------------------------------------------
# @brief Return a handle to the target instances.
#
# @details This method will initialize the target instances
#          if has not been already initialized.
#
# @param [in] $self - The global target object.
#
# @return - A handle to the target instance.
#--------------------------------------------------
sub getTargetInstanceHandle
{
    my $self = shift;

    # Initialize the target handle.  This call will return quickly
    # if already initialized or error out if it can't initialize,
    # either way, no need to check handle prior to calling.
    $self->__initializeTargetInstanceHandle__();

    return ($self->{TARGET_INST_HANDLE});
}

#--------------------------------------------------
# @brief Set the top level target to the given target.
#
# @note Private method, not for public consumption
#
# @param [in] $self - The global target object.
# @param [in] $target - The value the top level target is set to.
#--------------------------------------------------
sub __setTopLevel__
{
    my $self = shift;
    my $target = shift;

    $self->{TOP_LEVEL} = $target;
}

#--------------------------------------------------
# @brief Initialize the top level target.
#
# @details This method locates the top level target
#          and caches it for fast retrieval.
#
# @note Private method, not for public consumption
#
# @post The top level target is cached or exit stating that
#       top level target not found.
#
# @param [in] $self - The global target object.
#--------------------------------------------------
sub __initalizeTopLevel__
{
    my $self = shift;

    # If the top level target instance has not been found and set,
    # then find that target and set top level to it
    if ((!defined $self->{TOP_LEVEL}) || ($self->{TOP_LEVEL} eq ""))
    {
        # Get a handle to the target instances
        my $targetInstancesHandle = $self->getTargetInstanceHandle();

        # Find the system target which is the top level target
        foreach my $target (keys(%{$targetInstancesHandle}))
        {
            # If target is of type 'SYS' then we found the top level target
            if ($targetInstancesHandle->{$target}->{attribute}
                                      ->{TYPE}->{default} eq "SYS")
            {
                # Set the top level target and search no more
                $self->__setTopLevel__($target);

                last;
                # YOU SHALL NOT PASS!!!
            }
        }

        # If unable to find top level target, then state so and exit
        if ((!defined $self->{TOP_LEVEL}) || ($self->{TOP_LEVEL} eq ""))
        {
            die "Unable to find system top level target\n";
        }
    } # end if ((!defined $self->{TOP_LEVEL}) || ($self->{TOP_LEVEL} eq ""))
}

#--------------------------------------------------
# @brief Return the top level target.
#
# @details This method will initialize the top level
#          target, if has not already initialized, and
#          returns the top level target.
#
# @param [in] $self - The global target object.
#
# @return - The top level target.
#--------------------------------------------------
sub getTopLevel
{
    my $self = shift;

    # Initialize the top level.  This call will return quickly
    # if top level already initialized or error out if it can't
    # initialize, either way, no need to check top level prior to calling.
    $self->__initalizeTopLevel__();

    return ($self->{TOP_LEVEL});
}

####################################################
## build target hierarchy recursively
##
## creates convenient data structure
## for accessing targets and busses
## Structure:
##
##{TARGETS}                                         # location of all targets
##{NSTANCE_PATH}                                    # keeps track of hierarchy
##                                                   path while iterating
##{TARGETS} -> target_name                          # specific target
##{TARGETS} -> target_name -> {TARGET}              # pointer to target data
##                                                   from XML data struture
##{TARGETS} -> target_name -> {TYPE}# special attribute
##{TARGETS} -> target_name -> {PARENT}              # parent target name
##{TARGETS} -> target_name -> {CHILDREN}            # array of children targets
##{TARGETS} -> target_name -> {CONNECTION} -> {DEST} # array of connection
##                                                     destination targets
##{TARGETS} -> target_name -> {CONNECTION} -> {BUS} # array of busses
##{TARGETS} -> target_name -> {CHILDREN}            # array of children targets
##{TARGETS} -> target_name -> {ATTRIBUTES}          # attributes
## {ENUMERATION} -> enumeration_type -> enum        # value of enumeration
## {BUSSES} -> bus_type[]                           # array of busses by
##                                                   bus_type (I2C, FSI, etc)
## {BUSSES} -> bus_type[] -> {BUS}                  # pointer to bus target
##                                                   from xml structure
## {BUSSES} -> bus_type[] -> {SOURCE_TARGET}        # source target name
## {BUSSES} -> bus_type[] -> {DEST_TARGET}          # dest target name

sub buildHierarchy
{
    my $self   = shift;
    my $target = shift;

    # Get a handle to the target instances
    my $targetInstanceHandle = $self->getTargetInstanceHandle();

    # If caller did not provide a target, then use the top level target
    if ($target eq "")
    {
        $target = $self->getTopLevel();
    }

    my $instance_path = $self->{data}->{INSTANCE_PATH};
    if (!defined $instance_path)
    {
        $instance_path = "";
    }

    my $old_path        = $instance_path;
    my $target_xml      = $targetInstanceHandle->{$target};
    my $affinity_target = $target;
    my $key             = $instance_path . "/" . $target;

    if ($instance_path ne "")
    {
        $instance_path = "instance:" . substr($instance_path, 1);
    }
    else
    {
        $instance_path = "instance:";
    }
    $self->setAttribute($key, "INSTANCE_PATH", $instance_path);
    $self->{data}->{TARGETS}->{$key}->{TARGET} = $target_xml;
    $self->{data}->{INSTANCE_PATH} = $old_path . "/" . $target;

    ## copy attributes
    foreach my $attribute (keys %{ $target_xml->{attribute} })
    {
        my $value = $target_xml->{attribute}->{$attribute}->{default};
        if (ref($value) eq "HASH")
        {
            if (defined($value->{field}))
            {
                foreach my $f (keys %{ $value->{field} })
                {
                    my $field_val=$value->{field}{$f}{value};
                    if (ref($field_val)) {
                        $self->setAttributeField($key, $attribute, $f,"");
                    }
                    else
                    {
                        $self->setAttributeField($key, $attribute, $f,
                            $value->{field}{$f}{value});
                    }
                }
            }
            else
            {
                if ($attribute eq "FSI_MASTER_CHIP" || $attribute eq "ALTFSI_MASTER_CHIP" )
                {
                    $self->setAttribute($key, $attribute, "physical:sys-0");
                }
                else
                {
                    $self->setAttribute($key, $attribute, "");
                }
            }
        }
        else
        {
            $self->setAttribute($key, $attribute, $value);
        }
    } # end foreach my $attribute (keys %{ $target_xml->{attribute} })

    ## global attributes overwrite local
    my $settingptr = $self->{xml}->{globalSetting};
    if ($self->{xml_version} == 1)
    {
        $settingptr = $self->{xml}->{globalSettings}->{globalSetting};
    }

    foreach my $prop (keys %{$settingptr->{$key}->{property}})
    {
        my $val=$settingptr->{$key}->{property}->
                       {$prop}->{value};
        if ((ref ($val) ne "HASH") and ($val ne ""))
        {
            $self->setAttribute($key, $prop, $val);
        }
    }

    ## Save busses
    if (defined($target_xml->{bus}))
    {
        foreach my $b (@{ $target_xml->{bus} })
        {
            if (ref($b->{dest_path}) eq "HASH") {
                $b->{dest_path}="";
            }
            if (ref($b->{source_path}) eq "HASH") {
                $b->{source_path}="";
            }
            my $source_target =
              $key . "/" . $b->{source_path} . $b->{source_target};

            my $dest_target = $key . "/" . $b->{dest_path} . $b->{dest_target};
            my $bus_type    = $b->{bus_type};

            push(
                @{
                    $self->{data}->{TARGETS}->{$source_target}->{CONNECTION}
                      ->{DEST}
                  },
                $dest_target
            );
            push(
                @{
                    $self->{data}->{TARGETS}->{$dest_target}->{CONNECTION}
                      ->{SOURCE}
                  },
                $source_target
            );
            push(
                @{
                    $self->{data}->{TARGETS}->{$source_target}->{CONNECTION}
                      ->{BUS}
                  },
                $b
            );
            push(
                @{
                    $self->{data}->{TARGETS}->{$source_target}->{CONNECTION}
                      ->{BUS_PARENT}
                  },
                $key
            );
            my %bus_entry;
            $bus_entry{SOURCE_TARGET} = $source_target;
            $bus_entry{DEST_TARGET}   = $dest_target;
            $bus_entry{BUS_TARGET}    = $b;
            push(@{ $self->{data}->{BUSSES}->{$bus_type} }, \%bus_entry);
        }
    } # end if (defined($target_xml->{bus}))

    foreach my $child (@{ $target_xml->{child_id} })
    {
        my $child_key = $self->{data}->{INSTANCE_PATH} . "/" . $child;
        $self->{data}->{TARGETS}->{$child_key}->{PARENT} = $key;
        push(@{ $self->{data}->{TARGETS}->{$key}->{CHILDREN} }, $child_key);
        $self->buildHierarchy($child);
    }

    foreach my $child (@{ $target_xml->{hidden_child_id} })
    {
        my $child_key = $self->{data}->{INSTANCE_PATH} . "/" . $child;
        $self->{data}->{TARGETS}->{$child_key}->{PARENT} = $key;
        push(@{ $self->{data}->{TARGETS}->{$key}->{CHILDREN} }, $child_key);
        $self->buildHierarchy($child);
    }
    $self->{data}->{INSTANCE_PATH} = $old_path;
}

##########################################################
## prunes targets that do not have a valid XML data attached to them.
## Extraneous targets may get added during building heirarchy if the
## source/destination targets in the bus are not valid target instances.
sub prune
{
    my $self = shift;

    # TODO RTC 181162: This is just a temporary solution/workaround to the wrong
    # APSS location in witherspoon XML. Need to take a call on either making
    # this an error or get rid of this function altogether when we have fixed
    # the witherspoon XML.
    foreach my $target (sort keys %{ $self->{data}->{TARGETS} })
    {
        if(not defined $self->{data}->{TARGETS}->{$target}->{TARGET})
        {
            # Only spew warning if not in stealth mode
            if (0 == $self->{stealth_mode})
            {
                printf("WARNING: Target instance for %s not found, deleting. ",
                       $target);
                printf("This probably indicates a bug in the source XML\n");
            }
            delete $self->{data}->{TARGETS}->{$target};
        }
    }
}

## This function returns the position of the Node corresponding to the
## incoming target
##
sub getParentNodePos
{
    my $self = shift;
    my $target = shift;
    my $pos    = 0;

    my $parent = $target;
    while($self->getType($parent) ne "NODE")
    {
       $parent = $self->getTargetParent($parent);
    }
    if($parent ne "")
    {
      $pos = $self->{data}->{TARGETS}{$parent}{TARGET}{position};
      #Reducing one to account for control node
      if($pos > 0)
      {
        $pos = $pos - 1;
      }
    }
    return $pos;
}

#--------------------------------------------------
# @brief Get the targets position data, not to be confused with the
#        attribute POSITION
#
# @param[in] $self   - The global target object
# @param[in] $target - The target to get position from
#
# @return the position of the target given
#--------------------------------------------------
sub getTargetPosition
{
    my $self   = shift;
    my $target = shift;

    return $self->{data}->{TARGETS}{$target}{TARGET}{position};
}


sub getFapiName
{
    my $self        = shift;
    my $targetType  = shift;
    my $node        = shift;
    my $chipPos     = shift;
    my $chipletPos  = shift;

    if ($targetType eq "")
    {
        die "getFapiName: ERROR: Please specify a taget name\n";
    }

    my $chipName = $targetType; # default to target type
    my $fapiName = "";

    #This is a static variable. Persists over time
    state %nonFapiTargets;
    if (not %nonFapiTargets)
    {
        $nonFapiTargets{"NODE"}  = "NA";
        $nonFapiTargets{"TPM"}   = "NA";
        $nonFapiTargets{"NVBUS"} = "NA";
        $nonFapiTargets{"OCC"}   = "NA";
        $nonFapiTargets{"BMC"}   = "NA";
    }

    if ($nonFapiTargets{$targetType} eq "NA")
    {
        return $nonFapiTargets{$targetType};
    }
    elsif ($targetType eq "SYS")
    {
        return "k0";
    }
    elsif ($targetType eq "PROC"   || $targetType eq "DIMM" ||
           $targetType eq "MEMBUF" || $targetType eq "PMIC" ||
           $targetType eq "OCMB_CHIP")
    {
        if ($node eq "" || $chipPos eq "")
        {
            confess "getFapiName: ERROR: Must specify node and chipPos for $targetType
                 current node: $node, chipPos: $chipPos\n";
        }

        if ($targetType eq "PROC")
        {
            $chipName = "pu";
        }
        elsif ($targetType eq "OCMB_CHIP")
        {
            $chipName = "ocmb";
        }

        $chipName = lc $chipName;
        $fapiName = sprintf("%s:k0:n%d:s0:p%02d", $chipName, $node, $chipPos);
    }
    else
    {
        if ($node eq "" || $chipPos eq "" || $chipletPos eq "")
        {
            confess "getFapiName: ERROR: Must specify node, chipPos,
                 chipletPos for $targetType. Current node: $node, chipPos: $chipPos
                 chipletPos: $chipletPos\n";
        }

        if ($targetType eq "MBA" || $targetType eq "L4")
        {
            $chipName = "membuf.$targetType";

        }
        elsif ($targetType eq "MEM_PORT")
        {
            $chipName = "ocmb.mp";
        }
        else
        {
            $chipName = "pu.$targetType";
        }

        $chipName = lc $chipName;
        $fapiName = sprintf("%s:k0:n%d:s0:p%02d:c%d",
                            $chipName, $node, $chipPos, $chipletPos);
    }

    return $fapiName;
}

sub setFsiAttributes
{
    my $self = shift;
    my $target = shift;
    my $type = shift;
    my $cmfsi = shift;
    my $phys_path = shift;
    my $fsi_port = shift;
    my $flip_port = shift;
    my $altfsiswitch = shift;

    $self->setAttribute($target, "FSI_MASTER_TYPE","NO_MASTER");
    if ($type eq "FSIM")
    {
        $self->setAttribute($target, "FSI_MASTER_TYPE","MFSI");
    }
    if ($type eq "FSICM")
    {
        $self->setAttribute($target, "FSI_MASTER_TYPE","CMFSI");
    }
    if ($self->isBadAttribute($target, "FSI_MASTER_CHIP"))
    {
      $self->setAttribute($target, "FSI_MASTER_CHIP","physical:sys-0");
      $self->setAttribute($target, "FSI_MASTER_PORT","0xFF");
    }
    if ($self->isBadAttribute($target,"ALTFSI_MASTER_CHIP"))
    {
      $self->setAttribute($target, "ALTFSI_MASTER_CHIP","physical:sys-0");
      $self->setAttribute($target, "ALTFSI_MASTER_PORT","0xFF");
    }
    $self->setAttribute($target, "FSI_SLAVE_CASCADE", "0");
    if ($type eq "FSICM")
    {
        $self->setAttribute($target, "FSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "FSI_MASTER_PORT", $fsi_port);
        $self->setAttribute($target, "ALTFSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "ALTFSI_MASTER_PORT", $fsi_port);
    }
    else
    {
      if ($altfsiswitch eq 0 )
      {
        $self->setAttribute($target, "FSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "FSI_MASTER_PORT", $fsi_port);
      }
      else
      {
        $self->setAttribute($target, "ALTFSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "ALTFSI_MASTER_PORT", $fsi_port);
      }
    }

    $self->setAttributeField($target, "FSI_OPTION_FLAGS","flipPort",
          $flip_port);
    $self->setAttributeField($target, "FSI_OPTION_FLAGS","reserved", "0");

}

## remove target
sub removeTarget
{
    my $self   = shift;
    my $target = shift;
    delete $self->{data}->{TARGETS}->{$target};
}

## returns pointer to target from target name
sub getTarget
{
    my $self   = shift;
    my $target = shift;
    return $self->{data}->{TARGETS}->{$target};
}

## returns pointer to array of all targets
sub getAllTargets
{
    my $self   = shift;
    my $target = shift;
    return $self->{data}->{TARGETS};
}

## returns the target name of the parent of passed in target
sub getTargetParent
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{PARENT};
}


#--------------------------------------------------
# @brief Traverse parent lineage looking for parent with
#        given type search criteria
#
# @details Traverse the parent lineage and return the parent that matches the
#          type search criteria.  If the top level target is hit and it's
#          type does not match search criteria an error out flag is set to
#          true, or not set, then the this will exit via confess.  If the
#          error out flag is set to false then "" will be returned.
#
# @note If the target has no type, then try method findParentByInstName
#
# @param [in] $self - The global target object.
# @param [in] $child - the starting point to find parent
# @param [in] $typeToMatch - search criteria
# @param [in (optional)] $errorOutIfNotFound - if set to 'false', then will return
#             "" if search criteria not met.  If set to 'true' or not set at all
#             then will exit via confess if search criteria not met.
#
# @return if search criteria met: parent whose type matches search criteria
#         if search criteria not met and errorOutIfNotFound flag is set to false,
#         then "" will be returned.
#--------------------------------------------------
sub findParentByType
{
    my $self        = shift;
    my $child       = shift;
    my $typeToMatch = shift;
    my $errorOutIfNotFound = shift;

    if ($errorOutIfNotFound eq undef)
    {
        $errorOutIfNotFound = true;
    }

    # Make sure we have not reached the end
    my $topLevel = "/" . $self->getTopLevel();
    if ($child eq $topLevel)
    {
        if ($errorOutIfNotFound == true)
        {
           confess "findParentByType: ERROR: Reached top level target. " .
                   "There is no parent of type \"$typeToMatch\". Error";
        }
        else
        {
            return "";
        }
    }

    # Get the child's parent and check if that is the parent we want
    my $parent = ($self->getTarget($child))->{PARENT};
    my $parentType = $self->getType($parent);

    if ($parentType ne $typeToMatch)
    {
        $parent = $self->findParentByType($parent, $typeToMatch,
                                          $errorOutIfNotFound);
    }

    # Found our parent, now return it. Recursion, a wonderful thing
    return $parent;
}

## returns the number of connections associated with target
sub getNumConnections
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    if (!defined($target_ptr->{CONNECTION}->{DEST}))
    {
        return 0;
    }
    return scalar(@{ $target_ptr->{CONNECTION}->{DEST} });
}

## returns the number of connections associated with target where the target is
## the destination
sub getNumDestConnections
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    if (!defined($target_ptr->{CONNECTION}->{SOURCE}))
    {
        return 0;
    }
    return scalar(@{ $target_ptr->{CONNECTION}->{SOURCE} });
}

## returns destination target name of first connection
## useful for point to point busses with only 1 endpoint
sub getFirstConnectionDestination
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{DEST}->[0];
}

## returns pointer to bus of first connection
sub getFirstConnectionBus
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{BUS}->[0];
}
## returns target name of $i connection
sub getConnectionDestination
{
    my $self       = shift;
    my $target     = shift;
    my $i          = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{DEST}->[$i];
}

## returns target name of $i source connection
sub getConnectionSource
{
    my $self       = shift;
    my $target     = shift;
    my $i          = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{SOURCE}->[$i];
}

sub getConnectionBus
{
    my $self       = shift;
    my $target     = shift;
    my $i          = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{BUS}->[$i];
}

sub getConnectionBusParent
{
    my $self       = shift;
    my $target     = shift;
    my $i          = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{BUS_PARENT}->[$i];
}

sub findFirstEndpoint
{
    my $self     = shift;
    my $target   = shift;
    my $bus_type = shift;
    my $end_type = shift;

    my $target_children = $self->getTargetChildren($target);
    if ($target_children eq "") { return ""; }

    foreach my $child (@{ $self->getTargetChildren($target) })
    {
        my $child_bus_type = $self->getBusType($child);
        if ($child_bus_type eq $bus_type)
        {
            for (my $i = 0; $i < $self->getNumConnections($child); $i++)
            {
                my $dest_target = $self->getConnectionDestination($child, $i);
                my $dest_parent = $self->getTargetParent($dest_target);
                my $type        = $self->getMrwType($dest_parent);
                my $dest_type   = $self->getType($dest_parent);
                if ($type eq "NA") { $type = $dest_type; }
                if ($type eq $end_type)
                {
                    return $dest_parent;
                }
            }
        }
    }
    return "";
}

# Find connections _from_ $target (and it's children)
sub findConnections
{
    my $self     = shift;
    my $target   = shift;
    my $bus_type = shift;
    my $end_type = shift;

    return $self->findConnectionsByDirection($target, $bus_type,
                                             $end_type, 0);
}

# Find connections _to_ $target (and it's children)
sub findDestConnections
{
    my $self     = shift;
    my $target   = shift;
    my $bus_type = shift;
    my $source_type = shift;

    return $self->findConnectionsByDirection($target, $bus_type,
                                             $source_type, 1);

}

# Find connections from/to $target (and it's children)
# $to_this_target indicates the direction to find.
sub findConnectionsByDirection
{
    my $self     = shift;
    my $target   = shift;
    my $bus_type = shift;
    my $other_end_type = shift;
    my $to_this_target = shift;

    my %connections;
    my $num=0;
    my $target_children = $self->getTargetChildren($target);
    if ($target_children eq "")
    {
        return "";
    }

    foreach my $child ($self->getAllTargetChildren($target))
    {
        my $child_bus_type = "";
        if (!$self->isBadAttribute($child, "BUS_TYPE"))
        {
            $child_bus_type = $self->getBusType($child);
        }

        if ($child_bus_type eq $bus_type)
        {
            my $numOfConnections = 0;
            if($to_this_target)
            {
                $numOfConnections = $self->getNumDestConnections($child);
            }
            else
            {
                $numOfConnections = $self->getNumConnections($child);
            }

            for (my $i = 0; $i < $numOfConnections; $i++)
            {
                my $other_end_target = undef;
                if($to_this_target)
                {
                    $other_end_target = $self->getConnectionSource($child, $i);
                }
                else
                {
                    $other_end_target = $self->getConnectionDestination($child,
                                                                        $i);
                }

                my $other_end_parent = $self->getTargetParent($other_end_target);
                my $type        = $self->getMrwType($other_end_parent);
                my $dest_type   = $self->getType($other_end_parent);
                my $dest_class  = $self->getAttribute($other_end_parent,"CLASS");

                if ($type eq "NA")
                {
                    $type = $dest_type;
                }
                if ($type eq "NA") {
                    $type = $dest_class;
                }

                if ($other_end_type ne "") {
                    #Look for an other_end_type match on any ancestor, as
                    #connections may have a destination unit with a hierarchy
                    #like unit->pingroup->muxgroup->chip where the chip has
                    #the interesting type.
                    while ($type ne $other_end_type) {
                        $other_end_parent = $self->getTargetParent($other_end_parent);
                        if ($other_end_parent eq "") {
                            last;
                        }
                        $type = $self->getMrwType($other_end_parent);
                        if ($type eq "NA") {
                            $type = $self->getType($other_end_parent);
                        }
                        if ($type eq "NA") {
                            $type = $self->getAttribute($other_end_parent, "CLASS");
                        }
                    }
                }

                if ($type eq $other_end_type || $other_end_type eq "")
                {
                    if($to_this_target)
                    {
                        $connections{CONN}[$num]{SOURCE}=$other_end_target;
                        $connections{CONN}[$num]{SOURCE_PARENT}=
                                                $other_end_parent;
                        $connections{CONN}[$num]{DEST}=$child;
                        $connections{CONN}[$num]{DEST_PARENT}=$target;
                    }
                    else
                    {
                        $connections{CONN}[$num]{SOURCE}=$child;
                        $connections{CONN}[$num]{SOURCE_PARENT}=$target;
                        $connections{CONN}[$num]{DEST}=$other_end_target;
                        $connections{CONN}[$num]{DEST_PARENT}=$other_end_parent;
                    }
                    $connections{CONN}[$num]{BUS_NUM}=$i;
                    $num++;
                }
            }
        }
    }

    if ($num==0) { return ""; }
    return \%connections;
}

## returns BUS_TYPE attribute of target
sub getBusType
{
    my $self   = shift;
    my $target = shift;
    my $type   = $self->getAttribute($target, "BUS_TYPE");
    if ($type eq "") { $type = "NA"; }
    return $type;
}

## return target type
sub getType
{
    my $self   = shift;
    my $target = shift;
    my $type   = $self->getAttribute($target, "TYPE");
    if ($type eq "") { $type = "NA"; }
    return $type;
}

## return target type
sub getMrwType
{
    my $self   = shift;
    my $target = shift;
    my $type   = $self->getAttribute($target, "MRW_TYPE");
    if ($type eq "") { $type = "NA"; }
    return $type;
}

## returns target instance name
sub getInstanceName
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{TARGET}->{instance_name};
}

## returns the parent target type
sub getTargetType
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{TARGET}->{type};
}


#--------------------------------------------------
# @brief Checks the given target for given attribute
#
# @details Will check the target for the given attribute.
#          If attribute does not exist for target then
#          return 0 (false), else if attribute does exist
#          for target then return 1 (true).  This methods
#          does not check the validity of the attribute
#          or it's value.
#
# @param [in] $self - The global target object.
# @param [in] $target - target to locate attribute on
# @param [in] $attribute - attribute to locate
#
# @return true if attribute found, else false
#--------------------------------------------------
sub doesAttributeExistForTarget
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;

    my $target_ptr = $self->getTarget($target);

    # If can't locate attribute for target then return back 0 (false)
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}))
    {
        return 0;
    }

    # Attribute for target was found, return back 1 (true)
    return 1;
}

## checks if attribute is value
## must be defined and have a non-empty value
sub isBadAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;
    my $badvalue   = shift;
    my $target_ptr = $self->getTarget($target);
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}))
    {
        return 1;
    }
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}->{default}))
    {
        return 1;
    }
    if ($target_ptr->{ATTRIBUTES}->{$attribute}->{default} eq "")
    {
        return 1;
    }
    if (defined $badvalue &&
        $target_ptr->{ATTRIBUTES}->{$attribute}->{default} eq $badvalue)
    {
        return 1;
    }

    return 0;
}

## checks if complex attribute field is
## defined and non-empty
sub isBadComplexAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;
    my $field      = shift;
    my $badvalue   = shift;
    my $target_ptr = $self->getTarget($target);

    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}))
    {
        return 1;
    }
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}->{default}))
    {
        return 1;
    }
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}->{default}->{field}))
    {
        return 1;
    }
    if ($target_ptr->{ATTRIBUTES}->{$attribute}->{default}->{field}->{$field}
        ->{value} eq "")
    {
        return 1;
    }
    if ($target_ptr->{ATTRIBUTES}->{$attribute}->{default}->{field}->{$field}
        ->{value} eq $badvalue)
    {
        return 1;
    }
    return 0;
}

## returns attribute value
sub getAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;
    my $target_ptr = $self->getTarget($target);

    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}->{default}))
    {
        confess ("ERROR: getAttribute(%s,%s) | Attribute not defined\n",
            $target, $attribute);
        $self->myExit(4);
    }
    if (ref($target_ptr->{ATTRIBUTES}->{$attribute}->{default}) eq "HASH")
    {
        return "";
    }
    return $target_ptr->{ATTRIBUTES}->{$attribute}->{default};
}


sub getAttributeGroup
{
    my $self       = shift;
    my $target     = shift;
    my $group      = shift;
    my $target_ptr = $self->getTarget($target);
    if (!defined($self->{groups}->{$group})) {
        printf("ERROR: getAttributeGroup(%s,%s) | Group not defined\n",
            $target, $group);
        $self->myExit(4);
    }
    my %attr;
    foreach my $attribute (keys(%{$self->{groups}->{$group}}))
    {
        if (defined($target_ptr->{ATTRIBUTES}->{$attribute}->{default}))
        {
            $attr{$attribute} = $target_ptr->{ATTRIBUTES}->{$attribute};
        }
    }
    return \%attr;
}

## delete a target attribute
sub deleteAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $Name       = shift;
    my $target_ptr = $self->{data}->{TARGETS}->{$target};
    if (!defined($target_ptr->{ATTRIBUTES}->{$Name}))
    {
        return 1;
    }

    delete($target_ptr->{ATTRIBUTES}->{$Name});
    $self->log($target, "Deleting attribute: $Name");
    return 0;
}

## renames a target attribute
sub renameAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $oldName    = shift;
    my $newName    = shift;
    my $target_ptr = $self->{data}->{TARGETS}->{$target};
    if (!defined($target_ptr->{ATTRIBUTES}->{$oldName}))
    {
        return 1;
    }
    $target_ptr->{ATTRIBUTES}->{$newName}->{default} =
      $target_ptr->{ATTRIBUTES}->{$oldName}->{default};
    delete($target_ptr->{ATTRIBUTES}->{$oldName});
    $self->log($target, "Renaming attribute: $oldName => $newName");
    return 0;
}

## copy an attribute between targets
sub copyAttribute
{
    my $self = shift;
    my $source_target = shift;
    my $dest_target = shift;
    my $attribute = shift;

    my $value=$self->getAttribute($source_target,$attribute);
    $self->setAttribute($dest_target,$attribute,$value);

    $self->log($dest_target, "Copy Attribute: $attribute=$value");
}

#--------------------------------------------------
# @brief Copy an attribute field from a source target to a destination target
#
# @detail Copy a single field ($field) from source target ($srcTarget)
#         to destination target ($destTarget) for given attribute ($attribute).
#
# @param[in] $self       - The global target object blob
# @param[in] $srcTarget  - The target to read field from
# @param[in] $destTarget - The target to write field to
# @param[in] $attribute  - The complex attribute to read/write field from/to
# @param[in] $field      - The field to read/write from/to
#--------------------------------------------------
sub copyAttributeField
{
    my $self       = shift;
    my $srcTarget  = shift;
    my $destTarget = shift;
    my $attribute  = shift;
    my $field      = shift;

    my $fieldValue = $self->getAttributeField($srcTarget, $attribute, $field);
    $self->setAttributeField($destTarget, $attribute, $field, $fieldValue);
}

#--------------------------------------------------
# @brief Copy an attribute field from a source target's attribute to
#        a destination target's attribute
#
# @detail Copy a single field ($field) from source target's ($srcTarget)
#         attribute $srcAttribute), to destination target's ($destTarget)
#         attribute ($destAttribute).
#
# @Note The destination attribute may not be the same as the source attribute
#       but the fields must be equal.
#
# @param[in] $self          - The global target object blob
# @param[in] $srcTarget     - The target to read field from
# @param[in] $destTarget    - The target to write field to
# @param[in] $srcAttribute  - The complex attribute to read field from
# @param[in] $destAttribute - The complex attribute to write field to
# @param[in] $field         - The field to read/write from/to
#--------------------------------------------------
sub copySrcAttributeFieldToDestAttributeField
{
    my $self          = shift;
    my $srcTarget     = shift;
    my $destTarget    = shift;
    my $srcAttribute  = shift;
    my $destAttribute = shift;
    my $field         = shift;

    # Copy the field from the source target's attribute
    my $fieldValue = $self->getAttributeField($srcTarget, $srcAttribute, $field);
    # Write the field to the destination target's attribute. where the attribute
    # may not be same as the source target's, but the field are the same.
    $self->setAttributeField($destTarget, $destAttribute, $field, $fieldValue);
}

#--------------------------------------------------
# @brief Copy ALL attribute fields from a source target to a destination target
#
# @detail Copy ALL fields from the source target ($srcTarget) to the destination
#         target ($destTarget) for the given attribute ($attribute).
#
# @param[in] $self       - The global target object blob
# @param[in] $srcTarget  - The target to read fields from
# @param[in] $destTarget - The target to write fields to
# @param[in] $attribute  - The complex attribute to read/write ALL fields from/to
#--------------------------------------------------
sub copyAttributeFields
{
    my $self = shift;
    my $srcTarget = shift;
    my $destTarget = shift;
    my $attribute = shift;

    foreach my $field(sort keys
        %{$self->{data}->{TARGETS}->{$srcTarget}->{ATTRIBUTES}->{$attribute}->{default}->{field}})
    {
        my $fieldVal = $self->getAttributeField($srcTarget, $attribute, $field);
        $self->setAttributeField($destTarget, $attribute, $field, $fieldVal);
        $self->log($destTarget, "Copy Attribute Field:$attribute($field)=$fieldVal");
    }
}

## sets an attribute
sub setAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;
    my $value      = shift;
    my $target_ptr = $self->getTarget($target);
    $target_ptr->{ATTRIBUTES}->{$attribute}->{default} = $value;
    $self->log($target, "Setting Attribute: $attribute=$value");
}
## sets the field of a complex attribute
sub setAttributeField
{
    my $self      = shift;
    my $target    = shift;
    my $attribute = shift;
    my $field     = shift;
    my $value     = shift;
    $self->{data}->{TARGETS}->{$target}->{ATTRIBUTES}->{$attribute}->{default}
      ->{field}->{$field}->{value} = $value;
    $self->log($target, "Setting Attribute: $attribute ($field) =$value");
}
## returns complex attribute value
sub getAttributeField
{
    my $self       = shift;
    my $target     = shift;
    my $attribute  = shift;
    my $field      = shift;
    my $target_ptr = $self->getTarget($target);
    if (!defined($target_ptr->{ATTRIBUTES}->{$attribute}->
       {default}->{field}->{$field}->{value}))
    {
        printf("ERROR: getAttributeField(%s,%s,%s) | Attribute not defined\n",
            $target, $attribute,$field);

        $self->myExit(4);
    }

    return $target_ptr->{ATTRIBUTES}->{$attribute}->
           {default}->{field}->{$field}->{value};
}

## returns an attribute from a bus
sub getBusAttribute
{
    my $self       = shift;
    my $target     = shift;
    my $busnum     = shift;
    my $attr       = shift;
    my $target_ptr = $self->getTarget($target);

    if (
        !defined(
            $target_ptr->{CONNECTION}->{BUS}->[$busnum]->{bus_attribute}
              ->{$attr}->{default}
        )
      )
    {
        printf("ERROR: getBusAttribute(%s,%d,%s) | Attribute not defined\n",
            $target, $busnum, $attr);
        $self->myExit(4);
    }
   if (ref($target_ptr->{CONNECTION}->{BUS}->[$busnum]->{bus_attribute}->{$attr}
      ->{default}) eq  "HASH") {
        return  "";
    }
    return $target_ptr->{CONNECTION}->{BUS}->[$busnum]->{bus_attribute}->{$attr}
      ->{default};
}

## returns a boolean for if a given bus attribute is defined
sub isBusAttributeDefined
{
    my $self       = shift;
    my $target     = shift;
    my $busnum     = shift;
    my $attr       = shift;
    my $target_ptr = $self->getTarget($target);

    return defined($target_ptr->{CONNECTION}->{BUS}->[$busnum]->{bus_attribute}
            ->{$attr}->{default});
}

#--------------------------------------------------
# @brief Returns a bus connection's, bus attribute's, attribute's default value
#
# @detail Bus connections have a list of attributes under the 'bus_attribute'
#         name which consists of attribute names with default values.
#
# @note Will exit if the bus connection ($busConnection) and/or the attribute
#       ($attribute) are invalid or does not exist.
#
# @param[in] $self          - The global target object blob
# @param[in] $busConnection - A hande to a bus connection @see getFirstConnectionBus
# @param[in] $attribute     - The name of the attribute to retrieve a default value from
#--------------------------------------------------
sub getBusConnBusAttr
{
    my $self          = shift;
    my $busConnection = shift;
    my $attribute     = shift;

    if ( !defined($busConnection->{bus_attribute}->{$attribute}->{default}) )
    {
        printf("ERROR: getBusConnBusAttr(%s, %s) | " .
               "Attribute not defined\n", $busConnection, $attribute);
        $self->myExit(4);
    }

    if (ref($busConnection->{bus_attribute}->{$attribute}->{default}) eq  "HASH")
    {
        return  "";
    }

    return $busConnection->{bus_attribute}->{$attribute}->{default};
}

#--------------------------------------------------
# @brief Returns true/false if a bus connection's, bus attribute's,
#        attribute's default value exists.
#
# @detail Bus connections have a list of attributes under the 'bus_attribute'
#         name which consists of attribute names with default values.
#         This method will determin if caller provided attribute ($attribute)
#         exits for the bus connection.
#
# @param[in] $self          - The global target object blob
# @param[in] $busConnection - A hande to a bus connection @see getFirstConnectionBus
# @param[in] $attribute     - The name of the attribute to determine if an
#                             default value exists
#--------------------------------------------------
sub isBusConnBusAttrDefined
{
    my $self          = shift;
    my $busConnection = shift;
    my $attribute     = shift;

    return defined($busConnection->{bus_attribute}->{$attribute}->{default});
}

## returns a pointer to an array of children target names
sub getTargetChildren
{
    my $self       = shift;
    my $target     = shift;
    my $target_ptr = $self->getTarget($target);

    ## this is an array
    return $target_ptr->{CHILDREN};
}

## returns an array of all child (including grandchildren) target names
sub getAllTargetChildren
{
    my $self   = shift;
    my $target = shift;
    my @children;

    my $targets = $self->getTargetChildren($target);
    if ($targets ne "")
    {
        for my $child (@$targets)
        {
            push @children, $child;
            my @more = $self->getAllTargetChildren($child);
            push @children, @more;
        }
    }

    return @children;
}

sub getEnumValue
{
    my $self     = shift;
    my $enumType = shift;
    my $enumName = shift;
    if (!defined($self->{enumeration}->{$enumType}->{$enumName}))
    {
        printf("ERROR: getEnumValue(%s,%s) | enumType not defined\n",
            $enumType, $enumName);
        $self->myExit(4);
    }
    return $self->{enumeration}->{$enumType}->{$enumName};
}

sub getEnumHash
{
    my $self     = shift;
    my $enumType = shift;
    my $enumName = shift;
    if (!defined($self->{enumeration}->{$enumType}))
    {
        printf("ERROR: getEnumValue(%s) | enumType not defined\n",
            $enumType);
            print Dumper($self->{enumeration});
        $self->myExit(4);
    }
    return $self->{enumeration}->{$enumType};
}

#--------------------------------------------------
# @brief Calculate and set the HUID for the given target
#
# @details This method will calulate the HUID for the given target. This can
#          be done in 1 of 2 ways:
#          1) The HUID is calculated using a sequential numeric value for the
#             type of the target.  For example if given target of type MC and
#             this is the first instance of this type, for this method, then
#             it's offset will be 0. The next encountered MC, will be offset
#             1 and-so-forth.
#          2) The second way, is the caller sends in an optional index to be
#             used as the offset.  For example, if given index 5, then the HUID
#             will be an offset of 5 and-so-forth.  This option gives the
#             caller control of the sequencing of the HUID.
#
# @param [in] $self - The global target object.
# @param [in] $target - The target to set the HUID for.
# @param [in] $sys - The system (TYPE SYS) target position.
# @param [in] $node - The node (TYPE NODE) target position.
# @param [in][optional] $index - An optional argument to be used as the HUID's
#                                offset, as opposed to one be calculated
#--------------------------------------------------
sub setHuid
{
    my $self   = shift;
    my $target = shift;
    my $sys    = shift;
    my $node   = shift;
    my $index  = shift;

    my $type    = $self->getType($target);
    my $type_id = $self->{enumeration}->{TYPE}->{$type};

    if ($type eq "" || $type eq "NA")
    {
        if (defined ($self->getAttribute($target,"BUS_TYPE")))
        {
            $type = $self->getAttribute($target,"BUS_TYPE");
            $type_id = $self->{enumeration}->{TYPE}->{$type};
            if ($type_id eq "") {$type_id = $self->{enumeration}->{BUS_TYPE}->{$type};}
        }
    }

    if ( ($type_id eq "") || ($type_id == 0 ) )
    {
        return;
    }

    # If caller supplied an index, then cache the index
    if ($index ne undef)
    {
        $self->{huid_idx}->{$type} = $index;
    }
    # If caller did not supply an index, then calculate one
    else
    {
        # If no index cached, then cache a 0 index to start with
        if (not defined($self->{huid_idx}->{$type}))
        {
            $self->{huid_idx}->{$type} = 0;
        }

        $index = $self->{huid_idx}->{$type};
    }

    # Format: SSSS NNNN TTTTTTTT iiiiiiiiiiiiiiii
    my $huid = sprintf("%01x%01x%02x%04x", $sys, $node, $type_id, $index);
    $huid = "0x" . uc($huid);

    $self->setAttribute($target, "HUID", $huid);
    $self->{huid_idx}->{$type}++;
    $self->log($target, "Setting HUID: $huid");
    $self->setMruid($target, $node);
}

sub setMruid
{
    my $self   = shift;
    my $target = shift;
    my $node   = shift;

    my $type          = $self->getType($target);
    my $mru_prefix_id = $self->{enumeration}->{MRU_PREFIX}->{$type};

    if ( (!defined $mru_prefix_id) ||
         ($mru_prefix_id eq "")    ||
         ($mru_prefix_id eq "0xFFFF") )
    {
        return;
    }

    my $index = 0;
    if (defined($self->{mru_idx}->{$node}->{$type}))
    {
        $index = $self->{mru_idx}->{$node}->{$type};
    }
    else { $self->{mru_idx}->{$node}->{$type} = 0; }

    my $mruid = sprintf("%s%04x", $mru_prefix_id, $index);
    $self->setAttribute($target, "MRU_ID", $mruid);
    $self->{mru_idx}->{$node}->{$type}++;
}

sub getMasterProc
{
    my $self = shift;
    return $self->{master_proc};
}

sub setMasterProc
{
    my $self = shift;
    my $target = shift;
    $self->{master_proc}=$target;
}

sub getSystemName
{
    my $self = shift;
    return $self->getAttribute("/".$self->{TOP_LEVEL}, "SYSTEM_NAME");
}

#--------------------------------------------------
## Utility function to process all of the existing
## types of dimm port attributes that we have
## supported.
sub getDimmPort
{
    my $self = shift;

    # input can be a dimm connector or a ddr target
    #  data exist on the dimm_port in the xml but
    #  we mirror it to the ddr while processing (somewhere...)
    my $targ = shift;

    # output values
    my $port_num = 0;

    #We will converge on MEM_PORT eventually, but
    # we are leaving in support for everything for now
    if (!$self->isBadAttribute($targ, "MEM_PORT"))
    {
        $port_num = $self->getAttribute($targ,"MEM_PORT");
    }
    elsif (!$self->isBadAttribute($targ, "CEN_MBA_PORT"))
    {
        $port_num = $self->getAttribute($targ,"CEN_MBA_PORT");
    }
    elsif( !$self->isBadAttribute($targ, "MBA_PORT"))
    {
        $port_num = $self->getAttribute($targ,"MBA_PORT");
    }
    else
    {
        print("ERROR: There is no memory port defined for target $targ\n");
        $self->myExit(4);
    }

    return $port_num;
}

#--------------------------------------------------
## Utility function to process all of the existing
## types of dimm port position attributes that we have
## supported.
sub getDimmPos
{
    my $self = shift;

    # input can be a dimm connector or a ddr target
    #  data exist on the dimm_port in the xml but
    #  we mirror it to the ddr while processing (somewhere...)
    my $targ = shift;

    # output values
    my $dimm_num = 0;

    #We will converge on POS_ON_MEM_PORT eventually, but
    # we are leaving in support for everything for now
    if (!$self->isBadAttribute($targ, "POS_ON_MEM_PORT"))
    {
        $dimm_num = $self->getAttribute($targ,"POS_ON_MEM_PORT");
    }
    elsif (!$self->isBadAttribute($targ, "CEN_MBA_DIMM"))
    {
        $dimm_num = $self->getAttribute($targ,"CEN_MBA_DIMM");
    }
    elsif( !$self->isBadAttribute($targ, "MBA_DIMM"))
    {
        $dimm_num = $self->getAttribute($targ,"MBA_DIMM");
    }
    else
    {
        print("ERROR: CEN_MBA_DIMM not defined for dimm $targ\n");
        $self->myExit(4);
    }

    return $dimm_num;
}

sub myExit
{
    my $self      = shift;
    my $exit_code = shift;
    if ($exit_code eq "") { $exit_code = 0; }
    $self->{errorsExist} = 1;
    if ($self->{force} == 0)
    {
        exit($exit_code);
    }
}

sub log
{
    my $self   = shift;
    my $target = shift;
    my $msg    = shift;
    if ($self->{debug})
    {
        print "DEBUG: ($target) $msg\n";
    }
}
sub writeReport
{
    my $self   = shift;
    my $msg    = shift;
    $self->{report_log}=$self->{report_log}.$msg;
}
sub writeReportFile
{
    my $self   = shift;
    open(R,">$self->{report_filename}") ||
          die "Unable to create file: ".$self->{report_filename};
    print R $self->{report_log};
    close R;
}


###############################################################################
# Useful Utilites
###############################################################################

#--------------------------------------------------
# @brief This will print ALL targets and their hiearchy from the given file.
#        Run as a stand alone utility.
#
# @param[in] $self - The global target object
# @param[in] $filename - The XML file to be processed
# @param[in] $target   - The target to explore children of, if given, else
#                        will start with the top level target
#--------------------------------------------------
sub printFullTargetHierarchy
{
    my $self = shift;
    my $filename = shift;
    my $target = shift;

    if ($filename eq "")
    {
        die "Must provide an XML file to process.\n";
    }

    # Only want to load the XML file once.
    state $isXmlFileLoaded = 0;
    if (0 == $isXmlFileLoaded )
    {
        $self->__loadAndBuildMrwHierarchy__($filename);
        $isXmlFileLoaded = 1;
    }

    # If no target given, use the top level target
    if ($target eq undef)
    {
        $target = "/" . $self->getTopLevel();
        print "$target \n";
    }

    # Iterate over the children
    my $children = $self->getTargetChildren($target);
    foreach my $child (@{ $children })
    {
        print "$child \n";
        $self->printFullTargetHierarchy($filename, $child);
    }
} # end sub printFullTargetHierarchy


sub __loadAndBuildMrwHierarchy__
{
    my $self = shift;
    my $filename = shift;

    $XML::Simple::PREFERRED_PARSER = 'XML::Parser';
    print "Loading MRW XML: $filename\n";
    $self->{xml} =
    XMLin($filename,forcearray => [ 'child_id', 'hidden_child_id', 'bus',
                                    'property', 'field', 'attribute',
                                    'enumerator' ]);

    if (defined($self->{xml}->{'enumerationTypes'}))
    {
        $self->{xml_version} = 1;
    }

    $self->buildHierarchy();
}



###############################################################################
# The end of the perl module
#
# @brief The end of the executable elements of this PERL module
#
# @details Don't forget to return the true value (1) from this file
###############################################################################
1;


###############################################################################
# Perl documentation
#
# @brief The beginning of the Perl documentation
#
# @details do `perldoc Targets.pm` to see the Perl documentation
###############################################################################

=head1 NAME

Targets

=head1 SYNOPSIS

    use Targets;

    my $targets = Targets->new;
    $targets->loadXML("myfile.xml");
    foreach my $target ( sort keys %{ $targets->getAllTargets() } ) {
        ## do stuff with targets
    }

    $targets->printXML( $file_handle, "top" );

=head1 DESCRIPTION

C<Targets> is a class that consumes XML generated by ServerWiz2.  The XML
describes a POWER system topology including nodes, cards, chips, and busses.

=head1 OVERVIEW

A simple example of a ServerWiz2 topology would be:

=over 4

=item Topology Example:

   -system
      -node
         -motherboard
           -processor
           -pcie card
               - daughtercard
                  - memory buffer
                  - dimms

=back

Targets->loadXML("myfile.xml") reads this topology and creates 2 data
structures.  One data structure simply represents the hierarchical system
topology.  The other data structure represents the hierarchical structure
that hostboot expects (affinity path).

Unlike hostboot, everything in ServerWiz2 is represented as a target.
For example, FSI and I2C units are targets under the processor that have a
bus type and therefore allow connections to be made.

=head1 CONSTRUCTOR

=over 4

=item new ()

There are no arguments for the constructor.

=back

=head1 METHODS

C<TARGET> is a pointer to data structure containing all target information.
C<TARGET_STRING> is the hierarchical target string used as key for data
structure.  An example for C<TARGET_STRING> would be:
C</sys-0/node-0/motherboard-0/dimm-0>

=over 4

=item loadXml (C<FILENAME>)

Reads ServerWiz2 XML C<FILENAME> and stores into a data structure for
manipulation and printing.

=item getTargetInstanceHandle ( )

Returns a handle to the target instances.

=item getTopLevel ( )

Returns the top level target.

=item removeTarget(C<TARGET_STRING>)

Removes the given target from the data structure (C<TARGET>)

=item getTarget(C<TARGET_STRING>)

Returns pointer to data structure (C<TARGET>)

=item getAllTargets(C<TARGET_STRING>)

Returns array with all existing target data structures

=item getTargetParent(C<TARGET_STRING>)

Returns C<TARGET_STRING> of parent target

=item getNumConnections(C<TARGET_STRING>)

Returns the number of bus connections to this target

=item getFirstConnectionDestination(C<TARGET_STRING>)

Returns the target string of the first target found connected to
C<TARGET_STRING>.  This is useful because many busses are guaranteed
to only have one connection because they are point to point.

=item getFirstConnectionBus(C<TARGET_STRING>)

Returns the data structure of the bus of the first target found connected to
C<TARGET_STRING>.  The bus data structure is also a target with attributes.

=item getConnectionDestination(C<TARGET_STRING>,C<INDEX>)

Returns the target string of the C<INDEX> target found connected to
C<TARGET_STRING>.

=item getConnectionBus(C<TARGET_STRING>,C<INDEX>)

Returns the data structure of the C<INDEX> bus target found connected to
C<TARGET_STRING>.

=item getConnectionBusParent(C<TARGET_STRING>,C<INDEX>)

Returns C<PARENT_TARGET_STRING> of the parent target for the bus target found
connected to C<TARGET_STRING>

=item findEndpoint(C<TARGET_STRING>,C<BUS_TYPE>,C<ENDPOINT_MRW_TYPE>)

Searches through all connections to C<TARGET_STRING>
for a endpoint C<MRW_TYPE> and C<BUS_TYPE>

=item getBusType(C<TARGET_STRING>)

Returns the BUS_TYPE attribute of (C<TARGET_STRING>).  An example is I2C

=item getType(C<TARGET_STRING>)

Returns the TYPE attribute of (C<TARGET_STRING>).
Examples are PROC and MEMBUF.

=item getMrwType(C<TARGET_STRING>)

Returns the MRW_TYPE attribute of (C<TARGET_STRING>).
Examples are CARD and PCI_CONFIG.  This
is an extension to the TYPE attribute and are types that hostboot does
not care about.

=item getTargetType(C<TARGET_STRING>)

Returns the target type id of (C<TARGET_STRING>).
This is not the TYPE attribute.  This is the
<id> from target_types.xml.  Examples are unit-pci-power8 and enc-node-power8.

=item isBadAttribute(C<TARGET_STRING>,C<ATTRIBUTE_NAME>)

Tests where attribute (C<ATTRIBUTE_NAME>) has been set in
target (C<TARGET_STRING>).  Returns true if attribute is undefined or empty
and false if attribute is defined and not empty.

=item getAttribute(C<TARGET_STRING>,C<ATTRIBUTE_NAME>)

Returns the value of attribute C<ATTRIBUTE_NAME> in target C<TARGET_STRING>.

=item renameAttribute(C<TARGET_STRING>,C<ATTRIBUTE_OLDNAME>,
C<ATTRIBUTE_OLDNAME>)

Renames attribute C<ATTRIBUTE_OLDNAME> to C<ATTRIBUTE_NEWNAME> in target
C<TARGET_STRING>.

=item setAttribute(C<TARGET_STRING>,C<ATTRIBUTE_NAME>,C<VALUE>)

Sets attribute C<ATTRIBUTE_NAME> of target C<TARGET_STRING> to value C<VALUE>.

=item setAttributeField(C<TARGET_STRING>,C<ATTRIBUTE_NAME>,C<FIELD>,C<VALUE>)

Sets attribute C<ATTRIBUTE_NAME> and field C<FIELD> of target C<TARGET_STRING>
to value C<VALUE>.  This is for complex attributes.

=item getBusAttribute(C<TARGET_STRING>,C<INDEX>,C<ATTRIBUTE_NAME>)

Gets the attribute C<ATTRIBUTE_NAME> from bus C<TARGET_STRING> bus number
C<INDEX>.

=item isBusAttributeDefined(C<TARGET_STRING>,C<INDEX>.C<ATTRIBUTE_NAME>)

Looks for a specific attribute and returns if it exists or not

=item getTargetChildren(C<TARGET_STRING>)

Returns an array of target strings representing all the children of target
C<TARGET_STRING>.

=item getAllTargetChildren(C<TARGET_STRING>)

Returns an array of target strings representing all the children of target
C<TARGET_STRING>, including grandchildren and below as well.

=item getEnumValue(C<ENUM_TYPE>,C<ENUM_NAME>)

Returns the enum value of type C<ENUM_TYPE> and name C<ENUM_NAME>.  The
enumerations are also defined in ServerWiz2 XML output and are directly
copied from attribute_types.xml.

=item getMasterProc()

Returns the target string of the master processor.

=item myExit(C<EXIT_NUM>)

Calls exit(C<EXIT_NUM>) when force flag is not set.

=item log(C<TARGET_STRING>,C<MESSAGE>)

Prints to stdout log message is debug mode is turned on.


=back

=head1 CREDITS

Norman James <njames@us.ibm.com>

=cut
