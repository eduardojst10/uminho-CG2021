//
// Created by eduardo on 11/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <string>
#include <vector>
#include "engine.h"

#ifndef GENERATOR_MODEL_H
#define GENERATOR_MODEL_H

typedef struct model * MODEL;

MODEL init_model();
void add_Vertices(MODEL m, std::vector<vertice> v);
void drawModel(MODEL m);

#endif