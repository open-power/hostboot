#! /usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/genHDATstructures.pl $
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
use Targets;
use Getopt::Long;
use File::Basename;
use Class::Struct;
use Carp;

    struct(EntryHeader_t  => [
        offsetToArray      => '$',  #4byte
        numberOfEntries    => '$',  #4byte
        allottedEntrySize  => '$',  #4byte
        actualEntrySize    => '$',  #4byte
    ]);

my %EntryHeaderPackFunctionsMap = (
       "offsetToArray" , \&pack4byte,
       "numberOfEntries" , \&pack4byte,
       "allottedEntrySize" , \&pack4byte,
       "actualEntrySize" , \&pack4byte,
  );

    struct(smpLinkEntry_t  => [
       source              => '$',
       destination         => '$',
       linkEntryId         => '$',  #4byte
       linkUsage           => '$',  #4byte
       brickID             => '$',  #4byte
       laneMask            => '$',  #4byte
       slotMapEntryId      => '$',  #2byte
       sideBandSignalsSlotMapEntryId => '$', #2byte
       nvlinkPortSLCAIndex  => '$', #2byte
       reserved1            => '$', #2byte
       nvlinkI2cEntryId     => '$', #4byte
       nvlinkCablePresDetectI2cId  => '$', #4byte
       nvlinkCableMicroResetI2cId  => '$', #4byte
       smpLinkSpeed                => '$', #1byte
       occStatusRegisterBit        => '$', #1byte
       gpuSLCAIndex                => '$', #2byte
       obusConfig           => '$'
    ]);

my %SMPLinkEntryPackFunctionsMap = (
       "linkEntryId" , \&pack4byte,
       "linkUsage",    \&pack4byte,
       "brickID",      \&pack4byte,
       "laneMask",     \&pack4byte,
       "slotMapEntryId", \&pack2byte,
       "sideBandSignalsSlotMapEntryId", \&pack2byte,
       "nvlinkPortSLCAIndex", \&pack2byte,
       "reserved1",           \&pack2byte,
       "nvlinkI2cEntryId",    \&pack4byte,
       "nvlinkCablePresDetectI2cId", \&pack4byte,
       "nvlinkCableMicroResetI2cId", \&pack4byte,
       "smpLinkSpeed",      \&pack1byte,
       "occStatusRegisterBit",   \&pack1byte,
       "gpuSLCAIndex",      \&pack2byte,
  );

    struct(slotMapEntry_t  => [
        source             => '$',
        destination        => '$',
        myEntryId          => '$',  #2byte
        parentEntryId      => '$',  #2byte
        phbID              => '$',  #1byte
        myEntryType        => '$',  #1byte
        laneSwapConfig     => '$',  #1byte
        reserved1          => '$',  #1byte
        laneMask           => '$',  #2byte
        laneReversal       => '$',  #2byte
        slcaIndex          => '$',  #2byte
        slotIndex          => '$',  #2byte
        entryFeatures      => '$',  #4byte
        switchStationID    => '$',  #1byte
        switchPortNr       => '$',  #1byte
        reserved2          => '$',  #2byte
        vendorID           => '$',  #4byte
        deviceID           => '$',  #4byte
        subsystemVendorID  => '$',  #4byte
        subsystemDeviceID  => '$',  #4byte
        slotName           => '$',  #8byte null terminated string
      ]);

my %SlotMapEntryPackFunctionsMap = (
        "myEntryId",            \&pack2byte,
        "parentEntryId",        \&pack2byte,
        "phbID",                \&pack1byte,
        "myEntryType",          \&pack1byte,
        "laneSwapConfig",       \&pack1byte,
        "reserved1",            \&pack1byte,
        "laneMask",             \&pack2byte,
        "laneReversal",         \&pack2byte,
        "slcaIndex",            \&pack2byte,
        "slotIndex",            \&pack2byte,
        "entryFeatures",        \&pack4byte,
        "switchStationID",      \&pack1byte,
        "switchPortNr",         \&pack1byte,
        "reserved2",            \&pack2byte,
        "vendorID",             \&pack4byte,
        "deviceID",             \&pack4byte,
        "subsystemVendorID",    \&pack4byte,
        "subsystemDeviceID",    \&pack4byte,
        "slotName",             \&packString,
   );

    struct(slotEntryDetails_t   => [
        slotMapEntryID     => '$',  #2byte
        mgcLoadSource      => '$',  #1byte
        hddwOrder          => '$',  #1byte
        mmioSize32bitMB    => '$',  #2byte
        mmioSize64bitGB    => '$',  #2byte
        dmaSize32bitGB     => '$',  #2byte
        dmaSize64bitGB     => '$',  #2byte
        slotPowerCtlType   => '$',  #1byte
        presenceCtlType    => '$',  #1byte
        perstCtlType       => '$',  #1byte
        perstCtlGPIOPin    => '$',  #1byte
        slotMaxPowerWatts  => '$',  #2byte
        slotCapabilities   => '$',  #4byte
        totalMSISupport    => '$',  #2byte
        slotPowerI2CId     => '$',  #4byte
        slotPgoodI2CId     => '$',  #4byte
        slotPresenceI2CId  => '$',  #4byte
        slotEnableI2CId    => '$',  #4byte
        slotMexFPGAI2CId   => '$',  #4byte
      ]);

my %SlotEntryDetailsPackFunctionsMap = (
        "slotMapEntryID",     \&pack2byte,
        "mgcLoadSource",      \&pack1byte,
        "hddwOrder",          \&pack1byte,
        "mmioSize32bitMB",    \&pack2byte,
        "mmioSize64bitGB",    \&pack2byte,
        "dmaSize32bitGB",     \&pack2byte,
        "dmaSize64bitGB",     \&pack2byte,
        "slotPowerCtlType",   \&pack1byte,
        "presenceCtlType",    \&pack1byte,
        "perstCtlType",       \&pack1byte,
        "perstCtlGPIOPin",    \&pack1byte,
        "slotMaxPowerWatts",  \&pack2byte,
        "slotCapabilities",   \&pack4byte,
        "totalMSISupport",    \&pack2byte,
        "slotPowerI2CId",     \&pack4byte,
        "slotPgoodI2CId",     \&pack4byte,
        "slotPresenceI2CId",  \&pack4byte,
        "slotEnableI2CId",    \&pack4byte,
        "slotMexFPGAI2CId",   \&pack4byte,
     );

    struct(i2cdeviceentrystructure  => [
        source             => '$',
        destination        => '$',
        i2cEngine          => '$',  #1byte
        i2cPort            => '$',  #1byte
        i2cSpeed           => '$',  #2byte
        slaveDeviceType    => '$',  #1byte
        slaveDeviceAddress => '$',  #1byte
        slaveDevicePort    => '$',  #1byte
        reserved1          => '$',  #1byte
        entryPurpose       => '$',  #4byte
        hosti2cLinkId      => '$',  #4byte
        slcaIndex          => '$',  #2byte
        entryName          => '$',  #64byte
      ]);

my %i2centrystructpackfuncsmap = (
     "i2cEngine"   , \&pack1byte,
     "i2cPort"     , \&pack1byte,
     "i2cSpeed"    , \&pack2byte,
     "slaveDeviceType" , \&pack1byte,
     "slaveDeviceAddress", \&pack1byte,
     "slaveDevicePort"   , \&pack1byte,
     "reserved1"         , \&pack1byte,
     "entryPurpose"      , \&pack4byte,
     "hosti2cLinkId",      \&pack4byte,
     "slcaIndex",          \&pack2byte,
     "entryName",          \&packString,
  );

use constant {
      i2centryversion => 2,
   };

use constant {
      sd_pca9551 => 1,
      sd_at24c128 => 2,
      sd_nuvotontpm => 3,
      sd_mexfpga => 4,
      sd_ucx90 => 5,
      sd_pca9552 => 6,
      sd_pca9553 => 7,
      sd_pca9554 => 8,
      sd_pca9555 => 9,
      sd_smp_cable => 10,
      sd_at24c256 => 11,
      sd_thermalSensor => 12,
      sd_at24c04  =>13,
      sd_at24c512 => 14,
      sd_at24c32  => 15,
      sd_at24c64  => 16,
      sd_at24c16  => 17,
      sd_nvdiaGpu      => 18,
      sd_lpc11u35 => 19,
      sd_unknown  => 0xFF,
   };

use constant {
      reserved_default       => 0x00,
      invalid_1byte          => 0xFF,
      invalid_2byte          => 0xFFFF,
      invalid_4byte          => 0xFFFFFFFF,
   };

use constant {
      linkspeed_2000gpps          => 0,
      linkspeed_2500gbps          => 1,
      linkspeed_2578gbps          => 2,
   };

use constant {
      linkusage_smp             => 0,
      linkusage_gpu_ocapi       => 1,
      linkusage_interposercard  => 2,
      linkusage_extlink         => 3,
      linkusage_gpu2gpu         => 4,
   };

use constant {
      p_cableccardpresence => 1,
      p_pciepgood          => 2,
      p_pciecontrol        => 3,
      p_tpm                => 4,
      p_mvpd               => 5,
      p_dimmspd            => 6,
      p_procmodulevpd      => 7,
      p_sbeseeprom         => 8,
      p_bpvpd              => 9,
      p_cabletopcheck      => 10,
      p_cablemicroreset    => 11,
      p_nvlinkcablei2c     => 12,
      p_securebootwinopen  => 13,
      p_securebootphyspresence => 14,
      p_mexfpga            => 15,
      p_thermalSensor      => 16,
      p_cableccardhosti2cenable => 17,
      p_gpuconfig          => 18,
      p_unknown            => 0xFF,
   };

use constant {
      et_phbRootComplex       => 0,
      et_switchUpLeg          => 1,
      et_switchDownLeg        => 2,
      et_builtInDevice        => 3,
   };

use constant {
      slotPowerControlType_None => 0,
      slotPowerControlType_I2C  => 1,
      slotPresenceControlType_None => 0,
      slotPresenceControlType_PHB  => 1,
      slotPresenceControlType_I2C  => 2,
   };

my $VERSION = "1.0.0";

my $force          = 0;
my $serverwiz_file = "";
my $version        = 0;
my $debug          = 0;
my $report         = 0;
my $myslotMapEntryId = 0;
my $cfgBigEndian = 1;
my $prefixSystemName = 0;
my %hostconnectionslinkmap;


GetOptions(
    "f"   => \$force,             # numeric
    "x=s" => \$serverwiz_file,    # string
    "d"   => \$debug,
    "v"   => \$version,
    "r"   => \$report,
    "n"   => \$prefixSystemName,
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

#--------------------------------------------------
##Find Processor targets and invoke i2c and slot map construction
foreach my $target (sort keys %{ $targetObj->getAllTargets() })
{
    my $type = $targetObj->getType($target);
    if ($type eq "PROC")
    {
        processProcessor($targetObj, $target);
    }
}
$targetObj->writeReportFile();
#--------------------------------------------------
## Processing subroutines

sub printHostI2CLinkMap
{
    my $targetObj = shift;
    $targetObj->writeReport("\nHost Link Map \n");
    foreach my $key1 (keys %hostconnectionslinkmap)
    {
       foreach my $key2 (keys %{$hostconnectionslinkmap{$key1}})
       {
         $targetObj->writeReport("$key1 - $key2 =  $hostconnectionslinkmap{$key1}{$key2}\n");
       }
    }
    $targetObj->writeReport("---------------------------------------\n");
}

#--------------------------------------------------
## Processor
##

sub processProcessor
{
    my $targetObj = shift;
    my $target    = shift;

    my @slotmaparray;
    my @slotentrydetailsarray;
    my @smplinkarray;
    my @hostproci2centries;
    my @hostmembufi2centries;
    my $hosti2centryid = 0;

    #########################
    ## In serverwiz, processor instances are not unique
    ## because plugged into socket
    ## so processor instance unique attributes are socket level.
    ## The grandparent is guaranteed to be socket.

    $targetObj->writeReport("Processing PROC $target\n");

    my $parent_target =
             $targetObj->getTargetParent($targetObj->getTargetParent($target));
    my $proc_id = $targetObj->getAttribute($parent_target, "POSITION");
    my $node_id = getParentNodeId($targetObj,$parent_target);
    my $hosti2centryid = ($node_id << 24) | ($proc_id << 16);

    @hostproci2centries = processI2C($targetObj, $target,$hosti2centryid);

    my $i2cMapFileName = "i2cmapproc".$proc_id;
    my $numOfEntries = sendi2cdatatofile($i2cMapFileName, @hostproci2centries);

    $hosti2centryid +=  $numOfEntries ;

    #Looking for MEMBUFs connected to Processor to generate I2C Map
    my $dmiconnections = $targetObj->findConnections($target,"DMI","");
    if ($dmiconnections ne "")
    {
      foreach my $dmi (@{$dmiconnections->{CONN}})
      {
        # Found a MEMBUF and calling processI2C to construct I2C MAP
        $targetObj->writeReport("Processing MEMBUF $dmi->{DEST_PARENT}\n");
        @hostmembufi2centries = processI2C($targetObj, $dmi->{DEST_PARENT},$hosti2centryid);

        my $membuf_id = $targetObj->getAttribute($dmi->{DEST_PARENT}, "POSITION");
        my $memcard_id = getMemoryRiserCardId($targetObj,$dmi->{DEST_PARENT});
        if($memcard_id eq -1)
        {
          $i2cMapFileName = "i2cmapmembuf_p".$proc_id."_m".$membuf_id;
        }
        else
        {
          $i2cMapFileName = "i2cmapmembuf_p".$proc_id."_c".$memcard_id."_m".$membuf_id;
        }
        my $numOfEntries  = sendi2cdatatofile($i2cMapFileName, @hostmembufi2centries);

        $hosti2centryid += $numOfEntries;
      }
    }

    printHostI2CLinkMap($targetObj);


    foreach my $child (@{ $targetObj->getTargetChildren($target) })
    {
        my $child_type = $targetObj->getType($child);

        if ($child_type eq "PEC")
        {
            $targetObj->writeReport("\nProcessing PEC: $child\n");
            my ($s1array, $s2array) = processPec($targetObj, $child, $target);
            push (@slotmaparray, @$s1array);
            push (@slotentrydetailsarray, @$s2array);
        }

    }

    sendpecdatatofile($proc_id, \@slotmaparray, \@slotentrydetailsarray);

    processObus($targetObj, $target);
}

#--------------------------------------------------
## getMemoryRiserCardId
##
sub getMemoryRiserCardId
{
  my $targetObj     = shift;
  my $target        = shift;
  my $parent_target;
  my $memorycard_id = -1;
  my $targettype = $targetObj->getTargetType($target);
  my $parent_target = $target;
  while ($targettype ne "connector-card-generic" && $parent_target ne "")
  {
     $parent_target = $targetObj->getTargetParent($parent_target);
     $targettype = $targetObj->getTargetType($parent_target);
  }
  if($parent_target ne "")
  {
    $memorycard_id = $targetObj->getAttribute($parent_target, "POSITION");
  }
  return $memorycard_id;
}

#--------------------------------------------------
## addSlotEntryDetails
##

sub addSlotEntryDetails
{
   my $targetObj     = shift;
   my $pcieBus = shift;
   my $phb_config_child = $pcieBus->{SOURCE};
   my $slotentrydetails = new slotEntryDetails_t;

   my $parent_target =
             $targetObj->getTargetParent(
               $targetObj->getTargetParent($pcieBus->{DEST}));

   # Set these attributes only if we are in a pcie
   # slot connection
   $slotentrydetails->hddwOrder($targetObj->getAttribute
                                  ($parent_target, "HDDW_ORDER"));

   $slotentrydetails->mgcLoadSource($targetObj->getAttribute
                                  ($phb_config_child, "MGC_LOAD_SOURCE"));

   $slotentrydetails->mmioSize32bitMB($targetObj->getAttribute
                                  ($parent_target, "32BIT_MMIO_SIZE"));
   $slotentrydetails->mmioSize64bitGB($targetObj->getAttribute
                                  ($parent_target, "64BIT_MMIO_SIZE"));
   $slotentrydetails->dmaSize32bitGB($targetObj->getAttribute
                                  ($parent_target, "32BIT_DMA_SIZE"));
   $slotentrydetails->dmaSize64bitGB($targetObj->getAttribute
                                  ($parent_target, "64BIT_DMA_SIZE"));

   #TODO PERST signals are not modelled yet
   $slotentrydetails->perstCtlType(0);
   $slotentrydetails->perstCtlGPIOPin(0);

   if (!($targetObj->isBadAttribute
                             ($parent_target,"MAX_POWER")))
    {
        $slotentrydetails->slotMaxPowerWatts($targetObj->getAttribute
                             ($parent_target, "MAX_POWER"));
    }
    else
    {
        $targetObj->writeReport("ERROR::MAX_POWER attribute missing for $parent_target\n");
    }

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

   $slotentrydetails->slotCapabilities(hex($capabilites));

   #TODO: MSI attributed missing in MRW
   $slotentrydetails->totalMSISupport(0);

   #TODO: Currently Presence and Power Control are not modelled
   $slotentrydetails->slotPowerCtlType(slotPowerControlType_None);
   $slotentrydetails->presenceCtlType(slotPresenceControlType_None);

   if($hostconnectionslinkmap{$pcieBus->{DEST_PARENT}}{"ENABLE"} ne "")
   {
     $slotentrydetails->slotPowerI2CId($hostconnectionslinkmap{$pcieBus->{DEST_PARENT}}{ENABLE});
     $slotentrydetails->slotPowerCtlType(slotPowerControlType_I2C);
   }
   else
   {
     $targetObj->writeReport("ERROR::Power Control I2C connection missing for $pcieBus->{DEST_PARENT}\n");
   }

   my $slotname = $targetObj->getAttribute(
                              $targetObj->getTargetParent($pcieBus->{DEST_PARENT}),"SLOT_NAME");
   if($hostconnectionslinkmap{$slotname}{"PRESENCE"} ne "")
   {
     $slotentrydetails->slotPresenceI2CId($hostconnectionslinkmap{$slotname}{PRESENCE});
     $slotentrydetails->presenceCtlType(slotPresenceControlType_I2C);
   }
   else
   {
     $targetObj->writeReport("ERROR::PRESENCE GPIO connection missing for ", $slotname,"\n");
   }

   if($hostconnectionslinkmap{$pcieBus->{DEST_PARENT}}{"PGOOD"} ne "")
   {
     $slotentrydetails->slotPgoodI2CId($hostconnectionslinkmap{$pcieBus->{DEST_PARENT}}{PGOOD});
   }
   else
   {
     $targetObj->writeReport("ERROR::PGGOD GPIO connection missing for $pcieBus->{DEST_PARENT}\n");
   }

   if($hostconnectionslinkmap{$slotname}{"HOSTI2CENABLE"} ne "")
   {
     $slotentrydetails->slotEnableI2CId($hostconnectionslinkmap{$slotname}{HOSTI2CENABLE});
   }
   else
   {
     $targetObj->writeReport("ERROR::Host I2C Enable connection missing for $slotname\n");
   }

   $slotentrydetails->slotMexFPGAI2CId(0);

   return $slotentrydetails
}

#--------------------------------------------------
## addVendorDeviceID
##
sub addVendorDeviceID
{
 my $target = shift;
 my $targetObj = shift;
 my $slotMapEntry = shift;

 if(!($targetObj->isBadAttribute($target, "VENDOR_ID")))
 {
   $slotMapEntry->vendorID($targetObj->getAttribute
                            ($target, "VENDOR_ID"));
 }
 else
 {
   $targetObj->writeReport("ERROR::Vendor ID not found for $target\n");
 }
 if(!($targetObj->isBadAttribute($target, "DEVICE_ID")))
 {
   $slotMapEntry->deviceID($targetObj->getAttribute
                            ($target, "DEVICE_ID"));
 }
 else
 {
   $targetObj->writeReport("ERROR::Device ID not found for $target\n");
 }
 if(!($targetObj->isBadAttribute($target, "SUBSYSTEM_VENDOR_ID")))
 {
   $slotMapEntry->subsystemVendorID($targetObj->getAttribute
                            ($target, "SUBSYSTEM_VENDOR_ID"));
 }
 else
 {
   $targetObj->writeReport("ERROR::Subsystem Vendor ID not found for $target\n");
 }
 if(!($targetObj->isBadAttribute($target, "SUBSYSTEM_DEVICE_ID")))
 {
   $slotMapEntry->subsystemDeviceID($targetObj->getAttribute
                            ($target, "SUBSYSTEM_DEVICE_ID"));
 }
 else
 {
   $targetObj->writeReport("ERROR::Subsystem Device ID not found for $target\n");
 }
 return $slotMapEntry;
}

#--------------------------------------------------
## addRootComplex
##
sub addRootComplex
{
  my $target = shift;
  my $targetObj = shift;
  my $pcieBus = shift;
  my $phb_config_child = $pcieBus->{SOURCE};

  my $slotMapEntryRootComplex = new slotMapEntry_t;
  my $pec_num = $targetObj->getAttribute
                      ($target, "CHIP_UNIT");

  my $pec_iop_swap = 0;

  $slotMapEntryRootComplex->source( $pcieBus->{SOURCE});
  $slotMapEntryRootComplex->destination( $pcieBus->{DEST});

  $slotMapEntryRootComplex->phbID( $targetObj->getAttribute
                                      ($phb_config_child, "PHB_NUM"));
  $myslotMapEntryId++;
  $slotMapEntryRootComplex->myEntryId($myslotMapEntryId);
  $slotMapEntryRootComplex->parentEntryId(0);
  $slotMapEntryRootComplex->myEntryType(et_phbRootComplex);
  $slotMapEntryRootComplex->reserved1(0);
  $slotMapEntryRootComplex->reserved2(0);
  $slotMapEntryRootComplex->entryFeatures(0);
  $slotMapEntryRootComplex->slcaIndex(0);

  my $phb_num = $targetObj->getAttribute
                        ($phb_config_child, "PHB_NUM");

  my $pcie_lane_mask = $targetObj->getAttribute
                        ($phb_config_child,"PCIE_LANE_MASK");
  $slotMapEntryRootComplex->laneMask(unpack('S', pack('S', hex($pcie_lane_mask))));

  # Lane Reversal = swapped lanes
  my $lane_swap = $targetObj->getBusAttribute
                            ($phb_config_child, 0, "LANE_REVERSAL");

  # Lane swap comes out as "00" or "01" - so add 0 so it
  # converts to an integer to evaluate.
  my $lane_swap_int = $lane_swap + 0;
  if ($lane_swap_int)
  {
    $slotMapEntryRootComplex->laneSwapConfig(0x01);
    my $pcie_num_lanes = $targetObj->getAttribute
                                    ($phb_config_child,"PCIE_NUM_LANES");
    if($pcie_num_lanes eq 16 || $pcie_num_lanes eq 8)
    {
       $slotMapEntryRootComplex->laneReversal(0x1111);
    }
    elsif ($pcie_num_lanes eq 4)
    {
       $slotMapEntryRootComplex->laneReversal(0x01);
    }
    else
    {
       die "Invalid number of lanes $pcie_num_lanes for target $target";
    }
  }
  else
  {
    $slotMapEntryRootComplex->laneReversal(0x00);
    $slotMapEntryRootComplex->laneSwapConfig(0x00);
  }

  return $slotMapEntryRootComplex;
}

#--------------------------------------------------
## addBuiltInDeviceSlotMap
##
sub addBuiltInDeviceSlotMap
{
   my $targetObj = shift;
   my $desttarget = shift;

   my $slotMapEntryEndDevice = new slotMapEntry_t;
   $slotMapEntryEndDevice->source($desttarget->{SOURCE});
   $slotMapEntryEndDevice->destination($desttarget->{DEST});
   #add a slotMapEntryObj for type 3
   # Destination is a built in device. Set entry
   # type that corresponds to built in device
   $slotMapEntryEndDevice->myEntryType(et_builtInDevice);
   $slotMapEntryEndDevice->entryFeatures(0x00);
   $slotMapEntryEndDevice->reserved1(0x00);
   $slotMapEntryEndDevice->slcaIndex(0x00);
   $slotMapEntryEndDevice->slotIndex(0x00);
   $slotMapEntryEndDevice->laneSwapConfig(0x00);
   $slotMapEntryEndDevice->laneReversal(0x00);
   $slotMapEntryEndDevice->laneMask(0x00);
   $slotMapEntryEndDevice->switchStationID(0x00);
   $slotMapEntryEndDevice->switchPortNr(0x00);
   my $parent_target = $targetObj->getTargetParent($desttarget->{DEST_PARENT});
   if (!($targetObj->isBadAttribute
                             ($parent_target,"SLOT_NAME")))
   {
     $slotMapEntryEndDevice->slotName($targetObj->getAttribute($parent_target,"SLOT_NAME"));
   }
   else
   {
     $targetObj->writeReport("ERROR:SLOT_NAME attribute missing for $parent_target\n");
   }
   # Set device and vendor ID from the device
   $slotMapEntryEndDevice = addVendorDeviceID($desttarget->{DEST_PARENT},$targetObj, $slotMapEntryEndDevice);

   return $slotMapEntryEndDevice;
}

#--------------------------------------------------
## addSwitchUpleg
##
sub addSwitchUpleg
{
  my $targetObj = shift;
  my $pcieBus   = shift;
  my $phb_config_child = $pcieBus->{SOURCE};
  my $parentEntryId = shift;
  my @slotmaparray ;
  my @slotentrydetailsarray ;

  use constant {
    SWITCH_SLOT   => 0x01,
    SWITCH_SHARED => 0x02,
  };

  my $slotMapEntryUpleg = new slotMapEntry_t;
  $myslotMapEntryId++;

  $slotMapEntryUpleg->myEntryId($myslotMapEntryId);
  $slotMapEntryUpleg->phbID( $targetObj->getAttribute
                         ($phb_config_child, "PHB_NUM"));
  $slotMapEntryUpleg->parentEntryId($parentEntryId);
  $slotMapEntryUpleg->reserved1(0);
  $slotMapEntryUpleg->reserved2(0);
  $slotMapEntryUpleg->myEntryType(et_switchUpLeg);
  $slotMapEntryUpleg->entryFeatures(0);
  $slotMapEntryUpleg->slcaIndex(0x00);
  $slotMapEntryUpleg->slotIndex(0x00);
  $slotMapEntryUpleg->laneSwapConfig(0x00);
  $slotMapEntryUpleg->laneReversal(0x00);
  $slotMapEntryUpleg->laneMask(0x00);

  # Set Station and Ports which this downleg switch connects
  # to. Only valid for switch downleg
  $slotMapEntryUpleg->switchStationID($targetObj->getAttribute
                                 ($pcieBus->{DEST}, "STATION"));

  $slotMapEntryUpleg->switchPortNr($targetObj->getAttribute
                                 ($pcieBus->{DEST}, "PORT"));
  $slotMapEntryUpleg->source($pcieBus->{SOURCE});
  $slotMapEntryUpleg->destination($pcieBus->{DEST});
  #Find all connections ending up in this switch as upleg connections.
  #If there are more than one, then mark this switch as shared
  my $uplegconnections = $targetObj->findDestConnections($pcieBus->{DEST_PARENT},"PCIE","");
  if(scalar  @{$uplegconnections->{CONN}} > 1)
  {
     $slotMapEntryUpleg->entryFeatures(SWITCH_SHARED);
  }

  # Set device and vendor ID from the device
  $slotMapEntryUpleg = addVendorDeviceID($pcieBus->{DEST_PARENT},$targetObj, $slotMapEntryUpleg);

  push(@slotmaparray, $slotMapEntryUpleg);

  my $virtualswitch;
  foreach my $switch_child (@{ $targetObj->getTargetChildren($pcieBus->{DEST_PARENT}) })
  {
     if ($targetObj->getTargetType($switch_child) eq "Virtual-Switch")
     {
       if($targetObj->getAttribute($switch_child, "Upstream_Port") eq $slotMapEntryUpleg->switchPortNr)
       {
         $virtualswitch = $switch_child;
       }
     }
  }
  # Find Downleg connections connected to this switch
  my $switchdownlegconnections = $targetObj->findConnections($pcieBus->{DEST_PARENT},"PCIE","");
  if ($switchdownlegconnections ne "")
   {
      foreach my $switchdownleg (@{$switchdownlegconnections->{CONN}})
      {
          my $slotMapEntryDownleg = new slotMapEntry_t;
          $slotMapEntryDownleg->source($switchdownleg->{SOURCE});
          $slotMapEntryDownleg->destination($switchdownleg->{DEST});
          $slotMapEntryDownleg->phbID( $targetObj->getAttribute
                         ($phb_config_child, "PHB_NUM"));
          $slotMapEntryDownleg->parentEntryId($slotMapEntryUpleg->myEntryId);
          $slotMapEntryDownleg->myEntryType(et_switchDownLeg);
          $slotMapEntryDownleg->slcaIndex(0x00);
          $slotMapEntryDownleg->slotIndex(0x00);
          $slotMapEntryDownleg->laneSwapConfig(0x00);
          $slotMapEntryDownleg->laneReversal(0x00);
          $slotMapEntryDownleg->laneMask(0x00);
          $slotMapEntryDownleg->slotName(0);

          # Set device and vendor ID from the device
          $slotMapEntryDownleg = addVendorDeviceID($pcieBus->{DEST_PARENT},$targetObj, $slotMapEntryDownleg);

          # Set StationID and Ports which this downleg switch connects
          # to. Only valid for switch downleg
          $slotMapEntryDownleg->switchStationID($targetObj->getAttribute
                                        ($switchdownleg->{SOURCE}, "STATION"));
          $slotMapEntryDownleg->switchPortNr($targetObj->getAttribute
                                         ($switchdownleg->{SOURCE}, "PORT"));

          if($virtualswitch ne "")
          {
            my $found = 0;
            foreach my $virtualport (@{ $targetObj->getTargetChildren($virtualswitch)})
            {
              if($targetObj->getTargetType($virtualport) eq "Virtual-Port")
              {
                if($targetObj->getAttribute($virtualport, "Downstream_Port") eq
                          $targetObj->getAttribute($switchdownleg->{SOURCE}, "PORT"))
                {
                   $found = 1;
                }
              }
            }
            if($found == 0)
            {
               next;
            }
          }
          $myslotMapEntryId++;
          $slotMapEntryDownleg->myEntryId($myslotMapEntryId);

          my $switchdestTargetType = $targetObj->getTargetType
                                              ($switchdownleg->{DEST_PARENT});

          if($switchdestTargetType eq "chip-PEX8725")
          {
               # Found a cascaded switch
               my ($s1array , $s2array) = addSwitchUpleg($targetObj, $switchdownleg, $phb_config_child,
                                  $slotMapEntryDownleg->myEntryId);

               push(@slotmaparray, $slotMapEntryDownleg);
               push(@slotmaparray, @$s1array);
               push(@slotentrydetailsarray, @$s2array);
          }
          elsif (($switchdestTargetType eq "chip-TUSB7340") ||
                            ($switchdestTargetType eq "card-gv100card-card") ||
                            ($switchdestTargetType eq "chip-BCM5719") ||
                            ($switchdestTargetType eq "unit-pingroup-bmc"))
          {
                #Found a built in device connected to switch
#                print "Built in device to switch ",$switchdownleg->{DEST},"nid :",$myslotMapEntryId,"\n";
                my $slotMapEntryEndDevice = addBuiltInDeviceSlotMap($targetObj, $switchdownleg);
                $slotMapEntryEndDevice->source($switchdownleg->{SOURCE});
                $slotMapEntryEndDevice->destination($switchdownleg->{DEST});

                $slotMapEntryEndDevice->phbID( $targetObj->getAttribute
                                                          ($phb_config_child, "PHB_NUM"));
                $myslotMapEntryId++;
                $slotMapEntryEndDevice->myEntryId($myslotMapEntryId);
                $slotMapEntryEndDevice->parentEntryId($slotMapEntryDownleg->myEntryId);

                $hostconnectionslinkmap{$targetObj->getTargetParent($switchdownleg->{DEST_PARENT})}{"SLOTMAPENTRY"}=
                                             $slotMapEntryEndDevice->myEntryId;

                push(@slotmaparray, $slotMapEntryDownleg);
                push(@slotmaparray, $slotMapEntryEndDevice);
            }
           elsif ($switchdestTargetType eq "card-pciecard-card")
            {
                #Found a slot connected to a switch downleg
                my $slotentrydetails = addSlotEntryDetails($targetObj, $switchdownleg);

                $slotentrydetails->slotMapEntryID($slotMapEntryDownleg->myEntryId);
                $slotMapEntryDownleg->entryFeatures(0x01);

                my $parent_target = $targetObj->getTargetParent($switchdownleg->{DEST_PARENT});

                $slotMapEntryDownleg->slotName($targetObj->getAttribute($parent_target,"SLOT_NAME"));
                $slotMapEntryDownleg->slotIndex($targetObj->getAttribute($parent_target,"SLOT_INDEX"));

                $hostconnectionslinkmap{
                               $switchdownleg->{DEST_PARENT}}{SLOTINDEX} =
                                            $slotMapEntryDownleg->slotIndex;

                push(@slotmaparray, $slotMapEntryDownleg);
                push(@slotentrydetailsarray,$slotentrydetails);
             }
          }
      }
      else
      {
         $targetObj->writeReport("No downleg connections for $pcieBus->{DEST_PARENT}\n");
      }
      return (\@slotmaparray, \@slotentrydetailsarray);
}

#--------------------------------------------------
## sendi2cdatatofile
##
sub sendi2cdatatofile
{
    my $fileName = shift;
    my @hostI2CEntries = @{$_[0]};
    my $i2cMapBinaryData;
    my $numOfEntries = 0;
    my $i2cEntryHeader = new EntryHeader_t;
    my $headerBinData;
    my $lengthOfEntry = 0;
    my $systemName = $targetObj->getSystemName();
    my $i2cMapFileName;

    if($prefixSystemName == 1)
    {
      $i2cMapFileName = $systemName."_".$fileName;
    }
    else
    {
      $i2cMapFileName = $fileName;
    }

    open (my $i2cMapFileHandle, ">", $i2cMapFileName)
        or die "Can't open > $i2cMapFileName: $!";
    binmode($i2cMapFileHandle);

    $i2cEntryHeader->offsetToArray(0x14);
    $i2cEntryHeader->numberOfEntries(scalar @hostI2CEntries);
    print "==============================================================\n";
    foreach my $i2c (@hostI2CEntries)
    {
       print "i2c connection from ", $i2c->source, " to ", $i2c->destination, "\n";
       print "i2cEngine: ", $i2c->i2cEngine, " i2cPort: ", $i2c->i2cPort, " i2cSpeed: ", $i2c->i2cSpeed, "\n";
       print "slaveDeviceType: ", $i2c->slaveDeviceType," Address: ",$i2c->slaveDeviceAddress, " Port: ", $i2c->slaveDevicePort, "\n";
       print "reserved1: ",$i2c->reserved1,"\n";
       print "entryPurpose: ",$i2c->entryPurpose,"\n";
       print "hosti2cLinkId: ",$i2c->hosti2cLinkId,"\n";
       print "slcaIndex: ",$i2c->slcaIndex,"\n";
       print " entryName: ",$i2c->entryName,"\n";
       print "-----------------------------------------------------------\n";

       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"i2cEngine"}->($i2c->i2cEngine);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"i2cPort"}->($i2c->i2cPort);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"i2cSpeed"}->($i2c->i2cSpeed);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"slaveDeviceType"}->($i2c->slaveDeviceType);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"slaveDeviceAddress"}->($i2c->slaveDeviceAddress);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"slaveDevicePort"}->($i2c->slaveDevicePort);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"reserved1"}->($i2c->reserved1);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"entryPurpose"}->($i2c->entryPurpose);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"entryPurpose"}->($i2c->hosti2cLinkId);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"slcaIndex"}->($i2c->slcaIndex);
       $i2cMapBinaryData .= $i2centrystructpackfuncsmap{"entryName"}->($i2c->entryName,64);

       $numOfEntries++;
       if($lengthOfEntry eq 0)
       {
         $lengthOfEntry = length $i2cMapBinaryData;
       }
    }

    $i2cEntryHeader->allottedEntrySize($lengthOfEntry);
    $i2cEntryHeader->actualEntrySize($lengthOfEntry);
    $headerBinData .= $EntryHeaderPackFunctionsMap{"offsetToArray"}->($i2cEntryHeader->offsetToArray);
    $headerBinData .= $EntryHeaderPackFunctionsMap{"numberOfEntries"}->($i2cEntryHeader->numberOfEntries);
    $headerBinData .= $EntryHeaderPackFunctionsMap{"allottedEntrySize"}->($i2cEntryHeader->allottedEntrySize);
    $headerBinData .= $EntryHeaderPackFunctionsMap{"actualEntrySize"}->($i2cEntryHeader->actualEntrySize);
    $headerBinData .= pack4byte(i2centryversion);

    print $i2cMapFileHandle "$headerBinData";
    print $i2cMapFileHandle "$i2cMapBinaryData";

    close($i2cMapFileHandle)
      or die "Can't close $i2cMapFileName";

    return $numOfEntries;
}

#--------------------------------------------------
## sendpecdatatofile
##
sub sendpecdatatofile
{
    my $proc_id = shift;
    my @slotMapArray = @{$_[0]};
    my @slotEntryDetailsArray = @{$_[1]};
    my $slotMapBinaryData;
    my $slotEntryBinaryData;
    my $systemName = $targetObj->getSystemName();
    my $slotMapHeaderBinData;
    my $slotEntryHeaderBinData;
    my $slotMapHeader = new EntryHeader_t;
    my $lengthOfEntry = 0;
    my $slotMapFileName;
    my $slotDetailsFileName;

    if($prefixSystemName == 1)
    {
      $slotMapFileName = $systemName."_slotmapproc".$proc_id;
      $slotDetailsFileName = $systemName."_slotdetailsproc".$proc_id;
    }
    else
    {
      $slotMapFileName = "slotmapproc".$proc_id;
      $slotDetailsFileName = "slotdetailsproc".$proc_id;
    }
    open ( my $slotMapBinfh , ">", $slotMapFileName)
       or die "Can't open > $slotMapFileName: $!";
    binmode($slotMapBinfh);

    open ( my $slotEntryBinfh , ">", $slotDetailsFileName)
       or die "Can't open > $slotDetailsFileName: $!";
    binmode($slotEntryBinfh);

   $slotMapHeader->offsetToArray(0x10);
   $slotMapHeader->numberOfEntries(scalar @slotMapArray);
   $targetObj->writeReport("\n--------------------------------\n");
   print "===================================================================\n";
   foreach my $slotMapEntry (@slotMapArray)
   {
        print $slotMapEntry->source, " to ", $slotMapEntry->destination, "\n";
        print "Slot Map Entryid:", $slotMapEntry->myEntryId,"\n";
        print "Slot Map Parent Entryid:", $slotMapEntry->parentEntryId,"\n";
        print "Slot Map PHB Num :", $slotMapEntry->phbID,"\n";
        print "Slot Map Entry Type:", $slotMapEntry->myEntryType,"\n";
        print "Lane Swap Config:", $slotMapEntry->laneSwapConfig,"\n";
        print "Reserved        :", $slotMapEntry->reserved1,"\n";
        print "Lane Mask :", $slotMapEntry->laneMask,"\n";
        print "Lane Reversal :", $slotMapEntry->laneReversal,"\n";
        print "SLCA Index :", $slotMapEntry->slcaIndex,"\n";
        print "Slot Index :", $slotMapEntry->slotIndex,"\n";
        print "Entry Features :", $slotMapEntry->entryFeatures,"\n";
        print "Station ID :", $slotMapEntry->switchStationID,"\n";
        print "Switch Port :", $slotMapEntry->switchPortNr,"\n";
        print "Vendor ID :", $slotMapEntry->vendorID,"\n";
        print "Device ID :", $slotMapEntry->deviceID,"\n";
        print "Subsystem Vendor ID :", $slotMapEntry->subsystemVendorID,"\n";
        print "Subsystem device ID :", $slotMapEntry->subsystemDeviceID,"\n";
        print "Slot Name :", $slotMapEntry->slotName,"\n";
        print "----------------------------------------------------------------\n";

        my $result = sprintf("eid - 0x%x pid - 0x%x phb id - 0x%x type - 0x%x mask - 0x%04x features - 0x%x up id - 0x%x down id - 0x%x vid - 0x%x did - 0x%x sub-vid - 0x%x sub-did - 0x%x name - %s\n",
                                        $slotMapEntry->myEntryId, $slotMapEntry->parentEntryId, $slotMapEntry->phbID,
                                        $slotMapEntry->myEntryType, $slotMapEntry->laneMask, $slotMapEntry->entryFeatures,
                                        $slotMapEntry->switchStationID, $slotMapEntry->switchPortNr, $slotMapEntry->vendorID,
                                        $slotMapEntry->deviceID, $slotMapEntry->subsystemVendorID,$slotMapEntry->subsystemDeviceID,
                                        $slotMapEntry->slotName);
        $targetObj->writeReport($result);

        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"myEntryId"}->($slotMapEntry->myEntryId);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"parentEntryId"}->($slotMapEntry->parentEntryId);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"phbID"}->($slotMapEntry->phbID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"myEntryType"}->($slotMapEntry->myEntryType);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"laneSwapConfig"}->($slotMapEntry->laneSwapConfig);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"reserved1"}->($slotMapEntry->reserved1);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"laneMask"}->($slotMapEntry->laneMask);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"laneReversal"}->($slotMapEntry->laneReversal);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"slcaIndex"}->($slotMapEntry->slcaIndex);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"slotIndex"}->($slotMapEntry->slotIndex);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"entryFeatures"}->($slotMapEntry->entryFeatures);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"switchStationID"}->($slotMapEntry->switchStationID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"switchPortNr"}->($slotMapEntry->switchPortNr);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"reserved2"}->($slotMapEntry->reserved2);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"vendorID"}->($slotMapEntry->vendorID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"deviceID"}->($slotMapEntry->deviceID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"subsystemVendorID"}->($slotMapEntry->subsystemVendorID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"subsystemDeviceID"}->($slotMapEntry->subsystemDeviceID);
        $slotMapBinaryData .= $SlotMapEntryPackFunctionsMap{"slotName"}->($slotMapEntry->slotName,8);
        if($lengthOfEntry eq 0)
        {
          $lengthOfEntry = length $slotMapBinaryData;
        }

   }
   $targetObj->writeReport("\n--------------------------------\n");
   $slotMapHeader->allottedEntrySize($lengthOfEntry);
   $slotMapHeader->actualEntrySize($lengthOfEntry);

   $slotMapHeaderBinData .= $EntryHeaderPackFunctionsMap{"offsetToArray"}->($slotMapHeader->offsetToArray);
   $slotMapHeaderBinData .= $EntryHeaderPackFunctionsMap{"numberOfEntries"}->($slotMapHeader->numberOfEntries);
   $slotMapHeaderBinData .= $EntryHeaderPackFunctionsMap{"allottedEntrySize"}->($slotMapHeader->allottedEntrySize);
   $slotMapHeaderBinData .= $EntryHeaderPackFunctionsMap{"actualEntrySize"}->($slotMapHeader->actualEntrySize);

   print $slotMapBinfh "$slotMapHeaderBinData";
   print $slotMapBinfh "$slotMapBinaryData";
   close($slotMapBinfh)
     or die "Can't close $slotDetailsFileName";

   $slotMapHeader->offsetToArray(0x10);
   $slotMapHeader->numberOfEntries(scalar @slotEntryDetailsArray);
   $lengthOfEntry = 0;
   foreach my $slotDetailsEntry (@slotEntryDetailsArray)
   {
        print "Slot Map Entry ID : ", $slotDetailsEntry->slotMapEntryID, "\n";
        print "MGC Load Soure : ", $slotDetailsEntry->mgcLoadSource,"\n";
        print "HDDW Order : ", $slotDetailsEntry->hddwOrder,"\n";
        print "32 Bit MMIO Size : ", $slotDetailsEntry->mmioSize32bitMB,"\n";
        print "64 Bit MMIO Size : ", $slotDetailsEntry->mmioSize64bitGB,"\n";
        print "32 Bit DMA Size : ", $slotDetailsEntry->dmaSize32bitGB,"\n";
        print "64 Bit DMA Size : ", $slotDetailsEntry->dmaSize64bitGB,"\n";
        print "Slot Power Control Type : ", $slotDetailsEntry->slotPowerCtlType,"\n";
        print "Slot Presence Control Type : ", $slotDetailsEntry->presenceCtlType,"\n";
        print "PERST Control Type : ", $slotDetailsEntry->perstCtlType,"\n";
        print "PERST Control GPIO Pin : ", $slotDetailsEntry->perstCtlGPIOPin,"\n";
        print "Slot Max Power : ", $slotDetailsEntry->slotMaxPowerWatts,"\n";
        print "Slot Capabilities : ", $slotDetailsEntry->slotCapabilities, "\n";
        print "Total MSI Support : ", $slotDetailsEntry->totalMSISupport, "\n";
        print "Slot Power I2C Id : ", $slotDetailsEntry->slotPowerI2CId, "\n";
        print "Slot PGOOD I2C Id : ", $slotDetailsEntry->slotPgoodI2CId,"\n";
        print "Slot Presence I2C Id : ", $slotDetailsEntry->slotPresenceI2CId, "\n";
        print "Slot Enable I2C Id : ", $slotDetailsEntry->slotEnableI2CId, "\n";
        print "Slot Mex FPGA I2C Id : ", $slotDetailsEntry->slotMexFPGAI2CId, "\n";
        print "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotMapEntryID"}->($slotDetailsEntry->slotMapEntryID);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"mgcLoadSource"}->($slotDetailsEntry->mgcLoadSource);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"hddwOrder"}->($slotDetailsEntry->hddwOrder);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"mmioSize32bitMB"}->($slotDetailsEntry->mmioSize32bitMB);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"mmioSize64bitGB"}->($slotDetailsEntry->mmioSize64bitGB);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"dmaSize32bitGB"}->($slotDetailsEntry->dmaSize32bitGB);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"dmaSize64bitGB"}->($slotDetailsEntry->dmaSize64bitGB);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotPowerCtlType"}->($slotDetailsEntry->slotPowerCtlType);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"presenceCtlType"}->($slotDetailsEntry->presenceCtlType);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"perstCtlType"}->($slotDetailsEntry->perstCtlType);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"perstCtlGPIOPin"}->($slotDetailsEntry->perstCtlGPIOPin);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotMaxPowerWatts"}->($slotDetailsEntry->slotMaxPowerWatts);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotCapabilities"}->($slotDetailsEntry->slotCapabilities);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"totalMSISupport"}->($slotDetailsEntry->totalMSISupport);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotPowerI2CId"}->($slotDetailsEntry->slotPowerI2CId);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotPgoodI2CId"}->($slotDetailsEntry->slotPgoodI2CId);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotPresenceI2CId"}->($slotDetailsEntry->slotPresenceI2CId);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotEnableI2CId"}->($slotDetailsEntry->slotEnableI2CId);
        $slotEntryBinaryData .= $SlotEntryDetailsPackFunctionsMap{"slotMexFPGAI2CId"}->($slotDetailsEntry->slotMexFPGAI2CId);
        if($lengthOfEntry eq 0)
        {
          $lengthOfEntry = length $slotEntryBinaryData;
        }
   }
   $slotMapHeader->allottedEntrySize( $lengthOfEntry);
   $slotMapHeader->actualEntrySize( $lengthOfEntry );

   $slotEntryHeaderBinData .= $EntryHeaderPackFunctionsMap{"offsetToArray"}->($slotMapHeader->offsetToArray);
   $slotEntryHeaderBinData .= $EntryHeaderPackFunctionsMap{"numberOfEntries"}->($slotMapHeader->numberOfEntries);
   $slotEntryHeaderBinData .= $EntryHeaderPackFunctionsMap{"allottedEntrySize"}->($slotMapHeader->allottedEntrySize);
   $slotEntryHeaderBinData .= $EntryHeaderPackFunctionsMap{"actualEntrySize"}->($slotMapHeader->actualEntrySize);

   print $slotEntryBinfh "$slotEntryHeaderBinData";
   print $slotEntryBinfh "$slotEntryBinaryData";
   close($slotEntryBinfh)
     or die "Can't Close $slotDetailsFileName";
}


#--------------------------------------------------
## processPec
##
## Constructs Slot Map and Slot Entry Details structures

sub processPec
{
    my $targetObj    = shift;
    my $target       = shift; # PEC
    my $parentTarget = shift; # PROC

    my @slotmaparray;
    my @slotentrydetailsarray;

    # Find if this PHB has a pcieslot connection
    my $pcieBusConnection =
    $targetObj->findConnections($target,"PCIE","");

                   
    if($pcieBusConnection ne "")
    {
        foreach my $pcieBus (@{$pcieBusConnection->{CONN}})
        {
           my $sourceTargetType = $targetObj->getTargetType
                                       ($targetObj->getTargetParent($pcieBus->{SOURCE}));
           my $destTargetType = $targetObj->getTargetType
                                                  ($targetObj->getTargetParent($pcieBus->{DEST}));
           if (($sourceTargetType eq "unit-phb-nimbus" ||
                       $sourceTargetType eq "unit-phb-cumulus") &&
                                        $destTargetType eq "chip-PEX8725")
           {
             #Found a switch upleg connection
              my $slotMapRootComplex = addRootComplex($target,
                                                     $targetObj,
                                                     $pcieBus);

              my ($s1array , $s2array) = addSwitchUpleg($targetObj,
                                                        $pcieBus,
                                               $slotMapRootComplex->myEntryId);

              push(@slotmaparray, $slotMapRootComplex);
              push(@slotentrydetailsarray, @$s2array);
              push(@slotmaparray, @$s1array);
            }
            elsif(($sourceTargetType eq "unit-phb-nimbus" ||
                               $sourceTargetType eq "unit-phb-cumulus")  &&
                              ($destTargetType eq "card-pciecard-card" ||
                              $destTargetType eq "card-pciecard-cablecard"))
            {
                #Found a slot connected to a PHB root complex

                my $slotMapRootComplex = addRootComplex($target,
                                                        $targetObj,
                                                        $pcieBus);

                $slotMapRootComplex->entryFeatures(0x01);

                my $parent_target =
                           $targetObj->getTargetParent(
                                            $pcieBus->{DEST_PARENT});

                $slotMapRootComplex->slotName($targetObj->getAttribute(
                                         $parent_target,"SLOT_NAME"));
                $slotMapRootComplex->slotIndex($targetObj->getAttribute(
                                                  $parent_target,"SLOT_INDEX"));

                my $slotentrydetails = addSlotEntryDetails($targetObj,
                                                              $pcieBus);
                $slotentrydetails->slotMapEntryID(
                                         $slotMapRootComplex->myEntryId);

                push(@slotmaparray, $slotMapRootComplex);
                push(@slotentrydetailsarray,$slotentrydetails);
            }
            elsif(($sourceTargetType eq "unit-phb-nimbus" ||
                                   $sourceTargetType eq "unit-phb-cumulus") &&
                                   ($destTargetType eq "chip-TUSB7340" ||
                                   $destTargetType eq "chip-NVMe-device" ||
                                   $destTargetType eq "chip-BCM5719" ||
                                   $destTargetType eq "unit-pingroup-bmc"))
            {
                #Found a built-in device connected to a PHB root complex
                my $slotMapRootComplex = addRootComplex($target,
                                                        $targetObj,
                                                        $pcieBus);

                my $slotMapEntryEndDevice =
                                 addBuiltInDeviceSlotMap($targetObj,
                                                         $pcieBus);

                $slotMapEntryEndDevice->parentEntryId(
                                        $slotMapRootComplex->myEntryId);

                $myslotMapEntryId++;
                $slotMapEntryEndDevice->myEntryId($myslotMapEntryId);

                push(@slotmaparray, $slotMapRootComplex);
                push(@slotmaparray, $slotMapEntryEndDevice);
            }
        }
    } # Found connection
    return(\@slotmaparray, \@slotentrydetailsarray);
}

#--------------------------------------------------
## processObus
##
## Constructs SMP Link Data Structures

sub processObus
{
    my $targetObj    = shift;
    my $target       = shift; #proc
    my @smplinkarray;
    my %linkCounts;

    my %bricklaneMask;
    $bricklaneMask{0}  = 0x00F1E000;
    $bricklaneMask{1}  = 0x000E1870;
    $bricklaneMask{2}  = 0x0000078F;
    $bricklaneMask{9}  = 0x00F1E000;
    $bricklaneMask{10} = 0x000E1870;
    $bricklaneMask{11} = 0x0000078F;

    my %occgpustatusbit;
    $occgpustatusbit{0} = 22;
    $occgpustatusbit{1} = 23;
    $occgpustatusbit{2} = 24;
    $occgpustatusbit{3} = 22;
    $occgpustatusbit{4} = 23;
    $occgpustatusbit{5} = 24;

    my $obusconnections = $targetObj->findConnections($target,"OBUS","");

    if ($obusconnections ne "")
    {
       foreach my $obusconn (@{$obusconnections->{CONN}})
       {
         my $smplinkentry = new smpLinkEntry_t;

         $smplinkentry->source($obusconn->{SOURCE});
         $smplinkentry->destination($obusconn->{DEST});
         $smplinkentry->obusConfig(substr($targetObj->getBusAttribute($obusconn->{SOURCE},$obusconn->{BUS_NUM},"OBUS_CONFIG"),2));

         if($linkCounts{$smplinkentry->obusConfig} eq "")
         {
           $linkCounts{$smplinkentry->obusConfig} = 0;
         }
         $smplinkentry->linkEntryId($linkCounts{$smplinkentry->obusConfig});

         if($targetObj->getTargetType($obusconn->{DEST_PARENT})  eq "card-gv100card-card")
         {
           $smplinkentry->linkUsage(linkusage_gpu_ocapi);
         }
         $smplinkentry->brickID($targetObj->getAttribute($obusconn->{SOURCE},"CHIP_UNIT"));

         #TODO LaneMask has to be added to MRW
         $smplinkentry->laneMask($bricklaneMask{$smplinkentry->brickID});

         $smplinkentry->slotMapEntryId($hostconnectionslinkmap{$targetObj->getTargetParent($obusconn->{DEST_PARENT})}{"SLOTMAPENTRY"});

         $smplinkentry->sideBandSignalsSlotMapEntryId(invalid_2byte);

         if($smplinkentry->linkUsage eq linkusage_extlink)
         {
           $smplinkentry->nvlinkPortSLCAIndex(getParentFRUSLCAID($targetObj,$targetObj->getTargetParent($obusconn->{DEST_PARENT})));
         }
         else
         {
           $smplinkentry->nvlinkPortSLCAIndex(invalid_2byte);
         }
         $smplinkentry->reserved1(reserved_default);
         $smplinkentry->nvlinkI2cEntryId(invalid_4byte);
         $smplinkentry->nvlinkCablePresDetectI2cId(invalid_4byte);
         $smplinkentry->nvlinkCableMicroResetI2cId(invalid_4byte);
         $smplinkentry->smpLinkSpeed(linkspeed_2578gbps);

         if(!($targetObj->isBadAttribute($obusconn->{DEST_PARENT},"OCC_STATUS_BIT")))
         {
           $smplinkentry->occStatusRegisterBit($targetObj->getAttribute($$obusconn->{DEST_PARENT},"OCC_STATUS_BIT"));
         }
         else
         {
           $smplinkentry->occStatusRegisterBit($occgpustatusbit{$targetObj->getAttribute($targetObj->getTargetParent($obusconn->{DEST_PARENT}),"POSITION")});
         }

         $smplinkentry->gpuSLCAIndex(getParentFRUSLCAID($targetObj,$targetObj->getTargetParent($obusconn->{DEST_PARENT})));

         $linkCounts{$smplinkentry->obusConfig}++;
         push(@smplinkarray,$smplinkentry);
       }
    }
    my $position = $targetObj->getAttribute($target, "POSITION");
    sendobusdatatofile($position,\@smplinkarray);
}

#--------------------------------------------------
## sendobusdatatofile
##
sub sendobusdatatofile
{
    my $proc_id = shift;
    my @smplinkarray = @{$_[0]};
    my $smplinkheaderBinData;
    my $lengthOfEntry = 0;
    my $systemName = $targetObj->getSystemName();
    my $smplinkfilename;
    my %smplinkfilenames;
    my %smplinkfilehandles;
    my %smplinkbindata;
    my %smplinknumberOfEntries;

    foreach my $smplinkentry (@smplinkarray)
    {
      if($smplinkfilenames{$smplinkentry->obusConfig} eq "")
      {
        if($smplinkentry->obusConfig eq 0)
        {
           if($prefixSystemName == 1)
           {
             $smplinkfilename = $systemName."_"."smplinkproc".$proc_id;
           }
           else
           {
             $smplinkfilename = "smplinkproc".$proc_id;
           }
        }
        else
        {
           if($prefixSystemName == 1)
           {
             $smplinkfilename = $systemName."_"."smplinkproc".$proc_id."_oc".$smplinkentry->obusConfig;
           }
           else
           {
             $smplinkfilename = "smplinkproc".$proc_id."_oc".$smplinkentry->obusConfig
           }
        }
        $smplinkfilenames{$smplinkentry->obusConfig} = $smplinkfilename;
        open ( my $smplinkbinfh , ">", $smplinkfilename)
          or die "Can't open > $smplinkfilename: $!";
        binmode($smplinkbinfh);
        $smplinkfilehandles{$smplinkentry->obusConfig} = $smplinkbinfh;
        $smplinknumberOfEntries{$smplinkentry->obusConfig} = 0;
      }
    }

   print "===================================================================\n";
   foreach my $smplinkentry (@smplinkarray)
   {
       print "SMP Link :",$smplinkentry->source," to ",$smplinkentry->destination,"\n";
       print "GPU Config :",$smplinkentry->obusConfig,"\n";
       print "SMP Link Entryid:",$smplinkentry->linkEntryId,"\n";
       print "SMP Link Usage:",$smplinkentry->linkUsage,"\n";
       print "SMP Link brickID:",$smplinkentry->brickID,"\n";
       print "SMP Link Lane Mask:",$smplinkentry->laneMask,"\n";
       print "Interposer Slot Map Entry ID:",$smplinkentry->slotMapEntryId,"\n";
       print "Sideband Slot Map Entry ID:",$smplinkentry->sideBandSignalsSlotMapEntryId,"\n";
       print "SLCA Index of External NVLINK Port:",$smplinkentry->nvlinkPortSLCAIndex,"\n";
       print "Reserved:",$smplinkentry->reserved1,"\n";
       print "I2C Entry for NVLINK Cable:",$smplinkentry->nvlinkI2cEntryId,"\n";
       print "I2C Entry for NVLINK Cable Presence Detect:",$smplinkentry->nvlinkCablePresDetectI2cId,"\n";
       print "I2C Entry for NVLINK Micro Reset:",$smplinkentry->nvlinkCableMicroResetI2cId,"\n";
       print "SMP Link Speed:",$smplinkentry->smpLinkSpeed,"\n";
       print "OCC GPU Status bit:",$smplinkentry->occStatusRegisterBit,"\n";
       print "GPU SLCA Index:",$smplinkentry->gpuSLCAIndex,"\n";
       print "--------------------------- -------------------------------------\n";

        my $result = sprintf("eid - %d obc - %d brick id - %d usage - %d mask - 0x%08x seid - %d occ  - %d\n",
                             $smplinkentry->linkEntryId, $smplinkentry->obusConfig, $smplinkentry->brickID, $smplinkentry->linkUsage,
                             $smplinkentry->laneMask, $smplinkentry->slotMapEntryId, $smplinkentry->occStatusRegisterBit);
        $targetObj->writeReport($result);

        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"linkEntryId"}->($smplinkentry->linkEntryId);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"linkUsage"}->($smplinkentry->linkUsage);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"brickID"}->($smplinkentry->brickID);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"laneMask"}->($smplinkentry->laneMask);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"slotMapEntryId"}->($smplinkentry->slotMapEntryId);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"sideBandSignalsSlotMapEntryId"}->
                                                           ($smplinkentry->sideBandSignalsSlotMapEntryId);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"nvlinkPortSLCAIndex"}->($smplinkentry->nvlinkPortSLCAIndex);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"reserved1"}->($smplinkentry->reserved1);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"nvlinkI2cEntryId"}->($smplinkentry->nvlinkI2cEntryId);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"nvlinkCablePresDetectI2cId"}->
                                                          ($smplinkentry->nvlinkCablePresDetectI2cId);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"nvlinkCableMicroResetI2cId"}->
                                                            ($smplinkentry->nvlinkCableMicroResetI2cId);

        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"smpLinkSpeed"}->
                                                            ($smplinkentry->smpLinkSpeed);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"occStatusRegisterBit"}->
                                                        ($smplinkentry->occStatusRegisterBit);
        $smplinkbindata{$smplinkentry->obusConfig} .=
                         $SMPLinkEntryPackFunctionsMap{"gpuSLCAIndex"}->
                                                        ($smplinkentry->gpuSLCAIndex);

        if($lengthOfEntry eq 0)
        {
          $lengthOfEntry = length $smplinkbindata{$smplinkentry->obusConfig};
        }
        $smplinknumberOfEntries{$smplinkentry->obusConfig}++;
   }
   $targetObj->writeReport("\n-----------------------------------------------------------\n");

   foreach my $smpbinkey (keys %smplinkbindata)
   {
     my $smplinkheader = new EntryHeader_t;
     my $smplinkheaderBinData;
     my $binfh = $smplinkfilehandles{$smpbinkey};

     $smplinkheader->offsetToArray(0x10);
     $smplinkheader->numberOfEntries($smplinknumberOfEntries{$smpbinkey});
     $smplinkheader->allottedEntrySize( $lengthOfEntry);
     $smplinkheader->actualEntrySize( $lengthOfEntry );

     $smplinkheaderBinData .= pack4byte($smplinkheader->offsetToArray);
     $smplinkheaderBinData .= pack4byte($smplinkheader->numberOfEntries);
     $smplinkheaderBinData .= pack4byte($smplinkheader->allottedEntrySize);
     $smplinkheaderBinData .= pack4byte($smplinkheader->actualEntrySize);

     print $binfh "$smplinkheaderBinData";
     print $binfh "$smplinkbindata{$smpbinkey}";
     close($smplinkfilehandles{$smpbinkey})
       or die "Can't close $smplinkfilenames{$smpbinkey}";
   }
}

#--------------------------------------------------
## getSlaveDevicePurpose
##
#
sub getSlaveDevicePurpose
{
   my $targetObj = shift;
   my $slavetarget = shift;
   my $purpose = "";
   my %device_purpose_of = (
      "PSBE"         => p_sbeseeprom,
      "RSBE"         => p_sbeseeprom,
      "PMVPD"        => p_procmodulevpd,
      "SVPD"         => p_procmodulevpd,
      "RMVPD"        => p_procmodulevpd,
      "PVPD"         => p_bpvpd,
      "chip-NPCT501" => p_tpm,
      "chip-dimm-thermal-sensor" => p_thermalSensor,
      "PGOOD"        => p_pciepgood,
      "ENABLE"       => p_pciecontrol,
      "ENALE"        => p_pciecontrol,
      "PCVPD"        => p_dimmspd,
      "SPD"          => p_dimmspd,
      "EXP_PRSNT_FB" => p_cableccardpresence,
      "EXP_PRSNTA_B" => p_cableccardhosti2cenable,
      "chip-LPC11U35" => p_cablemicroreset,

   );

   if ($purpose eq "")
   {
     #If GPIO_TYPE is defined, then we can map it to the purpose directly
     if(!($targetObj->isBadAttribute($slavetarget,"GPIO_TYPE")))
     {
       $purpose = $device_purpose_of{$targetObj->getAttribute($slavetarget,"GPIO_TYPE")};
     }
     else
     {
       $targetObj->writeReport("WARNING::GPIO_TYPE missing for attribute $slavetarget\n");
     }
   }
   #If we did not find a purpose matching the GPIO_type
   #Find purpose based on PIN_NAME
   if ($purpose eq "")
   {
     if(!($targetObj->isBadAttribute($slavetarget,"PIN_NAME")))
     {
       my $pin_name = $targetObj->getAttribute($slavetarget,"PIN_NAME");
       if(index($pin_name , "EXP_PRSNT") ne -1)
       {
         $purpose = $device_purpose_of{substr $pin_name ,index($pin_name , "EXP_PRSNT")};
       }
     }
   }

   #If we did not find a purpose matching the PIN_NAME
   #Find purpose based on destination target type
   if ($purpose eq "")
   {
     my $parent_target = $targetObj->getTargetParent($slavetarget);
     my $destTargetType = $targetObj->getTargetType($parent_target);
     $purpose = $device_purpose_of{$destTargetType};
     #if we did not find a purpose matching the destination target type
     #Find purpose based on MRW_TYPE VPD
     if($purpose eq "")
     {
        my $i2cslavemrwtype = $targetObj->getAttribute($parent_target, "MRW_TYPE");
        if($i2cslavemrwtype eq "VPD" || $i2cslavemrwtype eq "SPD")
        {
           my $vpdtype = $targetObj->getAttribute($parent_target, "VPD_TYPE");
           $purpose = $device_purpose_of{$vpdtype};
        }
        elsif($i2cslavemrwtype eq "NA")
        {
          #if we did not find a purpose matching the MRW_TYPE
          $purpose = invalid_1byte;
        }
     }
   }
   return $purpose;
}

#--------------------------------------------------
## getSlaveDeviceType
##
##
sub getSlaveDeviceType
{
   my $targetObj = shift;
   my $slavetarget = shift;
   my $deviceType = invalid_1byte;

   my %device_type_of = (
      "chip-PCA9555" => sd_pca9555,
      "chip-PCA9554" => sd_pca9554,
      "chip-PCA9553" => sd_pca9553,
      "chip-PCA9552" => sd_pca9552,
      "chip-PCA9551" => sd_pca9551,
      "chip-UCD9090" => sd_ucx90,
      "chip-NPCT501" => sd_nuvotontpm,
      "chip-dimm-thermal-sensor" => sd_thermalSensor,
      "24c04"        => sd_at24c04,
      "24c128"       => sd_at24c128,
      "24c512"       => sd_at24c512,
      "24c32"        => sd_at24c32,
      "24c64"        => sd_at24c64,
      "24c16"        => sd_at24c16,
      "PSBE"         => sd_at24c512,
      "RSBE"         => sd_at24c512,
      "PVPD"         => sd_at24c256,
      "PMVPD"        => sd_at24c256,
      "RMVPD"        => sd_at24c128,
      "SVPD"         => sd_at24c128,
      "SPD"          => sd_at24c128,
      "PCVPD"        => sd_at24c256,
      "card-gv100card-card" => sd_nvdiaGpu,
      "chip-LPC11U35" => sd_lpc11u35,
   );

   my $parent_target = $targetObj->getTargetParent($slavetarget);
   my $i2cslavemrwtype = $targetObj->getAttribute($parent_target, "MRW_TYPE");

   if ($deviceType eq invalid_1byte )
   {
     if($i2cslavemrwtype eq "VPD" || $i2cslavemrwtype eq "SPD")
     {
       #Find device type based on VPD_SIZE attribute
       if($targetObj->getAttribute($slavetarget, "VPD_SIZE") ne "" &&
             $targetObj->getAttribute($slavetarget, "VPD_SIZE") ne "NA")
       {
         $deviceType = $device_type_of{$targetObj->getAttribute($slavetarget, "VPD_SIZE")};
       }
       else
       {
          $targetObj->writeReport("ERROR: VPD_SIZE not initialized for $slavetarget\n");
       }
       if ($deviceType eq invalid_1byte || $deviceType eq "")
       {
         #If we did not find any device type based on destination target type
         #Find device type based on MRW_TYPE VPD or SPD
         my $vpdtype = $targetObj->getAttribute($parent_target, "VPD_TYPE");
         $deviceType = $device_type_of{$vpdtype};
       }
     }
   }
   if ($deviceType eq invalid_1byte)
   {
     #Find device type based on destination target type
     my $destTargetType = $targetObj->getTargetType($parent_target);
     if($device_type_of{$destTargetType} ne "")
     {
       $deviceType = $device_type_of{$destTargetType};
     }
     else
     {
        #Find device type based on target type of grandparent target
        $deviceType = $device_type_of{$targetObj->getTargetType(
                                  $targetObj->getTargetParent($parent_target))};
        if($deviceType eq "")
        {
          $deviceType = invalid_1byte;
        }
      }
    }
   return  $deviceType;
}

#--------------------------------------------------
## getParentFRUSLCAID
##
## Get the SLCA ID of the parent FRU associated with the passed target
sub getParentFRUSLCAID
{
   my $targetObj = shift;
   my $target = shift;
   my $parent_target;
   my $input_target = $target;
   my $slca_id;
   my $rutype;
   my $incomingtarget = $target;
   my %fru_type_of = (
      "PLANAR"         => 0x0800,
      "PROC"           => 0x1000,
      "DIMM"           => 0xD000,
      "BMC"            => 0x0200,
      "FAN"            => 0x3A00,
      "POWERSUPPLY"    => 0x3100,
      "PCIESLOT"       => 0x3600,
      "VRM"            => 0x3900,
   );

   if(!($targetObj->isBadAttribute
                       ($target, "RU_TYPE")))
   {
     $rutype = $targetObj->getAttribute($target, "RU_TYPE");
   }
   my $parent_target = $target;
   while ($rutype ne "FRU" && $parent_target ne "")
   {
     $parent_target = $targetObj->getTargetParent($parent_target);
     if(!($targetObj->isBadAttribute
                       ($parent_target, "RU_TYPE")))
     {
       $rutype = $targetObj->getAttribute($parent_target, "RU_TYPE");
     }
     $target = $parent_target;
   }
   if($target ne "")
   {
     if(! $targetObj->isBadAttribute($target,"CARD_TYPE") &&
                ! $targetObj->isBadAttribute($target,"POSITION"))
     {
       $slca_id = $fru_type_of{$targetObj->getAttribute($target,"CARD_TYPE")} | $targetObj->getAttribute($target,"POSITION");
     }
     else
     {
       $targetObj->writeReport("Missing CARD_TYPE and/or POSITION attribute for $target\n");
       $slca_id = 0;
     }
   }
   else
   {
     $targetObj->writeReport("Could not find a parent FRU for incoming target $incomingtarget and parent target $target\n");
#     die "Could not find a parent FRU for incoming target $incomingtarget and parent target $target";
   }
   return $slca_id;
}

#--------------------------------------------------
## getParentNodeId
##
## Get the Node Ordinal ID corresponding to the passed target
sub getParentNodeId
{
   my $targetObj = shift;
   my $target = shift;
   my $parent_target;
   my $node_id;
   my $targettype = $targetObj->getTargetType($target);
   my $parent_target = $target;
   while ($targettype ne "enc-node-power9" && $parent_target ne "")
   {
     $parent_target = $targetObj->getTargetParent($parent_target);
     $targettype = $targetObj->getTargetType($parent_target);
   }
   if($parent_target ne "")
   {
     $node_id = $targetObj->getAttribute($parent_target, "ORDINAL_ID");
   }
   else
   {
     die "Could not find Parent Node";
   }
   return $node_id;
}

#--------------------------------------------------
## getI2CEntryName
##
## Constructs entry name string for each I2C structure
sub getI2CEntryName
{
 my $targetObj = shift;
 my $i2centry = shift;
 my $entryname;

 my %vendor_device_of = (
      sd_pca9555     , "nxp,pca9555",
      sd_pca9554     , "nxp,pca9554",
      sd_pca9553     , "nxp,pca9553",
      sd_pca9552     , "nxp,pca9552",
      sd_pca9551     , "nxp,pca9551",
      sd_ucx90       , "ti,ucd9090",
      sd_nuvotontpm  , "nuvoton,npct601",
      sd_thermalSensor , "thermal,sensor",
      sd_at24c128    , "atmel,24c128",
      sd_at24c256    , "atmel,24c256",
      sd_at24c04     , "atmel,24c04",
      sd_at24c512    , "atmel,24c512",
      sd_at24c32     , "atmel,24c32",
      sd_at24c64     , "atmel,24c64",
      sd_at24c16     , "atmel,24c16",
      sd_nvdiaGpu    , "nvdia,gpu",
      sd_lpc11u35    , "nxp,lpc11u35",
   );

  my %purpose_of = (
      p_sbeseeprom  , "image,sbe",
      p_procmodulevpd , "vpd,module",
      p_bpvpd         , "vpd,planar",
      p_tpm           , "tpm,host",
      p_thermalSensor , "thermalsensor,dimm",
      p_cableccardpresence , "cablecard,presence",
      p_pciepgood     , "cablecard,pgood",
      p_dimmspd       , "spd,dimm",
      p_cablemicroreset , "smpcable,reset",
      p_securebootphyspresence , "secureboot,physicalpresence",
      p_securebootwinopen , "secureboot,window_open",
      p_cableccardhosti2cenable , "cablecard,hosti2cenablestatus",
      p_pciecontrol , "pcieslot,powercontrol",
      p_unknown , "unknown,unknown",
   );

   if(exists $vendor_device_of{$i2centry->slaveDeviceType})
   {
     $entryname .= $vendor_device_of{$i2centry->slaveDeviceType};
   }
   else
   {
     die "Unknown vendor device combination for $i2centry->slaveDeviceType";
   }

   $entryname .= ",";

   if(exists $purpose_of{$i2centry->entryPurpose})
   {
     $entryname .= $purpose_of{$i2centry->entryPurpose};
   }
   else
   {
     die "Unknown purpose for", $i2centry->entryPurpose;
   }

   return $entryname;
}

#--------------------------------------------------
## processI2C
##
## Constructs I2C Map for the passed target
sub processI2C
{
   my $targetObj = shift;
   my $target = shift;
   my $hosti2centryid = shift;

   my @i2cmap;

   my $parent_target =
             $targetObj->getTargetParent($targetObj->getTargetParent($target));
   my $proc_id = $targetObj->getAttribute($parent_target, "POSITION");

    my $i2cconnections = $targetObj->findConnections($target,"I2C","");
    if ($i2cconnections ne "")
    {
       foreach my $i2cconn (@{$i2cconnections->{CONN}})
       {
         my $i2centry = new i2cdeviceentrystructure;
#         print "Found I2C Connection ", $i2cconn->{SOURCE}, " to ", $i2cconn->{DEST}, "\n";
         $i2centry->source($i2cconn->{SOURCE});
         $i2centry->destination($i2cconn->{DEST});
         my $destTargetType = $targetObj->getTargetType($i2cconn->{DEST_PARENT});
#         print "Dest Target Type is $destTargetType \n";

         my $i2cengine = $targetObj->getAttribute(
                                      $i2cconn->{SOURCE}, "I2C_ENGINE");
         $i2centry->i2cEngine(hex($i2cengine));

         my $i2cport = $targetObj->getAttribute(
                                      $i2cconn->{SOURCE}, "I2C_PORT");
         $i2centry->i2cPort(hex($i2cport));

         $i2centry->i2cSpeed($targetObj->getBusAttribute(
                                      $i2cconn->{SOURCE},
                                      $i2cconn->{BUS_NUM},"I2C_SPEED"));

         my $i2caddress = $targetObj->getAttribute(
                                      $i2cconn->{DEST}, "I2C_ADDRESS");
         $i2centry->slaveDeviceAddress(hex($i2caddress));

         $i2centry->reserved1(0);
         $i2centry->slcaIndex(getParentFRUSLCAID($targetObj,$i2cconn->{DEST}));

#         print "I2C Engine is ", $i2centry->i2cEngine, " and I2C Port is ",$i2centry->i2cPort," \n";

         if($targetObj->isBusAttributeDefined(
                                      $i2cconn->{SOURCE},
                                     $i2cconn->{BUS_NUM},"I2C_TYPE"))
         {
            my $type = $targetObj->getBusAttribute(
                                      $i2cconn->{SOURCE},
                                      $i2cconn->{BUS_NUM},"I2C_TYPE");
            if ($type ne "")
            {
               $i2centry->slaveDeviceType(hex($targetObj->
                           getEnumValue("HDAT_I2C_DEVICE_TYPE",$type)));
            }
         }
         if($i2centry->slaveDeviceType eq "")
         {
            $i2centry->slaveDeviceType(getSlaveDeviceType(
                                      $targetObj, $i2cconn->{DEST}));
         }


         if($targetObj->isBusAttributeDefined(
                                      $i2cconn->{SOURCE},
                                     $i2cconn->{BUS_NUM},"I2C_PURPOSE"))
         {
            my $purpose = $targetObj->getBusAttribute(
                                      $i2cconn->{SOURCE},
                                      $i2cconn->{BUS_NUM},"I2C_PURPOSE");
            if ($purpose ne "")
            {
              $i2centry->entryPurpose(hex($targetObj->
                                getEnumValue("HDAT_I2C_DEVICE_PURPOSE",$purpose)));
            }
         }
         if($i2centry->entryPurpose eq "")
         {
            $i2centry->entryPurpose(getSlaveDevicePurpose(
                                      $targetObj, $i2cconn->{DEST}));
         }

#         print "devicetype:",$i2centry->slaveDeviceType,"  and purpose is ",$i2centry->entryPurpose,"\n";

#         print "Finding GPIO Connections for $i2cconn->{DEST_PARENT} \n";
         my $gpiofromconnections = $targetObj->findConnections(
                                     $i2cconn->{DEST_PARENT}, "GPIO", "");
         my $gpiotoconnections = $targetObj->findDestConnections(
                                     $i2cconn->{DEST_PARENT}, "GPIO", "");
         if ($gpiofromconnections ne "" || $gpiotoconnections ne "")
         {
           if($gpiofromconnections ne "")
           {
            foreach my $gpio (@{$gpiofromconnections->{CONN}})
            {
#               print "Found FROM GPIO Connection ", $gpio->{SOURCE}, " to ", $gpio->{DEST}, "\n";

               my $i2cslaveentry = new i2cdeviceentrystructure;
               $i2cslaveentry->i2cEngine($i2centry->i2cEngine);
               $i2cslaveentry->i2cPort($i2centry->i2cPort);
               $i2cslaveentry->i2cSpeed($i2centry->i2cSpeed);
               $i2cslaveentry->slaveDeviceAddress(
                                    $i2centry->slaveDeviceAddress);
               $i2cslaveentry->reserved1(0);
               $i2cslaveentry->slcaIndex(0);
               $i2cslaveentry->slaveDeviceType(
                                    $i2centry->slaveDeviceType);

               my $purpose = getSlaveDevicePurpose(
                                    $targetObj, $gpio->{SOURCE});
               if($purpose ne invalid_1byte)
               {
                 $i2cslaveentry->entryPurpose($purpose);
               }

               $i2cslaveentry->source($gpio->{SOURCE});
               $i2cslaveentry->destination($gpio->{DEST});

               $i2cslaveentry->hosti2cLinkId($hosti2centryid);
               $hosti2centryid++;

               $i2cslaveentry->slaveDevicePort(hex($targetObj->getAttribute(
                                                 $gpio->{SOURCE}, "PIN_NUM")));
               if($i2cslaveentry->slaveDevicePort eq "")
               {
                  $targetObj->writeReport("ERROR::PIN_NUM not defined for target $gpio->{SOURCE}\n");
               }
               if($i2cslaveentry->entryPurpose eq p_pciecontrol)
               {
                 $hostconnectionslinkmap{$gpio->{DEST_PARENT}}{"ENABLE"} =
                                                $i2cslaveentry->hosti2cLinkId;
               }

#               print "linkid : ", $i2cslaveentry->hosti2cLinkId, " devicetype:",$i2cslaveentry->slaveDeviceType,"  and purpose is ",$i2cslaveentry->entryPurpose,"\n";
               $i2cslaveentry->entryName(getI2CEntryName($targetObj,$i2cslaveentry));
               push(@i2cmap, $i2cslaveentry);
            }
           }
           if($gpiotoconnections ne "")
           {
            foreach my $gpio (@{$gpiotoconnections->{CONN}})
            {
 #              print "Found TO GPIO Connection ", $gpio->{SOURCE}, " to ", $gpio->{DEST}, "\n";

               my $i2cslaveentry = new i2cdeviceentrystructure;
               $i2cslaveentry->i2cEngine($i2centry->i2cEngine);
               $i2cslaveentry->i2cPort($i2centry->i2cPort);
               $i2cslaveentry->i2cSpeed($i2centry->i2cSpeed);
               $i2cslaveentry->slaveDeviceAddress($i2centry->slaveDeviceAddress);
               $i2cslaveentry->reserved1(0);
               $i2cslaveentry->slcaIndex(0);
               $i2cslaveentry->source($gpio->{SOURCE});
               $i2cslaveentry->destination($gpio->{DEST});
               $i2cslaveentry->entryPurpose(getSlaveDevicePurpose($targetObj, $gpio->{DEST}));
               $i2cslaveentry->slaveDeviceType($i2centry->slaveDeviceType);

               $i2cslaveentry->hosti2cLinkId($hosti2centryid);
               $hosti2centryid++;

               $i2cslaveentry->slaveDevicePort(hex($targetObj->getAttribute($gpio->{DEST}, "PIN_NUM")));

               if($i2cslaveentry->entryPurpose eq p_pciepgood)
               {
                 $hostconnectionslinkmap{$gpio->{SOURCE_PARENT}}{"PGOOD"} = $i2cslaveentry->hosti2cLinkId;
               }

               # PIN_NAME attribute value is of pattern PE_C11_EXP_PRSNT
               # We are taking the second field (For eg., C11) to map it
               # to PRESENCE and HOSTI2CENABLE
               my $pinname = $targetObj->getAttribute($gpio->{DEST},"PIN_NAME");
               my $index = index($pinname,"_EXP");

               if($i2cslaveentry->entryPurpose eq p_cableccardhosti2cenable)
               {
                 $hostconnectionslinkmap{substr $pinname, 3, $index-3}{"HOSTI2CENABLE"} =
                                                $i2cslaveentry->hosti2cLinkId;
               }

               if($i2cslaveentry->entryPurpose eq p_cableccardpresence)
               {
                 $hostconnectionslinkmap{substr $pinname, 3, $index-3}{"PRESENCE"} =
                                                $i2cslaveentry->hosti2cLinkId;
               }

#               print "linkid : ", $i2cslaveentry->hosti2cLinkId, " devicetype:",$i2cslaveentry->slaveDeviceType,"  and purpose is ",$i2cslaveentry->entryPurpose,"\n";
               $i2cslaveentry->entryName(getI2CEntryName($targetObj,$i2cslaveentry));
               push(@i2cmap, $i2cslaveentry);
            }
           }
         }
         else
         {
               $i2centry->hosti2cLinkId($hosti2centryid);
               $hosti2centryid++;
#               print "linkid : ", $i2centry->hosti2cLinkId, " devicetype:",$i2centry->slaveDeviceType,"  and purpose is ",$i2centry->entryPurpose,"\n";
               $i2centry->slaveDevicePort(invalid_1byte);
               $i2centry->entryName(getI2CEntryName($targetObj,$i2centry));
               push(@i2cmap, $i2centry);
         }
       }
    }
    return \@i2cmap;
}

#--------------------------------------------------
################################################################################
# Pack 4 byte value into a buffer using configured endianness
################################################################################

sub pack4byte {
    my($value) = @_;

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("N",$value);
    }
    else # Little endian
    {
        $binaryData = pack("V",$value);
    }

    return $binaryData;
}

################################################################################
# Pack 2 byte value into a buffer using configured endianness
################################################################################

sub pack2byte {
    my($value) = @_;

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("n",$value);
    }
    else # Little endian
    {
        $binaryData = pack("v",$value);
    }

    return $binaryData;
}

################################################################################
# Pack 1 byte value into a buffer using configured endianness
################################################################################

sub pack1byte {
    my($value) = @_;

    my $binaryData = pack("C",$value);

    return $binaryData;
}

################################################################################
# Pack string into buffer
################################################################################

sub packString{
    my($value,$sizeInclNull) = @_;

    # For sanity, remove all white space from front and end of string
    $value =~ s/^\s+//g;
    $value =~ s/\s+$//g;

    my $length = length($value);

    # print "String content (after fixup) is [$value]\n";
    # print "String length is $length\n";
    # print "String container size is $sizeInclNull\n";

    if(($length + 1) > $sizeInclNull)
    {
        croak("ERROR: Supplied string exceeds allowed length");
    }

    return pack("Z$sizeInclNull",$value);
}
sub printUsage
{
    print "
genHDATstructures.pl -x [XML filename] [OPTIONS]
Options:
        -f = force output file creation even when errors
        -r = create report and save to [system_name].rpt
        -v = version
";
    exit(1);
}
