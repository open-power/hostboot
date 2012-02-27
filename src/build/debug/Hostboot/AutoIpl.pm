#!/usr/bin/perl

use strict;

package Hostboot::AutoIpl;
use Exporter;
our @EXPORT_OK = ('main');

use constant PRINTK_SAMPLING => 50;
use constant NUM_CLOCK_CYCLES => 25000;
use constant MAX_NUM_CONT_TRACE_CTL_STRUCT => 2;
use constant CONT_TRACE_CTL_STRUCT_SIZE => 16;
use constant CONT_TRACE_DISABLE_FLAG_OFFSET => MAX_NUM_CONT_TRACE_CTL_STRUCT * CONT_TRACE_CTL_STRUCT_SIZE;

use File::Temp ('tempfile');

sub main
{
    my ($packName,$args) = @_;
    #userDisplay("args fsp-trace ".$args->{"fsp-trace"}."\n");
    #userDisplay("args with-file-names ".$args->{"with-file-names"}."\n");
    #userDisplay("args num-clk-cycles ".$args->{"num-clk-cycles"}."\n");

    # Ensure environment is in the proper state for running instructions.
    if (!::readyForInstructions())
    {
        ::userDisplay "Cannot execute while unable to run instructions.\n";
        return;
    }

    # retrieve the Information of the Continous Trace Trigger Info structure
    my ($symAddr, $symSize) =
                      ::findSymbolAddress("TRACE::g_cont_trace_trigger_info");
    if (not defined $symAddr)
    {
         ::userDisplay "Cannot find symbol.\n"; die;
    }

    my $disable = 0;
    if (defined $args->{"enable-cont-trace"})
    {
        #my $disable = ::read64($symAddr + CONT_TRACE_DISABLE_FLAG_OFFSET);
        #::userDisplay("Cont Trace Disable Flag read = $disable\n");
        ::write64($symAddr + CONT_TRACE_DISABLE_FLAG_OFFSET, 0);
        #$disable =  ::read64($symAddr + CONT_TRACE_DISABLE_FLAG_OFFSET);
        #::userDisplay("Cont Trace Disable Flag after reset = $disable\n");
        # truncate tracMERG to 0
        system( "cp /dev/null tracMERG" );
        return;
    }
    else
    {
        my $disable = ::read64($symAddr + CONT_TRACE_DISABLE_FLAG_OFFSET);
        #::userDisplay("Cont Trace Disable Flag after reset = $disable\n");
    }

    # set the number of clock cycles
    my $cycles = NUM_CLOCK_CYCLES;
    if (defined $args->{"num-clk-cycles"})
    {
        $cycles = $args->{"num-clk-cycles"};
    }

    # Check if shutdown has been requested
    my $result = ::getShutdownRequestStatus();
    #::userDisplay("shutdown requested: $result\n");

    if ($result)
    {
        ::userDisplay("Shutdown has been reported.\n");
        return;
    }

    # truncate printk.content to 0
    system( "cp /dev/null printk.content" );

    my $loop = 0;
    my $excp = 0;

    while (0 == $result)
    {
        if ( -e 'STOP' )
        {
            return;
        }

        if (::CheckXstopAttn() == 1)
        {
            ::userDisplay("checkstop/attn occur.\n");
            ::FirCheck();
            return;
        }

        $loop++;

        # Display printk buffer's unshown messages
        if (($loop % PRINTK_SAMPLING) == 0)
        {
            system("hb-printk --mute > /dev/null");
            system("diff hb-Printk.output printk.content | sed -e 's/< //g' -e '1d'");
            system("mv hb-Printk.output printk.content");
        }

        # run clock cycles
        ::executeInstrCycles($cycles,1);

        # Display CIA 
        my $pc = ::getCIA();
        ::userDisplay("Loop $loop: $pc");

        # Check for exception
        if ($pc =~ m/.*0x0000000000000E4[04]/)
        {
            $excp++;
            if ($excp == 5)
            {
                ::userDisplay("Trapped in the exception loop.\n");
                return;
            }
        }
        else
        {
            $excp = 0;
        }
            
        if ($disable == 0)
        {
            # collect continuous traces
            system("hb-ContTrace --mute > /dev/null");
            system("cat hb-ContTrace.output >> tracMERG");
        }

        # check if shutdown has been requested
        $result = ::getShutdownRequestStatus();
        #::userDisplay("shutdown requested: $result\n");
    }

    if ($disable == 0)
    {
        # First, collect continuous traces from any triggered buffer
        system("hb-ContTrace --mute > /dev/null");
        system("cat hb-ContTrace.output >> tracMERG");
        # Now, collect the partial continuous traces from untriggered buffer
        system("hb-ContTrace --mute --last > /dev/null");
        system("cat hb-ContTrace.output >> tracMERG");
    }

    #::userDisplay("\n\n Hostboot has shutdown\n\n");

}

sub helpInfo
{
    my %info = (
        name => "AutoIpl",
        intro => ["IPL Hostboot and collect continuous trace."],
        options => {
                    "fsp-trace=<path>" => ["Path to non-default fsp-trace utility."],
                    "with-file-names" => ["Trace statements will include file name of place the",
                                          "trace was defined."],
                    "num-clk-cycles=<number>" => ["Number of clock cycles to before collecting traces."],
                    "enable-cont-trace" => ["Turn on continuous trace"],
                   },
    );
}
