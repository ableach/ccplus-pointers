/*
Author: A Bleach
Date: 09/01/2021
*/

#include <stdio.h>
#include <stddef.h>

void showPointerInfo(void);
int stringLength(const char* pstring);
int stringLength2(const char* pstring);

int main() {

    char testString[100];
    printf("Please enter a string:\n");
    scanf("%s",testString);
    printf("length of string %s is %d:\n",testString,stringLength2(testString));
    printf("\n-----------\n");
    showPointerInfo();
}

int stringLength(const char* pstring) {
    const char* pstring_start = pstring;
    while ( *pstring++ );

    return pstring - pstring_start - 1;
}

/* suggested answer */
int stringLength2(const char* pstring) {
    const char* pstring_end = pstring;
    while ( *pstring_end )
        pstring_end++;

    return pstring_end - pstring;
}


void showPointerInfo() {
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

}