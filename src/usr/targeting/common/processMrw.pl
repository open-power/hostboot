#! /usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/processMrw.pl $
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

use strict;
use XML::Simple;
use Data::Dumper;
use Targets;
use Math::BigInt;
use Getopt::Long;
use File::Basename;

my $VERSION = "1.0.0";

my $force          = 0;
my $serverwiz_file = "";
my $version        = 0;
my $debug          = 0;
my $report         = 0;
my $sdr_file       = "";

# TODO RTC:170860 - Remove this after dimm connector defines VDDR_ID
my $num_voltage_rails_per_proc = 1;

GetOptions(
    "f"   => \$force,             # numeric
    "x=s" => \$serverwiz_file,    # string
    "d"   => \$debug,
    "v"   => \$version,
    "r"   => \$report,
  )                               # flag
  or printUsage();

if ($version == 1)
{
    die "\nprocessMrw.pl\tversion $VERSION\n";
}

if ($serverwiz_file eq "")
{
    printUsage();
}

$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $targetObj = Targets->new;
if ($force == 1)
{
    $targetObj->{force} = 1;
}
if ($debug == 1)
{
    $targetObj->{debug} = 1;
}

$targetObj->setVersion($VERSION);
my $xmldir = dirname($serverwiz_file);
$targetObj->loadXML($serverwiz_file);


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
#--------------------------------------------------
## loop through all targets and do stuff
foreach my $target (sort keys %{ $targetObj->getAllTargets() })
{
    my $type = $targetObj->getType($target);
    if ($type eq "SYS")
    {
        processSystem($targetObj, $target);
    }
    elsif ($type eq "PROC")
    {
        processProcessor($targetObj, $target);
    }
    elsif ($type eq "APSS")
    {
        processApss($targetObj, $target);
    }

    processIpmiSensors($targetObj,$target);
}

## check topology
foreach my $n (keys %{$targetObj->{TOPOLOGY}}) {
    foreach my $p (keys %{$targetObj->{TOPOLOGY}->{$n}}) {
        if ($targetObj->{TOPOLOGY}->{$n}->{$p} > 1) {
            print "ERROR: Fabric topology invalid.  2 targets have same ".
                  "FABRIC_GROUP_ID,FABRIC_CHIP_ID ($n,$p)\n";
            $targetObj->myExit(3);
        }
    }
}
## check for errors
if ($targetObj->getMasterProc() eq "")
{
    print "ERROR: Master Processor not defined.  Please instaitant a BMC
 and connect LPC bus\n";
    $targetObj->myExit(3);
}
foreach my $target (keys %{ $targetObj->getAllTargets() })
{
    errorCheck($targetObj, $target);
}

#--------------------------------------------------
## write out final XML
my $xml_fh;
my $filename = $xmldir . "/" . $targetObj->getSystemName() . "_hb.mrw.xml";
print "Creating XML: $filename\n";
open($xml_fh, ">$filename") || die "Unable to create: $filename";
$targetObj->printXML($xml_fh, "top");
close $xml_fh;
if (!$targetObj->{errorsExist})
{
    ## optionally print out report
    if ($report)
    {
        print "Writing report to: ".$targetObj->{report_filename}."\n";
        $targetObj->writeReportFile();
    }
    print "MRW created successfully!\n";
}


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

    #@fixme-RTC:174616-Remove deprecated support
    if (!$targetObj->isBadAttribute($target,"XSCOM_BASE_ADDRESS") )
    {
        my ($num,$base,$group_offset,$proc_offset,$offset) = split(/,/,
            $targetObj->getAttribute($target,"XSCOM_BASE_ADDRESS"));
        $targetObj->setAttribute($target, "XSCOM_BASE_ADDRESS", $base);
    }

    # TODO RTC:170860 - Remove this after dimm connector defines VDDR_ID
    my $system_name = $targetObj->getAttribute($target,"SYSTEM_NAME");
    if ($system_name =~ /ZAIUS/i)
    {
        $num_voltage_rails_per_proc = 2;
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
        }
    }
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
#--------------------------------------------------
## Processor
##

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
    ## Copy Position attribute from socket
    ## Copy PBAX attributes from socket
    foreach my $attr (sort (keys
           %{ $targetObj->getTarget($socket_target)->{TARGET}->{attribute} }))
    {
        if ($attr =~ /PROC\_PCIE/)
        {
            $targetObj->copyAttribute($socket_target,$target,$attr);
        }
        elsif ($attr =~/POSITION/)
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
    }

    # Both for FSP and BMC based systems, it's good  enough
    # to look for processor with active LPC bus connected
    $targetObj->log($target,"Finding master proc (looking for LPC Bus)");
    my $lpcs=$targetObj->findConnections($target,"LPC","");
    if ($lpcs ne "")
    {
       $targetObj->log ($target, "Setting master proc to $target");
       $targetObj->setMasterProc($target);
    }

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
        if ($child_type eq "ABUS")
        {
            processAbus($targetObj, $child);
        }
        elsif ($child_type eq "XBUS")
        {
            processXbus($targetObj, $child);
        }
        elsif ($child_type eq "OBUS")
        {
            processObus($targetObj, $child);
        }
        elsif ($child_type eq "FSIM" || $child_type eq "FSICM")
        {
            processFsi($targetObj, $child, $target);
        }
        elsif ($child_type eq "PEC")
        {
            processPec($targetObj, $child, $target);
        }
        elsif ($child_type eq "MCBIST")
        {
            processMcbist($targetObj, $child, $target);

            # TODO RTC:170860 - Eventually the dimm connector will
            #   contain this information and this can be removed
            my $socket_pos =  $targetObj->getAttribute($socket_target,
                                  "POSITION");
            if ($num_voltage_rails_per_proc > 1)
            {
                my $mcbist_pos = $targetObj->getAttribute($child, "CHIP_UNIT");
                $targetObj->setAttribute($child, "VDDR_ID",
                         $socket_pos*$num_voltage_rails_per_proc + $mcbist_pos);
            }
            else
            {
                $targetObj->setAttribute($child, "VDDR_ID", $socket_pos);
            }
        }
        elsif ($child_type eq "OCC")
        {
            processOcc($targetObj, $child, $target);
        }
    }

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

    ## initialize master processor FSI's
    $targetObj->setAttributeField($target, "FSI_OPTION_FLAGS", "flipPort", "0");

    if ($target eq $targetObj->getMasterProc())
    {
        $targetObj->setAttributeField($target, "FSI_OPTION_FLAGS", "reserved",
            "0");
        $targetObj->setAttribute($target, "FSI_MASTER_CHIP",    "physical:sys-0");
        $targetObj->setAttribute($target, "FSI_MASTER_PORT",    "0xFF");
        $targetObj->setAttribute($target, "ALTFSI_MASTER_CHIP", "physical:sys-0");
        $targetObj->setAttribute($target, "ALTFSI_MASTER_PORT", "0xFF");
        $targetObj->setAttribute($target, "FSI_MASTER_TYPE",    "NO_MASTER");
        $targetObj->setAttribute($target, "FSI_SLAVE_CASCADE",  "0");
        $targetObj->setAttribute($target, "PROC_MASTER_TYPE", "ACTING_MASTER");
    }
    else
    {
        $targetObj->setAttribute($target, "PROC_MASTER_TYPE",
            "NOT_MASTER");
        $targetObj->setAttribute($target, "ALTFSI_MASTER_CHIP", "physical:sys-0");
    }
    ## Update bus speeds
    processI2cSpeeds($targetObj,$target);

    ## these are hardcoded because code sets them properly
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "reserved",   "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useSbeScom", "1");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useFsiScom", "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useInbandScom",
        "0");
    $targetObj->setAttributeField($target, "SCOM_SWITCHES", "useXscom", "0");

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


    processMembufVpdAssociation($targetObj,$target);
    setupBars($targetObj,$target);
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

            if ($bus_speed eq "" || $bus_speed==0) {
                print "ERROR: I2C bus speed not defined for $i2c->{SOURCE}\n";
                $targetObj->myExit(3);
            }

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

################################
## Setup address map

sub setupBars
{
    my $targetObj = shift;
    my $target = shift;
    #--------------------------------------------------
    ## Setup BARs

    my $group = $targetObj->getAttribute($target, "FABRIC_GROUP_ID");
    my $proc   = $targetObj->getAttribute($target, "FABRIC_CHIP_ID");
    $targetObj->{TOPOLOGY}->{$group}->{$proc}++;

    my @bars=(  "FSP_BASE_ADDR",
                "VAS_HYPERVISOR_WINDOW_CONTEXT_ADDR",
                "VAS_USER_WINDOW_CONTEXT_ADDR",
                "NVIDIA_NPU_PRIVILEGED_ADDR",
                "NVIDIA_NPU_USER_REG_ADDR",
                "NVIDIA_PHY0_REG_ADDR",
                "NVIDIA_PHY1_REG_ADDR",
                "NX_RNG_ADDR");

    # Attribute only valid in naples-based systems
    if (!$targetObj->isBadAttribute($target,"NPU_MMIO_BAR_BASE_ADDR") ) {
          push(@bars,"NPU_MMIO_BAR_BASE_ADDR");
    }

    #@fixme-RTC:174616-Remove deprecated support
    if (!$targetObj->isBadAttribute($target,"LPC_BUS_ADDR") ) {
          push(@bars,"LPC_BUS_ADDR");
    }
    if (!$targetObj->isBadAttribute($target,"XSCOM_BASE_ADDRESS") ) {
          push(@bars,"XSCOM_BASE_ADDRESS");
    }
    if (!$targetObj->isBadAttribute($target,"PSI_BRIDGE_BASE_ADDR") ) {
          push(@bars,"PSI_BRIDGE_BASE_ADDR");
    }
    if (!$targetObj->isBadAttribute($target,"INTP_BASE_ADDR") ) {
          push(@bars,"INTP_BASE_ADDR");
    }
    if (!$targetObj->isBadAttribute($target,"PSI_HB_ESB_ADDR") ) {
          push(@bars,"PSI_HB_ESB_ADDR");
    }
    if (!$targetObj->isBadAttribute($target,"XIVE_CONTROLLER_BAR_ADDR") ) {
          push(@bars,"XIVE_CONTROLLER_BAR_ADDR");
    }

    foreach my $bar (@bars)
    {
        my ($num,$base,$group_offset,$proc_offset,$offset) = split(/,/,
               $targetObj->getAttribute($target,$bar));
        my $i_base = Math::BigInt->new($base);
        my $i_node_offset = Math::BigInt->new($group_offset);
        my $i_proc_offset = Math::BigInt->new($proc_offset);
        my $i_offset = Math::BigInt->new($offset);

        my $value="";
        if ($num==0)
        {
            my $b=sprintf("0x%016s",substr((
                        $i_base+$i_node_offset*$group+
                        $i_proc_offset*$proc)->as_hex(),2));
            $value=$b;
        }
        else
        {
            for (my $i=0;$i<$num;$i++)
            {
                #Note: Hex convert method avoids overflow on 32bit machine
                my $b=sprintf("0x%016s",substr((
                        $i_base+$i_node_offset*$group+
                        $i_proc_offset*$proc+$i_offset*$i)->as_hex(),2));
                my $sep=",";
                if ($i==$num-1)
                {
                    $sep="";
                }
                $value=$value.$b.$sep;
            }
        }
        $targetObj->setAttribute($target,$bar,$value);
    }
}

#--------------------------------------------------
## MCS
##
sub processMcs
{
    my $targetObj    = shift;
    my $target       = shift;
    my $parentTarget = shift;
    my $group        = shift;
    my $proc         = shift;

    #@FIXME RTC:168611 To decouple DVPD from PVPD
    #parentTarget == MCBIST
    #parent(MCBIST) = Proc
    #parent(proc) = module
    #parent(module) = socket
    #parent(socket) = motherboard
    #parent(motherboard) = node
    my $node = $targetObj->getTargetParent( #node
                    $targetObj->getTargetParent( #motherboard
                        $targetObj->getTargetParent #socket
                            ($targetObj->getTargetParent #module
                                ($targetObj->getTargetParent($parentTarget)))));
    my $name = "EEPROM_VPD_PRIMARY_INFO";
    $targetObj->copyAttributeFields($node, $target, "EEPROM_VPD_PRIMARY_INFO");

#@TODO RTC:163874 -- maybe needed for centaur support


#    my ($base,$group_offset,$proc_offset,$offset) = split(/,/,
#               $targetObj->getAttribute($target,"IBSCOM_MCS_BASE_ADDR"));
#    my $i_base = Math::BigInt->new($base);
#    my $i_node_offset = Math::BigInt->new($group_offset);
#    my $i_proc_offset = Math::BigInt->new($proc_offset);
#    my $i_offset = Math::BigInt->new($offset);

#    my $mcs = $targetObj->getAttribute($target, "MCS_NUM");
#    #Note: Hex convert method avoids overflow on 32bit machines
#    my $mcsStr=sprintf("0x%016s",substr((
#         $i_base+$i_node_offset*$group+
#         $i_proc_offset*$proc+$i_offset*$mcs)->as_hex(),2));
#    $targetObj->setAttribute($target, "IBSCOM_MCS_BASE_ADDR", $mcsStr);
}


## MCBIST
sub processMcbist
{
    my $targetObj    = shift;
    my $target       = shift;
    my $parentTarget = shift;

    my $group = $targetObj->getAttribute($parentTarget, "FABRIC_GROUP_ID");
    my $proc   = $targetObj->getAttribute($parentTarget, "FABRIC_CHIP_ID");
#@TODO RTC:163874 -- maybe needed for centaur support
#    my ($base,$group_offset,$proc_offset,$offset) = split(/,/,
#               $targetObj->getAttribute($target,"IBSCOM_MCS_BASE_ADDR"));
#    my $i_base = Math::BigInt->new($base);
#    my $i_node_offset = Math::BigInt->new($group_offset);
#    my $i_proc_offset = Math::BigInt->new($proc_offset);
#    my $i_offset = Math::BigInt->new($offset);


    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        $targetObj->log($target,
            "Processing MCBIST child: $child Type: $child_type");

        if ($child_type eq "NA" || $child_type eq "FSI")
        {
            $child_type = $targetObj->getMrwType($child);
        }
        if ($child_type eq "MCS")
        {
            processMcs($targetObj, $child, $target, $group, $proc);
        }
    }

#@TODO RTC:163874 -- maybe needed for centaur support
#    my $mcs = $targetObj->getAttribute($target, "MCS_NUM");
#    #Note: Hex convert method avoids overflow on 32bit machines
#    my $mcsStr=sprintf("0x%016s",substr((
#         $i_base+$i_node_offset*$group+
#         $i_proc_offset*$proc+$i_offset*$mcs)->as_hex(),2));
#    $targetObj->setAttribute($target, "IBSCOM_MCS_BASE_ADDR", $mcsStr);
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
            #No connections mean, we need to set the OBUS_SLOT_INDEX to -1
            #to mark that they are not connected
            $targetObj->log($target,"no bus connection found");
            foreach my $obrick (@{ $targetObj->getTargetChildren($target) })
            {
                $targetObj->setAttribute($obrick, "OBUS_SLOT_INDEX", -1);
            }
        }
        else
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
#--------------------------------------------------
## XBUS
##
## Finds XBUS connections and creates PEER TARGET attributes

sub processXbus
{
    my $targetObj = shift;
    my $target    = shift;

    my $found_xbus = 0;

    my $xbus_child_conn = $targetObj->getFirstConnectionDestination($target);
    if ($xbus_child_conn ne "")
    {
        ## set attributes for both directions
        $targetObj->setAttribute($xbus_child_conn, "PEER_TARGET",
        $targetObj->getAttribute($target, "PHYS_PATH"));
        $targetObj->setAttribute($target, "PEER_TARGET",
        $targetObj->getAttribute($xbus_child_conn, "PHYS_PATH"));

        $targetObj->setAttribute($xbus_child_conn, "PEER_TARGET",
        $targetObj->getAttribute($target, "PHYS_PATH"));
        $targetObj->setAttribute($target, "PEER_TARGET",
        $targetObj->getAttribute($xbus_child_conn, "PHYS_PATH"));

        $found_xbus = 1;
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

    my $found_abus = 0;
    if ($targetObj->isBadAttribute($target, "PEER_PATH"))
    {
        $targetObj->setAttribute($target, "PEER_PATH","physical:na");
    }
    $targetObj->setAttribute($target, "EI_BUS_TX_LANE_INVERT","0");
    if ($targetObj->isBadAttribute($target, "EI_BUS_TX_MSBSWAP"))
    {
        $targetObj->setAttribute($target, "EI_BUS_TX_MSBSWAP","0");
    }
    my $abus_child_conn = $targetObj->getFirstConnectionDestination($target);
    if ($abus_child_conn ne "")
    {
        ## set attributes for both directions
        my $aff1 = $targetObj->getAttribute($target, "AFFINITY_PATH");
        my $aff2 = $targetObj->getAttribute($abus_child_conn, "AFFINITY_PATH");

        $targetObj->setAttribute($abus_child_conn, "PEER_TARGET",
            $targetObj->getAttribute($target, "PHYS_PATH"));
        $targetObj->setAttribute($target, "PEER_TARGET",
            $targetObj->getAttribute($abus_child_conn, "PHYS_PATH"));

        $targetObj->setAttribute($abus_child_conn, "PEER_PATH",
            $targetObj->getAttribute($target, "PHYS_PATH"));
        $targetObj->setAttribute($target, "PEER_PATH",
            $targetObj->getAttribute($abus_child_conn, "PHYS_PATH"));

        # copy Abus attributes to proc
        my $abus = $targetObj->getFirstConnectionBus($target);
        $targetObj->setAttribute($target, "EI_BUS_TX_MSBSWAP",
            $abus->{bus_attribute}->{SOURCE_TX_MSBSWAP}->{default});
        $targetObj->setAttribute($abus_child_conn, "EI_BUS_TX_MSBSWAP",
            $abus->{bus_attribute}->{DEST_TX_MSBSWAP}->{default});
        $found_abus = 1;
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
        my $flip_port         = 0;
        my $proc_path = $targetObj->getAttribute($parentTarget,"PHYS_PATH");
        my $fsi_child_target = $targetObj->getTargetParent($fsi_child_conn);
        $targetObj->setFsiAttributes($fsi_child_target,
                    $type,$cmfsi,$proc_path,$fsi_port,$flip_port);
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

                    # Set the lane swap for the PEC. If we find more swaps as
                    # we process the other PCI busses then we will overwrite
                    # the overall swap value with the newly computed one.
                    $targetObj->setAttribute($target,
                        "PEC_PCIE_IOP_SWAP_NON_BIFURCATED", $pec_iop_swap);
                    $targetObj->setAttribute($target,
                        "PROC_PCIE_IOP_SWAP", $pec_iop_swap);

                    $lane_mask[$lane_group][0] =
                        $targetObj->getAttribute
                            ($phb_config_child, "PCIE_LANE_MASK");

                    my $lane_mask_attr = sprintf("%s,%s,%s,%s",
                        $lane_mask[0][0], $lane_mask[1][0],
                        $lane_mask[2][0], $lane_mask[3][0]);

                    $targetObj->setAttribute($target, "PROC_PCIE_LANE_MASK",
                        $lane_mask_attr);
                    $targetObj->setAttribute($target,
                        "PEC_PCIE_LANE_MASK_NON_BIFURCATED", $lane_mask_attr);

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
    if ($parentTarget eq $targetObj->getMasterProc())
    {
        $master_capable=1;
    }
    $targetObj->setAttribute($target,"OCC_MASTER_CAPABLE",$master_capable);
}

sub processMembufVpdAssociation
{
    my $targetObj = shift;
    my $target    = shift;
    my $vpds=$targetObj->findConnections($target,"I2C","VPD");
    if ($vpds ne "" ) {
        my $vpd = $vpds->{CONN}->[0];
        my $membuf_assocs=$targetObj->findConnections($vpd->{DEST_PARENT},
                          "LOGICAL_ASSOCIATION","MEMBUF");

        if ($membuf_assocs ne "") {
            foreach my $membuf_assoc (@{$membuf_assocs->{CONN}}) {
                my $membuf_target = $membuf_assoc->{DEST_PARENT};
                setEepromAttributes($targetObj,
                       "EEPROM_VPD_PRIMARY_INFO",$membuf_target,$vpd);
                my $index = $targetObj->getBusAttribute($membuf_assoc->{SOURCE},
                                $membuf_assoc->{BUS_NUM}, "ISDIMM_MBVPD_INDEX");
                $targetObj->setAttribute(
                            $membuf_target,"ISDIMM_MBVPD_INDEX",$index);
                $targetObj->setAttribute($membuf_target,
                            "VPD_REC_NUM",$targetObj->{vpd_num});
            }
        }
        my $group_assocs=$targetObj->findConnections($vpd->{DEST_PARENT},
                          "LOGICAL_ASSOCIATION","CARD");

        if ($group_assocs ne "") {
            foreach my $group_assoc (@{$group_assocs->{CONN}}) {
                my $mb_target = $group_assoc->{DEST_PARENT};
                my $group_target = $targetObj->getTargetParent($mb_target);
                $targetObj->setAttribute($group_target,
                            "VPD_REC_NUM",$targetObj->{vpd_num});
            }
        }
        $targetObj->{vpd_num}++;
    }
}

#--------------------------------------------------
## MEMBUF
##
## Finds I2C connections to DIMM and creates EEPROM attributes
## FYI:  I had to handle DMI busses in framework because they
## define affinity path
#@TODO RTC:163874 -- centaur support
sub processMembuf
{
    my $targetObj = shift;
    my $target    = shift;
    if ($targetObj->isBadAttribute($target, "PHYS_PATH", ""))
    {
        ##dmi is probably not connected.  will get caught in error checking
        return;
    }

    processMembufVpdAssociation($targetObj,$target);

    ## find port mapping
    my %dimm_portmap;
    foreach my $child (@{$targetObj->getTargetChildren($target)})
    {
         if ($targetObj->getType($child) eq "MBA")
         {
             my $mba_num = $targetObj->getAttribute($child,"MBA_NUM");
             my $dimms=$targetObj->findConnections($child,"DDR3","");
             if ($dimms ne "")
             {
                 foreach my $dimm (@{$dimms->{CONN}})
                 {
                       my $port_num = $targetObj->getAttribute(
                                     $dimm->{SOURCE},"MBA_PORT");
                       my $dimm_num = $targetObj->getAttribute(
                                     $dimm->{SOURCE},"MBA_DIMM");

                       my $map = oct("0b".$mba_num.$port_num.$dimm_num);
                       $dimm_portmap{$dimm->{DEST_PARENT}} = $map;
                 }
             }
         }
    }


    ## Process MEMBUF to DIMM I2C connections
    my @addr_map=('0','0','0','0','0','0','0','0');
    my $dimms=$targetObj->findConnections($target,"I2C","SPD");
    if ($dimms ne "") {
        foreach my $dimm (@{$dimms->{CONN}}) {
            my $dimm_target = $targetObj->getTargetParent($dimm->{DEST_PARENT});
            setEepromAttributes($targetObj,
                       "EEPROM_VPD_PRIMARY_INFO",$dimm_target,
                       $dimm);
            my $field=getI2cMapField($targetObj,$dimm_target,$dimm);
            my $map = $dimm_portmap{$dimm_target};
            if ($map eq "") {
                print "ERROR: $dimm_target doesn't map to a dimm/port\n";
                $targetObj->myExit(3);
            }
            $addr_map[$map] = $field;
        }
    }
    $targetObj->setAttribute($target,
            "MRW_MEM_SENSOR_CACHE_ADDR_MAP","0x".join("",@addr_map));

    ## Update bus speeds
    #@TODO RTC:163874 -- centaur support
    #processI2cSpeeds($targetObj,$target);

    ## Do MBA port mapping
    my %mba_port_map;
    my $ddrs=$targetObj->findConnections($target,"DDR3","DIMM");
    if ($ddrs ne "") {
        my %portmap;
        foreach my $ddr (@{$ddrs->{CONN}}) {
            my $mba=$ddr->{SOURCE};
            my $dimm=$ddr->{DEST_PARENT};
            my ($dimmnum,$port)=split(//,sprintf("%02b\n",$portmap{$mba}));
            $targetObj->setAttribute($dimm, "MBA_DIMM",$dimmnum);
            $targetObj->setAttribute($dimm, "MBA_PORT",$port);
            $portmap{$mba}++;

            ## Copy connector attributes
            my $dimmconn=$targetObj->getTargetParent($dimm);
        }
    }
}

sub getI2cMapField
{
    my $targetObj = shift;
    my $target = shift;
    my $conn_target = shift;


    my $port = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_PORT");
    my $engine = $targetObj->getAttribute($conn_target->{SOURCE}, "I2C_ENGINE");
    my $addr = $targetObj->getBusAttribute($conn_target->{SOURCE},
            $conn_target->{BUS_NUM}, "I2C_ADDRESS");

    my $bits=sprintf("%08b",hex($addr));
    my $field=sprintf("%d%3s",oct($port),substr($bits,4,3));
    my $hexfield = sprintf("%X",oct("0b$field"));
    return $hexfield;
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

    my $path = $targetObj->getAttribute($conn_target->{SOURCE_PARENT},
               "PHYS_PATH");
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
## ERROR checking
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
        'EI_BUS_TX_MSBSWAP' =>
          'DMI connection is missing to this membuf from processor',
        'PHYS_PATH' =>'DMI connection is missing to this membuf from processor',
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
        ## note: DMI is checked on membuf side so don't need to check that here
        ## this checks if at least 1 abus is connected
        my $found_abus = 0;
        my $abus_error = "";
        foreach my $child (@{ $targetObj->getTargetChildren($target) })
        {
            my $child_type = $targetObj->getBusType($child);
            if ($child_type eq "ABUS" || $child_type eq "XBUS")
            {
                if ($targetObj->getMasterProc() ne $target)
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

sub printUsage
{
    print "
processMrwl.pl -x [XML filename] [OPTIONS]
Options:
        -f = force output file creation even when errors
        -d = debug mode
        -s [SDR XML file] = import SDRs
        -r = create report and save to [system_name].rpt
        -v = version
";
    exit(1);
}
