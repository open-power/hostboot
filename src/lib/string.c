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

int strcmp(const char* a, const char* b)
{
    while((*a != '\0') && (*b != '\0'))
    {
	if (*a == *b)
	{
	    a++; b++;
	}
	else
	{
	    return (*a > *b) ? 1 : -1;
	}
    }
    if (*a == *b)
	return 0;
    if (*a == '\0')
	return -1;
    else
	return 1;
}
