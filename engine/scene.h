//
// Created by eduardo on 11/03/21.
//
#include "model.h"
#ifndef GENERATOR_GROUP_H
#define GENERATOR_GROUP_H


struct scene {
    std::vector<MODEL> * models;

};
typedef struct scene * SCENE;


SCENE init_scene();
void add_model(SCENE g, MODEL m_add);
void draw_scene (SCENE g);
void aplica_transformacoes(MODEL g);
void init_vbo_scene (SCENE g);

#endif