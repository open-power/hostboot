#include <stdint.h>
#include <bfd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>

#include "../../include/sys/vfs.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::for_each;
using std::mem_fun_ref;
using std::bind1st;
using std::ofstream;

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

struct Section
{
    string name;
    size_t vma_offset;
    size_t size;
    
    bfd_byte* data;
};

struct Object
{
    public:
	string name;
	bfd* image;
	Section text;
	Section data;
	map<string, Symbol> symbols;
	vector<Symbol> relocs;
	long offset; 
	
	bool read_object(char* file);
	bool write_object(FILE* file);
	bool read_relocation();
	bool perform_local_relocations(FILE* file);
	bool perform_global_relocations(FILE* file);

	uint64_t find_init_symbol();
	uint64_t find_start_symbol();
};

vector<Object> objects;
FILE* output;
ofstream modinfo;
vector<uint64_t> all_relocations;

int main(int argc, char** argv)
{
    if (argc <= 2)
    {
	cout << argv[0] << " <output> <kernel> <modules>" << endl;
	return -1;
    }
    
    // Open output file.
    output = fopen(argv[1], "w+");
    if (NULL == output)
    {
	int error = errno;
	cout << "Error opening " << argv[1] << endl;
	cout << strerror(error) << endl;
    }
    // Open modinfo file.
    modinfo.open((string(argv[1])+".modinfo").c_str());
    
    // Read input objects.
    for (int files = 2; files < argc; files++)
    {
	Object o;
	if (o.read_object(argv[files]))
	{
	    o.read_relocation();	    
	    objects.push_back(o);
	    cout << endl;
	}
    }

    for_each(objects.begin(), objects.end(), 
	     bind2nd(mem_fun_ref(&Object::write_object), output));
    uint64_t last_address = ftell(output);
    if (0 != (last_address % 8))
    {
	char zero = 0;
	fwrite(&zero, 0, 8 - (last_address % 8), output);
	last_address = ftell(output);
    }

    cout << "Local relocations..." << endl;
    for_each(objects.begin(), objects.end(), 
	     bind2nd(mem_fun_ref(&Object::perform_local_relocations), output));
    cout << endl;

    cout << "Global relocations..." << endl;
    for_each(objects.begin(), objects.end(), 
	     bind2nd(mem_fun_ref(&Object::perform_global_relocations), output));
    cout << endl;
    
    // Create module table.
    uint64_t module_table_address = 
	    objects[0].symbols[VFS_TOSTRING(VFS_MODULES)].address +
	    objects[0].offset + objects[0].data.vma_offset;

    fseek(output, module_table_address, SEEK_SET);

    if ((objects.size()-1) > VFS_MODULE_MAX)
    {
	cout << "Error: Too many modules." << endl;
	return -1;
    }
    
    cout << "Updating module table... " << endl;
    for (vector<Object>::iterator i = ++objects.begin();
         i != objects.end();
	 ++i)
    {
	string object_name = i->name;
	object_name.erase(0, object_name.find_last_of("/")+1);

	char obj_name[VFS_MODULE_NAME_MAX];
	memset(obj_name, '\0', VFS_MODULE_NAME_MAX);
	strncpy(obj_name, object_name.c_str(), VFS_MODULE_NAME_MAX-1);
	fwrite(obj_name, VFS_MODULE_NAME_MAX, 1, output);

	uint64_t init_symbol = i->find_init_symbol();
	uint64_t start_symbol = i->find_start_symbol();

	char data[sizeof(uint64_t)];
	
	if (0 != init_symbol)
	    all_relocations.push_back(ftell(output));
	bfd_putb64(init_symbol, data);
	fwrite(data, sizeof(uint64_t), 1, output);
	if (0 != start_symbol)
	    all_relocations.push_back(ftell(output));
	bfd_putb64(start_symbol, data);
	fwrite(data, sizeof(uint64_t), 1, output);

	cout << "\tAdded module " << object_name << " with init at "
	     << std::hex << init_symbol << " and start at "
	     << start_symbol << endl;
    }

    cout << "Updating last address..." << std::hex;
    uint64_t last_address_entry_address =
	    objects[0].symbols[VFS_TOSTRING(VFS_LAST_ADDRESS)].address +
	    objects[0].offset + objects[0].data.vma_offset;
    
    fseek(output, last_address_entry_address, SEEK_SET);
    char last_addr_data[sizeof(uint64_t)];
    bfd_putb64(last_address, last_addr_data);
    fwrite(last_addr_data, sizeof(uint64_t), 1, output);

    cout << last_address << " to " << last_address_entry_address << endl;

    // Output relocation data.
    {
	fseek(output, 0, SEEK_END);
	char temp64[sizeof(uint64_t)];

	uint64_t count = all_relocations.size();
	bfd_putb64(count, temp64);
	fwrite(temp64, sizeof(uint64_t), 1, output);

	for (int i = 0; i < all_relocations.size(); i++)
	{
	    bfd_putb64(all_relocations[i], temp64);
	    fwrite(temp64, sizeof(uint64_t), 1, output);
	}
    }

    return 0;
}

bool Object::read_object(char* file)
{
    // Open BFD file.
    image = bfd_openr(file, NULL);
    if (!bfd_check_format(image, bfd_object))
    {
	cout << "Unsupported file format: " << file << endl;
	return false;
    }
    
    name = file;
    cout << "File " << file << endl;

    // Read sections.
    bfd_section* image_section = image->sections;
    while(image_section != NULL)
    {
	Section* s = NULL;
	if (string(".text") == bfd_get_section_name(image, image_section))
	{
	    s = &this->text;
	}
	if (string(".data") == bfd_get_section_name(image, image_section))
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

    return true;
}

#define advance_to_page_align(f) \
    { \
	long pos = ftell(f); \
	if (pos % 4096) \
	{ \
	    fseek((f), 4096 - (pos % 4096), SEEK_CUR); \
	} \
    }

bool Object::write_object(FILE* file)
{
    // Start outputing object at page boundary.
    advance_to_page_align(file);
    offset = ftell(file);
    
    // Output TEXT section.
    fseek(file, text.vma_offset, SEEK_CUR);
    if (text.size != fwrite(text.data, 1, text.size, file))
    {
	int error = errno;
	cout << "Error writing to output." << endl;
	cout << strerror(error) << endl;
    }

    // Output DATA section.
    fseek(file, offset + data.vma_offset, SEEK_SET);
    if (data.size != fwrite(data.data, 1, data.size, file))
    {
	int error = errno;
	cout << "Error writing to output." << endl;
	cout << strerror(error) << endl;
    }

    modinfo << &name[(name.find_last_of("/")+1)] << ",0x" << std::hex << offset << endl;
}

bool Object::read_relocation()
{
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
	return false;
    }
    cout << "Symbols: " << std::dec << symbols << endl;
    for (int i = 0; i < symbols; i++)
    {
	Symbol s;
	s.name = syms[i]->name;
	s.address = syms[i]->value;
	s.base = syms[i]->section->vma;
	s.type = 0;

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
	
	if (loc[i]->howto->name == string("R_PPC64_ADDR64"))
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
	     << loc[i]->addend << endl;
    }

cleanup:
    if (NULL != loc)
	free(loc);
    if (NULL != syms)
    	free(syms);

    return true;
}

bool Object::perform_local_relocations(FILE* file)
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

	fseek(file, offset + i->address, SEEK_SET);
	fread(data, sizeof(uint64_t), 1, file);

	address = bfd_getb64(data);
	if (address != i->addend)
	{
	    cout << "Expected " << i->addend << " found " << address 
		 << " at " << (offset + i->address) << endl;
	    cerr << "Expected " << i->addend << " found " << address 
		 << " at " << (offset + i->address) << endl;
	    exit(-1);
	}

	// If it is a non-ABS relocation, also need to add the symbol addr.
	if (i->name != BFD_ABS_SECTION_NAME) 
	{
	    Symbol& s = this->symbols[i->name];
	    uint64_t symbol_addr = s.base + s.address;
	    i->addend += symbol_addr;
	    relocation += symbol_addr;
	}

	address = relocation;
	bfd_putb64(address, data);
	all_relocations.push_back(offset + i->address);
	
	fseek(file, offset + i->address, SEEK_SET);
	fwrite(data, sizeof(uint64_t), 1, file);

	cout << "\tRelocated " << i->addend << " at " << i->address << " to " 
	     << relocation << endl;
    }
}

bool Object::perform_global_relocations(FILE* file)
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
			    cerr << "Can't handle offset unresolved function." 
				<< endl;
			    exit(-1);
			}

			fseek(file, symbol_addr, SEEK_SET);
			fread(data, sizeof(uint64_t), 3, file);

			fseek(file, offset + i->address, SEEK_SET);
			fwrite(data, sizeof(uint64_t), 3, file);
			all_relocations.push_back(offset + i->address);
			all_relocations.push_back(offset + i->address + 8);
			all_relocations.push_back(offset + i->address + 16);

			cout << "\tCopied relocation from " << std::hex 
			    << symbol_addr << " to " 
			    << offset + i->address << "." << endl;
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
			bfd_putb64(symbol_addr, data);
			fseek(file, offset + i->address, SEEK_SET);
			fwrite(data, sizeof(uint64_t), 1, file);
			all_relocations.push_back(offset + i->address);

			cout << "\tRelocated from " << std::hex
			    << symbol_addr << " to "
			    << offset + i->address << "." << endl;
		    }
		    break;
		}
	    }
	}

	if (!found_symbol)
	{
	    cout << "Could not find symbol " << i->name << std::endl;
	    cerr << "Could not find symbol " << i->name << std::endl;
	    exit(-1);
	}
    }
}

uint64_t Object::find_init_symbol()
{
    if (symbols.find(VFS_TOSTRING(VFS_SYMBOL_INIT)) == symbols.end())
	return 0;

    return symbols[VFS_TOSTRING(VFS_SYMBOL_INIT)].address + 
	   offset + data.vma_offset;
}

uint64_t Object::find_start_symbol()
{
    if (symbols.find(VFS_TOSTRING(VFS_SYMBOL_START)) == symbols.end())
	return 0;

    return symbols[VFS_TOSTRING(VFS_SYMBOL_START)].address + 
	   offset + data.vma_offset;
}
