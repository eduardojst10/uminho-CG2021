//
// Created by eduardo on 11/03/21.
//

#include <cstdlib>
#include <string>
#include <vector>
#ifndef GENERATOR_MODEL_H
#define GENERATOR_MODEL_H

typedef struct model * MODEL;

MODEL init_model();
void add_Vertices(MODEL m, vector<Vertice> v);
void drawModel(MODEL m);

#endif