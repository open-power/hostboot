# *** traceHB.py
#
# Script to extract and display formatted trace in simics

# *** Usage
#
# On simics console:
# 1. Load file
# simics> run-python-file <gitrepo>/src/build/trace/traceHB.py
# 2. Display global trace buffer
# simics> @traceHB("<compName1>,<compName2>,...", <git.repo>/img/hbicore.syms", <git.repo>/img/hbotStringFile")
# 3. Display kernel printk buffer
# simics> @printkHB("<git.repo>/img/hbicore.syms")

import os,sys
import conf
import configuration
import cli
import binascii

# Function to dump the global trace buffer
def traceHB(compStr, symsFile, stringFile):

    # "constants"
    DESC_ARRAY_ENTRY_SIZE = 24
    DESC_ARRAY_ENTRY_ADDR_SIZE = 8
    DESC_ARRAY_ENTRY_COMP_NAME_SIZE = 16
    MAX_NUM_BUFFERS = 24
    MAX_COMP_NAME_SIZE = DESC_ARRAY_ENTRY_COMP_NAME_SIZE - 1 #minus null termination

    print

    #Find location of g_desc_array variable from the image's .syms file
    for line in open(symsFile):

        if "g_desc_array" in line:                #if found

            #print line
            x = line.split(",")
            array_addr = int(x[1],16)             #address of g_desc_array
            #print "g_desc_array addr = 0x%x"%(array_addr)
            array_size = int(x[3],16)             #size of g_desc_array
            #print "g_desc_array size = 0x%x"%(array_size)

            # content of g_desc_array
            #string = "phys_mem.x 0x%x 0x%x"%(array_addr,array_size)
            #print string
            #result,message = quiet_run_command(string)
            #print message

            #flag to indicate if we found any buffer
            buffer_found = 0;

            #Parse the compStr argument for the list of component buffers requested
            compList = compStr.split(",")
            #print compList
            for compName in compList:

                # Strip all whitespaces and limit to 15 bytes max
                compName = compName.strip()
                if (len(compName) > MAX_COMP_NAME_SIZE):
                    compName = compName[0:MAX_COMP_NAME_SIZE]
                #print compName

                #pointer to first entry of g_desc_array
                entry_addr = array_addr

                #find the component trace buffer
                for entry in range (1, MAX_NUM_BUFFERS + 1):

                    #print "entry = 0x%x"%(entry)
                    string = "phys_mem.x 0x%x 0x%x"%(entry_addr,DESC_ARRAY_ENTRY_COMP_NAME_SIZE)
                    #print string
                    #example output of phys_mem.x is:
                    #simics> phys_mem.x 0x263c8 0x10
                    #p:0x000263c0                      4465 7646 5700 0000 0         DevFW...
                    #p:0x000263d0  0000 0000 0000 0000                     0 ........
                    result,message = quiet_run_command(string)
                    #print message
                    lst = message.split()
                    #print lst
                    #example output of lst (lst[1] = '4465'):
                    #['p:0x000263c0', '4465', '7646', '5700', '0000', '0', 'DevFW...', 
                    #'p:0x000263d0', '0000', '0000', '0000', '0000', '0', '........']

                    # no more entry to search
                    if lst[1]=='0000':
                        break

                    # get component name from entry
                    name_str = lst[1]
                    count = 1
                    i = 2
                    while (count < (DESC_ARRAY_ENTRY_COMP_NAME_SIZE/2)):
                        if (lst[i] == '0000'):
                            break
                        if len(lst[i]) == 4:
                            name_str += lst[i]
                            count +=1
                        i += 1

                    #1st method:
                    #str = name_str.strip('00')
                    #if (compName.encode("hex")==str):
                    #    print "we found the buffer"
                    #2nd method: 
                    name_str = binascii.unhexlify(name_str)
                    #print name_str
                    str = name_str.strip('\0')

                    #We found the component buffer
                    if ((str == compName) or (len(compName) == 0)): 

                        #get address of component trace buffer
                        string = "phys_mem.x 0x%x 0x%x"%(entry_addr + DESC_ARRAY_ENTRY_COMP_NAME_SIZE, DESC_ARRAY_ENTRY_ADDR_SIZE)
                        #print string
                        result,message = quiet_run_command(string)
                        #print message
                        lst = message.split()
                        #print lst

                        addr_str = ""
                        for i in range(1,(DESC_ARRAY_ENTRY_ADDR_SIZE/2) + 1):
                            addr_str += lst[i]
                        #print addr_str
                        addr_trace_buffer = int(addr_str,16)

                        #save trace buffer to <sandbox>/simics/trace.out
                        string = "memory_image_ln0.save tmp.out 0x%x 0x800"%(addr_trace_buffer)
                        #print string
                        result = run_command(string)
                        #print result

                        if (buffer_found == 0): 
                            fd1 = open('trace.out','wb')
                            buffer_found = 1
                        else:
                            fd1 = open('trace.out','ab')
                        fd2 = open('tmp.out', 'rb')
                        fd1.write(fd2.read())
                        fd1.close()
                        fd2.close()

                        if (str == compName):
                            break

                    # Increment address to next entry in g_desc_array
                    entry_addr += DESC_ARRAY_ENTRY_SIZE

            if (buffer_found == 1):
                #display formatted trace
                string = 'fsp-trace -s %s trace.out'%(stringFile)
                #print string
                os.system(string)

            print
            break
    return


# Function to dump the kernel printk buffer
def printkHB(symsFile):

    print

    #Find location of the kernel_printk_buffer variable from the image's .syms file
    #i.e. grep kernel_printk_buffer <gitrepo>/img/hbicore.syms
    for line in open(symsFile):
        if "kernel_printk_buffer" in line:  #if found
            #print line
            x = line.split(",")
            addr = int(x[1],16)             #address of kernel_printk_buffer
            #print "addr = 0x%x"%(addr)
            size = int(x[3],16)             #size of kernel_printk_buffer
            #print "size = 0x%x"%(size)

            #save kernel printk buffer to <sandbox>/simics/printk.out
            string = "memory_image_ln0.save printk.out 0x%x 0x%x"%(addr,size)
            #print string
            result = run_command(string)
            #print result

            #display buffer
            #for line in open("printk.out"):
            #    print line
            #file = open("printk.out")
            #print file.read()
            os.system('cat printk.out')

            break
    return

#===============================================================================
#   HOSTBOOT Commands
#===============================================================================
default_comp = ""
default_syms  = "hbicore.syms"
default_stringFile = "hbotStringFile"
#traceHB_relative_path  = "../tools"    # relative to $sb

#------------------------------------------------
#------------------------------------------------
def hb_trace(str_arg1, str_arg2, str_arg3):   
    if ((str_arg1 == None) or (str_arg1 == "all") or (str_arg1 == "ALL") or (str_arg1 == "All")):
            str_arg1 = default_comp
    if str_arg2 == None:
        if os.environ.has_key("HOSTBOOT_SYMS"):
            str_arg2 = str(os.environ.get("HOSTBOOT_SYMS"))
        else:
            str_arg2 = default_syms
    if str_arg3 == None:
        if os.environ.has_key("HOSTBOOT_STRINGFILE"):
            str_arg3 = str(os.environ.get("HOSTBOOT_STRINGFILE"))
        else:
            str_arg3 = default_stringFile
            
    print "comp=%s" % str(str_arg1)
            
    print "syms=%s" % str(str_arg2)
    print "StringFile=%s" % str(str_arg3)
    traceHB(str_arg1, str_arg2, str_arg3)
    return None
    
new_command("hb-trace",
    hb_trace,
    [arg(str_t, "comp", "?", None),
     arg(str_t, "syms", "?", None),
     arg(str_t, "stringFile", "?", None),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb_printk"],
    see_also = [ ],
    short = "Display the hostboot trace",
    doc = """
Parameters: \n
        in = component name \n
        in = SYMS file \n
        in = hostboot string file \n

Defaults: \n
        'comp' = all buffers \n
        'syms' = './hbicore.syms' \n
        'stringFile' = './hbotStringFile' \n\n

Examples: \n
    hb-trace \n
    hb-trace all \n
    hb-trace ERRL ../hbicore.syms <git.repo>/img/hbotStringFile \n
    """)

#------------------------------------------------
#------------------------------------------------
def hb_printk(str_arg1):   
    if str_arg1 == None:
        if os.environ.has_key("HOSTBOOT_SYMS"):
            str_arg1 = str(os.environ.get("HOSTBOOT_SYMS"))
        else:
            str_arg1 = default_syms
    
    print "syms=%s" % str(str_arg1)
    printkHB(str_arg1)
    return None
    
new_command("hb-printk",
    hb_printk,
    [arg(str_t, "syms", "?", None),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Display the kernel printk buffer",
    doc = """
Parameters: \n
        in = SYMS file \n
 
Defaults: \n
        'syms' = './hbicore.syms' \n\n

Examples: \n
    hb-printk \n
    hb-printk ../hbicore.syms \n
    """)
    
