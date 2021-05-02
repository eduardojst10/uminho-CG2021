#include "scene.h"
#include "transformacao.h"
#include "model.h"
#include <vector>
#include <cstdlib>
#include <GL/gl.h>
#include <cstdio>



SCENE init_scene() {
    SCENE g = (SCENE) malloc(sizeof(struct scene));
    if (g) {
        g->models = new std::vector<MODEL>();
    }
    return g;
}

/**
 * Função que adiciona um modelo
 * @param g
 * @param m_add
 */
void add_model(SCENE s, MODEL m) {
    if (s) {
        s->models->push_back(m);

    }
}
void aplica_transformacoes(MODEL g){
    for (TRANSFORMACAO t: *(g->transformacoes)) {
        glMultMatrixf(get_matrix(t));
    }
}

/**
 * Funcao que desenha um model
 * @param g
 */
void draw_scene(SCENE g){
    glPushMatrix();

    for(int i= 0; i<g->models->size();i++) {
        MODEL  m = g->models->at(i);
        if(tem_Transformacoes(m)) {
          aplica_transformacoes(m);
        }
        draw_modelVBO(m);
    }
    glPopMatrix();
}

void init_vbo_scene (SCENE g) {
    for(MODEL m : *(g->models)) {
        init_vbo_model(m);
    }
}
