#!/usr/bin/perl -w
#############################################################################
# $IBMCopyrightBlock:
#
# IBM Confidential
#
# Licensed Internal Code Source Materials
#
# IBM HostBoot Licensed Internal Code
#
# (C) Copyright IBM Corp. 2011
#
# The source code for this program is not published or other-
# wise divested of its trade secrets, irrespective of what has
# been deposited with the U.S. Copyright Office.
#$
#############################################################################

#
#       Change History:
#       mww 2011-05-10  simplify for sprint1 - stuff for later is commented out with "##"
#                                       modified from /esw/fips730/Builds/built/tools/x86/cxxtestgen.pl
#                                       (actually this looks the same as the latest on sourceforge)
#
use strict;
use Getopt::Long;

sub usage() {
  print STDERR "Usage: $0 [OPTIONS] <input file(s)>\n";
  print STDERR "Generate test source file for CxxTest.\n";
  print STDERR "\n";
  print STDERR "  -v, --version        Write CxxTest version\n";
  print STDERR "  -o, --output=NAME    Write output to file NAME\n";
##  print STDERR "  --runner=CLASS       Create a main() function that runs CxxTest::CLASS\n";
##  print STDERR "  --gui=CLASS          Like --runner, with GUI component\n";
##  print STDERR "  --error-printer      Same as --runner=ErrorPrinter\n";
##  print STDERR "  --abort-on-fail      Abort tests on failed asserts (like xUnit)\n";
##  print STDERR "  --have-std           Use standard library (even if not found in tests)\n";
##  print STDERR "  --no-std             Don't use standard library (even if found in tests)\n";
##  print STDERR "  --have-eh            Use exception handling (even if not found in tests)\n";
##  print STDERR "  --no-eh              Don't use exception handling (even if found in tests)\n";
##  print STDERR "  --longlong=[TYPE]    Use TYPE as `long long' (defaut = long long)\n";
##  print STDERR "  --template=TEMPLATE  Use TEMPLATE file to generate the test runner\n";
  print STDERR "  --include=HEADER     Include \"HEADER\" in test runner before other headers\n";
##  print STDERR "  --root               Write CxxTest globals\n";
##  print STDERR "  --part               Don't write CxxTest globals\n";
##  print STDERR "  --no-static-init     Don't rely on static initialization\n";
  print STDERR  " --hostboot           customize test for HostBoot()\n";

  exit -1;
}

main();

sub main {
  parseCommandline();
  scanInputFiles();
  writeOutput();
  
}

#
# Handling the command line
#

my ($output, $runner, $gui, $template, $abortOnFail, $haveEh, $noEh, $haveStd, $noStd);
my ($root, $part, $noStaticInit, $longlong, $factor);
my ($hostboot, $debug, $didHBPreamble );     ## new
my @headers = ();

sub parseCommandline() {
  @ARGV = expandWildcards(@ARGV);
  GetOptions( 'version'        => \&printVersion,
              'output=s'       => \$output,
              'template=s'     => \$template,
              'runner=s'       => \$runner,
              'gui=s',         => \$gui,
              'error-printer'  => sub { $runner = 'ErrorPrinter'; $haveStd = 1; },
              'abort-on-fail'  => \$abortOnFail,
              'have-eh'        => \$haveEh,
              'no-eh'          => \$noEh,
              'have-std'        => \$haveStd,
              'no-std'          => \$noStd,
              'include=s'      => \@headers,
              'root'           => \$root,
              'part'           => \$part,
              'no-static-init' => \$noStaticInit,
              'factor'         => \$factor,
              'longlong:s'     => \$longlong,
              'hostboot'       => \$hostboot,
              'debug'          => \$debug
            ) or usage();

  scalar @ARGV or $root or usage();

  if ( defined($noStaticInit) && (defined($root) || defined($part)) ) {
    die "--no-static-init cannot be used with --root/--part\n";
  }

  if ( $gui && !$runner ) {
    $runner = 'StdioPrinter';
  }

  if ( defined($longlong) && !$longlong ) {
    $longlong = 'long long';
  }


  foreach my $header (@headers) {
    if ( !($header =~ m/^["<].*[>"]$/) ) {
      $header = "\"$header\"";
    }
  }
}

sub printVersion() {
  print "This is CxxTest version 3.10.1.\n";
  exit 0;
}

sub expandWildcards() {
  my @result = ();
  while( my $fn = shift @_ ) {
    push @result, glob($fn);
  }
  return @result;
}

#
# Reading the input files and scanning for test cases
#

my (@suites, $suite, $test, $inBlock);
my $numTotalTests = 0;

sub scanInputFiles() {
  foreach my $file (@ARGV) {
    scanInputFile( $file );
  }
  scalar @suites or $root or die("No tests defined\n");
}

sub scanInputFile($) {
  my ($file) = @_;
  open FILE, "<$file" or die("Cannot open input file \"$file\"\n");

  my $line;
  while (defined($line = <FILE>)) {
    scanLineForExceptionHandling( $line );
    scanLineForStandardLibrary( $line );

    scanLineForSuiteStart( $file, $., $line );

    if ( $suite ) {
      if ( lineBelongsToSuite( $suite, $., $line ) ) {
        scanLineForTest( $., $line );
        scanLineForCreate( $., $line );
        scanLineForDestroy( $., $line );
      }
    }
  }
  closeSuite();
  close FILE;
}

sub lineBelongsToSuite($$$) {
  my ($suite, $lineNo, $line) = @_;
  if ( !$suite->{'generated'} ) {
    return 1;
  }

  if ( !$inBlock ) {
    $inBlock = lineStartsBlock( $line );
  }
  if ( $inBlock ) {
    addLineToBlock( $suite->{'file'}, $lineNo, $line );
  }
  return $inBlock;
}

sub scanLineForExceptionHandling($) {
  my ($line) = @_;
  if ( $line =~ m/\b(try|throw|catch|TSM?_ASSERT_THROWS[A-Z_]*)\b/ ) {
    addExceptionHandling();
  }
}

sub scanLineForStandardLibrary($) {
  my ($line) = @_;
  if ( $line =~ m/\b(std\s*::|CXXTEST_STD|using\s+namespace\s+std\b|^\s*\#\s*include\s+<[a-z0-9]+>)/ ) {
    addStandardLibrary();
  }
}

sub scanLineForSuiteStart($$$) {
  my ($fileName, $lineNo, $line) = @_;
  if ( $line =~ m/\bclass\s+(\w+)\s*:\s*public\s+((::)?\s*CxxTest\s*::\s*)?TestSuite\b/ ) {
    startSuite( $1, $fileName, $lineNo, 0 );
  }
  if ( $line =~ m/\bCXXTEST_SUITE\s*\(\s*(\w*)\s*\)/ ) {
    print "$fileName:$lineNo: Warning: Inline test suites are deprecated.\n";
    startSuite( $1, $fileName, $lineNo, 1 );
  }
}

sub startSuite($$$$) {
  my ($name, $file, $line, $generated) = @_;
  closeSuite();
  $suite = { 'name' => $name,
             'file' => $file,
             'line' => $line,
             'generated' => $generated,
             'create' => 0,
             'destroy' => 0,
             'tests' => [],
             'lines' => [] };
}

sub lineStartsBlock($) {
  my ($line) = @_;
  return $line =~ m/\bCXXTEST_CODE\s*\(/;
}

sub scanLineForTest($$) {
  my ($lineNo, $line) = @_;
  if ( $line =~ m/^([^\/]|\/[^\/])*\bvoid\s+([Tt]est\w+)\s*\(\s*(void)?\s*\)/ ) {
    addTest( $2, $lineNo );
  }
}

sub addTest($$$) {
  my ($name, $line) = @_;
  $test = { 'name' => $name,
            'line' => $line };
  push @{suiteTests()}, $test;
}

sub addLineToBlock($$$) {
  my ($fileName, $lineNo, $line) = @_;
  $line = fixBlockLine( $fileName, $lineNo, $line );
  $line =~ s/^.*\{\{//;
  my $end = ($line =~ s/\}\}.*//s);
  push @{$suite->{'lines'}}, $line;
  if ( $end ) {
    $inBlock = 0;
  }
}

sub fixBlockLine($$$) {
  my ($fileName, $lineNo, $line) = @_;
  my $fileLine = cstr($fileName) . "," . $lineNo;
  $line =~ s/\b(E?TSM?_(ASSERT[A-Z_]*|FAIL))\s*\(/_$1($fileLine,/g;
  return $line;
}

sub scanLineForCreate($$) {
  my ($lineNo, $line) = @_;
  if ( $line =~ m/\bstatic\s+\w+\s*\*\s*createSuite\s*\(\s*(void)?\s*\)/ ) {
    addCreateSuite( $lineNo );
  }
}

sub scanLineForDestroy($$) {
  my ($lineNo, $line) = @_;
  if ( $line =~ m/\bstatic\s+void\s+destroySuite\s*\(\s*\w+\s*\*\s*\w*\s*\)/ ) {
    addDestroySuite( $lineNo );
  }
}

sub closeSuite() {
  if ( $suite && scalar @{suiteTests()} ) {
    verifySuite();
    rememberSuite();
  }
  undef $suite;
}

sub addCreateSuite($) {
  $suite->{'createSuite'} = $_[0];
}

sub addDestroySuite($) {
  $suite->{'destroySuite'} = $_[0];
}

sub addExceptionHandling() {
  $haveEh = 1 unless defined($noEh);
}

sub addStandardLibrary() {
  $haveStd = 1 unless defined($noStd);
}

sub verifySuite() {
  if (suiteCreateLine() || suiteDestroyLine()) {
    die("Suite ", suiteName(), "  must have both createSuite() and destroySuite()\n")
      unless (suiteCreateLine() && suiteDestroyLine());
  }
}

sub rememberSuite() {
  push @suites, $suite;
  $numTotalTests += scalar @{$suite->{'tests'}};
}

sub suiteName() { return $suite->{'name'}; }
sub suiteTests() { return $suite->{'tests'}; }
sub suiteCreateLine() { return $suite->{'createSuite'}; }
sub suiteDestroyLine() { return $suite->{'destroySuite'}; }
sub fileName() { return $suite->{'file'}; }
sub fileString() { return cstr(fileName()); }
sub testName() { return $test->{'name'}; }
sub testLine() { return $test->{'line'}; }

sub suiteObject() { return "suite_".suiteName(); }

sub cstr($) {
  my $file = $_[0];
  $file =~ s/\\/\\\\/g;
  return "\"".$file."\"";
}

#
# Writing the test source file
#

sub writeOutput() {
    if ( $hostboot )    {
        writeHostBootOutput();
    }   elsif   ( $template )   {
        writeTemplateOutput();
    } else  {
        writeSimpleOutput();
    }
}

sub startOutputFile() {
  if ( !standardOutput() ) {
    open OUTPUT_FILE,">$output" or die("Cannot create output file \"$output\"\n");
    select OUTPUT_FILE;
  }
  print "/* Generated file, do not edit */\n\n";
}

sub standardOutput() {
  return !$output;
}

sub writeSimpleOutput() {
  startOutputFile();
  writePreamble();
  writeMain();    ## write the normal main()
  writeWorld();
}



my ($didPreamble, $didWorld);

sub writeTemplateOutput() {
  openTemplateFile();
  startOutputFile();
  my $line;
  while (defined($line = <TEMPLATE_FILE>)) {
    if ( $line =~ m/^\s*\#\s*include\s*<cxxtest\// ) {
      writePreamble();
      print $line;
    } elsif ( $line =~ m/^\s*<CxxTest\s+preamble>\s*$/ ) {
      writePreamble();
    } elsif ( $line =~ m/^\s*<CxxTest\s+world>\s*$/ ) {
      writeWorld();
    } else {
      print $line;
    }
  }
}

sub openTemplateFile() {
  open TEMPLATE_FILE, "<$template" or die("Cannot open template file \"$template\"\n");
}

sub writePreamble() {
  return if $didPreamble;
  print "#ifndef CXXTEST_RUNNING\n";
  print "#define CXXTEST_RUNNING\n";
  print "#endif\n";
  print "\n";
  if ( $haveStd ) {
    print "#define _CXXTEST_HAVE_STD\n";
  }
  if ( $haveEh ) {
    print "#define _CXXTEST_HAVE_EH\n";
  }
  if ( $abortOnFail ) {
    print "#define _CXXTEST_ABORT_TEST_ON_FAIL\n";
  }
  if ( $longlong ) {
    print "#define _CXXTEST_LONGLONG $longlong\n";
  }
  if ( $factor ) {
    print "#define _CXXTEST_FACTOR\n";
  }
  foreach my $header (@headers) {
    print "#include $header\n";
  }

  print "#include <cxxtest/TestListener.h>\n";
  print "#include <cxxtest/TestTracker.h>\n";
  print "#include <cxxtest/TestRunner.h>\n";
  print "#include <cxxtest/RealDescriptions.h>\n";
  print "#include <cxxtest/$runner.h>\n" if $runner;
  print "#include <cxxtest/$gui.h>\n" if $gui;
  print "\n";
  $didPreamble = 1;

}





sub writeWorld() {
  return if $didWorld;
  writePreamble();
  writeSuites();
  ($root or !$part) and writeRoot();
  $noStaticInit and writeInitialize();
  $didWorld = 1;
}

sub writeSuites() {
  foreach (@suites) {
    $suite = $_;
    writeInclude(fileName());
    if ( $suite->{'generated'} ) { generateSuite(); }
    dynamicSuite() ? writeSuitePointer() : writeSuiteObject();
    writeTestList();
    writeSuiteDescription();
    writeTestDescriptions();
  }
}

sub dynamicSuite() {
  return suiteCreateLine();
}

my $lastIncluded;

sub writeInclude($) {
  my $file = $_[0];
  return if $lastIncluded && ($file eq $lastIncluded);
  print "#include \"$file\"\n\n";
  $lastIncluded = $file;
}

sub generateSuite() {
  print "class ", suiteName(), " : public CxxTest::TestSuite {\n";
  print "public:\n";
  foreach my $line (@{$suite->{'lines'}}) {
    print $line;
  }
  print "};\n\n";
}

sub writeTestDescriptionsBase() {
  my $class = "TestDescriptionBase_" . suiteName();
  print "class $class : public CxxTest::TestDescription {\n";
  print "public:\n";
  print " const char *file() const { return ", fileString(), "; }\n";
  print " const char *suiteName() const { return \"", suiteName(), "\"; }\n";
  print "};\n\n";
}

sub writeSuitePointer() {
  if ( $noStaticInit ) {
    print "static ", suiteName(), " *", suiteObject(), ";\n\n";
  } else {
    print "static ", suiteName(), " *", suiteObject(), " = 0;\n\n";
  }
}

sub writeSuiteObject() {
  print "static ", suiteName(), " ", suiteObject(), ";\n\n";
}

sub testList() {
  return "Tests_" . suiteName();
}

sub writeTestList() {
  if ( $noStaticInit ) {
    printf "static CxxTest::List %s;\n", testList();
  } else {
    printf "static CxxTest::List %s = { 0, 0 };\n", testList();
  }
}

sub writeTestDescriptions() {
  foreach (@{suiteTests()}) {
    $test = $_;
    writeTestDescription();
  }
}

sub suiteDescription() {
  return "suiteDescription_" . suiteName();
}

sub writeTestDescription() {
  my $class = "TestDescription_" . suiteName() . "_" . testName();
  printf "static class $class : public CxxTest::RealTestDescription {\n";
  printf "public:\n";
  $noStaticInit or
    printf " $class() : CxxTest::RealTestDescription( %s, %s, %s, \"%s\" ) {}\n",
      testList(), suiteDescription(), testLine(), testName();
  printf " void runTest() { %s }\n", dynamicSuite() ? dynamicRun() : staticRun();
  printf "} testDescription_%s_%s;\n\n", suiteName(), testName();
}

sub dynamicRun() {
  return sprintf( "if ( %s ) %s->%s();", suiteObject(), suiteObject(), testName() );
}

sub staticRun() {
  return sprintf( "%s.%s();", suiteObject(), testName() );
}

sub writeSuiteDescription() {
  dynamicSuite() ? writeDynamicDescription() : writeStaticDescription();
}

sub writeDynamicDescription() {
  printf "CxxTest::DynamicSuiteDescription<%s> %s", suiteName(), suiteDescription();
  if ( !$noStaticInit ) {
    printf "( %s, %s, \"%s\", %s, %s, %s, %s )",
      fileString(), $suite->{'line'}, suiteName(), testList(),
        suiteObject(), suiteCreateLine(), suiteDestroyLine();
  }
  print ";\n\n";
}

sub writeStaticDescription() {
  printf "CxxTest::StaticSuiteDescription %s", suiteDescription();
  if ( !$noStaticInit ) {
    printf "( %s, %s, \"%s\", %s, %s )", fileString(), $suite->{'line'}, suiteName(), suiteObject(), testList();
  }
  print ";\n\n";
}

sub writeRoot() {
  print "#include <cxxtest/Root.cpp>\n";
}

sub writeInitialize() {
  print "namespace CxxTest {\n";
  print " void initialize()\n";
  print " {\n";
  foreach (@suites) {
    $suite = $_;
    printf "  %s.initialize();\n", testList();
    if ( dynamicSuite() ) {
      printf "  %s = 0;\n", suiteObject();
      printf "  %s.initialize( %s, %s, \"%s\", %s, %s, %s, %s );\n",
        suiteDescription(), fileString(), $suite->{'line'}, suiteName(), testList(),
          suiteObject(), suiteCreateLine(), suiteDestroyLine();
    } else {
      printf "  %s.initialize( %s, %s, \"%s\", %s, %s );\n",
        suiteDescription(), fileString(), $suite->{'line'}, suiteName(), suiteObject(), testList();
    }

    foreach (@{suiteTests()}) {
      $test = $_;
      printf "  testDescription_%s_%s.initialize( %s, %s, %s, \"%s\" );\n",
        suiteName(), testName(), testList(), suiteDescription(), testLine(), testName();
    }
  }
  print " }\n";
  print "}\n";
}

sub writeMain() {
  if ( $gui ) {
    print "int main( int argc, char *argv[] ) {\n";
    $noStaticInit &&
      print " CxxTest::initialize();\n";
    print " return CxxTest::GuiTuiRunner<CxxTest::$gui, CxxTest::$runner>( argc, argv ).run();\n";
    print "}\n";
  }
  elsif ( $runner ) {
    print "int main() {\n";
    $noStaticInit &&
      print " CxxTest::initialize();\n";
    print " return CxxTest::$runner().run();\n";
    print "}\n";
  }
}


#####   HostBoot functions....  #####

##
##  Write the preamble for hostboot
##
sub writeHostBootPreamble() {

  return if $didHBPreamble;
  print "#ifndef CXXTEST_RUNNING\n";
  print "#define CXXTEST_RUNNING\n";
  print "#endif\n";
  print "\n";
  if ( $haveStd ) {
    print "#define _CXXTEST_HAVE_STD\n";
  }
  if ( $haveEh ) {
    print "#define _CXXTEST_HAVE_EH\n";
  }
  if ( $abortOnFail ) {
    print "#define _CXXTEST_ABORT_TEST_ON_FAIL\n";
  }
  if ( $longlong ) {
    print "#define _CXXTEST_LONGLONG $longlong\n";
  }
  if ( $factor ) {
    print "#define _CXXTEST_FACTOR\n";
  }
  ##  these are headers that are included in the options, probably not used here.
  foreach my $header (@headers) {
    print "#include $header\n";
  }

  ##    print the standard includes for Hostboot
  print "\n";
  print "#include <kernel/console.H>\n";
  print "#include <sys/sync.h>\n";
  print "#include <sys/vfs.h>\n";
  print "#include <sys/task.h>\n";
  print "#include <sys/sync.h>\n";
  print "#include <trace/interface.H>\n";
  ## $$TODO print "#include <taskargs/taskargs.H>\n";

  print "#include <cxxtest/TestSuite.H>\n";

  print "\n";
  $didHBPreamble = 1;
}

sub writeHostBootSuites() {
  my  ( $suitecount, $suitevar, $testcount );

  $suitecount   =   1;                          #   initialize suite count
  $testcount    =   0;                          #   initialize test count
  
  ## $$TODO print   "\tTaskArgs    *pTaskArgs  = (TaskArgs *)ptr;\n";

  foreach (@suites) {
    $suite = $_;

    $suitevar   =   "l_ex$suitecount";          #   Make up the suite variable name

    ## writeInclude(fileName());

    if ( $debug )   {
        print   "\n";
        print   "\t// debug: suiteName=", suiteName(), "\n";
        print   "\t// debug: generated=", $suite->{'generated'}, "\n";
        foreach (@{suiteTests()}) {
            $test = $_;
            print "\t\t//  debug: test=", testName(), "\n";
        }
        #print   suiteCreateLine(), "\n";
        #print   suiteDestroyLine(), "\n";
        print   "\t// debug: filename=", fileName(), "\n";
        print   "\t// debug: filestring=", fileString(), "\n";
        print   "\n";
    }

    ##  declare and instantiate a new instance of the suite
    print   "\t// Test Suite ", $suitecount, ": " , suiteName(), "\n";
    if ( $debug )   { print   "\tprintk(\"Executing test suite ", suiteName(), ".\\n\");\n";    }
    print   "\tTRACDCOMP( g_trac_test, \"Execute ", suiteName(), ".\");\n";
    print   "\t", suiteName(), "\t*", $suitevar, "   =   new ", suiteName(), ";\n";

    ##if ( $suite->{'generated'} ) { generateSuite(); }
    ##dynamicSuite() ? writeSuitePointer() : writeSuiteObject();

    print   "\n\n";
    ##  run each of the tests in the list
    foreach (@{suiteTests()}) {
        $test = $_;
        if ( $debug )   {   print   "\tprintk(\"Executing test module ", testName(), ".\\n\");\n";  }
        printf "\t$suitevar->%s();\n\n", testName();
        $testcount++;
    }
    
    ## $$TODO print "\n";
    ## $$TODO print "\tif  ( pTaskArgs )\n";
    ## $$TODO print "\t{\n";
    ## $$TODO print "\t\tpTaskArgs->waitChildSync();\n";
    ## $$TODO print "\t}\n";

    print   "\n";
    ##  delete the suite instance
    print   "\tdelete   ", $suitevar, ";\n";

    print   "\n";
    print "\tCxxTest::reportTotalTests( \"", suiteName(), "\", $testcount );\n";
    print   "\n";

    $suitecount++;                            # bump to the next suite
  }
}

##
##  For HostBoot we write a _start() routine, there is no main()
##
sub write_start() {

  print   "\n";
  ## $$TODO print   "\tusing namespace TASKARGS;\n";
  
  print   "\n";
  print   "trace_desc_t *g_trac_test = NULL;\n";
##  Use same trace buffer for all unit tests, i.e. "UNIT_TEST"  
##  print   "TRAC_INIT(&g_trac_test, \"", suiteName(), "\", 4096);\n";
  print   "TRAC_INIT(&g_trac_test, \"", "UNIT_TEST", "\", 4096);\n";


  print   "\n\n";
  print   "extern \"C\"\n";
  print   "void _start(void *ptr) ";
  print   "{\n";
  
  
   ## here's where the  magic happens....
  writeHostBootSuites();

  print   "\n";
  print "\t__sync_add_and_fetch(&CxxTest::g_ModulesCompleted, 1);\n";
  print "\n";
  print "\tbarrier_wait( &CxxTest::g_CxxTestBarrier );\n";
  
  print "\n";
  print   "\ttask_end();\n";
  print   "}\n";

}

##
##  Write the Hostboot test file.
##
sub writeHostBootOutput() {

  startOutputFile();

  writeHostBootPreamble();

  foreach (@suites) {
    $suite = $_;
    writeInclude( fileName() );
  }

  write_start()   ## write _start() routine for HostBoot

}
