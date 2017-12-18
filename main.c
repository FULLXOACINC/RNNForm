#include <stdio.h>
#include <stdlib.h>
#include "RNN.h"

int main()
{
    __init(7, 16, 18, 35, 8);
    add_form("B.txt", "_B.txt");
    add_form("A.txt", "_A.txt");
    add_form("C.txt", "_C.txt");
    //add_form("D.txt", "_D.txt");
    /*
    search_X_form("A.txt");
    printf("-------------------\n");
    search_Y_form("_A.txt");
    printf("-------------------\n");
    search_X_form("B.txt");
    printf("-------------------\n");
    search_Y_form("_B.txt");
    printf("-------------------\n");
    search_X_form("C.txt");
    printf("-------------------\n");
    search_Y_form("_C.txt");
    printf("-------------------\n");
    search_X_form("D.txt");
    printf("-------------------\n");
    search_Y_form("_D.txt");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("-------------------\n");
    search_X_form("A_BAD.txt");
    printf("-------------------\n");
    search_Y_form("_A_BAD.txt");
    /*
    printf("-------------------\n");
    search_X_form("B_BAD.txt");
    printf("-------------------\n");
    search_Y_form("_B_BAD.txt");
    printf("-------------------\n");
    search_X_form("C_BAD.txt");
    printf("-------------------\n");
    search_Y_form("_C_BAD.txt");
    printf("-------------------\n");
    */
    search_X_form("B_BAD.txt");
    printf("-------------------\n");
    search_Y_form("_B_BAD.txt");






    return 0;
}
