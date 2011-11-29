#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/simics/hb-simdebug.py $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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

import os,sys
import conf
import configuration
import cli
import binascii
import datetime
import commands     ## getoutput, getstatusoutput

#------------------------------------------------------------------------------
# Function to dump L3
#------------------------------------------------------------------------------
def dumpL3():

    # "constants"
    L3_SIZE = 0x800000;

    print

    # Get a timestamp on when dump was collected
    t = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    #print t

    #dump L3 to hbdump.<timestamp>
    string = "memory_image_ln0.save hbdump.%s 0 0x%x"%(t, L3_SIZE)
    #print string
    result = run_command(string)
    #print result

    print "HostBoot dump saved to %s/hbdump.%s."%(os.getcwd(),t)

    return


#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
# Functions to run isteps
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def hb_istep_usage():
    print   "hb-istep usage:"
    print   "   istepmode   -   enable IStep Mode.  Must be executed before simics run command"
    print   "   normalmode  -   disable IStep Mode. "
    print   "   list        -   list all named isteps"
    print   "   sN          -   execute IStep N"
    print   "   sN..M       -   execute IStep N through M"
    print   "   <name1>..<name2>  - execute named isteps name1 through name2"
    print   "   debug       -   enable debugging messages"
    return  None  
    
## declare GLOBAL g_SeqNum var, & a routine to manipulate it.  
##  TODO:  make this into a class, etc. to do it The Python Way.   
g_SeqNum  = 0    
def bump_g_SeqNum() :
    global  g_SeqNum
    g_SeqNum    = ( (g_SeqNum +1) & 0x3f) 
    return  None

##  clock a certain amount of CPU cycles so the IStep will run (this will be 
##  different for each simulation environment) and then return.
##  simics clock is a somewhat arbitrary value, may need to be adjusted.
##
##  Handle following environments:
##  1.  [x] simics value    =   100,000     (from Patrick)
##  2.  VPO value       =   ???         (don't know yet)
##  3.  hardware value  =   ???         ( ditto)
##
def runClocks() :

    SIM_continue( 100000 )
    return  None
         
##    
##  send a command to the SPLess Command register (scratchpad reg 1) 
##  cmd is passed in as a 64-bit ppc formatted hex string, i.e.
##          "0x80000000_00000000"  
## 
##  Handle following environments:
##  1.  [x] simics
##  2.  VPO
##  3.  hardware  
def sendCommand( cmd ):
    global g_IStep_DEBUG
    CommandStr  =   "cpu0_0_0_1->scratch=%s"%(cmd)
    
    ##  send command to Hostboot
    ## print CommandStr
    (result, out) = quiet_run_command(CommandStr, output_modes.regular )

    if ( g_IStep_DEBUG ) :
        print "sendCommand( 0x%x ) returns : " + "0x%x"%(cmd, result) + " : " + out
    
    return  result

def printStsHdr( status ):

    runningbit  =   ( ( status & 0x8000000000000000 ) >> 63 )
    readybit    =   ( ( status & 0x4000000000000000 ) >> 62 ) 
    seqnum      =   ( ( status & 0x3f00000000000000 ) >> 56 )
    taskStatus  =   ( ( status & 0x00ff000000000000 ) >> 48 )

    print "runningbit = 0x%x, readybit=0x%x, seqnum=0x%x, taskStatus=0x%x"%(runningbit, readybit, seqnum, taskStatus )
    return  None

##  get status from the SPLess Status Register (scratchpad reg 2)
##  returns a 64-bit int.  
##
##  Handle following environments:
##  1.  [x] simics
##  2.  VPO
##  3.  hardware
##
def getStatus(): 
    global  g_IStep_DEBUG
    StatusStr   =   "cpu0_0_0_2->scratch"
      
    ( result, out )  =   quiet_run_command( StatusStr, output_modes.regular )
    if  ( g_IStep_DEBUG ) :
        print ">> getStatus(): " + "0x%x"%(result) + " : " + out
    ## printStsHdr(result)
    
    return result


##  check for status, waiting for the readybit and the sent g_SeqNum.
##  default is to check the readybit, in rare cases we want to skip this.
def getSyncStatus( ) :
    # set # of retries
    count = 100
    
    ##  get response.  sendCmd() should have bumped g_SeqNum, so we will sit
    ##  here for a reasonable amount of time waiting for the correct sequence
    ##  number to come back.  
    while True :
    
        ##  advance HostBoot code by a certain # of cycles, then check the 
        ##  sequence number to see if it has changed.  rinse and repeat.
        runClocks()
        
        ##  print a dot (with no carriage return) so that the user knows that
        ##  it's still doing something    
        print "." ,

        result = getStatus()
        seqnum  = ( ( result & 0x3f00000000000000 ) >> 56 )
        if ( seqnum == g_SeqNum ) :
            print                   # print a final carriage return
            return result
        
        if ( count <= 0 ):
            print                   # print a final carriage return
            print "TIMEOUT waiting for seqnum=%d"%( g_SeqNum )
            return -1
        count -= 1    
        
##  write to scratch reg 3 to set istep or normal mode, check return status        
def setMode( cmd ) :
    IStepModeStr    = "cpu0_0_0_3->scratch=0x4057b007_4057b007"
    NormalModeStr   = "cpu0_0_0_3->scratch=0x700b7504_700b7504"
    
    
    count   =   10
    
    if ( cmd == "istep" ) :
        (result, out)  =   quiet_run_command( IStepModeStr )
        # print "set istepmode returned 0x%x"%(result) + " : " + out 
        expected    =   1    
    elif   ( cmd == "normal" ) :
        (result, out)  =   quiet_run_command( NormalModeStr )
        # print "set normalmode returned 0x%x"%(result) + " : " + out 
        expected    =   0
    else :     
        print "invalid setMode command: %s"%(cmd) 
        return  None
 
    ##  Loop, advancing clock, and wait for readybit
    while True :
        runClocks()

        result = getStatus()
        readybit    =   ( ( result & 0x4000000000000000 ) >> 62 )
        print   "Setting %s mode, readybit=%d..."%( cmd, readybit )   
        if ( readybit == expected ) :
            print   "Set %s Mode success."%(cmd)
            return 0
            
        if ( count <= 0 ):
            print "TIMEOUT waiting for readybit, status=0x%x"%( result )
            return -1
        count -= 1 
        
    
##  read in file with csv istep list and store in inList
def get_istep_list( inList ):
    istep_file = open('./isteplist.csv')
    for line in istep_file.readlines():
        ( istep, substep, name) =   line.split(',')
        i = int(istep)
        j = int(substep)
        
        ## print ":: %d %d %s"%(i, j, name)
        if ( name.strip() != "" ):
            inList[i][j]  =   name.strip()     
          
    istep_file.close()

    return None

        

def print_istep_list( inList ):
    print   "IStep\tSubStep\tName"
    print   "---------------------------------------------------"
    for i in range(0,len(inList)) :
        for j in range( 0, len(inList[i])) :
            # print "%d %d"%(i,j)
            if ( inList[i][j] != None ) :
                print "%d\t%d\t%s"%( i,j, inList[i][j] )   
                
    print   " "                 
    return None
            

def runIStep( istep, substep, inList ):
    
    bump_g_SeqNum()
    
    print   "run  %d.%d %s :"%( istep, substep, inList[istep][substep] )
    ## print   "   istep # = 0x%x / substep # = 0x%x :"%(istep, substep)
    
    byte0   =   0x80 + g_SeqNum      ## gobit + seqnum
    command =   0x00
    cmd = "0x%2.2x%2.2x%2.2x%2.2x_00000000"%(byte0, command, istep, substep );
    sendCommand( cmd )
    
    result  =   getSyncStatus()
    
    ## if result is -1 we have a timeout
    if ( result == -1 ) :
        print   "-----------------------------------------------------------------"
    else :
        taskStatus  =   ( ( result & 0x00ff000000000000 ) >> 48 )
        stsIStep    =   ( ( result & 0x0000ff0000000000 ) >> 40 )
        stsSubstep  =   ( ( result & 0x000000ff00000000 ) >> 32 )
        istepStatus =   ( ( result & 0x00000000ffffffff )  )

        print   "-----------------------------------------------------------------"
        ## printStsHdr(result)
        ## print "Istep 0x%x / Substep 0x%x Status: 0x%x"%( stsIStep, stsSubstep, istepStatus ) 
        if ( taskStatus != 0 ) :
            print "Istep %d.%d FAILED to launch, task status is %d"%( taskStatus )
        else:            
            print "Istep %d.%d returned Status: 0x%x"%( stsIStep, stsSubstep, istepStatus ) 
        print   "-----------------------------------------------------------------"
        
    return    
    
    
##  run command = "sN"    
def sCommand( inList, scommand ) :
    
    i   =   int(scommand)
    j   =   0
    
    # sanity check
    if ( inList[i][0] == None ) :
        print "IStep %d.0 does not exist."%( i )
        return
        
    #   execute all the substeps in the IStep
    for substep in inList[i] :
        ## print   "-----------------" 
        ##print "run IStep %d %s  ..."%(i, substep)
        ##print   "-----------------" 
        if ( inList[i][j] != None ) :
            runIStep( i, j, inList )
        j = j+1
    return    
    
    
def find_in_inList( inList, substepname) :
    for i in range(0,len(inList)) :
        for j in range( 0, len(inList[i])) :
            #print "%d %d"%(i,j)
            if ( inList[i][j] == substepname ) :
                #print "%s %d %d"%( inList[i][j], i, j )
                return (i,j, True )
                break;  
                  
    return ( len(inList), len(inList[i]), False )   
    
##  ---------------------------------------------------------------------------
##  High Level Routine for ISteps.       
##  ---------------------------------------------------------------------------
##  possible commands:
##      list
##      istepmode
##      normalmode
##      sN
##      sN..M
##      <substepname1>..<substepname2>

##  declare GLOBAL g_IStep_DEBUG
g_IStep_DEBUG   =   0
def istepHB( str_arg1 ):
        
    ## simics cannot be running when we start, or SIM_continue() will not work
    ##  and the Status reg will not be updated.          
    if ( SIM_simics_is_running() ) :
        print "simics must be halted before issuing an istep command."
        return;     
        
          
    ## start with empty inList.  Put some dummy isteps in istep4 for debug.        
    n   =   10                                      ## size of inlist array
    inList  =   [[None]*n for x in xrange(n)]       ## init to nothing
    inList[4][0] =   "i1"
    inList[4][1] =   "i2"
    inList[4][2] =   "i3"
    inList[4][3] =   "i4"
   
      
    ## bump seqnum
    bump_g_SeqNum() 

    ## print   "run istepHB...."
    
    if ( str_arg1 == "debug" ) :
        print "enable istep debug - restart simics to reset"
        g_IStep_DEBUG   =   1
        return
    
    if ( str_arg1 == "istepmode"  ):    ## set IStep Mode in SCOM reg
        # print   "Set Istep Mode"
        setMode( "istep" )
        return
        
    if ( str_arg1 == "normalmode"  ):    ## set Normal Mode in SCOM reg
        # print   "Set Normal Mode"
        setMode( "normal" )
        return
        
        
    ## get readybit to see if we are running in IStep Mode.
    StatusReg  =   getStatus()
    readybit    =   ( ( StatusReg & 0x4000000000000000 ) >> 62 )     
    if ( not readybit ):
        print   "ERROR:  HostBoot Status reg is 0x%16.16x"%( StatusReg )
        print   "   Ready bit is not on, did you remember to run hb-istep istepmode ??"
        print   " "
        hb_istep_usage()
        return None
       
    ##  get the list of isteps from HostBoot...
    # print"get istep list"
    get_istep_list( inList )
             
    if ( str_arg1 == "list"  ):         ## dump command list
        print_istep_list( inList )          
        return         
           
    ## check to see if we have an 's' command (string starts with 's' and a number)    
    if ( re.match("^s+[0-9].*", str_arg1 ) ):
        ## run "s" command
        # print "s command"
        scommand    =   str_arg1.lstrip('s')
        
        if scommand.isdigit():
            # command = "sN"
            # print "single IStep: " + scommand
            sCommand( inList, scommand )
        else:
            #   list of substeps = "sM..N"
            (M, N)  =   scommand.split('..')
            # print "multiple ISteps: " + M + "-" + N 
            for x in range( (int(M,16)), (int(N,16)+1) ) :
                sCommand( inList, x )
        return
    else:  
        ## substep name .. substep name
        ## print   "named istep(s) : " + str_arg1 
        ## (ss_nameM, ss_nameN) = str_arg1.split("..")
        ss_list =   str_arg1.split("..")
        
        (istepM, substepM, foundit) = find_in_inList( inList, ss_list[0] )
        istepN      =   istepM
        substepN    =   substepM
        if ( not foundit ) :
            print( "Invalid substep %s"%(ss_list[0] ) )
            return
            
        if ( len(ss_list) > 1 ) :    
            (istepN, substepN, foundit) = find_in_inList( inList, ss_list[1] )
            if ( not foundit ) :
               print( "Invalid substep %s"%(ss_list[1] ) )
               return
 
        for x in range( istepM, istepN+1 ) :
                for y in range( substepM, substepN+1 ) :
                    runIStep( x, y, inList )
    return  


#===============================================================================
#   HOSTBOOT Commands
#===============================================================================
default_syms  = "hbicore.syms"
default_stringFile = "hbotStringFile"


#------------------------------------------------
#------------------------------------------------
new_command("hb-trace",
    (lambda comp: run_hb_debug_framework("Trace",
                                         ("components="+comp) if comp else "",
                                         outputFile = "hb-trace.output")),
    [arg(str_t, "comp", "?", None),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb_printk"],
    see_also = [ ],
    short = "Display the hostboot trace",
    doc = """
Parameters: \n
        in = component name(s) \n

Defaults: \n
        'comp' = all buffers \n
        'syms' = './hbicore.syms' \n
        'stringFile' = './hbotStringFile' \n\n

Examples: \n
    hb-trace \n
    hb-trace ERRL\n
    hb-trace "ERRL,INITSERVICE" \n
    """)

#------------------------------------------------
#------------------------------------------------
new_command("hb-printk",
    lambda: run_hb_debug_framework("Printk", outputFile = "hb-printk.output"),
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Display the kernel printk buffer",
    doc = """
Parameters: \n

Defaults: \n
        'syms' = './hbicore.syms' \n\n

Examples: \n
    hb-printk \n
    """)

#------------------------------------------------
#------------------------------------------------
def hb_dump():
    dumpL3()
    return None

new_command("hb-dump",
    hb_dump,
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Dumps L3 to hbdump.<timestamp>",
    doc = """
Parameters: \n

Defaults: \n

Examples: \n
    hb-dump \n
    """)

#------------------------------------------------
#   implement isteps
#------------------------------------------------
def hb_istep(str_arg1): 
 
    if ( str_arg1 == None): 
        hb_istep_usage()
    else:
        ## print "args=%s" % str(str_arg1)       
        istepHB( str_arg1 )
                    
    return None
    
new_command("hb-istep",
    hb_istep,
    [ arg(str_t, "syms", "?", None),
      # arg(flag_t,"-s", "?", None),
    ],
    type = ["hostboot-commands"],
    see_also = [ ],
    short = "Run IStep commands using the SPLess HostBoot interface",
    doc = """
Parameters: \n
 
Defaults: \n

Examples: \n
    hb-istep \n
    hb-istep -s4 \n
    hb-istep -s4..N
    hb-istep -4.1
    hb-istep -4.1..4.3 \n
    hb-istep poweron \n
    hb-istep poweron..clock_frequency_set /n
    """)    
    
#------------------------------------------------
#------------------------------------------------
new_command("hb-errl",
    (lambda logid, logidStr, flg_l, flg_d:
        run_hb_debug_framework("Errl",
                ("display="+(str(logid) if logid else logidStr) if flg_d else ""
                ),
                outputFile = "hb-errl.output")),
    [ arg(int_t, "logid", "?", None),
     arg(str_t, "logidStr", "?", None),
     arg(flag_t, "-l"),
     arg(flag_t, "-d"),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb_printk"],
    see_also = [ ],
    short = "Display the hostboot error logs",
    doc = """
Parameters: \n
        in = option for dumping error logs\n

Defaults: \n
        'flag' = '-l' \n

Examples: \n
    hb_errl [-l]\n
    hb-errl -d 1\n
    hb-errl -d [all]\n
    """)


#------------------------------------------------
#------------------------------------------------
def hb_singlethread():
    run_command("foreach $cpu in (system_cmp0.get-processor-list) {$cpu.disable}")
    run_command("cpu0_0_0_0.enable");
    return

new_command("hb-singlethread",
    hb_singlethread,
    [],
    alias = "hb-st",
    type = ["hostboot-commands"],
    short = "Disable all threads except cpu0_0_0_0.")
