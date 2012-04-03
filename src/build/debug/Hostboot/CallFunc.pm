#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/CallFunc.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011 - 2012
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
#  IBM_PROLOG_END
use strict;

package Hostboot::CallFunc;
use Exporter;
our @EXPORT_OK = ('main');

use constant CALLFUNC_DEBUG_READY_OFFSET => 0;
use constant CALLFUNC_DEBUG_RUNNING_OFFSET => CALLFUNC_DEBUG_READY_OFFSET + 1;
use constant CALLFUNC_DEBUG_COMPLETE_OFFSET => CALLFUNC_DEBUG_READY_OFFSET + 2;
use constant CALLFUNC_DEBUG_ENTRY_OFFSET => CALLFUNC_DEBUG_READY_OFFSET + 8;
use constant CALLFUNC_DEBUG_RETVAL_OFFSET => CALLFUNC_DEBUG_ENTRY_OFFSET + 8;
use constant CALLFUNC_DEBUG_PARMS_OFFSET => CALLFUNC_DEBUG_RETVAL_OFFSET + 8;
use constant CALLFUNC_DEBUG_PARMS => 8;
sub main
{
    my ($packName,$args) = @_;

    # Parse 'debug' option.
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    # Parse function name from options.
    my $function = "";
    if (defined $args->{"function"})
    {
        $function = $args->{"function"};
    }
    elsif (defined $args->{"func"})
    {
        $function = $args->{"func"};
    }
    else
    {
        ::userDisplay "Must give a function to execute.\n";
        return;
    }

    # Parse function arguments from options.
    my @parms = ();
    my $parms_string = "";
    if (defined $args->{"arguments"})
    {
        $parms_string = $args->{"arguments"}
    }
    elsif (defined $args->{"args"})
    {
        $parms_string = $args->{"args"};
    }
    elsif (defined $args->{"parameters"})
    {
        $parms_string = $args->{"parameters"};
    }
    elsif (defined $args->{"parms"})
    {
        $parms_string = $args->{"parms"};
    }
    @parms = map eval, split /,/, $parms_string;

    # Parse 'force' argument.
    my $force = 0;
    if (defined $args->{"force"})
    {
        $force = 1;
    }

    my $error = execFunc( $function, $debug, $force, @parms );
    if( $error )
    {
       return;
    }
}

sub execFunc
{
    my $function = shift;
    my $debug = shift;
    my $force = shift;
    my $parms_arg = shift;
    my @parms = @{$parms_arg};

    if( $debug )
    {
        ::userDisplay("function = $function.\n");
        my $tmparg;
        foreach $tmparg (@parms)
        {
            ::userDisplay("arg = $tmparg.\n");
        }
    }

    # Ensure environment is in the proper state for running instructions.
    if (!::readyForInstructions())
    {
        ::userDisplay "Cannot execute while unable to run instructions.\n";
        return 1;
    }

    # Find symbol's TOC address.
    my $toc = ::findSymbolTOCAddress($function);
    if ($debug)
    {
        ::userDisplay("Symbol $function TOC at $toc.\n");
    }

    # Find interactive debug structure in the kernel.
    my $address = (::findSymbolAddress("CpuManager::cv_interactive_debug"))[0];

    if ((not defined $toc) || (not defined $address))
    {
        ::userDisplay "Cannot find symbol to execute $function.\n";
        return 1;
    }

    # Verify kernel isn't busy with an outstanding request.
    if ((0 != ::read16 ($address + CALLFUNC_DEBUG_READY_OFFSET)) &&
        (0 == $force))
    {
        ::userDisplay "Another command is still pending.\n";
        return 1;
    }

    # Write entry point (function TOC) and parameters into debug structure.
    ::write64(($address + CALLFUNC_DEBUG_ENTRY_OFFSET), $toc);
    while(($#parms + 1) != CALLFUNC_DEBUG_PARMS)
    {
        push @parms, 0x0;
    }
    my $i = 0;
    while ($i != CALLFUNC_DEBUG_PARMS)
    {
        if ($debug)
        {
            ::userDisplay "Param $i = ".$parms[$i]."\n";
        }
        ::write64(($address + CALLFUNC_DEBUG_PARMS_OFFSET + 8*$i), $parms[$i]);
        $i = $i + 1;
    }

    # Set ready state.
    ::write32(($address + CALLFUNC_DEBUG_READY_OFFSET), 0x01000000);

    # Clock forward until kernel marks 'complete' state.
    my $i = 0;
    while((0 != ::read16($address + CALLFUNC_DEBUG_READY_OFFSET)) &&
          (0 == ::read8($address + CALLFUNC_DEBUG_COMPLETE_OFFSET)) &&
          ($i < 50))
    {
        ::executeInstrCycles(100000);
        $i = $i + 1;
        if ($debug)
        {
            ::userDisplay("Loop $i.\n");
        }
    }

    # Verify successful execution ('complete' state set).
    if (0 == ::read8($address + CALLFUNC_DEBUG_COMPLETE_OFFSET))
    {
        ::userDisplay "Command failed to complete.\n";
        return 1;
    }
    
    # Display return value.
    ::userDisplay ::read64($address + CALLFUNC_DEBUG_RETVAL_OFFSET)."\n";
}

sub helpInfo
{
    my %info = (
        name => "CallFunc",
        intro => ["Interactively execute a function."],
        options => {
                    "function='function name'" => ["Function to execute."],
                    "arguments=arg0,arg1..." =>["List of arguments to pass function."],
                    "force" => ["Run command even if state does not appear correct."],
                   },
        notes => ["func can be used as a short-name for 'function'.",
                  "args, parameters, or parms can be used as a short-name for arguments."]
    );
}

