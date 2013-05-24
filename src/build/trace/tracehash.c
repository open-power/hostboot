/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/trace/tracehash.c $                                 */
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

/** @file tracehash.c
 *
 *  Usage: 'tracehash foo.o'
 *  Generates foo.o and foo.o.hash from foo.o.trace.
 *
 *  The original trace strings are compiled into a foo.o.trace and need
 *  to be extracted and turned into hash numbers.  To accomplish this
 *  we create static structures at the trace call location and use the GCC
 *  options '-ffunction-sections' and '-fdata-sections' to force these
 *  structures into their own ELF sections that we can find / remove / update.
 *
 *  This program uses libbfd, which is not very well documented.  Some of
 *  the sequencing of bfd calls were determined by trial and error.  The
 *  intention is that this program supports [ppc|x86]-[32|64]bit, but
 *  some aspects of BFD / ELF are 'fragile' and may break between compiler
 *  versions.  I have found this is especially true in the interpretation /
 *  creation of relocation information.
 *
 *  Hostboot also uses 'libbfd' for the custom linker so it is likely that
 *  any changes needed here (or there) need to be replicated in both.
 */
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

/** @fn bfd_elf_gnu_hash
 *
 *  Hash function built into the BFD library which has decent non-collision
 *  properties.  The trace tools don't care what hash function is used as
 *  long as it is used consistently.
 *
 *  Alternatively, using a truncated MD5 or SHA hash would likely work as
 *  well.
 */
unsigned long bfd_elf_gnu_hash(const char*);

/** @struct traceCodeInfo
 *
 *  Only used for reference as to the file format of the original files.
 *  See same named structure in trace interface files.
 *
 *  This is the layout of the CODEINFO_SECTION_NAME sections.
 */
struct traceCodeInfo
{
    const char *formatString;
    uint32_t hash;
};

/** @struct traceParseInfo
 *
 *  Only used for reference as to the file format of the original files.
 *  See same named structure in trace interface files.
 *
 *  This is the layout of the PARSEINFO_SECTION_NAME sections.
 */
struct traceParseInfo
{
    uint16_t len_string;
    uint16_t len_file;
    uint32_t padding;
    const char string[512];
    const char file[256];
    struct traceCodeInfo* code;
};

/** Suffix name of the sections containing traceCodeInfo structs. */
const char* CODEINFO_SECTION_NAME = "__traceData_codeInfo";
/** Suffix name of the sections containing traceParseInfo structs. */
const char* PARSEINFO_SECTION_NAME = "__traceData_parseInfo";
/** Destination section name for the resulting format strings. */
const char* FORMATSTRING_SECTION_NAME = ".rodata.str.fsptrace.format";
/** String to replace with the basename of the source file. */
const char* TRACEPP_REPLACE_WITH_FILENAME = "TRACEPP_INSERT_FILENAME";

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
/** Global pointer to BFD section for format strings from hashes. */
asection* hash_section = NULL;

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

///--------- Forward Declarations ------------------///
void create_sections(bfd*, asection*, void*);
void copy_relocs(bfd*, asection*, void*);
void copy_content(bfd*, asection*, void*);
char* create_format_string(const char*);
void create_hashstring_section(bfd*);

size_t filter_symtab(size_t, size_t);
size_t filter_relocs(arelent***, size_t, size_t, const char*);

void parse_traceinfo(bfd*, asection*);
void parse_traceinfo_sections(bfd*, asection*, void*);

int check_hash_collision(ahash_string_list*);
void write_hash_file(const char*);
///--------- End Forward Declarations --------------///

/** @fn main
 */
int main(int argc, char** argv)
{
    static const char* inFileSuffix = ".trace";

    char* outFileName = strdup(argv[1]);

    char* inFileName = (char*) malloc(strlen(outFileName) +
                                      strlen(inFileSuffix) + 1);
    strcpy(inFileName, outFileName);
    strcat(inFileName, inFileSuffix);

    // Open input .o.trace file.
    bfd* inFile = bfd_openr(inFileName, NULL);
    CHECK_ERR(bfd_check_format(inFile, bfd_object));

    // Open output .o file.
    bfd* outFile = bfd_openw(outFileName, bfd_get_target(inFile));
    CHECK_NONNULL(outFile);

    // Copy header data from .o.trace file.
    CHECK_ERR(bfd_set_arch_mach(outFile, bfd_get_arch(inFile),
                                         bfd_get_mach(inFile)));
    CHECK_ERR(bfd_set_format(outFile, bfd_get_format(inFile)));

    // Load symbol table from .o.trace file.
    size_t symsize = bfd_get_symtab_upper_bound(inFile);
    origsymtab = symtab = (asymbol**) malloc(symsize);
    size_t symcount = bfd_canonicalize_symtab(inFile, symtab);

    // Copy over other sections to new file.
    bfd_map_over_sections(inFile, create_sections, outFile);
    // Create hash-string section.
    create_hashstring_section(outFile);

    // Copy ELF private header.
    CHECK_ERR(bfd_copy_private_header_data(inFile, outFile));

    // Filter symbol table and add to destination file.
    symcount = filter_symtab(symsize, symcount);
    bfd_set_symtab(outFile, symtab, symcount);

    // Parse trace info sections and update format-string section size.
    bfd_map_over_sections(inFile, parse_traceinfo_sections, outFile);
    bfd_set_section_size(outFile, hash_section, format_offset);

    // Copy relocations and content into destination file.
    bfd_map_over_sections(inFile, copy_relocs, outFile);
    bfd_map_over_sections(inFile, copy_content, outFile);
    bfd_set_section_contents(outFile, hash_section,
                             format_content, 0, format_offset);

    // Write .o.hash file.
    write_hash_file(outFileName);

    // Copy additional private BFD data and close file.
    CHECK_ERR(bfd_copy_private_bfd_data(inFile, outFile));
    bfd_close(outFile);

    return 0;
}

/** @fn create_sections
 *
 *  Creates a section in the result file based from the corresponding
 *  section in the source file.  Sections which should not be created in
 *  the result are skipped.
 *
 *  @param[in] inFile - Source file.
 *  @param[in] s - Section to create.
 *  @param[in] param(outFile) - Destination file.
 */
void create_sections(bfd* inFile, asection* s, void* param)
{
    bfd* outFile = (bfd*)param;

    // Clear output-file section reference in the source section.
    s->output_section = NULL;

    // Skip traceParseInfo and ELF-groups sections.
    if (NULL != strstr(s->name, PARSEINFO_SECTION_NAME)) { return; }
    if (bfd_get_section_flags(inFile, s) & SEC_GROUP) { return; }

    // Create result section.
    asection* new_s =
        bfd_make_section_anyway_with_flags(outFile, s->name,
                                           bfd_get_section_flags(inFile, s));
    CHECK_NONNULL(new_s);

    // Copy section sizes.
    new_s->entsize = s->entsize;
    size_t section_size = bfd_get_section_size(s);
    CHECK_ERR(bfd_set_section_size(outFile, new_s, section_size));
    CHECK_ERR(bfd_set_section_vma(outFile, new_s, bfd_section_vma(inFile, s)));
    new_s->lma = s->lma;

    // Copy alignment and private data.
    CHECK_ERR(bfd_set_section_alignment(outFile, new_s,
                                        bfd_section_alignment(inFile, s)));
    CHECK_ERR(bfd_copy_private_section_data(inFile, s, outFile, new_s));

    // Hook up output_section reference to source section.
    s->output_section = new_s;
}

/** @fn copy_relocs
 *
 *  Copy relocation information from source section to result section.
 *
 *  @param[in] inFile - Source file.
 *  @param[in] s - Source section.
 *  @param[in] param(outFile) - Destination file.
 */
void copy_relocs(bfd* inFile, asection* s, void* param)
{
    bfd* outFile = (bfd*)param;

    // Get destination section and skip if it doesn't exist.
    asection* new_s = s->output_section;
    if (NULL == new_s) return;

    // Allocate new relocations based on source relocations.
    size_t relocsize = bfd_get_reloc_upper_bound(inFile, s);
    arelent** relocs = (arelent**) malloc(relocsize);
    size_t reloccount = bfd_canonicalize_reloc(inFile, s, relocs, origsymtab);

    // Filter out relocations corresponding to symbols in filtered sections.
    reloccount = filter_relocs(&relocs, relocsize, reloccount,
                               PARSEINFO_SECTION_NAME);

    // If this is a traceCodeInfo section, create new relocations for the
    // format strings.
    if (NULL != strstr(s->name, CODEINFO_SECTION_NAME))
    {
        // Increase number of relocations by number of format strings.
        relocs = (arelent**)
            realloc(relocs, sizeof(arelent*)*(reloccount + hash_counts));

        // Search for relocations in this section.
        ahash_string_list* list = hash_strings;
        while(list != NULL)
        {
            // Section mismatch, continue to next symbol.
            if (list->fixup_symbol->section != s)
            {
                list = list->next;
                continue;
            }

            // Find format string corresponding to this symbol.
            char* format = create_format_string(list->string);
            aformat_list* format_node = format_strings;
            while(format_node != NULL)
            {
                if (0 == strcmp(format, format_node->format))
                {
                    break;
                }

                format_node = format_node->next;
            }
            assert(format_node != NULL);

            // Create relocation.
            relocs[reloccount] = (arelent*) malloc(sizeof(arelent));
            relocs[reloccount]->sym_ptr_ptr = hash_section->symbol_ptr_ptr;
            relocs[reloccount]->address = list->fixup_offset;
            // 64 and 32 bit relocations are done differently.
            //    64 bit has 0 in the destination area and offset in the
            //           relocation itself.
            //    32 bit has offset in the destination area and 0 in the
            //           relocation itself.
            if (bfd_arch_bits_per_address(inFile) == 64)
            {
                relocs[reloccount]->addend = format_node->offset;
                list->fixup_data = 0;
            }
            else
            {
                relocs[reloccount]->addend = 0;
                list->fixup_data = format_node->offset;
            }
            relocs[reloccount]->howto =
                bfd_reloc_type_lookup(outFile,
                    (bfd_arch_bits_per_address(inFile) == 64 ?
                     BFD_RELOC_64 : BFD_RELOC_32)
                );
            reloccount++;

            // Increment to next symbol.
            list = list->next;
        }

        // Turn on relocation flag (in case it wasn't already on).
        new_s->flags |= SEC_RELOC;
    }

    // Assign relocations to result section.
    bfd_set_reloc(outFile, new_s, relocs, reloccount);
}

/** @fn copy_content
 *
 *  Copies (and possibly updates) content from source to result sections.
 *
 *  Sections containing traceCodeInfo need to be updated with new hash and
 *  relocation values.
 *
 *  @param[in] inFile - Source file.
 *  @param[in] s - Source section.
 *  @param[in] param(outFile) - Destination file.
 */
void copy_content(bfd* inFile, asection* s, void* param)
{
    bfd* outFile = (bfd*) param;

    // Get destination section and skip if it doesn't exist.
    asection* new_s = s->output_section;
    if (NULL == new_s) return;

    // Skip if destination section doesn't have any contents.
    if (!(new_s->flags & SEC_HAS_CONTENTS))
    {
        return;
    }

    // Read contents from source section.
    bfd_byte* contents = NULL;
    CHECK_ERR(bfd_get_full_section_contents(inFile, s, &contents));
    size_t content_size = bfd_get_section_size(new_s);

    // Perform fix-ups if this is a traceCodeInfo section.
    if (NULL != strstr(s->name, CODEINFO_SECTION_NAME))
    {
        int big_endian = bfd_big_endian(inFile);
        int sixtyfour = bfd_arch_bits_per_address(inFile) == 64;
        ahash_string_list* list = hash_strings;

        // Search hash list for symbols in this section.
        while(list != NULL)
        {
            // Skip if symbol doesn't match.
            if (list->fixup_symbol->section != s)
            {
                list = list->next;
                continue;
            }

            // Update hash value.
            (big_endian ? bfd_putb32 : bfd_putl32)
                (list->hash,
                 &contents[list->fixup_offset + (sixtyfour ? 8 : 4)]);

            // Update fixup location.
            (big_endian ? (sixtyfour ? bfd_putb64 : bfd_putb32) :
                          (sixtyfour ? bfd_putl64 : bfd_putl32))
                (list->fixup_data, &contents[list->fixup_offset]);

            // Increment to next symbol.
            list = list->next;
        }
    }

    // Write section contents into result section.
    CHECK_ERR(bfd_set_section_contents(outFile, new_s, contents, 0,
                                       content_size));

    // Free temporary content buffer.
    free(contents);
}

/** @fn create_format_string
 *
 *  Creates a stripped down format string based on a source string.
 *
 *  @param[in] string - The source string to strip.
 *  @return Format string allocated with 'malloc'.
 */
char* create_format_string(const char* string)
{
    size_t length = strlen(string) + 1;

    char* result = malloc(length);
    memset(result, '\0', length);

    size_t r_pos = 0; // Current position in result string.

    // Iterate through source string looking for format tags.
    for(size_t pos = 0; pos < length; pos++)
    {
        // Skip if not %.
        if (string[pos] != '%') continue;
        // Skip over %%.
        if (string[pos+1] == '%') { pos++; continue; }

        // Found a valid start of a format tag... start in result.
        result[r_pos++] = '%';

        // Search for remainder of format and copy to result.
        int done = 0;
        do
        {
            switch(string[pos])
            {
                // Length tags.
                case 'h': case 'l': case 'L': case 'q':
                case 'j': case 'z': case 't':
                    result[r_pos++] = string[pos++];
                    break;

                // Type tags.
                case 'd': case 'i': case 'o': case 'u':
                case 'x': case 'X': case 'e': case 'E':
                case 'f': case 'F': case 'g': case 'G':
                case 'a': case 'A': case 'c': case 'C':
                case 's': case 'S': case 'p': case 'n':
                    result[r_pos++] = string[pos];
                    done = 1;
                    break;

                default:
                    pos++;
            }
        } while(!done);
    }

    return result;
}

/** @fn create_hashstring_section
 *
 *  Allocate a section for the format strings and add it to the result file.
 *
 *  @param[in] outFile - Result file.
 */
void create_hashstring_section(bfd* outFile)
{
    hash_section = bfd_make_section(outFile, FORMATSTRING_SECTION_NAME);
    CHECK_NONNULL(hash_section);

    // Set section flags:
    //     SEC_ALLOC - VMA Memory needs to be allocated.
    //     SEC_LOAD - The contents should be loaded into memory.
    //     SEC_READONLY - Read-only content.
    //     SEC_HAS_CONTENTS - The section has contents associated with it.
    //     SEC_MERGE - Duplicate sections (ex. two .o files) should be
    //                 merged together.
    //     SEC_STRINGS - The section content type is string.
    bfd_set_section_flags(outFile, hash_section,
                          SEC_ALLOC | SEC_LOAD | SEC_READONLY |
                          SEC_HAS_CONTENTS | SEC_MERGE | SEC_STRINGS);

    // Each entry is 1 byte (a character).
    hash_section->entsize = 1;
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
    asymbol** new_table = malloc(symsize+sizeof(asymbol*));
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

        // Symbol was not filtered, so copy it to the new table.
        new_table[newcount++] = symtab[i];
    }

    // Insert the symbol for the format string section.
    new_table[newcount++] = hash_section->symbol;

    symtab = new_table;
    return newcount;
}

/** @fn filter_relocs
 *
 *  Filters relocations from the source table the at should not be placed
 *  into the result file.
 *
 *  @param[in,out] relocs - Relocation table.
 *  @param[in] relocsize - Size (in bytes) of relocation table.
 *  @param[in] reloccount - Number of relocations.
 *  @param[in] section - Section name suffix/pattern to filter.
 */
size_t filter_relocs(arelent*** relocs, size_t relocsize,
                     size_t reloccount, const char* section)
{
    arelent** old_table = *relocs;
    arelent** new_table = malloc(relocsize);

    size_t newcount = 0;
    for(size_t i = 0; i < reloccount; i++)
    {
        asymbol** symtable = old_table[i]->sym_ptr_ptr;

        // Skip symbols in sections with pattern match.
        if (NULL != strstr((*symtable)->section->name, section))
        {
            continue;
        }

        // Copy non-skipped symbols into result table.
        new_table[newcount++] = old_table[i];
    }

    free(old_table);
    (*relocs) = new_table;

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
        size_t pos = list->sym->value;

        // Read the string length.
        size_t length_str =
            (big_endian ? bfd_getb16 : bfd_getl16)(&contents[pos]);
        pos += 2;

        // Read the filename length.
        size_t length_file =
            (big_endian ? bfd_getb16 : bfd_getl16)(&contents[pos]);
        pos += 2;

        // Padding
        pos += 4;

        // Create node for string information.
        ahash_string_list* new_node = malloc(sizeof(ahash_string_list));
        new_node->next = hash_strings;

        // Copy original filename from contents.
        new_node->file = strdup(&contents[pos+length_str]);

        // Copy original string from contents, calculate hash.
        char* replace_pos = strstr(&contents[pos],
                                   TRACEPP_REPLACE_WITH_FILENAME);
        if (NULL != replace_pos)
        {
            char* filename = basename(new_node->file);
            static const char filesep[] = ": ";

            size_t len_begin = replace_pos - (char*)&contents[pos];
            size_t len_end = strlen(&contents[pos]) -
                             strlen(TRACEPP_REPLACE_WITH_FILENAME);
            size_t length = len_begin + strlen(filename) + len_end +
                            strlen(filesep) + 1;
            new_node->string = malloc(length);

            memcpy(new_node->string, &contents[pos], len_begin);
            new_node->string[len_begin] = '\0';

            strcat(new_node->string, filename);
            strcat(new_node->string, filesep);
            strcat(new_node->string, &contents[pos + len_begin +
                    strlen(TRACEPP_REPLACE_WITH_FILENAME)]);
        }
        else
        {
            new_node->string = strdup(&contents[pos]);
        }
        new_node->hash = bfd_elf_gnu_hash(new_node->string);

        // Advance position to (traceCodeInfo*).
        pos += length_str + length_file;

        // Search relocations to find the traceCodeInfo symbol.
        for (size_t i = 0; i < reloccount; i++)
        {
            if (relocs[i]->address == pos)
            {
                // Get the symbol itself.
                new_node->fixup_symbol = *(relocs[i]->sym_ptr_ptr);

                // Find offset into the traceCodeInfo's section.
                if (big_endian)
                {
                    new_node->fixup_offset =
                        (bfd_arch_bits_per_address(inFile) == 64 ?
                            bfd_getb64 : bfd_getb32)
                        (&contents[relocs[i]->address]);
                }
                else
                {
                    new_node->fixup_offset =
                        (bfd_arch_bits_per_address(inFile) == 64 ?
                            bfd_getl64 : bfd_getl32)
                        (&contents[relocs[i]->address]);

                }
                new_node->fixup_offset += relocs[i]->addend;
            }
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

    // Create format strings and content blob for CODEINFO_SECTION_NAME.
    ahash_string_list* hash_list = hash_strings;
    while(hash_list != original_hash_strings)
    {
        char* format = create_format_string(hash_list->string);

        // Search for existing format string that matches.
        aformat_list* format_node = format_strings;
        while(format_node != NULL)
        {
            if (0 == strcmp(format, format_node->format))
            {
                break;
            }

            format_node = format_node->next;
        }

        // If we found a matching format string, it is already created.
        if (format_node != NULL)
        {
            free(format);
        }
        else // Create it.
        {
            // Create format string node.
            aformat_list* new_node = malloc(sizeof(aformat_list));
            new_node->next = format_strings;
            new_node->format = format;
            format_strings = new_node;

            // Update position in the format string section.
            new_node->offset = format_offset;
            format_offset += strlen(new_node->format) + 1;

            // Copy string into section.
            format_content = realloc(format_content, format_offset);
            strcpy(&format_content[new_node->offset], new_node->format);
        }

        // Increment to next item on the format string list.
        hash_list = hash_list->next;
    }
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
