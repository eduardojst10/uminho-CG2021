//
// Created by eduardo on 11/03/21.
//

#include "scene.h"
#include <vector>
#include <cstdlib>
#include <GL/gl.h>
#include <cstdio>

struct scene {
    std::vector<MODEL> * models;

};

SCENE init_scene() {
    SCENE g = (SCENE) malloc(sizeof(struct scene));
    if (g) {
        g->models = new std::vector<MODEL>();
    }
    return g;
}


void add_model(SCENE g, MODEL m_add) {
    if (g) {
        g->models->push_back(m_add);
    }
}


void draw_scene (SCENE g) {
    for(MODEL m : *(g->models)) {
        drawModel(m);
    }
}


