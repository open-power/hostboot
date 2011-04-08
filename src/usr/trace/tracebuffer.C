#include <limits.h>
#include "tracebuffer.H"

TracePage* TracePage::setNext(TracePage* new_next)
{
    return __sync_val_compare_and_swap(&this->next, NULL, new_next);
}

traceEntry* TracePage::claimEntry(size_t size)
{
    size_t position = __sync_fetch_and_add(&this->size, size);
    if (position > (PAGE_SIZE - sizeof(TracePage)))
    {
        return NULL;
    }
    else
    {
        return (traceEntry*)&((uint8_t*)this)[sizeof(TracePage) + position];
    }
}

traceEntry* TraceBuffer::claimEntry(size_t size)
{
    traceEntry* result = NULL;
    TracePage* page = last;

    while (result == NULL)
    {
        result = page->claimEntry(size);

        if (NULL == result)
        {
            if (NULL != page->getNext())
            {
                __sync_bool_compare_and_swap(&this->last, 
                                             page, page->getNext());
                page = page->getNext();
            }
            else
            {
                TracePage* new_page = new (malloc(PAGE_SIZE)) TracePage();
                TracePage* prev = page;

                while(prev != NULL)
                {
                    prev = prev->setNext(new_page);
                }
            }
        }
    }

    return result;
}
