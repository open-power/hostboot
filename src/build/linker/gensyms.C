/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/linker/gensyms.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <stdint.h>
#include <cstring>
#include <endian.h>
#include <assert.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#ifndef be64toh
    #include <byteswap.h>
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define be64toh(x) __bswap_64(x)
    #else
        #define be64toh(x) (x)
    #endif
#endif


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

/** Read the symbols from a module.
 *
 *  @param[in] pair<string, uint64_t>* - Pair of <Path of module, offset >.
 *
 *  Parameters are passed as a (void*) to allow this function to be started
 *  as a thread.
 *
 *  @return Unused.
 */
void* read_module_symbols(void*);

    /** Module information parsed from modinfo.  <Module, Offset> */
vector<pair<string, uint64_t> > g_modules;

    /** Name / path of the base image. */
string g_imageName;
    /** Name / path of the extended image. */
string g_extImageName;
    /** Pointer to the mmap of the base image. */
const char* g_imageFile;
    /** Size of the base image file. */
size_t g_imageFileSize;
    /** Pointer to the mmap of the extended image. */
const char* g_extImageFile;
    /** Size of the extended image file. */
size_t g_extImageFileSize;
    /** Offset (in memory) that the extended image is to be loaded at. */
uint64_t g_extImageOffset = ULONG_MAX;

    /** Cached value of the CROSS_PREFIX environment variable, used to
     *  call binutils tools. */
char* g_crossPrefix = NULL;

    /** Resulting symbol addresses and names.
     *
     *  This is a multimap because there are some symbol addresses with
     *  multiple names.  Ex. the data_start_address often collides with
     *  a global symbol in the data section.
     */
multimap<uint64_t, string> g_symbols;
    /** Mutex to protect symbol map. */
pthread_mutex_t g_symbolMutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv)
{
    // Allow one argument (base image) or three arguments (base, extend, offset)
    if ((argc != 2) && (argc != 4))
    {
        print_usage();
    }

    // Get base image name.
    g_imageName = argv[1];
    add_image_subdir(g_imageName);

    // Get extended image name.
    if (argc > 3)
    {
        g_extImageName = argv[2];
        add_image_subdir(g_extImageName);

        // Read extended image offset from options.
        if (1 != sscanf(argv[3], "%lx", &g_extImageOffset))
        {
            print_usage();
        }
    }

    // Open base image.
    int base_fd = open(g_imageName.c_str(), O_RDONLY);
    if (-1 == base_fd)
    {
        fprintf(stderr, "Failed to open image file: %s.\n", g_imageName.c_str());
        exit(-1);
    }
    struct stat base_stat;
    if (0 != fstat(base_fd, &base_stat))
    {
        fprintf(stderr, "Failed to stat image file: %s.\n", g_imageName.c_str());
        exit(-1);
    }
    g_imageFileSize = base_stat.st_size;
    g_imageFile = (const char*) mmap(NULL, base_stat.st_size,
                                     PROT_READ, MAP_PRIVATE,
                                     base_fd, 0);

    // Open extended image.
    if (string() != g_extImageName.c_str())
    {
        int ext_fd = open(g_extImageName.c_str(), O_RDONLY);
        if (-1 == ext_fd)
        {
            fprintf(stderr, "Failed to open image file: %s.\n", g_extImageName.c_str());
            exit(-1);
        }
        struct stat ext_stat;
        if (0 != fstat(ext_fd, &ext_stat))
        {
            fprintf(stderr, "Failed to stat image file: %s.\n", g_extImageName.c_str());
            exit(-1);
        }
        g_extImageFileSize = ext_stat.st_size;
        g_extImageFile = (const char*) mmap(NULL, ext_stat.st_size,
                                            PROT_READ, MAP_PRIVATE,
                                            ext_fd, 0);
    }

    // Read CROSS_PREFIX environment variable.
    g_crossPrefix = getenv("CROSS_PREFIX");
    if (NULL == g_crossPrefix)
    {
        fprintf(stderr, "Environment variable CROSS_PREFIX not set.\n");
        exit(-1);
    }
    g_crossPrefix = strdup(g_crossPrefix);

    // Parse modinfo file for base image.
    parse_modinfo_file(g_imageName);

    // Create threads for each ELF object in the image(s) to get their symbol
    // information.
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
            pthread_create(thread, NULL, read_module_symbols,
                           new pair<string,uint64_t>(*i));
            threads.push_back(thread);
        }
    }

    // Wait for all threads to finish.
    for(vector<pthread_t*>::const_iterator i = threads.begin();
        i != threads.end(); ++i)
    {
        pthread_join(*(*i), NULL);
    }

    // Output (in order) each symbol information.
    for (multimap<uint64_t, string>::const_iterator i = g_symbols.begin();
         i != g_symbols.end(); ++i)
    {
        printf("%s", i->second.c_str());
    }

    return 0;
}

void print_usage()
{
    fprintf(stderr, "gensyms <image> [<extimage> <extoffset>]\n");
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
        fprintf(stderr, "Unable to open modinfo file.\n");
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

void* read_module_symbols(void* input)
{
    // Get module name and offset from input parameter.
    pair<string, uint64_t>* mod_info =
        reinterpret_cast<pair<string,uint64_t>*>(input);
    const string& module = mod_info->first;
    uint64_t addr = mod_info->second;

    // Determine the full path to the module based on the base image path.
    // Assumes they are in the same subdirectory.
    string module_path = g_imageName.substr(0, g_imageName.rfind('/') + 1) +
                         module;

    const char* demangle = " -C ";

    if (getenv("HOSTBOOT_GENSYMS_NO_DEMANGLE"))
    {
        demangle = "";
    }

    // Create the 'objdump' command for finding all the symbols and start as
    // a sub-process.
    string command = string(g_crossPrefix) + "objdump --syms " + demangle +
                     module_path;
    FILE* pipe = popen(command.c_str(), "r");
    if (NULL == pipe) return NULL;

    // Local symbol map (to reduce contention on the global symbol map).
    //   No need to use the overhead of a map because we don't care about
    //   order at this point.
    vector<pair<uint64_t, string> > l_symbols;

    // Parse each line of the 'objdump' output.
    char line[1024];
    do
    {
        if (NULL == fgets(line, 1024, pipe)) break;

        size_t linelen = strlen(line);

        // Skip absolute values (ex. constants) and undefined symbols.
        if (strstr(line, "*ABS*") || strstr(line, "*UND*")) continue;
        // Skip section symbols (marked by 'd' in the 22nd column).
        if (linelen > 22 && 'd' == line[22]) continue;

        // First part of an objdump line is the symbol address, parse that.
        uint64_t line_address;
        if (1 != sscanf(line, "%16lx", &line_address)) continue;
        line_address += addr;

        // Determine if the symbol is a function and if it is in the .rodata
        // section.  Symbols in the .rodata section have a slightly longer
        // line than those in the .text/.data sections (by 2 characters).
        bool is_function = (linelen > 23 && 'F' == line[23]);
        size_t rodata = (NULL != strstr(line, ".rodata")) ? 2 : 0;

        // Parse the symbol size.
        uint64_t symbol_size;
        if (linelen > 32+rodata &&
            1 != sscanf(&line[32+rodata], "%lx", &symbol_size)) continue;

        // Parse the function name.
        assert(linelen > 48+rodata);
        string function = &line[48+rodata];
        function.resize(function.length() - 1); // remove the newline.

        // Function have two addresses: TOC entry and code address.  Objdump
        // gives the TOC entry, so we need to read the file itself to determine
        // the code address.  The first part of the TOC entry is the code
        // address.
        uint64_t code_addr = 0;
        if (is_function)
        {
            // Module is in the extended image, read from it.
            if (line_address > g_extImageOffset)
            {
                // Read code address.
                assert((line_address - g_extImageOffset) < g_extImageFileSize);
                memcpy(&code_addr,
                       &g_extImageFile[line_address - g_extImageOffset], 8);
            }
            // Module is in the base image.
            else
            {
                // Read code address.
                assert(line_address < g_imageFileSize);
                memcpy(&code_addr, &g_imageFile[line_address], 8);
            }
            // Fix up the endianness.
            code_addr = be64toh(code_addr);

            std::swap(code_addr, line_address);
        }

        // Print all of this into a new line and add to the symbol map.
        sprintf(line, "%c,%08lx,%08lx,%08lx,%s\n",
            is_function ? 'F' : 'V',
            line_address, code_addr, symbol_size,
            function.c_str());

        l_symbols.push_back(make_pair(line_address, line));

    } while(1);

    // Close subprocess (done).
    pclose(pipe);

    // Copy our local symbol list all at once into the global symbol list.
    pthread_mutex_lock(&g_symbolMutex);
    g_symbols.insert(l_symbols.begin(), l_symbols.end());
    pthread_mutex_unlock(&g_symbolMutex);

    return NULL;
}
