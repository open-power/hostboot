#include <string.h>

void* memset(void* s, int c, size_t n)
{
    char* _s = s;
    while(n)
    {
	*_s = c;
	_s++; n--;
    }
}
