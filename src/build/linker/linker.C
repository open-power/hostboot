//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/build/linker/linker.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file linker.C   Linker to generate the host boot binary images
 */
//  This code has been extended to create the host boot extended binary image.
//  Most of this code was already in existance and no attempt has been made to make it
//  completely conformant to PFD coding guidelines.
//
#include <stdint.h>
#include <stdlib.h>
#include <bfd.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <sstream>

#define LINKER_C
#include "../../include/sys/vfs.h"
#undef LINKER_C

using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::for_each;
using std::mem_fun_ref;
using std::bind1st;
using std::ofstream;
using std::invalid_argument;
using std::range_error;
using std::ostringstream;

/**
 * Symbol - ELF Symbol information
 */
struct Symbol
{
    string name;
    uint8_t type;
    uint64_t address;
    uint64_t addend;
    uint64_t base;

    enum SymbolType
    {
        LOCAL = 0x01,
        GLOBAL = 0x02,

        UNRESOLVED = 0x04,

        FUNCTION = 0x08,
        VARIABLE = 0x10,

        RELATIVE = 0x20,
    };
};

/**
 * ELF section
 */
struct Section
{
    string name;
    size_t vma_offset;
    size_t size;

    bfd_byte* data;
};

/**
 * Object  ELF image contents or binary blob
 */
struct Object
{
    public:
        string name;                    //!< full path name of file
        bfd* image;                     //!< bfd image of object
        Section text;                   //!< text section of binary
        Section rodata;                 //!< rodata section of binary
        Section data;                   //!< data section of binary
        map<string, Symbol> symbols;    //!< symbol map
        vector<Symbol> relocs;          //!< relocations
        unsigned long offset;           //!< output file offset of image start
        unsigned long base_addr;        //!< output file base address
        FILE * iv_output;               //!< output file handle

        /**
         * Read the object from it's file and extract bfd, text, & data image
         * @param[in] i_file : file path
         * @return true if no errors
         * @post sets name, image, text, data
         */
        bool read_object(const char* i_file);

        /**
         * Write object to iv_output
         * @return true if no errors
         * @post sets offset
         */
        bool write_object();

        /**
         * Read relocations
         * @return true if no errors
         * @post sets symbols, relocs
         */
        bool read_relocation();


        /**
         * Perform local relcations on object
         * @returns true if no errors
         */
        bool perform_local_relocations();

        /**
         * Perform global relocations
         * @return tre if no errors
         */
        bool perform_global_relocations();

        /**
         * Query if the object is valid bfd object
         * @return true if valid bfd object, false if binary blob
         */
        bool isELF();

        /**
         * Find the location of the _init symbol
         * @return location of the _init symbol
         */
        uint64_t find_init_symbol();

        /**
         * Find the location of the _start symbol
         * @return location of the _start symbol
         */
        uint64_t find_start_symbol();

        /**
         * Find the location of the _fini symbol
         * @return location of the _fini symbol
         */
        uint64_t find_fini_symbol();

        /**
         * CTOR default
         */
        Object() : image(NULL), offset(0), base_addr(0), iv_output(NULL),
                   text(), rodata(), data() {}

        /**
         * CTOR
         * @param[in] i_baseAddress of the output binary this object belongs to
         * @param[in] i_out : output FILE handle
         */
        Object(unsigned long i_baseAddr, FILE* i_out)
            : image(NULL), offset(0), base_addr(i_baseAddr), iv_output(i_out),
              text(), rodata(), data() {}
};

inline bool Object::isELF()
{
    return image != NULL;
}

/**
 * Infomraiton needed to build the Module table in each output image
 */
class ModuleTable
{
    private:
        FILE * iv_output;
        string iv_path;
        string iv_vfs_mod_table_name;

    public:

        /**
         * CTOR
         */
        ModuleTable(FILE * i_binfile,
                    const string & i_path,
                    const string & i_mod_table_name)
            :
                iv_output(i_binfile),
                iv_path(i_path),
                iv_vfs_mod_table_name(i_mod_table_name) {}

        /**
         * Write module table to file
         * @param[in] list of objects
         */
        void write_table(vector<Object> & i_objects);

        /**
         * Clean up after an error
         */
        void handle_error();
};

/**
 * Align offset to 4k page boundary
 * @param[in] i_offset value to align
 * @returns page aligned value
 */
inline uint64_t page_align(uint64_t i_offset)
{
    uint32_t v = i_offset;
    if(i_offset % 4096)
        v = i_offset + (4096 - i_offset % 4096);
    return v;
}

/**
 * Align file ptr to 4k page boundary
 * @param i_f FILE *
 */
inline void advance_to_page_align(FILE * i_f)
{
    long pos = ftell(i_f);
    if( pos % 4096 )
    {
        fseek(i_f, 4096 - (pos % 4096), SEEK_CUR);
    }
}

//
// Global variables
//
vector<Object> objects;
ofstream modinfo;
vector<uint64_t> all_relocations;
vector<ModuleTable> module_tables;
map<string,size_t> weak_symbols;
set<string> all_symbols;
set<string> weak_symbols_to_check;

//-----------------------------------------------------------------------------
// MAIN
//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
    int rc = 0;
    FILE * output;
    bool isOutput = true;
    unsigned long base_addr = 0;

    if (argc <= 2)
    {
        cout << argv[0] << " <output> <kernel> <modules>"
            " [--extended=<page_addr> <output> <modules>]" << endl;
        return -1;
    }

    try
    {
        // Open modinfo file.
        modinfo.open((string(argv[1])+".modinfo").c_str());

        // Read input args - generate objects.
        for (int files = 1; files < argc; files++)
        {
            string fname(argv[files]);
            if(isOutput)
            {
                isOutput = false;
                output = fopen(fname.c_str(), "w+");
                if (NULL == output)
                {
                    int error = errno;
                    ostringstream oss;
                    oss << "Error opening " << fname << endl;
                    oss << strerror(error);
                    cout << oss.str() << endl;
                    throw invalid_argument(oss.str());
                }
                string table_symbol;
                if(base_addr == 0)
                {
                    table_symbol = VFS_TOSTRING(VFS_MODULES);
                }
                else  // extended module
                {
                    // allocate space for the module table in the extended image
                    uint64_t table_size =
                        page_align(112*VFS_EXTENDED_MODULE_MAX);
                    fseek(output, table_size, SEEK_SET);
                }
                ModuleTable module_table(output,fname,table_symbol);
                module_tables.push_back(module_table);
            }
            else if (0 == fname.compare(0,11,"--extended="))
            {
                base_addr = strtoul(fname.c_str()+11,NULL,16) * 0x1000;
                isOutput = true;
            }
            else
            {
                Object o(base_addr,output);
                if(access(fname.c_str(),F_OK) != 0)
                {
                    ostringstream oss;
                    oss << "Error! File " << fname << " does not exist";
                    cout << oss.str() << endl;
                    throw invalid_argument(oss.str());
                }
                else if (o.read_object(fname.c_str()))
                {
                    if(o.isELF())
                    {
                        o.read_relocation();
                    }
                    objects.push_back(o);
                    cout << endl;
                }
            }
        }

        // Check weak-symbol collisions for contained values (typically
        // static member variables).
        for(set<string>::iterator i = weak_symbols_to_check.begin();
            i != weak_symbols_to_check.end();
            ++i)
        {

            // Need to ignore the first character of the weak symbol.
            //     In mangled C++ names a symbol is something like _Z3foo.
            //     A contained member value might be something like
            //     _ZZ3fooE3bar.
            string sym_name = string((i->c_str())+1);

            cout << "Checking weak symbol: " << *i << endl;

            for(set<string>::iterator j = all_symbols.begin();
                j != all_symbols.end();
                ++j)
            {
                if ((string::npos != j->find(sym_name)) &&
                    (*i != *j))
                {
                    cout << "\tDuplicate member found: " << *j << endl;
                    throw std::runtime_error(
                                string("Duplicate weak symbol with contained "
                                       "value member detected: ") +
                                *i +
                                string(" with member: ") +
                                *j);
                }
            }
        }

        // Write objects to their output file
        for_each(objects.begin(), objects.end(),
                 mem_fun_ref(&Object::write_object));
        //bind2nd(mem_fun_ref(&Object::write_object), output));

        // used to find start of unallocated memory
        // goes in base binary only
        uint64_t last_address = ftell(objects[0].iv_output);

        cout << "Local relocations..." << endl;
        for_each(objects.begin(), objects.end(),
                 mem_fun_ref(&Object::perform_local_relocations));
        //bind2nd(mem_fun_ref(&Object::perform_local_relocations), output));
        cout << endl;

        cout << "Global relocations..." << endl;
        for_each(objects.begin(), objects.end(),
                 mem_fun_ref(&Object::perform_global_relocations));
        //bind2nd(mem_fun_ref(&Object::perform_global_relocations), output));
        cout << endl;


        //
        // Create module tables
        //
        for(vector<ModuleTable>::iterator i = module_tables.begin();
            i != module_tables.end(); ++i)
        {
            i->write_table(objects);
        }

        //
        // Last Address
        // Only appies to base binary file
        //

        cout << "Updating last address..." << std::hex;
        uint64_t last_address_entry_address =
            objects[0].symbols[VFS_TOSTRING(VFS_LAST_ADDRESS)].address +
            objects[0].offset + objects[0].data.vma_offset;

        fseek(objects[0].iv_output, last_address_entry_address, SEEK_SET);

        char last_addr_data[sizeof(uint64_t)];
        bfd_putb64(last_address, last_addr_data);
        fwrite(last_addr_data, sizeof(uint64_t), 1, objects[0].iv_output);

        cout << last_address << " to " << last_address_entry_address << endl;

        // Output relocation data.
        {
            fseek(objects[0].iv_output, 0, SEEK_END);
            char temp64[sizeof(uint64_t)];

            uint64_t count = all_relocations.size();
            bfd_putb64(count, temp64);
            fwrite(temp64, sizeof(uint64_t), 1, objects[0].iv_output);

            for (int i = 0; i < all_relocations.size(); i++)
            {
                bfd_putb64(all_relocations[i], temp64);
                fwrite(temp64, sizeof(uint64_t), 1, objects[0].iv_output);
            }
        }
    }
    catch (std::exception & e)
    {
        cerr << "exception caught: " << e.what() << endl;
        rc = -1;
        // remove any partial output file(s)
        for(vector<ModuleTable>::iterator i = module_tables.begin();
            i != module_tables.end(); ++i)
        {
            i->handle_error();
        }
    }

    return rc;
}

//-----------------------------------------------------------------------------

bool Object::read_object(const char* i_file)
{
    name = i_file;
    cout << "File " << i_file << endl;
    bool result = true;

    // Open BFD file.
    image = bfd_openr(i_file, NULL);
    if (!bfd_check_format(image, bfd_object))
    {
        // Tread file as a binar blob
        if(!bfd_close(image))
        {
            cout << "ERROR: Unexpected error closing file " << i_file << endl;
            result = false;
        }
        else
        {
            cout << "NON ELF format on file: " << i_file
                << ". The file will be added as a binary blob." << endl;
            image = NULL;
        }
    }
    else // BFD file
    {

        // Read sections.
        bfd_section* image_section = image->sections;
        while(image_section != NULL)
        {
            Section* s = NULL;
            if (string(".text") == bfd_get_section_name(image, image_section))
            {
                s = &this->text;
            }
            else if (string(".rodata") ==
                     bfd_get_section_name(image, image_section))
            {
                s = &this->rodata;
            }
            else if (string(".data") ==
                     bfd_get_section_name(image, image_section))
            {
                s = &this->data;
            }
            if (NULL != s)
            {
                s->name = 		bfd_get_section_name(image, image_section);
                s->vma_offset = 	bfd_get_section_vma(image, image_section);
                s->size = 		bfd_get_section_size(image_section);

                bfd_malloc_and_get_section(image, image_section, &s->data);

                cout << "Section " << s->name << endl;
                cout << "\tSize " << std::dec << s->size << endl;
                cout << "\tVMA " << std::hex << s->vma_offset << endl;
                cout << "\tData " << std::hex << bfd_getb64(s->data)
                    << "..." << endl;
            }

            image_section = image_section->next;
        }
    }

    return result;
}


//-----------------------------------------------------------------------------

bool Object::write_object()
{
    // Start outputing object at page boundary.
    advance_to_page_align(iv_output);
    offset = ftell(iv_output);

    if(isELF())
    {
        // Output TEXT section.
        fseek(iv_output, text.vma_offset, SEEK_CUR);
        if (text.size != fwrite(text.data, 1, text.size, iv_output))
        {
            int error = errno;
            cout << "Error writing to output." << endl;
            cout << strerror(error) << endl;
        }

        // Output RODATA section.
        fseek(iv_output, offset + rodata.vma_offset, SEEK_SET);
        if ((0 != rodata.size) &&
            (rodata.size != fwrite(rodata.data, 1, rodata.size, iv_output)))
        {
            int error = errno;
            cout << "Error writing to output for rodata." << endl;
            cout << strerror(error) << endl;
        }

        // Output DATA section.
        fseek(iv_output, offset + data.vma_offset, SEEK_SET);
        if (data.size != fwrite(data.data, 1, data.size, iv_output))
        {
            int error = errno;
            cout << "Error writing to output." << endl;
            cout << strerror(error) << endl;
        }

    }
    else // binary blob
    {
        FILE * file = fopen(name.c_str(),"rb");
        fseek(file,0,SEEK_END);
        long int file_size = ftell(file);
        uint8_t * buffer = new uint8_t[file_size];
        fseek(file,0,SEEK_SET);
        fread(buffer,file_size,1,file);
        fwrite(buffer,file_size,1,iv_output);
        delete [] buffer;
        fclose(file);
    }

    // make file end on 8 byte boundary
    uint64_t eof = ftell(iv_output);
    if (0 != (eof % 8))
    {
        char zero = 0;
        fwrite(&zero, 1, 8 - (eof % 8), iv_output);
    }

    modinfo << &name[(name.find_last_of("/")+1)] << ",0x"
        << std::hex << offset + base_addr << endl;

}

//-----------------------------------------------------------------------------

bool Object::read_relocation()
{
    if(!isELF()) return false;

    bool result = true;
    asymbol** syms = NULL;
    long symbols = 0;
    arelent** loc = NULL;
    long locs = 0;

    // Read symbol tables.
    {
        long symbol_size = bfd_get_dynamic_symtab_upper_bound(image);
        if (0 < symbol_size)
        {
            syms = (asymbol**) malloc(symbol_size);
            symbols = bfd_canonicalize_dynamic_symtab(image, syms);
        }
    }
    if (0 >= symbols)
    {
        long symbol_size = bfd_get_symtab_upper_bound(image);
        if (0 < symbol_size)
        {
            syms = (asymbol**) malloc(symbol_size);
            symbols = bfd_canonicalize_symtab(image, syms);
        }
    }
    if (0 >= symbols)
    {
        cout << "Couldn't find symbol table." << endl;
        result = false;
        goto cleanup;
    }
    cout << "Symbols: " << std::dec << symbols << endl;
    for (int i = 0; i < symbols; i++)
    {
        Symbol s;
        s.name = syms[i]->name;
        s.address = syms[i]->value;
        s.base = syms[i]->section->vma;
        s.type = 0;

        all_symbols.insert(s.name);

        cout << "\tSymbol: " << syms[i]->name << endl;
        cout << "\t\tAddress: " << std::hex << syms[i]->value << endl;

        // Determine symbol types.
        if (syms[i]->flags & BSF_GLOBAL)
        {
            s.type |= Symbol::GLOBAL;
            cout << "\t\tGLOBAL" << endl;
        }
        else if (syms[i]->flags & (BSF_LOCAL | BSF_WEAK))
        {
            // Check weak symbol list for duplicate weak symbols.
            if (syms[i]->flags & (BSF_WEAK))
            {
                if (weak_symbols[syms[i]->name]++)
                {
                    weak_symbols_to_check.insert(syms[i]->name);
                }
            }

            s.type |= Symbol::LOCAL;
            cout << "\t\tLOCAL" << endl;
        }
        else
        {
            s.type |= Symbol::UNRESOLVED;
            cout << "\t\tUNDEFINED " << std::hex << syms[i]->flags << endl;
        }

        if (syms[i]->flags & BSF_FUNCTION)
        {
            s.type |= Symbol::FUNCTION;
            cout << "\t\tFUNCTION" << endl;
        }
        else if (!(s.type & Symbol::UNRESOLVED))
        {
            s.type |= Symbol::VARIABLE;
            cout << "\t\tVARIABLE" << endl;
        }

        // Add symbol to table.
        if (!(s.type & Symbol::UNRESOLVED))
            this->symbols[s.name] = s;
    }

    // Read relocations.
    {
        long loc_size = bfd_get_dynamic_reloc_upper_bound(image);
        if (0 < loc_size)
        {
            loc = (arelent**) malloc(loc_size);
            memset(loc, '\0', loc_size);
            locs = bfd_canonicalize_dynamic_reloc(image, loc, syms);
        }
    }
    if (0 >= locs)
    {
        goto cleanup;
    }

    cout << "Relocs: " << std::dec << locs << endl;
    for (int i = 0; i < locs; i++)
    {
        Symbol s;

        s.name = loc[i]->sym_ptr_ptr[0]->name;
        s.address = loc[i]->address;
        s.addend = loc[i]->addend;
        if ((s.name == BFD_ABS_SECTION_NAME) ||
            (this->symbols.find(s.name) != this->symbols.end()))
        {
            s.type = Symbol::RELATIVE;
        }
        else
        {
            s.type = Symbol::UNRESOLVED;
        }

        if ((loc[i]->howto->name == string("R_PPC64_ADDR64")) ||
            (loc[i]->howto->name == string("R_PPC64_UADDR64")))
        {
            s.type |= Symbol::VARIABLE;
        }
        else if (loc[i]->howto->name == string("R_PPC64_JMP_SLOT"))
        {
            s.type |= Symbol::FUNCTION;
        }
        this->relocs.push_back(s);

        cout << "\tSymbol: " << loc[i]->sym_ptr_ptr[0]->name;
        cout << "\tAddress: " << std::hex << loc[i]->address << ", "
            << loc[i]->addend << ", " << loc[i]->howto->name << endl;
    }

cleanup:
    if (NULL != loc)
        free(loc);
    if (NULL != syms)
        free(syms);

    return result;
}

//-----------------------------------------------------------------------------

bool Object::perform_local_relocations()
{
    cout << "File " << name << endl;

    for(vector<Symbol>::iterator i = relocs.begin();
        i != relocs.end();
        ++i)
    {
        if (i->type & Symbol::UNRESOLVED)
            continue;

        cout << "\tSymbol: " << i->name << endl;

        uint64_t relocation = i->addend + offset;
        uint64_t address = 0;
        char data[sizeof(uint64_t)];

        fseek(iv_output, offset + i->address, SEEK_SET);
        fread(data, sizeof(uint64_t), 1, iv_output);

        address = bfd_getb64(data);
        if ((address != i->addend) && (address != 0))
        {
            ostringstream oss;
            oss << "Expected " << i->addend << " found " << address
                << " at " << (offset + i->address);
            cout << oss.str() << endl;
            throw range_error(oss.str());
        }

        // If it is a non-ABS relocation, also need to add the symbol addr.
        if (i->name != BFD_ABS_SECTION_NAME)
        {
            Symbol& s = this->symbols[i->name];
            uint64_t symbol_addr = s.base + s.address;
            i->addend += symbol_addr;
            relocation += symbol_addr;
        }

        address = relocation + base_addr; //dgxxa
        bfd_putb64(address, data);
        if(!base_addr) all_relocations.push_back(offset + i->address);

        fseek(iv_output, offset + i->address, SEEK_SET);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        cout << "\tRelocated " << i->addend << " at " << i->address << " to "
            << relocation << endl;
    }
}

//-----------------------------------------------------------------------------

bool Object::perform_global_relocations()
{
    cout << "File " << name << endl;

    for(vector<Symbol>::iterator i = relocs.begin();
        i != relocs.end();
        ++i)
    {
        bool found_symbol = false;

        if (!(i->type & Symbol::UNRESOLVED))
            continue;

        cout << "\tSymbol: " << i->name << endl;

        char data[sizeof(uint64_t)*3];

        for(int allow_local = 0;
            ((allow_local < 2) && (!found_symbol));
            allow_local++)
        {
            for(vector<Object>::iterator j = objects.begin();
                j != objects.end();
                ++j)
            {
                if (j->symbols.find(i->name) != j->symbols.end())
                {
                    Symbol s = j->symbols[i->name];
                    uint64_t symbol_addr =
                        j->offset + s.address + s.base;

                    if (s.type & Symbol::UNRESOLVED)
                        continue;
                    if ((s.type & Symbol::LOCAL) && (!allow_local))
                        continue;
                    if ((!(s.type & Symbol::GLOBAL)) && (!allow_local))
                        continue;

                    found_symbol = true;

                    if ((s.type & Symbol::FUNCTION) &&
                        (i->type & Symbol::FUNCTION))
                    {
                        if (i->addend != 0)
                        {
                            ostringstream oss;
                            oss << "Can't handle offset unresolved function."
                                << " Symbol: " << s.name;
                            cout << oss.str() << endl;
                            throw range_error(oss.str());
                        }

                        fseek(j->iv_output, symbol_addr, SEEK_SET);
                        fread(data, sizeof(uint64_t), 3, j->iv_output);

                        fseek(iv_output, offset + i->address, SEEK_SET);
                        fwrite(data, sizeof(uint64_t), 3, iv_output);
                        if(!base_addr)
                        {
                            all_relocations.push_back(offset + i->address);
                            all_relocations.push_back(offset + i->address + 8);
                            all_relocations.push_back(offset + i->address + 16);
                        }

                        cout << "\tCopied relocation from " << std::hex
                            << j->base_addr << ':' << symbol_addr << " to "
                            << base_addr << ':' << offset + i->address << "."
                            << endl;
                    }
                    else
                    {
                        if (s.type & Symbol::FUNCTION)
                        {
                            cout << "\tTOC link for function: " << s.name
                                << endl;
                        }
                        if (i->addend != 0)
                        {
                            cout << "\tOffset to " << i->addend << endl;
                            symbol_addr += i->addend;
                        }
                        symbol_addr += j->base_addr;
                        bfd_putb64(symbol_addr, data);
                        fseek(iv_output, offset + i->address, SEEK_SET);
                        fwrite(data, sizeof(uint64_t), 1, iv_output);
                        if(!base_addr) all_relocations.push_back(offset + i->address);

                        cout << "\tRelocated from " << std::hex
                            << j->base_addr << ':'
                            << symbol_addr - j->base_addr << " to "
                            << base_addr << ':' << offset + i->address << "."
                            << endl;
                    }
                    break;
                }
            }
        }

        if (!found_symbol)
        {
            ostringstream oss;
            oss << "Could not find symbol " << i->name;
            cout << oss.str() << endl;
            throw range_error(oss.str());
        }
    }
}

//-----------------------------------------------------------------------------

uint64_t Object::find_init_symbol()
{
    if (symbols.find(VFS_TOSTRING(VFS_SYMBOL_INIT)) == symbols.end())
        return 0;

    return symbols[VFS_TOSTRING(VFS_SYMBOL_INIT)].address +
        offset + base_addr + rodata.vma_offset;
}

//-----------------------------------------------------------------------------

uint64_t Object::find_start_symbol()
{
    if (symbols.find(VFS_TOSTRING(VFS_SYMBOL_START)) == symbols.end())
        return 0;

    return symbols[VFS_TOSTRING(VFS_SYMBOL_START)].address +
        offset + base_addr + rodata.vma_offset;
}

//-----------------------------------------------------------------------------

uint64_t Object::find_fini_symbol()
{
    if (symbols.find(VFS_TOSTRING(VFS_SYMBOL_FINI)) == symbols.end())
        return 0;

    return symbols[VFS_TOSTRING(VFS_SYMBOL_FINI)].address +
        offset + base_addr + rodata.vma_offset;
}


//-----------------------------------------------------------------------------

void ModuleTable::write_table(vector<Object> & i_objects)
{
    vector<Object>::iterator i = i_objects.begin();

    uint64_t module_table_offset = 0;
    uint64_t module_count = 0;
    uint64_t max_modules = 0;

    if (iv_vfs_mod_table_name.size() != 0)
    {
        // Base module - First object is elf image, find the table location
        module_table_offset =
            i->symbols[iv_vfs_mod_table_name].address +
            i->offset + i->data.vma_offset;

        cout << "Updating base module table..." << endl;
        max_modules = VFS_MODULE_MAX;
        ++i;
    }
    else
    {
        // Extended module - module table is at offset 0 in file
        cout << "Updating extended module table..." << endl;
        max_modules = VFS_EXTENDED_MODULE_MAX;
    }

    fseek(iv_output, module_table_offset, SEEK_SET);

    for(; i != i_objects.end(); ++i)
    {
        if(i->iv_output != this->iv_output) continue;

        ++module_count;
        if(module_count > max_modules)
        {
            ostringstream oss;
            oss << "Too many modules. Max = " << max_modules;
            cout << oss.str() << endl;
            throw range_error(oss.str());
        }
        string object_name = i->name;
        object_name.erase(0,object_name.find_last_of("/")+1);

        char obj_name[VFS_MODULE_NAME_MAX];
        memset(obj_name, '\0', VFS_MODULE_NAME_MAX);
        strncpy(obj_name, object_name.c_str(), VFS_MODULE_NAME_MAX-1);
        fwrite(obj_name, VFS_MODULE_NAME_MAX, 1, iv_output);

        uint64_t init_symbol = 0;
        uint64_t start_symbol = 0;
        uint64_t fini_symbol = 0;
        uint64_t text_offset = 0;
        uint64_t data_offset = 0;
        uint64_t module_size = 0;

        if(i->isELF())
        {
            init_symbol  = i->find_init_symbol();
            start_symbol = i->find_start_symbol();
            fini_symbol  = i->find_fini_symbol();
            text_offset  = i->text.vma_offset + i->offset + i->base_addr;
            data_offset  = (i->data.vma_offset + i->offset + i->base_addr) &
                           (~(0xfff));
            module_size  = i->data.vma_offset + i->data.size;
            module_size  = page_align(module_size);
        }
        else // binary blob
        {
            FILE * f = fopen(i->name.c_str(), "rb"); // file has to exist already
            fseek(f,0,SEEK_END);
            module_size = ftell(f);
            text_offset = data_offset = i->offset + i->base_addr;
            fclose(f);
        }

        //module_size = page_align(module_size)/4096;

        char data[sizeof(uint64_t)];

        if (0 != init_symbol && !i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(init_symbol, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        if (0 != start_symbol && !i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(start_symbol, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        if (0 != fini_symbol && !i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(fini_symbol, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        if (0 != text_offset && !i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(text_offset, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        if (0 != data_offset && !i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(data_offset, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        if(!i->base_addr)
            all_relocations.push_back(ftell(iv_output));
        bfd_putb64(module_size, data);
        fwrite(data, sizeof(uint64_t), 1, iv_output);

        cout << std::hex << std::setfill('0');
        cout << "\tAdded module " << object_name
            << " page size 0x" << module_size << endl;
        cout << "\t\twith .text at 0x" << setw(16) << text_offset  << endl;
        cout << "\t\twith .data at 0x" << setw(16) << data_offset  << endl;
        cout << "\t\twith init  at 0x" << setw(16) << init_symbol  << endl;
        cout << "\t\twith start at 0x" << setw(16) << start_symbol << endl;
        cout << "\t\twith fini  at 0x" << setw(16) << fini_symbol  << endl;
    }
}

void ModuleTable::handle_error()
{
    if(iv_output)
    {
        fclose(iv_output);
        cout << "Removing " << iv_path << endl;
        remove(iv_path.c_str());
    }
}
