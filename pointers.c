/*
Author: A Bleach
Date: 09/01/2021
*/

#include <stdio.h>
#include <stddef.h>

int main() {
    int size = 10;
    int * psize = NULL;

    psize = &size;

    printf("int: value = %d\n", size);
    printf("sizeof int = %lu\n", sizeof(size));
    printf("address of int via & = %p\n", &size);
    printf("-------\n");
    printf("value of pointer variable %p\n", psize);
    printf("sizeof pointer variable = %lu\n", sizeof(psize));
    printf("dereference/indirection operator *: value pointed to by pointer variable = %d\n", *psize);
    printf("address of pointer variable = %p\n", &psize);

    return 0;

}