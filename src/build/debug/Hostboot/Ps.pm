#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Ps.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011-2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
use strict;

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

sub main
{
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
    displayList($symAddr,0);
}

# Display a list of task objects.
sub displayList
{
    my ($listAddr, $level) = @_;

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
        displayTracker($node, $level);
        # Follow pointer to the next node.
        $node = ::read64(PS_TRACKER_PREV_OFFSET + $node);
    }
}

sub displayTracker
{
    my ($trackAddr, $level) = @_;

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
    );
}
