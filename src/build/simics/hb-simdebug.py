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
# Functions to run isteps
#------------------------------------------------------------------------------
def print_istep_list( inList ):

    print
    print   "istep commands:."
    print   "   istepmode   -   enable IStep Mode.  Must be executed before simics run command"
    print   "   normalmode  -   disable IStep Mode. "
    print   "   list        -   list all named isteps"
    print   "   sN          -   execute IStep N"
    print   "   sN..M       -   execute IStep N through M"
    print   "   <name1>     -   excute named istep name1"
    print   "   <name1>..<name2>  - execute named isteps name1 through name2"
    print
    print   "-----------------------------------------------------------"
    print   " Supported ISteps:                                         "
    print   " IStep\tSubStep\tStepName                                  "
    print   "-----------------------------------------------------------"    

    ## print   len(inList)
    for i in range(0,len(inList)) :
        ##print len(inList[i])
        for j in range( 0, len(inList[i])) :
            print "%d\t%d\t%s"%( i, j, inList[i][j] )
                
    return None


#   normally this would be a loop to watch for the runningbit.  
#   currently simics dumps all sorts of error lines every time a SCOM is
#   read, so HostBoot only updates every 1 sec.  at that rate we only
#   need to sleep for 2 sec and we are sure to get it.
#   redo later after simics is fixed ...
def getStatusReg():
    ##StatusStr   = "salerno_chip.regdump SCOM 0x13012685"
    ##  -f <file> dumps the output to <file>_SCOM_0X13012685
    ## StatusStr   = "salerno_chip.regdump SCOM 0x13012685 -f ./scom.out"   
    StatusStr   = "cpu0_0_0_2->scratch"   
    
    ##  get response
    # (result, statusOutput)  =   quiet_run_command( StatusStr, output_modes.regular )
    result  =   conf.cpu0_0_0_2.scratch
    print "0x%x"%(result)  

    hiword  = ( ( result & 0xffffffff00000000) >> 32 )
    loword  = ( result & 0x00000000ffffffff )
    
    return (hiword, loword)



#   normally this would be a loop to watch for the runningbit.
#   currently simics dumps all sorts of error lines every time a SCOM is
#   read, so HostBoot only updates every 1 sec.  at that rate we only
#   need to sleep for 2 sec and we are sure to get it.
#   redo later after simics is fixed ...
def runIStep( istep, substep, inList ):
    print   "------------------------------------------------------------------"
    print   "run  %s :"%( inList[istep][substep] )
    print   "   istep # = 0x%x / substep # = 0x%x :"%(istep, substep)

    ## CommandStr  = "salerno_chip.regwrite SCOM 0x13012684 \"0x80000000_%4.4x%4.4x\" 64"%(istep,substep)
    CommandStr  = "cpu0_0_0_1->scratch=0x80000000_%4.4x%4.4x"%(istep,substep)

    #result  =   run_command( "run" )

    ##  send command to Hostboot
    # print CommandStr
    (result, out) = quiet_run_command(CommandStr, output_modes.regular )
    #print result

    time.sleep(2)

    # result  =   run_command( "stop" )

    (hiword, loword) =   getStatusReg()
    
    runningbit  =   ( ( hiword & 0x80000000 ) >> 31 )
    readybit    =   ( ( hiword & 0x40000000 ) >> 30 ) 
    stsIStep    =   ( ( hiword & 0x3fff0000 ) >> 16 )
    stsSubstep  =   ( ( hiword & 0x0000ffff ) )
    
    taskStatus  =   ( ( loword & 0xffff0000 ) >> 16 )
    istepStatus =   ( ( loword & 0x0000ffff )  )   
    print 
    print   "%s : returned Status 0x%8.8x_%8.8x : "%( inList[istep][substep], hiword, loword )
    print "runningbit = 0x%x, readybit=0x%x"%(runningbit, readybit)
    print "Istep 0x%x / Substep 0x%x Status: 0x%x 0x%x"%( stsIStep, stsSubstep, taskStatus, istepStatus )
    print   "-----------------------------------------------------------------"    
    
    # result  =   run_command( "run" )
    
##  run command = "sN"    
def sCommand( inList, scommand ) :
    i   =   int(scommand)
    j   =   0
    for substep in inList[i] :
        ## print   "-----------------"
        ##print "run IStep %d %s  ..."%(i, substep)
        ##print   "-----------------"
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


##  possible commands:
##      list
##      istepmode
##      sN
##      sN..M
##      <substepname1>..<substepname2>
def istepHB( str_arg1, inList):
    IStepModeStr    = "cpu0_0_0_3->scratch=0x4057b007_4057b007"
    NormalModeStr   = "cpu0_0_0_3->scratch=0x700b7504_700b7504"

    print   "run isteps...."

    if ( str_arg1 == "list"  ):         ## dump command list
        print_istep_list( inList)
        return

    if ( str_arg1 == "istepmode"  ):    ## set IStep Mode in SCOM reg
        print   "Set Istep Mode"
        (result, out)  =   quiet_run_command(IStepModeStr, output_modes.regular )
        # print result
        return
        
    if ( str_arg1 == "normalmode"  ):    ## set Normal Mode in SCOM reg
        print   "Set Normal Mode"
        (result, out)  =   quiet_run_command(NormalModeStr, output_modes.regular )
        # print result
        return       

    ## check to see if we have an 's' command (string starts with 's')
    if ( str_arg1.startswith('s') ):
        ## run "s" command
        scommand    =   str_arg1.lstrip('s')
        if scommand.isdigit():
            # command = "sN"
            sCommand( inList, scommand )
        else:
            print "multiple ISteps:" + scommand
            #   list of substeps = "sM..N"
            (M, N)  =   scommand.split('..')
            #print M + "-" + N
            for x in range( (int(M,16)), (int(N,16)+1) ) :
                sCommand( inList, x )
        return
    else:  
        ## substep name
        ## (ss_nameM, ss_nameN) = str_arg1.split("..")
        namelist    =   str_arg1.split("..")
        if ( len(namelist) ==  1 ) :
            (istepM, substepM, foundit) = find_in_inList( inList, namelist[0] )
            if ( not foundit ) :
                print "Invalid substep %s"%( namelist[0] )
                return
            runIStep( istepM, substepM, inList )
        else:       
            ## substep name .. substep name 
            (istepM, substepM, foundit) = find_in_inList( inList, namelist[0] )
            if ( not foundit ) :
                print "Invalid substep %s"%( namelist[0] )
                return    
            (istepN, substepN, foundit) = find_in_inList( inList, namelist[1] )
            if ( not foundit ) :
                print( "Invalid substep %s"%( namelist[1]) )
                return
            for x in range( istepM, istepN+1 ) :
                for y in range( substepM, substepN+1) :
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
                                         ("components="+comp) if comp else "")),
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
    lambda: run_hb_debug_framework("Printk"),
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

    ##  preprocess inputs,
    ##  read in a file and translate to an inList
    ##  TODO read in default file
    #   TODO inPath  =   "istep_list.txt"
    #   TODO inFile = open( inPath, 'rU')
    #   TODO inList = inFile.readlines()
    #   TODO inFile.close()

    ## set up demo inlist
    inList  =   [   [ "na" ],              ## istep 0
                    [ "na" ],              ## istep 1
                    [ "na" ],              ## istep 2
                    [ "na" ],              ## istep 3
                    [ "init_target_states",     ## istep 4
                      "init_fsi", 
                      "apply_fsi_info", 
                      "apply_dd_presence", 
                      "apply_pr_keyword_data",
                      "apply_partial_bad",
                      "apply_gard",
                      "testHWP"
                    ],
                ]  
                          
    ## print   flag_t                   
    
    if str_arg1 == None: 
        print_istep_list( inList )
    else:
        print "args=%s" % str(str_arg1)
        istepHB( str_arg1, inList, )

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
    hb-istep -s0 \n
    hb-istep -s0..4
    hb-istep poweron
    hb-istep poweron..clock_frequency_set
    """)

#------------------------------------------------
#------------------------------------------------
new_command("hb-errl",
    (lambda logid, logidStr, flg_l, flg_d:
        run_hb_debug_framework("Errl",
                ("display="+(str(logid) if logid else logidStr) if flg_d else ""
                ))),
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
