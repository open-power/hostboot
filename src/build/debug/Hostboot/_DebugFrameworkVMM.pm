#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/_DebugFrameworkVMM.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
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
# _DebugFrameworkVMM.pm
#
# This module is a set of utility functions for the debug framework, which
# should be common across all debug framework environments.
#
# The module provides the functions listed below in @EXPORT.
#
# A debug framework environment is expected to implement the following
# functions:
#     * getIsTest() - Is the image loaded a test image or normal?
#     * getImgPath() - Path to the .../img/ directory containing debug files.
#     * readData(addr,size) - Read a blob of memory.
#     * userDisplay(varargs-of-mixed) - Display things to the user.
#

use strict;
use integer;


package Hostboot::_DebugFrameworkVMM;
use Exporter 'import';

our @EXPORT = (
                'displaySPTE',
                'getPhysicalAddr',
                'printBaseSegment',
                'printStackSegment',
                'printDeviceSegments'
              );

use constant NotFound => 'not found';
use constant NotPresent => 'not present';

use constant SEGMGR_BASE_SEGMENT_OFFSET => 0;
use constant SEGMGR_STACK_SEGMENT_OFFSET => 8;
use constant SEGMGR_FIRSTDEVICE_SEGMENT_OFFSET => 16;

use constant BASESEGMENT_BASEADDR_OFFSET => 8;
use constant BASESEGMENT_BLOCK_OFFSET => 16;
use constant BASESEGMENT_PHY_SIZE_OFFSET => 24;

use constant STACKSEGMENT_BASEADDR_OFFSET => 8;
use constant STACKSEGMENT_FIRST_STACK_OFFSET => 16;

use constant DEVICESEGMENT_BASEADDR_OFFSET => 8;
use constant DEVICESEGMENT_BLOCK_OFFSET => 16;
use constant DEVICESEGMENT_BLOCK_SIZE => 24;

use constant STACK_NEXT_STACK_OFFSET => 0;
use constant STACK_PREV_STACK_OFFEST => 8;
use constant STACK_KEY_OFFSET => 16;
use constant STACK_BLOCKPTR_OFFSET => 24;

use constant MMIO_STRUCT_SIZE           => 16;
use constant MMIO_STRUCT_SEGADDR_OFFSET => 0;
use constant MMIO_STRUCT_SEGSIZE_OFFSET => 8;
use constant MMIO_STRUCT_GUARDED_MASK   => 0x4000000000000000;
use constant MMIO_STRUCT_NO_CI_MASK     => 0x8000000000000000;
use constant MMIO_STRUCT_SIZE_MASK      => 0x3FFFFFFFFFFFFFFF;

use constant BLOCK_BASE_ADDR => 0;
use constant BLOCK_SIZE_OFFSET => 8;
use constant BLOCK_PARENT_SEGMENTPTR_OFFSET => 16;
use constant BLOCK_NEXTPTR_OFFSET => 24;
use constant BLOCK_SPTE_OFFSET => 32;
use constant BLOCK_IS_PHYSICAL => 56;



our @EXPORT_OK = ('NotFound',
                  'NotPresent',
                  'SEGMGR_BASE_SEGMENT_OFFSET',
                  'SEGMGR_STACK_SEGMENT_OFFSET',
                  'SEGMGR_FIRSTDEVICE_SEGMENT_OFFSET',
                  'STACKSEGMENT_BASEADDR_OFFSET',
                  'STACKSEGMENT_FIRST_STACK_OFFSET',
 );


# @sub displaySPTE
#
# Display in PSTE entry info
#
# @param Address of the SPTE entry
#
sub displaySPTE
{
    my $vaddr = shift;
    my $SPTE_entry = shift;

    my $SPTEaddr = $SPTE_entry & 0xFFFFF000;

    ::userDisplay"\n===================================================\n";
    ::userDisplay (sprintf "SPTE Entry for VirtualAddr=%X\n" , $vaddr);
    ::userDisplay (sprintf "     Starting Physical Addr of the page   =:   %X\n"
                   , $SPTEaddr);

    ::userDisplay (sprintf "           present   =      %X\n" , ($SPTE_entry &
                                                                 0x00000800) >>
                   11 );

    ::userDisplay (sprintf "           readable  =      %X\n" , ($SPTE_entry &
                                                                 0x00000400) >>
                   10 );

    ::userDisplay (sprintf "           writable  =      %X\n" , ($SPTE_entry &
                                                                 0x00000200) >>
                   9 );

    ::userDisplay (sprintf "           executable=      %X\n" , ($SPTE_entry &
                                                                 0x00000100) >>
                   8 );

    ::userDisplay (sprintf "           trackWrite=      %X\n" , ($SPTE_entry &
                                                                 0x00000080) >>
                   7 );

    ::userDisplay (sprintf "           dirty     =      %X\n" , ($SPTE_entry &
                                                                 0x00000040) >>
                   6 );

    ::userDisplay (sprintf "           AllocateFromZero=%X\n" , ($SPTE_entry &
                                                                 0x00000020) >>
                   5 );

    ::userDisplay (sprintf "           last Access=     %X\n" , ($SPTE_entry &
                                                                 0x0000001C) >>
                   2 );

    ::userDisplay"===================================================\n";

}


# @sub findBlock
#
# Given a block and an address, find the block the address
# is part of.
#
# @param Ptr to the first block
# @param address we are looking for
# @param debug variable to indicate debug mode
# @return Ptr to block
#
sub findBlock
{

    my $block_ptr = shift;
    my $vaddr = shift;
    my $debug = shift;
    my $block_found = 0;

    while (($block_ptr != 0) && ($block_found == 0))
    {
        #Get the base address of the block
        my $block_base_addr =  ::read64 ($block_ptr + BLOCK_BASE_ADDR, 8);

        #Get the size of the block
        my $block_size =  ::read64 ($block_ptr + BLOCK_SIZE_OFFSET, 8);

        # check that va is in the block range
        if (($vaddr <= $block_base_addr + $block_size) &&
            ($vaddr >= $block_base_addr))
        {
            $block_found = 1;
        }

        my $next_block_ptr =  ::read64 ($block_ptr + BLOCK_NEXTPTR_OFFSET, 8);

        #::userDisplay (sprintf "      findBlock:: Next block ptr:   %X\n\n" ,
        #               $next_block_ptr);


        if ($block_found == 0)
        {
            $block_ptr = $next_block_ptr;
        }
        else
        {
            if ($debug)
            {
                #::userDisplay "      findBlock:  found a matching block \n";
                #::userDisplay (sprintf "      findblock - vaddr=   %X\n" , $vaddr);
                ::userDisplay (sprintf "      Block ptr:   %X\n" , $block_ptr);
                ::userDisplay (sprintf "        Found block base addr =%X\n" ,
                               $block_base_addr);
                ::userDisplay (sprintf "        Found block block size=%X\n" ,
                               $block_size);

            }
        }
    }

return $block_ptr;
}


# @sub findStack
#
# Given a Stack ptr from a list of stack and an address,
# find which stack this address is part of
#
# @param Ptr to the first stack entry
# @param address we are looking for
# @param debug var to indicate debug mode (1 = debug on)
# @return Ptr to stack
#
sub findStack
{
    my $stackptr = shift;
    my $vaddr = shift;
    my $debug = shift;
    my $found = 0;

    # the stack key
    my $Megabyte = 1024*1024;

    my $stackkey = $vaddr & ~((8 * $Megabyte) - 1);


    do
    {
        #if ($debug)
        #{
        #  ::userDisplay (sprintf "\n     findStack: Stack Pointer  =%X\n" ,
        #                 $stackptr);
        #  ::userDisplay (sprintf
        #                 "     findStack: stackkey we are looking for:   %X\n" , $stackkey);

        #  ::userDisplay (sprintf "     findStack: stackKey in Memory=%X\n" ,
        #                 ::read64 ($stackptr + 16, 8));
        #}

        if (::read64 ($stackptr + STACK_KEY_OFFSET, 8) == $stackkey)
        {
            $found = 1;

            if ($debug)
            {
               ::userDisplay (sprintf "\n      Stack Pointer=%X\n" , $stackptr);
            }
        }
        else
        {
            # Get the next stack pointer..
            $stackptr = ::read64 ($stackptr + STACK_NEXT_STACK_OFFSET, 8);
         }

    }while((!$found) && ($stackptr != 0));

    if (!$found)
    {
        if ($debug)
        {
            ::userDisplay
              (sprintf"      findStack: Did not find a stack entry for v addr:   %X\n" , $vaddr);
        }

        $stackptr = 0;
    }

return $stackptr
}



# @sub getPhyAddrfromSPTE
#
# Find the SPTE for that vaddr and return the physical addr
#
# @param Address of the SPTE entry
# @param address we are looking for
# @param debug var to indicate debug mode (1 = debug on)
# @return physical address
#
sub getPhyAddrfromSPTE
{
    my $block_ptr = shift;
    my $vaddr = shift;
    my $debug = shift;
    my $displaySPTE = shift;

    my $paddr = NotFound;

    my $SPTE_ptr = ::read64 ($block_ptr + BLOCK_SPTE_OFFSET, 8);

    #Get the base address of the block
    my $block_base_addr =  ::read64 ($block_ptr + BLOCK_BASE_ADDR, 8);

    my $index = ($vaddr - $block_base_addr)/4096;

    my $spteindex = $index*4;

    my $SPTE_entry = ::read32 ($SPTE_ptr + $spteindex, 4);

    my $isPhysical = ::read8 ($block_ptr + BLOCK_IS_PHYSICAL);

    if ($debug)
    {
        ::userDisplay (sprintf "        The SPTE ptr is:   %X\n" , $SPTE_ptr);
        #::userDisplay (sprintf
        #"      getPhyAddrfromSPTE: The index is:   %X\n\n" ,$index);

        #::userDisplay (sprintf
        #"      getPhyAddrfromSPTE: The SPTE index is:   %X\n\n" , $spteindex);

        ::userDisplay (sprintf "        The SPTE entry contents is:   %X\n" ,
               $SPTE_entry);
    }

    # if found present
    if ($SPTE_entry & 0x00000800)
    {
        my $addrmask = 0xFFFFF000;

        my $SPTEaddr = $SPTE_entry & $addrmask;

        my $addrOffset = ($vaddr - $block_base_addr)%4096;

        $paddr = $SPTEaddr + $addrOffset;

        if (0 == $isPhysical)
        {
            # add the HRMOR value to get the actual physical address
            $paddr += ::getHRMOR();
        }
        # mark address as bypassing HRMOR translation.
        $paddr |= 0x8000000000000000;
    }
    else
    {
        $paddr = NotPresent;
    }

    if ($displaySPTE)
    {
        Hostboot::_DebugFrameworkVMM::displaySPTE($vaddr, $SPTE_entry);
    }


    return $paddr;

}


# @sub getPhysicalAddr
#
# Find the physical address in the VMM from a VA passed in.
#
# @param address we are looking for
# @param debug var to indicate debug mode (1 = debug on)
# @return physical address
#
sub getPhysicalAddr
{
    my $vaddr = shift;
    my $debug = shift;
    my $displaySPTE = shift;

    my $phyAddr = NotFound;

    # Determine the index into the segment list
    my $segmentIndex = $vaddr >> 40;

    #if ($debug)
    #{
    #    ::userDisplay (sprintf "   stackIndex = :   %X\n" , $segmentIndex);
    #}

    # Get the device segment address
    my @segment_manager_addr =
      ::findSymbolAddress("Singleton<SegmentManager>::instance()::instance");


    if (not defined @segment_manager_addr)
    {
        ::userDisplay "   VirtualToPhy: Cannot find SegmentManager symbol.\n";
        return NotFound;
    }


    # if the stack index equal 0..then the address is part of the base segment
    if ($segmentIndex == 0)
    {
        if ($debug)
        {
            ::userDisplay"   In BASE SEGMENT address range\n\n";
        }

        my $base_segment_addr = ::read64 ($segment_manager_addr[0], 8);

        my $block_ptr = ::read64 ($base_segment_addr + BASESEGMENT_BLOCK_OFFSET, 8);


        # check that we have a valid block pointer..
        if ($block_ptr != 0)
        {
            if ($debug)
            {
                ::userDisplay (sprintf "   Base Segment symbol address:   %X\n"
                               , $base_segment_addr);

                ::userDisplay (sprintf "   Base Segment block_ptr:   %X\n" ,
                               $block_ptr);

            }

            #Call function to get the correct block for the VA
            my $block_ptr = Hostboot::_DebugFrameworkVMM::findBlock($block_ptr,
                                                                    $vaddr,
                                                                    $debug);


            #if ($debug)
            #{
            #    ::userDisplay (sprintf "   Block ptr:   %X\n" , $block_ptr);
            #}

            if ($block_ptr == 0)
            {
                ::userDisplay (sprintf
                               "   VirtualToPhy: Did not find a block for v addr:   %X\n" , $vaddr);
                return NotFound;

            }

            # get the physical address from SPTE entry in this block
            # pass the block pointer, Virtual address and debug flag..
            # if debug is on we print more detail about the entry
            $phyAddr =
              Hostboot::_DebugFrameworkVMM::getPhyAddrfromSPTE($block_ptr,
                                                               $vaddr, $debug,
                                                               $displaySPTE);

        }
        else
        {
            ::userDisplay
              "   VirtualToPhy:  BaseSegment - no valid pointer... Have you run yet?\n\n";
            return NotFound;
        }
    }
    elsif ($segmentIndex == 1)
    {

        if ($debug)
        {
            ::userDisplay"   In STACK SEGMENT Range\n\n";
        }

        my $stack_segment_addr = ::read64 ($segment_manager_addr[0] +
                                           SEGMGR_STACK_SEGMENT_OFFSET, 8);


        # get the pointer to the first segment..
        my $firststackptr = ::read64 ($stack_segment_addr +
                                      STACKSEGMENT_FIRST_STACK_OFFSET, 8);


        if ($firststackptr == 0)
        {
            ::userDisplay
              "   VirtualToPhy:  No Stack Pointer. Have you run yet?\n";
            return NotFound;

        }

        if ($debug)
        {
            ::userDisplay (sprintf "   Segment symbol address=%X\n" ,
                           $stack_segment_addr);

            ::userDisplay (sprintf "   Stackheadptr=%X\n" , $firststackptr);
        }

        my $stackptr = 0;

        #Call function to get the correct block for the VA
        $stackptr = Hostboot::_DebugFrameworkVMM::findStack($firststackptr,
                                                            $vaddr, $debug);


        if ($stackptr == 0)
        {
            ::userDisplay (sprintf
                           "   VirtualToPhy:Did not find a stack for v addr:   %X\n" , $vaddr);

            return NotFound;
        }

        my $firstblockptr = ::read64 ($stackptr + STACK_BLOCKPTR_OFFSET, 8);

        if ($firstblockptr == 0)
        {
            ::userDisplay "   No BlockPtr found.\n";
            return NotFound;
        }

        #Call function to get the correct block for the VA
        my $block_ptr = Hostboot::_DebugFrameworkVMM::findBlock($firstblockptr,
                                                                $vaddr, $debug);


        #if ($debug)
        #{
        #   ::userDisplay (sprintf "   Block ptr=%X\n\n" , $block_ptr);
        #}

        if ($block_ptr == 0)
        {
            ::userDisplay (sprintf
                           "   VirtualToPhy: Did not find a block for v addr:   %X\n" , $vaddr);

            return NotFound;
        }

        # get the physical address from SPTE entry in this block
        # pass the block pointer, Virtual address and debug flag.. if debug
        # is on we print more detail about the entry
        $phyAddr = Hostboot::_DebugFrameworkVMM::getPhyAddrfromSPTE($block_ptr,
                                                                    $vaddr,
                                                                    $debug,
                                                                    $displaySPTE);

    }

    # there are a max number of 16 segments allowed.. But we currently only propogate
    # 2-10 in the code.. But leaving the full range in here in case that changes.
    elsif (($segmentIndex > 1) && ($segmentIndex < 16))
    {
        if ($debug)
        {
            ::userDisplay"   In DEVICE SEGMENT Range\n\n";
        }

        # Get the pointer to the specific device segment
        my $deviceSegmentPtr = ::read64 ($segment_manager_addr[0] +
                                         (8*$segmentIndex), 8);


        # check to see that we have a valid segment ptr - if not print error
        if ($deviceSegmentPtr != 0)
        {
            my $segmentbaseaddr = ::read64($deviceSegmentPtr +
                                           DEVICESEGMENT_BASEADDR_OFFSET , 8);


            my $segment_ea = $vaddr - $segmentbaseaddr;

            my $terabyte = 1024*1024*1024*1024;

            my $idx = $segment_ea / ($terabyte / 32);

            if ($idx < 32)
            {
                my $segmentDevBlckAddr =::read64($deviceSegmentPtr +
                                                 DEVICESEGMENT_BLOCK_OFFSET
                                                 +(16*$idx), 8);

                my $segmentSize =::read64($deviceSegmentPtr +
                                          DEVICESEGMENT_BLOCK_SIZE +(16*$idx),
                                          8);

                if ($debug)
                {

                    ::userDisplay
                      (sprintf"      VirtualToPhy: Device Segment base Vaddress=%X\n" , $segmentbaseaddr);

                    ::userDisplay (sprintf"      segment_EA = %X\n" , $segment_ea);
                    ::userDisplay (sprintf"      mmio index = %X\n" , $idx);
                    ::userDisplay
                      (sprintf"      VirtualToPhy: Segment DeviceBlock Phy address = %X\n" , $segmentDevBlckAddr);

                    ::userDisplay (sprintf "      VirtualToPhy: Segment size = %X\n" , $segmentSize);
                }

                if ($segmentDevBlckAddr != 0)
                {
                    my $deviceoffset = $segment_ea - ($idx * ($terabyte / 32));

                    if ($debug)
                    {
                        ::userDisplay (sprintf "      device offset = %X\n" , $deviceoffset);
                    }

                    $phyAddr = $segmentDevBlckAddr + $deviceoffset;
                }
                else
                {
                    ::userDisplay ("  \n   Physical address equals 0\n");
                }
            }
            else
            {
                ::userDisplay "  Bad index.. address is not right.\n";
                return NotFound;
            }
        }
        else
        {
            ::userDisplay ("  \n   No valid Device pointers. Have you run yet? \n");
        }
    }
    else
    {
        ::userDisplay ("  \nVirtualToPhy: ERROR.. VA Address is out of range.\n");
    }

    if ($debug)
    {
        if (($phyAddr eq Hostboot::_DebugFrameworkVMM::NotFound) ||
            ($phyAddr eq Hostboot::_DebugFrameworkVMM::NotPresent))
        {
            ::userDisplay ("\n    The Physical Address = $phyAddr\n");
        }
        else
        {
            ::userDisplay (sprintf "\n   The Physical Address =  %X\n\n" , $phyAddr);
        }
    }

    return $phyAddr;
}




# @sub printBaseSegment
#
# Print out info on the base segment
#
# @param Address of the base segment
#
sub printBaseSegment
{
    my $base_segment_addr = shift;

    #::userDisplay (sprintf "    printBaseSegment: baseAddr:   %X\n" ,$base_segment_addr);

    # base segment address is 8 bytes (after Virtual Function Table ptr)
    my $seg_base_addr =
      ::read64 $base_segment_addr+BASESEGMENT_BASEADDR_OFFSET;

    my $seg_phys_size =
      ::read64 ($base_segment_addr + BASESEGMENT_PHY_SIZE_OFFSET, 8);

    ::userDisplay("   Base Segment Info:  \n");
    ::userDisplay (sprintf "   Base   Address:   %X\n" , $seg_base_addr);

    #::userDisplay"    isBaseSegment:  BaseSegment phys size:   $seg_phys_size\n";

    #::userDisplay (sprintf "   printBaseSegment: phys size:   %X\n" ,$seg_phys_size);


    my $blockPtr =  ::read64 $base_segment_addr+BASESEGMENT_BLOCK_OFFSET;

    ::userDisplay (sprintf "   Block Ptr =:   %X\n" , $blockPtr);

    printBlock($blockPtr);

}

# @sub printStackSegment
#
# Print out info on the stack segment passed in
#
# @param Address of the Stack we need to work with
#
sub printStackSegment
{
    my $stackptr = shift;
    my $i = 0;

    #::userDisplay (sprintf "   printStackSegment:  Base Ptr  %X\n" , $stackptr);

    while($stackptr != 0)
    {
        ::userDisplay (sprintf "\n   StackSegment[%X]\n" , $i);

        ::userDisplay"   --------------\n";
        my $Megabyte = 1024*1024;

        my $localkey = ::read64 ($stackptr + STACK_KEY_OFFSET, 8);
        ::userDisplay (sprintf "   StackKey:   %X\n" , $localkey);

        my $taskId = ($localkey - (1024*1024*$Megabyte))/ (8*$Megabyte);
        ::userDisplay (sprintf "   taskId:   %X\n" , $taskId);

        my $bottomOffset = (64 + 128 * ($taskId % 61)) * 1024;
        #::userDisplay (sprintf "   bottomOffset:   %X\n" , $bottomOffset);

        my $topOffset = $bottomOffset + (256 * 1024) - 8;
        #::userDisplay (sprintf "   topOffset:   %X\n" , $topOffset);

        # my $topAddr = $stackkey + $bottomOffset;
        my $topAddr = $localkey + $topOffset;

        #::userDisplay (sprintf "   topAddr:   %X\n" , $topAddr);

        ::userDisplay (sprintf "   STACK topAddr:   %X\n" , $topAddr);

        my $bottomAddr = $localkey + $bottomOffset;
        ::userDisplay (sprintf "   STACK bottomAddr:   %X\n" , $bottomAddr);

        # need to print the block information from here too..

        printBlock(::read64 ($stackptr + STACK_BLOCKPTR_OFFSET, 8));

        $stackptr = ::read64 ($stackptr + STACK_NEXT_STACK_OFFSET, 8);

        $i = $i + 1;
    }

}


# @sub printBlock
#
# Given a block and an address, find the block the address
# is part of.
#
# @param Ptr to the first block
# @param address we are looking for
#
sub printBlock
{

    my $block_ptr = shift;
    my $i = 0;

    while ($block_ptr != 0)
    {
        ::userDisplay (sprintf "\n      *Block[%X]\n" , $i);

        #Get the base address of the block
        #my $block_base_addr =  ::read64 ($block_ptr, 8);

        ::userDisplay (sprintf "        Block Base Address:   %X\n" ,::read64
                       ($block_ptr + BLOCK_BASE_ADDR, 8));


        ::userDisplay (sprintf "        Block Size:   %X\n" ,::read64
                       ($block_ptr + BLOCK_SIZE_OFFSET, 8));


        my $next_block_ptr =  ::read64 ($block_ptr + BLOCK_NEXTPTR_OFFSET, 8);

        #::userDisplay (sprintf "        Next Block Pointer:   %X\n" , $next_block_ptr);
        ::userDisplay (sprintf "        SPTE entry:   %X\n" , ::read64
                       ($block_ptr + BLOCK_SPTE_OFFSET, 8));


        my $pages = (::read64 ($block_ptr + 8, 8)) / 4096;

        my $presentcount =
          Hostboot::_DebugFrameworkVMM::getNumPresentPages(::read64 ($block_ptr
                                                                     +
                                                                     BLOCK_SPTE_OFFSET, 8), $pages);

        ::userDisplay"          SPTE Entries:  ";
        ::userDisplay (sprintf "Total=%d" , $pages);
        ::userDisplay (sprintf " Present=%d\n" , $presentcount);

        $block_ptr = $next_block_ptr;

        $i = $i+1;
    }

return 0;
}


# @sub getNumPresentPages
#
# Find the number of SPTE entries that are present.
#
# @param Address of the SPTE entry
#
sub getNumPresentPages
{
    my $SPTE_ptr = shift;
    my $pages = shift;

    my $presentcount = 0;

    my $i = 0;

    while( $i<$pages)
    {
        my $SPTE_entry = ::read32 ($SPTE_ptr + (4*$i), 4);

        # if found present
        if ($SPTE_entry & 0x00000800)
        {

#::userDisplay(sprintf"      getPhyAddrfromSPTE:   FOUND PRESENT The SPTE entry:   %X\n\n" , $SPTE_entry);

            $presentcount++
        }

        $i = $i+1;
    }

    return $presentcount;

}


# @sub printDeviceSegments
#
# Pass in a pointer to the address of the  first device segment.
#  This routine loops through all device segments and prints out
#  their info.
#  In addition each individual device segment could have
#  up to 32 mmio devices populated so this routine will print
#  out those as well.
#
# @param Ptr to the Address of the First Device segment
#        we need to work with from the segment manager
#
sub printDeviceSegments
{
    my $firstdevicesegmentaddr = shift;
    my $i = 0;

   # ::userDisplay (sprintf "   stack address:  Base Ptr  %X\n" ,
   #                $firstdevicesegmentaddr);


    my $maxdevices = 14;

    my $curdevice = 0;

    # loop through all possible devices.. up to max which is 14
    while ($curdevice < $maxdevices)
    {
        my $deviceSegmentPtr =::read64 ($firstdevicesegmentaddr + (8 *
                                                                   $curdevice),
                                        8);


        #  ::userDisplay (sprintf "   devicesegmentPtr:  Base Ptr  %X\n" ,
        #                 $deviceSegmentPtr);

        my $segmentbaseaddr =::read64($deviceSegmentPtr +
                                      DEVICESEGMENT_BASEADDR_OFFSET, 8);

        # If the device segment is valid, then print out its info and
        # check for MMIO devices populated.
        if ($deviceSegmentPtr != 0)
        {
            #::userDisplay (sprintf "   segmentbaseaddr:  %X\n" , $segmentbaseaddr);
            if($segmentbaseaddr != 0)
            {

                ::userDisplay (sprintf "\n     DeviceSegment[%X]\n" ,
                               $curdevice);

                ::userDisplay"     ---------------\n";
                ::userDisplay (sprintf "       Base VAddress:   %X\n" ,
                               $segmentbaseaddr);


                my $mmiostructptr = $deviceSegmentPtr +
                  DEVICESEGMENT_BLOCK_OFFSET;

                my $maxmmiodevices = 32;
                my $curmmiodevice = 0;

                # loop through all mmio devices max of 32 per device segment.
                while($curmmiodevice < $maxmmiodevices)
                {
                    my $segmentPhyAddr =::read64($mmiostructptr
                                            + $curmmiodevice*MMIO_STRUCT_SIZE
                                            + MMIO_STRUCT_SEGADDR_OFFSET, 8);

                    my $segmentSize =::read64($mmiostructptr
                                            + $curmmiodevice*MMIO_STRUCT_SIZE
                                            + MMIO_STRUCT_SEGSIZE_OFFSET, 8);
                    use bigint;

                    # DeviceSegment::devSegData.no_ci
                    my $no_ci = (   ($segmentSize & MMIO_STRUCT_NO_CI_MASK)
                                 == MMIO_STRUCT_NO_CI_MASK);

                    # DeviceSegment::devSegData.guarded
                    my $guarded = (   ($segmentSize & MMIO_STRUCT_GUARDED_MASK)
                                == MMIO_STRUCT_GUARDED_MASK);

                    # Segment size is a 62 bit quantity.
                    # DeviceSegment::devSegData.size
                    $segmentSize = ($segmentSize & MMIO_STRUCT_SIZE_MASK);

                    if ($segmentPhyAddr != 0)
                    {

                        ::userDisplay (sprintf "\n        *MMIOdevice[%X]\n" ,
                                       $curmmiodevice);

                        ::userDisplay (sprintf
                                       "          MMio device Phy Address:   %X\n" , $segmentPhyAddr);

                        ::userDisplay (sprintf
                                       "          MMio Device Size:   %X\n" ,
                                       $segmentSize);
                        ::userDisplay (sprintf
                                       "          MMio no_ci flag:   %u\n" ,
                                       $no_ci);
                        ::userDisplay (sprintf
                                       "          MMio guarded flag:   %u\n" ,
                                       $guarded);
                    }

                    $curmmiodevice = $curmmiodevice + 1;
                }

            }
        }
        $curdevice = $curdevice + 1;
    }

}

1;

__END__
