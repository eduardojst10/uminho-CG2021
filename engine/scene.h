//
// Created by eduardo on 11/03/21.
//
#include "model.h"
#ifndef GENERATOR_GROUP_H
#define GENERATOR_GROUP_H

typedef struct scene * SCENE;


SCENE init_scene();
void add_model(SCENE g, MODEL m_add);
void draw_group (SCENE g);

#endif