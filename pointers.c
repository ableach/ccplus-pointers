/*
Author: A Bleach
Date: 09/01/2021
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void showPointerInfo(void);
int stringLength(const char* pstring);
int stringLength2(const char* pstring);
void squareByReference(int * numberToSquare);
void printStringUsingMaloc();
void practiceStruct();

struct dateType {
    int day;
    int month;
    int year;
};

struct employeeType {
    char name[20];
    struct dateType hireDate;
    float salary;
};

int main() {

    practiceStruct();

    int numberToSquare = 7;
    squareByReference(&numberToSquare);
    printf("6 squared = %d\n",numberToSquare);

    char testString[100];
    printf("Please enter a string:\n");
    scanf("%s",testString);
    printf("length of string %s is %d:\n",testString,stringLength2(testString));
    printf("\n-----------\n");
    showPointerInfo();
}

void practiceStruct() {
    struct employeeType employee = {"Fred",{1,12,2020},2500.50f};

    printf("Employee name = %s, salary = %.2f, hire = %02i-%02i-%i\n", employee.name, employee.salary,employee.hireDate.day,employee.hireDate.month,employee.hireDate.year);

    printf("Please enter new employee: \n");
    scanf("%s",employee.name);
    printf("Please enter new employee salary: \n");
    scanf("%f",&employee.salary);

    printf("Employee name = %s, salary = %.2f\n", employee.name, employee.salary);
}

void printStringUsingMaloc() {
    char *myString = NULL;
    int stringLength = 0;

    printf("How long is the string?\n");
    scanf("%d",&stringLength);

    myString = (char *) malloc(stringLength * sizeof(char));
    if ( myString != NULL) {
        printf("Please enter the string:\n");
        scanf("%s",myString);
        printf("string = %s\n", myString);
    }

    free(myString);
}

void squareByReference(int * numberToSquare) {
    *numberToSquare *= *numberToSquare;
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