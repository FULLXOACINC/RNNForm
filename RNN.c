#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RNN.h"



int **W;
int **X;
int **Y;
int width, heigth;
int y_size;
int x_size;
int last;

void __init(int _Q, int _width, int _heigth, int _o_size)
{
    x_size = _width * _heigth;
    width = _width;
    heigth = _heigth;
    y_size = _o_size;

    last = 0;

    W = (int **)malloc(x_size * sizeof(int*));
    for(int i = 0; i < x_size; i++)
        W[i] = (int *)malloc(y_size * sizeof(int));

    X = (int **)malloc(_Q * sizeof(int*));
    for(int i = 0; i < _Q; i++)
        X[i] = (int *)malloc(x_size * sizeof(int));

    Y = (int **)malloc(_Q * sizeof(int*));
    for(int i = 0; i < _Q; i++)
        Y[i] = (int *)malloc(y_size * sizeof(int));

    for(int i = 0; i < x_size; i++)
        memset(W[i], 0, y_size * sizeof(int));

}

void add_form(char* name, char* form_name)
{
    FILE *file = fopen (name, "r");
    char ch;

    int i = 0;
    while(i < x_size) {
        fscanf (file, "%c", &ch);
        if(ch == '.') {
            X[last][i] = 1;
            i++;
        }
        if(ch == '#') {
            X[last][i] = -1;
            i++;
        }

    }
    fclose(file);
    file = fopen (form_name, "r");

    i = 0;
    while(i < y_size) {
        fscanf (file, "%c", &ch);
        if(ch == '.') {
            Y[last][i] = 1;
            i++;
        }
        if(ch == '#') {
            Y[last][i] = -1;
            i++;
        }

    }
    for(int index = 0; index < x_size; index++)
        for(int j = 0; j < y_size; j++)
            W[index][j] += X[last][index] * Y[last][j];

    last++;
    fclose(file);
}

void search_form(char* name)
{
    FILE *file = fopen (name, "r");
    char ch;
    int *res_x = (int *)malloc(x_size * sizeof(int));
    int *res_y = (int *)malloc(y_size * sizeof(int));

    int **temp = (int **)malloc(y_size * sizeof(int*));
    for(int i = 0; i < y_size; i++)
        temp[i] = (int *)malloc(sizeof(int));
    for(int i = 0; i < y_size; i++)
        memset(temp[i], 0, sizeof(int));

    int index = 0;
    while(index < x_size) {
        fscanf (file, "%c", &ch);
        if(ch == '.') {
            res_x[index] = 1;
            index++;
        }
        if(ch == '#') {
            res_x[index] = -1;
            index++;
        }

    }
    fclose(file);

    int is_relax = 1;
    int E_old=-1;
    int E=0;
    while(E!=E_old) {
        is_relax++;
        E_old=E;

        for(int i = 0; i < y_size; i++) {
            for(int j = 0; j < x_size; j++) {
                res_y[i] += res_x[j] * W[j][i];
            }
            if(res_y[i] > 0)
                res_y[i] = 1;
            if(res_y[i] < 0)
                res_y[i] = -1;
        }
        for(int i = 0; i < x_size; i++) {
            for(int j = 0; j < y_size; j++) {
                res_x[i] += res_y[j] * W[i][j];
            }
            if(res_x[i] > 0)
                res_x[i] = 1;
            if(res_x[i] < 0)
                res_x[i] = -1;
        }

        for(int i = 0; i < y_size; i++) {
            temp[i][1]=0;
            for(int j = 0; j < x_size; j++) {
                temp[i][1] += W[j][i] * res_y[i];
            }

        }
        E=0;
        for(int i = 0; i < y_size; i++) {
            for(int j = 0; j < x_size; j++) {
                E += temp[i][1] * res_x[j];
            }

        }
        printf("%i\n",E);

    }

    int number=-1;
    int is_find=0;
    for(int i = 0; i < last; i++) {
        for(int j = 0; j < x_size; j++) {
            if(X[i][j]!=res_x[j]){
                is_find=0;
                break;
            }
            is_find=1;

        }
        if(is_find){
            number=i;
            break;
        }

    }
    if(number!=-1)
        for(int j = 0; j < x_size; j++) {
            if(X[number][j] == 1) {
                printf(".");
            }
            if(X[number][j]  == -1) {
                printf("#");
            }
            if(X[number][j]  == 0) {
                printf("%i ", res_x[j]);
            }

            if((j + 1) % (width) == 0 )
                printf("\n");
        }
    free(res_x);
    free(res_y);

}


