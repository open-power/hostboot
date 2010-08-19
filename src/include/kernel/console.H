#ifndef __KERNEL_CONSOLE_H
#define __KERNEL_CONSOLE_H

#include <stdint.h>
#include <string.h>

void printk(const char*, ...);

class Console
{
    public:
	int putc(int);
	
	enum { BUFFER_SIZE = 1024 * 4 };

    protected:
	Console();
	~Console() {};

    private:
	size_t iv_pos;    
	char * iv_buffer;
};

#endif
