#include <string.h>

void* memset(void* s, int c, size_t n)
{
    char* _s = s;
    while(n)
    {
	*_s = c;
	_s++; n--;
    }
    return s;
}

char* strcpy(char* d, const char* s)
{
    char* d1 = d;

    do
    {
	*d1 = *s;
	if (*s == '\0') return d;
	d1++; s++;
    } while(1);
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
