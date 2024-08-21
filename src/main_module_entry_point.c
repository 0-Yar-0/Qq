#include <stdio.h>
#include "print_module.h"
#include "documentation_module.h"

int main()
{
    print_log(print_char, Module_load_success_message);
    const char* documents[] = { "Linked lists", "Queues", "Maps", "Binary Trees" };
    int document_count = sizeof(documents) / sizeof(documents[0]);

    short availability_mask = check_available_documentation_module(validate, document_count, 
                                                                    documents[0], documents[1], 
                                                                    documents[2], documents[3]);

    for (int i = 0; i < document_count; i++)
    {
        printf("%-15s : %s\n", documents[i], (availability_mask & (1 << i)) ? "available" : "unavailable");
    }

    return 0;
}
