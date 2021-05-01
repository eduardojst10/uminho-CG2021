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
typedef struct matriz * MATRIZ;
typedef struct patchBezier *  BezierPatch;



BezierPatch  read_file(char* filename);
BezierPatch init_BezierPatch();

#endif //GENERATOR_BEZIERPATCH_H