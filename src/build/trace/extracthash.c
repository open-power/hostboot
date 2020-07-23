/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/trace/extracthash.c $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

/** @file extracthash.c
 *
 *  Usage: 'extracthash foo.o'
 *  Generates foo.o.hash from foo.o
 *
 *  Stripped-down version of tracehash. Temporary fix for linker crash until we
 *  update tracehash and/or our linker. This program only extracts the trace
 *  strings and hashes from an object file and writes them to *.o.hash
 */
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
// Next 2 lines required by new BFD binutils package
#define PACKAGE 1
#define PACKAGE_VERSION 1
#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <endian.h>

/** @struct traceParseInfo
 *
 *  Only used for reference as to the file format of the original files.
 *  See same named structure in trace interface files.
 *
 *  This is the layout of the PARSEINFO_SECTION_NAME sections.
 */
struct traceParseInfo
{
    uint32_t magic;
    uint32_t hash;
    uint16_t len_string;
    uint16_t len_file;
    uint32_t __padding;
    const char string[768];
    const char file[256];
} __attribute__((packed));

/** Suffix name of the sections containing traceParseInfo structs. */
const char* PARSEINFO_SECTION_NAME = "__traceData_parseInfo__DISCARD";
/** String to replace with the basename of the source file. */
const char* TRACEPP_REPLACE_WITH_FILENAME = "TRACEPP_INSERT_FILENAME";
const char* TRACEPP_REPLACE_WITH_FILENAME_SHORT = "\xfe";

/** Macro to verify errors from BFD library. */
#define CHECK_ERR(i) \
    { \
        if (!(i)) \
        { \
            printf("Error: %s\n", bfd_errmsg(bfd_get_error())); \
            printf("\tLine %d : %s\n", __LINE__, #i); \
            exit(-1); \
        } \
    }

/** Macro to verify allocations from BFD library. */
#define CHECK_NONNULL(i) CHECK_ERR(NULL != (i));

/** Global pointer to Original / Source symbol table. */
static asymbol** origsymtab = NULL;
/** Global pointer to Result symbol table. */
static asymbol** symtab = NULL;

/** A linked-list of BFD asymbols */
typedef struct symbol_list
{
    struct symbol_list* next;
    asymbol* sym;
} asymbol_list;

/** Global list of symbols that should be excluded from the result file. */
asymbol_list* filtered_syms = NULL;

/** A linked-list of trace hash-string infos. */
typedef struct hash_string_list
{
    struct hash_string_list* next;

    char* string;       //< Original source string.
    char* file;         //< Original source file.
    uint32_t hash;      //< Calculated hash value of string.

        // These three are used to create an ELF relocation for the
        // format string pointer.
    asymbol* fixup_symbol; //< Symbol of traceCodeInfo object.
    bfd_vma fixup_offset;  //< Offset of traceCodeInfo object in its section.
    bfd_vma fixup_data;    //< Data to place at 'format' location for reloc.

} ahash_string_list;

/** Global linked list of hash-strings. */
ahash_string_list* hash_strings = NULL;
/** Global count of hash strings. */
size_t hash_counts = 0;

/** A linked-list of resulting format strings. */
typedef struct format_list
{
    struct format_list* next;

    char* format;       //< Reduced format string.
    bfd_vma offset;     //< Destination offset in the format string section.

} aformat_list;

/** Global linked list of format strings. */
aformat_list* format_strings = NULL;
/** Current size of the format string section. */
size_t format_offset = 0;
/** Content to place into the format string section. */
char* format_content = NULL;
/** Input file name */
char* inFileName = NULL;

/** Keep the full strings in the code rather than reduce to format strings. */
int full_strings = 0;

uint32_t *in_sect_idx_mod = NULL;
uint32_t *out_sect_idx_mod = NULL;

///--------- Forward Declarations ------------------///

size_t filter_symtab(size_t, size_t);

void parse_traceinfo(bfd*, asection*);
void parse_traceinfo_sections(bfd*, asection*, void*);

int check_hash_collision(ahash_string_list*);
void write_hash_file(const char*);

void determine_section_index_offsets(bfd*, bfd*);

///--------- End Forward Declarations --------------///

/** @fn main
 */
int main(int argc, char** argv)
{
    inFileName = strdup(argv[1]);

    // Open input .o file.
    bfd* inFile = bfd_openr(inFileName, NULL);
    CHECK_ERR(bfd_check_format(inFile, bfd_object));

    // Load symbol table from .o file.
    size_t symsize = bfd_get_symtab_upper_bound(inFile);
    origsymtab = symtab = (asymbol**) malloc(symsize);
    size_t symcount = bfd_canonicalize_symtab(inFile, symtab);

    // Filter symbol table
    symcount = filter_symtab(symsize, symcount);

    // Parse trace info sections and update format-string section size.
    bfd_map_over_sections(inFile, parse_traceinfo_sections, NULL);

    // Write .o.hash file.
    write_hash_file(inFileName);

    bfd_close(inFile);

    return 0;
}

/** @fn filter_symtab
 *
 *  Filters symbols from the source symtab that should not be placed into
 *  the result file.
 *
 *  @param[in] symsize - Size of current symbol table.
 *  @param[in] symcount - Number of current symbols.
 *
 *  @return Number of symbols in new table.
 */
size_t filter_symtab(size_t symsize, size_t symcount)
{
    size_t newcount = 0;

    for(size_t i = 0; i < symcount; i++)
    {
        // Filter symbols without an output section.
        if (NULL == symtab[i]->section->output_section)
        {
            // If the symbol isn't a section symbol then it is a
            // traceParseInfo struct, so create an entry for it on the
            // list of filtered_symbols.
            if (!(symtab[i]->flags & BSF_SECTION_SYM))
            {
                asymbol_list* node = malloc(sizeof(asymbol_list));
                node->next = filtered_syms;
                node->sym = symtab[i];
                filtered_syms = node;
            }
            continue;
        }
    }

    return newcount;
}



/** @fn parse_traceinfo
 *
 *  Parses traceParseInfo sections and extracts the trace information for
 *  each symbol / section.
 *
 *  @param[in] inFile - Source file.
 *  @param[in] s - Source section, should be a traceParseInfo section.
 */
void parse_traceinfo(bfd* inFile, asection* s)
{
    // Get contents of the section.
    bfd_byte* contents = NULL;
    CHECK_ERR(bfd_get_full_section_contents(inFile, s, &contents));

    int big_endian = bfd_big_endian(inFile);
    size_t size = bfd_get_section_size(s);

    // Save a reference to the current position in the hash_strings list.
    ahash_string_list* original_hash_strings = hash_strings;

    // Get relocations for the section.
    size_t relocsize = bfd_get_reloc_upper_bound(inFile, s);
    arelent** relocs = (arelent**) malloc(relocsize);
    size_t reloccount = bfd_canonicalize_reloc(inFile, s,
                                               relocs, origsymtab);

    asymbol_list* list = filtered_syms;
    while(list != NULL)
    {
        // Skip symbols in other sections.
        if (list->sym->section != s)
        {
            list = list->next; continue;
        }

        // Find offset of the symbol in the section (contents).
        size_t traceInfo_pos = list->sym->value;

        struct traceParseInfo parseInfo;
        memcpy(&parseInfo, &contents[traceInfo_pos], sizeof(parseInfo));

        // Check the magic value ("TRAC");
        uint32_t magic = 0;
        if (big_endian)
        {
            magic = be32toh(parseInfo.magic);
        }
        else
        {
            magic = le32toh(parseInfo.magic);
        }

        if (magic != 0x54524143u)
        {
            printf("tracehash: Magic from file %s is 0x%08x, expected 0x%08x\n",
                   inFileName,
                   magic,
                   0x54524143u);
            exit(-1);
        }

        // Read the string length.
        size_t length_str = (big_endian ? bfd_getb16 : bfd_getl16)(&parseInfo.len_string);

        // Read the filename length.
        size_t length_file = (big_endian ? bfd_getb16 : bfd_getl16)(&parseInfo.len_file);

        // Create node for string information.
        ahash_string_list* new_node = malloc(sizeof(ahash_string_list));
        new_node->next = hash_strings;

        // Copy original filename from contents.
        new_node->file = strdup(parseInfo.file);

        const char* replace_string = TRACEPP_REPLACE_WITH_FILENAME;

        // Copy original string from contents, calculate hash.
        char* replace_pos = strstr(parseInfo.string,
                                   TRACEPP_REPLACE_WITH_FILENAME);
        if (NULL == replace_pos)
        {
            replace_string = TRACEPP_REPLACE_WITH_FILENAME_SHORT;
            replace_pos = strstr(parseInfo.string, TRACEPP_REPLACE_WITH_FILENAME_SHORT);
        }

        if (NULL != replace_pos)
        {
            char* filename = basename(new_node->file);
            static const char filesep[] = ": ";

            size_t len_begin = replace_pos - parseInfo.string;
            size_t len_end = strlen(parseInfo.string + len_begin) -
                             strlen(replace_string);
            size_t length = len_begin + strlen(filename) + len_end +
                            strlen(filesep) + 1;
            new_node->string = malloc(length);

            memcpy(new_node->string, parseInfo.string, len_begin);
            new_node->string[len_begin] = '\0';

            strcat(new_node->string, filename);
            strcat(new_node->string, filesep);
            strcat(new_node->string, parseInfo.string + len_begin +
                    strlen(replace_string));
        }
        else
        {
            new_node->string = strdup(parseInfo.string);
        }
        if (big_endian)
        {
            new_node->hash = be32toh(parseInfo.hash);
        }
        else
        {
            new_node->hash = le32toh(parseInfo.hash);;
        }

        // Insert string information onto list.
        if (check_hash_collision(new_node))
        {
            hash_strings = new_node;
            hash_counts++;
        }

        // Increment to next symbol.
        list = list->next;
    }

    // Release memory for contents.
    free(contents);
}

/** @fn parse_traceinfo_sections
 *
 *  Calls parse_traceinfo on any sections containing traceParseInfo structs.
 *
 *  @param[in] inFile - Source file.
 *  @param[in] s - Source section.
 *  @param[in] param(outFile) - Destination file.
 */
void parse_traceinfo_sections(bfd* inFile, asection* s, void* param)
{
    if (NULL != strstr(s->name, PARSEINFO_SECTION_NAME))
    {
        parse_traceinfo(inFile, s);
    }
}

/** @fn check_hash_collision
 *
 *  Searches existing trace strings for any hash collisions.
 *
 *  @return 1 - No collision found, 0 - Collision found.
 */
int check_hash_collision(ahash_string_list* node)
{
    ahash_string_list* list = node->next;

    while(list != NULL)
    {
        if ((list->hash == node->hash) &&
            (0 != strcmp(list->string, node->string)))
        {
            printf("Hash collision detected:\n\t%s\n\t%s\n",
                   list->string, node->string);
            return 0;
        }

        list = list->next;
    }

    return 1;
}

/** @fn write_hash_file
 *
 *  Writes the FSP_TRACE format hash file for the result .o.
 *
 *  @param[in] file - Filename of output file.
 */
void write_hash_file(const char* file)
{
    // No hashes, then no file to write.
    if (NULL == hash_strings) return;

    // Open hash-result file (foo.o.hash).
    char* hash_file_name = malloc(strlen(file) + 6);
    strcpy(hash_file_name,file); strcat(hash_file_name, ".hash");
    FILE* hash_file = fopen(hash_file_name, "w");

    // Output header.
    time_t t = time(NULL);
    char* t_str = ctime(&t);
    (*strchr(t_str, '\n')) = '\0';

    fprintf(hash_file, "#FSP_TRACE_v2|||%s|||BUILD:%s\n",
            t_str,
            get_current_dir_name());

    // Iterate through all the strings.
    ahash_string_list* list = hash_strings;
    while(NULL != list)
    {
        // Output hash value.
        fprintf(hash_file, "%u||", list->hash);

        // Output original string and fix-up special symbols, such as '\n'.
        for (size_t i = 0; list->string[i] != '\0'; i++)
        {
            if (list->string[i] == '\n')
            {
                fputs("\\n", hash_file);
            }
            else if (list->string[i] == '\t')
            {
                fputs("\\t", hash_file);
            }
            else
            {
                fputc(list->string[i], hash_file);
            }
        }

        // Output source file name (ex foo.C).
        fprintf(hash_file, "||%s\n", list->file);

        list = list->next;
    }

    fclose(hash_file);
}
