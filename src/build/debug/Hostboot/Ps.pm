#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Ps.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2015
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

use Hostboot::VirtToPhys;

package Hostboot::Ps;
use Exporter;
our @EXPORT_OK = ('main');

use constant PS_TASKMGR_SYMBOLNAME =>
                "Singleton<TaskManager>::instance()::instance";
use constant PS_TASKMGR_TRACKER_LIST_OFFSET => 8 * 4;
use constant PS_TRACKER_LIST_HEAD_OFFSET => 0;
use constant PS_TRACKER_LIST_TAIL_OFFSET => 8 + PS_TRACKER_LIST_HEAD_OFFSET;
use constant PS_TRACKER_LIST_SIZE => 8 * 3;

use constant PS_TRACKER_PREV_OFFSET => 0;
use constant PS_TRACKER_NEXT_OFFSET => 8 + PS_TRACKER_PREV_OFFSET;
use constant PS_TRACKER_PARENT_OFFSET => 8 + PS_TRACKER_NEXT_OFFSET;
use constant PS_TRACKER_CHILDREN_LIST_OFFSET => 8 + PS_TRACKER_PARENT_OFFSET;
use constant PS_TRACKER_TID_OFFSET =>
                PS_TRACKER_CHILDREN_LIST_OFFSET + PS_TRACKER_LIST_SIZE;
use constant PS_TRACKER_TASK_OFFSET => 8 + PS_TRACKER_TID_OFFSET;
use constant PS_TRACKER_STATUS_OFFSET => 8 + PS_TRACKER_TASK_OFFSET;
use constant PS_TRACKER_RETVAL_OFFSET => 8 + PS_TRACKER_STATUS_OFFSET;
use constant PS_TRACKER_WAITINFO_OFFSET => 8 + PS_TRACKER_RETVAL_OFFSET;
use constant PS_TRACKER_ENTRYPOINT_OFFSET => 8 + PS_TRACKER_WAITINFO_OFFSET;

use constant PS_TASK_STATE_OFFSET => 8*43;
use constant PS_TASK_STATEEXTRA_OFFSET => 8 + PS_TASK_STATE_OFFSET;

use bigint;

sub main
{
    my ($packName,$args) = @_;

    my $withBacktrace = 0;
    if(defined $args->{"with-backtrace"})
    {
        $withBacktrace = 1;
    }

    # Find symbol containing kernel list of task objects.
    #   (Tasks who's parent is the kernel)
    my ($symAddr, $symSize) = ::findSymbolAddress(PS_TASKMGR_SYMBOLNAME);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find ".PS_TASKMGR_SYMBOLNAME;
        die;
    }

    # Pass address of list to 'displayList' function.
    $symAddr += PS_TASKMGR_TRACKER_LIST_OFFSET;
    displayList($symAddr,0,$withBacktrace);
}

# @sub displayStackTrace
#
# Displays a task's stack trace, including frame number, symbol, offset within
# symbol
#
# @param[in] i_taskAddr Task address
# @param[in] i_level Level of indent for stack trace
#
sub displayStackTrace
{
    my ( $i_taskAddr, $i_level ) = @_;

    my $off = 0;

    # Knobs for the VMM package
    my $vmmDebug = 0;
    my $vmmDisplaySPTE = 0;
    my $vmmQuiet = 1;

    use constant FRAME_TO_LR_OFFSET => 16;
    use constant MAX_STACK_FRAMES => 25;

    # Read in the task struct, which mirrors struct task_t in Hostboot
    # d prefix means "display", i.e. "dstack_ptr" is the display version of
    # "stack_ptr".  d-prefixed values are not part of task_t
    my %task = ();
    $task{cpu} = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{stack_ptr} = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{dstack_ptr} = sprintf "0x%X", $task{context_t}{stack_ptr};
    $task{context_t}{nip} = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{dnip} = sprintf "0x%X",$task{context_t}{nip};

    foreach(my $gpr=0; $gpr<32; ++$gpr)
    {
        $task{context_t}{"gprs$gpr"} =
           ::read64($i_taskAddr + $off); $off+=8;
        $task{context_t}{"dgprs$gpr"} =
            sprintf "0x%X",$task{context_t}{"gprs$gpr"};

        # For now, only interpret gpr1 as a virtual address having to be
        # converted to a physical address.  This gives the frame pointer
        if($gpr==1)
        {
            $task{context_t}{"pgprs$gpr"}
                = Hostboot::_DebugFrameworkVMM::getPhysicalAddr(
                    $task{context_t}{"gprs$gpr"}, $vmmDebug, $vmmDisplaySPTE,
                    $vmmQuiet);
            $task{context_t}{"dpgprs$gpr"} =
                sprintf "0x%x",$task{context_t}{"pgprs$gpr"} ;
        }
    }

    $task{context_t}{lr} = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{dlr} = sprintf "0x%X",$task{context_t}{lr} ;
    $task{context_t}{cr}              = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{ctr}             = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{xer}             = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{msr_mask}        = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{fp_context}      = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{tid}             = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{affinity_pinned} = ::read64($i_taskAddr + $off); $off+=8;
    $task{context_t}{state}           = ::read8( $i_taskAddr + $off); $off+=1;

    # At this point we cached the whole task struct, for any later application.
    # Now dump the stack trace

    my $curFrame = $task{context_t}{"pgprs1"} ;
    my $curLinkReg = $task{context_t}{lr};
    my ($entryPointName, $symOff) = ::findSymbolWithinAddrRange($curLinkReg);

    my $prefix = makeTabs($i_level);

    print sprintf("%s     F[%02d]: %s : 0x%08X\n",
        $prefix, 0, $entryPointName,$symOff);

    for(my $i=0; $i<MAX_STACK_FRAMES; ++$i)
    {
        my $nextFrame = ::read64($curFrame);
        my $linkReg = ::read64($curFrame + FRAME_TO_LR_OFFSET);

        $nextFrame = Hostboot::_DebugFrameworkVMM::getPhysicalAddr(
            $nextFrame, $vmmDebug, $vmmDisplaySPTE,$vmmQuiet);
        if (   ($nextFrame eq Hostboot::_DebugFrameworkVMM::NotFound)
            || ($nextFrame eq Hostboot::_DebugFrameworkVMM::NotPresent))
        {
            last;
        }

        ($entryPointName,$symOff) = ::findSymbolWithinAddrRange($linkReg);

        if($i!=0)
        {
            if($entryPointName eq "UNKNOWN")
            {
                last;
            }
            print sprintf("%s     F[%02d]: %s : 0x%08X\n",
                $prefix, $i, $entryPointName,$symOff);
        }

        $curFrame = $nextFrame;
    }

    print $prefix . "\n";
}

# Display a list of task objects.
sub displayList
{
    my ($listAddr, $level, $withBacktrace) = @_;

    my $firstDisplayed = 0;

    # Task lists are FIFO, so start from the 'tail'.
    my $node = ::read64(PS_TRACKER_LIST_TAIL_OFFSET + $listAddr);
    while (0 != $node)
    {
        if ($firstDisplayed)
        {
            ::userDisplay makeTabs($level)."\n";
        }
        else
        {
            $firstDisplayed = 1;
        }

        # Display tracker object for this node.
        displayTracker($node, $level, $withBacktrace);
        # Follow pointer to the next node.
        $node = ::read64(PS_TRACKER_PREV_OFFSET + $node);
    }
}

sub displayTracker
{
    my ($trackAddr, $level, $withBacktrace) = @_;

    # Read TID.
    my $tid = ::read16(PS_TRACKER_TID_OFFSET + $trackAddr);

    # Determine entry-point symbol name / module.
    my $entryPoint = ::read64(PS_TRACKER_ENTRYPOINT_OFFSET + $trackAddr);
    my $entryPointName = ::findSymbolByAddress($entryPoint);
    if (not $entryPointName) { $entryPointName = sprintf "0x%x",$entryPoint; }
    my $moduleName = ::findModuleByAddress($entryPoint);

    # Find task object, read task state if task is still running.
    my $taskAddr = ::read64(PS_TRACKER_TASK_OFFSET + $trackAddr);
    my $state = "";
    if ($taskAddr)
    {
        $state = pack("C",::read8(PS_TASK_STATE_OFFSET + $taskAddr));
    }
    else
    {
        $state = "Z";
    }
    my $stateExtra = "";  # Parse state extra debug info if it exists.
    if (($state ne "R") and ($state ne "r") and
        ($state ne "E") and ($state ne "Z"))
    {
        $stateExtra = sprintf "(0x%x)",
                              ::read64(PS_TASK_STATEEXTRA_OFFSET + $taskAddr);
    }
    elsif ($state eq "Z")
    {
        # If task has exited, read status and retval.
        my $status = ::read32(PS_TRACKER_STATUS_OFFSET + $trackAddr);
        my $retval = ::read64(PS_TRACKER_RETVAL_OFFSET + $trackAddr);
        if ($status) { $stateExtra = "(Crashed)"; }
        elsif ($retval) { $stateExtra = (sprintf "(0x%x)", $retval); }
    }
    # Map state to an verbose description.
    my %states = ( "R" => "Running",
                   "r" => "Ready",
                   "E" => "Ended",
                   "f" => "Block on Futex",
                   "M" => "Block on Message",
                   "u" => "Block on Userspace Request",
                   "s" => "Block on Sleeping",
                   "j" => "Block on Join",
                   "Z" => "Zombie",
                 );
    $state = $states{$state};

    # Display task info obtained.
    ::userDisplay makeTabs($level)."-+ TID $tid   State: $state$stateExtra\n";
    ::userDisplay makeTabs($level)." |     $entryPointName [$moduleName]\n";

    # Display stack trace for each task if specifically requested
    if($withBacktrace)
    {
        displayStackTrace($taskAddr, $level+1);
    }

    # Display list of children tasks.
    displayList($trackAddr + PS_TRACKER_CHILDREN_LIST_OFFSET, $level + 1);
}

sub makeTabs
{
    my $level = shift;

    my $result = "";
    while (0 != $level)
    {
        $result = $result." |";
        $level = $level - 1;
    }

    return $result;
}

sub helpInfo
{
    my %info = (
        name => "Ps",
        intro => ["Displays a tree of all tasks and their current state."],
        options => {
                    "with-backtrace" => ["Additionally display backtrace for",
                                         "each task."],
                   },
    );
}
