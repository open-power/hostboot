#! /usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/processMrw.pl $
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

###############################################################################
# Include these libraries
###############################################################################
use strict;
use XML::Simple;
use Data::Dumper;
use Targets;
use Math::BigInt;
use Getopt::Long;
use File::Basename;

###############################################################################
# Define some global constants
###############################################################################
# Create a Target object
my $targetObj = Targets->new;

# Define a true and false keyword
use constant { true => 1, false => 0 };

use constant HZ_PER_KHZ=>1000;

our %hwsvmrw_plugins;

###############################################################################
# Main - The starting point for this script
###############################################################################
main($targetObj);
exit 0;  # YOU SHALL NOT PASS!! All code should start in sub main

#--------------------------------------------------
# @brief Print usage statement and exit
#--------------------------------------------------
sub printUsage
{
    print "
processMrwl.pl -x [XML filename] [OPTIONS]
Options:
        -build <hb | fsp> = hb  - process HB targets only (the default)
                            fsp - process FSP targets in addition to HB targets
        -c <2N | w> = special configurations we want to run
                      2N - special 2 node config with extra ABUS links
                      w - Special MST wrap config
        -d = run in debug mode
        -f = force output file creation even when errors
        -o <filename> = output filename
        -r = create report and save to [system_name].rpt
        -s = run in silent mode, suppress warnings but not errors,
             use judiciously
        -t = run self test
";
    exit(1);
}

#--------------------------------------------------
# @brief main
#
# @details The real starting point of this script.
#--------------------------------------------------
sub main
{
    my $targetObj = shift;

    # Extract the caller's options off the command line and validate.
    # Will exit if options are not valid.
    getAndValidateCallerInputOptions($targetObj);

    # Run tests if asked to do so
    if ($targetObj->{run_self_test} == 1)
    {
        runTests($targetObj);
        return 0;
    }

    # Load the XML and process the file, extracting targets and associated
    # attributes, with their data, to the targets.
    loadXmlFile($targetObj);

    if ($targetObj->{build} eq "fsp")
    {
        eval ("use processMrw_fsp; return 1;");
        processMrw_fsp::return_plugins();
    }

    # Write the report
    writeReport($targetObj);

    # Process the targets - set some needed attribute values
    processTargets($targetObj);

    if ($targetObj->{build} eq "fsp")
    {
        processMrw_fsp::loadFSP($targetObj);
    }

    # Check for errors in the targets
    errorCheckTheTargets($targetObj);

    # Write the results of processing the targets to an XML file
    writeResultsToXml($targetObj);
}

###############################################################################
# Supporting subroutines
###############################################################################
#--------------------------------------------------
# @brief Extract caller's command line options
#
# @details Extract caller's command line options and
#          validate them.  If valid then store in the
#          global Target object for easy retrieval.
#          If options are not valid, then print
#          usage statement and exit script.
#--------------------------------------------------
sub getAndValidateCallerInputOptions
{
    my $targetObj = shift;

    # Local variables, and their defaults, to cache the command line options to
    my $serverwiz_file  = "";
    my $build           = "hb";  # Used to process HB targets only or FSP and HB
                                 # targets.  Process HB targets is the default.
                                 # It is also used as a tag for the generated
                                 # output file, if no output file given.
    my $system_config   = "";
    my $debug           = 0;
    my $force           = 0;
    my $output_file     = "";
    my $report          = 0;
    my $stealth_mode    = 0;  # Only print errors not warnings
    my $run_self_test   = 0;
    my $version         = 0;

    # Grab the user's command line options.  If an option is not recognized,
    # print usage statement and exit script.
    GetOptions(
        "x=s" => \$serverwiz_file, # string (mandatory)
        # The following options are optional
        "build=s" => \$build,      # string
        "c=s" => \$system_config,  # string
        "d"   => \$debug,          # flag
        "f"   => \$force,          # numeric
        "o=s" => \$output_file,    # string
        "r"   => \$report,         # flag
        "s"   => \$stealth_mode,   # flag
        "t"   => \$run_self_test,  # flag
      )
      or printUsage();

    # If caller did not specify an input file, then print usage and exit
    if ($serverwiz_file eq "")
    {
        printUsage();
    }

    # If caller used an invalid option for 'system_config' then state so and exit
    if ( ($system_config ne "")     &&
         ($system_config ne "2N")   &&
         ($system_config ne "w")  )

    {
        print "\nInvalid input \"$system_config\" for option -c\n";
        printUsage();
    }

    # If caller used an invalid option for 'build' then state so and exit
    if ( ($build ne "")     &&
         ($build ne "hb")   &&
         ($build ne "fsp")  )

    {
        print "\nInvalid input \"$build\" for option -build\n";
        printUsage();
    }

    # Save the caller's input options to global storage for easy retrieval
    $targetObj->{serverwiz_file} = $serverwiz_file;
    $targetObj->{serverwiz_dir} = dirname($serverwiz_file);
    $targetObj->{build} = $build;
    $targetObj->{system_config} = $system_config;
    $targetObj->{debug} = $debug;
    $targetObj->{force} = $force;
    $targetObj->{output_file} = $output_file;
    $targetObj->{report} = $report;
    $targetObj->{stealth_mode} = $stealth_mode;
    $targetObj->{run_self_test} = $run_self_test;

} # end getAndValidateCallerInputOptions


# loadXmlFile
sub loadXmlFile
{
    my $targetObj = shift;

    $XML::Simple::PREFERRED_PARSER = 'XML::Parser';
    $targetObj->loadXML($targetObj->{serverwiz_file});

    # Set the version number to the given input XML file
    $targetObj->setVersion();
} # end loadXmlFile

# writeReport
sub writeReport
{
    my $targetObj = shift;

    my $str=sprintf(
        " %30s | %10s | %6s | %4s | %9s | %4s | %4s | %4s | %10s | %s\n",
        "Sensor Name","FRU Name","Ent ID","Type","Evt Type","ID","Inst","FRU",
        "HUID","Target");

    $targetObj->writeReport($str);
    my $str=sprintf(
        " %30s | %10s | %6s | %4s | %9s | %4s | %4s | %4s | %10s | %s\n",
        "------------------------------","----------",
        "------","----","---------","----","----","----","----------",
        "----------");

    $targetObj->writeReport($str);
} # end loadXmlFile

# convert a number string into a bit-position number
# example:  "0x02" -->  0b0100 = 4
sub numToBitPositionNum
{
    my ($hexStr) = @_;

    my $num = 0x0001;
    my $newNum = $num << hex($hexStr);

    return $newNum;
}


#  @brief Returns whether system has multiple possible TPMs or not
#
#  @par Detailed Description:
#      Returns whether system has multiple possible TPMs or not.
#      The MRW parser activates more complicated I2C master detection logic when
#      a system blueprint defines more than one TPM, in order to avoid having to
#      fix other non-compliant workbooks.  If every workbook is determined to
#      model the TPM and its I2C connection properly, this special case can be
#      removed.
#
#  @param[in] $targetsRef Reference to array of targets in the system
#  @retval 0 System does not have multiple possible TPMs
#  @retval 1 System has multiple possible TPMs
#
#  @TODO RTC: 189374 Remove API when all platforms' MRW supports dynamically
#      determining the processor driving it.

sub isMultiTpmSystem
{
    my $targetObj = shift;
    my $targetsRef = shift;

    my $tpms=0;
    foreach my $target (@$targetsRef)
    {
        my $type = $targetObj->getType($target);
        if($type eq "TPM")
        {
            ++$tpms;
            if($tpms >1)
            {
                last;
            }
        }
    }

    return ($tpms > 1) ? 1 : 0;
}

#--------------------------------------------------
# @brief Loop through all targets and set attributes as needed
#
# @param [in] $targetObj - The global target object.
#--------------------------------------------------
sub processTargets
{
    my $targetObj = shift;
    my @targets = sort keys %{ $targetObj->getAllTargets() };
    my $isMultiTpmSys = isMultiTpmSystem($targetObj, \@targets);

    foreach my $target (@targets)
    {
        my $type = $targetObj->getType($target);
        if ($type eq "SYS")
        {
            processSystem($targetObj, $target);

            my $maxComputeNodes  = get_max_compute_nodes($targetObj , $target);
            $targetObj->setAttribute($target, "MAX_COMPUTE_NODES_PER_SYSTEM", $maxComputeNodes);

            #handle enumeration changes
            my $enum_val = $targetObj->getAttribute($target,"PROC_FABRIC_PUMP_MODE");
            if ( $enum_val =~ /MODE1/i)
            {
                $targetObj->setAttribute($target,"PROC_FABRIC_PUMP_MODE","CHIP_IS_NODE");
            }
            elsif ( $enum_val =~ /MODE2/i)
            {
                $targetObj->setAttribute($target,"PROC_FABRIC_PUMP_MODE","CHIP_IS_GROUP");
            }
        }
        elsif ($type eq "PROC")
        {
            processProcessor($targetObj, $target);

            if ($targetObj->{build} eq "fsp")
            {
                do_plugin("fsp_proc", $targetObj, $target);
            }
        }
        elsif ($type eq "APSS")
        {
            processApss($targetObj, $target);
        }

        # @TODO RTC: 189374 Remove multiple TPMs filter when all platforms' MRW
        # supports dynamically determining the processor driving it.
        elsif (($type eq "TPM") && $isMultiTpmSys)
        {
            processTpm($targetObj, $target);
        }
        elsif ($type eq "POWER_SEQUENCER")
        {
            my $target_type = $targetObj->getTargetType($target);

            # Strip off the chip- part of the target type name
            $target_type =~ s/chip\-//g;

            # Currently only UCD9090 and UCD90120A on FSP systems are supported.
            # All other UCD types are skipped.
            if (($target_type eq "UCD9090")
                || ($target_type eq "UCD90120A"))
            {
                processUcd($targetObj, $target);
            }
        }
        elsif ($type eq "OCMB_CHIP")
        {
            processOcmbChip($targetObj, $target);
        }

        # Once processing of the target type is complete, remove
        # deprecated and un-needed attributes for this type
        pruneTargetAttributes($targetObj, $target, $type);

        processIpmiSensors($targetObj,$target);
    }  # end foreach my $target (@targets)

} # end processTargets

#--------------------------------------------------
# @brief Check the processed targets for errors
#
# @param [in] $targetObj - The global target object.
#--------------------------------------------------
sub errorCheckTheTargets
{
    my $targetObj = shift;

    # Check topology
    foreach my $n (keys %{$targetObj->{TOPOLOGY}})
    {
        if ($targetObj->{TOPOLOGY}->{$n} > 1)
        {
            print "ERROR: Fabric topology invalid.  2 targets have same ".
                  "FABRIC_TOPOLOGY_ID ($n)\n";
            $targetObj->myExit(3);
        }
    }

    # Check for errors
    foreach my $target (keys %{ $targetObj->getAllTargets() })
    {
# TODO, RTC 215164. Having issues with power10-0 so wrapped errorCheck with if statement:
# ERROR: EEPROM_VPD_PRIMARY_INFO/devAddr attribute is invalid (Target=/sys-0/node-0/nisqually-0/proc_socket-0/godel-0/power10-0)
#	I2C connection to target is not defined
## Once resolved, will remove if statement
        if ($target != "/sys-0/node-0/nisqually-0/proc_socket-0/godel-0/power10-0")
        {
            errorCheck($targetObj, $target);
        }
    }
} # end sub errorCheckTheTargets

#--------------------------------------------------
# @brief Write out the results to an XML file
#
# @param [in] $targetObj - The global target object.
#--------------------------------------------------
sub writeResultsToXml
{
    my $targetObj = shift;

    my $xml_fh;
    my $filename;
    my $config_str = $targetObj->{system_config};

    #If user did not specify the output filename, then build one up by using
    #config and build parameters
    if ($targetObj->{output_file} eq "")
    {
        if ($config_str ne "")
        {
            $config_str = "_" . $config_str;
        }

        $filename = $targetObj->{serverwiz_dir} . "/" . $targetObj->getSystemName() . $config_str . "_" . $targetObj->{build} . ".mrw.xml";
    }
    else
    {
        $filename = $targetObj->{output_file};
    }

    print "Creating XML: $filename\n";
    open($xml_fh, ">$filename") || die "Unable to create: $filename";

    $targetObj->printXML($xml_fh, "top", $targetObj->{build});
    close $xml_fh;
    if (!$targetObj->{errorsExist})
    {
        ## optionally print out report
        if ($targetObj->{report})
        {
            print "Writing report to: ".$targetObj->{report_filename}."\n";
            $targetObj->writeReportFile();
        }
        print "MRW created successfully!\n";
    }
} # end sub writeResultsToXml

#--------------------------------------------------
# @brief Remove attributes associated with target.
#        Either because they have been deprecated
#        or simply not used/needed.
#
# @param[in] $targetObj - The global target object blob
# @param[in] $target - The target to remove attributes from
# @param[in] $type -   The type of the target
#
# TODO RTC: 178351 Remove depricated Attribute from HB XML
# these are obsolete
#
#--------------------------------------------------
sub pruneTargetAttributes
{
    my $targetObj = shift;
    my $target    = shift;
    my $type      = shift;

    if ($type eq "PHB")
    {
        $targetObj->deleteAttribute($target,"DEVICE_ID");
        $targetObj->deleteAttribute($target,"DEVICE_ID");
        $targetObj->deleteAttribute($target,"HDDW_ORDER");
        $targetObj->deleteAttribute($target,"MAX_POWER");
        $targetObj->deleteAttribute($target,"MGC_LOAD_SOURCE");
        $targetObj->deleteAttribute($target,"PCIE_32BIT_DMA_SIZE");
        $targetObj->deleteAttribute($target,"PCIE_32BIT_MMIO_SIZE");
        $targetObj->deleteAttribute($target,"PCIE_64BIT_DMA_SIZE");
        $targetObj->deleteAttribute($target,"PCIE_64BIT_MMIO_SIZE");
        $targetObj->deleteAttribute($target,"PCIE_CAPABILITES");
        $targetObj->deleteAttribute($target,"SLOT_INDEX");
        $targetObj->deleteAttribute($target,"SLOT_NAME");
        $targetObj->deleteAttribute($target,"VENDOR_ID");
    }
}  # end pruneTargetAttributes

#--------------------------------------------------
#--------------------------------------------------
## Processing subroutines

#--------------------------------------------------

#--------------------------------------------------
## System
##

sub processSystem
{
    my $targetObj = shift;
    my $target    = shift;

    $targetObj->setAttribute($target, "MAX_MCS_PER_SYSTEM",
        $targetObj->{NUM_PROCS_PER_NODE} * $targetObj->{MAX_MCS});
    $targetObj->setAttribute($target, "MAX_PROC_CHIPS_PER_NODE",
        $targetObj->{NUM_PROCS_PER_NODE});
    parseBitwise($targetObj,$target,"CDM_POLICIES");

    #Delete this attribute if it is leftover from an old format
    if (!$targetObj->isBadAttribute($target,"XSCOM_BASE_ADDRESS") )
    {
        $targetObj->deleteAttribute($target,"XSCOM_BASE_ADDRESS");
    }
}

sub processIpmiSensors {
    my $targetObj=shift;
    my $target=shift;

    if ($targetObj->isBadAttribute($target,"IPMI_INSTANCE") ||
        $targetObj->getMrwType($target) eq "IPMI_SENSOR" ||
        $targetObj->getTargetChildren($target) eq "")
    {
        return;
    }

    my $instance=$targetObj->getAttribute($target,"IPMI_INSTANCE");
    my $name="";
    if (!$targetObj->isBadAttribute($target,"FRU_NAME"))
    {
        $name=$targetObj->getAttribute($target,"FRU_NAME");
    }
    my $fru_id="N/A";
    if (!$targetObj->isBadAttribute($target,"FRU_ID"))
    {
        $fru_id=$targetObj->getAttribute($target,"FRU_ID");
    }
    my $huid="";
    if (!$targetObj->isBadAttribute($target,"HUID"))
    {
        $huid=$targetObj->getAttribute($target,"HUID");
    }
    my @sensors;
    my %sensorIdsCnt;

    foreach my $child (@{$targetObj->getTargetChildren($target)})
    {
        if ($targetObj->getMrwType($child) eq "IPMI_SENSOR")
        {
            my $entity_id=$targetObj->
                 getAttribute($child,"IPMI_ENTITY_ID");
            my $sensor_type=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_TYPE");
            my $name_suffix=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_NAME_SUFFIX");
            my $sensor_id=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_ID");
            my $sensor_evt=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_READING_TYPE");


            $name_suffix=~s/\n//g;
            $name_suffix=~s/\s+//g;
            $name_suffix=~s/\t+//g;
            my $sensor_name=$name_suffix;
            if ($name ne "")
            {
                $sensor_name=$name."_".$name_suffix;
            }
            my $attribute_name="";
            my $s=sprintf("0x%02X%02X,0x%02X",
                  oct($sensor_type),oct($entity_id),oct($sensor_id));
            push(@sensors,$s);
            my $sensor_id_str = "";
            if ($sensor_id ne "")
            {
                $sensor_id_str = sprintf("0x%02X",oct($sensor_id));
            }
            my $str=sprintf(
                " %30s | %10s |  0x%02X  | 0x%02X |    0x%02x   |" .
                " %4s | %4d | %4d | %10s | %s\n",
                $sensor_name,$name,oct($entity_id),oct($sensor_type),
                oct($sensor_evt), $sensor_id_str,$instance,$fru_id,
                $huid,$target);

            # Check that the sensor id hasn't already been used.  Don't check
            # blank sensor ids.
            if (($sensor_id ne "") && (++$sensorIdsCnt{$sensor_id} >= 2)) {
                print "ERROR: Duplicate IPMI_SENSOR_ID ($sensor_id_str)" .
                      " found in MRW.  Sensor name is $sensor_name.\n";
                print "$str";
                $targetObj->myExit(3);
            }

            $targetObj->writeReport($str);
        }
    }
    for (my $i=@sensors;$i<16;$i++)
    {
        push(@sensors,"0xFFFF,0xFF");
    }
    my @sensors_sort = sort(@sensors);
    $targetObj->setAttribute($target,
                 "IPMI_SENSORS",join(',',@sensors_sort));
}

sub processApss {
    my $targetObj=shift;
    my $target=shift;

    my $systemTarget = $targetObj->getTargetParent($target);
    my @sensors;
    my @channel_ids;
    my @channel_offsets;
    my @channel_gains;
    my @channel_grounds;
    my @gpios;

    foreach my $child (@{$targetObj->getTargetChildren($target)})
    {
        if ($targetObj->getMrwType($child) eq "APSS_SENSOR")
        {
            my $entity_id=$targetObj->
                 getAttribute($child,"IPMI_ENTITY_ID");
            my $sensor_id=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_ID");
            my $sensor_type=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_TYPE");
            my $sensor_evt=$targetObj->
                 getAttribute($child,"IPMI_SENSOR_READING_TYPE");

            #@fixme-RTC:175309-Remove deprecated support
            my $name;
            my $channel;
            my $channel_id;
            my $channel_gain;
            my $channel_offset;
            my $channel_ground;
            # Temporarily allow both old and new attribute names until
            #  all of the SW2 xmls get in sync
            if (!$targetObj->isBadAttribute($child,"IPMI_SENSOR_NAME_SUFFIX") )
            {
                # Using deprecated names
                $name = $targetObj->
                  getAttribute($child,"IPMI_SENSOR_NAME_SUFFIX");
                $channel = $targetObj->
                  getAttribute($child,"ADC_CHANNEL_ASSIGNMENT");
                $channel_id = $targetObj->
                  getAttribute($child,"ADC_CHANNEL_ID");
                $channel_gain = $targetObj->
                  getAttribute($child,"ADC_CHANNEL_GAIN");
                $channel_offset = $targetObj->
                  getAttribute($child,"ADC_CHANNEL_OFFSET");
                $channel_ground = $targetObj->
                  getAttribute($child,"ADC_CHANNEL_GROUND");
            }
            else
            {
                # Using correct/new names
                $name = $targetObj->
                  getAttribute($child,"FUNCTION_NAME");
                $channel = $targetObj->
                  getAttribute($child,"CHANNEL");
                $channel_id = $targetObj->
                  getAttribute($child,"FUNCTION_ID");
                $channel_gain = $targetObj->
                  getAttribute($child,"GAIN");
                $channel_offset = $targetObj->
                  getAttribute($child,"OFFSET");
                $channel_ground = $targetObj->
                  getAttribute($child,"GND");
            }

            $name=~s/\n//g;
            $name=~s/\s+//g;
            $name=~s/\t+//g;

            my $sensor_id_str = "";
            if ($sensor_id ne "")
            {
                $sensor_id_str = sprintf("0x%02X",oct($sensor_id));
            }
            if ($channel ne "")
            {
                $sensors[$channel] = $sensor_id_str;
                $channel_ids[$channel] = $channel_id;
                $channel_grounds[$channel] = $channel_ground;
                $channel_offsets[$channel] = $channel_offset;
                $channel_gains[$channel] = $channel_gain;
            }
            my $str=sprintf(
                    " %30s | %10s |  0x%02X  | 0x%02X |    0x%02x   |" .
                    " %4s | %4d | %4d | %10s | %s\n",
                    $name,"",oct($entity_id),oct($sensor_type),
                    oct($sensor_evt),$sensor_id_str,$channel,"","",
                    $systemTarget);

            $targetObj->writeReport($str);
        } # end if ($targetObj->getMrwType($child) eq "APSS_SENSOR")
        elsif ($targetObj->getMrwType($child) eq "APSS_GPIO")
        {
            my $function_id=$targetObj->
                 getAttribute($child,"FUNCTION_ID");
            my $port=$targetObj->
                 getAttribute($child,"PORT");

            if ($port ne "")
            {
                $gpios[$port] = $function_id;
            }
        } # end elsif ($targetObj->getMrwType($child) eq "APSS_GPIO")
    } # end foreach my $child (@{$targetObj->getTargetChildren($target)})

    for (my $i=0;$i<16;$i++)
    {
        if ($sensors[$i] eq "")
        {
            $sensors[$i]="0x00";
        }
        if ($channel_ids[$i] eq "")
        {
            $channel_ids[$i]="0";
        }
        if ($channel_grounds[$i] eq "")
        {
            $channel_grounds[$i]="0";
        }
        if ($channel_gains[$i] eq "")
        {
            $channel_gains[$i]="0";
        }
        if ($channel_offsets[$i] eq "")
        {
            $channel_offsets[$i]="0";
        }
        if ($gpios[$i] eq "")
        {
            $gpios[$i]="0";
        }
    }

    $targetObj->setAttribute($systemTarget,
                 "ADC_CHANNEL_FUNC_IDS",join(',',@channel_ids));
    $targetObj->setAttribute($systemTarget,
                 "ADC_CHANNEL_SENSOR_NUMBERS",join(',',@sensors));
    $targetObj->setAttribute($systemTarget,
                 "ADC_CHANNEL_GNDS",join(',',@channel_grounds));
    $targetObj->setAttribute($systemTarget,
                 "ADC_CHANNEL_GAINS",join(',',@channel_gains));
    $targetObj->setAttribute($systemTarget,
                 "ADC_CHANNEL_OFFSETS",join(',',@channel_offsets));
    $targetObj->setAttribute($systemTarget,
                 "APSS_GPIO_PORT_PINS",join(',',@gpios));

    convertNegativeNumbers($targetObj,$systemTarget,"ADC_CHANNEL_OFFSETS",32);
}

sub convertNegativeNumbers
{
    my $targetObj=shift;
    my $target=shift;
    my $attribute=shift;
    my $numbits=shift;

    my @offset = split(/\,/,
                 $targetObj->getAttribute($target,$attribute));
    for (my $i=0;$i<@offset;$i++)
    {
        if ($offset[$i]<0)
        {
            my $neg_offset = 2**$numbits+$offset[$i];
            $offset[$i]=sprintf("0x%08X",$neg_offset);
        }
    }
    my $new_offset = join(',',@offset);
    $targetObj->setAttribute($target,$attribute,$new_offset)
}

sub parseBitwise
{
    my $targetObj = shift;
    my $target = shift;
    my $attribute = shift;
    my $mask = 0;

    #if CDM_POLICIES_BITMASK is not a bad attribute, aka if it is defined
    if (!$targetObj->isBadAttribute($target, $attribute."_BITMASK"))
    {
        foreach my $e (keys %{ $targetObj->getEnumHash($attribute)})
        {
            my $field = $targetObj->getAttributeField(
                        $target,$attribute."_BITMASK",$e);
            my $val=hex($targetObj->getEnumValue($attribute,$e));
            if ($field eq "true")
            {
                $mask=$mask | $val;
            }
        }
        $targetObj->setAttribute($target,$attribute,$mask);
    }
}

#  @brief Processes a TPM target
#
#  @par Detailed Description:
#      Processes a TPM target; notably determines the TPM's I2C master chip and
#      updates the associated field in the TPM_INFO attribute, especially useful
#      on multi-node or multi-TPM systems.
#
#  @param[in] $targetObj Object model reference
#  @param[in] $target    Handle of the target to process

sub processTpm
{
    my $targetObj = shift;
    my $target    = shift;

    # Get any connection involving TPM target's child I2C slave targets
    my $i2cBuses=$targetObj->findDestConnections($target,"I2C","");
    if ($i2cBuses ne "")
    {
        foreach my $i2cBus (@{$i2cBuses->{CONN}})
        {
            # On the I2C master side of the connection, ascend one level to the
            # parent chip
            my $i2cMasterParentTarget=$i2cBus->{SOURCE_PARENT};
            my $i2cMasterParentTargetType =
                $targetObj->getType($i2cMasterParentTarget);

            # Hostboot code assumes CEC TPMs are only connected to processors.
            # Unless that assumption changes, this sanity check is required to
            # catch modeling errors.
            if($i2cMasterParentTargetType ne "PROC")
            {
                die   "Model integrity error; CEC TPM I2C connections must "
                    . "originate at a PROC target, not a "
                    . "$i2cMasterParentTargetType target.\n";
            }

            # Get its physical path
            my $i2cMasterParentTargetPath = $targetObj->getAttribute(
                $i2cMasterParentTarget,"PHYS_PATH");

            # Set the TPM's I2C master path accordingly
            $targetObj->setAttributeField(
                $target, "TPM_INFO","i2cMasterPath",
                $i2cMasterParentTargetPath);

            # All TPM I2C buses must be driven from the same I2C master, so only
            # process the first one
            last;
        }
    }
}

sub processUcd
{
    my $targetObj = shift;
    my $target    = shift;

    # Get any connection involving UCD target's child I2C slave targets
    my $i2cBuses=$targetObj->findDestConnections($target,"I2C","");
    if ($i2cBuses ne "")
    {
        foreach my $i2cBus (@{$i2cBuses->{CONN}})
        {
            # On the I2C master side of the connection, ascend one level to the
            # parent chip
            my $i2cMasterParentTarget=$i2cBus->{SOURCE_PARENT};
            my $i2cMasterParentTargetType =
                $targetObj->getType($i2cMasterParentTarget);

            # Hostboot code assumes UCDs are only connected to processors.
            if($i2cMasterParentTargetType ne "PROC")
            {
                die   "Model integrity error; UCD I2C connections must "
                    . "originate at a PROC target, not a "
                    . "$i2cMasterParentTargetType target.\n";
            }

            # Get the processor's physical path
            my $i2cMasterParentTargetPath = $targetObj->getAttribute(
                $i2cMasterParentTarget,"PHYS_PATH");

            # Set the UCD's I2C master path accordingly
            $targetObj->setAttributeField(
                $target, "I2C_CONTROL_INFO","i2cMasterPath",
                $i2cMasterParentTargetPath);

            # Set the UCD's I2C port and engine by accessing the
            # i2cMaster target and getting the data from it.
            my $i2cMaster = $i2cBus->{SOURCE};
            my $i2cPort = $targetObj->getAttribute($i2cMaster, "I2C_PORT");
            my $i2cEngine = $targetObj->getAttribute($i2cMaster, "I2C_ENGINE");

            $targetObj->setAttributeField($target, "I2C_CONTROL_INFO",
                                          "port", $i2cPort);

            $targetObj->setAttributeField($target, "I2C_CONTROL_INFO",
                                          "engine", $i2cEngine);

            # Set the UCD's device address by accessing the bus
            my $addr = "";
            if ($targetObj->isBusAttributeDefined(
                $i2cBus->{SOURCE},$i2cBus->{BUS_NUM},"I2C_ADDRESS"))
            {
                $addr = $targetObj->getBusAttribute($i2cBus->{SOURCE},
                    $i2cBus->{BUS_NUM}, "I2C_ADDRESS");
            }

            # If bus doesn't have I2C_ADDRESS or default value is not set,
            # then get it from i2c-slave, if defined.
            if ($addr eq "")
            {
                if (! $targetObj->isBadAttribute($i2cBus->{DEST},"I2C_ADDRESS"))
                {
                    $addr = $targetObj->getAttribute($i2cBus->{DEST},
                                                    "I2C_ADDRESS");
                }
            }

            #if the addr is still not defined, then throw an error
            if ($addr eq "")
            {
                print ("ERROR: I2C_ADDRESS is not defined for $i2cBus\n");
                $targetObj->myExit(4);
            }

            $targetObj->setAttributeField(
                $target, "I2C_CONTROL_INFO","devAddr",$addr);

            last;
        }
    }
}

#--------------------------------------------------
# @brief Process processors
#
#--------------------------------------------------
sub processProcessor
{
    my $targetObj = shift;
    my $target    = shift;

    #########################
    ## In serverwiz, processor instances are not unique
    ## because plugged into socket
    ## so processor instance unique attributes are socket level.
    ## The grandparent is guaranteed to be socket.
    my $socket_target =
       $targetObj->getTargetParent($targetObj->getTargetParent($target));
    $targetObj->copyAttribute($socket_target,$target,"LOCATION_CODE");

    ## Module attibutes are inherited into the proc target
    my $module_target =
       $targetObj->getTargetParent($target);
    $targetObj->copyAttribute($module_target,$target,"LOCATION_CODE");

    ## Copy PCIE attributes from socket
    ## Copy PBAX attributes from socket
    foreach my $attr (sort (keys
           %{ $targetObj->getTarget($socket_target)->{TARGET}->{attribute} }))
    {
        if ($attr =~ /PROC\_PCIE/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/PBAX_BRDCST_ID_VECTOR/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/PBAX_CHIPID/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/PBAX_GROUPID/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/PM_PBAX_NODEID/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/NO_APSS_PROC_POWER_VCS_VIO_WATTS/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
    }

    # I2C arrays
    my @engine = ();
    my @port = ();
    my @slavePort = ();
    my @addr = ();
    my @speed = ();
    my @type = ();
    my @purpose = ();
    my @label = ();

    $targetObj->log($target, "Processing PROC");
    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        $targetObj->log($target,
            "Processing PROC child: $child Type: $child_type");

        if ($child_type eq "NA" || $child_type eq "FSI")
        {
            $child_type = $targetObj->getMrwType($child);
        }
        if ($child_type eq "XBUS")
        {
            processXbus($targetObj, $child);
        }
        elsif (($child_type eq "EQ") || ($child_type eq "PAUC"))
        {
            # Recursively iterate over the target and it's children
            setTargetChipletId($targetObj, $child, $child_type);
        }
        elsif ($child_type eq "OBUS")
        {
            processObus($targetObj, $child);
            #handle enumeration changes
            my $enum_val = $targetObj->getAttribute($child,"OPTICS_CONFIG_MODE");
            if ( $enum_val =~ /NVLINK/i)
            {
                $targetObj->setAttribute($child,"OPTICS_CONFIG_MODE","NV");
            }
        }
        elsif ($child_type eq "FSIM" || $child_type eq "FSICM")
        {
            processFsi($targetObj, $child, $target);
        }
        elsif ($child_type eq "PEC")
        {
            processPec($targetObj, $child, $target);
        }
        elsif ($child_type eq "MC")
        {
            processMc($targetObj, $child);
        }
        elsif ($child_type eq "OCC")
        {
            processOcc($targetObj, $child, $target);
        }

        # Ideally this should be $child_type eq "I2C", but we need a change
        # in serverwiz and the witherspoon.xml first
        elsif (index($child,"i2c-master") != -1)
        {
            my ($i2cEngine, $i2cPort, $i2cSlavePort, $i2cAddr,
                $i2cSpeed, $i2cType, $i2cPurpose, $i2cLabel) =
                    processI2C($targetObj, $child, $target);

            # Add this I2C device's information to the proc array
            push(@engine,@$i2cEngine);
            push(@port,@$i2cPort);
            push(@slavePort,@$i2cSlavePort);
            push(@addr,@$i2cAddr);
            push(@speed,@$i2cSpeed);
            push(@type,@$i2cType);
            push(@purpose,@$i2cPurpose);
            push(@label, @$i2cLabel);

        }
    }

    # Add final I2C arrays to processor
    my $size         = scalar @engine;
    my $engine_attr  = $engine[0];
    my $port_attr    = $port[0];
    my $slave_attr   = $slavePort[0];
    my $addr_attr    = $addr[0];
    my $speed_attr   = $speed[0];
    my $type_attr    = $type[0];
    my $purpose_attr = $purpose[0];
    my $label_attr   = $label[0];

    # Parse out array to print as a string
    foreach my $n (1..($size-1))
    {
        $engine_attr    .= ",".$engine[$n];
        $port_attr      .= ",".$port[$n];
        $slave_attr     .= ",".$slavePort[$n];
        $addr_attr      .= ",".$addr[$n];
        $speed_attr     .= ",".$speed[$n];
        $type_attr      .= ",".$type[$n];
        $purpose_attr   .= ",".$purpose[$n];
        $label_attr     .= ",".$label[$n];
    }

    # Set the arrays to the corresponding attribute on the proc
    $targetObj->setAttribute($target,"HDAT_I2C_ENGINE",$engine_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_MASTER_PORT",$port_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_SLAVE_PORT",$slave_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_ADDR",$addr_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_BUS_FREQ",$speed_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_DEVICE_TYPE",$type_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_DEVICE_PURPOSE",$purpose_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_DEVICE_LABEL", $label_attr);
    $targetObj->setAttribute($target,"HDAT_I2C_ELEMENTS",$size);

    ## update path for mvpd's and sbe's
    my $path  = $targetObj->getAttribute($target, "PHYS_PATH");
    my $model = $targetObj->getAttribute($target, "MODEL");
    $targetObj->setAttributeField($target,
        "EEPROM_VPD_PRIMARY_INFO","i2cMasterPath",$path);
    $targetObj->setAttributeField($target,
        "EEPROM_VPD_BACKUP_INFO","i2cMasterPath",$path);
    $targetObj->setAttributeField($target,
        "EEPROM_SBE_PRIMARY_INFO","i2cMasterPath",$path);
    $targetObj->setAttributeField($target,
        "EEPROM_SBE_BACKUP_INFO","i2cMasterPath",$path);

    ## need to initialize the master processor's FSI connections here
    my $proc_type = $targetObj->getAttribute($target, "PROC_MASTER_TYPE");

    if ($proc_type eq "ACTING_MASTER" )
    {
        if($targetObj->isBadAttribute($target, "FSI_MASTER_TYPE"))
        {
          $targetObj->setAttributeField($target, "FSI_OPTION_FLAGS", "reserved",
            "0");
          $targetObj->setAttribute($target, "FSI_MASTER_CHIP",    "physical:sys-0");
          $targetObj->setAttribute($target, "FSI_MASTER_PORT",    "0xFF");
          $targetObj->setAttribute($target, "ALTFSI_MASTER_CHIP", "physical:sys-0");
          $targetObj->setAttribute($target, "ALTFSI_MASTER_PORT", "0xFF");
          $targetObj->setAttribute($target, "FSI_MASTER_TYPE",    "NO_MASTER");
        }
        $targetObj->setAttribute($target, "FSI_SLAVE_CASCADE",  "0");
        $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useSbeScom",
            "1");
        $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useFsiScom",
            "0");
    }
    else
    {
        if($targetObj->isBadAttribute($target, "ALTFSI_MASTER_CHIP"))
        {
          $targetObj->setAttribute($target, "ALTFSI_MASTER_CHIP", "physical:sys-0");
        }
        $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useSbeScom",
            "0");
        $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useFsiScom",
            "1");
    }
    ## Update bus speeds
    processI2cSpeeds($targetObj,$target);

    ## these are hardcoded because code sets them properly
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "reserved",   "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useInbandScom",
        "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useXscom", "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useI2cScom","0");

    ## default effective fabric ids to match regular fabric ids
    ##  the value will be adjusted based on presence detection later
    $targetObj->setAttribute($target,
                             "PROC_EFF_FABRIC_GROUP_ID",
                             $targetObj->getAttribute($target,
                                                      "FABRIC_GROUP_ID"));
    $targetObj->setAttribute($target,
                             "PROC_EFF_FABRIC_CHIP_ID",
                             $targetObj->getAttribute($target,
                                                      "FABRIC_CHIP_ID"));


    #TODO RTC: 191762 -- Need a generic way to source FABRIC_GROUP_ID and
    #FABRIC_CHIP_ID from the MRW and select the right value in processMRW
    #based on the system configuration we are compiling for.
    my $system_config = $targetObj->{system_config};
    if ($system_config eq "w")
    {
        my $huid_str = $targetObj->getAttribute($target, "HUID");
        my $huid     = hex $huid_str;
        my $grp_id   = $targetObj->getAttribute($target,"FABRIC_GROUP_ID");
        my $chip_id  = $targetObj->getAttribute($target,"FABRIC_CHIP_ID");

        if    ($huid eq 0x50000)
        {
            $grp_id  = 0;
            $chip_id = 0;
        }
        elsif ($huid eq 0x50001)
        {
            $grp_id  = 1;
            $chip_id = 1;
        }
        elsif ($huid eq 0x50002)
        {
            $grp_id  = 0;
            $chip_id = 1;
        }
        elsif ($huid eq 0x50003)
        {
            $grp_id  = 1;
            $chip_id = 0;
        }
        else
        {
            #This is super ugly hack to make sure FABRIC_GROUP_ID and
            #FABRIC_CHIP_ID are unique in the entire system. But, it
            #doesn't matter what they are for other drawers as for
            #wrap config we only care about one drawer
            $grp_id += 1;
        }

        $targetObj->setAttribute($target,"FABRIC_GROUP_ID",$grp_id);
        $targetObj->setAttribute($target,"FABRIC_CHIP_ID",$chip_id);
        $targetObj->setAttribute($target,"PROC_EFF_FABRIC_GROUP_ID",$grp_id);
        $targetObj->setAttribute($target,"PROC_EFF_FABRIC_CHIP_ID",$chip_id);
    }

    setupMemoryMaps($targetObj,$target);

    $targetObj->setAttribute($target,
                     "PROC_MEM_TO_USE", ( $targetObj->getAttribute($target,
                     "FABRIC_GROUP_ID") << 3));

    processPowerRails ($targetObj, $target);

    # TODO, RTC 215469. Remove this, once this attribute has been defined in the MRW
    # Default the FREQ_OMI_MHZ to 25600 if no value found for this attribute
    use constant FREQ_OMI_MHZ_ATTRIB  => "FREQ_OMI_MHZ";
    use constant FREQ_OMI_MHZ_VALUE   => 25600;
    if ($targetObj->doesAttributeExistForTarget($target, FREQ_OMI_MHZ_ATTRIB))
    {
        # Attribute exists for this processor, check
        # if it does not have a default value
        my $value = $targetObj->getAttribute($target, FREQ_OMI_MHZ_ATTRIB);
        if ($value eq "")
        {
            # No default defined for attribute, give it a value
            $targetObj->setAttribute($target, FREQ_OMI_MHZ_ATTRIB,
                                              FREQ_OMI_MHZ_VALUE);
        }
    }

    # Set the MRU_ID to correct values
    {
        # Split the PROC on "-" boundaries.  That will separate the PROC numeric
        # position from the other fluff: "...power10-0" => "...power10", "0"
        my @procParts = split(/-/, $target); # array of ("...power10", "0")
        # Get the last value from array to retrieve the position (-1 in Perl means last)
        my $procPosition = $procParts[-1];

        # Set the MRU_ID to the MRU_PREFIX plus PROC position
        my $mru_prefix_id = $targetObj->{enumeration}->{MRU_PREFIX}->{PROC};
        my $mruiId = sprintf("%s%04x", $mru_prefix_id, $procPosition);

        # Set the target MRU_ID attribute
        $targetObj->setAttribute($target, "MRU_ID", $mruiId);
    }
}

sub processPowerRails
{
    my $targetObj = shift;
    my $target    = shift;

    #Example of how system xml is getting parsed into data structures here
    #and eventually into the attribute
    #
    #System XML has this:
    #<bus>
    #    <bus_id>vrm3-connector-22/vrm-type3-10/35219-3-8/IR35219_special.vout-0 => fcdimm-connector-69/fcdimm-14/membuf-0/MemIO</bus_id>
    #    <bus_type>POWER</bus_type>
    #    <cable>no</cable>
    #    <source_path>vrm3-connector-22/vrm-type3-10/35219-3-8/</source_path>
    #    <source_target>IR35219_special.vout-0</source_target>
    #    <dest_path>fcdimm-connector-69/fcdimm-14/membuf-0/</dest_path>
    #    <dest_target>MemIO</dest_target>
    #    <bus_attribute>
    #            <id>CLASS</id>
    #    <default>BUS</default>
    #    </bus_attribute>
    #</bus>
    #
    #each of the connection comes up like this (this is $rail variable)
    # 'BUS_NUM' => 0,
    # 'DEST_PARENT' => '/sys/node-4/calliope-1/fcdimm-connector-69/fcdimm-14/membuf-0',
    # 'DEST' => '/sys/node-4/calliope-1/fcdimm-connector-69/fcdimm-14/membuf-0/MemIO',
    # 'SOURCE_PARENT' => '/sys/node-4/calliope-1/vrm3-connector-22/vrm-type3-10/35219-3-8',
    # 'SOURCE' => '/sys/node-4/calliope-1/vrm3-connector-22/vrm-type3-10/35219-3-8/IR35219_special.vout-0'
    #
    #So, for 'SOURCE' target, we walk up the hierarchy till we get to
    #vrm3-connector-22 as that is the first target in the hierarchy that
    #is unique per instance of a given volate rail. We get vrm connector's
    #POSITION and set it as the ID for that rail.
    #
    #The 'DEST' target also has an attribute called "RAIL_NAME" that we can use
    #to figure out which rail we are working with. But, for rails that are
    #common between proc and centaur have "Cent" or "Mem" as a prefix.
    #
    my $rails=$targetObj->findDestConnections($target,"POWER","");
    if ($rails ne "")
    {
        foreach my $rail (@{$rails->{CONN}})
        {
            my $rail_dest = $rail->{DEST};
            my $rail_src  = $rail->{SOURCE};
            my $rail_name = $targetObj->getAttribute($rail_dest, "RAIL_NAME");
            #Need to get the connector's position and set the ID to that
            #As it is unique for every new connection in the MRW
            my $rail_connector =  $targetObj->getTargetParent( #VRM connector
                                 ($targetObj->getTargetParent #VRM type
                                 ($targetObj->getTargetParent($rail_src))));


            my $position = $targetObj->getAttribute($rail_connector,"POSITION");
            my $rail_attr_id =
                ($targetObj->getAttribute($target, "TYPE") eq "PROC") ?
                "NEST_" : "";

            #The rails that are common between proc and centaur have a "Cent"
            #prefix in the system xml. We don't care for "Cent" in our attribute
            #as it is scoped to the right target. But, for VIO, we decided to
            #use MemIO rather than CentIO. The attribute is named as VIO_ID.
            $rail_name =~ s/Cent//g;
            $rail_name =~ s/Mem/V/g;
            $rail_attr_id .= $rail_name . "_ID";

            $targetObj->setAttribute($target, $rail_attr_id, $position);
        }
    }
}

sub processI2cSpeeds
{
    my $targetObj = shift;
    my $target    = shift;

    my @bus_speeds;
    my $bus_speed_attr=$targetObj->getAttribute($target,"I2C_BUS_SPEED_ARRAY");
    my @bus_speeds2 = split(/,/,$bus_speed_attr);

    #need to create a 4X13 array
    my $i = 0;
    for my $engineIdx (0 .. 3)
    {
        for my $portIdx (0 .. 12)
        {
            $bus_speeds[$engineIdx][$portIdx] = $bus_speeds2[$i];
            $i++;
        }
    }

    my $i2cs=$targetObj->findConnections($target,"I2C","");

    if ($i2cs ne "") {
        foreach my $i2c (@{$i2cs->{CONN}}) {
            my $dest_type = $targetObj->getTargetType($i2c->{DEST_PARENT});
            my $parent_target =$targetObj->getTargetParent($i2c->{DEST_PARENT});

            if ($dest_type eq "chip-spd-device") {
                 setEepromAttributes($targetObj,
                       "EEPROM_VPD_PRIMARY_INFO",$parent_target,
                       $i2c);
            } elsif ($dest_type eq "chip-dimm-thermal-sensor") {
                 setDimmTempAttributes($targetObj, $parent_target, $i2c);
            }

            my $port=oct($targetObj->getAttribute($i2c->{SOURCE},"I2C_PORT"));
            my $engine=oct($targetObj->getAttribute(
                           $i2c->{SOURCE},"I2C_ENGINE"));
            my $bus_speed=$targetObj->getBusAttribute(
                  $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_SPEED");

# TODO, RTC 215164. Having an issue with this statement:
# ERROR: I2C bus speed not defined for /sys-0/node-0/nisqually-0/proc_socket-0/godel-0/power10-0/i2c-master-lightpath
# Once resolved, will uncomment or maybe drop if not needed
#            if ($bus_speed eq "" || $bus_speed==0) {
#                print "ERROR: I2C bus speed not defined for $i2c->{SOURCE}\n";
#                $targetObj->myExit(3);
#            }

            ## choose lowest bus speed
            if ($bus_speeds[$engine][$port] eq "" ||
                  $bus_speeds[$engine][$port]==0  ||
                  $bus_speed < $bus_speeds[$engine][$port]) {
                $bus_speeds[$engine][$port] = $bus_speed;
            }
        }
    }

    #need to flatten 4x13 array
    $bus_speed_attr = "";
    for my $engineIdx (0 .. 3)
    {
        for my $portIdx (0 .. 12)
        {
            $bus_speed_attr .= $bus_speeds[$engineIdx][$portIdx] . ",";
        }
    }
    #remove last ,
    $bus_speed_attr =~ s/,$//;

    $targetObj->setAttribute($target,"I2C_BUS_SPEED_ARRAY",$bus_speed_attr);
}

#--------------------------------------------------
# @brief Set up memory maps for certain attributes of the PROCS
#--------------------------------------------------
sub setupMemoryMaps
{
    my $targetObj = shift;
    my $target = shift;

    # Keep track of which topology IDs have been used
    my $topoId = getTopologyId($targetObj, $target);
    $targetObj->{TOPOLOGY}->{$topoId}++;

    # Get the topology index
    my $topologyIndex = getTopologyIndex($targetObj, $target);

    # P10 has a defined memory map for all configurations,
    # these are the base addresses for topology ID 0 (group0-chip0).
    my %bars=(  "FSP_BASE_ADDR"             => 0x0006030100000000,
                "PSI_BRIDGE_BASE_ADDR"      => 0x0006030203000000);

    #Note - Not including XSCOM_BASE_ADDRESS and LPC_BUS_ADDR in here
    # because Hostboot code itself writes those on every boot
    if (!$targetObj->isBadAttribute($target,"XSCOM_BASE_ADDRESS") )
    {
        $targetObj->deleteAttribute($target,"XSCOM_BASE_ADDRESS");
    }
    if (!$targetObj->isBadAttribute($target,"LPC_BUS_ADDR") )
    {
        $targetObj->deleteAttribute($target,"LPC_BUS_ADDR");
    }

    # The topology index resides in bits 15:19 of the P10 memory map.
    # This offset, when multiplied to the index, will put the index in the
    # correct bits of the memory map.
    my $topologyIndexOffset = 0x0000100000000000;

    # Add the topology index to the bar base memory
    foreach my $bar (keys %bars)
    {
        my $base = Math::BigInt->new($bars{$bar});

        # Add the topology index (multiplied out to the correct position)
        # to the base.
        my $value=sprintf("0x%016s",substr(($base +
                          ($topologyIndexOffset*$topologyIndex))->as_hex(),2));
        # Set the bar of the target to calculated value
        $targetObj->setAttribute($target,$bar,$value);
    }
}  # end setupMemoryMaps

#--------------------------------------------------
# @brief Retrieve the fabric topology mode
#
# @details The fabric topology mode, attribute PROC_FABRIC_TOPOLOGY_MODE,
#          is an attribute of the top level target (sys-0), but retrieving
#          the value from the attribute returns a string (MODE0 or MODE1).
#          This string is used to get the actual value, tied to that mode,
#          within the enumeration types.
#
# @param[in] $targetObj - The global target object, needed to get topology mode
#
# @return the numerical value of the topology mode in base 10
#--------------------------------------------------
sub getTopologyMode
{
    my $targetObj = shift;

    use constant TOPOLOGY_MODE_ATTRIBUTE => "PROC_FABRIC_TOPOLOGY_MODE";

    # Get topology mode from top level target
    # Need to prepend "/" to the returned top level target because targets
    # are mapped slightly different in the TARGETS hash vs the xml hash.
    my $topologoyMode = $targetObj->getAttribute("/".$targetObj->{TOP_LEVEL},
                                                 TOPOLOGY_MODE_ATTRIBUTE);

    # Return the value of the mode as defined in
    # enumeration type PROC_FABRIC_TOPOLOGY_MODE
    # Convert the value from hex to base 10
    return hex($targetObj->{xml}->{enumerationTypes}->{enumerationType}
                      ->{PROC_FABRIC_TOPOLOGY_MODE}
                      ->{enumerator}->{$topologoyMode}->{value});
}

#--------------------------------------------------
# @brief Convert the topology ID to a topology index.
#
# @details  The topology ID is a 4 bit value that will be converted to a 5 bit
#           topology index. The topology index is an index into the topology
#           table.
#           The conversion method depends on the topology mode.
#                Mode      ID      index
#               MODE 0 => GGGC --> GGG0C
#               MODE 1 => GGCC --> GG0CC
#
# @param[in] $topologyId - The topology ID to convert to an index
# @param[in] $topologyMode - The topology mode that determines the conversion
#                            method. Needs to be a base 10 numeral value.
#
# @return a toplogy index, that is a base 10 numeral value.
#--------------------------------------------------
sub convertTopologyIdToIndex
{
    my $topologyId = shift;
    my $topologyMode = shift;

    use constant TOPOLOGY_MODE_1 => 1;

    # Assume topology mode 0 (GGGC -> GGG0C)
    my $groupMask = 0xE; # Use 0xE, 1110b, to extract 'GGG' from 'GGGC'
    my $chipMask = 0x1;  # Use 0x1, 0001b, to extract 'C' from 'GGGC'

    # If topology mode 1 (GGCC -> GG0CC)
    if (TOPOLOGY_MODE_1 == $topologyMode)
    {
        $groupMask = 0xC; # Use 0xC, 1100b, to extract 'GG' from 'GGCC'
        $chipMask = 0x3;  # Use 0x3, 0011b, to extract 'CC' from 'GGCC'
    }

    # Set topology index to topology ID before doing conversion
    my $topologyIndex = $topologyId;

    ## Turn the 4 bit topology ID into a 5 bit index
    ## convert GGGC to GGG0C
    ##      OR GGCC to GG0CC
    # If group mask equal to 0xE (mode 0) then extract 'GGG' from 'GGGC':
    #  1) GGGC & 0xE (1110b) returns GGG0 then shift left (<< 1) to get GGG00
    #  2) extract C from GGGC: GGGC & 0x1 (0001b) returns C
    # If group mask equal to 0xC (mode 1) then extract 'GG' from 'GGCC':
    #  1) GGCC & 0xC (1100b) returns GG00 then shift left (<< 1) to get GG000
    #  2) extract CC from GGCC: GGCC & 0x3 (0011b) returns CC
    # Bitwise 'OR' 1 and 2 together to produce a 5 bit index value: GGG0C OR GG0CC
    #    Index     =                  1                  'OR'               2
    $topologyIndex = (($topologyIndex & $groupMask) << 1) | ($topologyIndex & $chipMask);

    return ($topologyIndex);
}

#--------------------------------------------------
# @brief Get the topology ID from processor
#
#
# @param[in] $targetObj - The global target object, needed to get topology mode
# @param[in] $processorTarget - The processor target, has the attribute topology ID
#
# @return topology ID, that is a base 10 numeral value.
#--------------------------------------------------
sub getTopologyId
{
    my $targetObj = shift;
    my $processorTarget = shift;

    use constant TOPOLOGY_ID_ATTRIBUTE => "PROC_FABRIC_TOPOLOGY_ID";

    # Get the topology ID from the processor.
    # Convert hex value to base 10 numerical value
    return (hex($targetObj->getAttribute($processorTarget,
                                         TOPOLOGY_ID_ATTRIBUTE) ));
}

#--------------------------------------------------
# @brief Get the topology index, an index into the topology table.
#
# @details The topology index needs to be calculated using the topology mode
#          and the topology ID.  @see convertTopologyIdToIndex for
#          more details
#
# @param[in] $targetObj - The global target object, needed to get topology mode
# @param[in] $processorTarget - The processor target has the attribute topology ID
#
# @return a topology index, that is base 10 numeral value.
#--------------------------------------------------
sub getTopologyIndex
{
    my $targetObj = shift;
    my $processorTarget = shift;

    # Get the topology mode: MODE 0 (0) or MODE 1 (1)
    my $topologyMode = getTopologyMode($targetObj);

    # Get the topology ID from the processor.
    my $topologyId = getTopologyId($targetObj, $processorTarget);

    # Convert the topology ID to a topology index. The conversion method is
    # based on the topology mode.
    return (convertTopologyIdToIndex($topologyId, $topologyMode));
}

#--------------------------------------------------
# @brief Set the Target's attribute CHIPLET_ID
#
# @details The CHIPLET_ID value is calculated via the addition of the
#          target's attribute CHIP_UNIT with the PERVASIVE_PARENT_OFFSET value
#          for target type.
#
# @param [in] $targetObj - The global target object.
# @param [in] $target - target to set CHIPLET_ID for
# @param [in] $targetType - The target type of the target
# @param [in] $chipUnit - The CHIP_UNIT value used to calculate the CHIPLET_ID
#
# @note The $chipUnit may be supplied for the child to use in calculating
#       the CHIPLET_ID, if not supplied, then will use child's CHIP_UNIT value.
#
# @return true if attribute found, else false
#--------------------------------------------------
sub setTargetChipletId
{
    my $targetObj = shift;
    my $target    = shift;
    my $targetType = shift;
    my $chipUnit = shift;

    # If no chip unit given, then use the target's chip unit
    if ($chipUnit eq undef)
    {
        if ($targetObj->doesAttributeExistForTarget($target, "CHIP_UNIT"))
        {
            $chipUnit = $targetObj->getAttribute($target, "CHIP_UNIT");
        }
        else
        {
            # Can't get the CHIP_UNIT value, then no point in continuing
            # This is a an acceptable response, not all target instance have
            # a CHIP_UNIT attribute.
            return;
        }
    }

    # If the target has pervasive parent, then process it
    if (exists $Targets::PERVASIVE_PARENT_OFFSET{$targetType})
    {
        # Get this target's PERVASIVE_PARENT value
        my $value = $Targets::PERVASIVE_PARENT_OFFSET{$targetType};

        if ($targetType eq "PAU")
        {
            # We devide by 2 here because the PERVASIVE_PARENT repeats in pairs
            $value += ($chipUnit / 2);
        }
        else
        {
            # Add the CHIP_UNIT value to the pervasive parent offset
            $value += $chipUnit;
        }

        # Make it look pwetty
        $value = sprintf("0x%0.2X", $value);

        # Set the chiplet ID with calculated value
        $targetObj->setAttribute( $target, "CHIPLET_ID", $value);
    }

    # Set the Chiplet ID for the children, if children exists
    if ($targetObj->getTargetChildren($target) ne "")
    {
        # Iterate over the children setting their Chiplet IDs
        foreach my $child (@{ $targetObj->getTargetChildren($target) })
        {
            # Get the target type of the child for logging
            my $childType = $targetObj->getType($child);

            $targetObj->log($target,
                "Processing $targetType child: $child Type: $childType");

            if ($childType eq "IOHS")
            {
                # Don't send THIS chip unit, let IOHS use it's own chip unit
                setTargetChipletId($targetObj, $child, $childType);
            }
            elsif ($childType eq "PAU")
            {
                # TODO  RTC 215164 This is a bad place to put, but fits.
                # Will need to refactor
                setPauOrdinalId($targetObj, $child);
                setTargetChipletId($targetObj, $child, $childType, $chipUnit);
            }
            else
            {
                setTargetChipletId($targetObj, $child, $childType, $chipUnit);
            }
        }
    }
}

#--------------------------------------------------
# @brief This will set the PAU's ordinal ID.
#
# @details For a given PROC, PAU1 and PAU2 (0-based) are not used.
#          Normal calculation is done with the position of the PAU.  With PAU1
#          and PAU2 not being used, the position is not sequential but the
#          ordinal ID's for the used PAUs must be sequential.  There
#          are gaps in the position which must be realigned to get a contiguous
#          integer sequence.
#
# @details Need to take a sequence such as:
#          0, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15
#          transform to:
#          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
#          The sequence deviates after every 1st PAU in a given PROC.
#          To find those numbers, look for every number that is a product
#          of the maximum number of PAUs per PROC and the PROCs position.
#          Then realign those numbers.
#
# @param [in] $targetObj - The global target object.
# @param [in] $pauTarget - a target of type PAU
#--------------------------------------------------
sub setPauOrdinalId
{
    my $targetObj = shift;
    my $pauTarget = shift;

    # Verify that target type is of type PAU
    my $targetType = $targetObj->getType($pauTarget);
    if ($targetType ne "PAU")
    {
        die "setPauOrdinalId: ERROR: Target type must be \"PAU\" not " .
            "\"$targetType\". Error";
    }

    # Need to get the PROC for this PAU target
    my $procParent = $targetObj->findParentByType($pauTarget, "PROC");

    # Get the position of the PROC which is used to calculate the ORDINAL_ID
    my $procPosition = $targetObj->getAttribute($procParent, "POSITION");

    # Get the current ORDINAL_ID of the PAU, which will have numerical gaps.
    my $targetOrdinalId = $targetObj->getAttribute($pauTarget, "ORDINAL_ID");

    # Gaps begin on the 2nd ordinal id (1 for 0-based) for every proc.
    my $maxInst = $targetObj->getMaxInstPerProc($targetType);
    if ($targetOrdinalId >=
        (($procPosition * $maxInst) + 1) )
    {
        $targetOrdinalId = $targetOrdinalId - (($procPosition + 1) * 2);
    }
    elsif ($targetOrdinalId > 0)  # Do not process 0
    {
        $targetOrdinalId = $targetOrdinalId - ($procPosition * 2);
    }

    $targetObj->setAttribute($pauTarget, "ORDINAL_ID", $targetOrdinalId);
}

#--------------------------------------------------
## MC
##
##
sub processMc
{
    # NOTE: OMI_INBAND_BAR_BASE_ADDR_OFFSET will be set for the MC
    # targets via a specific child OMI Target. View the
    # processOmi function for further details.
    my $targetObj    = shift;
    my $target       = shift;

    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        $targetObj->log($target,
            "Processing MC child: $child Type: $child_type");

        if ($child_type eq "MI")
        {
            processMi($targetObj, $child);
        }
        elsif ($child_type eq "OMIC")
        {
            processOmic($targetObj, $child);
        }
    }

    {
        use integer;
        my $chip_unit = $targetObj->getAttribute($target, "CHIP_UNIT");
        my $value = sprintf("0x%x",
                            Targets::PERVASIVE_PARENT_MC_OFFSET
                            + $chip_unit);

        $targetObj->setAttribute( $target, "CHIPLET_ID", $value);
    }
}

#--------------------------------------------------
## MCC
##
##
sub processMcc
{
    my $targetObj   = shift;
    my $target      = shift;

    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        $targetObj->log($target,
            "Processing MCC child: $child Type: $child_type");

        if ($child_type eq "OMI")
        {
            processOmi($targetObj, $child);
        }
    }

    {
        use integer;
        # There are a total of four MCC units on an MC unit. So, to
        # determine which MC an MCC belongs to, the CHIP_UNIT of the MCC can
        # be divided by the number of units per MC to arrive at the correct
        # offset to add to the pervasive MCC parent offset.
        my $numberOfMccPerMc = 4;
        my $chip_unit = $targetObj->getAttribute($target, "CHIP_UNIT");

        my $value = sprintf("0x%x",
                            Targets::PERVASIVE_PARENT_MI_OFFSET
                            + ($chip_unit / $numberOfMccPerMc));

        $targetObj->setAttribute( $target, "CHIPLET_ID", $value);
    }
}

#--------------------------------------------------
## OMI
##
##
sub processOmi
{
    my $mrwObj  = shift;
    my $omitarg = shift;

# TODO, RTC 208783. This will need to be updated.  This will be addressed
# in story 208783, just making a note.
    # Map the OMI instance to its corresponding OMIC parent
    my %omi_map = (4  => "omic-0",
                   5  => "omic-0",
                   6  => "omic-0",
                   7  => "omic-1",
                   2  => "omic-1",
                   3  => "omic-1",
                   0  => "omic-2",
                   1  => "omic-2",
                   12 => "omic-0",
                   13 => "omic-0",
                   14 => "omic-0",
                   15 => "omic-1",
                   10 => "omic-1",
                   11 => "omic-1",
                   8  => "omic-2",
                   9  => "omic-2");

    use integer;
    # There are a total of eight OMI units on an MC unit. So, to
    # determine which MC an OMI belongs to, the CHIP_UNIT of the OMI can
    # be divided by the number of units per MC to arrive at the correct
    # offset to add to the pervasive OMI parent offset.
    my $numberOfOmiPerMc = 8;
    my $chip_unit = $mrwObj->getAttribute($omitarg, "CHIP_UNIT");
    my $fapi_pos = $mrwObj->getAttribute($omitarg, "FAPI_POS");
    my $value = sprintf("0x%x",
                        Targets::PERVASIVE_PARENT_MI_OFFSET
                        + ($chip_unit / $numberOfOmiPerMc));

    $mrwObj->setAttribute($omitarg, "CHIPLET_ID", $value);

    # Start with our affinity path "sys-a/node-b/proc-c/mc-d/mi-e/mcc-f/omi-g"
    #  then snip off everything before the mi
    my $phys_path = $mrwObj->getAttribute($omitarg, "PHYS_PATH");
    my $up_to_mi = index($phys_path,"mi-");
    my $omic_parent = substr($phys_path,0,$up_to_mi);
    $omic_parent = $omic_parent.$omi_map{$chip_unit};
    $mrwObj->setAttribute($omitarg, "OMIC_PARENT", $omic_parent);

    my $omi = Math::BigInt->new($mrwObj->getAttribute($omitarg,"FAPI_POS"));
    # Base omi bar offset
    # We use this base address in simics_AXONE.system.xml and want our
    # addresses to match the ones in that xml
    my $base = 0x30400000000;
    my $gigabyte = 0x40000000;
    my $value = 0;

    # This algorithm is explained in src/usr/mmio/mmio.C
    if ($omi % 2 eq 0)
    {
        $value = $base + $omi * 4 * $gigabyte;
    }
    else
    {
        $value = $base + (($omi - 1) * 4 + 2) * $gigabyte;
    }

    $value = sprintf("0x%016s", substr(($value)->as_hex(),2));
    $mrwObj->setAttribute($omitarg, "OMI_INBAND_BAR_BASE_ADDR_OFFSET",
        $value);

    # Set the parent MC BAR value to value of first OMI unit
    if ($omi % 8 eq 0)
    {
        my $parent_mcc = $mrwObj->getTargetParent($omitarg);
        my $parent_mi = $mrwObj->getTargetParent($parent_mcc);
        my $parent_mc = $mrwObj->getTargetParent($parent_mi);
        $mrwObj->setAttribute($parent_mc, "OMI_INBAND_BAR_BASE_ADDR_OFFSET",
            $value);
    }
}

#--------------------------------------------------
## OMIC
##
##
sub processOmic
{
    my $targetObj   = shift;
    my $target      = shift;

    use integer;
    # There are a total of three OMIC units on an MC unit. So, to
    # determine which MC an OMIC belongs to, the CHIP_UNIT of the OMIC can
    # be divided by the number of units per MC to arrive at the correct
    # offset to add to the pervasive OMIC parent offset.
    my $numberOfOmicPerMc = 3;
    my $chip_unit = $targetObj->getAttribute($target, "CHIP_UNIT");

    my $value = sprintf("0x%x",
                        Targets::PERVASIVE_PARENT_MI_OFFSET
                        + ($chip_unit / $numberOfOmicPerMc));

    $targetObj->setAttribute( $target, "CHIPLET_ID", $value);
}

#--------------------------------------------------
# @brief OCMB_CHIP
#
#--------------------------------------------------
sub processOcmbChip
{
    my $targetObj    = shift;
    my $target       = shift;

    $targetObj->setEepromAttributesForDdimms($target);
}

#--------------------------------------------------
## MI
##
##
sub processMi
{
    my $targetObj    = shift;
    my $target       = shift;

    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        $targetObj->log($target,
            "Processing MI child: $child Type: $child_type");

        if ($child_type eq "MCC")
        {
            processMcc($targetObj, $child);
        }
    }

    {
        use integer;
        # There are a total of two MI units on an MC unit. So, to
        # determine which MC an MI belongs to, the CHIP_UNIT of the MI can
        # be divided by the number of units per MC to arrive at the correct
        # offset to add to the pervasive MI parent offset.
        my $numberOfMiPerMc = 2;
        my $chip_unit = $targetObj->getAttribute($target, "CHIP_UNIT");

        my $value = sprintf("0x%x",
                            Targets::PERVASIVE_PARENT_MI_OFFSET
                            + ($chip_unit / $numberOfMiPerMc));

        $targetObj->setAttribute( $target, "CHIPLET_ID", $value);
    }

}


#--------------------------------------------------
## OBUS
##
## Finds OBUS connections and copy the slot position to obus brick target
sub processObus
{
    my $targetObj = shift;
    my $target    = shift;

    my $obus = $targetObj->findConnections($target,"OBUS", "");

    if ($obus eq "")
    {
        $obus = $targetObj->findConnections($target,"ABUS", "");
        if ($obus ne "")
        {
           $targetObj->setAttribute($target, "BUS_TYPE", "ABUS");
           if ($targetObj->isBadAttribute($target, "PEER_PATH"))
           {
              $targetObj->setAttribute($target, "PEER_PATH","physical:na");
           }
           foreach my $obusconn (@{$obus->{CONN}})
           {
              processAbus($targetObj, $target,$obusconn);
           }
        }
        else
        {
          #No connections mean, we need to set the OBUS_SLOT_INDEX to -1
          #to mark that they are not connected
          $targetObj->log($target,"no bus connection found");

          foreach my $obrick (@{ $targetObj->getTargetChildren($target) })
          {
             $targetObj->setAttribute($obrick, "OBUS_SLOT_INDEX", -1);
          }
        }
     }
     else
     {
        if ($targetObj->isBadAttribute($target, "PEER_PATH"))
        {
           $targetObj->setAttribute($target, "PEER_PATH","physical:na");
        }
        foreach my $obusconn (@{$obus->{CONN}})
        {
             #Loop through all the bricks and figure out if it connected to an
             #obusslot. If it is connected, then store the slot information (position)
             #in the obus_brick target as OBUS_SLOT_INDEX. If it is not connected,
             #set the value to -1 to mark that they are not connected
             my $match = 0;
             foreach my $obrick (@{ $targetObj->getTargetChildren($target) })
             {
               foreach my $obrick_conn (@{$obus->{CONN}})
               {
                 if ($targetObj->isBusAttributeDefined($obrick,
                                     $obrick_conn->{BUS_NUM}, "OBUS_CONFIG"))
                 {
                     my $cfg = $targetObj->getBusAttribute($obrick,
                                     $obrick_conn->{BUS_NUM}, "OBUS_CONFIG");
                     my $intarget = $obrick_conn->{SOURCE_PARENT};
                     while($targetObj->getAttribute($intarget,"CLASS") ne "CONNECTOR")
                     {
                       $intarget = $targetObj->getTargetParent($intarget);
                     }
                 }

                 $match = ($obrick_conn->{SOURCE} eq $obrick);
                 if ($match eq 1)
                 {
                     my $obus_slot    = $targetObj->getTargetParent(
                         $obrick_conn->{DEST_PARENT});
                     my $obus_slot_pos = $targetObj->getAttribute(
                            $obus_slot, "POSITION");
                        $targetObj->setAttribute($obrick, "OBUS_SLOT_INDEX",
                            $obus_slot_pos);
                        last;
                 }
               }

               #This brick is not connected to anything, set the value of OBUS_SLOT_INDEX to -1
               #to mark that they are not connected
               if ($match eq 0)
               {
                  $targetObj->setAttribute($obrick, "OBUS_SLOT_INDEX", -1);
               }
            }
     }
   }

    my $chip_unit = $targetObj->getAttribute($target, "CHIP_UNIT");
    my $value = sprintf("0x%x", Targets::PERVASIVE_PARENT_OBUS_OFFSET + $chip_unit);
    $targetObj->setAttribute($target, "CHIPLET_ID", $value);

    # Set CHIPLET_ID for OBUS_BRICKs
    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $type = $targetObj->getType($child);
        if ($type eq "OBUS_BRICK")
        {
            # OBUS_BRICK takes on CHIPLET_ID of OBUS parent
            $targetObj->setAttribute($child, "CHIPLET_ID", $value);
        }
    }
}

#--------------------------------------------------
## XBUS
##
## Finds XBUS connections and creates PEER TARGET attributes

sub processXbus
{
    my $targetObj = shift;
    my $target    = shift;

    my $found_xbus = 0;
    my $default_config = "d";
    my $wrap_config    = "w";
    my $xbus_child_conn = $targetObj->getFirstConnectionDestination($target);
    if ($xbus_child_conn ne "")
    {
        # The CONFIG_APPLY bus attribute carries a comma seperated values for each
        # X-bus connection. It can currently take the following values.
        # "w" - This connection is applicable only in wrap config
        # "d" - This connection is applicable in default config (non-wrap mode).
        my $config = $default_config;
        if ($targetObj->isBusAttributeDefined($target,0,"CONFIG_APPLY"))
        {
            $config = $targetObj->getBusAttribute($target,0,"CONFIG_APPLY");
        }

        # Validate a value was provided, if not use the default value
        if ($config eq "")
        {
            print STDOUT "No value found for CONFIG_APPLY, default to using default value ($default_config)\n";
            $config = $default_config;
        }

        #If CONFIG_APPLY doesn't match the system configuration we are
        #running for, then mark the peers null.
        #For example, in wrap config, CONFIG_APPLY is expected to have "w"
        #If "w" is not there, then we skip the connection and mark peers
        #as NULL
        my $system_config = $targetObj->{system_config};
        if (($system_config eq $wrap_config && $config =~ /$wrap_config/) ||
           ($system_config ne $wrap_config && $config =~ /$default_config/))
        {
            ## set attributes for both directions
            $targetObj->setAttribute($xbus_child_conn, "PEER_TARGET",
                $targetObj->getAttribute($target, "PHYS_PATH"));
            $targetObj->setAttribute($target, "PEER_TARGET",
                $targetObj->getAttribute($xbus_child_conn, "PHYS_PATH"));

            $targetObj->setAttribute($xbus_child_conn, "PEER_PATH",
                $targetObj->getAttribute($target, "PHYS_PATH"));
            $targetObj->setAttribute($target, "PEER_PATH",
                $targetObj->getAttribute($xbus_child_conn, "PHYS_PATH"));

            $targetObj->setAttribute($xbus_child_conn, "PEER_HUID",
                $targetObj->getAttribute($target, "HUID"));
            $targetObj->setAttribute($target, "PEER_HUID",
                $targetObj->getAttribute($xbus_child_conn, "HUID"));

            $found_xbus = 1;
        }
        else
        {
            $targetObj->setAttribute($xbus_child_conn, "PEER_TARGET", "NULL");
            $targetObj->setAttribute($target, "PEER_TARGET","NULL");
            $targetObj->setAttribute($xbus_child_conn, "PEER_PATH", "physical:na");
            $targetObj->setAttribute($target, "PEER_PATH", "physical:na");
        }
    }

}

#--------------------------------------------------
## ABUS
##
## Finds ABUS connections and creates PEER TARGET attributes

sub processAbus
{
    my $targetObj = shift;
    my $target    = shift;
    my $aBus      = shift;

    my $abussource = $aBus->{SOURCE};
    my $abusdest   = $aBus->{DEST};
    my $abus_dest_parent = $aBus->{DEST_PARENT};
    my $bustype = $targetObj->getBusType($abussource);
    my $updatePeerTargets = 0;


    my $config = $targetObj->getBusAttribute($aBus->{SOURCE},$aBus->{BUS_NUM},"CONFIG_APPLY");
    my $twonode = "2";
    my $threenode = "3";
    my $fournode = "4";
    my @configs = split(',',$config);

    # The CONFIG_APPLY bus attribute carries a comma seperated values for each
    # A-bus connection. For eg.,
    # "2,3,4" - This connection is applicable in 2,3 and 4 node config
    # "w" - This connection is applicable only in wrap config
    # "2" - This connection is applicable only in 2 node config
    # "4" - This connection is applicable only in 4 node config
    # The below logic looks for these tokens and decides whether a certain
    # A-bus connection has to be conisdered or not
    # If user has passed 2N as argument, then we consider only those
    # A-bus connections where token "2" is present
    my $system_config = $targetObj->{system_config};
    if($system_config eq "2N" && $config =~ /$twonode/)
    {
        #Looking for Abus connections pertaining to 2 node system only
        $updatePeerTargets = 1;
    }
    elsif ($system_config eq "")
    {
      #Looking for Abus connections pertaining to 2,3,4 node systems
      #This will skip any connections specific to ONLY 2 node
      if($config =~ /$threenode/ || $config =~ /$fournode/)
      {
          $updatePeerTargets = 1;
      }

    }
    elsif ($config =~ /$system_config/)
    {
        #If system configuration we are building for matches the config
        #this ABUS connection is for, then update. Ex: wrap config
        $updatePeerTargets = 1;
    }
    else
    {
        $updatePeerTargets = 0;
    }


    if($updatePeerTargets eq 1)
    {
        ## set attributes for both directions
        my $phys1 = $targetObj->getAttribute($target, "PHYS_PATH");
        my $phys2 = $targetObj->getAttribute($abus_dest_parent, "PHYS_PATH");

        $targetObj->setAttribute($abus_dest_parent, "PEER_TARGET",$phys1);
        $targetObj->setAttribute($target, "PEER_TARGET",$phys2);
        $targetObj->setAttribute($abus_dest_parent, "PEER_PATH", $phys1);
        $targetObj->setAttribute($target, "PEER_PATH", $phys2);

        $targetObj->setAttribute($abus_dest_parent, "PEER_HUID",
           $targetObj->getAttribute($target, "HUID"));
        $targetObj->setAttribute($target, "PEER_HUID",
           $targetObj->getAttribute($abus_dest_parent, "HUID"));

        $targetObj->setAttribute($abussource, "PEER_TARGET",
                 $targetObj->getAttribute($abusdest, "PHYS_PATH"));
        $targetObj->setAttribute($abusdest, "PEER_TARGET",
                 $targetObj->getAttribute($abussource, "PHYS_PATH"));

        $targetObj->setAttribute($abussource, "PEER_PATH",
                 $targetObj->getAttribute($abusdest, "PHYS_PATH"));
        $targetObj->setAttribute($abusdest, "PEER_PATH",
                 $targetObj->getAttribute($abussource, "PHYS_PATH"));

        $targetObj->setAttribute($abussource, "PEER_HUID",
           $targetObj->getAttribute($abusdest, "HUID"));
        $targetObj->setAttribute($abusdest, "PEER_HUID",
           $targetObj->getAttribute($abussource, "HUID"));

         # copy Abus attributes from the connection to the chiplet
        my $abus = $targetObj->getFirstConnectionBus($target);

        $targetObj->setAttribute($target, "EI_BUS_TX_MSBSWAP",
              $abus->{bus_attribute}->{SOURCE_TX_MSBSWAP}->{default});
        $targetObj->setAttribute($abus_dest_parent, "EI_BUS_TX_MSBSWAP",
              $abus->{bus_attribute}->{DEST_TX_MSBSWAP}->{default});

        # copy attributes for wrap config
        my $link_set = "SET_NONE";
        if ($targetObj->isBusAttributeDefined($aBus->{SOURCE},$aBus->{BUS_NUM},"MFG_WRAP_TEST_ABUS_LINKS_SET"))
        {
            $link_set = $targetObj->getBusAttribute($aBus->{SOURCE},$aBus->{BUS_NUM},"MFG_WRAP_TEST_ABUS_LINKS_SET");
        }
        $targetObj->setAttribute($target, "MFG_WRAP_TEST_ABUS_LINKS_SET", $link_set);
        $targetObj->setAttribute($abus_dest_parent, "MFG_WRAP_TEST_ABUS_LINKS_SET", $link_set);
    }
}

#--------------------------------------------------
## FSI
##
## Finds FSI connections and creates FSI MASTER attributes at endpoint target

sub processFsi
{
    my $targetObj    = shift;
    my $target       = shift;
    my $parentTarget = shift;
    my $type         = $targetObj->getBusType($target);

    ## fsi can only have 1 connection
    my $fsi_child_conn = $targetObj->getFirstConnectionDestination($target);

    ## found something on other end
    if ($fsi_child_conn ne "")
    {
        my $fsi_link = $targetObj->getAttribute($target, "FSI_LINK");
        my $fsi_port = $targetObj->getAttribute($target, "FSI_PORT");
        my $cmfsi = $targetObj->getAttribute($target, "CMFSI");
        my $proc_path = $targetObj->getAttribute($parentTarget,"PHYS_PATH");
        my $fsi_child_target = $targetObj->getTargetParent($fsi_child_conn);
        my $flip_port         = 0;
        my $altfsiswitch      = 0;

        # If this is a proc that can be a master, then we need to set flip_port
        # attribute in FSI_OPTIONS. $flip_port tells us which FSI port to write to.
        # The default setting ( with flip_port not set) is to send instructions to port A.
        # In High End systems there are 2 master capable procs per node.
        # For the alt-master processor we need to set flip_port so that when it is master,
        # it knows to send instructions to the B port. During processMrw
        # we cannot determine which proc is master and which is the alt-master.
        # We will set flipPort on both and the later clear flipPort when we determine
        # which is actually master during hwsv init.

        #    FSP A is primary FSB B is backup
        #   |--------|        |--------|
        #   | FSP A  |        | FSP B  |
        #   |  (M)   |        |    (M) |
        #   |--------|        |--------|
        #       |
        #       V
        #   |--------|        |--------|
        #   |  (A)(B)|------->|(B) (A) |
        #   | Master |        |Alt Mast|
        #   |     (M)|        |(M)     |
        #   |--------|\       |--------|
        #          |   \
        #         /     \
        #        /       \
        #   |--------|    \   |---------|
        #   | (A) (B)|     \->|(A)  (B) |
        #   | Slave  |        |  Slave  |
        #   |        |        |         |
        #   |--------|        |---------|

        #   FSP B is primary FSB A is backup
        #
        #   |--------|        |--------|
        #   | FSP A  |        | FSP B  |
        #   |  (M)   |        |    (M) |
        #   |--------|        |--------|
        #                           |
        #                           V
        #   |--------|        |--------|
        #   |  (A)(B)|<-------|(M) (A) |
        #   | Master |       /|Alt Mast|
        #   |     (M)|      /||(B)     |
        #   |--------|     / ||--------|
        #                 /   \
        #                /     \__
        #               /         \
        #   |--------| /      |---------|
        #   |(A)  (B)|        |(A) (B)  |
        #   | Slave  |        |  Slave  |
        #   |        |        |         |
        #   |--------|        |---------|
        my $source_type = $targetObj->getType($parentTarget);
        if ( $source_type eq "PROC" )
        {
            my $proc_type = $targetObj->getAttribute($parentTarget, "PROC_MASTER_TYPE");
            if ($proc_type eq "ACTING_MASTER" || $proc_type eq "MASTER_CANDIDATE" )
            {
                my $fcid = $targetObj->getAttribute($parentTarget,"FABRIC_CHIP_ID");
                if($fcid eq 1)
                {
                  $altfsiswitch = 1;
                }
            }
        }
        my $dest_type = $targetObj->getType($fsi_child_target);
        if ($dest_type eq "PROC" )
        {
            my $proc_type = $targetObj->getAttribute($fsi_child_target, "PROC_MASTER_TYPE");
            if ($proc_type eq "ACTING_MASTER" || $proc_type eq "MASTER_CANDIDATE" )
            {
                my $fcid = $targetObj->getAttribute($fsi_child_target,"FABRIC_CHIP_ID");
                if($fcid eq 1)
                {
                  $flip_port = 1;
                }
            }
        }
        $targetObj->setFsiAttributes($fsi_child_target,
                    $type,$cmfsi,$proc_path,$fsi_link,$flip_port,$altfsiswitch);
    }
}

#--------------------------------------------------
## PEC
##
## Creates attributes from abstract PCI attributes on bus

sub processPec
{
    my $targetObj    = shift;
    my $target       = shift; # PEC
    my $parentTarget = shift; # PROC


    ## process pcie config target
    ## this is a special target whose children are the different ways
    ## to configure iop/phb's

    ## Get config children
    my @lane_mask;
    $lane_mask[0][0] = "0x0000";
    $lane_mask[1][0] = "0x0000";
    $lane_mask[2][0] = "0x0000";
    $lane_mask[3][0] = "0x0000";

    my $pec_iop_swap = 0;
    my $bitshift_const = 0;
    my $pec_num = $targetObj->getAttribute
                      ($target, "CHIP_UNIT");

    my $chipletIdValue = sprintf("0x%x",
                        Targets::PERVASIVE_PARENT_PEC_OFFSET
                        + $pec_num);

    $targetObj->setAttribute( $target, "CHIPLET_ID", $chipletIdValue);

    foreach my $pec_config_child (@{ $targetObj->getTargetChildren($target) })
    {
        my $phb_counter = 0;
        foreach my $phb_child (@{ $targetObj->getTargetChildren
                                                  ($pec_config_child) })
        {
            foreach my $phb_config_child (@{ $targetObj->getTargetChildren
                                                             ($phb_child) })
            {
                my $num_connections = $targetObj->getNumConnections
                                                      ($phb_config_child);
                if ($num_connections > 0)
                {
                    # We have a PHB connection
                    # We need to create the PEC attributes
                    my $phb_num = $targetObj->getAttribute
                                      ($phb_config_child, "PHB_NUM");

                    # Get lane group and set lane masks
                    my $lane_group = $targetObj->getAttribute
                                      ($phb_config_child, "PCIE_LANE_GROUP");

                    # Set up Lane Swap attribute
                    # Get attribute that says if lane swap is set up for this
                    # bus. Taken as a 1 or 0 (on or off)
                    # Lane Reversal = swapped lanes
                    my $lane_swap = $targetObj->getBusAttribute
                            ($phb_config_child, 0, "LANE_REVERSAL");

                    # Lane swap comes out as "00" or "01" - so add 0 so it
                    # converts to an integer to evaluate.
                    my $lane_swap_int = $lane_swap + 0;

                    # The PROC_PCIE_IOP_SWAP attribute is PEC specific. The
                    # right most bit represents the highest numbered PHB in
                    # the PEC. e.g. for PEC2, bit 7 represents PHB5 while bit
                    # 5 represents PHB3. A value of 5 (00000101) represents
                    # both PHB3 and 5 having swap set.

                    # Because of the ordering of how we process PHB's and the
                    # different number of PHB's in each PEC we have to bitshift
                    # by a different number for each PHB in each PEC.
                    if ($lane_swap_int)
                    {
                        if ($pec_num eq 0)
                        {
                            # This number is not simply the PEC unit number,
                            # but the number of PHB's in each PEC.
                            $bitshift_const = 0;
                        }
                        elsif ($pec_num eq 1)
                        {
                            $bitshift_const = 1;
                        }
                        elsif ($pec_num eq 2)
                        {
                            $bitshift_const = 2;
                        }
                        else
                        {
                            die "Invalid PEC Chip unit number for target $target";
                        }

                        # The bitshift number is the absoulte value of the phb
                        # counter subtracted from the bitshift_const for this
                        # pec. For PHB 3, this abs(0-2), giving a bitshift of 2
                        # and filling in the correct bit in IOP_SWAP (5).
                        my $bitshift = abs($phb_counter - $bitshift_const);

                        $pec_iop_swap |= 1 << $bitshift;
                    }

                    my $pcie_bifurcated = "0";
                    if ($targetObj->isBusAttributeDefined($phb_config_child, 0, "PCIE_BIFURCATED")) {
                        $pcie_bifurcated = $targetObj->getBusAttribute
                                ($phb_config_child, 0, "PCIE_BIFURCATED");
                    }
                    # Set the lane swap for the PEC. If we find more swaps as
                    # we process the other PCI busses then we will overwrite
                    # the overall swap value with the newly computed one.
                    if ($pcie_bifurcated eq "1") {
                        $targetObj->setAttribute($target,
                            "PEC_PCIE_IOP_SWAP_BIFURCATED", $pec_iop_swap);
                    } else {
                        $targetObj->setAttribute($target,
                            "PEC_PCIE_IOP_SWAP_NON_BIFURCATED", $pec_iop_swap);
                        $targetObj->setAttribute($target,
                            "PROC_PCIE_IOP_SWAP", $pec_iop_swap);
                    }

                    $lane_mask[$lane_group][0] =
                        $targetObj->getAttribute
                            ($phb_config_child, "PCIE_LANE_MASK");

                    my $lane_mask_attr = sprintf("%s,%s,%s,%s",
                        $lane_mask[0][0], $lane_mask[1][0],
                        $lane_mask[2][0], $lane_mask[3][0]);

                    if ($pcie_bifurcated eq "1") {
                        $targetObj->setAttribute($target,
                            "PEC_PCIE_LANE_MASK_BIFURCATED", $lane_mask_attr);
                    } else {
                        $targetObj->setAttribute($target, "PROC_PCIE_LANE_MASK",
                            $lane_mask_attr);
                        $targetObj->setAttribute($target,
                            "PEC_PCIE_LANE_MASK_NON_BIFURCATED", $lane_mask_attr);
                    }

                    # Only compute the HDAT attributes if they are available
                    # and have default values
                    if (!($targetObj->isBadAttribute($phb_config_child,
                                                        "ENABLE_LSI")))
                    {
                        # Get capabilites, and bit shift them correctly
                        # Set the CAPABILITES attribute for evey PHB
                        my $lsiSupport = $targetObj->getAttribute
                                         ($phb_config_child, "ENABLE_LSI");
                        my $capiSupport = ($targetObj->getAttribute
                                      ($phb_config_child, "ENABLE_CAPI")) << 1;
                        my $cableCardSupport = ($targetObj->getAttribute
                                 ($phb_config_child, "ENABLE_CABLECARD")) << 2;
                        my $hotPlugSupport = ($targetObj->getAttribute
                                   ($phb_config_child, "ENABLE_HOTPLUG")) << 3;
                        my $sriovSupport = ($targetObj->getAttribute
                                     ($phb_config_child, "ENABLE_SRIOV")) << 4;
                        my $elLocoSupport = ($targetObj->getAttribute
                                    ($phb_config_child, "ENABLE_ELLOCO")) << 5;
                        my $nvLinkSupport = ($targetObj->getAttribute
                                    ($phb_config_child, "ENABLE_NVLINK")) << 6;
                        my $capabilites = sprintf("0x%X", ($nvLinkSupport |
                            $elLocoSupport | $sriovSupport | $hotPlugSupport |
                            $cableCardSupport | $capiSupport | $lsiSupport));


                        $targetObj->setAttribute($phb_child, "PCIE_CAPABILITES",
                            $capabilites);

                        # Set MGC_LOAD_SOURCE for every PHB
                        my $mgc_load_source = $targetObj->getAttribute
                           ($phb_config_child, "MGC_LOAD_SOURCE");

                        $targetObj->setAttribute($phb_child, "MGC_LOAD_SOURCE",
                            $mgc_load_source);

                        # Find if this PHB has a pcieslot connection
                        my $pcieBusConnection =
                            $targetObj->findConnections($phb_child,"PCIE","");

                        # Inspect the connection and set appropriate attributes
                        foreach my $pcieBus (@{$pcieBusConnection->{CONN}})
                        {
                            # Check if destination is a switch(PEX) or built in
                            # device(USB) and set entry type attribute
                            my $destTargetType = $targetObj->getTargetType
                                ($pcieBus->{DEST_PARENT});
                            if ($destTargetType eq "chip-PEX8725")
                            {
                                # Destination is a switch upleg. Set entry type
                                # that corresponds to switch upleg.
                                $targetObj->setAttribute($phb_child,
                                    "ENTRY_TYPE","0x01");

                                # Set Station ID (only valid for switch upleg)
                                my $stationId = $targetObj->getAttribute
                                   ($pcieBus->{DEST}, "STATION");

                                $targetObj->setAttribute($phb_child,
                                    "STATION_ID",$stationId);
                                # Set device and vendor ID from the switch
                                my $vendorId = $targetObj->getAttribute
                                   ($pcieBus->{DEST_PARENT}, "VENDOR_ID");
                                my $deviceId = $targetObj->getAttribute
                                   ($pcieBus->{DEST_PARENT}, "DEVICE_ID");
                                $targetObj->setAttribute($phb_child,
                                    "VENDOR_ID",$vendorId);
                                $targetObj->setAttribute($phb_child,
                                    "DEVICE_ID",$deviceId);
                            }
                            elsif ($destTargetType eq "chip-TUSB7340")
                            {
                                # Destination is a built in device. Set entry
                                # type that corresponds to built in device
                                $targetObj->setAttribute($phb_child,
                                    "ENTRY_TYPE","0x03");
                                # Set device and vendor ID from the device
                                my $vendorId = $targetObj->getAttribute
                                   ($pcieBus->{DEST_PARENT}, "VENDOR_ID");
                                my $deviceId = $targetObj->getAttribute
                                   ($pcieBus->{DEST_PARENT}, "DEVICE_ID");
                                $targetObj->setAttribute($phb_child,
                                    "VENDOR_ID",$vendorId);
                                $targetObj->setAttribute($phb_child,
                                    "DEVICE_ID",$deviceId);
                            }

                            # If the source is a PEX chip, its a switch downleg
                            # Set entry type accordingly
                            my $sourceTargetType = $targetObj->getTargetType
                                ($pcieBus->{SOURCE_PARENT});
                            if ($sourceTargetType eq "chip-PEX8725")
                            {
                                # Destination is a switch downleg.
                                $targetObj->setAttribute($phb_child,
                                    "ENTRY_TYPE","0x02");

                                # Set Ports which this downleg switch connects
                                # to. Only valid for switch downleg
                                my $portId = $targetObj->getAttribute
                                   ($pcieBus->{DEST}, "PORT");

                                $targetObj->setAttribute($phb_child, "PORT_ID",
                                    $portId);

                                # Set device and vendor ID from the device
                                my $vendorId = $targetObj->getAttribute
                                   ($pcieBus->{SOURCE_PARENT}, "VENDOR_ID");
                                my $deviceId = $targetObj->getAttribute
                                   ($pcieBus->{SOURCE_PARENT}, "DEVICE_ID");
                                $targetObj->setAttribute($phb_child,
                                    "VENDOR_ID",$vendorId);
                                $targetObj->setAttribute($phb_child,
                                    "DEVICE_ID",$deviceId);
                            }

                            # Get the parent of the DEST_PARENT, and chek its
                            # instance type
                            my $parent_target =
                              $targetObj->getTargetParent($pcieBus->{DEST_PARENT});
                            my $parentTargetType =
                                $targetObj->getTargetType($parent_target);
                            if ($parentTargetType eq "slot-pcieslot-generic")
                            {
                                # Set these attributes only if we are in a pcie
                                # slot connection
                                my $hddw_order = $targetObj->getAttribute
                                    ($parent_target, "HDDW_ORDER");
                                my $slot_index = $targetObj->getAttribute
                                    ($parent_target, "SLOT_INDEX");
                                my $slot_name = $targetObj->getAttribute
                                    ($parent_target, "SLOT_NAME");
                                my $mmio_size_32 = $targetObj->getAttribute
                                    ($parent_target, "32BIT_MMIO_SIZE");
                                my $mmio_size_64 = $targetObj->getAttribute
                                    ($parent_target, "64BIT_MMIO_SIZE");
                                my $dma_size_32 = $targetObj->getAttribute
                                    ($parent_target, "32BIT_DMA_SIZE");
                                my $dma_size_64 = $targetObj->getAttribute
                                    ($parent_target, "64BIT_DMA_SIZE");

                                $targetObj->setAttribute($phb_child, "HDDW_ORDER",
                                    $hddw_order);
                                $targetObj->setAttribute($phb_child, "SLOT_INDEX",
                                    $slot_index);
                                $targetObj->setAttribute($phb_child, "SLOT_NAME",
                                    $slot_name);
                                $targetObj->setAttribute($phb_child,
                                    "PCIE_32BIT_MMIO_SIZE", $mmio_size_32);
                                $targetObj->setAttribute($phb_child,
                                    "PCIE_64BIT_MMIO_SIZE", $mmio_size_64);
                                $targetObj->setAttribute($phb_child,
                                    "PCIE_32BIT_DMA_SIZE", $dma_size_32);
                                $targetObj->setAttribute($phb_child,
                                    "PCIE_64BIT_DMA_SIZE", $dma_size_64);
                                $targetObj->setAttribute($phb_child,
                                    "ENTRY_FEATURES", "0x0001");

                                # Only set MAX_POWER if it exisits in the system
                                # xml. TODO to remove this check when system xml
                                # is upated: RTC:175319
                                if (!($targetObj->isBadAttribute
                                    ($parent_target,"MAX_POWER")))
                                {
                                    my $maxSlotPower = $targetObj->getAttribute
                                    ($parent_target, "MAX_POWER");
                                    $targetObj->setAttribute($phb_child,
                                        "MAX_POWER",$maxSlotPower);
                                }

                            }
                            else
                            {
                                # Set these attributes only for non-pcie slot
                                # connections
                                $targetObj->setAttribute($phb_child,
                                    "ENTRY_FEATURES", "0x0002");
                            }
                        }
                    }
                } # Found connection
            } # PHB bus loop

            $phb_counter = $phb_counter + 1;

        } # PHB loop
    } # PEC config loop
}
#--------------------------------------------------
## OCC
##
sub processOcc
{
    my $targetObj    = shift;
    my $target       = shift;
    my $parentTarget = shift;
    my $master_capable=0;

    my $proc_type = $targetObj->getAttribute($parentTarget, "PROC_MASTER_TYPE");

    if ($proc_type eq "ACTING_MASTER" )
    {
        $master_capable=1;
    }
    $targetObj->setAttribute($target,"OCC_MASTER_CAPABLE",$master_capable);
}


sub getI2cMapField
{
    my $targetObj = shift;
    my $target = shift;
    my $conn_target = shift;


    my $port = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_PORT");
    my $engine = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_ENGINE");
    my $addr = "";

    # For Open Power systems continue to get the I2C_ADDRESS from
    # bus target, if defined.
    if ($targetObj->isBusAttributeDefined(
           $conn_target->{SOURCE},$conn_target->{BUS_NUM},"I2C_ADDRESS"))
    {
        $addr = $targetObj->getBusAttribute($conn_target->{SOURCE},
            $conn_target->{BUS_NUM}, "I2C_ADDRESS");
    }
    # If bus doesn't have I2C_ADDRESS or default value is not set,
    # then get it from i2c-slave, if defined.
    if ($addr eq "")
    {
        if (! $targetObj->isBadAttribute($conn_target->{DEST},"I2C_ADDRESS") )
        {
           $addr = $targetObj->getAttribute($conn_target->{DEST},"I2C_ADDRESS");
        }
    }

    #if the addr is still not defined, then throw an error
    if ($addr eq "")
    {
        print ("ERROR: I2C_ADDRESS is not defined for $conn_target\n");
        $targetObj->myExit(4);
    }

    my $bits=sprintf("%08b",hex($addr));
    my $field=sprintf("%d%3s",oct($port),substr($bits,4,3));
    my $hexfield = sprintf("%X",oct("0b$field"));
    return $hexfield;
}

#--------------------------------------------------
# I2C
#
sub processI2C
{
    my $targetObj    = shift; # Top Hierarchy of targeting structure
    my $target       = shift; # I2C targetInstance
    my $parentTarget = shift; # Processor target

    # Initialize output arrays
    my @i2cEngine = ();
    my @i2cPort = ();
    my @i2cSlave = ();
    my @i2cAddr = ();
    my @i2cSpeed = ();
    my @i2cType = ();
    my @i2cPurpose = ();
    my @i2cLabel = ();

    # Step 1: get I2C_ENGINE and PORT from <targetInstance>

    my $engine = $targetObj->getAttribute($target, "I2C_ENGINE");
    if($engine eq "") {$engine = "0xFF";}

    my $port = $targetObj->getAttribute($target, "I2C_PORT");
    if($port eq "") {$port = "0xFF";}

    # Step 2: get I2C_ADDRESS and I2C_SPEED from <bus>
    #         This is different for each connection.

    my $i2cs = $targetObj->findConnections($parentTarget, "I2C","");
    if ($i2cs ne "")
    {
        # This gives all i2c connections
        foreach my $i2c (@{$i2cs->{CONN}})
        {
            # Here we are checking that the i2c source matches our target
            my $source = $i2c->{SOURCE};
            if ($source ne $target)
            {
                next;
            }

            # Most I2C devices will default the slave port, it is only valid
            # for gpio expanders.
            my $slavePort = "0xFF";
            my $purpose_str = undef;
            if ($targetObj->isBusAttributeDefined(
                    $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_PURPOSE"))
            {
                $purpose_str = $targetObj->getBusAttribute(
                               $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_PURPOSE");
            }

            if(   defined $purpose_str
               && $purpose_str ne "")
            {
                my $parent = $targetObj->getTargetParent($i2c->{DEST});
                foreach my $aTarget ( sort keys %{ $targetObj->getAllTargets()})
                {
                    if($aTarget =~ m/$parent/)
                    {
                        if ($targetObj->isBadAttribute($aTarget,"PIN_NAME"))
                        {
                            next;
                        }

                        my $pin = $targetObj->getAttribute($aTarget,
                                                           "PIN_NAME");
                        if($pin eq $purpose_str)
                        {
                            ($slavePort) = $aTarget =~ m/\-([0-9]+)$/g;
                            last;
                        }
                    }
                }
            }

            my $type_str;
            my $purpose;
            my $addr;
            my $speed;
            my $type;
            my $label;

            # For all these attributes, we need to check if they're defined,
            # and if not we set them to a default value.
            if ($targetObj->isBusAttributeDefined(
                     $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_ADDRESS"))
            {
                $addr = $targetObj->getBusAttribute(
                           $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_ADDRESS");
            }

            # If bus doesn't have I2C_ADDRESS or default value is not set,
            # then get it from i2c-slave, if defined.
            if ($addr eq "")
            {
                if (! $targetObj->isBadAttribute($i2c->{DEST},"I2C_ADDRESS") )
                {
                   $addr = $targetObj->getAttribute($i2c->{DEST},"I2C_ADDRESS");
                }
            }

            if ($addr eq "") {$addr = "0xFF";}

            if ($targetObj->isBusAttributeDefined(
                     $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_SPEED"))
            {
                $speed = HZ_PER_KHZ * $targetObj->getBusAttribute(
                           $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_SPEED");
            }

            if ($speed eq "") {$speed = "0";}

            if ($targetObj->isBusAttributeDefined(
                     $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_TYPE"))
            {
                $type_str = $targetObj->getBusAttribute(
                                $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_TYPE");
            }

            if ($type_str eq "")
            {
                $type = "0xFF";
            }
            # TPM types can vary by MODEL number
            elsif ($type_str eq "NUVOTON_TPM")
            {
                # Model values can be found in tpmddif.H and are kept in
                # sync with TPM_MODEL attribute in attribute_types_hb.xml
                my $tpm_model = $targetObj->getAttribute($i2c->{DEST_PARENT},"TPM_MODEL");
                if ($tpm_model eq 1)
                {
                    $type = $targetObj->getEnumValue("HDAT_I2C_DEVICE_TYPE",$type_str);
                }
                if ($tpm_model eq 2)
                {
                    # @TODO RTC 212201 use proper enum when <system>.xml supports it
                    #$type = $targetObj->getEnumValue("HDAT_I2C_DEVICE_TYPE","TCG_I2C_TPM");
                    $type = 0x15;
                }
            }
            else
            {
                $type = $targetObj->getEnumValue("HDAT_I2C_DEVICE_TYPE",$type_str);
            }

            if ($targetObj->isBusAttributeDefined(
                     $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_PURPOSE"))
            {
                $purpose_str = $targetObj->getBusAttribute(
                                $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_PURPOSE");
            }

            if ($purpose_str eq "")
            {
                $purpose = "0xFF";
            }
            else
            {
                $purpose = $targetObj->getEnumValue("HDAT_I2C_DEVICE_PURPOSE",
                                                    $purpose_str);
            }


            if ($targetObj->isBusAttributeDefined(
                     $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_LABEL"))
            {
                $label = $targetObj->getBusAttribute(
                           $i2c->{SOURCE},$i2c->{BUS_NUM},"I2C_LABEL");
            }

            if ($label eq "")
            {
                # For SEEPROMS:
                # <vendor>,<device type>, <data type>, <hw subsystem>
                if (($type_str eq  "SEEPROM") ||
                    ($type_str =~ m/SEEPROM_Atmel28c128/i))
                {
                    $label = "atmel,28c128,";
                }
                elsif($type_str =~ m/SEEPROM_Atmel28c256/i)
                {
                    $label = "atmel,28c256,";
                }
                if ($label ne "")
                {
                    if ($purpose_str =~ m/MODULE_VPD/)
                    {
                        $label .= "vpd,module";
                    }
                    elsif ($purpose_str =~ m/DIMM_SPD/)
                    {
                        $label .= "spd,dimm";
                    }
                    elsif ($purpose_str =~ m/PROC_MODULE_VPD/)
                    {
                        $label .= "vpd,module";
                    }
                    elsif ($purpose_str =~ m/SBE_SEEPROM/)
                    {
                        $label .= "image,sbe";
                    }
                    elsif ($purpose_str =~ m/PLANAR_VPD/)
                    {
                        $label .= "vpd,planar";
                    }
                    else
                    {
                        $label .= "unknown,unknown";
                    }
                }
                # For GPIO expanders:
                # <vendor>,<device type>,<domain>,<purpose>
                if ($label eq "")
                {
                    if ($type_str =~ m/9551/)
                    {
                        $label = "nxp,pca9551,";
                    }
                    elsif ($type_str =~ m/9552/)
                    {
                        $label = "nxp,pca9552,";
                    }
                    elsif ($type_str =~ m/9553/)
                    {
                        $label = "nxp,pca9553,";
                    }
                    elsif ($type_str =~ m/9554/)
                    {
                        $label = "nxp,pca9554,";
                    }
                    elsif ($type_str =~ m/9555/)
                    {
                        $label = "nxp,pca9555,";
                    }
                    elsif($type_str =~ m/UCX90XX/)
                    {
                        $label = "ti,ucx90xx,";
                    }

                    if ($label ne "")
                    {
                        if ($purpose_str =~ m/CABLE_CARD_PRES/)
                        {
                            $label .= "cablecard,presence";
                        }
                        elsif ($purpose_str =~ m/PCI_HOTPLUG_PGOOD/)
                        {
                            $label .= "pcie-hotplug,pgood";
                        }
                        elsif ($purpose_str =~ m/PCI_HOTPLUG_CONTROL/)
                        {
                            $label .= "pcie-hotplug,control";
                        }
                        elsif ($purpose_str =~ m/WINDOW_OPEN/)
                        {
                            $label .= "secure-boot,window-open";
                        }
                        elsif ($purpose_str =~ m/PHYSICAL_PRESENCE/)
                        {
                            $label .= "secure-boot,physical-presence";
                        }
                        else
                        {
                            $label .= "unknown,unknown";
                        }
                    }
                }

                # For TPM:
                # <vendor>,<device type>,<purpose>,<scope>
                if ($type_str eq "NUVOTON_TPM")
                {
                    # Model values can be found in tpmddif.H and are kept in
                    # sync with TPM_MODEL attribute in attribute_types_hb.xml
                    my $tpm_model = $targetObj->getAttribute($i2c->{DEST_PARENT},"TPM_MODEL");
                    if ($tpm_model eq 1)
                    {
                        $label = "nuvoton,npct601,tpm,host";
                    }
                    if ($tpm_model eq 2)
                    {
                        $label = "tcg,tpm_i2c_ptp,tpm,host";
                    }
                }

                if ($label eq "")
                {
                    $label = "unknown,unknown,unknown,unknown"
                }

                $label = '"' . $label . '"';

            } # end of filling in default label values
            elsif ($label !~ m/^\".*\"$/)
            {
                # add quotes around label
                $label = '"' . $label . '"';
            }


            # Step 3: For each connection, create an instance in the array
            #         for the DeviceInfo_t struct.
            push @i2cEngine, $engine;
            push @i2cPort, $port;
            push @i2cSlave, $slavePort;
            push @i2cAddr, $addr;
            push @i2cSpeed, $speed;
            push @i2cType, $type;
            push @i2cPurpose, $purpose;
            push @i2cLabel, $label;

        }
    }

    # Return this i2c device's information back to the processor
    return (\@i2cEngine, \@i2cPort, \@i2cSlave, \@i2cAddr,
            \@i2cSpeed, \@i2cType, \@i2cPurpose, \@i2cLabel);
}

sub setEepromAttributes
{
    my $targetObj = shift;
    my $name = shift;
    my $target = shift;
    my $conn_target = shift;
    my $fru = shift;

    my $port = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_PORT");
    my $engine = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_ENGINE");
    #my $addr = $targetObj->getBusAttribute($conn_target->{SOURCE},
    #        $conn_target->{BUS_NUM}, "I2C_ADDRESS");

    my $addr = $targetObj->getAttribute($conn_target->{DEST},"I2C_ADDRESS");
    my $path = $targetObj->getAttribute($conn_target->{SOURCE_PARENT}, "PHYS_PATH");
    my $mem  = $targetObj->getAttribute($conn_target->{DEST_PARENT},
               "MEMORY_SIZE_IN_KB");
    my $count  = 1; # default for VPD SEEPROMs
    my $cycle  = $targetObj->getAttribute($conn_target->{DEST_PARENT},
               "WRITE_CYCLE_TIME");
    my $page  = $targetObj->getAttribute($conn_target->{DEST_PARENT},
               "WRITE_PAGE_SIZE");
    my $offset  = $targetObj->getAttribute($conn_target->{DEST_PARENT},
               "BYTE_ADDRESS_OFFSET");

    $targetObj->setAttributeField($target, $name, "i2cMasterPath", $path);
    $targetObj->setAttributeField($target, $name, "port", $port);
    $targetObj->setAttributeField($target, $name, "devAddr", $addr);
    $targetObj->setAttributeField($target, $name, "engine", $engine);
    $targetObj->setAttributeField($target, $name, "byteAddrOffset", $offset);
    $targetObj->setAttributeField($target, $name, "maxMemorySizeKB", $mem);
    $targetObj->setAttributeField($target, $name, "chipCount", $count);
    $targetObj->setAttributeField($target, $name, "writePageSize", $page);
    $targetObj->setAttributeField($target, $name, "writeCycleTime", $cycle);

    if ($fru ne "")
    {
        $targetObj->setAttributeField($target, $name, "fruId", $fru);
    }
}
sub setDimmTempAttributes
{
    my $targetObj = shift;
    my $target = shift;
    my $conn_target = shift;
    my $fru = shift;

    my $name = "TEMP_SENSOR_I2C_CONFIG";
    my $port = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_PORT");
    my $engine = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_ENGINE");
    my $addr = $targetObj->getAttribute($conn_target->{DEST},"I2C_ADDRESS");
    my $path = $targetObj->getAttribute($conn_target->{SOURCE_PARENT},
               "PHYS_PATH");

    $targetObj->setAttributeField($target, $name, "i2cMasterPath", $path);
    $targetObj->setAttributeField($target, $name, "port", $port);
    $targetObj->setAttributeField($target, $name, "devAddr", $addr);
    $targetObj->setAttributeField($target, $name, "engine", $engine);
}


sub setGpioAttributes
{
    my $targetObj = shift;
    my $target = shift;
    my $conn_target = shift;
    my $vddrPin = shift;

    my $port = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_PORT");
    my $engine = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_ENGINE");
    my $addr = $targetObj->getBusAttribute($conn_target->{SOURCE},
            $conn_target->{BUS_NUM}, "I2C_ADDRESS");
    my $path = $targetObj->getAttribute($conn_target->{SOURCE_PARENT},
               "PHYS_PATH");


    my $name="GPIO_INFO";
    $targetObj->setAttributeField($target, $name, "i2cMasterPath", $path);
    $targetObj->setAttributeField($target, $name, "port", $port);
    $targetObj->setAttributeField($target, $name, "devAddr", $addr);
    $targetObj->setAttributeField($target, $name, "engine", $engine);
    $targetObj->setAttributeField($target, $name, "vddrPin", $vddrPin);
}

#--------------------------------------------------
## Compute max compute node
sub get_max_compute_nodes
{
   my $targetObj = shift;
   my $sysTarget = shift;
   my $retVal = 0;
   ##
   #Proceeed only for sys targets
   ##
   #For fabric_node_map, we store the node's position at the node
   #position's index
   my @fabric_node_map = (255, 255, 255, 255, 255, 255, 255, 255);
   if ($targetObj->getType($sysTarget) eq "SYS")
   {
      foreach my $child (@{$targetObj->getTargetChildren($sysTarget)})
      {
         if ($targetObj->isBadAttribute($child, "ENC_TYPE") == 0)
         {
            my $attrVal =  $targetObj->getAttribute($child, "ENC_TYPE");
            if ($attrVal eq "CEC")
            {
                my $fapi_pos = $targetObj->getAttribute($child, "FAPI_POS");
                $fabric_node_map[$fapi_pos] = $fapi_pos;
                $retVal++;
            }
         }
      }
      ##
      #For Open Power systems this attribute
      #is not populated, we consider default value as 1
      # for open power systems.
      ##
      if ($retVal  == 0 )
      {
         $retVal = 1;
      }

      #Convert array into a comma separated string
      my $node_map = "";
      foreach my $i (@fabric_node_map)
      {
            $node_map .= "$i,";
      }

      #remove the last comma
      $node_map =~ s/.$//;
      $targetObj->setAttribute($sysTarget, "FABRIC_TO_PHYSICAL_NODE_MAP", $node_map);
   }
   return $retVal;
}

#--------------------------------------------------
# @brief Error checking
#
#--------------------------------------------------
sub errorCheck
{
    my $targetObj = shift;
    my $target    = shift;
    my $type      = $targetObj->getType($target);

    ## error checking even for connections are done with attribute checks
    ##  since connections simply create attributes at source and/or destination
    ##
    ## also error checking after processing is complete vs during
    ## processing is easier
    my %attribute_checks = (
        SYS         => ['SYSTEM_NAME'],#'OPAL_MODEL'],
        PROC        => ['FSI_MASTER_CHIP', 'EEPROM_VPD_PRIMARY_INFO/devAddr'],
        MEMBUF      => [ 'PHYS_PATH', 'EI_BUS_TX_MSBSWAP', 'FSI_MASTER_PORT|0xFF' ],
    );
    my %error_msg = (
        'EEPROM_VPD_PRIMARY_INFO/devAddr' =>
          'I2C connection to target is not defined',
        'FSI_MASTER_PORT' => 'This target is missing a required FSI connection',
        'FSI_MASTER_CHIP' => 'This target is missing a required FSI connection',
    );

    my @errors;
    foreach my $attr (@{ $attribute_checks{$type} })
    {
        my ($a,         $v)     = split(/\|/, $attr);
        my ($a_complex, $field) = split(/\//, $a);
        if ($field ne "")
        {
            if ($targetObj->isBadComplexAttribute(
                    $target, $a_complex, $field, $v) )
            {
                push(@errors,sprintf(
                        "$a attribute is invalid (Target=%s)\n\t%s\n",
                        $target, $error_msg{$a}));
            }
        }
        else
        {
            if ($targetObj->isBadAttribute($target, $a, $v))
            {
                push(@errors,sprintf(
                        "$a attribute is invalid (Target=%s)\n\t%s\n",
                        $target, $error_msg{$a}));
            }
        }
    }
    if ($type eq "PROC")
    {
        ## this checks if at least 1 abus is connected
        my $found_abus = 0;
        my $abus_error = "";

        foreach my $child (@{ $targetObj->getTargetChildren($target) })
        {
            my $child_type = $targetObj->getBusType($child);
            if ($child_type eq "ABUS" || $child_type eq "XBUS")
            {
              my $proc_type = $targetObj->getAttribute($target, "PROC_MASTER_TYPE");

              if ($proc_type eq "NOT_MASTER" )
              {
                    if (!$targetObj->isBadAttribute($child, "PEER_TARGET"))
                    {
                        $found_abus = 1;
                    }
                    else
                    {
                        $abus_error = sprintf(
"proc not connected to proc via Abus or Xbus (Target=%s)",$child);
                    }
              }
            }
        }
        if ($found_abus)
        {
            $abus_error = "";
        }
        else
        {
            push(@errors, $abus_error);
        }
    }
    if ($errors[0])
    {
        foreach my $err (@errors)
        {
            print "ERROR: $err\n";
        }
        $targetObj->myExit(3);
    }
}

################################################################################
# utility function used to call plugins. if none exists, call is skipped.
################################################################################

sub do_plugin
{
    my $step = shift;
    if (exists($hwsvmrw_plugins{$step}))
    {
        $hwsvmrw_plugins{$step}(@_);
    }
    elsif ($targetObj->{debug} && ($targetObj->{build} eq "fsp"))
    {
        print STDERR "build is $targetObj->{build} but no plugin for $step\n";
    }
}

###############################################################################
# Self tests
###############################################################################
#--------------------------------------------------
# @brief The main procedure to run the tests
#
# @param[in] $targetObj - The global target object
#--------------------------------------------------
sub runTests
{
    print "\nRunning tests: \n\n";
    my $targetObj = shift;

    # Load the XML and process the file, extracting targets and associating
    # attributes, with their data, to the targets
    loadXmlFile($targetObj);

    # Process the targets, setting the targets attributes.
    processTargets($targetObj);

    # Each one of the test build on each other, if one fails then no point in
    # running the other
    testGetTopologyMode($targetObj)   &&
    testTopologyIdToTopologyIndex()   &&
    testGetTopologyIndex($targetObj);

    testMaxInstPerProc($targetObj);
}

#--------------------------------------------------
# @brief Test the method that gets the topology mode.
#
# @param[in] $targetObj - The global target object
#
# @return true if test passed, false other wise
#--------------------------------------------------
sub testGetTopologyMode
{
    print ">> Running testgetTopologyMode \n";
    my $targetObj = shift;

    my $testPassed = true;

    use constant TOPOLOGY_MODE_ATTRIBUTE => "PROC_FABRIC_TOPOLOGY_MODE";
    use constant TOPOLOGY_MODES => qw/ MODE0 MODE1 /;
    my @topologyModes = (TOPOLOGY_MODES);

    # Cache the current mode to restore later
    my $persistMode = $targetObj->getAttribute("/".$targetObj->{TOP_LEVEL},
                                               TOPOLOGY_MODE_ATTRIBUTE);

    # Test getting the topology mode
    foreach my $topologyMode (@topologyModes)
    {
        $targetObj->setAttribute("/".$targetObj->{TOP_LEVEL},
                                 TOPOLOGY_MODE_ATTRIBUTE,
                                 $topologyMode);
        my $topologyModeNumber = chop($topologyMode);
        if (getTopologyMode($targetObj) != $topologyModeNumber)
        {

            $testPassed = false;
            print "ERROR: Expected topology mode '$topologyModeNumber' but got " .
                   getTopologyMode($targetObj) . "\n";
        }
    }

    # Restore mode
    $targetObj->setAttribute("/".$targetObj->{TOP_LEVEL},
                             TOPOLOGY_MODE_ATTRIBUTE,
                             $persistMode);

    print "<< Running testgetTopologyMode: test " .
          getPassFailString($testPassed) . "\n";

    return $testPassed;
}

#--------------------------------------------------
# @brief Tests the conversion method that converts the topology ID,
#        with given topology mode, to the topology index.
#
# @return true if test passed, false other wise
#--------------------------------------------------
sub testTopologyIdToTopologyIndex
{
    print ">> Running testTopologyIdToTopologyIndex \n";

    my $testPassed = true;

    # The different values expected when mode is 0 or 1
    use constant TOPOLOGY_MODE_0_ARRAY => qw/ 0 1 4 5 8 9 12 13 16 17 20 21 24 25 28 29 /;
    use constant TOPOLOGY_MODE_1_ARRAY => qw/ 0 1 2 3 8 9 10 11 16 17 18 19 24 25 26 27 /;

    # The different topology modes
    use constant TOPOLOGY_MODES => qw/ MODE0 MODE1 /;
    my @topologyModes = (TOPOLOGY_MODES);

    # Default with mode 0
    my @toplogyModeArray = (TOPOLOGY_MODE_0_ARRAY);

    # Test the conversion on the different IDs and modes
    for my $topologyMode (@topologyModes)
    {
        my $topologyModeNumber = chop($topologyMode);
        if (1 == $topologyModeNumber)
        {
            @toplogyModeArray = (TOPOLOGY_MODE_1_ARRAY);
        }

        # Needed variable
        my $topologyIndex = 0;

        # Iterate thru each permutation of the topology ID and
        # test conversion to index
        for (my $topologyId = 0; $topologyId < 16; ++$topologyId)
        {
            $topologyIndex = convertTopologyIdToIndex($topologyId,
                                                      $topologyModeNumber);
            if ($topologyIndex != $toplogyModeArray[$topologyId])
            {
                $testPassed = false;
                print "ERROR: conversion on topology Id($topologyId) with ";
                print "topology mode($topologyMode) returned ";
                print "topology index($topologyIndex), but expected ";
                print "topology index($toplogyModeArray[$topologyId]) \n";
            }
        }  # end for (my $topologyId = 0 ...
    } # end foreach my $topologyMode (@topologyModes)

    print "<< Running testTopologyIdToTopologyIndex: test " .
          getPassFailString($testPassed) . "\n";

    return $testPassed;
}

#--------------------------------------------------
# @brief Test the method that gets the topology index based
#        based on the current processors within the MRW XML
#
# @param[in] $targetObj - The global target object
#
# @return true if test passed, false other wise
#--------------------------------------------------
sub testGetTopologyIndex
{
    my $targetObj = shift;

    my $testPassed = true;

    my $system_name = $targetObj->getAttribute('/sys-0',"SYSTEM_NAME");
    if ($system_name =~ /RAINIER/i)
    {
        print ">> Running testGetTopologyIndex \n";

        # The different procs available
        use constant PROC_0 => "/sys-0/node-0/nisqually-0/proc_socket-0/godel-0/power10-0";
        use constant PROC_1 => "/sys-0/node-0/nisqually-0/proc_socket-0/godel-0/power10-1";

        # Get processor 1's index
        my $processorTarget = PROC_0;
        my $topologyIndex = getTopologyIndex($targetObj, $processorTarget);

        # For the current MRW, proc 0 has index 0 with mode 0
        my $expectedTopologyIndex = 0;
        if ($topologyIndex != $expectedTopologyIndex)
        {
            $testPassed = false;
            my @fullProc = split(/\//, $processorTarget);
            print "ERROR: retrieved topology index $topologyIndex for processor " .
                   "@fullProc[-1] but expected $expectedTopologyIndex \n";
        }

        # Get processor 2's index
        $processorTarget = PROC_1;
        $topologyIndex = getTopologyIndex($targetObj, $processorTarget);

        # For the current MRW, proc 1 has index 4 with mode 0
        $expectedTopologyIndex = 4;
        if ($topologyIndex != $expectedTopologyIndex)
        {
            $testPassed = false;
            my @fullProc = split(/\//, $processorTarget);
            print "ERROR: retrieved topology index $topologyIndex for processor " .
                   "@fullProc[-1] but expected $expectedTopologyIndex \n";
        }

        print "<< Running testGetTopologyIndex: test " .
              getPassFailString($testPassed) . "\n";

    } # end if ($system_name =~ /RAINIER/i)

    return $testPassed;
}

#--------------------------------------------------
# @brief Test that maixumum instance per PROC have the right values.
#
# @param[in] $targetObj - The global target object
#
# @return true if test passed, false other wise
#--------------------------------------------------
sub testMaxInstPerProc
{
    print ">> Running testMaxInstPerProc \n";

    my $targetObj = shift;

    my $testPassed = true;

    my %targetPerProc =
    (
        EQ        => 8,
        FC        => 16,
        CORE      => 32,

        MC        => 4,
        MI        => 4,
        MCC       => 8,
        OMIC      => 8,
        OMI       => 16,
        OCMB_CHIP => 16,
        DDIMM     => 16,
        PMIC      => 32,

        PAUC      => 4,
        IOHS      => 8,
        PAU       => 8,
    );

    foreach my $target (keys %targetPerProc)
    {
        if ($targetObj->getMaxInstPerProc("$target") != $targetPerProc{$target})
        {
            print "ERROR: getMaxInstPerProc(\"$target\") returned " .
                   $targetObj->getMaxInstPerProc("$target") .
                   ", but expected " . $targetPerProc{$target} . "\n";
            $testPassed = $targetPerProc{$target};
        }

    }

    return $testPassed;
}

#--------------------------------------------------
# @brief A utility to return a given pass/fail flag as string "passed"/"failed"
#
# @param[in] $passFailBoolean - Flag indicating a pass/fail in terms of true/false.
#
# @return return string "passed" or "failed" based on input
#--------------------------------------------------
sub getPassFailString
{
    my $passFailBoolean = shift;
    my $failPassString = "passed";

    if ($passFailBoolean == false)
    {
        $failPassString = "failed";
    }

    return $failPassString;
}


