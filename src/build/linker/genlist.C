/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/linker/genlist.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <regex.h>
#include <assert.h>

using namespace std;

/** Print tool usage */
void print_usage();

/** Prepend to a path the img/ subdirectory.
 *
 *  @param[in,out] io_path - The path to modify / prepend to.
 */
void add_image_subdir(string& io_path);

/** Parse the image.modinfo file.
 *
 *  @param[in] i_image - The path to the image to parse the corresponding
 *                       modinfo.
 */
void parse_modinfo_file(const string& i_image);

/** Parse the image.syms file.
 *
 *  @param[in] i_image - The path to the image ot parse the corresponding
 *                       syms file.
 */
void parse_syms_file(const string& i_image);

/** Find / create a symbol name for an address.
 *
 *  @param[in] i_addr - The address to find a symbol for.
 *  @param[in] i_match - Require an exact match in the symbol file.
 *
 *  @return The symbol name found / created (or an empty string).
 *
 *  If a match is required, this function will return the symbol at the
 *  address requested or an empty string.
 *
 *  If a match is not required, this function will return the symbol at the
 *  address requested or create a string of the form "symbol+offset".  This
 *  is useful for labeling the targets of branches.
 */
string find_symbol_name(uint64_t i_addr, bool i_match = false);

/** Read the listing of the module and update symbol names, labels, etc.
 *
 *  @param[in] pair<string, uint64_t>* - Pair of <Path of module, offset>.
 *
 *  Parameters are passed as a (void*) to allow this function to be started
 *  as a thread.
 *
 *  @return Pointer to a string containing the module's listing.
 */
void* read_module_content(void*);

    /** Module information parsed from modinfo.  <Module, Offset> */
vector<pair<string, uint64_t> > g_modules;
    /** Symbols parsed from sym file. <addr, symbol> */
map<uint64_t, string> g_symbols;

    /** Name / path of the base image. */
string g_imageName;
    /** Cached value of the CROSS_PREFIX environment variable, used to
     *  call binutils tools. */
char* g_crossPrefix = NULL;

int main(int argc, char** argv)
{
    // Only parameter allowed is the name of the base image.
    if (argc != 2)
    {
        print_usage();
    }

    // Get base image name from parameters.
    g_imageName = argv[1];
    add_image_subdir(g_imageName);

    // Read CROSS_PREFIX environment variable.
    g_crossPrefix = getenv("CROSS_PREFIX");
    if (NULL == g_crossPrefix)
    {
        printf("Environment variable CROSS_PREFIX not set.\n");
        exit(-1);
    }
    g_crossPrefix = strdup(g_crossPrefix);

    // Parse modinfo and symbols files.
    parse_modinfo_file(g_imageName);
    parse_syms_file(g_imageName);

    // Create threads for each ELF object in the image to get their listing.
    vector<pthread_t*> threads;
    for(vector<pair<string, uint64_t> >::const_iterator i = g_modules.begin();
        i != g_modules.end(); ++i)
    {
        const string& m = i->first;
        // Filter out non-ELF files by filename.
        if (strstr(m.c_str(), ".o") || strstr(m.c_str(), ".elf") ||
            strstr(m.c_str(), ".so"))
        {
            pthread_t* thread = new pthread_t;
            pthread_create(thread, NULL, read_module_content,
                           new pair<string,uint64_t>(*i));
            threads.push_back(thread);
        }
    }

    // Wait for all threads to finish and display listing result from each.
    //    Since we started in the address order and join in that same order
    //    the output becomes in-order as well.
    for (vector<pthread_t*>::const_iterator i = threads.begin();
         i != threads.end(); ++i)
    {
        char* result;
        pthread_join(*(*i), (void**)&result);
        if (result)
        {
            printf("%s", result);
            free(result);
        }
    }

    return 0;
}

void print_usage()
{
    printf("genlist <image>\n");
    exit(-1);
}

void add_image_subdir(string& io_path)
{
    // Prepend ./img if the path to the image directory is not already part
    // of the path.
    if (string::npos == io_path.find("img"))
    {
        io_path.insert(0, "./img/");
    }
}

void parse_modinfo_file(const string& i_image)
{
    // Open modinfo file.
    string modinfo_name = i_image + ".modinfo";
    FILE* modinfo_file = fopen(modinfo_name.c_str(), "r");
    if (NULL == modinfo_file)
    {
        printf("Unable to open modinfo file.\n");
        exit(-1);
    }

    // Parse one line at a time.
    char line[1024];
    do
    {
        // fgets returns NULL when no additional lines are present, break.
        if (NULL == fgets(line, 1024, modinfo_file)) break;

        // Lines should be formatted: "object,offset\n"

        // Skip lines without a comma.
        char* comma = strchr(line, ',');
        if (NULL == comma) continue;

        // Extract module name (everything before comma).
        string mod_name(line, comma - line);

        // Parse module offset (hex integer after comma).
        uint64_t mod_addr;
        if (1 != sscanf(comma+1, "0x%lx", &mod_addr)) continue;

        // Add to the module list.
        g_modules.push_back(make_pair(mod_name, mod_addr));

    } while(1);
}

void parse_syms_file(const string& i_image)
{
    // Determine syms filename.
    string syms_name = i_image;
    syms_name.erase(syms_name.size() - 4); // Remove .bin
    syms_name += ".syms";

    // Open syms file.
    FILE* syms_file = fopen(syms_name.c_str(), "r");
    if (NULL == syms_file)
    {
        printf("Unable to open syms file.\n");
        exit(-1);
    }

    // Parse one line at a time.
    char line[1024];
    do
    {
        // fgets returns NULL when no additional lines are present, break.
        if (NULL == fgets(line, 1024, syms_file)) break;

        // Lines are formatted:
        //     [VF],addr,addr,size,symbol

        // Parse addresses from line.
        uint64_t addr,addr2;
        if (2 != sscanf(&line[2], "%lx,%lx", &addr, &addr2)) continue;

        // Parse symbol name from line.
        char* name = line;
        for(int i = 0; i < 4; i++)
        {
            name = index(name, ',') + 1;
        }
        if (NULL == name) continue;

        string realname = name;
        realname.erase(realname.size() - 1); // remove newline.

        // Insert symbol into map.
        g_symbols.insert(make_pair(addr, realname));

        // If this is a function, also add the second address, which is the
        // address of the TOC entry.
        if ('F' == line[0])
        {
            g_symbols.insert(make_pair(addr2, realname));
        }

    } while(1);
}

string find_symbol_name(uint64_t addr, bool match)
{

    // Use lower_bound to find the symbol (or the symbol immediately after).
    map<uint64_t, string>::const_iterator sym =
        g_symbols.lower_bound(addr);

    // If we found a match, return it.
    if ((sym != g_symbols.end()) && (addr == sym->first))
    {
        return sym->second;
    }

    // Otherwise we are one past since lower_bound returns the symbol after,
    // so decrement.
    sym--;

    // Check again for a match (though this shouldn't happen).
    if (addr == sym->first)
    {
        return sym->second;
    }
    // If we require an exact match return empty string.
    else if (match)
    {
        return string();
    }
    // Create the "symbol+offset" string.
    else
    {
        char hex[16];
        sprintf(hex, "%lx", addr - sym->first);

        return sym->second + string("+0x") + hex;
    }
}

void* read_module_content(void* input)
{
    // Get module name and offset from input parameter.
    pair<string, uint64_t>* mod_info =
        reinterpret_cast<pair<string,uint64_t>*>(input);
    const string& module = mod_info->first;
    uint64_t mod_addr = mod_info->second;

    // Determine the full path to the module based on the base image path.
    // Assumes they are in the same subdirectory.
    string module_path = g_imageName.substr(0, g_imageName.rfind('/') + 1) +
                         module;

    // Create the 'objdump' command for finding all the symbols and start as
    // a sub-process.
    //    -d - Disassemble sections containing code.
    //    -C - Intersparse C code.
    //    -S - Demangle symbol names.
    //    -j .text, .data, .rodata - Only dump those 3 sections.
    string command = string(g_crossPrefix) +
                     string("objdump -dCS -j .text -j .data -j .rodata ") +
                     module_path;
    FILE* pipe = popen(command.c_str(), "r");
    if (NULL == pipe) return NULL;

    // Start result string and add module start header.
    string result;
    result += "BEGIN MODULE ---- " + module + " ----\n";

    size_t sections = 0;        // Count of sections observed.
    bool enabled = false;       // Boolean to enable / disable listing output.

    // --- Regular expressions ---

        // Identify asm lines by the address at the beginning.
    regex_t find_address;
    assert(0 == regcomp(&find_address,
                        "^\\([[:blank:]]\\+\\)\\([0-9a-f]\\+\\):", 0));

        // Identify function headers: "address <symbol>:"
    regex_t function_header;
    assert(0 == regcomp(&function_header,
                        "^\\([0-9a-f]\\+\\) <.*>:", 0));

        // Identify branch instructions: ex "bdnz+ addr <symbol>".
    regex_t branch_instruction;
    assert(0 == regcomp(&branch_instruction,
                        "b[a-z]*[+-]*[[:blank:]]\\+\\(.*,\\)\\{0,1\\}"
                        "\\([0-9a-f]\\+\\)[[:blank:]]\\+<\\(.*\\)>", 0));

    // --- End regular expressions ---

    uint64_t prev_addr = 1; // Choose 1 because no symbol should be at address
                            // 1, unlike address 0.
    char line[1024];
    do
    {
        // End if all appropriate output has been parsed, or EOF.
        if (!enabled && (sections >= 3)) break;
        if (NULL == fgets(line, 1024, pipe)) break;

        // Identify the beginning of a new section.
        if (strstr(line, "Disassembly of section"))
        {
            // Only allow interpretation of the 3 sections we are interested in.
            if (strstr(line, ".text") || strstr(line, ".rodata") ||
                strstr(line, ".data"))
            {
                enabled = true;
                sections++;
            }
            else
            {
                enabled = false;
            }
        }
        // Output is enabled so interpret it.
        else if (enabled)
        {
            // Look for an asm line (by finding the address at the beginning).
            regmatch_t matches[4];
            if (REG_NOMATCH != regexec(&find_address, line, 3, matches, 0))
            {
                // Parse address.
                string address(&line[matches[2].rm_so],
                               matches[2].rm_eo - matches[2].rm_so);

                uint64_t addr_value = 0;
                sscanf(address.c_str(), "%lx", &addr_value);
                addr_value += mod_addr;  // Add module offset to get real
                                         // memory address.

                // If the address hasn't been seen before, this may be the
                // first address for a new symbol, so check for that.
                if (addr_value != prev_addr)
                {
                    string name = find_symbol_name(addr_value, true);

                    // First address line for a symbol, output symbol header.
                    if (string() != name)
                    {
                        char function_start[1024];
                        sprintf(function_start, "%016lx <%s>:\n",
                                addr_value, name.c_str());

                        result += function_start;
                    }
                }

                // Output original address.
                result += string(line, matches[2].rm_eo);
                result += "\t";
                // Output offsetted address.
                char addr_text[16];
                sprintf(addr_text, "%08lx", addr_value);
                result += addr_text;

                // Shift address portion out of the current line.
                size_t line_shift = strlen(line) - matches[2].rm_eo;
                memmove(line, &line[matches[2].rm_eo],
                        line_shift);
                line[line_shift] = '\0';

                // Check if this is a branch instruction.
                if (REG_NOMATCH !=
                    regexec(&branch_instruction, line, 4, matches, 0))
                {
                    // Output everything up to the branch target address.
                    result += string(line, 0, matches[2].rm_so);

                    // Parse the original branch target address, add the
                    // module offset, output offsetted target.
                    uint64_t branch_addr = 0;
                    sscanf(&line[matches[2].rm_so], "%lx", &branch_addr);
                    branch_addr += mod_addr;
                    char branch_addr_txt[16];
                    sprintf(branch_addr_txt, "%lx", branch_addr);
                    result += branch_addr_txt;

                    // Find the symbol name for the branch target and output.
                    result += " <";
                    result += find_symbol_name(branch_addr);
                    result += ">\n";

                }
                else // Non-branch, output as is.
                {
                    result += line;
                }

            }
            // Check for function headers, which may need updating.
            else if (REG_NOMATCH !=
                     regexec(&function_header, line, 2, matches, 0))
            {
                // Get address portion of the function header.
                string address(&line[matches[1].rm_so],
                               matches[1].rm_eo - matches[1].rm_so);

                uint64_t addr_value = 0;
                sscanf(address.c_str(), "%lx", &addr_value);
                addr_value += mod_addr;

                // Find the appropriate symbol name.
                string name = find_symbol_name(addr_value, true);
                if (string() == name) { name = "Unknown Symbol"; }

                // Output new function header.
                char function_start[1024];
                sprintf(function_start, "%016lx <%s>:\n",
                        addr_value, name.c_str());
                result += function_start;

                // Save this address so we don't output a second function
                // header when we see the address line.
                prev_addr = addr_value;
            }
            // Otherwise it is some other line, like C code.  Output as is.
            else
            {
                result += line;
            }
        }

    } while(1);

    // Close the subprocess.
    pclose(pipe);

    // Return the output.
    return strdup(result.c_str());
}
