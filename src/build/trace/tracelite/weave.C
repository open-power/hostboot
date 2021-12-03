/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/trace/tracelite/weave.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

// Build via: g++ -std=gnu++0x weave.C -o weave

// The weave tool will parse tracelite output containing hex hash values in
// place of trace strings, and output the full human-readable trace file.
// The hbotStringFile contains the translation between hash data and
// trace strings.


#include <stdio.h>
#include <unordered_map>
#include <cstdlib>
#include <string.h>
#include <stdint.h>


std::unordered_map<uint32_t,char*> g_hbotStrings;

const uint32_t MAX_CHARS = 2048;
char g_chars[MAX_CHARS] = "";
char g_lookback[12] = "           ";
int g_index = 0;
const char g_trace_lite[12] = "trace_lite ";
char g_ch = 0; // last character read from stdin
FILE* debugfd = NULL;
char debugfile[100] = {};
int G_debug = 0;

// storage for parameters
const int MAX_PARAMS = 10;
uint64_t param[MAX_PARAMS] = {};

// storage for string parameters
const int MAX_STRING_SIZE = 256;
char string[MAX_PARAMS][MAX_STRING_SIZE] = {};

#define DBG_TRACE(_fmt_, _args_...) \
    if (debugfd) { fprintf(debugfd, _fmt_, ##_args_); }


// Find 'trace_lite ' in the lookback string
bool lookback_equals_trace_lite()
{
    bool ret = true;
    int x = 0;
    int y = g_index;
    for (x=0, y=g_index; x<11; x++, y = (y + 1) % 11)
    {
        //DBG_TRACE("\g_trace_lite[x]=%c g_lookback[y]=%c",
        //        g_trace_lite[x],g_lookback[y]);
        ret = ret && (g_trace_lite[x] == g_lookback[y]);
    }

    //DBG_TRACE("\nreturn %s",r?"true","false");
    return ret;
}

// Only increment up to max chars size
inline unsigned inc_amt(const char* c)
{
    return !(c == (g_chars + MAX_CHARS));
}

// Only increment up to base + len size
inline unsigned inc_amt2(const char* c, const char* base, const size_t len)
{
    return !(c == (base + len));
}

// Return true if ascii number
inline int isnum(const int c)
{
    return c >= '0' && c <= '9';
}

// Get the integer parameter from the trace output
// Return uint64_t value of parameter
uint64_t parseint()
{
    char* c = g_chars;
    char* end = g_chars + (MAX_CHARS-1);
    uint64_t r = 0;

    // Get the integer parameter as string
    DBG_TRACE("\nparseint called ");
    while ((g_ch=fgetc(stdin))!=' ' && c != end && g_ch != '\n')
    {
        *c = g_ch;
        c++;
    }
    *c = '\0';
    DBG_TRACE("got a string: %s; ",g_chars);

    // Use sscanf to get the uint64_t value
    int rc = sscanf(g_chars,"%lX",&r);
    if (rc == EOF)
    {
        DBG_TRACE("parseint(): ERROR sscanf returned EOF");
    }
    else
    {
        DBG_TRACE("scanned value: %lX\n",r);
    }

    return r;
}

// Get the string parameter from the trace output
// Return the address of the saved string
uint64_t parsestring(const int i)
{
    char* c = string[i];
    char* end = string[i] + (MAX_STRING_SIZE-1);

    DBG_TRACE("\nparsestring called ");

    // Get the string parameter
    while ((g_ch=fgetc(stdin))!='"' && c != end)
    {
        *c = g_ch;
        c++;
    }
    *c = '\0';

    // If string is longer than 255 then dump remaining to the debug trace
    while (g_ch != '"')
    {
        g_ch=getc(stdin);
        DBG_TRACE("parsestring():  skipping 0x%X char -> '%c'",
                g_ch, g_ch);
    }
    DBG_TRACE("got a string: %s at addr %lX\n",
            string[i],reinterpret_cast<unsigned long>(string[i]));

    return reinterpret_cast<uint64_t>(string[i]);
}

// Count the number of % in hbotStringFile trace
int countpercents(const char *str)
{
    const char* c = str;
    int r = 0;

    while (*c != '\0')
    {
        if (*c == '%') r++;
        c++;
    }
    return r;
}

// Function to read in the hbotStringFile
int readstringfile(const char* inFile)
{
    FILE* hbotFile = fopen(inFile,"r");
    char* newString = nullptr;
    char* modString = nullptr;
    size_t newSize = 0;
    uint32_t key = 0;

    if (!hbotFile)
    {
        DBG_TRACE("could not open hbotStringFile\n");
        return 1;
    }

    // Infinite loop until end-of-file
    for(;;)
    {
        // g_chars is a large global char string
        modString = g_chars;

        // Go to the end of the current line
        // g_ch is a global character
        while ((g_ch=fgetc(hbotFile)) != '\n')
        {
            if (g_ch == EOF)
            {
                break;
            }
        }
        if (g_ch == EOF)
        {
            break;
        }

        // Get the hash key at begining of line
        // Looks similar to:  1000146711
        while (isnum(g_ch=fgetc(hbotFile)))
        {
            *modString = static_cast<char>(g_ch);
            modString += inc_amt(modString);
        }
        if (g_ch == EOF)
        {
            break;
        }
        *modString = '\0';

        // Save the key
        int rc = sscanf(g_chars,"%u",&key);
        if (rc == EOF)
        {
            break;
        }

        // Reset the modString to global g_chars
        modString = g_chars;

        // Ignore the verticle bars: ||
        while ((g_ch=fgetc(hbotFile)) == '|');
        if (g_ch == EOF)
        {
            break;
        }

        // Get the trace string, example:
        // eff_dimm.C: Failed getting EFF_DRAM_WIDTH
        *modString = (char)g_ch;
        modString += inc_amt(modString);

        while ((g_ch=fgetc(hbotFile)) != '|')
        {
            *modString = (char)g_ch;
            modString += inc_amt(modString);
        }
        *modString = '\0';

        if (g_ch == EOF)
        {
            break;
        }

        // Save the size of the trace string
        newSize = static_cast<size_t>(reinterpret_cast<uint64_t>(modString)
                                    - reinterpret_cast<uint64_t>(g_chars));
        //printf("size = %i ",newSize);

        // Allocate space for the trace string + endline + endstring
        newString = new char[newSize+2];

        // Save the trace string
        memcpy(newString,g_chars,newSize);
        newString[newSize]   = '\n';
        newString[newSize+1] = '\0';

        // Trace the key and trace for debug
        if (G_debug > 2)
        {
            DBG_TRACE("hbotStringFile hash %.8X = %s", key, newString);
        }

        // Set the g_hbotStrings map entry for this key to this trace
        g_hbotStrings[key] = newString;
        newString = nullptr;

        if (g_ch == EOF)
        {
            break;
        }
    } // for

    if (hbotFile)
    {
        fclose(hbotFile);
    }

    return 0;
}

// Match hbotStringFile key to trace outupt
// Add trace string and parameters to final output
void inputloop()
{
    char* value = nullptr;
    size_t size = 0;
    uint32_t key = 0;
    int i = 0;
    int num_params = 0;

    // Infinite loop until end-of-file
    for(;;)
    {
        // Preload first 10 characters of the line
        for (g_index=0; g_index<10; g_index++)
        {
            g_ch=fgetc(stdin);
            g_lookback[g_index] = g_ch;
        }

        // Search for first occurance of trace_lite from stdin
        // Stop reading stdin right after 'trace_lite ' is found
        while (1)
        {
            g_ch=fgetc(stdin);
            g_lookback[g_index] = g_ch;
            g_index = (g_index+1) % 11;
            if (lookback_equals_trace_lite())
            {
                break;
            }
            g_ch = g_lookback[g_index];
            if (g_ch == EOF)
            {
                return;
            }
            int rc = putc(g_ch,stdout);
            if (rc == EOF)
            {
                printf("ERROR writing to stdout!\n");
                return;
            }
        }

        // Found trace_lite keyword, get following key data
        int rc = fscanf(stdin,"%X",&key);
        DBG_TRACE("\nfscanf key rc %d",rc);
        if (rc == EOF)
        {
            break;
        }
        DBG_TRACE("\n-------------\nlooking up key %X\n",key);

        // Find matching key in hbotStringFile
        if (g_hbotStrings.find(key) == g_hbotStrings.end())
        {
            DBG_TRACE("key not found!\n");

            // Go to the end of the line
            while (g_ch=fgetc(stdin) != '\n' && g_ch != '\r' && g_ch != EOF);
            int rc = putc(g_ch,stdin);
            if (rc == EOF)
            {
                printf("ERROR writing to stdin!\n");
            }
            continue;
        }

        // Assuming here that # of % = # of parameters
        int num_parms = countpercents(g_hbotStrings[key]);
        DBG_TRACE("num_parms = %i\n", num_parms);

        // Make sure num_params doesn't exceed max allowed
        if (num_parms > MAX_PARAMS)
        {
            fprintf(stdout,
                "Exceeded max params allowed. Found %d, Max %d, Invalid key %s",
                num_parms, MAX_PARAMS, g_hbotStrings[key]);
            num_parms = MAX_PARAMS;  // avoid array access out-of-bounds
        }

        // Get the next char after the key
        g_ch = fgetc(stdin);
        DBG_TRACE("\nthe key is %.8X and next char is '%c'\n",key,g_ch);
        if (g_ch == EOF)
        {
            break;
        }

        // Fill in parameters (only string and int are supported)
        for (i=0; i<num_parms; ++i)
        {
            g_ch=fgetc(stdin);
            DBG_TRACE("\ni=%i next char is '%c' 0x%x\n",i,g_ch,g_ch);

            // Ignore white space
            while (g_ch == ' ')
            {
                g_ch=fgetc(stdin);
            }

            // Get the string
            if (g_ch=='"')
            {
                param[i] = parsestring(i);
            }

            // Get the integer
            else if (g_ch >= '0' && g_ch <= '9' ||
                    g_ch >= 'A' && g_ch <= 'F')
            {
                ungetc(g_ch,stdin);
                param[i] = parseint();
            }
        }

        char * stringkey = g_hbotStrings[key];
        DBG_TRACE("\n%s ",stringkey);

        // Check for endline
        char lastChar = stringkey[strlen(stringkey)-1];
        if (lastChar != '\n')
        {
            printf("ERROR: expected all stringkeys to end with 0x0A nl char\n");
            printf("Last character = 0x%X '%c'\n", lastChar, lastChar);

            DBG_TRACE("ERROR: expected all stringkeys to end with 0x0A nl char\n");
            DBG_TRACE("Last character = 0x%X '%c'\n", lastChar, lastChar);
        }

        // Dump params to debug file
        for ( int j = 0;j < i; ++j )
        {
            DBG_TRACE("p%d=%lX ",j, param[j]);
        }

        // Add parameters to output
        switch(i)
        {
        case 0:
            rc = fputs(stringkey,stdout);
            if (rc == EOF)
            {
                printf("ERROR writing stringkey to stdout!\n");
            }
            break;
        case 1:
            fprintf(stdout,stringkey,param[0]);
            break;
        case 2:
            fprintf(stdout,stringkey,param[0],param[1]);
            break;
        case 3:
            fprintf(stdout,stringkey,param[0],param[1],param[2]);
            break;
        case 4:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3]);
            break;
        case 5:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4]);
            break;
        case 6:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4],param[5]);
            break;
        case 7:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4],param[5],param[6]);
            break;
        case 8:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4],param[5],param[6],param[7]);
            break;
        case 9:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4],param[5],param[6],param[7],
                                    param[8]);
            break;
        case 10:
            fprintf(stdout,stringkey,param[0],param[1],param[2],param[3],
                                    param[4],param[5],param[6],param[7],
                                    param[8],param[9]);
            break;
        default:
            fprintf(stdout,"Unsupported parameter number: %d, %s\n",
                    i, stringkey);
            break;
        }

        // clear out any remaining line characters of current line
        if ((g_ch != '\n') && (g_ch != EOF))
        {
            i = 0;
            DBG_TRACE("\nClear line: ");

            while ((g_ch != '\n') && (g_ch != EOF))
            {
                g_chars[i++] = g_ch;
                DBG_TRACE("%X ",g_ch);
                g_ch=fgetc(stdin);
            }
            g_chars[i] = '\0';
            DBG_TRACE("\n%s\n", g_chars);
        }
        fprintf(stdout, "\r");

        // clean up the string, no longer need it
        if (stringkey)
        {
            delete stringkey;
        }

    }
}

// Main weave function
// Requires hbotStringFile, debug file is optional
int main(int argc, char** argv)
{
    int main_ret = 0;
    if (argc < 2)
    {
        printf("usage: cat traceFile | weave hbotStringFile [debugFile]\n");
        return 1;
    }
    if (argc > 2)
    {
        strcpy(debugfile, argv[2]);
        debugfd = fopen(debugfile,"w+");
        if (!debugfd)
        {
            printf("Error: could not open debug file (%s)\n",debugfile);
            return 2;
        }
    }

    // Read the hbotStringFile
    int hbot_ret = readstringfile(argv[1]);

    // Try to parse stdin, whether or not hbotStringFile was parsed correctly
    inputloop();

    // Close the debug file
    if (debugfd)
    {
        fclose(debugfd);
    }

    // Return non-zero if there was a problem with the hbotStringFile
    if (hbot_ret)
    {
        main_ret = 3;
    }

    return main_ret;
}
