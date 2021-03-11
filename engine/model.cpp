//
// Created by eduardo on 11/03/21.
//

#include "model.h"
#include "engine.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <GL/gl.h>

struct model {
    std::vector<Vertice> * pontos;
}

MODEL init_model(){
    MODEL m = (MODEL) malloc(sizeof(struct model));
    m->pontos = new std::vector<float>();
}

void add_Vertices(MODEL m, vector<Vertice> v) {
    if (m) {
        for (int i = 0; i < v.size(); i++) {
            m->pontos->push_back(v[i]);
        }
    }

}

void drawModel(MODEL m){
    glDrawArrays(GL_TRIANGLES, 0, m->pontos->size());
}