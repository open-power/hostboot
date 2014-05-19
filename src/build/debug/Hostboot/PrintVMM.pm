# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/PrintVMM.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
use Hostboot::_DebugFrameworkVMM;
package Hostboot::PrintVMM;
use Exporter;
use integer;
our @EXPORT_OK = ('main');



sub main
{
    ::userDisplay "PrintVMM module.\n";

    my ($packName,$args) = @_;

    my $phyAddr = Hostboot::_DebugFrameworkVMM::NotFound;
    my $debug = 0;
    my $displaySPTE = 0;
    my $displayAll = 1;
    my $displayBase = 0;
    my $displayStack = 0;
    my $displayDevice = 0;

    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    if (defined $args->{"base"})
    {
        $displayBase = 1;
        $displayAll = 0;
    }

    if (defined $args->{"stack"})
    {
        $displayStack = 1;
        $displayAll = 0;
    }

    if (defined $args->{"device"})
    {
        $displayDevice = 1;
        $displayAll = 0;
    }

    # Get the device segment address
    my @segment_manager_addr =
          ::findSymbolAddress("Singleton<SegmentManager>::instance()::instance");

    if (not defined @segment_manager_addr)
    {
	::userDisplay "   VirtualToPhy: Cannot find Device Segment symbol.\n"; die;
    }

    my $baseSegmentPtr =
         ::read64 ($segment_manager_addr[0] +
                   Hostboot::_DebugFrameworkVMM::SEGMGR_BASE_SEGMENT_OFFSET, 8);

    my $StackSegmentPtr =
         ::read64 ($segment_manager_addr[0] +
                   Hostboot::_DebugFrameworkVMM::SEGMGR_STACK_SEGMENT_OFFSET, 8);

    my $DeviceSegmentPtr = 
         ::read64 ($segment_manager_addr[0] + 
                   Hostboot::_DebugFrameworkVMM::SEGMGR_FIRSTDEVICE_SEGMENT_OFFSET, 8);

    if (($displayBase) || ($displayAll))
    {
        ::userDisplay "\n-------------\n";
        ::userDisplay "BASE SEGMENT\n";
        ::userDisplay "-------------\n";


        if ($baseSegmentPtr == 0)
        {
            ::userDisplay "   PrintVMM:  No Segment Pointer. Have you run yet?\n"; die;
        }

        Hostboot::_DebugFrameworkVMM::printBaseSegment($baseSegmentPtr);
    }

    if (($displayStack) || ($displayAll))
    {

        ::userDisplay "\n-------------\n";
        ::userDisplay "STACK SEGMENT\n";
        ::userDisplay "-------------\n";

        if ($StackSegmentPtr == 0)
        {
            ::userDisplay "   PrintVMM:  No Segment Pointer. Have you run yet?\n"; die;
        }

        my $StackSegBaseAddr = ::read64($StackSegmentPtr +
                                        Hostboot::_DebugFrameworkVMM::STACKSEGMENT_BASEADDR_OFFSET, 8);

        ::userDisplay (sprintf "   Stack Segment base addr=%X\n" , $StackSegBaseAddr);

        my $firststackptr = ::read64 ($StackSegmentPtr +
                                      Hostboot::_DebugFrameworkVMM::STACKSEGMENT_FIRST_STACK_OFFSET, 8);

        Hostboot::_DebugFrameworkVMM::printStackSegment($firststackptr);
  
     }

    if (($displayDevice) || ($displayAll))
    {

        ::userDisplay "\n---------------\n";
        ::userDisplay "DEVICE SEGMENTS\n";
        ::userDisplay "---------------\n";

        if ($DeviceSegmentPtr == 0)
        {
            ::userDisplay "   PrintVMM:  No Segment Pointer. Have you run yet?\n"; die;
        }
        #Pass in address of the pointer to the first device segment in the segment manager
        # This routine will loop through all possible device semgnets and print their info.  
        Hostboot::_DebugFrameworkVMM::printDeviceSegments($segment_manager_addr[0] +
                   Hostboot::_DebugFrameworkVMM::SEGMGR_FIRSTDEVICE_SEGMENT_OFFSET);


     }

 return 0;
}



sub helpInfo
{
    my %info = (
        name => "PrintVMM",
        intro => ["Print out the VMM mapping. "],
        options => {
                    "debug" => ["More debug output."],
                    "base" => ["Prints out BASE segment info."],
                    "stack" => ["Prints out STACK segment info."],
                    "device" => ["Prints out Device segment info."],
                   },

    );
}
