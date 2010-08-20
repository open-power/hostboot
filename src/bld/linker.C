#include <stdint.h>
#include <bfd.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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
	bfd* image;
	Section text;
	Section data;

	bool read_object(char* file);
	bool write_object(FILE* file);
};

vector<Object> objects;
FILE* output;

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
    
    // Read input objects.
    for (int files = 2; files < argc; files++)
    {
	Object o;
	if (o.read_object(argv[files]))
	{
	    objects.push_back(o);
	}
    }

    for (vector<Object>::iterator i = objects.begin();
         i != objects.end();
	 ++i)
    {
	i->write_object(output);
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

    cout << endl;
    
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
    long start_pos = ftell(file);
    
    // Output TEXT section.
    fseek(file, text.vma_offset, SEEK_CUR);
    if (text.size != fwrite(text.data, 1, text.size, file))
    {
	int error = errno;
	cout << "Error writing to output." << endl;
	cout << strerror(error) << endl;
    }

    // Output DATA section.
    fseek(file, start_pos + data.vma_offset, SEEK_SET);
    if (data.size != fwrite(data.data, 1, data.size, file))
    {
	int error = errno;
	cout << "Error writing to output." << endl;
	cout << strerror(error) << endl;
    }
}
