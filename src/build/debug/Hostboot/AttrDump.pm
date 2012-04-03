
use strict;

package Hostboot::AttrDump;
use Exporter;
our @EXPORT_OK = ('main');
require Hostboot::CallFunc;

sub main
{
    my ($packName,$args) = @_;

    # Parse 'debug' option.
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    # Parse 'force' argument.
    my $force = 0;
    if (defined $args->{"force"})
    {
        $force = 1;
    }

    # Parse 'trace' argument.
    my $trace = (::findSymbolAddress("TARGETING::g_trac_targeting"))[0];
    if (defined $args->{"trace"})
    {
        $trace = (::findSymbolAddress($args->{"trace"}))[0];
    }
    if( $debug )
    {
        my $tmp2 = $args->{"trace"};
        ::userDisplay("\ntrace: $trace ($tmp2)\n");
    }

    # Parse 'target' argument.
    my $huid = 0; # dump all targets
    if (defined $args->{"huid"})
    {
        $huid = hex($args->{"huid"});
    }
    if( $debug )
    {
        ::userDisplay("huid: $huid\n");
    }

    my @dumpparms;
    push( @dumpparms, $trace );
    push( @dumpparms, $huid );
    Hostboot::CallFunc::execFunc( "TARGETING::dumpAllAttributes2(trace_buf_head**, unsigned int)", $debug, $force, \@dumpparms );

    return 0;
}

sub helpInfo
{
    my %info = (
        name => "AttrDump",
        intro => ["Dumps all Attributes to trace."],
        options => {
                    "huid" =>  ["HUID of target to dump (default is to dump all targets)."],
                    "trace" => ["Trace buffer to use (default=g_trac_targ)."],
                    "force" => ["Run command even if state does not appear correct."],
                    "debug" => ["More debug output."],
                   },
    );
}
