#include <stdio.h>
#include <stdlib.h>
#include "RNN.h"

int main()
{
    __init(3, 16, 18, 280);
    add_form("A.txt", "_A.txt");
    add_form("B.txt", "_B.txt");
   // add_form("C.txt", "_C.txt");
    search_X_form("A.txt");
    search_Y_form("_A.txt");
    printf("-------------------\n");
    search_X_form("B.txt");
    search_Y_form("_B.txt");
  //  printf("-------------------\n");
  //  search_form("C.txt");
  // printf("-------------------\n");
  //  search_form("bad_A.txt");
//printf("-------------------\n");
//search_form("bad_B.txt");
//printf("-------------------\n");
  //  search_form("bad_C.txt");
 //   printf("-------------------\n");





    return 0;
}
