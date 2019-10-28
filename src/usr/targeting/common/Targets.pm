# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/Targets.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2019
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

# Although these are duplicated in the hash below, I left these here as
# to not break other scripts that use this Perl module.
use constant
{
    PERVASIVE_PARENT_CORE_OFFSET => 32,
    PERVASIVE_PARENT_EQ_OFFSET => 32,
    PERVASIVE_PARENT_XBUS_OFFSET => 6,
    PERVASIVE_PARENT_OBUS_OFFSET => 9,
    PERVASIVE_PARENT_PEC_OFFSET => 13,
    PERVASIVE_PARENT_PHB_OFFSET => 13,
    PERVASIVE_PARENT_MC_OFFSET => 7,
    PERVASIVE_PARENT_MI_OFFSET => 7,
    NUM_PROCS_PER_GROUP => 4,
    MAX_PROCS_PER_SOCKET => 2,
    DIMMS_PER_PROC => 64,  # Cumulus
    DIMMS_PER_MBA => 4,# Cumulus
    MBA_PER_MEMBUF => 2,
    MAX_DIMMS_PER_MBA_PORT => 2,
    CORES_PER_EQ => 4,
    PAU_PER_PAUC => 2,
};

# Not only does this value control the PERVASIVE_PARENT start value,
# it also controls the starting value of the CHIPLET_ID.
# These values are just duplicates of above, but this hash allows for
# dynamic coding
our %PERVASIVE_PARENT_OFFSET =
(
    EQ    => 32,
    FC    => 32,
    CORE  => 32,
    MC    => 12,
    MI    => 12,
    MCC   => 12,
    OMI   => 12,
    OMIC  => 12,
    PAUC  => 16,
    IOHS  => 24,
    PAU   => 16,
    OBUS  => 9,
);

# The maximum number of target instances per parent
# This value has an effect on REL_POS, AFFINITY_PATH and PHYS_PATH
my %MAX_INST_PER_PARENT =
(
    PROC => 8, # Number of PROCs per NODE
    EQ   => 8, # Number of EQs per PROC
    FC   => 2, # Number of FCs per EQ
    CORE => 2, # Number of COREs per FC

    MC   => 4, # Number of MCs per PROC
    MI   => 1, # Number of MIs per MC
    MCC  => 2, # Number of MCCs per MI
    OMI  => 2, # Number of OMIs per MCC/OMIC (has two parents 'a nuclear family')
    OCMB => 1, # Number of CHIP_OCMBs per OMI
    PMIC => 2, # Number of PMICs per OCMB
    MEM_PORT => 1, # Number of MEM_PORTs per OCM
    DIMM => 1, # Number of DIMMs per MEM_PORT
    PMIC => 2, # Number of PMICs per DIMM

    OMIC => 2, # Number of OMICs per MC

    PAUC => 4, # Number of PAUCs per PROC
    IOHS => 2, # Number of IOHSs per PAUC
    PAU  => 1, # Number of PAUs per IOHS
);

# The maximum number of target instances per PROC.  These can be calculated
# from the values of MAX_INST_PER_PARENT.
# These values control HUID, PARENT_PERVASIVE, ORDINAL_ID, FAPI_POS values
our %MAX_INST_PER_PROC = (
    "EQ"            => $MAX_INST_PER_PARENT{EQ},
    "FC"            => $MAX_INST_PER_PARENT{EQ} * $MAX_INST_PER_PARENT{FC},
    "CORE"          => $MAX_INST_PER_PARENT{EQ} * $MAX_INST_PER_PARENT{FC} *
                       $MAX_INST_PER_PARENT{CORE},

    "MC"            => $MAX_INST_PER_PARENT{MC},
    "MI"            => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI},
    "MCC"           => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC},
    "OMI"           => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC} * $MAX_INST_PER_PARENT{OMI},
    "OCMB_CHIP"     => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC} * $MAX_INST_PER_PARENT{OMI} *
                       $MAX_INST_PER_PARENT{OCMB},
    "MEM_PORT"      => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC} * $MAX_INST_PER_PARENT{OMI} *
                       $MAX_INST_PER_PARENT{OCMB} * $MAX_INST_PER_PARENT{MEM_PORT},
    "DDIMM"         => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC} * $MAX_INST_PER_PARENT{OMI} *
                       $MAX_INST_PER_PARENT{OCMB} * $MAX_INST_PER_PARENT{MEM_PORT} *
                       $MAX_INST_PER_PARENT{DIMM},
    "PMIC"          => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{MI} *
                       $MAX_INST_PER_PARENT{MCC} * $MAX_INST_PER_PARENT{OMI} *
                       $MAX_INST_PER_PARENT{OCMB} * $MAX_INST_PER_PARENT{MEM_PORT} *
                       $MAX_INST_PER_PARENT{DIMM} * $MAX_INST_PER_PARENT{PMIC},

    "OMIC"          => $MAX_INST_PER_PARENT{MC} * $MAX_INST_PER_PARENT{OMIC},

    "PAUC"          => $MAX_INST_PER_PARENT{PAUC},
    "IOHS"          => $MAX_INST_PER_PARENT{PAUC} * $MAX_INST_PER_PARENT{IOHS},
    "PAU"           => $MAX_INST_PER_PARENT{PAUC} * $MAX_INST_PER_PARENT{IOHS} * $MAX_INST_PER_PARENT{PAU},
                       # For PAU, only 6 used, PAU1 and PAU2 not used

    "ABUS"          => 3,
    "XBUS"          => 3,
    "OBUS"          => 4,
    "PHB"           => 6, # PHB is same as PCIE
    "PEC"           => 2, # PEC is same as PBCQ
    "PCIESWITCH"    => 2,
    "MBA"           => 16,
    "PPE"           => 51, # Only 21, but they are sparsely populated
    "PERV"          => 56, # Only 39, but they are sparsely populated
    "CAPP"          => 2,
    "SBE"           => 1,
    "OBUS_BRICK"    => 12,
    "OCC"           => 1,
    "NV"            => 6,
    "NX"            => 1,
    "MEMBUF"        => 8,
    "SMPGROUP"      => 8,
);

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
        version         => 0,
        xml          => undef,
        data         => undef,
        targeting    => undef,
        enumerations => undef,
        master_proc  => undef,
        UNIT_COUNTS  => undef,
        huid_idx     => undef,
        mru_idx      => undef,
        xml_version  => 0,
        errorsExist  => 0,
        NUM_PROCS    => 0,
        TOP_LEVEL    => "",
        TOP_LEVEL_HANDLE    => undef,
        TOPOLOGY     => undef,
        report_log   => "",
        vpd_num      => 0,
        dimm_tpos    => 0,
        MAX_MC       => 0,
        MAX_MI       => 0,
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
    $self->buildAffinity();
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

    print $fh "\t<id>" . $target_id . "</id>\n";
    if($self->getTargetType($target) eq 'unit-clk-slave')
    {
        if($target_TYPE eq 'SYSREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-sysclk-slave"."</type>\n";
        }
        elsif($target_TYPE eq 'MFREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-mfclk-slave"."</type>\n";
        }
    }
    elsif($self->getTargetType($target) eq 'unit-clk-master')
    {
        if($target_TYPE eq 'SYSREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-sysclk-master"."</type>\n";
        }
        elsif($target_TYPE eq 'MFREFCLKENDPT')
        {
            print $fh "\t<type>"."unit-mfclk-master"."</type>\n";
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
        if ($val ne "")
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



##########################################################
## traces busses and builds affinity hierarchy
## HOSTBOOT expected hierarchy: sys/node/proc/<unit>
## This function also sets the common attributes for all the targets
## Common attributes include:
##  - FAPI_NAME
##  - PHYS_PATH
##  - AFFINITY_PATH
##  - ORDINAL_ID
##  - HUID
my $multiNode = 0;
sub buildAffinity
{
    my $self = shift;
    my $node            = -1;
    my $proc            = -1;
    my $tpm             = -1;
    my $ucd             = -1;
    my $bmc             = -1;
    my $mcc             = -1;
    my $omi             = -1;
    my $ocmb            = -1;
    my $mem_port        = -1;
    my $dimm            = -1;
    my $pmic            = -1;
    my $sys_phys        = "";
    my $node_phys       = "";
    my $node_aff        = "";
    my $proc_fapi       = "";
    my $sys_pos         = 0; # There is always a single system target
    my $num_mc          = 0 ;
    my @tpm_list        = (); # The list of TPMs found on the system
    my @ucd_list        = (); # The list of UCDs found on the system

    $multiNode = 0;

    $self->{membuf_inst_num}=0;

    ## count children target types
    foreach my $target (sort keys %{ $self->{data}->{TARGETS} })
    {
        my $children = $self->getTargetChildren($target);
        if ($children ne "") {
             foreach my $child (@{ $children })
             {
                  my $type = $self->getType($child);
                  $self->{UNIT_COUNTS}->{$target}->{$type}++;
             }
        }
    }

    foreach my $target (sort keys %{ $self->{data}->{TARGETS} })
    {
        my $target_ptr  = $self->{data}->{TARGETS}{$target};
        my $type        = $self->getType($target);
        my $type_id     = $self->getEnumValue("TYPE", $type);
        my $pos         = $self->{data}->{TARGETS}{$target}{TARGET}{position};

        if ($type_id eq "") { $type_id = 0; }

        if ($type eq "SYS")
        {
            $proc = -1;
            $node = -1;
            $self->{targeting}{SYS}[0]{KEY} = $target;

            #SYS target has PHYS_PATH and AFFINITY_PATH defined in the XML
            #Also, there is no HUID for SYS
            $self->setAttribute($target,"FAPI_NAME",$self->getFapiName($type));
            $self->setAttribute($target,"FAPI_POS",      $sys_pos);
            $self->setAttribute($target,"ORDINAL_ID",    $sys_pos);
            $sys_phys = "sys-0"; # just hardcode this as it does not change
        }
        elsif ($type eq "NODE")
        {
            $proc                    = -1;
            $self->{membuf_inst_num} = 0;
            $node++;

            if($node > 0)
            {
                $multiNode = 1;
                #reset the dimm index number across nodes
                $self->{dimm_tpos} = 0;
            }
            else
            {
                $multiNode = 0;
            }

            $node_phys = "physical:".$sys_phys."/node-$node";
            $node_aff  = "affinity:".$sys_phys."/node-$node";

            $self->{targeting}{SYS}[0]{NODES}[$node]{KEY} = $target;

            $self->setHuid($target, $sys_pos, $node);
            $self->setAttribute($target, "FAPI_NAME",$self->getFapiName($type));
            $self->setAttribute($target, "FAPI_POS",      $node);
            $self->setAttribute($target, "PHYS_PATH",     $node_phys);
            $self->setAttribute($target, "AFFINITY_PATH", $node_aff);

            if($pos > 0) #to handle control node in Fleetwood
            {
                $pos = $pos - 1;
            }
            $self->setAttribute($target, "ORDINAL_ID",    $pos);

        } # end elsif ($type eq "NODE")
        elsif ($type eq "TPM")
        {
            $tpm++;
            push @tpm_list, $target;

            $self->{targeting}{SYS}[0]{NODES}[$node]{TPMS}[$tpm]{KEY} = $target;

            my $tpm_phys = $node_phys . "/tpm-$tpm";

            $self->setHuid($target, $sys_pos, $node);
            $self->setAttribute($target, "FAPI_NAME",$self->getFapiName($type));
            $self->setAttribute($target, "FAPI_POS",      $pos);
            # NOTE: Affinity Path is set after this loop so that all procs have
            #       already been dealt with.
            $self->setAttribute($target, "PHYS_PATH",     $tpm_phys);
            $self->setAttribute($target, "ORDINAL_ID",    $tpm);
        } # end elsif ($type eq "TPM")
        elsif ($type eq "POWER_SEQUENCER")
        {
            my $target_type = $self->getTargetType($target);

            # Strip off the chip- part of the target type name
            $target_type =~ s/chip\-//g;

            # Currently only UCD9090 and UCD90120A on FSP systems are supported.
            # Skip over all other UCD types.
            if (($target_type ne "UCD9090")
               && ($target_type ne "UCD90120A"))
            {
                next;
            }

            $ucd++;
            push(@ucd_list, $target);

            $self->{targeting}{SYS}[0]{NODES}[$node]{UCDS}[$ucd]{KEY} = $target;

            my $ucd_phys = $node_phys . "/power_sequencer-$ucd";

            $self->setHuid($target, $sys_pos, $node);
            # NOTE: Affinity Path is set after this loop so that all procs have
            #       already been dealt with.
            $self->setAttribute($target, "PHYS_PATH",     $ucd_phys);
            $self->setAttribute($target, "ORDINAL_ID",    $ucd);
            # @TODO RTC 201991: remove these overrides when the MRW is updated
            $self->setAttribute($target, "CLASS", "ASIC");
            $self->deleteAttribute($target, "POSITION");
            $self->deleteAttribute($target, "FRU_ID");
        } # end elsif ($type eq "POWER_SEQUENCER")
        elsif ($type eq "MCC")
        {
            $mcc++;

            # For a given proc, there are 2 MCs, 4 MIs, 8 MCCs, and 16 OMIs
            # To get the corresponding proc, MC, or MI number for a given MCC
            # divide the MCC number by the number of MCCs per unit, then mod 2
            # to get the relative path in terms of 0 or 1
            my $numOfMccsPerProc = $MAX_INST_PER_PROC{$type};
            my $numOfMccsPerMc = 4;
            my $numOfMccsPerMi = 2;
            my $proc_num = ($mcc / $numOfMccsPerProc) % 2;
            my $mc_num = ($mcc / $numOfMccsPerMc) % 2;
            my $mi_num = ($mcc / $numOfMccsPerMi) % 2;
            my $mcc_num = $mcc % 2;
            my $path = "/proc-$proc_num/mc-$mc_num/mi-$mi_num/mcc-$mcc_num";
            my $mcc_aff = $node_aff . $path;
            my $mcc_phys = $node_phys . $path;
            $self->setAttribute($target, "AFFINITY_PATH", $mcc_aff);
            $self->setAttribute($target, "PHYS_PATH", $mcc_phys);

            $self->setAttribute($target, "REL_POS", $mcc_num);
            my $pos = $self->getAttribute($target, "CHIP_UNIT");
            my $fapi_pos = $pos + $numOfMccsPerProc * $proc_fapi;
            $self->setAttribute($target, "FAPI_POS", $fapi_pos);
            $self->setAttribute($target, "ORDINAL_ID", $mcc);
        }
        elsif ($type eq "OMI")
        {
            # We only want OMIs with MCC parent, skip over the ones with OMIC parent
            my $parent = $self->getTargetParent($target);
            my $parent_type = $self->getType($parent);
            if ($parent_type eq "MCC")
            {
                $omi++;

                # Same logic for MCC, but for OMI instead
                my $numOfOmisPerProc = $MAX_INST_PER_PROC{$type};
                my $numOfOmisPerMc = 8;
                my $numOfOmisPerMi = 4;
                my $numOfOmisPerMcc = 2;
                my $proc_num = ($omi / $numOfOmisPerProc) % 2;
                my $mc_num = ($omi / $numOfOmisPerMc) % 2;
                my $mi_num = ($omi / $numOfOmisPerMi) % 2;
                my $mcc_num = ($omi / $numOfOmisPerMcc) % 2;
                my $omi_num = $omi % 2;
                my $path = "/proc-$proc_num/mc-$mc_num/mi-$mi_num/mcc-$mcc_num/omi-$omi_num";
                my $omi_aff = $node_aff . $path;
                my $omi_phys = $node_phys . $path;
                $self->setAttribute($target, "AFFINITY_PATH", $omi_aff);
                $self->setAttribute($target, "PHYS_PATH", $omi_phys);

                my $pos = $self->getAttribute($target, "CHIP_UNIT");
                my $fapi_pos = $pos + $numOfOmisPerProc * $proc_fapi;
                $self->setAttribute($target, "FAPI_POS", $fapi_pos);
                $self->setAttribute($target, "ORDINAL_ID", $omi);
            }
        }
        elsif ($type eq "BMC")
        {
            $bmc++;

            $self->{targeting}{SYS}[0]{NODES}[$node]{BMC}[$bmc]{KEY} = $target;
            my $bmc_phys = $node_phys . "/bmc-$bmc";
            my $bmc_aff  = $node_aff  . "/bmc-$bmc";

            $self->setHuid($target, $sys_pos, $bmc);
            $self->setAttribute($target, "FAPI_NAME",$self->getFapiName($type));
            $self->setAttribute($target, "FAPI_POS",      $pos);
            $self->setAttribute($target, "PHYS_PATH",     $bmc_phys);
            $self->setAttribute($target, "AFFINITY_PATH", $bmc_aff);
            $self->setAttribute($target, "ORDINAL_ID",    $bmc);

        }
        elsif ($type eq "OCMB_CHIP")
        {
            # Ocmbs are not in order, so we take the parent dimm's POSITION as
            # our current ocmb number
            # Ex. dimm19 = ocmb19
            my $parent = $self->getTargetParent($target);
            $ocmb = $self->getAttribute($parent, "POSITION");
            $self->{targeting}{SYS}[0]{NODES}[$node]{OCMB_CHIPS}[$ocmb]{KEY} = $target;
            $self->setHuid($target, $sys_pos, $node);

            my $ocmb_phys = $node_phys . "/ocmb_chip-$ocmb";

            # Find the OMI bus connection to determine target values
            my $proc_num = -1;
            my $mc_num = -1;
            my $mi_num = -1;
            my $mcc_num = -1;
            my $omi_num = -1;
            my $conn = $self->findConnectionsByDirection($target, "OMI", "", 1);

            my $omi_chip_unit = -1;
            if ($conn ne "")
            {
                foreach my $conn (@{$conn->{CONN}})
                {
                    my $source = $conn->{SOURCE};
                    if ($source =~ /omic/i)
                    {
                        next;
                    }
                    my @targets = split(/\//, $source);
                    # Split the source into proc#, mc#, mi#, mcc#, omi#
                    # Source example:
                    # /sys-#/node-#/Pallid-#/proc_socket-#/Hopper-#/p9_axone/mc#/mi#/mcc#/omi#
                    foreach my $target (@targets)
                    {
                        $target =~ s/\D//g;
                    }

                    # Splitting on "/" makes the first array index empty string
                    # so every value here is shifted over by 1
                    # There are only ever two targets per parent in this case,
                    # so to get the relative positions for each target, we take
                    # mod two of the source value
                    $proc_num = $targets[4] % 2;
                    $mc_num = $targets[7] % 2;
                    $mi_num = $targets[8] % 2;
                    $mcc_num = $targets[9] % 2;

                    # omi_num indicates the chip_unit of the corresponding omi
                    $omi_num = $targets[10];
                    $omi_chip_unit = $omi_num;
                    $omi_num %= 2;
                }
            }

            my $ocmb_aff = $node_aff . "/proc-$proc_num/mc-$mc_num/mi-$mi_num/mcc-$mcc_num/omi-$omi_num/ocmb_chip-0";
            $self->setAttribute($target, "AFFINITY_PATH", $ocmb_aff);
            $self->setAttribute($target, "PHYS_PATH", $ocmb_phys);

            # The standard fapi_pos calculation uses the relative position to
            # the proc instead of omi_chip_unit. However, in this case, there is
            # no direct way to get the relative position to the proc. The
            # relationship between ocmb and omi is 1:1, so we take the chip unit
            # of the corresponding omi as the relative position to the proc
            my $fapi_pos = $omi_chip_unit + ($MAX_INST_PER_PROC{$type} * $proc_num);
            $self->setAttribute($target, "FAPI_POS", $fapi_pos);

            my $ocmb_num = $fapi_pos;
            # The norm for FAPI_NAME has a two digit number at the end
            if ($fapi_pos < 10)
            {
                $ocmb_num = "0$fapi_pos";
            }

            $self->setAttribute($target, "MRU_ID", "0x00060000");
            $self->setAttribute($target, "POSITION", $ocmb);

            # chipunit:system:node:slot:position
            $self->setAttribute($target, "FAPI_NAME", "ocmb:k0:n0:s0:p$ocmb_num");

            $self->setAttribute($target, "REL_POS", "0");

            my $fapi_name = "FAPI_I2C_CONTROL_INFO";
            my $master_path = "physical:sys-0/node-0/proc-$proc_num";
            $self->setAttributeField($target, $fapi_name, "i2cMasterPath", $master_path);

            my $eeprom_name = "EEPROM_VPD_PRIMARY_INFO";
            $self->setAttributeField($target, $eeprom_name, "i2cMasterPath", $master_path);
            $self->setAttributeField($target, $eeprom_name, "chipCount", "0x01");
        }
        elsif ($type eq "MEM_PORT")
        {
            my $parent = $self->getTargetParent($target);
            my $ocmb_num = $self->getAttribute($parent, "POSITION");
            my $ocmb_affinity = $self->getAttribute($parent, "AFFINITY_PATH");
            $self->setAttribute($target, "AFFINITY_PATH", "$ocmb_affinity/mem_port-0");
            my $ocmb_phys = $self->getAttribute($parent, "PHYS_PATH");
            $self->setAttribute($target, "PHYS_PATH", "$ocmb_phys/mem_port-0");
            $self->setHuid($target, $sys_pos, $node);
            $self->deleteAttribute($target, "EXP_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT");

            $self->{targeting}{SYS}[0]{NODES}[$node]{OCMB_CHIPS}[$ocmb_num]{MEM_PORTS}[0]{KEY} = $target;
        }
        # Witherspoon has its own DIMM parsing mechanism so don't want to
        # interfere with it
        elsif ($type eq "DIMM" && $self->getTargetType($target) eq "lcard-dimm-ddimm")
        {
            # Dimms are not posted in order, so need to get the dimm's position
            $dimm = $self->getAttribute($target, "POSITION");

            # Find the OMI bus connection to determine target values
            my $proc_num = -1;
            my $mc_num = -1;
            my $mi_num = -1;
            my $mcc_num = -1;
            my $omi_num = -1;
            my $conn = $self->findConnectionsByDirection($target, "OMI", "", 1);

            my $omi_chip_unit = -1;
            if ($conn ne "")
            {
                foreach my $conn (@{$conn->{CONN}})
                {
                    my $source = $conn->{SOURCE};
                    my @targets = split(/\//, $source);

                    if ($source =~ /omic/i)
                    {
                        next;
                    }

                    # Split the source into proc#, mc#, mi#, mcc#, omi#
                    # Source example:
                    # /sys-#/node-#/Pallid-#/proc_socket-#/Hopper-#/p9_axone/mc#/mi#/mcc#/omi#
                    foreach my $target (@targets)
                    {
                        $target =~ s/\D//g;
                    }

                    # Splitting on "/" makes the first array index empty string
                    # so every value here is shifted over by 1
                    # There are only ever two targets per parent in this case,
                    # so to get the relative positions for each target, we take
                    # mod two of the source value
                    $proc_num = $targets[4] % 2;
                    $mc_num = $targets[7] % 2;
                    $mi_num = $targets[8] % 2;
                    $mcc_num = $targets[9] % 2;
                    $omi_num = $targets[10];

                    # omi_num indicates the chip_unit of the corresponding omi
                    $omi_chip_unit = $omi_num;
                    $omi_num %= 2;
                } # end foreach my $conn (@{$conn->{CONN}})
            } # end if ($conn ne "")

            $self->{targeting}{SYS}[0]{NODES}[$node]{DIMMS}[$dimm]{KEY} = $target;
            $self->setAttribute($target, "PHYS_PATH", $node_phys . "/dimm-$dimm");
            $self->setHuid($target, $sys_pos, $node);

            # The standard fapi_pos calculation uses the relative position to
            # the proc instead of omi_chip_unit. However, in this case, there is
            # no direct way to get the relative position to the proc. The
            # relationship between dimm and omi is 1:1, so we take the chip unit
            # of the corresponding omi as the relative position to the proc
            my $fapi_pos = $omi_chip_unit + ($MAX_INST_PER_PROC{"DDIMM"} * $proc_num);
            $self->setAttribute($target, "FAPI_POS", $fapi_pos);
            $self->setAttribute($target, "ORDINAL_ID", $dimm);
            $self->setAttribute($target, "REL_POS", 0);
            $self->setAttribute($target, "VPD_REC_NUM", $dimm);

            my $dimm_num = $fapi_pos;
            if ($fapi_pos < 10)
            {
                $dimm_num = "0$fapi_pos";
            }
            # chipunit:slot:node:system:position
            $self->setAttribute($target, "FAPI_NAME", "dimm:k0:n0:s0:p$dimm_num");

            my $ocmb_num = 0;
            my $mem_num = 0;
            $dimm_num = 0;
            my $dimm_aff = $node_aff . "/proc-$proc_num/mc-$mc_num/mi-$mi_num/mcc-$mcc_num/omi-$omi_num/ocmb_chip-$ocmb_num/mem_port-$mem_num/dimm-$dimm_num";
            $self->setAttribute($target, "AFFINITY_PATH", $dimm_aff);

            my $eeprom_name = "EEPROM_VPD_PRIMARY_INFO";
            $self->setAttributeField($target, $eeprom_name, "chipCount", "0x01");
            $self->setAttributeField($target, $eeprom_name, "i2cMasterPath", "physical:sys-0/node-0/proc-$proc_num");
        } # end elsif ($type eq "DIMM" && $self->getTargetType($target) ...
        elsif ($type eq "PMIC")
        {
            # Pmics are not in order, so we take the parent dimm's
            # POSITION * 4 as our current pmic number, adding one
            # if it's a pmic1, two if it's a pmic2, three if it's a
            # pmic3
            # Ex. on a pmic0, dimm19 = pmic76
            # Ex. on a pmic1, dimm19 = pmic77
            # Ex. on a pmic2, dimm19 = pmic78
            # Ex. on a pmic3, dimm19 = pmic79
            my $instance_name = $self->getInstanceName($target);
            my $parent = $self->getTargetParent($target);
            my $parent_fapi_pos = $self->getAttribute($parent, "FAPI_POS");
            my $parent_pos = $self->getAttribute($parent, "POSITION");
            my $position = $self->getAttribute($target, "POSITION");
            $pmic = ($parent_pos * 4) + $position;

            $self->{targeting}{SYS}[0]{NODES}[$node]{PMICS}[$pmic]{KEY} = $target;
            $self->setAttribute($target, "PHYS_PATH", $node_phys . "/pmic-$pmic");
            $self->setAttribute($target, "ORDINAL_ID", $pmic);
            $self->setAttribute($target, "REL_POS", $pmic % 2);

            # Same logic with the position, but with FAPI_POS instead
            my $fapi_pos = ($parent_fapi_pos * 4) + $position;
            $self->setAttribute($target, "FAPI_POS", $fapi_pos);
            $self->setAttribute($target, "POSITION", $pmic);
            $self->setHuid($target, $sys_pos, $node);

            my $pmic_num = $fapi_pos;
            # The norm for FAPI_NAME has a two digit number at the end
            if ($fapi_pos < 10)
            {
                $pmic_num = "0$fapi_pos";
            }
            # chipunit:slot:node:system:position
            $self->setAttribute($target, "FAPI_NAME", "pmic:k0:n0:s0:p$pmic_num");

            # Find the OMI bus connection to determine target values
            my $proc_num = -1;
            my $mc_num = -1;
            my $mi_num = -1;
            my $mcc_num = -1;
            my $omi_num = -1;
            my $conn = $self->findConnectionsByDirection($self->getTargetParent($target), "OMI", "", 1);
            if ($conn ne "")
            {
                foreach my $conn (@{$conn->{CONN}})
                {
                    my $source = $conn->{SOURCE};
                    my @targets = split(/\//, $source);
                    # Split the source into proc#, mc#, mi#, mcc#, omi#
                    # Source example:
                    # /sys-#/node-#/Pallid-#/proc_socket-#/Hopper-#/p9_axone/mc#/mi#/mcc#/omi#
                    if ($source =~ /omic/i)
                    {
                        next;
                    }

                    foreach my $target (@targets)
                    {
                        $target =~ s/\D//g;
                    }

                    # Splitting on "/" makes the first array index empty string
                    # so every value here is shifted over by 1
                    # There are only ever two targets per parent in this case,
                    # so to get the relative positions for each target, we take
                    # mod two of the source value
                    $proc_num = $targets[4] % 2;
                    $mc_num = $targets[7] % 2;
                    $mi_num = $targets[8] % 2;
                    $mcc_num = $targets[9] % 2;
                    $omi_num = $targets[10] % 2;
                } # end foreach my $conn (@{$conn->{CONN}})
            } # end if ($conn ne "")

            my $ocmb_num = 0;
            $pmic_num %= 2;
            my $pmic_aff = $node_aff . "/proc-$proc_num/mc-$mc_num/mi-$mi_num/mcc-$mcc_num/omi-$omi_num/ocmb_chip-$ocmb_num/pmic-$pmic_num";
            $self->setAttribute($target, "AFFINITY_PATH", $pmic_aff);

            my $fapi_name = "FAPI_I2C_CONTROL_INFO";
            $self->setAttributeField($target, $fapi_name, "i2cMasterPath",
                "physical:sys-0/node-0/proc-$proc_num");
        } # end elsif ($type eq "PMIC")
        elsif ($type eq "PROC")
        {
            my $socket = $target;
            while($self->getAttribute($socket,"CLASS") ne "CONNECTOR")
            {
               $socket = $self->getTargetParent($socket);
            }
            if($socket ne "")
            {
                # Set the PROC position
                $proc = $self->getAttribute($target,"POSITION");

                my $system_name = $self->getSystemName();
                # Set position for RAINIER
                if ($system_name =~ /RAINIER/i)
                {
                   # There are 2 sockets comprising of 2 processors for a total of 4.
                   # For Rainier, the processors are unique to the system, not
                   # to a socket, therefore each processor gets their own position.
                   # The position of the socket is either 0 or 1 and the processors,
                   # within a socket, has position of either 0 or 1.
                   my $socketPosition = $self->getAttribute($socket,"POSITION");
                   # Do the following math to get the unique position for a processor
                   $proc = ($socketPosition * MAX_PROCS_PER_SOCKET) + $proc;
                }
            }
            else
            {
              die "Cannot find socket connector for $target\n";
            }

            my $num_mi = 0;
            ### count number of MCs
            foreach my $unit (@{ $self->{data}->{TARGETS}{$target}{CHILDREN} })
            {
                my $unit_type = $self->getType($unit);
                if ($unit_type eq "MC")
                {
                    $num_mc++;
                    $num_mi += 2; # 2 MI's per MC
                }
            }
            if ($num_mc > $self->{MAX_MC})
            {
                $self->{MAX_MC} = $num_mc;
            }
            if ($num_mi > $self->{MAX_MI})
            {
                $self->{MAX_MI} = $num_mi;
            }

            if($self->{NUM_PROCS_PER_NODE} < ($proc + 1))
            {
                $self->{NUM_PROCS_PER_NODE} = $proc + 1;
            }

            $self->{targeting}->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{KEY} =
                $target;

            #my $socket=$self->getTargetParent($self->getTargetParent($target));
            my $parent_affinity = $node_aff  . "/proc-$proc";
            my $parent_physical = $node_phys . "/proc-$proc";

            my $fapi_name = $self->getFapiName($type, $node, $proc);
            #unique offset per system
            my $nodepos = $self->getParentNodePos($target) ;
            my $proc_ordinal_id = ($nodepos * $MAX_INST_PER_PROC{$type}) + $proc;

            # Ensure processor HUID is node-relative
            $self->{huid_idx}->{$type} = $proc;
            $self->setHuid($target, $sys_pos, $node);
            $self->setAttribute($target, "FAPI_NAME",       $fapi_name);
            $self->setAttribute($target, "PHYS_PATH",       $parent_physical);
            $self->setAttribute($target, "AFFINITY_PATH",   $parent_affinity);
            $self->setAttribute($target, "ORDINAL_ID",      $proc_ordinal_id);
            $self->setAttribute($target, "POSITION",        $proc);

            $self->setAttribute($target, "FABRIC_GROUP_ID",
                $self->getAttribute($socket,"FABRIC_GROUP_ID"));
            $self->setAttribute($target, "FABRIC_CHIP_ID",
                $self->getAttribute($socket,"FABRIC_CHIP_ID"));
            $self->setAttribute($target, "VPD_REC_NUM",    $proc);
            $proc_fapi = $self->getAttribute($socket, "FABRIC_GROUP_ID") *
                NUM_PROCS_PER_GROUP +
                $self->getAttribute($socket, "FABRIC_CHIP_ID");
            $self->setAttribute($target, "FAPI_POS", $proc_fapi);

            # Both for FSP and BMC based systems, it's good  enough
            # to look for processor with active LPC bus connected
            $self->log($target,"Finding master proc (looking for LPC Bus)");
            my $lpcs=$self->findConnections($target,"LPC","");
            if ($lpcs ne "")
            {
                $self->log ($target, "Setting $target as ACTING_MASTER");
                $self->setAttribute($target, "PROC_MASTER_TYPE",
                                  "ACTING_MASTER");
                $self->setAttribute($target, "PROC_SBE_MASTER_CHIP", "TRUE");
            }
            else
            {
               $self->setAttribute($target, "PROC_MASTER_TYPE",
                               "NOT_MASTER");
               $self->setAttribute($target, "PROC_SBE_MASTER_CHIP", "FALSE");
            }

            # Iterate over the children of the PROC and set some attributes for them
            $self->iterateOverChiplets($target, $sys_pos, $node, $proc);

            $self->processMc($target, $sys_pos, $node, $proc, $parent_affinity,
                             $parent_physical, $node_phys);
        } # end elsif ($type eq "PROC")
    } # end foreach my $target (sort keys %{ $self->{data}->{TARGETS} })

    # Now populate the affinity path of each TPM. Do this after the main loop
    # because we need to make sure that all of the procs have been processed
    {
        my $type = "";
        if (@tpm_list != 0)
        {
            $type = $self->getAttribute($tpm_list[0], "TYPE");
        }
        $tpm = 0;
        foreach my $tpm_target (@tpm_list)
        {
            my $affinity_path = $self->getParentProcAffinityPath($tpm_target,
                                                                 $tpm,
                                                                 $type);
            $self->
               setAttribute($tpm_target, "AFFINITY_PATH", $affinity_path);
            $tpm++;
        }
    }
    # Populate the affinity path of each UCD. Do this after the main loop
    # because we need to make sure that all of the procs have been processed
    {
        my $type = "";
        if (@ucd_list != 0)
        {
            $type = $self->getAttribute($ucd_list[0], "TYPE");
        }
        $ucd = 0;
        foreach my $ucd_target (@ucd_list)
        {
            my $affinity_path = $self->getParentProcAffinityPath($ucd_target,
                                                                 $ucd,
                                                                 $type);
            $self->
               setAttribute($ucd_target, "AFFINITY_PATH", $affinity_path);
            $ucd++;
        }
    }
}

# Get the affinity path of the passed target. The affinity path is the physical
# path of the target's I2C master which for this function is the parent
# processor with chip unit number appended.
sub getParentProcAffinityPath
{
    my $self   = shift;
    my $target = shift;
    my $chip_unit = shift;
    my $type_name = shift;

    # Make sure the type_name is all upper-case
    my $type_name = uc $type_name;

    # Create a lower-case version of the type name
    my $lc_type_name = lc $type_name;

    my $affinity_path = "";

    # Only get affinity path for supported types.
    if(($type_name ne "TPM")
      && ($type_name ne "POWER_SEQUENCER"))
    {
        die "Attempted to get parent processor affinity path" .
            " on invalid target ($type_name)";
    }

    my $parentProcsPtr = $self->findDestConnections($target, "I2C", "");

    if($parentProcsPtr eq "")
    {
        $affinity_path = "affinity:sys-0/node-0/proc-0/" .
                         "$lc_type_name-$chip_unit";
    }
    else
    {
        my @parentProcsList = @{$parentProcsPtr->{CONN}};
        my $numConnections = scalar @parentProcsList;

        if($numConnections != 1)
        {
            die "Incorrect number of parent procs ($numConnections)".
                " found for $type_name$chip_unit";
        }

        # The target is only connected to one proc, so we can fetch just the
        # first connection.
        my $parentProc = $parentProcsList[0]{SOURCE_PARENT};
        if($self->getAttribute($parentProc, "TYPE") ne "PROC")
        {
            die "Upstream I2C connection to $type_name" .
                "$chip_unit is not type PROC!";
        }

        # Look at the I2C master's physical path; replace
        # "physical" with "affinity" and append chip unit
        $affinity_path = $self->getAttribute($parentProc, "PHYS_PATH");
        $affinity_path =~ s/physical/affinity/g;
        $affinity_path = $affinity_path . "/$lc_type_name-$chip_unit";
    }

    return $affinity_path;
}

sub iterateOverChiplets
{
    my $self     = shift;
    my $target   = shift;
    my $sys      = shift;
    my $node     = shift;
    my $proc     = shift;
    my $tgt_ptr        = $self->getTarget($target);
    my $tgt_type       = $self->getType($target);

    # Previous OBUS parent
    my $prev_obus = -1;
    # Subtract factor for OBUS_BRICK
    my $brick_sub = -1;

    my $target_children  = $self->getTargetChildren($target);

    if ($target_children eq "")
    {
        return "";
    }
    else
    {
        my @phb_array = ();
        my @non_connected_phb_array = ();
        foreach my $child (@{ $self->getTargetChildren($target) })
        {
            # For PEC children, we need to remove duplicate PHB targets
            if ($tgt_type eq "PEC")
            {
                my $pec_num = $self->getAttribute($target, "CHIP_UNIT");
                $self->setAttribute($child,"AFFINITY_PATH",$self
                    ->getAttribute($target,"AFFINITY_PATH"));
                $self->setAttribute($child,"PHYS_PATH",$self
                    ->getAttribute($target,"PHYS_PATH"));

                foreach my $phb (@{ $self->getTargetChildren($child) })
                {
                    my $phb_num = $self->getAttribute($phb, "CHIP_UNIT");
                    foreach my $pcibus (@{ $self->getTargetChildren($phb) })
                    {
                        # We need to ensure that all PHB's get added to the
                        # MRW, but PHB's with busses connected take priority
                        # and we cannot have duplicate PHB targets in the MRW.

                        # We processes every PHB pci bus config starting with
                        # the config with the fewest PHB's. For PEC2 we start
                        # with PHB3_x16. If a bus is not connected to that PHB
                        # we add it to the phb_array anyway so the target will
                        # be populated in the HB MRW. As we processes the later
                        # PHB configs under PEC2 we may find that PHB3 has a
                        # bus connected to it. Since the bus config takes
                        # priority over the target that was already added to
                        # the phb_array, we just overwrite that phb_array entry
                        # with the PHB that has a bus connected.

                        if (($self->getNumConnections($pcibus) > 0) &&
                                (@phb_array[$phb_num] eq ""))
                        {
                            # This PHB does have a bus connection and the slot
                            # is empty. We must add it to the PHB array
                            @phb_array[$phb_num] = $phb;
                        }
                        elsif (($self->getNumConnections($pcibus) == 0) &&
                                   (@phb_array[$phb_num] eq ""))
                        {
                            # This PHB does NOT have a bus connection. It's
                            # slot is still empty, so we must add it to the
                            # array so every PHB has a target in the MRW.
                            @phb_array[$phb_num] = $phb;

                            # Also add it to the non_connected_phb_array so we
                            # can examine later it if needs to be overriden.
                            @non_connected_phb_array[$phb_num] = $phb;
                        }
                        elsif (($self->getNumConnections($pcibus) > 0) &&
                                   (@phb_array[$phb_num] ne ""))
                        {
                             # This PHB has a connection, but the slot has
                             # already been filled by another PHB. We need to
                             # check if it was a non connected PHB
                             if(@non_connected_phb_array[$phb_num] ne "")
                             {
                                 # The previous connection in the PHB elecment
                                 # is not connected to a bus. We should
                                 # override it
                                 @phb_array[$phb_num] = $phb;
                             }
                             else
                             {
                                 # This is our "bug" scenerio. We have found a
                                 # connection, but that PHB element is already
                                 # filled in the array. We need to kill the
                                 # program.
                                 printf("Found a duplicate connection for PEC %s PHB %s.\n",$pec_num,$phb_num);
                                 die "Duplicate PHB bus connection found\n";
                             }
                        } # end elsif (($self->getNumConnections ...
                    } # end foreach my $pcibus ...
                } # end foreach my $phb (@{ $self->getTargetChildren($child) })
            } # end if ($tgt_type eq "PEC")
            else
            {
                # These target types are NOT PEC
                my $unit_ptr        = $self->getTarget($child);
                my $unit_type       = $self->getType($child);

                #System XML has some sensor target as hidden children
                #of targets. We don't care for sensors in this function
                #So, we can avoid them with this conditional
                if ($unit_type ne "PCI" && $unit_type ne "NA" &&
                    $unit_type ne "FSI" && $unit_type ne "PSI" &&
                    $unit_type ne "SYSREFCLKENDPT" && $unit_type ne "MFREFCLKENDPT")
                {
                    if ($unit_type eq "OBUS_BRICK")
                    {
                        # Check to see if this is on a new obus
                        # Current obus is the CHIP_UNIT of the parent obus
                        my $curr_obus = $self->getAttribute($target,
                            "CHIP_UNIT");
                        if ($prev_obus ne $curr_obus)
                        {
                            my $brick_pos = $self->getAttribute($child,
                                "CHIP_UNIT");
                            $brick_sub = $brick_pos;
                            $prev_obus = $curr_obus;
                        }
                    } # end if ($unit_type eq "OBUS_BRICK")

                    #set common attrs for child
                    $self->setCommonAttrForChiplet($child, $sys, $node, $proc,
                        $prev_obus, $brick_sub);
                    $self->iterateOverChiplets($child, $sys, $node, $proc);
                } # end if ($unit_type ne "PCI" && ...
            } # end if ($tgt_type eq "PEC") ... else
        } # end foreach my $child (@{ $self->getTargetChildren($target) })

        my $size = @phb_array;
        # For every entry in the PHB array, if there is a PHB in its slot
        # we add that PHB target to the MRW.

        # We process PEC's individually, so we need to make sure the PHB slot
        # has a PHB in it. eg: phb_array[0] will be empty for when processing
        # PEC1 and 2 as there is no PHB0 configured for those PECs.
        for (my $i = 0; $i < $size; $i++)
        {
            if (@phb_array[$i] ne "")
            {
                $self->setCommonAttrForChiplet
                    (@phb_array[$i], $sys, $node, $proc);
            }
        }
    } # end if ($target_children eq "") ... else
}

sub setCommonAttrForChiplet
{
    my $self        = shift;
    my $target      = shift;
    my $sys         = shift;
    my $node        = shift;
    my $proc        = shift;
    my $prev_obus   = shift;
    my $brick_sub   = shift;

    my $tgt_ptr        = $self->getTarget($target);
    my $tgt_type       = $self->getType($target);

    push(@{$self->{targeting}
            ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{$tgt_type}},
            { 'KEY' => $target });

    my $pos             = $self->getAttribute($target, "CHIP_UNIT");
    my $unit_pos        = $pos;

    # Chiplets' positions, in AFFINITY_PATH, are expected to be relative to the
    # parent, serverwiz outputs it unique/absolute.
    if ($MAX_INST_PER_PARENT{$tgt_type})
    {
        $unit_pos = $pos % $MAX_INST_PER_PARENT{$tgt_type};
    }

    my $parent_affinity = $self->getAttribute(
                          $self->getTargetParent($target),"AFFINITY_PATH");
    my $parent_physical = $self->getAttribute(
                          $self->getTargetParent($target),"PHYS_PATH");

    my $affinity_path   = $parent_affinity . "/" . lc $tgt_type ."-". $unit_pos;
    my $physical_path   = $parent_physical . "/" . lc $tgt_type ."-". $unit_pos;

    my $fapi_name       = $self->getFapiName($tgt_type, $node, $proc, $pos);

    # Calculate a system wide offset
    my $sys_offset = (($node * $MAX_INST_PER_PROC{"PROC"} + $proc ) *
        $MAX_INST_PER_PROC{$tgt_type}) + $pos;

    # Calculate a node specific offset
    my $node_offset = ($proc * $MAX_INST_PER_PROC{$tgt_type}) + $pos;

    # HUID is node based so use that offset
    $self->{huid_idx}->{$tgt_type} = $node_offset;
    $self->setHuid($target, $sys, $node);
    $self->setAttribute($target, "FAPI_NAME",       $fapi_name);
    $self->setAttribute($target, "PHYS_PATH",       $physical_path);
    $self->setAttribute($target, "AFFINITY_PATH",   $affinity_path);
    $self->setAttribute($target, "ORDINAL_ID",      $sys_offset);
    $self->setAttribute($target, "FAPI_POS",        $sys_offset);
    $self->setAttribute($target, "REL_POS",         $unit_pos);

    my $pervasive_parent= getPervasiveForUnit("$tgt_type$pos");
    if ($pervasive_parent ne "")
    {
        my $perv_parent_val =
            "physical:sys-$sys/node-$node/proc-$proc/perv-$pervasive_parent";
        $self->setAttribute($target, "PARENT_PERVASIVE", $perv_parent_val);
    }
}


sub getFapiName
{
    my $self        = shift;
    my $target      = shift;
    my $node        = shift;
    my $chipPos     = shift;
    my $chipletPos  = shift;

    if ($target eq "")
    {
        die "getFapiName: ERROR: Please specify a taget name\n";
    }

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

    if ($nonFapiTargets{$target} eq "NA")
    {
        return $nonFapiTargets{$target};
    }
    elsif ($target eq "SYS")
    {
        return "k0";
    }
    elsif ($target eq "PROC" || $target eq "DIMM" || $target eq "MEMBUF")
    {
        if ($node eq "" || $chipPos eq "")
        {
            die "getFapiName: ERROR: Must specify node and chipPos for $target
                 current node: $node, chipPos: $chipPos\n";
        }
        my $chip_name;
        if ($target eq "PROC")
        {
            $chip_name = "pu";
        }
        else
        {
            $chip_name = lc $target;
        }

        my $fapi_name = sprintf("%s:k0:n%d:s0:p%02d",$chip_name,$node,$chipPos);
        return $fapi_name;
    }
    else
    {
        if ($node eq "" || $chipPos eq "" || $chipletPos eq "")
        {
            die "getFapiName: ERROR: Must specify node, chipPos,
                 chipletPos for $target. Current node: $node, chipPos: $chipPos
                 chipletPos: $chipletPos\n";
        }

        $target = lc $target;

        my $fapi_name;

        if ($target eq "mba" || $target eq "l4")
        {
          $fapi_name = sprintf("membuf.$target:k0:n%d:s0:p%02d:c%d",
                            $node, $chipPos, $chipletPos);
        }
        else
        {
            $fapi_name = sprintf("pu.$target:k0:n%d:s0:p%02d:c%d",
                            $node, $chipPos, $chipletPos);
        }
        return $fapi_name;
    }
}

#--------------------------------------------------
# @brief Get the maximum instance per processor from global hash
#        MAX_INST_PER_PROC.
#
# @details This is a wrapper around the hash MAX_INST_PER_PROC that will
#          validate the key.  If the key does not exist in the hash, then an
#          error is displayed and the script halted.  The advantage to using
#          this method over reading the hash directly, is that, Perl will
#          not flag if the key does not exist, and the programmer can easily
#          dismiss the no warning/error as everything is working fine.
#
# @note Will croak if key into hash is not found.
#
# @param [in] $targetObj - The global target object.
# @param [in] $targetType - The key to look for in hash MAX_INST_PER_PROC
#
# @return Value associated with key in hash MAX_INST_PER_PROC if key exists,
#         else croak stating key not found in hash.
#--------------------------------------------------
sub getMaxInstPerProc
{
    my $self = shift;
    my $targetType = shift;

    if (not exists $MAX_INST_PER_PROC{$targetType})
    {
        confess "\nTargets::getMaxInstPerProc: ERROR: Key for target " .
           "type \"$targetType\" not found in hash " .
           "Targets::MAX_INST_PER_PROC.\n";
    }

    return $MAX_INST_PER_PROC{$targetType};
}

sub getPervasiveForUnit
{
    # Input should be of the form <type><chip unit>, example: "core0"
    my $unit = shift;

    # The mapping is a static variable that is preserved across new calls to
    # the function to speed up the mapping performance
    state %unitToPervasive;

    if ( not %unitToPervasive )
    {
        use integer;
        my @targetTypes = qw (PAU CORE IOHS EQ PAUC MC OBUS);
        foreach my $targetType (@targetTypes)
        {
            for my $targetTypeValue (0..$MAX_INST_PER_PROC{$targetType}-1)
            {
                my $value = $Targets::PERVASIVE_PARENT_OFFSET{$targetType};

                if ($targetType eq "PAU")
                {
                    $value += ($targetTypeValue/PAU_PER_PAUC);
                }
                elsif ($targetType eq "CORE")
                {
                    # The core pervasive parent value is not sequential, from min to
                    # max, but increase per EQ. In other words, all the core's
                    # pervasive parent value for an EQ are the same.
                    $value += ($targetTypeValue/CORES_PER_EQ);
                }
                else
                {
                    # Most target types will use this computation
                    $value += $targetTypeValue;
                }

                $unitToPervasive{"$targetType$targetTypeValue"} = $value;
            }
        } # end foreach my $targetType (@targetTypes)

        for my $xbus (0..$MAX_INST_PER_PROC{"XBUS"}-1)
        {
            $unitToPervasive{"XBUS$xbus"} = PERVASIVE_PARENT_XBUS_OFFSET;
        }

        for my $capp (0..$MAX_INST_PER_PROC{"CAPP"}-1)
        {
            $unitToPervasive{"CAPP$capp"} = 2 * ($capp+1);
        }

        for my $mi (0..$MAX_INST_PER_PROC{"MI"}-1)
        {
            $unitToPervasive{"MI$mi"} =
                PERVASIVE_PARENT_MI_OFFSET + ($mi > 1);
        }
        for my $pec (0..$MAX_INST_PER_PROC{"PEC"}-1)
        {
            $unitToPervasive{"PEC$pec"} =
                PERVASIVE_PARENT_PEC_OFFSET + $pec;
        }
        for my $phb (0..$MAX_INST_PER_PROC{"PHB"}-1)
        {
            $unitToPervasive{"PHB$phb"} =
                PERVASIVE_PARENT_PHB_OFFSET + ($phb>0) + ($phb>2);
        }
        my $offset = 0;
        for my $obrick (0..$MAX_INST_PER_PROC{"OBUS_BRICK"}-1)
        {
            $offset += (($obrick%3 == 0) && ($obrick != 0)) ? 1 : 0;
            $unitToPervasive{"OBUS_BRICK$obrick"}
                = PERVASIVE_PARENT_OBUS_OFFSET + $offset;
        }
    }

    my $pervasive = "";
    if(exists $unitToPervasive{$unit})
    {
        $pervasive = $unitToPervasive{$unit};
    }

    return $pervasive
}


# TODO, RTC 215164. This method was heavily involved with DMI which is dead for
#                   P10, therefore I removed all code associated with this
#                   method and it had no affect on the output file.  Leaving it
#                   here for now, until work on the MC target gets underway.
#
sub processMc
{

    my $self     = shift;
    my $target   = shift;
    my $sys      = shift;
    my $node     = shift;
    my $proc     = shift;
    my $parent_affinity = shift;
    my $parent_physical = shift;
    my $node_phys       = shift;

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
#          type does not match search criteria, then the script will exit
#          stating so.
#
# @note If the target has no type, then try method findParentByInstName
#
# @param [in] $self - The global target object.
# @param [in] $child - the starting point to find parent
# @param [in] $typeToMatch - search criteria
#
# @return parent whose type matches search criteria, else croak if not found
#--------------------------------------------------
sub findParentByType
{
    my $self        = shift;
    my $child       = shift;
    my $typeToMatch = shift;

    # Make sure we have not reached the end
    my $topLevel = "/" . $self->getTopLevel();
    if ($child eq $topLevel)
    {
       croak "findParentByType: ERROR: Reached top level target. " .
           "There is no parent of type \"$typeToMatch\". Error";
    };

    # Get the child's parent and check if that is the parent we want
    my $parent = ($self->getTarget($child))->{PARENT};
    my $parentType = $self->getType($parent);
    if ($parentType ne $typeToMatch)
    {
        $parent = $self->findParentByType($parent, $typeToMatch);
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
        printf("ERROR: getAttribute(%s,%s) | Attribute not defined\n",
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

## copy an attribute between targets
sub copyAttributeFields
{
    my $self = shift;
    my $source_target = shift;
    my $dest_target = shift;
    my $attribute = shift;

    foreach my $f(sort keys
        %{$self->{data}->{TARGETS}->{$source_target}->{ATTRIBUTES}->{$attribute}->{default}->{field}})
    {
            my $field_val = $self->getAttributeField($source_target,
                $attribute, $f);
            $self->setAttributeField($dest_target,$attribute,$f,
                $field_val);
            $self->log($dest_target, "Copy Attribute Field:$attribute($f)=$field_val");
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

#--------------------------------------------------
# @brief Populates the EEPROM attributes for DDIMMs
#
# @param [in] $self - The global target object.
# @param [in] $target - An OCMB target
#--------------------------------------------------
sub setEepromAttributesForDdimms
{
    my $self      = shift;
    my $target    = shift;  # Expects ocmb target

    my %connections;
    my $num=0;

    my $eeprom_name = "EEPROM_VPD_PRIMARY_INFO";
    my $fapi_name = "FAPI_I2C_CONTROL_INFO";
    # SPD contains data for EEPROM_VPD_PRIMARY_INFO and FAPI_I2C_CONTROL_INFO
    # SPD is the child of ocmb's parent, so get ocmb's parent
    # then look for the SPD child
    # With the resulting info, we populate pmic0, pmic1, ocmb, and dimm
    my $target_parent = $self->getTargetParent($target);

    # Need to store pmic targets because they get parsed before we
    # do calculations for engine, port, etc
    # pmics need these values, so we store them until we need them later
    my $address = 0;
    my @pmic_array;
    foreach my $child (@{ $self->getTargetChildren($target_parent) })
    {
        my $type = $self->getTargetType($child);
        if ($type eq "chip-spd-device")
        {
            my $offset = $self->getAttribute($child, "BYTE_ADDRESS_OFFSET");
            my $memory_size = $self->getAttribute($child, "MEMORY_SIZE_IN_KB");
            my $cycle_time = $self->getAttribute($child, "WRITE_CYCLE_TIME");
            my $page_size = $self->getAttribute($child, "WRITE_PAGE_SIZE");

            # Populate EEPROM for ocmb
            $self->setAttributeField($target, $eeprom_name, "byteAddrOffset",
                $offset);
            $self->setAttributeField($target, $eeprom_name, "maxMemorySizeKB",
                $memory_size);
            $self->setAttributeField($target, $eeprom_name, "writeCycleTime",
                $cycle_time);
            $self->setAttributeField($target, $eeprom_name, "writePageSize",
                $page_size);

            # Populate EEPROM for dimm
            $self->setAttributeField($target_parent, $eeprom_name, "byteAddrOffset",
                $offset);
            $self->setAttributeField($target_parent, $eeprom_name, "maxMemorySizeKB",
                $memory_size);
            $self->setAttributeField($target_parent, $eeprom_name, "writeCycleTime",
                $cycle_time);
            $self->setAttributeField($target_parent, $eeprom_name, "writePageSize",
                $page_size);

            # spd only child is i2c-slave, which contains devAddr info
            foreach my $i2c_slave (@{ $self->getTargetChildren($child) })
            {
                $address = $self->getAttribute($i2c_slave, "I2C_ADDRESS");
                # Populate EEPROM for dimm
                $self->setAttributeField($target_parent, $eeprom_name, "devAddr",
                    $address);

                # Populate EEPROM for ocmb
                $self->setAttributeField($target, $eeprom_name, "devAddr",
                    $address);
            }
        } # end if ($type eq "chip-spd-device") ...
        elsif ($type eq "chip-vreg-generic")
        {
            push(@pmic_array, $child);
            foreach my $i2c_slave (@{ $self->getTargetChildren($child) })
            {
                $type = $self->getTargetType($i2c_slave);
                # pmic has child i2c_slave which contains the device address
                if ($type eq "unit-i2c-slave")
                {
                    $address = $self->getAttribute($i2c_slave, "I2C_ADDRESS");

                    # Populate FAPI for pmic
                    $self->setAttributeField($child, $fapi_name, "devAddr",
                        $address);
                    last;
                }
            }
        } # end elsif ($type eq "chip-vreg-generic")
        elsif ($type eq "chip-ocmb")
        {
            foreach my $i2c_slave (@{ $self->getTargetChildren($child) })
            {
                # ocmb has multiple i2c-slaves, so we query with instance_name
                my $instance_name = $self->getInstanceName($i2c_slave);
                if ($instance_name eq "i2c-ocmb")
                {
                    $address = $self->getAttribute($i2c_slave, "I2C_ADDRESS");

                    # Populate FAPI for ocmb
                    $self->setAttributeField($target, $fapi_name, "devAddr",
                        $address);
                    last;
                }
            }
        } # end elsif ($type eq "chip-ocmb")
    } # end foreach my $child ...
} # end setEepromAttributesForDdimms

###############################################################################
# Useful Utilites
###############################################################################
#--------------------------------------------------
# @brief This will print a subset of the targets. Currently tweaked for
#        HB, but can be tweaked to print what targets you are interested in.
#
# @details This was written with Rainier MRW XML in mind, change accordingly.
#          Run as a stand alone utility.
#
# @param[in] $self - The global target object
# @param[in] $filename - The XML file to be processed
# @param[in] $target - The target to explore children of, if given, else
#                      will start with the top level target
#--------------------------------------------------
sub printCompactTargetHierarchy
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
        $XML::Simple::PREFERRED_PARSER = 'XML::Parser';
        $self->loadXML($filename);
        $isXmlFileLoaded = 1;
    }

    # No target given, so use the top level target
    if ($target eq undef)
    {
        $target = "/" . $self->getTopLevel();
        print "$target \n";
    }

    # Target print control
    my $stopProcessingChildren1 = "power10-1";
    my $stopProcessingChildren2 = "fsi-slave-0";
    my $stopProcessingChildren3 = "motherboard_fault_sensor";
    my $stopProcessingChildren4 = "system_event_sensor";
    my $skipChild = "vpd_assoc_child";
    my $skipChildrenUntilDimm = "proc_socket-1";
    my $skipUntilDimm = 0;

    # Iterate over the children
    my $children = $self->getTargetChildren($target);
    foreach my $child (@{ $children })
    {

        if (($child =~ m/$stopProcessingChildren1/)  ||
            ($child =~ m/$stopProcessingChildren2/)  ||
            ($child =~ m/$stopProcessingChildren3/)  ||
            ($child =~ m/$stopProcessingChildren4/) )
        {
            return;
        }

        if ($child =~ m/$skipChild/)
        {
            next;
        }

        if ($child =~ m/$skipChildrenUntilDimm/)
        {
            $skipUntilDimm = 1;
            next;
        }

        if ( ($skipUntilDimm == 1) &&
             (!($child =~ m/ddimm-connector/)) )
        {
            next;
        }

        print "$child \n";
        $self->printCompactTargetHierarchy($filename, $child);
    } # end foreach my $child (@{ $children })
} # end sub printCompactTargetHierarchy

#--------------------------------------------------
# @brief This will print ALL targets and their hiearchy from the given file.
#        Run as a stand alone utility.
#
# @param[in] $self - The global target object
# @param[in] $filename - The XML file to be processed
# @param[in] $target - The target to explore children of, if given, else
#                      will start with the top level target
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
        $XML::Simple::PREFERRED_PARSER = 'XML::Parser';
        $self->loadXML($filename);
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
