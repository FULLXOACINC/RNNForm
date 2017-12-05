#include <stdio.h>
#include <stdlib.h>
#include "RNN.h"

int main()
{
    __init(17, 8, 8, 64);
    add_form("A.txt", "_A.txt");
    add_form("B.txt", "_B.txt");
    add_form("C.txt", "_C.txt");
    search_form("bad_A.txt");
    printf("-------------------\n");
    search_form("bad_B.txt");
    printf("-------------------\n");
    search_form("bad_C.txt");
    printf("-------------------\n");
    search_form("test.txt");
    printf("-------------------\n");




    return 0;
}
