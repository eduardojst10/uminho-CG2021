//
// Created by eduardo on 09/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <vector>
#ifndef GENERATOR_ENGINE_H
#define GENERATOR_ENGINE_H

struct vertice{
    float x;
    float y;
    float z;
};
typedef struct vertice * VERTICE;

#endif //GENERATOR_ENGINE_H
