#include "documentation_module.h"
#include <stdarg.h>

short check_available_documentation_module(int (*validate)(char*), int document_count, ...)
{
    short availability_mask = 0;
    va_list args;

    va_start(args, document_count);
    for (int i = 0; i < document_count; i++)
    {
        char* document_name = va_arg(args, char*);
        if (validate(document_name))
        {
            availability_mask |= (1 << i); 
        }
    }
    va_end(args);

    return availability_mask;
}

