# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/Targets.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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

use constant
{
    PERVASIVE_PARENT_CORE_OFFSET => 32,
    PERVASIVE_PARENT_EQ_OFFSET => 16,
    PERVASIVE_PARENT_XBUS_OFFSET => 6,
    PERVASIVE_PARENT_OBUS_OFFSET => 9,
    PERVASIVE_PARENT_MCBIST_OFFSET => 7,
    PERVASIVE_PARENT_MCS_OFFSET => 7,
    PERVASIVE_PARENT_MCA_OFFSET => 7,
    PERVASIVE_PARENT_PEC_OFFSET => 13,
    PERVASIVE_PARENT_PHB_OFFSET => 13,
    PERVASIVE_PARENT_NV_OFFSET => 5,
};

my %maxInstance = (
    "PROC"  => 8,
    "CORE"  => 24,
    "EX"    => 12,
    "EQ"    => 6,
    "ABUS"  => 3,
    "XBUS"  => 3,
    "OBUS"  => 4,
    "MCBIST"=> 2,
    "MCS"   => 4,
    "MCA"   => 8,
    "PHB"   => 6, #PHB is same as PCIE
    "PEC"   => 3, #PEC is same as PBCQ
    "MBA"   => 2,
    "PPE"   => 51, #Only 21, but they are sparsely populated
    "PERV"  => 56, #Only 42, but they are sparsely populated
    "CAPP"  => 2,
    "SBE"   => 1,
    "NV"    => 6, #FW only for GARD purposes
    "MI"    => 4,
    "OCC"   => 1,
);
sub new
{
    my $class = shift;
    my $self  = {
        xml          => undef,
        data         => undef,
        targeting    => undef,
        enumerations => undef,
        MAX_MCS      => 0,
        UNIT_COUNTS  => undef,
        master_proc  => undef,
        huid_idx     => undef,
        mru_idx      => undef,
        force        => 0,
        debug        => 0,
        version      => "",
        xml_version  => 0,
        errorsExist  => 0,
        NUM_PROCS    => 0,
        TOP_LEVEL    => "",
        TOPOLOGY     => undef,
        report_log   => "",
        vpd_num      => 0,
        DMI_FSI_MAP  => {
            '0' => '3',
            '1' => '2',
            '4' => '7',
            '5' => '6'
        }
        # TODO RTC:132549
        # DMI_FSI_MAP is a lookup table for DMI channel to FSI and ref clock.
        # It is processor specific and needs to be pulled from a
        # processor attribute instead of being hardcoded

    };
    return bless $self, $class;
}

sub setVersion
{
    my $self    = shift;
    my $version = shift;

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
        $self->printTarget($fh, $target);
        my $children = $t->[$p];
        foreach my $u (sort(keys %{$children}))
        {
            if ($u ne "KEY")
            {
                $self->printXML($fh, $t->[$p]->{$u});
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

    my $target_ptr = $self->getTarget($target);

    if ($target eq "")
    {
        return;
    }

    print $fh "<targetInstance>\n";
    my $target_id = $self->getAttribute($target, "PHYS_PATH");
    $target_id = substr($target_id, 9);
    $target_id =~ s/\///g;
    $target_id =~ s/\-//g;


    print $fh "\t<id>" . $target_id . "</id>\n";
    print $fh "\t<type>" . $self->getTargetType($target) . "</type>\n";

    ## get attributes
    foreach my $attr (sort (keys %{ $target_ptr->{ATTRIBUTES} }))
    {
        $self->printAttribute($fh, $target_ptr->{ATTRIBUTES}, $attr);
    }
    print $fh "</targetInstance>\n";
}

sub printAttribute
{
    my $self       = shift;
    my $fh         = shift;
    my $target_ptr = shift;
    my $attribute  = shift;
    my $r          = "";

    # TODO RTC: TBD
    # temporary until we converge attribute types
    my %filter;
    $filter{MRW_TYPE}                                               = 1;
    $filter{SYSTEM_NAME}                                            = 1;
    $filter{BUS_TYPE}                                               = 1;
    $filter{DIRECTION}                                              = 1;
    $filter{ENABLE_CAPI}                                            = 1;
    $filter{PCIE_CONFIG_NUM}                                        = 1;
    $filter{PCIE_LANE_MASK}                                         = 1;
    $filter{PCIE_LANE_SET}                                          = 1;
    $filter{PCIE_NUM_LANES}                                         = 1;
    $filter{PHB_NUM}                                                = 1;
    $filter{IOP_NUM}                                                = 1;
    $filter{LOCATION_CODE}                                          = 1;
    $filter{LOCATION_CODE_TYPE}                                     = 1;
    $filter{MCS_NUM}                                                = 1;
    $filter{SCHEMATIC_INTERFACE}                                    = 1;
    $filter{ENTITY_ID}                                              = 1;
    $filter{CLASS}                                                  = 1;
    $filter{MODEL}                                                  = 1;
    $filter{TYPE}                                                   = 1;
    $filter{CDM_POLICIES}                                           = 1;
    $filter{CDM_POLICIES_BITMASK}                                   = 1;
    $filter{ENTITY_ID_LOOKUP}                                       = 1;
    $filter{ENTITY_INSTANCE}                                        = 1;
    $filter{MBA_NUM}                                                = 1;
    $filter{IPMI_NAME}                                              = 1;
    $filter{INSTANCE_ID}                                            = 1;
    $filter{INSTANCE_PATH}                                          = 1;
    $filter{IO_CONFIG_SELECT}                                       = 1;
    $filter{FRU_NAME}                                               = 1;
    $filter{TPM_BACKUP_INFO}                                        = 1;
    $filter{TPM_PRIMARY_INFO}                                       = 1;
    $filter{ALL_MCS_IN_INTERLEAVING_GROUP}                          = 1;
    $filter{AVERAGE_IPL_TIME}                                       = 1;
    $filter{CHECK_SCRIPT}                                           = 1;
    $filter{DMI_DFE_OVERRIDE}                                       = 1;
    $filter{FREQ_A}                                                 = 1;
    $filter{FREQ_NEST_HFT}                                          = 1;
    $filter{FREQ_PB}                                                = 1;
    $filter{FREQ_PB_HFT}                                            = 1;
    $filter{FREQ_PCIE}                                              = 1;
    $filter{FREQ_X}                                                 = 1;
    $filter{FREQ_X_HFT}                                             = 1;
    $filter{LED_ON_DEFAULT_GPIO_VALUE}                              = 1;
    $filter{LED_STRATEGY}                                           = 1;
    $filter{MSS_MCA_HASH_MODE}                                      = 1;
    $filter{MRW_ENHANCED_GROUPING_NO_MIRRORING}                     = 1;
    $filter{MRW_MEM_MIRRORING_ALLOWED}                              = 1;
    $filter{MRW_MEM_MIRRORING_ENABLE_DEFAULT}                       = 1;
    $filter{MRW_MEM_POWER_CONTROL_USAGE}                            = 1;
    $filter{MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM}         = 1;
    $filter{MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR4}    = 1;
    $filter{MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE}     = 1;
    $filter{MSS_VOLT_VDDR_OFFSET_DISABLE}                           = 1;
    $filter{OCC_LOAD_TIMEOUT}                                       = 1;
    $filter{OCC_RESET_TIMEOUT}                                      = 1;
    $filter{PCIE_DEFAULT_HDDW_SLOT_COUNT}                           = 1;
    $filter{PCIE_MIN_HDDW_SLOT_COUNT}                               = 1;
    $filter{PCIE_MAX_HDDW_SLOT_COUNT}                               = 1;
    $filter{REDUNDANT_FSPS}                                         = 1;
    $filter{SYSTEM_MTM}                                             = 1;
    $filter{PM_EXTERNAL_VRM_STEPSIZE}                               = 1;
    $filter{PM_EXTERNAL_VRM_STEPDELAY}                              = 1;
    $filter{PM_SPIPSS_FREQUENCY}                                    = 1;
    $filter{PM_SYSTEM_IVRMS_ENABLED}                                = 1;
    $filter{NUMERIC_POD_TYPE_TEST}                                  = 1;
    $filter{CARD_TYPE}                                              = 1;
    $filter{PROC_PCIE_DSMP_CAPABLE}                                 = 1;
    $filter{PROC_PCIE_IOP_CONFIG}                                   = 1;
    $filter{PROC_PCIE_IOP_REVERSAL}                                 = 1;
    $filter{PROC_PCIE_IOP_REVERSAL_BIFURCATED}                      = 1;
    $filter{PROC_PCIE_IOP_REVERSAL_NON_BIFURCATED}                  = 1;
    $filter{NPU_MMIO_BAR_SIZE}                                      = 1;
    $filter{NPU_MMIO_BAR_BASE_ADDR}                                 = 1;
    $filter{PROC_PCIE_REFCLOCK_ENABLE}                              = 1;
    $filter{PSI_HB_ESP_ADDR}                                        = 1;
    $filter{TPM_INFO}                                               = 1;
    $filter{STANDBY_PLUGGABLE}                                      = 1;
    $filter{CPM_INFLECTION_POINTS}                                  = 1;
    $filter{PROC_FABRIC_X_ATTACHED_CHIP_CNFG}                       = 1;
    $filter{SYSTEM_RESCLK_VALUE}                                    = 1;
    $filter{HWAS_STATE}                                             = 1;
    $filter{PROC_MIRROR_SIZES}                                      = 1;
    $filter{PROC_FABRIC_X_ADDR_DIS}                                 = 1;
    $filter{PROC_FABRIC_A_ATTACHED_LINK_ID}                         = 1;
    $filter{PROC_MEM_BASES}                                         = 1;
    $filter{UNIT_TEST_MCA_MEMORY_SIZES}                             = 1;
    $filter{SYSTEM_RESCLK_L3_VALUE}                                 = 1;
    $filter{PROC_CHTM_BAR_SIZES}                                    = 1;
    $filter{SYSTEM_RESCLK_FREQ_REGIONS}                             = 1;
    $filter{PROC_MIRROR_SIZES_ACK}                                  = 1;
    $filter{PROC_FABRIC_X_ATTACHED_LINK_ID}                         = 1;
    $filter{PROC_FABRIC_A_ATTACHED_LINK_ID}                         = 1;
    $filter{PROC_FABRIC_A_ATTACHED_CHIP_ID}                         = 1;
    $filter{PROC_MEM_SIZES}                                         = 1;
    $filter{PROC_FABRIC_OPTICS_CONFIG_MODE}                         = 1;
    $filter{PROC_PCIE_LANE_EQUALIZATION}                            = 1;
    $filter{HOT_PLUG_POWER_CONTROLLER_INFO}                         = 1;
    $filter{PROC_MEM_BASES_ACK}                                     = 1;
    $filter{PROC_FABRIC_A_ATTACHED_CHIP_CNFG}                       = 1;
    $filter{CHTM_TRACE_TYPE}                                        = 1;
    $filter{PROC_PCIE_NOT_F_LINK}                                   = 1;
    $filter{PROC_FABRIC_X_ATTACHED_CHIP_ID}                         = 1;
    $filter{PROC_FABRIC_A_ADDR_DIS}                                 = 1;
    $filter{MSS_MCS_GROUP_32}                                       = 1;
    $filter{PROC_MIRROR_BASES_ACK}                                  = 1;
    $filter{DELETE_AFFINITY_PATH}                                   = 1;
    $filter{PROC_MIRROR_BASES}                                      = 1;
    $filter{PROC_FABRIC_A_LINK_DELAY}                               = 1;
    $filter{PROC_MEM_SIZES_ACK}                                     = 1;
    $filter{SYSTEM_RESCLK_FREQ_REGION_INDEX}                        = 1;
    $filter{PROC_FABRIC_X_LINK_DELAY}                               = 1;
    $filter{PROC_CHTM_BAR_BASE_ADDR}                                = 1;
    $filter{TOD_CPU_DATA}                                           = 1;
    $filter{MSS_VOLT}                                               = 1;
    $filter{EFF_READ_DBI}                                           = 1;
    $filter{RU_TYPE}                                                = 1;
    $filter{STANDBY_PLUGGABLE}                                      = 1;
    $filter{MANUFACTURER}                                           = 1;
    $filter{HWAS_STATE_CHANGED_SUBSCRIPTION_MASK}                   = 1;
    if ($filter{$attribute} == 1)
    {
        return;
    }
    print $fh "\t<attribute>\n";
    print $fh "\t\t<id>$attribute</id>\n";
    my $value = $target_ptr->{$attribute}->{default};

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
        if ($value ne "") {
                print $fh "\t\t<default>$value</default>\n";
        }
    }
    print $fh "\t</attribute>\n";
}

## stores TYPE enumeration values which is used to generate HUIDs
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

    my $instance_path = $self->{data}->{INSTANCE_PATH};
    if (!defined $instance_path)
    {
        $instance_path = "";
    }
    my $baseptr = $self->{xml}->{'targetInstance'};
    if ($self->{xml_version} == 1)
    {
        $baseptr = $self->{xml}->{'targetInstances'}->{'targetInstance'};
    }
    if ($target eq "")
    {
        ## find system target
        foreach my $t (keys(%{$baseptr}))
        {
            if ($baseptr->{$t}->{attribute}->{TYPE}->{default} eq "SYS")
            {
                $self->{TOP_LEVEL} = $t;
                $target = $t;
            }
        }
    }
    if ($target eq "")
    {
        die "Unable to find system top level target\n";
    }
    my $old_path        = $instance_path;
    my $target_xml      = $baseptr->{$target};
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
                $self->setAttribute($key, $attribute, "");
            }
        }
        else
        {
            $self->setAttribute($key, $attribute, $value);
        }
    }
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
        $self->setAttribute($key, $prop, $val);
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
                    $self->{data}->{TARGETS}->{$source_target}->{CONNECTION}
                      ->{BUS}
                  },
                $b
            );
            my %bus_entry;
            $bus_entry{SOURCE_TARGET} = $source_target;
            $bus_entry{DEST_TARGET}   = $dest_target;
            $bus_entry{BUS_TARGET}    = $b;
            push(@{ $self->{data}->{BUSSES}->{$bus_type} }, \%bus_entry);
        }
    }

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
## traces busses and builds affinity hierarchy
## HOSTBOOT expected hierarchy: sys/node/proc/<unit>
##                              sys/node/proc/mcs/membuf/<unit>
##                              sys/node/proc/mcs/membuf/mba/dimm
## This function also sets the common attributes for all the targets
## Common attributes include:
##  - FAPI_NAME
##  - PHYS_PATH
##  - AFFINITY_PATH
##  - ORDINAL_ID
##  - HUID

sub buildAffinity
{
    my $self = shift;
    my $node            = -1;
    my $proc            = -1;
    my $tpm             = -1;
    my $sys_phys        = "";
    my $node_phys       = "";
    my $node_aff        = "";
    my $sys_pos         = -1;
    my $mcbist          = -1;

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
        my $target_ptr = $self->{data}->{TARGETS}{$target};
        my $type       = $self->getType($target);
        my $type_id    = $self->getEnumValue("TYPE", $type);
        my $pos        = $self->{data}->{TARGETS}{$target}{TARGET}{position};
        $sys_pos       = $pos if ($type eq "SYS");

        if ($type_id eq "") { $type_id = 0; }

        if ($type eq "SYS")
        {
            $proc = -1;
            $node = -1;
            $self->{targeting}{SYS}[0]{KEY} = $target;

            #SYS target has PHYS_PATH and AFFINITY_PATH defined in the XML
            #Also, there is no HUID for SYS
            $self->setAttribute($target,"FAPI_NAME",getFapiName($type));
            $self->setAttribute($target,"FAPI_POS",      $pos);
            $self->setAttribute($target,"ORDINAL_ID",    $pos);
            $sys_phys = $self->getAttribute($target, "PHYS_PATH");
            $sys_phys = substr($sys_phys, 9);
        }
        elsif ($type eq "NODE")
        {
            $proc                    = -1;
            $self->{membuf_inst_num} = 0;
            $node++;

            $node_phys = "physical:".$sys_phys."/node-$node";
            $node_aff  = "affinity:".$sys_phys."/node-$node";

            $self->{targeting}{SYS}[0]{NODES}[$node]{KEY} = $target;

            $self->setHuid($target, $sys_pos, $node);
            $self->setAttribute($target, "FAPI_NAME",getFapiName($type));
            $self->setAttribute($target, "FAPI_POS",      $pos);
            $self->setAttribute($target, "PHYS_PATH",     $node_phys);
            $self->setAttribute($target, "AFFINITY_PATH", $node_aff);
            $self->setAttribute($target, "ORDINAL_ID",    $pos);
        }
        elsif ($type eq "TPM")
        {
            $tpm++;

            $self->{targeting}{SYS}[0]{NODES}[$node]{TPMS}[$tpm]{KEY} = $target;

            my $tpm_phys = $node_phys . "/tpm-$tpm";
            my $tpm_aff  = $node_aff  . "/tpm-$tpm";


            $self->setHuid($target, $sys_pos, $tpm);
            $self->setAttribute($target, "FAPI_NAME",getFapiName($type));
            $self->setAttribute($target, "FAPI_POS",      $pos);
            $self->setAttribute($target, "PHYS_PATH",     $tpm_phys);
            $self->setAttribute($target, "AFFINITY_PATH", $tpm_aff);
            $self->setAttribute($target, "ORDINAL_ID",    $pos);
        }
        elsif ($type eq "MCS")
        {
            $self->setAttribute($target, "VPD_REC_NUM", 0);
            $self->setAttribute($target, "MEMVPD_POS",
                $self->getAttribute($target, "CHIP_UNIT"));
        }
        elsif ($type eq "MCA")
        {
            my $ddrs = $self->findConnections($target,"DDR4","");
            $self->processDimms($ddrs, $sys_pos, $node_phys, $node, $proc);
        }
        elsif ($type eq "PROC")
        {
            $proc++;
            my $num_mcs = 0;
            ### count number of MCSs
            foreach my $unit (@{ $self->{data}->{TARGETS}{$target}{CHILDREN} })
            {
                my $unit_type = $self->getType($unit);
                if ($unit_type eq "MCBIST")
                {
                    $num_mcs+=2;  # 2 MCS's per MCBIST
                }
            }
            if ($num_mcs > $self->{MAX_MCS})
            {
                $self->{MAX_MCS} = $num_mcs;
            }

            $self->{NUM_PROCS_PER_NODE} = $proc + 1;

            $self->{targeting}->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{KEY} =
                $target;

            my $socket=$self->getTargetParent($self->getTargetParent($target));
            my $parent_affinity = $node_aff  . "/proc-$proc";
            my $parent_physical = $node_phys . "/proc-$proc";

            my $fapi_name = getFapiName($type, $node, $proc);

            $self->setHuid($target, $sys_pos, $node);
            $self->setAttribute($target, "FAPI_NAME",       $fapi_name);
            $self->setAttribute($target, "PHYS_PATH",       $parent_physical);
            $self->setAttribute($target, "AFFINITY_PATH",   $parent_affinity);
            $self->setAttribute($target, "ORDINAL_ID",      $proc);
            $self->setAttribute($target, "POSITION",        $proc);

            $self->setAttribute($target, "FABRIC_GROUP_ID",
                  $self->getAttribute($socket,"FABRIC_GROUP_ID"));
             $self->setAttribute($target, "FABRIC_CHIP_ID",
                  $self->getAttribute($socket,"FABRIC_CHIP_ID"));
            $self->setAttribute($target, "VPD_REC_NUM",    $proc);

            $self->iterateOverChiplets($target, $sys_pos, $node, $proc);
        }
    }
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

    my $target_children  = $self->getTargetChildren($target);

    if ($target_children eq "")
    {
        return "";
    }
    else
    {
        foreach my $child (@{ $self->getTargetChildren($target) })
        {
            my $unit_ptr        = $self->getTarget($child);
            my $unit_type       = $self->getType($child);
            #System XML has some sensor target as hidden children
            #of targets. We don't care for sensors in this function
            #So, we can avoid them with this conditional
            if ($unit_type ne "NA" && $unit_type ne "FSI" &&
                $unit_type ne "PCI")
            {
                #set common attrs for child
                $self->setCommonAttrForChiplet($child, $sys, $node, $proc);
                $self->iterateOverChiplets($child, $sys, $node, $proc);
            }
        }
    }
}

sub setCommonAttrForChiplet
{
    my $self        = shift;
    my $target      = shift;
    my $sys         = shift;
    my $node        = shift;
    my $proc        = shift;

    my $tgt_ptr        = $self->getTarget($target);
    my $tgt_type       = $self->getType($target);

    push(@{$self->{targeting}
            ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{$tgt_type}},
            { 'KEY' => $target });

    #This is a static variable. Persists over time
    #everything that is a grand_children of proc
    state %grand_children;
    if (not %grand_children)
    {
        $grand_children{"EX"}    = 1;
        $grand_children{"CORE"}  = 1;
        $grand_children{"MCS"}   = 1;
        $grand_children{"MCA"}   = 1;
    }

    my $pos             = $self->getAttribute($target, "CHIP_UNIT");
    my $unit_pos        = $pos;

    #HB expects chiplets' positions in AFFINITY_PATH to be relative to the
    #parent, serverwiz outputs it unique/absolute.
    #Since, in P9, each of the chiplets only have
    #up to two children (each eq has 2 ex, each ex has 2 cores, each mcbist has
    #two mcs, etc), we can simply calculate this by (absolute_Pos%2)
    #CHIP_UNIT is absolute position
    if ($grand_children{$tgt_type} eq 1)
    {
        $unit_pos = $pos%2;
    }

    my $parent_affinity = $self->getAttribute(
                          $self->getTargetParent($target),"AFFINITY_PATH");
    my $parent_physical = $self->getAttribute(
                          $self->getTargetParent($target),"PHYS_PATH");

    my $affinity_path   = $parent_affinity . "/" . lc $tgt_type ."-". $unit_pos;
    my $physical_path   = $parent_physical . "/" . lc $tgt_type ."-". $unit_pos;

    my $fapi_name       = getFapiName($tgt_type, $node, $proc, $pos);


    #unique offset per system
    my $offset = ($proc * $maxInstance{$tgt_type}) + $pos;
    $self->{huid_idx}->{$tgt_type} = $offset;
    $self->setHuid($target, $sys, $node);
    $self->setAttribute($target, "FAPI_NAME",       $fapi_name);
    $self->setAttribute($target, "PHYS_PATH",       $physical_path);
    $self->setAttribute($target, "AFFINITY_PATH",   $affinity_path);
    $self->setAttribute($target, "ORDINAL_ID",      $pos);
    $self->setAttribute($target, "FAPI_POS",        $offset);
    $self->setAttribute($target, "REL_POS",         $pos);

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
    }

    if ($nonFapiTargets{$target} eq "NA")
    {
        return $nonFapiTargets{$target};
    }
    elsif ($target eq "SYS")
    {
        return "k0";
    }
    elsif ($target eq "PROC" || $target eq "DIMM")
    {
        if ($node eq "" || $chipPos eq "")
        {
            die "getFapiName: ERROR: Must specify node and chipPos for $target
                 current node: $node, chipPos: $chipPos\n";
        }

        my $chip_name = ($target eq "PROC") ? "pu" : "dimm";

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
        my $fapi_name = sprintf("pu.$target:k0:n%d:s0:p%02d:c%d",
            $node, $chipPos, $chipletPos);
        return $fapi_name;
    }
}

sub getPervasiveForUnit
{
    # Input should be of the form <type><chip unit>, example: "core0"
    my ($unit) = @_;

    # The mapping is a static variable that is preserved across new calls to
    # the function to speed up the mapping performance
    state %unitToPervasive;

    if ( not %unitToPervasive )
    {
        for my $core (0..$maxInstance{"CORE"}-1)
        {
            $unitToPervasive{"CORE$core"} = PERVASIVE_PARENT_CORE_OFFSET+$core;
        }
        for my $eq (0..$maxInstance{"EQ"}-1)
        {
            $unitToPervasive{"EQ$eq"} = PERVASIVE_PARENT_EQ_OFFSET + $eq;
        }
        for my $xbus (0..$maxInstance{"XBUS"}-1)
        {
            $unitToPervasive{"XBUS$xbus"} = PERVASIVE_PARENT_XBUS_OFFSET;
        }
        for my $obus (0..$maxInstance{"OBUS"}-1)
        {
            $unitToPervasive{"OBUS$obus"} = PERVASIVE_PARENT_OBUS_OFFSET+$obus;
        }
        for my $capp (0..$maxInstance{"CAPP"}-1)
        {
            $unitToPervasive{"CAPP$capp"} = 2 * ($capp+1);
        }
        for my $mcbist (0..$maxInstance{"MCBIST"}-1)
        {
            $unitToPervasive{"MCBIST$mcbist"} =
                PERVASIVE_PARENT_MCBIST_OFFSET + $mcbist;
        }
        for my $mcs (0..$maxInstance{"MCS"}-1)
        {
            $unitToPervasive{"MCS$mcs"} =
                PERVASIVE_PARENT_MCS_OFFSET + ($mcs > 1);
        }
        for my $mca (0..$maxInstance{"MCA"}-1)
        {
            $unitToPervasive{"MCA$mca"} =
                PERVASIVE_PARENT_MCA_OFFSET + ($mca > 3);
        }
        for my $pec (0..$maxInstance{"PEC"}-1)
        {
            $unitToPervasive{"PEC$pec"} =
                PERVASIVE_PARENT_PEC_OFFSET + $pec;
        }
        for my $phb (0..$maxInstance{"PHB"}-1)
        {
            $unitToPervasive{"PHB$phb"} =
                PERVASIVE_PARENT_PHB_OFFSET + ($phb>0) + ($phb>2);
        }
        for my $nv (0..$maxInstance{"NV"}-1)
        {
            $unitToPervasive{"NV$nv"} = PERVASIVE_PARENT_NV_OFFSET;
        }
    }

    my $pervasive = "";
    if(exists $unitToPervasive{$unit})
    {
        $pervasive = $unitToPervasive{$unit};
    }

    return $pervasive
}
sub processDimms
{
    my $self        = shift;
    my $ddrs        = shift;
    my $sys         = shift;
    my $node_phys   = shift;
    my $node        = shift;
    my $proc        = shift;

    if ($ddrs ne "")
    {
        #There should be 2 Connections
        #Each MCA has 2 ddr channels
        foreach my $dimms (@{$ddrs->{CONN}})
        {
            my $ddr = $dimms->{SOURCE};
            my $port_num = $self->getAttribute($ddr,"MBA_PORT");
            my $dimm_num = $self->getAttribute($ddr,"MBA_DIMM");
            my $dimm=$dimms->{DEST_PARENT};

            #proc->mcbist->mcs->mca->ddr
            my $mca_target          = $self->getTargetParent($ddr);
            my $mcs_target          = $self->getTargetParent($mca_target);
            my $mcbist_target       = $self->getTargetParent($mcs_target);
            my $proc_target         = $self->getTargetParent($mcbist_target);
            my $dimm_connector_tgt  = $self->getTargetParent($dimm);

            my $mca     = $self->getAttribute($mca_target,       "CHIP_UNIT")%2;
            my $mcs     = $self->getAttribute($mcs_target,       "CHIP_UNIT")%2;
            my $mcbist  = $self->getAttribute($mcbist_target,    "CHIP_UNIT");
            my $dimm_pos= $self->getAttribute($dimm_connector_tgt,"POSITION");

            $self->setAttribute($dimm, "AFFINITY_PATH",
                $self->getAttribute($mcbist_target, "AFFINITY_PATH")
             . "/mcs-$mcs/mca-$mca/dimm-$port_num"
            );

            $self->setAttribute($dimm, "PHYS_PATH",
                $node_phys . "/dimm-" . $dimm_pos);

            my $type       = $self->getType($dimm);

            $self->setAttribute($dimm,"FAPI_NAME",
                    getFapiName($type, $node, $dimm_pos));

            $self->setAttribute($dimm, "ORDINAL_ID",$dimm_pos);
            $self->setAttribute($dimm, "POSITION",  $dimm_pos);
            $self->setAttribute($dimm, "VPD_REC_NUM", $dimm_pos);
            $self->setAttribute($dimm, "REL_POS", $port_num);
            $self->setAttribute($dimm, "MBA_DIMM", $port_num); #which dimm
            $self->setAttribute($dimm, "MBA_PORT", 0);  #0, each MCA is a port

            ## set all FAPI_POS
            my $DIMM_PER_CHANNEL = 2;
            my $mcbist_pos = $proc * $self->{UNIT_COUNTS}->
              {$proc_target}->{MCBIST} +
              $self->getAttribute($mcbist_target,"REL_POS");
            my $mcs_pos = $mcbist_pos * $self->{UNIT_COUNTS}->
              {$mcbist_target}->{MCS} +
              $self->getAttribute($mcs_target,"REL_POS");
            my $mca_pos = $mcs_pos * $self->{UNIT_COUNTS}->
              {$mcs_target}->{MCA} +
              $self->getAttribute($mca_target,"REL_POS");
            my $dimm_pos = $mca_pos * $DIMM_PER_CHANNEL +
                        $self->getAttribute($dimm,"REL_POS");

            $self->setAttribute($mcbist_target, "FAPI_POS",  $mcbist_pos);
            $self->setAttribute($mcs_target, "FAPI_POS",  $mcs_pos);
            $self->setAttribute($mca_target, "FAPI_POS",  $mca_pos);
            $self->setAttribute($dimm, "FAPI_POS",  $dimm_pos);

            $self->{huid_idx}->{$type} = $dimm_pos;
            $self->setHuid($dimm, $sys, $node);

            $self->{targeting}
                  ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{MCBISTS}[$mcbist]
                    {MCSS}[$mcs]{MCAS}[$mca]{DIMMS}[$dimm_pos]{KEY}
                    = $dimm;
        }

    }

}

sub processMcs
{
#@TODO RTC:163874
#Most of the nimmbus functionality is already in incorporated in other
#functions. Leaving this in as we may need this code for centaur/cumulus.
=begin
    my $self            = shift;
    my $unit            = shift;
    my $node            = shift;
    my $proc            = shift;
    my $mcbist          = shift;
    my $parent_affinity = shift;
    my $parent_physical = shift;
    my $node_phys       = shift;

    my $mcs = $self->getAttribute($unit, "CHIP_UNIT");
    my $membufnum = $proc * $self->{MAX_MCS} + $mcs;
    $self->setAttribute($unit, "AFFINITY_PATH",$parent_affinity . "/mcs-$mcs");
    $self->setAttribute($unit, "PHYS_PATH", $parent_physical . "/mcs-$mcs");
    $self->setAttribute($unit, "MCS_NUM",   $mcs);
    $self->setHuid($unit, 0, $node);
    $self->{targeting}{SYS}[0]{NODES}[$node]{MCBISTS}{$mcbist}{MCSS}[$mcs]{KEY}
             = $unit;

#    $self->setAttribute($unit, "EI_BUS_TX_LANE_INVERT","0");
#    $self->setAttribute($unit, "EI_BUS_TX_MSBSWAP","0");
#    $self->setAttribute($unit, "DMI_REFCLOCK_SWIZZLE","0");

    ## Find connected membufs
    my $membuf_dmi = $self->{data}->{TARGETS}{$unit}{CONNECTION}{DEST}[0];
    if (defined($membuf_dmi))
    {
        ## found membuf connected
        my $membuf =
          $self->{data}->{TARGETS}{$membuf_dmi}
          {PARENT};    ## get parent of dmi unit which is membuf
        my $dmi_bus = $self->{data}->{TARGETS}{$unit}{CONNECTION}{BUS}[0];
        $self->setAttribute($membuf, "POSITION",$membufnum);
        $self->setAttribute($membuf, "AFFINITY_PATH",
            $parent_affinity . "/mcs-$mcs/membuf-$membufnum");
        $self->setAttribute($membuf, "PHYS_PATH",
            $node_phys . "/membuf-$membufnum");

        ## copy DMI bus attributes to membuf
        $self->setAttribute($unit, "EI_BUS_TX_LANE_INVERT",
            $dmi_bus->{bus_attribute}->{PROC_TX_LANE_INVERT}->{default});
        $self->setAttribute($unit, "EI_BUS_TX_MSBSWAP",
            $dmi_bus->{bus_attribute}->{PROC_TX_MSBSWAP}->{default});
        $self->setAttribute($membuf, "EI_BUS_TX_LANE_INVERT",
            $dmi_bus->{bus_attribute}->{MEMBUF_TX_LANE_INVERT}->{default});
        $self->setAttribute($membuf, "EI_BUS_TX_MSBSWAP",
            $dmi_bus->{bus_attribute}->{MEMBUF_TX_MSBSWAP}->{default});

        ## auto setup FSI assuming schematic symbol.  If FSI busses are
        ## defined in serverwiz2, this will be overridden
        ## in the schematic symbol, the fsi port num matches dmi ref clk num

        my $fsi_port = $self->{DMI_FSI_MAP}->{$mcs};
        my $proc_key =
            $self->{targeting}->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{KEY};
        my $proc_path = $self->getAttribute($proc_key,"PHYS_PATH");
        $self->setFsiAttributes($membuf,"FSICM",0,$proc_path,$fsi_port,0);
        $self->setAttribute($unit, "DMI_REFCLOCK_SWIZZLE",$fsi_port);
        my $dmi_swizzle =
             $self->getBusAttribute($unit,0,"DMI_REFCLOCK_SWIZZLE");
        if ($dmi_swizzle ne "")
        {
            $self->setAttribute($unit, "DMI_REFCLOCK_SWIZZLE",$dmi_swizzle);
        }

        $self->setHuid($membuf, 0, $node);
        $self->{targeting}
          ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{MCSS}[$mcs] {MEMBUFS}[0]{KEY} =
          $membuf;

        $self->setAttribute($membuf, "ENTITY_INSTANCE",
               $self->{membuf_inst_num});
        $self->{membuf_inst_num}++;
        ## get the mbas
        foreach my $child (@{ $self->{data}->{TARGETS}{$membuf}{CHILDREN} })
        {
            ## need to not hardcard the subunits
            if ($self->getType($child) eq "L4")
            {
                $self->{targeting}
                  ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{MCSS}[$mcs]{MEMBUFS}[0]
                  {L4S}[0] {KEY} = $child;
                $self->setAttribute($child, "AFFINITY_PATH",
                    $parent_affinity . "/mcs-$mcs/membuf-$membufnum/l4-0");
                $self->setAttribute($child, "PHYS_PATH",
                    $node_phys . "/membuf-$membufnum/l4-0");
                $self->setHuid($child, 0, $node);
            }


            if ($self->getType($child) eq "MCA")
            {
                my $mba = $self->getAttribute($child,"MBA_NUM");
                $self->setAttribute($child, "AFFINITY_PATH",
                    $parent_affinity . "/mcs-$mcs/membuf-$membufnum/mba-$mba");
                $self->setAttribute($child, "PHYS_PATH",
                    $node_phys . "/membuf-$membufnum/mba-$mba");
                $self->setHuid($child, 0, $node);
                $self->{targeting}
                  ->{SYS}[0]{NODES}[$node]{PROCS}[$proc]{MCSS}[$mcs]{MEMBUFS}[0]
                  {MBAS}[$mba]{KEY} = $child;

                ## Trace the DDR busses to find connected DIMM
                my $ddrs = $self->findConnections($child,"DDR4","");
                if ($ddrs ne "")
                {

                    my $affinitypos=0;
                    foreach my $dimms (@{$ddrs->{CONN}})
                    {
                        my $ddr = $dimms->{SOURCE};
                        my $port_num = $self->getAttribute($ddr,"MBA_PORT");
                        my $dimm_num = $self->getAttribute($ddr,"MBA_DIMM");
                        my $dimm=$dimms->{DEST_PARENT};
                        $self->setAttribute($dimm,"MBA_PORT",$port_num);
                        $self->setAttribute($dimm,"MBA_DIMM",$dimm_num);

                        my $aff_pos=16*$proc+$mcs*$self->{MAX_MCS}+4*$mba+
                                    2*$port_num+$dimm_num;
                        $self->setAttribute($dimm, "AFFINITY_PATH",
                            $parent_affinity
                      . "/mcs-$mcs/membuf-$membufnum/mba-$mba/dimm-$affinitypos"
                        );
                        $self->setAttribute($dimm, "PHYS_PATH",
                            $node_phys . "/dimm-" . $self->{dimm_tpos});
                        $self->setAttribute($dimm, "POSITION",
                            $aff_pos);
                        $self->setAttribute($dimm, "VPD_REC_NUM",
                            $aff_pos);
                        $self->setHuid($dimm, 0, $node);
                        $self->{targeting}
                          ->{SYS}[0]{NODES}[$node]{PROCS}[$proc] {MCSS}[$mcs]
                          {MEMBUFS}[0]{MBAS}[$mba] {DIMMS}[$affinitypos]{KEY} =
                          $dimm;
                        $self->setAttribute($dimm, "ENTITY_INSTANCE",
                             $self->{dimm_tpos});
                        $self->{dimm_tpos}++;
                        $affinitypos++;
                    }
                }
            }
        }
    }
=cut
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

    $self->setAttribute($target, "FSI_MASTER_TYPE","NO_MASTER");
    if ($type eq "FSIM")
    {
        $self->setAttribute($target, "FSI_MASTER_TYPE","MFSI");
    }
    if ($type eq "FSICM")
    {
        $self->setAttribute($target, "FSI_MASTER_TYPE","CMFSI");
    }
    $self->setAttribute($target, "FSI_MASTER_CHIP","physical:sys");
    $self->setAttribute($target, "FSI_MASTER_PORT","0xFF");
    $self->setAttribute($target, "ALTFSI_MASTER_CHIP","physical:sys");
    $self->setAttribute($target, "ALTFSI_MASTER_PORT","0xFF");
    $self->setAttribute($target, "FSI_SLAVE_CASCADE", "0");
    if ($cmfsi == 0)
    {
        $self->setAttribute($target, "FSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "FSI_MASTER_PORT", $fsi_port);
    }
    else
    {
        $self->setAttribute($target, "ALTFSI_MASTER_CHIP",$phys_path);
        $self->setAttribute($target, "ALTFSI_MASTER_PORT", $fsi_port);
    }

    $self->setAttributeField($target, "FSI_OPTION_FLAGS","flipPort",
          $flip_port);
    $self->setAttributeField($target, "FSI_OPTION_FLAGS","reserved", "0");

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

sub getConnectionBus
{
    my $self       = shift;
    my $target     = shift;
    my $i          = shift;
    my $target_ptr = $self->getTarget($target);
    return $target_ptr->{CONNECTION}->{BUS}->[$i];
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
sub findConnections
{
    my $self     = shift;
    my $target   = shift;
    my $bus_type = shift;
    my $end_type = shift;

    my %connections;
    my $num=0;
    my $target_children = $self->getTargetChildren($target);
    if ($target_children eq "")
    {
        return "";
    }

    foreach my $child ($self->getAllTargetChildren($target))
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
                my $dest_class  = $self->getAttribute($dest_parent,"CLASS");
                if ($type eq "NA")
                {
                    $type = $dest_type;
                }
                if ($type eq "NA") {
                    $type = $dest_class;
                }

                if ($end_type ne "") {
                    #Look for an end_type match on any ancestor, as
                    #connections may have a destination unit with a hierarchy
                    #like unit->pingroup->muxgroup->chip where the chip has
                    #the interesting type.
                    while ($type ne $end_type) {

                        $dest_parent = $self->getTargetParent($dest_parent);
                        if ($dest_parent eq "") {
                            last;
                        }

                        $type = $self->getMrwType($dest_parent);
                        if ($type eq "NA") {
                            $type = $self->getType($dest_parent);
                        }
                        if ($type eq "NA") {
                            $type = $self->getAttribute($dest_parent, "CLASS");
                        }
                    }
                }

                if ($type eq $end_type || $end_type eq "")
                {
                    $connections{CONN}[$num]{SOURCE}=$child;
                    $connections{CONN}[$num]{SOURCE_PARENT}=$target;
                    $connections{CONN}[$num]{DEST}=$dest_target;
                    $connections{CONN}[$num]{DEST_PARENT}=$dest_parent;
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

    my $type    = $self->getType($target);
    my $type_id = $self->{enumeration}->{TYPE}->{$type};
    if ($type_id eq "") { $type_id = 0; }
    if ($type_id == 0) { return; }
    my $index = 0;
    if (defined($self->{huid_idx}->{$type}))
    {
        $index = $self->{huid_idx}->{$type};
    }
    else { $self->{huid_idx}->{$type} = 0; }

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
    if (!defined $mru_prefix_id || $mru_prefix_id eq "")
    {
         $mru_prefix_id = "0xFFFF";
    }
    if ($mru_prefix_id eq "0xFFFF") { return; }
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

1;

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

=item getConnectionBus(C<TARGET_STRING>)

Returns the data structure of the C<INDEX> bus target found connected to
C<TARGET_STRING>.

=item findEndpoint(C<TARGET_STRING>,C<BUS_TYPE>,C<ENDPOINT_MRW_TYPE>)

Searches through all connections to C<TARGET_STRING>
for a endpoint C<MRW_TYPE> and C<BUS_TYPE>

=item getBusType(C<TARGET_STRING>)

Returns the BUS_TYPE attribute of (C<TARGET_STRING>).  Examples are I2C and DMI.

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
