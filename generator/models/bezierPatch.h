//
// Created by eduardo on 25/04/21.
//

#ifndef GENERATOR_BEZIERPATCH_H
#define GENERATOR_BEZIERPATCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>

struct vertice{
    float pontos[4];
};
typedef struct vertice * VERTICE;

struct matrix{
    int lines;
    int cols;
    float values[4][4];
};
typedef struct matrix * MATRIX;

struct indexArr {
    int ind[16];
};
typedef struct indexArr * INDEXARR;

void patch(std::string fileout, int tesselation, std::string filename);

#endif //GENERATOR_BEZIERPATCH_H
